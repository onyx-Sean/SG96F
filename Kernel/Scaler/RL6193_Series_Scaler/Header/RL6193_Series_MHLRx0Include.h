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
// ID Code      : RL6193_Series_MHLRx0Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macros of MHL Adopter ID
//--------------------------------------------------
#define GET_MHL_RX0_ADOPTER_ID_HBYTE()                  (g_ucMHLRx0AdopterIDH)
#define GET_MHL_RX0_ADOPTER_ID_LBYTE()                  (g_ucMHLRx0AdopterIDL)
#define CLR_MHL_RX0_ADOPTER_ID_HBYTE()                  (g_ucMHLRx0AdopterIDH = 0xFF)
#define CLR_MHL_RX0_ADOPTER_ID_LBYTE()                  (g_ucMHLRx0AdopterIDL = 0xFF)

#define GET_MHL_RX0_PROCESS_STATE()                     (g_stMHLRx0Process.b4MHLProcessState)
#define SET_MHL_RX0_PROCESS_STATE(x)                    (g_stMHLRx0Process.b4MHLProcessState = (x))

#define GET_MHL_RX0_READY_TO_TRANSMIT()                 (g_stMHLRx0Process.b1MHLTransmitStatus)
#define SET_MHL_RX0_READY_TO_TRANSMIT()                 (g_stMHLRx0Process.b1MHLTransmitStatus = _TRUE)
#define CLR_MHL_RX0_READY_TO_TRANSMIT()                 (g_stMHLRx0Process.b1MHLTransmitStatus = _FALSE)

#define GET_MHL_RX0_READY_TO_RESEND()                   (g_stMHLRx0Process.b1MHLResendStatus)
#define SET_MHL_RX0_READY_TO_RESEND()                   (g_stMHLRx0Process.b1MHLResendStatus = _TRUE)
#define CLR_MHL_RX0_READY_TO_RESEND()                   (g_stMHLRx0Process.b1MHLResendStatus = _FALSE)

#define GET_MHL_RX0_SWITCH_PORT_DISCOVERY_DONE()        (g_stMHLRx0Process.b1MHLSwitchPortDiscoveryDoneStatus)
#define SET_MHL_RX0_SWITCH_PORT_DISCOVERY_DONE()        (g_stMHLRx0Process.b1MHLSwitchPortDiscoveryDoneStatus = _TRUE)
#define CLR_MHL_RX0_SWITCH_PORT_DISCOVERY_DONE()        (g_stMHLRx0Process.b1MHLSwitchPortDiscoveryDoneStatus = _FALSE)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern BYTE g_ucMHLRx0AdopterIDH;
extern BYTE g_ucMHLRx0AdopterIDL;
extern StructMHLProcessInfo g_stMHLRx0Process;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMHLRx0ModeMHLSetting(void);
extern void ScalerMHLRx0ModeHdmiSetting(void);
extern void ScalerMHLRx0InitialSettings(void);
extern void ScalerMHLRx0CBUSPhySwitch(bit bSelect);
extern void ScalerMHLRx0CBUSSwitchClk(EnumClkSel enumClockSel);
extern void ScalerMHLRx0CBUSResetProc(void);
extern void ScalerMHLRx0PowerOffProc(void);
extern bit ScalerMHLRx0DetectClkMode(void);
extern BYTE ScalerMHLRx0DetectClkMode_EXINT0(void);
extern void ScalerMHLRx0IntHandler_EXINT0(void);
extern bit ScalerMHLRx0MscSendCommand(EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
extern void ScalerMHLRx0MscCheckDeviceINT(void);
extern bit ScalerMHLRx0MscHandler(BYTE ucActivePort, BYTE ucModeState);
extern bit ScalerMHLRx0MscRAPHandler(void);
extern bit ScalerMHLRx0MscRCPGetCommand(BYTE *pucKeyCode);

#if(_MHL_UCP_SUPPORT == _ON)
extern BYTE ScalerMHLRx0MscUCPGetCommand(BYTE *pucKeyCode);
#endif

extern bit ScalerMHLRx0PSPreDetect(void);
extern bit ScalerMHLRx0NormalPreDetect(void);
extern void ScalerMHLRx0TimerEventProc(EnumScalerTimerEventID enumEventID);

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
