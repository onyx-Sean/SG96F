/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6193_Series_TMDSRx4Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#if(_D4_TMDS_SUPPORT == _ON)
//--------------------------------------------------
// Macro of PHY Set Flag
//--------------------------------------------------
#define GET_TMDS_RX4_PHY_SET()                          (g_stTMDSRx4CtrlInfo.b1TMDSPhySet)
#define SET_TMDS_RX4_PHY_SET()                          (g_stTMDSRx4CtrlInfo.b1TMDSPhySet = _TRUE)
#define CLR_TMDS_RX4_PHY_SET()                          (g_stTMDSRx4CtrlInfo.b1TMDSPhySet = _FALSE)

//--------------------------------------------------
// Macro of TMDS Video Detecting Flag
//--------------------------------------------------
#define GET_TMDS_RX4_RGBHV_DETECTING()                  (g_stTMDSRx4CtrlInfo.b1RGBHVDetecting)
#define SET_TMDS_RX4_RGBHV_DETECTING()                  (g_stTMDSRx4CtrlInfo.b1RGBHVDetecting = _TRUE)
#define CLR_TMDS_RX4_RGBHV_DETECTING()                  (g_stTMDSRx4CtrlInfo.b1RGBHVDetecting = _FALSE)

//--------------------------------------------------
// Macro of Packet Detecting Flag
//--------------------------------------------------
#define GET_HDMI_RX4_PACKET_DETECTING()                 (g_stTMDSRx4CtrlInfo.b1PacketDetecting)
#define SET_HDMI_RX4_PACKET_DETECTING()                 (g_stTMDSRx4CtrlInfo.b1PacketDetecting = _TRUE)
#define CLR_HDMI_RX4_PACKET_DETECTING()                 (g_stTMDSRx4CtrlInfo.b1PacketDetecting = _FALSE)

//--------------------------------------------------
// Macro of AVI Info Frame Received Flag
//--------------------------------------------------
#define GET_HDMI_RX4_AVI_INFO_FRAME_RECEIVED()          (g_stTMDSRx4CtrlInfo.b1AVIInfoFrameReceived)
#define SET_HDMI_RX4_AVI_INFO_FRAME_RECEIVED()          (g_stTMDSRx4CtrlInfo.b1AVIInfoFrameReceived = _TRUE)
#define CLR_HDMI_RX4_AVI_INFO_FRAME_RECEIVED()          (g_stTMDSRx4CtrlInfo.b1AVIInfoFrameReceived = _FALSE)

//--------------------------------------------------
// Macro of GCP Received Flag
//--------------------------------------------------
#define GET_HDMI_RX4_GCP_RECEIVED()                     (g_stTMDSRx4CtrlInfo.b1GCPReceived)
#define SET_HDMI_RX4_GCP_RECEIVED()                     (g_stTMDSRx4CtrlInfo.b1GCPReceived = _TRUE)
#define CLR_HDMI_RX4_GCP_RECEIVED()                     (g_stTMDSRx4CtrlInfo.b1GCPReceived = _FALSE)

//--------------------------------------------------
// Macro of the Fiset Time of Z0 Asserted
//--------------------------------------------------
#define GET_TMDS_RX4_Z0_ASSERTED()                      (g_stTMDSRx4CtrlInfo.b1Z0Asserted)
#define SET_TMDS_RX4_Z0_ASSERTED()                      (g_stTMDSRx4CtrlInfo.b1Z0Asserted = _TRUE)
#define CLR_TMDS_RX4_Z0_ASSERTED()                      (g_stTMDSRx4CtrlInfo.b1Z0Asserted = _FALSE)

//--------------------------------------------------
// Macro of HPD Evnet Trigger
//--------------------------------------------------
#define GET_TMDS_RX4_HPD_TRIGGER_EVENT()                (g_stTMDSRx4CtrlInfo.b3HPDTriggerEvent)
#define SET_TMDS_RX4_HPD_TRIGGER_EVENT(x)               (g_stTMDSRx4CtrlInfo.b3HPDTriggerEvent = (x))
#define CLR_TMDS_RX4_HPD_TRIGGER_EVENT()                (g_stTMDSRx4CtrlInfo.b3HPDTriggerEvent = _TMDS_HPD_NONE)

#define GET_TMDS_RX4_DDC_DETECTED()                     (g_stTMDSRx4CtrlInfo.b1TMDSDdcDetected)
#define SET_TMDS_RX4_DDC_DETECTED()                     (g_stTMDSRx4CtrlInfo.b1TMDSDdcDetected = _TRUE)
#define CLR_TMDS_RX4_DDC_DETECTED()                     (g_stTMDSRx4CtrlInfo.b1TMDSDdcDetected = _FALSE)

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define GET_TMDS_RX4_CLK_MODE()                         (g_ucTMDSRx4ClkMode)
#define SET_TMDS_RX4_CLK_MODE(x)                        (g_ucTMDSRx4ClkMode = (x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern StructTMDSCtrlInfo g_stTMDSRx4CtrlInfo;
extern WORD g_usTMDSRx4ClkCount;

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
extern BYTE g_ucTMDSRx4ClkMode;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerTMDSRx4Initial(void);
extern void ScalerTMDSRx4InterruptInitial(void);
extern void ScalerTMDSRx4IntHandler_EXINT0(void);
extern bit ScalerTMDSRx4CheckCDRStable(WORD usClkCount);
extern BYTE ScalerTMDSRx4CheckCDRStable_EXINT0(WORD usClkCount);

#if(_D4_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx4HdmiSetDeepColorPll(WORD usTMDSClkCount, BYTE ucColorDepth);
extern void ScalerTMDSRx4HdmiAVMuteProc(void);

#endif

extern void ScalerTMDSRx4PowerSavingProc(void);
extern void ScalerTMDSRx4FreqDetectDisable(void);

#if(_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT)

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
extern BYTE ScalerTMDSRx4TMDSScanInputPort(BYTE ucInputType);
#endif // End of #if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)

extern BYTE ScalerTMDSRx4FormatDetect(void);
extern bit ScalerTMDSRx4HdcpEnabled(void);
#endif // End of #if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
extern bit ScalerTMDSRx4CheckDataDFE(void);

extern bit ScalerTMDSRx4TMDSStableDetect(BYTE ucSourceType);
extern void ScalerTMDSRx4HotPlugEvent(void);

#endif // End of #if(_D4_TMDS_SUPPORT == _ON)

