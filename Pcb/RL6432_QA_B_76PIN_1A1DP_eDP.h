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
// ID Code      : RL6432_QA_B_76PIN_1A1DP_eDP.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6432_QA_B_76PIN_1A1DP_eDP)


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
// D1 Input Port
//--------------------------------------------------
#define _D1_INPUT_PORT_TYPE                     _D1_DP_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_256
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_USER
#define _D1_DP_CONNECTOR_TYPE                   _DP_CONNECTOR_NORMAL
#define _D1_DP_LINK_CLK_RATE                    _DP_HIGH_SPEED2_540MHZ
#define _D1_DP_MAIN_LINK_LANES                  _DP_FOUR_LANE


/////////////////////////////
// Search Group & Priority //
/////////////////////////////

//--------------------------------------------------
// Input Port Search Group Define
//--------------------------------------------------
#define _A0_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0
#define _D1_INPUT_PORT_GROUP                    _INPUT_PORT_GROUP_0

//--------------------------------------------------
// Input Port Search Priority Define (Must Start From Valid Port)
//--------------------------------------------------
#define _INPUT_PORT_SEARCH_PRI_0                _A0_INPUT_PORT
#define _INPUT_PORT_SEARCH_PRI_1                _D1_INPUT_PORT


/////////////////////////
// eDPTx 1.1 HBR Panel //
/////////////////////////

//--------------------------------------------------
// eDPTx 1.1 HBR Main Link Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_LANE_SWAP               _DISABLE
#define _PANEL_DPTX_1_1_LANE_PN_SWAP            _DISABLE
#define _PANEL_DPTX_1_1_SWING_LEVEL             _DP_SWING_800_MV
#define _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL       _DP_PREEMPHASIS_0_DB

//--------------------------------------------------
// eDPTx 1.1 HBR SSC Config
//--------------------------------------------------
#define _PANEL_DPTX_1_1_SPREAD_RANGE            5
#define _PANEL_DPTX_1_1_SPREAD_SPEED            _SPEED_33K


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM2
#define _BACKLIGHT_PWM_INVERSE                  _ON

#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _ON
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _OFF

#define _PWM0_PSAV_EN                           _OFF
#define _PWM1_PSAV_EN                           _OFF
#define _PWM2_PSAV_EN                           _OFF
#define _PWM3_PSAV_EN                           _OFF
#define _PWM4_PSAV_EN                           _OFF

#define _PWM0_PDOW_EN                           _OFF
#define _PWM1_PDOW_EN                           _OFF
#define _PWM2_PDOW_EN                           _OFF
#define _PWM3_PDOW_EN                           _OFF
#define _PWM4_PDOW_EN                           _OFF

#define _PWM0_RST_BY_DVS                        _OFF
#define _PWM1_RST_BY_DVS                        _OFF
#define _PWM2_RST_BY_DVS                        _OFF
#define _PWM3_RST_BY_DVS                        _OFF
#define _PWM4_RST_BY_DVS                        _OFF
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
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_76PIN_76_1


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
// RL6432 Series Pin Share //
/////////////////////////////

//--------------------------------------------------
//  RL6432 76 Pin Share
//--------------------------------------------------
// LED2
#define _76PIN_PIN_16                           (1 & 0x0F) // Page 10-0x03[2:0]
// 0 ~ 7 (0: P1D3i<I>,    1: P1D3o<PP>,   2: P1D3o<OD>, 3: tcon[0], 4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

// DP_CABLE_DET_1_1
#define _76PIN_PIN_17                           (0 & 0x0F) // Page 10-0x04[2:0]
// 0 ~ 7 (0: P1D4i<I>,    1: P1D4o<PP>,   2: P1D4o<OD>, 3: tcon[8],  4: test4b_out0,
//        5: test4b_out1, 6: test4b_out2, 7: test4b_out3)

// DDCSCL_VGA
#define _76PIN_PIN_29                           (8 & 0x0F) // Page 10-0x05[2:0]
// 0 ~ 8 (0: P1D5i<I>, 1: P1D5o<PP>, 2: P1D5o<OD>, 8: DDCSCLVGA)

// DDCSDA_VGA
#define _76PIN_PIN_30                           (8 & 0x0F) // Page 10-0x06[2:0]
// 0 ~ 8 (0: P1D6i<I>, 1: P1D6o<PP>, 2: P1D6o<OD>, 8: DDCSDAVGA)

// VGA_CABLE_DET
#define _76PIN_PIN_31                           (0 & 0x0F) // Page 10-0x07[2:0]
// 0 ~ 2 (0: P1D7i<I>, 1: P1D7o<PP>,   2: P1D7o<OD>, 3: pwm0 <PP>,  4: pwm0 <OD>,
//        5: tcon[4],  6: test4b_out2, 7: test4b_out3)

// AUX_CHP_1
#define _76PIN_PIN_33                           (3 & 0x0F) // Page 10-0x0A[2:0]
// 0 ~ 8 (0: P3D2i<I>, 1: Reserved, 2: P3D2o<OD>, 3: AUXp1, 8:DDCSCL1)

// AUX_CHN_1
#define _76PIN_PIN_34                           (3 & 0x0F) // Page 10-0x0B[2:0]
// 0 ~ 8 (0: P3D3i<I>, 1: Reserved, 2: P3D1o<OD>, 3: AUXn1, 8: DDSSDA1)

// ADC_KEY1
#define _76PIN_PIN_39                           (3 & 0x0F) // Page 10-0x0C[2:0]
// 0 ~ 6 (0: P3D4i<I>,     1: P3D4o<PP>, 2: P3D4o<OD>, 3: a_adc0_0, 4: int0,
//        5: test4b_out0 , 6:test4b_out1)

// ADC_KEY2
#define _76PIN_PIN_38                           (3 & 0x0F) // Page 10-0x0D[2:0]
// 0 ~ 6 (0: P3D5i<I>,     1: P3D5o<PP>, 2: P3D5o<OD>, 3: a_adc1_0, 4: int1,
//        5: test4b_out2 , 6:test4b_out3)

// DPTX_AUX_P_2
#define _76PIN_PIN_58                           (6 & 0x0F) // Page 10-0x19[2:0]
// 0 ~ 6 (0: P5D1i<I>, 1: P5D1o<PP>, 2: P5D1o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: tcon[6],  6: DPTX_aux_ch_p_1)

// DPTX_AUX_N_2
#define _76PIN_PIN_57                           (6 & 0x0F) // Page 10-0x1A[2:0]
// 0 ~ 6 (0: P5D2i<I>, 1: P5D2o<PP>, 2: P5D2o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[7],  6: DPTX_aux_ch_n_1)

// TX2_HPD_2
#define _76PIN_PIN_56                           (3 & 0x0F) // Page 10-0x1B[2:0]
// 0 ~ 4 (0: P5D3i<I>, 1: P5D3o<PP>, 2: P5D3o<OD>, 3: DPTX_hpd1_org, 4:  tcon[8])

// FLASH_WP
#define _76PIN_PIN_65                           (1 & 0x0F) // Page 10-0x29[2:0]
// 0 ~ 2 (0: P7D1i<I>, 1: P7D1o<PP>, 2: P7D1o<OD>)

// ADJBACKLITE
#define _76PIN_PIN_66                           (3 & 0x0F) // Page 10-0x2A[2:0]
// 0 ~ 6 (0: P7D2i<I>, 1: P7D2o<PP>, 2: P7D2o<OD>, 3: PWM2<PP>, 4: PWM2<OD>,
//        5: TCON[1],  6: IRDA_in )

// LED1
#define _76PIN_PIN_68                           (1 & 0x0F) // Page 10-0x30[2:0]
// 0 ~ 8 (0: P8D0i<I>, 1: P8D0o<PP>, 2: P8D0o<OD>, 3: PWM4<PP>, 4: PWM4<OD>,
//        5: TCON[11], 8: IICSCL2)

// EDID_WP
#define _76PIN_PIN_69                           (2 & 0x0F) // Page 10-0x31[2:0]
// 0 ~ 8 (0: P8D1i<I>, 1: P8D1o<PP>, 2: P8D1o<OD>, 3: PWM3<PP>, 4: PWM3<OD>,
//        5: TCON[0],  8: IICSDA2)

// DP_SINK_ASS_N1
#define _76PIN_PIN_70                           (0 & 0x0F) // Page 10-0x32[2:0]
// 0 ~ 8 (0: P8D2i<I>,    1: P8D2o<PP>,   2: P8D2o<OD>,   3:  int0, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3, 8: TXD)

// DP_HOT_PLUG_1
#define _76PIN_PIN_67                           (1 & 0x0F) // Page 10-0x33[2:0]
// 0 ~ 8 (0: P8D3i<I>,    1: P8D3o<PP>,   2: P8D3o<OD>,   3: int1, 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3, 8: RXD)

// Panel_ON
#define _76PIN_PIN_71                           (1 & 0x0F) // Page 10-0x34[2:0]
// 0 ~ 7 (0: P8D4i<I>,    1: P8D4o<PP>,   2: P8D4o<OD>, 3: tcon[13], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// VCCK_OFF_EN
#define _76PIN_PIN_72                           (2 & 0x0F) // Page 10-0x35[2:0]
// 0 ~ 7 (0: P8D5i<I>,    1: P8D5o<PP>,   2: P8D5o<OD>, 3: tcon[12], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// DP_SINK_ASS_P1
#define _76PIN_PIN_73                           (0 & 0x0F) // Page 10-0x36[2:0]
// 0 ~ 7 (0: P8D6i<I>,    1: P8D6o<PP>,   2: P8D6o<OD>, 3:  tcon[10], 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// onBACKLITE
#define _76PIN_PIN_74                           (2 & 0x0F) // Page 10-0x37[2:0]
// 0 ~ 7 (0: P8D7i<I>,    1: P8D7o<PP>,   2: P8D7o<OD>, 3: tcon[9] , 4: Test4b_out0,
//        5: Test4b_out1, 6: Test4b_out2, 7: Test4b_out3)

// EEPROM_WP
#define _76PIN_PIN_75                           (2 & 0x0F) // Page 10-0x39[2:0]
// 0 ~ 5 (0: P9D1i<I>, 1: P9D1o<PP>, 2: P9D1o<OD>, 3: PWM2<PP>, 4: PWM2<OD>
//        5: TCON[3])

// EESCL
#define _76PIN_PIN_76                           (8 & 0x0F) // Page 10-0x3A[2:0]
// 0 ~ 8 (0: P9D2i<I>, 1: P9D2o<PP>, 2: P9D2o<OD>, 3: PWM0<PP>, 4: PWM0<OD>
//        5: TCON[1],  8: EEIICSCL)

// EESDA
#define _76PIN_PIN_1                            (8 & 0x0F) // Page 10-0x3B[2:0]
// 0 ~ 8 (0: P9D3i<I>, 1: P9D3o<PP>, 2: P9D3o<OD>, 3: PWM1<PP>, 4: PWM1<OD>,
//        5: TCON[2],  8:EEIICSDA)


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
#define bVCCKOFFPOWER                           (MCU_FE25_PORT85_PIN_REG) // 76PIN_PIN_72, P8.5

#define _VCCK_OFF_POWER_ON                      1
#define _VCCK_OFF_POWER_OFF                     0

#define PCB_VCCK_OFF_POWER(x)                   {\
                                                    bVCCKOFFPOWER = (x);\
                                                }


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_FE24_PORT84_PIN_REG) // 76PIN_PIN_71, P8.4

#define _PANEL_CONTROL_ON                       0
#define _PANEL_CONTROL_OFF                      1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_FE27_PORT87_PIN_REG) // 76PIN_PIN_74, P8.7

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
#define bFLASH_WRITE_PROTECT                    (MCU_FE19_PORT71_PIN_REG) // 76PIN_PIN_65, P7.1

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_FE29_PORT91_PIN_REG) // 76PIN_PIN_75, P9.1

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (MCU_FE21_PORT81_PIN_REG) // 76PIN_PIN_69, P8.1

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
                                                    bEDID_WRITE_PROTECT = (x);\
                                                }

#define PCB_D1_EDID_EEPROM_WRITE_PROTECT(x)     {\
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
#define bD1_DP_PIN15_CONNECT                    (MCU_FE26_PORT86_PIN_REG) // 76PIN_PIN_73, P8.6
#define bD1_DP_PIN16_CONNECT                    (P1_4) // 76PIN_PIN_17, P1.4
#define bD1_DP_PIN17_CONNECT                    (MCU_FE22_PORT82_PIN_REG) // 76PIN_PIN_70, P8.2

#define bA0_CONNECT                             (P1_7)  // 76PIN_PIN_31, P1.7
#define bD1_CONNECT                             (((bit)bD1_DP_PIN15_CONNECT == _TRUE) && ((bit)bD1_DP_PIN16_CONNECT == _TRUE) && ((bit)bD1_DP_PIN17_CONNECT == _FALSE))

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)

//-----------------------------------------------
// Macro of DP Source Power
//-----------------------------------------------
#define GET_PCB_D1_DP_SOURCE_POWER()            (bD1_DP_PIN17_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD1_HPD                                 (MCU_FE23_PORT83_PIN_REG) // 76PIN_PIN_67, P8.3

#define _D1_HOT_PLUG_HIGH                       1
#define _D1_HOT_PLUG_LOW                        0

#define PCB_D1_HOTPLUG(x)                       {\
                                                    bD1_HPD = (x);\
                                                }

#define PCB_D1_HOTPLUG_DETECT()                 (bD1_HPD)


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
#define bLED1                                   (MCU_FE20_PORT80_PIN_REG) // 76PIN_PIN_68, P8.0
#define bLED2                                   (P1_3) // 76PIN_PIN_16, P1.3

#define _LED_ON                                 1
#define _LED_OFF                                0

#define PCB_LED_AC_ON_INITIAL()                 {\
                                                    bLED1 = _LED_OFF;\
                                                    bLED2 = _LED_ON;\
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

#define PCB_LED_TYPE_FLASH()                    {\
                                                }


//////////////////
// AD Key Macro //
//////////////////

//-----------------------------------------------
// Macro of Keypad Setting
//-----------------------------------------------
#define AD_KEY1                                 (MCU_FF09_ADC_A0_CONVERT_RESULT) // 76PIN_PIN_39,A-ADC0
#define AD_KEY2                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT) // 76PIN_PIN_38,A-ADC1

#define PCB_ADKEY1()                            (AD_KEY2)
#define PCB_ADKEY2()                            (AD_KEY1)

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

#endif // End of #if(_PCB_TYPE == _RL6432_QA_B_76PIN_1A1DP_eDP)
