/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2012>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6193_QC_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
//************************************  For RL6193  *********************************************
// 1. RL6193_Project.h:
//    (1). _PCB_TYPE = _RL6193_QA_B_1A1H4MHL1DP_DPTX_LVDS_eDP
//    (2). _PANEL_TYPE = _AUO_LED_DP_32_UHD
//    (3). _OSD_TYPE = _NONE_OSD
// 2. Debug.h:
//    -> _DEBUG_MESSAGE_QC = _ON
// 3. RTD2014Function, RTD2014Osd, RTDFactory:
//    -> Option for Group -> Include in Target Build -> Disable
// 4. NoneFunction, NoneOsd, NoneFactory:
//    -> Option for Group -> Include in Target Build -> Enable
// 5. RL6193_Series_QC_BIST.c ~ RL6193_Series_QC_OSD.c:
//    -> Option for File -> Include in Target Build -> Enable
// 6. RL6193_Project_Link.lin:
//    -> Option for Target -> User -> Run User Programs After Build -> Run #1 -> Diable
// 7. Bank1 Spec Overflow:
//    -> Move ScalerDPRxMST.c to Bank6
// 8. Bank4 Spec Overflow:
//    -> Move RL6193_Series_DPRx1.c to Bank7
// 9. RL6193_Project_Link.lin :
//    -> Specify QC Code Bank in Keil C BL51 Misc By Modified Following:
/*
COMMON(?PR?SYSTIMERINTPROC0?SYSTIMER, ?PR?SYSTIMERINTPROC1?SYSTIMER, ?PR?SYSTIMERINTPROC2?SYSTIMER,?PR?SYSTIMERWDINTPROC?SYSTIMER)
BANK0(?CO?SYSSOURCE, ?CO?RL6193_SERIES_SCALING)
BANK1(?CO?SCALER*TX)
BANK2(?CO?SCALERPLL, ?CO?RL6193_SERIES_COLOR*, ?CO?SCALERDDR3)
BANK5(?CO?USERCOMMONMODESEARCH, ?CO?USERCOMMONDDCCIFUNCTION, ?CO?USERCOMMONINTERFACE, ?CO?USERCOMMONNVRAMSYSTEM, ?CO?SCALERVGATOP)
BANK6(?CO?NONEUSERADJUST, ?CO?NONEOSD, ?CO?NONEFACTORYFUNCTION, ?CO?NONEUSERINTERFACE)
BANK11(?CO?RL6193_SERIES_QC_MAIN, ?CO?RL6193_SERIES_QC_COLOR_IMDOMAIN)
BANK12(?CO?RL6193_SERIES_QC_COLOR_DDOMAIN)
BANK13(?CO?RL6193_SERIES_QC_COLOR_DDOMAIN_II)
BANK14(?CO?RL6193_SERIES_QC_DSPC, ?CO?RL6193_SERIES_QC_COLOR_DDOMAIN_III)
BANK15(?CO?RL6193_SERIES_QC_OD_FRC, ?CO?RL6193_SERIES_QC_OSD, ?CO?RL6193_SERIES_QC_BIST)
*/

//--------------------------------------------------
// QC type Options
//--------------------------------------------------
#define _RL6193_WITH_4P                                         0   // Enable 4P (PBP) Mode Testing
#define _RL6193_WITHOUT_4P                                      1   // RL2776B series testing without 4P (PBP)
#define _RL6193_COST_DOWN_TYPE_1                                2   // Cost Down Package Type
#define _RL6193_COST_DOWN_TYPE_2                                3   // Cost Down Package Type
#define _RLE0740_TYPE                                           4   // RLE0740 Package Type

#define _QC_TYPE                                                _RL6193_WITH_4P

// Type                4P       DP5.4G    HDMI2.0    D4/D5    DPTx      LVDS           Vby1     DDR
// RL6193 With 4P:     yes      yes       yes       yes      5.4G      8 port      yes      2
// RL6193 Without 4P:  no       yes       yes       yes      5.4G      8 port      yes      2
// Cost Down Type 1:   no       yes       yes       no       5.4G      4 port      yes      1
// Cost Down Type 2:   no       no        no        no       2.7G      4 port      no       1

// RL6193 with 4P:    RTD2786-VDC-CG, RTD2786-VEC-CG, RTD2796-VDC-CG, RTD2796-VEC-CG, RTD2796-DEC-CG
// RL6193 without 4P: RTD2776B-DDC-CG, RTD2776B-DEC-CG, RTD2786B-DEC-CG, RTD2786B-VDC-CG, RTD2786B-VEC-CG, RTD2796B-VDC-CG, RTD2796B-VEC-CG
// Cost Down Type 1:  RTD2792-VDC-CG
// Cost Down Type 2:  RTD2781-DDC-CG, RTD2781-DEC-CG, RTD2781-PEC-CG
//***********************************************************************************************
#if(((_QC_TYPE == _RL6193_WITHOUT_4P) || (_QC_TYPE == _RL6193_WITH_4P)) && (_MEMORY_SIZE_CONFIG == _1G_16BIT_DDR3_1PC))
#undef _MEMORY_SIZE_CONFIG
#define _MEMORY_SIZE_CONFIG                                     _1G_16BIT_DDR3_2PCS
#elif((((_QC_TYPE == _RL6193_COST_DOWN_TYPE_1) || (_QC_TYPE == _RL6193_COST_DOWN_TYPE_2) || (_QC_TYPE == _RLE0740_TYPE)) && (_MEMORY_SIZE_CONFIG == _1G_16BIT_DDR3_2PCS)))
#undef _MEMORY_SIZE_CONFIG
#define _MEMORY_SIZE_CONFIG                                     _1G_16BIT_DDR3_1PC
#endif

#if(_QC_TYPE == _RL6193_WITH_4P)
#undef _QC_4P_MODE_
#define _QC_4P_MODE_                                            _ON
#else
#undef _QC_4P_MODE_
#define _QC_4P_MODE_                                            _OFF
#endif

#if((_QC_TYPE == _RL6193_COST_DOWN_TYPE_1) || (_QC_TYPE == _RL6193_COST_DOWN_TYPE_2))
#define _RL6193_COST_DOWN                                       _ON
#else
#define _RL6193_COST_DOWN                                       _OFF
#endif

