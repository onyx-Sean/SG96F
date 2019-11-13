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
// ID Code      : ScalerDPTxInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_TX_SUPPORT == _ON)
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
extern void ScalerDpTxInitialReset(void);
extern void ScalerDpTxVersionCheck(BYTE ucDpVersion);
extern void ScalerDpTxLinkRateCheck(BYTE ucDpTxLinkRate);
extern bit ScalerDpTxTPSxSupportCheck(void);
extern void ScalerDpTxSSTDisplayFormatSetting(void);
extern BYTE ScalerDpTxSetTPSxPattern(void);
extern bit ScalerDpTxLinkRateReduce(EnumDPTxLTResult enumDPTxLTResult);
extern bit ScalerDpTxLaneCountReduce(EnumDPTxLTResult enumDPTxLTResult);
extern void ScalerDpTxSignalInitialSetting(void);
extern bit ScalerDpTxMeasureGetMeasureResult(StructMeasureSyncData *pstMeasureSyncHV);
extern bit ScalerDpTxMeasureInputInfo(void);
extern bit ScalerDpTxCloneCheckInterlaceVtotal(void);
extern void ScalerDpTxCloneSwitchFormatConversionMux(BYTE ucInputPort);

#endif // End of #if(_DP_TX_SUPPORT == _ON)
