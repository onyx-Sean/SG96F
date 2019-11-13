//--------------------------------------------------
// EDID Type Selection
//--------------------------------------------------
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
	#if ((_PANEL_DH_WIDTH==1920)&&(_PANEL_DV_HEIGHT==1080)&& (_PANEL_PRESET_MODE_FRAME_RATE==1440))
                   #define _EDID_D3_TYPE_SEL							  _EDID_DVI_1920_1080_144HZ
#elif((_PANEL_DH_WIDTH==2560)&&(_PANEL_DV_HEIGHT==1440)/*&& (_PANEL_PRESET_MODE_FRAME_RATE==1440)*/)
#define _EDID_D3_TYPE_SEL							   _EDID_DVI_2560_1440_60HZ
	#else
		#define _EDID_D3_TYPE_SEL                             _EDID_DVI_1920_1080_144HZ
	#endif
//#warning "Please Select D0 HDMI/MHL EDID Table!!!"
#elif((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
	#if (_D3_HDMI_2_0_SUPPORT == _ON)
        #warning "Please Select EDID Table!!!"
	#else
			#define _EDID_D3_TYPE_SEL								_EDID_HDMI_1920_1080_144HZ//HDMI1.4
        #endif
#endif


//--------------------------------------------------
// EDID Table
//--------------------------------------------------
#if((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON) || ((_D3_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D3_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)))

BYTE code tEDID_TABLE_D3[] =
{
#if(_EDID_D3_TYPE_SEL == _EDID_DVI_1920_1080_144HZ)
#include "./EDID/EdidDvi/EDID_DVI_1920_1080_144Hz.h"
#elif(_EDID_D3_TYPE_SEL == _EDID_DVI_2560_1440_60HZ)
#include "./EDID/EdidDvi/EDID_DVI_2560_1440_60Hz.h"
#endif
};

#endif
