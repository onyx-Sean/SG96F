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
// ID Code      : RL6193_Series_ColorSampling420to422D1Setting.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "RL6193_Series_ColorLibInternalInclude.h"

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
void ScalerColor420To422D1Setting(WORD usHStart, WORD usHWidth);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : 420To422 parameter setting for D1 source
// Input Value  : usHStart, usHWidth
// Output Value : None
//--------------------------------------------------
void ScalerColor420To422D1Setting(WORD usHStart, WORD usHWidth)
{
    ScalerSetBit(P31_22_YUV420_TO_YUV422_HSTM0, ~(_BIT2 | _BIT1 | _BIT0), (HIBYTE(usHStart) & 0x07));
    ScalerSetByte(P31_24_YUV420_TO_YUV422_HSTL1, LOBYTE(usHStart));
    ScalerSetBit(P31_25_YUV420_TO_YUV422_HWIDM0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(usHWidth) & 0x0F));
    ScalerSetByte(P31_27_YUV420_TO_YUV422_HWIDL1, LOBYTE(usHWidth));
}
