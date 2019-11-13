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
// ID Code      : ScalerDPRx0_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
//--------------------------------------------------
// Macro of DP Lane Mapping
//--------------------------------------------------
#define GET_DP_RX0_PCB_LANE0_MAPPING()                  (g_stDpRx0LanesMapping.b2Lane0Mapping)
#define SET_DP_RX0_PCB_LANE0_MAPPING(x)                 (g_stDpRx0LanesMapping.b2Lane0Mapping = (x))

#define GET_DP_RX0_PCB_LANE1_MAPPING()                  (g_stDpRx0LanesMapping.b2Lane1Mapping)
#define SET_DP_RX0_PCB_LANE1_MAPPING(x)                 (g_stDpRx0LanesMapping.b2Lane1Mapping = (x))

#define GET_DP_RX0_PCB_LANE2_MAPPING()                  (g_stDpRx0LanesMapping.b2Lane2Mapping)
#define SET_DP_RX0_PCB_LANE2_MAPPING(x)                 (g_stDpRx0LanesMapping.b2Lane2Mapping = (x))

#define GET_DP_RX0_PCB_LANE3_MAPPING()                  (g_stDpRx0LanesMapping.b2Lane3Mapping)
#define SET_DP_RX0_PCB_LANE3_MAPPING(x)                 (g_stDpRx0LanesMapping.b2Lane3Mapping = (x))

#define GET_DP_RX0_PCB_LANE0_PN_SWAP()                  (g_stDpRx0LanesMapping.b1Lane0PNSwap)
#define SET_DP_RX0_PCB_LANE0_PN_SWAP(x)                 (g_stDpRx0LanesMapping.b1Lane0PNSwap = (x))

#define GET_DP_RX0_PCB_LANE1_PN_SWAP()                  (g_stDpRx0LanesMapping.b1Lane1PNSwap)
#define SET_DP_RX0_PCB_LANE1_PN_SWAP(x)                 (g_stDpRx0LanesMapping.b1Lane1PNSwap = (x))

#define GET_DP_RX0_PCB_LANE2_PN_SWAP()                  (g_stDpRx0LanesMapping.b1Lane2PNSwap)
#define SET_DP_RX0_PCB_LANE2_PN_SWAP(x)                 (g_stDpRx0LanesMapping.b1Lane2PNSwap = (x))

#define GET_DP_RX0_PCB_LANE3_PN_SWAP()                  (g_stDpRx0LanesMapping.b1Lane3PNSwap)
#define SET_DP_RX0_PCB_LANE3_PN_SWAP(x)                 (g_stDpRx0LanesMapping.b1Lane3PNSwap = (x))

//--------------------------------------------------
// Definitions of DP Lane Setting Ralation to Actual Lane Mapping
//--------------------------------------------------
#define _D0_DP_LANE0                                    (GET_DP_RX0_PCB_LANE0_MAPPING())
#define _D0_DP_LANE1                                    (GET_DP_RX0_PCB_LANE1_MAPPING())
#define _D0_DP_LANE2                                    (GET_DP_RX0_PCB_LANE2_MAPPING())
#define _D0_DP_LANE3                                    (GET_DP_RX0_PCB_LANE3_MAPPING())

//--------------------------------------------------
// Macro of DP Mst to sst V-Front Porch Setting
//--------------------------------------------------
#define GET_DP_RX0_MST_TO_SST_VFRONT_PORCH()            (g_usDpRx0MstToSstVfrontporch)
#define SET_DP_RX0_MST_TO_SST_VFRONT_PORCH(x)           (g_usDpRx0MstToSstVfrontporch = (x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
extern BYTE g_ucDpRx0PhyCtsCtrl;
extern StructDpLanesMapping g_stDpRx0LanesMapping;

#if(_DP_MST_SUPPORT == _ON)
extern StructDPRxMiscInfo g_stDpRx0MiscInfo;
extern BYTE g_pucDpRx0MstTimeSlotBackup[13];
#endif

#if(_DP_TX_SUPPORT == _ON)
extern WORD g_usDpRx0MstToSstVfrontporch;
#endif

#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
extern void ScalerDpRx0AdjustVsyncDelay(void);

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
extern bit ScalerDpRx0CheckVgipVsBypass(void);
#endif

extern void ScalerDpRx0DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus);
extern DWORD ScalerDpRx0GetBStoVSDelay(void);
extern void ScalerDpRx0Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
extern bit ScalerDpRx0MarginLinkCheck(void);
extern void ScalerDpRx0LinkStatusIRQ(void);
extern void ScalerDpRx0AuxDiffModeSet(void);
extern bit ScalerDpRx0PSPreDetect(void);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
extern void ScalerDpRx6Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
extern WORD ScalerDpRx0GetBStoHSDelay(WORD usDpHtotal);
#endif

#if(_DP_MST_SUPPORT == _ON)
extern void ScalerDpRx0MstInfoBackup(EnumDpMstBackup enumDpMstBackup);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
extern void ScalerDpRx6AuxChPowerStatusCheck(bit bCableStatus);
extern void ScalerDpRx6MstInfoBackup(EnumDpMstBackup enumDpMstBackup);
#endif

#if(_DP_TX_SUPPORT == _ON)
extern void ScalerDpRx0HDCPAuthShaRun(bit bIsFirst);

#if(_D0_DP_MST_PORT_SUPPORT == _ON)
extern void ScalerDpRx0HDCPBlockReset(void);
#endif

extern void ScalerDpRx0HDCPChangeAuthState(EnumDPRxHDCPAuthState enumHDCPAuthState);
extern bit ScalerDpRx0HDCPCheckLvp(void);
extern void ScalerDpRx0HDCPHandler(void);
extern void ScalerDpRx0HDCPSetReadIrqTimeout(void);
extern void ScalerDpRx0HDCPSetRepeaterProcTimeout(void);
extern DWORD ScalerDpRx0MstToSstGetBStoVSDelay(void);
extern void ScalerDpRx0MstToSstProc(void);

#if(_DP_FREESYNC_SUPPORT == _ON)
extern WORD ScalerDpRx0MstToSstGetBStoHSDelay(WORD usDpHtotal);
#endif

#endif

#endif

#endif
