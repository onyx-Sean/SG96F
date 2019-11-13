/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6193_Series_VGIP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_VGIP__

#include "ScalerFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucVgipHSetting;
BYTE g_ucVgipVSetting;
BYTE g_ucVgipDelaySetting;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerVgipInputInitial(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort);
void ScalerVgipModifyPolarity(EnumSourceTypeDef enumSourceType);

WORD ScalerVgipGetCaptureVStartPosition(void);
void ScalerVgipSetCaptureVStartPosition(WORD usIVstart);

WORD ScalerVgipGetCaptureVHeight(void);
void ScalerVgipSetCaptureVHeight(WORD usIVheight);

WORD ScalerVgipGetCaptureVDelay(void);
void ScalerVgipSetCaptureVDelay(WORD usIVSDelay);

WORD ScalerVgipGetCaptureHStartPosition(void);
void ScalerVgipSetCaptureHStartPosition(WORD usIHstart);

void ScalerVgipSetCaptureHWidth(WORD usIHwidth);

void ScalerVgipSetCaptureHDelay(WORD usIHSDelay);
WORD ScalerVgipGetCaptureHDelay(void);

void ScalerVgipVsBypassEnable(bit bEnable);

void ScalerVgipSetDigitalCaptureStatus(bit bEnable);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial for VGIP Input
// Input Value  : Input Source Type
// Output Value : None
//--------------------------------------------------
void ScalerVgipInputInitial(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort)
{
    enumSourceType = enumSourceType;

    // Initial format conversion
    ScalerFmtCnvInitialSetting(enumSourceSearchPort);

    // Set source from format conversion; Disable Double buffer, Analog Capture, and Stop generate DE
    ScalerSetBit(P0_10_M1_VGIP_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));

    // HS Sync Edge select to Positive, Disable 1 clock Delay Mode
    ScalerSetBit(P0_12_M1_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

    // Set M2 VGIP state
    ScalerSetBit(P40_10_M2_VGIP_CTRL, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));
    ScalerSetBit(P40_12_M2_VGIP_DELAY_CTRL, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

    // Reset field detect edge
    ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~(_BIT5 | _BIT3), 0x00);
    ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~(_BIT5 | _BIT3), 0x00);

#if(_FREESYNC_SUPPORT == _ON)
    if((GET_FREESYNC_ENABLED() == _TRUE) && (enumSourceType == _SOURCE_DP))
    {
        // Enable bypass Vsync
        ScalerVgipVsBypassEnable(_ENABLE);
    }
    else
    {
        // Disable bypass Vsync
        ScalerVgipVsBypassEnable(_DISABLE);
    }
#else
    // Disable bypass Vsync
    ScalerVgipVsBypassEnable(_DISABLE);
#endif

    // Set clock gating
    ScalerSetBit(P80_1F_S1_ICLK_GATED_CTRL1, ~_BIT3, 0x00);
    ScalerSetBit(PC0_1F_S2_ICLK_GATED_CTRL1, ~_BIT3, 0x00);

    // Initial IVS/IHS Delay for Capture and Auto
    ScalerVgipSetCaptureHDelay(0x00);
    ScalerVgipSetCaptureVDelay(0x00);
}

//--------------------------------------------------
// Description  : Modify HS/VS Polarity
// Input Value  : Input Source Type
// Output Value : None
//--------------------------------------------------
void ScalerVgipModifyPolarity(EnumSourceTypeDef enumSourceType)
{
#if(_VGA_SUPPORT == _ON)
    if(enumSourceType == _SOURCE_VGA)
    {
        // HS No Invert in VGIP
        ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT2, 0x00);
        ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT2, 0x00);

        // VS No Invert in VGIP
        ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT3, 0x00);
        ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT3, 0x00);

        ScalerVgaTopModifyPolarity();
    }
    else
#endif
    {
        if(GET_SYNC_H_POLARITY() == _POSITIVE)
        {
            // HS No Invert
            ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT2, 0x00);
            ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT2, 0x00);
        }
        else
        {
            // HS Invert
            ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT2, _BIT2);
            ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT2, _BIT2);
        }

        if((enumSourceType == _SOURCE_DP) ||
           ((GET_SYNC_V_POLARITY() ^ (bit)ScalerGetBit(P0_4F_STABLE_MEASURE, _BIT2)) == _POSITIVE))
        {
            // VS No Invert
            ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT3, 0x00);
            ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT3, 0x00);
        }
        else
        {
            // VS Invert
            ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT3, _BIT3);
            ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT3, _BIT3);
        }
    }
}

//--------------------------------------------------
// Description  : Get Capture V-Start Position
// Input Value  : None
// Output Value : Capture Start
//--------------------------------------------------
WORD ScalerVgipGetCaptureVStartPosition(void)
{
    WORD usIVstart = ((((ScalerGetByte(P0_18_M1_IPV_ACT_STA_H) & 0x0F) << 8) | ScalerGetByte(P0_19_M1_IPV_ACT_STA_L)));

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        return (usIVstart << 1);
    }
    else
    {
        return usIVstart;
    }
}

//--------------------------------------------------
// Description  : Set Capture V-Start Position
// Input Value  : usIVstart --> V capture start
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureVStartPosition(WORD usIVstart)
{
    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        usIVstart = (usIVstart >> 1);
    }

    // Store effective values
    g_ucVgipVSetting = ((g_ucVgipVSetting & 0xF0) | (HIBYTE(usIVstart) & 0x0F));

    // Set M1 V capture start
    ScalerSetByte(P0_18_M1_IPV_ACT_STA_H, g_ucVgipVSetting);
    ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, LOBYTE(usIVstart));

    // Set M2 V capture start
    ScalerSetByte(P40_18_M2_IPV_ACT_STA_H, g_ucVgipVSetting);
    ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, LOBYTE(usIVstart));
}

//--------------------------------------------------
// Description  : Get Capture V-Height Position
// Input Value  : None
// Output Value : Capture Start
//--------------------------------------------------
WORD ScalerVgipGetCaptureVHeight(void)
{
    WORD usIVheight = ((((ScalerGetByte(P0_18_M1_IPV_ACT_STA_H) & 0xF0) << 4) | ScalerGetByte(P0_1B_M1_IPV_ACT_LEN_L)));

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        return (usIVheight << 1);
    }
    else
    {
        return usIVheight;
    }
}

//--------------------------------------------------
// Description  : Set Capture V-Height Position
// Input Value  : usIVheight --> Capture Height
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureVHeight(WORD usIVheight)
{
    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        usIVheight = (usIVheight >> 1);
    }

    g_ucVgipVSetting = ScalerGetByte(P0_18_M1_IPV_ACT_STA_H);

    // Store effective values
    g_ucVgipVSetting = ((g_ucVgipVSetting & 0x0F) | ((HIBYTE(usIVheight) & 0x0F) << 4));

    // Set M1 V capture height
    ScalerSetByte(P0_18_M1_IPV_ACT_STA_H, g_ucVgipVSetting);
    ScalerSetByte(P0_1B_M1_IPV_ACT_LEN_L, LOBYTE(usIVheight));

    // Set M2 V capture height
    ScalerSetByte(P40_18_M2_IPV_ACT_STA_H, g_ucVgipVSetting);
    ScalerSetByte(P40_1B_M2_IPV_ACT_LEN_L, LOBYTE(usIVheight));
}

//--------------------------------------------------
// Description  : Get Capture V Delay
// Input Value  : None
// Output Value : Capture V Delay
//--------------------------------------------------
WORD ScalerVgipGetCaptureVDelay(void)
{
    WORD usIVSDelay = (((((WORD)(ScalerGetByte(P0_1E_M1_VGIP_HV_DELAY) & _BIT1)) << 7) | ScalerGetByte(P0_1C_M1_IVS_DELAY)));

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        return (usIVSDelay << 1);
    }
    else
    {
        return usIVSDelay;
    }
}

//--------------------------------------------------
// Description  : Set Capture V Delay
// Input Value  : usIVSDelay --> V Delay
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureVDelay(WORD usIVSDelay)
{
    if(ScalerVgipGetDigitalCaptureStatus() == _TRUE)
    {
        return;
    }

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        usIVSDelay = (usIVSDelay >> 1);
    }

    // Store effective values
    g_ucVgipDelaySetting = ((g_ucVgipDelaySetting & ~_BIT1) | ((HIBYTE(usIVSDelay) & _BIT0) << 1));

    // Set M1 capture V delay
    ScalerSetByte(P0_1E_M1_VGIP_HV_DELAY, g_ucVgipDelaySetting);
    ScalerSetByte(P0_1C_M1_IVS_DELAY, LOBYTE(usIVSDelay));

    // Set M2 capture V delay
    ScalerSetByte(P40_1E_M2_VGIP_HV_DELAY, g_ucVgipDelaySetting);
    ScalerSetByte(P40_1C_M2_IVS_DELAY, LOBYTE(usIVSDelay));
}

//--------------------------------------------------
// Description  : Get Capture H-Start Position
// Input Value  : None
// Output Value : Capture H Start
//--------------------------------------------------
WORD ScalerVgipGetCaptureHStartPosition(void)
{
    WORD usHstart = (((ScalerGetByte(P0_14_M1_IPH_ACT_STA_H) & 0x0F) << 8) | ScalerGetByte(P0_15_M1_IPH_ACT_STA_L));

    // H-start in analog capture starts from 2
    if(ScalerVgipGetDigitalCaptureStatus() == _FALSE)
    {
        usHstart += 2;
    }

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        return (usHstart << 1);
    }
    else
    {
        return usHstart;
    }
}

//--------------------------------------------------
// Description  : Set Capture H-Start Position
// Input Value  : usIHstart --> Capture H start
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureHStartPosition(WORD usIHstart)
{
    // Modify H start under analog capture
    if(ScalerVgipGetDigitalCaptureStatus() == _FALSE)
    {
        if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
        {
            usIHstart = (usIHstart >> 1);
        }

        if(usIHstart >= 2)
        {
            // H-start in analog capture starts from 2
            usIHstart -= 2;
        }
    }

    // Store effective values
    g_ucVgipHSetting = ((g_ucVgipHSetting & 0xF0) | (HIBYTE(usIHstart) & 0x0F));

    // Set M1 H capture start
    ScalerSetByte(P0_14_M1_IPH_ACT_STA_H, g_ucVgipHSetting);
    ScalerSetByte(P0_15_M1_IPH_ACT_STA_L, LOBYTE(usIHstart));

    // Set M2 H capture start
    ScalerSetByte(P40_14_M2_IPH_ACT_STA_H, g_ucVgipHSetting);
    ScalerSetByte(P40_15_M2_IPH_ACT_STA_L, LOBYTE(usIHstart));
}

//--------------------------------------------------
// Description  : Set Capture H Width
// Input Value  : usIHwidth --> H capture width
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureHWidth(WORD usIHwidth)
{
    g_ucVgipHSetting = ScalerGetByte(P0_14_M1_IPH_ACT_STA_H);

    // Store effective values
    g_ucVgipHSetting = ((g_ucVgipHSetting & 0x0F) | ((HIBYTE(usIHwidth) & 0x0F) << 4));

    // Set M1 H capture width
    ScalerSetByte(P0_14_M1_IPH_ACT_STA_H, g_ucVgipHSetting);
    ScalerSetBit(P0_16_M1_IPH_ACT_WID_H, ~_BIT0, ((HIBYTE(usIHwidth) & _BIT4) >> 4));
    ScalerSetByte(P0_17_M1_IPH_ACT_WID_L, LOBYTE(usIHwidth));

    // Set M2 H capture width
    ScalerSetByte(P40_14_M2_IPH_ACT_STA_H, g_ucVgipHSetting);
    ScalerSetBit(P40_16_M2_IPH_ACT_WID_H, ~_BIT0, ((HIBYTE(usIHwidth) & _BIT4) >> 4));
    ScalerSetByte(P40_17_M2_IPH_ACT_WID_L, LOBYTE(usIHwidth));
}

//--------------------------------------------------
// Description  : Set Capture V Delay
// Input Value  : usIHSDelay --> H Delay
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetCaptureHDelay(WORD usIHSDelay)
{
    if(ScalerVgipGetDigitalCaptureStatus() == _TRUE)
    {
        return;
    }

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        usIHSDelay = (usIHSDelay >> 1);
    }

    if(usIHSDelay > _VGIP_IH_DELAY_MAX_VALUE)
    {
        ScalerIDomainFineTuneHCaptureStart(usIHSDelay - _VGIP_IH_DELAY_MAX_VALUE);

        usIHSDelay = _VGIP_IH_DELAY_MAX_VALUE;
    }

    // Store effective values
    g_ucVgipDelaySetting = ((g_ucVgipDelaySetting & ~(_BIT2 | _BIT0)) | (((HIBYTE(usIHSDelay) & _BIT1) << 1) | (HIBYTE(usIHSDelay) & _BIT0)));

    // Set M1 capture H delay
    ScalerSetByte(P0_1E_M1_VGIP_HV_DELAY, g_ucVgipDelaySetting);
    ScalerSetByte(P0_1D_M1_IHS_DELAY, LOBYTE(usIHSDelay));

    // Set M2 capture H delay
    ScalerSetByte(P40_1E_M2_VGIP_HV_DELAY, g_ucVgipDelaySetting);
    ScalerSetByte(P40_1D_M2_IHS_DELAY, LOBYTE(usIHSDelay));
}

//--------------------------------------------------
// Description  : Get Capture H Delay
// Input Value  : None
// Output Value : H Delay
//--------------------------------------------------
WORD ScalerVgipGetCaptureHDelay(void)
{
    WORD usHdelay = ((((WORD)ScalerGetByte(P0_1E_M1_VGIP_HV_DELAY) & _BIT2) << 7) | (((WORD)ScalerGetByte(P0_1E_M1_VGIP_HV_DELAY) & _BIT0) << 8) | ScalerGetByte(P0_1D_M1_IHS_DELAY));

    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        return (usHdelay << 1);
    }
    else
    {
        return usHdelay;
    }
}

//--------------------------------------------------
// Description  : Set VGIP VS bypass mode
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerVgipVsBypassEnable(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT6, _BIT6);
        ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT6, _BIT6);
    }
    else
    {
        ScalerSetBit(P0_11_M1_VGIP_SIGINV, ~_BIT6, 0x00);
        ScalerSetBit(P40_11_M2_VGIP_SIGINV, ~_BIT6, 0x00);
    }
}

//--------------------------------------------------
// Description  : Set VGA VS bypass VGIP
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerVgipSetDigitalCaptureStatus(bit bEnable)
{
    // Set Digital Capture
    if(bEnable == _ENABLE)
    {
        ScalerSetBit(P0_10_M1_VGIP_CTRL, ~_BIT1, _BIT1);
        ScalerSetBit(P40_10_M2_VGIP_CTRL, ~_BIT1, _BIT1);
    }
    else
    {
        ScalerSetBit(P0_10_M1_VGIP_CTRL, ~_BIT1, 0x00);
        ScalerSetBit(P40_10_M2_VGIP_CTRL, ~_BIT1, 0x00);
    }
}

