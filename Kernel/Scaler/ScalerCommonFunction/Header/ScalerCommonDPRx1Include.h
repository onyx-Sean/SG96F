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
// ID Code      : ScalerCommonDPRx1Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D1_DP_EXIST == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_DP_RX1_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpRx1MSAFailMacRsetCount)
#define ADD_DP_RX1_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpRx1MSAFailMacRsetCount++)
#define CLR_DP_RX1_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpRx1MSAFailMacRsetCount = 0)

#if(_ULTRA_HDR_SUPPORT == _ON)
#define GET_DP_RX1_RSV0_DETECTING()                     (g_stDPRx1InfoFrameRSV0Ctrl.b1RSV0PacketDetecting)
#define SET_DP_RX1_RSV0_DETECTING()                     (g_stDPRx1InfoFrameRSV0Ctrl.b1RSV0PacketDetecting = _TRUE)
#define CLR_DP_RX1_RSV0_DETECTING()                     (g_stDPRx1InfoFrameRSV0Ctrl.b1RSV0PacketDetecting = _FALSE)

#define GET_DP_RX1_HDR_INFO_FRAME_RECEIVED()            (g_stDPRx1InfoFrameRSV0Ctrl.b1HDRInfoFrameReceive)
#define SET_DP_RX1_HDR_INFO_FRAME_RECEIVED()            (g_stDPRx1InfoFrameRSV0Ctrl.b1HDRInfoFrameReceive = _TRUE)
#define CLR_DP_RX1_HDR_INFO_FRAME_RECEIVED()            (g_stDPRx1InfoFrameRSV0Ctrl.b1HDRInfoFrameReceive = _FALSE)

#define GET_DP_RX1_AUDIO_INFO_FRAME_RECEIVED()          (g_stDPRx1InfoFrameRSV0Ctrl.b1AudioInfoFrameReceive)
#define SET_DP_RX1_AUDIO_INFO_FRAME_RECEIVED()          (g_stDPRx1InfoFrameRSV0Ctrl.b1AudioInfoFrameReceive = _TRUE)
#define CLR_DP_RX1_AUDIO_INFO_FRAME_RECEIVED()          (g_stDPRx1InfoFrameRSV0Ctrl.b1AudioInfoFrameReceive = _FALSE)
#endif

#if((_ULTRA_HDR_SUPPORT == _ON) && (_DP_FREESYNC_SUPPORT == _ON))
#define GET_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED()        (g_stDPRx1InfoFrameRSV0Ctrl.b1AMDSPDInfoFrameReceive)
#define SET_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED()        (g_stDPRx1InfoFrameRSV0Ctrl.b1AMDSPDInfoFrameReceive = _TRUE)
#define CLR_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED()        (g_stDPRx1InfoFrameRSV0Ctrl.b1AMDSPDInfoFrameReceive = _FALSE)
#endif

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
#define GET_DP_RX1_VSC_SDP_COLOR_MODE()                 (g_bDpRx1VscSdpColorMode)
#define SET_DP_RX1_VSC_SDP_COLOR_MODE()                 (g_bDpRx1VscSdpColorMode = _TRUE)
#define CLR_DP_RX1_VSC_SDP_COLOR_MODE()                 (g_bDpRx1VscSdpColorMode = _FALSE)

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
#define GET_DP_RX1_RSV1_DETECTING()                     (g_bDpRx1RSV1PacketDetecting)
#define SET_DP_RX1_RSV1_DETECTING()                     (g_bDpRx1RSV1PacketDetecting = _TRUE)
#define CLR_DP_RX1_RSV1_DETECTING()                     (g_bDpRx1RSV1PacketDetecting = _FALSE)

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
#define GET_DP_RX1_MST2SST_RSV1_DETECTING()             (g_bDpRx1MstToSstRSV1PacketDetecting)
#define SET_DP_RX1_MST2SST_RSV1_DETECTING()             (g_bDpRx1MstToSstRSV1PacketDetecting = _TRUE)
#define CLR_DP_RX1_MST2SST_RSV1_DETECTING()             (g_bDpRx1MstToSstRSV1PacketDetecting = _FALSE)
#endif
#endif
#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern bit g_bDpRx1VscSdpColorMode;

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
extern bit g_bDpRx1RSV1PacketDetecting;

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
extern bit g_bDpRx1MstToSstRSV1PacketDetecting;
#endif
#endif
#endif

extern BYTE g_ucDpRx1MSAFailMacRsetCount;

#if(_ULTRA_HDR_SUPPORT == _ON)
extern BYTE g_ucDPRx1InfoTypeCompare;
extern BYTE g_pucDPRx1HDRBackup[_HW_DP_INFOFRAME_RSV0_LENGTH];
extern BYTE g_pucDPRx1RSV0Backup[_HW_DP_INFOFRAME_RSV0_LENGTH];
extern StructDPInfoFrameRSV0Ctrl g_stDPRx1InfoFrameRSV0Ctrl;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit ScalerDpRx1GetVideoInfo(void);
extern void ScalerDpRx1SetColorInfo(void);
extern void ScalerDpRx1VideoSetting(void);
extern void ScalerDpRx1ColorimetrySetting(void);
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern void ScalerDpRx1ColorimetryExtSetting(void);
#endif
extern void ScalerDpRx1QuantizationSetting(void);

extern bit ScalerDpRx1MiscCheck(void);

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern bit ScalerDpRx1VscCheck(void);

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
extern void ScalerDpRx1RSV1PacketDetectEvent(void);
extern void ScalerDpRx1SetInitialRSV1InfoType(void);
#endif
#endif

#if(_DP_MST_SUPPORT == _ON)
extern void ScalerDpRx1MstReset(void);

#if(_DP_TX_SUPPORT == _ON)
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
extern void ScalerDpRx1MstToSstRSV1PacketDetectEvent(void);
#endif
#endif
#endif
#endif

extern bit ScalerDpRx1MSACheck(void);
extern void ScalerDpRx1FakeLTProtect(void);
extern void ScalerDpRx1SetInitialRSV0InfoType(void);

#if(_DP_FREESYNC_SUPPORT == _ON)
extern BYTE ScalerDpRx1GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
extern BYTE ScalerDpRx1GetAmdSpdBackupInfo(EnumAmdSpdInfoContent enumContent);
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
extern void ScalerDpRx1InfoFrameRSV0Check(void);
extern void ScalerDpRx1RSV0PacketDetectEvent(void);
extern void ScalerDpRx1GetInfoFrameRSV0(BYTE *pucDPRx1RSV0Data);
extern void ScalerDpRx1InfoFrameRSV0Initial(void);
#endif

#endif // End of #if(_D1_DP_EXIST == _ON)
