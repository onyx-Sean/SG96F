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
// ID Code      : ScalerDPRx1_SeptPhyInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
//--------------------------------------------------
// Macro of DP Lane Mapping
//--------------------------------------------------
#define GET_DP_RX1_PCB_LANE0_MAPPING()                  (g_stDpRx1LanesMapping.b2Lane0Mapping)
#define SET_DP_RX1_PCB_LANE0_MAPPING(x)                 (g_stDpRx1LanesMapping.b2Lane0Mapping = (x))

#define GET_DP_RX1_PCB_LANE1_MAPPING()                  (g_stDpRx1LanesMapping.b2Lane1Mapping)
#define SET_DP_RX1_PCB_LANE1_MAPPING(x)                 (g_stDpRx1LanesMapping.b2Lane1Mapping = (x))

#define GET_DP_RX1_PCB_LANE2_MAPPING()                  (g_stDpRx1LanesMapping.b2Lane2Mapping)
#define SET_DP_RX1_PCB_LANE2_MAPPING(x)                 (g_stDpRx1LanesMapping.b2Lane2Mapping = (x))

#define GET_DP_RX1_PCB_LANE3_MAPPING()                  (g_stDpRx1LanesMapping.b2Lane3Mapping)
#define SET_DP_RX1_PCB_LANE3_MAPPING(x)                 (g_stDpRx1LanesMapping.b2Lane3Mapping = (x))

#define GET_DP_RX1_PCB_LANE0_PN_SWAP()                  (g_stDpRx1LanesMapping.b1Lane0PNSwap)
#define SET_DP_RX1_PCB_LANE0_PN_SWAP(x)                 (g_stDpRx1LanesMapping.b1Lane0PNSwap = (x))

#define GET_DP_RX1_PCB_LANE1_PN_SWAP()                  (g_stDpRx1LanesMapping.b1Lane1PNSwap)
#define SET_DP_RX1_PCB_LANE1_PN_SWAP(x)                 (g_stDpRx1LanesMapping.b1Lane1PNSwap = (x))

#define GET_DP_RX1_PCB_LANE2_PN_SWAP()                  (g_stDpRx1LanesMapping.b1Lane2PNSwap)
#define SET_DP_RX1_PCB_LANE2_PN_SWAP(x)                 (g_stDpRx1LanesMapping.b1Lane2PNSwap = (x))

#define GET_DP_RX1_PCB_LANE3_PN_SWAP()                  (g_stDpRx1LanesMapping.b1Lane3PNSwap)
#define SET_DP_RX1_PCB_LANE3_PN_SWAP(x)                 (g_stDpRx1LanesMapping.b1Lane3PNSwap = (x))

//--------------------------------------------------
// Definitions of DP Lane Setting Ralation to Actual Lane Mapping
//--------------------------------------------------
#define _D1_DP_LANE0                                    (GET_DP_RX1_PCB_LANE0_MAPPING())
#define _D1_DP_LANE1                                    (GET_DP_RX1_PCB_LANE1_MAPPING())
#define _D1_DP_LANE2                                    (GET_DP_RX1_PCB_LANE2_MAPPING())
#define _D1_DP_LANE3                                    (GET_DP_RX1_PCB_LANE3_MAPPING())

//--------------------------------------------------
// Macro of DP Lane Mapping
//--------------------------------------------------
#define GET_DP_RX1_LANE_MAPPING_MODE()                  (g_stDpRx1LanesMapping.b1LaneMappingMode)
#define SET_DP_RX1_LANE_MAPPING_MODE(x)                 (g_stDpRx1LanesMapping.b1LaneMappingMode = (x))
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
extern BYTE g_ucDpRx1PhyCtsCtrl;
extern StructDpLanesMapping g_stDpRx1LanesMapping;

#if(_DP_MST_SUPPORT == _ON)
extern StructDPRxMiscInfo g_stDpRx1MiscInfo;
extern BYTE g_pucDpRx1MstTimeSlotBackup[13];
#endif

extern WORD g_pusDpRx1ClockCount[4];
extern WORD g_pusDpRx1ClockCount1[4];
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
extern void ScalerDpRx1AdjustVsyncDelay(void);
extern bit ScalerDpRx1AlignCheck(void);
extern void ScalerDpRx1CheckHdcpCpirqStatus(void);

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
extern bit ScalerDpRx1CheckVgipVsBypass(void);
#endif

extern void ScalerDpRx1CrcCalculate(void);
#if(_HW_HS_TRACKING_GEN_TYPE == _HS_TRACKING_GEN_2)
extern void ScalerDpRx1HSActiveTrackingMode(EnumDpHSTrackingType enumHSTrackingType);
#endif
extern void ScalerDpRx1DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus);
extern DWORD ScalerDpRx1GetBStoVSDelay(void);
extern BYTE ScalerDpRx1GetDpcdBitInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
extern BYTE ScalerDpRx1GetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
extern bit ScalerDpRx1GetVideoStream(void);
extern void ScalerDpRx1HotPlugDuration(EnumDpHotPlugTime enumHpdTime);
extern void ScalerDpRx1HotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpRx1Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
extern bit ScalerDpRx1MarginLinkCheck(void);
extern void ScalerDpRx1LinkStatusIRQ(void);
extern void ScalerDpRx1AuxDiffModeSet(void);
extern bit ScalerDpRx1MSAActiveChange(void);
extern bit ScalerDpRx1PSPreDetect(void);
extern void ScalerDpRx1SecDataBlockReset(void);
extern void ScalerDpRx1SetDpcdBitValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
extern void ScalerDpRx1SetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
extern void ScalerDpRx1SinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
extern bit ScalerDpRx1ValidSignalDetectionDCOnCheck(void);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
extern void ScalerDpRx1ASSRModeSetting(void);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
extern WORD ScalerDpRx1GetBStoHSDelay(WORD usDpHtotal);
extern bit ScalerDpRx1GetFREESYNCStatusChange(void);
extern WORD ScalerDpRx1GetHPeriod(void);
extern WORD ScalerDpRx1GetHSW(void);
extern WORD ScalerDpRx1GetVFreq(void);
extern WORD ScalerDpRx1GetVPeriod(void);
#endif

#if(_DP_MST_SUPPORT == _ON)
extern void ScalerDpRx1AuxChPowerStatusCheck(bit bCableStatus);
extern void ScalerDpRx1MstInfoBackup(EnumDpMstBackup enumDpMstBackup);

#if(_DP_TX_SUPPORT == _ON)
extern void ScalerDpRx1HDCPAuthShaRun(bit bIsFirst);

#if(_D1_DP_MST_PORT_SUPPORT == _ON)
extern void ScalerDpRx1HDCPBlockReset(void);
#endif

extern void ScalerDpRx1HDCPChangeAuthState(EnumDPRxHDCPAuthState enumHDCPAuthState);
extern bit ScalerDpRx1HDCPCheckLvp(void);
extern void ScalerDpRx1HDCPHandler(void);
extern void ScalerDpRx1HDCPSetReadIrqTimeout(void);
extern void ScalerDpRx1HDCPSetRepeaterProcTimeout(void);
extern void ScalerDpRx1MstToSstProc(void);
extern void ScalerDpRx1MstToSstSetColorInfo(void);
#endif

#endif // End of #if(_DP_MST_SUPPORT == _ON)

#endif // End of #if(_D1_DP_EXIST == _ON)

