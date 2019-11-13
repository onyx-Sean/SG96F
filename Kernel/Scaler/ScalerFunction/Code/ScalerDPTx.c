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
// ID Code      : ScalerDPTx.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_DP_TX__

#include "ScalerFunctionInclude.h"

#if(_DP_TX_SUPPORT == _ON)
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
//--------------------------------------------------
void ScalerDpTxInitialReset(void);
void ScalerDpTxVersionCheck(BYTE ucDpVersion);
void ScalerDpTxLinkRateCheck(BYTE ucDpTxLinkRate);
bit ScalerDpTxTPSxSupportCheck(void);
void ScalerDpTxSSTDisplayFormatSetting(void);
BYTE ScalerDpTxSetTPSxPattern(void);
bit ScalerDpTxLinkRateReduce(EnumDPTxLTResult enumDPTxLTResult);
bit ScalerDpTxLaneCountReduce(EnumDPTxLTResult enumDPTxLTResult);
void ScalerDpTxSignalInitialSetting(void);
void ScalerDpTxSignalLaneSetting(void);
void ScalerDpTxSSCSet(bit bSSCEn);
bit ScalerDpTxMeasureGetMeasureResult(StructMeasureSyncData *pstMeasureSyncHV);
bit ScalerDpTxMeasureInputInfo(void);
bit ScalerDpTxCloneCheckInterlaceVtotal(void);
void ScalerDpTxCloneSwitchFormatConversionMux(BYTE ucInputPort);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

//--------------------------------------------------
// Description  : Dp Tx Initial Parameter Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpTxInitialReset(void)
{
    // Disable Downstream Z0 Detection
    ScalerSetBit(PBC_A2_DPTX_RCV_DET0, ~_BIT6, 0x00);

    // Set DP TX CLK divider
    ScalerSetByte(PBB_E0_DPTX_CLK_GEN, 0x21);
}

//--------------------------------------------------
// Description  : Handle Tx Dp Version
// Input Value  : DPCD 00000h
// Output Value : None
//--------------------------------------------------
void ScalerDpTxVersionCheck(BYTE ucDpVersion)
{
    if((ucDpVersion != _DP_VERSION_1_0) && (ucDpVersion != _DP_VERSION_1_1) && (ucDpVersion != _DP_VERSION_1_2))
    {
        if(ucDpVersion >= _DP_VERSION_1_2)
        {
            ucDpVersion = _DP_VERSION_1_2;
        }
        else
        {
            ucDpVersion = _DP_VERSION_1_1;
        }
    }

    SET_DP_TX_DOWNSTREAM_DPCD_REV(ucDpVersion);
}

//--------------------------------------------------
// Description  : Handle Tx Link Rate
// Input Value  : DPCD 00001h
// Output Value : None
//--------------------------------------------------
void ScalerDpTxLinkRateCheck(BYTE ucDpTxLinkRate)
{
    if((ucDpTxLinkRate == _DP_LINK_RBR) || (ucDpTxLinkRate == _DP_LINK_HBR) || ((GET_DP_TX_DOWNSTREAM_DPCD_REV() >= _DP_VERSION_1_2) && (ucDpTxLinkRate >= _DP_LINK_HBR2)))
    {
        if(ucDpTxLinkRate >= _DP_LINK_HBR2)
        {
            SET_DP_TX_DOWNSTREAM_MAX_LINK_RATE(_DP_LINK_HBR2);
        }
        else
        {
            SET_DP_TX_DOWNSTREAM_MAX_LINK_RATE(ucDpTxLinkRate);
        }
    }
    else // Set the slowest link rate
    {
        SET_DP_TX_DOWNSTREAM_MAX_LINK_RATE(_DP_LINK_RBR);
    }
}

//--------------------------------------------------
// Description  : Check Tx TPSx Support
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpTxTPSxSupportCheck(void)
{
    BYTE pucData[1];

    memset(pucData, 0, sizeof(pucData));

    if(ScalerDpTxAuxNativeRead(0x00, 0x00, 0x02, 1, pucData) == _FALSE)
    {
        return _FALSE;
    }

    // Check TPS3 support
    if(((pucData[0] & _BIT6) == _BIT6) && (GET_DP_TX_DOWNSTREAM_DPCD_REV() >= _DP_VERSION_1_2))
    {
        SET_DP_TX_DOWNSTREAM_TP3_SUPPORT();
    }
    else
    {
        CLR_DP_TX_DOWNSTREAM_TP3_SUPPORT();
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Tx Arbiter
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerDpTxSSTDisplayFormatSetting(void)
{
    // Disable HW Auto Calculate H Delay
    ScalerSetBit(PBB_D3_LFIFO_WL_SET, ~_BIT7, 0x00);

    // Pixel Generation Block Reset
    ScalerSetBit(PBB_A1_DP_RESET_CTRL, ~_BIT7, _BIT7);
    ScalerSetBit(PBB_A1_DP_RESET_CTRL, ~_BIT7, 0x00);

    // Set Interlace Bit of VBID as Interlace Mode Detected
    if(GET_DP_TX_INPUT_INTERLACE_MODE() == _ON)
    {
        ScalerSetBit(PBB_C7_VBID, ~_BIT0, _BIT0);
    }
    else
    {
        ScalerSetBit(PBB_C7_VBID, ~_BIT0, 0x00);
    }

    // Get Bit Per Chrome
    switch(GET_DP_TX_INPUT_COLOR_DEPTH())
    {
        case 0x00:
            pData[0] = 6;
            break;

        case 0x01:
            pData[0] = 8;
            break;

        case 0x02:
            pData[0] = 10;
            break;

        case 0x03:
            pData[0] = 12;
            break;

        case 0x04:
            pData[0] = 16;
            break;

        default:

            pData[0] = 8;
            break;
    }

    pData[1] = ((GET_DP_TX_INPUT_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) ? 2 : (GET_DP_TX_INPUT_COLOR_SPACE() == _COLOR_SPACE_Y_ONLY) ? 1 : 3);

    // step1: Cal vaild symbol in TU
    // Average TU = TU Size x (Stream_Clk x Byte of 1 pixel / Lane Number) / Link Rate
    PDATA_WORD(1) = ((GET_DP_TX_DOWNSTREAM_DOWN_SPREAD() == _TRUE) ? ((DWORD)270 * GET_DP_TX_DOWNSTREAM_LINK_RATE() * 9975 / 10000) : ((DWORD)270 * GET_DP_TX_DOWNSTREAM_LINK_RATE()));
    PDATA_WORD(1) = ((DWORD)_DP_TX_SST_TU_SIZE * (((DWORD)GET_DP_TX_INPUT_PIXEL_CLK() * pData[1] * pData[0]) / GET_DP_TX_DOWNSTREAM_LANE_NUM())) / (PDATA_WORD(1));

    ScalerSetByte(PBB_CC_TU_SIZE, _DP_TX_SST_TU_SIZE);
    ScalerSetByte(PBB_CD_TU_DATA_SIZE0, (PDATA_WORD(1) >> 3));
    ScalerSetByte(PBB_CE_TU_DATA_SIZE1, (PDATA_WORD(1) & 0x07));

    PDATA_WORD(2) = ((DWORD)g_stDPTxInputTimingInfo.usHWidth * pData[0] * pData[1]) / (GET_DP_TX_DOWNSTREAM_LANE_NUM() * 8);
    PDATA_WORD(2) += ((bit)(((DWORD)g_stDPTxInputTimingInfo.usHWidth * pData[0] * pData[1]) % (GET_DP_TX_DOWNSTREAM_LANE_NUM() * 8)) ? 1 : 0);

    ScalerSetByte(PBB_CA_V_DATA_PER_LINE0, pData[4]);
    ScalerSetByte(PBB_CB_V_DATA_PER_LINE1, pData[5]);

    // Get TU Number Per Line
    PDATA_WORD(0) = (PDATA_WORD(2) << 3) / PDATA_WORD(1) + (((PDATA_WORD(2) << 3) % PDATA_WORD(1) > 0) ? 1 : 0);

    // Store Horizontal DE for Sec Data End Count
    SET_DP_TX_HORIZONTAL_DE_PERIOD(PDATA_WORD(0) * _DP_TX_SST_TU_SIZE);

    // step 3: Enable HW Auto Calculate H Delay
    ScalerSetBit(PBB_D3_LFIFO_WL_SET, ~_BIT7, _BIT7);

    // Clear FIFO Status
    ScalerSetByte(PBB_A4_PG_FIFO_CTRL, 0xFF);
}

//--------------------------------------------------
// Description  : DP Tx Link Training 2
// Input Value  :
// Output Value :
//--------------------------------------------------
BYTE ScalerDpTxSetTPSxPattern(void)
{
    // Check TP3 Supported
    if(GET_DP_TX_DOWNSTREAM_TP3_SUPPORT() == _TRUE)
    {
        // Main Link Switch to TPS3 Pattern
        ScalerSetBit(PBB_01_DPTX_ML_PAT_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_DP_TX_OUTPUT_TPS3 << 4));
        return _DP_TP_3;
    }
    else
    {
        // Main Link Switch to TPS2 Pattern
        ScalerSetBit(PBB_01_DPTX_ML_PAT_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_DP_TX_OUTPUT_TPS2 << 4));
        return _DP_TP_2;
    }
}

//--------------------------------------------------
// Description  : DP Tx Link Training Link Rate Reduce
// Input Value  :
// Output Value :
//--------------------------------------------------
bit ScalerDpTxLinkRateReduce(EnumDPTxLTResult enumDPTxLTResult)
{
    switch(GET_DP_TX_DOWNSTREAM_LINK_RATE())
    {
        case _DP_LINK_HBR2:

            SET_DP_TX_DOWNSTREAM_LINK_RATE(_DP_LINK_HBR);

            if(enumDPTxLTResult == _DP_TX_TRAINING_PATTERN2_ADJUST_FAIL)
            {
                SET_DP_TX_DOWNSTREAM_LANE_NUM(GET_DP_TX_DOWNSTREAM_MAX_LANE_NUM_TEMP());
            }

            pData[0] = _DP_LINK_HBR;
            pData[1] = ((GET_DP_TX_DOWNSTREAM_ENHANCE_FRAMING() << 7) | GET_DP_TX_DOWNSTREAM_LANE_NUM());

            // Write Link Rate to DPCD 100h and Lane Count to DPCD 101h
            ScalerDpTxAuxNativeWrite(0x00, 0x01, 0x00, 2, pData);

            break;

        case _DP_LINK_HBR:

            SET_DP_TX_DOWNSTREAM_LINK_RATE(_DP_LINK_RBR);

            if(enumDPTxLTResult == _DP_TX_TRAINING_PATTERN2_ADJUST_FAIL)
            {
                SET_DP_TX_DOWNSTREAM_LANE_NUM(GET_DP_TX_DOWNSTREAM_MAX_LANE_NUM_TEMP());
            }

            pData[0] = _DP_LINK_RBR;
            pData[1] = ((GET_DP_TX_DOWNSTREAM_ENHANCE_FRAMING() << 7) | GET_DP_TX_DOWNSTREAM_LANE_NUM());

            // Write Link Rate to DPCD 100h and Lane Count to DPCD 101h
            ScalerDpTxAuxNativeWrite(0x00, 0x01, 0x00, 2, pData);

            break;

        default:

            switch(GET_DP_TX_DOWNSTREAM_LANE_NUM())
            {
                case _DP_LINK_4_LANE:

                    SET_DP_TX_DOWNSTREAM_MAX_LANE_NUM_TEMP(_DP_LINK_2_LANE);
                    break;

                case _DP_LINK_2_LANE:

                    SET_DP_TX_DOWNSTREAM_MAX_LANE_NUM_TEMP(_DP_LINK_1_LANE);
                    break;

                default:
                    break;
            }

            return _FAIL;

            break;
    }

    // Tx Lane Setting
    ScalerDpTxSignalLaneSetting();

    // Change Analog PHY CMU Clk
    ScalerGDIPhyTxCMUPowerOn();

    // Reset Signal Level
    ScalerDpTxSignalReset();

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : DP Tx Link Training Lane Count Reduce
// Input Value  :
// Output Value :
//--------------------------------------------------
bit ScalerDpTxLaneCountReduce(EnumDPTxLTResult enumDPTxLTResult)
{
    PDATA_WORD(0) = 0;

    switch(GET_DP_TX_DOWNSTREAM_LANE_NUM())
    {
        case _DP_LINK_4_LANE:

            if(enumDPTxLTResult == _DP_TX_TRAINING_PATTERN1_ADJUST_FAIL)
            {
                SET_DP_TX_DOWNSTREAM_LINK_RATE(GET_DP_TX_DOWNSTREAM_MAX_LINK_RATE());
            }

            SET_DP_TX_DOWNSTREAM_LANE_NUM(_DP_LINK_2_LANE);

            pData[0] = GET_DP_TX_DOWNSTREAM_LINK_RATE();
            pData[1] = ((GET_DP_TX_DOWNSTREAM_ENHANCE_FRAMING() << 7) | _DP_LINK_2_LANE);

            // Write Link Rate to DPCD 100h and Lane Count to DPCD 101h
            ScalerDpTxAuxNativeWrite(0x00, 0x01, 0x00, 2, pData);

            break;

        case _DP_LINK_2_LANE:

            if(enumDPTxLTResult == _DP_TX_TRAINING_PATTERN1_ADJUST_FAIL)
            {
                SET_DP_TX_DOWNSTREAM_LINK_RATE(GET_DP_TX_DOWNSTREAM_MAX_LINK_RATE());
            }

            SET_DP_TX_DOWNSTREAM_LANE_NUM(_DP_LINK_1_LANE);

            pData[0] = GET_DP_TX_DOWNSTREAM_LINK_RATE();
            pData[1] = ((GET_DP_TX_DOWNSTREAM_ENHANCE_FRAMING() << 7) | _DP_LINK_1_LANE);

            // Write Link Rate to DPCD 100h and Lane Count to DPCD 101h
            ScalerDpTxAuxNativeWrite(0x00, 0x01, 0x00, 2, pData);

            break;

        default:

            return _FAIL;

            break;
    }

    // Tx Lane Setting
    ScalerDpTxSignalLaneSetting();

    // Change Analog PHY CMU Clk
    ScalerGDIPhyTxCMUPowerOn();

    // Reset Signal Level
    ScalerDpTxSignalReset();

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Dp Tx Main Link Power on
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerDpTxSignalInitialSetting(void)
{
    // Set Voltage Swing and pre-emphasis level 0
    ScalerDpTxSignalReset();

    // Disable scramble
    ScalerSetBit(PBB_0D_DPTX_PHY_CTRL, ~_BIT0, 0x00);

    // Set Z0 to 50 ohm
    ScalerSetByte(PBC_C2_DPTX_Z0_LANE3_2, 0x88);
    ScalerSetByte(PBC_C3_DPTX_Z0_LANE1_0, 0x88);

    // Set Lane Swap
    ScalerSetByte(PBC_AA_DPTX_SFIFO_LANE_SWAP1, 0x1B);

    // Enable DP Tx
    ScalerSetBit(PBC_A0_DPTX_PHY_CTRL0, ~(_BIT7 | _BIT4), (_BIT7 | _BIT4));

    // set ENHANCED Mode
    ScalerSetBit(PBB_A0_DP_MAC_CTRL, ~_BIT2, (GET_DP_TX_DOWNSTREAM_ENHANCE_FRAMING() << 2));

    // SSC bug of PI for RLE0638
    ScalerDpTxSSCSet(_DISABLE);

    // DPTX power on TX driver and Enable output
    ScalerDpTxSignalLaneSetting();
}

//--------------------------------------------------
// Description  : Dp Tx Main Link Power on
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerDpTxSignalLaneSetting(void)
{
    // DPTX power on TX driver and Enable output
    switch(GET_DP_TX_DOWNSTREAM_LANE_NUM())
    {
        case _DP_ONE_LANE:

            // Set Mac 1 Lane
            ScalerSetBit(PBB_A0_DP_MAC_CTRL, ~(_BIT1 | _BIT0), _BIT0);

            // Dig PHY Set
            ScalerSetBit(PBB_00_DP_PHY_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT4 | _BIT2));

            // Disable Skew
            ScalerSetBit(PBB_0D_DPTX_PHY_CTRL, ~_BIT2, 0x00);

            // Set Daisy Chain Lane Num, 1 --> point to 1 lane
            SET_REG_DP_RX_DAISY_CHAIN_LANE_NUM(1);

            // Reset Small FIFO Before Output Enable
            ScalerSetBit(PBC_A7_DPTX_SFIFO_CTRL0, ~_BIT7, 0x00);
            ScalerSetBit(PBC_A7_DPTX_SFIFO_CTRL0, ~_BIT7, _BIT7);

            ScalerSetBit(PBC_A1_DPTX_PHY_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1));
            ScalerSetBit(PBC_A0_DPTX_PHY_CTRL0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);

            break;

        case _DP_TWO_LANE:

            // Set Mac 2 Lane
            ScalerSetBit(PBB_A0_DP_MAC_CTRL, ~(_BIT1 | _BIT0), _BIT1);

            // Dig PHY Set
            ScalerSetBit(PBB_00_DP_PHY_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3));

            // Set Daisy Chain Lane Num, 2 --> point to 2 lane
            SET_REG_DP_RX_DAISY_CHAIN_LANE_NUM(2);

            // Enable Lane Skew
            ScalerSetBit(PBB_0D_DPTX_PHY_CTRL, ~_BIT2, _BIT2);

            // Reset Small FIFO Before Output Enable
            ScalerSetBit(PBC_A7_DPTX_SFIFO_CTRL0, ~_BIT7, 0x00);
            ScalerSetBit(PBC_A7_DPTX_SFIFO_CTRL0, ~_BIT7, _BIT7);

            ScalerSetBit(PBC_A1_DPTX_PHY_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2));
            ScalerSetBit(PBC_A0_DPTX_PHY_CTRL0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

            break;

        case _DP_FOUR_LANE:

            // Set Mac 4 Lane
            ScalerSetBit(PBB_A0_DP_MAC_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            // Dig PHY Set
            ScalerSetBit(PBB_00_DP_PHY_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2));

            // Set Daisy Chain Lane Num, 3 --> point to 4 lane
            SET_REG_DP_RX_DAISY_CHAIN_LANE_NUM(3);

            // Enable Lane Skew
            ScalerSetBit(PBB_0D_DPTX_PHY_CTRL, ~_BIT2, _BIT2);

            // Reset Small FIFO Before Output Enable
            ScalerSetBit(PBC_A7_DPTX_SFIFO_CTRL0, ~_BIT7, 0x00);
            ScalerSetBit(PBC_A7_DPTX_SFIFO_CTRL0, ~_BIT7, _BIT7);

            ScalerSetBit(PBC_A1_DPTX_PHY_CTRL1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            ScalerSetBit(PBC_A0_DPTX_PHY_CTRL0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Dp Tx SSC Set
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerDpTxSSCSet(bit bSSCEn)
{
    // Set SSC
    if(bSSCEn == _ENABLE)
    {
        PDATA_WORD(0) = (WORD)((ScalerGetBit(PBC_DD_DPTX_CMU12, 0x1F) << 4) | (ScalerGetByte(PBC_DE_DPTX_CMU13) >> 4));
        PDATA_WORD(1) = (WORD)((ScalerGetBit(PBC_DE_DPTX_CMU13, 0x0F) << 8) | ScalerGetByte(PBC_DF_DPTX_CMU14));

        // Calculate SSC Frequency = 32k
        PDATA_WORD(3) = (((_EXT_XTAL / _DP_TX_SSC_FREQ) + 2) & 0xFFFC);

        // Calculate SSC 0.5 % downspread
        PDATA_WORD(2) = ((((DWORD)PDATA_WORD(0) + 4) * 4096 + PDATA_WORD(1))) * 16 / 200 / PDATA_WORD(3);

        // Set SSC Frequency = 32k
        ScalerSetByte(PBC_E1_DPTX_CMU16, (BYTE)(PDATA_WORD(3) >> 8));
        ScalerSetByte(PBC_E2_DPTX_CMU17, (BYTE) PDATA_WORD(3));

        // Set SSC 0.5 % downspread
        ScalerSetByte(PBC_E3_DPTX_CMU18, (BYTE)(PDATA_WORD(2) >> 8));
        ScalerSetByte(PBC_E4_DPTX_CMU19, (BYTE) PDATA_WORD(2));


        // [5] 1: Enable SSC, 0: disable
        // [4] 0: 1st Order SDM, 1:2nd Order SDM
        // [3] 0: Triangular wave, 1: Square wave
        ScalerSetBit(PBC_D5_DPTX_CMU5, ~(_BIT5 | _BIT4 | _BIT3), _BIT5);
    }
    else
    {
        // Disable SSC
        ScalerSetBit(PBC_D5_DPTX_CMU5, ~_BIT5, 0x00);
    }
}

//--------------------------------------------------
// Description  : On-line check for DPTX SST D0
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpTxMeasureGetMeasureResult(StructMeasureSyncData *pstMeasureSyncHV)
{
    if(ScalerTimerPollingFlagProc(_MEASURE_TIMEOUT, P16_42_DPTX_MEAS_CTL1, _BIT7, 0x00) == _FALSE)
    {
        return _FALSE;
    }

    // Check measure result status
    if(ScalerGetBit(P16_43_DPTX_MEAS_ERROR_FLG0, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) != 0x00)
    {
        return _FALSE;
    }

    // Pop up measurement result
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~_BIT6, _BIT6);

    // Polarity
    pstMeasureSyncHV->b1HSP = (bit)ScalerGetBit(P16_44_DPTX_MEAS_ERROR_FLG1, _BIT6);
    pstMeasureSyncHV->b1VSP = (bit)ScalerGetBit(P16_44_DPTX_MEAS_ERROR_FLG1, _BIT7);

    // HSync Period
    pstMeasureSyncHV->usHSPeriod = ((((WORD)ScalerGetByte(P16_45_DPTX_MEAS_HS_PERIOD_A_M) & 0x1F) << 8) | (ScalerGetByte(P16_46_DPTX_MEAS_HS_PERIOD_A_L))) + 1;

    // VSync Period
    pstMeasureSyncHV->usVSPeriod = ((((WORD)ScalerGetByte(P16_48_DPTX_MEAS_VS_PERIOD_A_M) & 0x0F) << 8) | (ScalerGetByte(P16_49_DPTX_MEAS_VS_PERIOD_A_L))) + 1;

    // HSync Pulse Width
    pstMeasureSyncHV->usHSWidth = ((((WORD)ScalerGetByte(P16_4A_DPTX_MEAS_HS_PULSE_A_M) & 0x1F) << 8) | (ScalerGetByte(P16_4B_DPTX_MEAS_HS_PULSE_A_L))) + 1;

    // VSync Pulse Width
    pstMeasureSyncHV->usVSWidth = ((((WORD)ScalerGetByte(P16_4C_DPTX_MEAS_VS_PULSE_A_M) & 0xF) << 8) | (ScalerGetByte(P16_4D_DPTX_MEAS_VS_PULSE_A_L))) + 1;

    // H total
    pstMeasureSyncHV->usHTotal = ((((WORD)ScalerGetByte(P16_4E_DPTX_MEAS_HS_PERIOD_D_M) & 0x1F) << 8) | (ScalerGetByte(P16_4F_DPTX_MEAS_HS_PERIOD_D_L))) + 1;

    // V Height
    pstMeasureSyncHV->usVHeight = ((((WORD)ScalerGetByte(P16_51_DPTX_MEAS_VS_PERIOD_D_M) & 0x0F) << 8) | (ScalerGetByte(P16_52_DPTX_MEAS_VS_PERIOD_D_L))) + 1;

    // H Width
    pstMeasureSyncHV->usHWidth = ((((WORD)ScalerGetByte(P16_53_DPTX_MEAS_HS_PULSE_D_M) & 0x1F) << 8) | (ScalerGetByte(P16_54_DPTX_MEAS_HS_PULSE_D_L))) + 1;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Measure function for DPTX SST D0
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpTxMeasureInputInfo(void)
{
    StructMeasureSyncData stMeasureSyncHV;
    memset(&stMeasureSyncHV, 0, sizeof(StructMeasureSyncData));

    // Power up DPTX measure; Measure Time Clock = 16384 Xtal; VS Measure Invert Disable; Disable HS/DEN swap
    ScalerSetBit(P16_41_DPTX_MEAS_CTL0, ~(_BIT7 | _BIT6 | _BIT4 | _BIT3 | _BIT0), (_BIT7 | _BIT6));

    // Use Auto function for ensuring that P16_5A_DPTX_MEAS2_HS_VS_DLY is ready
    // Start auto
    ScalerSetBit(P16_CD_DPTX_AUTO_ADJ_CTRL1, ~_BIT0, _BIT0);

    // Wait for auto
    if(ScalerTimerPollingFlagProc(90, P16_CD_DPTX_AUTO_ADJ_CTRL1, _BIT0, 0x00) == _FALSE)
    {
        DebugMessageMst("Tx Measure Auto Failed", 0x00);

        return _FALSE;
    }

    // Check Hs/Vs edge location
    switch(ScalerGetBit(P16_5A_DPTX_MEAS2_HS_VS_DLY, (_BIT7 | _BIT6 | _BIT5)))
    {
        case (_BIT6 | _BIT5):
            // 011: delay Vs
            ScalerSetBit(P16_5A_DPTX_MEAS2_HS_VS_DLY, ~(_BIT4 | _BIT3), _BIT3);
            break;
        case (_BIT5):
            // 001: delay Hs
            ScalerSetBit(P16_5A_DPTX_MEAS2_HS_VS_DLY, ~(_BIT4 | _BIT3), _BIT4);
            break;
        default:
            // reset Hs/Vs delay
            ScalerSetBit(P16_5A_DPTX_MEAS2_HS_VS_DLY, ~(_BIT4 | _BIT3), 0x00);
            break;
    }

    // Disable DPTX measure
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~(_BIT5 | _BIT0), 0x00);

    // Set DPTX VGIP sync polarity to default
    ScalerSetBit(P16_A1_DPTX_VGIP_SIGINV, ~(_BIT3 | _BIT2), 0x00);

    // Stop auto-function measure
    ScalerSetByte(P16_CD_DPTX_AUTO_ADJ_CTRL1, 0x80);

    // Set DPTX auto H boundary = 0x0000 ~ 0x1FFF
    ScalerSetByte(P16_C0_DPTX_H_BOUNDARY_H, 0x0F);
    ScalerSetByte(P16_C1_DPTX_H_BOUNDARY_STA_L, 0x00);
    ScalerSetByte(P16_C2_DPTX_H_BOUNDARY_END_L, 0xFF);
    ScalerSetBit(P16_C7_DPTX_GRN_NOISE_MARGIN, ~(_BIT1 | _BIT0), _BIT0);

    // Set DPTX auto V boundary = 0x0000 ~ 0x0FFF
    ScalerSetByte(P16_C3_DPTX_V_BOUNDARY_H, 0x0F);
    ScalerSetByte(P16_C4_DPTX_V_BOUNDARY_STA_L, 0x00);
    ScalerSetByte(P16_C5_DPTX_V_BOUNDARY_END_L, 0xFF);

    // Start DPTX measure
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~(_BIT5 | _BIT0), (_BIT5 | _BIT0));

    // Pop-out measure result
    if(ScalerDpTxMeasureGetMeasureResult(&stMeasureSyncHV) == _FALSE)
    {
        DebugMessageMst("Tx Measure Pop Up Failed", 0x00);

        return _FALSE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_DP_MST_FREESYNC_ENABLED() == _TRUE)
    {
        // Set DPTX VGIP sync polarity
        ScalerSetBit(P16_A1_DPTX_VGIP_SIGINV, ~(_BIT6 | _BIT3 | _BIT2), (_BIT6 | ((stMeasureSyncHV.b1VSP == _POSITIVE) ? 0x00 : _BIT3) | ((stMeasureSyncHV.b1HSP == _POSITIVE) ? 0x00 : _BIT2)));
    }
    else
#endif
    {
        // Set DPTX VGIP sync polarity
        ScalerSetBit(P16_A1_DPTX_VGIP_SIGINV, ~(_BIT3 | _BIT2), ((stMeasureSyncHV.b1VSP == _POSITIVE) ? 0x00 : _BIT3) | ((stMeasureSyncHV.b1HSP == _POSITIVE) ? 0x00 : _BIT2));
    }

    // Start auto
    ScalerSetBit(P16_CD_DPTX_AUTO_ADJ_CTRL1, ~_BIT0, _BIT0);

    // Wait for auto
    if(ScalerTimerPollingFlagProc(90, P16_CD_DPTX_AUTO_ADJ_CTRL1, _BIT0, 0x00) == _FALSE)
    {
        DebugMessageMst("Tx Measure Auto Failed", 0x00);

        return _FALSE;
    }

    // Update auto-function V result
    g_stDPTxInputTimingInfo.usVStart = (((WORD)(ScalerGetByte(P16_CE_DPTX_VER_START_END_H) & 0xF0) << 4) | ScalerGetByte(P16_CF_DPTX_VER_START_L));
    g_stDPTxInputTimingInfo.usVHeight = ((((WORD)(ScalerGetByte(P16_CE_DPTX_VER_START_END_H) & 0x0F) << 8) | ScalerGetByte(P16_D0_DPTX_VER_END_L))) - g_stDPTxInputTimingInfo.usVStart + 1;

    // Update auto-function H result (13-bit)
    g_stDPTxInputTimingInfo.usHStart = (((WORD)ScalerGetBit(P16_C8_DPTX_BLU_NOISE_MARGIN, _BIT1) << 11) |
                                        ((WORD)ScalerGetBit(P16_D1_DPTX_H_START_END_H, 0xF0) << 4) |
                                        (ScalerGetByte(P16_D2_DPTX_H_START_L))) + 1;
    g_stDPTxInputTimingInfo.usHWidth = (((WORD)ScalerGetBit(P16_C8_DPTX_BLU_NOISE_MARGIN, _BIT0) << 12) |
                                        ((WORD)ScalerGetBit(P16_D1_DPTX_H_START_END_H, 0x0F) << 8) |
                                        (ScalerGetByte(P16_D3_DPTX_H_END_L))) + 1;
    g_stDPTxInputTimingInfo.usHWidth = g_stDPTxInputTimingInfo.usHWidth - g_stDPTxInputTimingInfo.usHStart + 1;

    // Update off-line measure result
    g_stDPTxInputTimingInfo.b1HSP = stMeasureSyncHV.b1HSP;
    g_stDPTxInputTimingInfo.b1VSP = stMeasureSyncHV.b1VSP;
    g_stDPTxInputTimingInfo.usHSWidth = ((DWORD)((stMeasureSyncHV.b1HSP == _TRUE) ? stMeasureSyncHV.usHSWidth : (stMeasureSyncHV.usHSPeriod - stMeasureSyncHV.usHSWidth)) * GET_DP_TX_INPUT_PIXEL_CLK() * 100) / _MEASURE_CLK;
    g_stDPTxInputTimingInfo.usVSWidth = ((stMeasureSyncHV.b1VSP == _TRUE) ? stMeasureSyncHV.usVSWidth : (stMeasureSyncHV.usVSPeriod - stMeasureSyncHV.usVSWidth));
    g_stDPTxInputTimingInfo.usVTotal = stMeasureSyncHV.usVSPeriod;
    g_stDPTxInputTimingInfo.usHTotal = stMeasureSyncHV.usHTotal;
    g_stDPTxInputTimingInfo.usHFreq = (_MEASURE_CLK * 10 * 2 / stMeasureSyncHV.usHSPeriod + 1) / 2;
    g_stDPTxInputTimingInfo.usVFreq = (_MEASURE_CLK * 1000 * 10 * 2 / stMeasureSyncHV.usHSPeriod / stMeasureSyncHV.usVSPeriod + 1) / 2;

    DebugMessageMst("Tx Measure Done!!", 0x00);

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Tx Clone Check Interlace VTotal Odd
// Input Value  : None
// Output Value : _ODD/ _EVEN
//--------------------------------------------------
bit ScalerDpTxCloneCheckInterlaceVtotal(void)
{
    // Enable One Frame Measure
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~_BIT0, 0x00);
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~_BIT0, _BIT0);

    ScalerTimerPollingFlagProc(90, P16_42_DPTX_MEAS_CTL1, _BIT7, 0x00);

    // Pop up measurement result
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~_BIT6, _BIT6);

    // VSync Period
    PDATA_WORD(0) = ((((WORD)ScalerGetByte(P16_48_DPTX_MEAS_VS_PERIOD_A_M) & 0x0F) << 8) | (ScalerGetByte(P16_49_DPTX_MEAS_VS_PERIOD_A_L))) + 1;

    // Delay One Frame Plus 2ms Margin
    ScalerTimerDelayXms(10000 / g_stDPTxInputTimingInfo.usVFreq + 2);

    // Pop up measurement result
    ScalerSetBit(P16_42_DPTX_MEAS_CTL1, ~_BIT6, _BIT6);

    // VSync Period
    PDATA_WORD(1) = ((((WORD)ScalerGetByte(P16_48_DPTX_MEAS_VS_PERIOD_A_M) & 0x0F) << 8) | (ScalerGetByte(P16_49_DPTX_MEAS_VS_PERIOD_A_L))) + 1;

    DebugMessageMst("Clone Check Interlace Vtotal 1", PDATA_WORD(0));
    DebugMessageMst("Clone Check Interlace Vtotal 2", PDATA_WORD(1));

    if(PDATA_WORD(0) == PDATA_WORD(1))
    {
        return _EVEN;
    }
    else
    {
        // Set VTotal As the Smaller One
        g_stDPTxInputTimingInfo.usVTotal = (PDATA_WORD(0) < PDATA_WORD(1)) ? PDATA_WORD(0) : PDATA_WORD(1);
    }

    return _ODD;
}

//--------------------------------------------------
// Description  : Set Format Conversion for DP Tx Input
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerDpTxCloneSwitchFormatConversionMux(BYTE ucInputPort)
{
    // Set Format Conversion for DP Tx Input
    switch(ucInputPort)
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
        case _A1_INPUT_PORT:
        case _A2_INPUT_PORT:

            // Set source index to A0
            ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_ADC << 4));
            break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif
            // Set source index to D0
            ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D0 << 4));

#if((_AUDIO_SUPPORT == _ON) && (_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _OFF))
            // Set Audio Input Port for DP Tx
            ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), _AUDIO_FROM_D0_PORT);
#endif
            break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:

            // Set source index to D1
            ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D1 << 4));

#if((_AUDIO_SUPPORT == _ON) && (_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _OFF))
            // Set Audio Input Port for DP Tx
            ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), _AUDIO_FROM_D1_PORT);
#endif
            break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)
            // Modify input port select for dual-DVI cases
            if(ScalerDualLinkDVIRx2GetDualDVIMode() == _FALSE)
            {
                // Set source index to D3
                ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D3 << 4));
            }
            else
#endif
            {
                // Set source index to D2
                ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D2 << 4));
            }

#if((_AUDIO_SUPPORT == _ON) && (_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _OFF))
            // Set Audio Input Port for DP Tx
            ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), _AUDIO_FROM_D2_PORT);
#endif
            break;
#endif

#if(_D3_INPUT_PORT_TYPE != _D3_NO_PORT)
        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)
            // Set source index to D4
            ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D4 << 4));
#else
            // Set source index to D3
            ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D3 << 4));
#endif

#if((_AUDIO_SUPPORT == _ON) && (_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _OFF))
            // Set Audio Input Port for DP Tx
            ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), _AUDIO_FROM_D3_PORT);
#endif
            break;
#endif

#if(_D4_INPUT_PORT_TYPE != _D4_NO_PORT)
        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)
            // Modify input port select for dual-DVI cases
            if(ScalerDualLinkDVIRx4GetDualDVIMode() == _FALSE)
            {
                // Set source index to D5
                ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D5 << 4));
            }
            else
#endif
            {
                // Set source index to D4
                ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D4 << 4));
            }

#if((_AUDIO_SUPPORT == _ON) && (_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _OFF))
            // Set Audio Input Port for DP Tx
            ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), _AUDIO_FROM_D4_PORT);
#endif
            break;
#endif

#if(_D5_INPUT_PORT_TYPE != _D5_NO_PORT)
        case _D5_INPUT_PORT:

            // Set source index to D5
            ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_D5 << 4));

#if((_AUDIO_SUPPORT == _ON) && (_LINE_IN_AUDIO_DP_TX_CLONE_SUPPORT == _OFF))
            // Set Audio Input Port for DP Tx
            ScalerSetBit(P6F_02_MUX_DP_I2S_IN, ~(_BIT2 | _BIT1 | _BIT0), _AUDIO_FROM_D5_PORT);
#endif
            break;
#endif

        default:
            break;
    }
}

#endif // End for #if(_DP_SUPPORT == _ON)
