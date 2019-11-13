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
// ID Code      : UserCommonLocalDimming.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_LOCAL_DIMMING__

#include "UserCommonInclude.h"


#if(_ULTRA_HDR_SUPPORT == _ON)
#if(_LOCAL_DIMMING_SUPPORT == _ON)

#pragma OT(8)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#if(_PANEL_REGION_MODE == _LD_1X8_MODE)
#define _TOTAL_REGION                                           8
#elif(_PANEL_REGION_MODE == _LD_2X8_MODE)
#define _TOTAL_REGION                                           16
#endif

#define _SCENE_CHANGE_SUPPORT                                   _OFF
#define _FRAME_NUMBER_TO_TARGET                                 30

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//***************************************************************************s*
WORD code tHDRToneMappingLv1200[] =
{
#include "./BacklightModel/tHDRToneMappingLv1200.h"
};

WORD code tSDRGamma22Lv[] =
{
#include "./BacklightModel/tSDRGamma22Lv.h"
};

BYTE code tRegionMerged[] =
{
#include "./BacklightModel/tRegionMerged.h"
};

BYTE code tBaseLV[] =
{
#include "./BacklightModel/tBackGround.h"
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_pucUnifotmityGainTable[_PANEL_UNIFORMITY_LD_LUT_SIZE];
WORD g_pusUniformityGainNode[_PANEL_UNIFORMITY_LD_HOR_GRIDS * _PANEL_UNIFORMITY_LD_VER_GRIDS];
WORD g_pusDCRToLV[_TOTAL_REGION];
WORD g_pusApplyPWM[_TOTAL_REGION];
WORD g_pusLastDeltaPWM[_TOTAL_REGION] =
{
    _PANEL_PWM_DELTA_MAX, _PANEL_PWM_DELTA_MAX, _PANEL_PWM_DELTA_MAX, _PANEL_PWM_DELTA_MAX,
    _PANEL_PWM_DELTA_MAX, _PANEL_PWM_DELTA_MAX, _PANEL_PWM_DELTA_MAX, _PANEL_PWM_DELTA_MAX,
};

BYTE g_pucLocalDimmingUniformityLvMergeTable[(_PANEL_LV_MAX - _PANEL_LV_MIN + 1) * 5] =
{
#include "./BacklightModel/tLocalDimmingUniformityLvMergeTable.h"
};
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserCommonLocalDimmingAdjust(void);
void UserCommonLocalDimmingDCRToLv(BYTE *pucDCRData8bit, WORD *pusDCRToLV);
void UserCommonLocalDimmingSetPWM1x8(WORD *pusDCRToLV, WORD *pusApplyPWM);
void UserCommonLocalDimmingPWMStepChange(WORD *pusDCRLvPwm, WORD *pusLastDeltaPWM);
void UserCommonLocalDimmingPWMSmoothLevel(WORD *pusPWM, WORD usSmoothLevel);
void UserCommonLocalDimmingUniformityNodetoGainTable(WORD *pusUniformityGainNode, BYTE *pucUnifotmityGainTable);
void UserCommonLocalDimmingQuickSortDec(WORD xdata *pusArray, BYTE xdata *pucIndex);
void UserCommonLocalDimmingEnableSetting(bit bEn);
void UserCommonLocalDimmingSetLastPWMFull(void);
void UserCommonLocalDimmingStepToGDHDR(void);
void UserCommonLocalDimmingGetNodeLV1X8(WORD *pusUniformityGainNode, WORD *pusPWM);
#if(_SCENE_CHANGE_SUPPORT == _ON)
void UserCommonLocalDimmingSceneChangeStutas(WORD *pusApplyPWM, WORD *pusTargetPWM);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingAdjust(void)
{
    BYTE pucDCRResult[_TOTAL_REGION];
    memset(pucDCRResult, 255UL, _TOTAL_REGION);

    // Check if DCR data and DB ready
    if((ScalerColorDDomainDBStatus() == _NOT_WAIT) &&
       (ScalerColorDCRGetDataReadyStatus() == _TRUE))
    {
        // Clear DCR data ready status.
        ScalerColorDCRClrDataReadyStatus();
        ScalerColorDCRDataRefreshControl(_DISABLE);
        ScalerColorDCRLocalDimmingReadResult(pucDCRResult);
        ScalerColorDCRDataRefreshControl(_ENABLE);
        UserCommonLocalDimmingDCRToLv(pucDCRResult, g_pusDCRToLV);


#if(_PANEL_REGION_MODE == _LD_1X8_MODE)
        UserCommonLocalDimmingSetPWM1x8(g_pusDCRToLV, g_pusApplyPWM);
        UserCommonLocalDimmingGetNodeLV1X8(g_pusUniformityGainNode, g_pusApplyPWM);
#endif

        // Adjust pwm setting
        UserInterfaceLedDriverPwmArray(g_pusApplyPWM);

        // get uniformity table
        UserCommonLocalDimmingUniformityNodetoGainTable(g_pusUniformityGainNode, g_pucUnifotmityGainTable);

        // Write Uniformity table
        ScalerColorPanelUniformityLDTargetLUTAdjust(g_pucUnifotmityGainTable, _PANEL_UNIFORMITY_LD_LUT_SIZE, _DB_APPLY_NO_POLLING);
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingDCRToLv(BYTE *pucDCRData8bit, WORD *pusDCRToLV)
{
    BYTE ucI = 0;

    if(UserInterfaceGetHDREnableStatus() == _ON)
    {
        for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
        {
            pusDCRToLV[ucI] = tHDRToneMappingLv1200[pucDCRData8bit[ucI]];

            if(pusDCRToLV[ucI] < _PANEL_LV_MIN)
            {
                pusDCRToLV[ucI] = _PANEL_LV_MIN;
            }
        }
    }
    else
    {
        for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
        {
            pusDCRToLV[ucI] = tSDRGamma22Lv[pucDCRData8bit[ucI]];

            if(pusDCRToLV[ucI] < _PANEL_LV_MIN)
            {
                pusDCRToLV[ucI] = _PANEL_LV_MIN;
            }
        }
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingSetPWM1x8(WORD *pusDCRToLV, WORD *pusApplyPWM)
{
    BYTE data ucI = 0;
    WORD data pusDeltaPWM[_TOTAL_REGION] = {0};
    WORD xdata pusTarget_LV[_TOTAL_REGION];
    BYTE xdata pucRegionInd[_TOTAL_REGION] = {0, 1, 2, 3, 4, 5, 6, 7};
    WORD pusIdealPWM[8] = {0};
    memcpy(pusTarget_LV, pusDCRToLV, _TOTAL_REGION * sizeof(pusDCRToLV[0]));

    // sort
    UserCommonLocalDimmingQuickSortDec(pusTarget_LV, pucRegionInd);

    // set increase PWM
    for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
    {
        switch(pucRegionInd[ucI])
        {
            case 0:
                if(pusDCRToLV[0] > tBaseLV[0] + pusDeltaPWM[1] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[0] = (pusDCRToLV[0] - tBaseLV[0] - pusDeltaPWM[1] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[0] = (pusDeltaPWM[0] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[0];
                }
                break;
            case 1:
                if(pusDCRToLV[1] > tBaseLV[1] + pusDeltaPWM[0] / _PWM_TO_LV_NEIGHBOR + pusDeltaPWM[2] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[1] = (pusDCRToLV[1] - tBaseLV[1] - pusDeltaPWM[0] / _PWM_TO_LV_NEIGHBOR - pusDeltaPWM[2] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[1] = (pusDeltaPWM[1] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[1];
                }
                break;
            case 2:
                if(pusDCRToLV[2] > tBaseLV[2] + pusDeltaPWM[1] / _PWM_TO_LV_NEIGHBOR + pusDeltaPWM[3] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[2] = (pusDCRToLV[2] - tBaseLV[2] - pusDeltaPWM[1] / _PWM_TO_LV_NEIGHBOR - pusDeltaPWM[3] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[2] = (pusDeltaPWM[2] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[2];
                }
                break;
            case 3:
                if(pusDCRToLV[3] > tBaseLV[3] + pusDeltaPWM[2] / _PWM_TO_LV_NEIGHBOR + pusDeltaPWM[4] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[3] = (pusDCRToLV[3] - tBaseLV[3] - pusDeltaPWM[2] / _PWM_TO_LV_NEIGHBOR - pusDeltaPWM[4] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[3] = (pusDeltaPWM[3] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[3];
                }
                break;
            case 4:
                if(pusDCRToLV[4] > tBaseLV[4] + pusDeltaPWM[3] / _PWM_TO_LV_NEIGHBOR + pusDeltaPWM[5] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[4] = (pusDCRToLV[4] - tBaseLV[4] - pusDeltaPWM[3] / _PWM_TO_LV_NEIGHBOR - pusDeltaPWM[5] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[4] = (pusDeltaPWM[4] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[4];
                }
                break;
            case 5:
                if(pusDCRToLV[5] > tBaseLV[5] + pusDeltaPWM[4] / _PWM_TO_LV_NEIGHBOR + pusDeltaPWM[6] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[5] = (pusDCRToLV[5] - tBaseLV[5] - pusDeltaPWM[4] / _PWM_TO_LV_NEIGHBOR - pusDeltaPWM[6] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[5] = (pusDeltaPWM[5] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[5];
                }
                break;
            case 6:
                if(pusDCRToLV[6] > tBaseLV[6] + pusDeltaPWM[5] / _PWM_TO_LV_NEIGHBOR + pusDeltaPWM[7] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[6] = (pusDCRToLV[6] - tBaseLV[6] - pusDeltaPWM[5] / _PWM_TO_LV_NEIGHBOR - pusDeltaPWM[7] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[6] = (pusDeltaPWM[6] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[6];
                }
                break;
            case 7:
                if(pusDCRToLV[7] > tBaseLV[7] + pusDeltaPWM[6] / _PWM_TO_LV_NEIGHBOR)
                {
                    pusDeltaPWM[7] = (pusDCRToLV[7] - tBaseLV[7] - pusDeltaPWM[6] / _PWM_TO_LV_NEIGHBOR) * _PWM_TO_LV_OWN;
                    pusDeltaPWM[7] = (pusDeltaPWM[7] > _PANEL_PWM_DELTA_MAX) ? _PANEL_PWM_DELTA_MAX : pusDeltaPWM[7];
                }
                break;
            default:
                break;
        }
    }
    // smooth PWM process
    UserCommonLocalDimmingPWMSmoothLevel(pusDeltaPWM, UserInterfaceLedDriverPWMSmoothLevel());
    memcpy(pusIdealPWM, pusDeltaPWM, 8 * sizeof(pusDeltaPWM[0])); // scene test

    UserCommonLocalDimmingPWMStepChange(pusDeltaPWM, g_pusLastDeltaPWM);

#if(_SCENE_CHANGE_SUPPORT == _ON)
    UserCommonLocalDimmingSceneChangeStutas(pusDeltaPWM, pusIdealPWM);
#endif

    memcpy(pusApplyPWM, pusDeltaPWM, 8 * sizeof(pusDeltaPWM[0]));
    for(ucI = 0; ucI < 8; ucI++)
    {
        pusApplyPWM[ucI] = pusDeltaPWM[ucI] + _PANEL_PWM_MIN;
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingPWMStepChange(WORD *pusDCRLvPwm, WORD *pusLastDeltaPWM)
{
    BYTE data ucI = 0;
    BYTE ucPWMStep = 0;
    for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
    {
        if(pusDCRLvPwm[ucI] > pusLastDeltaPWM[ucI])
        {
            ucPWMStep = (pusDCRLvPwm[ucI] - pusLastDeltaPWM[ucI]) / _FRAME_NUMBER_TO_TARGET;
            ucPWMStep = (ucPWMStep == 0) ? 1 : ucPWMStep;
            if(pusDCRLvPwm[ucI] > (ucPWMStep + pusLastDeltaPWM[ucI]))
            {
                pusDCRLvPwm[ucI] = pusLastDeltaPWM[ucI] + ucPWMStep;
            }
        }
        else if(pusDCRLvPwm[ucI] < pusLastDeltaPWM[ucI])
        {
            ucPWMStep = (pusLastDeltaPWM[ucI] - pusDCRLvPwm[ucI]) / _FRAME_NUMBER_TO_TARGET;
            ucPWMStep = (ucPWMStep == 0) ? 1 : ucPWMStep;
            if(pusDCRLvPwm[ucI] + ucPWMStep < pusLastDeltaPWM[ucI])
            {
                pusDCRLvPwm[ucI] = pusLastDeltaPWM[ucI] - ucPWMStep;
            }
        }
    }

    memcpy(pusLastDeltaPWM, pusDCRLvPwm, 8 * sizeof(pusDCRLvPwm[0]));
}
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingPWMSmoothLevel(WORD *pusPWM, WORD usSmoothLevel)
{
    BYTE data ucI = 0;

    for(ucI = 0; ucI < 7; ucI++)
    {
        if(pusPWM[ucI] > (pusPWM[ucI + 1] + usSmoothLevel))
        {
            pusPWM[ucI + 1] = pusPWM[ucI] - usSmoothLevel;
        }
        if(pusPWM[ucI + 1] > (pusPWM[ucI] + usSmoothLevel))
        {
            pusPWM[ucI] = pusPWM[ucI + 1] - usSmoothLevel;
        }
    }

    for(ucI = 6; ucI > 0; ucI--)
    {
        if(pusPWM[ucI] > (pusPWM[ucI - 1] + usSmoothLevel))
        {
            pusPWM[ucI - 1] = pusPWM[ucI] - usSmoothLevel;
        }
        if(pusPWM[ucI - 1] > (pusPWM[ucI] + usSmoothLevel))
        {
            pusPWM[ucI] = pusPWM[ucI - 1] - usSmoothLevel;
        }
    }
}
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingUniformityNodetoGainTable(WORD *pusUniformityGainNode, BYTE *pucUnifotmityGainTable)
{
    BYTE data ucI = 0;
    BYTE data ucJ = 0;
    WORD *pusUniformityGainNodeOffset;
    BYTE data ucUniformityGainTablePosition = 0;
    BYTE data ucQuot = (_PANEL_UNIFORMITY_LD_HOR_GRIDS * _PANEL_UNIFORMITY_LD_VER_GRIDS) / 255;
    BYTE data ucRemind = (_PANEL_UNIFORMITY_LD_HOR_GRIDS * _PANEL_UNIFORMITY_LD_VER_GRIDS) % 255;
    BYTE data ucMaxIdx = 0;
    for(ucI = 0; ucI <= ucQuot; ucI++)
    {
        pusUniformityGainNodeOffset = &pusUniformityGainNode[(WORD)(ucI)*0xFF];

        if(ucI != ucQuot)
        {
            ucMaxIdx=0xFF;
        }
        else
        {
            ucMaxIdx = ucRemind;
        }

        for(ucJ = 0; ucJ < ucMaxIdx; ucJ++)
        {
            data WORD usUniformityGainNode_ucI = pusUniformityGainNodeOffset[ucJ];

            if((usUniformityGainNode_ucI > _PANEL_LV_MAX))
            {
                ucUniformityGainTablePosition = (_PANEL_LV_MAX - _PANEL_LV_MIN);
            }
            else if(usUniformityGainNode_ucI < _PANEL_LV_MIN)
            {
                ucUniformityGainTablePosition = (_PANEL_LV_MIN - _PANEL_LV_MIN);
            }
            else
            {
                ucUniformityGainTablePosition = usUniformityGainNode_ucI - _PANEL_LV_MIN;
            }
            memcpy(pucUnifotmityGainTable, g_pucLocalDimmingUniformityLvMergeTable + ((WORD)ucUniformityGainTablePosition) * 5, 5);
            pucUnifotmityGainTable += 5;
        }
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingQuickSortDec(WORD xdata *pusArray, BYTE xdata *pucIndex)
{
    BYTE data ucSwap = 0;
    BYTE data ucTempIndex = 0;

    WORD usPivot = 0;
    SBYTE data chI = 0;
    SBYTE data chLeft = 0;
    SBYTE data chRight = 0;
    BYTE data pucBegin[6];
    BYTE data pucEnd[6];
    ((DWORD *)&(pucIndex[0]))[0] = 0x00010203;
    ((DWORD *)&(pucIndex[4]))[0] = 0x04050607;

    pucBegin[0] = 0;
    pucEnd[0] = 8;

    while(chI >= 0)
    {
        chLeft = pucBegin[chI];
        chRight = pucEnd[chI] - 1;

        if(chLeft < chRight)
        {
            usPivot = pusArray[chLeft];
            ucTempIndex = pucIndex[chLeft];

            while(chLeft < chRight)
            {
                while((pusArray[chRight] <= usPivot) && (chLeft < chRight))
                {
                    chRight--;
                }

                if(chLeft < chRight)
                {
                    pucIndex[chLeft] = pucIndex[chRight];
                    pusArray[chLeft++] = pusArray[chRight];
                }

                while((pusArray[chLeft] >= usPivot) && (chLeft < chRight))
                {
                    chLeft++;
                }

                if(chLeft < chRight)
                {
                    pucIndex[chRight] = pucIndex[chLeft];
                    pusArray[chRight--] = pusArray[chLeft];
                }
            }
            pusArray[chLeft] = usPivot;
            pucIndex[chLeft] = ucTempIndex;
            pucBegin[chI + 1] = chLeft + 1;
            pucEnd[chI + 1] = pucEnd[chI];
            pucEnd[chI++] = chLeft;

            if(pucEnd[chI] - pucBegin[chI] > pucEnd[chI - 1] - pucBegin[chI - 1])
            {
                ucSwap = pucBegin[chI];
                pucBegin[chI] = pucBegin[chI - 1];
                pucBegin[chI - 1] = ucSwap;

                ucSwap = pucEnd[chI];
                pucEnd[chI] = pucEnd[chI - 1];
                pucEnd[chI - 1] = ucSwap;
            }
        }
        else
        {
            chI--;
        }
    }
}
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingEnableSetting(bit bEn)
{
    if(bEn == _ENABLE)
    {
        // DCR
        ScalerColorDCRLocalDimmingEnable(_FUNCTION_ON);
        ScalerColorDCRLocalDimmingSetMode(_LOCAL_DIMMING_HDR_1X8_MODE);
        ScalerColorDCRLocalDimmingSetTCon(_LOCAL_DIMMING_HDR_1X8_MODE);

        // Uniformity
        ScalerColorPanelUniformityLDInitial(_UNIFORMITY_PCM_MODE);
        ScalerColorPanelUniformityLDEnable(_ENABLE);
        ScalerColorPanelUniformityEnable(_FUNCTION_ON);

        // Global DB
        ScalerColorDDomainDBEnable(_ENABLE);
        ScalerColorDDomainDBTriggerEvent(_DB_VS_TRIGGER);
    }
    else
    {
        // DCR
        ScalerColorDCRLocalDimmingEnable(_FUNCTION_OFF);

        // Uniformity
        ScalerColorPanelUniformityLDEnable(_DISABLE);
        ScalerColorPanelUniformityEnable(_FUNCTION_OFF);

        // Global DB
        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerColorDDomainDBEnable(_DISABLE);

        // Back light setting
        UserInterfaceLedDriverInitial();
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingSetLastPWMFull(void)
{
    BYTE ucI = 0;

    for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
    {
        g_pusLastDeltaPWM[ucI] = _PANEL_PWM_DELTA_MAX;
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingStepToGDHDR(void)
{
    BYTE ucI = 0;
    BYTE ucFinishFlag = 0;
    BYTE ucTimeout = 30;
    BYTE pucRegionFlag[_TOTAL_REGION] = {0};

    if(ScalerColorDDomainDBStatus() == _WAIT)
    {
        ScalerTimerWaitForEvent(_EVENT_DVS);
    }

    while(ucFinishFlag != _TOTAL_REGION)
    {
        ucFinishFlag = 0;
        for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
        {
            g_pusApplyPWM[ucI] = g_pusApplyPWM[ucI] + _PWM_STEP_TO_GOLBAL;

            if(g_pusApplyPWM[ucI] >= _PANEL_PWM_MAX)
            {
                g_pusApplyPWM[ucI] = _PANEL_PWM_MAX;
                pucRegionFlag[ucI] = 1;
            }
            else
            {
                pucRegionFlag[ucI] = 0;
            }
        }

        UserInterfaceLedDriverPwmArray(g_pusApplyPWM);
        UserCommonLocalDimmingGetNodeLV1X8(g_pusUniformityGainNode, g_pusApplyPWM);

        UserCommonLocalDimmingUniformityNodetoGainTable(g_pusUniformityGainNode, g_pucUnifotmityGainTable);
        ScalerColorPanelUniformityLDTargetLUTAdjust(g_pucUnifotmityGainTable, _PANEL_UNIFORMITY_LD_LUT_SIZE, _DB_APPLY_POLLING);

        for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
        {
            ucFinishFlag += pucRegionFlag[ucI];
        }

        // Check timeout counter
        if(ucTimeout-- == 0)
        {
            for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
            {
                g_pusApplyPWM[ucI] = _PANEL_PWM_MAX;
            }
            UserInterfaceLedDriverPwmArray(g_pusApplyPWM);
            UserCommonLocalDimmingGetNodeLV1X8(g_pusUniformityGainNode, g_pusApplyPWM);

            UserCommonLocalDimmingUniformityNodetoGainTable(g_pusUniformityGainNode, g_pucUnifotmityGainTable);
            ScalerColorPanelUniformityLDTargetLUTAdjust(g_pucUnifotmityGainTable, _PANEL_UNIFORMITY_LD_LUT_SIZE, _DB_APPLY_POLLING);
            break;
        }
    }

    UserCommonLocalDimmingSetLastPWMFull();
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingGetNodeLV1X8(WORD *pusUniformityGainNode, WORD *pusPWM)
{
    BYTE ucI = 0;
    BYTE ucJ = 0;
    data BYTE code *pucData = tRegionMerged;
    WORD data usNodeIndex = 0;
    WORD data pusLocalPwm[_TOTAL_REGION];

    for(ucI = 0; ucI < (sizeof(pusLocalPwm) / sizeof(pusLocalPwm[0])); ++ucI)
    {
        pusLocalPwm[ucI] = pusPWM[ucI] - _PANEL_PWM_MIN;
        pusLocalPwm[ucI] *= 16;

        if(LOBYTE(pusLocalPwm[ucI]) >= 128)
        {
            pusLocalPwm[ucI] += 256;
        }
    }

    for(ucI = 0; ucI < _PANEL_UNIFORMITY_LD_VER_GRIDS; ucI++)
    {
        for(ucJ = 0; ucJ < _PANEL_UNIFORMITY_LD_HOR_GRIDS; ucJ++)
        {
            pusUniformityGainNode[usNodeIndex] =
                ((BYTEPTR(pusLocalPwm)[0] * pucData[0] +
                  BYTEPTR(pusLocalPwm)[2] * pucData[1] +
                  BYTEPTR(pusLocalPwm)[4] * pucData[2] +
                  BYTEPTR(pusLocalPwm)[6] * pucData[3] +
                  BYTEPTR(pusLocalPwm)[8] * pucData[4] +
                  BYTEPTR(pusLocalPwm)[10] * pucData[5] +
                  BYTEPTR(pusLocalPwm)[12] * pucData[6] +
                  BYTEPTR(pusLocalPwm)[14] * pucData[7]) / 32 + pucData[8]);
            usNodeIndex++;
            pucData += 9;
        }
    }
}

#if(_SCENE_CHANGE_SUPPORT == _ON)
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void UserCommonLocalDimmingSceneChangeStutas(WORD *pusApplyPWM, WORD *pusTargetPWM)
{
    BYTE ucI = 0;

    for(ucI = 0; ucI < _TOTAL_REGION; ucI++)
    {
        if((pusApplyPWM[ucI] + _PWM_BY_FRAME_ADJUST_ADD * 120 < pusTargetPWM[ucI]))
        {
            pusApplyPWM[ucI] = pusTargetPWM[ucI] - 60 * _PWM_BY_FRAME_ADJUST_ADD;
            g_pusLastDeltaPWM[ucI] = pusTargetPWM[ucI] - 60 * _PWM_BY_FRAME_ADJUST_ADD;
        }
    }
}
#endif

#endif // End of #if(_LOCAL_DIMMING_SUPPORT == _ON)
#endif // End of #if(_ULTRA_HDR_SUPPORT == _ON)

