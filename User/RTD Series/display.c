#if(_OSD_TYPE == _OSTAR_2014_OSD)





//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
//    STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _VGA_A0 = 0x01,
} EnumOsdSourceTypeVga;

typedef enum
{
    _DVI = 0x02,
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
    _DVI_D0,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    _DVI_D1,
#endif
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
    _DVI_D2,
#endif
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
    _DVI_D3,
#endif
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
    _DVI_D4,
#endif
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
    _DVI_D5,
#endif

    _HDMI = 0x10,
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
    _HDMI_D0,
#endif
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    _HDMI_D1,
#endif
#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
    _HDMI_D2,
#endif
#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
    _HDMI_D3,
#endif
#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
    _HDMI_D4,
#endif
#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
    _HDMI_D5,
#endif
}EnumOsdSourceTypeTMDS;

typedef enum
{
    _DP = 0x0E,
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    _DP_D0,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    _DP_D1,
#endif
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    _DP_D2,
#endif
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
    _DP_D6,
#endif
} EnumOsdSourceTypeDP;

//****************************************************************************
// CODE TABLES
//****************************************************************************
//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
bit g_usVolumeEarphoneForPopo = _ON;   //tdy add for popo
bit g_usVolumePowerForPopo = _ON;
#endif



//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
//void OsdPropPutOptionString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor, BYTE ucLanguage);
void COsdShowPageText(BYTE PageNo);
void COsdShowPageInputTextSelect(BYTE InputOsd,BYTE InputType,BYTE NUM);
void COsdShowPageInputText(void);
//void OsdFontVLCDynamicLoadIconSelect(BYTE ICONSavePos,BYTE InputIconSelect);
void OsdDisplayGetSourcePort(BYTE ucRow,BYTE ucCol);
//BYTE OsdDisplayGetSourcePortString(void);

/*
#if(_VGA_SUPPORT == _ON)
BYTE OsdDisplayGetVGAModeString(bit bUserMode);
#endif
*/
//WORD OsdDispDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);
BYTE OsdDispJudgeSourceType(void);

void OsdDispDisableOsd(void);
void OsdDispSetPosition(BYTE ucType, WORD usHPos, WORD usVPos);
void OsdDispSlider(BYTE ucRow, BYTE ucCol, BYTE ucLength, WORD usValue, WORD usMax, WORD usMin, BYTE ucColor);
//void OsdDispClearSelectColor(BYTE ucUpDown);
/*#if(_VGA_SUPPORT == _ON)
void OsdDispMainSubString(BYTE ucState);
#endif
*/
//void OsdDispMainOptionIcon(BYTE ucIconPos, BYTE ucIcon, BYTE ucColor);
//void OsdDispMainMenuIconString(BYTE ucIconPos, WORD usIcon, BYTE ucColor);    
//void OsdDispMainMenuIconPage(BYTE ucUpDown, BYTE ucState);
//void OsdDispMainMenuArrow(BYTE ucUpDown, BYTE ucLeftRight, BYTE ucState);
//void OsdDispClearArrow(bit ucUpDown);
//void OsdDispMainMenuOptionSetting(BYTE ucItem, BYTE ucSelectState, BYTE ucOption);
void OsdDispMainMenuItemSelection(BYTE ucIconPos, BYTE ucState);
//void OsdDispMainMenuSubSelect(BYTE ucItem, BYTE ucOsdState, BYTE ucOsdStatePrevious);
//void OsdDispMainMenukeyCursor(BYTE ucOsdPositionState,BYTE type);
//void OsdDispMainMenukeySlideAndOption(BYTE ucOsdPositionState,BYTE OSDState,BYTE SlideNum,BYTE MenuExit,BYTE type);
void OsdDispMainMenuCursorOsdDispMainMenukeyCursor(BYTE ucOsdPositionState,BYTE type);
void OsdDispMainMenu(void);

void OsdDispSliderAndNumber(BYTE ucOsdState, WORD usValue);
//void OsdDispClearSliderAndNumber(void);
WORD OsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle);
void OsdDisplaySixColorGetOneColor(BYTE ucColor);
//void OsdDisplaySixColorSetOneColor(BYTE ucColor);
/*
#if((_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) || (_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE))
void OsdDispOsdRotateSwitch(void);
#endif
*/
void OsdDispOsdMessage(EnumOSDDispMsg ucMessage);
#if(_VGA_SUPPORT == _ON)    
void OsdDispAutoConfigProc(void);
void OsdDisplayAutoBalanceProc(void);
#endif

void OsdDispShowLogo(void);
//void OsdDispShowInformation(void);
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
/*
void OsdFontVLCDynamicLoadIconSelect(BYTE ICONSavePos,BYTE InputIconSelect)
{
switch(InputIconSelect)
{
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
case  _OSD_INPUT_A0:
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_VGA);
      break;
#endif


 
#if((_D0_INPUT_PORT_TYPE!= _D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF))
case  _OSD_INPUT_D0:
    
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DVI);
#endif                    
#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_HDMI);
#endif      
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DP);
#endif      
      break;
#endif


#if(_D1_INPUT_PORT_TYPE!= _D1_NO_PORT)
case  _OSD_INPUT_D1:
    
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DVI);
#endif                    
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_HDMI);
#endif      
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DP);
#endif      
      break;
#endif
        

#if(_D2_INPUT_PORT_TYPE!= _D2_NO_PORT)
case  _OSD_INPUT_D2:
    
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DVI);
#endif                    
#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_HDMI);
#endif      
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DP);
#endif      
      break;
#endif         



#if(_D3_INPUT_PORT_TYPE!= _D3_NO_PORT)
case  _OSD_INPUT_D3:
    
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DVI);
#endif                    
#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_HDMI);
#endif      
      break;
#endif            



#if(_D4_INPUT_PORT_TYPE!= _D4_NO_PORT)
case  _OSD_INPUT_D4:
    
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DVI);
#endif                    
#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_HDMI);
#endif      
      break;
#endif        


#if(_D5_INPUT_PORT_TYPE!= _D5_NO_PORT)
case  _OSD_INPUT_D5:
    
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DVI);
#endif                    
#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT)||(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_HDMI);
#endif      
      break;
#endif  
          



#if(_D6_INPUT_PORT_TYPE!= _D6_NO_PORT)
case  _OSD_INPUT_D6:
    
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
    OsdFontVLCDynamicLoadIcon( ICONSavePos, _ICON_INPUT_DP);
#endif      
      break;
#endif  
}
}

*/

void OsdDisplayGetSourcePort(BYTE ucRow,BYTE ucCol)
{
    BYTE  DVInum,HDMInum,DPnum;
    DVInum=0;
    HDMInum=0;
    DPnum=0;    

		switch(SysSourceGetInputPort())
		{
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
			case _A0_INPUT_PORT:
				break;		
#endif   

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
			case _D0_INPUT_PORT:
                             #if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DVInum++;
                             COsdShowPageInputString(0,_INPUT_OSD_DVI,DVInum,0);
                             #endif                    
                             #if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
                             HDMInum++;
                             COsdShowPageInputString(0,_INPUT_OSD_HDMI,HDMInum,0);
                             #endif           
                             #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DPnum++;
                             COsdShowPageInputString(0,_INPUT_OSD_DP,DPnum,0);
                             #endif 
			     OsdPropPutString(ROW(ucRow), COL(ucCol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
			break;
#endif 

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
			case _D1_INPUT_PORT:
                             #if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DVInum++;
                             #endif                    
                             #if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
                             HDMInum++;
                             #endif           
                             #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DPnum++;
                             #endif 
                           #if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                           DVInum++;
                            COsdShowPageInputString(0,_INPUT_OSD_DVI,DVInum,0);
                           #endif                    
                           #if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                           HDMInum++;
                            COsdShowPageInputString(0,_INPUT_OSD_HDMI,HDMInum,0);
                           #endif           
                           #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                           DPnum++;
                            COsdShowPageInputString(0,_INPUT_OSD_DP,DPnum,0);
                           #endif            
			     OsdPropPutString(ROW(ucRow), COL(ucCol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
			    break;
		// return _STRING_D1_PORT;
#endif 

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
			case _D2_INPUT_PORT:
                             #if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DVInum++;
                             #endif                    
                             #if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
                             HDMInum++;
                             #endif           
                             #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DPnum++;
                             #endif 
                           #if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                           DVInum++;
                           #endif                    
                           #if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                           HDMInum++;
                           #endif           
                           #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                           DPnum++;
                           #endif     

			   #if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                                DVInum++;
                               COsdShowPageInputString(0,_INPUT_OSD_DVI,DVInum,0);
                              #endif                    
                              #if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
                              HDMInum++;
                               COsdShowPageInputString(0,_INPUT_OSD_HDMI,HDMInum,0);
                              #endif           
                              #if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
                              DPnum++;
                               COsdShowPageInputString(0,_INPUT_OSD_DP,DPnum,0);
                              #endif            
				
				OsdPropPutString(ROW(ucRow), COL(ucCol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
			    break;
			  //  return _STRING_D2_PORT;
#endif   

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
			case _D3_INPUT_PORT:
                             #if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DVInum++;
                             #endif                    
                             #if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
                             HDMInum++;
                             #endif           
                             #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DPnum++;
                             #endif 
                           #if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                           DVInum++;
                           #endif                    
                           #if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                           HDMInum++;
                           #endif           
                           #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                           DPnum++;
                           #endif     

			   #if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                                DVInum++;
                              #endif                    
                              #if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
                              HDMInum++;
                              #endif           
                              #if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
                              DPnum++;
                              #endif           				
                                #if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                                  DVInum++;
                                 COsdShowPageInputString(0,_INPUT_OSD_DVI,DVInum,0);
                                #endif                    
                                #if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
                                 HDMInum++;
                                 COsdShowPageInputString(0,_INPUT_OSD_HDMI,HDMInum,0);
                                #endif           
				OsdPropPutString(ROW(ucRow), COL(ucCol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
			    break;
		// 	return _STRING_D3_PORT;
#endif        
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
			case _D4_INPUT_PORT:
                             #if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DVInum++;
                             #endif                    
                             #if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
                             HDMInum++;
                             #endif           
                             #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DPnum++;
                             #endif 
                           #if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                           DVInum++;
                           #endif                    
                           #if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                           HDMInum++;
                           #endif           
                           #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                           DPnum++;
                           #endif     

			   #if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                                DVInum++;
                              #endif                    
                              #if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
                              HDMInum++;
                              #endif           
                              #if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
                              DPnum++;
                              #endif           				
                                #if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                                  DVInum++;
                                #endif                    
                                #if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
                                 HDMInum++;
                                #endif   

				#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                                   DVInum++;
                                 COsdShowPageInputString(0,_INPUT_OSD_DVI,DVInum,0);
                                 #endif                    
                                 #if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
                                  HDMInum++;
                                  COsdShowPageInputString(0,_INPUT_OSD_HDMI,HDMInum,0);
				#endif
				OsdPropPutString(ROW(ucRow), COL(ucCol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
				 break;
		//  return _STRING_D4_PORT;
#endif  

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
			case _D5_INPUT_PORT:
                             #if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DVInum++;
                             #endif                    
                             #if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
                             HDMInum++;
                             #endif           
                             #if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
                             DPnum++;
                             #endif 
                           #if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
                           DVInum++;
                           #endif                    
                           #if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
                           HDMInum++;
                           #endif           
                           #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
                           DPnum++;
                           #endif     

			   #if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
                                DVInum++;
                              #endif                    
                              #if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
                              HDMInum++;
                              #endif           
                              #if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
                              DPnum++;
                              #endif           				
                                #if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
                                  DVInum++;
                                #endif                    
                                #if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
                                 HDMInum++;
                                #endif   

				#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
                                   DVInum++;
                                 #endif                    
                                 #if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
                                  HDMInum++;
				#endif				
                               #if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
                                 DVInum++;
                               COsdShowPageInputString(0,_INPUT_OSD_DVI,DVInum,0);
                               #endif                    
                               #if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT)||(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
                                HDMInum++;
                                COsdShowPageInputString(0,_INPUT_OSD_HDMI,HDMInum,0);
                               #endif   
				OsdPropPutString(ROW(ucRow), COL(ucCol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);  
				break;
#endif


			default:
			break ;
			  // return _STRING_A0_PORT;
}
}
//--------------------------------------------------
// Description : 
// Input Value : None
// Output Value : None
//--------------------------------------------------
/*BYTE OsdDisplayGetSourcePortString(void)
{
 switch(SysSourceGetInputPort())
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
            return _STRING_A0_PORT;
#endif
    
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
            return _STRING_D0_PORT;
#endif                    
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
            return _STRING_D1_PORT;
#endif            
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
            return _STRING_D2_PORT;
#endif        
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
            return _STRING_D3_PORT;
#endif        
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
            return _STRING_D4_PORT;
#endif        
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:
            return _STRING_D5_PORT;
#endif
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
        case _D6_INPUT_PORT:
            return _STRING_D6_PORT;
#endif 
        default:
           return _STRING_A0_PORT;
    }
}
*/
/*
#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description : 
// Input Value : None
// Output Value : None
//--------------------------------------------------
BYTE OsdDisplayGetVGAModeString(bit bUserMode)
{
    if(bUserMode == _USER_MODE_TYPE)
    {
        return _STRING_VGA_USER_MODE;
    }
    else
    {
        return _STRING_VGA_PRESET_MODE;
    }
}
#endif
*/
//--------------------------------------------------
// Description : 
// Input Value : None
// Output Value : None
//--------------------------------------------------
/*WORD OsdDispDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle)
{
    ucValue = ucMax = ucMin;
    bCycle = 0;
    return 0;
    //return tOSD_ITEM_MAIN[0]; // to prevent uncall
}
*/
BYTE OsdDispJudgeSourceType(void)
{
    BYTE ucOsdSourcePort = _VGA_A0;
    
    switch(SysSourceGetInputPort())
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
            ucOsdSourcePort = _VGA_A0;
            return ucOsdSourcePort;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:
#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
            ucOsdSourcePort = _DVI_D0;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT) || (_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))
            ucOsdSourcePort = _HDMI_D0;
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ucOsdSourcePort = _DP_D0;
#endif        
            return ucOsdSourcePort; 
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
            ucOsdSourcePort = _DVI_D1;
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT) || (_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
            ucOsdSourcePort = _HDMI_D1;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ucOsdSourcePort = _DP_D1;
#endif        
            return ucOsdSourcePort;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
            if(_DVI_D2 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D2;
            }
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
            if(_HDMI_D2 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D2;
            }
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if(_DP_D2 > 0x10)
            {
                ucOsdSourcePort = 0x0F;
            }
            else
            {
                ucOsdSourcePort = _DP_D2;
            }
#endif        
            return ucOsdSourcePort;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
            if(_DVI_D3 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D3;
            }
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
            if(_HDMI_D3 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D3;
            }
#endif
            return ucOsdSourcePort;            
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
            if(_DVI_D4 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D4;
            }
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
            if(_HDMI_D4 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D4;
            }
#endif        
            return ucOsdSourcePort;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:
#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
            if(_DVI_D5 > 0x04)
            {
                ucOsdSourcePort = 0x03;
            }
            else
            {
                ucOsdSourcePort = _DVI_D5;
            }
#endif

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
            if(_HDMI_D5 > 0x12)
            {
                ucOsdSourcePort = 0x11;
            }
            else
            {
                ucOsdSourcePort = _HDMI_D5;
            }
#endif
            return ucOsdSourcePort;
#endif

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
        case _D6_INPUT_PORT:
#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
            if(_DP_D6 > 0x10)
            {
                ucOsdSourcePort = 0x0F;
            }
            else
            {
                ucOsdSourcePort = _DP_D6;
            }
#endif        
            return ucOsdSourcePort;           
#endif

        default:
            return ucOsdSourcePort;
    }
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispDisableOsd(void)
{

    SET_OSD_STATE(_MENU_NONE);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncDisableOsd();
    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
    g_ucOsdWidth = 0;
    g_ucOsdHeight = 0;        
}

//--------------------------------------------------
// Description  : 
// Input Value  : None
// Output Value : None
//--------------------------------------------------
//20140207 Abel Modify
void OsdDispSetPosition(BYTE ucType, WORD usHPos, WORD usVPos)
{
    WORD usx, usy;

    if(ucType == _POS_PERCENT)
    {  
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usx = 5 + ((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdWidth * 18) / 4) * usHPos) / _OSD_H_POS_MAX;
            usy = 3 + ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdHeight * 12) * usVPos ) / _OSD_V_POS_MAX;
        }
        else
        {
            usx = 5 + ((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdWidth * 12) / 4) * usHPos) / _OSD_H_POS_MAX;
            usy = 3 + ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdHeight * 18) * usVPos ) / _OSD_V_POS_MAX;
        }
#elif(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
#if 1//(_PCB_TYPE == _RL6432_SANC2785_1A1DP1HDMI1DUALDVI_DPTX_LVDS)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usx =  ((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdHeight * 18) / 4) * usHPos) / _OSD_H_POS_MAX;
            usy =  ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdWidth * 12) * usVPos ) / _OSD_V_POS_MAX;
        }
        else
        {
           if(usHPos == 0)
            {
               usx =  (((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdWidth * 12) / 4) * usHPos) / _OSD_H_POS_MAX)-1;
            }
           else
            {
               usx =  (((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdWidth * 12) / 4) * usHPos) / _OSD_H_POS_MAX);
            }

               usy =  ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdHeight * 18) * usVPos ) / _OSD_V_POS_MAX;
        }
#else
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usx = 5 + ((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdHeight * 18) / 4) * usHPos) / _OSD_H_POS_MAX;
            usy = 3 + ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdWidth * 12) * usVPos ) / _OSD_V_POS_MAX;
        }
        else
        {
            usx = 5 + ((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdWidth * 12) / 4) * usHPos) / _OSD_H_POS_MAX;
            usy = 3 + ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdHeight * 18) * usVPos ) / _OSD_V_POS_MAX;
        }
#endif
#else
        usx = 5 + ((DWORD)((_PANEL_DH_WIDTH - (WORD)g_ucOsdWidth * 12) / 4) * usHPos) / _OSD_H_POS_MAX;
        usy = 3 + ((DWORD)(_PANEL_DV_HEIGHT - (WORD)g_ucOsdHeight * 18) * usVPos ) / _OSD_V_POS_MAX;

#endif

    }
    else
    {
        usx = usHPos;
        usy = usVPos;
    }
// Lee add for osd mute     20141015 start//
//    if(usVPos<50)//
//    {
        //if(GET_OSD_BACKLIGHT()>95)
//        {
//            ScalerTimerDelayXms(100);
 //       }
//    }
// Lee add for osd mute     20141015 end//
    OsdFuncSetPosition(usx, usy);    
}

/*
void OsdDispMainMenuIconString(BYTE ucIconPos, WORD usIcon, BYTE ucColor)    
	{
		BYTE ucRow = 4, ucCol = 4;
		BYTE ucFontPage = _PFONT_PAGE_0;
		WORD usIconLoad = 0; 
	
		
	  //  ucRow =  ROW(32);
	 //   ucCol = COL(121) ;
	
	  if(usIcon == _MENU_NONE)
		{
			OsdFuncClearOsd( ucRow, (ucCol - 2), WIDTH(10), HEIGHT(5));
			return;
		}
		
		
		else if (usIcon>_ICON_PORT_END && usIcon !=_ICON_QINGHUA )
		{
			ucRow =  ROW(14);//ROW(37);
			ucCol = COL(26-(ucIconPos-8)*18);//COL(108);
			OsdFontVLCDynamicLoadIcon(ucIconPos, usIcon);		 
			OsdFontPut1BitMainMenuIcon(ucRow, ucCol, (32+_1DYNAMIC_ICON_START + (ucIconPos * 6)), ucColor, _CP_BG);
	
		}
		else if(usIcon==_ICON_QINGHUA)
		{
			ucRow =  ROW(16);//ROW(37);
			ucCol = COL(50);//COL(108);
			OsdFontVLCDynamicLoadIcon(ucIconPos, usIcon);		 
			OsdFontPut1BitMainMenuIcon(ucRow, ucCol, _1DYNAMIC_ICON_START, ucColor, _CP_BG);
	
		}
	
		// icon    
	 /*   if((usIcon >= _ICON_A0_PORT) && (usIcon <= _ICON_D6_PORT))	
		{
			switch(usIcon)	  
			{
				case _ICON_A0_PORT :
					usIconLoad = _A0_INPUT_TYPE;
					break;
				case _ICON_D0_PORT :
					usIconLoad = _D0_INPUT_TYPE;
					break;
				case _ICON_D1_PORT :
					usIconLoad = _D1_INPUT_TYPE;
					break;
				case _ICON_D2_PORT :
					usIconLoad = _D2_INPUT_TYPE;
					break;
				case _ICON_D3_PORT :
					usIconLoad = _D3_INPUT_TYPE;
					break;
	
				case _ICON_D4_PORT :
					usIconLoad = _D4_INPUT_TYPE;
					break;
				case _ICON_D5_PORT :
					usIconLoad = _D5_INPUT_TYPE;
					break;
	
				case _ICON_D6_PORT :
					usIconLoad = _D6_INPUT_TYPE;
					break;
	
			}
	
			OsdFontVLCDynamicLoadIcon(ucIconPos, usIconLoad);
		}
		else
	   
		else
		{
		
			ucRow =  ROW(14-(ucIconPos*2));//ROW(32)
			ucCol = COL(56) ;//COL(121)
	
			OsdFontVLCDynamicLoadIcon(ucIconPos, usIcon);		 
			
			OsdFontPut1BitMainMenuIcon(ucRow, ucCol, (32+_1DYNAMIC_ICON_START + (ucIconPos * 6)), ucColor, _CP_BG);    
	
		// string
			 
				ucRow -= 0;
				ucCol -= 8;
	
	
		// 1
				//ucRow = 17;
			//	ucCol = 54;
				OsdFuncClearOsd(ucRow, ucCol, WIDTH(6), HEIGHT(1));
				OsdPropPutStringCenter( ucRow, ucCol, WIDTH(6), ucFontPage, usIcon-1, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
		*/	
	
	
	 /*   // 2
		ucRow = 0;
				ucCol = 6;
				OsdFuncClearOsd(ucRow, ucCol, WIDTH(6), HEIGHT(1));
				OsdPropPutStringCenter( ucRow, ucCol, WIDTH(6), ucFontPage, usIcon-1, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
	// 3
		ucRow = 2;
					ucCol = 0;
					OsdFuncClearOsd(ucRow, ucCol, WIDTH(6), HEIGHT(1));
					OsdPropPutStringCenter( ucRow, ucCol, WIDTH(6), ucFontPage, usIcon-1, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
	// 4
		ucRow = 1;
					ucCol = 7;
					OsdFuncClearOsd(ucRow, ucCol, WIDTH(6), HEIGHT(1));
					OsdPropPutStringCenter( ucRow, ucCol, WIDTH(6), ucFontPage, usIcon-1, COLOR(ucColor, _CP_BG), GET_OSD_LANGUAGE());
	
	
	 }
	
		
	}
*/

void OsdDispMainMenuItemSelection(BYTE ucIconPos, BYTE ucState)
{
    BYTE ucRow, ucCol;
    BYTE ucWin = _OSD_WINDOW_8;//_OSD_WINDOW_4_1;
    BYTE ucWinColor = _CP_ORANGE;//_CP_BLUE;
    BYTE ucForegroundColor = _CP_RED;//_CP_ORANGE;
    
    ucCol =2;// ((ucIconPos / 4) ? ROW(14) : ROW(4));
    #if( _OSTAR_OSD_SMALL ==  _ON)   
     ucRow = 2 + ucIconPos*4;   //small osd set
     #else
     ucRow = 2 + ucIconPos*4;
    #endif

/*
    if(ucState == _OSD_UNSELECT)
    {
        if((ucIconPos / 4) > 0)
        {
            ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
        }    
        else
        {
            ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
        }
        return;
        */
       
    if(ucState == _OSD_UNSELECT)
    {
     ucWinColor = _CP_GREEN_119;
    ucForegroundColor = _CP_BLUE_65;
    }
    else if(ucState == _OSD_PRE_SELECT)
    {
        ucForegroundColor = _CP_BLUE_120;
    }
    else if(ucState == _OSD_SELECT_ADJUST)
    {
        ucForegroundColor = _CP_ORANGE_DARK;
    }

   /* 
    if((ucIconPos / 7) > 0)
    {
     ucWin = _OSD_WINDOW_4_2;
        ucWinColor = _CP_LIGHTBLUE;
    }
    */
  #if( _OSTAR_OSD_SMALL ==  _ON)   
  //OsdFontPut1FuncTableForm(2, 2, _EDGE_LINE,g_ucOsdWidth/5-1 ,3,ucForegroundColor,_CP_BLUE_65,_ARC_WINDOW_0);
  //OsdWindowDrawingByFontHighlight(ucWin, ucRow, ucCol, WIDTH(16), HEIGHT(10), ucWinColor, ucForegroundColor, _CP_ORANGE);
  
  OsdFontPut1FuncTableForm(ucRow, ucCol, _EDGE_LINE,g_ucOsdWidth/5-1 ,3,ucForegroundColor,_CP_BLUE_65,_ARC_WINDOW_0);
 #else
 //OsdFontPut1FuncTableForm(2, 2, _EDGE_LINE,g_ucOsdWidth/5-1 ,3,ucForegroundColor,_CP_BLUE_65,_ARC_WINDOW_0);
 //OsdWindowDrawingByFontHighlight(ucWin, ucRow, ucCol, WIDTH(21), HEIGHT(10), ucWinColor, ucForegroundColor, _CP_ORANGE);

 OsdFontPut1FuncTableForm(ucRow, ucCol, _EDGE_LINE,g_ucOsdWidth/5-1 ,3,ucForegroundColor,_CP_BLUE_65,_ARC_WINDOW_0);
 
 #endif
}

/*
void OsdDispClearArrow(bit ucUpDown)
{
    OsdDispMainMenuArrow(ucUpDown, _LEFT, _OSD_REJECT);
    OsdDispMainMenuArrow(ucUpDown, _RIGHT, _OSD_REJECT);

}
*/
/*
void OsdDispMainMenuSubSelect(BYTE ucItem, BYTE ucOsdState, BYTE ucOsdStatePrevious)
{

    BYTE ucItemPrev, ucItemCurr=0;
    switch(ucItem)
    {
        case _ICON_SUB_SEL_INPUT:
            //previous state 
            if((ucOsdStatePrevious >= _MENU_INPUT_AUTO) && (ucOsdStatePrevious <= _MENU_INPUT_D6_PORT))
            {
                ucItemPrev = ucOsdStatePrevious - _MENU_INPUT_AUTO;
            }
            //current state        
            if((ucOsdState >= _MENU_INPUT_AUTO) && (ucOsdState <= _MENU_INPUT_D6_PORT))
            {
                ucItemCurr = ucOsdState - _MENU_INPUT_AUTO;
            }
            break;

        default:
            break;
    }

    OsdDispMainMenuItemSelection((ucItemPrev % 4)+4, _OSD_UNSELECT);
    OsdDispMainMenuItemSelection((ucItemCurr % 4)+4, _OSD_SELECT);
}
*/


// selection
// arrow
// indicate

void OsdDispMainMenukeySlideAndOption(BYTE ucOsdPositionState,BYTE OSDState, BYTE SlideNum,BYTE MenuExit, BYTE type)
{

 BYTE    ucrow,uccol,ucFontPoint;
 
 //WORD g_usAdjustValueNum = 0; 
 
  ucrow=0;
  uccol=0;
  ucFontPoint=SlideNum+3;
// OSDstate=GET_OSD_STATE();
/*
#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
 if((OSDstate>=_MENU_PICTURE_BRIGHTNESS)&&(OSDstate<=_MENU_PICTURE_BLACK_EQUALIZER))
    {
       cont=_OSD_POSITION_1_COUNT;
       }
#else
 if((OSDstate>=_MENU_PICTURE_BRIGHTNESS)&&(OSDstate<=_MENU_PICTURE_CONTRAST))
    {
       cont=_OSD_POSITION_1_COUNT;
       }
#endif
 else if((OSDstate>=_MENU_DISPLAY_AUTO)&&(OSDstate<=_MENU_PICTURE_SHARPNESS))
     {
       cont=_OSD_POSITION_2_COUNT;
       }
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
 else if((OSDstate>=_MENU_COLOR_TEMPERATURE)&&(OSDstate<=_MENU_COLOR_LOW_BLUE_LIGHT))
     {
       cont=_OSD_POSITION_3_COUNT;
       }
#else
 else if((OSDstate>=_MENU_COLOR_TEMPERATURE)&&(OSDstate<=_MENU_COLOR_SATURATION))
     {
       cont=_OSD_POSITION_3_COUNT;
       }
#endif
 #if((_USE_TIME_SUPPORT == _ON)&&(_OD_FUNCTION == _ON))
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_USE_TIME))
 #elif(_OD_FUNCTION == _ON)
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_OD))
 #elif(_USE_TIME_SUPPORT == _ON)
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_USE_TIME))
 #else
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_ASPECT))
#endif

     {
       cont=_OSD_POSITION_4_COUNT;
    }
//  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_DP3_DVI_ORT))
 //  {
 //      cont=_OSD_POSITION_5_COUNT;
 //  }
  else if((OSDstate>=_MENU_AUDIO_VOLUME)&&(OSDstate<=_MENU_AUDIO_AUDIO_SOURCE))
     {
       cont=_OSD_POSITION_6_COUNT;
        }
  else if((OSDstate>=_MENU_OTHER_LANGUAGE)&&(OSDstate<=_MENU_FACTORY))
   {
     cont=_OSD_POSITION_7_COUNT;
   }
  else if((OSDstate>=_MENU_COLOR_TEMP_USER_R)&&(OSDstate<=_MENU_COLOR_TEMP_USER_ADJUST_B))
   {
     cont=_OSD_POSITION_TEMP_USER_COUNT;
   }
*/

  
     if(type==0)
      {
               switch(ucOsdPositionState/3)
            {
            case 0:
               ucrow=_OSD_NUMBER_1_ROW;            
            break; 
            
            case  1: 
               ucrow=_OSD_NUMBER_2_ROW;            

                   break;  
            case  2: 
               ucrow=_OSD_NUMBER_3_ROW;            

                   break;  
            default :
             break;
          }
           switch(ucOsdPositionState%3)
            {
                case 0:
               uccol=_OSD_NUMBER_2_COL;            
            break; 
            
            case  1: 
               uccol=_OSD_NUMBER_4_COL;            

                   break;  
            case  2: 
               uccol=_OSD_NUMBER_6_COL;            

                   break;  
            default :
             break;
          }
               switch(OSDState)
              {
                case _MENU_PICTURE_BRIGHTNESS_ADJUST:
#if(_BACKLIGHT_SELECT == _BACKLIGHT_ADJ)
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_BACKLIGHT(), _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER);        
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_OSD_BACKLIGHT(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER));
#else
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_BRIGHTNESS(), _BRIGHTNESS_MAX, _BRIGHTNESS_MIN, _BRIGHTNESS_CENTER);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_OSD_BRIGHTNESS(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _BRIGHTNESS_MAX, _BRIGHTNESS_MIN, _BRIGHTNESS_CENTER));

#endif
                 break;
               
                case _MENU_PICTURE_CONTRAST_ADJUST:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_CONTRAST(), _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER);        
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_OSD_CONTRAST(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));
                    break;


             	 case _MENU_OSDSETTINGS_OSD_HPOS_ADJUST:
            
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF);
					SET_OSD_HPOS(g_usAdjustValue);
					g_usAdjustValue=GET_OSD_HPOS();
                    break;


				 case _MENU_OSDSETTINGS_OSD_VPOS_ADJUST:
					 g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OFF);
					 SET_OSD_VPOS(g_usAdjustValue);
					 g_usAdjustValue=GET_OSD_VPOS();
				 	break;
				case _MENU_OSDSETTINGS_TRNASPARENCY_ADJUST:
					 g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_TRANSPARENCY_STATUS(), _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER);
					// g_usAdjustValue =( (BYTE)OsdDisplayDetOverRange((g_usAdjustValue/10), 10, 0, _OFF)*10);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_OSD_TRANSPARENCY_STATUS(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER));
					break;
				case _MENU_OSDSETTINGS_MENU_TIME_ADJUST:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_TIME_OUT(), _OSD_TIMEOUT_MAX, _OSD_TIMEOUT_MIN, _OSD_TIMEOUT_CENTER);				
					break;
				case _MENU_COLOR_TEMP_USER_ADJUST_R:
					//g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					//g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					//SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));

					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));
					break;
				case _MENU_COLOR_TEMP_USER_ADJUST_G:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_G(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));

					break;
				case _MENU_COLOR_TEMP_USER_ADJUST_B:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_B(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
					SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));
					//_MENU_COLOR_TEMP_USER_ADJUST_G
					break;
				case _MENU_AUDIO_ADJUST:

					g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_VOLUME(), _OSD_VOLUME_MAX, _OSD_VOLUME_MIN, _OFF);
					SET_OSD_VOLUME(g_usAdjustValue);

					break;

  

  /*         case _MENU_DISPLAY_CLOCK_ADJUST:

                  #if(_VGA_SUPPORT == _ON)

                          #if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)
                                   g_usAdjustValue = OsdDisplayDetOverRange(GET_VGA_MODE_ADJUST_CLOCK(), 100, 0, _OFF);
                           #else
                                   g_usAdjustValue = OsdDisplayDetOverRange(GET_VGA_MODE_ADJUST_CLOCK(), UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX), UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN), _OFF);
                            #endif
                           SET_VGA_MODE_ADJUST_CLOCK(g_usAdjustValue);
                 #endif
                    
                       break;
                
                case _MENU_DISPLAY_PHASE_ADJUST:

                #if(_VGA_SUPPORT == _ON)
                        g_usAdjustValue= (BYTE)OsdDisplayDetOverRange(GET_VGA_MODE_ADJUST_PHASE(), _OSD_PHASE_MAX, _OSD_PHASE_MIN, _OFF);
                       SET_VGA_MODE_ADJUST_PHASE(g_usAdjustValue);
                #endif       
                    break;


                case _MENU_COLOR_HUE_ADJUST:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_HUE(), _HUE_MAX, _HUE_MIN, _HUE_CENTER);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_OSD_HUE(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _HUE_MAX, _HUE_MIN, _HUE_CENTER));
                    break;
                
                case _MENU_COLOR_SATURATION_ADJUST:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_SATURATION(), _SATURATION_MAX, _SATURATION_MIN, _SATURATION_CENTER);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_OSD_SATURATION(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _SATURATION_MAX, _SATURATION_MIN, _SATURATION_CENTER));
                    break;

                case _MENU_AUDIO_VOLUME_ADJUST:
                             g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_VOLUME(), _OSD_VOLUME_MAX, _OSD_VOLUME_MIN, _OFF);
                             SET_OSD_VOLUME(g_usAdjustValue);
                    break;
                    
                case _MENU_OTHER_OSD_HPOS_ADJUST:
                             g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OFF);
                             SET_OSD_HPOS(g_usAdjustValue);
                    break;
                    
                case _MENU_OTHER_OSD_VPOS_ADJUST:
                             g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OFF);
                             SET_OSD_VPOS(g_usAdjustValue);
                    break;

                    
                case _MENU_OTHER_TRNASPARENCY_ADJUST:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_TRANSPARENCY_STATUS(), _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER);
                  //  g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                     g_usAdjustValue =( (BYTE)OsdDisplayDetOverRange((g_usAdjustValue/10), 10, 0, _OFF)*10);
                    SET_OSD_TRANSPARENCY_STATUS(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER));
                    break;

                case _MENU_COLOR_TEMP_USER_ADJUST_R:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));
                    break;

                case _MENU_COLOR_TEMP_USER_ADJUST_G:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_G(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));
                    break;
                    
                case _MENU_COLOR_TEMP_USER_ADJUST_B:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_B(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
                    g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
                    SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER));
                    break;
*/
            default :
             break;       
        }

        if(((GET_KEYMESSAGE()) ==_EXIT_KEY_MESSAGE)||(MenuExit==1))
             {   

           OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, SlideNum, _UNSELECT);
           OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), ucFontPoint, _OSD_NUMBER_UNSTLECT_COLOR);  
        }   
        else
        {
           OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, SlideNum, _SELECT);
           OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF| _SHOW_3), ucFontPoint, _OSD_NUMBER_UNSTLECT_COLOR); 
		
        }
      }
/*   
   else if(type==1)
      {
               switch(ucOsdPositionState/3)
            {
                case 0:
               ucrow=_OSD_NUMBER_1_ROW;            
            break; 
            
            case  1: 
               ucrow=_OSD_NUMBER_2_ROW;            

                   break;  
            case  2: 
               ucrow=_OSD_NUMBER_3_ROW;            

                   break;  
            default :
             break;
          }
           switch(ucOsdPositionState%3)
            {
                case 0:
               uccol=_OSD_NUMBER_2_COL;            
            break; 
            
            case  1: 
               uccol=_OSD_NUMBER_4_COL;            

                   break;  
            case  2: 
               uccol=_OSD_NUMBER_6_COL;            

                   break;  
            default :
             break;
          }
               switch(OSDState)
              {
          case _MENU_COLOR_TEMPERATURE_ADJUST:        
               SET_COLOR_TEMP_TYPE(OsdDisplayDetOverRange(GET_COLOR_TEMP_TYPE() , _CT_USER, _CT_9300, _ON));
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_8, _STRING_COLOR_TEMP_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
         break;

         case _MENU_COLOR_EFFECT_ADJUST:        
#if(_USER_FUNCTION_FPS1_FPS2==_ON)
        SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT() , _COLOREFFECT_AMOUNT, _COLOREFFECT_STANDARD, _ON));
#else
       SET_OSD_COLOR_EFFECT(OsdDisplayDetOverRange(GET_OSD_COLOR_EFFECT() , 3, 0, _ON));
#endif
           //    OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_2,_STRING_Color_Effect_TABLE1,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
#if(_USER_FUNCTION_FPS1_FPS2==_ON)

if((GET_OSD_COLOR_EFFECT()==_COLOREFFECT_VIVID)||(GET_OSD_COLOR_EFFECT()==_COLOREFFECT_USER))
{
         OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_4, _STRING_Color_Effect_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) ,_ENGLISH);
}
else
{
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_4, _STRING_Color_Effect_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
}
#else

          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_4, _STRING_Color_Effect_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());

#endif
           break;

         case _MENU_COLOR_GAMMA_ADJUST:        
               SET_OSD_GAMMA(OsdDisplayDetOverRange(GET_OSD_GAMMA() , 4, 0, _ON));
             //  OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_4,_STRING_Gama_TABLE1,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_6, _STRING_Gama_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
        break;
		
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
      case _MENU_COLOR_LOW_BLUE_LIGHT_ADJUST:
               SET_OSD_LOWBLUELIGHT_STATUS(OsdDisplayDetOverRange(GET_OSD_LOWBLUELIGHT_STATUS() , _ON, _OFF, _ON));
           //    OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_2,ONOFF_TABLE1[GET_OSD_DDCCI_STATUS()],COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_5, ONOFF_TABLE1[GET_OSD_LOWBLUELIGHT_STATUS()], COLOR(_CP_LIGHTBLUE, _CP_BG) ,GET_OSD_LANGUAGE());
            break;
#endif


         case _MENU_ADVANCE_ULTRA_VIVID_ADJUST:        
               SET_OSD_ULTRA_VIVID_STATUS(OsdDisplayDetOverRange(GET_OSD_ULTRA_VIVID_STATUS() , 3, 0, _ON));
             //  OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_3,_STRING_UltraVivid_TABLE1,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_3, _STRING_UltraVivid_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
             break;
            
         case _MENU_ADVANCE_ASPECT_ADJUST:       
		 #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _OFF)
               SET_OSD_ASPECT_RATIO_TYPE(OsdDisplayDetOverRange(GET_OSD_ASPECT_RATIO_TYPE() ,_OSD_ASPECT_RATIO_5_BY_4,_OSD_ASPECT_RATIO_FULL, _ON));
		 #else
               SET_OSD_ASPECT_RATIO_TYPE(OsdDisplayDetOverRange(GET_OSD_ASPECT_RATIO_TYPE() ,_OSD_ASPECT_RATIO_AMOUNT,_OSD_ASPECT_RATIO_FULL, _ON));
		 #endif
		  //     OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_4,_STRING_Aspect_Ratio_TABLE1,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_5, _STRING_Aspect_Ratio_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
          break;

 #if(_OD_FUNCTION == _ON)               

         case _MENU_ADVANCE_OVER_DRIVE_ADJUST:   


               SET_OSD_OD_STATUS(OsdDisplayDetOverRange(GET_OSD_OD_STATUS() , _ON, _OFF, _ON));
              // OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_5,ONOFF_TABLE1[GET_OSD_OVERSCAN_STATUS()],COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
              OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
              OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_6, ONOFF_TABLE1[GET_OSD_OD_STATUS()], COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
        break;
#endif


 #if(_USE_TIME_SUPPORT == _ON)  

          case _MENU_ADVANCE_USE_TIME_ADJUST:        
               g_usTimeTabe=OsdDisplayDetOverRange(g_usTimeTabe , _OSD_ADVANCE_TIME_AMOUNT, _OSD_ADVANCE_TIME_0, _ON);
              // OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_5,ONOFF_TABLE1[GET_OSD_OVERSCAN_STATUS()],COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
              OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
              OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_7, _STRING_USE_TIME_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , _ENGLISH);
        break;
#endif


         case _MENU_AUDIO_MUTE_ON_OFF:        
               SET_OSD_VOLUME_MUTE(OsdDisplayDetOverRange(GET_OSD_VOLUME_MUTE() , _ON, _OFF, _ON));
             //  OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_2,ONOFF_TABLE1[GET_OSD_VOLUME_MUTE()],COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_ITEM_5, ONOFF_TABLE1[GET_OSD_VOLUME_MUTE()], COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
             break;
         case _MENU_AUDIO_AUDIO_SOURCE_SELECT:        

          // modify by sfy for audio volume auto select 20140915 start //
             //  SET_OSD_AUDIO_SOURCE(OsdDisplayDetOverRange(GET_OSD_AUDIO_SOURCE() , 1, 0, _ON));
               SET_OSD_AUDIO_SOURCE(OsdDisplayDetOverRange(GET_OSD_AUDIO_SOURCE() , _AUDIO_AMOUNT, 0, _ON));
       // modify by sfy for audio volume auto select 20140915 end //
       
            //   OsdPropPutOptionString(ROW(ucrow),COL(uccol), _PFONT_PAGE_ITEM_3,_STRING_Audio_Source_TABLE1,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //           
          OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
          OsdPropPutStringCenter( ucrow,  uccol+1,_OSD_SLIDE_VALUE_OFFSET, _PFONT_PAGE_2, _STRING_Audio_Source_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG) , GET_OSD_LANGUAGE());
            break;
            
         case _MENU_OTHER_LANGUAGE_ADJUST:        
               SET_OSD_LANGUAGE(OsdDisplayDetOverRange(GET_OSD_LANGUAGE() , _LANGUAGE_AMOUNT, 0, _ON));
            //OsdFuncClearOsd(ROW(ucrow), COL(uccol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));
            OsdFuncClearOsd(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), WIDTH(20), HEIGHT(1));
              OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_Language_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认   LANGUAGE 
           break;


        default :
         break;       
         }
        if(((GET_KEYMESSAGE()) ==_EXIT_KEY_MESSAGE)||(MenuExit==1))
               {
         OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(ucrow),  COL(uccol), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_LIGHTBLUE, _CP_BG);
         }  
        else
        {
         OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(ucrow),  COL(uccol), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_ORANGE_H, _CP_BG);
        }
      }*/
  



}


//*********************************************************
// 第二级菜单窗口选择处理
// 参数传输位置，规则如下
// 0~2: 选择对应第一排的位置
// 3~5: 选择对应第二排的位置
// 6~8: 选择对应第三排的位置
//*********************************************************
/*void OsdDispMainMenukeyCursor(BYTE ucOsdPositionState,BYTE type)
{
 BYTE    OSDstate,cont,ucrow,uccol,ucEXIT;
        ucrow=0;
    uccol=0;
    ucEXIT=0;
  //  OSDKEY=GET_KEYMESSAGE();
 // BYTE   ucRow,ucCol,ucheihgt,;
 // BYTE PREOSDstate,ucCOUNT;
 //  ucCOUNT=0;
  // PREOSDstate=ucOsdPositionState;

 OSDstate=GET_OSD_STATE();
#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
 if((OSDstate>=_MENU_PICTURE_BACKLIGHT)&&(OSDstate<=_MENU_PICTURE_BLACK_EQUALIZER))
    {
       cont=_OSD_POSITION_1_COUNT;
       }
#else
 if((OSDstate>=_MENU_PICTURE_BACKLIGHT)&&(OSDstate<=_MENU_PICTURE_CONTRAST))
    {
       cont=_OSD_POSITION_1_COUNT;
       }
#endif
 else if((OSDstate>=_MENU_DISPLAY_AUTO)&&(OSDstate<=_MENU_PICTURE_SHARPNESS))
     {
       cont=_OSD_POSITION_2_COUNT;
       }
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
 else if((OSDstate>=_MENU_COLOR_TEMPERATURE)&&(OSDstate<=_MENU_COLOR_LOW_BLUE_LIGHT))
     {
       cont=_OSD_POSITION_3_COUNT;
       }
#else
 else if((OSDstate>=_MENU_COLOR_TEMPERATURE)&&(OSDstate<=_MENU_COLOR_SATURATION))
     {
       cont=_OSD_POSITION_3_COUNT;
       }
#endif


 #if((_USE_TIME_SUPPORT == _ON)&&(_OD_FUNCTION == _ON))
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_USE_TIME))
 #elif(_OD_FUNCTION == _ON)
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_OD))
 #elif(_USE_TIME_SUPPORT == _ON)
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_USE_TIME))
 #else
 else if((OSDstate>=_MENU_ADVANCE_ULTRA_VIVID)&&(OSDstate<=_MENU_ADVANCE_ASPECT))
#endif


     {
       cont=_OSD_POSITION_4_COUNT;
        }
       #if(_D6_INPUT_PORT_TYPE !=_D6_NO_PORT) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D6_PORT))
    #elif(_D5_INPUT_PORT_TYPE !=_D5_NO_PORT) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D5_PORT))
    #elif(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D4_PORT))
    #elif(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D3_PORT))
    #elif(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D2_PORT))
    #elif(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D1_PORT))
    #elif((_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF))
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_D0_PORT))
    #elif((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF)) 
  else if((OSDstate>=_MENU_INPUT_AUTO)&&(OSDstate<=_MENU_INPUT_A0_PORT))
    #endif 
     {
       cont=_OSD_INPUT_AMOUNT;
        }
  else if((OSDstate>=_MENU_AUDIO_VOLUME)&&(OSDstate<=_MENU_AUDIO_AUDIO_SOURCE))
     {
       cont=_OSD_POSITION_6_COUNT;
        }
    else if((OSDstate>=_MENU_OTHER_LANGUAGE)&&(OSDstate<=_MENU_FACTORY))
     {
       cont=_OSD_POSITION_7_COUNT;
        }
    else if((OSDstate>=_MENU_COLOR_TEMP_USER_R)&&(OSDstate<=_MENU_COLOR_TEMP_USER_ADJUST_B))
     {
       cont=_OSD_POSITION_TEMP_USER_COUNT;
        }
  else 
    {

        }

   if(type==0)
     {
           OsdDispMainMenuItemSelection(ucOsdPositionState, _OSD_SELECT);
    }
  else if(type==1)
      {
          switch(GET_KEYMESSAGE())
            {
                case _LEFT_KEY_MESSAGE:
                if(ucOsdPositionState>0)
                    {
                    ucOsdPositionState--;
                    }
                else
                    {
                       ucOsdPositionState=cont-1;
                       }
                         break; 
            case _RIGHT_KEY_MESSAGE: 
                if(ucOsdPositionState<(cont-1))
                    {
                       ucOsdPositionState++;
                    }
                else
                    {
                       ucOsdPositionState=0;
                    }

                         break;  
            case _EXIT_KEY_MESSAGE: 
                             ucEXIT=1;

                         break;   
            default :
                 break;

           }
           switch(ucOsdPositionState/3)
            {
                case 0:
               ucrow=_OSD_NUMBER_1_ROW;            
            break; 
            
            case  1: 
               ucrow=_OSD_NUMBER_2_ROW;            

                   break;  
            case  2: 
               ucrow=_OSD_NUMBER_3_ROW;            

                   break;  
            default :
             break;
          }
           switch(ucOsdPositionState%3)
            {
                case 0:
               uccol=_OSD_NUMBER_1_COL;            
            break; 
            
            case  1: 
               uccol=_OSD_NUMBER_3_COL;            

                   break;  
            case  2: 
               uccol=_OSD_NUMBER_5_COL;            

                   break;  
            default :
             break;
          }
           if(ucEXIT==1)
           {
                ScalerOsdWindowDisable(_OSD_WINDOW_9);
           }  
           else
           {
           
         OsdWindowDrawingSelect(_OSD_WINDOW_9, ROW(ucrow),  COL(uccol), WIDTH(15), HEIGHT(1), _CP_ORANGE);
           
         //  OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_2, ROW(ucrow),  COL(uccol), WIDTH(15), HEIGHT(1), _CP_GRAY_1, _CP_ORANGE, _CP_BG);
           }  

      }  

   else
      {
      
      }
    
}
*/
void COsdShowPageInputTextSelect(BYTE InputOsd,BYTE InputType,BYTE NUM)
{
BYTE ucrow, uccol;
    if(GET_OSD_STATE() == _MENU_HOT_INPUT_ADJUST)
    {
	 ucrow = 2;
    //  g_usItemNum=InputType;
        uccol = 4+(11*InputOsd);

       COsdShowPageInputString(InputOsd,InputType, NUM,0);

       OsdPropPutString(ROW(ucrow), COL(uccol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
    }
    else
    {
	 uccol = _OSD_NUMBER_2_COL;
    //  g_usItemNum=InputType;
      
           switch(InputOsd)
            {
                case 0:
               ucrow=_OSD_NUMBER_1_ROW;            
            break; 
            
            case  1: 
               ucrow=_OSD_NUMBER_2_ROW;            

                   break;  
            case  2: 
               ucrow=_OSD_NUMBER_3_ROW;            

                   break;  
            case  3: 
               ucrow=_OSD_NUMBER_4_ROW;            

                   break;  
            case  4: 
               ucrow=_OSD_NUMBER_11_ROW;            

                   break;  
				   
				   
            default :
             break;
          }
           COsdShowPageInputString(InputOsd,InputType, NUM,0);
    
           OsdPropPutString(ROW(ucrow), COL(uccol), _PFONT_PAGE_2, _STRING_INPUT_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
	}


		   /*
           switch(InputOsd%3)
            {
                case 0:
               uccol=_OSD_NUMBER_1_COL;            
            break; 
            
            case  1: 
               uccol=_OSD_NUMBER_3_COL;            

                   break;  
            case  2: 
               uccol=_OSD_NUMBER_5_COL;            

                   break;  
            default :
             break;
          }
          */

}


void COsdShowPageInputText(void)
{
BYTE  DVInum,HDMInum,DPnum;
    DVInum=0;
    HDMInum=0;
    DPnum=0;    
    if(GET_OSD_STATE() == _MENU_HOT_INPUT_ADJUST)
    {
      OsdPropPutString(ROW(2), COL(4), _PFONT_PAGE_2, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
    }
    else
    {
      OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
    }
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF))
 COsdShowPageInputTextSelect(_OSD_INPUT_A0,_INPUT_OSD_VGA,0);
 #endif



 
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)&&(_D0_PORT_SHIELD==_OFF))
DVInum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D0,_INPUT_OSD_DVI,DVInum);
#endif                    
#if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT))&&(_D0_PORT_SHIELD==_OFF))
HDMInum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D0,_INPUT_OSD_HDMI,HDMInum);
#endif           
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT)&&(_D0_PORT_SHIELD==_OFF))
DPnum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D0,_INPUT_OSD_DP,DPnum);
#endif            


#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
DVInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D1,_INPUT_OSD_DVI,DVInum);
#endif                    
#if((_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)||(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT))
HDMInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D1,_INPUT_OSD_HDMI,HDMInum);
#endif           
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
DPnum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D1,_INPUT_OSD_DP,DPnum);
#endif            


#if((_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
  DVInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D2,_INPUT_OSD_DVI,DVInum);
#endif                    
#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT)||(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT))
HDMInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D2,_INPUT_OSD_HDMI,HDMInum);
#endif           
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
DPnum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D2,_INPUT_OSD_DP,DPnum);
#endif            


#if((_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
  DVInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D3,_INPUT_OSD_DVI,DVInum);
#endif                    
#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT)||(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT))
 HDMInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D3,_INPUT_OSD_HDMI,HDMInum);
#endif           


#if((_D4_INPUT_PORT_TYPE == _D4_DVI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
  DVInum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D4,_INPUT_OSD_DVI,DVInum);
#endif                    
#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT)||(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT))
 HDMInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D4,_INPUT_OSD_HDMI,HDMInum);
#endif           


#if(_D5_INPUT_PORT_TYPE == _D5_DVI_PORT)
  DVInum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D5,_INPUT_OSD_DVI,DVInum);
#endif                    
#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT)||(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT))
 HDMInum++;
 COsdShowPageInputTextSelect(_OSD_INPUT_D5,_INPUT_OSD_HDMI,HDMInum);
#endif          

         



#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
DPnum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D6,_INPUT_OSD_DP,DPnum);
#endif                    

 }

void COsdShowPageText (BYTE PageNo)
	{
		CLR_KEYREPEATENABLE();
	 //   OsdFuncClearOsd(ROW(_OSD_NUMBER_1_ROW), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(1));
	 //  OsdFuncClearOsd(ROW(_OSD_NUMBER_2_ROW), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(1));
	//	  OsdFuncClearOsd(ROW(_OSD_NUMBER_3_ROW), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(1));
	
	   // OsdFuncClearOsd(ROW(g_ucOsdHeight/2), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight/2));
			 // OsdDispClearSliderAndNumber();
			   // ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
	
		switch(PageNo)
		   {
			case _MENU_PICTURE:
	
	//Picture
				ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
				if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
				{
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_BACKLIGHT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_CONTRAST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_ECO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				}
				else 
				{
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_BACKLIGHT, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_CONTRAST, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_ECO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				}
	
				//OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_MAINSR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
				//OsdPropPutStringCenter( ROW(4), COL(2),15, _PFONT_PAGE_2, _STRING_COLOR, COLOR(_CP_GRAY, _CP_BG) , GET_OSD_LANGUAGE());
#if(_BACKLIGHT_SELECT == _BACKLIGHT_ADJ)
		   //OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT, GET_OSD_BACKLIGHT());
#else
			//OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT, GET_OSD_BRIGHTNESS());
#endif
	
	   //			 OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST, GET_OSD_CONTRAST());
#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)
			// OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_BLACK_EQUALIZER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	  
		  //	  OsdDispSliderAndNumber(_MENU_PICTURE_BLACK_EQUALIZER, GET_OSD_BLACK_EQUALIZER1());
#endif
	
				  // OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_DCR, COLOR(_CP_BLUE, _CP_BG), _ENGLISH);	 
			   // OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_OFF,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //需定义	DCRON/OFF
	
				break;
			case _MENU_COLOR :
	
	
				
			   //Color
			  ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
			  ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
			   if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
			   {
				   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_RED, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_GREEN, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				   OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_BLUE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());  
			   }
			   else 
			   {
				   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_RED, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	 
				   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_GREEN, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	 
				   OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_BLUE, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());  
			   }
			   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLORTEMP, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
	/*					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_TEMP, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_COLOR_TEMP_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	  COLOR_TEMP
			   
			   if(GET_OSD_STATE()==_MENU_COLOR_TEMPERATURE_ADJUST)
			   {
					   OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_3, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL), (_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_ORANGE_H, _CP_BG);
			   }
			   
						OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_COLOR_EFFECT, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_4_COL), _PFONT_PAGE_1,_STRING_Color_Effect_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	COLOR_EFECT
			   
#if(_USER_FUNCTION_FPS1_FPS2==_ON)    
						 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_Gama_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	COLOR_GAMA
				   if((GET_OSD_COLOR_EFFECT()==_COLOREFFECT_VIVID)||(GET_OSD_COLOR_EFFECT()==_COLOREFFECT_USER))
				   {
			   
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_GAMMA, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());    
							 OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_4, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_6_COL), WIDTH(_OSD_SLIDE_VALUE_OFFSET+2), HEIGHT(1), _CP_GRAY_1, _CP_GRAY, _CP_BG);
				   }
			   
				   else
				   {
			   
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_GAMMA, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
			   
				   }
#else
					   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_GAMMA, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_Gama_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	COLOR_GAMA
			   
#endif
					   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_HUE, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
							  OsdDispSliderAndNumber(_MENU_COLOR_HUE, GET_OSD_HUE());////需确认    COLOR_hue
			   
						OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_SATURATION, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
							  OsdDispSliderAndNumber(_MENU_COLOR_SATURATION, GET_OSD_SATURATION());///需确认	COLOR_SATURATION
			   
#if(_USER_FUNCTION_LOW_BLUE_LIGHT==_ON)
						OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_LOW_BLUE_LIGHT_ADJUST, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_2_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,ONOFF_TABLE1[GET_OSD_LOWBLUELIGHT_STATUS()],COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	_STRING_DDCCI
#endif
			   */
			   //		OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_PANEL_UNIFORMITY, COLOR(_CP_BLUE, _CP_BG), _ENGLISH);	 
				 // 		   OsdPropPutOptionString(ROW(_OSD_NUMBER_3_ROW),COL(_OSD_NUMBER_4_COL), _PFONT_PAGE_1,_STRING_OFF,COLOR(_CP_BLUE, _CP_BG), _ENGLISH);////需确认	COLOR_UNIFORMITY
			   break;
	
	
			case _MENU_OSDSETTINGS:
			   //OSDSETTINGS
			   ScalerOsdWindowDisable(_OSD_WINDOW_4_4);
			   ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
			   ScalerOsdWindowDisable(_OSD_WINDOW_4_3);
			   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OSDSET_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());    
				   //  OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_Language_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	 LANGUAGE 
			   
				OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OSDSET_HORIZONTAL, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
				   //  OsdDispSliderAndNumber(_MENU_OTHER_OSD_HPOS, GET_OSD_HPOS());//
			   
				OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OSDSET_VERTICAL, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
				   //  OsdDispSliderAndNumber(_MENU_OTHER_OSD_VPOS, GET_OSD_VPOS());//
				 
			   OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OSDSET_OSDTIMEOUT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				   //  OsdDispSliderAndNumber(_MENU_OTHER_MENU_TIME, GET_OSD_TIME_OUT());//
			   
				 OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OSDSET_TRANSPARENCY, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
						  //	OsdDispSliderAndNumber(_MENU_OTHER_TRNASPARENCY, GET_OSD_TRANSPARENCY_STATUS());//
			   
					/*	 OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_RESET, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
			   
			   
						OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_INFORMATION, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());   
					   OsdDispShowInformation();
			   
					   if(GET_OSD_FactoryIn_TYPE()==_ON)
					   { 
					   OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_FACTORY, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
							}*/
			   
			   /*
	 #if(_ULTRA_VIVID_FUNC ==_OFF)
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_ULTRA_VIVID, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	 
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_UltraVivid_TABLE1,COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE()); //需确认	 _STRING_ULTRA_VIVID
	 #else
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_ULTRA_VIVID, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_UltraVivid_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	  _STRING_ULTRA_VIVID
	 #endif
			   
		#if(_ASPECT_RATIO_SUPPORT == _ON)
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_ASPECT_RATIO, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_4_COL), _PFONT_PAGE_1,_STRING_Aspect_Ratio_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	_STRING_ASPECT_RATIO
		#else
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_ASPECT_RATIO, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	  
							 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_4_COL), _PFONT_PAGE_1,_STRING_Aspect_Ratio_TABLE1,COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE()); //需确认    _STRING_ASPECT_RATIO
		#endif
			   
			   
 #if((_USE_TIME_SUPPORT == _ON)&&(_OD_FUNCTION == _ON))  
								   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_OD, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
								 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,ONOFF_TABLE1[GET_OSD_OD_STATUS()],COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	  _STRING_ASPECT_RATIO
				
								   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_USE_TIME, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    
								 OsdPropPutOptionString(ROW(_OSD_NUMBER_2_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_USE_TIME_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH); //需确认	  _STRING_ASPECT_RATIO
#elif(_OD_FUNCTION == _ON)
								   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_OD, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
								 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,ONOFF_TABLE1[GET_OSD_OD_STATUS()],COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	  _STRING_ASPECT_RATIO
#elif(_USE_TIME_SUPPORT == _ON)
								   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_USE_TIME, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    
								 OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_USE_TIME_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH); //需确认	  _STRING_ASPECT_RATIO
			   
#endif
			   */
			   
					   break;
	
	
			case _MENU_SETUP:
	//SETUP
				OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_SETUP_INPUT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
			//	OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_SETUP_AUDIOMUTE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_SETUP_AUDIO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_SETUP_RESET, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
	
				break;
	
	
	  /*		 case _MENU_DISPLAY:
	//Dispaly
		 /*
	
     #if(_VGA_SUPPORT == _ON)
	
					if(SysSourceGetInputPort() == _SOURCE_VGA)
					 {
					 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_AUTO_ADJUST, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
					 
					 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_HPOS, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
					 OsdDispSliderAndNumber(_MENU_DISPLAY_HPOS, GET_VGA_MODE_ADJUST_H_POSITION());
					 
					 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_VPOS, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
					 OsdDispSliderAndNumber(_MENU_DISPLAY_VPOS, GET_VGA_MODE_ADJUST_V_POSITION());
					 
					 OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_CLOCK, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
					 OsdDispSliderAndNumber(_MENU_DISPLAY_CLOCK, GET_VGA_MODE_ADJUST_CLOCK());
					 
					 OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_PHASE, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
					 OsdDispSliderAndNumber(_MENU_DISPLAY_PHASE,GET_VGA_MODE_ADJUST_PHASE());
					 }
				else
    #endif
					{
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_2, _STRING_AUTO_ADJUST, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	  
			
					 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_HPOS, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	
						   OsdDispSliderAndNumber(_MENU_DISPLAY_HPOS, 0);
			
						   OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_VPOS, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());	  
						   OsdDispSliderAndNumber(_MENU_DISPLAY_VPOS, 0);
			
						   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_CLOCK, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());    
						   OsdDispSliderAndNumber(_MENU_DISPLAY_CLOCK, 0);
			
						   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_PHASE, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());    
						   OsdDispSliderAndNumber(_MENU_DISPLAY_PHASE,0);
					  }
				   OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_SHARPNESS, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
				   OsdDispSliderAndNumber(_MENU_PICTURE_SHARPNESS, GET_OSD_SHARPNESS());//GET_VGA_MODE_ADJUST_PHASE()
	
				break;
	*/
	
	
	/*
	
			case  _MENU_INPUT:
				
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_AUTO_SELECT, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
				COsdShowPageInputText();
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_D0_DP, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
			  
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_D1_HDMI1, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
	
			 OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_D2_HDMI2, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
	
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_D3_DVI, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
	
			break;
	*/
	
	   //	  case	_MENU_SETUP:
	
	//AUDIO
	/*
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_VOLUME, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    
				OsdDispSliderAndNumber(_MENU_AUDIO_VOLUME, GET_OSD_VOLUME());//
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_MUTE, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
				  OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_4_COL), _PFONT_PAGE_1,ONOFF_TABLE1[GET_OSD_VOLUME_MUTE()],COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //GET_OSD_VOLUME_MUTE() 
	*/
			// OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_STAND_ALONG, COLOR(_CP_BLUE, _CP_BG), _ENGLISH);    
				 // OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_OFF,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //GET_OSD_AUDIO_STAND_ALONE
	/*
	#if((GUEST_TYPE == _LANCHUANG_GUEST) && ((_PCB_TYPE == _RL6432_SM2785G_1A1H_LVDS) || (_PCB_TYPE == _RL6193_SM2796G_1DP2HDMIDVI_LVDS_eDP)))
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_AUDIO_SOURCE, COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE());    
				  OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_Audio_Source_TABLE1,COLOR(_CP_GRAY, _CP_BG), GET_OSD_LANGUAGE()); //GET_OSD_AUDIO_SOURCE
	#else
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_AUDIO_SOURCE, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
				  OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_6_COL), _PFONT_PAGE_1,_STRING_Audio_Source_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //GET_OSD_AUDIO_SOURCE
	#endif
	*/
		//	  OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_SOUND_MODE, COLOR(_CP_BLUE, _CP_BG), _ENGLISH);	 
			//		OsdPropPutOptionString(ROW(_OSD_NUMBER_2_ROW),COL(_OSD_NUMBER_4_COL), _PFONT_PAGE_1,_STRING_OFF,COLOR(_CP_BLUE, _CP_BG), _ENGLISH); //需定义SOUND_MODE
	
	   //			break;
	
	
			case  _MENU_OTHER:
				ScalerOsdWindowDisable(_OSD_WINDOW_4_1);
				ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
				OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_DISPLAY_SIZE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_LOW_BLUE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_OVER_DRIVER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
				OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_OTHER_FREESYNC, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
	
	/*
	//OTHER
			OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_LANGUAGE, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	
				  OsdPropPutOptionString(ROW(_OSD_NUMBER_1_ROW),COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_1,_STRING_Language_TABLE1,COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE()); //需确认	LANGUAGE 
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_OSD_HPOS, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
				  OsdDispSliderAndNumber(_MENU_OTHER_OSD_HPOS, GET_OSD_HPOS());//
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_OSD_VPOS, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
				  OsdDispSliderAndNumber(_MENU_OTHER_OSD_VPOS, GET_OSD_VPOS());//
			  
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_MENU_TIME, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
				  OsdDispSliderAndNumber(_MENU_OTHER_MENU_TIME, GET_OSD_TIME_OUT());//
	
			  OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_TRANSPARENCY, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
				   OsdDispSliderAndNumber(_MENU_OTHER_TRNASPARENCY, GET_OSD_TRANSPARENCY_STATUS());//
	
			OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_RESET, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	 
	
	
			 OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_INFORMATION, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());   
			OsdDispShowInformation();
	
			if(GET_OSD_FactoryIn_TYPE()==_ON)
			{ 
			OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_FACTORY, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    
				 }
			*/
			  break;
	
	/*
			case  _MENU_COLOR_TEMP_USER_R:	
				
				
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), _PFONT_PAGE_1, _STRING_COLOR_TEMP_USER_R, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
				OsdDispSliderAndNumber(_MENU_COLOR_TEMP_USER_R, GET_COLOR_TEMP_TYPE_USER_R());
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_3_COL), _PFONT_PAGE_1, _STRING_COLOR_TEMP_USER_G, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
				 OsdDispSliderAndNumber(_MENU_COLOR_TEMP_USER_G, GET_COLOR_TEMP_TYPE_USER_G());
	
			 OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_5_COL), _PFONT_PAGE_1, _STRING_COLOR_TEMP_USER_B, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());	  
				  OsdDispSliderAndNumber(_MENU_COLOR_TEMP_USER_B, GET_COLOR_TEMP_TYPE_USER_B());
				  break;
	*/
			default:
				;
		}
	}
void COsdShowChoosePictureText(BYTE number)
{
			CLR_KEYREPEATENABLE();
	/*		_Countstar=0,
			_LANGUAGE,
			_HORIZONTAL,
			_VERTICAL,
			_TRANSPARENCY,
			_OSDTIMEOUT,
			_FONT_AMOUNT,
	*/
		
			switch(number)
			{
				case _STRING_BACKLIGHT:
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_BACKLIGHT(), _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER);        
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_0+3, _OSD_NUMBER_UNSTLECT_COLOR);	
	
					break;
	
	
		
				case _STRING_CONTRAST :
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_CONTRAST(), _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER);        
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_1+3, _OSD_NUMBER_UNSTLECT_COLOR);	
		
	
					break;
	
				case _STRING_ECO:
					if(GET_OSD_COLOR_EFFECT()==_PICTURE_STANDARD)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_1_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_GAME)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_2_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_MOVIE)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_3_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_PHOTO)
					{
						OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  

					}
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_USER)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_11_ROW, _OSD_NUMBER_11_COL, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_FPS)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_12_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_12_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_RTS)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_13_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_13_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_STANDARD, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_MOVE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_PHOTO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_GAME, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_FPS, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
					OsdPropPutString(ROW(_OSD_NUMBER_12_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_RTS, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_13_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_USER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
					break;
		
				case _STRING_MAINSR:
					/*
					if(GET_PICTURE_MAIN_SR()==_PICTURE_MAINSR_OFF)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_1_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_OSD_COLOR_EFFECT()==_PICTURE_MAINSR_WEAK)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_2_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						GET_PICTURE_MAIN_SR(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_PICTURE_MAIN_SR()==_PICTURE_MAINSR_MEDIAN)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_3_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					else if(GET_PICTURE_MAIN_SR()==_PICTURE_MAINSR_STRONG)
					{
						OsdFontPut1ChooseIcon(_OSD_NUMBER_4_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);

					}
					else if(GET_PICTURE_MAIN_SR()==_PICTURE_MAINSR_STRONGEST)
					{
						//OsdFontPut1ChooseIcon(_OSD_NUMBER_11_ROW, _OSD_NUMBER_2_COL+10, _CHOOSE_ICON,_CP_WHITE, _CP_BLUE_65);
						OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  
					}
					
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_PICTURE_OFF, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_PICTURE_WEAK, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_PICTURE_MEDIAN, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_PICTURE_STRONG, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
					OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_PICTURE_STRONGEST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
*/


					break;
	
		
				default:
					 break;
			}
}

void COsdShowChooseColorText(BYTE number)
{
			CLR_KEYREPEATENABLE();
	/*		_Countstar=0,
			_LANGUAGE,
			_HORIZONTAL,
			_VERTICAL,
			_TRANSPARENCY,
			_OSDTIMEOUT,
			_FONT_AMOUNT,
	*/
		
			switch(number)
			{
				case _STRING_COLORTEMP:
					if(GET_COLOR_TEMP_TYPE()==_COLOR_6500K)
					{
						OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  

					}
					else if(GET_COLOR_TEMP_TYPE()==_COLOR_9300K)
					{
						OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  

					}
					else if(GET_COLOR_TEMP_TYPE()==_COLOR_USER_DEFINE)
					{
						OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T);  

					}
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_COLOR_6500K, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());    
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_COLOR_9300K, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());    
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_COLOR_USER_DEFINE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());    
					break;
	
	
		
				case _STRING_COLOR_RED :
					//g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					//g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);

					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_R(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_6, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_6+3, _OSD_NUMBER_UNSTLECT_COLOR);	


					break;
	
				case _STRING_COLOR_GREEN:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_G(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_7, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_7+3, _OSD_NUMBER_UNSTLECT_COLOR);	
	
		
					break;
		
				case _STRING_COLOR_BLUE:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_COLOR_TEMP_TYPE_USER_B(), _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_8, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_8+3, _OSD_NUMBER_UNSTLECT_COLOR);	
					break;
	
		
		
				default:
					 break;
			}
}
void COsdShowChooseOSDSetText(BYTE number)
{
			CLR_KEYREPEATENABLE();
	/*		_Countstar=0,
			_LANGUAGE,
			_HORIZONTAL,
			_VERTICAL,
			_TRANSPARENCY,
			_OSDTIMEOUT,
			_FONT_AMOUNT,
	*/
		
			switch(number)
			{
				case _STRING_OSDSET_LANGUAGE:
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_12_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_13_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					if(GET_OSD_LANGUAGE()==_ENGLISH)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					else if(GET_OSD_LANGUAGE()==_ESPANA)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_2_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					else if(GET_OSD_LANGUAGE()==_FRENCH)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_3_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					else if(GET_OSD_LANGUAGE()==_GERMAN)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_2, ROW(_OSD_NUMBER_4_ROW),  COL(_OSD_NUMBER_11_COL-1), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					else if(GET_OSD_LANGUAGE()==_ITALIANO)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_11_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					else if(GET_OSD_LANGUAGE()==_KOREAN)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_12_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					else if(GET_OSD_LANGUAGE()==_CHINESE_T)
					{
						ScalerOsdWindowDisable(_OSD_WINDOW_4_2);
						ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
						OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_13_ROW),  COL(_OSD_NUMBER_2_COL+9), WIDTH(4), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					}
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _ENGLISH); 
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _ESPANA);
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _FRENCH); 
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _GERMAN);
					OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _ITALIANO); 
					OsdPropPutString(ROW(_OSD_NUMBER_12_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _KOREAN);
					OsdPropPutString(ROW(_OSD_NUMBER_13_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _CHOOSE_LANGUAGE, COLOR(_CP_WHITE, _CP_BG), _CHINESE_T); 

	
					break;
	
	
		
				case _STRING_OSDSET_HORIZONTAL :
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_HPOS(), _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_0+3, _OSD_NUMBER_UNSTLECT_COLOR);	
	
					break;
	
				case _STRING_OSDSET_VERTICAL:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_VPOS(), _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_3, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_0+3, _OSD_NUMBER_UNSTLECT_COLOR);	
		
		
	
		
					break;
		
				case _STRING_OSDSET_TRANSPARENCY:
					
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_TRANSPARENCY_STATUS(), _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_4, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_0+3, _OSD_NUMBER_UNSTLECT_COLOR);	
		
					break;
	
		
				case  _STRING_OSDSET_OSDTIMEOUT:
					g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_TIME_OUT(), _OSD_TIMEOUT_MAX, _OSD_TIMEOUT_MIN, _OSD_TIMEOUT_CENTER);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),g_usAdjustValue, _SLIDER_5, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_0+3, _OSD_NUMBER_UNSTLECT_COLOR);	
		
					break;
		
				default:
					 break;
			}
}


void COsdShowChooseSetupText(BYTE number)
{
			CLR_KEYREPEATENABLE();
		
			switch(number)
			{
				case _STRING_SETUP_INPUT:
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					ScalerOsdWindowDisable(_OSD_WINDOW_4_6);
					g_usBackupValue = GET_OSD_INPUT_PORT_OSD_ITEM();
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					break;
				case _STRING_SETUP_AUDIOMUTE:
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					g_usBackupValue = GET_OSD_VOLUME_MUTE();
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_OFF, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_ON, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					break;
	
		
				case _STRING_SETUP_AUDIO :
                    g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_VOLUME(), _OSD_VOLUME_MAX, _OSD_VOLUME_MIN, _OSD_VOLUME_CENTER);        
					//g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(GET_OSD_VOLUME(), _OSD_VOLUME_MAX, _OSD_VOLUME_MIN, _OFF);
					OsdWindowSlider(ROW(_OSD_NUMBER_10_ROW), COL(_OSD_NUMBER_10_COL),GET_OSD_VOLUME(), _SLIDER_9, _UNSELECT);
					OsdPropShowNumber(ROW(_OSD_NUMBER_10_ROW-2), COL(_OSD_NUMBER_10_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _SLIDER_1+3, _OSD_NUMBER_UNSTLECT_COLOR);	
	
					break;
	

		
				default:
					 break;
			}
}

void COsdShowChooseOtherText(BYTE number)
{
			CLR_KEYREPEATENABLE();
	/*		_Countstar=0,
			_LANGUAGE,
			_HORIZONTAL,
			_VERTICAL,
			_TRANSPARENCY,
			_OSDTIMEOUT,
			_FONT_AMOUNT,
	*/
		
			switch(number)
			{
				case _STRING_OTHER_DISPLAY_SIZE:
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	

					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_FULLSCREEN, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_AUTO, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_4_3, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					g_usBackupValue = GET_OSD_ASPECT_RATIO_TYPE();
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					break;
	
	
		
				case _STRING_OTHER_LOW_BLUE :
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_5_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	

					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_OFF, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_WEAK, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_MEDIAN, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_STRONG, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_11_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_STRONGEST, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					g_usBackupValue = GET_OSD_LOWBLUELIGHT_STATUS();
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					break;
	
				case _STRING_OTHER_OVER_DRIVER:
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_OFF, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_ON, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					g_usBackupValue = GET_OSD_OD_STATUS();
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*g_usBackupValue)),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
		
	
		
					break;
		
				case _STRING_OTHER_FREESYNC:
					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_11_COL), _PFONT_PAGE_2, _ICON_CHOOSE, COLOR(_CP_BLUE_65, _CP_BG), _CHINESE_T);	

					OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_OFF, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdPropPutString(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_OTHER_ON, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	 
					OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_6, ROW(_OSD_NUMBER_1_ROW+(3*GET_OSD_FREE_SYNC_STATUS())),  COL(_OSD_NUMBER_2_COL-1), WIDTH(_OSD_WINDOW_CHOOSE_WIDTH_1), HEIGHT(1), _CP_BLACK, _CP_WHITE, _CP_BG);
					break;
	

		
				default:
					 break;
			}
}


void COsdShowChooseLeftMenuText(BYTE number)
{
			CLR_KEYREPEATENABLE();
	/*		_Countstar=0,
			_LANGUAGE,
			_HORIZONTAL,
			_VERTICAL,
			_TRANSPARENCY,
			_OSDTIMEOUT,
			_FONT_AMOUNT,
	*/
		
			switch(number)
			{
				case _STRING_LEFT_MENU_AIM:
					OsdFontPut1BitMainMenuIcon(10, 14, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_WHITE);
					//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,3);
					OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
					
					OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG);
					OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	
					
					OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
					OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);	
					
					OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
					OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);  
	
					break;
	
	
		
				case _STRING_LEFT_MENU_TIMER :
					OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,1);	
					OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					
					OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,2); 	
					OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);

					OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,3); 	
					OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);

					OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,4); 	
					OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);

					OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,5); 	
					OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);

					OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,6); 	
					OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);

					OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_WHITE,_CP_BLUE_65,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,9); 	
					OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
					OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,10);
					OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);	
					OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLUE_65,0);
	
					break;
	
				default:
					 break;
			}
}



void OsdDispLeftMenu(void)
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
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BLUE_65 );
		OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_2, _STRING_GAME_MENU, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		if(GET_OSD_Left_Menu_Choose()==_LEFT_AIM)
		{

			SET_OSD_STATE(_Menu_LEFTKEY_GAME);
			OsdThreeColorChooseTableForm(7, 13,_EDGE_LINE,22 ,10,_CP_WHITE, _CP_BLUE_65,_CP_WHITE,0);
			OsdThreeColorChooseTableForm(7, 40,_EDGE_LINE,22 ,10,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
			OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_ORANGE_H, _CP_WHITE);	 
			OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_WHITE, _CP_BG);
		}
		else 
		{

			SET_OSD_STATE(_Menu_LEFTKEY_TIMER);
			OsdThreeColorChooseTableForm(7, 13,_EDGE_LINE,22 ,10,_CP_WHITE, _CP_BLUE_65,_CP_BLUE_65,0);
			OsdThreeColorChooseTableForm(7, 40,_EDGE_LINE,22 ,10,_CP_WHITE, _CP_BLUE_65,_CP_WHITE,0);
			OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_WHITE, _CP_BG);	 
			OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_ORANGE_H, _CP_WHITE);

		}
  //background    
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

 void OsdDispLeftAimMenu(void)
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
 
	 OsdFuncApplyMap(WIDTH(_OSD_LEFT_KEY_AIM_WIDTH), HEIGHT(_OSD_LEFT_KEY_AIM_HEIGHT), COLOR(_CP_BG, _CP_BG));
 
 //20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
	 ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_LEFT_KEY_AIM_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
 
	 //OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
	 OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
 
	 // Adjust Color Palette
	 OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
	 
	 OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);	
	 OsdFuncTransparency(255); 
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
	 OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BG );
	 
	 //OsdFontPut1BitMainMenuIcon(0, 0, _LEFT_MENU_AIM_ICON_START+24 , _CP_BG, _CP_BG);
	 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
	 
	 switch(GET_OSD_AIM())
	 {
		 case _AIM_1:
			 
	 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+24 , _CP_GREEN_119, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
		 case _AIM_2:
			 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
		 case _AIM_3:
	 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
		 case _AIM_4:
	 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
			 
		  default:
			  break;
	 }
 
   //background    
	 }
 
	 
	 
 
	 OsdDispSetPosition(_POS_PERCENT, 50, 50);
 
 
 
	 // Osd Enable
	 ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	 OsdFuncEnableOsd();
 
 }

//OsdDispLeftTimerMenuAdjust

void OsdDispRightMenu(void)
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

    OsdFuncApplyMap(WIDTH(_OSD_RIGHT_KEY_WIDTH), HEIGHT(_OSD_RIGHT_KEY_HEIGHT), COLOR(_CP_BLUE_120, _CP_BG));

//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_RIGHT_KEY_HEIGHT), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    //OsdFontVLCLoadFont(_FONT2_ICON_MENU);
	 OsdFontVLCLoadFont(_FOUR_CORNER);
	OsdFontVLCLoadFont(_MAIN_MENU_2BIT_ICON);

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
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(0), WIDTH(g_ucOsdWidth-2), HEIGHT((g_ucOsdHeight-2)), _CP_BLUE_65 );
		OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLUE_65,_CP_BG,_QUADRANGLE_WINDOW_0);
		OsdFontPut1FuncHLine(1, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLUE_65);
		OsdFontPut1FuncHLine(8, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLUE_65);



      
    }


	
	

    OsdDispSetPosition(_POS_PERCENT, 50, 50);



    // Osd Enable
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();

}

void OsdDispMainMenu(void)
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
 //ScalerSetBit(P3A_43_FRAME_CTRL_43, ~(_BIT6|_BIT5|_BIT4|_BIT3|_BIT2), 0x24);

    OsdFuncApplyMap(WIDTH(_OSD_MAIN_MENU_WIDTH), HEIGHT(_OSD_MAIN_MENU_HEIGHT), COLOR(_CP_BLUE_120, _CP_BG));

//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    //OsdFontVLCLoadFont(_FONT2_ICON_MENU);
	 OsdFontVLCLoadFont(_FOUR_CORNER);
	OsdFontVLCLoadFont(_MAIN_MENU_2BIT_ICON);
	

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
        //OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( g_ucOsdHeight/2), _CP_BLUE_120);
       // OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( g_ucOsdHeight/2+1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)), _CP_BLUE_120 );//_CP_LIGHTBLUE
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(1), WIDTH(g_ucOsdWidth-2), HEIGHT((g_ucOsdHeight-2)), _CP_BLUE_65 );
		OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLUE_65,_CP_BG,_QUADRANGLE_WINDOW_0);
		OsdFontPut1FuncHLine(1, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLUE_65);
		OsdFontPut1FuncHLine(24, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLUE_65);
		OsdFontPut1FuncTableForm(2, 20, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_GRID_WINDOW_0);
		OsdFontPut1FuncTableForm(2, 37, _EDGE_LINE,13 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
		OsdFontPut1FuncTableForm(2, 54, _EDGE_LINE,16 ,20,_CP_WHITE,_CP_BLUE_65,_ARC_WINDOW_0);
    }
		//OsdFontPut2BitTable(ROW(8), COL(8), tiOSD_MAIN_COLORTEMP_ICON, (_PALETTE_INDEX0 << 4) | COLOR0(_CP_BLUE_120) ,COLOR1(_CP_BLACK) ,COLOR2(_CP_YELLOW) ,COLOR3(_CP_WHITE));

		OsdFontPut2BitTable(ROW(_OSD_NUMBER_5_ROW), COL(_OSD_NUMBER_7_COL), tiOSD_MAIN_BIR_ICON, (_PALETTE_INDEX0 << 4) | COLOR0(_CP_BLUE_65) ,COLOR1(_CP_BLACK) ,COLOR2(_CP_YELLOW) ,COLOR3(_CP_WHITE));
		OsdFontPut1FuncHLine(6, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdPropPutString(ROW(4), COL(7), _PFONT_PAGE_0, _STRING_PICTURE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());

       	OsdFontPut2BitTable(ROW(_OSD_NUMBER_6_ROW), COL(_OSD_NUMBER_7_COL), tiOSD_MAIN_COLORTEMP_ICON, (_PALETTE_INDEX0 << 4) | COLOR0(_CP_BLUE_65) ,COLOR1(_CP_GREEN_66) ,COLOR2(_CP_GREEN_119) ,COLOR3(_CP_RED));
		OsdFontPut1FuncHLine(10, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdPropPutString(ROW(8), COL(7), _PFONT_PAGE_0, _STRING_COLOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		   
        OsdFontPut2BitTable(ROW(11), COL(2), tiOSD_MAIN_OSDSETTING_ICON, (_PALETTE_INDEX0 << 4) | COLOR0(_CP_BLUE_65) ,COLOR1(_CP_WHITE) ,COLOR2(_CP_BLUE_65) ,COLOR3(_CP_LIGHTBLUE));
		OsdFontPut1FuncHLine(14, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdPropPutString(ROW(12), COL(7), _PFONT_PAGE_0, _STRING_ADVANCE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		
		
		OsdFontPut2BitTable(ROW(15), COL(2), tiOSD_MAIN_MISC_ICON, (_PALETTE_INDEX0 << 4) | COLOR0(_CP_BLUE_65) ,COLOR1(_CP_WHITE) ,COLOR2(_CP_GREEN_66) ,COLOR3(_CP_BLUE_65));
		OsdFontPut1FuncHLine(18, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdPropPutString(ROW(16), COL(7), _PFONT_PAGE_0, _STRING_INPUT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());


		 
        OsdFontPut2BitTable(ROW(19), COL(2), tiOSD_MAIN_RESET_ICON, (_PALETTE_INDEX0 << 4) | COLOR0(_CP_BLUE_65) ,COLOR1(_CP_WHITE) ,COLOR2(_CP_BLACK) ,COLOR3(_CP_GREEN_66));
		OsdFontPut1FuncHLine(22, 2, _WHITE_EDGE_2, g_ucOsdWidth/5 ,_CP_WHITE, _CP_BLUE_65);
		OsdPropPutString(ROW(20), COL(7), _PFONT_PAGE_0, _STRING_OTHER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());

		OsdPropPutString(ROW(_OSD_NUMBER_4_ROW), COL(_OSD_NUMBER_1_COL+34), _PFONT_PAGE_0, _STRING_NOW_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);


#if(_PCB_TYPE == _RL6449_SM2775YTC_1DP2H_VBO)
switch(SysSourceGetInputPort())
{
			
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
				case _A0_INPUT_PORT:
					break;		
#endif   
	
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
				case _D0_INPUT_PORT:
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _FRENCH);  
					break;
#endif 
	/*
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
				case _D1_INPUT_PORT:
					OsdPropPutString(ROW(_OSD_NUMBER_4_ROW-2), COL(_OSD_NUMBER_1_COL+38), _PFONT_PAGE_0, _STRING_SETUP_DP, COLOR(_CP_WHITE, _CP_BG), _ESPANA);	
					break;
			// return _STRING_D1_PORT;
#endif 
*/	
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



#else

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

#endif



		
		COsdShowPageText(_MENU_PICTURE);

	
    OsdDispMainMenuItemSelection(0, _OSD_SELECT);
	

  /*
    
    // Realtek Mark
    OsdFontPut1BitTable( ROW(0), COL(32), tOSD_iREALTEK, COLOR(_CP_WHITE, _CP_BG));

    // Main Menu Icon & String
    if(GET_OSD_STATE() == _MENU_PICTURE)
    {
        OsdDispMainMenuIconPage(_UP, _ICON_PAGE_MAIN_0);
        OsdDispMainMenuIconPage(_DOWN, _ICON_PAGE_PICTURE_0);
        // Selection Arrow Indication
        OsdDispMainMenuCursor(GET_OSD_STATE(), GET_OSD_STATE_PREVIOUS(),_OUTSUBSET);
        
    }
    else if((GET_OSD_STATE() >= _MENU_INPUT_AUTO) && (GET_OSD_STATE() <= _MENU_INPUT_D6_PORT))
    {
        OsdDispMainMenuIconPage(_UP, _ICON_PAGE_MAIN_1);
        OsdDispMainMenuItemSelection(_ITEM_0, _OSD_PRE_SELECT);
        OsdDispMainMenuOptionSetting(_OPTION_INPUT_SOURCE_TYPE,_SELECT,SysSourceGetScanType());

        if((SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP) || (GET_OSD_STATE() <= _MENU_INPUT_D1_PORT))
        {
            OsdDispMainMenuIconPage(_DOWN, _ICON_PAGE_INPUT_0);
        }
        else if((GET_OSD_STATE() >= _MENU_INPUT_D2_PORT) || (GET_OSD_STATE() <= _MENU_INPUT_D5_PORT))
        {
            OsdDispMainMenuIconPage(_DOWN, _ICON_PAGE_INPUT_1);
        }    
        else
        {
            OsdDispMainMenuIconPage(_DOWN, _ICON_PAGE_INPUT_2);
        }
    }

    // key info
    OsdDispMainMenuKeyInfo(_KEY_INFO_ALL, _OSD_UNSELECT);
*/

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
// VLC
// font put 1 bit
// font put 1 bit table
// font put 2 bit
// font put 2 bit table
// font put 4 bit
// font put 4 bit color

// Prop
// font put prop string

// window 
// draw window    
/*
void OsdPropPutOptionString(BYTE ucRow, BYTE ucCol, BYTE ucFptsSelect, BYTE ucString, BYTE ucColor, BYTE ucLanguage)
    {
    OsdFuncClearOsd(ROW(ucRow), COL(ucCol+2), WIDTH(_OSD_SLIDE_VALUE_OFFSET-2), HEIGHT(1));

    OsdPropPutString(ucRow, ucCol+1, ucFptsSelect, _STRING_OPTION_LEFT, ucColor, _ENGLISH);
    OsdPropPutStringCenter( ucRow,  ucCol+1,_OSD_SLIDE_VALUE_OFFSET, ucFptsSelect, ucString, ucColor , ucLanguage);
    OsdPropPutString(ucRow, ucCol+_OSD_SLIDE_VALUE_OFFSET+1, ucFptsSelect, _STRING_OPTION_RIGHT, ucColor, _ENGLISH);
    }
*/
//--------------------------------------------------
// Description    : 
// Input Value    : None
// Output Value : None
//--------------------------------------------------


//void OsdDispSliderAndNumber(BYTE ucOsdState, WORD usValue)
//{

/*
    BYTE ucColor = 0;
    BYTE ucItemRow = 0;
    BYTE ucPFnotPageItem = 0;
    BYTE ucShowMax = 100;
    BYTE ucShowMin = 0;
    BYTE ucIndex = 0;

    g_usAdjustValue = usValue;

    
         if(SysSourceGetInputPort() == _SOURCE_VGA)
        {
            switch(ucOsdState)
                {

       case _MENU_DISPLAY_HPOS:
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

        case _MENU_DISPLAY_VPOS:
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_2, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

        case _MENU_DISPLAY_CLOCK:

                            
         #if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)
        g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 100, 0, 50);
         #else
        g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue,  UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX), UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN), ( UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX)+ UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN))/2+ UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN));
          #endif     
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_3, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

        case _MENU_DISPLAY_PHASE:
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_3, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_4, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;
            
         default:
           break;            
             }

        }
     else
     {
           switch(ucOsdState)
                {

       case _MENU_DISPLAY_HPOS:
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_GRAY_COLOR);            
            break;

        case _MENU_DISPLAY_VPOS:
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_2, _OSD_NUMBER_GRAY_COLOR);            
            break;

        case _MENU_DISPLAY_CLOCK:

                            
         #if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)
        g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, 100, 0, 50);
         #else
        g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue,  UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX), UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN), ( UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX)+ UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN))/2+ UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN));
          #endif     
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_3, _OSD_NUMBER_GRAY_COLOR);            
            break;

        case _MENU_DISPLAY_PHASE:
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_3, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_4, _OSD_NUMBER_GRAY_COLOR);            
            break;
            
         default:
           break;            
             }
     }
            switch(ucOsdState)
                {
        case _MENU_PICTURE_BACKLIGHT:
#if(_BACKLIGHT_SELECT == _BACKLIGHT_ADJ)

            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER);

#else
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _BRIGHTNESS_MAX, _BRIGHTNESS_MIN, _BRIGHTNESS_CENTER);

#endif

            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);
           OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF| _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;
            
      case _MENU_PICTURE_CONTRAST:
           g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_2, _OSD_NUMBER_UNSTLECT_COLOR);

            break;


#if(_USER_FUNCTION_BLACK_EQUALIZER==_ON)

      case _MENU_PICTURE_BLACK_EQUALIZER:
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_3, _OSD_NUMBER_UNSTLECT_COLOR);

            break;
#endif

    case _MENU_PICTURE_SHARPNESS:

            g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_SHARPNESS(), _SHARPNESS_MAX, _SHARPNESS_MIN, _SHARPNESS_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_6_COL),g_usAdjustValue, _SLIDER_4, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_6_COL+_OSD_SLIDE_VALUE_OFFSET), GET_OSD_SHARPNESS(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_5, _OSD_NUMBER_UNSTLECT_COLOR);

        break;
   



        
        case _MENU_COLOR_HUE:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _HUE_MAX, _HUE_MIN, _HUE_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

        case _MENU_COLOR_SATURATION:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _SATURATION_MAX, _SATURATION_MIN, _SATURATION_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_2, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

        case _MENU_COLOR_TEMP_USER_R:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);   
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;
            
        case _MENU_COLOR_TEMP_USER_G:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);  
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_2, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;
            
        case _MENU_COLOR_TEMP_USER_B:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _USER_RGB_MAX, _USER_RGB_MIN, _USER_RGB_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);                
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_3, _OSD_NUMBER_UNSTLECT_COLOR);            
        break;









        case _MENU_AUDIO_VOLUME:
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);
            break;





        case _MENU_OTHER_OSD_HPOS:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _OSD_H_POS_MAX, _OSD_H_POS_MIN, _OSD_H_POS_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_0, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), GET_OSD_HPOS(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);            

        break;

        case _MENU_OTHER_OSD_VPOS:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _OSD_V_POS_MAX, _OSD_V_POS_MIN, _OSD_V_POS_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL),g_usAdjustValue, _SLIDER_1, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_6_COL+_OSD_SLIDE_VALUE_OFFSET), GET_OSD_VPOS(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_2, _OSD_NUMBER_UNSTLECT_COLOR);            

            break;

         case _MENU_OTHER_MENU_TIME:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _OSD_TIMEOUT_MAX, _OSD_TIMEOUT_MIN, _OSD_TIMEOUT_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL),g_usAdjustValue, _SLIDER_2, _UNSELECT);
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET), GET_OSD_TIME_OUT(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_5, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

        case _MENU_OTHER_TRNASPARENCY:
            g_usAdjustValue = UserCommonAdjustRealValueToPercent(g_usAdjustValue, _OSD_TRANSPARENCY_MAX, _OSD_TRANSPARENCY_MIN, _OSD_TRANSPARENCY_CENTER);
            OsdWindowSlider(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL),g_usAdjustValue, _SLIDER_3, _UNSELECT);
           // OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), GET_OSD_TRANSPARENCY_STATUS(), (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_4, _OSD_NUMBER_UNSTLECT_COLOR);            
            OsdPropShowNumber(ROW(_OSD_NUMBER_2_ROW), COL(_OSD_NUMBER_4_COL+_OSD_SLIDE_VALUE_OFFSET), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_ITEM_4, _OSD_NUMBER_UNSTLECT_COLOR);            
            break;

       default:
           break;            
    }
*/
//}
//--------------------------------------------------
// Description    : 
// Input Value    : None
// Output Value : None
//--------------------------------------------------
	


//--------------------------------------------------
// Description    : 
// Input Value    : None
// Output Value : None
//--------------------------------------------------
WORD OsdDisplayDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle)
{


			switch(GET_KEYMESSAGE())
			{
				case _LEFT_KEY_MESSAGE:
                           if((GET_OSD_STATE() == _MENU_PICTURE_ECO_ADJUST)||(GET_OSD_STATE() == _MENU_COLOR_TEMPERATURE_ADJUST)||(GET_OSD_STATE() == _MENU_OSDSETTINGS_LANGUAGE_ADJUST)\
				||(GET_OSD_STATE() == _MENU_OTHERS_DISPLAY_SIZE_ADJUST)||(GET_OSD_STATE() == _MENU_OTHERS_LOW_BLUE_LIGHT_ADJUST))		   	
                           	{
              		            if (ucValue <= ucMin)
             		            {
             		                if(bCycle == _ON)
             		                {
             		                    return ucMax;
             		                }
             		                else
             		                {
             		                    return ucMin;
             		                }
             		            }
             		            else
             		            {
             		                ucValue--;
             		            }

                           }
		           else
                           	{
         		            if (ucValue >= ucMax)
         		            {
         		                if(bCycle == _ON)
         		                {
         		                    return ucMin;
         		                }
         		                else
         		                {
         		                    return ucMax;
         		                }
         		            }
         		            else
         		            {
         		                ucValue++;
         		            }
                           }				   
            	break;

        		case _RIGHT_KEY_MESSAGE:

                           if((GET_OSD_STATE() == _MENU_PICTURE_ECO_ADJUST)||(GET_OSD_STATE() == _MENU_COLOR_TEMPERATURE_ADJUST)||(GET_OSD_STATE() == _MENU_OSDSETTINGS_LANGUAGE_ADJUST)\
				||(GET_OSD_STATE() == _MENU_OTHERS_DISPLAY_SIZE_ADJUST)||(GET_OSD_STATE() == _MENU_OTHERS_LOW_BLUE_LIGHT_ADJUST))		   	
                           	{
         		            if (ucValue >= ucMax)
         		            {
         		                if(bCycle == _ON)
         		                {
         		                    return ucMin;
         		                }
         		                else
         		                {
         		                    return ucMax;
         		                }
         		            }
         		            else
         		            {
         		                ucValue++;
         		            }
                           }
		           else
                           	{
              		            if (ucValue <= ucMin)
             		            {
             		                if(bCycle == _ON)
             		                {
             		                    return ucMax;
             		                }
             		                else
             		                {
             		                    return ucMin;
             		                }
             		            }
             		            else
             		            {
             		                ucValue--;
             		            }

                           }						

		        break;

	        	default:
	            	break;
				
   			
    	}

    return ucValue;
}
/*
WORD OsdLanguageDetOverRange(WORD ucValue, WORD ucMax, WORD ucMin, bit bCycle)
{


			switch(GET_KEYMESSAGE())
			{
				case _RIGHT_KEY_MESSAGE:
				case _LEFT_KEY_MESSAGE:
					if (ucValue >= ucMax)
					{
						if(bCycle == _ON)
						{
							return ucMin;
						}
						else
						{
							return ucMax;
						}
					}
					else
					{
						ucValue++;
					}
				
				
					break;
					
					default:
					break;


		}

    return ucValue;
}
*/
//--------------------------------------------------
// Description  : Six Color Get One Color
// Input Value  : SixColor
// Output Value : None
//--------------------------------------------------
void OsdDisplaySixColorGetOneColor(BYTE ucColor)
{
    switch(ucColor)
    {
        case _SIXCOLOR_R:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueR);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationR);
            break;

        case _SIXCOLOR_Y:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueY);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationY);
            break;

        case _SIXCOLOR_G:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueG);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationG);
            break;

        case _SIXCOLOR_C:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueC);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationC);
            break;

        case _SIXCOLOR_B:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueB);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationB);
            break;

        case _SIXCOLOR_M:
            SET_OSD_SIX_COLOR_HUE(g_stSixColorData.ucSixColorHueM);
            SET_OSD_SIX_COLOR_SATURATION(g_stSixColorData.ucSixColorSaturationM);
            break;
    }
}

/*
void OsdDispHotKeySourceMenu(void)
{  
		BYTE gc_row1,  gc_row2, gc_col1, gc_high, gc_long;
	   
#if(_OSTAR_OSD_SMALL == _ON)
		 gc_row1 = 1;
		 gc_row2 = 5;
		 gc_col1 = 4;
		 gc_high = 7;
		 gc_long = 14;
#else
		 gc_row1 = 3;
		 gc_row2 = 8;
		 gc_col1 = 6;
		 gc_high = 11;
		 gc_long = 18;
#endif

    OsdFuncDisableOsd();
     OsdFuncCloseWindow(_OSD_WINDOW_ALL);

    OsdFuncApplyMap(WIDTH(_OSD_INPUT_AMOUNT*gc_long), HEIGHT(gc_high), COLOR(_CP_LIGHTBLUE, _CP_BG));    //Leixe yaya 

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(gc_high), _DISABLE, 0, _ENABLE);  
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()); 

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    
    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_BLUE_120);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(52), g_ucOsdWidth, _CP_LIGHTBLUE);    
    }
    else
#endif         
    {        
       // OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdHeight, _CP_BLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight, _CP_GREEN_119);     
    }

  
    // title
    // icon


     OsdFontVLCDynamicLoadIcon( _ICON_HOTKEY_AUTO_POS, _ICON_INPUT_AUTO);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
        OsdPropPutStringCenter( ROW(gc_row2), COL(0), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_AUTO_SELECT, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());
#if(_A0_PORT_SHIELD==_OFF)
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect(_ICON_HOTKEY_A0_POS, _OSD_INPUT_A0);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_A0)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_A0 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_A0,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_A0), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
    //    OsdPropPutString(ROW(8), COL(5+(18*_OSD_INPUT_A0) ), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
#endif 
#endif 
#if(_D0_PORT_SHIELD == _OFF)
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect(_ICON_HOTKEY_D0_POS, _OSD_INPUT_D0);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D0)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D0 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D0,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D0), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
    //    OsdPropPutString(ROW(8), COL(5+(18*_OSD_INPUT_A0) ), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
#endif   
#endif
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect(_ICON_HOTKEY_D1_POS, _OSD_INPUT_D1);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D1)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D1 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D1,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D1), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
    //    OsdPropPutString(ROW(8), COL(5+(18*_OSD_INPUT_A0) ), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
#endif  

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect(_ICON_HOTKEY_D2_POS, _OSD_INPUT_D2);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D2)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D2 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D2,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D2), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
#endif    

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect( _ICON_HOTKEY_D3_POS,_OSD_INPUT_D3);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D3)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D3 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D3,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D3), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
#endif    

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect(_ICON_HOTKEY_D4_POS, _OSD_INPUT_D4);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D4)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D4 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D4,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D4), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
#endif    

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect( _ICON_HOTKEY_D5_POS,_OSD_INPUT_D5);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D5)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D5 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D5,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D5), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
#endif    

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
    OsdFontVLCDynamicLoadIconSelect(_ICON_HOTKEY_D6_POS, _OSD_INPUT_D6);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*_OSD_INPUT_D6)), (_1DYNAMIC_ICON_START + (_OSD_INPUT_D6 * 24)), _CP_LIGHTBLUE, _CP_BG);
       COsdShowPageInputStringAll(_OSD_INPUT_D6,0);
        OsdPropPutStringCenter( ROW(gc_row2), COL(gc_long*_OSD_INPUT_D6), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
#endif 


    //    OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _D0_INPUT_TYPE);
    //    OsdFontPut1BitMainMenuIcon(ROW(2), COL(ucCol + (12 * 3)), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_BLUE, _CP_BG);

    // highligh window

if(GET_OSD_INPUT_PORT_OSD_ITEM() ==_OSD_INPUT_AUTO)
    {
        OsdWindowDrawingByFontHighlight(_OSD_WINDOW_8, ROW(0), COL(0), WIDTH(gc_long), HEIGHT(gc_high), _CP_ORANGE_H, _CP_LIGHTBLUE, _CP_BG);
    //     g_usItemNum=0;
   }
    else
    {
        OsdWindowDrawingByFontHighlight(_OSD_WINDOW_8, ROW(0), COL(0+ (gc_long * (GET_OSD_INPUT_PORT_OSD_ITEM()) )), WIDTH(gc_long), HEIGHT(gc_high), _CP_ORANGE_H, _CP_LIGHTBLUE, _CP_BG);
           //     g_usItemNum=GET_OSD_INPUT_PORT_OSD_ITEM() - 1;

    }


//OsdDispHotKeySourceMenuIcon();
    OsdDispSetPosition(_POS_PERCENT, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
    OsdFuncEnableOsd();

    ScalerTimerReactiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);

}
*/

#if( _MIAOZHUN_FUNCTION== _ON)

void OsdDispMIAOZHUNMenu(void)
{ 
	
	   BYTE gc_row1, gc_col1, gc_high, gc_long;
	
#if(_OSTAR_OSD_SMALL == _ON)
		 gc_row1 = 1;
		 gc_col1 = 4;
		 gc_high = 6;
		 gc_long = 14;
#else
		 gc_row1 = 3;
		 gc_col1 = 6;
		 gc_high = 11;
		 gc_long = 18;
#endif

    OsdFuncDisableOsd();
     OsdFuncCloseWindow(_OSD_WINDOW_ALL);

    OsdFuncApplyMap(WIDTH(4*gc_long), HEIGHT(gc_high), COLOR(_CP_LIGHTBLUE, _CP_BG));    //Leixe yaya 

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(gc_high), _DISABLE, 0, _ENABLE);  
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()); 

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    
    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_BLUE_120);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(52), g_ucOsdWidth, _CP_LIGHTBLUE);    
    }
    else
#endif         
    {        
       // OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdHeight, _CP_BLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight, _CP_GREEN_119);     
    }

  
    // title
    // icon


     OsdFontVLCDynamicLoadIcon( 0, _ICON_MIAOZHUN1);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_ORANGE_H, _CP_BG);


     OsdFontVLCDynamicLoadIcon( 1, _ICON_MIAOZHUN1);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+gc_long), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_GREEN_66, _CP_BG);

     OsdFontVLCDynamicLoadIcon( 2, _ICON_MIAOZHUN2);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*2)), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_ORANGE_H, _CP_BG);

     OsdFontVLCDynamicLoadIcon( 3, _ICON_MIAOZHUN2);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+(gc_long*3)), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_GREEN_66, _CP_BG);

    //    OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _D0_INPUT_TYPE);
    //    OsdFontPut1BitMainMenuIcon(ROW(2), COL(ucCol + (12 * 3)), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_BLUE, _CP_BG);

    // highligh window
        OsdWindowDrawingByFontHighlight(_OSD_WINDOW_8, ROW(0), COL(0+ (gc_long * g_MiaoZhun )), WIDTH(gc_long), HEIGHT(gc_high), _CP_ORANGE_H, _CP_LIGHTBLUE, _CP_BG);
           //     g_usItemNum=GET_OSD_INPUT_PORT_OSD_ITEM() - 1;



//OsdDispHotKeySourceMenuIcon();
    OsdDispSetPosition(_POS_PERCENT, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
    OsdFuncEnableOsd();

    ScalerTimerReactiveTimerEvent(SEC(10), _USER_TIMER_EVENT_OSD_DISABLE);

}


void OsdDispMIAOZHUNShow(void)
{   
    OsdFuncDisableOsd();
     OsdFuncCloseWindow(_OSD_WINDOW_ALL);

    OsdFuncApplyMap(WIDTH(8), HEIGHT(4), COLOR(_CP_LIGHTBLUE, _CP_BG));    //Leixe yaya 

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(4), _DISABLE, 0, _ENABLE);  
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
    OsdFuncTransparency(255); 

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    
    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_BLUE_120);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(52), g_ucOsdWidth, _CP_LIGHTBLUE);    
    }
    else
#endif         
    {        
       // OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdHeight, _CP_BLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight, _CP_GREEN_119);     
    }

  
    // title
    // icon

  if(g_MiaoZhun == 0)
    {
     OsdFontVLCDynamicLoadIcon( 0, _ICON_MIAOZHUN1);   
     OsdFontPut1BitMainMenuIcon(ROW(0), COL(2), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_ORANGE_H, _CP_BG);
  	
     }
  else if(g_MiaoZhun == 1)
    {
     OsdFontVLCDynamicLoadIcon( 0, _ICON_MIAOZHUN1);  
     OsdFontPut1BitMainMenuIcon(ROW(0), COL(2), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_GREEN_66, _CP_BG);

  	
     }
  else if(g_MiaoZhun == 2)
    {
     OsdFontVLCDynamicLoadIcon(0, _ICON_MIAOZHUN2);   
     OsdFontPut1BitMainMenuIcon(ROW(0), COL(2), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_ORANGE_H, _CP_BG);
     }
  else if(g_MiaoZhun == 3)
    {
     OsdFontVLCDynamicLoadIcon(0, _ICON_MIAOZHUN2);   
     OsdFontPut1BitMainMenuIcon(ROW(0), COL(2), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_GREEN_66, _CP_BG);
     }
    //    OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _D0_INPUT_TYPE);
    //    OsdFontPut1BitMainMenuIcon(ROW(2), COL(ucCol + (12 * 3)), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_BLUE, _CP_BG);




//OsdDispHotKeySourceMenuIcon();
    OsdDispSetPosition(_POS_PERCENT, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
    OsdFuncEnableOsd();
    g_MiaoZhun_OnOff = _ON;
     ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
}
#endif
#if(_USE_TIME_SUPPORT == _ON)
/*
//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void RTDOsdDisplayOsdTimerProc(void)
{
WORD gu_Timer = 0;
    switch ( g_usTimeTabe)
    	{
          case _OSD_ADVANCE_TIME_30:
		  gu_Timer = 30 * 60;
		  break;
		  
          case _OSD_ADVANCE_TIME_40:
		  gu_Timer = 40 * 60;
		  break;
		  
          case _OSD_ADVANCE_TIME_50:
		  gu_Timer = 50 * 60;
		  break;
		  
          case _OSD_ADVANCE_TIME_60:
		  gu_Timer = 60 * 60;
		  break;

          case _OSD_ADVANCE_TIME_90:
		  gu_Timer = 90 * 60;
		  break;
		  
         default:
		 break;
		 	
    	}

	if(0)//(GET_OSDTimerFLG_STATUS()==_OFF)
	{
	return;
	 }
	else
	{

		//OsdDispOsdMessage(_OSD_DISP_OSD_TTIME_MSG);
              if(g_usTime_OSD_OnOff ==_OFF)
                  {
                  OsdFuncDisableOsd();
                  g_usTime_OSD_OnOff =_ON;
                   OsdFuncCloseWindow(_OSD_WINDOW_ALL);
                  OsdFuncApplyMap(WIDTH(_OSD_TIME_SHOW_WIDTH), HEIGHT(_OSD_TIME_SHOW_HEIGHT), COLOR(_CP_LIGHTBLUE, _CP_BG));    //Leixe yaya 
              
              #if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
                  ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(2), _DISABLE, 0, _ENABLE);  
              #endif
              
                  OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
                 // OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()); 
                  OsdFuncTransparency(20); 
                  // Adjust Color Palette
                  OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
                  
                  // Load Font & Icon
                  OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    
              
                  
                  // Background window
              #if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
                  if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
                  {
                      OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_BLUE_120);
                      OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(52), g_ucOsdWidth, _CP_LIGHTBLUE);    
                  }
                  else
              #endif         
                  {        
                     // OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdHeight, _CP_BLUE);
                      OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight, _CP_GRAY_1);     
                  }
              
                
                  // title
                  // icon
                  OsdFontVLCLoadFont(_OSDTIMER_ICON);

		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
		  {
                    OsdDispSetPosition(_POS_PERCENT, 100,  100);
		   }
		else
		  {
                  OsdDispSetPosition(_POS_PERCENT, 0,  0);
		   }
	
              
                  ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
                  
                  OsdFuncEnableOsd();
		   ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_DISABLE);
		  
              }
		      OsdFontPut1BitTable(ROW(0), COL(2), tiOSDTimer[(gu_Timer-(g_usTimeUse))/60/10], COLOR(_CP_GREEN_66, _CP_BG));              		
                      OsdFontPut1BitTable(ROW(0), COL(4), tiOSDTimer[(gu_Timer-(g_usTimeUse))/60%10], COLOR(_CP_GREEN_66, _CP_BG));              		
                 	OsdFontPut1BitTable(ROW(0), COL(6), tiOSDTimer[10], COLOR(_CP_GREEN_66, _CP_BG));
		     OsdFontPut1BitTable(ROW(0), COL(7), tiOSDTimer[(gu_Timer-(g_usTimeUse))%60/10], COLOR(_CP_GREEN_66, _CP_BG));              		
                      OsdFontPut1BitTable(ROW(0), COL(9), tiOSDTimer[(gu_Timer-(g_usTimeUse))%60%10], COLOR(_CP_GREEN_66, _CP_BG)); 
		         if (gu_Timer == (g_usTimeUse))
				{
				  OsdFuncClearOsd(ROW(0), COL(0), WIDTH(_OSD_TIME_SHOW_WIDTH), HEIGHT(_OSD_TIME_SHOW_HEIGHT));
		                  OsdFontPut1BitTable(ROW(0), COL(2), tiOSDTimer[0], COLOR(_CP_ORANGE_H, _CP_BG));
                               	   ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_OSD_TIMER);
		                   g_usTimeTabe=_OSD_ADVANCE_TIME_0;
				}

          
		
		//SET_OSDTimerFLG_STATUS(_ON);
	}



	
}
*/
#endif
/*
void OsdDispHotKeyAspectRatioMenu(void)
{ 
	   BYTE gc_row1, gc_row2, gc_high, gc_long, gc_col1, gc_col2;
	   
#if(_OSTAR_OSD_SMALL == _ON)
		 gc_row1 = 1;	   
		 gc_col1 = 4;
		 gc_row2 = 5;
		 gc_col2 = 0;
		 gc_high = 8;
		 gc_long = 14;
#else
		 gc_row1 = 3;
		 gc_col1 = 6;
		 gc_row2 = 8;
		 gc_col2 = 0;
		 gc_high = 11;
		 gc_long = 18;
#endif

    OsdFuncDisableOsd();

     OsdFuncCloseWindow(_OSD_WINDOW_ALL);

    SET_OSD_STATE(_MENU_HOTKEY_ASPECT_RATIO);            
    SET_OSD_ASPECT_RATIO_TYPE((GET_OSD_ASPECT_RATIO_TYPE()+1)%(_OSD_ASPECT_RATIO_AMOUNT+1));
   
    OsdFuncApplyMap(WIDTH(gc_long), HEIGHT(gc_high), COLOR(_CP_LIGHTBLUE, _CP_BG));   

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(gc_high), _DISABLE, 0, _ENABLE);  
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()); 

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    
    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_LIGHTBLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(52), g_ucOsdWidth, _CP_LIGHTBLUE);    
    }
    else
#endif         
    {        
       // OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdHeight, _CP_BLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight, _CP_GREEN_119);     
    }

     OsdFontVLCDynamicLoadIcon( _ICON_HOTKEY_AUTO_POS, _ICON_ASPECT_RATIO);   
     OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
     OsdPropPutStringCenter( ROW(gc_row2), COL(gc_col2), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_ASPECT_RATIO, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());

      SET_OSD_ASPECT_RATIO_TYPE(OsdDisplayDetOverRange(GET_OSD_ASPECT_RATIO_TYPE() ,_OSD_ASPECT_RATIO_AMOUNT,_OSD_ASPECT_RATIO_FULL, _ON));
      OsdPropPutStringCenter( ROW(gc_row2+1), COL(gc_col2), WIDTH(gc_long), _PFONT_PAGE_1, _STRING_Aspect_Ratio_TABLE1, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());

    OsdDispSetPosition(_POS_PERCENT, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
    OsdFuncEnableOsd();

    #if(_ASPECT_RATIO_SUPPORT == _ON)
          SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
    #endif

     ScalerTimerReactiveTimerEvent(SEC(3), _USER_TIMER_EVENT_OSD_DISABLE);

    
}


*/



#if(_USER_FUNCTION_FPS1_FPS2==_ON)
/*
void OsdDispHotKeyColorEffectMenu(void) 
{ 
	   BYTE gc_row1, gc_col1, gc_high, gc_long;
	   
#if(_OSTAR_OSD_SMALL == _ON)
		 gc_row1 = 2;
		 gc_col1 = 4;
		 gc_high = 8;
		 gc_long = 14;
#else
		 gc_row1 = 3;
		 gc_col1 = 6;
		 gc_high = 11;
		 gc_long = 16;
#endif

    OsdFuncDisableOsd();
         OsdFuncCloseWindow(_OSD_WINDOW_ALL);

    OsdFuncApplyMap(WIDTH(gc_long), HEIGHT(gc_high), COLOR(_CP_LIGHTBLUE, _CP_BG));
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsd1BitFontShrink(_OSD_1BIT_SHRINK_BY_RIGHT);
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(gc_high), _DISABLE, 0, _ENABLE);    
#endif  

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()); 

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    
    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(gc_long), HEIGHT(g_ucOsdWidth), _CP_BLUE_120);       
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdHeight-12),HEIGHT(g_ucOsdWidth), _CP_LIGHTBLUE);
    }    
    else
#endif  
    {
          OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight, _CP_GREEN_119);           
    }
if((GET_OSD_COLOR_EFFECT()>=_COLOREFFECT_STANDARD)&&(GET_OSD_COLOR_EFFECT()<=_COLOREFFECT_PHOTO)&&(GET_OSD_LANGUAGE()==_CHINESE_T))
{
OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, GET_OSD_COLOR_EFFECT()+_ICON_COLOR_EFF_HANWEN_STD);   
}
else
{
OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, GET_OSD_COLOR_EFFECT()+_ICON_COLOR_EFF_STD);   
}
OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
       OsdDispSetPosition(_POS_PERCENT, 50, 50);
       ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
    OsdFuncEnableOsd();
}*/
#endif


/*OsdDispHotKeyConTrastMenu()
{   
    OsdFuncDisableOsd();
     OsdFuncCloseWindow(_OSD_WINDOW_ALL);

    OsdFuncApplyMap(WIDTH(42), HEIGHT(16), COLOR(_CP_LIGHTBLUE, _CP_BG));    //Leixe yaya 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(16), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);    
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()); 

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    
    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);    

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    
    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_BLUE_120);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(52), g_ucOsdWidth, _CP_LIGHTBLUE);    
    }
    else
#endif         
    {        
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), g_ucOsdWidth, g_ucOsdHeight/2, _CP_GREEN_119);     
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( g_ucOsdHeight/2), COL(0), g_ucOsdWidth, g_ucOsdHeight/2, _CP_GRAY_1);     
    }

    // title
    // icon
     OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_BACKLIGHT);   
     OsdFontPut1BitMainMenuIcon(ROW(2), COL(18), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
     OsdPropPutStringCenter( ROW(6), COL(10), WIDTH(22), _PFONT_PAGE_1, _STRING_CONTRAST, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());
     OsdPropPutString(ROW(12), COL(4 + (18 * 0)), _PFONT_PAGE_1, _STRING_CONTRAST, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());    

        g_usAdjustValue = UserCommonAdjustRealValueToPercent(GET_OSD_CONTRAST(), _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER);

        OsdWindowSlider(ROW(12), COL(_OSD_NUMBER_2_COL-6),g_usAdjustValue, _SLIDER_0, _UNSELECT);
        OsdPropShowNumber(ROW(12), COL(_OSD_NUMBER_2_COL+_OSD_SLIDE_VALUE_OFFSET-7), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF| _SHOW_3), _PFONT_PAGE_ITEM_1, _OSD_NUMBER_UNSTLECT_COLOR);            
        OsdWindowDrawingByFontHighlight(_OSD_WINDOW_8, ROW(0), COL(0), WIDTH(42), HEIGHT(8), _CP_ORANGE_H, _CP_LIGHTBLUE, _CP_BG);

//OsdDispHotKeySourceMenuIcon();
    OsdDispSetPosition(_POS_PERCENT, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    
    OsdFuncEnableOsd();
}
*/
/*
void OsdDispHotKeySourceMenuSwitch(void)
{  
	BYTE   gc_high, gc_long;

#if(_OSTAR_OSD_SMALL == _ON)
		 gc_high = 7;
		 gc_long = 14;
#else
		 gc_high =11;
		 gc_long =18;
#endif

if(GET_OSD_INPUT_PORT_OSD_ITEM() ==_OSD_INPUT_AUTO)
    {
        OsdWindowDrawingByFontHighlight(_OSD_WINDOW_8, ROW(0), COL(0), WIDTH(gc_long), HEIGHT(gc_high), _CP_ORANGE_H, _CP_LIGHTBLUE, _CP_BG);
    //     g_usItemNum=0;
   }
    else 
    {
        OsdWindowDrawingByFontHighlight(_OSD_WINDOW_8, ROW(0), COL(0+ (gc_long * (GET_OSD_INPUT_PORT_OSD_ITEM() ) )), WIDTH(gc_long), HEIGHT(gc_high), _CP_ORANGE_H, _CP_LIGHTBLUE, _CP_BG);
           //     g_usItemNum=GET_OSD_INPUT_PORT_OSD_ITEM() - 1;

    }

}
*/
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispOsdMessage(EnumOSDDispMsg ucMessage)
{

    OsdDispDisableOsd();

    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;
#if 0//((_PANEL_DH_WIDTH <= 1920) && (_PANEL_DV_HEIGHT<= 1080))  //osd small
	if(ucMessage == _OSD_DISP_INPUT_SIGNAL_MSG)
	{
			BYTE ucTest = 0;
		
			g_ucFontPointer0 = _OSD_PAGE_0_START;
			g_ucFontPointer1 = _OSD_PAGE_1_START;
			g_ucFontPointer2 = _OSD_PAGE_2_START;
		
			if(ucTest == 1)
			{
		
			   ScalerOsdDataPort(0);
			}
		
			OsdFuncDisableOsd();
		
			OsdFuncApplyMap(WIDTH(_OSD_INPUT_PORT_INFORMATION_WIDTH), HEIGHT(_OSD_INPUT_PORT_INFORMATION_HEIGHT), COLOR(_CP_BLUE_120, _CP_BG));
		
		//20140304 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
			ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(_OSD_MAIN_MENU_HEIGHT), _DISABLE, 0, _ENABLE);
#endif
		
			OsdFuncBlending(_OSD_TRANSPARENCY_ALL);
			OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());
		
			// Adjust Color Palette
			OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
		
			// Load Font & Icon
			OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);
		
			OsdFontVLCLoadFont(_FONT1_GLOBAL);
			//OsdFontVLCLoadFont(_FONT2_ICON_MENU);
			 OsdFontVLCLoadFont(_FOUR_CORNER);
			OsdFontVLCLoadFont(_MAIN_MENU_2BIT_ICON);
		
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
				OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(2), COL(1), WIDTH(g_ucOsdWidth-3), HEIGHT((g_ucOsdHeight-2)), _CP_BLUE_65 );
				OsdFontPut1FuncTableForm(1, 1, _LEFT_CORNER_0,g_ucOsdWidth -3,g_ucOsdHeight-3,_CP_BLUE_65,_CP_BG,_QUADRANGLE_WINDOW_0);
				OsdFontPut1FuncHLine(2, 1, _WHITE_EDGE_1, g_ucOsdWidth-1 ,_CP_WHITE, _CP_BLUE_65);
				OsdFontPut1FuncHLine(6, 1, _WHITE_EDGE_1, g_ucOsdWidth -1,_CP_WHITE, _CP_BLUE_65);
		
		
		
			  
			}

	
			// Osd Enable
			//ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
			//OsdFuncEnableOsd();
	 	OsdDisplayGetSourcePort(ROW(3),COL(8));
		
	  if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
		{
		OsdDispSetPosition(_POS_PERCENT, 0, 100);
		}
	  else
		{
		OsdDispSetPosition(_POS_PERCENT, 100, 0);
		}
	
	 }
	 else
#endif // #if((_PANEL_DH_WIDTH <= 1920) && (_PANEL_DV_HEIGHT<= 1080))

	{
    OsdFuncApplyMap(WIDTH(22), HEIGHT(7), COLOR(_CP_LIGHTBLUE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsd1BitFontShrink(_OSD_1BIT_SHRINK_BY_RIGHT);
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE,  HEIGHT(7), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
	OsdFontVLCLoadFont(_FOUR_CORNER);

    //20140210 Abel Background window Modify
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)||(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), HEIGHT(g_ucOsdWidth), _CP_BLUE_120);       
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(g_ucOsdHeight-12),HEIGHT(g_ucOsdWidth), _CP_LIGHTBLUE);
    }
    else
#endif
    {
        /*if(ucMessage == _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG)        
        {
            OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), g_ucOsdHeight, _CP_LIGHTBLUE);
        }
        else*/
        {
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(0), WIDTH(g_ucOsdWidth-2), HEIGHT((g_ucOsdHeight-2)), _CP_BLUE_65 );
			OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLUE_65,_CP_BG,_QUADRANGLE_WINDOW_0);
			OsdFontPut1FuncHLine(1, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLUE_65);
			OsdFontPut1FuncHLine(5, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLUE_65);
        }
    }

    //==== Show page item =======
    switch(ucMessage)
    {
        case _OSD_DISP_NOSIGNAL_MSG:
		OsdPropPutString(ROW(3), COL(2), _PFONT_PAGE_2, _STRING_NO_SIGNAL_INPUT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	
        // title
	//	OsdPropPutString(ROW(3), COL(8), _PFONT_PAGE_2, _STRING_NO_VIDEO_INPUT, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());	
 /*           OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_NO_SIGNAL0);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_SIGNAL1);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_SIGNAL2);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_NO_SIGNAL3);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdDispSetPosition(_POS_PERCENT, 50, 50);
*/
        // icon
       /* if(GET_OSD_LANGUAGE()==_ENGLISH)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_SIGNAL_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_SIGNAL_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdDispSetPosition(_POS_PERCENT, 50, 50);
            }
     else if(GET_OSD_LANGUAGE()==_CHINESE_T)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_SIGNAL_CHINA_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_SIGANL_CHINA_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdDispSetPosition(_POS_PERCENT, 50, 50);
            }*/
        break;
        
        case _OSD_DISP_NOCABLE_MSG:
      // title
      
	  OsdPropPutString(ROW(3), COL(5), _PFONT_PAGE_2, _STRING_NO_VIDEO_INPUT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	  
           // OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_NO_CABLE0);
           // OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
           // OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_CABLE1);
           // OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            //OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_CABLE2);
           // OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_LIGHTBLUE, _CP_BG);
           // OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_NO_CABLE3);
           // OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_LIGHTBLUE, _CP_BG);
        // icon
      /*  if(GET_OSD_LANGUAGE()==_ENGLISH)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_CABLE_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_CABLE_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            }
     else if(GET_OSD_LANGUAGE()==_CHINESE_T)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_CABLE_CHINA_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_CABLE_CHINA_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(6+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_NO_CABLE_CHINA_TEXT_2);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(6+6*2), (_1DYNAMIC_ICON_START + (3* 24)), _CP_LIGHTBLUE, _CP_BG);
         }*/
        OsdDispSetPosition(_POS_PERCENT, 50, 50);
        break;
        
        case _OSD_DISP_NOSUPPORT_MSG:
     // title
 /*           OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_NO_SUPPORT0);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_SUPPORT1);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_SUPPORT2);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_NO_SUPPORT3);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_LIGHTBLUE, _CP_BG);
*/
		// icon
     /*   if(GET_OSD_LANGUAGE()==_ENGLISH)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_SUPPORT_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_SUPPORT_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            }
     else if(GET_OSD_LANGUAGE()==_CHINESE_T)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_NO_SUPPORT_CHINA_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_NO_SUPPORT_CHINA_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
        }*/
        OsdDispSetPosition(_POS_PERCENT, 50, 50);
        break;
       
        case _OSD_DISP_FAIL_SAFE_MODE_MSG:
            OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END), _PFONT_PAGE_0, _STRING_NO_SUPPORT, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());
          OsdDispSetPosition(_POS_PERCENT, 50, 50);
            break;
        
        case _OSD_DISP_AUTO_CONFIG_MSG:            
      //title 
/*            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_AUTO_ADJUST0);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_AUTO_ADJUST1);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_WHITE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_AUTO_ADJUST2);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_WHITE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_AUTO_ADJUST3);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_WHITE, _CP_BG);
*/
		// icon
     /*   if(GET_OSD_LANGUAGE()==_ENGLISH)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_AUTO_ADJUST_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_AUTO_ADJUST_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(6+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_AUTO_ADJUST_TEXT_2);
             OsdFontPut1BitMainMenuIcon(ROW(6), COL(6+6+6), (_1DYNAMIC_ICON_START + (3* 24)), _CP_LIGHTBLUE, _CP_BG);
            }
     else if(GET_OSD_LANGUAGE()==_CHINESE_T)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_AUTO_ADJUST_CHINA_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_AUTO_ADJUST_CHINA_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
        }*/ 
     OsdDispSetPosition(_POS_PERCENT, 50, 50);
           
            break;

        case _OSD_DISP_INPUT_SIGNAL_MSG:
	 	OsdDisplayGetSourcePort(ROW(3),COL(8));
		  if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
            OsdDispSetPosition(_POS_PERCENT, 15, 85);
		  else
            OsdDispSetPosition(_POS_PERCENT, 85, 15);
 /*  OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_INPUT_AUTO);   
     OsdFontPut1BitMainMenuIcon(ROW(3), COL(6), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
        OsdPropPutString(ROW(7), COL(6 + (18 * 0)), _PFONT_PAGE_1, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _MENU_INFORMATION);
            OsdFontPut1BitMainMenuIcon(ROW(_OSD_MESSAGE_ROW_START), COL(3), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
           // OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END), _PFONT_PAGE_1, OsdDisplayGetSourcePortString(), COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
            OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START + 1), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END), _PFONT_PAGE_0, _STRING_NOW_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
            OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START + 2), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END),_PFONT_PAGE_0, _STRING_HFREQPCLK, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
#if(_VGA_SUPPORT == _ON)
            if(SysSourceGetSourceType() == _SOURCE_VGA)
            {
                OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START + 3), COL(_OSD_MESSAGE_CENTER_COL_START-1), WIDTH(_OSD_MESSAGE_CENTER_COL_END), _PFONT_PAGE_0, OsdDisplayGetVGAModeString(g_stVGAModeUserData.b1IsPresetMode), COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());                
                OsdPropShowNumber(ROW(_OSD_MESSAGE_ROW_START + 3), COL(26),  g_stVGAModeUserData.ucModeNumber, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), _PFONT_PAGE_1, COLOR(_CP_WHITE, _CP_BG));
            }
#endif

#if(_DIGITAL_PORT_SUPPORT == _ON)
            if((SysSourceGetInputPort() == _D0_INPUT_PORT) || 
               (SysSourceGetInputPort() == _D1_INPUT_PORT) ||
               (SysSourceGetInputPort() == _D2_INPUT_PORT) ||
               (SysSourceGetInputPort() == _D3_INPUT_PORT) ||
               (SysSourceGetInputPort() == _D4_INPUT_PORT) ||
               (SysSourceGetInputPort() == _D5_INPUT_PORT))
            {
                OsdPropPutStringCenter(ROW(_OSD_MESSAGE_ROW_START + 3), COL(_OSD_MESSAGE_CENTER_COL_START), WIDTH(_OSD_MESSAGE_CENTER_COL_END), _PFONT_PAGE_0, _STRING_HDCP_MODE, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
            }            
#endif */
          
            break;
            
        case _OSD_DISP_AUTO_COLOR_MSG:
/*
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_AUTOCOLOR_ADJUST0);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_AUTOCOLOR_ADJUST1);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_WHITE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_AUTOCOLOR_ADJUST2);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_WHITE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_AUTOCOLOR_ADJUST3);    
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_WHITE, _CP_BG);
             OsdDispSetPosition(_POS_PERCENT, 50, 50);
       */     break;        
   
        case _OSD_DISP_POWER_SAVING_MSG:   
		OsdPropPutString(ROW(3), COL(5), _PFONT_PAGE_2, _STRING_STANDBY_MODE, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	
     // title
/*            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_POWER_SAVING0);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_POWER_SAVING1);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_POWER_SAVING2);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_POWER_SAVING3);
            OsdFontPut1BitMainMenuIcon(ROW(gc_row1+4), COL(gc_col1+6), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_LIGHTBLUE, _CP_BG);
*/
		// icon
      /*  if(GET_OSD_LANGUAGE()==_ENGLISH)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_POWER_SAVING_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(5), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_POWER_SAVING_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(5+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_POWER_SAVING_TEXT_2);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(5+12), (_1DYNAMIC_ICON_START + (3* 24)), _CP_LIGHTBLUE, _CP_BG);
            }
     else if(GET_OSD_LANGUAGE()==_CHINESE_T)
            {
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_POWER_SAVING_CHINA_TEXT_0);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_LIGHTBLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_POWER_SAVING_CHINA_TEXT_1);
            OsdFontPut1BitMainMenuIcon(ROW(6), COL(8+6), (_1DYNAMIC_ICON_START + (2* 24)), _CP_LIGHTBLUE, _CP_BG);
        }   */
            OsdDispSetPosition(_POS_PERCENT, 50, 50);
        break;   
     /*   case _OSD_DISP_PANEL_UNIFORMITY_ONOFF_MSG:
        // title
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_0, _ICON_TRUN_OFF_PANEL_UNI_TEXT0);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_1, _ICON_TRUN_OFF_PANEL_UNI_TEXT1);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3+6), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_2, _ICON_YES);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(18), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon( _ICON_POS_UP_3, _ICON_NO);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(27), (_1DYNAMIC_ICON_START + (3 * 24)), _CP_BLUE, _CP_BG);
            OsdDispSetPosition(_POS_PERCENT, 50, 50);
*/
            break;
    }

    }   



    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispAutoConfigProc(void)
{
    OsdDispOsdMessage(_OSD_DISP_AUTO_CONFIG_MSG);
    UserCommonAutoConfig();
    OsdDispDisableOsd();
}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDisplayAutoBalanceProc(void)
{
    OsdDispDisableOsd();
    OsdDispOsdMessage(_OSD_DISP_AUTO_COLOR_MSG);

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
        {
            // Perform auto-color for RGB
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_RGB) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_RGB);

#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_FORMULA))
                // Calculate YPbPr gain/offset using formula
                g_stAdcData = ScalerAutoBalanceYPbPrFromFormula(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);

                // Restore RGB gain/offset
                ScalerAutoGetAutoColorResult(&g_stAdcData);
#endif
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#if((_YPBPR_SUPPORT == _ON) && (_YPBPR_AUTO_METHOD == _YPBPR_AUTO_BY_SOURCE))
        else
        {
            // Perform auto-color for YPbPr
            if(ScalerAutoDoWhiteBalance(_AUTO_TUNE_YPBPR) == _AUTO_SUCCESS)
            {
                ScalerAutoGetAutoColorResult(&g_stAdcData);
                UserCommonNVRamSaveADCSetting(_COLOR_SPACE_YPBPR);
            }
            else
            {
                UserCommonNVRamRestoreADCSetting();
            }
        }
#endif
    }

    OsdDispDisableOsd();
	
    SET_KEYMESSAGE(_NONE_KEY_MESSAGE);

}
#endif // End of #if(_VGA_SUPPORT == _ON)

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/*
void OsdDispClearSliderAndNumber(void)
{
    OsdWindowSliderDisable();
    OsdFuncClearOsd(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_1_COL), g_ucOsdWidth, 1);
}
*/
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispOsdReset(void)
{
    BYTE ucLanguageTemp = 0;
    //ucLanguageTemp = GET_OSD_LANGUAGE();
#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWDDomainEnable(_FUNCTION_OFF);
#endif

    OsdDispDisableOsd();

    UserCommonNVRamRestoreSystemData();
    OSTARNVRamRestoreOSDData();

    OSTARNVRamRestoreUserColorSetting();    
    OSTARNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    OSTARNVRamRestoreSixColorData();

    OSTARNVRamRestoreBriCon();
    OSTARNVRamRestoreBacklight();

#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        SET_VGA_MODE_DO_FIRST_AUTO(_TRUE);
        UserCommonModeSearchInitalUserAndCenterData(g_stVGAModeUserData.ucModeNumber);
        UserCommonNVRamSaveModeUserData();
    }
#endif
/*
    if(ucLanguageTemp != GET_OSD_LANGUAGE())
    {  
        SET_OSD_LANGUAGE(ucLanguageTemp);
        SET_OSD_FACTORY_BURNIN_STATUS(_OFF);// Lee add for burnin off,after reset  20141011//
        OSTARNVRamSaveOSDData();
    }
*/
// Lee add for burnin off,after reset  20141011 start//     
   if((GET_OSD_FACTORY_BURNIN_STATUS()==_ON))
   {
    SET_OSD_FACTORY_BURNIN_STATUS(_OFF);
    OSTARNVRamSaveOSDData();
   }
// Lee add for burnin off,after reset  20141011 end//       
if(GET_OSD_FactoryIn_TYPE() ==_ON)
{
SET_OSD_FactoryIn_TYPE(_OFF);
    OSTARNVRamSaveOSDData();
}

     #if(_FREESYNC_SUPPORT == _ON)
              ScalerSyncSetFREESYNCSupport(GET_OSD_FREE_SYNC_STATUS());
     #endif
#if(_AUDIO_SUPPORT == _ON)
    UserAdjustAudioVolume(GET_OSD_VOLUME());// sfy add for when set volume 0,after reset the osd volume 20140925 //
#endif
// AFTER RESET,THE SOURCE SELECT AUTO //
if(GET_OSD_INPUT_PORT_OSD_ITEM() != _OSD_INPUT_AUTO)
{
    SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_AUTO);
    OSTARNVRamSaveOSDData();
}
    SysSourceSetScanType(_SOURCE_SWITCH_AUTO_IN_GROUP);
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);

    OsdFuncSetOsdItemFlag();
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
	

    SET_OSD_STATE(_MENU_NONE);
}


#if(_LOGO_ON_OFF == _ON)
//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_LOGO_TYPE == _RTD_LOGO)  // sfy add  TongFang WD logo 20140819 //

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;

    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);

    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);
    OsdFuncApplyMap(WIDTH(70), HEIGHT(10), COLOR(_LOGO_CP_WHITE, _LOGO_CP_BG));

   //20140305 Abel
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_REALTEK_1BIT_LOGO0, COLOR(_LOGO_CP_BG, _LOGO_CP_BG));
    OsdFontPut1BitTable( ROW(0), COL(19), tiOSD_REALTEK_1BIT_LOGO1, COLOR(_LOGO_CP_BG, _LOGO_CP_BG));
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    OsdWindowDrawing(_OSD_WINDOW_0, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLUE);
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif

    SET_OSD_LOGO_ON(_ON);
}

// sfy add  TongFang WD logo 20140819 start //
#elif(_LOGO_TYPE == _TONGFANG_WD_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH((0x1e+1)), HEIGHT((0x13+1)), COLOR(_LOGO_CP_BLACK, _LOGO_CP_WHITE));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_TONGFANG_1BIT_LOGO0, COLOR(_LOGO_CP_BLACK, _LOGO_CP_WHITE));
    OsdFontPut1BitTable( ROW(8), COL(0), tiOSD_TONGFANG_1BIT_LOGO1, COLOR(_LOGO_CP_BLACK, _LOGO_CP_WHITE));
    OsdFontPut1BitTable( ROW(16), COL(0), tiOSD_TONGFANG_1BIT_LOGO2, COLOR(_LOGO_CP_BLACK, _LOGO_CP_WHITE));
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_RED);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}


#elif(_LOGO_TYPE == _TONGFANG_SEIKI_PRO_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(((0x53+1))), HEIGHT(((0x0c+1))), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(0), COL(39), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(0), COL(56), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO2, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}

// Lee  add  sanc  logo 20141013 start //
#elif(_LOGO_TYPE == _SANC_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(((60))), HEIGHT(((10))), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_SANC_1BIT_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(3), COL(0), tiOSD_SANC_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(6), COL(0), tiOSD_SANC_1BIT_LOGO2, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(9), COL(0), tiOSD_SANC_1BIT_LOGO3, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}
// Lee  add  sanc  logo 20141013 end //

#elif(_LOGO_TYPE == _SHENGYANG_UPSTAR_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(46), HEIGHT(12), COLOR(_LOGO_CP_BLACK,_LOGO_CP_RED));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_SHENGYANG_UPSTAR_1BIT_LOGO0, COLOR(_LOGO_CP_BLACK,_LOGO_CP_RED));

    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    //OsdWindowDrawing(_OSD_WINDOW_0, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}

#elif(_LOGO_TYPE == _TONGFANG_ELEMENT_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(((103+1))), HEIGHT(((11+1))), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_TONGFANG_ELEMENT_1BIT_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(0), COL(50), tiOSD_TONGFANG_ELEMENT_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
     
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
//    OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}

#elif(_LOGO_TYPE == _SANC_SECPTRE_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(((171+1))), HEIGHT(((14+1))), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_SANC_SECPTRE_1BIT_LOGO0, COLOR(_LOGO_CP_RED,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(0), COL(49), tiOSD_SANC_SECPTRE_1BIT_LOGO1, COLOR(_LOGO_CP_RED,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(0), COL(99), tiOSD_SANC_SECPTRE_1BIT_LOGO2, COLOR(_LOGO_CP_RED,_LOGO_CP_BLACK));
     
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
//    OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}

#elif(_LOGO_TYPE == _KOS_KOIOS_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(((56+1))), HEIGHT(((9+1))), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_KOS_KOIOS_1BIT_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    OsdFontPut1BitTable( ROW(0), COL(33), tiOSD_KOS_KOIOS_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
     
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
//    OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}



#elif(_LOGO_TYPE == _VIEWPAKER_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(60), HEIGHT(20), COLOR(_LOGO_CP_BLACK,_LOGO_CP_WHITE));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_VIEWPAKER_LOGO0, COLOR(_LOGO_CP_BLACK,_LOGO_CP_WHITE));
   // OsdFontPut1BitTable( ROW(0), COL(39), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
 //   OsdFontPut1BitTable( ROW(0), COL(56), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO2, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    //OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}
#elif(_LOGO_TYPE == _TIANXINGZHE_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(67), HEIGHT(17), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_TIANXINGZHE_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
   // OsdFontPut1BitTable( ROW(0), COL(39), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
 //   OsdFontPut1BitTable( ROW(0), COL(56), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO2, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    //OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}
// Lee  add  sanc  logo 20141013 start //

#elif(_LOGO_TYPE == _USE_PEO_LOGO)  
void OsdDispShowLogo(void)
{
	ScalerDDomainPatternGenAdjustColor(0, 0, 0);
	ScalerDDomainPatternGenEnable(_ENABLE);
	ScalerDDomainBackgroundEnable(_DISABLE);

	OsdFuncDisableOsd();
	OsdFuncApplyMap(WIDTH(44), HEIGHT(14), COLOR(_CP_BG, _CP_BG));
       OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
	OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
	OsdFuncTransparency(0);
	OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
	OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

	OsdFontPut1BitTable(ROW(0), COL(0), tOSD_PEO_LOGO, COLOR(_CP_WHITE ,_CP_BG));
	OsdFontPut1BitTable1(ROW(0), COL(22), tOSD_PEO_LOGO1, COLOR(_CP_WHITE ,_CP_BG));

	OsdFuncChangeColor1Bit(ROW(0), COL(0), WIDTH(44) , HEIGHT(8), COLOR(_CP_BLACK, _CP_RED));

	OsdFuncChangeColor1Bit(ROW(8), COL(0), WIDTH(44) , HEIGHT(6), COLOR(_CP_BLACK, _CP_BLACK));
//	OsdDispSetPosition(_POS_PERCENT, 54, 53);
	OsdDispSetPosition(_POS_PERCENT, 49, 53);

	OsdFuncEnableOsd();


	SET_OSD_LOGO_ON(_ON); 
} 
 
#elif(_LOGO_TYPE == _VIEWSONIC_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(26), HEIGHT(13), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_VIEWSONIC_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
   // OsdFontPut1BitTable( ROW(0), COL(39), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
 //   OsdFontPut1BitTable( ROW(0), COL(56), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO2, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    //OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}

#elif(_LOGO_TYPE == _KNIGHTEEN_LOGO)

void OsdDispShowLogo(void)
{
    g_ucLogoTimerCounter = 0;
    
    ScalerDDomainPatternGenAdjustColor(0, 0, 0);
    ScalerDDomainPatternGenEnable(_ENABLE);
    ScalerDDomainBackgroundEnable(_DISABLE);
    
    OsdFuncDisableOsd();

    OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);    
    OsdFuncApplyMap(WIDTH(74), HEIGHT(13), COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));

   //20140305 Abel 
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);  
#endif
    
    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
    OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
   // OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO1);

    OsdFontPut1BitTable( ROW(0), COL(0), tiOSD_KNIGHTEEN_LOGO0, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
   // OsdFontPut1BitTable( ROW(0), COL(39), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO1, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
 //   OsdFontPut1BitTable( ROW(0), COL(56), tiOSD_TONGFANG_SEIKI_PRO_1BIT_LOGO2, COLOR(_LOGO_CP_WHITE,_LOGO_CP_BLACK));
    
    OsdDispSetPosition(_POS_PERCENT, 50, 50);
    //OsdWindowDrawing(_OSD_WINDOW_2, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLACK);    
    OsdFuncEnableOsd();

#if(_INSTANT_TIMER_EVENT_0 == _ON)
    ScalerTimer0SetTimerCount(16);
#endif
    DebugMessageSystem("LOGO  test 1", 0);//jon add

    SET_OSD_LOGO_ON(_ON);    
}


#endif

#endif

//--------------------------------------------------
// Description  : OSD information function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/*
void OsdDispShowInformation(void)
{
    switch(SysSourceGetInputPort())
    {
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT) &&(_A0_PORT_SHIELD==_OFF))
        case _A0_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_A0,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
    break;      
#endif    
#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT)&&(_D0_PORT_SHIELD==_OFF))
        case _D0_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D0,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
        break;
#endif                    
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D1,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
           break;
#endif            
#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D2,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
           break;
#endif        
#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D3,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
          break;
#endif        
#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D4,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
          break;
#endif        
#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D5,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
            break;
#endif
#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
        case _D6_INPUT_PORT:
       COsdShowPageInputStringAll(_OSD_INPUT_D6,1);
     OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
         break;

#endif 
        default:
             ;
    }
    OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_ITEM_3, _STRING_INPUT_STRING_ALL, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);    
    OsdPropPutString(ROW(_OSD_NUMBER_3_ROW), COL(_OSD_NUMBER_2_COL+5), _PFONT_PAGE_2, _STRING_NOW_RESOLUTION, COLOR(_CP_LIGHTBLUE, _CP_BG), _ENGLISH);
   // OsdPropPutString(ROW(17 + 2), COL(23), _PFONT_PAGE_1, _STRING_HFREQPCLK, COLOR(_CP_BLUE, _CP_BG), _ENGLISH);

}

*/

#if((_AUDIO_SUPPORT == _ON) && (_AUDIO_HEADPHONE_SUPPORT == _ON))
//--------------------------------------------------
// Description	    : None
// Input Value	    : None
// Output Value     : None
//--------------------------------------------------
void OsdAudioHeadphoneScan(void)
{
	BYTE ucEarphonePolling = _FALSE;

	#if((_SLEEP_AUDIO_SUPPORT == _ON)&&(_OSD_STAND_ALONE_SELECT == _ON))
	if(GET_OSD_AUDIO_STAND_ALONE() == _TRUE)
	{
		switch(SysModeGetModeState())
		{
			case _MODE_STATUS_ACTIVE:
			case _MODE_STATUS_NOSUPPORT:
			case _MODE_STATUS_NOSIGNAL:
			case _MODE_STATUS_POWER_SAVING:
				ucEarphonePolling = _TRUE;
				break;
		}
	}
	else
	#endif		
	{
		if(SysModeGetModeState() == _MODE_STATUS_ACTIVE)
		{
			ucEarphonePolling = _TRUE;
		}			
	}	

	if((ucEarphonePolling == _TRUE) && (UserInterfaceGetAudioReadyToPlayStatus() == _TRUE) && (SysAudioGetAudioState() == _AUDIO_STATUS_PLAYBACK))

	{

		/*if(	(PCB_HP_MUTE_ON()&& PCB_EARPHONE_CONNECTED()) || 
			(PCB_AMP_MUTE_ON() && PCB_EARPHONE_DISCONNECTED()))
		{
	  DebugMessageAudio(" PCB_AMP_MUTE_ON()", PCB_AMP_MUTE_ON());

  DebugMessageAudio(" PCB_EARPHONE_CONNECTED", PCB_EARPHONE_CONNECTED());
			if(PCB_EARPHONE_CONNECTED())
			{
				UserAdjustAudioVolume(_OSD_VOLUME_MIN); 				
				PCB_HP_MUTE(_HP_MUTE_OFF);				
				PCB_AMP_MUTE(_AMP_MUTE_ON);									
				UserAdjustAudioVolume(GET_OSD_VOLUME());				
			}
			else
			{  
				UserAdjustAudioVolume(_OSD_VOLUME_MIN); 	
				ScalerTimerDelayXms(50);
				PCB_HP_MUTE(_HP_MUTE_ON);
				PCB_AMP_MUTE(_AMP_MUTE_OFF);				
				UserAdjustAudioVolume(GET_OSD_VOLUME());				
			}			
		} */

#if(_PCB_TYPE == _RL6449_SM2795A) //tdy add for popo
			if(PCB_EARPHONE_CONNECTED())
                          {
				// DebugMessageAudio(" 0000000", 0);

				//UserAdjustAudioVolume(_OSD_VOLUME_MIN); 	
				//ScalerTimerDelayXms(50);
                              ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);// TDY aad for audio popo
                                g_usVolumeEarphoneForPopo = _ON;
				 g_usVolumePowerForPopo= _OFF;
				
                               //   PCB_AMP_MUTE(_AMP_MUTE_OFF);	
				//PCB_HP_MUTE(_HP_MUTE_ON);
			//	PCB_AMP_MUTE(_AMP_MUTE_ON);				
				//UserAdjustAudioVolume(GET_OSD_VOLUME());				
			}
                       else
			{
			  //  DebugMessageAudio(" 11111111111", 0);
                          //  ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);// TDY aad for audio popo
                          if(g_usVolumeEarphoneForPopo == _ON)
                            {
                                g_usVolumeEarphoneForPopo= _OFF;
                               ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUDIO_MUTE_OFF);     // TDY aad for audio popo
                              DebugMessageAudio("(g_usVolumeEarphoneForPopo123 " ,0 );
                            }
			   if(g_usVolumePowerForPopo == _ON)
                            {
                                g_usVolumePowerForPopo= _OFF;
				PCB_AMP_MUTE(_AMP_MUTE_OFF);									
			         DebugMessageAudio("PCB_AMP_MUTE(_AMP_MUTE_OFF)0 0000", _AMP_MUTE_OFF);
                            }
			//	UserAdjustAudioVolume(_OSD_VOLUME_MIN); 				
				//PCB_HP_MUTE(_HP_MUTE_OFF);				
				//PCB_AMP_MUTE(_AMP_MUTE_OFF);									
				//UserAdjustAudioVolume(GET_OSD_VOLUME());				
			}
				
#endif
		
#if 0//(_PCB_TYPE == _RL6449_SM2775YTA_1DP2H_VBO) //tdy add for popo
			if(PCB_EARPHONE_CONNECTED())
                          {
				// DebugMessageAudio(" 0000000", 0);

				//UserAdjustAudioVolume(_OSD_VOLUME_MIN); 	
				//ScalerTimerDelayXms(50);
                              ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);// TDY aad for audio popo
                                g_usVolumeEarphoneForPopo = _ON;
				 g_usVolumePowerForPopo= _OFF;
				
                               //   PCB_AMP_MUTE(_AMP_MUTE_OFF);	
				//PCB_HP_MUTE(_HP_MUTE_ON);
			//	PCB_AMP_MUTE(_AMP_MUTE_ON);				
				//UserAdjustAudioVolume(GET_OSD_VOLUME());				
			}
                       else
			{
			  //  DebugMessageAudio(" 11111111111", 0);
                          //  ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_AUDIO_MUTE_OFF);// TDY aad for audio popo
                          if(g_usVolumeEarphoneForPopo == _ON)
                            {
                                g_usVolumeEarphoneForPopo= _OFF;
                               ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_AUDIO_MUTE_OFF);     // TDY aad for audio popo
                              DebugMessageAudio("(g_usVolumeEarphoneForPopo123 " ,0 );
                            }
			   if(g_usVolumePowerForPopo == _ON)
                            {
                                g_usVolumePowerForPopo= _OFF;
				PCB_AMP_MUTE(_AMP_MUTE_OFF);									
			         DebugMessageAudio("PCB_AMP_MUTE(_AMP_MUTE_OFF)0 0000", _AMP_MUTE_OFF);
                            }
			//	UserAdjustAudioVolume(_OSD_VOLUME_MIN); 				
				//PCB_HP_MUTE(_HP_MUTE_OFF);				
				//PCB_AMP_MUTE(_AMP_MUTE_OFF);									
				//UserAdjustAudioVolume(GET_OSD_VOLUME());				
			}
				
#endif

	}
}
#endif

#endif//#if(_OSD_TYPE == _OSTAR_2014_OSD)
