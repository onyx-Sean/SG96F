#if(_OSD_TYPE == _OSTAR_2014_OSD)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
#define _A0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_VGA)
#else
#define _A0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
#define _D0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DVI)
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
#define _D0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_HDMI)
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
#define _D0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DP)
#elif(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#define _D0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_MHL)
#else
#define _D0_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
#define _D1_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DVI)
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
#define _D1_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_HDMI)
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#define _D1_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DP)
#elif(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#define _D1_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_MHL)
#else
#define _D1_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
#define _D2_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DVI)
#elif(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
#define _D2_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_HDMI)
#elif(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
#define _D2_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DP)
#elif(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#define _D2_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_MHL)
#else
#define _D2_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif


#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
#define _D3_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DVI)
#elif(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
#define _D3_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_HDMI)
#elif(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
#define _D3_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_MHL)
#else
#define _D3_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
#define _D4_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DVI)
#elif(_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)
#define _D4_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_HDMI)
#elif(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define _D4_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_MHL)
#else
#define _D4_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif


#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
#define _D5_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DVI)
#elif(_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)
#define _D5_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_HDMI)
#elif(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define _D5_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_MHL)
#else
#define _D5_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif



#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
#define _D6_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_DP)
#else
#define _D6_INPUT_TYPE                            (_OPTION_ICON_END+_INPUT_NO_PORT)
#endif


//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
#define _CONTRAST_MAX                             (2848+320) // 2848
#define _CONTRAST_MIN                             (1248+320) // 1248
#else
#define _CONTRAST_MAX                               178
#define _CONTRAST_MIN                               78
#endif

#define _CONTRAST_CENTER                            (((_CONTRAST_MAX - _CONTRAST_MIN) / 2) + _CONTRAST_MIN)

//--------------------------------------------------
// Definitions of Backlight Range
//--------------------------------------------------
#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)
#define _BACKLIGHT_MAX                             255// _PCB_BACKLIGHT_MAX
#else
#define _BACKLIGHT_MAX                              4095
#endif

#define _BACKLIGHT_MIN                              0// _PCB_BACKLIGHT_MIN   //  (((_BACKLIGHT_MAX - 0) *25/ 100) + 0)
#define _BACKLIGHT_CENTER                           (((_BACKLIGHT_MAX - _BACKLIGHT_MIN) / 2) + _BACKLIGHT_MIN)

#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
//--------------------------------------------------
// Definitions of Brightness Range
//--------------------------------------------------
#define _BLACK_EQUALIZER_MAX                             100  
#define _BLACK_EQUALIZER_MIN                             0 
#define _BLACK_EQUALIZER_CENTER                          (((_BLACK_EQUALIZER_MAX - _BLACK_EQUALIZER_MIN) / 2) + _BLACK_EQUALIZER_MIN)

#endif
//--------------------------------------------------
// Definitions of Brightness Range
//--------------------------------------------------
#if(_BRI_TYPE == _BRI_GEN_1_10BIT)
#define _BRIGHTNESS_MAX                             712
#define _BRIGHTNESS_MIN                             312
#else
#define _BRIGHTNESS_MAX                             178
#define _BRIGHTNESS_MIN                             78
#endif

#define _BRIGHTNESS_CENTER                          (((_BRIGHTNESS_MAX - _BRIGHTNESS_MIN) / 2) + _BRIGHTNESS_MIN)

//--------------------------------------------------
// Definitions of Sharpness Range
//--------------------------------------------------
#define _SHARPNESS_MAX                              4
#define _SHARPNESS_MIN                              0
#define _SHARPNESS_CENTER                          (((_SHARPNESS_MAX - _SHARPNESS_MIN) / 2) + _SHARPNESS_MIN)
//--------------------------------------------------
// Definitions of Phase Range
//--------------------------------------------------
#define _OSD_PHASE_MAX                              100
#define _OSD_PHASE_MIN                              0

//--------------------------------------------------
// Definitions of Colortemp User RGB
//--------------------------------------------------
#define _USER_RGB_MAX                               255
#define _USER_RGB_MIN                               0
#define _USER_RGB_CENTER                            (((_USER_RGB_MAX - _USER_RGB_MIN) / 2) + _USER_RGB_MIN)

//--------------------------------------------------
// Definitions of OD Gain Range
//--------------------------------------------------
#define _OD_GAIN_MAX                                127
#define _OD_GAIN_MIN                                0
#define _OD_GAIN_CENTER                             (((_OD_GAIN_MAX - _OD_GAIN_MIN) / 2) + _OD_GAIN_MIN)

//--------------------------------------------------
// Definitions of 3D EFFECT
//--------------------------------------------------
#define _3D_EFFECT_MAX                              0x10
#define _3D_EFFECT_MIN                              0x00

//--------------------------------------------------
// Definitions of 2DTO3D EFFECT
//--------------------------------------------------
#define _2DTO3D_H_EFFECT_MAX                        0x30
#define _2DTO3D_H_EFFECT_MIN                        0x00

#define _2DTO3D_H_V_EFFECT_MAX                      0xFF
#define _2DTO3D_H_V_EFFECT_MIN                      0x00

//--------------------------------------------------
// Definitions of Menu Time Range
//--------------------------------------------------
#define _OSD_TIMEOUT_MAX                            60
#define _OSD_TIMEOUT_MIN                            10
#define _OSD_TIMEOUT_CENTER                         (((_OSD_TIMEOUT_MAX - _OSD_TIMEOUT_MIN) / 2) + _OSD_TIMEOUT_MIN)
//--------------------------------------------------
// Definitions of Transparency Range
//--------------------------------------------------
#define _OSD_TRANSPARENCY_MAX                       200//255//tdy modify for ostar 20141112 //
#define _OSD_TRANSPARENCY_MIN                       0
#define _OSD_TRANSPARENCY_CENTER                    (((_OSD_TRANSPARENCY_MAX - _OSD_TRANSPARENCY_MIN) / 2) + _OSD_TRANSPARENCY_MIN)
//--------------------------------------------------
// Definitions of OSD H Position Range
//--------------------------------------------------
#define _OSD_H_POS_MAX                              100
#define _OSD_H_POS_MIN                              0
#define _OSD_H_POS_CENTER                           (((_OSD_H_POS_MAX - _OSD_H_POS_MIN) / 2) + _OSD_H_POS_MIN)

//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_V_POS_MAX                              100
#define _OSD_V_POS_MIN                              0
#define _OSD_V_POS_CENTER                           (((_OSD_V_POS_MAX - _OSD_V_POS_MIN) / 2) + _OSD_V_POS_MIN)



//--------------------------------------------------
// Definitions of OSD V Position Range
//--------------------------------------------------
#define _OSD_ASPECT_ORIGINAL_RATIO_MAX              100
#define _OSD_ASPECT_ORIGINAL_RATIO_MIN              0
#define _OSD_ASPECT_ORIGINAL_RATIO_CENTER           ((_OSD_ASPECT_ORIGINAL_RATIO_MAX - _OSD_ASPECT_ORIGINAL_RATIO_MIN) / 2)

//--------------------------------------------------
// Definitions of Hue Saturation Range
// Allowed Hue = 0 ~ 360, Sat = 0 ~ 330
//--------------------------------------------------
#define _DEFAULT_HUE                                _HUE_CENTER
#define _DEFAULT_SATURATION                         _SATURATION_CENTER

//--------------------------------------------------
// Definitions of OSD Volume Range
//--------------------------------------------------
#define _OSD_VOLUME_MAX                             100
#define _OSD_VOLUME_MIN                             0
#define _OSD_VOLUME_CENTER                          (((_OSD_VOLUME_MAX - _OSD_VOLUME_MIN) / 2) + _OSD_VOLUME_MIN)

//--------------------------------------------------
// Definitions of Hue Saturation Range
//--------------------------------------------------
#define _SIX_COLOR_SATURATION_MAX                   200
#define _SIX_COLOR_SATURATION_MIN                   0
#define _SIX_COLOR_SATURATION_CENTER                100

#define _SIX_COLOR_HUE_MAX                          100
#define _SIX_COLOR_HUE_MIN                          0
#define _SIX_COLOR_HUE_CENTER                       50

//--------------------------------------------------
// Macro of Key Scan Start Flag
//--------------------------------------------------
#define GET_KEYSCANSTART()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT1))
#define SET_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT1)
#define CLR_KEYSCANSTART()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT1)

//--------------------------------------------------
// Macro of Key Scan Ready Flag
//--------------------------------------------------
#define GET_KEYSCANREADY()                          ((bit)(g_stOsdInfo.ucOsdKeyControl & _BIT0))
#define SET_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl |= _BIT0)
#define CLR_KEYSCANREADY()                          (g_stOsdInfo.ucOsdKeyControl &= ~_BIT0)

//--------------------------------------------------
// Macro of Key Repeat Start
//--------------------------------------------------
#define GET_KEYREPEATSTART()                        (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT2)
#define SET_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl |= _BIT2)
#define CLR_KEYREPEATSTART()                        (g_stOsdInfo.ucOsdKeyControl &= ~_BIT2)

//--------------------------------------------------
// Macro of Key Repeat Function Enable
// If you want to use repeat function, please set this flag. If not, please clear it.
//--------------------------------------------------
#define GET_KEYREPEATENABLE()                       (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT3)
#define SET_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl |= _BIT3)
#define CLR_KEYREPEATENABLE()                       (g_stOsdInfo.ucOsdKeyControl &= ~_BIT3)

//--------------------------------------------------
// Macro of Key Hold Start
//--------------------------------------------------
#define GET_KEY_HOLD()                              (bit)(g_stOsdInfo.ucOsdKeyControl & _BIT4)
#define SET_KEY_HOLD()                              (g_stOsdInfo.ucOsdKeyControl |= _BIT4)
#define CLR_KEY_HOLD()                              (g_stOsdInfo.ucOsdKeyControl &= ~_BIT4)

#if(_FREESYNC_SUPPORT == _ON)
#define GET_FREESYNC_OSD_ADDRESS()                  (g_stOsdInfo.ucOsdFREESYNCInforOsdAddress)
#define SET_FREESYNC_OSD_ADDRESS(x)                 (g_stOsdInfo.ucOsdFREESYNCInforOsdAddress = (x))
#endif

//--------------------------------------------------
// Macro of Key Message
//--------------------------------------------------
#define GET_KEYMESSAGE()                            (g_stOsdInfo.ucOsdKeyMessage)
#define SET_KEYMESSAGE(x)                           (g_stOsdInfo.ucOsdKeyMessage = (x))

//--------------------------------------------------
// Definitions of Key Message
//--------------------------------------------------
#define _MENU_KEY_MESSAGE                           0
#define _RIGHT_KEY_MESSAGE                          1
#define _LEFT_KEY_MESSAGE                           2
#define _EXIT_KEY_MESSAGE                           3
//------------------------------------------------------------------------//
#define _UP_KEY_MESSAGE                              4
#define _DOWN_KEY_MESSAGE                            5
//------------------------------------------------------------------------//
#define _7_KEY_MESSAGE                              6
#define _HOLD_KEY_MESSAGE                           7
#define _NONE_KEY_MESSAGE                           8
#define _LEFT_RIGHT_KEY_MESSAGE               9
#define _KEY_AMOUNT                                 4

//--------------------------------------------------
// Definitions of LED indicction
//--------------------------------------------------
typedef enum
{
    _LED_ALL_OFF = _LED_SYSTEM_END,
} EnumUserLedIndication;

//--------------------------------------------------
// Macro of OSD
//--------------------------------------------------
#define FONTBYTE0(x)                                HIBYTE(0x1000 | (x)),LOBYTE(0x1000 | (x))
#define FONTBYTE1(x)                                HIBYTE(0x5000 | (x)),LOBYTE(0x5000 | (x))
#define FONTBYTE2(x)                                HIBYTE(0x9000 | (x)),LOBYTE(0x9000 | (x))
#define FONTALLBYTE(x)                              HIBYTE(0xD000 | (x)),LOBYTE(0xD000 | (x))
#define WINDOWBYTE0(x)                              HIBYTE(0x0000 | (x)),LOBYTE(0x0000 | (x))
#define WINDOWBYTE1(x)                              HIBYTE(0x4000 | (x)),LOBYTE(0x4000 | (x))
#define WINDOWBYTE2(x)                              HIBYTE(0x8000 | (x)),LOBYTE(0x8000 | (x))
#define WINDOWALLBYTE(x)                            HIBYTE(0xC000 | (x)),LOBYTE(0xC000 | (x))
#define FRAMEBYTE0(x)                               WINDOWBYTE0(x)
#define FRAMEBYTE1(x)                               WINDOWBYTE1(x)
#define FRAMEBYTE2(x)                               WINDOWBYTE2(x)
#define FRAMEALLBYTE(x)                             WINDOWALLBYTE(x)
#define WINNO(x)                                    (x)
#define ROW(x)                                      (x)
#define COL(x)                                      (x)
#define WIDTH(x)                                    (x)
#define HEIGHT(x)                                   (x)
#define LENGTH(x)                                   (x)
#define FGCOLOR(x)                                  (x)
#define BGCOLOR(x)                                  (x)
#define COLOR00(x)                                  (x)
#define COLOR01(x)                                  (x)
#define COLOR10(x)                                  (x)
#define COLOR11(x)                                  (x)
#define XSTART(x)                                   (x)
#define YSTART(x)                                   (x)
#define XEND(x)                                     (x)
#define YEND(x)                                     (x)
#define PIXELROW(x)                                 (x * 18)
#define PIXELCOL(x)                                 (x * 12)

//--------------------------------------------------
// Definitions of Checking Max or Min Value Used by OsdDisplayDetOverRange()
//--------------------------------------------------
#define _DET_OVERRANGE_MAX                          (0)
#define _DET_OVERRANGE_MIN                          (1)

//--------------------------------------------------
// Definations of OSD Function
//--------------------------------------------------
#define _SPACE_                                     0xfc
#define _EXT_                                       0xfc
#define _REPEAT_                                    0xfd
#define _NEXT_                                      0xfe
#define _END_                                       0xff


//--------------------------------------------------
// Definations of Write Byte
//--------------------------------------------------
#define _WRITE_BYTE0                                0
#define _WRITE_BYTE1                                1
#define _WRITE_BYTE2                                2
#define _WRITE_BYTEALL                              3


//--------------------------------------------------
// MACRO for OSD Logo Status
//--------------------------------------------------
#define GET_OSD_LOGO_ON()                           (g_stOsdInfo.b1OsdLogo)
#define SET_OSD_LOGO_ON(x)                          (g_stOsdInfo.b1OsdLogo = (x))

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_WAKE_UP_SWITCH_DDCCI_PORT()         (g_stOsdInfo.b1OsdWakeUpSwitchDdcciPort)
#define SET_OSD_WAKE_UP_SWITCH_DDCCI_PORT(x)        (g_stOsdInfo.b1OsdWakeUpSwitchDdcciPort = (x))

//--------------------------------------------------
// MACRO for Power Saving Show Source
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_SOURCE()          (g_stOsdInfo.b1OsdWakeUpShowSource)
#define SET_OSD_POWER_SAVING_SHOW_SOURCE(x)         (g_stOsdInfo.b1OsdWakeUpShowSource = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
#define GET_OSD_IN_FACTORY_MENU_STATUS()            (g_stOsdInfo.b1OsdFactoryModeStatus)
#define SET_OSD_IN_FACTORY_MENU_STATUS(x)           (g_stOsdInfo.b1OsdFactoryModeStatus = (x))

//--------------------------------------------------
// MACRO for Source Menu Status
//--------------------------------------------------
#define GET_OSD_DO_ASPECT_RATIO()                   (g_stOsdInfo.b1OsdDoAspectRatio)
#define SET_OSD_DO_ASPECT_RATIO(x)                  (g_stOsdInfo.b1OsdDoAspectRatio = (x))

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_COLOR_FORMAT()                      (g_stOsdInfo.b3OsdColorFormat)
#define SET_OSD_COLOR_FORMAT(x)                     (g_stOsdInfo.b3OsdColorFormat = (x))

//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_STATE_PREVIOUS()                    (g_stOsdInfo.ucOsdStatePrevious)
#define SET_OSD_STATE_PREVIOUS(x)                   (g_stOsdInfo.ucOsdStatePrevious = (x))


//--------------------------------------------------
// MACRO for Osd Status
//--------------------------------------------------
#define GET_OSD_STATE()                             (g_stOsdInfo.ucOsdState)
#define SET_OSD_STATE(x)                            (g_stOsdInfo.ucOsdState = (x))

//--------------------------------------------------
// MACRO for Osd Evevt Message
//--------------------------------------------------
#define GET_OSD_EVENT_MESSAGE()                     (g_stOsdInfo.ucOsdEventMsg)
#define SET_OSD_EVENT_MESSAGE(x)                    (g_stOsdInfo.ucOsdEventMsg = (x))

//--------------------------------------------------
// MACRO for Six Color
//--------------------------------------------------
#define GET_OSD_SIX_COLOR()                         (g_stOsdInfo.b3OsdsixColor)
#define SET_OSD_SIX_COLOR(x)                        (g_stOsdInfo.b3OsdsixColor = (x))

//--------------------------------------------------
// MACRO for Six Color Hue
//--------------------------------------------------
#define GET_OSD_SIX_COLOR_HUE()                     (g_stOsdInfo.b3OsdsixColorHue)
#define SET_OSD_SIX_COLOR_HUE(x)                    (g_stOsdInfo.b3OsdsixColorHue = (x))

//--------------------------------------------------
// MACRO for Six Color Saturation
//--------------------------------------------------
#define GET_OSD_SIX_COLOR_SATURATION()              (g_stOsdInfo.b3OsdsixColorSaturation)
#define SET_OSD_SIX_COLOR_SATURATION(x)             (g_stOsdInfo.b3OsdsixColorSaturation = (x))


//--------------------------------------------------
// MACRO for Freeze Status
//--------------------------------------------------
#define GET_OSD_FREEZE_STATUS()                     (g_stOsdInfo.b1FreezeStatus)
#define SET_OSD_FREEZE_STATUS(x)                    (g_stOsdInfo.b1FreezeStatus = (x))

#if((_URGENT_EVENT_CHECK_MODE == _OFF) && (_FREEZE_SUPPORT == _ON))
#define GET_FREEZE_DISABLE_MSG_STATE()              (g_stOsdInfo.b1FreezeDisableOsdStatus)
#define SET_FREEZE_DISABLE_MSG_STATE(x)             (g_stOsdInfo.b1FreezeDisableOsdStatus = (x))
#endif

//==========================================================================================================
// Macro of NVRam BriCon Data
//==========================================================================================================
//--------------------------------------------------
// MACRO for Contrast
//--------------------------------------------------
#define GET_OSD_CONTRAST()                          (g_stBriConData.usContrast)
#define SET_OSD_CONTRAST(x)                         (g_stBriConData.usContrast = (x))

//--------------------------------------------------
// MACRO for Contrast
//--------------------------------------------------
#define GET_OSD_BRIGHTNESS()                        (g_stBriConData.usBrightness)
#define SET_OSD_BRIGHTNESS(x)                       (g_stBriConData.usBrightness = (x))

//==========================================================================================================
// Macro of NVRam User Data
//==========================================================================================================
//--------------------------------------------------
// MACRO for Rotation Status
//--------------------------------------------------
#if(_DISPLAY_ROTATION_SUPPORT ==_ON)
#define GET_OSD_DISP_ROTATION_SIZE_TYPE()           (g_stOSDUserData.b2DispRotationSizeType)
#define SET_OSD_DISP_ROTATION_SIZE_TYPE(x)          (g_stOSDUserData.b2DispRotationSizeType = (x))
#endif


//--------------------------------------------------
// MACRO for DP Port Version
//--------------------------------------------------
#define GET_OSD_DP_D0_VERSION()                     (g_stOSDUserData.b1OsdDpD0PortVersion)
#define SET_OSD_DP_D0_VERSION(x)                    (g_stOSDUserData.b1OsdDpD0PortVersion = (x))

#define GET_OSD_DP_D1_VERSION()                     (g_stOSDUserData.b1OsdDpD1PortVersion)
#define SET_OSD_DP_D1_VERSION(x)                    (g_stOSDUserData.b1OsdDpD1PortVersion = (x))

#define GET_OSD_DP_D2_VERSION()                     (g_stOSDUserData.b1OsdDpD2PortVersion)
#define SET_OSD_DP_D2_VERSION(x)                    (g_stOSDUserData.b1OsdDpD2PortVersion = (x))

#define GET_OSD_DP_D6_VERSION()                     (g_stOSDUserData.b1OsdDpD6PortVersion)
#define SET_OSD_DP_D6_VERSION(x)                    (g_stOSDUserData.b1OsdDpD6PortVersion = (x))

#define GET_OSD_DP_MST()                            (g_stOSDUserData.b2OsdDpMST)
#define SET_OSD_DP_MST(x)                           (g_stOSDUserData.b2OsdDpMST = (x))

//--------------------------------------------------
// MACRO for Display Rotate
//--------------------------------------------------
#define GET_OSD_DISP_ROTATE()                       (g_stOSDUserData.b3OsdDispRotate)	
#define SET_OSD_DISP_ROTATE(x)                      (g_stOSDUserData.b3OsdDispRotate = (x))	 

//--------------------------------------------------
// MACRO for Latency
//--------------------------------------------------
#define GET_OSD_LATENCY()                           (g_stOSDUserData.b2LatencyStatus)
#define SET_OSD_LATENCY(x)                          (g_stOSDUserData.b2LatencyStatus = (x))

//--------------------------------------------------
// MACRO for Display Rotate
//--------------------------------------------------
#define GET_OSD_DP_VERSION_HOTKEY_DISP()            (g_stOSDUserData.b1OsdDpVersionHotKeyDisp)
#define SET_OSD_DP_VERSION_HOTKEY_DISP(x)           (g_stOSDUserData.b1OsdDpVersionHotKeyDisp = (x))

//--------------------------------------------------
// MACRO for Display
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_DP_OPTION()       (g_stOSDUserData.b1PreShowDpHotKeyVersion)
#define SET_OSD_POWER_SAVING_SHOW_DP_OPTION(x)      (g_stOSDUserData.b1PreShowDpHotKeyVersion = (x))

//--------------------------------------------------
// MACRO for Panel Uniformity
//--------------------------------------------------
#define GET_OSD_PANEL_UNIFORMITY()                  (g_stOSDUserData.b1PanelUniformity)
#define SET_OSD_PANEL_UNIFORMITY(x)                 (g_stOSDUserData.b1PanelUniformity = (x))

//--------------------------------------------------
// MACRO for Panel Uniformity
//--------------------------------------------------
#define GET_OSD_PANEL_UNIFORMITY_TYPE()             (g_stOSDUserData.b3PanelUniformityType)
#define SET_OSD_PANEL_UNIFORMITY_TYPE(x)            (g_stOSDUserData.b3PanelUniformityType = (x))

#define GET_OSD_FactoryIn_TYPE()             (g_stOSDUserData.b3FactoryIn)
#define SET_OSD_FactoryIn_TYPE(x)            (g_stOSDUserData.b3FactoryIn = (x))
//--------------------------------------------------
// MACRO for PCM Soft Proft
//--------------------------------------------------

#define GET_OSD_PCM_SOFT_PROFT_MODE()               (g_stOSDUserData.b1PCMSoftProftMode)
#define SET_OSD_PCM_SOFT_PROFT_MODE(x)              (g_stOSDUserData.b1PCMSoftProftMode = (x))

//--------------------------------------------------
// MACRO for OSD Input Port Value
//--------------------------------------------------
#define GET_OSD_INPUT_PORT_OSD_ITEM()               (g_stOSDUserData.ucOsdInputPort)
#define SET_OSD_INPUT_PORT_OSD_ITEM(x)              (g_stOSDUserData.ucOsdInputPort = (x))


//--------------------------------------------------
// MACRO for OSD Rotate
//--------------------------------------------------
#define GET_OSD_ROTATE_STATUS()                     (g_stOSDUserData.b2OsdRotate)
#define SET_OSD_ROTATE_STATUS(x)                    (g_stOSDUserData.b2OsdRotate = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_3DOSD_STATUS()                      (g_stOSDUserData.b1Osd3DOSD)
#define SET_OSD_3DOSD_STATUS(x)                     (g_stOSDUserData.b1Osd3DOSD = (x))

//--------------------------------------------------
// Macro of BackLight
//--------------------------------------------------
#define GET_OSD_BACKLIGHT()                         (g_stOSDUserData.usBackLight)
#define SET_OSD_BACKLIGHT(x)                        (g_stOSDUserData.usBackLight = (x))

//--------------------------------------------------
// Macro of Aspect Origin Ratio
//--------------------------------------------------
//#define GET_OSD_ASPECT_ORIGIN_RATIO()               (g_stOSDUserData.ucAspectOriginRatio)
//#define SET_OSD_ASPECT_ORIGIN_RATIO(x)              (g_stOSDUserData.ucAspectOriginRatio = (x))

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()                       (g_stOSDUserData.b4ColorTempType)
#define SET_COLOR_TEMP_TYPE(x)                      (g_stOSDUserData.b4ColorTempType = (x))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_R()                (g_stColorProcData.usColorTempR >> 4)
#define SET_COLOR_TEMP_TYPE_USER_R(x)               (g_stColorProcData.usColorTempR = (x<<4))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_G()                (g_stColorProcData.usColorTempG >> 4)
#define SET_COLOR_TEMP_TYPE_USER_G(x)               (g_stColorProcData.usColorTempG = (x<<4))
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_B()                (g_stColorProcData.usColorTempB >> 4)
#define SET_COLOR_TEMP_TYPE_USER_B(x)               (g_stColorProcData.usColorTempB = (x<<4))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_ASPECT_RATIO_TYPE()                 (g_stOSDUserData.b3AspectRatio)
#define SET_OSD_ASPECT_RATIO_TYPE(x)                (g_stOSDUserData.b3AspectRatio = (x))

//--------------------------------------------------
// MACRO for VGA Color Format Status
//--------------------------------------------------
#define GET_VGA_COLOR_FORMAT_STATUS()               (g_stOSDUserData.b3VGARGBYUV)
#define SET_VGA_COLOR_FORMAT_STATUS(x)              (g_stOSDUserData.b3VGARGBYUV = (x))

//--------------------------------------------------
// MACRO for VGA Color Format Status
//--------------------------------------------------
#define GET_DVI_COLOR_FORMAT_STATUS()               (g_stOSDUserData.b3DVIRGBYUV)
#define SET_DVI_COLOR_FORMAT_STATUS(x)              (g_stOSDUserData.b3DVIRGBYUV = (x))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_DDCCI_STATUS()                      (g_stOSDUserData.b1DDCCIStatus)
#define SET_OSD_DDCCI_STATUS(x)                     (g_stOSDUserData.b1DDCCIStatus = (x))

//--------------------------------------------------
// MACRO for Ultra Vivid Status
//--------------------------------------------------
#define GET_OSD_ULTRA_VIVID_STATUS()                (g_stOSDUserData.b2UltraVividStatus)
#define SET_OSD_ULTRA_VIVID_STATUS(x)               (g_stOSDUserData.b2UltraVividStatus = (x))

//--------------------------------------------------
// MACRO for Sharpness
//--------------------------------------------------
#define GET_OSD_SHARPNESS()                         (g_stOSDUserData.b3Sharpness)
#define SET_OSD_SHARPNESS(x)                        (g_stOSDUserData.b3Sharpness = (x))

//--------------------------------------------------
// MACRO for Transparency
//--------------------------------------------------
#define GET_OSD_TRANSPARENCY_STATUS()               (g_stOSDUserData.ucTransparency)
#define SET_OSD_TRANSPARENCY_STATUS(x)              (g_stOSDUserData.ucTransparency = (x))

//--------------------------------------------------
// MACRO for Language
//--------------------------------------------------
#define GET_OSD_LANGUAGE()                          (g_stOSDUserData.b4Language)
#define SET_OSD_LANGUAGE(x)                         (g_stOSDUserData.b4Language = (x))

//--------------------------------------------------
// MACRO for Language
//--------------------------------------------------
#define GET_OSD_AIM()                          (g_stOSDUserData.aim)
#define SET_OSD_AIM(x)                         (g_stOSDUserData.aim = (x))

// MACRO for Language
//--------------------------------------------------
#define GET_OSD_Timer()                          (g_stOSDUserData.timernumber)
#define SET_OSD_Timer(x)                         (g_stOSDUserData.timernumber = (x))
//--------------------------------------------------
#define GET_OSD_Left_Menu_Choose()                          (g_stOSDUserData.leftMenuChoose)
#define SET_OSD_Left_Menu_Choose(x)                         (g_stOSDUserData.leftMenuChoose = (x))
//--------------------------------------------------
#define GET_OSD_Left_Timer_Position()                          (g_stOSDUserData.leftTimerPosition)
#define SET_OSD_Left_Timer_Position(x)                         (g_stOSDUserData.leftTimerPosition = (x))

//--------------------------------------------------
// MACRO for OsdTimeout
//--------------------------------------------------
#define GET_OSD_TIME_OUT()                          (g_stOSDUserData.ucOsdTimeout)
#define SET_OSD_TIME_OUT(x)                         (g_stOSDUserData.ucOsdTimeout = (x))

//--------------------------------------------------
// MACRO for OsdHPos
//--------------------------------------------------
#define GET_OSD_HPOS()                              (g_stOSDUserData.ucOsdHPos)
#define SET_OSD_HPOS(x)                             (g_stOSDUserData.ucOsdHPos = (x))

//--------------------------------------------------
// MACRO for OsdVPos
//--------------------------------------------------
#define GET_OSD_VPOS()                              (g_stOSDUserData.ucOsdVPos)
#define SET_OSD_VPOS(x)                             (g_stOSDUserData.ucOsdVPos = (x))
//--------------------------------------------------
// MACRO for OsdVPos
//--------------------------------------------------
#define GET_OSD_GAMMA()                             (g_stOSDUserData.b3Gamma)
#define SET_OSD_GAMMA(x)                            (g_stOSDUserData.b3Gamma = (x))

//--------------------------------------------------
// MACRO for OD Status
//--------------------------------------------------
#define GET_OSD_OD_STATUS()                         (g_stOSDUserData.b1ODStatus)
#define SET_OSD_OD_STATUS(x)                        (g_stOSDUserData.b1ODStatus = (x))

//--------------------------------------------------
// MACRO for OD Gain
//--------------------------------------------------
#define GET_OSD_OD_GAIN()                           (g_stOSDUserData.ucODGain)
#define SET_OSD_OD_GAIN(x)                          (g_stOSDUserData.ucODGain = (x))

//--------------------------------------------------
// MACRO for Color Effect
//--------------------------------------------------
#define GET_OSD_COLOR_EFFECT()                      (g_stOSDUserData.b4ColorEffect)
#define SET_OSD_COLOR_EFFECT(x)                     (g_stOSDUserData.b4ColorEffect = (x))
//--------------------------------------------------
// PictureMainSR
//--------------------------------------------------
//#define GET_PICTURE_MAIN_SR()                    (g_stOSDUserData.PictureMainsr)
//#define SET_PICTURE_MAIN_SR(x)                   (g_stOSDUserData.PictureMainsr = (x))

//--------------------------------------------------
// MACRO for DCRStatus
//--------------------------------------------------
#define GET_OSD_DCR_STATUS()                         (g_stOSDUserData.b1OsdDcrStatus)
#define SET_OSD_DCR_STATUS(x)                        (g_stOSDUserData.b1OsdDcrStatus = (x))

//--------------------------------------------------
// MACRO for FreeSync Status
//--------------------------------------------------
#define GET_OSD_FREE_SYNC_STATUS()                   (g_stOSDUserData.b1FreeSyncStatus)
#define SET_OSD_FREE_SYNC_STATUS(x)                  (g_stOSDUserData.b1FreeSyncStatus = (x))

//--------------------------------------------------
// MACRO for Clone Mode
//--------------------------------------------------
#define GET_OSD_CLONE_MODE()                         (g_stOSDUserData.b1CloneMode)
#define SET_OSD_CLONE_MODE(x)                        (g_stOSDUserData.b1CloneMode = (x))

//--------------------------------------------------
// MACRO for Volume Mute
//--------------------------------------------------
#define GET_OSD_VOLUME_MUTE()                       (g_stOSDUserData.b1VolumeMute)
#define SET_OSD_VOLUME_MUTE(x)                      (g_stOSDUserData.b1VolumeMute = (x))

//--------------------------------------------------
// MACRO for Volume
//--------------------------------------------------
#define GET_OSD_VOLUME()                            (g_stOSDUserData.ucVolume)
#define SET_OSD_VOLUME(x)                           (g_stOSDUserData.ucVolume = (x))

//--------------------------------------------------
// MACRO for Audio Stand a long
//--------------------------------------------------
#define GET_OSD_AUDIO_STAND_ALONE()                 (g_stOSDUserData.b1AudioStandAloneStatus)
#define SET_OSD_AUDIO_STAND_ALONE(x)                (g_stOSDUserData.b1AudioStandAloneStatus = (x))

//--------------------------------------------------
// MACRO for Audio Source
//--------------------------------------------------
// add by sfy for audio volume auto select 20140915 start //
#if(_AUDIO_AMOUNT==_AUTO_AUDIO)	
#define GET_OSD_AUDIO_SOURCE()                      (g_stOSDUserData.b2AudioSourceStatus)
#define SET_OSD_AUDIO_SOURCE(x)                     (g_stOSDUserData.b2AudioSourceStatus = (x))
#else
 // add by sfy for audio volume auto select 20140915 end //
#define GET_OSD_AUDIO_SOURCE()                      (g_stOSDUserData.b1AudioSourceStatus)
#define SET_OSD_AUDIO_SOURCE(x)                     (g_stOSDUserData.b1AudioSourceStatus = (x))
#endif // add by sfy for audio volume auto select 20140915 //


//--------------------------------------------------
// MACRO for Factory Burnin Status
//--------------------------------------------------
#define GET_OSD_FACTORY_BURNIN_STATUS()                      (g_stOSDUserData.b1FactoryBurninStatus)// Lee add for factory burnin model   20141011//	
#define SET_OSD_FACTORY_BURNIN_STATUS(x)                     (g_stOSDUserData.b1FactoryBurninStatus = (x))// Lee add for factory burnin model   20141011//	

#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
#define GET_OSD_LOWBLUELIGHT_STATUS()                      (g_stOSDUserData.b1LowBlueLightStatus)// Lee add for LowBlueLight function flg    20141024//	
#define SET_OSD_LOWBLUELIGHT_STATUS(x)                     (g_stOSDUserData.b1LowBlueLightStatus = (x))// Lee add for LowBlueLight function flg    20141024//		
#endif
//--------------------------------------------------------
#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
#define GET_OSD_BLACK_EQUALIZER1()                      (g_stOSDUserData.ucBlackeQualizerFPS1)// Lee add for BlackeQualizer function FPS1 flg     20141024//	
#define SET_OSD_BLACK_EQUALIZER1(x)                     (g_stOSDUserData.ucBlackeQualizerFPS1 = (x))// Lee add for BlackeQualizer function FPS1 flg    20141024//		
#endif

//--------------------------------------------------
// MACRO for Hue
//--------------------------------------------------
#define GET_OSD_HUE()                               (g_stOSDUserData.ucHue)
#define SET_OSD_HUE(x)                              (g_stOSDUserData.ucHue = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_SATURATION()                        (g_stOSDUserData.ucSaturation)
#define SET_OSD_SATURATION(x)                       (g_stOSDUserData.ucSaturation = (x))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_OVERSCAN_STATUS()                   (g_stOSDUserData.b1OverScan)
#define SET_OSD_OVERSCAN_STATUS(x)                  (g_stOSDUserData.b1OverScan = (x))

//--------------------------------------------------
// MACRO for Saturation
//--------------------------------------------------
#define GET_OSD_HLWIN_TYPE()                     _HL_WIN_OFF//   (g_stOSDUserData.ucHLWinType)
//#define SET_OSD_HLWIN_TYPE(x)                       (g_stOSDUserData.ucHLWinType = (x))

//--------------------------------------------------
// MACRO for 3D Status
//--------------------------------------------------
#define GET_OSD_3D_STATUS()                         (g_stOSDUserData.b23DStatus)
#define SET_OSD_3D_STATUS(x)                        (g_stOSDUserData.b23DStatus = (x))

//--------------------------------------------------
// MACRO for 3D LR Status
//--------------------------------------------------
#define GET_OSD_3D_LR_STATUS()                      (g_stOSDUserData.b13DLRStatus)
#define SET_OSD_3D_LR_STATUS(x)                     (g_stOSDUserData.b13DLRStatus = (x))

//--------------------------------------------------
// MACRO for 3D Format Status
//--------------------------------------------------
#define GET_OSD_3D_FORMAT_STATUS()                  (g_stOSDUserData.b23DFormatStatus)
#define SET_OSD_3D_FORMAT_STATUS(x)                 (g_stOSDUserData.b23DFormatStatus = (x))

//--------------------------------------------------
// MACRO for 3D EFFECT
//--------------------------------------------------
#define GET_OSD_3D_EFFECT()                         (g_stOSDUserData.uc3DEffect)
#define SET_OSD_3D_EFFECT(x)                        (g_stOSDUserData.uc3DEffect = (x))

//--------------------------------------------------
// MACRO for 3D 3DTO2D
//--------------------------------------------------
#define GET_OSD_3D_3DTO2D()                         (g_stOSDUserData.b13D3DTO2DStatus)
#define SET_OSD_3D_3DTO2D(x)                        (g_stOSDUserData.b13D3DTO2DStatus = (x))

//--------------------------------------------------
// MACRO for 3D Convergence
//--------------------------------------------------
#define GET_OSD_3D_CONVERGENCE()                    (g_stOSDUserData.uc3DConvergence)
#define SET_OSD_3D_CONVERGENCE(x)                   (g_stOSDUserData.uc3DConvergence = (x))

//--------------------------------------------------
// MACRO for 3D Convergence Mode
//--------------------------------------------------
#define GET_OSD_3D_CONVERGENCE_MODE()               (g_stOSDUserData.b33DConvergenceMode)
#define SET_OSD_3D_CONVERGENCE_MODE(x)              (g_stOSDUserData.b33DConvergenceMode = (x))

//--------------------------------------------------
// MACRO for Auto-Color Type
//--------------------------------------------------
#define _AUTO_COLOR_TYPE_INTERNAL                   0
#define _AUTO_COLOR_TYPE_EXTERNAL                   1

#define GET_OSD_FACTORY_AUTO_COLOR_TYPE()           (g_stOSDUserData.b1FactoryAutoColorType)
#define SET_OSD_FACTORY_AUTO_COLOR_TYPE(x)          (g_stOSDUserData.b1FactoryAutoColorType = (x))

//--------------------------------------------------
// MACRO for PCM Status
//--------------------------------------------------
#define GET_OSD_PCM_STATUS()                        (g_stOSDUserData.b3PCMStatus)
#define SET_OSD_PCM_STATUS(x)                       (g_stOSDUserData.b3PCMStatus = (x))

//--------------------------------------------------
// MACRO for Panel Time Min
//--------------------------------------------------
#define GET_PANEL_TIME_MIN()                        (g_stPanelTimeData.ucMin)
#define SET_PANEL_TIME_MIN(x)                       (g_stPanelTimeData.ucMin = (x))

//--------------------------------------------------
// MACRO for Panel Time Hour
//--------------------------------------------------
#define GET_PANEL_TIME_HOUR()                       (g_stPanelTimeData.usHour)
#define SET_PANEL_TIME_HOUR(x)                      (g_stPanelTimeData.usHour = (x))

//--------------------------------------------------
// MACRO for Factory Power Saving Case
//--------------------------------------------------
#define GET_FORCE_POW_SAV_STATUS()                  (g_bForcePowSavStatus)
#define SET_FORCE_POW_SAV_STATUS(x)                 (g_bForcePowSavStatus = (x))


#if(_USE_TIME_SUPPORT == _ON)
//--------------------------------------------------
// MACRO of OSD Timer Flag  status
//--------------------------------------------------
#define GET_OSDTimerFLG_STATUS()               ((bit)((g_stOSDUserData.ucMonitorFlag)& _BIT6))
#define SET_OSDTimerFLG_STATUS(x)               (g_stOSDUserData.ucMonitorFlag = ((g_stOSDUserData.ucMonitorFlag & ~_BIT6) | (x<<6)))

//--------------------------------------------------
// MACRO of ucPlusTimer  status
//--------------------------------------------------
//#define GET_OSD_PlusTimer_STATUS()                     (g_stOSDUserData.ucPlusTimer)
//#define SET_OSD_PlusTimer_STATUS(x)                    (g_stOSDUserData.ucPlusTimer = (x))
#endif

//--------------------------------------------------
// Definitions of OSD Number ROW COL
//--------------------------------------------------
#if( _OSTAR_OSD_SMALL ==  _ON)	 
#define _OSD_NUMBER_1_ROW                          (12-5)
#define _OSD_NUMBER_2_ROW                          (15-6)
#define _OSD_NUMBER_3_ROW                          (18-7)
#else
#define _OSD_RELATIVE_POSITION_ROW                 4
#define _OSD_NUMBER_1_ROW                           4
#define _OSD_NUMBER_2_ROW                           7
#define _OSD_NUMBER_3_ROW                           10
#define _OSD_NUMBER_4_ROW                           13
#define _OSD_NUMBER_11_ROW                         16
#define _OSD_NUMBER_12_ROW                         19
#define _OSD_NUMBER_13_ROW                         22

#define _OSD_NUMBER_5_ROW                           3
#define _OSD_NUMBER_6_ROW                           (_OSD_NUMBER_5_ROW+(_OSD_RELATIVE_POSITION_ROW*1))
#define _OSD_NUMBER_7_ROW                           (_OSD_NUMBER_5_ROW+(_OSD_RELATIVE_POSITION_ROW*2))
#define _OSD_NUMBER_8_ROW                           (_OSD_NUMBER_5_ROW+(_OSD_RELATIVE_POSITION_ROW*3))
#define _OSD_NUMBER_9_ROW                           (_OSD_NUMBER_5_ROW+(_OSD_RELATIVE_POSITION_ROW*4))
#define _OSD_NUMBER_10_ROW                          13
#define _OSD_TIMER_NUMBER_1_ROW                          8

#endif

#if  (_OSD_ROTATE_DEGREE_180_WIDTH == _ON)
#define _OSD_WINDOW_CHOOSE_WIDTH_1  			13 
#define _OSD_WINDOW_CHOOSE_WIDTH_2  			12 
#else
#define _OSD_WINDOW_CHOOSE_WIDTH_1  			14 
#define _OSD_WINDOW_CHOOSE_WIDTH_2  			13 
#endif




  #if( _OSTAR_OSD_SMALL ==  _ON)   
#define _OSD_NUMBER_1_COL                         (8-5) // 8    
#define _OSD_NUMBER_2_COL                          (23-5)  // 23

#define _OSD_NUMBER_3_COL                          (55-15) //  55
#define _OSD_NUMBER_4_COL                          ( 55+15-15) //  55+15

#define _OSD_NUMBER_5_COL                         (104-25) //   104
#define _OSD_NUMBER_6_COL                           (104+15-25)//  104+15
#define _OSD_SLIDE_VALUE_OFFSET                         (20-6) //20
#else

#define _OSD_NUMBER_1_COL                          21    
#define _OSD_NUMBER_2_COL                          38

#define _OSD_NUMBER_3_COL                            55
#define _OSD_NUMBER_4_COL                           (55+15)

#define _OSD_NUMBER_5_COL                           104
#define _OSD_NUMBER_6_COL                             (104+15)
#define _OSD_NUMBER_7_COL                             2
#define _OSD_NUMBER_10_COL                          37
#define _OSD_NUMBER_11_COL                          49
#define _OSD_SLIDE_VALUE_OFFSET                    10
#define _OSD_TIMER_NUMBER_1_COL                    8    



#endif

//#define _OSD_SLIDE_START_END_OFFSET                  30

#define _OSD_POSITION_1_1                                       0
#define _OSD_POSITION_1_2                                        1
#define _OSD_POSITION_1_3                                        2
#define _OSD_POSITION_2_1                                        3
#define _OSD_POSITION_2_2                                        4
#define _OSD_POSITION_2_3                                        5
#define _OSD_POSITION_3_1                                        6
#define _OSD_POSITION_3_2                                        7
#define _OSD_POSITION_3_3                                        8


#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
#define _OSD_POSITION_1_COUNT                                       (2+1)
#else
#define _OSD_POSITION_1_COUNT                                       2
#endif

#define _OSD_POSITION_2_COUNT                                       6
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
#define _OSD_POSITION_3_COUNT                                       (5+1)
#else
#define _OSD_POSITION_3_COUNT                                       5
#endif
 #if((_USE_TIME_SUPPORT == _ON)&&(_OD_FUNCTION == _ON))
#define _OSD_POSITION_4_COUNT                                     4
 #elif(_OD_FUNCTION == _ON)
#define _OSD_POSITION_4_COUNT                                     3
 #elif(_USE_TIME_SUPPORT == _ON)
#define _OSD_POSITION_4_COUNT                                     3
 #else
#define _OSD_POSITION_4_COUNT                                     2
#endif

#define _OSD_POSITION_5_COUNT                                      5
#define _OSD_POSITION_6_COUNT                                       3
#define _OSD_POSITION_7_COUNT                                       8
#define _OSD_POSITION_TEMP_USER_COUNT                     3


#define _OSD_NUMBER_STLECT_COLOR                      COLOR(_CP_ORANGE_H, _CP_BG)
#define _OSD_NUMBER_UNSTLECT_COLOR                  COLOR(_CP_LIGHTBLUE, _CP_BG)
#define _OSD_NUMBER_GRAY_COLOR                  COLOR(_CP_GRAY, _CP_BG)

//--------------------------------------------------
// Definitions of OSD
//--------------------------------------------------
#define _PFONT_PAGE_0                               0
#define _PFONT_PAGE_1                               1
#define _PFONT_PAGE_2                               2
#define _PFONT_PAGE_3                               3
#define _PFONT_PAGE_4                               4
#define _PFONT_PAGE_5                               5
#define _PFONT_PAGE_6                               6
#define _PFONT_PAGE_7                               7
#define _PFONT_PAGE_8                               8


#define _PFONT_PAGE_ITEM_1                          3
#define _PFONT_PAGE_ITEM_2                          4
#define _PFONT_PAGE_ITEM_3                          5
#define _PFONT_PAGE_ITEM_4                          6
#define _PFONT_PAGE_ITEM_5                          7
#define _PFONT_PAGE_ITEM_6                          8
#define _PFONT_PAGE_ITEM_7                          9
#define _PFONT_PAGE_ITEM_8                          10

#define _OSD_GLOBAL_START                           0x01
#define _OSD_GLOBAL_END                             0x0F

#define _OSD_PAGE_0_START                           0x04
#define _OSD_PAGE_0_END                              0x3e

#define _OSD_PAGE_1_START                           0x3f
#define _OSD_PAGE_1_END                             0x9c //0xc0  //0x5F    

#define _OSD_PAGE_2_START                         0x9d       //0xC1    
#define _OSD_PAGE_2_END                            0xEb  //0xF0



#define _SUB_PAGE_ITEM_1                               (_OSD_PAGE_2_END+1) // (_OSD_PAGE_2_START)
#define _SUB_PAGE_ITEM_1_END                        (_OSD_PAGE_2_END+5) // (_OSD_PAGE_2_START + 6)
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 5)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 10)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 10)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 8)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 8)
#define _SUB_PAGE_ITEM_7                            (_SUB_PAGE_ITEM_6_END)
#define _SUB_PAGE_ITEM_7_END                        (_SUB_PAGE_ITEM_6_END + 6)
#define _SUB_PAGE_ITEM_8                            (_SUB_PAGE_ITEM_7_END) 
#define _SUB_PAGE_ITEM_8_END                        (_SUB_PAGE_ITEM_7_END + 10)


#define _NORMAL                                     0
#define _CENTER                                     1
#define _START                                      0
#define _RUN                                        1

#define _UP                                         0
#define _DOWN                                       1

#define _OUTSUBSET                                  0
#define _INSUBSET                                   1

//--------------------------------------------------
// Definitions of OSD Window
//--------------------------------------------------
//=========== OSD Window Setting ======================//
//Blending type1:Only windows blending.
//Blending type2:All blending.
//Blending type3:Windows & Character background blending.
#define _WIN0                                       0
#define _WIN1                                       1
#define _WIN2                                       2
#define _WIN3                                       3
#define _WIN4                                       4
#define _WIN5                                       5
#define _WIN6                                       6
#define _WIN7                                       7
#define _WIN8                                       8 //Eli 20110622 add
#define _WIN9                                       9 //Eli 20110622 add
#define _WIN_ALL                                    0xFF

#define _WIN0_TRANS                                 (_BIT7 | 0)
#define _WIN1_TRANS                                 (_BIT7 | 1)
#define _WIN2_TRANS                                 (_BIT7 | 2)
#define _WIN3_TRANS                                 (_BIT7 | 3)
#define _WIN4_TRANS                                 (_BIT7 | 4)
#define _WIN5_TRANS                                 (_BIT7 | 5)
#define _WIN6_TRANS                                 (_BIT7 | 6)
#define _WIN7_TRANS                                 (_BIT7 | 7)

#define COLOR(fg,bg)                                (fg << 4 | bg)
#define COLOR0(x)                                   (x)
#define COLOR1(x)                                   (x)
#define COLOR2(x)                                   (x)
#define COLOR3(x)                                   (x)

#define X_START(x)                                  (x)
#define Y_START(x)                                  (x)
#define X_END(x)                                    (x)
#define Y_END(x)                                    (x)

#define _BORDER0_1_PIXEL                            0
#define _BORDER0_2_PIXEL                            1
#define _BORDER0_3_PIXEL                            2
#define _BORDER0_4_PIXEL                            3
#define _BORDER0_5_PIXEL                            4
#define _BORDER0_6_PIXEL                            5
#define _BORDER0_7_PIXEL                            6
#define _BORDER0_8_PIXEL                            7

#define _BORDER1_1_PIXEL                            0x00
#define _BORDER1_2_PIXEL                            0x08
#define _BORDER1_3_PIXEL                            0x10
#define _BORDER1_4_PIXEL                            0x18
#define _BORDER1_5_PIXEL                            0x20
#define _BORDER1_6_PIXEL                            0x28
#define _BORDER1_7_PIXEL                            0x30
#define _BORDER1_8_PIXEL                            0x38

#define _BLEND_DISABLE                              0
#define _BLEND_ENABLE                               0x80
#define _GRADIENT_DISABLE                           0
#define _GRADIENT_ENABLE                            0x40
#define _GRADIENT_DIRECTION_H                       0
#define _GRADIENT_DIRECTION_V                       0x20
#define _BORDER_DISABLE                             0
#define _BORDER_ENABLE                              0x10

#define _1_LEVEL_RER_GRADIENT                       0x20
#define _2_LEVEL_RER_GRADIENT                       0x40
#define _3_LEVEL_RER_GRADIENT                       0x60
#define _4_LEVEL_RER_GRADIENT                       0x80
#define _5_LEVEL_RER_GRADIENT                       0xA0
#define _6_LEVEL_RER_GRADIENT                       0xC0
#define _7_LEVEL_RER_GRADIENT                       0xE0
#define _8_LEVEL_RER_GRADIENT                       0x00

#define _R_GRADIENT_DEC                             0x00
#define _R_GRADIENT_INC                             0x80
#define _G_GRADIENT_DEC                             0x00
#define _G_GRADIENT_INC                             0x40
#define _B_GRADIENT_DEC                             0x00
#define _B_GRADIENT_INC                             0x20

#define _GRADIENT_LEVEL_1                           0
#define _GRADIENT_LEVEL_2                           0x08
#define _GRADIENT_LEVEL_3                           0x10
#define _GRADIENT_LEVEL_4                           0x18

#define _R_GRADIENT_ENABLE                          0x04
#define _R_GRADIENT_DISABLE                         0x00
#define _G_GRADIENT_ENABLE                          0x02
#define _G_GRADIENT_DISABLE                         0x00
#define _B_GRADIENT_ENABLE                          0x01
#define _B_GRADIENT_DISABLE                         0x00

#define _SHADOW_1                                   0x00
#define _SHADOW_2                                   0x02
#define _SHADOW_3                                   0x04
#define _SHADOW_4                                   0x06
#define _3D_BUTTON_1                                0x08
#define _3D_BUTTON_2                                0x0A

#define _WIN0_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)

#define _WIN0_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _GRADIENT_DIRECTION_H | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN0_GRADIENT_CONTROL0                     (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_3 | _R_GRADIENT_INC | _G_GRADIENT_INC | _B_GRADIENT_INC)
#define _WIN0_GRADIENT_CONTROL1                     (_3_LEVEL_RER_GRADIENT)

#define _WIN0_ROTATE_BORDER_PIXEL                   (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN0_ROTATE_BORDER_COLOR                   ((_CP_DARKBLUE << 4)  |_CP_DARKBLUE)
#define _WIN0_ROTATE_FUNC_CONTROL                   (_BLEND_ENABLE | _GRADIENT_ENABLE | _GRADIENT_DIRECTION_V | _BORDER_ENABLE | _SHADOW_3)
#define _WIN0_ROTATE_GRADIENT_CONTROL0              (_R_GRADIENT_DISABLE | _G_GRADIENT_DISABLE | _B_GRADIENT_ENABLE | _GRADIENT_LEVEL_4 | _R_GRADIENT_DEC | _G_GRADIENT_DEC | _B_GRADIENT_DEC)
#define _WIN0_ROTATE_GRADIENT_CONTROL1              (_3_LEVEL_RER_GRADIENT)

#define _WIN1_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN1_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)

#define _WIN1_FUNC_CONTROL                          (_BLEND_ENABLE | _GRADIENT_DISABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN1_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN1_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN2_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN2_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN2_FUNC_CONTROL                          (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN2_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN2_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN3_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN3_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN3_FUNC_CONTROL                          (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN3_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN3_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN7_BORDER_PIXEL                          (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN7_BORDER_COLOR                          ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN7_FUNC_CONTROL                          (_BLEND_ENABLE)
#define _WIN7_GRADIENT_CONTROL0                     (_DISABLE)
#define _WIN7_GRADIENT_CONTROL1                     (_DISABLE)

#define _WIN0_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN0_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN0_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN0_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN0_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN1_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN1_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN1_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN1_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN1_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN2_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN2_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN2_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN2_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN2_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN3_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN3_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN3_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN3_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN3_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN4_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN4_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN4_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN4_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN4_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN5_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN5_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN5_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN5_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN5_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN6_TRANS_BORDER_PIXEL                    (_BORDER0_2_PIXEL | _BORDER1_2_PIXEL)
#define _WIN6_TRANS_BORDER_COLOR                    ((_CP_WHITE << 4) | _CP_WHITE)
#define _WIN6_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE | _BORDER_ENABLE | _3D_BUTTON_1)
#define _WIN6_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN6_TRANS_GRADIENT_CONTROL1               (_DISABLE)

#define _WIN7_TRANS_BORDER_PIXEL                    (_BORDER0_3_PIXEL | _BORDER1_3_PIXEL)
#define _WIN7_TRANS_BORDER_COLOR                    (_CP_YELLOW << 4)
#define _WIN7_TRANS_FUNC_CONTROL                    (_BLEND_ENABLE)
#define _WIN7_TRANS_GRADIENT_CONTROL0               (_DISABLE)
#define _WIN7_TRANS_GRADIENT_CONTROL1               (_DISABLE)



#define _OSD_UNSELECT                           0
#define _OSD_SELECT                             1
#define _OSD_REJECT                             2
#define _OSD_ADJUST                             3
#define _OSD_UNHIGHLIGHT                        4
#define _OSD_HIGHLIGHT                          5
#define _OSD_PRE_SELECT                         6
#define _OSD_SELECT_ADJUST                      7


#define _KEY_INFO_ENTER                         0
#define _KEY_INFO_RIGHT                         1
#define _KEY_INFO_LEFT                          2
#define _KEY_INFO_EXIT                          3
#define _KEY_INFO_BACK                          4
#define _KEY_INFO_ALL                           5   // exit, left, right, enter

//=========== OSD Font Icon Address ======================//
#define _1GLOBAL_START                          0x00                        // Global 49
#define _1DYNAMIC_START                         _1GLOBAL_START + 30          // Dynamic 0
#define _1DYNAMIC_ICON_START                    _1DYNAMIC_START + 0x08         // main menu icon (6 x 4 x 8) = 196
#define _2DYNAMIC_START                         0x00
#define _2BIT_ICON_OFFSET                     0x23 // 0x7F
#define _2BIT_ICON_START_ADDRESS               0x23   //  0x7F
#define _2BIT_ICON_START                            0x00
#define _LEFT_MENU_TIME_ICON_START           (_1DYNAMIC_START + 0x19)
#define _LEFT_MENU_AIM_ICON_START           (_1DYNAMIC_START + 0x43)
#define _LEFT_MENU_NUMBER_ICON_START           (_1DYNAMIC_START + 0x91)

#define _LOGO_START_ADDRESS                     0x00



//=============== 1Bit Icon ========================
#define _LEFT_CORNER_0								(_1DYNAMIC_START + 0x01)
#define _WHITE_EDGE_0								(_1DYNAMIC_START + 0x02)
#define _WHITE_EDGE_1								(_1DYNAMIC_START + 0x06)
#define _WHITE_EDGE_2								(_1DYNAMIC_START + 0x0F)
#define _EDGE_LINE									(_1DYNAMIC_START + 0x10)
#define _CHOOSE_ICON								(_1DYNAMIC_START + 0x16)
#define _BACKGROUND_ICON							(_1DYNAMIC_START + 0x18)




#define _RIGHT_CORNER_0							(_1DYNAMIC_START + 0x03)
#define _RIGHT_CORNER_1							(_1DYNAMIC_START + 0x04)
#define _LEFT_CORNER_1							(_1DYNAMIC_START + 0x05)

#define _ICON_CORNER_LINE							(_1DYNAMIC_START + 0x07)


//=========== OSD Font Print Form ======================//
#define _ARC_WINDOW_0							0
#define _QUADRANGLE_WINDOW_0					1
#define _GRID_WINDOW_0							2
//=========== OSD Font Icon Address ======================//


enum OneBitGLOBAL
{
    ___ = 0,
    _iREALTEK_00,
    _iREALTEK_01,
    _iREALTEK_02,
    _iREALTEK_03,
    _iREALTEK_04,
    _iREALTEK_05,
    _iREALTEK_06,
    _iREALTEK_07,
    _iREALTEK_08,
    _iREALTEK_09,
    _iREALTEK_0A,
    _iREALTEK_0B,
    _iREALTEK_10,
    _iREALTEK_11,
    _iREALTEK_12,
    _iREALTEK_13,
    _iREALTEK_14,
    _iREALTEK_15,
    _iREALTEK_16,
    _iREALTEK_17,
    _iREALTEK_18,
    _iREALTEK_19,
    _iREALTEK_1A,
    _iREALTEK_1B,
    _iLEFT_00,
    _iLEFT_01,
    _iRIGHT_00,
    _iRIGHT_01,
    _iKEY_BACK_00,
    _iKEY_BACK_01,
    _iKEY_BACK_10,
    _iKEY_BACK_11,
    _iKEY_LEFT_00,
    _iKEY_LEFT_01,
    _iKEY_LEFT_10,
    _iKEY_LEFT_11,
    _iKEY_RIGHT_00,
    _iKEY_RIGHT_01,
    _iKEY_RIGHT_10,
    _iKEY_RIGHT_11,
    _iKEY_ENTER_00,
    _iKEY_ENTER_01,
    _iKEY_ENTER_10,
    _iKEY_ENTER_11,
    _iKEY_EXIT_00,
    _iKEY_EXIT_01,
    _iKEY_EXIT_10,
    _iKEY_EXIT_11,
    _iINDICATE,


};

#if(_LOGO_TYPE==_RTD_LOGO) // sfy add  TongFang WD logo 20140819  //
//OSTAR LOGO
#define _LOGO_WINDOW_SIZE_X                         839
#define _LOGO_WINDOW_SIZE_Y                         179

#define _Logo_0x00                                  0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50_End                              (_Logo_0x00 + 0x50)

#define _Logo1_0x00                                 (_Logo_0x50_End + 0x00)
#define _Logo1_0x01                                 (_Logo1_0x00 + 0x01)
#define _Logo1_0x02                                 (_Logo1_0x00 + 0x02)
#define _Logo1_0x03                                 (_Logo1_0x00 + 0x03)
#define _Logo1_0x04                                 (_Logo1_0x00 + 0x04)
#define _Logo1_0x05                                 (_Logo1_0x00 + 0x05)
#define _Logo1_0x06                                 (_Logo1_0x00 + 0x06)
#define _Logo1_0x07                                 (_Logo1_0x00 + 0x07)
#define _Logo1_0x08                                 (_Logo1_0x00 + 0x08)
#define _Logo1_0x09                                 (_Logo1_0x00 + 0x09)
#define _Logo1_0x0a                                 (_Logo1_0x00 + 0x0a)
#define _Logo1_0x0b                                 (_Logo1_0x00 + 0x0b)
#define _Logo1_0x0c                                 (_Logo1_0x00 + 0x0c)
#define _Logo1_0x0d                                 (_Logo1_0x00 + 0x0d)
#define _Logo1_0x0e                                 (_Logo1_0x00 + 0x0e)
#define _Logo1_0x0f                                 (_Logo1_0x00 + 0x0f)
#define _Logo1_0x10                                 (_Logo1_0x00 + 0x10)
#define _Logo1_0x11                                 (_Logo1_0x00 + 0x11)
#define _Logo1_0x12                                 (_Logo1_0x00 + 0x12)
#define _Logo1_0x13                                 (_Logo1_0x00 + 0x13)
#define _Logo1_0x14                                 (_Logo1_0x00 + 0x14)
#define _Logo1_0x15                                 (_Logo1_0x00 + 0x15)
#define _Logo1_0x16                                 (_Logo1_0x00 + 0x16)
#define _Logo1_0x17                                 (_Logo1_0x00 + 0x17)
#define _Logo1_0x18                                 (_Logo1_0x00 + 0x18)
#define _Logo1_0x19                                 (_Logo1_0x00 + 0x19)
#define _Logo1_0x1a                                 (_Logo1_0x00 + 0x1a)
#define _Logo1_0x1b                                 (_Logo1_0x00 + 0x1b)
#define _Logo1_0x1c                                 (_Logo1_0x00 + 0x1c)
#define _Logo1_0x1d                                 (_Logo1_0x00 + 0x1d)
#define _Logo1_0x1e                                 (_Logo1_0x00 + 0x1e)
#define _Logo1_0x1f                                 (_Logo1_0x00 + 0x1f)
#define _Logo1_0x20                                 (_Logo1_0x00 + 0x20)
#define _Logo1_0x21                                 (_Logo1_0x00 + 0x21)
#define _Logo1_0x22                                 (_Logo1_0x00 + 0x22)
#define _Logo1_0x23                                 (_Logo1_0x00 + 0x23)
#define _Logo1_0x24                                 (_Logo1_0x00 + 0x24)
#define _Logo1_0x25                                 (_Logo1_0x00 + 0x25)
#define _Logo1_0x26                                 (_Logo1_0x00 + 0x26)
#define _Logo1_0x27                                 (_Logo1_0x00 + 0x27)
#define _Logo1_0x28                                 (_Logo1_0x00 + 0x28)
#define _Logo1_0x29                                 (_Logo1_0x00 + 0x29)
#define _Logo1_0x2a                                 (_Logo1_0x00 + 0x2a)
#define _Logo1_0x2b                                 (_Logo1_0x00 + 0x2b)
#define _Logo1_0x2c                                 (_Logo1_0x00 + 0x2c)
#define _Logo1_0x2d                                 (_Logo1_0x00 + 0x2d)
#define _Logo1_0x2e                                 (_Logo1_0x00 + 0x2e)
#define _Logo1_0x2f                                 (_Logo1_0x00 + 0x2f)
#define _Logo1_0x30                                 (_Logo1_0x00 + 0x30)
#define _Logo1_0x31                                 (_Logo1_0x00 + 0x31)
#define _Logo1_0x32                                 (_Logo1_0x00 + 0x32)
#define _Logo1_0x33                                 (_Logo1_0x00 + 0x33)
#define _Logo1_0x34                                 (_Logo1_0x00 + 0x34)
#define _Logo1_0x35                                 (_Logo1_0x00 + 0x35)
#define _Logo1_0x36                                 (_Logo1_0x00 + 0x36)
#define _Logo1_0x37                                 (_Logo1_0x00 + 0x37)
#define _Logo1_0x38                                 (_Logo1_0x00 + 0x38)
#define _Logo1_0x39                                 (_Logo1_0x00 + 0x39)
#define _Logo1_0x3a                                 (_Logo1_0x00 + 0x3a)
#define _Logo1_0x3b                                 (_Logo1_0x00 + 0x3b)
#define _Logo1_0x3c                                 (_Logo1_0x00 + 0x3c)
#define _Logo1_0x3d                                 (_Logo1_0x00 + 0x3d)
#define _Logo1_0x3e                                 (_Logo1_0x00 + 0x3e)
#define _Logo1_0x3f                                 (_Logo1_0x00 + 0x3f)
#define _Logo1_0x40                                 (_Logo1_0x00 + 0x40)
#define _Logo1_0x41                                 (_Logo1_0x00 + 0x41)
#define _Logo1_0x42                                 (_Logo1_0x00 + 0x42)
#define _Logo1_0x43                                 (_Logo1_0x00 + 0x43)
#define _Logo1_0x44                                 (_Logo1_0x00 + 0x44)
#define _Logo1_0x45                                 (_Logo1_0x00 + 0x45)
#define _Logo1_0x46                                 (_Logo1_0x00 + 0x46)

// sfy add  TongFang WD logo 20140819 start //
#elif(_LOGO_TYPE==_TONGFANG_WD_LOGO)
#define _LOGO_WINDOW_SIZE_X                         ((0x1e+1)*12-1)//
#define _LOGO_WINDOW_SIZE_Y                         ((0x13+1)*18-1)//

#define _BFONT                                 (0x16)  // black font
#define _WFONT                                 (0x06)  // write font

#define _Logo_0x00                                  0x00//reserved
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  _WFONT //(_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  _BFONT//(_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)






//=============== 2Bit Icon ========================
#define _HKC_MAIN_ICON0							(_2BIT_ICON_START + 0)

#define _HKC_MAIN_ICON1							(_2BIT_ICON_START + 1)
#define _HKC_MAIN_ICON2							(_2BIT_ICON_START + 2)
#define _HKC_MAIN_ICON3							(_2BIT_ICON_START + 3)
#define _HKC_MAIN_ICON4							(_2BIT_ICON_START + 4)
#define _HKC_MAIN_ICON5							(_2BIT_ICON_START + 5)
#define _HKC_MAIN_ICON6							(_2BIT_ICON_START + 6)
#define _HKC_MAIN_ICON7							(_2BIT_ICON_START + 7)
#define _HKC_MAIN_ICON8							(_2BIT_ICON_START + 8)

#define _HKC_MAIN_ICON9							(_2BIT_ICON_START + 9)
#define _HKC_MAIN_ICON10							(_2BIT_ICON_START + 10)
#define _HKC_MAIN_ICON11							(_2BIT_ICON_START + 11)
#define _HKC_MAIN_ICON12							(_2BIT_ICON_START + 12)
#define _HKC_MAIN_ICON13							(_2BIT_ICON_START + 13)
#define _HKC_MAIN_ICON14							(_2BIT_ICON_START + 14)
#define _HKC_MAIN_ICON15							(_2BIT_ICON_START + 15)
#define _HKC_MAIN_ICON16							(_2BIT_ICON_START + 16)

#define _HKC_MAIN_ICON17							(_2BIT_ICON_START + 17)
#define _HKC_MAIN_ICON18							(_2BIT_ICON_START + 18)
#define _HKC_MAIN_ICON19							(_2BIT_ICON_START + 19)
#define _HKC_MAIN_ICON20							(_2BIT_ICON_START + 20)
#define _HKC_MAIN_ICON21							(_2BIT_ICON_START + 21)
#define _HKC_MAIN_ICON22							(_2BIT_ICON_START + 22)
#define _HKC_MAIN_ICON23							(_2BIT_ICON_START + 23)
#define _HKC_MAIN_ICON24							(_2BIT_ICON_START + 24)

#define _HKC_MAIN_ICON25							(_2BIT_ICON_START + 25)
#define _HKC_MAIN_ICON26							(_2BIT_ICON_START + 26)
#define _HKC_MAIN_ICON27							(_2BIT_ICON_START + 27)
#define _HKC_MAIN_ICON28							(_2BIT_ICON_START + 28)
#define _HKC_MAIN_ICON29							(_2BIT_ICON_START + 29)
#define _HKC_MAIN_ICON30							(_2BIT_ICON_START + 30)
#define _HKC_MAIN_ICON31							(_2BIT_ICON_START + 31)
#define _HKC_MAIN_ICON32							(_2BIT_ICON_START + 32)

#define _HKC_MAIN_ICON33							(_2BIT_ICON_START + 33)
#define _HKC_MAIN_ICON34							(_2BIT_ICON_START + 34)
#define _HKC_MAIN_ICON35							(_2BIT_ICON_START + 35)
#define _HKC_MAIN_ICON36							(_2BIT_ICON_START + 36)
#define _HKC_MAIN_ICON37							(_2BIT_ICON_START + 37)
#define _HKC_MAIN_ICON38							(_2BIT_ICON_START + 38)
#define _HKC_MAIN_ICON39							(_2BIT_ICON_START + 39)
#define _HKC_MAIN_ICON40							(_2BIT_ICON_START + 40)

#define _HKC_MAIN_ICON41							(_2BIT_ICON_START + 41)
#define _HKC_MAIN_ICON42							(_2BIT_ICON_START + 42)
#define _HKC_MAIN_ICON43							(_2BIT_ICON_START + 43)
#define _HKC_MAIN_ICON44							(_2BIT_ICON_START + 44)
#define _HKC_MAIN_ICON45							(_2BIT_ICON_START + 45)
#define _HKC_MAIN_ICON46							(_2BIT_ICON_START + 46)
#define _HKC_MAIN_ICON47							(_2BIT_ICON_START + 47)
#define _HKC_MAIN_ICON48							(_2BIT_ICON_START + 48)

#define _HKC_MAIN_ICON_END					(_2BIT_ICON_START + 49)










#elif(_LOGO_TYPE==_TONGFANG_SEIKI_PRO_LOGO)

#define _LOGO_WINDOW_SIZE_X                         ((0x53+1)*12-1)// the power on x logo size
#define _LOGO_WINDOW_SIZE_Y                         ((0x0c+1)*18-1)// the power on y logo size

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x1d)  // white font


#define _Logo_0x00                                  (_BFONT) //reserved  balck
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c) 
#define _Logo_0x1d                                  (_WFONT) //(_Logo_0x00 + 0x1d) // white
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)
// sfy add  TongFang WD logo 20140819 end //

// Lee  add  sanc  logo 20141013 start //
#elif(_LOGO_TYPE==_SANC_LOGO)
#define _LOGO_WINDOW_SIZE_X                         ((60)*12-1)//
#define _LOGO_WINDOW_SIZE_Y                         ((10)*18-1)//

#define _BFONT                                 (0x04)  // black font
#define _WFONT                                 (0x00)  // write font

#define _Logo_0x00                                  _WFONT //0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)
// Lee  add  sanc  logo 20141013 end //

#elif(_LOGO_TYPE==_SHENGYANG_UPSTAR_LOGO)

#define _LOGO_WINDOW_SIZE_X                         ((46)*12-1)//
#define _LOGO_WINDOW_SIZE_Y                         ((12)*18-1)//

#define _BFONT                                 (0x5c)  // black font
#define _WFONT                                 (0x00)  // write font

#define _Logo_0x00                                  _WFONT //0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)

#elif(_LOGO_TYPE == _TONGFANG_ELEMENT_LOGO)
#define _LOGO_WINDOW_SIZE_X                         ((103+1)*12-1)//
#define _LOGO_WINDOW_SIZE_Y                         ((11+1)*18-1)//

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x27)  // write font

#define _Logo_0x00                                  (_BFONT) //0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_WFONT) //(_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)


#define _Logo1_0x00                               (_Logo_0xff + 0x00)


#elif(_LOGO_TYPE == _SANC_SECPTRE_LOGO)
#define _LOGO_WINDOW_SIZE_X                         ((171)*12-1)//
#define _LOGO_WINDOW_SIZE_Y                         ((14)*18-1)//

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x05)  // write font

#define _Logo_0x00                                  (_BFONT) //0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_WFONT) // (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)
// Lee  add  sanc  logo 20141013 end //

#elif(_LOGO_TYPE == _KOS_KOIOS_LOGO)
#define _LOGO_WINDOW_SIZE_X                         ((56)*12-1)//
#define _LOGO_WINDOW_SIZE_Y                         ((9)*18-1)//

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x10)  // write font

#define _Logo_0x00                                  (_BFONT) //0x00
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                   (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_WFONT)//(_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c)
#define _Logo_0x1d                                  (_Logo_0x00 + 0x1d)
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)
// Lee  add  sanc  logo 20141013 end //



#elif(_LOGO_TYPE==_VIEWPAKER_LOGO)

#define _LOGO_WINDOW_SIZE_X                         ((0x53+1)*12-1)// the power on x logo size
#define _LOGO_WINDOW_SIZE_Y                         ((0x0c+1)*18-1)// the power on y logo size

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x1d)  // white font


#define _Logo_0x00                                  (_BFONT) //reserved  balck
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c) 
#define _Logo_0x1d                                  (_WFONT) //(_Logo_0x00 + 0x1d) // white
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)
#elif(_LOGO_TYPE==_TIANXINGZHE_LOGO)

#define _LOGO_WINDOW_SIZE_X                         ((0x53+1)*12-1)// the power on x logo size
#define _LOGO_WINDOW_SIZE_Y                         ((0x0c+1)*18-1)// the power on y logo size

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x1d)  // white font


#define _Logo_0x00                                  (_BFONT) //reserved  balck
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c) 
#define _Logo_0x1d                                  (_WFONT) //(_Logo_0x00 + 0x1d) // white
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)

#elif(_LOGO_TYPE==_VIEWSONIC_LOGO)

#define _LOGO_WINDOW_SIZE_X                         ((0x53+1)*12-1)// the power on x logo size
#define _LOGO_WINDOW_SIZE_Y                         ((0x0c+1)*18-1)// the power on y logo size

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x1d)  // white font


#define _Logo_0x00                                  (_BFONT) //reserved  balck
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c) 
#define _Logo_0x1d                                  (_WFONT) //(_Logo_0x00 + 0x1d) // white
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)


#elif(_LOGO_TYPE==_KNIGHTEEN_LOGO)

#define _LOGO_WINDOW_SIZE_X                         ((0x53+1)*12-1)// the power on x logo size
#define _LOGO_WINDOW_SIZE_Y                         ((0x0c+1)*18-1)// the power on y logo size

#define _BFONT                                 (0x00)  // black font
#define _WFONT                                 (0x1d)  // white font


#define _Logo_0x00                                  (_BFONT) //reserved  balck
#define _Logo_0x01                                  (_Logo_0x00 + 0x01)
#define _Logo_0x02                                  (_Logo_0x00 + 0x02)
#define _Logo_0x03                                  (_Logo_0x00 + 0x03)
#define _Logo_0x04                                  (_Logo_0x00 + 0x04)
#define _Logo_0x05                                  (_Logo_0x00 + 0x05)
#define _Logo_0x06                                  (_Logo_0x00 + 0x06)
#define _Logo_0x07                                  (_Logo_0x00 + 0x07)
#define _Logo_0x08                                  (_Logo_0x00 + 0x08)
#define _Logo_0x09                                  (_Logo_0x00 + 0x09)
#define _Logo_0x0a                                  (_Logo_0x00 + 0x0a)
#define _Logo_0x0b                                  (_Logo_0x00 + 0x0b)
#define _Logo_0x0c                                  (_Logo_0x00 + 0x0c)
#define _Logo_0x0d                                  (_Logo_0x00 + 0x0d)
#define _Logo_0x0e                                  (_Logo_0x00 + 0x0e)
#define _Logo_0x0f                                  (_Logo_0x00 + 0x0f)
#define _Logo_0x10                                  (_Logo_0x00 + 0x10)
#define _Logo_0x11                                  (_Logo_0x00 + 0x11)
#define _Logo_0x12                                  (_Logo_0x00 + 0x12)
#define _Logo_0x13                                  (_Logo_0x00 + 0x13)
#define _Logo_0x14                                  (_Logo_0x00 + 0x14)
#define _Logo_0x15                                  (_Logo_0x00 + 0x15)
#define _Logo_0x16                                  (_Logo_0x00 + 0x16)
#define _Logo_0x17                                  (_Logo_0x00 + 0x17)
#define _Logo_0x18                                  (_Logo_0x00 + 0x18)
#define _Logo_0x19                                  (_Logo_0x00 + 0x19)
#define _Logo_0x1a                                  (_Logo_0x00 + 0x1a)
#define _Logo_0x1b                                  (_Logo_0x00 + 0x1b)
#define _Logo_0x1c                                  (_Logo_0x00 + 0x1c) 
#define _Logo_0x1d                                  (_WFONT) //(_Logo_0x00 + 0x1d) // white
#define _Logo_0x1e                                  (_Logo_0x00 + 0x1e)
#define _Logo_0x1f                                  (_Logo_0x00 + 0x1f)
#define _Logo_0x20                                  (_Logo_0x00 + 0x20)
#define _Logo_0x21                                  (_Logo_0x00 + 0x21)
#define _Logo_0x22                                  (_Logo_0x00 + 0x22)
#define _Logo_0x23                                  (_Logo_0x00 + 0x23)
#define _Logo_0x24                                  (_Logo_0x00 + 0x24)
#define _Logo_0x25                                  (_Logo_0x00 + 0x25)
#define _Logo_0x26                                  (_Logo_0x00 + 0x26)
#define _Logo_0x27                                  (_Logo_0x00 + 0x27)
#define _Logo_0x28                                  (_Logo_0x00 + 0x28)
#define _Logo_0x29                                  (_Logo_0x00 + 0x29)
#define _Logo_0x2a                                  (_Logo_0x00 + 0x2a)
#define _Logo_0x2b                                  (_Logo_0x00 + 0x2b)
#define _Logo_0x2c                                  (_Logo_0x00 + 0x2c)
#define _Logo_0x2d                                  (_Logo_0x00 + 0x2d)
#define _Logo_0x2e                                  (_Logo_0x00 + 0x2e)
#define _Logo_0x2f                                  (_Logo_0x00 + 0x2f)
#define _Logo_0x30                                  (_Logo_0x00 + 0x30)
#define _Logo_0x31                                  (_Logo_0x00 + 0x31)
#define _Logo_0x32                                  (_Logo_0x00 + 0x32)
#define _Logo_0x33                                  (_Logo_0x00 + 0x33)
#define _Logo_0x34                                  (_Logo_0x00 + 0x34)
#define _Logo_0x35                                  (_Logo_0x00 + 0x35)
#define _Logo_0x36                                  (_Logo_0x00 + 0x36)
#define _Logo_0x37                                  (_Logo_0x00 + 0x37)
#define _Logo_0x38                                  (_Logo_0x00 + 0x38)
#define _Logo_0x39                                  (_Logo_0x00 + 0x39)
#define _Logo_0x3a                                  (_Logo_0x00 + 0x3a)
#define _Logo_0x3b                                  (_Logo_0x00 + 0x3b)
#define _Logo_0x3c                                  (_Logo_0x00 + 0x3c)
#define _Logo_0x3d                                  (_Logo_0x00 + 0x3d)
#define _Logo_0x3e                                  (_Logo_0x00 + 0x3e)
#define _Logo_0x3f                                  (_Logo_0x00 + 0x3f)
#define _Logo_0x40                                  (_Logo_0x00 + 0x40)
#define _Logo_0x41                                  (_Logo_0x00 + 0x41)
#define _Logo_0x42                                  (_Logo_0x00 + 0x42)
#define _Logo_0x43                                  (_Logo_0x00 + 0x43)
#define _Logo_0x44                                  (_Logo_0x00 + 0x44)
#define _Logo_0x45                                  (_Logo_0x00 + 0x45)
#define _Logo_0x46                                  (_Logo_0x00 + 0x46)
#define _Logo_0x47                                  (_Logo_0x00 + 0x47)
#define _Logo_0x48                                  (_Logo_0x00 + 0x48)
#define _Logo_0x49                                  (_Logo_0x00 + 0x49)
#define _Logo_0x4a                                  (_Logo_0x00 + 0x4a)
#define _Logo_0x4b                                  (_Logo_0x00 + 0x4b)
#define _Logo_0x4c                                  (_Logo_0x00 + 0x4c)
#define _Logo_0x4d                                  (_Logo_0x00 + 0x4d)
#define _Logo_0x4e                                  (_Logo_0x00 + 0x4e)
#define _Logo_0x4f                                  (_Logo_0x00 + 0x4f)
#define _Logo_0x50                                  (_Logo_0x00 + 0x50)
#define _Logo_0x51                                  (_Logo_0x00 + 0x51)
#define _Logo_0x52                                  (_Logo_0x00 + 0x52)
#define _Logo_0x53                                  (_Logo_0x00 + 0x53)
#define _Logo_0x54                                  (_Logo_0x00 + 0x54)
#define _Logo_0x55                                  (_Logo_0x00 + 0x55)
#define _Logo_0x56                                  (_Logo_0x00 + 0x56)
#define _Logo_0x57                                  (_Logo_0x00 + 0x57)
#define _Logo_0x58                                  (_Logo_0x00 + 0x58)
#define _Logo_0x59                                  (_Logo_0x00 + 0x59)
#define _Logo_0x5a                                  (_Logo_0x00 + 0x5a)
#define _Logo_0x5b                                  (_Logo_0x00 + 0x5b)
#define _Logo_0x5c                                  (_Logo_0x00 + 0x5c)
#define _Logo_0x5d                                  (_Logo_0x00 + 0x5d)
#define _Logo_0x5e                                  (_Logo_0x00 + 0x5e)
#define _Logo_0x5f                                  (_Logo_0x00 + 0x5f)
#define _Logo_0x60                                  (_Logo_0x00 + 0x60)
#define _Logo_0x61                                  (_Logo_0x00 + 0x61)
#define _Logo_0x62                                  (_Logo_0x00 + 0x62)
#define _Logo_0x63                                  (_Logo_0x00 + 0x63)
#define _Logo_0x64                                  (_Logo_0x00 + 0x64)
#define _Logo_0x65                                  (_Logo_0x00 + 0x65)
#define _Logo_0x66                                  (_Logo_0x00 + 0x66)
#define _Logo_0x67                                  (_Logo_0x00 + 0x67)
#define _Logo_0x68                                  (_Logo_0x00 + 0x68)
#define _Logo_0x69                                  (_Logo_0x00 + 0x69)
#define _Logo_0x6a                                  (_Logo_0x00 + 0x6a)
#define _Logo_0x6b                                  (_Logo_0x00 + 0x6b)
#define _Logo_0x6c                                  (_Logo_0x00 + 0x6c)
#define _Logo_0x6d                                  (_Logo_0x00 + 0x6d)
#define _Logo_0x6e                                  (_Logo_0x00 + 0x6e)
#define _Logo_0x6f                                  (_Logo_0x00 + 0x6f)
#define _Logo_0x70                                  (_Logo_0x00 + 0x70)
#define _Logo_0x71                                  (_Logo_0x00 + 0x71)
#define _Logo_0x72                                  (_Logo_0x00 + 0x72)
#define _Logo_0x73                                  (_Logo_0x00 + 0x73)
#define _Logo_0x74                                  (_Logo_0x00 + 0x74)
#define _Logo_0x75                                  (_Logo_0x00 + 0x75)
#define _Logo_0x76                                  (_Logo_0x00 + 0x76)
#define _Logo_0x77                                  (_Logo_0x00 + 0x77)
#define _Logo_0x78                                  (_Logo_0x00 + 0x78)
#define _Logo_0x79                                  (_Logo_0x00 + 0x79)
#define _Logo_0x7a                                  (_Logo_0x00 + 0x7a)
#define _Logo_0x7b                                  (_Logo_0x00 + 0x7b)
#define _Logo_0x7c                                  (_Logo_0x00 + 0x7c)
#define _Logo_0x7d                                  (_Logo_0x00 + 0x7d)
#define _Logo_0x7e                                  (_Logo_0x00 + 0x7e)
#define _Logo_0x7f                                  (_Logo_0x00 + 0x7f)
#define _Logo_0x80                                  (_Logo_0x00 + 0x80)
#define _Logo_0x81                                  (_Logo_0x00 + 0x81)
#define _Logo_0x82                                  (_Logo_0x00 + 0x82)
#define _Logo_0x83                                  (_Logo_0x00 + 0x83)
#define _Logo_0x84                                  (_Logo_0x00 + 0x84)
#define _Logo_0x85                                  (_Logo_0x00 + 0x85)
#define _Logo_0x86                                  (_Logo_0x00 + 0x86)
#define _Logo_0x87                                  (_Logo_0x00 + 0x87)
#define _Logo_0x88                                  (_Logo_0x00 + 0x88)
#define _Logo_0x89                                  (_Logo_0x00 + 0x89)
#define _Logo_0x8a                                  (_Logo_0x00 + 0x8a)
#define _Logo_0x8b                                  (_Logo_0x00 + 0x8b)
#define _Logo_0x8c                                  (_Logo_0x00 + 0x8c)
#define _Logo_0x8d                                  (_Logo_0x00 + 0x8d)
#define _Logo_0x8e                                  (_Logo_0x00 + 0x8e)
#define _Logo_0x8f                                  (_Logo_0x00 + 0x8f)
#define _Logo_0x90                                  (_Logo_0x00 + 0x90)
#define _Logo_0x91                                  (_Logo_0x00 + 0x91)
#define _Logo_0x92                                  (_Logo_0x00 + 0x92)
#define _Logo_0x93                                  (_Logo_0x00 + 0x93)
#define _Logo_0x94                                  (_Logo_0x00 + 0x94)
#define _Logo_0x95                                  (_Logo_0x00 + 0x95)
#define _Logo_0x96                                  (_Logo_0x00 + 0x96)
#define _Logo_0x97                                  (_Logo_0x00 + 0x97)
#define _Logo_0x98                                  (_Logo_0x00 + 0x98)
#define _Logo_0x99                                  (_Logo_0x00 + 0x99)
#define _Logo_0x9a                                  (_Logo_0x00 + 0x9a)
#define _Logo_0x9b                                  (_Logo_0x00 + 0x9b)
#define _Logo_0x9c                                  (_Logo_0x00 + 0x9c)
#define _Logo_0x9d                                  (_Logo_0x00 + 0x9d)
#define _Logo_0x9e                                  (_Logo_0x00 + 0x9e)
#define _Logo_0x9f                                  (_Logo_0x00 + 0x9f)
#define _Logo_0xa0                                  (_Logo_0x00 + 0xa0)
#define _Logo_0xa1                                  (_Logo_0x00 + 0xa1)
#define _Logo_0xa2                                  (_Logo_0x00 + 0xa2)
#define _Logo_0xa3                                  (_Logo_0x00 + 0xa3)
#define _Logo_0xa4                                  (_Logo_0x00 + 0xa4)
#define _Logo_0xa5                                  (_Logo_0x00 + 0xa5)
#define _Logo_0xa6                                  (_Logo_0x00 + 0xa6)
#define _Logo_0xa7                                  (_Logo_0x00 + 0xa7)
#define _Logo_0xa8                                  (_Logo_0x00 + 0xa8)
#define _Logo_0xa9                                  (_Logo_0x00 + 0xa9)
#define _Logo_0xaa                                  (_Logo_0x00 + 0xaa)
#define _Logo_0xab                                  (_Logo_0x00 + 0xab)
#define _Logo_0xac                                  (_Logo_0x00 + 0xac)
#define _Logo_0xad                                  (_Logo_0x00 + 0xad)
#define _Logo_0xae                                  (_Logo_0x00 + 0xae)
#define _Logo_0xaf                                  (_Logo_0x00 + 0xaf)
#define _Logo_0xb0                                  (_Logo_0x00 + 0xb0)
#define _Logo_0xb1                                  (_Logo_0x00 + 0xb1)
#define _Logo_0xb2                                  (_Logo_0x00 + 0xb2)
#define _Logo_0xb3                                  (_Logo_0x00 + 0xb3)
#define _Logo_0xb4                                  (_Logo_0x00 + 0xb4)
#define _Logo_0xb5                                  (_Logo_0x00 + 0xb5)
#define _Logo_0xb6                                  (_Logo_0x00 + 0xb6)
#define _Logo_0xb7                                  (_Logo_0x00 + 0xb7)
#define _Logo_0xb8                                  (_Logo_0x00 + 0xb8)
#define _Logo_0xb9                                  (_Logo_0x00 + 0xb9)
#define _Logo_0xba                                  (_Logo_0x00 + 0xba)
#define _Logo_0xbb                                  (_Logo_0x00 + 0xbb)
#define _Logo_0xbc                                  (_Logo_0x00 + 0xbc)
#define _Logo_0xbd                                  (_Logo_0x00 + 0xbd)
#define _Logo_0xbe                                  (_Logo_0x00 + 0xbe)
#define _Logo_0xbf                                  (_Logo_0x00 + 0xbf)
#define _Logo_0xc0                                  (_Logo_0x00 + 0xc0)
#define _Logo_0xc1                                  (_Logo_0x00 + 0xc1)
#define _Logo_0xc2                                  (_Logo_0x00 + 0xc2)
#define _Logo_0xc3                                  (_Logo_0x00 + 0xc3)
#define _Logo_0xc4                                  (_Logo_0x00 + 0xc4)
#define _Logo_0xc5                                  (_Logo_0x00 + 0xc5)
#define _Logo_0xc6                                  (_Logo_0x00 + 0xc6)
#define _Logo_0xc7                                  (_Logo_0x00 + 0xc7)
#define _Logo_0xc8                                  (_Logo_0x00 + 0xc8)
#define _Logo_0xc9                                  (_Logo_0x00 + 0xc9)
#define _Logo_0xca                                  (_Logo_0x00 + 0xca)
#define _Logo_0xcb                                  (_Logo_0x00 + 0xcb)
#define _Logo_0xcc                                  (_Logo_0x00 + 0xcc)
#define _Logo_0xcd                                  (_Logo_0x00 + 0xcd)
#define _Logo_0xce                                  (_Logo_0x00 + 0xce)
#define _Logo_0xcf                                  (_Logo_0x00 + 0xcf)
#define _Logo_0xd0                                  (_Logo_0x00 + 0xd0)
#define _Logo_0xd1                                  (_Logo_0x00 + 0xd1)
#define _Logo_0xd2                                  (_Logo_0x00 + 0xd2)
#define _Logo_0xd3                                  (_Logo_0x00 + 0xd3)
#define _Logo_0xd4                                  (_Logo_0x00 + 0xd4)
#define _Logo_0xd5                                  (_Logo_0x00 + 0xd5)
#define _Logo_0xd6                                  (_Logo_0x00 + 0xd6)
#define _Logo_0xd7                                  (_Logo_0x00 + 0xd7)
#define _Logo_0xd8                                  (_Logo_0x00 + 0xd8)
#define _Logo_0xd9                                  (_Logo_0x00 + 0xd9)
#define _Logo_0xda                                  (_Logo_0x00 + 0xda)
#define _Logo_0xdb                                  (_Logo_0x00 + 0xdb)
#define _Logo_0xdc                                  (_Logo_0x00 + 0xdc)
#define _Logo_0xdd                                  (_Logo_0x00 + 0xdd)
#define _Logo_0xde                                  (_Logo_0x00 + 0xde)
#define _Logo_0xdf                                  (_Logo_0x00 + 0xdf)
#define _Logo_0xe0                                  (_Logo_0x00 + 0xe0)
#define _Logo_0xe1                                  (_Logo_0x00 + 0xe1)
#define _Logo_0xe2                                  (_Logo_0x00 + 0xe2)
#define _Logo_0xe3                                  (_Logo_0x00 + 0xe3)
#define _Logo_0xe4                                  (_Logo_0x00 + 0xe4)
#define _Logo_0xe5                                  (_Logo_0x00 + 0xe5)
#define _Logo_0xe6                                  (_Logo_0x00 + 0xe6)
#define _Logo_0xe7                                  (_Logo_0x00 + 0xe7)
#define _Logo_0xe8                                  (_Logo_0x00 + 0xe8)
#define _Logo_0xe9                                  (_Logo_0x00 + 0xe9)
#define _Logo_0xea                                  (_Logo_0x00 + 0xea)
#define _Logo_0xeb                                  (_Logo_0x00 + 0xeb)
#define _Logo_0xec                                  (_Logo_0x00 + 0xec)
#define _Logo_0xed                                  (_Logo_0x00 + 0xed)
#define _Logo_0xee                                  (_Logo_0x00 + 0xee)
#define _Logo_0xef                                  (_Logo_0x00 + 0xef)
#define _Logo_0xf0                                  (_Logo_0x00 + 0xf0)
#define _Logo_0xf1                                  (_Logo_0x00 + 0xf1)
#define _Logo_0xf2                                  (_Logo_0x00 + 0xf2)
#define _Logo_0xf3                                  (_Logo_0x00 + 0xf3)
#define _Logo_0xf4                                  (_Logo_0x00 + 0xf4)
#define _Logo_0xf5                                  (_Logo_0x00 + 0xf5)
#define _Logo_0xf6                                  (_Logo_0x00 + 0xf6)
#define _Logo_0xf7                                  (_Logo_0x00 + 0xf7)
#define _Logo_0xf8                                  (_Logo_0x00 + 0xf8)
#define _Logo_0xf9                                  (_Logo_0x00 + 0xf9)
#define _Logo_0xfa                                  (_Logo_0x00 + 0xfa)
#define _Logo_0xfb                                  (_Logo_0x00 + 0xfb)
#define _Logo_0xfc                                  (_Logo_0x00 + 0xfc)
#define _Logo_0xfd                                  (_Logo_0x00 + 0xfd)
#define _Logo_0xfe                                  (_Logo_0x00 + 0xfe)
#define _Logo_0xff                                  (_Logo_0x00 + 0xff)

#define _Logo1_0x00                                 (_Logo_0xff + 0x00)


#else


//#warning "No Logo!!!!!!!!!!!!!!!!"


#endif



//=============== 2Bit Icon ========================

#define _HKC_MAIN_ICON0							(_2BIT_ICON_START + 0)

#define _HKC_MAIN_ICON1							(_2BIT_ICON_START + 1)
#define _HKC_MAIN_ICON2							(_2BIT_ICON_START + 2)
#define _HKC_MAIN_ICON3							(_2BIT_ICON_START + 3)
#define _HKC_MAIN_ICON4							(_2BIT_ICON_START + 4)
#define _HKC_MAIN_ICON5							(_2BIT_ICON_START + 5)
#define _HKC_MAIN_ICON6							(_2BIT_ICON_START + 6)
#define _HKC_MAIN_ICON7							(_2BIT_ICON_START + 7)
#define _HKC_MAIN_ICON8							(_2BIT_ICON_START + 8)

#define _HKC_MAIN_ICON9							(_2BIT_ICON_START + 9)
#define _HKC_MAIN_ICON10							(_2BIT_ICON_START + 10)
#define _HKC_MAIN_ICON11							(_2BIT_ICON_START + 11)
#define _HKC_MAIN_ICON12							(_2BIT_ICON_START + 12)
#define _HKC_MAIN_ICON13							(_2BIT_ICON_START + 13)
#define _HKC_MAIN_ICON14							(_2BIT_ICON_START + 14)
#define _HKC_MAIN_ICON15							(_2BIT_ICON_START + 15)
#define _HKC_MAIN_ICON16							(_2BIT_ICON_START + 16)

#define _HKC_MAIN_ICON17							(_2BIT_ICON_START + 17)
#define _HKC_MAIN_ICON18							(_2BIT_ICON_START + 18)
#define _HKC_MAIN_ICON19							(_2BIT_ICON_START + 19)
#define _HKC_MAIN_ICON20							(_2BIT_ICON_START + 20)
#define _HKC_MAIN_ICON21							(_2BIT_ICON_START + 21)
#define _HKC_MAIN_ICON22							(_2BIT_ICON_START + 22)
#define _HKC_MAIN_ICON23							(_2BIT_ICON_START + 23)
#define _HKC_MAIN_ICON24							(_2BIT_ICON_START + 24)

#define _HKC_MAIN_ICON25							(_2BIT_ICON_START + 25)
#define _HKC_MAIN_ICON26							(_2BIT_ICON_START + 26)
#define _HKC_MAIN_ICON27							(_2BIT_ICON_START + 27)
#define _HKC_MAIN_ICON28							(_2BIT_ICON_START + 28)
#define _HKC_MAIN_ICON29							(_2BIT_ICON_START + 29)
#define _HKC_MAIN_ICON30							(_2BIT_ICON_START + 30)
#define _HKC_MAIN_ICON31							(_2BIT_ICON_START + 31)
#define _HKC_MAIN_ICON32							(_2BIT_ICON_START + 32)

#define _HKC_MAIN_ICON33							(_2BIT_ICON_START + 33)
#define _HKC_MAIN_ICON34							(_2BIT_ICON_START + 34)
#define _HKC_MAIN_ICON35							(_2BIT_ICON_START + 35)
#define _HKC_MAIN_ICON36							(_2BIT_ICON_START + 36)
#define _HKC_MAIN_ICON37							(_2BIT_ICON_START + 37)
#define _HKC_MAIN_ICON38							(_2BIT_ICON_START + 38)
#define _HKC_MAIN_ICON39							(_2BIT_ICON_START + 39)
#define _HKC_MAIN_ICON40							(_2BIT_ICON_START + 40)

#define _HKC_MAIN_ICON41							(_2BIT_ICON_START + 41)
#define _HKC_MAIN_ICON42							(_2BIT_ICON_START + 42)
#define _HKC_MAIN_ICON43							(_2BIT_ICON_START + 43)
#define _HKC_MAIN_ICON44							(_2BIT_ICON_START + 44)
#define _HKC_MAIN_ICON45							(_2BIT_ICON_START + 45)
#define _HKC_MAIN_ICON46							(_2BIT_ICON_START + 46)
#define _HKC_MAIN_ICON47							(_2BIT_ICON_START + 47)
#define _HKC_MAIN_ICON48							(_2BIT_ICON_START + 48)
#define _HKC_MAIN_ICON49							(_2BIT_ICON_START + 49)
#define _HKC_MAIN_ICON50							(_2BIT_ICON_START + 50)
#define _HKC_MAIN_ICON51							(_2BIT_ICON_START + 51)
#define _HKC_MAIN_ICON52							(_2BIT_ICON_START + 52)
#define _HKC_MAIN_ICON53							(_2BIT_ICON_START + 53)
#define _HKC_MAIN_ICON54							(_2BIT_ICON_START + 54)
#define _HKC_MAIN_ICON55							(_2BIT_ICON_START + 55)
#define _HKC_MAIN_ICON56							(_2BIT_ICON_START + 56)
#define _HKC_MAIN_ICON57							(_2BIT_ICON_START + 57)
#define _HKC_MAIN_ICON58							(_2BIT_ICON_START + 58)
#define _HKC_MAIN_ICON59							(_2BIT_ICON_START + 59)
#define _HKC_MAIN_ICON60							(_2BIT_ICON_START + 60)


#define _HKC_MAIN_ICON_END					(_2BIT_ICON_START + 61)

extern BYTE code tiOSD_MAIN_BIR_ICON[];
extern BYTE code tiOSD_MAIN_IMAGE_ICON[] ;
extern BYTE code tiOSD_MAIN_COLORTEMP_ICON[] ;
extern BYTE code tiOSD_MAIN_OSDSETTING_ICON[] ;
extern BYTE code tiOSD_MAIN_RESET_ICON[] ;
extern BYTE code tiOSD_MAIN_MISC_ICON[] ;



//---------------------------------------------------------------------
// Definitions of OSD Show Number Function Used by OsdDisplayShowNumber()
//---------------------------------------------------------------------
#define _ALIGN_LEFT                                 (0)
#define _ALIGN_RIGHT                                (1)

#define _FORCE_SHOW_NUMBER_OFF                      (0 << 1)
#define _FORCE_SHOW_NUMBER_ON                       (1 << 1)

#define _SHOW_1                                     (0 << 4)
#define _SHOW_2                                     (1 << 4)
#define _SHOW_3                                     (2 << 4)
#define _SHOW_4                                     (3 << 4)
#define _SHOW_5                                     (4 << 4)
#define _SHOW_6                                     (5 << 4)

//------------------------------------------------------
// Definitions of OSD Slider Function Used by OsdDisplaySlider()
//------------------------------------------------------
#define _SLIDER_RESOLUTION                          (10)

//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define _PALETTE_INDEX0                             0   // 0 ~ 15
#define _PALETTE_INDEX1                             1   // 16 ~ 31
#define _PALETTE_INDEX2                             2   // 32 ~ 47
#define _PALETTE_INDEX3                             3   // 48 ~ 63

// OSD Position
#define _POS_DIRECT                                 0
#define _POS_PERCENT                                1

//--------------------------------------------------
// Definations of OSD MAIN MENU
//--------------------------------------------------
#if( _OSTAR_OSD_SMALL ==  _ON)   
#define _OSD_MAIN_MENU_WIDTH                     ( 147-35)//147 //150//132// 88//small osd set
#else
#define _OSD_MAIN_MENU_WIDTH                      (74+2) //150//132// 88//small osd set
#define _OSD_RIGHT_KEY_WIDTH                      34 //150//132// 88//small osd set
#define _OSD_LEFT_KEY_WIDTH                      80 //150//132// 88//small osd set
#define _OSD_LEFT_KEY_AIM_WIDTH                      8 //150//132// 88//small osd set
#define _OSD_MENU_HOT_INPUT_WIDTH                    ( 3+(11* _OSD_INPUT_AMOUNT))//150//132// 88//small osd set
#define _OSD_LEFT_KEY_TIMER_WIDTH                      12 //150//132// 88//small osd set
#define _OSD_INPUT_PORT_INFORMATION_WIDTH                      24 //150//132// 88//small osd set
#endif
#define _OSD_MAIN_MENU_HEIGHT                       26
#define _OSD_RIGHT_KEY_HEIGHT                       10
#define _OSD_LEFT_KEY_HEIGHT                       24
#define _OSD_LEFT_KEY_AIM_HEIGHT                    4
#define _OSD_MENU_HOT_INPUT_HEIGHT                      5 //150//132// 88//small osd set
#define _OSD_LEFT_KEY_TIMER_HEIGHT                    5
#define _OSD_INPUT_PORT_INFORMATION_HEIGHT         8

#if(_USE_TIME_SUPPORT == _ON)
#define _OSD_TIME_SHOW_WIDTH                       12
#define _OSD_TIME_SHOW_HEIGHT                       2

#endif
//--------------------------------------------------
// Definations of OSD Type
//--------------------------------------------------

#define _OSD_MESSAGE_ROW_START                      2
#define _OSD_MESSAGE_CENTER_COL_START               12
#define _OSD_MESSAGE_CENTER_COL_END                 23

//--------------------------------------------------
// Definations of HL window Border Size
//--------------------------------------------------
#define _HL_WIN_BORDER_SIZE                         2

//--------------------------------------------------
// Definations of Slider
//--------------------------------------------------
#if( _OSTAR_OSD_SMALL ==  _ON)   
#define _SLIDER_LENGHT                            ( 195-(12*5))//  195    //small osd set
#else
#define _SLIDER_LENGHT                                      (150-2)    //small osd set
#endif
#define _SLIDER_HIGH                                16
#define _SLIDER_BORDER_PIXEL                        2
#define _SLIDER_OFFSET                              6

#define _SLIDER_SELECT_BORDER_COLOR                 _CP_WHITE  
#define _SLIDER_SELECT_BG_COLOR                     _CP_BLACK

#define _SLIDER_UNSELECT_BORDER_COLOR               _CP_WHITE
#define _SLIDER_UNSELECT_BG_COLOR                   _CP_BLACK

#define _SLIDER_SELECT_COLOR                        _CP_RED
#define _SLIDER_UNSELECT_COLOR                      _CP_WHITE   

#define _SLIDER_0                                   0
#define _SLIDER_1                                   1
#define _SLIDER_2                                   2
#define _SLIDER_3                                  3
#define _SLIDER_4                                  4
#define _SLIDER_5                                  5
#define _SLIDER_6                                  6
#define _SLIDER_7                                  7
#define _SLIDER_8                                  8
#define _SLIDER_9                                  9

#define _SELECT                                     1
#define _UNSELECT                                   0

#define _SLIDER_0_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_6 //_OSD_WINDOW_4_5
#define _SLIDER_0_BG_WINDOW                         _OSD_WINDOW_4_4 //_OSD_WINDOW_5 //_OSD_WINDOW_4_4
#define _SLIDER_0_BORDER_WINDOW                     _OSD_WINDOW_4_3 //_OSD_WINDOW_5//_OSD_WINDOW_4_3

#define _SLIDER_1_BAR_WINDOW                       _OSD_WINDOW_4_5// _OSD_WINDOW_4_8
#define _SLIDER_1_BG_WINDOW                        _OSD_WINDOW_4_4 //_OSD_WINDOW_4_7
#define _SLIDER_1_BORDER_WINDOW                    _OSD_WINDOW_4_3 //_OSD_WINDOW_4_6

#define _SLIDER_2_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_5_5
#define _SLIDER_2_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5_4
#define _SLIDER_2_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_5_3

#define _SLIDER_3_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_5_8
#define _SLIDER_3_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5_7
#define _SLIDER_3_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_5_6

#define _SLIDER_4_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_6
#define _SLIDER_4_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5
#define _SLIDER_4_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_4

#define _SLIDER_5_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_6
#define _SLIDER_5_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5
#define _SLIDER_5_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_4

#define _SLIDER_6_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_5_8
#define _SLIDER_6_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5_7
#define _SLIDER_6_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_5_6

#define _SLIDER_7_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_6
#define _SLIDER_7_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5
#define _SLIDER_7_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_4

#define _SLIDER_8_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_6
#define _SLIDER_8_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5
#define _SLIDER_8_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_4

#define _SLIDER_9_BAR_WINDOW                        _OSD_WINDOW_4_5//_OSD_WINDOW_6
#define _SLIDER_9_BG_WINDOW                         _OSD_WINDOW_4_4//_OSD_WINDOW_5
#define _SLIDER_9_BORDER_WINDOW                     _OSD_WINDOW_4_3//_OSD_WINDOW_4

#define _SLIDER_0_ROW                               16
#define _SLIDER_0_COL                               11

#define _ITEM_0                                     0
#define _ITEM_1                                     1
#define _ITEM_2                                     2
#define _ITEM_3                                     3
#define _ITEM_4                                     4
#define _ITEM_5                                     5
#define _ITEM_6                                     6
#define _ITEM_7                                     7

#define _NONE_ITEM                                  8

#define _FONTFROM_0_255                             0x00
#define _FONTFROM_256_512                           _BIT5


//--------------------------------------------------
// Definations of Color effect user mode Hue & Saturation
//--------------------------------------------------
#define _COLOR_HUE                                  0
#define _COLOR_SATURATION                           1


//--------------------------------------------------
// Define enter panel uniformity msg adjust from pcm or gamma
//--------------------------------------------------
enum FromWhichState
{
    _FROM_STATE_PCM,
    _FROM_STATE_GAMMA,
    _FROM_STATE_AMOUNT = _FROM_STATE_GAMMA,
};

//--------------------------------------------------
// Definitions of Clone Mode
//--------------------------------------------------
enum OSDCloneModeDef
{
    _OSD_CLONE_OFF = 0,
    _OSD_CLONE_ON,
};



//--------------------------------------------------
// Define Display Latency
//--------------------------------------------------
enum OSDDLatency
{
    _LATENCY_L = 0,
    _LATENCY_M,
    _LATENCY_H,
    _LATENCY_AMOUNT = _LATENCY_H,
};
//--------------------------------------------------
// Define PCM Soft Proft
//--------------------------------------------------
enum PCMSoftProftMode
{
    _PCM_SOFT_MODE_1,
    _PCM_SOFT_MODE_2,
    _PCM_SOFT_MODE_AMOUNT = _PCM_SOFT_MODE_2,
};


//--------------------------------------------------
// Define Gamma
//--------------------------------------------------
enum GammaType
{
    _GAMMA_OFF,
    _GAMMA_18,
    _GAMMA_20,
    _GAMMA_22,
    _GAMMA_24,    
    _GAMMA_AMOUNT = _GAMMA_24,
};

//--------------------------------------------------
// Define HL Window Type
//--------------------------------------------------
enum HLWinType
{
    _HL_WIN_OFF,
    _HL_WIN_1,
    _HL_WIN_2,
    _HL_WIN_3,
    _HL_WIN_4,
    _HL_WIN_5,
    _HL_WIN_AMOUNT = _HL_WIN_5,
};

enum ColorEffectType      
{
    _COLOREFFECT_STANDARD,
    _COLOREFFECT_MOVIE,
    _COLOREFFECT_PHOTO,
     _COLOREFFECT_GAME,
    _COLOREFFECT_FPS,
    _COLOREFFECT_RTS,   
     _COLOREFFECT_USER,    

    _COLOREFFECT_AMOUNT = _COLOREFFECT_USER,
};




//--------------------------------------------------
// Define Color Effect Six Color
//--------------------------------------------------
enum SixColorType      
{
    _SIXCOLOR_R,
    _SIXCOLOR_Y,
    _SIXCOLOR_G,
    _SIXCOLOR_C,
    _SIXCOLOR_B,
    _SIXCOLOR_M,
    _SIXCOLOR_AMOUNT = _SIXCOLOR_M,
};

//--------------------------------------------------
// Define Ultra Vivid
//--------------------------------------------------
enum UltraVividType
{
    _ULTRA_VIVID_OFF,
    _ULTRA_VIVID_L,
    _ULTRA_VIVID_M,
    _ULTRA_VIVID_H,
    _ULTRA_VIVID_AMOUNT = _ULTRA_VIVID_H,
};


//--------------------------------------------------
// Define Supported Aspect Ratios
//--------------------------------------------------
enum AspectRatioType
{
    _OSD_ASPECT_RATIO_FULL,
  //  _OSD_ASPECT_RATIO_16_BY_9,
    _OSD_ASPECT_RATIO_AUTO,
    _OSD_ASPECT_RATIO_4_BY_3,
    //_OSD_ASPECT_RATIO_5_BY_4,
   // _OSD_ASPECT_RATIO_ORIGIN,
    _OSD_ASPECT_RATIO_AMOUNT = _OSD_ASPECT_RATIO_4_BY_3,
};


//--------------------------------------------------
// Define Supported Aspect Ratios
//--------------------------------------------------
#if(_USE_TIME_SUPPORT == _ON)
enum OsdTimerType
{
    _OSD_ADVANCE_TIME_0,
    _OSD_ADVANCE_TIME_30,
    _OSD_ADVANCE_TIME_40,
    _OSD_ADVANCE_TIME_50,
    _OSD_ADVANCE_TIME_60,
    _OSD_ADVANCE_TIME_90,
    _OSD_ADVANCE_TIME_AMOUNT = _OSD_ADVANCE_TIME_90,
};

#endif
//--------------------------------------------------
// Define DP Port Version
//--------------------------------------------------
enum OSDDpPortVersionDef
{
    _DP_VER_1_DOT_1 = 0,
    _DP_VER_1_DOT_2,
    _DP_VER_AMOUNT = _DP_VER_1_DOT_2,
};

enum OSDDpMstTypeDef
{
    _MST_OFF = 0,
    _MST_D0,
    _MST_D1,
    _MST_D6,
    _MST_AMOUNT = _MST_D6,
};

//--------------------------------------------------
// Define Display Image Rotate
//--------------------------------------------------
enum OSDDispRotateDegree
{
    _DISP_ROTATE_0 = 0,
    _DISP_ROTATE_90,
    _DISP_ROTATE_180,
    _DISP_ROTATE_270,
    _DISP_ROTATE_AMOUNT = _DISP_ROTATE_270,
};

//--------------------------------------------------
// Define HotKey Option
//--------------------------------------------------
/*enum OSDHotKeyDef
{
    _HOTKEY_DDCCI = 0,
    _HOTKEY_DP_D0_OPTION,
    _HOTKEY_DP_D1_OPTION,
    _HOTKEY_AMOUNT = _HOTKEY_DP_D1_OPTION,
};

*/
//--------------------------------------------------
// Definitions of Input Port
//--------------------------------------------------
enum OSDInputPortDef
{
    _OSD_INPUT_AUTO = 0,
#if(_A0_PORT_SHIELD==_OFF)
#if(_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) 
     _OSD_INPUT_A0,
#endif 
#endif 
#if(_D0_PORT_SHIELD==_OFF)
   #if(_D0_INPUT_PORT_TYPE !=_D0_NO_PORT) 
       _OSD_INPUT_D0,  
   #endif 
#endif
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
    _OSD_INPUT_D1,
#endif 

#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
    _OSD_INPUT_D2,
#endif 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
    _OSD_INPUT_D3,
#endif 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
    _OSD_INPUT_D4,
#endif 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
    _OSD_INPUT_D5,
#endif 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
    _OSD_INPUT_D6,
#endif 
    _OSD_INPUT_AMOUNT ,
};


//--------------------------------------------------
// Definitions of Color Temperature
//--------------------------------------------------
enum ColortemptureDef
{
    _CT_6500,
    _CT_9300,
    _CT_USER,    
    _CT_COLORTEMP_AMOUNT = _CT_USER,    
    _CT_5800,
   _CT_SRGB,
  };


//--------------------------------------------------
// Definitions of 3D Effect
//--------------------------------------------------
enum OSDSelect3DEffectDef
{
    _3D_EFFECT_OFF = _OFF,
    _3D_EFFECT_WEAK,
    _3D_EFFECT_MEDIUM,
    _3D_EFFECT_STRONG,
    _3D_EFFECT_AMOUNT = _3D_EFFECT_STRONG,
};

//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
enum PCMType
{
#if(_OCC_SUPPORT == _ON)
    _PCM_OSD_SRGB,
    _PCM_OSD_ADOBE_RGB,
#endif

    _PCM_OSD_USER,
    _PCM_OSD_NATIVE,
#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
    _PCM_OSD_SOFT_PROFT,
    _PCM_OSD_AMOUNT = _PCM_OSD_SOFT_PROFT,
#else 
    _PCM_OSD_AMOUNT = _PCM_OSD_NATIVE,
#endif
};

//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
enum UniformityTypeSelect
{
    _UNIFORMITY_OSD_TYPE1 = 0,  // gamma 1.8     
    _UNIFORMITY_OSD_TYPE2,      // gamma 2.0
    _UNIFORMITY_OSD_TYPE3,      // gamma 2.2
    _UNIFORMITY_OSD_TYPE4,      // gamma 2.4
    _UNIFORMITY_OSD_TYPE5,      // srgb
    _UNIFORMITY_OSD_TYPE6,      // adobe rgb                          
};

typedef struct
{
    BYTE b1OsdLogo : 1;
    BYTE b1OsdWakeUpSwitchDdcciPort : 1;
    BYTE b1OsdWakeUpShowSource : 1;
    BYTE b1OsdFactoryModeStatus : 1;
    BYTE b1OsdDoAspectRatio : 1;
    BYTE b3OsdColorFormat : 3;
    BYTE b3OsdsixColor : 3;

    BYTE ucOsdStatePrevious;
    BYTE ucOsdState;
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;
    BYTE b3OsdsixColorHue;
    BYTE b3OsdsixColorSaturation;
    BYTE ucOsd3DEffectRealValue;

    BYTE ucOsdFREESYNCInforOsdAddress;
	
//#if(_DP_DRR_SUPPORT == _ON)
//    BYTE ucOsdDRRInforOsdAddress;
//#endif


}StructOsdInfo;


enum OSDFontDef
{
    _ = 0,
    _0_,_1_,_2_,_3_,_4_,_5_,_6_,_7_,_8_,_9_,
    _A_, _B_, _C_, _D_, _E_, _F_, _G_, _H_, _I_, _J_, _K_, _L_, _M_, _N_, _O_, _P_, _Q_, _R_, _S_, _T_, _U_, _V_, _W_, _X_, _Y_, _Z_,
    _a_, _b_, _c_, _d_, _e_, _f_, _g_, _h_, _i_, _j_, _k_, _l_, _m_, _n_, _o_, _p_, _q_, _r_, _s_, _t_, _u_, _v_, _w_, _x_, _y_, _z_,
    _A0_,_A1_, _A2_, _a2_, _a3_, _a4_,_c0_, _E0_, _e0_, _e1_, _e2_, _N0_, _U0_, _u1_, _u2_, _o0_, _o1_, _o2_, _O3_,_I0_,

    _DOWNDOT_,                //  '
    _DOT_,                  //  .
    _LEFT_BRACE_,           //  (
    _RIGHT_BRACE_,          //  )
    _AND_,                  //  /
    _COLON_,                //  :
    _AT_0_,                 //  @
    _COMMA_,                //  ,
    _SLINE_,                //  -
    _SHIFT_LEFT_,           //  <<
    _SHIFT_RIGHT_,          //  >>
    _SEPERATE_,             //;
    _QUERY_,                //  ?  
    _60_, _61_, _62_, _63_, _64_,_65_, _66_, _67_, _68_, _69_, _6a_, _6b_, _6c_, _6d_, _6e_, _6f_,
    _70_, _71_, _72_, _73_, _74_,_75_, _76_, _77_, _78_, _79_, _7a_, _7b_, _7c_, _7d_, _7e_,_7f_, _80_, _81_, _82_, _83_, _84_,
};

enum OSDColorPaletteDef
{
    _CP_EMPTY = 0,
    _CP_BG = 0,
    _CP_BLACK = 0,
    _CP_WHITE,
    _CP_BLUE_65,
    _CP_GREEN_119,
    _CP_GREEN_66,
    _CP_YELLOW,
    _CP_RED,
    _CP_ORANGE,
    _CP_LIGHTBLUE,
    _CP_SELECTBOTTOM,
    _CP_PINK,
    _CP_GRAY,
    _CP_GREEN_1,
    _CP_ORANGE_DARK,
    _CP_ORANGE_H,
    _CP_GRAY_1,
	_CP_GREEN_241,
	_CP_GREEN_39,
	_CP_BLUE_158,
	_CP_BLUE_120,
		

};

enum OSDColorPaletteLogo
{
    _LOGO_CP_BG = 0,
    _LOGO_CP_BLACK = 0,
    _LOGO_CP_WHITE,
    _LOGO_CP_RED,
    _LOGO_CP_GREEN,
    _LOGO_CP_BLUE,
    _LOGO_CP_YELLOW,
    _LOGO_CP_GRAY,
    _LOGO_CP_DARKBLUE,
    _LOGO_CP_LIGHTBLUE,
    _LOGO_CP_SELECTBOTTOM,
    _LOGO_CP_PINK,
    _LOGO_CP_RED_1,
    _LOGO_CP_GREEN_1,
    _LOGO_CP_ORANGE_L,
    _LOGO_CP_ORANGE_H,
    _LOGO_CP_GRAY_1,
};

typedef enum
{
    _MENU_NONE,

    _MENU_PICTURE,
    _MENU_COLOR,
    _MENU_OSDSETTINGS,
    _MENU_SETUP,
    _MENU_OTHER,



    _MENU_PICTURE_BRIGHTNESS,
    _MENU_PICTURE_CONTRAST,

     _MENU_PICTURE_ECO,
    _MENU_PICTURE_MAIN_SR,
    
    _MENU_COLOR_TEMPERATURE,
    _MENU_COLOR_TEMP_USER_R,
    _MENU_COLOR_TEMP_USER_G,
    _MENU_COLOR_TEMP_USER_B,

    _MENU_OSDSETTINGS_LANGUAGE,
    _MENU_OSDSETTINGS_OSD_HPOS,
    _MENU_OSDSETTINGS_OSD_VPOS,
    _MENU_OSDSETTINGS_TRNASPARENCY,
    _MENU_OSDSETTINGS_MENU_TIME,

    _MENU_SETUP_INPUT,
	_MENU_SETUP_AUDIOMUTE,
	_MENU_SETUP_AUDIO,
    _MENU_SETUP_RESET,


    _MENU_OTHERS_DISPLAY_SIZE,
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
    _MENU_OTHERS_LOW_BLUE_LIGHT,
#endif
#if(_OD_FUNCTION == _ON)
    _MENU_OTHERS_OD,
#endif
    _MENU_OTHERS_FREE_SYNC,



    _MENU_PICTURE_BRIGHTNESS_ADJUST,
    _MENU_PICTURE_CONTRAST_ADJUST,
    _MENU_PICTURE_ECO_ADJUST,
    _MENU_PICTURE_MAIN_SR_ADJUST,


    _MENU_COLOR_TEMPERATURE_ADJUST,
    _MENU_COLOR_TEMP_USER_ADJUST_R,
    _MENU_COLOR_TEMP_USER_ADJUST_G,
    _MENU_COLOR_TEMP_USER_ADJUST_B,


    _MENU_OSDSETTINGS_LANGUAGE_ADJUST,
    _MENU_OSDSETTINGS_OSD_HPOS_ADJUST,
    _MENU_OSDSETTINGS_OSD_VPOS_ADJUST,
    _MENU_OSDSETTINGS_TRNASPARENCY_ADJUST,
    _MENU_OSDSETTINGS_MENU_TIME_ADJUST,
	_Menu_Hotkey_ECO_Adjust,
	_Menu_LEFTKEY_GAME,
	_Menu_LEFTKEY_GAME_ADJUST,
	_Menu_LEFTKEY_TIMER,
	_Menu_LEFTKEY_TIMER_ADJUST,
	_OSD_DISPLEFT_TIMER_MENU,
	_OSD_DISPLEFT_TIMER_MENU_ADJUST,
	_OSD_DISPLEFT_TIMER_MENU_POSITION,


    _MENU_INPUT_ADJUST,
	_MENU_AUDIO_AUDIOMUTE_ON_OFF,
	_MENU_AUDIO_ADJUST,

/*
    _MENU_INPUT_AUTO,
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
     _MENU_INPUT_A0_PORT,
#endif 
#if((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
    _MENU_INPUT_D0_PORT,
#endif 
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
    _MENU_INPUT_D1_PORT,
#endif 
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
    _MENU_INPUT_D2_PORT,
#endif 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
     _MENU_INPUT_D3_PORT,
#endif 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
    _MENU_INPUT_D4_PORT,
#endif 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
    _MENU_INPUT_D5_PORT,
#endif 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
    _MENU_INPUT_D6_PORT,
#endif 
*/

    _MENU_OTHERS_DISPLAY_SIZE_ADJUST,
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
    _MENU_OTHERS_LOW_BLUE_LIGHT_ADJUST,
#endif
#if(_OD_FUNCTION == _ON)
    _MENU_OTHERS_OD_ADJUST,
#endif
    _MENU_OTHERS_FREE_SYNC_ADJUST,
	_MENU_HOT_INPUT_ADJUST,
   _MENU_END,
    
};

typedef enum
{
    _ICON_SUB_SEL_NONE,
    _ICON_SUB_SEL_INPUT,
        
};

typedef enum
{
    _ICON_NONE = 0,
    
    // main
    _ICON_PICTURE,    
    _ICON_DISPLAY,
    _ICON_COLOR,    
    _ICON_ADVANCE,
    _ICON_INPUT,
    _ICON_AUDIO,
    _ICON_OTHER,

    // picture
    _ICON_BACKLIGHT,
    _ICON_VOLUME,
   _ICON_ASPECT_RATIO,



    _ICON_NO_SUPPORT0,
    _ICON_NO_SUPPORT1,
    _ICON_NO_SUPPORT2,
    _ICON_NO_SUPPORT3,
   // _ICON_NO_SUPPORT_TEXT_0,
   // _ICON_NO_SUPPORT_TEXT_1,
    _ICON_NO_CABLE0,
    _ICON_NO_CABLE1,
    _ICON_NO_CABLE2,
    _ICON_NO_CABLE3,
  //  _ICON_NO_CABLE_TEXT_0,
  //  _ICON_NO_CABLE_TEXT_1,
    
    _ICON_NO_SIGNAL0,
    _ICON_NO_SIGNAL1,
    _ICON_NO_SIGNAL2,
    _ICON_NO_SIGNAL3,
 //   _ICON_NO_SIGNAL_TEXT_0,
 //   _ICON_NO_SIGNAL_TEXT_1,

    _ICON_POWER_SAVING0,
    _ICON_POWER_SAVING1,
    _ICON_POWER_SAVING2,
    _ICON_POWER_SAVING3,
  //  _ICON_POWER_SAVING_TEXT_0,
  //  _ICON_POWER_SAVING_TEXT_1,
 //   _ICON_POWER_SAVING_TEXT_2,
     _ICON_AUTO_ADJUST0,
     _ICON_AUTO_ADJUST1,
     _ICON_AUTO_ADJUST2,
     _ICON_AUTO_ADJUST3,
   // _ICON_AUTO_ADJUST_TEXT_0,
   // _ICON_AUTO_ADJUST_TEXT_1,
   // _ICON_AUTO_ADJUST_TEXT_2,

     _ICON_AUTOCOLOR_ADJUST0,
     _ICON_AUTOCOLOR_ADJUST1,
     _ICON_AUTOCOLOR_ADJUST2,
     _ICON_AUTOCOLOR_ADJUST3,

 /*   
    _ICON_NO_SUPPORT_CHINA_TEXT_0,
    _ICON_NO_SUPPORT_CHINA_TEXT_1,
    
   _ICON_NO_CABLE_CHINA_TEXT_0,
    _ICON_NO_CABLE_CHINA_TEXT_1,
    _ICON_NO_CABLE_CHINA_TEXT_2,

   _ICON_NO_SIGNAL_CHINA_TEXT_0,
    _ICON_NO_SIGANL_CHINA_TEXT_1,

    _ICON_POWER_SAVING_CHINA_TEXT_0,
    _ICON_POWER_SAVING_CHINA_TEXT_1,

     _ICON_AUTO_ADJUST_CHINA_TEXT_0,
    _ICON_AUTO_ADJUST_CHINA_TEXT_1,

*/

#if(_USER_FUNCTION_FPS1_FPS2==_ON)
//Color Effect
    _ICON_COLOR_EFF_STD,
    _ICON_COLOR_EFF_GAME,
    _ICON_COLOR_EFF_MOVIE,
    _ICON_COLOR_EFF_PHOTO,
    _ICON_COLOR_EFF_VIVID,
    _ICON_COLOR_EFF_USER,
    _ICON_COLOR_EFF_HANWEN_STD,
    _ICON_COLOR_EFF_HANWEN_GAME,
    _ICON_COLOR_EFF_HANWEN_MOVIE,
    _ICON_COLOR_EFF_HANWEN_PHOTO,
#endif

    _OPTION_ICON_END,   
};


typedef enum
{
    _ICON_INPUT_AUTO= _OPTION_ICON_END ,    
    _ICON_INPUT_VGA ,
    _ICON_INPUT_DVI,
    _ICON_INPUT_HDMI,
    _ICON_INPUT_DP,
    _ICON_INPUT_MHL,
    _ICON_INPUT_NO_PORT,
     #if(_MIAOZHUN_FUNCTION== _ON)
    _ICON_MIAOZHUN1,
    _ICON_MIAOZHUN2,

 #endif


    _ICON_INPUT_END,  
    
};

typedef enum
{
    _ICON_A0_PORT = _ICON_INPUT_END,
    _ICON_D0_PORT,
    _ICON_D1_PORT,
    _ICON_D2_PORT,
    _ICON_D3_PORT,
    _ICON_D4_PORT,
    _ICON_D5_PORT,
    _ICON_D6_PORT,

    _ICON_PORT_END,
    
   	_ICON_BACKLIGH1,
    _ICON_CONTRAST,
    _ICON_QINGHUA,
    
    _ICON_H_ABOVELINE,
    _ICON_V_LEFTLINE,
    _ICON_H_UNDERLINE,
    _ICON_V_RIGHTLINE,
    _ICON_PORT_LINEEND,

	
    _ICON_TABLE_NUMBER1,
    _ICON_TABLE_NUMBER2,
    _ICON_TABLE_NUMBER3,
    _ICON_TABLE_NUMBER4,
    _ICON_TABLE_NUMBER5,
    _ICON_TABLE_NUMBER6,
    _ICON_TABLE_NUMBER7,
    _ICON_TABLE_NUMBER8,
    _ICON_TABLE_NUMBEREND,
    
};

typedef enum
{
    _INPUT_OSD_VGA ,    
    _INPUT_OSD_DVI ,
    _INPUT_OSD_HDMI,
    _INPUT_OSD_DP,
    _INPUT_OSD_END,
    
};


typedef enum
{
    _OPTION_NORMAL,
    _OPTION_OVERSCAN_ONOFF,
    _OPTION_OVERDRIVE_ONOFF,
    _OPTION_ENERGYSTART_ONOFF,
    _OPTION_DDCCI_ONOFF,
    _OPTION_ROTATE_ADJUST,
    _OPTION_MUTE_ONOFF,
    _OPTION_STAND_ALONG_ONOFF,
    _OPTION_PANEL_UNIFORMITY_ONOFF,
    _OPTION_AUDIO_SOURCE,

    _OPTION_ASPECT_RATIO_TYPE,
    _OPTION_ULTRA_VIVID_TYPE,
    _OPTION_GAMMA_TYPE,
    _OPTION_TEMPRATURE_TYPE,
    _OPTION_COLOR_EFFECT_TYPE,
    _OPTION_COLOR_DEMO_TYPE,
    _OPTION_COLOR_FORMAT_TYPE,
    _OPTION_COLOR_PCM_TYPE,
    _OPTION_COLOR_PCM_SOFT_PROFT_TYPE,
    _OPTION_TEMPRATURE_USER_ADJUST,
    _OPTION_COLOR_EFFC_USER_ADJUST,
    _OPTION_COLOR_EFFC_USER_RGBYCM,
    _OPTION_COLOR_RGBYCM_HUE_STA,

    _OPTION_INPUT_SOURCE_TYPE,
    _OPTION_DP_PORT_VERSION,    
    _OPTION_DP_MST_TYPE,    
    _OPTION_DISP_ROTATE_TYPE,    

    
};


typedef enum
{
    _FONT1_GLOBAL,
    _REALTEK_1BIT_LOGO0,
    _REALTEK_1BIT_LOGO1, 
 #if(_USE_TIME_SUPPORT == _ON)
 _OSDTIMER_ICON,
#endif 
	_FOUR_CORNER,
	_MAIN_MENU_2BIT_ICON,
	_LEFT_MENU_AIM_ICON,
	_LEFT_MENU_TIME_ICON,
	_LEFT_MENU_NUMBER_ICON,
};


typedef enum
{
    _PALETTE_RTD_LOGO,
    _PALETTE_MAIN_MENU,
};

/*enum OSDPictureECODef
{
	_PICTURE_STANDARD,	
	_PICTURE_MOVIE,
	_PICTURE_PHOTO,
	_PICTURE_GAME,
	_PICTURE_FPS,
	_PICTURE_RTS,
	_PICTURE_USER,

};*/

enum OSDPictureECODef
{
	_PICTURE_STANDARD,
	_PICTURE_GAME,
	_PICTURE_MOVIE,
	_PICTURE_PHOTO,
	_PICTURE_USER,
	_PICTURE_FPS,
	_PICTURE_RTS,

};

enum OSDPictureMainsr
{
	_PICTURE_MAINSR_OFF,
	_PICTURE_MAINSR_WEAK,
	_PICTURE_MAINSR_MEDIAN,
	_PICTURE_MAINSR_STRONG,
	_PICTURE_MAINSR_STRONGEST,

};

enum OSDLowBlueDef
{
	_LOWBLUE_OFF,
	_LOWBLUE_WEAK,
	_LOWBLUE_MEDIAN,
	_LOWBLUE_STRONG,
	_LOWBLUE_STRONGEST,

};



enum OSDColorTempDef
{
	_COLOR_6500K,
	_COLOR_9300K,
	_COLOR_USER_DEFINE,

};
/*enum OSDLanguageDef
{
    _ENGLISH = 0,
	_FRENCH,
	_GERMAN,
	_ESPANA,
	_ITALIANO,
	_NEDERLAND,
	_KOREAN,
    _CHINESE_T,
	_CHINESE_FANTI,
    _LANGUAGE_AMOUNT=_CHINESE_FANTI,
    _SPANISH,
    _CHINESE_S,
    _JAPAN,

};*/
enum OSDLanguageDef
{
    _ENGLISH,
	_ESPANA,	
	_FRENCH,
	_GERMAN,
	_ITALIANO,
	_KOREAN,
	_CHINESE_T,
	
};

enum OSDAimDef
{
   // _AIM_START = 0,
	_AIM_1,
	_AIM_2,
	_AIM_3,
	_AIM_4,
	_AIM_END=_AIM_4,

};
enum OSDTimerNumberDef
{
	_TIMER_START = 0,
	_TIMER_10,
	_TIMER_20,
	_TIMER_30,
	_TIMER_40,
	_TIMER_50,
	_TIMER_60,
	_TIMER_90,
	_TIMER_END=_TIMER_90,

};
enum OSDLeftMenuChooseDef
{
	_LEFT_MENU_START = 0,
	_LEFT_AIM,
	_TIMER_TIMER,
	_LEFT_MENU_END=_TIMER_TIMER,

};

enum OSDLeftTimerPositionDef
{
	_LEFT_TIMER_POSITION_START = 0,
	_LEFT_TIMER_POSITION_1,
	_LEFT_TIMER_POSITION_2,
	_LEFT_TIMER_POSITION_3,
	_LEFT_TIMER_POSITION_END=_LEFT_TIMER_POSITION_3,

};

enum OSDFontCountDef
{
	_Countstar=0,
    _LANGUAGE,
    _HORIZONTAL,
    _VERTICAL,
    _TRANSPARENCY,
    _OSDTIMEOUT,
    _FONT_AMOUNT,

};



enum OSDEvenMassage
{
    _OSDEVENT_NONE_MSG = 0,
    _OSDEVENT_SHOW_NOSIGNAL_MSG,
    _OSDEVENT_SHOW_NOCABLE_MSG,
    _OSDEVENT_SHOW_NOSUPPORT_MSG,
    _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG,
    _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG,    
    _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG,
   // _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG,    
    _OSDEVENT_DO_AUTO_CONFIG_MSG,
    _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG,
    _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG,
    _OSDEVENT_SAVE_NVRAM_BRICON_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG,
};

typedef enum
{
   _OSD_DISP_NOSIGNAL_MSG,
   _OSD_DISP_NOCABLE_MSG,
   _OSD_DISP_NOSUPPORT_MSG,
   _OSD_DISP_FAIL_SAFE_MODE_MSG,
   _OSD_DISP_AUTO_CONFIG_MSG,
   _OSD_DISP_INPUT_SIGNAL_MSG,
   _OSD_DISP_AUTO_COLOR_MSG,
   _OSD_DISP_SWITCH_DDCCI_PORT_MSG,
   _OSD_DISP_POWER_SAVING_MSG,
 //  _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG,
} EnumOSDDispMsg;

enum OSDMainMenuIcon
{
    _ICON_POS_UP_0,
    _ICON_POS_UP_1,
    _ICON_POS_UP_2,
    _ICON_POS_UP_3,
    _ICON_POS_DOWN_0,
    _ICON_POS_DOWN_1,
    _ICON_POS_DOWN_2,
    _ICON_POS_DOWN_3,        
};

enum OSDHotKeyIcon
{
     _ICON_HOTKEY_AUTO_POS,
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
     _ICON_HOTKEY_A0_POS,
#endif 
#if((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF)) 
     _ICON_HOTKEY_D0_POS,
#endif 
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
     _ICON_HOTKEY_D1_POS,
#endif 
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
     _ICON_HOTKEY_D2_POS,
#endif 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
     _ICON_HOTKEY_D3_POS,
#endif 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
     _ICON_HOTKEY_D4_POS,
#endif 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
     _ICON_HOTKEY_D5_POS,
#endif 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
     _ICON_HOTKEY_D6_POS,
#endif 
};

typedef enum
{

//
_ICON_CHOOSE,

//
    _STRING_PICTURE,        
    _STRING_DISPLAY,
    _STRING_COLOR,
    _STRING_ADVANCE,   
    _STRING_INPUT,
    _STRING_AUDIO,
    _STRING_OTHER,

    // picture
    _STRING_BACKLIGHT,
     _STRING_CONTRAST,
	_STRING_ECO,
	_STRING_MAINSR,
//ECO
	_STRING_PICTURE_STANDARD,	
	_STRING_PICTURE_MOVIE,
	_STRING_PICTURE_PHOTO,
	_STRING_PICTURE_GAME,
	_STRING_PICTURE_FPS,
	_STRING_PICTURE_RTS,
	_STRING_PICTURE_USER,

//GAME
	_STRING_GAME_MENU,
	_STRING_GAME_TIME,
	_STRING_GAME_CURSOR,
	_STRING_GAME_TIMER_POSITION,

//MainSR
	
	_STRING_PICTURE_OFF,
	_STRING_PICTURE_WEAK,	
	_STRING_PICTURE_MEDIAN,	
	_STRING_PICTURE_STRONG,
	_STRING_PICTURE_STRONGEST,
#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
    _STRING_BLACK_EQUALIZER,
#endif   
   //  _STRING_DCR,

    // display
    _STRING_AUTO_ADJUST,
    _STRING_HPOS,
    _STRING_VPOS,
    _STRING_CLOCK,
    _STRING_PHASE,
     _STRING_SHARPNESS,
    //_STRING_DISP_ROTATE,    

    // color
     _STRING_COLORTEMP,
	_STRING_COLOR_RED,
	_STRING_COLOR_GREEN,
	_STRING_COLOR_BLUE,
	
	_STRING_COLOR_6500K,
	_STRING_COLOR_9300K,
	_STRING_COLOR_USER_DEFINE,
//OSD Settings
	_CHOOSE_LANGUAGE,
	_STRING_OSDSET_LANGUAGE,
	_STRING_OSDSET_HORIZONTAL,
	_STRING_OSDSET_VERTICAL,
	_STRING_OSDSET_TRANSPARENCY,
	_STRING_OSDSET_OSDTIMEOUT,
//SETUP
	_STRING_SETUP_INPUT,
	_STRING_SETUP_AUDIOMUTE,
	_STRING_SETUP_AUDIO,
	_STRING_SETUP_RESET,
	_STRING_SETUP_DVI,
	_STRING_SETUP_HDMI,
	_STRING_SETUP_DP,
	_STRING_NO_VIDEO_INPUT,
	_STRING_STANDBY_MODE,
	_STRING_NO_SIGNAL_INPUT,
    _STRING_COLOR_EFFECT,
     //_STRING_COLOR_FORMAT,
     _STRING_GAMMA,
  //  _STRING_PCM,
    _STRING_HUE,
    _STRING_SATURATION,     
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
    _STRING_LOW_BLUE_LIGHT_ADJUST,
#endif
//Other
	_STRING_OTHER_DISPLAY_SIZE,
	_STRING_OTHER_LOW_BLUE,
	_STRING_OTHER_OVER_DRIVER,
	_STRING_OTHER_FREESYNC,
	_STRING_OTHER_FULLSCREEN,
	_STRING_OTHER_AUTO,
	_STRING_OTHER_4_3,
	_STRING_OTHER_ON,
	_STRING_OTHER_OFF,
	_STRING_OTHER_WEAK,
	_STRING_OTHER_MEDIAN,
	_STRING_OTHER_STRONG,
	_STRING_OTHER_STRONGEST,
//
	_STRING_LEFT_MENU_AIM,
	_STRING_LEFT_MENU_TIMER,
//
   _STRING_COLOR_TEMP_USER_R,
   _STRING_COLOR_TEMP_USER_G,
   _STRING_COLOR_TEMP_USER_B,

    // advance
    _STRING_DP_OPTION,
  //  _STRING_DP_MST,
    _STRING_DDCCI,
    _STRING_ULTRA_VIVID,
    _STRING_ASPECT_RATIO,
    _STRING_DP_EDID,
    _STRING_OD,
 #if(_USE_TIME_SUPPORT == _ON)   
    _STRING_USE_TIME,
#endif 
 //   _STRING_OVER_SCAN,
  //  _STRING_OVER_DRIVE,


//INPUT
    _STRING_AUTO_SELECT,
    _STRING_INPUT_SELECT,
   _STRING_INPUT_STRING_ALL,
// _STRING_A0_NO_PORT,
//     _STRING_D0_DP,
//    _STRING_D1_HDMI1,
//     _STRING_D2_HDMI2,
//     _STRING_D3_DVI,
 //    _STRING_D4_DVI,
 //    _STRING_D5_DVI,
  //   _STRING_D6_DVI,
	//_STRING_D4_DVI,
	//_STRING_D5_NO_PORT,

    // audio
    _STRING_VOLUME,
    _STRING_MUTE,
  //  _STRING_STAND_ALONG,
    _STRING_AUDIO_SOURCE,

    // other
     _STRING_LANGUAGE,
     _STRING_OSD_HPOS,
     _STRING_OSD_VPOS,
    _STRING_MENU_TIME,
    _STRING_TRANSPARENCY,
    _STRING_RESET,
    _STRING_INFORMATION,
    _STRING_FACTORY,

    
    //Show OSD Number
    _STRING_SHOW_NUMBER,

    // information
    _STRING_HDCP_MODE,    

    //Adjust message
   _STRING_NO_SUPPORT,
    _STRING_AUTO_COLOR,
 //   _STRING_GO_TO_POWER_SAVING_MODE,
    _STRING_NOW_RESOLUTION,

    _STRING_PASS,
    _STRING_FAIL,


       _STRING_ON,
       _STRING_OFF,

  // _STRING_ROTATE_TABLE1,
  
    _STRING_DP_EDID_TABLE1,

    _STRING_COLOR_TEMP_TABLE1, 
    _STRING_Color_Effect_TABLE1, 
   // _STRING_Color_Format_TABLE1, 
    _STRING_Gama_TABLE1, 
  //  _STRING_PCM_TABLE1, 
  
   _STRING_DP_OPTION_TABLE1,
  // _STRING_DP_MST_TABLE1,
   _STRING_UltraVivid_TABLE1,
   _STRING_Aspect_Ratio_TABLE1,
   //_STRING_Over_Drive_TABLE1,
   _STRING_Audio_Source_TABLE1,
    _STRING_Language_TABLE1,
 #if(_USE_TIME_SUPPORT == _ON)   
        _STRING_USE_TIME_TABLE1,
#endif 
   _STRING_OPTION_LEFT,
    _STRING_OPTION_RIGHT,

    _STRIN_END,   
};

typedef enum
{
    // input
    _STRING_A0_PORT = _STRIN_END,
    _STRING_D0_PORT,
    _STRING_D1_PORT,
    _STRING_D2_PORT,
    _STRING_D3_PORT,
    _STRING_D4_PORT,
    _STRING_D5_PORT,
    _STRING_D6_PORT,    
};

typedef enum
{
    _A0_PORT = 0,
    _D0_PORT,
    _D1_PORT,
    _D2_PORT,
    _D3_PORT,
    _D4_PORT,
    _D5_PORT,
    _D6_PORT,
};

enum OsdRotationDisplaySizeDef
{
    _OSD_ROTATE_DISPLAY_FULL = 0,    
    _OSD_ROTATE_DISPLAY_PIXEL_BY_PIXEL,
    _OSD_ROTATE_DISPLAY_KEEP_SRC_ASPECT_RATIO,
};

typedef enum
{
    _AUTO_CONFIG_DO = 0,
    _AUTO_CONFIG_RESULT,
};



//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
#ifndef __OSTAR_DDCCI__
extern bit g_bForcePowSavStatus;
#endif

#ifndef __OSTAR_OSD__
extern StructOsdInfo g_stOsdInfo;
extern WORD g_usAdjustValue;
extern WORD g_usBackupValue;
extern BYTE g_usItemNum;
extern BYTE g_ucLogoTimerCounter;
#if(_USE_TIME_SUPPORT == _ON)  
extern BYTE g_usTimeTabe ;
extern bit g_usTime_OSD_OnOff ;
extern WORD g_usTimeUse ;
#endif
 extern bit g_usTime_OSD_OnOff1 ;
 #if(_MIAOZHUN_FUNCTION== _ON)
extern BYTE g_MiaoZhun ;
extern bit g_MiaoZhun_OnOff ;

 #endif
 extern BYTE g_MiaoZhun1 ;
 extern bit g_MiaoZhun_OnOff1 ;
  
#endif

#ifndef __OSTAR_OSDFUNC__
extern WORD xdata g_usFontSelectStart;
extern WORD xdata g_usFontTableStart;
extern BYTE xdata g_ucOsdWidth;
extern BYTE xdata g_ucOsdHeight;
extern BYTE g_ucFontPointer0;
extern BYTE g_ucFontPointer1;
extern BYTE g_ucFontPointer2;
extern BYTE g_ucFontPointer3;
extern BYTE g_ucFontPointer4;
extern BYTE g_ucFontPointer5;
extern BYTE g_ucFontPointer6;
extern BYTE g_ucFontPointer7;
extern BYTE g_ucFontPointer8;


#endif
//----------------------------------------------------------------------------------------
// Extern Tables from OsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSDFONTVLC__
extern BYTE code tICON_REALTEK_1BIT_LOGO0[];
extern BYTE code tICON_REALTEK_1BIT_LOGO1[];
#endif

//----------------------------------------------------------------------------------------
// Extern Tables from OsdTable.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSDFONTTABLE__
/*extern BYTE code tOSD_iREALTEK[];
extern BYTE code tOSD_iKEY_BACK[];
extern BYTE code tOSD_iKEY_LEFT[];
extern BYTE code tOSD_iKEY_RIGHT[];
extern BYTE code tOSD_iKEY_ENTER[];
extern BYTE code tOSD_iKEY_EXIT[];
*/

 #if(_USE_TIME_SUPPORT== _ON)
extern  BYTE code tiOSDTimer_0[] ;

extern code BYTE *tiOSDTimer[] ;
#endif
#if(_LOGO_TYPE==_RTD_LOGO) // sfy add  TongFang WD logo 20140819 //
extern BYTE code tiOSD_REALTEK_1BIT_LOGO0[];
extern BYTE code tiOSD_REALTEK_1BIT_LOGO1[];
// sfy add  TongFang WD logo 20140819 start //
#elif(_LOGO_TYPE==_TONGFANG_WD_LOGO)
extern BYTE code tiOSD_TONGFANG_1BIT_LOGO0[];
extern BYTE code tiOSD_TONGFANG_1BIT_LOGO1[];
extern BYTE code tiOSD_TONGFANG_1BIT_LOGO2[];
#elif(_LOGO_TYPE==_TONGFANG_SEIKI_PRO_LOGO)
extern BYTE code tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO0[];
extern BYTE code tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO1[];
extern BYTE code tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO2[];
// sfy add  TongFang WD logo 20140819 end //
// Lee  add  sanc  logo 20141013 start //
#elif(_LOGO_TYPE==_SANC_LOGO)
extern BYTE code tiOSD_SANC_1BIT_LOGO0[];
extern BYTE code tiOSD_SANC_1BIT_LOGO1[];
extern BYTE code tiOSD_SANC_1BIT_LOGO2[];
extern BYTE code tiOSD_SANC_1BIT_LOGO3[];
// Lee  add  sanc  logo 20141013 end //
#elif(_LOGO_TYPE==_SHENGYANG_UPSTAR_LOGO)
extern BYTE code tiOSD_SHENGYANG_UPSTAR_1BIT_LOGO0[];
#elif(_LOGO_TYPE == _TONGFANG_ELEMENT_LOGO)
extern BYTE code tiOSD_TONGFANG_ELEMENT_1BIT_LOGO0[];
extern BYTE code tiOSD_TONGFANG_ELEMENT_1BIT_LOGO1[];
#elif(_LOGO_TYPE == _SANC_SECPTRE_LOGO)
extern BYTE code tiOSD_SANC_SECPTRE_1BIT_LOGO0[];
extern BYTE code tiOSD_SANC_SECPTRE_1BIT_LOGO1[];
extern BYTE code tiOSD_SANC_SECPTRE_1BIT_LOGO2[];
#elif(_LOGO_TYPE == _KOS_KOIOS_LOGO)
extern BYTE code tiOSD_KOS_KOIOS_1BIT_LOGO0[];
extern BYTE code tiOSD_KOS_KOIOS_1BIT_LOGO1[];
#elif(_LOGO_TYPE == _USE_PEO_LOGO)
extern BYTE code tOSD_PEO_LOGO[];
extern BYTE code tOSD_PEO_LOGO1[];

#elif(_LOGO_TYPE == _VIEWPAKER_LOGO)
extern BYTE code tiOSD_VIEWPAKER_LOGO0[];
#elif(_LOGO_TYPE == _TIANXINGZHE_LOGO)
extern BYTE code tiOSD_TIANXINGZHE_LOGO0[];
#elif(_LOGO_TYPE == _VIEWSONIC_LOGO)
extern BYTE code tiOSD_VIEWSONIC_LOGO0[];
#elif(_LOGO_TYPE == _KNIGHTEEN_LOGO)
extern BYTE code tiOSD_KNIGHTEEN_LOGO0[];
#endif
// sfy add  TongFang WD logo 20140819 end //

#endif

#ifndef __OSTAR_OSDFONTPROP__


//extern BYTE code tSTRING_DCR[];
extern  BYTE code tSTRING_SHIFT_LEFT[];
extern  BYTE code tSTRING_SHIFT_RIGHT[];
extern  BYTE code tSTRING_ON[];
extern  BYTE code tSTRING_OFF[];
extern  BYTE code  ONOFF_TABLE1[];
 #if(_USE_TIME_SUPPORT == _ON)  
extern  BYTE code * tUSE_TIME_TABLE[];
 #endif

//extern  BYTE code  *ROTATE_TABLE1[];
extern  BYTE code  *COLOR_TEMP_TABLE1[];
extern  BYTE code  *tSTRING_Color_Effect_TABLE1[];
//extern  BYTE code  *tSTRING_Color_Format_TABLE1[];
extern  BYTE code  *tSTRING_Gama_TABLE1[];
//extern  BYTE code  *tSTRING_PCM_TABLE1[] ;
extern BYTE code  *tSTRING_DP_Option_TABLE1[] ;
extern BYTE code  *tSTRING_DP_EDID[] ;
extern BYTE code  *tSTRING_OD[] ;
//extern BYTE code  *tSTRING_DP_MST_TABLE1[] ;
extern BYTE code  *tSTRING_Ultra_Vivid_TABLE1[] ;
extern BYTE code  *tSTRING_Aspect_Ratio_TABLE1[] ;
//extern BYTE code  *tSTRING_Over_Drive_TABLE1[] ;
extern BYTE code  *tSTRING_audio_source_TABLE1[] ;
//extern BYTE code  *tSTRING_Language_TABLE1[] ;

extern BYTE code tSTRING_BACKLIGHT[];
extern BYTE code tSTRING_CONTRAST[];
    // main menu
extern BYTE code tSTRING_PICTURE[];        
extern BYTE code tSTRING_DISPLAY[];
extern BYTE code tSTRING_COLOR[];
extern BYTE code tSTRING_ADVANCE[];   
extern BYTE code tSTRING_INPUT[];
extern BYTE code tSTRING_AUDIO[];
extern BYTE code tSTRING_OTHER[];
extern BYTE code tSTRING_INFORMATION[];
extern BYTE code tSTRING_FACTORY[];

// picture

//extern BYTE code tSTRING_BRIGHTNESS[];
extern BYTE code tSTRING_SHARPNESS[];

// display
extern BYTE code tSTRING_AUTO_ADJUST[];
extern BYTE code tSTRING_HPOS[];
extern BYTE code tSTRING_VPOS[];
extern BYTE code tSTRING_CLOCK[];
extern BYTE code tSTRING_PHASE[];
//extern BYTE code tSTRING_DISP_ROTATE[];

// color
//extern BYTE code tSTRING_PANEL_UNIFORMITY[];
extern BYTE code tSTRING_GAMMA[];
extern BYTE code tSTRING_COLOR_TEMP[];
extern BYTE code tSTRING_COLOR_EFFECT[];
//extern BYTE code tSTRING_DEMO[];
//extern BYTE code tSTRING_COLOR_FORMAT[];
//extern BYTE code tSTRING_PCM[];
extern BYTE code tSTRING_HUE[];
extern BYTE code tSTRING_SATURATION[];  
extern BYTE code tSTRING_COLOR_TEMP_USER_R[];
extern BYTE code tSTRING_COLOR_TEMP_USER_G[];
extern BYTE code tSTRING_COLOR_TEMP_USER_B[];

// advance
extern BYTE code tSTRING_ASPECT_RATIO[];
//extern BYTE code tSTRING_OVER_SCAN[];
//extern BYTE code tSTRING_OVER_DRIVE[];
//extern BYTE code tSTRING_ENERGY_STAR[];
extern BYTE code tSTRING_DDCCI[];
extern BYTE code tSTRING_ULTRA_VIVID[];
extern BYTE code tSTRING_DP_OPTION[];
//extern BYTE code tSTRING_DP_MST[];

// input
extern BYTE code tSTRING_AUTO_SELECT[];

// audio
extern BYTE code tSTRING_VOLUME[];
extern BYTE code tSTRING_MUTE[];
//extern BYTE code tSTRING_STAND_ALONG[];
extern BYTE code tSTRING_AUDIO_SOURCE[];
extern BYTE code tSTRING_SOUND_MODE[];

// other
extern BYTE code tSTRING_RESET[];
extern BYTE code tSTRING_MENU_TIME[];
extern BYTE code tSTRING_OSD_HPOS[];
extern BYTE code tSTRING_OSD_VPOS[];
extern BYTE code tSTRING_LANGUAGE[];
extern BYTE code tSTRING_TRANSPARENCY[];
//extern BYTE code tSTRING_ROTATE[];
//extern code BYTE *tSTRING_MENU_TABLE[];
/*
#if(_TONGFANG_HOTKEY_FACTORY_DDCCI_BURN_DP11_DP12_FUNCTION == _ON)
extern BYTE code tSTRING_HOTKEY_BURNIN[];
extern BYTE code tSTRING_HOTKEY_DP11[];
extern BYTE code tSTRING_HOTKEY_DP12[];
#endif
*/
#endif


#ifndef __OSTAR_OSDWINDOW__
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserDdcci.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_DDCCI__
extern void UserDdcciHandler(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from OSTARKey.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_KEY__
extern void OSTARKeyInitial(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from Osd.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSD__

#endif


//----------------------------------------------------------------------------------------
// Extern functions from OsdFunc.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSDFUNC__
extern void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void OsdFuncSetPosition(WORD usX, WORD usY);
extern void OsdFuncTransparency(BYTE ucTrans);
extern void OsdFuncBlending(BYTE ucType);




extern BYTE OsdFuncGetOsdFontPointer(BYTE ucPointerSelect);
extern BYTE OsdFuncSetOsdFontPointer(BYTE ucPointerSelect,BYTE ucPointer);
extern void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex);
extern void OsdFuncDisableOsd(void);
extern void OsdFuncEnableOsd(void);

//extern void OsdFuncChangeIconColor1Bit(BYTE ucRow, BYTE ucItem, BYTE ucWidth , BYTE ucHeight, BYTE ucColor);
//extern void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom);
extern void OsdFuncSet2BitIconOffset(BYTE ucOffset);
extern void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight);
extern void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth , BYTE ucHeight, BYTE ucColor);

#if(_SIX_COLOR_SUPPORT == _ON)
//extern void OsdFuncSixColorAdjust(void);
#endif

//extern void OsdFuncColorFormatAdjust(void);
//extern void OsdFuncColorPcmAdjust(void);
extern void OsdFuncSetOsdItemFlag(void);


#endif


//----------------------------------------------------------------------------------------
// Extern functions from OsdDisplay.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSDDISPLAY__
//extern void OsdDispMainMenukeyCursor(BYTE ucOsdPositionState,BYTE type);
extern void OsdDispMainMenukeySlideAndOption(BYTE ucOsdPositionState,BYTE OSDState,BYTE SlideNum,BYTE MenuExit, BYTE type);
extern void OsdPropPutOptionString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor, BYTE ucLanguage);
extern void COsdShowPageText(BYTE PageNo);
extern void COsdShowPageInputText(void);

extern void COsdShowChoosePictureText(BYTE number);
extern void COsdShowChooseColorText(BYTE number);
extern void COsdShowChooseOSDSetText(BYTE number);
extern void COsdShowChooseSetupText(BYTE number);
extern void COsdShowChooseOtherText(BYTE number);
extern void COsdShowChooseLeftMenuText(BYTE number);


extern BYTE OsdDispJudgeSourceType(void);

extern void OsdDispDisableOsd(void);
extern void OsdDispSetPosition(BYTE ucType, WORD usHPos, WORD usVPos);
extern void OsdDispSlider(BYTE ucRow, BYTE ucCol, BYTE ucLength, WORD usValue, WORD usMax, WORD usMin, BYTE ucColor);


extern void OsdDispMainMenu(void);
extern void OsdDispRightMenu(void);
extern void OsdDispLeftMenu(void);
extern void OsdDispLeftAimMenu(void);
extern void MenuHotInput(void);
extern void OsdDispLeftTimerMenu(void);
extern void OsdDispLeftTimerCountDown(void);
extern void OsdDispLeftTimerMenuAdjust(void);
extern void OsdDispLeftAimMenuAdjust(void);
extern void OsdDispSliderAndNumber(BYTE ucOsdState, WORD usValue);
extern WORD OsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);
//extern WORD OsdLanguageDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);

extern void OsdDispOsdReset(void);
//extern void OsdDispHotKeyOptionMenu(BYTE ucOption);
//extern void OsdDispHotKeySourceMenuIcon(void); 
//extern void OsdDispHotKeySourceMenu(void);   
//extern void OsdDispHotKeyAspectRatioMenu(void);   
/*
#if(_TONGFANG_HOTKEY_FACTORY_DDCCI_BURN_DP11_DP12_FUNCTION == _ON)
extern void OsdDispHotKeyDdcciMenu(void);   
extern void OsdDispHotKeyBurnMenu(void);  
extern void OsdDispHotLongKeyDP11Menu(void);  
extern void OsdDispHotLongKeyDP12Menu(void);  

#endif
*/
#if(_USER_FUNCTION_FPS1_FPS2==_ON)
extern void OsdDispHotKeyColorEffectMenu(void);
#endif


 #if(_MIAOZHUN_FUNCTION== _ON)
 extern void OsdDispMIAOZHUNMenu(void);
  extern void OsdDispMIAOZHUNShow(void);

#endif
 #if(_MIAOZHUN_FUNCTION== _ON)
 extern void RTDOsdDisplayOsdTimerProc(void);
#endif

extern void OsdDispHotKeyConTrastMenu(void); 

extern void OsdDispOsdMessage(EnumOSDDispMsg ucMessage);
#if(_VGA_SUPPORT == _ON)   
extern void OsdDispAutoConfigProc(void);
extern void OsdDisplayAutoBalanceProc(void);
#endif

extern void OsdDispShowLogo(void);
extern void OsdDispShowInformation(void);
extern void OsdDisplaySixColorGetOneColor(BYTE ucColor);

#endif

//----------------------------------------------------------------------------------------
// Extern functions from OsdFont.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSDFONTVLC__
extern void OsdFontVLCLoadFont(BYTE ucState);
extern void OsdFontVLCDynamicLoadIcon(BYTE ucIconPos, WORD usIcon);
#endif

#ifndef __OSTAR_OSDFONTDYNAMICICON_1__
extern void OsdFontVLCDynamicLoadIcon(BYTE ucIconPos, WORD usIcon);
#endif

#ifndef __OSTAR_OSDFONTDYNAMICICON_2__
extern void OsdFontVLCLoadMainIcon_2(BYTE ucIconPos, WORD usIcon);
#endif

#ifndef __OSTAR_OSDFONTTABLE__
#if((_USE_TIME_SUPPORT == _ON)||(_LOGO_ON_OFF ==_ON))

extern void OsdFontPut1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor);
extern void OsdFontPut1Bit1(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor);

extern void OsdFontPut1BitTable(BYTE ucRow, BYTE ucCol, BYTE *pArray, BYTE ucColor);
extern void OsdFontPut1BitTable1(BYTE ucRow, BYTE ucCol, BYTE *pArray, BYTE ucColor);

#endif
extern void OsdFontPut1ChooseIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucForeground, BYTE ucBackground);
extern void OsdFontPut1FuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucLength,BYTE ucForeground, BYTE ucBackground);
extern void OsdFontPut1FuncVLine(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucHeight,BYTE ucForeground, BYTE ucBackground);
extern void OsdFontPut1FuncTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucType);
extern void OsdFontPut1NumberTableForm(BYTE ucRow, BYTE ucCol, BYTE ucNumberIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucnumber);
extern void OsdFontPut1FuncAimTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType);
extern void OsdThreeColorChooseTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType);
extern void OsdFontPut1BitMainMenuIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void OsdFontPut2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void OsdFontPut2BitTable(BYTE ucRow, BYTE ucCol, BYTE *pArray, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
#endif

#ifndef __OSTAR_OSDFONTPROP__
extern void OsdPropPutString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor, BYTE ucLanguage);
extern void OsdPropPutStringCenter(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor , BYTE ucLanguage);
extern void OsdPropShowNumber(BYTE ucRow, BYTE ucCol, DWORD usValue, BYTE ucPar ,BYTE ucFontPoint, BYTE ucColor);
extern void COsdShowPageInputStringAll(BYTE InputOsd,BYTE MAINOSDINF);
extern void COsdShowPageInputString(BYTE InputOsd,BYTE InputType,BYTE NUM,BYTE MAINOSDINF);
#endif


#ifndef __OSTAR_OSDPALETTE__
extern void OsdPaletteSelectPalette(BYTE ucValue);
#endif

#ifndef __OSTAR_OSDWINDOW__
extern void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void OsdWindowDrawingByFontHighlight(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucForegroundColor, BYTE BackgroundColor);
extern void OsdWindowDrawingSelect(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void OsdWindowSlider(BYTE ucRow, BYTE ucCol, BYTE ucPercentValue, BYTE ucSliderNumber, bit bSelectState);
extern void OsdWindowSliderDisable(void);
#endif

//----------------------------------------------------------------------------------------
// Extern functions from OsdTableFunc.c
//----------------------------------------------------------------------------------------
#ifndef __OSTAR_OSDTABLEFUNC__
extern void OsdTableFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD usValue, BYTE ucPar ,BYTE ucFontPoint);
extern BYTE OsdTableFuncVideoResolution(void);
extern void OsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucLanguage);
extern void OsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, SBYTE ucCenterOffset , BYTE ucLanguage);
extern void OsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdTableFuncPutIcon1BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void OsdTableFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
#endif
#if((_AUDIO_SUPPORT == _ON) && (_AUDIO_HEADPHONE_SUPPORT == _ON))
extern void OsdAudioHeadphoneScan(void);
#endif

 // Add SSC Adjust by yj 160927
extern BYTE ucEmiSSC;
#define _DDCCI_OPCODE_VCP_HDMI_FREESYNC_SUPPORT     0xE6

#endif//#if(_OSD_TYPE == _OSTAR_2014_OSD)

