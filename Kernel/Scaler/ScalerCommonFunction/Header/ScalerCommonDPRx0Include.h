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
// ID Code      : ScalerCommonDPRx0Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D0_DP_EXIST == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_DP_RX0_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpRx0MSAFailMacRsetCount)
#define ADD_DP_RX0_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpRx0MSAFailMacRsetCount++)
#define CLR_DP_RX0_MSA_FAIL_MAC_RESET_COUNT()           (g_ucDpRx0MSAFailMacRsetCount = 0)

#if(_ULTRA_HDR_SUPPORT == _ON)
#define GET_DP_RX0_RSV0_DETECTING()                     (g_stDPRx0InfoFrameRSV0Ctrl.b1RSV0PacketDetecting)
#define SET_DP_RX0_RSV0_DETECTING()                     (g_stDPRx0InfoFrameRSV0Ctrl.b1RSV0PacketDetecting = _TRUE)
#define CLR_DP_RX0_RSV0_DETECTING()                     (g_stDPRx0InfoFrameRSV0Ctrl.b1RSV0PacketDetecting = _FALSE)

#define GET_DP_RX0_HDR_INFO_FRAME_RECEIVED()            (g_stDPRx0InfoFrameRSV0Ctrl.b1HDRInfoFrameReceive)
#define SET_DP_RX0_HDR_INFO_FRAME_RECEIVED()            (g_stDPRx0InfoFrameRSV0Ctrl.b1HDRInfoFrameReceive = _TRUE)
#define CLR_DP_RX0_HDR_INFO_FRAME_RECEIVED()            (g_stDPRx0InfoFrameRSV0Ctrl.b1HDRInfoFrameReceive = _FALSE)

#define GET_DP_RX0_AUDIO_INFO_FRAME_RECEIVED()          (g_stDPRx0InfoFrameRSV0Ctrl.b1AudioInfoFrameReceive)
#define SET_DP_RX0_AUDIO_INFO_FRAME_RECEIVED()          (g_stDPRx0InfoFrameRSV0Ctrl.b1AudioInfoFrameReceive = _TRUE)
#define CLR_DP_RX0_AUDIO_INFO_FRAME_RECEIVED()          (g_stDPRx0InfoFrameRSV0Ctrl.b1AudioInfoFrameReceive = _FALSE)
#endif

#if((_ULTRA_HDR_SUPPORT == _ON) && (_DP_FREESYNC_SUPPORT == _ON))
#define GET_DP_RX0_AMD_SPD_INFO_FRAME_RECEIVED()        (g_stDPRx0InfoFrameRSV0Ctrl.b1AMDSPDInfoFrameReceive)
#define SET_DP_RX0_AMD_SPD_INFO_FRAME_RECEIVED()        (g_stDPRx0InfoFrameRSV0Ctrl.b1AMDSPDInfoFrameReceive = _TRUE)
#define CLR_DP_RX0_AMD_SPD_INFO_FRAME_RECEIVED()        (g_stDPRx0InfoFrameRSV0Ctrl.b1AMDSPDInfoFrameReceive = _FALSE)
#endif

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
#define GET_DP_RX0_VSC_SDP_COLOR_MODE()                 (g_bDpRx0VscSdpColorMode)
#define SET_DP_RX0_VSC_SDP_COLOR_MODE()                 (g_bDpRx0VscSdpColorMode = _TRUE)
#define CLR_DP_RX0_VSC_SDP_COLOR_MODE()                 (g_bDpRx0VscSdpColorMode = _FALSE)

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
#define GET_DP_RX0_RSV1_DETECTING()                     (g_bDpRx0RSV1PacketDetecting)
#define SET_DP_RX0_RSV1_DETECTING()                     (g_bDpRx0RSV1PacketDetecting = _TRUE)
#define CLR_DP_RX0_RSV1_DETECTING()                     (g_bDpRx0RSV1PacketDetecting = _FALSE)

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
#define GET_DP_RX0_MST2SST_RSV1_DETECTING()             (g_bDpRx0MstToSstRSV1PacketDetecting)
#define SET_DP_RX0_MST2SST_RSV1_DETECTING()             (g_bDpRx0MstToSstRSV1PacketDetecting = _TRUE)
#define CLR_DP_RX0_MST2SST_RSV1_DETECTING()             (g_bDpRx0MstToSstRSV1PacketDetecting = _FALSE)
#endif
#endif
#endif // End of #if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern bit g_bDpRx0VscSdpColorMode;

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
extern bit g_bDpRx0RSV1PacketDetecting;

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
extern bit g_bDpRx0MstToSstRSV1PacketDetecting;
#endif
#endif
#endif

extern BYTE g_ucDpRx0MSAFailMacRsetCount;

#if(_ULTRA_HDR_SUPPORT == _ON)
extern BYTE g_ucDPRx0InfoTypeCompare;
extern BYTE g_pucDPRx0HDRBackup[_HW_DP_INFOFRAME_RSV0_LENGTH];
extern BYTE g_pucDPRx0RSV0Backup[_HW_DP_INFOFRAME_RSV0_LENGTH];
extern StructDPInfoFrameRSV0Ctrl g_stDPRx0InfoFrameRSV0Ctrl;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit ScalerDpRx0GetVideoInfo(void);
extern void ScalerDpRx0SetColorInfo(void);
extern void ScalerDpRx0VideoSetting(void);
extern void ScalerDpRx0ColorimetrySetting(void);
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern void ScalerDpRx0ColorimetryExtSetting(void);
#endif
extern void ScalerDpRx0QuantizationSetting(void);

extern bit ScalerDpRx0MiscCheck(void);
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern bit ScalerDpRx0VscCheck(void);

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
extern void ScalerDpRx0RSV1PacketDetectEvent(void);
extern void ScalerDpRx0SetInitialRSV1InfoType(void);
#endif

#endif

#if(_DP_MST_SUPPORT == _ON)
extern void ScalerDpRx0MstReset(void);

#if(_DP_TX_SUPPORT == _ON)
extern bit ScalerDpRx0MstToSstGetVideoInfo(void);
extern void ScalerDpRx0MstToSstSetColorInfo(void);
extern void ScalerDpRx0MstToSstVideoSetting(void);
extern bit ScalerDpRx0MstToSstMiscCheck(void);

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
extern bit ScalerDpRx0MstToSstVscCheck(void);

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
extern void ScalerDpRx0MstToSstRSV1PacketDetectEvent(void);
#endif
#endif

#endif
#endif

extern bit ScalerDpRx0MSACheck(void);
extern void ScalerDpRx0FakeLTProtect(void);
extern void ScalerDpRx0SetInitialRSV0InfoType(void);

#if(_DP_FREESYNC_SUPPORT == _ON)
extern BYTE ScalerDpRx0GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
extern BYTE ScalerDpRx0GetAmdSpdBackupInfo(EnumAmdSpdInfoContent enumContent);
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
extern void ScalerDpRx0InfoFrameRSV0Check(void);
extern void ScalerDpRx0RSV0PacketDetectEvent(void);
extern void ScalerDpRx0GetInfoFrameRSV0(BYTE *pucDPRx0RSV0Data);
//extern void ScalerDpRx0InfoFrameRSV0Initial(void);
#endif

#endif // End of #if(_D0_DP_EXIST == _ON)
