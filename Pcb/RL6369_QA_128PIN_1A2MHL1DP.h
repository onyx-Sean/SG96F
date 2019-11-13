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
// ID Code      : RL6369_QA_128PIN_1A2MHL1DP.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6369_QA_128PIN_1A2MHL1DP)


///////////////////
// External Xtal //
///////////////////

//--------------------------------------------------
// External Xtal Define
//--------------------------------------------------
#define _EXT_XTAL                               _XTAL14318K


///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// A0 Input Port
//--------------------------------------------------
#define _A0_INPUT_PORT_TYPE                     _A0_VGA_PORT
#define _A0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _A0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D0 Input Port
//--------------------------------------------------
#define _D0_INPUT_PORT_TYPE                     _D0_MHL_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0
#define _D0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D0_MHL_VERSION                         _MHL_VERSION_2_2
#define _D0_CBUS_CHANNEL_SEL                    _CBUS1
#define _D0_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_256
#define _D0_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_MHL_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D1_MHL_VERSION                         _MHL_VERSION_2_2
#define _D1_CBUS_CHANNEL_SEL                    _CBUS0
#define _D1_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_256
#define _D1_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D2 Input Port
//--------------------------------------------------
#define _D2_INPUT_PORT_TYPE                     _D2_DP_PORT
#define _D2_DDC_CHANNEL_SEL                     _DDC2
#define _D2_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_256
#define _D2_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#define _D2_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED_270MHZ
#define _D2_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _D1_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _D2_INPUT_PORT


////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Port Config
//--------------------------------------------------
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_AB
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _ENABLE

//--------------------------------------------------
// LVDS Driving Config
//--------------------------------------------------
#define _LVDS_DRIV_CONTROL                      _LVDS_DRIV_CONTROL_3_0
#define _LVDS_VCM_CONTROL                       _LVDS_VCM_NORMAL
#define _LVDS_SR_CONTROL                        _LVDS_SR_CONTROL_0
#define _LVDS_PRE_EMPHASIS_CONTROL              _LVDS_PRE_EMPHASIS_0
#define _LVDS_TERMINATION_CONTROL               _DISABLE

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

#define _BACKLIGHT_PWM                          _PWM0
#define _BACKLIGHT_PWM_INVERSE                  _ON

#define _PWM0_EN                                _ON
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

#define _PWM0_RST_BY_DVS                        _ON
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

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24LC16
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_37_38


//////////
// Misc //
//////////

//--------------------------------------------------
// AD Key Option
//--------------------------------------------------
#define _AD_KEY_SUPPORT                         _ON

//--------------------------------------------------
// Low Speed ADC Option
//--------------------------------------------------
#define _LOW_SPEED_ADC_SUPPORT                  _ON


/////////////////////////////
// RL6369 Series Pin Share //
/////////////////////////////

//--------------------------------------------------
//  RL6369 76 Pin Share
//--------------------------------------------------
// eCBUS/HDMI_HPD_1
#define _PIN_21                                 (2 & 0x0F) // Page 10-0x00[3:0]
// 0 ~ 15 (0: P1d0i <I> , 1: P1d0o <PP>, 2: P1d0o <OD>, 3: CLKO , 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15: Test4b_out3)

// CBUS/HDMI_HPD_0
#define _PIN_22                                 (2 & 0x0F) // Page 10-0x01[3:0]
// 0 ~ 15 (0: P1d1i <I> , 1: P1d1o <PP>, 2: P1d1o <OD>, 3~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15: Test4b_out3)

// HDMI_MHL_SEL_1
#define _PIN_34                                 (2 & 0x0F) // Page 10-0x02[3:0]
// 0 ~ 15 (0: P1d2i <I> , 1: P1d2o <PP>, 2: P1d2o <OD>, 3: PWM0<PP> , 4: PWM0<OD>, 5: IIS_MCK, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// MHL_DETECT_1
#define _PIN_35                                 (0 & 0x0F) // Page 10-0x03[3:0]
// 0 ~ 15 (0: P1d3i <I> , 1: P1d3o <PP>, 2: P1d3o <OD>, 3: PWM1<PP> , 4: PWM1<OD>, 5: IIS_SCK, 6:IRQB, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// HDMI_CABLE_DETECT_1
#define _PIN_36                                 (0 & 0x0F) // Page 10-0x04[3:0]
// 0 ~ 15 (0: P1d4i <I> , 1: P1d4o <PP>, 2: P1d4o <OD>, 3: PWM2<PP> , 4: PWM2<OD>, 5: IIS_WS, 6: Tcon[13], 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// EESCL
#define _PIN_37                                 (7 & 0x0F) // Page 10-0x05[3:0]
// 0 ~ 15 (0: P1d5i <I> , 1: P1d5o <PP>, 2: P1d5o <OD>, 3: PWM3<PP> , 4: PWM3<OD>, 5: IIS_SD0, 6: Spdif0, 7: IICSCL0, 8: Rxd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// EESDA
#define _PIN_38                                 (7 & 0x0F) // Page 10-0x06[3:0]
// 0 ~ 15 (0: P1d6i <I> , 1: P1d6o <PP>, 2: P1d6o <OD>, 3: PWM4<PP> , 4: PWM4<OD>, 5: IIS_SD1, 6: Spdif1, 7: IICSDA0, 8: Txd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// VBUS_EN_1
#define _PIN_39                                 (1 & 0x0F) // Page 10-0x07[3:0]
// 0 ~ 15 (0: P1d7i <I> , 1: P1d7o <PP>, 2: P1d7o <OD>, 3: PWM5<PP> , 4: PWM5<OD>, 5: IIS_SD2, 6: Spdif2, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// ADC_KEY1
#define _PIN_42                                 (3 & 0x0F) // Page 10-0x08[3:0]
// 0 ~ 15 (0: P3d0i <I> , 1: P3d0o <PP>, 2: P3d0o <OD>, 3: A-adc0, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// ADC_KEY2
#define _PIN_43                                 (3 & 0x0F) // Page 10-0x09[3:0]
// 0 ~ 15 (0: P3d1i <I> , 1: P3d1o <PP>, 2: P3d1o <OD>, 3: A-adc1, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// KEYPAD_LED2
#define _PIN_44                                 (1 & 0x0F) // Page 10-0x0A[3:0]
// 0 ~ 15 (0: P3d2i <I> , 1: P3d2o <PP>, 2: P3d2o <OD>, 3: A-adc2, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// HDMI_CABLE_DETECT_0
#define _PIN_45                                 (0 & 0x0F) // Page 10-0x0B[3:0]
// 0 ~ 15 (0: P3d3i <I> , 1: P3d3o <PP>, 2: P3d3o <OD>, 3: A-adc3, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// MHL_DETECT_0
#define _PIN_46                                 (0 & 0x0F) // Page 10-0x0C[3:0]
// 0 ~ 15 (0: P3d4i <I> , 1: P3d4o <PP>, 2: P3d4o <OD>, 3: PWM1<PP>, 4: PWM1<OD>, 5: PWM5<PP> , 6: PWM5<OD>, 7: Tcon[7], 8: Tcon[13], 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// VGA_CABLE_DET
#define _PIN_47                                 (0 & 0x0F) // Page 10-0x0D[3:0]
// 0 ~ 15 (0: P3d5i <I> , 1: P3d5o <PP>, 2: P3d5o <OD>, 3: Tcon[8] ,4: Tcon[12], 5~6: reserved, 7: IICSCL1, 8: IICSCL_AUX, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// KEYPAD_LED1
#define _PIN_48                                 (1 & 0x0F) // Page 10-0x0E[3:0]
// 0 ~ 15 (0: P3d6i <I> , 1: P3d6o <PP>, 2: P3d6o <OD>, 3~6: reserved, 7: IICSDA1, 8: IICSDA_AUX, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSCL_VGA
#define _PIN_49                                 (7 & 0x0F) // Page 10-0x0F[3:0]
// 0 ~ 15 (0: P3d7i <I> , 1: P3d7o <PP>, 2: P3d7o <OD>, 3~6: reserved, 7: DDCSCLVGA, 8: RXD, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSDA_VGA
#define _PIN_50                                 (7 & 0x0F) // Page 10-0x10[3:0]
// 0 ~ 15 (0: P4d0i <I> , 1: P4d0o <PP>, 2: P4d0o <OD>, 3: Tcon[11] ,4: Tcon[13], 5~6: reserved, 7: DDCSDAVGA, 8: TXD, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// ADJBACKLITE
#define _PIN_52                                 (3 & 0x0F) // Page 10-0x11[3:0]
// 0 ~ 15 (0: P4d1i <I> , 1: P4d1o <PP>, 2: P4d1o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: IIS_SD3, 6: Spdif3, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// onBACKLITE
#define _PIN_53                                 (2 & 0x0F) // Page 10-0x12[3:0]
// 0 ~ 15 (0: P4d2i <I> , 1: P4d2o <PP>, 2: P4d2o <OD>, 3: PWM3<PP>, 4: PWM3<OD>, 5:PWM4<PP> , 6:PWM4<OD>, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// LINE_INL
#define _PIN_55                                 (6 & 0x0F) // Page 10-0x13[3:0]
// 0 ~ 15 (0: P4d3i <I> , 1: P4d3o <PP>, 2: P4d3o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: IIS_MCK, 6: Line_inl, 7~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// LINE_INR
#define _PIN_56                                 (4 & 0x0F) // Page 10-0x14[3:0]
// 0 ~ 15 (0: P4d4i <I> , 1: P4d4o <PP>, 2: P4d4o <OD>, 3: IIS_SCK, 4: Line_inr, 5~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// Audio_ref
#define _PIN_57                                 (4 & 0x0F) // Page 10-0x15[3:0]
// 0 ~ 15 (0: P4d5i <I> , 1: P4d5o <PP>, 2: P4d5o <OD>, 3: IIS_WS, 4: Audio_ref, 5: Tcon[13] , 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// AUDIO_SOUTL
#define _PIN_58                                 (5 & 0x0F) // Page 10-0x16[3:0]
// 0 ~ 15 (0: P4d6i <I> , 1: P4d6o <PP>, 2: P4d6o <OD>, 3: IIS_SD0, 4: Spdif0, 5: Soutl, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// AUDIO_SOUTR
#define _PIN_59                                 (5 & 0x0F) // Page 10-0x17[3:0]
// 0 ~ 15 (0: P4d7i <I> , 1: P4d7o <PP>, 2: P4d7o <OD>, 3: IIS_SD1, 4: Spdif1, 5: Soutr, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// AUDIO_HOUTL
#define _PIN_60                                 (5 & 0x0F) // Page 10-0x18[3:0]
// 0 ~ 15 (0: P5d0i <I> , 1: P5d0o <PP>, 2: P5d0o <OD>, 3: IIS_SD2, 4: Spdif2, 5: Houtl, 6: reserved, 7: IICSCL2, 8:Rxd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// AUDIO_HOUTR
#define _PIN_61                                 (5 & 0x0F) // Page 10-0x19[3:0]
// 0 ~ 15 (0: P5d1i <I> , 1: P5d1o <PP>, 2: P5d1o <OD>, 3: IIS_SD3, 4: Spdif3, 5: Houtr, 6: reserved, 7: IICSDA2, 8: Txd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// HDMI_MHL_SEL_0
#define _PIN_63                                 (2 & 0x0F) // Page 10-0x1B[3:0]
// 0 ~ 15 (0: P5d3i <I> , 1: P5d3o <PP>, 2: P5d3o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: PWM3<PP>, 6: PWM3<PP>, 7: Tcon[7], 8: Int1, 9: T2, 10: IHS_after_scaling_down, 11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// VBUS_EN_0
#define _PIN_64                                 (1 & 0x0F) // Page 10-0x1A[3:0]
// 0 ~ 15 (0: P5d2i <I> , 1: P5d2o <PP>, 2: P5d2o <OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: Tcon[8], 6: Int0, 7: IENA_after_scaling_down, 8: CLKO, 9~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD4P
#define _PIN_65                                 (4 & 0x0F) // Page 10-0x1C[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d4i <I>, 2: P5d4o <PP>, 3: P5d4o <OD>, 4: TXO4+_10b, 5: TTL_BLU7, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD4N
#define _PIN_66                                 (4 & 0x0F) // Page 10-0x1D[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d5i <I>, 2: P5d5o <PP>, 3: P5d5o <OD>, 4: TXO4-_10b, 5: TTL_BLU6, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD3P
#define _PIN_67                                 (4 & 0x0F) // Page 10-0x1E[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d6i <I>, 2: P5d6o <PP>, 3: P5d6o <OD>, 4: TXO3+_8b_10b, 5: TTL_BLU5, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD3N
#define _PIN_68                                 (4 & 0x0F) // Page 10-0x1F[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d7i <I>, 2: P5d7o <PP>, 3: P5d7o <OD>, 4: TXO3-_8b_10b, 5: TTL_BLU4, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD2P
#define _PIN_69                                 (4 & 0x0F) // Page 10-0x20[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d0i <I>, 2: P6d0o <PP>, 3: P6d0o <OD>, 4: TXO2+_8b_10b, 5: TTL_BLU3, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD2N
#define _PIN_70                                 (4 & 0x0F) // Page 10-0x21[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d1i <I>, 2: P6d1o <PP>, 3: P6d1o <OD>, 4: TXO2-_8b_10b, 5: TTL_BLU2, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD1P
#define _PIN_71                                 (4 & 0x0F) // Page 10-0x22[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d2i <I>, 2: P6d2o <PP>, 3: P6d2o <OD>, 4: TXO1+_8b_10b, 5: TTL_BLU1, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD1N
#define _PIN_72                                 (4 & 0x0F) // Page 10-0x23[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d3i <I>, 2: P6d3o <PP>, 3: P6d3o <OD>, 4: TXO1-_8b_10b, 5: TTL_BLU0, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD0P
#define _PIN_73                                 (4 & 0x0F) // Page 10-0x24[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d4i <I>, 2: P6d4o <PP>, 3: P6d4o <OD>, 4:TXO0+_8b_10b, 5:TTL_GRN7, 6~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXD0N
#define _PIN_74                                 (4 & 0x0F) // Page 10-0x25[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d5i <I>, 2: P6d5o <PP>, 3: P6d5o <OD>, 4: TXO0-_8b_10b, 5: TTL_GRN6, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXC4P
#define _PIN_77                                 (4 & 0x0F) // Page 10-0x26[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d6i <I>, 2: P6d6o <PP>, 3: P6d6o <OD>, 4: TXE4+_10b, 5: TTL_GRN5, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXC4N
#define _PIN_78                                 (4 & 0x0F) // Page 10-0x27[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d7i <I>, 2: P6d7o <PP>, 3: P6d7o <OD>, 4: TXE4-_10b, 5: TTL_GRN4, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// FLASH_WP
#define _PIN_96                                 (1 & 0x0F) // Page 10-0x28[3:0]
// 0 ~ 15 (0: P7d0i <I> , 1: P7d0o <PP>, 2: P7d0o <OD>, 3: Int0, 4: TTL_RED1, 5~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// Panel_ON
#define _PIN_97                                 (2 & 0x0F) // Page 10-0x29[3:0]
// 0 ~ 15 (0: P7d1i <I> , 1: P7d1o <PP>, 2: P7d1o <OD>, 3: Int1, 4: Tcon[11], 5: Reserved, 6: IVS_after_scaling_down,7: TTL_RED0, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DP_HOT_PLUG
#define _PIN_98                                 (1 & 0x0F) // Page 10-0x2A[3:0]
// 0 ~ 15 (0: P7d2i <I> , 1: P7d2o <PP>, 2: P7d2o <OD>, 3: T0, 4: DENA , 5: Tcon[9], 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DP_CABLE_DET_1
#define _PIN_99                                 (0 & 0x0F) // Page 10-0x2B[3:0]
// 0 ~ 15 (0: P7d3i <I> , 1: P7d3o <PP>, 2: P7d3o <OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: PWM3<PP>, 6: PWM3<OD>, 7: T1, 8: DHS, 9: Tcon[13] 10~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DP_SINK_ASS_N1
#define _PIN_100                                (0 & 0x0F) // Page 10-0x2C[3:0]
// 0 ~ 15 (0: P7d4i <I> , 1: P7d4o <PP>, 2: P7d4o <OD>, 3: Aux_d2, 4: DCLK , 5: Tcon[8] , 6: Pwm_in , 7:T2EX , 8~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DP_SINK_ASS_P1
#define _PIN_101                                (0 & 0x0F) // Page 10-0x2D[3:0]
// 0 ~ 15 (0: P7d5i <I> , 1: P7d5o <PP>, 2: P7d5o <OD>, 3: PWM4<PP>, 4: PWM4<OD>, 5: Aux_d1, 6: DVS, 7: Tcon[7], 8: Pwm_out, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSCL_0
#define _PIN_110                                (7 & 0x0F) // Page 10-0x2E[3:0]
// 0 ~ 15 (0: P7d6i <I> , 1: P7d6o <PP>, 2: P7d6o <OD>, 3: PWM4<PP>, 4: PWM4<OD>, 5: Auxp, 6: reserved, 7: DDCSCL0, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSDA_0
#define _PIN_111                                (7 & 0x0F) // Page 10-0x2F[3:0]
// 0 ~ 15 (0: P7d7i <I> , 1: P7d7o <PP>, 2: P7d7o <OD>, 3: PWM5<PP>, 4: PWM5<OD>, 5: Auxn, 6: reserved, 7: DDCSDA0, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSCL_1
#define _PIN_112                                (7 & 0x0F) // Page 10-0x30[3:0]
// 0 ~ 15 (0: P8d0i <I> , 1: P8d0o <PP>, 2: P8d0o <OD>, 3:Auxp, 4~6:reserved, 7:  DDCSCL1, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSDA_1
#define _PIN_113                                (7 & 0x0F) // Page 10-0x31[3:0]
// 0 ~ 15 (0: P8d1i <I> , 1: P8d1o <PP>, 2: P8d1o <OD>, 3:Auxn, 4~6:reserved, 7: DDCSDA1, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// AUX_CHP
#define _PIN_114                                (3 & 0x0F) // Page 10-0x33[3:0]
// 0 ~ 15 (0: P8d3i <I> , 1: P8d3o <PP>, 2: P8d3o <OD>, 3: Auxp, 4~6: reserved, 7:  DDCSCL2, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// AUX_CHN
#define _PIN_115                                (3 & 0x0F) // Page 10-0x32[3:0]
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


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_FE19_PORT71_PIN_REG) // Pin_97, P7.1

#define _PANEL_CONTROL_ON                       0
#define _PANEL_CONTROL_OFF                      1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_FE02_PORT42_PIN_REG) // Pin_53, P4.2

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
#define bFLASH_WRITE_PROTECT                    (MCU_FE18_PORT70_PIN_REG)  // Pin_96, P7.0

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_FE01_PORT41_PIN_REG) // Pin_52, P4.1

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


////////////////////////
// Cable Status Macro //
////////////////////////

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------
#define bD2_DP_PIN15_CONNECT                    (MCU_FE1D_PORT75_PIN_REG) // Pin_101, P7.5
#define bD2_DP_PIN16_CONNECT                    (MCU_FE1B_PORT73_PIN_REG) // Pin_99, P7.3
#define bD2_DP_PIN17_CONNECT                    (MCU_FE1C_PORT74_PIN_REG) // Pin_100, P7.4

#define bA0_CONNECT                             (P3_5) // Pin_47, P3.5
#define bD0_CONNECT                             (P3_3) // Pin_45, P3.3
#define bD1_CONNECT                             (P1_4) // Pin_36, P1.4
#define bD2_CONNECT                             (((bit)bD2_DP_PIN15_CONNECT == _TRUE) && ((bit)bD2_DP_PIN16_CONNECT == _TRUE) && ((bit)bD2_DP_PIN17_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)
#define PCB_D2_PIN()                            (bD2_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D2_DP_SOURCE_POWER()            (bD2_DP_PIN17_CONNECT)

//-----------------------------------------------
// Macro of MHL Cable Connect
//-----------------------------------------------
#define bD0_MHL_CONNECT                         (P3_4) // Pin_46, P3.4
#define bD1_MHL_CONNECT                         (P1_3) // Pin_35, P1.3

#define PCB_D0_MHL_DETECT()                     (bD0_MHL_CONNECT)
#define PCB_D1_MHL_DETECT()                     (bD1_MHL_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (P1_1) // Pin_22, P1.1
#define bD1_HPD                                 (P1_0) // Pin_21, P1.0
#define bD2_HPD                                 (MCU_FE1A_PORT72_PIN_REG) // Pin_98, P7.2

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
#define bD0_TMDS_SWITCH                         (MCU_FE0B_PORT53_PIN_REG) // Pin_63, P5.3
#define bD1_TMDS_SWITCH                         (P1_2) // Pin_34, P1.2

#define _TMDS_SWITCH_MHL_CBUS                   0
#define _TMDS_SWITCH_HDMI_HPD                   1

#define PCB_D0_HDMI_MHL_SWITCH(x)               {\
                                                    bD0_TMDS_SWITCH = (x);\
                                                }

#define PCB_D1_HDMI_MHL_SWITCH(x)               {\
                                                    bD1_TMDS_SWITCH = (x);\
                                                }

//-----------------------------------------------
// Macro of MHL VBus Switch
//-----------------------------------------------
#define bD0_MHL_VBUS_SWITCH                     (MCU_FE0A_PORT52_PIN_REG) // Pin_64, P5.2
#define bD1_MHL_VBUS_SWITCH                     (P1_7) // Pin_39, P1.7

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

#define PCB_GET_D0_MHL_VBUS_SWITCH()            (bD0_MHL_VBUS_SWITCH)
#define PCB_GET_D1_MHL_VBUS_SWITCH()            (bD1_MHL_VBUS_SWITCH)

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


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (P3_6) // Pin_48, P3.6
#define bLED2                                   (P3_2) // Pin_44, P3.2

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_IDLE()                          {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_ON;\
                                                    bLED2 = _LED_ON;\
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_OFF;\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                    bLED1 = _LED_ON;\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                    bLED2 = _LED_ON;\
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
#define AD_KEY0                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT)
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT)

#define PCB_ADKEY0()                            (AD_KEY0)
#define PCB_ADKEY1()                            (AD_KEY1)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                    if((0 <= (ucV0)) && ((ucV0) < 0x20))\
                                                    {\
                                                        (ucKeyState) |= _LEFT_KEY_MASK;\
                                                    }\
                                                    if((0x40 <= (ucV0)) && ((ucV0) < 0x80))\
                                                    {\
                                                        (ucKeyState) |= _RIGHT_KEY_MASK;\
                                                    }\
                                                    if((0x90 <= (ucV0)) && ((ucV0) < 0xE0))\
                                                    {\
                                                        (ucKeyState) |= _EXIT_KEY_MASK;\
                                                    }\
                                                    if((0 <= (ucV1)) && ((ucV1) < 0x20))\
                                                    {\
                                                        (ucKeyState) |= _POWER_KEY_MASK;\
                                                    }\
                                                    if((0x40 <= (ucV1)) && ((ucV1) < 0x80))\
                                                    {\
                                                        (ucKeyState) |= _MENU_KEY_MASK;\
                                                    }\
                                                    if((0x90 <= (ucV1)) && ((ucV1) < 0xE0))\
                                                    {\
                                                        (ucKeyState) |= _EXIT_KEY_MASK;\
                                                    }\
                                                }



#define bEEPROM_WRITE_PROTECT                   (P1_2) // Pin_34, P1.2

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)


#endif // End of #if(_PCB_TYPE == _RL6369_QA_128PIN_1A2MHL1DP)
