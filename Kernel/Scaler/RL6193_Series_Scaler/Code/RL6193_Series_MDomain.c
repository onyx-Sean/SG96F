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
// ID Code      : RL6193_Series_MDomain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

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

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMDomainControlDBApply(void);
bit ScalerMDomainMemoryCheck(void);
void ScalerMDomainSetDisplayFormat(BYTE ucMemorySel);

#if(_FREESYNC_OD_MEASURE == _ON)
void ScalerMDomainFREESYNCODSetDisplayFormat(WORD usDHtotal, DWORD ulDclk, WORD usTarFreq);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Special Double Buffer Apply Procedure for FS
// Input Value  : None
// Output Value : None
// Note : Only for Frame Sync case
//--------------------------------------------------
void ScalerMDomainControlDBApply(void)
{
    bit bFreeRunEn = _FALSE;

    // Enable double buffer
    if((GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER) || (GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY) || (GET_MEMORY_SELECT() == _MN_FRAME_SYNC_MEMORY))
    {
        if(ScalerGetBit(P0_10_M1_VGIP_CTRL, _BIT1) == _BIT1)
        {
            // Avoid (Current_IVStart + IVHeight) > IVToal + New_IVSDelay in digital capture
            PDATA_WORD(0) = (g_stInputTimingData.usVStart + ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight);
        }
        else
        {
            // Avoid (Current_IVSDelay + IVStart + IVHeight) > IVToal + New_IVSDelay in analog capture
            PDATA_WORD(0) = (ScalerVgipGetCaptureVDelay() + ScalerVgipGetCaptureVStartPosition() + g_stMDomainInputData.usVHeight);
        }

#if(_FREESYNC_SUPPORT == _ON)
        if(GET_FREESYNC_ENABLED() == _TRUE)
        {
            bFreeRunEn = (PDATA_WORD(0) > ((DWORD)g_stMDomainInputData.usVHeight * 105 / 100)) ? (_TRUE) : (_FALSE);
        }
        else
#endif
        {
            bFreeRunEn = (PDATA_WORD(0) > g_stMDomainInputData.usVTotal) ? (_TRUE) : (_FALSE);
        }

        if(bFreeRunEn == _TRUE)
        {
            ScalerTimerWaitForEvent(_EVENT_DEN_START);

            // Set Free run
            ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, 0x00);

            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, ~_BIT7, 0x00);
        }

        ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);

        if(bFreeRunEn == _TRUE)
        {
            switch(GET_MEMORY_DVF_SELECT())
            {
                case _1_IVF:
                    ScalerTimerWaitForEvent(_EVENT_IVS);
                    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                    // Set Frame sync
                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, _BIT3);
                    break;

                case _2_IVF:
                case _3_IVF:
                    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_27_N_FOR_MN_FRAME_RATE, 1, &pData[15], _NON_AUTOINC);

                    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
                    ScalerTimerWaitForEvent(_EVENT_IVS);

                    while(pData[15] > 0)
                    {
                        pData[15] --;
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                    }
                    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, _BIT3);
                    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, ~_BIT7, _BIT7);
                    break;

                case _2_5_IVF:
                    // Measure DVtotal in current mode
                    ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT5, _BIT5);
                    ScalerSetBit(P0_44_LAST_LINE_H, ~_BIT7, _BIT7);

                    // Get N frame
                    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_27_N_FOR_MN_FRAME_RATE, 1, &pData[15], _NON_AUTOINC);

                    // Get free run DVtotal
                    GET_FREE_RUN_DVTOTAL(PDATA_WORD(6));

                    ScalerTimerWaitForEvent(_EVENT_IEN_STOP);
                    ScalerTimerWaitForEvent(_EVENT_IVS);

                    GET_DVTOTAL_LASTLINE(PDATA_WORD(0));

                    if(PDATA_WORD(0) < (PDATA_WORD(6) * 7 / 10))
                    {
                        while(pData[15] > 0)
                        {
                            pData[15] --;
                            ScalerTimerWaitForEvent(_EVENT_DEN_START);
                        }
                    }
                    else
                    {
                        ScalerTimerWaitForEvent(_EVENT_DEN_START);
                    }

                    ScalerTimerWaitForEvent(_EVENT_DEN_STOP);

                    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, _BIT3);
                    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, ~_BIT7, _BIT7);
                    ScalerSetBit(P0_43_FS_DELAY_FINE_TUNE, ~_BIT5, 0x00);
                    break;

                default:
                    break;
            }
        }
    }
    else
    {
        ScalerGlobalIDomainDBApply(_DB_APPLY_POLLING);
    }
    ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);
}

//--------------------------------------------------
// Description  : Check memory
// Input Value  : None
// Output Value : Memory check pass or fail
//--------------------------------------------------
bit ScalerMDomainMemoryCheck(void)
{
    // Check fifo underflow and Input HVsync error flag, Display Vsync timeout flag
    if((ScalerGetBit(P0_02_STATUS0, (_BIT6 | _BIT5 | _BIT0)) != 0x00) ||
       (ScalerGetBit(P0_0C_WATCH_DOG_CTRL0, _BIT0) != 0x00))
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Set Display Format
// Input Value  : free run/ frame sync line buffer/ frame sync frame buffer /
//                MN frame sync/ free run no input
// Output Value : NA
//--------------------------------------------------
void ScalerMDomainSetDisplayFormat(BYTE ucMemorySel)
{
    WORD usFreeRunDVtotal = 0;
    WORD usWatchDogDVtotal = 0;
    DWORD ulDclk = 0;
    StructDHVtotal stHVTotal;

#if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON)
    WORD usDhtotalBackup = 0;

    ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_00_DISPLAY_HOR_TOTAL_H, 2, &pData[0], _AUTOINC);
    usDhtotalBackup = PDATA_WORD(0) & 0x1FFF;
#endif

    if(GET_MDOMAIN_OUTPUT_VBHEIGHT() == GET_MDOMAIN_OUTPUT_VHEIGHT())
    {
        SET_MDOMAIN_OUTPUT_VBSTART(GET_MDOMAIN_OUTPUT_VSTART());
    }

#if(_DISPLAY_ROTATION_SUPPORT == _ON)
    if(GET_ROT_TYPE() != _ROT_DISABLE)
    {
        SET_MDOMAIN_OUTPUT_VBSTART(_PANEL_DV_START);
    }
#endif

    if((ucMemorySel == _MN_FRAME_SYNC_MEMORY) &&
       (ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, _BIT7) == _BIT7))
    {
        ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_00_DISPLAY_HOR_TOTAL_H, 2, &pData[4], _AUTOINC);
        SET_MDOMAIN_OUTPUT_HTOTAL((PDATA_WORD(2) & 0x1FFF) + 4);
    }

    // Display timing gen setting
    ScalerMDomainSetDisplayTimingGen();

    switch(ucMemorySel)
    {
        case _FRAME_SYNC_LINE_BUFFER:

            // Set DVTotal
            PDATA_WORD(2) = (DWORD)g_stMDomainInputData.usVTotal * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight;

#if(_FREESYNC_SUPPORT == _ON)
            if(GET_FREESYNC_ENABLED() == _TRUE)
            {
                // DVtotal for WD setting
                usWatchDogDVtotal = _PANEL_DV_TOTAL_MAX + 64;

                // DVtotal for free run setting
                usFreeRunDVtotal = _PANEL_DV_TOTAL_MAX;
            }
            else
#endif
            {
                // DVtotal for WD setting
                usWatchDogDVtotal = PDATA_WORD(2) + 64;

                // DVtotal for free run setting
                usFreeRunDVtotal = PDATA_WORD(2);
            }

            // Enable Display Timing, Set Frame sync
            ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

            // Calculate Dclk
            // PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * (DWORD)g_stMDomainInputData.usHFreq * (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight / 10;
            PDATA_DWORD(0) = (DWORD)(g_stMDomainOutputData.usHTotal) * (DWORD)g_stMDomainInputData.usHFreq / 10; /** (DWORD)(g_stMDomainOutputData.usVHeight) / g_stMDomainInputData.usVHeight / 10; */
            PDATA_DWORD(0) = PDATA_DWORD(0) / g_stMDomainInputData.usVHeight;
            ulDclk = PDATA_DWORD(0) * (DWORD)(g_stMDomainOutputData.usVHeight);

            break;

#if(_FRC_SUPPORT == _ON)

        case _MN_FRAME_SYNC_MEMORY:

            // DVtotal for WD setting
            usWatchDogDVtotal = _PANEL_DV_TOTAL + 64;

            // DVtotal for free run setting
            usFreeRunDVtotal = usWatchDogDVtotal + 1;

            // Calculate Dclk
            ulDclk = (DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * _PANEL_DV_TOTAL / 10 * g_usDVFreq / 1000;

            break;

        case _FRAME_SYNC_MEMORY:

#if(_FREESYNC_SUPPORT == _ON)
            if(GET_FREESYNC_ENABLED() == _TRUE)
            {
                if((ScalerMDomainFSLineBufferDclkDvtotalCheck() == _TRUE) &&
                   (g_stMDomainOutputData.usVBackHeight == g_stMDomainOutputData.usVHeight))
                {
                    // According Frame sync line buffer to Calculate Dclk
                    ulDclk = (DWORD)g_stMDomainOutputData.usHTotal * g_stMDomainInputData.usHFreq / 10 / g_stMDomainInputData.usVHeight * g_stMDomainOutputData.usVHeight;
                }
                else
                {
                    // Calculate Dclk
                    ulDclk = (((DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * _PANEL_DV_TOTAL) + _LAST_LINE_TARGET) / 10 * g_usDVFreq / 1000;
                }

                // DVtotal for WD setting
                usWatchDogDVtotal = _PANEL_DV_TOTAL_MAX + 64;
            }
            else
#endif
            {
                // Calculate Dclk
                ulDclk = (((DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * _PANEL_DV_TOTAL) + _LAST_LINE_TARGET) / 10 * g_usDVFreq / 1000;

                // DVtotal for WD setting
                usWatchDogDVtotal = _PANEL_DV_TOTAL + 64;
            }

            // DVtotal for free run setting
            usFreeRunDVtotal = usWatchDogDVtotal + 1;

            break;

        case _FREE_RUN_MEMORY:

            if((GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER) && (g_stMDomainOutputData.usVHeight == _PANEL_DV_HEIGHT) && (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE))
            {
                PDATA_WORD(2) = ScalerFRCSetOneFrameDVTotal();
            }
            else if((GET_MEMORY_FRAME_BUFFER() == _MEMORY_1_FRAME_BUFFER) && (((g_stMDomainOutputData.usVHeight < _PANEL_DV_HEIGHT) && (g_stMDomainInputData.usVFreq > _PANEL_MAX_FRAME_RATE)) || (g_stMDomainInputData.usVFreq < _PANEL_MIN_FRAME_RATE)))
            {
                PDATA_WORD(2) = _PANEL_DV_TOTAL_MIN;
            }
            else
            {
                PDATA_WORD(2) = _PANEL_DV_TOTAL;
            }

            // DVtotal for WD setting
            usWatchDogDVtotal = PDATA_WORD(2) + 64;

            // DVtotal for free run setting
            usFreeRunDVtotal = PDATA_WORD(2);

            // Calculate Dclk
            ulDclk = (DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * PDATA_WORD(2) / 10 * g_usDVFreq / 1000;

            break;

#endif // End of #if(_FRC_SUPPORT == _ON)

        case _FREE_RUN_NO_INPUT:
        default:

            // PDATA_WORD(2): Calculate DVtotal
            PDATA_WORD(2) = GET_MDOMAIN_OUTPUT_VTOTAL();

            // DVtotal for WD setting
            usWatchDogDVtotal = PDATA_WORD(2) + 64;

            // DVtotal for free run setting
            usFreeRunDVtotal = PDATA_WORD(2) + 1;

            // Enable Display Timing, and enable free run mode
            ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~(_BIT7 | _BIT3 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));

            // Disable M:N frame sync mode
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, ~_BIT7, 0x00);

            // Calculate Dclk
            ulDclk = (DWORD)_PANEL_DH_TOTAL * _PANEL_DV_TOTAL / 10 * _PANEL_TYP_FRAME_RATE / 1000;

            break;
    }

#if(_FRC_SUPPORT == _ON)
    // M:N case reset to display setting, no need to set M:N tracking again
    if((ucMemorySel != _MN_FRAME_SYNC_MEMORY) ||
       (ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_25_MN_FRAME_RATE_EN, _BIT7) != _BIT7))
#endif
    {
        // If Dclk over panel, fine tune DHtotal, DVtotal and Dclk
        stHVTotal = ScalerMDomainDHVtotalFinetune(ulDclk, ucMemorySel);

        if((stHVTotal.usDVtotal != GET_MDOMAIN_OUTPUT_VTOTAL()) || (stHVTotal.usDHtotal != GET_MDOMAIN_OUTPUT_HTOTAL()))
        {
            if(stHVTotal.usDHtotal != GET_MDOMAIN_OUTPUT_HTOTAL())
            {
                SET_MDOMAIN_OUTPUT_HTOTAL(stHVTotal.usDHtotal);
            }

            if(stHVTotal.usDVtotal != GET_MDOMAIN_OUTPUT_VTOTAL())
            {
                SET_MDOMAIN_OUTPUT_VTOTAL(stHVTotal.usDVtotal);

                // Freesync timing, watch dog and free run DVtotal are defined Panel max, do not need to update again
#if(_FREESYNC_SUPPORT == _ON)
                if(GET_FREESYNC_ENABLED() == _FALSE)
#endif
                {
                    usWatchDogDVtotal = GET_MDOMAIN_OUTPUT_VTOTAL() + 64;
                    usFreeRunDVtotal = GET_MDOMAIN_OUTPUT_VTOTAL() + 1;
                }
            }

            ulDclk = (DWORD)GET_MDOMAIN_OUTPUT_HTOTAL() * GET_MDOMAIN_OUTPUT_VTOTAL() / 10 * g_usDVFreq / 1000;
        }

        // Set DHtotal
        ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_00_DISPLAY_HOR_TOTAL_H);
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_HTOTAL() - 4) & 0x1F));
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_HTOTAL() - 4));

        // Set Last line for free run
        ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_32_FIXED_LAST_LINE_MSB);
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(GET_MDOMAIN_OUTPUT_HTOTAL() - 4) & 0x1F));
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(GET_MDOMAIN_OUTPUT_HTOTAL() - 4));

        // Set Frame Sync Watch Dog
        ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_0B_DISPLAY_VER_TOTAL_H);
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(usWatchDogDVtotal) & 0x1F));
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(usWatchDogDVtotal));

        // Set DVtotal for free run
        ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_30_FIXED_DVTOTAL_MSB);
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(usFreeRunDVtotal) & 0x1F));
        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(usFreeRunDVtotal));

#if(_FRAME_SYNC_LINE_BUFFER_SUPPORT == _ON)
        if(GET_MEMORY_SELECT() == _FRAME_SYNC_LINE_BUFFER)
        {
            ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_00_DISPLAY_HOR_TOTAL_H, 2, &pData[0], _AUTOINC);

            // Frame sync line buffer need to fine tune Dclk according I-active-region & D-active-region
            if(usDhtotalBackup != (PDATA_WORD(0) & 0x1FFF))
            {
                ScalerGlobalDDomainDBApply(_DB_APPLY_POLLING);
            }
        }
#endif

        SET_D_CLK_FREQ(ulDclk);

        DebugMessageScaler("DCLK", GET_D_CLK_FREQ());

        // Set DClk
        ScalerPLLSetDPLLFreq(GET_D_CLK_FREQ());
    }
}

#if(_FREESYNC_OD_MEASURE == _ON)
//--------------------------------------------------
// Description  : Set Display Format for FREESYNC OD measure
// Input Value  : Current DHtotal(pixel)/ Current Dclk(kHz)/ Target Measure VFreq(0.1Hz)
// Output Value : None
//--------------------------------------------------
void ScalerMDomainFREESYNCODSetDisplayFormat(WORD usDHtotal, DWORD ulDclk, WORD usTarFreq)
{
    ScalerGlobalDoubleBufferEnable(_DISABLE);
    ScalerGlobalWatchDog(_DISABLE);

    // Calculate FREESYNC DVtotal for OD measure
    PDATA_WORD(4) = (DWORD)ulDclk * 1000 / usDHtotal * 10 / usTarFreq;

    if(PDATA_WORD(4) < _PANEL_DV_TOTAL_MIN)
    {
        PDATA_WORD(4) = _PANEL_DV_TOTAL_MIN;
    }

    // DVtotal for WD setting
    PDATA_WORD(3) = PDATA_WORD(4) + 64;

    // Set Frame Sync Watch Dog
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_0B_DISPLAY_VER_TOTAL_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(PDATA_WORD(3)) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(PDATA_WORD(3)));

    // Set DVtotal for free run
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_30_FIXED_DVTOTAL_MSB);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(PDATA_WORD(4)) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(PDATA_WORD(4)));

    // Set DHtotal
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_00_DISPLAY_HOR_TOTAL_H);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(usDHtotal - 4) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(usDHtotal - 4));

    // Set Last line for free run
    ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_32_FIXED_LAST_LINE_MSB);
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(usDHtotal - 4) & 0x1F));
    ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(usDHtotal - 4));

    SET_D_CLK_FREQ(ulDclk);

    // Set DClk
    ScalerPLLSetDPLLFreq(GET_D_CLK_FREQ());

    // Set Free Run Mode
    ScalerSetBit(P0_28_VIDEO_DISPLAY_CONTROL_REG, ~_BIT3, 0x00);

    // Clear fifo flag
    ScalerSetByte(P0_02_STATUS0, 0xFF);

    // Clear Display Vsync timeout flag
    ScalerSetBit(P0_0C_WATCH_DOG_CTRL0, ~_BIT0, _BIT0);

    ScalerTimerWaitForEvent(_EVENT_IVS);
    ScalerTimerWaitForEvent(_EVENT_IVS);
}
#endif
