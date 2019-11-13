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
// ID Code      : Pcb_Config_Check.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#ifndef __PCB_CONFIG_CHECK_H__
#define __PCB_CONFIG_CHECK_H__

/////////////////////
// PCB Power Macro //
/////////////////////

//-----------------------------------------------
// Macro of Embedded LDO Support
//-----------------------------------------------
#if(_SCALER_TYPE == _RL6369_SERIES)

#if(PCB_EMBEDDED_LDO_DETECT() == _EMBEDDED_LDO_ON)
#warning "PCB_EMBEDDED_LDO_DETECT() Should Be _EMBEDDED_LDO_OFF!!!"
#endif

#endif

///////////////////////
// Input Port Config //
///////////////////////

//--------------------------------------------------
// PCB DP Lane Swap Check
//--------------------------------------------------
#if(_HW_DP_LANE_SWAP_SUPPORT == _OFF)
#if((_D0_DP_PCB_LANE0_MAPPING != _DP_SCALER_LANE0) ||\
    (_D0_DP_PCB_LANE1_MAPPING != _DP_SCALER_LANE1) ||\
    (_D0_DP_PCB_LANE2_MAPPING != _DP_SCALER_LANE2) ||\
    (_D0_DP_PCB_LANE3_MAPPING != _DP_SCALER_LANE3) ||\
    (_D1_DP_PCB_LANE0_MAPPING != _DP_SCALER_LANE0) ||\
    (_D1_DP_PCB_LANE1_MAPPING != _DP_SCALER_LANE1) ||\
    (_D1_DP_PCB_LANE2_MAPPING != _DP_SCALER_LANE2) ||\
    (_D1_DP_PCB_LANE3_MAPPING != _DP_SCALER_LANE3))
#warning "DP Lane Swap Can Not Be Supported!!!"
#endif
#endif

//--------------------------------------------------
// PCB DP PN Swap Check
//--------------------------------------------------
#if(_HW_DP_PN_SWAP_SUPPORT == _OFF)
#if((_D0_DP_PCB_LANE0_PN_SWAP == _ON) || (_D0_DP_PCB_LANE1_PN_SWAP == _ON) ||\
    (_D0_DP_PCB_LANE2_PN_SWAP == _ON) || (_D0_DP_PCB_LANE3_PN_SWAP == _ON) ||\
    (_D1_DP_PCB_LANE0_PN_SWAP == _ON) || (_D1_DP_PCB_LANE1_PN_SWAP == _ON) ||\
    (_D1_DP_PCB_LANE2_PN_SWAP == _ON) || (_D1_DP_PCB_LANE3_PN_SWAP == _ON))
#warning "DP PN Swap Can Not Be Supported!!!"
#endif
#endif

//--------------------------------------------------
// DP HBR2 Margin Link Support Check
//--------------------------------------------------
#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
#if((_D0_DP_LINK_CLK_RATE != _DP_HIGH_SPEED2_540MHZ) &&\
    (_D1_DP_LINK_CLK_RATE != _DP_HIGH_SPEED2_540MHZ) &&\
    (_D6_DP_LINK_CLK_RATE != _DP_HIGH_SPEED2_540MHZ))
#warning "_DP_HBR2_MARGIN_LINK_SUPPORT Can Not Be Supported!!!"
#endif
#endif

//--------------------------------------------------
// DDC Mapping Check
//--------------------------------------------------
#if(((_D0_DDC_CHANNEL_SEL != _NO_DDC) && (_D0_DDC_CHANNEL_SEL != _DDC0)) ||\
    ((_D1_DDC_CHANNEL_SEL != _NO_DDC) && (_D1_DDC_CHANNEL_SEL != _DDC1)) ||\
    ((_D2_DDC_CHANNEL_SEL != _NO_DDC) && (_D2_DDC_CHANNEL_SEL != _DDC2)) ||\
    ((_D3_DDC_CHANNEL_SEL != _NO_DDC) && (_D3_DDC_CHANNEL_SEL != _DDC3)) ||\
    ((_D4_DDC_CHANNEL_SEL != _NO_DDC) && (_D4_DDC_CHANNEL_SEL != _DDC4)) ||\
    ((_D5_DDC_CHANNEL_SEL != _NO_DDC) && (_D5_DDC_CHANNEL_SEL != _DDC5)))

#if(_DDC_CHANNEL_SWITCH_SUPPORT == _OFF)
#warning "D0 or D1 or D2 or D3 or D4 or D5 Select Wrong DDC Channel!!!"
#else
#if(_DDCCI_AUTO_SWITCH_SUPPORT == _OFF)
#warning "_DDCCI_AUTO_SWITCH_SUPPORT should be _ON!!!"
#endif
#endif

#endif

//--------------------------------------------------
// PCB Debug DDC Check
//--------------------------------------------------
#if(_PCB_DEBUG_DDC == _VGA_DDC2)
#warning "_PCB_DEBUG_DDC Can't be be _VGA_DDC2!!!"
#endif

//--------------------------------------------------
// Input Port Type & DDC Channel Status Check
//--------------------------------------------------
#if(((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DDC_CHANNEL_SEL == _NO_DDC)) ||\
     ((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DDC_CHANNEL_SEL == _NO_DDC)) ||\
     ((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DDC_CHANNEL_SEL == _NO_DDC)) ||\
     ((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) && (_D3_DDC_CHANNEL_SEL == _NO_DDC)) ||\
     ((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) && (_D4_DDC_CHANNEL_SEL == _NO_DDC)) ||\
     ((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) && (_D5_DDC_CHANNEL_SEL == _NO_DDC)))
#warning "When D0 or D1 or D2 or D3 or D4 or D5 Input Port Type Select not _NO_PORT, DDC Channel Can't be _NO_DDC!!!"
#endif

//--------------------------------------------------
// Dual Link DVI Check
//--------------------------------------------------
#if(_HW_DUAL_LINK_DVI_SUPPORT_PORT == _DUAL_LINK_DVI_NONE)
#if(_DUAL_DVI_SUPPORT == _ON)
#warning "Dual Link DVI Port Can't Use in This Project!!!"
#endif
#elif(_HW_DUAL_LINK_DVI_SUPPORT_PORT == _DUAL_LINK_DVI_D2)
#if((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
#warning "D3 or D4 Input Port Can't be Dual DVI Port!!!"
#endif
#elif(_HW_DUAL_LINK_DVI_SUPPORT_PORT == _DUAL_LINK_DVI_D4)
#if((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
#warning "D2 or D3 Input Port Can't be Dual DVI Port!!!"
#endif
#elif(_HW_DUAL_LINK_DVI_SUPPORT_PORT == _DUAL_LINK_DVI_D2_D3_D4)
#if(((_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT) && (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)) ||\
     ((_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT) && (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)))
#warning "D2&D3 or D3&D4 Input Port Can't both be Dual DVI Port!!!"
#endif
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
#warning "_D3_INPUT_PORT_TYPE Should Be _D3_NO_PORT!!!"
#endif

#if(_D3_DDC_CHANNEL_SEL == _NO_DDC)
#warning "When D2 Input Port Type is Dual Link DVI Port, D3 DDC Channel Can't be _NO_DDC!!!"
#endif

#endif // End of #if(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)

#if(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
#warning "_D4_INPUT_PORT_TYPE Should Be _D4_NO_PORT!!!"
#endif

#if(_D4_DDC_CHANNEL_SEL == _NO_DDC)
#warning "When D3 Input Port Type is Dual Link DVI Port, D4 DDC Channel Can't be _NO_DDC!!!"
#endif

#endif // End of #if(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)

#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
#warning "_D5_INPUT_PORT_TYPE Should Be _D5_NO_PORT!!!"
#endif

#if(_D5_DDC_CHANNEL_SEL == _NO_DDC)
#warning "When D4 Input Port Type is Dual Link DVI Port, D5 DDC Channel Can't be _NO_DDC!!!"
#endif

#endif // End of #if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)

//--------------------------------------------------
// VGA Port Check
//--------------------------------------------------
#if((_SCALER_TYPE == _RL6369_SERIES) ||\
    (_SCALER_TYPE == _RL6410_SERIES) ||\
    (_SCALER_TYPE == _RL6432_SERIES) ||\
    (_SCALER_TYPE == _RL6449_SERIES) ||\
    (_SCALER_TYPE == _RL6463_SERIES) ||\
    (_SCALER_TYPE == _RL6492_SERIES))
#if((_A1_INPUT_PORT_TYPE != _A1_NO_PORT) || (_A2_INPUT_PORT_TYPE != _A2_NO_PORT))
#warning "_A1_VGA_PORT & _A2_VGA_PORT Can Not Be Supported!!!"
#endif
#endif

#if((_A1_INPUT_PORT_TYPE != _A1_NO_PORT) || (_A2_INPUT_PORT_TYPE != _A2_NO_PORT))
#if(_A0_INPUT_PORT_TYPE == _A0_NO_PORT)
#warning "_A0_INPUT_PORT_TYPE Should Be _A0_VGA_PORT!!!"
#endif
#endif

//--------------------------------------------------
// Type-C && Port Controller Setting Check
//--------------------------------------------------
#if((_D0_DP_TYPE_C_SUPPORT == _ON) && (_D0_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTOLLER_NONE))
#warning "'_D0_DP_TYPE_C_PORT_CTRL_TYPE' can't select '_PORT_CONTOLLER_NONE' if '_D0_DP_CONNECTOR_TYPE' selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D1_DP_TYPE_C_SUPPORT == _ON) && (_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTOLLER_NONE))
#warning "'_D1_DP_TYPE_C_PORT_CTRL_TYPE' can't select '_PORT_CONTOLLER_NONE' if '_D1_DP_CONNECTOR_TYPE' selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D2_DP_TYPE_C_SUPPORT == _ON) && (_D1_DP_TYPE_C_PORT_CTRL_TYPE == _PORT_CONTOLLER_NONE))
#warning "'_D1_DP_TYPE_C_PORT_CTRL_TYPE' can't select '_PORT_CONTOLLER_NONE' if '_D2DP_CONNECTOR_TYPE' selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D6_DP_TYPE_C_SUPPORT == _ON) && (_D6_DP_TYPE_C_PORT_CTRL_TYPE == _USB_HUB_USER))
#warning "'_D6_DP_TYPE_C_PORT_CTRL_TYPE' can't select '_PORT_CONTOLLER_NONE' if '_D6_DP_CONNECTOR_TYPE' selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D0_DP_TYPE_C_SUPPORT == _OFF) && (_D0_DP_TYPE_C_USB_HUB_TYPE != _USB_HUB_NONE))
#warning "'_D0_DP_TYPE_C_USB_HUB_TYPE' should be select '_USB_HUB_NONE' if '_D0_DP_CONNECTOR_TYPE' not selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D1_DP_TYPE_C_SUPPORT == _OFF) && (_D1_DP_TYPE_C_USB_HUB_TYPE != _USB_HUB_NONE))
#warning "'_D1_DP_TYPE_C_USB_HUB_TYPE' should be select '_USB_HUB_NONE' if '_D1_DP_CONNECTOR_TYPE' not selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D2_DP_TYPE_C_SUPPORT == _OFF) && (_D2_DP_TYPE_C_USB_HUB_TYPE != _USB_HUB_NONE))
#warning "'_D2_DP_TYPE_C_USB_HUB_TYPE' should be select '_USB_HUB_NONE' if '_D2_DP_CONNECTOR_TYPE' not selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

#if((_D6_DP_TYPE_C_SUPPORT == _OFF) && (_D6_DP_TYPE_C_USB_HUB_TYPE != _USB_HUB_NONE))
#warning "'_D6_DP_TYPE_C_USB_HUB_TYPE' should be select '_USB_HUB_NONE' if '_D6_DP_CONNECTOR_TYPE' not selected '_DP_CONNECTOR_TYPEC'!!!"
#endif

//-------------------------------------------------
// Type-C Auto Detect Pinassignment Type Mode Option Check
//-------------------------------------------------
#if((_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL < _RTS5400_SERIES_FW_SPEC_VERSION_V0D7) && (_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE))
#warning "_TYPE_C_PINCFG_AUTO_MODE Need Change to _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB~ !!"
#endif

#if((_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL < _RTS5400_SERIES_FW_SPEC_VERSION_V0D9) && (_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON))
#warning "_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT Need Change to _RTS5400_SERIES_FW_SPEC_VERSION_V0D9 or uper version~ !!"
#endif

#ifdef __USER_COMMON_INTERFACE__

//--------------------------------------------------
// A0 EDID Location Check
//--------------------------------------------------
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
#if((_A0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check A0 EDID table location!!!"
#endif
#if((_HW_PC99_SUPPORT != _ON) && (_A0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_PC99))
#warning "_A0_EMBEDDED_DDCRAM_LOCATION cannot be _EDID_TABLE_LOCATION_PC99"
#endif
#endif

//--------------------------------------------------
// D0 EDID Location Check
//--------------------------------------------------
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
#if((_D0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D0 EDID table location!!!"
#endif
#if((_D0_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D0_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D0 MHL EDID table location!!!"
#endif

#if((_HW_PC99_SUPPORT != _ON) && (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_PC99))
#warning "_D0_EMBEDDED_DDCRAM_LOCATION cannot be _EDID_TABLE_LOCATION_PC99"
#endif

// D0 Multi Edid Check
#if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 > _D0_EMBEDDED_DDCRAM_SIZE) && (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST)) ||\
    ((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 > _D0_EMBEDDED_DDCRAM_SIZE) && (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST)) ||\
    ((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 > _D0_EMBEDDED_DDCRAM_SIZE) && (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST)))
#warning "Please check _D0_EMBEDDED_DDCRAM_SIZE!!!"
#endif

#if(((_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 == _EDID_NOT_EXIST) + (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 == _EDID_NOT_EXIST) + (_D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 == _EDID_NOT_EXIST)) >= 2)
#warning "Please check _D0_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_x (at least 2 edid exist) !!!"
#endif

#endif // End of #if(_D0_HDMI_MULTI_EDID_SUPPORT == _ON)

#endif // End of #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
//--------------------------------------------------
// D1 EDID Location Check
//--------------------------------------------------
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
#if((_D1_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D1 EDID table location!!!"
#endif
#if((_D1_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D1_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D1 MHL EDID table location!!!"
#endif

#if((_HW_PC99_SUPPORT != _ON) && (_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_PC99))
#warning "_D1_EMBEDDED_DDCRAM_LOCATION cannot be _EDID_TABLE_LOCATION_PC99"
#endif

// D1 Multi Edid Check
#if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 > _D1_EMBEDDED_DDCRAM_SIZE) && (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST)) ||\
    ((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 > _D1_EMBEDDED_DDCRAM_SIZE) && (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST)) ||\
    ((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 > _D1_EMBEDDED_DDCRAM_SIZE) && (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST)))
#warning "Please check _D1_EMBEDDED_DDCRAM_SIZE!!!"
#endif

#if(((_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 == _EDID_NOT_EXIST) + (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 == _EDID_NOT_EXIST) + (_D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 == _EDID_NOT_EXIST)) >= 2)
#warning "Please check _D1_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_x (at least 2 edid exist) !!!"
#endif

#endif // End of #if(_D1_HDMI_MULTI_EDID_SUPPORT == _ON)

#endif // End of #if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
//--------------------------------------------------
// D2 EDID Location Check
//--------------------------------------------------
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
#if((_D2_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D2_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D2 EDID table location!!!"
#endif
#if((_D2_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D2_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D2 MHL EDID table location!!!"
#endif

// D2 Multi Edid Check
#if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 > _D2_EMBEDDED_DDCRAM_SIZE) && (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST)) ||\
    ((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 > _D2_EMBEDDED_DDCRAM_SIZE) && (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST)) ||\
    ((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 > _D2_EMBEDDED_DDCRAM_SIZE) && (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST)))
#warning "Please check _D2_EMBEDDED_DDCRAM_SIZE!!!"
#endif

#if(((_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 == _EDID_NOT_EXIST) + (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 == _EDID_NOT_EXIST) + (_D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 == _EDID_NOT_EXIST)) >= 2)
#warning "Please check _D2_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_x (at least 2 edid exist) !!!"
#endif

#endif // End of #if(_D2_HDMI_MULTI_EDID_SUPPORT == _ON)

#endif // End of #if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)

//--------------------------------------------------
// D3 EDID Location Check
//--------------------------------------------------
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
#if((_D3_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D3 EDID table location!!!"
#endif
#if((_D3_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D3_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D3 MHL EDID table location!!!"
#endif

// D3 Multi Edid Check
#if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 > _D3_EMBEDDED_DDCRAM_SIZE) && (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST)) ||\
    ((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 > _D3_EMBEDDED_DDCRAM_SIZE) && (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST)) ||\
    ((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 > _D3_EMBEDDED_DDCRAM_SIZE) && (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST)))
#warning "Please check _D3_EMBEDDED_DDCRAM_SIZE!!!"
#endif

#if(((_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 == _EDID_NOT_EXIST) + (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 == _EDID_NOT_EXIST) + (_D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 == _EDID_NOT_EXIST)) >= 2)
#warning "Please check _D3_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_x (at least 2 edid exist) !!!"
#endif

#endif // End of #if(_D3_HDMI_MULTI_EDID_SUPPORT == _ON)

#endif // End of #if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)

//--------------------------------------------------
// D4 EDID Location Check
//--------------------------------------------------
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
#if((_D4_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D4_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D4 EDID table location!!!"
#endif
#if((_D4_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D4_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D4 MHL EDID table location!!!"
#endif

// D4 Multi Edid Check
#if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 > _D4_EMBEDDED_DDCRAM_SIZE) && (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST)) ||\
    ((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 > _D4_EMBEDDED_DDCRAM_SIZE) && (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST)) ||\
    ((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 > _D4_EMBEDDED_DDCRAM_SIZE) && (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST)))
#warning "Please check _D4_EMBEDDED_DDCRAM_SIZE!!!"
#endif

#if(((_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 == _EDID_NOT_EXIST) + (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 == _EDID_NOT_EXIST) + (_D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 == _EDID_NOT_EXIST)) >= 2)
#warning "Please check _D4_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_x (at least 2 edid exist) !!!"
#endif

#endif // End of #if(_D4_HDMI_MULTI_EDID_SUPPORT == _ON)

#endif // End of #if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)

//--------------------------------------------------
// D5 EDID Location Check
//--------------------------------------------------
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
#if((_D5_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D5_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D5 EDID table location!!!"
#endif
#if((_D5_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D5_MHL_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D5 MHL EDID table location!!!"
#endif

// D5 Multi Edid Check
#if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)

#if(((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 > _D5_EMBEDDED_DDCRAM_SIZE) && (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 != _EDID_NOT_EXIST)) ||\
    ((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 > _D5_EMBEDDED_DDCRAM_SIZE) && (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 != _EDID_NOT_EXIST)) ||\
    ((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 > _D5_EMBEDDED_DDCRAM_SIZE) && (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 != _EDID_NOT_EXIST)))
#warning "Please check _D5_EMBEDDED_DDCRAM_SIZE!!!"
#endif

#if(((_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_0 == _EDID_NOT_EXIST) + (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_1 == _EDID_NOT_EXIST) + (_D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_2 == _EDID_NOT_EXIST)) >= 2)
#warning "Please check _D5_EMBEDDED_DDCRAM_SIZE_MULTI_EDID_x (at least 2 edid exist) !!!"
#endif

#endif // End of #if(_D5_HDMI_MULTI_EDID_SUPPORT == _ON)

#endif // End of #if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)

//--------------------------------------------------
// D6 EDID Location Check
//--------------------------------------------------
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
#if((_D6_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D6_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE))
#warning "Please check D6 EDID table location!!!"
#endif
#endif

#endif // End of #ifdef __USER_COMMON_INTERFACE__


////////////////////
// For LVDS Panel //
////////////////////

//--------------------------------------------------
// LVDS Panel
//--------------------------------------------------
#if(_LVDS_VCM_USER_LEVEL > 0x1F)
#warning "LVDS VCM Selection Exceed The Maximum Value"
#endif


/////////////////////////
// eDPTx 1.1 HBR Panel //
/////////////////////////

//--------------------------------------------------
// eDPTx 1.1 HBR Panel Config Check
//--------------------------------------------------
#if(_PANEL_STYLE == _PANEL_DPTX)

#if((_PANEL_DPTX_1_1_SWING_LEVEL + _PANEL_DPTX_1_1_PREEMPHASIS_LEVEL) > 2)
#warning "Panel DPTX 1.1 Swing and Pre-emphasis over Spec!!!"
#endif

#if(_PANEL_DPTX_1_1_SPREAD_SPEED == _SPEED_66K)
#warning "Panel DPTx Spread Spectrum Speed Should Be 30kHz~33kHz"
#endif


//////////////////////////
// eDPTx 1.2 HBR2 Panel //
//////////////////////////

//--------------------------------------------------
// eDPTx 1.2 HBR2 Panel Config Check
//--------------------------------------------------
#if((_PANEL_DPTX_1_2_SWING_LEVEL + _PANEL_DPTX_1_2_PREEMPHASIS_LEVEL) > 3)
#warning "Panel DPTX 1.2 Swing and Pre-emphasis over Spec!!!"
#endif

#if(_PANEL_DPTX_1_2_SPREAD_SPEED == _SPEED_66K)
#warning "Panel DPTx Spread Spectrum Speed Should Be 30kHz~33kHz"
#endif

#endif


////////////////////
// V by One Panel //
////////////////////

//--------------------------------------------------
// V by One Panel Config Check
//--------------------------------------------------
#if(_PANEL_STYLE == _PANEL_VBO)
#if(_VBO_SPREAD_SPEED != _SPEED_30K)
#warning "Vbyone Spread Spectrum Speed Should Be 30kHz"
#endif
#endif


/////////////////
// Memory DDR3 //
/////////////////

//--------------------------------------------------
// DDR3 of Multi Phase For Different Vendor
//--------------------------------------------------
#if(_MEMORY_TYPE_CONFIG != _MEMORY_DDR3)
#if(_DDR3_MULTIPHASE_EXIST == _ON)
#warning "This Function Can Not Be _ON without DDR3"
#endif
#endif

//-----------------------------------------------
// Macro of DDR Poewr Release Time Control
//-----------------------------------------------
#if((_MEMORY_TYPE_CONFIG == _MEMORY_DDR2) || (_MEMORY_TYPE_CONFIG == _MEMORY_DDR3))
#if(_DDR_POWER_OFF_TIME > 1000)
#warning "DDR Power Off Time Delay Should Be Less 1S"
#endif
#endif

/////////////////
// SW & HW IIC //
/////////////////

//--------------------------------------------------
// SW & HW IIC
//--------------------------------------------------
#if (_PCB_SYS_EEPROM_IIC == _SW_IIC_PIN_GPIO)
#if(_SW_IIC_SUPPORT == _OFF)
#warning "If using SW IIC _SW_IIC_SUPPORT Should Be ON"
#endif
#endif


//////////
// Misc //
//////////

//--------------------------------------------------
// Flash Latch Edge Option
//--------------------------------------------------
#if((_SCALER_TYPE == _RL6193_SERIES) ||\
    (_SCALER_TYPE == _RL6410_SERIES) ||\
    (_SCALER_TYPE == _RL6432_SERIES) ||\
    (_SCALER_TYPE == _RL6449_SERIES) ||\
    (_SCALER_TYPE == _RLE0779_SERIES) ||\
    (_SCALER_TYPE == _RL6463_SERIES) ||\
    (_SCALER_TYPE == _RL6492_SERIES) ||\
    (_SCALER_TYPE == _RL6478_SERIES))
#if(_PCB_FLASH_LATCH_SO_DATA_IN_RISING_EDGE == _ON)
#warning "Flash Latch Edge Can Not Be Change In this IC"
#endif
#endif

#endif // End of #ifndef __PCB_CONFIG_CHECK_H__
