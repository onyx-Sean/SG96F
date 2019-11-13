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
// ID Code      : RL6369_DEMO_76PIN_1A1H.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#if(_PCB_TYPE == _RL6369_DEMO_76PIN_1A1H)


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
#define _D1_INPUT_PORT_TYPE                     _D1_HDMI_PORT
#define _D1_DDC_CHANNEL_SEL                     _DDC1
#define _D1_EMBEDDED_DDCRAM_SIZE                _EDID_SIZE_NONE
#define _D1_EMBEDDED_DDCRAM_LOCATION            _EDID_TABLE_LOCATION_CODE


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
#define _LVDS_SPREAD_RANGE                      10
#define _LVDS_SPREAD_SPEED                      _SPEED_33K


/////////
// PWM //
/////////

//--------------------------------------------------
// PWM Setting
//--------------------------------------------------
#define _PWM_DUT_RESOLUTION                     _PWM_8BIT

#define _BACKLIGHT_PWM                          _PWM4
#define _BACKLIGHT_PWM_INVERSE                  _ON

#define _PWM0_EN                                _OFF
#define _PWM1_EN                                _OFF
#define _PWM2_EN                                _OFF
#define _PWM3_EN                                _OFF
#define _PWM4_EN                                _ON
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
#define _PWM4_RST_BY_DVS                        _ON
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
#define _PCB_SYS_EEPROM_IIC                     _HW_IIC_76PIN_31_32


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
//  RL6369 128 Pin Share
//--------------------------------------------------
// EDID_WP
#define _76PIN_PIN_21                           (2 & 0x0F) // Page 10-0x02[3:0]
// 0 ~ 15 (0: P1d2i <I> , 1: P1d2o <PP>, 2: P1d2o <OD>, 3: PWM0<PP> , 4: PWM0<OD>, 5: IIS_MCK, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// HDMI_CABLE_Det
#define _76PIN_PIN_22                           (0 & 0x0F) // Page 10-0x03[3:0]
// 0 ~ 15 (0: P1d3i <I> , 1: P1d3o <PP>, 2: P1d3o <OD>, 3: PWM1<PP> , 4: PWM1<OD>, 5: IIS_SCK, 6:IRQB, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// HDMI_HOT_PLUG
#define _76PIN_PIN_23                           (2 & 0x0F) // Page 10-0x04[3:0]
// 0 ~ 15 (0: P1d4i <I> , 1: P1d4o <PP>, 2: P1d4o <OD>, 3: PWM2<PP> , 4: PWM2<OD>, 5: IIS_WS, 6: Tcon[13], 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// LED_2
#define _76PIN_PIN_24                           (1 & 0x0F) // Page 10-0x05[3:0]
// 0 ~ 15 (0: P1d5i <I> , 1: P1d5o <PP>, 2: P1d5o <OD>, 3: PWM3<PP> , 4: PWM3<OD>, 5: IIS_SD0, 6: Spdif0, 7: IICSCL0, 8: Rxd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// LED_1
#define _76PIN_PIN_25                           (1 & 0x0F) // Page 10-0x06[3:0]
// 0 ~ 15 (0: P1d6i <I> , 1: P1d6o <PP>, 2: P1d6o <OD>, 3: PWM4<PP> , 4: PWM4<OD>, 5: IIS_SD1, 6: Spdif1, 7: IICSDA0, 8: Txd, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// KEY1
#define _76PIN_PIN_27                           (3 & 0x0F) // Page 10-0x08[3:0]
// 0 ~ 15 (0: P3d0i <I> , 1: P3d0o <PP>, 2: P3d0o <OD>, 3: A-adc0, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// KEY2
#define _76PIN_PIN_28                           (3 & 0x0F) // Page 10-0x09[3:0]
// 0 ~ 15 (0: P3d1i <I> , 1: P3d1o <PP>, 2: P3d1o <OD>, 3: A-adc1, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// NC
#define _76PIN_PIN_29                           (1 & 0x0F) // Page 10-0x0A[3:0]
// 0 ~ 15 (0: P3d2i <I> , 1: P3d2o <PP>, 2: P3d2o <OD>, 3: A-adc2, 4~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// VGA_CABLE_Det
#define _76PIN_PIN_30                           (0 & 0x0F) // Page 10-0x0C[3:0]
// 0 ~ 15 (0: P3d4i <I> , 1: P3d4o <PP>, 2: P3d4o <OD>, 3: PWM1<PP>, 4: PWM1<OD>, 5: PWM5<PP> , 6: PWM5<OD>, 7: Tcon[7], 8: Tcon[13], 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// EESCL
#define _76PIN_PIN_31                           (7 & 0x0F) // Page 10-0x0D[3:0]
// 0 ~ 15 (0: P3d5i <I> , 1: P3d5o <PP>, 2: P3d5o <OD>, 3: Tcon[8] ,4: Tcon[12], 5~6: reserved, 7: IICSCL1, 8: IICSCL_AUX, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// EESDA
#define _76PIN_PIN_32                           (7 & 0x0F) // Page 10-0x0E[3:0]
// 0 ~ 15 (0: P3d6i <I> , 1: P3d6o <PP>, 2: P3d6o <OD>, 3~6: reserved, 7: IICSDA1, 8: IICSDA_AUX, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// VGADDCSCL
#define _76PIN_PIN_33                           (7 & 0x0F) // Page 10-0x0F[3:0]
// 0 ~ 15 (0: P3d7i <I> , 1: P3d7o <PP>, 2: P3d7o <OD>, 3~6: reserved, 7: DDCSCLVGA, 8: RXD, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// VGADDCSDA
#define _76PIN_PIN_34                           (7 & 0x0F) // Page 10-0x10[3:0]
// 0 ~ 15 (0: P4d0i <I> , 1: P4d0o <PP>, 2: P4d0o <OD>, 3: Tcon[11] ,4: Tcon[13], 5~6: reserved, 7: DDCSDAVGA, 8: TXD, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// SYSTEM_EEPROM_WP
#define _76PIN_PIN_37                           (2 & 0x0F) // Page 10-0x1B[3:0]
// 0 ~ 15 (0: P5d3i <I> , 1: P5d3o <PP>, 2: P5d3o <OD>, 3: PWM0<PP>, 4: PWM0<OD>, 5: PWM3<PP>, 6: PWM3<PP>, 7: Tcon[7], 8: Int1, 9: T2, 10: IHS_after_scaling_down, 11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// Panel_ON
#define _76PIN_PIN_38                           (1 & 0x0F) // Page 10-0x1A[3:0]
// 0 ~ 15 (0: P5d2i <I> , 1: P5d2o <PP>, 2: P5d2o <OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: Tcon[8], 6: Int0, 7: IENA_after_scaling_down, 8: CLKO, 9~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO3+
#define _76PIN_PIN_39                           (4 & 0x0F) // Page 10-0x1E[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d6i <I>, 2: P5d6o <PP>, 3: P5d6o <OD>, 4: TXO3+_8b_10b, 5: TTL_BLU5, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO3-
#define _76PIN_PIN_40                           (4 & 0x0F) // Page 10-0x1F[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P5d7i <I>, 2: P5d7o <PP>, 3: P5d7o <OD>, 4: TXO3-_8b_10b, 5: TTL_BLU4, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO2+
#define _76PIN_PIN_41                           (4 & 0x0F) // Page 10-0x20[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d0i <I>, 2: P6d0o <PP>, 3: P6d0o <OD>, 4: TXO2+_8b_10b, 5: TTL_BLU3, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO2-
#define _76PIN_PIN_42                           (4 & 0x0F) // Page 10-0x21[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d1i <I>, 2: P6d1o <PP>, 3: P6d1o <OD>, 4: TXO2-_8b_10b, 5: TTL_BLU2, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO1+
#define _76PIN_PIN_43                           (4 & 0x0F) // Page 10-0x22[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d2i <I>, 2: P6d2o <PP>, 3: P6d2o <OD>, 4: TXO1+_8b_10b, 5: TTL_BLU1, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO1-
#define _76PIN_PIN_44                           (4 & 0x0F) // Page 10-0x23[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d3i <I>, 2: P6d3o <PP>, 3: P6d3o <OD>, 4: TXO1-_8b_10b, 5: TTL_BLU0, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO0+
#define _76PIN_PIN_45                           (4 & 0x0F) // Page 10-0x24[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d4i <I>, 2: P6d4o <PP>, 3: P6d4o <OD>, 4:TXO0+_8b_10b, 5:TTL_GRN7, 6~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// TXO0-
#define _76PIN_PIN_46                           (4 & 0x0F) // Page 10-0x25[3:0]
// 0 ~ 15 (0: Hi-Z <I> , 1:P6d5i <I>, 2: P6d5o <PP>, 3: P6d5o <OD>, 4: TXO0-_8b_10b, 5: TTL_GRN6, 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// FLASH_WP
#define _76PIN_PIN_58                           (1 & 0x0F) // Page 10-0x28[3:0]
// 0 ~ 15 (0: P7d0i <I> , 1: P7d0o <PP>, 2: P7d0o <OD>, 3: Int0, 4: TTL_RED1, 5~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// NC
#define _76PIN_PIN_59                           (1 & 0x0F) // Page 10-0x29[3:0]
// 0 ~ 15 (0: P7d1i <I> , 1: P7d1o <PP>, 2: P7d1o <OD>, 3: Int1, 4: Tcon[11], 5: IVS_after_scaling_down, 6: TTL_RED0, 7~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// NC
#define _76PIN_PIN_60                           (1 & 0x0F) // Page 10-0x2A[3:0]
// 0 ~ 15 (0: P7d2i <I> , 1: P7d2o <PP>, 2: P7d2o <OD>, 3: T0, 4: DENA , 5: Tcon[9], 6~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// NC
#define _76PIN_PIN_61                           (1 & 0x0F) // Page 10-0x2B[3:0]
// 0 ~ 15 (0: P7d3i <I> , 1: P7d3o <PP>, 2: P7d3o <OD>, 3: PWM2<PP>, 4: PWM2<OD>, 5: PWM3<PP>, 6: PWM3<OD>, 7: T1, 8: DHS, 9: Tcon[13] 10~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// BL_EN
#define _76PIN_PIN_62                           (1 & 0x0F) // Page 10-0x2C[3:0]
// 0 ~ 15 (0: P7d4i <I> , 1: P7d4o <PP>, 2: P7d4o <OD>, 3: Aux_d2, 4: DCLK , 5: Tcon[8] , 6: Pwm_in , 7:T2EX , 8~11:reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// BL_ADJ
#define _76PIN_PIN_63                           (3 & 0x0F) // Page 10-0x2D[3:0]
// 0 ~ 15 (0: P7d5i <I> , 1: P7d5o <PP>, 2: P7d5o <OD>, 3: PWM4<PP>, 4: PWM4<OD>, 5: Aux_d1, 6: DVS, 7: Tcon[7], 8: Pwm_out, 9~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSCL2
#define _76PIN_PIN_70                           (7 & 0x0F) // Page 10-0x30[3:0]
// 0 ~ 15 (0: P8d0i <I> , 1: P8d0o <PP>, 2: P8d0o <OD>, 3:Auxp, 4~6:reserved, 7:  DDCSCL1, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)

// DDCSDA2
#define _76PIN_PIN_71                           (7 & 0x0F) // Page 10-0x31[3:0]
// 0 ~ 15 (0: P8d1i <I> , 1: P8d1o <PP>, 2: P8d1o <OD>, 3:Auxn, 4~6:reserved, 7: DDCSDA1, 8~11: reserved, 12: Test4b_out0, 13: Test4b_out1, 14: Test4b_out2, 15:Test4b_out3)


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


///////////////////////
// Panel Power Macro //
///////////////////////

//--------------------------------------------------
// Macro of Panel Power Up/Down
//--------------------------------------------------
#define bPANELPOWER                             (MCU_FE0A_PORT52_PIN_REG) // 76pin_Pin38

#define _PANEL_CONTROL_ON                       0
#define _PANEL_CONTROL_OFF                      1

#define PCB_PANEL_POWER(x)                      {\
                                                    bPANELPOWER = (x);\
                                                }

#define PCB_PANEL_POWER_DETECT()                (bPANELPOWER)

//--------------------------------------------------
// Macro of Light Power Up/Down
//--------------------------------------------------
#define bBACKLIGHTPOWER                         (MCU_FE1C_PORT74_PIN_REG) // 76pin_Pin62

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
#define bFLASH_WRITE_PROTECT                    (MCU_FE18_PORT70_PIN_REG)  // 76Pin_Pin_58, P7.0

#define _FLASH_WRITE_PROTECT_ENABLE             0
#define _FLASH_WRITE_PROTECT_DISABLE            1

#define PCB_FLASH_WRITE_PROTECT(x)              {\
                                                    bFLASH_WRITE_PROTECT = (x);\
                                                }

//-----------------------------------------------
// Macro of System Eeprom WP High/Low
//-----------------------------------------------
#define bEEPROM_WRITE_PROTECT                   (MCU_FE0B_PORT53_PIN_REG) // 76Pin_Pin_37, P5.3

#define _EEPROM_WP_ENABLE                       1
#define _EEPROM_WP_DISABLE                      0

#define PCB_EEPROM_WRITE_PROTECT(x)             {\
                                                    bEEPROM_WRITE_PROTECT = (x);\
                                                }

#define PCB_EEPROM_WRITE_PROTECT_DETECT()       (bEEPROM_WRITE_PROTECT)

//-----------------------------------------------
// Macro of EDID Eeprom WP High/Low
//-----------------------------------------------
#define bEDID_WRITE_PROTECT                     (P1_2) // 76Pin_Pin_21, P1.2

#define _EDID_EEPROM_WP_ENABLE                  1
#define _EDID_EEPROM_WP_DISABLE                 0

#define PCB_A0_EDID_EEPROM_WRITE_PROTECT(x)     {\
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
#define bA0_CONNECT                             (P3_4)
#define bD1_CONNECT                             (P1_3)

#define PCB_A0_PIN()                            (bA0_CONNECT)
#define PCB_D1_PIN()                            (bD1_CONNECT)


////////////////////
// Hot Plug Macro //
////////////////////

//-----------------------------------------------
// Macro of Digital Hot Plug High/Low
//-----------------------------------------------
#define bD1_HPD                                 (P1_4) // 73PIN_Pin_23, P1.4

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
#define bLED1                                   (P1_6) // Pin_25, P1.6
#define bLED2                                   (P1_5) // Pin_24, P1.5

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
#define AD_KEY0                                 (MCU_FF09_ADC_A0_CONVERT_RESULT) // 76PIN_28PIN P3.1
#define AD_KEY1                                 (MCU_FF0A_ADC_A1_CONVERT_RESULT) // 76PIN_27PIN P3.0

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

#endif // End of #if(_PCB_TYPE == _RL6369_DEMO_76PIN_1A1H)
