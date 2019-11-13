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
// ID Code      : RL6193_Series_FRCInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Deinfe FRC setting path
//--------------------------------------------------
#define _FRC_CAP_MAIN_1                                 (_BIT0)
#define _FRC_CAP_MAIN_2                                 (_BIT1)
#define _FRC_CAP_SUB_1                                  (_BIT2)
#define _FRC_CAP_SUB_2                                  (_BIT3)

#define _FRC_DISP_MAIN_1                                (_BIT4)
#define _FRC_DISP_MAIN_2                                (_BIT5)
#define _FRC_DISP_SUB_1                                 (_BIT6)
#define _FRC_DISP_SUB_2                                 (_BIT7) // Only for 4P Case / PBP_TB

#define _FRC_CAP_DISP_ALL                               (_FRC_CAP_MAIN_1 | _FRC_CAP_MAIN_2 | _FRC_CAP_SUB_1 | _FRC_CAP_SUB_2 | _FRC_DISP_MAIN_1 | _FRC_DISP_MAIN_2 | _FRC_DISP_SUB_1 | _FRC_DISP_SUB_2)

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
extern void ScalerFRCEn(BYTE ucSettingPath, bit bEn);
#endif

#if(_FRC_SUPPORT == _ON)
extern void ScalerFRCWaitWriteFrameBufFinish(void);

#if(_FREEZE_SUPPORT == _ON)
extern void ScalerFRCDisplayFreeze(bit bEn);
#endif
#endif

extern void ScalerFRCSetDDomainSourceSelect(EnumDDomainSourceSelect enumSourceSelect);
