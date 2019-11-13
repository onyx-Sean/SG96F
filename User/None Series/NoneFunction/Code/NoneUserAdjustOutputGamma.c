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
// ID Code      : NoneUserAdjustOutputGamma.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_ADJUST_OUTPUT_GAMMA__

#include "UserCommonInclude.h"

#if((_OSD_TYPE == _NONE_OSD) && (_GAMMA_FUNCTION == _ON))

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************
#if(_OGC_SUPPORT == _ON)
WORD code tGAMMA_OSD_INDEX[] =
{
    _OGC_GAMMA1_ADDRESS,            _OGC_GAMMA2_ADDRESS,        _OGC_GAMMA3_ADDRESS,

#if(_OGC_TOTAL_GAMMA == 5)
    _OGC_GAMMA4_ADDRESS,            _OGC_GAMMA5_ADDRESS,
#endif
};
#endif  // End of #if(_OGC_SUPPORT == _ON)


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserAdjustGamma(BYTE ucGamma);

//-------------------------------------------------------
// PCM
//-------------------------------------------------------
#if(_PCM_FUNCTION == _ON)
void UserAdjustPCM(BYTE ucPCM);
#endif

//-------------------------------------------------------
// HDR
//-------------------------------------------------------
#if(_ULTRA_HDR_SUPPORT == _ON)
void UserAdjustHDR2084LoadTable(EnumHDRMaxMasteringLvType enumHDRMaxMasteringLvType, EnumHDRColorMatrix enumHDRColorMatrix, bit bDarkEnhanceEnable);
void UserAdjustHDR2084(EnumHDRMaxMasteringLvType enumHDRMaxMasteringLvType, EnumHDRColorMatrix enumHDRColorMatrix, bit bDarkEnhanceEnable);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Adjust Gamma
// Input Value  : Gamma type
// Output Value : None
//--------------------------------------------------
void UserAdjustGamma(BYTE ucGamma)
{
    if(ucGamma != _GAMMA_OFF)
    {
#if(_OGC_SUPPORT == _ON)
        ScalerColorOutputGammaAdjust(&g_pucDISP_CALIBRATION_FLASH[tGAMMA_OSD_INDEX[ucGamma]], _OGC_FLASH_BANK);
        RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

#if(_CONTRAST_SUPPORT == _ON)
        UserAdjustContrast(GET_OSD_CONTRAST());
#endif

#else

#if(_RGB_GAMMA_FUNCTION == _ON)
        ScalerColorRGBOutputGammaEnable(_FUNCTION_OFF);
#endif

        ScalerColorOutputGammaAdjust(tGAMMA_TABLE[ucGamma], GET_CURRENT_BANK_NUMBER());

#if(_RGB_GAMMA_FUNCTION == _ON)
        UserAdjustRGBGamma(ucGamma);
        ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
        ScalerColorRGBOutputGammaEnable(_FUNCTION_ON);
#endif

#endif // End of #if(_OGC_SUPPORT == _ON)
    }
}


#if(_PCM_FUNCTION == _ON)
//--------------------------------------------------
// Description  : Adjust PCM
// Input Value  : ucPCM
// Output Value : None
//--------------------------------------------------
void UserAdjustPCM(BYTE ucPCM)
{
    if(ucPCM != _PCM_OSD_NATIVE)
    {
#if(_OCC_SUPPORT == _ON)
        if(ucPCM == _PCM_OSD_SRGB)
        {
            ScalerColorPCMLoadTable(_PCM_SRGB, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_SRGBMATRIX_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
        }
        else if(ucPCM == _PCM_OSD_ADOBE_RGB)
        {
            ScalerColorPCMLoadTable(_PCM_ADOBE_RGB, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_ADOBEMATRIX_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
        }

#if(_RGB_3D_GAMMA == _ON)
        else if(ucPCM == _PCM_OSD_SOFT_PROFT)
        {
            ScalerColorPCMLoadTable(_PCM_SOFT_PROFT, _NULL_POINTER, g_pucDISP_CALIBRATION_FLASH + _OCC_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + _OCC_SOFTPROOF_ADDRESS, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
        }
#endif // End of #if(_RGB_3D_GAMMA == _ON)

        else
#endif // End of #if(_OCC_SUPPORT == _ON)
        {
            ScalerColorPCMLoadTable(_PCM_USER_MODE, tPCM_USER_TABLE[(ucPCM - _PCM_OSD_USER) * 3], tPCM_USER_TABLE[((ucPCM - _PCM_OSD_USER) * 3) + 1], tPCM_USER_TABLE[((ucPCM - _PCM_OSD_USER) * 3) + 2], GET_CURRENT_BANK_NUMBER(), _OCC_COLORMATRIX_TABLE_SIZE);
        }
    }
}
#endif  // End of #if(_PCM_FUNCTION == _ON)

#if(_ULTRA_HDR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Load HDR 2084 Table
// Input Value  : enumHDRMaxMasteringLvType, enumHDRColorMatrix, bDarkEnhanceEnable
// Output Value : None
//--------------------------------------------------
void UserAdjustHDR2084LoadTable(EnumHDRMaxMasteringLvType enumHDRMaxMasteringLvType, EnumHDRColorMatrix enumHDRColorMatrix, bit bDarkEnhanceEnable)
{
    WORD usHDRInputGammaFlashAddress = 0x0000;
    WORD usHDRColorMatrixFlashAddress = 0x0000;

    // Input Gamma Setting
    switch(enumHDRMaxMasteringLvType)
    {
        case _HDR_MAX_MASTERING_LV_TYPE_1200:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_1200_NOR_ADDRESS;
            break;

        case _HDR_MAX_MASTERING_LV_TYPE_4000:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_4000_NOR_ADDRESS;
            break;

        case _HDR_MAX_MASTERING_LV_TYPE_10000:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_10000_NOR_ADDRESS;
            break;

        case _HDR_MAX_MASTERING_LV_TYPE_540:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_540_NOR_ADDRESS;
            break;

        default:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_1200_NOR_ADDRESS;
            break;
    }

    // Dark Enahnce Setting
    if(bDarkEnhanceEnable == _ON)
    {
        usHDRInputGammaFlashAddress += _OGC_HDR_IG_TABLE_SIZE;
    }

    // Color Matrix Setting
    switch(enumHDRColorMatrix)
    {
        case _HDR_COLOR_MATRIX_SRGB:
            usHDRColorMatrixFlashAddress = _OCC_HDR_SRGB_MATRIX_ADDRESS;
            break;

        case _HDR_COLOR_MATRIX_ADOBE:
            usHDRColorMatrixFlashAddress = _OCC_HDR_ADOBE_MATRIX_ADDRESS;
            break;

        case _HDR_COLOR_MATRIX_DCIP3_D65:
            usHDRColorMatrixFlashAddress = _OCC_HDR_DCIP3_D65_MATRIX_ADDRESS;
            break;

        case _HDR_COLOR_MATRIX_BT2020:
            usHDRColorMatrixFlashAddress = _OCC_HDR_BT2020_MATRIX_ADDRESS;
            break;

        default:
            usHDRColorMatrixFlashAddress = _OCC_HDR_BT2020_MATRIX_ADDRESS;
            break;
    }

    ScalerColorPCMLoadTable(_PCM_HDR_2084, g_pucDISP_CALIBRATION_FLASH + usHDRInputGammaFlashAddress, g_pucDISP_CALIBRATION_FLASH + _OCC_HDR_GAMMA10_ADDRESS, g_pucDISP_CALIBRATION_FLASH + usHDRColorMatrixFlashAddress, _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
}

//--------------------------------------------------
// Description  : Adjust HDR 2084 force mode
// Input Value  : enumHDRMaxMasteringLvType, enumHDRColorMatrix, bDarkEnhanceEnable
// Output Value : None
//--------------------------------------------------
void UserAdjustHDR2084(EnumHDRMaxMasteringLvType enumHDRMaxMasteringLvType, EnumHDRColorMatrix enumHDRColorMatrix, bit bDarkEnhanceEnable)
{
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerColorOutputGammaEnable(_FUNCTION_OFF);
    ScalerColorSRGBEnable(_FUNCTION_OFF);
    ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);

#if(_RGB_3D_GAMMA == _ON)
    ScalerColorRGB3DGammaEnable(_FUNCTION_OFF);
#endif

#if(_BRIGHTNESS_SUPPORT == _ON)
    ScalerColorBrightnessEnable(_FUNCTION_OFF);
#endif

#if(_CONTRAST_SUPPORT == _ON)
    ScalerColorContrastEnable(_FUNCTION_OFF);
#endif

    UserAdjustHDR2084LoadTable(enumHDRMaxMasteringLvType, enumHDRColorMatrix, bDarkEnhanceEnable);
    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
    ScalerColorOutputGammaEnable(_FUNCTION_ON);
    ScalerColorSRGBEnable(_FUNCTION_ON);
    ScalerColorPCMInputGammaEnable(_FUNCTION_ON);
}
#endif

#endif // End of #if((_OSD_TYPE == _REALTEK_2014_OSD) && (_GAMMA_FUNCTION == _ON))



