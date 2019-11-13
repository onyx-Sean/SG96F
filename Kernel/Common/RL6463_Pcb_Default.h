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
// ID Code      : RL6463_Pcb_Default.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------


///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// FW Support Xtal-less
//--------------------------------------------------
#ifndef _XTALESS_SUPPORT
#define _XTALESS_SUPPORT                        _OFF
#endif

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#ifndef _EXT_XTAL
#define _EXT_XTAL                               _XTAL14318K
#endif


///////////////
// Debug DDC //
///////////////

//--------------------------------------------------
// Debug DDC Channel
//--------------------------------------------------
#ifndef _PCB_DEBUG_DDC
#define _PCB_DEBUG_DDC                          _VGA_DDC
#endif


///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
#ifndef _A0_INPUT_PORT_TYPE
#define _A0_INPUT_PORT_TYPE                     _A0_NO_PORT
#endif

#ifndef _A0_EMBEDDED_DDCRAM_SIZE
#define _A0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#endif

#ifndef _A0_EMBEDDED_DDCRAM_LOCATION
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _A0_PC99_EMBEDDED_EDID_TABLE
#define _A0_PC99_EMBEDDED_EDID_TABLE            "./EDID/EdidTableDummy128.h"
#endif

//--------------------------------------------------
// D0 Input Port
//--------------------------------------------------
#ifndef _D0_INPUT_PORT_TYPE
#define _D0_INPUT_PORT_TYPE                     _D0_NO_PORT
#endif

#ifndef _D0_DDC_CHANNEL_SEL
#define _D0_DDC_CHANNEL_SEL                     _NO_DDC
#endif

#ifndef _D0_EMBEDDED_DDCRAM_SIZE
#define _D0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#endif

#ifndef _D0_EMBEDDED_DDCRAM_LOCATION
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _D0_PC99_EMBEDDED_EDID_TABLE
#define _D0_PC99_EMBEDDED_EDID_TABLE            "./EDID/EdidTableDummy256.h"
#endif

#ifndef _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0
#define _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_NOT_EXIST
#endif

#ifndef _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1
#define _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_NOT_EXIST
#endif

#ifndef _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2
#define _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST
#endif

#ifndef _D0_DP_CONNECTOR_TYPE
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#endif

#ifndef _D0_DP_LINK_CLK_RATE
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#endif

#ifndef _D0_DP_MAIN_LINK_LANES
#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE
#endif

#ifndef _D0_DP_TYPE_C_PORT_CTRL_TYPE
#define _D0_DP_TYPE_C_PORT_CTRL_TYPE            _PORT_CONTOLLER_NONE
#endif

#ifndef _D0_DP_TYPE_C_USB_HUB_TYPE
#define _D0_DP_TYPE_C_USB_HUB_TYPE              _USB_HUB_NONE
#endif

#ifndef _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR
#define _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#endif

#ifndef _D0_DP_TYPE_C_HUB_SLAVE_ADDR
#define _D0_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#endif

#ifndef _D0_DP_TYPE_C_SMBUS_IIC
#define _D0_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN
#endif

//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#ifndef _D1_INPUT_PORT_TYPE
#define _D1_INPUT_PORT_TYPE                     _D1_NO_PORT
#endif

#ifndef _D1_DDC_CHANNEL_SEL
#define _D1_DDC_CHANNEL_SEL                     _NO_DDC
#endif

#ifndef _D1_EMBEDDED_DDCRAM_SIZE
#define _D1_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#endif

#ifndef _D1_EMBEDDED_DDCRAM_LOCATION
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#endif

#ifndef _D1_PC99_EMBEDDED_EDID_TABLE
#define _D1_PC99_EMBEDDED_EDID_TABLE            "./EDID/EdidTableDummy256.h"
#endif

#ifndef _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0
#define _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_NOT_EXIST
#endif

#ifndef _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1
#define _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_NOT_EXIST
#endif

#ifndef _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2
#define _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST
#endif

#ifndef _D1_DP_CONNECTOR_TYPE
#define _D1_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#endif

#ifndef _D1_DP_LINK_CLK_RATE
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#endif

#ifndef _D1_DP_MAIN_LINK_LANES
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE
#endif

#ifndef _D1_DP_TYPE_C_PORT_CTRL_TYPE
#define _D1_DP_TYPE_C_PORT_CTRL_TYPE            _PORT_CONTOLLER_NONE
#endif

#ifndef _D1_DP_TYPE_C_USB_HUB_TYPE
#define _D1_DP_TYPE_C_USB_HUB_TYPE              _USB_HUB_NONE
#endif

#ifndef _D1_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR
#define _D1_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#endif

#ifndef _D1_DP_TYPE_C_HUB_SLAVE_ADDR
#define _D1_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#endif

#ifndef _D1_DP_TYPE_C_SMBUS_IIC
#define _D1_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN
#endif


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#ifndef _A0_INPUT_PORT_GROUP
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

#ifndef _D0_INPUT_PORT_GROUP
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

#ifndef _D1_INPUT_PORT_GROUP
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#endif

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#ifndef _INPUT_PORT_SEARCH_PRI_0
#define _INPUT_PORT_SEARCH_PRI_0                _NO_INPUT_PORT
#endif

#ifndef _INPUT_PORT_SEARCH_PRI_1
#define _INPUT_PORT_SEARCH_PRI_1                _NO_INPUT_PORT
#endif

#ifndef _INPUT_PORT_SEARCH_PRI_2
#define _INPUT_PORT_SEARCH_PRI_2                _NO_INPUT_PORT
#endif


//////////////
// VGA Port //
//////////////

//--------------------------------------------------
// Analog Signal Swap Options
//--------------------------------------------------
#ifndef _VGA_INPUT_SWAP_RG
#define _VGA_INPUT_SWAP_RG                      _OFF
#endif

#ifndef _VGA_INPUT_SWAP_RB
#define _VGA_INPUT_SWAP_RB                      _OFF
#endif

#ifndef _VGA_INPUT_SWAP_GB
#define _VGA_INPUT_SWAP_GB                      _OFF
#endif

//--------------------------------------------------
// Analog Hsync Schmitt Trigger Control
//--------------------------------------------------
#ifndef _VGA_HS_SCHMITT_TRIGGER_POLARITY_SEL
#define _VGA_HS_SCHMITT_TRIGGER_POLARITY_SEL    _POSITIVE
#endif

#ifndef _VGA_HS_SCHMITT_TRIGGER_VTH_FINE_TUNE
#define _VGA_HS_SCHMITT_TRIGGER_VTH_FINE_TUNE   _DISABLE
#endif

#ifndef _VGA_HS_SCHMITT_TRIGGER_POSITIVE_VTH
#define _VGA_HS_SCHMITT_TRIGGER_POSITIVE_VTH    _HS_SCHMITT_TRIGGER_LEVEL_10
#endif

#ifndef _VGA_HS_SCHMITT_TRIGGER_NEGATIVE_VTH
#define _VGA_HS_SCHMITT_TRIGGER_NEGATIVE_VTH    _HS_SCHMITT_TRIGGER_LEVEL_01
#endif


///////////////
// TMDS Port //
///////////////

//--------------------------------------------------
// TMDS Signal Swap Options
//--------------------------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)

#ifndef _D0_TMDS_BR_SWAP
#define _D0_TMDS_BR_SWAP                        _ON
#endif
#ifndef _D0_TMDS_PN_SWAP
#define _D0_TMDS_PN_SWAP                        _ON
#endif

#else

#ifndef _D0_TMDS_BR_SWAP
#define _D0_TMDS_BR_SWAP                        _OFF
#endif
#ifndef _D0_TMDS_PN_SWAP
#define _D0_TMDS_PN_SWAP                        _OFF
#endif

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)

#ifndef _D1_TMDS_BR_SWAP
#define _D1_TMDS_BR_SWAP                        _ON
#endif
#ifndef _D1_TMDS_PN_SWAP
#define _D1_TMDS_PN_SWAP                        _ON
#endif

#else

#ifndef _D1_TMDS_BR_SWAP
#define _D1_TMDS_BR_SWAP                        _OFF
#endif

#ifndef _D1_TMDS_PN_SWAP
#define _D1_TMDS_PN_SWAP                        _OFF
#endif

#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)


////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Port Config
//--------------------------------------------------
#ifndef _LVDS_PORT_SEL
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_AB
#endif

#ifndef _LVDS_PORT_MIRROR
#define _LVDS_PORT_MIRROR                       _DISABLE
#endif

#ifndef _LVDS_PORT_AB_SWAP
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#endif

#ifndef _LVDS_PN_SWAP
#define _LVDS_PN_SWAP                           _DISABLE
#endif

#ifndef _LVDS_RB_SWAP
#define _LVDS_RB_SWAP                           _DISABLE
#endif

#ifndef _LVDS_ML_SWAP
#define _LVDS_ML_SWAP                           _DISABLE
#endif

#ifndef _LVDS_DVS_INVERT
#define _LVDS_DVS_INVERT                        _DISABLE
#endif

#ifndef _LVDS_DHS_INVERT
#define _LVDS_DHS_INVERT                        _DISABLE
#endif

#ifndef _LVDS_DEN_INVERT
#define _LVDS_DEN_INVERT                        _DISABLE
#endif

#ifndef _LVDS_PAIR_MIRROR
#define _LVDS_PAIR_MIRROR                       _DISABLE
#endif

//--------------------------------------------------
// LVDS Port AB Phase Selection
//--------------------------------------------------
#ifndef _LVDS_A0_PHASE
#define _LVDS_A0_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_A1_PHASE
#define _LVDS_A1_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_A2_PHASE
#define _LVDS_A2_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_AC_PHASE
#define _LVDS_AC_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_A3_PHASE
#define _LVDS_A3_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_B0_PHASE
#define _LVDS_B0_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_B1_PHASE
#define _LVDS_B1_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_B2_PHASE
#define _LVDS_B2_PHASE                          _LVDS_PI_PHASE_AB0
#endif

#ifndef _LVDS_B3_PHASE
#define _LVDS_B3_PHASE                          _LVDS_PI_PHASE_AB0
#endif

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#ifndef _LVDS_DRIV_CONTROL
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#endif

#ifndef _LVDS_VCM_CONTROL
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#endif

#ifndef _LVDS_SR_CONTROL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#endif

#ifndef _LVDS_PRE_EMPHASIS_CONTROL
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#endif

#ifndef _LVDS_TERMINATION_CONTROL
#define _LVDS_TERMINATION_CONTROL               _DISABLE
#endif

#ifndef _LVDS_VCM_USER_LEVEL
#define _LVDS_VCM_USER_LEVEL                    0x0C
#endif

//--------------------------------------------------
// LVDS SSC Config
//--------------------------------------------------
#ifndef _LVDS_SPREAD_RANGE
#define _LVDS_SPREAD_RANGE                      10
#endif

#ifndef _LVDS_SPREAD_SPEED
#define _LVDS_SPREAD_SPEED                      _SPEED_33K
#endif


/////////////
// DP Port //
/////////////

//--------------------------------------------------
// DP Lane & PN Swap Option
//--------------------------------------------------
#ifndef _D0_DP_PCB_LANE0_MAPPING
#define _D0_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#endif

#ifndef _D0_DP_PCB_LANE1_MAPPING
#define _D0_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#endif

#ifndef _D0_DP_PCB_LANE2_MAPPING
#define _D0_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#endif

#ifndef _D0_DP_PCB_LANE3_MAPPING
#define _D0_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3
#endif

#ifndef _D0_DP_PCB_LANE0_PN_SWAP
#define _D0_DP_PCB_LANE0_PN_SWAP                _OFF
#endif

#ifndef _D0_DP_PCB_LANE1_PN_SWAP
#define _D0_DP_PCB_LANE1_PN_SWAP                _OFF
#endif

#ifndef _D0_DP_PCB_LANE2_PN_SWAP
#define _D0_DP_PCB_LANE2_PN_SWAP                _OFF
#endif

#ifndef _D0_DP_PCB_LANE3_PN_SWAP
#define _D0_DP_PCB_LANE3_PN_SWAP                _OFF
#endif

#ifndef _D1_DP_PCB_LANE0_MAPPING
#define _D1_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#endif

#ifndef _D1_DP_PCB_LANE1_MAPPING
#define _D1_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#endif

#ifndef _D1_DP_PCB_LANE2_MAPPING
#define _D1_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#endif

#ifndef _D1_DP_PCB_LANE3_MAPPING
#define _D1_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3
#endif

#ifndef _D1_DP_PCB_LANE0_PN_SWAP
#define _D1_DP_PCB_LANE0_PN_SWAP                _OFF
#endif

#ifndef _D1_DP_PCB_LANE1_PN_SWAP
#define _D1_DP_PCB_LANE1_PN_SWAP                _OFF
#endif

#ifndef _D1_DP_PCB_LANE2_PN_SWAP
#define _D1_DP_PCB_LANE2_PN_SWAP                _OFF
#endif

#ifndef _D1_DP_PCB_LANE3_PN_SWAP
#define _D1_DP_PCB_LANE3_PN_SWAP                _OFF
#endif


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#ifndef _PWM_DUT_RESOLUTION
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT
#endif

#ifndef _BACKLIGHT_PWM
#define _BACKLIGHT_PWM                          _NO_PWM
#endif

#ifndef _BACKLIGHT_PWM_INVERSE
#define _BACKLIGHT_PWM_INVERSE                  _OFF
#endif

#ifndef _PWM0_EN
#define _PWM0_EN                                _OFF
#endif

#ifndef _PWM1_EN
#define _PWM1_EN                                _OFF
#endif

#ifndef _PWM2_EN
#define _PWM2_EN                                _OFF
#endif

#ifndef _PWM3_EN
#define _PWM3_EN                                _OFF
#endif

#ifndef _PWM4_EN
#define _PWM4_EN                                _OFF
#endif

#ifndef _PWM5_EN
#define _PWM5_EN                                _OFF
#endif

#ifndef _PWM0_PSAV_EN
#define _PWM0_PSAV_EN                           _OFF
#endif

#ifndef _PWM1_PSAV_EN
#define _PWM1_PSAV_EN                           _OFF
#endif

#ifndef _PWM2_PSAV_EN
#define _PWM2_PSAV_EN                           _OFF
#endif

#ifndef _PWM3_PSAV_EN
#define _PWM3_PSAV_EN                           _OFF
#endif

#ifndef _PWM4_PSAV_EN
#define _PWM4_PSAV_EN                           _OFF
#endif

#ifndef _PWM5_PSAV_EN
#define _PWM5_PSAV_EN                           _OFF
#endif

#ifndef _PWM0_PDOW_EN
#define _PWM0_PDOW_EN                           _OFF
#endif

#ifndef _PWM1_PDOW_EN
#define _PWM1_PDOW_EN                           _OFF
#endif

#ifndef _PWM2_PDOW_EN
#define _PWM2_PDOW_EN                           _OFF
#endif

#ifndef _PWM3_PDOW_EN
#define _PWM3_PDOW_EN                           _OFF
#endif

#ifndef _PWM4_PDOW_EN
#define _PWM4_PDOW_EN                           _OFF
#endif

#ifndef _PWM5_PDOW_EN
#define _PWM5_PDOW_EN                           _OFF
#endif

#ifndef _PWM0_RST_BY_DVS
#define _PWM0_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM1_RST_BY_DVS
#define _PWM1_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM2_RST_BY_DVS
#define _PWM2_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM3_RST_BY_DVS
#define _PWM3_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM4_RST_BY_DVS
#define _PWM4_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM5_RST_BY_DVS
#define _PWM5_RST_BY_DVS                        _OFF
#endif

#ifndef _PWM_RST_BY_TCON
#define _PWM_RST_BY_TCON                        _OFF
#endif


/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// Sofware and Hardware IIC Option
//--------------------------------------------------
#ifndef _SW_IIC_SUPPORT
#define _SW_IIC_SUPPORT                         _OFF
#endif

#ifndef _SW_IIC_CLK_DIV
#define _SW_IIC_CLK_DIV                         _DIV_1
#endif

#ifndef _HW_IIC_SUPPORT
#define _HW_IIC_SUPPORT                         _OFF
#endif

#ifndef _HW_IIC_SPEED
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K
#endif


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#ifndef _EEPROM_TYPE
#define _EEPROM_TYPE                            _EEPROM_24LC16
#endif

#ifndef _EEPROM_SLAVE_ADDRESS
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#endif

#ifndef _PCB_SYS_EEPROM_IIC
#define _PCB_SYS_EEPROM_IIC                     _NO_IIC_PIN
#endif


//////////
// Misc //
//////////

//--------------------------------------------------
// AD Key Option
//--------------------------------------------------
#ifndef _AD_KEY_SUPPORT
#define _AD_KEY_SUPPORT                         _OFF
#endif

//--------------------------------------------------
// Low Speed ADC Option
//--------------------------------------------------
#ifndef _LOW_SPEED_ADC_SUPPORT
#define _LOW_SPEED_ADC_SUPPORT                  _OFF
#endif


//////////////////////
// GPIO Power Macro //
//////////////////////

//-----------------------------------------------
// Macro of Pcb GPIO Inital Setting
//-----------------------------------------------
#ifndef PCB_GPIO_ON_REGION_INITIAL_SETTING
#define PCB_GPIO_ON_REGION_INITIAL_SETTING()    {\
                                                }
#endif

//-----------------------------------------------
// Power OFF Region GPIO Initial Setting
//-----------------------------------------------
#ifndef PCB_GPIO_OFF_REGION_INITIAL_SETTING
#define PCB_GPIO_OFF_REGION_INITIAL_SETTING()   {\
                                                }
#endif

#ifndef PCB_GPIO_SETTING_POWER_AC_ON
#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                }
#endif

#ifndef PCB_GPIO_SETTING_POWER_NORMAL
#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                }
#endif

#ifndef PCB_GPIO_SETTING_POWER_SAVING
#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                }
#endif

#ifndef PCB_GPIO_SETTING_POWER_DOWN
#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                }
#endif


/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of Embedded LDO Support
//-----------------------------------------------
#ifndef _EMBEDDED_LDO_OFF
#define _EMBEDDED_LDO_OFF                       0
#endif

#ifndef _EMBEDDED_LDO_ON
#define _EMBEDDED_LDO_ON                        1
#endif

#ifdef _76PIN_PIN_21
#ifndef PCB_EMBEDDED_LDO_DETECT
#define PCB_EMBEDDED_LDO_DETECT()               (_EMBEDDED_LDO_ON)
#endif
#endif

#ifndef PCB_EMBEDDED_LDO_DETECT
#define PCB_EMBEDDED_LDO_DETECT()               (_EMBEDDED_LDO_ON)
#endif

//-----------------------------------------------
// Macro of Power Board Low Power Pin High/Low
//-----------------------------------------------
#ifndef _LOW_POWER_ON
#define _LOW_POWER_ON                           1
#endif

#ifndef _LOW_POWER_OFF
#define _LOW_POWER_OFF                          0
#endif

#ifndef PCB_POWERBOARD_LOWPOWER
#define PCB_POWERBOARD_LOWPOWER(x)              {\
                                                }
#endif


////////////////////
// DP Power Macro //
////////////////////

//-----------------------------------------------
// Macro of MyDP Power Control
//-----------------------------------------------
#ifndef _MYDP_5V_POWER_ON
#define _MYDP_5V_POWER_ON                       1
#endif

#ifndef _MYDP_5V_POWER_OFF
#define _MYDP_5V_POWER_OFF                      0
#endif

#ifndef PCB_D0_MYDP_POWER
#define PCB_D0_MYDP_POWER(x)                    {\
                                                }
#endif

#ifndef PCB_D1_MYDP_POWER
#define PCB_D1_MYDP_POWER(x)                    {\
                                                }
#endif

//-----------------------------------------------
// Macro of DP1.2 Power Control
//-----------------------------------------------
#ifndef _DP12_33V_POWER_ON
#define _DP12_33V_POWER_ON                      1
#endif

#ifndef _DP12_33V_POWER_OFF
#define _DP12_33V_POWER_OFF                     0
#endif

#ifndef PCB_D0_DP12_POWER
#define PCB_D0_DP12_POWER(x)                    {\
                                                }
#endif

#ifndef PCB_D1_DP12_POWER
#define PCB_D1_DP12_POWER(x)                    {\
                                                }
#endif

//-----------------------------------------------
// Macro of MyDP & DP1.2 Power Select
//-----------------------------------------------
#ifndef _DP12_33V_POWER
#define _DP12_33V_POWER                         0
#endif

#ifndef _MYDP_5V_POWER
#define _MYDP_5V_POWER                          1
#endif

#ifndef PCB_D0_DP12_MYDP_POWER_SELECT
#define PCB_D0_DP12_MYDP_POWER_SELECT(x)        {\
                                                }
#endif

#ifndef PCB_D1_DP12_MYDP_POWER_SELECT
#define PCB_D1_DP12_MYDP_POWER_SELECT(x)        {\
                                                }
#endif


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#ifndef _PANEL_CONTROL_ON
#define _PANEL_CONTROL_ON                       0
#endif

#ifndef _PANEL_CONTROL_OFF
#define _PANEL_CONTROL_OFF                      1
#endif

#ifndef PCB_PANEL_POWER
#define PCB_PANEL_POWER(x)                      {\
                                                }
#endif

#ifndef PCB_PANEL_POWER_DETECT
#define PCB_PANEL_POWER_DETECT()                (_PANEL_CONTROL_OFF)
#endif

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#ifndef _LIGHT_CONTROL_ON
#define _LIGHT_CONTROL_ON                       0
#endif

#ifndef _LIGHT_CONTROL_OFF
#define _LIGHT_CONTROL_OFF                      1
#endif

#ifndef PCB_BACKLIGHT_POWER_PIN
#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                }
#endif

#ifndef PCB_BACKLIGHT_POWER
#define PCB_BACKLIGHT_POWER(x)                  {\
                                                }
#endif


/////////////////////////
// Write Protect Macro //
/////////////////////////

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#ifndef _FLASH_WRITE_PROTECT_ENABLE
#define _FLASH_WRITE_PROTECT_ENABLE             0
#endif

#ifndef _FLASH_WRITE_PROTECT_DISABLE
#define _FLASH_WRITE_PROTECT_DISABLE            1
#endif

#ifndef PCB_FLASH_WRITE_PROTECT
#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                }
#endif

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#ifndef _EEPROM_WP_ENABLE
#define _EEPROM_WP_ENABLE                       1
#endif

#ifndef _EEPROM_WP_DISABLE
#define _EEPROM_WP_DISABLE                      0
#endif

#ifndef PCB_EEPROM_WRITE_PROTECT
#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                }
#endif

#ifndef PCB_EEPROM_WRITE_PROTECT_DETECT
#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (_EEPROM_WP_DISABLE)
#endif

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#ifndef _EDID_EEPROM_WP_ENABLE
#define _EDID_EEPROM_WP_ENABLE                  1
#endif

#ifndef _EDID_EEPROM_WP_DISABLE
#define _EDID_EEPROM_WP_DISABLE                 0
#endif

#ifndef PCB_A0_EDID_EEPROM_WRITE_PROTECT
#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }
#endif

#ifndef PCB_D0_EDID_EEPROM_WRITE_PROTECT
#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }
#endif

#ifndef PCB_D1_EDID_EEPROM_WRITE_PROTECT
#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                }
#endif


////////////////////////
// Cable Status Macro //
////////////////////////

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------
#ifndef PCB_A0_PIN
#define PCB_A0_PIN()                            (_PCB_CABLE_DISCONNECT_LEVEL)
#endif

#ifndef PCB_D0_PIN
#define PCB_D0_PIN()                            (_PCB_CABLE_DISCONNECT_LEVEL)
#endif

#ifndef PCB_D1_PIN
#define PCB_D1_PIN()                            (_PCB_CABLE_DISCONNECT_LEVEL)
#endif

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#ifndef GET_PCB_D0_DP_SOURCE_POWER
#define GET_PCB_D0_DP_SOURCE_POWER()            (_LOW)
#endif

#ifndef GET_PCB_D1_DP_SOURCE_POWER
#define GET_PCB_D1_DP_SOURCE_POWER()            (_LOW)
#endif


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#ifndef _D0_HOT_PLUG_HIGH
#define _D0_HOT_PLUG_HIGH                       1
#endif

#ifndef _D0_HOT_PLUG_LOW
#define _D0_HOT_PLUG_LOW                        0
#endif

#ifndef _D1_HOT_PLUG_HIGH
#define _D1_HOT_PLUG_HIGH                       1
#endif

#ifndef _D1_HOT_PLUG_LOW
#define _D1_HOT_PLUG_LOW                        0
#endif

#ifndef PCB_D0_HOTPLUG
#define PCB_D0_HOTPLUG(x)                       {\
                                                }
#endif

#ifndef PCB_D1_HOTPLUG
#define PCB_D1_HOTPLUG(x)                       {\
                                                }
#endif

#ifndef PCB_D0_HOTPLUG_DETECT
#define PCB_D0_HOTPLUG_DETECT()                 (_D0_HOT_PLUG_LOW)
#endif

#ifndef PCB_D1_HOTPLUG_DETECT
#define PCB_D1_HOTPLUG_DETECT()                 (_D1_HOT_PLUG_LOW)
#endif


///////////////
// PWM Macro //
///////////////

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#ifndef PCB_PWM_SETTING
#define PCB_PWM_SETTING()                       {\
                                                }
#endif

#ifndef PCB_BACKLIGHT_PWM
#define PCB_BACKLIGHT_PWM(x)                    {\
                                                }
#endif

#ifndef PCB_GET_BACKLIGHT_PWM
#define PCB_GET_BACKLIGHT_PWM()                 (0xFF)
#endif


//////////////////
// SW IIC Macro //
//////////////////

//--------------------------------------------------
// Macro of IIC : (_SW_IIC_SUPPORT == _ON)
//--------------------------------------------------
#ifndef PCB_SW_IIC_SDA_SET
#define PCB_SW_IIC_SDA_SET()                    {\
                                                }
#endif

#ifndef PCB_SW_IIC_SDA_CLR
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                }
#endif

#ifndef PCB_SW_IIC_SDA_CHK
#define PCB_SW_IIC_SDA_CHK()                    {\
                                                }
#endif

#ifndef PCB_SW_IIC_SCL_SET
#define PCB_SW_IIC_SCL_SET()                    {\
                                                }
#endif

#ifndef PCB_SW_IIC_SCL_CLR
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                }
#endif

#ifndef PCB_SW_IIC_SCL_CHK
#define PCB_SW_IIC_SCL_CHK()                    {\
                                                }
#endif


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#ifndef _LED_ON
#define _LED_ON                                 1
#endif

#ifndef _LED_OFF
#define _LED_OFF                                0
#endif

#ifndef PCB_LED_AC_ON_INITIAL
#define PCB_LED_AC_ON_INITIAL()                 {\
                                                }
#endif

#ifndef PCB_LED_ACTIVE
#define PCB_LED_ACTIVE()                        {\
                                                }
#endif

#ifndef PCB_LED_IDLE
#define PCB_LED_IDLE()                          {\
                                                }
#endif

#ifndef PCB_LED_POWER_SAVING
#define PCB_LED_POWER_SAVING()                  {\
                                                }
#endif

#ifndef PCB_LED_ON
#define PCB_LED_ON()                            {\
                                                }
#endif

#ifndef PCB_LED_OFF
#define PCB_LED_OFF()                           {\
                                                }
#endif

#ifndef PCB_LED_TYPE1
#define PCB_LED_TYPE1()                         {\
                                                }
#endif

#ifndef PCB_LED_TYPE2
#define PCB_LED_TYPE2()                         {\
                                                }
#endif

#ifndef PCB_LED_TYPE3
#define PCB_LED_TYPE3()                         {\
                                                }
#endif

#ifndef PCB_LED_TYPE4
#define PCB_LED_TYPE4()                         {\
                                                }
#endif

#ifndef PCB_LED_TYPE5
#define PCB_LED_TYPE5()                         {\
                                                }
#endif

#ifndef PCB_LED_TYPE_FLASH
#define PCB_LED_TYPE_FLASH()                    {\
                                                }
#endif


//////////////////
// AD Key Macro //
//////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#ifndef PCB_ADKEY0
#define PCB_ADKEY0()                            (_FALSE)
#endif

#ifndef PCB_ADKEY1
#define PCB_ADKEY1()                            (_FALSE)
#endif

#ifndef PCB_ADKEY2
#define PCB_ADKEY2()                            (_FALSE)
#endif

#ifndef PCB_ADKEY3
#define PCB_ADKEY3()                            (_FALSE)
#endif

#ifndef PCB_KEY_STATE
#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                }
#endif


////////////////////
// GPIO Key Macro //
////////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#ifndef PCB_KEY_STATE
#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                }
#endif


//////////////////
// EEPROM Macro //
//////////////////

//-----------------------------------------------
// Macro of HDMI External EDID Switch
//-----------------------------------------------
#ifndef _EEPROM_EDID_ENABLE
#define _EEPROM_EDID_ENABLE                     0
#endif

#ifndef _EEPROM_EDID_DISABLE
#define _EEPROM_EDID_DISABLE                    1
#endif

#ifndef PCB_D0_EXT_EDID_0_SWITCH
#define PCB_D0_EXT_EDID_0_SWITCH(x)             {\
                                                }
#endif

#ifndef PCB_D0_EXT_EDID_1_SWITCH
#define PCB_D0_EXT_EDID_1_SWITCH(x)             {\
                                                }
#endif

#ifndef PCB_D0_EXT_EDID_2_SWITCH
#define PCB_D0_EXT_EDID_2_SWITCH(x)             {\
                                                }
#endif

#ifndef PCB_D1_EXT_EDID_0_SWITCH
#define PCB_D1_EXT_EDID_0_SWITCH(x)             {\
                                                }
#endif

#ifndef PCB_D1_EXT_EDID_1_SWITCH
#define PCB_D1_EXT_EDID_1_SWITCH(x)             {\
                                                }
#endif

#ifndef PCB_D1_EXT_EDID_2_SWITCH
#define PCB_D1_EXT_EDID_2_SWITCH(x)             {\
                                                }
#endif


/////////////////
// Audio Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Audio Connect
//-----------------------------------------------
#ifndef _AUDIO_CONNECT
#define _AUDIO_CONNECT                          0
#endif

#ifndef _AUDIO_DISCONNECT
#define _AUDIO_DISCONNECT                       1
#endif

#ifndef PCB_AUDIO_DETECT
#define PCB_AUDIO_DETECT()                      (_AUDIO_DISCONNECT)
#endif

//-----------------------------------------------
// Macro of PCB Audio AMP Control
//-----------------------------------------------
#ifndef _AMP_MUTE_ON
#define _AMP_MUTE_ON                            0
#endif

#ifndef _AMP_MUTE_OFF
#define _AMP_MUTE_OFF                           1
#endif

#ifndef PCB_AMP_MUTE
#define PCB_AMP_MUTE(x)                         {\
                                                }
#endif

//-----------------------------------------------
// Code Digital Signature ISP Channel Option
// Setting Format: (WORD)((1 << _VGA_DDC) | (1 << _DDC0) | ...)
//-----------------------------------------------
#ifndef _CODE_DIGITAL_SIGNATURE_ISP_SEL_DIS
#define _CODE_DIGITAL_SIGNATURE_ISP_SEL_DIS     (WORD)(1 << _VGA_DDC)
#endif

#ifndef _CODE_DIGITAL_SIGNATURE_ISP_SEL_EN
#define _CODE_DIGITAL_SIGNATURE_ISP_SEL_EN      (WORD)(1 << _VGA_DDC)
#endif
