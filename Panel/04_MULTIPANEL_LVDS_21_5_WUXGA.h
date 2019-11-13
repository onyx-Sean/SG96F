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

#if(_PANEL_TYPE == _MULTIPANEL_LVDS_21_5_WUXGA)
//----------------------------------------------------------------------------------------------------
// ID Code      : _MULTIPANEL_LVDS_21_5_WUXGA.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//////////////////
// General Info //
//////////////////

//--------------------------------------------------
// Definitions for Panel Style
//--------------------------------------------------
#define _PANEL_STYLE                            _PANEL_LVDS

//--------------------------------------------------
// Definitions for LVDS Panel Configuration
//--------------------------------------------------
#define _LVDS_OUTPUT_PORT                       _LVDS_2_PORT
#define _LVDS_PANEL_SECTION                     _LVDS_PANEL_1_SECTION
#define _LVDS_TABLE_TYPE                        _LVDS_BIT_MAP_TABLE_1_3

//--------------------------------------------------
// Definitions for MultiPanel Support
//--------------------------------------------------
#define _PANEL_EXIST_MULTIPANEL                 _ON

//--------------------------------------------------
// Definitions for Panel Manufacturer
//--------------------------------------------------
#define _PANEL_MANUFACTURER                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_MANUFACTURER_INDEX])

//--------------------------------------------------
// Definitions for Panel Display Color Depth
//--------------------------------------------------
#define _PANEL_DISP_BIT_MODE                    (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DISP_COLOR_BIT_INDEX])

//--------------------------------------------------
// Definitions for Maximum Panel Frame Rate (Unit: 0.1 Hz)
//--------------------------------------------------
#define _PANEL_TYP_FRAME_RATE                   600
#define _PANEL_MAX_FRAME_RATE                   860
#define _PANEL_MIN_FRAME_RATE                   560


///////////////
// Parameter //
///////////////

//--------------------------------------------------
// Definitions for Panel Parameter
//--------------------------------------------------
#define _PANEL_DH_WIDTH                         (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_WIDTH_INDEX])             // Display Horizontal Width
#define _PANEL_DH_END                           (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_END_INDEX])               // Display Horizontal End Position

#define _PANEL_DH_TOTAL                         (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_INDEX])             // Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MAX                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_MAX_INDEX])         // Maxinum Display Horizontal Total Clock Number in One Display Line
#define _PANEL_DH_TOTAL_MIN                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_MIN_INDEX])         // Mininum Display Horizontal Total Clock Number in One Display Line

#define _PANEL_DV_HEIGHT                        (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_HEIGHT_INDEX])            // Display Vertical Width
#define _PANEL_DV_END                           (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_END_INDEX])               // Display Vertical End Position

#define _PANEL_DV_TOTAL                         (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_TOTAL_INDEX])             // Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MAX                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_TOTAL_MAX_INDEX])         // Maxinum Display Vertical Total Clock Number in One Display Line
#define _PANEL_DV_TOTAL_MIN                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DV_TOTAL_MIN_INDEX])         // Mininum Display Vertical Total Clock Number in One Display Line

#define _PANEL_PIXEL_CLOCK                      (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_PIXEL_CLOCK_INDEX])          // Typical Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MAX                  (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_PIXEL_CLOCK_MAX_INDEX])      // Maxinum Pixel Clock in MHz
#define _PANEL_PIXEL_CLOCK_MIN                  (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_PIXEL_CLOCK_MIN_INDEX])      // Mininum Pixel Clock in MHz

#define _PANEL_POWER_ON_T1                      (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_ON_T1_INDEX])          // Panel Power On T1 (ms)
#define _PANEL_POWER_ON_T2                      (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_ON_T2_INDEX])          // Panel Power On T2 (ms)
#define _PANEL_POWER_ON_T3                      (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_ON_T3_INDEX])          // Panel Power On T3 (ms)

#define _PANEL_POWER_OFF_T4                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_OFF_T4_INDEX])         // Panel Power Off T4 (ms)
#define _PANEL_POWER_OFF_T5                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_OFF_T5_INDEX])         // Panel Power Off T5 (ms)
#define _PANEL_POWER_OFF_T6                     (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_POWER_OFF_T6_INDEX])         // Panel Power Off T6 (ms)

#define _PANEL_DH_START                         48
#define _PANEL_DH_SYNC_WIDTH                    8

#define _PANEL_DV_START                         6
#define _PANEL_DV_SYNC_HEIGHT                   2

//--------------------------------------------------
// Definitions for Panel Amount
//--------------------------------------------------
#define _PANEL_AMOUNT                           5

//--------------------------------------------------
// Macros of MDomain Panel Index
//--------------------------------------------------
#define SET_MDOMAIN_PANEL_INDEX(x)              (g_ucDDomainPanelIndex = (x))
#define GET_MDOMAIN_PANEL_INDEX()               (g_ucDDomainPanelIndex)

//--------------------------------------------------
// Definitions of Panel data Index
//--------------------------------------------------
typedef enum
{
    _PANEL_LAST_LINE_TARGET_INDEX,
    _PANEL_MANUFACTURER_INDEX,
    _PANEL_DISP_COLOR_BIT_INDEX,
//--------------------------------
    _PANEL_DH_START_INDEX,
    _PANEL_DH_WIDTH_INDEX,
    _PANEL_DH_END_INDEX,

    _PANEL_DH_TOTAL_INDEX,
    _PANEL_DH_TOTAL_MAX_INDEX,
    _PANEL_DH_TOTAL_MIN_INDEX,

    _PANEL_DV_START_INDEX,
    _PANEL_DV_HEIGHT_INDEX,
    _PANEL_DV_END_INDEX,

    _PANEL_DV_TOTAL_INDEX,
    _PANEL_DV_TOTAL_MAX_INDEX,
    _PANEL_DV_TOTAL_MIN_INDEX,
    _PANEL_DH_SYNC_WIDTH_INDEX,
    _PANEL_DV_SYNC_HEIGHT_INDEX,

    _PANEL_PIXEL_CLOCK_INDEX,
    _PANEL_PIXEL_CLOCK_MAX_INDEX,
    _PANEL_PIXEL_CLOCK_MIN_INDEX,

    _PANEL_POWER_ON_T1_INDEX,
    _PANEL_POWER_ON_T2_INDEX,
    _PANEL_POWER_ON_T3_INDEX,

    _PANEL_POWER_OFF_T4_INDEX,
    _PANEL_POWER_OFF_T5_INDEX,
    _PANEL_POWER_OFF_T6_INDEX,

    _PANEL_DATA_AMOUNT,
} EnumMultiPanelIndex;

#ifdef __SCALER_DDOMAIN__

//--------------------------------------------------
// Panel Data Table
//--------------------------------------------------
WORD code tPanelData[_PANEL_AMOUNT][_PANEL_DATA_AMOUNT] =
{
    {
        150,        // _LAST_LINE_TARGET
        _PANEL_AUO, // _PANEL_MANUFACTURER
        _PANEL_DISP_24_BIT, // _PANEL_DISP_COLOR_BIT
//--------------------------------------------------
        48,         // _PANEL_DH_START
        3440,       // _PANEL_DH_WIDTH
        3488,       // _PANEL_DH_END

        4580,       // _PANEL_DH_TOTAL
        4912,       // _PANEL_DH_TOTAL_MAX
        4576,       // _PANEL_DH_TOTAL_MIN

        6,          // _PANEL_DV_START
        1440,       // _PANEL_DV_HEIGHT
        1446,       // _PANEL_DV_END

        1472,       // _PANEL_DV_TOTAL
        1474,       // _PANEL_DV_TOTAL_MAX
        1470,       // _PANEL_DV_TOTAL_MIN
        8,          // _PANEL_DH_SYNC_WIDTH
        2,          // _PANEL_DV_SYNC_HEIGHT

        430,        // _PANEL_PIXEL_CLOCK
        580,        // _PANEL_PIXEL_CLOCK_MAX
        200,        // _PANEL_PIXEL_CLOCK_MIN

        100,        // _PANEL_POWER_ON_T1
        50,         // _PANEL_POWER_ON_T2
        230,        // _PANEL_POWER_ON_T3

        230,         // _PANEL_POWER_OFF_T4
        20,         // _PANEL_POWER_OFF_T5
        1200,        // _PANEL_POWER_OFF_T6
    },

    {
        150,        // _LAST_LINE_TARGET
        _PANEL_AUO, // _PANEL_MANUFACTURER
        _PANEL_DISP_24_BIT, // _PANEL_DISP_COLOR_BIT
//--------------------------------------------------
        48,         // _PANEL_DH_START
        1920,       // _PANEL_DH_WIDTH
        1968,       // _PANEL_DH_END

        2100,       // _PANEL_DH_TOTAL
        2200,       // _PANEL_DH_TOTAL_MAX
        2048,       // _PANEL_DH_TOTAL_MIN

        6,          // _PANEL_DV_START
        1080,       // _PANEL_DV_HEIGHT
        1086,       // _PANEL_DV_END

        1150,       // _PANEL_DV_TOTAL
        1600,       // _PANEL_DV_TOTAL_MAX
        1100,       // _PANEL_DV_TOTAL_MIN
        8,          // _PANEL_DH_SYNC_WIDTH
        2,          // _PANEL_DV_SYNC_HEIGHT

        144,        // _PANEL_PIXEL_CLOCK
        700,        // _PANEL_PIXEL_CLOCK_MAX
        70,        // _PANEL_PIXEL_CLOCK_MIN

        100,        // _PANEL_POWER_ON_T1
        40,         // _PANEL_POWER_ON_T2
        300,        // _PANEL_POWER_ON_T3

        20,         // _PANEL_POWER_OFF_T4
        40,         // _PANEL_POWER_OFF_T5
        600,        // _PANEL_POWER_OFF_T6
    },

    {// QHD
        2495,        // _LAST_LINE_TARGET
        _PANEL_LGD, // _PANEL_MANUFACTURER
        _PANEL_DISP_24_BIT,
//--------------------------------------------------
        48,         // _PANEL_DH_START
        2560,       // _PANEL_DH_WIDTH
        2608,       // _PANEL_DH_END

        2720,       // _PANEL_DH_TOTAL
        2736,       // _PANEL_DH_TOTAL_MAX
        2704,       // _PANEL_DH_TOTAL_MIN

        6,          // _PANEL_DV_START
        1440,       // _PANEL_DV_HEIGHT
        1446,       // _PANEL_DV_END

        1481,       // _PANEL_DV_TOTAL
        1483,       // _PANEL_DV_TOTAL_MAX
        1479,       // _PANEL_DV_TOTAL_MIN
        8,          // _PANEL_DH_SYNC_WIDTH
        2,          // _PANEL_DV_SYNC_HEIGHT

        241,        // _PANEL_PIXEL_CLOCK
        302,        // _PANEL_PIXEL_CLOCK_MAX
        110,        // _PANEL_PIXEL_CLOCK_MIN

        10,        // _PANEL_POWER_ON_T1
        50,         // _PANEL_POWER_ON_T2
        250,        // _PANEL_POWER_ON_T3

        50,         // _PANEL_POWER_OFF_T4
        10,         // _PANEL_POWER_OFF_T5
        300,        // _PANEL_POWER_OFF_T6
    },

    {// UHD
        3656,        // _LAST_LINE_TARGET
        _PANEL_SAMSUNG, // _PANEL_MANUFACTURER
        _PANEL_DISP_24_BIT,
//--------------------------------------------------
        48,         // _PANEL_DH_START
        3840,       // _PANEL_DH_WIDTH
        3888,       // _PANEL_DH_END

        3956,       // _PANEL_DH_TOTAL
        4020,       // _PANEL_DH_TOTAL_MAX
        3892,       // _PANEL_DH_TOTAL_MIN

        6,          // _PANEL_DV_START
        2160,       // _PANEL_DV_HEIGHT
        2166,       // _PANEL_DV_END

        2190,       // _PANEL_DV_TOTAL
        2210,       // _PANEL_DV_TOTAL_MAX
        2170,       // _PANEL_DV_TOTAL_MIN
        8,          // _PANEL_DH_SYNC_WIDTH
        2,          // _PANEL_DV_SYNC_HEIGHT

        520,        // _PANEL_PIXEL_CLOCK
        700,        // _PANEL_PIXEL_CLOCK_MAX
        250,        // _PANEL_PIXEL_CLOCK_MIN

        10,        // _PANEL_POWER_ON_T1
        100,         // _PANEL_POWER_ON_T2
        50,        // _PANEL_POWER_ON_T3

        50,         // _PANEL_POWER_OFF_T4
        10,         // _PANEL_POWER_OFF_T5
        300,        // _PANEL_POWER_OFF_T6
    },

    {// qhd_modified
        150,        // _LAST_LINE_TARGET
        _PANEL_SAMSUNG, // _PANEL_MANUFACTURER
        _PANEL_DISP_24_BIT,
//--------------------------------------------------
        48,         // _PANEL_DH_START
        2560,       // _PANEL_DH_WIDTH
        2608,       // _PANEL_DH_END

        2720,       // _PANEL_DH_TOTAL
        2736,       // _PANEL_DH_TOTAL_MAX
        2704,       // _PANEL_DH_TOTAL_MIN

        6,          // _PANEL_DV_START
        1080,       // _PANEL_DV_HEIGHT
        1086,       // _PANEL_DV_END

        1150,       // _PANEL_DV_TOTAL
        1600,       // _PANEL_DV_TOTAL_MAX
        1100,       // _PANEL_DV_TOTAL_MIN
        8,          // _PANEL_DH_SYNC_WIDTH
        2,          // _PANEL_DV_SYNC_HEIGHT

        520,        // _PANEL_PIXEL_CLOCK
        533,        // _PANEL_PIXEL_CLOCK_MAX
        150,        // _PANEL_PIXEL_CLOCK_MIN

        10,        // _PANEL_POWER_ON_T1
        100,         // _PANEL_POWER_ON_T2
        50,        // _PANEL_POWER_ON_T3

        50,         // _PANEL_POWER_OFF_T4
        10,         // _PANEL_POWER_OFF_T5
        300,        // _PANEL_POWER_OFF_T6
    },
};

#endif

#ifndef __SCALER_DDOMAIN__

//--------------------------------------------------
// Panel Data Table Extern
//--------------------------------------------------
extern WORD code tPanelData[_PANEL_AMOUNT][_PANEL_DATA_AMOUNT];

#endif


/////////////
// Display //
/////////////

//--------------------------------------------------
// Set Last Line Finetune Target
//--------------------------------------------------
#define _LAST_LINE_TARGET                       ((tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_DH_TOTAL_INDEX]) - (tPanelData[GET_MDOMAIN_PANEL_INDEX()][_PANEL_LAST_LINE_TARGET_INDEX])) // (_PANEL_DH_TOTAL - 150)

//--------------------------------------------------
// Definitions for Frame Sync Margin (Unit: 0.1Hz)
//--------------------------------------------------
#define _FRAME_SYNC_MARGIN                      20

//--------------------------------------------------
// Definitions for Panel DCLK Unit
//--------------------------------------------------
#define _PANEL_PIXEL_CLOCK_UNIT                 _PANEL_CLOCK_MHZ


////////////////////
// VGA Auto Color //
////////////////////

//--------------------------------------------------
// Definitions for ADC Gain/Offset Adjust
//--------------------------------------------------
#define _PANEL_ADC_OFFSET_BIAS                  (0)
#define _PANEL_ADC_GAIN_BIAS                    (0)


///////////////////////////
// Color Characteristics //
///////////////////////////



/////////////////////////
// Color Default Table //
/////////////////////////

//--------------------------------------------------
// Color Default Value
//--------------------------------------------------
#include "./RTDColorDefaultTable/ColorTableInclude.h"

#endif // End of #if(_PANEL_TYPE == _MULTIPANEL_LVDS_21_5_WUXGA)
