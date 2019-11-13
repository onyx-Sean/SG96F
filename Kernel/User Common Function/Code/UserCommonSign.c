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
// ID Code      : UserCommonSign.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_SIGN__

#include "UserCommonInclude.h"

#if(_CODE_DIGITAL_SIGNATURE_SUPPORT != _SIGNATURE_TYPE_OFF)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _LOCAL_PUBLIC_KEY_BANK                      5
#define _LOCAL_PUBLIC_KEY_PAGE                      15

#define _PROTECT_PUBLIC_KEY_BANK                    7
#define _PROTECT_PUBLIC_KEY_PAGE                    9

// FHD key need at least 163 byte, so define 200 for reserved
#define _PUBLIC_KEY_LENGTH                          200

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
#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
void UserCommonSignMoveKey(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
//--------------------------------------------------
// Description  : FHD Move Sign Key to Protect Region
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonSignMoveKey(void)
{
    BYTE pucArray[_PUBLIC_KEY_LENGTH];
    memset(pucArray, 0, sizeof(pucArray));

    // Check if need to update key, Compare 5 byte key data from second data(first data is key length)
    UserCommonFlashRead(_LOCAL_PUBLIC_KEY_BANK, ((WORD)(_LOCAL_PUBLIC_KEY_PAGE << 12) + 1), 5, pucArray);
    UserCommonFlashRead(_PROTECT_PUBLIC_KEY_BANK, ((WORD)(_PROTECT_PUBLIC_KEY_PAGE << 12) + 1), 5, &pucArray[5]);

    // if the same, then don't update key
    if(memcmp(pucArray, &pucArray[5], 5) == 0)
    {
        return;
    }

    // Read Local Public Key
    UserCommonFlashRead(_LOCAL_PUBLIC_KEY_BANK, (WORD)(_LOCAL_PUBLIC_KEY_PAGE << 12), _PUBLIC_KEY_LENGTH, pucArray);

    // Erase Protect Public Key Region
    UserCommonFlashErasePage(_PROTECT_PUBLIC_KEY_BANK, _PROTECT_PUBLIC_KEY_PAGE);

    // Move Public Key to Protect Region
    UserCommonFlashWrite(_PROTECT_PUBLIC_KEY_BANK, (WORD)(_PROTECT_PUBLIC_KEY_PAGE << 12), _PUBLIC_KEY_LENGTH, pucArray);
}
#endif //#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)

#endif //#if(_CODE_DIGITAL_SIGNATURE_SUPPORT != _SIGNATURE_TYPE_OFF)
