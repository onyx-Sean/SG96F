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
// ID Code      : ScalerCommonSyncInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macros of DP/HDMI HotPlug Toggle Support
//--------------------------------------------------
#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Macro of Digital Input Port Switch
//--------------------------------------------------
#define GET_DIGITAL_PORT_SWITCH_TO_D0()                     ((g_ucDigitalSwitch & _BIT5) >> 5)
#define SET_DIGITAL_PORT_SWITCH_TO_D0()                     (g_ucDigitalSwitch |= _BIT5)
#define CLR_DIGITAL_PORT_SWITCH_TO_D0()                     (g_ucDigitalSwitch &= ~_BIT5)

#define GET_DIGITAL_PORT_SWITCH_TO_D1()                     ((g_ucDigitalSwitch & _BIT4) >> 4)
#define SET_DIGITAL_PORT_SWITCH_TO_D1()                     (g_ucDigitalSwitch |= _BIT4)
#define CLR_DIGITAL_PORT_SWITCH_TO_D1()                     (g_ucDigitalSwitch &= ~_BIT4)

#define GET_DIGITAL_PORT_SWITCH_TO_D2()                     ((g_ucDigitalSwitch & _BIT3) >> 3)
#define SET_DIGITAL_PORT_SWITCH_TO_D2()                     (g_ucDigitalSwitch |= _BIT3)
#define CLR_DIGITAL_PORT_SWITCH_TO_D2()                     (g_ucDigitalSwitch &= ~_BIT3)

#define GET_DIGITAL_PORT_SWITCH_TO_D3()                     ((g_ucDigitalSwitch & _BIT2) >> 2)
#define SET_DIGITAL_PORT_SWITCH_TO_D3()                     (g_ucDigitalSwitch |= _BIT2)
#define CLR_DIGITAL_PORT_SWITCH_TO_D3()                     (g_ucDigitalSwitch &= ~_BIT2)

#define GET_DIGITAL_PORT_SWITCH_TO_D4()                     ((g_ucDigitalSwitch & _BIT1) >> 1)
#define SET_DIGITAL_PORT_SWITCH_TO_D4()                     (g_ucDigitalSwitch |= _BIT1)
#define CLR_DIGITAL_PORT_SWITCH_TO_D4()                     (g_ucDigitalSwitch &= ~_BIT1)

#define GET_DIGITAL_PORT_SWITCH_TO_D5()                     ((g_ucDigitalSwitch & _BIT0) >> 0)
#define SET_DIGITAL_PORT_SWITCH_TO_D5()                     (g_ucDigitalSwitch |= _BIT0)
#define CLR_DIGITAL_PORT_SWITCH_TO_D5()                     (g_ucDigitalSwitch &= ~_BIT0)

#define GET_DIGITAL_PORT_SWITCH_TO_D6()                     ((g_ucDigitalSwitch & _BIT6) >> 6)
#define SET_DIGITAL_PORT_SWITCH_TO_D6()                     (g_ucDigitalSwitch |= _BIT6)
#define CLR_DIGITAL_PORT_SWITCH_TO_D6()                     (g_ucDigitalSwitch &= ~_BIT6)

#define GET_DP_DC_OFF_HPD_HIGH()                            (g_bDpDCOffHPDHigh)
#define SET_DP_DC_OFF_HPD_HIGH()                            (g_bDpDCOffHPDHigh = _TRUE)
#define CLR_DP_DC_OFF_HPD_HIGH()                            (g_bDpDCOffHPDHigh = _FALSE)

#define GET_HDMI_HOTPLUG_TOGGLE()                           ((g_ucHDMIHotPlug & _BIT7) >> 7)
#define SET_HDMI_HOTPLUG_TOGGLE()                           (g_ucHDMIHotPlug |= _BIT7)
#define CLR_HDMI_HOTPLUG_TOGGLE()                           (g_ucHDMIHotPlug &= ~_BIT7)

#define GET_HDMI_HOTPLUG_TIME()                             ((WORD)(g_ucHDMIHotPlug & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) * 100)
#define SET_HDMI_HOTPLUG_TIME(x)                            (g_ucHDMIHotPlug = (g_ucHDMIHotPlug & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)) | (x))

#define GET_DP_AUX_DIFF_MODE()                              (g_bDpAuxDiffMode)
#define SET_DP_AUX_DIFF_MODE()                              (g_bDpAuxDiffMode = _TRUE)
#define CLR_DP_AUX_DIFF_MODE()                              (g_bDpAuxDiffMode = _FALSE)

//--------------------------------------------------
// Macro of Digital color info change
//--------------------------------------------------
#define GET_DIGITAL_COLOR_INFO_CHANGE_RESET()               (g_bDigitalColorInfoChangeReset)
#define SET_DIGITAL_COLOR_INFO_CHANGE_RESET()               (g_bDigitalColorInfoChangeReset = _TRUE)
#define CLR_DIGITAL_COLOR_INFO_CHANGE_RESET()               (g_bDigitalColorInfoChangeReset = _FALSE)


#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Definitions of DP Marginal Link
//--------------------------------------------------
#define GET_DP_RX_D0_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D0MarginLinkHBRRBR)
#define SET_DP_RX_D0_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D0MarginLinkHBRRBR = _TRUE)
#define CLR_DP_RX_D0_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D0MarginLinkHBRRBR = _FALSE)

#define GET_DP_RX_D1_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D1MarginLinkHBRRBR)
#define SET_DP_RX_D1_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D1MarginLinkHBRRBR = _TRUE)
#define CLR_DP_RX_D1_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D1MarginLinkHBRRBR = _FALSE)

#define GET_DP_RX_D2_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D2MarginLinkHBRRBR)
#define SET_DP_RX_D2_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D2MarginLinkHBRRBR = _TRUE)
#define CLR_DP_RX_D2_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D2MarginLinkHBRRBR = _FALSE)

#define GET_DP_RX_D6_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D6MarginLinkHBRRBR)
#define SET_DP_RX_D6_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D6MarginLinkHBRRBR = _TRUE)
#define CLR_DP_RX_D6_MARGIN_LINK_HBR_RBR()                  (g_stDpMarginLink.b1D6MarginLinkHBRRBR = _FALSE)
#endif

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
#define GET_D0_HDMI_5V_STATUS()                             ((bit)(g_stDpHdmiCompatibleInfo.b1D0Hdmi5VStatus))
#define SET_D0_HDMI_5V_STATUS()                             (g_stDpHdmiCompatibleInfo.b1D0Hdmi5VStatus = 1)
#define CLR_D0_HDMI_5V_STATUS()                             (g_stDpHdmiCompatibleInfo.b1D0Hdmi5VStatus = 0)

#define GET_D1_HDMI_5V_STATUS()                             ((bit)(g_stDpHdmiCompatibleInfo.b1D1Hdmi5VStatus))
#define SET_D1_HDMI_5V_STATUS()                             (g_stDpHdmiCompatibleInfo.b1D1Hdmi5VStatus = 1)
#define CLR_D1_HDMI_5V_STATUS()                             (g_stDpHdmiCompatibleInfo.b1D1Hdmi5VStatus = 0)

#define GET_D2_HDMI_5V_STATUS()                             ((bit)(g_stDpHdmiCompatibleInfo.b1D2Hdmi5VStatus))
#define SET_D2_HDMI_5V_STATUS()                             (g_stDpHdmiCompatibleInfo.b1D2Hdmi5VStatus = 1)
#define CLR_D2_HDMI_5V_STATUS()                             (g_stDpHdmiCompatibleInfo.b1D2Hdmi5VStatus = 0)

#define GET_D0_HDMI_PS_WAKEUP()                             ((bit)(g_stDpHdmiCompatibleInfo.b1D0HdmiPSWakeUp))
#define SET_D0_HDMI_PS_WAKEUP()                             (g_stDpHdmiCompatibleInfo.b1D0HdmiPSWakeUp = 1)
#define CLR_D0_HDMI_PS_WAKEUP()                             (g_stDpHdmiCompatibleInfo.b1D0HdmiPSWakeUp = 0)

#define GET_D1_HDMI_PS_WAKEUP()                             ((bit)(g_stDpHdmiCompatibleInfo.b1D1HdmiPSWakeUp))
#define SET_D1_HDMI_PS_WAKEUP()                             (g_stDpHdmiCompatibleInfo.b1D1HdmiPSWakeUp = 1)
#define CLR_D1_HDMI_PS_WAKEUP()                             (g_stDpHdmiCompatibleInfo.b1D1HdmiPSWakeUp = 0)

#define GET_D2_HDMI_PS_WAKEUP()                             ((bit)(g_stDpHdmiCompatibleInfo.b1D2HdmiPSWakeUp))
#define SET_D2_HDMI_PS_WAKEUP()                             (g_stDpHdmiCompatibleInfo.b1D2HdmiPSWakeUp = 1)
#define CLR_D2_HDMI_PS_WAKEUP()                             (g_stDpHdmiCompatibleInfo.b1D2HdmiPSWakeUp = 0)
#endif

#endif

//--------------------------------------------------
// Macros of HDR Support
//--------------------------------------------------
#if(_ULTRA_HDR_SUPPORT == _ON)
#define SET_HDR_INFO_DATA(x)                                (g_stHDRSaticMetadata = (x))

#define GET_HDR_EOTF()                                      (g_stHDRSaticMetadata.ucEOTF)
#define SET_HDR_EOTF(x)                                     (g_stHDRSaticMetadata.ucEOTF = (x))
#define CLR_HDR_EOTF()                                      (g_stHDRSaticMetadata.ucEOTF = _FALSE)

#define GET_HDR_METADATA_ID()                               (g_stHDRSaticMetadata.ucStaticMetadataID)
#define SET_HDR_METADATA_ID()                               (g_stHDRSaticMetadata.ucStaticMetadataID = (x))
#define CLR_HDR_METADATA_ID()                               (g_stHDRSaticMetadata.ucStaticMetadataID = _FALSE)

#define GET_HDR_DISPALY_PRIMARIES_X0()                      (g_stHDRSaticMetadata.usDisplayPrimariesX0)
#define SET_HDR_DISPALY_PRIMARIES_X0(x)                     (g_stHDRSaticMetadata.usDisplayPrimariesX0 = (x))
#define CLR_HDR_DISPALY_PRIMARIES_X0()                      (g_stHDRSaticMetadata.usDisplayPrimariesX0 = (0))

#define GET_HDR_DISPALY_PRIMARIES_Y0()                      (g_stHDRSaticMetadata.usDisplayPrimariesY0)
#define SET_HDR_DISPALY_PRIMARIES_Y0(x)                     (g_stHDRSaticMetadata.usDisplayPrimariesY0 = (x))
#define CLR_HDR_DISPALY_PRIMARIES_Y0()                      (g_stHDRSaticMetadata.usDisplayPrimariesY0 = (0))

#define GET_HDR_DISPALY_PRIMARIES_X1()                      (g_stHDRSaticMetadata.usDisplayPrimariesX1)
#define SET_HDR_DISPALY_PRIMARIES_X1(x)                     (g_stHDRSaticMetadata.usDisplayPrimariesX1 = (x))
#define CLR_HDR_DISPALY_PRIMARIES_X1()                      (g_stHDRSaticMetadata.usDisplayPrimariesX1 = (0))

#define GET_HDR_DISPALY_PRIMARIES_Y1()                      (g_stHDRSaticMetadata.usDisplayPrimariesY1)
#define SET_HDR_DISPALY_PRIMARIES_Y1(x)                     (g_stHDRSaticMetadata.usDisplayPrimariesY1 = (x))
#define CLR_HDR_DISPALY_PRIMARIES_Y1()                      (g_stHDRSaticMetadata.usDisplayPrimariesY1 = (0))

#define GET_HDR_DISPALY_PRIMARIES_X2()                      (g_stHDRSaticMetadata.usDisplayPrimariesX2)
#define SET_HDR_DISPALY_PRIMARIES_X2(x)                     (g_stHDRSaticMetadata.usDisplayPrimariesX2 = (x))
#define CLR_HDR_DISPALY_PRIMARIES_X2()                      (g_stHDRSaticMetadata.usDisplayPrimariesX2 = (0))

#define GET_HDR_DISPALY_PRIMARIES_Y2()                      (g_stHDRSaticMetadata.usDisplayPrimariesY2)
#define SET_HDR_DISPALY_PRIMARIES_Y2(x)                     (g_stHDRSaticMetadata.usDisplayPrimariesY2 = (x))
#define CLR_HDR_DISPALY_PRIMARIES_Y2()                      (g_stHDRSaticMetadata.usDisplayPrimariesY2 = (0))

#define GET_HDR_WHITE_POINT_X()                             (g_stHDRSaticMetadata.usWhitePointX)
#define SET_HDR_WHITE_POINT_X(x)                            (g_stHDRSaticMetadata.usWhitePointX = (x))
#define CLR_HDR_WHITE_POINT_X()                             (g_stHDRSaticMetadata.usWhitePointX = (0))

#define GET_HDR_WHITE_POINT_Y()                             (g_stHDRSaticMetadata.usWhitePointY)
#define SET_HDR_WHITE_POINT_Y(x)                            (g_stHDRSaticMetadata.usWhitePointY = (x))
#define CLR_HDR_WHITE_POINT_Y()                             (g_stHDRSaticMetadata.usWhitePointY = (0))

#define GET_HDR_MAX_DISPLAY_MASTERING_LV()                  (g_stHDRSaticMetadata.usMaxDisplayMasteringLv)
#define SET_HDR_MAX_DISPLAY_MASTERING_LV(x)                 (g_stHDRSaticMetadata.usMaxDisplayMasteringLv = (x))
#define CLR_HDR_MAX_DISPLAY_MASTERING_LV()                  (g_stHDRSaticMetadata.usMaxDisplayMasteringLv = (0))

#define GET_HDR_MIN_DISPLAY_MASTERING_LV()                  (g_stHDRSaticMetadata.usMinDisplayMasteringLv)
#define SET_HDR_MIN_DISPLAY_MASTERING_LV(x)                 (g_stHDRSaticMetadata.usMinDisplayMasteringLv = (x))
#define CLR_HDR_MIN_DISPLAY_MASTERING_LV()                  (g_stHDRSaticMetadata.usMinDisplayMasteringLv = (0))

#define GET_HDR_MAX_CLL()                                   (g_stHDRSaticMetadata.usMaxCLL)
#define SET_HDR_MAX_CLL(x)                                  (g_stHDRSaticMetadata.usMaxCLL = (x))
#define CLR_HDR_MAX_CLL()                                   (g_stHDRSaticMetadata.usMaxCLL = (0))

#define GET_HDR_MAX_FALL()                                  (g_stHDRSaticMetadata.usMaxFALL)
#define SET_HDR_MAX_FALL(x)                                 (g_stHDRSaticMetadata.usMaxFALL = (x))
#define CLR_HDR_MAX_FALL()                                  (g_stHDRSaticMetadata.usMaxFALL = (0))
#endif

typedef enum
{
    _HDR_EOTF_CHG = _BIT0,
    _HDR_DIS_PRIMARIES_CHG = _BIT1,
    _HDR_MAX_LUM_CHG = _BIT2,
}EnumHDRChange;

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************
#if(_DIGITAL_PORT_SUPPORT == _ON)
extern BYTE g_ucDigitalSwitch;
extern bit g_bDpDCOffHPDHigh;
extern BYTE g_ucHDMIHotPlug;
extern bit g_bDpAuxDiffMode;
extern bit g_bDigitalColorInfoChangeReset;

#if(_DP_SUPPORT == _ON)
extern StructDPMarginLinkInfo g_stDpMarginLink;
#endif

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
extern StructDpHdmiCompatibleInfo g_stDpHdmiCompatibleInfo;
#endif

#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
extern StructHDRStaticMetaData g_stHDRSaticMetadata;
#endif

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
extern bit ScalerSyncGetFREESYNCEnable(void);
extern void ScalerSyncSetFREESYNCSupport(bit bEnable);

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
extern BYTE ScalerSyncGetHDMIFREESYNCVcp_EXINT1(void);
extern void ScalerSyncSetHDMIFREESYNCVcp_EXINT1(BYTE ucVcpCode);
#endif
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
extern bit ScalerSyncHDRGetCurrentStatus(StructHDRStaticMetaData *pstHDRSaticMetadata, EnumSourceSearchPort enumSourceSearchPort);

#if(_DP_SUPPORT == _ON)
extern void ScalerSyncDPHDRInfoFrameRSV0Check(EnumSourceSearchPort enumSourceSearchPort);
extern void ScalerSyncDPHDRInfoFramePacketDetect(EnumSourceSearchPort enumSourceSearchPort);
#endif
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_DP_SUPPORT == _ON)
extern void ScalerSyncDpFakeLTProtect(void);
#endif

#if(_DP_TX_SUPPORT == _ON)
void ScalerSyncDpTxHdcpUpstreamSwitchProc(BYTE ucInputPort);

#if(_DP_MST_SUPPORT == _ON)
extern bit ScalerSyncDpFakePowerSavingCheck(void);
extern bit ScalerSyncDpFakePowerOffCheck(EnumSourceSearchPort enumInputPort);
#endif

extern void ScalerSyncHdcpEnableDownLoadDPTxKey(bit bEnable);
extern void ScalerSyncHdcpDownLoadDPTxAKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
extern void ScalerSyncHdcpDownLoadDPTxAKey(WORD usLength, BYTE *pucReadArray);
#endif

extern EnumHDCPType ScalerSyncHdcpCheckEnabled(BYTE ucInputPort);
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_URGENT_EVENT_CHECK_MODE == _ON)
extern bit ScalerSyncCheckUrgentEvent(void);
extern bit ScalerSyncGetUrgentEventFlg(void);
extern void ScalerSyncClrUrgentEventFlg(void);
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
extern BYTE ScalerSyncDdcDetect_EXINT1(void);
extern void ScalerSyncTMDSScanInitial(BYTE ucInputPort);

#if(_HDMI_SUPPORT == _ON)
extern void ScalerSyncTMDSEdidSwitch(BYTE ucPortSelect);
extern void ScalerSyncHDMIDdcCheckBusy(BYTE ucInputPort);
#endif
extern void ScalerSyncTMDSHPDToggleProc(void);
#endif

#if(_MHL_SUPPORT == _ON)
extern bit ScalerSyncMHLVBusPowerExist(void);
#endif

extern void ScalerSyncActiveProc(BYTE ucSourceType);
extern void ScalerSyncPowerProc(EnumPowerAction enumPowerAction);
extern void ScalerSyncInterfaceSwitch(BYTE ucInputPort, BYTE ucPortType, BYTE ucSourceSearchDelayMode);
extern void ScalerSyncSetDdcForceNack(BYTE ucInputPort, bit bSelect);
extern bit ScalerSyncGetDdcForceNackStatus(BYTE ucInputPort);

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern bit ScalerSyncDigitalGetColorimetryChanged(void);
extern bit ScalerSyncDigitalGetColorimetryExtChanged(void);
extern bit ScalerSyncDigitalGetQuantizationChanged(void);
extern void ScalerSyncDigitalClrColorimetryChanged(void);
extern void ScalerSyncDigitalClrColorimetryExtChanged(void);
extern void ScalerSyncDigitalClrQuantizationChanged(void);
#endif

#if(_HW_FLASH_ACCESS_METHOD == _XDATA_MAP_ACCESS)
extern bit ScalerSyncVGAUseEmbeddedEDID(void);
extern void ScalerSyncVGADdcCheckBusyAndForceNack(void);
#endif

