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
// ID Code      : ScalerDPRx1_INT_SeptPhy.c No.0000
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
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
BYTE ScalerDpRx1GetDpcdBitInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
BYTE ScalerDpRx1GetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
void ScalerDpRx1SetDpcdBitValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
void ScalerDpRx1SetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
void ScalerDpRx1SinkStatusSet_EXINT0(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
BYTE ScalerDpRx1TrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType);
BYTE ScalerDpRx1TrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType);
void ScalerDpRx1TrainingPatternEnd_EXINT0(void);

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
void ScalerDpRx1HDCPResetDpcdInfo_EXINT0(void);
void ScalerDpRx1HDCPResetKsvFifoToFirst_EXINT0(void);
void ScalerDpRx1HDCPSetKsvFifo_EXINT0(void);
#endif

#if(_WD_TIMER_INT_SUPPORT == _ON)
BYTE ScalerDpRx1GetDpcdInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
#endif

BYTE ScalerDpRx1Tp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);
BYTE ScalerDpRx1Tp2Check_EXINT0(EnumDpLinkTrainingType enumDpLtType);

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
//--------------------------------------------------
// Description  : Get DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpRx1GetDpcdBitInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit) using 1
{
    ScalerSetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);

    return ScalerGetBit_EXINT(PBA_C4_DPCD_DATA_PORT, ucDpcdBit);
}
//--------------------------------------------------
// Description  : Get DPCD Table Information in INT0
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpRx1GetDpcdInfo_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL) using 1
{
    ScalerSetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);

    return ScalerGetByte_EXINT(PBA_C4_DPCD_DATA_PORT);
}
//--------------------------------------------------
// Description  : Set DPCD Table Information in INT0
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetDpcdBitValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit) using 1
{
    ScalerSetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);
    ScalerSetBit_EXINT(PBA_C4_DPCD_DATA_PORT, ~(~ucNotDpcdBit), ucDpcdBit);
}
//--------------------------------------------------
// Description  : Set DPCD Table Information in INT0
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue) using 1
{
    ScalerSetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);
    ScalerSetByte_EXINT(PBA_C4_DPCD_DATA_PORT, ucDpcdValue);
}
//--------------------------------------------------
// Description  : DP Sink Status Setting in EXINT
// Input Value  : Receive Port, Sync Status
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SinkStatusSet_EXINT0(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync) using 1
{
    if(enumInSync == _DP_SINK_IN_SYNC)
    {
        if(enumReceiverPort == _DP_SINK_REVEICE_PORT0)
        {
            // Set Receive Port 0 in Sync
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x05) | _BIT0));
        }
        else if(enumReceiverPort == _DP_SINK_REVEICE_PORT1)
        {
            // Set Receive Port 1 in Sync
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x05) | _BIT1));
        }
    }
    else
    {
        if(enumReceiverPort == _DP_SINK_REVEICE_PORT0)
        {
            // Set Receive Port 0 Out of Sync
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x05) & ~_BIT0));
        }
        else if(enumReceiverPort == _DP_SINK_REVEICE_PORT1)
        {
            // Set Receive Port 1 Out of Sync
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x05) & ~_BIT1));
        }
    }
}
//--------------------------------------------------
// Description  : Check Dp Training Pattern 1
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
BYTE ScalerDpRx1TrainingPattern1_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
    if(ScalerDpRx1GetDpcdBitInfo_EXINT0(0x00, 0x00, 0x0E, _BIT7) == _BIT7)
    {
        if(g_ucDpRx1LinkRate > _D1_DP_LINK_CLK_RATE)
        {
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

            return _FALSE;
        }
    }
    else
#endif
    {
        if(g_ucDpRx1LinkRate > ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x00, 0x01))
        {
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

            return _FALSE;
        }
    }

    if(enumDpLtType == _DP_NORMAL_LT)
    {
        ScalerDpRx1Tp1SetPhy_EXINT0(_DP_NF_REF_XTAL);
    }

    if(ScalerDpRx1Tp1Check_EXINT0(enumDpLtType) == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Check Dp Training Pattern 2
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP2 Pass
//--------------------------------------------------
BYTE ScalerDpRx1TrainingPattern2_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{
    if(enumDpLtType == _DP_NORMAL_LT)
    {
        ScalerDpRx1Tp2SetPhy_EXINT0();
    }

    if(ScalerDpRx1Tp2Check_EXINT0(enumDpLtType) == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Settings after Link Training Pass
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1TrainingPatternEnd_EXINT0(void) using 1
{
    switch(g_ucDpRx1LaneCount)
    {
        case _DP_ONE_LANE:
            ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT3);
            break;

        case _DP_TWO_LANE:
            ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT4);
            break;

        case _DP_FOUR_LANE:
        default:
            ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
            break;
    }

    // De-Skew Circuit Reset
    ScalerSetBit_EXINT(PB0_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit_EXINT(PB0_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), _BIT6);

    if((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x01) & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);
    }
    else
    {
        // Disable Enhancement Control Mode --> MAC
        ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT2, 0x00);
    }

    if((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x02) & _BIT5) == _BIT5)
    {
        // Disable Scrambling
        ScalerSetBit_EXINT(PB0_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);
    }
    else
    {
        // Enable Scrambling
        ScalerSetBit_EXINT(PB0_07_SCRAMBLE_CTRL, ~_BIT5, 0x00);
    }
}

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Reset Dp Rx HDCP info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPResetDpcdInfo_EXINT0(void) using 1
{
    // Check if nead to clear HDCP dpcd info
    if((ScalerDpRx1GetDpcdInfo_EXINT0(0x06, 0x80, 0x2A) != 0x00) || (ScalerDpRx1GetDpcdInfo_EXINT0(0x06, 0x80, 0x2B) != 0x00))
    {
        ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, 0x29, 0x00);
        ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, 0x2A, 0x00);
        ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, 0x2B, 0x00);

        for(pData_EXINT[0] = 0; pData_EXINT[0] < 20; pData_EXINT[0]++)
        {
            ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, (0x14 + pData_EXINT[0]), 0x00);
        }

        for(pData_EXINT[0] = 0; pData_EXINT[0] < 15; pData_EXINT[0]++)
        {
            ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, (0x2C + pData_EXINT[0]), 0x00);
        }

        // Waiting for R0 Calculate Finish
        for(g_ucDpRx1Temp = 0; g_ucDpRx1Temp <= 40; g_ucDpRx1Temp++)
        {
            Delay5us_EXINT(g_ucDelay5usN);
        }

        ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, 0x29, 0x02);
    }
}
//--------------------------------------------------
// Description  : Load KSV List to Rx KSV FIFO
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPResetKsvFifoToFirst_EXINT0(void) using 1
{
    for(g_usDpRx1HdcpKsvFifoOffset = 0; g_usDpRx1HdcpKsvFifoOffset < 15; g_usDpRx1HdcpKsvFifoOffset++)
    {
        ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, (0x2C + g_usDpRx1HdcpKsvFifoOffset), g_pucDpTxHdcpKsvFifo[g_usDpRx1HdcpKsvFifoOffset]);
    }
}
//--------------------------------------------------
// Description  : Load KSV List to Rx KSV FIFO
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPSetKsvFifo_EXINT0(void) using 1
{
    for(pData_EXINT[0] = 0; pData_EXINT[0] < 15; pData_EXINT[0]++)
    {
        ScalerDpRx1SetDpcdValue_EXINT0(0x06, 0x80, (0x2C + pData_EXINT[0]), g_pucDpTxHdcpKsvFifo[g_usDpRx1HdcpKsvFifoOffset + pData_EXINT[0]]);
    }

    g_usDpRx1HdcpKsvFifoOffset += pData_EXINT[0];
}

#endif // End of #if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))

#if(_WD_TIMER_INT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DPCD Table Information in WDINT
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpRx1GetDpcdInfo_WDINT(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL) using 3
{
    ScalerSetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);

    return ScalerGetByte_EXINT(PBA_C4_DPCD_DATA_PORT);
}
#endif

//--------------------------------------------------
// Description  : Check Dp Training Pattern 1
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
BYTE ScalerDpRx1Tp1Check_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{
    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x00);
    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);
    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

    if(enumDpLtType == _DP_NORMAL_LT)
    {
        if((GET_DP_RX1_LINK_TRAINING_STATUS() != _DP_NORMAL_TRAINING_PATTERN_1_FAIL) && (GET_DP_RX1_LINK_TRAINING_STATUS() != _DP_FAKE_TRAINING_PATTERN_1_FAIL))
        {
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x03, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x04, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x05, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x06, 0x00);

            g_ucDpRx1LinkRequest01 = 0x00;
            g_ucDpRx1LinkRequest23 = 0x00;

#if(_DP_HBR_RBR_LT_FORCE_MARGINAL_LINK == _ON)

            SET_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR();
            SET_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR();
            SET_DP_RX_D1_LANE2_MARGIN_LINK_HBR_RBR();
            SET_DP_RX_D1_LANE3_MARGIN_LINK_HBR_RBR();
#else
            if(GET_DP_RX_D1_MARGIN_LINK_HBR_RBR() == _TRUE)
            {
                SET_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR();
                SET_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR();
                SET_DP_RX_D1_LANE2_MARGIN_LINK_HBR_RBR();
                SET_DP_RX_D1_LANE3_MARGIN_LINK_HBR_RBR();
            }
            else
            {
                CLR_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR();
                CLR_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR();
                CLR_DP_RX_D1_LANE2_MARGIN_LINK_HBR_RBR();
                CLR_DP_RX_D1_LANE3_MARGIN_LINK_HBR_RBR();
            }
#endif
        }

        pData_EXINT[0] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x03);
        pData_EXINT[1] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x04);
        pData_EXINT[2] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x05);
        pData_EXINT[3] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x06);

        g_ucDpRx1LinkStatus01 = 0;
        g_ucDpRx1LinkStatus23 = 0;

        switch(g_ucDpRx1LaneCount)
        {
            case _DP_FOUR_LANE:

                // Read Back Lane2 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE2 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane2 Check
                if(((GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[2] & _BIT2) == _BIT2) || ((pData_EXINT[2] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x01;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE2_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[2] & (_BIT1 | _BIT0)) >= (g_ucDpRx1LinkRequest23 & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x01;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                                CLR_DP_RX_D1_LANE2_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else if(((pData_EXINT[2] & _BIT2) == _BIT2) || ((pData_EXINT[2] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x01;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[2] & _BIT2) == _BIT2) && ((pData_EXINT[2] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x01;
                    }
                    else if(((pData_EXINT[2] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[2] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                // Read Back Lane3 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE3 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane3 Check
                if(((GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[3] & _BIT2) == _BIT2) || ((pData_EXINT[3] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x10;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE3_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[3] & (_BIT1 | _BIT0)) >= ((g_ucDpRx1LinkRequest23 >> 4) & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x10;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] << 4) & (_BIT5 | _BIT4))) + 0x10;
                                CLR_DP_RX_D1_LANE3_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] << 4) & (_BIT5 | _BIT4))) + 0x10;
                        }
                    }
                    else if(((pData_EXINT[3] & _BIT2) == _BIT2) || ((pData_EXINT[3] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x10;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[3] & _BIT2) == _BIT2) && ((pData_EXINT[3] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x10;
                    }
                    else if(((pData_EXINT[3] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[3] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }

                // Read Back Lane1 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE1 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane1 Check
                if(((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= ((g_ucDpRx1LinkRequest01 >> 4) & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                                CLR_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                        }
                    }
                    else if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[1] & _BIT2) == _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                    }
                    else if(((pData_EXINT[1] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[1] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }

                // Read Back Lane0 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE0 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane0 Check
                if(((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (g_ucDpRx1LinkRequest01 & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                                CLR_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[0] & _BIT2) == _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                    }
                    else if(((pData_EXINT[0] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[0] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                break;

            case _DP_TWO_LANE:

                // Read Back Lane1 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE1 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane1 Check
                if(((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= ((g_ucDpRx1LinkRequest01 >> 4) & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                                CLR_DP_RX_D1_LANE1_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                        }
                    }
                    else if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[1] & _BIT2) == _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x10;
                    }
                    else if(((pData_EXINT[1] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[1] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                    }
                }

                // Read Back Lane0 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE0 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane0 Check
                if(((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (g_ucDpRx1LinkRequest01 & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                                CLR_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[0] & _BIT2) == _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                    }
                    else if(((pData_EXINT[0] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[0] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                break;

            case _DP_ONE_LANE:
            default:

                // Read Back Lane0 Vth
                ScalerSetBit_EXINT(P7A_F2_COEF_3, ~(_BIT7 | _BIT6), (_D1_DP_LANE0 << 6));

                ScalerSetBit_EXINT(P7A_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

                // Lane0 Check
                if(((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT4) == _BIT4)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT5) == _BIT5)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT6) == _BIT6)) ||
                   ((GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit_EXINT(PB0_14_EQ_CRC_3, _BIT7) == _BIT7)))
                {
                    if(g_ucDpRx1LinkRate <= _DP_LINK_HBR)
                    {
                        if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= _BIT1))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                        }
                        else if((ScalerGetByte_EXINT(P7A_F1_COEF_2) & 0x0F) > 3)
                        {
                            if((GET_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR() == _FALSE) &&
                               ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (g_ucDpRx1LinkRequest01 & (_BIT1 | _BIT0))))
                            {
                                g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                            }
                            else
                            {
                                g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                                CLR_DP_RX_D1_LANE0_MARGIN_LINK_HBR_RBR();
                            }
                        }
                        else
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= _BIT1))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                    }
                    else
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if((g_ucDpRx1LinkRate == _DP_LINK_HBR2) && (((pData_EXINT[0] & _BIT2) == _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) == _BIT1)))
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x01;
                    }
                    else if(((pData_EXINT[0] & _BIT2) != _BIT2) &&
                            ((pData_EXINT[0] & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                break;
        }

        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, g_ucDpRx1LinkStatus01);
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, g_ucDpRx1LinkStatus23);
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, g_ucDpRx1LinkRequest23);

        switch(g_ucDpRx1LaneCount)
        {
            case _DP_ONE_LANE:

                if((g_ucDpRx1LinkStatus01 & _BIT0) == _BIT0)
                {
                    return _TRUE;
                }

                break;

            case _DP_TWO_LANE:

                if((g_ucDpRx1LinkStatus01 & (_BIT4 | _BIT0)) == (_BIT4 | _BIT0))
                {
                    return _TRUE;
                }

                break;

            case _DP_FOUR_LANE:
            default:

                if(((g_ucDpRx1LinkStatus01 & (_BIT4 | _BIT0)) == (_BIT4 | _BIT0)) && (((g_ucDpRx1LinkStatus23 & (_BIT4 | _BIT0)) == (_BIT4 | _BIT0))))
                {
                    return _TRUE;
                }

                break;
        }
    }
    else
    {
        if(GET_DP_RX1_LINK_TRAINING_STATUS() != _DP_FAKE_TRAINING_PATTERN_1_FAIL)
        {
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x03, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x04, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x05, 0x00);
            ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x01, 0x06, 0x00);
        }

        pData_EXINT[0] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x03);
        pData_EXINT[1] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x04);
        pData_EXINT[2] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x05);
        pData_EXINT[3] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x06);

        g_ucDpRx1LinkRequest01 = (pData_EXINT[0] & 0x03) | ((pData_EXINT[1] << 4) & 0x30);
        g_ucDpRx1LinkRequest23 = (pData_EXINT[2] & 0x03) | ((pData_EXINT[3] << 4) & 0x30);

        switch(g_ucDpRx1LaneCount)
        {
            case _DP_ONE_LANE:

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);

                if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0))))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x01);

                    return _TRUE;
                }

                break;

            case _DP_TWO_LANE:

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);

                if((((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) == ((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) >> 4) & (_BIT1 | _BIT0)))))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);

                    return _TRUE;
                }

                break;

            case _DP_FOUR_LANE:
            default:

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }

                    if(((pData_EXINT[2] & _BIT2) != _BIT2) && ((pData_EXINT[2] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[3] & _BIT2) != _BIT2) && ((pData_EXINT[3] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }

                    if(((pData_EXINT[2] & _BIT2) != _BIT2) && ((pData_EXINT[2] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[3] & _BIT2) != _BIT2) && ((pData_EXINT[3] & (_BIT1 | _BIT0)) < _BIT0))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, g_ucDpRx1LinkRequest23);

                if((((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) == ((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) >> 4) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[2] & _BIT2) == _BIT2) || ((pData_EXINT[2] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x07) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[3] & _BIT2) == _BIT2) || ((pData_EXINT[3] & (_BIT1 | _BIT0)) == ((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x07) >> 4) & (_BIT1 | _BIT0)))))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x11);

                    return _TRUE;
                }

                break;
        }
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Check Dp Training Pattern 2
// Input Value  : Normal or Fake LT
// Output Value : TRUE --> TP2 Pass
//--------------------------------------------------
BYTE ScalerDpRx1Tp2Check_EXINT0(EnumDpLinkTrainingType enumDpLtType) using 1
{
    BYTE ucEQCRCStatus = 0;
    BYTE ucEQCRCStatus1 = 0;
    BYTE ucEQCRCStatus2 = 0;

    pData_EXINT[0] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x03);
    pData_EXINT[1] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x04);
    pData_EXINT[2] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x05);
    pData_EXINT[3] = ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x01, 0x06);

    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

    if(enumDpLtType == _DP_NORMAL_LT)
    {
        // Clear 8b/10b Decode Error
        ScalerSetBit_EXINT(PB0_06_DECODE_10B8B_ERROR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

        g_ucDpRx1LinkRequest01 = ((pData_EXINT[0] & 0x03) |
                                  ((pData_EXINT[0] >> 1) & 0x0C) |
                                  ((pData_EXINT[1] << 4) & 0x30) |
                                  ((pData_EXINT[1] << 3) & 0xC0));

        g_ucDpRx1LinkRequest23 = ((pData_EXINT[2] & 0x03) |
                                  ((pData_EXINT[2] >> 1) & 0x0C) |
                                  ((pData_EXINT[3] << 4) & 0x30) |
                                  ((pData_EXINT[3] << 3) & 0xC0));

        // Enable EQ-CRC and Clear EQ-CRC Status(- K28.5)
        ScalerSetBit_EXINT(PB0_12_EQ_CRC_1, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

        for(g_ucDpRx1Temp = 0; g_ucDpRx1Temp <= 2; g_ucDpRx1Temp++)
        {
            Delay5us_EXINT(g_ucDelay5usN);
        }

        ucEQCRCStatus1 = ScalerGetByte_EXINT(PB0_12_EQ_CRC_1);

        if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
        {
            for(g_ucDpRx1Temp = 0; g_ucDpRx1Temp <= 30; g_ucDpRx1Temp++)
            {
                ucEQCRCStatus1 = ucEQCRCStatus1 & ScalerGetByte_EXINT(PB0_12_EQ_CRC_1);
            }
        }
        else
        {
            for(g_ucDpRx1Temp = 0; g_ucDpRx1Temp <= 5; g_ucDpRx1Temp++)
            {
                ucEQCRCStatus1 = ucEQCRCStatus1 & ScalerGetByte_EXINT(PB0_12_EQ_CRC_1);
            }
        }

        // Disable EQ-CRC
        ScalerSetBit_EXINT(PB0_12_EQ_CRC_1, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

        // Enable EQ-CRC and Clear EQ-CRC Status(+ K28.5)
        ScalerSetBit_EXINT(PB0_12_EQ_CRC_1, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

        for(g_ucDpRx1Temp = 0; g_ucDpRx1Temp <= 2; g_ucDpRx1Temp++)
        {
            Delay5us_EXINT(g_ucDelay5usN);
        }

        ucEQCRCStatus2 = ScalerGetByte_EXINT(PB0_12_EQ_CRC_1);

        for(g_ucDpRx1Temp = 0; g_ucDpRx1Temp <= 5; g_ucDpRx1Temp++)
        {
            ucEQCRCStatus2 = ucEQCRCStatus2 & ScalerGetByte_EXINT(PB0_12_EQ_CRC_1);
        }

        // Disable EQ-CRC
        ScalerSetBit_EXINT(PB0_12_EQ_CRC_1, ~(_BIT7 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

        ucEQCRCStatus = (ucEQCRCStatus1 | ucEQCRCStatus2);

        g_ucDpRx1EQCRC = 0x00;

        if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
        {
            g_ucDpRx1EQCRC |= (ucEQCRCStatus & 0x01);
        }
        else if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x02) >> 1);
        }
        else if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x04) >> 2);
        }
        else if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x08) >> 3);
        }

        if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x01) << 1);
        }
        else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1)
        {
            g_ucDpRx1EQCRC |= (ucEQCRCStatus & 0x02);
        }
        else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x04) >> 1);
        }
        else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x08) >> 2);
        }

        if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE0)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x01) << 2);
        }
        else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE1)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x02) << 1);
        }
        else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE2)
        {
            g_ucDpRx1EQCRC |= (ucEQCRCStatus & 0x04);
        }
        else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE3)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x08) >> 1);
        }

        if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE0)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x01) << 3);
        }
        else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE1)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x02) << 2);
        }
        else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE2)
        {
            g_ucDpRx1EQCRC |= ((ucEQCRCStatus & 0x04) << 1);
        }
        else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE3)
        {
            g_ucDpRx1EQCRC |= (ucEQCRCStatus & 0x08);
        }

        ucEQCRCStatus = g_ucDpRx1EQCRC;

        if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
        {
            if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
            {
                ucEQCRCStatus |= _BIT0;
            }

            if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
            {
                ucEQCRCStatus |= _BIT1;
            }

            if(((pData_EXINT[2] & _BIT2) == _BIT2) || ((pData_EXINT[2] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
            {
                ucEQCRCStatus |= _BIT2;
            }

            if(((pData_EXINT[3] & _BIT2) == _BIT2) || ((pData_EXINT[3] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
            {
                ucEQCRCStatus |= _BIT3;
            }
        }
        else
        {
            if(g_ucDpRx1TrainingPatternSet == _DP_TRAINING_PATTERN_3)
            {
                if(ScalerGetBit_EXINT(PB0_06_DECODE_10B8B_ERROR, _BIT0) == 0x00)
                {
                    if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0)
                    {
                        ucEQCRCStatus |= _BIT0;
                    }
                    else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0)
                    {
                        ucEQCRCStatus |= _BIT1;
                    }
                    else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE0)
                    {
                        ucEQCRCStatus |= _BIT2;
                    }
                    else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE0)
                    {
                        ucEQCRCStatus |= _BIT3;
                    }
                }

                if(ScalerGetBit_EXINT(PB0_06_DECODE_10B8B_ERROR, _BIT1) == 0x00)
                {
                    if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1)
                    {
                        ucEQCRCStatus |= _BIT0;
                    }
                    else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1)
                    {
                        ucEQCRCStatus |= _BIT1;
                    }
                    else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE1)
                    {
                        ucEQCRCStatus |= _BIT2;
                    }
                    else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE1)
                    {
                        ucEQCRCStatus |= _BIT3;
                    }
                }

                if(ScalerGetBit_EXINT(PB0_06_DECODE_10B8B_ERROR, _BIT2) == 0x00)
                {
                    if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2)
                    {
                        ucEQCRCStatus |= _BIT0;
                    }
                    else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2)
                    {
                        ucEQCRCStatus |= _BIT1;
                    }
                    else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE2)
                    {
                        ucEQCRCStatus |= _BIT2;
                    }
                    else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE2)
                    {
                        ucEQCRCStatus |= _BIT3;
                    }
                }

                if(ScalerGetBit_EXINT(PB0_06_DECODE_10B8B_ERROR, _BIT3) == 0x00)
                {
                    if(GET_DP_RX1_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3)
                    {
                        ucEQCRCStatus |= _BIT0;
                    }
                    else if(GET_DP_RX1_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3)
                    {
                        ucEQCRCStatus |= _BIT1;
                    }
                    else if(GET_DP_RX1_PCB_LANE2_MAPPING() == _DP_SCALER_LANE3)
                    {
                        ucEQCRCStatus |= _BIT2;
                    }
                    else if(GET_DP_RX1_PCB_LANE3_MAPPING() == _DP_SCALER_LANE3)
                    {
                        ucEQCRCStatus |= _BIT3;
                    }
                }
            }
        }

        switch(g_ucDpRx1LaneCount)
        {
            case _DP_FOUR_LANE:

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if((ucEQCRCStatus & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) != (_BIT3 | _BIT2 | _BIT1 | _BIT0))
                    {
                        ucEQCRCStatus &= ~(_BIT3 | _BIT2 | _BIT1 | _BIT0);
                    }
                }

                // Lane2 EQ-CRC Check
                if((ucEQCRCStatus & _BIT2) == _BIT2)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[2] & _BIT2) == _BIT2) || ((pData_EXINT[2] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x07;
                        }
                        else if((ucEQCRCStatus & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == (_BIT3 | _BIT2 | _BIT1 | _BIT0))
                        {
                            g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x07;
                    }
                }
                else
                {
                    if(((pData_EXINT[2] & _BIT5) != _BIT5) &&
                       (((g_ucDpRx1LinkRequest23 & 0x03) + ((g_ucDpRx1LinkRequest23 >> 2) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest23 = g_ucDpRx1LinkRequest23 + 0x04;
                    }
                }

                // Lane3 EQ-CRC Check
                if((ucEQCRCStatus & _BIT3) == _BIT3)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[3] & _BIT2) == _BIT2) || ((pData_EXINT[3] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x70;
                        }
                        else if((ucEQCRCStatus & (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == (_BIT3 | _BIT2 | _BIT1 | _BIT0))
                        {
                            g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] << 4) & (_BIT5 | _BIT4))) + 0x10;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus23 = g_ucDpRx1LinkStatus23 | 0x70;
                    }
                }
                else
                {
                    if(((pData_EXINT[3] & _BIT5) != _BIT5) &&
                       ((((g_ucDpRx1LinkRequest23 >> 4) & 0x03) + ((g_ucDpRx1LinkRequest23 >> 6) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest23 = g_ucDpRx1LinkRequest23 + 0x40;
                    }
                }

                // Lane1 EQ-CRC Check
                if((ucEQCRCStatus & _BIT1) == _BIT1)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x70;
                        }
                        else if((ucEQCRCStatus & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x70;
                    }
                }
                else
                {
                    if(((pData_EXINT[1] & _BIT5) != _BIT5) &&
                       ((((g_ucDpRx1LinkRequest01 >> 4) & 0x03) + ((g_ucDpRx1LinkRequest01 >> 6) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest01 = g_ucDpRx1LinkRequest01 + 0x40;
                    }
                }

                // Lane0 EQ-CRC Check
                if((ucEQCRCStatus & _BIT0) == _BIT0)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x07;
                        }
                        else if((ucEQCRCStatus & _BIT0) == _BIT0)
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x07;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT5) != _BIT5) &&
                       (((g_ucDpRx1LinkRequest01 & 0x03) + ((g_ucDpRx1LinkRequest01 >> 2) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest01 = g_ucDpRx1LinkRequest01 + 0x04;
                    }
                }

                break;

            case _DP_TWO_LANE:

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if((ucEQCRCStatus & (_BIT1 | _BIT0)) != (_BIT1 | _BIT0))
                    {
                        ucEQCRCStatus &= ~(_BIT1 | _BIT0);
                    }
                }

                // Lane1 EQ-CRC Check
                if((ucEQCRCStatus & _BIT1) == _BIT1)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x70;
                        }
                        else if((ucEQCRCStatus & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] << 4) & (_BIT5 | _BIT4))) + 0x10;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x70;
                    }
                }
                else
                {
                    if(((pData_EXINT[1] & _BIT5) != _BIT5) &&
                       ((((g_ucDpRx1LinkRequest01 >> 4) & 0x03) + ((g_ucDpRx1LinkRequest01 >> 6) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest01 = g_ucDpRx1LinkRequest01 + 0x40;
                    }
                }

                // Lane0 EQ-CRC Check
                if((ucEQCRCStatus & _BIT0) == _BIT0)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x07;
                        }
                        else if((ucEQCRCStatus & _BIT0) == _BIT0)
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x07;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT5) != _BIT5) &&
                       (((g_ucDpRx1LinkRequest01 & 0x03) + ((g_ucDpRx1LinkRequest01 >> 2) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest01 = g_ucDpRx1LinkRequest01 + 0x04;
                    }
                }

                break;

            case _DP_ONE_LANE:
            default:

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if((ucEQCRCStatus & _BIT0) != _BIT0)
                    {
                        ucEQCRCStatus &= ~_BIT0;
                    }
                }

                // Lane0 EQ-CRC Check
                if((ucEQCRCStatus & _BIT0) == _BIT0)
                {
                    if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                    {
                        if(((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) >= (_BIT1 | _BIT0)))
                        {
                            g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x07;
                        }
                        else if((ucEQCRCStatus & _BIT0) == _BIT0)
                        {
                            g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                        }
                    }
                    else
                    {
                        g_ucDpRx1LinkStatus01 = g_ucDpRx1LinkStatus01 | 0x07;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT5) != _BIT5) &&
                       (((g_ucDpRx1LinkRequest01 & 0x03) + ((g_ucDpRx1LinkRequest01 >> 2) & 0x03)) < 3) &&
                       (g_ucDpRx1LinkRate <= _DP_LINK_HBR))
                    {
                        g_ucDpRx1LinkRequest01 = g_ucDpRx1LinkRequest01 + 0x04;
                    }
                }

                break;
        }

        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, g_ucDpRx1LinkStatus01);
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, g_ucDpRx1LinkStatus23);
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, g_ucDpRx1LinkRequest23);

        switch(g_ucDpRx1LaneCount)
        {
            case _DP_ONE_LANE:

                if((g_ucDpRx1LinkStatus01 & 0x07) == 0x07)
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);
                    return _TRUE;
                }

                break;

            case _DP_TWO_LANE:

                if((g_ucDpRx1LinkStatus01 & 0x77) == 0x77)
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);
                    return _TRUE;
                }

                break;

            case _DP_FOUR_LANE:
            default:

                if(((g_ucDpRx1LinkStatus01 & 0x77) == 0x77) && (((g_ucDpRx1LinkStatus23 & 0x77) == 0x77)))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);
                    return _TRUE;
                }

                break;
        }
    }
    else
    {
        ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x80);

        g_ucDpRx1LinkRequest01 = (pData_EXINT[0] & 0x03) | ((pData_EXINT[1] << 4) & 0x30);
        g_ucDpRx1LinkRequest23 = (pData_EXINT[2] & 0x03) | ((pData_EXINT[3] << 4) & 0x30);

        switch(g_ucDpRx1LaneCount)
        {
            case _DP_ONE_LANE:

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }
                }

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);

                if(((pData_EXINT[0] & _BIT5) == _BIT5) || ((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0))))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x07);
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);

                    return _TRUE;
                }

                break;

            case _DP_TWO_LANE:

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x00);

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, 0x00);

                if((((pData_EXINT[0] & _BIT5) == _BIT5) || ((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[1] & _BIT5) == _BIT5) || ((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) == ((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT5 | _BIT4)) >> 4))))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x77);
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);

                    return _TRUE;
                }

                break;

            case _DP_FOUR_LANE:
            default:

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x11);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x11);

                if(g_ucDpRx1LinkRate == _DP_LINK_HBR2)
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }

                    if(((pData_EXINT[2] & _BIT2) != _BIT2) && ((pData_EXINT[2] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[3] & _BIT2) != _BIT2) && ((pData_EXINT[3] & (_BIT1 | _BIT0)) < (_BIT1 | _BIT0)))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }
                else
                {
                    if(((pData_EXINT[0] & _BIT2) != _BIT2) && ((pData_EXINT[0] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xFC) | (pData_EXINT[0] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[1] & _BIT2) != _BIT2) && ((pData_EXINT[1] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest01 = ((g_ucDpRx1LinkRequest01 & 0xCF) | ((pData_EXINT[1] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }

                    if(((pData_EXINT[2] & _BIT2) != _BIT2) && ((pData_EXINT[2] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xFC) | (pData_EXINT[2] & (_BIT1 | _BIT0))) + 0x01;
                    }

                    if(((pData_EXINT[3] & _BIT2) != _BIT2) && ((pData_EXINT[3] & (_BIT1 | _BIT0)) < _BIT1))
                    {
                        g_ucDpRx1LinkRequest23 = ((g_ucDpRx1LinkRequest23 & 0xCF) | ((pData_EXINT[3] & (_BIT1 | _BIT0)) << 4)) + 0x10;
                    }
                }

                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x06, g_ucDpRx1LinkRequest01);
                ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x07, g_ucDpRx1LinkRequest23);

                if((((pData_EXINT[0] & _BIT5) == _BIT5) || ((pData_EXINT[0] & _BIT2) == _BIT2) || ((pData_EXINT[0] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[1] & _BIT5) == _BIT5) || ((pData_EXINT[1] & _BIT2) == _BIT2) || ((pData_EXINT[1] & (_BIT1 | _BIT0)) == ((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x06) & (_BIT5 | _BIT4)) >> 4))) &&
                   (((pData_EXINT[2] & _BIT5) == _BIT5) || ((pData_EXINT[2] & _BIT2) == _BIT2) || ((pData_EXINT[2] & (_BIT1 | _BIT0)) == (ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x07) & (_BIT1 | _BIT0)))) &&
                   (((pData_EXINT[3] & _BIT5) == _BIT5) || ((pData_EXINT[3] & _BIT2) == _BIT2) || ((pData_EXINT[3] & (_BIT1 | _BIT0)) == ((ScalerDpRx1GetDpcdInfo_EXINT0(0x00, 0x02, 0x07) & (_BIT5 | _BIT4)) >> 4))))
                {
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x02, 0x77);
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x03, 0x77);
                    ScalerDpRx1SetDpcdValue_EXINT0(0x00, 0x02, 0x04, 0x81);

                    return _TRUE;
                }

                break;
        }
    }

    return _FALSE;
}
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
