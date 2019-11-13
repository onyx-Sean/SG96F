#if(_OSD_TYPE == _OSTAR_2014_OSD)
StructOsdInfo g_stOsdInfo = {0};

WORD g_usAdjustValue = 0; //Eli test
WORD g_usBackupValue = 0; //Eli test
BYTE g_usItemNum = 0;
#if(_USE_TIME_SUPPORT == _ON)  
BYTE g_usTimeTabe = 0;
bit g_usTime_OSD_OnOff = _ON;
WORD g_usTimeUse = 0;
#endif
BYTE g_usTimeTabe1 = 0;
/////////////
bit g_usTime_OSD_OnOff1 = _OFF;
///////////
 #if(_MIAOZHUN_FUNCTION== _ON)
BYTE g_MiaoZhun = 0;
bit g_MiaoZhun_OnOff = _ON;
 #endif
 ///////////////
BYTE g_MiaoZhun1 = 0;
bit g_MiaoZhun_OnOff1 = _OFF;
////////////
BYTE g_ucLogoTimerCounter = 0;
 

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserOsdHandler(void);
void OSTAROsdSystemFlowProc(void);
void OSTAROsdEventMsgProc(void);
code void (*OperationTable[])(void);
extern ScalerDpRx0HotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
extern ScalerDpRx1HotPlugEvent(EnumDpHotPlugAssertType enumHpdType);

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
    OSTAROsdSystemFlowProc();
    OSTAROsdEventMsgProc();
}

//--------------------------------------------------
// Description  : OSD system flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OSTAROsdSystemFlowProc(void)
{
#if((_AUDIO_SUPPORT == _ON) && (_AUDIO_HEADPHONE_SUPPORT == _ON))
		OsdAudioHeadphoneScan();
#endif
    switch(SysModeGetModeState())
    {
        case _MODE_STATUS_POWER_OFF:

            if(SysModeGetModeStateChange() == _TRUE)
            {
                SET_FORCE_POW_SAV_STATUS(_FALSE);
            }

            break;

        case _MODE_STATUS_INITIAL:

            if((SysModeGetModeStateChange() == _TRUE)&&(GET_OSD_FACTORY_BURNIN_STATUS() == _OFF))
            {
            #if(_LOGO_ON_OFF == _ON)
                OsdDispShowLogo();
                UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE_OSD_LOGO);
	     #endif
            }

            break;

        case _MODE_STATUS_SEARCH:

            if(SysModeGetModeStateChange()== _TRUE)
            {
#if(_FREEZE_SUPPORT == _ON)
                if(GET_OSD_FREEZE_STATUS() == _ON)
                {
                    SET_OSD_FREEZE_STATUS(_OFF);
                }
#endif
                UserInterfaceKeyPadLedControl(_LED_POWER_SEARCH);
            }

            break;

        case _MODE_STATUS_DISPLAY_SETTING:

            break;

        case _MODE_STATUS_ACTIVE:
	  
            if(SysModeGetModeStateChange()== _TRUE)
            {
                UserInterfaceKeyPadLedControl(_LED_POWER_ACTIVE);
            }

#if(_DCR_SUPPORT == _ON)
            if(GET_OSD_DCR_STATUS() == _ON)
            {
                UserCommonAdjustDCR();
            }
#endif
            break;

        case _MODE_STATUS_NOSUPPORT:

            if(SysModeGetModeStateChange()== _TRUE)
            {
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SHOW_NOSUPPORT_MSG);
                UserInterfaceKeyPadLedControl(_LED_POWER_NOSUPPORT);
            }

            break;

        case _MODE_STATUS_NOSIGNAL:

            if(SysModeGetModeStateChange()== _TRUE)
            {
// Lee add for factory burnin model   20141011 start//  

            if((GET_OSD_FACTORY_BURNIN_STATUS()==_ON))
            {

                ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_SHOW_BURNIN);
            }
                 else   
// Lee add for factory burnin model   20141011 end//        
                    
            {  
                
                        if(SysSourceGetCableDetect(UserCommonNVRamGetSystemData(_SEARCH_PORT)))
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

                  //  SET_OSD_EVENT_MESSAGE(_OSDEVENT_WAKE_UP_SWITCH_DDCCI_PORT_MSG);

                }
#if 0//(_DP_SUPPORT == _ON)
                else if(GET_OSD_POWER_SAVING_SHOW_DP_OPTION() == _TRUE)
                {
                    SET_OSD_POWER_SAVING_SHOW_DP_OPTION(_FALSE);
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_DP_VERSIOM_MSG);
                }
#endif
            }
#if(_USER_FUNCTION_LED_FLASH == _ON)
        UserInterfaceKeyPadLedControl(_LED_TYPE_FLASH);// Lee add for powersaving led flash 20141011//              
#endif

            break;

        case _MODE_STATUS_FACTORY:

            break;

        default:

            break;
    }

    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
    {
        // hot key
        if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) ||
           (SysModeGetModeState() == _MODE_STATUS_POWER_SAVING))
        {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D1_INPUT_PORT_TYPE == _D1_DP_PORT))
            if((GET_OSD_STATE() != _MENU_NONE) && ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)) \
                )
#else
            if((GET_OSD_STATE() != _MENU_NONE) && ((GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE) || (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)))
#endif
            {
                SET_KEYREPEATENABLE();
            }
        }

      if(GET_OSD_IN_FACTORY_MENU_STATUS() == _TRUE && GET_OSD_STATE() >_MAIN_MENU_STATE_END)
        {
            OSTARFactoryMenuOperation();
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
/*
            if((GET_OSD_STATE() >= _MENU_PICTURE) && (GET_OSD_STATE() <= _MENU_COLOR_PCM_SOFT_PROFT_ADJUST))
            {
                OsdDispMainMenuKeyInfo(GET_KEYMESSAGE(), _OSD_HIGHLIGHT);
            }
*/
        if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSUPPORT) ||
           (SysModeGetModeState() == _MODE_STATUS_NOSIGNAL) ||
           (SysModeGetModeState() == _MODE_STATUS_POWER_SAVING))
        	{
                    (*OperationTable[GET_OSD_STATE()])();
        	}			
/*
            if(GET_OSD_IN_FACTORY_MENU_STATUS() == _FALSE)
            {
                if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                {
                    if(GET_OSD_TIME_OUT() <= 10)
                    {
                        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
                    }
                    else
                    {
                        ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
                    }
                }
            }
*/


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

			if(g_MiaoZhun_OnOff1 == _ON)
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
            }
			if(g_usTime_OSD_OnOff1 == _ON)
            {
                ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
            }
        }
    }
else //    if(GET_KEYMESSAGE() < _KEY_AMOUNT)
	{

            if(GET_KEYMESSAGE() == _LEFT_RIGHT_KEY_MESSAGE)
	    {
             	SET_OSD_FactoryIn_TYPE(_ON);
                SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
               SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
               OSTARFactoryMainMenu();
               OsdDispEepromWriteProtectOff(); 
	     } 
	}
}

//--------------------------------------------------
// Description  : OSD event message processing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OSTAROsdEventMsgProc(void)
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
            ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);
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

  

        case _OSDEVENT_SHOW_POWER_SAVING_EVENT_MSG:
            OsdDispDisableOsd();
            OsdDispOsdMessage(_OSD_DISP_POWER_SAVING_MSG);
            UserCommonInterfacePanelPowerAction(_BACKLIGHT_ON);
            ScalerTimerActiveTimerEvent(SEC(2), _USER_TIMER_EVENT_GO_TO_POWER_SAVING);
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
                OsdDispOsdMessage(_OSD_DISP_INPUT_SIGNAL_MSG);
                ScalerTimerActiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);
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
            OSTARNVRamSaveOSDData();            
            break;

#if(_VGA_SUPPORT == _ON)
        case _OSDEVENT_SAVE_NVRAM_ADCDATA_MSG:
            if(ScalerColorGetColorSpace() == _COLOR_SPACE_RGB)
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
            OSTARNVRamSaveColorSetting(GET_COLOR_TEMP_TYPE());            
            break;

        case _OSDEVENT_SAVE_NVRAM_BRICON_MSG:
            OSTARNVRamSaveBriCon(SysSourceGetSourceType());            
            break;

        case _OSDEVENT_SAVE_NVRAM_OSDSIXCOLORDATA_MSG:
            OSTARNVRamSaveSixColorData();
            break;

#if(_DP_SUPPORT == _ON)

#endif

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
		 OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_2, _STRING_GAME_CURSOR, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
		 COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_AIM);
	 	{
			 if(GET_OSD_AIM()==_AIM_1)
			 	{
				 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);
				 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_WHITE);
				 
				 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
				 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
				 
				 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	 
				 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
				 
				 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);	 
				 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	
			 	}
			 else if(GET_OSD_AIM()==_AIM_2)
			 	{
				 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				 
				 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);	 
				 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_WHITE);
				 
				 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	 
				 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
				 
				 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);	 
				 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 	}
			 else if(GET_OSD_AIM()==_AIM_3)
			 	{
				 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				 
				 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG);
				 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				 
				 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);	 
				 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_WHITE);	 
				 
				 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	 
				 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 	}
			 else if(GET_OSD_AIM()==_AIM_4)
			 	{
				 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				 
				 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
				 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
				 
				 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	 
				 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				 
				 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);	 
				 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_WHITE);
			 	}
	 	
		 }
		 
	 
 
	 break;
	 case _LEFT_KEY_MESSAGE:
	 case _RIGHT_KEY_MESSAGE:
		 SET_OSD_STATE(_Menu_LEFTKEY_TIMER);	 
		 SET_OSD_Left_Menu_Choose(OsdDisplayDetOverRange(GET_OSD_Left_Menu_Choose() , _LEFT_MENU_END, _LEFT_AIM, _ON));
		 OsdFontPut1FuncAimTableForm(7,13, _EDGE_LINE,22,10,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		 OsdFontPut1FuncAimTableForm(7,40, _EDGE_LINE,22,10,_CP_WHITE,_CP_BLUE_65,_CP_WHITE,0);
		 OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_ORANGE_H, _CP_BG);	  
		 OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_ORANGE_H, _CP_WHITE);
		 
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

//MenuLeftKeyTimer
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
		  OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_2, _STRING_GAME_MENU, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
		  COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_TIMER);
		  //ScalerOsdWindowDisable(_OSD_WINDOW_1);
		 // OsdFontPut1FuncTableForm(0, 0, _EDGE_LINE,g_ucOsdWidth-2,g_ucOsdHeight-2,_CP_BG,_CP_BG,3);
		 // OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
		  {

		  
			  if(GET_OSD_Timer()==_TIMER_10)
			  	{
				  OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,1);	  
				  OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);   
				  OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_20)
			  	{
				  OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,2);	  
				  OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	  
				  OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_30)
			  	{
				  OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,3);	  
				  OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	  
				  OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_40)
			  	{
				  OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,4);	  
				  OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	  
				  OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_50)
			  	{
				  OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,5);   
				  OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);  
				  OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_60)
			  	{
				  OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,6);	  
				  OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);   
				  OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else if(GET_OSD_Timer()==_TIMER_90)
			  	{
				  OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,9);	  
				  OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);   
				  OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  else
			  	{
				  SET_OSD_Timer(_TIMER_10);
				  OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,1);	  
				  OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
				  OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
				  OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);   
				  OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  	}
			  
				  
		  }
		  
	  
  
	  break;
		  
	  case _RIGHT_KEY_MESSAGE: 
	  case _LEFT_KEY_MESSAGE:
	  SET_OSD_STATE(_Menu_LEFTKEY_GAME);
	  SET_OSD_Left_Menu_Choose(OsdDisplayDetOverRange(GET_OSD_Left_Menu_Choose() , _LEFT_MENU_END, _LEFT_AIM, _ON));
		  OsdFontPut1FuncAimTableForm(7,13, _EDGE_LINE,22,10,_CP_WHITE,_CP_BLUE_65,_CP_WHITE,0);
		  OsdFontPut1FuncAimTableForm(7,40, _EDGE_LINE,22,10,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		  OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_ORANGE_H, _CP_WHITE);	   
		  OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_ORANGE_H, _CP_BG);
		  
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
	
	//	OsdFontPut1FuncTableForm(7, 13, _EDGE_LINE,22 ,10,_CP_WHITE,_CP_BLUE_65,3);
	//	OsdFontPut1FuncTableForm(7, 40, _EDGE_LINE,22 ,10,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
	
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

				OsdFontPut1FuncAimTableForm(8, 12, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_WHITE,0);
				//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_WHITE);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);	
				break;
			case _AIM_2:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
				
				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_WHITE,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_WHITE);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);	
				break;
			case _AIM_3:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
				
				//OsdFontPut1FuncTableForm(8, 38, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);
				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_WHITE,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_WHITE); 

				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);	
				break;
			case _AIM_4:
				OsdFontPut1FuncAimTableForm(8,12, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,28, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);

				OsdFontPut1FuncAimTableForm(8,44, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
				OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	
				
				OsdFontPut1FuncAimTableForm(8,60, _EDGE_LINE,8,6,_CP_WHITE,_CP_BLUE_65,_CP_WHITE,0);
				OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_WHITE);
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




void MenuNone(void)
{
	BYTE uchpos=0;
	BYTE ucvpos=0;
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
	//#if(_USE_TIME_SUPPORT == _ON)
	//if(g_usTime_OSD_OnOff != 1)
	//#endif
	//{
            //if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            //{
/* #if( _MIAOZHUN_FUNCTION== _ON)
            if(g_MiaoZhun_OnOff == _ON)
              {
                OsdDispDisableOsd();
              }
	    else			
#endif*/
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
           //    if(GET_OSD_FactoryIn_TYPE() == _ON)
         //	 {
         //	          OSTARFactoryMainMenu();
         //	}
	 //   else
	   // 	{
	        //_PORTUGUESE
		SET_OSD_STATE(_MENU_PICTURE);
		OsdFuncSetOsdItemFlag();
		OsdDispMainMenu();
	    //	}
	}


	
           // }
	//}
            break;


        case _RIGHT_KEY_MESSAGE:
	
			   if(SysModeGetModeState() == _MODE_STATUS_ACTIVE && g_usTime_OSD_OnOff1!=_ON && g_MiaoZhun_OnOff1!=_ON)
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
            break;
			
		case _LEFT_KEY_MESSAGE:
			if(SysModeGetModeState() == _MODE_STATUS_ACTIVE && g_usTime_OSD_OnOff1!=_ON && g_MiaoZhun_OnOff1 !=_ON)
			{  

				
				SET_OSD_STATE(_Menu_Hotkey_ECO_Adjust);
				OsdFuncSetOsdItemFlag();
				OsdDispRightMenu();
				OsdPropPutString(ROW(5), COL(6), _PFONT_PAGE_1, _STRING_ECO, COLOR(_CP_WHITE, _CP_BG),_ENGLISH);
				switch(GET_OSD_COLOR_EFFECT())
				{
					case _PICTURE_STANDARD:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_STANDARD, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						break;
					case _PICTURE_GAME:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_MOVIE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
						break;
					case _PICTURE_MOVIE:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_PHOTO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
						break;
					case _PICTURE_PHOTO:
						OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
						OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_GAME, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
						break;
				   case _PICTURE_USER:
					   OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
					   OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_FPS, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				   case _PICTURE_FPS:
					   OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
					   OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_RTS, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				   case _PICTURE_RTS:
					   OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
					   OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_USER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
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

			
	/*#if(_USE_TIME_SUPPORT == _ON)//
	if(g_usTime_OSD_OnOff != 1)
#endif*/
	/*{
#if(GUEST_TYPE == _LANCHUANG_GUEST)
		// 背光亮度快捷
		 if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
		{
					 //bright and volume

		//			 SET_OSD_STATE(_MENU_HOTKEY_BRIGHTNESS);
				   //  OsdDispHotKeyBrightnessAndVolumeMenu();		
			//SET_OSD_STATE(_MENU_HOTKEY_BRIGHTNESS_ADJUST);
					 //OsdDispHotKeyBrightnessMenu();
		}
#else
		// 信源快捷
		CLR_KEYREPEATENABLE();

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
			else if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
			{
			/*
					SET_OSD_STATE(_MENU_HOTKEY_SOURCE);
					OsdFuncSetOsdItemFlag();
					g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
					OsdDispHotKeySourceMenu();
	*/
		  //  }
	//	#endif

	//	}*/
			break;
			
        case _EXIT_KEY_MESSAGE:
			
			if(g_usTime_OSD_OnOff1!=_ON && g_MiaoZhun_OnOff1!=_ON)
			{
                		CLR_KEYREPEATENABLE();
                
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
                			else if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                			{
                			       SET_OSD_STATE(_MENU_HOT_INPUT_ADJUST);
                				MenuHotInput();
                			}
			}
			else if(g_MiaoZhun_OnOff1==_ON && g_usTime_OSD_OnOff1 !=_ON)
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

			
/*
	#if(GUEST_TYPE == _LANCHUANG_GUEST)
    	     #if(_MIAOZHUN_FUNCTION ==  _ON)
			#if(_USE_TIME_SUPPORT == _ON)
			if(g_usTime_OSD_OnOff != 1)
			#endif
			{
               		if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
                		{
                   		// SET_OSD_STATE(_MENU_HOTKEY_MIAOZHUN_ADJUST);
                   		//OsdDispMIAOZHUNMenu();
    
                		}
			}
			#if(_USE_TIME_SUPPORT == _ON)
			else
			{

			 g_usTimeTabe = 0;
			 g_usTime_OSD_OnOff = _OFF;
			 g_usTimeUse = 0;
                	OsdDispDisableOsd();
			ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_TIMER);

			}
			#endif
              #else
		// 信源快捷
		CLR_KEYREPEATENABLE();

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
            else if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
            {
                	//SET_OSD_STATE(_MENU_HOTKEY_SOURCE);
                //	OsdFuncSetOsdItemFlag();
                //	g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
                //	OsdDispHotKeySourceMenu();
	
            }
		#endif

	 #else
            // auto adjust
		#if(_VGA_SUPPORT == _ON)
              if((SysModeGetModeState() == _MODE_STATUS_ACTIVE) && (GET_FAIL_SAFE_MODE() == _FALSE) && (SysSourceGetSourceType() == _SOURCE_VGA))
              {
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_DO_AUTO_CONFIG_MSG);
              }
		#endif
    	 #endif
*/
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

			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				COsdShowChoosePictureText(_STRING_BACKLIGHT);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else 
			{
				SET_OSD_STATE(_MENU_PICTURE_ECO);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_ECO);
			}
			
		
	

	//OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT, GET_OSD_BRIGHTNESS());
			break;

        case _RIGHT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR);
			
		OsdDispMainMenuItemSelection(_MENU_COLOR-2, _OSD_UNSELECT);	
		OsdDispMainMenuItemSelection(_MENU_COLOR-1, _OSD_SELECT);
		OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
		OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
    	COsdShowPageText(_MENU_COLOR);

            break;

        case _LEFT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OTHER);
		   OsdDispMainMenuItemSelection(_MENU_PICTURE-1, _OSD_UNSELECT);
		   OsdDispMainMenuItemSelection(_MENU_OTHER-1, _OSD_SELECT);       		//OsdDispMainMenukeyCursor(_MENU_OTHER-1,0);
		   OsdFontPut1FuncHLine(6, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);   
		   OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
		   OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
           COsdShowPageText(_MENU_OTHER);



            break;

        case _EXIT_KEY_MESSAGE:
            OsdDispDisableOsd();
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
         SET_OSD_STATE(_MENU_COLOR_TEMPERATURE);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_3);

		 ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
		 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);

		 OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		 OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
 //        OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
		 COsdShowChooseColorText(_STRING_COLORTEMP);
        break;
            
			case _RIGHT_KEY_MESSAGE:
				SET_OSD_STATE(_MENU_OSDSETTINGS);
			OsdDispMainMenuItemSelection(_MENU_OSDSETTINGS-2, _OSD_UNSELECT);
			OsdDispMainMenuItemSelection(_MENU_OSDSETTINGS-1, _OSD_SELECT);
			 OsdFontPut1FuncHLine(6, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
			 OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
			 OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);

			  COsdShowPageText(_MENU_OSDSETTINGS);
					  
			
				break;
			
			case _LEFT_KEY_MESSAGE:
				SET_OSD_STATE(_MENU_PICTURE);
				
				OsdDispMainMenuItemSelection(_MENU_COLOR-1, _OSD_UNSELECT);
				OsdDispMainMenuItemSelection(_MENU_PICTURE-1, _OSD_SELECT); 
				OsdFontPut1FuncHLine(10, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
				OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			    COsdShowPageText(_MENU_PICTURE);
				break;

        case _EXIT_KEY_MESSAGE:
            OsdDispDisableOsd();
            break;

        default:
            break;                   
    }
}

void MenuOsdSettings(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
		SET_OSD_STATE(_MENU_OSDSETTINGS_LANGUAGE);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
		COsdShowChooseOSDSetText(_STRING_OSDSET_LANGUAGE);
	//	_STRING_OSDSET_LANGUAGE
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);

	   // OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
		break;
			
			 case _RIGHT_KEY_MESSAGE:
				 SET_OSD_STATE(_MENU_SETUP);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
			OsdDispMainMenuItemSelection(_MENU_SETUP-2, _OSD_UNSELECT);
			OsdDispMainMenuItemSelection(_MENU_SETUP-1, _OSD_SELECT);
			OsdFontPut1FuncHLine(10, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
			OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			COsdShowPageText(_MENU_SETUP);
			
				 break;
			
			 case _LEFT_KEY_MESSAGE:
				 SET_OSD_STATE(_MENU_COLOR);
				 ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
			OsdDispMainMenuItemSelection(_MENU_OSDSETTINGS-1, _OSD_UNSELECT);
			OsdDispMainMenuItemSelection(_MENU_COLOR-1, _OSD_SELECT);
			OsdFontPut1FuncHLine(14, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
			OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			COsdShowPageText(_MENU_COLOR);
			
				 break;

		case _EXIT_KEY_MESSAGE:
			OsdDispDisableOsd();
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
		ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);

		ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
		OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
		COsdShowPageInputText();
		COsdShowChooseSetupText(_STRING_SETUP_INPUT);
		//COsdShowChooseSetupText(_STRING_SETUP_INPUT);
       //  OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
            break;
            
			 case _RIGHT_KEY_MESSAGE:
			 SET_OSD_STATE(_MENU_OTHER);
			
			 OsdDispMainMenuItemSelection(_MENU_OTHER-2, _OSD_UNSELECT);
			 OsdDispMainMenuItemSelection(_MENU_OTHER-1, _OSD_SELECT);
			 OsdFontPut1FuncHLine(14, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
			 OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
			 OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			 COsdShowPageText(_MENU_OTHER);
			
			
				 
				 break;
			
			 case _LEFT_KEY_MESSAGE: 
				 SET_OSD_STATE(_MENU_OSDSETTINGS);
				OsdDispMainMenuItemSelection(_MENU_SETUP-1, _OSD_UNSELECT);
			 OsdDispMainMenuItemSelection(_MENU_OSDSETTINGS-1, _OSD_SELECT);
			 OsdFontPut1FuncHLine(18, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
			 OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
			 OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			 COsdShowPageText(_MENU_OSDSETTINGS);
				 break;

        case _EXIT_KEY_MESSAGE:
            OsdDispDisableOsd();
            break;

        default:
            break;
    }
}

void MenuOther(void)
{
    switch(GET_KEYMESSAGE())
    {

			case _MENU_KEY_MESSAGE:

				
	    #if(_ULTRA_VIVID_FUNC ==_OFF)
			#if(_ASPECT_RATIO_SUPPORT == _ON)
			SET_OSD_STATE(_MENU_ADVANCE_ASPECT);	  
			OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_3_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
			#else
				#if(_OD_FUNCTION == _ON)
				SET_OSD_STATE(_MENU_ADVANCE_OD);	  
				OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_5_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
				#endif
			#endif
	   #else
				/////	
		   SET_OSD_STATE(_MENU_OTHERS_DISPLAY_SIZE);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		   OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
	   	   COsdShowChooseOtherText(_STRING_OTHER_DISPLAY_SIZE);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);

	   
//			OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),	COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
	    #endif

		break;

        case _RIGHT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_PICTURE);
		
		OsdDispMainMenuItemSelection(_MENU_OTHER-1, _OSD_UNSELECT);
		OsdDispMainMenuItemSelection(_MENU_PICTURE-1, _OSD_SELECT);
		OsdFontPut1FuncHLine(18, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdFontPut1FuncHLine(22, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
		OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
	    COsdShowPageText(_MENU_PICTURE);
            break;

        case _LEFT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP);
		OsdDispMainMenuItemSelection(_MENU_OTHER-1, _OSD_UNSELECT);
		OsdDispMainMenuItemSelection(_MENU_SETUP-1, _OSD_SELECT);
		OsdFontPut1FuncHLine(22, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdFuncClearOsd(ROW(2), COL(20), WIDTH(15), HEIGHT(22));
		OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
        COsdShowPageText(_MENU_SETUP);


            break;

        case _EXIT_KEY_MESSAGE:
            OsdDispDisableOsd();
			
            break;

        default:
            break;
    }
}

void MenuPictureBrightness(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
		  //  g_usBackupValue = GET_OSD_BACKLIGHT();
			
		   SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS_ADJUST);
		 // OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT, GET_OSD_BRIGHTNESS());
		 
		 OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_BRIGHTNESS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_PICTURE_BRIGHTNESS_ADJUST,_SLIDER_0,_OFF,0);
		 

			break;
			
		case _RIGHT_KEY_MESSAGE:
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_CONTRAST);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_CONTRAST);
			}
			else 
			{
			}

			
			break;

		case _LEFT_KEY_MESSAGE:
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_ECO);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_ECO);
			}
			else 
			{
			}
/*			
			SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_BACKLIGHT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_MAINSR, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	
			COsdShowChoosePictureText(_STRING_MAINSR);
	  */

	  //  OsdDispMainMenukeyCursor(_MENU_PICTURE_BACKLIGHT-_MENU_PICTURE_BACKLIGHT,1);
	
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_PICTURE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_BACKLIGHT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
//			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_BACKLIGHT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
	  //   OsdDispMainMenukeyCursor(_MENU_PICTURE_BACKLIGHT-_MENU_PICTURE_BACKLIGHT,1);

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
		   SET_OSD_STATE(_MENU_PICTURE_CONTRAST_ADJUST);
		   OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_CONTRAST_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_PICTURE_CONTRAST_ADJUST,_SLIDER_1,_OFF,0);
		break;
			
		case _RIGHT_KEY_MESSAGE:
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_ECO);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_ECO);
			}
			else 
			{
			}

			break;

		case _LEFT_KEY_MESSAGE:    
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_BACKLIGHT);
			}
			else 
			{
			}
	  //  OsdDispMainMenukeyCursor(_MENU_PICTURE_CONTRAST-_MENU_PICTURE_BACKLIGHT,1);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_PICTURE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			
			ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_CONTRAST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
//		OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_CONTRAST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
			
	//	  OsdDispMainMenukeyCursor(_MENU_PICTURE_CONTRAST-_MENU_PICTURE_BACKLIGHT,1);
 
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
			
			SET_OSD_STATE(_MENU_PICTURE_ECO_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_12_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_13_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	


			switch(GET_OSD_COLOR_EFFECT())
			{
				case _PICTURE_STANDARD:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_GAME:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_MOVIE:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					
					break;
				case _PICTURE_PHOTO:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					
					break;
			   case _PICTURE_USER:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
			   case _PICTURE_FPS:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_12_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   
				   break;
			   case _PICTURE_RTS:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_13_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
				 default:
					 break;
			}
		break;
		   
		case _RIGHT_KEY_MESSAGE:
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_BACKLIGHT);


/*

				SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(13), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	
				COsdShowChoosePictureText(_STRING_MAINSR);
		*/		



			}
			else 
			{
		/*		SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(13), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	
				COsdShowChoosePictureText(_STRING_MAINSR);
*/
			
			}
/*			  SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_MAINSR, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_ECO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE()); 

			COsdShowChoosePictureText(_STRING_MAINSR);
*/

 // 	  OsdDispMainMenukeyCursor(_MENU_COLOR_GAMMA-_MENU_COLOR_TEMPERATURE,1);


			break;

		case _LEFT_KEY_MESSAGE:
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				SET_OSD_STATE(_MENU_PICTURE_CONTRAST);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_CONTRAST);
			}
			else 
			{
			/*	SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(13), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_MAINSR);
			*/
			}
	//	  OsdDispMainMenukeyCursor(_MENU_COLOR_EFFECT-_MENU_COLOR_TEMPERATURE,1);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_PICTURE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_ECO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE()); 
   //	  OsdDispMainMenukeyCursor(_MENU_COLOR_EFFECT-_MENU_COLOR_TEMPERATURE,1);
			break;

		default:
			break;					 
	}
}


void MenuPictureMainSR(void)
{
/*
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_PICTURE_MAIN_SR_ADJUST);
   //    OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_CONTRAST_ADJUST-_MENU_PICTURE_BACKLIGHT_ADJUST,_MENU_PICTURE_CONTRAST_ADJUST,_SLIDER_1,_OFF,0);
		   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);   
		   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);   
		   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);   
		   OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);   
		   OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
		   switch(GET_PICTURE_MAIN_SR())
		   {
			   case _PICTURE_MAINSR_OFF:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
			   case _PICTURE_MAINSR_WEAK:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
			   case _PICTURE_MAINSR_MEDIAN:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   
				   break;
			   case _PICTURE_MAINSR_STRONG:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   
				   break;
			  case _PICTURE_MAINSR_STRONGEST:
				  ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				  OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				  break;
		   }
		break;
            
        case _RIGHT_KEY_MESSAGE:
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{

				SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(13), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChoosePictureText(_STRING_BACKLIGHT);

			}
			else 
			{
				SET_OSD_STATE(_MENU_PICTURE_ECO);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(13), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	
				COsdShowChoosePictureText(_STRING_ECO);

			
			}

            break;

        case _LEFT_KEY_MESSAGE:    
				SET_OSD_STATE(_MENU_PICTURE_ECO);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(13), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	
				COsdShowChoosePictureText(_STRING_ECO);


	  //  OsdDispMainMenukeyCursor(_MENU_PICTURE_CONTRAST-_MENU_PICTURE_BACKLIGHT,1);
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_PICTURE);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_MAINSR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
       // OsdDispMainMenukeyCursor(_MENU_PICTURE_CONTRAST-_MENU_PICTURE_BACKLIGHT,1);
 
            break;

        default:
            break;                   
    }
    */
}



 void MenuColorTemperature(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            
            SET_OSD_STATE(_MENU_COLOR_TEMPERATURE_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			if(GET_COLOR_TEMP_TYPE()==_COLOR_6500K)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_COLOR_TEMP_TYPE()==_COLOR_9300K)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
 //      OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMPERATURE_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_TEMPERATURE_ADJUST,_SLIDER_1,_OFF,1);
            break;
            
        case _RIGHT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMP_USER_R);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0); 		
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(10), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLOR_RED);
				//OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_6,_ON,0);
			}
			else 
			{
			}
            break;

        case _LEFT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMP_USER_B);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0); 		
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(10), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLOR_BLUE);
				//OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_8,_ON,0);
			}
			else 
			{
			}


            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
 			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLORTEMP, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	   
    //    OsdDispMainMenukeyCursor(_MENU_COLOR_TEMPERATURE-_MENU_COLOR_TEMPERATURE,1);
            break;

        default:
            break;                   
    }
}

void MenuColorColortempUserR(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
       SET_OSD_STATE(_MENU_COLOR_TEMP_USER_ADJUST_R);
	  // OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_0,_OFF,0);
  //     OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_0,_OFF,0);
	  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_6,_OFF,0);

	  break;
            
        case _RIGHT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMP_USER_G);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0); 		
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLOR_GREEN);
				//OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_7,_ON,0);
			}
			else 
			{
			}
            break;
        case _LEFT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMPERATURE);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLORTEMP);
			}
			else 
			{
			}
            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_COLOR);	   
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
		   OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		   OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
		   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_RED, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
        // COsdShowPageText(_MENU_COLOR);
         //    OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
        // OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_ORANGE_H, _CP_BG);
         break;

        default:
            break;                   
    }
}

void MenuColorColortempUserG(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
       SET_OSD_STATE(_MENU_COLOR_TEMP_USER_ADJUST_G);
	   OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_7,_OFF,0);
  //     OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_1,_OFF,0);
        break;
            
        case _RIGHT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMP_USER_B);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0); 		
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(10), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLOR_BLUE);
				//OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_8,_ON,0);
			}
			else 
			{
			}
            break;
        case _LEFT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMP_USER_R);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0); 		
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(10), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLOR_RED);
				//OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_0,_ON,0);
			}
			else 
			{
			}
            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_COLOR);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
		   OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		   OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
		   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_GREEN, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
       //  COsdShowPageText(_MENU_COLOR);
       //      OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
      //   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_ORANGE_H, _CP_BG);
            break;

        default:
            break;                   
    }
}


void MenuColorColortempUserB(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
       SET_OSD_STATE(_MENU_COLOR_TEMP_USER_ADJUST_B);
	   OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_8,_OFF,0);
    //   OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_2,_OFF,0);
            break;
            
        case _RIGHT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMPERATURE);
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLORTEMP);
			}
			else 
			{
			}
            break;
        case _LEFT_KEY_MESSAGE:
			if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			{
				SET_OSD_STATE(_MENU_COLOR_TEMP_USER_G);
				OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
				OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0); 		
				ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_7, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(10), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				COsdShowChooseColorText(_STRING_COLOR_GREEN);
				//OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_7,_ON,0);
			}
			else 
			{
			}
           break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_COLOR);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_7);
		   OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		   OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
		   OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_BLUE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());  	   
      //   COsdShowPageText(_MENU_COLOR);
     //        OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
      //   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_ORANGE_H, _CP_BG);
           break;

        default:
            break;                   
    }
}





void MenuOsdSettingsLanguage(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			
			SET_OSD_STATE(_MENU_OSDSETTINGS_LANGUAGE_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_12_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			OsdPropPutString(ROW(_OSD_NUMBER_13_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
			if(GET_OSD_LANGUAGE()==_ENGLISH)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_1_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_OSD_LANGUAGE()==_ESPANA)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_2_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_OSD_LANGUAGE()==_FRENCH)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_3_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_OSD_LANGUAGE()==_GERMAN)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_4_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_OSD_LANGUAGE()==_ITALIANO)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_11_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_OSD_LANGUAGE()==_KOREAN)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_12_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_12_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
			else if(GET_OSD_LANGUAGE()==_CHINESE_T)
			{
			//	OsdFontPut1ChooseIcon(_OSD_NUMBER_13_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_RED, _CP_BLUE_65);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_13_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			}
		 //OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(2), _CP_GRAY_1, _CP_ORANGE_H, _CP_BG);
		   break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_HPOS);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowChooseOSDSetText(_STRING_OSDSET_HORIZONTAL);
	   // OsdDispMainMenukeyCursor(_MENU_OTHER_LANGUAGE-_MENU_OTHER_LANGUAGE,1);
		
			break;
		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_MENU_TIME);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowChooseOSDSetText(_STRING_OSDSET_OSDTIMEOUT);
			break;

 /* 	  case _LEFT_KEY_MESSAGE:
		if(GET_OSD_FactoryIn_TYPE()==_ON)
			   {
			   SET_OSD_STATE(_MENU_FACTORY);
			OsdDispMainMenukeyCursor(_MENU_OTHER_LANGUAGE-_MENU_OTHER_LANGUAGE,1);
   
			   }
		else
			  {
				   SET_OSD_STATE(_MENU_INFORMATION);
						OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(2), _CP_ORANGE);
						
			}
			break;*/

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
		//OsdDispMainMenukeyCursor(_MENU_OTHER_LANGUAGE-_MENU_OTHER_LANGUAGE,1);
			break;

		default:
			break;					 
	}
}



void MenuOsdSettingsOsdHPos(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_HPOS_ADJUST);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_HPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_HPOS_ADJUST,_SLIDER_2,_OFF,0);
			
		break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_VPOS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	//	  OsdDispMainMenukeyCursor(_MENU_OTHER_OSD_HPOS-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_VERTICAL);
			break;

		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_LANGUAGE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowChooseOSDSetText(_STRING_OSDSET_LANGUAGE);
	 //   OsdDispMainMenukeyCursor(_MENU_OTHER_OSD_HPOS-_MENU_OTHER_LANGUAGE,1);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
  //	  OsdDispMainMenukeyCursor(_MENU_OTHER_OSD_HPOS-_MENU_OTHER_LANGUAGE,1);
			break;

		default:
			break;					 
	}
}


void MenuOsdSettingsOsdVPos(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_VPOS_ADJUST);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_VPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_VPOS_ADJUST,_SLIDER_3,_OFF,0);
			break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_TRNASPARENCY);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
//		  OsdDispMainMenukeyCursor(_MENU_OTHER_OSD_VPOS-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_TRANSPARENCY);
			break;

		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_HPOS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
   //	  OsdDispMainMenukeyCursor(_MENU_OTHER_OSD_VPOS-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_HORIZONTAL);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
//		  OsdDispMainMenukeyCursor(_MENU_OTHER_OSD_VPOS-_MENU_OTHER_LANGUAGE,1);
			break;

		default:
			break;					 
	}
}



void MenuOsdSettingsTransparency(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:

			SET_OSD_STATE(_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST,_SLIDER_4,_OFF,0);
		break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_MENU_TIME);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
  //	  OsdDispMainMenukeyCursor(_MENU_OTHER_TRNASPARENCY-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_OSDTIMEOUT);
			break;

		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_VPOS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	//	  OsdDispMainMenukeyCursor(_MENU_OTHER_TRNASPARENCY-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_VERTICAL);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
	 //   OsdDispMainMenukeyCursor(_MENU_OTHER_TRNASPARENCY-_MENU_OTHER_LANGUAGE,1);
			break;

		default:
			break;					 
	}
}



void MenuOsdSettingsMenuTime(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_MENU_TIME_ADJUST);
				g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_TIME_OUT(), _OSD_TIMEOUT_MAX, _OSD_TIMEOUT_MIN, _OSD_TIMEOUT_CENTER);
				OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_5, _SELECT);
				OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF| _SHOW_3), _SLIDER_5+3, _OSD_NUMBER_STLECT_COLOR); 
//			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_MENU_TIME_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_MENU_TIME_ADJUST,_SLIDER_5,_OFF,0);
			break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_LANGUAGE);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	//	  OsdDispMainMenukeyCursor(_MENU_OTHER_MENU_TIME-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_LANGUAGE);
			break;

		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_TRNASPARENCY);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	  //  OsdDispMainMenukeyCursor(_MENU_OTHER_MENU_TIME-_MENU_OTHER_LANGUAGE,1);
			COsdShowChooseOSDSetText(_STRING_OSDSET_TRANSPARENCY);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
	//	  OsdDispMainMenukeyCursor(_MENU_OTHER_MENU_TIME-_MENU_OTHER_LANGUAGE,1);
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
           SET_OSD_STATE(_MENU_INPUT_ADJUST);
          OsdFuncSetOsdItemFlag();
          g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
		 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_INPUT_PORT_OSD_ITEM())),	COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
		//   g_usBackupValue = SysSourceGetInputPort();
         /*
            if(SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP)
            {
        SET_OSD_STATE(_MENU_INPUT_AUTO);      
      //   OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL), WIDTH(15), HEIGHT(1), _CP_ORANGE);
        }
            else
            {

                switch(SysSourceGetInputPort())
                {
                    case _A0_INPUT_PORT:
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
            SET_OSD_STATE(_MENU_INPUT_A0_PORT);
      //  OsdDispMainMenukeyCursor(_MENU_INPUT_A0_PORT-_MENU_INPUT_AUTO,1);
#endif
                  break;
                 
                    case _D0_INPUT_PORT:
#if((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF))
                        SET_OSD_STATE(_MENU_INPUT_D0_PORT);
     //   OsdDispMainMenukeyCursor(_MENU_INPUT_D0_PORT-_MENU_INPUT_AUTO,1);
#endif
         break;

                    case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
                        SET_OSD_STATE(_MENU_INPUT_D1_PORT);
   //     OsdDispMainMenukeyCursor(_MENU_INPUT_D1_PORT-_MENU_INPUT_AUTO,1);
#endif
          break;

                    case _D2_INPUT_PORT:
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
                        SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    //    OsdDispMainMenukeyCursor(_MENU_INPUT_D2_PORT-_MENU_INPUT_AUTO,1);
#endif
         break;

                  case _D3_INPUT_PORT:
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
                        SET_OSD_STATE(_MENU_INPUT_D3_PORT);
     //   OsdDispMainMenukeyCursor(_MENU_INPUT_D3_PORT-_MENU_INPUT_AUTO,1);
#endif
         break;

                    case _D4_INPUT_PORT:
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
                        SET_OSD_STATE(_MENU_INPUT_D4_PORT);
      //  OsdDispMainMenukeyCursor(_MENU_INPUT_D4_PORT-_MENU_INPUT_AUTO,1);
#endif
        break;
                        
                    case _D5_INPUT_PORT:
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
                        SET_OSD_STATE(_MENU_INPUT_D5_PORT);
   //      OsdDispMainMenukeyCursor(_MENU_INPUT_D5_PORT-_MENU_INPUT_AUTO,1);
#endif
           break;

                    case _D6_INPUT_PORT:
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
                        SET_OSD_STATE(_MENU_INPUT_D6_PORT);
    //     OsdDispMainMenukeyCursor(_MENU_INPUT_D6_PORT-_MENU_INPUT_AUTO,1);
#endif

               break;    
                                                
                }

            }
			*/
            break;

        case _RIGHT_KEY_MESSAGE:
			 SET_OSD_STATE(_MENU_SETUP_AUDIOMUTE);
			 OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			 OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			 ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			 COsdShowChooseSetupText(_STRING_SETUP_AUDIOMUTE);

			 break;
        case _LEFT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_RESET);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			//COsdShowChooseSetupText(_STRING_SETUP_RESET);
    //    OsdDispMainMenukeyCursor(_MENU_ADVANCE-1,0);
   //      COsdShowPageText(_MENU_ADVANCE);
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
           // OsdDispDisableOsd();
            break;

        default:
            break;
    }
}

//MenuSetupAudioMute  MenuSetupAudio
void MenuSetupAudioMute(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_AUDIO_AUDIOMUTE_ON_OFF);
			  OsdFuncSetOsdItemFlag();
			  g_usBackupValue = GET_OSD_VOLUME_MUTE();
			  OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			  OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			  OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_SETUP_AUDIO);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowChooseSetupText(_STRING_SETUP_AUDIO);
			break;

		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_SETUP_INPUT);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowPageInputText();
			COsdShowChooseSetupText(_STRING_SETUP_INPUT);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_SETUP);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			break;

		default:
			break;					 
	}
}



void MenuSetupAudio(void)
{
	switch(GET_KEYMESSAGE())
	{
		case _MENU_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_AUDIO_ADJUST);
			OsdDispMainMenukeySlideAndOption(_MENU_AUDIO_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_AUDIO_ADJUST,_SLIDER_9,_OFF,0);
			
		break;
			
		case _RIGHT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_SETUP_RESET);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			
			break;

		case _LEFT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_SETUP_AUDIOMUTE);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowChooseSetupText(_STRING_SETUP_AUDIOMUTE);
			break;

		case _EXIT_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_SETUP); 
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_5);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_3);			
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
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
		   SET_OSD_STATE(_MENU_SETUP_INPUT);
		   OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
		   OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
		   COsdShowPageInputText();
		   COsdShowChooseSetupText(_STRING_SETUP_INPUT);
		   //COsdShowChooseSetupText(_STRING_SETUP_INPUT);
	//	 OsdDispMainMenukeyCursor(_MENU_OTHER_RESET-_MENU_OTHER_LANGUAGE,1);
		   break;
			
        case _LEFT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_AUDIO);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			COsdShowChooseSetupText(_STRING_SETUP_AUDIO);
			//COsdShowChooseSetupText(_STRING_SETUP_INPUT);
     //   OsdDispMainMenukeyCursor(_MENU_OTHER_RESET-_MENU_OTHER_LANGUAGE,1);
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
   //     OsdDispMainMenukeyCursor(_MENU_OTHER_RESET-_MENU_OTHER_LANGUAGE,1);
            break;

        default:
            break;                   
    }
}



 void MenuOthersDisplaySize(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_DISPLAY_SIZE_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
                OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_ASPECT_RATIO_TYPE())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				

		break;
            
        case _RIGHT_KEY_MESSAGE:

            SET_OSD_STATE(_MENU_OTHERS_LOW_BLUE_LIGHT);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_LOW_BLUE);
           // OsdDispMainMenukeyCursor(_MENU_ADVANCE_ASPECT-_MENU_ADVANCE_ULTRA_VIVID,1);

           break;

        case _LEFT_KEY_MESSAGE:

            SET_OSD_STATE(_MENU_OTHERS_FREE_SYNC);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_FREESYNC);
        // OsdDispMainMenukeyCursor(_MENU_ADVANCE_ASPECT-_MENU_ADVANCE_ULTRA_VIVID,1);

            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHER);			
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_DISPLAY_SIZE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
   //      OsdDispMainMenukeyCursor(_MENU_ADVANCE_ASPECT-_MENU_ADVANCE_ULTRA_VIVID,1);
            break;

        default:
            break;                   
    }
}



#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON) 

  void MenuOthersLowBlueLight(void)
{
 
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_LOW_BLUE_LIGHT_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
		OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_LOWBLUELIGHT_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
        break;
            
        case _RIGHT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_OD);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_OVER_DRIVER);
            break;

        case _LEFT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_DISPLAY_SIZE);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_DISPLAY_SIZE);
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHER);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_LOW_BLUE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
            break;

        default:
            break;                   
    }
}   


#endif

#if(_OD_FUNCTION == _ON) 

 void MenuOthersOverDrive(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE: 
            SET_OSD_STATE(_MENU_OTHERS_OD_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
		OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_OD_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
             break;
            
        case _RIGHT_KEY_MESSAGE:

            SET_OSD_STATE(_MENU_OTHERS_FREE_SYNC);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_FREESYNC);
         		//OsdDispMainMenukeyCursor(_MENU_ADVANCE_OD-_MENU_ADVANCE_ULTRA_VIVID,1);

             break;

        case _LEFT_KEY_MESSAGE:

			SET_OSD_STATE(_MENU_OTHERS_LOW_BLUE_LIGHT);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_LOW_BLUE);
         			//OsdDispMainMenukeyCursor(_MENU_ADVANCE_OD-_MENU_ADVANCE_ULTRA_VIVID,1);


            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHER);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_OVER_DRIVER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
    //     OsdDispMainMenukeyCursor(_MENU_ADVANCE_OD-_MENU_ADVANCE_ULTRA_VIVID,1);
            break;

        default:
            break;                   
    }
}

#endif


 void MenuOthersFreeSync(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE: 
            SET_OSD_STATE(_MENU_OTHERS_FREE_SYNC_ADJUST);
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);  
		OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_FREE_SYNC_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
             break;
            
        case _RIGHT_KEY_MESSAGE:

            SET_OSD_STATE(_MENU_OTHERS_DISPLAY_SIZE);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_DISPLAY_SIZE);
         		//OsdDispMainMenukeyCursor(_MENU_ADVANCE_OD-_MENU_ADVANCE_ULTRA_VIVID,1);


             break;

        case _LEFT_KEY_MESSAGE:

			SET_OSD_STATE(_MENU_OTHERS_OD);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
	   		COsdShowChooseOtherText(_STRING_OTHER_OVER_DRIVER);
         			//OsdDispMainMenukeyCursor(_MENU_ADVANCE_OD-_MENU_ADVANCE_ULTRA_VIVID,1);


            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHER);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(37), WIDTH(15), HEIGHT(22));
			OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_FREESYNC, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
     //    OsdDispMainMenukeyCursor(_MENU_ADVANCE_OD-_MENU_ADVANCE_ULTRA_VIVID,1);
            break;

        default:
            break;                   
    }
}



void MenuPictureBacklightAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:

        #if(_BACKLIGHT_SELECT == _BACKLIGHT_ADJ)
            //backlight is OSDUSER data
             SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        #else
            //brightness is BRICON data
             SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
        #endif
              SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS);
			  OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_BRIGHTNESS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_AUDIO_AUDIOMUTE_ON_OFF,_SLIDER_0,_ON,0);
            break;
            
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:  


  			  OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_BRIGHTNESS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_PICTURE_BRIGHTNESS_ADJUST,_SLIDER_0,_OFF,0);

#if(_BACKLIGHT_SELECT == _BACKLIGHT_ADJ)
    UserAdjustBacklight(GET_OSD_BACKLIGHT());
#else
    UserAdjustBrightness(GET_OSD_BRIGHTNESS());
#endif
            break;

        case _EXIT_KEY_MESSAGE:
      //     OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_BACKLIGHT_ADJUST-_MENU_PICTURE_BACKLIGHT_ADJUST,_MENU_PICTURE_BACKLIGHT_ADJUST,_SLIDER_0,_OFF,0);

        #if(_BACKLIGHT_SELECT == _BACKLIGHT_ADJ)
             //brightness is BRICON data
             SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        #else
            //brightness is BRICON data
             SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
        
        #endif
              SET_OSD_STATE(_MENU_PICTURE_BRIGHTNESS);
			  COsdShowChoosePictureText(_STRING_BACKLIGHT);
            break;

        default:
            break;                   
    }
}



void MenuPictureContrastAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_CONTRAST_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_PICTURE_CONTRAST_ADJUST,_SLIDER_1,_ON,0);
             SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
             SET_OSD_STATE(_MENU_PICTURE_CONTRAST);

        break;
            
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:            
			OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_CONTRAST_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_PICTURE_CONTRAST_ADJUST,_SLIDER_1,_OFF,0);
			//OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_CONTRAST_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_PICTURE_CONTRAST_ADJUST,_SLIDER_1,_OFF,0);
               UserAdjustContrast(GET_OSD_CONTRAST());
            break;

        case _EXIT_KEY_MESSAGE:
            //OsdDispMainMenukeySlideAndOption(_MENU_PICTURE_CONTRAST_ADJUST-_MENU_PICTURE_BACKLIGHT_ADJUST,_MENU_PICTURE_CONTRAST_ADJUST,_SLIDER_1,_OFF,0);
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);
            SET_OSD_STATE(_MENU_PICTURE_CONTRAST);
			COsdShowChoosePictureText(_STRING_CONTRAST);
            break;

        default:
            break;                   
    }
}


void MenuPictureECOAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                SET_OSD_STATE(_MENU_PICTURE_ECO);
				COsdShowChoosePictureText(_STRING_ECO);
				
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
              //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_EFFECT_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_EFFECT_ADJUST,_SLIDER_1,_ON,1);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;
            
        case _RIGHT_KEY_MESSAGE:   
        case _LEFT_KEY_MESSAGE:
			CLR_KEYREPEATENABLE();
					SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT() , _PICTURE_RTS, _PICTURE_STANDARD, _ON));
			//==== Show page item=======   
			if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
			{
				//OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_BACKLIGHT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				//OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_CONTRAST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
				ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_2, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
			
			}
			else 
			{
				//OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_BACKLIGHT, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());
				//OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_CONTRAST, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	
				ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_GRAY, _CP_BG);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_2, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_GRAY, _CP_BG);
			}

			
			switch(GET_OSD_COLOR_EFFECT())
			{
				case _PICTURE_STANDARD:

					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_GAME:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_MOVIE:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_PHOTO:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
			   case _PICTURE_USER:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
			   case _PICTURE_FPS:
				  ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_12_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
			   case _PICTURE_RTS:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_13_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
				 default:
					 break;
			}

#if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))
		 UserAdjustColorEffectMode();
#endif
			
/*
g_usBackupValue=GET_OSD_COLOR_EFFECT();
     //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_EFFECT_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_EFFECT_ADJUST,_SLIDER_1,_OFF,1);
#if((_DCC_FUNCTION == _ON) || (_ICM_SUPPORT == _ON) || (_SCM_SUPPORT == _ON) || (_SIX_COLOR_SUPPORT == _ON))
            UserAdjustColorEffectMode();
#endif
#if(_USER_FUNCTION_FPS1_FPS2==_ON)

if(((g_usBackupValue==_COLOREFFECT_STANDARD)||(g_usBackupValue==_COLOREFFECT_PHOTO))&&((GET_OSD_COLOR_EFFECT()==_COLOREFFECT_VIVID)||(GET_OSD_COLOR_EFFECT()==_COLOREFFECT_USER)))
{
        OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_ITEM_7, _STRING_GAMMA, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());    
         OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_4, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_6_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_GRAY, _CP_BG);
}

else if(((g_usBackupValue==_COLOREFFECT_VIVID)||(g_usBackupValue==_COLOREFFECT_USER))&&((GET_OSD_COLOR_EFFECT()==_COLOREFFECT_STANDARD)||(GET_OSD_COLOR_EFFECT()==_COLOREFFECT_PHOTO)))
{

        OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_ITEM_7, _STRING_GAMMA, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    
        OsdFuncCloseWindow(_OSD_WINDOW_4_4);
}

#endif
*/
            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_PICTURE_ECO);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   COsdShowChoosePictureText(_STRING_ECO);
     //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_EFFECT_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_EFFECT_ADJUST,_SLIDER_1,_OFF,1);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;

        default:
            break;                   
    }
}


void MenuPictureMainSRAdjust(void)
{
/*
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
                SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);

				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				COsdShowChoosePictureText(_STRING_MAINSR);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

            break;
            
        case _RIGHT_KEY_MESSAGE:   
        case _LEFT_KEY_MESSAGE:
			SET_PICTURE_MAIN_SR(OsdDisplayDetOverRange(GET_PICTURE_MAIN_SR() , _PICTURE_MAINSR_STRONGEST, _PICTURE_MAINSR_OFF, _ON));
			switch(GET_PICTURE_MAIN_SR())
			{
				case _PICTURE_MAINSR_OFF:

					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_MAINSR_WEAK:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_MAINSR_MEDIAN:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
				case _PICTURE_MAINSR_STRONG:
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
					break;
			   case _PICTURE_MAINSR_STRONGEST:
				   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				   break;
				 default:
					 break;
			}

            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_PICTURE_MAIN_SR);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   COsdShowChoosePictureText(_STRING_MAINSR);

            break;

        default:
            break;                   
    }
    */
}



void MenuColorColortempAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
           /*
           if(GET_COLOR_TEMP_TYPE() == _CT_USER)
            {
         COsdShowPageText(_MENU_COLOR_TEMP_USER_R);
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_R);
           }
        else
            {
       //   OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMPERATURE_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_TEMPERATURE_ADJUST,_SLIDER_1,_ON,1);
             }
            */
           SET_OSD_STATE(_MENU_COLOR_TEMPERATURE);
		   if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
		   {
			   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			   ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
			   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   }
		   
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   COsdShowChooseColorText(_STRING_COLORTEMP);
		   COsdShowPageText(_MENU_COLOR);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;
            
        case _RIGHT_KEY_MESSAGE:   
        case _LEFT_KEY_MESSAGE:
			CLR_KEYREPEATENABLE();
       //OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMPERATURE_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_TEMPERATURE_ADJUST,_SLIDER_1,_OFF,1);
			   SET_COLOR_TEMP_TYPE(OsdDisplayDetOverRange(GET_COLOR_TEMP_TYPE() , _COLOR_USER_DEFINE, _COLOR_6500K, _ON));
/*	   if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
	   {
		   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_COLOR_RED, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
		   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_COLOR_GREEN, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
		   OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_COLOR_BLUE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());  
	   
	   }
	   else 
	   {
		   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_COLOR_RED, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());  
		   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_COLOR_GREEN, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	 
		   OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_COLOR_BLUE, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());  
	   
	   }*/
	   if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
	   {
		   //OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_BACKLIGHT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		   //OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_CONTRAST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());  
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_4, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_2, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
	   }
	   else 
	   {
		   //OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_BACKLIGHT, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());
		   //OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_CONTRAST, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());   
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_4, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_GRAY, _CP_BG);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_2, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_GRAY, _CP_BG);
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_1_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_2), HEIGHT(1), _CP_BLACK, _CP_GRAY, _CP_BG);
	   }

	 
				   switch(GET_COLOR_TEMP_TYPE())
				   {
					   case _COLOR_6500K:
						   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
						   break;
					   case _COLOR_9300K:
						   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
						   break;
					   case _COLOR_USER_DEFINE:
						   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
						   break;
						  break;
						default:
							break;
				   }

			 //  if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			 //  {
			   
			//   }
			//   else 
			//   {
				   OSTARNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
			//   }

               UserAdjustContrast(GET_OSD_CONTRAST());

            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_COLOR_TEMPERATURE);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   COsdShowChooseColorText(_STRING_COLORTEMP);
		   COsdShowPageText(_MENU_COLOR);
     //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMPERATURE_ADJUST-_MENU_COLOR_TEMPERATURE_ADJUST,_MENU_COLOR_TEMPERATURE_ADJUST,_SLIDER_1,_OFF,1);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            
            break;

        default:
            break;                   
    }
}


void MenuColorColortempUserAdjustR(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_R);
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_6,_ON,0);
     //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_0,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
        break;
            
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_6,_OFF,0);
     //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_0,_OFF,0);
	 		UserAdjustContrast(GET_OSD_CONTRAST());
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_R);
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_R-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_R,_SLIDER_6,_ON,0);
			//COsdShowChooseColorText(_STRING_COLOR_RED);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
            break;

        default:
            break;                   
    }
}

void MenuColorColortempUserAdjustG(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_G);
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_7,_ON,0);
      // OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_1,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
            break;
            
        case _RIGHT_KEY_MESSAGE:   
        case _LEFT_KEY_MESSAGE:
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_7,_OFF,0);
      // OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_1,_OFF,0);
            UserAdjustContrast(GET_OSD_CONTRAST());
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_G);
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_G-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_G,_SLIDER_7,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
            break;

        default:
            break;                   
    }
}

void MenuColorColortempUserAdjustB(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_B);
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_8,_ON,0);
     //  OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_2,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
        break;
            
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE: 
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_8,_OFF,0);
   //    OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_COLOR_TEMP_USER_ADJUST_R,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_2,_OFF,0);
            UserAdjustContrast(GET_OSD_CONTRAST());
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_COLOR_TEMP_USER_B);
			OsdDispMainMenukeySlideAndOption(_MENU_COLOR_TEMP_USER_ADJUST_B-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_COLOR_TEMP_USER_ADJUST_B,_SLIDER_8,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
            break;

        default:
            break;                   
    }
}


void MenuOsdSettingsLanguageAdjust(void)
{
BYTE   Icon=0;
BYTE   Lengh1=0,High1=0,Lengh2=5,High2=1;
BYTE   LaungageChoose=0;
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
			SET_OSD_STATE(_MENU_OSDSETTINGS_LANGUAGE);
			for(Lengh1=1;Lengh1<6;Lengh1++)
			{
				OsdFuncClearOsd(ROW(4*Lengh1), COL(7), WIDTH(13), HEIGHT(1));
			}
			
			for(Lengh2=1;Lengh2<6;Lengh2++)
			{
				OsdFuncClearOsd(ROW(_OSD_NUMBER_1_ROW+(Lengh2-1)*3), COL(_OSD_NUMBER_1_COL), WIDTH(13), HEIGHT(1));
			}
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(54), WIDTH(15), HEIGHT(20));
			OsdFontPut1FuncTableForm(2, 54, _EDGE_LINE,16 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			COsdShowPageText(_MENU_OSDSETTINGS);
			OsdPropPutString(ROW(4), COL(7), _PFONT_PAGE_0, _STRING_PICTURE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE()); 		
			OsdPropPutString(ROW(8), COL(7), _PFONT_PAGE_0, _STRING_COLOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());			   
			OsdPropPutString(ROW(12), COL(7), _PFONT_PAGE_0, _STRING_ADVANCE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());		
			OsdPropPutString(ROW(16), COL(7), _PFONT_PAGE_0, _STRING_INPUT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());		 
			OsdPropPutString(ROW(20), COL(7), _PFONT_PAGE_0, _STRING_OTHER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL+34), _PFONT_PAGE_0, _STRING_NOW_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
			COsdShowChooseOSDSetText(_STRING_OSDSET_LANGUAGE);
			OsdDispMainMenuItemSelection(_MENU_OSDSETTINGS-1, _OSD_SELECT);

		switch(SysSourceGetInputPort())
		{
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
			case _A0_INPUT_PORT:
				break;		
#endif   

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
			case _D0_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
				break;
#endif 

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
			case _D1_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _ESPANA);  
				break;
		// return _STRING_D1_PORT;
#endif 

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
			case _D2_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
				break;
			  //  return _STRING_D2_PORT;
#endif   

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
			case _D3_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	
				break;
		//	return _STRING_D3_PORT;
#endif        
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
			case _D4_INPUT_PORT:
				 break;
		//	return _STRING_D4_PORT;
#endif  

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
			case _D5_INPUT_PORT:
				break;
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
			case _D6_INPUT_PORT:
				break;

#endif 
			default:
			break ;
			  // return _STRING_A0_PORT;
}


			
		// OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_LIGHTBLUE, _CP_BG);
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        break;
            
        case _RIGHT_KEY_MESSAGE:  
        case _LEFT_KEY_MESSAGE:
			CLR_KEYREPEATENABLE();
			LaungageChoose=OsdDisplayDetOverRange(GET_OSD_LANGUAGE() , _CHINESE_T, _ENGLISH, _ON);
			if(LaungageChoose==_ENGLISH)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_ENGLISH);
			}
			else if(LaungageChoose==_ESPANA)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_ESPANA);
			}
			else if(LaungageChoose==_FRENCH)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_FRENCH);
			}
			else if(LaungageChoose==_GERMAN)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_GERMAN);
			}
			else if(LaungageChoose==_ITALIANO)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_ITALIANO);
			}
			else if(LaungageChoose==_KOREAN)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_12_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_KOREAN);
			}
			else if(LaungageChoose==_CHINESE_T)
			{
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_13_ROW),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
				SET_OSD_LANGUAGE(_CHINESE_T);
			}
			
			//SET_OSD_LANGUAGE(_ENGLISH);
    // OsdDispMainMenukeySlideAndOption(_MENU_OTHER_LANGUAGE_ADJUST-_MENU_OTHER_LANGUAGE_ADJUST,_MENU_OTHER_LANGUAGE_ADJUST,_SLIDER_0,_OFF,1);
//	 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1, _CHOOSE_LANGUAGE, COLOR(_CP_RED, _CP_BG), _ENGLISH); 
	// OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T); 

            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_LANGUAGE);
			for(Lengh1=1;Lengh1<6;Lengh1++)
			{
				OsdFuncClearOsd(ROW(4*Lengh1), COL(7), WIDTH(13), HEIGHT(1));
			}
			
			for(Lengh2=1;Lengh2<6;Lengh2++)
			{
				OsdFuncClearOsd(ROW(_OSD_NUMBER_1_ROW+(Lengh2-1)*3), COL(_OSD_NUMBER_1_COL), WIDTH(13), HEIGHT(1));
			}
			ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
			OsdFuncClearOsd(ROW(2), COL(54), WIDTH(15), HEIGHT(20));
			OsdFontPut1FuncTableForm(2, 54, _EDGE_LINE,16 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			COsdShowPageText(_MENU_OSDSETTINGS);
			OsdPropPutString(ROW(4), COL(7), _PFONT_PAGE_0, _STRING_PICTURE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());			
			OsdPropPutString(ROW(8), COL(7), _PFONT_PAGE_0, _STRING_COLOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());			   
			OsdPropPutString(ROW(12), COL(7), _PFONT_PAGE_0, _STRING_ADVANCE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());		
			OsdPropPutString(ROW(16), COL(7), _PFONT_PAGE_0, _STRING_INPUT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());		 
			OsdPropPutString(ROW(20), COL(7), _PFONT_PAGE_0, _STRING_OTHER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
			OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL+34), _PFONT_PAGE_0, _STRING_NOW_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
			COsdShowChooseOSDSetText(_STRING_OSDSET_LANGUAGE);
			OsdDispMainMenuItemSelection(_MENU_OSDSETTINGS-1, _OSD_SELECT);

		switch(SysSourceGetInputPort())
		{
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
			case _A0_INPUT_PORT:
				break;		
#endif   

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
			case _D0_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
				break;
#endif 

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
			case _D1_INPUT_PORT:
				break;
		// return _STRING_D1_PORT;
#endif 

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
			case _D2_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
				break;
			  //  return _STRING_D2_PORT;
#endif   

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
			case _D3_INPUT_PORT:
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	
				break;
		//	return _STRING_D3_PORT;
#endif        
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
			case _D4_INPUT_PORT:
				 break;
		//	return _STRING_D4_PORT;
#endif  

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
			case _D5_INPUT_PORT:
				break;
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
			case _D6_INPUT_PORT:
				break;

#endif 
			default:
			break ;
			  // return _STRING_A0_PORT;
}
		// OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_LIGHTBLUE, _CP_BG);


		SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        break;

        default:
            break;                   
    }
}




void MenuOsdSettingsHPosAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_HPOS);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_HPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_HPOS_ADJUST,_SLIDER_2,_ON,0);
            SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;
            
        case _RIGHT_KEY_MESSAGE:                 
        case _LEFT_KEY_MESSAGE:
	     OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_HPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_HPOS_ADJUST,_SLIDER_2,_OFF,0);
              if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
                {
                     OsdDispSetPosition(_POS_PERCENT, (_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
                }  
              else
                {
                     OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());
                }
              
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_HPOS);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_HPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_HPOS_ADJUST,_SLIDER_2,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;

        default:
            break;                   
    }
}

void MenuOsdSettingsVPosAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_VPOS);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_VPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_VPOS_ADJUST,_SLIDER_3,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
           break;
            
        case _RIGHT_KEY_MESSAGE:                 
        case _LEFT_KEY_MESSAGE:
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_VPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_VPOS_ADJUST,_SLIDER_3,_OFF,0);
       //     ScalerTimerDelayXms(20);
              if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
                {
                     OsdDispSetPosition(_POS_PERCENT, (_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
                }  
              else
                {
                     OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());
                }
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_OSD_VPOS);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_OSD_VPOS_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_OSD_VPOS_ADJUST,_SLIDER_3,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;

        default:
            break;                   
    }
}

void MenuOsdSettingsTransparencyAdjust(void)
{
  switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_TRNASPARENCY);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST,_SLIDER_4,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
          break;
            
        case _RIGHT_KEY_MESSAGE:                 
        case _LEFT_KEY_MESSAGE:
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST,_SLIDER_4,_OFF,0);
            OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OSDSETTINGS_TRNASPARENCY);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_TRNASPARENCY_ADJUST,_SLIDER_4,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;

        default:
            break;                   
    }

}


void MenuOsdSettingsMenuTimeAdjust(void)
{
  switch(GET_KEYMESSAGE())
    {

        case _MENU_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OSDSETTINGS_MENU_TIME);
		   OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_MENU_TIME_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_MENU_TIME_ADJUST,_SLIDER_5,_ON,0);
           SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;

			
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE: 
			g_usAdjustValue= (BYTE)OsdDisplayDetOverRange(GET_OSD_TIME_OUT(), _OSD_TIMEOUT_MAX, _OSD_TIMEOUT_MIN, _OFF);
			SET_OSD_TIME_OUT(g_usAdjustValue);
			OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_MENU_TIME_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_MENU_TIME_ADJUST,_SLIDER_5,_OFF,0);
                  //  ScalerTimerReactiveTimerEvent(SEC(GET_OSD_TIME_OUT()), _USER_TIMER_EVENT_OSD_DISABLE);
                   break;
            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OSDSETTINGS_MENU_TIME);
		   OsdDispMainMenukeySlideAndOption(_MENU_OSDSETTINGS_MENU_TIME_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_OSDSETTINGS_MENU_TIME_ADJUST,_SLIDER_5,_ON,0);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
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
	OsdFontPut1FuncHLine(18, 8, _WHITE_EDGE_1, g_ucOsdWidth-8 ,_CP_WHITE, _CP_BLUE_65);
	OsdPropPutString(ROW(20), COL(8), _PFONT_PAGE_2, _STRING_GAME_TIMER_POSITION, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
	OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
	OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
	switch(GET_OSD_Left_Timer_Position())
	{
		case _LEFT_TIMER_POSITION_1:
			OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
			OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
			
			break;
		case _LEFT_TIMER_POSITION_2:
			OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
			OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
			break;
		case _LEFT_TIMER_POSITION_3:
			OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
			OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
			break;
		 default:
		 	SET_OSD_Left_Timer_Position(_LEFT_TIMER_POSITION_1);
			OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
			OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
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
		OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,1);	
		OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);

		 OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,2);	 
		 OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,10);
		 OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);	 
		 OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);

		 OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,9);	 
		 OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,10);
		 OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);	 
		 OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);
		 break;

	 
	case _TIMER_20:
	
		ucForeground2=_CP_RED;
		ucForeground1=_CP_WHITE;
		ucForeground3=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,1);	
		OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);
		
		
		
		
		
		 OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,2);	 
		 OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,10);
		 OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);	 
		 OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);
		
		 
		 OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,3);	 
		 OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);
		 OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,10);
		 OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);	 
		 OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);
		
		break;
	case _TIMER_30:
		ucForeground3=_CP_RED;
		ucForeground2=_CP_WHITE;
		ucForeground4=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,2); 	
		OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground2,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,3); 	
		OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,4); 	
		OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);
		
		break;
	case _TIMER_40:
		ucForeground4=_CP_RED;
		ucForeground3=_CP_WHITE;
		ucForeground5=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,3); 	
		OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground3,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,4); 	
		OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,5);	
		OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);
		
		
		break;
	case _TIMER_50:
		ucForeground5=_CP_RED;
		ucForeground4=_CP_WHITE;
		ucForeground6=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,4); 	
		OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground4,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,5);	
		OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,6);	
		OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);
		
	
	break;
	case _TIMER_60:
		ucForeground6=_CP_RED;
		ucForeground5=_CP_WHITE;
		ucForeground7=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,5);	
		OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground5,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,6);	
		OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,9);	
		OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);
		break;
	case _TIMER_90:
		ucForeground7=_CP_RED;
		ucForeground6=_CP_WHITE;
		ucForeground1=_CP_WHITE;
		OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,6);	
		OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground6,_CP_BLUE_65,0);
		
		
		OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,9);	
		OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground7,_CP_BLUE_65,0);
		OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,1);	
		OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);
		OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,10);
		OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);	
		OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,ucForeground1,_CP_BLUE_65,0);
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
void OsdDispLeftTimerMenu(void)
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
        
//        OsdWindowDrawingHighlight(0, 0, 0, 0, 0, 0, 0, 0);
//        OsdFuncChangeIconColor1Bit(0, 0, 0 , 0, 0);

       ScalerOsdDataPort(0);

//#if(_DIGITAL_PORT_SUPPORT == _ON)
       // ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
//#endif

    }

    OsdFuncDisableOsd();

    OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_TIMER_WIDTH+1), HEIGHT(_OSD_LEFT_KEY_TIMER_HEIGHT+1), COLOR(_CP_BLUE_120, _CP_BG));

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
     #if(_OSTAR_OSD_SMALL == _ON)
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( 6), _CP_GREEN_119);
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( 6), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(7), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #else     
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #endif	
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
				OsdDispSetPosition(_POS_PERCENT, _OSD_H_POS_MAX-0, _OSD_V_POS_MAX-0);
				break;
			case _LEFT_TIMER_POSITION_2:
				OsdDispSetPosition(_POS_PERCENT, _OSD_H_POS_MAX-0, _OSD_V_POS_MAX-50);
				break;
			case _LEFT_TIMER_POSITION_3:
				OsdDispSetPosition(_POS_PERCENT, _OSD_H_POS_MAX-0, _OSD_V_POS_MAX-90);
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
				OsdDispSetPosition(_POS_PERCENT, 0, 0);
				break;
			case _LEFT_TIMER_POSITION_2:
				OsdDispSetPosition(_POS_PERCENT, 0, 50);
				break;
			case _LEFT_TIMER_POSITION_3:
				OsdDispSetPosition(_POS_PERCENT, 0, 90);
				break;
			 default:
				 break;
		}
	}



	


    // Osd Enable
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();

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
	
		 //   OsdDispDetOverRange(0, 0, 0, 0);
	
		  //  OSTARFactoryPanelUsedTimer();
		  //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
			
	//		  OsdWindowDrawingHighlight(0, 0, 0, 0, 0, 0, 0, 0);
	//		  OsdFuncChangeIconColor1Bit(0, 0, 0 , 0, 0);
	
		   ScalerOsdDataPort(0);
	
	//#if(_DIGITAL_PORT_SUPPORT == _ON)
		   // ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
	//#endif
	
		}
	
		OsdFuncDisableOsd();
	
		OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_WIDTH), HEIGHT(_OSD_LEFT_KEY_HEIGHT), COLOR(_CP_BLUE_120, _CP_BG));
	
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
     #if(_OSTAR_OSD_SMALL == _ON)
			OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( 6), _CP_GREEN_119);
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( 6), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(7), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #else     
			OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #endif	
		 }
		else
#endif
    {
	OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BG );
	
	OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_2, _STRING_GAME_TIME, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_TIMER);
		
	
    }
	{
	
	  
		  if(GET_OSD_Timer()==_TIMER_10)
			{
			  OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,1);	  
			  OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	
			  OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_20)
			{
			  OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,2);   
			  OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	  
			  OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_30)
			{
			  OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,3);   
			  OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	  
			  OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_40)
			{
			  OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,4);   
			  OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	  
			  OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_50)
			{
			  OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,5);	
			  OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	
			  OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_60)
			{
			  OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,6);	  
			  OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	
			  OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
		  else if(GET_OSD_Timer()==_TIMER_90)
			{
			  OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,9);	  
			  OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			  OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,10);
			  OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);	
			  OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_RED,_CP_BLUE_65,0);
			}
					  
	  }
	
		
		
	
	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
	  {
		   OsdDispSetPosition(_POS_PERCENT, (_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
	  }  
	else
	  {
		   OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());
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
	
		 //   OsdDispDetOverRange(0, 0, 0, 0);
	
		  //  OSTARFactoryPanelUsedTimer();
		  //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
			
	//		  OsdWindowDrawingHighlight(0, 0, 0, 0, 0, 0, 0, 0);
	//		  OsdFuncChangeIconColor1Bit(0, 0, 0 , 0, 0);
	
		   ScalerOsdDataPort(0);
	
	//#if(_DIGITAL_PORT_SUPPORT == _ON)
		   // ScalerSyncHdcpCheckEnabled(SysSourceGetInputPort());
	//#endif
	
		}
	
		OsdFuncDisableOsd();
	
		OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_WIDTH), HEIGHT(_OSD_LEFT_KEY_HEIGHT), COLOR(_CP_BLUE_120, _CP_BG));
	
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
     #if(_OSTAR_OSD_SMALL == _ON)
			OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( 6), _CP_GREEN_119);
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( 6), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(7), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #else     
			OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #endif	
		 }
		else
#endif
		
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BG );
		
	OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_2, _STRING_GAME_CURSOR, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
	 COsdShowChooseLeftMenuText(_STRING_LEFT_MENU_AIM);
	{
		 if(GET_OSD_AIM()==_AIM_1)
			{
			 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);
			 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_WHITE);
			 
			 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
			 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
			 
			 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	 
			 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
			 
			 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);  
			 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	
			}
		 else if(GET_OSD_AIM()==_AIM_2)
			{
			 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
			 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 
			 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);	 
			 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_WHITE);
			 
			 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	 
			 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
			 
			 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);  
			 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			}
		 else if(GET_OSD_AIM()==_AIM_3)
			{
			 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
			 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 
			 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG);
			 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 
			 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);	 
			 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_WHITE);	 
			 
			 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	 
			 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			}
		 else if(GET_OSD_AIM()==_AIM_4)
			{
			 OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
			 OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 
			 OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
			 OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	 
			 
			 OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);	 
			 OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
			 
			 OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);	 
			 OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_WHITE);
			}
	
	 }
		
	
		
		
	
	if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
	  {
		   OsdDispSetPosition(_POS_PERCENT, (_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
	  }  
	else
	  {
		   OsdDispSetPosition(_POS_PERCENT, GET_OSD_HPOS(), GET_OSD_VPOS());
	}
	
	
	
		// Osd Enable
		ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
		OsdFuncEnableOsd();
	
	}



//OsdDispLeftTimerMenuPosition
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
	 break;
		 
	 case _RIGHT_KEY_MESSAGE: 
	 case _LEFT_KEY_MESSAGE:
	 	
		 SET_OSD_Left_Timer_Position(OsdDisplayDetOverRange(GET_OSD_Left_Timer_Position() , _LEFT_TIMER_POSITION_END, _LEFT_TIMER_POSITION_1, _ON));
 
 
		 
		 switch(GET_OSD_Left_Timer_Position())
		 {
			 case _LEFT_TIMER_POSITION_1:
				 OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 break;
			 case _LEFT_TIMER_POSITION_2:
				 OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 break;
			 case _LEFT_TIMER_POSITION_3:
				 OsdThreeColorChooseTableForm(19, 17,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdThreeColorChooseTableForm(20, 27,_EDGE_LINE,2 ,1,_CP_BLUE_65, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdThreeColorChooseTableForm(21, 37,_EDGE_LINE,2 ,1,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
				 OsdFontPut1ChooseIcon(20, 18, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 OsdFontPut1ChooseIcon(21, 28, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
				 OsdFontPut1ChooseIcon(22, 38, _LEFT_CORNER_0+1,_CP_WHITE, _CP_BLUE_65);
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
				 SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT() , _PICTURE_USER, _PICTURE_STANDARD, _ON));
		 
		 switch(GET_OSD_COLOR_EFFECT())
		 {
			 case _PICTURE_STANDARD:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_STANDARD, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				 break;
			 case _PICTURE_GAME:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_MOVIE, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());	 
				 break;
			 case _PICTURE_MOVIE:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_PHOTO, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());	 
				 break;
			 case _PICTURE_PHOTO:
				 OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				 OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_GAME, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				 break;
			case _PICTURE_USER:
				OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_FPS, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				break;
			case _PICTURE_FPS:
				OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_RTS, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
				break;
			case _PICTURE_RTS:
				OsdFuncClearOsd(ROW(5), COL(22), WIDTH(10), HEIGHT(1));
				OsdPropPutString(ROW(5), COL(22), _PFONT_PAGE_2, _STRING_PICTURE_USER, COLOR(_CP_RED, _CP_BG), GET_OSD_LANGUAGE());
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
 void MenuInputAdjust(void)
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
							 OSTARNVRamSaveOSDData();  
#endif                            
							 break;
#if(_A0_PORT_SHIELD==_OFF)
#if(_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) 
			 case _OSD_INPUT_A0: // A0
						 SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_A0);
						 SET_FORCE_POW_SAV_STATUS(_FALSE);
						 SysSourceSwitchInputPort(_A0_INPUT_PORT);
 
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
		   
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
							 OSTARNVRamSaveOSDData();  
#endif                            
 
									  
							 break;
#endif
#endif
 
#if(_D0_PORT_SHIELD==_OFF)
#if(_D0_INPUT_PORT_TYPE !=_D0_NO_PORT) 
				 case _OSD_INPUT_D0: // D0
                                   #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                           g_usVolumePowerForPopo= _ON;
                                   	  PCB_AMP_MUTE(_AMP_MUTE_ON);
                                          DebugMessageAudio("PCB_AMP_MUTE(D2Port)   0000000", 0);
                                   #endif					 
					 SET_FORCE_POW_SAV_STATUS(_FALSE);
					 SysSourceSwitchInputPort(_D0_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
					 
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
						 OSTARNVRamSaveOSDData();					   
					 }
#else
					 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
					OSTARNVRamSaveOSDData();
#endif
#endif
								 break;
	 
#endif
 
#endif
 
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
			 case _OSD_INPUT_D1:	//D1
                                #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                        g_usVolumePowerForPopo= _ON;
                                        PCB_AMP_MUTE(_AMP_MUTE_ON);
                                       DebugMessageAudio("PCB_AMP_MUTE(D2Port)   1111111", 0);
                                #endif	
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D1_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
					 OSTARNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 OSTARNVRamSaveOSDData();
#endif
#endif
						  break;
 
#endif
 
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
			 case _OSD_INPUT_D2:	//D2
                                #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                        g_usVolumePowerForPopo= _ON;
                                        PCB_AMP_MUTE(_AMP_MUTE_ON);	
                                       DebugMessageAudio("PCB_AMP_MUTE(D2Port)   22222", 0);
                                #endif				
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D2_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
					 OSTARNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 OSTARNVRamSaveOSDData();
#endif
#endif
							 break;
 
#endif
 
 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
			   case _OSD_INPUT_D3:	//D3
                                #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                        g_usVolumePowerForPopo= _ON;
                                        PCB_AMP_MUTE(_AMP_MUTE_ON);	
                                       DebugMessageAudio("PCB_AMP_MUTE(D2Port)   333333", 0);
                                #endif	
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D3_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
				 OSTARNVRamSaveOSDData();
#endif
							 break;
#endif
 
 
 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
						 case _OSD_INPUT_D4:	//D4
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D4_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
				 OSTARNVRamSaveOSDData();
#endif
									
							 break;
 
#endif
 
 
 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
						 case _OSD_INPUT_D5:	//D5
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D5_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
				 OSTARNVRamSaveOSDData();
#endif
 
 
							 break;
#endif
 
 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
						 case _OSD_INPUT_D6:	//D6
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D6_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
					 OSTARNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 OSTARNVRamSaveOSDData();
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
			 g_usItemNum=_OSD_INPUT_AUTO;
			 }
		 else 
			 {
				  g_usItemNum++;
			 }
 
		 SET_OSD_INPUT_PORT_OSD_ITEM(g_usItemNum);
		 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usItemNum)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
			 if((SysModeGetModeState() == _MODE_STATUS_POWER_SAVING)||(SysModeGetModeState() == _MODE_STATUS_NOSIGNAL))
			 {
				 ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_SHOW_POWER_SAVING);			
			 }	 
			 SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
 
 
			 break;
 
		 case _LEFT_KEY_MESSAGE: 
			 CLR_KEYREPEATENABLE();
		 g_usItemNum=GET_OSD_INPUT_PORT_OSD_ITEM();
		 if(g_usItemNum==_OSD_INPUT_AUTO)
			 {
			 g_usItemNum=(_OSD_INPUT_AMOUNT-1);
			 }
		 else 
					{
					g_usItemNum--;
			 }
 
		 SET_OSD_INPUT_PORT_OSD_ITEM(g_usItemNum);
		 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usItemNum)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
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
				 SET_OSD_STATE(_MENU_SETUP_INPUT);
				 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
				 COsdShowChooseSetupText(_STRING_SETUP_INPUT);
			 }			  
 
			 break;
 
		 default:
			 break; 				  
	 }
 }

 /*
 void MenuInputAuto(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            if(SysSourceGetScanType() != _SOURCE_SWITCH_AUTO_IN_GROUP)
            {
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_AUTO);
                SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

                if(UserCommonNVRamGetSystemData(_SOURCE_SCAN_TYPE) != SysSourceGetScanType())
                {
                    UserCommonNVRamSetSystemData(_SOURCE_SCAN_TYPE, SysSourceGetScanType());
                    SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_SYSTEMDATA_MSG);
                }

#if(_DP_MST_SUPPORT == _ON)
                ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
                OSTARNVRamSaveOSDData();  
#endif
            }
         else
          {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                ScalerOsdWindowDisable(_OSD_WINDOW_9);
            }
            break;
            
        case _RIGHT_KEY_MESSAGE:
            
    #if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF))
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
       #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
    #endif 
            break;

        case _LEFT_KEY_MESSAGE:
            
       #if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF))
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #endif 
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
       
            break;

        default:
            break;                   
    }
}
#if(_A0_PORT_SHIELD==_OFF)
#if(_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) 
void MenuInputA0Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _A0_INPUT_PORT))
            {
                        SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_A0);
                        SET_FORCE_POW_SAV_STATUS(_FALSE);
                        SysSourceSwitchInputPort(_A0_INPUT_PORT);
                        SET_OSD_STATE(_MENU_SETUP_INPUT);

                            SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
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
                            OSTARNVRamSaveOSDData();  
#endif                            

                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
        }          
            break;
            
        case _RIGHT_KEY_MESSAGE:
    #if((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
       #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
       #else 
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _LEFT_KEY_MESSAGE:
            
             SET_OSD_STATE(_MENU_INPUT_AUTO);
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
                       
            break;

        default:
            break;                   
    }
}
#endif
#endif
#if(_D0_PORT_SHIELD==_OFF)
    #if(_D0_INPUT_PORT_TYPE !=_D0_NO_PORT) 
    void MenuInputD0Port(void)
    {
        switch(GET_KEYMESSAGE())
        {
            case _MENU_KEY_MESSAGE:
    #if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D0_INPUT_PORT))
                {
                   #if(_PCB_TYPE == _RL6449_2795) //tdy add for popo
                           g_usVolumePowerForPopo= _ON;
                   	  PCB_AMP_MUTE(_AMP_MUTE_ON);
                          DebugMessageAudio("PCB_AMP_MUTE(D2Port)   0000000", 0);
                   #endif	
				
                    SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D0);
    
                    SET_FORCE_POW_SAV_STATUS(_FALSE);
                    SysSourceSwitchInputPort(_D0_INPUT_PORT);
                    SET_OSD_STATE(_MENU_SETUP_INPUT);
                    SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                    
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
                        OSTARNVRamSaveOSDData();                      
                    }
    #else
                    ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
                    OSTARNVRamSaveOSDData();
    #endif
    #endif
                    
                }
                else
                {
                    SET_OSD_STATE(_MENU_SETUP_INPUT);
                   ScalerOsdWindowDisable(_OSD_WINDOW_9);
              }
    #endif      
    
                break;
                
            case _RIGHT_KEY_MESSAGE:
        #if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
                 SET_OSD_STATE(_MENU_INPUT_D1_PORT);
        #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
                 SET_OSD_STATE(_MENU_INPUT_D2_PORT);
        #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
                 SET_OSD_STATE(_MENU_INPUT_D3_PORT);
        #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
                 SET_OSD_STATE(_MENU_INPUT_D4_PORT);
        #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
                 SET_OSD_STATE(_MENU_INPUT_D5_PORT);
           #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
                 SET_OSD_STATE(_MENU_INPUT_D6_PORT);
           #else 
                 SET_OSD_STATE(_MENU_INPUT_AUTO);
        #endif 
                break;
    
            case _LEFT_KEY_MESSAGE:
                
        #if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
                 SET_OSD_STATE(_MENU_INPUT_A0_PORT);
        #else
                 SET_OSD_STATE(_MENU_INPUT_AUTO);
        #endif 
                break;
    
            case _EXIT_KEY_MESSAGE:
                SET_OSD_STATE(_MENU_SETUP_INPUT);
     break;
    
            default:
                break;                   
        }
    }
    #endif
#endif

#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
void MenuInputD1Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D1_INPUT_PORT))
            {
                   #if(_PCB_TYPE == _RL6449_2795) //tdy add for popo
                           g_usVolumePowerForPopo= _ON;
                   	  PCB_AMP_MUTE(_AMP_MUTE_ON);
                          DebugMessageAudio("PCB_AMP_MUTE(D2Port)   1111111", 0);
                   #endif	
			
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D1);

                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D1_INPUT_PORT);
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                
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
                    OSTARNVRamSaveOSDData();                      
                }
#else
                ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
                OSTARNVRamSaveOSDData();
#endif
#endif
                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
          }
#endif      
            break;
            
        case _RIGHT_KEY_MESSAGE:    
    #if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
       #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
       #else 
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            
            break;

        case _LEFT_KEY_MESSAGE:
            
    #if((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #else
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
 break;

        default:
            break;                   
    }
}
#endif

#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
void MenuInputD2Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D2_INPUT_PORT))
            {
                   #if(_PCB_TYPE == _RL6449_2795) //tdy add for popo
                           g_usVolumePowerForPopo= _ON;
                   	  PCB_AMP_MUTE(_AMP_MUTE_ON);	
                          DebugMessageAudio("PCB_AMP_MUTE(D2Port)   22222", 0);
                   #endif	
			
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D2);

                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D2_INPUT_PORT);
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                
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
                    OSTARNVRamSaveOSDData();                      
                }
#else
                ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
                OSTARNVRamSaveOSDData();
#endif
#endif
                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
          }
#endif      
            break;
            
        case _RIGHT_KEY_MESSAGE:    
    #if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
       #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
       #else 
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _LEFT_KEY_MESSAGE:
    #if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #else
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _EXIT_KEY_MESSAGE: 
                    SET_OSD_STATE(_MENU_SETUP_INPUT);
            break;

        default:
            break;                   
    }
}
#endif

#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
void MenuInputD3Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D3_INPUT_PORT))
            {
                   #if(_PCB_TYPE == _RL6449_2795) //tdy add for popo
                           g_usVolumePowerForPopo= _ON;
                   	  PCB_AMP_MUTE(_AMP_MUTE_ON);	
                          DebugMessageAudio("PCB_AMP_MUTE(D2Port)   333333", 0);
                   #endif	
			
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D3);

                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D3_INPUT_PORT);
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                
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
                OSTARNVRamSaveOSDData();
#endif
                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
          }
#endif      
            break;
            
        case _RIGHT_KEY_MESSAGE:    
    #if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
       #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
       #else 
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _LEFT_KEY_MESSAGE:
            
    #if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #else
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
            break;

        default:
            break;                   
    }
}
#endif


#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 

void MenuInputD4Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D4_INPUT_PORT))
            {
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D4);

                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D4_INPUT_PORT);
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                
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
                OSTARNVRamSaveOSDData();
#endif
                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
          }
#endif      
            break;
            
        case _RIGHT_KEY_MESSAGE:    
    #if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
       #elif(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
       #else 
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _LEFT_KEY_MESSAGE:
            
    #if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #else
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
     break;

        default:
            break;                   
    }
}
#endif

#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
void MenuInputD5Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D5_INPUT_PORT))
            {
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D5);

                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D5_INPUT_PORT);
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                
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
                OSTARNVRamSaveOSDData();
#endif
                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
          }
#endif      
            break;
            
        case _RIGHT_KEY_MESSAGE: 
            
       #if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D6_PORT);
       #else 
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _LEFT_KEY_MESSAGE:
    #if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #else
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
break;

        default:
            break;                   
    }
}
#endif

#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
void MenuInputD6Port(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
            if((SysSourceGetScanType() != _SOURCE_SWITCH_FIXED_PORT) || (SysSourceGetInputPort() != _D6_INPUT_PORT))
            {
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D6);

                SET_FORCE_POW_SAV_STATUS(_FALSE);
                SysSourceSwitchInputPort(_D6_INPUT_PORT);
                SET_OSD_STATE(_MENU_SETUP_INPUT);
                SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
                
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
                    OSTARNVRamSaveOSDData();                      
                }
#else
                ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
                OSTARNVRamSaveOSDData();
#endif
#endif
                
            }
            else
            {
                SET_OSD_STATE(_MENU_SETUP_INPUT);
               ScalerOsdWindowDisable(_OSD_WINDOW_9);
          }
#endif      
            break;
            
        case _RIGHT_KEY_MESSAGE:    

             SET_OSD_STATE(_MENU_INPUT_AUTO);
            break;

        case _LEFT_KEY_MESSAGE:
            
    #if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D5_PORT);
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D4_PORT);
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D3_PORT);
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D2_PORT);
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
             SET_OSD_STATE(_MENU_INPUT_D1_PORT);
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
             SET_OSD_STATE(_MENU_INPUT_D0_PORT);
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
             SET_OSD_STATE(_MENU_INPUT_A0_PORT);
    #else
             SET_OSD_STATE(_MENU_INPUT_AUTO);
    #endif 
    
            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_SETUP_INPUT);
 break;

        default:
            break;                   
    }
}
#endif
*/
void MenuAudioMuteonoff(void)
{
   switch(GET_KEYMESSAGE())
   {
	   case _MENU_KEY_MESSAGE:

		   SET_OSD_STATE(_MENU_SETUP_AUDIOMUTE);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   COsdShowChooseSetupText(_STRING_SETUP_AUDIOMUTE);
			   SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	  break;
		   
	   case _RIGHT_KEY_MESSAGE: 			 
	   case _LEFT_KEY_MESSAGE:
		   CLR_KEYREPEATENABLE();
		   SET_OSD_VOLUME_MUTE(OsdDisplayDetOverRange(GET_OSD_VOLUME_MUTE() , _ON, _OFF, _ON));
		   g_usBackupValue = GET_OSD_VOLUME_MUTE();
		   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
#if(_AUDIO_SUPPORT == _ON)
		   UserAdjustAudioMuteSwitch();
#endif
		   break;

	   case _EXIT_KEY_MESSAGE:
		   SET_OSD_STATE(_MENU_SETUP_AUDIOMUTE);
		   ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		   COsdShowChooseSetupText(_STRING_SETUP_AUDIOMUTE);
			   SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
	   break;

	   default:
		   break;					
   }
}
					   
//MenuAudioAdjust

void MenuAudioAdjust(void)
{
   switch(GET_KEYMESSAGE())
   {
	   case _MENU_KEY_MESSAGE:

		   SET_OSD_STATE(_MENU_SETUP_AUDIO);
		   OsdDispMainMenukeySlideAndOption(_MENU_AUDIO_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_AUDIO_ADJUST,_SLIDER_9,_ON,0);
			   SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
		   break;
		   
	   case _RIGHT_KEY_MESSAGE:
	   case _LEFT_KEY_MESSAGE:

	 OsdDispMainMenukeySlideAndOption(_MENU_AUDIO_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_AUDIO_ADJUST,_SLIDER_9,_OFF,0);
	  if((GET_OSD_VOLUME_MUTE() == _ON) && (g_usBackupValue == GET_OSD_VOLUME())) 
		   {
			   SET_OSD_VOLUME_MUTE(_OFF);
		   }			
#if(_AUDIO_SUPPORT == _ON)
		   UserAdjustAudioVolume(GET_OSD_VOLUME());
#endif
	  
		   
		   break;

	   case _EXIT_KEY_MESSAGE:
		   SET_OSD_STATE(_MENU_SETUP_AUDIO);
		   OsdDispMainMenukeySlideAndOption(_MENU_AUDIO_ADJUST-_MENU_PICTURE_BRIGHTNESS_ADJUST,_MENU_AUDIO_ADJUST,_SLIDER_9,_ON,0);
			   SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

		   break;

	   default:
		   break;					
   }
}
//MenuAudioMuteonoff



void MenuOthersDisplaySizeAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_DISPLAY_SIZE);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
				COsdShowChooseOtherText(_STRING_OTHER_DISPLAY_SIZE);
			break;
            
        case _RIGHT_KEY_MESSAGE:
        case _LEFT_KEY_MESSAGE:
               SET_OSD_ASPECT_RATIO_TYPE(OsdDisplayDetOverRange(GET_OSD_ASPECT_RATIO_TYPE() ,_OSD_ASPECT_RATIO_AMOUNT,_OSD_ASPECT_RATIO_FULL, _ON));
                OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_ASPECT_RATIO_TYPE())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);


		  #if(_ASPECT_RATIO_SUPPORT == _ON)
                SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
          #endif

            break;

        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_DISPLAY_SIZE);
		ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		COsdShowChooseOtherText(_STRING_OTHER_DISPLAY_SIZE);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
   
            break;

        default:
            break;                   
    }
}

#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
void MenuOthersLowBlueLightAdjust(void)
{
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OTHERS_LOW_BLUE_LIGHT);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		 COsdShowChooseOtherText(_STRING_OTHER_LOW_BLUE);
				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;
            
        case _RIGHT_KEY_MESSAGE:   
        case _LEFT_KEY_MESSAGE:
			CLR_KEYREPEATENABLE();
	  SET_OSD_LOWBLUELIGHT_STATUS(OsdDisplayDetOverRange(GET_OSD_LOWBLUELIGHT_STATUS() , _LOWBLUE_STRONGEST, _LOWBLUE_OFF, _ON));
          OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_LOWBLUELIGHT_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
            UserAdjustColorLowBlueLight(GET_OSD_LOWBLUELIGHT_STATUS());
            break;

        case _EXIT_KEY_MESSAGE:
           SET_OSD_STATE(_MENU_OTHERS_LOW_BLUE_LIGHT);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		 COsdShowChooseOtherText(_STRING_OTHER_LOW_BLUE);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
            break;

        default:
            break;
    }
}

#endif

#if(_OD_FUNCTION == _ON)        	
void MenuOthersOverDriveAdjust(void)
{
	
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_OD);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		 COsdShowChooseOtherText(_STRING_OTHER_OVER_DRIVER);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        break;



        case _RIGHT_KEY_MESSAGE:  
            
        case _LEFT_KEY_MESSAGE:
			CLR_KEYREPEATENABLE();
	  SET_OSD_OD_STATUS(OsdDisplayDetOverRange(GET_OSD_OD_STATUS() , _ON, _OFF, _ON));
          OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_OD_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
    #if(_OD_SUPPORT == _ON)    
            ScalerODEnable(GET_OSD_OD_STATUS());
	        ScalerTimerWaitForEvent(_EVENT_DVS);

    #endif
    
       break;




        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_OD);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		 COsdShowChooseOtherText(_STRING_OTHER_OVER_DRIVER);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
        break;

        default:
            break;                   
    }
}

#endif


void MenuOthersFreeSyncAdjust(void)
{
	
    switch(GET_KEYMESSAGE())
    {
        case _MENU_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_FREE_SYNC);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		 COsdShowChooseOtherText(_STRING_OTHER_FREESYNC);

				SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
               #if(_FREESYNC_SUPPORT == _ON)
                               ScalerSyncSetFREESYNCSupport(GET_OSD_FREE_SYNC_STATUS());
                #endif
				
        break;



        case _RIGHT_KEY_MESSAGE:  
            
        case _LEFT_KEY_MESSAGE: 
			CLR_KEYREPEATENABLE();
	        SET_OSD_FREE_SYNC_STATUS(OsdDisplayDetOverRange(GET_OSD_FREE_SYNC_STATUS() , _ON, _OFF, _ON));
          OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_FREE_SYNC_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);
#if(_PCB_TYPE == _RL6449_SM2775YTC_1DP2H_VBO)

	#if  0//((_WRITE_EDID_LOCATION_BY_USER_SUPPORT == _ON))
         	if(GET_OSD_FREE_SYNC_STATUS() == _ON)
                   {
                      UserCommonRestoreEmbeddedEDIDData();
         	  }
         	else
                   {
                      UserCommonRestoreEmbeddedEDIDDataNoFreesync();
         	   }
	
        #endif
		       OsdDispEepromWriteProtectOff(); // tdy add for ostar osd 20170306 //
#endif	
       break;




        case _EXIT_KEY_MESSAGE:
            SET_OSD_STATE(_MENU_OTHERS_FREE_SYNC);
		 ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
		 COsdShowChooseOtherText(_STRING_OTHER_FREESYNC);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
               #if(_FREESYNC_SUPPORT == _ON)
                               ScalerSyncSetFREESYNCSupport(GET_OSD_FREE_SYNC_STATUS());
                #endif
				
        break;

        default:
            break;                   
    }
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
 // 	   OsdFuncChangeIconColor1Bit(0, 0, 0 , 0, 0);
 
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
     #if(_OSTAR_OSD_SMALL == _ON)
		 OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( 6), _CP_GREEN_119);
		 OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( 6), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(7), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #else     
		 OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
		 OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
     #endif	
	  }
	 else
#endif
	 {
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
		{
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(1), WIDTH(g_ucOsdWidth-3), HEIGHT((g_ucOsdHeight-1)), _CP_BLUE_65 );
		}	 
		else 
		{
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(1), WIDTH(g_ucOsdWidth-3), HEIGHT((g_ucOsdHeight-1)), _CP_BLUE_65 );
		}
	OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLUE_65,_CP_BG,_QUADRANGLE_WINDOW_0);

	COsdShowPageInputText();


	//OsdPropPutString(ROW(2), COL(3), _PFONT_PAGE_0, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	 
	//OsdPropPutString(ROW(2), COL(18), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
	//OsdPropPutString(ROW(2), COL(26), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
	//OsdPropPutString(ROW(2), COL(37), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	
//OsdPropPutStringCenter
	  //OsdPropPutStringCenter(ROW(3), COL(37), _PFONT_PAGE_0, _STRING_SETUP_HDMI, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	  
	//  OsdPropPutStringCenter(ROW(2), COL(1), WIDTH(11), _PFONT_PAGE_0, _STRING_AUTO_SELECT, _CP_BLUE_65 , _ENGLISH);
	 // OsdPropPutStringCenter(ROW(2), COL(12), WIDTH(11), _PFONT_PAGE_0, _STRING_SETUP_DP, _CP_BLUE_65 , _ENGLISH);
	 // OsdPropPutStringCenter(ROW(2), COL(23), WIDTH(11), _PFONT_PAGE_0, _STRING_SETUP_HDMI, _CP_BLUE_65 , _ENGLISH);
	 // OsdPropPutStringCenter(ROW(2), COL(34), WIDTH(11), _PFONT_PAGE_0, _STRING_SETUP_HDMI, _CP_BLUE_65 , _ESPANA);

	  g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
	 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(2), COL(3+(11*GET_OSD_INPUT_PORT_OSD_ITEM())), WIDTH(8), HEIGHT(1), _CP_BLACK, _CP_RED, _CP_BG);

   //background    
	 }
 
	 
	 
 
	 OsdDispSetPosition(_POS_PERCENT, 50, 50);
 
 
 
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
							 OSTARNVRamSaveOSDData();  
#endif                            
							 break;
#if(_A0_PORT_SHIELD==_OFF)
#if(_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) 
			 case _OSD_INPUT_A0: // A0
						 SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_A0);
						 SET_FORCE_POW_SAV_STATUS(_FALSE);
						 SysSourceSwitchInputPort(_A0_INPUT_PORT);
 
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
		   
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
							 OSTARNVRamSaveOSDData();  
#endif                            
 
									  
							 break;
#endif
#endif
 
#if(_D0_PORT_SHIELD==_OFF)
#if(_D0_INPUT_PORT_TYPE !=_D0_NO_PORT) 
				 case _OSD_INPUT_D0: // D0
                                 #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                         g_usVolumePowerForPopo= _ON;
                                 	  PCB_AMP_MUTE(_AMP_MUTE_ON);
                                        DebugMessageAudio("PCB_AMP_MUTE(D2Port)   0000000", 0);
                                 #endif					
					 SET_FORCE_POW_SAV_STATUS(_FALSE);
					 SysSourceSwitchInputPort(_D0_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
					 
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
						 OSTARNVRamSaveOSDData();					   
					 }
#else
					 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
					OSTARNVRamSaveOSDData();
#endif
#endif
								 break;
	 
#endif
 
#endif
 
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
			  case _OSD_INPUT_D1:	//D1
                                #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                       g_usVolumePowerForPopo= _ON;
                                       PCB_AMP_MUTE(_AMP_MUTE_ON);
                                      DebugMessageAudio("PCB_AMP_MUTE(D2Port)   1111111", 0);
                               #endif	

				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D1_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
					 OSTARNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 OSTARNVRamSaveOSDData();
#endif
#endif
						  break;
 
#endif
 
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
		   case _OSD_INPUT_D2:	//D2
                          #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                  g_usVolumePowerForPopo= _ON;
                          	  PCB_AMP_MUTE(_AMP_MUTE_ON);	
                                 DebugMessageAudio("PCB_AMP_MUTE(D2Port)   22222", 0);
                          #endif							 
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D2_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
					 OSTARNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 OSTARNVRamSaveOSDData();
#endif
#endif
							 break;
 
#endif
 
 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
			  case _OSD_INPUT_D3:	//D3
                           #if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
                                   g_usVolumePowerForPopo= _ON;
                           	  PCB_AMP_MUTE(_AMP_MUTE_ON);	
                                  DebugMessageAudio("PCB_AMP_MUTE(D2Port)   333333", 0);
                           #endif	
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D3_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
				 OSTARNVRamSaveOSDData();
#endif
							 break;
#endif
 
 
 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
						 case _OSD_INPUT_D4:	//D4
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D4_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
				 OSTARNVRamSaveOSDData();
#endif
									
							 break;
 
#endif
 
 
 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
						 case _OSD_INPUT_D5:	//D5
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D5_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
				 OSTARNVRamSaveOSDData();
#endif
 
 
							 break;
#endif
 
 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
						 case _OSD_INPUT_D6:	//D6
				 SET_FORCE_POW_SAV_STATUS(_FALSE);
				 SysSourceSwitchInputPort(_D6_INPUT_PORT);
	  #if(GUEST_TYPE != _LANCHUANG_GUEST)
				 SysSourceSetScanType(_SOURCE_SWITCH_FIXED_PORT);
	  #endif
				 
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
					 OSTARNVRamSaveOSDData();					   
				 }
#else
				 ScalerDpRxMstRx0Rx1switch(_DP_MST_NO_PORT);
				 OSTARNVRamSaveOSDData();
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
			 g_usItemNum=_OSD_INPUT_AUTO;
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
		 if(g_usItemNum==_OSD_INPUT_AUTO)
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
    MenuOsdSettings,
    MenuSetup,
    MenuOther,
    
    // picture
    MenuPictureBrightness,
    MenuPictureContrast,
    MenuPictureECO,
    MenuPictureMainSR,

  
    // color
    MenuColorTemperature,
    MenuColorColortempUserR,
    MenuColorColortempUserG,
    MenuColorColortempUserB,

   //OSD Settings
    MenuOsdSettingsLanguage,
    MenuOsdSettingsOsdHPos,
    MenuOsdSettingsOsdVPos,
    MenuOsdSettingsTransparency,
    MenuOsdSettingsMenuTime,

   //Setup 
    MenuSetupInput,
	MenuSetupAudioMute,
	MenuSetupAudio,
    MenuSetupReset,

  //Others
    MenuOthersDisplaySize,
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
    MenuOthersLowBlueLight,
#endif
#if(_OD_FUNCTION == _ON)
    MenuOthersOverDrive,
#endif
    MenuOthersFreeSync,



    // picture adjust
    MenuPictureBacklightAdjust,
    MenuPictureContrastAdjust,
    MenuPictureECOAdjust,
    MenuPictureMainSRAdjust,

    //color
    MenuColorColortempAdjust,
    MenuColorColortempUserAdjustR,
    MenuColorColortempUserAdjustG,
    MenuColorColortempUserAdjustB,

   //Osd Setting 
    MenuOsdSettingsLanguageAdjust,
    MenuOsdSettingsHPosAdjust,
    MenuOsdSettingsVPosAdjust,
    MenuOsdSettingsTransparencyAdjust,
    MenuOsdSettingsMenuTimeAdjust,
  ///
    MenuHotkeyECOAdjust,
    
 //   MenuHotkeyGameArm,	
    MenuLeftKeyGame,
   // MenuHotkeyGameArmAdjust,
    MenuLeftKeyGameAdjust,
    MenuLeftKeyTimer,
    MenuLeftKeyTimerAdjust,
    OsdDispLeftTimerMenu,
    OsdDispLeftTimerMenuAdjust,
    OsdDispLeftTimerMenuPosition,
    //setup
    MenuInputAdjust,
	MenuAudioMuteonoff,
    MenuAudioAdjust,
    /*
    MenuInputAuto,
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
    MenuInputA0Port,
#endif 
#if((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF) )
    MenuInputD0Port,
#endif 
#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
    MenuInputD1Port,
#endif 
#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
    MenuInputD2Port,
#endif 
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
    MenuInputD3Port,
#endif 
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
    MenuInputD4Port,
#endif 
#if(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
    MenuInputD5Port,
#endif 
#if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
    MenuInputD6Port,
#endif 
*/
   //others
    MenuOthersDisplaySizeAdjust,
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
    MenuOthersLowBlueLightAdjust,
#endif
#if(_OD_FUNCTION == _ON)        	    
    MenuOthersOverDriveAdjust,
#endif
    MenuOthersFreeSyncAdjust,
	MenuHotInputAdjust,
    };


#endif  //#if(_OSD_TYPE == _OSTAR_2014_OSD)

