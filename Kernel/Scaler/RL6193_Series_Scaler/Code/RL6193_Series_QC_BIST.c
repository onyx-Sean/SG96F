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
// ID Code      : RL6193_Series_QC_BIST.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_QC_BIST__

#include "ScalerFunctionInclude.h"

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************

BYTE code tQCVBO[] =
{
//*************************************************************************
// Global Setting
//*************************************************************************
4,    _AUTOINC,    0x9F,    0x38,       // page 38 (VbyOne)
4,    _AUTOINC,    0x17,    0x40,       // DPTX clk in

//*************************************************************************
//  DPTX DPll Parameters Setting
//  Vref = Crystal = 14.318M
//  Target Clock = 297M for Vby1 Analog Phy referenced Freq
//  Target Clock = 297.099M = 14.318M * 83 / 2 / 2
//*************************************************************************

    ////////////////////////////////
    // PLL VCO Setting            //
    ////////////////////////////////
4,    _AUTOINC,    0x9F,    0xBE,       // page BE (PLL)

    ////////////////////////////////
    // DPLL Reset                 //
    ////////////////////////////////
4,    _AUTOINC,    0x03,    0x09,        // DP DPLL Power down
4,    _AUTOINC,    0x00,    0x00,         // Reset M code
4,    _AUTOINC,    0x01,    0x00,         // Reset N code
4,    _AUTOINC,    0x04,    0xA1,        // VCOMD=2'b10, DPLL Bypass Calibration
4,    _AUTOINC,    0x08,    0x01,       // [0]: 1 => Enable DDS Spread Spectrum output function

    ////////////////////////////////
    // DP DPLL Setting            //
    ////////////////////////////////
4,    _AUTOINC,    0x04,    0xA1,        // Set VCOMD=2'b10
4,    _AUTOINC,    0x00,    0x51,         // M = 0x51, DPM = 83, VCO: 594MHz
4,    _AUTOINC,    0x01,    0x10,         // N = 00 => div 2, O_code = 1 => div 2
4,    _AUTOINC,    0x02,    0x7D,         // [7:5] loop filter resiter  [4:3] capacitor  [3:0] charger pump current

4,    _AUTOINC,    0x03,    0x08,        // DPLL Power ON

//*************************************************************************
//  VbyOne Pll Parameters Setting
//  Target Vby1 MAC Clock = 375M
//  Target Vby1 MAC Clock = 371.37M = 297.099M * 5 / 4
//  Pin_K29: Measure Clock = 23.21M
//*************************************************************************

    ////////////////////////////////
    // Vby1 VCO Setting           //
    ////////////////////////////////
4,    _AUTOINC,    0x9F,    0x38,       // page 38 (Vby1 PLL)

    ////////////////////////////////
    // Vby1 Reset                 //
    ////////////////////////////////
4,    _AUTOINC,    0xA0,    0x00,        // Vby1 Phy Power down
4,    _AUTOINC,    0xAD,    0x00,        // Vby1 PLL Power down
4,    _AUTOINC,    0x09,    0x2A,        // DPLL for Vby1 lclk is not stable
4,    _AUTOINC,    0xAF,    0x02,         // Reset M code, Reset N code

    ////////////////////////////////
    // Vby1 Setting               //
    ////////////////////////////////
4,    _AUTOINC,    0xAF,    0x46,         // M = 5, N = 4, O = 1, VCO: DPLL * M / N / DIVO = 297.099MM * 50 / 4 / 1 = 3713.73M

4,    _AUTOINC,    0xA0,    0x80,        // Vby1 Phy Power on
4,    _AUTOINC,    0xAD,    0x88,        // Vby1 PLL Power on
4,    _AUTOINC,    0x09,    0x6A,        // DPLL for Vby1 lclk is stable
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
bit ScalerQCBistTest(void);

#if(_QC_4P_MODE_ == _ON)
bit ScalerQC4PBistTest(void);
#endif
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
bit ScalerQCBistTest_D0(void);
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
bit ScalerQCBistTest_D1(void);
#endif

bit ScalerQCTimerPollingPortFlagProc(WORD usTimeout, WORD usPortAddress, WORD usRegister, BYTE ucBit, bit bSuccess);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Test All Memory BIST
// Input Value  : None
// Output Value : TEST_PASS or TEST_FAIL
//--------------------------------------------------
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
bit ScalerQCBistTest(void)
{
    BYTE ucBistResult = 0;
    BYTE ucCnt = 0;

    DebugMessageQC("5. Bist Test Start", 0x00);

/*------------ADCNR BIST---------------*/

    DebugMessageQC("5. ====ADCNR Bist Test Start", 0x00);
    ScalerSetBit(P33_2A_BIST_CTRL, ~_BIT6, _BIT6);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P33_2A_BIST_CTRL, _BIT2, _TRUE) == _TRUE)
    {
        if(ScalerGetBit(P33_2B_BIST_RESULT, _BIT7) != 0x00)
        {
            DebugMessageQC("5. ADCNR bist_result_3 Fail", 0x00);
            ucBistResult |= _BIT7;
        }

        if(ScalerGetBit(P33_2B_BIST_RESULT, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ADCNR bist_result_2 Fail", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P33_2B_BIST_RESULT, _BIT5) != 0x00)
        {
            DebugMessageQC("5. ADCNR bist_result_1 Fail", 0x00);
            ucBistResult |= _BIT5;
        }

        if(ScalerGetBit(P33_2B_BIST_RESULT, _BIT4) != 0x00)
        {
            DebugMessageQC("5. ADCNR bist_result_0 Fail", 0x00);
            ucBistResult |= _BIT4;
        }

    }
    else
    {
        DebugMessageQC("5. ADCNR Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable ADCNR bist test
    ScalerSetBit(P33_2A_BIST_CTRL, ~_BIT6, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. ADCNR Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. ADCNR Bist FAIL", ucBistResult);
    }
    ucBistResult = 0x00;

/*------------Scaling Down BIST---------------*/

    //Test ScaleDown M1 Bist Mode
    DebugMessageQC("5. ====ScaleDown M1 Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, ~_BIT5, _BIT5);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, _BIT7, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M1 Linebuffer0 Bist Even Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_46_SD_BIST_CTRL1_M1, _BIT7) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M1 Linebuffer1 Bist Even Fail", 0x00);
            ucBistResult |= _BIT7;
        }
    }
    else
    {
        DebugMessageQC("5. ScaleDown M1 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }
    //disable ScaleDown M1 bist test
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, ~_BIT5, 0x00);


    //Test ScaleDown M2 Bist Mode
    DebugMessageQC("5. ====ScaleDown M2 Bist Test Start", 0x00);
    ScalerSetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, ~_BIT5, _BIT5);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, _BIT7, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M2 Linebuffer0 Bist Even Fail", 0x00);
            ucBistResult |= _BIT5;
        };

        if(ScalerGetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_46_SD_BIST_CTRL1_M2, _BIT7) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M2 Linebuffer1 Bist Even Fail", 0x00);
            ucBistResult |= _BIT5;
        }
    }
    else
    {
        DebugMessageQC("5. ScaleDown M2 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT4;
    }
    //disable ScaleDown M2 bist test
    ScalerSetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, ~_BIT5, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. ScaleDown M1 & M2 Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. ScaleDown M1 & M2 Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. ScaleDown M1 & M2 Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------DisplayTimingGen BIST---------------*/

    //Test DisplayTimingGen Even Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Even Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, ~_BIT6, _BIT6);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, _BIT2, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT7) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even BIST Fail for SRAM No.3", 0x00);
            ucBistResult |= _BIT7;
        }

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT6) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even BIST Fail for SRAM No.2", 0x00);
            ucBistResult |= _BIT7;
        }

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT5) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even BIST Fail for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        }

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT4) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even BIST Fail for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        }
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Even Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable DisplayTimingGen Even bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, ~_BIT6, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen Even Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen Even Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen Even Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


    //Test DisplayTimingGen Odd Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Odd Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, ~_BIT6, _BIT6);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, _BIT2, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT7) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd BIST Fail for SRAM No.3", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT6) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd BIST Fail for SRAM No.2", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT5) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd BIST Fail for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT4) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd BIST Fail for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Odd Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable DisplayTimingGen Odd bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, ~_BIT6, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen Odd Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen Odd Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen Odd Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


    //Test DisplayTimingGen Sub Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Sub Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, ~_BIT6, _BIT6);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, _BIT2, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT7) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub BIST Fail for SRAM No.3", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT6) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub BIST Fail for SRAM No.2", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT5) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub BIST Fail for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT4) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub BIST Fail for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Sub Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable DisplayTimingGen Sub bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, ~_BIT6, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen Sub Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen Sub Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen Sub Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


    //Test DisplayTimingGen Fifo Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Fifo Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, ~_BIT6, _BIT6);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, _BIT2, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_47_FIFO_BIST_RESULT, _BIT5) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Fifo BIST Fail for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_47_FIFO_BIST_RESULT, _BIT4) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Fifo BIST Fail for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Fifo Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable DisplayTimingGen Fifo bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, ~_BIT6, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen FIFO Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen FIFO Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen FIFO Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------DCC BIST---------------*/

    //D1 DCC bist function
    DebugMessageQC("5. ====D1 DCC Bist Test Start", 0x00);
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_00_PORT_PAGE3_SRAM_BIST, ~_BIT7, _BIT7);
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, ~_BIT7, 0x00);

    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_00_PORT_PAGE3_SRAM_BIST, _BIT1, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_00_PORT_PAGE3_SRAM_BIST, _BIT0) != 0x00)
        {
            DebugMessageQC("5. D1 DCC Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. D1 DCC Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }

    // D1 DCC diable Bist test
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_00_PORT_PAGE3_SRAM_BIST, ~_BIT7, 0x00);
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, ~_BIT7, 0x00);
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~(_BIT1 | _BIT0), 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. D1 DCC Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. D1 DCC Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. D1 DCC Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------GAMMA BIST---------------*/

    //ScalerColorOutputGammaEnable(_FUNCTION_OFF);
    DebugMessageQC("5. ====Gamma Bist Test Start", 0x00);

    // Normal Bist
    ScalerSetBit(P2F_01_GAMMA_BIST_CTRL0_M1, ~_BIT7,_BIT7);
    ScalerSetBit(P2F_04_GAMMA_BIST_CTRL3_M1, ~_BIT7,_BIT7);
    ScalerSetBit(P2F_07_GAMMA_BIST_CTRL0_M2, ~_BIT7,_BIT7);
    ScalerSetBit(P2F_0A_GAMMA_BIST_CTRL3_M2, ~_BIT7,_BIT7);

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_01_GAMMA_BIST_CTRL0_M1, _BIT6, _BIT6) == _TRUE)
    {
        if(ScalerGetBit(P2F_01_GAMMA_BIST_CTRL0_M1, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. Gamma Normal Bist M1 Set A Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_04_GAMMA_BIST_CTRL3_M1, _BIT6, _BIT6) == _TRUE)
    {
        if(ScalerGetBit(P2F_04_GAMMA_BIST_CTRL3_M1, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. Gamma Normal Bist M1 Set B Fail", 0x00);
            ucBistResult |= _BIT6;
        };
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_07_GAMMA_BIST_CTRL0_M2, _BIT6, _BIT6) == _TRUE)
    {
        if(ScalerGetBit(P2F_07_GAMMA_BIST_CTRL0_M2, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. Gamma Normal Bist M2 Set A Fail", 0x00);
            ucBistResult |= _BIT5;
        };
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_0A_GAMMA_BIST_CTRL3_M2, _BIT6, _BIT6) == _TRUE)
    {
        if(ScalerGetBit(P2F_0A_GAMMA_BIST_CTRL3_M2, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. Gamma Normal Bist M2 Set B Fail", 0x00);
            ucBistResult |= _BIT4;
        };
    }

    // turn off Normal BIST
    ScalerSetBit(P2F_01_GAMMA_BIST_CTRL0_M1, ~_BIT7, 0x00);
    ScalerSetBit(P2F_04_GAMMA_BIST_CTRL3_M1, ~_BIT7, 0x00);
    ScalerSetBit(P2F_07_GAMMA_BIST_CTRL0_M2, ~_BIT7, 0x00);
    ScalerSetBit(P2F_0A_GAMMA_BIST_CTRL3_M2, ~_BIT7, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. Gamma Normal Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. Gamma Normal Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. Gamma Normal Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------3D LUT BIST---------------*/

    //Test 3D LUT SRAM

    DebugMessageQC("5. ====3D LUT SDRAM M1-1 Test Start", 0x00);
    ScalerSetBit(P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1,~_BIT7,_BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1, _BIT6, _TRUE) == _TRUE)
    {
        if(ScalerGetBit(P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1, _BIT5) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1, _BIT4) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1, _BIT2) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }

    }
    else
    {
        DebugMessageQC("5. 3D LUT SDRAM M1-1 Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }

    DebugMessageQC("5. 3D LUT SDRAM M1-2 Test Start", 0x00);
    ScalerSetBit(P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2,~_BIT7,_BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2, _BIT6, _TRUE) == _TRUE)
    {
        if(ScalerGetBit(P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2, _BIT5) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2, _BIT4) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2, _BIT3) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2, _BIT2) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }

    }
    else
    {
        DebugMessageQC("5. 3D LUT SDRAM M1-2 Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }

    DebugMessageQC("5. 3D LUT SDRAM M2-1 Test Start", 0x00);
    ScalerSetBit(P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1,~_BIT7,_BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1, _BIT6, _TRUE) == _TRUE)
    {
        if(ScalerGetBit(P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1, _BIT5) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1, _BIT4) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1, _BIT2) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }

    }
    else
    {
        DebugMessageQC("5. 3D LUT SDRAM M2-1 Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }


    DebugMessageQC("5. 3D LUT SDRAM M2-2 Test Start", 0x00);
    ScalerSetBit(P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2,~_BIT7,_BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2, _BIT6, _TRUE) == _TRUE)
    {
        if(ScalerGetBit(P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2, _BIT5) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2, _BIT4) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2, _BIT3) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2, _BIT2) != 0x00)
        {
            DebugMessageQC("5. BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }

    }
    else
    {
        DebugMessageQC("5. 3D LUT SDRAM M2-2 Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }
    //Disable 3D LUT Normal Bist Test
     ScalerSetBit(P9_B4_RGB_3D_GAMMA_BIST_CTRL_MAIN1_1,~_BIT7,0x00);
     ScalerSetBit(P9_B5_RGB_3D_GAMMA_BIST_CTRL_MAIN1_2,~_BIT7,0x00);
     ScalerSetBit(P9_B6_RGB_3D_GAMMA_BIST_CTRL_MAIN2_1,~_BIT7,0x00);
     ScalerSetBit(P9_B7_RGB_3D_GAMMA_BIST_CTRL_MAIN2_2,~_BIT7,0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. 3D LUT SDRAM Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. 3D LUT SDRAM Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. 3D LUT SDRAM Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------SHP BIST---------------*/

        //Test SHP M1 M2  SRAM
    DebugMessageQC("5. ====SHP M1 M2 Bist Test Start", 0x00);
    ScalerSetBit(P12_A2_SR_SHP_BIST_CTRL_0,~_BIT3,_BIT3);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P12_A2_SR_SHP_BIST_CTRL_0, _BIT2, _BIT2) == _TRUE)
    {
        if(ScalerGetBit(P12_A2_SR_SHP_BIST_CTRL_0, _BIT1) != 0x00)
        {
            DebugMessageQC("5. SHP M1 Bist Even Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P12_A2_SR_SHP_BIST_CTRL_0, _BIT0) != 0x00)
        {
            DebugMessageQC("5. SHP M1 Bist Odd Fail", 0x00);
            ucBistResult |= _BIT7;
        }

        if(ScalerGetBit(P12_A2_SR_SHP_BIST_CTRL_0, _BIT5) != 0x00)
        {
            DebugMessageQC("5. SHP M2 Bist Even Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P12_A2_SR_SHP_BIST_CTRL_0, _BIT4) != 0x00)
        {
            DebugMessageQC("5. SHP M2 Bist Odd Fail", 0x00);
            ucBistResult |= _BIT7;
        }

    }
    else
    {
        DebugMessageQC("5. SHP Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }

    //Test SHP S1 SRAM
    DebugMessageQC("5. ====SHP S1 Bist Test Start", 0x00);
    ScalerSetBit(P92_A2_SR_SHP_BIST_CTRL_0,~_BIT3,_BIT3);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P92_A2_SR_SHP_BIST_CTRL_0, _BIT2, _BIT2) == _TRUE)
    {
        if(ScalerGetBit(P92_A2_SR_SHP_BIST_CTRL_0, _BIT1) != 0x00)
        {
            DebugMessageQC("5. SHP S1 Bist Even Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P92_A2_SR_SHP_BIST_CTRL_0, _BIT0) != 0x00)
        {
            DebugMessageQC("5. SHP S1 Bist Odd Fail", 0x00);
            ucBistResult |= _BIT7;
        }
    }
    else
    {
        DebugMessageQC("5. SHP Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable SHP bist test
    ScalerSetBit(P12_A2_SR_SHP_BIST_CTRL_0,~_BIT3,0x00);
    ScalerSetBit(P92_A2_SR_SHP_BIST_CTRL_0,~_BIT3,0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. SHP Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. SHP Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. SHP Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------Panel Uniformity BIST---------------*/

    // Test Panel Uniformity Table SRAM
    DebugMessageQC("5. ====Panel Uniformity Bist Test Start", 0x00);
    ScalerSetBit(P34_09_UN_SRAM_BIST, ~_BIT7, _BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P34_09_UN_SRAM_BIST, _BIT6, _BIT6) == _TRUE)
    {
        // BIST Fail
        if(ScalerGetBit(P34_09_UN_SRAM_BIST, _BIT5) != 0x00)
        {
            DebugMessageQC("5. Panel Uniformity Bist Fail", 0x00);
            ucBistResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageQC("5. Panel Uniformity Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    ScalerSetBit(P34_09_UN_SRAM_BIST, ~_BIT7, 0x00);


    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. Panel Uniformity Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. Panel Uniformity Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. Panel Uniformity Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------LiveShow(OD) BIST---------------*/

    DebugMessageQC("5. ====OD Bist Test Start", 0x00);

    // Test M1 OD Capture SRAM
    ScalerSetBit(P3_DE_CAP_BIST_CTRL, ~_BIT1, _BIT1);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P3_DE_CAP_BIST_CTRL, _BIT7, _TRUE) == _TRUE)
    {
        // M1 Cap BIST Fail
        if(ScalerGetBit(P3_DE_CAP_BIST_CTRL, _BIT5) != 0x00)
        {
            DebugMessageQC("5. OD M1 Cap Bist Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    else
    {
        DebugMessageQC("5. OD M1 Cap Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    ScalerSetBit(P3_DE_CAP_BIST_CTRL, ~_BIT1, 0x00);

    // Test M1 OD Display SRAM
    ScalerSetBit(P3_DF_DIS_BIST_CTRL, ~_BIT1, _BIT1);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P3_DF_DIS_BIST_CTRL, _BIT7, _TRUE) == _TRUE)
    {
        // M1 Dis BIST Fail
        if(ScalerGetBit(P3_DF_DIS_BIST_CTRL, _BIT5) != 0x00)
        {
            DebugMessageQC("5. OD M1 Dis Bist Fail", 0x00);
            ucBistResult |= _BIT2;
        }
    }
    else
    {
        DebugMessageQC("5. OD M1 Dis Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT3;
    }
    ScalerSetBit(P3_DF_DIS_BIST_CTRL, ~_BIT1, 0x00);

    // Test M2 OD Capture SRAM
    ScalerSetBit(P43_DE_CAP_BIST_CTRL, ~_BIT1, _BIT1);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P43_DE_CAP_BIST_CTRL, _BIT7, _TRUE) == _TRUE)
    {
        // M2 Cap BIST Fail
        if(ScalerGetBit(P43_DE_CAP_BIST_CTRL, _BIT5) != 0x00)
        {
            DebugMessageQC("5. OD M2 Cap Bist Fail", 0x00);
            ucBistResult |= _BIT4;
        }
    }
    else
    {
        DebugMessageQC("5. OD M2 Cap Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT5;
    }
    ScalerSetBit(P43_DE_CAP_BIST_CTRL, ~_BIT1, 0x00);

    // Test M2 OD Display SRAM
    ScalerSetBit(P43_DF_DIS_BIST_CTRL, ~_BIT1, _BIT1);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P43_DF_DIS_BIST_CTRL, _BIT7, _TRUE) == _TRUE)
    {
        // M2 Dis BIST Fail
        if(ScalerGetBit(P43_DF_DIS_BIST_CTRL, _BIT5) != 0x00)
        {
            DebugMessageQC("5. OD M2 Dis Bist Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageQC("5. OD M2 Dis Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT7;
    }
    ScalerSetBit(P43_DF_DIS_BIST_CTRL, ~_BIT1, 0x00);


    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. OD Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. OD Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. OD Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

/*------------Display Conversion BIST---------------*/

    DebugMessageQC("5. ====Display Conversion Bist Test Start", 0x00);

    // Test LVDS Table SRAM
    DebugMessageQC("5. ====LVDS Bist Test", 0x00);

    ScalerSetBit(P39_21_LVDS_BIST_CTRL, ~_BIT7, _BIT7);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P39_21_LVDS_BIST_CTRL, _BIT6, _BIT6) == _TRUE)
    {
        // BIST Fail
        if(ScalerGetBit(P39_21_LVDS_BIST_CTRL, _BIT5) != 0x00)
        {
            DebugMessageQC("5. LVDS Bist No.5 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P39_21_LVDS_BIST_CTRL, _BIT4) != 0x00)
        {
            DebugMessageQC("5. LVDS Bist No.4 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P39_21_LVDS_BIST_CTRL, _BIT3) != 0x00)
        {
            DebugMessageQC("5. LVDS Bist No.3 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P39_21_LVDS_BIST_CTRL, _BIT2) != 0x00)
        {
            DebugMessageQC("5. LVDS Bist No.2 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P39_21_LVDS_BIST_CTRL, _BIT1) != 0x00)
        {
            DebugMessageQC("5. LVDS Bist No.1 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P39_21_LVDS_BIST_CTRL, _BIT0) != 0x00)
        {
            DebugMessageQC("5. LVDS Bist No.0 Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    else
    {
        DebugMessageQC("5. LVDS Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    ScalerSetBit(P39_21_LVDS_BIST_CTRL, ~_BIT7, 0x00);

    // Test Vbyone Table SRAM
    DebugMessageQC("5. ====VBO Bist Test", 0x00);

    ScalerBurstWrite(tQCVBO, sizeof(tQCVBO), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    ScalerTimerDelayXms(10);

    // Test Vbyone BIST0
    ScalerSetBit(P38_19_VBY1_BIST_CON_0, ~_BIT0, _BIT0);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P38_19_VBY1_BIST_CON_0, _BIT3, _BIT3) == _TRUE)
    {
        // BIST0 Fail
        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT7) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 7 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT6) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 6 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT5) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 5 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT4) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 4 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT3) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 3 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT2) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 2 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT1) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 1 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1B_VBY1_BIST0, _BIT0) != 0x00)
        {
            DebugMessageQC("5. VBO Bist0 SRAM 0 Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    else
    {
        DebugMessageQC("5. VBO Bist0 Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    ScalerSetBit(P38_19_VBY1_BIST_CON_0, ~_BIT0, 0x00);

    // Test Vbyone BIST1
    ScalerSetBit(P38_1A_VBY1_BIST_CON_1, ~_BIT0, _BIT0);
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P38_1A_VBY1_BIST_CON_1, _BIT3, _BIT3) == _TRUE)
    {
        // BIST1 Fail
        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT7) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 7 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT6) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 6 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT5) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 5 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT4) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 4 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 3 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT2) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 2 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT1) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 1 Fail", 0x00);
            ucBistResult |= _BIT0;
        }

        if(ScalerGetBit(P38_1C_VBY1_BIST1, _BIT0) != 0x00)
        {
            DebugMessageQC("5. VBO Bist1 SRAM 0 Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    else
    {
        DebugMessageQC("5. VBO Bist1 Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    ScalerSetBit(P38_1A_VBY1_BIST_CON_1, ~_BIT0, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. Display Conversion Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. Display Conversion Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. Display Conversion Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

    DebugMessageQC("6. Bist Test Done", 0x00);
    return _TEST_PASS;
}

#if(_QC_4P_MODE_ == _ON)
bit ScalerQC4PBistTest(void)
{
    BYTE ucBistResult = 0;

    DebugMessageQC("5. 4P Bist Test Start", 0x00);

/*------------Sub Scaling Down BIST---------------*/

    //Test ScaleDown S1 Bist Mode
    DebugMessageQC("5. ====ScaleDown S1 Bist Test Start", 0x00);
    ScalerSetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, ~_BIT5, _BIT5);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, _BIT7, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S1 Linebuffer0 Bist Even Fail", 0x00);
            ucBistResult |= _BIT3;
        };

        if(ScalerGetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_46_SD_BIST_CTRL1_S1, _BIT7) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S1 Linebuffer1 Bist Even Fail", 0x00);
            ucBistResult |= _BIT3;
        }
    }
    else
    {
        DebugMessageQC("5. ScaleDown S1 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT2;
    }
    //disable ScaleDown S1 bist test
    ScalerSetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, ~_BIT5, 0x00);


    //Test ScaleDown S2 Bist Mode
    DebugMessageQC("5. ====ScaleDown S2 Bist Test Start", 0x00);
    ScalerSetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, ~_BIT5, _BIT5);
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, _BIT7, _TRUE) == _TRUE)
    {
        if(ScalerGetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S2 Linebuffer0 Bist Even Fail", 0x00);
            ucBistResult |= _BIT1;
        };

        if(ScalerGetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_46_SD_BIST_CTRL1_S2, _BIT7) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S2 Linebuffer1 Bist Even Fail", 0x00);
            ucBistResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageQC("5. ScaleDown S2 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }
    //disable ScaleDown S2 bist test
    ScalerSetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, ~_BIT5, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. ScaleDown S1 & S2 Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. ScaleDown S1 & S2 Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. ScaleDown S1 & S2 Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

    DebugMessageQC("6. 4P Bist Test Done", 0x00);
    return _TEST_PASS;
}
#endif // End of #if(_QC_4P_MODE_ == _ON)

#endif

//--------------------------------------------------
// Description  : Test D0 Memory BIST
// Input Value  : None
// Output Value : TEST_PASS or TEST_FAIL
//--------------------------------------------------
#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
bit ScalerQCBistTest_D0(void)
{
    BYTE ucBistResult = 0;
    BYTE ucCnt = 0;

/*------------D0 420to422 BIST---------------*/

    //D0 420to422 bist function {0x3128[7],0x3129[7]} = 2'b10
    DebugMessageQC("5. ====420to422 D0 Bist Test Start", 0x00);
    ScalerSetBit(P31_28_BIST_D0_YUV420TO422,~_BIT7,_BIT7);
    ScalerSetBit(P31_29_DRF_BIST_D0_YUV420TO422,~_BIT7,0x00);

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P31_28_BIST_D0_YUV420TO422, _BIT6, _BIT6) == _TRUE)
    {
        if(ScalerGetBit(P31_28_BIST_D0_YUV420TO422, (_BIT5 | _BIT4)) != 0x00)
        {
            DebugMessageQC("5. D0 420to422 Y Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P31_28_BIST_D0_YUV420TO422, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. D0 420to422 UV Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

    }
    else
    {
        DebugMessageQC("5. D0 420to422 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }

    ScalerSetBit(P31_28_BIST_D0_YUV420TO422,~_BIT7,0x00);
    ScalerSetBit(P31_29_DRF_BIST_D0_YUV420TO422,~_BIT7,0x00);

    //D0 420to422 DRF bist function {0x3128[7],0x3129[7]} = 2'b01
    /*
    DebugMessageQC("5. ====420to422 D0 DRF Bist Test Start", 0x00);
    //1.Start DRF BIST mode
    ScalerSetBit(P31_28_BIST_D0_YUV420TO422,~_BIT7,0x00);
    ScalerSetBit(P31_29_DRF_BIST_D0_YUV420TO422,~_BIT7,_BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(1000, P31_2C_DRF_BIST_D0D1_YUV420TO422, _BIT6, _BIT6) == _TRUE)
        {
            //3.Wait 1ms
            //ScalerTimerDelayXms(2);
            //4.DRF Tets Resume Start
            ScalerSetBit(P31_2C_DRF_BIST_D0D1_YUV420TO422,~_BIT7,_BIT7);
            ScalerSetBit(P31_2C_DRF_BIST_D0D1_YUV420TO422,~_BIT7,0x00);
        }
        else
        {
            DebugMessageQC("5. D0 420to422 DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //8.Wait DRF Bist Done
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P31_29_DRF_BIST_D0_YUV420TO422, _BIT6, _BIT6) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetBit(P31_29_DRF_BIST_D0_YUV420TO422, (_BIT5 | _BIT4)) != 0x00)
        {
            DebugMessageQC("5. D0 420to422 Y DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P31_29_DRF_BIST_D0_YUV420TO422, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. D0 420to422 UV DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. D0 420to422 DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    */
    //D0 420to422 diable Bist test
    ScalerSetBit(P31_28_BIST_D0_YUV420TO422,~_BIT7,0x00);
    ScalerSetBit(P31_29_DRF_BIST_D0_YUV420TO422,~_BIT7,0x00);
    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. D0 420to422Bist PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. D0 420to422Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. D0 420to422Bist FAIL", 0x00);
        return _TEST_FAIL;
    }
}
#endif

//--------------------------------------------------
// Description  : Test D1 Memory BIST
// Input Value  : None
// Output Value : TEST_PASS or TEST_FAIL
//--------------------------------------------------
#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
bit ScalerQCBistTest_D1(void)
{
    BYTE ucBistResult = 0;
    BYTE ucCnt = 0;

//------------Scaling Down DRF BIST---------------//
/*
    //Test ScaleDown M1 DRF Bist Mode
    DebugMessageQC("5. ====ScaleDown M1 DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, ~_BIT2, _BIT2);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, _BIT1, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, ~_BIT0, _BIT0);
            ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, ~_BIT0, 0x00);
        }
        else
        {
            DebugMessageQC("5. ScaleDown M1 DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, _BIT4, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M1 Linebuffer0 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_46_SD_BIST_CTRL1_M1, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M1 Linebuffer1 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. ScaleDown M1 DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //ScaleDown M1 diable DRF Bist test
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_45_SD_BIST_CTRL0_M1, ~_BIT2, 0x00);

    //Test ScaleDown M2 DRF Bist Mode
    DebugMessageQC("5. ====ScaleDown M2 DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, ~_BIT2, _BIT2);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, _BIT1, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, ~_BIT0, _BIT0);
            ScalerSetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, ~_BIT0, 0x00);
        }
        else
        {
            DebugMessageQC("5. ScaleDown M2 DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, _BIT4, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, _BIT3) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M2 Linebuffer0 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_46_SD_BIST_CTRL1_M2, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown M2 Linebuffer1 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. ScaleDown M2 DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //ScaleDown M2 diable DRF Bist test
    ScalerSetDataPortBit(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_45_SD_BIST_CTRL0_M2, ~_BIT2, 0x00);

    //Test ScaleDown S1 DRF Bist Mode
    DebugMessageQC("5. ====ScaleDown S1 DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, ~_BIT2, _BIT2);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, _BIT1, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, ~_BIT0, _BIT0);
            ScalerSetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, ~_BIT0, 0x00);
        }
        else
        {
            DebugMessageQC("5. ScaleDown S1 DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, _BIT4, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S1 Linebuffer0 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_46_SD_BIST_CTRL1_S1, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S1 Linebuffer1 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. ScaleDown S1 DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //ScaleDown S1 diable DRF Bist test
    ScalerSetDataPortBit(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_45_SD_BIST_CTRL0_S1, ~_BIT2, 0x00);

    //Test ScaleDown S2 DRF Bist Mode
    DebugMessageQC("5. ====ScaleDown S2 DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, ~_BIT2, _BIT2);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, _BIT1, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, ~_BIT0, _BIT0);
            ScalerSetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, ~_BIT0, 0x00);
        }
        else
        {
            DebugMessageQC("5. ScaleDown S2 DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, _BIT4, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, _BIT3) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S2 Linebuffer0 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_46_SD_BIST_CTRL1_S2, _BIT6) != 0x00)
        {
            DebugMessageQC("5. ScaleDown S2 Linebuffer1 DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. ScaleDown S2 DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //ScaleDown S2 diable DRF Bist test
    ScalerSetDataPortBit(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_45_SD_BIST_CTRL0_S2, ~_BIT2, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. ScaleDown M1 & M2 & S1 & S2 DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. ScaleDown M1 & M2 & S1 & S2 DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. ScaleDown M1 & M2 & S1 & S2 DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

//------------DisplayTimingGen DRF BIST---------------//

    //Test DisplayTimingGen Even DRF Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Even DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, ~_BIT5, _BIT5);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, _BIT0, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, ~_BIT4, _BIT4);
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, ~_BIT4, 0x00);
        }
        else
        {
            DebugMessageQC("5. DisplayTimingGen Even DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, _BIT1, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_41_EVEN_BIST_RESULT, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Even DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Even DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //DisplayTimingGen diable Even DRF Bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_40_EVEN_BIST_CTRL, ~_BIT5, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen Even DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen Even DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen Even DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


    //Test DisplayTimingGen Odd DRF Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Odd DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, ~_BIT5, _BIT5);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, _BIT0, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, ~_BIT4, _BIT4);
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, ~_BIT4, 0x00);
        }
        else
        {
            DebugMessageQC("5. DisplayTimingGen Odd DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, _BIT1, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_43_ODD_BIST_RESULT, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Odd DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Odd DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //DisplayTimingGen diable Odd DRF Bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_42_ODD_BIST_CTRL, ~_BIT5, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen Odd DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen Odd DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen Odd DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


    //Test DisplayTimingGen Sub DRF Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Sub DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, ~_BIT5, _BIT5);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, _BIT0, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, ~_BIT4, _BIT4);
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, ~_BIT4, 0x00);
        }
        else
        {
            DebugMessageQC("5. DisplayTimingGen Sub DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, _BIT1, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_45_SUB_BIST_RESULT, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Sub DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Sub DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //DisplayTimingGen diable Sub DRF Bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_44_SUB_BIST_CTRL, ~_BIT5, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen Sub DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen Sub DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen Sub DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


    //Test DisplayTimingGen Fifo DRF Bist Mode
    DebugMessageQC("5. ====DisplayTimingGen Fifo DRF Bist Test Start", 0x00);
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, ~_BIT5, _BIT5);

    //Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(1000, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, _BIT0, _TRUE) == _TRUE)
        {
            //Wait 1ms
            //ScalerTimerDelayXms(2);
            //DRF Test Resume Start
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, ~_BIT4, _BIT4);
            ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, ~_BIT4, 0x00);
        }
        else
        {
            DebugMessageQC("5. DisplayTimingGen Fifo DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }

    //Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, _BIT1, _TRUE) == _TRUE)
    {
        //Check Bist Pass or Fail
        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_47_FIFO_BIST_RESULT, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Fifo DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetDataPortBit( P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_47_FIFO_BIST_RESULT, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DisplayTimingGen Fifo DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. DisplayTimingGen Fifo DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    //DisplayTimingGen diable Fifo DRF Bist test
    ScalerSetDataPortBit(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_46_FIFO_BIST_CTRL, ~_BIT5, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. DisplayTimingGen FIFO DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. DisplayTimingGen FIFO DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. DisplayTimingGen FIFO DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

//------------DCC DRF BIST---------------//

    DebugMessageQC("5. ====DCC D1 DRF Bist Test Start", 0x00);
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~(_BIT1 | _BIT0), _BIT1 | _BIT0);

    //1.Start DRF BIST mode
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_00_PORT_PAGE3_SRAM_BIST, ~_BIT7, 0x00);
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, ~_BIT7, _BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, _BIT1, _TRUE) == _TRUE)
        {
            //3.Wait 1ms
            //ScalerTimerDelayXms(2);
            ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, ~_BIT6, _BIT6);
            ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, ~_BIT6, 0x00);
        }
        else
        {
            DebugMessageQC("5. D1 DCC DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    //8.Wait DRF Bist Done
    if(ScalerQCTimerPollingPortFlagProc(_BIST_TIMEOUT, P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, _BIT3, _TRUE) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, _BIT2) != 0x00)
        {
            DebugMessageQC("5. D1 DCC DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. D1 DCC DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }

    // D1 DCC diable Bist test
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_00_PORT_PAGE3_SRAM_BIST, ~_BIT7, 0x00);
    ScalerSetDataPortBit(P7_C9_DCC_ADDRESS_PORT, _P7_CA_PT_01_PORT_PAGE3_SRAM_DRF_BIST, ~_BIT7, 0x00);
    ScalerSetBit(P7_C7_DCC_CTRL_0, ~(_BIT1 | _BIT0), 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. D1 DCC DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. D1 DCC DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. D1 DCC DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

//------------GAMMA DRF BIST---------------//

    DebugMessageQC("5. ====Gamma DRF Bist Test Start", 0x00);

    ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT7,_BIT7);
    ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT7,_BIT7);
    ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT7,_BIT7);
    ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT7,_BIT7);

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_02_GAMMA_BIST_CTRL1_M1, _BIT5, _BIT5) == _TRUE)
    {
        ScalerTimerDelayXms(2);
        ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT6, 0x00);
        ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT6, _BIT6);
        ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT6, 0x00);

        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_02_GAMMA_BIST_CTRL1_M1, _BIT5, _BIT5) == _TRUE)
        {
            ScalerTimerDelayXms(2);
            ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT6, 0x00);
            ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT6, _BIT6);
            ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT6, 0x00);

            if(ScalerGetBit(P2F_03_GAMMA_BIST_CTRL2_M1, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageQC("5. Gamma DRF Bist M1 Set A Fail", 0x00);
                ucBistResult |= _BIT3;
            }
        }
        else
        {
            DebugMessageQC("5. Gamma DRF Bist M1 Set A Time Out 1", 0x00);
            ucBistResult |= _BIT3;
        }
    }
    else
    {
        DebugMessageQC("5. Gamma DRF Bist M1 Set A Time Out 2", 0x00);
        ucBistResult |= _BIT3;
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_05_GAMMA_BIST_CTRL4_M1, _BIT5, _BIT5) == _TRUE)
    {
        ScalerTimerDelayXms(2);
        ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT6, 0x00);
        ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT6, _BIT6);
        ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT6, 0x00);

        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_05_GAMMA_BIST_CTRL4_M1, _BIT5, _BIT5) == _TRUE)
        {
            ScalerTimerDelayXms(2);
            ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT6, 0x00);
            ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT6, _BIT6);
            ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT6, 0x00);

            if(ScalerGetBit(P2F_06_GAMMA_BIST_CTRL5_M1, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageQC("5. Gamma DRF Bist M1 Set B Fail", 0x00);
                ucBistResult |= _BIT2;
            }
        }
        else
        {
            DebugMessageQC("5. Gamma DRF Bist M1 Set B Time Out 1", 0x00);
            ucBistResult |= _BIT2;
        }
    }
    else
    {
        DebugMessageQC("5. Gamma DRF Bist M1 Set B Time Out 2", 0x00);
        ucBistResult |= _BIT2;
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_08_GAMMA_BIST_CTRL1_M2, _BIT5, _BIT5) == _TRUE)
    {
        ScalerTimerDelayXms(2);
        ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT6, 0x00);
        ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT6, _BIT6);
        ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT6, 0x00);

        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_08_GAMMA_BIST_CTRL1_M2, _BIT5, _BIT5) == _TRUE)
        {
            ScalerTimerDelayXms(2);
            ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT6, 0x00);
            ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT6, _BIT6);
            ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT6, 0x00);

            if(ScalerGetBit(P2F_09_GAMMA_BIST_CTRL2_M2, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageQC("5. Gamma DRF Bist M2 Set A Fail", 0x00);
                ucBistResult |= _BIT1;
            }
        }
        else
        {
            DebugMessageQC("5. Gamma DRF Bist M2 Set A Time Out 1", 0x00);
            ucBistResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageQC("5. Gamma DRF Bist M2 Set A Time Out 2", 0x00);
        ucBistResult |= _BIT1;
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_0B_GAMMA_BIST_CTRL4_M2, _BIT5, _BIT5) == _TRUE)
    {
        ScalerTimerDelayXms(2);
        ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT6, 0x00);
        ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT6, _BIT6);
        ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT6, 0x00);

        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P2F_0B_GAMMA_BIST_CTRL4_M2, _BIT5, _BIT5) == _TRUE)
        {
            ScalerTimerDelayXms(2);
            ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT6, 0x00);
            ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT6, _BIT6);
            ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT6, 0x00);

            if(ScalerGetBit(P2F_0C_GAMMA_BIST_CTRL5_M2, (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
            {
                DebugMessageQC("5. Gamma DRF Bist M2 Set B Fail", 0x00);
                ucBistResult |= _BIT0;
            }
        }
        else
        {
            DebugMessageQC("5. Gamma DRF Bist M2 Set B Time Out 1", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    else
    {
        DebugMessageQC("5. Gamma DRF Bist M2 Set B Time Out 2", 0x00);
        ucBistResult |= _BIT0;
    }

    // turn off drf bist
    ScalerSetBit(P2F_02_GAMMA_BIST_CTRL1_M1, ~_BIT7, 0x00);
    ScalerSetBit(P2F_05_GAMMA_BIST_CTRL4_M1, ~_BIT7, 0x00);
    ScalerSetBit(P2F_08_GAMMA_BIST_CTRL1_M2, ~_BIT7, 0x00);
    ScalerSetBit(P2F_0B_GAMMA_BIST_CTRL4_M2, ~_BIT7, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. Gamma DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. Gamma DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. Gamma DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;

//-----------3D LUT DRF BIST---------------//

    DebugMessageQC("5. ====3D LUT DRF M1-1 Bist Test Start", 0x00);

    //1.Start DRF BIST mode
    ScalerSetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1,~_BIT7,0x00);
    ScalerSetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1,~_BIT7,_BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1, _BIT5, _TRUE) == _TRUE)
        {
            //3.Wait 1ms
            ScalerTimerDelayXms(2);
            ScalerSetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1,~_BIT6,_BIT6);
            ScalerSetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1,~_BIT6,0x00);
        }
        else
        {
            DebugMessageQC("5. 3D LUT DRF M1-1 Bist Test Out Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    //8.Wait DRF Bist Done
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1, _BIT4, _TRUE) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageQC("5. 3D LUT DRF M1-1 Bist Test Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }


    DebugMessageQC("5. ====3D LUT DRF M1-2 Bist Test Start", 0x00);

    //1.Start DRF BIST mode
    ScalerSetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2,~_BIT7,0x00);
    ScalerSetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2,~_BIT7,_BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2, _BIT5, _TRUE) == _TRUE)
        {
            //3.Wait 1ms
            ScalerTimerDelayXms(2);
            ScalerSetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2,~_BIT6,_BIT6);
            ScalerSetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2,~_BIT6,0x00);
        }
        else
        {
            DebugMessageQC("5. 3D LUT DRF M1-2 Bist Test Out Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    //8.Wait DRF Bist Done
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2, _BIT4, _TRUE) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageQC("5. 3D LUT DRF M1-2 Bist Test Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }

    DebugMessageQC("5. ====3D LUT DRF M2-1 Bist Test Start", 0x00);

    //1.Start DRF BIST mode
    ScalerSetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1,~_BIT7,0x00);
    ScalerSetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1,~_BIT7,_BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1, _BIT5, _TRUE) == _TRUE)
        {
            //3.Wait 1ms
            ScalerTimerDelayXms(2);
            ScalerSetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1,~_BIT6,_BIT6);
            ScalerSetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1,~_BIT6,0x00);
        }
        else
        {
            DebugMessageQC("5. 3D LUT DRF M2-1 Bist Test Out Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    //8.Wait DRF Bist Done
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1, _BIT4, _TRUE) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageQC("5. 3D LUT DRF M2-1 Bist Test Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }

    DebugMessageQC("5. ====3D LUT DRF M2-2 Bist Test Start", 0x00);

    //1.Start DRF BIST mode
    ScalerSetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2,~_BIT7,0x00);
    ScalerSetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2,~_BIT7,_BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2, _BIT5, _TRUE) == _TRUE)
        {
            //3.Wait 1ms
            ScalerTimerDelayXms(2);
            ScalerSetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2,~_BIT6,_BIT6);
            ScalerSetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2,~_BIT6,0x00);
        }
        else
        {
            DebugMessageQC("5. 3D LUT DRF M2-2 Bist Test Out Fail", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    //8.Wait DRF Bist Done
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2, _BIT4, _TRUE) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2, _BIT3) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.3", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2, _BIT2) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.2", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2, _BIT1) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.1", 0x00);
            ucBistResult |= _BIT6;
        }

        if(ScalerGetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2, _BIT0) != 0x00)
        {
            DebugMessageQC("5. DRF BIST Fail Flag for SRAM No.0", 0x00);
            ucBistResult |= _BIT6;
        }
    }
    else
    {
        DebugMessageQC("5. 3D LUT DRF M2-2 Bist Test Time Out Fail", 0x00);
        ucBistResult |= _BIT6;
    }


    //Disable 3D LUT Normal Bist Test
     ScalerSetBit(P9_B8_RGB_3D_GAMMA_DRF_BIST_MAIN1_1,~_BIT7,0x00);
     ScalerSetBit(P9_B9_RGB_3D_GAMMA_DRF_BIST_MAIN1_2,~_BIT7,0x00);
     ScalerSetBit(P9_BA_RGB_3D_GAMMA_DRF_BIST_MAIN2_1,~_BIT7,0x00);
     ScalerSetBit(P9_BB_RGB_3D_GAMMA_DRF_BIST_MAIN2_2,~_BIT7,0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. 3D LUT DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. 3D LUT DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. 3D LUT DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;


//------------Panel Uniformity  DRF BIST---------------//
    DebugMessageQC("5. ====Panel Uniformity DRF Bist Test Start", 0x00);

    ScalerSetBit(P34_0A_UN_SRAM_DRF_BIST, ~_BIT7, _BIT7);
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P34_0A_UN_SRAM_DRF_BIST, _BIT1, _BIT1) == _TRUE)
        {
            // DRF BIST Start Pause, Set DRF BIST Resume
            ScalerSetBit(P34_0A_UN_SRAM_DRF_BIST, ~_BIT6, _BIT6);
            ScalerSetBit(P34_0A_UN_SRAM_DRF_BIST, ~_BIT6, 0x00);
        }
        else
        {
            DebugMessageQC("5. Panel Uniformity DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT1;
        }
    }

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P34_0A_UN_SRAM_DRF_BIST, _BIT3, _BIT3) == _TRUE)
    {
        // BIST Fail
        if(ScalerGetBit(P34_0A_UN_SRAM_DRF_BIST, _BIT2) != 0x00)
        {
            DebugMessageQC("5. Panel Uniformity DRF Bist Fail", 0x00);
            ucBistResult |= _BIT1;
        }
    }
    else
    {
        DebugMessageQC("5. Panel Uniformity DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }

    ScalerSetBit(P34_0A_UN_SRAM_DRF_BIST, ~_BIT7, 0x00);

    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. Panel Uniformity DRF Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. Panel Uniformity DRF Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. Panel Uniformity DRF Bist FAIL", 0x00);
    }
    ucBistResult = 0x00;
*/

//------------D1 420to422 BIST---------------//

    //D1 420to422 bist function {0x312A[7],0x312B[7]} = 2'b10
    DebugMessageQC("5. ====420to422 D1 Bist Test Start", 0x00);
    ScalerSetBit(P31_2A_BIST_D1_YUV420TO422,~_BIT7,_BIT7);
    ScalerSetBit(P31_2B_DRF_BIST_D1_YUV420TO422,~_BIT7,0x00);

    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P31_2A_BIST_D1_YUV420TO422, _BIT6, _BIT6) == _TRUE)
    {
        if(ScalerGetBit(P31_2A_BIST_D1_YUV420TO422, (_BIT5 | _BIT4)) != 0x00)
        {
            DebugMessageQC("5. D1 420to422 Y Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P31_2A_BIST_D1_YUV420TO422, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. D1 420to422 UV Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

    }
    else
    {
        DebugMessageQC("5. D1 420to422 Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT0;
    }


    //D1 420to422 drf bist function {0x312A[7],0x312B[7]} = 2'b01
    /*
    DebugMessageQC("5. ====420to422 D1 DRF Bist Test Start", 0x00);

    //1.Start DRF BIST mode
    ScalerSetBit(P31_2A_BIST_D1_YUV420TO422,~_BIT7,0x00);
    ScalerSetBit(P31_2B_DRF_BIST_D1_YUV420TO422,~_BIT7,_BIT7);

    //2.Wait DRF Start Pause
    for(ucCnt = 0; ucCnt < 2; ucCnt++)
    {
        if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P31_2C_DRF_BIST_D0D1_YUV420TO422, _BIT4, _BIT4) == _TRUE)
        {
            //3.Wait 1ms
            //ScalerTimerDelayXms(2);
            ScalerSetBit(P31_2C_DRF_BIST_D0D1_YUV420TO422,~_BIT5,_BIT5);
            ScalerSetBit(P31_2C_DRF_BIST_D0D1_YUV420TO422,~_BIT5,0x00);
        }
        else
        {
            DebugMessageQC("5. D1 420to422 DRF Bist Start Pause Time Out Fail", 0x00);
            ucBistResult |= _BIT0;
        }
    }
    //8.Wait DRF Bist Done
    if(ScalerTimerPollingFlagProc(_BIST_TIMEOUT, P31_2B_DRF_BIST_D1_YUV420TO422, _BIT6, _BIT6) == _TRUE)
    {
        //9.Check Bist Pass or Fail
        if(ScalerGetBit(P31_2B_DRF_BIST_D1_YUV420TO422, (_BIT5 | _BIT4)) != 0x00)
        {
            DebugMessageQC("5. D1 420to422 Y DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };

        if(ScalerGetBit(P31_2B_DRF_BIST_D1_YUV420TO422, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != 0x00)
        {
            DebugMessageQC("5. D1 420to422 UV DRF Bist Fail", 0x00);
            ucBistResult |= _BIT7;
        };
    }
    else
    {
        DebugMessageQC("5. D1 420to422 DRF Bist Time Out Fail", 0x00);
        ucBistResult |= _BIT1;
    }
    */
    //D1 420to422 diable Bist test
    ScalerSetBit(P31_2A_BIST_D1_YUV420TO422,~_BIT7,0x00);
    ScalerSetBit(P31_2B_DRF_BIST_D1_YUV420TO422,~_BIT7,0x00);
    if(ucBistResult == 0x00)
    {
        DebugMessageQC("6. D1 420to422Bist PASS", 0x00);
    }
    else
    {
        DebugMessageQC("6. D1 420to422Bist Fail Mode", ucBistResult);
        DebugMessageQC("6. D1 420to422Bist FAIL", 0x00);
    }

    DebugMessageQC("6. Bist Test Done", 0x00);
    return _TEST_PASS;
}
#endif

//----------------------------------------------------------------------
// Description  : Polling Scaler Flag Process
// Input Value  : ucTimeout --> Timeout number (Max: 255 ms)
//                usPortAddress--> Current Port Address
//                ucRegister--> Current Port Register
//                ucBit     --> Polling Bit
//                bSuccess  --> 1 or 0 when finished for Polling Bit
// Output Value : Return _TRUE while polling success, _FALSE for timeout
//----------------------------------------------------------------------
bit ScalerQCTimerPollingPortFlagProc(WORD usTimeout, WORD usPortAddress, WORD usRegister, BYTE ucBit, bit bSuccess)
{
    WORD usTimeElapsed = 0;
    WORD usPreviousTime = 0;

    usPreviousTime = g_usTimerCounter;

    do
    {
        if(((bit)ScalerGetDataPortBit(usPortAddress, usRegister, ucBit) ^ bSuccess) == _FALSE)
        {
            return _TRUE;
        }

        if(usPreviousTime != g_usTimerCounter)
        {
            usTimeElapsed++;
            usPreviousTime = g_usTimerCounter;
        }
    }while(usTimeElapsed <= usTimeout);

    return _FALSE;
}

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
