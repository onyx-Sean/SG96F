
//--------------------------------------------------
// EDID Type Selection
//--------------------------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
#warning "Please Select D0 DVI EDID Table!!!"
#elif((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
#warning "Please Select D0 HDMI/MHL EDID Table!!!"
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        #if ((_PANEL_DH_WIDTH==1920)&&(_PANEL_DV_HEIGHT==1080)/*&& (_PANEL_PRESET_MODE_FRAME_RATE==1440)*/)
        #define _EDID_D0_TYPE_SEL								_EDID_DP_1920_1080_144HZ
     #elif((_PANEL_DH_WIDTH==2560)&&(_PANEL_DV_HEIGHT==1440)/*&& (_PANEL_PRESET_MODE_FRAME_RATE==1440)*/)
#define _EDID_D0_TYPE_SEL								_EDID_DP_2560_1440_144HZ
	#else
#define _EDID_D0_TYPE_SEL								_EDID_DP_1920_1080_144HZ
	#endif
#endif


//--------------------------------------------------
// EDID Table
//--------------------------------------------------
#if((_WRITE_EDID_TO_SYSTEM_EEPROM == _ON) || ((_D0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE) && (_D0_EMBEDDED_DDCRAM_LOCATION == _EDID_TABLE_LOCATION_CODE)))

BYTE code tEDID_TABLE_D0[] =
{
#if(_EDID_D0_TYPE_SEL == _EDID_DP_1920_1080_144HZ)
#include "./EDID/EdidDp/EDID_DP_1920_1080_144HZ_INNO.h"
#elif(_EDID_D0_TYPE_SEL == _EDID_DP_2560_1440_144HZ)
#include "./EDID/EdidDp/EDID_DP_2560_1440_144HZ.h"
#endif
};

#if(_FREESYNC_SUPPORT==_ON)
BYTE code tEDID_FREESYNC_TABLE_D0[] =
{
#if(_EDID_D0_TYPE_SEL == _EDID_DP_1920_1080_144HZ)
#include "./EDID/EdidDp/EDID_DP_1920_1080_144HZ_FREESYNC_INNO.h"
#elif(_EDID_D0_TYPE_SEL == _EDID_DP_2560_1440_144HZ)
#include "./EDID/EdidDp/EDID_DP_2560_1440_144HZ_FREESYNC.h"
#endif
};
#endif

#endif
