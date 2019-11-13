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
// ID Code      : RL6410_DEMO_5K3K_2H2DP_LVDS_eDP.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6410_DEMO_5K3K_2H2DP_LVDS_eDP)


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
// D0 Input Port
//--------------------------------------------------
#define _D0_INPUT_PORT_TYPE                     _D0_DP_PORT
#define _D0_DDC_CHANNEL_SEL                     _DDC0
#define _D0_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_256
#define _D0_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#define _D0_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D0_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D0_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

//--------------------------------------------------
// D1 Input Port
//--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_DP_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#define _D1_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE

//--------------------------------------------------
// D2 Input Port
//--------------------------------------------------
#define _D2_INPUT_PORT_TYPE                     _D2_MHL_PORT
#define _D2_DDC_CHANNEL_SEL                     _DDC2
#define _D2_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D2_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D2_MHL_VERSION                         _MHL_VERSION_2_2
#define _D2_CBUS_CHANNEL_SEL                    _CBUS0
#define _D2_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_256
#define _D2_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE

//--------------------------------------------------
// D3 Input Port
//--------------------------------------------------
#define _D3_INPUT_PORT_TYPE                     _D3_MHL_PORT
#define _D3_DDC_CHANNEL_SEL                     _DDC3
#define _D3_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D3_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE
#define _D3_MHL_VERSION                         _MHL_VERSION_2_2
#define _D3_CBUS_CHANNEL_SEL                    _CBUS1
#define _D3_MHL_EMBEDDED_DDCRAM_SIZE            _EDID_SIZE_256
#define _D3_MHL_EMBEDDED_DDCRAM_LOCATION        _EDID_TABLE_LOCATION_CODE


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _D0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D2_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D3_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _D0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D1_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_2                _D2_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_3                _D3_INPUT_PORT


////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Port Config
//--------------------------------------------------
#if(_LVDS_OUTPUT_PORT == _LVDS_2_PORT)
#define _LVDS_PORT_SEL                          _LVDS_2_PORT_CD
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _DISABLE
#define _LVDS_PORT_CD_SWAP                      _DISABLE
#define _LVDS_PORT_EF_SWAP                      _DISABLE
#define _LVDS_PORT_GH_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _ENABLE
#elif(_LVDS_OUTPUT_PORT == _LVDS_4_PORT)

#if(_LVDS_CABLE_TYPE == _LVDS_CABLE_TYPE_0)
#define _LVDS_PORT_SEL                          _LVDS_4_PORT_ABCD
#define _LVDS_PORT_MIRROR                       _DISABLE
#define _LVDS_PORT_AB_SWAP                      _ENABLE
#define _LVDS_PORT_CD_SWAP                      _DISABLE
#define _LVDS_PORT_EF_SWAP                      _DISABLE
#define _LVDS_PORT_GH_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
#elif(_LVDS_CABLE_TYPE == _LVDS_CABLE_TYPE_1)
#define _LVDS_PORT_SEL                          _LVDS_4_PORT_ABCD
#define _LVDS_PORT_MIRROR                       _ENABLE
#define _LVDS_PORT_AB_SWAP                      _ENABLE
#define _LVDS_PORT_CD_SWAP                      _ENABLE
#define _LVDS_PORT_EF_SWAP                      _DISABLE
#define _LVDS_PORT_GH_SWAP                      _DISABLE
#define _LVDS_PN_SWAP                           _DISABLE
#endif

#endif

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
#define _LVDS_SPREAD_RANGE                      10
#define _LVDS_SPREAD_SPEED                      _SPEED_33K


/////////////////////////
// eDPTx 1.1 HBR Panel //
/////////////////////////

//--------------------------------------------------
// eDPTx 1.1 HBR Main Link Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_FB_SWAP                 _DISABLE
#define _PANEL_DPTX_1_1_LANE_SWAP               _ENABLE
#define _PANEL_DPTX_1_1_LANE_PN_SWAP            _ENABLE
#define _PANEL_DPTX_1_1_SWING_LEVEL             _DP_SWING_800_MV
#define _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_0_DB

//--------------------------------------------------
// eDPTx 1.1 HBR SSC Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_SPREAD_RANGE            12
#define _PANEL_DPTX_1_1_SPREAD_SPEED            _SPEED_33K


//////////////////////////
// eDPTx 1.2 HBR2 Panel //
//////////////////////////

//--------------------------------------------------
// eDPTx 1.2 HBR2 Main Link Config
//--------------------------------------------------
#define _PANEL_DPTX_1_2_SWING_LEVEL             _DP_SWING_800_MV
#define _PANEL_DPTX_1_2_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_3_5_DB

//--------------------------------------------------
// eDPTx 1.2 HBR2 SSC Config
//--------------------------------------------------
#define _PANEL_DPTX_1_2_SPREAD_RANGE            12
#define _PANEL_DPTX_1_2_SPREAD_SPEED            _SPEED_33K

//--------------------------------------------------
// eDPTx 1.2 HBR2 FB/Lane Config
//--------------------------------------------------
#define _PANEL_DPTX_1_2_FB_SWAP                 _ENABLE
#define _PANEL_DPTX_1_2_LANE_SWAP               _ENABLE
#define _PANEL_DPTX_1_2_LANE_PN_SWAP            _ENABLE


/////////////////
// Memory DDR3 //
/////////////////

//--------------------------------------------------
// Definitions of DDR3 Memory Size
//--------------------------------------------------
#define _EXTERNAL_MEMORY_SIZE_CONFIG            _1G_16BIT_DDR3_2PCS

//--------------------------------------------------
// Definitions of DDR3 PLL Phase
//--------------------------------------------------
#if((_EXTERNAL_MEMORY_SIZE_CONFIG & _MEMORY_DENSITY_MASK) == _MEMORY_DENSITY_64M_16)
#define _DDR3_PLL_INITIAL_PHASE_0               0x16032100
#define _DDR3_PLL_INITIAL_PHASE_1               0x18002314
#define _DDR3_READ_DQ_DLYN_TAP                  0x1F1F1F1F
#elif((_EXTERNAL_MEMORY_SIZE_CONFIG & _MEMORY_DENSITY_MASK) == _MEMORY_DENSITY_128M_16)
#define _DDR3_PLL_INITIAL_PHASE_0               0x1B002900
#define _DDR3_PLL_INITIAL_PHASE_1               0x1800291B
#define _DDR3_READ_DQ_DLYN_TAP                  0x1C1C1C1C
#elif((_EXTERNAL_MEMORY_SIZE_CONFIG & _MEMORY_DENSITY_MASK) == _MEMORY_DENSITY_256M_16)
#define _DDR3_PLL_INITIAL_PHASE_0               0x1A002500
#define _DDR3_PLL_INITIAL_PHASE_1               0x18002717
#define _DDR3_READ_DQ_DLYN_TAP                  0x1E1E1E1E
#endif


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM5
#define _BACKLIGHT_PWM_INVERSE                  _ON

#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF
#define _PWM5_EN                                _ON

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
#define _PWM5_RST_BY_DVS                        _ON
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
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_PIN_J7_H6


////////////////////////////////////
// Communication Between Two Chip //
////////////////////////////////////

//--------------------------------------------------
// Definitions of DDCCI1 Communication Pin
//--------------------------------------------------
#define _PCB_TWO_CHIP_DATA_EXCHANGE_IIC         _HW_IIC_PIN_AG8_AG9

//--------------------------------------------------
// Definitions HW IIC SCL Pin Status
//--------------------------------------------------
#define GET_TWO_CHIP_HW_SCL_PIN_STATUS()        (MCU_FE4D_PORTD5_PIN_REG) // Pin AG8 HW IIC SCL Pin, PD.5, FE4D[0]


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
// RL6410 Series Pin Share //
/////////////////////////////

//--------------------------------------------------
//  RL6410 BGA Pin Share
//--------------------------------------------------
// AUX_P_2
#define _PIN_Y6                                 (3 & 0x07) // Page 10-0x00[2:0]
// 0 ~ 4 (0: P1D0i<I>, 1: reserved, 2: P1D0o<OD>, 3: AUX_P1)

// AUX_N_2
#define _PIN_Y5                                 (3 & 0x07) // Page 10-0x01[2:0]
// 0 ~ 4 (0: P1D1i<I>, 1: reserved, 2: P1D1o<OD>, 3: AUX_N1)

// AUX_P_0
#define _PIN_AA6                                (3 & 0x07) // Page 10-0x02[2:0]
// 0 ~ 4 (0: P1D2i<I>, 1: reserved, 2: P1D2o<OD>, 3: AUX_P0)

// AUX_N_0
#define _PIN_AA5                                (3 & 0x07) // Page 10-0x03[2:0]
// 0 ~ 4 (0: P1D3i<I>, 1: reserved, 2: P1D3o<OD>, 3: AUX_N0)

// CBUS/HDMI_HPD_2
#define _PIN_L4                                 (2 & 0x07) // Page 10-0x04[2:0]
// 0 ~ 2 (0: P1D4i<I>, 1: P1D4o<PP>, 2: P1D4o<OD>)

// MHL_DETECT_2
#define _PIN_W6                                 (0 & 0x07) // Page 10-0x05[2:0]
// 0 ~ 2 (0: P1D5i<I>, 1: P1D5o<PP>, 2: P1D5o<OD>)

// CBUS/HDMI_HPD_3
#define _PIN_F4                                 (2 & 0x07) // Page 10-0x06[2:0]
// 0 ~ 2 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>)

// MHL_DETECT_3
#define _PIN_W5                                 (0 & 0x07) // Page 10-0x07[2:0]
// 0 ~ 2 (0: P1D7i<I>, 1: P1D7o<PP>, 2: P1D7o<OD>)

// NC
#define _PIN_AJ3                                (1 & 0x07) // Page 10-0x08[2:0]
// 0 ~ 6 (0: P3D0i<I>, 1: P3D0o<PP>, 2: P3D0o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AJ1                                (1 & 0x07) // Page 10-0x09[2:0]
// 0 ~ 6 (0: P3D1i<I>, 1: P3D1o<PP>, 2: P3D1o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AJ2                                (1 & 0x07) // Page 10-0x0A[2:0]
// 0 ~ 6 (0: P3D2i<I>, 1: P3D2o<PP>, 2: P3D2o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AK3                                (1 & 0x07) // Page 10-0x0B[2:0]
// 0 ~ 6 (0: P3D3i<I>, 1: P3D3o<PP>, 2: P3D3o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AK2                                (1 & 0x07) // Page 10-0x0C[2:0]
// 0 ~ 6 (0: P3D4i<I>, 1: P3D4o<PP>, 2: P3D4o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AL3                                (1 & 0x07) // Page 10-0x0D[2:0]
// 0 ~ 6 (0: P3D5i<I>, 1: P3D5o<PP>, 2: P3D5o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AL2                                (1 & 0x07) // Page 10-0x0E[2:0]
// 0 ~ 6 (0: P3D6i<I>, 1: P3D6o<PP>, 2: P3D6o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AL1                                (1 & 0x07) // Page 10-0x0F[2:0]
// 0 ~ 6 (0: P3D7i<I>, 1: P3D7o<PP>, 2: P3D7o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_AM1                                (1 & 0x07) // Page 10-0x10[2:0]
// 0 ~ 6 (0: P4D0i<I>, 1: P4D0o<PP>, 2: P4D0o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3)

// KEY1
#define _PIN_AH9                                (3 & 0x07) // Page 10-0x11[2:0]
// 0 ~ 4 (0: P4D1i<I>, 1: P4D1o<PP>, 2: P4D1o<OD>, 3: A-adc0_0, 4: Int0)

// KEY2
#define _PIN_AH8                                (3 & 0x07) // Page 10-0x12[2:0]
// 0 ~ 4 (0: P4D2i<I>, 1: P4D2o<PP>, 2: P4D2o<OD>, 3: A-adc1_0, 4: INT1)

// LED1
#define _PIN_AJ9                                (1 & 0x07) // Page 10-0x13[2:0]
// 0 ~ 3 (0: P4D3i<I>, 1: P4D3o<PP>, 2: P4D3o<OD>, 3: A-adc2_0)

// LED2
#define _PIN_AJ8                                (1 & 0x07) // Page 10-0x14[2:0]
// 0 ~ 3 (0: P4D4i<I>, 1: P4D4o<PP>, 2: P4D4o<OD>, 3: A-adc3_0)

// DDCSCL_VGA
#define _PIN_AL5                                (3 & 0x07) // Page 10-0x15[2:0]
// 0 ~ 3 (0: P4D5i<I>, 1: P4D5o<PP>, 2: P4D5o<OD>, 3: Ddcsclvga)

// DDCSDA_VGA
#define _PIN_AK5                                (3 & 0x07) // Page 10-0x16[2:0]
// 0 ~ 3 (0: P4D6i<I>, 1: P4D6o<PP>, 2: P4D6o<OD>, 3: Ddcsdavga)

// NC
#define _PIN_AJ5                                (1 & 0x07) // Page 10-0x17[2:0]
// 0 ~ 5 (0: P4D7i<I>, 1: P4D7o<PP>, 2: P4D7o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: TCON[4])

// NC
#define _PIN_AK4                                (1 & 0x07) // Page 10-0x18[2:0]
// 0 ~ 6 (0: P5D0i<I>, 1: P5D0o<PP>, 2: P5D0o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[5], 6: INT0)

// NC
#define _PIN_AL4                                (1 & 0x07) // Page 10-0x19[2:0]
// 0 ~ 5 (0: P5D1i<I>, 1: P5D1o<PP>, 2: P5D1o<OD>, 3: PWM2<PP>, 4: PWM2<OD>,
//        5: TCON[7])

// NC
#define _PIN_AM4                                (1 & 0x07) // Page 10-0x1A[2:0]
// 0 ~ 5 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: TCON[8])

// NC
#define _PIN_AM2                                (1 & 0x07) // Page 10-0x1B[2:0]
// 0 ~ 7 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCON[10], 6: INT1, 7: PWM_IN)

// Panel_ON
#define _PIN_AM3                                (1 & 0x07) // Page 10-0x1C[2:0]
// 0 ~ 6 (0: P5D4i<I>, 1: P5D4o<PP>, 2: P5D4o<OD>, 3: PWM5<PP>, 4: PWM5<OD>,
//        5: TCON[12], 6: PWM_OUT)

// EEPROM_WP
#define _PIN_G7                                 (2 & 0x07) // Page 10-0x1D[2:0]
// 0 ~ 5 (0: P5D5i<I>, 1: P5D5o<PP>, 2: P5D5o<OD>, 3: PWM2<PP>, 4: PWM2<OD>,
//        5: TCON[3])

// EESCL
#define _PIN_J7                                 (6 & 0x07) // Page 10-0x1E[2:0]
// 0 ~ 6 (0: P5D6i<I>, 1: P5D6o<PP>, 2: P5D6o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: TCON[1], 6: EEIICSCL)

// EESDA
#define _PIN_H6                                 (6 & 0x07) // Page 10-0x1F[2:0]
// 0 ~ 6 (0: P5D7i<I>, 1: P5D7o<PP>, 2: P5D7o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[2], 6: EEIICSDA)

// GPIO1
#define _PIN_AD28                               (2 & 0x0F) // Page 10-0x24[2:0]
// 0 ~ 8 (0: P6D4i<I>, 1: P6D4o<PP>, 2: P6D4o<OD>, 3: TCON[4], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3, 8: IICSCL1)

// GPIO2
#define _PIN_AH27                               (2 & 0x0F) // Page 10-0x25[2:0]
// 0 ~ 8 (0: P6D5i<I>, 1: P6D5o<PP>, 2: P6D5o<OD>, 3: TCON[5], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3, 8: IICSDA1)

// DPTX_AUX_P_1
#define _PIN_N29                                (6 & 0x07) // Page 10-0x26[2:0]
// 0 ~ 6 (0: P6D6i<I>, 1: P6D6o<PP>, 2: P6D6o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: TCON[6], 6: Dptx_aux_ch_p_1)

// DPTX_AUX_N_1
#define _PIN_N28                                (6 & 0x07) // Page 10-0x27[2:0]
// 0 ~ 6 (0: P6D7i<I>, 1: P6D7o<PP>, 2: P6D7o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[7], 6: Dptx_aux_ch_n_1)

// DPTX_AUX_P_2
#define _PIN_M29                                (6 & 0x07) // Page 10-0x28[2:0]
// 0 ~ 6 (0: P7D0i<I>, 1: P7D0o<PP>, 2: P7D0o<OD>, 3: PWM2<PP>, 4: PWM3<OD>,
//        5: TCON[8], 6: Dptx_aux_ch_p_2)

// DPTX_AUX_N_2
#define _PIN_M28                                (6 & 0x07) // Page 10-0x29[2:0]
// 0 ~ 6 (0: P7D1i<I>, 1: P7D1o<PP>, 2: P7D1o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: TCON[9], 6: Dptx_aux_ch_n_2)

// NC
#define _PIN_J29                                (1 & 0x07) // Page 10-0x2A[2:0]
// 0 ~ 7 (0: P7D2i<I>, 1: P7D2o<PP>, 2: P7D2o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCON[10], 6: Disp_frame_start_in, 7: Disp_frame_start_out)

// ADJBACKLITE
#define _PIN_AJ28                               (3 & 0x07) // Page 10-0x2B[2:0]
// 0 ~ 6 (0: P7D3i<I>, 1: P7D3o<PP>, 2: P7D3o<OD>, 3: PWM5<PP>, 4: PWM5<OD>,
//        5: TCON[11], 6: Cryclk)

// NC
#define _PIN_N27                                (1 & 0x07) // Page 10-0x2C[2:0]
// 0 ~ 6 (0: P7D4i<I>, 1: P7D4o<PP>, 2: P7D4o<OD>, 3: Ws, 4: TCON[12],
//        5: Test4b_out0, 6: Test4b_out1)

// NC
#define _PIN_K27                                (1 & 0x07) // Page 10-0x2D[2:0]
// 0 ~ 6 (0: P7D5i<I>, 1: P7D5o<PP>, 2: P7D5o<OD>, 3: Sck, 4: TCON[13],
//        5: Test4b_out2, 6: Test4b_out3)

// NC
#define _PIN_M27                                (1 & 0x07) // Page 10-0x2E[2:0]
// 0 ~ 7 (0: P7D6i<I>, 1: P7D6o<PP>, 2: P7D6o<OD>, 3: Mck, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// NC
#define _PIN_K29                                (1 & 0x07) // Page 10-0x2F[2:0]
// 0 ~ 6 (0: P7D7i<I>, 1: P7D7o<PP>, 2: P7D7o<OD>, 3: Spdif0, 4: Sd0,
//        5: Test4b_out0, 6: Test4b_out1, 7: TCON[0])

// NC
#define _PIN_J28                                (1 & 0x07) // Page 10-0x30[2:0]
// 0 ~ 6 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: Spdif1, 4: Sd1,
//        5: Test4b_out2, 6: Test4b_out3,  7: TCON[1])

// NC
#define _PIN_J27                                (1 & 0x07) // Page 10-0x31[2:0]
// 0 ~ 6 (0: P8D1i<I>, 1: P8D1o<PP>, 2: P8D1o<OD>, 3: Spdif2, 4: Sd2,
//        5: Test4b_out0, 6: Test4b_out1,  7: TCON[2])

// NC
#define _PIN_K28                                (1 & 0x07) // Page 10-0x32[2:0]
// 0 ~ 6 (0: P8D2i<I>, 1: P8D2o<PP>, 2: P8D2o<OD>, 3: Spdif3, 4: Sd3,
//        5: Test4b_out2, 6: Test4b_out3,  7: TCON[3])

// VCCK_OFF_EN
#define _PIN_AH21                               (2 & 0x07) // Page 10-0x33[2:0]
// 0 ~ 4 (0: P8D3i<I>, 1: P8D3o<PP>, 2: P8D3o<OD>, 3: CLKO, 4: Usb_spi_clk)

// DDR_PW_EN
#define _PIN_AK21                               (2 & 0x07) // Page 10-0x34[2:0]
// 0 ~ 4 (0: P8D4i<I>, 1: P8D4o<PP>, 2: P8D4o<OD>, 3: INT0, 4: Usb_spi_si)

// VCCK_ON_EN_T
#define _PIN_AJ21                               (2 & 0x07) // Page 10-0x35[2:0]
// 0 ~ 4 (0: P8D5i<I>, 1: P8D5o<PP>, 2: P8D5o<OD>, 3: INT1, 4: Usb_spi_so)

// VCCK_OFF_EN_T
#define _PIN_AJ20                               (2 & 0x07) // Page 10-0x36[2:0]
// 0 ~ 4 (0: P8D6i<I>, 1: P8D6o<PP>, 2: P8D6o<OD>, 3: IRQB, 4: Usb_spi_ceb0)

// V33S_EN_T
#define _PIN_AH20                               (2 & 0x07) // Page 10-0x37[2:0]
// 0 ~ 4 (0: P8D7i<I>, 1: P8D7o<PP>, 2: P8D7o<OD>, 3: T2ex , 4: Usb_spi_ceb1)

// FLASH_WP
#define _PIN_AL21                               (1 & 0x07) // Page 10-0x38[2:0]
// 0 ~ 2 (0: P9D0i<I>, 1: P9D0o<PP>, 2: P9D0o<OD>)

// VTX_PLL_LOCK
#define _PIN_AA29                               (4 & 0x07) // Page 10-0x39[2:0]
// 0 ~ 4 (0: P9D1i<I>, 1: P9D1o<PP>, 2: P9D1o<OD>, 3: Vb1_lock_n, 4: Dptx_hpd2_org)

// VTX_HPD
#define _PIN_AA28                               (4 & 0x07) // Page 10-0x3A[2:0]
// 0 ~ 4 (0: P9D2i<I>, 1: P9D2o<PP>, 2: P9D2o<OD>, 3: Vb1_htpd_n, 4: Dptx_hpd1_org)

// VBUS_EN_2
#define _PIN_AG25                               (1 & 0x07) // Page 10-0x3B[2:0]
// 0 ~ 6 (0: P9D3i<I>, 1: P9D3o<PP>, 2: P9D3o<OD>, 3: PWM5<PP>, 4: PWM5<OD>,
//        5: TCON[7], 6:T0)

// VBUS_EN_3
#define _PIN_AH26                               (1 & 0x07) // Page 10-0x3C[2:0]
// 0 ~ 6 (0: P9D4i<I>, 1: P9D4o<PP>, 2: P9D4o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCON[6], 6:T1)

// GPIO3
#define _PIN_AG26                               (2 & 0x07) // Page 10-0x3D[2:0]
// 0 ~ 6 (0: P9D5i<I>, 1: P9D5o<PP>, 2: P9D5o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: TCON[5], 6:T2)

// IR_IN
#define _PIN_AJ26                               (6 & 0x07) // Page 10-0x3E[2:0]
// 0 ~ 6 (0: P9D6i<I>, 1: P9D6o<PP>, 2: P9D6o<OD>, 3: PWM2<PP>, 4: PWM2<OD>,
//        5: TCON[4], 6:Irda_in)

// GPIO4
#define _PIN_AF28                               (2 & 0x07) // Page 10-0x3F[2:0]
// 0 ~ 7 (0: P9D7i<I>, 1: P9D7o<PP>, 2: P9D7o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[3], 6: Test4b_out2, 7: Test4b_out3)

// EDID_WP
#define _PIN_AG24                               (2 & 0x07) // Page 10-0x40[2:0]
// 0 ~ 7 (0: PAD0i<I>, 1: PAD0o<PP>, 2: PAD0o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5: TCON[2], 6: Test4b_out0, 7: Test4b_out1)

// GPIO5
#define _PIN_AE28                               (1 & 0x0F) // Page 10-0x41[2:0]
// 0 ~ 8 (0: PAD1i<I>, 1: PAD1o<PP>, 2: PAD1o<OD>, 3: TCON[1], 4: reserved,
//        5: reserved, 6: Test4b_out2, 7: Test4b_out3, 8: RXD)

// onBACKLITE
#define _PIN_AJ27                               (2 & 0x0F) // Page 10-0x42[2:0]
// 0 ~ 8 (0: PAD2i<I>, 1: PAD2o<PP>, 2: PAD2o<OD>, 3: TCON[0], 4: Test4b_out0,
//        5: Test4b_out1, 6:reserved, 7: reserved, 8: TXD)

// DP_SINK_ASS_P0
#define _PIN_AG29                               (0 & 0x07) // Page 10-0x43[2:0]
// 0 ~ 7 (0: PAD3i<I>, 1: PAD3o<PP>, 2: PAD3o<OD>, 3: TCON[13], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// DP_SINK_ASS_N0
#define _PIN_AH25                               (0 & 0x07) // Page 10-0x44[2:0]
// 0 ~ 5 (0: PAD4i<I>, 1: PAD4o<PP>, 2: PAD4o<OD>, 3: TCON[12], 4: Sd3,
//        5: Spdif3)

// DP_CABLE_DET_0
#define _PIN_AF29                               (0 & 0x07) // Page 10-0x45[2:0]
// 0 ~ 5 (0: PAD5i<I>, 1: PAD5o<PP>, 2: PAD5o<OD>, 3: TCON[11], 4: Sd2,
//        5: Spdif2)

// DP_SINK_ASS_P1
#define _PIN_AJ25                               (0 & 0x07) // Page 10-0x46[2:0]
// 0 ~ 5 (0: PAD6i<I>, 1: PAD6o<PP>, 2: PAD6o<OD>, 3: TCON[10], 4: Sd1,
//        5: Spdif1)

// DP_SINK_ASS_N1
#define _PIN_AG28                               (0 & 0x07) // Page 10-0x47[2:0]
// 0 ~ 5 (0: PAD7i<I>, 1: PAD7o<PP>, 2: PAD7o<OD>, 3: TCON[9], 4: Sd0,
//        5: Spdif0)

// DP_CABLE_DET_1
#define _PIN_AH24                               (0 & 0x07) // Page 10-0x48[2:0]
// 0 ~ 7 (0: PBD0i<I>, 1: PBD0o<PP>, 2: PBD0o<OD>, 3: TCON[8], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// NC
#define _PIN_AF27                               (1 & 0x07) // Page 10-0x49[2:0]
// 0 ~ 7 (0: PBD1i<I>, 1: PBD1o<PP>, 2: PBD1o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3, 7: Mck)

// NC
#define _PIN_AJ24                               (1 & 0x07) // Page 10-0x4A[2:0]
// 0 ~ 7 (0: PBD2i<I>, 1: PBD2o<PP>, 2: PBD2o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3, 7: Sck)

// HDMI_CABLE_DETECT_3
#define _PIN_AG27                               (0 & 0x07) // Page 10-0x4B[2:0]
// 0 ~ 7 (0: PBD3i<I>, 1: PBD3o<PP>, 2: PBD3o<OD>, 3: Test4b_out0, 4: Test4b_out1,
//        5: Test4b_out2, 6: Test4b_out3, 7: Ws)

// LINE_INL
#define _PIN_AJ18                               (3 & 0x07) // Page 10-0x4C[2:0]
// 0 ~ 4 (0: PBD4i<I>, 1: PBD4o<PP>, 2: PBD4o<OD>, 3: Line_inl, 4: Ws)

// LINE_INR
#define _PIN_AK18                               (3 & 0x07) // Page 10-0x4D[2:0]
// 0 ~ 4 (0: PBD5i<I>, 1: PBD5o<PP>, 2: PBD5o<OD>, 3: Line_inr, 4: Sck)

// Audio_REF
#define _PIN_AE20                               (3 & 0x07) // Page 10-0x4E[2:0]
// 0 ~ 4 (0: PBD6i<I>, 1: PBD6o<PP>, 2: PBD6o<OD>, 3: Audio_ref, 4: Mck)

// NC
#define _PIN_AL18                               (1 & 0x07) // Page 10-0x4F[2:0]
// 0 ~ 5 (0: PBD7i<I>, 1: PBD7o<PP>, 2: PBD7o<OD>, 3: Audio_soutl, 4: Sdo,
//        5: Spdif0)

// NC
#define _PIN_AM18                               (1 & 0x07) // Page 10-0x50[2:0]
// 0 ~ 5 (0: PCD0i<I>, 1: PCD0o<PP>, 2: PCD0o<OD>, 3: Audio_soutr, 4: Sd1,
//        5: Spdif1)

// AUDIO_HOUTL
#define _PIN_AL19                               (3 & 0x07) // Page 10-0x51[2:0]
// 0 ~ 5 (0: PCD1i<I>, 1: PCD1o<PP>, 2: PCD1o<OD>, 3: Audio_houtl, 4: Sd2,
//        5: Spdif2)

// AUDIO_HOUTR
#define _PIN_AM19                               (3 & 0x07) // Page 10-0x52[2:0]
// 0 ~ 5 (0: PCD2i<I>, 1: PCD2o<PP>, 2: PCD2o<OD>, 3: Audio_houtr, 4: Sd3,
//        5: Spdif3)

// NC
#define _PIN_AJ11                               (1 & 0x07) // Page 10-0x53[2:0]
// 0 ~ 3 (0: PCD3i<I>, 1: PCD3o<PP>, 2: PCD3o<OD>, 3: Dptx_aux_ch_p)

// NC
#define _PIN_AJ12                               (1 & 0x07) // Page 10-0x54[2:0]
// 0 ~ 3 (0: PCD4i<I>, 1: PCD4o<PP>, 2: PCD4o<OD>, 3: Dptx_aux_ch_n)

// NC
#define _PIN_AG6                                (1 & 0x07) // Page 10-0x55[2:0]
// 0 ~ 3 (0: PCD5i<I>, 1: PCD5o<PP>, 2: PCD5o<OD>, 3: Dptx_hpd_org)

// HDMI_CABLE_DETECT_2
#define _PIN_AJ4                                (0 & 0x07) // Page 10-0x56[2:0]
// 0 ~ 2 (0: PCD6i<I>, 1: PCD6o<PP>, 2: PCD6o<OD>)

// NC
#define _PIN_AF7                                (1 & 0x07) // Page 10-0x57[2:0]
// 0 ~ 2 (0: PCD7i<I>, 1: PCD7o<PP>, 2: PCD7o<OD>)

// NC
#define _PIN_AF6                                (1 & 0x07) // Page 10-0x58[2:0]
// 0 ~ 2 (0: PDD0i<I>, 1: PDD0o<PP>, 2: PDD0o<OD>)

// HDMI_MHL_SEL_3
#define _PIN_AG7                                (2 & 0x07) // Page 10-0x59[2:0]
// 0 ~ 2 (0: PDD1i<I>, 1: PDD1o<PP>, 2: PDD1o<OD>)

// HDMI_MHL_SEL_2
#define _PIN_AH7                                (2 & 0x07) // Page 10-0x5A[2:0]
// 0 ~ 2 (0: PDD2i<I>, 1: PDD2o<PP>, 2: PDD2o<OD>)

// DP_HPD_2
#define _PIN_AH6                                (1 & 0x07) // Page 10-0x5B[2:0]
// 0 ~ 2 (0: PDD3i<I>, 1: PDD3o<PP>, 2: PDD3o<OD>)

// DP_HPD_0
#define _PIN_AH5                                (1 & 0x07) // Page 10-0x5C[2:0]
// 0 ~ 2 (0: PDD4i<I>, 1: PDD4o<PP>, 2: PDD4o<OD>)

// DDC2_SCL
#define _PIN_AG8                                (6 & 0x07) // Page 10-0x5D[2:0]
// 0 ~ 6 (0: PDD5i<I>, 1: PDD5o<PP>, 2: PDD5o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5:TCON[7], 6:IICSCL2)

// DDC2_SDA
#define _PIN_AG9                                (6 & 0x07) // Page 10-0x5E[2:0]
// 0 ~ 6 (0: PDD6i<I>, 1: PDD6o<PP>, 2: PDD6o<OD>, 3: PWM0<PP>, 4: PWM0<OD>,
//        5:TCON[3], 6:IICSDA2)

// R0_AUX_SCL
#define _PIN_J6                                 (3 & 0x07) // Page 10-0x5F[2:0]
// 0 ~ 3 (0: PDD7i<I>, 1: reserved, 2: PDD7o<OD>, 3: DDCSCL5)

// R0_AUX_SDA
#define _PIN_J5                                 (3 & 0x07) // Page 10-0x60[2:0]
// 0 ~ 3 (0: PED0i<I>, 1: reserved, 2: PED0o<OD>, 3: DDCSDA5)

// R1_AUX_SCL
#define _PIN_K6                                 (3 & 0x07) // Page 10-0x61[2:0]
// 0 ~ 3 (0: PED1i<I>, 1: reserved, 2: PED1o<OD>, 3: DDCSCL4)

// R1_AUX_SDA
#define _PIN_K5                                 (3 & 0x07) // Page 10-0x62[2:0]
// 0 ~ 3 (0: PED2i<I>, 1: reserved, 2: PED2o<OD>, 3: DDCSDA4)

// DDCSCL_3
#define _PIN_L6                                 (3 & 0x07) // Page 10-0x63[2:0]
// 0 ~ 3 (0: PED3i<I>, 1: reserved, 2: PED3o<OD>, 3: DDCSCL3)

// DDCSDA_3
#define _PIN_L5                                 (3 & 0x07) // Page 10-0x64[2:0]
// 0 ~ 3 (0: PED4i<I>, 1: reserved, 2: PED4o<OD>, 3: DDCSDA3)

// DDCSCL_2
#define _PIN_M6                                 (3 & 0x07) // Page 10-0x65[2:0]
// 0 ~ 3 (0: PED5i<I>, 1: reserved, 2: PED5o<OD>, 3: DDCSCL2)

// DDCSDA_2
#define _PIN_M5                                 (3 & 0x07) // Page 10-0x66[2:0]
// 0 ~ 3 (0: PED6i<I>, 1: reserved, 2: PED6o<OD>, 3: DDCSDA2)

// DP33V_ON
#define _PIN_H7                                 (0 & 0x07) // Page 10-0x67[2:0]
// 0 ~ 3 (0: PED7i<I>, 1: PED7o<PP>, 2: PED7o<OD>)

// NC
#define _PIN_K7                                 (1 & 0x07) // Page 10-0x68[2:0]
// 0     (0: PFD0i<I>)

// NC
#define _PIN_C8                                 (1 & 0x07) // Page 10-0x69[2:0]
// 0 ~ 2 (0: PFD1i<I>, 1: PFD1o<PP>, 2: PFD1o<OD>)

// NC
#define _PIN_N6                                 (1 & 0x07) // Page 10-0x6A[2:0]
// 0 ~ 2 (0: PFD2i<I>, 1: PFD2o<PP>, 2: PFD2o<OD>)

// NC
#define _PIN_C6                                 (1 & 0x07) // Page 10-0x6B[2:0]
// 0 ~ 2 (0: PFD3i<I>, 1: PFD3o<PP>, 2: PFD3o<OD>)

// NC
#define _PIN_N5                                 (1 & 0x07) // Page 10-0x6C[2:0]
// 0 ~ 2 (0: PFD4i<I>, 1: PFD4o<PP>, 2: PFD4o<OD>)


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
// N28,N29,M28,M29,J29,N27,K27,M27,K29,J28
// J27,K28
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
// Macro of VCCK_ON/VCCK_OFF Power Control
//-----------------------------------------------
#define bVCCKOFFPOWER                           (MCU_FE23_PORT83_PIN_REG) // Pin_AH21
#define bRLE0779VCCKOFFPOWER                    (MCU_FE26_PORT86_PIN_REG) // Pin_AJ20
#define bRLE0779VCCKONPOWER                     (MCU_FE25_PORT85_PIN_REG) // Pin_AJ21
#define bRLE0779V33SPOWER                       (MCU_FE27_PORT87_PIN_REG) // Pin_AH20

#define _VCCK_OFF_POWER_ON                      1
#define _VCCK_OFF_POWER_OFF                     0

#define _V33S_POWER_ON                          1
#define _V33S_POWER_OFF                         0

#define PCB_VCCK_OFF_POWER(x)                   {\
                                                    bVCCKOFFPOWER = (x);\
                                                }

#define PCB_RLE0779_VCCK_OFF_POWER(x)           {\
                                                    bRLE0779VCCKOFFPOWER = (x);\
                                                }

#define PCB_RLE0779_VCCK_ON_POWER(x)            {\
                                                    bRLE0779VCCKONPOWER = (x);\
                                                }

#define PCB_RLE0779_V33S_POWER(x)               {\
                                                    bRLE0779V33SPOWER = (x);\
                                                }

//-----------------------------------------------
// Macro of DDR Poewr Control
//-----------------------------------------------
#define bDDRPOWER                               (MCU_FE24_PORT84_PIN_REG) // Pin_AK21

#define _DDR_POWER_ON                           1
#define _DDR_POWER_OFF                          0

#define PCB_DDR_POWER(x)                        {\
                                                    bDDRPOWER = (x);\
                                                }


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_FE0C_PORT54_PIN_REG) // Pin_AM3

#define _PANEL_CONTROL_ON                       0
#define _PANEL_CONTROL_OFF                      1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_FE32_PORTA2_PIN_REG) // Pin_AJ27

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
#define bFLASH_WRITE_PROTECT                    (MCU_FE28_PORT90_PIN_REG) // Pin_AL21

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_FE0D_PORT55_PIN_REG) // Pin_G7

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_FE30_PORTA0_PIN_REG)  // Pin_AG24

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

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
#define bD0_DP_PIN15_CONNECT                    (MCU_FE33_PORTA3_PIN_REG)  // Pin_AG29
#define bD0_DP_PIN16_CONNECT                    (MCU_FE35_PORTA5_PIN_REG)  // Pin_AF29
#define bD0_DP_PIN17_CONNECT                    (MCU_FE34_PORTA4_PIN_REG)  // Pin_AH25
#define bD0_CONNECT                             (0) // (((bit)bD0_DP_PIN15_CONNECT == _TRUE) && ((bit)bD0_DP_PIN16_CONNECT == _TRUE) && ((bit)bD0_DP_PIN17_CONNECT == _FALSE))

#define bD1_DP_PIN15_CONNECT                    (MCU_FE36_PORTA6_PIN_REG)   // Pin_AJ25
#define bD1_DP_PIN16_CONNECT                    (MCU_FE38_PORTB0_PIN_REG)   // Pin_AH24
#define bD1_DP_PIN17_CONNECT                    (MCU_FE37_PORTA7_PIN_REG)   // Pin_AG28
#define bD1_CONNECT                             (0) // (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))

#define bD2_CONNECT                             (MCU_FE46_PORTC6_PIN_REG)// Pin_AJ4
#define bD3_CONNECT                             (MCU_FE3B_PORTB3_PIN_REG)// Pin_AG27

#define PCB_D0_PIN()                            (bD0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)
#define PCB_D2_PIN()                            (bD2_CONNECT)
#define PCB_D3_PIN()                            (bD3_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D0_DP_SOURCE_POWER()            (bD0_DP_PIN17_CONNECT)
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)

//-----------------------------------------------
// Macro of MHL Cable Connect
//-----------------------------------------------
#define bD2_MHL_CONNECT                         (P1_5) // Pin_W6
#define bD3_MHL_CONNECT                         (P1_7) // Pin_W5

#define PCB_D2_MHL_DETECT()                     (bD2_MHL_CONNECT)
#define PCB_D3_MHL_DETECT()                     (bD3_MHL_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD0_HPD                                 (MCU_FE4C_PORTD4_PIN_REG) // Pin_AH5
#define bD1_HPD                                 (MCU_FE4B_PORTD3_PIN_REG) // Pin_AH6
#define bD2_HPD                                 (P1_4) // PIN_L4
#define bD3_HPD                                 (P1_6) // Pin_F4

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


///////////////
// MHL Macro //
///////////////

//-----------------------------------------------
// Macro of HDMI/MHL Switch
//-----------------------------------------------
#define bD2_TMDS_SWITCH                         (MCU_FE4A_PORTD2_PIN_REG) // Pin_AH7
#define bD3_TMDS_SWITCH                         (MCU_FE49_PORTD1_PIN_REG) // Pin_AG7

#define _TMDS_SWITCH_MHL_CBUS                   0
#define _TMDS_SWITCH_HDMI_HPD                   1

#define PCB_D2_HDMI_MHL_SWITCH(x)               {\
                                                    bD2_TMDS_SWITCH = (x);\
                                                }

#define PCB_D3_HDMI_MHL_SWITCH(x)               {\
                                                    bD3_TMDS_SWITCH = (x);\
                                                }

//-----------------------------------------------
// Macro of MHL VBus Switch
//-----------------------------------------------
#define bD2_MHL_VBUS_SWITCH                     (MCU_FE2B_PORT93_PIN_REG) // Pin_AG25
#define bD3_MHL_VBUS_SWITCH                     (MCU_FE2C_PORT94_PIN_REG) // Pin_AH26

#define _MHL_VBUS_ON                            1
#define _MHL_VBUS_OFF                           0

#define PCB_D2_MHL_VBUS_SWITCH(x)               {\
                                                    bD2_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

#define PCB_D3_MHL_VBUS_SWITCH(x)               {\
                                                    bD3_MHL_VBUS_SWITCH = (x);\
                                                    PCB_MHL_VBUS_POWER(x);\
                                                }

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


///////////////
// LED Macro //
///////////////

//--------------------------------------------------
// Macro of LED On/Off
//--------------------------------------------------
#define bLED1                                   (MCU_FE03_PORT43_PIN_REG) // Pin_AJ9
#define bLED2                                   (MCU_FE04_PORT44_PIN_REG) // Pin_AJ8

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
                                                    bLED1 = _LED_OFF;\
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
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT)// Pin_AH9
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT)// Pin_AH8

#define PCB_ADKEY1()                            (AD_KEY1)
#define PCB_ADKEY2()                            (AD_KEY2)

#define PCB_KEY_STATE(ucV0, ucV1,\
                      ucV2, ucV3, ucKeyState)   {\
                                                    if((0 <= (ucV2)) && ((ucV2) < 0x20))\
                                                    {\
                                                        (ucKeyState) |= _LEFT_KEY_MASK;\
                                                    }\
                                                    if((0x40 <= (ucV2)) && ((ucV2) < 0x80))\
                                                    {\
                                                        (ucKeyState) |= _RIGHT_KEY_MASK;\
                                                    }\
                                                    if((0x90 <= (ucV2)) && ((ucV2) < 0xE0))\
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


//////////////////
// GPIO Macro   //
//////////////////

//-----------------------------------------------
// Macro of GPIO
//-----------------------------------------------
#define bGPIO1                                  (MCU_FE14_PORT64_PIN_REG) // Pin_AD28
#define bGPIO2                                  (MCU_FE15_PORT65_PIN_REG) // Pin_AH27
#define bGPIO3                                  (MCU_FE2D_PORT95_PIN_REG) // Pin_AG26
#define bGPIO4                                  (MCU_FE2F_PORT97_PIN_REG) // Pin_AF28
#define bGPIO5                                  (MCU_FE31_PORTA1_PIN_REG) // Pin_AE28

#define _High                                   1
#define _Low                                    0

#define PCB_SET_GPIO_1(x)                       {\
                                                    bGPIO1 = (x);\
                                                }

#define PCB_SET_GPIO_2(x)                       {\
                                                    bGPIO2 = (x);\
                                                }

#define PCB_SET_GPIO_3(x)                       {\
                                                    bGPIO3 = (x);\
                                                }

#define PCB_SET_GPIO_4(x)                       {\
                                                    bGPIO4 = (x);\
                                                }

#define PCB_SET_GPIO_5(x)                       {\
                                                    bGPIO5 = (x);\
                                                }

#define PCB_GET_GPIO_1()                        (bGPIO1)
#define PCB_GET_GPIO_2()                        (bGPIO2)
#define PCB_GET_GPIO_3()                        (bGPIO3)
#define PCB_GET_GPIO_4()                        (bGPIO4)
#define PCB_GET_GPIO_5()                        (bGPIO5)

#endif // End of #if(_PCB_TYPE == _RL6410_DEMO_5K3K_2H2DP_LVDS_eDP)
