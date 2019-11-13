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
// ID Code      : ScalerCommonSync.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_SYNC__

#include "ScalerCommonFunctionInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE data pData_EXINT[6];

WORD idata g_usInputPixelClk;
WORD idata g_usTmdsOffLineMeasureClk;

#if(_D0_DP_EXIST == _ON)
BYTE g_ucDpRx0LTStatus = _DP_LINK_TRAINING_NONE;
bit g_bDpMSTRx0BackupLinkStatusFlg_INT;
BYTE g_pucDpRx0LinkStatusBackup_INT[2];
#endif

#if(_D1_DP_EXIST == _ON)
BYTE g_ucDpRx1LTStatus = _DP_LINK_TRAINING_NONE;
bit g_bDpMSTRx1BackupLinkStatusFlg_INT;
BYTE g_pucDpRx1LinkStatusBackup_INT[2];
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)

bit g_bDpDCOffHPDHigh = 0;
bit g_bDpAuxDiffMode = 1;
BYTE g_ucDigitalSwitch;
BYTE g_ucHDMIHotPlug;

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
StructDpHdmiCompatibleInfo g_stDpHdmiCompatibleInfo;
#endif

#if(_DP_TX_SUPPORT == _ON)
BYTE idata g_pucHdcpAksvBackup[5];
#endif

#if(_DP_SUPPORT == _ON)
StructDPCapSwitchInfo g_stDpCapSwitch;
StructDPMarginLinkInfo g_stDpMarginLink;
#endif

#if(_DP_TX_SUPPORT == _ON)
StructDPTxStatusInfo g_stDpTxStatus;
StructDpTxColorInfo g_stDpTxColorInfo;
#endif

#if(_FREESYNC_SUPPORT == _ON)

#if(_DP_FREESYNC_SUPPORT == _ON)
StructDPFREESYNCENABLE g_stDpFREESYNCInfo;
#endif

#if(_HDMI_FREESYNC_SUPPORT == _ON)
StructHDMIFREESYNCENABLE g_stHDMIFREESYNCInfo;

#if(_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE)
BYTE g_ucHDMIFREESYNCVCPReceive;
#endif
#endif

BYTE g_ucFREESYNCSupport;
WORD g_usFREESYNCVFreq;
#endif

bit g_bDigitalColorInfoChangeReset;
StructDigitalColorInfo g_stDigitalColorInfo;
StructDigitalColorInfoChanged g_stDigitalColorInfoChanged;
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
StructHDRStaticMetaData g_stHDRSaticMetadata;
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
WORD g_usDDCDebounceCnt;

#if(_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON)
StructTmdsZ0ToggleFlag g_stTmdsToggleZ0Flag;
#endif

#endif

#if(_URGENT_EVENT_CHECK_MODE == _ON)
BYTE g_ucCheckUrgentEventOccured;
#endif

#if(_HDMI_SUPPORT == _ON)
BYTE g_pucTMDSRxAviInfo[6];
#endif

#if(_HW_FLASH_ACCESS_METHOD == _XDATA_MAP_ACCESS)
#if(_A0_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
BYTE xdata g_ucFlashISPProPort                                       _at_ 0xE000;
#endif
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
bit ScalerSyncGetFREESYNCEnable(void);
void ScalerSyncSetFREESYNCSupport(bit bEnable);

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
BYTE ScalerSyncGetHDMIFREESYNCVcp_EXINT1(void);
void ScalerSyncSetHDMIFREESYNCVcp_EXINT1(BYTE ucVcpCode);
#endif
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
bit ScalerSyncHDRCheckPortStatus(EnumSourceSearchPort enumSourceSearchPort);
bit ScalerSyncHDRGetCurrentStatus(StructHDRStaticMetaData *pstHDRSaticMetadata, EnumSourceSearchPort enumSourceSearchPort);

#if(_DP_SUPPORT == _ON)
void ScalerSyncDPHDRInfoFrameRSV0Check(EnumSourceSearchPort enumSourceSearchPort);
void ScalerSyncDPHDRInfoFramePacketDetect(EnumSourceSearchPort enumSourceSearchPort);
//void ScalerSyncDpSecDataResetProc(BYTE ucInputPort);
void ScalerSyncDpHDRReset(void);
#endif
#endif

#if(_DP_SUPPORT == _ON)
void ScalerSyncDpFakeLTProtect(void);
#endif

#if(_DP_TX_SUPPORT == _ON)
void ScalerSyncDpTxPowerProc(EnumPowerAction enumPowerAction);
void ScalerSyncDpTxHdcpUpstreamSwitchProc(BYTE ucInputPort);
EnumDPRxHDCPUpstreamAuthStatus ScalerSyncDpHdcpGetUpstreamEvent(void);
bit ScalerSyncDpHdcpGetUpstreamEncryptStatus(void);

#if(_DP_MST_SUPPORT == _ON)
bit ScalerSyncDpFakePowerSavingCheck(void);
bit ScalerSyncDpFakePowerOffCheck(EnumSourceSearchPort enumInputPort);
#endif
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_DP_TX_SUPPORT == _ON)
void ScalerSyncHdcpEnableDownLoadDPTxKey(bit bEnable);
void ScalerSyncHdcpDownLoadDPTxAKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void ScalerSyncHdcpDownLoadDPTxAKey(WORD usLength, BYTE *pucReadArray);
#endif

EnumHDCPType ScalerSyncHdcpCheckEnabled(BYTE ucInputPort);
void ScalerSyncGDIPowerProc(EnumPowerAction enumPowerAction);
#endif

#if(_URGENT_EVENT_CHECK_MODE == _ON)
bit ScalerSyncCheckUrgentEvent(void);
bit ScalerSyncGetUrgentEventFlg(void);
void ScalerSyncClrUrgentEventFlg(void);
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
void ScalerSyncDdcDetectDebounce_EXINT1(void);
BYTE ScalerSyncDdcDetect_EXINT1(void);
void ScalerSyncTMDSScanInitial(BYTE ucInputPort);
#if(_HDMI_SUPPORT == _ON)
void ScalerSyncTMDSEdidSwitch(BYTE ucPortSelect);
void ScalerSyncHDMIDdcCheckBusy(BYTE ucInputPort);
#endif
void ScalerSyncTMDSHPDToggleProc(void);
#endif

#if(_MHL_SUPPORT == _ON)
bit ScalerSyncMHLVBusPowerExist(void);
#endif

void ScalerSyncActiveProc(BYTE ucSourceType);
void ScalerSyncResetProc(BYTE ucInputPort);
void ScalerSyncPowerProc(EnumPowerAction enumPowerAction);
void ScalerSyncInterfaceSwitch(BYTE ucInputPort, BYTE ucPortType, BYTE ucSourceSearchDelayMode);
void ScalerSyncSetDdcForceNack(BYTE ucInputPort, bit bSelect);
bit ScalerSyncGetDdcForceNackStatus(BYTE ucInputPort);

#if(((_D0_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF)) || ((_HDMI_SUPPORT == _ON) && (_TMDS_PAGE2_COMBO_EXIST == _ON)))
void ScalerSyncTMDSRx0HdmiVideoSetting(void);
void ScalerSyncTMDSRx0HdmiColorimetrySetting(void);
void ScalerSyncTMDSRx0HdmiColorimetryExtSetting(void);
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
void ScalerSyncTMDSRx0HdmiQuantizationSetting(void);
#endif

bit ScalerSyncTMDSRx0HdmiColorInfoChanged(void);
#endif

#if((_D1_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
void ScalerSyncTMDSRx1HdmiVideoSetting(void);
void ScalerSyncTMDSRx1HdmiColorimetrySetting(void);
void ScalerSyncTMDSRx1HdmiColorimetryExtSetting(void);
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
void ScalerSyncTMDSRx1HdmiQuantizationSetting(void);
#endif
bit ScalerSyncTMDSRx1HdmiColorInfoChanged(void);
#endif

#if((_D2_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
void ScalerSyncTMDSRx2HdmiVideoSetting(void);
#endif

void ScalerSyncTMDSRx2HdmiColorimetrySetting(void);
void ScalerSyncTMDSRx2HdmiColorimetryExtSetting(void);
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
void ScalerSyncTMDSRx2HdmiQuantizationSetting(void);
#endif
bit ScalerSyncTMDSRx2HdmiColorInfoChanged(void);
#endif

#if((_D3_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
void ScalerSyncTMDSRx3HdmiVideoSetting(void);
#endif

void ScalerSyncTMDSRx3HdmiColorimetrySetting(void);
void ScalerSyncTMDSRx3HdmiColorimetryExtSetting(void);
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
void ScalerSyncTMDSRx3HdmiQuantizationSetting(void);
#endif
bit ScalerSyncTMDSRx3HdmiColorInfoChanged(void);
#endif

#if((_D4_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
#if(_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT)
void ScalerSyncTMDSRx4HdmiVideoSetting(void);
#endif

void ScalerSyncTMDSRx4HdmiColorimetrySetting(void);
void ScalerSyncTMDSRx4HdmiColorimetryExtSetting(void);
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
void ScalerSyncTMDSRx4HdmiQuantizationSetting(void);
#endif
bit ScalerSyncTMDSRx4HdmiColorInfoChanged(void);
#endif

#if((_D5_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
void ScalerSyncTMDSRx5HdmiVideoSetting(void);
void ScalerSyncTMDSRx5HdmiColorimetrySetting(void);
void ScalerSyncTMDSRx5HdmiColorimetryExtSetting(void);
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
void ScalerSyncTMDSRx5HdmiQuantizationSetting(void);
#endif
bit ScalerSyncTMDSRx5HdmiColorInfoChanged(void);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
bit ScalerSyncDigitalGetColorimetryChanged(void);
bit ScalerSyncDigitalGetColorimetryExtChanged(void);
bit ScalerSyncDigitalGetQuantizationChanged(void);
void ScalerSyncDigitalClrColorimetryChanged(void);
void ScalerSyncDigitalClrColorimetryExtChanged(void);
void ScalerSyncDigitalClrQuantizationChanged(void);
#endif

#if(_HW_FLASH_ACCESS_METHOD == _XDATA_MAP_ACCESS)
bit ScalerSyncVGAUseEmbeddedEDID(void);
void ScalerSyncVGADdcCheckBusyAndForceNack(void);
#endif
extern void ScalerAudioWatchDogProc(bit bOn, BYTE ucInputPort);
extern void ScalerDpSecDataReset(BYTE ucInputPort);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get FREESYNC Mode Enabled
// Input Value  : None
// Output Value : True  --> Enabled
//                False --> Disabled
//--------------------------------------------------
bit ScalerSyncGetFREESYNCEnable(void)
{
    return GET_FREESYNC_ENABLED();
}

//--------------------------------------------------
// Description  : Set FREESYNC Support
// Input Value  : Enable --> Support
// Output Value : None
//--------------------------------------------------
void ScalerSyncSetFREESYNCSupport(bit bEnable)
{
    SET_FREESYNC_SUPPORT(bEnable);
}

#if((_HDMI_FREESYNC_SUPPORT == _ON) && (_HDMI_FREESYNC_CAPABILITY_SWITCH_METHOD == _MCCS_SWITCH_MODE))
//--------------------------------------------------
// Description  : Get HDMI FREESYNC VCP
// Input Value  : None
// Output Value : HDMI FREESYNC VCP
//                False --> Disabled
//--------------------------------------------------
BYTE ScalerSyncGetHDMIFREESYNCVcp_EXINT1(void) using 2
{
    return GET_HDMI_FREESYNC_VCP();
}

//--------------------------------------------------
// Description  : Set HDMI FREESYNC VCP
// Input Value  : HDMI FREESYNC VCP
// Output Value : None
//--------------------------------------------------
void ScalerSyncSetHDMIFREESYNCVcp_EXINT1(BYTE ucVcpCode) using 2
{
    g_ucHDMIFREESYNCVCPReceive = ucVcpCode;
}
#endif
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Current HDR data enable status
// Input Value  : enumSourceSearchPort --> Input port
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
bit ScalerSyncHDRCheckPortStatus(EnumSourceSearchPort enumSourceSearchPort)
{
    switch(enumSourceSearchPort)
    {
        case _D0_INPUT_PORT:
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) ||\
    (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            if(_HDMI_ULTRA_HDR_SUPPORT == _OFF)
            {
                return _FALSE;
            }
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            if(_DP_ULTRA_HDR_SUPPORT == _OFF)
            {
                return _FALSE;
            }
#endif
            break;

        case _D1_INPUT_PORT:
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) ||\
    (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            if(_HDMI_ULTRA_HDR_SUPPORT == _OFF)
            {
                return _FALSE;
            }
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            if(_DP_ULTRA_HDR_SUPPORT == _OFF)
            {
                return _FALSE;
            }
#endif
            break;

        case _D2_INPUT_PORT:
#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) ||\
    (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            if(_HDMI_ULTRA_HDR_SUPPORT == _OFF)
            {
                return _FALSE;
            }
#endif
            break;

        case _D3_INPUT_PORT:
#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) ||\
    (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            if(_HDMI_ULTRA_HDR_SUPPORT == _OFF)
            {
                return _FALSE;
            }
#endif
            break;

        default:
            return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get Current HDR data
// Input Value  : stHDRSaticMetadata --> HDR data
//                enumSourceSearchPort --> Input port
// Output Value : _FALSE: no receive
//--------------------------------------------------
bit ScalerSyncHDRGetCurrentStatus(StructHDRStaticMetaData *pstHDRSaticMetadata, EnumSourceSearchPort enumSourceSearchPort)
{
    if(ScalerSyncHDRCheckPortStatus(enumSourceSearchPort) == _TRUE)
    {
        bit bHDRInfoReceive = 0;
        BYTE pucHDRInfoData[_HW_DP_INFOFRAME_RSV0_LENGTH];

        memset(pucHDRInfoData, 0, _HW_DP_INFOFRAME_RSV0_LENGTH);

#if(_TMDS_PAGE2_COMBO_EXIST == _ON)

        if((((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)) && (enumSourceSearchPort == _D0_INPUT_PORT)) ||
           (((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)) && (enumSourceSearchPort == _D1_INPUT_PORT)) ||
           (((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)) && (enumSourceSearchPort == _D2_INPUT_PORT)))
        {
            bHDRInfoReceive = GET_HDMI_RX0_HDR_INFO_FRAME_RECEIVED();

            ScalerTMDSRx0GetHDRData(pucHDRInfoData);
        }

#else

        switch(enumSourceSearchPort)
        {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

            case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            case _D6_INPUT_PORT:
#endif
                bHDRInfoReceive = GET_DP_RX0_HDR_INFO_FRAME_RECEIVED();
                memcpy(pucHDRInfoData, g_pucDPRx0HDRBackup, _HW_DP_INFOFRAME_RSV0_LENGTH);

                break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            case _D1_INPUT_PORT:

                bHDRInfoReceive = GET_DP_RX1_HDR_INFO_FRAME_RECEIVED();
                memcpy(pucHDRInfoData, g_pucDPRx1HDRBackup, _HW_DP_INFOFRAME_RSV0_LENGTH);

                break;

#elif((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            case _D1_INPUT_PORT:

                bHDRInfoReceive = GET_HDMI_RX1_HDR_INFO_FRAME_RECEIVED();

                ScalerTMDSRx1GetHDRData(pucHDRInfoData);

                break;

#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            case _D2_INPUT_PORT:

                bHDRInfoReceive = GET_HDMI_RX2_HDR_INFO_FRAME_RECEIVED();

                ScalerTMDSRx2GetHDRData(pucHDRInfoData);

                break;
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            case _D3_INPUT_PORT:

                bHDRInfoReceive = GET_HDMI_RX3_HDR_INFO_FRAME_RECEIVED();

                ScalerTMDSRx3GetHDRData(pucHDRInfoData);

                break;
#endif

            default:
                break;
				
        }

#endif
		DebugMessageHDR("pucHDRInfoData[0]",pucHDRInfoData[0]);
		DebugMessageHDR("pucHDRInfoData[1]",pucHDRInfoData[1]);
		DebugMessageHDR("pucHDRInfoData[2]",pucHDRInfoData[2]);
		DebugMessageHDR("bHDRInfoReceive",bHDRInfoReceive);

        // Check HDR Version/ Length & InfoFrame receive bit
        if((pucHDRInfoData[0] == 0x01) && (pucHDRInfoData[1] == 0x1A) && (bHDRInfoReceive == _TRUE))
        {
            pstHDRSaticMetadata->ucEOTF = pucHDRInfoData[2];
            pstHDRSaticMetadata->ucStaticMetadataID = pucHDRInfoData[3];

            pstHDRSaticMetadata->usDisplayPrimariesX0 = ((WORD)(pucHDRInfoData[5] << 8) | (pucHDRInfoData[4]));
            pstHDRSaticMetadata->usDisplayPrimariesY0 = ((WORD)(pucHDRInfoData[7] << 8) | (pucHDRInfoData[6]));

            pstHDRSaticMetadata->usDisplayPrimariesX1 = ((WORD)(pucHDRInfoData[9] << 8) | (pucHDRInfoData[8]));
            pstHDRSaticMetadata->usDisplayPrimariesY1 = ((WORD)(pucHDRInfoData[11] << 8) | (pucHDRInfoData[10]));

            pstHDRSaticMetadata->usDisplayPrimariesX2 = ((WORD)(pucHDRInfoData[13] << 8) | (pucHDRInfoData[12]));
            pstHDRSaticMetadata->usDisplayPrimariesY2 = ((WORD)(pucHDRInfoData[15] << 8) | (pucHDRInfoData[14]));

            pstHDRSaticMetadata->usWhitePointX = ((WORD)(pucHDRInfoData[17] << 8) | (pucHDRInfoData[16]));
            pstHDRSaticMetadata->usWhitePointY = ((WORD)(pucHDRInfoData[19] << 8) | (pucHDRInfoData[18]));

            pstHDRSaticMetadata->usMaxDisplayMasteringLv = ((WORD)(pucHDRInfoData[21] << 8) | (pucHDRInfoData[20]));
            pstHDRSaticMetadata->usMinDisplayMasteringLv = ((WORD)(pucHDRInfoData[23] << 8) | (pucHDRInfoData[22]));

            pstHDRSaticMetadata->usMaxCLL = ((WORD)(pucHDRInfoData[25] << 8) | (pucHDRInfoData[24]));
            pstHDRSaticMetadata->usMaxFALL = ((WORD)(pucHDRInfoData[27] << 8) | (pucHDRInfoData[26]));

            return _TRUE;
        }
    }

    pstHDRSaticMetadata->ucEOTF = 0x00;
    pstHDRSaticMetadata->ucStaticMetadataID = 0x00;

    pstHDRSaticMetadata->usDisplayPrimariesX0 = 0x0000;
    pstHDRSaticMetadata->usDisplayPrimariesY0 = 0x0000;

    pstHDRSaticMetadata->usDisplayPrimariesX1 = 0x0000;
    pstHDRSaticMetadata->usDisplayPrimariesY1 = 0x0000;

    pstHDRSaticMetadata->usDisplayPrimariesX2 = 0x0000;
    pstHDRSaticMetadata->usDisplayPrimariesY2 = 0x0000;

    pstHDRSaticMetadata->usWhitePointX = 0x0000;
    pstHDRSaticMetadata->usWhitePointY = 0x0000;

    pstHDRSaticMetadata->usMaxDisplayMasteringLv = 0x0000;
    pstHDRSaticMetadata->usMinDisplayMasteringLv = 0x0000;

    pstHDRSaticMetadata->usMaxCLL = 0x0000;
    pstHDRSaticMetadata->usMaxFALL = 0x0000;

    return _FALSE;
}

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : HDR Infoframe RSV0 Check
// Input Value  : Input source port
// Output Value : None
//--------------------------------------------------
void ScalerSyncDPHDRInfoFrameRSV0Check(EnumSourceSearchPort enumSourceSearchPort)
{
    switch(enumSourceSearchPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif
            ScalerDpRx0InfoFrameRSV0Check();

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            ScalerDpRx1InfoFrameRSV0Check();

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : HDR Infoframe packet detect
// Input Value  : Input source port
// Output Value : None
//--------------------------------------------------
void ScalerSyncDPHDRInfoFramePacketDetect(EnumSourceSearchPort enumSourceSearchPort)
{
    switch(enumSourceSearchPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            if(GET_DP_RX0_RSV0_DETECTING() == _FALSE)
            {
                SET_DP_RX0_RSV0_DETECTING();
                ScalerDpRx0InfoFrameRSV0Check();

#if(_DP_FREESYNC_SUPPORT == _ON)
                // Activate Packet Detection Event
                ScalerTimerActiveTimerEvent(SEC(0.13), _SCALER_TIMER_EVENT_DP_RX0_RSV0_PACKET_DETECT);
#else
                // Activate Packet Detection Event
                ScalerTimerActiveTimerEvent(((WORD)2 * 10000 / GET_INPUT_TIMING_VFREQ()), _SCALER_TIMER_EVENT_DP_RX0_RSV0_PACKET_DETECT);
#endif
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            if(GET_DP_RX1_RSV0_DETECTING() == _FALSE)
            {
                SET_DP_RX1_RSV0_DETECTING();
                ScalerDpRx1InfoFrameRSV0Check();

#if(_DP_FREESYNC_SUPPORT == _ON)
                // Activate Packet Detection Event
                ScalerTimerActiveTimerEvent(SEC(0.13), _SCALER_TIMER_EVENT_DP_RX1_RSV0_PACKET_DETECT);
#else
                // Activate Packet Detection Event
                ScalerTimerActiveTimerEvent(((WORD)2 * 10000 / GET_INPUT_TIMING_VFREQ()), _SCALER_TIMER_EVENT_DP_RX1_RSV0_PACKET_DETECT);
#endif
            }

            break;
#endif

        default:

            break;
    }
}
/*
//--------------------------------------------------
// Description  : DP Audio Secondary Data Reset Process
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpSecDataResetProc(BYTE ucInputPort)
{
#if(_AUDIO_SUPPORT == _ON)
    WORD usVolume = 0;

    if(ScalerAudioDPGetMuteProc(ucInputPort) == _TRUE)
    {
        usVolume = ((WORD) ScalerGetBit(P8_A5_DVC_GAIN_MSB, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | ScalerGetByte(P8_A6_DVC_GAIN_LSB);

        ScalerAudioMuteProc(_ON, usVolume);
        ScalerAudioWatchDogProc(_OFF, ScalerAudioGetDigitalAudioPortMapping());

#if(_EMBEDDED_DAC_SUPPORT == _ON)
        ScalerAudioDACNormalToDepop();
#endif
    }
#endif

    ScalerDpSecDataReset(ucInputPort);
}
*/
//--------------------------------------------------
// Description  : DP HDR Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpHDRReset(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    ScalerDpRx0SetInitialRSV0InfoType();
    memset(g_pucDPRx0HDRBackup, 0, sizeof(g_pucDPRx0HDRBackup));
    memset(g_pucDPRx0RSV0Backup, 0, sizeof(g_pucDPRx0RSV0Backup));
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    ScalerDpRx1SetInitialRSV0InfoType();
    memset(g_pucDPRx1HDRBackup, 0, sizeof(g_pucDPRx1HDRBackup));
    memset(g_pucDPRx1RSV0Backup, 0, sizeof(g_pucDPRx1RSV0Backup));
#endif
}
#endif
#endif // End of #if(_ULTRA_HDR_SUPPORT == _ON)

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Fake LT Protect
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpFakeLTProtect(void)
{
#if(_D0_DP_EXIST == _ON)
    // DP Fake LT Protect
    ScalerDpRx0FakeLTProtect();
#endif

#if(_D1_DP_EXIST == _ON)
    // DP Fake LT Protect
    ScalerDpRx1FakeLTProtect();
#endif
}
#endif

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Tx PowerProc
// Input Value  : EnumPowerAction
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpTxPowerProc(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:

            ScalerDpTxInitial();

            // Power CMU PHY But use power down mode
            ScalerGDIPhyTxCMUPowerDownMode();

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:
        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            ScalerDpTxStateChangeEvent(_DP_TX_MODE_STATUS_INITIAL);

            CLR_DP_TX_DOWNSTREAM_INFO_READY();

            // Power Down ML PHY
            ScalerGDIPhyTxMLPowerOff();

            // Power CMU PHY
            ScalerGDIPhyTxCMUPowerOff();

            // Power Down Aux CH
            ScalerSetBit(PBD_A0_AUX_TX_CTRL, ~_BIT0, 0x00);

            // Clear HPD IRQ Flag
            ScalerSetByte(PBB_71_HPD_IRQ, 0xFE);

            // Clear IRQ HPD Type Flag
            CLR_DP_TX_IRQ_HPD_TYPE();
            CLR_DP_TX_IRQ_HPD_TYPE_INT();
            CLR_DP_TX_IRQ_HPD_DETECTED();
            CLR_DP_TX_IRQ_HDCP_TYPE();

            break;

        case _POWER_ACTION_PS_TO_OFF:

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Dp Hdcp Port Switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDpTxHdcpUpstreamSwitchProc(BYTE ucInputPort)
{
#if(_DP_MST_SUPPORT == _ON)
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || ((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)))
    if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
    {
        SET_DP_RX_HDCP_UPSTREAM_PORT(_HDCP_D0_PORT);

        return;
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
    {
        SET_DP_RX_HDCP_UPSTREAM_PORT(_HDCP_D1_PORT);

        return;
    }
#endif
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || ((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)))
    if((ucInputPort == _D0_INPUT_PORT) || (ucInputPort == _D6_INPUT_PORT))
    {
        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS))
        {
            SET_DP_RX_HDCP_UPSTREAM_PORT(_HDCP_D0_PORT);

            return;
        }
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(ucInputPort == _D1_INPUT_PORT)
    {
        if((GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS))
        {
            SET_DP_RX_HDCP_UPSTREAM_PORT(_HDCP_D1_PORT);

            return;
        }
    }
#endif

    SET_DP_RX_HDCP_UPSTREAM_PORT(_HDCP_NO_PORT);
}

//--------------------------------------------------
// Description  : Get Upstream HDCP event
// Input Value  : None
// Output Value : EnumDPRxHDCPUpstreamAuthStatus
//--------------------------------------------------
EnumDPRxHDCPUpstreamAuthStatus ScalerSyncDpHdcpGetUpstreamEvent(void)
{
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || ((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)))
    if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D0_PORT)
    {
        return GET_DP_RX0_HDCP_UPSTREAM_EVENT();
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D1_PORT)
    {
        return GET_DP_RX1_HDCP_UPSTREAM_EVENT();
    }
#endif

    return _DP_RX_HDCP_UPSTREAM_AUTH_EVENT_NONE;
}

//--------------------------------------------------
// Description  : Get Upstream HDCP status
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerSyncDpHdcpGetUpstreamEncryptStatus(void)
{
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || ((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0)))
    if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D0_PORT)
    {
        return ((ScalerDpRx0HdcpEnebled() == _TRUE) && (ScalerDpRx0HDCPCheckLvp() == _TRUE));
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D1_PORT)
    {
        return ((ScalerDpRx1HdcpEnebled() == _TRUE) && (ScalerDpRx1HDCPCheckLvp() == _TRUE));
    }
#endif

    return _FALSE;
}

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Rx Fake Power Saving Check
// Input Value  : None
// Output Value : True  --> Fake Power Saving
//                False --> Power Saving
//--------------------------------------------------
bit ScalerSyncDpFakePowerSavingCheck(void)
{
    if(g_enumDpMSTCapablePort != _DP_MST_NO_PORT)
    {
        if(GET_DP_SOURCE_FIRST_POWER_ON() == _TRUE)
        {
            return _TRUE;
        }

        if(GET_DP_CHECK_AUX_CH_POWER_OFF() == _TRUE)
        {
            return _FALSE;
        }

        if((GET_REG_DP_DPCD_INFO(0x00, 0x01, 0x11) & _BIT0) == _BIT0)
        {
            return _TRUE;
        }

        // Check if MSG Processing or Stream Propagating
        if((ScalerDpRxMstCheckMsgTransition() == _TRUE) || (GET_REG_DP_DPCD_INFO(0x00, 0x02, 0xC1) != 0))
        {
            return _TRUE;
        }

        return GET_DP_LT_STATUS_CHCEK();
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Dp Rx Fake Power Off Check
// Input Value  : enumInputPort
// Output Value : True  --> Fake Power Off
//                False --> Power Off
//--------------------------------------------------
bit ScalerSyncDpFakePowerOffCheck(EnumSourceSearchPort enumInputPort)
{
    if(((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) && (enumInputPort == _D0_INPUT_PORT)) ||
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
       ((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) && (enumInputPort == _D6_INPUT_PORT)) ||
#endif
       ((g_enumDpMSTCapablePort == _DP_MST_RX1_PORT) && (enumInputPort == _D1_INPUT_PORT)))
    {
        // Mst enable & Upstream Is Source
        if((GET_REG_DP_DPCD_INFO(0x00, 0x01, 0x11) & (_BIT2 | _BIT0)) == (_BIT2 | _BIT0))
        {
            return _TRUE;
        }
    }

    return _FALSE;
}
#endif // End of #if(_DP_MST_SUPPORT == _ON)

#endif // End of #if(_DP_TX_SUPPORT == _ON)

#if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable DownLoad DPTx HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncHdcpEnableDownLoadDPTxKey(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        // Enable Key download port
        ScalerSetBit(PBB_30_DPTX_HDCP_CTRL1, ~_BIT3, _BIT3);
    }
    else
    {
        // Disable Key download port
        ScalerSetBit(PBB_30_DPTX_HDCP_CTRL1, ~_BIT3, 0x00);
    }
}

//--------------------------------------------------
// Description  : DownLoad TX HDCP AKsv
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncHdcpDownLoadDPTxAKsv(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
    for(pData[0] = ucSubAddr; pData[0] < ucLength; pData[0]++)
    {
        g_pucHdcpAksvBackup[pData[0]] = pucReadArray[pData[0]];
    }

    DebugMessageDigital("8. HDCP Aksv Backup", g_pucHdcpAksvBackup[0]);
    DebugMessageDigital("8. HDCP Aksv Backup", g_pucHdcpAksvBackup[1]);
    DebugMessageDigital("8. HDCP Aksv Backup", g_pucHdcpAksvBackup[2]);
    DebugMessageDigital("8. HDCP Aksv Backup", g_pucHdcpAksvBackup[3]);
    DebugMessageDigital("8. HDCP Aksv Backup", g_pucHdcpAksvBackup[4]);
}

//--------------------------------------------------
// Description  : DownLoad TX HDCP Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncHdcpDownLoadDPTxAKey(WORD usLength, BYTE *pucReadArray)
{
    ScalerWrite(PBB_32_DP_HDCP_KEY_DL_PORT, usLength, pucReadArray, _NON_AUTOINC);
}
#endif

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : Input Port
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
EnumHDCPType ScalerSyncHdcpCheckEnabled(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            if(ScalerDpHdcpCheckEnabled(ucInputPort) == _TRUE)
            {
#if(_DP_HDCP_2_2_SUPPORT == _ON)
                if(GET_DP_RX0_HDCP2_MODE() == _TRUE)
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX0_HDCP2_REPEATER_CAPABLE() == _TRUE)
                    {
                        return _HDCP_22_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_22;
                    }
                }
                else
#endif
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX0_HDCP_REPEATER_SUPPORT() == _TRUE)
                    {
                        return _HDCP_14_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_14;
                    }
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#else

#if(_D0_TMDS_SUPPORT == _ON)
            if(ScalerTMDSHdcpEnabled(ucInputPort) == _TRUE)
            {
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && ((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)))
                if(GET_TMDS_RX0_HDCP2_MODE() == _TRUE)
                {
                    return _HDCP_22;
                }
                else
#endif
                {
                    return _HDCP_14;
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif

#endif
            break;

        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            if(ScalerDpHdcpCheckEnabled(ucInputPort) == _TRUE)
            {
#if(_DP_HDCP_2_2_SUPPORT == _ON)
                if(GET_DP_RX1_HDCP2_MODE() == _TRUE)
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX1_HDCP2_REPEATER_CAPABLE() == _TRUE)
                    {
                        return _HDCP_22_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_22;
                    }
                }
                else
#endif
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX1_HDCP_REPEATER_SUPPORT() == _TRUE)
                    {
                        return _HDCP_14_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_14;
                    }
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#else

#if(_D1_TMDS_SUPPORT == _ON)
            if(ScalerTMDSHdcpEnabled(ucInputPort) == _TRUE)
            {
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && ((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)))
                if(GET_TMDS_RX1_HDCP2_MODE() == _TRUE)
                {
                    return _HDCP_22;
                }
                else
#endif
                {
                    return _HDCP_14;
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif

#endif
            break;

        case _D2_INPUT_PORT:
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if(ScalerDpHdcpCheckEnabled(ucInputPort) == _TRUE)
            {
#if(_DP_HDCP_2_2_SUPPORT == _ON)
                if(GET_DP_RX1_HDCP2_MODE() == _TRUE)
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX1_HDCP2_REPEATER_CAPABLE() == _TRUE)
                    {
                        return _HDCP_22_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_22;
                    }
                }
                else
#endif
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX1_HDCP_REPEATER_SUPPORT() == _TRUE)
                    {
                        return _HDCP_14_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_14;
                    }
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#else

#if(_D2_TMDS_SUPPORT == _ON)
            if(ScalerTMDSHdcpEnabled(ucInputPort) == _TRUE)
            {
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && ((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)))
                if(GET_TMDS_RX2_HDCP2_MODE() == _TRUE)
                {
                    return _HDCP_22;
                }
                else
#endif
                {
                    return _HDCP_14;
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif

#endif
            break;

        case _D3_INPUT_PORT:
#if(_D3_TMDS_SUPPORT == _ON)
            if(ScalerTMDSHdcpEnabled(ucInputPort) == _TRUE)
            {
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && ((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)))
                if(GET_TMDS_RX3_HDCP2_MODE() == _TRUE)
                {
                    return _HDCP_22;
                }
                else
#endif
                {
                    return _HDCP_14;
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif
            break;

        case _D4_INPUT_PORT:
#if(_D4_TMDS_SUPPORT == _ON)
            if(ScalerTMDSHdcpEnabled(ucInputPort) == _TRUE)
            {
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && ((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)))
                if(GET_TMDS_RX4_HDCP2_MODE() == _TRUE)
                {
                    return _HDCP_22;
                }
                else
#endif
                {
                    return _HDCP_14;
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif
            break;

        case _D5_INPUT_PORT:
#if(_D5_TMDS_SUPPORT == _ON)
            if(ScalerTMDSHdcpEnabled(ucInputPort) == _TRUE)
            {
#if((_TMDS_HDCP_2_2_SUPPORT == _ON) && ((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)))
                if(GET_TMDS_RX5_HDCP2_MODE() == _TRUE)
                {
                    return _HDCP_22;
                }
                else
#endif
                {
                    return _HDCP_14;
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif
            break;

        case _D6_INPUT_PORT:
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            if(ScalerDpHdcpCheckEnabled(ucInputPort) == _TRUE)
            {
#if(_DP_HDCP_2_2_SUPPORT == _ON)
                if(GET_DP_RX0_HDCP2_MODE() == _TRUE)
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX0_HDCP2_REPEATER_CAPABLE() == _TRUE)
                    {
                        return _HDCP_22_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_22;
                    }
                }
                else
#endif
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX0_HDCP_REPEATER_SUPPORT() == _TRUE)
                    {
                        return _HDCP_14_REPEATER;
                    }
                    else
#endif
                    {
                        return _HDCP_14;
                    }
                }
            }
            else
            {
                return _HDCP_NONE;
            }
#endif
            break;
        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : GDI Power Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncGDIPowerProc(EnumPowerAction enumPowerAction)
{
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, enumPowerAction);
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, enumPowerAction);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, enumPowerAction);
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, enumPowerAction);
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, enumPowerAction);
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, enumPowerAction);
#endif
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_URGENT_EVENT_CHECK_MODE == _ON)
//--------------------------------------------------
// Description  : Check Urgent Event Occur
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerSyncCheckUrgentEvent(void)
{
#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
    if(ScalerDpRxMstCheckMsgTransition() == _TRUE)
    {
        SET_URGENT_EVENT_OCCUR_FLG();

        return _TRUE;
    }
#endif

#if(_HDCP_2_2_SUPPORT == _ON)
    if(GET_HDCP_2_2_AUTHENTICATION_ACTIVE() == _TRUE)
    {
        DebugMessageHDCP2("HDCP2 Urgent", g_ucHdcp2AuthActive);

        SET_URGENT_EVENT_OCCUR_FLG();

        return _TRUE;
    }
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Urgent Event Occured Flag
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerSyncGetUrgentEventFlg(void)
{
    return GET_URGENT_EVENT_OCCUR_FLG();
}

//--------------------------------------------------
// Description  : Clear Urgent Event Occured Flag
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncClrUrgentEventFlg(void)
{
    CLR_URGENT_EVENT_OCCUR_FLG();
}
#endif // End of #if(_URGENT_EVENT_CHECK_MODE == _ON)

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS DDC Debounce
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void ScalerSyncDdcDetectDebounce_EXINT1(void) using 2
{
    WORD usDebounceCnt = 0;

    // Debounce 300us
    for(usDebounceCnt = 0; usDebounceCnt < g_usDDCDebounceCnt; usDebounceCnt++) {};
}
#pragma restore

//--------------------------------------------------
// Description  : TMDS Power Saving Detect DDC Handshake
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerSyncDdcDetect_EXINT1(void) using 2
{
#if(((_D0_TMDS_SUPPORT == _ON) && (_D0_DDC_CHANNEL_SEL == _DDC0)) || ((_D1_TMDS_SUPPORT == _ON) && (_D1_DDC_CHANNEL_SEL == _DDC0)) || ((_D2_TMDS_SUPPORT == _ON) && (_D2_DDC_CHANNEL_SEL == _DDC0)))

    // DDC0 Detect SCL Toggle
    if((MCU_FFE4_DDC0_EDID_IRQ & 0x0C) == 0x0C)
    {
        // Debounce 300us
        ScalerSyncDdcDetectDebounce_EXINT1();

        // Clear SCL Toggle
        MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;

        // EDID read freq. 100K about 20us
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);

        // Double check SCL Toggle again
        if((MCU_FFE4_DDC0_EDID_IRQ & 0x0C) == 0x0C)
        {
            // Disable SCL Toggle IRQ
            MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT3;
            // Clear SCL Toggle
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;

#if((_D0_TMDS_SUPPORT == _ON) && (_D0_DDC_CHANNEL_SEL == _DDC0))
            if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
            {
                SET_TMDS_RX0_DDC_DETECTED();
            }
#elif((_D1_TMDS_SUPPORT == _ON) && (_D1_DDC_CHANNEL_SEL == _DDC0))
            if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
            {
                SET_TMDS_RX1_DDC_DETECTED();
            }
#elif((_D2_TMDS_SUPPORT == _ON) && (_D2_DDC_CHANNEL_SEL == _DDC0))
            if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
            {
                SET_TMDS_RX2_DDC_DETECTED();
            }
#endif

            return _TRUE;
        }
    }
#endif

#if(((_D0_TMDS_SUPPORT == _ON) && (_D0_DDC_CHANNEL_SEL == _DDC1)) || ((_D1_TMDS_SUPPORT == _ON) && (_D1_DDC_CHANNEL_SEL == _DDC1)) || ((_D2_TMDS_SUPPORT == _ON) && (_D2_DDC_CHANNEL_SEL == _DDC1)))

    // DDC1 Detect SCL Toggle
    if((MCU_FFE5_DDC1_EDID_IRQ & 0x0C) == 0x0C)
    {
        // Debounce 300us
        ScalerSyncDdcDetectDebounce_EXINT1();

        // Clear SCL Toggle
        MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;

        // EDID read freq. 100K about 20us
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);

        // Double check SCL Toggle again
        if((MCU_FFE5_DDC1_EDID_IRQ & 0x0C) == 0x0C)
        {
            // Disable SCL Toggle IRQ
            MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT3;
            // Clear SCL Toggle
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;

#if((_D0_TMDS_SUPPORT == _ON) && (_D0_DDC_CHANNEL_SEL == _DDC1))
            if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
            {
                SET_TMDS_RX0_DDC_DETECTED();
            }
#elif((_D1_TMDS_SUPPORT == _ON) && (_D1_DDC_CHANNEL_SEL == _DDC1))
            if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
            {
                SET_TMDS_RX1_DDC_DETECTED();
            }
#elif((_D2_TMDS_SUPPORT == _ON) && (_D2_DDC_CHANNEL_SEL == _DDC1))
            if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
            {
                SET_TMDS_RX2_DDC_DETECTED();
            }
#endif
            return _TRUE;
        }
    }
#endif

#if(((_D0_TMDS_SUPPORT == _ON) && (_D0_DDC_CHANNEL_SEL == _DDC2)) || ((_D1_TMDS_SUPPORT == _ON) && (_D1_DDC_CHANNEL_SEL == _DDC2)) || ((_D2_TMDS_SUPPORT == _ON) && (_D2_DDC_CHANNEL_SEL == _DDC2)))

    // DDC2 Detect SCL Toggle
    if((MCU_FE69_DDC2_EDID_IRQ & 0x0C) == 0x0C)
    {
        // Debounce 300us
        ScalerSyncDdcDetectDebounce_EXINT1();

        // Clear SCL Toggle
        MCU_FE69_DDC2_EDID_IRQ |= _BIT2;

        // EDID read freq. 100K about 20us
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);

        // Double check SCL Toggle again
        if((MCU_FE69_DDC2_EDID_IRQ & 0x0C) == 0x0C)
        {
            // Disable SCL Toggle IRQ
            MCU_FE69_DDC2_EDID_IRQ &= ~_BIT3;
            // Clear SCL Toggle
            MCU_FE69_DDC2_EDID_IRQ |= _BIT2;

#if((_D0_TMDS_SUPPORT == _ON) && (_D0_DDC_CHANNEL_SEL == _DDC2))
            if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
            {
                SET_TMDS_RX0_DDC_DETECTED();
            }
#elif((_D1_TMDS_SUPPORT == _ON) && (_D1_DDC_CHANNEL_SEL == _DDC2))
            if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
            {
                SET_TMDS_RX1_DDC_DETECTED();
            }
#elif((_D2_TMDS_SUPPORT == _ON) && (_D2_DDC_CHANNEL_SEL == _DDC2))
            if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
            {
                SET_TMDS_RX2_DDC_DETECTED();
            }
#endif
            return _TRUE;
        }
    }
#endif

#if((_D3_TMDS_SUPPORT == _ON) && (_D3_DDC_CHANNEL_SEL == _DDC3))

    // DDC3 Detect SCL Toggle
    if((MCU_FE72_DDC3_EDID_IRQ & 0x0C) == 0x0C)
    {
        // Debounce 300us
        ScalerSyncDdcDetectDebounce_EXINT1();

        // Clear SCL Toggle
        MCU_FE72_DDC3_EDID_IRQ |= _BIT2;

        // EDID read freq. 100K about 20us
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);

        // Double check SCL Toggle again
        if((MCU_FE72_DDC3_EDID_IRQ & 0x0C) == 0x0C)
        {
            // Disable SCL Toggle IRQ
            MCU_FE72_DDC3_EDID_IRQ &= ~_BIT3;
            // Clear SCL Toggle
            MCU_FE72_DDC3_EDID_IRQ |= _BIT2;

            if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
            {
                SET_TMDS_RX3_DDC_DETECTED();
            }

            return _TRUE;
        }
    }
#endif

#if((_D4_TMDS_SUPPORT == _ON) && (_D4_DDC_CHANNEL_SEL == _DDC4))

    // DDC4 Detect SCL Toggle
    if((MCU_FE7B_DDC4_EDID_IRQ & 0x0C) == 0x0C)
    {
        // Debounce 300us
        ScalerSyncDdcDetectDebounce_EXINT1();

        // Clear SCL Toggle
        MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;

        // EDID read freq. 100K about 20us
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);

        // Double check SCL Toggle again
        if((MCU_FE7B_DDC4_EDID_IRQ & 0x0C) == 0x0C)
        {
            // Disable SCL Toggle IRQ
            MCU_FE7B_DDC4_EDID_IRQ &= ~_BIT3;
            // Clear SCL Toggle
            MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;

            if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
            {
                SET_TMDS_RX4_DDC_DETECTED();
            }

            return _TRUE;
        }
    }
#endif

#if((_D5_TMDS_SUPPORT == _ON) && (_D5_DDC_CHANNEL_SEL == _DDC5))

    // DDC5 Detect SCL Toggle
    if((MCU_FE84_DDC5_EDID_IRQ & 0x0C) == 0x0C)
    {
        // Debounce 300us
        ScalerSyncDdcDetectDebounce_EXINT1();

        // Clear SCL Toggle
        MCU_FE84_DDC5_EDID_IRQ |= _BIT2;

        // EDID read freq. 100K about 20us
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);
        Delay5us_EXINT(g_ucDelay5usN);

        // Double check SCL Toggle again
        if((MCU_FE84_DDC5_EDID_IRQ & 0x0C) == 0x0C)
        {
            // Disable SCL Toggle IRQ
            MCU_FE84_DDC5_EDID_IRQ &= ~_BIT3;
            // Clear SCL Toggle
            MCU_FE84_DDC5_EDID_IRQ |= _BIT2;

            if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
            {
                SET_TMDS_RX5_DDC_DETECTED();
            }

            return _TRUE;
        }
    }
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : Initial Setting for TMDS Scanning Port(Power Normal)
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSScanInitial(BYTE ucInputPort)
{
    // Set Power normal DDC Debounce Counter
    g_usDDCDebounceCnt = _TMDS_DDC_DEBOUNCE_NORMAL;

    ScalerTMDSInitial(ucInputPort);

    ScalerTMDSInterruptInitial(ucInputPort);
}

#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS EDID Switch
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSEdidSwitch(BYTE ucPortSelect)
{
    switch(ucPortSelect)
    {
        // For User, DVI and DUAL_DVI Port can not pull HPD
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
        case _D0_INPUT_PORT:

            SET_TMDS_RX0_HPD_TRIGGER_EVENT(_TMDS_HPD_EDID_SWITCH);

            break;
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
        case _D1_INPUT_PORT:

            SET_TMDS_RX1_HPD_TRIGGER_EVENT(_TMDS_HPD_EDID_SWITCH);

            break;
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
        case _D2_INPUT_PORT:

            SET_TMDS_RX2_HPD_TRIGGER_EVENT(_TMDS_HPD_EDID_SWITCH);

            break;
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
        case _D3_INPUT_PORT:

            SET_TMDS_RX3_HPD_TRIGGER_EVENT(_TMDS_HPD_EDID_SWITCH);

            break;
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
        case _D4_INPUT_PORT:

            SET_TMDS_RX4_HPD_TRIGGER_EVENT(_TMDS_HPD_EDID_SWITCH);

            break;
#endif

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
        case _D5_INPUT_PORT:

            SET_TMDS_RX5_HPD_TRIGGER_EVENT(_TMDS_HPD_EDID_SWITCH);

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Check DDC channel Idle
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerSyncHDMIDdcCheckBusy(BYTE ucInputPort)
{
    WORD ustemp = 0;

    switch(ucInputPort)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                // Disable SCL Toggle IRQ
                MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT3;
                MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;

                // set a polling duration
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FFE4_DDC0_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif

#if(_D0_DDC_CHANNEL_SEL == _DDC1)
                // Disable SCL Toggle IRQ
                MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT3;
                MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;

                // set a polling duration
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // Delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FFE5_DDC1_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif

#if(_D0_DDC_CHANNEL_SEL == _DDC2)
                // Disable SCL Toggle IRQ
                MCU_FE69_DDC2_EDID_IRQ &= ~_BIT3;
                MCU_FE69_DDC2_EDID_IRQ |= _BIT2;

                // Set a Polling Duration: 30ms
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FE69_DDC2_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FE69_DDC2_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif
            }
            break;
#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                // Disable SCL Toggle IRQ
                MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT3;
                MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;

                // set a polling duration
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FFE4_DDC0_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif

#if(_D1_DDC_CHANNEL_SEL == _DDC1)
                // Disable SCL Toggle IRQ
                MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT3;
                MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;

                // set a polling duration
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // Delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FFE5_DDC1_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif

#if(_D1_DDC_CHANNEL_SEL == _DDC2)
                // Disable SCL Toggle IRQ
                MCU_FE69_DDC2_EDID_IRQ &= ~_BIT3;
                MCU_FE69_DDC2_EDID_IRQ |= _BIT2;

                // Set a Polling Duration: 30ms
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FE69_DDC2_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FE69_DDC2_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif
            }
            break;
#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
            if(GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
#if(_D2_DDC_CHANNEL_SEL == _DDC0)
                // Disable SCL Toggle IRQ
                MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT3;
                MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;

                // set a polling duration
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FFE4_DDC0_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif

#if(_D2_DDC_CHANNEL_SEL == _DDC1)
                // Disable SCL Toggle IRQ
                MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT3;
                MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;

                // set a polling duration
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // Delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FFE5_DDC1_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif

#if(_D2_DDC_CHANNEL_SEL == _DDC2)
                // Disable SCL Toggle IRQ
                MCU_FE69_DDC2_EDID_IRQ &= ~_BIT3;
                MCU_FE69_DDC2_EDID_IRQ |= _BIT2;

                // Set a Polling Duration: 30ms
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FE69_DDC2_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FE69_DDC2_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
#endif
            }
            break;
#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
            if(GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                // Disable SCL Toggle IRQ
                MCU_FE72_DDC3_EDID_IRQ &= ~_BIT3;
                MCU_FE72_DDC3_EDID_IRQ |= _BIT2;

                // Set a Polling Duration: 30ms
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FE72_DDC3_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
            if(GET_D4_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                // Disable SCL Toggle IRQ
                MCU_FE7B_DDC4_EDID_IRQ &= ~_BIT3;
                MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;

                // Set a Polling Duration: 30ms
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FE7B_DDC4_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
            if(GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                // Disable SCL Toggle IRQ
                MCU_FE84_DDC5_EDID_IRQ &= ~_BIT3;
                MCU_FE84_DDC5_EDID_IRQ |= _BIT2;

                // Set a Polling Duration: 30ms
                for(ustemp = 0; ustemp < 1500; ustemp++)
                {
                    // delay 20us for IIC 100k
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);
                    Delay5us_EXINT(g_ucDelay5usN);

                    if((MCU_FE84_DDC5_EDID_IRQ & _BIT2) == _BIT2)
                    {
                        MCU_FE84_DDC5_EDID_IRQ |= _BIT2;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;
#endif

        default:

            break;
    }
}

#endif // End of #if(_HDMI_SUPPORT == _ON)

//--------------------------------------------------
// Description  : TMDS HPD Toggle Process
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSHPDToggleProc(void)
{
#if(_D0_TMDS_SUPPORT == _ON)
    if(GET_TMDS_RX0_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
    {
        ScalerTMDSHotPlugEvent(_D0_INPUT_PORT);
    }
#endif

#if(_D1_TMDS_SUPPORT == _ON)
    if(GET_TMDS_RX1_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
    {
        ScalerTMDSHotPlugEvent(_D1_INPUT_PORT);
    }
#endif

#if(_D2_TMDS_SUPPORT == _ON)
    if(GET_TMDS_RX2_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
    {
        ScalerTMDSHotPlugEvent(_D2_INPUT_PORT);
    }
#endif

#if(_D3_TMDS_SUPPORT == _ON)
    if(GET_TMDS_RX3_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
    {
        ScalerTMDSHotPlugEvent(_D3_INPUT_PORT);
    }
#endif

#if(_D4_TMDS_SUPPORT == _ON)
    if(GET_TMDS_RX4_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
    {
        ScalerTMDSHotPlugEvent(_D4_INPUT_PORT);
    }
#endif

#if(_D5_TMDS_SUPPORT == _ON)
    if(GET_TMDS_RX5_HPD_TRIGGER_EVENT() != _TMDS_HPD_NONE)
    {
        ScalerTMDSHotPlugEvent(_D5_INPUT_PORT);
    }
#endif
}
#endif // End of #if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_MHL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : MHL VBus Power Exist
// Input Value  : None
// Output Value : _TRUE : VBUS Power Exist
//--------------------------------------------------
bit ScalerSyncMHLVBusPowerExist(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
    if(PCB_GET_D0_MHL_VBUS_SWITCH() == _MHL_VBUS_ON)
    {
        return _TRUE;
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
    if(PCB_GET_D1_MHL_VBUS_SWITCH() == _MHL_VBUS_ON)
    {
        return _TRUE;
    }
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
    if(PCB_GET_D2_MHL_VBUS_SWITCH() == _MHL_VBUS_ON)
    {
        return _TRUE;
    }
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
    if(PCB_GET_D3_MHL_VBUS_SWITCH() == _MHL_VBUS_ON)
    {
        return _TRUE;
    }
#endif

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
    if(PCB_GET_D4_MHL_VBUS_SWITCH() == _MHL_VBUS_ON)
    {
        return _TRUE;
    }
#endif

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
    if(PCB_GET_D5_MHL_VBUS_SWITCH() == _MHL_VBUS_ON)
    {
        return _TRUE;
    }
#endif

    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : Process Required to be Performed for Active State
// Input Value  : Current Source Type
// Output Value : None
//--------------------------------------------------
void ScalerSyncActiveProc(BYTE ucSourceType)
{
    switch(ucSourceType)
    {
#if(_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            break;
#endif

#if(_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:
            break;
#endif

#if(_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:

            ScalerTMDSHdmiAVMuteProc();

            break;
#endif

#if(_DP_SUPPORT == _ON)
        case _SOURCE_DP:

            break;
#endif
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Sync reset Process for Mode Reset
// Input Value  : ucInputPort --> Input Port
// Output Value : None
//--------------------------------------------------
void ScalerSyncResetProc(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

#if(_DP_SUPPORT == _ON)
    ScalerDpResetProc();
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))

#if(_HDMI_SUPPORT == _ON)
    ScalerTMDSHdmiWatchDog((_HDMI_AVI_INFO_VARIATION_WD | _HDMI_AV_MUTE_WD), _DISABLE);
#endif

    ScalerTMDSResetProc();
#endif

#if(_FREESYNC_SUPPORT == _ON)
    CLR_FREESYNC_ENABLED();
#endif

#if((_DP_SUPPORT == _ON) && (_ULTRA_HDR_SUPPORT == _ON))
    ScalerSyncDpHDRReset();
#endif
}

//--------------------------------------------------
// Description  : Power Process for Interface
// Input Value  : Power Action
// Output Value : None
//--------------------------------------------------
void ScalerSyncPowerProc(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

#if(_ADC_SUPPORT == _ON)
            // ADC Bandgap Enable
            ScalerADCBandgap(_ON);
#endif

            // GDI Bandgap Enable
            ScalerGDIPhyBandgap(_ON);

#if(_DP_SUPPORT == _ON)
            ScalerDpPowerSwitch(enumPowerAction);
#endif

#if(_FREESYNC_SUPPORT == _ON)
            ScalerSyncFREESYNCTestPinEnable();
#endif

            if(enumPowerAction == _POWER_ACTION_PS_TO_NORMAL)
            {
#if(_DIGITAL_PORT_SUPPORT == _ON)
                ScalerSyncGDIPowerProc(enumPowerAction);
#endif
            }

#if(_URGENT_EVENT_CHECK_MODE == _ON)
            // Clear Urgent Event Occured Flag When System Flow Is Runing to Normal
            ScalerSyncClrUrgentEventFlg();
#endif

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_ADC_SUPPORT == _ON)
            // Power down ADC/APLL
            ScalerSyncAdcApllPowerDown();

            // ADC Bandgap Disable
            ScalerADCBandgap(_OFF);
#endif

#if(_DP_SUPPORT == _ON)
            ScalerDpPowerSwitch(enumPowerAction);
#else
            ScalerGDIPhyBandgap(_OFF);
#endif

#if(_DP_TX_SUPPORT == _ON)
            ScalerSyncDpTxPowerProc(enumPowerAction);
#endif

#if(_EMBEDDED_DP_TX_SUPPORT == _ON)
            ScalerSyncEmbeddedDpTxPowerProc(enumPowerAction);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
            ScalerSyncGDIPowerProc(enumPowerAction);
#endif

#if(_ADC_SUPPORT == _ON)
            // Schmitt trigger setting old mode in power saving.
            ScalerSetByte(P0_F4_HS_SCHMITT_TRIGGE_CTRL, 0xC2);

            // Disable Sync proc clock
            ScalerSetBit(P0_47_SYNC_SELECT, ~_BIT7, _BIT7);
#endif

            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_ADC_SUPPORT == _ON)
            // Power down ADC/APLL
            ScalerSyncAdcApllPowerDown();

            // ADC Bandgap Disable
            ScalerADCBandgap(_OFF);
#endif

#if(_MHL_SUPPORT == _ON)
            if(enumPowerAction == _POWER_ACTION_AC_ON_TO_OFF)
            {
                ScalerGDIPhyBandgap(_ON);
            }
#endif

#if(_DP_TX_SUPPORT == _ON)
            ScalerSyncDpTxPowerProc(enumPowerAction);
#endif

#if(_EMBEDDED_DP_TX_SUPPORT == _ON)
            ScalerSyncEmbeddedDpTxPowerProc(enumPowerAction);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
            ScalerSyncGDIPowerProc(enumPowerAction);
#endif

#if(_DP_SUPPORT == _ON)
            ScalerDpPowerSwitch(enumPowerAction);
#else
            ScalerGDIPhyBandgap(_OFF);
#endif

#if((_DP_SUPPORT != _ON) && (_DVI_SUPPORT != _ON))
            EX0 = 0;
#endif

#if(_VGA_SUPPORT == _ON)
            // Disable sync pulse detect
            ScalerSyncProcPulseDetectEnable(_DISABLE);
#endif

#if(_ADC_SUPPORT == _ON)
            // Schmitt trigger setting old mode in power saving.
            ScalerSetByte(P0_F4_HS_SCHMITT_TRIGGE_CTRL, 0x42);

            // Disable Sync proc clock
            ScalerSetBit(P0_47_SYNC_SELECT, ~_BIT7, _BIT7);
#endif

            break;

        case _POWER_ACTION_NORMAL_TO_FAKE_OFF:

#if(_DP_SUPPORT == _ON)
            ScalerDpPowerSwitch(enumPowerAction);
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Switch Between Interfaces
// Input Value  : Current Input Port, Target Source Type, Source Search Mode
// Output Value : None
//--------------------------------------------------
void ScalerSyncInterfaceSwitch(BYTE ucInputPort, BYTE ucPortType, BYTE ucSourceSearchDelayMode)
{
    ucSourceSearchDelayMode = ucSourceSearchDelayMode;
    ucPortType = ucPortType;

#if(_ADC_SUPPORT == _ON)
    if(ucPortType != _PORT_VGA)
    {
        ScalerSyncAdcApllPowerDown();
    }
#endif

#if((_DVI_SUPPORT == _ON) || (_HDMI_SUPPORT == _ON))
    if((ucPortType != _PORT_DVI) && (ucPortType != _PORT_HDMI) &&
       (ucPortType != _PORT_MHL) && (ucPortType != _PORT_DUAL_DVI))
    {
        ScalerTMDSFreqDetectDisable();
    }
#endif

#if(_DP_SUPPORT == _ON)
    ScalerDpFakeLinkTrainingSetting(ucInputPort);
#endif

    switch(ucInputPort)
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)

        case _A0_INPUT_PORT:
        case _A1_INPUT_PORT:
        case _A2_INPUT_PORT:

            if(ucInputPort == _A0_INPUT_PORT)
            {
                PCB_VGA_SWITCH_A0();
            }
            else if(ucInputPort == _A1_INPUT_PORT)
            {
                PCB_VGA_SWITCH_A1();
            }
            else if(ucInputPort == _A2_INPUT_PORT)
            {
                PCB_VGA_SWITCH_A2();
            }

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

            break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

#if(_DP_HDMI_COMPATIBLE_MODE == _OFF)
#if((_D0_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE)
            {
                SET_TMDS_RX0_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D0_INPUT_PORT);
            }
#endif
            if(GET_TMDS_RX0_TOGGLE_Z0_EVENT() == _TRUE)
            {
                SET_TMDS_RX0_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D0_INPUT_PORT);
            }

#else // Else of #if((_D0_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE))
            {
                SET_TMDS_RX0_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);
                ScalerTMDSHotPlugEvent(_D0_INPUT_PORT);
            }
#endif

#endif // End of #if((_D0_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
#endif // End of #if(_DP_HDMI_COMPATIBLE_MODE == _OFF)

            ScalerGDIPhyDigitalPhySwitch(_D0_INPUT_PORT);

            if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _FALSE)
            {
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)

#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D0_HDMI_5V_STATUS() == _TRUE))
                {
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                }
                else
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                }
#elif(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
                {
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D0_HDMI_5V_STATUS() == _TRUE))
                    {
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                        ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
                    }
                    else
                    {
                        ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                    }
                }
                else
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                }
#else
                ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
#endif

#else // Else of #if(_DP_HDMI_COMPATIBLE_MODE == _ON)

                ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
#endif
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

        case _D1_INPUT_PORT:

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

#if(_DP_HDMI_COMPATIBLE_MODE == _OFF)
#if((_D1_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE)
            {
                SET_TMDS_RX1_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D1_INPUT_PORT);
            }
#endif
            if(GET_TMDS_RX1_TOGGLE_Z0_EVENT() == _TRUE)
            {
                SET_TMDS_RX1_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D1_INPUT_PORT);
            }

#else // Else of #if((_D1_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE))
            {
                SET_TMDS_RX1_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);
                ScalerTMDSHotPlugEvent(_D1_INPUT_PORT);
            }
#endif

#endif // End of #if((_D1_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
#endif // End of #if(_DP_HDMI_COMPATIBLE_MODE == _OFF)

            ScalerGDIPhyDigitalPhySwitch(_D1_INPUT_PORT);

            if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _FALSE)
            {
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_HDMI_5V_STATUS() == _TRUE))
                {
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                }
                else
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                }
#elif(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
                if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
                {
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D1_HDMI_5V_STATUS() == _TRUE))
                    {
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
                    }
                    else
                    {
                        ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                    }
                }
                else
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                }
#else
                ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
#endif

#else // Else of #if(_DP_HDMI_COMPATIBLE_MODE == _ON)

                ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
#endif
            }

            break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)

        case _D2_INPUT_PORT:

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

                if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

#if(_DP_HDMI_COMPATIBLE_MODE == _OFF)
#if((_D2_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE)
            {
                SET_TMDS_RX2_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D2_INPUT_PORT);
            }
#endif
            if(GET_TMDS_RX2_TOGGLE_Z0_EVENT() == _TRUE)
            {
                SET_TMDS_RX2_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D2_INPUT_PORT);
            }

#else // Else of #if((_D2_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE))
            {
                SET_TMDS_RX2_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);
                ScalerTMDSHotPlugEvent(_D2_INPUT_PORT);
            }
#endif

#endif // End of #if((_D2_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
#endif // #if(_DP_HDMI_COMPATIBLE_MODE == _OFF)

            ScalerGDIPhyDigitalPhySwitch(_D2_INPUT_PORT);

            if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _FALSE)
            {
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)

#if(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
                if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D2_HDMI_5V_STATUS() == _TRUE))
                {
                    PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                }
                else
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                }
#elif(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
                if(GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE)
                {
                    if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_D2_HDMI_5V_STATUS() == _TRUE))
                    {
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_LOW);
                        ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D2_HOTPLUG(_D2_HOT_PLUG_HIGH);
                    }
                    else
                    {
                        ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                    }
                }
                else
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
                }
#else
                ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
#endif

#else // Else of #if(_DP_HDMI_COMPATIBLE_MODE == _ON)

                ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
#endif
            }

#if(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)
            if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE)
            {
                ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
            }
#endif
            break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)

        case _D3_INPUT_PORT:

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

#if((_D3_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE)
            {
                SET_TMDS_RX3_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D3_INPUT_PORT);
            }
#endif
            if(GET_TMDS_RX3_TOGGLE_Z0_EVENT() == _TRUE)
            {
                SET_TMDS_RX3_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D3_INPUT_PORT);
            }

#else // Else of #if((_D3_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE))
            {
                SET_TMDS_RX3_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);
                ScalerTMDSHotPlugEvent(_D3_INPUT_PORT);
            }
#endif

#endif // End of #if((_D3_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

            ScalerGDIPhyDigitalPhySwitch(_D3_INPUT_PORT);

            if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _FALSE)
            {
                ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
            }

#if(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)
            if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _FALSE)
            {
                ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
            }
#endif
            break;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)

        case _D4_INPUT_PORT:

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

#if((_D4_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
            if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _FALSE)
            {
                SET_TMDS_RX4_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D4_INPUT_PORT);
            }
#endif
            if(GET_TMDS_RX4_TOGGLE_Z0_EVENT() == _TRUE)
            {
                SET_TMDS_RX4_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D4_INPUT_PORT);
            }

#else // Else of #if((_D4_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D4() == _FALSE))
            {
                SET_TMDS_RX4_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);
                ScalerTMDSHotPlugEvent(_D4_INPUT_PORT);
            }
#endif

#endif // End of #if((_D4_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

            ScalerGDIPhyDigitalPhySwitch(_D4_INPUT_PORT);

            if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _FALSE)
            {
                ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
            }

#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)
            if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _FALSE)
            {
                ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
            }
#endif
            break;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)

        case _D5_INPUT_PORT:

            if(ucSourceSearchDelayMode != _SOURCE_SEARCH_POLLING_MODE)
            {
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D0() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D0_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D1() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D1_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                if(GET_DIGITAL_PORT_SWITCH_TO_D2() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D2_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D3() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D3_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                if(GET_DIGITAL_PORT_SWITCH_TO_D4() == _TRUE)
                {
                    ScalerGDIPhyPowerProc(_D4_INPUT_PORT, _POWER_ACTION_SWITCH_INTERFACE_TO_OFF);
                }
#endif
            }

#if((_D5_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
            if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _FALSE)
            {
                SET_TMDS_RX5_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D5_INPUT_PORT);
            }
#endif
            if(GET_TMDS_RX5_TOGGLE_Z0_EVENT() == _TRUE)
            {
                SET_TMDS_RX5_HPD_TRIGGER_EVENT(_TMDS_HPD_ACER);
                ScalerTMDSHotPlugEvent(_D5_INPUT_PORT);
            }

#else // Else of #if((_D5_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
            if((GET_HDMI_HOTPLUG_TOGGLE() == _TRUE) && (GET_DIGITAL_PORT_SWITCH_TO_D5() == _FALSE))
            {
                SET_TMDS_RX5_HPD_TRIGGER_EVENT(_TMDS_HPD_NORMAL);
                ScalerTMDSHotPlugEvent(_D5_INPUT_PORT);
            }
#endif

#endif // End of #if((_D5_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))

            ScalerGDIPhyDigitalPhySwitch(_D5_INPUT_PORT);

            if(GET_DIGITAL_PORT_SWITCH_TO_D5() == _FALSE)
            {
                ScalerGDIPhyPowerProc(_D5_INPUT_PORT, _POWER_ACTION_OFF_TO_NORMAL);
            }

            break;
#endif
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Set DDC channel Force nack
// Input Value  : bSelect --> _ON: force nack
// Output Value : NONE
//--------------------------------------------------
void ScalerSyncSetDdcForceNack(BYTE ucInputPort, bit bSelect)
{
    if(bSelect == _ON)
    {
        switch(ucInputPort)
        {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
            case _A0_INPUT_PORT:

#if(_HW_PC99_VGADDC2_SUPPORT == _ON)
                if(GET_A0_DDC_CHANNEL_SEL() == _VGA_DDC2)
                {
                    // ADC_DDC2 Force Nack
                    MCU_FD37_ADC_DDC2_EDID_IRQ |= _BIT5;
                }
                else
#endif
                {
                    // A0 DDC force Nack
                    MCU_FFE7_VGA_EDID_IRQ |= _BIT5;
                }
                break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC0 force nack
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT5;
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT5;
#elif(_D0_DDC_CHANNEL_SEL == _DDC2)
                    MCU_FE69_DDC2_EDID_IRQ |= _BIT5;
#endif
                }
                break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
                if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC1 force nack
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT5;
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT5;
#elif(_D1_DDC_CHANNEL_SEL == _DDC2)
                    MCU_FE69_DDC2_EDID_IRQ |= _BIT5;
#endif
                }
                break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
            case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
                if(GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC2 force nack
#if(_D2_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ |= _BIT5;
#elif(_D2_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ |= _BIT5;
#elif(_D2_DDC_CHANNEL_SEL == _DDC2)
                    MCU_FE69_DDC2_EDID_IRQ |= _BIT5;
#endif
                }
                break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
            case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
                if(GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC3 force nack
                    MCU_FE72_DDC3_EDID_IRQ |= _BIT5;
                }

                break;
#endif
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
            case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
                if(GET_D4_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC4 force nack
                    MCU_FE7B_DDC4_EDID_IRQ |= _BIT5;
                }

                break;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
            case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
                if(GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC5 force nack
                    MCU_FE84_DDC5_EDID_IRQ |= _BIT5;
                }

                break;
#endif
            default:

                break;
        }
    }
    else
    {
        switch(ucInputPort)
        {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
            case _A0_INPUT_PORT:

                // A0 DDC nack off
                MCU_FFE7_VGA_EDID_IRQ &= ~_BIT5;

#if(_HW_PC99_VGADDC2_SUPPORT == _ON)
                // ADC_DDC2 nack off
                MCU_FD37_ADC_DDC2_EDID_IRQ &= ~_BIT5;
#endif
                break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if(_D0_AUX_DDC_CHANNEL == _D0_AUX_MAP_DDC0_PIN)

                // Disable DDC0 Force Nack
                MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT5;

                // Enable Segment Control
                MCU_FF20_DDC0_DDC_CONTROL_2 |= _BIT2;

#elif(_D0_AUX_DDC_CHANNEL == _D0_AUX_MAP_DDC1_PIN)

                // Disable DDC1 Force Nack
                MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT5;

                // Disable Segment Control for Link Layer CTS
                MCU_FF2E_DDC1_DDC_CONTROL_2 |= _BIT2;

#elif(_D0_AUX_DDC_CHANNEL == _D0_AUX_MAP_DDC2_PIN)

                // Disable DDC2 Force Nack
                MCU_FE69_DDC2_EDID_IRQ &= ~_BIT5;

                // Disable Segment Control for Link Layer CTS
                MCU_FE66_DDC2_DDC_CONTROL_2 |= _BIT2;
#endif

#elif(_D0_TMDS_SUPPORT == _ON)

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC0 nack off
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT5;
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT5;
#elif(_D0_DDC_CHANNEL_SEL == _DDC2)
                    MCU_FE69_DDC2_EDID_IRQ &= ~_BIT5;
#endif
                }
#endif
                break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

#if(_D1_AUX_DDC_CHANNEL == _D1_AUX_MAP_DDC0_PIN)
                // Disable DDC0 Force Nack
                MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT5;

                // Enable Segment Control
                MCU_FF20_DDC0_DDC_CONTROL_2 |= _BIT2;

#elif(_D1_AUX_DDC_CHANNEL == _D1_AUX_MAP_DDC1_PIN)
                // Disable DDC1 Force Nack
                MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT5;

                // Disable Segment Control for Link Layer CTS
                MCU_FF2E_DDC1_DDC_CONTROL_2 |= _BIT2;

#elif(_D1_AUX_DDC_CHANNEL == _D1_AUX_MAP_DDC2_PIN)
                // Disable DDC2 Force Nack
                MCU_FE69_DDC2_EDID_IRQ &= ~_BIT5;

                // Disable Segment Control for Link Layer CTS
                MCU_FE66_DDC2_DDC_CONTROL_2 |= _BIT2;
#endif

#elif(_D1_TMDS_SUPPORT == _ON)

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
                if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC1 nack off
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT5;
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT5;
#elif(_D1_DDC_CHANNEL_SEL == _DDC2)
                    MCU_FE69_DDC2_EDID_IRQ &= ~_BIT5;
#endif
                }
#endif
                break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
            case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)

#if(_D2_AUX_DDC_CHANNEL == _D2_AUX_MAP_DDC0_PIN)

                // Disable DDC0 Force Nack
                MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT5;

                // Enable Segment Control
                MCU_FF20_DDC0_DDC_CONTROL_2 |= _BIT2;

#elif(_D2_AUX_DDC_CHANNEL == _D2_AUX_MAP_DDC1_PIN)

                // Disable DDC1 Force Nack
                MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT5;

                // Disable Segment Control for Link Layer CTS
                MCU_FF2E_DDC1_DDC_CONTROL_2 |= _BIT2;

#elif(_D2_AUX_DDC_CHANNEL == _D2_AUX_MAP_DDC2_PIN)

                // Disable DDC2 Force Nack
                MCU_FE69_DDC2_EDID_IRQ &= ~_BIT5;

                // Disable Segment Control for Link Layer CTS
                MCU_FE66_DDC2_DDC_CONTROL_2 |= _BIT2;
#endif

#elif(_D2_TMDS_SUPPORT == _ON)

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
                if(GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC2 nack off
#if(_D2_DDC_CHANNEL_SEL == _DDC0)
                    MCU_FFE4_DDC0_EDID_IRQ &= ~_BIT5;
#elif(_D2_DDC_CHANNEL_SEL == _DDC1)
                    MCU_FFE5_DDC1_EDID_IRQ &= ~_BIT5;
#elif(_D2_DDC_CHANNEL_SEL == _DDC2)
                    MCU_FE69_DDC2_EDID_IRQ &= ~_BIT5;
#endif
                }
#endif
                break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
            case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
                if(GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC3 nack off
                    MCU_FE72_DDC3_EDID_IRQ &= ~_BIT5;
                }

                break;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
            case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
                if(GET_D4_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC4 nack off
                    MCU_FE7B_DDC4_EDID_IRQ &= ~_BIT5;
                }

                break;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
            case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
                if(GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
                {
                    // DDC5 nack off
                    MCU_FE84_DDC5_EDID_IRQ &= ~_BIT5;
                }

                break;
#endif

            default:

                break;
        }
    }
}

//--------------------------------------------------
// Description  : Get DDC channel Force nack Status
// Input Value  : ucInputPort
// Output Value : _TRUE --> Force Nack State
//--------------------------------------------------
bit ScalerSyncGetDdcForceNackStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)

        case _A0_INPUT_PORT:

#if(_HW_PC99_VGADDC2_SUPPORT == _ON)
            if(GET_A0_DDC_CHANNEL_SEL() == _VGA_DDC2)
            {
                if((MCU_FD37_ADC_DDC2_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
            }
            else
#endif
            {
                if((MCU_FFE7_VGA_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
            }

            break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

            if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                // DDC0 force nack
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
                if((MCU_FFE4_DDC0_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#elif(_D0_DDC_CHANNEL_SEL == _DDC1)
                if((MCU_FFE5_DDC1_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#elif(_D0_DDC_CHANNEL_SEL == _DDC2)
                if((MCU_FE69_DDC2_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#endif
            }
            break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

            if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                // DDC1 force nack
#if(_D1_DDC_CHANNEL_SEL == _DDC0)
                if((MCU_FFE4_DDC0_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
                if((MCU_FFE5_DDC1_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#elif(_D1_DDC_CHANNEL_SEL == _DDC2)
                if((MCU_FE69_DDC2_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#endif
            }
            break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)

        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)

            if(GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                // DDC2 force nack
#if(_D2_DDC_CHANNEL_SEL == _DDC0)
                if((MCU_FFE4_DDC0_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#elif(_D2_DDC_CHANNEL_SEL == _DDC1)
                if((MCU_FFE5_DDC1_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#elif(_D2_DDC_CHANNEL_SEL == _DDC2)
                if((MCU_FE69_DDC2_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
#endif
            }
            break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)

        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)

            if(GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                if((MCU_FE72_DDC3_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
            }
            break;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)

        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)

            if(GET_D4_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                if((MCU_FE7B_DDC4_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
            }
            break;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)

        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)

            if(GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE)
#endif
            {
                if((MCU_FE84_DDC5_EDID_IRQ & _BIT5) == _BIT5)
                {
                    return _TRUE;
                }
            }
            break;
#endif

        default:
            break;
    }

    return _FALSE;
}

#if(((_D0_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF)) || ((_HDMI_SUPPORT == _ON) && (_TMDS_PAGE2_COMBO_EXIST == _ON)))
//--------------------------------------------------
// Description  : TMDS Rx0 Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx0HdmiVideoSetting(void)
{
    if(GET_HDMI_RX0_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Color Space Auto/ Pixel Repetition auto mode
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_51_PORT_PAGE2_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

        pData[0] = ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] == _AVI_COLOR_SPACE_00)
        {
            // Color Space RGB
            DebugMessageRx0("Get Color Space RGB", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_01)
        {
            // YCC422
            DebugMessageRx0("Get Color Space YUV422", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_11)
        {
            // YCC420
            DebugMessageRx0("Get Color Space YUV420", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
        }
        else
        {
            // YCC444
            DebugMessageRx0("Get Color Space YUV444", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
        }

        // Set Pixel Repetition
        switch(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION))
        {
            case _AVI_PIXEL_REPETITION_0:

                DebugMessageRx0("Get Pixel Repetition 0", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;

            case _AVI_PIXEL_REPETITION_1:

                DebugMessageRx0("Get Pixel Repetition 1", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_1);

                break;

            case _AVI_PIXEL_REPETITION_2:

                DebugMessageRx0("Get Pixel Repetition 2", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_2);

                break;

            case _AVI_PIXEL_REPETITION_3:

                DebugMessageRx0("Get Pixel Repetition 3", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_3);

                break;

            case _AVI_PIXEL_REPETITION_4:

                DebugMessageRx0("Get Pixel Repetition 4", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_4);

                break;

            case _AVI_PIXEL_REPETITION_5:

                DebugMessageRx0("Get Pixel Repetition 5", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_5);

                break;

            case _AVI_PIXEL_REPETITION_6:

                DebugMessageRx0("Get Pixel Repetition 6", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_6);

                break;

            case _AVI_PIXEL_REPETITION_7:

                DebugMessageRx0("Get Pixel Repetition 7", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_7);

                break;

            case _AVI_PIXEL_REPETITION_8:

                DebugMessageRx0("Get Pixel Repetition 8", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_8);

                break;

            case _AVI_PIXEL_REPETITION_9:

                DebugMessageRx0("Get Pixel Repetition 9", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_9);

                break;

            default:

                DebugMessageRx0("Get Pixel Repetition Error", 0x00);
                SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;
        }

        // Set Colorimetry
        ScalerSyncTMDSRx0HdmiColorimetrySetting();

        // Set Quantization
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
        ScalerSyncTMDSRx0HdmiQuantizationSetting();
#endif
    }
    else    // No Info Frame Received
    {
#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
        if(GET_TMDS_RX0_CLK_MODE() == _TMDS_MHL_PPMODE_PHY_SETTING)
        {
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

            // Manual Set Color Space to YCbCr422 and disable pixel repetition
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_51_PORT_PAGE2_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
        }
        else
#endif

        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

            // Manual Set Color Space to RGB and disable pixel repetition
            ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_51_PORT_PAGE2_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
        }

        // Disable down sampling
        ScalerSetDataPortBit(P2_C9_HDMI_AP, _P2_CA_PT_50_PORT_PAGE2_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        SET_TMDS_RX0_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
    }

    ScalerTMDSRx0SetPorchColor(GET_COLOR_SPACE());
}

//--------------------------------------------------
// Description  : TMDS Rx0 HDMI Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx0HdmiColorimetrySetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx0("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_00);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_01:

                DebugMessageRx0("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_01);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_10:

                DebugMessageRx0("Get Colorimetry YCC_ITUR_BT709", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_10);

                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx0("Get Colorimetry Extended", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_11);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx0HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx0("Get Colorimetry INTO_DEFAULT", 0x00);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_PREVALUE(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_PREVALUE())
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx0("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx0("Get Colorimetry Extended", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx0HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx0("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : TMDS Rx0 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx0HdmiColorimetryExtSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        // Get extended colorimetry
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        // Get extended colorimetry
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_000:

                DebugMessageRx0("Get Colorimetry EXT_YCC_XVYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_001:

                DebugMessageRx0("Get Colorimetry EXT_YCC_XVYCC709", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);

                break;

            case _AVI_COLORIMETRY_EXT_010:

                DebugMessageRx0("Get Colorimetry EXT_YCC_SYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_011:

                DebugMessageRx0("Get Colorimetry EXT_YCC_ADOBEYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_101:

                DebugMessageRx0("Get Colorimetry EXT_YCC_ITUR_BT2020_CL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx0("Get Colorimetry EXT_YCC_ITUR_BT2020_NCL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);

                break;

            default:

                DebugMessageRx0("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_100:

                DebugMessageRx0("Get Colorimetry EXT_RGB_ADOBERGB", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx0("Get Colorimetry EXT_RGB_ITUR_BT2020", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);

                break;

            default:

                DebugMessageRx0("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Rx0 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx0HdmiQuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        SET_DIGITAL_QUANTIZATION_PREVALUE(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION));

        switch(GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            case _AVI_YCC_QUANTIZATION_FULL:

                DebugMessageRx0("Get YCC FULL RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_YCC_QUANTIZATION_LIMITED:

                DebugMessageRx0("Get YCC LIMIT RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

                break;

            default:

                DebugMessageRx0("Get YCC RANGE Error", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
        {
            case _AVI_RGB_QUANTIZATION_LIMITED:

                DebugMessageRx0("Get RGB LIMIT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_LIMITED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_FULL:

                DebugMessageRx0("Get RGB FULL RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_DEFAULT:

                DebugMessageRx0("Get RGB DEFAULT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_DEFAULT);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_RESERVED:

                DebugMessageRx0("Get RGB RESERVED RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_RESERVED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

                break;

            default:

                DebugMessageRx0("Get RGB RANGE Error", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx0 HDMI ColorInfo Changed Detect
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncTMDSRx0HdmiColorInfoChanged(void)
{
    // Check Color Space
    if(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageRx0("Color Space Changed", 0x00);
        return _TRUE;
    }

    // Check Colorimetry
    if(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_PREVALUE())
    {
        DebugMessageRx0("Colorimetry Changed", 0x00);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
        {
            BYTE pucTemp[2];

            pucTemp[0] = ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY);

            pucTemp[1] = GET_DIGITAL_COLORIMETRY_PREVALUE();

            ScalerSyncTMDSRx0HdmiColorimetrySetting();

            if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
            {
                if(!(((pucTemp[0] == _AVI_COLORIMETRY_00) && (pucTemp[1] == _AVI_COLORIMETRY_01)) || ((pucTemp[0] == _AVI_COLORIMETRY_01) && (pucTemp[1] == _AVI_COLORIMETRY_00))))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
            else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
            {
                if((pucTemp[0] == _AVI_COLORIMETRY_11) || (pucTemp[1] == _AVI_COLORIMETRY_11))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            return _TRUE;
        }
    }
    else
    {
        if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
        {
            if(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
            {
                DebugMessageRx0("Ext Colorimetry Changed", 0x00);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
                {
                    BYTE pucTemp[2];

                    pucTemp[0] = ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    pucTemp[1] = GET_DIGITAL_COLORIMETRY_EXT_PREVALUE();

                    ScalerSyncTMDSRx0HdmiColorimetryExtSetting();

                    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
                    {
                        if(!(((pucTemp[0] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] == _AVI_COLORIMETRY_EXT_111)) || ((pucTemp[1] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] == _AVI_COLORIMETRY_EXT_111))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
                    {
                        if(!(((pucTemp[0] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] != _AVI_COLORIMETRY_EXT_110)) && ((pucTemp[1] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] != _AVI_COLORIMETRY_EXT_110))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                }
                else
                {
                    return _TRUE;
                }
            }
        }
    }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx0("YCC Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                BYTE pucTemp[2];

                pucTemp[0] = ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

                pucTemp[1] = GET_DIGITAL_QUANTIZATION_PREVALUE();

                ScalerSyncTMDSRx0HdmiQuantizationSetting();

                if((pucTemp[0] == _AVI_YCC_QUANTIZATION_LIMITED) || (pucTemp[1] == _AVI_YCC_QUANTIZATION_LIMITED))
                {
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        if(ScalerTMDSRx0HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx0("RGB Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                ScalerSyncTMDSRx0HdmiQuantizationSetting();

                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

    return _FALSE;
}
#endif

#if((_D1_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
//--------------------------------------------------
// Description  : TMDS Rx1 Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx1HdmiVideoSetting(void)
{
    if(GET_HDMI_RX1_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Color Space Auto/ Pixel Repetition auto mode
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE70)
        ScalerSetDataPortBit(P70_C9_HDMI_AP, _P70_CA_PT_51_PORT_PAGE70_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));
#else
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));
#endif

        pData[0] = ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] == _AVI_COLOR_SPACE_00)
        {
            // Color Space RGB
            DebugMessageRx1("Get Color Space RGB", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_01)
        {
            // YCC422
            DebugMessageRx1("Get Color Space YUV422", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_11)
        {
            // YCC420
            DebugMessageRx1("Get Color Space YUV420", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
        }
        else
        {
            // YCC444
            DebugMessageRx1("Get Color Space YUV444", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
        }

        // Set Pixel Repetition
        switch(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION))
        {
            case _AVI_PIXEL_REPETITION_0:

                DebugMessageRx1("Get Pixel Repetition 0", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;

            case _AVI_PIXEL_REPETITION_1:

                DebugMessageRx1("Get Pixel Repetition 1", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_1);

                break;

            case _AVI_PIXEL_REPETITION_2:

                DebugMessageRx1("Get Pixel Repetition 2", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_2);

                break;

            case _AVI_PIXEL_REPETITION_3:

                DebugMessageRx1("Get Pixel Repetition 3", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_3);

                break;

            case _AVI_PIXEL_REPETITION_4:

                DebugMessageRx1("Get Pixel Repetition 4", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_4);

                break;

            case _AVI_PIXEL_REPETITION_5:

                DebugMessageRx1("Get Pixel Repetition 5", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_5);

                break;

            case _AVI_PIXEL_REPETITION_6:

                DebugMessageRx1("Get Pixel Repetition 6", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_6);

                break;

            case _AVI_PIXEL_REPETITION_7:

                DebugMessageRx1("Get Pixel Repetition 7", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_7);

                break;

            case _AVI_PIXEL_REPETITION_8:

                DebugMessageRx1("Get Pixel Repetition 8", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_8);

                break;

            case _AVI_PIXEL_REPETITION_9:

                DebugMessageRx1("Get Pixel Repetition 9", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_9);

                break;

            default:

                DebugMessageRx1("Get Pixel Repetition Error", 0x00);
                SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;
        }

        // Set Colorimetry
        ScalerSyncTMDSRx1HdmiColorimetrySetting();

        // Set Quantization
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
        ScalerSyncTMDSRx1HdmiQuantizationSetting();
#endif
    }
    else    // No Info Frame Received
    {
#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
        if(GET_TMDS_RX1_CLK_MODE() == _TMDS_MHL_PPMODE_PHY_SETTING)
        {
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

            // Manual Set Color Space to YCbCr422 and disable pixel repetition
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE70)
            ScalerSetDataPortBit(P70_C9_HDMI_AP, _P70_CA_PT_51_PORT_PAGE70_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
#else
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
#endif
        }
        else
#endif

        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

            // Manual Set Color Space to RGB and disable pixel repetition
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE70)
            ScalerSetDataPortBit(P70_C9_HDMI_AP, _P70_CA_PT_51_PORT_PAGE70_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
#else
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
#endif
        }

        // Disable down sampling
#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE70)
        ScalerSetDataPortBit(P70_C9_HDMI_AP, _P70_CA_PT_50_PORT_PAGE70_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#else
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_50_PORT_PAGE71_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
#endif

        SET_TMDS_RX1_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
    }

    ScalerTMDSRx1SetPorchColor(GET_COLOR_SPACE());
}

//--------------------------------------------------
// Description  : TMDS Rx1 HDMI Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx1HdmiColorimetrySetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx1("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_00);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_01:

                DebugMessageRx1("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_01);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_10:

                DebugMessageRx1("Get Colorimetry 709", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_10);

                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx1("Get Colorimetry Extended", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_11);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx1HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx1("Get Colorimetry INTO_DEFAULT", 0x00);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_PREVALUE(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_PREVALUE())
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx1("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx1("Get Colorimetry Extended", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx1HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx1("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : TMDS Rx1 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx1HdmiColorimetryExtSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        // Get extended colorimetry
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        // Get extended colorimetry
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_000:

                DebugMessageRx1("Get Colorimetry EXT_YCC_XVYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_001:

                DebugMessageRx1("Get Colorimetry EXT_YCC_XVYCC709", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);

                break;

            case _AVI_COLORIMETRY_EXT_010:

                DebugMessageRx1("Get Colorimetry EXT_YCC_SYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_011:

                DebugMessageRx1("Get Colorimetry EXT_YCC_ADOBEYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_101:

                DebugMessageRx1("Get Colorimetry EXT_YCC_ITUR_BT2020_CL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx1("Get Colorimetry EXT_YCC_ITUR_BT2020_NCL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);

                break;

            default:

                DebugMessageRx1("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_100:

                DebugMessageRx1("Get Colorimetry EXT_RGB_ADOBERGB", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx1("Get Colorimetry EXT_RGB_ITUR_BT2020", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);

                break;

            default:

                DebugMessageRx1("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Rx1 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx1HdmiQuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        SET_DIGITAL_QUANTIZATION_PREVALUE(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION));

        switch(GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            case _AVI_YCC_QUANTIZATION_FULL:

                DebugMessageRx1("Get YCC FULL RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_YCC_QUANTIZATION_LIMITED:

                DebugMessageRx1("Get YCC LIMIT RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

                break;

            default:

                DebugMessageRx1("Get YCC RANGE Error", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
        {
            case _AVI_RGB_QUANTIZATION_LIMITED:

                DebugMessageRx1("Get RGB LIMIT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_LIMITED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_FULL:

                DebugMessageRx1("Get RGB FULL RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_DEFAULT:

                DebugMessageRx1("Get RGB DEFAULT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_DEFAULT);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_RESERVED:

                DebugMessageRx1("Get RGB RESERVED RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_RESERVED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

                break;

            default:

                DebugMessageRx1("Get RGB RANGE Error", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx1 HDMI ColorInfo Changed Detect
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncTMDSRx1HdmiColorInfoChanged(void)
{
    // Check Color Space
    if(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageRx1("Color Space Changed", 0x00);
        return _TRUE;
    }

    // Check Colorimetry
    if(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_PREVALUE())
    {
        DebugMessageRx1("Colorimetry Changed", 0x00);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
        {
            BYTE pucTemp[2];

            pucTemp[0] = ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY);

            pucTemp[1] = GET_DIGITAL_COLORIMETRY_PREVALUE();

            ScalerSyncTMDSRx1HdmiColorimetrySetting();

            if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
            {
                if(!(((pucTemp[0] == _AVI_COLORIMETRY_00) && (pucTemp[1] == _AVI_COLORIMETRY_01)) || ((pucTemp[0] == _AVI_COLORIMETRY_01) && (pucTemp[1] == _AVI_COLORIMETRY_00))))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
            else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
            {
                if((pucTemp[0] == _AVI_COLORIMETRY_11) || (pucTemp[1] == _AVI_COLORIMETRY_11))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            return _TRUE;
        }
    }
    else
    {
        if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
        {
            if(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
            {
                DebugMessageRx1("Ext Colorimetry Changed", 0x00);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
                {
                    BYTE pucTemp[2];

                    pucTemp[0] = ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    pucTemp[1] = GET_DIGITAL_COLORIMETRY_EXT_PREVALUE();

                    ScalerSyncTMDSRx1HdmiColorimetryExtSetting();

                    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
                    {
                        if(!(((pucTemp[0] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] == _AVI_COLORIMETRY_EXT_111)) || ((pucTemp[1] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] == _AVI_COLORIMETRY_EXT_111))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
                    {
                        if(!(((pucTemp[0] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] != _AVI_COLORIMETRY_EXT_110)) && ((pucTemp[1] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] != _AVI_COLORIMETRY_EXT_110))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                }
                else
                {
                    return _TRUE;
                }
            }
        }
    }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx1("YCC Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                BYTE pucTemp[2];

                pucTemp[0] = ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

                pucTemp[1] = GET_DIGITAL_QUANTIZATION_PREVALUE();

                ScalerSyncTMDSRx1HdmiQuantizationSetting();

                if((pucTemp[0] == _AVI_YCC_QUANTIZATION_LIMITED) || (pucTemp[1] == _AVI_YCC_QUANTIZATION_LIMITED))
                {
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        if(ScalerTMDSRx1HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx1("RGB Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                ScalerSyncTMDSRx1HdmiQuantizationSetting();

                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

    return _FALSE;
}
#endif

#if((_D2_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
#if(_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT)
//--------------------------------------------------
// Description  : TMDS Rx0 Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx2HdmiVideoSetting(void)
{
    if(GET_HDMI_RX2_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Color Space Auto/ Pixel Repetition auto mode
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

        pData[0] = ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] == _AVI_COLOR_SPACE_00)
        {
            // Color Space RGB
            DebugMessageRx2("Get Color Space RGB", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_01)
        {
            // YCC422
            DebugMessageRx2("Get Color Space YUV422", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_11)
        {
            // YCC420
            DebugMessageRx2("Get Color Space YUV420", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
        }
        else
        {
            // YCC444
            DebugMessageRx2("Get Color Space YUV444", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
        }

        // Set Pixel Repetition
        switch(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION))
        {
            case _AVI_PIXEL_REPETITION_0:

                DebugMessageRx2("Get Pixel Repetition 0", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;

            case _AVI_PIXEL_REPETITION_1:

                DebugMessageRx2("Get Pixel Repetition 1", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_1);

                break;

            case _AVI_PIXEL_REPETITION_2:

                DebugMessageRx2("Get Pixel Repetition 2", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_2);

                break;

            case _AVI_PIXEL_REPETITION_3:

                DebugMessageRx2("Get Pixel Repetition 3", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_3);

                break;

            case _AVI_PIXEL_REPETITION_4:

                DebugMessageRx2("Get Pixel Repetition 4", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_4);

                break;

            case _AVI_PIXEL_REPETITION_5:

                DebugMessageRx2("Get Pixel Repetition 5", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_5);

                break;

            case _AVI_PIXEL_REPETITION_6:

                DebugMessageRx2("Get Pixel Repetition 6", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_6);

                break;

            case _AVI_PIXEL_REPETITION_7:

                DebugMessageRx2("Get Pixel Repetition 7", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_7);

                break;

            case _AVI_PIXEL_REPETITION_8:

                DebugMessageRx2("Get Pixel Repetition 8", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_8);

                break;

            case _AVI_PIXEL_REPETITION_9:

                DebugMessageRx2("Get Pixel Repetition 9", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_9);

                break;

            default:

                DebugMessageRx2("Get Pixel Repetition Error", 0x00);
                SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;
        }

        // Set Colorimetry
        ScalerSyncTMDSRx2HdmiColorimetrySetting();

        // Set Quantization
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
        ScalerSyncTMDSRx2HdmiQuantizationSetting();
#endif
    }
    else    // No Info Frame Received
    {
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
        if(GET_TMDS_RX2_CLK_MODE() == _TMDS_MHL_PPMODE_PHY_SETTING)
        {
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

            // Manual Set Color Space to YCbCr422 and disable pixel repetition
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
        }
        else
#endif

        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

            // Manual Set Color Space to RGB and disable pixel repetition
            ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_51_PORT_PAGE71_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
        }

        // Disable down sampling
        ScalerSetDataPortBit(P71_C9_HDMI_AP, _P71_CA_PT_50_PORT_PAGE71_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        SET_TMDS_RX2_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
    }

    ScalerTMDSRx2SetPorchColor(GET_COLOR_SPACE());
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx2 HDMI Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx2HdmiColorimetrySetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx2("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_00);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_01:

                DebugMessageRx2("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_01);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_10:

                DebugMessageRx2("Get Colorimetry 709", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_10);

                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx2("Get Colorimetry Extended", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_11);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx2HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx2("Get Colorimetry INTO_DEFAULT", 0x00);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_PREVALUE(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_PREVALUE())
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx2("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx2("Get Colorimetry Extended", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx2HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx2("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : TMDS Rx2 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx2HdmiColorimetryExtSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        // Get extended colorimetry
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        // Get extended colorimetry
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_000:

                DebugMessageRx2("Get Colorimetry EXT_YCC_XVYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_001:

                DebugMessageRx2("Get Colorimetry EXT_YCC_XVYCC709", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);

                break;

            case _AVI_COLORIMETRY_EXT_010:

                DebugMessageRx2("Get Colorimetry EXT_YCC_SYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_011:

                DebugMessageRx2("Get Colorimetry EXT_YCC_ADOBEYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_101:

                DebugMessageRx2("Get Colorimetry EXT_YCC_ITUR_BT2020_CL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx2("Get Colorimetry EXT_YCC_ITUR_BT2020_NCL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);

                break;

            default:

                DebugMessageRx2("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_100:

                DebugMessageRx2("Get Colorimetry EXT_RGB_ADOBERGB", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx2("Get Colorimetry EXT_RGB_ITUR_BT2020", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);

                break;

            default:

                DebugMessageRx2("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Rx2 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx2HdmiQuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        SET_DIGITAL_QUANTIZATION_PREVALUE(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION));

        switch(GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            case _AVI_YCC_QUANTIZATION_FULL:

                DebugMessageRx2("Get YCC FULL RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_YCC_QUANTIZATION_LIMITED:

                DebugMessageRx2("Get YCC LIMIT RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

                break;

            default:

                DebugMessageRx2("Get YCC RANGE Error", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
        {
            case _AVI_RGB_QUANTIZATION_LIMITED:

                DebugMessageRx2("Get RGB LIMIT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_LIMITED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_FULL:

                DebugMessageRx2("Get RGB FULL RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_DEFAULT:

                DebugMessageRx2("Get RGB DEFAULT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_DEFAULT);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_RESERVED:

                DebugMessageRx2("Get RGB RESERVED RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_RESERVED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

                break;

            default:

                DebugMessageRx2("Get RGB RANGE Error", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx2 HDMI ColorInfo Changed Detect
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncTMDSRx2HdmiColorInfoChanged(void)
{
    // Check Color Space
    if(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageRx2("Color Space Changed", 0x00);
        return _TRUE;
    }

    // Check Colorimetry
    if(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_PREVALUE())
    {
        DebugMessageRx2("Colorimetry Changed", 0x00);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
        {
            BYTE pucTemp[2];

            pucTemp[0] = ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY);

            pucTemp[1] = GET_DIGITAL_COLORIMETRY_PREVALUE();

            ScalerSyncTMDSRx2HdmiColorimetrySetting();

            if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
            {
                if(!(((pucTemp[0] == _AVI_COLORIMETRY_00) && (pucTemp[1] == _AVI_COLORIMETRY_01)) || ((pucTemp[0] == _AVI_COLORIMETRY_01) && (pucTemp[1] == _AVI_COLORIMETRY_00))))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
            else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
            {
                if((pucTemp[0] == _AVI_COLORIMETRY_11) || (pucTemp[1] == _AVI_COLORIMETRY_11))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            return _TRUE;
        }
    }
    else
    {
        if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
        {
            if(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
            {
                DebugMessageRx2("Ext Colorimetry Changed", 0x00);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
                {
                    BYTE pucTemp[2];

                    pucTemp[0] = ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    pucTemp[1] = GET_DIGITAL_COLORIMETRY_EXT_PREVALUE();

                    ScalerSyncTMDSRx2HdmiColorimetryExtSetting();

                    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
                    {
                        if(!(((pucTemp[0] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] == _AVI_COLORIMETRY_EXT_111)) || ((pucTemp[1] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] == _AVI_COLORIMETRY_EXT_111))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
                    {
                        if(!(((pucTemp[0] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] != _AVI_COLORIMETRY_EXT_110)) && ((pucTemp[1] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] != _AVI_COLORIMETRY_EXT_110))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                }
                else
                {
                    return _TRUE;
                }
            }
        }
    }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx2("YCC Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                BYTE pucTemp[2];

                pucTemp[0] = ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

                pucTemp[1] = GET_DIGITAL_QUANTIZATION_PREVALUE();

                ScalerSyncTMDSRx2HdmiQuantizationSetting();

                if((pucTemp[0] == _AVI_YCC_QUANTIZATION_LIMITED) || (pucTemp[1] == _AVI_YCC_QUANTIZATION_LIMITED))
                {
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        if(ScalerTMDSRx2HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx2("RGB Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                ScalerSyncTMDSRx2HdmiQuantizationSetting();

                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

    return _FALSE;
}
#endif

#if((_D3_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
#if(_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT)
//--------------------------------------------------
// Description  : TMDS Rx0 Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx3HdmiVideoSetting(void)
{
    if(GET_HDMI_RX3_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Color Space Auto/ Pixel Repetition auto mode
        ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

        pData[0] = ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] == _AVI_COLOR_SPACE_00)
        {
            // Color Space RGB
            DebugMessageRx3("Get Color Space RGB", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_01)
        {
            // YCC422
            DebugMessageRx3("Get Color Space YUV422", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_11)
        {
            // YCC420
            DebugMessageRx3("Get Color Space YUV420", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
        }
        else
        {
            // YCC444
            DebugMessageRx3("Get Color Space YUV444", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
        }

        // Set Pixel Repetition
        switch(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION))
        {
            case _AVI_PIXEL_REPETITION_0:

                DebugMessageRx3("Get Pixel Repetition 0", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;

            case _AVI_PIXEL_REPETITION_1:

                DebugMessageRx3("Get Pixel Repetition 1", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_1);

                break;

            case _AVI_PIXEL_REPETITION_2:

                DebugMessageRx3("Get Pixel Repetition 2", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_2);

                break;

            case _AVI_PIXEL_REPETITION_3:

                DebugMessageRx3("Get Pixel Repetition 3", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_3);

                break;

            case _AVI_PIXEL_REPETITION_4:

                DebugMessageRx3("Get Pixel Repetition 4", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_4);

                break;

            case _AVI_PIXEL_REPETITION_5:

                DebugMessageRx3("Get Pixel Repetition 5", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_5);

                break;

            case _AVI_PIXEL_REPETITION_6:

                DebugMessageRx3("Get Pixel Repetition 6", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_6);

                break;

            case _AVI_PIXEL_REPETITION_7:

                DebugMessageRx3("Get Pixel Repetition 7", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_7);

                break;

            case _AVI_PIXEL_REPETITION_8:

                DebugMessageRx3("Get Pixel Repetition 8", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_8);

                break;

            case _AVI_PIXEL_REPETITION_9:

                DebugMessageRx3("Get Pixel Repetition 9", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_9);

                break;

            default:

                DebugMessageRx3("Get Pixel Repetition Error", 0x00);
                SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;
        }

        // Set Colorimetry
        ScalerSyncTMDSRx3HdmiColorimetrySetting();

        // Set Quantization
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
        ScalerSyncTMDSRx3HdmiQuantizationSetting();
#endif
    }
    else    // No Info Frame Received
    {
#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
        if(GET_TMDS_RX3_CLK_MODE() == _TMDS_MHL_PPMODE_PHY_SETTING)
        {
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

            // Manual Set Color Space to YCbCr422 and disable pixel repetition
            ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
        }
        else
#endif

        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

            // Manual Set Color Space to RGB and disable pixel repetition
            ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_51_PORT_PAGE72_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
        }

        // Disable down sampling
        ScalerSetDataPortBit(P72_C9_HDMI_AP, _P72_CA_PT_50_PORT_PAGE72_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        SET_TMDS_RX3_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
    }

    ScalerTMDSRx3SetPorchColor(GET_COLOR_SPACE());
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx3 HDMI Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx3HdmiColorimetrySetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx3("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_00);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_01:

                DebugMessageRx3("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_01);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_10:

                DebugMessageRx3("Get Colorimetry 709", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_10);

                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx3("Get Colorimetry Extended", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_11);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx3HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx3("Get Colorimetry INTO_DEFAULT", 0x00);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_PREVALUE(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_PREVALUE())
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx3("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx3("Get Colorimetry Extended", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx3HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx3("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : TMDS Rx3 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx3HdmiColorimetryExtSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        // Get extended colorimetry
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        // Get extended colorimetry
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_000:

                DebugMessageRx3("Get Colorimetry EXT_YCC_XVYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_001:

                DebugMessageRx3("Get Colorimetry EXT_YCC_XVYCC709", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);

                break;

            case _AVI_COLORIMETRY_EXT_010:

                DebugMessageRx3("Get Colorimetry EXT_YCC_SYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_011:

                DebugMessageRx3("Get Colorimetry EXT_YCC_ADOBEYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_101:

                DebugMessageRx3("Get Colorimetry EXT_YCC_ITUR_BT2020_CL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx3("Get Colorimetry EXT_YCC_ITUR_BT2020_NCL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);

                break;

            default:

                DebugMessageRx3("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_100:

                DebugMessageRx3("Get Colorimetry EXT_RGB_ADOBERGB", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx3("Get Colorimetry EXT_RGB_ITUR_BT2020", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);

                break;

            default:

                DebugMessageRx3("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Rx3 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx3HdmiQuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        SET_DIGITAL_QUANTIZATION_PREVALUE(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION));

        switch(GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            case _AVI_YCC_QUANTIZATION_FULL:

                DebugMessageRx3("Get YCC FULL RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_YCC_QUANTIZATION_LIMITED:

                DebugMessageRx3("Get YCC LIMIT RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

                break;

            default:

                DebugMessageRx3("Get YCC RANGE Error", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
        {
            case _AVI_RGB_QUANTIZATION_LIMITED:

                DebugMessageRx3("Get RGB LIMIT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_LIMITED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_FULL:

                DebugMessageRx3("Get RGB FULL RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_DEFAULT:

                DebugMessageRx3("Get RGB DEFAULT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_DEFAULT);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_RESERVED:

                DebugMessageRx3("Get RGB RESERVED RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_RESERVED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

                break;

            default:

                DebugMessageRx3("Get RGB RANGE Error", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx3 HDMI ColorInfo Changed Detect
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncTMDSRx3HdmiColorInfoChanged(void)
{
    // Check Color Space
    if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageRx3("Color Space Changed", 0x00);
        return _TRUE;
    }

    // Check Colorimetry
    if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_PREVALUE())
    {
        DebugMessageRx3("Colorimetry Changed", 0x00);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
        {
            BYTE pucTemp[2];

            pucTemp[0] = ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY);

            pucTemp[1] = GET_DIGITAL_COLORIMETRY_PREVALUE();

            ScalerSyncTMDSRx3HdmiColorimetrySetting();

            if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
            {
                if(!(((pucTemp[0] == _AVI_COLORIMETRY_00) && (pucTemp[1] == _AVI_COLORIMETRY_01)) || ((pucTemp[0] == _AVI_COLORIMETRY_01) && (pucTemp[1] == _AVI_COLORIMETRY_00))))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
            else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
            {
                if((pucTemp[0] == _AVI_COLORIMETRY_11) || (pucTemp[1] == _AVI_COLORIMETRY_11))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            return _TRUE;
        }
    }
    else
    {
        if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
        {
            if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
            {
                DebugMessageRx3("Ext Colorimetry Changed", 0x00);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
                {
                    BYTE pucTemp[2];

                    pucTemp[0] = ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    pucTemp[1] = GET_DIGITAL_COLORIMETRY_EXT_PREVALUE();

                    ScalerSyncTMDSRx3HdmiColorimetryExtSetting();

                    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
                    {
                        if(!(((pucTemp[0] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] == _AVI_COLORIMETRY_EXT_111)) || ((pucTemp[1] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] == _AVI_COLORIMETRY_EXT_111))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
                    {
                        if(!(((pucTemp[0] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] != _AVI_COLORIMETRY_EXT_110)) && ((pucTemp[1] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] != _AVI_COLORIMETRY_EXT_110))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                }
                else
                {
                    return _TRUE;
                }
            }
        }
    }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx3("YCC Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                BYTE pucTemp[2];

                pucTemp[0] = ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

                pucTemp[1] = GET_DIGITAL_QUANTIZATION_PREVALUE();

                ScalerSyncTMDSRx3HdmiQuantizationSetting();

                if((pucTemp[0] == _AVI_YCC_QUANTIZATION_LIMITED) || (pucTemp[1] == _AVI_YCC_QUANTIZATION_LIMITED))
                {
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        if(ScalerTMDSRx3HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx3("RGB Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                ScalerSyncTMDSRx3HdmiQuantizationSetting();

                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

    return _FALSE;
}
#endif

#if((_D4_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
#if(_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT)
//--------------------------------------------------
// Description  : TMDS Rx0 Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx4HdmiVideoSetting(void)
{
    if(GET_HDMI_RX4_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Color Space Auto/ Pixel Repetition auto mode
        ScalerSetDataPortBit(P73_C9_HDMI_AP, _P73_CA_PT_51_PORT_PAGE73_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

        pData[0] = ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] == _AVI_COLOR_SPACE_00)
        {
            // Color Space RGB
            DebugMessageRx4("Get Color Space RGB", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_01)
        {
            // YCC422
            DebugMessageRx4("Get Color Space YUV422", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_11)
        {
            // YCC420
            DebugMessageRx4("Get Color Space YUV420", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
        }
        else
        {
            // YCC444
            DebugMessageRx4("Get Color Space YUV444", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
        }

        // Set Pixel Repetition
        switch(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION))
        {
            case _AVI_PIXEL_REPETITION_0:

                DebugMessageRx4("Get Pixel Repetition 0", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;

            case _AVI_PIXEL_REPETITION_1:

                DebugMessageRx4("Get Pixel Repetition 1", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_1);

                break;

            case _AVI_PIXEL_REPETITION_2:

                DebugMessageRx4("Get Pixel Repetition 2", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_2);

                break;

            case _AVI_PIXEL_REPETITION_3:

                DebugMessageRx4("Get Pixel Repetition 3", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_3);

                break;

            case _AVI_PIXEL_REPETITION_4:

                DebugMessageRx4("Get Pixel Repetition 4", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_4);

                break;

            case _AVI_PIXEL_REPETITION_5:

                DebugMessageRx4("Get Pixel Repetition 5", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_5);

                break;

            case _AVI_PIXEL_REPETITION_6:

                DebugMessageRx4("Get Pixel Repetition 6", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_6);

                break;

            case _AVI_PIXEL_REPETITION_7:

                DebugMessageRx4("Get Pixel Repetition 7", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_7);

                break;

            case _AVI_PIXEL_REPETITION_8:

                DebugMessageRx4("Get Pixel Repetition 8", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_8);

                break;

            case _AVI_PIXEL_REPETITION_9:

                DebugMessageRx4("Get Pixel Repetition 9", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_9);

                break;

            default:

                DebugMessageRx4("Get Pixel Repetition Error", 0x00);
                SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;
        }

        // Set Colorimetry
        ScalerSyncTMDSRx4HdmiColorimetrySetting();

        // Set Quantization
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
        ScalerSyncTMDSRx4HdmiQuantizationSetting();
#endif
    }
    else    // No Info Frame Received
    {
#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
        if(GET_TMDS_RX4_CLK_MODE() == _TMDS_MHL_PPMODE_PHY_SETTING)
        {
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

            // Manual Set Color Space to YCbCr422 and disable pixel repetition
            ScalerSetDataPortBit(P73_C9_HDMI_AP, _P73_CA_PT_51_PORT_PAGE73_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
        }
        else
#endif

        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

            // Manual Set Color Space to RGB and disable pixel repetition
            ScalerSetDataPortBit(P73_C9_HDMI_AP, _P73_CA_PT_51_PORT_PAGE73_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
        }

        // Disable down sampling
        ScalerSetDataPortBit(P73_C9_HDMI_AP, _P73_CA_PT_50_PORT_PAGE73_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        SET_TMDS_RX4_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
    }

    ScalerTMDSRx4SetPorchColor(GET_COLOR_SPACE());
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx4 HDMI Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx4HdmiColorimetrySetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx4("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_00);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_01:

                DebugMessageRx4("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_01);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_10:

                DebugMessageRx4("Get Colorimetry 709", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_10);

                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx4("Get Colorimetry Extended", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_11);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx4HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx4("Get Colorimetry INTO_DEFAULT", 0x00);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_PREVALUE(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_PREVALUE())
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx4("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx4("Get Colorimetry Extended", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx4HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx4("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : TMDS Rx4 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx4HdmiColorimetryExtSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        // Get extended colorimetry
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        // Get extended colorimetry
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_000:

                DebugMessageRx4("Get Colorimetry EXT_YCC_XVYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_001:

                DebugMessageRx4("Get Colorimetry EXT_YCC_XVYCC709", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);

                break;

            case _AVI_COLORIMETRY_EXT_010:

                DebugMessageRx4("Get Colorimetry EXT_YCC_SYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_011:

                DebugMessageRx4("Get Colorimetry EXT_YCC_ADOBEYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_101:

                DebugMessageRx4("Get Colorimetry EXT_YCC_ITUR_BT2020_CL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx4("Get Colorimetry EXT_YCC_ITUR_BT2020_NCL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);

                break;

            default:

                DebugMessageRx4("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_100:

                DebugMessageRx4("Get Colorimetry EXT_RGB_ADOBERGB", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx4("Get Colorimetry EXT_RGB_ITUR_BT2020", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);

                break;

            default:

                DebugMessageRx4("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Rx4 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx4HdmiQuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        SET_DIGITAL_QUANTIZATION_PREVALUE(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION));

        switch(GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            case _AVI_YCC_QUANTIZATION_FULL:

                DebugMessageRx4("Get YCC FULL RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_YCC_QUANTIZATION_LIMITED:

                DebugMessageRx4("Get YCC LIMIT RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

                break;

            default:

                DebugMessageRx4("Get YCC RANGE Error", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
        {
            case _AVI_RGB_QUANTIZATION_LIMITED:

                DebugMessageRx4("Get RGB LIMIT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_LIMITED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_FULL:

                DebugMessageRx4("Get RGB FULL RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_DEFAULT:

                DebugMessageRx4("Get RGB DEFAULT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_DEFAULT);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_RESERVED:

                DebugMessageRx4("Get RGB RESERVED RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_RESERVED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

                break;

            default:

                DebugMessageRx4("Get RGB RANGE Error", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx4 HDMI ColorInfo Changed Detect
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncTMDSRx4HdmiColorInfoChanged(void)
{
    // Check Color Space
    if(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageRx4("Color Space Changed", 0x00);
        return _TRUE;
    }

    // Check Colorimetry
    if(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_PREVALUE())
    {
        DebugMessageRx4("Colorimetry Changed", 0x00);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
        {
            BYTE pucTemp[2];

            pucTemp[0] = ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY);

            pucTemp[1] = GET_DIGITAL_COLORIMETRY_PREVALUE();

            ScalerSyncTMDSRx4HdmiColorimetrySetting();

            if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
            {
                if(!(((pucTemp[0] == _AVI_COLORIMETRY_00) && (pucTemp[1] == _AVI_COLORIMETRY_01)) || ((pucTemp[0] == _AVI_COLORIMETRY_01) && (pucTemp[1] == _AVI_COLORIMETRY_00))))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
            else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
            {
                if((pucTemp[0] == _AVI_COLORIMETRY_11) || (pucTemp[1] == _AVI_COLORIMETRY_11))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            return _TRUE;
        }
    }
    else
    {
        if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
        {
            if(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
            {
                DebugMessageRx4("Ext Colorimetry Changed", 0x00);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
                {
                    BYTE pucTemp[2];

                    pucTemp[0] = ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    pucTemp[1] = GET_DIGITAL_COLORIMETRY_EXT_PREVALUE();

                    ScalerSyncTMDSRx4HdmiColorimetryExtSetting();

                    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
                    {
                        if(!(((pucTemp[0] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] == _AVI_COLORIMETRY_EXT_111)) || ((pucTemp[1] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] == _AVI_COLORIMETRY_EXT_111))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
                    {
                        if(!(((pucTemp[0] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] != _AVI_COLORIMETRY_EXT_110)) && ((pucTemp[1] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] != _AVI_COLORIMETRY_EXT_110))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                }
                else
                {
                    return _TRUE;
                }
            }
        }
    }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx4("YCC Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                BYTE pucTemp[2];

                pucTemp[0] = ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

                pucTemp[1] = GET_DIGITAL_QUANTIZATION_PREVALUE();

                ScalerSyncTMDSRx4HdmiQuantizationSetting();

                if((pucTemp[0] == _AVI_YCC_QUANTIZATION_LIMITED) || (pucTemp[1] == _AVI_YCC_QUANTIZATION_LIMITED))
                {
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        if(ScalerTMDSRx4HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx4("RGB Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                ScalerSyncTMDSRx4HdmiQuantizationSetting();

                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

    return _FALSE;
}
#endif

#if((_D5_HDMI_SUPPORT == _ON) && (_TMDS_COMBO_EXIST == _OFF))
//--------------------------------------------------
// Description  : TMDS Rx0 Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx5HdmiVideoSetting(void)
{
    if(GET_HDMI_RX5_AVI_INFO_FRAME_RECEIVED() == _TRUE)
    {
        // Color Space Auto/ Pixel Repetition auto mode
        ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_51_PORT_PAGE74_HDMI_ACRCR, ~(_BIT6 | _BIT2), (_BIT6 | _BIT2));

        pData[0] = ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE);

        // Get Color Space
        if(pData[0] == _AVI_COLOR_SPACE_00)
        {
            // Color Space RGB
            DebugMessageRx5("Get Color Space RGB", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_01)
        {
            // YCC422
            DebugMessageRx5("Get Color Space YUV422", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
        }
        else if(pData[0] == _AVI_COLOR_SPACE_11)
        {
            // YCC420
            DebugMessageRx5("Get Color Space YUV420", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
        }
        else
        {
            // YCC444
            DebugMessageRx5("Get Color Space YUV444", pData[0]);
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
        }

        // Set Pixel Repetition
        switch(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_PIXEL_REPETITION))
        {
            case _AVI_PIXEL_REPETITION_0:

                DebugMessageRx5("Get Pixel Repetition 0", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;

            case _AVI_PIXEL_REPETITION_1:

                DebugMessageRx5("Get Pixel Repetition 1", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_1);

                break;

            case _AVI_PIXEL_REPETITION_2:

                DebugMessageRx5("Get Pixel Repetition 2", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_2);

                break;

            case _AVI_PIXEL_REPETITION_3:

                DebugMessageRx5("Get Pixel Repetition 3", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_3);

                break;

            case _AVI_PIXEL_REPETITION_4:

                DebugMessageRx5("Get Pixel Repetition 4", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_4);

                break;

            case _AVI_PIXEL_REPETITION_5:

                DebugMessageRx5("Get Pixel Repetition 5", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_5);

                break;

            case _AVI_PIXEL_REPETITION_6:

                DebugMessageRx5("Get Pixel Repetition 6", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_6);

                break;

            case _AVI_PIXEL_REPETITION_7:

                DebugMessageRx5("Get Pixel Repetition 7", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_7);

                break;

            case _AVI_PIXEL_REPETITION_8:

                DebugMessageRx5("Get Pixel Repetition 8", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_8);

                break;

            case _AVI_PIXEL_REPETITION_9:

                DebugMessageRx5("Get Pixel Repetition 9", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_9);

                break;

            default:

                DebugMessageRx5("Get Pixel Repetition Error", 0x00);
                SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

                break;
        }

        // Set Colorimetry
        ScalerSyncTMDSRx5HdmiColorimetrySetting();

        // Set Quantization
#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
        ScalerSyncTMDSRx5HdmiQuantizationSetting();
#endif
    }
    else    // No Info Frame Received
    {
#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
        if(GET_TMDS_RX5_CLK_MODE() == _TMDS_MHL_PPMODE_PHY_SETTING)
        {
            SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

            // Manual Set Color Space to YCbCr422 and disable pixel repetition
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_51_PORT_PAGE74_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), _BIT3);
        }
        else
#endif

        {
            SET_COLOR_SPACE(_COLOR_SPACE_RGB);
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

            // Manual Set Color Space to RGB and disable pixel repetition
            ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_51_PORT_PAGE74_HDMI_ACRCR, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);
        }

        // Disable down sampling
        ScalerSetDataPortBit(P74_C9_HDMI_AP, _P74_CA_PT_50_PORT_PAGE74_HDMI_VCR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

        SET_TMDS_RX5_AVI_PIXEL_REPETITION(_AVI_PIXEL_REPETITION_0);

        // Waiting for down sampling  effect
        ScalerTimerDelayXms(20);
    }

    ScalerTMDSRx5SetPorchColor(GET_COLOR_SPACE());
}

//--------------------------------------------------
// Description  : TMDS Rx5 HDMI Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx5HdmiColorimetrySetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY))
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx5("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_00);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_01:

                DebugMessageRx5("Get Colorimetry YCC_SMPTE_170M", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_01);

                SET_COLORIMETRY(_COLORIMETRY_YCC_SMPTE_170M);

                break;

            case _AVI_COLORIMETRY_10:

                DebugMessageRx5("Get Colorimetry 709", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_10);

                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx5("Get Colorimetry Extended", 0x00);

                SET_DIGITAL_COLORIMETRY_PREVALUE(_AVI_COLORIMETRY_11);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx5HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx5("Get Colorimetry INTO_DEFAULT", 0x00);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_PREVALUE(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_PREVALUE())
        {
            case _AVI_COLORIMETRY_00:

                DebugMessageRx5("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;

            case _AVI_COLORIMETRY_11:

                DebugMessageRx5("Get Colorimetry RGB_SRGB", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_EXT);

                ScalerSyncTMDSRx5HdmiColorimetryExtSetting();

                break;

            default:

                DebugMessageRx5("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : TMDS Rx5 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx5HdmiColorimetryExtSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        // Get extended colorimetry
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        // Get extended colorimetry
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_000:

                DebugMessageRx5("Get Colorimetry EXT_YCC_XVYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_001:

                DebugMessageRx5("Get Colorimetry EXT_YCC_XVYCC709", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);

                break;

            case _AVI_COLORIMETRY_EXT_010:

                DebugMessageRx5("Get Colorimetry EXT_YCC_SYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_011:

                DebugMessageRx5("Get Colorimetry EXT_YCC_ADOBEYCC601", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);

                break;

            case _AVI_COLORIMETRY_EXT_101:

                DebugMessageRx5("Get Colorimetry EXT_YCC_ITUR_BT2020_CL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx5("Get Colorimetry EXT_YCC_ITUR_BT2020_NCL", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);

                break;

            default:

                DebugMessageRx5("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY));

        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _AVI_COLORIMETRY_EXT_100:

                DebugMessageRx5("Get Colorimetry EXT_RGB_ADOBERGB", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);

                break;

            case _AVI_COLORIMETRY_EXT_110:

                DebugMessageRx5("Get Colorimetry EXT_RGB_ITUR_BT2020", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);

                break;

            default:

                DebugMessageRx5("Get Colorimetry INTO_DEFAULT", 0x00);

                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);

                break;
        }
    }
}

#if((_RGB_QUANTIZATION_RANGE_SUPPORT == _ON) || (_YCC_QUANTIZATION_RANGE_SUPPORT == _ON))
//--------------------------------------------------
// Description  : TMDS Rx5 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncTMDSRx5HdmiQuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        SET_DIGITAL_QUANTIZATION_PREVALUE(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION));

        switch(GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            case _AVI_YCC_QUANTIZATION_FULL:

                DebugMessageRx5("Get YCC FULL RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_YCC_QUANTIZATION_LIMITED:

                DebugMessageRx5("Get YCC LIMIT RANGE", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);

                break;

            default:

                DebugMessageRx5("Get YCC RANGE Error", 0x00);

                SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_RESERVED);

                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION))
        {
            case _AVI_RGB_QUANTIZATION_LIMITED:

                DebugMessageRx5("Get RGB LIMIT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_LIMITED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_FULL:

                DebugMessageRx5("Get RGB FULL RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_DEFAULT:

                DebugMessageRx5("Get RGB DEFAULT RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_DEFAULT);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_DEFAULT_RANGE);

                break;

            case _AVI_RGB_QUANTIZATION_RESERVED:

                DebugMessageRx5("Get RGB RESERVED RANGE", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_RESERVED);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);

                break;

            default:

                DebugMessageRx5("Get RGB RANGE Error", 0x00);

                SET_DIGITAL_QUANTIZATION_PREVALUE(_AVI_RGB_QUANTIZATION_FULL);

                SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);

                break;
        }
    }
}
#endif

//--------------------------------------------------
// Description  : TMDS Rx5 HDMI ColorInfo Changed Detect
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncTMDSRx5HdmiColorInfoChanged(void)
{
    // Check Color Space
    if(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_COLOR_SPACE) != GET_COLOR_SPACE())
    {
        DebugMessageRx5("Color Space Changed", 0x00);
        return _TRUE;
    }

    // Check Colorimetry
    if(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_PREVALUE())
    {
        DebugMessageRx5("Colorimetry Changed", 0x00);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
        {
            BYTE pucTemp[2];

            pucTemp[0] = ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_COLORIMETRY);

            pucTemp[1] = GET_DIGITAL_COLORIMETRY_PREVALUE();

            ScalerSyncTMDSRx5HdmiColorimetrySetting();

            if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
            {
                if(!(((pucTemp[0] == _AVI_COLORIMETRY_00) && (pucTemp[1] == _AVI_COLORIMETRY_01)) || ((pucTemp[0] == _AVI_COLORIMETRY_01) && (pucTemp[1] == _AVI_COLORIMETRY_00))))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
            else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
            {
                if((pucTemp[0] == _AVI_COLORIMETRY_11) || (pucTemp[1] == _AVI_COLORIMETRY_11))
                {
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            return _TRUE;
        }
    }
    else
    {
        if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
        {
            if(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
            {
                DebugMessageRx5("Ext Colorimetry Changed", 0x00);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
                {
                    BYTE pucTemp[2];

                    pucTemp[0] = ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_EXTENDED_COLORIMETRY);

                    pucTemp[1] = GET_DIGITAL_COLORIMETRY_EXT_PREVALUE();

                    ScalerSyncTMDSRx5HdmiColorimetryExtSetting();

                    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
                    {
                        if(!(((pucTemp[0] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] == _AVI_COLORIMETRY_EXT_111)) || ((pucTemp[1] == _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] == _AVI_COLORIMETRY_EXT_111))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
                    {
                        if(!(((pucTemp[0] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[0] != _AVI_COLORIMETRY_EXT_110)) && ((pucTemp[1] != _AVI_COLORIMETRY_EXT_100) && (pucTemp[1] != _AVI_COLORIMETRY_EXT_110))))
                        {
                            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
                        }
                    }
                }
                else
                {
                    return _TRUE;
                }
            }
        }
    }

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx5("YCC Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                BYTE pucTemp[2];

                pucTemp[0] = ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_YCC_QUANTIZATION);

                pucTemp[1] = GET_DIGITAL_QUANTIZATION_PREVALUE();

                ScalerSyncTMDSRx5HdmiQuantizationSetting();

                if((pucTemp[0] == _AVI_YCC_QUANTIZATION_LIMITED) || (pucTemp[1] == _AVI_YCC_QUANTIZATION_LIMITED))
                {
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        if(ScalerTMDSRx5HdmiGetAVIInfo(_AVI_INFO_RGB_QUANTIZATION) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx5("RGB Quantization Range Changed", 0x00);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _FALSE)
            {
                ScalerSyncTMDSRx5HdmiQuantizationSetting();

                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
            else
            {
                return _TRUE;
            }
        }
    }
#endif

    return _FALSE;
}
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Digital Get Colorimetry Changed
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncDigitalGetColorimetryChanged(void)
{
    return GET_DIGITAL_COLORIMETRY_CHANGED();
}

//--------------------------------------------------
// Description  : Digital Get Colorimetry Extended Changed
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncDigitalGetColorimetryExtChanged(void)
{
    return GET_DIGITAL_COLORIMETRY_EXT_CHANGED();
}

//--------------------------------------------------
// Description  : Digital Get Quantization Changed
// Input Value  : None
// Output Value : Changed ==> _TRUE; No Changed ==> _FALSE;
//--------------------------------------------------
bit ScalerSyncDigitalGetQuantizationChanged(void)
{
    return GET_DIGITAL_QUANTIZATION_CHANGED();
}

//--------------------------------------------------
// Description  : Digital Clr ColorimetryChanged
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDigitalClrColorimetryChanged(void)
{
    CLR_DIGITAL_COLORIMETRY_CHANGED();
}

//--------------------------------------------------
// Description  : Digital Clr Colorimetry Extended Changed
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDigitalClrColorimetryExtChanged(void)
{
    CLR_DIGITAL_COLORIMETRY_EXT_CHANGED();
}

//--------------------------------------------------
// Description  : Digital Clr Quantization Changed
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerSyncDigitalClrQuantizationChanged(void)
{
    CLR_DIGITAL_QUANTIZATION_CHANGED();
}
#endif

#if(_HW_FLASH_ACCESS_METHOD == _XDATA_MAP_ACCESS)
//--------------------------------------------------
// Description  : Check VGA use embedded EDID
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
bit ScalerSyncVGAUseEmbeddedEDID(void)
{
#if(_A0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
    return _TRUE;
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check VGA DDC channel idle
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerSyncVGADdcCheckBusyAndForceNack(void)
{
#if(_VGA_PORT_EXIST == _ON)
    WORD usTemp = 0;

#if(_HW_PC99_VGADDC2_SUPPORT == _ON)
    if(GET_A0_DDC_CHANNEL_SEL() == _VGA_DDC2)
    {
        MCU_FD37_ADC_DDC2_EDID_IRQ |= _BIT2;

        // set a polling duration
        for(usTemp = 0; usTemp < 1500; usTemp++)
        {
            // delay 20us for IIC 100k
            Delay5us_EXINT(g_ucDelay5usN);
            Delay5us_EXINT(g_ucDelay5usN);
            Delay5us_EXINT(g_ucDelay5usN);
            Delay5us_EXINT(g_ucDelay5usN);

            if((MCU_FD37_ADC_DDC2_EDID_IRQ & _BIT2) == _BIT2)
            {
                MCU_FD37_ADC_DDC2_EDID_IRQ |= _BIT2;
            }
            else
            {
                break;
            }
        }

        if((MCU_FD37_ADC_DDC2_EDID_IRQ & _BIT2) == _BIT2)
        {
            DebugMessageScaler("Warning :  VGA DDC2 wait SCL idle timeout", 0);
        }
    }
    else
#endif
    {
        MCU_FFE7_VGA_EDID_IRQ |= _BIT2;

        // set a polling duration
        for(usTemp = 0; usTemp < 1500; usTemp++)
        {
            // delay 20us for IIC 100k
            Delay5us_EXINT(g_ucDelay5usN);
            Delay5us_EXINT(g_ucDelay5usN);
            Delay5us_EXINT(g_ucDelay5usN);
            Delay5us_EXINT(g_ucDelay5usN);

            if((MCU_FFE7_VGA_EDID_IRQ & _BIT2) == _BIT2)
            {
                MCU_FFE7_VGA_EDID_IRQ |= _BIT2;
            }
            else
            {
                break;
            }
        }

        if((MCU_FFE7_VGA_EDID_IRQ & _BIT2) == _BIT2)
        {
            DebugMessageScaler("Warning :  VGA DDC wait SCL idle timeout", 0);
        }
    }

    // Force nack Ddc Channel
    ScalerSyncSetDdcForceNack(_A0_INPUT_PORT, _ON);
#endif
}
#endif // End of #if(_HW_FLASH_ACCESS_METHOD == _XDATA_MAP_ACCESS)

