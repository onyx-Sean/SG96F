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
// ID Code      : RL6463_Gen_Option.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_SCALER_TYPE == _RL6463_SERIES)

#ifndef __RL6463_GEN_OPTION__
#define __RL6463_GEN_OPTION__

////////
// HW //
////////

//--------------------------------------------------
// HW Input Port TMDS MAC USE
//--------------------------------------------------
#define _D0_TMDS_MAC_USE                                        _PAGE2
#define _D1_TMDS_MAC_USE                                        _PAGE2
#define _D2_TMDS_MAC_USE                                        _PAGE_NONE
#define _D3_TMDS_MAC_USE                                        _PAGE_NONE
#define _D4_TMDS_MAC_USE                                        _PAGE_NONE
#define _D5_TMDS_MAC_USE                                        _PAGE_NONE

//--------------------------------------------------
// HW PC99 FUNCTION SUPPORT
//--------------------------------------------------
#define _HW_PC99_SUPPORT                                        _ON
#define _HW_PC99_VGADDC2_SUPPORT                                _ON
//--------------------------------------------------
// Definitions of XRAM addresses
//--------------------------------------------------
#define _XRAM_ADDR_START                                        (0xE000)
#define _XRAM_ADDR_END                                          (0xE5FF)

//--------------------------------------------------
// Definitions of Combo Phy Support
//--------------------------------------------------
#define _HW_DIGITAL_PORT_COMBO_PHY_TYPE                         _DIGITAL_PORT_COMBO_PHY_ALL

//--------------------------------------------------
// HW DP Lane Swap Support
//--------------------------------------------------
#define _HW_DP_LANE_SWAP_SUPPORT                                _OFF

//--------------------------------------------------
// HW DP PN Swap Support
//--------------------------------------------------
#define _HW_DP_PN_SWAP_SUPPORT                                  _OFF

//--------------------------------------------------
// DDC Mapping Switch
//--------------------------------------------------
#define _DDC_CHANNEL_SWITCH_SUPPORT                             _ON

//--------------------------------------------------
// MCU PWM Hw Clock Source refence M2Pll / 2
//--------------------------------------------------
#define _HW_MCU_PWM_HW_REF_HALF_OF_M2PLL                        _ON

//--------------------------------------------------
// MCU PWM Support Bit
//--------------------------------------------------
#define _MCU_PWM_BIT_SUPPORT                                    _PWM_12BIT

//-------------------------------------------------
// FW Flash Clock Option
//-------------------------------------------------
#define _FLASH_CLK_SOURCE                                       _FLASH_EXT_XTAL_CLK

//-------------------------------------------------
// FW Access Flash Method
//-------------------------------------------------
#define _HW_FLASH_ACCESS_METHOD                                 _XDATA_MAP_ACCESS

//--------------------------------------------------
// HW Support LC Tank
//--------------------------------------------------
#define _LC_TANK_SUPPORT                                        _ON

//--------------------------------------------------
// eFuse Support
//--------------------------------------------------
#define _EFUSE_SUPPORT                                          _ON

//--------------------------------------------------
// IOSC Clock Frequncy Define
//--------------------------------------------------
#define _INTERNAL_OSC_XTAL                                      _IOSC28000K

//-------------------------------------------------
// M2PLL Structure
//-------------------------------------------------
#define _M2PLL_STRUCT_TYPE                                      _M2PLL_STRUCT_N_F

//-------------------------------------------------
// MPLL Structure
//-------------------------------------------------
#define _MPLL_STRUCT_TYPE                                       _MPLL_STRUCT_COMBO_M2PLL

//--------------------------------------------------
// M-Domain Data Bit Max
//--------------------------------------------------
#define _M_DOMAIN_DATA_BIT_MAX                                  (_COLOR_DEPTH_8_BITS * 3)

//-------------------------------------------------
// DPLL Structure
//-------------------------------------------------
#define _DPLL_STRUCT_TYPE                                       _DPLL_STRUCT_N_F_COMBO_LVDSPLL

//--------------------------------------------------
// DPLL vcorstb setting
//--------------------------------------------------
#define _DPLL_VCORSTB_NORMAL_VALUE                              0

//--------------------------------------------------
// Select Fifo Frequency Reference Clk
//--------------------------------------------------
#define _FIFO_FREQ_LINE_BUFFER_SEL                              _SCALER_FIFO_FREQ_M2PLL_DIV2
#define _FIFO_FREQ_FRAME_BUFFER_SEL                             _SCALER_FIFO_FREQ_M2PLL_DIV2

//--------------------------------------------------
// TMDS Input Clock Online Measure Divider
//--------------------------------------------------
#define _TMDS_MEASURE_CLOCK_DIVIDER                             2

//--------------------------------------------------
// TMDS Input Clock Online Measure Counter
//--------------------------------------------------
#define _TMDS_MEASURE_CLOCK_COUNTER                             2000

//--------------------------------------------------
// ADC Support --> VGA & ADC Bandgap
//--------------------------------------------------
#define _ADC_SUPPORT                                            _ON

//--------------------------------------------------
// VGA capture Support
//--------------------------------------------------
#define _VGA_CAPTURE_SUPPORT                                    _OFF

//--------------------------------------------------
// ADC Sampling Limitation
//--------------------------------------------------
#define _ADC_SAMPLE_CLOCK_LIMIT                                 2100000

//--------------------------------------------------
// ADC Limit Out Of Range
//--------------------------------------------------
#define _ADC_PIXEL_WIDTH_LIMIT                                  3200

//--------------------------------------------------
// Memory Type
//--------------------------------------------------
#define _MEMORY_TYPE                                            _EMBEDDED_MEMORY

//--------------------------------------------------
// FRC 3 Block Toggle Option
//--------------------------------------------------
#define _FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT                      _OFF

//--------------------------------------------------
// MN Frame Tracking Support
//--------------------------------------------------
#define _MN_FRAME_TRACKING_SUPPORT                              _OFF

//--------------------------------------------------
// FRC Memory 2 frame
//--------------------------------------------------
#define _FRC_MEMORY_2_FRAME_SUPPORT                             _OFF

//--------------------------------------------------
// FRC supports only for DOS-mode
//--------------------------------------------------
#define _HW_FRC_DOSMODE_ONLY_SUPPORT                            _ON

//-------------------------------------------------
// OD Gen
//-------------------------------------------------
#define _OD_TABLE_TYPE                                          _OD_GEN_1
#define _OD_LUT_MODE                                            _OD_8BIT_LUT

//-------------------------------------------------
// Global DB Gen
//------------------------------------------------
#define _HW_GLOBAL_DB_TYPE                                      _GEN_NONE

//-------------------------------------------------
// Display Rotation Gen
//-------------------------------------------------
#define _DISPLAY_ROTATION_TYPE                                  _GEN_NONE

//--------------------------------------------------
// I Domain Format Conversion
//--------------------------------------------------
#define _FORMAT_CONVERSION_SUPPORT                              _OFF

//--------------------------------------------------
// On-line measure
//--------------------------------------------------
#define _IDOMAIN_ONLINE_MEASURE_SUPPORT                         _OFF

//-------------------------------------------------
// IDither Gen
//-------------------------------------------------
#define _IDITHER_TYPE                                           _IDITHER_GEN_2_1_SEQ_NO_TEMPO_TRUNCATE_2_0_BIT

//-------------------------------------------------
// Scale Down Gen
//-------------------------------------------------
#define _SCALING_DOWN_TYPE                                      _SD_GEN_0 // H/V SD: no coef

//-------------------------------------------------
// Scale Up Gen
//-------------------------------------------------
#define _SCALING_UP_TYPE                                        _SU_GEN_0 // H_SU: 128 taps, V_SU: 128 taps
#define _HSU_128TAPS_SUPPORT                                    _ON
#define _HSU_96TAPS_SUPPORT                                     _OFF
#define _VSU_128TAPS_SUPPORT                                    _OFF

//-------------------------------------------------
// UltraVivid Gen
//-------------------------------------------------
#define _ULTRA_VIVID_TABLE_TYPE                                 _ULTRA_VIVID_GEN_5

//-------------------------------------------------
// Color Conversion
//-------------------------------------------------
#define _COLOR_CONVERSION_TYPE                                  _COLOR_CONVERSION_GEN_3

//-------------------------------------------------
// DCC Gen
//-------------------------------------------------
#define _DCC_TABLE_TYPE                                         _DCC_GEN_0

//-------------------------------------------------
// AUX TALK MODE LDO VOL Gen
//-------------------------------------------------
#define _AUX_TALK_MODE_LDO_VOL_TYPE                             _AUX_LDO_VOL_GEN_1

//-------------------------------------------------
// ICM Gen
//-------------------------------------------------
#define _ICM_TABLE_TYPE                                         _ICM_GEN_2

//-------------------------------------------------
// Contrast Gen
//-------------------------------------------------
#define _CTS_TYPE                                               _CTS_GEN_0_8BIT

//-------------------------------------------------
// Brightness Gen
//-------------------------------------------------
#define _BRI_TYPE                                               _BRI_GEN_0_8BIT

//-------------------------------------------------
// DCR Gen
//-------------------------------------------------
#define _DCR_BIT_MODE                                           _DCR_8BIT

//-------------------------------------------------
// IAPS Gain Gen
//-------------------------------------------------
#define _IAPS_GAIN_COMPENSATION_TYPE                            _IAPS_GAIN_COMPENSATION_GEN_0

//-------------------------------------------------
// RGB 3D Gamma Gen
//-------------------------------------------------
#define _3D_GAMMA_TABLE_TYPE                                    _GEN_NONE

//-------------------------------------------------
// PCM Gen
//-------------------------------------------------
#define _PCM_TABLE_TYPE                                         _GEN_NONE

//-------------------------------------------------
// Input Gamma Gen
//-------------------------------------------------
#define _INPUT_GAMMA_TABLE_TYPE                                 _INPUT_GAMMA_GEN_0

//-------------------------------------------------
// Output Gamma Gen
//-------------------------------------------------
#define _OUTPUT_GAMMA_TABLE_TYPE                                _OUTPUT_GAMMA_GEN_0

//-------------------------------------------------
// DDither Gen
//-------------------------------------------------
#define _DDITHER_TYPE                                           _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL

//-------------------------------------------------
// Multi Region Color Calibration Support
//-------------------------------------------------
#define _COLOR_CALIBRATION_SUPPORT_REGION_NUM                   _COLOR_1_REGION

//--------------------------------------------------
// HDCP2.2 Gen
//--------------------------------------------------
#define _HDCP_2_2_FUNCTION_GEN                                  _GEN_NONE

//--------------------------------------------------
// TMDS HDCP2.2 Online AES Page Assign
//--------------------------------------------------
#define _TMDS_HDCP_2_2_RX0_ONLINE_AES_PAGE                      _PAGE_NONE
#define _TMDS_HDCP_2_2_RX1_ONLINE_AES_PAGE                      _PAGE_NONE
#define _TMDS_HDCP_2_2_RX2_ONLINE_AES_PAGE                      _PAGE_NONE
#define _TMDS_HDCP_2_2_RX3_ONLINE_AES_PAGE                      _PAGE_NONE
#define _TMDS_HDCP_2_2_RX4_ONLINE_AES_PAGE                      _PAGE_NONE
#define _TMDS_HDCP_2_2_RX5_ONLINE_AES_PAGE                      _PAGE_NONE

//--------------------------------------------------
// TMDS HDCP2.2 Support
//--------------------------------------------------
#define _TMDS_HDCP_2_2_FUNCTION_SUPPORT                         _OFF

//--------------------------------------------------
// DP HDCP2.2 Support
//--------------------------------------------------
#define _DP_HDCP_2_2_FUNCTION_SUPPORT                           _OFF

//--------------------------------------------------
// HDCP1.4 Key eFuse
//--------------------------------------------------
#define _HDCP_1_4_KEY_EFUSE_SUPPORT                             _OFF

//--------------------------------------------------
// HW HDMI 2.0 Support
//--------------------------------------------------
#define _HW_HDMI_2_0_SUPPORT_PORT                               _HDMI_2_0_NONE

//--------------------------------------------------
// HW Dual Link DVI Support
//--------------------------------------------------
#define _HW_DUAL_LINK_DVI_SUPPORT_PORT                          _DUAL_LINK_DVI_NONE

//--------------------------------------------------
// HW DP VSC SDP Support
//--------------------------------------------------
#define _HW_DP_VSC_SDP_EXT_CAPABILITY_SUPPORT                   _OFF

//--------------------------------------------------
// HW DP VSC SDP Registers Support
//--------------------------------------------------
#define _HW_DP_VSC_SDP_REG_SUPPORT                              _OFF

//--------------------------------------------------
// HW DP Video Fifo Size
//--------------------------------------------------
#define _HW_DP_RX_VIDEO_FIFO_SIZE                               (128 * 96)

//--------------------------------------------------
// HW Audio Line In Swap
//--------------------------------------------------
#define _HW_AUDIO_LINE_IN_TO_DIGITAL_LR_SWAP                    _OFF

//--------------------------------------------------
// HW Digital Audio (I2S/SPDIF) Adjust Volume
//--------------------------------------------------
#define _HW_AUDIO_DIGITAL_OUTPUT_ADJUST_VOLUME                  _ON

//--------------------------------------------------
// DP InfoFrame Length
//--------------------------------------------------
#define _HW_DP_INFOFRAME_RSV0_LENGTH                            28
#define _HW_DP_INFOFRAME_RSV1_LENGTH                            0
#define _HW_DP_INFOFRAME_RSV2_LENGTH                            0

//--------------------------------------------------
// HW GDI DFE TYPE
//--------------------------------------------------
#define _HW_GDI_DFE_TYPE                                        _PASSIVE_DFE

//--------------------------------------------------
// HW FRC TYPE
//--------------------------------------------------
#define _HW_FRC_TYPE                                            _FRC_GEN_0

//--------------------------------------------------
// HW GDI DFE TYPE
//--------------------------------------------------
#define _HW_HS_TRACKING_GEN_TYPE                                _HS_TRACKING_GEN_2

//--------------------------------------------------
// _PWM_RST_BY_TCON SELECT
//--------------------------------------------------
#define _HW_PWM_RST_BY_TCON_SELECT                              _TCON7

//--------------------------------------------------
// USB3 Retimer Support
//--------------------------------------------------
#define _HW_USB3_RETIMER_SUPPORT                                _OFF

//--------------------------------------------------
// _TYPEC_SUPPORT_VERSION SELSCT
//--------------------------------------------------
#define _HW_TYPEC_SUPPORT_VERSION                               _TYPEC_VERSION_1_2

//--------------------------------------------------
// _PD_SUPPORT_VERSION SELSCT
//--------------------------------------------------
#define _HW_PD_SUPPORT_VERSION                                  _PD_VERSION_3_0

////////
// FW //
////////

//-------------------------------------------------
// FW Project Default Include
//-------------------------------------------------
#define _RLXXXX_PROJECT_DEFAULT                                 "RL6463_Project_Default.h"

//-------------------------------------------------
// FW Pcb Default Include
//-------------------------------------------------
#define _RLXXXX_PCB_DEFAULT                                     "RL6463_Pcb_Default.h"

//-------------------------------------------------
// FW M2PLL Freq
//-------------------------------------------------
#define _M2PLL_FREQ_SEL                                         _M2PLL_FREQ_372M

//-------------------------------------------------
// FW TMDS DDC Debounce Counter
//-------------------------------------------------
#define _TMDS_DDC_DEBOUNCE_NORMAL                               250
#define _TMDS_DDC_DEBOUNCE_PS                                   55

//--------------------------------------------------
// FW Underscan
//--------------------------------------------------
#define _UNDERSCAN_SUPPORT                                      _ON

//-------------------------------------------------
// FW Display Rotation
//-------------------------------------------------
#define _DISPLAY_ROTATION_90_SUPPORT                            _OFF
#define _DISPLAY_ROTATION_180_SUPPORT                           _OFF
#define _DISPLAY_ROTATION_270_SUPPORT                           _OFF

//--------------------------------------------------
// FW Pixel Shift Mode
//--------------------------------------------------
#define _PIXEL_SHIFT_MODE                                       _PIXEL_SHIFT_IN_IDOMAIN

//--------------------------------------------------
// Panel Uniformity SRAM MAX SIZE
//--------------------------------------------------
#define _PANEL_UNIFORMITY_MAX_GAIN_LUT_SIZE                     0

//--------------------------------------------------
// FW Local Dimming Support
//--------------------------------------------------
#define _FW_LOCAL_DIMMING_GEN_SEL                               _LOCAL_DIMMING_OFF

//--------------------------------------------------
// _TYPEC_ACC_SUPPORT_TYPE SELSCT
//--------------------------------------------------
#define _TYPEC_ACC_SUPPORT_TYPE                                 _TYPEC_ACC_NO_SUPPORT

////////
// IP //
////////

#include "RL6463_OSD_Gen_Option.h"

#endif // End of #ifndef __RL6463_GEN_OPTION__
#endif // End of #if(_SCALER_TYPE == _RL6463_SERIES)
