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
// ID Code      : RL6193_Series_DP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_DP_SUPPORT == _ON)

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
void ScalerDpScanInitial(BYTE ucInputPort);
void ScalerDpSecDataReset(BYTE ucInputPort);
bit ScalerDpNormalPreDetect(BYTE ucInputPort);
BYTE ScalerDpScanInputPort(BYTE ucInputPort);
bit ScalerDpPSPreDetect(BYTE ucInputPort);
bit ScalerDpStableDetect(BYTE ucInputPort);
bit ScalerDpHdcpCheckEnabled(BYTE ucInputPort);
void ScalerDpFirstActiveProc(BYTE ucInputPort);
void ScalerDpPowerSwitch(EnumPowerAction enumPowerAction);
void ScalerDpJudgeHPDToggle(EnumPowerAction enumPowerAction);

#if(_DP_MST_SUPPORT == _ON)
void ScalerDpAuxChPowerStatusCheck(BYTE ucInputPort, bit bCableStatus);
#endif

void ScalerDpCapabilitySwitchProc(void);

#if(_DP_FREESYNC_SUPPORT == _ON)
#if(_DP_TX_SUPPORT == _ON)
void ScalerDpTxSSTSetAmdSpdInfo(bit bPlayback);
#endif
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial Setting for DP Scanning Port(Power Normal)
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : None
//--------------------------------------------------
void ScalerDpScanInitial(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif
            ScalerDpRx0MacInitial();

            ScalerDpRx0PhyInitial();

            CLR_DP_RX0_FAKE_LINK_TRAINING();

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            ScalerDpRx1MacInitial();

            ScalerDpRx1PhyInitial();

            CLR_DP_RX1_FAKE_LINK_TRAINING();

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : DP Sec Data Reset
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerDpSecDataReset(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            ScalerDpRx0SecDataBlockReset();
#endif
            break;

        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            ScalerDpRx1SecDataBlockReset();
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Signal PreDetection for DP(Power Normal)
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpNormalPreDetect(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            return ScalerDpRx0NormalPreDetect();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return ScalerDpRx1NormalPreDetect();
#endif
        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Port Source/Sync Scanning and Setting
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : Source DP --> DP Sync Stable
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerDpScanInputPort(BYTE ucInputPort)
{
    switch((ucInputPort))
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            return ScalerDpRx0ScanInputPort();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            return ScalerDpRx1ScanInputPort();
#endif

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Signal Detection for DP(Power Saving)
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpPSPreDetect(BYTE ucInputPort)
{
    switch((ucInputPort))
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            return ScalerDpRx0PSPreDetect();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            return ScalerDpRx1PSPreDetect();
#endif

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : On Line Check DP stability
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True --> DP Stable
//                False --> DP Unstable
//--------------------------------------------------
bit ScalerDpStableDetect(BYTE ucInputPort)
{
    switch((ucInputPort))
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            return ScalerDpRx0StableDetect();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            return ScalerDpRx1StableDetect();
#endif

        default:

            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : Input Port
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerDpHdcpCheckEnabled(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        return ScalerDpRx0HdcpEnebled();
#endif
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        return ScalerDpRx1HdcpEnebled();
#endif
    }
    else if(ucInputPort == _D6_INPUT_PORT)
    {
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        return ScalerDpRx0HdcpEnebled();
#endif
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP First Active Process
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerDpFirstActiveProc(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
#endif

            // Enable DP Fifo Under/OverFlow Watch Dog
            ScalerDpRx0SetFifoWD(_ENABLE);

            // Enable DP Fifo Under/OverFlow IRQ
            ScalerDpRx0SetFifoIRQ(_ENABLE);

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:

            // Enable DP Fifo Under/OverFlow Watch Dog
            ScalerDpRx1SetFifoWD(_ENABLE);

            // Enable DP Fifo Under/OverFlow IRQ
            ScalerDpRx1SetFifoIRQ(_ENABLE);

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : Check DP Into Power Saving
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpPowerSwitch(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_DP_TX_SUPPORT == _ON)
            // Power Down Tx Reset
            ScalerDpTxSetStreamSource(_DP_TX_SOURCE_NONE);
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

            // Add for DPCD 2002h Bug
            CLR_DP_RX0_AUX_COMMAND_NO_REPLY();
            SET_DP_RX0_POWER_STATE_INTO_PS();

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
            // Power Down HDCP Reset
            ScalerDpRx0HDCPBlockReset();
#endif

#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
            {
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
                if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
#endif
                {
                    ScalerDpRx0MstInfoBackup(_DP_MST_BACKUP_INFO);
                }
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
                else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
                {
                    ScalerDpRx6MstInfoBackup(_DP_MST_BACKUP_INFO);
                }
#endif
                ScalerDpMstReset(_DP_MST_RX0_PORT);

                ScalerDpDpcdLinkStatusReset(_D0_INPUT_PORT);
                ScalerDpHotPlugEvent(_D0_INPUT_PORT, _DP_HPD_LOW_RESET_AUX);

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HOTPLUG_ASSERTED);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
            }
            else
#endif
            {
                if((GET_DP_DC_OFF_HPD_HIGH() == _FALSE) || (ScalerDpHdcpCheckEnabled(_D0_INPUT_PORT) == _TRUE))
                {
                    ScalerDpDpcdLinkStatusReset(_D0_INPUT_PORT);
                    ScalerDpHotPlugEvent(_D0_INPUT_PORT, _DP_HPD_LOW_RESET_AUX);

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HOTPLUG_ASSERTED);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
                }
                else
                {
                    // Disable HDCP support
                    ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x28, 0x00);

                    // Disable Write 68xxx int
                    ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~_BIT2, 0x00);
                }
            }
#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            // Add for DPCD 2002h Bug
            CLR_DP_RX1_AUX_COMMAND_NO_REPLY();
            SET_DP_RX1_POWER_STATE_INTO_PS();

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
            // Power Down HDCP Reset
            ScalerDpRx1HDCPBlockReset();
#endif

#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
            {
                ScalerDpRx1MstInfoBackup(_DP_MST_BACKUP_INFO);

                ScalerDpMstReset(_DP_MST_RX1_PORT);

                ScalerDpDpcdLinkStatusReset(_D1_INPUT_PORT);
                ScalerDpHotPlugEvent(_D1_INPUT_PORT, _DP_HPD_LOW_RESET_AUX);

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HOTPLUG_ASSERTED);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_LONG_HOTPLUG_EVENT);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ);
            }
            else
#endif
            {
                if((GET_DP_DC_OFF_HPD_HIGH() == _FALSE) || (ScalerDpHdcpCheckEnabled(_D1_INPUT_PORT) == _TRUE))
                {
                    ScalerDpDpcdLinkStatusReset(_D1_INPUT_PORT);
                    ScalerDpHotPlugEvent(_D1_INPUT_PORT, _DP_HPD_LOW_RESET_AUX);

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HOTPLUG_ASSERTED);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_LONG_HOTPLUG_EVENT);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ);
                }
                else
                {
                    // Disable HDCP support
                    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x28, 0x00);

                    // Disable Write 68xxx int
                    ScalerSetBit(PBA_DA_AUX_FIFO_RST, ~_BIT2, 0x00);
                }
            }
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            ScalerDpLowPowerProc();

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

            // Add for DPCD 2002h Bug
            CLR_DP_RX0_AUX_COMMAND_NO_REPLY();
            SET_DP_RX0_POWER_STATE_INTO_PS();

#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
            {
                ScalerDpMstReset(_DP_MST_RX0_PORT);
            }
#endif

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            // Add for DPCD 2002h Bug
            CLR_DP_RX1_AUX_COMMAND_NO_REPLY();
            SET_DP_RX1_POWER_STATE_INTO_PS();

#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
            {
                ScalerDpMstReset(_DP_MST_RX1_PORT);
            }
#endif

#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            ScalerDpLowPowerProc();

            break;

        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

            // Set Channel FIFO Read Control by FW
            ScalerSetBit(PB_63_DUMMY2, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

            // Disable Aux Power Saving Mode
            ScalerSetBit(PB7_62_AUX_2, ~_BIT1, 0x00);

            // Switch Aux PHY to GDI BandGap
            ScalerSetBit(PB7_63_AUX_3, ~_BIT7, 0x00);

            // Aux comm current select max
            ScalerSetBit(PB7_64_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            // Disable Aux INT
            ScalerSetBit(PB7_7A_AUX_DIG_PHYA, ~_BIT4, 0x00);

            // Stream Load By 63th MTPH
            ScalerSetBit(PB5_02_STHD_CTRL_1, ~_BIT7, 0x00);

            // Clear flag for write 68xxx int
            ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~_BIT1, _BIT1);

            // Enable Write 68xxx int
            ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~_BIT2, _BIT2);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
            // Enable HDCP and repeater support
            ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x28, 0x03);
#else
            // Enable HDCP support
            ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x28, 0x01);
#endif

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            // Set Channel FIFO Read Control by FW
            ScalerSetBit(PB0_63_DUMMY2, ~(_BIT6 | _BIT5), (_BIT6 | _BIT5));

            // Disable Aux Power Saving Mode
            ScalerSetBit(PBA_62_AUX_2, ~_BIT1, 0x00);

            // Switch Aux PHY to GDI BandGap
            ScalerSetBit(PBA_63_AUX_3, ~_BIT7, 0x00);

            // Aux comm current select max
            ScalerSetBit(PBA_64_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            // Disable Aux INT
            ScalerSetBit(PBA_7A_AUX_DIG_PHYA, ~_BIT4, 0x00);

            // Stream Load By 63th MTPH
            ScalerSetBit(PB8_02_STHD_CTRL_1, ~_BIT7, 0x00);

            // Clear flag for write 68xxx int
            ScalerSetBit(PBA_DA_AUX_FIFO_RST, ~_BIT1, _BIT1);

            // Enable Write 68xxx int
            ScalerSetBit(PBA_DA_AUX_FIFO_RST, ~_BIT2, _BIT2);

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
            // Enable HDCP and repeater support
            ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x28, 0x03);
#else
            // Enable HDCP support
            ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x28, 0x01);
#endif

#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            IP = 0xA0;

            break;

        case _POWER_ACTION_NORMAL_TO_FAKE_OFF:

#if(_DP_MST_SUPPORT == _ON)

            // Reset the Stream Mux
            ScalerDpRxMstStreamMuxReset();

            SET_DP_RX_MST_ST_SOURCE_CHANGE();
#endif
            break;

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Decision DP HPD Toggle Behavior
// Input Value  : Power Action State
// Output Value : None
//--------------------------------------------------
void ScalerDpJudgeHPDToggle(EnumPowerAction enumPowerAction)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

    // Add for DPCD 2002h Bug
    // 2002h Has Been Read and Cancel Rx Mst Msg Finish during PS/ PD
    if(((enumPowerAction == _POWER_ACTION_OFF_TO_NORMAL) || (enumPowerAction == _POWER_ACTION_PS_TO_NORMAL)) && (GET_DP_RX0_AUX_COMMAND_NO_REPLY() == _TRUE))
    {
        CLR_DP_RX0_AUX_COMMAND_NO_REPLY();

        ScalerDpRx0HotPlugEvent(_DP_MST_LONG_HPD_EVENT);
    }
    else if(enumPowerAction == _POWER_ACTION_OFF_TO_NORMAL)
    {
#if(_DP_MST_SUPPORT == _ON)

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) || (g_enumDpMSTCapablePort == _DP_MST_RX6_PORT))
#else
        if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
#endif
        {
            ScalerDpRx0HPDPowerOfftoNormalProc(_LOW_FOR_MST);
        }
        else
#endif
        {
            ScalerDpRx0HPDPowerOfftoNormalProc(GET_DP_DC_OFF_HPD_HIGH());
        }
    }

    CLR_DP_RX0_POWER_STATE_INTO_PS();
#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)


#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

    // Add for DPCD 2002h Bug
    // 2002h Has Been Read and Cancel Rx Mst Msg Finish during PS/ PD
    if(((enumPowerAction == _POWER_ACTION_OFF_TO_NORMAL) || (enumPowerAction == _POWER_ACTION_PS_TO_NORMAL)) && (GET_DP_RX1_AUX_COMMAND_NO_REPLY() == _TRUE))
    {
        CLR_DP_RX1_AUX_COMMAND_NO_REPLY();

        ScalerDpRx1HotPlugEvent(_DP_MST_LONG_HPD_EVENT);
    }
    else if(enumPowerAction == _POWER_ACTION_OFF_TO_NORMAL)
    {
#if(_DP_MST_SUPPORT == _ON)

        if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
        {
            ScalerDpRx1HPDPowerOfftoNormalProc(_LOW_FOR_MST);
        }
        else
#endif
        {
            ScalerDpRx1HPDPowerOfftoNormalProc(GET_DP_DC_OFF_HPD_HIGH());
        }
    }

    CLR_DP_RX1_POWER_STATE_INTO_PS();
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
}

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Rx Aux Ch Power Status Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpAuxChPowerStatusCheck(BYTE ucInputPort, bit bCableStatus)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    if(ucInputPort == _D0_INPUT_PORT)
    {
        ScalerDpRx0AuxChPowerStatusCheck(bCableStatus);
    }

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if(ucInputPort == _D6_INPUT_PORT)
    {
        ScalerDpRx6AuxChPowerStatusCheck(bCableStatus);
    }
#endif

#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(ucInputPort == _D1_INPUT_PORT)
    {
        ScalerDpRx1AuxChPowerStatusCheck(bCableStatus);
    }
#endif
}
#endif

//--------------------------------------------------
// Description  : Dp Capability Switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpCapabilitySwitchProc(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    bit bDPRx0DoLongHotPlug = _FALSE;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    bit bDPRx1DoLongHotPlug = _FALSE;
#endif

#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_DP_HBR2_MARGIN_LINK_SUPPORT == _ON))
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if((GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) &&
       (GET_PCB_D0_DP_SOURCE_POWER() == _FALSE) &&
       (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2) &&
       (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) < _D0_DP_LINK_CLK_RATE) &&
       (_D0_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D0_DP_LINK_CLK_RATE);
        DebugMessageRx0("TYPEC_NO Cable", ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));
    }
    else if((GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT) &&
            (GET_PCB_D6_DP_SOURCE_POWER() == _FALSE) &&
            (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2) &&
            (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) < _D6_DP_LINK_CLK_RATE) &&
            (_D6_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D6_DP_LINK_CLK_RATE);
        DebugMessageRx0("TYPEC_NO Cable", ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));
    }
#else
    if((GET_PCB_D0_DP_SOURCE_POWER() == _FALSE) &&
       (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2) &&
       (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) < _D0_DP_LINK_CLK_RATE) &&
       (_D0_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D0_DP_LINK_CLK_RATE);
        DebugMessageRx0("TYPEC_NO Cable", ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));
    }
#endif
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_DP_HBR2_MARGIN_LINK_SUPPORT == _ON))
    if((GET_PCB_D1_DP_SOURCE_POWER() == _FALSE) &&
       (ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2) &&
       (ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x01) < _D1_DP_LINK_CLK_RATE) &&
       (_D1_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
    {
        ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x01, _D1_DP_LINK_CLK_RATE);
        DebugMessageRx1("TYPEC_NO Cable", ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x01));
    }
#endif

    if(GET_DP_RX_CAPABILITY_SWITCHED() == _TRUE)
    {
        DebugMessageMst("MST Cap Switch", GET_DP_RX_TARGET_MST_PORT());

        // D0 Port Version Switch
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if(_DP_FREESYNC_SUPPORT == _ON)

        if(GET_DP_RX0_FREESYNC_CAPABILITY_SWITCH() == _TRUE)
        {
            CLR_DP_RX0_FREESYNC_CAPABILITY_SWITCH();
            bDPRx0DoLongHotPlug = _TRUE;
        }
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
#endif
        {
            if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x00, 0x02, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != GET_DP_RX_D0_PORT_TARGET_LANE_COUNT())
            {
                ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x02, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), GET_DP_RX_D0_PORT_TARGET_LANE_COUNT());

                bDPRx0DoLongHotPlug = _TRUE;
            }

            if(GET_DP_RX_D0_EDID_SWITCH() == _TRUE)
            {
                CLR_DP_RX_D0_EDID_SWITCH();

#if(_DP_MST_SUPPORT == _ON)
                if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
                {
                    ScalerDpMstReset(_DP_MST_RX0_PORT);
                }
#endif
                bDPRx0DoLongHotPlug = _TRUE;
            }

            CLR_DP_RX_D6_EDID_SWITCH();

            if((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX0_PORT) && (GET_DP_RX_D0_PORT_TARGET_VERSION() == _DP_VERSION_1_1))
            {
                SET_DP_RX_D0_PORT_TARGET_VERSION(_DP_VERSION_1_2);
            }

            if(ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) != GET_DP_RX_D0_PORT_TARGET_VERSION())
            {
#if(_DP_MST_SUPPORT == _ON)
                if((GET_REG_DP_RX_DOWN_REQUEST_ADDR_WRITTEN() == _TRUE) ||
#if(_DP_TX_SUPPORT == _ON)
                   (GET_DP_TOTAL_RECEIVED_MSG_COUNT() != 0) ||
#endif
                   (GET_DP_RX_REPLY_BUF_FREE() == _FALSE))
                {
                    return;
                }
#endif
                ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D0_PORT_TARGET_VERSION(), GET_DP_RX_TARGET_MST_PORT());

#if(_DP_MST_SUPPORT == _ON)
                if(GET_DP_RX_D0_PORT_TARGET_VERSION() == _DP_VERSION_1_1)
                {
                    CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                    CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF();

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
                }
#endif

                bDPRx0DoLongHotPlug = _TRUE;
            }
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            else
            {
                ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D0_PORT_TARGET_VERSION(), GET_DP_RX_TARGET_MST_PORT());
            }
#endif
        }
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
        {
            if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x00, 0x02, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != GET_DP_RX_D6_PORT_TARGET_LANE_COUNT())
            {
                ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x02, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), GET_DP_RX_D6_PORT_TARGET_LANE_COUNT());

                bDPRx0DoLongHotPlug = _TRUE;
            }

            if(GET_DP_RX_D6_EDID_SWITCH() == _TRUE)
            {
                CLR_DP_RX_D6_EDID_SWITCH();

#if(_DP_MST_SUPPORT == _ON)
                if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
                {
                    ScalerDpMstReset(_DP_MST_RX0_PORT);
                }
#endif
                bDPRx0DoLongHotPlug = _TRUE;
            }

            CLR_DP_RX_D0_EDID_SWITCH();

            if((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX6_PORT) && (GET_DP_RX_D6_PORT_TARGET_VERSION() == _DP_VERSION_1_1))
            {
                SET_DP_RX_D6_PORT_TARGET_VERSION(_DP_VERSION_1_2);
            }

            if(ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) != GET_DP_RX_D6_PORT_TARGET_VERSION())
            {
#if(_DP_MST_SUPPORT == _ON)
                if((GET_REG_DP_RX_DOWN_REQUEST_ADDR_WRITTEN() == _TRUE) ||
#if(_DP_TX_SUPPORT == _ON)
                   (GET_DP_TOTAL_RECEIVED_MSG_COUNT() != 0) ||
#endif
                   (GET_DP_RX_REPLY_BUF_FREE() == _FALSE))
                {
                    return;
                }
#endif
                ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D6_PORT_TARGET_VERSION(), GET_DP_RX_TARGET_MST_PORT());

#if(_DP_MST_SUPPORT == _ON)
                if(GET_DP_RX_D6_PORT_TARGET_VERSION() == _DP_VERSION_1_1)
                {
                    CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                    CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF();

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
                }
#endif

                bDPRx0DoLongHotPlug = _TRUE;
            }
            else
            {
                ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D6_PORT_TARGET_VERSION(), GET_DP_RX_TARGET_MST_PORT());
            }
        }
#endif

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)


        // D1 Port Version Switch
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

#if(_DP_FREESYNC_SUPPORT == _ON)

        if(GET_DP_RX1_FREESYNC_CAPABILITY_SWITCH() == _TRUE)
        {
            CLR_DP_RX1_FREESYNC_CAPABILITY_SWITCH();
            bDPRx1DoLongHotPlug = _TRUE;
        }
#endif
        if(ScalerDpRx1GetDpcdBitInfo(0x00, 0x00, 0x02, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != GET_DP_RX_D1_PORT_TARGET_LANE_COUNT())
        {
            ScalerDpRx1SetDpcdBitValue(0x00, 0x00, 0x02, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), GET_DP_RX_D1_PORT_TARGET_LANE_COUNT());

            bDPRx1DoLongHotPlug = _TRUE;
        }

        if(GET_DP_RX_D1_EDID_SWITCH() == _TRUE)
        {
            CLR_DP_RX_D1_EDID_SWITCH();

#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
            {
                ScalerDpMstReset(_DP_MST_RX1_PORT);
            }
#endif
            bDPRx1DoLongHotPlug = _TRUE;
        }

        if((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX1_PORT) && (GET_DP_RX_D1_PORT_TARGET_VERSION() == _DP_VERSION_1_1))
        {
            SET_DP_RX_D1_PORT_TARGET_VERSION(_DP_VERSION_1_2);
        }

        if(ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x00) != GET_DP_RX_D1_PORT_TARGET_VERSION())
        {
#if(_DP_MST_SUPPORT == _ON)
            if((GET_REG_DP_RX_DOWN_REQUEST_ADDR_WRITTEN() == _TRUE) ||
#if(_DP_TX_SUPPORT == _ON)
               (GET_DP_TOTAL_RECEIVED_MSG_COUNT() != 0) ||
#endif
               (GET_DP_RX_REPLY_BUF_FREE() == _FALSE))
            {
                return;
            }
#endif
            ScalerDpRx1ChangeDpcdVersion(GET_DP_RX_D1_PORT_TARGET_VERSION(), GET_DP_RX_TARGET_MST_PORT());

#if(_DP_MST_SUPPORT == _ON)
            if(GET_DP_RX_D1_PORT_TARGET_VERSION() == _DP_VERSION_1_1)
            {
                CLR_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                CLR_DP_RX1_CHECK_AUX_CH_POWER_OFF();

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
            }
#endif

            bDPRx1DoLongHotPlug = _TRUE;
        }
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)


        // Mst Port Switch
#if(_DP_MST_SUPPORT == _ON)

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        // Target MST Port != Current Capable Port or External-Switching port case
        if(((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_NO_PORT) && (g_enumDpMSTCapablePort != _DP_MST_NO_PORT)) ||
           ((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX0_PORT) && (g_enumDpMSTCapablePort == _DP_MST_NO_PORT)) ||
           ((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX0_PORT) && ((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) && (g_bDpMSTD6Capable == _TRUE))) ||
           ((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX6_PORT) && (g_enumDpMSTCapablePort == _DP_MST_NO_PORT)) ||
           ((GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX6_PORT) && ((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) && (g_bDpMSTD6Capable == _FALSE))))
#else
        if(GET_DP_RX_TARGET_MST_PORT() != g_enumDpMSTCapablePort)
#endif
        {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

            if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
#endif
            {
                // No Port or Rx1 or Rx6 => Rx0
                // RX0 => NO Port or RX1 or Rx6
                if(((g_enumDpMSTCapablePort != _DP_MST_RX0_PORT) && (GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX0_PORT)) ||
                   ((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) && (GET_DP_RX_TARGET_MST_PORT() != _DP_MST_RX0_PORT)))
                {
                    CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                    CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF();

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);

                    bDPRx0DoLongHotPlug = _TRUE;

                    DebugMessageMst("MST Switch Long Plug : 1", GET_DP_RX_TARGET_MST_PORT());
                }

                ScalerDpMstReset(_DP_MST_RX0_PORT);

                if(GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX0_PORT)
                {
                    ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D0_PORT_TARGET_VERSION(), _DP_MST_RX0_PORT);
                }
                else
                {
                    ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D0_PORT_TARGET_VERSION(), _DP_MST_NO_PORT);
                }
            }
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
            {
                // No Port or Rx0 or Rx1 => Rx6
                // RX6 => NO Port or RX0 or Rx1
                if(((g_enumDpMSTCapablePort != _DP_MST_RX0_PORT) && (GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX6_PORT)) ||
                   ((g_enumDpMSTCapablePort == _DP_MST_RX0_PORT) && (GET_DP_RX_TARGET_MST_PORT() != _DP_MST_RX6_PORT)))
                {
                    CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                    CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF();

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);

                    bDPRx0DoLongHotPlug = _TRUE;

                    DebugMessageMst("MST Switch Long Plug : 2", GET_DP_RX_TARGET_MST_PORT());
                }

                ScalerDpMstReset(_DP_MST_RX0_PORT);

                if(GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX6_PORT)
                {
                    ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D6_PORT_TARGET_VERSION(), _DP_MST_RX6_PORT);
                }
                else
                {
                    ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D6_PORT_TARGET_VERSION(), _DP_MST_NO_PORT);
                }
            }
#endif

#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            // No Port or Rx0 or Rx6 => Rx1
            // RX1 => NO Port or RX0 or Rx6
            if(((g_enumDpMSTCapablePort != _DP_MST_RX1_PORT) && (GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX1_PORT)) ||
               ((g_enumDpMSTCapablePort == _DP_MST_RX1_PORT) && (GET_DP_RX_TARGET_MST_PORT() != _DP_MST_RX1_PORT)))
            {
                CLR_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                CLR_DP_RX1_CHECK_AUX_CH_POWER_OFF();

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);

                bDPRx1DoLongHotPlug = _TRUE;
            }

            ScalerDpMstReset(_DP_MST_RX1_PORT);

            if(GET_DP_RX_TARGET_MST_PORT() == _DP_MST_RX1_PORT)
            {
                ScalerDpRx1ChangeDpcdVersion(GET_DP_RX_D1_PORT_TARGET_VERSION(), _DP_MST_RX1_PORT);
            }
            else
            {
                ScalerDpRx1ChangeDpcdVersion(GET_DP_RX_D1_PORT_TARGET_VERSION(), _DP_MST_NO_PORT);
            }
#endif

#if(_DP_TX_SUPPORT == _ON)

            ScalerDpTxSetStreamSource(_DP_TX_SOURCE_NONE);

            if(GET_DP_TX_DOWNSTREAM_DPPLUG_STATUS() == _DP_PLUG)
            {
                pData[0] = 0x00;

                ScalerDpTxAuxNativeWrite(0x00, 0x01, 0x11, 1, pData);

#if(_DP_FREESYNC_SUPPORT == _ON)
                // Clear freesync enable bit
                ScalerDpTxAuxNativeRead(0x00, 0x01, 0x07, 1, pData);

                if((pData[0] & _BIT7) == _BIT7)
                {
                    pData[0] &= ~_BIT7;
                    ScalerDpTxAuxNativeWrite(0x00, 0x01, 0x07, 1, pData);
                }
#endif
            }
#endif
            ScalerDpRxMstInitial(GET_DP_RX_TARGET_MST_PORT());
        }
#endif // End of #if(_DP_MST_SUPPORT == _ON)

        CLR_DP_RX_CAPABILITY_SWITCHED();
    }

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

    if(bDPRx0DoLongHotPlug == _TRUE)
    {
        ScalerDpRx0HotPlugEvent(_DP_MST_LONG_HPD_EVENT);
    }

#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

    if(bDPRx1DoLongHotPlug == _TRUE)
    {
        ScalerDpRx1HotPlugEvent(_DP_MST_LONG_HPD_EVENT);
    }

#endif
}

#if(_DP_FREESYNC_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Set DP TX AMD SPD info, using MPEG info
// Input Value  : On/ Off
// Output Value : None
//--------------------------------------------------
void ScalerDpTxSSTSetAmdSpdInfo(bit bPlayback)
{
    bPlayback = bPlayback;
}
#endif

#endif // #if(_DP_FREESYNC_SUPPORT == _ON)

#endif // #if(_DP_SUPPORT == _ON)

