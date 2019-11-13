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
// ID Code      : RTD2014Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "RTD2014Project.h"
#include "RTD2014NVRamOsd.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)





#define _OSD_MAIN_MENU_WIDTH                      (74+2) //150//132// 88//small osd set
#define _OSD_RIGHT_KEY_WIDTH                      34 //150//132// 88//small osd set
#define _OSD_LEFT_KEY_WIDTH                      80 //150//132// 88//small osd set
#define _OSD_LEFT_KEY_AIM_WIDTH                      8 //150//132// 88//small osd set
#define _OSD_MENU_HOT_INPUT_WIDTH                    ( 3+(11* (_OSD_INPUT_AMOUNT)))//150//132// 88//small osd set
#define _OSD_LEFT_KEY_TIMER_WIDTH                      12 //150//132// 88//small osd set
#define _OSD_INPUT_PORT_INFORMATION_WIDTH                      24 //150//132// 88//small osd set
#define _OSD_MAIN_MENU_HEIGHT                       26
#define _OSD_RIGHT_KEY_HEIGHT                       10
#define _OSD_LEFT_KEY_HEIGHT                       24
#define _OSD_LEFT_KEY_AIM_HEIGHT                    4
#define _OSD_MENU_HOT_INPUT_HEIGHT                      5 //150//132// 88//small osd set
#define _OSD_LEFT_KEY_TIMER_HEIGHT                    5
#define _OSD_INPUT_PORT_INFORMATION_HEIGHT         8

//=========== OSD Font Icon Address ======================//
#define _1GLOBAL_START                          0x00                        // Global 49
#define _1DYNAMIC_START                         _1GLOBAL_START + 30          // Dynamic 0
#define _1DYNAMIC_ICON_START                    _1DYNAMIC_START + 0x08         // main menu icon (6 x 4 x 8) = 196

#define _2BIT_ICON_OFFSET                     0xff // 0x7F
#define _2BIT_ICON_START_ADDRESS               0xff  //  0x7F
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

typedef enum
{   
    _OSD_INPUT_D0,
    _OSD_INPUT_D1,
    _OSD_INPUT_D3,
    _OSD_INPUT_AMOUNT,
       _OSD_INPUT_D2,
    
    _OSD_INPUT_D4,
  _OSD_INPUT_AUTO,
    _OSD_INPUT_D5,
    _OSD_INPUT_D6,
      _OSD_INPUT_A0,
}EnumOSDInputPortDef;






#define _ECO_MOVIE_BACKLIGHT					(_BACKLIGHT_MIN+2*90)
#define _ECO_GAME_BACKLIGHT						(_BACKLIGHT_MIN+2*90)
#define _ECO_TEXT_BACKLIGHT						(_BACKLIGHT_MIN+2*70)
#define _ECO_STANDARD_BACKLIGHT						(_BACKLIGHT_MIN+2*80)

//2608 1376
#define _ECO_MOVIE_CONTRAST						2048//50
#define _ECO_GAME_CONTRAST						2288//65
#define _ECO_TEXT_CONTRAST						1888//40
#define _ECO_STANDARD_CONTRAST						2048

#if(_EOC_RTS_FPS_SUPPORT == _ON)
#define _ECO_FPS_BACKLIGHT						(_BACKLIGHT_MIN+2*100)
#define _ECO_RTS_BACKLIGHT						(_BACKLIGHT_MIN+2*100)

#define _ECO_FPS_CONTRAST						2448//60
#define _ECO_RTS_CONTRAST						2608//75
#endif

#define _ECO_FPS_SHARPNESS		                2
#define _ECO_RTS_SHARPNESS		                3



#define  _ICON1_ROW            4
#define  _ICON2_ROW           7
#define  _ICON3_ROW           10
#define  _ICON4_ROW          13
#define  _ICON5_ROW     16
#define  _ICON6_ROW     19

#define  _ICON_COL     2


#define ICON_LINE_LEFT    1
#define ICON_LINE_RIGHT   15

#define FONT1_ROW    5
#define FONT2_ROW    7
#define FONT3_ROW   9
#define FONT4_ROW    11
#define FONT5_ROW    13
#define FONT6_ROW    15
#define FONT7_ROW    17


#define FONT1_COL     6
#define FONT2_COL   19
#define FONT3_COL   36
#define FONT4_COL   53


#define SELECT_ICON  (36+12)

#define SLIDER_ROW  11
#define SLIDER_COL  35








//****************************************************************************
#define   _1BIT_ICON_START                         0x01
#define _HKC_BAR_L                                  (_1BIT_ICON_START + 0x04)
#define _HKC_BAR0                                    (_1BIT_ICON_START + 0x05)
#define _HKC_BAR1                                    (_1BIT_ICON_START + 0x06)
#define _HKC_BAR2                                    (_1BIT_ICON_START + 0x07)
#define _HKC_BAR3                                    (_1BIT_ICON_START + 0x08)
#define _HKC_BAR4                                    (_1BIT_ICON_START + 0x09)
#define _HKC_BAR5                                    (_1BIT_ICON_START + 0x0a)
#define _HKC_BAR6                                    (_1BIT_ICON_START + 0x0b)
#define _HKC_BAR7                                    (_1BIT_ICON_START + 0x0c)
#define _HKC_BAR8                                    (_1BIT_ICON_START + 0x0d)
#define _HKC_BAR9                                    (_1BIT_ICON_START + 0x0e)
#define _HKC_BAR10                                  (_1BIT_ICON_START + 0x0f)
#define _HKC_BAR_R                                  (_1BIT_ICON_START + 0x10)


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




//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#if(_A0_INPUT_PORT_TYPE == _A0_VGA_PORT)
#define _A0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_VGA)
#else
#define _A0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
#define _D0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DVI)
#elif(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
#define _D0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_HDMI)
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
#define _D0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DP)
#elif(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
#define _D0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_MHL)
#else
#define _D0_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
#define _D1_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DVI)
#elif(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
#define _D1_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_HDMI)
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#define _D1_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DP)
#elif(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
#define _D1_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_MHL)
#else
#define _D1_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
#define _D2_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DVI)
#elif(_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)
#define _D2_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_HDMI)
#elif(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
#define _D2_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DP)
#elif(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
#define _D2_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_MHL)
#else
#define _D2_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif


#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
#define _D3_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DVI)
#elif(_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)
#define _D3_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_HDMI)
#elif(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
#define _D3_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_MHL)
#else
#define _D3_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
#define _D4_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DVI)
#elif(_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)
#define _D4_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_HDMI)
#elif(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define _D4_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_MHL)
#else
#define _D4_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif


#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
#define _D5_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DVI)
#elif(_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)
#define _D5_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_HDMI)
#elif(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
#define _D5_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_MHL)
#else
#define _D5_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif



#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
#define _D6_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_DP)
#else
#define _D6_INPUT_TYPE                              (_OPTION_ICON_END + _INPUT_NO_PORT)
#endif


//--------------------------------------------------
// Definitions of Contrast Range (Real Value)
//--------------------------------------------------
#if(_CTS_TYPE == _CTS_GEN_1_12BIT)
#define _CONTRAST_MAX                              2368// 2848
#define _CONTRAST_MIN                               1248
#else
#define _CONTRAST_MAX                               178
#define _CONTRAST_MIN                               78
#endif

#define _CONTRAST_CENTER                            (((_CONTRAST_MAX - _CONTRAST_MIN) / 2) + _CONTRAST_MIN)





#define _COLORTEMP_MAX                               255
#define _COLORTEMP_MIN                          0
#define _COLORTEMP_CENTER                                  (((_COLORTEMP_MAX - _COLORTEMP_MIN) / 2) + _COLORTEMP_MIN)


//--------------------------------------------------
// Definitions of Backlight Range
//--------------------------------------------------
#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)
#define _BACKLIGHT_MAX                              255
#else
#define _BACKLIGHT_MAX                              4095
#endif
#define _BACKLIGHT_MIN                              55
#define _BACKLIGHT_CENTER                           179//(((_BACKLIGHT_MAX - _BACKLIGHT_MIN) / 2) + _BACKLIGHT_MIN)


//--------------------------------------------------
#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)
#define _VOLUM_MAX                              255
#else
#define _VOLUM_MAX                              4095
#endif
#define _VOLUM_MIN                              0
#define _VOLUM_CENTER                           (((_BACKLIGHT_MAX - _BACKLIGHT_MIN) / 2) + _BACKLIGHT_MIN)

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
#define _SHARPNESS_CENTER                           (((_SHARPNESS_MAX - _SHARPNESS_MIN) / 2) + _SHARPNESS_MIN)
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
#define _OD_GAIN_CENTER                           10//  (((_OD_GAIN_MAX - _OD_GAIN_MIN) / 2) + _OD_GAIN_MIN)

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
#define _OSD_TRANSPARENCY_MAX                       255
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
#define _5_KEY_MESSAGE                              4
#define _6_KEY_MESSAGE                              5
#define _7_KEY_MESSAGE                              6
#define _HOLD_KEY_MESSAGE                           7
#define _NONE_KEY_MESSAGE                           8

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
#define FONTBYTE0(x)                                HIBYTE(0x1000 | (x)), LOBYTE(0x1000 | (x))
#define FONTBYTE1(x)                                HIBYTE(0x5000 | (x)), LOBYTE(0x5000 | (x))
#define FONTBYTE2(x)                                HIBYTE(0x9000 | (x)), LOBYTE(0x9000 | (x))
#define FONTALLBYTE(x)                              HIBYTE(0xD000 | (x)), LOBYTE(0xD000 | (x))
#define WINDOWBYTE0(x)                              HIBYTE(0x0000 | (x)), LOBYTE(0x0000 | (x))
#define WINDOWBYTE1(x)                              HIBYTE(0x4000 | (x)), LOBYTE(0x4000 | (x))
#define WINDOWBYTE2(x)                              HIBYTE(0x8000 | (x)), LOBYTE(0x8000 | (x))
#define WINDOWALLBYTE(x)                            HIBYTE(0xC000 | (x)), LOBYTE(0xC000 | (x))
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
#define PIXELROW(x)                                 ((x) * 18)
#define PIXELCOL(x)                                 ((x) * 12)

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
#if(_DP_DEBUG_MSG == _ON)
//--------------------------------------------------
// MACRO for Power Saving Show DP Info
//--------------------------------------------------
#define GET_OSD_POWER_SAVING_SHOW_DP_INFO()         (g_stOsdInfo.b1OsdWakeUpShowDpINFO)
#define SET_OSD_POWER_SAVING_SHOW_DP_INFO(x)        (g_stOsdInfo.b1OsdWakeUpShowDpINFO = (x))
#define GET_OSD_POWER_SAVING_SHOW_DP_INFO_PORT()    (g_stOsdInfo.b4OsdWakeUpShowDpINFOPort)
#define SET_OSD_POWER_SAVING_SHOW_DP_INFO_PORT(x)   (g_stOsdInfo.b4OsdWakeUpShowDpINFOPort = (x))


#endif

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
// MACRO for OSD double size
//--------------------------------------------------
#define GET_OSD_DOUBLE_SIZE()                       (g_stOsdInfo.b1OsdDoubleSizeStatus)
#define SET_OSD_DOUBLE_SIZE(x)                      (g_stOsdInfo.b1OsdDoubleSizeStatus = (x))

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
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#define GET_OSD_DISP_ROTATION_SIZE_TYPE()           (g_stOSDUserData.b2DispRotationSizeType)
#define SET_OSD_DISP_ROTATION_SIZE_TYPE(x)          (g_stOSDUserData.b2DispRotationSizeType = (x))
#endif


//--------------------------------------------------
// MACRO for DP Port Version
//--------------------------------------------------
#define GET_OSD_DP_D0_VERSION()                     (g_stOSDUserData.b2OsdDpD0PortVersion)
#define SET_OSD_DP_D0_VERSION(x)                    (g_stOSDUserData.b2OsdDpD0PortVersion = (x))

#define GET_OSD_DP_D1_VERSION()                     (g_stOSDUserData.b2OsdDpD1PortVersion)
#define SET_OSD_DP_D1_VERSION(x)                    (g_stOSDUserData.b2OsdDpD1PortVersion = (x))

#define GET_OSD_DP_D2_VERSION()                     (g_stOSDUserData.b2OsdDpD2PortVersion)
#define SET_OSD_DP_D2_VERSION(x)                    (g_stOSDUserData.b2OsdDpD2PortVersion = (x))

#define GET_OSD_DP_D6_VERSION()                     (g_stOSDUserData.b2OsdDpD6PortVersion)
#define SET_OSD_DP_D6_VERSION(x)                    (g_stOSDUserData.b2OsdDpD6PortVersion = (x))

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
// Macro of ECO_MODE


#define GET_ECO_MODE()                         (g_stOSDUserData.b3ECOMode)
#define SET_ECO_MODE(x)                        (g_stOSDUserData.b3ECOMode = (x))

//--------------------------------------------------
// MACRO for Sharpness
//--------------------------------------------------
#define GET_OSD_SHARPNESS()                         (g_stOSDUserData.b3Sharpness)
#define SET_OSD_SHARPNESS(x)                        (g_stOSDUserData.b3Sharpness = (x))


//--------------------------------------------------
// Macro of Aspect Origin Ratio
//--------------------------------------------------
#define GET_OSD_ASPECT_ORIGIN_RATIO()               (g_stOSDUserData.ucAspectOriginRatio)
#define SET_OSD_ASPECT_ORIGIN_RATIO(x)              (g_stOSDUserData.ucAspectOriginRatio = (x))

//--------------------------------------------------
// Macro of Color Temperature
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE()                       (g_stOSDUserData.b4ColorTempType)
#define SET_COLOR_TEMP_TYPE(x)                      (g_stOSDUserData.b4ColorTempType = (x))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_R()                (g_stColorProcData.usColorTempR >> 4)
#define SET_COLOR_TEMP_TYPE_USER_R(x)               (g_stColorProcData.usColorTempR = ((x) << 4))

//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_G()                (g_stColorProcData.usColorTempG >> 4)
#define SET_COLOR_TEMP_TYPE_USER_G(x)               (g_stColorProcData.usColorTempG = ((x) << 4))
//--------------------------------------------------
// Macro of Color Temperature User R
//--------------------------------------------------
#define GET_COLOR_TEMP_TYPE_USER_B()                (g_stColorProcData.usColorTempB >> 4)
#define SET_COLOR_TEMP_TYPE_USER_B(x)               (g_stColorProcData.usColorTempB = ((x) << 4))

//--------------------------------------------------
// MACRO for Aspect Ratio Status
//--------------------------------------------------
#define GET_OSD_ASPECT_RATIO_TYPE()                 (g_stOSDUserData.b3AspectRatio)
#define SET_OSD_ASPECT_RATIO_TYPE(x)                (g_stOSDUserData.b3AspectRatio = (x))


#define GET_OSD_LOW_BLUE()                 (g_stOSDUserData.b3LowBlue)
#define SET_OSD_LOW_BLUE(x)                (g_stOSDUserData.b3LowBlue = (x))

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
// MACRO for DCRStatus
//--------------------------------------------------
#define GET_OSD_DCR_STATUS()                        (g_stOSDUserData.b1OsdDcrStatus)
#define SET_OSD_DCR_STATUS(x)                       (g_stOSDUserData.b1OsdDcrStatus = (x))

//--------------------------------------------------
// MACRO for FreeSync Status
//--------------------------------------------------
#define GET_OSD_FREE_SYNC_STATUS()                  (g_stOSDUserData.b1FreeSyncStatus)
#define SET_OSD_FREE_SYNC_STATUS(x)                 (g_stOSDUserData.b1FreeSyncStatus = (x))



#define GET_OSD_FREE_SYNC_HOT_PLUG()                  (g_stOSDUserData.b1FREESYNC_HOTPLUG)
#define SET_OSD_FREE_SYNC_HOT_PLUG(x)                 (g_stOSDUserData.b1FREESYNC_HOTPLUG = (x))

#define GET_OSD_FACTORY_STATUS()                  (g_stOSDUserData.b1FACTORYSTATUS)
#define SET_OSD_FACTORY_STATUS(x)                 (g_stOSDUserData.b1FACTORYSTATUS = (x))

#define GET_OSD_BURN_STATUS()                  (g_stOSDUserData.b1BURNSTATUS)
#define SET_OSD_BURN_STATUS(x)                 (g_stOSDUserData.b1BURNSTATUS = (x))


//--------------------------------------------------
// MACRO for Clone Mode
//--------------------------------------------------
#define GET_OSD_CLONE_MODE()                        (g_stOSDUserData.b1CloneMode)
#define SET_OSD_CLONE_MODE(x)                       (g_stOSDUserData.b1CloneMode = (x))

#if(_ULTRA_HDR_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for HDR Mode
//--------------------------------------------------
#define GET_OSD_HDR_MODE()                          (g_stOSDUserData.ucHdrMode)
#define SET_OSD_HDR_MODE(x)                         (g_stOSDUserData.ucHdrMode = (x))

//--------------------------------------------------
// MACRO for Dark Enhance Status
//--------------------------------------------------
#define GET_OSD_DARK_ENHANCE_STATUS()               (g_stOSDUserData.b1DarkEnhanceStatus)
#define SET_OSD_DARK_ENHANCE_STATUS(x)              (g_stOSDUserData.b1DarkEnhanceStatus = (x))

//--------------------------------------------------
// MACRO for HDR Sharpness
//--------------------------------------------------
#define GET_OSD_HDR_SHARPNESS()                     (g_stOSDUserData.b1HdrSharpnesse)
#define SET_OSD_HDR_SHARPNESS(x)                    (g_stOSDUserData.b1HdrSharpnesse = (x))

//--------------------------------------------------
// MACRO for HDR Contrast
//--------------------------------------------------
#define GET_OSD_HDR_CONTRAST()                      (g_stOSDUserData.ucHdrContrast)
#define SET_OSD_HDR_CONTRAST(x)                     (g_stOSDUserData.ucHdrContrast = (x))

#endif

#if(_LOCAL_DIMMING_SUPPORT == _ON)
//--------------------------------------------------
// MACRO for Local Dimming
//--------------------------------------------------
#define GET_OSD_LOCAL_DIMMING()                     (g_stOSDUserData.b1HdrLocalDimming)
#define SET_OSD_LOCAL_DIMMING(x)                    (g_stOSDUserData.b1HdrLocalDimming= (x))

//--------------------------------------------------
// MACRO for Local Dimming Smooth Backlight adjust
//--------------------------------------------------
#define GET_OSD_LD_ADJ()                            (g_stOSDUserData.ucHdrLocalDimmingAdj)
#define SET_OSD_LD_ADJ(x)                           (g_stOSDUserData.ucHdrLocalDimmingAdj = (x))
#endif
//--------------------------------------------------
// MACRO for Volume Mute
//--------------------------------------------------
#define GET_OSD_VOLUME_MUTE()                       (g_stOSDUserData.b1VolumeMute)
#define SET_OSD_VOLUME_MUTE(x)                      (g_stOSDUserData.b1VolumeMute = (x))
#define GET_OSD_LED()                             (g_stOSDUserData.b1LED)
#define SET_OSD_LED(x)                            (g_stOSDUserData.b1LED = (x))


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
#define GET_OSD_AUDIO_SOURCE()                      (g_stOSDUserData.b1AudioSourceStatus)
#define SET_OSD_AUDIO_SOURCE(x)                     (g_stOSDUserData.b1AudioSourceStatus = (x))

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
#define GET_OSD_HLWIN_TYPE()                        (g_stOSDUserData.ucHLWinType)
#define SET_OSD_HLWIN_TYPE(x)                       (g_stOSDUserData.ucHLWinType = (x))

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
// MACRO for DP Lane Count switch
//--------------------------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
#define GET_OSD_DP_D0_LANE_MODE()                   (g_stOSDUserData.b3D0DpLaneMode)
#define SET_OSD_DP_D0_LANE_MODE(x)                  (g_stOSDUserData.b3D0DpLaneMode = (x))
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#define GET_OSD_DP_D1_LANE_MODE()                   (g_stOSDUserData.b3D1DpLaneMode)
#define SET_OSD_DP_D1_LANE_MODE(x)                  (g_stOSDUserData.b3D1DpLaneMode = (x))
#endif
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
#define GET_OSD_DP_D2_LANE_MODE()                   (g_stOSDUserData.b3D2DpLaneMode)
#define SET_OSD_DP_D2_LANE_MODE(x)                  (g_stOSDUserData.b3D2DpLaneMode = (x))
#endif
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
#define GET_OSD_DP_D6_LANE_MODE()                   (g_stOSDUserData.b3D6DpLaneMode)
#define SET_OSD_DP_D6_LANE_MODE(x)                  (g_stOSDUserData.b3D6DpLaneMode = (x))
#endif

//--------------------------------------------------
// MACRO for OSD double size
//--------------------------------------------------
#define GET_OSD_NVRAM_DOUBLE_SIZE()                 (g_stOSDUserData.b1OsdDoubleSize)
#define SET_OSD_NVRAM_DOUBLE_SIZE(x)                (g_stOSDUserData.b1OsdDoubleSize = (x))

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

#define GET_BURN_TIME_HOUR()                       (g_stPanelTimeData.usBurnHour)
#define SET_BURN_TIME_HOUR(x)                      (g_stPanelTimeData.usBurnHour = (x))

#define GET_BURN_TIME_MIN()                        (g_stPanelTimeData.usBurnHour)
#define SET_BURN_TIME_MIN(x)                       (g_stPanelTimeData.usBurnHour = (x))

//--------------------------------------------------
// MACRO for Factory Power Saving Case
//--------------------------------------------------
#define GET_FORCE_POW_SAV_STATUS()                  (g_bForcePowSavStatus)
#define SET_FORCE_POW_SAV_STATUS(x)                 (g_bForcePowSavStatus = (x))



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
// Definitions of OSD Number ROW COL
//--------------------------------------------------
//#define _OSD_NUMBER_1_ROW                           15
#define _OSD_NUMBER_1_COL                           21

#define _OSD_NUMBER_UNSTLECT_COLOR                  COLOR(_CP_BLUE, _CP_BG)
#define _OSD_NUMBER_UNSTLECT_COLOR                  COLOR(_CP_BLUE, _CP_BG)
//--------------------------------------------------
// Definitions of OSD
//--------------------------------------------------
#define _PFONT_PAGE_0                               0
#define _PFONT_PAGE_1                               1
#define _PFONT_PAGE_2                               2
#define _PFONT_PAGE_ITEM_1                          3
#define _PFONT_PAGE_ITEM_2                          4
#define _PFONT_PAGE_ITEM_3                          5
#define _PFONT_PAGE_ITEM_4                          6
#define _PFONT_PAGE_ITEM_5                          7
#define _PFONT_PAGE_ITEM_6                          8
#define _PFONT_PAGE_ITEM_7                          9
#define _PFONT_PAGE_ITEM_8                          10
#define _PFONT_PAGE_3                              11

#define _OSD_GLOBAL_START                           0x01
#define _OSD_GLOBAL_END                             0x40

#define _OSD_PAGE_0_START                           0x41
#define _OSD_PAGE_0_END                             0x70

#define _OSD_PAGE_1_START                           0x71
#define _OSD_PAGE_1_END                             0xA5

#define _OSD_PAGE_2_START                           0xA6
#define _OSD_PAGE_2_END                             0xD0

#define _OSD_PAGE_3_START                           0xD1
#define _OSD_PAGE_3_END                             0xFE

#define _SUB_PAGE_ITEM_1                            (_OSD_PAGE_2_START)
#define _SUB_PAGE_ITEM_1_END                        (_OSD_PAGE_2_START + 3)
#define _SUB_PAGE_ITEM_2                            (_SUB_PAGE_ITEM_1_END)
#define _SUB_PAGE_ITEM_2_END                        (_SUB_PAGE_ITEM_1_END + 3)
#define _SUB_PAGE_ITEM_3                            (_SUB_PAGE_ITEM_2_END)
#define _SUB_PAGE_ITEM_3_END                        (_SUB_PAGE_ITEM_2_END + 3)
#define _SUB_PAGE_ITEM_4                            (_SUB_PAGE_ITEM_3_END)
#define _SUB_PAGE_ITEM_4_END                        (_SUB_PAGE_ITEM_3_END + 3)
#define _SUB_PAGE_ITEM_5                            (_SUB_PAGE_ITEM_4_END)
#define _SUB_PAGE_ITEM_5_END                        (_SUB_PAGE_ITEM_4_END + 3)
#define _SUB_PAGE_ITEM_6                            (_SUB_PAGE_ITEM_5_END)
#define _SUB_PAGE_ITEM_6_END                        (_SUB_PAGE_ITEM_5_END + 1)
#define _SUB_PAGE_ITEM_7                            (_SUB_PAGE_ITEM_6_END)
#define _SUB_PAGE_ITEM_7_END                        (_SUB_PAGE_ITEM_6_END + 8)
#define _SUB_PAGE_ITEM_8                            (_SUB_PAGE_ITEM_7_END)
#define _SUB_PAGE_ITEM_8_END                        (_SUB_PAGE_ITEM_7_END + 18)

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
#define _WIN8                                       8
#define _WIN9                                       9
#define _WIN_ALL                                    0xFF

#define _WIN0_TRANS                                 (_BIT7 | 0)
#define _WIN1_TRANS                                 (_BIT7 | 1)
#define _WIN2_TRANS                                 (_BIT7 | 2)
#define _WIN3_TRANS                                 (_BIT7 | 3)
#define _WIN4_TRANS                                 (_BIT7 | 4)
#define _WIN5_TRANS                                 (_BIT7 | 5)
#define _WIN6_TRANS                                 (_BIT7 | 6)
#define _WIN7_TRANS                                 (_BIT7 | 7)

#define COLOR(fg, bg)                               ((fg) << 4 | (bg))
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
#define _WIN0_ROTATE_BORDER_COLOR                   ((_CP_DARKBLUE << 4) | _CP_DARKBLUE)
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



#define _OSD_UNSELECT                               0
#define _OSD_SELECT                                 1
#define _OSD_REJECT                                 2
#define _OSD_ADJUST                                 3
#define _OSD_UNHIGHLIGHT                            4
#define _OSD_HIGHLIGHT                              5
#define _OSD_PRE_SELECT                             6
#define _OSD_SELECT_ADJUST                          7


#define _KEY_INFO_ENTER                             0
#define _KEY_INFO_RIGHT                             1
#define _KEY_INFO_LEFT                              2
#define _KEY_INFO_EXIT                              3
#define _KEY_INFO_BACK                              4
#define _KEY_INFO_ALL                               5   // exit, left, right, enter

//=============== 1Bit Icon ========================

typedef enum
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
}EnumOneBitGLOBAL;
#if(_OSD_LOGO_TYPE ==  _DNA_LOGO)

#define _LOGO_WINDOW_SIZE_X                         46*12
#define _LOGO_WINDOW_SIZE_Y                         9*18
#elif(_OSD_LOGO_TYPE ==  _NEWSKILL_LOGO)

#define _LOGO_WINDOW_SIZE_X                         50*12
#define _LOGO_WINDOW_SIZE_Y                         9*18
#else
#define _LOGO_WINDOW_SIZE_X                         81*12
#define _LOGO_WINDOW_SIZE_Y                         9*18
#endif


//=============== 2Bit Icon ========================



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
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
#define _PALETTE_INDEX0                             0   // 0 ~ 15
#define _PALETTE_INDEX1                             1   // 16 ~ 31
#define _PALETTE_INDEX2                             2   // 32 ~ 47
#define _PALETTE_INDEX3                             3   // 48 ~ 63

// OSD Position
#define _POS_DIRECT                                 0
#define _POS_PERCENT                                1
#define _POS_GAME_MODE                               2

//--------------------------------------------------
// Definations of OSD MAIN MENU
//--------------------------------------------------
//#define _OSD_MAIN_MENU_WIDTH                        44
//#define _OSD_MAIN_MENU_HEIGHT                       22

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
#define _SLIDER_LENGHT                              250
#define _SLIDER_HIGH                                20
#define _SLIDER_BORDER_PIXEL                        2
#define _SLIDER_OFFSET                              6

#define _SLIDER_SELECT_BORDER_COLOR                 _CP_GRAY
#define _SLIDER_SELECT_BG_COLOR                     _CP_WHITE

#define _SLIDER_UNSELECT_BORDER_COLOR               _CP_WHITE
#define _SLIDER_UNSELECT_BG_COLOR                   _CP_GRAY

#define _SLIDER_SELECT_COLOR                        _CP_ORANGE
#define _SLIDER_UNSELECT_COLOR                      _CP_BLUE

#define _SLIDER_0                                   0
#define _SLIDER_1                                   1
#define _SLIDER_2                                   2

#define _SELECT                                     1
#define _UNSELECT                                   0

#define _SLIDER_0_BAR_WINDOW                        _OSD_WINDOW_4_8 // _OSD_WINDOW_4_5
#define _SLIDER_0_BG_WINDOW                         _OSD_WINDOW_4_7 // _OSD_WINDOW_4_4
#define _SLIDER_0_BORDER_WINDOW                     _OSD_WINDOW_4_6 // _OSD_WINDOW_4_3

#define _SLIDER_1_BAR_WINDOW                        _OSD_WINDOW_4_8
#define _SLIDER_1_BG_WINDOW                         _OSD_WINDOW_4_7
#define _SLIDER_1_BORDER_WINDOW                     _OSD_WINDOW_4_6

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
// HDMI Freesync
//--------------------------------------------------
#define _DDCCI_OPCODE_VCP_HDMI_FREESYNC_SUPPORT     0xE6

//--------------------------------------------------
// Define enter panel uniformity msg adjust from pcm or gamma
//--------------------------------------------------
typedef enum
{
    _FROM_STATE_PCM,
    _FROM_STATE_GAMMA,
    _FROM_STATE_HDR,
    _FROM_STATE_LD,
} EnumFromWhichState;


//--------------------------------------------------
// Define PCM Soft Proft
//--------------------------------------------------
typedef enum
{
    _PCM_SOFT_MODE_1,
    _PCM_SOFT_MODE_2,
    _PCM_SOFT_MODE_AMOUNT = _PCM_SOFT_MODE_2,
} EnumPCMSoftProftMode;


//--------------------------------------------------
// Define Gamma
//--------------------------------------------------
typedef enum
{
    _GAMMA_OFF,
    _GAMMA_18,
    _GAMMA_20,
    _GAMMA_22,
    _GAMMA_24,
    _GAMMA_AMOUNT = _GAMMA_24,
}EnumGammaType;

//--------------------------------------------------
// Define HL Window Type
//--------------------------------------------------
typedef enum
{
    _HL_WIN_OFF,
    _HL_WIN_1,
    _HL_WIN_2,
    _HL_WIN_3,
    _HL_WIN_4,
    _HL_WIN_5,
    _HL_WIN_AMOUNT = _HL_WIN_5,
}EnumHLWinType;

typedef enum
{
    _COLOREFFECT_STANDARD,
        _COLOREFFECT_MOVIE,
    _COLOREFFECT_PHOTO,
    _COLOREFFECT_GAME,
#if(_EOC_RTS_FPS_SUPPORT == _ON)
		_COLOREFFECT_FPS,
		_COLOREFFECT_RTS,
#endif
    _COLOREFFECT_USER,
#if (_SDR_TO_HDR_SUPPORT == _ON)
    _COLOREFFECT_HDR_LIKE,
    _COLOREFFECT_HDR_LIKE_PHOTO,
    _COLOREFFECT_AMOUNT = _COLOREFFECT_HDR_LIKE_PHOTO,
#else
    _COLOREFFECT_AMOUNT = _COLOREFFECT_USER,
#endif
    _COLOREFFECT_VIVID,

}EnumColorEffectType;

//--------------------------------------------------
// Define Color Effect Six Color
//--------------------------------------------------
typedef enum
{
    _SIXCOLOR_R,
    _SIXCOLOR_Y,
    _SIXCOLOR_G,
    _SIXCOLOR_C,
    _SIXCOLOR_B,
    _SIXCOLOR_M,
    _SIXCOLOR_AMOUNT = _SIXCOLOR_M,
}EnumSixColorType;

//--------------------------------------------------
// Define Ultra Vivid
//--------------------------------------------------
typedef enum
{
    _ULTRA_VIVID_OFF,
    _ULTRA_VIVID_L,
    _ULTRA_VIVID_M,
    _ULTRA_VIVID_H,
    _ULTRA_VIVID_AMOUNT = _ULTRA_VIVID_H,
}EnumUltraVividType;


//--------------------------------------------------
// Define Supported Aspect Ratios
//--------------------------------------------------
typedef enum
{
    _OSD_ASPECT_RATIO_FULL,
    _OSD_ASPECT_RATIO_16_BY_9,
    _OSD_ASPECT_RATIO_4_BY_3,
    _OSD_ASPECT_RATIO_5_BY_4,
    _OSD_ASPECT_RATIO_ORIGIN,
    _OSD_ASPECT_RATIO_AMOUNT = _OSD_ASPECT_RATIO_4_BY_3,
}EnumAspectRatioTypeIndex;

//--------------------------------------------------
// Define DP Port Version
//--------------------------------------------------
typedef enum
{
    _DP_VER_1_DOT_1 = 0,
    _DP_VER_1_DOT_2,
    _DP_VER_1_DOT_3,
    _DP_VER_AMOUNT = _DP_VER_1_DOT_3,
}EnumOSDDpPortVersionDef;

typedef enum
{
    _MST_OFF = 0,
    _MST_D0,
    _MST_D1,
    _MST_D6,
    _MST_AMOUNT = _MST_D6,
}EnumOSDDpMstTypeDef;

//--------------------------------------------------
// Define Display Image Rotate
//--------------------------------------------------
typedef enum
{
    _DISP_ROTATE_0 = 0,
#if(_DISPLAY_ROTATION_90_SUPPORT == _ON)
    _DISP_ROTATE_90,
#endif
#if(_DISPLAY_ROTATION_180_SUPPORT == _ON)
    _DISP_ROTATE_180,
#endif
#if(_DISPLAY_ROTATION_270_SUPPORT == _ON)
    _DISP_ROTATE_270,
#endif
#if(_DISPLAY_HOR_MIRROR_SUPPORT == _ON)
    _DISP_ROTATE_HOR_MIRROR,
#endif
#if(_DISPLAY_VER_MIRROR_SUPPORT == _ON)
    _DISP_ROTATE_VER_MIRROR,
#endif

    _DISP_ROTATE_AMOUNT,

}EnumOSDDispRotateDegree;

//--------------------------------------------------
// Define Display Latency
//--------------------------------------------------
typedef enum
{
    _LATENCY_L = 0,
    _LATENCY_M,
    _LATENCY_H,
    _LATENCY_AMOUNT = _LATENCY_H,
}EnumOSDDLatency;

//--------------------------------------------------
// Define HotKey Option
//--------------------------------------------------
typedef enum
{
    _HOTKEY_DDCCI = 0,
    _HOTKEY_DP_D0_OPTION,
    _HOTKEY_DP_D1_OPTION,
    _HOTKEY_DP_D2_OPTION,
    _HOTKEY_DP_D6_OPTION,
    _HOTKEY_AMOUNT = _HOTKEY_DP_D6_OPTION,
}EnumOSDHotKeyDef;


//--------------------------------------------------
// Definitions of Input Port
//--------------------------------------------------
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

//--------------------------------------------------
// Definitions of Color Temperature
//--------------------------------------------------
typedef enum
{
		_CT_6500,
		_CT_9300,
		 _CT_7500,
		_CT_USER,
		_CT_COLORTEMP_AMOUNT = _CT_USER,
		_CT_5800,
		_CT_SRGB,

}EnumColortemptureDef;


//--------------------------------------------------
// Definitions of 3D Effect
//--------------------------------------------------
typedef enum
{
    _3D_EFFECT_OFF = _OFF,
    _3D_EFFECT_WEAK,
    _3D_EFFECT_MEDIUM,
    _3D_EFFECT_STRONG,
    _3D_EFFECT_AMOUNT = _3D_EFFECT_STRONG,
}EnumOSDSelect3DEffectDef;

//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
typedef enum
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
}EnumPCMTypeIndex;


typedef enum
{
    _INPUT_OSD_VGA ,    
    _INPUT_OSD_DVI ,
    _INPUT_OSD_HDMI,
    _INPUT_OSD_DP,
    _INPUT_OSD_END,
    
};
//--------------------------------------------------
// Definitions of PCMType
//--------------------------------------------------
typedef enum
{
    _UNIFORMITY_OSD_TYPE1 = 0,  // gamma 1.8
    _UNIFORMITY_OSD_TYPE2,      // gamma 2.0
    _UNIFORMITY_OSD_TYPE3,      // gamma 2.2
    _UNIFORMITY_OSD_TYPE4,      // gamma 2.4
    _UNIFORMITY_OSD_TYPE5,      // srgb
    _UNIFORMITY_OSD_TYPE6,      // adobe rgb
}EnumUniformityTypeSelectIndex;
//--------------------------------------------------
// Definitions of Clone Mode
//--------------------------------------------------
typedef enum
{
    _OSD_CLONE_OFF = 0,
    _OSD_CLONE_ON,
}EnumOSDCloneModeDef;

typedef struct
{
    BYTE b1OsdLogo : 1;
    BYTE b1OsdWakeUpSwitchDdcciPort : 1;
    BYTE b1OsdWakeUpShowSource : 1;
    BYTE b1OsdFactoryModeStatus : 1;
    BYTE b1OsdDoAspectRatio : 1;
    BYTE b3OsdColorFormat : 3;
    BYTE b3OsdsixColor : 3;
    BYTE b1OsdDoubleSizeStatus : 1;
    BYTE b1FreezeStatus : 1;
#if((_URGENT_EVENT_CHECK_MODE == _OFF) && (_FREEZE_SUPPORT == _ON))
    BYTE b1FreezeDisableOsdStatus : 1;
#endif
#if(_DP_DEBUG_MSG == _ON)
    BYTE b1OsdWakeUpShowDpINFO : 1;
    BYTE b4OsdWakeUpShowDpINFOPort : 4;
#endif
    BYTE ucOsdStatePrevious;
    WORD ucOsdState;//By Jerry -2016-10-04//
    BYTE ucOsdEventMsg;
    BYTE ucOsdKeyMessage;
    BYTE ucOsdKeyControl;
    BYTE b3OsdsixColorHue;
    BYTE b3OsdsixColorSaturation;
    BYTE ucOsd3DEffectRealValue;

#if(_FREESYNC_SUPPORT == _ON)
    BYTE ucOsdFREESYNCInforOsdAddress;
#endif
} StructOsdInfo;


typedef enum
{
    _ = 0,
    _0_, _1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, _9_,
    _A_, _B_, _C_, _D_, _E_, _F_, _G_, _H_, _I_, _J_, _K_, _L_, _M_, _N_, _O_, _P_, _Q_, _R_, _S_, _T_, _U_, _V_, _W_, _X_, _Y_, _Z_,
    _a_, _b_, _c_, _d_, _e_, _f_, _g_, _h_, _i_, _j_, _k_, _l_, _m_, _n_, _o_, _p_, _q_, _r_, _s_, _t_, _u_, _v_, _w_, _x_, _y_, _z_,
    _A0_, _a0_, _a1_, _a2_, _a3_, _a4_, _c0_, _E0_, _e0_, _e1_, _e2_, _n0_, _u0_, _u1_, _u2_, _o0_, _o1_, _o2_, _o3_, _i0_,

    _UPDOT_,                // '
    _DOT_,                  // .
    _LEFT_BRACE_,           // (
    _RIGHT_BRACE_,          // )
    _AND_,                  // /
    _COLON_,                // :
    _AT_0_,                 // @
    _COMMA_,                // ,
    _SLINE_,                // -
    _SHIFT_LEFT_,           // <<
    _SHIFT_RIGHT_,          // >>
    _SEPERATE_,             // ;
    _QUERY_,                // ?
}EnumOSDFontDef;
typedef enum
{
    _CP_EMPTY = 0,
    _CP_BG = 0,
    _CP_BLACK = 0,
    _CP_WHITE,
   _CP_RED ,
    _CP_GREEN_119,
    _CP_BLUE,
    _CP_YELLOW,
    _CP_BLACK_1,
    _CP_RED_1,
    _CP_LIGHTBLUE,
    _CP_SELECTBOTTOM,
    _CP_PINK,
   _CP_BLUE_65 ,
    _CP_BLUE_120,
    _CP_ORANGE,
    _CP_ORANGE_H,
    _CP_GRAY,
}EnumOSDColorPaletteDef;

typedef enum
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
}EnumOSDColorPaletteLogo;

typedef enum
{
    _MENU_NONE,

    _MENU_PICTURE,
    _MENU_COLOR,
    _MENU_OSD_SETTING,
    _MENU_SETUP,
    _MENU_OTHER,
	//picture
	_MENU_PICTURE_BACKLIGHT,
	_MENU_PICTURE_CONTRAST,
	_MENU_PICTURE_ECO,
	_MENU_PICTURE_MAIN_SR,
	_MENU_PICTURE_HDR,

	 MENU_PICTURE_BACKLIGHT_ADJ,
	_MENU_PICTURE_CONTRAST_ADJ,
	_MENU_PICTURE_ECO_ADJ,
	_MENU_PICTURE_MAIN_SR_ADJ,
		_MENU_PICTURE_HDR_ADJ,

	//color
	_MENU_COLOR_TEMP,
	_MENU_COLOR_R,
	_MENU_COLOR_G,
	_MENU_COLOR_B,

	_MENU_COLOR_TEMP_ADJ,
	_MENU_COLOR_R_ADJ,
	_MENU_COLOR_G_ADJ,
	_MENU_COLOR_B_ADJ,
//OSD
	_MENU_OSD_LANGUAGE,
	_MENU_OSD_HPos,
	_MENU_OSD_VPos,
	_MENU_OSD_TRNAS,
	_MENU_OSD_TIME,

	_MENU_OSD_LANGUAGE_ADJ,
	_MENU_OSD_H_ADJ,
	_MENU_OSD_V_ADJ,
	_MENU_OSD_TRNA_ADJ,
	_MENU_OSD_TIME_ADJ,
//set up
	_MENU_SETUP_INPUT,
	_MENU_SETUP_MUTE,
	_MENU_SETUP_VOLUME,
	_MENU_SETUP_RESET,


	_MENU_SETUP_INPUT_ADJ,
	_MENU_SETUP_MUTE_ADJ,
	_MENU_SETUP_VOLUME_ADJ,
//others
	_MENU_OTHERS_RATIO,
	_MENU_OTHERS_LOWBLUE,
	_MENU_OTHERS_OD,
	


	
	_MENU_FREESYNC,


	_MENU_OTHERS_RATIO_ADJ,
	_MENU_OTHERS_LOWBLUE_ADJ,
	_MENU_OTHERS_OD_ADJ,
	_MENU_OTHERS_FREESYNC_ADJ,

	_Menu_LEFTKEY_GAME,
	_Menu_LEFTKEY_GAME_ADJUST,
	_Menu_LEFTKEY_TIMER,
	_Menu_LEFTKEY_TIMER_ADJUST,
	_OSD_DISPLEFT_TIMER_MENU,
	_OSD_DISPLEFT_TIMER_MENU_ADJUST,
	_OSD_DISPLEFT_TIMER_MENU_POSITION,

_Menu_Hotkey_ECO_Adjust,
_MENU_HOT_INPUT_ADJUST,
    _MENU_HOTKEY_DDCCI,
    _MENU_HOTKEY_SOURCE,
    _MENU_HOTKEY_DP_OPTION,
    _MENU_PANEL_UNIFORMITY_MSG_ADJUST,
    _MENU_FACTORY,
_OSD_NULL,
    _MENU_END,





	
    _MENU_PICTURE_SHARPNESS,
    _MENU_INFORMATION,


	
    _MENU_PICTURE_BRIGHTNESS,

    _MENU_ADVANCE,
    _MENU_INPUT,
    _MENU_AUDIO,
    _MENU_DISPLAY,
    _MENU_DISPLAY_AUTO,
    _MENU_DISPLAY_HPOS,
    _MENU_DISPLAY_VPOS,
    _MENU_DISPLAY_CLOCK,
    _MENU_DISPLAY_PHASE,
    _MENU_DISPLAY_DISP_ROTATE,
    _MENU_DISPLAY_LATENCY,
    _MENU_DISPLAY_FREEZE,

    _MENU_COLOR_PANEL_UNIFORMITY,
    _MENU_COLOR_GAMMA,
    _MENU_COLOR_TEMPERATURE,
    _MENU_COLOR_EFFECT,
    _MENU_COLOR_DEMO,
    _MENU_COLOR_FORMAT,
    _MENU_COLOR_PCM,
    _MENU_COLOR_HUE,
    _MENU_COLOR_SATURATION,

    _MENU_ADVANCE_ASPECT,
    _MENU_ADVANCE_OVER_SCAN,
    _MENU_ADVANCE_OVER_DRIVE,
    _MENU_ADVANCE_DCR,
    _MENU_ADVANCE_DDCCI,
    _MENU_ADVANCE_ULTRA_VIVID,
    _MENU_ADVANCE_DP_OPTION,
    _MENU_ADVANCE_DP_MST,
    _MENU_ADVANCE_DP_EDID,
    _MENU_ADVANCE_CLONE,
    _MENU_ADVANCE_FREESYNC,
    _MENU_ADVANCE_DP_LANE_COUNT,

#if(_ULTRA_HDR_SUPPORT == _ON)
    _MENU_ADVANCE_HDR,
#endif
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    _MENU_ADVANCE_LOCAL_DIMMING,
#endif
    _MENU_INPUT_AUTO,
    _MENU_INPUT_A0_PORT,
    _MENU_INPUT_D0_PORT,
    _MENU_INPUT_D1_PORT,
    _MENU_INPUT_D2_PORT,
    _MENU_INPUT_D3_PORT,
    _MENU_INPUT_D4_PORT,
    _MENU_INPUT_D5_PORT,
    _MENU_INPUT_D6_PORT,



    _MENU_AUDIO_VOLUME,
    _MENU_AUDIO_MUTE,
    _MENU_AUDIO_STAND_ALONG,
    _MENU_AUDIO_AUDIO_SOURCE,
    _MENU_AUDIO_SOUND_MODE,
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    _MENU_AUDIO_AUDIO_SELF_TEST,
#endif

    _MENU_OTHER_RESET,
    _MENU_OTHER_MENU_TIME,
    _MENU_OTHER_OSD_HPOS,
    _MENU_OTHER_OSD_VPOS,
    _MENU_OTHER_LANGUAGE,
    _MENU_OTHER_TRNASPARENCY,
    _MENU_OTHER_ROTATE,

    _MENU_PICTURE_BACKLIGHT_ADJUST,
    _MENU_PICTURE_BRIGHTNESS_ADJUST,
    _MENU_PICTURE_CONTRAST_ADJUST,
    _MENU_PICTURE_SHARPNESS_ADJUST,

    _MENU_DISPLAY_HPOS_ADJUST,
    _MENU_DISPLAY_VPOS_ADJUST,
    _MENU_DISPLAY_CLOCK_ADJUST,
    _MENU_DISPLAY_PHASE_ADJUST,
    _MENU_DISPLAY_DISP_ROTATE_ADJUST,
    _MENU_DISPLAY_LATENCY_ADJUST,
    _MENU_DISPLAY_FREEZE_ADJUST,

    _MENU_COLOR_PANEL_UNIFORMITY_ADJUST,
    _MENU_COLOR_GAMMA_ADJUST,
    _MENU_COLOR_TEMPERATURE_ADJUST,
    _MENU_COLOR_EFFECT_ADJUST,
    _MENU_COLOR_DEMO_ADJUST,
    _MENU_COLOR_FORMAT_ADJUST,
    _MENU_COLOR_PCM_ADJUST,
    _MENU_COLOR_HUE_ADJUST,
    _MENU_COLOR_SATURATION_ADJUST,

    _MENU_ADVANCE_ASPECT_ADJUST,
    _MENU_ADVANCE_OVER_SCAN_ADJUST,
    _MENU_ADVANCE_OVER_DRIVE_ONOFF,
    _MENU_ADVANCE_OVER_DRIVE_GAIN,
    _MENU_ADVANCE_DCR_ADJUST,
    _MENU_ADVANCE_DDCCI_ADJUST,
    _MENU_ADVANCE_ULTRA_VIVID_ADJUST,
    _MENU_ADVANCE_DP_OPTION_D0,
    _MENU_ADVANCE_DP_OPTION_D1,
    _MENU_ADVANCE_DP_OPTION_D2,
    _MENU_ADVANCE_DP_OPTION_D6,
    _MENU_ADVANCE_DP_MST_ADJUST,
    _MENU_ADVANCE_DP_EDID_ADJUST,
    _MENU_ADVANCE_CLONE_ADJUST,
    _MENU_ADVANCE_FREESYNC_ADJUST,
    _MENU_ADVANCE_DP_LANE_COUNT_D0,
    _MENU_ADVANCE_DP_LANE_COUNT_D1,
    _MENU_ADVANCE_DP_LANE_COUNT_D2,
    _MENU_ADVANCE_DP_LANE_COUNT_D6,

#if(_ULTRA_HDR_SUPPORT == _ON)
    _MENU_ADVANCE_HDR_MODE,
    _MENU_ADVANCE_HDR_DARK_ENHANCE_ONOFF,
    _MENU_ADVANCE_HDR_SHARPNESS_ONOFF,
    _MENU_ADVANCE_HDR_CONTRAST,
#endif
#if(_EDID_SWITCH_BY_PORT_ITEM == _ON)
    _MENU_ADVANCE_EDID_ADJUST,
    _MENU_ADVANCE_EDID_DX_ADJUST,
#endif
    _MENU_AUDIO_VOLUME_ADJUST,
    _MENU_AUDIO_MUTE_ON_OFF,
    _MENU_AUDIO_STAND_ALONG_SELECT,
    _MENU_AUDIO_AUDIO_SOURCE_SELECT,
    _MENU_AUDIO_SOUND_MODE_SELECT,
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    _MENU_AUDIO_AUDIO_SELF_TEST_SELECT,
#endif

    _MENU_OTHER_MENU_TIME_ADJUST,
    _MENU_OTHER_OSD_HPOS_ADJUST,
    _MENU_OTHER_OSD_VPOS_ADJUST,
    _MENU_OTHER_LANGUAGE_ADJUST,
    _MENU_OTHER_TRNASPARENCY_ADJUST,
    _MENU_OTHER_ROTATE_ADJUST,

    _MENU_COLOR_TEMP_USER_R,
    _MENU_COLOR_TEMP_USER_G,
    _MENU_COLOR_TEMP_USER_B,

    _MENU_COLOR_TEMP_USER_ADJUST_R,
    _MENU_COLOR_TEMP_USER_ADJUST_G,
    _MENU_COLOR_TEMP_USER_ADJUST_B,

    _MENU_COLOR_EFF_USER_R,
    _MENU_COLOR_EFF_USER_Y,
    _MENU_COLOR_EFF_USER_G,
    _MENU_COLOR_EFF_USER_C,
    _MENU_COLOR_EFF_USER_B,
    _MENU_COLOR_EFF_USER_M,

    _MENU_COLOR_EFF_USER_R_HUE,
    _MENU_COLOR_EFF_USER_R_SAT,
    _MENU_COLOR_EFF_USER_Y_HUE,
    _MENU_COLOR_EFF_USER_Y_SAT,
    _MENU_COLOR_EFF_USER_G_HUE,
    _MENU_COLOR_EFF_USER_G_SAT,
    _MENU_COLOR_EFF_USER_C_HUE,
    _MENU_COLOR_EFF_USER_C_SAT,
    _MENU_COLOR_EFF_USER_B_HUE,
    _MENU_COLOR_EFF_USER_B_SAT,
    _MENU_COLOR_EFF_USER_M_HUE,
    _MENU_COLOR_EFF_USER_M_SAT,

    _MENU_COLOR_EFF_USER_R_HUE_ADJUST,
    _MENU_COLOR_EFF_USER_R_SAT_ADJUST,
    _MENU_COLOR_EFF_USER_Y_HUE_ADJUST,
    _MENU_COLOR_EFF_USER_Y_SAT_ADJUST,
    _MENU_COLOR_EFF_USER_G_HUE_ADJUST,
    _MENU_COLOR_EFF_USER_G_SAT_ADJUST,
    _MENU_COLOR_EFF_USER_C_HUE_ADJUST,
    _MENU_COLOR_EFF_USER_C_SAT_ADJUST,
    _MENU_COLOR_EFF_USER_B_HUE_ADJUST,
    _MENU_COLOR_EFF_USER_B_SAT_ADJUST,
    _MENU_COLOR_EFF_USER_M_HUE_ADJUST,
    _MENU_COLOR_EFF_USER_M_SAT_ADJUST,

    _MENU_COLOR_PCM_SOFT_PROFT_ADJUST,

    _MENU_ADVANCE_OD_ONOFF_ADJUST,
    _MENU_ADVANCE_OD_GAIN_ADJUST,

    _MENU_ADVANCE_DP_D0_VERSION_ADJUST,
    _MENU_ADVANCE_DP_D1_VERSION_ADJUST,
    _MENU_ADVANCE_DP_D2_VERSION_ADJUST,
    _MENU_ADVANCE_DP_D6_VERSION_ADJUST,

    _MENU_ADVANCE_DP_D0_LANE_COUNT_ADJUST,
    _MENU_ADVANCE_DP_D1_LANE_COUNT_ADJUST,
    _MENU_ADVANCE_DP_D2_LANE_COUNT_ADJUST,
    _MENU_ADVANCE_DP_D6_LANE_COUNT_ADJUST,

#if(_ULTRA_HDR_SUPPORT == _ON)
    _MENU_ADVANCE_HDR_MODE_ADJUST,
    _MENU_ADVANCE_HDR_DARK_ENHANCE_ONOFF_ADJUST,
    _MENU_ADVANCE_HDR_SHARPNESS_ONOFF_ADJUST,
    _MENU_ADVANCE_HDR_CONTRAST_ADJUST,
#endif
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    _MENU_ADVANCE_HDR_LD_ONOFF,
    _MENU_ADVANCE_HDR_LD_SMOOTH_ADJ,
    _MENU_ADVANCE_HDR_LD_ONOFF_ADJUST,
    _MENU_ADVANCE_HDR_LD_SMOOTH_ADJ_ADJUST,
#endif


}EnumOsdMenuState;

typedef enum
{
    _ICON_PAGE_CLEAR = 0,
    _ICON_PAGE_MAIN_0,
    _ICON_PAGE_MAIN_1,
    _ICON_PAGE_MAIN_2,

    _ICON_PAGE_PICTURE_0,

    _ICON_PAGE_DISPLAY_0,
    _ICON_PAGE_DISPLAY_1,

    _ICON_PAGE_COLOR_0,
    _ICON_PAGE_COLOR_1,
    _ICON_PAGE_COLOR_2,

    _ICON_PAGE_ADVANCE_0,
    _ICON_PAGE_ADVANCE_1,
    _ICON_PAGE_ADVANCE_2,
    _ICON_PAGE_ADVANCE_3,

    _ICON_PAGE_INPUT_0,
    _ICON_PAGE_INPUT_1,
    _ICON_PAGE_INPUT_2,

    _ICON_PAGE_AUDIO_0,
    _ICON_PAGE_AUDIO_1,

    _ICON_PAGE_OTHER_0,
    _ICON_PAGE_OTHER_1,

    _ICON_PAGE_INFORMATION_0,

    _ICON_PAGE_FACTORY_0,

    _ICON_PAGE_ON_OFF,
    _ICON_PAGE_ASPECT_RATIO_0,
    _ICON_PAGE_ASPECT_RATIO_1,
    _ICON_PAGE_AUDIO_SOURCE,
    _ICON_PAGE_ULTRA_VIVID,

    _ICON_PAGE_GAMMA_0,
    _ICON_PAGE_GAMMA_1,
    _ICON_PAGE_TEMPRATURE_0,
    _ICON_PAGE_TEMPRATURE_1,

    _ICON_PAGE_COLOR_EFFECT_0,
    _ICON_PAGE_COLOR_EFFECT_1,

    _ICON_PAGE_COLOR_DEMO_0,
    _ICON_PAGE_COLOR_DEMO_1,

    _ICON_PAGE_COLOR_FORMAT,

    _ICON_PAGE_COLOR_PCM_0,
    _ICON_PAGE_COLOR_PCM_1,
    _ICON_PAGE_TEMPERATURE_USER,
    _ICON_PAGE_COLOR_EFFECT_USER_0,
    _ICON_PAGE_COLOR_EFFECT_USER_1,
    _ICON_PAGE_COLOR_RGBYCM_HUE_SAT,

    _ICON_PAGE_PCM_SOFT_PROFT,
    _ICON_PAGE_OSD_ROTATE,
    _ICON_PAGE_OD_ADJUST,

    _ICON_PAGE_DP_OPTION,
    _ICON_PAGE_DP_1_DOT_X,
    _ICON_PAGE_DP_MST,
    _ICON_PAGE_DISP_ROTATE_0,
    _ICON_PAGE_DISP_ROTATE_1,
    _ICON_PAGE_DP_EDID,
    _ICON_PAGE_CLONE_0,
    _ICON_PAGE_FREESYNC,
    _ICON_PAGE_LATENCY,
    _ICON_PAGE_DP_LANE_COUNT,
    _ICON_PAGE_DP_LANE_X,
#if(_ULTRA_HDR_SUPPORT == _ON)
    _ICON_PAGE_HDR_ADJUST,
    _ICON_PAGE_HDR_MODE,
#endif
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    _ICON_PAGE_LOCAL_DIMMING,
#endif
#if(_EDID_SWITCH_BY_PORT_ITEM == _ON)
    _ICON_PAGE_EDID_PORT_0,
    _ICON_PAGE_EDID_PORT_1,
    _ICON_PAGE_HDMI_EDID_D0,
    _ICON_PAGE_HDMI_EDID_D1,
    _ICON_PAGE_HDMI_EDID_D2,
    _ICON_PAGE_HDMI_EDID_D3,
    _ICON_PAGE_HDMI_EDID_D4,
    _ICON_PAGE_HDMI_EDID_D5,
#endif
}EnumIconPageIndex;

typedef enum
{
    _ICON_SUB_SEL_NONE,
    _ICON_SUB_SEL_INPUT,

}EnumIconSun;

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
    _ICON_INFORMATION,
    _ICON_FACTORY,

    // picture
    _ICON_BACKLIGHT,
    _ICON_BRIGHTNESS,
    _ICON_CONTRAST,
    _ICON_SHARPNESS,

    // display
    _ICON_AUTO_ADJUST,
    _ICON_HPOS,
    _ICON_VPOS,
    _ICON_CLOCK,
    _ICON_PHASE,
    _ICON_DISP_ROTATE,
    _ICON_LANTENCY,
    _ICON_FREEZE,


    // color
    _ICON_PANEL_UNIFORMITY,
    _ICON_GAMMA,
    _ICON_COLOR_TEMPERATURE,
    _ICON_COLOR_EFFECT,
    _ICON_COLOR_DEMO,
    _ICON_COLOR_FORMAT,
    _ICON_PCM,
    _ICON_HUE,
    _ICON_SATURATION,

    // advance
    _ICON_DP_LANE,
    _ICON_ASPECT,
    _ICON_OVER_SCAN,
    _ICON_OVER_DRIVE,
    _ICON_DCR,
    _ICON_DDCCI,
    _ICON_ULTRAVIVID,
    _ICON_DP_OPTION,
    _ICON_DP_MST,
    _ICON_DP_EDID,
    _ICON_CLONE,
    _ICON_FREESYNC,
#if(_ULTRA_HDR_SUPPORT == _ON)
    _ICON_HDR,
    _ICON_HDR_MODE,
    _ICON_DARK_ENHANCE,
    _ICON_HDR_SHARPNESS,
#endif
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    _ICON_LOCAL_DIMMING,
#endif

    // input
    _ICON_INPUT_AUTO,


    // audio
    _ICON_VOLUME,
    _ICON_MUTE,
    _ICON_STAND_ALONG,
    _ICON_AUDIO_SOURCE,
    _ICON_SOUND_MODE,
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    _ICON_AUDIO_SELF_TEST,
#endif

    // other
    _ICON_RESET,
    _ICON_MENU_TIME,
    _ICON_OSD_HPOS,
    _ICON_OSD_VPOS,
    _ICON_LANGUAGE,
    _ICON_TRNASPARENCY,
    _ICON_ROTATE,

    //option icon
    _ICON_ON,
    _ICON_OFF,
    _ICON_AUDIO_ANALOG,
    _ICON_AUDIO_DIGITAL,
    _ICON_AS_RATIO_FULL,
    _ICON_AS_RATIO_16_9,
    _ICON_AS_RATIO_4_3,
    _ICON_AS_RATIO_5_4,
    _ICON_AS_RATIO_ORIGINAL,

    _ICON_ULTRA_VIVID_H,
    _ICON_ULTRA_VIVID_M,
    _ICON_ULTRA_VIVID_L,

    _ICON_GAMMA_1_8,
    _ICON_GAMMA_2_0,
    _ICON_GAMMA_2_2,
    _ICON_GAMMA_2_4,

    _ICON_TEMP_9300,
    _ICON_TEMP_7500,
    _ICON_TEMP_6500,
    _ICON_TEMP_5800,
    _ICON_TEMP_SRGB,
    _ICON_TEMP_USER,

    _ICON_COLOR_EFF_STD,
    _ICON_COLOR_EFF_GAME,
    _ICON_COLOR_EFF_MOVIE,
    _ICON_COLOR_EFF_PHOTO,
    _ICON_COLOR_EFF_VIVID,
    _ICON_COLOR_EFF_USER,
#if(_SDR_TO_HDR_SUPPORT == _ON)
    _ICON_COLOR_EFF_HDR_LIKE,
    _ICON_COLOR_EFF_HDR_LIKE_PHOTO,
#endif

    _ICON_COLOR_DEMO_TYPE1,
    _ICON_COLOR_DEMO_TYPE2,
    _ICON_COLOR_DEMO_TYPE3,
    _ICON_COLOR_DEMO_TYPE4,
    _ICON_COLOR_DEMO_TYPE5,


    _ICON_COLOR_FORMAT_RGB,
    _ICON_COLOR_FORMAT_YUV,

    _ICON_TEMP_USER_R,
    _ICON_TEMP_USER_G,
    _ICON_TEMP_USER_B,

    _ICON_COLOR_PCM_SRGB,
    _ICON_COLOR_PCM_ADOBE_RGB,
    _ICON_COLOR_PCM_USER,
    _ICON_COLOR_PCM_NACTIVE,
    _ICON_COLOR_PCM_SOFT_PROFT,

    _ICON_COLOR_EFF_USER_Y,
    _ICON_COLOR_EFF_USER_C,
    _ICON_COLOR_EFF_USER_M,
    _ICON_COLOR_EFF_USER_HUE,
    _ICON_COLOR_EFF_USER_SAT,

    _ICON_NO_SUPPORT,
    _ICON_NO_SUPPORT_TEXT_0,
    _ICON_NO_SUPPORT_TEXT_1,
    _ICON_NO_CABLE,
    _ICON_NO_CABLE_TEXT_0,
    _ICON_NO_CABLE_TEXT_1,

    _ICON_NO_SIGNAL,
    _ICON_NO_SIGNAL_TEXT_0,
    _ICON_NO_SIGNAL_TEXT_1,

    _ICON_POWER_SAVING,
    _ICON_POWER_SAVING_TEXT_0,
    _ICON_POWER_SAVING_TEXT_1,
    _ICON_POWER_SAVING_TEXT_2,

    _ICON_AUTO_ADJUST_TEXT_0,
    _ICON_AUTO_ADJUST_TEXT_1,
    _ICON_AUTO_ADJUST_TEXT_2,

    _ICON_AUTO_COLOR_TEXT_0,
    _ICON_AUTO_COLOR_TEXT_1,
    _ICON_AUTO_COLOR_TEXT_2,

    _ICON_MODE1,
    _ICON_MODE2,


    _ICON_0_DEGREE,
    _ICON_90_DEGREE,
    _ICON_180_DEGREE,
    _ICON_270_DEGREE,
    _ICON_LR_MIRROR,
    _ICON_UD_MIRROR,

    _ICON_DP_1080P,
    _ICON_DP_2560_1440,
    _ICON_DP_4K2K_30HZ,
    _ICON_DP_4K2K_60HZ,


    _ICON_TRUN_OFF_PANEL_UNI_TEXT0,
    _ICON_TRUN_OFF_PANEL_UNI_TEXT1,

    _ICON_YES,
    _ICON_NO,

    _ICON_ONOFF,
    _ICON_OD_GAIN,


    _ICON_D0,
    _ICON_D1,
    _ICON_D2,
    _ICON_D6,
    _ICON_1_DOT_1,
    _ICON_1_DOT_2,
    _ICON_1_DOT_3,
    _ICON_2_LANE,
    _ICON_4_LANE,

#if(_ULTRA_HDR_SUPPORT == _ON)
    _ICON_HDR_MODE_SMPTE_ST_2084,
#endif
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    _ICON_LD_SMOOTHADJ,
#endif

    _ICON_FREEZE_DISABLE_TEXT_0,
    _ICON_FREEZE_DISABLE_TEXT_1,
    _ICON_FREEZE_DISABLE_TEXT_2,
#if(_DP_MST_SUPPORT == _ON)
    _ICON_MST_WARNING_MSG_0,
    _ICON_MST_WARNING_MSG_1,
    _ICON_MST_WARNING_MSG_2,
#endif
#if(_EDID_SWITCH_BY_PORT_ITEM == _ON)
    _ICON_EDID_HDMI_1_4,
    _ICON_EDID_HDMI_2_0,
    _ICON_EDID_HDMI_2_0_HDR,
#endif
    _OPTION_ICON_END,
}EnumIconIndex;


typedef enum
{
    _ICON_INPUT_VGA = _OPTION_ICON_END ,
    _ICON_INPUT_DVI,
    _ICON_INPUT_HDMI,
    _ICON_INPUT_DP,
    _ICON_INPUT_MHL,
    _ICON_INPUT_NO_PORT,

    _ICON_INPUT_END,

}EnumIconPort;

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
}EnumIconPortIndex;




typedef enum
{
    _OPTION_NORMAL,
    _OPTION_OVERSCAN_ONOFF,
    _OPTION_OVERDRIVE_ONOFF,
    _OPTION_DCR_ONOFF,
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
    _OPTION_LATENCY_TYPE,
    _OPTION_DP_EDID_TYPE,

    _OPTION_CLONE_TYPE,
    _OPTION_FREESYNC_ONOFF_TYPE,

    _OPTION_DP_LANE_COUNT_SELECT,
#if(_ULTRA_HDR_SUPPORT == _ON)
    _OPTION_HDR_MODE_SELECT,
#endif
    _OPTION_ON_OFF,
#if(_LOCAL_DIMMING_SUPPORT == _ON)
    _OPTION_LOCAL_DIMMING_TYPE,
#endif
}EnumOptionIndex;


typedef enum
{
    _FONT1_GLOBAL,
   _FONT2_ICON,
    _REALTEK_1BIT_LOGO0,
    _REALTEK_1BIT_LOGO1,
 _OSDTIMER_ICON,

    	_FOUR_CORNER,
	_MAIN_MENU_2BIT_ICON,
	_LEFT_MENU_AIM_ICON,
	_LEFT_MENU_TIME_ICON,
	_LEFT_MENU_NUMBER_ICON,
}EnumFont;


typedef enum
{
    _PALETTE_RTD_LOGO,
    _PALETTE_MAIN_MENU,
}EnumPalette;

typedef enum
{
    _ENGLISH = 0,
        _SPANISH,
    _FRENCH,
    _GERMAN,
         _ITALIANO,
        _KOREAN,     
    _CHINESE_S,

    _LANGUAGE_AMOUNT =_CHINESE_S,
}EnumOSDLanguageDef;

typedef enum
{
    _OSDEVENT_NONE_MSG = 0,
    _OSDEVENT_SHOW_NOSIGNAL_MSG,
    _OSDEVENT_SHOW_NOCABLE_MSG,
    _OSDEVENT_SHOW_NOSUPPORT_MSG,
    _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG,
    _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG,
    _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG,
    _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG,
    _OSDEVENT_DO_AUTO_CONFIG_MSG,
    _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG,
    _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG,
    _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG,
    _OSDEVENT_SAVE_NVRAM_BRICON_MSG,
    _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG,
    _OSDEVENT_DP_VERSIOM_MSG,
    _OSDEVENT_BUININ_MSG,
}EnumOSDEvenMassage;

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
    _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG,
#if(_FREEZE_SUPPORT == _ON)
    _OSD_DISP_DISABLE_FREEZE_MSG,
#endif
#if(_DP_MST_SUPPORT == _ON)
    _OSD_DISP_MST_WARNING_MSG,
#endif
} EnumOSDDispMsg;

typedef enum
{
    _ICON_POS_UP_0,
    _ICON_POS_UP_1,
    _ICON_POS_UP_2,
    _ICON_POS_UP_3,
    _ICON_POS_DOWN_0,
    _ICON_POS_DOWN_1,
    _ICON_POS_DOWN_2,
    _ICON_POS_DOWN_3,
}EnumOSDMainMenuIcon;

typedef enum
{

    _STRING_SELECT,

    _STRING_PICTURE,
    _STRING_COLOR,
    _OSD_SETTING,
    _SET_UP,
    _STRING_OTHER,





    // picture
    _STRING_BRIGHTNESS,
    _STRING_CONTRAST,
    _ECO,
    _MAIN_SR,
    _STRING_HDR,
_STRING_HDR_AUTO,
_STRING_HDR_2048,

    _STRING_STANDARD,
    _STRING_MOVE,
    _STRING_PHOTO,
    _STRING_GAME,
    _STRING_FPS,
    _STRING_RTS,
    _STRING_USER,
    
    _STRING_OFF,
    _STRING_WEAK,
    _STRING_MEDIAN,
    _STRING_STRONG,
    _STRING_STRONGEST,



    
    // color
    _STRING_COLOR_TEMP,
    _STRING_R,
    _STRING_G,
    _STRING_B,

       //OSD SETTING
    _STRING_LANGUAGE,
    _STRING_OSD_HPOS,
    _STRING_OSD_VPOS,
    _STRING_TRANSPARENCY,
    _STRING_OSD_TIMEOUT,

      
    _STRING_HDMI,
      _STRING_HDMI1,
    _STRING_HDMI2,
    _STRING_HDMI3,
    _STRING_HDMI4,
      _STRING_DP,
      _STRING_DVI,

	_STRING_A0,
	_STRING_D0,
	_STRING_D1,
	_STRING_D2,
	_STRING_D3,
	_STRING_D4,



      _STRING_ON,
		_STRING_FLICKER,

      
      _STRING_FULL_SCREEN,
      _STRING_16_9,
      _STRING_4_3,
      _STRING_5_4,
      _STRING_ORIGIN,
      


      _STRING_AUTO,

    

//SETUP
    _STRING_INPUT,
      _STRING_MUTE,
    _STRING_VOLUME,
    _STRING_RESET,

 //OTHERS

    _STRING_RATIO,
    _STRING_LOW_BLUE,
    _STRING_OD,
    _STRING_FREESYNC,



 
    _STRING_6500K,
    _STRING_9300K,
    _STRING_USER_DEFINE,
_STRING_7500K,
//////////////LUO
	_STRING_GAME_MENU,
	_STRING_GAME_TIME,
	_STRING_GAME_CURSOR,
	_STRING_GAME_TIMER_POSITION,

	_STRING_LEFT_MENU_AIM,
	_STRING_LEFT_MENU_TIMER,

_STRING_INPUT_SELECT,
//_STRING_FLICKER_FREE_SELECT,
























    _STRING_DP_OPTION,
    _STRING_DP_MST,
    _STRING_DP_EDID,
    _STRING_CLONE,
    

    _STRING_AUTO_SELECT,



    // other


    // Show OSD Number
    _STRING_SHOW_NUMBER,

    // information
    _STRING_HFREQPCLK,
    _STRING_VFREQUENCY,
    _STRING_VGA_USER_MODE,
    _STRING_VGA_PRESET_MODE,
    _STRING_HDCP_MODE,

    // Adjust message
    _STRING_PLEASE_WAIT,
    _STRING_NO_SIGNAL,
    _STRING_NO_CABLE,
    _STRING_NO_SUPPORT,
    _STRING_AUTO_COLOR,
    _STRING_GO_TO_POWER_SAVING_MODE,
    _STRING_NOW_RESOLUTION,

    _STRING_PASS,
    _STRING_FAIL,
    _STRING_FREESYNC_SUPPORT_V_RANGE,

#if(_DP_DEBUG_MSG == _ON)
    _STRING_DP_INFO,
    _STRING_DP_INFO_2,
#endif

    _STRIN_END,
}EnumStringIndex;
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
}EnumStringPort;

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
}EnumPortInx;

typedef enum
{
    _OSD_ROTATE_DISPLAY_FULL = 0,
    _OSD_ROTATE_DISPLAY_PIXEL_BY_PIXEL,
    _OSD_ROTATE_DISPLAY_KEEP_SRC_ASPECT_RATIO,
}EnumOsdRotationDisplaySizeDef;

typedef enum
{
    _AUTO_CONFIG_DO = 0,
    _AUTO_CONFIG_RESULT,
}EnumautoConfig;


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
// __RTD_DDCCI__
extern bit g_bForcePowSavStatus;


// __RTD_OSD__
extern StructOsdInfo g_stOsdInfo;
extern WORD g_usAdjustValue;
extern WORD g_usBackupValue;
extern BYTE g_ucLogoTimerCounter;

// __RTD_OSDFUNC__
extern WORD g_usFontSelectStart;
extern WORD g_usFontTableStart;
extern BYTE g_ucOsdWidth;
extern BYTE g_ucOsdHeight;
extern BYTE g_ucOsdWidthB;
extern BYTE g_ucOsdHeightB;
extern BYTE g_ucFontPointer0;
extern BYTE g_ucFontPointer1;
extern BYTE g_ucFontPointer2;
extern BYTE g_ucFontPointer3;
extern BYTE g_ucSubMask[5];
//----------------------------------------------------------------------------------------
// Extern Tables from OsdFont.c
//----------------------------------------------------------------------------------------
// __RTD_OSDFONTVLC__
extern BYTE code tICON_REALTEK_1BIT_LOGO0[];
extern BYTE code tICON_REALTEK_1BIT_LOGO1[];

//----------------------------------------------------------------------------------------
// Extern Tables from OsdTable.c
//----------------------------------------------------------------------------------------
// __RTD_OSDFONTTABLE__


extern BYTE code tOSD_ICON1[];
extern BYTE code tOSD_ICON2[];
extern BYTE code tOSD_ICON3[];
extern BYTE code tOSD_ICON4[];
extern BYTE code tOSD_ICON5[];
extern BYTE code tOSD_LINE[];
extern BYTE code tOSD_LINE1[];
 extern BYTE code tOSD_LINE_LEFT[];
 extern BYTE code tOSD_LINE_RIGHT[];
 extern BYTE code tOSD_LINE_DOWN[];
 extern BYTE code tOSD_LINE1_DOWN[];
 extern BYTE code tOSD_LINE1_UP[];
 extern BYTE code tOSD_BIAN_UP[];
 extern BYTE code tOSD_BIAN_DOWN[];
 extern BYTE code tOSD_LINE_LEFT1[];
 extern BYTE code tOSD_LINE_RIGHT1[];
 extern BYTE code tOSD_PIXIO[];
  extern BYTE code tOSD_PIXIO_2BIT[];


 extern BYTE code tOSD_QUAN_LEFT[];
 extern BYTE code tOSD_DIAN_LEFT[];
 extern BYTE code tOSD_DIAN_RIGHT[];
 extern BYTE code tOSD_QUAN_RIGHT[];


 extern BYTE code tOSD_LINE2_UP[];
 extern BYTE code tOSD_LINE2_DOWN[];
 extern BYTE code tOSD_LINE_ICON[];
 extern BYTE code tOSD_LINE_ICON_UP[];
 extern BYTE code tOSD_LINE_ICON1[];
  extern BYTE code tWANGZHI[];


 extern BYTE code tOSD_FREESYNC[];

extern BYTE code tOSD_iREALTEK[];
extern BYTE code tOSD_iKEY_BACK[];
extern BYTE code tOSD_iKEY_LEFT[];
extern BYTE code tOSD_iKEY_RIGHT[];
extern BYTE code tOSD_iKEY_ENTER[];
extern BYTE code tOSD_iKEY_EXIT[];

extern BYTE code tiOSD_REALTEK_1BIT_LOGO0[];
extern BYTE code tiOSD_REALTEK_1BIT_LOGO1[];


// __RTD_OSDFONTPROP__
// main menu


extern BYTE code tSTRING_SELECT[];
extern BYTE code tSTRING_YUYAN[][6];

extern BYTE code tSTRING_PICTURE[];
extern BYTE code tSTRING_DISPLAY[];
extern BYTE code tSTRING_COLOR[];
extern BYTE code tSTRING_ADVANCE[];
extern BYTE code tSTRING_INPUT[];
extern BYTE code tSTRING_AUDIO[];
extern BYTE code tSTRING_OTHER[];
extern BYTE code tSTRING_INFORMATION[];
extern BYTE code tSTRING_FACTORY[];


extern BYTE code _tSTRING_GAME_MENU[];
extern BYTE code _tSTRING_GAME_TIME[];
extern BYTE code _tSTRING_GAME_CURSOR[];
extern BYTE code _tSTRING_GAME_TIMER_POSITION[];


  
extern BYTE code tSET_UP[];
extern BYTE code tOSD_SETTING[];
// picture
extern BYTE code tSTRING_BRIGHTNESS[];
extern BYTE code tSTRING_CONTRAST[];
extern BYTE code tECO[];
 extern BYTE code tMAIN_SR[];

extern BYTE code tSTRING_BACKLIGHT[];
extern BYTE code tSTRING_SHARPNESS[];
extern BYTE code tSTRING_STANDARD[];
extern BYTE code tSTRING_MOVE[];
extern BYTE code tSTRING_PHOTO[];
extern BYTE code tSTRING_GAME[];
extern BYTE code tSTRING_FPS[];
extern BYTE code tSTRING_RTS[];
extern BYTE code tMAIN_USER[];
extern void Heng(void);


extern BYTE code tSTRING_OFF[];
extern BYTE code tSTRING_WEAK[];
extern BYTE code tSTRING_MEDIAN[];
extern BYTE code tSTRING_STRONG[];
extern BYTE code tMAIN_STRONGEST[];





// display
extern BYTE code tSTRING_AUTO_ADJUST[];
extern BYTE code tSTRING_HPOS[];
extern BYTE code tSTRING_VPOS[];
extern BYTE code tSTRING_CLOCK[];
extern BYTE code tSTRING_PHASE[];
extern BYTE code tSTRING_DISP_ROTATE[];

// color

extern BYTE code tSTRING_COLOR_TEMP[];
extern BYTE code tSTRING_USER_DEFINE[];
extern BYTE code tSTRING_R[];
extern BYTE code tSTRING_G[];
extern BYTE code tSTRING_B[];
extern BYTE code tSTRING_6500K[];
extern BYTE code tSTRING_9300K[];
extern BYTE code tSTRING_7500K[];



extern BYTE code tSTRING_PANEL_UNIFORMITY[];
extern BYTE code tSTRING_GAMMA[];
extern BYTE code tSTRING_COLOR_EFFECT[];
extern BYTE code tSTRING_DEMO[];
extern BYTE code tSTRING_COLOR_FORMAT[];
extern BYTE code tSTRING_PCM[];
extern BYTE code tSTRING_HUE[];
extern BYTE code tSTRING_SATURATION[];



// advance
extern BYTE code tSTRING_ASPECT_RATIO[];
extern BYTE code tSTRING_OVER_SCAN[];
extern BYTE code tSTRING_OVER_DRIVE[];
extern BYTE code tSTRING_DCR[];
extern BYTE code tSTRING_DDCCI[];
extern BYTE code tSTRING_ULTRA_VIVID[];
extern BYTE code tSTRING_DP_OPTION[];
extern BYTE code tSTRING_DP_MST[];
extern BYTE code tSTRING_DP_EDID[];
extern BYTE code tSTRING_CLONE[];
extern BYTE code tSTRING_CLONE[];
extern BYTE code tSTRING_FREESYNC[];
extern BYTE code tSTRING_LATENCY[];

extern BYTE code tSTRING_OD[];
extern BYTE code tSTRING_LOW_BLUE[];
extern BYTE code tSTRING_RATIO[];




// input
extern BYTE code tSTRING_AUTO_SELECT[];

// audio
extern BYTE code tSTRING_VOLUME[];
extern BYTE code tSTRING_MUTE[];
extern BYTE code tSTRING_STAND_ALONG[];
extern BYTE code tSTRING_AUDIO_SOURCE[];
extern BYTE code tSTRING_SOUND_MODE[];

// other
extern BYTE code tSTRING_RESET[];
extern BYTE code tSTRING_MENU_TIME[];
extern BYTE code tSTRING_OSD_HPOS[];
extern BYTE code tSTRING_OSD_VPOS[];
extern BYTE code tSTRING_LANGUAGE[];
extern BYTE code tSTRING_TRANSPARENCY[];
extern BYTE code tSTRING_ROTATE[];
//extern code BYTE *tSTRING_MENU_TABLE[];
extern BYTE code tSTRING_TIME_OUT[];



extern BYTE code tSTRING_HDMI[];
extern BYTE code tSTRING_HDMI1[];
extern BYTE code tSTRING_HDMI2[];
extern BYTE code tSTRING_HDMI3[];
extern BYTE code tSTRING_HDMI4[];
extern BYTE code tSTRING_DP[];

extern BYTE code tSTRING_DVI[];
extern BYTE code tSTRING_ON[];
extern BYTE code tSTRING_FULL_SCREEN[];
extern BYTE code tSTRING_AUTO[];
extern BYTE code tSTRING_4_3[];
extern BYTE code tSTRING_16_9[];
extern BYTE code tSTRING_5_4[];
extern BYTE code tSTRING_ORIGIN[];
extern BYTE code tSTRING_FLICKER[];



//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
//----------------------------------------------------------------------------------------
// Extern functions from UserDdcci.c
//----------------------------------------------------------------------------------------
// __RTD_DDCCI__
extern void UserDdcciHandler(void);

//----------------------------------------------------------------------------------------
// Extern functions from RTDKey.c
//----------------------------------------------------------------------------------------
// __RTD_KEY__
extern void RTDKeyInitial(void);

//----------------------------------------------------------------------------------------
// Extern functions from Osd.c
//----------------------------------------------------------------------------------------
// __RTD_OSD__


//----------------------------------------------------------------------------------------
// Extern functions from OsdFunc.c
//----------------------------------------------------------------------------------------
// __RTD_OSDFUNC__
extern void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void OsdFuncSetPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY);
extern void OsdFuncTransparency(BYTE ucTrans);
extern void OsdFuncBlending(BYTE ucType);

extern void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex);
extern void OsdFuncDisableOsd(void);
extern void OsdFuncEnableOsd(void);
extern void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth ,BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom);
extern void OsdFuncSet2BitIconOffset(BYTE ucOffset);
extern void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth ,BYTE ucHeight);

#if(_ULTRA_HDR_SUPPORT == _ON)

extern void OsdFuncColorFormatAdjust(void);
extern void OsdFuncColorPcmAdjust(void);
#endif
extern void OsdFuncSetOsdItemFlag(void);

#if(_FREEZE_SUPPORT == _ON)
extern bit OsdFuncCheckFreezeDisable(void);
#endif


extern void RTDOsdFuncChangeColor2Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);

//----------------------------------------------------------------------------------------
// Extern functions from OsdDisplay.c
//----------------------------------------------------------------------------------------
// __RTD_OSDDISPLAY__
extern BYTE OsdDispJudgeSourceType(void);

extern void OsdDispDisableOsd(void);
extern void OsdDispSetPosition(BYTE ucType,EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos);


extern void OsdDispMainMenu(void);

extern void OsdDispSliderAndNumber(WORD ucOsdState, WORD usValue);
extern WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
extern void OsdDispOsdReset(void);
extern void OsdDispHotKeyOptionMenu(BYTE ucOption);
extern void OsdDispOsdMessage(EnumOSDDispMsg enumMessage);
#if(_VGA_SUPPORT == _ON)
extern void OsdDispAutoConfigProc(void);
extern void OsdDisplayAutoBalanceProc(void);
#endif

extern void OsdDispShowLogo(void);
extern void OsdDisplaySixColorGetOneColor(BYTE ucColor);



//----------------------------------------------------------------------------------------
// Extern functions from OsdFont.c
//----------------------------------------------------------------------------------------
// __RTD_OSDFONTVLC__
extern void OsdFontVLCLoadFont1(BYTE ucState);
extern void OsdFontVLCLoadFont(BYTE ucState);

// __RTD_OSDFONTDYNAMICICON_1__
extern void OsdFontVLCDynamicLoadIcon(BYTE ucIconPos, WORD usIcon);

// __RTD_OSDFONTDYNAMICICON_2__
extern void OsdFontVLCLoadMainIcon_2(BYTE ucIconPos, WORD usIcon);

// __RTD_OSDFONTTABLE__
extern void OsdFontPut1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor);
extern void OsdFontPut1BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor);
extern void OsdFontPut1BitMainMenuIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void OsdFontPut2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void OsdFontPut2BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);

// __RTD_OSDFONTPROP__
extern void OsdPropPutString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor, BYTE ucLanguage);
extern void OsdPropPutStringCenter(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor ,BYTE ucLanguage);
extern void OsdPropShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar ,BYTE ucFontPoint, BYTE ucColor);

// __RTD_OSDPALETTE__
extern void OsdPaletteSelectPalette(BYTE ucValue);

// __RTD_OSDWINDOW__
extern void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
extern void OsdWindowDrawingByFontHighlight(BYTE ucWindow, BYTE ucRow1, BYTE ucCol1, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor);

//----------------------------------------------------------------------------------------
// Extern functions from OsdTableFunc.c
//----------------------------------------------------------------------------------------
// __RTD_OSDTABLEFUNC__ 
extern void OsdTableFuncShowNumber(BYTE ucRow, BYTE ucCol, DWORD ulValue, BYTE ucPar, BYTE ucFontPoint);
extern BYTE OsdTableFuncVideoResolution(void);
extern void OsdTableFuncPutStringProp(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, BYTE ucLanguage);
extern void OsdTableFuncPutStringCenter(BYTE ucRow, BYTE ucColStart, BYTE ucColEnd, BYTE ucFptsSelect, BYTE ucString, BYTE ucStringIndex, SBYTE chCenterOffset, BYTE ucLanguage);
extern void OsdTableFuncDrawWindow(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
extern void OsdTableFuncPutIcon1BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
extern void OsdTableFuncPutIcon2BitTable(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
extern void UpdateInterface(BYTE ucItem);
 extern void UpdateSubInterface(BYTE ucItem);
 extern void Update3thInterface(BYTE MainItem , BYTE SubItem);
extern void RTDOsdDisplaySlider(BYTE ucRow, BYTE ucCol, BYTE ucLength, WORD usValue, WORD usMax, WORD usMin, BYTE ucColor);
extern void OSDFunctionAdj(WORD ucOsdState, WORD usValue);
 extern void UpdateSubInterface2(BYTE ucItem);
 extern void UpdateSubInterface3(BYTE ucItem);
extern BYTE OsdFuncGetOsdItemFlag(void);
extern void ScalerSyncSetFREESYNCSupport(bit bEnable);
extern void OsdDispLeftMenu(void);
extern void OsdDispLeftAimMenu(void);
extern void OsdDispRightMenu(void);

extern void OsdFontPut1ChooseIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucForeground, BYTE ucBackground);
extern void OsdFontPut1FuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucLength,BYTE ucForeground, BYTE ucBackground);

extern void OsdThreeColorChooseTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType);

extern void OsdFontPut1FuncAimTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType);
extern void OsdFontPut1NumberTableForm(BYTE ucRow, BYTE ucCol, BYTE ucNumberIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucnumber);
extern void OsdFontPut1FuncTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucType);
extern void COsdShowChooseLeftMenuText(BYTE number);
extern void OsdDispLeftTimerCountDown(void);
extern void COsdShowPageInputText(void);
 extern void COsdShowPageInputString(BYTE InputOsd,BYTE InputType,BYTE NUM,BYTE MAINOSDINF);



extern BYTE g_usTimeTabe ;
extern bit g_usTime_OSD_OnOff ;
extern WORD g_usTimeUse ;
 extern bit g_usTime_OSD_OnOff1 ;
extern BYTE g_MiaoZhun ;
extern bit g_MiaoZhun_OnOff ;

 extern BYTE g_MiaoZhun1 ;
 extern bit g_MiaoZhun_OnOff1 ;
 extern BYTE g_usItemNum ;
extern BYTE Time_Flag ;
extern BYTE ucTemppp;
#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
