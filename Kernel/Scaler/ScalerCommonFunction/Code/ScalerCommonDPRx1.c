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
// ID Code      : ScalerCommonDPRx1.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_DPRX1__

#include "ScalerCommonFunctionInclude.h"

#if(_D1_DP_EXIST == _ON)

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
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
bit g_bDpRx1VscSdpColorMode;

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
bit g_bDpRx1RSV1PacketDetecting;

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
bit g_bDpRx1MstToSstRSV1PacketDetecting;
#endif
#endif
#endif

BYTE g_ucDpRx1MSAFailMacRsetCount;

#if(_ULTRA_HDR_SUPPORT == _ON)
BYTE g_ucDPRx1InfoTypeCompare;
BYTE g_pucDPRx1HDRBackup[_HW_DP_INFOFRAME_RSV0_LENGTH];
BYTE g_pucDPRx1RSV0Backup[_HW_DP_INFOFRAME_RSV0_LENGTH];
StructDPInfoFrameRSV0Ctrl g_stDPRx1InfoFrameRSV0Ctrl;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
bit ScalerDpRx1GetVideoInfo(void);
void ScalerDpRx1SetColorInfo(void);
void ScalerDpRx1VideoSetting(void);
void ScalerDpRx1ColorimetrySetting(void);
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
void ScalerDpRx1ColorimetryExtSetting(void);
#endif
void ScalerDpRx1QuantizationSetting(void);

bit ScalerDpRx1MiscCheck(void);

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
bit ScalerDpRx1VscCheck(void);

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
void ScalerDpRx1RSV1PacketDetectEvent(void);
void ScalerDpRx1SetInitialRSV1InfoType(void);
#endif

#endif

#if(_DP_MST_SUPPORT == _ON)
void ScalerDpRx1MstReset(void);

#if(_DP_TX_SUPPORT == _ON)
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
void ScalerDpRx1MstToSstRSV1PacketDetectEvent(void);
#endif
#endif
#endif
#endif

bit ScalerDpRx1MSACheck(void);
void ScalerDpRx1FakeLTProtect(void);
void ScalerDpRx1SetInitialRSV0InfoType(void);

#if(_DP_FREESYNC_SUPPORT == _ON)
BYTE ScalerDpRx1GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
BYTE ScalerDpRx1GetAmdSpdBackupInfo(EnumAmdSpdInfoContent enumContent);
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
void ScalerDpRx1InfoFrameRSV0Check(void);
void ScalerDpRx1RSV0PacketDetectEvent(void);
void ScalerDpRx1GetInfoFrameRSV0(BYTE *pucDPRx1RSV0Data);
BYTE ScalerDpRx1SelectInfoFrameType(BYTE ucInfoFrameTypeCurrent);
void ScalerDpRx1InfoFrameRSV0Initial(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : DP Get Video Info
// Input Value  : None
// Output Value : TRUE --> Get successfully
//--------------------------------------------------
bit ScalerDpRx1GetVideoInfo(void)
{
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
    CLR_DP_RX1_VSC_SDP_COLOR_MODE();

    // Check MISC1[6]
    if((ScalerGetBit(PB9_03_MN_STRM_ATTR_MISC1, _BIT6)) == _BIT6)
    {
        SET_DP_RX1_VSC_SDP_COLOR_MODE();

#if(_HW_DP_VSC_SDP_REG_SUPPORT == _ON)

        // Read DB16~18 --> pData[0:2]
        ScalerRead(PB9_46_VSC15, 3, pData, _AUTOINC);
#else
        // Delay 2 frames for SRAM ready (worst case)
        ScalerTimerDelayXms(_DP_ONE_FRAME_TIME_MAX * 2);

        SET_DP_RX1_RSV1_DETECTING();

        ScalerTimerActiveTimerEvent((_DP_ONE_FRAME_TIME_MAX * 3), _SCALER_TIMER_EVENT_DP_RX1_RSV1_PACKET_DETECT);

        // Read DB16~18 --> pData[0:2]
        ScalerGetDataPortByte(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV1_DB16, 3, pData, _AUTOINC);
#endif
        // Set ColorimetryExtPreValue & QuantizationPreValue & ColorDepthPreValue
        SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(pData[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
        SET_DIGITAL_QUANTIZATION_PREVALUE((pData[1] & _BIT7) >> 7);
        SET_DIGITAL_COLOR_DEPTH_PREVALUE(pData[1] & (_BIT2 | _BIT1 | _BIT0));
        SET_DIGITAL_COLOR_SPACE_PREVALUE(pData[0] & (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        DebugMessageRx1("VSC DB16", pData[0]);
        DebugMessageRx1("VSC DB17", pData[1]);
    }
    else
#endif
    {
        // Get MISC Info
        pData[0] = ScalerGetByte(PB9_02_MN_STRM_ATTR_MISC);

        // Set ColorimetryPreValue & QuantizationPreValue
        SET_DIGITAL_COLORIMETRY_PREVALUE((pData[0] & (_BIT4 | _BIT3 | _BIT2 | _BIT1)) >> 1);
        SET_DIGITAL_QUANTIZATION_PREVALUE((pData[0] & _BIT3) >> 3);
        SET_DIGITAL_COLOR_DEPTH_PREVALUE((pData[0] & (_BIT7 | _BIT6 | _BIT5)) >> 5);
        SET_DIGITAL_COLOR_SPACE_PREVALUE((ScalerGetBit(PB9_03_MN_STRM_ATTR_MISC1, _BIT7)) | (pData[0] & (_BIT2 | _BIT1)));
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Set Color Info Macros
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetColorInfo(void)
{
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
    if(GET_DP_RX1_VSC_SDP_COLOR_MODE() == _TRUE)
    {
        // Use VSC SDP
        // Set Color Space Macro
        switch(GET_DIGITAL_COLOR_SPACE_PREVALUE())
        {
            case _VSC_COLOR_SPACE_0:
                SET_COLOR_SPACE(_COLOR_SPACE_RGB);
                break;

            case _VSC_COLOR_SPACE_1:
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
                break;

            case _VSC_COLOR_SPACE_2:
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
                break;

            case _VSC_COLOR_SPACE_3:
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
                break;

            case _VSC_COLOR_SPACE_4:
                SET_COLOR_SPACE(_COLOR_SPACE_Y_ONLY);
                break;

            case _VSC_COLOR_SPACE_5:
                SET_COLOR_SPACE(_COLOR_SPACE_RAW);
                break;

            default:
                SET_COLOR_SPACE(_COLOR_SPACE_RGB);
                break;
        }

        // Set Colorimetry Ext
        ScalerDpRx1ColorimetryExtSetting();
    }
    else
#endif
    {
        switch(GET_DIGITAL_COLOR_SPACE_PREVALUE())
        {
            case _BIT1:
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
                break;

            case _BIT2:
                SET_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
                break;

            case _BIT7:
                SET_COLOR_SPACE(_COLOR_SPACE_Y_ONLY);
                break;

            case (_BIT7 | _BIT1):
                SET_COLOR_SPACE(_COLOR_SPACE_RAW);
                break;

            default:
                SET_COLOR_SPACE(_COLOR_SPACE_RGB);
                break;
        }

        // Set Colorimetry
        ScalerDpRx1ColorimetrySetting();
    }

    // Get Color Depth
    if(GET_COLOR_SPACE() != _COLOR_SPACE_RAW)
    {
        switch(GET_DIGITAL_COLOR_DEPTH_PREVALUE())
        {
            case 0:
                SET_COLOR_DEPTH(_COLOR_DEPTH_6_BITS);
                break;

            case 1:
                SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
                break;

            case 2:
                SET_COLOR_DEPTH(_COLOR_DEPTH_10_BITS);
                break;

            case 3:
                SET_COLOR_DEPTH(_COLOR_DEPTH_12_BITS);
                break;

            case 4:
                SET_COLOR_DEPTH(_COLOR_DEPTH_16_BITS);
                break;

            default:
                SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
                break;
        }
    }
    else
    {
        switch(GET_DIGITAL_COLOR_DEPTH_PREVALUE())
        {
            case 1:
                SET_COLOR_DEPTH(_COLOR_DEPTH_6_BITS);
                break;

            case 2:
                SET_COLOR_DEPTH(_COLOR_DEPTH_7_BITS);
                break;

            case 3:
                SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
                break;

            case 4:
                SET_COLOR_DEPTH(_COLOR_DEPTH_10_BITS);
                break;

            case 5:
                SET_COLOR_DEPTH(_COLOR_DEPTH_12_BITS);
                break;

            case 6:
                SET_COLOR_DEPTH(_COLOR_DEPTH_14_BITS);
                break;

            case 7:
                SET_COLOR_DEPTH(_COLOR_DEPTH_16_BITS);
                break;

            default:
                SET_COLOR_DEPTH(_COLOR_DEPTH_8_BITS);
                break;
        }
    }

    // Set Porch Color
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420))
    {
        if(GET_DIGITAL_QUANTIZATION_PREVALUE() == _DP_COLOR_QUANTIZATION_LIMIT)
        {
            SET_DP_RX1_PORCH_COLOR_YCC_LIMIT();
        }
        else if(GET_DIGITAL_QUANTIZATION_PREVALUE() == _DP_COLOR_QUANTIZATION_FULL)
        {
            SET_DP_RX1_PORCH_COLOR_YCC_FULL();
        }
    }
    else
    {
        SET_DP_RX1_PORCH_COLOR_RGB();
    }

    // Set Quantization Range
    ScalerDpRx1QuantizationSetting();
}

//--------------------------------------------------
// Description  : DP Video Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1VideoSetting(void)
{
    // Set Color Space for Display Format Gen.
    switch(GET_COLOR_SPACE())
    {
        case _COLOR_SPACE_RGB:
            DebugMessageRx1("_COLOR_SPACE_RGB", 0);
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), 0x00);
            break;

        case _COLOR_SPACE_YCBCR444:
            DebugMessageRx1("_COLOR_SPACE_YCBCR444", 0);
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), _BIT4);
            break;

        case _COLOR_SPACE_YCBCR422:
            DebugMessageRx1("_COLOR_SPACE_YCBCR422", 0);
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), _BIT3);
            break;

        case _COLOR_SPACE_YCBCR420:
            DebugMessageRx1("_COLOR_SPACE_YCBCR420", 0);
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), 0x00);
            break;

        case _COLOR_SPACE_Y_ONLY:
            DebugMessageRx1("_COLOR_SPACE_Y_ONLY", 0);
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
            break;

        case _COLOR_SPACE_RAW:
            DebugMessageRx1("_COLOR_SPACE_RAW", 0);
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), 0x00);
            break;

        default:
            // RGB
            ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT4 | _BIT3), 0x00);
            break;
    }

    // Set Color Depth for Display Format Gen.
    ScalerSetBit(PB8_20_PG_CTRL_0, ~(_BIT2 | _BIT1 | _BIT0), GET_DIGITAL_COLOR_DEPTH_PREVALUE());
    DebugMessageRx1("_COLOR_DEPTH", GET_COLOR_DEPTH());
}


//--------------------------------------------------
// Description  : DP Rx1 Colorimetry Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1ColorimetrySetting(void)
{
    BYTE ucColorimetryValue = (GET_DIGITAL_COLORIMETRY_PREVALUE() << 1);

    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(ucColorimetryValue & (_BIT4 | _BIT3))
        {
            case 0:
                SET_COLORIMETRY(_COLORIMETRY_YCC_XVYCC601);
                DebugMessageRx1("_COLORIMETRY_YCC_XVYCC601", 0);
                break;

            case _BIT3:
                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT601);
                DebugMessageRx1("_COLORIMETRY_YCC_ITUR_BT601", 0);
                break;

            case _BIT4:
                SET_COLORIMETRY(_COLORIMETRY_YCC_XVYCC709);
                DebugMessageRx1("_COLORIMETRY_YCC_XVYCC709", 0);
                break;

            case (_BIT4 | _BIT3):
                SET_COLORIMETRY(_COLORIMETRY_YCC_ITUR_BT709);
                DebugMessageRx1("_COLORIMETRY_YCC_ITUR_BT709", 0);
                break;

            default:
                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(ucColorimetryValue & (_BIT4 | _BIT3 | _BIT2 | _BIT1))
        {
            case 0:
                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);
                DebugMessageRx1("_COLORIMETRY_RGB_SRGB_VESA", 0);
                break;

            case _BIT3:
                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);
                DebugMessageRx1("_COLORIMETRY_RGB_SRGB_CEA", 0);
                break;

            case (_BIT2 | _BIT1):
                SET_COLORIMETRY(_COLORIMETRY_RGB_XRRGB);
                DebugMessageRx1("_COLORIMETRY_RGB_XRRGB", 0);
                break;

            case (_BIT4 | _BIT2 | _BIT1):
                SET_COLORIMETRY(_COLORIMETRY_RGB_SCRGB);
                DebugMessageRx1("_COLORIMETRY_RGB_SCRGB", 0);
                break;

            case (_BIT4 | _BIT3):
                SET_COLORIMETRY(_COLORIMETRY_RGB_ADOBERGB);
                DebugMessageRx1("_COLORIMETRY_RGB_ADOBERGB", 0);
                break;

            case (_BIT3 | _BIT2 | _BIT1):
                SET_COLORIMETRY(_COLORIMETRY_RGB_DCI_P3);
                DebugMessageRx1("_COLORIMETRY_RGB_DCI_P3", 0);
                break;

            case (_BIT4 | _BIT3 | _BIT2 | _BIT1):
                SET_COLORIMETRY(_COLORIMETRY_RGB_COLOR_PROFILE);
                DebugMessageRx1("_COLORIMETRY_RGB_COLOR_PROFILE", 0);
                break;

            default:
                SET_COLORIMETRY(_COLORIMETRY_RGB_SRGB);
                DebugMessageRx1("_COLORIMETRY_RGB_SRGB", 0);
                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_Y_ONLY)
    {
        SET_COLORIMETRY(_COLORIMETRY_Y_ONLY);
        DebugMessageRx1("_COLORIMETRY_Y_ONLY", 0);
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RAW)
    {
        SET_COLORIMETRY(_COLORIMETRY_RAW);
        DebugMessageRx1("_COLORIMETRY_RAW", 0);
    }
}

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Rx1 Colorimetry Extended Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1ColorimetryExtSetting(void)
{
    SET_COLORIMETRY(_COLORIMETRY_EXT);

    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _VSC_COLORIMETRY_0:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT601);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_ITUR_BT601", 0);
                break;

            case _VSC_COLORIMETRY_1:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT709);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_ITUR_BT709", 0);
                break;

            case _VSC_COLORIMETRY_2:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC601);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_XVYCC601", 0);
                break;

            case _VSC_COLORIMETRY_3:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_XVYCC709);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_XVYCC709", 0);
                break;

            case _VSC_COLORIMETRY_4:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_SYCC601);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_SYCC601", 0);
                break;

            case _VSC_COLORIMETRY_5:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ADOBEYCC601);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_ADOBEYCC601", 0);
                break;

            case _VSC_COLORIMETRY_6:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_ITUR_BT2020_CL", 0);
                break;

            case _VSC_COLORIMETRY_7:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL);
                DebugMessageRx1("_COLORIMETRY_EXT_YCC_ITUR_BT2020_NCL", 0);
                break;

            default:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);
                DebugMessageRx1("_COLORIMETRY_EXT_RESERVED", 0);
                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RGB)
    {
        switch(GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            case _VSC_COLORIMETRY_0:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_SRGB);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_SRGB", 0);
                break;

            case _VSC_COLORIMETRY_1:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_XRRGB);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_XRRGB", 0);
                break;

            case _VSC_COLORIMETRY_2:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_SCRGB);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_SCRGB", 0);
                break;

            case _VSC_COLORIMETRY_3:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ADOBERGB);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_ADOBERGB", 0);
                break;

            case _VSC_COLORIMETRY_4:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_DCI_P3);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_DCI_P3", 0);
                break;

            case _VSC_COLORIMETRY_5:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_CUSTOM_COLOR_PROFILE);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_CUSTOM_COLOR_PROFILE", 0);
                break;

            case _VSC_COLORIMETRY_6:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RGB_ITUR_BT2020);
                DebugMessageRx1("_COLORIMETRY_EXT_RGB_ITUR_BT2020", 0);
                break;

            default:
                SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RESERVED);
                DebugMessageRx1("_COLORIMETRY_EXT_RESERVED", 0);
                break;
        }
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_Y_ONLY)
    {
        SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_Y_ONLY_DICOM_PART14);
        DebugMessageRx1("_COLORIMETRY_EXT_Y_ONLY_DICOM_PART14", 0);
    }
    else if(GET_COLOR_SPACE() == _COLOR_SPACE_RAW)
    {
        SET_EXT_COLORIMETRY(_COLORIMETRY_EXT_RAW_CUSTOM_COLOR_PROFILE);
        DebugMessageRx1("_COLORIMETRY_EXT_RAW_CUSTOM_COLOR_PROFILE", 0);
    }
}
#endif

//--------------------------------------------------
// Description  : DP Rx1 Quantization Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1QuantizationSetting(void)
{
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444))
    {
        if(GET_DIGITAL_QUANTIZATION_PREVALUE() == _DP_COLOR_QUANTIZATION_FULL)
        {
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);
            DebugMessageRx1("_YCC_QUANTIZATION_FULL_RANGE", 0);
        }
        else
        {
            SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_LIMIT_RANGE);
            DebugMessageRx1("_YCC_QUANTIZATION_LIMIT_RANGE", 0);
        }

        SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_RESERVED);
    }
    else if(GET_COLORIMETRY() == _COLORIMETRY_RGB_ADOBERGB) // Special case for AdobeRGB
    {
        SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);
        SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);
    }
    else
    {
        if(GET_DIGITAL_QUANTIZATION_PREVALUE() == _DP_COLOR_QUANTIZATION_FULL)
        {
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_FULL_RANGE);
            DebugMessageRx1("_RGB_QUANTIZATION_FULL_RANGE", 0);
        }
        else
        {
            SET_COLOR_RGB_QUANTIZATION_RANGE(_RGB_QUANTIZATION_LIMIT_RANGE);
            DebugMessageRx1("_RGB_QUANTIZATION_LIMIT_RANGE", 0);
        }

        SET_COLOR_YCC_QUANTIZATION_RANGE(_YCC_QUANTIZATION_FULL_RANGE);
    }
}

//--------------------------------------------------
// Description  : Check DP Misc Information
// Input Value  : None
// Output Value : True --> DP Misc Check Ok
//--------------------------------------------------
bit ScalerDpRx1MiscCheck(void)
{
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
    // Check MISC1[6]
    if((ScalerGetBit(PB9_03_MN_STRM_ATTR_MISC1, _BIT6)) == _BIT6)
    {
        return ScalerDpRx1VscCheck();
    }
    else
#endif
    {
        // Get MISC Info
        BYTE ucMisc0 = ScalerGetByte(PB9_02_MN_STRM_ATTR_MISC);
        BYTE ucColorSpaceValue = (ScalerGetBit(PB9_03_MN_STRM_ATTR_MISC1, _BIT7)) | (ucMisc0 & (_BIT2 | _BIT1));

        // Color Space Check
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)

        // Color format info source change from VSC --> MISC
        if(GET_DP_RX1_VSC_SDP_COLOR_MODE() == _TRUE)
        {
            switch(ucColorSpaceValue)
            {
                case _BIT1:
                    if(GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR422)
                    {
                        DebugMessageRx1("Misc change: Color Format, _COLOR_SPACE_YCBCR422", 0);
                        return _FALSE;
                    }
                    break;

                case _BIT2:
                    if(GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR444)
                    {
                        DebugMessageRx1("Misc change: Color Format, _COLOR_SPACE_YCBCR444", 0);
                        return _FALSE;
                    }
                    break;

                case _BIT7:
                    if(GET_COLOR_SPACE() != _COLOR_SPACE_Y_ONLY)
                    {
                        DebugMessageRx1("Misc change: Color Format, _COLOR_SPACE_Y_ONLY", 0);
                        return _FALSE;
                    }
                    break;

                case (_BIT7 | _BIT1):
                    if(GET_COLOR_SPACE() != _COLOR_SPACE_RAW)
                    {
                        DebugMessageRx1("Misc change: Color Format, _COLOR_SPACE_RAW", 0);
                        return _FALSE;
                    }
                    break;

                default:
                    if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
                    {
                        DebugMessageRx1("Misc change: Color Format, _COLOR_SPACE_RGB", 0);
                        return _FALSE;
                    }
                    break;
            }
        }
        else
#endif
        {
            if(ucColorSpaceValue != GET_DIGITAL_COLOR_SPACE_PREVALUE())
            {
                DebugMessageRx1("Misc change: Color Space", 0);
                return _FALSE;
            }
        }

        // Color Depth Check
        if((((ucMisc0 & (_BIT7 | _BIT6 | _BIT5))) >> 5) != GET_DIGITAL_COLOR_DEPTH_PREVALUE())
        {
            DebugMessageRx1("Misc change: Color Depth", (((ucMisc0 & (_BIT7 | _BIT6 | _BIT5))) >> 5));
            return _FALSE;
        }

        // Colorimetry Check
        if(GET_COLORIMETRY() != _COLORIMETRY_EXT)
        {
            if(((ucMisc0 & (_BIT4 | _BIT3 | _BIT2 | _BIT1)) >> 1) != GET_DIGITAL_COLORIMETRY_PREVALUE())
            {
                DebugMessageRx1("Misc change: Colorimetry", 0);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
                {
                    return _FALSE;
                }
                else
                {
                    SET_DIGITAL_COLORIMETRY_PREVALUE((ucMisc0 & (_BIT4 | _BIT3 | _BIT2 | _BIT1)) >> 1);
                    ScalerDpRx1ColorimetrySetting();
                    SET_DIGITAL_COLORIMETRY_CHANGED();
                }
            }
        }
        else
        {
            DebugMessageRx1("Misc change: Ext Colorimetry", 0);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
            {
                return _FALSE;
            }
            else
            {
                SET_DIGITAL_COLORIMETRY_PREVALUE((ucMisc0 & (_BIT4 | _BIT3 | _BIT2 | _BIT1)) >> 1);
                ScalerDpRx1ColorimetrySetting();
                SET_DIGITAL_COLORIMETRY_CHANGED();
            }
        }

        // Dynamic Range Check
#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
        if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422))
        {
            if(((ucMisc0 & _BIT3) >> 3) != GET_DIGITAL_QUANTIZATION_PREVALUE())
            {
                DebugMessageRx1("Misc change: Dynamic Range", 0);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
                {
                    return _FALSE;
                }
                else
                {
                    SET_DIGITAL_QUANTIZATION_PREVALUE((ucMisc0 & _BIT3) >> 3);
                    ScalerDpRx1QuantizationSetting();
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
        }
        else
#endif
        {
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
            if(((ucMisc0 & _BIT3) >> 3) != GET_DIGITAL_QUANTIZATION_PREVALUE())
            {
                DebugMessageRx1("Misc change: Dynamic Range", 0);

                if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
                {
                    return _FALSE;
                }
                else
                {
                    SET_DIGITAL_QUANTIZATION_PREVALUE((ucMisc0 & _BIT3) >> 3);
                    ScalerDpRx1QuantizationSetting();
                    SET_DIGITAL_QUANTIZATION_CHANGED();
                }
            }
#endif
        }

#if(_DP_FREESYNC_SUPPORT == _ON)
        if(GET_FREESYNC_ENABLED() == _FALSE)
#endif
        {
            // Get HSW
            ScalerRead(PB9_0E_MSA_HSW_0, 2, &pData[0], _AUTOINC);

            // Get VSW
            ScalerRead(PB9_18_MSA_VSW_0, 2, &pData[2], _AUTOINC);

            if(((PDATA_WORD(0) & 0x7FFF) == 0x00) || ((PDATA_WORD(1) & 0x7FFF) == 0x00))
            {
                return _FALSE;
            }
        }

        return _TRUE;
    }
}

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check DP VSC SDP Information
// Input Value  : None
// Output Value : True --> DP VSC SDP Check Ok
//--------------------------------------------------
bit ScalerDpRx1VscCheck(void)
{
    BYTE pucVscColorFormat[3];

    memset(pucVscColorFormat, 0, sizeof(pucVscColorFormat));

#if(_HW_DP_VSC_SDP_REG_SUPPORT == _ON)

    // Read DB16~18 --> pucVscColorFormat[0:2]
    ScalerRead(PB9_46_VSC15, 3, pucVscColorFormat, _AUTOINC);
#else
    if(GET_DP_RX1_RSV1_DETECTING() == _FALSE)
    {
        // Read DB16~18 --> pucVscColorFormat[0:2]
        ScalerGetDataPortByte(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV1_DB16, 3, pucVscColorFormat, _AUTOINC);

        SET_DP_RX1_RSV1_DETECTING();

        ScalerTimerActiveTimerEvent((_DP_ONE_FRAME_TIME_MAX * 3), _SCALER_TIMER_EVENT_DP_RX1_RSV1_PACKET_DETECT);
    }
    else
    {
        return _TRUE;
    }
#endif

    // Color Space Check
    if(GET_DP_RX1_VSC_SDP_COLOR_MODE() == _FALSE)
    {
        // Color format info source change from MISC --> VSC
        switch(pucVscColorFormat[0] & (_BIT7 | _BIT6 | _BIT5 | _BIT4))
        {
            case _VSC_COLOR_SPACE_0:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_RGB", 0);
                    return _FALSE;
                }

                break;

            case _VSC_COLOR_SPACE_1:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR444)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_YCBCR444", 0);
                    return _FALSE;
                }

                break;

            case _VSC_COLOR_SPACE_2:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR422)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_YCBCR422", 0);
                    return _FALSE;
                }

                break;

            case _VSC_COLOR_SPACE_3:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_YCBCR420)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_YCBCR420", 0);
                    return _FALSE;
                }

                break;

            case _VSC_COLOR_SPACE_4:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_Y_ONLY)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_Y_ONLY", 0);
                    return _FALSE;
                }

                break;

            case _VSC_COLOR_SPACE_5:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_RAW)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_RAW", 0);
                    return _FALSE;
                }

                break;

            default:
                if(GET_COLOR_SPACE() != _COLOR_SPACE_RGB)
                {
                    DebugMessageRx1("VSC change: Color Space, _COLOR_SPACE_RGB", 0);
                    return _FALSE;
                }

                break;
        }
    }
    else
    {
        if((pucVscColorFormat[0] & (_BIT7 | _BIT6 | _BIT5 | _BIT4)) != GET_DIGITAL_COLOR_SPACE_PREVALUE())
        {
            DebugMessageRx1("VSC change: Color Space", 0);
            return _FALSE;
        }
    }

    // Color Depth Check
    if((pucVscColorFormat[1] & (_BIT2 | _BIT1 | _BIT0)) != GET_DIGITAL_COLOR_DEPTH_PREVALUE())
    {
        DebugMessageRx1("VSC change: Color Depth", 0);
        return _FALSE;
    }

    // Colorimetry Ext Check
    if(GET_COLORIMETRY() == _COLORIMETRY_EXT)
    {
        if((pucVscColorFormat[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != GET_DIGITAL_COLORIMETRY_EXT_PREVALUE())
        {
            DebugMessageRx1("VSC change: Color Depth", 0);

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
            {
                return _FALSE;
            }
            else
            {
                SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(pucVscColorFormat[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
                ScalerDpRx1ColorimetryExtSetting();
                SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
            }
        }
    }
    else
    {
        DebugMessageRx1("VSC change: Colorimetry Ext", 0);

        if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
        {
            return _FALSE;
        }
        else
        {
            SET_DIGITAL_COLORIMETRY_EXT_PREVALUE(pucVscColorFormat[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0));
            ScalerDpRx1ColorimetryExtSetting();
            SET_DIGITAL_COLORIMETRY_EXT_CHANGED();
        }
    }

    // Dynamic Range Check
#if(_YCC_QUANTIZATION_RANGE_SUPPORT == _ON)
    if((GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR444) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420))
    {
        if(((pucVscColorFormat[1] & _BIT7) >> 7) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx1("VSC change: Dynamic Range", ((pucVscColorFormat[1] & _BIT7) >> 7));

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
            {
                return _FALSE;
            }
            else
            {
                SET_DIGITAL_QUANTIZATION_PREVALUE((pucVscColorFormat[1] & _BIT7) >> 7);
                ScalerDpRx1QuantizationSetting();
                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
        }
    }
    else
#endif
    {
#if(_RGB_QUANTIZATION_RANGE_SUPPORT == _ON)
        if(((pucVscColorFormat[1] & _BIT7) >> 7) != GET_DIGITAL_QUANTIZATION_PREVALUE())
        {
            DebugMessageRx1("VSC change: Dynamic Range", ((pucVscColorFormat[1] & _BIT7) >> 7));

            if(GET_DIGITAL_COLOR_INFO_CHANGE_RESET() == _TRUE)
            {
                return _FALSE;
            }
            else
            {
                SET_DIGITAL_QUANTIZATION_PREVALUE((pucVscColorFormat[1] & _BIT7) >> 7);
                ScalerDpRx1QuantizationSetting();
                SET_DIGITAL_QUANTIZATION_CHANGED();
            }
        }
#endif
    }

    return _TRUE;
}

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
//--------------------------------------------------
// Description  : DP Rx1 VSC Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1RSV1PacketDetectEvent(void)
{
    CLR_DP_RX1_RSV1_DETECTING();
}

//--------------------------------------------------
// Description  : Set DP Rx1 RSV1 infoframe type to VSC
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetInitialRSV1InfoType(void)
{
    // Set Packet Type of RSV1 to VSC
    ScalerSetByte(PB9_2D_DP_INFO_FM_RSV1, _DP_SDP_TYPE_VSC);

    CLR_DP_RX1_RSV1_DETECTING();
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_RSV1_PACKET_DETECT);

#if((_DP_MST_SUPPORT == _ON) && (_DP_TX_SUPPORT == _ON))
    ScalerSetByte(PBC_54_DP_INFO_FM_RSV1, _DP_SDP_TYPE_VSC);

    CLR_DP_RX1_MST2SST_RSV1_DETECTING();
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_MST2SST_RSV1_PACKET_DETECT);
#endif
}
#endif
#endif

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Rx1 Mst Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1MstReset(void)
{
    SET_DP_RX1_AUX_MANUAL_MODE();

    // Reset GUID
    for(pData[0] = 0; pData[0] < 16; pData[0]++)
    {
        ScalerDpRx1SetDpcdValue(0x00, 0x00, (0x30 + pData[0]), 0x00);
    }

    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x00, ((ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x00) & 0xC0) | 0x01));

    // Disable 0x111 IRQ
    ScalerSetBit(PBA_B2_AUX_SPECIAL_IRQ_EN, ~_BIT7, 0x00);

    ScalerDpRx1SetDpcdValue(0x00, 0x01, 0x11, 0x00);

    // CLR 0x111 IRQ Flag
    ScalerSetBit(PBA_B3_AUX_SPECIAL_IRQ_FLAG, ~(_BIT7 | _BIT4), _BIT7);

    // Enable 0x111 IRQ
    ScalerSetBit(PBA_B2_AUX_SPECIAL_IRQ_EN, ~_BIT7, _BIT7);

    SET_DP_RX1_AUX_AUTO_MODE();

    // Disable MST
    ScalerSetBit(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT7, 0x00);

    // Clear Payload ID Table
    ScalerSetBit(PBA_B0_AUX_PAYLOAD_CLEAR, ~_BIT6, _BIT6);
    ScalerSetBit(PBA_B0_AUX_PAYLOAD_CLEAR, ~_BIT6, 0x00);

    // Reset ST1 ~ ST5
    for(pData[0] = 0; pData[0] < 5; pData[0]++)
    {
        // Reset Start Position
        ScalerSetByte(PB8_03_STHD_CTRL_2 + (pData[0] << 1), 0x00);

        // Reset End Position
        ScalerSetByte(PB8_04_STHD_CTRL_3 + (pData[0] << 1), 0x00);
    }

    // Reset ST1_Source ~ ST5_Source
    ScalerSetBit(PB8_0D_SOURCE_SEL_0, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(PB8_0D_SOURCE_SEL_0, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(PB8_0E_SOURCE_SEL_1, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(PB8_0E_SOURCE_SEL_1, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(PB8_0F_SOURCE_SEL_2, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // Reset Daisy Chain ST3 ~ ST5
    for(pData[0] = 0; pData[0] < 3; pData[0]++)
    {
        // Reset Start Position
        ScalerSetByte(RET_REG_ADDR_DP_RX1_DAIZY_ST3_START() + (pData[0] << 1), 0x00);

        // Reset End Position
        ScalerSetByte(RET_REG_ADDR_DP_RX1_DAIZY_ST3_END() + (pData[0] << 1), 0x00);
    }

    if((GET_REG_DP_RX_DOWN_REQUEST_BUF0_MSG_FINISH() == 0x01) || (GET_REG_DP_RX_DOWN_REQUEST_BUF1_MSG_FINISH() == 0x01))
    {
        SET_DP_RX1_AUX_COMMAND_NO_REPLY();
    }

    // Disable Buf0 / Buf1 Receive Capability
    CLR_REG_DP_RX_DOWN_REQUEST_MSG_RECEIVE_CRC_IGNORE_ENABLE();

    // Clr Buf0/Buf1 DownRequest MSG Finish Flag
    CLR_REG_DP_RX_DOWN_REQUEST_MSG_FINISH();

    // Clr Buf0 / Buf1
    CLR_REG_DP_RX_DOWN_REQUEST_BUF0_BUF1();

    // Clr Buf0/Buf1 MSG Error Flag
    CLR_REG_DP_RX_DOWN_REQUEST_MSG_ERROR();

    // Disable MST Related IRQ
    CLR_REG_DP_RX_DOWN_REPLY_UP_REQUEST_READY_BIT_IRQ();

    // Clr 1000h Has Been Write
    CLR_REG_DP_RX_DOWN_REQUEST_ADDR_WRITTEN();

    // Disable Rx Igrone Error
    ScalerSetBit(PBA_D1_DP_IIC_SET, ~_BIT3, 0x00);

    // Message Upstream Disable
    CLR_REG_DP_RX_UPSTREAM_REPLY();

    // Reset Rx MSG Block
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT6, _BIT6);
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT6, 0x00);

    if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
    {
        // Enable DownRequest Buf0 / Buf1 Receive Capability
        SET_REG_DP_RX_DOWN_REQUEST_MSG_RECEIVE_CRC_IGNORE_ENABLE();

        // Enable UpReply Buf0 / Buf1 Receive Capability
        SET_REG_DP_RX_UP_REPLY_MSG_RECEIVE_CRC_IGNORE_ENABLE();
    }
}

#if(_DP_TX_SUPPORT == _ON)

#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)

#if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
//--------------------------------------------------
// Description  : DP Rx1 MstToSst VSC Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1MstToSstRSV1PacketDetectEvent(void)
{
    CLR_DP_RX1_MST2SST_RSV1_DETECTING();
}
#endif // End of #if(_HW_DP_VSC_SDP_REG_SUPPORT != _ON)
#endif // End of #if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
#endif // End of #if(_DP_TX_SUPPORT == _ON)
#endif // End of #if(_DP_MST_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Check Dp Video Straam VBID
// Input Value  : None
// Output Value : True --> Get Video Stream
//--------------------------------------------------
bit ScalerDpRx1MSACheck(void)
{
    // Pop up Main Stream Attributes
    ScalerSetBit(PB9_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT3));

    // Get Hactive
    ScalerRead(PB9_0C_MSA_HWD_0, 2, &pData[4], _AUTOINC);

    // Get Vactive
    ScalerRead(PB9_16_MSA_VHT_0, 2, &pData[12], _AUTOINC);

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        if((PDATA_WORD(2) == 0x00) || (PDATA_WORD(6) == 0x00))
        {
            return _FALSE;
        }
    }
    else
#endif
    {
#if((_ULTRA_HDR_SUPPORT == _ON) && (_AUDIO_SUPPORT == _ON))
        // Set Audio Info Type to RSV0 for HDR application
        ScalerSetByte(PB9_2C_DP_INFO_FM_RSV0, _DP_AUDIO_TIMESTAMP);
#endif

        // Get Htotal
        ScalerRead(PB9_08_MSA_HTT_0, 2, &pData[0], _AUTOINC);

        // Get Hstart
        ScalerRead(PB9_0A_MSA_HST_0, 2, &pData[2], _AUTOINC);

        // Get HSW
        ScalerRead(PB9_0E_MSA_HSW_0, 2, &pData[6], _AUTOINC);

        // Get Vtotal
        ScalerRead(PB9_10_MSA_VTTE_0, 2, &pData[8], _AUTOINC);

        // Get Vstart
        ScalerRead(PB9_14_MSA_VST_0, 2, &pData[10], _AUTOINC);

        // Get VSW
        ScalerRead(PB9_18_MSA_VSW_0, 2, &pData[14], _AUTOINC);

        if((PDATA_WORD(0) == 0x00) || (PDATA_WORD(1) == 0x00) || (PDATA_WORD(2) == 0x00) || ((PDATA_WORD(3) & 0x7FFF) == 0x00) ||
           (PDATA_WORD(4) == 0x00) || (PDATA_WORD(5) == 0x00) || (PDATA_WORD(6) == 0x00) || ((PDATA_WORD(7) & 0x7FFF) == 0x00))
        {
            if((PDATA_WORD(0) == 0x00) && (PDATA_WORD(1) == 0x00) && (PDATA_WORD(2) == 0x00) && ((PDATA_WORD(3) & 0x7FFF) == 0x00) &&
               (PDATA_WORD(4) == 0x00) && (PDATA_WORD(5) == 0x00) && (PDATA_WORD(6) == 0x00) && ((PDATA_WORD(7) & 0x7FFF) == 0x00))
            {
#if(_DP_MST_SUPPORT == _ON)
                if(GET_REG_DP_RX_MST_ENABLE() == _FALSE)
#endif
                {
                    if(ScalerDpRx1HdcpEnebled() == _TRUE)
                    {
                        if(GET_DP_RX1_MSA_FAIL_MAC_RESET_COUNT() < 10)
                        {
                            ADD_DP_RX1_MSA_FAIL_MAC_RESET_COUNT();
                        }
                        else
                        {
                            CLR_DP_RX1_MSA_FAIL_MAC_RESET_COUNT();

                            ScalerSetBit(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
                            ScalerTimerDelayXms(30);
                            ScalerSetBit(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

                            // Delay a Complete Frame
                            ScalerTimerDelayXms(30);
                        }
                    }
                    else
                    {
                        return _FALSE;
                    }
                }
            }

            return _FALSE;
        }

        CLR_DP_RX1_MSA_FAIL_MAC_RESET_COUNT();
    }

    // Get Mvid
    ScalerRead(PB9_1A_MSA_MVID_0, 3, pData, _AUTOINC);

    if((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)) == 0x00)
    {
        return _FALSE;
    }

    // Get Nvid
    ScalerRead(PB9_1D_MSA_NVID_0, 3, pData, _AUTOINC);

    if((((DWORD)pData[0] << 16) | ((DWORD)pData[1] << 8) | ((DWORD)pData[2] << 0)) == 0x00)
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : PS Mode Set Fake LT Flag
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1FakeLTProtect(void)
{
    SET_DP_RX1_FAKE_LINK_TRAINING();

    SET_DP_RX1_AUX_MANUAL_MODE();

    if(GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
    {
        SET_DP_RX1_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS);
    }

    SET_DP_RX1_AUX_AUTO_MODE();
}

//--------------------------------------------------
// Description  : Set DP RSV0 infoframe type
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetInitialRSV0InfoType(void)
{
#if(_DP_FREESYNC_SUPPORT == _ON)
    // Set Freesync Info Type to RSV0
    ScalerSetByte(PB9_2C_DP_INFO_FM_RSV0, _SPD_INFO_TYPE);
#else
#if((_ULTRA_HDR_SUPPORT == _ON) && (_AUDIO_SUPPORT == _ON))
    // Set Audio Info Type to RSV0
    ScalerSetByte(PB9_2C_DP_INFO_FM_RSV0, _DP_AUDIO_TIMESTAMP);
#endif
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
    CLR_DP_RX1_RSV0_DETECTING();
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_RSV0_PACKET_DETECT);
#endif
}

#if(_DP_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get AMD SPD Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerDpRx1GetAmdSpdInfo(EnumAmdSpdInfoContent enumContent)
{
    if(ScalerGetByte(PB9_2C_DP_INFO_FM_RSV0) == _SPD_INFO_TYPE)
    {
        // Get AMD OUI
        ScalerGetDataPortByte(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV0_DB1, 3, pData, _AUTOINC);

        if((pData[0] == 0x1A) && (pData[1] == 0x00) && (pData[2] == 0x00))
        {
            switch(enumContent)
            {
                case _SPD_INFO_FREESYNC_SUPPORT:

                    pData[0] = ScalerGetDataPortBit(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV0_DB6, _BIT0);
                    return ((bit)pData[0]);

                case _SPD_INFO_FREESYNC_ENABLE:

                    pData[0] = ScalerGetDataPortBit(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV0_DB6, _BIT1);
                    return ((bit)pData[0]);

                case _SPD_INFO_FREESYNC_ACTIVE:

                    pData[0] = ScalerGetDataPortBit(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV0_DB6, _BIT2);
                    return ((bit)pData[0]);

                case _SPD_INFO_FREESYNC_MIN_VFREQ:

                    ScalerGetDataPortByte(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV0_DB7, 1, pData, _NON_AUTOINC);

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                case _SPD_INFO_FREESYNC_MAX_VFREQ:

                    ScalerGetDataPortByte(PB9_30_DP_INFO_FM_ADR, _DP_INFO_RSV0_DB8, 1, pData, _NON_AUTOINC);

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                default:

                    return 0x00;
            }
        }

        return 0x00;
    }

    return 0x00;
}

//--------------------------------------------------
// Description  : Get AMD SPD Backup Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerDpRx1GetAmdSpdBackupInfo(EnumAmdSpdInfoContent enumContent)
{
#if(_ULTRA_HDR_SUPPORT == _ON)
    if((GET_FREESYNC_ENABLED() == _TRUE) && (GET_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED() == _TRUE))
    {
        // Check AMD OUI
        if((g_pucDPRx1RSV0Backup[1] == 0x1A) && (g_pucDPRx1RSV0Backup[2] == 0x00) && (g_pucDPRx1RSV0Backup[3] == 0x00))
        {
            switch(enumContent)
            {
                case _SPD_INFO_FREESYNC_SUPPORT:

                    return ((bit)(g_pucDPRx1RSV0Backup[6] & _BIT0));

                case _SPD_INFO_FREESYNC_ENABLE:

                    return ((bit)(g_pucDPRx1RSV0Backup[6] & _BIT1));

                case _SPD_INFO_FREESYNC_ACTIVE:

                    return ((bit)(g_pucDPRx1RSV0Backup[6] & _BIT2));

                case _SPD_INFO_FREESYNC_MIN_VFREQ:

                    pData[0] = g_pucDPRx1RSV0Backup[7];

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                case _SPD_INFO_FREESYNC_MAX_VFREQ:

                    pData[0] = g_pucDPRx1RSV0Backup[8];

                    if(((WORD)pData[0] * 10) < _PANEL_FREESYNC_MIN_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MIN_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 0);
                    }
                    else if(((WORD)pData[0] * 10) > _PANEL_FREESYNC_MAX_FRAME_RATE)
                    {
                        pData[0] = _PANEL_FREESYNC_MAX_FRAME_RATE / 10;
                        DebugMessageRx1("Freesync SPD info abnormal", 1);
                    }

                    return pData[0];

                default:

                    return 0x00;
            }
        }

        return 0x00;
    }

    return 0x00;
#else
    return ScalerDpRx1GetAmdSpdInfo(enumContent);
#endif
}
#endif // End of #if(_DP_FREESYNC_SUPPORT == _ON)

#if(_ULTRA_HDR_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP InfoFrame RSV0 Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1InfoFrameRSV0Check(void)
{
    BYTE pucDPRx1RSV0Data[_HW_DP_INFOFRAME_RSV0_LENGTH];
    BYTE ucInfoFrameType = 0;

    memset(pucDPRx1RSV0Data, 0, _HW_DP_INFOFRAME_RSV0_LENGTH);
    ScalerDpRx1GetInfoFrameRSV0(pucDPRx1RSV0Data);

    ucInfoFrameType = ScalerGetByte(PB9_2C_DP_INFO_FM_RSV0);

    if(ucInfoFrameType == _HDR_INFO_TYPE)
    {
        switch(g_ucDPRx1InfoTypeCompare)
        {
#if(_DP_FREESYNC_SUPPORT == _ON)
            case _SPD_INFO_TYPE:

                if(memcmp(pucDPRx1RSV0Data, g_pucDPRx1RSV0Backup, _HW_DP_INFOFRAME_RSV0_LENGTH) == 0)
                {
                    CLR_DP_RX1_HDR_INFO_FRAME_RECEIVED();
                }
                else
                {
                    SET_DP_RX1_HDR_INFO_FRAME_RECEIVED();
                }

                break;
#endif

            case _DP_AUDIO_TIMESTAMP:

                if(memcmp(&pucDPRx1RSV0Data[16], &g_pucDPRx1RSV0Backup[16], 12) == 0)
                {
                    CLR_DP_RX1_HDR_INFO_FRAME_RECEIVED();
                }
                else
                {
                    SET_DP_RX1_HDR_INFO_FRAME_RECEIVED();
                }

                break;

            default:
                break;
        }

        if(GET_DP_RX1_HDR_INFO_FRAME_RECEIVED() == _TRUE)
        {
            memcpy(g_pucDPRx1HDRBackup, pucDPRx1RSV0Data, _HW_DP_INFOFRAME_RSV0_LENGTH);
        }
    }
    else
    {
        switch(g_ucDPRx1InfoTypeCompare)
        {
#if(_DP_FREESYNC_SUPPORT == _ON)
            case _SPD_INFO_TYPE:

                if(memcmp(pucDPRx1RSV0Data, g_pucDPRx1HDRBackup, _HW_DP_INFOFRAME_RSV0_LENGTH) == 0)
                {
                    CLR_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED();
                }
                else
                {
                    SET_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED();
                    memcpy(g_pucDPRx1RSV0Backup, pucDPRx1RSV0Data, _HW_DP_INFOFRAME_RSV0_LENGTH);
                }

                break;
#endif

            case _DP_AUDIO_TIMESTAMP:

                if(memcmp(pucDPRx1RSV0Data, g_pucDPRx1HDRBackup, _HW_DP_INFOFRAME_RSV0_LENGTH) == 0)
                {
                    CLR_DP_RX1_AUDIO_INFO_FRAME_RECEIVED();
                }
                else
                {
                    SET_DP_RX1_AUDIO_INFO_FRAME_RECEIVED();
                    memcpy(g_pucDPRx1RSV0Backup, pucDPRx1RSV0Data, _HW_DP_INFOFRAME_RSV0_LENGTH);
                }

                break;

            default:
                break;
        }
    }

    ScalerSetByte(PB9_2C_DP_INFO_FM_RSV0, ScalerDpRx1SelectInfoFrameType(ucInfoFrameType));
}

//--------------------------------------------------
// Description  : HDMI Info Frame Packet Detect Event
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1RSV0PacketDetectEvent(void)
{
    CLR_DP_RX1_RSV0_DETECTING();
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerDpRx1GetInfoFrameRSV0(BYTE *pucDPRx1RSV0Data)
{
    BYTE ucTemp = 0;

    do
    {
        ScalerSetByte(PB9_30_DP_INFO_FM_ADR, (_DP_INFO_RSV0_DB0 + ucTemp));
        pucDPRx1RSV0Data[ucTemp] = ScalerGetByte(PB9_31_DP_INFO_FM_DAT);

        ucTemp ++;
    }
    while(ucTemp < _HW_DP_INFOFRAME_RSV0_LENGTH);
}

//--------------------------------------------------
// Description  : DP Select InfoFrame Type
// Input Value  : None
// Output Value : InfoFrame Type
//--------------------------------------------------
BYTE ScalerDpRx1SelectInfoFrameType(BYTE ucInfoFrameTypeCurrent)
{
    BYTE ucInfoFrameTypeNext = 0;

    if(ucInfoFrameTypeCurrent == _HDR_INFO_TYPE)
    {
        ucInfoFrameTypeNext = g_ucDPRx1InfoTypeCompare;
    }
    else
    {
        ucInfoFrameTypeNext = _HDR_INFO_TYPE;
    }

    return ucInfoFrameTypeNext;
}

//--------------------------------------------------
// Description  : DP InfoFrame RSV0 initial setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1InfoFrameRSV0Initial(void)
{
#if((_ULTRA_HDR_SUPPORT == _ON) && (_DP_FREESYNC_SUPPORT == _ON))
    CLR_DP_RX1_AMD_SPD_INFO_FRAME_RECEIVED();
#endif

#if(_ULTRA_HDR_SUPPORT == _ON)
    // Get RSV0 Infoframe
    ScalerDpRx1GetInfoFrameRSV0(g_pucDPRx1RSV0Backup);

    // Get Compare with HDR infoframe type
    g_ucDPRx1InfoTypeCompare = ScalerGetByte(PB9_2C_DP_INFO_FM_RSV0);
    CLR_DP_RX1_AUDIO_INFO_FRAME_RECEIVED();
    CLR_DP_RX1_HDR_INFO_FRAME_RECEIVED();
    // Set DP RSV0 info type: HDR
    ScalerSetByte(PB9_2C_DP_INFO_FM_RSV0, _HDR_INFO_TYPE);
#endif
}
#endif // End of #if(_ULTRA_HDR_SUPPORT == _ON)

#endif // End of #if(_D1_DP_EXIST == _ON)
