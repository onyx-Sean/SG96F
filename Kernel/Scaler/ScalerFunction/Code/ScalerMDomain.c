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
// ID Code      : ScalerMDomain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MDOMAIN__

#include "ScalerFunctionInclude.h"

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

DWORD g_ulDClkFreq;

StructMDomainInfo g_stMDomainInfo;
StructTimingInfo g_stMDomainInputData;
StructDisplayInfo g_stMDomainOutputData;

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
bit g_bAspectOriginMode = 0;
#endif

WORD g_usDVFreq;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerMDomainControl(void);
EnumMemoryWorkMode ScalerMDomainMemoryConfig(void);
StructDHVtotal ScalerMDomainDHVtotalFinetune(DWORD ulDclk, BYTE ucMemorySel);
void ScalerMDomainSetDisplayTimingGen(void);
WORD ScalerMDomainGetDisplayBackgroundVstart(void);
WORD ScalerMDomainGetDisplayVheight(void);

#if((_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON) || (_FREESYNC_SUPPORT == _ON))
#if(_FRC_SUPPORT == _ON)
bit ScalerMDomainFSLineBufferDclkDvtotalCheck(void);
#endif
#endif

BYTE ScalerMDomainGetDpllSscgDivMode(void);
void ScalerMDomainCheckDisplayFormat(void);

void ScalerMDomainSetScaling(const StructSDRAMDataInfo *pstFIFOScaling);
BYTE ScalerMDomainMemorySelectConfirm(void);
void ScalerMDomainSetMemoryDataBit(BYTE ucColorDepth);

WORD ScalerMDomainGetVerticalAdjustLimit(EnumSourceTypeDef enumSourceTypeDef);
DWORD ScalerMDomainGetDisplayActiveRegion(void);
bit ScalerMDomainDisplayTimingGenCheck(void);

#if(_I_DITHER_SUPPORT == _ON)
BYTE ScalerMDomainGetColorDepth(void);
#endif

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
void ScalerMDomainAspectOriginMode(bit bOn);
#endif

#if(_OD_SUPPORT == _ON)
void ScalerMDomainODConfig(void);
WORD ScalerMDomainODCalculateMemoryUseSpace(BYTE ucODbit);
WORD ScalerMDomainODCalculateMemoryUseBW(BYTE ucODbit);
#endif // End of #if(_OD_SUPPORT == _ON)

#if(((_FRC_SUPPORT == _ON) && (_OD_SUPPORT == _ON)) || (_DISP_LATENCY_ADJUST_SUPPORT == _ON))
WORD ScalerMDomainGetFRCMemorySpace(void);
WORD ScalerMDomainGetFRCMemoryBW(void);
#endif
void ScalerMDomainSetDBOsdFlow(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : M Domain Main Process
// Input Value  : None
// Output Value : M domain check pass or fail
//--------------------------------------------------
bit ScalerMDomainControl(void)
{
    StructSDRAMDataInfo stFIFOScaling;
    memset(&stFIFOScaling, 0, sizeof(StructSDRAMDataInfo));

#if(_OD_SUPPORT == _ON)
    SET_OD_USE_BIT(_OFF);
#endif

    SET_MEMORY_DVF_SELECT(ScalerDisplaySelectDVFMode());
    ScalerDisplaySetDVFreq();


    // Set memory data bit
    ScalerMDomainSetMemoryDataBit(GET_COLOR_DEPTH());

    SET_MEMORY_CONFIG(ScalerMDomainMemoryConfig());

#if((_FRC_SUPPORT == _ON) && (_FRC_FIXED_30_BIT_DATA_FORMAT == _ON))
    if(GET_MEMORY_CONFIG() == _MEMORY_WORK_MODE)
    {
        ScalerMDomainSetMemoryDataBit(_COLOR_DEPTH_10_BITS);
    }
#endif

    // Update DVT in Line buffer frame sync
    if(GET_MEMORY_CONFIG() == _LINE_BUFFER_MODE)
    {
        g_stMDomainOutputData.usVTotal = ((DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight * 1000) / g_stMDomainInputData.usVFreq;
    }

    // Select Memory Configuration Type
    SET_MEMORY_SELECT(ScalerMDomainMemorySelectConfirm());

    // Disable Spread Spectrum
    ScalerPLLSetDPLLSSC(_DCLK_SPREAD_SPEED, _OFF);

    // Get Scaling size in FIFO
    ScalerScalingGetFIFOScalingSize(&stFIFOScaling);

    // Scaling Setting
    ScalerMDomainSetScaling(&stFIFOScaling);

    // I DB apply after SD to ensure the correctness of g_ulInputActiveRegionBackUp
    ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);

#if(_OD_SUPPORT == _ON)
    ScalerMDomainODConfig();
#endif

    // Enable Active Region Measure
    ScalerMeasureSetInputRegionCount(_ACTIVE_REGION_TYPE);

    // Set FIFO Capture Window
    ScalerMemorySetFifoCapture(stFIFOScaling.usOutputHWidth, stFIFOScaling.usOutputVHeight);

    DebugMessageScaler("Memory Work Select", GET_MEMORY_SELECT());

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _FALSE;
    }
#endif

    // Set Memory Utilization
    switch(GET_MEMORY_SELECT())
    {
        case _FRAME_SYNC_LINE_BUFFER:

            // Initial M Domain Block
            ScalerMemoryInitial();

            // Set FIFO freq.
            ScalerMemorySetFIFOFreq(_FIFO_FREQ_LINE_BUFFER_SEL);

            // Set Initial Dt Value
            ScalerMemoryFrameSyncSetDt(_DT_TARGET_PERCENTAGE);

            // Set display Format
            ScalerMDomainSetDisplayFormat(_FRAME_SYNC_LINE_BUFFER);

            // Fine Tune DClk Offset
            ScalerDPLLFineTuneFrameSyncLineBuffer();

            // Adjust IVS/IHS for Position Range
            ScalerIDomainVgipAdjustIHVDelay();

            break;

#if(_FRC_SUPPORT == _ON)

        case _FRAME_SYNC_MEMORY:
        case _FREE_RUN_MEMORY:
        case _MN_FRAME_SYNC_MEMORY:

            // Adjust IVS/IHS for Position Range
            ScalerIDomainVgipAdjustIHVDelay();

            // Set display Format
            ScalerMDomainSetDisplayFormat(GET_MEMORY_SELECT());

            // Initial M Domain Block
            ScalerMemoryInitial();

            // Measure Input Active Region
            ScalerMeasureSetInputRegionCount(_ACTIVE_REGION_TYPE);
            g_ulInputActiveRegionBackUp = ScalerMeasureGetInputRegionCountResult(_WAIT);

            // Set FIFO freq.
            ScalerMemorySetFIFOFreq(_FIFO_FREQ_FRAME_BUFFER_SEL);

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
            // Get Rotation status
            if(ScalerRotationCheckStatus() == _TRUE)
            {
#if(_DISPLAY_VER_MIRROR_SUPPORT == _ON)
                if(GET_ROT_TYPE() == _ROT_VER_MIRROR)
                {
                    // Set FRC control
                    ScalerFRCControl(&stFIFOScaling);
                }
                else
#endif
                {
                    // Set Rotation
                    ScalerRotationControl(&stFIFOScaling);
                }
            }
            else
#endif
            {
                // Set FRC control
                ScalerFRCControl(&stFIFOScaling);
            }

            if(GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY)
            {
                ScalerDPLLFineTuneFrameSyncFrameBuffer();
            }
#if(_MN_FINE_TUNE_LASTLINE_SUPPORT == _ON)
            else if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_MEMORY)
            {
                ScalerDPLLFineTuneFrameSyncFrameBuffer();
            }
#endif

            break;

#endif // End of #if(_FRC_SUPPORT == _ON)

        default:

            // Initial M Domain Block
            ScalerMemoryInitial();

            break;
    }

    // Enable double buffer
    ScalerMDomainControlDBApply();

    // Enable Spread Spectrum
    ScalerPLLSetDPLLSSC(_DCLK_SPREAD_SPEED, _DCLK_SPREAD_RANGE);

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _FALSE;
    }
#endif

    // Measure Input Active Region
    ScalerMeasureSetInputRegionCount(_ACTIVE_REGION_TYPE);

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _FALSE;
    }
#endif

    ScalerTimerWaitForEvent(_EVENT_IVS);

#if(_OD_SUPPORT == _ON)
    ScalerODInitial(_PANEL_DH_WIDTH, _PANEL_DV_HEIGHT);

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
    ScalerMemorySetODThreeBlockAddress();
#endif
#endif

#if(_MEMORY_TYPE_CONFIG != _NO_MEMORY)
    ScalerMemoryReset();
#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#if(_DISPLAY_ROTATION_TYPE == _DISPLAY_ROTATION_GEN_II)
    ScalerRotationReset();
#endif
#endif

    // Clear Buffer Status
    ScalerSetByte(P0_02_STATUS0, 0xFF);

    // Clear Display Vsync timeout flag
    ScalerSetBit(P0_0C_WATCH_DOG_CTRL0, ~_BIT0, _BIT0);

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _FALSE;
    }
#endif

    ScalerTimerWaitForEvent(_EVENT_IVS);

    if((ScalerMDomainMemoryCheck() == _FALSE) ||
       (ScalerMeasureInputActiveRegionChange() == _TRUE) ||
       (ScalerMDomainDisplayTimingGenCheck() == _FALSE))
    {
        DebugMessageScaler("MemoryCheck Fail in Display Setting", GET_MEMORY_SELECT());

        return _FALSE;
    }

    // If M domain setup success, set I domain DB trigger event to IEN_STOP
    ScalerGlobalIDDomainDBSetTriggerEvent();

    // Update on-line measure result
    ScalerMeasureUpdateOnlineMeasureResult();

#if(_LC_TANK_SUPPORT == _ON)
#if(_XTALESS_SUPPORT == _ON)
    // Initialize LCTank DPLL check
    ScalerLCTankDpllRegulationInitial();
#endif
#endif

    return _TRUE;
}

//--------------------------------------------------
// Description  : Memory Config
// Input Value  : NA
// Output Value : NA
//--------------------------------------------------
EnumMemoryWorkMode ScalerMDomainMemoryConfig(void)
{
#if(_FREESYNC_SUPPORT == _ON)
    if((GET_FREESYNC_ENABLED() == _TRUE) && (_FREESYNC_LINEBUFFER_PRIORITY == _ON))
    {
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
        if(ScalerRotationCheckStatus() == _TRUE)
        {
            return _MEMORY_WORK_MODE;
        }
#endif

        if(_LAST_LINE_FINETUNE_ENABLE == _DISABLE)
        {
            return _MEMORY_WORK_MODE;
        }
        else
        {
#if(_FRC_SUPPORT == _ON)
            if((g_stMDomainOutputData.usVBackHeight > g_stMDomainOutputData.usVHeight) ||
               (ScalerMDomainFSLineBufferDclkDvtotalCheck() == _FALSE))
            {
                return _MEMORY_WORK_MODE;
            }
#endif
        }

        return _LINE_BUFFER_MODE;
    }
    else
#endif // End of #if(_FREESYNC_SUPPORT == _ON)
    {
#if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _OFF)
        return _MEMORY_WORK_MODE;
#else
        BYTE ucMemoryConfig = _LINE_BUFFER_MODE;

#if(_FRC_SUPPORT == _ON)
        if(((g_stDVCustomizedFreq.usMaxFreq - g_stDVCustomizedFreq.usMinFreq) < (g_stDVCustomizedFreq.usTypFreq >> 4)) &&
           (abs(g_stMDomainInputData.usVFreq - g_stDVCustomizedFreq.usTypFreq) < (g_stDVCustomizedFreq.usTypFreq >> 4)))
        {
            g_stDVCustomizedFreq.usMaxFreq += _FRAME_SYNC_MARGIN;
            g_stDVCustomizedFreq.usMinFreq -= _FRAME_SYNC_MARGIN;
        }

        if((g_stMDomainInputData.usVFreq < (g_stDVCustomizedFreq.usMinFreq)) ||
           (g_stMDomainInputData.usVFreq > (g_stDVCustomizedFreq.usMaxFreq)) ||
           (g_stMDomainOutputData.usVBackHeight > g_stMDomainOutputData.usVHeight) ||
           (ScalerMDomainFSLineBufferDclkDvtotalCheck() == _FALSE))
        {
            ucMemoryConfig = _MEMORY_WORK_MODE;
        }

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
        if(ScalerFmtCnvFtoPGetStatus() == _FALSE)
        {
            ucMemoryConfig = _MEMORY_WORK_MODE;
        }
#endif

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
        if(ScalerRotationCheckStatus() == _TRUE)
        {
            ucMemoryConfig = _MEMORY_WORK_MODE;
        }
#endif

#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
        // if display latency != faster, then change to _MEMORY_WORK_MODE
        if((GET_DISP_LATENCY_RATIO() != 0x00) && (ucMemoryConfig == _LINE_BUFFER_MODE))
        {
            if((ScalerMDomainGetFRCMemorySpace() < _MEMORY_ROW) && (ScalerMDomainGetFRCMemoryBW() < _MEMORY_TOTAL_BW))
            {
                ucMemoryConfig = _MEMORY_WORK_MODE;
            }
            else
            {
                SET_DISP_LATENCY_RATIO(0x00);
            }
        }
#endif // End if #if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
#endif // End of #if(_FRC_SUPPORT == _ON)

        return ucMemoryConfig;

#endif // End of #if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _OFF)
    }
}

//--------------------------------------------------
// Description  : If Dclk over panel spec, finetune DHtotal and DVtotal
// Input Value  : Dclk/ Memory select
// Output Value : ((usDVtotal << 8) | (usDHtotal))
//--------------------------------------------------
StructDHVtotal ScalerMDomainDHVtotalFinetune(DWORD ulDclk, BYTE ucMemorySel)
{
    DWORD ulDclkSscgMax = 0;
    DWORD ulDclkSscgMin = 0;
    DWORD ulDclkNew = 0;

    StructDHVtotal stHVtotal;
    stHVtotal.usDHtotal = GET_MDOMAIN_OUTPUT_HTOTAL();
    stHVtotal.usDVtotal = GET_MDOMAIN_OUTPUT_VTOTAL();

    ucMemorySel = ucMemorySel;

    ulDclkSscgMax = ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ - ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ / 100) - (_PANEL_PIXEL_CLOCK_MAX_KHZ * _DCLK_SPREAD_RANGE * 5 / 2000 / ScalerMDomainGetDpllSscgDivMode()));
    ulDclkSscgMin = ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ + ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ / 100) + (_PANEL_PIXEL_CLOCK_MIN_KHZ * _DCLK_SPREAD_RANGE * 5 / 2000 / ScalerMDomainGetDpllSscgDivMode()));

    // If DClk Out of Panel Spec => Try Modifying DHTotal
    if((ulDclk > ulDclkSscgMax) || (ulDclk < ulDclkSscgMin))
    {
        // DClk > Panel Max with Max SSC ((_DCLK_SPREAD_RANGE / ucDpllSscgDiv) / 2 each Side plus 1 % margin)
        if(ulDclk > ulDclkSscgMax)
        {
            // Calculate Target DHTotal
            stHVtotal.usDHtotal = (GET_MDOMAIN_OUTPUT_HTOTAL() * ulDclkSscgMax / ulDclk);

            // Make Sure DHTotal to be multiple of output port
            stHVtotal.usDHtotal -= (stHVtotal.usDHtotal % _DHTOTAL_MULTIPLE);

            stHVtotal.usDHtotal = ((stHVtotal.usDHtotal < _PANEL_DH_TOTAL_MIN) ? _PANEL_DH_TOTAL_MIN : stHVtotal.usDHtotal);

            DebugMessageScaler("D Clock Larger Than Panel Spec => Modify Htotal", stHVtotal.usDHtotal);
        }
        else // DClk < Panel Min plus Max SSC (plus margin)
        {
            // Calculate Target DHTotal
            stHVtotal.usDHtotal = (GET_MDOMAIN_OUTPUT_HTOTAL() * ulDclkSscgMin / ulDclk);

            // Make Sure DHTotal to be multiple of output port
            stHVtotal.usDHtotal = stHVtotal.usDHtotal + _DHTOTAL_MULTIPLE - (stHVtotal.usDHtotal % _DHTOTAL_MULTIPLE);

            stHVtotal.usDHtotal = ((stHVtotal.usDHtotal > _PANEL_DH_TOTAL_MAX) ? _PANEL_DH_TOTAL_MAX : stHVtotal.usDHtotal);

            DebugMessageScaler("D Clock Smaller Than Panel Spec => Modify Htotal", stHVtotal.usDHtotal);
        }

        // Calculate Target Dclk
        ulDclkNew = (ulDclk / GET_MDOMAIN_OUTPUT_HTOTAL() * stHVtotal.usDHtotal) +
                    ((ulDclk % GET_MDOMAIN_OUTPUT_HTOTAL()) * stHVtotal.usDHtotal / GET_MDOMAIN_OUTPUT_HTOTAL());

#if(_FRC_SUPPORT == _ON)
        // Check Dclk
        if(((ucMemorySel == _FRAME_SYNC_MEMORY) || (ucMemorySel == _MN_FRAME_SYNC_MEMORY)) &&
           ((ulDclkNew > ulDclkSscgMax) || (ulDclkNew < ulDclkSscgMin)))
        {
            if(ulDclkNew > ulDclkSscgMax)
            {
                // Calculate Target DVTotal
                stHVtotal.usDVtotal = ((DWORD)_PANEL_DV_TOTAL * ulDclkSscgMax / ulDclkNew);
                stHVtotal.usDVtotal = ((stHVtotal.usDVtotal < _PANEL_DV_TOTAL_MIN) ? _PANEL_DV_TOTAL_MIN : stHVtotal.usDVtotal);
            }
            else
            {
                // Calculate Target DVTotal
                stHVtotal.usDVtotal = (DWORD)_PANEL_DV_TOTAL * ulDclkSscgMin / ulDclkNew + 1;
                stHVtotal.usDVtotal = ((stHVtotal.usDVtotal > _PANEL_DV_TOTAL_MAX) ? _PANEL_DV_TOTAL_MAX : stHVtotal.usDVtotal);
            }
        }
#endif // End of #if(_FRC_SUPPORT == _ON)
    }

    return stHVtotal;
}

//--------------------------------------------------
// Description  : Set Display Timgin Gen: Dtotal, Background, active region and display mode
// Input Value  : NA
// Output Value : NA
//--------------------------------------------------
void ScalerMDomainSetDisplayTimingGen(void)
{
    WORD usVBackStartOld = 0;
    WORD usVHeightOld = 0;
    WORD usHStartOld = 0;
    WORD usVStartOld = 0;
    WORD usDVtotal = 0;

    usVBackStartOld = ScalerMDomainGetDisplayBackgroundVstart();
    usVHeightOld = ScalerMDomainGetDisplayVheight();
    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_05_DISPLAY_HOR_ACT_STA_H, 2, pData, _AUTOINC);
    usHStartOld = ((pData[0] << 8) | pData[1]);
    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_10_DISPLAY_VER_ACT_STA_H, 2, pData, _AUTOINC);
    usVStartOld = ((pData[0] << 8) | pData[1]);

    // Set H sync width, must by 2x in even-odd-mode
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_02_DISPLAY_HOR_SYNC_END);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (_PANEL_DH_SYNC_WIDTH + _PANEL_DH_SYNC_WIDTH % 2));

    // Set V sync height
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_0D_DISPLAY_VER_SYNC_END);

#if(_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(_DP_FREESYNC_DV_SYNC_HEIGHT));
    }
    else
#endif
    {
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(_PANEL_DV_SYNC_HEIGHT));
    }

    // Set Main H background st/ ed (Panel size)
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_03_DISPLAY_HOR_BG_STA_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_HBSTART()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_HBSTART()));

    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_09_DISPLAY_HOR_BG_END_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_HBSTART() + GET_MDOMAIN_OUTPUT_HBWIDTH()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_HBSTART() + GET_MDOMAIN_OUTPUT_HBWIDTH()));

    // Set Main V background st/ ed (Panel size)
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_0E_DISPLAY_VER_BG_STA_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_VBSTART()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_VBSTART()));

    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_14_DISPLAY_VER_BG_END_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_VBSTART() + GET_MDOMAIN_OUTPUT_VBHEIGHT()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_VBSTART() + GET_MDOMAIN_OUTPUT_VBHEIGHT()));

    // Set Main1 H Active st/ ed
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_05_DISPLAY_HOR_ACT_STA_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_HSTART()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_HSTART()));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_HSTART() + GET_MDOMAIN_OUTPUT_HWIDTH()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_HSTART() + GET_MDOMAIN_OUTPUT_HWIDTH()));

    // Set Main1 V Active st/ ed
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_10_DISPLAY_VER_ACT_STA_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_VSTART()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_VSTART()));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT()) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT()));

    // [4]: Main source type: !4P
    // [3]: Dtime Main mode: select even/ odd
    // [2]: Dtime Sub mode: select disable
    // [1]: Main active num: one
    // [0]: Sub active num: one
    ScalerSetBit(P0_2E_VIDEO_DISPLAY_CONTROL_REG1, ~(0x1F), (_BIT4 | _BIT3));

    // Adjust OSD Position, apply D before adjust OSD position
    // Frame sync line buffer need to fine tune Dclk according I-active-region & D-active-region
    if((usVBackStartOld != GET_MDOMAIN_OUTPUT_VBSTART()) ||
       (usHStartOld != GET_MDOMAIN_OUTPUT_HSTART()) ||
       ((usVHeightOld != GET_MDOMAIN_OUTPUT_VHEIGHT()) && (GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER)))
    {
        // Adjust OSD Position
        if(usVBackStartOld != GET_MDOMAIN_OUTPUT_VBSTART())
        {
            ScalerMDomainSetDBOsdFlow();
        }
        else
        {
            // DDB apply only for frame sync line buffer (for Dt)
            if(GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER)
            {
                ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);
            }
        }

        ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, _BIT7);
        GET_DVTOTAL_LASTLINE(usDVtotal);
        // show msg if current dvtotal +- dvst diff id out of panel spec
        if(((usDVtotal + abs(usVStartOld - GET_MDOMAIN_OUTPUT_VSTART())) > (_PANEL_DV_TOTAL_MAX - _PANEL_DV_TOTAL_FINE_TUNE_MARGIN)) ||
           ((usDVtotal - abs(usVStartOld - GET_MDOMAIN_OUTPUT_VSTART())) < (_PANEL_DV_TOTAL_MIN + _PANEL_DV_TOTAL_FINE_TUNE_MARGIN)))
        {
            DebugMessageFS("WARNING: Transient Dvtotal is out of spec!!!", 0);
        }
    }
}

//--------------------------------------------------
// Description  : Get Display Background Vstart
// Input Value  : None
// Output Value : Display Background Vstart
//--------------------------------------------------
WORD ScalerMDomainGetDisplayBackgroundVstart(void)
{
    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_0E_DISPLAY_VER_BG_STA_H, 2, &pData[1], _AUTOINC);
    return ((((WORD)pData[1] & 0x1F) << 8) | pData[2]);
}

//--------------------------------------------------
// Description  : Get Display Vheight
// Input Value  : None
// Output Value : Display Vheight
//--------------------------------------------------
WORD ScalerMDomainGetDisplayVheight(void)
{
    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_10_DISPLAY_VER_ACT_STA_H, 4, &pData[1], _AUTOINC);
    return (((((WORD)pData[3] & 0x1F) << 8) | pData[4]) - ((((WORD)pData[1] & 0x1F) << 8) | pData[2]));
}

#if((_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON) || (_FREESYNC_SUPPORT == _ON))
#if(_FRC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check DCLK & DVtotal margin when frame sync line buffer
// Input Value  : NA
// Output Value : Pass or fail
//--------------------------------------------------
bit ScalerMDomainFSLineBufferDclkDvtotalCheck(void)
{
    BYTE ucDpllSscgDiv = ScalerMDomainGetDpllSscgDivMode();

#if(_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _FALSE)
#endif
    {
        // Frame sync Dvtotal
        PDATA_WORD(0) = (DWORD)g_stMDomainInputData.usVTotal * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight;

        if((PDATA_WORD(0) > (_PANEL_DV_TOTAL_MAX - _PANEL_DV_TOTAL_FINE_TUNE_MARGIN)) || (PDATA_WORD(0) < (_PANEL_DV_TOTAL_MIN + _PANEL_DV_TOTAL_FINE_TUNE_MARGIN)))
        {
            return _FALSE;
        }
    }

    // Calculate DHF
    PDATA_DWORD(0) = (DWORD)g_stMDomainInputData.usHFreq * g_stMDomainOutputData.usVHeight / g_stMDomainInputData.usVHeight / 10;

    // Frame sync Dclk max
    PDATA_DWORD(1) = PDATA_DWORD(0) * _PANEL_DH_TOTAL_MAX;

    // Frame sync Dclk min
    PDATA_DWORD(2) = PDATA_DWORD(0) * _PANEL_DH_TOTAL_MIN;

    // Dclk_min > (Panel_max_clk - margin - SSCG/2)
    if(PDATA_DWORD(2) > ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ - ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ / 100) - ((DWORD)_PANEL_PIXEL_CLOCK_MAX_KHZ * _DCLK_SPREAD_RANGE * 5 / 2000 / ucDpllSscgDiv)))
    {
        return _FALSE;
    }

    // Dclk_max < (Panel_min_clk + margin + SSCG/2)
    if(PDATA_DWORD(1) < ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ + ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ / 100) + ((DWORD)_PANEL_PIXEL_CLOCK_MIN_KHZ * _DCLK_SPREAD_RANGE * 5 / 2000 / ucDpllSscgDiv)))
    {
        return _FALSE;
    }

    return _TRUE;
}
#endif // End of #if(_FRC_SUPPORT == _ON)
#endif // End of #if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Get D-Domain PLL SSCG Divider Mode
// Input Value  : None
// Output Value : DPLL SSCG DIV NUM
//--------------------------------------------------
BYTE ScalerMDomainGetDpllSscgDivMode(void)
{
#if(_PANEL_STYLE == _PANEL_VBO)
    return _DIV_8;
#else
    return _DIV_1;
#endif
}

//--------------------------------------------------
// Description  : Check Display Format
// Input Value  : NA
// Output Value : NA
//--------------------------------------------------
void ScalerMDomainCheckDisplayFormat(void)
{
    // Check display format resolution to be even
    SET_MDOMAIN_OUTPUT_VSTART((GET_MDOMAIN_OUTPUT_VSTART() + 1) & 0xFFFE);
    SET_MDOMAIN_OUTPUT_VBSTART((GET_MDOMAIN_OUTPUT_VBSTART() + 1) & 0xFFFE);
    SET_MDOMAIN_OUTPUT_VHEIGHT((GET_MDOMAIN_OUTPUT_VHEIGHT() + 1) & 0xFFFE);
    SET_MDOMAIN_OUTPUT_VBHEIGHT((GET_MDOMAIN_OUTPUT_VBHEIGHT() + 1) & 0xFFFE);

#if(_PANEL_STYLE == _PANEL_LVDS)
    // Check display format resolution according to LVDS port count
    SET_MDOMAIN_OUTPUT_HSTART(GET_MDOMAIN_OUTPUT_HSTART() - (GET_MDOMAIN_OUTPUT_HSTART() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HWIDTH(GET_MDOMAIN_OUTPUT_HWIDTH() - (GET_MDOMAIN_OUTPUT_HWIDTH() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HBSTART(GET_MDOMAIN_OUTPUT_HBSTART() - (GET_MDOMAIN_OUTPUT_HBSTART() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
    SET_MDOMAIN_OUTPUT_HBWIDTH(GET_MDOMAIN_OUTPUT_HBWIDTH() - (GET_MDOMAIN_OUTPUT_HBWIDTH() % ((BYTE)1 << _LVDS_OUTPUT_PORT)));
#else
    SET_MDOMAIN_OUTPUT_HSTART((GET_MDOMAIN_OUTPUT_HSTART() + 1) & 0xFFFE);
    SET_MDOMAIN_OUTPUT_HBSTART((GET_MDOMAIN_OUTPUT_HBSTART() + 1) & 0xFFFE);
    SET_MDOMAIN_OUTPUT_HWIDTH((GET_MDOMAIN_OUTPUT_HWIDTH() + 1) & 0xFFFE);
    SET_MDOMAIN_OUTPUT_HBWIDTH((GET_MDOMAIN_OUTPUT_HBWIDTH() + 1) & 0xFFFE);
#endif
}

//--------------------------------------------------
// Description  : Decide which scaling function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerMDomainSetScaling(const StructSDRAMDataInfo *pstFIFOScaling)
{
    ScalerScalingSetScalingDown(pstFIFOScaling);

    ScalerScalingSetScalingUp(pstFIFOScaling);
}

//--------------------------------------------------
// Description  : Select memory confirm
// Input Value  : NA
// Output Value : free run/ frame sync line buffer/ frame sync frame buffer / MN frame sync/ free run no input
//--------------------------------------------------
BYTE ScalerMDomainMemorySelectConfirm(void)
{
    switch(GET_MEMORY_CONFIG())
    {
        case _LINE_BUFFER_MODE:

            return _FRAME_SYNC_LINE_BUFFER;

#if(_FRC_SUPPORT == _ON)
        case _MEMORY_WORK_MODE:

            switch(GET_MEMORY_DVF_SELECT())
            {
                case _1_IVF:

                    return _FRAME_SYNC_MEMORY;

                case _3_IVF:
                case _2_5_IVF:
                case _2_IVF:
#if(_DISPLAY_ROTATION_SUPPORT == _ON)
#if((_DISPLAY_ROTATION_TYPE == _DISPLAY_ROTATION_GEN_II) && (_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON))
                case _5_4_IVF:
                case _6_5_IVF:
#endif
#endif
                    return _MN_FRAME_SYNC_MEMORY;

                default:
                case _PANEL_TYP_FRAME_RATE_FREE_RUN:

                    return _FREE_RUN_MEMORY;
            }
#endif

        default:

            return _FRAME_SYNC_LINE_BUFFER;
    }
}

//--------------------------------------------------
// Description  : Set Memory Data Bit
// Input Value  : ucColorDepth
// Output Value : None
//--------------------------------------------------
void ScalerMDomainSetMemoryDataBit(BYTE ucColorDepth)
{
    if((ucColorDepth * 3) >= _M_DOMAIN_DATA_BIT_MAX)
    {
        SET_MEMORY_DATA_BIT(_M_DOMAIN_DATA_BIT_MAX);
    }
    else
    {
        SET_MEMORY_DATA_BIT(_COLOR_DEPTH_8_BITS * 3);
    }
}

//--------------------------------------------------
// Description  : Calculate I/D domain V adjust limitation
// Input Value  : input source type
// Output Value : vertical adjust limit for IV delay
//--------------------------------------------------
WORD ScalerMDomainGetVerticalAdjustLimit(EnumSourceTypeDef enumSourceTypeDef)
{
    WORD usAdjustLimit = 0x0001;

    enumSourceTypeDef = enumSourceTypeDef;

    // Calculate I-domain limitation; Safe New V-Delay value must larger than DEN falling edge position plus 3 lines
#if(_VGA_SUPPORT == _ON)
    if(enumSourceTypeDef == _SOURCE_VGA)
    {
        if(GET_INPUT_TIMING_VTOTAL() > (GET_INPUT_TIMING_VHEIGHT() + ScalerVgaTopGetCaptureVStartPosition() + 3))
        {
            usAdjustLimit = (GET_INPUT_TIMING_VTOTAL() - (GET_INPUT_TIMING_VHEIGHT() + ScalerVgaTopGetCaptureVStartPosition() + 3));
        }
    }
    else
#endif
    {
        if(GET_INPUT_TIMING_VTOTAL() > (GET_INPUT_TIMING_VHEIGHT() + ScalerVgipGetCaptureVStartPosition() + 3))
        {
            usAdjustLimit = (GET_INPUT_TIMING_VTOTAL() - (GET_INPUT_TIMING_VHEIGHT() + ScalerVgipGetCaptureVStartPosition() + 3));
        }
    }

#if((_PANEL_STYLE == _PANEL_DPTX) || (_PANEL_STYLE == _PANEL_VBO))

    // Check D-domain limitation only for non-free-run case
    if(GET_MEMORY_SELECT() != _FREE_RUN_MEMORY)
    {
        // Calculate D-domain limitation
        WORD usDdomainLimit = (WORD)((DWORD)(GET_MDOMAIN_OUTPUT_VTOTAL() - GET_MDOMAIN_OUTPUT_VHEIGHT() - GET_MDOMAIN_OUTPUT_VSTART()) * GET_MDOMAIN_INPUT_VTOTAL() / GET_MDOMAIN_OUTPUT_VTOTAL() - 1);

        if(usDdomainLimit < usAdjustLimit)
        {
            usAdjustLimit = usDdomainLimit;
        }

        // Update adjust limit for MN tracking
        if(GET_MEMORY_SELECT() == _MN_FRAME_SYNC_MEMORY)
        {
            switch(GET_MEMORY_DVF_SELECT())
            {
                case _3_IVF:
                    usAdjustLimit /= 3;
                    break;

                case _2_5_IVF:
                    usAdjustLimit = (usAdjustLimit * 2 / 5);

                    // For 2 successive IVS
                    usAdjustLimit /= 2;
                    break;

                case _2_IVF:
                    usAdjustLimit /= 2;
                    break;

                default:
                    break;
            }
        }

        // Keep at least one line for adjusting V-Position; otherwise take 2 lines as margin
        if(usAdjustLimit < 0x0003)
        {
            usAdjustLimit = 0x0001;
        }
        else
        {
            usAdjustLimit -= 0x0002;
        }
    }
#endif

    // Avoid Lost Frame-Sync DVS
    if(GET_MEMORY_DVF_SELECT() == _1_IVF)
    {
        WORD usIvs2dvsDelay = ((((WORD)ScalerGetByte(P0_3E_IVS2DVS_DLY_LINE_H) & 0x01F) << 8) | ScalerGetByte(P0_40_IVS2DVS_DLY_LINE_L));
        WORD usIvs2dvsDelayLimit = 0;
        WORD usIvDelay = 0;

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
        if(ScalerFmtCnvFtoPGetStatus() == _TRUE)
        {
            usIvs2dvsDelay = usIvs2dvsDelay << 1;
        }
#endif

#if(_VGA_SUPPORT == _ON)
        if(enumSourceTypeDef == _SOURCE_VGA)
        {
            usIvDelay = ScalerVgaTopGetCaptureVDelay();
        }
        else
#endif
        {
            usIvDelay = ScalerVgipGetCaptureVDelay();
        }

        // Check IVS_Delay change from larger to smaller
        if((GET_INPUT_TIMING_VTOTAL() - usIvDelay) < (usIvs2dvsDelay + 4)) // 4 line margin
        {
            usIvs2dvsDelayLimit = ((usIvs2dvsDelay + 4) - (GET_INPUT_TIMING_VTOTAL() - usIvDelay));

            if(usIvDelay > usIvs2dvsDelayLimit)
            {
                usIvs2dvsDelayLimit = usIvDelay - usIvs2dvsDelayLimit;

                if(usIvs2dvsDelayLimit < usAdjustLimit)
                {
                    usAdjustLimit = usIvs2dvsDelayLimit;
                }
            }
        }
    }

    DebugMessageScaler("V adj. limit", usAdjustLimit);

    return usAdjustLimit;
}

//--------------------------------------------------
// Description  : Measure Display Active Region in Display Setting
// Input Value  : void
// Output Value : Display Avtive Region
//--------------------------------------------------
DWORD ScalerMDomainGetDisplayActiveRegion(void)
{
    bit bChangeDVStartStatus = _FALSE;
    WORD usIvs2dvsDelay = 0;
    WORD usDVTotal = 0;
    DWORD ulDisplayActiveRegion = 0;

#if(_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _ENABLE)
    {
        bChangeDVStartStatus = _TRUE;
    }
    else
#endif
    {
        // Measure DVtotal in frame sync mode
        ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT5, 0x00);
        ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, _BIT7);

        ScalerTimerWaitForEvent(_EVENT_DVS);
        ScalerTimerWaitForEvent(_EVENT_DVS);

        // Get DVTotal Result
        GET_DVTOTAL_LASTLINE(usDVTotal);

        // Get Ivs2dvsdelay
        usIvs2dvsDelay = ScalerMemoryGetIVS2DVSDelayPixel() / GET_MDOMAIN_INPUT_HTOTAL() * GET_MDOMAIN_OUTPUT_VHEIGHT() / GET_MDOMAIN_INPUT_VHEIGHT();

        DebugMessageFS("usIvs2dvsDelay", usIvs2dvsDelay);
        DebugMessageFS("DVT", usDVTotal);
        DebugMessageFS("DVS", GET_MDOMAIN_OUTPUT_VSTART());

        // Check DVT < Ivs2dvsdelay + DVStart + DVHeigth
        bChangeDVStartStatus = ((usDVTotal < (usIvs2dvsDelay + GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT() + 2)) ? (_TRUE) : (_FALSE)); // 2 line margin
    }

    if(bChangeDVStartStatus == _TRUE)
    {
        // Set Main1 VHeight / 2
        SET_D_DOMAIN_V_ACT_END(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT() / 2);

        // Apply DB
        ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);
    }

    // Set Measure Display Active Region
    ScalerMeasureSetDisplayRegionCount(_ACTIVE_REGION_TYPE);

    // Read Active Region Result
    ulDisplayActiveRegion = ScalerMeasureGetDisplayRegionCountResult(_WAIT);

    if(bChangeDVStartStatus == _TRUE)
    {
        // Get H HBlanking
        PDATA_WORD(0) = GET_MDOMAIN_OUTPUT_HTOTAL() - GET_MDOMAIN_OUTPUT_HWIDTH();

        // Calculate full-frame count = half-frame count * (Htotal * Vheight/2 - Hblanking) / (Htotal * Vheight - Hblanking)
        ulDisplayActiveRegion = GET_DWORD_MUL_DIV(ulDisplayActiveRegion, ((DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() * GET_MDOMAIN_OUTPUT_HTOTAL() - PDATA_WORD(0)), ((DWORD)GET_MDOMAIN_OUTPUT_VHEIGHT() / 2 * GET_MDOMAIN_OUTPUT_HTOTAL() - PDATA_WORD(0)));

        // Set Main1 V Active st/ ed
        SET_D_DOMAIN_V_ACT_END(GET_MDOMAIN_OUTPUT_VSTART() + GET_MDOMAIN_OUTPUT_VHEIGHT());

        // Apply DB
        ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);
    }

    DebugMessageFS("bChangeDVStartStatus", bChangeDVStartStatus);

    return ulDisplayActiveRegion;
}

//--------------------------------------------------
// Description  : Check Display Timing Gen
// Input Value  : None
// Output Value : TRUE: Pass
//--------------------------------------------------
bit ScalerMDomainDisplayTimingGenCheck(void)
{
#if(_FREESYNC_SUPPORT == _ON)
    if((GET_FREESYNC_ENABLED() == _TRUE) &&
       ((GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER) || (GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY)))
    {
        WORD usDVtotal = GET_MDOMAIN_OUTPUT_VTOTAL();

        // Measure DVtotal in frame sync mode
        ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT5, 0x00);
        ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, _BIT7);

        GET_SAFE_DVTOTAL_LASTLINE(usDVtotal);
        SET_MDOMAIN_OUTPUT_VTOTAL(usDVtotal);

        // Check DV_BG_End > DVtotal
        if((GET_MDOMAIN_OUTPUT_VBSTART() + GET_MDOMAIN_OUTPUT_VBHEIGHT()) > GET_MDOMAIN_OUTPUT_VTOTAL())
        {
            DebugMessageScaler("DVBG end > DVtotal", usDVtotal);
            return _FALSE;
        }
    }
#endif

    return _TRUE;
}
#if(_I_DITHER_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get Color Depth
// Input Value  : None
// Output Value : M domain use Color Depth
//--------------------------------------------------
BYTE ScalerMDomainGetColorDepth(void)
{
    return (GET_MEMORY_DATA_BIT() / 3);
}
#endif

#if(_ASPECT_ORIGINAL_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Enable/Disable
// Input Value  :
// Output Value : None
//--------------------------------------------------
void ScalerMDomainAspectOriginMode(bit bOn)
{
    SET_ASPECT_ORIGIN_MODE(bOn);
}
#endif

#if(_OD_SUPPORT == _ON)
//--------------------------------------------------
// Description  : If memory is not enough for OD, disable OD
// Input Value  : Input timing for cal FRC memory size
// Output Value : None
//--------------------------------------------------
void ScalerMDomainODConfig(void)
{
#if(_FRC_SUPPORT == _ON)
    WORD usFRCSpace = 0;
    WORD usFRCBW = 0;
    DWORD ulAvailMemRow = _MEMORY_ROW; // Available Memory Row
#endif

    SET_OD_USE_BIT(_OFF);

    switch(GET_MEMORY_CONFIG())
    {
        case _LINE_BUFFER_MODE:
            SET_OD_USE_BIT(ScalerODGetCompressionBitNum(_MEMORY_ROW, _MEMORY_TOTAL_BW));
            break;

#if(_FRC_SUPPORT == _ON)
        case _MEMORY_WORK_MODE:
            usFRCSpace = ScalerMDomainGetFRCMemorySpace();
            usFRCBW = ScalerMDomainGetFRCMemoryBW();

            switch(GET_MEMORY_FRAME_BUFFER())
            {
                case _MEMORY_1_5_FRAME_BUFFER:
                    ulAvailMemRow = (DWORD)_MEMORY_ROW * 2 / 3;
                    break;

                case _MEMORY_2_FRAME_BUFFER:
                    usFRCSpace *= 2;
                    break;

                case _MEMORY_3_FRAME_BUFFER:
                    usFRCSpace *= 3;
                    break;

                case _MEMORY_1_FRAME_BUFFER:
                default:
                    break;
            }

            if((usFRCSpace < ulAvailMemRow) && (usFRCBW < _MEMORY_TOTAL_BW))
            {
                // Check available OD use bit
                SET_OD_USE_BIT(ScalerODGetCompressionBitNum((ulAvailMemRow - usFRCSpace), (_MEMORY_TOTAL_BW - usFRCBW)));
            }

            DebugMessageFRC("4. FRC BW", usFRCBW);
            DebugMessageFRC("4. FRC Size", usFRCSpace);
            break;
#endif // End of #if(_FRC_SUPPORT == _ON)

        default:
            break;
    }

    DebugMessageFRC("4. OD bit", GET_OD_USE_BIT());
}

//--------------------------------------------------
// Description  : Calculate memory use space
// Input Value  : OD use bit(10x) ucODbit = real ODbit x 10, 6.5bit OD --> ucODbit = 65
// Output Value : OD memory use space, unit:row
//--------------------------------------------------
WORD ScalerMDomainODCalculateMemoryUseSpace(BYTE ucODbit)
{
    //***************************************************//
    // Column = Column_per_bank * memory_bank
    // Row = Total memory unit / column
    //***************************************************//

    // OD memory size, unit:row
    return ((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * _PANEL_DV_HEIGHT * ucODbit / _MEMORY_BIT_NUM) /
            (_MEMORY_COL_PER_BANK * _MEMORY_BANK) / 10 + 1);
}

//--------------------------------------------------
// Description  : Calculate memory use BW
// Input Value  : OD use bit(10x)
// Output Value : OD memory use BW, unit:100k
//--------------------------------------------------
WORD ScalerMDomainODCalculateMemoryUseBW(BYTE ucODbit)
{
    BYTE ucDpllSscgDiv = ScalerMDomainGetDpllSscgDivMode();

    PDATA_DWORD(0) = (((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * g_stMDomainOutputData.usVTotal * ucODbit * 2 / _MEMORY_BUS_WIDTH / 100) * g_usDVFreq / 10) +
                      (((((DWORD)CEILING(_PANEL_DH_WIDTH, _OD_PIXEL_PER_COMP)) * g_stMDomainOutputData.usVTotal * ucODbit * 2 / _MEMORY_BUS_WIDTH / 100) * g_usDVFreq / 10) * ((_DCLK_SPREAD_RANGE / ucDpllSscgDiv) + _DCLK_SPREAD_RANGE_MARGIN) / 4 / 100));

    PDATA_DWORD(0) = (PDATA_DWORD(0) / 10000) + ((PDATA_DWORD(0) % 10000) ? 1 : 0); // unit:100k

    DebugMessageFRC("4.OD use BW", (PDATA_DWORD(0)));

    return (PDATA_DWORD(0) & 0xFFFF);
}
#endif // End of #if(_OD_SUPPORT == _ON)

#if(((_FRC_SUPPORT == _ON) && (_OD_SUPPORT == _ON)) || (_DISP_LATENCY_ADJUST_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Calculate FRC use memory space
// Input Value  : IVheight and IHwidth
// Output Value : FRC use memory space, unit: row
//--------------------------------------------------
WORD ScalerMDomainGetFRCMemorySpace(void)
{
    WORD usMemoryFRCSpace = 0;
    DWORD ulLineStep = 0;
    WORD usHwidth = 0;
    WORD usVheight = 0;

    //-----------------------------------------
    // Column = Column_per_bank * memory_bank
    // Row = Total memory unit / column
    //-----------------------------------------
    usHwidth = ((g_stMDomainInputData.usHWidth < g_stMDomainOutputData.usHWidth) ? g_stMDomainInputData.usHWidth : g_stMDomainOutputData.usHWidth);
    usVheight = ((g_stMDomainInputData.usVHeight < g_stMDomainOutputData.usVHeight) ? g_stMDomainInputData.usVHeight : g_stMDomainOutputData.usVHeight);

    ulLineStep = ScalerMemoryCalculateFrameLineTotalPixel(_MEMORY_ACCESS_TYPE, usHwidth, usVheight);

    if(_MEMORY_ACCESS_TYPE == _LINE_MODE)
    {
        // 10*row
        usMemoryFRCSpace = (ulLineStep * usVheight * 10 / (_MEMORY_COL_PER_BANK * _MEMORY_BANK));
    }
    else
    {
        // 10*row
        usMemoryFRCSpace = (ulLineStep * 10 / (_MEMORY_COL_PER_BANK * _MEMORY_BANK));
    }

    // unit:row
    usMemoryFRCSpace = (usMemoryFRCSpace % 10) ? (usMemoryFRCSpace / 10 + 1) : (usMemoryFRCSpace / 10);
    return usMemoryFRCSpace;
}

//--------------------------------------------------
// Description  : Calculate FRC use memory BW
// Input Value  : IVF, IVheight and IHwidth
// Output Value : FRC use memory BW, unit: 100k
//--------------------------------------------------
WORD ScalerMDomainGetFRCMemoryBW(void)
{
    BYTE ucDpllSscgDiv = ScalerMDomainGetDpllSscgDivMode();
    WORD usIVtotal = 0;

    //-----------------------------------------------------------------------------
    // FRC write BW = IVtotal * Fifo_width * Bit_Num / Memory_Bus_bit * IVF
    // FRC read BW  = DVtotal * Fifo_width * Bit_Num / Memory_Bus_bit * DVF * (1 + (SSCG_Range + margin) / 2)
    //-----------------------------------------------------------------------------

    PDATA_WORD(0) = ((g_stMDomainInputData.usHWidth < g_stMDomainOutputData.usHWidth) ? g_stMDomainInputData.usHWidth : g_stMDomainOutputData.usHWidth);

#if(_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        usIVtotal = (DWORD)g_stMDomainInputData.usVHeight * 105 / 100;
    }
    else
#endif
    {
        usIVtotal = g_stMDomainInputData.usVTotal;
    }

    // FRC write BW x Multiple
    PDATA_DWORD(1) = (((DWORD)usIVtotal * PDATA_WORD(0) * GET_MEMORY_DATA_BIT() / _MEMORY_BUS_WIDTH / 10) * g_stMDomainInputData.usVFreq / 100) * _FRC_WRITE_BW_MULTIPLE;

    // FRC read BW
    PDATA_DWORD(2) = ((((DWORD)g_stMDomainOutputData.usVTotal * PDATA_WORD(0) * GET_MEMORY_DATA_BIT() / _MEMORY_BUS_WIDTH / 10) * g_usDVFreq / 100) +
                      (((DWORD)g_stMDomainOutputData.usVTotal * PDATA_WORD(0) * GET_MEMORY_DATA_BIT() / _MEMORY_BUS_WIDTH / 100) * g_usDVFreq * ((_DCLK_SPREAD_RANGE / ucDpllSscgDiv) + _DCLK_SPREAD_RANGE_MARGIN) / 4 / 100 / 10));

    // unit:100k
    PDATA_DWORD(0) = ((PDATA_DWORD(1) + PDATA_DWORD(2)) / 1000) + (((PDATA_DWORD(1) + PDATA_DWORD(2)) % 1000) ? 1 : 0);

    return (PDATA_DWORD(0) & 0xFFFF);
}
#endif // End of #if(((_FRC_SUPPORT == _ON) && (_OD_SUPPORT == _ON)) || (_DISP_LATENCY_ADJUST_SUPPORT == _ON))

//--------------------------------------------------
// Description  : Apply DdomainDB before set OSD
// Input Value  : ucHOffset,ucVOffset
// Output Value : None
//--------------------------------------------------
void ScalerMDomainSetDBOsdFlow(void)
{
    BYTE ucHOffset = 0;
    BYTE ucVOffset = 0;

#if(_OSD_POSITION_OFFSET_CORRECTION == _ON)
    WORD usHVOffset = ScalerOsdPositionOffsetCalculation();
    ucHOffset = X_POS(HIBYTE(usHVOffset));
    ucVOffset = Y_POS(LOBYTE(usHVOffset));

#else
    ucHOffset = X_POS(GET_OSD_POSITION_GOLOBAL_OFFSET_H());
    ucVOffset = Y_POS(GET_OSD_POSITION_GOLOBAL_OFFSET_V());

    SET_OSD_POSITION_GOLOBAL_OFFSET_H(ucHOffset);
    SET_OSD_POSITION_GOLOBAL_OFFSET_V(ucVOffset);

    ucVOffset = ScalerOsdPositionOffsetVerticalAlignByDVBGStart(ucVOffset);
#endif
    // do calculation before apply DDB (to save time)
    ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);

    ScalerSetByte(P3A_2C_FRAME_CTRL_2C, ucVOffset);
    ScalerSetByte(P3A_2F_FRAME_CTRL_2F, ucHOffset);
}

