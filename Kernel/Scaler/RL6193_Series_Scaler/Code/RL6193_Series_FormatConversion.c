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
// ID Code      : RL6193_Series_FormatConversion.c No.0000
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
void ScalerFmtCnvInitialSetting(EnumSourceSearchPort enumSourceSearchPort);

#if(_HDMI_2_0_SUPPORT == _ON)
void ScalerFmtCnv420To422FinalSetting(void);
#endif

void ScalerFmtCnvFinalSetting(void);
EnumFormatConversionSourceType ScalerFmtCnvGetSourceType(void);

void ScalerFmtCnvFtoPControl(bit bEnable);
bit ScalerFmtCnvGetHalfDataPathEvenOddModeStatus(void);

#if(_DIGITAL_PORT_SUPPORT == _ON)
void ScalerFmtCnvSetBackgroundColor(void);
#endif

void ScalerFmtCnvFtoPSetFifo(WORD usHwidth, WORD usVstart);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initialize for format conversion
// Input Value  : enumSourceSearchPort --> input port
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnvInitialSetting(EnumSourceSearchPort enumSourceSearchPort)
{
    switch(enumSourceSearchPort)
    {
        case _A0_INPUT_PORT:

            // Set source index to A0
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_ADC << 4));
            break;

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif
            // Set source index to D0
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D0 << 4));

#if(_D0_HDMI_2_0_SUPPORT == _ON)
            // Disble 420-to-422
            ScalerColor420To422D0Enable(_FUNCTION_OFF);
#endif
            break;

        case _D1_INPUT_PORT:

            // Set source index to D1
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D1 << 4));

#if(_D1_HDMI_2_0_SUPPORT == _ON)
            // Disble 420-to-422
            ScalerColor420To422D1Enable(_FUNCTION_OFF);
#endif
            break;

        case _D2_INPUT_PORT:

            // Set source index to D2
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D2 << 4));
            break;

        case _D3_INPUT_PORT:

            // Set source index to D3
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D3 << 4));
            break;

        case _D4_INPUT_PORT:

            // Set source index to D4
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D4 << 4));
            break;

        case _D5_INPUT_PORT:

            // Set source index to D5
            ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D5 << 4));
            break;

        default:
            break;
    }

    // Duplicate M2 source from M1
    ScalerSetBit(P31_00_FC_INPUT_SEL_P01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((ScalerGetBit(P31_00_FC_INPUT_SEL_P01, (_BIT7 | _BIT6 | _BIT5 | _BIT4))) >> 4));

    // Check input pixel rate
    if(ScalerSyncGetInputPixelClk() > _DATA_PATH_SPEED_LIMIT)
    {
        ScalerFmtCnvHalfSDSetFirstPixel(0);

        // Enable 1/2 scaling down
        ScalerFmtCnvHalfSDControl(_ENABLE);
    }
    else
    {
        // Disable 1/2 scaling down
        ScalerFmtCnvHalfSDControl(_DISABLE);
    }

    // Disable F-to-P
    ScalerFmtCnvFtoPControl(_DISABLE);

    // Enable clock gating for sub
    ScalerSetBit(P31_0D_FC_INPUT_CLK_GATING, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
}

#if(_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Final YCBCR 420 setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnv420To422FinalSetting(void)
{
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)
    {
        if(ScalerFmtCnvGetSourceType() == _FC_SOURCE_D0)
        {
            // Update actual 420-422 state
            if(ScalerFmtCnvHalfSDGetStatus() == _TRUE)
            {
                ScalerColor420To422D0Setting(GET_ACTIVE_H_START() << 1, GET_ACTIVE_H_WIDTH() << 1);
            }
            else
            {
                ScalerColor420To422D0Setting(GET_ACTIVE_H_START(), GET_ACTIVE_H_WIDTH());
            }
            ScalerTimerWaitForEvent(_EVENT_IVS);
            ScalerColor420To422D0Enable(_FUNCTION_ON);
        }
        else if(ScalerFmtCnvGetSourceType() == _FC_SOURCE_D1)
        {
            // Update actual 420-422 state
            if(ScalerFmtCnvHalfSDGetStatus() == _TRUE)
            {
                ScalerColor420To422D1Setting(GET_ACTIVE_H_START() << 1, GET_ACTIVE_H_WIDTH() << 1);
            }
            else
            {
                ScalerColor420To422D1Setting(GET_ACTIVE_H_START(), GET_ACTIVE_H_WIDTH());
            }
            ScalerTimerWaitForEvent(_EVENT_IVS);
            ScalerColor420To422D1Enable(_FUNCTION_ON);
        }
    }
}
#endif

//--------------------------------------------------
// Description  : Final format conversion setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnvFinalSetting(void)
{
#if(_HDMI_2_0_SUPPORT == _ON)
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)
    {
        // Set main F-to-P FIFO
        ScalerFmtCnvFtoPSetFifo((GET_INPUT_TIMING_HWIDTH() << 1), GET_INPUT_TIMING_VSTART());
    }
    else
#endif
    {
        // Set main F-to-P FIFO
        ScalerFmtCnvFtoPSetFifo(GET_INPUT_TIMING_HWIDTH(), GET_INPUT_TIMING_VSTART());
    }

    if(ScalerFmtCnvHalfSDGetStatus() == _TRUE)
    {
        // Disable 1/2 scaling down
        ScalerFmtCnvHalfSDControl(_DISABLE);
    }

    // Enable main F-to-P
    ScalerFmtCnvFtoPControl(_ENABLE);

    if(ScalerFmtCnvGetSourceType() != _FC_SOURCE_ADC)
    {
        // Wait 4 IVS after format conversion setting
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);
        ScalerTimerWaitForEvent(_EVENT_IVS);

        // Clear VGIP Interlace Toggle Flag
        ScalerSetBit(P0_1A_M1_IPV_ACT_LEN_H, ~_BIT5, _BIT5);
    }

    // Enable clock gating for M2
    ScalerSetBit(P31_0D_FC_INPUT_CLK_GATING, ~_BIT1, 0x00);
}

//--------------------------------------------------
// Description  : Show format conversion input source
// Input Value  : NONE
// Output Value : Current format conversino source
//--------------------------------------------------
EnumFormatConversionSourceType ScalerFmtCnvGetSourceType(void)
{
    return (EnumFormatConversionSourceType)(ScalerGetBit(P31_00_FC_INPUT_SEL_P01, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4);
}

//--------------------------------------------------
// Description  : Control for even/odd
// Input Value  : _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnvFtoPControl(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
#if(_VGA_SUPPORT == _ON)
        if(ScalerFmtCnvGetSourceType() != _FC_SOURCE_ADC)
#endif
        {
            // Enable VS delay 8 line to enlarge front porch
            if(GET_ACTIVE_V_START() >= (_VGIP_IV_CAPTURE_MIN_VALUE * 2 + 0x08))
            {
                ScalerSetBit(P31_0B_FC_FPRMAT_PRO_OUTPUT, ~_BIT1, _BIT1);
            }
        }

        // Enable F-to-P
        ScalerSetBit(P31_06_FC_EO_LINE_CTRL, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

        if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
        {
            // Set interlace for E/O mode
            ScalerFmtCnvFtoPInterlaceSetting();
        }
    }
    else
    {
        // Disable VS delay 8 line
        ScalerSetBit(P31_0B_FC_FPRMAT_PRO_OUTPUT, ~(_BIT7 | _BIT6 | _BIT3 | _BIT1), 0x00);

        // Disable F-to-P
        ScalerSetBit(P31_06_FC_EO_LINE_CTRL, ~(_BIT7 | _BIT6), 0x00);
    }
}

//--------------------------------------------------
// Description  : Set format conversion Single Mode & D-domain E/O Mode
// Input Value  : NA
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerFmtCnvGetHalfDataPathEvenOddModeStatus(void)
{
#if(_FORMAT_CONVERSION_FORCE_EO_MODE == _ON)

    // Force E/O mode
    return _FALSE;

#else

    // Check if 1/2 H freq. > measure H freq. min
    if((GET_INPUT_TIMING_HFREQ() >> 1) < _MEASURE_H_FREQ_MIN)
    {
        return _TRUE;
    }

#if(_VGA_SUPPORT == _ON)
    if(ScalerFmtCnvGetSourceType() != _FC_SOURCE_ADC)
#endif
    {
        // Check if H-Width is ODD integer, Select Single Path
        if((GET_INPUT_TIMING_HWIDTH() % 2) != 0x00)
        {
            return _TRUE;
        }
    }

    if(ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE)
    {
#if(_HDMI_2_0_SUPPORT == _ON)
        // E/O mode for 420 format
        if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)
        {
            return _FALSE;
        }
#endif

        // Single mode for I-domain pixel clock under 300M Hz
        return (ScalerSyncGetInputPixelClk() <= _DATA_PATH_SPEED_LIMIT);
    }
    else
    {
        // Check if V height is odd
#if(_VGA_SUPPORT == _ON)
        if(ScalerFmtCnvGetSourceType() != _FC_SOURCE_ADC)
#endif
        {
            if((ScalerSyncGetInputPixelClk() <= _DATA_PATH_SPEED_LIMIT) &&
               ((LOBYTE(GET_INPUT_TIMING_VHEIGHT()) % 2) != 0x00))
            {
                g_stActiveRegion.usVActiveEnd += 1;
                return _TRUE;
            }
        }

        if(GET_INPUT_TIMING_INTERLACE_FLG() == _TRUE)
        {
            return _TRUE;
        }
        else
        {
            return _FALSE;
        }
    }

#endif // End of #if(_FORMAT_CONVERSION_FORCE_EO_MODE == _ON)
}

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set background color for format conversion
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnvSetBackgroundColor(void)
{
    // Capture last line for odd V height (before E/O)
    if((GET_INPUT_TIMING_VHEIGHT() % 2) == 0x01)
    {
        // Extend format conversion DEN
        ScalerSetBit(P31_0B_FC_FPRMAT_PRO_OUTPUT, ~_BIT3, _BIT3);

        // Enlarge H width by 1
        ScalerSetWord(P31_07_FC_FORMAT_PRO_MAIN_0, (ScalerGetWord(P31_07_FC_FORMAT_PRO_MAIN_0) + 1));
    }
}
#endif

//--------------------------------------------------
// Description  : Set even/odd resolution
// Input Value  : usHwidth, usVstart  --> resolution for even/odd
// Output Value : None
//--------------------------------------------------
void ScalerFmtCnvFtoPSetFifo(WORD usHwidth, WORD usVstart)
{
    if((LOBYTE(usVstart) & _BIT0) == _BIT0)
    {
        // Set vertical start field = even
        ScalerSetBit(P31_06_FC_EO_LINE_CTRL, ~_BIT4, _BIT4);
    }
    else
    {
        // Set vertical start field = odd
        ScalerSetBit(P31_06_FC_EO_LINE_CTRL, ~_BIT4, 0x00);
    }

    // Toggle vertical start field for VS bypass
    if(ScalerGetBit(P0_11_M1_VGIP_SIGINV, _BIT6) == _BIT6)
    {
        ScalerSetByte(P31_06_FC_EO_LINE_CTRL, (ScalerGetByte(P31_06_FC_EO_LINE_CTRL) ^ _BIT4));
    }

    // Set horizontal width
    ScalerSetBit(P31_07_FC_FORMAT_PRO_MAIN_0, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (HIBYTE(usHwidth) & 0x1F));
    ScalerSetByte(P31_08_FC_FORMAT_PRO_MAIN_1, LOBYTE(usHwidth));
}

