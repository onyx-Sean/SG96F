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
// ID Code      : RL6193_Series_TMDSInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
extern void ScalerTMDSIntHandler_EXINT0(void);

#if(_HDMI_SUPPORT == _ON)

#if(_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSPSIntHandler_EXINT0(void);
#endif

//extern bit ScalerTMDSYUV420SupportCheck(BYTE ucInputPort);

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern void ScalerTMDSFreesyncInitial(bit bSupport);
extern BYTE ScalerTMDSHdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif
#endif

extern bit ScalerTMDSNormalPreDetect(BYTE ucInputPort);
extern BYTE ScalerTMDSScanInputPort(BYTE ucInputPort, BYTE ucInputType);
extern bit ScalerTMDSPSPreDetect(BYTE ucInputPort);
extern bit ScalerTMDSStableDetect(BYTE ucInputPort, BYTE ucSourceType);
extern void ScalerTMDSHotPlugEvent(BYTE ucPortSelect);
#endif
