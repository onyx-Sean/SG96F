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
// ID Code      : ScalerTMDSRx3_SeptPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

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

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_D3_TMDS_SUPPORT == _ON)
void ScalerTMDSRx3DviVideoSetting(void);
void ScalerTMDSRx3FirstActiveProc(BYTE ucSourceType);
void ScalerTMDSRx3PowerOffProc(void);
BYTE ScalerTMDSRx3TMDSVideoDetect(bit bWait);
void ScalerTMDSRx3TMDSVideoDetectEvent(void);

#if((_D3_INPUT_PORT_TYPE == _D3_MHL_PORT) && (_D3_MHL_VERSION >= _MHL_VERSION_3_0))
void ScalerTMDSRx3MHL3SetCmu_EXINT0(BYTE ucCmuSel);
void ScalerTMDSRx3MHL3SetDFEInitial_EXINT0(void);
void ScalerTMDSRx3SetDFEInitial(void);

#if(_MHL3_ECBUS_AVLINK_CDR_MODE == _ACDR_MODE)
void ScalerTMDSRx3MHL3AcdrSetPhy(void);
void ScalerTMDSRx3MHL3AcdrSetPhy_EXINT0(void);
#endif

#if(_MHL3_ECBUS_AVLINK_CDR_MODE == _DCDR_MODE)
void ScalerTMDSRx3MHL3DcdrSetPhy(void);
void ScalerTMDSRx3MHL3DcdrSetPhy_EXINT0(void);
#endif

#endif

#if(_D3_HDMI_SUPPORT == _ON)
bit ScalerTMDSRx3HdmiAviPixelRepInfoChanged(void);
BYTE ScalerTMDSRx3HdmiGetAVIInfo(EnumAviInfoContent enumContent);
BYTE ScalerTMDSRx3HdmiGetColorDepth(void);
void ScalerTMDSRx3HdmiPacketDetectEvent(void);

#if(_D3_HDMI_2_0_SUPPORT == _ON)
void ScalerTMDSRx3HDMI2HPDRRIRQEnable(bit bEnable);
void ScalerTMDSRx3Hdmi2FormatResetEvent(void);
void ScalerTMDSRx3PSIntHandler_EXINT0(void);
void ScalerTMDSRx3ReadRequestProc_EXINT0(BYTE ucRROutCome);
void ScalerTMDSRx3ReadRequestTimerEventEnable_WDINT(bit bEnable);
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
bit ScalerTMDSRx3HdmiDeepColorProc(WORD usTmdsClkCnt);
bit ScalerTMDSRx3HdmiWaitDeepColorPllLock(void);
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
BYTE ScalerTMDSRx3HdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif

#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
bit ScalerTMDSRx3TMDSNormalPreDetect(void);
bit ScalerTMDSRx3TMDSPSPreDetect(void);
#endif

#endif

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D3_TMDS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Video Setting
// Input Value  : Source Type
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3DviVideoSetting(void)
{
    // Manual Set Color Space and disable pixel repetition
    ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

    // Disable Down Sampling
    ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_50_PORT_PAGE72_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // Waiting for Down Sampling Effect
    ScalerTimerDelayXms(20);

    SET_COLOR_SPACE(_COLOR_SPACE_RGB);
    SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

    ScalerTMDSRx3SetPorchColor(GET_COLOR_SPACE());
}
//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3FirstActiveProc(BYTE ucSourceType)
{
    ucSourceType = ucSourceType;
}
//--------------------------------------------------
// Description  : TMDS Power Off Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3PowerOffProc(void)
{
    // Disable EDID read/ SCL toggle IRQ
    MCU_FE72_DDC3_EDID_IRQ = ((MCU_FE72_DDC3_EDID_IRQ & ~(_BIT3 | _BIT1)) | (_BIT2 | _BIT0));

    ScalerTMDSRx3FreqDetectDisable();
}
//--------------------------------------------------
// Description  : Detect TMDS video mode
// Input Value  : bWait => Whether to wait then read
// Output Value : TMDS video type
//--------------------------------------------------
BYTE ScalerTMDSRx3TMDSVideoDetect(bit bWait)
{
    BYTE ucTemp = _TMDS_VIDEO_DATA_NONE;

    if(bWait == _WAIT)
    {
        // Wait at least 1 frame for HW auto update TMDS video RGBHV valid value
        ScalerTimerPollingFlagProc(45, P72_A4_TMDS_CTRL, _BIT3, _TRUE);

        // Wait for HW update DE flag
        if(ScalerTimerPollingFlagProc(20, P72_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5), _TRUE) == _TRUE)
        {
            // H/Vsync received
            if(ScalerGetBit(P72_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
            {
                ucTemp = _TMDS_VIDEO_DATA_RGBHV;
            }
            else
            {
                ucTemp = _TMDS_VIDEO_DATA_DE_ONLY;
            }
        }
        else
        {
            ucTemp = _TMDS_VIDEO_DATA_NONE;
        }

        CLR_TMDS_RX3_RGBHV_DETECTING();

        return ucTemp;
    }
    else
    {
        // R/G/B data detected
        if(ScalerGetBit(P72_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
        {
            // H/Vsync received
            if(ScalerGetBit(P72_A4_TMDS_CTRL, (_BIT4 | _BIT3)) == (_BIT4 | _BIT3))
            {
                ucTemp = _TMDS_VIDEO_DATA_RGBHV;
            }
            else
            {
                ucTemp = _TMDS_VIDEO_DATA_DE_ONLY;
            }
        }
        else
        {
            ucTemp = _TMDS_VIDEO_DATA_NONE;
        }

        // Clear video Detection Flag
        ScalerSetBit(P72_A4_TMDS_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3));

        SET_TMDS_RX3_RGBHV_DETECTING();

        // Activate TMDS video Detection Event
        ScalerTimerActiveTimerEvent(SEC(0.045), _SCALER_TIMER_EVENT_RX3_TMDS_VIDEO_DETECT);

        return ucTemp;
    }
}
//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3TMDSVideoDetectEvent(void)
{
    CLR_TMDS_RX3_RGBHV_DETECTING();
}

#if((_D3_INPUT_PORT_TYPE == _D3_MHL_PORT) && (_D3_MHL_VERSION >= _MHL_VERSION_3_0))
//--------------------------------------------------
// Description  : MHL3 set CMU
// Input Value  : ucCmuSel
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3MHL3SetCmu_EXINT0(BYTE ucCmuSel) using 1
{
    ucCmuSel = ucCmuSel;

    // TODO:
}
//--------------------------------------------------
// Description  : MHL3 DFE initial INT process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3MHL3SetDFEInitial_EXINT0(void) using 1
{
    // TODO:
}
//--------------------------------------------------
// Description  : MHL3 DFE initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3SetDFEInitial(void)
{
    // TODO:
}

#if(_MHL3_ECBUS_AVLINK_CDR_MODE == _ACDR_MODE)
//--------------------------------------------------
// Description  : MHL3 Data Lane Set PHY
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3MHL3AcdrSetPhy(void)
{
    // TODO:


    /////////////////
    // DFE Setting //
    /////////////////

    // Load DFE Initial Code
    ScalerTMDSRx3SetDFEInitial();
}
//--------------------------------------------------
// Description  : MHL3 Data Lane Set PHY (Interrupt Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3MHL3AcdrSetPhy_EXINT0(void) using 1
{
    // TODO:


    /////////////////
    // DFE Setting //
    /////////////////

    // Load DFE Initial Code
    ScalerTMDSRx3MHL3SetDFEInitial_EXINT0();
}
#endif

#if(_MHL3_ECBUS_AVLINK_CDR_MODE == _DCDR_MODE)
//--------------------------------------------------
// Description  : MHL3 Data Lane Set PHY
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3MHL3DcdrSetPhy(void)
{
    // TODO:


    /////////////////
    // DFE Setting //
    /////////////////

    // Load DFE Initial Code
    ScalerTMDSRx3SetDFEInitial();
}
//--------------------------------------------------
// Description  : MHL3 Data Lane Set PHY (Interrupt Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3MHL3DcdrSetPhy_EXINT0(void) using 1
{
    // TODO:


    /////////////////
    // DFE Setting //
    /////////////////

    // Load DFE Initial Code
    ScalerTMDSRx3MHL3SetDFEInitial_EXINT0();
}
#endif

#endif

#if(_D3_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect HDMI AVI pixel repetition
// Input Value  : None
// Output Value : _TRUE => Current Info is different from previous setting
//--------------------------------------------------
bit ScalerTMDSRx3HdmiAviPixelRepInfoChanged(void)
{
    // Check Tmds Pixel Repetition
    if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION) != GET_TMDS_RX3_AVI_PIXEL_REPETITION())
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSRx3HdmiGetAVIInfo(EnumAviInfoContent enumContent)
{
    if(GET_HDMI_RX3_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        switch(enumContent)
        {
            case _AVI_INFO_COLOR_SPACE:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x04, (_BIT6 | _BIT5)) >> 5);

            case _AVI_INFO_COLORIMETRY:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x05, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_EXTENDED_COLORIMETRY:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x06, (_BIT6 | _BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_RGB_QUANTIZATION:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x06, (_BIT3 | _BIT2)) >> 2);

            case _AVI_INFO_YCC_QUANTIZATION:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x08, (_BIT7 | _BIT6)) >> 6);

            case _AVI_INFO_SCAN_INFO:

                return ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x04, (_BIT1 | _BIT0));

            case _AVI_INFO_IT_CONTENT:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x06, _BIT7) >> 7);

            case _AVI_INFO_PIXEL_REPETITION:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x08, (_BIT3 | _BIT2 | _BIT1 | _BIT0)));

            case _AVI_INFO_AR:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x05, (_BIT5 | _BIT4)) >> 4);

            case _AVI_INFO_VIC:

                return (ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x07, (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));

            default:

                break;
        }
    }

    return 0xFF;
}
//--------------------------------------------------
// Description  : Get Color Depth
// Input Value  : None
// Output Value : Received Color Depth
//--------------------------------------------------
BYTE ScalerTMDSRx3HdmiGetColorDepth(void)
{
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        return _COLOR_DEPTH_12_BITS;
    }

    if(GET_HDMI_RX3_GCP_RECEIVED() == _TRUE)
    {
        if(ScalerGetBit(P72_B4_TMDS_DPC0, 0x07) == 0x05)
        {
            return _COLOR_DEPTH_10_BITS;
        }
        else if(ScalerGetBit(P72_B4_TMDS_DPC0, 0x07) == 0x06)
        {
            return _COLOR_DEPTH_12_BITS;
        }
        else if(ScalerGetBit(P72_B4_TMDS_DPC0, 0x07) == 0x07)
        {
            return _COLOR_DEPTH_16_BITS;
        }
    }

    return _COLOR_DEPTH_8_BITS;
}
//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3HdmiPacketDetectEvent(void)
{
    CLR_HDMI_RX3_PACKET_DETECTING();
}

#if(_D3_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS HPD IRQ Enable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3HDMI2HPDRRIRQEnable(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Set HPD Debounce = 700 Clock Cycle
        // Set HPD IRQ Detect Rising to Falling Edge IRQ
        ScalerSetBit(P72_23_HDMI_CTRL_23, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT5 | _BIT4 | _BIT3 | _BIT1));

        // Enable HDMI HPD IRQ Enable
        ScalerSetBit(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);

        // Write 1 Clear Read Request
        ScalerSetBit(P72_25_HDMI_CTRL_25, ~_BIT3, _BIT3);

        // Enable HDMI 2.0 SCDC IIC Module
        ScalerSetBit(P72_19_HDMI_CTRL_19, ~_BIT7, _BIT7);

        // Clear HDMI 2.0 Read Request Enable
        CLR_HDMI_2_0_RX3_RR_ENABLE();

        // Enable HDMI 2.0 Read Request Enable Detect IRQ
        ScalerSetBit(P72_26_HDMI_CTRL_26, ~_BIT3, _BIT3);
    }
    else
    {
        // Write 1 Clear Read Request
        ScalerSetBit(P72_25_HDMI_CTRL_25, ~_BIT3, _BIT3);

        // Clear HDMI 2.0 Read Request Enable
        CLR_HDMI_2_0_RX3_RR_ENABLE();

        // Disable HDMI 2.0 Read Request Enable Detect IRQ
        ScalerSetBit(P72_26_HDMI_CTRL_26, ~_BIT3, 0x00);
    }
}
//--------------------------------------------------
// Description  : TMDS Format Reset Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3Hdmi2FormatResetEvent(void)
{
    CLR_TMDS_RX3_HDMI_2_0_FORMAT_RESET_WAITING();
}
//--------------------------------------------------
// Description  : TMDS Interrupt Process In PS/PD State(EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3PSIntHandler_EXINT0(void) using 1
{
    BYTE pucBackUp[2];

    pucBackUp[0] = ScalerGetByte_EXINT(P72_39_HDMI_CTRL_39);
    pucBackUp[1] = ScalerGetByte_EXINT(P72_38_HDMI_CTRL_38);

    // Detect Source Write Read Request Enable Flag
    if((ScalerGetBit_EXINT(P72_25_HDMI_CTRL_25, _BIT3) == _BIT3) && (ScalerGetBit_EXINT(P72_26_HDMI_CTRL_26, _BIT3) == _BIT3))
    {
        // Clear Read Request Flag
        ScalerSetBit_EXINT(P72_25_HDMI_CTRL_25, ~_BIT3, _BIT3);

        // Set Read Request Enable
        SET_HDMI_2_0_RX3_RR_ENABLE();

        // Enable Test Read Request HW Auto Mode
        ScalerSetBit_EXINT(P72_1C_HDMI_CTRL_1C, ~_BIT1, _BIT1);

        // Enable CED Update Read Request Auto Mode
        ScalerSetBit_EXINT(P72_24_HDMI_CTRL_24, ~_BIT0, _BIT0);

        // Enable Read Request Done IRQ
        ScalerSetBit_EXINT(P72_1F_HDMI_CTRL_1F, ~_BIT3, _BIT3);
    }

    // Read Request Done into IRQ
    if((ScalerGetBit_EXINT(P72_1F_HDMI_CTRL_1F, _BIT3) == _BIT3) && (ScalerGetBit_EXINT(P72_1C_HDMI_CTRL_1C, _BIT7) == _BIT7))
    {
        // Clear Read Request Done Flag
        ScalerSetBit_EXINT(P72_1C_HDMI_CTRL_1C, ~_BIT7, _BIT7);

        // Read Request Outcome Processing
        ScalerTMDSRx3ReadRequestProc_EXINT0(ScalerGetByte_EXINT(P72_1C_HDMI_CTRL_1C) & 0x70);
    }

    // Detect HDMI HPD Rising to Falling into IRQ
    if(ScalerGetBit_EXINT(P72_23_HDMI_CTRL_23, (_BIT6 | _BIT1)) == (_BIT6 | _BIT1))
    {
        // Clear HPD IRQ Flag
        ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT1, _BIT1);

        if(ScalerGetBit_EXINT(P72_23_HDMI_CTRL_23, (_BIT2 | _BIT0)) == 0x00)
        {
            // Clear All Source Write SCDC Port Register
            ScalerSetBit_EXINT(P72_38_HDMI_CTRL_38, ~(_BIT2 | _BIT1), (_BIT2 | _BIT1));

            // Clear HDMI 2.0 Read Request Enable
            CLR_HDMI_2_0_RX3_RR_ENABLE();

            // Disable Rising to Falling IRQ, Set IRQ Status Falling to Rising edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

            // Enable Falling to Rising edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);

            /*
            // Disable Test Read Request HW Auto Mode
            ScalerSetBit_EXINT(P72_1C_HDMI_CTRL_1C, ~_BIT1, 0x00);

            // Disable CED Update Read Request Auto Mode
            ScalerSetBit_EXINT(P72_24_HDMI_CTRL_24, ~_BIT0, 0x00);

            // Disable Character Error Detection Function
            ScalerSetBit_EXINT(P72_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

            // Disable Lock Transition IRQ
            ScalerSetBit_EXINT(P72_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

            ScalerSetBit_EXINT(P72_17_HDMI_CTRL_17, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // Detect 3 Channel CDR Stable
            if((bit)ScalerTMDSRx3CheckCDRStable_EXINT(g_usTMDSRx3ClkCount) == _TRUE)
            {
                // Disable Rising to Falling IRQ, Set IRQ Status Falling to Rising edge IRQ
                ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

                // Enable Falling to Rising edge IRQ
                ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);
            }
            */
        }
        else
        {
            /*
            // Enable CED Function
            ScalerSetBit_EXINT(P72_0B_HDMI_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2));

            // Enable CED Lock Transition IRQ
            ScalerSetBit_EXINT(P72_17_HDMI_CTRL_17, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            ScalerSetBit_EXINT(P72_18_HDMI_CTRL_18, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

            // Enable SCDC Module
            ScalerSetBit_EXINT(P72_19_HDMI_CTRL_19, ~_BIT7, _BIT7);
            */

            // Disable Falling to Rising IRQ, Set IRQ Status Rising to Falling edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~(_BIT6 | _BIT2 | _BIT1), _BIT1);

            // Enable Rising to Falling edge IRQ
            ScalerSetBit_EXINT(P72_23_HDMI_CTRL_23, ~_BIT6, _BIT6);
        }
    }

    // Clear IRQ Pending Flag
    ScalerSetByte_EXINT(P72_C9_HDMI_AP, _P72_CA_PT_60_PORT_PAGE72_HDMI_INTCR);
    ScalerSetBit_EXINT(P72_CA_HDMI_DP, ~_BIT7, _BIT7);

    ScalerSetByte_EXINT(P72_38_HDMI_CTRL_38, pucBackUp[1]);
    ScalerSetByte_EXINT(P72_39_HDMI_CTRL_39, pucBackUp[0]);
}
//--------------------------------------------------
// Description  : TMDS Read Request Outcome Case Processing(EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ReadRequestProc_EXINT0(BYTE ucRROutCome) using 1
{
    // Get Read Request Outcome Case
    switch(ucRROutCome)
    {
        case _HDMI_2_0_READ_REQUEST_ACK_DONE:
        case _HDMI_2_0_READ_REQUEST_ACK_STOP:

            break;

        case _HDMI_2_0_READ_REQUEST_NACK1:

            if(GET_HDMI_2_0_RX3_RR_ENABLE() == _TRUE)
            {
                // FW Manual Enable Read Request
                ScalerSetBit_EXINT(P72_1B_HDMI_CTRL_1B, ~_BIT7, _BIT7);
            }

            break;

        case _HDMI_2_0_READ_REQUEST_NACK2:

#if(_WD_TIMER_INT_SUPPORT == _ON)
            if(GET_HDMI_2_0_RX3_RR_ENABLE() == _TRUE)
            {
                // Enable Read Request Retry
                ScalerTimerWDActivateTimerEvent_EXINT0(10, _SCALER_WD_TIMER_EVENT_RX3_HDMI_RR_RETRY);
            }
#endif

            break;

        default:

            break;
    }
}
//--------------------------------------------------
// Description  : TMDS Read Request Timer Event Enable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSRx3ReadRequestTimerEventEnable_WDINT(bit bEnable) using 3
{
    if(bEnable == _ENABLE)
    {
        if(GET_HDMI_2_0_RX3_RR_ENABLE() == _TRUE)
        {
            // FW Manual Enable Read Request
            ScalerSetBit_EXINT(P72_1B_HDMI_CTRL_1B, ~_BIT7, _BIT7);
        }
    }
    else
    {
        // Disable Read Request Enable
        ScalerSetBit_EXINT(P72_1B_HDMI_CTRL_1B, ~_BIT7, 0x00);
    }
}
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
//--------------------------------------------------
// Description  : HDMI Deep Color Proc
// Input Value  : void
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerTMDSRx3HdmiDeepColorProc(WORD usTmdsClkCnt)
{
    // Setting Deep Color PLL
    if(ScalerTMDSRx3HdmiSetDeepColorPll(usTmdsClkCnt, GET_COLOR_DEPTH()) == _FALSE)
    {
        return _FALSE;
    }

    // Wait for Phase lock
    if(ScalerTMDSRx3HdmiWaitDeepColorPllLock() == _FALSE)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Wait for Deep Color PLL Phase Lock
// Input Value  : None
// Output Value : _TRUE = > Phase Locked
//--------------------------------------------------
bit ScalerTMDSRx3HdmiWaitDeepColorPllLock(void)
{
    BYTE ucTemp = 0;

    do
    {
        ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_82_PORT_PAGE72_HDMI_DPC_SET2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Delay for PLL Phase Lock
        ScalerTimerDelayXms(2);

        ucTemp++;
    }
    while((ScalerGetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_82_PORT_PAGE72_HDMI_DPC_SET2, _BIT1) != 0) && (ucTemp <= 15));

    if(ucTemp > 15)
    {
        return _FALSE;
    }

    return _TRUE;
}
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get AMD SPD Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSRx3HdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent)
{
    if(GET_TMDS_RX3_SPD_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Get AMD OUI
        ScalerGetDataPortByte(P72_CD_HDMI_PSAP, 0x90, 3, pData, _AUTOINC);
        if((pData[0] == 0x1A) && (pData[1] == 0x00) && (pData[2] == 0x00))
        {
            switch(enumContent)
            {
                case _SPD_INFO_FREESYNC_SUPPORT:

                    return ((bit)ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x95, _BIT0));

                case _SPD_INFO_FREESYNC_ENABLE:

                    return ((bit)ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x95, _BIT1));

                case _SPD_INFO_FREESYNC_ACTIVE:

                    return ((bit)ScalerGetDataPortBit(P72_CD_HDMI_PSAP, 0x95, _BIT2));

                case _SPD_INFO_FREESYNC_MIN_VFREQ:

                    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, 0x96, 1, pData, _AUTOINC);

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageRx3("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageRx3("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                case _SPD_INFO_FREESYNC_MAX_VFREQ:

                    ScalerGetDataPortByte(P72_CD_HDMI_PSAP, 0x97, 1, pData, _AUTOINC);

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageRx3("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageRx3("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                default:

                    return 0x00;
            }
        }
    }

    return 0x00;
}
#endif

#endif

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSRx3TMDSNormalPreDetect(void)
{
    // DDC handshake Detected
    if(GET_TMDS_RX3_DDC_DETECTED() == _TRUE)
    {
        DebugMessageRx3("7. Normal D3 DDC", 0);

        CLR_TMDS_RX3_DDC_DETECTED();

        return _TRUE;
    }

    // Enable DDC Toggle IRQ
    if(((MCU_FE72_DDC3_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX3_DDC_DETECTED() != _TRUE))
    {
        MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
        MCU_FE72_DDC3_EDID_IRQ |= _BIT3;

        CLR_TMDS_RX3_DDC_DETECTED();
    }

    ScalerTimerDelayXms(6);

    if(GET_TMDS_RX3_PHY_SET() == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Signal Detection for TMDS(Power Saving)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSRx3TMDSPSPreDetect(void)
{
    // DDC handshake Detected
    if(GET_TMDS_RX3_DDC_DETECTED() == _TRUE)
    {
        DebugMessageRx3("7. PowerSaving D3 DDC", 0);

        CLR_TMDS_RX3_DDC_DETECTED();

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
        SET_TMDS_RX3_TOGGLE_Z0();
#endif
        return _TRUE;
    }

    // Enable DDC Toggle IRQ
    if(((MCU_FE72_DDC3_EDID_IRQ & _BIT3) != _BIT3) && (GET_TMDS_RX3_DDC_DETECTED() != _TRUE))
    {
        MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
        MCU_FE72_DDC3_EDID_IRQ |= _BIT3;
    }

    // Reset Freq. Detect Counter(Toggle) & Choose Measure Clk to TMDS Clk
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);

    // Clear Freq. Stable Flag
    ScalerSetBit(P72_EF_HDMI_ERROR_TH, ~_BIT6, _BIT6);

    // Clear Unstable Flag
    ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

    // Delay enough time for freq. measure (calculated for measure 5 times)
    ScalerTimerDelayXms(5);

    // Detect Freq. Measure Stable
    if((ScalerGetBit(P72_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P72_EF_HDMI_ERROR_TH, _BIT6) == _BIT6))
    {
#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
        SET_TMDS_RX3_TOGGLE_Z0();
#endif
        return _TRUE;
    }
    else
    {
        // Disable Freq. Detection
        ScalerSetBit(P72_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);

        return _FALSE;
    }

    return _FALSE;
}
#endif

#endif

#endif
