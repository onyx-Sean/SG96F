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
// ID Code      : NoneUserInterface.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_INTERFACE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _NONE_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _EDID_VENDOR_SPEC_0                     160
#define _EDID_CHKSUM                            255

//-------------------------------------------------------
//  Definitions of RCP Key Codes
//-------------------------------------------------------
#define _MHL_RCP_VOLUME_UP                      0x41
#define _MHL_RCP_VOLUME_DOWN                    0x42
#define _MHL_RCP_MUTE                           0x43
#define _MHL_RCP_MUTE_FUNCTION                  0x65
#define _MHL_RCP_RESTORE_VOLUME_FUNCTION        0x66

//--------------------------------------------------
// Definitions of DCR THD Setting
//--------------------------------------------------
#define _DCR_THESHOLD1                          0x20
#define _DCR_THESHOLD2                          0x180

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//----------------------------------------------------------------------------------------------------
// EDID Table
//----------------------------------------------------------------------------------------------------
#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
#if(_DP_SUPPORT == _ON)
BYTE code tEDID_TABLE_DP_1080P[] =
{
#include "./EDID/EdidDp/EDID_DP_1920x1080@60.h"
};

BYTE code tEDID_TABLE_DP_2K1K[] =
{
#include "./EDID/EdidDp/EDID_DP_2560x1440@60_DELL.h"
};

BYTE code tEDID_TABLE_DP_4K2K_30[] =
{
#include "./EDID/EdidDp/EDID_DP_3840x2160@30_DELL.h"
};

BYTE code tEDID_TABLE_DP_4K2K_60[] =
{
#include "./EDID/EdidDp/EDID_DP_3840x2160@60_RTK.h"
};
#endif

#if(_D0_HDMI_SUPPORT == _ON)

BYTE code tHDMI14_EDID_TABLE_D0[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
};

BYTE code tHDMI20_EDID_TABLE_D0[] =
{
#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_WITH420.h"
#else
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60.h"
#endif
};

BYTE code tHDMI20_HDR_EDID_TABLE_D0[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_HFVSDB_WITH420_HDR.h"
};

#endif

#if(_D1_HDMI_SUPPORT == _ON)

BYTE code tHDMI14_EDID_TABLE_D1[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
};

BYTE code tHDMI20_EDID_TABLE_D1[] =
{
#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_WITH420.h"
#else
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60.h"
#endif
};

BYTE code tHDMI20_HDR_EDID_TABLE_D1[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_HFVSDB_WITH420_HDR.h"
};

#endif


#if(_D2_HDMI_SUPPORT == _ON)

BYTE code tHDMI14_EDID_TABLE_D2[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
};

BYTE code tHDMI20_EDID_TABLE_D2[] =
{
#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_WITH420.h"
#else
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60.h"
#endif
};

BYTE code tHDMI20_HDR_EDID_TABLE_D2[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_HFVSDB_WITH420_HDR.h"
};

#endif

#if(_D3_HDMI_SUPPORT == _ON)

BYTE code tHDMI14_EDID_TABLE_D3[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
};

BYTE code tHDMI20_EDID_TABLE_D3[] =
{
#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_WITH420.h"
#else
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60.h"
#endif
};

BYTE code tHDMI20_HDR_EDID_TABLE_D3[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_HFVSDB_WITH420_HDR.h"
};

#endif

#if(_D4_HDMI_SUPPORT == _ON)

BYTE code tHDMI14_EDID_TABLE_D4[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
};

BYTE code tHDMI20_EDID_TABLE_D4[] =
{
#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_WITH420.h"
#else
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60.h"
#endif
};

BYTE code tHDMI20_HDR_EDID_TABLE_D4[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_HFVSDB_WITH420_HDR.h"
};

#endif

#if(_D5_HDMI_SUPPORT == _ON)

BYTE code tHDMI14_EDID_TABLE_D5[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI_1920x1080@60.h"
};

BYTE code tHDMI20_EDID_TABLE_D5[] =
{
#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_WITH420.h"
#else
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60.h"
#endif
};

BYTE code tHDMI20_HDR_EDID_TABLE_D5[] =
{
#include "./EDID/EdidHdmi/EDID_HDMI2_3840x2160@60_HFVSDB_WITH420_HDR.h"
};

#endif
#endif

//----------------------------------------------------------------------------------------------------
// Filter Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
#if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))
BYTE code tSU_COEF_128_TAPS_0[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable0.h"
};

BYTE code tSU_COEF_128_TAPS_2[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable2.h"
};

BYTE code tSU_COEF_128_TAPS_4[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable4.h"
};

BYTE code tSU_COEF_128_TAPS_6[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable6.h"
};

BYTE code tSU_COEF_128_TAPS_8[] =
{
#include "./Sharpness/Sharpness128TapsNormalTable8.h"
};

code BYTE *tSCALE_128TAPS_NORMAL_COEF_TABLE[] =
{
    tSU_COEF_128_TAPS_0,        tSU_COEF_128_TAPS_2,        tSU_COEF_128_TAPS_4,        tSU_COEF_128_TAPS_6,        tSU_COEF_128_TAPS_8,
};
#endif // End of #if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))

#if(_HSU_128TAPS_SUPPORT == _ON)
BYTE code tSU_1to1_COEF_128_TAPS_0[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table0.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_2[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table2.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_4[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table4.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_6[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table6.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_8[] =
{
#include "./Sharpness/Sharpness128Taps1to1Table8.h"
};

code BYTE *tSCALE_128TAPS_1to1_COEF_TABLE[] =
{
    tSU_1to1_COEF_128_TAPS_0,        tSU_1to1_COEF_128_TAPS_2,        tSU_1to1_COEF_128_TAPS_4,        tSU_1to1_COEF_128_TAPS_6,        tSU_1to1_COEF_128_TAPS_8,
};
#endif // End of #if(_HSU_128TAPS_SUPPORT == _ON)

#if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))
BYTE code tSU_COEF_96_TAPS_0[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable0.h"
};

BYTE code tSU_COEF_96_TAPS_2[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable2.h"
};

BYTE code tSU_COEF_96_TAPS_4[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable4.h"
};

BYTE code tSU_COEF_96_TAPS_6[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable6.h"
};

BYTE code tSU_COEF_96_TAPS_8[] =
{
#include "./Sharpness/Sharpness96TapsNormalTable8.h"
};

code BYTE *tSCALE_96TAPS_NORMAL_COEF_TABLE[] =
{
    tSU_COEF_96_TAPS_0,        tSU_COEF_96_TAPS_2,        tSU_COEF_96_TAPS_4,        tSU_COEF_96_TAPS_6,        tSU_COEF_96_TAPS_8,
};
#endif // End of #if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))

#if(_HSU_96TAPS_SUPPORT == _ON)
BYTE code tSU_1to1_COEF_96_TAPS_0[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table0.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_2[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table2.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_4[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table4.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_6[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table6.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_8[] =
{
#include "./Sharpness/Sharpness96Taps1to1Table8.h"
};

code BYTE *tSCALE_96TAPS_1to1_COEF_TABLE[] =
{
    tSU_1to1_COEF_96_TAPS_0,        tSU_1to1_COEF_96_TAPS_2,        tSU_1to1_COEF_96_TAPS_4,        tSU_1to1_COEF_96_TAPS_6,        tSU_1to1_COEF_96_TAPS_8,
};
#endif // End of #if(_HSU_96TAPS_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// ULTRAVIVID TABLE
//----------------------------------------------------------------------------------------------------
BYTE code tCOLOR_ULTRAVIVID_SETTING_L[] =
{
#include "./UltraVivid/UltraVividTableL.h"
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M[] =
{
#include "./UltraVivid/UltraVividTableM.h"
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_H[] =
{
#include "./UltraVivid/UltraVividTableH.h"
};

code BYTE *tCOLOR_ULTRAVIVID_SETTING_TABLE[] =
{
    tCOLOR_ULTRAVIVID_SETTING_L,
    tCOLOR_ULTRAVIVID_SETTING_M,
    tCOLOR_ULTRAVIVID_SETTING_H,
};
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_YPEAKING_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// Ypeaking Coefficient Table
//----------------------------------------------------------------------------------------------------
#include "YPeakingTable.h"

code BYTE *tYPEAKING_TABLE[] =
{
    tYPK_COEF_1,
};
#endif // End of #if(_YPEAKING_SUPPORT == _ON)


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_UART_SUPPORT == _ON)
BYTE g_pucUartData[5];
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID);

//-------------------------------------------------------
// INT
//-------------------------------------------------------
#if(_INSTANT_TIMER_EVENT_0 == _ON)
void UserInterfaceTimer0InstantAccess_EXINT(void);
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
void UserInterfaceTimer1InstantAccess_EXINT(void);
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
void UserInterfaceTimer2InstantAccess_EXINT(void);
#endif

#if(_UART_SUPPORT == _ON)
void UserInterfaceUartIntHandler_SERIALPORT(void);
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
BYTE UserInterfaceGetDdcciStatus_EXINT1(void);
BYTE UserInterfaceGetFactoryCommand_EXINT1(void);
#if(_HDMI_FREESYNC_SUPPORT == _ON)
BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void);
#endif
#endif

//-------------------------------------------------------
// EDID & HDCP
//-------------------------------------------------------
#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
void UserInterfaceGetEmbeddedEDIDData(EnumInputPortEdid enumInputPort);
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
void UserInterfaceGetHDCPKeyBksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void UserInterfaceGetHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);

#if(_DP_TX_SUPPORT == _ON)
void UserInterfaceGetTxHDCPKeyAksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray);
void UserInterfaceGetTxHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif
#endif

#if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
void UserInterfaceGetHdcp2CertrxByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSADkeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSARRModNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSAKPrivByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2RSANpinvByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
void UserInterfaceGetHdcp2LCKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
#endif
#endif

//-------------------------------------------------------
// Wait for Panel Power Sequence Delay
//-------------------------------------------------------
#if(_PANEL_POWER_SEQUENCE_CONTROL_BY_USER == _ON)
void UserInterfacePanelPowerAction(BYTE ucEvent);
#endif

void UserInterfaceAdjustWaitPanelT1(void);
void UserInterfaceAdjustWaitPanelT2(void);
void UserInterfaceAdjustWaitPanelT3(void);
#if(_PANEL_TYPE != _PANEL_NONE)
void UserInterfaceAdjustWaitPanelT4(void);
#endif
void UserInterfaceAdjustWaitPanelT5(void);

//-------------------------------------------------------
// Misc
//-------------------------------------------------------
void UserInterfaceUncallFunction(void);
void UserInterfaceInitial(void);

void UserInterfacePowerSwitch(EnumPowerAction enumSwitch);
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed);

//-------------------------------------------------------
// User Information
//-------------------------------------------------------
bit UserInterfaceGetLogoStatus(void);
bit UserInterfaceGetdNoSupportStatus(void);
bit UserInterfaceGetDclkNoSupportStatus(void);
bit UserInterfaceGetActiveByPassStatus(void);
bit UserInterfaceGetCableResetStatus(void);
bit UserInterfaceGetForcePSStatus(void);
bit UserInterfaceGetIntoPSStatus(void);
bit UserInterfaceGetNVRamDataStatus(EnumNvramCheckType enumNvramCheckType);
bit UserInterfaceGetDisplaySettingBacklightAction(void);

#if(_OVERSCAN_SUPPORT == _ON)
bit UserInterfaceGetOverScanStatus(void);
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
EnumAspectRatioType UserInterfaceGetAspectRatioType(void);
void UserInterfaceGetAspectRatio(WORD *pusHRatio, WORD *pusVRatio);
void UserInterfaceAdjustAspectRatio(void);

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
BYTE UserInterfaceGetAspectRatioOriginalRatio(void);
#endif

#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
EnumRotationType UserInterfaceGetRotationDegree(void);
EnumRotationDisplayType UserInterfaceGetRotationDisplayType(void);
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
BYTE UserInterfaceGetDisplayLatencyRatio(void);
#endif

#if(_FRC_SUPPORT == _ON)
void UserInterfaceGetDVMaxMinFreq(StructDVCustomizedFreq *pstDVCustomizedFreq);
#endif

#if(_OD_SUPPORT == _ON)
EnumFunctionOnOFF UserInterfaceGetODEnableStatus(void);
#endif

#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR3) && (_DDR3_MULTIPHASE_EXIST == _ON))
void UserInterfaceUpdateDDR3PhaseData(void);
#endif

#if(_USER_SYSTEM_EEPROM_CUSTOMIZATION == _ON)
bit UserInterfaceSystemEepromReadCustomProc(WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
bit UserInterfaceSystemEepromWriteCustomProc(WORD usSubAddr, WORD usLength, BYTE *pucWriteArray);
#endif

//-------------------------------------------------------
// Display Timing
//-------------------------------------------------------
void UserInterfaceDisplayInitialization(void);
void UserInterfaceAdjustInputTiming(void);
void UserInterfaceAdjustDisplayTiming(void);

#if(_UNDERSCAN_SUPPORT == _ON)
bit UserInterfaceAdjustUnderScan(void);
#endif

//-------------------------------------------------------
// Color
//-------------------------------------------------------
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceGetRGBQuantizationLimitRangeStatus(EnumColorRGBQuantization enumColorRGBQuantization);
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceGetYCCQuantizationFullRangeStatus(EnumColorYCCQuantization enumColorYCCQuantization);
#endif

void UserInterfaceAdjustActiveByPassColorProc(void);
void UserInterfaceAdjustColorProc(void);

#if(_ULTRA_HDR_SUPPORT == _ON)
void UserInterfaceAdjustHDRColorProcInitial(void);
extern void UserInterfaceAdjustHDR2084(void);
void UserInterfaceAdjustHDRTargetHDR(void);
void UserInterfaceAdjustHDRTargetSDR(void);
EnumHDRModeDef UserInterfaceGetHDRModeStatus(void);
bit UserInterfaceGetHDRDarkEnhanceStatus(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
void UserInterfaceAdjustUltraVivid(void);
void UserInterfaceAdjustUltraVividProc(EnumDBApply enumDBApply);
#endif

#if(_SHARPNESS_SUPPORT == _ON)
code BYTE *UserInterfaceGetSharpnessCoef(EnumSUCoefType enumSUCoefType, EnumSourceSearchPort enumSourceSearchPort);
BYTE UserInterfaceGetSharpnessCoefBankNum(void);
bit UserInterfaceSharpnessBypassCheck(void);
#endif

#if(_DCR_SUPPORT == _ON)
void UserInterfaceAdjustDCR(void);
#endif

//-------------------------------------------------------
// Osd
//-------------------------------------------------------
void UserInterfaceAdjustOsdPowerOnInitial(void);
void UserInterfaceAdjustOsdActiveProc(void);
void UserInterfaceAdjustOsdResetProc(void);

//-------------------------------------------------------
// Interfaces
//-------------------------------------------------------
#if(_VGA_SUPPORT == _ON)
BYTE UserInterfaceGetVGAConfuseMode(BYTE ucModeIndex);
bit UserInterfaceGetLoadModeTableDefaultStatus(void);
bit UserInterfaceGetFirstAutoConfigStatus(void);
void UserInterfaceGetAutoConfigPercentage(BYTE ucAutoPercentage);

#if(_VGA_FORCE_DISPLAY == _ON)
BYTE UserInterfaceModeSearchModeVGA(void);
#endif

bit UserInterfaceSkipAutoVpos(void);
bit UserInterfaceSkipAutoHpos(void);
#endif

#if(_MHL_SUPPORT == _ON)
bit UserInterfaceAdjustMHLMscRCPProc(BYTE ucKeyCode);
#endif

#if(_FREESYNC_SUPPORT == _ON)
bit UserInterfaceGetFREESYNCEnable(void);
#endif

#if(_DP_SUPPORT == _ON)
EnumDpVersionType UserInterfaceGetDPVersion(BYTE ucInputPort);
EnumDpLaneCount UserInterfaceGetDpLaneCount(BYTE ucInputPort);
EnumDPMSTPort UserInterfaceGetDpMSTCapablePort(void);

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
bit UserInterfaceGetDpCloneOutputStatus(void);
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) || (_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP))
BYTE UserInterfaceGetDpSwitchSelectPort(void);
#endif

#endif // End of #if(_DP_SUPPORT == _ON)

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
bit UserInterfaceGetHdmi5VStatus(BYTE ucInputPort);
#endif

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_EIZO_STYLE)
bit UserInterfaceAdjustOsdCheckTotalSearchFinish(void);
void UserInterfaceAdjustSourceSearchTime(void);
WORD UserInterfaceGetEizoSearchFinishTime(void);
#endif

//-------------------------------------------------------
// AUDIO
//-------------------------------------------------------
#if(_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioReadyToPlayStatus(void);
bit UserInterfaceGetAudioMuteStatus(void);
EnumAudioInputSource UserInterfaceGetAudioSource(void);
bit UserInterfaceGetAudioNonLPCMStatus(void);
WORD UserInterfaceGetAudioVolume(void);

#if(_EMBEDDED_DAC_SUPPORT == _ON)
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void);
bit UserInterfaceGetAudioDACKeepDepopState(void);
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioStandAloneStatus(void);
#endif

void UserInterfaceAdjustAudioResetProc(void);
void UserInterfaceAdjustAudioPowerProc(EnumPowerStatus enumPowStatus);
void UserInterfaceAdjustAudioAmpMuteProc(bit bMute);

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
void UserInterfaceSwapExternalAudioCodecInput(bit bSwap);
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if(_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypecUSBSupport(BYTE ucInputPort);
bit UserInterfaceTypecGetUSBSupportStatus(BYTE ucInputPort);

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB)
void UserInterfaceTypecSwitchDPLaneByUsbHubStatus(void);
#endif

void UserInterfaceTypeCPortControllerTypeCModeSwitch(BYTE ucInputPort);

#if(_D0_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD0PortControllerPower(void);
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD1PortControllerPower(void);
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD2PortControllerPower(void);
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD6PortControllerPower(void);
#endif

bit UserInterfaceTypeCPortControllerCheckAltMode(BYTE ucInputPort);
bit UserInterfaceTypeCPortControllerAltModeUserFlow(BYTE ucInputPort);
bit UserInterfaceTypeCPortControllerCableCheckUserFlow(BYTE ucInputPort);
BYTE UserInterfaceTypeCGetOsdLaneSelMode(BYTE ucInputPort);

#if(_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON)
bit UserInterfaceTypeCPDO(BYTE ucInputPort);
#endif

bit UserInterfaceTypeCPortControllerSupport(BYTE ucInputPort);

#if(_DP_USB_HUB_SUPPORT == _ON)
WORD UserInterfaceTypecUsbHubSetPollingStep(BYTE ucInputPort);
bit UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(BYTE ucInputPort);
bit UserInterfaceTypecUsbHubSetSSMode(BYTE ucInputPort, bit bEn);
BYTE UserInterfaceTypecUsbHubDetectSSDevicePlugInfo(BYTE ucInputPort);
#endif

#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON) || (_UNIFORMITY_SUPPORT == _ON))
void UserInterfaceAdjustBeforeDisplayCalibration(EnumCaliType enumMode);
void UserInterfaceAdjustAfterDisplayCalibration(EnumCaliType enumMode);
#endif

#if(_YPEAKING_SUPPORT == _ON)
void UserInterfaceAdjustYpeaking(void);
#endif

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
void UserInterfaceReceivedDataProc(BYTE *pucArray);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : None
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
        case _USER_TIMER_EVENT_KEY_REPEAT_ENABLE:
            SET_KEYREPEATSTART();
            break;

        case _USER_TIMER_EVENT_KEY_SCAN_READY:
            SET_KEYSCANREADY();
            break;

        case _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON:
            SET_PANELPOWERSTATUS(_READY_FOR_BACKLIGHT);
            break;

        case _USER_TIMER_EVENT_PANEL_POWER_OFF:
            break;

        case _USER_TIMER_EVENT_PANEL_USED_TIMER:
            break;

        default:
            break;
    }
}

#if(_INSTANT_TIMER_EVENT_0 == _ON)
//--------------------------------------------------
// Description  : Action in Timer0 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void UserInterfaceTimer0InstantAccess_EXINT(void)
{
}
#pragma restore
#endif

#if(_INSTANT_TIMER_EVENT_1 == _ON)
//--------------------------------------------------
// Description  : Action in Timer1 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void UserInterfaceTimer1InstantAccess_EXINT(void)
{
}
#pragma restore
#endif

#if(_SYSTEM_TIMER_QUARTER_RESOLUTION == _ON)
//--------------------------------------------------
// Description  : Action in Timer2 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#pragma save
#pragma OT(8)
void UserInterfaceTimer2InstantAccess_EXINT(void)
{
}
#pragma restore
#endif

#if(_UART_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Action in Serial Port0 int defined by User
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUartIntHandler_SERIALPORT(void)
{
    if(GET_UART_RECEIVE_STATUS() == _TRUE)
    {
        g_pucUartData[0] = GET_UART_DATA();

        CLR_UART_RECEIVE_STATUS();
    }
}
#endif

#if(_DEBUG_MESSAGE_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get DDC-CI Status for Int1
// Input Value  : ucDataType --> Data Type in StructSystemData
// Output Value : ucValue --> Value of the Input Data Type
//--------------------------------------------------
BYTE UserInterfaceGetDdcciStatus_EXINT1(void) using 2
{
    return GET_OSD_DDCCI_STATUS();
}

//--------------------------------------------------
// Description  : Get Data from DDCCI Buffer defined by user
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetFactoryCommand_EXINT1(void) using 2
{
    return _FALSE;
}

#if(_HDMI_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Source Opcode is HDMI freesync
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceDdcciHDMIFreesyncOpcode_EXINT1(void) using 2
{
    return _FALSE;
}
#endif // #if(_HDMI_FREESYNC_SUPPORT == _ON)
#endif

#if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Set Embedded EDID Data
// Input Value  : Input Port EDID Select
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetEmbeddedEDIDData(EnumInputPortEdid enumInputPort)
{
    switch(enumInputPort)
    {
        case _A0_INPUT_PORT_EDID:
            break;

        case _D0_INPUT_PORT_EDID:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _DP_EDID_1080P)
            {
                memcpy(MCU_DDCRAM_D0, tEDID_TABLE_DP_1080P, _D0_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _DP_EDID_2560_1440)
            {
                memcpy(MCU_DDCRAM_D0, tEDID_TABLE_DP_2K1K, _D0_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _DP_EDID_4K2K_30HZ)
            {
                memcpy(MCU_DDCRAM_D0, tEDID_TABLE_DP_4K2K_30, _D0_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _DP_EDID_4K2K_60HZ)
            {
                memcpy(MCU_DDCRAM_D0, tEDID_TABLE_DP_4K2K_60, _D0_EMBEDDED_DDCRAM_SIZE);
            }

#elif(_D0_HDMI_SUPPORT == _ON)

            if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _HDMI_EDID_0)
            {
#if((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_SIZE_NONE) && (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D0, tHDMI14_EDID_TABLE_D0, _D0_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _HDMI_EDID_1)
            {
#if((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_SIZE_NONE) && (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D0, tHDMI20_EDID_TABLE_D0, _D0_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D0_SELECT) == _HDMI_EDID_2)
            {
#if((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_SIZE_NONE) && (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D0, tHDMI20_HDR_EDID_TABLE_D0, _D0_EMBEDDED_DDCRAM_SIZE);
#endif
            }
#endif
            break;

        case _D1_INPUT_PORT_EDID:

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _DP_EDID_1080P)
            {
                memcpy(MCU_DDCRAM_D1, tEDID_TABLE_DP_1080P, _D1_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _DP_EDID_2560_1440)
            {
                memcpy(MCU_DDCRAM_D1, tEDID_TABLE_DP_2K1K, _D1_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _DP_EDID_4K2K_30HZ)
            {
                memcpy(MCU_DDCRAM_D1, tEDID_TABLE_DP_4K2K_30, _D1_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _DP_EDID_4K2K_60HZ)
            {
                memcpy(MCU_DDCRAM_D1, tEDID_TABLE_DP_4K2K_60, _D1_EMBEDDED_DDCRAM_SIZE);
            }

#elif(_D1_HDMI_SUPPORT == _ON)

            if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _HDMI_EDID_0)
            {
#if((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_SIZE_NONE) && (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D1, tHDMI14_EDID_TABLE_D1, _D1_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _HDMI_EDID_1)
            {
#if((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_SIZE_NONE) && (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D1, tHDMI20_EDID_TABLE_D1, _D1_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D1_SELECT) == _HDMI_EDID_2)
            {
#if((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_SIZE_NONE) && (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D1, tHDMI20_HDR_EDID_TABLE_D1, _D1_EMBEDDED_DDCRAM_SIZE);
#endif
            }
#endif
            break;

        case _D2_INPUT_PORT_EDID:

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _DP_EDID_1080P)
            {
                memcpy(MCU_DDCRAM_D2, tEDID_TABLE_DP_1080P, _D2_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _DP_EDID_2560_1440)
            {
                memcpy(MCU_DDCRAM_D2, tEDID_TABLE_DP_2K1K, _D2_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _DP_EDID_4K2K_30HZ)
            {
                memcpy(MCU_DDCRAM_D2, tEDID_TABLE_DP_4K2K_30, _D2_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _DP_EDID_4K2K_60HZ)
            {
                memcpy(MCU_DDCRAM_D2, tEDID_TABLE_DP_4K2K_60, _D2_EMBEDDED_DDCRAM_SIZE);
            }

#elif(_D2_HDMI_SUPPORT == _ON)

            if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _HDMI_EDID_0)
            {
#if((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_SIZE_NONE) && (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D2, tHDMI14_EDID_TABLE_D2, _D2_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _HDMI_EDID_1)
            {
#if((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_SIZE_NONE) && (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D2, tHDMI20_EDID_TABLE_D2, _D2_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D2_SELECT) == _HDMI_EDID_2)
            {
#if((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_SIZE_NONE) && (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D2, tHDMI20_HDR_EDID_TABLE_D2, _D2_EMBEDDED_DDCRAM_SIZE);
#endif
            }
#endif
            break;

        case _D3_INPUT_PORT_EDID:

#if(_D3_HDMI_SUPPORT == _ON)

            if(UserCommonNVRamGetSystemData(_EDID_D3_SELECT) == _HDMI_EDID_0)
            {
#if((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_SIZE_NONE) && (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D3, tHDMI14_EDID_TABLE_D3, _D3_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D3_SELECT) == _HDMI_EDID_1)
            {
#if((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_SIZE_NONE) && (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D3, tHDMI20_EDID_TABLE_D3, _D3_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D3_SELECT) == _HDMI_EDID_2)
            {
#if((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_SIZE_NONE) && (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D3, tHDMI20_HDR_EDID_TABLE_D3, _D3_EMBEDDED_DDCRAM_SIZE);
#endif
            }
#endif
            break;

        case _D4_INPUT_PORT_EDID:

#if(_D4_HDMI_SUPPORT == _ON)

            if(UserCommonNVRamGetSystemData(_EDID_D4_SELECT) == _HDMI_EDID_0)
            {
#if((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_SIZE_NONE) && (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D4, tHDMI14_EDID_TABLE_D4, _D4_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D4_SELECT) == _HDMI_EDID_1)
            {
#if((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_SIZE_NONE) && (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D4, tHDMI20_EDID_TABLE_D4, _D4_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D4_SELECT) == _HDMI_EDID_2)
            {
#if((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_SIZE_NONE) && (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D4, tHDMI20_HDR_EDID_TABLE_D4, _D4_EMBEDDED_DDCRAM_SIZE);
#endif
            }
#endif
            break;

        case _D5_INPUT_PORT_EDID:

#if(_D5_HDMI_SUPPORT == _ON)

            if(UserCommonNVRamGetSystemData(_EDID_D5_SELECT) == _HDMI_EDID_0)
            {
#if((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_SIZE_NONE) && (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D5, tHDMI14_EDID_TABLE_D5, _D5_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D5_SELECT) == _HDMI_EDID_1)
            {
#if((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_SIZE_NONE) && (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D5, tHDMI20_EDID_TABLE_D5, _D5_EMBEDDED_DDCRAM_SIZE);
#endif
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D5_SELECT) == _HDMI_EDID_2)
            {
#if((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_SIZE_NONE) && (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST))
                memcpy(MCU_DDCRAM_D5, tHDMI20_HDR_EDID_TABLE_D5, _D5_EMBEDDED_DDCRAM_SIZE);
#endif
            }
#endif
            break;

        case _D6_INPUT_PORT_EDID:

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
            if(UserCommonNVRamGetSystemData(_EDID_D6_SELECT) == _DP_EDID_1080P)
            {
                memcpy(MCU_DDCRAM_D6, tEDID_TABLE_DP_1080P, _D6_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D6_SELECT) == _DP_EDID_2560_1440)
            {
                memcpy(MCU_DDCRAM_D6, tEDID_TABLE_DP_2K1K, _D6_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D6_SELECT) == _DP_EDID_4K2K_30HZ)
            {
                memcpy(MCU_DDCRAM_D6, tEDID_TABLE_DP_4K2K_30, _D6_EMBEDDED_DDCRAM_SIZE);
            }
            else if(UserCommonNVRamGetSystemData(_EDID_D6_SELECT) == _DP_EDID_4K2K_60HZ)
            {
                memcpy(MCU_DDCRAM_D6, tEDID_TABLE_DP_4K2K_60, _D6_EMBEDDED_DDCRAM_SIZE);
            }
#endif
            break;

        case _D0_INPUT_PORT_MHL_EDID:
            break;

        case _D1_INPUT_PORT_MHL_EDID:
            break;

        case _D2_INPUT_PORT_MHL_EDID:
            break;

        case _D3_INPUT_PORT_MHL_EDID:
            break;

        case _D4_INPUT_PORT_MHL_EDID:
            break;

        case _D5_INPUT_PORT_MHL_EDID:
            break;

        default:
            break;
    }
}
#endif // End of #if((_EMBEDDED_EDID_SUPPORT == _ON) && (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
//--------------------------------------------------
// Description  : Get HDCP Bksv By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyBksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Tx HDCP Aksv By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetTxHDCPKeyAksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetTxHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)
#endif // End of #if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)

#if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2CertrxByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSADkeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSARRModNByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSAKPrivByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSANpinvByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2LCKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
}
#endif // End of #if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_PANEL_POWER_SEQUENCE_CONTROL_BY_USER == _ON)
//--------------------------------------------------
// Description  : Power Power On/Off Sequence
// Input Value  : ucEvent --> _PANEL_ON
//                            _PANEL_OFF
//                            _BACKLIGHT_ON
//                            _BACKLIGHT_OFF
// Output Value : None
//--------------------------------------------------
void UserInterfacePanelPowerAction(BYTE ucEvent)
{
    ucEvent = ucEvent;
}
#endif

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T1
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT1(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_ON_T1);
}

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T2
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT2(void)
{
#if(_PANEL_STYLE == _PANEL_LVDS)

    ScalerTimerDelayXms(_PANEL_POWER_ON_T2);

#elif(_PANEL_STYLE == _PANEL_VBO)

    ScalerDisplayVboPollingHotPlug(_PANEL_POWER_ON_T2);

#elif(_PANEL_STYLE == _PANEL_DPTX)

    ScalerDisplayDPTxPollingHotPlug(_PANEL_POWER_ON_T2);

#endif
}

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T3
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT3(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_ON_T3);
}

#if(_PANEL_TYPE != _PANEL_NONE)
//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT4(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_OFF_T4);
}
#endif

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T5
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT5(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_OFF_T5);
}

//--------------------------------------------------
// Description  : Uncall Function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUncallFunction(void)
{
    bit bUncall = _FALSE;

    if(bUncall == _TRUE)
    {
#if(_AUDIO_SUPPORT == _ON)
        UserInterfaceGetAudioMuteStatus();
#endif
        UserInterfaceAdjustWaitPanelT2();
        UserInterfaceAdjustWaitPanelT5();

        UserInterfaceGetDisplaySettingBacklightAction();

#if(_TRANSLATOR_SUPPORT == _ON)
        UserInterfaceGetDclkNoSupportStatus();
        UserInterfaceGetDisplaySettingBacklightAction();
        UserInterfaceDisplayInitialization();
        UserInterfaceAdjustDisplayTiming();
        UserInterfaceAdjustInputTiming();
        UserInterfaceAdjustActiveByPassColorProc();
        UserInterfaceAdjustColorProc();

#if(_ULTRA_HDR_SUPPORT == _ON)
        UserInterfaceAdjustHDRColorProcInitial();
        UserInterfaceAdjustHDR2084();
        UserInterfaceAdjustHDRTargetHDR();
        UserInterfaceAdjustHDRTargetSDR();
        UserInterfaceGetHDRModeStatus();
        UserInterfaceGetHDRDarkEnhanceStatus();
#endif

        UserAdjustBacklight(0);
#if(_AUDIO_SUPPORT == _ON)
        UserInterfaceGetAudioVolume();
        UserInterfaceAdjustAudioAmpMuteProc(0);
        UserAdjustAudioVolume(0);
        UserAdjustAudioMuteSwitch();
        UserAdjustAudioVolumeMapping(0);
#endif
#endif
    }
}

//--------------------------------------------------
// Description  : User Power On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceInitial(void)
{
    // Call Uncalled Function for Compile Warning
    UserInterfaceUncallFunction();

    PCB_PWM_SETTING();
    NoneNVRamStartup();

#if(_DP_MST_SUPPORT == _ON)
    ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
#endif

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, _SOURCE_SWITCH_FIXED_PORT);
    UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _ON);

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    UserCommonNVRamSetSystemData(_SEARCH_PORT, _A0_INPUT_PORT);
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    UserCommonNVRamSetSystemData(_SEARCH_PORT, _D0_INPUT_PORT);
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    UserCommonNVRamSetSystemData(_SEARCH_PORT, _D1_INPUT_PORT);
#else
    UserCommonNVRamSetSystemData(_SEARCH_PORT, _A0_INPUT_PORT);
#endif
#endif

    ScalerMcuDdcciSwitchPort(_DEBUG_MODE, UserCommonNVRamGetSystemData(_SEARCH_PORT));
    NoneKeyInitial();
    SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);

#if(_TRANSLATOR_SUPPORT == _OFF)
    // Adjust Backlight
    UserAdjustBacklight(0x80);
#endif
}

//--------------------------------------------------
// Description  : User Power Switch
// Input Value  : ucSwitch --> Power Action
// Output Value : None
//--------------------------------------------------
void UserInterfacePowerSwitch(EnumPowerAction enumSwitch)
{
    switch(enumSwitch)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_ON);

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_ON);

            // Set Monitor Power On Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _ON);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;


        case _POWER_ACTION_AC_ON_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            break;

        case _POWER_ACTION_NORMAL_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_FAKE_OFF_TO_NORMAL:

            UserInterfaceKeyPadLedControl(_LED_POWER_SEARCH);

            break;

        case _POWER_ACTION_NORMAL_TO_FAKE_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            break;

        case _POWER_ACTION_PS_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_OFF);

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NORMAL_TO_FAKE_PS:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            break;

        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_SAVING);

            break;

        case _POWER_ACTION_NORMAL_TO_NOSUPPORT_PS:

            // Update LED Status
            UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT_SAVING);

            UserCommonInterfaceOsdResetProc();

            // Panel pown down.
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);

            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : Keypad Led Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed)
{
#if(_FACTORY_RTD_QC_SUPPORT == _ON)

    ucKeyPadLed = ucKeyPadLed;

#else

    switch(ucKeyPadLed)
    {
        case _LED_POWER_ON:
            PCB_LED_ON();
            break;

        case _LED_POWER_ACTIVE:
            PCB_LED_ACTIVE();
            break;

        case _LED_POWER_SEARCH:
            PCB_LED_IDLE();
            break;

        case _LED_POWER_SAVING:
            PCB_LED_POWER_SAVING();
            break;

        case _LED_POWER_NOSUPPORT:
            PCB_LED_ACTIVE();
            break;

        case _LED_POWER_NOSUPPORT_SAVING:
            PCB_LED_POWER_SAVING();
            break;

        case _LED_POWER_OFF:
            PCB_LED_OFF();
            break;

        case _LED_ALL_OFF:
            PCB_LED_OFF();
            break;

        case _LED_TYPE_1:
            PCB_LED_TYPE1();
            break;

        case _LED_TYPE_2:
            PCB_LED_TYPE2();
            break;

        case _LED_TYPE_3:
            PCB_LED_TYPE3();
            break;

        case _LED_TYPE_4:
            PCB_LED_TYPE4();
            break;

        case _LED_TYPE_5:
            PCB_LED_TYPE5();
            break;

        case _LED_TYPE_FLASH:
            PCB_LED_TYPE_FLASH();
            break;

        default:
            break;
    }

#endif  // End of #if(_FACTORY_RTD_QC_SUPPORT == _OFF)
}

//--------------------------------------------------
// Description  : User OSD Get LogoOn
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetLogoStatus(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Whther to support this timing
// Input Value  : None
// Output Value : TRUE => Go to No Support State
//--------------------------------------------------
bit UserInterfaceGetdNoSupportStatus(void)
{
    // Add User No Support Check
    return _FALSE;
}

//--------------------------------------------------
// Description  : For User to Check Whether to Support Current DCLK
// Input Value  : None
// Output Value : _TRUE => No Support
//--------------------------------------------------
bit UserInterfaceGetDclkNoSupportStatus(void)
{
#if(_TRANSLATOR_SUPPORT == _OFF)

    if((GET_D_CLK_FREQ() > ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ)) ||
       (GET_D_CLK_FREQ() < ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ)))
    {
        DebugMessageScaler("D Clock Exceed Panel Supported Range", GET_D_CLK_FREQ());
        return _TRUE;
    }

#if((_FRC_SUPPORT == _ON) && (_HW_FRC_DOSMODE_ONLY_SUPPORT == _ON))
    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        if((GET_INPUT_TIMING_HWIDTH() > 800) ||
           (GET_INPUT_TIMING_VHEIGHT() > 600))
        {
            DebugMessageScaler("FRC only supports dos-mode timing", 0);
            return _TRUE;
        }
    }
#endif

#endif // End of #if(_TRANSLATOR_SUPPORT == _OFF)

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get whether to by pass normal active process
// Input Value  : None
// Output Value : _TRUE => By pass normal active process
//--------------------------------------------------
bit UserInterfaceGetActiveByPassStatus(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : User Define Whether Cable Status Should Reset
// Input Value  : None
// Output Value : _TRUE => Reset
//--------------------------------------------------
bit UserInterfaceGetCableResetStatus(void)
{
    if((SysSourceGetCableStatusChange(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE) &&
       ((!(SysModeGetModeState() == _MODE_STATUS_SEARCH)) || (SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE)))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Forced Power Saving Status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetForcePSStatus(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : User Check Into Power Saving
// Input Value  : None
// Output Value : True --> User Check Ready to Power Saving
//--------------------------------------------------
bit UserInterfaceGetIntoPSStatus(void)
{
    return _TRUE;
}

//--------------------------------------------------
// Description  : Check Whther ADC Data is Reasonable
// Input Value  : LOAD or SAVE
// Output Value : _TRUE => Reasonable
//--------------------------------------------------
bit UserInterfaceGetNVRamDataStatus(EnumNvramCheckType enumNvramCheckType)
{
    switch(enumNvramCheckType)
    {
#if(_VGA_SUPPORT == _ON)
        case _CHECK_ADC_LOAD:

            if(g_stAdcData.ucAdcPGA >= 0xF0)
            {
                // Assign Prefered Value
                g_stAdcData.ucAdcPGA = 8;
            }

            break;

        case _CHECK_ADC_SAVE:

            if(g_stAdcData.ucAdcPGA >= 0xF0)
            {
                return _FAIL;
            }
            break;
#endif

        case _CHECK_SYSTEM_DATA_LOAD:
        case _CHECK_SYSTEM_DATA_SAVE:
        case _CHECK_MODE_USER_DATA_LOAD:
        case _CHECK_MODE_USER_DATA_SAVE:

            break;

        default:
            break;
    }

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Get backlight staus when performing display setting
// Input Value  : None
// Output Value : _ENABLE or _DISABLE
//--------------------------------------------------
bit UserInterfaceGetDisplaySettingBacklightAction(void)
{
#if((_PANEL_STYLE == _PANEL_DPTX) ||\
    (_PANEL_STYLE == _PANEL_VBO))

    return _DISABLE;

#else

    return _ENABLE;

#endif
}

#if(_OVERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
bit UserInterfaceGetOverScanStatus(void)
{
    bit bDoOverScan = _FALSE;
    BYTE ucTemp = 0;
    WORD code tusOverscanEnTable[][3] =
    {
        // VFreq, HWidth, VHeight,
        {600,  640,  480},    // 480p
        {600,  720,  480},    // 480p
        {600,  960,  480},    // 480p
        {600, 1440,  480},    // 480p

        {500,  720,  576},    // 576p
        {500,  768,  576},    // 576p
        {500,  960,  576},    // 576p
        {500, 1280,  576},    // 576p
        {500, 1440,  576},    // 576p
        {500, 1280,  720},    // 720p
        {600, 1280,  720},    // 720p
        {500, 1920,  1080},   // 1080p
        {600, 1920,  1080},   // 1080p

        // Don't delete it, and place it at last.
        {  0,    0,    0},
    };

    if(GET_OSD_OVERSCAN_STATUS() == _OFF)
    {
        return _FALSE;
    }

    // Decide whether to do over scan
    switch(SysSourceGetSourceType())
    {
#if(_OVERSCAN_VGA_SUPPORT == _ON)
        case _SOURCE_VGA:

            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(GET_VGA_COLOR_FORMAT_STATUS() == _COLOR_SPACE_RGB)
            {
                break;
            }

            while(tusOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tusOverscanEnTable[ucTemp][0]) < 10) &&
                   (abs(GET_INPUT_TIMING_HWIDTH() - tusOverscanEnTable[ucTemp][1]) < 2) &&
                   (GET_INPUT_TIMING_VHEIGHT() == tusOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }

            break;
#endif // End of #if(_OVERSCAN_VGA_SUPPORT == _ON)

#if(_OVERSCAN_DVI_SUPPORT != _ON)
        case _SOURCE_DVI:
            break;
#endif

#if(_OVERSCAN_HDMI_SUPPORT != _ON)
        case _SOURCE_HDMI:
            break;
#endif

#if(_OVERSCAN_DP_SUPPORT == _ON)
        case _SOURCE_DP:
            break;
#endif

        default:
#if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))
            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(ScalerColorGetColorSpaceRGB(ScalerColorGetColorSpace()) == _TRUE)
            {
                break;
            }

            while(tusOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tusOverscanEnTable[ucTemp][0]) < 10) &&
                   (abs(GET_INPUT_TIMING_HWIDTH() - tusOverscanEnTable[ucTemp][1]) < 2) &&
                   (GET_INPUT_TIMING_VHEIGHT() == tusOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }
#endif // End of #if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))

            break;
    }

    return bDoOverScan;
}

#endif // End of #if(_OVERSCAN_SUPPORT == _ON)

#if(_ASPECT_RATIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Aspect Ratio
// Input Value  : enumSelRegion --> select region
// Output Value : aspect ration type
//--------------------------------------------------
EnumAspectRatioType UserInterfaceGetAspectRatioType(void)
{
    return _ASPECT_RATIO_FULL;
}

//--------------------------------------------------
// Description  : Get user H/V aspect ratio values
// Input Value  : enumSelRegion --> select region
//                usHRatio, usVRatio --> aspect ratio
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetAspectRatio(WORD *pusHRatio, WORD *pusVRatio)
{
    pusHRatio = pusHRatio;
    pusVRatio = pusVRatio;
}

//--------------------------------------------------
// Description  : User defined aspect ratio process
// Input Value  : select region
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAspectRatio(void)
{
}

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get aspect original mode ratio
// Input Value  : select region
// Output Value : Retion display ratio in aspect ratio original mode (0x00 ~ 0xFF)
//--------------------------------------------------
BYTE UserInterfaceGetAspectRatioOriginalRatio(void)
{
    return 0xFF;
}
#endif
#endif // End of #if(_ASPECT_RATIO_SUPPORT == _ON)

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get current rotation degree
// Input Value  : None
// Output Value : rotation degree
//--------------------------------------------------
EnumRotationType UserInterfaceGetRotationDegree(void)
{
    switch(GET_OSD_DISP_ROTATE())
    {
        default:
        case _DISP_ROTATE_0:
            return _ROT_DISABLE;

#if (_DISPLAY_ROTATION_90_SUPPORT == _ON)
        case _DISP_ROTATE_90:
            return _ROT_CW90;
#endif
#if (_DISPLAY_ROTATION_180_SUPPORT == _ON)
        case _DISP_ROTATE_180:
            return _ROT_CW180;
#endif
#if (_DISPLAY_ROTATION_270_SUPPORT == _ON)
        case _DISP_ROTATE_270:
            return _ROT_CW270;
#endif
    }
}

//--------------------------------------------------
// Description  : Get current rotation type
// Input Value  : None
// Output Value : rotation type
//--------------------------------------------------
EnumRotationDisplayType UserInterfaceGetRotationDisplayType(void)
{
    switch(GET_OSD_DISP_ROTATION_SIZE_TYPE())
    {
        default:
        case _OSD_ROTATE_DISPLAY_FULL:
            return _ROT_FULL;

        case _OSD_ROTATE_DISPLAY_PIXEL_BY_PIXEL:
            return _ROT_PIXEL_BY_PIXEL;

        case _OSD_ROTATE_DISPLAY_KEEP_SRC_ASPECT_RATIO:
            return _ROT_KEEP_SRC_ASPECT_RATIO;
    }
}
#endif  // #if(_DISPLAY_ROTATION_SUPPORT == _ON)

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Display Latency Ratio
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceGetDisplayLatencyRatio(void)
{
    switch(GET_OSD_LATENCY())
    {
        default:
            break;

        case _LATENCY_L:
            return 0;   // 0%

        case _LATENCY_M:
            return 50;  // 50%

        case _LATENCY_H:
            return 100; // 100%
    }

    return 0;
}
#endif

#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Max/Min Freq according to latency
// Input Value  : None
// Output Value : max/min freq
//--------------------------------------------------
void UserInterfaceGetDVMaxMinFreq(StructDVCustomizedFreq *pstDVCustomizedFreq)
{
    pstDVCustomizedFreq = pstDVCustomizedFreq;

#if(_MN_FINE_TUNE_LASTLINE_SUPPORT == _ON)
    if((SysSourceGetInputPort() == _A0_INPUT_PORT) ||
       (GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE))
    {
        pstDVCustomizedFreq->b1FORCETOFREERUN = _ENABLE;
    }
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
    switch (GET_OSD_LATENCY())
    {
        default:
        case _LATENCY_H:
        case _LATENCY_M:
        case _LATENCY_L:

            pstDVCustomizedFreq->usMaxFreq = _PANEL_MAX_FRAME_RATE;
            pstDVCustomizedFreq->usTypFreq = _PANEL_TYP_FRAME_RATE;
            pstDVCustomizedFreq->usMinFreq = _PANEL_MIN_FRAME_RATE;
            break;
    }
#endif
}
#endif

#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get OD enable status
// Input Value  : None
// Output Value : function enable status
//--------------------------------------------------
EnumFunctionOnOFF UserInterfaceGetODEnableStatus(void)
{
    return GET_OSD_OD_STATUS();
}
#endif


#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR3) && (_DDR3_MULTIPHASE_EXIST == _ON))
//--------------------------------------------------
// Description  : Get DDR3 Phase From GPIO or DDCCI command
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceUpdateDDR3PhaseData(void)
{
    StructDDR3PhaseInfo stUserVedorDdr3PhaseData = {_DDR3_PLL_INITIAL_PHASE_0, _DDR3_PLL_INITIAL_PHASE_1, _DDR3_READ_DQ_DLYN_TAP};
    ScalerPLLGetDDR3PhaseData(&stUserVedorDdr3PhaseData);
}
#endif

#if(_USER_SYSTEM_EEPROM_CUSTOMIZATION == _ON)
//--------------------------------------------------
// Description  : User Custom Check Proc when System Eeprom Read
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to read
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserInterfaceSystemEepromReadCustomProc(WORD usSubAddr, WORD usLength, BYTE *pucReadArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucReadArray = pucReadArray;
    return _SUCCESS;
}

//--------------------------------------------------
// Description  : User Custom Check Proc when System Eeprom Write
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to write
//                pReadArray   --> Result array
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserInterfaceSystemEepromWriteCustomProc(WORD usSubAddr, WORD usLength, BYTE *pucWriteArray)
{
    usSubAddr = usSubAddr;
    usLength = usLength;
    pucWriteArray = pucWriteArray;
    return _SUCCESS;
}
#endif

//--------------------------------------------------
// Description  : Modify display Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceDisplayInitialization(void)
{
}

//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : Current Input Timing Info
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserInterfaceAdjustInputTiming(void)
{
}

//--------------------------------------------------
// Description  : Modify Display Timing Based on User Requirement
// Input Value  : Current Display Timing Info
// Output Value : Modified Display Timing
//--------------------------------------------------
void UserInterfaceAdjustDisplayTiming(void)
{
#if(_PANEL_STYLE == _PANEL_LVDS)
    // Check display format resolution according to LVDS port count
    SET_MDOMAIN_OUTPUT_HSTART(GET_MDOMAIN_OUTPUT_HSTART() + (GET_MDOMAIN_OUTPUT_HSTART() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HWIDTH(GET_MDOMAIN_OUTPUT_HWIDTH() - (GET_MDOMAIN_OUTPUT_HWIDTH() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HBSTART(GET_MDOMAIN_OUTPUT_HBSTART() + (GET_MDOMAIN_OUTPUT_HBSTART() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HBWIDTH(GET_MDOMAIN_OUTPUT_HBWIDTH() - (GET_MDOMAIN_OUTPUT_HBWIDTH() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
#endif
}

#if(_UNDERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceAdjustUnderScan(void)
{
    return _FALSE;
}
#endif

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceGetRGBQuantizationLimitRangeStatus(EnumColorRGBQuantization enumColorRGBQuantization)
{
    switch(enumColorRGBQuantization)
    {
        case _RGB_QUANTIZATION_FULL_RANGE:
        case _RGB_QUANTIZATION_DEFAULT_RANGE:
        case _RGB_QUANTIZATION_RESERVED:
        default:

            return _FALSE;

        case _RGB_QUANTIZATION_LIMIT_RANGE:

            return _TRUE;
    }
}
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if YCC Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceGetYCCQuantizationFullRangeStatus(EnumColorYCCQuantization enumColorYCCQuantization)
{
    return (enumColorYCCQuantization == _YCC_QUANTIZATION_FULL_RANGE);
}
#endif

//--------------------------------------------------
// Description  : Set Color in pass normal active process
// Input Value  : None
// Output Value : void
//--------------------------------------------------
void UserInterfaceAdjustActiveByPassColorProc(void)
{
    return;
}

//--------------------------------------------------
// Description  : Set User Required Color Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustColorProc(void)
{
#if(_TRANSLATOR_SUPPORT == _OFF)
    // Adjust Color Space
    SysModeColorSpaceConvert(ScalerColorGetColorSpace(), _DB_APPLY_NONE);

    // Adjust Backlight
    UserAdjustBacklight(0x80);

    // Adjust Brightness & Contrast
#if(_BRIGHTNESS_SUPPORT == _ON)
#if(_BRI_TYPE == _BRI_GEN_1_10BIT)
    UserAdjustBrightness(0x200);
#else
    UserAdjustBrightness(0x080);
#endif
#endif // End of #if(_BRIGHTNESS_SUPPORT == _ON)

#if(_CONTRAST_SUPPORT == _ON)
#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
    UserAdjustContrast(0x800);
#else
    UserAdjustContrast(0x080);
#endif
#endif // End of #if(_CONTRAST_SUPPORT == _ON)

    // Adjust Sharpness
#if(_SHARPNESS_SUPPORT == _ON)
    UserCommonAdjustSharpness(SysSourceGetInputPort());
#endif

    // Adjust Transparency
    ScalerOsdSetTransparency(2);
    ScalerOsdSetTransparencyType(_OSD_TRANSPARENCY_DISABLE);

    // Adjust Gamma On/Off
#if(_GAMMA_FUNCTION == _ON)
    ScalerColorOutputGammaEnable(_FUNCTION_OFF);
#endif

#if(_RGB_GAMMA_FUNCTION == _ON)
    ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif

    // Adjust Hue & Saturation
#if(_GLOBAL_HUE_SATURATION == _ON)
    UserAdjustGlobalHueSat(_DEFAULT_HUE, _DEFAULT_SATURATION);
#endif

    // Adjust ICM On/Off
#if(_ICM_SUPPORT == _ON)
    ScalerColorICMEnable(_FUNCTION_OFF);
#endif

    // Adjust DCC On/Off
#if(_DCC_FUNCTION == _ON)
    ScalerColorDCCEnable(_FUNCTION_OFF);
#endif

    // Adjust Ypeaking On/Off
#if(_YPEAKING_SUPPORT == _ON)
    ScalerColorYpeaking(_OFF);
#endif

    // Adjust Highlight Window Type & On/Off
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWEnable(_FUNCTION_OFF, _DB_APPLY_NO_POLLING);
#endif

#if(_OD_SUPPORT == _ON)
    ScalerODAdjustDeltaGain(0x40);
#endif // End of #if(_OD_SUPPORT == _ON)

    // Adjust UltraVivid
#if(_ULTRA_VIVID_SUPPORT == _ON)
    ScalerColorUltraVividEnable(_FUNCTION_OFF, _DB_APPLY_POLLING);
#endif
#endif // End of #if(_TRANSLATOR_SUPPORT == _OFF)
}

#if(_ULTRA_HDR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Initial HDR Auto Mode using in UserInterfaceAdjustColorProc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustHDRColorProcInitial(void)
{
    if(GET_HDR_EOTF() == _HDR_INFO_EOTF_SMPTE_ST_2084)
    {
        UserCommonAdjustHDRAutoMode(_OFF);
    }
    else
    {
        ScalerColorOutputGammaEnable(_FUNCTION_OFF);
        ScalerColorSRGBEnable(_FUNCTION_OFF);
        ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);
    }
}

//--------------------------------------------------
// Description  : Adjust HDR 2084 force mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustHDR2084(void)
{
    ScalerColorOutputGammaEnable(_FUNCTION_OFF);
    ScalerColorSRGBEnable(_FUNCTION_OFF);
    ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);
}

//--------------------------------------------------
// Description  : Adjust SDR to HDR flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustHDRTargetHDR(void)
{
    UserAdjustBacklight(_BACKLIGHT_MAX);
}

//--------------------------------------------------
// Description  : Adjust HDR to SDR flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustHDRTargetSDR(void)
{
    UserAdjustBacklight(_BACKLIGHT_CENTER);
}

//--------------------------------------------------
// Description  : Get OSD HDR Mode Status
// Input Value  : None
// Output Value : OSD HDR MODE OFF/AUTO/_HDR_MODE_SMPTE_ST_2084
//--------------------------------------------------
EnumHDRModeDef UserInterfaceGetHDRModeStatus(void)
{
    return _HDR_MODE_OFF;
}

//--------------------------------------------------
// Description  : Get OSD HDR Dark Enhance Status
// Input Value  : None
// Output Value : OSD Dark Enahnce ON/OFF
//--------------------------------------------------
bit UserInterfaceGetHDRDarkEnhanceStatus(void)
{
    return _OFF;
}
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set UltraVivid Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustUltraVivid(void)
{
    BYTE ucUltraVividStatus = 1;

    ScalerColorUltraVividEnable(_FUNCTION_OFF, _DB_APPLY_NONE);
    ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[ucUltraVividStatus - 1], GET_CURRENT_BANK_NUMBER());
}

//--------------------------------------------------
// Description  : UltraVivid Proccess
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustUltraVividProc(EnumDBApply enumDBApply)
{
    ScalerColorUltraVividEnable(_FUNCTION_OFF, enumDBApply);
}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_SHARPNESS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Sharpness Coef
// Input Value  : SU Coef Type
// Output Value : SU Coef
//--------------------------------------------------
code BYTE *UserInterfaceGetSharpnessCoef(EnumSUCoefType enumSUCoefType, EnumSourceSearchPort enumSourceSearchPort)
{
    enumSourceSearchPort = enumSourceSearchPort;

    switch(enumSUCoefType)
    {
#if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))
        case _H_V_SU_128TAPS_NORMAL:
            return tSCALE_128TAPS_NORMAL_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif

#if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))
        case _H_V_SU_96TAPS_NORMAL:
            return tSCALE_96TAPS_NORMAL_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif

#if(_HSU_128TAPS_SUPPORT == _ON)
        case _H_SU_128TAPS_1_TO_1:
            return tSCALE_128TAPS_1to1_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif

#if(_HSU_96TAPS_SUPPORT == _ON)
        case _H_SU_96TAPS_1_TO_1:
            return tSCALE_96TAPS_1to1_COEF_TABLE[GET_OSD_SHARPNESS()];
#endif
        default:
            return _NULL_POINTER;
    }
}

//--------------------------------------------------
// Description  : Get Sharpness Coef BankNum
// Input Value  : None
// Output Value : BankNum
//--------------------------------------------------
BYTE UserInterfaceGetSharpnessCoefBankNum(void)
{
    return GET_CURRENT_BANK_NUMBER();
}

//--------------------------------------------------
// Description  : User Bypass Check
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceSharpnessBypassCheck(void)
{
    return _FALSE;
}
#endif // End of #if(_SHARPNESS_SUPPORT == _ON)

#if(_DCR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Adjust DCR
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustDCR(void)
{
    PDATA_DWORD(0) = ScalerColorDCRReadResult(_DCR_ABOVE_TH1_NUM);
}
#endif // End of #if(_DCR_SUPPORT == _ON)

//--------------------------------------------------
// Description  : OSD Power On Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdPowerOnInitial(void)
{
    // Adjust Dither Table
    ///UserAdjustLoadDitherTable();

    // Adjust DCR Threshold & Source
#if(_DCR_SUPPORT == _ON)

#if(_DCR_BIT_MODE == _DCR_10BIT)
    ScalerColorDCRAdjust(_DCR_THESHOLD1, _DCR_THESHOLD2, _MEASURE_AVERAGE);
#elif(_DCR_BIT_MODE == _DCR_8BIT)
    ScalerColorDCRAdjust((_DCR_THESHOLD1 >> 2), (_DCR_THESHOLD2 >> 2), _MEASURE_AVERAGE);
#endif

#endif

    // Adjust Highlight Window Border
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWBorderAdjust((_HLW_BORDER_BOTTOM | _HLW_BORDER_LEFT | _HLW_BORDER_RIGHT | _HLW_BORDER_TOP), 255, 0, 0);
#endif

#if(_OD_SUPPORT == _ON)
    UserAdjustOD();
#endif

#if(_TRANSLATOR_SUPPORT == _OFF)
#if(_AUDIO_SUPPORT == _ON)
    // Set Default Audio Volume
    ScalerAudioDigitalAdjustVolume(0xFFFF);
#endif
#endif
}

//--------------------------------------------------
// Description  : OSD Active Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdActiveProc(void)
{
    if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
       (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
    {
        UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
        UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
        UserCommonNVRamSaveSystemData();
    }

    if(UserInterfaceGetActiveByPassStatus() == _FALSE)
    {
        // DDCCI switch to active port
        ScalerMcuDdcciSwitchPort(_ON, SysSourceGetInputPort());

#if(_VGA_SUPPORT == _ON)
        if((SysSourceGetSourceType() == _SOURCE_VGA) && (UserInterfaceGetFirstAutoConfigStatus() == _TRUE))
        {
            ///SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_CONFIG_MSG);
        }
#endif
    }

#if(_TRANSLATOR_SUPPORT == _OFF)
    ScalerDDomainBackgroundEnable(_DISABLE);
#endif

#if(_FREEZE_SUPPORT == _ON)
    UserCommonAdjustDisplayFreeze(_OFF);
#endif
}

//--------------------------------------------------
// Description  : OSD Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdResetProc(void)
{
}


#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check ModeIndex
// Input Value  : System ModeIndex
// Output Value : ModeIndex
//--------------------------------------------------
BYTE UserInterfaceGetVGAConfuseMode(BYTE ucModeIndex)
{
    if((ucModeIndex == _MODE_640x480_60HZ) || (ucModeIndex == _MODE_720x480_60HZ_GTF) || (ucModeIndex == _MODE_720x480p_60HZ))
    {
        if(GET_INPUT_TIMING_VSYNCWIDTH() <= 4)
        {
            ucModeIndex = _MODE_640x480_60HZ;

            DebugMessageAnalog("Detected by Special Case to 640x480-60", _MODE_640x480_60HZ);
        }
        else if((GET_INPUT_TIMING_H_POLARITY() == _FALSE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_720x480_60HZ_GTF;

            DebugMessageAnalog("Detected by Special Case to 720x480-60_GTF", _MODE_720x480_60HZ_GTF);
        }
        else
        {
            ucModeIndex = _MODE_720x480p_60HZ;

            DebugMessageAnalog("Detected by Special Case to 720x480-60", _MODE_720x480p_60HZ);
        }
    }

    if((ucModeIndex == _MODE_720x400_70HZ) || (ucModeIndex == _MODE_640x400_70HZ))
    {
        if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_640x350_70HZ;

            DebugMessageAnalog("Detected by Special Case to _MODE_640x350_70HZ", _MODE_640x350_70HZ);
        }
    }

    if((ucModeIndex == _MODE_640x400_85HZ) || (ucModeIndex == _MODE_720x400_85HZ))
    {
        if((GET_INPUT_TIMING_H_POLARITY() == _TRUE) && (GET_INPUT_TIMING_V_POLARITY() == _FALSE))
        {
            ucModeIndex = _MODE_640x350_85HZ;
        }

        DebugMessageAnalog("Detected by Special Case to _MODE_640x350_85HZ", _MODE_640x350_85HZ);
    }

    return ucModeIndex;
}

//--------------------------------------------------
// Description  : Check Load Mode Table Value
// Input Value  : None
// Output Value : _TURE -> Force Load Mode Table Value
//--------------------------------------------------
bit UserInterfaceGetLoadModeTableDefaultStatus(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : Check VGA First Auto Config
// Input Value  : None
// Output Value : _TRUE => Do Auto Config
//--------------------------------------------------
bit UserInterfaceGetFirstAutoConfigStatus(void)
{
    if((GET_VGA_MODE_DO_FIRST_AUTO() == _TRUE) &&
       (GET_INPUT_TIMING_HWIDTH() > 720))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Percentage of AutoConfig
// Input Value  : Percentage
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetAutoConfigPercentage(BYTE ucAutoPercentage)
{
    ucAutoPercentage = ucAutoPercentage;
}

#if(_VGA_FORCE_DISPLAY == _ON)
//--------------------------------------------------
// Description  : VGA Mode Search User Flow
// Input Value  : None
// Output Value : Mode Number
//--------------------------------------------------
BYTE UserInterfaceModeSearchModeVGA(void)
{
    return 0;
}
#endif

//--------------------------------------------------
// Description  : VGA Auto Config Flow control for V position
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceSkipAutoVpos(void)
{
    return _FALSE;
}

//--------------------------------------------------
// Description  : VGA Auto Config Flow control for H position
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceSkipAutoHpos(void)
{
    return _FALSE;
}
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_MHL_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User RCP Handler
// Input Value  : RCP Key Code
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceAdjustMHLMscRCPProc(BYTE ucKeyCode)
{
    // Check RCP Key Code
    switch(ucKeyCode)
    {
        default:
            return _FALSE;
            break;
    }

    return _TRUE;
}
#endif

#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Decide whether to Enable FREESYNC Function
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
bit UserInterfaceGetFREESYNCEnable(void)
{
    return _TRUE;
}
#endif

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DP Version
// Input Value  : RCP Key Code
// Output Value : DP_VERSION_1_1 or DP_VERSION_1_2
//--------------------------------------------------
EnumDpVersionType UserInterfaceGetDPVersion(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            return _DP_VERSION_1_2;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            return _DP_VERSION_1_2;
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:

            return _DP_VERSION_1_2;
#endif
        default:

            break;
    }

    return _DP_VERSION_1_1;
}

//--------------------------------------------------
// Description  : Get DP Lane Count
// Input Value  : InputPort
// Output Value : DP Lane Count
//--------------------------------------------------
EnumDpLaneCount UserInterfaceGetDpLaneCount(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:
            return _D0_DP_MAIN_LINK_LANES;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:
            return _D1_DP_MAIN_LINK_LANES;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:
            return _D2_DP_MAIN_LINK_LANES;
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:
            return _D6_DP_MAIN_LINK_LANES;
#endif
        default:
            break;
    }

    return _DP_LINK_4_LANE;
}

//--------------------------------------------------
// Description  : Get Dp MST Capable Port
// Input Value  : None
// Output Value : _DP_MST_RX0 or _DP_MST_RX1
//--------------------------------------------------
EnumDPMSTPort UserInterfaceGetDpMSTCapablePort(void)
{
#if(_DP_MST_SUPPORT == _OFF)

    return _DP_MST_NO_PORT;
#else

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D1_INPUT_PORT_TYPE != _D1_DP_PORT))

#if(_D0_DP_MST_PORT_SUPPORT == _ON)
    if(UserInterfaceGetDPVersion(_D0_INPUT_PORT) >= _DP_VERSION_1_2)
    {
        return _DP_MST_RX0_PORT;
    }
    else
#endif
    {
        return _DP_MST_NO_PORT;
    }
#elif((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D0_INPUT_PORT_TYPE != _D0_DP_PORT))

#if(_D1_DP_MST_PORT_SUPPORT == _ON)
    if(UserInterfaceGetDPVersion(_D1_INPUT_PORT) >= _DP_VERSION_1_2)
    {
        return _DP_MST_RX1_PORT;
    }
    else
#endif
    {
        return _DP_MST_NO_PORT;
    }
#elif((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_PORT))

    if(SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT)
    {
#if(_D0_DP_MST_PORT_SUPPORT == _ON)
        if(SysSourceGetInputPort() == _D0_INPUT_PORT)
        {
            if(UserInterfaceGetDPVersion(_D0_INPUT_PORT) >= _DP_VERSION_1_2)
            {
                return _DP_MST_RX0_PORT;
            }
            else
            {
                return _DP_MST_NO_PORT;
            }
        }
        else
#endif

#if(_D1_DP_MST_PORT_SUPPORT == _ON)
        if(SysSourceGetInputPort() == _D1_INPUT_PORT)
        {
            if(UserInterfaceGetDPVersion(_D1_INPUT_PORT) >= _DP_VERSION_1_2)
            {
                return _DP_MST_RX1_PORT;
            }
            else
            {
                return _DP_MST_NO_PORT;
            }
        }
        else
#endif
        {
            return _DP_MST_NO_PORT;
        }
    }

    return _DP_MST_NO_PORT;
#endif // End of #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D1_INPUT_PORT_TYPE != _D1_DP_PORT))
#endif // End of #if(_DP_MST_SUPPORT == _OFF)
}

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Decide whether to Clone output to DP Tx
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetDpCloneOutputStatus(void)
{
    return _TRUE;
}
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) || (_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP))
//--------------------------------------------------
// Description  : User Select Externel DP Switch
// Input Value  : None
// Output Value : Only Return _D0_INPUT_PORT or _D6_INPUT_PORT
//--------------------------------------------------
BYTE UserInterfaceGetDpSwitchSelectPort(void)
{
    return _D0_INPUT_PORT;
}
#endif

#endif // End of #if(_DP_SUPPORT == _ON)

#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
//--------------------------------------------------
// Description  : User Report HDMI +5V Status
// Input Value  : D0/D1/D2 Port
// Output Value : _TURE --> +5V exist
//--------------------------------------------------
bit UserInterfaceGetHdmi5VStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _TRUE;
        case _D1_INPUT_PORT:
            return _TRUE;
        case _D2_INPUT_PORT:
            return _TRUE;
        default:
            return _TRUE;
    }
}
#endif

#if(_SOURCE_AUTO_SEARCH_STYLE == _SOURCE_POLLING_EIZO_STYLE)
//--------------------------------------------------
// Description  : User check search is finish or not
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
bit UserInterfaceAdjustOsdCheckTotalSearchFinish(void)
{
    return _TRUE;
}

//--------------------------------------------------
// Description  : Determine the search time of each source
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustSourceSearchTime(void)
{
}

//--------------------------------------------------
// Description  : User Report Eizo Search Finish Time
// Input Value  : None
// Output Value : Search Finish Time
//--------------------------------------------------
WORD UserInterfaceGetEizoSearchFinishTime(void)
{
    return 0;
}
#endif

#if(_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Determine whether to User is Ready to play audio
// Input Value  : None
// Output Value : _TRUE => Free to Play
//--------------------------------------------------
bit UserInterfaceGetAudioReadyToPlayStatus(void)
{
    if(UserInterfaceGetAudioMuteStatus() != _ON)
    {
        if(UserInterfaceGetAudioSource() == _DIGITAL_AUDIO)
        {
            if(ScalerAudioGetAudioDetected(SysSourceGetInputPort()) == _TRUE)
            {
                if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) || (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK))
                {
                    return _TRUE;
                }
            }
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get Current Audio Mute Status
// Input Value  : Node
// Output Value : Node
//--------------------------------------------------
bit UserInterfaceGetAudioMuteStatus(void)
{
    return _OFF;
}

//--------------------------------------------------
// Description  : User OSD Get Audio Source
// Input Value  : None
// Output Value : _DIGITAL_AUDIO or _LINE_IN_AUDIO
//--------------------------------------------------
EnumAudioInputSource UserInterfaceGetAudioSource(void)
{
    switch(SysSourceGetSourceType())
    {
        case _SOURCE_HDMI:
        case _SOURCE_DP:

            return _DIGITAL_AUDIO;

        case _SOURCE_VGA:
        case _SOURCE_DVI:

            return _LINE_IN_AUDIO;

        default:

            break;
    }
    return _LINE_IN_AUDIO;
}

//--------------------------------------------------
// Description  : User Decide whether to play non-LPCM Audio
// Input Value  : None
// Output Value : _ON => Mute Audio
//--------------------------------------------------
bit UserInterfaceGetAudioNonLPCMStatus(void)
{
    if(ScalerAudioLPCMCheckData(SysSourceGetInputPort()) == _TRUE)
    {
#if(_HDMI_SUPPORT == _ON)
        if(SysSourceGetSourceType() == _SOURCE_HDMI)
        {
            if(ScalerAudioLPCMCheckInfo(SysSourceGetInputPort()) == _TRUE)
            {
                return _OFF;
            }
            else
            {
                return _ON;
            }
        }
#endif

        return _OFF;
    }

    return _ON;
}

//--------------------------------------------------
// Description  : Get Current Audio Volume
// Input Value  : None
// Output Value : Current Volume
//--------------------------------------------------
WORD UserInterfaceGetAudioVolume(void)
{
    return 0x3FFF;
}

#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DAC Output Switch
// Input Value  : None
// Output Value : EnumAudioDACOutput
//--------------------------------------------------
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void)
{
    return _AUDIO_DAC_OUTPUT_BOTH;
}

//--------------------------------------------------
// Description  : Get if Keep Audio Depop State
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit UserInterfaceGetAudioDACKeepDepopState(void)
{
    return _FALSE;
}
#endif

#if(_SLEEP_AUDIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Current Audio Stand Alone Status
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
bit UserInterfaceGetAudioStandAloneStatus(void)
{
    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : User Audio Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAudioResetProc(void)
{
#if(_SLEEP_AUDIO_SUPPORT == _ON)
    if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
    {
        // if Currently playing digital audio
        if((SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (UserInterfaceGetAudioSource() == _DIGITAL_AUDIO))
        {
#if(((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP))))
            if(SysSourceGetAudioPlaybackPort() != SysSourceGetInputPort())
#endif
            {
                DebugMessageAudio("User Audio Reset Process", 0x00);

                SysAudioMuteProc(_ON);
            }
        }
    }
    else
#endif
    {
        if(SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)
        {
            DebugMessageAudio("User Audio Reset Process", 0x00);

            SysAudioMuteProc(_ON);
        }
    }
}

//--------------------------------------------------
// Description  : Audio Power Process
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
void UserInterfaceAdjustAudioPowerProc(EnumPowerStatus enumPowStatus)
{
    if(enumPowStatus == _POWER_STATUS_NORMAL)
    {
        // Add User interface function

    }
    else if(enumPowStatus == _POWER_STATUS_SAVING)
    {
        // Add User interface function
    }
    else
    {
        // Add User interface function
    }
}

//--------------------------------------------------
// Description  : Control User Audio Mute Process
// Input Value  : bMute
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAudioAmpMuteProc(bit bMute)
{
    bMute = bMute;

#if(_EMBEDDED_DAC_SUPPORT == _ON)
    if(UserInterfaceGetAudioDACOutput() == _AUDIO_DAC_OUTPUT_BOTH)
    {
        PCB_AMP_MUTE(bMute);
    }
#endif
}

#if((_LINE_IN_SUPPORT == _ON) && (_HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP == _ON))
//--------------------------------------------------
// Description  : Swap External Audio Codec Input for Line in
// Input Value  : _TRUE or _FALSE
// Output Value : None
//--------------------------------------------------
void UserInterfaceSwapExternalAudioCodecInput(bit bSwap)
{
    if(bSwap == _TRUE)
    {
        // Swap External Audio Codec Input(L/R)
    }
    else
    {
        // No Swap External Audio Codec Input(L/R)
    }
}
#endif

#endif // End of #if(_AUDIO_SUPPORT == _ON)

#if(_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Decide Wether Support USB Hub
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserInterfaceTypecUSBSupport(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            return _TRUE;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return _TRUE;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            return _TRUE;
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:

            return _TRUE;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceTypecGetUSBSupportStatus(BYTE ucInputPort)
{
    if((SysPowerGetPowerStatus() == _POWER_STATUS_OFF) && ((GET_DP_DC_OFF_HPD_HIGH() == _OFF) || (UserInterfaceGetDpMSTCapablePort() != _DP_MST_NO_PORT)))
    {
        return _OFF;
    }

    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            if(GET_OSD_DP_D0_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            if(GET_OSD_DP_D1_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;

#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            if(GET_OSD_DP_D2_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;

#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:
            if(GET_OSD_DP_D6_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;

#endif

        default:
            break;
    }

    return _OFF;
}

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB)
//--------------------------------------------------
// Description  : User decided how many lanes to switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTypecSwitchDPLaneByUsbHubStatus(void)
{
    BYTE ucUsbHubInfo = 0x00;

#if(_D0_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D0_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D0_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D0_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D0_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D0_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D0_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D0_LANES));
    }
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D1_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D1_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D1_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D1_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D1_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D1_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D1_LANES));
    }
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D2_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D2_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D2_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D2_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D2_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D2_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D2_LANES));
    }
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D6_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D6_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D6_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D6_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D6_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D6_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D6_LANES));
    }
#endif
}
#endif

#if(_D0_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D0 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD0PortControllerPower(void)
{
    return _ON;
}
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D1 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD1PortControllerPower(void)
{
    return _ON;
}
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D2 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD2PortControllerPower(void)
{
    return _ON;
}
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D6 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD6PortControllerPower(void)
{
    return _ON;
}
#endif

//--------------------------------------------------
// Description  : User Decition Port Controller whether Enter Alt Mode
// Input Value  : ucInputPort --> Inputput
// Output Value : Decition Alt Mode result
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerCheckAltMode(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _FAIL;
            break;

        case _D1_INPUT_PORT:
            return _FAIL;
            break;

        case _D2_INPUT_PORT:
            return _FAIL;
            break;

        case _D3_INPUT_PORT:
            return _FAIL;
            break;

        default:
            break;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Alt Mode Decition By User Flow Support
// Input Value  : ucInputPort --> Inputput
// Output Value : _TRUE: Adopt User Flow, _FALSE: Adopt Kernal Flow
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerAltModeUserFlow(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _FALSE;
            break;

        case _D1_INPUT_PORT:
            return _FALSE;
            break;

        case _D2_INPUT_PORT:
            return _FALSE;
            break;

        case _D3_INPUT_PORT:
            return _FALSE;
            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Cable Check By User Flow Support
// Input Value  : ucInputPort --> Inputput
// Output Value : _TRUE: Adopt User Flow, _FALSE: Adopt Kernal Flow
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerCableCheckUserFlow(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _FALSE;
            break;

        case _D1_INPUT_PORT:
            return _FALSE;
            break;

        case _D2_INPUT_PORT:
            return _FALSE;
            break;

        case _D3_INPUT_PORT:
            return _FALSE;
            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get OSD lane Sel Mode
// Input Value  : ucInputPort --> Input Port
// Output Value : Lane Sel mode
//--------------------------------------------------
BYTE UserInterfaceTypeCGetOsdLaneSelMode(BYTE ucInputPort)
{
    BYTE ucLaneMode = _DP_LANE_AUTO_MODE;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D0_LANE_MODE();
            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D1_LANE_MODE();
            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D2_LANE_MODE();
            break;
#endif


#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D6_LANE_MODE();
            break;
#endif
        default:
            break;
    }

    return ucLaneMode;
}

#if(_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : 5400 PD current & voltage calculate
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserInterfaceTypeCPDO(BYTE ucInputPort)
{
    WORD usTemp = 0;

    if(UserCommonPortControllerGetPdReadyFlag(ucInputPort) == _TRUE)
    {
	    if(UserCommonPortControllerGetPDOStatus(ucInputPort) == _FAIL)
		{
	        return _FAIL;
		}
	}

    // All Filed Element of g_unSMBusRdDataPool.stRdGetPDOStatus can be used here
    // For example:
    /*
    g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte0
	usTemp = (g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte0 + ((g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte1 & 0x03) << 8)) * 10;
	SET_OSDINFO_TYPEC_CURRENT(usTemp);

    usTemp = ((((g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte1 & 0xFC) >> 2)+ ((g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte2 & 0xFF) << 6)) * 50);
	SET_OSDINFO_TYPEC_VOLTAGE(usTemp);
	*/

	return _TRUE;
}
#endif

//--------------------------------------------------
// Description  : Get Type-C Port Controller Support
// Input Value  : InputPort
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerSupport(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return _TRUE;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return _TRUE;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return _TRUE;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return _TRUE;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : User Set OSD Menu Set Lane Mode Switched Flag
// Input Value  : InputPort
// Output Value : None
//--------------------------------------------------
void UserInterfaceTypeCPortControllerTypeCModeSwitch(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
}

#if(_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Set Usb Hub Polling SS Device Step
// Input Value  : ucInputPort --> Input Port
// Output Value : Usb Hub Polling Step Par.
//--------------------------------------------------
WORD UserInterfaceTypecUsbHubSetPollingStep(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
    return 0;
}

//--------------------------------------------------
// Description  : Usb Hub RTS5400 Series User Flow Support
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE: User Flow, _FALSE: Kernal Flow
//--------------------------------------------------
bit UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            return _FALSE;
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            return _FALSE;
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
        case _D6_INPUT_PORT:

            return _FALSE;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Adjust Type-C Dp Lanes
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceTypecUsbHubSetSSMode(BYTE ucInputPort, bit bEn)
{
    ucInputPort = ucInputPort;
    bEn = bEn;
}

//--------------------------------------------------
// Description  : Config Config Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE UserInterfaceTypecUsbHubDetectSSDevicePlugInfo(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
}
#endif // End of #if(_DP_USB_HUB_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)

#if((_OGC_SUPPORT == _ON) || (_OCC_SUPPORT == _ON) || (_OGC_DICOM_SUPPORT == _ON) || (_UNIFORMITY_SUPPORT == _ON))
//--------------------------------------------------
// Description  : User function Before Calibration Start
// Input Value  : EnumCaliType
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustBeforeDisplayCalibration(EnumCaliType enumMode)
{
    if(enumMode == _UNIFORMITY_CAL)// for Uniformity
    {
    }
    else // OGC/OCC/DICOM
    {
    }
}

//--------------------------------------------------
// Description  : User function After Calibration Start
// Input Value  : EnumCaliType
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustAfterDisplayCalibration(EnumCaliType enumMode)
{
    if(enumMode == _UNIFORMITY_CAL)// for Uniformity
    {
    }
    else // OGC/OCC/DICOM
    {
    }
}
#endif

#if(_YPEAKING_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Ypeaking Table
// Input Value  : Request Ypeaking Table
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustYpeaking(void)
{
#if(_ULTRA_VIVID_SUPPORT == _ON)
    switch(GET_OSD_ULTRA_VIVID_STATUS())
    {
        case _ULTRA_VIVID_L:
            ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x0E, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
            break;

        case _ULTRA_VIVID_M:
            ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x41, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
            break;

        case _ULTRA_VIVID_H:
        default:
            ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x7E, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
            break;
    }
#else
    // Table mode
    // ScalerColorYpeakingAdjust(_YPEAKING_TABLE_MODE, 0x00, _YPEAKING_NO_DIV, tYPEAKING_TABLE[0], _YPEAKING_TABLE_SIZE, GET_CURRENT_BANK_NUMBER());

    // Gain mode
    ScalerColorYpeakingAdjust(_YPEAKING_GAIN_MODE, 0x41, _YPEAKING_N_DIV32, _NULL_POINTER, 0x00, 0x00);
#endif
}
#endif // End of #if(_YPEAKING_SUPPORT == _ON)

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Deal With The Received Data
// Input Value  : pucArray --> Data Pointer
// Output Value : None
//--------------------------------------------------
void UserInterfaceReceivedDataProc(BYTE *pucArray)
{
    pucArray = pucArray;
}
#endif

#endif //#if(_OSD_TYPE == _NONE_OSD)
