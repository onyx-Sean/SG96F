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
// ID Code      : ScalerMHL3Rx2_SeptPhyInclude.h No.0000
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
#if((_D2_INPUT_PORT_TYPE == _D2_MHL_PORT) && (_D2_MHL_VERSION >= _MHL_VERSION_3_0))
extern void ScalerMHL3Rx2BISTHandler(void);
extern bit ScalerMHL3Rx2DataSignalDetect(void);
extern void ScalerMHL3Rx2DisplatFormatGenAdjustHsyncDelay(DWORD ulPixelClkValue);
extern void ScalerMHL3Rx2DisplayFormatGenAdjustVsyncDelay(DWORD ulPixelClkValue);
extern bit ScalerMHL3Rx2DisplayFormatGenFifoCheck(void);
extern void ScalerMHL3Rx2ECBUSConfigureSettings(void);
extern BYTE ScalerMHL3Rx2ECBUSEMSCRxHandler(void);
extern bit ScalerMHL3Rx2ECBUSEMSCTxHandler(void);
extern bit ScalerMHL3Rx2ECBUSHandler(void);
extern void ScalerMHL3Rx2ECBUSInitialSetting(void);
extern void ScalerMHL3Rx2ECBUSIntHandler_EXINT0(void);
extern void ScalerMHL3Rx2ECBUSResetProc(void);
extern void ScalerMHL3Rx2ECBUSResetProc_EXINT0(void);
extern bit ScalerMHL3Rx2ECBUSTdmReallocation(void);
extern void ScalerMHL3Rx2EnableECBUSMode(bit bEnable);
extern void ScalerMHL3Rx2EnableECBUSMode_EXINT0(bit bEnable);
extern bit ScalerMHL3Rx2FakePowerSavingCheck(void);
extern BYTE ScalerMHL3Rx2FormatDetect(void);
extern bit ScalerMHL3Rx2MeasureCheck(void);
extern void ScalerMHL3Rx2MeasureReset(void);
extern DWORD ScalerMHL3Rx2StreamClkRegenerate(void);
extern void ScalerMHL3Rx2TimerEventProc(EnumScalerTimerEventID enumEventID);
extern bit ScalerMHL3Rx2ViewPixelFormatCheck(void);
extern void ScalerMHL3Rx2WDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID, BYTE *pucActiveWDID, BYTE *pucActiveWDTime);

#if(_ECBUS_RX_TEST_FUNCTION == _ON)
extern void ScalerMHL3Rx2ECBUSRxTestSettingFunction(void);
#endif

#if(_ECBUS_TX_TEST_FUNCTION == _ON)
extern void ScalerMHL3Rx2ECBUSTxTestSettingFunction(void);
#endif

#if(_MHL3_TEST_FUNCTION_DEBUG_MODE == _ON)
extern void ScalerMHL3Rx2TestPinSetting(BYTE ucMode);
#endif

#endif
