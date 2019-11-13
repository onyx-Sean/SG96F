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
// ID Code      : ScalerMHLRx2_SeptPhy.c No.0000
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
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
void ScalerMHLRx2DataPortInitial(void);
void ScalerMHLRx2DataPortInitial_EXINT0(void);
bit ScalerMHLRx2MscRCPGetCommand(BYTE *pucKeyCode);
void ScalerMHLRx2SetDevCapReg(void);
void ScalerMHLRx2SetTimingRelateSetting(void);
void ScalerMHLRx2TimerEventProc(EnumScalerTimerEventID enumEventID);

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
void ScalerMHLRx2CheckWriteBurst(void);
#endif

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
//--------------------------------------------------
// Description  : MHL Cbus Mac Data Port Reset Proc for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2DataPortInitial(void)
{
    // MSC channel manual mode enable
    ScalerSetBit(P2A_C8_CBUS_CTRL_28, ~_BIT7, _BIT7);

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

    // Initial the value in data port
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_80_ECBUS_SPEEDS, 0x03);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_81_TMDS_SPEEDS, 0x04);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_82_ECBUS_DEV_ROLES, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_83_LOG_DEV_MAPX, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_84_ACRFS_DIV_SUPPORT, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_90_CURR_ECBUS_MODE, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_91_AVLINK_MODE_STATUS, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_92_AVLINK_MODE_CONTROL, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_93_MULTI_SINK_STATUS, 0x00);

#endif // End of #if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_DCHANGE_INT, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_CONNECTED_RDY, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_LINK_MODE, 0x00);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_MHL_VERSION_STAT, 0x00);

    // MSC channel manual mode disable
    ScalerSetBit(P2A_C8_CBUS_CTRL_28, ~_BIT7, 0x00);
}
//--------------------------------------------------
// Description  : MHL Cbus Mac Data Port Reset Proc for D2 Port (For Interrupt)
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2DataPortInitial_EXINT0(void) using 1
{
    // MSC channel manual mode enable
    ScalerSetBit_EXINT(P2A_C8_CBUS_CTRL_28, ~_BIT7, _BIT7);

    pData_EXINT[0] = ScalerGetByte_EXINT(P2A_AB_CBUS_CTRL_0B);

    // Disable Port Auto-Inc
    ScalerSetBit_EXINT(P2A_AB_CBUS_CTRL_0B, ~_BIT0, 0x00);

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

    // Reset _MSC_80_ECBUS_SPEEDS
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x80);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x03);

    // Reset _MSC_81_TMDS_SPEEDS
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x81);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x04);

    // Reset _MSC_82_ECBUS_DEV_ROLES
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x82);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_83_LOG_DEV_MAPX
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x83);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_84_ACRFS_DIV_SUPPORT
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x84);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset CURR_ECBUS_MODE
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x90);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_91_AVLINK_MODE_STATUS
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x91);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_92_AVLINK_MODE_CONTROL
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x92);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_93_MULTI_SINK_STATUS
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x93);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

#endif // End of #if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

    // Reset _MSC_RCHANGE_INT
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x20);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_DCHANGE_INT
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x21);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_CONNECTED_READY
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x30);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_LINK_MODE
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x31);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Reset _MSC_MHL_VERSION_STAT
    ScalerSetByte_EXINT(P2A_AC_CBUS_CTRL_0C, 0x32);
    ScalerSetByte_EXINT(P2A_AD_CBUS_CTRL_0D, 0x00);

    // Enable Port Auto-Inc
    ScalerSetByte_EXINT(P2A_AB_CBUS_CTRL_0B, pData_EXINT[0]);

    // MSC channel manual mode disable
    ScalerSetBit_EXINT(P2A_C8_CBUS_CTRL_28, ~_BIT7, 0x00);
}
//--------------------------------------------------
// Description  : Get RCP Key Code for D2 Port
// Input Value  : RCP Key Code
// Output Value : True or False
//--------------------------------------------------
bit ScalerMHLRx2MscRCPGetCommand(BYTE *pucKeyCode)
{
    // Check RCP Command
    if((bit)ScalerGetBit(P2A_D4_CBUS_CTRL_34, _BIT6) == _TRUE)
    {
        // Clear Flag
        ScalerSetByte(P2A_D4_CBUS_CTRL_34, (BYTE)_BIT6);

        pucKeyCode[0] = ScalerGetByte(P2A_D9_CBUS_CTRL_39);

        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Set Devcap Registor Values
// Input Value  : Non
// Output Value : Non
//--------------------------------------------------
void ScalerMHLRx2SetDevCapReg(void)
{
    // ---------------------- DEV CAP Reg Setting ------------------------- //

    // Modify Device Capabilities according to MHL Version
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_MHL_VERSION_01, _D2_MHL_VERSION);

    // Set POWLIM DEVCAP Reg.
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_DEV_CAT_02, 0x31);

    // Adopter ID
#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_ADOPTER_ID_H_03, (BYTE)(((WORD)_MHL3_ADOPTER_ID >> 8) & 0x00FF));
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_ADOPTER_ID_L_04, (BYTE)(_MHL3_ADOPTER_ID & 0x00FF));
#else
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_ADOPTER_ID_H_03, (BYTE)(((WORD)_MHL2_ADOPTER_ID >> 8) & 0x00FF));
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_ADOPTER_ID_L_04, (BYTE)(_MHL2_ADOPTER_ID & 0x00FF));
#endif

    // Modify Packed Pixel Mode (2.0) and 16 Bits Mode (3.0) Support according to MHL Version
#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
    ScalerGetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_VID_LINK_MODE_05, 1, pData, _AUTOINC);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_VID_LINK_MODE_05, (pData[0] | ((BYTE)_MHL2_PP_MODE_SUPPORT << 3) | ((BYTE)_MHL3_16_BIT_MODE_SUPPORT << 6)));
#else
    ScalerSetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_VID_LINK_MODE_05, ~_BIT3, (BYTE)_MHL2_PP_MODE_SUPPORT << 3);
#endif

    // Modify Audio Link Mode and High-Bitrate Support according to MHL Version
#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
    ScalerSetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_AUD_LINK_MODE_06, ~(_BIT2 | _BIT1 | _BIT0), (_MHL3_AUD_HBR | _MHL3_AUD_CHANNEL));
#else
    ScalerSetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_AUD_LINK_MODE_06, ~(_BIT1 | _BIT0), _MHL2_AUD_CHANNEL);
#endif

    // Display Support
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_LOG_DEV_MAP_08, 0x01);

    // Modify RAP/RCP/UCP/RBP/XVYCC Support according to MHL Version
#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
    ScalerSetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_FEATURE_FLAG_0A, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE)_MHL3_RBP_SUPPORT << 6) | ((BYTE)_MHL3_XVYCC_SUPPORT << 5) | ((BYTE)_MHL3_UCP_SUPPORT << 4) | (_MHL3_UCP_SUPPORT << 3) | (_BIT2 | _BIT1 | _BIT0)));
#else
    ScalerSetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_FEATURE_FLAG_0A, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (((BYTE)_MHL2_UCP_SUPPORT << 4) | (_MHL2_UCP_SUPPORT << 3) | (_BIT2 | _BIT1 | _BIT0)));
#endif

    // Device ID
#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_DEVICE_ID_H_0B, (BYTE)(((WORD)_MHL3_DEVICE_ID >> 8) & 0x00FF));
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_DEVICE_ID_L_0C, (BYTE)(_MHL3_DEVICE_ID & 0x00FF));
#else
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_DEVICE_ID_H_0B, (BYTE)(((WORD)_MHL2_DEVICE_ID >> 8) & 0x00FF));
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_DEVICE_ID_L_0C, (BYTE)(_MHL2_DEVICE_ID & 0x00FF));
#endif

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

    // Indicate Sink Support eCBUS-S / 8bit TDM Slot
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_80_ECBUS_SPEEDS, 0x03);

    // Indicate Sink Support TMDS 1.5 / 3.0 / 6.0 Gbps Mode
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_81_TMDS_SPEEDS, 0x07);

    // HID Support
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_82_ECBUS_DEV_ROLES, (BYTE)((_MHL3_ECBUS_HID_SUPPORT << 4) & _BIT4));

    // Set Logical Device Map Registor
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_83_LOG_DEV_MAPX, 0x00);

    // Enable Devcap Reg FW Manual -> Manual Set _MSC_92_AVLINK_MODE_CONTROL to 0xFF -> Disable Devcap Reg FW Manual
    ScalerSetBit(P2A_C8_CBUS_CTRL_28, ~_BIT7, _BIT7);
    ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_92_AVLINK_MODE_CONTROL, _ECBUS_LINK_RATE_NULL);
    ScalerSetBit(P2A_C8_CBUS_CTRL_28, ~_BIT7, 0x00);

#endif // End of #if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
}
//--------------------------------------------------
// Description  : Set Devcap Registor Values
// Input Value  : Non
// Output Value : Non
//--------------------------------------------------
void ScalerMHLRx2SetTimingRelateSetting(void)
{
    // ------------- Re-Set Timing Related Setting After oCBUS -> eCBUS Switch ---------- //

    // Gate CBUS System Clk First (In Case of Digital Clk Glitch)
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT5, 0x00);

    // MHL System Clk select to IOSC (Bypass GDI Clk)
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT4, _BIT4);
    ScalerSetBit(P2A_A2_CBUS_CTRL_02, ~_BIT2, 0x00);

    // Clear Wake Up Pulses Flag
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT3, _BIT3);

    // Sys Clk Divider
    ScalerSetBit(P2A_A1_CBUS_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Disable Debounce For Core Function
    ScalerSetBit(P2A_A2_CBUS_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Enable oCBUS Priority Option for MHL2.2 CTS
    ScalerSetBit(P2A_AB_CBUS_CTRL_0B, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT7 | _BIT6));

    // Upper Bound of SYNC Pulse Low Time Period
    ScalerSetByte(P2A_AF_CBUS_CTRL_0F, 0x35);

    // Lower Bound of SYNC Pulse Low Time Period
    ScalerSetByte(P2A_B0_CBUS_CTRL_10, 0x20);

    // Upper Bound of SYNC Pulse High Time Period
    ScalerSetByte(P2A_B1_CBUS_CTRL_11, 0x14);

    // Lower Bound of SYNC Pulse High Time Period
    ScalerSetByte(P2A_B2_CBUS_CTRL_12, 0x09);

    // Absolute Threshold Time
    ScalerSetByte(P2A_B4_CBUS_CTRL_14, 0x15);

    // Parity Bit Time
    ScalerSetByte(P2A_B5_CBUS_CTRL_15, 0x1C);

    // Parity Error Limit
    ScalerSetBit(P2A_B6_CBUS_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    // Ack Bit Initial Falling Edge
    ScalerSetBit(P2A_B7_CBUS_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);

    // Ack Bit Drive Low Time
    ScalerSetBit(P2A_B8_CBUS_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0D);

    // Requester Bit Time
    ScalerSetByte(P2A_BA_CBUS_CTRL_1A, 0x1C);

    // Check Received Ack Bit's Falling Edge
    ScalerSetBit(P2A_BC_CBUS_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x1C);

    // Check Received Ack Bit's Driving Low Period Upper Bound
    ScalerSetBit(P2A_BD_CBUS_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x12);

    // Check Received Ack Bit's Driving Low Period Lower Bound
    ScalerSetBit(P2A_BE_CBUS_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x05);

    // Actively Driving High Time for CBUS
    ScalerSetBit(P2A_C0_CBUS_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

    // CBUS Requester Transmit Opportunity after Arbitration
    ScalerSetByte(P2A_C2_CBUS_CTRL_22, 0x1C);

    // CBUS Requester Continue After Ack
    ScalerSetByte(P2A_C3_CBUS_CTRL_23, 0x0D);

    // Link Layer Timeout
    ScalerSetBit(P2A_C5_CBUS_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

    // Set Global MEC Packe TMOUT -> 192ms
    ScalerSetBit(P2A_C5_CBUS_CTRL_25, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Set IIC SCL Clock Frequency
    ScalerSetByte(P2A_F9_CBUS_CTRL_59, 0x03);

    // Enable CBUS System Clk
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT5, _BIT5);
}
//--------------------------------------------------
// Description  : Handle MHL Rx2 Related Timer Event
// Input Value  : ucEventID
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2TimerEventProc(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
        case _SCALER_TIMER_EVENT_MHL_RX2_READY_TO_TRANSMIT:

            SET_MHL_RX2_READY_TO_TRANSMIT();

            break;

        case _SCALER_TIMER_EVENT_MHL_RX2_RECONNECT_1K:

            if((((ScalerGetByte(P2A_A7_CBUS_CTRL_07) & 0x38) >> 3) == 0x01) ||
               (((ScalerGetByte(P2A_A7_CBUS_CTRL_07) & 0x38) >> 3) == 0x02))
            {
                ScalerSetBit(P2A_A8_CBUS_CTRL_08, ~_BIT5, 0x00);
                ScalerTimerDelayXms(52);
                ScalerSetBit(P2A_A8_CBUS_CTRL_08, ~_BIT5, _BIT5);
            }

            break;

        case _SCALER_TIMER_EVENT_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE:

            SET_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE();

            break;

        default:
            break;
    }
}

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
//--------------------------------------------------
// Description  : Check Write Burst for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2CheckWriteBurst(void)
{
    // Receive Write_Burst
    if(((bit)ScalerGetBit(P2A_CF_CBUS_CTRL_2F, _BIT7) == _TRUE) && (GET_MHL_RX2_WRITE_BURST_PROCESS_DONE() == _FALSE))
    {
        BYTE ucTmp = 0;
        BYTE ucTmp2 = 0;

        BYTE ucFifoLength = 0;
        BYTE pucFifoRxArray[16];
        BYTE pucFifoTxArray[16];
        BYTE ucTotEnt = 0;
        BYTE ucSeq = 0;
        BYTE ucNumEnt = 0;
        BYTE ucCheckSum = 0;

        BYTE ucECBUSBISTReady = 0;

        // Get Rx FIFO Length
        ucFifoLength = 16;

        // Get Rx FIFO Data (Write_Burst)
        ScalerGetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_40_SCRATCHPAD_OFFSET, ucFifoLength, pucFifoRxArray, _AUTOINC);

#if(_MHL3_ECBUS_WRITEBURST_DEBUG_MESSAGE == _ON)

        DebugMessageMHL("WB Rx2 Seq", pucFifoRxArray[4]);
        DebugMessageMHL("WB Rx2 Tot_Seq", pucFifoRxArray[3]);

        for(ucTmp2 = 0; ucTmp2 < ucFifoLength; ucTmp2++)
        {
            DebugMessageMHL("WB Rx2", pucFifoRxArray[ucTmp2]);
        }
#endif

        //---------------------------------------//
        //---- If is VC Assign Write_Burst ------//
        //---------------------------------------//
        if((((WORD)pucFifoRxArray[0] << 8) | ((WORD)pucFifoRxArray[1] << 0)) == (((WORD)_MHL_WRITE_BURST_ECBUS_VC_ASSIGN_HBYTE << 8) | ((WORD)_MHL_WRITE_BURST_ECBUS_VC_ASSIGN_LBYTE << 0)))
        {
#if(_MHL3_ECBUS_STARTUP_DEBUG_MESSAGE == _ON)
            DebugMessageMHL("Get VC Assign Write_Burst Form Source", 0x00);
#endif
            ucTotEnt = pucFifoRxArray[3];
            ucSeq = pucFifoRxArray[4];

            SET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucSeq, pucFifoRxArray[5]);
            SET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucSeq, ucFifoLength);

            // CBUS1 Size = 1
            SET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_SIZE(_ECBUS_CBUS1_VC_NUM, _ECBUS_CBUS1_VC_SIZE);

            // Scan Assigened VC Size
            for(ucTmp = 0; ucTmp < GET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucSeq); ucTmp++)
            {
                SET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_NUM((ucTmp + 1), pucFifoRxArray[(3 * ucTmp) + 6]);
                SET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_ID((ucTmp + 1), pucFifoRxArray[(3 * ucTmp) + 6 + 1]);
                SET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_SIZE((ucTmp + 1), pucFifoRxArray[(3 * ucTmp) + 6 + 2]);
                SET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_COUNT(GET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_COUNT() + 1);
            }

            // Check Entry Count of Received VC Assign
            for(ucTmp = 1; ucTmp <= ucSeq; ucTmp++)
            {
                ucNumEnt = ucNumEnt + GET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucTmp);
            }

            // If All VC Assign Write_Burst Have been Scanned
            if(ucNumEnt == ucTotEnt)
            {
                // If VC Size of eMSC != 0
                if(GET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_SIZE(_ECBUS_EMSC_VC_NUM) != 0x00)
                {
                    // Reallocate eMSC Virtual Channel with Assigened eMSC VC Size
                    if(ScalerMHL3Rx2ECBUSTdmReallocation() == _SUCCESS)
                    {
                        // Encode VC_CONFIRM Write_Burst
                        for(ucTmp = 1; ucTmp <= ucSeq; ucTmp++)
                        {
                            // Set VC_CONFIRM Header
                            pucFifoTxArray[0] = pucFifoRxArray[0];
                            pucFifoTxArray[1] = pucFifoRxArray[1] + 1;

                            pucFifoTxArray[3] = ucTotEnt;
                            pucFifoTxArray[4] = ucTmp;
                            pucFifoTxArray[5] = GET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucTmp);

                            for(ucTmp2 = 0; ucTmp2 < GET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucTmp); ucTmp2++)
                            {
                                pucFifoTxArray[(3 * ucTmp2) + 6] = GET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_NUM(ucTmp2 + 1);
                                pucFifoTxArray[(3 * ucTmp2) + 6 + 1] = GET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_ID(ucTmp2 + 1);

                                if(pucFifoTxArray[(3 * ucTmp2) + 6 + 1] == 0x00)
                                {
                                    pucFifoTxArray[(3 * ucTmp2) + 6 + 2] = 0x00;
                                }
                                else
                                {
                                    pucFifoTxArray[(3 * ucTmp2) + 6 + 2] = 0x00;
                                }
                            }

                            // Compute Check Sum of Write_Burst
                            for(ucTmp2 = 0; ucTmp2 < GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp); ucTmp2++)
                            {
                                if(ucTmp2 != 0x02)
                                {
                                    ucCheckSum = pucFifoTxArray[ucTmp2] + ucCheckSum;
                                }
                            }
                            pucFifoTxArray[2] = 256 - ucCheckSum;

                            if(ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _SUCCESS)
                            {
                                ucTmp2 = 100;

                                while((ucTmp2-- > 0) && ((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT) != _TRUE))
                                {
                                    ScalerTimerDelayXms(5);
                                }

                                if(ScalerMHLRx2MscSendWriteBurst(0x40, GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp), &pucFifoTxArray, _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                                {
                                    // Clear Flag
                                    ScalerSetBit(P2A_CF_CBUS_CTRL_2F, ~_BIT7, _BIT7);

                                    SET_MHL_RX2_WRITE_BURST_PROCESS_DONE();
                                }
                            }
                        }
                    }
                }
                else  // if(GET_MHL3_ECBUS_VC_ASSIGN_VC_SIZE(_ECBUS_EMSC_VC_NUM) == 0x00)
                {
                    // Encode VC_CONFIRM Write_Burst
                    for(ucTmp = 1; ucTmp <= ucSeq; ucTmp++)
                    {
                        // Set VC_CONFIRM Header
                        pucFifoTxArray[0] = pucFifoRxArray[0];
                        pucFifoTxArray[1] = pucFifoRxArray[1] + 1;

                        pucFifoTxArray[3] = ucTotEnt;
                        pucFifoTxArray[4] = ucTmp;
                        pucFifoTxArray[5] = GET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucTmp);

                        for(ucTmp2 = 0; ucTmp2 < GET_MHL3_RX2_ECBUS_VC_ASSIGN_NUM_ENT(ucTmp); ucTmp2++)
                        {
                            pucFifoTxArray[(3 * ucTmp2) + 6] = GET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_NUM(ucTmp2 + 1);
                            pucFifoTxArray[(3 * ucTmp2) + 6 + 1] = GET_MHL3_RX2_ECBUS_VC_ASSIGN_VC_ID(ucTmp2 + 1);
                            pucFifoTxArray[(3 * ucTmp2) + 6 + 2] = 0x00;
                        }

                        // Compute Check Sum of Write_Burst
                        for(ucTmp2 = 0; ucTmp2 < GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp); ucTmp2++)
                        {
                            if(ucTmp2 != 0x02)
                            {
                                ucCheckSum = pucFifoTxArray[ucTmp2] + ucCheckSum;
                            }
                        }
                        pucFifoTxArray[2] = 256 - ucCheckSum;

                        if(ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _SUCCESS)
                        {
                            ucTmp2 = 100;

                            while((ucTmp2-- > 0) && ((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT) != _TRUE))
                            {
                                ScalerTimerDelayXms(5);
                            }

                            if(ScalerMHLRx2MscSendWriteBurst(0x40, GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp), &pucFifoTxArray, _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                            {
                                // Clear Flag
                                ScalerSetBit(P2A_CF_CBUS_CTRL_2F, ~_BIT7, _BIT7);

                                SET_MHL_RX2_WRITE_BURST_PROCESS_DONE();
                            }
                        }

#if(_MHL3_ECBUS_WRITEBURST_DEBUG_MESSAGE == _ON)
                        if(GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp) > 0x00)
                        {
                            DebugMessageMHL("WB Tx Seq", ucTmp);
                            DebugMessageMHL("WB Tx Length", GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp));

                            for(ucTmp2 = 0; ucTmp2 < GET_MHL3_RX2_ECBUS_VC_ASSIGN_WB_LENGTH(ucTmp); ucTmp2++)
                            {
                                DebugMessageMHL("WB Tx", pucFifoTxArray[ucTmp2]);
                            }
                        }
#endif
                    }
                }
            }
        }


        //----------------------------------------//
        //---- If is BIST Setup Write_Burst ------//
        //----------------------------------------//
        else if((((WORD)pucFifoRxArray[0] << 8) | ((WORD)pucFifoRxArray[1] << 0)) == ((((WORD)_MHL_WRITE_BURST_ECBUS_BIST_SETUP_HBYTE << 8)) | ((WORD)_MHL_WRITE_BURST_ECBUS_BIST_SETUP_LBYTE << 0)))
        {
#if(_MHL3_BIST_FUNCTION_DEBUG_MESSAGE == _ON)
            for(ucTmp = 0; ucTmp < 16; ucTmp++)
            {
                DebugMessageMHL("1 BIST SETUP", pucFifoRxArray[ucTmp]);
            }
#endif
            // Set BIST Duration (Seconds)
            SET_MHL3_RX2_BIST_ECBUS_DURATION(pucFifoRxArray[3]);

            if(pucFifoRxArray[3] != 0x00)
            {
                if(pucFifoRxArray[4] == 0x01) // ECBUS PRBS
                {
                    ScalerSetBit(P2B_35_ECBUS_BIST_CONFIG, ~_BIT3, 0x00);
                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT0;
                }
                else if(pucFifoRxArray[4] == 0x02) // ECBUS Fixed 8
                {
                    ScalerSetBit(P2B_35_ECBUS_BIST_CONFIG, ~_BIT3, _BIT3);
                    ScalerSetByte(P2B_36_ECBUS_BIST_FIXED8, pucFifoRxArray[6]);
                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT0;
                }
                else
                {
                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT4;
                }
            }
            else
            {
                ucECBUSBISTReady = ucECBUSBISTReady | _BIT4;
            }

            // Set AV Link Duration (Frames)
            if(pucFifoRxArray[11] != 0x00)
            {
                // Set AV Link Duration to Duration Mode
                ScalerSetBit(P76_02_MHL_BIST_CTRL, ~_BIT4, _BIT4);

                // Set AV Link Duration = ucFifoRxArray[11] x 32 Frames
                ScalerSetByte(P76_0D_MHL_BIST_DURATION, pucFifoRxArray[11]);
            }
            else
            {
                // Set AV Link Duration to Continuous Mode
                ScalerSetBit(P76_02_MHL_BIST_CTRL, ~_BIT4, 0x00);
            }

            // Set AV Link Rate
            switch(pucFifoRxArray[8])
            {
                case _ECBUS_LINK_RATE_1_5:

                    SET_MHL3_RX2_AV_LINK_RATE(_ECBUS_LINK_RATE_1_5);
                    SET_MHL3_RX2_AV_LINK_N_CODE(_ECBUS_N_CODE_1_5);

                    break;

                case _ECBUS_LINK_RATE_3_0:

                    SET_MHL3_RX2_AV_LINK_RATE(_ECBUS_LINK_RATE_3_0);
                    SET_MHL3_RX2_AV_LINK_N_CODE(_ECBUS_N_CODE_3_0);

                    break;

                case _ECBUS_LINK_RATE_6_0:

                    SET_MHL3_RX2_AV_LINK_RATE(_ECBUS_LINK_RATE_6_0);
                    SET_MHL3_RX2_AV_LINK_N_CODE(_ECBUS_N_CODE_6_0);

                    break;

                default:

                    SET_MHL3_RX2_AV_LINK_RATE(_ECBUS_LINK_RATE_NULL);
                    SET_MHL3_RX2_AV_LINK_N_CODE(_ECBUS_N_CODE_NULL);

                    break;
            }

            if(pucFifoRxArray[9] == 0x01) // AV PRBS
            {
                ScalerSetBit(P76_02_MHL_BIST_CTRL, ~(_BIT6 | _BIT5), _BIT5);

                // Switch Align Mode for Fixed 8/ PRBS
                ScalerSetBit(P76_03_MHL_BIST_CONFIG_1, ~_BIT4, 0X00);

                ucECBUSBISTReady = ucECBUSBISTReady | _BIT1;
            }
            else if(pucFifoRxArray[9] == 0x02) // AV Fixed 8
            {
                ScalerSetBit(P76_02_MHL_BIST_CTRL, ~(_BIT6 | _BIT5), _BIT6);

                // Switch Align Mode for Fixed 8/ PRBS
                ScalerSetBit(P76_03_MHL_BIST_CONFIG_1, ~_BIT4, 0X00);

                // Set Fixed 8 Patten
                ScalerSetByte(P76_04_MHL_BIST_CONFIG_2, pucFifoRxArray[13]);

                ucECBUSBISTReady = ucECBUSBISTReady | _BIT1;
            }
            else if(pucFifoRxArray[9] == 0x03) // AV Fixed 10
            {
                ScalerSetBit(P76_02_MHL_BIST_CTRL, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

                // Set Fixed 10 Patten Inversion
                // Switch Align Mode for Fixed 10
                ScalerSetBit(P76_03_MHL_BIST_CONFIG_1, ~(_BIT5 | _BIT4), (((pucFifoRxArray[12] & _BIT7) >> 2) | _BIT4));

                // Set Fixed 10 Patten
                ScalerSetBit(P76_03_MHL_BIST_CONFIG_1, ~(_BIT1 | _BIT0), (pucFifoRxArray[12] & 0x11));
                ScalerSetByte(P76_04_MHL_BIST_CONFIG_2, pucFifoRxArray[13]);

                ucECBUSBISTReady = ucECBUSBISTReady | _BIT1;
            }
            else
            {
                ucECBUSBISTReady = ucECBUSBISTReady | _BIT5;
            }

            // Set AV Link Randomizer
            ScalerSetBit(P76_02_MHL_BIST_CTRL, ~_BIT2, (((~pucFifoRxArray[14]) & _BIT0) << 2));

            // ----- Impedance BIST ------ //
            switch(pucFifoRxArray[15])
            {
                case _AV_LINK_RX:

                    // Re-Connect AV Link Z0
                    ScalerSetBit(P7B_18_IMPEDANCE_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
                    ScalerSetBit(P7B_18_IMPEDANCE_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

                    SET_MHL3_RX2_BIST_IMPEDENCE_MODE(_AV_LINK_RX);

                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT2;

                    break;

                case _ECBUS_S_TX_LOW:

                    // Re-Connect ECBUS 50 Ohm
                    ScalerSetBit(P27_06_ECBUS_Z0_CTRL_0, ~_BIT2, 0x00);
                    ScalerSetBit(P27_06_ECBUS_Z0_CTRL_0, ~_BIT2, _BIT2);

                    SET_MHL3_RX2_BIST_IMPEDENCE_MODE(_ECBUS_S_TX_LOW);

                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT2;

                    break;

                case _ECBUS_S_TX_HIGH:

                    // Re-Connect ECBUS 50 Ohm
                    ScalerSetBit(P27_06_ECBUS_Z0_CTRL_0, ~_BIT2, 0x00);
                    ScalerSetBit(P27_06_ECBUS_Z0_CTRL_0, ~_BIT2, _BIT2);

                    SET_MHL3_RX2_BIST_IMPEDENCE_MODE(_ECBUS_S_TX_HIGH);

                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT2;

                    break;

                case _ECBUS_S_RX:

                    // Re-Connect ECBUS 50 Ohm
                    ScalerSetBit(P27_06_ECBUS_Z0_CTRL_0, ~_BIT2, 0x00);
                    ScalerSetBit(P27_06_ECBUS_Z0_CTRL_0, ~_BIT2, _BIT2);

                    SET_MHL3_RX2_BIST_IMPEDENCE_MODE(_ECBUS_S_RX);

                    ucECBUSBISTReady = ucECBUSBISTReady | _BIT2;

                    break;

                default:

                    break;
            }

            if(ScalerMHLRx2MscSendCommand(_MSC_MSG, _MSC_BIST_READY, ucECBUSBISTReady) == _SUCCESS)
            {
#if(_MHL3_BIST_FUNCTION_DEBUG_MESSAGE == _ON)
                // Set AV Link Video Mode
                DebugMessageMHL("2 BIST Ready", ucECBUSBISTReady);
#endif
                // Clear Flag
                ScalerSetBit(P2A_CF_CBUS_CTRL_2F, ~_BIT7, _BIT7);

                SET_MHL_RX2_WRITE_BURST_PROCESS_DONE();
            }
        }


        //---------------------------------------//
        //---- If Receive Other Write_Burst -----//
        //---------------------------------------//
        else
        {
            ScalerSetBit(P2A_CF_CBUS_CTRL_2F, ~_BIT7, _BIT7);

            SET_MHL_RX2_WRITE_BURST_PROCESS_DONE();
        }
    }
}
#endif

#endif
