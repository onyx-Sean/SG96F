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
// ID Code      : ScalerDP_SeptPhy.c No.0000
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
#if(_DP_SUPPORT == _ON)
void ScalerDpDpcdLinkStatusReset(BYTE ucInputPort);
void ScalerDpEdidSwitch(BYTE ucInputPort);
void ScalerDpFakeLinkTrainingSetting(BYTE ucInputPort);
EnumDpPowerState ScalerDpGetPowerStatus(BYTE ucInputPort);
EnumDpLaneCount ScalerDpGetLaneCount(BYTE ucInputPort);
EnumDpLinkRate ScalerDpGetLinkRate(BYTE ucInputPort);
EnumDpVoltageSwingLevel ScalerDpGetLaneVoltageSwingLv(BYTE ucInputPort, EnumDpLane enumDpLane);
EnumDpPreEmphasisLevel ScalerDpGetLanePreEmpLv(BYTE ucInputPort, EnumDpLane enumDpLane);
bit ScalerDpGetSrcMstEnable(BYTE ucInputPort);
void ScalerDpHotPlugEvent(BYTE ucInputPort, EnumDpHotPlugAssertType enumHpdType);
void ScalerDpInitial(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount);
void ScalerDpLowPowerProc(void);
void ScalerDpResetProc(void);
void ScalerDpTimerEventProc(EnumScalerTimerEventID enumEventID);
void ScalerDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);

#if(_DP_MST_SUPPORT == _ON)
void ScalerDpMstReset(EnumDPMSTPort enumRxMstPort);
#if(_DP_TX_SUPPORT == _ON)
void ScalerDpHDCPHandler(void);
#endif
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
void ScalerDpFREESYNCSupportSwitch(EnumDpFREESYNCCapabilitySwitch enumDpFREESYNCCapSwitch, bit bEn);
BYTE ScalerDpGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent);
WORD ScalerDpGetHSPeriod(void);
WORD ScalerDpGetHSW(void);
WORD ScalerDpGetVFreq(void);
WORD ScalerDpGetVSPeriod(void);
#endif

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DPCD Link Status Field Reset
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerDpDpcdLinkStatusReset(BYTE ucInputPort)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    if(ucInputPort == _D0_INPUT_PORT)
    {
        ScalerDpRx0DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(ucInputPort == _D1_INPUT_PORT)
    {
        ScalerDpRx1DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);
    }
#endif
}

//--------------------------------------------------
// Description  : DP EDID Switch
// Input Value  : Input DP Port
// Output Value : None
//--------------------------------------------------
void ScalerDpEdidSwitch(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:
            SET_DP_RX_D0_EDID_SWITCH();
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:
            SET_DP_RX_D1_EDID_SWITCH();
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
            SET_DP_RX_D6_EDID_SWITCH();
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : DP Fake Link Training Setting
// Input Value  : ucInputPortType
// Output Value : None
//--------------------------------------------------
void ScalerDpFakeLinkTrainingSetting(BYTE ucInputPort)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if((ucInputPort != _D0_INPUT_PORT) && (ucInputPort != _D6_INPUT_PORT))
#else
    if(ucInputPort != _D0_INPUT_PORT)
#endif
    {
        ScalerDpRx0FakeLTProtect();
    }

#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

    if(ucInputPort != _D1_INPUT_PORT)
    {
        ScalerDpRx1FakeLTProtect();
    }

#endif
}

//--------------------------------------------------
// Description  : Get DP Power Status (DPCD 00600h)
// Input Value  : DP Input Port
// Output Value : DP Power Status
//--------------------------------------------------
EnumDpPowerState ScalerDpGetPowerStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        case _D6_INPUT_PORT:
#endif
            if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1)
            {
                return _DP_POWER_DOWN;
            }
            else if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0))
            {
                return _DP_POWER_DOWN_WITH_AUX;
            }

            return _DP_POWER_NORMAL;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            if(ScalerDpRx1GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1)
            {
                return _DP_POWER_DOWN;
            }
            else if(ScalerDpRx1GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0))
            {
                return _DP_POWER_DOWN_WITH_AUX;
            }

            return _DP_POWER_NORMAL;
#endif

        default:

            return _DP_POWER_NORMAL;
    }
}

//--------------------------------------------------
// Description  : Get DP Lane Count (DPCD 00101h)
// Input Value  : DP Input Port
// Output Value : DP Lane Count
//--------------------------------------------------
EnumDpLaneCount ScalerDpGetLaneCount(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        case _D6_INPUT_PORT:
#endif
            return (ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, 0x01, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return (ScalerDpRx1GetDpcdBitInfo(0x00, 0x01, 0x01, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));
#endif
        default:

            return _DP_LINK_4_LANE;
    }
}

//--------------------------------------------------
// Description  : Get DP Link Rate (DPCD 00100h)
// Input Value  : DP Input Port
// Output Value : DP Link Rate
//--------------------------------------------------
EnumDpLinkRate ScalerDpGetLinkRate(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        case _D6_INPUT_PORT:
#endif
            return (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00));
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return (ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00));
#endif
        default:

            return _DP_LINK_RBR;
    }
}

//--------------------------------------------------
// Description  : Get DP Voltage Swing Level(DPCD 00103h-00106h [1:0])
// Input Value  : DP Input Port, Lane #
// Output Value : DP Voltage Swing Level of the lane
//--------------------------------------------------
EnumDpVoltageSwingLevel ScalerDpGetLaneVoltageSwingLv(BYTE ucInputPort, EnumDpLane enumDpLane)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        case _D6_INPUT_PORT:
#endif
            return (ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, (0x03 + enumDpLane), (_BIT1 | _BIT0)));
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return (ScalerDpRx1GetDpcdBitInfo(0x00, 0x01, (0x03 + enumDpLane), (_BIT1 | _BIT0)));
#endif
        default:

            return 0;
    }
}

//--------------------------------------------------
// Description  : Get DP Pre-emphasis Level(DPCD 00103h-00106h [4:3])
// Input Value  : DP Input Port, Lane #
// Output Value : DP Pre-emphasis Level of the lane
//--------------------------------------------------
EnumDpPreEmphasisLevel ScalerDpGetLanePreEmpLv(BYTE ucInputPort, EnumDpLane enumDpLane)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        case _D6_INPUT_PORT:
#endif
            return (ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, (0x03 + enumDpLane), (_BIT4 | _BIT3)) >> 3);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return (ScalerDpRx1GetDpcdBitInfo(0x00, 0x01, (0x03 + enumDpLane), (_BIT4 | _BIT3)) >> 3);
#endif
        default:

            return 0;
    }
}

//--------------------------------------------------
// Description  : Get DP Source MST enable (DPCD 00111h[0])
// Input Value  : DP Input Port
// Output Value : _TRUE --> MST enable, _FALSE --> SST
//--------------------------------------------------
bit ScalerDpGetSrcMstEnable(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _D0_INPUT_PORT:

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        case _D6_INPUT_PORT:
#endif
            if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, 0x11, _BIT0) == _BIT0)
            {
                return _TRUE;
            }
            else
            {
                return _FALSE;
            }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            if(ScalerDpRx1GetDpcdBitInfo(0x00, 0x01, 0x11, _BIT0) == _BIT0)
            {
                return _TRUE;
            }
            else
            {
                return _FALSE;
            }
#endif
        default:

            return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Dp HotPlug Event for interface
// Input Value  : Hot Plug Type
// Output Value : None
//--------------------------------------------------
void ScalerDpHotPlugEvent(BYTE ucInputPort, EnumDpHotPlugAssertType enumHpdType)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    if(ucInputPort == _D0_INPUT_PORT)
    {
        ScalerDpRx0HotPlugEvent(enumHpdType);
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(ucInputPort == _D1_INPUT_PORT)
    {
        ScalerDpRx1HotPlugEvent(enumHpdType);
    }
#endif
}

//--------------------------------------------------
// Description  : Initial DP Settings
// Input Value  : _D0_DP_PORT or _D1_DP_PORT or _D2_DP_PORT, DPCD version, Lane Count, MST Port
// Output Value : None
//--------------------------------------------------
void ScalerDpInitial(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:
            ScalerDpRx0Initial(enumDpVersion, enumDpLaneCount, enumDpRxMstPort);
            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:
            ScalerDpRx1Initial(enumDpVersion, enumDpLaneCount, enumDpRxMstPort);
            break;
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
            ScalerDpRx6Initial(enumDpVersion, enumDpLaneCount, enumDpRxMstPort);
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : DP Lane Switch
// Input Value  : DP input port, DP Lane Count
// Output Value : None
//--------------------------------------------------
void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:
            SET_DP_RX_D0_PORT_TARGET_LANE_COUNT(enumDpLaneCount);
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:
            SET_DP_RX_D1_PORT_TARGET_LANE_COUNT(enumDpLaneCount);
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
            SET_DP_RX_D6_PORT_TARGET_LANE_COUNT(enumDpLaneCount);
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : DP Low Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpLowPowerProc(void)
{
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D1_INPUT_PORT_TYPE == _D1_DP_PORT))

    // Turn Off Output Clock
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~_BIT6, 0x00);

    // Turn Off SCLK PLL
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Turn Off Output Clock
    ScalerSetBit(PB8_B8_MN_SCLKG_SDM_CTRL, ~_BIT6, 0x00);

    // Turn Off SCLK PLL
    ScalerSetBit(PB8_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set end to idle trigger Aux Int, Clear Aux INT Flag
    ScalerSetBit(PB7_7A_AUX_DIG_PHYA, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

    // Clear Manchester/Stop pattern/Sync_end pattern/Byte boundary check Error
    ScalerSetBit(PB7_79_AUX_DIG_PHY9, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Set end to idle trigger Aux Int, Clear Aux INT Flag
    ScalerSetBit(PBA_7A_AUX_DIG_PHYA, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

    // Clear Manchester/Stop pattern/Sync_end pattern/Byte boundary check Error
    ScalerSetBit(PBA_79_AUX_DIG_PHY9, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    ScalerTimerDelayXms(2);

    if((ScalerGetBit(PB7_7A_AUX_DIG_PHYA, _BIT0) == 0x00) && (ScalerGetBit(PBA_7A_AUX_DIG_PHYA, _BIT0) == 0x00))
    {
        // Aux PHY Power Saving Mode
        ScalerSetBit(PB7_62_AUX_2, ~_BIT1, _BIT1);

        // Aux Bias Current From POR
        ScalerSetBit(PB7_63_AUX_3, ~_BIT7, _BIT7);

        // Aux comm current select min
        ScalerSetBit(PB7_64_AUX_4, ~(_BIT7 | _BIT6), 0x00);

        // Aux PHY Power Saving Mode
        ScalerSetBit(PBA_62_AUX_2, ~_BIT1, _BIT1);

        // Aux Bias Current From POR
        ScalerSetBit(PBA_63_AUX_3, ~_BIT7, _BIT7);

        // Aux comm current select min
        ScalerSetBit(PBA_64_AUX_4, ~(_BIT7 | _BIT6), 0x00);

        // Disable GDI Bandgap
        ScalerGDIPhyBandgap(_OFF);

        IP = 0x81;

        CLR_DP_RX0_PS_AUX_TOGGLE();

        CLR_DP_RX1_PS_AUX_TOGGLE();

        // Enable Aux INT
        ScalerSetBit(PB7_7A_AUX_DIG_PHYA, ~(_BIT4 | _BIT0), (_BIT4));

        // Enable Aux INT
        ScalerSetBit(PBA_7A_AUX_DIG_PHYA, ~(_BIT4 | _BIT0), (_BIT4));

        DebugMessageDigital("7. Low Power Event", 0);
    }
    else
    {
        SET_DP_RX0_PS_AUX_TOGGLE();

        SET_DP_RX1_PS_AUX_TOGGLE();
    }

#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

    // Turn Off Output Clock
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~_BIT6, 0x00);

    // Turn Off SCLK PLL
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set end to idle trigger Aux Int, Clear Aux INT Flag
    ScalerSetBit(PB7_7A_AUX_DIG_PHYA, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

    // Clear Manchester/Stop pattern/Sync_end pattern/Byte boundary check Error
    ScalerSetBit(PB7_79_AUX_DIG_PHY9, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PB7_7A_AUX_DIG_PHYA, _BIT0) == 0x00)
    {
        // Aux PHY Power Saving Mode
        ScalerSetBit(PB7_62_AUX_2, ~_BIT1, _BIT1);

        // Aux Bias Current From POR
        ScalerSetBit(PB7_63_AUX_3, ~_BIT7, _BIT7);

        // Aux comm current select min
        ScalerSetBit(PB7_64_AUX_4, ~(_BIT7 | _BIT6), 0x00);

        // Disable GDI Bandgap
        ScalerGDIPhyBandgap(_OFF);

        IP = 0x81;

        CLR_DP_RX0_PS_AUX_TOGGLE();

        // Enable Aux INT
        ScalerSetBit(PB7_7A_AUX_DIG_PHYA, ~(_BIT4 | _BIT0), (_BIT4));

        DebugMessageDigital("7. Low Power Event", 0);
    }
    else
    {
        SET_DP_RX0_PS_AUX_TOGGLE();
    }

#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

    // Turn Off Output Clock
    ScalerSetBit(PB8_B8_MN_SCLKG_SDM_CTRL, ~_BIT6, 0x00);

    // Turn Off SCLK PLL
    ScalerSetBit(PB8_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set end to idle trigger Aux Int, Clear Aux INT Flag
    ScalerSetBit(PBA_7A_AUX_DIG_PHYA, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT1 | _BIT0));

    // Clear Manchester/Stop pattern/Sync_end pattern/Byte boundary check Error
    ScalerSetBit(PBA_79_AUX_DIG_PHY9, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PBA_7A_AUX_DIG_PHYA, _BIT0) == 0x00)
    {
        // Aux PHY Power Saving Mode
        ScalerSetBit(PBA_62_AUX_2, ~_BIT1, _BIT1);

        // Aux Bias Current From POR
        ScalerSetBit(PBA_63_AUX_3, ~_BIT7, _BIT7);

        // Aux comm current select min
        ScalerSetBit(PBA_64_AUX_4, ~(_BIT7 | _BIT6), 0x00);

        // Disable GDI Bandgap
        ScalerGDIPhyBandgap(_OFF);

        IP = 0x81;

        CLR_DP_RX1_PS_AUX_TOGGLE();

        // Enable Aux INT
        ScalerSetBit(PBA_7A_AUX_DIG_PHYA, ~(_BIT4 | _BIT0), (_BIT4));

        DebugMessageDigital("7. Low Power Event", 0);
    }
    else
    {
        SET_DP_RX1_PS_AUX_TOGGLE();
    }
#endif
}
//--------------------------------------------------
// Description  : DP Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpResetProc(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    // Disable DP Fifo Under/OverFlow Watch Dog
    ScalerDpRx0SetFifoWD(_DISABLE);

    // Disable DP Fifo Under/OverFlow IRQ
    ScalerDpRx0SetFifoIRQ(_DISABLE);

    // Disable DP No Video Stream IRQ
    ScalerDpRx0SetNoVideoStreamIRQ(_DISABLE);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    // Disable DP Fifo Under/OverFlow Watch Dog
    ScalerDpRx1SetFifoWD(_DISABLE);

    // Disable DP Fifo Under/OverFlow IRQ
    ScalerDpRx1SetFifoIRQ(_DISABLE);

    // Disable DP No Video Stream IRQ
    ScalerDpRx1SetNoVideoStreamIRQ(_DISABLE);
#endif

#if(_DP_TX_SUPPORT == _ON)
    if(GET_DP_TX_STREAM_SOURCE() == _DP_TX_SOURCE_CLONE)
    {
        ScalerDpTxSetStreamSource(_DP_TX_SOURCE_NONE);
    }
    else if(GET_DP_TX_STREAM_SOURCE() == _DP_TX_SOURCE_NONE) // for Clone OOR Case
    {
        // Clear Exceed BW Flag for Clone Mode
        CLR_DP_TX_EXCEED_LINK_BANDWIDTH();
    }
#endif
}
//--------------------------------------------------
// Description  : Handle DP Related Timer Event
// Input Value  : ucEventID
// Output Value : None
//--------------------------------------------------
void ScalerDpTimerEventProc(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _SCALER_TIMER_EVENT_DP_RX0_HOTPLUG_ASSERTED:
            ScalerDpRx0HotPlugEvent(_DP_HPD_ASSERTED);
            break;

        case _SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT:

            if(ScalerDpRx0HdcpReAuthStatusCheck() == _FALSE)
            {
                DebugMessageRx0("7. DP HDCP Long HPD", 0);
                ScalerDpRx0HotPlugEvent(_DP_HDCP_LONG_HPD_EVENT);
            }

            break;

        case _SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ:

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            if(((GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) && (GET_D0_CABLE_STATUS() == _TRUE)) ||
               ((GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT) && (GET_D6_CABLE_STATUS() == _TRUE)))
#else
            if(GET_D0_CABLE_STATUS() == _TRUE)
#endif
            {
                if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2) &&
                   ((GET_DP_RX_D0_MARGIN_LINK_HBR2() == _TRUE) || (GET_DP_RX_D6_MARGIN_LINK_HBR2() == _TRUE)))
                {
                    DebugMessageRx0("7. DP Margin Link Long HPD", 0);

                    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);

                    ScalerDpRx0HotPlugEvent(_DP_HBR2_MARGIN_LINK_HPD_EVENT);
                }
                else
                {
                    ScalerDpRx0LinkStatusIRQ();
                }
            }
#else
            ScalerDpRx0LinkStatusIRQ();
#endif
            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _SCALER_TIMER_EVENT_DP_RX1_HOTPLUG_ASSERTED:
            ScalerDpRx1HotPlugEvent(_DP_HPD_ASSERTED);
            break;

        case _SCALER_TIMER_EVENT_DP_RX1_HDCP_LONG_HOTPLUG_EVENT:

            if(ScalerDpRx1HdcpReAuthStatusCheck() == _FALSE)
            {
                DebugMessageRx1("7. DP HDCP Long HPD", 0);
                ScalerDpRx1HotPlugEvent(_DP_HDCP_LONG_HPD_EVENT);
            }

            break;

        case _SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ:

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
            if(GET_D1_CABLE_STATUS() == _TRUE)
            {
                if((ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2) &&
                   (GET_DP_RX_D1_MARGIN_LINK_HBR2() == _TRUE))
                {
                    DebugMessageRx1("7. DP Margin Link Long HPD", 0);

                    ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);

                    ScalerDpRx1HotPlugEvent(_DP_HBR2_MARGIN_LINK_HPD_EVENT);
                }
                else
                {
                    ScalerDpRx1LinkStatusIRQ();
                }
            }
#else
            ScalerDpRx1LinkStatusIRQ();
#endif
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Dp Version Switch
// Input Value  : DP input port, _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:
            SET_DP_RX_D0_PORT_TARGET_VERSION(enumDpVersion);
            SET_DP_RX_TARGET_MST_PORT(enumDpRxMstPort);
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _D1_INPUT_PORT:
            SET_DP_RX_D1_PORT_TARGET_VERSION(enumDpVersion);
            SET_DP_RX_TARGET_MST_PORT(enumDpRxMstPort);
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        case _D6_INPUT_PORT:
            SET_DP_RX_D6_PORT_TARGET_VERSION(enumDpVersion);
            SET_DP_RX_TARGET_MST_PORT(enumDpRxMstPort);
            SET_DP_RX_CAPABILITY_SWITCHED();
            break;
#endif

        default:
            break;
    }
}

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Mst Reset
// Input Value  : _DP_MST_RX0_PORT or _DP_MST_RX1_PORT
// Output Value : None
//--------------------------------------------------
void ScalerDpMstReset(EnumDPMSTPort enumRxMstPort)
{
// HW Reset-----------------------------------
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

    if(enumRxMstPort == _DP_MST_RX0_PORT)
    {
        ScalerDpRx0MstReset();
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

    if(enumRxMstPort == _DP_MST_RX1_PORT)
    {
        ScalerDpRx1MstReset();
    }
#endif

// FW Reset-----------------------------------

    // MSG Status Reset
    SET_DP_RX_MST_MODE_STATE(_DP_RX_MST_MODE_STATUS_NONE_MSG);
    SET_DP_RX_EVENT(_DP_RX_NONE_EVENT);

    ScalerDpRxMstClrStreamMuxBackup();

    // Reset Stream ID Mapping Table
    for(pData[0] = 0; pData[0] < 5; pData[0]++)
    {
        g_pucDpStreamToIdMapping[pData[0]] = 0;
    }

    // Clear Down Request MSG Proc Flags
    CLR_DP_RX_DOWN_REQUEST_ANAL();

    // Clear Down Reply MSG Proc Flags
    CLR_DP_RX_DOWN_REPLY_READY();
    CLR_DP_RX_DOWN_REPLY_SET_HPD();
    CLR_DP_RX_DOWN_REPLY_BYPASS();
    CLR_DP_RX_DOWN_REPLY_DIRECTLY();

#if(_DOWN_REPLY_MANUAL_MODE_SUPPORT == _ON)

    // Clear the Rx Down Reply MSG Segment Count No.
    g_ucDpDownReplyManualMsgCount = 0;

#endif

    // Free Request Pool Array
    SET_DP_REQUEST_POOL_FREE();

    // Free Reply Pool Array
    SET_DP_REPLY_POOL_FREE();

    // Free Reply Buffer
    SET_DP_RX_REPLY_BUF_FREE();

    // Reset Down Request Buffer Priority
    SET_DP_RX_DOWN_REQUEST_BUF_PRIORITY(_DP_DOWN_REQUEST_BUF0);

    // Clear Allocated Flag Manual Mode
    CLR_DP_RX_MANUAL_FORCE_SET_ACT();

    // Disable Read 2C0 INT
    CLR_REG_DP_RX_2C0_IRQ();

// Tx Reset-----------------------------------

#if(_DP_TX_SUPPORT == _ON)

    ScalerDpTxMstReset();

#endif
}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Rx HDCP Auth Handler
// Input Value  :
// Output Value :
//--------------------------------------------------
void ScalerDpHDCPHandler(void)
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    ScalerDpRx0HDCPHandler();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    ScalerDpRx1HDCPHandler();
#endif
}
#endif // #if(_DP_TX_SUPPORT == _ON)
#endif // #if(_DP_MST_SUPPORT == _ON)

#if(_DP_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Switch DP FREESYNC Support
// Input Value  : Hotplug Type and FREESYNC Enable or Not
// Output Value : None
//--------------------------------------------------
void ScalerDpFREESYNCSupportSwitch(EnumDpFREESYNCCapabilitySwitch enumDpFREESYNCCapSwitch, bit bEn)
{
    if(enumDpFREESYNCCapSwitch == _DP_FREESYNC_CAPABILITY_SWITCH)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        if(((bit)(ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07) & _BIT6)) != bEn)
        {
            SET_DP_RX_CAPABILITY_SWITCHED();
            SET_DP_RX0_FREESYNC_CAPABILITY_SWITCH();
        }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        if(((bit)(ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x07) & _BIT6)) != bEn)
        {
            SET_DP_RX_CAPABILITY_SWITCHED();
            SET_DP_RX1_FREESYNC_CAPABILITY_SWITCH();
        }
#endif
    }

    SET_FREESYNC_SUPPORT(bEn);

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

    SET_DP_RX0_FREESYNC_SUPPORT(bEn);

    if(bEn == _ON)
    {
        pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07);
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, (pData[0] | _BIT6));
    }
    else
    {
        CLR_FREESYNC_ENABLED();
        pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07);
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, (pData[0] & ~_BIT6));
    }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

    SET_DP_RX1_FREESYNC_SUPPORT(bEn);

    if(bEn == _ON)
    {
        pData[0] = ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x07);
        ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x07, (pData[0] | _BIT6));
    }
    else
    {
        CLR_FREESYNC_ENABLED();
        pData[0] = ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x07);
        ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x07, (pData[0] & ~_BIT6));
    }
#endif
}
//--------------------------------------------------
// Description  : Dp Get AMD SPD info
// Input Value  : None
// Output Value :
//--------------------------------------------------
BYTE ScalerDpGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent)
{
    switch(ScalerFmtCnvGetSourceType())
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _FC_SOURCE_D0:

            return ScalerDpRx0GetAmdSpdBackupInfo(enumContent);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _FC_SOURCE_D1:

            return ScalerDpRx1GetAmdSpdBackupInfo(enumContent);
#endif

        default:

            return 0;
    }
}
//--------------------------------------------------
// Description  : Get Current DP H Period
// Input Value  : None
// Output Value : H period in nano sec
//--------------------------------------------------
WORD ScalerDpGetHSPeriod(void)
{
    switch(ScalerGetBit(P30_00_SYNC_SELECT, (_BIT3 | _BIT2 | _BIT1 | _BIT0)))
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case 0x00:

            return ScalerDpRx0GetHPeriod();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case 0x01:

            return ScalerDpRx1GetHPeriod();
#endif

        default:

            return 0;
    }
}
//--------------------------------------------------
// Description  : Get Current DP H Sync Width
// Input Value  : None
// Output Value : H Sync Width in pixel clk
//--------------------------------------------------
WORD ScalerDpGetHSW(void)
{
    switch(ScalerGetBit(P30_00_SYNC_SELECT, (_BIT3 | _BIT2 | _BIT1 | _BIT0)))
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case 0x00:

            pData[0] = ((DWORD)ScalerDpRx0GetHSW() * _MEASURE_CLK / GET_INPUT_PIXEL_CLK() / 100);
            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case 0x01:

            pData[0] = ((DWORD)ScalerDpRx1GetHSW() * _MEASURE_CLK / GET_INPUT_PIXEL_CLK() / 100);
            break;
#endif

        default:
            pData[0] = 0;
            break;
    }

    return ((pData[0] == 0) ? 1 : pData[0]);
}
//--------------------------------------------------
// Description  : Dp Get Vfreq
// Input Value  : None
// Output Value : VFreq in 0.1Hz
//--------------------------------------------------
WORD ScalerDpGetVFreq(void)
{
    switch(ScalerFmtCnvGetSourceType())
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _FC_SOURCE_D0:

            return ScalerDpRx0GetVFreq();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _FC_SOURCE_D1:

            return ScalerDpRx1GetVFreq();
#endif

        default:

            return 0;
    }
}
//--------------------------------------------------
// Description  : Get Current DP V Period
// Input Value  : None
// Output Value : V period in line
//--------------------------------------------------
WORD ScalerDpGetVSPeriod(void)
{
    switch(ScalerFmtCnvGetSourceType())
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _FC_SOURCE_D0:

            return ScalerDpRx0GetVPeriod();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _FC_SOURCE_D1:

            return ScalerDpRx1GetVPeriod();
#endif

        default:

            return 0;
    }
}
#endif // End of #if(_DP_FREESYNC_SUPPORT == _ON)

#endif // End of #if(_DP_SUPPORT == _ON)
