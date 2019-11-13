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
// ID Code      : UserCommonAdjust.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_ADJUST__

#include "UserCommonInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************

#if(_VGA_SUPPORT == _ON)

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
//----------------------------------------------------------------------------------------------------
// TABLE DIGITAL FILTER ENHANCE PHASE MODE
//----------------------------------------------------------------------------------------------------
#include _DIGITAL_FILTER_ENHANCE_PHASE_TABLE
#endif

#if(_RINGING_FILTER_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// TABLE RINGING FILTER OFFSET COEFFICIENT
//----------------------------------------------------------------------------------------------------
#include _RINGING_FILTER_TABLE
#endif

#endif  // End of #if(_VGA_SUPPORT == _ON)


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

#if(_UNIFORMITY_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// TABLE Uniformity Gain Address
//----------------------------------------------------------------------------------------------------
WORD code tUNIFORMITY_OSD_TYPE_ADDRESS_INDEX[] =
{
    _UNIFORMITY_TYPE1_ADDRESS,
    _UNIFORMITY_TYPE2_ADDRESS,
    _UNIFORMITY_TYPE3_ADDRESS,
    _UNIFORMITY_TYPE4_ADDRESS,
    _UNIFORMITY_TYPE5_ADDRESS,
    _UNIFORMITY_TYPE6_ADDRESS,
};

BYTE code tUNIFORMITY_OSD_TYPE_BANK_INDEX[] =
{
    _UNIFORMITY_TYPE1_BANK,
    _UNIFORMITY_TYPE2_BANK,
    _UNIFORMITY_TYPE3_BANK,
    _UNIFORMITY_TYPE4_BANK,
    _UNIFORMITY_TYPE5_BANK,
    _UNIFORMITY_TYPE6_BANK,
};

#if(_UNIFORMITY_LEVEL0_SUPPORT == _ON)
//----------------------------------------------------------------------------------------------------
// TABLE Uniformity Offset and Decay Address
//----------------------------------------------------------------------------------------------------
WORD code tUNIFORMITY_OSD_TYPE_OFFSET_ADDRESS_INDEX[] =
{
    _UNIFORMITY_TYPE1_OFFSET_ADDRESS,
    _UNIFORMITY_TYPE2_OFFSET_ADDRESS,
    _UNIFORMITY_TYPE3_OFFSET_ADDRESS,
    _UNIFORMITY_TYPE4_OFFSET_ADDRESS,
    _UNIFORMITY_TYPE5_OFFSET_ADDRESS,
    _UNIFORMITY_TYPE6_OFFSET_ADDRESS,
};
BYTE code tUNIFORMITY_OSD_TYPE_OFFSET_BANK_INDEX[] =
{
    _UNIFORMITY_TYPE1_OFFSET_BANK,
    _UNIFORMITY_TYPE2_OFFSET_BANK,
    _UNIFORMITY_TYPE3_OFFSET_BANK,
    _UNIFORMITY_TYPE4_OFFSET_BANK,
    _UNIFORMITY_TYPE5_OFFSET_BANK,
    _UNIFORMITY_TYPE6_OFFSET_BANK,
};
WORD code tUNIFORMITY_OSD_TYPE_DECAY_ADDRESS_INDEX[] =
{
    _UNIFORMITY_TYPE1_DECAY_ADDRESS,
    _UNIFORMITY_TYPE2_DECAY_ADDRESS,
    _UNIFORMITY_TYPE3_DECAY_ADDRESS,
    _UNIFORMITY_TYPE4_DECAY_ADDRESS,
    _UNIFORMITY_TYPE5_DECAY_ADDRESS,
    _UNIFORMITY_TYPE6_DECAY_ADDRESS,
};
BYTE code tUNIFORMITY_OSD_TYPE_DECAY_BANK_INDEX[] =
{
    _UNIFORMITY_TYPE1_DECAY_BANK,
    _UNIFORMITY_TYPE2_DECAY_BANK,
    _UNIFORMITY_TYPE3_DECAY_BANK,
    _UNIFORMITY_TYPE4_DECAY_BANK,
    _UNIFORMITY_TYPE5_DECAY_BANK,
    _UNIFORMITY_TYPE6_DECAY_BANK,
};
BYTE code tUNIFORMITY_OSD_TYPE_OFFSET_ENABLE_INDEX[] =
{
    _UNIFORMITY_OFFSET_TYPE0,
    _UNIFORMITY_OFFSET_TYPE1,
    _UNIFORMITY_OFFSET_TYPE2,
    _UNIFORMITY_OFFSET_TYPE3,
    _UNIFORMITY_OFFSET_TYPE4,
    _UNIFORMITY_OFFSET_TYPE5,
};
#endif // End of #if(_UNIFORMITY_LEVEL0_SUPPORT == _ON)
#endif // End of #if(_UNIFORMITY_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
WORD UserCommonAdjustGetAdcClockRange(BYTE ucPar);
void UserCommonAdjustClock(WORD usUserIHTotal);
void UserCommonAdjustPhase(BYTE ucPhase);

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
void UserCommonAdjustDigitalFilterEnhancePhase(void);
#endif

#if(_RINGING_FILTER_SUPPORT == _ON)
void UserCommonAdjustRingingFilter(void);
#endif
#endif

#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
void UserCommonAdjustEmbeddedDpSwitch(void);
#endif

#if(_TRANSLATOR_SUPPORT == _OFF)
WORD UserCommonAdjustGetHPositionRange(BYTE ucPar);
WORD UserCommonAdjustGetHPositionHBiasValue(void);
WORD UserCommonAdjustGetVPositionRange(BYTE ucPar);
WORD UserCommonAdjustGetVPositionVBiasValue(void);
void UserCommonAdjustHPosition(BYTE ucUserHPosition);
void UserCommonAdjustVPosition(BYTE ucUserVPosition);
#endif

BYTE UserCommonAdjustRealValueToPercent(WORD usRealValue, WORD usMax, WORD usMin, WORD usCenter);
WORD UserCommonAdjustPercentToRealValue(BYTE ucPercentValue, WORD usMax, WORD usMin, WORD usCenter);

#if(_OVERSCAN_SUPPORT == _ON)
void UserCommonAdjustOverScan(void);
#endif

#if(_UNDERSCAN_SUPPORT == _ON)
void UserCommonAdjustUnderScan(void);
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
void UserCommonAdjustAspectRatio(void);
#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
void UserCommonAdjustRotationInputSize(void);
void UserCommonAdjustRotationDisplaySize(void);
#endif

#if(_I_DITHER_SUPPORT == _ON)
void UserCommonAdjustIDither(void);
#endif

#if(_ULTRA_VIVID_SUPPORT == _ON)
void UserCommonAdjustUltraVivid(EnumFunctionOnOFF enumFunctionOnOFF, EnumColorSpace enumColorFormat, EnumDBApply enumDBApply);
#endif

#if(_D_DITHER_SUPPORT == _ON)
void UserCommonAdjustDDither(void);
#endif

// 10  bit Panel
WORD UserCommonAdjust10bitPanelCompensate(WORD usData);

#if(_SHARPNESS_SUPPORT == _ON)
void UserCommonAdjustSharpness(EnumSourceSearchPort enumSourceSearchPort);
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
void UserCommonAdjustHDR(EnumHDRFlowStatus enumHDRFlowStatus);
EnumHDRChangeStatus UserCommonAdjustHDRChangeStatus(EnumSourceSearchPort enumSourceSearchPort);
EnumHDRTargetStatus UserCommonAdjustHDRTargetStatus(EnumSourceSearchPort enumSourceSearchPort);
EnumHDRTargetStatus UserCommonAdjustHDRAutoModeInitial(EnumSourceSearchPort enumSourceSearchPort);
EnumHDRMaxMasteringLvType UserCommonAdjustHDRGetLvType(void);
void UserCommonAdjustHDRAutoMode(bit bDarkEnhanceEnable);
bit UserCommonAdjustHDREnableStatus(EnumHDRModeDef enumHDRModeDef);
#endif

#if(_DCR_SUPPORT == _ON)
void UserCommonAdjustDCR(void);
#endif

#if(_FREEZE_SUPPORT == _ON)
void UserCommonAdjustDisplayFreeze(bit bEn);
#endif

#if(_UNIFORMITY_SUPPORT == _ON)
void UserCommonAdjustPanelUniformity(EnumUniformityTypeSelect enumUniformityType, EnumUniformityModeSelect enumUniformityMode);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_VGA_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check if the ADC clock (IHTotal) is out of range. Range = (BackPorch + FrontPorch) * 2 / 5 .
// Input Value  : usClock   --> ADC Clock (IHTotal)
// Output Value : Return _TRUE if not out of range
//--------------------------------------------------
WORD UserCommonAdjustGetAdcClockRange(BYTE ucPar)
{
    WORD usDelta1 = 0;
    WORD usDelta2 = 0;
    WORD usDelta = 0;

    usDelta1 = GET_ADC_LIMIT_CLOCK() - g_stVGAModeUserData.usCenterClock;

    usDelta2 = g_stVGAModeUserData.usCenterClock - ScalerVgaTopGetCaptureHStartPosition() - ScalerVgaTopGetCaptureHWidth();

    usDelta = (usDelta1 < usDelta2) ? usDelta1 : usDelta2;

    if(ucPar == _GET_CLOCKRANGE_MAX)
    {
        if(usDelta < _CLOCK_BIAS)
        {
            return (g_stVGAModeUserData.usCenterClock + usDelta);
        }
        else
        {
            return (g_stVGAModeUserData.usCenterClock + _CLOCK_BIAS);
        }
    }
    else if(ucPar == _GET_CLOCKRANGE_MIN)
    {
        if(usDelta < _CLOCK_BIAS)
        {
            return (g_stVGAModeUserData.usCenterClock - usDelta);
        }
        else
        {
            return (g_stVGAModeUserData.usCenterClock - _CLOCK_BIAS);
        }
    }

    return (g_stVGAModeUserData.usCenterClock);
}

//--------------------------------------------------
// Description  : Adjust clock.
// Input Value  : usUserIHTotal --> OSD Value(0~100) or Real Value
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustClock(WORD usUserIHTotal)
{
#if(_AUTO_CLOCK_SAVE_VALUE_OPTION == _CLOCK_SAVE_PERCENT_VALUE)

    WORD usClockRangeMax = 0;
    WORD usClockRangeMin = 0;

    usClockRangeMax = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MAX);
    usClockRangeMin = UserCommonAdjustGetAdcClockRange(_GET_CLOCKRANGE_MIN);
    usUserIHTotal = UserCommonAdjustPercentToRealValue((BYTE)usUserIHTotal, usClockRangeMax, usClockRangeMin, (((usClockRangeMax - usClockRangeMin) / 2) + usClockRangeMin));

#endif

    ScalerGlobalWatchDog(_DISABLE);

    ScalerAPLLFastLockAdjust(usUserIHTotal);

    ScalerGlobalWatchDog(_ENABLE);
}

//--------------------------------------------------
// Description  : Adjust phase
// Input Value  : ucPhase --> phase value
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustPhase(BYTE ucPhase)
{
    ucPhase = UserCommonAdjustPercentToRealValue(ucPhase, _ADJUST_PHASE_MAX, _ADJUST_PHASE_MIN, _ADJUST_PHASE_CENTER);

    ScalerGlobalWatchDog(_DISABLE);

    ScalerPLLSetPhase(ucPhase, UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IVFREQ));

    ScalerGlobalWatchDog(_ENABLE);
}

#if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)
//--------------------------------------------------
// Description  : Adjust Digital Filter Enhanced Phase Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustDigitalFilterEnhancePhase(void)
{
    BYTE ucI = 0;
    BYTE ucTemp = 0;
    BYTE ucSpan = 0;
    SWORD shTemp = 0;
    WORD usPixelRate = (ScalerSyncGetInputPixelClk() + 5) / 10;

    if(usPixelRate <= tDF_ENHANCE_PHASE_SETTING[0])
    {
        pData[0] = tDF_ENHANCE_PHASE_SETTING[1];
        pData[1] = tDF_ENHANCE_PHASE_SETTING[2];
        pData[2] = tDF_ENHANCE_PHASE_SETTING[3];
    }
    else if(usPixelRate >= tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 4])
    {
        pData[0] = tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 3];
        pData[1] = tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 2];
        pData[2] = tDF_ENHANCE_PHASE_SETTING[sizeof(tDF_ENHANCE_PHASE_SETTING) - 1];
    }
    else
    {
        for(ucI = 0; tDF_ENHANCE_PHASE_SETTING[ucI * 4] < usPixelRate; ucI++) {}

        ucI--;

        ucTemp = usPixelRate - tDF_ENHANCE_PHASE_SETTING[ucI * 4];
        ucSpan = tDF_ENHANCE_PHASE_SETTING[(ucI + 1) * 4] - tDF_ENHANCE_PHASE_SETTING[ucI * 4];

        shTemp = tDF_ENHANCE_PHASE_SETTING[((ucI + 1) * 4) + 1] - tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 1];
        pData[0] = tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 1] + (SWORD)ucTemp * shTemp / ucSpan;

        shTemp = tDF_ENHANCE_PHASE_SETTING[((ucI + 1) * 4) + 2] - tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 2];
        pData[1] = tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 2] + (SWORD)ucTemp * shTemp / ucSpan;

        shTemp = tDF_ENHANCE_PHASE_SETTING[((ucI + 1) * 4) + 3] - tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 3];
        pData[2] = tDF_ENHANCE_PHASE_SETTING[(ucI * 4) + 3] + (SWORD)ucTemp * shTemp / ucSpan;
    }

    ScalerColorDigitalFilterEnhancePhaseAdjust(pData);
}
#endif // End of #if(_DIG_FILTER_ENHANCE_PHASE_ENABLE == _ENABLE)


#if(_RINGING_FILTER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust Ringing Filter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustRingingFilter(void)
{
    BYTE ucI = 0;
    BYTE ucTemp = 0;
    BYTE ucSpan = 0;
    SWORD shTemp = 0;
    WORD usPixelRate = (ScalerSyncGetInputPixelClk() + 5) / 10;

    if(usPixelRate <= tRF_OFFSET_COEF_SETTING[0])
    {
        pData[0] = tRF_OFFSET_COEF_SETTING[1];
    }
    else if(usPixelRate >= tRF_OFFSET_COEF_SETTING[sizeof(tRF_OFFSET_COEF_SETTING) - 2])
    {
        pData[0] = tRF_OFFSET_COEF_SETTING[sizeof(tRF_OFFSET_COEF_SETTING) - 1];
    }
    else
    {
        for(ucI = 0; tRF_OFFSET_COEF_SETTING[ucI * 2] < usPixelRate; ucI++) {}

        ucI--;

        ucTemp = usPixelRate - tRF_OFFSET_COEF_SETTING[ucI * 2];
        ucSpan = tRF_OFFSET_COEF_SETTING[(ucI + 1) * 2] - tRF_OFFSET_COEF_SETTING[ucI * 2];

        shTemp = tRF_OFFSET_COEF_SETTING[((ucI + 1) * 2) + 1] - tRF_OFFSET_COEF_SETTING[(ucI * 2) + 1];
        pData[0] = tRF_OFFSET_COEF_SETTING[(ucI * 2) + 1] + (SWORD)ucTemp * shTemp / ucSpan;
    }

    ScalerColorRingingFilterAdjust(pData);
}
#endif // End of #if(_RINGING_FILTER_SUPPORT == _ON)
#endif // End of #if(_VGA_SUPPORT == _ON)

#if(_DP_EMBEDDED_SWITCH_SUPPORT_TYPE == _DP_EMBEDDED_SWITCH_2_DP)
//--------------------------------------------------
// Description  : Check embedded DP switch status
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustEmbeddedDpSwitch(void)
{
    // Proceed if not DP
    if(SysSourceGetSourceType() == _SOURCE_DP)
    {
        return;
    }
    else
    {
        // Proceed when in steady states
        switch(SysModeGetModeState())
        {
            case _MODE_STATUS_ACTIVE:
            case _MODE_STATUS_NOSUPPORT:
                break;

            default:
                return;
        }
    }

    UserAdjustEmbeddedDpSwitch();
}
#endif

#if(_TRANSLATOR_SUPPORT == _OFF)
//--------------------------------------------------
// Description  : Get Max or Min H-Position
// Input Value  : ucPar--> Max or Min paramater
// Output Value : Max or Min H-Position
//--------------------------------------------------
WORD UserCommonAdjustGetHPositionRange(BYTE ucPar)
{
    WORD usDeltaIHWidthOverScan = 0;
    WORD usIHWidth = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIHWidth = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IHWIDTH);

#if((_OVERSCAN_SUPPORT == _ON) && (_VGA_CAPTURE_SUPPORT == _OFF))
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIHWidth >= ScalerVgaTopGetCaptureHWidth())
            {
#if(_FORMAT_CONVERSION_SUPPORT == _ON)
                if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
                {
                    usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgaTopGetCaptureHWidth()));
                }
                else
#endif
                {
                    usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgaTopGetCaptureHWidth()) / 2);
                }
            }
        }
#endif
    }
    else
#endif
    {
        usIHWidth = GET_INPUT_TIMING_HWIDTH();

#if(_OVERSCAN_SUPPORT == _ON)
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIHWidth >= ScalerVgipGetCaptureHWidth())
            {
#if(_FORMAT_CONVERSION_SUPPORT == _ON)
                if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
                {
                    usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgipGetCaptureHWidth()));
                }
                else
#endif
                {
                    usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgipGetCaptureHWidth()) / 2);
                }
            }
        }
#endif
    }

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#if(_OVERSCAN_SUPPORT == _ON)
    if(UserInterfaceGetOverScanStatus() == _FALSE)
#endif
    {
        if((ScalerRotationCheckStatus() == _TRUE) && (GET_ROT_DISP_SIZE() == _ROT_PIXEL_BY_PIXEL))
        {
            if((GET_ROT_TYPE() == _ROT_CW90) || (GET_ROT_TYPE() == _ROT_CW270))
            {
                if(_PANEL_DV_HEIGHT < usIHWidth)
                {
                    usDeltaIHWidthOverScan = (usIHWidth - _PANEL_DV_HEIGHT);
                }
            }
            else if(GET_ROT_TYPE() == _ROT_CW180)
            {
                // Calculate / Set H
                if(_PANEL_DH_WIDTH < usIHWidth)
                {
                    usDeltaIHWidthOverScan = (usIHWidth - _PANEL_DH_WIDTH);
                }
            }
        }
    }
#endif

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(ucPar == _GET_HPOSITIONRANGE_MAX)
        {
            return (g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan + _HPOSITION_BIAS);
        }
        else if(ucPar == _GET_HPOSITIONRANGE_MIN)
        {
            return (g_stVGAModeUserData.usCenterHPosition + usDeltaIHWidthOverScan - _HPOSITION_BIAS);
        }
        else
        {
            return (g_stVGAModeUserData.usCenterHPosition);
        }
    }
    else
#endif
    {
        if(ucPar == _GET_HPOSITIONRANGE_MAX)
        {
            return (GET_INPUT_TIMING_HSTART() + usDeltaIHWidthOverScan + _HPOSITION_BIAS);
        }
        else if(ucPar == _GET_HPOSITIONRANGE_MIN)
        {
            return (GET_INPUT_TIMING_HSTART() + usDeltaIHWidthOverScan - _HPOSITION_BIAS);
        }
        else
        {
            return (GET_INPUT_TIMING_HSTART() + usDeltaIHWidthOverScan);
        }
    }
}

//--------------------------------------------------
// Description  : Get HPosition H Bias Value
// Input Value  : None
// Output Value : H Bias Value
//--------------------------------------------------
WORD UserCommonAdjustGetHPositionHBiasValue(void)
{
    WORD usHBias = 0;
    WORD usDeltaIHWidthOverScan = 0;
    WORD usIHWidth = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIHWidth = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IHWIDTH);

#if((_OVERSCAN_SUPPORT == _ON) && (_VGA_CAPTURE_SUPPORT == _OFF))
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIHWidth >= ScalerVgaTopGetCaptureHWidth())
            {
                usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgaTopGetCaptureHWidth()) / 2);
            }
        }
#endif

        usHBias = ((g_stVGAModeUserData.usCenterHPosition - ScalerVgaTopGetCaptureHStartPosition()) <= (_MAX_H_POSITION_RANGE / 2)) ?
                  (g_stVGAModeUserData.usCenterHPosition - ScalerVgaTopGetCaptureHStartPosition() - 1) : (_MAX_H_POSITION_RANGE / 2);
    }
    else
#endif
    {
        usIHWidth = GET_INPUT_TIMING_HWIDTH();

#if(_OVERSCAN_SUPPORT == _ON)
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIHWidth >= ScalerVgipGetCaptureHWidth())
            {
                usDeltaIHWidthOverScan = ((usIHWidth - ScalerVgipGetCaptureHWidth()) / 2);
            }
        }
#endif

        usHBias = ((GET_INPUT_TIMING_HSTART() + usDeltaIHWidthOverScan - ScalerVgipGetCaptureHStartPosition()) <= (_MAX_H_POSITION_RANGE / 2)) ?
                  (GET_INPUT_TIMING_HSTART() + usDeltaIHWidthOverScan - ScalerVgipGetCaptureHStartPosition() - 1) : (_MAX_H_POSITION_RANGE / 2);
    }

    return usHBias;
}

//--------------------------------------------------
// Description  : Get Max or Min V-Position
// Input Value  : ucPar--> Max or Min paramater
// Output Value : Max or Min V-Position
//--------------------------------------------------
WORD UserCommonAdjustGetVPositionRange(BYTE ucPar)
{
    WORD usDeltaIVHeightOverScan = 0;
    WORD usDeltaIVHeightUnderScan = 0;
    WORD usIVHeight = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIVHeight = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IVHEIGHT);

#if(_OVERSCAN_SUPPORT == _ON)
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIVHeight >= ScalerVgaTopGetCaptureVHeight())
            {
                usDeltaIVHeightOverScan = ((usIVHeight - ScalerVgaTopGetCaptureVHeight()) / 2);
            }
        }
#endif
    }
    else
#endif
    {
        usIVHeight = GET_INPUT_TIMING_VHEIGHT();

#if(_OVERSCAN_SUPPORT == _ON)
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIVHeight >= ScalerVgipGetCaptureVHeight())
            {
                usDeltaIVHeightOverScan = ((usIVHeight - ScalerVgipGetCaptureVHeight()) / 2);
            }
        }
#endif
    }

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#if(_OVERSCAN_SUPPORT == _ON)
    if(UserInterfaceGetOverScanStatus() == _FALSE)
#endif
    {
        if((ScalerRotationCheckStatus() == _TRUE) && (GET_ROT_DISP_SIZE() == _ROT_PIXEL_BY_PIXEL))
        {
            if((GET_ROT_TYPE() == _ROT_CW90) || (GET_ROT_TYPE() == _ROT_CW270))
            {
                // Calculate / Set V
                if(_PANEL_DH_WIDTH < usIVHeight)
                {
                    usDeltaIVHeightOverScan = ((usIVHeight - _PANEL_DH_WIDTH) / 2);
                }
            }
            else if(GET_ROT_TYPE() == _ROT_CW180)
            {
                if(_PANEL_DV_HEIGHT < usIVHeight)
                {
                    usDeltaIVHeightOverScan = ((usIVHeight - _PANEL_DV_HEIGHT) / 2);
                }
            }
        }
    }
#endif

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        if(usIVHeight <= ScalerVgaTopGetCaptureVHeight())
        {
            usDeltaIVHeightUnderScan = ((ScalerVgaTopGetCaptureVHeight() - usIVHeight) / 2);
        }

        if(ucPar == _GET_VPOSITIONRANGE_MAX)
        {
            return (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan + _VPOSITION_BIAS);
        }
        else if(ucPar == _GET_VPOSITIONRANGE_MIN)
        {
            return (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - _VPOSITION_BIAS);
        }
        else
        {
            return (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan);
        }
    }
    else
#endif
    {
        if(usIVHeight <= ScalerVgipGetCaptureVHeight())
        {
            usDeltaIVHeightUnderScan = ((ScalerVgipGetCaptureVHeight() - usIVHeight) / 2);
        }

        if(ucPar == _GET_VPOSITIONRANGE_MAX)
        {
            return (GET_INPUT_TIMING_VSTART() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan + _VPOSITION_BIAS);
        }
        else if(ucPar == _GET_VPOSITIONRANGE_MIN)
        {
            return (GET_INPUT_TIMING_VSTART() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - _VPOSITION_BIAS);
        }
        else
        {
            return (GET_INPUT_TIMING_VSTART() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan);
        }
    }
}

//--------------------------------------------------
// Description  : Get VPosition V Bias Value
// Input Value  : None
// Output Value : V Bias Value
//--------------------------------------------------
WORD UserCommonAdjustGetVPositionVBiasValue(void)
{
    WORD usVBias = 0;
    WORD usDeltaIVHeightOverScan = 0;
    WORD usDeltaIVHeightUnderScan = 0;
    WORD usIVHeight = 0;

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        usIVHeight = UserCommonModeSearchGetModetableTimingDataItem(g_stVGAModeUserData.ucModeNumber, _IVHEIGHT);

#if(_OVERSCAN_SUPPORT == _ON)
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIVHeight >= ScalerVgaTopGetCaptureVHeight())
            {
                usDeltaIVHeightOverScan = ((usIVHeight - ScalerVgaTopGetCaptureVHeight()) / 2);
            }
        }
#endif

        if(usIVHeight <= ScalerVgaTopGetCaptureVHeight())
        {
            usDeltaIVHeightUnderScan = ((ScalerVgaTopGetCaptureVHeight() - usIVHeight) / 2);
        }

        usVBias = ((g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgaTopGetCaptureVStartPosition()) < (_MAX_V_POSITION_RANGE / 2)) ?
                  (g_stVGAModeUserData.usCenterVPosition + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgaTopGetCaptureVStartPosition()) : (_MAX_V_POSITION_RANGE / 2);

        return usVBias;
    }
    else
#endif
    {
        usIVHeight = GET_INPUT_TIMING_VHEIGHT();

#if(_OVERSCAN_SUPPORT == _ON)
        if(UserInterfaceGetOverScanStatus() == _TRUE)
        {
            if(usIVHeight >= ScalerVgipGetCaptureVHeight())
            {
                usDeltaIVHeightOverScan = ((usIVHeight - ScalerVgipGetCaptureVHeight()) / 2);
            }
        }
#endif

        if(usIVHeight <= ScalerVgipGetCaptureVHeight())
        {
            usDeltaIVHeightUnderScan = ((ScalerVgipGetCaptureVHeight() - usIVHeight) / 2);
        }

        usVBias = ((GET_INPUT_TIMING_VSTART() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgipGetCaptureVStartPosition()) < (_MAX_V_POSITION_RANGE / 2)) ?
                  (GET_INPUT_TIMING_VSTART() + usDeltaIVHeightOverScan - usDeltaIVHeightUnderScan - ScalerVgipGetCaptureVStartPosition()) : (_MAX_V_POSITION_RANGE / 2);

        return usVBias;
    }
}

//--------------------------------------------------
// Description  : Adjust picture position.
// Input Value  : ucUserHPosition --> Current percentage of H position associate to OSD bar
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustHPosition(BYTE ucUserHPosition)
{
    WORD usTargetIHStart = 0;
    WORD usHPositionRangeMax = 0;
    WORD usHPositionRangeMin = 0;
    SWORD shHDelay = 0;

    // Disable Wach dog
    ScalerGlobalWatchDog(_DISABLE);

    usHPositionRangeMax = UserCommonAdjustGetHPositionRange(_GET_HPOSITIONRANGE_MAX);
    usHPositionRangeMin = UserCommonAdjustGetHPositionRange(_GET_HPOSITIONRANGE_MIN);

    usTargetIHStart = UserCommonAdjustPercentToRealValue((100 - ucUserHPosition), usHPositionRangeMax, usHPositionRangeMin, (((usHPositionRangeMax - usHPositionRangeMin) / 2) + usHPositionRangeMin));

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        shHDelay = (SWORD)usTargetIHStart - (SWORD)ScalerVgaTopGetCaptureHStartPosition();

        if((ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR422) || (ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420))
        {
            shHDelay += ((shHDelay - ScalerVgaTopGetCaptureHDelay()) % 2);
        }

        // Can't set IH delay to 0 by HW limit
        shHDelay = (shHDelay < 1) ? 1 : shHDelay;

        // Compensate IHS delay
        ScalerVgaTopSetCaptureHDelay(shHDelay);

        // Apply the above setting by setting Double Buffer Ready in VGIP
        ScalerVgaTopDoubleBufferApply();
    }
    else
#endif
    {
        if(ScalerVgipGetDigitalCaptureStatus() == _FALSE)
        {
            shHDelay = (SWORD)usTargetIHStart - (SWORD)ScalerVgipGetCaptureHStartPosition();

            if((ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR422) || (ScalerColorGetColorSpace() == _COLOR_SPACE_YCBCR420))
            {
                shHDelay += ((shHDelay - ScalerVgipGetCaptureHDelay()) % 2);
            }

            // Can't set IH delay to 0 by HW limit
            shHDelay = (shHDelay < 1) ? 1 : shHDelay;

            // Compensate IHS delay
            ScalerVgipSetCaptureHDelay(shHDelay);

            // Apply the above setting by setting Double Buffer Ready in VGIP
            ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);
        }
    }

    // Enable Wach dog
    ScalerGlobalWatchDog(_ENABLE);
}

//--------------------------------------------------
// Description  : Adjust picture position.
// Input Value  : ucUserVPosition --> Current percentage of V position associate to OSD bar
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustVPosition(BYTE ucUserVPosition)
{
    WORD usTargetIVStart = 0;
    WORD usVDelayAdjustDeltaLimit = 0;
    WORD usVPositionRangeMax = 0;
    WORD usVPositionRangeMin = 0;
    SWORD shVDelay = 0;
    BYTE ucTimeoutCounter = 0;

    ScalerGlobalWatchDog(_DISABLE);

    usVPositionRangeMax = UserCommonAdjustGetVPositionRange(_GET_VPOSITIONRANGE_MAX);
    usVPositionRangeMin = UserCommonAdjustGetVPositionRange(_GET_VPOSITIONRANGE_MIN);

    usTargetIVStart = UserCommonAdjustPercentToRealValue(ucUserVPosition, usVPositionRangeMax, usVPositionRangeMin, (((usVPositionRangeMax - usVPositionRangeMin) / 2) + usVPositionRangeMin));

#if(_VGA_SUPPORT == _ON)
    if(SysSourceGetSourceType() == _SOURCE_VGA)
    {
        shVDelay = (SWORD)usTargetIVStart - (SWORD)ScalerVgaTopGetCaptureVStartPosition();

        shVDelay = (shVDelay < 0) ? 0 : shVDelay;

        // Get current V adjust limit
        usVDelayAdjustDeltaLimit = ScalerMDomainGetVerticalAdjustLimit(_SOURCE_VGA);

        ucTimeoutCounter = (abs(shVDelay - ScalerVgaTopGetCaptureVDelay()) / usVDelayAdjustDeltaLimit) + 1;

        do
        {
            if(shVDelay > ScalerVgaTopGetCaptureVDelay())
            {
                ScalerVgaTopSetCaptureVDelay(shVDelay);
            }
            else
            {
                if((ScalerVgaTopGetCaptureVDelay() - shVDelay) <= usVDelayAdjustDeltaLimit)
                {
                    ScalerVgaTopSetCaptureVDelay(shVDelay);
                }
                else
                {
                    ScalerVgaTopSetCaptureVDelay(ScalerVgaTopGetCaptureVDelay() - usVDelayAdjustDeltaLimit);
                }
            }

            ScalerVgaTopDoubleBufferApply();

            ucTimeoutCounter--;
        }
        while((shVDelay != ScalerVgaTopGetCaptureVDelay()) && (ucTimeoutCounter > 0));

        // VGA Top capture adjust need wait one full ivs time
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);

        ScalerGlobalWatchDog(_ENABLE);
    }
    else
#endif
    {
        if(ScalerVgipGetDigitalCaptureStatus() == _FALSE)
        {
            shVDelay = (SWORD)usTargetIVStart - (SWORD)ScalerVgipGetCaptureVStartPosition();

            shVDelay = (shVDelay < 0) ? 0 : shVDelay;

            // Get current V adjust limit
            usVDelayAdjustDeltaLimit = ScalerMDomainGetVerticalAdjustLimit(SysSourceGetSourceType());

            ucTimeoutCounter = (abs(shVDelay - ScalerVgipGetCaptureVDelay()) / usVDelayAdjustDeltaLimit) + 1;

            do
            {
                if(shVDelay > ScalerVgipGetCaptureVDelay())
                {
                    ScalerVgipSetCaptureVDelay(shVDelay);
                }
                else
                {
                    if((ScalerVgipGetCaptureVDelay() - shVDelay) <= usVDelayAdjustDeltaLimit)
                    {
                        ScalerVgipSetCaptureVDelay(shVDelay);
                    }
                    else
                    {
                        ScalerVgipSetCaptureVDelay(ScalerVgipGetCaptureVDelay() - usVDelayAdjustDeltaLimit);
                    }
                }

                ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);

                ucTimeoutCounter--;
            }
            while((shVDelay != ScalerVgipGetCaptureVDelay()) && (ucTimeoutCounter > 0));

            ScalerTimerWaitForEvent(_EVENT_IVS);
            ScalerGlobalWatchDog(_ENABLE);
        }
    }
}
#endif // End of #if(_TRANSLATOR_SUPPORT == _OFF)

//--------------------------------------------------
// Description  :  Calculate value to percent for input range for 2 Sectors
// Input Value  :  usRealValue --> input real value
//                 usMax       --> the max value
//                 usMin       --> the min value
//                 usCenter    --> the Center Value
// Output Value :  Percent
//--------------------------------------------------
BYTE UserCommonAdjustRealValueToPercent(WORD usRealValue, WORD usMax, WORD usMin, WORD usCenter)
{
    WORD usTemp = 0;
    usRealValue = MINOF(usRealValue, usMax);
    usRealValue = MAXOF(usRealValue, usMin);

    if((usMax <= usMin) || (usCenter <= usMin) || (usCenter >= usMax))
    {
        usTemp = 0;
    }
    else
    {
        if(usRealValue < usCenter)
        {
            usTemp = (((DWORD)(usRealValue - usMin) * 10000) / (usCenter - usMin)) / 2;
        }
        else if(usRealValue > usCenter)
        {
            usTemp = (((DWORD)(usRealValue - usCenter) * 10000) / (usMax - usCenter)) / 2 + 5000;
        }
        else
        {
            return 50;
        }
    }

    if((usTemp % 100) > 49)
    {
        usTemp = usTemp + 100;
    }

    usTemp = usTemp / 100;

    return ((BYTE)usTemp);
}

//--------------------------------------------------
// Description  :  Calculate percent to real value for input range for 2 Sectors
// Input Value  :  ucPercentValue --> input percent value
//                 usMax          --> the max value
//                 usMin          --> the min value
//                 usCenter       --> the Center Value
// Output Value :  Real value
//--------------------------------------------------
WORD UserCommonAdjustPercentToRealValue(BYTE ucPercentValue, WORD usMax, WORD usMin, WORD usCenter)
{
    DWORD ulTemp = 0;

    ucPercentValue = MINOF(100, ucPercentValue);

    if(ucPercentValue > 50)
    {
        ulTemp = (((DWORD)(ucPercentValue - 50) * (usMax - usCenter) * 10) / 50);
    }
    else if(ucPercentValue < 50)
    {
        ulTemp = (((DWORD)ucPercentValue * (usCenter - usMin) * 10) / 50);
    }
    else
    {
        return usCenter;
    }

    if((ulTemp % 10) > 5)
    {
        ulTemp = ulTemp + 10;
    }

    if(ucPercentValue > 50)
    {
        return (WORD)((ulTemp / 10) + usCenter);
    }
    else
    {
        return (WORD)((ulTemp / 10) + usMin); // <= 50
    }
}

#if(_OVERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Overscan
// Input Value  : Current Input Timing
// Output Value : Modified Input Timing
//--------------------------------------------------
void UserCommonAdjustOverScan(void)
{
    BYTE ucDelta = 0;

    if(UserInterfaceGetOverScanStatus() == _FALSE)
    {
        return;
    }

    // Modify Over Scanned H
    ucDelta = (BYTE)((DWORD)GET_MDOMAIN_INPUT_HWIDTH() * _OVERSCAN_H_RATIO / 1000);

    // Let Adjusted Value be 2's multiple
    ucDelta += ucDelta % 2;

    SET_MDOMAIN_INPUT_HSTART(GET_MDOMAIN_INPUT_HSTART() + ucDelta);
    SET_MDOMAIN_INPUT_HWIDTH(GET_MDOMAIN_INPUT_HWIDTH() - 2 * ucDelta);

    // Modify Over Scanned V
    ucDelta = (BYTE)((DWORD)GET_MDOMAIN_INPUT_VHEIGHT() * _OVERSCAN_V_RATIO / 1000);

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
    if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
    {
        // Let Adjusted Value be 2's multiple under E/O mode
        ucDelta += ucDelta % 2;
    }
#endif

    SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSTART() + ucDelta);
    SET_MDOMAIN_INPUT_VHEIGHT(GET_MDOMAIN_INPUT_VHEIGHT() - 2 * ucDelta);
}
#endif  // End of #if(_OVERSCAN_SUPPORT == _ON)

#if(_UNDERSCAN_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Timing For Underscan
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustUnderScan(void)
{
    if(UserInterfaceAdjustUnderScan() == _FALSE)
    {
        return;
    }

    if(GET_MDOMAIN_INPUT_VHEIGHT() < GET_UNDERSCAN_VHEIGHT())
    {
        // Adjust M-domain Vstart for underscan; Default center-positioned
        WORD usVdiff = (GET_UNDERSCAN_VHEIGHT() - GET_MDOMAIN_INPUT_VHEIGHT()) / 2;

        if(GET_MDOMAIN_INPUT_VSTART() > (usVdiff + ScalerIDomainVgipGetVCaptureStartMinValue()))
        {
            SET_MDOMAIN_INPUT_VSTART(GET_MDOMAIN_INPUT_VSTART() - usVdiff);
        }
        else
        {
            SET_MDOMAIN_INPUT_VSTART(ScalerIDomainVgipGetVCaptureStartMinValue());
        }

        SET_MDOMAIN_INPUT_VHEIGHT(GET_UNDERSCAN_VHEIGHT());
    }
}
#endif

#if(_ASPECT_RATIO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Modify Display Timing For Aspect Ratio
// Input Value  : void
// Output Value : void
//--------------------------------------------------
void UserCommonAdjustAspectRatio(void)
{
    WORD usHRatio = 0x0000;
    WORD usVRatio = 0x0000;

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    // No aspect ratio allowed in rotation 90/270
    if((ScalerRotationCheckStatus() == _TRUE) &&
       ((GET_ROT_TYPE() == _ROT_CW90) || (GET_ROT_TYPE() == _ROT_CW270)))
    {
        return;
    }
#endif
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
    SET_ASPECT_RATIO_MIN_DVH(0);
#endif

    switch(UserInterfaceGetAspectRatioType())
    {
        case _ASPECT_RATIO_FULL:
        default:

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
            ScalerMDomainAspectOriginMode(_FALSE);
#endif
            break;

        case _ASPECT_RATIO_FIXED:

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
            ScalerMDomainAspectOriginMode(_FALSE);
#endif

            UserInterfaceGetAspectRatio(&usHRatio, &usVRatio);

            // Calculate H Width
            PDATA_WORD(0) = (DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * usHRatio / usVRatio;

            // H Width Should be 4x
            PDATA_WORD(0) &= 0xFFFC;

            if(PDATA_WORD(0) > GET_MDOMAIN_OUTPUT_HWIDTH())
            {
                // Calculate V Height
                PDATA_WORD(0) = (DWORD)GET_MDOMAIN_OUTPUT_HWIDTH() * usVRatio / usHRatio;

                // V Height Should be 4x
                PDATA_WORD(0) &= 0xFFFC;

                // Set V Start, V Height
                SET_MDOMAIN_OUTPUT_VSTART(GET_MDOMAIN_OUTPUT_VSTART() + ((GET_MDOMAIN_OUTPUT_VHEIGHT() - PDATA_WORD(0)) / 2));
                SET_MDOMAIN_OUTPUT_VHEIGHT(PDATA_WORD(0));
            }
            else if(PDATA_WORD(0) < GET_MDOMAIN_OUTPUT_HWIDTH())
            {
                // Calculate H Start
                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_HSTART() + ((GET_MDOMAIN_OUTPUT_HWIDTH() - PDATA_WORD(0)) / 2);

                // Set H Start, H Width
                SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(1));
                SET_MDOMAIN_OUTPUT_HWIDTH(PDATA_WORD(0));
            }

            break;

        case _ASPECT_RATIO_USER:

            // User defined adjust aspect ratio
            UserInterfaceAdjustAspectRatio();
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
            SET_ASPECT_RATIO_MIN_DVH(UserInterfaceGetAspectRatioMinDVHeight());
#endif
            break;

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
        case _ASPECT_RATIO_ORIGIN:

            ScalerMDomainAspectOriginMode(_TRUE);

            // Consider Panel Height and Input Height
            if(GET_MDOMAIN_OUTPUT_VHEIGHT() > GET_MDOMAIN_INPUT_VHEIGHT())
            {
                // Double V height for interlaced timing
                if((GET_MDOMAIN_INPUT_INTERLACE_FLG() == _TRUE) &&
                   (GET_MDOMAIN_INPUT_HWIDTH() > (GET_MDOMAIN_INPUT_VHEIGHT() << 1)))
                {
                    // Check if output V height > (input V height x 2)
                    if(GET_MDOMAIN_OUTPUT_VHEIGHT() > (GET_MDOMAIN_INPUT_VHEIGHT() << 1))
                    {
                        PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_VHEIGHT() - (GET_MDOMAIN_INPUT_VHEIGHT() << 1);
                        SET_MDOMAIN_OUTPUT_VHEIGHT(GET_MDOMAIN_INPUT_VHEIGHT() << 1);
                    }
                    else
                    {
                        // Output V height unchanged
                        PDATA_WORD(0) = 0x00;
                    }
                }
                else
                {
                    PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_VHEIGHT() - GET_MDOMAIN_INPUT_VHEIGHT();
                    SET_MDOMAIN_OUTPUT_VHEIGHT(GET_MDOMAIN_INPUT_VHEIGHT());
                }

                PDATA_WORD(0) &= 0xFFFC; // V start should be even
                SET_MDOMAIN_OUTPUT_VSTART(GET_MDOMAIN_OUTPUT_VSTART() + (PDATA_WORD(0) / 2));
            }
            else
            {
                usHRatio = 0x01;
            }

            // Consider Panel Width and Input Width
            if(GET_MDOMAIN_OUTPUT_HWIDTH() > GET_MDOMAIN_INPUT_HWIDTH())
            {
                PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_HWIDTH() - GET_MDOMAIN_INPUT_HWIDTH();
                PDATA_WORD(0) &= 0xFFFC; // H start should be even
                SET_MDOMAIN_OUTPUT_HSTART(GET_MDOMAIN_OUTPUT_HSTART() + (PDATA_WORD(0) / 2));
                SET_MDOMAIN_OUTPUT_HWIDTH(GET_MDOMAIN_INPUT_HWIDTH());
            }
            else
            {
                usVRatio = 0x01;
            }

            if((usHRatio != 1) || (usVRatio != 1))
            {
                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_VSTART() - ((DWORD)GET_MDOMAIN_OUTPUT_VSTART() * UserInterfaceGetAspectRatioOriginalRatio() / 0xFF);
                PDATA_WORD(1) &= 0xFFFE; // V start should be even

                SET_MDOMAIN_OUTPUT_VSTART(GET_MDOMAIN_OUTPUT_VSTART() - PDATA_WORD(1));
                SET_MDOMAIN_OUTPUT_VHEIGHT(GET_MDOMAIN_OUTPUT_VHEIGHT() + PDATA_WORD(1) * 2);

                PDATA_WORD(1) = GET_MDOMAIN_OUTPUT_HSTART() - ((DWORD)GET_MDOMAIN_OUTPUT_HSTART() * UserInterfaceGetAspectRatioOriginalRatio() / 0xFF);
                PDATA_WORD(1) &= 0xFFFE; // H start should be even

                SET_MDOMAIN_OUTPUT_HSTART(GET_MDOMAIN_OUTPUT_HSTART() - PDATA_WORD(1));
                SET_MDOMAIN_OUTPUT_HWIDTH(GET_MDOMAIN_OUTPUT_HWIDTH() + PDATA_WORD(1) * 2);
            }

            break;
#endif // End of #if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
    }
}
#endif // End of #if(_ASPECT_RATIO_SUPPORT == _ON)

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Adjust input size for rotation
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustRotationInputSize(void)
{
    if((ScalerRotationCheckStatus() == _FALSE) ||
       ((GET_ROT_TYPE() != _ROT_CW90) && (GET_ROT_TYPE() != _ROT_CW270)))
    {
        return;
    }

    switch(GET_ROT_DISP_SIZE())
    {
        default:
            break;

        case _ROT_PIXEL_BY_PIXEL:
            // Calculate / Set V
            if(_PANEL_DH_WIDTH < GET_INPUT_TIMING_VHEIGHT())
            {
                PDATA_WORD(0) = ((GET_INPUT_TIMING_VHEIGHT() - _PANEL_DH_WIDTH) / 2);
                PDATA_WORD(0) += GET_INPUT_TIMING_VSTART();

                // VStart / VHeight
                SET_MDOMAIN_INPUT_VSTART(PDATA_WORD(0));
                SET_MDOMAIN_INPUT_VHEIGHT(_PANEL_DH_WIDTH);
            }

            // Calculate / Set H
            if(_PANEL_DV_HEIGHT < GET_INPUT_TIMING_HWIDTH())
            {
                PDATA_WORD(0) = (GET_INPUT_TIMING_HWIDTH() - _PANEL_DV_HEIGHT);
                PDATA_WORD(0) += GET_INPUT_TIMING_HSTART();
                PDATA_WORD(0) += (PDATA_WORD(0) % 2);

                // HStart / HWidth
                SET_MDOMAIN_INPUT_HSTART(PDATA_WORD(0));
                SET_MDOMAIN_INPUT_HWIDTH(_PANEL_DV_HEIGHT);
            }

            break;
    }
}

//--------------------------------------------------
// Description  : Adjust display size for rotation
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustRotationDisplaySize(void)
{
    if((ScalerRotationCheckStatus() == _FALSE) ||
       ((GET_ROT_TYPE() != _ROT_CW90) && (GET_ROT_TYPE() != _ROT_CW270)))
    {
        return;
    }

    switch(GET_ROT_DISP_SIZE())
    {
        default:
        case _ROT_FULL:

            // Set Size
            SET_MDOMAIN_OUTPUT_HSTART(_PANEL_DH_START);
            SET_MDOMAIN_OUTPUT_HWIDTH(_PANEL_DH_WIDTH);
            SET_MDOMAIN_OUTPUT_VSTART(_PANEL_DV_START);
            SET_MDOMAIN_OUTPUT_VHEIGHT(_PANEL_DV_HEIGHT);

            break;

        case _ROT_PIXEL_BY_PIXEL:

            PDATA_WORD(0) = _PANEL_DH_START;
            PDATA_WORD(1) = _PANEL_DH_WIDTH;
            PDATA_WORD(2) = _PANEL_DV_START;
            PDATA_WORD(3) = _PANEL_DV_HEIGHT;

            // Calculate / Set Display Window H
            if(_PANEL_DH_WIDTH > GET_MDOMAIN_INPUT_VHEIGHT())
            {
                // Underscan
                PDATA_WORD(0) += ((_PANEL_DH_WIDTH - GET_MDOMAIN_INPUT_VHEIGHT()) / 2);
                PDATA_WORD(0) += (PDATA_WORD(0) % 2);
                PDATA_WORD(1) = GET_INPUT_TIMING_VHEIGHT();
            }

            // Calculate / Set Display Window V Start
            if(_PANEL_DV_HEIGHT > GET_MDOMAIN_INPUT_HWIDTH())
            {
                // Underscan
                PDATA_WORD(2) += ((_PANEL_DV_HEIGHT - GET_MDOMAIN_INPUT_HWIDTH()) / 2);
                PDATA_WORD(3) = GET_MDOMAIN_INPUT_HWIDTH();
            }

            // Set Display Window H Start/Width
            SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(0));
            SET_MDOMAIN_OUTPUT_HWIDTH(PDATA_WORD(1));

            // Set Display Window V Start/Height
            SET_MDOMAIN_OUTPUT_VSTART(PDATA_WORD(2));
            SET_MDOMAIN_OUTPUT_VHEIGHT(PDATA_WORD(3));

            break;

        case _ROT_KEEP_SRC_ASPECT_RATIO:

            // Double V height for interlaced timing
            if((GET_MDOMAIN_INPUT_INTERLACE_FLG() == _TRUE) &&
               (GET_MDOMAIN_INPUT_VHEIGHT() < (GET_MDOMAIN_INPUT_HWIDTH() / 2)))
            {
                PDATA_WORD(1) = GET_MDOMAIN_INPUT_VHEIGHT() * 2;
            }
            else
            {
                PDATA_WORD(1) = GET_MDOMAIN_INPUT_VHEIGHT();
            }

            // Calculate VHeight
            PDATA_WORD(0) = ((DWORD)_PANEL_DH_WIDTH * GET_MDOMAIN_INPUT_HWIDTH()) / PDATA_WORD(1);

            if(PDATA_WORD(0) > _PANEL_DV_HEIGHT)
            {
                // Calculate HWidth
                PDATA_WORD(0) = ((DWORD)_PANEL_DV_HEIGHT * PDATA_WORD(1)) / GET_MDOMAIN_INPUT_HWIDTH();

                // Set HWidth / VHeight
                PDATA_WORD(0) += (PDATA_WORD(0) % 2);
                SET_MDOMAIN_OUTPUT_HWIDTH(PDATA_WORD(0));
                SET_MDOMAIN_OUTPUT_VHEIGHT(_PANEL_DV_HEIGHT);

                // HStart / VStart
                PDATA_WORD(0) = (_PANEL_DH_START + (_PANEL_DH_WIDTH - PDATA_WORD(0)) / 2);
                PDATA_WORD(0) += (PDATA_WORD(0) % 2);
                SET_MDOMAIN_OUTPUT_HSTART(PDATA_WORD(0));
                SET_MDOMAIN_OUTPUT_VSTART(_PANEL_DV_START);
            }
            else
            {
                // HWidth / VHeight
                SET_MDOMAIN_OUTPUT_HWIDTH(_PANEL_DH_WIDTH);
                SET_MDOMAIN_OUTPUT_VHEIGHT(PDATA_WORD(0));

                // HStart / VStart
                SET_MDOMAIN_OUTPUT_HSTART(_PANEL_DH_START);
                SET_MDOMAIN_OUTPUT_VSTART((_PANEL_DV_START + (_PANEL_DV_HEIGHT - PDATA_WORD(0)) / 2));
            }

            break;
    }
}
#endif  // #if(_DISPLAY_ROTATION_SUPPORT == _ON)

#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set IDither Table
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustIDither(void)
{
#if(_IDITHER_TYPE == _IDITHER_GEN_2_1_SEQ_NO_TEMPO_TRUNCATE_2_0_BIT)
    BYTE code *pucTempoTable = _NULL_POINTER;
#else
    BYTE code *pucTempoTable = tIDITHER_TEMPOFFSET_TABLE;
#endif

#if(_IDITHER_TYPE == _IDITHER_GEN_1_4_SEQ_TRUNCATE_4_2_BIT)
    ScalerColorSetScalingDownMaskLSB();
#endif

    if(ScalerMDomainGetColorDepth() == _COLOR_DEPTH_8_BITS)
    {
        ScalerColorIDitherAdjust(tIDITHER_TABLE_FIFO8, tIDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
    }
    else if(ScalerMDomainGetColorDepth() == _COLOR_DEPTH_10_BITS)
    {
        ScalerColorIDitherAdjust(tIDITHER_TABLE_FIFO10, tIDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
    }
#if(_IDITHER_TYPE == _IDITHER_GEN_3_4_SEQ_TRUNCATE_6_4_2_BIT)
    else if(ScalerMDomainGetColorDepth() == _COLOR_DEPTH_6_BITS)
    {
        ScalerColorIDitherAdjust(tIDITHER_TABLE_FIFO8, tIDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
    }
#endif
}
#endif // End of #if(_I_DITHER_SUPPORT == _ON)

#if(_ULTRA_VIVID_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set UltraVivid Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustUltraVivid(EnumFunctionOnOFF enumFunctionOnOFF, EnumColorSpace enumColorFormat, EnumDBApply enumDBApply)
{
    if(enumFunctionOnOFF == _FUNCTION_ON)
    {
        if(ScalerColorUltraVividSetDisable() == _TRUE)
        {
#if(_YPEAKING_SUPPORT == _ON)
            UserInterfaceAdjustYpeaking();
#endif
            ScalerColorUltraVividEnable(_FUNCTION_OFF, _DB_APPLY_NONE);
        }
        else
        {
#if(_YPEAKING_SUPPORT == _ON)
            ScalerColorYpeaking(_OFF);
#endif
            UserInterfaceAdjustUltraVivid();
        }
    }
    else
    {
#if(_YPEAKING_SUPPORT == _ON)
        ScalerColorYpeaking(_OFF);
#endif
        ScalerColorUltraVividEnable(_FUNCTION_OFF, _DB_APPLY_NONE);
    }

    SysModeColorSpaceConvert(enumColorFormat, enumDBApply);
}
#endif  // End of #if(_ULTRA_VIVID_SUPPORT == _ON)

#if(_D_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set DDither Table
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustDDither(void)
{
#if(_DDITHER_TYPE == _DDITHER_GEN_2_4_SEQ_NO_TEMPO_4BIT_DITHERTBL)
    BYTE code *pucTempoTable = _NULL_POINTER;
#else
    BYTE code *pucTempoTable = tDDITHER_TEMPOFFSET_TABLE;
#endif

#if(_PANEL_EXIST_MULTIPANEL == _OFF)
    ScalerColorDDitherAdjust(tDDITHER_TABLE, tDDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
#else
    switch(_PANEL_DISP_BIT_MODE)
    {
        case _PANEL_DISP_18_BIT:
#if(_DDITHER_TYPE == _DDITHER_GEN_1_6BIT_DITHERTBL)
            ScalerColorDDitherAdjust(_NULL_POINTER, tDDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
#else
            ScalerColorDDitherAdjust(tDDITHER_TABLE18Bit, tDDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
#endif
            break;

        case _PANEL_DISP_24_BIT:
            ScalerColorDDitherAdjust(tDDITHER_TABLE24Bit, tDDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
            break;

        case _PANEL_DISP_30_BIT:
        default:
            ScalerColorDDitherAdjust(tDDITHER_TABLE30Bit, tDDITHER_SEQ_TABLE, pucTempoTable, GET_CURRENT_BANK_NUMBER());
            break;
    }
#endif

#if(_D_DITHER_ADVANCE_SETTING_ENABLE == _ENABLE)

#if(_PANEL_EXIST_MULTIPANEL == _OFF)
    ScalerColorDDitherAdvanceSettingAdjust(tDDITHER_REALIGN_TABLE, tDDITHER_REALIGN_TEMPO_TABLE, tDDITHER_LSB_TABLE, tDDITHER_ADVANCE_SETTING_TABLE, GET_CURRENT_BANK_NUMBER());
#else
    switch(_PANEL_DISP_BIT_MODE)
    {
        case _PANEL_DISP_18_BIT:
#if((_DDITHER_TYPE == _DDITHER_GEN_3_6BIT_DITHERTBL_6BIT_PANEL) || (_DDITHER_TYPE == _DDITHER_GEN_4_6BIT_DITHERTBL_6BIT_PANEL_S2))
            ScalerColorDDitherAdvanceSettingAdjust(tDDITHER_REALIGN_TABLE, tDDITHER_REALIGN_TEMPO_TABLE, tDDITHER_LSB_TABLE18Bit, tDDITHER_ADVANCE_SETTING_TABLE18Bit, GET_CURRENT_BANK_NUMBER());
#endif
            break;

        case _PANEL_DISP_24_BIT:
            ScalerColorDDitherAdvanceSettingAdjust(tDDITHER_REALIGN_TABLE, tDDITHER_REALIGN_TEMPO_TABLE, tDDITHER_LSB_TABLE24Bit, tDDITHER_ADVANCE_SETTING_TABLE24Bit, GET_CURRENT_BANK_NUMBER());
            break;

        case _PANEL_DISP_30_BIT:
        default:
            ScalerColorDDitherAdvanceSettingAdjust(tDDITHER_REALIGN_TABLE, tDDITHER_REALIGN_TEMPO_TABLE, tDDITHER_LSB_TABLE30Bit, tDDITHER_ADVANCE_SETTING_TABLE30Bit, GET_CURRENT_BANK_NUMBER());
            break;
    }
#endif

#endif
}
#endif // End of #if(_D_DITHER_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Set 10bit Panel Compesate
// Input Value  : Row Data
// Output Value : Compesate Data
//--------------------------------------------------
WORD UserCommonAdjust10bitPanelCompensate(WORD usData)
{
#if(_TRANSLATOR_SUPPORT == _OFF)
    if(ScalerColorGetColorDepth() == _COLOR_DEPTH_8_BITS)
    {
        usData = (WORD)(((DWORD)usData * 1023 / 1020) > 4095) ? 4095 : (WORD)((DWORD)usData * 1023 / 1020);
    }
#endif

    return usData;
}

#if(_SHARPNESS_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set Sharpness Table
// Input Value  : Request Sharpness Table
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustSharpness(EnumSourceSearchPort enumSourceSearchPort)
{
    switch(ScalerScalingGetScalingUpType())
    {
        case _VSU_2D_4LINE_COEF:

            // 1:1 Mode Use Different Scaling Table
            if((ScalerColorScalingByPassTableSel() == _TRUE) || (UserInterfaceSharpnessBypassCheck() == _TRUE))
            {
                ScalerMemorySetScalingCoef(UserInterfaceGetSharpnessCoef(_H_SU_128TAPS_1_TO_1, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoef(_H_V_SU_128TAPS_NORMAL, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoefBankNum());
            }
            else
            {
                ScalerMemorySetScalingCoef(UserInterfaceGetSharpnessCoef(_H_V_SU_128TAPS_NORMAL, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoef(_H_V_SU_128TAPS_NORMAL, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoefBankNum());
            }

            break;

#if(_VSU_3L_SUPPORT == _ON)
        case _VSU_2D_3LINE_COEF:

            // 1:1 Mode Use Different Scaling Table
            if((ScalerColorScalingByPassTableSel() == _TRUE) || (UserInterfaceSharpnessBypassCheck() == _TRUE))
            {
                ScalerMemorySetScalingCoef(UserInterfaceGetSharpnessCoef(_H_SU_128TAPS_1_TO_1, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoef(_H_V_SU_96TAPS_NORMAL, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoefBankNum());
            }
            else
            {
                ScalerMemorySetScalingCoef(UserInterfaceGetSharpnessCoef(_H_V_SU_128TAPS_NORMAL, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoef(_H_V_SU_96TAPS_NORMAL, enumSourceSearchPort),
                                           UserInterfaceGetSharpnessCoefBankNum());
            }

            break;
#endif

        default:

            break;
    }
}
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Integrate HDR FW Flow
// Input Value  : enumHDRFlowStatus
// Output Value : none
//--------------------------------------------------
void UserCommonAdjustHDR(EnumHDRFlowStatus enumHDRFlowStatus)
{
    EnumHDRTargetStatus enumHDRTargetStatus = _HDR_TARGET_STATUS_DO_NOTHING;

    switch(UserInterfaceGetHDRModeStatus())
    {
        case _HDR_MODE_AUTO:
            if(enumHDRFlowStatus != _HDR_FLOW_OSD_DARK_ENHANCE)
            {
                if(enumHDRFlowStatus == _HDR_FLOW_MODE_STATUS_ACTIVE)
                {
                    enumHDRTargetStatus = UserCommonAdjustHDRTargetStatus(SysSourceGetInputPort());
                }
                else if(enumHDRFlowStatus == _HDR_FLOW_OSD_MODE_CHANGE)
                {
#if(_ULTRA_VIVID_SUPPORT == _ON)
                    UserCommonAdjustUltraVivid(_FUNCTION_ON, ScalerColorGetColorSpace(), _DB_APPLY_NO_POLLING);
#endif
                    enumHDRTargetStatus = UserCommonAdjustHDRAutoModeInitial(SysSourceGetInputPort());
                }

                switch(enumHDRTargetStatus)
                {
                    case _HDR_TARGET_STATUS_SMPTE_ST_2084:

                        UserCommonAdjustHDRAutoMode(UserInterfaceGetHDRDarkEnhanceStatus());
                        UserInterfaceAdjustHDRTargetHDR();
                        break;

                    case _HDR_TARGET_STATUS_TRADITIONAL_GAMMA_SDR:
                        UserInterfaceAdjustHDRTargetSDR();
                        break;

                    case _HDR_TARGET_STATUS_DO_NOTHING:
                    default:
                        break;
                }
            }
            else
            {
                if(GET_HDR_EOTF() == _HDR_INFO_EOTF_SMPTE_ST_2084)
                {
                    UserCommonAdjustHDRAutoMode(UserInterfaceGetHDRDarkEnhanceStatus());
                }
            }
            break;

        case _HDR_MODE_SMPTE_ST_2084:
            if(enumHDRFlowStatus == _HDR_FLOW_OSD_MODE_CHANGE)
            {
#if(_ULTRA_VIVID_SUPPORT == _ON)
                UserCommonAdjustUltraVivid(_FUNCTION_ON, ScalerColorGetColorSpace(), _DB_APPLY_NO_POLLING);
#endif
                UserInterfaceAdjustHDR2084();
                UserInterfaceAdjustHDRTargetHDR();
            }
            else if(enumHDRFlowStatus == _HDR_FLOW_OSD_DARK_ENHANCE)
            {
                UserInterfaceAdjustHDR2084();
            }
            break;

        case _HDR_MODE_OFF:
            if(enumHDRFlowStatus == _HDR_FLOW_OSD_MODE_CHANGE)
            {
#if(_ULTRA_VIVID_SUPPORT == _ON)
                UserCommonAdjustUltraVivid(_FUNCTION_ON, ScalerColorGetColorSpace(), _DB_APPLY_NO_POLLING);
#endif
                UserInterfaceAdjustHDRTargetSDR();
            }
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Check HDR change status according to EOTF, (primaries color), max mastering luminance
// Input Value  : EnumSourceSearchPort
// Output Value : HDR chagne status
//--------------------------------------------------
EnumHDRChangeStatus UserCommonAdjustHDRChangeStatus(EnumSourceSearchPort enumSourceSearchPort)
{
    StructHDRStaticMetaData stHDRInfoData;
    memset(&stHDRInfoData, 0, sizeof(stHDRInfoData));
    ScalerSyncHDRGetCurrentStatus(&stHDRInfoData, enumSourceSearchPort);

    if(stHDRInfoData.usMaxDisplayMasteringLv != GET_HDR_MAX_DISPLAY_MASTERING_LV())
    {
        SET_HDR_INFO_DATA(stHDRInfoData);
        return _HDR_INFO_MAX_LV_CHANGE;
    }
    else if(stHDRInfoData.ucEOTF != GET_HDR_EOTF())
    {
        SET_HDR_INFO_DATA(stHDRInfoData);
        return _HDR_INFO_EOTF_CHANGE;
    }

    return _HDR_INFO_NO_CHANGE;
}

//--------------------------------------------------
// Description  : Check HDR target status to set HDR 2084, SDR or do nothing
// Input Value  : EnumSourceSearchPort
// Output Value : HDR target status
//--------------------------------------------------
EnumHDRTargetStatus UserCommonAdjustHDRTargetStatus(EnumSourceSearchPort enumSourceSearchPort)
{
    // Check if DCC data ready
    if(ScalerColorDCCGetDataReadyStatus() == _TRUE)
    {
        // Clear DCC data ready status.
        ScalerColorDCCClrDataReadyStatus();

        if(UserCommonAdjustHDRChangeStatus(enumSourceSearchPort) != _HDR_INFO_NO_CHANGE)
        {
            DebugMessageHDR("HDRCheckStatus EOTF", GET_HDR_EOTF());

            DebugMessageHDR("HDRCheckStatus X0", GET_HDR_DISPALY_PRIMARIES_X0());
            DebugMessageHDR("HDRCheckStatus Y0", GET_HDR_DISPALY_PRIMARIES_Y0());

            DebugMessageHDR("HDRCheckStatus X1", GET_HDR_DISPALY_PRIMARIES_X1());
            DebugMessageHDR("HDRCheckStatus Y1", GET_HDR_DISPALY_PRIMARIES_Y1());

            DebugMessageHDR("HDRCheckStatus X2", GET_HDR_DISPALY_PRIMARIES_X2());
            DebugMessageHDR("HDRCheckStatus Y2", GET_HDR_DISPALY_PRIMARIES_Y2());

            DebugMessageHDR("HDRCheckStatus Wx", GET_HDR_WHITE_POINT_X());
            DebugMessageHDR("HDRCheckStatus Wy", GET_HDR_WHITE_POINT_Y());

            DebugMessageHDR("HDRCheckStatus Mastering Lv", GET_HDR_MAX_DISPLAY_MASTERING_LV());

            if(GET_HDR_EOTF() == _HDR_INFO_EOTF_SMPTE_ST_2084) // HDR SMPTE ST 2084
            {
                DebugMessageHDR("HDR Target Status HDR2084", 0x00);
                return _HDR_TARGET_STATUS_SMPTE_ST_2084;
            }
            else // SDR Traditional gamma
            {
                DebugMessageHDR("HDR Target Status SDR", 0x00);
                return _HDR_TARGET_STATUS_TRADITIONAL_GAMMA_SDR;
            }
        }
    }
    return _HDR_TARGET_STATUS_DO_NOTHING;
}

//--------------------------------------------------
// Description  : Initial HDR metadata and setting HDR or PCM
// Input Value  : EnumSourceSearchPort
// Output Value : HDR target status
//--------------------------------------------------
EnumHDRTargetStatus UserCommonAdjustHDRAutoModeInitial(EnumSourceSearchPort enumSourceSearchPort)
{
    StructHDRStaticMetaData stHDRInfoData;
    memset(&stHDRInfoData, 0, sizeof(stHDRInfoData));
    ScalerSyncHDRGetCurrentStatus(&stHDRInfoData, enumSourceSearchPort);

    SET_HDR_INFO_DATA(stHDRInfoData);

    if(GET_HDR_EOTF() == _HDR_INFO_EOTF_SMPTE_ST_2084) // HDR SMPTE ST 2084
    {
        DebugMessageHDR("HDR Target Status HDR2084", 0x00);
        return _HDR_TARGET_STATUS_SMPTE_ST_2084;
    }
    else // SDR Traditional gamma
    {
        DebugMessageHDR("HDR Target Status SDR", 0x00);
        return _HDR_TARGET_STATUS_TRADITIONAL_GAMMA_SDR;
    }
}

//--------------------------------------------------
// Description  : Return HDR Max Mastering Lv Type by infoframe mastering Lv
// Input Value  : none
// Output Value : HDR max mastering Lv type
//--------------------------------------------------
EnumHDRMaxMasteringLvType UserCommonAdjustHDRGetLvType(void)
{
    if(GET_HDR_MAX_DISPLAY_MASTERING_LV() > _HDR_MAX_MASTERING_LV_4000)
    {
        return _HDR_MAX_MASTERING_LV_TYPE_10000;
    }
    else if(GET_HDR_MAX_DISPLAY_MASTERING_LV() > _HDR_MAX_MASTERING_LV_1200)
    {
        return _HDR_MAX_MASTERING_LV_TYPE_4000;
    }
    else if(GET_HDR_MAX_DISPLAY_MASTERING_LV() > _HDR_MAX_MASTERING_LV_540)
    {
        return _HDR_MAX_MASTERING_LV_TYPE_1200;
    }
    else
    {
        return _HDR_MAX_MASTERING_LV_TYPE_540;
    }
}

//--------------------------------------------------
// Description  : Adjust HDR by SelRegion, HDRMaxMasteringLvType, DarkEnhanceEnable
// Input Value  : DarkEnhanceEnable
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustHDRAutoMode(bit bDarkEnhanceEnable)
{
    WORD usHDRInputGammaFlashAddress = 0x0000;
    WORD usHDRColorMatrixFlashAddress = 0x0000;

    // Input Gamma Setting
    switch(UserCommonAdjustHDRGetLvType())
    {
        case _HDR_MAX_MASTERING_LV_TYPE_1200:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_1200_NOR_ADDRESS;
            DebugMessageHDR("HDR apply type 1200 parameter", 0x00);
            break;

        case _HDR_MAX_MASTERING_LV_TYPE_4000:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_4000_NOR_ADDRESS;
            DebugMessageHDR("HDR apply type 4000 parameter", 0x00);
            break;

        case _HDR_MAX_MASTERING_LV_TYPE_10000:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_10000_NOR_ADDRESS;
            DebugMessageHDR("HDR apply type 10000 parameter", 0x00);
            break;

        case _HDR_MAX_MASTERING_LV_TYPE_540:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_540_NOR_ADDRESS;
            DebugMessageHDR("HDR apply type 540 parameter", 0x00);
            break;

        default:
            usHDRInputGammaFlashAddress = _OGC_HDR_IG_1200_NOR_ADDRESS;
            DebugMessageHDR("HDR apply type 1200 parameter default", 0x00);
            break;
    }

    if(bDarkEnhanceEnable == _ON)
    {
        usHDRInputGammaFlashAddress += _OGC_HDR_IG_TABLE_SIZE;
        DebugMessageHDR("HDR apply Dark Enhance parameter", 0x00);
    }

    // Color Matrix Setting
    switch(ScalerColorGetColorimetry())
    {
        case _COLORIMETRY_RGB_SRGB:
        case _COLORIMETRY_RGB_XRRGB:
        case _COLORIMETRY_RGB_SCRGB:
        case _COLORIMETRY_YCC_SMPTE_170M:
        case _COLORIMETRY_YCC_ITUR_BT601:
        case _COLORIMETRY_YCC_ITUR_BT709:
        case _COLORIMETRY_YCC_XVYCC601:
        case _COLORIMETRY_YCC_XVYCC709:
            usHDRColorMatrixFlashAddress = _OCC_HDR_SRGB_MATRIX_ADDRESS;
            DebugMessageHDR("HDR apply SRGB matrix", 0x00);
            break;

        case _COLORIMETRY_RGB_ADOBERGB:
            usHDRColorMatrixFlashAddress = _OCC_HDR_ADOBE_MATRIX_ADDRESS;
            DebugMessageHDR("HDR apply AdobeRGB matrix", 0x00);
            break;

        case _COLORIMETRY_RGB_DCI_P3:
            usHDRColorMatrixFlashAddress = _OCC_HDR_DCIP3_D65_MATRIX_ADDRESS;
            DebugMessageHDR("HDR apply DCIP3_D65 matrix", 0x00);
            break;


        case _COLORIMETRY_EXT:
            switch(ScalerColorGetExtColorimetry())
            {
                case _COLORIMETRY_EXT_RGB_SRGB:
                case _COLORIMETRY_EXT_RGB_XRRGB:
                case _COLORIMETRY_EXT_RGB_SCRGB:
                case _COLORIMETRY_EXT_YCC_ITUR_BT601:
                case _COLORIMETRY_EXT_YCC_ITUR_BT709:
                case _COLORIMETRY_EXT_YCC_XVYCC601:
                case _COLORIMETRY_EXT_YCC_XVYCC709:
                case _COLORIMETRY_EXT_YCC_SYCC601:
                    usHDRColorMatrixFlashAddress = _OCC_HDR_SRGB_MATRIX_ADDRESS;
                    DebugMessageHDR("HDR apply SRGB matrix EXT", 0x00);
                    break;

                case _COLORIMETRY_EXT_RGB_ADOBERGB:
                case _COLORIMETRY_EXT_YCC_ADOBEYCC601:
                    usHDRColorMatrixFlashAddress = _OCC_HDR_ADOBE_MATRIX_ADDRESS;
                    DebugMessageHDR("HDR apply AdobeRGB matrix EXT", 0x00);
                    break;

                case _COLORIMETRY_EXT_RGB_DCI_P3:
                    usHDRColorMatrixFlashAddress = _OCC_HDR_DCIP3_D65_MATRIX_ADDRESS;
                    DebugMessageHDR("HDR apply DCIP3_D65 matrix EXT", 0x00);
                    break;

#if(_COLOR_CONVERSION_TYPE == _COLOR_CONVERSION_GEN_2)
                case _COLORIMETRY_EXT_RGB_ITUR_BT2020:
                case _COLORIMETRY_EXT_YCC_ITUR_BT2020_CL:
                case _COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL:
                    usHDRColorMatrixFlashAddress = _OCC_HDR_BT2020_MATRIX_ADDRESS;
                    DebugMessageHDR("HDR apply BT2020 matrix", 0x00);
                    break;
#endif

                default:
                    usHDRColorMatrixFlashAddress = _OCC_HDR_BT2020_MATRIX_ADDRESS;
                    DebugMessageHDR("HDR apply BT2020 matrix EXT default", 0x00);
                    break;
            }
            break;

        default:
            usHDRColorMatrixFlashAddress = _OCC_HDR_BT2020_MATRIX_ADDRESS;
            DebugMessageHDR("HDR apply BT2020 matrix default", 0x00);
            break;
    }
	
	ScalerTimerWaitForEvent(_EVENT_IEN_STOP);

	ScalerColorPCMInputGammaEnable(_FUNCTION_OFF);
	ScalerColorPCMInputGammaAdjust(g_pucDISP_CALIBRATION_FLASH + _OGC_HDR_IG_1200_NOR_ADDRESS , _OGC_FLASH_BANK);
	ScalerColorSRGBEnable(_FUNCTION_OFF);
	
	// Set Output Gamma
	ScalerColorOutputGammaEnable(_FUNCTION_OFF);
	
	ScalerColorPCMOutputGammaAdjust(g_pucDISP_CALIBRATION_FLASH + _OCC_HDR_GAMMA10_ADDRESS, _OGC_FLASH_BANK);
	
	// Set Color Matrix
	ScalerColorPCMSRGBAdjust(_SRGB_1_BIT_SHIFT_LEFT, g_pucDISP_CALIBRATION_FLASH + _OCC_HDR_BT2020_MATRIX_ADDRESS , _OGC_FLASH_BANK, _OCC_COLORMATRIX_TABLE_SIZE);
	
	ScalerTimerWaitForEvent(_EVENT_DEN_STOP);
	ScalerColorOutputGammaEnable(_FUNCTION_ON);
	ScalerColorSRGBEnable(_FUNCTION_ON);
	ScalerColorPCMInputGammaEnable(_FUNCTION_ON);
	
	ScalerColorBrightnessEnable(_FUNCTION_OFF);
	ScalerColorContrastEnable(_FUNCTION_OFF);

}

//--------------------------------------------------
// Description  : return applying HDR parameter or PCM parameter
// Input Value  : EnumHDRModeDef
// Output Value : _ON(HDR), _OFF(PCM)
//--------------------------------------------------
bit UserCommonAdjustHDREnableStatus(EnumHDRModeDef enumHDRModeDef)
{
    switch(enumHDRModeDef)
    {
        case _HDR_MODE_OFF:

            return _OFF;

        case _HDR_MODE_AUTO:

            if(GET_HDR_EOTF() == _HDR_INFO_EOTF_SMPTE_ST_2084)
            {
                return _ON;
            }
            else
            {
                return _OFF;
            }

        case _HDR_MODE_SMPTE_ST_2084:

            return _ON;

        default:
            break;
    }
    return _OFF;
}
#endif

#if(_DCR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set DCR setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustDCR(void)
{
    // Check if DCR data ready.
    if(ScalerColorDCRGetDataReadyStatus() == _TRUE)
    {
        // Clear DCR data ready status.
        ScalerColorDCRClrDataReadyStatus();

        // freeze DCR data
        ScalerColorDCRDataRefreshControl(_DISABLE);

        // Read DCR Result
        UserInterfaceAdjustDCR();

        // release DCR data
        ScalerColorDCRDataRefreshControl(_ENABLE);
    }
}
#endif // End of #if(_DCR_SUPPORT == _ON)

#if(_FREEZE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Display freeze
// Input Value  : ON --> Display freeze
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustDisplayFreeze(bit bEn)
{
    ScalerFRCDisplayFreeze(bEn);
}
#endif // End of #if(_FREEZE_SUPPORT == _ON)

#if(_UNIFORMITY_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Load gain, offset and decay LUT, turn on/off offset function
// Input Value  : EnumUniformityType, EnumUniformityModeSelect
// Output Value : None
//--------------------------------------------------
void UserCommonAdjustPanelUniformity(EnumUniformityTypeSelect enumUniformityType, EnumUniformityModeSelect enumUniformityMode)
{
#if(_UNIFORMITY_LEVEL0_SUPPORT == _ON)
    if(tUNIFORMITY_OSD_TYPE_OFFSET_ENABLE_INDEX[enumUniformityType] == _ON)
    {
        ScalerColorPanelUniformityOffsetAdjust(g_pucDISP_CALIBRATION_FLASH + tUNIFORMITY_OSD_TYPE_OFFSET_ADDRESS_INDEX[enumUniformityType], _PANEL_UNIFORMITY_OFFSET_LUT_SIZE, tUNIFORMITY_OSD_TYPE_OFFSET_BANK_INDEX[enumUniformityType]);
        ScalerColorPanelUniformityDecayAdjust(g_pucDISP_CALIBRATION_FLASH + tUNIFORMITY_OSD_TYPE_DECAY_ADDRESS_INDEX[enumUniformityType], _PANEL_UNIFORMITY_DECAY_LUT_SIZE, tUNIFORMITY_OSD_TYPE_DECAY_BANK_INDEX[enumUniformityType], enumUniformityMode, _PANEL_UNIFORMITY_MULTI_LUT_MODE);
        ScalerColorPanelUniformityOffsetEnable(_FUNCTION_ON);
    }
    else
    {
        ScalerColorPanelUniformityOffsetEnable(_FUNCTION_OFF);
    }
#endif // End of #if(_UNIFORMITY_LEVEL0_SUPPORT == _ON)

    ScalerColorPanelUniformityAdjust(g_pucDISP_CALIBRATION_FLASH + tUNIFORMITY_OSD_TYPE_ADDRESS_INDEX[enumUniformityType], _PANEL_UNIFORMITY_LUT_SIZE, tUNIFORMITY_OSD_TYPE_BANK_INDEX[enumUniformityType], enumUniformityMode);
}
#endif // End of #if(_UNIFORMITY_SUPPORT == _ON)

