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
// ID Code      : RTD2014OsdWindow.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDWINDOW__

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

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor);
void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor);
void OsdWindowDrawingByFontHighlight(BYTE ucWindow, BYTE ucRow1, BYTE ucCol1, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor);

//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowDrawing(BYTE ucWindow, WORD usXStart, WORD usYStart, WORD usXEnd, WORD usYEnd, BYTE ucColor)
{
#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    WORD xdata usTemp = 0;
    WORD xdata usTemp1 = 0;
    WORD xdata usTemp2 = 0;
    usTemp  = usXEnd - usXStart;
    usTemp1 = usYEnd - usYStart;
    usTemp2 = usXStart;

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usXEnd = (g_ucOsdWidth * 18 - usYStart);
        usXStart = usXEnd - usTemp1;
        usYStart = usTemp2;
        usYEnd = usYStart + usTemp;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usXStart = usYStart;
        usYStart = (g_ucOsdHeight * 12) - usXEnd;
        usXEnd = usXStart + usTemp1;
        usYEnd = usYStart + usTemp;
    }
    else
    {
    }

#elif(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_HARDWARE)
    WORD xdata usTemp = 0;
    WORD xdata usTemp1 = 0;
    WORD xdata usTemp2 = 0;
    usTemp  = usXEnd - usXStart;
    usTemp1 = usYEnd - usYStart;
    usTemp2 = usXStart;

    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usXEnd = (g_ucOsdHeight * 18 - usYStart);
        usXStart = usXEnd - usTemp1;
        usYStart = usTemp2;
        usYEnd = usYStart + usTemp;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usXStart = usYStart;
        usYStart = (g_ucOsdWidth * 12) - usXEnd;
        usXEnd = usXStart + usTemp1;
        usYEnd = usYStart + usTemp;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_180)
    {
        usXStart = (g_ucOsdWidth * 12) - usTemp - usXStart;
        usXEnd = usXStart + usTemp;
        usYStart = (g_ucOsdHeight * 18) - usTemp1 - usYStart;
        usYEnd = usYStart + usTemp1;
    }
    else
    {
    }

#else // #if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)


#endif

    SET_OSD_WINDOW_NUMBER(ucWindow);
    SET_OSD_WINDOW_COLOR(ucColor);

    SET_OSD_WINDOW_BLEND_ENABLE(_ENABLE);
    SET_OSD_WINDOW_ENABLE(_ENABLE);
    ScalerTimerWaitForEvent(_EVENT_DVS);
    ScalerOsdDrawWindow(usXStart, usYStart, usXEnd, usYEnd);
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
void OsdWindowDrawingByFont(BYTE ucWindow, BYTE ucRow, BYTE ucCol, BYTE ucWidth, BYTE ucHeight, BYTE ucColor)
{
    WORD usHstart = 0;
    WORD usHend = 0;
    WORD usVstart = 0;
    WORD usVend = 0;

    usHstart = ((WORD)ucCol * 12);
    usHend = usHstart + ((WORD)ucWidth * 12);

    if(ucRow > 0)
    {
        usVstart = (ucRow * 18);
    }
    usVend = usVstart + (18 * ucHeight);

    OsdWindowDrawing(ucWindow, usHstart, usVstart, usHend, usVend, ucColor);
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void OsdWindowDrawingByFontHighlight(BYTE ucWindow, BYTE ucRow1, BYTE ucCol1, BYTE ucWidth, BYTE ucHeight, BYTE ucColor, BYTE ucForegroundColor, BYTE ucBackgroundColor)
{
    WORD usHstart = 0;
    WORD usHend = 0;
    WORD usVstart = 0;
    WORD usVend = 0;

    usHstart = ((WORD)ucCol1 * 12);
    usHend = usHstart + ((WORD)ucWidth * 12);

    if(ucRow1 > 0)
    {
        usVstart = (ucRow1 * 18);
    }
    usVend = usVstart + (18 * ucHeight);

    OsdWindowDrawing(ucWindow, usHstart, usVstart, usHend, usVend, ucColor);

    ScalerOsdWindowHighlightFunction(_ENABLE, ucWindow, ucForegroundColor, ucBackgroundColor, _CP_BG);
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

#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)

