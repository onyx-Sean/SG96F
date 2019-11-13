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
// ID Code      : RL6369_PCB_EXAMPLE_128_PIN.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6369_PCB_EXAMPLE_128_PIN)


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

// For HDMI MultiEdid
#define _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_NOT_EXIST
#define _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_NOT_EXIST
#define _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST

// For DP
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

// For DP Type-C
#define _D0_DP_TYPE_C_PORT_CTRL_TYPE            _RTS5400_SERIES
#define _D0_DP_TYPE_C_USB_HUB_TYPE              _RTS5411_SERIES
#define _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D0_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#define _D0_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN

// For MHL
#define _D0_MHL_VERSION                         _MHL_VERSION_NULL
#define _D0_CBUS_CHANNEL_SEL                    _NO_CBUS
#define _D0_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_NONE
#define _D0_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

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
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
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

// For DP
#define _D2_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D2_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#define _D2_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

// For DP Type-C
#define _D2_DP_TYPE_C_PORT_CTRL_TYPE            _RTS5400_SERIES
#define _D2_DP_TYPE_C_USB_HUB_TYPE              _RTS5411_SERIES
#define _D2_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR      0xD4
#define _D2_DP_TYPE_C_HUB_SLAVE_ADDR            0xD2
#define _D2_DP_TYPE_C_SMBUS_IIC                 _NO_IIC_PIN

// For MHL
#define _D2_MHL_VERSION                         _MHL_VERSION_NULL
#define _D2_CBUS_CHANNEL_SEL                    _NO_CBUS
#define _D2_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_NONE
#define _D2_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE


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

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _NO_INPUT_PORT


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
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
#define _D0_TMDS_BR_SWAP                        _ON
#define _D0_TMDS_PN_SWAP                        _ON
#else
#define _D0_TMDS_BR_SWAP                        _OFF
#define _D0_TMDS_PN_SWAP                        _OFF
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
#define _D1_TMDS_BR_SWAP                        _ON
#define _D1_TMDS_PN_SWAP                        _ON
#else
#define _D1_TMDS_BR_SWAP                        _OFF
#define _D1_TMDS_PN_SWAP                        _OFF
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
#define _D2_TMDS_BR_SWAP                        _ON
#define _D2_TMDS_PN_SWAP                        _ON
#else
#define _D2_TMDS_BR_SWAP                        _OFF
#define _D2_TMDS_PN_SWAP                        _OFF
#endif


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


////////////////////
// For TTL Panel  //
////////////////////

//-------------------------------------------------
// TTL Spread Spectrum Options
//-------------------------------------------------
#define _TTL_SPREAD_RANGE                       10                     // 0~15, 0 ~ disable, 15 ~ 7.50%
#define _TTL_SPREAD_SPEED                       _SPEED_33K


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

//--------------------------------------------------
// Flash Latch Edge Option(Only Supported In RL6369)
//--------------------------------------------------
#define _PCB_FLASH_LATCH_SO_DATA_IN_RISING_EDGE _OFF


/////////////////////////////
// RL6369 Series Pin Share //
/////////////////////////////

//--------------------------------------------------
//  RL6369 128 Pin Share
//--------------------------------------------------
#define _PIN_21                                 (0 & 0x0F) // Page 10-0x00[3:0]
// 0 ~ 15 (0: P1d0i <I> , 1: P1d0o <PP>, 2: P1d0o <OD>, 3: CLKO , 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15: Test4b_out3)

#define _PIN_22                                 (0 & 0x0F) // Page 10-0x01[3:0]
// 0 ~ 15 (0: P1d1i <I> , 1: P1d1o <PP>, 2: P1d1o <OD>, 3~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15: Test4b_out3)

#define _PIN_34                                 (0 & 0x0F) // Page 10-0x02[3:0]
// 0 ~ 15 (0: P1d2i <I> , 1: P1d2o <PP>, 2: P1d2o <OD>, 3: PWM0<PP> , 4: PWM0<OD>, 5: IIS_MCK, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_35                                 (0 & 0x0F) // Page 10-0x03[3:0]
// 0 ~ 15 (0: P1d3i <I> , 1: P1d3o <PP>, 2: P1d3o <OD>, 3: PWM1<PP> , 4: PWM1<OD>, 5: IIS_SCK, 6:IRQB, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_36                                 (0 & 0x0F) // Page 10-0x04[3:0]
// 0 ~ 15 (0: P1d4i <I> , 1: P1d4o <PP>, 2: P1d4o <OD>, 3: PWM2<PP> , 4: PWM2<OD>, 5: IIS_WS, 6: Tcon[13], 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_37                                 (0 & 0x0F) // Page 10-0x05[3:0]
// 0 ~ 15 (0: P1d5i <I> , 1: P1d5o <PP>, 2: P1d5o <OD>, 3: PWM3<PP> , 4: PWM3<OD>, 5: IIS_SD0, 6: Spdif0, 7: IICSCL0, 8: Rxd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_38                                 (0 & 0x0F) // Page 10-0x06[3:0]
// 0 ~ 15 (0: P1d6i <I> , 1: P1d6o <PP>, 2: P1d6o <OD>, 3: PWM4<PP> , 4: PWM4<OD>, 5: IIS_SD1, 6: Spdif1, 7: IICSDA0, 8: Txd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_39                                 (0 & 0x0F) // Page 10-0x07[3:0]
// 0 ~ 15 (0: P1d7i <I> , 1: P1d7o <PP>, 2: P1d7o <OD>, 3: PWM5<PP> , 4: PWM5<OD>, 5: IIS_SD2, 6: Spdif2, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_42                                 (0 & 0x0F) // Page 10-0x08[3:0]
// 0 ~ 15 (0: P3d0i <I> , 1: P3d0o <PP>, 2: P3d0o <OD>, 3: A-adc0, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_43                                 (0 & 0x0F) // Page 10-0x09[3:0]
// 0 ~ 15 (0: P3d1i <I> , 1: P3d1o <PP>, 2: P3d1o <OD>, 3: A-adc1, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_44                                 (0 & 0x0F) // Page 10-0x0A[3:0]
// 0 ~ 15 (0: P3d2i <I> , 1: P3d2o <PP>, 2: P3d2o <OD>, 3: A-adc2, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_45                                 (0 & 0x0F) // Page 10-0x0B[3:0]
// 0 ~ 15 (0: P3d3i <I> , 1: P3d3o <PP>, 2: P3d3o <OD>, 3: A-adc3, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_46                                 (0 & 0x0F) // Page 10-0x0C[3:0]
// 0 ~ 15 (0: P3d4i <I> , 1: P3d4o <PP>, 2: P3d4o <OD>, 3: PWM1<PP>, 4: PWM1<OD>, 5: PWM5<PP> , 6: PWM5<OD>, 7: Tcon[7], 8: Tcon[13], 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_47                                 (0 & 0x0F) // Page 10-0x0D[3:0]
// 0 ~ 15 (0: P3d5i <I> , 1: P3d5o <PP>, 2: P3d5o <OD>, 3: Tcon[8] ,4: Tcon[12], 5~6: reserved, 7: IICSCL1, 8: IICSCL_AUX, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_48                                 (0 & 0x0F) // Page 10-0x0E[3:0]
// 0 ~ 15 (0: P3d6i <I> , 1: P3d6o <PP>, 2: P3d6o <OD>, 3~6: reserved, 7: IICSDA1, 8: IICSDA_AUX, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_49                                 (0 & 0x0F) // Page 10-0x0F[3:0]
// 0 ~ 15 (0: P3d7i <I> , 1: P3d7o <PP>, 2: P3d7o <OD>, 3~6: reserved, 7: DDCSCLVGA, 8: RXD, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_50                                 (0 & 0x0F) // Page 10-0x10[3:0]
// 0 ~ 15 (0: P4d0i <I> , 1: P4d0o <PP>, 2: P4d0o <OD>, 3: Tcon[11] ,4: Tcon[13], 5~6: reserved, 7: DDCSDAVGA, 8: TXD, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_52                                 (0 & 0x0F) // Page 10-0x11[3:0]
// 0 ~ 15 (0: P4d1i <I> , 1: P4d1o <PP>, 2: P4d1o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: IIS_SD3, 6: Spdif3, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_53                                 (0 & 0x0F) // Page 10-0x12[3:0]
// 0 ~ 15 (0: P4d2i <I> , 1: P4d2o <PP>, 2: P4d2o <OD>, 3: PWM3<PP>, 4: PWM3<OD>, 5:PWM4<PP> , 6:PWM4<OD>, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_55                                 (0 & 0x0F) // Page 10-0x13[3:0]
// 0 ~ 15 (0: P4d3i <I> , 1: P4d3o <PP>, 2: P4d3o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: IIS_MCK, 6: Line_inl, 7~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_56                                 (0 & 0x0F) // Page 10-0x14[3:0]
// 0 ~ 15 (0: P4d4i <I> , 1: P4d4o <PP>, 2: P4d4o <OD>, 3: IIS_SCK, 4: Line_inr, 5~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_57                                 (0 & 0x0F) // Page 10-0x15[3:0]
// 0 ~ 15 (0: P4d5i <I> , 1: P4d5o <PP>, 2: P4d5o <OD>, 3: IIS_WS, 4: Audio_ref, 5: Tcon[13] , 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_58                                 (0 & 0x0F) // Page 10-0x16[3:0]
// 0 ~ 15 (0: P4d6i <I> , 1: P4d6o <PP>, 2: P4d6o <OD>, 3: IIS_SD0, 4: Spdif0, 5: Soutl, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_59                                 (0 & 0x0F) // Page 10-0x17[3:0]
// 0 ~ 15 (0: P4d7i <I> , 1: P4d7o <PP>, 2: P4d7o <OD>, 3: IIS_SD1, 4: Spdif1, 5: Soutr, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_60                                 (0 & 0x0F) // Page 10-0x18[3:0]
// 0 ~ 15 (0: P5d0i <I> , 1: P5d0o <PP>, 2: P5d0o <OD>, 3: IIS_SD2, 4: Spdif2, 5: Houtl, 6: reserved, 7: IICSCL2, 8:Rxd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_61                                 (0 & 0x0F) // Page 10-0x19[3:0]
// 0 ~ 15 (0: P5d1i <I> , 1: P5d1o <PP>, 2: P5d1o <OD>, 3: IIS_SD3, 4: Spdif3, 5: Houtr, 6: reserved, 7: IICSDA2, 8: Txd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_63                                 (0 & 0x0F) // Page 10-0x1B[3:0]
// 0 ~ 15 (0: P5d3i <I> , 1: P5d3o <PP>, 2: P5d3o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: PWM3<PP>, 6: PWM3<PP>, 7: Tcon[7], 8: Int1, 9: T2, 10: IHS_after_scaling_down, 11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_64                                 (0 & 0x0F) // Page 10-0x1A[3:0]
// 0 ~ 15 (0: P5d2i <I> , 1: P5d2o <PP>, 2: P5d2o <OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: Tcon[8], 6: Int0, 7: IENA_after_scaling_down, 8: CLKO, 9~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_65                                 (0 & 0x0F) // Page 10-0x1C[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d4i <I>, 2: P5d4o <PP>, 3: P5d4o <OD>, 4: TXO4+_10b, 5: TTL_BLU7, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_66                                 (0 & 0x0F) // Page 10-0x1D[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d5i <I>, 2: P5d5o <PP>, 3: P5d5o <OD>, 4: TXO4-_10b, 5: TTL_BLU6, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_67                                 (0 & 0x0F) // Page 10-0x1E[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d6i <I>, 2: P5d6o <PP>, 3: P5d6o <OD>, 4: TXO3+_8b_10b, 5: TTL_BLU5, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_68                                 (0 & 0x0F) // Page 10-0x1F[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d7i <I>, 2: P5d7o <PP>, 3: P5d7o <OD>, 4: TXO3-_8b_10b, 5: TTL_BLU4, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_69                                 (0 & 0x0F) // Page 10-0x20[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d0i <I>, 2: P6d0o <PP>, 3: P6d0o <OD>, 4: TXO2+_8b_10b, 5: TTL_BLU3, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_70                                 (0 & 0x0F) // Page 10-0x21[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d1i <I>, 2: P6d1o <PP>, 3: P6d1o <OD>, 4: TXO2-_8b_10b, 5: TTL_BLU2, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_71                                 (0 & 0x0F) // Page 10-0x22[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d2i <I>, 2: P6d2o <PP>, 3: P6d2o <OD>, 4: TXO1+_8b_10b, 5: TTL_BLU1, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_72                                 (0 & 0x0F) // Page 10-0x23[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d3i <I>, 2: P6d3o <PP>, 3: P6d3o <OD>, 4: TXO1-_8b_10b, 5: TTL_BLU0, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_73                                 (0 & 0x0F) // Page 10-0x24[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d4i <I>, 2: P6d4o <PP>, 3: P6d4o <OD>, 4:TXO0+_8b_10b, 5:TTL_GRN7, 6~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_74                                 (0 & 0x0F) // Page 10-0x25[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d5i <I>, 2: P6d5o <PP>, 3: P6d5o <OD>, 4: TXO0-_8b_10b, 5: TTL_GRN6, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_77                                 (0 & 0x0F) // Page 10-0x26[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d6i <I>, 2: P6d6o <PP>, 3: P6d6o <OD>, 4: TXE4+_10b, 5: TTL_GRN5, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_78                                 (0 & 0x0F) // Page 10-0x27[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d7i <I>, 2: P6d7o <PP>, 3: P6d7o <OD>, 4: TXE4-_10b, 5: TTL_GRN4, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_96                                 (0 & 0x0F) // Page 10-0x28[3:0]
// 0 ~ 15 (0: P7d0i <I> , 1: P7d0o <PP>, 2: P7d0o <OD>, 3: Int0, 4: TTL_RED1, 5~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_97                                 (0 & 0x0F) // Page 10-0x29[3:0]
// 0 ~ 15 (0: P7d1i <I> , 1: P7d1o <PP>, 2: P7d1o <OD>, 3: Int1, 4: Tcon[11], 5: Reserved, 6: IVS_after_scaling_down,7: TTL_RED0, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_98                                 (0 & 0x0F) // Page 10-0x2A[3:0]
// 0 ~ 15 (0: P7d2i <I> , 1: P7d2o <PP>, 2: P7d2o <OD>, 3: T0, 4: DENA , 5: Tcon[9], 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_99                                 (0 & 0x0F) // Page 10-0x2B[3:0]
// 0 ~ 15 (0: P7d3i <I> , 1: P7d3o <PP>, 2: P7d3o <OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: PWM3<PP>, 6: PWM3<OD>, 7: T1, 8: DHS, 9: Tcon[13] 10~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_100                                (0 & 0x0F) // Page 10-0x2C[3:0]
// 0 ~ 15 (0: P7d4i <I> , 1: P7d4o <PP>, 2: P7d4o <OD>, 3: Aux_d2, 4: DCLK , 5: Tcon[8] , 6: Pwm_in , 7:T2EX , 8~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_101                                (0 & 0x0F) // Page 10-0x2D[3:0]
// 0 ~ 15 (0: P7d5i <I> , 1: P7d5o <PP>, 2: P7d5o <OD>, 3: PWM4<PP>, 4: PWM4<OD>, 5: Aux_d1, 6: DVS, 7: Tcon[7], 8: Pwm_out, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_110                                (0 & 0x0F) // Page 10-0x2E[3:0]
// 0 ~ 15 (0: P7d6i <I> , 1: P7d6o <PP>, 2: P7d6o <OD>, 3: PWM4<PP>, 4: PWM4<OD>, 5: Auxp, 6: reserved, 7: DDCSCL0, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_111                                (0 & 0x0F) // Page 10-0x2F[3:0]
// 0 ~ 15 (0: P7d7i <I> , 1: P7d7o <PP>, 2: P7d7o <OD>, 3: PWM5<PP>, 4: PWM5<OD>, 5: Auxn, 6: reserved, 7: DDCSDA0, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_112                                (0 & 0x0F) // Page 10-0x30[3:0]
// 0 ~ 15 (0: P8d0i <I> , 1: P8d0o <PP>, 2: P8d0o <OD>, 3:Auxp, 4~6:reserved, 7:  DDCSCL1, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_113                                (0 & 0x0F) // Page 10-0x31[3:0]
// 0 ~ 15 (0: P8d1i <I> , 1: P8d1o <PP>, 2: P8d1o <OD>, 3:Auxn, 4~6:reserved, 7: DDCSDA1, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_114                                (0 & 0x0F) // Page 10-0x33[3:0]
// 0 ~ 15 (0: P8d3i <I> , 1: P8d3o <PP>, 2: P8d3o <OD>, 3: Auxp, 4~6: reserved, 7:  DDCSCL2, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

#define _PIN_115                                (0 & 0x0F) // Page 10-0x32[3:0]
// 0 ~ 15 (0: P8d2i <I> , 1: P8d2o <PP>, 2: P8d2o <OD> 3: Auxn, 4~6: reserved, 7:  DDCSDA2, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)


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
// PIN65-PIN67
// PIN77-PIN88
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
// Macro of Embedded LDO Support
//-----------------------------------------------
#define _EMBEDDED_LDO_OFF                       0
#define _EMBEDDED_LDO_ON                        1

#define PCB_EMBEDDED_LDO_DETECT()               (_EMBEDDED_LDO_OFF)

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
#define bD2_MYDP_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _MYDP_5V_POWER_ON                       1
#define _MYDP_5V_POWER_OFF                      0

#define PCB_D0_MYDP_POWER(x)                    {\
                                                    bD0_MYDP_POWER = (x);\
                                                }

#define PCB_D1_MYDP_POWER(x)                    {\
                                                    bD1_MYDP_POWER = (x);\
                                                }

#define PCB_D2_MYDP_POWER(x)                    {\
                                                    bD2_MYDP_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of DP1.2 Power Control
//-----------------------------------------------
#define bD0_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_DP12_POWER                          (MCU_EMPTY_PIN_ASSIGN_ADDRESS)


#define _DP12_33V_POWER_ON                      1
#define _DP12_33V_POWER_OFF                     0

#define PCB_D0_DP12_POWER(x)                    {\
                                                    bD0_DP12_POWER = (x);\
                                                }

#define PCB_D1_DP12_POWER(x)                    {\
                                                    bD1_DP12_POWER = (x);\
                                                }

#define PCB_D2_DP12_POWER(x)                    {\
                                                    bD2_DP12_POWER = (x);\
                                                }

//-----------------------------------------------
// Macro of MyDP & DP1.2 Power Select
//-----------------------------------------------
#define bD0_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_D12_MYDP_SEL                        (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _DP12_33V_POWER                         0
#define _MYDP_5V_POWER                          1

#define PCB_D0_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD0_D12_MYDP_SEL = (x);\
                                                }

#define PCB_D1_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD1_D12_MYDP_SEL = (x);\
                                                }

#define PCB_D2_DP12_MYDP_POWER_SELECT(x)        {\
                                                    bD2_D12_MYDP_SEL = (x);\
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

#define PCB_D0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D2_EDID_EEPROM_WRITE_PROTECT(x)     {\
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

#define bD2_DP_PIN15_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_DP_PIN16_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_DP_PIN17_CONNECT                    (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

// For DP Type-C
#define bD0_USB_TYPEC_AUXP_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_USB_TYPEC_AUXN_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD1_USB_TYPEC_AUXP_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_USB_TYPEC_AUXN_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bD2_USB_TYPEC_AUXP_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_USB_TYPEC_AUXN_CONNECT              (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define bA0_CONNECT                             (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_CONNECT                             (((bit)bD0_DP_PIN15_CONNECT == _TRUE) && ((bit)bD0_DP_PIN16_CONNECT == _TRUE) && ((bit)bD0_DP_PIN17_CONNECT == _FALSE))
#define bD1_CONNECT                             (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))
#define bD2_CONNECT                             (((bit)bD2_DP_PIN15_CONNECT == _TRUE) && ((bit)bD2_DP_PIN16_CONNECT == _TRUE) && ((bit)bD2_DP_PIN17_CONNECT == _FALSE))

// For DP Type-C
#define bD0_CONNECT                             (((bit)bD0_USB_TYPEC_AUXP_CONNECT == _TRUE) && ((bit)bD0_USB_TYPEC_AUXN_CONNECT == _FALSE))
#define bD1_CONNECT                             (((bit)bD1_USB_TYPEC_AUXP_CONNECT == _TRUE) && ((bit)bD1_USB_TYPEC_AUXN_CONNECT == _FALSE))
#define bD2_CONNECT                             (((bit)bD2_USB_TYPEC_AUXP_CONNECT == _TRUE) && ((bit)bD2_USB_TYPEC_AUXN_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)
#define PCB_D2_PIN()                            (bD2_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_DP_PIN17_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)
#define GET_PCB_D2_DP_SOURCE_POWER()            (bD2_DP_PIN17_CONNECT)

// For DP Type-C
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_USB_TYPEC_AUXN_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_USB_TYPEC_AUXN_CONNECT)
#define GET_PCB_D2_DP_SOURCE_POWER()            (bD2_USB_TYPEC_AUXN_CONNECT)

//-----------------------------------------------
// Macro of MHL Cable Connect
//-----------------------------------------------
#define bD0_MHL_CONNECT                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_MHL_CONNECT                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_MHL_CONNECT                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define PCB_D0_MHL_DETECT()                     (bD0_MHL_CONNECT)
#define PCB_D1_MHL_DETECT()                     (bD1_MHL_CONNECT)
#define PCB_D2_MHL_DETECT()                     (bD2_MHL_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_HPD                                 (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _D0_HOT_PLUG_HIGH                       1
#define _D0_HOT_PLUG_LOW                        0

#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0

#define _D2_HOT_PLUG_HIGH                       1
#define _D2_HOT_PLUG_LOW                        0

#define PCB_D0_HOTPLUG(x)                       {\
                                                    bD0_HPD = (x);\
                                                }

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = (x);\
                                                }

#define PCB_D2_HOTPLUG(x)                       {\
                                                    bD2_HPD = (x);\
                                                }

#define PCB_D0_HOTPLUG_DETECT()                 (bD0_HPD)
#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)
#define PCB_D2_HOTPLUG_DETECT()                 (bD2_HPD)


///////////////
// MHL Macro //
///////////////

//-----------------------------------------------
// Macro of HDMI/MHL Switch
//-----------------------------------------------
#define bD0_TMDS_SWITCH                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_TMDS_SWITCH                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_TMDS_SWITCH                         (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _TMDS_SWITCH_MHL_CBUS                   0
#define _TMDS_SWITCH_HDMI_HPD                   1

#define PCB_D0_HDMI_MHL_SWITCH(x)               {\
                                                    bD0_TMDS_SWITCH = (x);\
                                                }

#define PCB_D1_HDMI_MHL_SWITCH(x)               {\
                                                    bD1_TMDS_SWITCH = (x);\
                                                }

#define PCB_D2_HDMI_MHL_SWITCH(x)               {\
                                                    bD2_TMDS_SWITCH = (x);\
                                                }

//-----------------------------------------------
// Macro of MHL VBus Switch
//-----------------------------------------------
#define bD0_MHL_VBUS_SWITCH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_MHL_VBUS_SWITCH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_MHL_VBUS_SWITCH                     (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _MHL_VBUS_ON                            1
#define _MHL_VBUS_OFF                           0

#define PCB_D0_MHL_VBUS_SWITCH(x)               {\
                                                    bD0_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_D1_MHL_VBUS_SWITCH(x)               {\
                                                    bD1_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_D2_MHL_VBUS_SWITCH(x)               {\
                                                    bD2_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_GET_D0_MHL_VBUS_SWITCH()            (bD0_MHL_VBUS_SWITCH)
#define PCB_GET_D1_MHL_VBUS_SWITCH()            (bD1_MHL_VBUS_SWITCH)
#define PCB_GET_D2_MHL_VBUS_SWITCH()            (bD2_MHL_VBUS_SWITCH)

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
#define bD0_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD0_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD1_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_EXT_SWITCH_EDID_0                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_EXT_SWITCH_EDID_1                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)
#define bD2_EXT_SWITCH_EDID_2                   (MCU_EMPTY_PIN_ASSIGN_ADDRESS)

#define _EEPROM_EDID_ENABLE                     0
#define _EEPROM_EDID_DISABLE                    1

#define PCB_D0_EXT_EDID_0_SWITCH(x)             {\
                                                    bD0_EXT_SWITCH_EDID_0 = (x);\
                                                }

#define PCB_D0_EXT_EDID_1_SWITCH(x)             {\
                                                    bD0_EXT_SWITCH_EDID_1 = (x);\
                                                }

#define PCB_D0_EXT_EDID_2_SWITCH(x)             {\
                                                    bD0_EXT_SWITCH_EDID_2 = (x);\
                                                }

#define PCB_D1_EXT_EDID_0_SWITCH(x)             {\
                                                    bD1_EXT_SWITCH_EDID_0 = (x);\
                                                }

#define PCB_D1_EXT_EDID_1_SWITCH(x)             {\
                                                    bD1_EXT_SWITCH_EDID_1 = (x);\
                                                }

#define PCB_D1_EXT_EDID_2_SWITCH(x)             {\
                                                    bD1_EXT_SWITCH_EDID_2 = (x);\
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

#endif // End of #if(_PCB_TYPE == _RL6369_PCB_EXAMPLE_128_PIN)
