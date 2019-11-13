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
// ID Code      : RL6193_Series_QC_Color_IMDomain.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_QC_COLOR_IMDOMAIN__

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
//--------------------------------------------------
// Code Tables of VGA PG CRC
//--------------------------------------------------
BYTE code tVGAPG_CRC_TABLE0[] = {
    0xE8, 0xF4, 0x22, 0x12, 0x2A, 0xB5, // M1
    0xF6, 0xC8, 0x31, 0x86, 0xEF, 0xDB, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tVGAPG_CRC_TABLE1[] = {
    0x2A, 0x84, 0xE0, 0xA4, 0xBC, 0x6A, // M1
    0xDC, 0xA8, 0x15, 0xA2, 0xC8, 0xAB, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

//--------------------------------------------------
// Code Tables of ADCNR
//--------------------------------------------------
BYTE code tADCNR_CRC_TABLE0[] = {
    0xA4, 0x78, 0xF8, 0x00, 0x00, 0x00, // M1
    0x7B, 0xE9, 0x5B, 0x00, 0x00, 0x00, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

//--------------------------------------------------
// Code Tables of RingingFilter CRC
//--------------------------------------------------
BYTE code tRingingFilterTest0_ICRCTable[] = {
    0x64, 0x72, 0x63, 0xA4, 0xBC, 0x6A, // M1
    0xD6, 0xE8, 0xD0, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest1_ICRCTable[] = {
    0x5F, 0x17, 0xA9, 0xA4, 0xBC, 0x6A, // M1
    0x18, 0xB1, 0x0C, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest2_ICRCTable[] = {
    0x43, 0xDF, 0xB7, 0xA4, 0xBC, 0x6A, // M1
    0xA4, 0x30, 0x9E, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest3_ICRCTable[] = {
    0x93, 0x72, 0x24, 0xA4, 0xBC, 0x6A, // M1
    0x58, 0xF9, 0x30, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest4_ICRCTable[] = {
    0xEF, 0xCC, 0xFA, 0xA4, 0xBC, 0x6A, // M1
    0x5A, 0xA0, 0x1C, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest5_ICRCTable[] = {
    0xD8, 0xEE, 0xD6, 0xA4, 0xBC, 0x6A, // M1
    0xE0, 0xF1, 0x17, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest6_ICRCTable[] = {
    0xAC, 0x49, 0x16, 0xA4, 0xBC, 0x6A, // M1
    0x1D, 0x55, 0xFB, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tRingingFilterTest7_ICRCTable[] = {
    0x4C, 0x68, 0x0F, 0xA4, 0xBC, 0x6A, // M1
    0x17, 0x2D, 0x0E, 0xA2, 0xC8, 0xAB, // M2
};

//--------------------------------------------------
// Code Tables of DigitalFilter CRC
//--------------------------------------------------
BYTE code tDigitalFilterTest0_ICRCTable[] = {
    0x4E, 0x18, 0xE5, 0xA4, 0xBC, 0x6A, // M1
    0x85, 0x6A, 0x98, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest1_ICRCTable[] = {
    0x63, 0x98, 0x4E, 0xA4, 0xBC, 0x6A, // M1
    0xC5, 0xF9, 0x64, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest2_ICRCTable[] = {
    0x28, 0x59, 0x0F, 0xA4, 0xBC, 0x6A, // M1
    0x91, 0x13, 0x01, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest3_ICRCTable[] = {
    0x93, 0x1C, 0x37, 0xA4, 0xBC, 0x6A, // M1
    0xBE, 0xBE, 0xC3, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest4_ICRCTable[] = {
    0x72, 0xF9, 0x7A, 0xA4, 0xBC, 0x6A, // M1
    0xBE, 0x0B, 0xB0, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest5_ICRCTable[] = {
    0x72, 0xF9, 0x7A, 0xA4, 0xBC, 0x6A, // M1
    0xBE, 0x0B, 0xB0, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest6_ICRCTable[] = {
    0x72, 0xF9, 0x7A, 0xA4, 0xBC, 0x6A, // M1
    0xBE, 0x0B, 0xB0, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest7_ICRCTable[] = {
    0x73, 0x03, 0xEF, 0xA4, 0xBC, 0x6A, // M1
    0x36, 0xCA, 0x32, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest8_ICRCTable[] = {
    0x1D, 0x93, 0xF9, 0xA4, 0xBC, 0x6A, // M1
    0xB0, 0x9A, 0x6D, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest9_ICRCTable[] = {
    0x94, 0xC1, 0xCB, 0xA4, 0xBC, 0x6A, // M1
    0xB7, 0x5C, 0xA0, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest10_ICRCTable[] = {
    0x89, 0x41, 0xC4, 0xA4, 0xBC, 0x6A, // M1
    0x42, 0xA4, 0xE0, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest11_ICRCTable[] = {
    0x95, 0x24, 0x2D, 0xA4, 0xBC, 0x6A, // M1
    0xC4, 0x4B, 0x5E, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest12_ICRCTable[] = {
    0xCC, 0x2F, 0x92, 0xA4, 0xBC, 0x6A, // M1
    0x77, 0x31, 0x44, 0xA2, 0xC8, 0xAB, // M2
};
BYTE code tDigitalFilterTest13_ICRCTable[] = {
    0x72, 0xE6, 0x09, 0xA4, 0xBC, 0x6A, // M1
    0x45, 0xDD, 0xCC, 0xA2, 0xC8, 0xAB, // M2
};

//--------------------------------------------------
// Code Tables of I Domain 422to444 CRC
//--------------------------------------------------
BYTE code t422to444_Table0[] = {
    0x88, 0x08, 0xE1, 0x49, 0xD2, 0x6E, // M1
    0x88, 0x08, 0xE1, 0x49, 0xD2, 0x6E, // M2
};

BYTE code t422to444_Table1[] = {
    0xEC, 0xA3, 0x87, 0x90, 0x1F, 0xDA, // M1
    0xEC, 0xA3, 0x87, 0x90, 0x1F, 0xDA, // M2
};

BYTE code t422to444_Table2[] = {
    0x88, 0x08, 0xE1, 0x00, 0x00, 0x00, // M1
    0x88, 0x08, 0xE1, 0x00, 0x00, 0x00, // M2
};
#if(_QC_4P_MODE_ == _ON)

//------------4P-------------
BYTE code t422to444_4P_Table0[] = {
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // M1
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // M2
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // S1
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // S2
};

BYTE code t422to444_4P_Table1[] = {
    0xD4, 0xE7, 0xE2, 0x4C, 0xA2, 0x02, // M1
    0xD4, 0xE7, 0xE2, 0x4C, 0xA2, 0x02, // M2
    0xD4, 0xE7, 0xE2, 0x4C, 0xA2, 0x02, // S1
    0xD4, 0xE7, 0xE2, 0x4C, 0xA2, 0x02, // S2
};

BYTE code t422to444_4P_Table2[] = {
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // M1
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // M2
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // S1
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // S2
};

#endif
//--------------------------------------------------
// Code Tables of Format Conversion
//--------------------------------------------------
BYTE code tFC_TEST0[] =
{
    //--------Main/Sub E/O, for 1P, PIP, PBP-------
    4, _NON_AUTOINC, 0x9F, 0x31,
    4, _NON_AUTOINC, 0x00, 0x45,
    4, _NON_AUTOINC, 0x01, 0x47,
    4, _NON_AUTOINC, 0x02, 0x80,
    4, _NON_AUTOINC, 0x03, 0x00,
    4, _NON_AUTOINC, 0x04, 0x00,
    4, _NON_AUTOINC, 0x05, 0xF0,
    4, _NON_AUTOINC, 0x06, 0xDD,
    4, _NON_AUTOINC, 0x07, 0x10,
    4, _NON_AUTOINC, 0x08, 0x00,
    4, _NON_AUTOINC, 0x09, 0x10,
    4, _NON_AUTOINC, 0x0A, 0x00,
    4, _NON_AUTOINC, 0x0C, 0x70,
    4, _NON_AUTOINC, 0x0D, 0x0F,

     //---------VGIP-------------
    4, _NON_AUTOINC, 0x9F, 0x00,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x00,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x01,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x40,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x38,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
    4, _NON_AUTOINC, 0x9F, 0x40,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x00,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x01,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x40,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x38,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
    4, _NON_AUTOINC, 0x9F, 0x80,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x00,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x01,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x40,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x38,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
    4, _NON_AUTOINC, 0x9F, 0xC0,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x00,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x01,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x40,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x38,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
};

BYTE code tFC_TEST1[] =
{
    //---1/2 SD, for 4P------------
    4, _NON_AUTOINC, 0x9F, 0x31,
    4, _NON_AUTOINC, 0x00, 0x44,
    4, _NON_AUTOINC, 0x01, 0x44,
    4, _NON_AUTOINC, 0x02, 0x00,
    4, _NON_AUTOINC, 0x03, 0x00,
    4, _NON_AUTOINC, 0x04, 0x00,
    4, _NON_AUTOINC, 0x05, 0x00,
    4, _NON_AUTOINC, 0x06, 0x11,
    4, _NON_AUTOINC, 0x07, 0x10,
    4, _NON_AUTOINC, 0x08, 0x00,
    4, _NON_AUTOINC, 0x09, 0x00,
    4, _NON_AUTOINC, 0x0A, 0x00,
    4, _NON_AUTOINC, 0x0B, 0x00,
    4, _NON_AUTOINC, 0x0C, 0x70,
    4, _NON_AUTOINC, 0x0D, 0x0F,
    4, _NON_AUTOINC, 0xA0, 0x00,

    //---------VGIP-------------
    4, _NON_AUTOINC, 0x9F, 0x00,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x80,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x00,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x80,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x70,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
    4, _NON_AUTOINC, 0x9F, 0x40,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x80,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x00,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x80,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x70,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
    4, _NON_AUTOINC, 0x9F, 0x80,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x80,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x00,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x80,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x70,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
    4, _NON_AUTOINC, 0x9F, 0xC0,
    4, _NON_AUTOINC, 0x10, 0x0F,
    4, _NON_AUTOINC, 0x14, 0x80,
    4, _NON_AUTOINC, 0x15, 0x00,
    4, _NON_AUTOINC, 0x16, 0x00,
    4, _NON_AUTOINC, 0x17, 0x00,
    4, _NON_AUTOINC, 0x18, 0x80,
    4, _NON_AUTOINC, 0x19, 0x00,
    4, _NON_AUTOINC, 0x1A, 0x00,
    4, _NON_AUTOINC, 0x1B, 0x70,
    4, _NON_AUTOINC, 0x1C, 0x00,
    4, _NON_AUTOINC, 0x1D, 0x00,
};

// -----------CRC Table of Format Conversion, 4096x2160, 256 Gray Level--------
BYTE code tFC_CRC_2P[] =
{   // 2P DP dark Red 4096x2160
    0x6F, 0xFF, 0xF2, 0x00, 0x00, 0x00, // M1
    0x6F, 0xFF, 0xF2, 0x00, 0x00, 0x00, // M2
    0x6F, 0xFF, 0xF2, 0x00, 0x00, 0x00, // S1
    0x6F, 0xFF, 0xF2, 0x00, 0x00, 0x00, // S2
    _END
};

BYTE code tFC_CRC_1P[] =
{   // 1p 256 Gray 4096x2160
    0x88, 0x08, 0xE1, 0x00, 0x00, 0x00, // M1
    0x88, 0x08, 0xE1, 0x00, 0x00, 0x00, // M1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
    _END
};

BYTE code tFC_CRC_4P[] =
{   // 4P 256 Gray 2048x2160
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // M1
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // M2
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // S1
    0x31, 0x44, 0x78, 0x00, 0x00, 0x00, // S2
    _END
};

//--------------------------------------------------
// Code Tables of Color Conversion
//--------------------------------------------------
// RGB to YCC Table
BYTE code tQC_CONV_RGB2YUV_ITU709[] =  //enable RGB2YUV
{
    26, _NON_AUTOINC,   P0_9D_RGB2YCC_COEF_DATA,    0x00, 0xBA, 0x02, 0x73, 0x00, 0x3F, // h00~h02 MSB
                                                    0xFF, 0x99, 0xFE, 0xA6, 0x01, 0xC0, // h10~h12 MSB
                                                    0x01, 0xC0, 0xFE, 0x68, 0xFF, 0xD6, // h20~h22 MSB
                                                    0x31, 0x22, 0x34, 0x45, 0x70,       // h00~h22 LSB
    _END
};

// -----------CRC Table of Color Conversion------------
BYTE code tICOLORCONV_CRC_TABLE[] = {
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // M1
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

#if(_QC_4P_MODE_ == _ON)

BYTE code tICOLORCONV_4P_CRC_TABLE[] = {
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // M1
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // M2
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // S1
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // S2
};

BYTE code tICOLORCONV_2P_CRC_TABLE[] = {
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // M1
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // M2
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // S1
    0xB6, 0xD7, 0xE3, 0xDE, 0xD2, 0x03, // S2
};
#endif

//--------------------------------------------------
// Code Tables of IPG CRC
//--------------------------------------------------
BYTE code tIPG_CRC_TABLE[] = {
    0x27, 0x68, 0x99, 0x81, 0x8B, 0xEE, // M1
    0x27, 0x68, 0x99, 0x81, 0x8B, 0xEE, // M2
    0x27, 0x68, 0x99, 0x81, 0x8B, 0xEE, // S1
    0x27, 0x68, 0x99, 0x81, 0x8B, 0xEE, // S2
};

BYTE code tIPG_CRC_TABLE1[] = {
    0x8A, 0x1D, 0x08, 0xE0, 0x97, 0x01, // M1
    0x8A, 0x1D, 0x08, 0xE0, 0x97, 0x01, // M2
    0x8A, 0x1D, 0x08, 0xE0, 0x97, 0x01, // S1
    0x8A, 0x1D, 0x08, 0xE0, 0x97, 0x01, // S2
};

//--------------------------------------------------
// Code Tables of I Domain DLTI Setting
//--------------------------------------------------
BYTE code tQC_IDLTI_SETTING_1[] =
{
    0x0B,0x3F,0x01,0x01,0x20,0x00,
    0x1E,0x00,0xAA,0x01,0xBB,0x01,
    0xCC,0x01,0xDD,0x01,0xEE,0x00,
    0x0C,0x3D,0xFF,0x01,0x40,0x00,
    0x28,0x00,0x99,0x01,0xAA,0x01,
    0xBB,0x01,0xCC,0x01,0xDD,0x00,
};

BYTE code tQC_IDLTI_SETTING_2[] =
{
    0x0F,0x17,0x48,0x00,0xD8,0x00,
    0x18,0x00,0x88,0x01,0x99,0x01,
    0xAA,0x01,0xBB,0x01,0xCC,0x00,
    0x0A,0x2A,0x90,0x01,0x60,0x00,
    0x20,0x00,0x77,0x01,0x88,0x01,
    0x99,0x01,0xAA,0x01,0xBB,0x00,
};

BYTE code tQC_IDLTI_SETTING_3[] =
{
    0x0D,0x29,0xD8,0x01,0x00,0x00,
    0x1C,0x00,0x77,0x01,0x88,0x01,
    0x99,0x01,0xAA,0x01,0xBB,0x00,
    0x06,0x17,0x20,0x01,0x80,0x00,
    0x24,0x00,0x66,0x01,0x77,0x01,
    0x88,0x01,0x99,0x01,0xAA,0x00,
};

BYTE code tQC_IDLTI_SETTING_4[] =
{
    0x07,0x3F,0x01,0x01,0x20,0x00,
    0x1E,0x00,0xAA,0x01,0xBB,0x01,
    0xCC,0x01,0xDD,0x01,0xEE,0x00,
    0x0E,0x3D,0xFF,0x01,0x40,0x00,
    0x28,0x00,0x99,0x01,0xAA,0x01,
    0xBB,0x01,0xCC,0x01,0xDD,0x00,
};

BYTE code tQC_IDLTI_SETTING_5[] =
{
    0x0F,0x3E,0xA8,0x01,0x20,0x00,
    0x1E,0x00,0x55,0x01,0x66,0x01,
    0x77,0x01,0x88,0x01,0x99,0x00,
    0x0E,0x15,0x70,0x01,0xA0,0x00,
    0x26,0x00,0x44,0x01,0x55,0x01,
    0x66,0x01,0x77,0x01,0x88,0x00,
};

BYTE code tQC_IDLTI_SETTING_2P[] =
{
    0x0B,0x3F,0x01,0x01,0x20,0x00,
    0x1E,0x00,0xAA,0x01,0xBB,0x01,
    0xCC,0x01,0xDD,0x01,0xEE,0x00,
    0x0C,0x3D,0xFF,0x01,0x40,0x00,
    0x28,0x00,0x99,0x01,0xAA,0x01,
    0xBB,0x01,0xCC,0x01,0xDD,0x00,
    0x07,0x2A,0x50,0x01,0x60,0x00,
    0x38,0x00,0x88,0x01,0x99,0x01,
    0xAA,0x01,0xBB,0x01,0xCC,0x00,
    0x0E,0x2A,0xA0,0x01,0x80,0x00,
    0x4C,0x00,0x77,0x01,0x88,0x01,
    0x99,0x01,0xAA,0x01,0xBB,0x00,
};

BYTE code tQC_IDLTI_SETTING_4P[] =
{
    0x0F,0x17,0x10,0x01,0x90,0x00,
    0x78,0x00,0xCD,0x01,0xCE,0x01,
    0xEF,0x01,0xF0,0x01,0xEA,0x00,
    0x0F,0x2A,0x60,0x01,0x2C,0x00,
    0x5A,0x00,0xC1,0x01,0xC2,0x01,
    0xE3,0x01,0xF4,0x01,0xE5,0x00,
    0x0F,0x3D,0xB0,0x00,0xC8,0x00,
    0x3C,0x00,0xC6,0x01,0xC7,0x01,
    0xE8,0x01,0xF9,0x01,0xEA,0x00,
    0x0F,0x16,0xFF,0x01,0x80,0x00,
    0x48,0x00,0xCB,0x01,0xCC,0x01,
    0xED,0x01,0xFE,0x01,0xEF,0x00,
};

BYTE code tQC_IDLTI_HLW[] =
{
    0x04,0x00,0x0C,0x00,0x01,0x0E,0x03,0x2A,
};

BYTE code tQC_IDLTI_HLW_4P[] =
{
    0x02,0x00,0x06,0x00,0x02,0x1C,0x06,0x54,
};

//--------------------------------------------------
// Code Tables of I Domain DLTI CRC
//--------------------------------------------------

BYTE code tQC_IDLTI_CRCTable_1[] =
{
    0x6C, 0xD9, 0x4A, 0x07, 0x46, 0xA0, // M1
    0x6C, 0xD9, 0x4A, 0x07, 0x46, 0xA0, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tQC_IDLTI_CRCTable_2[] =
{
    0x65, 0xD4, 0x46, 0xC0, 0xDD, 0xEA, // M1
    0x65, 0xD4, 0x46, 0xC0, 0xDD, 0xEA, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tQC_IDLTI_CRCTable_3[] =
{
    0xE0, 0xE8, 0x4C, 0xEF, 0x83, 0xDC, // M1
    0xE0, 0xE8, 0x4C, 0xEF, 0x83, 0xDC, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tQC_IDLTI_CRCTable_4[] =
{
    0x55, 0x94, 0x66, 0x36, 0xE6, 0xF9, // M1
    0x55, 0x94, 0x66, 0x36, 0xE6, 0xF9, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tQC_IDLTI_CRCTable_5[] =
{
    0x04, 0x8E, 0x97, 0x90, 0xE4, 0x2E, // M1
    0x04, 0x8E, 0x97, 0x90, 0xE4, 0x2E, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tQC_IDLTI_CRCTable_2P_1[] =
{
    0x6C, 0xD9, 0x4A, 0x07, 0x46, 0xA0, // M1
    0x6C, 0xD9, 0x4A, 0x07, 0x46, 0xA0, // M2
    0x68, 0x3D, 0x95, 0xBB, 0x97, 0x6B, // S1
    0x68, 0x3D, 0x95, 0xBB, 0x97, 0x6B, // S2
};

BYTE code tQC_IDLTI_CRCTable_2P_2[] =
{
    0x9F, 0xD3, 0xA5, 0xF8, 0x60, 0x8E, // M1
    0x9F, 0xD3, 0xA5, 0xF8, 0x60, 0x8E, // M2
    0xD3, 0xDF, 0x40, 0x50, 0xF1, 0xB1, // S1
    0xD3, 0xDF, 0x40, 0x50, 0xF1, 0xB1, // S2
};

BYTE code tQC_IDLTI_CRCTable_2P_3[] =
{
    0x9D, 0xC3, 0x4A, 0x1D, 0x95, 0x9D, // M1
    0x9D, 0xC3, 0x4A, 0x1D, 0x95, 0x9D, // M2
    0x08, 0xD4, 0x38, 0x02, 0x0D, 0xB8, // S1
    0x08, 0xD4, 0x38, 0x02, 0x0D, 0xB8, // S2
};

BYTE code tQC_IDLTI_CRCTable_2P_4[] =
{
    0x6C, 0xD9, 0x4A, 0x07, 0x46, 0xA0, // M1
    0x6C, 0xD9, 0x4A, 0x07, 0x46, 0xA0, // M2
    0xF1, 0x72, 0xDF, 0xF7, 0x59, 0x41, // S1
    0xF1, 0x72, 0xDF, 0xF7, 0x59, 0x41, // S2
};

BYTE code tQC_IDLTI_CRCTable_4P_1[] =
{
    0xB9, 0x67, 0x88, 0x6C, 0x65, 0x45, // M1
    0xD1, 0xEF, 0xBF, 0xFE, 0x65, 0xF6, // M2
    0x5F, 0x45, 0x91, 0x52, 0xB8, 0x3A, // S1
    0xE9, 0xFF, 0xB3, 0x2C, 0x28, 0xAC, // S2
};

BYTE code tQC_IDLTI_CRCTable_4P_2[] =
{
    0xDF, 0xDF, 0x3F, 0x02, 0x4D, 0xBF, // M1
    0xEE, 0xA2, 0x43, 0xB4, 0x2B, 0x93, // M2
    0x3D, 0x7B, 0xF1, 0xF6, 0x3A, 0x4E, // S1
    0xA3, 0xC6, 0xE7, 0x7E, 0x92, 0xFC, // S2
};

BYTE code tQC_IDLTI_CRCTable_4P_3[] =
{
    0x41, 0xD0, 0x2E, 0xEF, 0xA3, 0x14, // M1
    0x18, 0x25, 0x65, 0xCB, 0xC5, 0x8B, // M2
    0x45, 0x56, 0xF9, 0x25, 0x09, 0x9A, // S1
    0x6D, 0x51, 0xCD, 0xD3, 0x31, 0xBE, // S2
};

//--------------------------------------------------
// Description  : I Domain Dither Table 10 -> 8 Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_12_10_TABLE[] =
{
    // 12 --> 10
    0x01, 0x32, 0x12, 0x03, 0x23, 0x10, 0x30, 0x21,
    0x23, 0x10, 0x30, 0x21, 0x01, 0x32, 0x12, 0x03,
    0x30, 0x21, 0x01, 0x32, 0x12, 0x03, 0x23, 0x10,
};

//--------------------------------------------------
// Description  : I Domain Dither Table 10 -> 6 Setting
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_12_8_TABLE[] =
{
    // 12 --> 8
    0x07, 0xF8, 0x69, 0x1E, 0xAD, 0x52, 0xC3, 0xB4,
    0xAD, 0x52, 0xC3, 0xB4, 0x07, 0xF8, 0x69, 0x1E,
    0xAD, 0x52, 0x69, 0x1E, 0xC3, 0xB4, 0x07, 0xF8,
};

//--------------------------------------------------
// Description  : I Domain Dither Sequence Table Setting
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_SEQ_TABLE[] =
{
    0xE4, 0xA2, 0x05, 0x37, 0xF6, 0x31, 0x69, 0xCB, 0x1F, 0xD2, 0xB0, 0xE6,
    0x45, 0x1B, 0x87, 0xC6, 0x9E, 0xB4, 0xC6, 0x38, 0xD4, 0xDB, 0x12, 0x1B,

    0x63, 0x27, 0x93, 0x1E, 0x36, 0x2D, 0xD8, 0x4E, 0x36, 0x2D, 0xD2, 0x39,
    0x1E, 0x8D, 0x39, 0x87, 0x36, 0xB1, 0x9C, 0xD2, 0x87, 0x27, 0x1B, 0xD8,

    0xE1, 0xF7, 0xE6, 0xB7, 0x27, 0xB9, 0x8C, 0x8E, 0xD2, 0xEB, 0x3C, 0xA6,
    0x30, 0x56, 0xAD, 0xC6, 0x61, 0xFB, 0xCB, 0x39, 0x6C, 0x5D, 0x03, 0x02,

    0xD2, 0xD8, 0x93, 0xB4, 0x2D, 0x39, 0x9C, 0x2D, 0xC9, 0x4B, 0xD2, 0x87,
    0x27, 0xE1, 0xC6, 0x93, 0x2D, 0x9C, 0xD8, 0xC6, 0x1B, 0x36, 0x93, 0x1E,
};

#if(_QC_4P_MODE_ == _ON)
//--------------------------------------------------
// Description  : I Domain Dither Sequence Table Setting
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_SEQ_TABLE2[] =
{
    0xB4, 0xC9, 0x4B, 0x2D, 0x4E, 0xC9, 0x8D, 0x9C, 0xD2, 0x39, 0x93, 0x39,
    0x63, 0x72, 0x27, 0xE4, 0x2D, 0x8D, 0xB4, 0xD8, 0xB1, 0x72, 0xC6, 0x2D,

    0x72, 0x36, 0x63, 0x1E, 0x1B, 0x4E, 0xC9, 0x87, 0xD2, 0x72, 0x4B, 0xD2,
    0x4B, 0x1B, 0x39, 0x2D, 0x8D, 0xE1, 0x6C, 0x87, 0xD8, 0xB1, 0x8D, 0x72,

    0x72, 0x1E, 0x63, 0x27, 0xD2, 0x1E, 0x6C, 0x2D, 0x8D, 0xD8, 0xE1, 0xB4,
    0x1E, 0xE1, 0x27, 0xE4, 0x8D, 0xD8, 0xB4, 0xC6, 0x6C, 0x93, 0xB1, 0xE4,

    0xD2, 0x72, 0x1B, 0x36, 0x4E, 0x78, 0xB4, 0x4B, 0x2D, 0xE1, 0x4B, 0xE4,
    0x9C, 0x78, 0xD8, 0xE4, 0x8D, 0xE1, 0x6C, 0x1E, 0xC9, 0x9C, 0x63, 0xD8,
};
#endif

//--------------------------------------------------
// Description  : I Dither Offset Table Setting
//--------------------------------------------------
BYTE code tQC_I_DOMAIN_DITHER_TEMOFFSET[] =
{
    0xE4, 0xE4, 0xE4, 0xE4,
};

//--------------------------------------------------
// Description  : I Dither Pattern 0 Result
//--------------------------------------------------
BYTE code tQC_IDITHER_CRCTable_P0[] =
{
    0xA2, 0x4C, 0xF7, 0x3C, 0x40, 0xF0, // M1
    0x22, 0xE5, 0xC6, 0x4A, 0x82, 0x45, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0x8B, 0x93, 0xEB, 0xDD, 0x83, 0x33, // M1
    0x9C, 0xB2, 0x50, 0x60, 0x9D, 0x5F, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0x46, 0xF1, 0x07, 0xD7, 0x25, 0x3D, // M1
    0x60, 0x3D, 0x75, 0xF8, 0x33, 0x32, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0x8E, 0x39, 0x39, 0xC2, 0xCD, 0xA2, // M1
    0xAA, 0x75, 0x29, 0xAC, 0x73, 0x68, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0x15, 0xAB, 0xD0, 0x92, 0x51, 0xBE, // M1
    0xD8, 0xD1, 0x4A, 0x1B, 0x89, 0xE1, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0xB5, 0x35, 0x99, 0x83, 0x5D, 0x19, // M1
    0x80, 0x78, 0x7A, 0x7D, 0x77, 0x1F, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0xB5, 0x18, 0x03, 0xA0, 0x52, 0x71, // M1
    0x18, 0xEE, 0xEC, 0x2A, 0x2E, 0xBA, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0x2E, 0x31, 0xF0, 0xDA, 0x28, 0x7F, // M1
    0x53, 0x75, 0xA1, 0x01, 0xF7, 0x02, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0x66, 0xD0, 0xD2, 0x62, 0x04, 0xB8, // M1
    0x5E, 0x13, 0xBB, 0x21, 0x6C, 0xD3, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0xE7, 0x33, 0x23, 0xF2, 0xC5, 0x31, // M1
    0xC7, 0xB2, 0xF5, 0x27, 0x63, 0x27, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0xBE, 0xB9, 0x8D, 0x72, 0xCC, 0x96, // M1
    0x27, 0x28, 0xCB, 0x4E, 0x23, 0xDF, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0xC9, 0xB5, 0xDF, 0x77, 0x0F, 0x1E, // M1
    0x30, 0x5C, 0x45, 0x65, 0x65, 0x74, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2

    0xA2, 0x4C, 0xF7, 0x3C, 0x40, 0xF0, // M1
    0x22, 0xE5, 0xC6, 0x4A, 0x82, 0x45, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

BYTE code tQC_IDITHER_CRCTable_P1[] =
{
    0x8C, 0x03, 0x61, 0xB0, 0x4F, 0x42, // M1
    0x05, 0xD7, 0x27, 0x9E, 0x4E, 0xF4, // M2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // S2
};

#if(_QC_4P_MODE_ == _ON)
BYTE code tQC_IDITHER_CRCTable_2P[] =
{
    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xA2, 0x4C, 0xF7, 0x3C, 0x40, 0xF0, // S1
    0x22, 0xE5, 0xC6, 0x4A, 0x82, 0x45, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0x8B, 0x93, 0xEB, 0xDD, 0x83, 0x33, // S1
    0x9C, 0xB2, 0x50, 0x60, 0x9D, 0x5F, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0x46, 0xF1, 0x07, 0xD7, 0x25, 0x3D, // S1
    0x60, 0x3D, 0x75, 0xF8, 0x33, 0x32, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0x8E, 0x39, 0x39, 0xC2, 0xCD, 0xA2, // S1
    0xAA, 0x75, 0x29, 0xAC, 0x73, 0x68, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0x15, 0xAB, 0xD0, 0x92, 0x51, 0xBE, // S1
    0xD8, 0xD1, 0x4A, 0x1B, 0x89, 0xE1, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xB5, 0x35, 0x99, 0x83, 0x5D, 0x19, // S1
    0x80, 0x78, 0x7A, 0x7D, 0x77, 0x1F, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xB5, 0x18, 0x03, 0xA0, 0x52, 0x71, // S1
    0x18, 0xEE, 0xEC, 0x2A, 0x2E, 0xBA, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0x2E, 0x31, 0xF0, 0xDA, 0x28, 0x7F, // S1
    0x53, 0x75, 0xA1, 0x01, 0xF7, 0x02, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0x66, 0xD0, 0xD2, 0x62, 0x04, 0xB8, // S1
    0x5E, 0x13, 0xBB, 0x21, 0x6C, 0xD3, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xE7, 0x33, 0x23, 0xF2, 0xC5, 0x31, // S1
    0xC7, 0xB2, 0xF5, 0x27, 0x63, 0x27, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xBE, 0xB9, 0x8D, 0x72, 0xCC, 0x96, // S1
    0x27, 0x28, 0xCB, 0x4E, 0x23, 0xDF, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xC9, 0xB5, 0xDF, 0x77, 0x0F, 0x1E, // S1
    0x30, 0x5C, 0x45, 0x65, 0x65, 0x74, // S2

    0x95, 0x52, 0xCD, 0x4F, 0xB9, 0xF6, // M1
    0x1C, 0x14, 0xBE, 0xAF, 0xF7, 0x6A, // M2
    0xA2, 0x4C, 0xF7, 0x3C, 0x40, 0xF0, // S1
    0x22, 0xE5, 0xC6, 0x4A, 0x82, 0x45, // S2
};

BYTE code tQC_IDITHER_CRCTable_4P[] =
{
    0xD0, 0x50, 0x29, 0x75, 0x4E, 0x88, // M1
    0xFA, 0xA5, 0xE3, 0xFF, 0x79, 0x36, // M2
    0xD0, 0x50, 0x29, 0x75, 0x4E, 0x88, // S1
    0xFA, 0xA5, 0xE3, 0xFF, 0x79, 0x36, // S2

    0xF0, 0x6F, 0x59, 0xA7, 0x74, 0x1C, // M1
    0xFB, 0x45, 0xA8, 0x0B, 0x97, 0x9A, // M2
    0xF0, 0x6F, 0x59, 0xA7, 0x74, 0x1C, // S1
    0xFB, 0x45, 0xA8, 0x0B, 0x97, 0x9A, // S2

    0xF2, 0x9E, 0xD4, 0x19, 0x4B, 0x33, // M1
    0xB0, 0x4B, 0x2A, 0x8B, 0xEB, 0x20, // M2
    0xF2, 0x9E, 0xD4, 0x19, 0x4B, 0x33, // S1
    0xB0, 0x4B, 0x2A, 0x8B, 0xEB, 0x20, // S2

    0x7D, 0xC9, 0x9D, 0xAE, 0x6F, 0x5D, // M1
    0x02, 0x23, 0xE5, 0x20, 0x78, 0x51, // M2
    0x7D, 0xC9, 0x9D, 0xAE, 0x6F, 0x5D, // S1
    0x02, 0x23, 0xE5, 0x20, 0x78, 0x51, // S2

    0x11, 0xA4, 0x1C, 0xBC, 0xEC, 0x42, // M1
    0xFA, 0xA5, 0xE3, 0xFF, 0x79, 0x36, // M2
    0x11, 0xA4, 0x1C, 0xBC, 0xEC, 0x42, // S1
    0xFA, 0xA5, 0xE3, 0xFF, 0x79, 0x36, // S2

    0x9A, 0x59, 0x98, 0x25, 0x27, 0xA4, // M1
    0xFB, 0x45, 0xA8, 0x0B, 0x97, 0x9A, // M2
    0x9A, 0x59, 0x98, 0x25, 0x27, 0xA4, // S1
    0xFB, 0x45, 0xA8, 0x0B, 0x97, 0x9A, // S2

    0x89, 0xAD, 0xAF, 0x57, 0xAD, 0x75, // M1
    0xB0, 0x4B, 0x2A, 0x8B, 0xEB, 0x20, // M2
    0x89, 0xAD, 0xAF, 0x57, 0xAD, 0x75, // S1
    0xB0, 0x4B, 0x2A, 0x8B, 0xEB, 0x20, // S2

    0xC3, 0x12, 0x0F, 0x16, 0x91, 0x97, // M1
    0x02, 0x23, 0xE5, 0x20, 0x78, 0x51, // M2
    0xC3, 0x12, 0x0F, 0x16, 0x91, 0x97, // S1
    0x02, 0x23, 0xE5, 0x20, 0x78, 0x51, // S2

    0x29, 0x64, 0xD9, 0xAC, 0x13, 0x7F, // M1
    0xFA, 0xA5, 0xE3, 0xFF, 0x79, 0x36, // M2
    0x29, 0x64, 0xD9, 0xAC, 0x13, 0x7F, // S1
    0xFA, 0xA5, 0xE3, 0xFF, 0x79, 0x36, // S2

    0xE4, 0x1D, 0x4B, 0xAB, 0xB4, 0x05, // M1
    0xFB, 0x45, 0xA8, 0x0B, 0x97, 0x9A, // M2
    0xE4, 0x1D, 0x4B, 0xAB, 0xB4, 0x05, // S1
    0xFB, 0x45, 0xA8, 0x0B, 0x97, 0x9A, // S2

    0xFA, 0xD2, 0x26, 0x59, 0x39, 0x87, // M1
    0xB0, 0x4B, 0x2A, 0x8B, 0xEB, 0x20, // M2
    0xFA, 0xD2, 0x26, 0x59, 0x39, 0x87, // S1
    0xB0, 0x4B, 0x2A, 0x8B, 0xEB, 0x20, // S2

    0xB6, 0xA7, 0x24, 0x7C, 0xBD, 0x6F, // M1
    0x02, 0x23, 0xE5, 0x20, 0x78, 0x51, // M2
    0xB6, 0xA7, 0x24, 0x7C, 0xBD, 0x6F, // S1
    0x02, 0x23, 0xE5, 0x20, 0x78, 0x51, // S2
};

BYTE tQC_IDITHER_CRCTable_4P1[] =
{
    0xEC, 0x74, 0x71, 0x82, 0xB0, 0x7D, // M1
    0x3D, 0x0F, 0x14, 0xA2, 0x2A, 0x7A, // M2
    0xEC, 0x74, 0x71, 0x82, 0xB0, 0x7D, // S1
    0x3D, 0x0F, 0x14, 0xA2, 0x2A, 0x7A, // S2
};
#endif

//--------------------------------------------------
// Code Tables of ScaleDown Coef
//--------------------------------------------------
BYTE code tQC_HSD_COEF[] =
{
    0xFB, 0x0F, 0xFE, 0x0F, 0xFD, 0x0F, 0xFC, 0x0F, 0xFB, 0x0F, 0xFA, 0x0F, 0xF7, 0x0F, 0xF5, 0x0F,
    0xF1, 0x0F, 0xED, 0x0F, 0xE9, 0x0F, 0xE4, 0x0F, 0xDE, 0x0F, 0xD9, 0x0F, 0xD3, 0x0F, 0xCD, 0x0F,
    0xC7, 0x0F, 0xDB, 0x0F, 0xF0, 0x0F, 0x0C, 0x00, 0x27, 0x00, 0x49, 0x00, 0x6B, 0x00, 0x93, 0x00,
    0xBC, 0x00, 0xEA, 0x00, 0x16, 0x01, 0x49, 0x01, 0x7A, 0x01, 0xB0, 0x01, 0xE3, 0x01, 0x1C, 0x02,
    0x84, 0x04, 0x78, 0x04, 0x6C, 0x04, 0x57, 0x04, 0x42, 0x04, 0x23, 0x04, 0x04, 0x04, 0xDC, 0x03,
    0xB4, 0x03, 0x86, 0x03, 0x59, 0x03, 0x26, 0x03, 0xF4, 0x02, 0xBD, 0x02, 0x89, 0x02, 0x50, 0x02,
    0xBA, 0x0F, 0xAF, 0x0F, 0xA7, 0x0F, 0xA1, 0x0F, 0x9C, 0x0F, 0x9A, 0x0F, 0x9A, 0x0F, 0x9C, 0x0F,
    0x9F, 0x0F, 0xA3, 0x0F, 0xA8, 0x0F, 0xAD, 0x0F, 0xB4, 0x0F, 0xBA, 0x0F, 0xC1, 0x0F, 0xC7, 0x0F,
};
BYTE code tQC_VSD_COEF[] =
{
    0x82, 0x0F, 0x97, 0x0F, 0xA4, 0x0F, 0xCE, 0x0F, 0xE8, 0x0F, 0x1A, 0x00, 0x3B, 0x00, 0x73, 0x00,
    0x98, 0x00, 0xD2, 0x00, 0xF8, 0x00, 0x32, 0x01, 0x58, 0x01, 0x91, 0x01, 0xB5, 0x01, 0xEE, 0x01,
    0x7E, 0x04, 0x69, 0x04, 0x5C, 0x04, 0x32, 0x04, 0x18, 0x04, 0xE6, 0x03, 0xC5, 0x03, 0x8D, 0x03,
    0x68, 0x03, 0x2E, 0x03, 0x08, 0x03, 0xCE, 0x02, 0xA8, 0x02, 0x6F, 0x02, 0x4B, 0x02, 0x12, 0x02,
};

//--------------------------------------------------
// Code Tables of ScaleDown CRC
//--------------------------------------------------
BYTE code tScaleDownTest0_ICRCTable[] = {
    0xF2, 0x18, 0xD5, 0xAD, 0x9F, 0x21, // M1
    0xBE, 0xBE, 0xB7, 0x8D, 0x6F, 0xFA, // M2
};

BYTE code tScaleDownTest1_ICRCTable[] = {
    0x52, 0x17, 0x77, 0xBC, 0x0D, 0x97, // M1
    0x61, 0x46, 0x46, 0x7A, 0x62, 0x86, // M2
};

#if(_QC_4P_MODE_ == _ON)
BYTE code tScaleDownTest0_4P_ICRCTable[] = {
    0x15, 0x76, 0xAE, 0x00, 0x69, 0x89, // M1
    0x15, 0x76, 0xAE, 0x00, 0x69, 0x89, // M2
    0x15, 0x76, 0xAE, 0x00, 0x69, 0x89, // S1
    0x15, 0x76, 0xAE, 0x00, 0x69, 0x89, // S2
};

BYTE code tScaleDownTest1_4P_ICRCTable[] = {
    0x52, 0x1C, 0x7D, 0x57, 0x9C, 0xEA, // M1
    0x52, 0x1C, 0x7D, 0x57, 0x9C, 0xEA, // M2
    0x52, 0x1C, 0x7D, 0x57, 0x9C, 0xEA, // S1
    0x52, 0x1C, 0x7D, 0x57, 0x9C, 0xEA, // S2
};

BYTE code tScaleDownTest0_2P_ICRCTable[] = {
    0xCC, 0xE5, 0x6B, 0xC8, 0x44, 0xB9, // M1
    0x92, 0x1B, 0x48, 0x38, 0x1F, 0xF1, // M2
    0xCC, 0xE5, 0x6B, 0xC8, 0x44, 0xB9, // S1
    0x92, 0x1B, 0x48, 0x38, 0x1F, 0xF1, // S2
};

BYTE code tScaleDownTest1_2P_ICRCTable[] = {
    0xD5, 0x5E, 0xBA, 0xD7, 0x6E, 0x51, // M1
    0x4D, 0x63, 0xBF, 0x78, 0x9C, 0xFB, // M2
    0xD5, 0x5E, 0xBA, 0xD7, 0x6E, 0x51, // S1
    0x4D, 0x63, 0xBF, 0x78, 0x9C, 0xFB, // S2
};
#endif
//--------------------------------------------------
// Code Tables of HLW CRC
//--------------------------------------------------
BYTE code tHLWTest0_DCRCTable[] = {
    0x38, 0x1C, 0xF1, 0xE1, 0x1A, 0x56, // M1
    0x4C, 0x7C, 0xC4, 0x07, 0x8D, 0x93, // M2
};

BYTE code tHLWTest1_DCRCTable[] = {
    0xA6, 0x0E, 0xDE, 0xE2, 0xB6, 0x25, // M1
    0xE8, 0x33, 0x70, 0x66, 0x44, 0x0D, // M2
};

BYTE code tHLWTest2_DCRCTable[] = {
    0xB7, 0x63, 0xB5, 0x46, 0x27, 0xFE, // M1
    0xFA, 0x33, 0xDA, 0x36, 0x75, 0xBA, // M2
};

BYTE code tHLWTest3_DCRCTable[] = {
    0xFD, 0x7F, 0xA0, 0x6E, 0x08, 0x74, // M1
    0x91, 0x42, 0x7E, 0xA3, 0x9D, 0xF8, // M2
};

BYTE code tHLWTest4_DCRCTable[] = {
    0x6B, 0xA5, 0x13, 0x02, 0xF0, 0xB9, // M1
    0xF8, 0xD0, 0xD4, 0xC4, 0xD2, 0xAF, // M2
};

//--------------------------------------------------
// Code Tables of HLW
//--------------------------------------------------
BYTE code tQC_HIGHLIGHT_WINDOW_SETTING[] =
{
    0x00,0x55,0x02,0xAA,0x00,0x55,0x02,0xAA,0x0F,0xFF,0xFF,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

//--------------------------------------------------
// Code Tables of ScaleUp CRC
//--------------------------------------------------
BYTE code tQC_SU_COEF[] =
{
    0xFB, 0x0F, 0xFE, 0x0F, 0xFD, 0x0F, 0xFC, 0x0F, 0xFB, 0x0F, 0xFA, 0x0F, 0xF7, 0x0F, 0xF5, 0x0F,
    0xF1, 0x0F, 0xED, 0x0F, 0xE9, 0x0F, 0xE4, 0x0F, 0xDE, 0x0F, 0xD9, 0x0F, 0xD3, 0x0F, 0xCD, 0x0F,
    0xC7, 0x0F, 0xDB, 0x0F, 0xF0, 0x0F, 0x0C, 0x00, 0x27, 0x00, 0x49, 0x00, 0x6B, 0x00, 0x93, 0x00,
    0xBC, 0x00, 0xEA, 0x00, 0x16, 0x01, 0x49, 0x01, 0x7A, 0x01, 0xB0, 0x01, 0xE3, 0x01, 0x1C, 0x02,
    0x84, 0x04, 0x78, 0x04, 0x6C, 0x04, 0x57, 0x04, 0x42, 0x04, 0x23, 0x04, 0x04, 0x04, 0xDC, 0x03,
    0xB4, 0x03, 0x86, 0x03, 0x59, 0x03, 0x26, 0x03, 0xF4, 0x02, 0xBD, 0x02, 0x89, 0x02, 0x50, 0x02,
    0xBA, 0x0F, 0xAF, 0x0F, 0xA7, 0x0F, 0xA1, 0x0F, 0x9C, 0x0F, 0x9A, 0x0F, 0x9A, 0x0F, 0x9C, 0x0F,
    0x9F, 0x0F, 0xA3, 0x0F, 0xA8, 0x0F, 0xAD, 0x0F, 0xB4, 0x0F, 0xBA, 0x0F, 0xC1, 0x0F, 0xC7, 0x0F,
};

BYTE code tMDomain_Table[] = {
    0x34, 0x9D, 0xA1, 0x00, 0x00, 0x00, // M1
    0x34, 0x9D, 0xA1, 0x00, 0x00, 0x00, // M2
};

BYTE code tScaleUpTest0_DCRCTable[] = {
    0x4F, 0x1C, 0xA1, 0x5E, 0x61, 0x88, // M1
    0x41, 0x5E, 0x75, 0xEA, 0xEB, 0x4E, // M2
};

BYTE code tScaleUpTest1_DCRCTable[] = {
    0xB7, 0x3E, 0x4E, 0xC3, 0x99, 0x76, // M1
    0x7F, 0x48, 0x5C, 0x40, 0x7F, 0x23, // M2
};

BYTE code tScaleUpTest2_DCRCTable[] = {
    0x4F, 0xF0, 0x70, 0x00, 0x00, 0x00, // M1
    0x92, 0x32, 0x8A, 0x00, 0x00, 0x00, // M2
};

#if(_QC_4P_MODE_ == _ON)
BYTE code tMDomain_4P_Table[] = {
    0x9F, 0xD4, 0x38, 0x00, 0x00, 0x00, // M1
    0x9F, 0xD4, 0x38, 0x00, 0x00, 0x00, // M2
    0x9F, 0xD4, 0x38, 0x00, 0x00, 0x00, // S1
    0x9F, 0xD4, 0x38, 0x00, 0x00, 0x00, // S2
};

BYTE code tScaleUpTest0_4P_DCRCTable[] = {
    0x6F, 0x3E, 0xD7, 0x9C, 0x76, 0xB6, // M1
    0x04, 0xE8, 0xAC, 0x38, 0xDB, 0x00, // M2
    0x6C, 0xB5, 0x46, 0x68, 0x3B, 0x6A, // Sub
};

BYTE code tScaleUpTest1_4P_DCRCTable[] = {
    0x2C, 0x1A, 0xC9, 0xBB, 0xA6, 0x54, // M1
    0xF6, 0x9D, 0xA0, 0x8C, 0xA6, 0x85, // M2
    0x6E, 0xA1, 0xB1, 0xC4, 0xEF, 0xFF, // Sub
};

BYTE code tScaleUpTest2_4P_DCRCTable[] = {
    0x2A, 0xF5, 0xDB, 0x00, 0x00, 0x00, // M1
    0xB8, 0xF6, 0x96, 0x00, 0x00, 0x00, // M2
    0xD7, 0x3F, 0x50, 0x00, 0x00, 0x00, // Sub
};

BYTE code tScaleUpTest3_4P_DCRCTable[] = {
    0x60, 0x7D, 0xB6, 0x6E, 0xBF, 0x81, // M1
    0xC3, 0xD1, 0xFE, 0x0D, 0x37, 0x7E, // M2
    0x6E, 0xA1, 0xB1, 0xC4, 0xEF, 0xFF, // Sub
};
#endif
//--------------------------------------------------
// Code Tables of M Domain LSR Setting
//--------------------------------------------------
//(180)
BYTE code tQC_LSR_SETTING[] =
{
    4,  _AUTOINC,       0x9F,   0x14,
    29, _AUTOINC,       0xC0,   0xE0,0x28,0x1B,0x01,0x00,0xEF,0x00,0xD4,0x32,0x23,0x08,0x05,0x00,0x50,0x1E,0x8C,
                                0x14,0x32,0x0F,0x0A,0x0C,0x28,0x00,0x50,0x00,0x28,
    35, _AUTOINC,       0xE0,   0x00,0xE8,0x00,0xC8,0x29,0x14,0x08,0x05,0x00,0xA8,0x1E,0x96,0x1E,0x3C,0x0F,0x04,
                                0x0C,0x54,0x00,0xA8,0x00,0x54,0x00,0x48,0x04,0x48,0x80,0x80,0x00,0x40,0x0C,0x48,
    9,  _AUTOINC,       0x00,   0x04,0x84,0xCC,0xCC,0x44,0x84,
    13, _AUTOINC,       0x10,   0x2D,0x40,0x07,0x2D,0x40,0x06,0x00,0x0A,0x00,0x0A,

    4,  _AUTOINC,       0x9F,   0x54,
    29, _AUTOINC,       0xC0,   0xC0,0x4B,0x0F,0x00,0x02,0x52,0x01,0xF4,0xC8,0xBB,0x55,0x47,0x09,0x0C,0x12,0x0C,
                                0xDA,0x0E,0x0E,0x00,0x0C,0xE1,0x0E,0xCD,0x05,0x71,
    35, _AUTOINC,       0xE0,   0x01,0xE1,0x00,0xE3,0xD9,0xAC,0x53,0x1C,0x08,0x1C,0x70,0x47,0x29,0x35,0x0A,0x07,
                                0x0C,0x1D,0x07,0x13,0x00,0xD6,0x80,0x4C,0x08,0x88,0xC8,0x00,0x88,0xC4,0xC8,0x04,
    9,  _AUTOINC,       0x00,   0x8C,0x0C,0x48,0xCC,0xCC,0xC8,
    13, _AUTOINC,       0x10,   0x11,0xC0,0x06,0xD4,0xC0,0x03,0x00,0xB1,0x02,0xB2,

};
//(15)
BYTE code tQC_LSR_HLW[] =
{
    4,  _AUTOINC,       0x9F,   0x11,
    11, _AUTOINC,       0xCC,   0x01,0x2C,0x03,0x84,0x01,0xF4,0x05,0xDC,
};

BYTE code tLSR_Table0[] = {
    0xE7, 0x53, 0x12, 0x5D, 0xD0, 0xC0, // M1
    0xC5, 0x4A, 0xC7, 0x5C, 0x95, 0x5B, // M2
};

BYTE code tLSR_Table1[] = {
    0xDF, 0x20, 0xDB, 0x51, 0x6C, 0x6E, // M1
    0x5F, 0x02, 0x80, 0x87, 0x93, 0x90, // M2
};

BYTE code tLSR_Table2[] = {
    0x29, 0xC5, 0x33, 0xEF, 0x1C, 0x8A, // M1
    0x01, 0x40, 0x7B, 0x83, 0x65, 0x37, // M2
};

BYTE code tLSR_Table3[] = {
    0xE7, 0x53, 0x12, 0x5D, 0xD0, 0xC0, // M1
    0xC5, 0x4A, 0xC7, 0x5C, 0x95, 0x5B, // M2
};

BYTE code tLSR_Table4[] = {
    0x8C, 0x73, 0xA9, 0xE5, 0x4A, 0xF8, // M1
    0x2A, 0x65, 0x86, 0xE7, 0xBE, 0xA1, // M2
};

BYTE code tLSR_Table5[] = {
    0x60, 0x7B, 0x7A, 0x31, 0xB0, 0x4E, // M1
    0x4A, 0x7B, 0x28, 0x5A, 0x1D, 0x8F, // M2
};

#if(_QC_4P_MODE_ == _ON)
//(360)
BYTE code tQC_2P_4P_LSR_SETTING[] =
{
    //Main1
    4,  _AUTOINC,       0x9F,   0x14,
    29, _AUTOINC,       0xC0,   0xE0,0x28,0x1B,0x01,0x00,0xEF,0x00,0xD4,0x32,0x23,0x08,0x05,0x00,0x50,0x1E,0x8C,
                                0x14,0x32,0x0F,0x0A,0x0C,0x28,0x00,0x50,0x00,0x28,
    35, _AUTOINC,       0xE0,   0x00,0xE8,0x00,0xC8,0x29,0x14,0x08,0x05,0x00,0xA8,0x1E,0x96,0x1E,0x3C,0x0F,0x04,
                                0x0C,0x54,0x00,0xA8,0x00,0x54,0x00,0x48,0x04,0x48,0x80,0x80,0x00,0x40,0x0C,0x48,
    9,  _AUTOINC,       0x00,   0x04,0x84,0xCC,0xCC,0x44,0x84,
    13, _AUTOINC,       0x10,   0x2D,0x40,0x07,0x2D,0x40,0x06,0x00,0x0A,0x00,0x0A,
    //Main2
    4,  _AUTOINC,       0x9F,   0x54,
    29, _AUTOINC,       0xC0,   0xE0,0x4B,0x0F,0x00,0x02,0x52,0x01,0xF4,0xC8,0xBB,0x55,0x47,0x09,0x0C,0x12,0x0C,
                                0xDA,0x0E,0x0E,0x00,0x0C,0xE1,0x0E,0xCD,0x05,0x71,
    35, _AUTOINC,       0xE0,   0x01,0xE1,0x00,0xE3,0xD9,0xAC,0x53,0x1C,0x08,0x1C,0x70,0x47,0x29,0x35,0x0A,0x07,
                                0x0C,0x1D,0x07,0x13,0x00,0xD6,0x80,0x4C,0x08,0x88,0xC8,0x00,0x88,0xC4,0xC8,0x04,
    9,  _AUTOINC,       0x00,   0x8C,0x0C,0x48,0xCC,0xCC,0xC8,
    13, _AUTOINC,       0x10,   0x11,0xC0,0x06,0xD4,0xC0,0x03,0x00,0xB1,0x02,0xB2,
    //Sub1
    4,  _AUTOINC,       0x9F,   0x94,
    29, _AUTOINC,       0xC0,   0xE0,0x0B,0x43,0x00,0x01,0xFD,0x01,0xD8,0xCA,0xC3,0x74,0x75,0x0C,0x5E,0x71,0x1C,
                                0xB1,0x3F,0x3C,0x0F,0x02,0x98,0x0C,0x0E,0x03,0x4F,
    35,_AUTOINC,        0xE0,   0x02,0x9F,0x01,0x48,0xFE,0xF5,0x30,0x5D,0x01,0x1D,0x16,0x4F,0x38,0x02,0x05,0x08,
                                0x02,0x5D,0x02,0x3B,0x00,0x23,0x44,0x4C,0x44,0x8C,0xC8,0x4C,0x88,0xC8,0x88,0x00,
    9,_AUTOINC,         0x00,   0x40,0x44,0x00,0x88,0xC8,0x44,
    13,_AUTOINC,        0x10,   0x7C,0xC0,0x08,0x1A,0x40,0x07,0x00,0x84,0x06,0x0A,
    //Sub2
    4,_AUTOINC,         0x9F,   0xD4,
    29,_AUTOINC,        0xC0,   0xE0,0x02,0x70,0x01,0x03,0x82,0x02,0x37,0xF9,0xAA,0x55,0x58,0x07,0xD3,0xCF,0xE7,
                                0xFA,0x61,0x1F,0x34,0x0D,0x3B,0x0D,0x21,0x0D,0x6C,
    35,_AUTOINC,        0xE0,   0x03,0xDD,0x03,0xDA,0xFB,0xAC,0x76,0x7D,0x02,0xEF,0xD4,0x8B,0x07,0x14,0x02,0x00,
                                0x00,0xE3,0x02,0xBB,0x00,0x17,0xCC,0xC8,0x84,0x4C,0x4C,0xCC,0x4C,0x8C,0xC4,0xCC,
    9,_AUTOINC,         0x00,   0x04,0xC4,0x88,0x84,0x48,0x80,
    13,_AUTOINC,        0x10,   0x5B,0x80,0x00,0xCD,0x80,0x07,0x00,0xCF,0x06,0xBA,

};
//(60)
BYTE code tQC_2P_4P_LSR_HLW[] =
{
    4,  _AUTOINC,       0x9F,   0x11,
    11, _AUTOINC,       0xCC,   0x01,0x2C,0x03,0x84,0x01,0x2C,0x02,0x58,

    4,  _AUTOINC,       0x9F,   0x51,
    11, _AUTOINC,       0xCC,   0x01,0x2C,0x03,0x84,0x01,0x2C,0x02,0x58,

    4,  _AUTOINC,       0x9F,   0x91,
    11, _AUTOINC,       0xCC,   0x01,0x2C,0x03,0x84,0x01,0x2C,0x02,0x58,

    4,  _AUTOINC,       0x9F,   0xD1,
    11, _AUTOINC,       0xCC,   0x01,0x2C,0x03,0x84,0x01,0x2C,0x02,0x58,
};

BYTE code tLSR_4P_Table0[] = {
    0x20, 0xAB, 0x4C, 0xDA, 0xBC, 0x64, // M1
    0x7B, 0x02, 0x3C, 0x04, 0x45, 0x53, // M2
    0x7C, 0xC1, 0xD9, 0x91, 0x21, 0xD2, // Sub
};

BYTE code tLSR_4P_Table1[] = {
    0x7C, 0xF8, 0xD2, 0x73, 0x48, 0xD8, // M1
    0x6C, 0x91, 0x34, 0x18, 0xBA, 0xF5, // M2
    0x4D, 0x62, 0xC7, 0xB2, 0x23, 0x6D, // Sub
};

BYTE code tLSR_4P_Table2[] = {
    0x14, 0x1C, 0x0A, 0xCE, 0x81, 0x28, // M1
    0x73, 0xA7, 0x18, 0xAD, 0x70, 0xBB, // M2
    0x42, 0x12, 0xF2, 0xAF, 0x85, 0x48, // Sub
};

//-----------------2P LSR CRC-------------------
BYTE code tMDomain_2P_Table[] = {
    0xCC, 0xE5, 0x6B, 0x00, 0x00, 0x00, // M1
    0x92, 0x1B, 0x48, 0x00, 0x00, 0x00, // M2
    0xCC, 0xE5, 0x6B, 0x00, 0x00, 0x00, // S1
    0x92, 0x1B, 0x48, 0x00, 0x00, 0x00, // S2
};

BYTE code tDDomain_2P_Table[] = {
    0xF4, 0x96, 0xB3, 0x00, 0x00, 0x00, // M1
    0x59, 0x6B, 0xC0, 0x00, 0x00, 0x00, // M2
    0xC0, 0x05, 0xEC, 0x00, 0x00, 0x00, // Sub
};

BYTE code tLSR_2P_Table0[] = {
    0x68, 0x7C, 0x59, 0x98, 0x4E, 0x83, // M1
    0x1A, 0x6C, 0x97, 0xA9, 0x0F, 0xB9, // M2
    0xDC, 0x74, 0x82, 0x0D, 0x82, 0x11, // Sub
};

BYTE code tLSR_2P_Table1[] = {
    0x6B, 0x0E, 0xAB, 0x46, 0x60, 0xDB, // M1
    0x4B, 0x84, 0xEA, 0x7D, 0xD8, 0x58, // M2
    0x18, 0x0E, 0x3D, 0x56, 0xF0, 0x6C, // Sub
};

BYTE code tLSR_2P_Table2[] = {
    0x5F, 0x90, 0xCB, 0x1E, 0xE6, 0x17, // M1
    0xD4, 0x91, 0xDD, 0x9C, 0x36, 0xFE, // M2
    0x46, 0xD9, 0xAA, 0xFA, 0x13, 0x02, // Sub
};

BYTE code tLSR_2P_Table3[] = {
    0x85, 0xF5, 0x0C, 0x8D, 0x7F, 0x20, // M1
    0x20, 0x9C, 0x6D, 0xE3, 0xD5, 0x15, // M2
    0x3B, 0x11, 0x55, 0x0A, 0x85, 0xF8, // Sub
};

BYTE code tLSR_2P_Table4[] = {
    0xC0, 0x08, 0xD3, 0x58, 0x86, 0xCC, // M1
    0xC6, 0x7E, 0xF7, 0xE1, 0xEE, 0xA6, // M2
    0x9E, 0xD2, 0x7B, 0xAC, 0xE3, 0x6E, // Sub
};

BYTE code tLSR_2P_Table5[] = {
    0x83, 0x2F, 0xE1, 0x32, 0x7C, 0x9B, // M1
    0x01, 0x37, 0x44, 0x3D, 0x23, 0xFF, // M2
    0x54, 0x90, 0x71, 0x04, 0xBB, 0x7C, // Sub
};
#endif
//--------------------------------------------------
// Code Tables of ScaleUp Coef
//--------------------------------------------------
BYTE code tQC_SU_COEF0[] =
{
    0xFB, 0x0F, 0xFE, 0x0F, 0xFD, 0x0F, 0xFC, 0x0F, 0xFB, 0x0F, 0xFA, 0x0F, 0xF7, 0x0F, 0xF5, 0x0F,
    0xF1, 0x0F, 0xED, 0x0F, 0xE9, 0x0F, 0xE4, 0x0F, 0xDE, 0x0F, 0xD9, 0x0F, 0xD3, 0x0F, 0xCD, 0x0F,
    0xC7, 0x0F, 0xDB, 0x0F, 0xF0, 0x0F, 0x0C, 0x00, 0x27, 0x00, 0x49, 0x00, 0x6B, 0x00, 0x93, 0x00,
    0xBC, 0x00, 0xEA, 0x00, 0x16, 0x01, 0x49, 0x01, 0x7A, 0x01, 0xB0, 0x01, 0xE3, 0x01, 0x1C, 0x02,
    0x84, 0x04, 0x78, 0x04, 0x6C, 0x04, 0x57, 0x04, 0x42, 0x04, 0x23, 0x04, 0x04, 0x04, 0xDC, 0x03,
    0xB4, 0x03, 0x86, 0x03, 0x59, 0x03, 0x26, 0x03, 0xF4, 0x02, 0xBD, 0x02, 0x89, 0x02, 0x50, 0x02,
    0xBA, 0x0F, 0xAF, 0x0F, 0xA7, 0x0F, 0xA1, 0x0F, 0x9C, 0x0F, 0x9A, 0x0F, 0x9A, 0x0F, 0x9C, 0x0F,
    0x9F, 0x0F, 0xA3, 0x0F, 0xA8, 0x0F, 0xAD, 0x0F, 0xB4, 0x0F, 0xBA, 0x0F, 0xC1, 0x0F, 0xC7, 0x0F,
};

BYTE code tQC_SU_COEF1[] =
{
    0xE0, 0x0F, 0xE9, 0x0F, 0xE8, 0x0F, 0xE9, 0x0F, 0xE8, 0x0F, 0xE7, 0x0F, 0xE4, 0x0F, 0xE3, 0x0F,
    0xE1, 0x0F, 0xDF, 0x0F, 0xDC, 0x0F, 0xDB, 0x0F, 0xD8, 0x0F, 0xD7, 0x0F, 0xD5, 0x0F, 0xD5, 0x0F,
    0x4C, 0x00, 0x61, 0x00, 0x78, 0x00, 0x92, 0x00, 0xAC, 0x00, 0xC9, 0x00, 0xE6, 0x00, 0x06, 0x01,
    0x26, 0x01, 0x48, 0x01, 0x69, 0x01, 0x8D, 0x01, 0xAF, 0x01, 0xD4, 0x01, 0xF6, 0x01, 0x1B, 0x02,
    0x9A, 0x03, 0x8B, 0x03, 0x84, 0x03, 0x75, 0x03, 0x68, 0x03, 0x56, 0x03, 0x44, 0x03, 0x2D, 0x03,
    0x15, 0x03, 0xFA, 0x02, 0xE0, 0x02, 0xC0, 0x02, 0xA3, 0x02, 0x81, 0x02, 0x61, 0x02, 0x3C, 0x02,
    0x3A, 0x00, 0x2B, 0x00, 0x1C, 0x00, 0x10, 0x00, 0x04, 0x00, 0xFA, 0x0F, 0xF2, 0x0F, 0xEA, 0x0F,
    0xE4, 0x0F, 0xDF, 0x0F, 0xDB, 0x0F, 0xD8, 0x0F, 0xD6, 0x0F, 0xD4, 0x0F, 0xD4, 0x0F, 0xD4, 0x0F,
};

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerQCVGAPGTest(void);
bit ScalerQCADCNRTest(void);
bit ScalerQCRingingFilterTest(void);
bit ScalerQCDigitalFilterTest(void);

// I-domain
bit ScalerQC422to444Test(void);
bit ScalerQCFormatConversionTest(void);
bit ScalerQCIPGTest(void);
bit ScalerQCIDomainColorConvTest(void);
bit ScalerQCIDLTITest(void);
bit ScalerQCIDitherTest(void);
bit ScalerQCScaleDownTest(void);
bit ScalerQCHLWTest(void);

// M-domain
bit ScalerQCLSRTest(void);
bit ScalerQCScaleUpTest(void);

// Common Function
void ScalerQCPrintCRC(BYTE ucFrame, BYTE ucPath, BYTE *ucCRC, BYTE ucNum);
bit ScalerQCCRCCompare_IM(BYTE ucDomain, EnumIMCRCPosition enumPosition, BYTE ucSourceSel, BYTE *ucCRC, BYTE ucFrameNum);

void ScalerQCVGATopRandomGenOn(bit bRandomSelect);
void ScalerQCVGATopRandomGenOff(void);
void ScalerQCIDomainRandomGenOn(bit bRandomSelect);
void ScalerQCIDomainRandomGenOff(void);
void ScalerQCHighlightWindowOn(void);
void ScalerQCHighlightWindowOff(void);

#if(_QC_4P_MODE_ == _ON)
void ScalerQCSetScalingCoef(void);
void ScalerQCSetScalingUp(EnumDisplayDataPath enumDisplayDataPath, const StructSDRAMDataInfo *pstFIFOScaling, const StructDisplayInfo *pstMDomainOutputData);
void ScalerQCSetScalingDownCoef(void);
void ScalerQCSetScalingDown(EnumInputDataPath enumInputDataPath, const StructSDRAMDataInfo *pstFIFOScaling, const StructTimingInfo *pstMDomainInputData);
void ScalerQCSetScaling(bit bMode);

bit ScalerQC4P422to444Test(void);
bit ScalerQC4PFormatConversionTest(void);
bit ScalerQC4PIDomainColorConvTest(void);
bit ScalerQC4PIDLTITest(void);
bit ScalerQC4PIDitherTest(void);
bit ScalerQC4PScaleDownTest(void);
bit ScalerQC4PLSRTest(void);
bit ScalerQC4PScaleUpTest(void);

bit ScalerQC2PFormatConversionTest(void);
bit ScalerQC2PIPGTest(void);
bit ScalerQC2PIDomainColorConvTest(void);
bit ScalerQC2PIDLTITest(void);
bit ScalerQC2PIDitherTest(void);
bit ScalerQC2PScaleDownTest(void);
bit ScalerQC2PLSRTest(void);
#endif  // End of #if(_QC_4P_MODE_ == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//----------------------------------------------------------------------------
// Color Function Test
//----------------------------------------------------------------------------
//--------------------------------------------------
// Description  : Test VGA Random Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCVGAPGTest(void)
{
    BYTE ucFlag = 0;
    DebugMessageQC("5. VGA PG Start", 0x00);

    ScalerQCVGATopRandomGenOn(_GRAY);
    ucFlag = (ucFlag | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tVGAPG_CRC_TABLE0, 1) << 0));

    ScalerQCVGATopRandomGenOn(_MASS);
    ucFlag = (ucFlag | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tVGAPG_CRC_TABLE1, 1) << 1));

    DebugMessageQC("5. VGA PG End", 0x00);

    ScalerQCVGATopRandomGenOff();

    if(ucFlag == _TEST_PASS)
    {
        DebugMessageQC("6.====VGA PG PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====VGA PG Fail====", ucFlag);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : ADCNR Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCADCNRTest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. ADCNR Start", 0x00);

    ScalerQCVGATopRandomGenOn(_GRAY);

    ScalerSetByte(P33_01_ADCNR_CTRL2, 0x37);
    ScalerSetByte(P33_02_ADCNR_CTRL3, 0x76);
    ScalerSetByte(P33_00_ADCNR_CTRL1, 0x9C); // Enable ADCNR

    ScalerTimerDelayXms(300); // Wait over 7frames

    DebugMessageQC("5. Mode_0", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tADCNR_CRC_TABLE0, 1) << 0);

    ScalerSetByte(P33_00_ADCNR_CTRL1, 0x1C); // Disable ADCNR
    ScalerSetBit(P33_02_ADCNR_CTRL3, ~(_BIT7 | _BIT6), 0x00);       // No Truncate LSB

    ScalerQCVGATopRandomGenOff();

    DebugMessageQC("5.ADCNR End", 0x00);

    if(ucData == 0x00)
    {
        DebugMessageQC("6. ADCNR PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. ADCNR FAIL", 0x00);
        return _TEST_FAIL;
    }

}

//--------------------------------------------------
// Description  : RingingFilter Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCRingingFilterTest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. Ringing Filter Start", 0x00);

    ScalerQCVGATopRandomGenOn(_MASS);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xE0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x23);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_0", 0x00);  // normal
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest0_ICRCTable, 1) << 0);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xC0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x23);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_1", 0x00);  // disable JumpJudgment En
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest1_ICRCTable, 1) << 1);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xE0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x23);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x07);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_2", 0x00);  // Enable Factor=1
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest2_ICRCTable, 1) << 2);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xA0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x50);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x0C);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x00);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_3", 0x00);  // Fixing Offset Range
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest3_ICRCTable, 1) << 3);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xA0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0xB4);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x06);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_4", 0x00);  // big threshold, small offset Coef, DiffThreshold_UB/LB
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest4_ICRCTable, 1) << 4);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xE0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x14);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x02);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x12);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x01);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x08);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_5", 0x00);  // Enable DiffFactor=0 when pixels=2
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest5_ICRCTable, 1) << 5);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xB0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x96);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x02);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x00);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x04);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_6", 0x00);  // big threshold, small coef, R disable, THD_Factor=1
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest6_ICRCTable, 1) << 6);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0xC0);
    ScalerSetByte(P25_A1_RFILTER_THD, 0x50);
    ScalerSetByte(P25_A2_RFILTER_THD_RNG_EXP, 0x04);
    ScalerSetByte(P25_A3_RFILTER_OFS_COEF, 0x1E);
    ScalerSetByte(P25_A4_RFILTER_OFS_RNG_EXP, 0x04);
    ScalerSetByte(P25_A5_RFILTER_DIFF_THD_UB, 0x00);
    ScalerSetByte(P25_A6_RFILTER_DIFF_THD_LB, 0x01);
    ScalerSetByte(P25_A7_RFILTER_FACTOR_TEST_CTRL, 0x00);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_7", 0x00);  // big coef
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tRingingFilterTest7_ICRCTable, 1) << 7);

    ScalerSetByte(P25_A0_RFILTER_CTRL, 0x00); // Disable Ringing Filter

    ScalerQCVGATopRandomGenOff();

    DebugMessageQC("5.Ringing Filter End", 0x00);

    if(ucData == 0x00)
    {
        DebugMessageQC("6. Ringing Filter PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. Ringing Filter FAIL", 0x00);
        return _TEST_FAIL;
    }

}

//--------------------------------------------------
// Description  : DigitalFilter Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCDigitalFilterTest(void)
{
    WORD usData = 0;

    DebugMessageQC("5. Digital Filter Start", 0x00);
    ScalerQCVGATopRandomGenOn(_MASS);

    // reset regs
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x10); // Enable Phase subFunction
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x20);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale negative semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x30);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale positive semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale positive ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x60);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale mismatch subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x70);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale mismatch subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x80);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale Noise Reduction subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // disable New Phase Mode EN
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x21);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x31);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x41);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x51);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x61);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x71);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x81);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x91);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0xA1);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00);

    // mode start
    //Digital Filter For Phase
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x70); // Digital Filter Coefficient
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xF0);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x10); // Enable Phase subFunction
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // disable New Phase Mode EN
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x32);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_0", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest0_ICRCTable, 1) << 0));

    //Digital Filter For Other Sub-Function(disable)

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x10);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // Disbale Phase subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x20);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xD4); // Enable negative semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x30);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xD8); // Enable positive semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xDC); // Enable negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xD0); // Enable positive ringing subFunction (0xd0:80   0xb0:48)
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x60);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // Enable mismatch subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x80);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x90); // Enable Noise Reduction subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x32);

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x02);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_1", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest1_ICRCTable, 1) << 1));


    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x80);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xE0); // Enable Noise Reduction subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x00); // only reduce ringing condition + mismatch

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_2", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest2_ICRCTable, 1) << 2));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x02); // only reduce smear condition + mismatch

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_3", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest3_ICRCTable, 1) << 3));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x10);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale Phase subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x20);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x94); // Enable negative semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x30);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xA8); // Enable positive semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xBC); // Enable negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xB0); // Enable positive ringing subFunction (0xd0:80   0xb0:48)
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x60);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // Enable mismatch subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x80);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x90); // Enable Noise Reduction subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x32);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x06);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_4", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest4_ICRCTable, 1) << 4));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x0A); // disable + noise reduction

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_5", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest5_ICRCTable, 1) << 5));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x0E);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_6", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest6_ICRCTable, 1) << 6));

    //Digital Filter For NEW Phase
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x10); // Enable Phase subFunction
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80);
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x20);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale negative semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x30);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale positive semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale positive ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x60);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale mismatch subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x80);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Disbale Noise Reduction subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x90); // Set Old Phase Threshold
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x32);

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // New Phase Mode EN
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x21);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x1E); // Threshold Of R
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x31);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x05); // Offset Of R
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x41);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x85); // Gain Of R

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x51);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x50); // Threshold Of G
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x61);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x07); // Offset Of G
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x71);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x05); // Gain Of G

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x81);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x01); // Threshold Of B
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x91);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x01); // Offset Of B
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0xA1);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xFF); // Gain Of B
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x00);

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_7", 0x00);  // Double Side + Double Gain
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest7_ICRCTable, 1) << 7));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xC0); // Single Side + Double Gain
    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_8", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest8_ICRCTable, 1) << 8));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xA0); // Double Side + Single Gain
    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_9", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest9_ICRCTable, 1) << 9));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xE0); // Single Side + Single Gain
    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_10", 0x00);
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest10_ICRCTable, 1) << 10));


    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x10);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // Enable Phase subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x20);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x90); // Enable negative semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x30);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xA4); // Enable positive semar sunFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xB8); // Enable negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xBC); // Enable positive ringing subFunction (0xd0:80   0xb0:48)
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x60);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // Enable mismatch subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x80);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xE0); // Enable Noise Reduction subFunction

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x80); // New Phase Mode EN

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x04); // only reduce ringing condition

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_11", 0x00);  // Double Side + Double Gain + other function
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest11_ICRCTable, 1) << 11));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x38); // Disable negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x3C); // Disable positive ringing subFunction (0xd0:80   0xb0:48)

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xC0);

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x41);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x19); //

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x81);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x10); //

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x00); // disable Two condition occur continuous (ringing to smear)

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_12", 0x00);  // Double Side + Single Gain + other function
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest12_ICRCTable, 1) << 12));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x40);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xB8); // Enable negative ringing subFunction
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x50);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xBC); // Enable positive ringing subFunction (0xd0:80   0xb0:48)

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x11);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0xA0); // Single Side + Double Gain + other function

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x41);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x85); //

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x81);
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x01); //

    ScalerTimerDelayXms(50);
    DebugMessageQC("5. Mode_13", 0x00);  // Double Side + Double Gain + other function
    usData = (usData | ((WORD)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tDigitalFilterTest13_ICRCTable, 1) << 13));

    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x70); // Disable Digital Filter
    ScalerSetByte(P0_99_DIGITAL_FILTER_PORT,0x00); // Y/Pb/Pr Function Disable //Initial Value=0
    ScalerSetByte(P0_98_DIGITAL_FILTER_CTRL,0x00); // Disable Digital Filter

    ScalerQCVGATopRandomGenOff();

    DebugMessageQC("5. Digital Filter End", 0x00);

    if(usData == 0x0000)
    {
        DebugMessageQC("6. Digital Filter PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", usData);
        DebugMessageQC("6. Digital Filter FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : 422to444 Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC422to444Test(void)
{
    BYTE ucData = 0;
    BYTE ucSD = ScalerGetBit(P0_23_SCALE_DOWN_CTRL_M1, _BIT1 | _BIT0);

    //disable Scale down
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, _BIT1 | _BIT0, 0x00);
    DebugMessageQC("5. 422to444 Start", 0x00);

    //0.
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x08);
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2, t422to444_Table0, 1) << 0);

    //1.
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x0B);
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2, t422to444_Table1, 1) << 1);

    //2.
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x0E);
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2, t422to444_Table2, 1) << 2);

    //enable Scale down
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, _BIT1 | _BIT0, ucSD);
    //disable 422to444
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x00);

    DebugMessageQC("5. 422to444 End", 0x00);

    if(ucData == _TEST_PASS)
    {
        DebugMessageQC("6.====I Random 422to444 PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====I Random 422to444 Fail====", 0x00);
        return _TEST_FAIL;
    }

}

//--------------------------------------------------
// Description  : FC TEST
// Input Value  : None
// return Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCFormatConversionTest(void)
{
    BYTE ucData = 0;
    BYTE ucIVS = 0;
    BYTE ucTemp[14];

    DebugMessageQC("5. Format Conversion Start", 0x00);

    ScalerRead(P31_00_FC_INPUT_SEL_P01, 14, ucTemp, _AUTOINC);

    ScalerBurstWrite(tFC_TEST0, sizeof(tFC_TEST0), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ucIVS = ScalerGetByte(P0_19_M1_IPV_ACT_STA_L) + ScalerGetByte(P0_1C_M1_IVS_DELAY);

    if((ucIVS % 2) == 1)
    {
        ScalerSetByte(P31_06_FC_EO_LINE_CTRL, 0xCC);
    }


    // Even/Odd, 4096x2160, 256 Gray Level
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2, tFC_CRC_1P, 1) << 0);

    ScalerSetByte(0x3100, ucTemp[0]);
    ScalerSetByte(0x3101, ucTemp[1]);
    ScalerSetByte(0x3102, ucTemp[2]);
    ScalerSetByte(0x3103, ucTemp[3]);
    ScalerSetByte(0x3104, ucTemp[4]);
    ScalerSetByte(0x3105, ucTemp[5]);
    ScalerSetByte(0x3106, ucTemp[6]);
    ScalerSetByte(0x3107, ucTemp[7]);
    ScalerSetByte(0x3108, ucTemp[8]);
    ScalerSetByte(0x3109, ucTemp[9]);
    ScalerSetByte(0x310A, ucTemp[10]);
    ScalerSetByte(0x310C, ucTemp[12]);
    ScalerSetByte(0x310D, ucTemp[13]);

    DebugMessageQC("5. Format Conversion End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. Format Conversion PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. Format Conversion FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Test I-Domain Random Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCIPGTest(void)
{
    BYTE ucFlag = 0;
    DebugMessageQC("5. IPG Start", 0x00);
    ScalerQCIDomainRandomGenOn(_MASS);

    ucFlag = ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1 | _M2, tIPG_CRC_TABLE, 1) << 0);

    DebugMessageQC("5. IPG End", 0x00);

    ScalerQCIDomainRandomGenOff();

    if(ucFlag == _TEST_PASS)
    {
        DebugMessageQC("6.====IPG PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====IPG Fail====", ucFlag);
        return _TEST_FAIL;
    }
}

//----------------------------------------------------------------------------
// I-Domain Color Conversion Test
//----------------------------------------------------------------------------
bit ScalerQCIDomainColorConvTest(void)
{
    BYTE ucResult = _TEST_PASS;

    ////////////////////////////////////////////////////////////////////
    // RGB -> YCbCr                                                   //
    ////////////////////////////////////////////////////////////////////
    DebugMessageQC("5. I-Domain Color Conversion Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerTimerDelayXms(50);

    // Enable YUV2RGB coefficient access
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), P0_9D_RGB2YCC_COEF_DATA, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT3, 0x00);

    //////////////////////////////////////////////////////////////////
    // case 0: RGB->YUV, enable y out shift, enable CbCr out shift + 2048, Output_sel
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, 0x00, _BIT7 | _BIT6 | _BIT4 | _BIT0);  // 0xD1

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);

    DebugMessageQC("5. Color Conv case", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2, tICOLORCONV_CRC_TABLE, 1));

    //////////////////////////////////////////////////////////////////
    // case 1: RGB->YUV, Disable Output_Sel
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, 0x00, _BIT7 | _BIT6 | _BIT0);  // 0xD1

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);

    DebugMessageQC("5. Color Conv case", 0x01);
    ucResult = ucResult | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2, tIPG_CRC_TABLE, 1) << 1);

    ScalerQCIDomainRandomGenOff();

    // Disable YUV2RGB conversion
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT0, _BIT0);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);

    DebugMessageQC("5. I-Domain Color Conversion End", 0x00);

    if(ucResult == 0)
    {
        DebugMessageQC("6. I-Domain Color Conversion PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucResult);
        DebugMessageQC("6. I-Domain Color Conversion FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : IDLTI Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCIDLTITest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. IDLTI Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerBurstWrite(&tQC_IDLTI_SETTING_1[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 1
    ScalerBurstWrite(&tQC_IDLTI_SETTING_1[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 1
    ScalerBurstWrite(tQC_IDLTI_HLW, 8, GET_CURRENT_BANK_NUMBER(), P11_D4_I_DLTI_HLW_HOR_START_HSB_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);    // IDLTI HLW Table
    ScalerBurstWrite(tQC_IDLTI_HLW, 8, GET_CURRENT_BANK_NUMBER(), P51_D4_I_DLTI_HLW_HOR_START_HSB_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);    // IDLTI HLW Table

    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x00);    // Disable HLW

    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_M1_M2);
    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_M1_M2);

    // Case 0 : IDomainRandomGen(_MASS) + Setting1 + I_Domain_CRC
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDLTI_CRCTable_1, 1) << 0));

    ScalerBurstWrite(&tQC_IDLTI_SETTING_2[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 2
    ScalerBurstWrite(&tQC_IDLTI_SETTING_2[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 2

    // Case 1 : IDomainRandomGen(_MASS) + Setting2 + I_Domain_CRC + HLW(Inside B, Outside Bypass)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x06);     // Enable HLW(Inside B, Outside Bypass)
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x06);     // Enable HLW(Inside B, Outside Bypass)
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDLTI_CRCTable_2, 1) << 1));

    ScalerBurstWrite(&tQC_IDLTI_SETTING_3[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 3
    ScalerBurstWrite(&tQC_IDLTI_SETTING_3[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 3

    // Case 2 : IDomainRandomGen(_MASS) + Setting3 + I_Domain_CRC + HLW(Inside A, Outside B)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x0A);     // Enable HLW(Inside A, Outside B)
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDLTI_CRCTable_3, 1) << 2));

    ScalerBurstWrite(&tQC_IDLTI_SETTING_4[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 4
    ScalerBurstWrite(&tQC_IDLTI_SETTING_4[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 4

    // Case 3 : IDomainRandomGen(_MASS) + Setting4 + I_Domain_CRC + HLW(Inside Bypass, Outside A)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x03);     // Enable HLW(Inside Bypass, Outside A)
    DebugMessageQC("5. Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDLTI_CRCTable_4, 1) << 3));

    ScalerBurstWrite(&tQC_IDLTI_SETTING_5[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 5
    ScalerBurstWrite(&tQC_IDLTI_SETTING_5[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);        // IDLTI Table 5

    // Case 4 : IDomainRandomGen(_MASS) + Setting5 + I_Domain_CRC + HLW(Inside B, Outside B)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x0F);     // Enable HLW(Inside B, Outside B)
    DebugMessageQC("5. Mode_4", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDLTI_CRCTable_5, 1) << 4));

    ScalerSetByte(P11_A1_I_DLTI_CTRL_M1, 0x00);         // Disable IDLTI
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x00);     // Disable HLW
    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. IDLTI End", 0x00);

    if(ucData == 0x00)
    {
        DebugMessageQC("6. IDLTI PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. IDLTI FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : I Domain Dither Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCIDitherTest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. I Dither Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    // 10 bit dither test
    DebugMessageQC("5. Mode_0", 0x00);
    ScalerQCWaitForIDDomainEvent(_EVENT_IEN_START, _INPUT_PATH_M1_M2);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_10_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00, _BIT5 | _BIT4 | _BIT1 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA, 0x00, _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);
    ucData = ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDITHER_CRCTable_P0, 13) << 0);

    // 8 bit dither test
    DebugMessageQC("5. Mode_1", 0x00);
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_8_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00, _BIT5 | _BIT3 | _BIT2);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA, 0x00, _BIT1 | _BIT0);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);
    ucData = ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2, tQC_IDITHER_CRCTable_P1, 1) << 1);

    ScalerSetByte(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00);
    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. I Dither End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. I Dither PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. I Dither FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Scale Down Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCScaleDownTest(void)
{
    BYTE ucData = 0;

    BYTE ucTemp[2] = {0};

    DebugMessageQC("5. Scale down Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ucTemp[0] = ScalerGetByte(P0_19_M1_IPV_ACT_STA_L);
    ucTemp[1] = ScalerGetByte(P40_19_M2_IPV_ACT_STA_L);

    // increase frontporch
    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ucTemp[0] - 1);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, ucTemp[1] - 1);
    }

    // M1
    // Set Coefficient table 1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_HSD_COEF, _HSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_27_SD_USER_FILTER_ACCESS_PORT_M1, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_VSD_COEF, _VSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_27_SD_USER_FILTER_ACCESS_PORT_M1, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // M2
    // Set Coefficient table 1
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_HSD_COEF, _HSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P40_27_SD_USER_FILTER_ACCESS_PORT_M2, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_VSD_COEF, _VSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P40_27_SD_USER_FILTER_ACCESS_PORT_M2, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);


    // M1 HSD InitialPhase + Factor
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_04_H_SD_INIT_M1, 0x7F);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_43_H_SD_INIT_M_M1, 0xFF);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_44_H_SD_INIT_L_M_M1, 0xFC);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_05_H_SD_FACTOR_H_M1, 0x66);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_06_H_SD_FACTOR_M_M1, 0x66);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_07_H_SD_FACTOR_L_M1, 0x66);

    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_04_H_SD_INIT_M2, 0x7F);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_43_H_SD_INIT_M_M2, 0xFF);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_44_H_SD_INIT_L_M2, 0xFC);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_05_H_SD_FACTOR_H_M2, 0x66);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_06_H_SD_FACTOR_M_M2, 0x66);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_07_H_SD_FACTOR_L_M2, 0x66);

    // M1  VSD InitialPhase + Factor
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_00_V_SD_INIT_M1, 0x70);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_01_V_SD_FACTOR_H_M1, 0x09);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_02_V_SD_FACTOR_M_M1, 0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_03_V_SD_FACTOR_L_M1, 0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_42_V_SD_FACTOR_L1_M1, 0x00);
    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_00_V_SD_INIT_M2, 0x70);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_01_V_SD_FACTOR_H_M2, 0x09);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_02_V_SD_FACTOR_M_M2, 0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_03_V_SD_FACTOR_L_M2, 0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_42_V_SD_FACTOR_L1_M2, 0x00);

    //Enable SD Out Window Set
    // M1
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_36_SD_OUT_WID_M_M1, 0x02);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_37_SD_OUT_WID_L_M1, 0x80);

    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_38_SD_OUT_LEN_M_M1, 0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_39_SD_OUT_LEN_L_M1, 0xF0);

    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT3, 0x00);

    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_36_SD_OUT_WID_M_M2, 0x02);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_37_SD_OUT_WID_L_M2, 0x80);

    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_38_SD_OUT_LEN_M_M2, 0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_39_SD_OUT_LEN_L_M2, 0xF0);

    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT3, 0x00);

    // Enable H Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~(_BIT3 | _BIT1), _BIT1);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~(_BIT3 | _BIT1), _BIT1);

    // Enable V Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT0, _BIT0);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT0, _BIT0);

    DebugMessageQC("5. Mode_0", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_SD, _M1 | _M2, tScaleDownTest0_ICRCTable, 1) << 0);


    // LSB2bits is tied to 'b00
    // M1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, _BIT0);
    // M2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~_BIT0, _BIT0);

    DebugMessageQC("5. Mode_1", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_SD, _M1 | _M2, tScaleDownTest1_ICRCTable, 1) << 1);

    // M1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, 0x00);
    // M2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~_BIT0, 0x00);

    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ucTemp[0]);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, ucTemp[1]);
    }

    ScalerQCIDomainRandomGenOff();

     // Disable V Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT0, 0x00);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT0, 0x00);


    DebugMessageQC("5. Scale down End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. Scale down PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", 0x01);
        DebugMessageQC("6. Scale down FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQCHLWTest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. Highlight Window Start", 0x00);
    ScalerQCDDomainRandomGenOn(_MASS, _BIT_MODE_12);
    ScalerQCHighlightWindowOn();

    // RandomGen + HLW(Four border);
    DebugMessageQC("5. Mode_0", 0x00);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tHLWTest0_DCRCTable, 1) << 0);

    // RandomGen + HLW(Bottom & Right border);
    DebugMessageQC("5. Mode_1", 0x00);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tHLWTest1_DCRCTable, 1) << 1);

    // RandomGen + HLW(Top & Right border);
    DebugMessageQC("5. Mode_2", 0x00);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT4));
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tHLWTest2_DCRCTable, 1) << 2);

    // RandomGen + HLW(Top & Left border);
    DebugMessageQC("5. Mode_3", 0x00);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tHLWTest3_DCRCTable, 1) << 3);

    // RandomGen + HLW(Bottom & Left border);
    DebugMessageQC("5. Mode_4", 0x00);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5));
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tHLWTest4_DCRCTable, 1) << 4);


    ScalerQCDDomainPatternGenOff();
    ScalerQCHighlightWindowOff();

    DebugMessageQC("5. Highlight Window End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. Highlight Window PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. Highlight Window FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : LSR Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCLSRTest(void)
{
    BYTE ucData = 0;
    BYTE temp[9]=0;
    BYTE ucTemp = 0;


    DebugMessageQC("5. LSR Start", 0x00);

    ucData = 0;

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);

    DebugMessageQC("M domain CRC Test!",1);

    for(ucTemp=0; ucTemp < 3 ; ucTemp++)
    {
        if(ScalerQCCRCCompare_IM(_M_DOMAIN_CRC, _M_CRC_AFTER_FIFO, _M1 | _M2, tMDomain_Table, 1))
        {
            DebugMessageQC("M domain CRC fail!",ucTemp);
        }
    }

    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~(_BIT5 | _BIT4), 0x00);

    DebugMessageQC("5. Check SU mode0 D_CRC", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tScaleUpTest0_DCRCTable, 1) << 0);

    ScalerBurstWrite(tQC_LSR_SETTING, 180, GET_CURRENT_BANK_NUMBER(), P12_A0_SR_SHP_CTRL_0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(tQC_LSR_HLW, 15, GET_CURRENT_BANK_NUMBER(), P11_CC_LSR_HLW_H_START_HIGH, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);


    //0.LSR
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0x00); //0xxx
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tLSR_Table0, 1) << 0);

    //1.LSR + HLW inA outB
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0xA0); //1010
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tLSR_Table1, 1) << 1);

    //2.LSR + HLW inB outA
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0xE0); //1110
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tLSR_Table2, 1) << 2);

    //3.LSR + HLW inA outA
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0xB0); //1011
    DebugMessageQC("5. Mode_3", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tLSR_Table3, 1) << 3);

    //4.LSR + HLW inA outPass
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0x80); //1000
    DebugMessageQC("5. Mode_4", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tLSR_Table4, 1) << 5);

    //5.LSR + HLW inPass outB
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0xD0); //1101
    DebugMessageQC("5. Mode_5", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1|_M2, tLSR_Table5, 1) << 5);

    ScalerSetByte(P14_C0_LSR_CTRL, 0x00);
    ScalerSetByte(P54_C0_LSR_CTRL_M2, 0x00);
    ScalerSetByte(P11_B9_SCALER_LSR_HLW, 0x00);

    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. LSR End", 0x00);

    if(ucData == _TEST_PASS)
    {
        DebugMessageQC("6.====M Random LSR PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====M Random LSR Fail====", 0x00);
        return _TEST_FAIL;
    }

}

//--------------------------------------------------
// Description  : ScaleUp Test
// Input Value  : None
// Output Value : TEST_PASS/TEST_FAIL
//--------------------------------------------------
bit ScalerQCScaleUpTest(void)
{
    BYTE ucData = 0;
    BYTE ucTemp = 0;


    DebugMessageQC("5. Scale Up Start", 0x00);

    ucData = 0;

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1_M2);

    DebugMessageQC("M domain CRC Test!",1);

    for(ucTemp=0; ucTemp < 3 ; ucTemp++)
    {
        if(ScalerQCCRCCompare_IM(_M_DOMAIN_CRC, _M_CRC_AFTER_FIFO, _M1 | _M2, tMDomain_Table, 1))
        {
            DebugMessageQC("M domain CRC fail!",ucTemp);
        }
    }

    // 2D 4Line VSU
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF0, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF1, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT4);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_16_VER_FILTER_COEF_INI_M, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_17_VER_FILTER_COEF_INI_L, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x07);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0x95);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0xCE);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_10_HOR_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_14_HOR_FILTER_COEF_INI_M, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_15_HOR_FILTER_COEF_INI_L, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x05);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0x55);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0x55);

    // Enable V Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT1, _BIT1);
    // Enable H Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT0, _BIT0);

    DebugMessageQC("5. Mode_0", 0x00);

    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tScaleUpTest0_DCRCTable, 1) << 0);

    // Hcoef sel = 2nd, Vcoef sel = 1st
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT5);
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tScaleUpTest1_DCRCTable, 1) << 1);

    // fix H coef, fix V coef
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2, tScaleUpTest2_DCRCTable, 1) << 2);

    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~(_BIT5 | _BIT4), 0x00);
    ScalerQCIDomainRandomGenOff();


    DebugMessageQC("5. Scale Up End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. Scale Up PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. Scale Up FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Print CRC when not match
// Input Value  : ucCRC: IC CRC, ucNum: CRC Number
// Output Value : None
//--------------------------------------------------
void ScalerQCPrintCRC(BYTE ucFrame, BYTE ucPath, BYTE *ucCRC, BYTE ucNum)
{
    BYTE i = 0;
    char pchMessage[12]= NULL;
    strcpy(pchMessage, "5.M1_CRC[0]");

    switch(ucPath)
    {
        case 0:
        default: pchMessage[2] = 'M';pchMessage[3] = '1';break;
        case 1:  pchMessage[2] = 'M';pchMessage[3] = '2';break;
        case 2:  pchMessage[2] = 'S';pchMessage[3] = '1';break;
        case 3:  pchMessage[2] = 'S';pchMessage[3] = '2';break;
        case 4:  pchMessage[2] = 'R';pchMessage[3] = '1';break;
        case 5:  pchMessage[2] = 'R';pchMessage[3] = '2';break;
    }

    if(ucFrame > 0)
    {
        DebugMessageQC("5.======Frame=====", ucFrame);
    }

    for(i = 0; i < ucNum; i++)
    {
        pchMessage[9] = (i + 0x30);
        DebugMessageQC(pchMessage, ucCRC[i]);
    }

    ucCRC = ucCRC;
}

//--------------------------------------------------
// Description  : Compare CRC with IC Read out
// Input Value  : enumDomain: CRC domain, e.g. _I_DOMAIN
//                ucPosition: CRC Position, e.g._I_CRC_AFTER_VGIP
//                ucSourceSel: I domain: _M1,_M2, _M1|_M2(EO), _S1, _S2, _S1|_S2(EO)
//                             M domain: _M1,_M2, _M1|_M2(EO), _S1, _S2, _S1|_S2(EO), _ROT_M1, _ROT_M2, _ROT_M1|_ROT_M2,
//                ucCRC: CRC Table pointer
//                ucFrameNum: Frame number to be compared, if not by frame, set 1
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQCCRCCompare_IM(BYTE ucDomain, EnumIMCRCPosition enumPosition, BYTE ucSourceSel, BYTE *ucCRC, BYTE ucFrameNum)
{
    BYTE i = 0, j = 0, k = 0;
    BYTE xdata ucReadCRC[36] = {0};
    bit bFlag = _TEST_PASS;
//    BYTE ucOrder[6] = {_M1, _M2, _S1, _S2, _ROT_M1, _ROT_M2};
    BYTE ucOrder[6] = {0};
    WORD usAddr = P36_01_I_MAIN1_CRC_1;
    BYTE ucPathNum = 4;
    BYTE ucWaitType = _EVENT_IVS;
    BYTE ucDataPath = 0;

    ucOrder[0] = _M1;
    ucOrder[1] = _M2;
    ucOrder[2] = _S1;
    ucOrder[3] = _S2;
    ucOrder[4] = _ROT_M1;
    ucOrder[5] = _ROT_M2;

    if(ucDomain == _I_DOMAIN_CRC)
    {
        ScalerSetByte(P36_00_I_CRC_CTRL, 0x00);
        ScalerSetByte(P36_00_I_CRC_CTRL, ((enumPosition & 0x03) << 6) | ucSourceSel);

        switch(ucSourceSel)
        {
            case _M1:
                ucDataPath = _INPUT_PATH_M1;
                break;
            case _M2:
                ucDataPath = _INPUT_PATH_M2;
                break;
            case _M1|_M2://(EO)
                ucDataPath = _INPUT_PATH_M1_M2;
                break;
            case _S1:
                ucDataPath = _INPUT_PATH_S1;
                break;
            case _S2:
                ucDataPath = _INPUT_PATH_S2;
                break;
            case _S1|_S2://(EO)
                ucDataPath = _INPUT_PATH_S1_S2;
                break;
            case _M1|_M2|_S1|_S2:// only for QC
                ucDataPath = _INPUT_PATH_ALL;
                break;
            default:
                DebugMessageQC("ucSourceSel: No such case!", ucSourceSel);
                return _TEST_FAIL;
        }
    }
    else if(ucDomain == _M_DOMAIN_CRC)
    {
        ucWaitType = _EVENT_DVS;
        usAddr = P36_41_M_M1_CRC_1;
        ucPathNum = 6;
        ScalerSetByte(P36_40_M_CRC_CTRL, 0x00);
        ScalerSetByte(P36_40_M_CRC_CTRL, ucSourceSel);

        switch(ucSourceSel)
        {
            case _M1:
            case _ROT_M1:
                ucDataPath = _INPUT_PATH_M1;
                break;
            case _M2:
            case _ROT_M2:
                ucDataPath = _INPUT_PATH_M2;
                break;
            case _M1|_M2://(EO)
            case _ROT_M1|_ROT_M2:
                ucDataPath = _INPUT_PATH_M1_M2;
                break;
            case _S1:
                ucDataPath = _INPUT_PATH_S1;
                break;
            case _S2:
                ucDataPath = _INPUT_PATH_S2;
                break;
            case _S1|_S2://(EO)
                ucDataPath = _INPUT_PATH_S1_S2;
                break;
            default:
                DebugMessageQC("ucSourceSel: No such case!", ucSourceSel);
                return _TEST_FAIL;
        }
    }
    else
    {
        ucWaitType = _EVENT_DVS;
        usAddr = P36_2D_D_MAIN1_CRC_1;
        ucPathNum = 3;
        ucDataPath = _INPUT_PATH_ALL;
        ScalerSetByte(P36_2C_D_CRC_CTRL, 0x00);
        ScalerSetByte(P36_2C_D_CRC_CTRL, ((enumPosition & 0x01) << 7) | ucSourceSel);
    }

    ScalerQCWaitForIDDomainEvent(ucWaitType, ucDataPath);

    for(k = 0; k < ucFrameNum; k++)
    {
        ScalerQCWaitForIDDomainEvent(ucWaitType, ucDataPath);
        ScalerTimerDelayXms(2);

        for(j = 0; j < ucPathNum; j++)
        {
            if((ucSourceSel & ucOrder[j]) != 0)
            {
                for(i = 6*j; i < 6*(j + 1); i++)
                {
                    ucReadCRC[i] = ScalerGetByte(usAddr + i);
                }
            }
        }

        for(j = 0; j < ucPathNum; j++)
        {
            if((ucSourceSel & ucOrder[j]) != 0)
            {
                for(i = 6*j; i < 6*(j + 1); i++)
                {
                    if(ucReadCRC[i] != ucCRC[k*ucPathNum*6 + i])
                    {
                        ScalerQCPrintCRC(k, j, ucReadCRC + 6*j, 6);
                        bFlag = _TEST_FAIL;
                        break;
                    }
                }
             }
        }

        if(bFlag == _TEST_FAIL)
        {
            return _TEST_FAIL;
        }
    }

    if(bFlag == _TEST_PASS)
    {
        DebugMessageQC("5.===Pass===", 0);
    }

    return bFlag;
}

//--------------------------------------------------
// Description  : Enable VGATOP Random Generator
// Input Value  : bRandomSelect ---> 0: R = G = B, 1: R != G != B
// Output Value : None
//--------------------------------------------------
void ScalerQCVGATopRandomGenOn(bit bRandomSelect)
{
    // Set default initial value
    ScalerSetByte(P30_DF_VGATOP_PAT_GEN_RED_INI_L, 0x01);
    ScalerSetByte(P30_E0_VGATOP_PAT_GEN_GRN_INI_L, 0x01);
    ScalerSetByte(P30_E1_VGATOP_PAT_GEN_BLU_INI_L, 0x01);

    if(bRandomSelect == _GRAY)
    {
       ScalerSetBit(P30_DD_VGATOP_PAT_GEN_CTRL0, ~_BIT6, 0x00);
    }
    else
    {
       ScalerSetBit(P30_DD_VGATOP_PAT_GEN_CTRL0, ~_BIT6, _BIT6);
    }

    ScalerSetBit(P30_A0_VGATOP_VGIP_CTRL, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Disable VGATOP Random Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCVGATopRandomGenOff(void)
{
    ScalerSetBit(P30_A0_VGATOP_VGIP_CTRL, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : Enable I Domain Random Generator
// Input Value  : bRandomSelect ---> 0: R = G = B, 1: R != G != B
// Output Value : None
//--------------------------------------------------
void ScalerQCIDomainRandomGenOn(bit bRandomSelect)
{
    if(bRandomSelect == _GRAY)
    {
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_10_I_PG_CTRL_0_M1, ~_BIT6, 0x00);
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0x4000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0x4000, ~_BIT6, 0x00);
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0x8000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0x8000, ~_BIT6, 0x00);
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0xC000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0xC000, ~_BIT6, 0x00);
    }
    else
    {
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_10_I_PG_CTRL_0_M1, ~_BIT6, _BIT6);
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0x4000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0x4000, ~_BIT6, _BIT6);
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0x8000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0x8000, ~_BIT6, _BIT6);
       ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0xC000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0xC000, ~_BIT6, _BIT6);
    }

    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1, ~_BIT7, 0x00);
    ScalerSetBit(P0_10_M1_VGIP_CTRL, ~_BIT7, _BIT7);

    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1 + 0x4000, ~_BIT7, 0x00);
    ScalerSetBit(P0_10_M1_VGIP_CTRL + 0x4000, ~_BIT7, _BIT7);

    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1 + 0x8000, ~_BIT7, 0x00);
    ScalerSetBit(P0_10_M1_VGIP_CTRL + 0x8000, ~_BIT7, _BIT7);

    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1 + 0xC000, ~_BIT7, 0x00);
    ScalerSetBit(P0_10_M1_VGIP_CTRL + 0xC000, ~_BIT7, _BIT7);
}

//--------------------------------------------------
// Description  : Disable I Domain Random Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCIDomainRandomGenOff(void)
{
    // M1 Setting
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_10_I_PG_CTRL_0_M1, ~_BIT6, 0x00);
    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    ScalerSetBit(P0_10_M1_VGIP_CTRL, ~_BIT7, 0x00);

    // M2 Setting
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0x4000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0x4000, ~_BIT6, 0x00);
    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1 + 0x4000, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    ScalerSetBit(P0_10_M1_VGIP_CTRL + 0x4000, ~_BIT7, 0x00);

    // S1 Setting
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0x8000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0x8000, ~_BIT6, 0x00);
    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1 + 0x8000, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    ScalerSetBit(P0_10_M1_VGIP_CTRL + 0x8000, ~_BIT7, 0x00);

    // S2 Setting
    ScalerSetDataPortBit(P0_24_SD_ADDRESS_PORT_M1 + 0xC000, _P0_25_PT_10_I_PG_CTRL_0_M1 + 0xC000, ~_BIT6, 0x00);
    ScalerSetBit(P0_24_SD_ADDRESS_PORT_M1 + 0xC000, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    ScalerSetBit(P0_10_M1_VGIP_CTRL + 0xC000, ~_BIT7, 0x00);
}

//--------------------------------------------------
// Description  : Enable Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCHighlightWindowOn(void)
{
    ScalerSetByte(P0_60_HLW_ADDR_PORT, 0x00);

    ScalerBurstWrite(tQC_HIGHLIGHT_WINDOW_SETTING, 19, GET_CURRENT_BANK_NUMBER(), P0_61_HLW_DATA_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : Disable Highlight Window
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerQCHighlightWindowOff(void)
{
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_0D_HLW_CONTROL1, 0x00);
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_0E_HLW_CONTROL0, 0x00);
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_0F_HLW_CONTROL2, 0x00);
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_10_HLW_CONTROL3, 0x00);
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_11_HLW_SETSEL0, 0x00);
    ScalerSetDataPortByte(P0_60_HLW_ADDR_PORT, _P0_61_PT_12_HLW_SETSEL1, 0x00);
    ScalerSetDataPortBit(P0_60_HLW_ADDR_PORT, _P0_61_PT_0C_HLW_BORDER_EN, ~_BIT0, 0x00);
}

#if(_QC_4P_MODE_ == _ON)
//--------------------------------------------------
// Description  : Set Scale Up coef
// Input Value  : H/V coef table, length
// Output Value : none
//--------------------------------------------------
void ScalerQCSetScalingCoef()
{
    // M1
    // Set Coefficient table 1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    // Disable Coefficient Access,
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6 | _BIT5), 0x00);
    // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT4);

    // M2
    // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x4000, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P40_37_SCALE_UP_FOR_LINE_INTERLEAVE_M2, ~_BIT0, _BIT0);

    // S1
    // Set Coefficient table 1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // Disable Coefficient Access,
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT5 | _BIT4), _BIT4);

    // S2
    // Set HSU to use coefficient table 1 & set VSU to use coefficient table 2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0xC000, ~(_BIT5 | _BIT4), _BIT4);
}

//--------------------------------------------------
// Description  : Decide which scaling up function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerQCSetScalingUp(EnumDisplayDataPath enumDisplayDataPath, const StructSDRAMDataInfo *pstFIFOScaling, const StructDisplayInfo *pstMDomainOutputData)
{
    WORD usRegPageSel = 0x00;

    switch(enumDisplayDataPath)
    {
        case _DISPLAY_PATH_M1:

            usRegPageSel = _REG_MAIN1_PAGE;
            break;

        case _DISPLAY_PATH_M2:

            usRegPageSel = _REG_MAIN2_PAGE;
            break;

        case _DISPLAY_PATH_S1:

            usRegPageSel = _REG_SUB1_PAGE;
            break;

        case _DISPLAY_PATH_S2:

            usRegPageSel = _REG_SUB2_PAGE;
            break;

        default:
            break;
    }

    CLR_V_SCALE_UP();
    CLR_H_SCALE_UP();

    // Disable Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + usRegPageSel, ~(_BIT1 | _BIT0), 0x00);

    //===============================
    // Decide V direction scaling up
    //===============================
    // Set V Scaling Up Factor
    if(pstFIFOScaling->usOutputVHeight < pstMDomainOutputData->usVHeight)
    {
        SET_V_SCALE_UP();

        PDATA_DWORD(0) = (DWORD)pstFIFOScaling->usOutputVHeight << 20;
        PDATA_DWORD(0) = (PDATA_DWORD(0) / pstMDomainOutputData->usVHeight) + (PDATA_DWORD(0) % 2);

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_03_VER_SCALE_FACTOR_H, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_04_VER_SCALE_FACTOR_M, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_05_VER_SCALE_FACTOR_L, (PDATA_DWORD(0) & 0xFF));

        // 1080i->1080P  no video compensation
        if((GET_INTERLACED_MODE() == _FALSE) || (ScalerGetBit(P0_10_M1_VGIP_CTRL, (_BIT3 | _BIT2)) == 0x00) || (pstFIFOScaling->usOutputHWidth == 1080 && pstMDomainOutputData->usHWidth == 1080))
        {
            // Set V Initial Phase
            // R = Input Height /Output Height
            // ideal initial phase: for 4line SU = (1+R)*16*8
            PDATA_DWORD(0) = (DWORD)(pstFIFOScaling->usOutputVHeight + pstMDomainOutputData->usVHeight) * 16 * 8 / pstMDomainOutputData->usVHeight;
            ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_11_VER_FILTER_COEF_INI, pData[3]);
        }
        else
        {
            ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xFF);
        }
    }
    else
    {
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x0F);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0xFF);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0xFF);
    }

    if(GET_V_SCALE_UP() == _TRUE)
    {
        // Enable V Scale Up
        ScalerSetBit(P0_32_SCALE_CONTROL_REG + usRegPageSel, ~_BIT1, _BIT1);
    }

    //===============================
    // Decide H direction scaling up
    //===============================
    // Set H Scaling Up Factor
    SET_H_SCALE_UP();

    if(pstFIFOScaling->usOutputHWidth < pstMDomainOutputData->usHWidth)
    {
        SET_H_SCALE_UP();

        PDATA_DWORD(0) = (DWORD)pstFIFOScaling->usOutputHWidth << (20 - 1);
        PDATA_DWORD(0) = (PDATA_DWORD(0) / (pstMDomainOutputData->usHWidth >> 1)) + (PDATA_DWORD(0) % 2);

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_00_HOR_SCALE_FACTOR_H, ((PDATA_DWORD(0) >> 16) & 0x0F));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_01_HOR_SCALE_FACTOR_M, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_02_HOR_SCALE_FACTOR_L, (PDATA_DWORD(0) & 0xFF));

        // Set H Initial Phase
        // R = Input width /Output width
        // ideal initial phase = (1+R)*16*8
        PDATA_DWORD(0) = (DWORD)(pstFIFOScaling->usOutputHWidth + pstMDomainOutputData->usHWidth) * 16 * 8 / pstMDomainOutputData->usHWidth;

        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_10_HOR_FILTER_COEF_INI, pData[3]);
    }
    else
    {
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x0F);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0xFF);
        ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + usRegPageSel, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0xFF);
    }

   //===============================
    // Set H direction scaling up
    //===============================
    if(GET_H_SCALE_UP() == _TRUE)
    {
        // Enable H Scale Up
        ScalerSetBit(P0_32_SCALE_CONTROL_REG + usRegPageSel, ~_BIT0, _BIT0);
    }

}

//--------------------------------------------------
// Description  : Set Scale Down Coef
// Input Value  : none
// Output Value : none
//--------------------------------------------------
void ScalerQCSetScalingDownCoef(void)
{
    // M1
    // Set Coefficient table 1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_HSD_COEF, _HSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_27_SD_USER_FILTER_ACCESS_PORT_M1, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_VSD_COEF, _VSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_27_SD_USER_FILTER_ACCESS_PORT_M1, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // M2
    // Set Coefficient table 1
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_HSD_COEF, _HSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P40_27_SD_USER_FILTER_ACCESS_PORT_M2, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_VSD_COEF, _VSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P40_27_SD_USER_FILTER_ACCESS_PORT_M2, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // S1
    // Set Coefficient table 1
    ScalerSetBit(P80_26_SD_FILTER_CONTROL_REG_S1, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_HSD_COEF, _HSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P80_27_SD_USER_FILTER_ACCESS_PORT_S1, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(P80_26_SD_FILTER_CONTROL_REG_S1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_VSD_COEF, _VSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P80_27_SD_USER_FILTER_ACCESS_PORT_S1, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    // S2
    // Set Coefficient table 1
    ScalerSetBit(PC0_26_SD_FILTER_CONTROL_REG_S2, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_HSD_COEF, _HSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), PC0_27_SD_USER_FILTER_ACCESS_PORT_S2, _BURSTWRITE_DATA_COMMON,_BURSTWRITE_FROM_FLASH);
    // Set Coefficient table 2
    ScalerSetBit(PC0_26_SD_FILTER_CONTROL_REG_S2, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_VSD_COEF, _VSD_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), PC0_27_SD_USER_FILTER_ACCESS_PORT_S2, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
}


//--------------------------------------------------
// Description  : Decide which scaling down function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerQCSetScalingDown(EnumInputDataPath enumInputDataPath, const StructSDRAMDataInfo *pstFIFOScaling, const StructTimingInfo *pstMDomainInputData)
{
    WORD usRegPageSel = 0x0000;
    bit bEvenOdd = _FALSE;

    switch(enumInputDataPath)
    {
        case _INPUT_PATH_M1:

            usRegPageSel = _REG_MAIN1_PAGE;
            break;

        case _INPUT_PATH_M2:

            usRegPageSel = _REG_MAIN2_PAGE;
            break;

        case _INPUT_PATH_M1_M2:

            usRegPageSel = _REG_MAIN1_PAGE;
            bEvenOdd = _TRUE;
            break;

        case _INPUT_PATH_S1:

            usRegPageSel = _REG_SUB1_PAGE;
            break;

        case _INPUT_PATH_S2:

            usRegPageSel = _REG_SUB2_PAGE;
            break;

        case _INPUT_PATH_S1_S2:

            usRegPageSel = _REG_SUB1_PAGE;
            bEvenOdd = _TRUE;

        default:
            break;
    }

    CLR_V_SCALE_DOWN();
    CLR_H_SCALE_DOWN();

    // Disable Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel, ~(_BIT7 | _BIT3 |_BIT2 | _BIT1 | _BIT0), 0x00);

    if(bEvenOdd == _TRUE)
    {
        // M2 or S2
        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel + 0x4000, ~(_BIT7 | _BIT3 |_BIT2 | _BIT1 | _BIT0), 0x00);
    }
    //===============================
    // Decide H direction scaling down
    //===============================
    // Set H Scaling Down Factor
    if(pstMDomainInputData->usHWidth > pstFIFOScaling->usInputHWidth)
    {
        SET_H_SCALE_DOWN();

        // Calculate Scaling Factor
        // (4096 << 20) == 1<<32 DWORD  -> (IHwidth<<20)/(DHwidth) == (IHwidth<<19)/(DHwidth>>1)
        PDATA_DWORD(0) = (DWORD)pstMDomainInputData->usHWidth << (20 - 1);
        PDATA_DWORD(0) = (PDATA_DWORD(0) / (pstFIFOScaling->usInputHWidth >> 1)) + (PDATA_DWORD(0) % 2);

        // M1
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_05_H_SD_FACTOR_H_M1, ((PDATA_DWORD(0) >> 16) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_06_H_SD_FACTOR_M_M1, ((PDATA_DWORD(0) >> 8) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_07_H_SD_FACTOR_L_M1, (PDATA_DWORD(0) & 0xFF));

        if(bEvenOdd == _TRUE)
        {
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_05_H_SD_FACTOR_H_M1, ((PDATA_DWORD(0) >> 16) & 0xFF));
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_06_H_SD_FACTOR_M_M1, ((PDATA_DWORD(0) >> 8) & 0xFF));
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_07_H_SD_FACTOR_L_M1, (PDATA_DWORD(0) & 0xFF));
        }
        // Calculate Initial Phase
        // (factor - 1) / 2  // 1.6
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 15) - 32;

        if(PDATA_DWORD(0) > 0x7F)
        {
            PDATA_DWORD(0) = 0x7F;
        }
        // M1
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_04_H_SD_INIT_M1, PDATA_DWORD(0));

        if(bEvenOdd == _TRUE)
        {
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_04_H_SD_INIT_M1, PDATA_DWORD(0));
        }
    }
    else
    {
        // M1
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_04_H_SD_INIT_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_05_H_SD_FACTOR_H_M1, 0x10);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_06_H_SD_FACTOR_M_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_07_H_SD_FACTOR_L_M1, 0x00);

        if(bEvenOdd == _TRUE)
        {
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_04_H_SD_INIT_M1, 0x00);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_05_H_SD_FACTOR_H_M1, 0x10);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_06_H_SD_FACTOR_M_M1, 0x00);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_07_H_SD_FACTOR_L_M1, 0x00);
        }
    }

    if(GET_H_SCALE_DOWN() == _TRUE)
    {
        // Enable H Scale Down
        // M1
        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel, ~(_BIT3 | _BIT1), _BIT1);

        if(bEvenOdd == _TRUE)
        {
            ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel + 0x4000, ~(_BIT3 | _BIT1), _BIT1);
        }
    }

    //===============================
    // Decide V direction scaling down
    //===============================
    // Set V Scaling Down Factor
    if((pstMDomainInputData->usVHeight) > pstFIFOScaling->usInputVHeight)
    {
        SET_V_SCALE_DOWN();

        // Calculate Scaling Factor
        PDATA_DWORD(0) = ((DWORD)(pstMDomainInputData->usVHeight) << 20);
        PDATA_DWORD(0) = (PDATA_DWORD(0) / pstFIFOScaling->usInputVHeight) + (PDATA_DWORD(0) % 2);
        // M1
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_01_V_SD_FACTOR_H_M1, ((PDATA_DWORD(0) >> 19) & 0x0F));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_02_V_SD_FACTOR_M_M1, ((PDATA_DWORD(0) >> 11) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_03_V_SD_FACTOR_L_M1, ((PDATA_DWORD(0) >> 3) & 0xFF));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_42_V_SD_FACTOR_L1_M1, (((PDATA_DWORD(0) & 0x07) << 5) & 0xE0));

        if(bEvenOdd == _TRUE)
        {
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_01_V_SD_FACTOR_H_M1, ((PDATA_DWORD(0) >> 19) & 0x0F));
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_02_V_SD_FACTOR_M_M1, ((PDATA_DWORD(0) >> 11) & 0xFF));
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_03_V_SD_FACTOR_L_M1, ((PDATA_DWORD(0) >> 3) & 0xFF));
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_42_V_SD_FACTOR_L1_M1, (((PDATA_DWORD(0) & 0x07) << 5) & 0xE0));
        }

                // Calculate Initial Phase
        PDATA_DWORD(0) = (PDATA_DWORD(0) >> 15) - 32;

        if(PDATA_DWORD(0) > 0x7F)
        {
            PDATA_DWORD(0) = 0x7F;
        }
        // M1
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_00_V_SD_INIT_M1, PDATA_DWORD(0));

        if(bEvenOdd == _TRUE)
        {
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_00_V_SD_INIT_M1, PDATA_DWORD(0));
        }
    }
    else
    {
        // M1
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_00_V_SD_INIT_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_01_V_SD_FACTOR_H_M1, 0x02);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_02_V_SD_FACTOR_M_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_03_V_SD_FACTOR_L_M1, 0x00);
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_42_V_SD_FACTOR_L1_M1, 0x00);

        if(bEvenOdd == _TRUE)
        {
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_00_V_SD_INIT_M1, 0x00);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_01_V_SD_FACTOR_H_M1, 0x02);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_02_V_SD_FACTOR_M_M1, 0x00);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_03_V_SD_FACTOR_L_M1, 0x00);
            ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_42_V_SD_FACTOR_L1_M1, 0x00);
        }
    }

    if(GET_V_SCALE_DOWN() == _TRUE)
    {
        // Enable V Scale Down
        // M1
        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel, ~_BIT0, _BIT0);

        if(bEvenOdd == _TRUE)
        {
            ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel + 0x4000, ~_BIT0, _BIT0);
        }
    }

    PDATA_WORD(0) = pstFIFOScaling->usInputVHeight >> (WORD)bEvenOdd;

    //Enable SD Out Window Set
    // M1
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_36_SD_OUT_WID_M_M1, ((pstFIFOScaling->usInputHWidth >> 8) & 0x0F));
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_37_SD_OUT_WID_L_M1, pstFIFOScaling->usInputHWidth);

    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_38_SD_OUT_LEN_M_M1, (pData[0] & 0x0F));
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel, _P0_25_PT_39_SD_OUT_LEN_L_M1, pData[1]);

    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel, ~_BIT3, 0x00);

    if(bEvenOdd == _TRUE)
    {
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_36_SD_OUT_WID_M_M1, ((pstFIFOScaling->usInputHWidth >> 8) & 0x0F));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_37_SD_OUT_WID_L_M1, pstFIFOScaling->usInputHWidth);

        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_38_SD_OUT_LEN_M_M1, (pData[0] & 0x0F));
        ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1 + usRegPageSel + 0x4000, _P0_25_PT_39_SD_OUT_LEN_L_M1, pData[1]);

        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + usRegPageSel + 0x4000, ~_BIT3, 0x00);
    }
}

//--------------------------------------------------
// Description  : Decide which scaling function should be performed
// Input Value  : Input/Output H/V Active Region
// Output Value : None
//--------------------------------------------------
void ScalerQCSetScaling(bit bMode)
{
    EnumDisplayDataPath enumDisplayDataPath = _DISPLAY_PATH_M1;
    StructSDRAMDataInfo stFIFOScaling;
    StructDisplayInfo stMDomainOutputData;
    EnumInputDataPath enumInputDataPath = _INPUT_PATH_M1;
    StructTimingInfo stMDomainInputData;

    PDATA_WORD(1) = 0x0000;
    for(pData[0] = 0; pData[0] < 4; pData[0] ++)
    {
        // Disable Scale down
        ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1 + PDATA_WORD(1), ~(_BIT7 | _BIT3 |_BIT2 | _BIT1 | _BIT0), 0x00);
        // Disable Scale Up
        ScalerSetBit(P0_32_SCALE_CONTROL_REG + PDATA_WORD(1), ~(_BIT1 | _BIT0), 0x00);
        PDATA_WORD(1) += 0x4000;
    }

    if(bMode == _4P)
    {
        if(GET_MDOMAIN_INPUT_HWIDTH() == 1280)
        {
            ScalerQCSetScalingCoef();

            stFIFOScaling.usOutputHWidth = 1280;
            stFIFOScaling.usOutputVHeight = 1024;

            stMDomainOutputData.usHWidth = 1920;
            stMDomainOutputData.usVHeight = 1080;

            enumDisplayDataPath = _DISPLAY_PATH_M1;
            ScalerQCSetScalingUp(enumDisplayDataPath, &stFIFOScaling, &stMDomainOutputData);
            enumDisplayDataPath = _DISPLAY_PATH_M2;
            ScalerQCSetScalingUp(enumDisplayDataPath, &stFIFOScaling, &stMDomainOutputData);
            enumDisplayDataPath = _DISPLAY_PATH_S1;
            ScalerQCSetScalingUp(enumDisplayDataPath, &stFIFOScaling, &stMDomainOutputData);
            enumDisplayDataPath = _DISPLAY_PATH_S2;
            ScalerQCSetScalingUp(enumDisplayDataPath, &stFIFOScaling, &stMDomainOutputData);
        }
        else
        {
            ScalerQCSetScalingDownCoef();

            stFIFOScaling.usInputHWidth = 1920;
            stFIFOScaling.usInputVHeight = 1080;

            stMDomainInputData.usHWidth = 2048;
            stMDomainInputData.usVHeight = 2160;

            enumInputDataPath = _INPUT_PATH_M1;
            ScalerQCSetScalingDown(enumInputDataPath, &stFIFOScaling, &stMDomainInputData);
            enumInputDataPath = _INPUT_PATH_M2;
            ScalerQCSetScalingDown(enumInputDataPath, &stFIFOScaling, &stMDomainInputData);
            enumInputDataPath = _INPUT_PATH_S1;
            ScalerQCSetScalingDown(enumInputDataPath, &stFIFOScaling, &stMDomainInputData);
            enumInputDataPath = _INPUT_PATH_S2;
            ScalerQCSetScalingDown(enumInputDataPath, &stFIFOScaling, &stMDomainInputData);

        }
    }
    else if(bMode == _PBP_LR)
    {
        ScalerQCSetScalingDownCoef();

        stFIFOScaling.usInputHWidth = 1920;
        stFIFOScaling.usInputVHeight = 1080;

        stMDomainInputData.usHWidth = 4096;
        stMDomainInputData.usVHeight = 2160;

        enumInputDataPath = _INPUT_PATH_M1_M2;
        ScalerQCSetScalingDown(enumInputDataPath, &stFIFOScaling, &stMDomainInputData);
        enumInputDataPath = _INPUT_PATH_S1_S2;
        ScalerQCSetScalingDown(enumInputDataPath, &stFIFOScaling, &stMDomainInputData);
    }

}

//--------------------------------------------------
// Description  : 422to444 Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC4P422to444Test(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. 4P 422to444 Start", 0x00);
    DebugMessageQC("5. Check I CRC", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, t422to444_4P_Table0, 1) << 0);

    //0.
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x08);
    ScalerSetByte(P31_41_YUV422_TO_444_PATH1, 0x08);
    ScalerSetByte(P31_42_YUV422_TO_444_PATH2, 0x08);
    ScalerSetByte(P31_43_YUV422_TO_444_PATH3, 0x08);
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, t422to444_4P_Table0, 1) << 0);

    //1.
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x0B);
    ScalerSetByte(P31_41_YUV422_TO_444_PATH1, 0x0B);
    ScalerSetByte(P31_42_YUV422_TO_444_PATH2, 0x0B);
    ScalerSetByte(P31_43_YUV422_TO_444_PATH3, 0x0B);
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, t422to444_4P_Table1, 1) << 1);

    //2.
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x0E);
    ScalerSetByte(P31_41_YUV422_TO_444_PATH1, 0x0E);
    ScalerSetByte(P31_42_YUV422_TO_444_PATH2, 0x0E);
    ScalerSetByte(P31_43_YUV422_TO_444_PATH3, 0x0E);
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, t422to444_4P_Table2, 1) << 2);


    //disable 422to444
    ScalerSetByte(P31_40_YUV422_TO_444_PATH0, 0x00);
    ScalerSetByte(P31_41_YUV422_TO_444_PATH1, 0x00);
    ScalerSetByte(P31_42_YUV422_TO_444_PATH2, 0x00);
    ScalerSetByte(P31_43_YUV422_TO_444_PATH3, 0x00);

    DebugMessageQC("5. 4P 422to444 End", 0x00);

    if(ucData == _TEST_PASS)
    {
        DebugMessageQC("6.====4P 422to444 PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====4P 422to444 Fail====", 0x00);
        return _TEST_FAIL;
    }

}

//--------------------------------------------------
// Description  : FC TEST: 4P
// Input Value  : None
// return Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC4PFormatConversionTest(void)
{
    BYTE ucData = 0;
    BYTE ucIVS = 0;
    BYTE ucTemp[14];

    DebugMessageQC("5. Format Conversion 4P Test Start", 0x00);

    ScalerRead(P31_00_FC_INPUT_SEL_P01, 14, ucTemp, _AUTOINC);

    ScalerBurstWrite(tFC_TEST1, sizeof(tFC_TEST1), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);

    // Even/Odd, 4096x2160, 256 Gray Level
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, tFC_CRC_4P, 1) << 0);

    ScalerSetByte(0x3100, ucTemp[0]);
    ScalerSetByte(0x3101, ucTemp[1]);
    ScalerSetByte(0x3102, ucTemp[2]);
    ScalerSetByte(0x3103, ucTemp[3]);
    ScalerSetByte(0x3104, ucTemp[4]);
    ScalerSetByte(0x3105, ucTemp[5]);
    ScalerSetByte(0x3106, ucTemp[6]);
    ScalerSetByte(0x3107, ucTemp[7]);
    ScalerSetByte(0x3108, ucTemp[8]);
    ScalerSetByte(0x3109, ucTemp[9]);
    ScalerSetByte(0x310A, ucTemp[10]);
    ScalerSetByte(0x310C, ucTemp[12]);
    ScalerSetByte(0x310D, ucTemp[13]);

    DebugMessageQC("5. Format Conversion 4P Test End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. Format Conversion 4P PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. Format Conversion 4P FAIL", 0x00);
        return _TEST_FAIL;
    }
}
//--------------------------------------------------
// Description  : 4P I-Domain Color Conversion Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC4PIDomainColorConvTest(void)
{
    BYTE ucResult = _TEST_PASS;

    DebugMessageQC("5. 4P I-Domain Color Conversion Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerTimerDelayXms(50);

    // Enable YUV2RGB coefficient access
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), P0_9D_RGB2YCC_COEF_DATA, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT3, 0x00);

    ScalerSetBit(P40_9C_RGB2YCC_CTRL_M2, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), P40_9D_RGB2YCC_COEF_DATA_M2, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P40_9C_RGB2YCC_CTRL_M2, ~_BIT3, 0x00);

    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), P80_9D_RGB2YCC_COEF_DATA_S1, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, ~_BIT3, 0x00);

    ScalerSetBit(PC0_9C_RGB2YCC_CTRL_S2, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), PC0_9D_RGB2YCC_COEF_DATA_S2, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(PC0_9C_RGB2YCC_CTRL_S2, ~_BIT3, 0x00);

    //////////////////////////////////////////////////////////////////
    // case 0: RGB->YUV, enable y out shift, enable CbCr out shift + 2048, Output_sel
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, 0x00, _BIT7 | _BIT6 | _BIT4 | _BIT0);  // 0xD1
    ScalerSetBit(P40_9C_RGB2YCC_CTRL_M2, 0x00, _BIT7 | _BIT6 | _BIT0);  // 0xC1
    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, 0x00, _BIT7 | _BIT6 | _BIT0);  // 0xC1
    ScalerSetBit(PC0_9C_RGB2YCC_CTRL_S2, 0x00, _BIT7 | _BIT6 | _BIT0);  // 0xC1

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);

    DebugMessageQC("5. 4P Color Conv case", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, (_M1 | _M2 | _S1 | _S2), tICOLORCONV_4P_CRC_TABLE, 1));

    ScalerQCIDomainRandomGenOff();

    // Disable YUV2RGB conversion
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT0, 0x00);
    ScalerSetBit(P40_9C_RGB2YCC_CTRL_M2, ~_BIT0, 0x00);
    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, ~_BIT0, 0x00);
    ScalerSetBit(PC0_9C_RGB2YCC_CTRL_S2, ~_BIT0, 0x00);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);

    DebugMessageQC("5. 4P I-Domain Color Conversion End", 0x00);

    if(ucResult == 0)
    {
        DebugMessageQC("6. 4P I-Domain Color Conversion PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. 4P Fail Mode", ucResult);
        DebugMessageQC("6. 4P I-Domain Color Conversion FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : IDLTI Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC4PIDLTITest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. 4P IDLTI Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerBurstWrite(&tQC_IDLTI_SETTING_4P[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI Table 1
    ScalerBurstWrite(&tQC_IDLTI_SETTING_4P[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);      // IDLTI Table 1
    ScalerBurstWrite(&tQC_IDLTI_SETTING_4P[36], 18, GET_CURRENT_BANK_NUMBER(), P91_A1_I_DLTI_CTRL_S1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);      // IDLTI Table 1
    ScalerBurstWrite(&tQC_IDLTI_SETTING_4P[54], 18, GET_CURRENT_BANK_NUMBER(), PD1_A1_I_DLTI_CTRL_S2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);      // IDLTI Table 1
    ScalerBurstWrite(tQC_IDLTI_HLW_4P, 8, GET_CURRENT_BANK_NUMBER(), P11_D4_I_DLTI_HLW_HOR_START_HSB_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table 1
    ScalerBurstWrite(tQC_IDLTI_HLW_4P, 8, GET_CURRENT_BANK_NUMBER(), P51_D4_I_DLTI_HLW_HOR_START_HSB_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table 1
    ScalerBurstWrite(tQC_IDLTI_HLW_4P, 8, GET_CURRENT_BANK_NUMBER(), P91_D4_I_DLTI_HLW_HOR_START_HSB_S1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table 1
    ScalerBurstWrite(tQC_IDLTI_HLW_4P, 8, GET_CURRENT_BANK_NUMBER(), PD1_D4_I_DLTI_HLW_HOR_START_HSB_S2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table 1

    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x00);     // Disable HLW
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x00);     // Disable HLW
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x00);     // Disable HLW
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x00);     // Disable HLW

    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_ALL);
    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_ALL);

    // Case 0 : IDomainRandomGen(_MASS) + Setting1 + I_Domain_CRC
    DebugMessageQC("5. 4P_Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_4P_1, 1) << 0));

    // Case 1 : IDomainRandomGen(_MASS) + Setting2 + I_Domain_CRC + HLW
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x02);     // Enable HLW(Used Inside)
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x03);     // Enable HLW(Used Outside)
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x02);     // Enable HLW(Used Inside)
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x03);     // Enable HLW(Used Outside)
    DebugMessageQC("5. 4P_Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_4P_2, 1) << 1));

    // Case 2 : IDomainRandomGen(_MASS) + Setting3 + I_Domain_CRC + HLW
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x03);     // Enable HLW(Used Outside)
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x02);     // Enable HLW(Used Inside)
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x03);     // Enable HLW(Used Outside)
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x02);     // Enable HLW(Used Inside)
    DebugMessageQC("5. 4P_Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_4P_3, 1) << 2));

    ScalerSetByte(P11_A1_I_DLTI_CTRL_M1, 0x00);         // Disable IDLTI
    ScalerSetByte(P51_A1_I_DLTI_CTRL_M2, 0x00);         // Disable IDLTI
    ScalerSetByte(P91_A1_I_DLTI_CTRL_S1, 0x00);         // Disable IDLTI
    ScalerSetByte(PD1_A1_I_DLTI_CTRL_S2, 0x00);         // Disable IDLTI
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x00);     // Disable HLW
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x00);     // Disable HLW
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x00);     // Disable HLW
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x00);     // Disable HLW
    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. 4P IDLTI End", 0x00);

    if(ucData == 0x00)
    {
        DebugMessageQC("6. 4P IDLTI PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. 4P Fail Mode", ucData);
        DebugMessageQC("6. 4P IDLTI FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : I Domain Dither Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQC4PIDitherTest(void)
{
    BYTE ucData = 0;
    BYTE ucReadCRC[6] = {0};

    DebugMessageQC("5. 4P I Dither Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    DebugMessageQC("5. Mode_0", 0x00);
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_10_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00, _BIT5);


    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_8_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE2, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, 0x00, _BIT5);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x4000, 0x00, _BIT5);
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0xC000, 0x00, _BIT5);

    ScalerTimerWaitForEvent(_EVENT_IEN_START);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA, 0x00, _BIT7 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0x4000, 0x00, _BIT0);

    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0x8000, 0x00, _BIT7 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0xC000, 0x00, _BIT0);

    ucData = ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2 | _S1 | _S2, tQC_IDITHER_CRCTable_4P1, 1) << 1);

    DebugMessageQC("5. Mode_1", 0x00);
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_8_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00, _BIT5 | _BIT4 | _BIT3 | _BIT2);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_10_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE2, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, 0x00, _BIT5 | _BIT1 | _BIT0);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x4000, 0x00, _BIT5);
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0xC000, 0x00, _BIT5);
    ScalerSetByte(0x3600, 0x4f);

    ScalerQCWaitForIDDomainEvent(_EVENT_IEN_START, _INPUT_PATH_ALL);

    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA, 0x00, _BIT3 | _BIT2 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0x4000, 0x00, _BIT7 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0x8000, 0x00, _BIT6 | _BIT5 | _BIT4 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0xC000, 0x00, _BIT7 | _BIT0);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0x8000, ~(_BIT0), _BIT0);

    ucData = ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2 | _S1 | _S2, tQC_IDITHER_CRCTable_4P, 12) << 0);

    ScalerSetByte(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00);
    ScalerSetByte(P40_89_I_DITHER_COMMON_CTRL1_M2, 0x00);
    ScalerSetByte(P80_89_I_DITHER_COMMON_CTRL1_SETB, 0x00);
    ScalerSetByte(PC0_89_I_DITHER_COMMON_CTRL1_S2, 0x00);

    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. 4PI Dither End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. 4P I Dither PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. 4P I Dither FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Scale Down Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQC4PScaleDownTest(void)
{
    BYTE ucData = 0;

    BYTE ucTemp[4] = {0};

    DebugMessageQC("5.4P Scale down Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ucTemp[0] = ScalerGetByte(P0_19_M1_IPV_ACT_STA_L);
    ucTemp[1] = ScalerGetByte(P40_19_M2_IPV_ACT_STA_L);

    // increase frontporch
    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ucTemp[0] - 1);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, ucTemp[1] - 1);
    }

    ucTemp[2] = ScalerGetByte(P80_19_S1_IPV_ACT_STA_L);
    ucTemp[3] = ScalerGetByte(PC0_19_S2_IPV_ACT_STA_L);

    // increase frontporch
    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P80_19_S1_IPV_ACT_STA_L, ucTemp[2] - 1);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(PC0_19_S2_IPV_ACT_STA_L, ucTemp[3] - 1);
    }

    ScalerQCSetScalingDownCoef();

    // M1 HSD InitialPhase + Factor
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_04_H_SD_INIT_M1,     0x02);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_43_H_SD_INIT_M_M1,   0x22);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_44_H_SD_INIT_L_M_M1, 0x20);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_05_H_SD_FACTOR_H_M1, 0x11);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_06_H_SD_FACTOR_M_M1, 0x11);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_07_H_SD_FACTOR_L_M1, 0x11);

    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_04_H_SD_INIT_M2,     0x02);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_43_H_SD_INIT_M_M2,   0x22);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_44_H_SD_INIT_L_M2,   0x20);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_05_H_SD_FACTOR_H_M2, 0x11);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_06_H_SD_FACTOR_M_M2, 0x11);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_07_H_SD_FACTOR_L_M2, 0x11);

    // S1 HSD InitialPhase + Factor
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_04_H_SD_INIT_S1,     0x02);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_43_H_SD_INIT_M_S1,   0x22);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_44_H_SD_INIT_L_S1,   0x20);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_05_H_SD_FACTOR_H_S1, 0x11);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_06_H_SD_FACTOR_M_S1, 0x11);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_07_H_SD_FACTOR_L_S1, 0x11);

    // S2
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_04_H_SD_INIT_S2,     0x02);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_43_H_SD_INIT_M_S2,   0x22);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_44_H_SD_INIT_L_S2,   0x20);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_05_H_SD_FACTOR_H_S2, 0x11);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_06_H_SD_FACTOR_M_S2, 0x11);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_07_H_SD_FACTOR_L_S2, 0x11);

    // M1  VSD InitialPhase + Factor
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_00_V_SD_INIT_M1,      0x20);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_40_V_SD_INIT_M_M1,    0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_41_V_SD_INIT_L_M1,    0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_01_V_SD_FACTOR_H_M1,  0x04);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_02_V_SD_FACTOR_M_M1,  0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_03_V_SD_FACTOR_L_M1,  0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_42_V_SD_FACTOR_L1_M1, 0x00);
    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_00_V_SD_INIT_M2,      0x20);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_40_V_SD_INIT_M_M2,    0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_41_V_SD_INIT_L_M2,    0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_01_V_SD_FACTOR_H_M2,  0x04);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_02_V_SD_FACTOR_M_M2,  0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_03_V_SD_FACTOR_L_M2,  0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_42_V_SD_FACTOR_L1_M2, 0x00);

    // S1  VSD InitialPhase + Factor
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_00_V_SD_INIT_S1,      0x20);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_40_V_SD_INIT_M_S1,    0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_41_V_SD_INIT_L_S1,    0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_01_V_SD_FACTOR_H_S1,  0x04);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_02_V_SD_FACTOR_M_S1,  0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_03_V_SD_FACTOR_L_S1,  0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_42_V_SD_FACTOR_L1_S1, 0x00);
    // S2
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_00_V_SD_INIT_S2,      0x20);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_40_V_SD_INIT_M_S2,    0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_41_V_SD_INIT_L_S2,    0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_01_V_SD_FACTOR_H_S2,  0x04);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_02_V_SD_FACTOR_M_S2,  0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_03_V_SD_FACTOR_L_S2,  0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_42_V_SD_FACTOR_L1_S2, 0x00);

    //Enable SD Out Window Set
    // M1
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_36_SD_OUT_WID_M_M1, 0x07);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_37_SD_OUT_WID_L_M1, 0x80);

    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_38_SD_OUT_LEN_M_M1, 0x04);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_39_SD_OUT_LEN_L_M1, 0x38);

    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT3, 0x00);

    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_36_SD_OUT_WID_M_M2, 0x07);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_37_SD_OUT_WID_L_M2, 0x80);

    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_38_SD_OUT_LEN_M_M2, 0x04);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_39_SD_OUT_LEN_L_M2, 0x38);

    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT3, 0x00);

    //Enable SD Out Window Set
    // S1
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_36_SD_OUT_WID_M_S1, 0x07);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_37_SD_OUT_WID_L_S1, 0x80);

    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_38_SD_OUT_LEN_M_S1, 0x04);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_39_SD_OUT_LEN_L_S1, 0x38);

    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~_BIT3, 0x00);

    // S2
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_36_SD_OUT_WID_M_S2, 0x07);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_37_SD_OUT_WID_L_S2, 0x80);

    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_38_SD_OUT_LEN_M_S2, 0x04);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_39_SD_OUT_LEN_L_S2, 0x38);

    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~_BIT3, 0x00);

    // Enable H Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~(_BIT3 | _BIT1), _BIT1);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~(_BIT3 | _BIT1), _BIT1);

    // Enable V Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT0, _BIT0);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT0, _BIT0);

    // Enable H Scale Down
    // S1
    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~(_BIT3 | _BIT1), _BIT1);
    // S2
    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~(_BIT3 | _BIT1), _BIT1);

    // Enable V Scale Down
    // S1
    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~_BIT0, _BIT0);
    // S2
    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~_BIT0, _BIT0);

    DebugMessageQC("5. Mode_0", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_SD, _M1 | _M2 | _S1 | _S2, tScaleDownTest0_4P_ICRCTable, 1) << 0);


    // LSB2bits is tied to 'b00
    // M1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, _BIT0);
    // M2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~_BIT0, _BIT0);
    // LSB2bits is tied to 'b00
    // S1
    ScalerSetBit(P80_26_SD_FILTER_CONTROL_REG_S1, ~_BIT0, _BIT0);
    // S2
    ScalerSetBit(PC0_26_SD_FILTER_CONTROL_REG_S2, ~_BIT0, _BIT0);

    DebugMessageQC("5. Mode_1", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_SD, _M1 | _M2 | _S1 | _S2, tScaleDownTest1_4P_ICRCTable, 1) << 1);

    // M1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, 0x00);
    // M2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~_BIT0, 0x00);
    // S1
    ScalerSetBit(P80_26_SD_FILTER_CONTROL_REG_S1, ~_BIT0, 0x00);
    // S2
    ScalerSetBit(PC0_26_SD_FILTER_CONTROL_REG_S2, ~_BIT0, 0x00);

    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ucTemp[0]);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, ucTemp[1]);
    }

    // increase frontporch
    if(ucTemp[2] > 1)
    {
        ScalerSetByte(P80_19_S1_IPV_ACT_STA_L, ucTemp[2]);
    }
    if(ucTemp[3] > 1)
    {
        ScalerSetByte(PC0_19_S2_IPV_ACT_STA_L, ucTemp[3]);
    }

    ScalerQCIDomainRandomGenOff();

     // Disable V Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT0, 0x00);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT0, 0x00);

    // S1
    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~_BIT0, 0x00);
    // S2
    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~_BIT0, 0x00);


    DebugMessageQC("5.4P Scale down End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6.4P Scale down PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", 0x01);
        DebugMessageQC("6.4P Scale down FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : LSR Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC4PLSRTest(void)
{
    BYTE ucData = 0;
    BYTE temp[9]=0;
    BYTE ucTemp = 0;


    DebugMessageQC("5. 4P LSR Start", 0x00);

    ucData = 0;

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1);

    DebugMessageQC("4P M domain CRC Test!",1);

    for(ucTemp=0; ucTemp < 3 ; ucTemp++)
    {
        if(ScalerQCCRCCompare_IM(_M_DOMAIN_CRC, _M_CRC_AFTER_FIFO, _M1 | _M2, tMDomain_4P_Table, 1))
        {
            DebugMessageQC("4P M domain CRC fail!",ucTemp);
        }
    }

    DebugMessageQC("5. SU Mode_0 check", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tScaleUpTest0_4P_DCRCTable, 1) << 0);

    ScalerBurstWrite(tQC_2P_4P_LSR_SETTING, 360, GET_CURRENT_BANK_NUMBER(), P12_A0_SR_SHP_CTRL_0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(tQC_2P_4P_LSR_HLW, 60, GET_CURRENT_BANK_NUMBER(), P11_CC_LSR_HLW_H_START_HIGH, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);


    //0.LSR
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0x00); //0xxx
    ScalerSetByte(P51_B9_SCALER_LSR_HLW_M2, 0x00);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0x00);
    ScalerSetByte(PD1_B9_SCALER_LSR_HLW_S2, 0x00);
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_4P_Table0, 1) << 0);

    //1.LSR + HLW inA outPass
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0x80); //0x80
    ScalerSetByte(P51_B9_SCALER_LSR_HLW_M2, 0x80);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0x80);
    ScalerSetByte(PD1_B9_SCALER_LSR_HLW_S2, 0x80);
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_4P_Table1, 1) << 1);

    //2.LSR + HLW inPass outA
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0xC0); //0xC0
    ScalerSetByte(P51_B9_SCALER_LSR_HLW_M2, 0xC0);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0xC0);
    ScalerSetByte(PD1_B9_SCALER_LSR_HLW_S2, 0xC0);
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_4P_Table2, 1) << 2);

    //disable LSR
    ScalerSetByte(P14_C0_LSR_CTRL,    0x00);
    ScalerSetByte(P54_C0_LSR_CTRL_M2, 0x00);
    ScalerSetByte(P94_C0_LSR_CTRL_S1, 0x00);
    ScalerSetByte(PD4_C0_LSR_CTRL_S2, 0x00);

    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. 4P LSR End", 0x00);

    if(ucData == _TEST_PASS)
    {
        DebugMessageQC("6.====4P LSR PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====4P LSR Fail====", 0x00);
        return _TEST_FAIL;
    }

}

//--------------------------------------------------
// Description  : ScaleUp Test
// Input Value  : None
// Output Value : TEST_PASS/TEST_FAIL
//--------------------------------------------------
bit ScalerQC4PScaleUpTest(void)
{
    BYTE ucData = 0;
    BYTE ucTemp = 0;


    DebugMessageQC("5. 4P Scale Up Start", 0x00);

    ucData = 0;

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1);

    DebugMessageQC("4P M domain CRC Test!",1);

    for(ucTemp=0; ucTemp < 3 ; ucTemp++)
    {
        if(ScalerQCCRCCompare_IM(_M_DOMAIN_CRC, _M_CRC_AFTER_FIFO, _M1 | _M2, tMDomain_4P_Table, 1))
        {
            DebugMessageQC("4P M domain CRC fail!",ucTemp);
        }
    }

    // 2D 4Line VSU
    // M1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF0, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF1, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT4);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_16_VER_FILTER_COEF_INI_M, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_17_VER_FILTER_COEF_INI_L, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x0F);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0x2B);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0x9D);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_10_HOR_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_14_HOR_FILTER_COEF_INI_M, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_15_HOR_FILTER_COEF_INI_L, 0x00);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x0A);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0xAA);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0xAA);

    // Enable V Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT1, _BIT1);
    // Enable H Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG, ~_BIT0, _BIT0);

    // M2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x4000, ~(_BIT5 | _BIT4), _BIT4);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x0F);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0x2B);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0x9D);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_10_HOR_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x0A);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0xAA);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x4000, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0xAA);

    // Enable V Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + 0x4000, ~_BIT1, _BIT1);
    // Enable H Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + 0x4000, ~_BIT0, _BIT0);

    // S1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF0, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF1, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT5 | _BIT4), _BIT4);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x0F);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0x2B);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0x9D);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_10_HOR_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x0A);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0xAA);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0x8000, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0xAA);

    // Enable V Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + 0x8000, ~_BIT1, _BIT1);
    // Enable H Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + 0x8000, ~_BIT0, _BIT0);

    // S2
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0xC000, ~(_BIT5 | _BIT4), _BIT4);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_11_VER_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_03_VER_SCALE_FACTOR_H, 0x0F);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_04_VER_SCALE_FACTOR_M, 0x2B);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_05_VER_SCALE_FACTOR_L, 0x9D);

    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_10_HOR_FILTER_COEF_INI, 0xC4);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_00_HOR_SCALE_FACTOR_H, 0x0A);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_01_HOR_SCALE_FACTOR_M, 0xAA);
    ScalerSetDataPortByte(P0_33_SF_ADDR_PORT + 0xC000, _P0_34_PT_02_HOR_SCALE_FACTOR_L, 0xAA);

    // Enable V Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + 0xC000, ~_BIT1, _BIT1);
    // Enable H Scale Up
    ScalerSetBit(P0_32_SCALE_CONTROL_REG + 0xC000, ~_BIT0, _BIT0);

    DebugMessageQC("5. Mode_0", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tScaleUpTest0_4P_DCRCTable, 1) << 0);

    // Hcoef sel = 2nd, Vcoef sel = 1st
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT5);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x4000, ~(_BIT5 | _BIT4), _BIT5);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT5 | _BIT4), _BIT5);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0xC000, ~(_BIT5 | _BIT4), _BIT5);

    DebugMessageQC("5. Mode_1", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tScaleUpTest1_4P_DCRCTable, 1) << 1);

    // fix H coef, fix V coef
    ScalerSetBit(P0_35_FILTER_CONTROL_REG, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x4000, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0x4000, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0x8000, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0xC000, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0xC000, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    DebugMessageQC("5. Mode_2", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tScaleUpTest2_4P_DCRCTable, 1) << 2);

    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0x4000, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0x8000, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0xC000, ~(_BIT5 | _BIT4), 0x00);

    // M2 coef Sel ref to S1
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF1, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF0, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0x4000, ~_BIT0, 0x00);

    DebugMessageQC("5. Mode_3", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tScaleUpTest3_4P_DCRCTable, 1) << 3);

    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_SU_COEF0, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_35_FILTER_CONTROL_REG + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_SU_COEF1, _SU_TABLE_SIZE, GET_CURRENT_BANK_NUMBER(), P0_36_USER_DEF_FILTER_ACCESS_PORT + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_37_SCALE_UP_FOR_LINE_INTERLEAVE + 0x4000, ~_BIT0, _BIT0);

    ScalerQCIDomainRandomGenOff();


    DebugMessageQC("5.4P Scale Up End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6.4P Scale Up PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6.4P Scale Up FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : FC TEST: Main/Sub E/O
// Input Value  : None
// return Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC2PFormatConversionTest(void)
{
    BYTE ucData = 0;
    BYTE ucIVS = 0;
    BYTE ucTemp[14];

    DebugMessageQC("5. Format Conversion 2P Test Start", 0x00);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);

    ScalerRead(P31_00_FC_INPUT_SEL_P01, 14, ucTemp, _AUTOINC);

    ScalerBurstWrite(tFC_TEST0, sizeof(tFC_TEST0), GET_CURRENT_BANK_NUMBER(), 0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerTimerDelayXms(20);
    ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ScalerGetByte(P0_19_M1_IPV_ACT_STA_L)/2);

    ucIVS = ScalerGetByte(P0_19_M1_IPV_ACT_STA_L) + ScalerGetByte(P0_1C_M1_IVS_DELAY);

    if((ucIVS % 2) == 1)
    {
        ScalerSetByte(P31_06_FC_EO_LINE_CTRL, 0xCC);
    }

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);
    // Even/Odd, 4096x2160, 256 Gray Level
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, tFC_CRC_2P, 1) << 0);

    ScalerSetByte(0x3100, ucTemp[0]);
    ScalerSetByte(0x3101, ucTemp[1]);
    ScalerSetByte(0x3102, ucTemp[2]);
    ScalerSetByte(0x3103, ucTemp[3]);
    ScalerSetByte(0x3104, ucTemp[4]);
    ScalerSetByte(0x3105, ucTemp[5]);
    ScalerSetByte(0x3106, ucTemp[6]);
    ScalerSetByte(0x3107, ucTemp[7]);
    ScalerSetByte(0x3108, ucTemp[8]);
    ScalerSetByte(0x3109, ucTemp[9]);
    ScalerSetByte(0x310A, ucTemp[10]);
    ScalerSetByte(0x310C, ucTemp[12]);
    ScalerSetByte(0x310D, ucTemp[13]);

    DebugMessageQC("5. Format Conversion 2P Test End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. Format Conversion 2P PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. Format Conversion 2P FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Test 4P I-Domain Random Generator
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQC2PIPGTest(void)
{
    BYTE ucFlag = 0;
    DebugMessageQC("5. 2P IPG Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);
    ucFlag = (ucFlag | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, tIPG_CRC_TABLE, 1) << 0));
    //ucFlag = (ucFlag | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _S1 | _S2, tIPG_CRC_TABLE, 1) << 1));
    ScalerQCIDomainRandomGenOn(_GRAY);
    ucFlag = (ucFlag | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _M1|_M2|_S1|_S2, tIPG_CRC_TABLE1, 1) << 1));
    //ucFlag = (ucFlag | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_VGIP, _S1 | _S2, tIPG_CRC_TABLE1, 1) << 3));

    DebugMessageQC("5. 2P IPG End", 0x00);

    ScalerQCIDomainRandomGenOff();

    if(ucFlag == _TEST_PASS)
    {
        DebugMessageQC("6.====2P IPG PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====2P IPG Fail====", ucFlag);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : 2P I-Domain Color Conversion Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC2PIDomainColorConvTest(void)
{
    BYTE ucResult = _TEST_PASS;

    DebugMessageQC("5. 2P I-Domain Color Conversion Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);
    ScalerTimerDelayXms(50);

    // Enable YUV2RGB coefficient access
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), P0_9D_RGB2YCC_COEF_DATA, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT3, 0x00);

    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, ~_BIT3, _BIT3);
    ScalerBurstWrite(tQC_CONV_RGB2YUV_ITU709, sizeof(tQC_CONV_RGB2YUV_ITU709), GET_CURRENT_BANK_NUMBER(), P80_9D_RGB2YCC_COEF_DATA_S1, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, ~_BIT3, 0x00);

    //////////////////////////////////////////////////////////////////
    // case 0: RGB->YUV, enable y out shift, enable CbCr out shift + 2048, Output_sel
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, 0x00, _BIT7 | _BIT6 | _BIT4 | _BIT0);  // 0xD1
    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, 0x00, _BIT7 | _BIT6 | _BIT0);  // 0xC1

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);

    DebugMessageQC("5. 2P Color Conv case", 0x00);
    ucResult = ucResult | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, (_M1 | _M2 | _S1 | _S2), tICOLORCONV_2P_CRC_TABLE, 1));

    ScalerQCIDomainRandomGenOff();

    // Disable YUV2RGB conversion
    ScalerSetBit(P0_9C_RGB2YCC_CTRL, ~_BIT0, 0x00);
    ScalerSetBit(P80_9C_RGB2YCC_CTRL_S1, ~_BIT0, 0x00);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_ALL);

    DebugMessageQC("5. 2P I-Domain Color Conversion End", 0x00);

    if(ucResult == 0)
    {
        DebugMessageQC("6. 2P I-Domain Color Conversion PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. 2P Fail Mode", ucResult);
        DebugMessageQC("6. 2P I-Domain Color Conversion FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : IDLTI Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC2PIDLTITest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. 2P IDLTI Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerBurstWrite(&tQC_IDLTI_SETTING_2P[0], 18, GET_CURRENT_BANK_NUMBER(), P11_A1_I_DLTI_CTRL_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI Table
    ScalerBurstWrite(&tQC_IDLTI_SETTING_2P[18], 18, GET_CURRENT_BANK_NUMBER(), P51_A1_I_DLTI_CTRL_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);      // IDLTI Table
    ScalerBurstWrite(&tQC_IDLTI_SETTING_2P[36], 18, GET_CURRENT_BANK_NUMBER(), P91_A1_I_DLTI_CTRL_S1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);      // IDLTI Table
    ScalerBurstWrite(&tQC_IDLTI_SETTING_2P[54], 18, GET_CURRENT_BANK_NUMBER(), PD1_A1_I_DLTI_CTRL_S2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);      // IDLTI Table
    ScalerBurstWrite(tQC_IDLTI_HLW, 8, GET_CURRENT_BANK_NUMBER(), P11_D4_I_DLTI_HLW_HOR_START_HSB_M1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table
    ScalerBurstWrite(tQC_IDLTI_HLW, 8, GET_CURRENT_BANK_NUMBER(), P51_D4_I_DLTI_HLW_HOR_START_HSB_M2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table
    ScalerBurstWrite(tQC_IDLTI_HLW, 8, GET_CURRENT_BANK_NUMBER(), P91_D4_I_DLTI_HLW_HOR_START_HSB_S1, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table
    ScalerBurstWrite(tQC_IDLTI_HLW, 8, GET_CURRENT_BANK_NUMBER(), PD1_D4_I_DLTI_HLW_HOR_START_HSB_S2, _BURSTWRITE_DATA_COMMON_AUTO_INC, _BURSTWRITE_FROM_FLASH);       // IDLTI HLW Table

    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x00);     // Disable HLW
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x00);     // Disable HLW
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x00);     // Disable HLW
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x00);     // Disable HLW

    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_ALL);
    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_ALL);

    // Case 0 : IDomainRandomGen(_MASS) + Setting1 + I_Domain_CRC
    DebugMessageQC("5. 2P_Mode_0", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_2P_1, 1) << 0));

    // Case 1 : IDomainRandomGen(_MASS) + Setting2 + I_Domain_CRC + HLW(Main : Inside A, Outside B / Sub : Inside D, Outside C)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x0A);     // Enable HLW(Inside A, Outside B)
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x0A);     // Enable HLW(Inside A, Outside B)
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x0B);     // Enable HLW(Inside D, Outside C)
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x0B);     // Enable HLW(Inside D, Outside C)
    DebugMessageQC("5. 2P_Mode_1", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_2P_2, 1) << 1));

    // Case 2 : IDomainRandomGen(_MASS) + Setting3 + I_Domain_CRC + HLW(Main : Inside A, Outside Bypass / Sub : Inside Bypass, Outside D)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x02);     // Enable HLW(Inside A, Outside Bypass)
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x02);     // Enable HLW(Inside A, Outside Bypass)
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x07);     // Enable HLW(Inside Bypass, Outside D)
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x07);     // Enable HLW(Inside Bypass, Outside D)
    DebugMessageQC("5. 2P_Mode_2", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_2P_3, 1) << 2));

    // Case 3 : IDomainRandomGen(_MASS) + Setting4 + I_Domain_CRC + HLW(Main : Inside A, Outside A / Sub : Inside D, Outside D)
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x0E);     // Enable HLW(Inside A, Outside A)
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x0E);     // Enable HLW(Inside A, Outside A)
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x0F);     // Enable HLW(Inside D, Outside D)
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x0F);     // Enable HLW(Inside D, Outside D)
    DebugMessageQC("5. 2P_Mode_3", 0x00);
    ucData = (ucData | ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1|_M2|_S1|_S2, tQC_IDLTI_CRCTable_2P_4, 1) << 3));

    ScalerSetByte(P11_A1_I_DLTI_CTRL_M1, 0x00);         // Disable IDLTI
    ScalerSetByte(P51_A1_I_DLTI_CTRL_M2, 0x00);         // Disable IDLTI
    ScalerSetByte(P91_A1_I_DLTI_CTRL_S1, 0x00);         // Disable IDLTI
    ScalerSetByte(PD1_A1_I_DLTI_CTRL_S2, 0x00);         // Disable IDLTI
    ScalerSetByte(P11_DC_I_DLTI_HLW_CTRL_M1, 0x00);     // Disable HLW
    ScalerSetByte(P51_DC_I_DLTI_HLW_CTRL_M2, 0x00);     // Disable HLW
    ScalerSetByte(P91_DC_I_DLTI_HLW_CTRL_S1, 0x00);     // Disable HLW
    ScalerSetByte(PD1_DC_I_DLTI_HLW_CTRL_S2, 0x00);     // Disable HLW
    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. 2P IDLTI End", 0x00);

    if(ucData == 0x00)
    {
        DebugMessageQC("6. 2P IDLTI PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. 2P Fail Mode", ucData);
        DebugMessageQC("6. 2P IDLTI FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : I Domain Dither Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQC2PIDitherTest(void)
{
    BYTE ucData = 0;

    DebugMessageQC("5. 2P I Dither Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    // 8 bit dither test
    DebugMessageQC("5. Mode_0", 0x00);
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_8_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE2, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00, _BIT5 | _BIT3);

    // 10 bit dither test
    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), _BIT7);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_12_10_TABLE, 24, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), _BIT6);
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_SEQ_TABLE, 96, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
    ScalerBurstWrite(tQC_I_DOMAIN_DITHER_TEMOFFSET, 4, GET_CURRENT_BANK_NUMBER(), P0_88_I_DITHER_DATA_ACCESS_SETA + 0x8000, _BURSTWRITE_DATA_COMMON, _BURSTWRITE_FROM_FLASH);

    ScalerSetBit(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, 0x00, _BIT5 | _BIT4 | _BIT1 | _BIT0);

    ScalerQCWaitForIDDomainEvent(_EVENT_IEN_START, _INPUT_PATH_ALL);
    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA + 0x8000, 0x00, _BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT0);

    ScalerSetBit(P0_8A_I_DITHER_COMMON_CTRL2_SETA, 0x00, _BIT0);
    ScalerQCWaitForIDDomainEvent(_EVENT_IEN_START, _INPUT_PATH_ALL);
    ucData = ((BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_IDITHER, _M1 | _M2 | _S1 | _S2, tQC_IDITHER_CRCTable_2P, 1) << 0);

    ScalerSetByte(P0_89_I_DITHER_COMMON_CTRL1_SETA, 0x00);
    ScalerSetByte(P0_89_I_DITHER_COMMON_CTRL1_SETA + 0x8000, 0x00);
    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. 2P I Dither End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6. 2P I Dither PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", ucData);
        DebugMessageQC("6. 2P I Dither FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : Scale Down Test
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerQC2PScaleDownTest(void)
{
    BYTE ucData = 0;

    BYTE ucTemp[4] = {0};

    DebugMessageQC("5.2P Scale down Start", 0x00);

    ScalerQCIDomainRandomGenOn(_MASS);

    ucTemp[0] = ScalerGetByte(P0_19_M1_IPV_ACT_STA_L);
    ucTemp[1] = ScalerGetByte(P40_19_M2_IPV_ACT_STA_L);

    // increase frontporch
    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ucTemp[0] - 1);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, ucTemp[1] - 1);
    }

    ucTemp[2] = ScalerGetByte(P80_19_S1_IPV_ACT_STA_L);
    ucTemp[3] = ScalerGetByte(PC0_19_S2_IPV_ACT_STA_L);

    // increase frontporch
    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P80_19_S1_IPV_ACT_STA_L, ucTemp[2] - 1);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(PC0_19_S2_IPV_ACT_STA_L, ucTemp[3] - 1);
    }

    ScalerQCSetScalingDownCoef();

    // M1 HSD InitialPhase + Factor
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_04_H_SD_INIT_M1,     0x24);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_43_H_SD_INIT_M_M1,   0x44);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_44_H_SD_INIT_L_M_M1, 0x44);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_05_H_SD_FACTOR_H_M1, 0x22);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_06_H_SD_FACTOR_M_M1, 0x22);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_07_H_SD_FACTOR_L_M1, 0x22);

    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_04_H_SD_INIT_M2,     0x24);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_43_H_SD_INIT_M_M2,   0x44);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_44_H_SD_INIT_L_M2,   0x44);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_05_H_SD_FACTOR_H_M2, 0x22);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_06_H_SD_FACTOR_M_M2, 0x22);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_07_H_SD_FACTOR_L_M2, 0x22);

    // S1 HSD InitialPhase + Factor
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_04_H_SD_INIT_S1,     0x24);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_43_H_SD_INIT_M_S1,   0x44);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_44_H_SD_INIT_L_S1,   0x44);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_05_H_SD_FACTOR_H_S1, 0x22);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_06_H_SD_FACTOR_M_S1, 0x22);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_07_H_SD_FACTOR_L_S1, 0x22);

    // S2
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_04_H_SD_INIT_S2,     0x24);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_43_H_SD_INIT_M_S2,   0x44);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_44_H_SD_INIT_L_S2,   0x44);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_05_H_SD_FACTOR_H_S2, 0x22);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_06_H_SD_FACTOR_M_S2, 0x22);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_07_H_SD_FACTOR_L_S2, 0x22);

    // M1  VSD InitialPhase + Factor
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_00_V_SD_INIT_M1,      0x20);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_40_V_SD_INIT_M_M1,    0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_41_V_SD_INIT_L_M1,    0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_01_V_SD_FACTOR_H_M1,  0x04);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_02_V_SD_FACTOR_M_M1,  0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_03_V_SD_FACTOR_L_M1,  0x00);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_42_V_SD_FACTOR_L1_M1, 0x00);
    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_00_V_SD_INIT_M2,      0x20);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_40_V_SD_INIT_M_M2,    0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_41_V_SD_INIT_L_M2,    0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_01_V_SD_FACTOR_H_M2,  0x04);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_02_V_SD_FACTOR_M_M2,  0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_03_V_SD_FACTOR_L_M2,  0x00);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_42_V_SD_FACTOR_L1_M2, 0x00);

    // S1  VSD InitialPhase + Factor
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_00_V_SD_INIT_S1,      0x20);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_40_V_SD_INIT_M_S1,    0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_41_V_SD_INIT_L_S1,    0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_01_V_SD_FACTOR_H_S1,  0x04);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_02_V_SD_FACTOR_M_S1,  0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_03_V_SD_FACTOR_L_S1,  0x00);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_42_V_SD_FACTOR_L1_S1, 0x00);
    // S2
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_00_V_SD_INIT_S2,      0x20);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_40_V_SD_INIT_M_S2,    0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_41_V_SD_INIT_L_S2,    0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_01_V_SD_FACTOR_H_S2,  0x04);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_02_V_SD_FACTOR_M_S2,  0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_03_V_SD_FACTOR_L_S2,  0x00);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_42_V_SD_FACTOR_L1_S2, 0x00);

    //Enable SD Out Window Set
    // M1
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_36_SD_OUT_WID_M_M1, 0x07);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_37_SD_OUT_WID_L_M1, 0x80);

    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_38_SD_OUT_LEN_M_M1, 0x02);
    ScalerSetDataPortByte(P0_24_SD_ADDRESS_PORT_M1, _P0_25_PT_39_SD_OUT_LEN_L_M1, 0x1C);

    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT3, 0x00);

    // M2
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_36_SD_OUT_WID_M_M2, 0x07);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_37_SD_OUT_WID_L_M2, 0x80);

    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_38_SD_OUT_LEN_M_M2, 0x02);
    ScalerSetDataPortByte(P40_24_SD_ADDRESS_PORT_M2, _P40_25_PT_39_SD_OUT_LEN_L_M2, 0x1C);

    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT3, 0x00);

    //Enable SD Out Window Set
    // S1
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_36_SD_OUT_WID_M_S1, 0x07);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_37_SD_OUT_WID_L_S1, 0x80);

    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_38_SD_OUT_LEN_M_S1, 0x02);
    ScalerSetDataPortByte(P80_24_SD_ADDRESS_PORT_S1, _P80_25_PT_39_SD_OUT_LEN_L_S1, 0x1C);

    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~_BIT3, 0x00);

    // S2
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_36_SD_OUT_WID_M_S2, 0x07);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_37_SD_OUT_WID_L_S2, 0x80);

    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_38_SD_OUT_LEN_M_S2, 0x02);
    ScalerSetDataPortByte(PC0_24_SD_ADDRESS_PORT_S2, _PC0_25_PT_39_SD_OUT_LEN_L_S2, 0x1C);

    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~_BIT3, 0x00);

    // Enable H Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~(_BIT3 | _BIT1), _BIT1);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~(_BIT3 | _BIT1), _BIT1);

    // Enable V Scale Down
    // M1
    ScalerSetBit(P0_23_SCALE_DOWN_CTRL_M1, ~_BIT0, _BIT0);
    // M2
    ScalerSetBit(P40_23_SCALE_DOWN_CTRL_M2, ~_BIT0, _BIT0);

    // Enable H Scale Down
    // S1
    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~(_BIT3 | _BIT1), _BIT1);
    // S2
    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~(_BIT3 | _BIT1), _BIT1);

    // Enable V Scale Down
    // S1
    ScalerSetBit(P80_23_SCALE_DOWN_CTRL_S1, ~_BIT0, _BIT0);
    // S2
    ScalerSetBit(PC0_23_SCALE_DOWN_CTRL_S2, ~_BIT0, _BIT0);

    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_ALL);
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_SD, _M1 | _M2 | _S1 | _S2, tScaleDownTest0_2P_ICRCTable, 1) << 0);

    // LSB2bits is tied to 'b00
    // M1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, _BIT0);
    // M2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~_BIT0, _BIT0);
    // LSB2bits is tied to 'b00
    // S1
    ScalerSetBit(P80_26_SD_FILTER_CONTROL_REG_S1, ~_BIT0, _BIT0);
    // S2
    ScalerSetBit(PC0_26_SD_FILTER_CONTROL_REG_S2, ~_BIT0, _BIT0);

    ScalerQCWaitForIDDomainEvent(_EVENT_DVS, _INPUT_PATH_ALL);
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = (ucData | (BYTE)ScalerQCCRCCompare_IM(_I_DOMAIN_CRC, _I_CRC_AFTER_SD, _M1 | _M2 | _S1 | _S2, tScaleDownTest1_2P_ICRCTable, 1) << 1);

    // M1
    ScalerSetBit(P0_26_SD_FILTER_CONTROL_REG_M1, ~_BIT0, 0x00);
    // M2
    ScalerSetBit(P40_26_SD_FILTER_CONTROL_REG_M2, ~_BIT0, 0x00);
    // S1
    ScalerSetBit(P80_26_SD_FILTER_CONTROL_REG_S1, ~_BIT0, 0x00);
    // S2
    ScalerSetBit(PC0_26_SD_FILTER_CONTROL_REG_S2, ~_BIT0, 0x00);

    if(ucTemp[0] > 1)
    {
        ScalerSetByte(P0_19_M1_IPV_ACT_STA_L, ucTemp[0]);
    }
    if(ucTemp[1] > 1)
    {
        ScalerSetByte(P40_19_M2_IPV_ACT_STA_L, ucTemp[1]);
    }

    // increase frontporch
    if(ucTemp[2] > 1)
    {
        ScalerSetByte(P80_19_S1_IPV_ACT_STA_L, ucTemp[2]);
    }
    if(ucTemp[3] > 1)
    {
        ScalerSetByte(PC0_19_S2_IPV_ACT_STA_L, ucTemp[3]);
    }

    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5.2P Scale down End", 0x00);
    if(ucData == 0x00)
    {
        DebugMessageQC("6.2P Scale down PASS", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6. Fail Mode", 0x01);
        DebugMessageQC("6.2P Scale down FAIL", 0x00);
        return _TEST_FAIL;
    }
}

//--------------------------------------------------
// Description  : LSR Test
// Input Value  : None
// Output Value : _TEST_PASS or _TEST_FAIL
//--------------------------------------------------
bit ScalerQC2PLSRTest(void)
{
    BYTE ucData = 0;
    BYTE temp[9]=0;
    BYTE ucTemp = 0;


    DebugMessageQC("5. 2P LSR Start", 0x00);

    ucData = 0;

    ScalerQCIDomainRandomGenOn(_MASS);

    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1);
    ScalerQCWaitForIDDomainEvent(_EVENT_IVS, _INPUT_PATH_M1);

    DebugMessageQC("2P M domain CRC Test!",1);

    for(ucTemp=0; ucTemp < 3 ; ucTemp++)
    {
        if(ScalerQCCRCCompare_IM(_M_DOMAIN_CRC, _M_CRC_AFTER_FIFO, _M1 | _M2, tMDomain_2P_Table, 1))
        {
            DebugMessageQC("2P M domain CRC fail!",ucTemp);
        }
    }
    DebugMessageQC("2P D domain CRC Test!",1);

    if(ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tDDomain_2P_Table, 1))
    {
        DebugMessageQC("2P D domain CRC fail!",ucTemp);
    }

    ScalerBurstWrite(tQC_2P_4P_LSR_SETTING, 360, GET_CURRENT_BANK_NUMBER(), P12_A0_SR_SHP_CTRL_0, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);
    ScalerBurstWrite(tQC_2P_4P_LSR_HLW, 60, GET_CURRENT_BANK_NUMBER(), P11_CC_LSR_HLW_H_START_HIGH, _BURSTWRITE_COMMAND, _BURSTWRITE_FROM_FLASH);

    //0.LSR HLW off
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0x00);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0x00);
    DebugMessageQC("5. Mode_0", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_2P_Table0, 1) << 0);

    //1.LSR + main(inA outB) sub(inB outA)
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0xA0);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0xE0);
    DebugMessageQC("5. Mode_1", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_2P_Table1, 1) << 1);

    //2.LSR + main(inA outP) sub(inB outP)
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0x80);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0x90);
    DebugMessageQC("5. Mode_2", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_2P_Table2, 1) << 2);

    //3.LSR + main(inA outA) sub(inB outB)
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0xB0);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0xF0);
    DebugMessageQC("5. Mode_3", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_2P_Table3, 1) << 2);

    //4.LSR + main(inP outB) sub(inP outA)
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0xD0);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0xC0);
    DebugMessageQC("5. Mode_4", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_2P_Table4, 1) << 2);

    //5.LSR + main(inB outA) sub(inA outP)
    ScalerSetByte(P11_B9_SCALER_LSR_HLW,    0xE0);
    ScalerSetByte(P91_B9_SCALER_LSR_HLW_S1, 0x80);
    DebugMessageQC("5. Mode_5", 0x00);
    ucData = ucData | ((BYTE)ScalerQCCRCCompare_IM(_D_DOMAIN_CRC, _D_CRC_AFTER_DDITHER, _M1 | _M2 | _S1, tLSR_2P_Table5, 1) << 2);

    //disable LSR
    ScalerSetByte(P14_C0_LSR_CTRL,    0x00);
    ScalerSetByte(P54_C0_LSR_CTRL_M2, 0x00);
    ScalerSetByte(P94_C0_LSR_CTRL_S1, 0x00);
    ScalerSetByte(PD4_C0_LSR_CTRL_S2, 0x00);

    ScalerQCIDomainRandomGenOff();

    DebugMessageQC("5. 2P LSR End", 0x00);

    if(ucData == _TEST_PASS)
    {
        DebugMessageQC("6.====2P LSR PASS====", 0x00);
        return _TEST_PASS;
    }
    else
    {
        DebugMessageQC("6.====2P LSR Fail====", 0x00);
        return _TEST_FAIL;
    }

}
#endif  // End of #if(_QC_4P_MODE_ == _ON)

#endif // End of #if(_FACTORY_RTD_QC_SUPPORT == _ON)
