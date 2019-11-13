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
// ID Code      : ScalerMHL3Rx3_SeptPhyInclude.h No.0000
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
#if((_D3_INPUT_PORT_TYPE == _D3_MHL_PORT) && (_D3_MHL_VERSION >= _MHL_VERSION_3_0))
extern void ScalerMHL3Rx3BISTHandler(void);
extern bit ScalerMHL3Rx3DataSignalDetect(void);
extern void ScalerMHL3Rx3DisplatFormatGenAdjustHsyncDelay(DWORD ulPixelClkValue);
extern void ScalerMHL3Rx3DisplayFormatGenAdjustVsyncDelay(DWORD ulPixelClkValue);
extern bit ScalerMHL3Rx3DisplayFormatGenFifoCheck(void);
extern void ScalerMHL3Rx3ECBUSConfigureSettings(void);
extern BYTE ScalerMHL3Rx3ECBUSEMSCRxHandler(void);
extern bit ScalerMHL3Rx3ECBUSEMSCTxHandler(void);
extern bit ScalerMHL3Rx3ECBUSHandler(void);
extern void ScalerMHL3Rx3ECBUSInitialSetting(void);
extern void ScalerMHL3Rx3ECBUSIntHandler_EXINT0(void);
extern void ScalerMHL3Rx3ECBUSResetProc(void);
extern void ScalerMHL3Rx3ECBUSResetProc_EXINT0(void);
extern bit ScalerMHL3Rx3ECBUSTdmReallocation(void);
extern void ScalerMHL3Rx3EnableECBUSMode(bit bEnable);
extern void ScalerMHL3Rx3EnableECBUSMode_EXINT0(bit bEnable);
extern bit ScalerMHL3Rx3FakePowerSavingCheck(void);
extern BYTE ScalerMHL3Rx3FormatDetect(void);
extern bit ScalerMHL3Rx3MeasureCheck(void);
extern void ScalerMHL3Rx3MeasureReset(void);
extern DWORD ScalerMHL3Rx3StreamClkRegenerate(void);
extern void ScalerMHL3Rx3TimerEventProc(EnumScalerTimerEventID enumEventID);
extern bit ScalerMHL3Rx3ViewPixelFormatCheck(void);
extern void ScalerMHL3Rx3WDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID, BYTE *pucActiveWDID, BYTE *pucActiveWDTime);
#endif
