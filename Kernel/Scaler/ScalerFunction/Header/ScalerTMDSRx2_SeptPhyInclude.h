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
// ID Code      : ScalerTMDSRx2_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D2_TMDS_SUPPORT == _ON)
extern void ScalerTMDSRx2DviVideoSetting(void);
extern void ScalerTMDSRx2FirstActiveProc(BYTE ucSourceType);
extern void ScalerTMDSRx2PowerOffProc(void);
extern BYTE ScalerTMDSRx2TMDSVideoDetect(bit bWait);
extern void ScalerTMDSRx2TMDSVideoDetectEvent(void);

#if((_D2_INPUT_PORT_TYPE == _D2_MHL_PORT) && (_D2_MHL_VERSION >= _MHL_VERSION_3_0))
extern void ScalerTMDSRx2MHL3SetCmu_EXINT0(BYTE ucCmuSel);

#if(_MHL3_ECBUS_AVLINK_CDR_MODE == _ACDR_MODE)
extern void ScalerTMDSRx2MHL3AcdrSetPhy(void);
extern void ScalerTMDSRx2MHL3AcdrSetPhy_EXINT0(void);
#endif

#if(_MHL3_ECBUS_AVLINK_CDR_MODE == _DCDR_MODE)
extern void ScalerTMDSRx2MHL3DcdrSetPhy(void);
extern void ScalerTMDSRx2MHL3DcdrSetPhy_EXINT0(void);
#endif

#endif

#if(_D2_HDMI_SUPPORT == _ON)
extern bit ScalerTMDSRx2HdmiAviPixelRepInfoChanged(void);
extern BYTE ScalerTMDSRx2HdmiGetAVIInfo(EnumAviInfoContent enumContent);
extern BYTE ScalerTMDSRx2HdmiGetColorDepth(void);
extern void ScalerTMDSRx2HdmiPacketDetectEvent(void);

#if(_D2_HDMI_2_0_SUPPORT == _ON)
extern void ScalerTMDSRx2HDMI2HPDRRIRQEnable(bit bEnable);
extern void ScalerTMDSRx2Hdmi2FormatResetEvent(void);
extern void ScalerTMDSRx2PSIntHandler_EXINT0(void);
extern void ScalerTMDSRx2ReadRequestProc_EXINT0(BYTE ucRROutCome);
extern void ScalerTMDSRx2ReadRequestTimerEventEnable_WDINT(bit bEnable);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
extern bit ScalerTMDSRx2HdmiDeepColorProc(WORD usTmdsClkCnt);
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
extern BYTE ScalerTMDSRx2HdmiGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
#endif

#endif

#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
extern bit ScalerTMDSRx2TMDSNormalPreDetect(void);
extern bit ScalerTMDSRx2TMDSPSPreDetect(void);
#endif

#endif

#endif
