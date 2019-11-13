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
// ID Code      : ScalerDP_ComboPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
//  DP LEQ RELOAD Define
//--------------------------------------------------
#define _DP_RELOAD_LEQ_INITIAL                            0
#define _DP_RELOAD_LEQ_LARGE                              1
#define _DP_RELOAD_LEQ_DEFAULT                            2
#define _DP_RELOAD_LEQ_SMALL                              3


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_DP_SUPPORT == _ON)
extern void ScalerDpDpcdLinkStatusReset(BYTE ucInputPort);
extern void ScalerDpFakeLinkTrainingSetting(BYTE ucInputPort);
extern void ScalerDpFirstActiveProc(BYTE ucInputPort);
extern bit ScalerDpHdcpCheckEnabled(BYTE ucInputPort);
extern void ScalerDpHotPlugEvent(BYTE ucInputPort, EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpLowPowerProc(void);
extern void ScalerDpResetProc(void);

#if(_DP_FREESYNC_SUPPORT == _ON)
extern WORD ScalerDpGetHSPeriod(void);
extern WORD ScalerDpGetHSW(void);
extern WORD ScalerDpGetVFreq(void);
extern WORD ScalerDpGetVSPeriod(void);
#endif

#endif
