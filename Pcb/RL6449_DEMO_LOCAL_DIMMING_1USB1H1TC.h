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
// ID Code      : RL6449_DEMO_LOCAL_DIMMING_1USB1H1TC.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6449_DEMO_LOCAL_DIMMING_1USB1H1TC)


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
#define _PCB_DEBUG_DDC                          _DDC2


#define _D0_INPUT_PORT_NAME                     _U_,_S_,_B_,_,_T_,_y_,_p_,_e_,_SLINE_,_C_
#define _D3_INPUT_PORT_NAME                     _H_,_D_,_M_,_I_


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
#define _D0_INPUT_PORT_TYPE                     _D0_DP_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0
#define _D0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_256
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_TYPEC// _DP_CONNECTOR_NORMAL
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D0_DP_MAIN_LINK_LANES                  _DP_TWO_LANE//  _DP_FOUR_LANE //

#define _D0_DP_TYPE_C_PORT_CTRL_TYPE            _PORT_CONTOLLER_USER

//--------------------------------------------------
// D3 Input Port
//--------------------------------------------------
#define _D3_INPUT_PORT_TYPE                     _D3_HDMI_PORT
#define _D3_DDC_CHANNEL_SEL                     _DDC3
#define _D3_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D3_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER

// For HDMI MultiEdid
#define _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0   _EDID_SIZE_NONE
#define _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1   _EDID_SIZE_NONE
#define _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2   _EDID_NOT_EXIST


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_NONE
#define _D3_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _D0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D3_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _NO_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_4                _NO_INPUT_PORT

//--------------------------------------------------
// DP Lane & PN Swap Option
//--------------------------------------------------
#define _D0_DP_PCB_LANE0_MAPPING                _DP_SCALER_LANE2
#define _D0_DP_PCB_LANE1_MAPPING                _DP_SCALER_LANE3
#define _D0_DP_PCB_PN_SWAP                      _OFF
#define _D0_DP_PCB_LANE2_MAPPING                _DP_SCALER_LANE0
#define _D0_DP_PCB_LANE3_MAPPING                _DP_SCALER_LANE1


/////////////////////////
// eDPTx 1.1 HBR Panel //
/////////////////////////

//--------------------------------------------------
// eDPTx 1.1 HBR Main Link Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_FB_SWAP                 _DISABLE
#define _PANEL_DPTX_1_1_LANE_SWAP               _DISABLE
#define _PANEL_DPTX_1_1_LANE_PN_SWAP            _DISABLE
#define _PANEL_DPTX_1_1_SWING_LEVEL             _DP_SWING_800_MV
#define _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_0_DB

//--------------------------------------------------
// eDPTx 1.1 HBR SSC Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_SPREAD_RANGE            12
#define _PANEL_DPTX_1_1_SPREAD_SPEED            _SPEED_33K

//--------------------------------------------------
// Definitions of eDP Panel Power Sequence
//
// Panel On Sequence
//       _________       ________      ________
//       |       |       |      |      |      |
// ______|       |_______|      |______|      |______
//
//   Panel_On  HPD_ON    LT    IDLE   VIDEO  BL_ON
//
// Panel Off Sequence
//
//       _________
//       |       |
// ______|       |_______
//
//    BL_OFF    IDLE
//--------------------------------------------------
#define _DPTX_POWER_SEQUENCE_PANEL_ON           _HIGH
#define _DPTX_POWER_SEQUENCE_HPD_ON             _LOW
#define _DPTX_POWER_SEQUENCE_LINK_TRAINING      _HIGH
#define _DPTX_POWER_SEQUENCE_IDLE_PATTERN       _LOW
#define _DPTX_POWER_SEQUENCE_VIDEO_PATTERN      _HIGH
#define _DPTX_POWER_SEQUENCE_BACKLIGHT_ON       _LOW
#define _DPTX_POWER_SEQUENCE_BACKLIGHT_OFF      _HIGH




/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM5
#define _BACKLIGHT_PWM_INVERSE                  _ON

#define _PWM0_EN                                _ON
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _ON

#define _PWM0_PSAV_EN                           _ON
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
#define _PWM2_RST_BY_DVS                        _ON
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
#define _PWM5_RST_BY_DVS                        _ON
#define _PWM_RST_BY_TCON                        _OFF


/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// Sofware and Hardware IIC Option
//--------------------------------------------------
#define _SW_IIC_SUPPORT                         _ON
#define _SW_IIC_CLK_DIV                         _DIV_1

#define _HW_IIC_SUPPORT                         _ON
#define _HW_IIC_SPEED                           _HW_IIC_LOW_SPEED_100K


///////////////////
// System Eeprom //
///////////////////

//--------------------------------------------------
// Eeprom System Data Storage Option
//--------------------------------------------------
#define _EEPROM_TYPE                            _EEPROM_24WC64
#define _EEPROM_SLAVE_ADDRESS                   0xA0
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_210_211


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
// RL6449 Series Pin Share //
/////////////////////////////

//--------------------------------------------------
//  RL6449 216 Pin Share
//--------------------------------------------------
// HDMI1_HPD_CPU
#define _PIN_1                                  (2 & 0x0F) // Page 10-0x00[2:0]
// 0 ~ 2 (0: P1D0i<I>, 1: P1D0o<PP>, 2: P1D0o<OD> & d3_hdmi_hpd_int<I>)

// NC
#define _PIN_14                                 (1 & 0x0F) // Page 10-0x01[2:0]
// 0 ~ 2 (0: P1D1i<I>, 1: P1D1o<PP>, 2: P1D1o<OD> & d2_hdmi_hpd_int<I>)

// I2C_SCL_ISP
#define _PIN_65                                 (8 & 0x0F) // Page 10-0x02[2:0]
// 0 ~ 8 (0: P1D2i<I>, 1: P1D2o<PP>, 2: P1D2o<OD>, 8: ddcsclvga<OD>)

// I2C_SDA_ISP
#define _PIN_66                                 (8 & 0x0F) // Page 10-0x03[2:0]
// 0 ~ 8 (0: P1D3i<I>, 1: P1D3o<PP>, 2: P1D3o<OD>, 8: ddcsdavga<I>)

// GPIO_67_CPU_KEY_POWER
#define _PIN_67                                 (0 & 0x0F) // Page 10-0x04[2:0]
// 0 ~ 7 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>, 3: tcon[1],
//        4: test4b_out0, 5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

// DP_SINK_CPU_N
#define _PIN_68                                 (0 & 0x0F) // Page 10-0x05[2:0]
// 0 ~ 7 (0: P1D5i<I>, 1: P1D5o<PP>, 2: P1D5o<OD>,  3: tcon[3], 4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

// C_CABLE_DET_GPIO
#define _PIN_69                                 (0 & 0x0F) // Page 10-0x06[2:0]
// 0 ~ 7 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 3: tcon[0], 4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

// DP_SINK_CPU_P
#define _PIN_70                                 (0 & 0x0F) // Page 10-0x07[2:0]
// 0 ~ 7 (0: P1D7i<I>, 1: P1D7o<PP>, 2: P1D7o<OD>, 3: tcon[8], 4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

// NC
#define _PIN_71                                 (1 & 0x0F) // Page 10-0x08[2:0]
// 0 ~ 4 (0: P3D0i<I>, 1:P3D0o<PP>, 2: P3D0o<OD>, 3: tcon[4], 4: dptx_hpd_org<I>

// AUX_CHP_0
#define _PIN_74                                 (3 & 0x0F) // Page 10-0x09[2:0]
// 0 ~ 3 (0: P3D1i<I>, 1: Reserved, 2: P3D1o<OD>, 3: auxp0)

// AUX_CHN_0
#define _PIN_75                                 (3 & 0x0F) // Page 10-0x0A[2:0]
// 0 ~ 3 (0: P3D2i<I>, 1: Reserved, 2: P3D2o<OD>, 3: auxn0)

// NC
#define _PIN_76                                 (1 & 0x0F) // Page 10-0x0B[2:0]
// 0 ~ 3 (0: P3D3i<I>, 1: Reserved, 2: P3D3o<OD>, 3: auxp1)

// NC
#define _PIN_77                                 (1 & 0x0F) // Page 10-0x0C[2:0]
// 0 ~ 3 (0: P3D4i<I>, 1: Reserved, 2: P3D4o<OD>, 3: auxn1)

// I2C_1_SCL_EC
#define _PIN_91                                 (2 & 0x0F) // Page 10-0x0D[2:0]
// 0 ~ 3 (0: P3D5i<I>, 1: P3D5o<PP>, 2: P3D5o<OD>, 3: dptx_aux_ch_p)

// I2C_1_SDA_EC
#define _PIN_92                                 (2 & 0x0F) // Page 10-0x0E[2:0]
// 0 ~ 3 (0: P3D6i<I>, 1: P3D6o<PP>, 2: P3D6o<OD>, 3: dptx_aux_ch_n)

// GPIO_94_CPU_KEY1
#define _PIN_94                                 (3 & 0x0F) // Page 10-0x0F[2:0]
// 0 ~ 6 (0: P3D7i<I>, 1: P3D7o<PP>, 2: P3D7o<OD>, 3: a_adc0_0, 4: int0,
//        5: test4b_out0 , 6:test4b_out1)

// GPIO_95_CPU_KEY2
#define _PIN_95                                 (3 & 0x0F) // Page 10-0x10[2:0]
// 0 ~ 6 (0: P4D0i<I>, 1: P4D0o<PP>, 2: P4D0o<OD>, 3: a_adc1_0, 4: int1,
//        5: test4b_out2 , 6:test4b_out3)

// DP_HPD_CPU
#define _PIN_96                                 (1 & 0x0F) // Page 10-0x11[2:0]
// 0 ~ 6 (0: P4D1i<I>, 1: P4D1o<PP>, 2: P4D1o<OD>,  3: a_adc2_0, 4: tcon[9],
//        5: test4b_out0 , 6:test4b_out1)

// GPIO_97_CPU_LED_WHITE
#define _PIN_97                                 (1 & 0x0F) // Page 10-0x12[2:0]
// 0 ~ 6 (0: P4D2i<I>, 1: P4D2o<PP>, 2: P4D2o<OD>, 3: a_adc3_0, 4: tcon[10],
//        5: test4b_out2 , 6:test4b_out3)

// NC
#define _PIN_109                                (1 & 0x0F) // Page 10-0x13[2:0]
// 0 ~ 5 (0: P4D3i<I>, 1: P4D3o<PP>, 2: P4D3o<OD>, 3: audio_houtl, 4: sd2, 5: spdif2)

// NC
#define _PIN_110                                (1 & 0x0F) // Page 10-0x14[2:0]
// 0 ~ 5 (0: P4D4i<I>, 1: P4D4o<PP>, 2: P4D4o<OD>, 3: audio_houtr, 4: sd3, 5: spdif3)

// NC
#define _PIN_113                                (1 & 0x0F) // Page 10-0x15[2:0]
// 0 ~ 4 (0: P4D5i<I>, 1: P4D5o<PP>, 2: P4D5o<OD>, 3: line_inl, 4: ws)

// NC
#define _PIN_114                                (1 & 0x0F) // Page 10-0x16[2:0]
// 0 ~ 4 (0: P4D6i<I>, 1: P4D6o<PP>, 2: P4D6o<OD>, 3: line_inr, 4: sck)

// AUDIO_REF
#define _PIN_115                                (3 & 0x0F) // Page 10-0x17[2:0]
// 0 ~ 4 (0: P4D7i<I>, 1: P4D7o<PP>, 2: P4D7o<OD>, 3: audio_ref, 4: mck)

// ANA_AUDOUT_AMP_L
#define _PIN_116                                (3 & 0x0F) // Page 10-0x18[2:0]
// 0 ~ 5 (0: P5D0i<I>, 1: P5D0o<PP>, 2: P5D0o<OD>, 3: audio_soutl, 4: sd0, 5: spdif0)

// ANA_AUDOUT_AMP_R
#define _PIN_117                                (3 & 0x0F) // Page 10-0x19[2:0]
// 0 ~ 5 (0: P5D1i<I>, 1: P5D1o<PP>, 2: P5D1o<OD>, 3: audio_soutr, 4: sd1, 5: spdif1)

// NC
#define _PIN_143                                (1 & 0x0F) // Page 10-0x1A[2:0]
// 0 ~ 3 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: dptx_aux_ch_p_2

// NC
#define _PIN_144                                (1 & 0x0F) // Page 10-0x1B[2:0]
// 0 ~ 3 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: dptx_aux_ch_n_2

// NC
#define _PIN_145                                (1 & 0x0F) // Page 10-0x1C[2:0]
// 0 ~ 4 (0: P5D4i<I>, 1: P5D4o<PP>, 2: P5D4o<OD>, 3: dptx_hpd2_org, 4: vb1_lock_n,

// eDP_AUX_CPU_P
#define _PIN_146                                (3 & 0x0F) // Page 10-0x1D[2:0]
// 0 ~ 3 (0: P5D5i<I>, 1: P5D5o<PP>, 2: P5D5o<OD>, 3: dptx_aux_ch_p_1

// eDP_AUX_CPU_N
#define _PIN_147                                (3 & 0x0F) // Page 10-0x1E[2:0]
// 0 ~ 3 (0: P5D6i<I>, 1: P5D6o<PP>,  2: P5D6o<OD>, 3: dptx_aux_ch_n_1)

// eDP_HPD_CPU
#define _PIN_148                                (3 & 0x0F) // Page 10-0x1F[2:0]
// 0 ~ 4 (0: P5D7i<I>, 1: P5D7o<PP>, 2: P5D7o<OD>, 3: dptx_hpd1_org,
//        4: vb1_htpd_n)

// NC
#define _PIN_149                                (1 & 0x0F) // Page 10-0x20[2:0]
// 0 ~ 8 (0: P6D0i<I>, 1: P6D0o<PP>, 2: P6D0o<OD>, 3: tcon[2], 8: iicscl1

// NC
#define _PIN_150                                (1 & 0x0F) // Page 10-0x21[2:0]
// 0 ~ 8 (0: P6D1i<I>, 1: P6D1o<PP>, 2: P6D1o<OD>, 3: pwm1<PP>, 4: pwm1<OD>,
//        8: iicsda1)

// NC
#define _PIN_151                                (1 & 0x0F) // Page 10-0x22[2:0]
// 0 ~ 5 (0: P6D2i<I>, 1: P6D2o<PP>, 2: P6D2o<OD>, 3: pwm2<PP>, 4: pwm2<OD>,
//        5: tcon[3])

// LOCAL_DIMMING_VSYNC
#define _PIN_152                                (3 & 0x0F) // Page 10-0x23[2:0]
// 0 ~ 7 (0: P6D3i<I>, 1: P6D3o<PP>, 2: P6D3o<OD>, 3: pwm5<PP>, 4: pwm5<OD>,
//        5: tcon[2],  6:test4b_out0, 7: test4b_out1)

// LOCAL_DIMMING_SPI_CLK
#define _PIN_153                                (8 & 0x0F) // Page 10-0x24[2:0]
// 0 ~ 8 (0: P6D4i<I>, 1: P6D4o<PP>, 2: P6D4o<OD>, 3: t0, 8: usb_spi_clk)

// LOCAL_DIMMING_SPI_SI
#define _PIN_154                                (8 & 0x0F) // Page 10-0x25[2:0]
// 0 ~ 8 (0: P6D5i<I>, 1: P6D5o<PP>, 2: P6D5o<OD>, 3: int0, 4: t1, 8: usb_spi_si)

// LOCAL_DIMMING_SPI_SO
#define _PIN_155                                (8 & 0x0F) // Page 10-0x26[2:0]
// 0 ~ 8 (0: P6D6i<I>, 1: P6D6o<PP>, 2: P6D6o<OD>, 3: int1, 4: t2, 8: usb_spi_so)

// LOCAL_DIMMING_SPI_CE
#define _PIN_156                                (8 & 0x0F) // Page 10-0x27[2:0]
// 0 ~ 8 (0: P6D7i<I>, 1: P6D7o<PP>, 2: P6D7o<OD>, 3: irqb, 4: ttl_dvs,
//        8: usb_spi_ceb0)

// NC
#define _PIN_157                                (8 & 0x0F) // Page 10-0x28[2:0]
// 0 ~ 8 (0: P7D0i<I>, 1: P7D0o<PP>, 2: P7D0o<OD>, 3: t2ex, 8: usb_spi_ceb1)

// GPIO_158_CPU_PANELVCC_EN
#define _PIN_158                                (1 & 0x0F) // Page 10-0x29[2:0]
// 0 ~ 6 (0: P7D1i<I>, 1: P7D1o<PP>, 2: P7D1o<OD>, 3:ws, 4: tcon[12], 5:test4b_out0
//        6: test4b_out1)

// NC
#define _PIN_159                                (1 & 0x0F) // Page 10-0x2A[2:0]
// 0 ~ 6 (0: P7D2i<I>, 1: P7D2o<PP>, 2: P7D2o<OD>, 3: sck, 4: tcon[13],
//        5: test4b_out2, 6: test4b_out3)

// NC
#define _PIN_160                                (1 & 0x0F) // Page 10-0x2B[2:0]
// 0 ~ 7 (0: P7D3i<I>, 1: P7D3o<PP>, 2: P7D3o<OD>, 3: mck, 4: test4b_out0,
//        5: test4b_out1, 6:test4b_out2, 7:test4b_out3)

// NC
#define _PIN_161                                (1 & 0x0F) // Page 10-0x2C[2:0]
// 0 ~ 6 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: pwm0<PP>, 4: pwm0<OD>,
//        5: spdif0, 6: sd0)

// NC
#define _PIN_163                                (1 & 0x0F) // Page 10-0x2D[2:0]
// 0 ~ 5 (0: P7D5i<I>, 1: P7D5o<PP>, 2: P7D5o<OD>, 3: tcon[5], 4: spdif1,
//        5: sd1)

// NC
#define _PIN_164                                (1 & 0x0F) // Page 10-0x2E[2:0]
// 0 ~ 6 (0: P7D6i<I>, 1: P7D6o<PP>, 2: P7D6o<OD>, 3: tcon[1], 4: spdif2,
//        5: sd2, 6: cryclk)

// NC
#define _PIN_165                                (1 & 0x0F) // Page 10-0x2F[2:0]
// 0 ~ 7 (0: P7D7i<I>, 1: P7D7o<PP>, 2: P7D7o<OD>, 3: tcon[6], 4: spdif3, 5: sd3,
//        6: disp_frame_start_in, 7: disp_frame_start_out)

// NC
#define _PIN_166                                (1 & 0x0F) // Page 10-0x30[2:0]
// 0 ~ 6 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: TCON[8], 6: m1_idomain_vs_out)

// 1D1V_OFF_EN_CPU VCCK_OFF_EN
#define _PIN_179                                (2 & 0x0F) // Page 10-0x31[2:0]
// 0 ~ 7 (0: P8D1i<I>, 1: P8D1o<PP>, 2: P8D1o<OD>, 3: ttl_dhs, 4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7:test4b_out3)

// GPIO_180_CPU_USB_EN
#define _PIN_180                                (1 & 0x0F) // Page 10-0x32[2:0]
// 0 ~ 7 (0: P8D2i<I>, 1: P8D2o<PP>, 2: P8D2o<OD>, 3: ttl_den, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// DDC_WPn_CPU
#define _PIN_181                                (1 & 0x0F) // Page 10-0x33[2:0]
// 0 ~ 7 (0: P8D3i<I>, 1: P8D3o<PP>, 2: P8D3o<OD>, 3: dclk, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// GPIO_184_CPU_LED_WHITE
#define _PIN_184                                (3 & 0x0F) // Page 10-0x34[2:0]
// 0 ~ 6 (0: P8D4i<I>, 1: P8D4o<PP>, 2: P8D4o<OD>, 3: pwm0<PP>, 4: pwm0<OD>,
//        5: tcon[11], 6: clko)

// GPIO_185_CPU_BLEN
#define _PIN_185                                (1 & 0x0F) // Page 10-0x35[2:0]
// 0 ~ 6 (0: P8D5i<I>, 1: P8D5o<PP>, 2: P8D5o<OD>, 3: pwm1<PP>, 4: pwm1<OD>,
//        5: tcon[7], 6: m1_idomain_den_out)

// SPI_WP_CPU
#define _PIN_190                                (1 & 0x0F) // Page 10-0x36[2:0]
// 0 ~ 2 (0: P8D6i<I>, 1: P8D6o<PP>, 2: P8D6o<OD>)

// GPIO_193_CPU_BLVCC_EN (BACKLIGHT 19V ENABLE)
#define _PIN_193                                (1 & 0x0F) // Page 10-0x37[2:0]
// 0 ~ 7 (0: P8D7i<I>, 1: P8D7o<PP>, 2: P8D7o<OD>, 3: Reserved,
//        4: Test4b_out0, 5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// GPIO_194_CPU_PD_EN
#define _PIN_194                                (1 & 0x0F) // Page 10-0x38[2:0]
// 0 ~ 6 (0: P9D0i<I>, 1: P9D0o<PP>, 2: P9D0o<OD>, 3: pwm2<PP>, 4: pwm2<PP>,
//        5: tcon[6], 6: irda_in)

// NC
#define _PIN_195                                (1 & 0x0F) // Page 10-0x39[2:0]
// 0 ~ 6 (0: P9D1i<I>, 1: P9D1o<PP>, 2: P9D1o<OD>, 3: PWM4<PP>, 4: PWM4<OD>
//        5: tcon[7], 6: pwm_out)

// NC
#define _PIN_196                                (1 & 0x0F) // Page 10-0x3A[2:0]
// 0 ~ 7 (0: P9D2i<I>, 1: P9D2o<PP>, 2: P9D2o<OD>, 3: tcon[5], 4: test4b_out0
//        5: test4b_out1, 6:test4b_out2, 7:test4b_out3)

// NC
#define _PIN_197                                (1 & 0x0F) // Page 10-0x3B[2:0]
// 0 ~ 7 (0: P9D3i<I>, 1: P9D3o<PP>, 2: P9D3o<OD>, 3: tcon[4], 4: test4b_out0
//        5: test4b_out1, 6:test4b_out2, 7:test4b_out3)

// HDMI1_EDID_HDR_E2
#define _PIN_198                                (1 & 0x0F) // Page 10-0x3C[2:0]
// 0 ~ 7 (0: P9D4i<I>, 1: P9D4o<PP>, 2: P9D4o<OD>, 3: m1_idomain_hs_out, 4: test4b_out0
//        5: test4b_out1, 6:test4b_out2, 7:test4b_out3)

// GPIO_199_CPU_MUTEN
#define _PIN_199                                (2 & 0x0F) // Page 10-0x3D[2:0]
// 0 ~ 5 (0: P9D5i<I>, 1: P9D5o<PP>, 2: P9D5o<OD>, 3: pwm5<PP>, 4: pwm5<OD>,
//        5: pwm_in)

// 1D8V_EN_CPU DDR_PW_EN
#define _PIN_200                                (2 & 0x0F) // Page 10-0x3E[2:0]
// 0 ~ 8 (0: P9D6i<I>, 1: P9D6o<PP>, 2: P9D6o<OD>, 3: pwm4<PP>, 4: pwm4<OD>
//        5: tcon[11], 8: iicscl2)

// CDP_AUTO
#define _PIN_201                                (2 & 0x0F) // Page 10-0x3F[2:0]
// 0 ~ 8 (0: P9D7i<I>, 1: P9D7o<PP>, 2: P9D7o<OD>, 3: pwm3<PP>, 4: pwm3<OD>
//        5: tcon[0], 8: iicsda2)

// BC_CHAR_EN
#define _PIN_202                                (2 & 0x0F) // Page 10-0x40[2:0]
// 0 ~ 8 (0: PAD0i<I>, 1: PAD0o<PP>, 2: PAD0o<OD>, 3: int0, 4: test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7:test4b_out3, 8: txd)

// PSID_DET
#define _PIN_203                                (2 & 0x0F) // Page 10-0x41[2:0]
// 0 ~ 8 (0: PAD1i<I>, 1: PAD1o<PP>, 2: PAD1o<OD>, 3: int1, 4: test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7:test4b_out3, 8: rxd)

// HDMI1_DET_CPU
#define _PIN_204                                (0 & 0x0F) // Page 10-0x42[2:0]
// 0 ~ 7 (0: PAD2i<I>, 1: PAD2o<PP>, 2: PAD2o<OD>, 3: tcon[13], 4: test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7:test4b_out3)

// 3D3V_USB_EN
#define _PIN_206                                (2 & 0x0F) // Page 10-0x43[2:0]
// 0 ~ 7 (0: PAD3i<I>, 1: PAD3o<PP>, 2: PAD3o<OD>, 3: tcon[12], 4: test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7:test4b_out3)

// TYPE_C_IRQ1
#define _PIN_207                                (0 & 0x0F) // Page 10-0x44[2:0]
// 0 ~ 7 (0: PAD4i<I>, 1: PAD4o<PP>, 2: PAD4o<OD>, 3: tcon[10], 4: test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7:test4b_out3)

// GPIO_208_CPU_AUDIO_DET
#define _PIN_208                                (0 & 0x0F) // Page 10-0x45[2:0]
// 0 ~ 7 (0: PAD5i<I>, 1: PAD5o<PP>, 2: PAD5o<OD>, 3: tcon[9], 4: test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7:test4b_out3)

// EEPROM_WPn_CPU
#define _PIN_209                                (2 & 0x0F) // Page 10-0x46[2:0]
// 0 ~ 2 (0: PAD6i<I>, 1: PAD6o<PP>, 2: PAD6o<OD>)

// EEPROM_SCL_CPU
#define _PIN_210                                (8 & 0x0F) // Page 10-0x47[2:0]
// 0 ~ 8 (0: PAD7i<I>, 1: PAD7o<PP>, 2: PAD7o<OD>, 8: eeiicscl)

// EEPROM_SDA_CPU
#define _PIN_211                                (8 & 0x0F) // Page 10-0x48[2:0]
// 0 ~ 8 (0: PBD0i<I>, 1: PBD0o<PP>, 2: PBD0o<OD>, 8: eeiicsda)

// I2C_DEBUG_SCL
#define _PIN_212                                (8 & 0x0F) // Page 10-0x49[2:0]
// 0 ~ 8 (0: PBD1i<I>, 1: Reserved, 2: PBD1o<OD>, 8: ddcscl2)

// I2C_DEBUG_SDA
#define _PIN_213                                (8 & 0x0F) // Page 10-0x4A[2:0]
// 0 ~ 8 (0: PBD2i<I>, 1: Reserved, 2: PBD2o<OD>, 8: ddcsda2)

// HDMI1_SCL_CPU
#define _PIN_214                                (8 & 0x0F) // Page 10-0x4B[2:0]
// 0 ~ 8 (0: PBD3i<I>, 1: Reserved, 2: PBD3o<OD>, 8: ddcscl3)

// HDMI1_SDA_CPU
#define _PIN_215                                (8 & 0x0F) // Page 10-0x4C[2:0]
// 0 ~ 8 (0: PBD4i<I>, 1: Reserved, 2: PBD4o<OD>, 8: ddcsda3 )


//////////////////////
// GPIO Power Macro //
//////////////////////

//-----------------------------------------------
// Macro of Pcb GPIO Inital Setting
//-----------------------------------------------
#define PCB_GPIO_ON_REGION_INITIAL_SETTING()    {\
                                                    PCB_AMP_MUTE(_AMP_MUTE_OFF);\
                                                    PCB_USB_HUB_POWER(_USB_HUB_POWER_OFF);\
                                                    _USB_PD_EN = _HIGH;\
                                                    bBACKLIGHTPOWER=_LIGHT_CONTROL_OFF;\
                                                }
/*PCB_AMP_MUTE(_AMP_MUTE_OFF);\*/
/*PCB_USB_5V_CONTROL(_USB_5V_ON);\*/

//-----------------------------------------------
// Power OFF Region GPIO Initial Setting
// PIN109-166
//-----------------------------------------------
#define PCB_GPIO_OFF_REGION_INITIAL_SETTING()   {\
                                                }

#define PCB_GPIO_SETTING_POWER_AC_ON()          {\
                                                    /*need enable Vsync for SPI communication*/\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 480);\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (0x30));\
                                                    /*need enable Vsync for SPI communication*/\
                                                    bBACKLIGHTBL3D3V =_ON;\
                                                    _nop_();\
                                                    _nop_();\
                                                    _nop_();\
                                                    _nop_();\
                                                    bBACKLIGHTVCC = _ON;\
                                                }

#define PCB_GPIO_SETTING_POWER_NORMAL()         {\
                                                    /*need enable Vsync for SPI communication*/\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 480);\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (0x30));\
                                                    /*need enable Vsync for SPI communication*/\
                                                    bBACKLIGHTBL3D3V =_ON;\
                                                    _nop_();\
                                                    _nop_();\
                                                    _nop_();\
                                                    _nop_();\
                                                    bBACKLIGHTVCC = _ON;\
                                                    /*_nop_();_nop_();_nop_();_nop_();*/\
                                                    /*bBACKLIGHTPOWER=_LIGHT_CONTROL_ON;*/\
                                                }

#define PCB_GPIO_SETTING_POWER_SAVING()         {\
                                                    bBACKLIGHTVCC = _OFF;\
                                                    ScalerTimerDelayXms(2);\
                                                    bBACKLIGHTPOWER=_LIGHT_CONTROL_OFF;\
                                                }

#define PCB_GPIO_SETTING_POWER_DOWN()           {\
                                                    bBACKLIGHTVCC = _OFF;\
                                                    ScalerTimerDelayXms(2);\
                                                    bBACKLIGHTPOWER=_LIGHT_CONTROL_OFF;\
                                                }


/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of VCCK_OFF Power Control
//-----------------------------------------------
#define bVCCKOFFPOWER                           (MCU_FE21_PORT81_PIN_REG) // _PIN_179,1D1V_OFF_EN_CPU, P8.1

#define _VCCK_OFF_POWER_ON                      1
#define _VCCK_OFF_POWER_OFF                     0

#define PCB_VCCK_OFF_POWER(x)                   {\
                                                    bVCCKOFFPOWER = (x);\
                                                }

//-----------------------------------------------
// Macro of DDR Poewr Control
//-----------------------------------------------
#define bDDRPOWER                               (MCU_FE2E_PORT96_PIN_REG) // _PIN_200,1D8V_EN_CPU, P9.6

#define _DDR_POWER_ON                           1
#define _DDR_POWER_OFF                          0

#define PCB_DDR_POWER(x)                        {\
                                                    bDDRPOWER = (x);\
                                                }

//-----------------------------------------------
// Macro of 12V to 5V Regulator for MyDP or MHL
//-----------------------------------------------
#define bREGULATOR_5V                           (MCU_FE22_PORT82_PIN_REG) // Pin_180, P8.2

#define _REGULATOR_5V_ON                        0
#define _REGULATOR_5V_OFF                       1

#define PCB_REGULATOR_5V_OUT(x)                 {\
                                                    bREGULATOR_5V = (x);\
                                                }


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_FE19_PORT71_PIN_REG) // _PIN_158,GPIO_158_CPU_PANELVCC_EN, P7.1

#define _PANEL_CONTROL_ON                       1
#define _PANEL_CONTROL_OFF                      0

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_FE25_PORT85_PIN_REG) // _PIN_185,GPIO_185_CPU_BLEN, P8.5
#define bBACKLIGHTVCC                           (MCU_FE27_PORT87_PIN_REG) // _PIN_193,GPIO_193_CPU_BLVCC_EN, P8.7
#define bBACKLIGHTBL3D3V                        (MCU_FE02_PORT42_PIN_REG) // _PIN_97,GPIO_97_CPU_BL3D3V_EN, P4.2

#define _LIGHT_CONTROL_ON                       1
#define _LIGHT_CONTROL_OFF                      0



extern void DeviceInterfaceLedDriverBacklightPowerPin(BYTE ucEnable);
extern void DeviceInterfaceLedDriverBacklightPower(BYTE ucEnable);

#if(_SPI_SUPPORT == _ON)
#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    DeviceInterfaceLedDriverBacklightPowerPin(x);\
                                                }

#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    DeviceInterfaceLedDriverBacklightPower(x);\
                                                }
#else
#define PCB_BACKLIGHT_POWER_PIN(x)              {\
                                                    bBACKLIGHTPOWER = (x);\
                                                }

#define PCB_BACKLIGHT_POWER(x)                  {\
                                                    if((x) == _LIGHT_CONTROL_ON)\
                                                    {\
                                                        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                        ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, (WORD)22000);\
                                                    }\
                                                    else\
                                                    {\
                                                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);\
                                                    }\
                                                    PCB_BACKLIGHT_POWER_PIN(x)\
                                                }
#endif


/////////////////////////
// Write Protect Macro //
/////////////////////////

//-----------------------------------------------
// Macro of Flash write protect pin
//-----------------------------------------------
#define bFLASH_WRITE_PROTECT                    (MCU_FE26_PORT86_PIN_REG) // _PIN_190,SPI_WP_CPU, P8.6

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_FE36_PORTA6_PIN_REG) // _PIN_209,EEPROM_WPn_CPU, PA.6

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_FE23_PORT83_PIN_REG) // _PIN_181,DDC_WPn_CPU, P8.3

#define _EDID_EEPROM_WP_ENABLE                  0
#define _EDID_EEPROM_WP_DISABLE                 1

#define PCB_D3_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of D3 HDMI EDID Switch
//-----------------------------------------------
#define _HDMI_EDID_20                           1
#define _HDMI_EDID_14                           1
#define bHDMI_EDID_SELECT                       (MCU_FE2C_PORT94_PIN_REG) // _PIN_198,HDMI1_EDID_HDR_E2, P9.4

#define PCB_D3_EXT_EDID_0_SWITCH(x)             {\
                                                    bHDMI_EDID_SELECT = _HDMI_EDID_14;\
                                                }

#define PCB_D3_EXT_EDID_1_SWITCH(x)             {\
                                                    bHDMI_EDID_SELECT = _HDMI_EDID_20;\
                                                }

#define PCB_D3_EXT_EDID_2_SWITCH(x)             {\
                                                }

#define PCB_D3_EDID_SELECT(x)                   {\
                                                    bHDMI_EDID_SELECT = 1;\
                                                }


////////////////////////
// Cable Status Macro //
////////////////////////

//-----------------------------------------------
// Macro of Input Cable Connect
//-----------------------------------------------
#define bD0_DP_PIN15_CONNECT                    (P1_7)  // _PIN_70,DP_SINK_CPU_P, P1.7
#define bD0_DP_PIN16_CONNECT                    (P1_6)  // _PIN_69,C_CABLE_DET_GPIO, P1.6
#define bD0_DP_PIN17_CONNECT                    (P1_5)  // _PIN_68,DP_SINK_CPU_N, P1.5

//#define bD0_CONNECT                             (((bit)bD0_DP_PIN15_CONNECT == _TRUE) && ((bit)bD0_DP_PIN16_CONNECT == _TRUE) && ((bit)bD0_DP_PIN17_CONNECT == _FALSE))
#define bD0_CONNECT                             ((bit)bD0_DP_PIN16_CONNECT == _FALSE)
#define bD3_CONNECT                             (MCU_FE32_PORTA2_PIN_REG) // _PIN_204,HDMI1_DET_CPU, PA.2

#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D3_PIN()                            (bD3_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_DP_PIN17_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (MCU_FE01_PORT41_PIN_REG) // _PIN_96,DP_HPD_CPU, P4.1
#define bD3_HPD                                 (P1_0)  // _PIN_1,HDMI1_HPD_CPU,P1.0

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

#define PCB_D3_HOTPLUG(x)                       {\
                                                    bD3_HPD = (x);\
                                                }

#define PCB_D0_HOTPLUG_DETECT()                 (bD0_HPD)
#define PCB_D3_HOTPLUG_DETECT()                 (bD3_HPD)


///////////////
// PWM Macro //
///////////////
extern WORD g_usLedControlPwm;

//-----------------------------------------------
// Macro of Pcb PWM Inital Setting
//-----------------------------------------------
//#define _LED_PWM                                _NO_PWM // check later?

extern void ScalerMcuPwmAdjustFrequency(BYTE ucPwmType, WORD usFrequency);
extern void DeviceInterfaceLedDriverBacklightPowerPin(BYTE ucEnable);


#define PCB_PWM_SETTING()                       {\
                                                    ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 480);\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (0x30));\
                                                    ScalerMcuPwmAdjustFrequency(_LED_PWM, 500);\
                                                }

#if(_SPI_SUPPORT == _ON)
#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    g_usLedControlPwm = (x);\
                                                    DeviceInterfaceLedDriverBacklightPowerPin(_ENABLE);\
                                                }
#else

#define PCB_BACKLIGHT_PWM(x)                    {\
                                                    MCU_ADJUST_8BIT_PWM_DUTY(_BACKLIGHT_PWM, (x));\
                                                }

#endif



//////////////////
// SW IIC Macro //
//////////////////

//--------------------------------------------------
// Macro of IIC : (_SW_IIC_SUPPORT == _ON)
//--------------------------------------------------
//#define bSWIIC_SYS_EEPROM_SCL                   (MCU_FE0E_PORT56_PIN_REG)        // _PIN_J7, P5.6
//#define bSWIIC_SYS_EEPROM_SDA                   (MCU_FE0F_PORT57_PIN_REG)        // _PIN_H6, P5.7

#define bSWIIC_D3_EEPROM_SCL                    (MCU_FE3B_PORTB3_PIN_REG)        // _PIN_214,HDMI1_SCL_CPU, PB.3
#define bSWIIC_D3_EEPROM_SDA                    (MCU_FE3C_PORTB4_PIN_REG)        // _PIN_215,HDMI1_SDA_CPU, PB.4



#define PCB_SW_IIC_SDA_SET()                    {\
                                                }

#define PCB_SW_IIC_SDA_CLR()                    {\
                                                }

#define PCB_SW_IIC_SDA_CHK(x)                   {\
                                                }

#define PCB_SW_IIC_SCL_SET()                    {\
                                                }

#define PCB_SW_IIC_SCL_CLR()                    {\
                                                }

#define PCB_SW_IIC_SCL_CHK(x)                   {\
                                                }


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED PWM GPIO
//--------------------------------------------------
#define bLED_PWM                                (MCU_FE24_PORT84_PIN_REG) // _PIN_184,GPIO_184_CPU_LED_WHITE, P8.4
#define _LED_PWM_GPIO_ON                        1
#define _LED_PWM_GPIO_OFF                       0

#define PCB_LED_PWM_TYPE_GPIO(x)                {\
                                                    bLED_PWM = (x);\
                                                }

#define PCB_GET_LED_PWM_TYPE_GPIO()             (bLED_PWM)

//--------------------------------------------------
// Macro of LED PinShare PWM Switch
//--------------------------------------------------
#define PCB_LED_PWM_SWITCH(x)                   {\
                                                }


///////////////////
//   LED PWM     //
///////////////////

//--------------------------------------------------
// Macro of LED PWM
//--------------------------------------------------
#define _PWM_LED_TIMER_COUNT                    30
#define _PWM_LED_ADJUST_TIME                    82

#define _LED_PWM                                _PWM0

#define _LED_PWM_MAX                            255
#define _LED_PWM_MIN                            0

#define PCB_LED_TYPE_PWM(x)                     {\
                                                    MCU_ADJUST_PWM_DUTY(_LED_PWM, (x));\
                                                }

#define PCB_GET_LED_PWM()                       (MCU_GET_PWM_DUTY(_LED_PWM))

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_FE24_PORT84_PIN_REG) // _PIN_184,GPIO_184_CPU_LED_WHITE, P8.4

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                    bLED1 = _LED_OFF;\
                                                }

#define PCB_LED_ACTIVE()                        {\
                                                    bLED1 = _LED_ON;\
                                                }

#define PCB_LED_IDLE()                          {\
                                                }

#define PCB_LED_POWER_SAVING()                  {\
                                                }

#define PCB_LED_ON()                            {\
                                                    bLED1 = _LED_ON;\
                                                }

#define PCB_LED_OFF()                           {\
                                                    bLED1 = _LED_OFF;\
                                                }

#define PCB_LED_TYPE1()                         {\
                                                }

#define PCB_LED_TYPE2()                         {\
                                                }

#define PCB_LED_TYPE_FLASH()                    {\
                                                }


//////////////////
// AD Key Macro //
//////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT) // _PIN_94,GPIO_94_CPU_KEY1
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT) // _PIN_95,GPIO_95_CPU_KEY2
#define bPOWER_KEY                              (P1_4)  // _PIN_67,GPIO_67_CPU_KEY_POWER, P1.4

#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                    if(bPOWER_KEY == 0)\
                                                    {\
                                                        (ucKeyState) |= _POWER_KEY_MASK;\
                                                    }\
                                                    if((0x90 <= (ucV2)) && ((ucV2) < 0xE0))\
                                                    {\
                                                        (ucKeyState) |= _MENU_KEY_MASK;\
                                                    }\
                                                    if((0x40 <= (ucV2)) && ((ucV2) < 0x90))\
                                                    {\
                                                        (ucKeyState) |= _EXIT_KEY_MASK;\
                                                    }\
                                                    if((0x40 <= (ucV1)) && ((ucV1) < 0x80))\
                                                    {\
                                                        (ucKeyState) |= _LEFT_KEY_MASK;\
                                                    }\
                                                    if((0x90 <= (ucV1)) && ((ucV1) < 0xE0))\
                                                    {\
                                                        (ucKeyState) |= _RIGHT_KEY_MASK;\
                                                    }\
                                                }


/////////////////
// Audio Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Audio AMP Control
//-----------------------------------------------
#define bAMP_MUTE                               (MCU_FE2D_PORT95_PIN_REG) // _PIN_199,GPIO_199_CPU_MUTEN, P9.5

#define _AMP_MUTE_ON                            1 // Amp Mute on state
#define _AMP_MUTE_OFF                           0 // Amp Mute off state

#define PCB_AMP_MUTE(x)                         {\
                                                    bAMP_MUTE = (x);\
                                                }


/////////////////
// Usb Macro //
/////////////////

//-----------------------------------------------
// Macro of PCB Usb Cable Detect
//-----------------------------------------------
#define _USB_CONNECTOR_OFF                      0
#define _USB_CONNECTOR_ON                       1

#define PCB_GET_USB_CABLE()                     (bD0_DP_PIN16_CONNECT)



//////////////////////////////
// Device USB Charger Power //
//////////////////////////////
#define _DEVICE_USB_CHARGER_POWER_TYPE          _DEVICE_USB_CHARGER_POWER_01_MACRO

#define bUSB_3V3_CONTROL                        (MCU_FE33_PORTA3_PIN_REG) // _PIN_206,3D3V_USB_EN,PA.3
#define _USB_3V3_ON                             1
#define _USB_3V3_OFF                            0

#define _USB_PD_EN                              (MCU_FE28_PORT90_PIN_REG) // _PIN_194,GPIO_194_CPU_PD_EN,P9.0

//-----------------------------------------------
// Macro of PCB Usb Charger Power Power
//-----------------------------------------------
#define bUSB_CHARGER_POWER                      (MCU_FE22_PORT82_PIN_REG) // _PIN_180,GPIO_180_CPU_USB_EN,P8.2

#define _USB_CHARGER_POWER_OFF                  1
#define _USB_CHARGER_POWER_ON                   0

#define PCB_USB_CHARGER_POWER(x)                {\
                                                    bUSB_CHARGER_POWER = (x);\
                                                    bUSB_3V3_CONTROL = !(x);\
                                                }

#define PCB_GET_USB_CHARGER_POWER()             (bUSB_CHARGER_POWER)

//-----------------------------------------------
// Macro of PCB Usb Charger Power Data
//-----------------------------------------------
#define bUSB_CHARGER_DATA                       (MCU_FE2F_PORT97_PIN_REG)// _PIN_201,GPIO_201_CPU_USB_EN,P9.7

#define _USB_CHARGER_DATA_DCP                   0
#define _USB_CHARGER_DATA_CDP                   1

#define PCB_USB_CHARGER_DATA(x)                 {\
                                                    bUSB_CHARGER_DATA = (x);\
                                                }

#define PCB_GET_USB_CHARGER_DATA()              (bUSB_CHARGER_DATA)


////////////////////
// Device USB Hub //
////////////////////
#define _DEVICE_USB_HUB_TYPE                    _DEVICE_USB_HUB_04_TI_TUSB8041

//-----------------------------------------------
// Macro of PCB Usb Hub Power
//-----------------------------------------------
#define bUSB_HUB_POWER                          (MCU_FE22_PORT82_PIN_REG) // _PIN_180,GPIO_180_CPU_USB_EN,P8.2

#define _USB_HUB_POWER_OFF                      1
#define _USB_HUB_POWER_ON                       0

#define PCB_USB_HUB_POWER(x)                    {\
                                                    bUSB_HUB_POWER = (x);\
                                                    bUSB_3V3_CONTROL = !(x);\
                                                }


#define PCB_GET_USB_HUB_POWER()                 (bUSB_HUB_POWER)


/////////////////
//   35 TRS    //
/////////////////
#define _PCB_EMBEDDED_SPEAKER                   _AUDIO_OUTPUT_FROM_DAC_SPEAKER
#define _PCB_EXTERN_35_TRS                      _AUDIO_OUTPUT_FROM_NONE // _AUDIO_OUTPUT_FROM_DAC_HEADPHONE


/////////////////
// Power Adapt //
/////////////////

//--------------------------------------------------
// Power Adapt Detect
//--------------------------------------------------
#define _DEVICE_PSID_TYPE                       _DEVICE_PSID_01_TI_BQ2022A

#define bPSID_DET                               (MCU_FE31_PORTA1_PIN_REG) // _PIN_203,PSID_DET, PA.1

#define DRIVING_SDQ_LOW                         0
#define RELEASING_SDQ_HIGH                      1

#define PCB_SDQ(x)                              {\
                                                    bPSID_DET = (x);\
                                                }

#define _POWER_ADAPT_LOW                        0
#define _POWER_ADAPT_HIGH                       1
#define _POWER_ADAPT_BACKLIGHT                  100

#define PCB_GET_POWER_ADAPTER(ucAdaptValue)     {\
                                                    (ucAdaptValue) = DeviceInterfacePSIDGetPowerAdaptStatus();\
                                                }

#endif // End of #if(_PCB_TYPE == _RL6449_DEMO_LOCAL_DIMMING_1USB1H1TC)

