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
// ID Code      : RL6193_Series_TMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_TMDS__

#include "ScalerFunctionInclude.h"

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

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
void ScalerTMDSInitial(BYTE ucInputPort);
void ScalerTMDSInterruptInitial(BYTE ucInputPort);
void ScalerTMDSIntHandler_EXINT0(void);
void ScalerTMDSVideoDetectEvent(EnumScalerTimerEventID enumEventID);
void ScalerTMDSResetProc(void);

#if(_HDMI_SUPPORT == _ON)
void ScalerTMDSHdmiAVMuteProc(void);
void ScalerTMDSHdmiWatchDog(BYTE ucWDType, bit bEnable);
void ScalerTMDSHdmiPacketDetectEvent(EnumScalerTimerEventID enumEventID);

#if(_HDMI_2_0_SUPPORT == _ON)
void ScalerTMDSPSIntHandler_EXINT0(void);
void ScalerTMDSHdmiReadRequestTimerEnable_WDINT(bit bEnable);
void ScalerTMDSHdmi2FormatResetEvent(EnumScalerTimerEventID enumEventID);
#endif

//bit ScalerTMDSYUV420SupportCheck(BYTE ucInputPort);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
void ScalerTMDSFreesyncInitial(bit bSupport);
BYTE ScalerTMDSHdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif

#endif

void ScalerTMDSFreqDetectDisable(void);
void ScalerTMDSFirstActiveProc(BYTE ucInputPort, BYTE ucSourceType);
bit ScalerTMDSHdcpEnabled(BYTE ucInputPort);

bit ScalerTMDSNormalPreDetect(BYTE ucInputPort);
BYTE ScalerTMDSScanInputPort(BYTE ucInputPort, BYTE ucInputType);
bit ScalerTMDSPSPreDetect(BYTE ucInputPort);
bit ScalerTMDSStableDetect(BYTE ucInputPort, BYTE ucSourceType);
void ScalerTMDSHotPlugEvent(BYTE ucPortSelect);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initialize TMDS setting for search
// Input Value  : Current Search Port
// Output Value : None
//--------------------------------------------------
void ScalerTMDSInitial(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)

        case _D0_INPUT_PORT:

            ScalerTMDSRx0Initial();

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            ScalerTMDSRx1Initial();

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)

        case _D2_INPUT_PORT:

            ScalerTMDSRx2Initial();

            break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)

        case _D3_INPUT_PORT:

            ScalerTMDSRx3Initial();

            break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)

        case _D4_INPUT_PORT:

            ScalerTMDSRx4Initial();

            break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)

        case _D5_INPUT_PORT:

            ScalerTMDSRx5Initial();

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Initialize TMDS Interrupt Required Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSInterruptInitial(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)

        case _D0_INPUT_PORT:

            ScalerTMDSRx0InterruptInitial();

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            ScalerTMDSRx1InterruptInitial();

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)

        case _D2_INPUT_PORT:

            ScalerTMDSRx2InterruptInitial();

            break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)

        case _D3_INPUT_PORT:

            ScalerTMDSRx3InterruptInitial();

            break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)

        case _D4_INPUT_PORT:

            ScalerTMDSRx4InterruptInitial();

            break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)

        case _D5_INPUT_PORT:

            ScalerTMDSRx5InterruptInitial();

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : TMDS Interrupt Process (EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSIntHandler_EXINT0(void) using 1
{
#if(_D0_TMDS_SUPPORT == _ON)
    ScalerTMDSRx0IntHandler_EXINT0();
#endif

#if(_D1_TMDS_SUPPORT == _ON)
    ScalerTMDSRx1IntHandler_EXINT0();
#endif

#if(_D2_TMDS_SUPPORT == _ON)
    ScalerTMDSRx2IntHandler_EXINT0();
#endif

#if(_D3_TMDS_SUPPORT == _ON)
    ScalerTMDSRx3IntHandler_EXINT0();
#endif

#if(_D4_TMDS_SUPPORT == _ON)
    ScalerTMDSRx4IntHandler_EXINT0();
#endif

#if(_D5_TMDS_SUPPORT == _ON)
    ScalerTMDSRx5IntHandler_EXINT0();
#endif
}

//--------------------------------------------------
// Description  : TMDS video Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSVideoDetectEvent(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX0_TMDS_VIDEO_DETECT:

            ScalerTMDSRx0TMDSVideoDetectEvent();

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX1_TMDS_VIDEO_DETECT:

            ScalerTMDSRx1TMDSVideoDetectEvent();

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX2_TMDS_VIDEO_DETECT:

            ScalerTMDSRx2TMDSVideoDetectEvent();

            break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX3_TMDS_VIDEO_DETECT:

            ScalerTMDSRx3TMDSVideoDetectEvent();

            break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX4_TMDS_VIDEO_DETECT:

            ScalerTMDSRx4TMDSVideoDetectEvent();

            break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX5_TMDS_VIDEO_DETECT:

            ScalerTMDSRx5TMDSVideoDetectEvent();

            break;
#endif

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : TMDS Reset Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSResetProc(void)
{
#if(_D0_TMDS_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX0_TMDS_VIDEO_DETECT);
#if(_D0_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX0_TMDS_HDMI_PACKET_DETECT);
#if(_D0_HDMI_2_0_SUPPORT == _ON)
    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_RX0_HDMI_RR_RETRY);
#endif
#endif // End of #if(_D0_HDMI_SUPPORT == _ON)
#endif // End of #if(_D0_TMDS_SUPPORT == _ON)

#if(_D1_TMDS_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX1_TMDS_VIDEO_DETECT);
#if(_D1_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX1_TMDS_HDMI_PACKET_DETECT);
#if(_D1_HDMI_2_0_SUPPORT == _ON)
    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_RX1_HDMI_RR_RETRY);
#endif
#endif // End of #if(_D1_HDMI_SUPPORT == _ON)
#endif // End of #if(_D1_TMDS_SUPPORT == _ON)


#if(_D2_TMDS_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX2_TMDS_VIDEO_DETECT);

#if(_D2_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX2_TMDS_HDMI_PACKET_DETECT);
#endif // End of #if(_D2_HDMI_SUPPORT == _ON)
#endif // End of #if(_D2_TMDS_SUPPORT == _ON)

#if(_D3_TMDS_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX3_TMDS_VIDEO_DETECT);

#if(_D3_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX3_TMDS_HDMI_PACKET_DETECT);
#endif // End of #if(_D3_HDMI_SUPPORT == _ON)
#endif // End of #if(_D3_TMDS_SUPPORT == _ON)

#if(_D4_TMDS_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX4_TMDS_VIDEO_DETECT);

#if(_D4_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX4_TMDS_HDMI_PACKET_DETECT);
#endif // End of #if(_D4_HDMI_SUPPORT == _ON)
#endif // End of #if(_D4_TMDS_SUPPORT == _ON)

#if(_D5_TMDS_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX5_TMDS_VIDEO_DETECT);

#if(_D5_HDMI_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_RX5_TMDS_HDMI_PACKET_DETECT);
#endif // End of #if(_D5_HDMI_SUPPORT == _ON)
#endif // End of #if(_D5_TMDS_SUPPORT == _ON)
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Hdmi Handle AVMute Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiAVMuteProc(void)
{
#if(_D0_HDMI_SUPPORT == _ON)
    if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
    {
        ScalerTMDSRx0HdmiAVMuteProc();
    }
#endif

#if(_D1_HDMI_SUPPORT == _ON)
    if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
    {
        ScalerTMDSRx1HdmiAVMuteProc();
    }
#endif

#if(_D2_HDMI_SUPPORT == _ON)
    if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
    {
        ScalerTMDSRx2HdmiAVMuteProc();
    }
#endif

#if(_D3_HDMI_SUPPORT == _ON)
    if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
    {
        ScalerTMDSRx3HdmiAVMuteProc();
    }
#endif

#if(_D4_HDMI_SUPPORT == _ON)
    if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
    {
        ScalerTMDSRx4HdmiAVMuteProc();
    }
#endif

#if(_D5_HDMI_SUPPORT == _ON)
    if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
    {
        ScalerTMDSRx5HdmiAVMuteProc();
    }
#endif
}

//--------------------------------------------------
// Description  : Hdmi Enable Watch Dog
// Input Value  : ucWDType => Watch Dog type, bEnable => Enable watch dog flag
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiWatchDog(BYTE ucWDType, bit bEnable)
{
#if(_D0_HDMI_SUPPORT == _ON)
    ScalerTMDSRx0HdmiWatchDog(ucWDType, bEnable);
#endif // End of #if(_D0_HDMI_SUPPORT == _ON)

#if(_D1_HDMI_SUPPORT == _ON)
    ScalerTMDSRx1HdmiWatchDog(ucWDType, bEnable);
#endif // End of #if(_D1_HDMI_SUPPORT == _ON)

#if(_D2_HDMI_SUPPORT == _ON)
    ScalerTMDSRx2HdmiWatchDog(ucWDType, bEnable);
#endif // End of #if(_D2_HDMI_SUPPORT == _ON)

#if(_D3_HDMI_SUPPORT == _ON)
    ScalerTMDSRx3HdmiWatchDog(ucWDType, bEnable);
#endif // End of #if(_D3_HDMI_SUPPORT == _ON)

#if(_D4_HDMI_SUPPORT == _ON)
    ScalerTMDSRx4HdmiWatchDog(ucWDType, bEnable);
#endif // End of #if(_D4_HDMI_SUPPORT == _ON)

#if(_D5_HDMI_SUPPORT == _ON)
    ScalerTMDSRx5HdmiWatchDog(ucWDType, bEnable);
#endif // End of #if(_D5_HDMI_SUPPORT == _ON)

}

//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiPacketDetectEvent(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX0_TMDS_HDMI_PACKET_DETECT:

            ScalerTMDSRx0HdmiPacketDetectEvent();

            break;
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX1_TMDS_HDMI_PACKET_DETECT:

            ScalerTMDSRx1HdmiPacketDetectEvent();

            break;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX2_TMDS_HDMI_PACKET_DETECT:

            ScalerTMDSRx2HdmiPacketDetectEvent();

            break;
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX3_TMDS_HDMI_PACKET_DETECT:

            ScalerTMDSRx3HdmiPacketDetectEvent();

            break;
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX4_TMDS_HDMI_PACKET_DETECT:

            ScalerTMDSRx4HdmiPacketDetectEvent();

            break;
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX5_TMDS_HDMI_PACKET_DETECT:

            ScalerTMDSRx5HdmiPacketDetectEvent();

            break;
#endif

        default:

            break;
    }
}

#if(_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS Interrupt Process In PS/PD State(EXINT0 Only)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSPSIntHandler_EXINT0(void) using 1
{
#if(_D0_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx0PSIntHandler_EXINT0();
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx1PSIntHandler_EXINT0();
#endif
}

//--------------------------------------------------
// Description  : Hdmi Enable RR Timer
// Input Value  : bEnable => Enable RR Timer flag
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmiReadRequestTimerEnable_WDINT(bit bEnable) using 3
{
#if(_D0_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx0ReadRequestTimerEventEnable_WDINT(bEnable);
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
    ScalerTMDSRx1ReadRequestTimerEventEnable_WDINT(bEnable);
#endif
}

//--------------------------------------------------
// Description  : TMDS Format Reset Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHdmi2FormatResetEvent(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D0_HDMI_2_0_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX0_HDMI2_FORMAT_RESET_WAIT:
            ScalerTMDSRx0Hdmi2FormatResetEvent();
            break;
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _SCALER_TIMER_EVENT_RX1_HDMI2_FORMAT_RESET_WAIT:
            ScalerTMDSRx1Hdmi2FormatResetEvent();
            break;
#endif
        default:
            break;
    }
}
#endif // End of #if(_HDMI_2_0_SUPPORT == _ON)
/*
//--------------------------------------------------
// Description  : TMDS 420 Color Space Support Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerTMDSYUV420SupportCheck(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            // Check YCbCr 420 format; only support 8 bit
            if((ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420) &&
               (ScalerColorGetColorDepth() > _COLOR_DEPTH_8_BITS))
            {
                return _FALSE;
            }

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            // Check YCbCr 420 format; only support 8 bit
            if((ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420) &&
               (ScalerColorGetColorDepth() > _COLOR_DEPTH_8_BITS))
            {
                return _FALSE;
            }

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        case _D2_INPUT_PORT:

            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420)
            {
                return _FALSE;
            }

            break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)
        case _D3_INPUT_PORT:

            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420)
            {
                return _FALSE;
            }

            break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)
        case _D4_INPUT_PORT:

            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420)
            {
                return _FALSE;
            }

            break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)
        case _D5_INPUT_PORT:

            if(ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420)
            {
                return _FALSE;
            }

            break;
#endif
        default:
            break;
    }

    return _TRUE;
}
*/
#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDMI freesync initial
// Input Value  : support or not
// Output Value :
//--------------------------------------------------
void ScalerTMDSFreesyncInitial(bit bSupport)
{
    SET_FREESYNC_SUPPORT(bSupport);

#if(_D0_HDMI_SUPPORT == _ON)
    SET_TMDS_RX0_FREESYNC_SUPPORT(bSupport);
#endif

#if(_D1_HDMI_SUPPORT == _ON)
    SET_TMDS_RX1_FREESYNC_SUPPORT(bSupport);
#endif

#if(_D2_HDMI_SUPPORT == _ON)
    SET_TMDS_RX2_FREESYNC_SUPPORT(bSupport);
#endif

#if(_D3_HDMI_SUPPORT == _ON)
    SET_TMDS_RX3_FREESYNC_SUPPORT(bSupport);
#endif

#if(_D4_HDMI_SUPPORT == _ON)
    SET_TMDS_RX4_FREESYNC_SUPPORT(bSupport);
#endif

#if(_D5_HDMI_SUPPORT == _ON)
    SET_TMDS_RX5_FREESYNC_SUPPORT(bSupport);
#endif
}

//--------------------------------------------------
// Description  : Dp Get AMD SPD info
// Input Value  : None
// Output Value :
//--------------------------------------------------
BYTE ScalerTMDSHdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent)
{
    switch(ScalerFmtCnvGetSourceType())
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _FC_SOURCE_D0:

            return ScalerTMDSRx0HdmiGetAmdSpdInfo(enumContent);
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _FC_SOURCE_D1:

            return ScalerTMDSRx1HdmiGetAmdSpdInfo(enumContent);
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _FC_SOURCE_D2:

            return ScalerTMDSRx2HdmiGetAmdSpdInfo(enumContent);
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _FC_SOURCE_D3:

            return ScalerTMDSRx3HdmiGetAmdSpdInfo(enumContent);
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _FC_SOURCE_D4:

            return ScalerTMDSRx4HdmiGetAmdSpdInfo(enumContent);
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _FC_SOURCE_D5:

            return ScalerTMDSRx5HdmiGetAmdSpdInfo(enumContent);
#endif

        default:

            return 0;
    }
}
#endif // #if(_HDMI_FREESYNC_SUPPORT == _ON)

#endif // End of #if(_HDMI_SUPPORT == _ON)

//--------------------------------------------------
// Description  : TMDS Freq. Detection IRQ Disable and Clear Clock Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSFreqDetectDisable(void)
{
#if(_D0_TMDS_SUPPORT == _ON)
    ScalerTMDSRx0FreqDetectDisable();
#endif

#if(_D1_TMDS_SUPPORT == _ON)
    ScalerTMDSRx1FreqDetectDisable();
#endif

#if(_D2_TMDS_SUPPORT == _ON)
    ScalerTMDSRx2FreqDetectDisable();
#endif

#if(_D3_TMDS_SUPPORT == _ON)
    ScalerTMDSRx3FreqDetectDisable();
#endif

#if(_D4_TMDS_SUPPORT == _ON)
    ScalerTMDSRx4FreqDetectDisable();
#endif

#if(_D5_TMDS_SUPPORT == _ON)
    ScalerTMDSRx5FreqDetectDisable();
#endif
}

//--------------------------------------------------
// Description  : Process Required when Switched to Active State
// Input Value  : Input Source
// Output Value : None
//--------------------------------------------------
void ScalerTMDSFirstActiveProc(BYTE ucInputPort, BYTE ucSourceType)
{
    ucSourceType = ucSourceType;

    switch(ucInputPort)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            ScalerTMDSRx0FirstActiveProc(ucSourceType);
            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            ScalerTMDSRx1FirstActiveProc(ucSourceType);
            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            ScalerTMDSRx2FirstActiveProc(ucSourceType);
            break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)
        case _D3_INPUT_PORT:
            ScalerTMDSRx3FirstActiveProc(ucSourceType);
            break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)
        case _D4_INPUT_PORT:
            ScalerTMDSRx4FirstActiveProc(ucSourceType);
            break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)
        case _D5_INPUT_PORT:
            ScalerTMDSRx5FirstActiveProc(ucSourceType);
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : None
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerTMDSHdcpEnabled(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            return ScalerTMDSRx0HdcpEnabled();
#endif

            break;

        case _D1_INPUT_PORT:

#if((_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            return ScalerTMDSRx1HdcpEnabled();
#endif

            break;

        case _D2_INPUT_PORT:

#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            return ScalerTMDSRx2HdcpEnabled();
#elif(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)
            return ScalerTMDSRx3HdcpEnabled();
#endif

            break;

        case _D3_INPUT_PORT:

#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            return ScalerTMDSRx3HdcpEnabled();
#elif(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)
            return ScalerTMDSRx4HdcpEnabled();
#endif

            break;

        case _D4_INPUT_PORT:

#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
            return ScalerTMDSRx4HdcpEnabled();
#elif(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)
            return ScalerTMDSRx5HdcpEnabled();
#endif

            break;

        case _D5_INPUT_PORT:

#if((_D5_INPUT_PORT_TYPE == _D5_DVI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
            return ScalerTMDSRx5HdcpEnabled();
#endif

            break;

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Signal PreDetection for TMDS(Power Normal)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSNormalPreDetect(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_TMDS_SUPPORT == _ON)
            return ScalerTMDSRx0TMDSNormalPreDetect();
#endif

            break;

        case _D1_INPUT_PORT:

#if(_D1_TMDS_SUPPORT == _ON)
            return ScalerTMDSRx1TMDSNormalPreDetect();
#endif

            break;

        case _D2_INPUT_PORT:

#if((_D2_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT))
            return ScalerTMDSRx2TMDSNormalPreDetect();
#endif

            break;

        case _D3_INPUT_PORT:

#if((_D3_TMDS_SUPPORT == _ON) &&\
    (_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT) &&\
    (_D3_INPUT_PORT_TYPE != _D3_NO_PORT))
            return ScalerTMDSRx3TMDSNormalPreDetect();
#endif

            break;

        case _D4_INPUT_PORT:

#if((_D4_TMDS_SUPPORT == _ON) &&\
    (_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT) &&\
    (_D4_INPUT_PORT_TYPE != _D4_NO_PORT))
            return ScalerTMDSRx4TMDSNormalPreDetect();
#endif

            break;

        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
            return ScalerTMDSRx5TMDSNormalPreDetect();
#endif

            break;

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : TMDS Port Source/Sync Scanning and Setting
// Input Value  : Input Port
// Output Value : Source DVI --> DVI Format
//                Source HDMI --> HDMI Format
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerTMDSScanInputPort(BYTE ucInputPort, BYTE ucInputType)
{
    ucInputType = ucInputType;

    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_TMDS_SUPPORT == _ON)
            return ScalerTMDSRx0TMDSScanInputPort(ucInputType);
#endif

            break;

        case _D1_INPUT_PORT:

#if(_D1_TMDS_SUPPORT == _ON)
            return ScalerTMDSRx1TMDSScanInputPort(ucInputType);
#endif

            break;

        case _D2_INPUT_PORT:

#if((_D2_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT))
            return ScalerTMDSRx2TMDSScanInputPort(ucInputType);
#endif

            break;

        case _D3_INPUT_PORT:

#if((_D3_TMDS_SUPPORT == _ON) &&\
    (_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT) &&\
    (_D3_INPUT_PORT_TYPE != _D3_NO_PORT))
            return ScalerTMDSRx3TMDSScanInputPort(ucInputType);
#endif

            break;

        case _D4_INPUT_PORT:

#if((_D4_TMDS_SUPPORT == _ON) &&\
    (_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT) &&\
    (_D4_INPUT_PORT_TYPE != _D4_NO_PORT))
            return ScalerTMDSRx4TMDSScanInputPort(ucInputType);
#endif

            break;

        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
            return ScalerTMDSRx5TMDSScanInputPort(ucInputType);
#endif

            break;

        default:

            break;
    }

    return _SOURCE_NONE;
}

//--------------------------------------------------
// Description  : Signal Detection for TMDS(Power Saving)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerTMDSPSPreDetect(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if(_D0_TMDS_SUPPORT == _ON)
            return ScalerTMDSRx0TMDSPSPreDetect();
#endif

            break;

        case _D1_INPUT_PORT:

#if(_D1_TMDS_SUPPORT == _ON)
            return ScalerTMDSRx1TMDSPSPreDetect();
#endif

            break;

        case _D2_INPUT_PORT:

#if((_D2_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT))
            return ScalerTMDSRx2TMDSPSPreDetect();
#endif

            break;

        case _D3_INPUT_PORT:

#if((_D3_TMDS_SUPPORT == _ON) &&\
    (_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT) &&\
    (_D3_INPUT_PORT_TYPE != _D3_NO_PORT))
            return ScalerTMDSRx3TMDSPSPreDetect();
#endif

            break;

        case _D4_INPUT_PORT:

#if((_D4_TMDS_SUPPORT == _ON) &&\
    (_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT) &&\
    (_D4_INPUT_PORT_TYPE != _D4_NO_PORT))
            return ScalerTMDSRx4TMDSPSPreDetect();
#endif

            break;

        case _D5_INPUT_PORT:

#if((_D5_TMDS_SUPPORT == _ON) && (_D5_INPUT_PORT_TYPE != _D5_NO_PORT))
            return ScalerTMDSRx5TMDSPSPreDetect();
#endif

            break;

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : On Line Check TMDS stability
// Input Value  : ucSourceType --> Source Type
// Output Value : True --> TMDS Stable
//                False --> TMDS Unstable
//--------------------------------------------------
bit ScalerTMDSStableDetect(BYTE ucInputPort, BYTE ucSourceType)
{
    switch(ucSourceType)
    {
        case _SOURCE_DVI:
        case _SOURCE_HDMI:

            switch(ucInputPort)
            {
#if(_D0_TMDS_SUPPORT == _ON)
                case _D0_INPUT_PORT:
                    return ScalerTMDSRx0TMDSStableDetect(ucSourceType);
#endif

#if(_D1_TMDS_SUPPORT == _ON)
                case _D1_INPUT_PORT:
                    return ScalerTMDSRx1TMDSStableDetect(ucSourceType);
#endif

#if(_D2_TMDS_SUPPORT == _ON)

                case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
                    return ScalerTMDSRx2TMDSStableDetect(ucSourceType);
#else
                    if(ScalerDualLinkDVIGetDualDVIMode(_D2_INPUT_PORT) == _TRUE)
                    {
                        return ((ScalerTMDSRx2TMDSStableDetect(ucSourceType) == _TRUE) &&
                                (ScalerTMDSRx3TMDSStableDetect(ucSourceType) == _TRUE));
                    }
                    else
                    {
                        return ScalerTMDSRx3TMDSStableDetect(ucSourceType);
                    }
#endif

#endif

#if(_D3_TMDS_SUPPORT == _ON)

                case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
                    return ScalerTMDSRx3TMDSStableDetect(ucSourceType);
#else
                    if(ScalerDualLinkDVIGetDualDVIMode(_D3_INPUT_PORT) == _TRUE)
                    {
                        return ((ScalerTMDSRx3TMDSStableDetect(ucSourceType) == _TRUE) &&
                                (ScalerTMDSRx4TMDSStableDetect(ucSourceType) == _TRUE));
                    }
                    else
                    {
                        return ScalerTMDSRx4TMDSStableDetect(ucSourceType);
                    }
#endif


#endif

#if(_D4_TMDS_SUPPORT == _ON)

                case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT)
                    return ScalerTMDSRx4TMDSStableDetect(ucSourceType);
#else
                    if(ScalerDualLinkDVIGetDualDVIMode(_D4_INPUT_PORT) == _TRUE)
                    {
                        return ((ScalerTMDSRx4TMDSStableDetect(ucSourceType) == _TRUE) &&
                                (ScalerTMDSRx5TMDSStableDetect(ucSourceType) == _TRUE));
                    }
                    else
                    {
                        return ScalerTMDSRx5TMDSStableDetect(ucSourceType);
                    }
#endif
#endif

#if(_D5_TMDS_SUPPORT == _ON)
                case _D5_INPUT_PORT:
                    return ScalerTMDSRx5TMDSStableDetect(ucSourceType);
#endif
                default:
                    break;
            }

            break;

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : TMDS Hot Plug Event
// Input Value  : None
// Output Value :
//--------------------------------------------------
void ScalerTMDSHotPlugEvent(BYTE ucPortSelect)
{
    switch(ucPortSelect)
    {
#if(_D0_TMDS_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            ScalerTMDSRx0HotPlugEvent();

            break;
#endif

#if(_D1_TMDS_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            ScalerTMDSRx1HotPlugEvent();

            break;
#endif

#if(_D2_TMDS_SUPPORT == _ON)
        case _D2_INPUT_PORT:

            ScalerTMDSRx2HotPlugEvent();

            break;
#endif

#if(_D3_TMDS_SUPPORT == _ON)
        case _D3_INPUT_PORT:

            ScalerTMDSRx3HotPlugEvent();

            break;
#endif

#if(_D4_TMDS_SUPPORT == _ON)
        case _D4_INPUT_PORT:

            ScalerTMDSRx4HotPlugEvent();

            break;
#endif

#if(_D5_TMDS_SUPPORT == _ON)
        case _D5_INPUT_PORT:

            ScalerTMDSRx5HotPlugEvent();

            break;
#endif
        default:

            break;
    }
}
#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

