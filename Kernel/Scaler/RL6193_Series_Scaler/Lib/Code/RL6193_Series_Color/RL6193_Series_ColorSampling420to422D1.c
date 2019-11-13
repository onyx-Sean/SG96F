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
// ID Code      : RL6193_Series_ColorSampling420to422D1.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6193_Series_ColorLibInternalInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _3840_2160_FTOP_CRC        0x6B6878
#define _4096_2160_FTOP_CRC        0x7627A5

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerColor420To422D1Recheck(void);
bit ScalerColor420to422D1CheckCRC(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Recheck 420To422 for D1 source
// Input Value  : Enable or Disable
// Output Value : None
//--------------------------------------------------
bit ScalerColor420To422D1Recheck(void)
{
    WORD usCount = 0;

    if((ScalerGlobalGetIDCode() >= _RL6193_VER_D_ID_CODE) ||
       (GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR420) ||
       (GET_COLOR_DEPTH() > _COLOR_DEPTH_8_BITS) ||
       ((g_stInputTimingData.usHWidth != 3840) && (g_stInputTimingData.usHWidth != 4096)))
    {
        return _TRUE;
    }
    else
    {
        ScalerSetByte(P0_23_SCALE_DOWN_CTRL_M1, 0x00);
        ScalerSetByte(P40_23_SCALE_DOWN_CTRL_M2, 0x00);

        // Set M1 H capture start
        ScalerSetByte(P0_14_M1_IPH_ACT_STA_H, ((HIBYTE(g_stInputTimingData.usHWidth) << 4) | HIBYTE((g_stInputTimingData.usHStart / 2) - 2)));
        ScalerSetByte(P0_15_M1_IPH_ACT_STA_L, LOBYTE((g_stInputTimingData.usHStart / 2) - 2));
        ScalerSetByte(P0_16_M1_IPH_ACT_WID_H, (g_stInputTimingData.usHWidth >> 12));
        ScalerSetByte(P0_17_M1_IPH_ACT_WID_L, LOBYTE(g_stInputTimingData.usHWidth));

        // Set M2 H capture start
        ScalerSetByte(P40_14_M2_IPH_ACT_STA_H, ((HIBYTE(g_stInputTimingData.usHWidth) << 4) | HIBYTE((g_stInputTimingData.usHStart / 2) - 2)));
        ScalerSetByte(P40_15_M2_IPH_ACT_STA_L, LOBYTE((g_stInputTimingData.usHStart / 2) - 2));
        ScalerSetByte(P40_16_M2_IPH_ACT_WID_H, (g_stInputTimingData.usHWidth >> 12));
        ScalerSetByte(P40_17_M2_IPH_ACT_WID_L, LOBYTE(g_stInputTimingData.usHWidth));

        // Set M1 V capture start
        ScalerSetByte(P0_18_M1_IPV_ACT_STA_H, ((HIBYTE(g_stInputTimingData.usVHeight / 2) << 4) | HIBYTE(g_stInputTimingData.usVStart / 2)));
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, LOBYTE(g_stInputTimingData.usVStart / 2));
        ScalerSetByte(P0_1B_M1_IPV_ACT_LEN_L, LOBYTE(g_stInputTimingData.usVHeight / 2));

        // Set M2 V capture start
        ScalerSetByte(P40_18_M2_IPV_ACT_STA_H, ((HIBYTE(g_stInputTimingData.usVHeight / 2) << 4) | HIBYTE(g_stInputTimingData.usVStart / 2)));
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, LOBYTE(g_stInputTimingData.usVStart / 2));
        ScalerSetByte(P40_1B_M2_IPV_ACT_LEN_L, LOBYTE(g_stInputTimingData.usVHeight / 2));


        ScalerSetByte(P0_1C_M1_IVS_DELAY, 0x00);
        ScalerSetByte(P0_1D_M1_IHS_DELAY, 0x00);
        ScalerSetBit(P0_1E_M1_VGIP_HV_DELAY, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        ScalerSetByte(P40_1C_M2_IVS_DELAY, 0x00);
        ScalerSetByte(P40_1D_M2_IHS_DELAY, 0x00);
        ScalerSetBit(P40_1E_M2_VGIP_HV_DELAY, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        ScalerSetByte(P36_00_I_CRC_CTRL, 0x0C);

        // disable HDMI RGB output
        ScalerSetBit(P70_A6_TMDS_OUTCTL, ~(_BIT6 | _BIT5 | _BIT4), 0x00);

        // enable background color R=0xff G=0x80 B=0x00
        ScalerSetByte(P70_BA_TMDS_ROUT_HIGH_BYTE, 0xFF);
        ScalerSetByte(P70_BC_TMDS_GOUT_HIGH_BYTE, 0x80);
        ScalerSetByte(P70_BE_TMDS_BOUT_HIGH_BYTE, 0x00);
    }

    for(usCount = 0; usCount < 50; usCount++)
    {
        if(ScalerMeasureTimingChange(_SOURCE_HDMI) == _TRUE)
        {
            return _FALSE;
        }

        if(ScalerColor420to422D1CheckCRC() == _FALSE)
        {
            // 420to422 retoggle
            if(ScalerTimerWaitForEvent(_EVENT_IEN_START) == _FALSE)
            {
                return _FALSE;
            }

            for(pData[2] = 0; pData[2] < 20; pData[2]++)
            {
                ScalerSetByte(P31_21_YUV420_TO_YUV422_D1, 0x83);
                ScalerSetByte(P31_21_YUV420_TO_YUV422_D1, 0x8B);
            }
        }
        else
        {
            break;
        }
    }

    // Enable HDMI RGB output
    ScalerSetBit(P70_A6_TMDS_OUTCTL, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

    // Restore background color
    ScalerTMDSRx1SetPorchColor(_COLOR_SPACE_YCBCR420);

    return _TRUE;
}

//--------------------------------------------------
// Description  : 420To422 CRC Check
// Input Value  : CRC read address
// Output Value : None
//--------------------------------------------------
bit ScalerColor420to422D1CheckCRC(void)
{
    // Wait for M1 IVS
    ScalerSetByte(P0_03_STATUS1, _EVENT_IVS);

    if(ScalerTimerPollingFlagProc(120, P0_03_STATUS1, _EVENT_IVS, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Wait for M1 IVS
    ScalerSetByte(P0_03_STATUS1, _EVENT_IVS);

    if(ScalerTimerPollingFlagProc(120, P0_03_STATUS1, _EVENT_IVS, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Check CRC
    PDATA_DWORD(0) = ScalerGetDWord(P36_01_I_MAIN1_CRC_1) >> 8;

    if(((g_stInputTimingData.usHWidth == 3840) && (PDATA_DWORD(0) == _3840_2160_FTOP_CRC)) ||
       ((g_stInputTimingData.usHWidth == 4096) && (PDATA_DWORD(0) == _4096_2160_FTOP_CRC)))
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
