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
// ID Code      : RL6432_PCB_EXAMPLE_216_PIN.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6432_PCB_EXAMPLE_216_PIN)


///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#define _EXT_XTAL                               _XTAL14318K


///////////////
// Debug DDC //
///////////////

//--------------------------------------------------
// Debug DDC Channel
//--------------------------------------------------
#define _PCB_DEBUG_DDC                          _VGA_DDC


///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
#define _A0_INPUT_PORT_TYPE                     _A0_NO_PORT
#define _A0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D0 Input Port
//--------------------------------------------------
#define _D0_INPUT_PORT_TYPE                     _D0_NO_PORT
#define _D0_DDC_CHANNEL_SEL                     _NO_DDC
#define _D0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

// For DP
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

// For DP Type-C
#define _D0_DP_TYPE_C_PORT_CTRL_TYPE            _RTS5400_SERIES
#define _D0_DP_TYPE_C_USB_HUB_TYPE              _RTS5411_SERIES
#define _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D0_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#define _D0_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN

//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_NO_PORT
#define _D1_DDC_CHANNEL_SEL                     _NO_DDC
#define _D1_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

// For HDMI MultiEdid
#define _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_NOT_EXIST
#define _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_NOT_EXIST
#define _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST

// For DP
#define _D1_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

// For DP Type-C
#define _D1_DP_TYPE_C_PORT_CTRL_TYPE            _RTS5400_SERIES
#define _D1_DP_TYPE_C_USB_HUB_TYPE              _RTS5411_SERIES
#define _D1_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D1_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#define _D1_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN

// For MHL
#define _D1_MHL_VERSION                         _MHL_VERSION_NULL
#define _D1_CBUS_CHANNEL_SEL                    _NO_CBUS
#define _D1_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_NONE
#define _D1_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D2 Input Port
//--------------------------------------------------
#define _D2_INPUT_PORT_TYPE                     _D2_NO_PORT
#define _D2_DDC_CHANNEL_SEL                     _NO_DDC
#define _D2_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D2_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

// For HDMI MultiEdid
#define _D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_NOT_EXIST
#define _D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_NOT_EXIST
#define _D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST

// For MHL
#define _D2_MHL_VERSION                         _MHL_VERSION_NULL
#define _D2_CBUS_CHANNEL_SEL                    _NO_CBUS
#define _D2_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_NONE
#define _D2_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D3 Input Port
//--------------------------------------------------
#define _D3_INPUT_PORT_TYPE                     _D3_NO_PORT
#define _D3_DDC_CHANNEL_SEL                     _NO_DDC
#define _D3_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D3_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

// For HDMI MultiEdid
#define _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_NOT_EXIST
#define _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_NOT_EXIST
#define _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST

// For MHL
#define _D3_MHL_VERSION                         _MHL_VERSION_NULL
#define _D3_CBUS_CHANNEL_SEL                    _NO_CBUS
#define _D3_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_NONE
#define _D3_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D6 Input Port
//--------------------------------------------------
#define _D6_INPUT_PORT_TYPE                     _D6_NO_PORT
#define _D6_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D6_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

// For DP
#define _D6_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D6_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D6_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE
#define _D6_INPUT_PORT_SWITCH_FROM              _SWITCH_NONE

// For DP Type-C
#define _D6_DP_TYPE_C_PORT_CTRL_TYPE            _RTS5400_SERIES
#define _D6_DP_TYPE_C_USB_HUB_TYPE              _RTS5411_SERIES
#define _D6_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D6_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#define _D6_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN


/////////////////////////////
// Type-C Config Setting   //
/////////////////////////////

//-------------------------------------------------
// Type-C Auto Detect Pinassignment Type Mode Option
//-------------------------------------------------
#define _TYPE_C_PINCFG_AUTO_MODE                _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE

//-------------------------------------------------
// Type-C Support 5400 Spec Version
//-------------------------------------------------
#define _TYPE_C_RTS5400_SERIES_SPEC_VER_SEL     _RTS5400_SERIES_FW_SPEC_VERSION_V0D9

//-------------------------------------------------
// Type-C PDO Information Support
//-------------------------------------------------
#define _TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT _OFF


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D3_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D6_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_4                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_5                _NO_INPUT_PORT


//////////////
// VGA Port //
//////////////

//--------------------------------------------------
// Analog Signal Swap Options
//--------------------------------------------------
#define _VGA_INPUT_SWAP_RG                      _OFF
#define _VGA_INPUT_SWAP_RB                      _OFF
#define _VGA_INPUT_SWAP_GB                      _OFF

//--------------------------------------------------
// Analog Hsync Schmitt Trigger Control
//--------------------------------------------------
#define _VGA_HS_SCHMITT_TRIGGER_POLARITY_SEL    _POSITIVE
#define _VGA_HS_SCHMITT_TRIGGER_VTH_FINE_TUNE   _DISABLE
#define _VGA_HS_SCHMITT_TRIGGER_POSITIVE_VTH    _HS_SCHMITT_TRIGGER_LEVEL_10
#define _VGA_HS_SCHMITT_TRIGGER_NEGATIVE_VTH    _HS_SCHMITT_TRIGGER_LEVEL_01


///////////////
// TMDS Port //
///////////////

//--------------------------------------------------
// TMDS Signal Swap Options
//--------------------------------------------------
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
#define _D1_TMDS_BR_SWAP                        _ON
#define _D1_TMDS_PN_SWAP                        _ON
#else
#define _D1_TMDS_BR_SWAP                        _OFF
#define _D1_TMDS_PN_SWAP                        _OFF
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
#define _D2_TMDS_BR_SWAP                        _ON
#define _D2_TMDS_PN_SWAP                        _ON
#else
#define _D2_TMDS_BR_SWAP                        _OFF
#define _D2_TMDS_PN_SWAP                        _OFF
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
#define _D3_TMDS_BR_SWAP                        _ON
#define _D3_TMDS_PN_SWAP                        _ON
#else
#define _D3_TMDS_BR_SWAP                        _OFF
#define _D3_TMDS_PN_SWAP                        _OFF
#endif


/////////////
// DP Port //
/////////////

//--------------------------------------------------
// DP Lane & PN Swap Option
//--------------------------------------------------
#define _D0_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#define _D0_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#define _D0_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#define _D0_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3
#define _D0_DP_PCB_LANE0_PN_SWAP                _OFF
#define _D0_DP_PCB_LANE1_PN_SWAP                _OFF
#define _D0_DP_PCB_LANE2_PN_SWAP                _OFF
#define _D0_DP_PCB_LANE3_PN_SWAP                _OFF

#define _D1_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE0
#define _D1_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE1
#define _D1_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE2
#define _D1_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE3
#define _D1_DP_PCB_LANE0_PN_SWAP                _OFF
#define _D1_DP_PCB_LANE1_PN_SWAP                _OFF
#define _D1_DP_PCB_LANE2_PN_SWAP                _OFF
#define _D1_DP_PCB_LANE3_PN_SWAP                _OFF


//////////////
// MHL Port //
//////////////

//--------------------------------------------------
// MHL CBUS Output High Voltage Level
//--------------------------------------------------
#define _MHL_CBUS_LDO_HIGH                      _DISABLE


////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Port Config
//--------------------------------------------------
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_AB
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#define _LVDS_PORT_CD_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
#define _LVDS_RB_SWAP                           _DISABLE
#define _LVDS_ML_SWAP                           _DISABLE
#define _LVDS_DVS_INVERT                        _DISABLE
#define _LVDS_DHS_INVERT                        _DISABLE
#define _LVDS_DEN_INVERT                        _DISABLE
#define _LVDS_PAIR_MIRROR                       _DISABLE

#define _LVDS_CLK_CHANNEL_SEL                   _NORMAL_MODE           /// Display CLK Pair Position Selection: TXK = A / B / C / D / E / F / G / H port
                                                                       /// Normal mode: TXKCK1 as CLK for 8bit / 10bit
                                                                       /// Mode1:       TXK1   as CLK for 8bit / 10bit
                                                                       /// Mode2:       TXK2   as CLK for 8bit / 10bit
                                                                       /// Mode3:       TXKCK1 as CLK for 8bit
                                                                       ///              TXK3   as CLK for        10bit

//--------------------------------------------------
// LVDS Port AB Phase Selection
//--------------------------------------------------
#define _LVDS_A0_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A1_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A2_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_AC_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A3_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_A4_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B0_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B1_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B2_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_BC_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B3_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_B4_PHASE                          _LVDS_PI_PHASE_AB0
#define _LVDS_PI_PHASE_AB0_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used
#define _LVDS_PI_PHASE_AB1_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used
#define _LVDS_PI_PHASE_AB2_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used
#define _LVDS_PI_PHASE_AB3_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used

//--------------------------------------------------
// LVDS Port CD Phase Selection
//--------------------------------------------------
#define _LVDS_C0_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_C1_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_C2_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_CC_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_C3_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_C4_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_D0_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_D1_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_D2_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_DC_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_D3_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_D4_PHASE                          _LVDS_PI_PHASE_CD0
#define _LVDS_PI_PHASE_CD0_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used
#define _LVDS_PI_PHASE_CD1_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used
#define _LVDS_PI_PHASE_CD2_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used
#define _LVDS_PI_PHASE_CD3_SEL                  _LVDS_PHASE0           // Only Phase 0 ~ 16 can be used

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL               _DISABLE
#define _LVDS_VCM_USER_LEVEL                    0x0C

//--------------------------------------------------
// LVDS SSC Config
//--------------------------------------------------
#define _LVDS_SPREAD_RANGE                      10                     // 0~15, 0 ~ disable, 15 ~ 7.50%
#define _LVDS_SPREAD_SPEED                      _SPEED_33K


/////////////////////////
// eDPTx 1.1 HBR Panel //
/////////////////////////

//--------------------------------------------------
// eDPTx 1.1 HBR Main Link Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_LANE_SWAP               _DISABLE               // Lane Port Swap
#define _PANEL_DPTX_1_1_LANE_PN_SWAP            _DISABLE               // Lane PN Swap
#define _PANEL_DPTX_1_1_SWING_LEVEL             _DP_SWING_800_MV       // Swing Level = 400,600,800,1200mV
#define _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_0_DB   // Preemphasis Level = 0,3.5,6,9.5dB

//--------------------------------------------------
// eDPTx 1.1 HBR SSC Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_SPREAD_RANGE            5                      // 0~15, 0 ~ disable, 15 ~ 0.98%
#define _PANEL_DPTX_1_1_SPREAD_SPEED            _SPEED_33K             // _SPEED_30K or _SPEED_33K


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _NO_PWM
#define _BACKLIGHT_PWM_INVERSE                  _OFF

#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF
#define _PWM5_PSAV_EN                           _OFF

#define _PWM0_PDOW_EN                           _OFF
#define _PWM1_PDOW_EN                           _OFF
#define _PWM2_PDOW_EN                           _OFF
#define _PWM3_PDOW_EN                           _OFF
#define _PWM4_PDOW_EN                           _OFF
#define _PWM5_PDOW_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _OFF
#define _PWM_RST_BY_TCON                        _OFF


/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// Sofware and Hardware IIC Option
//--------------------------------------------------
#define _SW_IIC_SUPPORT                         _OFF
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _OFF
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _NO_IIC_PIN


//////////
// Misc //
//////////

//--------------------------------------------------
// AD Key Option
//--------------------------------------------------
#define _AD_KEY_SUPPORT                         _OFF

//--------------------------------------------------
// Low Speed ADC Option
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _OFF


/////////////////////////////
// RL6432 Series Pin Share //
/////////////////////////////

//--------------------------------------------------
//  RL6432 216 Pin Share
//--------------------------------------------------
#define _PIN_1                                  (0 & 0x0F) // Page 10-0x00[2:0]
// 0 ~ 6 (0: P1D0i<I>,    1: P1D0o<PP>,   2: P1D0o<OD>, 3: test4b_out0,
//        4: test4b_out1, 5: test4b_out2, 6: test4b_out3)

#define _PIN_3                                  (0 & 0x0F) // Page 10-0x01[2:0]
// 0 ~ 2 (0: P1D1i<I>, 1: P1D1o<PP>, 2: P1D1o<OD> & d3_hdmi_hpd_int<I>)

#define _PIN_15                                 (0 & 0x0F) // Page 10-0x02[2:0]
// 0 ~ 2 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD> & d2_hdmi_hpd_int <I>)

#define _PIN_53                                 (0 & 0x0F) // Page 10-0x03[2:0]
// 0 ~ 7 (0: P1D3i<I>,    1: P1D3o<PP>,   2: P1D3o<OD>, 3: tcon[0], 4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

#define _PIN_54                                 (0 & 0x0F) // Page 10-0x04[2:0]
// 0 ~ 7 (0: P1D4i<I>,    1: P1D4o<PP>,   2: P1D4o<OD>, 3: tcon[8],  4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

#define _PIN_66                                 (0 & 0x0F) // Page 10-0x05[2:0]
// 0 ~ 8 (0: P1D5i<I>, 1: P1D5o<PP>, 2: P1D5o<OD>, 8: DDCSCLVGA)

#define _PIN_67                                 (0 & 0x0F) // Page 10-0x06[2:0]
// 0 ~ 8 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 8: DDCSDAVGA)

#define _PIN_68                                 (0 & 0x0F) // Page 10-0x07[2:0]
// 0 ~ 2 (0: P1D7i<I>, 1: P1D7o<PP>,   2: P1D7o<OD>, 3: pwm0 <PP>,  4: pwm0 <OD>,
//        5: tcon[4],  6: test4b_out2, 7: test4b_out3)

#define _PIN_71                                 (0 & 0x0F) // Page 10-0x08[2:0]
// 0 ~ 3 (0: P3D0i<I>, 1: Reserved, 2: P3D0o<OD>, 3: AUXp0)

#define _PIN_72                                 (0 & 0x0F) // Page 10-0x09[2:0]
// 0 ~ 3 (0: P3D1i<I>, 1: Reserved, 2: P3D1o<OD>, 3: AUXn0)

#define _PIN_73                                 (0 & 0x0F) // Page 10-0x0A[2:0]
// 0 ~ 8 (0: P3D2i<I>, 1: Reserved, 2: P3D2o<OD>, 3: AUXp1, 8:DDCSCL1)

#define _PIN_74                                 (0 & 0x0F) // Page 10-0x0B[2:0]
// 0 ~ 8 (0: P3D3i<I>, 1: Reserved, 2: P3D1o<OD>, 3: AUXn1, 8: DDSSDA1)

#define _PIN_91                                 (0 & 0x0F) // Page 10-0x0C[2:0]
// 0 ~ 6 (0: P3D4i<I>,     1: P3D4o<PP>, 2: P3D4o<OD>, 3: a_adc0_0, 4: int0,
//        5: test4b_out0 , 6:test4b_out1)

#define _PIN_92                                 (0 & 0x0F) // Page 10-0x0D[2:0]
// 0 ~ 6 (0: P3D5i<I>,     1: P3D5o<PP>, 2: P3D5o<OD>, 3: a_adc1_0, 4: int1,
//        5: test4b_out2 , 6:test4b_out3)

#define _PIN_93                                 (0 & 0x0F) // Page 10-0x0E[2:0]
// 0 ~ 6 (0: P3D6i<I>,     1: P3D6o<PP>, 2: P3D6o<OD>, 3: a_adc2_0, 4: tcon[9],
//        5: test4b_out0 , 6:test4b_out1)

#define _PIN_94                                 (0 & 0x0F) // Page 10-0x0F[2:0]
// 0 ~ 6 (0: P3D7i<I>,     1: P3D7o<PP>, 2: P3D7o<OD>, 3: a_adc3_0, 4: tcon[10],
//        5: test4b_out2 , 6:test4b_out3)

#define _PIN_89                                 (0 & 0x0F) // Page 10-0x10[2:0]
// 0 ~ 3 (0: P4D0i<I>, 1: P4D0o<PP>, 2: P4D0o<OD>, 3: DPTX_aux_ch_p)

#define _PIN_90                                 (0 & 0x0F) // Page 10-0x11[2:0]
// 0 ~ 3 (0: P4D1i<I>, 1: P4D1o<PP>, 2: P4D1o<OD>, 3: DPTX_aux_ch_n)

#define _PIN_99                                 (0 & 0x0F) // Page 10-0x12[2:0]
// 0 ~ 5 (0: P4D2i<I>, 1: P4D2o<PP>, 2: P4D2o<OD>, 3: Audio_houtl, 4: sd2, 5: spdif2)

#define _PIN_100                                (0 & 0x0F) // Page 10-0x13[2:0]
// 0 ~ 5 (0: P4D3i<I>, 1: P4D3o<PP>, 2: P4D3o<OD>, 3: Audio_houtr, 4: sd3, 5: spdif3)

#define _PIN_103                                (0 & 0x0F) // Page 10-0x14[2:0]
// 0 ~ 4 (0: P4D4i<I>, 1: P4D4o<PP>, 2: P4D4o<OD>, 3: line_inl, 4: ws)

#define _PIN_104                                (0 & 0x0F) // Page 10-0x15[2:0]
// 0 ~ 4 (0: P4D5i<I>, 1: P4D5o<PP>, 2: P4D5o<OD>, 3: line_inr, 4: sck)

#define _PIN_105                                (0 & 0x0F) // Page 10-0x16[2:0]
// 0 ~ 4 (0: P4D6i<I>, 1: P4D6o<PP>, 2: P4D6o<OD>, 3: Audio_ref, 4: mck)

#define _PIN_106                                (0 & 0x0F) // Page 10-0x17[2:0]
// 0 ~ 5 (0: P4D7i<I>, 1: P4D7o<PP>, 2: P4D7o<OD>, 3: Audio_soutl, 4: sd0,
//        5: spdif0)

#define _PIN_107                                (0 & 0x0F) // Page 10-0x18[2:0]
// 0 ~ 5 (0: P5D0i<I>, 1: P5D0o<PP>, 2: P5D0o<OD>, 3: Audio_soutr, 4: sd1,
//        5: spdif1)

#define _PIN_174                                (0 & 0x0F) // Page 10-0x19[2:0]
// 0 ~ 6 (0: P5D1i<I>, 1: P5D1o<PP>, 2: P5D1o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: tcon[6],  6: DPTX_aux_ch_p_1)

#define _PIN_175                                (0 & 0x0F) // Page 10-0x1A[2:0]
// 0 ~ 6 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[7],  6: DPTX_aux_ch_n_1)

#define _PIN_173                                (0 & 0x0F) // Page 10-0x1B[2:0]
// 0 ~ 4 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: DPTX_hpd1_org, 4:  tcon[8])

#define _PIN_164                                (0 & 0x0F) // Page 10-0x1C[2:0]
// 0 ~ 6 (0: P5D4i<I>,   1: P5D4o<PP>, 2: P5D4o<OD>, 3: ws, 4: tcon[12],
//        5:test4b_out0, 6: test4b_out1)

#define _PIN_165                                (0 & 0x0F) // Page 10-0x1D[2:0]
// 0 ~ 5 (0: P5D5i<I>,    1: P5D5o<PP>, 2: P5D5o<OD>, 3: sck, 4: tcon[13] ,
//        5: test4b_out2, 6:  test4b_out3)

#define _PIN_166                                (0 & 0x0F) // Page 10-0x1E[2:0]
// 0 ~ 7 (0: P5D6i<I>,    1: P5D6o<PP>,  2: P5D6o<OD>, 3: mck, 4: test4b_out0 ,
//        5: test4b_out1, 6: test4b_out2 7: test4b_out3)

#define _PIN_167                                (0 & 0x0F) // Page 10-0x1F[2:0]
// 0 ~ 6 (0: P5D7i<I>,    1: P5D7o<PP>, 2: P5D7o<OD>, 3: spdif0, 4: sd0,
//        5: test4b_out0, 6: test4b_out1)

#define _PIN_168                                (0 & 0x0F) // Page 10-0x20[2:0]
// 0 ~ 8  (0: P6D0i<I>, 1: P6D0o<PP>, 2: P6D0o<OD>, 3: clko, 4: t0, 8: usb_spi_clk)

#define _PIN_169                                (0 & 0x0F) // Page 10-0x21[2:0]
// 0 ~ 8  (0: P6D1i<I>, 1: P6D1o<PP>, 2: P6D1o<OD>, 3: int0, 4: t1, 5: dena,
//         8: usb_spi_si )

#define _PIN_170                                (0 & 0x0F) // Page 10-0x22[2:0]
// 0 ~ 8  (0: P6D2i<I>, 1: P6D2o<PP>, 2: P6D2o<OD>, 3: int1, 4: t2, 5: DCLK,
//         8: usb_spi_so)

#define _PIN_171                                (0 & 0x0F) // Page 10-0x23[2:0]
// 0 ~ 8  (0: P6D3i<I>, 1: P6D3o<PP>, 2: P6D3o<OD>, 3: IRQB, 4: DVS,
//         8: usb_spi_ceb0)

#define _PIN_172                                (0 & 0x0F) // Page 10-0x24[2:0]
// 0 ~ 8 (0: P6D4i<I>, 1: P6D4o<PP>, 2: P6D4o<OD>, 3: T2ex, 4: DHS,
//        8: usb_spi_ceb1)

#define _PIN_178                                (0 & 0x0F) // Page 10-0x25[2:0]
// 0 ~ 7 (0: P6D5i<I>, 1: P6D5o<PP>,   2: P6D5o<OD>, 3: PWM5<PP>, 4: PWM5<OD>,
//        5: TCON[2],  6: test4b_out0, 7: test4b_out1)

#define _PIN_179                                (0 & 0x0F) // Page 10-0x26[2:0]
// 0 ~ 8 (0: P6D6i<I>, 1: P6D6o<PP>, 2: P6D6o<OD>, 3: TCON[6],
//        4: IHS_after_scaling_down, 8: IICSCL1)

#define _PIN_180                                (0 & 0x0F) // Page 10-0x27[2:0]
// 0 ~ 8 (0: P6D7i<I>, 1: P6D7o<PP>, 2: P6D7o<OD>, 3: tcon[7],
//        4: IVS_after_scaling_down, 8: IICSDA1)

#define _PIN_183                                (0 & 0x0F) // Page 10-0x28[2:0]
// 0 ~ 4 (0: P7D0i<I>, 1: P7D0o<PP>, 2: P7D0o<OD>, 3: tcon[5],
//        4: IENA_after_scaling_down)

#define _PIN_189                                (0 & 0x0F) // Page 10-0x29[2:0]
// 0 ~ 2 (0: P7D1i<I>, 1: P7D1o<PP>, 2: P7D1o<OD>)

#define _PIN_192                                (0 & 0x0F) // Page 10-0x2A[2:0]
// 0 ~ 6 (0: P7D2i<I>, 1: P7D2o<PP>, 2: P7D2o<OD>, 3: PWM2<PP>, 4: PWM2<OD>,
//        5: TCON[1],  6: IRDA_in )

#define _PIN_193                                (0 & 0x0F) // Page 10-0x2B[2:0]
// 0 ~ 7 (0: P7D3i<I>, 1: P7D3o<PP>,  2: P7D3o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCON[3],  6:Test4b_out2, 7: Test4b_out3)

#define _PIN_194                                (0 & 0x0F) // Page 10-0x2C[2:0]
// 0 ~ 7 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: tcon[5], 4: pwm_out,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_195                                (0 & 0x0F) // Page 10-0x2D[2:0]
// 0 ~ 7 (0: P7D5i<I>,    1: P7D5o<PP>,   2: P7D5o<OD>, 3: tcon[4], 4: pwm_in,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_196                                (0 & 0x0F) // Page 10-0x2E[2:0]
// 0 ~ 7 (0: P7D6i<I>,    1: P7D6o<PP>,   2: P7D6o<OD>, 3: DPTX_hpd_org, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_197                                (0 & 0x0F) // Page 10-0x2F[2:0]
// 0 ~ 5 (0: P7D7i<I>, 1: P7D7o<PP>, 2: P7D7o<OD>, 3: PWM5<PP>, 4: PWM5<OD>,
//        5: TCON[11])

#define _PIN_198                                (0 & 0x0F) // Page 10-0x30[2:0]
// 0 ~ 8 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCON[11], 8: IICSCL2)

#define _PIN_199                                (0 & 0x0F) // Page 10-0x31[2:0]
// 0 ~ 8 (0: P8D1i<I>, 1: P8D1o<PP>, 2: P8D1o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: TCON[0],  8: IICSDA2)

#define _PIN_201                                (0 & 0x0F) // Page 10-0x32[2:0]
// 0 ~ 8 (0: P8D2i<I>,    1: P8D2o<PP>,   2: P8D2o<OD>,   3:  int0, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3, 8: TXD)

#define _PIN_200                                (0 & 0x0F) // Page 10-0x33[2:0]
// 0 ~ 8 (0: P8D3i<I>,    1: P8D3o<PP>,   2: P8D3o<OD>,   3: int1, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3, 8: RXD)

#define _PIN_202                                (0 & 0x0F) // Page 10-0x34[2:0]
// 0 ~ 7 (0: P8D4i<I>,    1: P8D4o<PP>,   2: P8D4o<OD>, 3: tcon[13], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_203                                (0 & 0x0F) // Page 10-0x35[2:0]
// 0 ~ 7 (0: P8D5i<I>,    1: P8D5o<PP>,   2: P8D5o<OD>, 3: tcon[12], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_204                                (0 & 0x0F) // Page 10-0x36[2:0]
// 0 ~ 7 (0: P8D6i<I>,    1: P8D6o<PP>,   2: P8D6o<OD>, 3:  tcon[10], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_205                                (0 & 0x0F) // Page 10-0x37[2:0]
// 0 ~ 7 (0: P8D7i<I>,    1: P8D7o<PP>,   2: P8D7o<OD>, 3: tcon[9] , 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_208                                (0 & 0x0F) // Page 10-0x38[2:0]
// 0 ~ 7 (0: P9D0i<I>,    1: Reserved,    2: Reserved, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

#define _PIN_209                                (0 & 0x0F) // Page 10-0x39[2:0]
// 0 ~ 5 (0: P9D1i<I>, 1: P9D1o<PP>, 2: P9D1o<OD>, 3: PWM2<PP>, 4: PWM2<OD>
//        5: TCON[3])

#define _PIN_210                                (0 & 0x0F) // Page 10-0x3A[2:0]
// 0 ~ 8 (0: P9D2i<I>, 1: P9D2o<PP>, 2: P9D2o<OD>, 3: PWM0<PP>, 4: PWM0<OD>
//        5: TCON[1],  8: EEIICSCL)

#define _PIN_211                                (0 & 0x0F) // Page 10-0x3B[2:0]
// 0 ~ 8 (0: P9D3i<I>, 1: P9D3o<PP>, 2: P9D3o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[2],  8:EEIICSDA)

#define _PIN_212                                (0 & 0x0F) // Page 10-0x3C[2:0]
// 0 ~ 8 (0: P9D4i<I>, 1: Reserved, 2: P9D4o<OD>, 8: DDCSCL2)

#define _PIN_213                                (0 & 0x0F) // Page 10-0x3D[2:0]
// 0 ~ 8 (0: P9D5i<I>, 1: Reserved, 2: P9D5o<OD>, 8: DDCSDA2)

#define _PIN_214                                (0 & 0x0F) // Page 10-0x3E[2:0]
// 0 ~ 8 (0: P9D6i<I>, 1: Reserved, 2: P9D6o<OD>, 8: DDCSCL3)

#define _PIN_215                                (0 & 0x0F) // Page 10-0x3F[2:0]
// 0 ~ 8 (0: P9D7i<I>, 1: Reserved, 2: P9D7o<OD>, 8: DDCSDA3)

#define _PIN_216                                (0 & 0x0F) // Page 10-0x40[2:0]
// 0 ~ 6 (0: PAD0i<I>,    1: PAD0o<PP>, 2: PAD0o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

#define _PIN_139                                (0 & 0x0F) // Page 10-0x45[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD1i<I>, 2: PAD1o<PP>, 3: PAD1o<OD>, 4: TXB4+_10b)

#define _PIN_140                                (0 & 0x0F) // Page 10-0x46[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD2i<I>, 2: PAD2o<PP>, 3: PAD2o<OD>, 4: TXB4-_10b)

#define _PIN_141                                (0 & 0x0F) // Page 10-0x47[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD3i<I>, 2: PAD3o<PP>, 3: PAD3o<OD>, 4: TXB3+_10b)

#define _PIN_142                                (0 & 0x0F) // Page 10-0x48[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD4i<I>, 2: PAD4o<PP>, 3: PAD4o<OD>, 4: TXB3-_10b)

#define _PIN_143                                (0 & 0x0F) // Page 10-0x49[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD5i<I>, 2: PAD5o<PP>, 3: PAD5o<OD>, 4: TXB2+_10b)

#define _PIN_144                                (0 & 0x0F) // Page 10-0x4A[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD6i<I>, 2: PAD6o<PP>, 3: PAD6o<OD>, 4: TXB2-_10b)

#define _PIN_145                                (0 & 0x0F) // Page 10-0x4B[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PAD7i<I>, 2: PAD7o<PP>, 3: PAD7o<OD>, 4: TXB1+_10b)

#define _PIN_146                                (0 & 0x0F) // Page 10-0x4C[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD0i<I>, 2: PBD0o<PP>, 3: PBD0o<OD>, 4: TXB1-_10b)

#define _PIN_147                                (0 & 0x0F) // Page 10-0x4D[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD1i<I>, 2: PBD1o<PP>, 3: PBD1o<OD>, 4: TXB0+_10b)

#define _PIN_148                                (0 & 0x0F) // Page 10-0x4E[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD2i<I>, 2: PBD2o<PP>, 3: PBD2o<OD>, 4: TXB0-_10b)

#define _PIN_150                                (0 & 0x0F) // Page 10-0x4F[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD3i<I>, 2: PBD3o<PP>, 3: PBD3o<OD>, 4: TXA4+_10b)

#define _PIN_151                                (0 & 0x0F) // Page 10-0x50[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD4i<I>, 2: PBD4o<PP>, 3: PBD4o<OD>, 4: TXA4+_10b)

#define _PIN_152                                (0 & 0x0F) // Page 10-0x51[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD5i<I>, 2: PBD5o<PP>, 3: PBD5o<OD>, 4: TXA3+_10b)

#define _PIN_153                                (0 & 0x0F) // Page 10-0x52[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD6i<I>, 2: PBD6o<PP>, 3: PBD6o<OD>, 4: TXA3-_10b)

#define _PIN_154                                (0 & 0x0F) // Page 10-0x53[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PBD7i<I>, 2: PBD7o<PP>, 3: PBD7o<OD>, 4: TXAC+_10b)

#define _PIN_155                                (0 & 0x0F) // Page 10-0x54[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD0i<I>, 2: PCD0o<PP>, 3: PCD0o<OD>, 4: TXAC-_10b)

#define _PIN_156                                (0 & 0x0F) // Page 10-0x55[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD1i<I>, 2: PCD1o<PP>, 3: PCD1o<OD>, 4: TXA2+_10b)

#define _PIN_157                                (0 & 0x0F) // Page 10-0x56[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD2i<I>, 2: PCD2o<PP>, 3: PCD2o<OD>, 4: TXA2-_10b)

#define _PIN_158                                (0 & 0x0F) // Page 10-0x57[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD3i<I>, 2: PCD3o<PP>, 3: PCD3o<OD>, 4: TXA1+_10b)

#define _PIN_159                                (0 & 0x0F) // Page 10-0x58[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD4i<I>, 2: PCD4o<PP>, 3: PCD4o<OD>, 4: TXA1-_10b)

#define _PIN_160                                (0 & 0x0F) // Page 10-0x59[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD5i<I>, 2: PCD5o<PP>, 3: PCD5o<OD>, 4: TXA0+_10b)

#define _PIN_161                                (0 & 0x0F) // Page 10-5A[2:0]
// 0 ~ 5 (0: Hi-Z, 1: PCD6i<I>, 2: PCD6o<PP>, 3: PCD6o<OD>, 4: TXA0-_10b)

#define _PIN_97                                 (0 & 0x0F) // Page 10-0x5B[2:0]
// 0 ~ 5 (0: PCD7i<I>, 1: PCD7o<PP>, 2: PCD7o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: PWM_out )

#define _PIN_98                                 (0 & 0x0F) // Page 10-0x5C[2:0]
// 0 ~ 3 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>, 3: PWM_in)


//////////////////////
// GPIO Power Macro //
//////////////////////

//-----------------------------------------------
// Macro of Pcb GPIO Inital Setting
//-----------------------------------------------
#define PCB_GPIO_ON_REGION_INITIAL_SETTING()    {\
                                                }

//-----------------------------------------------
// Power OFF Region GPIO Initial Setting
// PIN139-PIN48 , PIN150-PIN161 , PIN164-PIN172
// PIN173-PIN175  , PIN178-PIN183
//-----------------------------------------------
#define PCB_GPIO_OFF_REGION_INITIAL_SETTING()   {\
                                                }

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                }

#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                }

#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                }

#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                }


/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of VCCK_OFF Power Control
//-----------------------------------------------
#define bVCCKOFFPOWER                           (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _VCCK_OFF_POWER_ON                      1
#define _VCCK_OFF_POWER_OFF                     0
#define _VCCK_OFF_TIME_POLLING_POWER_ON         20 // ms

#define PCB_VCCK_OFF_POWER(x)                   {\
                                                    bVCCKOFFPOWER = (x);\
                                                }

//-----------------------------------------------
// Macro of Power Board Low Power Pin High/Low
//-----------------------------------------------
#define bPOWERBOARDPOWER                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LOW_POWER_ON                           1
#define _LOW_POWER_OFF                          0

#define PCB_POWERBOARD_LOWPOWER(x)              {\
                                                    bPOWERBOARDPOWER = (x);\
                                                }

//-----------------------------------------------
// Macro of 12V to 5V Regulator for MyDP or MHL
//-----------------------------------------------
#define bREGULATOR_5V                           (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _REGULATOR_5V_ON                        0
#define _REGULATOR_5V_OFF                       1

#define PCB_REGULATOR_5V_OUT(x)                 {\
                                                    bREGULATOR_5V = (x);\
                                                }


////////////////////
// DP Power Macro //
////////////////////

//-----------------------------------------------
// Macro of MyDP Power Control
//-----------------------------------------------
#define bD0_MYDP_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_MYDP_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_MYDP_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _MYDP_5V_POWER_ON                       1
#define _MYDP_5V_POWER_OFF                      0

#define PCB_D0_MYDP_POWER(x)                    {\
                                                    bD0_MYDP_POWER = (x);\
                                                }

#define PCB_D1_MYDP_POWER(x)                    {\
                                                    bD1_MYDP_POWER = (x);\
                                                }

#define PCB_D6_MYDP_POWER(x)                    {\
                                                    bD6_MYDP_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of DP1.2 Power Control
//-----------------------------------------------
#define bD0_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)


#define _DP12_33V_POWER_ON                      1
#define _DP12_33V_POWER_OFF                     0

#define PCB_D0_DP12_POWER(x)                    {\
                                                    bD0_DP12_POWER = (x);\
                                                }

#define PCB_D1_DP12_POWER(x)                    {\
                                                    bD1_DP12_POWER = (x);\
                                                }

#define PCB_D6_DP12_POWER(x)                    {\
                                                    bD6_DP12_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of MyDP & DP1.2 Power Select
//-----------------------------------------------
#define bD0_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DP12_33V_POWER                         0
#define _MYDP_5V_POWER                          1

#define PCB_D0_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD0_D12_MYDP_SEL = (x);\
                                                }

#define PCB_D1_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD1_D12_MYDP_SEL = (x);\
                                                }

#define PCB_D6_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD6_D12_MYDP_SEL = (x);\
                                                }


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _PANEL_CONTROL_ON                       0
#define _PANEL_CONTROL_OFF                      1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LIGHT_CONTROL_ON                       0
#define _LIGHT_CONTROL_OFF                      1

#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = (x);\
                                                }

#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if((x) == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (((DWORD)_PANEL_TYP_FRAME_RATE * 60) / 100));\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    PCB_BACKLIGHT_POWER_PIN(x)\
                                                }


//////////////////////////////////////
// eDPTx Panel Power Sequence Macro //
//////////////////////////////////////

//--------------------------------------------------
// eDPTx 1.1 Panel Power Sequence Macro
//--------------------------------------------------
#define PCB_DPTX1_POWER_SEQUENCE(x)             {\
                                                }


/////////////////////////
// Write Protect Macro //
/////////////////////////

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D2_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D3_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }


////////////////////////
// Cable Status Macro //
////////////////////////

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------
#define bD0_DP_PIN15_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_DP_PIN16_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_DP_PIN17_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD1_DP_PIN15_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP_PIN16_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP_PIN17_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD6_DP_PIN15_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_DP_PIN16_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_DP_PIN17_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

// For DP Type-C
#define bD0_USB_TYPEC_AUXP_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_USB_TYPEC_AUXN_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD1_USB_TYPEC_AUXP_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_USB_TYPEC_AUXN_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD6_USB_TYPEC_AUXP_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_USB_TYPEC_AUXN_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bA0_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_CONNECT                             (((bit)bD0_DP_PIN15_CONNECT == _TRUE) && ((bit)bD0_DP_PIN16_CONNECT == _TRUE) && ((bit)bD0_DP_PIN17_CONNECT == _FALSE))
#define bD1_CONNECT                             (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))
#define bD2_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD6_CONNECT                             (((bit)bD6_DP_PIN15_CONNECT == _TRUE) && ((bit)bD6_DP_PIN16_CONNECT == _TRUE) && ((bit)bD6_DP_PIN17_CONNECT == _FALSE))

// For DP Type-C
#define bD0_CONNECT                             (((bit)bD0_USB_TYPEC_AUXP_CONNECT == _TRUE) && ((bit)bD0_USB_TYPEC_AUXN_CONNECT == _FALSE))
#define bD1_CONNECT                             (((bit)bD1_USB_TYPEC_AUXP_CONNECT == _TRUE) && ((bit)bD1_USB_TYPEC_AUXN_CONNECT == _FALSE))
#define bD6_CONNECT                             (((bit)bD6_USB_TYPEC_AUXP_CONNECT == _TRUE) && ((bit)bD6_USB_TYPEC_AUXN_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)
#define PCB_D2_PIN()                            (bD2_CONNECT)
#define PCB_D3_PIN()                            (bD3_CONNECT)
#define PCB_D6_PIN()                            (bD6_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_DP_PIN17_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)
#define GET_PCB_D6_DP_SOURCE_POWER()            (bD6_DP_PIN17_CONNECT)

// For DP Type-C
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_USB_TYPEC_AUXN_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_USB_TYPEC_AUXN_CONNECT)
#define GET_PCB_D6_DP_SOURCE_POWER()            (bD6_USB_TYPEC_AUXN_CONNECT)

//-----------------------------------------------
// Macro of MHL Cable Connect
//-----------------------------------------------
#define bD1_MHL_CONNECT                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_MHL_CONNECT                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_MHL_CONNECT                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_D1_MHL_DETECT()                     (bD1_MHL_CONNECT)
#define PCB_D2_MHL_DETECT()                     (bD2_MHL_CONNECT)
#define PCB_D3_MHL_DETECT()                     (bD3_MHL_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _D0_HOT_PLUG_HIGH                       1
#define _D0_HOT_PLUG_LOW                        0

#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0

#define _D2_HOT_PLUG_HIGH                       1
#define _D2_HOT_PLUG_LOW                        0

#define _D3_HOT_PLUG_HIGH                       1
#define _D3_HOT_PLUG_LOW                        0

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = (x);\
                                                }

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = (x);\
                                                }

#define PCB_D2_HOTPLUG(x)                       {\
                                                    bD2_HPD = (x);\
                                                }

#define PCB_D3_HOTPLUG(x)                       {\
                                                    bD3_HPD = (x);\
                                                }

#define PCB_D0_HOTPLUG_DETECT()                 (bD0_HPD)
#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)
#define PCB_D2_HOTPLUG_DETECT()                 (bD2_HPD)
#define PCB_D3_HOTPLUG_DETECT()                 (bD3_HPD)


//////////////////////////////////////
// DP D0 & D6 External Switch Macro //
//////////////////////////////////////

//-----------------------------------------------
// Macro of D6 Switch Power
//-----------------------------------------------
#define bDIGITAL_D6_SWITCH_POWER                (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DIGITAL_D6_SWITCH_POWER_ON             1
#define _DIGITAL_D6_SWITCH_POWER_DOWN           0

#define PCB_DIGITAL_D6_SWITCH_POWER(x)          {\
                                                    bDIGITAL_D6_SWITCH_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of D6 Switch Lane & Aux_HPD Macro
//-----------------------------------------------
#define bDIGITAL_D6_SWITCH_LANE                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bDIGITAL_D6_SWITCH_AUX_HPD              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DP_D0_D6_SWITCH_D0                     1
#define _DP_D0_D6_SWITCH_D6                     0

#define PCB_DIGITAL_D0_D6_SWITCH_LANE(x)        {\
                                                    bDIGITAL_D6_SWITCH_LANE = (x);\
                                                }

#define PCB_DIGITAL_D0_D6_SWITCH_AUX_HPD(x)     {\
                                                    bDIGITAL_D6_SWITCH_AUX_HPD = (x);\
                                                }


///////////////
// MHL Macro //
///////////////

//-----------------------------------------------
// Macro of HDMI/MHL Switch
//-----------------------------------------------
#define bD1_TMDS_SWITCH                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_TMDS_SWITCH                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_TMDS_SWITCH                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _TMDS_SWITCH_MHL_CBUS                   0
#define _TMDS_SWITCH_HDMI_HPD                   1

#define PCB_D1_HDMI_MHL_SWITCH(x)               {\
                                                    bD1_TMDS_SWITCH = (x);\
                                                }

#define PCB_D2_HDMI_MHL_SWITCH(x)               {\
                                                    bD2_TMDS_SWITCH = (x);\
                                                }

#define PCB_D3_HDMI_MHL_SWITCH(x)               {\
                                                    bD3_TMDS_SWITCH = (x);\
                                                }

//-----------------------------------------------
// Macro of MHL VBus Switch
//-----------------------------------------------
#define bD1_MHL_VBUS_SWITCH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_MHL_VBUS_SWITCH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_MHL_VBUS_SWITCH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _MHL_VBUS_ON                            1
#define _MHL_VBUS_OFF                           0

#define PCB_D1_MHL_VBUS_SWITCH(x)               {\
                                                    bD1_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_D2_MHL_VBUS_SWITCH(x)               {\
                                                    bD2_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_D3_MHL_VBUS_SWITCH(x)               {\
                                                    bD3_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_GET_D1_MHL_VBUS_SWITCH()            (bD1_MHL_VBUS_SWITCH)
#define PCB_GET_D2_MHL_VBUS_SWITCH()            (bD2_MHL_VBUS_SWITCH)
#define PCB_GET_D3_MHL_VBUS_SWITCH()            (bD3_MHL_VBUS_SWITCH)

//-----------------------------------------------
// Macro of MHL VBUS 5V Power Control
//-----------------------------------------------
#define PCB_MHL_VBUS_POWER(x)                   {\
                                                    if((x) == _MHL_VBUS_ON)\
                                                    {\
                                                        PCB_REGULATOR_5V_OUT(_REGULATOR_5V_ON);\
                                                    }\
                                                    else\
                                                    {\
                                                        if(ScalerSyncMHLVBusPowerExist() == _FALSE)\
                                                        {\
                                                            PCB_REGULATOR_5V_OUT(_REGULATOR_5V_OFF);\
                                                        }\
                                                    }\
                                                }


///////////////
// PWM Macro //
///////////////

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 240);\
                                                }

#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_GET_8BIT_PWM_DUTY(_BACKLIGHT_PWM))

#elif(_PWM_DUT_RESOLUTION == _PWM_12BIT)

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_12BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#define PCB_GET_BACKLIGHT_PWM()                 (MCU_GET_12BIT_PWM_DUTY(_BACKLIGHT_PWM))

#endif


//////////////////
// SW IIC Macro //
//////////////////

//--------------------------------------------------
// Macro of IIC : (_SW_IIC_SUPPORT == _ON)
//--------------------------------------------------
#define bSWIIC_SYS_EEPROM_SCL                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bSWIIC_SYS_EEPROM_SDA                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_SW_IIC_SDA_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SDA = _TRUE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SDA_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SDA = _FALSE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        (x) = bSWIIC_SYS_EEPROM_SDA;\
                                                    }\
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SCL = _TRUE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SCL_CLR()                    {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        bSWIIC_SYS_EEPROM_SCL = _FALSE;\
                                                    }\
                                                }
#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                    if(GET_SW_IIC_STATUS() == _IIC_SYS_EEPROM)\
                                                    {\
                                                        (x) = bSWIIC_SYS_EEPROM_SCL;\
                                                    }\
                                                }


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bLED2                                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                }

#define PCB_LED_IDLE()                          {\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                }

#define PCB_LED_ON()                            {\
                                                }

#define PCB_LED_OFF()                           {\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                }

#define PCB_LED_TYPE3()                         {\
                                                }

#define PCB_LED_TYPE4()                         {\
                                                }

#define PCB_LED_TYPE5()                         {\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
                                                }


//////////////////
// AD Key Macro //
//////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define AD_KEY0                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define AD_KEY1                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define AD_KEY2                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define AD_KEY3                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_ADKEY0()                            (_FALSE)
#define PCB_ADKEY1()                            (_FALSE)
#define PCB_ADKEY2()                            (_FALSE)
#define PCB_ADKEY3()                            (_FALSE)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                }


////////////////////
// GPIO Key Macro //
////////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define bPOWER_KEY                              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bMENU_KEY                               (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bEXIT_KEY                               (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bLEFT_KEY                               (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bRIGHT_KEY                              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                }


//////////////////
// EEPROM Macro //
//////////////////

//-----------------------------------------------
// Macro of HDMI External EDID Switch
//-----------------------------------------------
#define bD1_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD3_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EEPROM_EDID_ENABLE                     0
#define _EEPROM_EDID_DISABLE                    1

#define PCB_D1_EXT_EDID_0_SWITCH(x)             {\
                                                    bD2_EXT_SWITCH_EDID_0 = (x);\
                                                }

#define PCB_D1_EXT_EDID_1_SWITCH(x)             {\
                                                    bD2_EXT_SWITCH_EDID_1 = (x);\
                                                }

#define PCB_D1_EXT_EDID_2_SWITCH(x)             {\
                                                    bD2_EXT_SWITCH_EDID_2 = (x);\
                                                }

#define PCB_D2_EXT_EDID_0_SWITCH(x)             {\
                                                    bD2_EXT_SWITCH_EDID_0 = (x);\
                                                }

#define PCB_D2_EXT_EDID_1_SWITCH(x)             {\
                                                    bD2_EXT_SWITCH_EDID_1 = (x);\
                                                }

#define PCB_D2_EXT_EDID_2_SWITCH(x)             {\
                                                    bD2_EXT_SWITCH_EDID_2 = (x);\
                                                }

#define PCB_D3_EXT_EDID_0_SWITCH(x)             {\
                                                    bD3_EXT_SWITCH_EDID_0 = (x);\
                                                }

#define PCB_D3_EXT_EDID_1_SWITCH(x)             {\
                                                    bD3_EXT_SWITCH_EDID_1 = (x);\
                                                }

#define PCB_D3_EXT_EDID_2_SWITCH(x)             {\
                                                    bD3_EXT_SWITCH_EDID_2 = (x);\
                                                }


/////////////////
// Audio Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Audio Connect
//-----------------------------------------------
#define bAudioDetect                            (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _AUDIO_CONNECT                          0
#define _AUDIO_DISCONNECT                       1

#define PCB_AUDIO_DETECT()                      (bAudioDetect)

//-----------------------------------------------
// Macro of PCB Audio AMP Control
//-----------------------------------------------
#define bPCBAMPMUTECONTROL                      (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _AMP_MUTE_ON                            0
#define _AMP_MUTE_OFF                           1

#define PCB_AMP_MUTE(x)                         {\
                                                    bPCBAMPMUTECONTROL = (x);\
                                                }

#endif // End of #if(_PCB_TYPE == _RL6432_PCB_EXAMPLE_216_PIN)
