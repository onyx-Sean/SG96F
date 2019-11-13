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
// ID Code      : RTD2014OsdFunc.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFUNC__

#include "UserCommonInclude.h"

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
WORD g_usFontSelectStart;
WORD g_usFontTableStart;
BYTE g_ucOsdWidth;
BYTE g_ucOsdHeight;
BYTE g_ucOsdWidthB;
BYTE g_ucOsdHeightB;
BYTE g_ucFontPointer0 = _OSD_PAGE_0_START;
BYTE g_ucFontPointer1 = _OSD_PAGE_1_START;
BYTE g_ucFontPointer2 = _OSD_PAGE_2_START;
BYTE g_ucFontPointer3 = _OSD_PAGE_3_START;

BYTE g_ucSubMask[5] = {0};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
void OsdFuncSetPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY);
void OsdFuncTransparency(BYTE ucTrans);
void OsdFuncBlending(BYTE ucType);

void OsdFontPut1ChooseIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucForeground, BYTE ucBackground);

BYTE OsdFuncGetOsdItemFlag(void);

void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex);
void OsdFuncDisableOsd(void);
void OsdFuncEnableOsd(void);
void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom);
void OsdFuncSet2BitIconOffset(BYTE ucOffset);
void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight);
#if(_ULTRA_HDR_SUPPORT == _ON)

void OsdFuncColorFormatAdjust(void);
void OsdFuncColorPcmAdjust(void);
#endif
void OsdFuncSetOsdItemFlag(void);

#if(_FREEZE_SUPPORT == _ON)
bit OsdFuncCheckFreezeDisable(void);
#endif

void OsdFontPut1FuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucLength,BYTE ucForeground, BYTE ucBackground);
void OsdThreeColorChooseTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType);
void OsdFontPut1FuncAimTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType);
void OsdFontPut1NumberTableForm(BYTE ucRow, BYTE ucCol, BYTE ucNumberIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucnumber);
void OsdFontPut1FuncTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucType);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncApplyMap(BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    BYTE ucI = 0;
    BYTE ucTmp = 17; // Row Height = 18

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucI = ucWidth;
        ucWidth = ucHeight;
        ucHeight = ucI;
        ucTmp = 11;  // Row Height = 12
    }
#endif

    // Row Command
    for(ucI = 0; ucI < ucHeight; ucI++)
    {
        ScalerOsdCommandAllByte(ucI, 0x80, ucTmp, ucWidth);
    }


    // Row Command end
    ScalerOsdCommandByte(ucHeight, _OSD_BYTE0, 0x00);

    // Frame Control (set font start address)
    g_usFontSelectStart = ucHeight + 1;
    g_usFontTableStart = g_usFontSelectStart + (WORD)(ucWidth * ucHeight);
    ScalerOsdSramBaseAddressSet(_OSD_A, 0, g_usFontSelectStart, g_usFontTableStart);

    // Character Command initial
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucTmp = 0x4E;  // 18 Pixel
    }
    else
#endif
    {
        ucTmp = 0x4C;  // 12 Pixel
    }

    ScalerOsdCharCommandAllByteSeries(g_usFontSelectStart, ucTmp, 0, ucColor, (WORD)ucWidth * ucHeight);

    g_ucOsdWidth = ucWidth; // for calculation (unit: word count)
    g_ucOsdHeight = ucHeight;

    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_DVS);
    ScalerOsdDoubleFunction(GET_OSD_DOUBLE_SIZE(), GET_OSD_DOUBLE_SIZE());
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncSetPosition(EnumOsdPositionType enumOsdPositionType, WORD usX, WORD usY)
{

    ScalerOsdPosition(enumOsdPositionType, usX, usY);

    ScalerTimerWaitForEvent(_EVENT_DVS);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncTransparency(BYTE ucTrans)
{
    ScalerOsdSetTransparency(ucTrans);
}

//--------------------------------------------------
// Description  :
// Input Value  : Blending type1:Only windows blending.
//                Blending type2:All blending.
//                Blending type3:Windows & Character background blending.
// Output Value : None
//--------------------------------------------------
void OsdFuncBlending(BYTE ucType)
{
    ScalerOsdVerticalStartSelect(_OSD_VSYNC_SELECT_DVS);
    ScalerOsdWindow7SpecialFunction(_OSD_WINDOW_7_FUNCTION_MASK_REGION_TRANSPARENT_ALL);
    ScalerOsdSetTransparencyType(ucType);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncCloseWindow(EnumOsdWindowsType enumWinIndex)
{
    ScalerOsdWindowDisable(enumWinIndex);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncDisableOsd(void)
{
   if( g_MiaoZhun_OnOff == _ON)
    {
       g_MiaoZhun_OnOff = _OFF;
    }

   if( g_usTime_OSD_OnOff == _ON)
    {
       g_usTime_OSD_OnOff = _OFF;
    }
                   OsdFuncCloseWindow(_OSD_WINDOW_ALL);


    ScalerOsdDisableOsd();
#if(_INTERNAL_AUDIO_TEST_SUPPORT == _ON)
    if(ScalerAudioGetInternalAudioGenEnable(SysSourceGetInputPort()) == _ENABLE)
        SysAudioInternalGenTestProc(_OFF);
#endif
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncEnableOsd(void)
{
    ScalerOsdEnableOsd();
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
/* //1bitcolor
void OsdFuncChangeIconColor1Bit(BYTE ucRow, BYTE ucItem, BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    // BYTE ucRow;
    BYTE ucCol = 3;

    if((ucRow == 18) || (ucRow == 8))
    {
        OsdFuncChangeColor1Bit(ucRow, ucCol, 8, ucHeight, (ucColor << 4) & 0xF0, _FONTFROM_256_512);
    }
    else
    {
        ucCol = COL(4) + ((ucItem % 4) * 10) - 2;
        OsdFuncChangeColor1Bit(ucRow, ucCol, ucWidth, ucHeight, (ucColor << 4) & 0xF0, _FONTFROM_0_255);
    }
}
*/
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncChangeColor1Bit(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucFontSelectFrom)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
    BYTE ucHeightCount = 0;

ucFontSelectFrom = ucFontSelectFrom;
        for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
        {
         //   ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, (0x4C | ucFontSelectFrom), ucWidth);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE2, ucColor, ucWidth);
            usOsdAddr += g_ucOsdWidth;
        }
   
}



void OsdFontPut1ChooseIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucForeground, BYTE ucBackground)
	{
		WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
		BYTE xdata ucByte0 = 0x4C;
		BYTE xdata ucByte2 = 0;
		BYTE ucLength2 = 16, ucHeight2 = 2;
		BYTE ucLength1 = 2, ucHeight1 = 1;
		BYTE ucOsdRotateStatus = _OSD_ROTATE_DEGREE_0;
		WORD windowcountmax=0;
//ScalerOsdHardwareVLC(tFONT1_MAIN_ICON_TABLE_1[10], VLC_TABLE_SIZE(tFONT1_MAIN_ICON_TABLE_1[10]), GET_CURRENT_BANK_NUMBER(), ucIcon , g_usFontTableStart, ucOsdRotateStatus);




#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
		{
			usOsdAddr = (WORD)((g_ucOsdWidth-ucRow-1) + g_ucOsdWidth * ucCol) ; 	   
			ucByte0 = 0x4E; 
		}	 
		else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
			ucByte0 = 0x4E; 
		}
#endif

		
		ucForeground &= 0x0F;
		
		ucByte2 = ((ucForeground  << 4) | ucBackground);

	
	//20140207 Abel Modify	  
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) 
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
		{
					 
				for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
				{				   
						usOsdAddr = (WORD)(g_ucOsdWidth- ucRow - ucHeight2 - 1)+ g_ucOsdWidth * (ucCol+ucLength2);
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
					ucIcon++;		 
				}				 
				 
	
		}	 
		else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{	 
				 
				for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
				{
					usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol+ucLength2)) * g_ucOsdWidth + (ucRow+ucHeight2); 			   
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
					ucIcon++;		 
				}				 
				 
		}
		else  
#endif        
		{	 
				 
				for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
				{
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart + ucLength2, ucByte0, ucIcon, ucByte2);	  
					ucIcon++;		 
				}	 
			
			 
		}
	}
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut1NumberTableForm(BYTE ucRow, BYTE ucCol, BYTE ucNumberIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucnumber)
	{
		WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
		BYTE xdata ucByte0 = 0x4C;
		BYTE xdata ucByte2 = 0;
		BYTE ucLength1 = 0, ucHeight1 = 0;
		BYTE ucLength2 = 0, ucHeight2 = 0;
		BYTE ucIcon;
		ucIcon =ucNumberIcon+ ucnumber*6;
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
		{
			usOsdAddr = (WORD)((g_ucOsdWidth-ucRow-1) + g_ucOsdWidth * ucCol) ; 	   
			ucByte0 = 0x4E; 
		}	 
		else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
			ucByte0 = 0x4E; 
		}
#endif
	
		ucForeground &= 0x0F;
		
		ucByte2 = ((ucForeground  << 4) | ucBackground);
	
	//20140207 Abel Modify	  
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) 
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
		{
			for(ucHeight1 = 0; ucHeight1 < ucHeight; ucHeight1++)
			{					 
				for(ucLength1=0; ucLength1 < ucLength; ucLength1++)
				{				   
						usOsdAddr = (WORD)(g_ucOsdWidth- ucRow - ucHeight1 - 1)+ g_ucOsdWidth * (ucCol+ucLength1);
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
					ucIcon++;		 
				}				 
			}	 
	
		}	 
		else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{	 
			for(ucHeight1 = 0; ucHeight1 < ucHeight; ucHeight1++)
			{					 
				for(ucLength1=0; ucLength1 < ucLength; ucLength1++)
				{
					usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol+ucLength1)) * g_ucOsdWidth + (ucRow+ucHeight1); 			   
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
					ucIcon++;		 
				}				 
			}	 
		}
		else  
#endif        
		{	 
			for(ucHeight1 = 0; ucHeight1 < ucHeight; ucHeight1++)
			{					 
				for(ucLength1=0; ucLength1 < ucLength; ucLength1++)
				{
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart + ucLength1, ucByte0, ucIcon, ucByte2);	  
					ucIcon++;		 
				}	 
				usOsdAddr += g_ucOsdWidth;
			}	 
		}
	}


void OsdFontPut1FuncAimTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType)
{
				WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
				BYTE xdata ucByte0 = 0x4C;
				BYTE xdata ucByte2 = 0,ucaimByte2 = 0;
				BYTE ucLength2 = 16, ucHeight2 = 2;
				BYTE ucLength1 = 0, ucHeight1 = 0;
				BYTE ucOsdRotateStatus = _OSD_ROTATE_DEGREE_0;
				WORD windowcountmax=0;
				WORD linenumber=0;
				WORD linenumberaddr=0;
		//ScalerOsdHardwareVLC(tFONT1_MAIN_ICON_TABLE_1[10], VLC_TABLE_SIZE(tFONT1_MAIN_ICON_TABLE_1[10]), GET_CURRENT_BANK_NUMBER(), ucIcon , g_usFontTableStart, ucOsdRotateStatus);
		
		
		
		
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
				if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
				{
					usOsdAddr = (WORD)((g_ucOsdWidth-ucRow-1) + g_ucOsdWidth * ucCol) ; 	   
					ucByte0 = 0x4E; 
				}	 
				else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
				{
					usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
					ucByte0 = 0x4E; 
				}
#endif
		
				
				ucForeground &= 0x0F;
				
				ucByte2 = ((ucForeground  << 4) | ucBackground);
				
				ucbox &= 0x0F;
				
				ucaimByte2 = ((ucbox  << 4) | ucbox);

			
			//20140207 Abel Modify	  
	/*#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) 
				if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
				{
							 
						for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
						{				   
								usOsdAddr = (WORD)(g_ucOsdWidth- ucRow - ucHeight2 - 1)+ g_ucOsdWidth * (ucCol+ucLength2);
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
							ucIcon++;		 
						}				 
						 
			
				}	 
				else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
				{	 
						 
						for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
						{
							usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol+ucLength2)) * g_ucOsdWidth + (ucRow+ucHeight2);			   
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
							ucIcon++;		 
						}				 
						 
				}
				else  
#endif   */  
	
	if(ucType==0)
	{	 
		for(ucHeight1=0; ucHeight1 < ucHeight+2;ucHeight1++)
		{


			if(ucHeight1==0)
			{
				for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
				{
					if(ucLength1==0)
					{
						ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon, ucByte2); 
					}
					
					else if(ucLength1==ucLength+1)
					{
						ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
						ucRow++;
						usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

					}


					
					else
					{
					//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
						ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-1, ucByte2);   
				//	ucRow++;	
					}
				}
			}
			

			else if(ucHeight1==ucHeight+1)
			{
					for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
					{
						if(ucLength1==0)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+4, ucByte2); 
						}
						else if(ucLength1==ucLength+1)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+3, ucByte2);
							//ucRow++;
							//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

						}
						else
						{
						//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+6, ucByte2);   
					//	ucRow++;	
						}
					}


			}

			else
			{
					for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
					{
						if(ucLength1==0)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-2, ucByte2); 
						}
						if(ucLength1==ucLength+1)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-6, ucByte2);
							ucRow++;
							usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

						}

						if(ucLength1>0 && ucLength1<ucLength+1)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-14, ucaimByte2);
						}
							
						
						
					}



			}


		}
		
		 
	}		

}


void OsdThreeColorChooseTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucbox,BYTE ucType)
	{
					WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
					BYTE xdata ucByte0 = 0x4C;
					BYTE xdata ucByte2 = 0,ucaimByte2 = 0;
					BYTE ucLength2 = 16, ucHeight2 = 2;
					BYTE ucLength1 = 0, ucHeight1 = 0;
					BYTE ucOsdRotateStatus = _OSD_ROTATE_DEGREE_0;
					WORD windowcountmax=0;
					WORD linenumber=0;
					WORD linenumberaddr=0;
			//ScalerOsdHardwareVLC(tFONT1_MAIN_ICON_TABLE_1[10], VLC_TABLE_SIZE(tFONT1_MAIN_ICON_TABLE_1[10]), GET_CURRENT_BANK_NUMBER(), ucIcon , g_usFontTableStart, ucOsdRotateStatus);
			
			
			
			
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
					if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
					{
						usOsdAddr = (WORD)((g_ucOsdWidth-ucRow-1) + g_ucOsdWidth * ucCol) ; 	   
						ucByte0 = 0x4E; 
					}	 
					else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
					{
						usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
						ucByte0 = 0x4E; 
					}
#endif
			
					
					ucForeground &= 0x0F;
					
					ucByte2 = ((ucForeground  << 4) | ucBackground);
					
					ucbox &= 0x0F;
					
					ucaimByte2 = ((ucbox  << 4) | ucbox);
	
				
				//20140207 Abel Modify	  
		/*#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) 
					if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
					{
								 
							for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
							{				   
									usOsdAddr = (WORD)(g_ucOsdWidth- ucRow - ucHeight2 - 1)+ g_ucOsdWidth * (ucCol+ucLength2);
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
								ucIcon++;		 
							}				 
							 
				
					}	 
					else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
					{	 
							 
							for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
							{
								usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol+ucLength2)) * g_ucOsdWidth + (ucRow+ucHeight2);			   
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
								ucIcon++;		 
							}				 
							 
					}
					else  
#endif   */  
		
		if(ucType==0)
		{	 
			for(ucHeight1=0; ucHeight1 < ucHeight+2;ucHeight1++)
			{
	
	
				if(ucHeight1==0)
				{
					for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
					{
						if(ucLength1==0)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon, ucByte2); 
						}
						
						else if(ucLength1==ucLength+1)
						{
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
							ucRow++;
							usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
	
						}
	
	
						
						else
						{
						//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
							ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-1, ucByte2);   
					//	ucRow++;	
						}
					}
				}
				
	
				else if(ucHeight1==ucHeight+1)
				{
						for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
						{
							if(ucLength1==0)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+4, ucByte2); 
							}
							else if(ucLength1==ucLength+1)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+3, ucByte2);
								//ucRow++;
								//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
	
							}
							else
							{
							//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+6, ucByte2);   
						//	ucRow++;	
							}
						}
	
	
				}
	
				else
				{
						for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
						{
							if(ucLength1==0)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-2, ucByte2); 
							}
							if(ucLength1==ucLength+1)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-6, ucByte2);
								ucRow++;
								usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
	
							}
	
							if(ucLength1>0 && ucLength1<ucLength+1)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-14, ucaimByte2);
							}
								
							
							
						}
	
	
	
				}
	
	
			}
			
			 
		}		
	
	}



void OsdFontPut1FuncHLine(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucLength,BYTE ucForeground, BYTE ucBackground)
	{
		WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
		BYTE xdata ucByte0 = 0x4C;
		BYTE xdata ucByte2 = 0;
		BYTE ucLength2 = 16, ucHeight2 = 2;
		BYTE ucLength1 = ucLength, ucHeight1 = 0;
		BYTE ucOsdRotateStatus = _OSD_ROTATE_DEGREE_0;
		WORD windowcountmax=0;
//ScalerOsdHardwareVLC(tFONT1_MAIN_ICON_TABLE_1[10], VLC_TABLE_SIZE(tFONT1_MAIN_ICON_TABLE_1[10]), GET_CURRENT_BANK_NUMBER(), ucIcon , g_usFontTableStart, ucOsdRotateStatus);



#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
		{
			usOsdAddr = (WORD)((g_ucOsdWidth-ucRow-1) + g_ucOsdWidth * ucCol) ; 	   
			ucByte0 = 0x4E; 
		}	 
		else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{
			usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
			ucByte0 = 0x4E; 
		}
#endif

		
		ucForeground &= 0x0F;
		
		ucByte2 = ((ucForeground  << 4) | ucBackground);

	
	//20140207 Abel Modify	  
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) 
		if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
		{
					 
				for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
				{				   
						usOsdAddr = (WORD)(g_ucOsdWidth- ucRow - ucHeight2 - 1)+ g_ucOsdWidth * (ucCol+ucLength2);
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
					ucIcon++;		 
				}				 
				 
	
		}	 
		else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
		{	 
				 
				for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
				{
					usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol+ucLength2)) * g_ucOsdWidth + (ucRow+ucHeight2); 			   
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
					ucIcon++;		 
				}				 
				 
		}
		else  
#endif        
		{	 
				 
				for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
				{
					ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart + ucLength2, ucByte0, ucIcon, ucByte2);	  
							 
				}	 
			
			 
		}
	}


void OsdFuncSet2BitIconOffset(BYTE ucOffset)
{
    ScalerOsd2BitFontOffset(ucOffset);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncClearOsd(BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol + g_usFontSelectStart;
    BYTE ucHeightCount = 0;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    BYTE ucWidthCount = 0;

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdWidth - ucRow - ucHeight) + g_ucOsdWidth * (ucCol + ucWidthCount) + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x4E, ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, 0x00, ucHeight);
        }
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        for(ucWidthCount = 0; ucWidthCount < ucWidth; ucWidthCount++)
        {
            usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol - ucWidthCount) * g_ucOsdWidth + ucRow + g_usFontSelectStart;
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x4E, ucHeight);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, 0x00, ucHeight);
        }
    }
    else
#endif
    {
        for(ucHeightCount = 0; ucHeightCount < ucHeight; ucHeightCount++)
        {
            // 1 Bit Font
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE0, 0x4C, ucWidth);
            ScalerOsdCharCommandByteSeries(usOsdAddr, _OSD_BYTE1, 0x00, ucWidth);
            usOsdAddr += g_ucOsdWidth;
        }
    }
}

#if(_ULTRA_HDR_SUPPORT == _ON)


//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------

void OsdFuncColorFormatAdjust(void)
{
    switch(SysSourceGetInputPort())
    {
        case _A0_INPUT_PORT:

            if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
            {
                SET_VGA_COLOR_FORMAT_STATUS(_COLOR_SPACE_RGB);
            }
            else
            {
                SET_VGA_COLOR_FORMAT_STATUS(_COLOR_SPACE_YPBPR);
            }

            break;

#if(_D0_INPUT_PORT_TYPE == _D0_DVI_PORT)
        case _D0_INPUT_PORT:
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DVI_PORT)
        case _D1_INPUT_PORT:
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DVI_PORT)
        case _D2_INPUT_PORT:
#endif

#if(_D3_INPUT_PORT_TYPE == _D3_DVI_PORT)
        case _D3_INPUT_PORT:
#endif

            if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
            {
                SET_DVI_COLOR_FORMAT_STATUS(_COLOR_SPACE_RGB);
            }
            else
            {
                SET_DVI_COLOR_FORMAT_STATUS(_COLOR_SPACE_YPBPR);
            }

            break;

        default:
            break;
    }

#if(_OVERSCAN_SUPPORT == _ON)
    if(GET_OSD_OVERSCAN_STATUS() == _ON)
    {
        SysModeSetResetTarget(_MODE_ACTION_RESET_TO_DISPLAY_SETTING);
    }
    else
#endif
    {
        if(GET_OSD_COLOR_FORMAT() == _COLOR_SPACE_RGB)
        {
            SysModeColorSpaceConvert(_COLOR_SPACE_RGB, _DB_APPLY_POLLING);
        }
        else
        {
            SysModeColorSpaceConvert(_COLOR_SPACE_YPBPR, _DB_APPLY_POLLING);
        }
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFuncColorPcmAdjust(void)
{
#if(_PCM_FUNCTION == _ON)
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

    ScalerColorOutputGammaEnable(_FUNCTION_OFF);
    ScalerColorSRGBEnable(_FUNCTION_OFF);
    ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);

#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
    ScalerColorRGB3DGammaEnable(_FUNCTION_OFF);

#endif
    if(GET_OSD_PCM_STATUS() != _PCM_OSD_NATIVE)
    {
#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
        if(GET_OSD_PCM_STATUS() == _PCM_OSD_SOFT_PROFT)
        {
            UserAdjust3DGamma(GET_OSD_PCM_SOFT_PROFT_MODE());
        }
#endif
        UserAdjustPCM(GET_OSD_PCM_STATUS());
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_BRIGHTNESS_SUPPORT == _ON)
        ScalerColorBrightnessEnable(_FUNCTION_OFF);
#endif

#if(_CONTRAST_SUPPORT == _ON)
        ScalerColorContrastEnable(_FUNCTION_OFF);
#endif
        ScalerColorOutputGammaEnable(_FUNCTION_ON);
        ScalerColorSRGBEnable(_FUNCTION_ON);
        ScalerColorPCMInputGammaEnable(_FUNCTION_ON);

#if((_OCC_SUPPORT == _ON) && (_RGB_3D_GAMMA == _ON))
        if(GET_OSD_PCM_STATUS() == _PCM_OSD_SOFT_PROFT)
        {
            ScalerColorRGB3DGammaEnable(_FUNCTION_ON);
        }
#endif
    }
    else
    {
#if(_GAMMA_FUNCTION == _ON)
        UserAdjustGamma(GET_OSD_GAMMA());
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        UserAdjustGlobalHueSat((SWORD)GET_OSD_HUE(), GET_OSD_SATURATION());
#endif

#if((_GAMMA_FUNCTION == _ON) || (_GLOBAL_HUE_SATURATION == _ON))
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

#if(_GAMMA_FUNCTION == _ON)
        if(GET_OSD_GAMMA() != _GAMMA_OFF)
        {
            ScalerColorOutputGammaEnable(_FUNCTION_ON);

#if(_RGB_GAMMA_FUNCTION == _ON)
            ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif
        }
#endif

#if(_GLOBAL_HUE_SATURATION == _ON)
        ScalerColorSRGBEnable(_FUNCTION_ON);
#endif

#if(_CONTRAST_SUPPORT == _ON)
        UserAdjustContrast(GET_OSD_CONTRAST());
#endif

#if(_BRIGHTNESS_SUPPORT == _ON)
        UserAdjustBrightness(GET_OSD_BRIGHTNESS());
#endif
#endif  // End of #if((_GAMMA_FUNCTION == _ON) || (_GLOBAL_HUE_SATURATION == _ON))

    }
#endif  // End of #if(_PCM_FUNCTION == _ON)
}
#endif
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut1FuncTableForm(BYTE ucRow, BYTE ucCol, BYTE ucIcon,BYTE ucLength ,BYTE ucHeight,BYTE ucForeground, BYTE ucBackground,BYTE ucType)
	//
	{
			WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
			BYTE xdata ucByte0 = 0x4C;
			BYTE xdata ucByte2 = 0;
			BYTE ucHeight2 = 2;
			BYTE ucLength1 = 0, ucHeight1 = 0;
			WORD windowcountmax=0;
			WORD linenumber=0;
			WORD linenumberaddr=0;
	//ScalerOsdHardwareVLC(tFONT1_MAIN_ICON_TABLE_1[10], VLC_TABLE_SIZE(tFONT1_MAIN_ICON_TABLE_1[10]), GET_CURRENT_BANK_NUMBER(), ucIcon , g_usFontTableStart, ucOsdRotateStatus);
	
	
	
	
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
			if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
			{
				usOsdAddr = (WORD)((g_ucOsdWidth-ucRow-1) + g_ucOsdWidth * ucCol) ; 	   
				ucByte0 = 0x4E; 
			}	 
			else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
			{
				usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
				ucByte0 = 0x4E; 
			}
#endif
	
			
			ucForeground &= 0x0F;
			
			ucByte2 = ((ucForeground  << 4) | ucBackground);
	
		
		//20140207 Abel Modify	  
/*#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE) 
			if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
			{
						 
					for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
					{				   
							usOsdAddr = (WORD)(g_ucOsdWidth- ucRow - ucHeight2 - 1)+ g_ucOsdWidth * (ucCol+ucLength2);
						ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
						ucIcon++;		 
					}				 
					 
		
			}	 
			else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
			{	 
					 
					for(ucLength2=0; ucLength2 < ucLength1; ucLength2++)
					{
						usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol+ucLength2)) * g_ucOsdWidth + (ucRow+ucHeight2);			   
						ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);    
						ucIcon++;		 
					}				 
					 
			}
			else  
#endif   */  

		if(ucType==3)
			{	 
				for(ucHeight1=0; ucHeight1 < ucHeight+2;ucHeight1++)
				{


					if(ucHeight1==0)
					{
						for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
						{
							if(ucLength1==0)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon, ucByte2); 
							}
							
							else if(ucLength1==ucLength+1)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
								ucRow++;
								usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

							}


							
							else
							{
							//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-1, ucByte2);   
						//	ucRow++;	
							}
						}
					}
					

					else if(ucHeight1==ucHeight+1)
					{
							for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
							{
								if(ucLength1==0)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+4, ucByte2); 
								}
								else if(ucLength1==ucLength+1)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+3, ucByte2);
									//ucRow++;
									//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

								}
								else
								{
								//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+6, ucByte2);   
							//	ucRow++;	
								}
							}


					}

					else
					{
							for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
							{
								if(ucLength1==0)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-2, ucByte2); 
								}
								if(ucLength1==ucLength+1)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-6, ucByte2);
									ucRow++;
									usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

								}

								if(ucLength1>0 && ucLength1<ucLength+1)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-14, ucByte2);
								}
									
								
								
							}



					}


				}
				
				 
			}		



		if(ucType==_QUADRANGLE_WINDOW_0)
			{	 
				for(ucHeight1=0; ucHeight1 < ucHeight+2;ucHeight1++)
				{

					if(ucHeight1==0)
					{
						for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
						{
							if(ucLength1==0)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon, ucByte2); 
							}
							else if(ucLength1==ucLength+1)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+2, ucByte2);
								ucRow++;
								usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

							}
							else
							{
							//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);   
						//	ucRow++;	
							}
						}
					}

					else if(ucHeight1==ucHeight+1)
					{
					
							for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
							{
								if(ucLength1==0)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+4, ucByte2); 
								}
								else if(ucLength1==ucLength+1)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+3, ucByte2);
									//ucRow++;
									//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

								}
								else
								{
								//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);   
							//	ucRow++;	
								}
							}
                                         

					}

					else
					{
							for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
							{
								if(ucLength1==0)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1+1 , ucByte0, ucIcon+1, ucByte2); 
								}
								if(ucLength1==ucLength+1 )
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1-1 , ucByte0, ucIcon+1, ucByte2);
									ucRow++;
									usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

								}
								else
								{
								//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
									//ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);   
							//	ucRow++;	
								}

							}

					}


				}
				
				 
			}


		if(ucType==2)
			{	 
							for(ucHeight1=0; ucHeight1 < ucHeight+2;ucHeight1++)
							{

								

								
							
								
								if(ucHeight1==0)
								{
									for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
									{
										if(ucLength1==0)
										{
											ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon, ucByte2); 
										}
										else if(ucLength1==ucLength+1)
										{
											ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
											ucRow++;
											usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
			
										}
										else
										{
										//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
											ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-1, ucByte2);   
									//	ucRow++;	
										}
									}
								}
			
								else if(ucHeight1==ucHeight+1)
								{
										for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
										{
											if(ucLength1==0)
											{
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+4, ucByte2); 
											}
											else if(ucLength1==ucLength+1)
											{
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+3, ucByte2);
												//ucRow++;
												//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
			
											}
											else
											{
											//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+6, ucByte2);   
										//	ucRow++;	
											}
										}
			
			
								}
								else if(ucHeight1%3==0 && ucHeight1>0 && ucHeight1< 22)
								{
								
																
										for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
										{
											if(ucLength1==0)
											{
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+5, ucByte2); 
											}
											if(ucLength1==ucLength+1)
											{
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+2, ucByte2);
												ucRow++;
												usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
											
											}
											else
											{
											//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1+1 , ucByte0, ucIcon+6, ucByte2);   
												//	ucRow++;	
											}
											
										}
								
								}





			
								else
								{
										for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
										{
											if(ucLength1==0)
											{
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-2, ucByte2); 
											}
											if(ucLength1==ucLength+1)
											{
												ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-6, ucByte2);
												ucRow++;
												usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
			
											}
			
										}
			
								}
								
			
			
			}
							
							 
		}


		
		if(ucType==_ARC_WINDOW_0)
			{	 
				for(ucHeight1=0; ucHeight1 < ucHeight+2;ucHeight1++)
				{

					if(ucHeight1==0)
					{
						for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
						{
							if(ucLength1==0)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon, ucByte2); 
							}
							else if(ucLength1==ucLength+1)
							{
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+1, ucByte2);
								ucRow++;
								usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

							}
							else
							{
							//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
								ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-1, ucByte2);   
						//	ucRow++;	
							}
						}
					}

					else if(ucHeight1==ucHeight+1)
					{
							for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
							{
								if(ucLength1==0)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+4, ucByte2); 
								}
								else if(ucLength1==ucLength+1)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+3, ucByte2);
									//ucRow++;
									//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

								}
								else
								{
								//usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon+6, ucByte2);   
							//	ucRow++;	
								}
							}


					}

					else
					{
							for(ucLength1=0; ucLength1 < ucLength+2;ucLength1++)
							{
								if(ucLength1==0)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-2, ucByte2); 
								}
								if(ucLength1==ucLength+1)
								{
									ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart+ucLength1 , ucByte0, ucIcon-6, ucByte2);
									ucRow++;
									usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;

								}

							}

					}


				}
				
				 
			}		
		}

void OsdFuncSetOsdItemFlag(void)
{
    // input port
 //   if(SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP)
 //   {
  //      SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_AUTO);
   // }
 //   else
    {
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_A0);
                break;

            case _D0_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D0);
                break;

            case _D1_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D1);
                break;

            case _D2_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D2);
                break;

            case _D3_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D3);
                break;

            case _D4_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D4);
                break;

            case _D5_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D5);
                break;

            case _D6_INPUT_PORT:
                SET_OSD_INPUT_PORT_OSD_ITEM(_OSD_INPUT_D6);
                break;

            default:
                break;
        }
    }
}

BYTE OsdFuncGetOsdItemFlag(void)
{
    // input port
  //  if(SysSourceGetScanType() == _SOURCE_SWITCH_AUTO_IN_GROUP)
  //  {
 //       return (_OSD_INPUT_AUTO);
 //   }
//    else
    {
        switch(SysSourceGetInputPort())
        {
            case _A0_INPUT_PORT:
                return(_OSD_INPUT_A0);
                break;

            case _D0_INPUT_PORT:
                return(_OSD_INPUT_D0);
                break;

            case _D1_INPUT_PORT:
                return(_OSD_INPUT_D1);
                break;

            case _D2_INPUT_PORT:
                return(_OSD_INPUT_D2);
                break;

            case _D3_INPUT_PORT:
                return(_OSD_INPUT_D3);
                break;

            case _D4_INPUT_PORT:
                return(_OSD_INPUT_D4);
                break;

            case _D5_INPUT_PORT:
                return(_OSD_INPUT_D5);
                break;

            case _D6_INPUT_PORT:
                return(_OSD_INPUT_D6);
                break;

            default:
                break;
        }
    }
}


#if(_FREEZE_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit OsdFuncCheckFreezeDisable(void)
{
    if(((((GET_OSD_STATE() >= _MENU_DISPLAY_AUTO) &&
          (GET_OSD_STATE() <= _MENU_DISPLAY_PHASE)) ||
         (GET_OSD_STATE() == _MENU_COLOR_FORMAT) ||
         (GET_OSD_STATE() == _MENU_ADVANCE_ASPECT) ||
         (GET_OSD_STATE() == _MENU_ADVANCE_OVER_SCAN) ||
         (GET_OSD_STATE() == _MENU_OTHER_RESET) ||
         (GET_OSD_STATE() == _MENU_DISPLAY_LATENCY)) &&
        (GET_KEYMESSAGE() == _MENU_KEY_MESSAGE)) ||
       ((GET_OSD_STATE() == _MENU_ADVANCE_ULTRA_VIVID_ADJUST) && (GET_OSD_ULTRA_VIVID_STATUS() == _ULTRA_VIVID_OFF) && (GET_KEYMESSAGE() == _RIGHT_KEY_MESSAGE)) ||
       ((GET_OSD_STATE() == _MENU_ADVANCE_ULTRA_VIVID_ADJUST) && (GET_OSD_ULTRA_VIVID_STATUS() == _ULTRA_VIVID_L) && (GET_KEYMESSAGE() == _LEFT_KEY_MESSAGE)))
    {
        OsdDispOsdMessage(_OSD_DISP_DISABLE_FREEZE_MSG);
        ScalerTimerActiveTimerEvent(SEC(1), _USER_TIMER_EVENT_OSD_DISABLE_FREEZE_MSG);
        SET_OSD_STATE(GET_OSD_STATE_PREVIOUS());
        SET_OSD_FREEZE_STATUS(_OFF);
        UserCommonAdjustDisplayFreeze(_OFF);
#if(_URGENT_EVENT_CHECK_MODE == _OFF)
        SET_FREEZE_DISABLE_MSG_STATE(_ON);
#endif
        return _TRUE;
    }
    return _FALSE;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------

#endif

#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)

