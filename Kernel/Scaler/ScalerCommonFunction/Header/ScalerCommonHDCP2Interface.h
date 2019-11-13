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
// ID Code      : ScalerCommonHDCP2Interface.h No.0000
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
#if(_HDCP_2_2_FUNCTION_GEN == _HDCP_2_2_GEN_2)
#if(_HDCP_2_2_SUPPORT == _ON)
extern void ScalerHdcp2DownLoadCalculateKey(WORD usSubAddr, WORD usLength, BYTE *pucReadArray, BYTE ucRSAType);
extern void ScalerHdcp2Handler(void);
extern void ScalerHdcp2IntHandler_EXINT0(void);
extern void ScalerHdcp2ResetProc(BYTE ucInputPort);
extern bit ScalerHdcp2RxPairingCalculate(BYTE *pucHdcp2KPriv, BYTE ucIndex);
#endif
#endif

