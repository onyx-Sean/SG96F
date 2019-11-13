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
// ID Code      : ScalerDP_ComboPhy.c No.0000
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
void ScalerDpCapabilitySwitchProc(void);
void ScalerDpDpcdLinkStatusReset(BYTE ucInputPort);
void ScalerDpEdidSwitch(BYTE ucInputPort);
void ScalerDpFakeLinkTrainingSetting(BYTE ucInputPort);
void ScalerDpFirstActiveProc(BYTE ucInputPort);
EnumDpPowerState ScalerDpGetPowerStatus(BYTE ucInputPort);
EnumDpLaneCount ScalerDpGetLaneCount(BYTE ucInputPort);
EnumDpLinkRate ScalerDpGetLinkRate(BYTE ucInputPort);
EnumDpVoltageSwingLevel ScalerDpGetLaneVoltageSwingLv(BYTE ucInputPort, EnumDpLane enumDpLane);
EnumDpPreEmphasisLevel ScalerDpGetLanePreEmpLv(BYTE ucInputPort, EnumDpLane enumDpLane);
bit ScalerDpGetSrcMstEnable(BYTE ucInputPort);
bit ScalerDpHdcpCheckEnabled(BYTE ucInputPort);
void ScalerDpHotPlugEvent(BYTE ucInputPort, EnumDpHotPlugAssertType enumHpdType);
void ScalerDpInitial(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
void ScalerDpJudgeHPDToggle(EnumPowerAction enumPowerAction);
void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount);
void ScalerDpLowPowerProc(void);
bit ScalerDpNormalPreDetect(BYTE ucInputPort);
bit ScalerDpPSPreDetect(BYTE ucInputPort);
void ScalerDpResetProc(void);
void ScalerDpScanInitial(BYTE ucInputPort);
BYTE ScalerDpScanInputPort(BYTE ucInputPort);
bit ScalerDpStableDetect(BYTE ucInputPort);
void ScalerDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);

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
// Description  : Dp Capability Switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpCapabilitySwitchProc(void)
{
    bit bDPRx0DoLongHotPlug = _FALSE;

    if(GET_DP_RX_CAPABILITY_SWITCHED() == _TRUE)
    {
        DebugMessageMst("DP Cap Switch", GET_DP_RX_TARGET_MST_PORT());

#if(_DP_FREESYNC_SUPPORT == _ON)

        if(GET_DP_RX0_FREESYNC_CAPABILITY_SWITCH() == _TRUE)
        {
            CLR_DP_RX0_FREESYNC_CAPABILITY_SWITCH();
            bDPRx0DoLongHotPlug = _TRUE;
        }
#endif
        if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x00, 0x02, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) != GET_DP_RX_D0_PORT_TARGET_LANE_COUNT())
        {
            ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x02, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), GET_DP_RX_D0_PORT_TARGET_LANE_COUNT());

            bDPRx0DoLongHotPlug = _TRUE;
        }

        if(GET_DP_RX_D0_EDID_SWITCH() == _TRUE)
        {
            CLR_DP_RX_D0_EDID_SWITCH();

            bDPRx0DoLongHotPlug = _TRUE;
        }

        if(ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) != GET_DP_RX_D0_PORT_TARGET_VERSION())
        {
            ScalerDpRx0ChangeDpcdVersion(GET_DP_RX_D0_PORT_TARGET_VERSION(), GET_DP_RX_TARGET_MST_PORT());

            bDPRx0DoLongHotPlug = _TRUE;
        }

        CLR_DP_RX_CAPABILITY_SWITCHED();
    }

    if(bDPRx0DoLongHotPlug == _TRUE)
    {
        ScalerDpRx0HotPlugEvent(_DP_MST_LONG_HPD_EVENT);
    }
}
//--------------------------------------------------
// Description  : DPCD Link Status Field Reset
// Input Value  : Input Port
// Output Value : None
//--------------------------------------------------
void ScalerDpDpcdLinkStatusReset(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    ScalerDpRx0DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);
}
//--------------------------------------------------
// Description  : DP EDID Switch
// Input Value  : Input DP Port
// Output Value : None
//--------------------------------------------------
void ScalerDpEdidSwitch(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    SET_DP_RX_D0_EDID_SWITCH();
    SET_DP_RX_CAPABILITY_SWITCHED();
}
//--------------------------------------------------
// Description  : DP Fake Link Training Setting
// Input Value  : ucInputPortType
// Output Value : None
//--------------------------------------------------
void ScalerDpFakeLinkTrainingSetting(BYTE ucInputPort)
{
    if(((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (ucInputPort == _D0_INPUT_PORT)) ||
       ((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (ucInputPort == _D1_INPUT_PORT)) ||
       ((_D2_INPUT_PORT_TYPE == _D2_DP_PORT) && (ucInputPort == _D2_INPUT_PORT)))
    {
        return;
    }
    else
    {
        ScalerDpRx0FakeLTProtect();
    }
}
//--------------------------------------------------
// Description  : DP First Active Process
// Input Value  : ucInputPort
// Output Value : None
//--------------------------------------------------
void ScalerDpFirstActiveProc(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    ScalerDpRx0SetFifoWD(_ENABLE);
    ScalerDpRx0SetFifoIRQ(_ENABLE);
}

//--------------------------------------------------
// Description  : Get DP Power Status (DPCD 00600h)
// Input Value  : DP Input Port
// Output Value : DP Power Status
//--------------------------------------------------
EnumDpPowerState ScalerDpGetPowerStatus(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1)
    {
        return _DP_POWER_DOWN;
    }
    else if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0))
    {
        return _DP_POWER_DOWN_WITH_AUX;
    }

    return _DP_POWER_NORMAL;
}

//--------------------------------------------------
// Description  : Get DP Lane Count (DPCD 00101h)
// Input Value  : DP Input Port
// Output Value : DP Lane Count
//--------------------------------------------------
EnumDpLaneCount ScalerDpGetLaneCount(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    return (ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, 0x01, (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)));
}

//--------------------------------------------------
// Description  : Get DP Link Rate (DPCD 00100h)
// Input Value  : Input DP Port
// Output Value : DP Link Rate
//--------------------------------------------------
EnumDpLinkRate ScalerDpGetLinkRate(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    return (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00));
}

//--------------------------------------------------
// Description  : Get DP Voltage Swing Level (DPCD 00103h-00106h [1:0])
// Input Value  : DP Input Port, Lane #
// Output Value : DP Voltage Swing Level of the lane
//--------------------------------------------------
EnumDpVoltageSwingLevel ScalerDpGetLaneVoltageSwingLv(BYTE ucInputPort, EnumDpLane enumDpLane)
{
    ucInputPort = ucInputPort;

    return (ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, (0x03 + enumDpLane), (_BIT1 | _BIT0)));
}

//--------------------------------------------------
// Description  : Get DP Pre-emphasis Level (DPCD 00103h-00106h [4:3])
// Input Value  : DP Input Port, Lane #
// Output Value : DP Pre-emphasis Level of the lane
//--------------------------------------------------
EnumDpPreEmphasisLevel ScalerDpGetLanePreEmpLv(BYTE ucInputPort, EnumDpLane enumDpLane)
{
    ucInputPort = ucInputPort;

    return (ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, (0x03 + enumDpLane), (_BIT4 | _BIT3)) >> 3);
}

//--------------------------------------------------
// Description  : Get DP Source MST enable (DPCD 00111h[0])
// Input Value  : DP Input Port
// Output Value : _TRUE --> MST enable, _FALSE --> SST
//--------------------------------------------------
bit ScalerDpGetSrcMstEnable(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x01, 0x11, _BIT0) == _BIT0)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : Input Port
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerDpHdcpCheckEnabled(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    return ScalerDpRx0HdcpEnebled();
}
//--------------------------------------------------
// Description  : Dp HotPlug Event for interface
// Input Value  : Hot Plug Type
// Output Value : None
//--------------------------------------------------
void ScalerDpHotPlugEvent(BYTE ucInputPort, EnumDpHotPlugAssertType enumHpdType)
{
    ucInputPort = ucInputPort;

    ScalerDpRx0HotPlugEvent(enumHpdType);
}
//--------------------------------------------------
// Description  : Initial DP Settings
// Input Value  : DP port, DPCD version, Lane Count, MST Port
// Output Value : None
//--------------------------------------------------
void ScalerDpInitial(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort)
{
    ucInputPort = ucInputPort;
    ScalerDpRx0Initial(enumDpVersion, enumDpLaneCount, enumDpRxMstPort);
}
//--------------------------------------------------
// Description  : Decision DP HPD Toggle Behavior
// Input Value  : Power Action State
// Output Value : None
//--------------------------------------------------
void ScalerDpJudgeHPDToggle(EnumPowerAction enumPowerAction)
{
    if(enumPowerAction == _POWER_ACTION_OFF_TO_NORMAL)
    {
        ScalerDpRx0HPDPowerOfftoNormalProc(GET_DP_DC_OFF_HPD_HIGH());
    }
}
//--------------------------------------------------
// Description  : DP Lane Switch
// Input Value  : DP input port, DP Lane Count
// Output Value : None
//--------------------------------------------------
void ScalerDpLaneCountSwitch(BYTE ucInputPort, EnumDpLaneCount enumDpLaneCount)
{
    ucInputPort = ucInputPort;

    SET_DP_RX_D0_PORT_TARGET_LANE_COUNT(enumDpLaneCount);
    SET_DP_RX_CAPABILITY_SWITCHED();
}
//--------------------------------------------------
// Description  : DP Low Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpLowPowerProc(void)
{
    // Turn Off Output Clock
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~_BIT6, 0x00);

    // Turn Off SCLK PLL
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    // Set Data State to End State trigger Aux Int, Clear Aux INT Flag
    ScalerSetBit(PB7_7A_AUX_DIG_PHYA, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));

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
}
//--------------------------------------------------
// Description  : Signal PreDetection for DP(Power Normal)
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpNormalPreDetect(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
    return ScalerDpRx0NormalPreDetect();
}
//--------------------------------------------------
// Description  : Signal Detection for DP(Power Saving)
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpPSPreDetect(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
    return ScalerDpRx0PSPreDetect();
}
//--------------------------------------------------
// Description  : DP Reset Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpResetProc(void)
{
    // Disable DP Fifo Under/OverFlow Watch Dog
    ScalerDpRx0SetFifoWD(_DISABLE);

    // Disable DP Fifo Under/OverFlow IRQ
    ScalerDpRx0SetFifoIRQ(_DISABLE);
}
//--------------------------------------------------
// Description  : Initial Setting for DP Scanning Port(Power Normal)
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : None
//--------------------------------------------------
void ScalerDpScanInitial(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    ScalerDpRx0MacInitial();

    ScalerDpRx0PhyInitial();

    CLR_DP_RX0_FAKE_LINK_TRAINING();
}
//--------------------------------------------------
// Description  : DP Port Source/Sync Scanning and Setting
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : Source DP --> DP Sync Stable
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerDpScanInputPort(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
    return ScalerDpRx0ScanInputPort();
}
//--------------------------------------------------
// Description  : On Line Check DP stability
// Input Value  : _D0_INPUT_PORT or _D1_INPUT_PORT
// Output Value : True --> DP Stable
//                False --> DP Unstable
//--------------------------------------------------
bit ScalerDpStableDetect(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
    return ScalerDpRx0StableDetect();
}
//--------------------------------------------------
// Description  : Dp Version Switch
// Input Value  : DP input port, _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpVersionSwitch(BYTE ucInputPort, EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort)
{
    ucInputPort = ucInputPort;

    SET_DP_RX_D0_PORT_TARGET_VERSION(enumDpVersion);
    SET_DP_RX_TARGET_MST_PORT(enumDpRxMstPort);
    SET_DP_RX_CAPABILITY_SWITCHED();
}

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
        if(((bit)(ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07) & _BIT6)) != bEn)
        {
            SET_DP_RX_CAPABILITY_SWITCHED();
            SET_DP_RX0_FREESYNC_CAPABILITY_SWITCH();
        }
    }

    SET_FREESYNC_SUPPORT(bEn);
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
}
//--------------------------------------------------
// Description  : Dp Get AMD SPD info
// Input Value  : None
// Output Value :
//--------------------------------------------------
BYTE ScalerDpGetAmdSpdInfo(EnumAmdSpdInfoContent enumContent)
{
    return ScalerDpRx0GetAmdSpdBackupInfo(enumContent);
}
//--------------------------------------------------
// Description  : Get Current DP H Period
// Input Value  : None
// Output Value : H period in nano sec
//--------------------------------------------------
WORD ScalerDpGetHSPeriod(void)
{
    return ScalerDpRx0GetHPeriod();
}
//--------------------------------------------------
// Description  : Get Current DP H Sync Width
// Input Value  : None
// Output Value : H Sync Width in pixel clk
//--------------------------------------------------
WORD ScalerDpGetHSW(void)
{
    pData[0] = ((DWORD)ScalerDpRx0GetHSW() * _MEASURE_CLK / GET_INPUT_PIXEL_CLK() / 100);

    return ((pData[0] == 0) ? 1 : pData[0]);
}
//--------------------------------------------------
// Description  : Dp Get Vfreq
// Input Value  : None
// Output Value : VFreq in 0.1Hz
//--------------------------------------------------
WORD ScalerDpGetVFreq(void)
{
    return ScalerDpRx0GetVFreq();
}
//--------------------------------------------------
// Description  : Get Current DP V Period
// Input Value  : None
// Output Value : V period in line
//--------------------------------------------------
WORD ScalerDpGetVSPeriod(void)
{
    return ScalerDpRx0GetVPeriod();
}
#endif

#endif
