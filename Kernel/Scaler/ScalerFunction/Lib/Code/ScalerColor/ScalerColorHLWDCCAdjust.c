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
// ID Code      : ScalerColorHLWDCCAdjust.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerColorLibInternalInclude.h"

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
void ScalerColorHLWDCCAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust DCC Highlight Window Active Region
// Input Value  : Highlight Window Actvie Region Option
//                EnumDBApply
// Output Value : None
//--------------------------------------------------
void ScalerColorHLWDCCAdjust(EnumHLWType enumHLWActive, EnumDBApply enumDBApply)
{
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, ~(_BIT3 | _BIT2), ((enumHLWActive & 0x03) << 2));
    ScalerColorDCCSetMeasureRegion(enumHLWActive);
    ScalerGlobalDDomainDBApply(enumDBApply);
}
