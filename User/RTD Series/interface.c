#if(_OSD_TYPE == _OSTAR_2014_OSD)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _USER_SHOW_LOGO_STEP                    18 // frames

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
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
//----------------------------------------------------------------------------------------------------
// Filter Coefficient Table (Sharpness)
//----------------------------------------------------------------------------------------------------
#if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))
BYTE code tSU_COEF_128_TAPS_0[] =
{
#include ".\Sharpness\Sharpness128TapsNormalTable0.h"
};

BYTE code tSU_COEF_128_TAPS_2[] =
{
#include ".\Sharpness\Sharpness128TapsNormalTable2.h"
};

BYTE code tSU_COEF_128_TAPS_4[] =
{
#include ".\Sharpness\Sharpness128TapsNormalTable4.h"
};

BYTE code tSU_COEF_128_TAPS_6[] =
{
#include ".\Sharpness\Sharpness128TapsNormalTable6.h"
};

BYTE code tSU_COEF_128_TAPS_8[] =
{
#include ".\Sharpness\Sharpness128TapsNormalTable8.h"
};

code BYTE *tSCALE_128TAPS_NORMAL_COEF_TABLE[] =
{
    tSU_COEF_128_TAPS_0,        tSU_COEF_128_TAPS_2,        tSU_COEF_128_TAPS_4,        tSU_COEF_128_TAPS_6,        tSU_COEF_128_TAPS_8,
};
#endif // End of #if((_HSU_128TAPS_SUPPORT == _ON) || (_VSU_128TAPS_SUPPORT == _ON))

#if(_HSU_128TAPS_SUPPORT == _ON)
BYTE code tSU_1to1_COEF_128_TAPS_0[] =
{
#include ".\Sharpness\Sharpness128Taps1to1Table0.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_2[] =
{
#include ".\Sharpness\Sharpness128Taps1to1Table2.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_4[] =
{
#include ".\Sharpness\Sharpness128Taps1to1Table4.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_6[] =
{
#include ".\Sharpness\Sharpness128Taps1to1Table6.h"
};

BYTE code tSU_1to1_COEF_128_TAPS_8[] =
{
#include ".\Sharpness\Sharpness128Taps1to1Table8.h"
};

code BYTE *tSCALE_128TAPS_1to1_COEF_TABLE[] =
{
    tSU_1to1_COEF_128_TAPS_0,        tSU_1to1_COEF_128_TAPS_2,        tSU_1to1_COEF_128_TAPS_4,        tSU_1to1_COEF_128_TAPS_6,        tSU_1to1_COEF_128_TAPS_8,
};
#endif // End of #if(_HSU_128TAPS_SUPPORT == _ON)

#if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))
BYTE code tSU_COEF_96_TAPS_0[] =
{
#include ".\Sharpness\Sharpness96TapsNormalTable0.h"
};

BYTE code tSU_COEF_96_TAPS_2[] =
{
#include ".\Sharpness\Sharpness96TapsNormalTable2.h"
};

BYTE code tSU_COEF_96_TAPS_4[] =
{
#include ".\Sharpness\Sharpness96TapsNormalTable4.h"
};

BYTE code tSU_COEF_96_TAPS_6[] =
{
#include ".\Sharpness\Sharpness96TapsNormalTable6.h"
};

BYTE code tSU_COEF_96_TAPS_8[] =
{
#include ".\Sharpness\Sharpness96TapsNormalTable8.h"
};

code BYTE *tSCALE_96TAPS_NORMAL_COEF_TABLE[] =
{
    tSU_COEF_96_TAPS_0,        tSU_COEF_96_TAPS_2,        tSU_COEF_96_TAPS_4,        tSU_COEF_96_TAPS_6,        tSU_COEF_96_TAPS_8,
};
#endif // End of #if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))

#if(_HSU_96TAPS_SUPPORT == _ON)
BYTE code tSU_1to1_COEF_96_TAPS_0[] =
{
#include ".\Sharpness\Sharpness96Taps1to1Table0.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_2[] =
{
#include ".\Sharpness\Sharpness96Taps1to1Table2.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_4[] =
{
#include ".\Sharpness\Sharpness96Taps1to1Table4.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_6[] =
{
#include ".\Sharpness\Sharpness96Taps1to1Table6.h"
};

BYTE code tSU_1to1_COEF_96_TAPS_8[] =
{
#include ".\Sharpness\Sharpness96Taps1to1Table8.h"
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
#include ".\UltraVivid\UltraVividTableL.h"
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_M[] =
{
#include ".\UltraVivid\UltraVividTableM.h"
};

BYTE code tCOLOR_ULTRAVIVID_SETTING_H[] =
{
#include ".\UltraVivid\UltraVividTableH.h"
};

code BYTE *tCOLOR_ULTRAVIVID_SETTING_TABLE[] =
{
    tCOLOR_ULTRAVIVID_SETTING_L,
    tCOLOR_ULTRAVIVID_SETTING_M,
    tCOLOR_ULTRAVIVID_SETTING_H,
};
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_UART_SUPPORT == _ON)
BYTE g_ucUartData[5] = {0};
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
// Lee add to write edid at 24c02   20141011 start//        

#if(_DDCCI_DDCPROC_FUNC==_ON)
BYTE OSTARPinTypeGpioDdcIICConvert(BYTE ucDDCChanelSel,BYTE ucPinType);
bit OSTAREdidEepromCheck(BYTE ucSize,BYTE ucDDCChanelSel);
   #if( (_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
   void UserCommonRestoreEmbeddedEDIDData();
   void UserInterfaceGetEmbeddedEDIDData(BYTE ucPort);
   #endif
   #endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
void UserInterfaceGetHDCPKeyBksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
void UserInterfaceGetHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);

#if(_DP_TX_SUPPORT == _ON)
void UserInterfaceGetTxHDCPKeyAksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray);
void UserInterfaceGetTxHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
#endif
#endif

#if((_HDCP_2_2_SUPPORT == _ON) && (_HDCP_2_2_KEY_LOCATION == _TABLE_LOCATION_USER))
void UserInterfaceGetHdcp2CertrxByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
void UserInterfaceGetHdcp2RSADkeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
void UserInterfaceGetHdcp2RSARRModNByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
void UserInterfaceGetHdcp2RSAKPrivByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
void UserInterfaceGetHdcp2RSANpinvByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
void UserInterfaceGetHdcp2LCKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray);
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
void UserInterfaceAdjustWaitPanelT4(void);
void UserInterfaceAdjustWaitPanelT5(void);

//-------------------------------------------------------
//
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
void UserInterfaceGetAspectRatio(WORD *usHRatio, WORD *usVRatio);
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
StructDVCustomizedFreq UserInterfaceGetDVMaxMinFreq(void);
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
void UserInterfaceAdjustInputTiming(void);

#if(_UNDERSCAN_SUPPORT == _ON)
bit UserInterfaceAdjustUnderScan(void);
#endif

void UserInterfaceAdjustDisplayTiming(void);

//-------------------------------------------------------
// Color
//-------------------------------------------------------
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceGetRGBQuantizationLimitRangeStatus(BYTE ucQuanRange);
#endif

#if(_OD_SUPPORT == _ON)
EnumFunctionOnOFF UserInterfaceGetODEnableStatus(void);
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
bit UserInterfaceGetYCCQuantizationFullRangeStatus(bit bQuanRange);
#endif

void UserInterfaceAdjustActiveByPassColorProc(void);
void UserInterfaceAdjustColorProc(void);

#if(_ULTRA_VIVID_SUPPORT)
void UserInterfaceAdjustUltraVivid(void);
#endif

code BYTE *UserInterfaceGetSharpnessCoef(EnumSUCoefType enumSUCoefType, EnumSourceSearchPort enumSourceSearchPort);
BYTE UserInterfaceGetSharpnessCoefBankNum(void);
bit UserInterfaceSharpnessBypassCheck(void);

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


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : User timer event process
// Input Value  : Event ID
// Output Value : None
//--------------------------------------------------

EnumFunctionOnOFF UserInterfaceGetODEnableStatus(void)
{
    return GET_OSD_OD_STATUS();
}
void UserInterfaceTimerEventProc(EnumScalerTimerEventID enumEventID)
{
#if( _USER_FUNCTION_LED_FLASH == _ON )
    static bit bLedStatus   = 0;// Lee add for led flash   20141011//   
#endif
    switch(enumEventID)
    {
        case _USER_TIMER_EVENT_KEY_REPEAT_ENABLE:
            SET_KEYREPEATSTART();
            break;

        case _USER_TIMER_EVENT_KEY_SCAN_READY:
            SET_KEYSCANREADY();
            break;

        case _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO:
            OsdDispDisableOsd();
            SET_OSD_LOGO_ON(_OFF);

#if(_INSTANT_TIMER_EVENT_0 == _ON)
            ScalerTimer0SetTimerCount(_TIMER_OFF);
#endif

#if(_PANEL_POW_SEQ_FAST_MODE == _ON)
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_OFF);
#else
            UserCommonInterfacePanelPowerAction(_PANEL_OFF);
#endif
            ScalerDDomainBackgroundEnable(_ENABLE);
            ScalerDDomainPatternGenEnable(_DISABLE);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOCABLE_MSG);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSIGNAL_MSG);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG);
            break;

        case _USER_TIMER_EVENT_GO_TO_POWER_SAVING:
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG);
            break;

        case _USER_TIMER_EVENT_OSD_DISABLE:
            OsdDispDisableOsd();
            break;

        case _USER_TIMER_EVENT_PANEL_BACKLIGHT_ON:
            SET_PANELPOWERSTATUS(_READY_FOR_BACKLIGHT);
            break;

        case _USER_TIMER_EVENT_PANEL_POWER_OFF:
            SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);
            break;

#if(_VGA_SUPPORT == _ON)
        case _USER_TIMER_EVENT_DO_AUTO_COLOR:
            //CLR_KEY_HOLD();
            OsdDisplayAutoBalanceProc();
            break;
#endif

        case _USER_TIMER_EVENT_PANEL_USED_TIMER:
            OSTARFactoryPanelUsedTimer();
            break;

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
        case _USER_TIMER_EVENT_HLWIN_TYPE5_MOVE:
            UserAdjustHLWinType5Move();
            break;
#endif


// Lee add for factory burnin model   20141011 start//  
        case _USER_TIMER_EVENT_SHOW_BURNIN:
            OSTARFactoryShowBurninPicture();
            break;
// Lee add for factory burnin model   20141011 end//    

#if( _USER_FUNCTION_LED_FLASH == _ON )
// Lee add for led flash   20141011 start// 
        case _USER_TIMER_EVENT_LED_FLASH:

#if(_KEY_TYPE == _SANSE_AD_5KEY_BLUE_RED_KEY)
            if(bLedStatus)
            {
                PCB_LED_ON();
            }
            else
            {
                PCB_LED_TYPE3();
            }
            bLedStatus = ~bLedStatus;    

#else
// NEED ACTIVE BLUE,OFF RED,POWERSAVING BULE FLASH//
            if(bLedStatus)
            {
                PCB_LED_ON();
            }
            else
            {
                PCB_LED_OFF();
            }
            bLedStatus = ~bLedStatus;    
            
#endif
            break;
// Lee add for led flash   20141011 end//   
#endif
  /*      case _USER_TIMER_EVENT_OSD_KEYINFO_UNHIGHLIGHT:
            OsdDispMainMenuKeyInfo(_KEY_INFO_ALL, _OSD_UNHIGHLIGHT);
            break;

        case _USER_TIMER_EVENT_OSD_SHOW_DP_VERSION_SELECT:
            CLR_KEY_HOLD();

            if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING))
            {
                SET_OSD_POWER_SAVING_SHOW_DP_OPTION(_TRUE);
                ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
            }
            else
            {
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_DP_VERSIOM_MSG);
            }

            break;
*/
#if(_FREESYNC_SUPPORT == _ON)
        case _USER_TIMER_EVENT_OSD_SHOW_FREESYNC_VFREQ:
        /*    if((GET_OSD_STATE() == _MENU_INFORMATION) && (ScalerSyncGetFREESYNCEnable() == _TRUE))
            {
                g_ucFontPointer1 = GET_FREESYNC_OSD_ADDRESS();
                OsdPropPutString(ROW(14 + 1), COL(16), _PFONT_PAGE_1, _STRING_NOW_RESOLUTION, COLOR(_CP_BLUE_120, _CP_BG), _ENGLISH);
                ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_SHOW_FREESYNC_VFREQ);
            }*/
            break;
#endif
#if(_FREEZE_SUPPORT == _ON)
        case _USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG:
            OsdFuncDisableOsd();
            if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_OSD_STATE() != _MENU_NONE))
            {
                OsdFuncShowOSDAfterClosedFreezeMsg();
#if(_URGENT_EVENT_CHECK_MODE == _OFF)
                SET_FREEZE_DISABLE_MSG_STATE(_OFF);
#endif
            }
            break;
#endif
#if(_USE_TIME_SUPPORT == _ON)

	case _USER_TIMER_EVENT_OSD_TIMER:
		        g_usTimeUse++;
        ScalerTimerActiveTimerEvent(SEC(0.898), _USER_TIMER_EVENT_OSD_TIMER);// 
        #if(_MIAOZHUN_FUNCTION== _ON)

            if((GET_OSD_STATE() == _MENU_NONE)&&(g_MiaoZhun_OnOff == _OFF))
        #else
            if(GET_OSD_STATE() == _MENU_NONE)
        #endif
            
			
			if(g_usTime_OSD_OnOff1==_ON)
			{

			OsdDispLeftTimerCountDown();
            }
        
		break;
#endif

#if(_PCB_TYPE == _RL6449_SM2795A)

	case _USER_TIMER_EVENT_AUDIO_MUTE_OFF:   //tdy add for popo
			   DebugMessageAudio(" _USER_TIMER_EVENT_AUDIO_MUTE_OFF   111111", 0);

	                    PCB_AMP_MUTE(_AMP_MUTE_OFF);
                          DebugMessageAudio("PCB_AMP_MUTE(_AMP_MUTE_OFF)0 1111", _AMP_MUTE_OFF);
		 break;
#endif
/*
	case _USER_TIMER_EVENT_AUDIO_MUTE_OFF:   //tdy add for popo
			   DebugMessageAudio(" _USER_TIMER_EVENT_AUDIO_MUTE_OFF   111111", 0);

	                    PCB_AMP_MUTE(_AMP_MUTE_OFF);
                          DebugMessageAudio("PCB_AMP_MUTE(_AMP_MUTE_OFF)0 1111", _AMP_MUTE_OFF);
		 break;
		 */
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
    if(GET_OSD_LOGO_ON() == _ON)
    {
        if(g_ucLogoTimerCounter != 0xFF)
        {
            g_ucLogoTimerCounter++;
        }

        switch(g_ucLogoTimerCounter)
        {
            case _USER_SHOW_LOGO_STEP:
            case (_USER_SHOW_LOGO_STEP * 2):
            case (_USER_SHOW_LOGO_STEP * 3):
            case (_USER_SHOW_LOGO_STEP * 4):
            case (_USER_SHOW_LOGO_STEP * 5):
            case (_USER_SHOW_LOGO_STEP * 6):
            case (_USER_SHOW_LOGO_STEP * 7):

                ScalerOsdSetTransparency_EXINT(0xFF - (g_ucLogoTimerCounter / _USER_SHOW_LOGO_STEP) * 36);

                break;

            default:

                break;
        }
    }
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
        g_ucUartData[0] = GET_UART_DATA();

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
    if(g_pucDdcciRxBuf[_DDCCI_SOURCE_OPCODE] == _DDCCI_OPCODE_VCP_HDMI_FREESYNC_SUPPORT)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}
#endif // #if(_HDMI_FREESYNC_SUPPORT == _ON)

#endif
// Lee add to write edid at 24c02   20141011 start //       

#if(_DDCCI_DDCPROC_FUNC==_ON)
BYTE OSTARPinTypeGpioDdcIICConvert(BYTE ucDDCChanelSel,BYTE ucPinType)
{
    if(ucPinType==_SWITCH_DDC)
    {
        switch(ucDDCChanelSel)
        {
            case _VGA_DDC:
                return   _DDC_VGA_SWITCH_DDC;
        break;
        
            case _DDC0:
                return   _DDC0_SWITCH_DDC;
        break;

            case _DDC1:
                return   _DDC1_SWITCH_DDC;
        break;

            case _DDC2:
                return   _DDC2_SWITCH_DDC;
        break;

            case _DDC3:
                return   _DDC3_SWITCH_DDC;
        break;

            case _DDC4:
                return   _DDC4_SWITCH_DDC;
        break;

            case _DDC5:
                return   _DDC5_SWITCH_DDC;
        break;

            default:
            return   _DDC_VGA_SWITCH_DDC;
            break;
        }
    }
    else if(ucPinType==_SWITCH_GPIO)
    {
        switch(ucDDCChanelSel)
        {
            case _VGA_DDC:
                return   _DDC_VGA_SWITCH_GPIO;
        break;

        
            case _DDC0:
                return   _DDC0_SWITCH_GPIO;
        break;

            case _DDC1:
                return   _DDC1_SWITCH_GPIO;
        break;

            case _DDC2:
                return   _DDC2_SWITCH_GPIO;
        break;

            case _DDC3:
                return   _DDC3_SWITCH_GPIO;
        break;

            case _DDC4:
                return   _DDC4_SWITCH_GPIO;
        break;

            case _DDC5:
                return   _DDC5_SWITCH_GPIO;
        break;

            default:
            return   _DDC_VGA_SWITCH_GPIO;
            break;
        }
    }
    else  //if(ucPinType==_SWITCH_IIC)
    {
        switch(ucDDCChanelSel)
        {
            case _VGA_DDC:
                return   _IIC_FOR_VGA;
        break;
        
            case _DDC0:
                return   _IIC_FOR_DDC0;
        break;

            case _DDC1:
                return   _IIC_FOR_DDC1;
        break;

            case _DDC2:
                return   _IIC_FOR_DDC2;
        break;

            case _DDC3:
                return   _IIC_FOR_DDC3;
        break;

            case _DDC4:
                return   _IIC_FOR_DDC4;
        break;

            case _DDC5:
                return   _IIC_FOR_DDC5;
        break;

            default:
            return   _IIC_FOR_VGA;
            break;
        }
    }
        
}

bit OSTAREdidEepromCheck(BYTE ucSize,BYTE ucDDCChanelSel)
{
      BYTE cnt0 = 0;
      BYTE cnt1 = 0;
      WORD usCheckSum128 = 0;
      WORD usCheckSum256 = 0;
      BYTE DDCRAM_TMP[256]={0};

    UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 8, pData, (OSTARPinTypeGpioDdcIICConvert(ucDDCChanelSel,_SWITCH_IIC)), _SW_IIC_PIN_GPIO);

    if((pData[0] != 0x00)||(pData[1] != 0xff)||(pData[2] != 0xff)||(pData[3] != 0xff)
    ||(pData[4] != 0xff)||(pData[5] != 0xff)||(pData[6] != 0xff)||(pData[7] != 0x00))    
    {
            return _FALSE ;
    }
    else if(ucSize==_EDID_SIZE_128)
    {
        UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 127, DDCRAM_TMP, (OSTARPinTypeGpioDdcIICConvert(ucDDCChanelSel,_SWITCH_IIC)), _SW_IIC_PIN_GPIO);
        //check checksum >>
        for(cnt0 = 0; cnt0 < 127; cnt0++)
        {
            usCheckSum128 += DDCRAM_TMP[cnt0];
        }
        usCheckSum128 = (256- usCheckSum128%256)%256;
        ScalerTimerDelayXms(1);
        UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, pData, (OSTARPinTypeGpioDdcIICConvert(ucDDCChanelSel,_SWITCH_IIC)), _SW_IIC_PIN_GPIO);

        if((BYTE)(usCheckSum128) != pData[0])
        {
            return _FALSE ;
        }       
        else
        {
            return _TRUE ;
        }
    }
   else if(ucSize==_EDID_SIZE_256)
    {

        UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x00, 1, 255, DDCRAM_TMP, (OSTARPinTypeGpioDdcIICConvert(ucDDCChanelSel,_SWITCH_IIC)), _SW_IIC_PIN_GPIO);
        //check checksum >>
        for(cnt0 = 0; cnt0 < 127; cnt0++)
        {
            usCheckSum128 += DDCRAM_TMP[cnt0];
        }
        usCheckSum128 = (256- usCheckSum128%256)%256;

        for(cnt1 = 0; cnt1 < 127; cnt1++)
        {
            usCheckSum256 += DDCRAM_TMP[128+cnt1];
        }
        usCheckSum256 = (256- usCheckSum256%256)%256;
        
        ScalerTimerDelayXms(1);

        UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0x7F, 1, 1, &pData[0], (OSTARPinTypeGpioDdcIICConvert(ucDDCChanelSel,_SWITCH_IIC)), _SW_IIC_PIN_GPIO);
        UserCommonEepromIICRead(_EEPROM_SLAVE_ADDRESS, 0xFF, 1, 1, &pData[1], (OSTARPinTypeGpioDdcIICConvert(ucDDCChanelSel,_SWITCH_IIC)), _SW_IIC_PIN_GPIO);

        if(((BYTE)(usCheckSum128) != pData[0])||((BYTE)(usCheckSum256) != pData[1]))
        {
            return _FALSE ;
        }       
        else
        {
            return _TRUE ;
        }        
    }
   else
   {
      return _TRUE ;
   }
}

#if(_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON)

#define _EEPROM_READ_SIZEYJ                           24
#define _EEPROM_TIMEOUT_LIMITYJ                       50

//--------------------------------------------------
// Description  : Write data to the System EEPROM by IIC
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to write
//                pReadArray   --> Result array
//                ucIICStatus   --> SW IIC Applications
//                ucHwIICPinNum --> HW IIC Pin Used
//                enumWriteSize --> 8 or 16 or 32
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
#pragma save
#pragma OT(8)
bit UserCommonEepromIICWriteyj(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucSubAddrLength, WORD usLength, BYTE *pucWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum, EnumEepromWriteSize enumWriteSize)
{
    BYTE ucSlaveAddress = ucSlaveAddr;
    BYTE ucDataCnt = 0;
    BYTE ucTimeOutCnt = _EEPROM_TIMEOUT_LIMITYJ;
    BYTE pucTempData[32];

    ucSWIICStatus = ucSWIICStatus;

    if(usLength <= 0)
    {
        return _FAIL;
    }

    while(usLength > 0)
    {
        if(ucSubAddrLength == 1)
        {
            ucSlaveAddress = ucSlaveAddr + (BYTE)((usSubAddr & 0xFF00) >> 7);
        }

        // Transmit 8, 16 or 32 bytes each time
        ucDataCnt = enumWriteSize;

        // Check if more than 8, 16 or 32 bytes are needed to be transmitted
        if(enumWriteSize == _WRITE_SIZE_32)
        {
            if(((usSubAddr & 0x001F) + usLength - 1) >= enumWriteSize)
            {
                ucDataCnt = enumWriteSize - (usSubAddr & 0x001F);
            }
        }
        else if(enumWriteSize == _WRITE_SIZE_16)
        {
            if(((usSubAddr & 0x000F) + usLength - 1) >= enumWriteSize)
            {
                ucDataCnt = enumWriteSize - (usSubAddr & 0x000F);
            }
        }
        else if(enumWriteSize == _WRITE_SIZE_8)
        {
            if(((usSubAddr & 0x0007) + usLength - 1) >= enumWriteSize)
            {
                ucDataCnt = enumWriteSize - (usSubAddr & 0x0007);
            }
        }

        if(usLength > ucDataCnt)
        {
            usLength -= ucDataCnt;
        }
        else
        {
            ucDataCnt = usLength;
            usLength = 0;
        }

        // Save the data to be transfered to pData to ensure the data is saved in XDATA SPACE
        memcpy(pucTempData, pucWriteArray, ucDataCnt);

        // Increase data location
        pucWriteArray += ucDataCnt;

        // Disable EEPROM Write Protect
       PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
	DebugMessageSystem("_EEPROM_WP_DISABLE",0);

	//ScalerTimerDelayXms(1000);
	 
        // Execute Hardware IIC Write Command
        if(ucHwIICPinNum == _SW_IIC_PIN_GPIO)
        {
#if(_SW_IIC_SUPPORT == _ON)
            SET_SW_IIC_STATUS(ucSWIICStatus);

            if(ScalerMcuIICWrite(ucSlaveAddress, ucSubAddrLength, usSubAddr, ucDataCnt, pucTempData) == _FAIL)
            {
                // Enable EEPROM Write Protect
                PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
		DebugMessageSystem("_EEPROM_WP_ENABLE1",0);

                return _FAIL;
            }
#endif // End of #if(_SW_IIC_SUPPORT == _ON)

        }
        else if(ucHwIICPinNum != _NO_IIC_PIN)
        {
#if(_HW_IIC_SUPPORT == _ON)
            if(ScalerMcuHwIICWrite(ucSlaveAddress, ucSubAddrLength, usSubAddr, ucDataCnt, pucTempData, ucHwIICPinNum) == _FAIL)
            {
                // Enable EEPROM Write Protect
              PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
		DebugMessageSystem("_EEPROM_WP_ENABLE2",0);

                return _FAIL;
            }
#endif // End of #if(_HW_IIC_SUPPORT == _ON)

        }

        // Increment Sub-Addr for next Write
        usSubAddr += ucDataCnt;

        // Need to delay until internal write cycle is finished
        if(ucHwIICPinNum == _SW_IIC_PIN_GPIO)
        {
#if(_SW_IIC_SUPPORT == _ON)
            SET_SW_IIC_STATUS(ucSWIICStatus);

            while(ScalerMcuIICWritePolling(ucSlaveAddress) == _FAIL)
            {
                ucTimeOutCnt--;

                Delay5us(g_ucDelay5usN);

                if(ucTimeOutCnt == 0x00)
                {
                    // Enable EEPROM Write Protect
                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
			
			DebugMessageSystem("_EEPROM_WP_ENABLE3",0);

                    return _FAIL;
                }
            }
#endif // End of #if(_SW_IIC_SUPPORT == _ON)

        }
        else if(ucHwIICPinNum != _NO_IIC_PIN)
        {
#if(_HW_IIC_SUPPORT == _ON)
            while(ScalerMcuHwIICWritePolling(ucSlaveAddress, ucSubAddrLength, ucHwIICPinNum) == _FAIL)
            {
                ucTimeOutCnt--;

                Delay5us(g_ucDelay5usN);

                if(ucTimeOutCnt == 0x00)
                {
                    // Enable EEPROM Write Protect
                    PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
			DebugMessageSystem("_EEPROM_WP_ENABLE4",0);

                    return _FAIL;
                }
            }
#endif // End of #if(_HW_IIC_SUPPORT == _ON)

        }

        ucTimeOutCnt = _EEPROM_TIMEOUT_LIMITYJ;


	//ScalerTimerDelayXms(1000);
        // Enable EEPROM Write Protect
        PCB_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
	DebugMessageSystem("_EEPROM_WP_ENABLE5",0);

    }

    return _SUCCESS;
}
#pragma restore


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// EDID DATA TABLE
//--------------------------------------------------
#include ".\EDID\EdidTableList.h"
//A0 EDID
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
#if((_A0_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE) && (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))

#warning "Write A0 EDID into 24C02"

//BYTE code tEDID_TABLE_A0[] =
//{                   
#include ".\EDID\EdidTableA0yj.h"
//};
#endif // End of #if(((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON) && (_EMBEDDED_DDCRAM_A0_SIZE != _EDID_SIZE_NONE) && (_EMBEDDED_DDCRAM_A0_LOCATION != _EDID_TABLE_LOCATION_USER)) || (_EMBEDDED_DDCRAM_A0_LOCATION == _EDID_TABLE_LOCATION_CODE))
#endif


#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

//D0 EDID
#if((_D0_EMBEDDED_DDCRAM_SIZE ==  _EDID_SIZE_NONE) && (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
//BYTE code tEDID_TABLE_D0[] =
//{
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)

#warning "Write D0_DVI EDID into 24C02"

#include "\EDID\EdidTableD0yj.h"
    
#elif((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))

#warning "Write D0_HDMI EDID into 24C02"

#include "\EDID\EdidTableD0yj.h"

#endif
//};

#endif 

#endif 

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

//D1 EDID
#if((_D1_EMBEDDED_DDCRAM_SIZE ==  _EDID_SIZE_NONE) && (_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
//BYTE code tEDID_TABLE_D1[] =
//{
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)

#warning "Write D1_DVI EDID into 24C02"

#include "\EDID\EdidTableD1yj.h"
    
#elif((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))

#warning "Write D1_HDMI EDID into 24C02"

#include "\EDID\EdidTableD1yj.h"
 
#endif
//};

#endif

#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)

//D2 EDID
#if((_D2_EMBEDDED_DDCRAM_SIZE ==  _EDID_SIZE_NONE) && (_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
//BYTE code tEDID_TABLE_D2[] =
//{
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))

#warning "Write D2_DVI EDID into 24C02"

#include "\EDID\EdidTableD2yj.h"
    
#elif((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))

#warning "Write D2_HDMI EDID into 24C02"

#include "\EDID\EdidTableD2yj.h"
    
#endif
//};
#endif 

#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)


#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)

//D3 EDID
#if((_D3_EMBEDDED_DDCRAM_SIZE ==  _EDID_SIZE_NONE) && (_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
//BYTE code tEDID_TABLE_D3[] =
//{
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))

#warning "Write D3_DVI EDID into 24C02"

#include "\EDID\EdidTableD3yj.h"
    
#elif((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))

#warning "Write D3_HDMI EDID into 24C02"

#include "\EDID\EdidTableD3yj.h"
    
#endif
//};
#endif 

#endif 

#if(_D4_INPUT_PORT_TYPE !=  _D4_NO_PORT)

//D4 EDID
#if((_D4_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE) && (_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
//BYTE code tEDID_TABLE_D4[] =
//{
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))

#warning "Please check D4_DVI EDID table location!!"

#include "\EDID\EdidTableD4yj.h"
    
#elif((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))

#warning "Please check D4_HDMI EDID table location!!"

#include "\EDID\EdidTableD4yj.h"
    
#endif
//};
#endif

#endif 

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)

//D5 EDID
#if((_D5_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE) && (_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
//BYTE code tEDID_TABLE_D5[] =
//{
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)

#warning "Please check D5_DVI EDID table location!!"

#include "\EDID\EdidTableD5yj.h"
    
#elif((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))

#warning "Please check D5_HDMI EDID table location!!"

#include "\EDID\EdidTableD5yj.h"
    
#endif
//};
#endif 

#endif 


//--------------------------------------------------
// Description  :Convert Switch DDC pin to GPIO or viceversa
// Input Value  : ucDDCChanelSel --> DDC0-6 ; bDdcPinEnable-->enable for ddc function disable for gpio function
// Output Value : ddcxgpio or ddcxddc type
//--------------------------------------------------
//--------------------------------------------------
// Description  : Set Embedded EDID Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------

void UserCommonRestoreEmbeddedEDIDData()
{

#if( (_A0_INPUT_PORT_TYPE != _A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_GPIO));
                UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_A0), tEDID_TABLE_A0, (OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_DDC));
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
#if( (_D0_INPUT_PORT_TYPE != _D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                 UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D0), tEDID_TABLE_D0, (OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif

#if( (_D1_INPUT_PORT_TYPE != _D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D1), tEDID_TABLE_D1, (OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
#if( (_D2_INPUT_PORT_TYPE != _D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))

		DebugMessageSystem("UserCommonEepromIICWrite D2",0);
		DebugMessageSystem("tEDID_TABLE_D2[255]",tEDID_TABLE_D2[255]);
		DebugMessageSystem("tEDID_TABLE_D2[127]",tEDID_TABLE_D2[127]);
              PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_GPIO));
		UserCommonEepromIICWriteyj(_EEPROM_SLAVE_ADDRESS, 0x00, 1, sizeof(tEDID_TABLE_D2), tEDID_TABLE_D2, (OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

#endif
#if( (_D3_INPUT_PORT_TYPE != _D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))

		DebugMessageSystem("UserCommonEepromIICWrite D3",0);
		
              PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj(_EEPROM_SLAVE_ADDRESS, 0x00, 1, sizeof(tEDID_TABLE_D3), tEDID_TABLE_D3, (OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

#endif
#if( (_D4_INPUT_PORT_TYPE != _D4_NO_PORT)&&(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D4_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D4), tEDID_TABLE_D4, (OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D4_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
#if( (_D5_INPUT_PORT_TYPE != _D5_NO_PORT)&&(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D5_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D5), tEDID_TABLE_D5, (OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D5_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif


}

#if(_PCB_TYPE == _RL6449_SM2775YTC_1DP2H_VBO)
void UserCommonRestoreEmbeddedEDIDDataNoFreesync()
{

#if( (_A0_INPUT_PORT_TYPE != _A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_GPIO));
                UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_A0), tEDID_TABLE_A0, (OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_DDC));
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
#if( (_D0_INPUT_PORT_TYPE != _D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                 UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D0), tEDID_TABLE_D0, (OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif

#if( (_D1_INPUT_PORT_TYPE != _D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D1), tEDID_TABLE_D1, (OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
#if( (_D2_INPUT_PORT_TYPE != _D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))

              PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_GPIO));
		UserCommonEepromIICWriteyj(_EEPROM_SLAVE_ADDRESS, 0x00, 1, sizeof(tEDID_TABLE_D2_NOFREESYNC), tEDID_TABLE_D2_NOFREESYNC, (OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

#endif
#if( (_D3_INPUT_PORT_TYPE != _D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))

		DebugMessageSystem("UserCommonEepromIICWrite D3",0);
		
              PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                   UserCommonEepromIICWriteyj(_EEPROM_SLAVE_ADDRESS, 0x00, 1, sizeof(tEDID_TABLE_D3_NOFREESYNC), tEDID_TABLE_D3_NOFREESYNC, (OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);

#endif
#if( (_D4_INPUT_PORT_TYPE != _D4_NO_PORT)&&(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D4_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D4), tEDID_TABLE_D4, (OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D4_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
#if( (_D5_INPUT_PORT_TYPE != _D5_NO_PORT)&&(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D5_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                     UserCommonEepromIICWriteyj( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D5), tEDID_TABLE_D5, (OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D5_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif


}
#endif
//--------------------------------------------------
// Description  :Convert Switch DDC pin to GPIO or viceversa
// Input Value  : ucDDCChanelSel --> DDC0-6 ; bDdcPinEnable-->enable for ddc function disable for gpio function
// Output Value : ddcxgpio or ddcxddc type
//--------------------------------------------------
//--------------------------------------------------
// Description  : Set Embedded EDID Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetEmbeddedEDIDData(BYTE ucPort)
{
	ucPort=ucPort;
    return ;
/*
    switch(ucPort)
    {
        case _A0_INPUT_PORT:
#if( (_A0_INPUT_PORT_TYPE != _A0_NO_PORT)&&(_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_A0),_VGA_DDC)!=_TRUE)
                {
                    UserCommonEepromIICWrite( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_A0), tEDID_TABLE_A0, (OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_VGA_DDC,_SWITCH_DDC));
                PCB_A0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;

        case _D0_INPUT_PORT:
#if((_D0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D0_INPUT_PORT_TYPE != _D0_NO_PORT)&&(_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D0),_D0_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D0), tEDID_TABLE_D0, (OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D0_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D0_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif

            break;

        case _D1_INPUT_PORT:
#if( (_D1_INPUT_PORT_TYPE != _D1_NO_PORT)&&(_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D1),_D1_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D1), tEDID_TABLE_D1, (OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D1_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D1_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;

        case _D2_INPUT_PORT:
#if( (_D2_INPUT_PORT_TYPE != _D2_NO_PORT)&&(_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D2),_D2_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, sizeof(tEDID_TABLE_D2), tEDID_TABLE_D2, (OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D2_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D2_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;

        case _D3_INPUT_PORT:
#if((_D3_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D3_INPUT_PORT_TYPE != _D3_NO_PORT)&&(_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D3),_D3_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite(_EEPROM_SLAVE_ADDRESS, 0x00, 1, sizeof(tEDID_TABLE_D3), tEDID_TABLE_D3, (OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D3_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D3_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;

        case _D4_INPUT_PORT:
#if((_D4_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D4_INPUT_PORT_TYPE != _D4_NO_PORT)&&(_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D4_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D4),_D4_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D4), tEDID_TABLE_D4, (OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D4_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D4_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;

        case _D5_INPUT_PORT:
#if((_D5_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D5_INPUT_PORT_TYPE != _D5_NO_PORT)&&(_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D5_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D5),_D5_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D5), tEDID_TABLE_D5, (OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D5_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D5_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;

        case _D6_INPUT_PORT://reserved for dp 
#if 0//((_EMBEDDED_DDCRAM_D6_SIZE != _EDID_SIZE_NONE) && (_D6_INPUT_PORT_TYPE != _D6_NO_PORT)&&(_EMBEDDED_DDCRAM_D6_LOCATION == _EDID_TABLE_LOCATION_USER))
              PCB_D6_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_DISABLE);
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D6_INPUT_PORT_TYPE,_SWITCH_GPIO));
                if(OSTAREdidEepromCheck(sizeof(tEDID_TABLE_D6),_D6_DDC_CHANNEL_SEL)!=_TRUE)
                {
                     UserCommonEepromIICWrite( _EEPROM_SLAVE_ADDRESS,0x00, 1, sizeof(tEDID_TABLE_D6), tEDID_TABLE_D6, (OSTARPinTypeGpioDdcIICConvert(_D6_DDC_CHANNEL_SEL,_SWITCH_IIC)), _SW_IIC_PIN_GPIO, _WRITE_SIZE_8);
                }
                 ScalerPinshareGpioDdcPinSwitch(OSTARPinTypeGpioDdcIICConvert(_D6_DDC_CHANNEL_SEL,_SWITCH_DDC));   
              PCB_D6_EDID_EEPROM_WRITE_PROTECT(_EEPROM_WP_ENABLE);
#endif
            break;
            
        default:
            break;
    }
	*/
}

#endif
#endif


#if(_DIGITAL_PORT_SUPPORT == _ON)
#if(_HDCP_1_4_KEY_LOCATION == _TABLE_LOCATION_USER)
//--------------------------------------------------
// Description  : Get HDCP Bksv By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyBksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{

}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Tx HDCP Aksv By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetTxHDCPKeyAksvByUser(BYTE ucSubAddr, BYTE ucLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetTxHDCPKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
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
void UserInterfaceGetHdcp2CertrxByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSADkeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSARRModNByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSAKPrivByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2RSANpinvByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
{

}

//--------------------------------------------------
// Description  : Get HDCP By User Defined Method
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetHdcp2LCKeyByUser(WORD usSubAddr, WORD usLength, BYTE *pReadArray)
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

//--------------------------------------------------
// Description  : Wait For Panel Power Sequence T4
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustWaitPanelT4(void)
{
    ScalerTimerDelayXms(_PANEL_POWER_OFF_T4);
}

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

    if(bUncall)
    {

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
    OSTARNVRamStartup();

    ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), UserCommonNVRamGetSystemData(_SEARCH_PORT));
    OSTARKeyInitial();
    SET_PANELPOWERSTATUS(_PANEL_POWER_OFF_STATE);

    // Adjust Backlight
    UserAdjustBacklight(GET_OSD_BACKLIGHT());

    // Adjust IR Decode
#if(_IR_SUPPORT == _IR_HW_SUPPORT)
    UserAdjusIR();
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

            // Set Monitor Power Off Status
            UserCommonNVRamSetSystemData(_MONITOR_POWER_STATUS, _OFF);

            // Save System Power Status Data.
            UserCommonNVRamSaveSystemData();
                 SET_OSD_FactoryIn_TYPE(_OFF);
	       // SET_OSD_FACTORY_BURNIN_STATUS(_OFF);
            OSTARNVRamSaveOSDData();            

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

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(_TIMER_OFF);
#endif
}

//--------------------------------------------------
// Description  : Keypad Led Control
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceKeyPadLedControl(BYTE ucKeyPadLed)
{
    switch(ucKeyPadLed)
    {
        case _LED_POWER_ON:
            PCB_LED_ACTIVE();
            break;

        case _LED_POWER_ACTIVE:
// Lee add for powersaving led flash cancel 20141014 start //   
             #if(_USER_FUNCTION_LED_FLASH ==_ON)    
              ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_FLASH); 
             #endif
// Lee add for powersaving led flash cancel 20141014 end //        
            PCB_LED_ACTIVE();
            break;

        case _LED_POWER_SEARCH:
            PCB_LED_ACTIVE(); // sfy modify for ostar pcb led 20140910 //
            //PCB_LED_IDLE();
            break;

        case _LED_POWER_SAVING:
            PCB_LED_POWER_SAVING();
            break;

        case _LED_POWER_NOSUPPORT:
            PCB_LED_POWER_SAVING();
            break;

        case _LED_POWER_NOSUPPORT_SAVING:
            PCB_LED_POWER_SAVING();
            break;

        case _LED_POWER_OFF:
// Lee add for powersaving led flash cancel 20141014 start //   
     #if(_USER_FUNCTION_LED_FLASH ==_ON)
          ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_FLASH);
     #endif
// Lee add for powersaving led flash cancel 20141014 end //   
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
// Lee add for powersaving led flash cancel 20141014 start //   
     #if(_USER_FUNCTION_LED_FLASH ==_ON)    
        ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_LED_FLASH);// Lee add for powersaving led flash 20141011//    
     #endif
// Lee add for powersaving led flash cancel 20141014 end //   
        
            PCB_LED_TYPE_FLASH();
            break;

        default:
            break;
    }
}


//--------------------------------------------------
// Description  : User OSD Get LogoOn
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetLogoStatus(void)
{
    return (GET_OSD_LOGO_ON());
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

  DebugMessageOsd("GET_D_CLK_FREQ =",GET_D_CLK_FREQ());
  DebugMessageSystem("GET_D_CLK_FREQ =",GET_D_CLK_FREQ());
    if((GET_D_CLK_FREQ() > ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ)) ||
       (GET_D_CLK_FREQ() < ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ)))
    {
        DebugMessageOsd("D Clock Exceed Panel Supported Range", GET_D_CLK_FREQ());
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get whether to by pass normal active process
// Input Value  : None
// Output Value : _TRUE => By pass normal active process
//--------------------------------------------------
bit UserInterfaceGetActiveByPassStatus(void)
{
/*
    if((GET_OSD_STATE() == _MENU_COLOR_FORMAT) || (GET_OSD_STATE() == _MENU_COLOR_FORMAT_ADJUST))
    {
        return _FALSE;
    }
*/
    if(GET_OSD_STATE() != _MENU_NONE)
    {
        return _TRUE;
    }

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
        SET_FORCE_POW_SAV_STATUS(_FALSE);

        if(SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT)
        {
            SysSourceSwitchInputPort(UserCommonNVRamGetSystemData(_SEARCH_PORT));
        }

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
    return (GET_FORCE_POW_SAV_STATUS());
}

//--------------------------------------------------
// Description  : User Check Into Power Saving
// Input Value  : None
// Output Value : True --> User Check Ready to Power Saving
//--------------------------------------------------
bit UserInterfaceGetIntoPSStatus(void)
{
    if(ScalerOsdGetOsdEnable() == _TRUE)
    {
        return _FALSE;
    }

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
    WORD code tOverscanEnTable[][3] =
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

            while(tOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tOverscanEnTable[ucTemp][0]) < 10) && \
                    (abs(GET_INPUT_TIMING_HWIDTH() - tOverscanEnTable[ucTemp][1]) < 2) && \
                    (GET_INPUT_TIMING_VHEIGHT() == tOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }

            break;
#endif // End of #if(_OVERSCAN_VGA_SUPPORT == _ON)


#if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))
#if(_OVERSCAN_DVI_SUPPORT == _ON)
        case _SOURCE_DVI:
#endif

#if(_OVERSCAN_HDMI_SUPPORT == _ON)
        case _SOURCE_HDMI:
#endif

#if((_DP_SUPPORT == _ON) && (_OVERSCAN_DP_SUPPORT == _ON))
        case _SOURCE_DP:
#endif
            // Interlaced and YUV Timing Always do overscan
            if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
            {
                bDoOverScan = _TRUE;
                break;
            }

            if(ScalerColorGetColorSpace() == _COLOR_SPACE_RGB)
            {
                break;
            }

            while(tOverscanEnTable[ucTemp][0] != 0)
            {
                if((abs(GET_INPUT_TIMING_VFREQ() - tOverscanEnTable[ucTemp][0]) < 10) && \
                    (abs(GET_INPUT_TIMING_HWIDTH() - tOverscanEnTable[ucTemp][1]) < 2) && \
                    (GET_INPUT_TIMING_VHEIGHT() == tOverscanEnTable[ucTemp][2]))
                {
                    bDoOverScan = _TRUE;
                    break;
                }

                ucTemp++;
            }

            break;
#endif // End of #if((_OVERSCAN_DVI_SUPPORT == _ON) || (_OVERSCAN_HDMI_SUPPORT == _ON) || (_OVERSCAN_DP_SUPPORT == _ON))


        default:
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
    switch(GET_OSD_ASPECT_RATIO_TYPE())
    {
      //  case _OSD_ASPECT_RATIO_16_BY_9:
        case _OSD_ASPECT_RATIO_4_BY_3:
        case _OSD_ASPECT_RATIO_AUTO:
    //    case _OSD_ASPECT_RATIO_5_BY_4:

            return _ASPECT_RATIO_FIXED;

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        case _OSD_ASPECT_RATIO_ORIGIN:

            return _ASPECT_RATIO_ORIGIN;
#endif

        default:
        case _OSD_ASPECT_RATIO_FULL:

            return _ASPECT_RATIO_FULL;
    }
}

//--------------------------------------------------
// Description  : Get user H/V aspect ratio values
// Input Value  : enumSelRegion --> select region
//                usHRatio, usVRatio --> aspect ratio
// Output Value : None
//--------------------------------------------------
void UserInterfaceGetAspectRatio(WORD *usHRatio, WORD *usVRatio)
{

// spur 
    switch(GET_OSD_ASPECT_RATIO_TYPE())
    {
        default:
            break;
/*
        case _OSD_ASPECT_RATIO_16_BY_9:
            *usHRatio = 16;
            *usVRatio = 9;
            break;
*/
        case _OSD_ASPECT_RATIO_4_BY_3:
            *usHRatio = 4;
            *usVRatio = 3;
            break;
			
        case _OSD_ASPECT_RATIO_AUTO:
            *usHRatio = 1;
            *usVRatio = 1;
            break;
			
/*
        case _OSD_ASPECT_RATIO_5_BY_4:
            *usHRatio = 5;
            *usVRatio = 4;
            break;
			*/
    }
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
#if (_DISPLAY_HOR_MIRROR_SUPPORT == _ON)
        case _DISP_ROTATE_HOR_MIRROR:
            return _ROT_HOR_MIRROR;
#endif
#if (_DISPLAY_VER_MIRROR_SUPPORT == _ON)
        case _DISP_ROTATE_VER_MIRROR:
            return _ROT_VER_MIRROR;
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
#endif

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

//--------------------------------------------------
// Description  : Adjust Max/Min Freq according to latency
// Input Value  : None
// Output Value : max/min freq
//--------------------------------------------------
StructDVCustomizedFreq UserInterfaceGetDVMaxMinFreq(void)
{
    StructDVCustomizedFreq stDVCustomizedFreq;

    switch (GET_OSD_LATENCY())
    {
        default:
        case _LATENCY_H:
        case _LATENCY_M:
        case _LATENCY_L:
            stDVCustomizedFreq.usMaxFreq = _PANEL_MAX_FRAME_RATE;
            stDVCustomizedFreq.usTypFreq = _PANEL_TYP_FRAME_RATE;
            stDVCustomizedFreq.usMinFreq = _PANEL_MIN_FRAME_RATE;
            break;
    }

    return stDVCustomizedFreq;
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
    StructDDR3PhaseInfo stUserVedorDdr3PhaseData = {_DDRPLL_INITIAL_PHASE_0, _DDRPLL_INITIAL_PHASE_1, _DDR_READ_DQ_DLYN_TAP};
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
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustInputTiming(void)
{
}

#if(_UNDERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Input Timing Based on User Requirement
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceAdjustUnderScan(void)
{
    if((GET_INPUT_TIMING_HWIDTH() == 640) && (GET_INPUT_TIMING_VHEIGHT() == 350))
    {
        SET_UNDERSCAN_VHEIGHT(400);
        return _TRUE;
    }

    return _FALSE;
}
#endif

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

#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceGetRGBQuantizationLimitRangeStatus(BYTE ucQuanRange)
    {
    switch(ucQuanRange)
        {
        case _RGB_QUANTIZATION_FULL_RANGE:
        case _RGB_QUANTIZATION_DEFAULT_RANGE:
        case _RGB_QUANTIZATION_RESERVED:
        default:

            return _FALSE;
            break;

        case _RGB_QUANTIZATION_LIMIT_RANGE:

            return _TRUE;
            break;
        }
    }
#endif

#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Judge if YCC Quantization Range is Full or Limited
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit UserInterfaceGetYCCQuantizationFullRangeStatus(bit bQuanRange)
{
    return (bQuanRange == _YCC_QUANTIZATION_FULL_RANGE);
}
#endif

//--------------------------------------------------
// Description  : Set Color in pass normal active process
// Input Value  : None
// Output Value : void
//--------------------------------------------------
void UserInterfaceAdjustActiveByPassColorProc(void)
{
#if(_OD_SUPPORT == _ON)
    ScalerODEnable(GET_OSD_OD_STATUS());
#endif
}

//--------------------------------------------------
// Description  : Set User Required Color Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustColorProc(void)
{
    if((GET_OSD_STATE() == _MENU_NONE) || (GET_OSD_STATE() == _MENU_SETUP_RESET))
    {
        // Set Color Conversion
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:

                SET_OSD_COLOR_FORMAT(GET_VGA_COLOR_FORMAT_STATUS());

                break;

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            case _D1_INPUT_PORT:
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
            case _D2_INPUT_PORT:
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)
            case _D3_INPUT_PORT:
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DVI_PORT) || \
    (_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DVI_PORT))
                SET_OSD_COLOR_FORMAT(GET_DVI_COLOR_FORMAT_STATUS());
                break;
#endif

            default:

                if(ScalerColorGetColorSpace() == _COLOR_SPACE_RGB)
                {
                    SET_OSD_COLOR_FORMAT(_COLOR_SPACE_RGB);
                }
                else
                {
                    SET_OSD_COLOR_FORMAT(_COLOR_SPACE_YPBPR);
                }

                break;
        }
    }

    // Adjust Color Space
    if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
    {
        SysModeColorSpaceConvert(_COLOR_SPACE_RGB, _DB_APPLY_NO_POLLING);
    }
    else
    {
        SysModeColorSpaceConvert(_COLOR_SPACE_YPBPR, _DB_APPLY_NO_POLLING);
    }

    // Adjust UltraVivid
#if(_ULTRA_VIVID_SUPPORT == _ON)

    if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
    {
        if(GET_OSD_ULTRA_VIVID_STATUS() == _ULTRA_VIVID_OFF)
        {
            UserCommonAdjustUltraVivid(_FUNCTION_OFF, _COLOR_SPACE_RGB, _DB_APPLY_NO_POLLING);
        }
        else
        {
            UserCommonAdjustUltraVivid(_FUNCTION_ON, _COLOR_SPACE_RGB, _DB_APPLY_NO_POLLING);
        }
    }
    else
    {
        if(GET_OSD_ULTRA_VIVID_STATUS() == _ULTRA_VIVID_OFF)
        {
            UserCommonAdjustUltraVivid(_FUNCTION_OFF, _COLOR_SPACE_YPBPR, _DB_APPLY_NO_POLLING);
        }
        else
        {
            UserCommonAdjustUltraVivid(_FUNCTION_ON, _COLOR_SPACE_YPBPR, _DB_APPLY_NO_POLLING);
        }
    }
#endif

    // Adjust Y-Peaking
#if(_YPEAKING_SUPPORT == _ON)
    ScalerColorYpeaking(_ON);
#endif

    // Adjust Sharpness
    UserCommonAdjustSharpness(SysSourceGetInputPort());

    // Adjust Backlight
    UserAdjustBacklight(GET_OSD_BACKLIGHT());

    // Adjust Brightness & Contrast
    OSTARNVRamLoadBriCon(SysSourceGetSourceType());

    // Adjust Transparency
    ScalerOsdSetTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // User Adjust Background Color
    ScalerDDomainBackgroundSetColor(0, 0, 0);

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        ScalerColorBrightnessEnable(_FUNCTION_OFF);
        ScalerColorContrastEnable(_FUNCTION_OFF);
        ScalerColorOutputGammaEnable(_FUNCTION_ON);
        ScalerColorSRGBEnable(_FUNCTION_ON);
        ScalerColorPCMInputGammaEnable(_FUNCTION_ON);

#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
        if(GET_OSD_PCM_STATUS() == _PCM_OSD_SOFT_PROFT)
        {
            ScalerColorRGB3DGammaEnable(_FUNCTION_ON);
        }
        else
        {
            ScalerColorRGB3DGammaEnable(_FUNCTION_OFF);
        }
#endif  // End of #if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))

    }
    else
#endif  // End of #if(_PCM_FUNCTION == _ON)
    {

#if(_PCM_FUNCTION == _ON)
        ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);
#endif

        // Adjust Gamma On/Off
#if(_GAMMA_FUNCTION == _ON)
#if(_USER_FUNCTION_FPS1_FPS2==_ON)
//#if(_GAMMA_FUNCTION == _ON)
        if((GET_OSD_GAMMA() == _GAMMA_OFF)&&((GET_OSD_COLOR_EFFECT() != _COLOREFFECT_FPS))&&((GET_OSD_COLOR_EFFECT() != _COLOREFFECT_RTS)))
        {
            ScalerColorOutputGammaEnable(_FUNCTION_OFF);
#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif

        }
        else
        {
            ScalerColorOutputGammaEnable(_FUNCTION_ON);
#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif

        UserAdjustGamma(GET_OSD_GAMMA());
        }
#else
        if(GET_OSD_GAMMA() == _GAMMA_OFF)
        {
            ScalerColorOutputGammaEnable(_FUNCTION_OFF);

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif
        }
        else
        {
            ScalerColorOutputGammaEnable(_FUNCTION_ON);

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif
        }
#endif

#endif  // End of #if(_GAMMA_FUNCTION == _ON)

        // Adjust Hue & Saturation
#if(_GLOBAL_HUE_SATURATION == _ON)
#if(_USER_FUNCTION_FPS1_FPS2 == _ON)
     //   if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_FPS)
     //   {
      //      UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), 140);
     //   }
     //   else
        {
            UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
        }

#else
        UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
#endif
#endif  // End of #if(_GLOBAL_HUE_SATURATION == _ON)

        // Adjuset Brightness & Contrast
        UserAdjustBrightness(GET_OSD_BRIGHTNESS());
        UserAdjustContrast(GET_OSD_CONTRAST());
    }

    // Adjust ICM On/Off
#if(_ICM_SUPPORT == _ON)
#if(_USER_FUNCTION_FPS1_FPS2 == _ON)
  //  if((GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD)||(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_GAME)||(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_FPS)||(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER))
  //  {
        ScalerColorICMEnable(_FUNCTION_OFF);
  //  }
  //  else
  //  {
   //     ScalerColorICMEnable(_FUNCTION_ON);
    //}
#else
    if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD)
    {
        ScalerColorICMEnable(_FUNCTION_OFF);
    }
    else
    {
        ScalerColorICMEnable(_FUNCTION_ON);
    }
#endif
#endif

#if(_USER_FUNCTION_LOW_BLUE_LIGHT == _ON)
        UserAdjustColorLowBlueLight(GET_OSD_LOWBLUELIGHT_STATUS());

#endif

    // Adjust DCC On/Off
#if(_DCC_FUNCTION == _ON)
  //  if((GET_OSD_COLOR_EFFECT() == _COLOREFFECT_STANDARD) || (GET_OSD_COLOR_EFFECT() == _COLOREFFECT_RTS)||(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_USER))
  //  {
        ScalerColorDCCEnable(_FUNCTION_OFF);
  //  }
  //  else
  //  {
    //    ScalerColorDCCEnable(_FUNCTION_ON);
   // }
#endif

#if(_OD_SUPPORT == _ON)
    ScalerODAdjustDeltaGain(GET_OSD_OD_GAIN());
    ScalerODEnable(GET_OSD_OD_STATUS());
#endif

    // Adjust DCC Table
#if(_DCC_FUNCTION == _ON)
    UserAdjustDCC(GET_OSD_COLOR_EFFECT());
#endif

#if(_UNIFORMITY_SUPPORT == _ON)
    if(GET_OSD_PANEL_UNIFORMITY() == _OFF)
    {
        ScalerColorPanelUniformityEnable(_FUNCTION_OFF);
    }
    else
    {
        ScalerColorPanelUniformityEnable(_FUNCTION_ON);
    }
#endif

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    // Adjust Highlight Window Effect Space
    UserAdjustHighLightWindowEffectSpace();

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    if(GET_OSD_ASPECT_RATIO_TYPE() != _OSD_ASPECT_RATIO_ORIGIN)
#endif
    {
        if(GET_OSD_HLWIN_TYPE() == _HL_WIN_OFF)
        {
            ScalerColorHLWEnable(_FUNCTION_OFF, _DB_APPLY_NONE);
        }
        else
        {
            UserAdjustHLWinType(GET_OSD_HLWIN_TYPE());
            ScalerColorHLWEnable(_FUNCTION_ON, _DB_APPLY_NONE);
        }
    }
#endif  // End of #if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
}

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set UltraVivid Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustUltraVivid(void)
{
    BYTE ucUltraVividStatus = GET_OSD_ULTRA_VIVID_STATUS();

    if(ucUltraVividStatus != _ULTRA_VIVID_OFF)
    {
        ScalerColorUltraVividAdjust(tCOLOR_ULTRAVIVID_SETTING_TABLE[ucUltraVividStatus - 1], GET_CURRENT_BANK_NUMBER());
    }
}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

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
            break;
#endif

#if((_HSU_96TAPS_SUPPORT == _ON) || (_VSU_96TAPS_SUPPORT == _ON))
        case _H_V_SU_96TAPS_NORMAL:
            return tSCALE_96TAPS_NORMAL_COEF_TABLE[GET_OSD_SHARPNESS()];
            break;
#endif

#if(_HSU_128TAPS_SUPPORT == _ON)
        case _H_SU_128TAPS_1_TO_1:
            return tSCALE_128TAPS_1to1_COEF_TABLE[GET_OSD_SHARPNESS()];
            break;
#endif

#if(_HSU_96TAPS_SUPPORT == _ON)
        case _H_SU_96TAPS_1_TO_1:
            return tSCALE_96TAPS_1to1_COEF_TABLE[GET_OSD_SHARPNESS()];
            break;
#endif
        default:
            return NULL;
            break;
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

#if(_SIX_COLOR_SUPPORT == _ON)
    BYTE ucIndex = 0;
#endif

#if(_UNIFORMITY_SUPPORT == _ON)
    // Uniformity parameters setting
    ScalerColorPanelUniformityInitial(_PANEL_UNIFORMITY_MULTI_LUT_MODE);

    if(GET_OSD_PANEL_UNIFORMITY() == _ON)
    {
        UserAdjustPanelUniformityMode(_UNIFORMITY_OSD_TYPE1);
    }
#endif

#if(_YPEAKING_SUPPORT == _ON)
    // Adjust YPeaking
    UserAdjustYpeaking();
#endif

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);

#if(_PCM_FUNCTION == _ON)
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
        UserAdjustPCM(GET_OSD_PCM_STATUS());
    }
    else
#endif

    {
    // Adjust Gamma Table
#if(_GAMMA_FUNCTION == _ON)
        UserAdjustGamma(GET_OSD_GAMMA());
#endif
    }

#if(_RGB_3D_GAMMA == _ON)
     UserAdjust3DGamma(GET_OSD_PCM_SOFT_PROFT_MODE());
#endif

// Adjust SCM Table, Should before ICM Adjust
#if(_SCM_SUPPORT == _ON)
    UserAdjustSCM(GET_OSD_COLOR_EFFECT());
#endif

    // Adjust ICM Table
#if(_ICM_SUPPORT == _ON)
    UserAdjustICM(GET_OSD_COLOR_EFFECT());
#endif

    // Adjust DCR Threshold & Source
#if(_DCR_SUPPORT == _ON)

#if(_DCR_BIT_MODE == _DCR_10BIT)
    ScalerColorDCRAdjust(_DCR_THESHOLD1, _DCR_THESHOLD2, _MEASURE_AVERAGE);
#elif(_DCR_BIT_MODE == _DCR_8BIT)
    ScalerColorDCRAdjust((_DCR_THESHOLD1 >> 2), (_DCR_THESHOLD2 >> 2), _MEASURE_AVERAGE);
#endif

#endif

    // Adjust Six Color Hue / Saturation
#if(_SIX_COLOR_SUPPORT == _ON)
   // if(GET_OSD_COLOR_EFFECT() == _COLOREFFECT_RTS)
    {
        for(ucIndex = 0; ucIndex < 7; ucIndex++)
        {
            SET_OSD_SIX_COLOR(ucIndex);
            OsdDisplaySixColorGetOneColor(ucIndex);
            ScalerColorSixColorAdjust(ucIndex, GET_OSD_SIX_COLOR_HUE(), GET_OSD_SIX_COLOR_SATURATION());
        }

        ScalerColorSixColorInitial();
    }
#endif

#if(_OD_SUPPORT == _ON)
    UserAdjustOD();
#endif

    // Adjust Highlight Window Border
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWBorderAdjust(_HL_WIN_BORDER_SIZE, 255, 0, 0);

    ScalerColorHLWBorderEnable(_ON, _ON, _ON, _ON);
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
        ScalerMcuDdcciSwitchPort(GET_OSD_DDCCI_STATUS(), SysSourceGetInputPort());

        if(GET_FAIL_SAFE_MODE() == _TRUE)
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG);
        }
        else
        {
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_ACTIVE_DO_ONE_TIME_MSG);
        }
    }

#if((_OD_SUPPORT == _ON) && (_FREESYNC_SUPPORT == _ON))
    UserAdjustOD();
#endif

#if(_FREEZE_SUPPORT == _ON)
    UserCommonAdjustDisplayFreeze(GET_OSD_FREEZE_STATUS());
#endif

    ScalerDDomainBackgroundEnable(_DISABLE);

#if(_FREESYNC_OD_MEASURE == _ON)
    UserAdjustFREESYNCODMeasure();
#endif
}

//--------------------------------------------------
// Description  : OSD Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceAdjustOsdResetProc(void)
{
    // Disable OSD
    if(GET_OSD_LOGO_ON() == _OFF)
    {
        OsdDispDisableOsd();
    }

    SET_OSD_LOGO_ON(_OFF);

    // Cancel Timer Events
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_DO_AUTO_COLOR);
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_HLWIN_TYPE5_MOVE);

// Lee add for powersaving led flash cancel 20141014 start //   
     #if(_USER_FUNCTION_LED_FLASH ==_ON)
    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_LED_FLASH);// Lee add to cancel led flash  20141011//   
     #endif
   ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_SHOW_BURNIN);// Lee add to cancel factory burnin model   20141011//   
      #if(_PCB_TYPE == _RL6449_SM2795A)

     ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);   //  //tdy add for popo
    #endif

  //  ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);   //  //tdy add for popo

// Lee add for powersaving led flash cancel 20141014 end //   
//    ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_DP_VERSION_SELECT);    
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
    if(GET_VGA_MODE_DO_FIRST_AUTO() && (GET_INPUT_TIMING_HWIDTH() > 720))
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
    g_usAdjustValue = ucAutoPercentage;
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

#if(_AUDIO_SUPPORT == _ON)
        case _MHL_RCP_VOLUME_UP:

            if(GET_OSD_VOLUME() < 100)
            {
                SET_OSD_VOLUME(GET_OSD_VOLUME() + 1);
            }

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;

        case _MHL_RCP_VOLUME_DOWN:

            if(GET_OSD_VOLUME() > 0)
            {
                SET_OSD_VOLUME(GET_OSD_VOLUME() - 1);
            }

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;

        case _MHL_RCP_MUTE:
        case _MHL_RCP_MUTE_FUNCTION:

            SET_OSD_VOLUME_MUTE(!GET_OSD_VOLUME_MUTE());

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioMuteSwitch();
            }
            break;

        case _MHL_RCP_RESTORE_VOLUME_FUNCTION:

            SET_OSD_VOLUME(50);

            if(UserInterfaceGetAudioReadyToPlayStatus() == _TRUE)
            {
                UserAdjustAudioVolume(GET_OSD_VOLUME());
            }
            break;
#endif

        default:
            return _FALSE;
            break;
    }

    return _TRUE;
}
#endif // End of #if(_MHL_SUPPORT == _ON)

#if(_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Decide whether to Enable FREESYNC Function
// Input Value  : None
// Output Value : Ture or False
//--------------------------------------------------
bit UserInterfaceGetFREESYNCEnable(void)
{
    return GET_OSD_FREE_SYNC_STATUS();
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
	
    switch((ucInputPort))
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D0)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else
            {
                return _DP_VERSION_1_2;
            }
            break;

#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D1)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else
            {
                return _DP_VERSION_1_2;
            }
            break;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            if(GET_OSD_DP_D2_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D1)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else
            {
                return _DP_VERSION_1_2;
            }
            break;
#endif


#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:

            if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_1)
            {
                if(GET_OSD_DP_MST() == _MST_D6)
                {
                    SET_OSD_DP_MST(_MST_OFF);
                }

                return _DP_VERSION_1_1;
            }
            else
            {
                return _DP_VERSION_1_2;
            }
            break;
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
        case _D0_DP_PORT:
            return _D0_DP_MAIN_LINK_LANES;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)        
        case _D1_DP_PORT:
            return _D1_DP_MAIN_LINK_LANES;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)        
        case _D2_DP_PORT:
            return _D2_DP_MAIN_LINK_LANES;
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_DP_PORT:
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

#endif

    if((SysSourceGetScanType() == _SOURCE_SWITCH_FIXED_PORT) && (GET_PORT_TYPE(SysSourceGetInputPortType(SysSourceGetInputPort())) == _PORT_DP))
    {
        if((GET_OSD_DP_MST() == _MST_D0) && (SysSourceGetInputPort() == _D0_INPUT_PORT))
        {
            if(GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1)
            {
                SET_OSD_DP_MST(_MST_OFF);

                return _DP_MST_NO_PORT;
            }
            else
            {
                return _DP_MST_RX0_PORT;
            }
        }
        else if((GET_OSD_DP_MST() == _MST_D1) && (SysSourceGetInputPort() == _D1_INPUT_PORT))
        {
            if(GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_1)
            {
                SET_OSD_DP_MST(_MST_OFF);

                return _DP_MST_NO_PORT;
            }
            else
            {
                return _DP_MST_RX1_PORT;
            }
        }
        else if((GET_OSD_DP_MST() == _MST_D6) && (SysSourceGetInputPort() == _D6_INPUT_PORT))
        {
            if(GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_1)
            {
                SET_OSD_DP_MST(_MST_OFF);

                return _DP_MST_NO_PORT;
            }
            else
            {
                return _DP_MST_RX6_PORT;
            }
        }
        else
        {
            return _DP_MST_NO_PORT;
        }
    }
    else
    {
        return _DP_MST_NO_PORT;
    }

    return _DP_MST_NO_PORT;
}

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Decide whether to Clone output to DP Tx
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceGetDpCloneOutputStatus(void)
{
    if(GET_OSD_CLONE_MODE() == _OFF)
    {
        return _FALSE;
    }

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
#if(_EMBEDDED_DAC_SUPPORT == _ON)
        if(ScalerAudioDACGetState() == _AUDIO_DAC_READY)
#endif
        {
#if(_LINE_IN_SUPPORT == _ON)
            if(UserInterfaceGetAudioSource() == _LINE_IN_AUDIO)
            {

#if(_SLEEP_AUDIO_SUPPORT == _ON)
                if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
                {
#if((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN))
                    return _TRUE;
#endif
                }
#endif
                if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) ||
                   ((SysModeGetModeState() == _MODE_STATUS_DISPLAY_SETTING) && (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)))
                {
                    return _TRUE;
                }
            }
            else
#endif
            {
            if(UserInterfaceGetAudioSource() == _DIGITAL_AUDIO)
            {

		//DebugMessageAudio("UserInterfaceGetAudioSource 0000" , 0);	
		//DebugMessageAudio("SysSourceGetInputPort 0000" , SysSourceGetInputPort());	
                if(ScalerAudioGetAudioDetected(SysSourceGetInputPort()) == _TRUE)
                {
#if(_SLEEP_AUDIO_SUPPORT == _ON)
                    if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
                    {
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
                        if(ScalerAudioGetDigitalAudioSource(SysSourceGetInputPort()) == _DIGITAL_AUDIO_SOURCE_DP)
                        {
                            // When Fixed Port, should not play DP Audio at different port
                            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetAudioPlaybackPort() == SysSourceGetInputPort()))
                            {
                                return _TRUE;
                            }
                        }
#endif
                    }
#endif
                    if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) || (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK))
                    {
                        return _TRUE;
                    }
                }
            }
            }
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : User OSD Get Audio Source
// Input Value  : None
// Output Value : _DIGITAL_AUDIO or _LINE_IN_AUDIO
//--------------------------------------------------
EnumAudioInputSource UserInterfaceGetAudioSource(void)
{
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable(SysSourceGetInputPort()) == _ENABLE)
    {
        return _DIGITAL_AUDIO;
    }
#endif

    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
        case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
        case _D1_INPUT_PORT:
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
        case _D2_INPUT_PORT:
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
        case _D3_INPUT_PORT:
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
        case _D4_INPUT_PORT:
#endif

#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
        case _D5_INPUT_PORT:
#endif

#if(_LINE_IN_SUPPORT == _ON)
#if(_EMBEDDED_DAC_SUPPORT == _ON)
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            if(UserInterfaceGetAudioStandAloneStatus() == _FALSE)
#endif
            {
                // Don't switch audio source if input source is not found
                if(SysSourceGetSourceType() == _SOURCE_NONE)
                {
                    return ScalerAudioDACGetInputSource();
                }
            }
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
// modify by sfy 20140915 for audito volume audo select 20140915 start //
       if(GET_OSD_AUDIO_SOURCE()==_AUTO_AUDIO)
       {
       return _LINE_IN_AUDIO; 
       }
       else
       {
           return GET_OSD_AUDIO_SOURCE();
       }
// modify by sfy 20140915 for audito volume audo select 20140915 end //


#else
            return _NO_AUDIO_SOURCE;
#endif // End of #if(_LINE_IN_SUPPORT == _ON)
       break;

        default:

#if(_LINE_IN_SUPPORT == _ON)
#if(_EMBEDDED_DAC_SUPPORT == _ON)
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_LINE_IN)))
            // Don't Switch Audio Source if Line In is Currently Playing unless Digital Source is found
            if(UserInterfaceGetAudioStandAloneStatus() == _TRUE)
            {
                if((SysSourceGetSourceType() == _SOURCE_NONE) && (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK) && (ScalerAudioDACGetInputSource() == _LINE_IN_AUDIO))
                {
                    return _LINE_IN_AUDIO;
                }
            }
#endif
#endif // End of #if(_EMBEDDED_DAC_SUPPORT == _ON)
// modify by sfy 20140915 for audito volume audo select 20140915 start //
//            return GET_OSD_AUDIO_SOURCE();

if(GET_OSD_AUDIO_SOURCE()==_AUTO_AUDIO)
{
				return _DIGITAL_AUDIO;
}
else
{
    return GET_OSD_AUDIO_SOURCE();
}
// modify by sfy 20140915 for audito volume audo select 20140915 end //
#else
            return _DIGITAL_AUDIO;
#endif // End of #if(_LINE_IN_SUPPORT == _ON)

            break;
    }
}

//--------------------------------------------------
// Description  : Get Current Audio Mute Status
// Input Value  : Node
// Output Value : Node
//--------------------------------------------------
bit UserInterfaceGetAudioMuteStatus(void)
{
    return GET_OSD_VOLUME_MUTE();
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
    return UserAdjustAudioVolumeMapping(GET_OSD_VOLUME());
}


#if(_EMBEDDED_DAC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DAC Output Switch
// Input Value  : None
// Output Value : EnumAudioDACOutput
//--------------------------------------------------
EnumAudioDACOutput UserInterfaceGetAudioDACOutput(void)
{
#if((_PCB_TYPE == _RL6449_SM2775YTA_1DP2H_VBO)||(_PCB_TYPE ==_RL6449_SM2775YTC_1DP2H_VBO))
if(PCB_EARPHONE_CONNECTED() ==0) //||(GET_OSD_VOLUME() ==0))
{
	//PCB_AMP_MUTE(_AMP_MUTE_ON);
    return _AUDIO_DAC_OUTPUT_HEADPHONE;
}
else
{
    //PCB_AMP_MUTE(_AMP_MUTE_OFF);	
    return _AUDIO_DAC_OUTPUT_SPEAKER;
}
#elif(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo

if(PCB_EARPHONE_CONNECTED() ) //||(GET_OSD_VOLUME() ==0))
{
	PCB_AMP_MUTE(_AMP_MUTE_ON);
         DebugMessageAudio("PCB_AMP_MUTE(_AMP_MUTE_OFF)0 33333", _AMP_MUTE_ON);
	 ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);// TDY aad for audio popo
    return _AUDIO_DAC_OUTPUT_HEADPHONE;
}
else
{
    return _AUDIO_DAC_OUTPUT_SPEAKER;
}


#else
    //return _AUDIO_DAC_OUTPUT_SPEAKER;
    return _AUDIO_DAC_OUTPUT_SPEAKER;	
#endif
}

bit UserInterfaceGetAudioDACKeepDepopState(void)
{
    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : Get Current Audio Stand Alone Status
// Input Value  : enumPowStatus
// Output Value : Node
//--------------------------------------------------
#if(_SLEEP_AUDIO_SUPPORT == _ON)
bit UserInterfaceGetAudioStandAloneStatus(void)
{
    return GET_OSD_AUDIO_STAND_ALONE();
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
#if((_DP_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))
            if(SysSourceGetAudioPlaybackPort() != SysSourceGetInputPort())
#endif
            {

                SysAudioMuteProc(_ON);
                ScalerAudioWatchDogProc(_OFF, ScalerAudioGetDigitalAudioPortMapping());

                SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
            }
        }
    }
    else
#endif
    {
        if(SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK)
        {

            SysAudioMuteProc(_ON);
            ScalerAudioWatchDogProc(_OFF, ScalerAudioGetDigitalAudioPortMapping());

            SysAudioChangeAudioState(_AUDIO_STATUS_PREPARING);
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
// Lee add for audio issue when ac on   20141011 start //   
    if(bMute == _OFF)
    {
        UserAdjustAudioVolume(GET_OSD_VOLUME());
    }
    else//(bMute == _AMP_MUTE_ON)
    {
        UserAdjustAudioVolume(0);
    }
// Lee add for audio issue when ac on   20141011 end // 
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
#endif//#if(_OSD_TYPE == _OSTAR_2014_OSD)

