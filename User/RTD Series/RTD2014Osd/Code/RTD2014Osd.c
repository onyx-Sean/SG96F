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
// ID Code      : RTD2014Osd.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSD__

#include "UserCommonInclude.h"
BYTE ucTemppp = 0;

#if(_OSD_TYPE == _REALTEK_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructOsdInfo g_stOsdInfo;

WORD g_usAdjustValue;
WORD g_usBackupValue;
BYTE g_ucLogoTimerCounter;
BYTE g_usItemNum = 0;


bit g_usTime_OSD_OnOff1 = _OFF;
BYTE g_MiaoZhun = 0;
bit g_MiaoZhun_OnOff = _ON;
BYTE g_MiaoZhun1 = 0;
bit g_MiaoZhun_OnOff1 = _OFF;

BYTE g_usTimeTabe = 0;
bit g_usTime_OSD_OnOff = _ON;
WORD g_usTimeUse = 0;

BYTE Time_Flag = 0;
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void RTDOsdSystemFlowProc(void);
void RTDOsdEventMsgProc(void);
void OsdDispLeftTimerMenuAdjust(void);
void OsdDispLeftAimMenuAdjust(void);
void OsdDispLeftTimerMenu(void);
 void MenuHotInput(void);

//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : OSD Handler, executed in the main loop
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserOsdHandler(void)
{
    RTDOsdSystemFlowProc();
    RTDOsdEventMsgProc();
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdSystemFlowProc(void)
{
    switch(SysModeGetModeState())
    {
        case _MODE_STATUS_POWER_OFF:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }

            break;

        case _MODE_STATUS_INITIAL:

            if(SysModeGetModeStateChange() == _TRUE)
            {
#if(_FREESYNC_OD_MEASURE == _ON)
                UserAdjustFREESYNCODMeasure();
#endif
        #if(_OSD_LOGO_TYPE !=  _NONE_LOGO)

                OsdDispShowLogo();
                UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);

               ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
               #endif
            }

            break;

        case _MODE_STATUS_SEARCH:
    if(GET_OSD_FREE_SYNC_HOT_PLUG())
    {
							SET_OSD_FREE_SYNC_HOT_PLUG(_OFF);
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                        ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                        PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);

    }



            if(SysModeGetModeStateChange() == _TRUE)
            {
#if(_FREEZE_SUPPORT == _ON)
                if(GET_OSD_FREEZE_STATUS() == _ON)
                {
                    SET_OSD_FREEZE_STATUS(_OFF);
                }
#endif
                if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
                {
                    UserInterfaceKeyPadLedControl(_LED_POWER_SEARCH);
                }
            }

            break;

        case _MODE_STATUS_DISPLAY_SETTING:

            break;

        case _MODE_STATUS_ACTIVE:

            if(SysModeGetModeStateChange() == _TRUE)
            {
               //     ScalerTimerActiveTimerEvent(SEC(5), _USER_TIMER_EVENT_OSD_TIMER);// 

                if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
                {
                    UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
                }


        	switch(GET_OSD_LED())
	{
	   case 0:
				OSD_LED_CONTRL(_OSD_LED_OFF);
			ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED);
		break;

		
		case 1: 		 
				OSD_LED_CONTRL(_OSD_LED_ON);
			 ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED);
		 break;

	   case 2:		
				OSD_LED_CONTRL(_OSD_LED_OFF);
			
			ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_LED);
		break;

	   }


				
            }

#if(_DCR_SUPPORT == _ON)
            if(GET_OSD_DCR_STATUS() == _ON)
            {
                UserCommonAdjustDCR();
            }
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
            UserCommonAdjustHDR(_HDR_FLOW_MODE_STATUS_ACTIVE);

#if(_LOCAL_DIMMING_SUPPORT == _ON)
            if((UserCommonAdjustHDREnableStatus(UserInterfaceGetHDRModeStatus()) == _ON))
            {
                if((GET_OSD_LOCAL_DIMMING()==_ON) && (ScalerOsdGetOsdEnable()==_OFF))
                {
                    UserCommonLocalDimmingAdjust();
                }
            }
#endif
#endif

            break;

        case _MODE_STATUS_NOSUPPORT:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
                {
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
                    UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);
                }
            }

            break;

        case _MODE_STATUS_NOSIGNAL:
        
if(GET_OSD_BURN_STATUS()==_ON)
{
			ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_SHOW_BURNIN);
}
else
{

            if(SysModeGetModeStateChange() == _TRUE)
            {
                if(SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)) == _TRUE)
                {
                    ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
                }
                else
                {
                    ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
                }
            }
}

            break;

        case _MODE_STATUS_POWER_SAVING:

            if(SysSourceGetCableDetect(SysSourceGetInputPort()) == _FALSE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }

            if(SysPowerGetPowerStatus() == _POWER_STATUS_NORMAL)
            {
                if(GET_OSD_POWER_SAVING_SHOW_SOURCE() == _TRUE)
                {
                    SET_OSD_POWER_SAVING_SHOW_SOURCE(_FALSE);

                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG);
                }
                else if(GET_OSD_WAKE_UP_SWITCH_DDCCI_PORT() == _TRUE)
                {
                    SET_OSD_WAKE_UP_SWITCH_DDCCI_PORT(_FALSE);

                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG);
                }
#if(_DP_SUPPORT == _ON)
                else if(GET_OSD_POWER_SAVING_SHOW_DP_OPTION() == _TRUE)
                {
                    SET_OSD_POWER_SAVING_SHOW_DP_OPTION(_FALSE);
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_DP_VERSIOM_MSG);
                }
#endif
#if(_DP_DEBUG_MSG == _ON)
                else if(GET_OSD_POWER_SAVING_SHOW_DP_INFO() == _TRUE)
                {
                    SET_OSD_POWER_SAVING_SHOW_DP_INFO(_FALSE);

                    OsdDispOsdMessage(_OSD_DISP_INPUT_SIGNAL_MSG);
                    UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
                }
#endif
            }
            break;

        case _MODE_STATUS_FACTORY:

            break;

        default:

            break;
    }

#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
    // Check embedded DP switch status
    UserCommonAdjustEmbeddedDpSwitch();
#endif

    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
    {
        // hot key
        if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) ||
           (SysModeGetModeState() == _MODE_STATUS_POWER_SAVING))
        {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
            if((GET_OSD_STATE() != _MENU_NONE) &&
               ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)) &&
               (GET_OSD_STATE() != _MENU_HOTKEY_SOURCE))
#else
            if((GET_OSD_STATE() != _MENU_NONE) && ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)))
#endif
            {
                SET_KEYREPEATENABLE();
            }
        }

        if(GET_OSD_IN_FACTORY_MENU_STATUS() == _TRUE)
        {
            RTDFactoryMenuOperation();
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
        }
        else
        {
#if(_FREEZE_SUPPORT == _ON)
#if(_URGENT_EVENT_CHECK_MODE == _ON)
            if(ScalerTimerSearchActiveTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG) == _TRUE)
            {
                return;
            }
#else
            if(GET_FREEZE_DISABLE_MSG_STATE() == _ON)
            {
                return;
            }
#endif
#endif
            // back up previous OSD State
            SET_OSD_STATE_PREVIOUS(GET_OSD_STATE());

#if(_FREEZE_SUPPORT == _ON)
            if(GET_OSD_FREEZE_STATUS() == _ON) // Confirm whether disable the freeze status
            {
                if(OsdFuncCheckFreezeDisable() == _TRUE)
                {
                    return;
                }
            }
#endif

            if((GET_OSD_STATE() >= _MENU_PICTURE) && (GET_OSD_STATE() <= _MENU_END))
            {
             //   OsdDispMainMenuKeyInfo(GET_KEYMESSAGE(), _OSD_HIGHLIGHT);
            }

            (*OperationTable[GET_OSD_STATE()])();

            if(GET_OSD_IN_FACTORY_MENU_STATUS() == _FALSE)
            {
                if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                {
                   if(GET_OSD_TIME_OUT() <= 4)
                  {
                      ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                 }
                else
                    {
			if(GET_OSD_STATE() == _MENU_NONE) 
				ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                          else
	                         ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
                    }
                }
            }


/*
            if((GET_OSD_STATE() >= _MENU_NONE) &&
                (GET_OSD_STATE() < _MENU_END) &&
                ((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING) || (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL)))
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            }
            else//(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
            }

            if(GET_OSD_IN_FACTORY_MENU_STATUS())
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
            }
*/
        }
    }
}

//--------------------------------------------------
// Description  : OSD event message processing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdEventMsgProc(void)
{
    switch(GET_OSD_EVENT_MESSAGE())
    {
        case _OSDEVENT_SHOW_NOSIGNAL_MSG:
            OsdDispOsdMessage(_OSD_DISP_NOSIGNAL_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            break;

        case _OSDEVENT_SHOW_NOCABLE_MSG:
            OsdDispOsdMessage(_OSD_DISP_NOCABLE_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            break;

        case _OSDEVENT_SHOW_NOSUPPORT_MSG:

            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);

            OsdDispOsdMessage(_OSD_DISP_NOSUPPORT_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            break;

        case _OSDEVENT_SHOW_FAIL_SAFE_MODE_MSG:
            OsdDispOsdMessage(_OSD_DISP_FAIL_SAFE_MODE_MSG);
            break;

        case _OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG:
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
                  CLR_KEYREPEATENABLE();                
                  SET_OSD_STATE(_MENU_HOT_INPUT_ADJUST);
                   MenuHotInput();
            ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            break;

        case _OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG:

            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_GO_TO_POWER_SAVING);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_CABLE);
            ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_SHOW_NO_SIGNAL);
            SET_OSD_STATE(_MENU_HOTKEY_DDCCI);
            OsdDispHotKeyOptionMenu(_HOTKEY_DDCCI);
            ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);

            break;

        case _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG:
            OsdDispDisableOsd();
            OsdDispOsdMessage(_OSD_DISP_POWER_SAVING_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);

			OSD_LED_CONTRL(_OSD_LED_OFF);
			ScalerTimerCancelTimerEvent( _USER_TIMER_EVENT_LED);
            break;

        case _OSDEVENT_GO_TO_POWER_SAVING_EVENT_MSG:

            OsdDispDisableOsd();
            if((SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_NOSUPPORT_SAVING);
            }
            else
            {
                SysPowerSetTargetPowerStatus(_POWER_STATUS_SAVING);
            }
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_DO_AUTO_CONFIG_MSG:
#if(_FREEZE_SUPPORT == _ON)
            ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG);
#endif
            OsdDispAutoConfigProc();
            break;
#endif

        case _OSDEVENT_ACTIVE_DO_ONE_TIME_MSG:

#if(_FREEZE_SUPPORT == _ON)
            ScalerTimerWaitForActiveTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG);
#endif

#if(_VGA_SUPPORT == _ON)
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                if(UserInterfaceGetFirstAutoConfigStatus() == _TRUE)
                {
                    OsdDispAutoConfigProc();
                }
            }
#endif

            if(GET_OSD_STATE() == _MENU_NONE)
            {
            ucTemppp = 1;
              OsdDispOsdMessage(_OSD_DISP_INPUT_SIGNAL_MSG);
             ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE1);

            }
            break;

        case _OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG:
            UserCommonNVRamSaveSystemData();
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_MODEUSERDATA_MSG:
            UserCommonNVRamSaveModeUserData();
            break;
#endif
        case _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG:
            RTDNVRamSaveOSDData();

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
            UserCommonDataExchangeSetSentDataEvent(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
#endif
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG:
            if(ScalerColorGetColorSpaceRGB(ScalerColorGetColorSpace()) == _TRUE)
            {
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            }
            else
            {
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);
            }
            break;
#endif

        case _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG:
            RTDNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
            UserCommonDataExchangeSetSentDataEvent(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
#endif
            break;

        case _OSDEVENT_SAVE_NVRAM_BRICON_MSG:
            RTDNVRamSaveBriCon(SysSourceGetSourceType());

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
            UserCommonDataExchangeSetSentDataEvent(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
#endif
            break;

        case _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG:
            RTDNVRamSaveSixColorData();
            break;

#if(_DP_SUPPORT == _ON)
        case _OSDEVENT_DP_VERSIOM_MSG:
            SET_OSD_STATE(_MENU_HOTKEY_DP_OPTION);

            if(SysSourceGetSourceType() == _SOURCE_DP)
            {
                if(SysSourceGetInputPort() == _D0_INPUT_PORT)
                {
                    OsdDispHotKeyOptionMenu(_HOTKEY_DP_D0_OPTION);
                }
                else if(SysSourceGetInputPort() == _D1_INPUT_PORT)
                {
                    OsdDispHotKeyOptionMenu(_HOTKEY_DP_D1_OPTION);
                }
                else if(SysSourceGetInputPort() == _D2_INPUT_PORT)
                {
                    OsdDispHotKeyOptionMenu(_HOTKEY_DP_D2_OPTION);
                }
                else if(SysSourceGetInputPort() == _D6_INPUT_PORT)
                {
                    OsdDispHotKeyOptionMenu(_HOTKEY_DP_D6_OPTION);
                }
            }
            else
            {
#if (_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
                OsdDispHotKeyOptionMenu(_HOTKEY_DP_D0_OPTION);
#elif (_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                OsdDispHotKeyOptionMenu(_HOTKEY_DP_D1_OPTION);
#elif (_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
                OsdDispHotKeyOptionMenu(_HOTKEY_DP_D2_OPTION);
#elif (_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
                OsdDispHotKeyOptionMenu(_HOTKEY_DP_D6_OPTION);
#else
                SET_OSD_STATE(_MENU_NONE);
#endif
            }

            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            break;
#endif
        case _OSDEVENT_BUININ_MSG:
            SGFactoryShowBurninPicture();

            break;

        default:
            break;
    }

    SET_OSD_EVENT_MESSAGE(_OSDEVENT_NONE_MSG);
}

  void MenuLeftKeyGame(void)
 {
	  CLR_KEYREPEATENABLE();
	 switch(GET_KEYMESSAGE())
	 {
	 case _MENU_KEY_MESSAGE:
		 SET_OSD_STATE(_Menu_LEFTKEY_GAME_ADJUST);
		 //ScalerOsdWindowDisable(_OSD_WINDOW_1);
		 OsdFontPut1FuncTableForm(0, 0, _EDGE_LINE,g_ucOsdWidth-2,g_ucOsdHeight-2,_CP_BG,_CP_BG,3);
		 OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
		 OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_0, _STRING_GAME_CURSOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		 COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_AIM);
	 	{
		switch(GET_OSD_AIM())
		{
			case _AIM_1:

				OsdFontPut1FuncAimTableForm(8, 12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_GRAY);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_2:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_GRAY);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_3:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
				
				//OsdFontPut1FuncTableForm(8, 38, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_GRAY); 

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_4:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	
				
				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_GRAY);
				break;
				
			 default:
				 break;
		}
	 	
		 }
		 
	 
 
	 break;
	 case _LEFT_KEY_MESSAGE:
	 case _RIGHT_KEY_MESSAGE:
		 SET_OSD_STATE(_Menu_LEFTKEY_TIMER);	 
		 SET_OSD_Left_Menu_Choose(OsdDisplayDetOverRange(GET_OSD_Left_Menu_Choose() , _LEFT_MENU_END, _LEFT_AIM, _ON));
		 OsdFontPut1FuncAimTableForm(7,13, _EDGE_LINE,22,10,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		 OsdFontPut1FuncAimTableForm(7,40, _EDGE_LINE,22,10,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		 OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START ,_CP_WHITE , _CP_BG);	  
		 OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START ,_CP_ORANGE_H , _CP_GRAY);
		 
	 break;
		

	//(BYTE)OsdDisplayDetOverRange(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF);	
	 case _EXIT_KEY_MESSAGE:
		 g_usTime_OSD_OnOff1=_OFF;
		 g_MiaoZhun_OnOff1=_OFF;
		 OsdDispDisableOsd();
	 break;
		 
		 default:
			 break; 				  
	 }
 }


   void MenuLeftKeyTimer(void)
  {
	CLR_KEYREPEATENABLE();
	  switch(GET_KEYMESSAGE())
	  {
	  case _MENU_KEY_MESSAGE:
		  SET_OSD_STATE(_Menu_LEFTKEY_TIMER_ADJUST);
		  g_usTimeUse = 0;
		  OsdFontPut1FuncTableForm(0, 0, _EDGE_LINE,g_ucOsdWidth-2,g_ucOsdHeight-2,_CP_BG,_CP_BG,3);
		  OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
		  OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_1, _STRING_GAME_TIME, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		  COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_TIMER);
		  //ScalerOsdWindowDisable(_OSD_WINDOW_1);
		 // OsdFontPut1FuncTableForm(0, 0, _EDGE_LINE,g_ucOsdWidth-2,g_ucOsdHeight-2,_CP_BG,_CP_BG,3);
		 // OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
		  {

		  
			  if(GET_OSD_Timer()==_TIMER_10)
			  	{
				  OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,1);	  
				  OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);   
				  OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_20)
			  	{
				  OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,2);	  
				  OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	  
				  OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_30)
			  	{
				  OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,3);	  
				  OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	  
				  OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_40)
			  	{
				  OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,4);	  
				  OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	  
				  OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_50)
			  	{
				  OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,5);   
				  OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);  
				  OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_60)
			  	{
				  OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,6);	  
				  OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);   
				  OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_90)
			  	{
				  OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,9);	  
				  OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);   
				  OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  else
			  	{
				  SET_OSD_Timer(_TIMER_10);
				  OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,1);	  
				  OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
				  OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
				  OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);   
				  OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  	}
			  
				  
		  }
		  
	  
  
	  break;
		  
	  case _RIGHT_KEY_MESSAGE: 
	  case _LEFT_KEY_MESSAGE:
	  SET_OSD_STATE(_Menu_LEFTKEY_GAME);
	  SET_OSD_Left_Menu_Choose(OsdDisplayDetOverRange(GET_OSD_Left_Menu_Choose() , _LEFT_MENU_END, _LEFT_AIM, _ON));
		  OsdFontPut1FuncAimTableForm(7,13, _EDGE_LINE,22,10,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		  OsdFontPut1FuncAimTableForm(7,40, _EDGE_LINE,22,10,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		  OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_ORANGE_H, _CP_GRAY);	   
		  OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_WHITE, _CP_BG);
		  
  	  break;
	 //(BYTE)OsdDisplayDetOverRange(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF);	 
	  
	  case _EXIT_KEY_MESSAGE:
		  g_usTime_OSD_OnOff1=_OFF;
		  g_MiaoZhun_OnOff1=_OFF;
		  OsdDispDisableOsd();
	  break;
		  
		  default:
			  break;				   
	  }
  }


void OsdDispLeftTimerCountDown(void)
{
	WORD gu_Timer = 0;
		 switch(GET_OSD_Timer())
		 {
		 case _TIMER_10:
			 gu_Timer=10 * 60;
			 break;
		
		 
		case _TIMER_20:
		
			gu_Timer=20 * 60;
			break;
		case _TIMER_30:
			gu_Timer=30 * 60;
			break;
		case _TIMER_40:
			gu_Timer=40 * 60;
			
			break;
		case _TIMER_50:
			gu_Timer=50 * 60;
		break;
		case _TIMER_60:
			gu_Timer=60 * 60;
			break;
		case _TIMER_90:
			gu_Timer=90 * 60;
	
			break;
			default:
				break;
			}

			OsdFontPut1NumberTableForm(1, 1, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BG,(gu_Timer-g_usTimeUse)/60/10); 
			OsdFontPut1NumberTableForm(1, 3, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BG,(gu_Timer-g_usTimeUse)/60%10);
			OsdFontPut1NumberTableForm(1, 5, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BG,10);
			OsdFontPut1NumberTableForm(1, 7, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BG,(gu_Timer-g_usTimeUse)%60/10); 
			OsdFontPut1NumberTableForm(1, 9, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BG,(gu_Timer-g_usTimeUse)%60%10);
		 if( (gu_Timer-g_usTimeUse==0)) 
		 {
				g_usTime_OSD_OnOff1=_OFF;
				SET_OSD_STATE(_Menu_LEFTKEY_TIMER_ADJUST);
	         ScalerTimerActiveTimerEvent(SEC(1),_USER_TIMER_EVENT_OSD_DISABLE);		
	         ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_TIMER);

		 }
}

  
 void MenuLeftKeyGameAdjust(void)
{
	 CLR_KEYREPEATENABLE();

	switch(GET_KEYMESSAGE())
	{


	case _MENU_KEY_MESSAGE:
		SET_OSD_STATE(_Menu_LEFTKEY_GAME);
		g_MiaoZhun_OnOff1=_ON;
		OsdDispDisableOsd();
		OsdDispLeftAimMenu();
		/*ScalerOsdWindowDisable(_OSD_WINDOW_1);
		OsdFontPut1FuncTableForm(0, 0, _EDGE_LINE,g_ucOsdWidth-2,g_ucOsdHeight-2,_CP_BG,_CP_BG,3);
		OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
		switch(GET_OSD_AIM())
		{
			case _AIM_1:
				


				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG);
				
				break;
			case _AIM_2:
				

				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_YELLOW, _CP_BG);
				break;
			case _AIM_3:


				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
				break;
			case _AIM_4:
	

				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);
				break;
				
			 default:
				 break;
		}

*/
		
		//ScalerOsdWindowDisable(_OSD_WINDOW_1);
		//OsdFontPut1FuncTableForm(7, 13, _EDGE_LINE,22 ,10,_CP_BG,_CP_BG,3);
		//OsdFontPut1FuncTableForm(7, 40, _EDGE_LINE,22 ,10,_CP_BG,_CP_BG,_ARC_WINDOW_0);
		
		//OsdFuncClearOsd(ROW(7), COL(13), WIDTH(24), HEIGHT(14));
		
		//OsdFuncClearOsd(ROW(7), COL(40), WIDTH(24), HEIGHT(14));
	
	//	OsdFontPut1FuncTableForm(7, 13, _EDGE_LINE,22 ,10,_CP_WHITE,_CP_BLACK_1,3);
	//	OsdFontPut1FuncTableForm(7, 40, _EDGE_LINE,22 ,10,_CP_WHITE,_CP_BLACK_1,_ARC_WINDOW_0);
	
		//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_BG,_CP_BG,3);
		//OsdFontPut1BitMainMenuIcon(10, 8, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_WHITE);
		
		//OsdFontPut1BitMainMenuIcon(10, 24, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG);
		//OsdFontPut1FuncTableForm(8, 22, _EDGE_LINE,8 ,6,_CP_BG,_CP_BG,_ARC_WINDOW_0); 	
		
		//OsdFontPut1BitMainMenuIcon(10, 40, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
		//OsdFontPut1FuncTableForm(8, 38, _EDGE_LINE,8 ,6,_CP_BG,_CP_BG,_ARC_WINDOW_0); 	
	
		//OsdFontPut1BitMainMenuIcon(10, 56, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
		//OsdFontPut1FuncTableForm(8, 54, _EDGE_LINE,8 ,6,_CP_BG,_CP_BG,_ARC_WINDOW_0); 	
		
		//OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_WHITE, _CP_BG);
		//OsdDispDisableOsd();
		
		//OsdFontPut1BitMainMenuIcon(10, 38, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG); 
		//OsdFuncClearOsd(ROW(10), COL(38), WIDTH(6), HEIGHT(4));

	break;
		
	case _RIGHT_KEY_MESSAGE: 
	case _LEFT_KEY_MESSAGE:
		SET_OSD_AIM(OsdDisplayDetOverRange(GET_OSD_AIM() , _AIM_END, 0, _ON));


		
		switch(GET_OSD_AIM())
		{
			case _AIM_1:

				OsdFontPut1FuncAimTableForm(8, 12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_GRAY);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_2:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_GRAY);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_3:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
				
				//OsdFontPut1FuncTableForm(8, 38, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_GRAY); 

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_4:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	
				
				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_GRAY);
				break;
				
			 default:
				 break;
		}
		
		break;



	
	case _EXIT_KEY_MESSAGE:
		g_usTime_OSD_OnOff1=_OFF;
		g_MiaoZhun_OnOff1=_OFF;
		OsdFuncSetOsdItemFlag();
		OsdDispLeftMenu();
	break;
		
		default:
			break;					 
	}
}

  void OsdDispLeftTimerMenuPosition(void)
 {
 
	  CLR_KEYREPEATENABLE();
 
	 switch(GET_KEYMESSAGE())
	 {
 
 
	 case _MENU_KEY_MESSAGE:
		 g_usTimeUse=0;
		 g_usTime_OSD_OnOff1=_ON;
		 OsdDispDisableOsd();
		 OsdDispLeftTimerMenu();
		 //OsdDispLeftMenu();
		 	         SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

	 break;
		 
	 case _RIGHT_KEY_MESSAGE: 
	 case _LEFT_KEY_MESSAGE:
	 	
		 SET_OSD_Left_Timer_Position(OsdDisplayDetOverRange(GET_OSD_Left_Timer_Position() , _LEFT_TIMER_POSITION_END, _LEFT_TIMER_POSITION_1, _ON));
 
 
		 
		 switch(GET_OSD_Left_Timer_Position())
		 {
			 case _LEFT_TIMER_POSITION_1:
				 OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_BLACK_1, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_BLACK_1, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 break;
			 case _LEFT_TIMER_POSITION_2:
				 OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLACK_1, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_BLACK_1, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 break;
			 case _LEFT_TIMER_POSITION_3:
				 OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLACK_1, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_BLACK_1, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
				 OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
				 break;
			  default:
				  break;
		 }
		 
		 break;
 
 
 
	 
	 case _EXIT_KEY_MESSAGE:
	 	
		 SET_OSD_STATE(_Menu_LEFTKEY_TIMER_ADJUST);
		 ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		 OsdFuncDisableOsd();
		 OsdFuncCloseWindow(_OSD_WINDOW_ALL);
		 
		 OsdDispLeftTimerMenuAdjust();
		 g_usTime_OSD_OnOff1 =_OFF;
		 
		 
	 break;
		 
		 default:
			 break; 				  
	 }
 }


void OsdDispLeftTimerMenu(void)
{
    BYTE ucTest = 0;

    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;

    if(ucTest == 1)
    {
     //   ScalerDDomainPatternGenAdjustColor(0, 0, 0);


      //  OSTARFactoryPanelUsedTimer();
      //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
        

       ScalerOsdDataPort(0);

//#if(_DIGITAL_PORT_SUPPORT == _ON)
       // ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
//#endif

    }

    OsdFuncDisableOsd();

    OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_TIMER_WIDTH+1), HEIGHT(_OSD_LEFT_KEY_TIMER_HEIGHT+1), COLOR(_CP_BLACK_1, _CP_BG));

//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_LEFT_KEY_TIMER_HEIGHT+1), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(255);

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    //OsdFontVLCLoadFont(_FONT2_ICON_MENU);
	 OsdFontVLCLoadFont(_LEFT_MENU_TIME_ICON);
	 OsdFontVLCLoadFont(_LEFT_MENU_AIM_ICON);
	 OsdFontVLCLoadFont(_FOUR_CORNER);
	 OsdFontVLCLoadFont(_LEFT_MENU_NUMBER_ICON);
   // Background window
   //20140210 Abel Modify
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
  
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
	 }
    else
#endif
		{
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BG );
		
		//OsdFontPut1BitMainMenuIcon(0, 0, _LEFT_MENU_AIM_ICON_START+24 , _CP_BG, _CP_BG);
		//OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
		
		UserInterfaceTimerEventProc(_USER_TIMER_EVENT_OSD_TIMER);
		
	
	  //background	  
		}
	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
	  {
		switch(GET_OSD_Left_Timer_Position())
		{
			case _LEFT_TIMER_POSITION_1:
				OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,_OSD_H_POS_MAX-0, _OSD_V_POS_MAX-0);
				break;
			case _LEFT_TIMER_POSITION_2:
				OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,_OSD_H_POS_MAX-0, _OSD_V_POS_MAX-50);
				break;
			case _LEFT_TIMER_POSITION_3:
				OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, _OSD_H_POS_MAX-0, _OSD_V_POS_MAX-90);
				break;
			 default:
				 break;
		}
	  }  
	else
	  {
		switch(GET_OSD_Left_Timer_Position())
		{
			case _LEFT_TIMER_POSITION_1:
				OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,0, 0);
				break;
			case _LEFT_TIMER_POSITION_2:
				OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,0, 50);
				break;
			case _LEFT_TIMER_POSITION_3:
				OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 0, 100);
				break;
			 default:
				 break;
		}
	}



	


    // Osd Enable
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();

}

void MenuNone(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
		if(GET_OSD_FACTORY_STATUS() == _ON)
		{

					RTDFactoryMainMenu();	
	
		}
		else
		{
            

	if(g_usTime_OSD_OnOff1 ==_ON && g_MiaoZhun_OnOff1!=_ON)
	{
		SET_OSD_STATE(_Menu_LEFTKEY_TIMER_ADJUST);
		
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdFuncDisableOsd();
		OsdFuncCloseWindow(_OSD_WINDOW_ALL);
		//OsdDispLeftMenu();
		OsdDispLeftTimerMenuAdjust();
		g_usTime_OSD_OnOff1 = _OFF;
	
	}
	else if(g_MiaoZhun_OnOff1==_ON && g_usTime_OSD_OnOff1 !=_ON)
	{
		SET_OSD_STATE(_Menu_LEFTKEY_GAME_ADJUST);
		
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdFuncDisableOsd();
		OsdFuncCloseWindow(_OSD_WINDOW_ALL);
		//OsdDispLeftMenu();
		OsdDispLeftAimMenuAdjust();
		g_MiaoZhun_OnOff1 = _OFF;
		
	}
	else
	{
                SET_OSD_STATE(_MENU_PICTURE);
               OsdFuncSetOsdItemFlag();

                OsdDispMainMenu();
	 
	}


}
       }     
            break;
        case _RIGHT_KEY_MESSAGE :

            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
		if(GET_OSD_FACTORY_STATUS() == _ON)
		{

	
		}
		else
		{
            


        
			   if( g_usTime_OSD_OnOff1!=_ON && g_MiaoZhun_OnOff1!=_ON)
		      {  
				OsdFuncSetOsdItemFlag();
				OsdDispLeftMenu();


		      }
			   else if(g_usTime_OSD_OnOff1 == _ON && g_MiaoZhun_OnOff1!=_ON)
			   {
				   g_usTimeUse=0;
				   SET_OSD_Timer(OsdDisplayDetOverRange(GET_OSD_Timer() , _TIMER_END, _TIMER_10, _ON));
			   }
			   else if(g_MiaoZhun_OnOff1==_ON && g_usTime_OSD_OnOff1 !=_ON)
			   {
				   SET_OSD_AIM(OsdDisplayDetOverRange(GET_OSD_AIM() , _AIM_END, 0, _ON));
				   OsdDispLeftAimMenu();
			   }

}
}
            break;
        case _LEFT_KEY_MESSAGE :

            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
		if(GET_OSD_FACTORY_STATUS() == _ON)
		{

	
		}
		else
		{
            

			if( g_usTime_OSD_OnOff1!=_ON && g_MiaoZhun_OnOff1 !=_ON)
			{  

				
				SET_OSD_STATE(_Menu_Hotkey_ECO_Adjust);
				OsdFuncSetOsdItemFlag();
				OsdDispRightMenu();
				OsdPropPutString(ROW(5), COL(6), _PFONT_PAGE_1, _ECO, COLOR(_CP_WHITE, _CP_BG),GET_OSD_LANGUAGE());
				switch(GET_OSD_COLOR_EFFECT())
				{
					case _PICTURE_STANDARD:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_STANDARD, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
						break;
					case _PICTURE_GAME:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_MOVE, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());	
						break;
					case _PICTURE_MOVIE:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PHOTO, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());	
						break;
					case _PICTURE_PHOTO:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_GAME, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
						break;
				   case _PICTURE_USER:
					   OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
					   OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_FPS, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				   case _PICTURE_FPS:
					   OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
					   OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_RTS, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				   case _PICTURE_RTS:
					   OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
					   OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_USER, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
					   break;
						
					 default:
						 break;
				}
			}
			else if(g_usTime_OSD_OnOff1==_ON && g_MiaoZhun_OnOff1 !=_ON)
			{
				g_usTimeUse=0;
				SET_OSD_Timer(OsdDisplayDetOverRange(GET_OSD_Timer() , _TIMER_END, _TIMER_10, _ON));

			}
			else if(g_MiaoZhun_OnOff1==_ON && g_usTime_OSD_OnOff1 !=_ON)
			{
				SET_OSD_AIM(OsdDisplayDetOverRange(GET_OSD_AIM() , _AIM_END, 0, _ON));
				OsdDispLeftAimMenu();
			}
}
}
            break;

        case _EXIT_KEY_MESSAGE:
            if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
		if(GET_OSD_FACTORY_STATUS() == _ON)
		{

	
		}
		else
		{
            



  			if(g_usTime_OSD_OnOff1!=_ON && g_MiaoZhun_OnOff1!=_ON)
			{
                		CLR_KEYREPEATENABLE();
                /*
                			if(SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)
                			{
                				SET_OSD_POWER_SAVING_SHOW_SOURCE(_TRUE);
                
                				if((SysPowerGetPowerStatus() == _POWER_STATUS_SAVING) || (SysPowerGetPowerStatus() == _POWER_STATUS_NOSUPPORT_SAVING))
                				{
                					SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);
                				}
                			 }
                			else if((SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) || (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
                			{
                				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_CHANGE_SOURCE_MENU_MSG);
                			}
                			else 
*/

                			if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                			{
                			       SET_OSD_STATE(_MENU_HOT_INPUT_ADJUST);
                				MenuHotInput();
                			}
			}
			else  if(g_MiaoZhun_OnOff1==_ON && g_usTime_OSD_OnOff1 !=_ON)
			{
				SET_OSD_STATE(_Menu_LEFTKEY_GAME_ADJUST);
				
				ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
				OsdFuncDisableOsd();
				OsdFuncCloseWindow(_OSD_WINDOW_ALL);
				
				OsdDispLeftAimMenuAdjust();
				g_MiaoZhun_OnOff1 = _OFF;
			}
			else if(g_usTime_OSD_OnOff1 ==_ON && g_MiaoZhun_OnOff1!=_ON)
			{
				SET_OSD_STATE(_Menu_LEFTKEY_TIMER_ADJUST);
				
				ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
				OsdFuncDisableOsd();
				OsdFuncCloseWindow(_OSD_WINDOW_ALL);
				
				OsdDispLeftTimerMenuAdjust();
				g_usTime_OSD_OnOff1 = _OFF;
			
			}
}
}

            break;

        default:
            break;
    }
}

void MenuPicture(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
		if(GET_OSD_COLOR_EFFECT() != _ECO_MODE_USER)
        {
        SET_OSD_STATE(_MENU_PICTURE_ECO);
		
      UpdateSubInterface(1);
      Update3thInterface(1,3);
            OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED , _CP_BLACK_1),0);
 
        }
        else
        {
              SET_OSD_STATE(_MENU_PICTURE_BACKLIGHT);
        		
      UpdateSubInterface(1);
      Update3thInterface(1,1);
        }


            break;

        case _RIGHT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_FREESYNC);
UpdateInterface(6);

            break;

        case _LEFT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_COLOR);
 UpdateInterface(2);


            break;

        case _EXIT_KEY_MESSAGE:
                OsdFuncDisableOsd();
                  SET_OSD_STATE(_MENU_NONE);


            break;

        default:
            break;
    }
}

void MenuColor(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

              SET_OSD_STATE(_MENU_COLOR_TEMP);
        		
		      UpdateSubInterface2(1);
		      Update3thInterface(2,1);

            break;

        case _RIGHT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_PICTURE);
UpdateInterface(1);

            break;

        case _LEFT_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_OSD_SETTING);
UpdateInterface(3);


            break;

        case _EXIT_KEY_MESSAGE:
                        OsdFuncDisableOsd();
                  SET_OSD_STATE(_MENU_NONE);
            break;

        default:
            break;
    }
}

void MenuOsd(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

              SET_OSD_STATE(_MENU_OSD_LANGUAGE);
        		
		      UpdateSubInterface3(1);
		      Update3thInterface(3,1);

            break;

        case _RIGHT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_COLOR);
UpdateInterface(2);

            break;

        case _LEFT_KEY_MESSAGE:
           
               SET_OSD_STATE(_MENU_SETUP);
UpdateInterface(4);

            break;

        case _EXIT_KEY_MESSAGE:
                        OsdFuncDisableOsd();
                  SET_OSD_STATE(_MENU_NONE);
            break;

        default:
            break;
    }
}



void MenuSetup(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                       SET_OSD_STATE(_MENU_SETUP_INPUT);

		      UpdateSubInterface3(1);

#if(_OSD_AUDIO_SUPPORT ==  _OFF)
			  OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY , _CP_BLACK_1),0);
			  OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY	, _CP_BLACK_1),0);
#endif
				Update3thInterface(4,1);
            break;

        case _RIGHT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_OSD_SETTING);
UpdateInterface(3);

            break;

        case _LEFT_KEY_MESSAGE:
                SET_OSD_STATE(_MENU_OTHER);
UpdateInterface(5);


            break;

        case _EXIT_KEY_MESSAGE:
                        OsdFuncDisableOsd();
                  SET_OSD_STATE(_MENU_NONE);
            break;

        default:
            break;
    }
}


void MenuOthers(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                       SET_OSD_STATE(_MENU_OTHERS_RATIO);

		      UpdateSubInterface3(1);

				Update3thInterface(5,1);

            break;

        case _RIGHT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_SETUP);
UpdateInterface(4);

            break;

        case _LEFT_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_FREESYNC);
UpdateInterface(6);


            break;

        case _EXIT_KEY_MESSAGE:
                        OsdFuncDisableOsd();
                  SET_OSD_STATE(_MENU_NONE);
            break;

        default:
            break;
    }
}
void MenuPictureECO(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_PICTURE_ECO_ADJ);

			OSDFunctionAdj(_MENU_PICTURE_ECO_ADJ,GET_OSD_COLOR_EFFECT());
            break;

        case _RIGHT_KEY_MESSAGE:
		if(GET_OSD_COLOR_EFFECT() == _ECO_MODE_USER)
{
              SET_OSD_STATE(_MENU_PICTURE_CONTRAST);
UpdateSubInterface(2);

            Update3thInterface(1,2);
}
else
{       
       SET_OSD_STATE(_MENU_PICTURE_HDR);

      UpdateSubInterface(5);
                  Update3thInterface(1,5);
}
            break;

        case _LEFT_KEY_MESSAGE:
		if(GET_OSD_COLOR_EFFECT() == _ECO_MODE_USER)
{       
              SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
UpdateSubInterface(4);

            Update3thInterface(1,4);
}
		else
			{       
                                                        SET_OSD_STATE(_MENU_PICTURE_HDR);

      UpdateSubInterface(5);
                  Update3thInterface(1,5);
}
            break;

        case _EXIT_KEY_MESSAGE:
                                              SET_OSD_STATE(_MENU_PICTURE);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

        
            break;

        default:
            break;
    }
}

void MenuPictureMainSR(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_PICTURE_MAIN_SR_ADJ);

			OSDFunctionAdj(_MENU_PICTURE_MAIN_SR_ADJ,GET_OSD_SHARPNESS());

            break;

        case _RIGHT_KEY_MESSAGE:
                                             SET_OSD_STATE(_MENU_PICTURE_ECO);

      UpdateSubInterface(3);

                  Update3thInterface(1,3);

            break;

        case _LEFT_KEY_MESSAGE:
                                                        SET_OSD_STATE(_MENU_PICTURE_HDR);

      UpdateSubInterface(5);
                  Update3thInterface(1,5);


            break;

        case _EXIT_KEY_MESSAGE:
                                              SET_OSD_STATE(_MENU_PICTURE);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
		OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

        
            break;

        default:
            break;
    }
}

void MenuPictureHDR(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_PICTURE_HDR_ADJ);

			OSDFunctionAdj(_MENU_PICTURE_HDR_ADJ,GET_OSD_HDR_MODE());

            break;

        case _RIGHT_KEY_MESSAGE:
					if(GET_OSD_COLOR_EFFECT() == _ECO_MODE_USER)

				{
                                             SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);

      UpdateSubInterface(4);

                  Update3thInterface(1,4);
        	}
else
	{
                                             SET_OSD_STATE(_MENU_PICTURE_ECO);

      UpdateSubInterface(3);

                  Update3thInterface(1,3);
}
            break;

        case _LEFT_KEY_MESSAGE:
					if(GET_OSD_COLOR_EFFECT() == _ECO_MODE_USER)
						{
                                                        SET_OSD_STATE(_MENU_PICTURE_BACKLIGHT);

      UpdateSubInterface(1);
                  Update3thInterface(1,1);
						}
					else
						{
                                             SET_OSD_STATE(_MENU_PICTURE_ECO);

      UpdateSubInterface(3);

                  Update3thInterface(1,3);
}

            break;

        case _EXIT_KEY_MESSAGE:
                                              SET_OSD_STATE(_MENU_PICTURE);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
		OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

        
            break;

        default:
            break;
    }
}
void OSD_NULL(void)
{
}


void MenuFactory(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:


            break;

        case _RIGHT_KEY_MESSAGE:

            break;

        case _LEFT_KEY_MESSAGE:
           

            break;

        case _EXIT_KEY_MESSAGE:
            break;

        default:
            break;
    }
}

void MenuPictureBacklight(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			   OsdDispSliderAndNumber(MENU_PICTURE_BACKLIGHT_ADJ,GET_OSD_BACKLIGHT()); 
                       SET_OSD_STATE(MENU_PICTURE_BACKLIGHT_ADJ);
	//		OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
                       SET_OSD_STATE(_MENU_PICTURE_HDR);

      UpdateSubInterface(5);
            Update3thInterface(1,5);


            break;

        case _LEFT_KEY_MESSAGE:
                                  SET_OSD_STATE(_MENU_PICTURE_CONTRAST);

      UpdateSubInterface(2);
            Update3thInterface(1,2);

            break;

        case _EXIT_KEY_MESSAGE:
                                              SET_OSD_STATE(_MENU_PICTURE);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

        
            break;

        default:
            break;
    }
}

void MenuPictureBacklightAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT,GET_OSD_BACKLIGHT()); 
                                                    SET_OSD_STATE(_MENU_PICTURE_BACKLIGHT);
			//OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(MENU_PICTURE_BACKLIGHT_ADJ,GET_OSD_BACKLIGHT()); 

            break;

        case _LEFT_KEY_MESSAGE:
         			    OsdDispSliderAndNumber(MENU_PICTURE_BACKLIGHT_ADJ,GET_OSD_BACKLIGHT()); 
  

            break;

        case _EXIT_KEY_MESSAGE:

        			    OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT,GET_OSD_BACKLIGHT()); 
                                                    SET_OSD_STATE(_MENU_PICTURE_BACKLIGHT);
		//	OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuPictureContrast(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST_ADJ,GET_OSD_CONTRAST()); 
                       SET_OSD_STATE(_MENU_PICTURE_CONTRAST_ADJ);
	//		OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
                       SET_OSD_STATE(_MENU_PICTURE_BACKLIGHT);

      UpdateSubInterface(1);
                  Update3thInterface(1,1);

            break;

        case _LEFT_KEY_MESSAGE:
                                  SET_OSD_STATE(_MENU_PICTURE_ECO);

      UpdateSubInterface(3);
            Update3thInterface(1,3);

            break;

        case _EXIT_KEY_MESSAGE:

                                                    SET_OSD_STATE(_MENU_PICTURE);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
		OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);
  
            break;

        default:
            break;
    }
}

void MenuPictureContrastAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                                                    SET_OSD_STATE(_MENU_PICTURE_CONTRAST);

			    OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST,GET_OSD_CONTRAST()); 
		//	OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST_ADJ,GET_OSD_CONTRAST()); 

            break;

        case _LEFT_KEY_MESSAGE:
               OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST_ADJ,GET_OSD_CONTRAST()); 


            break;

        case _EXIT_KEY_MESSAGE:
        		  OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST,GET_OSD_CONTRAST()); 
                                                    SET_OSD_STATE(_MENU_PICTURE_CONTRAST);
		//	OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuPictureECOAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_PICTURE_ECO);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_COLOR_EFFECT()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
           SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT(), _ECO_MODE_USER, _ECO_MODE_STANDARD, _ON));

			OSDFunctionAdj(_MENU_PICTURE_ECO_ADJ,GET_OSD_COLOR_EFFECT());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;

        case _LEFT_KEY_MESSAGE:
           SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT(), _ECO_MODE_USER, _ECO_MODE_STANDARD, _ON));

			OSDFunctionAdj(_MENU_PICTURE_ECO_ADJ,GET_OSD_COLOR_EFFECT());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;

        case _EXIT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_PICTURE_ECO);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_COLOR_EFFECT()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}



void MenuPictureHDRAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_PICTURE_HDR);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_HDR_MODE()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
				SET_OSD_HDR_MODE(OsdDisplayDetOverRange(GET_OSD_HDR_MODE(), _HDR_MODE_SMPTE_ST_2084, _LEVEL_OFF, _ON));

				OSDFunctionAdj(_MENU_PICTURE_HDR_ADJ,GET_OSD_HDR_MODE());

				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);


            break;

        case _LEFT_KEY_MESSAGE:
				SET_OSD_HDR_MODE(OsdDisplayDetOverRange(GET_OSD_HDR_MODE(), _HDR_MODE_SMPTE_ST_2084, _LEVEL_OFF, _ON));

				OSDFunctionAdj(_MENU_PICTURE_HDR_ADJ,GET_OSD_HDR_MODE());

				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;

        case _EXIT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_PICTURE_HDR);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_HDR_MODE()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}


void MenuPictureMainSRAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_SHARPNESS()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
				SET_OSD_SHARPNESS(OsdDisplayDetOverRange(GET_OSD_SHARPNESS(), _LEVEL_STRONGEST, _LEVEL_OFF, _ON));

				OSDFunctionAdj(_MENU_PICTURE_MAIN_SR_ADJ,GET_OSD_SHARPNESS());

				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);


            break;

        case _LEFT_KEY_MESSAGE:
				SET_OSD_SHARPNESS(OsdDisplayDetOverRange(GET_OSD_SHARPNESS(), _LEVEL_STRONGEST, _LEVEL_OFF, _ON));

				OSDFunctionAdj(_MENU_PICTURE_MAIN_SR_ADJ,GET_OSD_SHARPNESS());

				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;

        case _EXIT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_SHARPNESS()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuColorTemp(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_COLOR_TEMP_ADJ);

			OSDFunctionAdj(_MENU_COLOR_TEMP_ADJ,GET_COLOR_TEMP_TYPE());


            break;

        case _RIGHT_KEY_MESSAGE:
        if(GET_COLOR_TEMP_TYPE() == _CT_USER)
		{
			SET_OSD_STATE(_MENU_COLOR_B);

			UpdateSubInterface2(4);
			Update3thInterface(2,4);
		}
            break;

        case _LEFT_KEY_MESSAGE:
		if(GET_COLOR_TEMP_TYPE() == _CT_USER)
		{
                SET_OSD_STATE(_MENU_COLOR_R);

				UpdateSubInterface2(2);
				Update3thInterface(2,2);
		}

            break;

        case _EXIT_KEY_MESSAGE:

                                                      SET_OSD_STATE(_MENU_COLOR);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuColorR(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

			   OsdDispSliderAndNumber(_MENU_COLOR_R_ADJ,GET_COLOR_TEMP_TYPE_USER_R()); 
                       SET_OSD_STATE(_MENU_COLOR_R_ADJ);
		//	OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
                                  SET_OSD_STATE(_MENU_COLOR_TEMP);

      UpdateSubInterface2(1);
            Update3thInterface(2,1);

            break;

        case _LEFT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_COLOR_G);

      UpdateSubInterface2(3);
            Update3thInterface(2,3);

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_COLOR);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}


void MenuColorG(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			   OsdDispSliderAndNumber(_MENU_COLOR_G_ADJ,GET_COLOR_TEMP_TYPE_USER_G()); 
                       SET_OSD_STATE(_MENU_COLOR_G_ADJ);
		//	OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
                                  SET_OSD_STATE(_MENU_COLOR_R);

      UpdateSubInterface2(2);
            Update3thInterface(2,2);
            break;

        case _LEFT_KEY_MESSAGE:
                                             SET_OSD_STATE(_MENU_COLOR_B);

      UpdateSubInterface2(4);
            Update3thInterface(2,4);

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_COLOR);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
		OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuColorB(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			   OsdDispSliderAndNumber(_MENU_COLOR_B_ADJ,GET_COLOR_TEMP_TYPE_USER_B()); 
                       SET_OSD_STATE(_MENU_COLOR_B_ADJ);
		//	OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
                                SET_OSD_STATE(_MENU_COLOR_G);

      UpdateSubInterface2(3);
            Update3thInterface(2,3);
            break;

        case _LEFT_KEY_MESSAGE:
           
                                SET_OSD_STATE(_MENU_COLOR_TEMP);

      UpdateSubInterface2(1);
            Update3thInterface(2,1);
            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_COLOR);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
		OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuColorTempAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_COLOR_TEMP);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_COLOR_TEMP_TYPE()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
           SET_COLOR_TEMP_TYPE(OsdDisplayDetOverRange(GET_COLOR_TEMP_TYPE(), _CT_USER, _CT_6500, _ON));

			OSDFunctionAdj(_MENU_COLOR_TEMP_ADJ,GET_COLOR_TEMP_TYPE());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);

            break;

        case _LEFT_KEY_MESSAGE:
                      SET_COLOR_TEMP_TYPE(OsdDisplayDetOverRange(GET_COLOR_TEMP_TYPE(), _CT_USER, _CT_6500, _ON));

			OSDFunctionAdj(_MENU_COLOR_TEMP_ADJ,GET_COLOR_TEMP_TYPE());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);


            break;

        case _EXIT_KEY_MESSAGE:
                              SET_OSD_STATE(_MENU_COLOR_TEMP);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_COLOR_TEMP_TYPE()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}
void MenuColorRAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_COLOR_R,GET_COLOR_TEMP_TYPE_USER_R()); 
                                                    SET_OSD_STATE(_MENU_COLOR_R);
	//		OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);


            break;

        case _RIGHT_KEY_MESSAGE:
			OsdDispSliderAndNumber(_MENU_COLOR_R_ADJ,GET_COLOR_TEMP_TYPE_USER_R()); 

            break;

        case _LEFT_KEY_MESSAGE:
    			OsdDispSliderAndNumber(_MENU_COLOR_R_ADJ,GET_COLOR_TEMP_TYPE_USER_R()); 
       

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_COLOR_R,GET_COLOR_TEMP_TYPE_USER_R()); 
                                                    SET_OSD_STATE(_MENU_COLOR_R);

            break;

        default:
            break;
    }
}


void MenuColorGAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

			    OsdDispSliderAndNumber(_MENU_COLOR_G,GET_COLOR_TEMP_TYPE_USER_G()); 
                                                    SET_OSD_STATE(_MENU_COLOR_G);

            break;

        case _RIGHT_KEY_MESSAGE:
        			OsdDispSliderAndNumber(_MENU_COLOR_G_ADJ,GET_COLOR_TEMP_TYPE_USER_G()); 


            break;

        case _LEFT_KEY_MESSAGE:
           
        			OsdDispSliderAndNumber(_MENU_COLOR_G_ADJ,GET_COLOR_TEMP_TYPE_USER_G()); 

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_COLOR_G,GET_COLOR_TEMP_TYPE_USER_G()); 
                                                    SET_OSD_STATE(_MENU_COLOR_G);

            break;

        default:
            break;
    }
}

void MenuColorBAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

			    OsdDispSliderAndNumber(_MENU_COLOR_B,GET_COLOR_TEMP_TYPE_USER_B()); 
                                                    SET_OSD_STATE(_MENU_COLOR_B);

            break;

        case _RIGHT_KEY_MESSAGE:

       			OsdDispSliderAndNumber(_MENU_COLOR_B_ADJ,GET_COLOR_TEMP_TYPE_USER_B()); 

         break;

        case _LEFT_KEY_MESSAGE:
       			OsdDispSliderAndNumber(_MENU_COLOR_B_ADJ,GET_COLOR_TEMP_TYPE_USER_B()); 
 

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_COLOR_B,GET_COLOR_TEMP_TYPE_USER_B()); 
                                                    SET_OSD_STATE(_MENU_COLOR_B);

            break;

        default:
            break;
    }
}

void MenuOsdLanguage(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                 SET_OSD_STATE(_MENU_OSD_LANGUAGE_ADJ);
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW+2*GET_OSD_LANGUAGE()), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);



            break;

        case _RIGHT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OSD_TIME);
        		
		      UpdateSubInterface3(5);
		      Update3thInterface(3,5);
            break;

        case _LEFT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_OSD_HPos);
        		
		      UpdateSubInterface3(2);
		      Update3thInterface(3,2);

            break;

        case _EXIT_KEY_MESSAGE:
                                                                      SET_OSD_STATE(_MENU_OSD_SETTING);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);


            break;

        default:
            break;
    }
}



void MenuOsdHPos(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_H_ADJ,GET_OSD_HPOS()); 
                       SET_OSD_STATE(_MENU_OSD_H_ADJ);


            break;

        case _RIGHT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OSD_LANGUAGE);
        		
		      UpdateSubInterface3(1);
		      Update3thInterface(3,1);
            break;

        case _LEFT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_OSD_VPos);
        		
		      UpdateSubInterface3(3);
		      Update3thInterface(3,3);

            break;

        case _EXIT_KEY_MESSAGE:
                                                      SET_OSD_STATE(_MENU_OSD_SETTING);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuOsdVPos(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_V_ADJ,GET_OSD_VPOS()); 
                       SET_OSD_STATE(_MENU_OSD_V_ADJ);

            break;

        case _RIGHT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_OSD_HPos);
        		
		      UpdateSubInterface3(2);
		      Update3thInterface(3,2);
            break;

        case _LEFT_KEY_MESSAGE:
                                 SET_OSD_STATE(_MENU_OSD_TRNAS);
        		
		      UpdateSubInterface3(4);
		      Update3thInterface(3,4);

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_OSD_SETTING);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}


void MenuOsdTrans(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_TRNA_ADJ,GET_OSD_TRANSPARENCY_STATUS()); 
                       SET_OSD_STATE(_MENU_OSD_TRNA_ADJ);

            break;

        case _RIGHT_KEY_MESSAGE:
                                 SET_OSD_STATE(_MENU_OSD_VPos);
        		
		      UpdateSubInterface3(3);
		      Update3thInterface(3,3);
            break;

        case _LEFT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OSD_TIME);
        		
		      UpdateSubInterface3(5);
		      Update3thInterface(3,5);

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_OSD_SETTING);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuOsdTime(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

			    OsdDispSliderAndNumber(_MENU_OSD_TIME_ADJ,GET_OSD_TIME_OUT()); 
                       SET_OSD_STATE(_MENU_OSD_TIME_ADJ);

            break;

        case _RIGHT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OSD_TRNAS);
        		
		      UpdateSubInterface3(4);
		      Update3thInterface(3,4);
            break;

        case _LEFT_KEY_MESSAGE:
                                                     SET_OSD_STATE(_MENU_OSD_LANGUAGE);
        		
		      UpdateSubInterface3(1);
		      Update3thInterface(3,1);  

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_OSD_SETTING);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuOsdLanguageAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
            case _EXIT_KEY_MESSAGE:
        case _MENU_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_OSD_LANGUAGE);
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW+2*GET_OSD_LANGUAGE()), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
			#if 0
                SET_OSD_LANGUAGE(OsdDisplayDetOverRange(GET_OSD_LANGUAGE(), _LANGUAGE_AMOUNT, _ENGLISH, _ON));

			OSDFunctionAdj(_MENU_OSD_LANGUAGE_ADJ,GET_OSD_LANGUAGE());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
      
#endif
            break;


        default:
            break;
    }
}

void MenuOsdHPosAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_HPos,GET_OSD_HPOS()); 
                                                    SET_OSD_STATE(_MENU_OSD_HPos);


            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_H_ADJ,GET_OSD_HPOS()); 

            break;

        case _LEFT_KEY_MESSAGE:
       			    OsdDispSliderAndNumber(_MENU_OSD_H_ADJ,GET_OSD_HPOS()); 
    

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_OSD_HPos,GET_OSD_HPOS()); 
                                                    SET_OSD_STATE(_MENU_OSD_HPos);

            break;

        default:
            break;
    }
}

void MenuOsdVPosAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_VPos,GET_OSD_VPOS()); 
                                                    SET_OSD_STATE(_MENU_OSD_VPos);


            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_V_ADJ,GET_OSD_VPOS()); 

            break;

        case _LEFT_KEY_MESSAGE:
     			    OsdDispSliderAndNumber(_MENU_OSD_V_ADJ,GET_OSD_VPOS()); 
     

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_OSD_VPos,GET_OSD_VPOS()); 
                                                    SET_OSD_STATE(_MENU_OSD_VPos);

            break;

        default:
            break;
    }
}

void MenuOsdTransAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_TRNAS,GET_OSD_TRANSPARENCY_STATUS()); 
                                                    SET_OSD_STATE(_MENU_OSD_TRNAS);


            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_TRNA_ADJ,GET_OSD_TRANSPARENCY_STATUS()); 

            break;

        case _LEFT_KEY_MESSAGE:
          			    OsdDispSliderAndNumber(_MENU_OSD_TRNA_ADJ,GET_OSD_TRANSPARENCY_STATUS()); 
 

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_OSD_TRNAS,GET_OSD_TRANSPARENCY_STATUS()); 
                                                    SET_OSD_STATE(_MENU_OSD_TRNAS);

            break;

        default:
            break;
    }
}

void MenuOsdTimeAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_TIME,GET_OSD_TIME_OUT()); 
                                                    SET_OSD_STATE(_MENU_OSD_TIME);


            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_OSD_TIME_ADJ,GET_OSD_TIME_OUT()); 

            break;

        case _LEFT_KEY_MESSAGE:
    			    OsdDispSliderAndNumber(_MENU_OSD_TIME_ADJ,GET_OSD_TIME_OUT()); 
       

            break;

        case _EXIT_KEY_MESSAGE:
        			    OsdDispSliderAndNumber(_MENU_OSD_TIME,GET_OSD_TIME_OUT()); 
                                                    SET_OSD_STATE(_MENU_OSD_TIME);

            break;

        default:
            break;
    }
}

void MenuSetupInput(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

              SET_OSD_STATE(_MENU_SETUP_INPUT_ADJ);

			OSDFunctionAdj(_MENU_SETUP_INPUT_ADJ,GET_OSD_INPUT_PORT_OSD_ITEM());

            break;

        case _RIGHT_KEY_MESSAGE:
                  SET_OSD_STATE(_MENU_SETUP_RESET);
        		
		      UpdateSubInterface3(4);
#if(_OSD_AUDIO_SUPPORT ==  _OFF)
			OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY , _CP_BLACK_1),0);
			OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY  , _CP_BLACK_1),0);
#endif
		      Update3thInterface(4,4);
            break;

        case _LEFT_KEY_MESSAGE:
#if(_OSD_AUDIO_SUPPORT ==  _ON)
                           SET_OSD_STATE(_MENU_SETUP_MUTE);
        		
		      UpdateSubInterface3(2);
		      Update3thInterface(4,2);  
#else
			 SET_OSD_STATE(_MENU_SETUP_RESET);
			   
			 UpdateSubInterface3(4);
			 
#if(_OSD_AUDIO_SUPPORT ==  _OFF)
			   OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY , _CP_BLACK_1),0);
			   OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY  , _CP_BLACK_1),0);
#endif
			 Update3thInterface(4,4);

#endif
            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_SETUP);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuSetupMute(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_SETUP_MUTE_ADJ);

			OSDFunctionAdj(_MENU_SETUP_MUTE_ADJ,GET_OSD_LED());

            break;

        case _RIGHT_KEY_MESSAGE:
                  SET_OSD_STATE(_MENU_SETUP_INPUT);
        		
		      UpdateSubInterface3(1);
		      Update3thInterface(4,1);
            break;

        case _LEFT_KEY_MESSAGE:
                             SET_OSD_STATE(_MENU_SETUP_VOLUME);
        		
		      UpdateSubInterface3(3);
		      Update3thInterface(4,3);

            break;

        case _EXIT_KEY_MESSAGE:

                                                              SET_OSD_STATE(_MENU_SETUP);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuSetupVolume(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_SETUP_VOLUME_ADJ,GET_OSD_VOLUME()); 
                       SET_OSD_STATE(_MENU_SETUP_VOLUME_ADJ);

            break;

        case _RIGHT_KEY_MESSAGE:
                             SET_OSD_STATE(_MENU_SETUP_MUTE);
        		
		      UpdateSubInterface3(2);
		      Update3thInterface(4,2);
            break;

        case _LEFT_KEY_MESSAGE:
                                      SET_OSD_STATE(_MENU_SETUP_RESET);
        		
		      UpdateSubInterface3(4);
		      Update3thInterface(4,4);  

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_SETUP);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuSetupReset(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

OsdDispOsdReset();
            break;

        case _RIGHT_KEY_MESSAGE:
			
#if(_OSD_AUDIO_SUPPORT ==  _ON)
		 SET_OSD_STATE(_MENU_SETUP_VOLUME);
			
		  UpdateSubInterface3(3);
		  Update3thInterface(4,3);
#else
		 SET_OSD_STATE(_MENU_SETUP_INPUT);
  
                UpdateSubInterface3(1);
				
#if(_OSD_AUDIO_SUPPORT ==  _OFF)
		   OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY , _CP_BLACK_1),0);
		   OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY  , _CP_BLACK_1),0);
#endif
                Update3thInterface(4,1);


#endif
		      break;

        case _LEFT_KEY_MESSAGE:
                             SET_OSD_STATE(_MENU_SETUP_INPUT);
        		
		      UpdateSubInterface3(1);
			  
#if(_OSD_AUDIO_SUPPORT ==  _OFF)
			 OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY , _CP_BLACK_1),0);
			 OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY  , _CP_BLACK_1),0);
#endif
		      Update3thInterface(4,1);
            break;

        case _EXIT_KEY_MESSAGE:

                                                      SET_OSD_STATE(_MENU_SETUP);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuSetupInputAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
if(OsdFuncGetOsdItemFlag() == GET_OSD_INPUT_PORT_OSD_ITEM())
{
         SET_OSD_STATE(_MENU_SETUP_INPUT);
         OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);
	        OsdFuncClearOsd(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2, SELECT_ICON, WIDTH(1), HEIGHT(1));

         OsdFuncSetOsdItemFlag();
	    OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));

}
else
{
	  switch(GET_OSD_INPUT_PORT_OSD_ITEM())
        {
            case _OSD_INPUT_AUTO:
                if(SysSourceGetScanType() != _SOURCE_SWITCH_AUTO_IN_GROUP)
            {
                SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
                {
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }
            
                break;
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)

            case _OSD_INPUT_A0:
              if( (SysSourceGetInputPort() != _A0_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_A0_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
             //   SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }          
                break;
#endif
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

            case _OSD_INPUT_D0:
            if( (SysSourceGetInputPort() != _D0_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D0_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
             //   SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }              

            break;
#endif       

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)

            case _OSD_INPUT_D1:
            if(  (SysSourceGetInputPort() != _D1_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D1_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
             //   SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }

                break;
       #endif
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)

            case _OSD_INPUT_D2:
            if(  (SysSourceGetInputPort() != _D2_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D2_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
              //  SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }            

            break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
            case _OSD_INPUT_D3:
            if(  (SysSourceGetInputPort() != _D3_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D3_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
             //   SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            } 

            break;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)

			case _OSD_INPUT_D4:
            if( (SysSourceGetInputPort() != _D4_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D4_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
              //  SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }


                break;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)

            case _OSD_INPUT_D5:

            if( (SysSourceGetInputPort() != _D5_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D5_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
            //    SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }
                break;
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)

            case _OSD_INPUT_D6:
            if( (SysSourceGetInputPort() != _D6_INPUT_PORT))
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D6_INPUT_PORT);
                SET_OSD_STATE(_MENU_INPUT);
              //  SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
                   (UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
                {
                    UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(UserInterfaceGetDpMSTCapablePort());
                RTDNVRamSaveOSDData();
#endif
            }


                break;
#endif
            default:
                break;
        }	

}






            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
             SET_OSD_INPUT_PORT_OSD_ITEM(OsdDisplayDetOverRange(GET_OSD_INPUT_PORT_OSD_ITEM(), (_OSD_INPUT_AMOUNT-1), 0, _ON));

			OSDFunctionAdj(_MENU_SETUP_INPUT_ADJ,GET_OSD_INPUT_PORT_OSD_ITEM());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        

            break;

        case _EXIT_KEY_MESSAGE:
         SET_OSD_STATE(_MENU_SETUP_INPUT);
         OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);
	        OsdFuncClearOsd(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2, SELECT_ICON, WIDTH(1), HEIGHT(1));

         OsdFuncSetOsdItemFlag();
	    OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));

     

            break;

        default:
            break;
    }
}

void MenuSetupMuteAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_SETUP_MUTE);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_LED()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
          SET_OSD_LED(OsdDisplayDetOverRange(GET_OSD_LED(),1, _OFF, _ON));

			OSDFunctionAdj(_MENU_SETUP_MUTE_ADJ,GET_OSD_LED());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;

        case _EXIT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_SETUP_MUTE);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_LED()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);
        
            break;

        default:
            break;
    }
}
void MenuSetupVolumeAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			OsdDispSliderAndNumber(_MENU_SETUP_VOLUME,GET_OSD_VOLUME()); 
			SET_OSD_STATE(_MENU_SETUP_VOLUME);

            break;

        case _RIGHT_KEY_MESSAGE:
			    OsdDispSliderAndNumber(_MENU_SETUP_VOLUME_ADJ,GET_OSD_VOLUME()); 
            break;

        case _LEFT_KEY_MESSAGE:
           
			    OsdDispSliderAndNumber(_MENU_SETUP_VOLUME_ADJ,GET_OSD_VOLUME()); 
            break;

        case _EXIT_KEY_MESSAGE:
        			OsdDispSliderAndNumber(_MENU_SETUP_VOLUME,GET_OSD_VOLUME()); 
			SET_OSD_STATE(_MENU_SETUP_VOLUME);

            break;

        default:
            break;
    }
}


void MenuOthersRatio(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_OTHERS_RATIO_ADJ);

			OSDFunctionAdj(_MENU_OTHERS_RATIO_ADJ,GET_OSD_ASPECT_RATIO_TYPE());

            break;

        case _RIGHT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OTHERS_OD);
        		
		      UpdateSubInterface3(3);
		      Update3thInterface(5,3);         
		      break;

        case _LEFT_KEY_MESSAGE:
                                                SET_OSD_STATE(_MENU_OTHERS_LOWBLUE);
        		
		      UpdateSubInterface3(2);
		      Update3thInterface(5,2);          

            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_OTHER);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

        
            break;

        default:
            break;
    }
}

void MenuOthersLowBlue(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_OTHERS_LOWBLUE_ADJ);

			OSDFunctionAdj(_MENU_OTHERS_LOWBLUE_ADJ,GET_OSD_LOW_BLUE());

            break;

        case _RIGHT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OTHERS_RATIO);
        		
		      UpdateSubInterface3(1);
		      Update3thInterface(5,1);  
		      break;

        case _LEFT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OTHERS_OD);
        		
		      UpdateSubInterface3(3);
		      Update3thInterface(5,3);  
            break;

        case _EXIT_KEY_MESSAGE:

                                                                      SET_OSD_STATE(_MENU_OTHER);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

            break;

        default:
            break;
    }
}

void MenuOthersOD(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_OTHERS_OD_ADJ);

			OSDFunctionAdj(_MENU_OTHERS_OD_ADJ,GET_OSD_OD_STATUS());

            break;

        case _RIGHT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OTHERS_LOWBLUE);
        		
		      UpdateSubInterface3(2);
		      Update3thInterface(5,2);  
            break;

        case _LEFT_KEY_MESSAGE:
                                            SET_OSD_STATE(_MENU_OTHERS_RATIO);
        		
		      UpdateSubInterface3(1);
		      Update3thInterface(5,1);  
            break;

        case _EXIT_KEY_MESSAGE:
                                                              SET_OSD_STATE(_MENU_OTHER);

			OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
			OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);
        
            break;

        default:
            break;
    }
}


void MenuOthersFreeSync(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

            if((SysSourceGetInputPort() == _D0_INPUT_PORT )||(SysSourceGetInputPort() == _D1_INPUT_PORT ))
            {
				SET_OSD_STATE(_MENU_OTHERS_FREESYNC_ADJ);
				g_usBackupValue = GET_OSD_FREE_SYNC_STATUS();
				OSDFunctionAdj(_MENU_OTHERS_FREESYNC_ADJ,GET_OSD_FREE_SYNC_STATUS());

			}
			else
			{


			}
            break;

        case _RIGHT_KEY_MESSAGE:
               SET_OSD_STATE(_MENU_OTHER);
UpdateInterface(5);

            break;

        case _LEFT_KEY_MESSAGE:
              SET_OSD_STATE(_MENU_PICTURE);
UpdateInterface(1);


            break;

        case _EXIT_KEY_MESSAGE:
                        OsdFuncDisableOsd();
                  SET_OSD_STATE(_MENU_NONE);
            break;

        default:
            break;
    }
}

void MenuOthersRatioAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                case _EXIT_KEY_MESSAGE:

                      SET_OSD_STATE(_MENU_OTHERS_RATIO);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_ASPECT_RATIO_TYPE()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:

          SET_OSD_ASPECT_RATIO_TYPE(OsdDisplayDetOverRange(GET_OSD_ASPECT_RATIO_TYPE(), _OSD_ASPECT_RATIO_AMOUNT, _OSD_ASPECT_RATIO_FULL, _ON));

			OSDFunctionAdj(_MENU_OTHERS_RATIO_ADJ,GET_OSD_ASPECT_RATIO_TYPE());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
                                    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);



           

            break;


        default:
            break;
    }
}

void MenuOthersLowBlueAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        case _EXIT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_OTHERS_LOWBLUE);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_LOW_BLUE()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
         SET_OSD_LOW_BLUE(OsdDisplayDetOverRange(GET_OSD_LOW_BLUE(), _LEVEL_STRONGEST , _LEVEL_OFF, _ON));

			OSDFunctionAdj(_MENU_OTHERS_LOWBLUE_ADJ,GET_OSD_LOW_BLUE());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

           

            break;


        default:
            break;
    }
}


void MenuOthersODAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
        case _EXIT_KEY_MESSAGE:
                      SET_OSD_STATE(_MENU_OTHERS_OD);

      OsdFuncChangeColor1Bit(ROW(FONT1_ROW+GET_OSD_OD_STATUS()*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);

            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:

        SET_OSD_OD_STATUS(OsdDisplayDetOverRange(GET_OSD_OD_STATUS(), _ON , _OFF, _ON));

			OSDFunctionAdj(_MENU_OTHERS_OD_ADJ,GET_OSD_OD_STATUS());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);


           


            break;

        default:
            break;
    }
}

void MenuOthersFreeSyncAdj(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            if(g_usBackupValue != GET_OSD_FREE_SYNC_STATUS())
            {
                SET_OSD_FREE_SYNC_STATUS(g_usBackupValue);
                ScalerSyncSetFREESYNCSupport(GET_OSD_FREE_SYNC_STATUS());
            #if(_EMBEDDED_EDID_SUPPORT == _ON)
            		UserCommonInterfaceLoadEmbeddedEdidData();
            #endif
 		
             #if(_HDMI_SUPPORT == _ON)
             			if(SysSourceGetSourceType() == _SOURCE_HDMI)
             				ScalerSyncTMDSEdidSwitch(SysSourceGetInputPort());
             #endif
#if( _D1_INPUT_PORT_TYPE ==  _D1_HDMI_PORT)
					PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
					ScalerTimerDelayXms(500);
					PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
#endif
             							
             #if(_DP_SUPPORT == _ON)
             			if(SysSourceGetSourceType() == _SOURCE_DP)
             			{
             				ScalerDpEdidSwitch(SysSourceGetInputPort());
             				SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
             			}
             #endif
							
		SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            }

            break;

        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
         g_usBackupValue =(OsdDisplayDetOverRange(g_usBackupValue, _ON , _OFF, _ON));

			OSDFunctionAdj(_MENU_OTHERS_FREESYNC_ADJ,g_usBackupValue);

            break;

        case _EXIT_KEY_MESSAGE:
                SET_OSD_STATE(_MENU_FREESYNC);
			if(GET_OSD_FREE_SYNC_STATUS() == g_usBackupValue )
			{
			    OsdFuncChangeColor1Bit(ROW(FONT1_ROW+g_usBackupValue*2), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

			}
			else
			{
				OsdFuncChangeColor1Bit(ROW(FONT1_ROW+g_usBackupValue*2), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);
						OsdFuncClearOsd(FONT1_ROW+g_usBackupValue*2, FONT2_COL+12, WIDTH(1), HEIGHT(1));  

	       	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_FREE_SYNC_STATUS()*2), COL(FONT2_COL+12), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));
			}
        
            break;

        default:
            break;
    }
}



void MenuHotKeyDdcci(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:


            break;

        case _RIGHT_KEY_MESSAGE:

            break;

        case _LEFT_KEY_MESSAGE:
           

            break;

        case _EXIT_KEY_MESSAGE:
            break;

        default:
            break;
    }
}

void MenuHotKeySource(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:


            break;

        case _RIGHT_KEY_MESSAGE:

            break;

        case _LEFT_KEY_MESSAGE:
           

            break;

        case _EXIT_KEY_MESSAGE:
            break;

        default:
            break;
    }
}


void MenuHotKeyDpOption(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:


            break;

        case _RIGHT_KEY_MESSAGE:

            break;

        case _LEFT_KEY_MESSAGE:
           

            break;

        case _EXIT_KEY_MESSAGE:
            break;

        default:
            break;
    }
}


void MenuPanelUniformityMsgAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:


            break;

        case _RIGHT_KEY_MESSAGE:

            break;

        case _LEFT_KEY_MESSAGE:
           

            break;

        case _EXIT_KEY_MESSAGE:
            break;

        default:
            break;
    }
}

void MenuLeftKeyTimerAdjust(void)
{

	BYTE ucForeground1=0;
	BYTE ucBackground1=0;
	BYTE ucForeground2=0;
	BYTE ucBackground2=0;
	BYTE ucForeground3=0;
	BYTE ucBackground3=0;
	BYTE ucForeground4=0;
	BYTE ucBackground4=0;
	BYTE ucForeground5=0;
	BYTE ucBackground5=0;
	BYTE ucForeground6=0;
	BYTE ucBackground6=0;
	BYTE ucForeground7=0;
	BYTE ucBackground7=0;
	BYTE uchpos=0;
	BYTE ucvpos=0;
	CLR_KEYREPEATENABLE();
 switch(GET_KEYMESSAGE())
 {


 case _MENU_KEY_MESSAGE:
	 SET_OSD_STATE(_OSD_DISPLEFT_TIMER_MENU_POSITION);
	//OsdDispDisableOsd();
	 //OsdDispLeftTimerMenu();
	OsdFontPut1FuncHLine(18, 8, _WHITE_EDGE_1, g_ucOsdWidth-8 ,_CP_BLUE_65, _CP_BLACK_1);
	OsdPropPutString(ROW(20), COL(8), _PFONT_PAGE_2, _STRING_GAME_TIMER_POSITION, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
	OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
	OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
	switch(GET_OSD_Left_Timer_Position())
	{
		case _LEFT_TIMER_POSITION_1:
			OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
			OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
			
			break;
		case _LEFT_TIMER_POSITION_2:
			OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
			OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
			break;
		case _LEFT_TIMER_POSITION_3:
			OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
			OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
			break;
		 default:
		 	SET_OSD_Left_Timer_Position(_LEFT_TIMER_POSITION_1);
			OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
			OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLACK_1);
			 break;
	}
	 /*ScalerOsdWindowDisable(_OSD_WINDOW_1);
	 OsdFontPut1FuncTableForm(0, 0, _EDGE_LINE,g_ucOsdWidth-2,g_ucOsdHeight-2,_CP_BG,_CP_BG,3);
	 OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
*/
 break;
	 
 case _RIGHT_KEY_MESSAGE: 
 case _LEFT_KEY_MESSAGE:
	 SET_OSD_Timer(OsdDisplayDetOverRange(GET_OSD_Timer() , _TIMER_END, _TIMER_10, _ON));

	 switch(GET_OSD_Timer())
	 {
	 case _TIMER_10:
	 
		ucForeground1=_CP_RED;
		ucForeground2=_CP_WHITE;
		ucForeground7=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_GRAY,1);	
		OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_GRAY,10);
		OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_GRAY,0);	
		OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_GRAY,0);

		 OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		 OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,2);	 
		 OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,0);
		 OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,10);
		 OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,0);	 
		 OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,0);

		 OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		 OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,9);	 
		 OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,0);
		 OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,10);
		 OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,0);	 
		 OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,0);
		 break;

	 
	case _TIMER_20:
	
		ucForeground2=_CP_RED;
		ucForeground1=_CP_WHITE;
		ucForeground3=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,1);	
		OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,0);
		
		
		
		
		
		 OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		 OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_GRAY,2);	 
		 OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_GRAY,0);
		 OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_GRAY,10);
		 OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_GRAY,0);	 
		 OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_GRAY,0);
		
		 
		 OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		 OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,3);	 
		 OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,0);
		 OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,10);
		 OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,0);	 
		 OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,0);
		
		break;
	case _TIMER_30:
		ucForeground3=_CP_RED;
		ucForeground2=_CP_WHITE;
		ucForeground4=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,2); 	
		OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLACK_1,0);
		
		
		OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_GRAY,3); 	
		OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_GRAY,10);
		OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_GRAY,0);	
		OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_GRAY,0);
		
		
		OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,4); 	
		OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,0);
		
		break;
	case _TIMER_40:
		ucForeground4=_CP_RED;
		ucForeground3=_CP_WHITE;
		ucForeground5=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,3); 	
		OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLACK_1,0);
		
		
		OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_GRAY,4); 	
		OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_GRAY,10);
		OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_GRAY,0);	
		OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_GRAY,0);
		
		
		OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,5);	
		OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,0);
		
		
		break;
	case _TIMER_50:
		ucForeground5=_CP_RED;
		ucForeground4=_CP_WHITE;
		ucForeground6=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,4); 	
		OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLACK_1,0);
		
		
		OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_GRAY,5);	
		OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_GRAY,10);
		OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_GRAY,0);	
		OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_GRAY,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,6);	
		OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,0);
		
	
	break;
	case _TIMER_60:
		ucForeground6=_CP_RED;
		ucForeground5=_CP_WHITE;
		ucForeground7=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,5);	
		OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLACK_1,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_GRAY,6);	
		OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_GRAY,10);
		OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_GRAY,0);	
		OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_GRAY,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,9);	
		OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLACK_1,0);
		break;
	case _TIMER_90:
		ucForeground7=_CP_RED;
		ucForeground6=_CP_WHITE;
		ucForeground1=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,6);	
		OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLACK_1,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_GRAY,9);	
		OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_GRAY,0);
		OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_GRAY,10);
		OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_GRAY,0);	
		OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_GRAY,0);

		OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,1);	
		OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,0);
		OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,10);
		OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,0);	
		OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLACK_1,0);
		break;
		default:
			break;
	 	}

	 break;



 
 case _EXIT_KEY_MESSAGE:
 	
	//OsdDispDisableOsd();
	g_usTime_OSD_OnOff1=_OFF;
	g_MiaoZhun_OnOff1=_OFF;
	OsdFuncSetOsdItemFlag();
	OsdDispLeftMenu();
 break;
	 
	 default:
		 break; 				  
 }
}



 void MenuHotkeyECOAdjust(void)
 {
 
   switch(GET_KEYMESSAGE())
	 {
		 case _MENU_KEY_MESSAGE:
			 OsdDispDisableOsd();
		 break;
			 
		 case _RIGHT_KEY_MESSAGE:	
		 case _LEFT_KEY_MESSAGE:
//_PICTURE_STANDARD			 
				 SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT() , _PICTURE_RTS, _PICTURE_STANDARD, _ON));
		 
		 switch(GET_OSD_COLOR_EFFECT())
		 {
			 case _PICTURE_STANDARD:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_STANDARD, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				 break;
			 case _PICTURE_GAME:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_MOVE, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());	 
				 break;
			 case _PICTURE_MOVIE:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PHOTO, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());	 
				 break;
			 case _PICTURE_PHOTO:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_GAME, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				 break;  
			case _PICTURE_USER:
				OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_FPS, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				break;
			case _PICTURE_FPS:
				OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_RTS, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				break;
			case _PICTURE_RTS:
				OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_USER, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				break;
			  default:
				  break;
		 }
		   
     #if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))
			  UserAdjustColorEffectMode();
     #endif
			 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
		 break;
 
		 case _EXIT_KEY_MESSAGE:
			 OsdDispDisableOsd();
		 break;
 
		 default:
			 break; 				  
	 }
 
 }

void OsdDispLeftTimerMenuAdjust(void)
	{
		BYTE ucTest = 0;
	
		g_ucFontPointer0 = _OSD_PAGE_0_START;
		g_ucFontPointer1 = _OSD_PAGE_1_START;
		g_ucFontPointer2 = _OSD_PAGE_2_START;
	
		if(ucTest == 1)
		{
		 //   ScalerDDomainPatternGenAdjustColor(0, 0, 0);
	
	
		  //  OSTARFactoryPanelUsedTimer();
		  //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
			
	
		   ScalerOsdDataPort(0);
	
	//#if(_DIGITAL_PORT_SUPPORT == _ON)
		   // ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
	//#endif
	
		}
	
		OsdFuncDisableOsd();
	
		OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_WIDTH), HEIGHT(_OSD_LEFT_KEY_HEIGHT), COLOR(_CP_BLACK_1, _CP_BG));
	
	//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
		ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_LEFT_KEY_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
	
		OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
		OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
	
		// Adjust Color Palette
		OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
	
		// Load Font & Icon
		OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
	
		OsdFontVLCLoadFont(_FONT1_GLOBAL);
		//OsdFontVLCLoadFont(_FONT2_ICON_MENU);
		 OsdFontVLCLoadFont(_LEFT_MENU_TIME_ICON);
		 OsdFontVLCLoadFont(_LEFT_MENU_AIM_ICON);
		 OsdFontVLCLoadFont(_FOUR_CORNER);
		 OsdFontVLCLoadFont(_LEFT_MENU_NUMBER_ICON);
	   // Background window
	   //20140210 Abel Modify
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
		if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
		{
  
			OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
		 }
		else
#endif
    {
	OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BG );
	
	OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_1, _STRING_GAME_TIME, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_TIMER);
		
	
    }
	{
	
	  
		  if(GET_OSD_Timer()==_TIMER_10)
			{
			  OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,1);	  
			  OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	
			  OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_20)
			{
			  OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,2);   
			  OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	  
			  OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_30)
			{
			  OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,3);   
			  OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	  
			  OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_40)
			{
			  OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,4);   
			  OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	  
			  OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_50)
			{
			  OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,5);	
			  OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	
			  OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_60)
			{
			  OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,6);	  
			  OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	
			  OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_90)
			{
			  OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,9);	  
			  OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			  OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,10);
			  OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);	
			  OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_GRAY,0);
			}
					  
	  }
	
		
		
	
	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
	  {
		   OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, (_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
	  }  
	else
	  {
		   OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 50, 50);
	}
	
	
	
		// Osd Enable
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdFuncEnableOsd();
	
	}







void OsdDispLeftAimMenuAdjust(void)
	{
		BYTE ucTest = 0;
	
		g_ucFontPointer0 = _OSD_PAGE_0_START;
		g_ucFontPointer1 = _OSD_PAGE_1_START;
		g_ucFontPointer2 = _OSD_PAGE_2_START;
	
		if(ucTest == 1)
		{
		 //   ScalerDDomainPatternGenAdjustColor(0, 0, 0);
	
	
		  //  OSTARFactoryPanelUsedTimer();
		  //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
			
	
		   ScalerOsdDataPort(0);
	
	//#if(_DIGITAL_PORT_SUPPORT == _ON)
		   // ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
	//#endif
	
		}
	
		OsdFuncDisableOsd();
	
		OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_WIDTH), HEIGHT(_OSD_LEFT_KEY_HEIGHT), COLOR(_CP_BLACK_1, _CP_BG));
	
	//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
		ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_LEFT_KEY_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
	
		OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
		OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
	
		// Adjust Color Palette
		OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
	
		// Load Font & Icon
		OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
	
		OsdFontVLCLoadFont(_FONT1_GLOBAL);
		//OsdFontVLCLoadFont(_FONT2_ICON_MENU);
		 OsdFontVLCLoadFont(_LEFT_MENU_TIME_ICON);
		 OsdFontVLCLoadFont(_LEFT_MENU_AIM_ICON);
		 OsdFontVLCLoadFont(_FOUR_CORNER);
		 OsdFontVLCLoadFont(_LEFT_MENU_NUMBER_ICON);
	   // Background window
	   //20140210 Abel Modify
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
		if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
		{
   
			OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
		 }
		else
#endif
		
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BG );
		
	OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_0, _STRING_GAME_CURSOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	 COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_AIM);
	{
	switch(GET_OSD_AIM())
		{
			case _AIM_1:

				OsdFontPut1FuncAimTableForm(8, 12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_GRAY);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_2:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_GRAY);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_3:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
				
				//OsdFontPut1FuncTableForm(8, 38, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_GRAY); 

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);	
				break;
			case _AIM_4:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	
				
				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_BLUE_65,_CP_BLACK_1,_CP_GRAY,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_GRAY);
				break;
				
			 default:
				 break;
		}


	}
		
	
		
		
	
	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
	  {
		   OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,(_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
	  }  
	else
	  {
		   OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,50, 50);
	}
	
	
	
		// Osd Enable
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdFuncEnableOsd();
	
	}
 void MenuHotInput(void)
 {
	 BYTE ucTest = 0;
 
	 g_ucFontPointer0 = _OSD_PAGE_0_START;
	 g_ucFontPointer1 = _OSD_PAGE_1_START;
	 g_ucFontPointer2 = _OSD_PAGE_2_START;
 
	 if(ucTest == 1)
	 {
	  //   ScalerDDomainPatternGenAdjustColor(0, 0, 0);
 
	  //   OsdDispDetOverRange(0, 0, 0, 0);
 
	   //  OSTARFactoryPanelUsedTimer();
	   //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
		 
 // 	   OsdWindowDrawingHighlight(0, 0, 0, 0, 0, 0, 0, 0);
 
		ScalerOsdDataPort(0);
 
 //#if(_DIGITAL_PORT_SUPPORT == _ON)
		// ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
 //#endif
 
	 }
 
	 OsdFuncDisableOsd();
 
	 OsdFuncApplyMap(WIDTH(_OSD_MENU_HOT_INPUT_WIDTH), HEIGHT(_OSD_MENU_HOT_INPUT_HEIGHT), COLOR(_CP_BG, _CP_BG));
 
 //20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	 ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MENU_HOT_INPUT_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
 
	 //OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	 OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
 
	 // Adjust Color Palette
	 OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
	 
	 OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);	
	 OsdFuncTransparency(0); 
	 // Load Font & Icon
	 OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
 
	 OsdFontVLCLoadFont(_FONT1_GLOBAL);
	 //OsdFontVLCLoadFont(_FONT2_ICON_MENU);
	  OsdFontVLCLoadFont(_LEFT_MENU_TIME_ICON);
	  OsdFontVLCLoadFont(_LEFT_MENU_AIM_ICON);
	  OsdFontVLCLoadFont(_FOUR_CORNER);
 
	// Background window
	//20140210 Abel Modify
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
	 if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
	 {
   
		 OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
		 OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
	  }
	 else
#endif
	 {
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
		{
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(1), WIDTH(g_ucOsdWidth-3), HEIGHT((g_ucOsdHeight-1)), _CP_BLACK_1 );
		}	 
		else 
		{
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(1), WIDTH(g_ucOsdWidth-3), HEIGHT((g_ucOsdHeight-1)), _CP_BLACK_1 );
		}
	OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLACK_1,_CP_BG,_QUADRANGLE_WINDOW_0);

	COsdShowPageInputText();


	//OsdPropPutString(ROW(2), COL(3), _PFONT_PAGE_0, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	 
	//OsdPropPutString(ROW(2), COL(18), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
	//OsdPropPutString(ROW(2), COL(26), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
	//OsdPropPutString(ROW(2), COL(37), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	
//OsdPropPutStringCenter
	  //OsdPropPutStringCenter(ROW(3), COL(37), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	  
	//  OsdPropPutStringCenter(ROW(2), COL(1), WIDTH(11), _PFONT_PAGE_0, _STRING_AUTO_SELECT, _CP_BLACK_1 , _ENGLISH);
	 // OsdPropPutStringCenter(ROW(2), COL(12), WIDTH(11), _PFONT_PAGE_0, _STRING_SETUP_DP, _CP_BLACK_1 , _ENGLISH);
	 // OsdPropPutStringCenter(ROW(2), COL(23), WIDTH(11), _PFONT_PAGE_0, _STRING_SETUP_HDMI, _CP_BLACK_1 , _ENGLISH);
	 // OsdPropPutStringCenter(ROW(2), COL(34), WIDTH(11), _PFONT_PAGE_0, _STRING_SETUP_HDMI, _CP_BLACK_1 , _ESPANA);
	OsdFuncSetOsdItemFlag();

	  g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
	 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(2), COL(3+(11*GET_OSD_INPUT_PORT_OSD_ITEM())), WIDTH(8), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);

   //background    
	 }
 
	 
	 
 
	 OsdDispSetPosition(_POS_PERCENT,  _OSD_POSITION_GLOBAL_A,50, 50);
 
 
 
	 // Osd Enable
	 ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	 OsdFuncEnableOsd();
 
 }
 void MenuHotInputAdjust(void)
 {
	 switch(GET_KEYMESSAGE())
	 {
		 case _MENU_KEY_MESSAGE:
  if(GET_OSD_DP_VERSION_HOTKEY_DISP() == _OFF)
			 {
 
 
				 if(g_usBackupValue != GET_OSD_INPUT_PORT_OSD_ITEM())
				 {		 
 
					 switch(GET_OSD_INPUT_PORT_OSD_ITEM())
					 {
						 case _OSD_INPUT_AUTO: // auto
							 SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
							 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
							 if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
							 {
								 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
								 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
							 }	   
#if(_DP_MST_SUPPORT == _ON)
							 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
							 RTDNVRamSaveOSDData();  
#endif                            
							 break;
#if(_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) 
			 case _OSD_INPUT_A0: // A0
						 SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_A0);
						 SET_FORCE_POW_SAV_STATUS(_FALSE);
						 SysSourceSwitchInputPort(_A0_INPUT_PORT);
 
		   
							 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);	 
 
							 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
								(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
							 {
								 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
								 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
								 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
							 }
 
#if(_DP_MST_SUPPORT == _ON)
							 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
							 RTDNVRamSaveOSDData();  
#endif                            
 
									  
							 break;
#endif
 
#if(_D0_INPUT_PORT_TYPE !=_D0_NO_PORT) 
				 case _OSD_INPUT_D0: // D0
					 SET_FORCE_POW_SAV_STATUS(_FALSE);
					 SysSourceSwitchInputPort(_D0_INPUT_PORT);
					 
					 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
	 
					 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
						(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
					 {
						 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
						 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
						 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
					 }		
	 
#if(_DP_MST_SUPPORT == _ON)
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
					 if(UserInterfaceGetDpMSTCapablePort() == _DP_MST_RX0_PORT)
					 {
						 ScalerDpRxMstRx0Rx1switch(_DP_MST_RX0_PORT);
						 RTDNVRamSaveOSDData();					   
					 }
#else
					 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
					RTDNVRamSaveOSDData();
#endif
#endif
								 break;
	 
#endif
 
 
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
			  case _OSD_INPUT_D1:	//D1

				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D1_INPUT_PORT);
				 
				 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
				 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				 {
					 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				 }		
 
#if(_DP_MST_SUPPORT == _ON)
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
				 if(UserInterfaceGetDpMSTCapablePort() == _DP_MST_RX0_PORT)
				 {
					 ScalerDpRxMstRx0Rx1switch(_DP_MST_RX0_PORT);
					 RTDNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 RTDNVRamSaveOSDData();
#endif
#endif
						  break;
 
#endif
 
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
		   case _OSD_INPUT_D2:	//D2
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D2_INPUT_PORT);
				 
				 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
				 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				 {
					 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				 }		
 
#if(_DP_MST_SUPPORT == _ON)
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
				 if(UserInterfaceGetDpMSTCapablePort() == _DP_MST_RX0_PORT)
				 {
					 ScalerDpRxMstRx0Rx1switch(_DP_MST_RX0_PORT);
					 RTDNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 RTDNVRamSaveOSDData();
#endif
#endif
							 break;
 
#endif
 
 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
			  case _OSD_INPUT_D3:	//D3
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D3_INPUT_PORT);
				 
				 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
				 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				 {
					 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				 }		
 
#if(_DP_MST_SUPPORT == _ON)
 
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 RTDNVRamSaveOSDData();
#endif
							 break;
#endif
 
 
 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
						 case _OSD_INPUT_D4:	//D4
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D4_INPUT_PORT);
				 
				 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
				 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				 {
					 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				 }		
 
#if(_DP_MST_SUPPORT == _ON)
 
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 RTDNVRamSaveOSDData();
#endif
									
							 break;
 
#endif
 
 
 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
						 case _OSD_INPUT_D5:	//D5
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D5_INPUT_PORT);
				 
				 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
				 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				 {
					 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				 }		
 
#if(_DP_MST_SUPPORT == _ON)
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 RTDNVRamSaveOSDData();
#endif
 
 
							 break;
#endif
 
 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
						 case _OSD_INPUT_D6:	//D6
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D6_INPUT_PORT);
				 
				 SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
 
				 if((UserCommonNVRamGetSystemData(_SEARCH_PORT) != SysSourceGetInputPort()) ||
					(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType()))
				 {
					 UserCommonNVRamSetSystemData(_SEARCH_PORT, SysSourceGetInputPort());
					 UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
					 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
				 }		
 
#if(_DP_MST_SUPPORT == _ON)
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
				 if(UserInterfaceGetDpMSTCapablePort() == _DP_MST_RX0_PORT)
				 {
					 ScalerDpRxMstRx0Rx1switch(_DP_MST_RX0_PORT);
					 RTDNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 RTDNVRamSaveOSDData();
#endif
#endif
 
							 break;
#endif
 
						 default:
							 break;
					 }
				 }		
				 else
				 {
					 if(SysModeGetModeState() == _MODE_STATUS_NOSUPPORT)
					 {
						 SysPowerSetTargetPowerStatus(_POWER_STATUS_NOSUPPORT_SAVING);
					 }
					 else if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)||(SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
					 {
						 ScalerTimerReactiveTimerEvent(SEC(0), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
					 }
					 else
					 {
						 OsdDispDisableOsd();
					 }
				 } 
				 SET_OSD_STATE(_MENU_NONE);
			 }
 
			 break;
			 
		 case _RIGHT_KEY_MESSAGE: 
		 	
			CLR_KEYREPEATENABLE();
			 g_usItemNum=GET_OSD_INPUT_PORT_OSD_ITEM();
		 if(g_usItemNum==(_OSD_INPUT_AMOUNT-1))
			 {
			 g_usItemNum=0;
			 }
		 else 
			 {
				  g_usItemNum++;
			 }
 
		 SET_OSD_INPUT_PORT_OSD_ITEM(g_usItemNum);
		 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(2), COL(3+(11*GET_OSD_INPUT_PORT_OSD_ITEM())), WIDTH(8), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			 if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)||(SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
			 {
				 ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);			
			 }	 
			 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
 
 
			 break;
 
		 case _LEFT_KEY_MESSAGE: 
			 CLR_KEYREPEATENABLE();
		 g_usItemNum=GET_OSD_INPUT_PORT_OSD_ITEM();
		 if(g_usItemNum==0)
			 {
			 g_usItemNum=(_OSD_INPUT_AMOUNT-1);
			 }
		 else 
					{
					g_usItemNum--;
			 }
 
		 SET_OSD_INPUT_PORT_OSD_ITEM(g_usItemNum);
		 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(2), COL(3+(11*GET_OSD_INPUT_PORT_OSD_ITEM())), WIDTH(8), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			 if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)||(SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
			 {
				 ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);			
			 }	 
			 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
 
			 break;
 
		 case _EXIT_KEY_MESSAGE:
			 if(g_usBackupValue != GET_OSD_INPUT_PORT_OSD_ITEM())
			 {
				 SET_OSD_INPUT_PORT_OSD_ITEM(g_usBackupValue);
				 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			 }
 
			 if(SysModeGetModeState() == _MODE_STATUS_NOSUPPORT)
			 {
				 SysPowerSetTargetPowerStatus(_POWER_STATUS_NOSUPPORT_SAVING);
			 }
			 else if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)||(SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
			 {
				 ScalerTimerReactiveTimerEvent(SEC(0), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
			 }
			 else
			 {
				 SET_OSD_STATE(_MENU_NONE);
				 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				 //COsdShowChooseSetupText(_STRING_SETUP_INPUT);
				 OsdDispDisableOsd();
			 }			  
 
			 break;
 
		 default:
			 break; 				  
	 }
 }

code void (*OperationTable[])(void) =
{
    MenuNone,



    // main
	MenuPicture,
	MenuColor,
	MenuOsd,
	MenuSetup,
	MenuOthers,
    
    MenuPictureBacklight,
    MenuPictureContrast,
    MenuPictureECO,
    MenuPictureMainSR,
	MenuPictureHDR,

    MenuPictureBacklightAdj,
    MenuPictureContrastAdj,
    MenuPictureECOAdj,
    MenuPictureMainSRAdj,
    	MenuPictureHDRAdj,

    MenuColorTemp,
    MenuColorR,
    MenuColorG,
    MenuColorB,

    MenuColorTempAdj,
    MenuColorRAdj,
    MenuColorGAdj,
    MenuColorBAdj,

	MenuOsdLanguage,
	MenuOsdHPos,
	MenuOsdVPos,
	MenuOsdTrans,
	MenuOsdTime,
	
	MenuOsdLanguageAdj,
	MenuOsdHPosAdj,
	MenuOsdVPosAdj,
	MenuOsdTransAdj,
	MenuOsdTimeAdj,

	MenuSetupInput,
	MenuSetupMute,
	MenuSetupVolume,
	MenuSetupReset,

	MenuSetupInputAdj,
	MenuSetupMuteAdj,
	MenuSetupVolumeAdj,
	
	MenuOthersRatio,
	MenuOthersLowBlue,
	MenuOthersOD,
	MenuOthersFreeSync,

	MenuOthersRatioAdj,
	MenuOthersLowBlueAdj,
	MenuOthersODAdj,
	MenuOthersFreeSyncAdj,
	
    MenuLeftKeyGame,
   // MenuHotkeyGameArmAdjust,
    MenuLeftKeyGameAdjust,
    MenuLeftKeyTimer,
    MenuLeftKeyTimerAdjust,
    OsdDispLeftTimerMenu,
    OsdDispLeftTimerMenuAdjust,
    OsdDispLeftTimerMenuPosition,
	    MenuHotkeyECOAdjust,
	MenuHotInputAdjust,

    // ddcci
    MenuHotKeyDdcci,

    // hotkey source
    MenuHotKeySource,

    // hotkey dp version
    MenuHotKeyDpOption,

    // ask turn off/on panel uniformity msg
    MenuPanelUniformityMsgAdjust,
        MenuFactory,
OSD_NULL,
};

#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
