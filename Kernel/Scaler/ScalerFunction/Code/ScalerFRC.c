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
// ID Code      : ScalerFRC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------
#define __SCALER_FRC__

#include "ScalerFunctionInclude.h"

#if(_FRC_SUPPORT == _ON)
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
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
BYTE g_ucDispLatecnyRatio;
#endif
#if(_ASPECT_RATIO_WITHOUT_MUTE == _ON)
WORD g_usAspectRatioMinDVHeight;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
WORD ScalerFRCGetIVS2DVSDelayMax(WORD usFRCVerSize);
#endif

WORD ScalerFRCCalculatePreReadLine(WORD usFRCVerSize);
#if(_FRC_MEMORY_2_FRAME_SUPPORT == _ON)
bit ScalerFRCCheckDoubleFrameBuffer(WORD usInputHWidth, WORD usInputVHeight);
#endif
BYTE ScalerFRCIVS2DVSDelayMargin(void);

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
void ScalerFRCSetDisplayAutoBlkToggle(void);
void ScalerFRCSetDisplayAutoBlkToggleEnable(bit bEn);
void ScalerFRCSetHWAutoBlockToggle(void);
void ScalerFRCSetInputAutoBlkToggle(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get IVS2DVSDelay Max Value in Frame Sync Mode
// Input Value  : usFRCVerSize : Input VHeight
// Output Value : IVS2DVSDelay Max Value
//--------------------------------------------------
WORD ScalerFRCGetIVS2DVSDelayMax(WORD usFRCVerSize)
{
    WORD usDHF = 0x00;
    WORD usIPeriod = 0x00;
    WORD usDStartPeriod = 0x00;

    if(GET_MEMORY_SELECT() == _FRAME_SYNC_MEMORY)
    {
        // DHFreq
        usDHF = ((DWORD)GET_D_CLK_FREQ() * 10 / g_stMDomainOutputData.usHTotal);

        // (IVStart + IDEN) Period
        usIPeriod = (g_stMDomainInputData.usVStart + g_stMDomainInputData.usVHeight);

        // Pre-read Period
        usDStartPeriod = ((DWORD)ScalerFRCCalculatePreReadLine(usFRCVerSize) * g_stMDomainInputData.usHFreq / usDHF);

        return (usIPeriod - (usDStartPeriod + _FRC_IVS2DVSDELAY_MARGIN));
    }

    return 0;
}
#endif // End of #if(_DISP_LATENCY_ADJUST_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Calculate FRC Pre-read Line
// Input Value  : usFRCVerSize --> FRC Output Vertical Size
// Output Value : The line after DVS that FRC display start to access
//--------------------------------------------------
WORD ScalerFRCCalculatePreReadLine(WORD usFRCVerSize)
{
    // preread = den_start - _PRE_READ_MEMORY x VSU factor - 1
    // VSU >= 1
    usFRCVerSize = (((DWORD)g_stMDomainOutputData.usVHeight * 10) / usFRCVerSize) * _PRE_READ_MEMORY + 1;
    usFRCVerSize = ((usFRCVerSize % 10) ? (usFRCVerSize / 10 + 1) : (usFRCVerSize / 10));

    return ((g_stMDomainOutputData.usVStart > usFRCVerSize) ? ((g_stMDomainOutputData.usVStart - usFRCVerSize)) : (0));
}

#if(_FRC_MEMORY_2_FRAME_SUPPORT == _ON)
//--------------------------------------------------
// Description  : FRC 2 Frame Buffer Case
// Input Value  : N.A.
// Output Value : _TRUE: 2 Frame Buffer
//--------------------------------------------------
bit ScalerFRCCheckDoubleFrameBuffer(WORD usInputHWidth, WORD usInputVHeight)
{
    // Consider Double Frame Size
    if(_MEMORY_ROW > ((DWORD)usInputHWidth * GET_MEMORY_DATA_BIT() / _MEMORY_BIT_NUM * usInputVHeight * 2 / _MEMORY_COL_PER_BANK / _MEMORY_BANK))
    {
        return _TRUE;
    }
    else
    {
        // (IVF/ DVF) or (DVF/ IVF) ratio > 2
        if(((g_stMDomainInputData.usVFreq > g_usDVFreq) && (g_stMDomainInputData.usVFreq > (g_usDVFreq << 1))) ||
           ((g_stMDomainInputData.usVFreq < g_usDVFreq) && ((g_stMDomainInputData.usVFreq << 1) < g_usDVFreq)))
        {
            return _TRUE;
        }
    }

    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : Calculate IVS2DVS delay margin
// Input Value  : N.A.
// Output Value : IVS2DVS delay margin
//--------------------------------------------------
BYTE ScalerFRCIVS2DVSDelayMargin(void)
{
#if(_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        // Margin need to consider Fifo margin, line buffer margin and setting margin
        // Fifo margin: FIFO size/ format/ IHwidth * 2
        pData[0] = ((DWORD)_M_DOMAMAIN_FIFO_BIT / GET_MEMORY_DATA_BIT() / g_stMDomainInputData.usHWidth);
        pData[0] += ((((DWORD)_M_DOMAMAIN_FIFO_BIT / GET_MEMORY_DATA_BIT() % g_stMDomainInputData.usHWidth) != 0x00) ? 1 : 0);

        pData[0] += (_FRC_IVS2DVSDELAY_LINE_BUFFER_MARGIN + _FRC_IVS2DVSDELAY_MARGIN_FREESYNC);
    }
    else
#endif
    {
        pData[0] = _FRC_IVS2DVSDELAY_MARGIN;
    }

    return pData[0];
}

#if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set display adderss for auto block toggle
// Input Value  : ulBlockStep --> block step(single frame input and display)
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetDisplayAutoBlkToggle(void)
{
    // 1st Read Address
    PDATA_DWORD(0) = (((DWORD)_FRC_R_1ST_BLOCK_STA_ADDR_H << 16) | ((DWORD)_FRC_R_1ST_BLOCK_STA_ADDR_M << 8) | 0x00);

#if((_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM) || (_MEMORY_TYPE_CONFIG == _MEMORY_DDR1))
    // Column = 256 :
    // Capture Column [9:0] --> 1'b0, Col[8:0]
    // Display Column [8:0]
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);
#if(_MEMORY_BANK == 2)
    // Capture Bank [1:0] --> 1'b0, Bank[0]
    // Display Bank [0]
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);
#endif
#endif

    ScalerSetBit(P5_C1_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetByte(P5_C6_MN_READ_ADDR_H, pData[1]);
    ScalerSetByte(P5_C7_MN_READ_ADDR_M, pData[2]);
    ScalerSetByte(P5_C8_MN_READ_ADDR_L, pData[3]);
    DebugMessageFRC("-D addr1 FRC", PDATA_DWORD(0));

    // 2nd Read Address
    PDATA_DWORD(0) = (((DWORD)_FRC_R_2ND_BLOCK_STA_ADDR_H << 16) | ((DWORD)_FRC_R_2ND_BLOCK_STA_ADDR_M << 8) | 0x00);

#if((_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM) || (_MEMORY_TYPE_CONFIG == _MEMORY_DDR1))
    // Column = 256 :
    // Capture Column [9:0] --> 1'b0, Col[8:0]
    // Display Column [8:0]
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);
#if(_MEMORY_BANK == 2)
    // Capture Bank [1:0] --> 1'b0, Bank[0]
    // Display Bank [0]
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);
#endif
#endif

    ScalerSetBit(P5_C1_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetByte(P5_C6_MN_READ_ADDR_H, pData[1]);
    ScalerSetByte(P5_C7_MN_READ_ADDR_M, pData[2]);
    ScalerSetByte(P5_C8_MN_READ_ADDR_L, pData[3]);
    DebugMessageFRC("-D addr2 FRC", PDATA_DWORD(0));

    // 3rd Read Address
    PDATA_DWORD(0) = (((DWORD)_FRC_R_3RD_BLOCK_STA_ADDR_H << 16) | ((DWORD)_FRC_R_3RD_BLOCK_STA_ADDR_M << 8) | 0x00);

#if((_MEMORY_TYPE_CONFIG == _MEMORY_SDRAM) || (_MEMORY_TYPE_CONFIG == _MEMORY_DDR1))
    // Column = 256 :
    // Capture Column [9:0] --> 1'b0, Col[8:0]
    // Display Column [8:0]
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);
#if(_MEMORY_BANK == 2)
    // Capture Bank [1:0] --> 1'b0, Bank[0]
    // Display Bank [0]
    PDATA_DWORD(0) = (PDATA_DWORD(0) >> 1);
#endif
#endif

    ScalerSetBit(P5_C1_MN_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetByte(P5_C6_MN_READ_ADDR_H, pData[1]);
    ScalerSetByte(P5_C7_MN_READ_ADDR_M, pData[2]);
    ScalerSetByte(P5_C8_MN_READ_ADDR_L, pData[3]);
    DebugMessageFRC("-D addr3 FRC", PDATA_DWORD(0));
}

//--------------------------------------------------
// Description  : Set display adderss for auto block toggle
// Input Value  : En: enable / disable
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetDisplayAutoBlkToggleEnable(bit bEn)
{
    // Enable M:N HW auto toggle's double buffer
    ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~_BIT5, _BIT5);

    if(bEn == _ENABLE)
    {
        // Input Hardware auto toggle address enable
        ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~_BIT4, _BIT4);

        // Display Hardware auto toggle among address enable
        ScalerSetBit(P5_C1_MN_MADDR_TOG_CTL, ~_BIT4, _BIT4);
    }
    else
    {
        // Input Hardware auto toggle address disable
        ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~_BIT4, 0x00);

        // Display Hardware auto toggle among address disable
        ScalerSetBit(P5_C1_MN_MADDR_TOG_CTL, ~_BIT4, 0x00);
    }

    // Hardware auto toggle M:N double buffer ready
    ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~_BIT6, _BIT6);

    // Wait dobule buffer
    ScalerTimerPollingFlagProc(_M_N_AUTO_BLK_TOGGLE_STABLE_TIME, P5_BA_IN1_MADDR_TOG_CTL, _BIT6, 0);
}

//--------------------------------------------------
// Description  : Set auto block toggle
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetHWAutoBlockToggle(void)
{
    BYTE ucM = 1;
    BYTE ucN = 1;

    PDATA_WORD(0) = ScalerMemoryGetMNRatio();

    ucM = (PDATA_WORD(0) >> 8) & 0xFF;
    ucN = PDATA_WORD(0) & 0xFF;

    // IVS to DVS shift value for hardware auto toggle among three initial read address
    // Set Shift = 2 _3_IVF, _2_5_IVF
    ScalerSetBit(P5_CB_MN_BLOCK_STEP_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 2 << 4);

    // Multiple of hardware auto toggle among three initial read address, it is (N/M - 1)
    PDATA_WORD(0) = ucN / ucM - 1;

    ScalerSetBit(P5_BE_MN_PXL_NUM_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (PDATA_WORD(0) << 4));

    // Remain of hardware auto toggle among three initial read address, and it is (N%M)/N * 2^10.(11bit in total)
    PDATA_WORD(0) = ((ucN % ucM) << 10) / ucN;
    PDATA_WORD(0) += 1;

    ScalerSetBit(P5_C1_MN_MADDR_TOG_CTL, ~(_BIT7 | _BIT6 | _BIT5), ((pData[0] << 5) & 0xFF));
    ScalerSetByte(P5_EB_MN_MADDR_TOG_REM, (pData[1] & 0xFF));
}

//--------------------------------------------------
// Description  : Set Input adderss for auto block toggle
// Input Value  : ulBlockStep --> block step(single frame input and display)
// Output Value : None
//--------------------------------------------------
void ScalerFRCSetInputAutoBlkToggle(void)
{
    // 1st write address
    PDATA_DWORD(0) = ((DWORD)_FRC_R_2ND_BLOCK_STA_ADDR_H << 16) + ((DWORD)_FRC_R_2ND_BLOCK_STA_ADDR_M << 8);

    ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), 0x00);
    ScalerSetByte(P5_AD_IN1_MEM_ADDR_H, pData[1]);
    ScalerSetByte(P5_AE_IN1_MEM_ADDR_M, pData[2]);
    ScalerSetByte(P5_AF_IN1_MEM_ADDR_L, pData[3]);
    DebugMessageFRC("-I_addr1 FRC", PDATA_DWORD(0));

    // 2nd write address
    PDATA_DWORD(0) = ((DWORD)_FRC_R_3RD_BLOCK_STA_ADDR_H << 16) + ((DWORD)_FRC_R_3RD_BLOCK_STA_ADDR_M << 8);

    ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT2);
    ScalerSetByte(P5_AD_IN1_MEM_ADDR_H, pData[1]);
    ScalerSetByte(P5_AE_IN1_MEM_ADDR_M, pData[2]);
    ScalerSetByte(P5_AF_IN1_MEM_ADDR_L, pData[3]);
    DebugMessageFRC("-I_addr2 FRC", PDATA_DWORD(0));

    // 3rd write address
    PDATA_DWORD(0) = ((DWORD)_FRC_R_1ST_BLOCK_STA_ADDR_H << 16) + ((DWORD)_FRC_R_1ST_BLOCK_STA_ADDR_M << 8);

    ScalerSetBit(P5_BA_IN1_MADDR_TOG_CTL, ~(_BIT3 | _BIT2), _BIT3);
    ScalerSetByte(P5_AD_IN1_MEM_ADDR_H, pData[1]);
    ScalerSetByte(P5_AE_IN1_MEM_ADDR_M, pData[2]);
    ScalerSetByte(P5_AF_IN1_MEM_ADDR_L, pData[3]);
    DebugMessageFRC("-I_addr3 FRC", PDATA_DWORD(0));
}
#endif // End of #if(_FRC_HW_AUTO_3BLOCK_TOGGLE_SUPPORT == _ON)

#endif // End of #if(_FRC_SUPPORT == _ON)

