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
// ID Code      : RL6193_Series_QC_DSPC.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_QC_DSPC__

#include "ScalerFunctionInclude.h"

#if(_FACTORY_RTD_QC_SUPPORT == _ON)

#if(_PCB_TYPE == _RL6193_QA_B_1A1H4MHL1DP_DPTX_LVDS_eDP)

#define _SIMPLE                                 0
#define _COMPLEX                                1

#define _DSPC_FPGA_CONTENT                      _COMPLEX
#define _DSPC_FPGA_TEST                         _DISABLE   // Jeyu_test

#if(_RL6193_COST_DOWN == _ON)
#define _DSPC_LVDS_COST_DOWN                    _ENABLE    // Jeyu_test
#else
#define _DSPC_LVDS_COST_DOWN                    _DISABLE   // Jeyu_test
#endif  // End of #if(_RL6193_COST_DOWN == _ON)

#if(_DSPC_LVDS_COST_DOWN == _DISABLE)
#define _DSPC_LVDS_PORT_AB                      _ON
#define _DSPC_LVDS_PORT_CD                      _ON
#define _DSPC_LVDS_PORT_EF                      _ON
#define _DSPC_LVDS_PORT_GH                      _ON

#else
#define _DSPC_LVDS_PORT_AB                      _OFF
#define _DSPC_LVDS_PORT_CD                      _ON
#define _DSPC_LVDS_PORT_EF                      _ON
#define _DSPC_LVDS_PORT_GH                      _OFF
#endif

#define pin43                                   (P3_6)   // Fred add
#define pin44                                   (P3_5)   // Fred add
BYTE GPIO_RESULT = 0x00;    // fred add
BYTE GPIO_RESULT_VBY1_A = 0x00;    // fred add
BYTE GPIO_RESULT_VBY1_B = 0x00;    // fred add
//--------------------------------------------------
// Macro of FPGA IIC
//--------------------------------------------------
#define bSWIIC_FPGA_SCL_I                       (MCU_FE12_PORT62_PIN_REG) // Pin J28, P6.2
#define bSWIIC_FPGA_SDA_I                       (MCU_FE11_PORT61_PIN_REG) // Pin H29, P6.1

#define bSWIIC_FPGA_SCL_II                      (MCU_FE1B_PORT73_PIN_REG) // Pin L28, P7.3
#define bSWIIC_FPGA_SDA_II                      (MCU_FE15_PORT65_PIN_REG) // Pin K29, P6.5

#define FPGA_SW_IIC_SDA_I_SET()                 {\
                                                    bSWIIC_FPGA_SDA_I = _TRUE;\
                                                }

#define FPGA_SW_IIC_SDA_I_CLR()                 {\
                                                    bSWIIC_FPGA_SDA_I = _FALSE;\
                                                }

#define FPGA_SW_IIC_SDA_I_CHK(x)                {\
                                                    x = bSWIIC_FPGA_SDA_I;\
                                                }

#define FPGA_SW_IIC_SCL_I_SET()                 {\
                                                    bSWIIC_FPGA_SCL_I = _TRUE;\
                                                }

#define FPGA_SW_IIC_SCL_I_CLR()                 {\
                                                    bSWIIC_FPGA_SCL_I = _FALSE;\
                                                }

#define FPGA_SW_IIC_SCL_I_CHK(x)                {\
                                                    x = bSWIIC_FPGA_SCL_I;\
                                                }

#define FPGA_SW_IIC_SDA_II_SET()                {\
                                                    bSWIIC_FPGA_SDA_II = _TRUE;\
                                                }

#define FPGA_SW_IIC_SDA_II_CLR()                {\
                                                    bSWIIC_FPGA_SDA_II = _FALSE;\
                                                }

#define FPGA_SW_IIC_SDA_II_CHK(x)               {\
                                                    x = bSWIIC_FPGA_SDA_II;\
                                                }

#define FPGA_SW_IIC_SCL_II_SET()                {\
                                                    bSWIIC_FPGA_SCL_II = _TRUE;\
                                                }

#define FPGA_SW_IIC_SCL_II_CLR()                {\
                                                    bSWIIC_FPGA_SCL_II = _FALSE;\
                                                }

#define FPGA_SW_IIC_SCL_II_CHK(x)               {\
                                                    x = bSWIIC_FPGA_SCL_II;\
                                                }


//****************************************************************************
// CODE TABLES
//****************************************************************************
//--------------------------------------------------
// LVDS Common TABLE
//--------------------------------------------------
BYTE code tQCLVDS_FT[] =
{
//////////////////////////////////////////
// Software Reset Whole Chip (0x0001[0])
//////////////////////////////////////////
/*
4, _NON_AUTOINC, 0x9F, 0x00,   // Page 00
4, _NON_AUTOINC, 0x01, 0x01,
//DELAY(20)
4, _NON_AUTOINC, 0x01, 0x00,
*/
////////////////////////////////
// RL6193 LVDS DC0 CP Pattern //
////////////////////////////////

//////////////////////////////////////////
// Enable ADC Bandgap (0x00C6[3])
//////////////////////////////////////////

4, _NON_AUTOINC, 0x9F, 0x00,   // Page 00
4, _NON_AUTOINC, 0xC6, 0x08,

//////////////////////////////////////////
// Enable GDI Bandgap (0x0BB4[7])
//////////////////////////////////////////

4, _NON_AUTOINC, 0x9F, 0x0B,   // Page 0B
4,  _NON_AUTOINC, 0xB4, 0xA0,  // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V

//*************************************************************************
// End Define Setting
//*************************************************************************

// Power on LVDS Analog
4, _NON_AUTOINC, 0x9F, 0x15,  // Page 15
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port A Power [5] LVDS Port B Power

4, _NON_AUTOINC, 0x9F, 0x55,  // Page 55
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port C Power [5] LVDS Port D Power

4, _NON_AUTOINC, 0x9F, 0x95,  // Page 95
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port E Power [5] LVDS Port F Power

4, _NON_AUTOINC, 0x9F, 0xD5,  // Page D5
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port G Power [5] LVDS Port H Power


//*************************************************************************
//  Pll Parameters Setting
//  Vref = Crystal = 14.318M
//  Target Clock = 340M
//  Target Clock = 336.473M = 14.318M * 47 / 2
//*************************************************************************

//---------PLL VCO Setting---------
4,    _AUTOINC,    0x9F,    0x01,     // page 1 (PLL)

// DPLL Reset
4,    _AUTOINC,    0xC2,    0x19,     // DPLL Power down
4,    _AUTOINC,    0xBF,    0x00,     // Reset M code
4,    _AUTOINC,    0xC0,    0x00,     // Reset N code
4,    _AUTOINC,    0xC3,    0xA1,     // VCOMD=2'b10, DPLL Bypass Calibration
4,    _AUTOINC,    0xCA,    0x01,     // [2] test enable "[0]: 1 => Enable DDS Spread Spectrum output function"

//---------DPLL Setting---------
4,    _AUTOINC,    0xC3,    0x61,     // Set VCOMD=2'b10, Auto Calibration
4,    _AUTOINC,    0xBF,    0x2D,     // M = 0x2D, DPM = 45, VCO: 340MHz
4,    _AUTOINC,    0xC0,    0x00,     // N = 00 => div 2, O_code = 0 => div 1
4,    _AUTOINC,    0xC1,    0x7C,     // [7:5] loop filter resiter  [4:3] capacitor  [3:0] charger pump current
4,    _AUTOINC,    0xDA,    0x00,     // [1:0] pixel clk divider
4,    _AUTOINC,    0xC2,    0x08,     // DPLL Power ON


//*************************************************************************
//  LVDS Digital Parameters Setting
//  LVDS Output Port: 4 Port LVDS (i.e: E~H Port copy A~D Port)
//  LVDS Clock = 84.118M = 336.473M / 4
//  LVDS Output Resolution: 10bit LVDS
//  LVDS Bitmap Reverse: Enable
//*************************************************************************

//---------Display Conversion-------------
4, _NON_AUTOINC, 0x9F, 0x39,  // page 39 (Display Conversion)
4, _NON_AUTOINC, 0x00, 0x01,  // LVDS mode
4, _NON_AUTOINC, 0x01, 0x8C,
4, _NON_AUTOINC, 0x02, 0x01,
4, _NON_AUTOINC, 0x03, 0x23,
4, _NON_AUTOINC, 0x04, 0x01,
4, _NON_AUTOINC, 0x05, 0x23,
4, _NON_AUTOINC, 0x06, 0x08,
4, _NON_AUTOINC, 0x30, 0x08,

//*************************************************************************
//  Display Timing Setting
//  Timing: 1024 x 1024
//  DCLK Polarity Inverted
//  LVDS Output DC Signal
//*************************************************************************

//---------DisplayTimingGen-------------
4, _NON_AUTOINC, 0x9F, 0x00,        // page 00
4, _AUTOINC,     0x28, 0x08,        // Frame Sync

4, _AUTOINC,     0x2A, 0x00,
5, _NON_AUTOINC, 0x2B, 0x04, 0x64,  // DHTotal = 1128
4, _AUTOINC,     0x2A, 0x02,
4, _NON_AUTOINC, 0x2B, 0x08,        // Hs End
4, _AUTOINC,     0x2A, 0x03,
5, _NON_AUTOINC, 0x2B, 0x00, 0x28,  // Hori bkg start
4, _AUTOINC,     0x2A, 0x05,
5, _NON_AUTOINC, 0x2B, 0x00, 0x28,  // Hori act start
4, _AUTOINC,     0x2A, 0x07,
5, _NON_AUTOINC, 0x2B, 0x04, 0x28,  // Hori act end
4, _AUTOINC,     0x2A, 0x09,
5, _NON_AUTOINC, 0x2B, 0x04, 0x28,  // Hori bkg end
4, _AUTOINC,     0x2A, 0x0B,
5, _NON_AUTOINC, 0x2B, 0x04, 0x0A,  // DVTotal = 1034
4, _AUTOINC,     0x2A, 0x0D,
4, _NON_AUTOINC, 0x2B, 0x03,        // Vs End
4, _AUTOINC,     0x2A, 0x0E,
5, _NON_AUTOINC, 0x2B, 0x00, 0x06,  // Vert bkg start
4, _AUTOINC,     0x2A, 0x10,
5, _NON_AUTOINC, 0x2B, 0x00, 0x06,  // Vert act start
4, _AUTOINC,     0x2A, 0x12,
5, _NON_AUTOINC, 0x2B, 0x04, 0x06,  // Vert act start
4, _AUTOINC,     0x2A, 0x14,
5, _NON_AUTOINC, 0x2B, 0x04, 0x06,  // Vert bkg end
4, _AUTOINC,     0x2A, 0x16,
5, _NON_AUTOINC, 0x2B, 0x00, 0x00,
4, _AUTOINC,     0x2A, 0x18,
5, _NON_AUTOINC, 0x2B, 0x00, 0x00,
4, _AUTOINC,     0x2A, 0x1A,
5, _NON_AUTOINC, 0x2B, 0x00, 0x00,
4, _AUTOINC,     0x2A, 0x1C,
5, _NON_AUTOINC, 0x2B, 0x00, 0x00,

4, _AUTOINC,     0x2A, 0x20,
4, _AUTOINC,     0x2B, 0x00,        // DCLK Polarity not inverted

//---------Fixed Last Line for Free Run Mode---------
4, _NON_AUTOINC, 0x2A, 0x30,
7, _NON_AUTOINC, 0x2B, 0x04, 0x0A, 0x04, 0x64,

//---------Free Run Mode---------
4,    _AUTOINC,       0x28,    0x83,       // Free Run Mode, Force Enable


//*************************************************************************
//  D Domain Pattern Generator
//  Pixel/Line Increase Enable
//*************************************************************************
//---------DPG-------------
4, _NON_AUTOINC, 0x9F, 0x07,        // Page7 (Dpg)
4, _NON_AUTOINC, 0xF0, 0x85,
4, _NON_AUTOINC, 0xF1, 0x05,
4, _NON_AUTOINC, 0xF2, 0x05,
4, _NON_AUTOINC, 0xF4, 0x01,
4, _NON_AUTOINC, 0xF5, 0x02,
4, _NON_AUTOINC, 0xF6, 0x01,
4, _NON_AUTOINC, 0xF7, 0x01,
4, _NON_AUTOINC, 0xFC, 0x00,
4, _NON_AUTOINC, 0x9F, 0x87,
4, _NON_AUTOINC, 0xF0, 0x41,
4, _NON_AUTOINC, 0xF1, 0x01,
4, _NON_AUTOINC, 0xF2, 0x01,
4, _NON_AUTOINC, 0xF6, 0x01,
4, _NON_AUTOINC, 0xF7, 0x01,

//*************************************************************************
//  LVDS Analog Parameters Setting
//  LVDS Output Port: 8 Port LVDS Power (i.e: E~H Port copy A~D Port)
//  LVDS BW Setting
//*************************************************************************

//---------Power on LVDS Power---------
4, _NON_AUTOINC, 0x9F, 0x15,  // Page 15 (AB Port)
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port A Power [5] LVDS Port B Power
4, _NON_AUTOINC, 0x01, 0x6B,
4, _NON_AUTOINC, 0x02, 0x03,
4, _NON_AUTOINC, 0x03, 0x65,
4, _NON_AUTOINC, 0x0D, 0xAB,
4, _NON_AUTOINC, 0x0E, 0xFD,
4, _NON_AUTOINC, 0x21, 0x80,
4, _NON_AUTOINC, 0x26, 0x00,
4, _NON_AUTOINC, 0x31, 0x80,
4, _NON_AUTOINC, 0x36, 0x00,

4, _NON_AUTOINC, 0x9F, 0x55,  // Page 55 (CD Port)
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port C Power [5] LVDS Port D Power
4, _NON_AUTOINC, 0x01, 0x6B,
4, _NON_AUTOINC, 0x02, 0x03,
4, _NON_AUTOINC, 0x03, 0x65,
4, _NON_AUTOINC, 0x0D, 0xAB,
4, _NON_AUTOINC, 0x0E, 0xFD,
4, _NON_AUTOINC, 0x21, 0x80,
4, _NON_AUTOINC, 0x26, 0x00,
4, _NON_AUTOINC, 0x31, 0x80,
4, _NON_AUTOINC, 0x36, 0x00,

4, _NON_AUTOINC, 0x9F, 0x95,  // Page 95 (EF Port)
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port E Power [5] LVDS Port F Power
4, _NON_AUTOINC, 0x01, 0x6B,
4, _NON_AUTOINC, 0x02, 0x03,
4, _NON_AUTOINC, 0x03, 0x65,
4, _NON_AUTOINC, 0x0D, 0xAB,
4, _NON_AUTOINC, 0x0E, 0xFD,
4, _NON_AUTOINC, 0x21, 0x80,
4, _NON_AUTOINC, 0x26, 0x00,
4, _NON_AUTOINC, 0x31, 0x80,
4, _NON_AUTOINC, 0x36, 0x00,

4, _NON_AUTOINC, 0x9F, 0xD5,  // Page D5 (GH Port)
4, _NON_AUTOINC, 0x00, 0xE0,  // [7] LVDS IBGen [6] LVDS Port G Power [5] LVDS Port H Power
4, _NON_AUTOINC, 0x01, 0x6B,
4, _NON_AUTOINC, 0x02, 0x03,
4, _NON_AUTOINC, 0x03, 0x65,
4, _NON_AUTOINC, 0x0D, 0xAB,
4, _NON_AUTOINC, 0x0E, 0xFD,
4, _NON_AUTOINC, 0x21, 0x80,
4, _NON_AUTOINC, 0x26, 0x00,
4, _NON_AUTOINC, 0x31, 0x80,
4, _NON_AUTOINC, 0x36, 0x00,

//---------Power on LVDS Power and PLL---------
4, _NON_AUTOINC, 0x9F, 0x15,  // Page 15 (AB Port)
4, _NON_AUTOINC, 0x00, 0xF8,  // [7] LVDS IBGen [6] LVDS Port A Power [5] LVDS Port B Power [4] LVDS PLL LDO [3] LVDS PLL Power

4, _NON_AUTOINC, 0x9F, 0x55,  // Page 55 (CD Port)
4, _NON_AUTOINC, 0x00, 0xF8,  // [7] LVDS IBGen [6] LVDS Port C Power [5] LVDS Port D Power [4] LVDS PLL LDO [3] LVDS PLL Power

4, _NON_AUTOINC, 0x9F, 0x95,  // Page 95 (EF Port)
4, _NON_AUTOINC, 0x00, 0xF8,  // [7] LVDS IBGen [6] LVDS Port E Power [5] LVDS Port F Power [4] LVDS PLL LDO [3] LVDS PLL Power

4, _NON_AUTOINC, 0x9F, 0xD5,  // Page D5 (GH Port)
4, _NON_AUTOINC, 0x00, 0xF8,  // [7] LVDS IBGen [6] LVDS Port G Power [5] LVDS Port H Power [4] LVDS PLL LDO [3] LVDS PLL Power

// Start Pair CRC
4,    _AUTOINC,       0x9F,    0x39,
4,    _AUTOINC,       0x30,    0x08,  // Start LVDS CRC
};

BYTE code tQCLVDS_QA_ENVIRONMENT[] =
{
//*************************************************************************
//  LVDS Digital Parameters For QA Environment Setting
//  LVDS PN Swap
//  LVDS Port Swap
//*************************************************************************

//---------Display Conversion-------------
4, _NON_AUTOINC, 0x9F, 0x39,  // page 39 (Display Conversion)
4, _NON_AUTOINC, 0x01, 0x8C,
4, _NON_AUTOINC, 0x02, 0x23,
4, _NON_AUTOINC, 0x03, 0x01,
4, _NON_AUTOINC, 0x04, 0x23,
4, _NON_AUTOINC, 0x05, 0x01,
4, _NON_AUTOINC, 0x06, 0x18,
4, _NON_AUTOINC, 0x30, 0x08,

//*************************************************************************
//  LVDS Analog Parameters Setting
//  LVDS Trace Skew Correction
//*************************************************************************

//---------LVDS Phase Interpolation---------
4, _NON_AUTOINC, 0x9F, 0x55,  // Page 55 (CD Port)
4, _NON_AUTOINC, 0x07, 0x33,  // CK7X_PI1: 2-PI
4, _NON_AUTOINC, 0x24, 0x05,  // TXD0/TXD1: CK7X_PI1
4, _NON_AUTOINC, 0x25, 0x40,  // TXD2     : CK7X_PI1

4, _NON_AUTOINC, 0x9F, 0x95,  // Page 95 (EF Port)
4, _NON_AUTOINC, 0x07, 0x37,  // CK7X_PI1: 3-PI
4, _NON_AUTOINC, 0x24, 0x05,  // TXF0/TXF1: CK7X_PI1
4, _NON_AUTOINC, 0x25, 0x40,  // TXF2     : CK7X_PI1

4, _NON_AUTOINC, 0x9F, 0xD5,  // Page D5 (GH Port)
4, _NON_AUTOINC, 0x07, 0x37,  // CK7X_PI1: 3-PI
4, _NON_AUTOINC, 0x09, 0x6F,  // CK7X_PI2: 4-PI
4, _NON_AUTOINC, 0x24, 0x0A,  // TXH0/TXH1: CK7X_PI2
4, _NON_AUTOINC, 0x25, 0x80,  // TXH2     : CK7X_PI2
4, _NON_AUTOINC, 0x34, 0x05,  // TXG0/TXG1: CK7X_PI1
4, _NON_AUTOINC, 0x35, 0x40,  // TXG2     : CK7X_PI1
};


BYTE code tQCDPTX_HBR2_21_FT[] =
{

    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x0B,        // Page 0B
    4,       _NON_AUTOINC,       0xB4,    0xA0,        // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V



// DPTX Power ON and CMU Enable
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x90,
4,    _AUTOINC,    0xA2,   0x00,

// Divider for Postdivider of CMU and Pre-divder of CMU
4,    _AUTOINC,    0xD2,   0x00,

// LDO Voltage Setting
4,    _AUTOINC,    0xD3,   0x77,

// DP Mode
4,    _AUTOINC,    0xA9,   0x80,

// Enable Fifo
4,    _AUTOINC,    0xA7,   0x80,

//CLKRD duty Setting
4,    _AUTOINC,    0xBD,   0xF0,

///////////////////////////////////////////////////
// HBR2

// VCO 750MHz~6GHz
4,    _AUTOINC,    0xBD,   0xF0,

// KVCO,Icp,Rs
4,    _AUTOINC,    0xD0,   0x73,
4,    _AUTOINC,    0xD1,   0x7E,

// N.F Code
4,    _AUTOINC,    0xDF,   0x2E,
4,    _AUTOINC,    0xDE,   0x89,
4,    _AUTOINC,    0xDD,   0x8B,
4,    _AUTOINC,    0xDD,   0x8B,

// Toggle CMU Power toggle Bit4
4,    _AUTOINC,    0xA0,   0x80,
4,    _AUTOINC,    0xA0,   0x90,

// Swing,Pre-emphasis
4,    _AUTOINC,    0xB0,   0x00,
4,    _AUTOINC,    0xB1,   0xE0,
4,    _AUTOINC,    0xB2,   0xE0,
4,    _AUTOINC,    0xB3,   0xE0,
4,    _AUTOINC,    0xB4,   0xE0,
4,    _AUTOINC,    0xB6,   0xBB,
4,    _AUTOINC,    0xB7,   0xBB,
4,    _AUTOINC,    0xB8,   0xFF,
4,    _AUTOINC,    0xB9,   0xFF,
4,    _AUTOINC,    0xBA,   0xFF,
4,    _AUTOINC,    0xBB,   0xFF,


// Idle Pattern
4,    _AUTOINC,    0x9F,   0xBB,
4,    _AUTOINC,    0x00,   0xFC,
4,    _AUTOINC,    0x01,   0x01,
4,    _AUTOINC,    0x01,   0x01,

// Inter-pair skew enable
4,    _AUTOINC,    0x0D,   0x04,

// Output data
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x9F,
4,    _AUTOINC,    0xA1,   0x00,


};

BYTE code tQCDPTX_HBR2_FT[] =
{

    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x0B,        // Page 0B
    4,       _NON_AUTOINC,       0xB4,    0xA0,        // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V



// DPTX Power ON and CMU Enable
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x90,
4,    _AUTOINC,    0xA2,   0x00,

// Divider for Postdivider of CMU and Pre-divder of CMU
4,    _AUTOINC,    0xD2,   0x00,

// LDO Voltage Setting
4,    _AUTOINC,    0xD3,   0x77,

// DP Mode
4,    _AUTOINC,    0xA9,   0x80,

// Enable Fifo
4,    _AUTOINC,    0xA7,   0x80,

//CLKRD duty Setting
4,    _AUTOINC,    0xBD,   0xF0,

///////////////////////////////////////////////////
// HBR2

// VCO 750MHz~6GHz
4,    _AUTOINC,    0xBD,   0xF0,

// KVCO,Icp,Rs
4,    _AUTOINC,    0xD0,   0x73,
4,    _AUTOINC,    0xD1,   0x7E,

// N.F Code
4,    _AUTOINC,    0xDF,   0x2E,
4,    _AUTOINC,    0xDE,   0x89,
4,    _AUTOINC,    0xDD,   0x8B,
4,    _AUTOINC,    0xDD,   0x8B,

// Toggle CMU Power toggle Bit4
4,    _AUTOINC,    0xA0,   0x80,
4,    _AUTOINC,    0xA0,   0x90,

// Swing,Pre-emphasis
4,    _AUTOINC,    0xB0,   0x00,
4,    _AUTOINC,    0xB1,   0x00,
4,    _AUTOINC,    0xB2,   0x00,
4,    _AUTOINC,    0xB3,   0x00,
4,    _AUTOINC,    0xB4,   0x00,
4,    _AUTOINC,    0xB6,   0x77,
4,    _AUTOINC,    0xB7,   0x77,
4,    _AUTOINC,    0xB8,   0x55,
4,    _AUTOINC,    0xB9,   0x55,
4,    _AUTOINC,    0xBA,   0x44,
4,    _AUTOINC,    0xBB,   0x44,


// Idle Pattern
4,    _AUTOINC,    0x9F,   0xBB,
4,    _AUTOINC,    0x00,   0xFC,
4,    _AUTOINC,    0x01,   0x01,
4,    _AUTOINC,    0x01,   0x01,

// Inter-pair skew enable
4,    _AUTOINC,    0x0D,   0x04,

// Output data
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x9F,
4,    _AUTOINC,    0xA1,   0x00,


};

BYTE code tQCDPTX_HBR_21_FT[] =
{

    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x0B,        // Page 0B
    4,       _NON_AUTOINC,       0xB4,    0xA0,        // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V



// DPTX Power ON and CMU Enable
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x90,
4,    _AUTOINC,    0xA2,   0x00,

// Divider for Postdivider of CMU and Pre-divder of CMU
4,    _AUTOINC,    0xD2,   0x00,

// LDO Voltage Setting
4,    _AUTOINC,    0xD3,   0x77,

// DP Mode
4,    _AUTOINC,    0xA9,   0x80,

// Enable Fifo
4,    _AUTOINC,    0xA7,   0x80,

//CLKRD duty Setting
4,    _AUTOINC,    0xBD,   0xF0,

///////////////////////////////////////////////////
// HBR

// VCO 1.5GHz~3GHz
4,    _AUTOINC,    0xBD,   0xF1,

// KVCO,Icp,Rs
4,    _AUTOINC,    0xD0,   0x73,
4,    _AUTOINC,    0xD1,   0x7E,

// N.F Code
4,    _AUTOINC,    0xDF,   0x2E,
4,    _AUTOINC,    0xDE,   0x89,
4,    _AUTOINC,    0xDD,   0x8B,
4,    _AUTOINC,    0xDD,   0x8B,

// Toggle CMU Power toggle Bit4
4,    _AUTOINC,    0xA0,   0x80,
4,    _AUTOINC,    0xA0,   0x90,

// Swing,Pre-emphasis
4,    _AUTOINC,    0xB0,   0x00,
4,    _AUTOINC,    0xB1,   0x1C,
4,    _AUTOINC,    0xB2,   0x1C,
4,    _AUTOINC,    0xB3,   0x1C,
4,    _AUTOINC,    0xB4,   0x1C,
4,    _AUTOINC,    0xB6,   0xFF,
4,    _AUTOINC,    0xB7,   0xFF,
4,    _AUTOINC,    0xB8,   0xFF,
4,    _AUTOINC,    0xB9,   0xFF,
4,    _AUTOINC,    0xBA,   0xAA,
4,    _AUTOINC,    0xBB,   0xAA,



///////////////////////////////////////////////////



// Idle Pattern
4,    _AUTOINC,    0x9F,   0xBB,
4,    _AUTOINC,    0x00,   0xFC,
4,    _AUTOINC,    0x01,   0x01,
4,    _AUTOINC,    0x01,   0x01,

// Inter-pair skew enable
4,    _AUTOINC,    0x0D,   0x04,

// Output data
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x9F,
4,    _AUTOINC,    0xA1,   0x00,

};

BYTE code tQCDPTX_HBR_FT[] =
{

    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x0B,        // Page 0B
    4,       _NON_AUTOINC,       0xB4,    0xA0,        // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V



// DPTX Power ON and CMU Enable
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x90,
4,    _AUTOINC,    0xA2,   0x00,

// Divider for Postdivider of CMU and Pre-divder of CMU
4,    _AUTOINC,    0xD2,   0x00,

// LDO Voltage Setting
4,    _AUTOINC,    0xD3,   0x77,

// DP Mode
4,    _AUTOINC,    0xA9,   0x80,

// Enable Fifo
4,    _AUTOINC,    0xA7,   0x80,

//CLKRD duty Setting
4,    _AUTOINC,    0xBD,   0xF0,

///////////////////////////////////////////////////
// HBR

// VCO 1.5GHz~3GHz
4,    _AUTOINC,    0xBD,   0xF1,

// KVCO,Icp,Rs
4,    _AUTOINC,    0xD0,   0x73,
4,    _AUTOINC,    0xD1,   0x7E,

// N.F Code
4,    _AUTOINC,    0xDF,   0x2E,
4,    _AUTOINC,    0xDE,   0x89,
4,    _AUTOINC,    0xDD,   0x8B,
4,    _AUTOINC,    0xDD,   0x8B,

// Toggle CMU Power toggle Bit4
4,    _AUTOINC,    0xA0,   0x80,
4,    _AUTOINC,    0xA0,   0x90,

// Swing,Pre-emphasis
4,    _AUTOINC,    0xB0,   0x00,
4,    _AUTOINC,    0xB1,   0x04,
4,    _AUTOINC,    0xB2,   0x04,
4,    _AUTOINC,    0xB3,   0x04,
4,    _AUTOINC,    0xB4,   0x04,
4,    _AUTOINC,    0xB6,   0xCC,
4,    _AUTOINC,    0xB7,   0xCC,
4,    _AUTOINC,    0xB8,   0xAA,
4,    _AUTOINC,    0xB9,   0xAA,
4,    _AUTOINC,    0xBA,   0x22,
4,    _AUTOINC,    0xBB,   0x22,

///////////////////////////////////////////////////
// Idle Pattern
4,    _AUTOINC,    0x9F,   0xBB,
4,    _AUTOINC,    0x00,   0xFC,
4,    _AUTOINC,    0x01,   0x01,
4,    _AUTOINC,    0x01,   0x01,

// Inter-pair skew enable
4,    _AUTOINC,    0x0D,   0x04,

// Output data
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x9F,
4,    _AUTOINC,    0xA1,   0x00,

};

BYTE code tQCDPTX_RBR_21_FT[] =
{
    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x0B,        // Page 0B
    4,       _NON_AUTOINC,       0xB4,    0xA0,        // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V



// DPTX Power ON and CMU Enable
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x90,
4,    _AUTOINC,    0xA2,   0x00,

// Divider for Postdivider of CMU and Pre-divder of CMU
4,    _AUTOINC,    0xD2,   0x00,

// LDO Voltage Setting
4,    _AUTOINC,    0xD3,   0x77,

// DP Mode
4,    _AUTOINC,    0xA9,   0x80,

// Enable Fifo
4,    _AUTOINC,    0xA7,   0x80,

//CLKRD duty Setting
4,    _AUTOINC,    0xBD,   0xF0,

///////////////////////////////////////////////////
// RBR


// VCO 1.5GHz~3GHz
4,    _AUTOINC,    0xBD,   0xF1,

// KVCO,Icp,Rs
4,    _AUTOINC,    0xD0,   0x73,
4,    _AUTOINC,    0xD1,   0x14,

// N.F Code
4,    _AUTOINC,    0xDF,   0x4F,
4,    _AUTOINC,    0xDE,   0xD2,
4,    _AUTOINC,    0xDD,   0x86,
4,    _AUTOINC,    0xDD,   0x86,

// Toggle CMU Power toggle Bit4
4,    _AUTOINC,    0xA0,   0x80,
4,    _AUTOINC,    0xA0,   0x90,

// Swing,Pre-emphasis
4,    _AUTOINC,    0xB0,   0x00,
4,    _AUTOINC,    0xB1,   0x1C,
4,    _AUTOINC,    0xB2,   0x1C,
4,    _AUTOINC,    0xB3,   0x1C,
4,    _AUTOINC,    0xB4,   0x1C,
4,    _AUTOINC,    0xB6,   0xFF,
4,    _AUTOINC,    0xB7,   0xFF,
4,    _AUTOINC,    0xB8,   0xFF,
4,    _AUTOINC,    0xB9,   0xFF,
4,    _AUTOINC,    0xBA,   0xAA,
4,    _AUTOINC,    0xBB,   0xAA,



///////////////////////////////////////////////////



// Idle Pattern
4,    _AUTOINC,    0x9F,   0xBB,
4,    _AUTOINC,    0x00,   0xFC,
4,    _AUTOINC,    0x01,   0x01,
4,    _AUTOINC,    0x01,   0x01,

// Inter-pair skew enable
4,    _AUTOINC,    0x0D,   0x04,

// Output data
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x9F,
4,    _AUTOINC,    0xA1,   0x00,

};


BYTE code tQCDPTX_RBR_FT[] =
{
    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////
    4,    _NON_AUTOINC,    0x9F,    0x0B,        // Page 0B
    4,       _NON_AUTOINC,       0xB4,    0xA0,        // Enable GDI Bandgap & Set GDI bandgap ouput voltage to 1.21V



// DPTX Power ON and CMU Enable
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x90,
4,    _AUTOINC,    0xA2,   0x00,

// Divider for Postdivider of CMU and Pre-divder of CMU
4,    _AUTOINC,    0xD2,   0x00,

// LDO Voltage Setting
4,    _AUTOINC,    0xD3,   0x77,

// DP Mode
4,    _AUTOINC,    0xA9,   0x80,

// Enable Fifo
4,    _AUTOINC,    0xA7,   0x80,

//CLKRD duty Setting
4,    _AUTOINC,    0xBD,   0xF0,

///////////////////////////////////////////////////
// RBR


// VCO 1.5GHz~3GHz
4,    _AUTOINC,    0xBD,   0xF1,

// KVCO,Icp,Rs
4,    _AUTOINC,    0xD0,   0x73,
4,    _AUTOINC,    0xD1,   0x14,

// N.F Code
4,    _AUTOINC,    0xDF,   0x4F,
4,    _AUTOINC,    0xDE,   0xD2,
4,    _AUTOINC,    0xDD,   0x86,
4,    _AUTOINC,    0xDD,   0x86,

// Toggle CMU Power toggle Bit4
4,    _AUTOINC,    0xA0,   0x80,
4,    _AUTOINC,    0xA0,   0x90,

// Swing,Pre-emphasis
4,    _AUTOINC,    0xB0,   0x00,
4,    _AUTOINC,    0xB1,   0x04,
4,    _AUTOINC,    0xB2,   0x04,
4,    _AUTOINC,    0xB3,   0x04,
4,    _AUTOINC,    0xB4,   0x04,
4,    _AUTOINC,    0xB6,   0xCC,
4,    _AUTOINC,    0xB7,   0xCC,
4,    _AUTOINC,    0xB8,   0xAA,
4,    _AUTOINC,    0xB9,   0xAA,
4,    _AUTOINC,    0xBA,   0x22,
4,    _AUTOINC,    0xBB,   0x22,
///////////////////////////////////////////////////
// Idle Pattern
4,    _AUTOINC,    0x9F,   0xBB,
4,    _AUTOINC,    0x00,   0xFC,
4,    _AUTOINC,    0x01,   0x01,
4,    _AUTOINC,    0x01,   0x01,

// Inter-pair skew enable
4,    _AUTOINC,    0x0D,   0x04,

// Output data
4,    _AUTOINC,    0x9F,   0xBC,
4,    _AUTOINC,    0xA0,   0x9F,
4,    _AUTOINC,    0xA1,   0x00,

};


BYTE code tQCVBY1TX_HBR_FT[] =
{
    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////

    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    // DELAY(300)


    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////

    4,    _NON_AUTOINC,    0x9F,    0x0B,       // Page 0B
    4,     _NON_AUTOINC,    0xB4,     0xA0,             // Enable GDI Bandgap &
                        // Set GDI bandgap ouput voltage to 1.21V




//*************************************************************************
// Global Setting
//*************************************************************************

4,    _AUTOINC,    0x9F,    0x39,        // page 39 (Display Conversion)
4,    _AUTOINC,    0x00,    0x04,        // DPTX Mode

4,    _AUTOINC,    0x9F,    0x38,        // page 38 (VbyOne)
4,    _AUTOINC,    0x17,    0x40,        // DPTX clk in

//*************************************************************************
//  DPTX DPll Parameters Setting
//  Vref = Crystal = 14.318M
//  Target Clock = 160M for Vby1 Analog Phy referenced Freq
//  Target Clock = 157.5M = 14.318M * 44 / 2 / 2
//*************************************************************************

//*************************************************************************
//  DPTX DPll Parameters Setting
//  Vref = Crystal = 14.318M
//  Target Clock = 210M for Vby1 Analog Phy referenced Freq
//  Target Clock = 207.6M = 14.318M * 58 / 2 / 2
//*************************************************************************

    ////////////////////////////////
    // PLL VCO Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x9F,    0xBE,        // page BE (PLL)

    ////////////////////////////////
    // DPLL Reset          //
    ////////////////////////////////
4,    _AUTOINC,    0x03,    0x09,        // DP DPLL Power down
4,    _AUTOINC,    0x00,    0x00,     // Reset M code
4,    _AUTOINC,    0x01,    0x00,     // Reset N code
4,    _AUTOINC,    0x04,    0xA1,        // VCOMD=2'b10, DPLL Bypass Calibration
4,    _AUTOINC,    0x08,    0x01,   // [0]: 1 => Enable DDS Spread Spectrum output function

    ////////////////////////////////
    // DP DPLL Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x04,    0xA1,      // Set VCOMD=2'b10
4,    _AUTOINC,    0x00,    0x3E,     // M = 0x3A, DPM = 58
4,    _AUTOINC,    0x01,    0x10,     // N = 00 => div 2, O_code = 1 => div 2
4,    _AUTOINC,    0x02,    0x5A,     // [7:5] loop filter resiter  [4:3] capacitor  [2:0] charger pump current

4,    _AUTOINC,    0x03,    0x08,    // DPLL Power ON
4,    _AUTOINC,    0x05,    0x17,    // OFFSET
4,    _AUTOINC,    0x06,    0x50,    // OFFSET
4,    _AUTOINC,    0x07,    0x04,    // OFFSET DOUBLE BUFFER



4,    _AUTOINC,    0x9F,    0x01,   // page 01 (DPLL)
4,    _AUTOINC,    0xDC,    0x1F,//02    // Ebable Vby1 clk


   ////////////////////////////////
    // D-domain DPLL Setting          //
    ////////////////////////////////

4,    _AUTOINC,    0x9F,    0x01,
4,    _AUTOINC,    0xBF,    0x51,
4,    _AUTOINC,    0xC0,    0x00,     //
4,    _AUTOINC,    0xC1,    0x7D,     //
4,    _AUTOINC,    0xC2,    0x08,     //

4,    _AUTOINC,    0xC3,    0xA1,    //

4,    _AUTOINC,    0xDA,    0x01,   //



//*************************************************************************
//  VbyOne Pll Parameters Setting
//  Target Vby1 MAC Clock = 2700M
//  Target Vby1 MAC Clock = 2700M = 207.6M * 50 / 4
//  Pin_K29: Measure Clock = 24.61M
//*************************************************************************

    ////////////////////////////////
    // Vby1 VCO Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x9F,    0x38,        // page 38 (Vby1 PLL)

    ////////////////////////////////
    // Vby1 Reset          //
    ////////////////////////////////
4,    _AUTOINC,    0xA0,    0x00,        // Vby1 Phy Power down
4,    _AUTOINC,    0xAD,    0x00,        // Vby1 PLL Power down
4,    _AUTOINC,    0x09,    0x2A,        // DPLL for Vby1 lclk is not stable
4,    _AUTOINC,    0xAF,    0x02,     // Reset M code, Reset N code

    ////////////////////////////////
    // Vby1 Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x00,    0x10,

4,    _AUTOINC,    0xAF,    0x46,

4,    _AUTOINC,    0xA0,    0x80,        // Vby1 Phy Power on
4,    _AUTOINC,    0xAD,    0x88,        // Vby1 PLL Power on
4,    _AUTOINC,    0x09,    0x6A,        // DPLL for Vby1 lclk is stable

4,    _AUTOINC,    0xAE,    0x02,        // Vbyone Analog TX Bandwidth

4,    _AUTOINC,    0xB0,    0xDC,        // PLL VCO LDO,1V regulator

4,    _AUTOINC,    0xA7,    0x44,        // Swing
4,    _AUTOINC,    0xA8,    0x44,        // Swing
4,    _AUTOINC,    0xA9,    0x44,        // Swing
4,    _AUTOINC,    0xAA,    0x44,        // Swing

4,    _AUTOINC,    0xB1,    0x00,        // Pre-emphasis
4,    _AUTOINC,    0xA3,    0x48,        // Pre-emphasis
4,    _AUTOINC,    0xA4,    0x48,        // Pre-emphasis
4,    _AUTOINC,    0xA5,    0x48,        // Pre-emphasis
4,    _AUTOINC,    0xA6,    0x48,        // Pre-emphasis

4,    _AUTOINC,    0xA2,    0xFF,        //
4,    _AUTOINC,    0xA1,    0xFF,        //
4,    _AUTOINC,    0x89,    0x60,        //

// DELAY(30000)

4,    _AUTOINC,    0x9F,    0x9C,        //
4,    _AUTOINC,    0x01,    0x01,        //
4,    _AUTOINC,    0x10,    0x80,        //
4,    _AUTOINC,    0xC9,    0x03,        //

4,    _AUTOINC,    0x9F,    0x9E,        //
4,    _AUTOINC,    0x01,    0x01,        //
4,    _AUTOINC,    0x10,    0x80,        //
4,    _AUTOINC,    0xC9,    0x03,        //
};

BYTE code tQCVBY1TX_RBR_FT[] =
{

    //////////////////////////////////////////
    // Enable ADC Bandgap (0x00C6[3])
    //////////////////////////////////////////

    4,    _NON_AUTOINC,    0x9F,    0x00,        // Page 00
    4,    _NON_AUTOINC,    0xC6,    0x08,

    // DELAY(300)


    //////////////////////////////////////////
    // Enable GDI Bandgap (0x0BB4[7])
    //////////////////////////////////////////

    4,    _NON_AUTOINC,    0x9F,    0x0B,       // Page 0B
    4,     _NON_AUTOINC,    0xB4,     0xA0,             // Enable GDI Bandgap &
                        // Set GDI bandgap ouput voltage to 1.21V




//*************************************************************************
// Global Setting
//*************************************************************************

4,    _AUTOINC,    0x9F,    0x39,        // page 39 (Display Conversion)
4,    _AUTOINC,    0x00,    0x04,        // DPTX Mode

4,    _AUTOINC,    0x9F,    0x38,        // page 38 (VbyOne)
4,    _AUTOINC,    0x17,    0x40,        // DPTX clk in

//*************************************************************************
//  DPTX DPll Parameters Setting
//  Vref = Crystal = 14.318M
//  Target Clock = 160M for Vby1 Analog Phy referenced Freq
//  Target Clock = 157.5M = 14.318M * 44 / 2 / 2
//*************************************************************************

//*************************************************************************
//  DPTX DPll Parameters Setting
//  Vref = Crystal = 14.318M
//  Target Clock = 210M for Vby1 Analog Phy referenced Freq
//  Target Clock = 207.6M = 14.318M * 58 / 2 / 2
//*************************************************************************

    ////////////////////////////////
    // PLL VCO Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x9F,    0xBE,        // page BE (PLL)

    ////////////////////////////////
    // DPLL Reset          //
    ////////////////////////////////
4,    _AUTOINC,    0x03,    0x09,        // DP DPLL Power down
4,    _AUTOINC,    0x00,    0x00,     // Reset M code
4,    _AUTOINC,    0x01,    0x00,     // Reset N code
4,    _AUTOINC,    0x04,    0xA1,        // VCOMD=2'b10, DPLL Bypass Calibration
4,    _AUTOINC,    0x08,    0x01,   // [0]: 1 => Enable DDS Spread Spectrum output function

    ////////////////////////////////
    // DP DPLL Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x04,    0xA1,      // Set VCOMD=2'b10
4,    _AUTOINC,    0x00,    0x3E,     // M = 0x3A, DPM = 58
4,    _AUTOINC,    0x01,    0x10,     // N = 00 => div 2, O_code = 1 => div 2
4,    _AUTOINC,    0x02,    0x5A,     // [7:5] loop filter resiter  [4:3] capacitor  [2:0] charger pump current

4,    _AUTOINC,    0x03,    0x08,    // DPLL Power ON
4,    _AUTOINC,    0x05,    0x17,    // OFFSET
4,    _AUTOINC,    0x06,    0x50,    // OFFSET
4,    _AUTOINC,    0x07,    0x04,    // OFFSET DOUBLE BUFFER



4,    _AUTOINC,    0x9F,    0x01,   // page 01 (DPLL)
4,    _AUTOINC,    0xDC,    0x1F,//02    // Ebable Vby1 clk


   ////////////////////////////////
    // D-domain DPLL Setting          //
    ////////////////////////////////

4,    _AUTOINC,    0x9F,    0x01,
4,    _AUTOINC,    0xBF,    0x51,
4,    _AUTOINC,    0xC0,    0x00,     //
4,    _AUTOINC,    0xC1,    0x7D,     //
4,    _AUTOINC,    0xC2,    0x08,     //

4,    _AUTOINC,    0xC3,    0xA1,    //

4,    _AUTOINC,    0xDA,    0x01,   //



//*************************************************************************
//  VbyOne Pll Parameters Setting
//  Target Vby1 MAC Clock = 1620M
//  Target Vby1 MAC Clock = 1557M = 207.6M * 30 / 4
//  Pin_K29: Measure Clock = 24.61M
//*************************************************************************

    ////////////////////////////////
    // Vby1 VCO Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x9F,    0x38,        // page 38 (Vby1 PLL)

    ////////////////////////////////
    // Vby1 Reset          //
    ////////////////////////////////
4,    _AUTOINC,    0xA0,    0x00,        // Vby1 Phy Power down
4,    _AUTOINC,    0xAD,    0x00,        // Vby1 PLL Power down
4,    _AUTOINC,    0x09,    0x2A,        // DPLL for Vby1 lclk is not stable
4,    _AUTOINC,    0xAF,    0x02,     // Reset M code, Reset N code

    ////////////////////////////////
    // Vby1 Setting          //
    ////////////////////////////////
4,    _AUTOINC,    0x00,    0x10,

4,    _AUTOINC,    0xAF,    0x4A,

4,    _AUTOINC,    0xA0,    0x80,        // Vby1 Phy Power on
4,    _AUTOINC,    0xAD,    0x88,        // Vby1 PLL Power on
4,    _AUTOINC,    0x09,    0x6A,        // DPLL for Vby1 lclk is stable

4,    _AUTOINC,    0xAE,    0x02,        // Vbyone Analog TX Bandwidth

4,    _AUTOINC,    0xB0,    0xDC,        // PLL VCO LDO,1V regulator

4,    _AUTOINC,    0xA7,    0x44,        // Swing
4,    _AUTOINC,    0xA8,    0x44,        // Swing
4,    _AUTOINC,    0xA9,    0x44,        // Swing
4,    _AUTOINC,    0xAA,    0x44,        // Swing

4,    _AUTOINC,    0xB1,    0x00,        // Pre-emphasis
4,    _AUTOINC,    0xA3,    0x48,        // Pre-emphasis
4,    _AUTOINC,    0xA4,    0x48,        // Pre-emphasis
4,    _AUTOINC,    0xA5,    0x48,        // Pre-emphasis
4,    _AUTOINC,    0xA6,    0x48,        // Pre-emphasis

4,    _AUTOINC,    0xA2,    0xFF,        //
4,    _AUTOINC,    0xA1,    0xFF,        //
4,    _AUTOINC,    0x89,    0x60,        //

// DELAY(30000)

4,    _AUTOINC,    0x9F,    0x9C,        //
4,    _AUTOINC,    0x01,    0x01,        //
4,    _AUTOINC,    0x10,    0x80,        //
4,    _AUTOINC,    0xC9,    0x03,        //

4,    _AUTOINC,    0x9F,    0x9E,        //
4,    _AUTOINC,    0x01,    0x01,        //
4,    _AUTOINC,    0x10,    0x80,        //
4,    _AUTOINC,    0xC9,    0x03,        //



};
//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerQCIICSDA_I(bit ucset);
void ScalerQCFPGASetSCLK_I(void);
void ScalerQCFPGACLRSCLK_I(void);
void ScalerQCFPGASendByte_I(BYTE ucValue);
void ScalerQCFPGASendAddr_I(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc);
void ScalerQCFPGAReadStop_I(void);
void ScalerQCFPGAWriteStop_I(void);
void ScalerQCFPGASetByte_I(BYTE ucAddr, BYTE ucValue);
BYTE ScalerQCFPGAGetByte_I(void);
void ScalerQCFPGARead_I(BYTE ucAddr, BYTE *pucArray);

void ScalerQCIICSDA_II(bit ucset);
void ScalerQCFPGASetSCLK_II(void);
void ScalerQCFPGACLRSCLK_II(void);
void ScalerQCFPGASendByte_II(BYTE ucValue);
void ScalerQCFPGASendAddr_II(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc);
void ScalerQCFPGAReadStop_II(void);
void ScalerQCFPGAWriteStop_II(void);
void ScalerQCFPGASetByte_II(BYTE ucAddr, BYTE ucValue);
BYTE ScalerQCFPGAGetByte_II(void);  // Jeyu_modify: ScalerQCFPGAGetByte_I
void ScalerQCFPGARead_II(BYTE ucAddr, BYTE *pucArray);

void ScalerQCFPGATable_I(void);
void ScalerQCFPGATable_II(void);
void ScalerQCFPGAContent(BYTE *pucpass);

bit ScalerQCDSPCTest(void);
bit ScalerQCDPTXTest(void);    //FRED ADD
bit ScalerQCVBY1TXTest(void);    //FRED ADD

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#define GET_GPIO_RESULT()                        (GPIO_RESULT)          //FRED ADD
#define GET_GPIO_RESULT_VBY1_A()                 (GPIO_RESULT_VBY1_A)   //FRED ADD
#define GET_GPIO_RESULT_VBY1_B()                 (GPIO_RESULT_VBY1_B)   //FRED ADD

//--------------------------------------------------
// Description  : Setting data with IIC_SDA_I
// Input Value  : bset  -->  Set bit of IIC_SDA_I
// Output Value : None
//--------------------------------------------------
void ScalerQCIICSDA_I(bit ucset)
{
    if(ucset == _HIGH)
    {
        FPGA_SW_IIC_SDA_I_SET();
    }

    else
    {
        FPGA_SW_IIC_SDA_I_CLR();
    }
}

//--------------------------------------------------
// Description  : Setting CLK of IIC_SCL_I
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASetSCLK_I(void)
{
    FPGA_SW_IIC_SCL_I_SET();
    FPGA_SW_IIC_SCL_I_SET();
    FPGA_SW_IIC_SCL_I_SET();
    FPGA_SW_IIC_SCL_I_SET();
    FPGA_SW_IIC_SCL_I_SET();
}

//--------------------------------------------------
// Description  : Clear CLK with IIC_SCL_I
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGACLRSCLK_I(void)
{
    FPGA_SW_IIC_SCL_I_CLR();
    FPGA_SW_IIC_SCL_I_CLR();
    FPGA_SW_IIC_SCL_I_CLR();
    FPGA_SW_IIC_SCL_I_CLR();
    FPGA_SW_IIC_SCL_I_CLR();
}

//--------------------------------------------------
// Description  : Send the data to FPGA_I's register
// Input Value  : ucValue  --> The data of FPGA_I's register where you want to write
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASendByte_I(BYTE ucValue)
{
    ScalerQCIICSDA_I((bit)(ucValue & _BIT0));
    FPGA_SW_IIC_SCL_I_CLR();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT1));
    FPGA_SW_IIC_SCL_I_SET();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT2));
    FPGA_SW_IIC_SCL_I_CLR();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT3));
    FPGA_SW_IIC_SCL_I_SET();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT4));
    FPGA_SW_IIC_SCL_I_CLR();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT5));
    FPGA_SW_IIC_SCL_I_SET();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT6));
    FPGA_SW_IIC_SCL_I_CLR();

    ScalerQCIICSDA_I((bit)(ucValue & _BIT7));
    FPGA_SW_IIC_SCL_I_SET();
}

//--------------------------------------------------
// Description  : The address of the FPGA_I's register
// Input Value  : ucAddr      --> Start address of register
//                bReadWrite  --> Setting the read/write command to FPGA_I
//                bAutoInc    --> Setting the auto/non-auto increase command to FPGA_I
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASendAddr_I(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc)
{
    FPGA_SW_IIC_SCL_I_SET();
    ScalerQCIICSDA_I(_HIGH);
    ScalerQCIICSDA_I(_LOW);
    ScalerQCIICSDA_I(_HIGH);

    ScalerQCFPGASendByte_I(ucAddr);

    ScalerQCIICSDA_I(ucReadWrite);
    FPGA_SW_IIC_SCL_I_CLR();
    ScalerQCIICSDA_I(ucAutoInc);
    FPGA_SW_IIC_SCL_I_SET();
    ScalerQCIICSDA_I(_HIGH);
}

//--------------------------------------------------
// Description  : Stop reading the FPGA_I's register
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAReadStop_I(void)
{
    ScalerQCIICSDA_I(_HIGH);
    ScalerQCIICSDA_I(_LOW);
    ScalerQCIICSDA_I(_HIGH);
    FPGA_SW_IIC_SCL_I_SET();
}

//--------------------------------------------------
// Description  : Stop writting the FPGA_I's register
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAWriteStop_I(void)
{
    FPGA_SW_IIC_SCL_I_CLR();
    FPGA_SW_IIC_SCL_I_SET();
    ScalerQCIICSDA_I(_HIGH);
    ScalerQCIICSDA_I(_LOW);
    ScalerQCIICSDA_I(_HIGH);
}

//--------------------------------------------------
// Description  : Write a data array into registers of scaler (FPGA_I)
// Input Value  : ucAddr    --> Start address of register
//                ucValue   --> Pointer of the writing data array
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASetByte_I(BYTE ucAddr, BYTE ucValue)
{
    ScalerQCFPGASendAddr_I(ucAddr, _WRITE, _NON_AUTOINC);
    ScalerQCFPGASendByte_I(ucValue);
    ScalerQCFPGAWriteStop_I();
}

//--------------------------------------------------
// Description  : Get the data of FPGA_I's register
// Input Value  : None
// Output Value : Data of FPGA_I's register
//--------------------------------------------------
BYTE ScalerQCFPGAGetByte_I(void)
{
    BYTE ucValue = 0;
    BYTE ucChk = 0;

    ScalerSetByte(P10_21_PIN_SHARE_CTRL61, 0x00); // Page 10-21 Pin H29

    ScalerQCFPGACLRSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT0;
    }

    ScalerQCFPGASetSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT1;
    }

    ScalerQCFPGACLRSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT2;
    }

    ScalerQCFPGASetSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT3;
    }

    ScalerQCFPGACLRSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT4;
    }

    ScalerQCFPGASetSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT5;
    }

    ScalerQCFPGACLRSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT6;
    }

    ScalerQCFPGASetSCLK_I();
    FPGA_SW_IIC_SDA_I_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT7;
    }

    ScalerQCFPGACLRSCLK_I();

    ScalerSetByte(P10_21_PIN_SHARE_CTRL61, 0x01); // Page 10-21 Pin H29
    return ucValue;
}

//--------------------------------------------------
// Description  : Read data from registers of scaler and put it into an reading data array (FPGA_I)
// Input Value  : ucAddr    --> Start address of register
//                pArray    --> Pointer of the reading data array
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGARead_I(BYTE ucAddr, BYTE *pucArray)
{
    ScalerQCFPGASendAddr_I(ucAddr, _READ, _NON_AUTOINC);
    *pucArray = ScalerQCFPGAGetByte_I();
    ScalerQCFPGAReadStop_I();
}


//--------------------------------------------------
// Description  : Setting data with IIC_SDA_II
// Input Value  : bset  -->  Set bit of IIC_SDA_II
// Output Value : None
//--------------------------------------------------
void ScalerQCIICSDA_II(bit ucset)
{
    if(ucset == _HIGH)
    {
        FPGA_SW_IIC_SDA_II_SET();
    }

    else
    {
        FPGA_SW_IIC_SDA_II_CLR();
    }
}

//--------------------------------------------------
// Description  : Setting CLK of IIC_SCL_II
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASetSCLK_II(void)
{
    FPGA_SW_IIC_SCL_II_SET();
    FPGA_SW_IIC_SCL_II_SET();
    FPGA_SW_IIC_SCL_II_SET();
    FPGA_SW_IIC_SCL_II_SET();
    FPGA_SW_IIC_SCL_II_SET();
}

//--------------------------------------------------
// Description  : Clear CLK with IIC_SCL_II
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGACLRSCLK_II(void)
{
    FPGA_SW_IIC_SCL_II_CLR();
    FPGA_SW_IIC_SCL_II_CLR();
    FPGA_SW_IIC_SCL_II_CLR();
    FPGA_SW_IIC_SCL_II_CLR();
    FPGA_SW_IIC_SCL_II_CLR();
}

//--------------------------------------------------
// Description  : Send the data to FPGA_II's register
// Input Value  : ucValue  --> The data of FPGA_II's register where you want to write
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASendByte_II(BYTE ucValue)
{
    ScalerQCIICSDA_II((bit)(ucValue & _BIT0));
    FPGA_SW_IIC_SCL_II_CLR();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT1));
    FPGA_SW_IIC_SCL_II_SET();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT2));
    FPGA_SW_IIC_SCL_II_CLR();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT3));
    FPGA_SW_IIC_SCL_II_SET();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT4));
    FPGA_SW_IIC_SCL_II_CLR();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT5));
    FPGA_SW_IIC_SCL_II_SET();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT6));
    FPGA_SW_IIC_SCL_II_CLR();

    ScalerQCIICSDA_II((bit)(ucValue & _BIT7));
    FPGA_SW_IIC_SCL_II_SET();
}

//--------------------------------------------------
// Description  : The address of the FPGA_II's register
// Input Value  : ucAddr      --> Start address of register
//                bReadWrite  --> Setting the read/write command to FPGA_II
//                bAutoInc    --> Setting the auto/non-auto increase command to FPGA_II
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASendAddr_II(BYTE ucAddr, bit ucReadWrite, bit ucAutoInc)
{
    FPGA_SW_IIC_SCL_II_SET();
    ScalerQCIICSDA_II(_HIGH);
    ScalerQCIICSDA_II(_LOW);
    ScalerQCIICSDA_II(_HIGH);

    ScalerQCFPGASendByte_II(ucAddr);

    ScalerQCIICSDA_II(ucReadWrite);
    FPGA_SW_IIC_SCL_II_CLR();
    ScalerQCIICSDA_II(ucAutoInc);
    FPGA_SW_IIC_SCL_II_SET();
    ScalerQCIICSDA_II(_HIGH);
}

//--------------------------------------------------
// Description  : Stop reading the FPGA_II's register
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAReadStop_II(void)
{
    ScalerQCIICSDA_II(_HIGH);
    ScalerQCIICSDA_II(_LOW);
    ScalerQCIICSDA_II(_HIGH);
    FPGA_SW_IIC_SCL_II_SET();
}

//--------------------------------------------------
// Description  : Stop writting the FPGA_II's register
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAWriteStop_II(void)
{
    FPGA_SW_IIC_SCL_II_CLR();
    FPGA_SW_IIC_SCL_II_SET();
    ScalerQCIICSDA_II(_HIGH);
    ScalerQCIICSDA_II(_LOW);
    ScalerQCIICSDA_II(_HIGH);
}

//--------------------------------------------------
// Description  : Write a data array into registers of scaler (FPGA_II)
// Input Value  : ucAddr    --> Start address of register
//                ucValue   --> Pointer of the writing data array
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGASetByte_II(BYTE ucAddr, BYTE ucValue)
{
    ScalerQCFPGASendAddr_II(ucAddr, _WRITE, _NON_AUTOINC);
    ScalerQCFPGASendByte_II(ucValue);
    ScalerQCFPGAWriteStop_II();
}

//--------------------------------------------------
// Description  : Get the data of FPGA_II's register
// Input Value  : None
// Output Value : Data of FPGA_II's register
//--------------------------------------------------
BYTE ScalerQCFPGAGetByte_II(void)
{
    BYTE ucValue = 0;
    BYTE ucChk = 0;

    ScalerSetByte(P10_25_PIN_SHARE_CTRL65, 0x00); // Page 10-25 Pin K29

    ScalerQCFPGACLRSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT0;
    }

    ScalerQCFPGASetSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT1;
    }

    ScalerQCFPGACLRSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT2;
    }

    ScalerQCFPGASetSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT3;
    }

    ScalerQCFPGACLRSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT4;
    }

    ScalerQCFPGASetSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT5;
    }

    ScalerQCFPGACLRSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT6;
    }

    ScalerQCFPGASetSCLK_II();
    FPGA_SW_IIC_SDA_II_CHK(ucChk);
    if(ucChk)
    {
        ucValue |= _BIT7;
    }

    ScalerQCFPGACLRSCLK_II();

    ScalerSetByte(P10_25_PIN_SHARE_CTRL65, 0x01); // Page 10-25 Pin K29
    return ucValue;
}

//--------------------------------------------------
// Description  : Read data from registers of scaler and put it into an reading data array (FPGA_II)
// Input Value  : ucAddr    --> Start address of register
//                pArray    --> Pointer of the reading data array
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGARead_II(BYTE ucAddr, BYTE *pucArray)
{
    ScalerQCFPGASendAddr_II(ucAddr, _READ, _NON_AUTOINC);
    *pucArray = ScalerQCFPGAGetByte_II();
    ScalerQCFPGAReadStop_II();
}

//--------------------------------------------------
// Description  : FPGA_I for LVDS configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGATable_I(void)
{
    ScalerQCFPGASetByte_I(0x00, 0x00);
    ScalerTimerDelayXms(2);

    ScalerQCFPGASetByte_I(0x00, 0x7E);
}

//--------------------------------------------------
// Description  : FPGA_II for LVDS configuration setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGATable_II(void)
{
    ScalerQCFPGASetByte_II(0x00, 0x00);
    ScalerTimerDelayXms(2);

    ScalerQCFPGASetByte_II(0x00, 0x7E);
}

//--------------------------------------------------
// Description  : The content of FPGA's setting
// Input Value  : check  --> checking the FPGA_I's register
// Output Value : None
//--------------------------------------------------
void ScalerQCFPGAContent(BYTE *pucPass)
{
    BYTE ucCheck[96];
    BYTE ucScalerCRC[96];
    BYTE ucLVDSTxPort[8];

    ScalerQCFPGARead_I(0xFC, &ucCheck[0]);
    ScalerQCFPGARead_I(0xFD, &ucCheck[1]);
    ScalerQCFPGARead_I(0xFE, &ucCheck[2]);
    ScalerQCFPGARead_I(0xFF, &ucCheck[3]);

    ScalerQCFPGARead_II(0xFC, &ucCheck[48]);
    ScalerQCFPGARead_II(0xFD, &ucCheck[49]);
    ScalerQCFPGARead_II(0xFE, &ucCheck[50]);
    ScalerQCFPGARead_II(0xFF, &ucCheck[51]);

#if(_DSPC_LVDS_COST_DOWN == _DISABLE)
    DebugMessageQC("5. DSPC LVDS Normal", 0x00);
#else
    DebugMessageQC("5. DSPC LVDS Cost-down", 0x00);
#endif

    if(((ucCheck[0] == 0x20) && (ucCheck[1] == 0x14) && (ucCheck[2] == 0x05) && (ucCheck[3] == 0x26)) || ((ucCheck[48] == 0x20) && (ucCheck[49] == 0x14) && (ucCheck[50] == 0x05) && (ucCheck[51] == 0x26)))
    {
        ScalerRead(P39_31_D_CONV_CRC_0_H, 96, &ucScalerCRC, _AUTOINC);

        //------LVDS QA Environment Setting------//
        ScalerBurstWrite(tQCLVDS_QA_ENVIRONMENT, sizeof(tQCLVDS_QA_ENVIRONMENT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

        //------Reset FPGA Setting------//
        ScalerQCFPGATable_I();
        ScalerQCFPGATable_II();

        ScalerTimerDelayXms(200);

#if((_DSPC_LVDS_PORT_AB == _ON) || (_DSPC_LVDS_PORT_CD == _ON))

        if((ucCheck[0] != 0x20) || (ucCheck[1] != 0x14) || (ucCheck[2] != 0x05) || (ucCheck[3] != 0x26))
        {
            DebugMessageQC("5. FPGA_I Flash Code Error!!", 0x00);

            *pucPass |= _TEST_FAIL;
        }
        else
        {
            ScalerQCFPGARead_I(0x20, &ucCheck[0]);
            ScalerQCFPGARead_I(0x21, &ucCheck[1]);
            ScalerQCFPGARead_I(0x22, &ucCheck[2]);
            ScalerQCFPGARead_I(0x23, &ucCheck[3]);
            ScalerQCFPGARead_I(0x24, &ucCheck[4]);
            ScalerQCFPGARead_I(0x25, &ucCheck[5]);
            ScalerQCFPGARead_I(0x26, &ucCheck[6]);
            ScalerQCFPGARead_I(0x27, &ucCheck[7]);
            ScalerQCFPGARead_I(0x28, &ucCheck[8]);
            ScalerQCFPGARead_I(0x29, &ucCheck[9]);
            ScalerQCFPGARead_I(0x2A, &ucCheck[10]);
            ScalerQCFPGARead_I(0x2B, &ucCheck[11]);
            ScalerQCFPGARead_I(0x2C, &ucCheck[12]);
            ScalerQCFPGARead_I(0x2D, &ucCheck[13]);
            ScalerQCFPGARead_I(0x2E, &ucCheck[14]);
            ScalerQCFPGARead_I(0x2F, &ucCheck[15]);
            ScalerQCFPGARead_I(0x30, &ucCheck[16]);
            ScalerQCFPGARead_I(0x31, &ucCheck[17]);
            ScalerQCFPGARead_I(0x32, &ucCheck[18]);
            ScalerQCFPGARead_I(0x33, &ucCheck[19]);
            ScalerQCFPGARead_I(0x34, &ucCheck[20]);
            ScalerQCFPGARead_I(0x35, &ucCheck[21]);
            ScalerQCFPGARead_I(0x36, &ucCheck[22]);
            ScalerQCFPGARead_I(0x37, &ucCheck[23]);
            ScalerQCFPGARead_I(0x38, &ucCheck[24]);
            ScalerQCFPGARead_I(0x39, &ucCheck[25]);
            ScalerQCFPGARead_I(0x3A, &ucCheck[26]);
            ScalerQCFPGARead_I(0x3B, &ucCheck[27]);
            ScalerQCFPGARead_I(0x3C, &ucCheck[28]);
            ScalerQCFPGARead_I(0x3D, &ucCheck[29]);
            ScalerQCFPGARead_I(0x3E, &ucCheck[30]);
            ScalerQCFPGARead_I(0x3F, &ucCheck[31]);
            ScalerQCFPGARead_I(0x40, &ucCheck[32]);
            ScalerQCFPGARead_I(0x41, &ucCheck[33]);
            ScalerQCFPGARead_I(0x42, &ucCheck[34]);
            ScalerQCFPGARead_I(0x43, &ucCheck[35]);
            ScalerQCFPGARead_I(0x44, &ucCheck[36]);
            ScalerQCFPGARead_I(0x45, &ucCheck[37]);
            ScalerQCFPGARead_I(0x46, &ucCheck[38]);
            ScalerQCFPGARead_I(0x47, &ucCheck[39]);
            ScalerQCFPGARead_I(0x48, &ucCheck[40]);
            ScalerQCFPGARead_I(0x49, &ucCheck[41]);
            ScalerQCFPGARead_I(0x4A, &ucCheck[42]);
            ScalerQCFPGARead_I(0x4B, &ucCheck[43]);
            ScalerQCFPGARead_I(0x4C, &ucCheck[44]);
            ScalerQCFPGARead_I(0x4D, &ucCheck[45]);
            ScalerQCFPGARead_I(0x4E, &ucCheck[46]);
            ScalerQCFPGARead_I(0x4F, &ucCheck[47]);

#if(_DSPC_LVDS_PORT_AB == _ON)

            if((ucCheck[24] == ucScalerCRC[24]) && (ucCheck[25] == ucScalerCRC[25]) && (ucCheck[26] == ucScalerCRC[26]) && (ucCheck[27] == ucScalerCRC[27]) && (ucCheck[28] == ucScalerCRC[28]) && (ucCheck[29] == ucScalerCRC[29]) &&
               (ucCheck[30] == ucScalerCRC[30]) && (ucCheck[31] == ucScalerCRC[31]) && (ucCheck[32] == ucScalerCRC[32]) && (ucCheck[33] == ucScalerCRC[33]) && (ucCheck[34] == ucScalerCRC[34]) && (ucCheck[35] == ucScalerCRC[35]))
            {
                ucLVDSTxPort[0] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXA Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[0] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXA Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXA Fail Start----//", 0x00);

                if((ucCheck[24] != ucScalerCRC[24]) || (ucCheck[25] != ucScalerCRC[25]))
                {
                    DebugMessageQC("5. LVDS TXA0 Fail", 0x00);
                }

                if((ucCheck[26] != ucScalerCRC[26]) || (ucCheck[27] != ucScalerCRC[27]))
                {
                    DebugMessageQC("5. LVDS TXA1 Fail", 0x00);
                }

                if((ucCheck[28] != ucScalerCRC[28]) || (ucCheck[29] != ucScalerCRC[29]))
                {
                    DebugMessageQC("5. LVDS TXA2 Fail", 0x00);
                }

                if((ucCheck[30] != ucScalerCRC[30]) || (ucCheck[31] != ucScalerCRC[31]))
                {
                    DebugMessageQC("5. LVDS TXACK Fail", 0x00);
                }

                if((ucCheck[32] != ucScalerCRC[32]) || (ucCheck[33] != ucScalerCRC[33]))
                {
                    DebugMessageQC("5. LVDS TXA3 Fail", 0x00);
                }

                if((ucCheck[34] != ucScalerCRC[34]) || (ucCheck[35] != ucScalerCRC[35]))
                {
                    DebugMessageQC("5. LVDS TXA4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXA Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

            if((ucCheck[36] == ucScalerCRC[36]) && (ucCheck[37] == ucScalerCRC[37]) && (ucCheck[38] == ucScalerCRC[38]) && (ucCheck[39] == ucScalerCRC[39]) && (ucCheck[40] == ucScalerCRC[40]) && (ucCheck[41] == ucScalerCRC[41]) &&
               (ucCheck[42] == ucScalerCRC[42]) && (ucCheck[43] == ucScalerCRC[43]) && (ucCheck[44] == ucScalerCRC[44]) && (ucCheck[45] == ucScalerCRC[45]) && (ucCheck[46] == ucScalerCRC[46]) && (ucCheck[47] == ucScalerCRC[47]))
            {
                ucLVDSTxPort[1] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXB Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[1] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXB Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXB Fail Strat----//", 0x00);

                if((ucCheck[36] != ucScalerCRC[36]) || (ucCheck[37] != ucScalerCRC[37]))
                {
                    DebugMessageQC("5. LVDS TXB0 Fail", 0x00);
                }

                if((ucCheck[38] != ucScalerCRC[38]) || (ucCheck[39] != ucScalerCRC[39]))
                {
                    DebugMessageQC("5. LVDS TXB1 Fail", 0x00);
                }

                if((ucCheck[40] != ucScalerCRC[40]) || (ucCheck[41] != ucScalerCRC[41]))
                {
                    DebugMessageQC("5. LVDS TXB2 Fail", 0x00);
                }

                if((ucCheck[42] != ucScalerCRC[42]) || (ucCheck[43] != ucScalerCRC[43]))
                {
                    DebugMessageQC("5. LVDS TXBCK Fail", 0x00);
                }

                if((ucCheck[44] != ucScalerCRC[44]) || (ucCheck[45] != ucScalerCRC[45]))
                {
                    DebugMessageQC("5. LVDS TXB3 Fail", 0x00);
                }

                if((ucCheck[46] != ucScalerCRC[46]) || (ucCheck[47] != ucScalerCRC[47]))
                {
                    DebugMessageQC("5. LVDS TXB4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXB Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

#else // Else of #if(_DSPC_LVDS_PORT_AB == _ON)

            ucLVDSTxPort[0] = _TEST_PASS; // TXA Pass
            ucLVDSTxPort[1] = _TEST_PASS; // TXB Pass

#endif // End of #if(_DSPC_LVDS_PORT_AB == _ON)

#if(_DSPC_LVDS_PORT_CD == _ON)

            if((ucCheck[0] == ucScalerCRC[0]) && (ucCheck[1] == ucScalerCRC[1]) && (ucCheck[2] == ucScalerCRC[2]) && (ucCheck[3] == ucScalerCRC[3]) && (ucCheck[4] == ucScalerCRC[4]) && (ucCheck[5] == ucScalerCRC[5]) &&
            (ucCheck[6] == ucScalerCRC[6]) && (ucCheck[7] == ucScalerCRC[7]) && (ucCheck[8] == ucScalerCRC[8]) && (ucCheck[9] == ucScalerCRC[9]) && (ucCheck[10] == ucScalerCRC[10]) && (ucCheck[11] == ucScalerCRC[11]))
            {
                ucLVDSTxPort[2] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXC Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[2] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXC Fail Start----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXC Fail----//", 0x00);

                if((ucCheck[0] != ucScalerCRC[0]) || (ucCheck[1] != ucScalerCRC[1]))
                {
                    DebugMessageQC("5. LVDS TXC0 Fail", 0x00);
                }

                if((ucCheck[2] != ucScalerCRC[2]) || (ucCheck[3] != ucScalerCRC[3]))
                {
                    DebugMessageQC("5. LVDS TXC1 Fail", 0x00);
                }

                if((ucCheck[4] != ucScalerCRC[4]) || (ucCheck[5] != ucScalerCRC[5]))
                {
                    DebugMessageQC("5. LVDS TXC2 Fail", 0x00);
                }

                if((ucCheck[6] != ucScalerCRC[6]) || (ucCheck[7] != ucScalerCRC[7]))
                {
                    DebugMessageQC("5. LVDS TXCCK Fail", 0x00);
                }

                if((ucCheck[8] != ucScalerCRC[8]) || (ucCheck[9] != ucScalerCRC[9]))
                {
                    DebugMessageQC("5. LVDS TXC3 Fail", 0x00);
                }

                if((ucCheck[10] != ucScalerCRC[10]) || (ucCheck[11] != ucScalerCRC[11]))
                {
                    DebugMessageQC("5. LVDS TXC4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXC Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

            if((ucCheck[12] == ucScalerCRC[12]) && (ucCheck[13] == ucScalerCRC[13]) && (ucCheck[14] == ucScalerCRC[14]) && (ucCheck[15] == ucScalerCRC[15]) && (ucCheck[16] == ucScalerCRC[16]) && (ucCheck[17] == ucScalerCRC[17]) &&
            (ucCheck[18] == ucScalerCRC[18]) && (ucCheck[19] == ucScalerCRC[19]) && (ucCheck[20] == ucScalerCRC[20]) && (ucCheck[21] == ucScalerCRC[21]) && (ucCheck[22] == ucScalerCRC[22]) && (ucCheck[23] == ucScalerCRC[23]))
            {
                ucLVDSTxPort[3] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXD Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[3] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXD Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXD Fail Start----//", 0x00);

                if((ucCheck[12] != ucScalerCRC[12]) || (ucCheck[13] != ucScalerCRC[13]))
                {
                    DebugMessageQC("5. LVDS TXD0 Fail", 0x00);
                }

                if((ucCheck[14] != ucScalerCRC[14]) || (ucCheck[15] != ucScalerCRC[15]))
                {
                    DebugMessageQC("5. LVDS TXD1 Fail", 0x00);
                }

                if((ucCheck[16] != ucScalerCRC[16]) || (ucCheck[17] != ucScalerCRC[17]))
                {
                    DebugMessageQC("5. LVDS TXD2 Fail", 0x00);
                }

                if((ucCheck[18] != ucScalerCRC[18]) || (ucCheck[19] != ucScalerCRC[19]))
                {
                    DebugMessageQC("5. LVDS TXDCK Fail", 0x00);
                }

                if((ucCheck[20] != ucScalerCRC[20]) || (ucCheck[21] != ucScalerCRC[21]))
                {
                    DebugMessageQC("5. LVDS TXD3 Fail", 0x00);
                }

                if((ucCheck[22] != ucScalerCRC[22]) || (ucCheck[23] != ucScalerCRC[23]))
                {
                    DebugMessageQC("5. LVDS TXD4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXD Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

#else // Else of #if(_DSPC_LVDS_PORT_CD == _ON)

        ucLVDSTxPort[2] = _TEST_PASS; // TXC Pass
        ucLVDSTxPort[3] = _TEST_PASS; // TXD Pass

#endif // End of #if(_DSPC_LVDS_PORT_CD == _ON)
        }

#else // Else of #if((_DSPC_LVDS_PORT_AB == _ON) || (_DSPC_LVDS_PORT_CD == _ON))

        ucLVDSTxPort[0] = _TEST_PASS; // TXA Pass
        ucLVDSTxPort[1] = _TEST_PASS; // TXB Pass
        ucLVDSTxPort[2] = _TEST_PASS; // TXC Pass
        ucLVDSTxPort[3] = _TEST_PASS; // TXD Pass

#endif // End of #if((_DSPC_LVDS_PORT_AB == _ON) || (_DSPC_LVDS_PORT_CD == _ON))

#if((_DSPC_LVDS_PORT_EF == _ON) || (_DSPC_LVDS_PORT_GH == _ON))

        if((ucCheck[48] != 0x20) || (ucCheck[49] != 0x14) || (ucCheck[50] != 0x05) || (ucCheck[51] != 0x26))
        {
            DebugMessageQC("5. FPGA_II Flash Code Error!!", 0x00);

            *pucPass |= _TEST_FAIL;
        }
        else
        {
            ScalerQCFPGARead_II(0x20, &ucCheck[48]);
            ScalerQCFPGARead_II(0x21, &ucCheck[49]);
            ScalerQCFPGARead_II(0x22, &ucCheck[50]);
            ScalerQCFPGARead_II(0x23, &ucCheck[51]);
            ScalerQCFPGARead_II(0x24, &ucCheck[52]);
            ScalerQCFPGARead_II(0x25, &ucCheck[53]);
            ScalerQCFPGARead_II(0x26, &ucCheck[54]);
            ScalerQCFPGARead_II(0x27, &ucCheck[55]);
            ScalerQCFPGARead_II(0x28, &ucCheck[56]);
            ScalerQCFPGARead_II(0x29, &ucCheck[57]);
            ScalerQCFPGARead_II(0x2A, &ucCheck[58]);
            ScalerQCFPGARead_II(0x2B, &ucCheck[59]);
            ScalerQCFPGARead_II(0x2C, &ucCheck[60]);
            ScalerQCFPGARead_II(0x2D, &ucCheck[61]);
            ScalerQCFPGARead_II(0x2E, &ucCheck[62]);
            ScalerQCFPGARead_II(0x2F, &ucCheck[63]);
            ScalerQCFPGARead_II(0x30, &ucCheck[64]);
            ScalerQCFPGARead_II(0x31, &ucCheck[65]);
            ScalerQCFPGARead_II(0x32, &ucCheck[66]);
            ScalerQCFPGARead_II(0x33, &ucCheck[67]);
            ScalerQCFPGARead_II(0x34, &ucCheck[68]);
            ScalerQCFPGARead_II(0x35, &ucCheck[69]);
            ScalerQCFPGARead_II(0x36, &ucCheck[70]);
            ScalerQCFPGARead_II(0x37, &ucCheck[71]);
            ScalerQCFPGARead_II(0x38, &ucCheck[72]);
            ScalerQCFPGARead_II(0x39, &ucCheck[73]);
            ScalerQCFPGARead_II(0x3A, &ucCheck[74]);
            ScalerQCFPGARead_II(0x3B, &ucCheck[75]);
            ScalerQCFPGARead_II(0x3C, &ucCheck[76]);
            ScalerQCFPGARead_II(0x3D, &ucCheck[77]);
            ScalerQCFPGARead_II(0x3E, &ucCheck[78]);
            ScalerQCFPGARead_II(0x3F, &ucCheck[79]);
            ScalerQCFPGARead_II(0x40, &ucCheck[80]);
            ScalerQCFPGARead_II(0x41, &ucCheck[81]);
            ScalerQCFPGARead_II(0x42, &ucCheck[82]);
            ScalerQCFPGARead_II(0x43, &ucCheck[83]);
            ScalerQCFPGARead_II(0x44, &ucCheck[84]);
            ScalerQCFPGARead_II(0x45, &ucCheck[85]);
            ScalerQCFPGARead_II(0x46, &ucCheck[86]);
            ScalerQCFPGARead_II(0x47, &ucCheck[87]);
            ScalerQCFPGARead_II(0x48, &ucCheck[88]);
            ScalerQCFPGARead_II(0x49, &ucCheck[89]);
            ScalerQCFPGARead_II(0x4A, &ucCheck[90]);
            ScalerQCFPGARead_II(0x4B, &ucCheck[91]);
            ScalerQCFPGARead_II(0x4C, &ucCheck[92]);
            ScalerQCFPGARead_II(0x4D, &ucCheck[93]);
            ScalerQCFPGARead_II(0x4E, &ucCheck[94]);
            ScalerQCFPGARead_II(0x4F, &ucCheck[95]);

#if(_DSPC_LVDS_PORT_EF == _ON)

            if((ucCheck[72] == ucScalerCRC[72]) && (ucCheck[73] == ucScalerCRC[73]) && (ucCheck[74] == ucScalerCRC[74]) && (ucCheck[75] == ucScalerCRC[75]) && (ucCheck[76] == ucScalerCRC[76]) && (ucCheck[77] == ucScalerCRC[77]) &&
               (ucCheck[78] == ucScalerCRC[78]) && (ucCheck[79] == ucScalerCRC[79]) && (ucCheck[80] == ucScalerCRC[80]) && (ucCheck[81] == ucScalerCRC[81]) && (ucCheck[82] == ucScalerCRC[82]) && (ucCheck[83] == ucScalerCRC[83]))
            {
                ucLVDSTxPort[4] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXE Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[4] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXE Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXE Fail Start----//", 0x00);

                if((ucCheck[72] != ucScalerCRC[72]) || (ucCheck[73] != ucScalerCRC[73]))
                {
                    DebugMessageQC("5. LVDS TXE0 Fail", 0x00);
                }

                if((ucCheck[74] != ucScalerCRC[74]) || (ucCheck[75] != ucScalerCRC[75]))
                {
                    DebugMessageQC("5. LVDS TXE1 Fail", 0x00);
                }

                if((ucCheck[76] != ucScalerCRC[76]) || (ucCheck[77] != ucScalerCRC[77]))
                {
                    DebugMessageQC("5. LVDS TXE2 Fail", 0x00);
                }

                if((ucCheck[78] != ucScalerCRC[78]) || (ucCheck[79] != ucScalerCRC[79]))
                {
                    DebugMessageQC("5. LVDS TXECK Fail", 0x00);
                }

                if((ucCheck[80] != ucScalerCRC[80]) || (ucCheck[81] != ucScalerCRC[81]))
                {
                    DebugMessageQC("5. LVDS TXE3 Fail", 0x00);
                }

                if((ucCheck[82] != ucScalerCRC[82]) || (ucCheck[83] != ucScalerCRC[83]))
                {
                    DebugMessageQC("5. LVDS TXE4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXE Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

            if((ucCheck[84] == ucScalerCRC[84]) && (ucCheck[85] == ucScalerCRC[85]) && (ucCheck[86] == ucScalerCRC[86]) && (ucCheck[87] == ucScalerCRC[87]) && (ucCheck[88] == ucScalerCRC[88]) && (ucCheck[89] == ucScalerCRC[89]) &&
               (ucCheck[90] == ucScalerCRC[90]) && (ucCheck[91] == ucScalerCRC[91]) && (ucCheck[92] == ucScalerCRC[92]) && (ucCheck[93] == ucScalerCRC[93]) && (ucCheck[94] == ucScalerCRC[94]) && (ucCheck[95] == ucScalerCRC[95]))
            {
                ucLVDSTxPort[5] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXF Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[5] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXF Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXF Fail Start----//", 0x00);

                if((ucCheck[84] != ucScalerCRC[84]) || (ucCheck[85] != ucScalerCRC[85]))
                {
                    DebugMessageQC("5. LVDS TXF0 Fail", 0x00);
                }

                if((ucCheck[86] != ucScalerCRC[86]) || (ucCheck[87] != ucScalerCRC[87]))
                {
                    DebugMessageQC("5. LVDS TXF1 Fail", 0x00);
                }

                if((ucCheck[88] != ucScalerCRC[88]) || (ucCheck[89] != ucScalerCRC[89]))
                {
                    DebugMessageQC("5. LVDS TXF2 Fail", 0x00);
                }

                if((ucCheck[90] != ucScalerCRC[90]) || (ucCheck[91] != ucScalerCRC[91]))
                {
                    DebugMessageQC("5. LVDS TXFCK Fail", 0x00);
                }

                if((ucCheck[92] != ucScalerCRC[92]) || (ucCheck[93] != ucScalerCRC[93]))
                {
                    DebugMessageQC("5. LVDS TXF3 Fail", 0x00);
                }

                if((ucCheck[94] != ucScalerCRC[94]) || (ucCheck[95] != ucScalerCRC[95]))
                {
                    DebugMessageQC("5. LVDS TXF4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXF Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

#else // Else of #if(_DSPC_LVDS_PORT_EF == _ON)

            ucLVDSTxPort[4] = _TEST_PASS; // TXE Pass
            ucLVDSTxPort[5] = _TEST_PASS; // TXF Pass

#endif // End of #if(_DSPC_LVDS_PORT_EF == _ON)

#if(_DSPC_LVDS_PORT_GH == _ON)

            if((ucCheck[48] == ucScalerCRC[48]) && (ucCheck[49] == ucScalerCRC[49]) && (ucCheck[50] == ucScalerCRC[50]) && (ucCheck[51] == ucScalerCRC[51]) && (ucCheck[52] == ucScalerCRC[52]) && (ucCheck[53] == ucScalerCRC[53]) &&
               (ucCheck[54] == ucScalerCRC[54]) && (ucCheck[55] == ucScalerCRC[55]) && (ucCheck[56] == ucScalerCRC[56]) && (ucCheck[57] == ucScalerCRC[57]) && (ucCheck[58] == ucScalerCRC[58]) && (ucCheck[59] == ucScalerCRC[59]))
            {
                ucLVDSTxPort[6] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXG Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[6] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXG Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXG Fail Start----//", 0x00);

                if((ucCheck[48] != ucScalerCRC[48]) || (ucCheck[49] != ucScalerCRC[49]))
                {
                    DebugMessageQC("5. LVDS TXG0 Fail", 0x00);
                }

                if((ucCheck[50] != ucScalerCRC[50]) || (ucCheck[51] != ucScalerCRC[51]))
                {
                    DebugMessageQC("5. LVDS TXG1 Fail", 0x00);
                }

                if((ucCheck[52] != ucScalerCRC[52]) || (ucCheck[53] != ucScalerCRC[53]))
                {
                    DebugMessageQC("5. LVDS TXG2 Fail", 0x00);
                }

                if((ucCheck[54] != ucScalerCRC[54]) || (ucCheck[55] != ucScalerCRC[55]))
                {
                    DebugMessageQC("5. LVDS TXGCK Fail", 0x00);
                }

                if((ucCheck[56] != ucScalerCRC[56]) || (ucCheck[57] != ucScalerCRC[57]))
                {
                    DebugMessageQC("5. LVDS TXG3 Fail", 0x00);
                }

                if((ucCheck[58] != ucScalerCRC[58]) || (ucCheck[59] != ucScalerCRC[59]))
                {
                    DebugMessageQC("5. LVDS TXG4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXG Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)

            }

            if((ucCheck[60] == ucScalerCRC[60]) && (ucCheck[61] == ucScalerCRC[61]) && (ucCheck[62] == ucScalerCRC[62]) && (ucCheck[63] == ucScalerCRC[63]) && (ucCheck[64] == ucScalerCRC[64]) && (ucCheck[65] == ucScalerCRC[65]) &&
               (ucCheck[66] == ucScalerCRC[66]) && (ucCheck[67] == ucScalerCRC[67]) && (ucCheck[68] == ucScalerCRC[68]) && (ucCheck[69] == ucScalerCRC[69]) && (ucCheck[70] == ucScalerCRC[70]) && (ucCheck[71] == ucScalerCRC[71]))
            {
                ucLVDSTxPort[7] = _TEST_PASS;
                DebugMessageQC("5. //----LVDS TXH Pass----//", 0x00);
            }
            else
            {
                ucLVDSTxPort[7] = _TEST_FAIL;

#if(_DSPC_FPGA_CONTENT == _SIMPLE)

                DebugMessageQC("5. //----LVDS TXH Fail----//", 0x00);

#elif(_DSPC_FPGA_CONTENT == _COMPLEX)

                DebugMessageQC("5. //----LVDS TXH Fail Start----//", 0x00);

                if((ucCheck[60] != ucScalerCRC[60]) || (ucCheck[61] != ucScalerCRC[61]))
                {
                    DebugMessageQC("5. LVDS TXH0 Fail", 0x00);
                }

                if((ucCheck[62] != ucScalerCRC[62]) || (ucCheck[63] != ucScalerCRC[63]))
                {
                    DebugMessageQC("5. LVDS TXH1 Fail", 0x00);
                }

                if((ucCheck[64] != ucScalerCRC[64]) || (ucCheck[65] != ucScalerCRC[65]))
                {
                    DebugMessageQC("5. LVDS TXH2 Fail", 0x00);
                }

                if((ucCheck[66] != ucScalerCRC[66]) || (ucCheck[67] != ucScalerCRC[67]))
                {
                    DebugMessageQC("5. LVDS TXHCK Fail", 0x00);
                }

                if((ucCheck[68] != ucScalerCRC[68]) || (ucCheck[69] != ucScalerCRC[69]))
                {
                    DebugMessageQC("5. LVDS TXH3 Fail", 0x00);
                }

                if((ucCheck[70] != ucScalerCRC[70]) || (ucCheck[71] != ucScalerCRC[71]))
                {
                    DebugMessageQC("5. LVDS TXH4 Fail", 0x00);
                }

                DebugMessageQC("5. //----LVDS TXH Fail End----//", 0x00);
#endif // End of #if(_DSPC_FPGA_CONTENT == _SIMPLE)
            }

#else // Else of #if(_DSPC_LVDS_PORT_GH == _ON)

        ucLVDSTxPort[6] = _TEST_PASS; // TXG Pass
        ucLVDSTxPort[7] = _TEST_PASS; // TXH Pass

#endif // End of #if(_DSPC_LVDS_PORT_GH == _ON)
        }

#else // Else of #if((_DSPC_LVDS_PORT_EF == _ON) || (_DSPC_LVDS_PORT_GH == _ON))

        ucLVDSTxPort[4] = _TEST_PASS; // TXE Pass
        ucLVDSTxPort[5] = _TEST_PASS; // TXF Pass
        ucLVDSTxPort[6] = _TEST_PASS; // TXG Pass
        ucLVDSTxPort[7] = _TEST_PASS; // TXH Pass

#endif // End of #if((_DSPC_LVDS_PORT_EF == _ON) || (_DSPC_LVDS_PORT_GH == _ON))

        if((ucLVDSTxPort[0] == _TEST_PASS) && (ucLVDSTxPort[1] == _TEST_PASS) && (ucLVDSTxPort[2] == _TEST_PASS) && (ucLVDSTxPort[3] == _TEST_PASS))
        {
            DebugMessageQC("5. FPGA_I Content Pass", 0x00);
            *pucPass |= _TEST_PASS;
        }
        else
        {
            DebugMessageQC("5. FPGA_I Content Fail", 0x00);
            *pucPass |= _TEST_FAIL;
        }

        if((ucLVDSTxPort[4] == _TEST_PASS) && (ucLVDSTxPort[5] == _TEST_PASS) && (ucLVDSTxPort[6] == _TEST_PASS) && (ucLVDSTxPort[7] == _TEST_PASS))
        {
            DebugMessageQC("5. FPGA_II Content Pass", 0x00);
            *pucPass |= _TEST_PASS;
        }
        else
        {
            DebugMessageQC("5. FPGA_II Content Fail", 0x00);
            *pucPass |= _TEST_FAIL;
        }
    }
    else
    {
        DebugMessageQC("5. FPGA Environment Fail", 0x00);
        *pucPass |= _TEST_FAIL;
    }
}

//************************************************//
//--------------------------------------------------
// Description  : QC DPTX Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCDPTXTest(void)
{

    BYTE ucResult = _TEST_PASS;

#if(_QC_TYPE != _RL6193_COST_DOWN_TYPE_2)

    ScalerBurstWrite(tQCDPTX_HBR2_FT, sizeof(tQCDPTX_HBR2_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    // For DP HBR2
    MCU_FE0B_PORT53_PIN_REG = 1;    //PIN36
    MCU_FE4D_PORTD5_PIN_REG = 0;    //PIN38 //Question
  //  MCU_FE03_PORT43_PIN_REG = 0;    //PIN38



    ScalerTimerDelayXms(10);


    // For DP TX TEST
    pin43 = 0;    //PIN43
    pin44 = 1;    //PIN4

    ScalerTimerDelayXms(120);

    GPIO_RESULT = 0x00  | ((BYTE)(MCU_FE08_PORT50_PIN_REG) << 1) | ((BYTE)(MCU_FE00_PORT40_PIN_REG));   // Pin37,Pin42

    DebugMessageQC("pin37", MCU_FE08_PORT50_PIN_REG);
    DebugMessageQC("pin42", MCU_FE00_PORT40_PIN_REG);
    DebugMessageQC("pin36 ==1", MCU_FE0B_PORT53_PIN_REG);
    DebugMessageQC("pin38 ==0", MCU_FE4D_PORTD5_PIN_REG);

    if(GET_GPIO_RESULT() == 0x00)
    {
        DebugMessageQC("DP HBR2___PASS---1", 0);

    }
    else
    {
        DebugMessageQC("DP HBR2___TEST 2", 0);
        // For DP HBR
        MCU_FE0B_PORT53_PIN_REG = 0;    //PIN36
        MCU_FE4D_PORTD5_PIN_REG = 1;    //PIN38

        ScalerTimerDelayXms(10);

        ScalerBurstWrite(tQCDPTX_HBR2_21_FT, sizeof(tQCDPTX_HBR2_21_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

        // For DP HBR2
        MCU_FE0B_PORT53_PIN_REG = 1;    //PIN36
        MCU_FE4D_PORTD5_PIN_REG = 0;    //PIN38

        ScalerTimerDelayXms(200);

        GPIO_RESULT = 0x00  | ((BYTE)(MCU_FE08_PORT50_PIN_REG) << 1) | ((BYTE)(MCU_FE00_PORT40_PIN_REG));   // Pin37,Pin42

         if(GET_GPIO_RESULT() == 0x00)
         {
            DebugMessageQC("DP HBR2___PASS---2", 0);

         }
         else
         {
            DebugMessageQC("DP HBR2___FAIL", 0);
         }

    }

    ScalerTimerDelayXms(50);

#endif // End of  #if(_QC_TYPE != _RL6193_COST_DOWN_TYPE_2)

    ScalerBurstWrite(tQCDPTX_HBR_FT, sizeof(tQCDPTX_HBR_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    // For DP TX TEST
    pin43 = 0;    //PIN43
    pin44 = 1;    //PIN4

    // For DP HBR
    MCU_FE0B_PORT53_PIN_REG = 0;    //PIN36
    MCU_FE4D_PORTD5_PIN_REG = 1;    //PIN38
    //MCU_FE03_PORT43_PIN_REG = 1;    //PIN38

    ScalerTimerDelayXms(120);

    GPIO_RESULT = 0x00  | ((BYTE)(MCU_FE08_PORT50_PIN_REG) << 1) | ((BYTE)(MCU_FE00_PORT40_PIN_REG));   // Pin37,Pin42

    DebugMessageQC("pin37", MCU_FE08_PORT50_PIN_REG);
    DebugMessageQC("pin42", MCU_FE00_PORT40_PIN_REG);
    DebugMessageQC("pin36 ==0", MCU_FE0B_PORT53_PIN_REG);
    DebugMessageQC("pin38 ==1", MCU_FE4D_PORTD5_PIN_REG);

    if(GET_GPIO_RESULT() == 0x00)
    {
        DebugMessageQC("DP HBR___PASS---1", 0);

    }
    else
    {
        DebugMessageQC("DP HBR___TEST 2", 0);
        // For DP HBR2
        MCU_FE0B_PORT53_PIN_REG = 1;    //PIN36
        MCU_FE4D_PORTD5_PIN_REG = 0;    //PIN38

        ScalerTimerDelayXms(10);

        ScalerBurstWrite(tQCDPTX_HBR_21_FT, sizeof(tQCDPTX_HBR_21_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

         // For DP HBR
        MCU_FE0B_PORT53_PIN_REG = 0;    //PIN36
        MCU_FE4D_PORTD5_PIN_REG = 1;    //PIN38


        ScalerTimerDelayXms(200);

        GPIO_RESULT = 0x00  | ((BYTE)(MCU_FE08_PORT50_PIN_REG) << 1) | ((BYTE)(MCU_FE00_PORT40_PIN_REG));   // Pin37,Pin42

         if(GET_GPIO_RESULT() == 0x00)
         {
            DebugMessageQC("DP HBR___PASS---2", 0);

         }
         else
         {
            DebugMessageQC("DP HBR___FAIL", 0);
         }

    }

    ScalerTimerDelayXms(50);

    ScalerBurstWrite(tQCDPTX_RBR_FT, sizeof(tQCDPTX_RBR_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    // For DP TX TEST
    pin43 = 0;    //PIN43
    pin44 = 1;    //PIN4

    // For DP RBR
    MCU_FE0B_PORT53_PIN_REG = 0;    //PIN36
    MCU_FE4D_PORTD5_PIN_REG = 0;    //PIN38

    ScalerTimerDelayXms(120);

    GPIO_RESULT = 0x00  | ((BYTE)(MCU_FE08_PORT50_PIN_REG) << 1) | ((BYTE)(MCU_FE00_PORT40_PIN_REG));   // Pin37,Pin42

    DebugMessageQC("pin37", MCU_FE08_PORT50_PIN_REG);
    DebugMessageQC("pin42", MCU_FE00_PORT40_PIN_REG);
    DebugMessageQC("pin36 ==0", MCU_FE0B_PORT53_PIN_REG);
    DebugMessageQC("pin38 ==0", MCU_FE4D_PORTD5_PIN_REG);

    if(GET_GPIO_RESULT() == 0x00)
    {
        DebugMessageQC("DP RBR___PASS---1", 0);

        MCU_FE0B_PORT53_PIN_REG = 1;    //PIN36 //FFRR

        return _TEST_PASS;

    }
    else
    {
        DebugMessageQC("DP RBR___TEST 2", 0);
        // For DP HBR
        MCU_FE0B_PORT53_PIN_REG = 0;    //PIN36
        MCU_FE4D_PORTD5_PIN_REG = 1;    //PIN38

        ScalerTimerDelayXms(10);

        ScalerBurstWrite(tQCDPTX_RBR_21_FT, sizeof(tQCDPTX_RBR_21_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

        // For DP RBR
        MCU_FE0B_PORT53_PIN_REG = 0;    //PIN36
        MCU_FE4D_PORTD5_PIN_REG = 0;    //PIN38


        ScalerTimerDelayXms(200);

        GPIO_RESULT = 0x00  | ((BYTE)(MCU_FE08_PORT50_PIN_REG) << 1) | ((BYTE)(MCU_FE00_PORT40_PIN_REG));   // Pin37,Pin42

         if(GET_GPIO_RESULT() == 0x00)
         {
            DebugMessageQC("DP RBR___PASS---2", 0);

            MCU_FE0B_PORT53_PIN_REG = 1;    //PIN36 //FFRR

            return _TEST_PASS;

         }
         else
         {
            DebugMessageQC("DP RBR___FAIL", 0);
            MCU_FE0B_PORT53_PIN_REG = 1;    //PIN36 //FFRR
         }

        return _TEST_FAIL;

    }




}


//************************************************//
//--------------------------------------------------
// Description  : QC Vby1 Tx Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCVBY1TXTest(void)
{
    BYTE ucResult = _TEST_PASS;

#if(_QC_TYPE == _RL6193_COST_DOWN_TYPE_2)
    return ucResult;
#endif

    ScalerBurstWrite(tQCVBY1TX_HBR_FT, sizeof(tQCVBY1TX_HBR_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    // For Vby1_A Tx HBR
    MCU_FE26_PORT86_PIN_REG = 0;    //PIN36
    MCU_FE42_PORTC2_PIN_REG = 1;    //PIN38

    // For Vby1_B Tx HBR
    MCU_FE34_PORTA4_PIN_REG = 0;    //PIN36
    MCU_FE35_PORTA5_PIN_REG = 1;    //PIN38

    // For Vby1_A Tx Select Test
    MCU_FE3C_PORTB4_PIN_REG = 1;    //PIN43
    MCU_FE3D_PORTB5_PIN_REG = 0;    //PIN44

    // For Vby1_B Tx Select Test
    MCU_FE02_PORT42_PIN_REG = 1;    //PIN43
    MCU_FE01_PORT41_PIN_REG = 0;    //PIN44



    ScalerTimerDelayXms(300);

    GPIO_RESULT_VBY1_A = 0x00  | ((BYTE)(MCU_FE41_PORTC1_PIN_REG) << 1) | ((BYTE)(MCU_FE40_PORTC0_PIN_REG));   // Pin37,Pin42
    GPIO_RESULT_VBY1_B = 0x00  | ((BYTE)(MCU_FE33_PORTA3_PIN_REG) << 1) | ((BYTE)(MCU_FE04_PORT44_PIN_REG));   // Pin37,Pin39

    DebugMessageQC("pin37_Vby1_A", MCU_FE41_PORTC1_PIN_REG);
    DebugMessageQC("pin42_Vby1_A", MCU_FE40_PORTC0_PIN_REG);
    DebugMessageQC("pin36 ==0_Vby1_A", MCU_FE26_PORT86_PIN_REG);
    DebugMessageQC("pin38 ==1_Vby1_A", MCU_FE42_PORTC2_PIN_REG);

    DebugMessageQC("pin37_Vby1_B", MCU_FE33_PORTA3_PIN_REG);
    DebugMessageQC("pin39_Vby1_B", MCU_FE04_PORT44_PIN_REG);
    DebugMessageQC("pin36 ==0_Vby1_B", MCU_FE34_PORTA4_PIN_REG);
    DebugMessageQC("pin38 ==1_Vby1_B", MCU_FE35_PORTA5_PIN_REG);



    if(GET_GPIO_RESULT_VBY1_A() == 0x00)
    {
        DebugMessageQC("Vby1_A HBR___PASS", 0);

    }
    else
    {

        DebugMessageQC("Vby1_A  HBR___FAIL", 0);

    }

    if(GET_GPIO_RESULT_VBY1_B() == 0x00)
    {
        DebugMessageQC("Vby1_B HBR___PASS", 0);

    }
    else
    {

        DebugMessageQC("Vby1_B  HBR___FAIL", 0);

    }

    ScalerBurstWrite(tQCVBY1TX_RBR_FT, sizeof(tQCVBY1TX_RBR_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    // For Vby1_A Tx RBR
    MCU_FE26_PORT86_PIN_REG = 0;    //PIN36
    MCU_FE42_PORTC2_PIN_REG = 0;    //PIN38

    // For Vby1_B Tx RBR
    MCU_FE34_PORTA4_PIN_REG = 0;    //PIN36
    MCU_FE35_PORTA5_PIN_REG = 0;    //PIN38

    // For Vby1_A Tx Select Test
    MCU_FE3C_PORTB4_PIN_REG = 1;    //PIN43
    MCU_FE3D_PORTB5_PIN_REG = 0;    //PIN44

    // For Vby1_B Tx Select Test
    MCU_FE02_PORT42_PIN_REG = 1;    //PIN43
    MCU_FE01_PORT41_PIN_REG = 0;    //PIN44



    ScalerTimerDelayXms(300);

    GPIO_RESULT_VBY1_A = 0x00  | ((BYTE)(MCU_FE41_PORTC1_PIN_REG) << 1) | ((BYTE)(MCU_FE40_PORTC0_PIN_REG));   // Pin37,Pin42
    GPIO_RESULT_VBY1_B = 0x00  | ((BYTE)(MCU_FE33_PORTA3_PIN_REG) << 1) | ((BYTE)(MCU_FE04_PORT44_PIN_REG));   // Pin37,Pin39

    DebugMessageQC("pin37_Vby1_A", MCU_FE41_PORTC1_PIN_REG);
    DebugMessageQC("pin42_Vby1_A", MCU_FE40_PORTC0_PIN_REG);
    DebugMessageQC("pin36 ==0_Vby1_A", MCU_FE26_PORT86_PIN_REG);
    DebugMessageQC("pin38 ==0_Vby1_A", MCU_FE42_PORTC2_PIN_REG);

    DebugMessageQC("pin37_Vby1_B", MCU_FE33_PORTA3_PIN_REG);
    DebugMessageQC("pin39_Vby1_B", MCU_FE04_PORT44_PIN_REG);
    DebugMessageQC("pin36 ==0_Vby1_B", MCU_FE34_PORTA4_PIN_REG);
    DebugMessageQC("pin38 ==0_Vby1_B", MCU_FE35_PORTA5_PIN_REG);



    if(GET_GPIO_RESULT_VBY1_A() == 0x00)
    {
        DebugMessageQC("Vby1_A RBR___PASS", 0);

    }
    else
    {

        DebugMessageQC("Vby1_A  RBR___FAIL", 0);

    }

    if(GET_GPIO_RESULT_VBY1_B() == 0x00)
    {
        DebugMessageQC("Vby1_B RBR___PASS", 0);
        return _TEST_PASS;

    }
    else
    {

        DebugMessageQC("Vby1_B  RBR___FAIL", 0);
        return _TEST_FAIL;
    }



}
//--------------------------------------------------
// Description  : QC DSPC Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCDSPCTest(void)
{
    BYTE ucResult = _TEST_PASS;
    BYTE test = 0;

    /*
    // Whole chip reset
    ScalerSetBit(P0_01_HOST_CTRL, ~_BIT0, _BIT0);

    // For Delay 10 ms
    ScalerTimerDelayXms(10);

    // Clear to 0
    ScalerSetBit(P0_01_HOST_CTRL, ~_BIT0, 0x00);
    */

    // Group A power block power cut off
    if((ScalerGetBit(P0_F0_VCCKOFF_CONTROL0, _BIT4) == _BIT4) || (ScalerGetBit(P0_09_GA_POWER_CTRL, _BIT1) == _BIT1))
    {
        // Group A Power Cut block Reset
        ScalerSetBit(P0_09_GA_POWER_CTRL, ~_BIT0, _BIT0);

        PCB_DDR_POWER(_DDR_POWER_ON);

        // Wait for DDR stable, can't delete
        ScalerTimerDelayXms(10);

        PCB_VCCK_OFF_POWER(_VCCK_OFF_POWER_ON);

        // Wait for 1.5V stable, can't delete
        ScalerTimerDelayXms(10);

        // Group A power block power isolation off
        ScalerSetBit(P0_09_GA_POWER_CTRL, ~_BIT1, 0x00);
        ScalerSetBit(P0_F0_VCCKOFF_CONTROL0, ~_BIT4, 0x00);

        // Group A Power Cut block Relase
        ScalerSetBit(P0_09_GA_POWER_CTRL, ~_BIT0, 0x00);
    }

    ScalerSetByte(P10_21_PIN_SHARE_CTRL61, 0x01); // Pin H29 SDA_I (Push-pull)
    ScalerSetByte(P10_22_PIN_SHARE_CTRL62, 0x01); // Pin J28 SCL_I (Push-pull)

    ScalerSetByte(P10_24_PIN_SHARE_CTRL64, 0x00);
    ScalerSetByte(P10_25_PIN_SHARE_CTRL65, 0x01); // Pin K29 SDA_II (Push-pull)
    ScalerSetByte(P10_2B_PIN_SHARE_CTRL73, 0x01); // Pin L28 SCL_II (Push-pull)
    ScalerTimerDelayXms(2);

#if(_DSPC_FPGA_TEST == _ENABLE)
    while(1)
    {
        //------LVDS 8_Port 85MHz------//
        ScalerBurstWrite(tQCLVDS_FT, sizeof(tQCLVDS_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

        ScalerTimerDelayXms(200);

        ScalerQCFPGAContent(&ucResult);

        while(test < 250)
        {
            ScalerDebug();

            test += 1;
        }
        test = 0;
    }

#else
    //------LVDS 8_Port 85MHz------//
    ScalerBurstWrite(tQCLVDS_FT, sizeof(tQCLVDS_FT), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    ScalerTimerDelayXms(200);

    ScalerQCFPGAContent(&ucResult);

#endif // End of #if(_DSPC_FPGA_TEST == _ENABLE)

    if(ucResult == _TEST_PASS)
    {
        DebugMessageQC("6. Display Conversion PASS", ucResult);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Display Conversion FAIL", ucResult);
        return _TEST_FAIL;
    }
}
#endif // End of #if(_PCB_TYPE == _RL6193_QA_B_1A1H4MHL1DP_DPTX_LVDS_eDP)
#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
