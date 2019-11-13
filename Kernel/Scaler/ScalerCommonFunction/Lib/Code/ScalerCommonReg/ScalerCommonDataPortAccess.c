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
// ID Code      : ScalerCommonDataPortAccess.c
// Update Note  :
//----------------------------------------------------------------------------------------------------
#include "ScalerCommonRegLibInternalInclude.h"

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
BYTE ScalerEnableAccessPort(WORD usAddr, BYTE ucValue);
void ScalerDisableAccessPort(WORD usAddr);
void ScalerSetDataPortByte(WORD usAddr, BYTE ucValue1, BYTE ucValue2);
void ScalerGetDataPortByte(WORD usAddr, BYTE ucValue, WORD usLength, BYTE *pucArray, bit bAutoInc);
void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr);
BYTE ScalerGetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Enable Access Port
// Input Value  : usAddr    --> Start address of register
//                ucValue   --> Data Port Value we want to set
// Output Value : Return Access Port Value
//--------------------------------------------------
BYTE ScalerEnableAccessPort(WORD usAddr, BYTE ucValue)
{
    usAddr = usAddr;
    return ucValue;
}

//--------------------------------------------------
// Description  : Disable Access Port
// Input Value  : usAddr   --> Start address of register
// Output Value : None
//--------------------------------------------------
void ScalerDisableAccessPort(WORD usAddr)
{
    usAddr = usAddr;
}

//--------------------------------------------------
// Description  : Set the value into selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue1  --> Data Port Value we want to set
//                ucValue2  --> Data Value we want to set
// Output Value : None
//--------------------------------------------------
void ScalerSetDataPortByte(WORD usAddr, BYTE ucValue1, BYTE ucValue2)
{
    volatile BYTE xdata *pucAddr = (volatile BYTE xdata *)usAddr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue1);
    *(pucAddr + 1) = ucValue2;
    ScalerDisableAccessPort(usAddr);
}

//--------------------------------------------------
// Description  : Get bytes from selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Address we want to Get
//                ucLength  --> Numbers of data we want to read
//                pArray    --> Pointer of the reading data array
//                bAutoInc  --> Address auto increasing select
// Output Value : None
//--------------------------------------------------
void ScalerGetDataPortByte(WORD usAddr, BYTE ucValue, WORD usLength, BYTE *pucArray, bit bAutoInc)
{
    BYTE ucAccessValue = 0;
    WORD usIndex = 0;
    volatile BYTE xdata *pucAddr = (volatile BYTE xdata *)usAddr;

    if(usLength > 0)
    {
        ucAccessValue = ScalerEnableAccessPort(usAddr, ucValue);

        for(usIndex = 0; usIndex < usLength; usIndex++)
        {
            if(bAutoInc == _AUTOINC)
            {
                *pucAddr = ucAccessValue + usIndex;
            }
            else
            {
                *pucAddr = ucAccessValue;
            }

            *(pucArray + usIndex) = *(pucAddr + 1);
        }

        ScalerDisableAccessPort(usAddr);
    }
}

//--------------------------------------------------
// Description  : Set some bits of selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Value we want to set
//                ucAnd     --> & operation
//                ucOr      --> | operation
// Output Value : None
//--------------------------------------------------
void ScalerSetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd, BYTE ucOr)
{
    BYTE ucValueTemp = 0;
    volatile BYTE xdata *pucAddr = (volatile BYTE xdata *)usAddr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue);
    ucValueTemp = *(pucAddr + 1);

    ucValueTemp = (ucValueTemp & ucAnd) | ucOr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue);
    *(pucAddr + 1) = ucValueTemp;

    ScalerDisableAccessPort(usAddr);
}

//--------------------------------------------------
// Description  : Set some bits of selected register in data port
// Input Value  : usAddr    --> Access Port Address of register
//                ucValue   --> Data Port Value we want to set
//                ucAnd     --> & operation
// Output Value : Value after & operation
//--------------------------------------------------
BYTE ScalerGetDataPortBit(WORD usAddr, BYTE ucValue, BYTE ucAnd)
{
    BYTE ucValueTemp = 0;
    volatile BYTE xdata *pucAddr = (volatile BYTE xdata *)usAddr;

    *pucAddr = ScalerEnableAccessPort(usAddr, ucValue);
    ucValueTemp = (*(pucAddr + 1)) & ucAnd;
    ScalerDisableAccessPort(usAddr);

    return ucValueTemp;
}

