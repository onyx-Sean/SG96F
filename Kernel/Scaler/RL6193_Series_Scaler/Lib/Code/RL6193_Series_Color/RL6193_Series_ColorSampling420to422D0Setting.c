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
// ID Code      : RL6193_Series_ColorSampling420to422D0Setting.c
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
void ScalerColor420To422D0Setting(WORD usHStart, WORD usHWidth);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : 420To422 parameter setting for D0 source
// Input Value  : usHStart, usHWidth
// Output Value : None
//--------------------------------------------------
void ScalerColor420To422D0Setting(WORD usHStart, WORD usHWidth)
{
    ScalerSetBit(P31_22_YUV420_TO_YUV422_HSTM0, ~(_BIT5 | _BIT4 | _BIT3), (HIBYTE(usHStart) & 0x07) << 3);
    ScalerSetByte(P31_23_YUV420_TO_YUV422_HSTL0, LOBYTE(usHStart));
    ScalerSetBit(P31_25_YUV420_TO_YUV422_HWIDM0, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (HIBYTE(usHWidth) & 0x0F) << 4);
    ScalerSetByte(P31_26_YUV420_TO_YUV422_HWIDL0, LOBYTE(usHWidth));
}
