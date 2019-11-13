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
// ID Code      : RTD2014OsdDisplay.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDDISPLAY__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
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

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

void OSDFunctionAdj(WORD ucOsdState, WORD usValue);

BYTE OsdDisplayGetSourcePortString(void);
void RTDOsdFuncChangeColor2Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);

#if(_VGA_SUPPORT == _ON)
BYTE OsdDisplayGetVGAModeString(bit bUserMode);
#endif

BYTE OsdDispJudgeSourceType(void);
void OsdDispDisableOsd(void);
void OsdDispSetPosition(BYTE ucType, EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos);

void Heng(void);



void OsdDispMainMenu(void);
void OsdDispSliderAndNumber(WORD ucOsdState, WORD usValue);
WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle);
void OsdDisplaySixColorGetOneColor(BYTE ucColor);
void OsdDispHotKeyOptionMenu(BYTE ucOption);
void OsdDispOsdMessage(EnumOSDDispMsg enumMessage);

#if(_VGA_SUPPORT == _ON)
void OsdDispAutoConfigProc(void);
void OsdDisplayAutoBalanceProc(void);
#endif

void OsdDispOsdReset(void);
void OsdDispShowLogo(void);


void UpdateInterface(BYTE ucItem);

void UpdateSubInterface(BYTE ucItem);
void UpdateSubInterface3(BYTE ucItem);

void UpdateSubInterface2(BYTE ucItem);

void Update3thInterface(BYTE MainItem , BYTE SubItem);
void RTDOsdDisplaySlider(BYTE ucRow, BYTE ucCol, BYTE ucLength, WORD usValue, WORD usMax, WORD usMin, BYTE ucColor);
void OsdDispLeftMenu(void);
 void OsdDispLeftAimMenu(void);
void OsdDispRightMenu(void);
void COsdShowChooseLeftMenuText(BYTE number);
void COsdShowPageInputText(void);
void COsdShowPageInputTextSelect(BYTE InputOsd,BYTE InputType,BYTE NUM);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------
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
    /*
    if(GET_OSD_STATE() == _MENU_HOT_INPUT_ADJUST)
    {
      OsdPropPutString(ROW(2), COL(4), _PFONT_PAGE_2, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
    }
    else
    {
      OsdPropPutString(ROW(_OSD_NUMBER_1_ROW), COL(_OSD_NUMBER_2_COL), _PFONT_PAGE_2, _STRING_AUTO_SELECT, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);    
    }
    */
#if((_A0_INPUT_PORT_TYPE !=_A0_NO_PORT))
 COsdShowPageInputTextSelect(_OSD_INPUT_A0,_INPUT_OSD_VGA,0);
 #endif



 
#if((_D0_INPUT_PORT_TYPE == _D0_DVI_PORT))
DVInum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D0,_INPUT_OSD_DVI,DVInum);
#endif                    
#if(((_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)||(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)))
HDMInum++;
COsdShowPageInputTextSelect(_OSD_INPUT_D0,_INPUT_OSD_HDMI,HDMInum);
#endif           
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT))
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
					//OsdFontPut1FuncTableForm(8, 6, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,3);
					OsdFontPut1FuncTableForm(8, 12, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,_ARC_WINDOW_0);
					
					OsdFontPut1BitMainMenuIcon(10, 30, _LEFT_MENU_AIM_ICON_START+24 , _CP_ORANGE_H, _CP_BG);
					OsdFontPut1FuncTableForm(8, 28, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,_ARC_WINDOW_0);	
					
					OsdFontPut1BitMainMenuIcon(10, 46, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
					OsdFontPut1FuncTableForm(8, 44, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,_ARC_WINDOW_0);	
					
					OsdFontPut1BitMainMenuIcon(10, 62, _LEFT_MENU_AIM_ICON_START+48 , _CP_ORANGE_H, _CP_BG);	
					OsdFontPut1FuncTableForm(8, 60, _EDGE_LINE,8 ,6,_CP_WHITE,_CP_BLACK_1,_ARC_WINDOW_0);  
	
					break;
	
	
		
				case _STRING_LEFT_MENU_TIMER :
					OsdFontPut1FuncAimTableForm(7,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,1);	
					OsdFontPut1NumberTableForm(8, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(8, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(8, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					
					OsdFontPut1FuncAimTableForm(7,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,2); 	
					OsdFontPut1NumberTableForm(8, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(8, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(8, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);

					OsdFontPut1FuncAimTableForm(7,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,3); 	
					OsdFontPut1NumberTableForm(8, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(8, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(8, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);

					OsdFontPut1FuncAimTableForm(7,8+53, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 8+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,4); 	
					OsdFontPut1NumberTableForm(8, 10+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(8, 12+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(8, 14+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(8, 16+54, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);

					OsdFontPut1FuncAimTableForm(13,7, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(14, 8, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,5); 	
					OsdFontPut1NumberTableForm(14, 10, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(14, 12, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(14, 14, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(14, 16, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);

					OsdFontPut1FuncAimTableForm(13,8+17, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(14, 8+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,6); 	
					OsdFontPut1NumberTableForm(14, 10+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(14, 12+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(14, 14+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(14, 16+18, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);

					OsdFontPut1FuncAimTableForm(13,8+35, _EDGE_LINE,11,3,_CP_BLUE_65,_CP_BLACK_1,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(14, 8+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,9); 	
					OsdFontPut1NumberTableForm(14, 10+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
					OsdFontPut1NumberTableForm(14, 12+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,10);
					OsdFontPut1NumberTableForm(14, 14+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);	
					OsdFontPut1NumberTableForm(14, 16+36, _LEFT_MENU_NUMBER_ICON_START,2 ,3,_CP_WHITE,_CP_BLACK_1,0);
	
					break;
	
				default:
					 break;
			}
}


void OsdDispRightMenu(void)
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

    OsdFuncApplyMap(WIDTH(_OSD_RIGHT_KEY_WIDTH), HEIGHT(_OSD_RIGHT_KEY_HEIGHT), COLOR(_CP_BLACK_1, _CP_BG));

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
  
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
	 }
    else
#endif
    {
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(0), WIDTH(g_ucOsdWidth-2), HEIGHT((g_ucOsdHeight-2)), _CP_BLACK_1 );
		OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLACK_1,_CP_BG,_QUADRANGLE_WINDOW_0);
		OsdFontPut1FuncHLine(1, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLACK_1);
		OsdFontPut1FuncHLine(8, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_WHITE, _CP_BLACK_1);



      
    }


	
	

    OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 50, 50);



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
 
 
	   //  OSTARFactoryPanelUsedTimer();
	   //  OsdFontPut2BitTable(0, 0, tOSD_iREALTEK, 0, 0, 0, 0);
		 
 
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
    
		 OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT( (g_ucOsdHeight/2)-1), _CP_GREEN_119);
		 OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW( (g_ucOsdHeight/2)-1), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight/2)+1), _CP_GRAY_1 );//_CP_LIGHTBLUE
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
			 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+24 , _CP_RED, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
		 case _AIM_3:
	 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+48 , _CP_GREEN_119, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
		 case _AIM_4:
	 
	 
			 OsdFontPut1BitMainMenuIcon(0, 1, _LEFT_MENU_AIM_ICON_START+48 , _CP_RED, _CP_BG);
			 
			 //OsdFuncClearOsd(ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT(g_ucOsdHeight));
			 break;
			 
		  default:
			  break;
	 }
 
   //background    
	 }
 
	 
	 
 
	 OsdDispSetPosition(_POS_GAME_MODE, _OSD_POSITION_GLOBAL_A,50, 50);
 
 
 
	 // Osd Enable
	 ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	 OsdFuncEnableOsd();
 
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
		OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(g_ucOsdWidth), HEIGHT((g_ucOsdHeight)), _CP_BLACK_1 );
		OsdPropPutString(ROW(4), COL(34), _PFONT_PAGE_2, _STRING_GAME_MENU, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
		if(GET_OSD_Left_Menu_Choose()==_LEFT_AIM)
		{

			SET_OSD_STATE(_Menu_LEFTKEY_GAME);
			OsdThreeColorChooseTableForm(7, 13,_EDGE_LINE,22 ,10,_CP_BLUE_65, _CP_BLACK_1,_CP_GRAY,0);
			OsdThreeColorChooseTableForm(7, 40,_EDGE_LINE,22 ,10,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
			OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_ORANGE_H, _CP_GRAY);	 
			OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_WHITE, _CP_BG);
		}
		else 
		{

			SET_OSD_STATE(_Menu_LEFTKEY_TIMER);
			OsdThreeColorChooseTableForm(7, 13,_EDGE_LINE,22 ,10,_CP_BLUE_65, _CP_BLACK_1,_CP_BLACK_1,0);
			OsdThreeColorChooseTableForm(7, 40,_EDGE_LINE,22 ,10,_CP_BLUE_65, _CP_BLACK_1,_CP_GRAY,0);
			OsdFontPut1BitMainMenuIcon(11, 22, _LEFT_MENU_AIM_ICON_START , _CP_WHITE, _CP_BG);	 
			OsdFontPut1BitMainMenuIcon(11, 49, _LEFT_MENU_TIME_ICON_START , _CP_ORANGE_H, _CP_GRAY);

		}
  //background    
    }

	
	

if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
  {
       OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,(_OSD_H_POS_MAX-GET_OSD_HPOS()), (_OSD_V_POS_MAX-GET_OSD_VPOS()));
  }  
else
  {
       OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 50, 50);
}



    // Osd Enable
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncEnableOsd();

}









BYTE OsdDisplayGetSourcePortString(void)
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

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description :
// Input Value :
// Output Value :
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

//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description :
// Input Value : None
// Output Value : Source Port Number
//--------------------------------------------------
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
    SET_OSD_IN_FACTORY_MENU_STATUS(_FALSE);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdFuncDisableOsd();
    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
    g_ucOsdWidth = 0;
    g_ucOsdHeight = 0;
    g_ucOsdWidthB = 0;
    g_ucOsdHeightB = 0;
    Time_Flag = 0;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispSetPosition(BYTE ucType, EnumOsdPositionType enumOsdPositionType, WORD usHPos, WORD usVPos)
{
    WORD usX  = 0;
    WORD usY = 0;
    BYTE ucFonWidth = 12;
    BYTE ucFonHeight = 18;
    BYTE ucHorizontalDelayStep = 4;
    BYTE ucTempWidth = g_ucOsdWidth;
    BYTE ucTempHeight = g_ucOsdHeight-1;

    if((enumOsdPositionType == _OSD_POSITION_GLOBAL_B) ||
       (enumOsdPositionType == _OSD_POSITION_FONT_B))
    {
        ucTempWidth = g_ucOsdWidthB;
        ucTempHeight = g_ucOsdHeightB;
    }

    if(ScalerOsdGetHorizontalDelayStep() == _OSD_HORIZONTAL_DELAY_STEP_1_PIXEL)
    {
        ucHorizontalDelayStep = 1;
    }

    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        ucFonWidth *= 2;
        ucFonHeight *= 2;
    }

    if(ucType == _POS_PERCENT)
    {
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonHeight) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonWidth) * usVPos) / _OSD_V_POS_MAX;
        }
        else
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
        }
#elif(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
        if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
           (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempHeight * ucFonHeight) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempWidth * ucFonWidth) * usVPos) / _OSD_V_POS_MAX;
        }
        else
        {
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX-7;
        }
#else
        usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
        usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX;
#endif
    }
    else
    {
        // Notice!!! if osd set double size need to chek real position
        usX = usHPos;
        usY = usVPos;
    }
    if(GET_OSD_DOUBLE_SIZE() == _ON)
    {
        usX = usX / 2;
        usY = usY / 2;
    }
    if(usVPos ==0)
    {
			usY = 0;
    }
    else if(usVPos ==1)
    {
			usY += 4;

    }
      else if(usVPos ==100)
       {

			usY += 3;

       }
if(ucType == _POS_GAME_MODE)
{
            usX = ((((DWORD)(_PANEL_DH_WIDTH) - (DWORD)ucTempWidth * ucFonWidth) / ucHorizontalDelayStep) * usHPos) / _OSD_H_POS_MAX;
            usY = (((DWORD)_PANEL_DV_HEIGHT - (DWORD)ucTempHeight * ucFonHeight) * usVPos) / _OSD_V_POS_MAX-7;

usY= usY-1;
}

DebugMessageOsd("usY",usY);
    OsdFuncSetPosition(enumOsdPositionType, usX, usY);
}

//--------------------------------------------------
// Description :
// Input Value :
// Output Value :
//--------------------------------------------------




  
void OsdDispMainMenu(void)
{
    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;
    g_ucFontPointer3= _OSD_PAGE_3_START;

	  //      OsdFuncClearOsd(0, 0, WIDTH(20), HEIGHT(20));
    OsdFuncDisableOsd();
  //  ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncApplyMap(WIDTH(68), HEIGHT(25), COLOR(_CP_WHITE, _CP_BG));
        ScalerOsdCommandAllByte(0, 0x80, 10, 68);

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

    OsdFontVLCLoadFont1(_FONT1_GLOBAL);
	    OsdFontVLCLoadFont1(_FONT2_ICON);

    // OsdFontVLCLoadFont(_FONT2_ICON_MENU);
    /**************ICON************************/
   OsdFontPut2BitTable(ROW(_ICON1_ROW), COL(2), tOSD_ICON1, COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
   OsdFontPut2BitTable(ROW(_ICON2_ROW), COL(2), tOSD_ICON2, COLOR0(_CP_BLACK),COLOR1(_CP_RED),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
   
#if(_OSD_HHT==_ON)
   OsdFontPut2BitTable(ROW(_ICON3_ROW), COL(2), tOSD_ICON3, COLOR0(_CP_BLACK),COLOR1(_CP_WHITE),COLOR2(_CP_BLUE_65),COLOR3(_CP_WHITE));
#else
  OsdFontPut2BitTable(ROW(_ICON3_ROW), COL(2), tOSD_ICON3, COLOR0(_CP_BLACK),COLOR1(_CP_WHITE),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
#endif
   OsdFontPut2BitTable(ROW(_ICON4_ROW), COL(2), tOSD_ICON4, COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
   OsdFontPut2BitTable(ROW(_ICON5_ROW), COL(2), tOSD_ICON5, COLOR0(_CP_BLACK),COLOR1(_CP_WHITE),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));

    OsdFontPut1BitTable(ROW(_ICON6_ROW+1), COL(2), tOSD_FREESYNC, COLOR(_CP_BG , _CP_RED));

    RTDOsdFuncChangeColor2Bit(ROW(10), COL(2), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
//ScalerOsdChange2BitColor
    OsdFontPut1BitTable(ROW(4), COL(6), tOSD_LINE_ICON_UP, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(6), COL(6), tOSD_LINE_ICON, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(9), COL(6), tOSD_LINE_ICON, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(12), COL(6), tOSD_LINE_ICON, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(15), COL(6), tOSD_LINE_ICON, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(18), COL(6), tOSD_LINE_ICON, COLOR(_CP_BLUE_65, _CP_BG));
	OsdFontPut1BitTable(ROW(21), COL(2), tOSD_LINE_ICON1, COLOR(_CP_BLUE_65, _CP_BG));
	    
    OsdFontPut1BitTable(ROW(4), COL(ICON_LINE_LEFT), tOSD_LINE_LEFT1, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(4), COL(ICON_LINE_RIGHT), tOSD_LINE_RIGHT1, COLOR(_CP_BLUE_65, _CP_BG));

    //    OsdFuncChangeColor1Bit(ROW(8), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(12), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
     //   OsdFuncChangeColor1Bit(ROW(8), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(12), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

/***********************CHANGE COLOR*****************/
		UpdateInterface(1);
     //  RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(3), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
  //   OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
   //  OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
    //    OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(10), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);
    //    OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(10), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);




//WINDOW
   OsdWindowDrawing(_OSD_WINDOW_0, XSTART(0), YSTART(11), XEND(12*68), YEND(18*24-7), _CP_BLACK);
    OsdFontPut1BitTable(ROW(1-1), COL(0), tOSD_BIAN_UP, COLOR(_CP_BG, _CP_BG));
    OsdFontPut1BitTable(ROW(24), COL(0), tOSD_BIAN_DOWN, COLOR(_CP_BG, _CP_BG));
    //OsdFontPut1BitTable(ROW(1), COL(2), tOSD_PIXIO, COLOR(_CP_RED, _CP_BG));
#if(_OSD_HHT==_ON)

   OsdFontPut2BitTable(ROW(23), COL(52), tWANGZHI, COLOR0(_CP_BG),COLOR1(_CP_WHITE),COLOR2(_CP_BG),COLOR3(_CP_BG));
//jiexiangwangzhi
// OsdFontPut2BitTable(ROW(23), COL(19), tWANGZHI, COLOR0(_CP_BG),COLOR1(_CP_RED_1),COLOR2(_CP_BG),COLOR3(_CP_BG));
 //    OsdPropPutString(ROW(23), COL(56), _PFONT_PAGE_3, _STRING_FLICKER_FREE_SELECT, COLOR(_CP_WHITE, _CP_BLACK_1), _ENGLISH);

#endif
    
//CHU
    OsdFontPut1BitTable(ROW(3-1), COL(0), tOSD_LINE, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(22), COL(0), tOSD_LINE, COLOR(_CP_BLUE_65, _CP_BG));
#if(_OSD_HHT==_OFF)

//  OsdFontPut2BitTable(ROW(1), COL(2), tOSD_PIXIO_2BIT, COLOR0(_CP_RED_1),COLOR1(_CP_BG),COLOR2(_CP_WHITE),COLOR3(_CP_BG));
#else
 //OsdFontPut2BitTable(ROW(1), COL(30), tOSD_PIXIO_2BIT, COLOR0(_CP_GRAY),COLOR1(_CP_BG),COLOR2(_CP_RED_1),COLOR3(_CP_BLUE_65));
#endif
//KUANG
    OsdFontPut1BitTable(ROW(5-1), COL(17), tOSD_LINE_LEFT, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(5-1), COL(33), tOSD_LINE_RIGHT, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(5-1), COL(18), tOSD_LINE1_UP, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(19-1), COL(18), tOSD_LINE1_DOWN, COLOR(_CP_BLUE_65, _CP_BG));

    OsdFontPut1BitTable(ROW(5-1), COL(34), tOSD_LINE_LEFT, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(5-1), COL(50), tOSD_LINE_RIGHT, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(5-1), COL(35), tOSD_LINE1_UP, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(19-1), COL(35), tOSD_LINE1_DOWN, COLOR(_CP_BLUE_65, _CP_BG));

    OsdFontPut1BitTable(ROW(5-1), COL(51), tOSD_LINE_LEFT, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(5-1), COL(66), tOSD_LINE_RIGHT, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(5-1), COL(52), tOSD_LINE2_UP, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(19-1), COL(52), tOSD_LINE2_DOWN, COLOR(_CP_BLUE_65, _CP_BG));


//HENG
    OsdFontPut1BitTable(ROW(7-1), COL(18), tOSD_LINE1, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(9-1), COL(18), tOSD_LINE1, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(11-1), COL(18), tOSD_LINE1, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(13-1), COL(18), tOSD_LINE1, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(15-1), COL(18), tOSD_LINE1, COLOR(_CP_BLUE_65, _CP_BG));
    OsdFontPut1BitTable(ROW(17-1), COL(18), tOSD_LINE1, COLOR(_CP_BLUE_65, _CP_BG));




//FONT
        OsdPropPutString(ROW(6-1), COL(FONT1_COL), _PFONT_PAGE_3, _STRING_PICTURE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(9-1), COL(FONT1_COL), _PFONT_PAGE_3, _STRING_COLOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(12-1), COL(FONT1_COL), _PFONT_PAGE_3, _OSD_SETTING, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(15-1), COL(FONT1_COL), _PFONT_PAGE_3, _SET_UP, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(18-1), COL(FONT1_COL), _PFONT_PAGE_3, _STRING_OTHER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());

//FONT_SUB

//TIMING
          OsdPropPutStringCenter(ROW(11-1), COL(52), WIDTH(14), _PFONT_PAGE_ITEM_7, OsdDisplayGetSourcePortString(), COLOR(_CP_WHITE, _CP_BG), 0);

        OsdPropPutStringCenter(ROW(13-1), COL(52), WIDTH(14), _PFONT_PAGE_ITEM_8, _STRING_NOW_RESOLUTION, COLOR(_CP_WHITE, _CP_BG), 0);





    OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,GET_OSD_HPOS(), GET_OSD_VPOS());

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

//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
void OsdDispSliderAndNumber(WORD ucOsdState, WORD usValue)
{
	BYTE ucColor = 0;
	BYTE ucItemRow = 0;
	BYTE ucPFnotPageItem = 0;
	BYTE ucShowMax = 100;
	BYTE ucShowMin = 0;    
	BYTE ucItemCol = 0; 

	
	if((ucOsdState == MENU_PICTURE_BACKLIGHT_ADJ) || (ucOsdState == _MENU_PICTURE_CONTRAST_ADJ) || (ucOsdState == _MENU_COLOR_R_ADJ)|| (ucOsdState == _MENU_COLOR_G_ADJ)|| (ucOsdState == _MENU_COLOR_B_ADJ)
   ||(ucOsdState ==	_MENU_OSD_H_ADJ)    ||(ucOsdState ==	_MENU_OSD_V_ADJ) ||(ucOsdState ==	_MENU_OSD_TRNA_ADJ) ||(ucOsdState ==	_MENU_OSD_TIME_ADJ  )||(ucOsdState ==	_MENU_SETUP_VOLUME_ADJ  )
      )
	{
		 //SET_KEYREPEATENABLE();
		ucColor = ((_CP_RED<<4)|_CP_BLACK);// Adjust item.
	}
	else
	{
		ucColor = ((_CP_WHITE<<4)|_CP_BLACK);// Adjust item.

    }


	g_usAdjustValue = usValue;
	switch(ucOsdState)
	{
			case _MENU_PICTURE_BACKLIGHT:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
		//	g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _BACKLIGHT_MAX, _BACKLIGHT_MIN, _BACKLIGHT_CENTER);
			break;

				case _MENU_PICTURE_CONTRAST:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER);
			break;

				case 	_MENU_COLOR_R:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER);
			break;
				case 	_MENU_COLOR_G:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER);
			break;

							case 	_MENU_COLOR_B:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER);
			break;
							case 	_MENU_OSD_HPos:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			break;
							case 	_MENU_OSD_VPos:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			break;

							case 	_MENU_OSD_TRNAS:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
						ucShowMax = 4;
			ucShowMin = 0;
			break;

						case 	_MENU_OSD_TIME:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
						ucShowMax = 60;
			ucShowMin = 0;
			break;
			
						case _MENU_SETUP_VOLUME:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			

			break;	
							case 	_MENU_OSD_H_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_OSD_HPOS(g_usAdjustValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,GET_OSD_HPOS() , GET_OSD_VPOS());

			break;
							case 	_MENU_OSD_V_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_OSD_VPOS(g_usAdjustValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,GET_OSD_HPOS() , GET_OSD_VPOS());

			break;

							case 	_MENU_OSD_TRNA_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			ucShowMax = 4;
			ucShowMin = 0;
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 4, 0, _OFF);
			SET_OSD_TRANSPARENCY_STATUS(g_usAdjustValue);
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
			    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS()*50);

			break;

						case 	_MENU_OSD_TIME_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			ucShowMax = 60;
			ucShowMin = 0;
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 60, 5, _OFF);
			SET_OSD_TIME_OUT(g_usAdjustValue);
			SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

			
			break;
			
				case 	_MENU_COLOR_R_ADJ:
			
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
						g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER);
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_COLOR_TEMP_TYPE_USER_R(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER));
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
                UserAdjustContrast(GET_OSD_CONTRAST());

break;


							case 	_MENU_COLOR_G_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
						g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER);
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_COLOR_TEMP_TYPE_USER_G(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER));
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
                UserAdjustContrast(GET_OSD_CONTRAST());

			break;
				case 	_MENU_COLOR_B_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
						g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER);
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_COLOR_TEMP_TYPE_USER_B(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _COLORTEMP_MAX, _COLORTEMP_MIN, _COLORTEMP_CENTER));
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_COLORPROC_MSG);
                UserAdjustContrast(GET_OSD_CONTRAST());

			break;

			case MENU_PICTURE_BACKLIGHT_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
	       	SET_OSD_BACKLIGHT( (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF));
               UserAdjustBacklight(GET_OSD_BACKLIGHT());
               g_usAdjustValue=GET_OSD_BACKLIGHT();
        
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);

			break;

				case _MENU_PICTURE_CONTRAST_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			g_usAdjustValue=UserCommonAdjustRealValueToPercent(g_usAdjustValue, _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER);
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_OSD_CONTRAST(UserCommonAdjustPercentToRealValue(g_usAdjustValue, _CONTRAST_MAX, _CONTRAST_MIN, _CONTRAST_CENTER));

                UserAdjustContrast(GET_OSD_CONTRAST());
                SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_BRICON_MSG);

			break;
				case _MENU_SETUP_VOLUME_ADJ:
			ucItemRow = SLIDER_ROW;
			ucItemCol = SLIDER_COL;		
			ucPFnotPageItem = _PFONT_PAGE_ITEM_1;
			
			g_usAdjustValue = (BYTE)OsdDisplayDetOverRange(g_usAdjustValue, 100, 0, _OFF);
			SET_OSD_VOLUME(g_usAdjustValue);

                UserAdjustAudioVolume(GET_OSD_VOLUME());
           SET_OSD_EVENT_MESSAGE(_OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG);
			break;


			default:
		   break;	
}

       ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	RTDOsdDisplaySlider(ucItemRow, COL(ucItemCol), LENGTH(14), g_usAdjustValue, ucShowMax, ucShowMin, ucColor);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    OsdPropShowNumber(ucItemRow-1, COL(ucItemCol + LENGTH(10)), g_usAdjustValue, (_ALIGN_LEFT | _FORCE_SHOW_NUMBER_OFF | _SHOW_3), ucPFnotPageItem, ucColor);
}

//--------------------------------------------------
// Description    :
// Input Value    : None
// Output Value : None
//--------------------------------------------------
WORD OsdDisplayDetOverRange(WORD usValue, WORD usMax, WORD usMin, bit bCycle)
{
if((GET_OSD_STATE() == _MENU_PICTURE_ECO_ADJ) ||(GET_OSD_STATE() == _MENU_PICTURE_MAIN_SR_ADJ)||(GET_OSD_STATE() == _MENU_COLOR_TEMP_ADJ)||(GET_OSD_STATE() == _MENU_OSD_LANGUAGE_ADJ)||(GET_OSD_STATE() == _MENU_SETUP_INPUT_ADJ) 
 ||  (GET_OSD_STATE() == _MENU_OTHERS_RATIO_ADJ)  ||  (GET_OSD_STATE() == _MENU_OTHERS_LOWBLUE_ADJ)  )
{
    switch(GET_KEYMESSAGE())
    {
        case _LEFT_KEY_MESSAGE :
            if(usValue >= usMax)
            {
                if(bCycle == _ON)
                {
                    return usMin;
                }
                else
                {
                    return usMax;
                }
            }
            else
            {
                usValue++;
            }

            break;

        case _RIGHT_KEY_MESSAGE :
            if (usValue <= usMin)
            {
                if(bCycle == _ON)
                {
                    return usMax;
                }
                else
                {
                    return usMin;
                }
            }
            else
            {
                usValue--;
            }
            break;

        default:
            break;
    }
}



else
{

    switch(GET_KEYMESSAGE())
    {
        case _RIGHT_KEY_MESSAGE:
            if(usValue >= usMax)
            {
                if(bCycle == _ON)
                {
                    return usMin;
                }
                else
                {
                    return usMax;
                }
            }
            else
            {
                usValue++;
            }

            break;

        case _LEFT_KEY_MESSAGE:
            if (usValue <= usMin)
            {
                if(bCycle == _ON)
                {
                    return usMax;
                }
                else
                {
                    return usMin;
                }
            }
            else
            {
                usValue--;
            }
            break;

        default:
            break;
    }
}
    return usValue;
}

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

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Six Color Set One Color
// Input Value  : SixColor
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdDispHotKeyOptionMenu(BYTE ucOption)
{
    BYTE uctemp = 0;

    OsdFuncCloseWindow(_OSD_WINDOW_ALL);
    OsdFuncDisableOsd();
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncApplyMap(WIDTH(36), HEIGHT(8), COLOR(_CP_WHITE, _CP_BG));

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, HEIGHT(8), _DISABLE, 0, _ENABLE);
#endif

    OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
    OsdFuncTransparency(GET_OSD_TRANSPARENCY_STATUS());

    // Adjust Color Palette
    OsdPaletteSelectPalette(_PALETTE_MAIN_MENU);

    // Load Font & Icon
    OsdFuncSet2BitIconOffset(_2BIT_ICON_OFFSET);

    OsdFontVLCLoadFont(_FONT1_GLOBAL);
    // OsdFontVLCLoadFont(_FONT2_ICON_MENU);

    // Background window
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdWidth, _CP_BLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(24), g_ucOsdWidth, _CP_LIGHTBLUE);
    }
    else
#endif
    {
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), g_ucOsdHeight, _CP_BLUE);
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(24), g_ucOsdHeight, _CP_LIGHTBLUE);
    }

    // title
    switch(ucOption)
    {
        case _HOTKEY_DDCCI:
            // icon
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_DDCCI);

            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
            // string
       //     OsdPropPutStringCenter(ROW(6), COL(0), WIDTH(12), _PFONT_PAGE_1, _STRING_DDCCI, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());


            (GET_OSD_DDCCI_STATUS() == _ON) ? (uctemp = 1) : (uctemp = 2);

            OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(2), COL(3 + (12 * uctemp)), WIDTH(6), HEIGHT(4), _CP_LIGHTBLUE, _CP_RED, _CP_BG);

            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_1, _ICON_ON);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3 + (12 * 1)), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_BLUE, _CP_BG);

            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_2, _ICON_OFF);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3 + (12 * 2)), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_BLUE, _CP_BG);
            break;

        case _HOTKEY_DP_D0_OPTION:
        case _HOTKEY_DP_D1_OPTION:
        case _HOTKEY_DP_D2_OPTION:
        case _HOTKEY_DP_D6_OPTION:

            g_usAdjustValue=ucOption;
            // icon
            if(ucOption == _HOTKEY_DP_D0_OPTION)
            {
                OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_D0);
                (GET_OSD_DP_D0_VERSION() == _DP_VER_1_DOT_1) ? (uctemp = 1) : (uctemp = 2);
            }
            else if(ucOption == _HOTKEY_DP_D1_OPTION)
            {
                OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_D1);
                (GET_OSD_DP_D1_VERSION() == _DP_VER_1_DOT_1) ? (uctemp = 1) : (uctemp = 2);
            }
            else if(ucOption == _HOTKEY_DP_D2_OPTION)
            {
                OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_D2);
                (GET_OSD_DP_D2_VERSION() == _DP_VER_1_DOT_1) ? (uctemp = 1) : (uctemp = 2);
            }
            else if(ucOption == _HOTKEY_DP_D6_OPTION)
            {
                OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_0, _ICON_D6);
                (GET_OSD_DP_D6_VERSION() == _DP_VER_1_DOT_1) ? (uctemp = 1) : (uctemp = 2);
            }

            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3), (_1DYNAMIC_ICON_START + (0 * 24)), _CP_WHITE, _CP_BG);
            // string
            OsdPropPutStringCenter(ROW(6), COL(0), WIDTH(12), _PFONT_PAGE_1, _STRING_DP_OPTION, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
            OsdWindowDrawingByFontHighlight(_OSD_WINDOW_4_1, ROW(2), COL(3 + (12 * uctemp)), WIDTH(6), HEIGHT(4), _CP_LIGHTBLUE, _CP_RED, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_1, _ICON_1_DOT_1);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3 + (12 * 1)), (_1DYNAMIC_ICON_START + (1 * 24)), _CP_BLUE, _CP_BG);
            OsdFontVLCDynamicLoadIcon(_ICON_POS_UP_2, _ICON_1_DOT_2);
            OsdFontPut1BitMainMenuIcon(ROW(2), COL(3 + (12 * 2)), (_1DYNAMIC_ICON_START + (2 * 24)), _CP_BLUE, _CP_BG);
            break;

        default:
            break;
    }
    OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);

    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    OsdFuncEnableOsd();
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdDispOsdMessage(EnumOSDDispMsg enumMessage)
{

    OsdDispDisableOsd();

    g_ucFontPointer0 = _OSD_PAGE_0_START;
    g_ucFontPointer1 = _OSD_PAGE_1_START;
    g_ucFontPointer2 = _OSD_PAGE_2_START;
//SET_OSD_STATE(_OSD_NULL);
Time_Flag = 1;
	{
    OsdFuncApplyMap(WIDTH(22), HEIGHT(7), COLOR(_CP_BLACK_1, _CP_BG));

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
        OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(0), COL(0), WIDTH(12), HEIGHT(g_ucOsdWidth), _CP_BLACK_1);       
        OsdWindowDrawingByFont(_OSD_WINDOW_0, ROW(0), COL(12), WIDTH(g_ucOsdHeight-12),HEIGHT(g_ucOsdWidth), _CP_BLACK_1);
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
			OsdWindowDrawingByFont(_OSD_WINDOW_1, ROW(1), COL(0), WIDTH(g_ucOsdWidth-2), HEIGHT((g_ucOsdHeight-2)), _CP_BLACK_1 );
			OsdFontPut1FuncTableForm(0, 0, _LEFT_CORNER_0,g_ucOsdWidth -2,g_ucOsdHeight-2,_CP_BLACK_1,_CP_BG,_QUADRANGLE_WINDOW_0);
			OsdFontPut1FuncHLine(1, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_BLUE_65, _CP_BLACK_1);
			OsdFontPut1FuncHLine(5, 0, _WHITE_EDGE_1, g_ucOsdWidth ,_CP_BLUE_65, _CP_BLACK_1);
        }
    }

    //==== Show page item =======
    switch(enumMessage)
    {
        case _OSD_DISP_NOSIGNAL_MSG:
		OsdPropPutStringCenter(ROW(3), COL(0),22, _PFONT_PAGE_2, _STRING_NO_SIGNAL, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	
		        OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,50, 50);

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
      		OsdPropPutStringCenter(ROW(3), COL(0),22, _PFONT_PAGE_2, _STRING_NO_SIGNAL, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	

	 // OsdPropPutStringCenter(ROW(3), COL(0), 22,_PFONT_PAGE_2, _STRING_NO_CABLE, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	  
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
        OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,50, 50);
        break;
        
        case _OSD_DISP_NOSUPPORT_MSG:
                    OsdPropPutStringCenter(ROW(3), COL(0), WIDTH(22), _PFONT_PAGE_0, _STRING_NO_SUPPORT, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());
          OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 50, 50);

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
        OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,50, 50);
        break;
       
        case _OSD_DISP_FAIL_SAFE_MODE_MSG:
            OsdPropPutStringCenter(ROW(3), COL(0), WIDTH(22), _PFONT_PAGE_0, _STRING_NO_SUPPORT, COLOR(_CP_LIGHTBLUE, _CP_BG), GET_OSD_LANGUAGE());
          OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 50, 50);
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
     OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,50, 50);
           
            break;

        case _OSD_DISP_INPUT_SIGNAL_MSG:
        OsdPropPutStringCenter(ROW(3), COL(0), WIDTH(22), _PFONT_PAGE_0, OsdDisplayGetSourcePortString(), COLOR(_CP_WHITE, _CP_BG), _ENGLISH);
 
	// 	OsdDisplayGetSourcePort(ROW(3),COL(8));
            OsdDispSetPosition(_POS_PERCENT,_OSD_POSITION_GLOBAL_A, 95, 5);

            
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
		OsdPropPutStringCenter(ROW(3), COL(0),22, _PFONT_PAGE_2, _STRING_GO_TO_POWER_SAVING_MODE, COLOR(_CP_WHITE, _CP_BG), _ENGLISH);	
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
            OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A,50, 50);
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
    // SET_KEYMESSAGE(_HOLD_KEY_MESSAGE);
}
#endif // End of #if(_VGA_SUPPORT == _ON)

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispOsdReset(void)
{
    BYTE ucIndex = _ENGLISH;
	
	BYTE preOsdDisAudioSource=GET_OSD_AUDIO_SOURCE();//by wcy   与 QS命名不一样 保留其中一个

#if(_HIGHLIGHT_WINDOW_SUPPORT == _ON)
    ScalerColorHLWDDomainEnable(_FUNCTION_OFF);
#endif

    OsdDispDisableOsd();

    UserCommonNVRamRestoreSystemData();
    RTDNVRamRestoreOSDData();

    RTDNVRamRestoreUserColorSetting();
    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
    RTDNVRamRestoreSixColorData();

    RTDNVRamRestoreBriCon();
    RTDNVRamRestoreBacklight();

#if(_VGA_SUPPORT == _ON)
    UserCommonNVRamRestoreModeUserData();

    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        SET_VGA_MODE_DO_FIRST_AUTO(_TRUE);
        UserCommonModeSearchInitalUserAndCenterData(g_stVGAModeUserData.ucModeNumber);
        UserCommonNVRamSaveModeUserData();
    }
#endif
#if(_AUDIO_SUPPORT == _ON)
	SET_OSD_AUDIO_SOURCE(preOsdDisAudioSource);//by wcy 与 QS命名不一样 保留其中一个
    UserAdjustAudioVolume(GET_OSD_VOLUME());
#endif	
/*
				//if(GET_OSD_HDR_MODE() = =_HDR_MODE_OFF)
					{
					    UserCommonInterfaceLoadEmbeddedEdidData();
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(GET_HDMI_HOTPLUG_TIME());
                    PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
					}
					*/
    if (0)//(ucIndex != GET_OSD_LANGUAGE())
    {
        SET_OSD_LANGUAGE(ucIndex);
        RTDNVRamSaveOSDData();
    }
    OsdFuncSetOsdItemFlag();
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);


	SET_OSD_FACTORY_STATUS(_OFF);
	SET_OSD_BURN_STATUS(_OFF);
	RTDNVRamSaveOSDData();

    SET_OSD_STATE(_MENU_NONE);
}

//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
#if(_OSD_LOGO_TYPE ==  _DNA_LOGO)

//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispShowLogo(void)
{
	
		g_ucLogoTimerCounter = 0;
	
		ScalerDDomainPatternGenAdjustColor(0, 0, 0);
		ScalerDDomainPatternGenEnable(_ENABLE);
		ScalerDDomainBackgroundEnable(_DISABLE);
	
		OsdFuncDisableOsd();
		OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);
		OsdFuncApplyMap(WIDTH(47), HEIGHT(10), COLOR(_LOGO_CP_WHITE, _LOGO_CP_BG));
	
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
		ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);
#endif
	
		OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
		OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
		
		OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
	
		OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_REALTEK_1BIT_LOGO0, COLOR(_LOGO_CP_GRAY, _LOGO_CP_BLACK));
		  OsdFuncChangeColor1Bit(ROW(2), COL(4), WIDTH(6), HEIGHT(1), COLOR(_CP_ORANGE_H, _LOGO_CP_BLACK),0);
		  OsdFuncChangeColor1Bit(ROW(3), COL(3), WIDTH(8), HEIGHT(3), COLOR(_CP_ORANGE_H, _LOGO_CP_BLACK),0);
		  OsdFuncChangeColor1Bit(ROW(6), COL(4), WIDTH(6), HEIGHT(1), COLOR(_CP_ORANGE_H, _LOGO_CP_BLACK),0);

		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
	//	  OsdWindowDrawing(_OSD_WINDOW_0, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLUE);
		OsdFuncEnableOsd();
	
#if(_INSTANT_TIMER_EVENT_0 == _ON)
		ScalerTimer0SetTimerCount(16);
#endif
	
		SET_OSD_LOGO_ON(_ON);
}

#endif

#if(_OSD_LOGO_TYPE ==  _NEWSKILL_LOGO)

//--------------------------------------------------
// Description  : Logo showing function
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdDispShowLogo(void)
{
	
		g_ucLogoTimerCounter = 0;
	
		ScalerDDomainPatternGenAdjustColor(0, 0, 0);
		ScalerDDomainPatternGenEnable(_ENABLE);
		ScalerDDomainBackgroundEnable(_DISABLE);
	
		OsdFuncDisableOsd();
		OsdPaletteSelectPalette(_PALETTE_RTD_LOGO);
		OsdFuncApplyMap(WIDTH(50), HEIGHT(9), COLOR(_LOGO_CP_WHITE, _LOGO_CP_BG));
	
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
		ScalerOsdMapRotation(GET_OSD_ROTATE_STATUS(), _ENABLE, g_ucOsdHeight, _DISABLE, 0, _ENABLE);
#endif
	
		OsdFuncBlending(_OSD_TRANSPARENCY_ONLY_WINDOW);
		OsdFuncTransparency(_OSD_TRANSPARENCY_MAX);
		
		OsdFontVLCLoadFont(_REALTEK_1BIT_LOGO0);
	
		OsdFontPut1BitTable(ROW(0), COL(0), tiOSD_REALTEK_1BIT_LOGO0, COLOR(_LOGO_CP_BLACK , _LOGO_CP_WHITE));
		OsdFuncChangeColor1Bit(ROW(0), COL(0), WIDTH(13), HEIGHT(9), COLOR(_LOGO_CP_BLACK , _CP_ORANGE_H),0);
		OsdFuncChangeColor1Bit(ROW(0), COL(33), WIDTH(17), HEIGHT(5), COLOR(_LOGO_CP_BLACK, _CP_ORANGE),0);
		OsdFuncChangeColor1Bit(ROW(5), COL(32), WIDTH(18), HEIGHT(4), COLOR(_LOGO_CP_BLACK, _CP_ORANGE),0);

		  //OsdFuncChangeColor1Bit(ROW(6), COL(4), WIDTH(6), HEIGHT(1), COLOR(_CP_ORANGE_H, _LOGO_CP_BLACK),0);

		OsdDispSetPosition(_POS_PERCENT, _OSD_POSITION_GLOBAL_A, 50, 50);
	//	  OsdWindowDrawing(_OSD_WINDOW_0, XSTART(1), YSTART(1), XEND(_LOGO_WINDOW_SIZE_X), YEND(_LOGO_WINDOW_SIZE_Y), _LOGO_CP_BLUE);
		OsdFuncEnableOsd();
	
#if 0//(_INSTANT_TIMER_EVENT_0 == _ON)
		ScalerTimer0SetTimerCount(16);
#endif
	
		SET_OSD_LOGO_ON(_ON);
}

#endif

//--------------------------------------------------
// Description  : OSD information function
// Input Value  : None
// Output Value : None
//--------------------------------------------------


#if((_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) || (_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE))
//--------------------------------------------------
// Description  : OSD information function
// Input Value  : None
// Output Value : None
//--------------------------------------------------

#endif


void RTDOsdFuncChangeColor2Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3)
{
    BYTE ucCntY = 0;
    BYTE ucTemp = 0;

    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
	
    ucTemp = 0x80 | ((ucColor3 & 0x07) << 1) | ((ucColor0 & 0x04) >> 2);

    for(ucCntY = 0; ucCntY < ucHeight; ucCntY++)
    {
        ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, ucTemp, ucWidth);;
        usOsdAddr += g_ucOsdWidth;
    }

    usOsdAddr =  (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
		
    ucTemp = ((ucColor0 & 0x03) << 6) | ((ucColor2 & 0x07) << 3) | (ucColor1 & 0x07);

    for(ucCntY = 0; ucCntY < ucHeight; ucCntY++)
    {
        ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucTemp, ucWidth);;
        usOsdAddr += g_ucOsdWidth;    
    }
}

void UpdateInterface(BYTE ucItem)
{
/********************
_CP_BLACK  _CP_WHITE   _CP_YELLOW     _CP_WHITE   2
_CP_BLACK   _CP_RED    _CP_GREEN_119  _CP_BLUE   2
_CP_BLACK  _CP_WHITE   _CP_BLACK     _CP_WHITE  4
_CP_BLACK  _CP_WHITE   _CP_BLUE        _CP_WHITE  4
_CP_BLACK  _CP_WHITE   _CP_WHITE    _CP_BLUE  3


*********************/

	BYTE Mark[5] = {0};

	BYTE   i = 0;
	BYTE   color = 0;
#if(_OSD_HHT==_OFF)
color=_CP_WHITE;

#else
color=_CP_RED;

#endif
	if(GET_OSD_COLOR_EFFECT() !=_ECO_MODE_USER)
	{
		g_ucSubMask[0] |= (_BIT0 | _BIT1 |_BIT3);

	}
	else
	{
		g_ucSubMask[0] = 0;

	}

  if(GET_COLOR_TEMP_TYPE() != _CT_USER)
	{
			g_ucSubMask[1] |= (_BIT1 | _BIT2 |_BIT3);

    }
    else
    	{
			g_ucSubMask[1] = 0;

    }

	        OsdFuncClearOsd(FONT1_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT2_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT3_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT4_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT5_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));

		switch(ucItem)
		{

		case 1:
		Mark[0] =  (g_ucSubMask[0] & 0x01);
		Mark[1] = (g_ucSubMask[0] & 0x02);
		Mark[2] = (g_ucSubMask[0] & 0x04);
		Mark[3] = (g_ucSubMask[0] & 0x08);
		Mark[4] = (g_ucSubMask[0] & 0x10);
				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_BRIGHTNESS, COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_CONTRAST, COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _ECO, COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT4_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _MAIN_SR, COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT5_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_HDR, COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());


		break;

		case 2:
				Mark[0] =  (g_ucSubMask[1] & 0x01);
		Mark[1] = (g_ucSubMask[1] & 0x02);
		Mark[2] = (g_ucSubMask[1] & 0x04);
		Mark[3] = (g_ucSubMask[1] & 0x08);
		Mark[4] = (g_ucSubMask[1] & 0x10);
				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_COLOR_TEMP, COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_R, COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_G, COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT4_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_B, COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());


		 break;




		case 3:
				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_LANGUAGE, COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OSD_HPOS, COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OSD_VPOS, COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT4_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_TRANSPARENCY, COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT5_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OSD_TIMEOUT, COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());


		 break;    


		 case 4:
				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_INPUT, COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
#if(_OSD_AUDIO_SUPPORT ==  _ON)
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_MUTE, COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_VOLUME, COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
#else
                            OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_MUTE, COLOR( _CP_GRAY , _CP_BLACK_1), GET_OSD_LANGUAGE());
                            OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_VOLUME, COLOR( _CP_GRAY , _CP_BLACK_1), GET_OSD_LANGUAGE());

#endif
				OsdPropPutString(ROW(FONT4_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_RESET, COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());


		 break;


		 case 5:



				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_RATIO, COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_LOW_BLUE, COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OD, COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());
			//	OsdPropPutString(ROW(FONT4_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_FREESYNC, COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1), GET_OSD_LANGUAGE());

		 break;
				 case 6:
if((SysSourceGetInputPort() == _D0_INPUT_PORT )||(SysSourceGetInputPort() == _D1_INPUT_PORT ))
{
				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL+1), _PFONT_PAGE_0, _STRING_OFF, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL+1), _PFONT_PAGE_0, _STRING_ON, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	          OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_FREE_SYNC_STATUS()*2), COL(31), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));
}
else
{
				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL+1), _PFONT_PAGE_0, _STRING_OFF, COLOR(_CP_GRAY , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL+1), _PFONT_PAGE_0, _STRING_ON, COLOR(_CP_GRAY , _CP_BLACK_1), GET_OSD_LANGUAGE());


}
		 break;

		}
 switch(ucItem)
    {
        case 1:
        //2bit
        
#if(_OSD_HHT==_ON)
		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(3), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
		//	  RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLUE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
			RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_RED));
			RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(color));
			RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_RED),COLOR3(_CP_BLUE));
#else
	   RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(3), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));

#endif
//////////////////heng
      OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

/////////up down
        OsdFuncChangeColor1Bit(ROW(_ICON2_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(15), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON2_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(15), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
//////////
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);


            break;

        case 2:
		
#if(_OSD_HHT==_ON)
		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
    //   RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
    //   RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
    //   RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));
#else
	 RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
	 RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
	RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
	RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
	RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
	RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));

#endif

      OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

        OsdFuncChangeColor1Bit(ROW(_ICON3_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(12), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON3_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(12), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);


        OsdFuncChangeColor1Bit(ROW(_ICON2_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON2_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;

        case 3:
			
#if(_OSD_HHT==_ON)
      RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
//		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
   //    RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_RED));
  //     RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
  //     RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));
#else
      RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_RED ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_RED));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));
#endif
      OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);


        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(6), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(6), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

        OsdFuncChangeColor1Bit(ROW(_ICON4_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(9), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON4_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(9), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);


        OsdFuncChangeColor1Bit(ROW(_ICON3_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON3_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;

        case 4:
        //////////
        
#if(_OSD_HHT==_ON)
      RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
//		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
 //      RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_RED));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_RED));
 //      RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));
#else
      RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_RED));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_RED));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_WHITE),COLOR3(_CP_BLUE));

#endif
/////////////////////
      OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

/////////////////
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(9), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(9), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

        OsdFuncChangeColor1Bit(ROW(_ICON5_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(6), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON5_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(6), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);


        OsdFuncChangeColor1Bit(ROW(_ICON4_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON4_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;
            
      case 5:
	  	
#if(_OSD_HHT==_ON)
     RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
//		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
 //      RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
 //      RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_RED));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_RED),COLOR3(_CP_BLUE));
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);
#else
	 RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
	   RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_RED));
	  RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_RED),COLOR3(_CP_BLUE));
	  OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

#endif
      OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);


        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(12), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(12), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);

        OsdFuncChangeColor1Bit(ROW(_ICON5_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON5_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);

            break;
      case 6:
#if(_OSD_HHT==_ON)
      RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
	//	RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
    //   RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
//    RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
  //     RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_RED),COLOR3(_CP_BLUE));
#else
      RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_BLACK ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
		RTDOsdFuncChangeColor2Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_YELLOW),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON2_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_GREEN_119),COLOR3(_CP_BLUE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON3_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLUE),COLOR3(_CP_WHITE));
       RTDOsdFuncChangeColor2Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL), LENGTH(4), HEIGHT(1), COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_RED),COLOR3(_CP_BLUE));

#endif
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW+2), COL(_ICON_COL), WIDTH(13), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);
      OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(_ICON4_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);

       OsdFuncChangeColor1Bit(ROW(_ICON1_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(color, _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(_ICON5_ROW+2), COL(_ICON_COL+4), WIDTH(9), HEIGHT(1), COLOR(_CP_RED, _CP_BLACK_1),0);






        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(15), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON1_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(15), COLOR(_CP_BLACK_1, _CP_BLACK_1),0);


        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW), COL(ICON_LINE_LEFT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);
        OsdFuncChangeColor1Bit(ROW(_ICON6_ROW), COL(ICON_LINE_RIGHT), WIDTH(1), HEIGHT(3), COLOR(_CP_RED, _CP_BLACK_1),0);

      
          break;
      
        default:
            break;
    }     


 switch(ucItem)
{
     case 1:
     		  OsdFontPut1BitTable(ROW(_ICON2_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON2_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_RED, _CP_BG));


		  
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_BG, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_BG, _CP_BG));


     break;

   case 2:
		  OsdFontPut1BitTable(ROW(_ICON2_ROW-1), COL(ICON_LINE_LEFT), tOSD_DIAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON2_ROW-1), COL(ICON_LINE_RIGHT), tOSD_DIAN_RIGHT, COLOR(_CP_RED, _CP_BG));
		


		  
		  OsdFontPut1BitTable(ROW(_ICON3_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON3_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_RED, _CP_BG));


     break;

   case 3:
		  OsdFontPut1BitTable(ROW(_ICON3_ROW-1), COL(ICON_LINE_LEFT), tOSD_DIAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON3_ROW-1), COL(ICON_LINE_RIGHT), tOSD_DIAN_RIGHT, COLOR(_CP_RED, _CP_BG));
		  
		  OsdFontPut1BitTable(ROW(_ICON4_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON4_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_RED, _CP_BG));

		  OsdFontPut1BitTable(ROW(_ICON2_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_BG, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON2_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_BG, _CP_BG));

     break;


        case 4:
		  OsdFontPut1BitTable(ROW(_ICON4_ROW-1), COL(ICON_LINE_LEFT), tOSD_DIAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON4_ROW-1), COL(ICON_LINE_RIGHT), tOSD_DIAN_RIGHT, COLOR(_CP_RED, _CP_BG));
		  
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_RED, _CP_BG));

		  OsdFontPut1BitTable(ROW(_ICON3_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_BG, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON3_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_BG, _CP_BG));

     break;

        case 5:
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_LEFT), tOSD_DIAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_RIGHT), tOSD_DIAN_RIGHT, COLOR(_CP_RED, _CP_BG));
		  

		  OsdFontPut1BitTable(ROW(_ICON4_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_BG, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON4_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_BG, _CP_BG));


		  OsdFontPut1BitTable(ROW(_ICON6_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON6_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_RED, _CP_BG));

     break;

             case 6:

		  OsdFontPut1BitTable(ROW(_ICON6_ROW-1), COL(ICON_LINE_LEFT), tOSD_DIAN_LEFT, COLOR(_CP_RED, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON6_ROW-1), COL(ICON_LINE_RIGHT), tOSD_DIAN_RIGHT, COLOR(_CP_RED, _CP_BG));
		  

		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_LEFT), tOSD_QUAN_LEFT, COLOR(_CP_BG, _CP_BG));
		  OsdFontPut1BitTable(ROW(_ICON5_ROW-1), COL(ICON_LINE_RIGHT), tOSD_QUAN_RIGHT, COLOR(_CP_BG, _CP_BG));


             
     break;

        default:
            break;
}

	
}


void UpdateSubInterface(BYTE ucItem)
{
	BYTE Mark[5] = {0};

		if(GET_OSD_COLOR_EFFECT() != _ECO_MODE_USER)
		{
			g_ucSubMask[0] |= (_BIT0 | _BIT1 |_BIT3);

		}
		else
		{
			g_ucSubMask[0] = 0;

		}


    	Mark[0] =  (g_ucSubMask[0] & 0x01);
		Mark[1] = (g_ucSubMask[0] & 0x02);
		Mark[2] = (g_ucSubMask[0] & 0x04);
		Mark[3] = (g_ucSubMask[0] & 0x08);
		Mark[4] = (g_ucSubMask[0] & 0x10);
	 switch(ucItem)
	{
		case 1:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);




		break;


		case 2:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);



		break;

		   case 3:


		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);

		break;


		   case 4:


		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);

		break;

		   case 5:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);


		break;

		default:
		  break;

	}

}

void UpdateSubInterface3(BYTE ucItem)
{
	BYTE Mark[5] = {0};

	 switch(ucItem)
	{
		case 1:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);




		break;


		case 2:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);



		break;

		   case 3:


		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);

		break;


		   case 4:


		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);

		break;

		   case 5:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);


		break;

		default:
		  break;

	}

}

void UpdateSubInterface2(BYTE ucItem)
{
	BYTE Mark[5] = {0};

  if(GET_COLOR_TEMP_TYPE() != _CT_USER)
	{
			g_ucSubMask[1] |= (_BIT1 | _BIT2 |_BIT3);

    }
    else
    {
			g_ucSubMask[1] = 0;


    }
    		Mark[0] =  (g_ucSubMask[1] & 0x01);
		Mark[1] = (g_ucSubMask[1] & 0x02);
		Mark[2] = (g_ucSubMask[1] & 0x04);
		Mark[3] = (g_ucSubMask[1] & 0x08);
		Mark[4] = (g_ucSubMask[1] & 0x10);
	 switch(ucItem)
	{
		case 1:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);




		break;


		case 2:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);



		break;

		   case 3:


		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);

		break;


		   case 4:


		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);

		break;

		   case 5:

		
       OsdFuncChangeColor1Bit(ROW(FONT1_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[0]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[1]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[2]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[3]? _CP_GRAY : _CP_WHITE) , _CP_BLACK_1),0);
       OsdFuncChangeColor1Bit(ROW(FONT5_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR((Mark[4]? _CP_GRAY : _CP_RED) , _CP_BLACK_1),0);


		break;

		default:
		  break;

	}

}
void Update3thInterface(BYTE MainItem , BYTE SubItem)
{
			BYTE i =0;

	        OsdFuncClearOsd(FONT1_ROW, FONT3_COL-1, WIDTH(15), HEIGHT(13));
	 switch(MainItem)
	{
		   case 1:
							switch(SubItem)
							{
								 case 1:
							         OsdDispSliderAndNumber(_MENU_PICTURE_BACKLIGHT,GET_OSD_BACKLIGHT()); 
	 
								break;

								 case 2:
										OsdDispSliderAndNumber(_MENU_PICTURE_CONTRAST,GET_OSD_CONTRAST()); 

								break;
																																														     																																					
																																												
								 case 3:
								 		Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_STANDARD, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_MOVE, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT3_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_PHOTO, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT4_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_GAME, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT5_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_FPS, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT6_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_RTS, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT7_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_USER, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());

	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_COLOR_EFFECT()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));

								break;
								 

								 case 4:
										Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_OFF, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_WEAK, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT3_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_MEDIAN, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT4_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_STRONG, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT5_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_STRONGEST, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_SHARPNESS()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));
						break;

								 case 5:

										Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_OFF, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_HDR_AUTO, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT3_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_HDR_2048, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_HDR_MODE()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));


								 

								break;

								default:
								break;
							}





		break;

		   case 2:
							switch(SubItem)
							{
																																						  
								 case 1:
								 //_CT_USER
								 		Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_6500K, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_9300K, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT3_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_7500K, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());

										OsdPropPutString(ROW(FONT4_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_USER_DEFINE, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_COLOR_TEMP_TYPE()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));


								break;

								 case 2:
							         OsdDispSliderAndNumber(_MENU_COLOR_R,GET_COLOR_TEMP_TYPE_USER_R()); 

								break;

								 case 3:
							         OsdDispSliderAndNumber(_MENU_COLOR_G,GET_COLOR_TEMP_TYPE_USER_G()); 

								break;

								 case 4:
							         OsdDispSliderAndNumber(_MENU_COLOR_B,GET_COLOR_TEMP_TYPE_USER_B()); 

								break;

								 case 5:

								break;

								default:
								break;
							}

		break;

		   case 3:
							switch(SubItem)
							{
								 case 1:
								 		Heng();
										#if 0
								for(i=0; i<7;i++)
								{
							    OsdFontPut1BitTable(ROW(FONT1_ROW+(i*2)), COL(FONT3_COL), tSTRING_YUYAN[i], COLOR(_CP_WHITE, _CP_BG));
	
								//   OsdFontPut2BitTable(ROW(FONT1_ROW+(i*2)), COL(FONT3_COL), tSTRING_YUYAN[i], COLOR0(_CP_BLACK),COLOR1(_CP_WHITE ),COLOR2(_CP_BLACK),COLOR3(_CP_BLACK));
						 		}
										//OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_CHINESE, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_LANGUAGE()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));

										#endif
								break;

								 case 2:
							         OsdDispSliderAndNumber(_MENU_OSD_HPos,GET_OSD_HPOS()); 
								break;

								 case 3:
							         OsdDispSliderAndNumber(_MENU_OSD_VPos,GET_OSD_VPOS()); 

								break;


								 case 4:
							         OsdDispSliderAndNumber(_MENU_OSD_TRNAS,GET_OSD_TRANSPARENCY_STATUS()); 


								break;

								 case 5:
							         OsdDispSliderAndNumber(_MENU_OSD_TIME,GET_OSD_TIME_OUT()); 

								break;

								default:
								break;
							}

		break;

		   case 4:
							switch(SubItem)
							{
								 case 1:
			//	OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_AUTO, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
			//		i++;
#if(_A0_INPUT_PORT_TYPE !=_A0_NO_PORT)
			OsdPropPutString(ROW(FONT1_ROW+i*2), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_A0, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	               i++;
#endif

#if(_D0_INPUT_PORT_TYPE !=_D0_NO_PORT)
			OsdPropPutString(ROW(FONT1_ROW+i*2), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_D0, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
			i++;
#endif

#if(_D1_INPUT_PORT_TYPE !=_D1_NO_PORT)
			OsdPropPutString(ROW(FONT1_ROW+i*2), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_D1, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
			i++;
#endif

#if(_D2_INPUT_PORT_TYPE !=_D2_NO_PORT)
			OsdPropPutString(ROW(FONT1_ROW+i*2), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_D2, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
			i++;
#endif
#if(_D3_INPUT_PORT_TYPE !=_D3_NO_PORT)
			OsdPropPutString(ROW(FONT1_ROW+i*2), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_D3, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
			i++;
#endif
#if(_D4_INPUT_PORT_TYPE !=_D4_NO_PORT)
			OsdPropPutString(ROW(FONT1_ROW+i*2), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_D4, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
#endif



					 		Heng();
	                 OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_INPUT_PORT_OSD_ITEM()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));


								break;

								 case 2:
								 		Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_OFF, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_ON, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_LED()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));

								 

								break;

								 case 3:
							         OsdDispSliderAndNumber(_MENU_SETUP_VOLUME,GET_OSD_VOLUME()); 
								 

								break;

								 case 4:
					 		Heng();

								break;

								 case 5:

								break;

								default:
								break;
							}

		break;

		   case 5:
							switch(SubItem)
							{
								 case 1:
								 		Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_FULL_SCREEN, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_16_9, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT3_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_4_3, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
									//	OsdPropPutString(ROW(FONT4_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_5_4, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
									//	OsdPropPutString(ROW(FONT5_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_ORIGIN, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());



	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_ASPECT_RATIO_TYPE()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));

								break;

								 case 2:
										Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_OFF, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_WEAK, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT3_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_MEDIAN, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT4_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_STRONG, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT5_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_STRONGEST, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_LOW_BLUE()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));
								break;

								 case 3:
								 		Heng();
										OsdPropPutString(ROW(FONT1_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_OFF, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
										OsdPropPutString(ROW(FONT2_ROW), COL(FONT3_COL), _PFONT_PAGE_1, _STRING_ON, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
	                              	OsdFontPut1BitTable(ROW(FONT1_ROW+GET_OSD_OD_STATUS()*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_WHITE , _CP_BLACK_1));


								break;

								 case 4:

								break;

								 case 5:

								break;

								default:
								break;
							}

		break;
		
		default:
		  break;
	}
}





void RTDOsdDisplaySlider(BYTE ucRow, BYTE ucCol, BYTE ucLength, WORD usValue, WORD usMax, WORD usMin, BYTE ucColor)
{
	BYTE xdata ucCnt = 0;
    BYTE xdata ucCount = 0;
    BYTE xdata ucHTemp = ucCol;
    BYTE *pArray = 0;

	BYTE xdata ucTmp[32] = {0};

	if(usValue < usMin)
	{
		usValue = usMin;
	}

	if(usValue > usMax)
	{
		usValue = usMax;
	}

	usValue -= usMin;
	// ------------------------------------------------------------------------
	// Draw MINUS ICON
	// ------------------------------------------------------------------------
	ucTmp[0] = _HKC_BAR_L;
	// ------------------------------------------------------------------------
	// Draw BAR
	// ------------------------------------------------------------------------
	for(ucCnt = 1; ucCnt < (ucLength - 1); ucCnt++)
	{
		ucTmp[ucCnt] = _HKC_BAR0;
	}

	if(usMax > usMin)
	{
		ucCnt = ((WORD)(usValue * (ucLength - 2))) / (usMax - usMin);

		if(ucCnt < (ucLength - 2))
		{
			ucTmp[ucCnt + 1] = (_HKC_BAR0) + (((((WORD)(usValue * (ucLength - 2))) * _SLIDER_RESOLUTION) / (usMax - usMin)) % _SLIDER_RESOLUTION);
		}
		for(; ucCnt > 0; ucCnt--)
		{
			ucTmp[ucCnt] = _HKC_BAR10;
		}
	}

	if((ucTmp[ucLength - 2] == _HKC_BAR10) && ((usValue + usMin) != usMax))
	{
		ucTmp[ucLength - 2] = _HKC_BAR9;
	}

	if((ucTmp[1] == _HKC_BAR0) && ((usValue + usMin) != usMin))
	{
		ucTmp[1] = _HKC_BAR1;
	}

	// ------------------------------------------------------------------------
	// Draw PLUS ICON
	// ------------------------------------------------------------------------
	ucTmp[ucLength - 1] = _HKC_BAR_R;
	ucTmp[ucLength] = _END_;

	//RTDOsdFuncPutString(ucRow, ucCol, GET_OSD_LANGUAGE(), ucTmp, ucColor);
    pArray = ucTmp;


    while(*pArray != _END_)
    {
        if(*pArray == _NEXT_)
        {
            ucRow++;
            ucHTemp = ucCol;
            pArray++;
        }
        else if(*pArray == _SPACE_)
        {
            ucHTemp++;
            pArray++;
        }
        else if(*pArray == _REPEAT_)
        {
            ucCount =*(pArray + 1) - 1;
            
            while(ucCount > 0)
            {
                OsdFontPut1Bit(ucRow, ucHTemp, *(pArray - 1), ucColor);
                ucHTemp++;
       
                if((ucHTemp == g_ucOsdWidth) && (*(pArray + 1) != _NEXT_))
                {
                    ucRow++;
                    ucHTemp =ucCol;  
                }
                ucCount--;
            }
            pArray += 2;
        }
        else
        {            
            OsdFontPut1Bit(ucRow, ucHTemp, *pArray, ucColor);
            ucHTemp++;

            if((ucHTemp == g_ucOsdWidth) && (*(pArray + 1) != _NEXT_))
            {
                ucRow++;
                ucHTemp = ucCol;  
            }
            pArray++;
        }
    }
}


void Heng(void)
{
    OsdFontPut1BitTable(ROW(7-1), COL(FONT3_COL-1), tOSD_LINE1, COLOR(_CP_WHITE, _CP_BG));
    OsdFontPut1BitTable(ROW(9-1), COL(FONT3_COL-1), tOSD_LINE1, COLOR(_CP_WHITE, _CP_BG));
    OsdFontPut1BitTable(ROW(11-1), COL(FONT3_COL-1), tOSD_LINE1, COLOR(_CP_WHITE, _CP_BG));
    OsdFontPut1BitTable(ROW(13-1), COL(FONT3_COL-1), tOSD_LINE1, COLOR(_CP_WHITE, _CP_BG));
    OsdFontPut1BitTable(ROW(15-1), COL(FONT3_COL-1), tOSD_LINE1, COLOR(_CP_WHITE, _CP_BG));
    OsdFontPut1BitTable(ROW(17-1), COL(FONT3_COL-1), tOSD_LINE1, COLOR(_CP_WHITE, _CP_BG));
}


void OSDFunctionAdj(WORD ucOsdState, WORD usValue)
{
	BYTE ucColor = 0;
	//BYTE ucItemRow = 0;
//	BYTE ucItemCol = 0;
	BYTE i = 0;
	BYTE MaxItem = 0;
   BYTE  Clean1 = 0;
   BYTE  Clean2 = 0;


	switch(ucOsdState)
	{
			case _MENU_PICTURE_ECO_ADJ:
			MaxItem = 7-1;
				
            UserAdjustColorEffectMode();


		
	
		//	 ScalerColorOutputGammaEnable(_FUNCTION_ON);				
		//	UserAdjustGamma(GET_OSD_GAMMA());

			break;

			case _MENU_PICTURE_HDR_ADJ:
			
			MaxItem = 3-1;
	    if(GET_KEYMESSAGE() != _MENU_KEY_MESSAGE)
	    {
	            UserCommonAdjustHDR(_HDR_FLOW_OSD_MODE_CHANGE);
		}

			break;

			case _MENU_PICTURE_MAIN_SR_ADJ:
			
			MaxItem = 5-1;
				UserCommonAdjustSharpness(SysSourceGetInputPort());


			break;
			case _MENU_COLOR_TEMP_ADJ:
			
			MaxItem = 3;
	

				if(GET_COLOR_TEMP_TYPE() != _CT_USER)
				{
					g_ucSubMask[1] |= (_BIT1 | _BIT2 |_BIT3);

				   OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_GRAY, _CP_BLACK_1),0);
				   OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_GRAY  , _CP_BLACK_1),0);
				   OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_GRAY, _CP_BLACK_1),0);

				}
				else
				{
					g_ucSubMask[1]= 0;

				   OsdFuncChangeColor1Bit(ROW(FONT2_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);
				   OsdFuncChangeColor1Bit(ROW(FONT3_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR( _CP_WHITE  , _CP_BLACK_1),0);
				   OsdFuncChangeColor1Bit(ROW(FONT4_ROW), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE, _CP_BLACK_1),0);

				}	

			            RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                UserAdjustContrast(GET_OSD_CONTRAST());

  	   break;	

			case _MENU_SETUP_INPUT_ADJ:

			MaxItem = _OSD_INPUT_AMOUNT-1;

break;

			case _MENU_SETUP_MUTE_ADJ:

			MaxItem = 1;
           //     UserAdjustAudioMuteSwitch();
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
           

break;



			case _MENU_OTHERS_RATIO_ADJ:

			MaxItem = 3-1;
					UserCommonAdjustAspectRatio();

break;

			case _MENU_OTHERS_LOWBLUE_ADJ:

			MaxItem = 5-1;
UserAdjustContrast(GET_OSD_CONTRAST());
break;

				case _MENU_OTHERS_OD_ADJ:

			MaxItem = 1;
			    ScalerODEnable(GET_OSD_OD_STATUS());


break;	

				case _MENU_OTHERS_FREESYNC_ADJ:
			MaxItem = 1;



break;	

case _MENU_OSD_LANGUAGE_ADJ:

	        OsdFuncClearOsd(5, FONT1_COL, WIDTH(9), HEIGHT(1));
        OsdFuncClearOsd(8, FONT1_COL, WIDTH(9), HEIGHT(1));
        OsdFuncClearOsd(11, FONT1_COL, WIDTH(9), HEIGHT(1));
        OsdFuncClearOsd(14, FONT1_COL, WIDTH(9), HEIGHT(1));
        OsdFuncClearOsd(17, FONT1_COL, WIDTH(9), HEIGHT(1));



			MaxItem = 6;
        OsdPropPutString(ROW(6-1), COL(FONT1_COL), _PFONT_PAGE_3, _STRING_PICTURE, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(9-1), COL(FONT1_COL), _PFONT_PAGE_3, _STRING_COLOR, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(12-1), COL(FONT1_COL), _PFONT_PAGE_3, _OSD_SETTING, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(15-1), COL(FONT1_COL), _PFONT_PAGE_3, _SET_UP, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());
        OsdPropPutString(ROW(18-1), COL(FONT1_COL), _PFONT_PAGE_3, _STRING_OTHER, COLOR(_CP_WHITE, _CP_BG), GET_OSD_LANGUAGE());



	        OsdFuncClearOsd(FONT1_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT2_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT3_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT4_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));
        OsdFuncClearOsd(FONT5_ROW, FONT2_COL, WIDTH(14), HEIGHT(1));


				OsdPropPutString(ROW(FONT1_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_LANGUAGE, COLOR(_CP_RED , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT2_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OSD_HPOS, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT3_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OSD_VPOS, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT4_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_TRANSPARENCY, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());
				OsdPropPutString(ROW(FONT5_ROW), COL(FONT2_COL), _PFONT_PAGE_0, _STRING_OSD_TIMEOUT, COLOR(_CP_WHITE , _CP_BLACK_1), GET_OSD_LANGUAGE());


break;	




			default:
		   break;	
}


           if(usValue == 0)
           {
				Clean1 = MaxItem;
				Clean2 = 1;
			}
			else if(usValue == MaxItem)
			{
				Clean1 = MaxItem -1;
				Clean2 = 0;
			}
			else
			{
				Clean1 = usValue -1;
				Clean2 = usValue +1;
			}

if(ucOsdState == _MENU_OTHERS_FREESYNC_ADJ)
{
		OsdFuncClearOsd(FONT1_ROW+Clean1*2, FONT2_COL+12, WIDTH(1), HEIGHT(1));  
		OsdFuncClearOsd(FONT1_ROW+Clean2*2, FONT2_COL+12, WIDTH(1), HEIGHT(1));  
		OsdFontPut1BitTable(ROW(FONT1_ROW+usValue*2), COL(FONT2_COL+12), tSTRING_SELECT, COLOR(_CP_RED , _CP_BLACK_1));

		OsdFuncChangeColor1Bit(ROW(FONT1_ROW+usValue*2), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED , _CP_BLACK_1),0);
		OsdFuncChangeColor1Bit(ROW(FONT1_ROW+Clean1*2), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);
		OsdFuncChangeColor1Bit(ROW(FONT1_ROW+Clean2*2), COL(FONT2_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);


}
else
{
		OsdFuncClearOsd(FONT1_ROW+Clean1*2, SELECT_ICON, WIDTH(1), HEIGHT(1));  
		OsdFuncClearOsd(FONT1_ROW+Clean2*2, SELECT_ICON, WIDTH(1), HEIGHT(1));  
		OsdFontPut1BitTable(ROW(FONT1_ROW+usValue*2), COL(SELECT_ICON), tSTRING_SELECT, COLOR(_CP_RED , _CP_BLACK_1));

		OsdFuncChangeColor1Bit(ROW(FONT1_ROW+usValue*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_RED , _CP_BLACK_1),0);
		OsdFuncChangeColor1Bit(ROW(FONT1_ROW+Clean1*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);
		OsdFuncChangeColor1Bit(ROW(FONT1_ROW+Clean2*2), COL(FONT3_COL), WIDTH(14), HEIGHT(1), COLOR(_CP_WHITE , _CP_BLACK_1),0);
}


	
}




#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
