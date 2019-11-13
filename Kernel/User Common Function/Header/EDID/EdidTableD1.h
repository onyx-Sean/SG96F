//--------------------------------------------------
// EDID Type Selection
//--------------------------------------------------
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
#warning "Please Select D0 HDMI/MHL EDID Table!!!"
#elif((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
	#if 1//(_D1_HDMI_2_0_SUPPORT == _ON)
		#if(_HDMI_2_0_YCBCR420_SUPPORT == _ON)
            #if ((_PANEL_DH_WIDTH==1920)&&(_PANEL_DV_HEIGHT==1080)/*&& (_PANEL_PRESET_MODE_FRAME_RATE==1440)*/)
            	#define _EDID_D1_TYPE_SEL								_EDID_HDMI_1920_1080_144HZ
#elif((_PANEL_DH_WIDTH==2560)&&(_PANEL_DV_HEIGHT==1440)/*&& (_PANEL_PRESET_MODE_FRAME_RATE==1440)*/)
#define _EDID_D1_TYPE_SEL								_EDID_HDMI_2560_1440_144HZ
			#else
#define _EDID_D1_TYPE_SEL								_EDID_HDMI_1920_1080_144HZ
			#endif
		#else
        	#warning "Please Select EDID Table!!!"
		#endif
	#else
    	#warning "Please Select EDID Table!!!"
	#endif
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#warning "Please Select EDID Table!!!"
#endif


//--------------------------------------------------
// EDID Table
//--------------------------------------------------
#if((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON) || ((_D1_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D1_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)))

BYTE code tEDID_TABLE_D1[] =
{
#if(_EDID_D1_TYPE_SEL == _EDID_HDMI_1920_1080_144HZ)
#include "./EDID/EdidHdmi/EDID_HDMI_1920_1080_144HZ_INNO.h"
#elif(_EDID_D1_TYPE_SEL == _EDID_HDMI_2560_1440_144HZ)
#include "./EDID/EdidHdmi/EDID_HDMI_2560x1440@144.h"
#endif
};

#if(_FREESYNC_SUPPORT==_ON)
BYTE code tEDID_FREESYNC_TABLE_D1[] =
{
#if(_EDID_D1_TYPE_SEL == _EDID_HDMI_1920_1080_144HZ)
#include "./EDID/EdidHdmi/EDID_HDMI_1920_1080_144HZ_FREESYNC_INNO.h"
#elif(_EDID_D1_TYPE_SEL == _EDID_HDMI_2560_1440_144HZ)
#include "./EDID/EdidHdmi/EDID_HDMI_2560x1440@144_FREESYNC.h"
#endif
};
#endif


#endif
