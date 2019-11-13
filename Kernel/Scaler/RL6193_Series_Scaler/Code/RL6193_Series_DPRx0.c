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
// ID Code      : RL6193_Series_DPRx0.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_DPRX0__

#include "ScalerFunctionInclude.h"

#if(_D0_DP_EXIST == _ON)

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
bit g_bDpRx0PSAuxToggle = _FALSE;

// Add for DPCD 2002h Bug
bit g_bDpRx0PowerStateIntoPS = _FALSE;
bit g_bDpRx0AuxCommandNoReply = _FALSE;

BYTE g_ucDpRx0LinkStatus01;
BYTE g_ucDpRx0LinkStatus23;
BYTE g_ucDpRx0LinkRequest01;
BYTE g_ucDpRx0LinkRequest23;
BYTE g_ucDpRx0Temp;
BYTE g_pucDpRx0Backup[3];
BYTE g_ucDpRx0Info;
BYTE g_ucDpRx0LinkRate;
BYTE g_ucDpRx0LaneCount;
BYTE g_ucDpRx0TrainingPatternSet;

BYTE g_pucDpRx0Tap0MaxTemp[4];
BYTE g_pucDpRx0LEMinTemp[4];
BYTE g_pucDpRx0LEMaxTemp[4];
BYTE g_pucDpRx0Tap1MaxTemp[4];
BYTE g_ucDpRx0EQCRC;
WORD g_usDpRx0ClockCount;
WORD g_usDpRx0ClockCount1;
BYTE g_ucRx0AuxTemp;
BYTE g_ucRx0AuxTemp_EXINT;
WORD g_usDpRx0Vfrontporch;

#if(_DP_TX_SUPPORT == _ON)
bit g_bDpRx0HdcpAksvWritten = 0;
WORD g_usDpRx0HdcpKsvFifoOffset;
StructDPRxHDCPAuthInfo g_stDpRx0HDCPAuthInfo;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerDpRx0AuxIntInitial(void);
void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
void ScalerDpRx0ChangeDpcdVersion(EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
void ScalerDpRx0HotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
void ScalerDpRx0HotPlugDuration(EnumDpHotPlugTime enumHpdTime);
void ScalerDpRx0MacInitial(void);
void ScalerDpRx0PhyInitial(void);
void ScalerDpRx0CMUNFCodeSetting(EnumDpNFCodeRef enumDpNFCodeRef, EnumDpLinkRate enumLinkRate);
void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane);
void ScalerDpRx0SetDFEInitial(EnumDpLinkRate enumDpLinkRate);
bit ScalerDpRx0CDRCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane);
bit ScalerDpRx0MeasureLaneCDRClk(BYTE ucDpLinkRate, BYTE ucDpRx0LaneNumber);
void ScalerDpRx0ValidSignalDetection(void);
bit ScalerDpRx0DecodeCheck(void);
void ScalerDpRx0SetNoVideoStreamIRQ(bit bEn);
bit ScalerDpRx0DFECheck(void);
void ScalerDpRx0SignalDetectInitial(BYTE ucDpLinkRate);
bit ScalerDpRx0SignalCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane);
bit ScalerDpRx0DisplayFormatSetting(void);

#if(_DP_TX_SUPPORT == _ON)
void ScalerDpRx0UpdateSinkCount(void);
#endif

bit ScalerDpRx0InterlaceCheck(WORD *pusVTotal, BYTE *pucOddFlg);
bit ScalerDpRx0StreamClkRegenerate(void);
bit ScalerDpRx0FifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
bit ScalerDpRx0HdcpCheck(void);
bit ScalerDpRx0HdcpReAuthStatusCheck(void);
bit ScalerDpRx0HdcpMeasureCheck(void);
void ScalerDpRx0CpIRQ(EnumDpRxBStatusType enumBStatusType);
bit ScalerDpRx0HdcpEnebled(void);
void ScalerDpRx0PhyCtsTp1SetPhy(EnumDpNFCodeRef enumDpNFCodeRef);
void ScalerDpRx0PhyCtsACDR(void);
void ScalerDpRx0PhyCtsTp2SetPhy(void);
bit ScalerDpRx0PhyCtsTp1Check(void);
bit ScalerDpRx0PhyCtsTp2Check(void);
void ScalerDpRx0PhyCTS(void);
void ScalerDpRx0SetFifoWD(bit bEn);
void ScalerDpRx0SetFifoIRQ(bit bEn);
bit ScalerDpRx0NormalPreDetect(void);
BYTE ScalerDpRx0ScanInputPort(void);
bit ScalerDpRx0StableDetect(void);
void ScalerDpRx0HPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHighStatus);

#if(_DP_MST_SUPPORT == _ON)

bit ScalerDpRx0LTStatusCheck(void);
void ScalerDpRx0AuxChPowerStatusCheck(bit bCableStatus);

#if(_DP_TX_SUPPORT == _ON)
bit ScalerDpRx0MstToSstStreamClkRegenerate(void);
bit ScalerDpRx0MstToSstInterlaceCheck(WORD *pusVTotal, BYTE *pucOddFlg);
bit ScalerDpRx0MstToSstDisplayFormatSetting(void);
bit ScalerDpRx0MstToSstFifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
bit ScalerDpRx0MstToSstMeasureInput(void);
void ScalerDpRx0HDCPEnableReadIrq(bit bEnable);
#endif

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Initial Setting for DP Digital Aux, Analog Aux, Aux INT
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AuxIntInitial(void)
{
    // Digital Aux Power On, DPCD REG Power On, MSG Power On.
    ScalerSetBit(PB7_C0_DPCD_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT1 | _BIT0), 0x00);

    // Average 8 cycles as Start Postion, Aux Clk Select to 27MHz, no Swap
    ScalerSetByte(PB7_72_AUX_DIG_PHY2, 0xC0);

    // Aux Clk Select Manual Mode, Aux New Mode
    ScalerSetBit(PB7_73_AUX_DIG_PHY3, ~(_BIT7 | _BIT6), _BIT6);

    // HW Fake Link Training Disable.
    ScalerSetBit(PB7_C6_AUX_PHY_DIG2, ~_BIT4, 0x00);

    // Set Aux Precharge Number.
    ScalerSetBit(PB7_74_AUX_DIG_PHY4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));

    // Aux Auto Mode, Using Default Average Number.
    ScalerSetByte(PB7_75_AUX_DIG_PHY5, 0x0D);

    // Enble Aux Channel.
    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~(_BIT3 | _BIT2 | _BIT0), _BIT0);

    // Fast IIC Clock.
    ScalerSetByte(PB7_D1_DP_IIC_SET, 0x02);

    // Enable 068xxx INT
    ScalerSetBit(PB7_DA_AUX_FIFO_RST, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

    // Not Reply when Aux Error.
    ScalerSetBit(PB7_DB_AUX_STATUS, ~(_BIT5 | _BIT4), _BIT4);
    ScalerSetBit(PB7_76_AUX_DIG_PHY6, ~(_BIT7 | _BIT6), _BIT6);

    // Disable other DPCD, Aux Timeout, Receiving Aux INT.
    ScalerSetBit(PB7_DC_AUX_IRQ_STATUS, ~(_BIT5 | _BIT3 | _BIT2), 0x00);

    // Disable Aux Phy Int
    ScalerSetBit(PB7_77_AUX_DIG_PHY7, ~_BIT7, 0x00);

    // Enable DPCD INT
    ScalerSetByte(PB7_DE_AUX_DPCD_IRQ_EN, 0xE5);

    // Aux Ack Timer.
    ScalerSetBit(PB7_F0_AUX_TX_TIMER, ~(_BIT5 | _BIT2), (_BIT5 | _BIT2));

    // Set Timeout Target
    ScalerSetBit(PB7_F1_AUX_TX_TIMER_2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT0));

    // Disable Reply IIC Defer Before Data Ready.
    ScalerSetBit(PB7_F4_MCUIIC, ~(_BIT6 | _BIT5), 0x00);

    // Enable Aux Error Handler.
    ScalerSetBit(PB7_78_AUX_DIG_PHY8, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4));

    // Toggle Aux Auto K
    ScalerSetBit(PB7_65_AUX_5, ~_BIT7, 0x00);
    ScalerSetBit(PB7_65_AUX_5, ~_BIT7, _BIT7);

    // Aux Mode Set (Diff Mode or Single-ended mode)
    ScalerDpRx0AuxDiffModeSet();

    // Set Aux Talk Mode ADJR
    ScalerSetByte(PB7_67_DIG_TX_03, 0xFF);

    ScalerSetBit(PB7_60_DIG_TX_04, ~(_BIT1 | _BIT0), _BIT0);

    // Aux comm current select max
    ScalerSetBit(PB7_64_AUX_4, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // Set Aux D_2 = ~D_1 for Aux Single Ended Mode
    ScalerSetBit(PB7_79_AUX_DIG_PHY9, ~_BIT7, _BIT7);

    // Internal IRQ Enable (Global)
    ScalerGlobalIRQControl(_ENABLE);

    // Aux ps clk from IOSC
    ScalerSetBit(P0_0B_POWER_CTRL, ~(_BIT5 | _BIT4), 0x00);

    if(ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE)
    {
        // Clear DPCD 0x2002 INT Status Flag
        ScalerSetBit(PB7_FB_DUMMY_1, ~_BIT7, _BIT7);

        // Enable DPCD 0x2002 INT
        ScalerSetBit(PB7_FB_DUMMY_1, ~(_BIT7 | _BIT6), _BIT6);
    }

    // Enable INT0
    EX0 = 1;
}

//--------------------------------------------------
// Description  : DPCD Table Initial
// Input Value  : _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort)
{
    ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT0, _DP_SINK_OUT_OF_SYNC);
    ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT1, _DP_SINK_OUT_OF_SYNC);

    ScalerDpRx0ChangeDpcdVersion(enumDpVersion, enumDpRxMstPort);

    // Enhanced Framing Support(Bit7) and DP Lane Count(Bit[4:0])
    pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x02);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x02, ((pData[0] & ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) | _BIT7 | enumDpLaneCount));

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x03, 0x01);

#if(_AUDIO_SUPPORT == _ON)
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x04, 0x21);
#else
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x04, 0x20);
#endif

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x06, 0x01);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x08, 0x02);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x09, 0x00);

    // Set TRAINING_AUX_RD_INTERVAL
    ScalerDpRx0SetDpcdBitValue(0x00, 0x00, 0x0E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _DP_RX_DPCD_TRAINING_AUX_RD_INTERVAL);

#if(_AUDIO_SUPPORT == _ON)
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0A, 0x06);
#else
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0A, 0x00);
#endif

    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0B, 0x00);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x0D, 0x01);
#endif

    // DPCD Link Status Field Setting
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x01, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x05, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x08, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x09, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x0A, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x0B, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x10, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x11, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x12, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x13, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x14, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x15, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x16, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x17, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x46, 0x20);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
    // _BIT3:0, Down Stream Port Counter
    pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, ((pData[0] & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)) | _BIT0));

    // Down Stream Port is HPD Aware
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x80, 0x08);

    // _BIT1: Repeater,  _BIT0: HDCP Capable
    ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x28, 0x03);
#else
    // _BIT3:0, Down Stream Port Counter
    pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07);
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, (pData[0] & ~(_BIT3 | _BIT2 | _BIT1 | _BIT0)));

    // Down Stream Port isn't HPD Aware
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x80, 0x00);

    // _BIT1: Repeater,  _BIT0: HDCP Capable
    ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x28, 0x01);
#endif
}

//--------------------------------------------------
// Description  : Dp Version Switch
// Input Value  : _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0ChangeDpcdVersion(EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort)
{
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

    if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
    {
#if(_D0_DP_LINK_CLK_RATE == _DP_LOW_SPEED_162MHZ)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_RBR);
#elif(_D0_DP_LINK_CLK_RATE == _DP_HIGH_SPEED_270MHZ)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);
#endif
    }
    else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
    {
#if(_D6_DP_LINK_CLK_RATE == _DP_LOW_SPEED_162MHZ)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_RBR);
#elif(_D6_DP_LINK_CLK_RATE == _DP_HIGH_SPEED_270MHZ)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);
#endif
    }
#else // Else of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

#if(_D0_DP_LINK_CLK_RATE == _DP_LOW_SPEED_162MHZ)
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_RBR);
#elif(_D0_DP_LINK_CLK_RATE == _DP_HIGH_SPEED_270MHZ)
    ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);
#endif

#endif // End of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

    if(enumDpVersion == _DP_VERSION_1_2)
    {
        // DPCD Capability Field Initial
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x00, 0x12);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
        {
#if(_D0_DP_LINK_CLK_RATE == _DP_HIGH_SPEED2_540MHZ)
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR2);
#endif
        }
        else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
        {
#if(_D6_DP_LINK_CLK_RATE == _DP_HIGH_SPEED2_540MHZ)
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR2);
#endif
        }
#else // Else of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

#if(_D0_DP_LINK_CLK_RATE == _DP_HIGH_SPEED2_540MHZ)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR2);
#endif

#endif // End of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x02);

        if(ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) == _DP_LINK_HBR2)
        {
            // TPS3 Support
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x02, ((pData[0] & ~_BIT6) | _BIT6));
        }
        else
        {
            // TPS3 NonSupport
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x02, (pData[0] & ~_BIT6));
        }

        // _BIT7 = 1: Always IEEE OUI Support Under DP1.2
        pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07);
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, ((pData[0] & ~_BIT7) | _BIT7));

        // Sink IEEE OUI
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x00, _DP_SINK_RTK_IEEE_OUI_L);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x01, _DP_SINK_RTK_IEEE_OUI_M);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x02, _DP_SINK_RTK_IEEE_OUI_H);

        // Sink IEEE OUI LSB For DP1.2
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x03, _DP_SINK_RTK_ID_STRING_0);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x04, _DP_SINK_RTK_ID_STRING_1);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x05, _DP_SINK_RTK_ID_STRING_2);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x06, _DP_SINK_RTK_ID_STRING_3);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x07, _DP_SINK_RTK_ID_STRING_4);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x08, _DP_SINK_RTK_ID_STRING_5);

        // Sink HW/FW Version For DP1.2
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x09, _DP_SINK_RTK_HW_VERSION);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x0A, _DP_SINK_RTK_FW_VERSION_H);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x0B, _DP_SINK_RTK_FW_VERSION_L);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
        // Branch IEEE OUI
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x00, _DP_BRANCH_RTK_IEEE_OUI_L);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x01, _DP_BRANCH_RTK_IEEE_OUI_M);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x02, _DP_BRANCH_RTK_IEEE_OUI_H);

        // Branch IEEE OUI LSB For DP1.2
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x03, _DP_BRANCH_RTK_ID_STRING_0);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x04, _DP_BRANCH_RTK_ID_STRING_1);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x05, _DP_BRANCH_RTK_ID_STRING_2);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x06, _DP_BRANCH_RTK_ID_STRING_3);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x07, _DP_BRANCH_RTK_ID_STRING_4);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x08, _DP_BRANCH_RTK_ID_STRING_5);

        // Branch HW/FW Version
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x09, _DP_BRANCH_RTK_HW_VERSION);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x0A, _DP_BRANCH_RTK_FW_VERSION_H);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x0B, _DP_BRANCH_RTK_FW_VERSION_L);
#endif

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if((enumDpRxMstPort == _DP_MST_RX0_PORT) || (enumDpRxMstPort == _DP_MST_RX6_PORT))
#else
        if(enumDpRxMstPort == _DP_MST_RX0_PORT)
#endif
        {
            // Down Sream Port Present
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x05, 0x01);

            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x21, 0x01);
        }
        else
        {
            // Down Sream Port isn't Present
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x05, 0x00);

            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x21, 0x00);
        }
    }
    else
    {
        // DPCD Capability Field Initial
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x00, 0x11);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
        {
#if(_D0_DP_LINK_CLK_RATE == _DP_HIGH_SPEED2_540MHZ)
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);
#endif
        }
        else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
        {
#if(_D6_DP_LINK_CLK_RATE == _DP_HIGH_SPEED2_540MHZ)
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);
#endif
        }
#else // Else of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

#if(_D0_DP_LINK_CLK_RATE == _DP_HIGH_SPEED2_540MHZ)
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _DP_LINK_HBR);
#endif

#endif // End of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        // TPS3 NonSupport
        pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x02);
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x02, (pData[0] & ~_BIT6));

        // Back DPCD Table Address 0x00007
        pData[0] = ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x07);

#if(_DP_SINK_VER11_OUI_SUPPORT == _ON)
        // _BIT7 = 1: IEEE OUI Support
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, ((pData[0] & ~_BIT7) | _BIT7));

        // Sink IEEE OUI
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x00, _DP_SINK_RTK_IEEE_OUI_L);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x01, _DP_SINK_RTK_IEEE_OUI_M);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x02, _DP_SINK_RTK_IEEE_OUI_H);
#else
        // _BIT7 = 0: IEEE OUI Not Support
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x07, (pData[0] & ~_BIT7));

        // Sink IEEE OUI
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x00, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x01, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x02, 0x00);
#endif

        // Sink IEEE OUI LSB For DP1.1
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x03, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x04, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x05, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x06, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x07, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x08, 0x00);

        // Sink HW/FW Version For DP1.1
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x09, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x0A, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x0B, 0x00);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
#if(_DP_SINK_VER11_OUI_SUPPORT == _ON)
        // Branch IEEE OUI
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x00, _DP_BRANCH_RTK_IEEE_OUI_L);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x01, _DP_BRANCH_RTK_IEEE_OUI_M);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x02, _DP_BRANCH_RTK_IEEE_OUI_H);
#else
        // Branch IEEE OUI
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x00, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x01, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x02, 0x00);
#endif
        // Branch IEEE OUI LSB For DP1.1
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x03, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x04, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x05, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x06, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x07, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x08, 0x00);

        // Branch HW/FW Version For DP1.1
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x09, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x0A, 0x00);
        ScalerDpRx0SetDpcdValue(0x00, 0x05, 0x0B, 0x00);
#endif

        // Down Sream Port isn't Present
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x05, 0x00);

        // MST Capability Disable
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x21, 0x00);
    }

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
    ScalerDpRx0HDCPBlockReset();
#endif
}

//--------------------------------------------------
// Description  : Dp HotPlug Event
// Input Value  : Hot Plug Type
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0HotPlugEvent(EnumDpHotPlugAssertType enumHpdType)
{
    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_RX0_DP_LINK_TRAINING_REBUILD_PHY);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HOTPLUG_ASSERTED);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_VALID_SIGNAL_DETECT_CHECK);

#if(_DP_MST_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
#if(_DP_TX_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_CPIRQ_EVENT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_REPEATER_PROC_TIMEOUT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_READ_IRQ_TIMEOUT);
#endif
#endif

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if((enumHpdType != _DP_HDCP_LONG_HPD_EVENT) && (enumHpdType != _DP_HBR2_MARGIN_LINK_HPD_EVENT) && (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2))
    {
        if((GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) && (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) < _D0_DP_LINK_CLK_RATE) && (_D0_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
        {
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D0_DP_LINK_CLK_RATE);
            DebugMessageRx0("Flag Clear_Hotplug Event", ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));
        }
        else if((GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT) && (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) < _D6_DP_LINK_CLK_RATE) && (_D6_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
        {
            ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D6_DP_LINK_CLK_RATE);
            DebugMessageRx0("Flag Clear_Hotplug Event", ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));
        }
    }
#else
    if((enumHpdType != _DP_HDCP_LONG_HPD_EVENT) && (enumHpdType != _DP_HBR2_MARGIN_LINK_HPD_EVENT) &&
       (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2) && (ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01) < _D0_DP_LINK_CLK_RATE) && (_D0_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x01, _D0_DP_LINK_CLK_RATE);
        DebugMessageRx0("Flag Clear_Hotplug Event", ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));
    }
#endif
#endif

    if(enumHpdType == _DP_HPD_ASSERTED)
    {
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if((PCB_D0_HOTPLUG_DETECT() == _D0_HOT_PLUG_HIGH) && (GET_D6_SWITCH_POWER_STATUS() == _DIGITAL_D6_SWITCH_POWER_ON))
#else
        if(PCB_D0_HOTPLUG_DETECT() == _D0_HOT_PLUG_HIGH)
#endif
        {
            return;
        }
    }
    else
    {
        ScalerDpRx0AVMute();
    }

    if(enumHpdType == _DP_HPD_LOW)
    {
        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);

        return;
    }
    else if(enumHpdType == _DP_HPD_LOW_RESET_AUX)
    {
        // Reset Aux
        ScalerSetBit(PB7_C0_DPCD_CTRL, ~_BIT7, _BIT7);

        PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);

        return;
    }

    // Reset DDC0
    MCU_FF1F_DDC0_DDC_CONTROL_1 |= _BIT1;

    // Release Aux
    ScalerSetBit(PB7_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerDpRx0DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);

#if(_DP_FREESYNC_SUPPORT == _ON)
    SET_DP_RX0_AUX_MANUAL_MODE();
    ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x07, 0x00);
    SET_DP_RX0_AUX_AUTO_MODE();
#endif

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
    ScalerDpRx0HDCPBlockReset();
#endif

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    SET_DP_RX0_AUX_MANUAL_MODE();
    ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x0A, 0x00);
    SET_DP_RX0_AUX_AUTO_MODE();
#endif

    if(enumHpdType == _DP_LONG_HPD_EVENT)
    {
        ScalerDpRx0HotPlugDuration(_DP_LONG_HPD_TIME);
    }
    else if(enumHpdType == _DP_HDCP_LONG_HPD_EVENT)
    {
        ScalerDpRx0HotPlugDuration(_DP_HDCP_LONG_HPD_TIME);
    }
    else if(enumHpdType == _DP_MST_LONG_HPD_EVENT)
    {
        // Reset Aux
        ScalerSetBit(PB7_C0_DPCD_CTRL, ~_BIT7, _BIT7);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
        // No Receiving Topology Rebuild MSG within 4s
        if(GET_DP_TX_WAIT_TOPOLOGY_REBUILD_MSG() == _TRUE)
        {
            ScalerDpRx0HotPlugDuration(_DP_MST_FORCE_LONG_HPD_TIME);
        }
        else
#endif
        {
            ScalerDpRx0HotPlugDuration(_DP_MST_LONG_HPD_TIME);
        }
    }
#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
    else if(enumHpdType == _DP_HBR2_MARGIN_LINK_HPD_EVENT)
    {
#if(_DP_MST_SUPPORT == _ON)
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if(((GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) && (g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)) ||
           ((GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT) && (g_enumDpMSTCapablePort == _DP_MST_RX6_PORT)))
#else
        if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
#endif
        {
            ScalerDpRx0MstReset();
        }
#endif
        ScalerDpRx0HotPlugDuration(800);
    }
#endif
    else
    {
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))

        if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
        {
            PCB_DIGITAL_D0_D6_SWITCH_LANE(_DP_D0_D6_SWITCH_D0);
            PCB_DIGITAL_D0_D6_SWITCH_AUX_HPD(_DP_D0_D6_SWITCH_D0);
            ScalerMcuDdcRamEDIDAddrSelect(_D0_DDCRAM, _DDCRAM_TOP_ADDR);
        }
        else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
        {
            PCB_DIGITAL_D0_D6_SWITCH_LANE(_DP_D0_D6_SWITCH_D6);
            PCB_DIGITAL_D0_D6_SWITCH_AUX_HPD(_DP_D0_D6_SWITCH_D6);
            ScalerMcuDdcRamEDIDAddrSelect(_D0_DDCRAM, _DDCRAM_BOTTOM_ADDR);
        }

        PCB_DIGITAL_D6_SWITCH_POWER(_DIGITAL_D6_SWITCH_POWER_ON);
        SET_D6_SWITCH_POWER_STATUS(_DIGITAL_D6_SWITCH_POWER_ON);
#endif
        ScalerDpRx0HotPlugDuration(_DP_HPD_ASSERTED_TIME);
    }

    // Reset Aux
    ScalerSetBit(PB7_C0_DPCD_CTRL, ~_BIT7, _BIT7);

    // Release Aux
    ScalerSetBit(PB7_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, 0x00);

    ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x00, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x01, (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0xE0));

    ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if((GET_D6_SWITCH_POWER_STATUS() == _DIGITAL_D6_SWITCH_POWER_ON) && (GET_DP_AUTO_SEARCH_SWITCH() == _FALSE) &&
       (((GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) && (GET_D0_CABLE_STATUS() == _TRUE)) ||
        ((GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT) && (GET_D6_CABLE_STATUS() == _TRUE))))
#else
    if(GET_D0_CABLE_STATUS() == _TRUE)
#endif
    {
#if(_DP_MST_SUPPORT == _ON)
        ScalerTimerActiveTimerEvent(SEC(3), _SCALER_TIMER_EVENT_DP_RX0_VALID_SIGNAL_DETECT_CHECK);
#else
        ScalerTimerActiveTimerEvent(SEC(1.2), _SCALER_TIMER_EVENT_DP_RX0_VALID_SIGNAL_DETECT_CHECK);
#endif
    }
}

//--------------------------------------------------
// Description  : Hot Plug Low Pulse Duration
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0HotPlugDuration(EnumDpHotPlugTime enumHpdTime)
{
#if(_DP_TX_SUPPORT == _ON)
    BYTE ucBackUp1 = 0;
#endif
    BYTE ucBackUp2 = 0;

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if(((GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) && (GET_D0_CABLE_STATUS() == _TRUE)) ||
       ((GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT) && (GET_D6_CABLE_STATUS() == _TRUE)))
#else
    if(GET_D0_CABLE_STATUS() == _TRUE)
#endif
    {
        if(enumHpdTime != 1)
        {
            if(enumHpdTime != 0)
            {
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
                if(GET_D6_SWITCH_POWER_STATUS() == _DIGITAL_D6_SWITCH_POWER_ON)
#endif
                {
#if(_DP_TX_SUPPORT == _ON)
                    if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D0_PORT)
                    {
                        ScalerDpTxForceIdlePatternSetting();
                    }
#endif
                    PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);
                    ScalerTimerDelayXms(enumHpdTime);
                }
            }

#if(_DP_TX_SUPPORT == _ON)
            ScalerDpRx0UpdateSinkCount();
#endif

            PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);
        }
        else
        {
#if(_DP_TX_SUPPORT == _ON)
            // Disable IRQs that take too long
            ucBackUp1 = ScalerGetBit(PBB_72_HPD_IRQ_EN, _BIT6);
            ScalerSetBit(PBB_72_HPD_IRQ_EN, ~_BIT6, 0x00);
#endif

            ucBackUp2 = ScalerGetByte(PB7_D0_AUX_MODE_SET);

            SET_DP_RX0_AUX_MANUAL_MODE();

            PCB_D0_HOTPLUG(_D0_HOT_PLUG_LOW);

            for(pData[0] = 0; pData[0] < 85; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            PCB_D0_HOTPLUG(_D0_HOT_PLUG_HIGH);

            if((ucBackUp2 & _BIT1) == _BIT1)
            {
                SET_DP_RX0_AUX_AUTO_MODE();
            }

#if(_DP_TX_SUPPORT == _ON)
            ScalerSetBit(PBB_72_HPD_IRQ_EN, ~_BIT6, ucBackUp1);
#endif
        }
    }
}

//--------------------------------------------------
// Description  : Dp Mac Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0MacInitial(void)
{
    // Set Digital Phy to Normal
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

    // Select DP
    ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, 0x00);

    // DP Lane Swap Setting
    ScalerSetByte(PB_03_LANE_MUX, 0xE4);

    // DP RGB Output Enable
    ScalerSetBit(PB5_31_DP_OUTPUT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

    // DP CLK Output Enable
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~_BIT6, _BIT6);

    // 0x00:disable error correction, 0xF4:enable all error correction
    ScalerSetBit(PB6_00_MN_STRM_ATTR_CTRL, ~_BIT1, _BIT1);

    // Disable DP Fifo Under/OverFlow Watch Dog
    ScalerDpRx0SetFifoWD(_DISABLE);

    // Disable DP Fifo Under/OverFlow IRQ
    ScalerDpRx0SetFifoIRQ(_DISABLE);

    // Disable DP No Video Stream IRQ
    ScalerDpRx0SetNoVideoStreamIRQ(_DISABLE);

    ScalerDpRx0SetInitialRSV0InfoType();

#if((_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON) && (_HW_DP_VSC_SDP_REG_SUPPORT != _ON))
    ScalerDpRx0SetInitialRSV1InfoType();
#endif

    CLR_DP_RX0_MSA_FAIL_MAC_RESET_COUNT();
}

//--------------------------------------------------
// Description  : DP Phy Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyInitial(void)
{
    /////////////
    // Rx Misc //
    /////////////

    // [7] mhl_mode = 1'b0 --> Disable MHL Mode
    // [6] en_mhl_op = 1'b0 --> Disable D0 Port MHL OP
    ScalerSetBit(PB_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

    /////////////////////////
    // CMU CDR DFE Setting //
    /////////////////////////

    // [4] CMU_en_awdog = 1'b0 --> Disable CMU WatchDog
    // [3] CMU_CKSEL = 1'b0 --> Ref. XTAL
    // [2] CMU_Sel_D4 = 1'b0 --> CMU Feedback Loop Divider = 1
    ScalerSetBit(PB_A5_CMU_05, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

    // [0] PLL_WD_EN = 1'b0 --> Disable WD
    ScalerSetBit(PB_F4_WD_00, ~_BIT0, 0x00);

    // [4] SEL_DFE_DELAY = 1'b0 --> Normal DFE Delay
    ScalerSetBit(PB_A6_CMU_06, ~_BIT4, 0x00);

    // [0] De_brank_en = 1'b0 --> Disable Blank Function
    ScalerSetBit(P1D_AF_L0_GDI_DE, ~_BIT0, 0x00);
    ScalerSetBit(P1D_BF_L1_GDI_DE, ~_BIT0, 0x00);
    ScalerSetBit(P1D_CF_L2_GDI_DE, ~_BIT0, 0x00);
    ScalerSetBit(P1D_DF_L3_GDI_DE, ~_BIT0, 0x00);

    // Disable Tap2 Delay
    ScalerSetBit(PB_B2_EQ_00, ~_BIT0, 0x00);

    // [7:5] LE_lowgain_highboost = 3'b100 --> LE HighBoost Mode
    ScalerSetBit(PB_A8_CMU_08, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);

    // Set Digital PHY Sampling Edge
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // en_wide_temp = 1'b1
    ScalerSetBit(PB_AB_CDR_02, ~_BIT0, _BIT0);

    // [7:4] Enable Data Stream Signal Detection
    ScalerSetBit(PB_BA_DP_SIG_DET_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
}

//--------------------------------------------------
// Description  : DP CDR N.F. Code Setting
// Input Value  : Link Rate and N.F. Code Clock Ref.
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0CMUNFCodeSetting(EnumDpNFCodeRef enumDpNFCodeRef, EnumDpLinkRate enumLinkRate)
{
    WORD usCMUNCode = 0;
    WORD usCMUFCode = 0;
    WORD usCount = 0;
    DWORD ulFreqDetect = 0;

    if(enumDpNFCodeRef == _DP_NF_REF_XTAL)
    {
        if(enumLinkRate == _DP_LINK_RBR)
        {
            usCMUNCode = 109;
            usCMUFCode = 591;
        }
        else  // HBR HBR2
        {
            usCMUNCode = 184;
            usCMUFCode = 2350;
        }
    }
    else
    {
        switch(g_ucDpRx0PhyCtsCtrl & 0x30)
        {
            case 0x10: // Lane1 Test

                // [1:0] FREQDET_LANE_SEL = 2'b01 -> Select Lane1
                ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE1);

                break;

            case 0x20: // Lane2 Test

                // [1:0] FREQDET_LANE_SEL = 2'b10 -> Select Lane2
                ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE2);

                break;

            case 0x30: // Lane3 Test

                // [1:0] FREQDET_LANE_SEL = 2'b11 -> Select Lane3
                ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE3);

                break;

            default:
            case 0x00: // Lane0 Test

                // [1:0] FREQDET_LANE_SEL = 2'b00 -> Select Lane0
                ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

                break;
        }

        // [5] ln_ck_sel = 1'b0 -> DP Raw Data
        // [3:0] DP_XTAL_CYCLE = 4'b0011 -> XTAL Counter Cycles = 1000
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

        // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
        ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

        // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

        // Waiting for Measure Done -> 50us
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        switch(enumLinkRate)
        {
            case _DP_LINK_HBR2:

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    ulFreqDetect = (((DWORD)usCount * 2700) / 10006) * 100000;

                    usCMUNCode = ((ulFreqDetect / 14318) - 400) / 100;
                    usCMUFCode = (((ulFreqDetect / 14318) - 400) - (usCMUNCode * 100)) * 4096 / 100;
                }
                else
                {
                    usCMUNCode = 184;
                    usCMUFCode = 2350;
                }

                break;

            case _DP_LINK_HBR:

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    ulFreqDetect = (((DWORD)usCount * 2700) / 5003) * 100000;

                    usCMUNCode = ((ulFreqDetect / 14318) - 400) / 100;
                    usCMUFCode = (((ulFreqDetect / 14318) - 400) - (usCMUNCode * 100)) * 4096 / 100;
                }
                else
                {
                    usCMUNCode = 184;
                    usCMUFCode = 2350;
                }

                break;

            case _DP_LINK_RBR:
            default:

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    ulFreqDetect = (((DWORD)usCount * 1620) / 3002) * 100000;

                    usCMUNCode = ((ulFreqDetect / 14318) - 400) / 100;

                    usCMUFCode = (((ulFreqDetect / 14318) - 400) - (usCMUNCode * 100)) * 4096 / 100;
                }
                else
                {
                    usCMUNCode = 109;
                    usCMUFCode = 591;
                }

                break;
        }
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    // [5] N_CODE[8]
    ScalerSetBit(PB_F1_SDM_00, ~_BIT5, ((usCMUNCode >> 3) & _BIT5));

    // [7:0] N_CODE[7:0]
    ScalerSetByte(PB_F2_SDM_01, (BYTE)usCMUNCode);

    // [4:1] F_CODE[11:8]
    ScalerSetBit(PB_F1_SDM_00, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1), ((usCMUFCode >> 7) & (_BIT4 | _BIT3 | _BIT2 | _BIT1)));

    // [7:0] F_CODE[7:0]
    ScalerSetByte(PB_F3_SDM_02, (BYTE)usCMUFCode);
}

//--------------------------------------------------
// Description  : Rebuilding DP PHY
// Input Value  : DPCD Bit Rate and Lane Count
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane)
{
    BYTE ucBestVCOBand = 0;
    WORD usVCOBandDiff = 0xFFFF;
    BYTE ucTemp = 0;

    g_ucDpRx0PhyCtsCtrl = 0x00;


    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////

    // [7] cmu_en = 1'b0 --> Disable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, 0x00);

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_A1_CMU_01, 0x00);

    switch(ucDpcdLane & 0x1F)
    {
        case _DP_ONE_LANE:

            ScalerSetBit(PB_A1_CMU_01, ~_BIT4, _BIT4);

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetBit(PB_A1_CMU_01, ~_BIT0, _BIT0);

            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT3);

            break;

        case _DP_TWO_LANE:

            ScalerSetBit(PB_A1_CMU_01, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetBit(PB_A1_CMU_01, ~(_BIT1 | _BIT0), _BIT0);
            ScalerSetBit(PB_A1_CMU_01, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT4);

            break;

        case _DP_FOUR_LANE:
        default:

            ScalerSetBit(PB_A1_CMU_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
            ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
            ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

            break;
    }


    /////////////////
    // CMU Setting //
    /////////////////

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR2:

            // [7:5] rate_sel = 3'b000 --> 5.4GHz
            ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // [7:5] SEL_DIV = 3'b000 --> 5.4GHz
            // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
            // [1:0] CMU_SELPREDIV = 2'b00 --> /1
            ScalerSetByte(PB_A3_CMU_03, 0x0C);

            // [7:4] CMU_SEL_PUMP_I = 4'b1100 --> Icp = 35uA
            // [3:1] CMU_SEL_RI = 3'b000 --> Rs = 6KOhm
            // [0] CMU_SEL_CP = 1'b0 --> Cp = 1pF
            ScalerSetByte(PB_A4_CMU_04, 0xC0);

            // [5] CMU_BYPASS_PI = 1'b1 --> Integer N PLL
            ScalerSetBit(PB_A5_CMU_05, ~_BIT5, _BIT5);

            // [7] BYPASS_PI = 1'b1 --> Use Integer N Code
            ScalerSetBit(PB_F1_SDM_00, ~_BIT7, _BIT7);

            // Digital CDR Ref Clock = Analog CDR / 20
            ScalerSetBit(PB_AE_CDR_05, ~_BIT0, 0x00);
            ScalerSetBit(PB_AF_CDR_06, ~_BIT1, _BIT1);

            // [7:0] N_CODE = 8'b0001 0000 --> 16 + 4 = 20
            ScalerSetByte(PB_F2_SDM_01, 0x10);

            break;

        case _DP_LINK_HBR:

            // [7:5] rate_sel = 3'b001 --> 2.7GHz
            ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            // [7:5] SEL_DIV = 3'b001 --> 2.7GHz
            // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
            // [1:0] CMU_SELPREDIV = 2'b00 --> /1
            ScalerSetByte(PB_A3_CMU_03, 0x2C);

            // [7:4] CMU_SEL_PUMP_I = 4'b0101 --> Icp = 15uA
            // [3:1] CMU_SEL_RI = 3'b011 --> Rs = 12KOhm
            // [0] CMU_SEL_CP = 1'b0 --> Cp = 1pF
            ScalerSetByte(PB_A4_CMU_04, 0x56);

            // [5] CMU_BYPASS_PI = 1'b0 --> Fractional N PLL
            ScalerSetBit(PB_A5_CMU_05, ~_BIT5, 0x00);

            // [7] BYPASS_PI = 1'b0 --> Use Fractional N_F_CODE
            ScalerSetBit(PB_F1_SDM_00, ~_BIT7, 0x00);

            ScalerDpRx0CMUNFCodeSetting(_DP_NF_REF_XTAL, _DP_LINK_HBR);

            break;

        case _DP_LINK_RBR:
        default:

            // [7:5] rate_sel = 3'b001 --> 1.62GHz
            ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            // [7:5] SEL_DIV = 3'b001 --> 1.62GHz
            // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
            // [1:0] CMU_SELPREDIV = 2'b00 --> /1
            ScalerSetByte(PB_A3_CMU_03, 0x2C);

            // [7:4] CMU_SEL_PUMP_I = 4'b0101 --> Icp = 15uA
            // [3:1] CMU_SEL_RI = 3'b011 --> Rs = 12KOhm
            // [0] CMU_SEL_CP = 1'b0 --> Cp = 1pF
            ScalerSetByte(PB_A4_CMU_04, 0x56);

            // [5] CMU_BYPASS_PI = 1'b0 --> Fractional N PLL
            ScalerSetBit(PB_A5_CMU_05, ~_BIT5, 0x00);

            // [7] BYPASS_PI = 1'b0 --> Use Fractional N_F_CODE
            ScalerSetBit(PB_F1_SDM_00, ~_BIT7, 0x00);

            ScalerDpRx0CMUNFCodeSetting(_DP_NF_REF_XTAL, _DP_LINK_RBR);

            break;
    }


    /////////////////////
    // A/D CDR Setting //
    /////////////////////

    // [3:0] KD = 4'b0000 --> KD = 0
    ScalerSetBit(PB_CC_ERROR_COUNT_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR2:

            // [5:4] reg_cdr_kvco = 2'b01 --> Analog CDR KVCO = 550M/v
            ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~(_BIT5 | _BIT4), _BIT4);

            // [4:2] reg_sel_cdr_res = 3'b011 --> Analog CDR Rs = 4K
            ScalerSetBit(PB_FD_LANE0_A_CDR_07, ~(_BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

            // [3:0] reg_cdr_cp_in = 4'b0011 --> Analog CDR Icp = 10.5uA
            ScalerSetBit(PB_FE_LANE0_A_CDR_08, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

            // KI = 3'b000 --> KI = 0
            ScalerSetByte(PB_D4_KI_0, 0x00);
            ScalerSetByte(PB_D5_KI_1, 0x00);

            // KP = 0x07 --> KP = 1.75
            ScalerSetByte(PB_D6_KP_0, 0x07);
            ScalerSetByte(PB_D7_KP_1, 0x07);
            ScalerSetByte(PB_D8_KP_2, 0x07);
            ScalerSetByte(PB_D9_KP_3, 0x07);

            break;

        case _DP_LINK_HBR:

            // KI = 3'b010 --> KI = 1/8
            ScalerSetByte(PB_D4_KI_0, 0x48);
            ScalerSetByte(PB_D5_KI_1, 0x48);

            // KP = 0x1F --> KP = 7.75
            ScalerSetByte(PB_D6_KP_0, 0x1F);
            ScalerSetByte(PB_D7_KP_1, 0x1F);
            ScalerSetByte(PB_D8_KP_2, 0x1F);
            ScalerSetByte(PB_D9_KP_3, 0x1F);

            break;

        case _DP_LINK_RBR:
        default:

            // KI = 3'b010 --> KI = 1/8
            ScalerSetByte(PB_D4_KI_0, 0x48);
            ScalerSetByte(PB_D5_KI_1, 0x48);

            // KP = 0x37 --> KP = 13.75
            ScalerSetByte(PB_D6_KP_0, 0x37);
            ScalerSetByte(PB_D7_KP_1, 0x37);
            ScalerSetByte(PB_D8_KP_2, 0x37);
            ScalerSetByte(PB_D9_KP_3, 0x37);

            break;
    }


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // Enable Comma Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, 0x00);

    if((ucDpcdLane & _BIT7) == _BIT7)
    {
        // Enable Enhancement Control Mode --> MAC
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);
    }
    else
    {
        // Disable Enhancement Control Mode --> MAC
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, 0x00);
    }

    if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x02) & _BIT5) == _BIT5)
    {
        // Disable Scrambling
        ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);
    }
    else
    {
        // Enable Scrambling
        ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, 0x00);
    }

    // [0] en_clkout_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, 0x00);

    // [0] en_eqen_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

    // [0] en_data_manual = 0 --> Disable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~_BIT0, 0x00);

    // Disable Hybrid Mode
    ScalerSetBit(PB_AF_CDR_06, ~_BIT0, 0x00);

    // [3:0] RST_N = 4'b0000 --> Digital Circuit Reset
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [3:0] RST_N = 4'b1111 --> Digital Circuit Normal
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));


    /////////////////
    // DFE Setting //
    /////////////////

    // Set DFE Initial
    ScalerDpRx0SetDFEInitial(ucDpLinkRate);

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR2:

            // [7:5] LE_ISEL = 3'b011
            // [4:2] LE_RLSEL = 3'b000
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT5));

            break;

        case _DP_LINK_HBR:

            // [7:5] LE_ISEL = 3'b010
            // [4:2] LE_RLSEL = 3'b001
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT2));

            break;

        case _DP_LINK_RBR:
        default:

            // [7:5] LE_ISEL = 3'b000
            // [4:2] LE_RLSEL = 3'b011
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

            break;
    }


    //////////////
    // K Offset //
    //////////////

#if(_PCB_TYPE_FOR_DP_HBR2 == _DP_HBR2_AIO_PCB)
    if(ucDpLinkRate == _DP_LINK_HBR2)
    {
        // Enable Sumamp High Gain Mode
        ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);
    }
    else
#endif
    {
        // Disable Sumamp High Gain Mode
        ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);
    }

    // [2] Enable Foreground Calibration Auto Mode
    ScalerSetBit(PB_AD_CDR_04, ~_BIT2, _BIT2);

    // [5] Toggle Foreground Calibration
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, _BIT5);
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, _BIT5);

    // Waiting for K Offset
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }


    /////////////////////
    // Adaptation Loop //
    /////////////////////

    // [7] cmu_en = 1'b1 --> Enable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, _BIT7);

    // Enable Tap1/2
    ScalerSetBit(PB_B2_EQ_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

    if(ucDpLinkRate == _DP_LINK_HBR2)
    {
        // [4] reg_en_data_manual_l0 = 1'b0
        // [3] reg_bypass_data_rdy_l0 = 1'b0
        ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~(_BIT4 | _BIT3), 0x00);

        // [0] en_clkout_manual = 0 --> Disable Clkout
        ScalerSetBit(PB_F5_WD_01, ~_BIT4, 0x00);

        // [5] reg_adp_eq_off = 1'b0 --> Enable Analog CDR DFE Adaptation
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT5, 0x00);

        // [4] reg_auto_mode = 1'b1 --> FLD Select Auto Mode
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT4, _BIT4);

        // [0] reg_acdr_l0_en = 1'b1 --> Enable Lane0 ACDR
        ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~_BIT0, _BIT0);

        // [6] reg_xtal_en = 1'b1 --> Using Xtal
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT6, _BIT6);

        // Analog CDR Auto FLD Counter
        ScalerSetByte(PB_FA_LANE0_A_CDR_04, 0xF9);
        ScalerSetByte(PB_FB_LANE0_A_CDR_05, 0x0C);
        ScalerSetByte(PB_FC_LANE0_A_CDR_06, 0x85);

        // [0] en_clkout_manual = 1'b1 --> Enable Clkout
        ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

        // [7] reg_en_ana_cdr = 1'b1 --> Enable Analog CDR
        // [6] reg_en_vco_lpf = 1'b0 --> Disable Analog CDR Multi Band VCO's LPF
        // [3] reg_cp_adj_en = 1'b1 --> Enable Adjust Icp When Tracking
        // [2] reg_enhance_bias_boost = 1'b0 --> Disable Enhance LEQ Boost Bias
        // [1] reg_enhance_bias_gain = 1'b0 --> Disable Enhance LEQ Gain Bias
        // [0] reg_rstb_fsm --> Toggle for FLD reset
        ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3));
        ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~_BIT0, _BIT0);

        // Waiting for FLD Lock Band
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // [3] reg_cp_en_manual = 1'b0 -->  Disable cp_en_manual
        // [2] reg_adp_en_manual = 1'b0 --> Disable adp_en_manual
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~(_BIT3 | _BIT2), 0x00);

        // [4] reg_auto_mode = 1'b0 --> FLD Manual Mode
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT4, 0x00);

        // [0] en_clkout_manual = 1'b1 --> Enable Clkout
        ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

        // [2] reg_adp_en_manual = 1'b1 --> Enable adp_en_manual
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT2, _BIT2);

        ucBestVCOBand = ScalerGetByte(PB_BF_LANE0_A_CDR_02);

        g_usDpRx0ClockCount = 0x2710; // ideal 5.4G

        for(ucTemp = 0; ucTemp <= 5; ucTemp++)
        {
            // Manually Reload FLD Band
            ScalerSetByte(PB_BE_LANE0_A_CDR_01, (ScalerGetByte(PB_BF_LANE0_A_CDR_02) - 2 + ucTemp));

            // Waiting for VCO Stable
            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            // [5] ln_ck_sel = 1'b1 -> CDR Clock
            // [3:0] DP_XTAL_CYCLE = 4'b0011 -> XTAL Counter Cycles = 1000
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT1 | _BIT0));

            // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 50us
            for(pData[0] = 0; pData[0] <= 10; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
            {
                g_usDpRx0ClockCount1 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
            }
            else
            {
                ucBestVCOBand = ScalerGetByte(PB_BF_LANE0_A_CDR_02);
                continue;
            }

            // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

            if((abs(g_usDpRx0ClockCount1 - g_usDpRx0ClockCount) < usVCOBandDiff) && (g_usDpRx0ClockCount1 >= g_usDpRx0ClockCount))
            {
                usVCOBandDiff = abs(g_usDpRx0ClockCount1 - g_usDpRx0ClockCount);
                ucBestVCOBand = (ScalerGetByte(PB_BF_LANE0_A_CDR_02) - 2 + ucTemp);
            }
        }

        // Manually Reload FLD Band
        ScalerSetByte(PB_BE_LANE0_A_CDR_01, ucBestVCOBand);

        // Waiting for VCO Stable
        for(pData[0] = 0; pData[0] <= 2; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // [3] reg_cp_en_manual = 1'b1 -->  Enaable cp_en_manual
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT3, _BIT3);

        // Enable Tap0 Adaptation
        ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x41);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Start to Record Tap0 Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Stop To Record Tap0 Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

        // Disable Vth/Tap0 Adaptation
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);

        // Read Back Lane0
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);

        // Read Back Tap0 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

        g_pucDpRx0Tap0MaxTemp[0] = ScalerGetByte(P1D_F3_COEF_4);

        // Reload Max Value of Tap0 (Lane0)
        ScalerSetByte(P1D_A4_L0_INIT_2, g_pucDpRx0Tap0MaxTemp[0]);

        // Reload Tap0
        ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT0, _BIT0);
        ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT0, 0x00);

        // Enable LE Adaptation
        ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x80);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Start to Record LE Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Stop To Record LE Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

        // Disable Adaptation
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);

        // Read Back Lane0
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);

        // Read Back LE Min
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT1));

        g_pucDpRx0LEMinTemp[0] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back LE Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT3);

        g_pucDpRx0LEMaxTemp[0] = ScalerGetByte(P1D_F3_COEF_4);

        pData[0] = 0;

        if(g_pucDpRx0LEMaxTemp[pData[0]] > g_pucDpRx0LEMinTemp[pData[0]])
        {
            if(g_pucDpRx0LEMinTemp[pData[0]] < 10)
            {
                g_pucDpRx0LEMinTemp[pData[0]] = g_pucDpRx0LEMinTemp[pData[0]] + 2;
            }
            else if(g_pucDpRx0LEMinTemp[pData[0]] < 12)
            {
                g_pucDpRx0LEMinTemp[pData[0]]++;
            }
        }

        // Reload LE to Min
        ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
        ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[0] << 2) & _BIT6));

        // Reload LE
        ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT7, _BIT7);
        ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT7, 0x00);

        // [0] en_clkout_manual = 0 --> Disable Clkout
        ScalerSetBit(PB_F5_WD_01, ~_BIT4, 0x00);

        // Enable Hybrid Mode
        ScalerSetBit(PB_AF_CDR_06, ~_BIT0, _BIT0);

        // Enable Vth/Tap0 Adaptation
        ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x41);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x41);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x41);

        // Reset Digital CDR
        ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);
        ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

        // Waiting for CMU PLL Stable
        for(pData[0] = 0; pData[0] <= 2; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // [0] en_clkout_manual = 1 --> Enable Clkout
        ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

        // [0] en_eqen_manual = 1 --> Enable Adapation
        ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Start to Record Tap0 Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Stop To Record Tap0 Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

        // Disable All Adapation Loop
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

        // Read Back Lane1
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);

        // Read Back Tap0 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

        g_pucDpRx0Tap0MaxTemp[1] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back Lane2
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);

        // Read Back Tap0 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

        g_pucDpRx0Tap0MaxTemp[2] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back Lane3
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

        // Read Back Tap0 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

        g_pucDpRx0Tap0MaxTemp[3] = ScalerGetByte(P1D_F3_COEF_4);

        // Reload Max Value of Tap0 (Lane1)
        ScalerSetByte(P1D_B4_L1_INIT_2, g_pucDpRx0Tap0MaxTemp[1]);

        // Reload Max Value of Tap0 (Lane2)
        ScalerSetByte(P1D_C4_L2_INIT_2, g_pucDpRx0Tap0MaxTemp[2]);

        // Reload Max Value of Tap0 (Lane3)
        ScalerSetByte(P1D_D4_L3_INIT_2, g_pucDpRx0Tap0MaxTemp[3]);

        // Reload Tap0 Max
        ScalerSetBit(P1D_BA_L1_INIT_8, ~_BIT0, _BIT0);
        ScalerSetBit(P1D_CA_L2_INIT_8, ~_BIT0, _BIT0);
        ScalerSetBit(P1D_DA_L3_INIT_8, ~_BIT0, _BIT0);
        ScalerSetBit(P1D_BA_L1_INIT_8, ~_BIT0, 0x00);
        ScalerSetBit(P1D_CA_L2_INIT_8, ~_BIT0, 0x00);
        ScalerSetBit(P1D_DA_L3_INIT_8, ~_BIT0, 0x00);

        // Enable LE Adaptation
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x80);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x80);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x80);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Start to Record Tap0 Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Stop To Record Tap0 Max/Min
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

        // Disable All Adapation Loop
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

        // Read Back Lane1
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);

        // Read Back LE Min
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT1));

        g_pucDpRx0LEMinTemp[1] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back LE Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT3);

        g_pucDpRx0LEMaxTemp[1] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back Lane2
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);

        // Read Back LE Min
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT1));

        g_pucDpRx0LEMinTemp[2] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back LE Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT3);

        g_pucDpRx0LEMaxTemp[2] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back Lane3
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

        // Read Back LE Min
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT1));

        g_pucDpRx0LEMinTemp[3] = ScalerGetByte(P1D_F3_COEF_4);

        // Read Back LE Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT3);

        g_pucDpRx0LEMaxTemp[3] = ScalerGetByte(P1D_F3_COEF_4);

        for(pData[0] = 1; pData[0] <= 3; pData[0]++)
        {
            if(abs(g_pucDpRx0LEMaxTemp[pData[0]] - g_pucDpRx0LEMinTemp[pData[0]]) == 1)
            {
                if(g_pucDpRx0LEMinTemp[pData[0]] < 10)
                {
                    g_pucDpRx0LEMinTemp[pData[0]] = g_pucDpRx0LEMinTemp[pData[0]] + 2;
                }
                else if(g_pucDpRx0LEMinTemp[pData[0]] < 13)
                {
                    g_pucDpRx0LEMinTemp[pData[0]]++;
                }
            }
            else if(abs(g_pucDpRx0LEMaxTemp[pData[0]] - g_pucDpRx0LEMinTemp[pData[0]]) > 1)
            {
                if(g_pucDpRx0LEMinTemp[pData[0]] < 12)
                {
                    g_pucDpRx0LEMinTemp[pData[0]] = g_pucDpRx0LEMinTemp[pData[0]] + 2;
                }
                else if(g_pucDpRx0LEMinTemp[pData[0]] < 13)
                {
                    g_pucDpRx0LEMinTemp[pData[0]]++;
                }
            }
        }

        // Reload LE to Min
        ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[1] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
        ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[1] << 2) & _BIT6));

        // Reload LE to Min
        ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[2] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
        ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[2] << 2) & _BIT6));

        // Reload LE to Min
        ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[3] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
        ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[3] << 2) & _BIT6));

        // Reload LE
        ScalerSetBit(P1D_BA_L1_INIT_8, ~_BIT7, _BIT7);
        ScalerSetBit(P1D_CA_L2_INIT_8, ~_BIT7, _BIT7);
        ScalerSetBit(P1D_DA_L3_INIT_8, ~_BIT7, _BIT7);
        ScalerSetBit(P1D_BA_L1_INIT_8, ~_BIT7, 0x00);
        ScalerSetBit(P1D_CA_L2_INIT_8, ~_BIT7, 0x00);
        ScalerSetBit(P1D_DA_L3_INIT_8, ~_BIT7, 0x00);

        // [5] servo_notrans = 1'b0 --> Servo is Effective Each Bit
        // [4] tap0_notrans = 1'b0 --> Tap0 is Effective Each Bit
        ScalerSetBit(P1D_F8_GRAY_DEC_2, ~(_BIT5 | _BIT4), 0x00);

        // Enable Tap0/1 Adapt
        ScalerSetBit(P1D_A1_L0_DFE_EN_2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        ScalerSetBit(P1D_B1_L1_DFE_EN_2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        ScalerSetBit(P1D_C1_L2_DFE_EN_2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));
        ScalerSetBit(P1D_D1_L3_DFE_EN_2, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Start to Record DFE Coef.
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 20; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Stop to Record DFE Coef.
        ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

        // Disable Tap0/1 Adapt
        ScalerSetBit(P1D_A1_L0_DFE_EN_2, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_B1_L1_DFE_EN_2, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_C1_L2_DFE_EN_2, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_D1_L3_DFE_EN_2, ~(_BIT1 | _BIT0), 0x00);


        ///////////
        // Lane0 //
        ///////////

        // Read Back Lane0
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);

        // Read Back Tap1 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

        g_pucDpRx0Tap1MaxTemp[0] = ScalerGetByte(P1D_F3_COEF_4);


        ///////////
        // Lane1 //
        ///////////

        // Read Back Lane1
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);

        // Read Back Tap1 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

        g_pucDpRx0Tap1MaxTemp[1] = ScalerGetByte(P1D_F3_COEF_4);


        ///////////
        // Lane2 //
        ///////////

        // Read Back Lane2
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);

        // Read Back Tap1 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

        g_pucDpRx0Tap1MaxTemp[2] = ScalerGetByte(P1D_F3_COEF_4);


        ///////////
        // Lane3 //
        ///////////

        // Read Back Lane3
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

        // Read Back Tap1 Max
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT2);

        g_pucDpRx0Tap1MaxTemp[3] = ScalerGetByte(P1D_F3_COEF_4);

        for(pData[0] = 0; pData[0] <= 3; pData[0]++)
        {
            if(g_pucDpRx0Tap1MaxTemp[pData[0]] > 10)
            {
                g_pucDpRx0Tap1MaxTemp[pData[0]] = 0x06;

                if(g_pucDpRx0LEMinTemp[pData[0]] < 15)
                {
                    g_pucDpRx0LEMinTemp[pData[0]]++;
                }
            }
        }

        // Reload LE
        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x03) == 0x06)
        {
            ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[0] << 2) & _BIT6));
        }
        else
        {
            ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[0] << 2) & _BIT6));
        }

        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x04) == 0x06)
        {
            ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[1] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[1] << 2) & _BIT6));
        }
        else
        {
            ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[1] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[1] << 2) & _BIT6));
        }

        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x05) == 0x06)
        {
            ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[2] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[2] << 2) & _BIT6));
        }
        else
        {
            ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[2] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[2] << 2) & _BIT6));
        }

        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x06) == 0x06)
        {
            ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[3] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[3] << 2) & _BIT6));
        }
        else
        {
            ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[3] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[3] << 2) & _BIT6));
        }

        // Reload Max Value of Tap0
        ScalerSetByte(P1D_A4_L0_INIT_2, g_pucDpRx0Tap0MaxTemp[0]);
        ScalerSetByte(P1D_B4_L1_INIT_2, g_pucDpRx0Tap0MaxTemp[1]);
        ScalerSetByte(P1D_C4_L2_INIT_2, g_pucDpRx0Tap0MaxTemp[2]);
        ScalerSetByte(P1D_D4_L3_INIT_2, g_pucDpRx0Tap0MaxTemp[3]);

        // Reload Tap1
        ScalerSetByte(P1D_A5_L0_INIT_3, g_pucDpRx0Tap1MaxTemp[0]);
        ScalerSetByte(P1D_B5_L1_INIT_3, g_pucDpRx0Tap1MaxTemp[1]);
        ScalerSetByte(P1D_C5_L2_INIT_3, g_pucDpRx0Tap1MaxTemp[2]);
        ScalerSetByte(P1D_D5_L3_INIT_3, g_pucDpRx0Tap1MaxTemp[3]);

        // Load Tap0/Tap1
        ScalerSetBit(P1D_AA_L0_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
        ScalerSetBit(P1D_BA_L1_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
        ScalerSetBit(P1D_CA_L2_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
        ScalerSetBit(P1D_DA_L3_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), (_BIT7 | _BIT1 | _BIT0));
        ScalerSetBit(P1D_AA_L0_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_BA_L1_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_CA_L2_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_DA_L3_INIT_8, ~(_BIT7 | _BIT1 | _BIT0), 0x00);

        // [4] transition_only = 1 --> Each Bit is Effective
        ScalerSetBit(P1D_E0_MODE_TIMER, ~_BIT4, 0x00);

        // Enable Tap 3/4 Adapt
        ScalerSetBit(P1D_A1_L0_DFE_EN_2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        ScalerSetBit(P1D_B1_L1_DFE_EN_2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        ScalerSetBit(P1D_C1_L2_DFE_EN_2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
        ScalerSetBit(P1D_D1_L3_DFE_EN_2, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

        // Waiting for DFE Adapt
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // [0] reg_en_eqen_manual = 1'b0 --> Disable Analog DFE Adapt
        ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);
    }
    else
    {
        // [7] reg_en_ana_cdr = 1'b0 --> Disable Analog CDR
        ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~_BIT7, 0x00);

        // [0] reg_acdr_l0_en = 1'b0 --> Disable Lane0 ACDR
        ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~_BIT0, 0x00);

        // Enable Tap0/Vth/LE/Tap1/Tap2
        ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0xC7);
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0xC7);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0xC7);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0xC7);

        // Reset Digital CDR
        ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);
        ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

        // Waiting for CMU PLL Stable
        for(pData[0] = 0; pData[0] <= 2; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // [0] en_clkout_manual = 1 --> Enable Clkout
        ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

        // [0] en_eqen_manual = 1 --> Enable Adapation
        ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

        // Waiting for DFE Adaptation
        for(pData[0] = 0; pData[0] <= 40; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // Enable Vth/Tap0 Adaptation
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x41);
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x41);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x41);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x41);

        // Set Vth Min = 0
        ScalerSetBit(P1D_F9_LIMIT_10, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    }

    // [0] en_data_manual = 1 --> Enable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~_BIT0, _BIT0);

    if(ScalerGetBit(PB_FF_LANE0_A_CDR_09, _BIT0) == _BIT0)
    {
        // [5] reg_adp_eq_off = 1'b1 --> Disable Adaptation for Analog CDR
        ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT5, _BIT5);

        // [4] reg_en_data_manual_l0 = 1'b1
        // [3] reg_bypass_data_rdy_l0 = 1'b1
        ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));
    }

    // DP Mac Clock Select to Link Clock
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, 0x00);
}

//--------------------------------------------------
// Description  : DP PHY DFE Initial Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetDFEInitial(EnumDpLinkRate enumDpLinkRate)
{
    enumDpLinkRate = enumDpLinkRate;

    // [7] Positive Symbol-Rate Clock
    // [6] Enable Timer Control DFE Loop
    // [5:4] Reduce Gain to 1/4
    // [3] Disable Running Length Detection
    // [2] bypass Blank out Case-3 Symbol
    ScalerSetBit(P1D_A0_L0_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5));
    ScalerSetBit(P1D_B0_L1_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5));
    ScalerSetBit(P1D_C0_L2_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5));
    ScalerSetBit(P1D_D0_L3_DFE_EN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5));

    // [7:6] adapt_mode[1:0] = 2'b10 --> Amplitude-based Adaptation with Independent LE Loop(Loop Mode 2)
    // [5] edge_det_mode = 1 --> Edge Lag Data
    // [4] transition_only = 1 --> Only Transition Bit is Effective
    // [3] le_auto_reload = 0 --> Disable Auto-reload LE Coefficient
    // [2:0] tap1_delay[2:0] = 3'b010 --> Tap1+LE Delay 2us after Tap0
    ScalerSetByte(P1D_E0_MODE_TIMER, 0xB2);

    // Set DFE Delay Time
    ScalerSetByte(P1D_E1_TIMER, 0x01);

    // Tap0,Tap1 Loop Gain 1/512
    ScalerSetBit(P1D_E2_GAIN_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT2));

    // Tap2,Tap3 Loop Gain 1/512
    ScalerSetBit(P1D_E3_GAIN_2, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT2));

    // Tap4,Servo Loop Gain 1/512
    ScalerSetBit(P1D_E4_GAIN_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT3));

    // LE Gain1 Loop Gain 1/256, LE Gain2 Loop Gain 0, LE Pre-Courser Gain 0
    ScalerSetBit(P1D_E5_GAIN_4, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT6 | _BIT4 | _BIT3));
    ScalerSetBit(P1D_FA_GAIN_PREC, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));

    // Tap5,Tap6 Loop Gain 1/512
    ScalerSetBit(P1D_F7_GAIN_5, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT2));

    // Tap0 Max is 21
    ScalerSetByte(P1D_E6_LIMIT_1, 0x35);

    // Tap1 Min is 31
    ScalerSetBit(P1D_E7_LIMIT_2, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Tap2 Max is 6, Min is -6
    ScalerSetBit(P1D_E8_LIMIT_3, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT5 | _BIT4));
    ScalerSetBit(P1D_E8_LIMIT_3, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
    ScalerSetBit(P1D_E9_LIMIT_4, ~(_BIT7 | _BIT6), _BIT7);

    // Tap3 Max is 0, Min is -3
    ScalerSetBit(P1D_E9_LIMIT_4, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_EA_LIMIT_5, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT4 | _BIT3));

    // Tap4 Max is 0, Min is -3
    ScalerSetBit(P1D_EA_LIMIT_5, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_EB_LIMIT_6, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetBit(P1D_EB_LIMIT_6, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Tap0 Threshold
    ScalerSetBit(P1D_EF_RESET_1, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT5));

    if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00)
    {
        // Set Vth Max = 6, Min = 0
        ScalerSetByte(P1D_F9_LIMIT_10, 0x60);
    }
    else if(enumDpLinkRate == _DP_LINK_HBR2)
    {
        // Set Vth Max = 6, Min = 4
        ScalerSetByte(P1D_F9_LIMIT_10, 0x64);
    }
    else
    {
        // Set Vth Max = 6, Min = 0
        ScalerSetByte(P1D_F9_LIMIT_10, 0x62);
    }

    // Set Vth/Servo-loop/Tap Divider
    ScalerSetByte(P1D_EC_LOOP_DIV_1, 0xA3);

    // Tap Divider = 10 for TP2
    ScalerSetByte(P1D_ED_LOOP_DIV_2, 0xCA);

    // [5] servo_notrans = 1'b1 --> Servo is Effective when Non-Tran
    // [4] tap0_notrans = 1'b1 --> Tap0 is Effective when Non-Tran
    ScalerSetBit(P1D_F8_GRAY_DEC_2, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));


    /////////////////////////
    // DFE Code Initialize //
    /////////////////////////

    if(enumDpLinkRate == _DP_LINK_HBR2)
    {
        // LE Max = 15, Initial = 12, Servo Initial = 16
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_A3_L0_INIT_1, 0x10);
        ScalerSetByte(P1D_B3_L1_INIT_1, 0x10);
        ScalerSetByte(P1D_C3_L2_INIT_1, 0x10);
        ScalerSetByte(P1D_D3_L3_INIT_1, 0x10);
    }
    else
    {
        // LE Max = 31, Initial = 12, Servo Initial = 16
        ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0xFC);
        ScalerSetByte(P1D_A3_L0_INIT_1, 0x90);
        ScalerSetByte(P1D_B3_L1_INIT_1, 0x90);
        ScalerSetByte(P1D_C3_L2_INIT_1, 0x90);
        ScalerSetByte(P1D_D3_L3_INIT_1, 0x90);
    }

    // Tap0 Initial Value = 12
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x0C);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x0C);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x0C);
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x0C);

    // Tap1 Initial Value = 0
    ScalerSetByte(P1D_A5_L0_INIT_3, 0x00);
    ScalerSetByte(P1D_B5_L1_INIT_3, 0x00);
    ScalerSetByte(P1D_C5_L2_INIT_3, 0x00);
    ScalerSetByte(P1D_D5_L3_INIT_3, 0x00);

    // Tap2 Initial Value = 0
    ScalerSetByte(P1D_A6_L0_INIT_4, 0x00);
    ScalerSetByte(P1D_B6_L1_INIT_4, 0x00);
    ScalerSetByte(P1D_C6_L2_INIT_4, 0x00);
    ScalerSetByte(P1D_D6_L3_INIT_4, 0x00);

    // Vth Initial Value = 4
    ScalerSetByte(P1D_A9_L0_INIT_7, 0x04);
    ScalerSetByte(P1D_B9_L1_INIT_7, 0x04);
    ScalerSetByte(P1D_C9_L2_INIT_7, 0x04);
    ScalerSetByte(P1D_D9_L3_INIT_7, 0x04);

    // Load Intial DFE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0xFF);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0xFF);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0xFF);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0xFF);
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));
    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT5 | _BIT4), (_BIT5 | _BIT4));

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT5 | _BIT4), 0x00);

    // DFE Loop Normal
    ScalerSetBit(P1D_EF_RESET_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_EF_RESET_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Disable All Adaptation Loop
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);
}

//--------------------------------------------------
// Description  : Check Valid Lane CDR
// Input Value  : None
// Output Value : True --> CDR Lock
//--------------------------------------------------
bit ScalerDpRx0CDRCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane)
{
    if(ucDpLinkRate <= _DP_LINK_HBR)
    {
        return _TRUE;
    }

    switch(ucDpcdLane)
    {
        case _DP_ONE_LANE:

            if(ScalerDpRx0MeasureLaneCDRClk(ucDpLinkRate, _D0_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }

            break;

        case _DP_TWO_LANE:

            if(ScalerDpRx0MeasureLaneCDRClk(ucDpLinkRate, _D0_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }

            break;

        case _DP_FOUR_LANE:
        default:

            if(ScalerDpRx0MeasureLaneCDRClk(ucDpLinkRate, _D0_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }

            break;
    }

    DebugMessageRx0("7. wuzanne test : DP CDR Unlock", 0);

    return _FALSE;
}

//--------------------------------------------------
// Description : check DP CDR locked or unlocked
// Input Value  : DP Lane
// Output Value : True --> locked; False --> unlocked
//--------------------------------------------------
bit ScalerDpRx0MeasureLaneCDRClk(BYTE ucDpLinkRate, BYTE ucDpRx0LaneNumber)
{
    WORD usCDRClockCount = 0;
    ucDpLinkRate = ucDpLinkRate;

    if((abs(g_usDpRx0ClockCount - 0x2710)) > (0x2710 >> 4))
    {
        return _TRUE;
    }

    // Select Measure CDR Clock & XTAL 27M Count 1000 Times
    ScalerSetByte(PB_50_DP_SIG_DET_0, 0x23);

    // Select CDR Lane
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), ucDpRx0LaneNumber);

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // Toggle Start Measure
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Waiting for Measure Done -> 50us
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == 0x00)
    {
        return _FALSE;
    }

    usCDRClockCount = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

    if(abs(g_usDpRx0ClockCount - usCDRClockCount) > (g_usDpRx0ClockCount >> 7))
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check Valid Video Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0ValidSignalDetection(void)
{
    BYTE ucDpLinkRate = 0;
    BYTE ucDpcdLane = 0;
    BYTE ucLane0Vth = 0;
    BYTE ucLane0LE = 0;
    BYTE ucLane1Vth = 0;
    BYTE ucLane1LE = 0;
    BYTE ucLane2Vth = 0;
    BYTE ucLane2LE = 0;
    BYTE ucLane3Vth = 0;
    BYTE ucLane3LE = 0;

    do
    {
        if(ucDpLinkRate == 0)
        {
            ucDpLinkRate = _DP_LINK_RBR;

            DebugMessageRx0("7. VBIOS : RBR", 0);
        }
        else if(ucDpLinkRate == _DP_LINK_RBR)
        {
            ucDpLinkRate = _DP_LINK_HBR;

            DebugMessageRx0("7. VBIOS : HBR", 0);
        }
        else if(ucDpLinkRate == _DP_LINK_HBR)
        {
            ucDpLinkRate = _DP_LINK_HBR2;

            DebugMessageRx0("7. VBIOS : HBR2", 0);
        }

        SET_DP_RX0_AUX_MANUAL_MODE();

#if(_DP_MST_SUPPORT == _ON)
        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00) && ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & 0x03) != 0x03))
#else
        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00))
#endif
        {
            ScalerDpRx0SignalDetectInitial(ucDpLinkRate);

            if(ScalerDpRx0SignalCheck(ucDpLinkRate, _DP_FOUR_LANE) == _TRUE)
            {
                ucDpcdLane = _DP_FOUR_LANE;
            }
            else if(ScalerDpRx0SignalCheck(ucDpLinkRate, _DP_TWO_LANE) == _TRUE)
            {
                ucDpcdLane = _DP_TWO_LANE;
            }
            else if(ScalerDpRx0SignalCheck(ucDpLinkRate, _DP_ONE_LANE) == _TRUE)
            {
                ucDpcdLane = _DP_ONE_LANE;
            }
            else
            {
                ucDpcdLane = 0xFF;
            }

            ScalerDpRx0RebuildPhy(ucDpLinkRate, 0x84);
        }
        else
        {
            SET_DP_RX0_AUX_AUTO_MODE();

            return;
        }

        SET_DP_RX0_AUX_AUTO_MODE();

        // De-Skew Circuit Reset
        ScalerSetBit(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), 0x00);
        ScalerSetBit(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), _BIT6);

        // Mac Reset After Link Clock Stable
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

        // Read Lane0
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE0 << 6));

        // Read Vth
        ScalerSetByte(P1D_F0_COEF_1, 0x00);
        ucLane0Vth = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

        // Read LE
        ScalerSetByte(P1D_F0_COEF_1, 0x09);
        ucLane0LE = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

        // Read Lane1
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE1 << 6));

        // Read Vth
        ScalerSetByte(P1D_F0_COEF_1, 0x00);
        ucLane1Vth = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

        // Read LE
        ScalerSetByte(P1D_F0_COEF_1, 0x09);
        ucLane1LE = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

        // Read Lane2
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE2 << 6));

        // Read Vth
        ScalerSetByte(P1D_F0_COEF_1, 0x00);
        ucLane2Vth = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

        // Read LE
        ScalerSetByte(P1D_F0_COEF_1, 0x09);
        ucLane2LE = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

        // Read Lane3
        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE3 << 6));

        // Read Vth
        ScalerSetByte(P1D_F0_COEF_1, 0x00);
        ucLane3Vth = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

        // Read LE
        ScalerSetByte(P1D_F0_COEF_1, 0x09);
        ucLane3LE = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

        DebugMessageRx0("7. Lane0 Vth --> ", ucLane0Vth);
        DebugMessageRx0("7. Lane0 LE --> ", ucLane0LE);
        DebugMessageRx0("7. Lane1 Vth --> ", ucLane1Vth);
        DebugMessageRx0("7. Lane1 LE --> ", ucLane1LE);
        DebugMessageRx0("7. Lane2 Vth --> ", ucLane2Vth);
        DebugMessageRx0("7. Lane2 LE --> ", ucLane2LE);
        DebugMessageRx0("7. Lane3 Vth --> ", ucLane3Vth);
        DebugMessageRx0("7. Lane3 LE --> ", ucLane3LE);

        ScalerTimerDelayXms(5);

        // Clear 8b/10b Decode Error Flag
        ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

        ScalerTimerDelayXms(2);

        SET_DP_RX0_AUX_MANUAL_MODE();

#if(_DP_MST_SUPPORT == _ON)
        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00) && ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & 0x03) != 0x03))
#else
        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00))
#endif
        {
            if(((ucLane0Vth != 0) && (ucLane0LE <= 15)) && ((ucLane1Vth != 0) && (ucLane1LE <= 15)) &&
               ((ucLane2Vth != 0) && (ucLane2LE <= 15)) && ((ucLane3Vth != 0) && (ucLane3LE <= 15)) &&
               (ucDpcdLane == _DP_FOUR_LANE) && (ScalerDpRx0CDRCheck(ucDpLinkRate, _DP_FOUR_LANE) == _TRUE) &&
               (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x00))
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x00, ucDpLinkRate);
                ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x01, ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x60) | 0x84));
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x04, 0x01);

                SET_DP_RX0_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS_VBIOS);

                DebugMessageRx0("7. 4 Lane", 0);

                break;
            }
            else if(((ucLane0Vth != 0) && (ucLane0LE <= 15)) && ((ucLane1Vth != 0) && (ucLane1LE <= 15)) &&
                    (ucDpcdLane == _DP_TWO_LANE) && (ScalerDpRx0CDRCheck(ucDpLinkRate, _DP_TWO_LANE) == _TRUE) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT1 | _BIT0)) == 0x00))
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x00, ucDpLinkRate);
                ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x01, ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x60) | 0x82));
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x04, 0x01);

                SET_DP_RX0_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS_VBIOS);

                DebugMessageRx0("7. 2 Lane", 0);

                break;
            }
            else if((ucLane0Vth != 0) && (ucLane0LE <= 15) &&
                    (ucDpcdLane == _DP_ONE_LANE) && (ScalerDpRx0CDRCheck(ucDpLinkRate, _DP_ONE_LANE) == _TRUE) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, _BIT0) == 0x00))
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x00, ucDpLinkRate);
                ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x01, ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x60) | 0x81));
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x07);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x04, 0x01);

                SET_DP_RX0_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS_VBIOS);

                DebugMessageRx0("7. 1 lane", 0);

                break;
            }
        }
        else
        {
            // Set Aux HW Control Mode
            SET_DP_RX0_AUX_AUTO_MODE();

            return;
        }

        // Set Aux HW Control Mode
        SET_DP_RX0_AUX_AUTO_MODE();
    }
    while(ucDpLinkRate < ScalerDpRx0GetDpcdInfo(0x00, 0x00, 0x01));

#if(_DP_MST_SUPPORT == _ON)
    if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS)
    {
        ScalerDpRx0MstInfoBackup(_DP_MST_BACKUP_INFO_RESTORE);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        ScalerDpRx6MstInfoBackup(_DP_MST_BACKUP_INFO_RESTORE);
#endif
    }
#endif

    // Set Aux HW Control Mode
    SET_DP_RX0_AUX_AUTO_MODE();
}

//--------------------------------------------------
// Description : check DP 8b/10b Decode Error
// Input Value  : None
// Output Value : True --> ok, False --> 8b/10b Decode Error
//--------------------------------------------------
bit ScalerDpRx0DecodeCheck(void)
{
    pData[1] = 3;

    while(pData[1] > 0)
    {
        // Clear 8b/10b Decode Error Flag
        ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

        for(pData[0] = 0; pData[0] <= 20; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
        {
            case _DP_ONE_LANE:

                if(ScalerGetBit(PB_06_DECODE_10B8B_ERROR, _BIT0) == 0x00)
                {
                    return _TRUE;
                }

                break;

            case _DP_TWO_LANE:

                if(ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT1 | _BIT0)) == 0x00)
                {
                    return _TRUE;
                }

                break;

            case _DP_FOUR_LANE:

                if(ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) == 0x00)
                {
                    return _TRUE;
                }

                break;

            default:

                return _FALSE;

                break;
        }

        pData[1]--;
    }

    DebugMessageRx0("7. DP 8b/10b Decode Error", 0);

    return _FALSE;
}

//--------------------------------------------------
// Description  : Enable DP Fifo Under/OverFlow IRQ
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetNoVideoStreamIRQ(bit bEn)
{
    // VB-ID[3] Change Flag
    ScalerSetBit(PB6_36_DP_GLB_STATUS, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), _BIT6);

    // VB-ID[3] Change IRQ
    ScalerSetBit(PB6_3B_DP_IRQ_CTRL1, ~_BIT4, ((bEn == _ENABLE) ? _BIT4 : 0x00));
}

//--------------------------------------------------
// Description : check DFE Coef
// Input Value  : None
// Output Value : True --> valid, False --> invalid
//--------------------------------------------------
bit ScalerDpRx0DFECheck(void)
{
    if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
    {
        return _TRUE;
    }

    switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
    {
        case _DP_FOUR_LANE:

            // Read Lane2 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE2 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane2 DFE Fail", 0);

                return _FALSE;
            }

            // Read Lane3 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE3 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane3 DFE Fail", 0);

                return _FALSE;
            }

            // Read Lane1 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE1 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane1 DFE Fail", 0);

                return _FALSE;
            }

            // Read Lane0 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE0 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane0 DFE Fail", 0);

                return _FALSE;
            }

            break;

        case _DP_TWO_LANE:

            // Read Lane1 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE1 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane1 DFE Fail", 0);

                return _FALSE;
            }

            // Read Lane0 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE0 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane0 DFE Fail", 0);

                return _FALSE;
            }

            break;

        case _DP_ONE_LANE:

            // Read Lane0 DFE
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_D0_DP_LANE0 << 6));

            // Read Back Vth
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            pData[0] = (ScalerGetByte(P1D_F1_COEF_2) & 0x0F);

            // Read Back Tap0
            ScalerSetBit(P1D_F0_COEF_1, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
            pData[1] = (ScalerGetByte(P1D_F1_COEF_2) & 0x1F);

            if(PDATA_WORD(0) == 0x0015)
            {
                DebugMessageRx0("7. Lane0 DFE Fail", 0);

                return _FALSE;
            }

            break;

        default:

            return _FALSE;

            break;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description : Initial Signal check
// Input Value  : DP Link Rate
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SignalDetectInitial(BYTE ucDpLinkRate)
{
    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////

    // [7] cmu_en = 1'b0 --> Disable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, 0x00);

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_A1_CMU_01, 0x00);

    ScalerSetBit(PB_A1_CMU_01, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

    // Enable Local Bias LPF
    ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

    for(pData[0] = 0; pData[0] <= 2; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT0);
    ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));
    ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    ScalerSetBit(PB_A1_CMU_01, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

    ////////////////
    // LE Setting //
    ////////////////

    // [7] Positive Symbol-Rate Clock
    ScalerSetBit(P1D_A0_L0_DFE_EN_1, ~_BIT7, _BIT7);
    ScalerSetBit(P1D_B0_L1_DFE_EN_1, ~_BIT7, _BIT7);
    ScalerSetBit(P1D_C0_L2_DFE_EN_1, ~_BIT7, _BIT7);
    ScalerSetBit(P1D_D0_L3_DFE_EN_1, ~_BIT7, _BIT7);

    // [7:6] adapt_mode[1:0] = 2'b10 --> Amplitude-based Adaptation with Independent LE Loop(Loop Mode 2)
    // [5] edge_det_mode = 1 --> Edge Lag Data
    // [4] transition_only = 1 --> Only Transition Bit is Effective
    // [3] le_auto_reload = 0 --> Disable Auto-reload LE Coefficient
    // [2:0] tap1_delay[2:0] = 3'b010 --> Tap1+LE Delay 2us after Tap0
    ScalerSetByte(P1D_E0_MODE_TIMER, 0xB2);

    // LE Max = 31, Initial = 18, Servo Initial = 16
    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0xF2);
    ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0xF2);
    ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0xF2);
    ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0xF2);
    ScalerSetByte(P1D_A3_L0_INIT_1, 0xD0);
    ScalerSetByte(P1D_B3_L1_INIT_1, 0xD0);
    ScalerSetByte(P1D_C3_L2_INIT_1, 0xD0);
    ScalerSetByte(P1D_D3_L3_INIT_1, 0xD0);

    // Load Initial LE Code
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // DFE Loop Normal
    ScalerSetBit(P1D_EF_RESET_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_EF_RESET_1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Disable All Adaptation Loop
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR2:

            // [7:5] LE_ISEL = 3'b011
            // [4:2] LE_RLSEL = 3'b000
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT5));

            break;

        case _DP_LINK_HBR:

            // [7:5] LE_ISEL = 3'b010
            // [4:2] LE_RLSEL = 3'b001
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT2));

            break;

        case _DP_LINK_RBR:
        default:

            // [7:5] LE_ISEL = 3'b000
            // [4:2] LE_RLSEL = 3'b011
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

            break;
    }
}

//--------------------------------------------------
// Description : Check Valid Signal
// Input Value  : DP Link Rate and Lane Count
// Output Value : True --> valid, False --> invalid
//--------------------------------------------------
bit ScalerDpRx0SignalCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane)
{
    WORD usDataStreamL0 = 0;
    WORD usDataStreamL1 = 0;
    WORD usDataStreamL2 = 0;
    WORD usDataStreamL3 = 0;

    // [5] ln_ck_sel = 1'b0 -> data stream
    // [4:0] DP_XTAL_CYCLE = 4'b00100 -> XTAL Counter Cycles = 2000 need to wait at least 75us
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

    switch(ucDpcdLane)
    {
        case _DP_ONE_LANE:

            // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL0 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            break;

        case _DP_TWO_LANE:

            // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL0 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            // [1:0] freqdet_lane_sel = 2'b01 -> Lane1
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE1);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL1 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            break;

        default:
        case _DP_FOUR_LANE:

            // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL0 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            // [1:0] freqdet_lane_sel = 2'b01 -> Lane1
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE1);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL1 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            // [1:0] freqdet_lane_sel = 2'b10 -> Lane2
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE2);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL2 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            // [1:0] freqdet_lane_sel = 2'b11 -> Lane3
            ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE3);

            // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT Value
            ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

            // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
            ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

            // Waiting for Measure Done -> 150us
            for(pData[0] = 0; pData[0] <= 30; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);

                if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
                {
                    usDataStreamL3 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

                    break;
                }
            }

            break;
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

#if(_DP_MST_SUPPORT == _ON)
    // Data Stream Count Upper Bound = (VCO target count) x 2 x 0.65
    // Data Stream Count Lower Bound = (VCO target count) x 2 x 0.4
    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR2:

            switch(ucDpcdLane)
            {
                case _DP_ONE_LANE:

                    if((usDataStreamL0 > 0x32C8) || (usDataStreamL0 < 0x1F40))
                    {
                        return _FALSE;
                    }

                    break;

                case _DP_TWO_LANE:

                    if(((usDataStreamL1 > 0x32C8) || (usDataStreamL1 < 0x1F40)) || ((usDataStreamL0 > 0x32C8) || (usDataStreamL0 < 0x1F40)))
                    {
                        return _FALSE;
                    }

                    break;

                default:
                case _DP_FOUR_LANE:

                    if(((usDataStreamL3 > 0x32C8) || (usDataStreamL3 < 0x1F40)) ||
                       ((usDataStreamL2 > 0x32C8) || (usDataStreamL2 < 0x1F40)) ||
                       ((usDataStreamL1 > 0x32C8) || (usDataStreamL1 < 0x1F40)) ||
                       ((usDataStreamL0 > 0x32C8) || (usDataStreamL0 < 0x1F40)))
                    {
                        return _FALSE;
                    }

                    break;
            }

            break;

        case _DP_LINK_HBR:

            switch(ucDpcdLane)
            {
                case _DP_ONE_LANE:

                    if((usDataStreamL0 > 0x1964) || (usDataStreamL0 < 0xFA0))
                    {
                        return _FALSE;
                    }

                    break;

                case _DP_TWO_LANE:

                    if(((usDataStreamL1 > 0x1964) || (usDataStreamL1 < 0xFA0)) || ((usDataStreamL0 > 0x1964) || (usDataStreamL0 < 0xFA0)))
                    {
                        return _FALSE;
                    }

                    break;

                default:
                case _DP_FOUR_LANE:

                    if(((usDataStreamL3 > 0x1964) || (usDataStreamL3 < 0xFA0)) ||
                       ((usDataStreamL2 > 0x1964) || (usDataStreamL2 < 0xFA0)) ||
                       ((usDataStreamL1 > 0x1964) || (usDataStreamL1 < 0xFA0)) ||
                       ((usDataStreamL0 > 0x1964) || (usDataStreamL0 < 0xFA0)))
                    {
                        return _FALSE;
                    }

                    break;
            }

            break;

        default:
        case _DP_LINK_RBR:

            switch(ucDpcdLane)
            {
                case _DP_ONE_LANE:

                    if((usDataStreamL0 > 0xF3C) || (usDataStreamL0 < 0x960))
                    {
                        return _FALSE;
                    }

                    break;

                case _DP_TWO_LANE:

                    if(((usDataStreamL1 > 0xF3C) || (usDataStreamL1 < 0x960)) || ((usDataStreamL0 > 0xF3C) || (usDataStreamL0 < 0x960)))
                    {
                        return _FALSE;
                    }

                    break;

                default:
                case _DP_FOUR_LANE:

                    if(((usDataStreamL3 > 0xF3C) || (usDataStreamL3 < 0x960)) ||
                       ((usDataStreamL2 > 0xF3C) || (usDataStreamL2 < 0x960)) ||
                       ((usDataStreamL1 > 0xF3C) || (usDataStreamL1 < 0x960)) ||
                       ((usDataStreamL0 > 0xF3C) || (usDataStreamL0 < 0x960)))
                    {
                        return _FALSE;
                    }

                    break;
            }

            break;
    }
#else
    // Data Stream Count Upper Bound = (VCO target count) x 2 x 0.65
    // Data Stream Count Lower Bound = (VCO target count) x 2 x 0.55
    switch(ucDpLinkRate)
    {
        case _DP_LINK_HBR2:

            switch(ucDpcdLane)
            {
                case _DP_ONE_LANE:

                    if((usDataStreamL0 > 0x32C8) || (usDataStreamL0 < 0x2AF8))
                    {
                        return _FALSE;
                    }

                    break;

                case _DP_TWO_LANE:

                    if(((usDataStreamL1 > 0x32C8) || (usDataStreamL1 < 0x2AF8)) || ((usDataStreamL0 > 0x32C8) || (usDataStreamL0 < 0x2AF8)))
                    {
                        return _FALSE;
                    }

                    break;

                default:
                case _DP_FOUR_LANE:

                    if(((usDataStreamL3 > 0x32C8) || (usDataStreamL3 < 0x2AF8)) ||
                       ((usDataStreamL2 > 0x32C8) || (usDataStreamL2 < 0x2AF8)) ||
                       ((usDataStreamL1 > 0x32C8) || (usDataStreamL1 < 0x2AF8)) ||
                       ((usDataStreamL0 > 0x32C8) || (usDataStreamL0 < 0x2AF8)))
                    {
                        return _FALSE;
                    }

                    break;
            }

            break;

        case _DP_LINK_HBR:

            switch(ucDpcdLane)
            {
                case _DP_ONE_LANE:

                    if((usDataStreamL0 > 0x1964) || (usDataStreamL0 < 0x157C))
                    {
                        return _FALSE;
                    }

                    break;

                case _DP_TWO_LANE:

                    if(((usDataStreamL1 > 0x1964) || (usDataStreamL1 < 0x157C)) || ((usDataStreamL0 > 0x1964) || (usDataStreamL0 < 0x157C)))
                    {
                        return _FALSE;
                    }

                    break;

                default:
                case _DP_FOUR_LANE:

                    if(((usDataStreamL3 > 0x1964) || (usDataStreamL3 < 0x157C)) ||
                       ((usDataStreamL2 > 0x1964) || (usDataStreamL2 < 0x157C)) ||
                       ((usDataStreamL1 > 0x1964) || (usDataStreamL1 < 0x157C)) ||
                       ((usDataStreamL0 > 0x1964) || (usDataStreamL0 < 0x157C)))
                    {
                        return _FALSE;
                    }

                    break;
            }

            break;

        default:
        case _DP_LINK_RBR:

            switch(ucDpcdLane)
            {
                case _DP_ONE_LANE:

                    if((usDataStreamL0 > 0xF3C) || (usDataStreamL0 < 0xCE4))
                    {
                        return _FALSE;
                    }

                    break;

                case _DP_TWO_LANE:

                    if(((usDataStreamL1 > 0xF3C) || (usDataStreamL1 < 0xCE4)) || ((usDataStreamL0 > 0xF3C) || (usDataStreamL0 < 0xCE4)))
                    {
                        return _FALSE;
                    }

                    break;

                default:
                case _DP_FOUR_LANE:

                    if(((usDataStreamL3 > 0xF3C) || (usDataStreamL3 < 0xCE4)) ||
                       ((usDataStreamL2 > 0xF3C) || (usDataStreamL2 < 0xCE4)) ||
                       ((usDataStreamL1 > 0xF3C) || (usDataStreamL1 < 0xCE4)) ||
                       ((usDataStreamL0 > 0xF3C) || (usDataStreamL0 < 0xCE4)))
                    {
                        return _FALSE;
                    }

                    break;
            }

            break;
    }
#endif

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Display Format Generator Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx0DisplayFormatSetting(void)
{
    BYTE ucOddFlg = 0;
    WORD usDpVtotal = 0;
    WORD usDpHactive = 0;
    DWORD ulStreamClkValue = 0;
    DWORD ulVBs2BsCount = 0;

#if(_DP_FREESYNC_SUPPORT == _ON)
    WORD usHBs2BsCount = 0;
    DWORD ulDpMvidValue = 0;
    DWORD ulDpNvidValue = 0;
#endif

    // Measurement Enable
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The result
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    // Measurement Disable
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);

    // VBs2BS count in GDI clk
    ulVBs2BsCount = ((((DWORD)(ScalerGetByte(PB5_58_MN_MEAS_CTRL) & 0x1F)) << 16) | (((DWORD)ScalerGetByte(PB5_59_MN_MEAS_VLN_M)) << 8) | ((DWORD)ScalerGetByte(PB5_5A_MN_MEAS_VLN_L)));

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        // Get IVfreq
        PDATA_DWORD(0) = ((DWORD)_GDI_CLK_KHZ * 1000 / (ulVBs2BsCount / 10));

        if((PDATA_DWORD(0) < (_PANEL_FREESYNC_MIN_FRAME_RATE - _FRAME_SYNC_MARGIN)) || (PDATA_DWORD(0) > (_PANEL_FREESYNC_MAX_FRAME_RATE + _FRAME_SYNC_MARGIN)))
        {
            return _FALSE;
        }

        // HBs2Bs count in Link Clk / 2
        usHBs2BsCount = (((DWORD)ScalerGetByte(PB5_5B_MN_MEAS_HLN_M)) << 8) | ((DWORD)ScalerGetByte(PB5_5C_MN_MEAS_HLN_L));

        // VTotal in line, Link Clk / 2 : (Link Rate * 27 / 2)
        usDpVtotal = ulVBs2BsCount * (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) * 27 / 2) / usHBs2BsCount * 1000 / _GDI_CLK_KHZ;

        ulDpMvidValue = ((((DWORD)ScalerGetByte(PB6_1A_MSA_MVID_0)) << 16) | (((DWORD)ScalerGetByte(PB6_1B_MSA_MVID_1)) << 8) | ((DWORD)ScalerGetByte(PB6_1C_MSA_MVID_2)));

        ulDpNvidValue = ((((DWORD)ScalerGetByte(PB6_1D_MSA_NVID_0)) << 16) | (((DWORD)ScalerGetByte(PB6_1E_MSA_NVID_1)) << 8) | ((DWORD)ScalerGetByte(PB6_1F_MSA_NVID_2)));

        // [5] ln_ck_sel = 1'b1 -> CDR Clock
        // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

        // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
        ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

        // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
        ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

        // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

        // Waiting for Measure Done
        ScalerTimerDelayXms(2);

        PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));

        // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

        PDATA_DWORD(0) = ((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ;

        // Calculate streamclk
        ulStreamClkValue = ((DWORD)ulDpMvidValue * (PDATA_DWORD(0) / ulDpNvidValue) + (PDATA_DWORD(0) % ulDpNvidValue * 100 / ulDpNvidValue * (DWORD)ulDpMvidValue / 100));
    }
    else
#endif
    {
        usDpVtotal = ((((WORD)ScalerGetByte(PB6_10_MSA_VTTE_0)) << 8) | ((WORD)ScalerGetByte(PB6_11_MSA_VTTE_1)));

        // Calculate streamclk (Unit is Hz)
        ulStreamClkValue = (((((((DWORD)ScalerGetByte(PB6_08_MSA_HTT_0)) << 8) | ((WORD)ScalerGetByte(PB6_09_MSA_HTT_1))) * ((DWORD)usDpVtotal) * 100) / ulVBs2BsCount) * _GDI_CLK_KHZ * 10);
    }

    // Input Pixel CLK Unit is 0.1 M
    SET_INPUT_PIXEL_CLK(ulStreamClkValue / 100000);

    // Disable Generate Display Format
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT7, 0x00);

    // DP Display Format Generator Reset
    ScalerSetBit(PB5_00_MAC_DIG_RESET_CTRL, ~_BIT7, _BIT7);
    ScalerSetBit(PB5_00_MAC_DIG_RESET_CTRL, ~_BIT7, 0x00);

    // Set Vactive
    ScalerRead(PB6_16_MSA_VHT_0, 2, &pData[4], _AUTOINC);
    ScalerSetByte(PB5_4D_MN_DPF_VHT_M, pData[4]);
    ScalerSetByte(PB5_4E_MN_DPF_VHT_L, pData[5]);

    // Set Hactive
    ScalerRead(PB6_0C_MSA_HWD_0, 2, pData, _AUTOINC);
    ScalerSetByte(PB5_45_MN_DPF_HWD_M, pData[0]);
    ScalerSetByte(PB5_46_MN_DPF_HWD_L, pData[1]);
    usDpHactive = PDATA_WORD(0);

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        // HTotal in Pixel Clk, Link Clk / 2 : (Link Rate * 27 / 2)
        WORD usDpHtotal = (DWORD)usHBs2BsCount * (GET_INPUT_PIXEL_CLK() / 10) / (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) * 27 / 2);

        // Set Htotal
        ScalerSetByte(PB5_41_MN_DPF_HTT_M, HIBYTE(usDpHtotal));
        ScalerSetByte(PB5_42_MN_DPF_HTT_L, LOBYTE(usDpHtotal));

        // Set Hstart
        ScalerSetByte(PB5_43_MN_DPF_HST_M, HIBYTE(_DP_DE_ONLY_MODE_HSTART));
        ScalerSetByte(PB5_44_MN_DPF_HST_L, LOBYTE(_DP_DE_ONLY_MODE_HSTART));

        // Set HSW
        ScalerSetByte(PB5_47_MN_DPF_HSW_M, HIBYTE(_DP_DE_ONLY_MODE_HSW));
        ScalerSetByte(PB5_48_MN_DPF_HSW_L, LOBYTE(_DP_DE_ONLY_MODE_HSW));

        // Set Vstart
        ScalerSetByte(PB5_4B_MN_DPF_VST_M, HIBYTE(_DP_DE_ONLY_MODE_VSTART));
        ScalerSetByte(PB5_4C_MN_DPF_VST_L, LOBYTE(_DP_DE_ONLY_MODE_VSTART));

        // Set VSW
        ScalerSetByte(PB5_4F_MN_DPF_VSW_M, HIBYTE(_DP_DE_ONLY_MODE_VSW));
        ScalerSetByte(PB5_50_MN_DPF_VSW_L, LOBYTE(_DP_DE_ONLY_MODE_VSW));

        PDATA_WORD(0) = ScalerDpRx0GetBStoHSDelay(usDpHtotal);

        // Set HBs2Bs
        ScalerSetByte(PB5_38_BS2HS_0, pData[0]);
        ScalerSetByte(PB5_39_BS2HS_1, pData[1]);

        ScalerDpRx0InterlaceCheck(&usDpVtotal, &ucOddFlg);

        // Set DE Only Mode Vsync Front Porch
        ScalerSetByte(PB5_40_VS_FRONT_PORCH, GET_DP_RX0_VFRONT_PORCH());

        if(ScalerDpRx0GetAmdSpdInfo(_SPD_INFO_FREESYNC_SUPPORT) == _ENABLE)
        {
            // Get DP DRR SPD Vmax
            g_usFREESYNCVFreq = (WORD)ScalerDpRx0GetAmdSpdInfo(_SPD_INFO_FREESYNC_MAX_VFREQ) * 10;
        }
        else
        {
            g_usFREESYNCVFreq = _PANEL_FREESYNC_MAX_FRAME_RATE;
            DebugMessageRx0("DP DRR without SPD info", 0x00);
        }

        // Set DE Only Mode
        ScalerSetBit(PB5_30_DPF_CTRL_0, ~(_BIT7 | _BIT5 | _BIT4), _BIT4);

        if(ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE)
        {
            // Choose Frame start BE to Reset FIFO
            ScalerSetBit(PB5_20_PG_CTRL_0, ~_BIT5, _BIT5);
        }
        else
        {
            // Choose vsync posedge to Reset FIFO
            ScalerSetBit(PB5_20_PG_CTRL_0, ~_BIT5, 0x00);
        }

        // Set DP FREESYNC Mode Enable
        ScalerSetBit(PB5_F0_DP_RSV0, ~_BIT0, _BIT0);

        DebugMessageRx0("FREESYNC Mode Enabled!!", ScalerGetByte(PB5_30_DPF_CTRL_0));
    }
    else
#endif
    {
        DWORD ulBs2VsDelay = 0;

        // Set Htotal
        ScalerRead(PB6_08_MSA_HTT_0, 2, &pData[2], _AUTOINC);
        ScalerSetByte(PB5_41_MN_DPF_HTT_M, pData[2]);
        ScalerSetByte(PB5_42_MN_DPF_HTT_L, pData[3]);

        // Get HSW
        pData[4] = ScalerGetBit(PB6_0E_MSA_HSW_0, (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
        pData[5] = ScalerGetByte(PB6_0F_MSA_HSW_1);

        // Get HSW min by Measure clock
        PDATA_WORD(3) = ((DWORD) _DP_HSYNC_WIDTH_MEASURE_COUNTER * GET_INPUT_PIXEL_CLK() * 100) / _MEASURE_CLK + 1;

        // Check HSW <= HSW min
        if(PDATA_WORD(2) <= PDATA_WORD(3))
        {
            // Check if H porch is more than HSW min
            if((PDATA_WORD(1) - usDpHactive) >= PDATA_WORD(3))
            {
                // HSW = HSW min
                PDATA_WORD(2) = PDATA_WORD(3);
            }
            else
            {
                // HSW = Max H Porch
                PDATA_WORD(2) = (PDATA_WORD(1) - usDpHactive);
            }
        }

        // DPF H Front Porch must not be less than 8 (HW constraint)
        // Check if H porch is more than 8
        if((PDATA_WORD(1) - usDpHactive - PDATA_WORD(2)) <= _DP_HSYNC_FRONT_PORCH)
        {
            // HSW < HSW min
            if(PDATA_WORD(2) < PDATA_WORD(3))
            {
                // Hstart = HSW
                PDATA_WORD(4) = PDATA_WORD(2);
            }
            else if((PDATA_WORD(1) - usDpHactive - PDATA_WORD(3) >= _DP_HSYNC_FRONT_PORCH))
            {
                // HSW = H porch - _DP_HSYNC_FRONT_PORCH
                PDATA_WORD(2) = PDATA_WORD(1) - usDpHactive - _DP_HSYNC_FRONT_PORCH;

                // Hstart = HSW
                PDATA_WORD(4) = PDATA_WORD(2);
            }
            else
            {
                // HSW = HSW min
                PDATA_WORD(2) = PDATA_WORD(3);

                // Hstart = HSW min
                PDATA_WORD(4) = PDATA_WORD(3);
            }
        }
        else
        {
            // Hstart = Htotal - Hactive - _DP_HSYNC_FRONT_PORCH
            PDATA_WORD(4) = PDATA_WORD(1) - usDpHactive - _DP_HSYNC_FRONT_PORCH;
        }

        // Set HSW and HSP => positive
        ScalerSetByte(PB5_47_MN_DPF_HSW_M, (pData[4] & ~_BIT7));
        ScalerSetByte(PB5_48_MN_DPF_HSW_L, pData[5]);

        // Set Hstart
        ScalerSetByte(PB5_43_MN_DPF_HST_M, pData[8]);
        ScalerSetByte(PB5_44_MN_DPF_HST_L, pData[9]);

        DebugMessageRx0("###Origin usVTotal###", usDpVtotal);

        if(ScalerDpRx0InterlaceCheck(&usDpVtotal, &ucOddFlg) == _TRUE) // Interlace
        {
            DebugMessageRx0("7. IIIIIInterLace Vtotal", usDpVtotal);
        }
        else // Progressive
        {
            DebugMessageRx0("7. PPPPProgressive", 0);
        }

        // Set Vtotal
        ScalerSetByte(PB5_49_MN_DPF_VTT_M, (usDpVtotal >> 8));
        ScalerSetByte(PB5_4A_MN_DPF_VTT_L, (usDpVtotal & 0xFF));

        // Get Vactive
        ScalerRead(PB6_16_MSA_VHT_0, 2, &pData[4], _AUTOINC);

        // V Front porch must not be less than 2 because of V scaling down.
        // Set Vstart -> (Vtotal - Vactive - Frontporch)
        PDATA_WORD(0) = usDpVtotal - PDATA_WORD(2) - GET_DP_RX0_VFRONT_PORCH();
        ScalerSetByte(PB5_4B_MN_DPF_VST_M, pData[0]);
        ScalerSetByte(PB5_4C_MN_DPF_VST_L, pData[1]);

        // Set VSW; Set VSP => Positive
        ScalerSetByte(PB5_4F_MN_DPF_VSW_M, (HIBYTE(_DP_VSYNC_WIDTH) & ~_BIT7));
        ScalerSetByte(PB5_50_MN_DPF_VSW_L, LOBYTE(_DP_VSYNC_WIDTH));

        ulBs2VsDelay = ScalerDpRx0GetBStoVSDelay();

        // Set Odd Field BS to VS Delay
        ScalerSetByte(PB5_35_OVBLK2VS_H, (BYTE)(ulBs2VsDelay >> 16));
        ScalerSetByte(PB5_36_OVBLK2VS_M, (BYTE)(ulBs2VsDelay >> 8));
        ScalerSetByte(PB5_37_OVBLK2VS_L, (BYTE)(ulBs2VsDelay >> 0));

        if((bit)ucOddFlg == _TRUE)
        {
            // Get Htotal
            ScalerRead(PB6_08_MSA_HTT_0, 2, &pData[10], _AUTOINC);

            // BStoVSDelay = BStoVSDelay + (Link Clk * 256 / Stream Clk) * ((DWORD)Htotal) / 256;
            ulBs2VsDelay += ((((DWORD)ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00)) * 270UL) * 256) / ((DWORD)GET_INPUT_PIXEL_CLK()) * ((DWORD)PDATA_WORD(5)) / 256 / 2;
        }

        // Set Even Field BS to VS Delay
        ScalerSetByte(PB5_32_EVBLK2VS_H, (BYTE)(ulBs2VsDelay >> 16));
        ScalerSetByte(PB5_33_EVBLK2VS_M, (BYTE)(ulBs2VsDelay >> 8));
        ScalerSetByte(PB5_34_EVBLK2VS_L, (BYTE)(ulBs2VsDelay >> 0));

        // Choose VS Rising to Reset FIFO
        ScalerSetBit(PB5_20_PG_CTRL_0, ~_BIT5, 0x00);

        // Set DP FREESYNC Mode Disable
        ScalerSetBit(PB5_F0_DP_RSV0, ~_BIT0, 0x00);

        // Set full last line Mode
        ScalerSetBit(PB5_30_DPF_CTRL_0, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

        DebugMessageRx0("FREESYNC Mode Disabled", ScalerGetByte(PB5_30_DPF_CTRL_0));
    }

    // Double Buffer to Apply Display Format Setting
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT6, _BIT6);

    ScalerDpRx0VideoSetting();

    return _TRUE;
}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Sink Count Update
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0UpdateSinkCount(void)
{
    if(GET_DP_TX_HPD_DEBOUNCE_LEVEL() == _HIGH)
    {
        // Align Reported Cable status with Downstream Port
        SET_DP_RX_REPORT_DOWNSTREAM_DP_CABLE_STATUS(_DP_PLUG);

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
#endif
        {
#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
            {
                // Read Sink Count
                if(ScalerDpTxAuxNativeRead(0x00, 0x02, 0x00, 1, pData) == _TRUE)
                {
                    // Set Rx Sink Count
                    pData[1] = ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x00);

                    // Downstream sink count number plus Branch device itself
                    pData[1] = ((pData[1] & _BIT6) | (pData[0] & 0xBF)) + 1;
                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, pData[1]);
                }
                else
                {
                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);
                }
            }
            else
#endif // End of #if(_DP_MST_SUPPORT == _ON)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);
            }
        }

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
        {
#if(_DP_MST_SUPPORT == _ON)
            if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
            {
                // Read Sink Count
                if(ScalerDpTxAuxNativeRead(0x00, 0x02, 0x00, 1, pData) == _TRUE)
                {
                    // Set Rx Sink Count
                    pData[1] = ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x00);

                    // Downstream sink count number plus Branch device itself
                    pData[1] = ((pData[1] & _BIT6) | (pData[0] & 0xBF)) + 1;
                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, pData[1]);
                }
                else
                {
                    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);
                }
            }
            else
#endif // End of #if(_DP_MST_SUPPORT == _ON)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);
            }
        }
#endif // End of #if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    }
    else
    {
        ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x00, 0x41);

        // Align Reported Cable status with Downstream Port
        SET_DP_RX_REPORT_DOWNSTREAM_DP_CABLE_STATUS(_DP_UNPLUG);
    }
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Check Dp Interlace by VBID or Measure
// Input Value  : None
// Output Value : True --> Interlace
//--------------------------------------------------
bit ScalerDpRx0InterlaceCheck(WORD *pusVTotal, BYTE *pucOddFlg)
{
    DWORD ulLinkClk = 0;
    WORD usTempVTotal = *pusVTotal;
    WORD usHTotalCount = 0;
    WORD usVsyncWidth = 0;
    WORD usVstart = 0;
    WORD usVactive = 0;

    // Set Vfront Porch
    SET_DP_RX0_VFRONT_PORCH(_DP_VSYNC_FRONT_PORCH);

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        // Field inverse disable
        ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT4, 0x00);

        if(ScalerGetBit(PB6_01_DP_VBID, _BIT2) == _BIT2) // Interlace
        {
            // Start to Measure Vertical BS to BS Counter by GDI Clock
            ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
            ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

            if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
            {
                return _FALSE;
            }

            // Pop up The result
            ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

            // Get Measure Result
            ScalerRead(PB5_58_MN_MEAS_CTRL, 3, &pData[5], _AUTOINC);

            // Delay 2ms To Get VBID
            ScalerTimerDelayXms(2);

            // Get VBID
            ScalerRead(PB6_01_DP_VBID, 1, &pData[1], _NON_AUTOINC);

            // Delay 1 frame
            ScalerTimerDelayXms((((PDATA_DWORD(1) & 0x001FFFFF) / (_GDI_CLK_KHZ)) + 2));

            // Pop up Measure Result
            ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

            // Get Measure Result
            ScalerRead(PB5_58_MN_MEAS_CTRL, 3, &pData[9], _AUTOINC);

            // Get VBID
            ScalerRead(PB6_01_DP_VBID, 1, &pData[2], _NON_AUTOINC);

            PDATA_DWORD(1) = (PDATA_DWORD(1) & 0x001FFFFF);
            PDATA_DWORD(2) = (PDATA_DWORD(2) & 0x001FFFFF);

            if((pData[1] & _BIT1) != (pData[2] & _BIT1))
            {
                // Enable DP Interlace, Field Information reference to VBID
                ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), _BIT7);

                if((ScalerGetBit(PB5_57_INTERLACE_MODE_CONFIG, _BIT0) == 0x00) &&
                   ((((pData[1] & _BIT1) == _BIT1) && ((pData[2] & _BIT1) == 0x00) && (PDATA_DWORD(1) < PDATA_DWORD(2))) ||
                    (((pData[1] & _BIT1) == 0x00) && ((pData[2] & _BIT1) == _BIT1) && (PDATA_DWORD(1) > PDATA_DWORD(2)))))
                {
                    // Field inverse enable
                    ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT4, _BIT4);
                }
            }
            else
            {
                // Enable interlace mode, field reference HW
                ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            }

            *pusVTotal = usTempVTotal;

            return _TRUE;
        }
    }
    else
#endif
    {
        // [5] ln_ck_sel = 1'b1 -> CDR Clock
        // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

        // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
        ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

        // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
        ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

        // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

        // Waiting for Measure Done
        ScalerTimerDelayXms(2);

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
        }
        else
        {
            if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
            {
                PDATA_WORD(0) = 0x4E20;
            }
            else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
            {
                PDATA_WORD(0) = 0x2710;
            }
            else // Both Default && _DP_LINK_RBR Case
            {
                PDATA_WORD(0) = 0x1770;
            }
        }

        // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

        PDATA_DWORD(0) = (((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ);

        // Link Clk in KHz
        ulLinkClk = (PDATA_DWORD(0) / 1000);

        DebugMessageRx0("Current Link Clk", ulLinkClk);

        // Field inverse disable
        ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT4, 0x00);

        // Start to Measure Vertical BS to BS Counter by GDI Clock
        ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
        ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

        if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
        {
            return _FALSE;
        }

        // Pop up The result
        ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

        // Get Measure Result
        ScalerRead(PB5_58_MN_MEAS_CTRL, 3, &pData[5], _AUTOINC);

        // Delay 2ms To Get VBID
        ScalerTimerDelayXms(2);

        // Get VBID
        ScalerRead(PB6_01_DP_VBID, 1, &pData[1], _NON_AUTOINC);

        // Delay 1 frame
        ScalerTimerDelayXms((((PDATA_DWORD(1) & 0x001FFFFF) / (_GDI_CLK_KHZ)) + 2));

        // Pop up Measure Result
        ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

        // Get Measure Result
        ScalerRead(PB5_58_MN_MEAS_CTRL, 3, &pData[9], _AUTOINC);

        // Get Measure Htotal Counts
        ScalerRead(PB5_5B_MN_MEAS_HLN_M, 2, &pData[12], _AUTOINC);

        // Get VBID
        ScalerRead(PB6_01_DP_VBID, 1, &pData[2], _NON_AUTOINC);

        PDATA_DWORD(1) = (PDATA_DWORD(1) & 0x001FFFFF);
        PDATA_DWORD(2) = (PDATA_DWORD(2) & 0x001FFFFF);

        // Disable Measure Block
        ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);

        // Convert HTotal Count from 1/2 Link Clk to GDI Clk
        usHTotalCount = ((DWORD)PDATA_WORD(6) * _GDI_CLK_KHZ * 2 + (ulLinkClk >> 1)) / ulLinkClk;

        DebugMessageRx0("HTotal Count", usHTotalCount);

        // if VTotal Difference > 1/2 HTotal
        if((ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))) > (usHTotalCount / 2))
        {
            if(PDATA_DWORD(1) < PDATA_DWORD(2))
            {
                usTempVTotal = ((PDATA_DWORD(1) * 8 + (usHTotalCount >> 1)) / usHTotalCount);
            }
            else
            {
                usTempVTotal = ((PDATA_DWORD(2) * 8 + (usHTotalCount >> 1)) / usHTotalCount);
            }

            usTempVTotal = (usTempVTotal + 4) / 8;

            *pucOddFlg = _TRUE;
        }
        else
        {
            *pucOddFlg = _FALSE;
        }

        DebugMessageRx0("####Calculated usVTotal####", usTempVTotal);

        DebugMessageRx0("7. DelayTime", (((PDATA_DWORD(1) & 0x000FFFFF) / (_GDI_CLK_KHZ)) + 2));
        DebugMessageRx0("7. PDATA_DWORD(1)", PDATA_DWORD(1));
        DebugMessageRx0("7. PDATA_DWORD(2)", PDATA_DWORD(2));
        DebugMessageRx0("7. PDATA_DWORD(ABS)", (ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))));

        if(ScalerGetBit(PB6_01_DP_VBID, _BIT2) == _BIT2) // Interlace
        {
            // Get VSW
            usVsyncWidth = ((WORD)ScalerGetByte(PB6_18_MSA_VSW_0) << 8) | ScalerGetByte(PB6_19_MSA_VSW_1);
            usVsyncWidth &= 0x7FFF;

            // Get VStart
            usVstart = ((WORD)ScalerGetByte(PB6_14_MSA_VST_0) << 8) | ScalerGetByte(PB6_15_MSA_VST_1);

            // Enable DP Interlace
            ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT7, _BIT7);

            if((*pucOddFlg) == _FALSE)
            {
                // Disable DP Interlace
                ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT7, 0x00);
            }

            // usVbackporch = usVstart - Fixed V-Sync Pulse Width, usVbackporch > usVsyncWidth + 2 lines, here 2 lines is for V-Sync Falling edge to DEN Rising Edge distance margion
            if(((pData[1] & _BIT1) != (pData[2] & _BIT1)) && (usVstart > (usVsyncWidth + _DP_VSYNC_WIDTH + 2)))
            {
                // Field Information reference to VBID
                ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT6, 0x00);

                // Get Vactive
                usVactive = ((WORD)ScalerGetByte(PB6_16_MSA_VHT_0) << 8) | ScalerGetByte(PB6_17_MSA_VHT_1);

                // Set Front Porch = VTotal - Active height - MSA V Start + V Sync Pulse Width
                SET_DP_RX0_VFRONT_PORCH(usTempVTotal - usVactive - usVstart + usVsyncWidth);

                if((ScalerGetBit(PB5_57_INTERLACE_MODE_CONFIG, _BIT0) == 0x00) &&
                   ((((pData[1] & _BIT1) == _BIT1) && ((pData[2] & _BIT1) == 0x00) && (PDATA_DWORD(1) < PDATA_DWORD(2))) ||
                    (((pData[1] & _BIT1) == 0x00) && ((pData[2] & _BIT1) == _BIT1) && (PDATA_DWORD(1) > PDATA_DWORD(2)))))
                {
                    // Field inverse enable
                    ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT4, _BIT4);
                }
            }
            else
            {
                // Field reference HW
                ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~_BIT6, _BIT6);
            }

            *pusVTotal = usTempVTotal;

            return _TRUE;
        }
        else if((ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))) > (usHTotalCount / 2))
        {
            // Enable interlace mode, field reference HW
            ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            *pusVTotal = usTempVTotal;

            return _TRUE;
        }
    }

    // Disable DP Interlace
    ScalerSetBit(PB5_57_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), 0x00);

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Stream Clk PLL Setting
// Input Value  : None
// Output Value : True --> Stream CLK Regen. ok
//--------------------------------------------------
bit ScalerDpRx0StreamClkRegenerate(void)
{
    DWORD ulStreamClkValue = 0;
    SDWORD lOffsetValue = 0;
    DWORD ulpllm = 0;
    DWORD ulXtal_clk = 0;
    WORD usDpHtotal = 0;
    WORD usDpVtotal = 0;
    DWORD ulVBs2BsCount = 0;
    DWORD ulDpNvidValue = 0;
    BYTE ucpllo = 0;
    BYTE ucdivs = 0;
    BYTE ucdiv2 = 0;
    BYTE ucplln = 0;
    BYTE ucBuf = 0;
    BYTE ucdiv_pllo = 0;
    BYTE ucdiv_divs = 0;

#if(_DP_FREESYNC_SUPPORT == _ON)
    DWORD ulDpMvidValue = 0;
#endif

    // PLL Input Clock select to Link Clock, Output Clock Select to PLL Clock, Double Buffer.
    ScalerSetBit(PB5_A0_MN_SCLKG_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));

    ulDpNvidValue = ((((DWORD)ScalerGetByte(PB6_1D_MSA_NVID_0)) << 16) | (((DWORD)ScalerGetByte(PB6_1E_MSA_NVID_1)) << 8) | ((DWORD)ScalerGetByte(PB6_1F_MSA_NVID_2)));

    usDpHtotal = ((((WORD)ScalerGetByte(PB5_41_MN_DPF_HTT_M)) << 8) | ((WORD)ScalerGetByte(PB5_42_MN_DPF_HTT_L)));

    usDpVtotal = ((((WORD)ScalerGetByte(PB5_49_MN_DPF_VTT_M)) << 8) | ((WORD)ScalerGetByte(PB5_4A_MN_DPF_VTT_L)));

    // [5] ln_ck_sel = 1'b1 -> CDR Clock
    // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

    // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Waiting for Measure Done
    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
    {
        PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
    }
    else
    {
        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
        {
            PDATA_WORD(0) = 0x4E20;
        }
        else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
        {
            PDATA_WORD(0) = 0x2710;
        }
        else // Both Default && _DP_LINK_RBR Case
        {
            PDATA_WORD(0) = 0x1770;
        }
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    PDATA_DWORD(0) = (((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ);

    ulXtal_clk = (PDATA_DWORD(0) / 1000);

    // Measurement Enable
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The result
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    ulVBs2BsCount = ((((DWORD)(ScalerGetByte(PB5_58_MN_MEAS_CTRL) & 0x1F)) << 16) | ((DWORD)ScalerGetByte(PB5_59_MN_MEAS_VLN_M) << 8) | ((DWORD)ScalerGetByte(PB5_5A_MN_MEAS_VLN_L)));

    // Measurement Disable
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        ulDpMvidValue = ((((DWORD)ScalerGetByte(PB6_1A_MSA_MVID_0)) << 16) | (((DWORD)ScalerGetByte(PB6_1B_MSA_MVID_1)) << 8) | ((DWORD)ScalerGetByte(PB6_1C_MSA_MVID_2)));

        // Calculate streamclk
        ulStreamClkValue = ((DWORD)ulDpMvidValue * (PDATA_DWORD(0) / ulDpNvidValue) + (PDATA_DWORD(0) % ulDpNvidValue * 100 / ulDpNvidValue * (DWORD)ulDpMvidValue / 100));
    }
    else
#endif
    {
        // Calculate streamclk (Unit is Hz)
        ulStreamClkValue = (((((DWORD)usDpHtotal) * ((DWORD)usDpVtotal) * 100) / ulVBs2BsCount) * _GDI_CLK_KHZ * 10);
    }

    // Input Pixel CLK Unit is 0.1 M
    SET_INPUT_PIXEL_CLK(ulStreamClkValue / 100000);

    DebugMessageRx0("Stream Clk", ulStreamClkValue);

    ucplln = ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00);

    // Get DPLL parameter
    // If "600Mhz > ulStreamClkValue > 270Mhz"
    if((750000000 > ulStreamClkValue) && (ulStreamClkValue >= 270000000))//ybm
    {
        ucpllo = 0;
        ucdivs = 0;

        ucdiv_divs = 1;
        ucdiv_pllo = 1;

        ulpllm = ((((ulStreamClkValue / 4) * ucdiv_divs * ucdiv_pllo) * ucplln / 250 + (ulXtal_clk / 4)) / (ulXtal_clk));

        if(ulpllm > 257)
        {
            return _FALSE;
        }
    }
    // If "270MHz > ulStreamClkValue > 4.21875Mhz"
    else if((ulStreamClkValue < 270000000) && (ulStreamClkValue >= 4218750))
    {
        ucpllo = 1;

        if((ulStreamClkValue < 270000000) && (ulStreamClkValue >= 135000000))
        {
            ucdivs = 0;
        }
        else if((ulStreamClkValue < 135000000) && (ulStreamClkValue >= 67500000))
        {
            ucdivs = 1;
        }
        else if((ulStreamClkValue < 67500000) && (ulStreamClkValue >= 33750000))
        {
            ucdivs = 2;
        }
        else if((ulStreamClkValue < 33750000) && (ulStreamClkValue >= 16875000))
        {
            ucdivs = 4;
        }
        else if((ulStreamClkValue < 16875000) && (ulStreamClkValue >= 8437500))
        {
            ucdivs = 8;
        }
        else
        {
            ucdivs = 16;
        }

        // Because set 17 get minimum error for recovery stream clk , close to fact clk.
        if(ucdivs == 0)
        {
            ucdiv_divs = 1;
        }
        else
        {
            ucdiv_divs = 2 * ucdivs;
        }

        ucdiv_pllo = 1;

        if(ucpllo != 0)
        {
            ucdiv_pllo = 1;

            for(ucBuf = 0; ucBuf < ucpllo; ucBuf++)
            {
                ucdiv_pllo = 2 * ucdiv_pllo;
            }
        }

        ulpllm = ((((ulStreamClkValue / 4) * ucdiv_divs * ucdiv_pllo) * ucplln / 250 + (ulXtal_clk / 4)) / (ulXtal_clk));

        if(ulpllm > 257)
        {
            return _FALSE;
        }
    }
    else
    {
        return _FALSE;
    }

    ulpllm++;

    // offset = (m/n*f_ref - f)/(m/n*f_ref)*2^21
    // seperate *2^21 to *32*16384*4
    lOffsetValue = ((SDWORD)((ulXtal_clk * 1000 / ucplln) * ulpllm) - (SDWORD)(ulStreamClkValue * ucdiv_pllo * ucdiv_divs)) * 32 / ulpllm * ucplln / ulXtal_clk * 16384 / 1000 * 4;

    lOffsetValue = 0x7FFFF - lOffsetValue + 1;

    // DPPLL Power Down
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    /*
    // Disable M/N Tracking
    ScalerSetBit(PB5_A7_MN_SCLKG_TRK_CTRL, ~_BIT7, 0x00);
    */

    // Disable HSync Tracking
    ScalerSetBit(PB5_A7_MN_SCLKG_TRK_CTRL, ~_BIT6, 0x00);

    // Set VCOMD, phase Swallow Circuit Clock Select, SCLKGSTOP
    ScalerSetBit(PB5_BF_MN_SCLKG_PLL_WD, ~(0x7F), 0x16);

    // Set DPPLL Div_2 & Div_s
    ScalerSetByte(PB5_A3_MN_SCLKG_DIVS, (((ucdiv2) << 7) | ((ucdivs) << 0)));

    // Set DPPLL Div_O.
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~(_BIT1 | _BIT0), ucpllo);

    // Offset Value Setting
    ScalerSetByte(PB5_A6_MN_SCLKG_OFFS_L, (BYTE)lOffsetValue);
    ScalerSetByte(PB5_A5_MN_SCLKG_OFFS_M, (BYTE)(lOffsetValue >> 8));
    ScalerSetBit(PB5_A4_MN_SCLKG_OFFS_H, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)(lOffsetValue >> 16)) & (_BIT2 | _BIT1 | _BIT0));

    // Enable phase swallow
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~(_BIT5 | _BIT4), _BIT4);

    // Set DPPLL M Code
    ScalerSetBit(PB5_A0_MN_SCLKG_CTRL, ~(_BIT1 | _BIT0), (((ulpllm - 2) >> 8) & 0x03));
    ScalerSetByte(PB5_A1_MN_SCLKG_DIVM, ((ulpllm - 2) & 0xFF));

    // Set DPPLL N Code
    ScalerSetByte(PB5_A2_MN_SCLKG_DIVN, (ucplln - 2));

    // Load offset value
    ScalerSetBit(PB5_A4_MN_SCLKG_OFFS_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT7);

    // Double Buffer for M/N Tracking
    ScalerSetBit(PB5_A0_MN_SCLKG_CTRL, ~_BIT4, _BIT4);

    // DPLL VCORSTB Set to Normal
    ScalerSetBit(PB5_C0_MN_SCLKG_PLL_INSEL, ~_BIT0, _DPLL_VCORSTB_NORMAL_VALUE);

    // DPLL Power On
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT7, 0x00);

    ScalerTimerDelayXms(2);


    ////////////////////////////////
    // DPPLL VCO Band Calibration //
    ////////////////////////////////

    // Reg DPLL_CMPEN
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT2, _BIT2);

    ScalerTimerDelayXms(2);

    // Reg DPLL_CALLCH
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT3, _BIT3);

    ScalerTimerDelayXms(2);

    // Reg DPLL_CALSW
    ScalerSetBit(PB5_BD_MN_SCLKG_PLL_PWR, ~_BIT4, _BIT4);

    // VCO Band : 01 ---> KVCO = 1340
    // VCO Band : 10 ---> KVCO = 1880
    // VCO Band : 11 ---> KVCO = 2340
    // R : 13
    // Icp = 6.28 * 700 * M / KVCO / R
    // Icp   = 2.5u + D0[0] * 2.5u + D0[1] * 5u + D0[2] * 10u (A)
    // Icp = 2.5uA, 5uA, 7.5uA, 10uA......
    if(ScalerGetBit(PB5_C0_MN_SCLKG_PLL_INSEL, (_BIT5 | _BIT4)) == _BIT5)
    {
        pData[5] = 4396 * ulpllm / 1880 / 13;
    }
    else if(ScalerGetBit(PB5_C0_MN_SCLKG_PLL_INSEL, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4))
    {
        pData[5] = 4396 * ulpllm / 2340 / 13;
    }
    else
    {
        // For ICP default Setting
        pData[5] = 4396 * ulpllm / 1340 / 13;
    }

    pData[5] = ((20 * pData[5]) + 25) / 50;
    pData[5] -= (pData[5] == 0) ? 0 : 1;

    // Set PLL Charge Pump Current
    ScalerSetByte(PB5_BE_MN_SCLKG_PLL_CHP, (0x78 | (pData[5] & 0x07)));

    /*
    ////////////////////////////////
    // DPPLL M/N Tracking Setting //
    ////////////////////////////////

    // Don't Use M/N Tracking for Nvid > 0x40000 or Nvid < 0xFF

    //////////////////// Enable M/N auto tracking /////////////////////////
    // I = (2^22)*( (Tdds / Tmn) * (1 / n), n = 8
    // 1. Fdds = 1/4 * Fvco = (ulLinkClkValue / 8) * (ulpllm / ucplln) / 4 --> Tdds = (32 / ulLinkClkValue) * (plln / ulpllm)
    // 2. Tmn = Nvid * (1 / ulLinkClkValue)
    // from1,2 we can get : I = (2^27) * (ucplln / ulpllm) / Nvid / n = (2^24) * (ucplln / ulpllm) / Nvid

    ulIcodeValue = (16777216 / ulDpNvidValue) * ucplln / ulpllm;  //I = (2^24) * (ucplln / ulpllm) / Nvid

    ScalerSetBit(PB5_A8_MN_SCLKG_TRK_MN_I_H, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)(ulIcodeValue >> 16) & 0x03));
    ScalerSetByte(PB5_A9_MN_SCLKG_TRK_MN_I_M, (BYTE)(ulIcodeValue >> 8));
    ScalerSetByte(PB5_AA_MN_SCLKG_TRK_MN_I_L, (BYTE)ulIcodeValue);

    // Set P Code
    ScalerSetBit(PB5_AB_MN_SCLKG_TRK_MN_P_H, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    ScalerSetByte(PB5_AC_MN_SCLKG_TRK_MN_P_M, 0xFF);
    ScalerSetByte(PB5_AD_MN_SCLKG_TRK_MN_P_L, 0xFF);
    */

    ////////////////////////////////////////
    // DPPLL HS Tracking Tracking Setting //
    ////////////////////////////////////////

    // Disable Tracking New Mode
    ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~(_BIT2 | _BIT1), _BIT1);

    // Set Initial I/P Code
    ScalerSetByte(PB5_B1_MN_SCLKG_TRK_VS_I_M, 0x00);
    ScalerSetByte(PB5_B2_MN_SCLKG_TRK_VS_I_L, 0x04);
    ScalerSetByte(PB5_B3_MN_SCLKG_TRK_VS_P_H, 0x07);
    ScalerSetByte(PB5_B4_MN_SCLKG_TRK_VS_P_M, 0xFF);
    ScalerSetByte(PB5_B5_MN_SCLKG_TRK_VS_P_L, 0xFF);

    // Get How Many Lines per SSC Period
    pData[0] = ulStreamClkValue / usDpHtotal / 33000;

    if(pData[0] > 15)
    {
        pData[0] = 15;
    }

    // Set Tracking Freq 8 Line for 33K SSC at 4K2K60Hz
    ScalerSetBit(PB5_A8_MN_SCLKG_TRK_MN_I_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (pData[0] << 4));

    // Set Tracking Lock PE
    ScalerSetByte(PB5_B7_MN_SCLKG_TRK_VS_NLOCK, 0x7F);

    // Enable H Sync Tracking
    ScalerSetByte(PB5_A7_MN_SCLKG_TRK_CTRL, 0x58);

    // Double Buffer for H Sync Tracking
    ScalerSetBit(PB5_A0_MN_SCLKG_CTRL, ~_BIT4, _BIT4);

    // Get Frame Period
    pData[15] = 1000 / (ulStreamClkValue / usDpHtotal / usDpVtotal) + 1;

    pData[0] = 0;
    // Waiting for Stream Clk Stable
    do
    {
        // Clear PE Flag
        ScalerSetBit(PB5_B7_MN_SCLKG_TRK_VS_NLOCK, ~_BIT7, _BIT7);
        ScalerTimerDelayXms(pData[15]);

        pData[0]++;
    }
    while((ScalerGetBit(PB5_B7_MN_SCLKG_TRK_VS_NLOCK, _BIT7) == _BIT7) && (pData[0] < 10));

    // Set Final I/P Code
    ScalerSetByte(PB5_B1_MN_SCLKG_TRK_VS_I_M, 0x00);
    ScalerSetByte(PB5_B2_MN_SCLKG_TRK_VS_I_L, 0x02);

    // Start Generate Display Format
    ScalerSetBit(PB5_30_DPF_CTRL_0, ~_BIT7, _BIT7);

    // Polling Vertical BS
    ScalerTimerPollingFlagProc(50, PB6_01_DP_VBID, _BIT0, _TRUE);

    // Don't Enable HS Tracking New Mode for DE Only Mode
    if(ScalerGetBit(PB5_30_DPF_CTRL_0, (_BIT5 | _BIT4)) != _BIT4)
    {
        // Need to be Moved to FIFO Ready
        // Only Enable Tracking at Active Region when PE is Small
        PDATA_WORD(0) = ulVBs2BsCount / usDpVtotal / 2;

        ScalerSetBit(PB5_C2_HS_TRACKING_NEW_MODE1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (pData[0] & 0x0F));
        ScalerSetByte(PB5_C3_HS_TRACKING_NEW_MODE2, pData[1]);

        // Enable Tracking New Mode
        ScalerSetBit(PB5_B8_MN_SCLKG_SDM_CTRL, ~(_BIT2 | _BIT1), _BIT2);
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Video Fifo Check
// Input Value  : Fifo Check Condition
// Output Value : True --> Fifo not over/underflow
//--------------------------------------------------
bit ScalerDpRx0FifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition)
{
#if(_DP_FREESYNC_SUPPORT == _ON)
    // Temp for C Version Bug
    if((GET_FREESYNC_ENABLED() == _TRUE) && (ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE))
    {
        return _TRUE;
    }
#endif

    if(enumFifoCheckCondition == _DP_FIFO_DELAY_CHECK)
    {
        ScalerSetBit(PB5_21_PG_CTRL_1, ~(_BIT4 | _BIT2 | _BIT0), (_BIT4 | _BIT2 | _BIT0));

        ScalerTimerDelayXms(_DP_TWO_FRAME_TIME_MAX);

        pData[0] = 0;

        while(pData[0] < 6)
        {
            ScalerTimerDelayXms(10);

            if((ScalerGetBit(PB5_21_PG_CTRL_1, _BIT4) == _BIT4) || (ScalerGetBit(PB5_21_PG_CTRL_1, _BIT2) == _BIT2))
            {
                return _FALSE;
            }

            pData[0]++;
        }
    }
    else
    {
        if((ScalerGetBit(PB5_21_PG_CTRL_1, _BIT4) == _BIT4) || (ScalerGetBit(PB5_21_PG_CTRL_1, _BIT2) == _BIT2))
        {
            return _FALSE;
        }
    }

    if(ScalerGetBit(PB6_3B_DP_IRQ_CTRL1, _BIT4) == 0x00)
    {
        // Enable DP No Video Stream IRQ
        ScalerDpRx0SetNoVideoStreamIRQ(_ENABLE);
    }

    if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x02, 0x05, _BIT0) == 0x00)
    {
        // Set DP Receive Port0 In Sync
        ScalerDpRx0SinkStatusSet(_DP_SINK_REVEICE_PORT0, _DP_SINK_IN_SYNC);
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check DP Link Integrity
// Input Value  : None
// Output Value : FALSE => DP Link Integrity Fail
//--------------------------------------------------
bit ScalerDpRx0HdcpCheck(void)
{
    if(ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x0B) == 0x00)
    {
        return _TRUE;
    }

    if(((ScalerGetByte(PB_1E_HDCP_INTGT_VRF_ANS_MSB) == 0x53) || (ScalerGetByte(PB_1E_HDCP_INTGT_VRF_ANS_MSB) == 0x00)) &&
       ((ScalerGetByte(PB_1F_HDCP_INTGT_VRF_ANS_LSB) == 0x1F) || (ScalerGetByte(PB_1F_HDCP_INTGT_VRF_ANS_LSB) == 0x00)))
    {
        return _TRUE;
    }

    if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & _BIT2) == 0x00)
    {
        return _FALSE;
    }

    if(ScalerDpRx0HdcpMeasureCheck() == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check DP Hdcp ReAuth Process
// Input Value  : None
// Output Value : TRUE or FALSE
//--------------------------------------------------
bit ScalerDpRx0HdcpReAuthStatusCheck(void)
{
    if((ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x07) != 0x00) || (ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x08) != 0x00) ||
       (ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x09) != 0x00) || (ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x0A) != 0x00) ||
       (ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x0B) != 0x00))
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : DP HDCP Measure Check
// Input Value  : None
// Output Value : FALSE => Measure Check Fail
//--------------------------------------------------
bit ScalerDpRx0HdcpMeasureCheck(void)
{
    DWORD ulLinkClk = 0;
    WORD usHTotalCount = 0;

    // Pop up Main Stream Attributes
    ScalerSetBit(PB6_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT3));

    // Get Vtotal
    ScalerRead(PB6_10_MSA_VTTE_0, 2, &pData[10], _AUTOINC);

    if(PDATA_WORD(5) == 0)
    {
        return _FALSE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_FREESYNC_ENABLED() == _TRUE)
    {
        return _FALSE;
    }
#endif

    // [5] ln_ck_sel = 1'b1 -> CDR Clock
    // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

    // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Waiting for Measure Done
    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
    {
        PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
    }
    else
    {
        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
        {
            PDATA_WORD(0) = 0x4E20;
        }
        else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
        {
            PDATA_WORD(0) = 0x2710;
        }
        else // Both Default && _DP_LINK_RBR Case
        {
            PDATA_WORD(0) = 0x1770;
        }
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    PDATA_DWORD(0) = (((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ);

    // Link Clk in KHz
    ulLinkClk = (PDATA_DWORD(0) / 1000);

    DebugMessageRx0("Current Link Clk", ulLinkClk);

    // Start to Measure Vertical BS to BS Counter by GDI Clock
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB5_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The result
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    // Get Measure Result
    ScalerRead(PB5_58_MN_MEAS_CTRL, 3, &pData[1], _AUTOINC);

    // Get Measure Htotal Counts
    ScalerRead(PB5_5B_MN_MEAS_HLN_M, 2, &pData[6], _AUTOINC);

    // Disable Measure Block
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, 0x00);

    // Convert HTotal Count from 1/2 Link Clk to GDI Clk
    usHTotalCount = ((DWORD)PDATA_WORD(3) * _GDI_CLK_KHZ * 2 + (ulLinkClk >> 1)) / ulLinkClk;

    PDATA_DWORD(0) = (PDATA_DWORD(0) & 0x001FFFFF);
    PDATA_DWORD(1) = ((DWORD)usHTotalCount & 0x0000FFFF);

    PDATA_WORD(2) = PDATA_DWORD(0) / PDATA_DWORD(1);

    // 2% Tolerance
    if((ABSDWORD(PDATA_WORD(2), PDATA_WORD(5))) > (PDATA_WORD(5) * 2 / 100))
    {
        return _FALSE;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Content Protection Interrupt Request
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0CpIRQ(EnumDpRxBStatusType enumBStatusType)
{
    // Link Status CPIRQ Flag
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x01, (ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x01) | _BIT2));

    // Set B Status
    ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x29, (ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x29) | enumBStatusType));

    if((enumBStatusType == _DP_HDCP_BSTATUS_LINK_INTEGRITY_FAIL) || (enumBStatusType == _DP_HDCP_BSTATUS_REAUTH_REQ))
    {
#if(_DP_MST_SUPPORT == _ON)
        if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & _BIT0) == 0x00)
        {
            // Reset HDCP Block
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT0, _BIT0);
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT0, 0x00);
        }

        if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & _BIT1) == _BIT1)
        {
            ScalerDpRx0SetDpcdValue(0x00, 0x20, 0x05, (ScalerDpRx0GetDpcdInfo(0x00, 0x20, 0x05) | _BIT2));
        }
#else
        // Reset HDCP Block
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT0, _BIT0);
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT0, 0x00);
#endif

        SET_DP_RX0_AUX_MANUAL_MODE();

        // Clear Aksv
        ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x07, 0x00);
        ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x08, 0x00);
        ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x09, 0x00);
        ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x0A, 0x00);
        ScalerDpRx0SetDpcdValue(0x06, 0x80, 0x0B, 0x00);

        SET_DP_RX0_AUX_AUTO_MODE();
    }

    ScalerDpRx0HotPlugDuration(_DP_HPD_IRQ_TIME);
}

//--------------------------------------------------
// Description  : Check whether HDCP is enabled
// Input Value  : None
// Output Value : TRUE => HDCP Enabled
//--------------------------------------------------
bit ScalerDpRx0HdcpEnebled(void)
{
    if(ScalerGetBit(PB_20_HDCP_DEBUG, (_BIT7 | _BIT6 | _BIT5)) == (_BIT7 | _BIT6 | _BIT5))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP1 for PHY CTS
// Input Value  : FLD Reference Clock
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCtsTp1SetPhy(EnumDpNFCodeRef enumDpNFCodeRef)
{
    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////

    // [0] cmu_en = 1'b0 --> Disable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, 0x00);

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_A1_CMU_01, 0x00);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test

            ScalerSetByte(PB_A1_CMU_01, 0x01);

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            // Waiting Bias Settling
            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetByte(PB_A1_CMU_01, 0x11);

            break;

        case 0x10: // Lane1 Test

            ScalerSetByte(PB_A1_CMU_01, 0x02);

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            // Waiting Bias Settling
            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetByte(PB_A1_CMU_01, 0x22);

            break;

        case 0x20: // Lane2 Test

            ScalerSetByte(PB_A1_CMU_01, 0x04);

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            // Waiting Bias Settling
            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetByte(PB_A1_CMU_01, 0x44);

            break;

        case 0x30: // Lane3 Test

            ScalerSetByte(PB_A1_CMU_01, 0x08);

            // Enable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

            // Waiting Bias Settling
            for(pData[0] = 0; pData[0] <= 2; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            ScalerSetByte(PB_A1_CMU_01, 0x88);

            break;

        default:

            break;
    }

    // 4 Lane DP CTS
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));


    /////////////////
    // CMU Setting //
    /////////////////

    // [5] CMU_BYPASS_PI = 1'b0 --> Fractional N PLL
    // [3] CMU_CKSEL = 1'b0 --> Ref. XTAL
    ScalerSetBit(PB_A5_CMU_05, ~(_BIT5 | _BIT3), 0x00);

    // [7] BYPASS_PI = 1'b0 --> Fractional N PLL
    ScalerSetBit(PB_F1_SDM_00, ~_BIT7, 0x00);

    switch(g_ucDpRx0PhyCtsCtrl & (_BIT7 | _BIT6))
    {
        case _BIT7: // HBR2

            // [7:5] rate_sel = 3'b000 --> 5.4GHz
            ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // [7:5] SEL_DIV = 3'b000 --> 5.4GHz
            // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
            // [1:0] CMU_SELPREDIV = 2'b00 --> /1
            ScalerSetByte(PB_A3_CMU_03, 0x0C);

            // [7:4] CMU_SEL_PUMP_I = 4'b0101 --> Icp = 15uA
            // [3:1] CMU_SEL_RI = 3'b010 --> Rs = 10KOhm
            // [0] CMU_SEL_CP = 1'b1 --> Cp = 2pF
            ScalerSetByte(PB_A4_CMU_04, 0x55);

            ScalerDpRx0CMUNFCodeSetting(enumDpNFCodeRef, _DP_LINK_HBR2);

            break;

        case _BIT6: // HBR

            // [7:5] rate_sel = 3'b001 --> 2.7GHz
            ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            // [7:5] SEL_DIV = 3'b001 --> 2.7GHz
            // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
            // [1:0] CMU_SELPREDIV = 2'b00 --> /1
            ScalerSetByte(PB_A3_CMU_03, 0x2C);

            // [7:4] CMU_SEL_PUMP_I = 4'b0101 --> Icp = 15uA
            // [3:1] CMU_SEL_RI = 3'b011 --> Rs = 12KOhm
            // [0] CMU_SEL_CP = 1'b1 --> Cp = 2pF
            ScalerSetByte(PB_A4_CMU_04, 0x57);

            ScalerDpRx0CMUNFCodeSetting(enumDpNFCodeRef, _DP_LINK_HBR);

            break;

        case 0x00: // RBR
        default:

            // [7:5] rate_sel = 3'b001 --> 1.62GHz
            ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), _BIT5);

            // [7:5] SEL_DIV = 3'b001 --> 1.62GHz
            // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
            // [1:0] CMU_SELPREDIV = 2'b00 --> /1
            ScalerSetByte(PB_A3_CMU_03, 0x2C);

            // [7:4] CMU_SEL_PUMP_I = 4'b0101 --> Icp = 15uA
            // [3:1] CMU_SEL_RI = 3'b011 --> Rs = 12KOhm
            // [0] CMU_SEL_CP = 1'b1 --> Cp = 2pF
            ScalerSetByte(PB_A4_CMU_04, 0x57);

            ScalerDpRx0CMUNFCodeSetting(enumDpNFCodeRef, _DP_LINK_RBR);

            break;
    }


    /////////////////
    // CDR Setting //
    /////////////////

    // KI = 3'b011 --> KI = 1/4
    ScalerSetByte(PB_D4_KI_0, 0x6C);
    ScalerSetByte(PB_D5_KI_1, 0x6C);

    // [3:0] KD = 4'b0000 --> KD = 0
    ScalerSetBit(PB_CC_ERROR_COUNT_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    switch(g_ucDpRx0PhyCtsCtrl & (_BIT7 | _BIT6))
    {
        case 0x00: // RBR

            // KP = 0x37 --> KP = 13.75
            ScalerSetByte(PB_D6_KP_0, 0x37);
            ScalerSetByte(PB_D7_KP_1, 0x37);
            ScalerSetByte(PB_D8_KP_2, 0x37);
            ScalerSetByte(PB_D9_KP_3, 0x37);

            break;

        case _BIT7: // HBR2

            // KP = 0x08 --> KP = 2
            ScalerSetByte(PB_D6_KP_0, 0x08);
            ScalerSetByte(PB_D7_KP_1, 0x08);
            ScalerSetByte(PB_D8_KP_2, 0x08);
            ScalerSetByte(PB_D9_KP_3, 0x08);

            break;

        default:
        case _BIT6: // HBR

            // KP = 0x1F --> KP = 7.75
            ScalerSetByte(PB_D6_KP_0, 0x1F);
            ScalerSetByte(PB_D7_KP_1, 0x1F);
            ScalerSetByte(PB_D8_KP_2, 0x1F);
            ScalerSetByte(PB_D9_KP_3, 0x1F);

            break;
    }


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // Disable Comma Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, _BIT4);

    // Disable De-Scrambling
    ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

    // Enable Enhancement Control Mode --> MAC
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);

    // [7] reg_en_ana_cdr = 1'b0 --> Disable Analog CDR
    ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~_BIT7, 0x00);

    // [0] reg_acdr_l0_en = 1'b0 --> Disable Lane0 ACDR
    ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~_BIT0, 0x00);

    // Disable Hybrid Mode
    ScalerSetBit(PB_AF_CDR_06, ~_BIT0, 0x00);

    // [1] bypass_clk_rdy = 1 --> Manual Mode
    // [0] en_clkout_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F5_WD_01, ~(_BIT5 | _BIT4), _BIT5);

    // [1] bypass_eqen_rdy = 1 --> Manual Mode
    // [0] en_eqen_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F6_EQEN_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [1] bypass_data_rdy = 1 --> Manual Mode
    // [0] en_data_manual = 0 --> Disable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [3:0] RST_N = 4'b0000 --> Digital Circuit Reset
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [3:0] RST_N = 4'b1111 --> Digital Circuit Normal
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));


    /////////////////
    // DFE Setting //
    /////////////////

    switch(g_ucDpRx0PhyCtsCtrl & (_BIT7 | _BIT6))
    {
        case _BIT7: // HBR2

            // Set DFE Initial
            ScalerDpRx0SetDFEInitial(_DP_LINK_HBR2);

            // LE Max = 24, Initial = 18, Servo Initial = 16
            ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x82);
            ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x82);
            ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x82);
            ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x82);
            ScalerSetByte(P1D_A3_L0_INIT_1, 0xD0);
            ScalerSetByte(P1D_B3_L1_INIT_1, 0xD0);
            ScalerSetByte(P1D_C3_L2_INIT_1, 0xD0);
            ScalerSetByte(P1D_D3_L3_INIT_1, 0xD0);

            ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

            // [7:5] LE_ISEL = 3'b011
            // [4:2] LE_RLSEL = 3'b000
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT5));

            // [7:5] LE_lowgain_highboost = 3'b000 --> LE LowBoost Mode
            ScalerSetBit(PB_A8_CMU_08, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

            // Enable SumAmp Bias
            ScalerSetBit(PB_A6_CMU_06, ~_BIT5, _BIT5);

            break;

        case _BIT6: // HBR

            // Set DFE Initial
            ScalerDpRx0SetDFEInitial(_DP_LINK_HBR);

            // [7:5] LE_ISEL = 3'b010
            // [4:2] LE_RLSEL = 3'b001
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT2));

            // [7:5] LE_lowgain_highboost = 3'b100 --> LE HighBoost Mode
            ScalerSetBit(PB_A8_CMU_08, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);

            // Disable SumAmp Bias
            ScalerSetBit(PB_A6_CMU_06, ~_BIT5, 0x00);

            break;

        case 0x00: // RBR
        default:

            // Set DFE Initial
            ScalerDpRx0SetDFEInitial(_DP_LINK_RBR);

            // [7:5] LE_ISEL = 3'b000
            // [4:2] LE_RLSEL = 3'b011
            ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

            // [7:5] LE_lowgain_highboost = 3'b100 --> LE HighBoost Mode
            ScalerSetBit(PB_A8_CMU_08, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);

            // Disable SumAmp Bias
            ScalerSetBit(PB_A6_CMU_06, ~_BIT5, 0x00);

            break;
    }


    //////////////
    // K Offset //
    //////////////

    // Enable Sumamp High Gain Mode
    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

    // Fix Tap0 = 21
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x15);
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x01);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x01);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x01);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // [2] Enable Foreground Calibration Auto Mode
    ScalerSetBit(PB_AD_CDR_04, ~_BIT2, _BIT2);

    // [5] Toggle Foreground Calibration
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, _BIT5);
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, _BIT5);

    // Waiting for K Offset
    for(pData[0] = 0; pData[0] <= 6; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }


    /////////////////////
    // Adaptation Loop //
    /////////////////////

    // Reset Digital CDR
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

    // Disable Tap1~6
    ScalerSetBit(PB_B2_EQ_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), 0x00);

    // Disable Adaptation
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

    // [7] cmu_en = 1'b1 --> Enable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, _BIT7);

    // Waiting for CMU PLL Stable
    for(pData[0] = 0; pData[0] <= 4; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // [0] en_clkout_manual = 1 --> Enable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

    // [0] en_data_manual = 1 --> Enable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~_BIT0, _BIT0);

    // DP Mac Clock Select to Link Clock
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, 0x00);
}

//--------------------------------------------------
// Description  : DP PHY CTS Lane0 ACDR
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCtsACDR(void)
{
    BYTE ucBestVCOBand = 0;
    WORD usVCOBandDiff = 0xFFFF;
    BYTE ucTemp = 0;


    ///////////////////////////
    // RX CMU EN & Mac Power //
    ///////////////////////////

    // [7] cmu_en = 1'b0 --> Disable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, 0x00);

    // Disable RX_EN, CDR_EN
    ScalerSetByte(PB_A1_CMU_01, 0x00);

    // Enable Lane0 RX_EN
    ScalerSetBit(PB_A1_CMU_01, ~_BIT4, _BIT4);

    // Enable Local Bias LPF
    ScalerSetBit(PB_A7_CMU_07, ~_BIT5, _BIT5);

    for(pData[0] = 0; pData[0] <= 2; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Enable Lane0 CDR_EN
    ScalerSetBit(PB_A1_CMU_01, ~_BIT0, _BIT0);

    // One Lane Test
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~(_BIT4 | _BIT3), _BIT3);


    /////////////////
    // CMU Setting //
    /////////////////

    // [7:5] rate_sel = 3'b000 --> 5.4GHz
    ScalerSetBit(PB_DB_ST_0, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // [7:5] SEL_DIV = 3'b000 --> 5.4GHz
    // [4:2] CMU_PI_I_SEL = 3'b011 --> 12.5uA
    // [1:0] CMU_SELPREDIV = 2'b00 --> /1
    ScalerSetByte(PB_A3_CMU_03, 0x0C);

    // [7:4] CMU_SEL_PUMP_I = 4'b0011 --> Icp = 10uA
    // [3:1] CMU_SEL_RI = 3'b010 --> Rs = 10KOhm
    // [0] CMU_SEL_CP = 1'b1 --> Cp = 2pF
    ScalerSetByte(PB_A4_CMU_04, 0x35);

    // [5] CMU_BYPASS_PI = 1'b1 --> Integer N PLL
    ScalerSetBit(PB_A5_CMU_05, ~_BIT5, _BIT5);

    // [7] BYPASS_PI = 1'b1 --> Use Integer N Code
    ScalerSetBit(PB_F1_SDM_00, ~_BIT7, _BIT7);

    // Digital CDR Ref Clock = Analog CDR / 10
    ScalerSetBit(PB_AE_CDR_05, ~_BIT0, 0x00);
    ScalerSetBit(PB_AF_CDR_06, ~_BIT1, 0x00);

    // [7:0] N_CODE = 8'b0001 0000 --> 6 + 4 = 10
    ScalerSetByte(PB_F2_SDM_01, 0x06);


    /////////////////////
    // A/D CDR Setting //
    /////////////////////

    // KD = 4'b0000 --> KD = 0
    ScalerSetBit(PB_CC_ERROR_COUNT_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // KI = 3'b000 --> KI = 0
    ScalerSetByte(PB_D4_KI_0, 0x00);
    ScalerSetByte(PB_D5_KI_1, 0x00);

    // KP = 0x0B --> KP = 2.25
    ScalerSetByte(PB_D6_KP_0, 0x09);
    ScalerSetByte(PB_D7_KP_1, 0x09);
    ScalerSetByte(PB_D8_KP_2, 0x09);
    ScalerSetByte(PB_D9_KP_3, 0x09);

    // [5:4] reg_cdr_kvco = 2'b01 --> Analog CDR KVCO = 550M/v
    ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~(_BIT5 | _BIT4), _BIT4);

    // [4:2] reg_sel_cdr_res = 3'b011 --> Analog CDR Rs = 4K
    ScalerSetBit(PB_FD_LANE0_A_CDR_07, ~(_BIT4 | _BIT3 | _BIT2), (_BIT3 | _BIT2));

    // [3:0] reg_cdr_cp_in = 4'b0011 --> Analog CDR Icp = 10.5uA
    ScalerSetBit(PB_FE_LANE0_A_CDR_08, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));


    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // Enable Comma Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, 0x00);

    // Enable Enhancement Control Mode --> MAC
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);

    // Disable De-Scrambling
    ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

    // [0] en_clkout_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, 0x00);

    // [0] en_eqen_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

    // [0] en_data_manual = 0 --> Disable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~_BIT0, 0x00);

    // Disable Hybrid Mode
    ScalerSetBit(PB_AF_CDR_06, ~_BIT0, 0x00);

    // [3:0] RST_N = 4'b0000 --> Digital Circuit Reset
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [3:0] RST_N = 4'b1111 --> Digital Circuit Normal
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));


    /////////////////
    // DFE Setting //
    /////////////////

    // Set DFE Initial
    ScalerDpRx0SetDFEInitial(_DP_LINK_HBR2);

    // [0] Tap2~6 Adaptation Revise
    ScalerSetBit(PB_B2_EQ_00, ~_BIT0, 0x00);

    // LE Max = 20, Initial = 16, Servo Initial = 16
    ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x40);
    ScalerSetByte(P1D_A3_L0_INIT_1, 0xD0);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

    // [7:5] LE_ISEL = 3'b011
    // [4:2] LE_RLSEL = 3'b000
    ScalerSetBit(PB_A9_CMU_09, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT6 | _BIT5));

    // [7:5] LE_lowgain_highboost = 3'b000 --> LE LowBoost Mode
    ScalerSetBit(PB_A8_CMU_08, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

    // Enable SumAmp Bias
    ScalerSetBit(PB_A6_CMU_06, ~_BIT5, _BIT5);


    //////////////
    // K Offset //
    //////////////

    // Enable Sumamp High Gain Mode
    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

    // Fix Tap0 = 21
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

    // [2] Enable Foreground Calibration Auto Mode
    ScalerSetBit(PB_AD_CDR_04, ~_BIT2, _BIT2);

    // [5] Toggle Foreground Calibration
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, _BIT5);
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);
    ScalerSetBit(PB_AA_CDR_01, ~_BIT5, _BIT5);

    // Waiting for K Offset
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }


    ///////////////////
    // FLD Lock Band //
    ///////////////////

    // Disable Sumamp High Gain Mode
    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

    // [7] cmu_en = 1'b1 --> Enable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, _BIT7);

    // Enable Tap1~4
    ScalerSetBit(PB_B2_EQ_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

    // [4] reg_en_data_manual_l0 = 1'b0
    // [3] reg_bypass_data_rdy_l0 = 1'b0
    ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~(_BIT4 | _BIT3), 0x00);

    // [0] en_clkout_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, 0x00);

    // [5] reg_adp_eq_off = 1'b0 --> Enable Analog CDR DFE Adaptation
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT5, 0x00);

    // [4] reg_auto_mode = 1'b1 --> FLD Select Auto Mode
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT4, _BIT4);

    // [0] reg_acdr_l0_en = 1'b1 --> Enable Lane0 ACDR
    ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~_BIT0, _BIT0);

    // [6] reg_xtal_en = 1'b1 --> Using Xtal
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT6, _BIT6);

    // Analog CDR Auto FLD Counter
    ScalerSetByte(PB_FA_LANE0_A_CDR_04, 0xF9);
    ScalerSetByte(PB_FB_LANE0_A_CDR_05, 0x0C);
    ScalerSetByte(PB_FC_LANE0_A_CDR_06, 0x85);

    // [0] en_clkout_manual = 1'b1 --> Enable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

    // [7] reg_en_ana_cdr = 1'b1 --> Enable Analog CDR
    // [6] reg_en_vco_lpf = 1'b0 --> Disable Analog CDR Multi Band VCO's LPF
    // [3] reg_cp_adj_en = 1'b1 --> Enable Adjust Icp When Tracking
    // [2] reg_enhance_bias_boost = 1'b0 --> Disable Enhance LEQ Boost Bias
    // [1] reg_enhance_bias_gain = 1'b0 --> Disable Enhance LEQ Gain Bias
    // [0] reg_rstb_fsm --> Toggle for FLD reset
    ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~(_BIT7 | _BIT6 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT3));
    ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~_BIT0, _BIT0);

    // Waiting for FLD Lock Band
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // [3] reg_cp_en_manual = 1'b0 -->  Disable cp_en_manual
    // [2] reg_adp_en_manual = 1'b0 --> Disable adp_en_manual
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~(_BIT3 | _BIT2), 0x00);

    // [4] reg_auto_mode = 1'b0 --> FLD Manual Mode
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT4, 0x00);

    // [0] en_clkout_manual = 1'b1 --> Enable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

    // [2] reg_adp_en_manual = 1'b1 --> Enable adp_en_manual
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT2, _BIT2);

    ucBestVCOBand = ScalerGetByte(PB_BF_LANE0_A_CDR_02);

    g_usDpRx0ClockCount = 0x2710; // ideal 5.4G

    for(ucTemp = 0; ucTemp <= 5; ucTemp++)
    {
        // Manually Reload FLD Band
        ScalerSetByte(PB_BE_LANE0_A_CDR_01, (ScalerGetByte(PB_BF_LANE0_A_CDR_02) - 2 + ucTemp));

        // Waiting for VCO Stable
        for(pData[0] = 0; pData[0] <= 2; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        // [5] ln_ck_sel = 1'b1 -> CDR Clock
        // [3:0] DP_XTAL_CYCLE = 4'b0011 -> XTAL Counter Cycles = 1000
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT1 | _BIT0));

        // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
        ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), 0x00);

        // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
        ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

        // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

        // Waiting for Measure Done -> 50us
        for(pData[0] = 0; pData[0] <= 10; pData[0]++)
        {
            Delay5us(g_ucDelay5usN);
        }

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            g_usDpRx0ClockCount1 = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
        }
        else
        {
            ucBestVCOBand = ScalerGetByte(PB_BF_LANE0_A_CDR_02);
            continue;
        }

        // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

        if((abs(g_usDpRx0ClockCount1 - g_usDpRx0ClockCount) < usVCOBandDiff) && (g_usDpRx0ClockCount1 >= g_usDpRx0ClockCount))
        {
            usVCOBandDiff = abs(g_usDpRx0ClockCount1 - g_usDpRx0ClockCount);
            ucBestVCOBand = (ScalerGetByte(PB_BF_LANE0_A_CDR_02) - 2 + ucTemp);
        }
    }

    // Manually Reload FLD Band
    ScalerSetByte(PB_BE_LANE0_A_CDR_01, ucBestVCOBand);

    // Waiting for VCO Stable
    for(pData[0] = 0; pData[0] <= 2; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // [3] reg_cp_en_manual = 1'b1 -->  Enaable cp_en_manual
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT3, _BIT3);


    /////////////////////
    // Adaptation Loop //
    /////////////////////

    // Enable Tap0 Adaptation
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x41);

    // Waiting for DFE Adaptation
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Start to Record Tap0 Max/Min
    ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

    // Waiting for DFE Adaptation
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Stop To Record Tap0 Max/Min
    ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

    // Disable Vth/Tap0 Adaptation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);

    // Read Back Lane0
    ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);

    // Read Back Tap0 Max
    ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

    g_pucDpRx0Tap0MaxTemp[0] = ScalerGetByte(P1D_F3_COEF_4);

    // Reload Max Value of Tap0 (Lane0)
    ScalerSetByte(P1D_A4_L0_INIT_2, g_pucDpRx0Tap0MaxTemp[0]);

    // Reload Tap0
    ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT0, _BIT0);
    ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT0, 0x00);

    // Read Back Vth
    ScalerSetByte(P1D_F0_COEF_1, 0x00);

    // Reload Vth - 1 (Lane0)
    ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetByte(P1D_A9_L0_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) - 1);

    // Reload Vth
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x40);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

    // Enable LE Adaptation
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x80);

    // Waiting for DFE Adaptation
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Start to Record LE Max/Min
    ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

    // Waiting for DFE Adaptation
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Stop To Record LE Max/Min
    ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

    // Disable Adaptation
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);

    // Read Back Lane0
    ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);

    // Read Back LE Min
    ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT1));

    g_pucDpRx0LEMinTemp[0] = ScalerGetByte(P1D_F3_COEF_4);

    // Reload LE to Min
    ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMinTemp[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
    ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[0] << 2) & _BIT6));

    // Reload LE
    ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT7, _BIT7);
    ScalerSetBit(P1D_AA_L0_INIT_8, ~_BIT7, 0x00);

    // Read Back Vth
    ScalerSetByte(P1D_F0_COEF_1, 0x00);

    // Reload Vth + 1 (Lane0)
    ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
    ScalerSetByte(P1D_A9_L0_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) + 1);

    // Reload Vth
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x40);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

    // Enable Tap0~4 Adaptation for HBR2 0x01F
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x1F);

    // [0] en_eqen_manual = 1 --> Enable Adapation
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

    // Waiting for Adaptation
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Disable Adaptation
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

    // Disable Adaptation   0x000
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);


    ////////////////
    // SetPHY End //
    ////////////////

    // Enable Sumamp High Gain Mode
    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

    // Reload Tap0 to 21.5
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

    // Reset Digital CDR
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

    // [5] reg_adp_eq_off = 1'b1 --> Disable Adaptation for Analog CDR
    ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~_BIT5, _BIT5);

    // [4] reg_en_data_manual_l0 = 1'b1
    // [3] reg_bypass_data_rdy_l0 = 1'b1
    ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

    // DP Mac Clock Select to Link Clock
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, 0x00);
}

//--------------------------------------------------
// Description  : DP Phy Setting in TP2 for PHY CTS
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCtsTp2SetPhy(void)
{
    /////////////////////
    // Rx Misc Setting //
    /////////////////////

    // Enable Commoa Detection
    ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, 0x00);

    // Disable De-Scrambling
    ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

    // Enable Enhancement Control Mode --> MAC
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT2, _BIT2);

    // [0] cmu_en = 1'b0 --> Disable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, 0x00);

    // [1] bypass_clk_rdy = 1 --> Manual Mode
    // [0] en_clkout_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F5_WD_01, ~(_BIT5 | _BIT4), _BIT5);

    // [1] bypass_eqen_rdy = 1 --> Manual Mode
    // [0] en_eqen_manual = 0 --> Disable Clkout
    ScalerSetBit(PB_F6_EQEN_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [1] bypass_data_rdy = 1 --> Manual Mode
    // [0] en_data_manual = 0 --> Disable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~(_BIT1 | _BIT0), _BIT1);

    // [7] reg_en_ana_cdr = 1'b0 --> Disable Analog CDR
    ScalerSetBit(PB_B9_LANE0_A_CDR_00, ~_BIT7, 0x00);

    // [0] reg_acdr_l0_en = 1'b0 --> Disable Lane0 ACDR
    ScalerSetBit(PB_FF_LANE0_A_CDR_09, ~_BIT0, 0x00);

    // Disable Hybrid Mode
    ScalerSetBit(PB_AF_CDR_06, ~_BIT0, 0x00);

    // [3:0] RST_N = 4'b0000 --> Digital Circuit Reset
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);

    // [3:0] RST_N = 4'b1111 --> Digital Circuit Normal
    ScalerSetBit(PB_DA_PI_0, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));


    /////////////////
    // DFE Setting //
    /////////////////

    switch(g_ucDpRx0PhyCtsCtrl & (_BIT7 | _BIT6))
    {
        case _BIT7: // HBR2

            // Set DFE Initial
            ScalerDpRx0SetDFEInitial(_DP_LINK_HBR2);

            // TPS3 Pattern is Uesed as Training Pattern 2 in HBR2
            if((g_ucDpRx0PhyCtsCtrl & 0x07) == 0x02)
            {
                // Tap Divider = 34 for TPS3 Patterns
                ScalerSetByte(P1D_ED_LOOP_DIV_2, 0xE2);
            }
            else
            {
                // Tap Divider = 10 for Other Patterns
                ScalerSetByte(P1D_ED_LOOP_DIV_2, 0xCA);
            }

            // LE Max = 20, Initial = 16, Servo Initial = 16
            ScalerSetByte(P1D_A2_L0_LIMIT_INIT, 0x40);
            ScalerSetByte(P1D_B2_L1_LIMIT_INIT, 0x40);
            ScalerSetByte(P1D_C2_L2_LIMIT_INIT, 0x40);
            ScalerSetByte(P1D_D2_L3_LIMIT_INIT, 0x40);
            ScalerSetByte(P1D_A3_L0_INIT_1, 0xD0);
            ScalerSetByte(P1D_B3_L1_INIT_1, 0xD0);
            ScalerSetByte(P1D_C3_L2_INIT_1, 0xD0);
            ScalerSetByte(P1D_D3_L3_INIT_1, 0xD0);

            ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

            // [0] Tap2~6 Adaptation Revise
            ScalerSetBit(PB_B2_EQ_00, ~_BIT0, 0x00);

            break;

        case _BIT6: // HBR

            // Set DFE Initial
            ScalerDpRx0SetDFEInitial(_DP_LINK_HBR);

            break;

        case 0x00: // RBR
        default:

            // Set DFE Initial
            ScalerDpRx0SetDFEInitial(_DP_LINK_RBR);

            break;
    }

    // Disable Sumamp High Gain Mode
    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

    // Enable Tap1~4
    ScalerSetBit(PB_B2_EQ_00, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

    // Reset Digital CDR
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);


    /////////////////////
    // Adaptation Loop //
    /////////////////////

    // Enable Vth, Tap0 Adaptation   0x041
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x41);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x41);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x41);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x41);

    // [7] cmu_en = 1'b1 --> Enable CMU PLL
    ScalerSetBit(PB_A7_CMU_07, ~_BIT7, _BIT7);

    // Waiting for CMU PLL Stable
    for(pData[0] = 0; pData[0] <= 10; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // [0] en_clkout_manual = 1 --> Enable Clkout
    ScalerSetBit(PB_F5_WD_01, ~_BIT4, _BIT4);

    // [0] en_eqen_manual = 1 --> Enable Adapation
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

    // Waiting for Adaptation
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    if((g_ucDpRx0PhyCtsCtrl & 0x80) == 0x80)
    {
        if((g_ucDpRx0PhyCtsCtrl & 0x07) == 0x02)  // TPS3 Pattern
        {
            // Disable Adaptation
            ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

            // Disable Adaptation for HBR2 TPS3 Pattern
            ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
            ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
            ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
            ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

            // Reload LE = 16
            ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, _BIT6);
            ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, _BIT6);
            ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, _BIT6);
            ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, _BIT6);

            // Reload LE
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);
        }
        else
        {
            // Start to Record Tap0 Max/Min
            ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

            // Waiting for Adaptation
            for(pData[0] = 0; pData[0] <= 20; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            // Stop To Record Tap0 Max/Min
            ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

            // Disable Adaptation
            ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

            // Read Back Tap0 Max
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x00);

            // Reload Max Value of Tap0 (Lane0)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetByte(P1D_A4_L0_INIT_2, ScalerGetByte(P1D_F3_COEF_4));

            // Reload Max Value of Tap0 (Lane1)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetByte(P1D_B4_L1_INIT_2, ScalerGetByte(P1D_F3_COEF_4));

            // Reload Max Value of Tap0 (Lane2)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetByte(P1D_C4_L2_INIT_2, ScalerGetByte(P1D_F3_COEF_4));

            // Reload Max Value of Tap0 (Lane3)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetByte(P1D_D4_L3_INIT_2, ScalerGetByte(P1D_F3_COEF_4));

            // Reload Tap0
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x01);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x01);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x01);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

            // Read Back Vth
            ScalerSetByte(P1D_F0_COEF_1, 0x00);

            // Reload Vth - 1 (Lane0)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetByte(P1D_A9_L0_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) - 1);

            // Reload Vth - 1 (Lane1)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetByte(P1D_B9_L1_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) - 1);

            // Reload Vth - 1 (Lane2)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetByte(P1D_C9_L2_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) - 1);

            // Reload Vth - 1 (Lane3)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetByte(P1D_D9_L3_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) - 1);

            // Reload Vth
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x40);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x40);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x40);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x40);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

            // Enable LE Adaptation   0x080
            ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x80);
            ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x80);
            ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x80);
            ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x80);

            // [0] en_eqen_manual = 1 --> Enable Adapation
            ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

            // Waiting for Adaptation
            for(pData[0] = 0; pData[0] <= 20; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            // Start to Record LE Max/Min
            ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, _BIT0);

            // Waiting for Adaptation
            for(pData[0] = 0; pData[0] <= 20; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            // Stop To Record LE Max/Min
            ScalerSetBit(P1D_F2_COEF_3, ~_BIT0, 0x00);

            // Disable Adaptation
            ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

            // Read Back LE Min
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT3 | _BIT1));

            // Reload Min Value of LE (Lane0)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ScalerGetByte(P1D_F3_COEF_4) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((ScalerGetByte(P1D_F3_COEF_4) << 2) & _BIT6));

            // Reload Min Value of LE (Lane1)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ScalerGetByte(P1D_F3_COEF_4) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, ((ScalerGetByte(P1D_F3_COEF_4) << 2) & _BIT6));

            // Reload Min Value of LE (Lane2)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ScalerGetByte(P1D_F3_COEF_4) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, ((ScalerGetByte(P1D_F3_COEF_4) << 2) & _BIT6));

            // Reload Min Value of LE (Lane3)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (ScalerGetByte(P1D_F3_COEF_4) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
            ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, ((ScalerGetByte(P1D_F3_COEF_4) << 2) & _BIT6));

            // Reload LE
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

            // Read Back Vth
            ScalerSetByte(P1D_F0_COEF_1, 0x00);

            // Reload Vth + 1 (Lane0)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetByte(P1D_A9_L0_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) + 1);

            // Reload Vth + 1 (Lane1)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
            ScalerSetByte(P1D_B9_L1_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) + 1);

            // Reload Vth + 1 (Lane2)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
            ScalerSetByte(P1D_C9_L2_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) + 1);

            // Reload Vth + 1 (Lane3)
            ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            ScalerSetByte(P1D_D9_L3_INIT_7, (ScalerGetByte(P1D_F1_COEF_2) & 0x0F) + 1);

            // Reload Vth
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x40);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x40);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x40);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x40);
            ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
            ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
            ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
            ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

            // Enable Tap0~4 Adaptation for HBR2 0x01F
            ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
            ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x1F);
            ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x1F);
            ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x1F);
            ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x1F);
        }
    }
    else
    {
        // Disable Adaptation
        ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

        // Enable LE, Tap1~4 Adaptation for RBR/HBR 0x09E
        ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x9E);
        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x9E);
        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x9E);
        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x9E);
    }

    // [0] en_eqen_manual = 1 --> Enable Adapation
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

    // Waiting for Adaptation
    for(pData[0] = 0; pData[0] <= 20; pData[0]++)
    {
        Delay5us(g_ucDelay5usN);
    }

    // Disable Adaptation
    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

    // Disable Adaptation   0x000
    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);


    ////////////////
    // SetPHY End //
    ////////////////

    // Enable Sumamp High Gain Mode
    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

    // Reload Tap0 to 21.5
    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
    ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
    ScalerSetByte(P1D_C4_L2_INIT_2, 0x15);
    ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x01);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x01);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x01);

    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

    // Reset Digital CDR
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);
    ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

    // [0] en_data_manual = 1 --> Enable Dataout
    ScalerSetBit(PB_F7_DATA_TIMER, ~_BIT0, _BIT0);
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 1 for PHY CTS
// Input Value  : None
// Output Value : TRUE --> TP1 Pass
//--------------------------------------------------
bit ScalerDpRx0PhyCtsTp1Check(void)
{
    // Wait for 10ms
    ScalerTimerDelayXms(10);

    // Clear 8B/10B Decode Error Flags
    ScalerSetBit(PB_06_DECODE_10B8B_ERROR, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT2 | _BIT1 | _BIT0));

    // Wait for 2ms
    ScalerTimerDelayXms(2);

    ScalerSetByte(PB7_A1_AUX_RESERVE1, ScalerGetByte(PB_06_DECODE_10B8B_ERROR));
    ScalerSetByte(PB7_A2_AUX_RESERVE2, ScalerGetByte(PB_14_EQ_CRC_3));
    ScalerSetByte(PB7_A3_AUX_RESERVE3, g_ucDpRx0PhyCtsCtrl & 0x30);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test

            // EQ auto K,Check lane0 CRC
            pData[0] = 0x10;

            break;

        case 0x10: // Lane1 Test

            // EQ auto K,Check lane1 CRC
            pData[0] = 0x20;

            break;

        case 0x20: // Lane2 Test

            // EQ auto K,Check lane2 CRC
            pData[0] = 0x40;

            break;

        case 0x30: // Lane3 Test

            // EQ auto K,Check lane3 CRC
            pData[0] = 0x80;

            break;

        default:

            pData[0] = 0x00;

            break;
    }

    if(((ScalerGetByte(PB7_A1_AUX_RESERVE1) & 0x0F) == 0x00) &&
       ((ScalerGetByte(PB7_A2_AUX_RESERVE2) & pData[0]) != 0x00))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Dp Training Pattern 2 for PHY CTS
// Input Value  : None
// Output Value : TRUE --> TP2 Pass
//--------------------------------------------------
bit ScalerDpRx0PhyCtsTp2Check(void)
{
    ScalerTimerDelayXms(10);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test

            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), 0x00);

            break;

        case 0x10: // Lane1 Test

            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _BIT3);

            break;

        case 0x20: // Lane2 Test

            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _BIT4);

            break;

        case 0x30: // Lane3 Test

            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

            break;

        default:
            break;
    }

    // Mac Use Xtal Clk
    ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT6, _BIT6);

    // Clear EQ-CRC
    ScalerSetBit(PB_12_EQ_CRC_1, ~(_BIT7 | _BIT6), _BIT6);

    // Start Calculate EQ-CRC
    ScalerSetBit(PB_12_EQ_CRC_1, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    ScalerTimerDelayXms(2);

    ScalerSetByte(PB7_A1_AUX_RESERVE1, ScalerGetByte(PB_12_EQ_CRC_1));
    ScalerSetByte(PB7_A2_AUX_RESERVE2, ScalerGetByte(PB_13_EQ_CRC_2));
    ScalerSetByte(PB7_A3_AUX_RESERVE3, g_ucDpRx0PhyCtsCtrl & 0x30);

    // Stop Calculate EQ-CRC
    ScalerSetBit(PB_12_EQ_CRC_1, ~(_BIT7 | _BIT6), _BIT6);

    switch(g_ucDpRx0PhyCtsCtrl & 0x30)
    {
        case 0x00: // Lane0 Test

            pData[0] = 0x01;

            break;

        case 0x10: // Lane1 Test

            pData[0] = 0x02;

            break;

        case 0x20: // Lane2 Test

            pData[0] = 0x04;

            break;

        case 0x30: // Lane3 Test

            pData[0] = 0x08;

            break;

        default:

            pData[0] = 0x00;

            break;
    }

    if((ScalerGetByte(PB7_A1_AUX_RESERVE1) & pData[0]) != 0x00)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP PHY CTS Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0PhyCTS(void)
{
    WORD usTemp = 0;

    // _ERROR_PRONE_CODE
    // g_ucDpRx0PhyCtsCtrl(Page0x0B A7[0] = 0 --> PHY CTS Enable Start
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[2:0]) = 0x01 --> CDR
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[2:0]) = 0x02 --> EQ CRC
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[2:0]) = 0x03 --> PRBS7 Error Counter Reset and Counter Start
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[2:0]) = 0x04 --> PRBS7 Error Counter Read
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[2:0]) = 0x05 --> PHY CTS Disable
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[5:4]) = 00 --> lane0
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[5:4]) = 01 --> lane1
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[5:4]) = 10 --> lane2
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[5:4]) = 11 --> lane3
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[7:6]) = 00 --> RBR
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[7:6]) = 01 --> HBR
    // g_ucDpRx0PhyCtsCtrl(Page0xB7 A5[7:6]) = 10 --> HBR2
    g_ucDpRx0PhyCtsCtrl = 0x00;

    EX0 = 0;

    while(GET_DP_RX0_PHY_CTS_FLG() == _TRUE)
    {
        ScalerDebug();

        ScalerRead(PB7_A5_AUX_RESERVE5, 1, &g_ucDpRx0PhyCtsCtrl, _NON_AUTOINC);

        DebugMessageRx0("7. PHY CTS Loop", g_ucDpRx0PhyCtsCtrl);

        switch(g_ucDpRx0PhyCtsCtrl & 0x07)
        {
            case 0x01: // CDR Lock Check

                ScalerSetByte(PB7_A5_AUX_RESERVE5, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0))); // Clear DP PHY CTS Phase Info

                g_ucDpRx0Temp = 50;

                while(g_ucDpRx0Temp > 0)
                {
                    if((g_ucDpRx0PhyCtsCtrl & 0xB0) == 0x80)   // Only for lane0 HBR2
                    {
                        ScalerDpRx0PhyCtsACDR();
                    }
                    else
                    {
                        ScalerDpRx0PhyCtsTp1SetPhy(_DP_NF_REF_XTAL);
                    }

                    if(ScalerDpRx0PhyCtsTp1Check() == _TRUE)
                    {
                        ScalerSetByte(PB7_A4_AUX_RESERVE4, 0x01);
                        g_ucDpRx0Temp = 0;
                    }
                    else
                    {
                        ScalerSetByte(PB7_A4_AUX_RESERVE4, 0xFF);
                        g_ucDpRx0Temp--;
                    }
                }

                break;

            case 0x02: // Symbol Lock Check

                ScalerSetByte(PB7_A5_AUX_RESERVE5, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0)));

                g_ucDpRx0Temp = 50;

                while(g_ucDpRx0Temp > 0)
                {
                    if((g_ucDpRx0PhyCtsCtrl & 0xB0) == 0x80)   // Only for lane0 HBR2
                    {
                        ScalerDpRx0PhyCtsACDR();
                    }
                    else
                    {
                        ScalerDpRx0PhyCtsTp2SetPhy();
                    }

                    if(ScalerDpRx0PhyCtsTp2Check() == _TRUE)
                    {
                        ScalerSetByte(PB7_A4_AUX_RESERVE4, 0x01);
                        g_ucDpRx0Temp = 0;
                    }
                    else
                    {
                        ScalerSetByte(PB7_A4_AUX_RESERVE4, 0xFF);
                        g_ucDpRx0Temp--;
                    }
                }

                break;

            case 0x03:

                ScalerSetByte(PB7_A5_AUX_RESERVE5, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0)));

                switch(g_ucDpRx0PhyCtsCtrl & 0x30)
                {
                    case 0x00: // Lane0 Test

                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), 0x00);

                        break;

                    case 0x10: // Lane1 Test

                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _BIT3);

                        break;

                    case 0x20: // Lane2 Test

                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), _BIT4);

                        break;

                    case 0x30: // Lane3 Test

                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), (_BIT4 | _BIT3));

                        break;

                    default:
                        break;
                }

                // Disable Scramble
                ScalerSetBit(PB_07_SCRAMBLE_CTRL, ~_BIT5, _BIT5);

                // Reverse PRBS7 Pattern Gen
                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~_BIT6, _BIT6);

                // Disable Error Detection
                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                if((g_ucDpRx0PhyCtsCtrl & 0x80) == 0x80)
                {
                    if((g_ucDpRx0PhyCtsCtrl & 0x30) == 0x00)   // Only for lane0 HBR2
                    {
                        // SetPhy for HBR2 Lane0 ACDR
                        ScalerDpRx0PhyCtsACDR();

                        // Waiting for PHY Stable
                        ScalerTimerDelayXms(10);

                        // HBR2 Compliance Eye Pattern
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                        // Waiting for PHY Stable
                        ScalerTimerDelayXms(10);

                        if(((((WORD)ScalerGetByte(PB_0B_BIST_PATTERN3)) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4)) < 1000)
                        {
                            DebugMessageRx0("CDR No Reset", 0x00);
                        }
                        else // Reset CDR to Re-allocate 10bit Raw Data
                        {
                            // [4] Disable Comma Detection
                            ScalerSetBit(PB_05_SAMPLE_EDGE, ~_BIT4, _BIT4);

                            for(usTemp = 0; usTemp <= 1000; usTemp++)
                            {
                                // [6] reg_adp_en_manual = 1'b0 --> CDR Open Loop
                                // [5] reg_cp_en_manual = 1'b0 --> CDR Open Loop
                                ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~(_BIT3 | _BIT2), 0x00);

                                // Waiting for VCO Stable
                                for(pData[0] = 0; pData[0] <= 2; pData[0]++)
                                {
                                    Delay5us(g_ucDelay5usN);
                                }

                                // [6] reg_adp_en_manual = 1'b1 --> CDR Close Loop
                                // [5] reg_cp_en_manual = 1'b1 --> CDR Close Loop
                                ScalerSetBit(PB_F9_LANE0_A_CDR_03, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

                                ScalerTimerDelayXms(2);

                                // Disable Error Detection
                                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                                // HBR2 Compliance Eye Pattern
                                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                                ScalerTimerDelayXms(2);

                                DebugMessageRx0("CDR Reset", usTemp);

                                if(((((WORD)ScalerGetByte(PB_0B_BIST_PATTERN3)) << 8) | ScalerGetByte(PB_0C_BIST_PATTERN4)) < 1000)
                                {
                                    break;
                                }
                            }

                            DebugMessageRx0("CDR Reset Done", 0xFF);
                        }
                    }
                    else
                    {
                        // SetPhy for HBR2
                        ScalerDpRx0PhyCtsTp2SetPhy();

                        // KI = 3'b011 --> KI = 1/4
                        ScalerSetByte(PB_D4_KI_0, 0x6C);
                        ScalerSetByte(PB_D5_KI_1, 0x6C);

                        // KP = 0x07 --> KP = 1.75
                        ScalerSetByte(PB_D6_KP_0, 0x07);
                        ScalerSetByte(PB_D7_KP_1, 0x07);
                        ScalerSetByte(PB_D8_KP_2, 0x07);
                        ScalerSetByte(PB_D9_KP_3, 0x07);

                        g_ucDpRx0Temp = 50;

                        while(g_ucDpRx0Temp > 0)  // Reset CDR
                        {
                            // Reset Digital CDR
                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            // Enable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                            // Waiting 1ms for Error Counter
                            ScalerTimerDelayXms(2);

                            if(ScalerGetByte(PB_0B_BIST_PATTERN3) < 0x7E)
                            {
                                g_ucDpRx0Temp = 0;
                            }
                            else
                            {
                                g_ucDpRx0Temp--;
                            }

                            // Disable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                        }

                        // Enable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                        // Waiting 2s for Error Counter
                        ScalerTimerDelayXms(2000);

                        pData[1] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                        pData[0] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                        // Disable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                        // KI = 3'b100 --> KI = 1/2
                        ScalerSetByte(PB_D4_KI_0, 0x90);
                        ScalerSetByte(PB_D5_KI_1, 0x90);

                        // KP = 0x07 --> KP = 1.75
                        ScalerSetByte(PB_D6_KP_0, 0x07);
                        ScalerSetByte(PB_D7_KP_1, 0x07);
                        ScalerSetByte(PB_D8_KP_2, 0x07);
                        ScalerSetByte(PB_D9_KP_3, 0x07);

                        g_ucDpRx0Temp = 50;

                        while(g_ucDpRx0Temp > 0)  // Reset CDR
                        {
                            // Reset Digital CDR
                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            // Enable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                            // Waiting 1ms for Error Counter
                            ScalerTimerDelayXms(2);

                            if(ScalerGetByte(PB_0B_BIST_PATTERN3) < 0x7E)
                            {
                                g_ucDpRx0Temp = 0;
                            }
                            else
                            {
                                g_ucDpRx0Temp--;
                            }

                            // Disable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                        }

                        // Enable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                        // Waiting 2s for Error Counter
                        ScalerTimerDelayXms(2000);

                        pData[3] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                        pData[2] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                        // Disable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                        // KI = 3'b011 --> KI = 1/4
                        ScalerSetByte(PB_D4_KI_0, 0x6C);
                        ScalerSetByte(PB_D5_KI_1, 0x6C);

                        // KP = 0x03 --> KP = 3.75
                        ScalerSetByte(PB_D6_KP_0, 0x0F);
                        ScalerSetByte(PB_D7_KP_1, 0x0F);
                        ScalerSetByte(PB_D8_KP_2, 0x0F);
                        ScalerSetByte(PB_D9_KP_3, 0x0F);

                        g_ucDpRx0Temp = 50;

                        while(g_ucDpRx0Temp > 0)  // Reset CDR
                        {
                            // Reset Digital CDR
                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            // Enable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                            // Waiting 1ms for Error Counter
                            ScalerTimerDelayXms(2);

                            if(ScalerGetByte(PB_0B_BIST_PATTERN3) < 0x7E)
                            {
                                g_ucDpRx0Temp = 0;
                            }
                            else
                            {
                                g_ucDpRx0Temp--;
                            }

                            // Disable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                        }

                        // Enable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                        // Waiting 2s for Error Counter
                        ScalerTimerDelayXms(2000);

                        pData[5] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                        pData[4] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                        // Disable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                        // KI = 3'b100 --> KI = 1/2
                        ScalerSetByte(PB_D4_KI_0, 0x90);
                        ScalerSetByte(PB_D5_KI_1, 0x90);

                        // KP = 0x0F --> KP = 3.75
                        ScalerSetByte(PB_D6_KP_0, 0x0F);
                        ScalerSetByte(PB_D7_KP_1, 0x0F);
                        ScalerSetByte(PB_D8_KP_2, 0x0F);
                        ScalerSetByte(PB_D9_KP_3, 0x0F);

                        g_ucDpRx0Temp = 50;

                        while(g_ucDpRx0Temp > 0)  // Reset CDR
                        {
                            // Reset Digital CDR
                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            // Enable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                            // Waiting 1ms for Error Counter
                            ScalerTimerDelayXms(2);

                            if(ScalerGetByte(PB_0B_BIST_PATTERN3) < 0x7E)
                            {
                                g_ucDpRx0Temp = 0;
                            }
                            else
                            {
                                g_ucDpRx0Temp--;
                            }

                            // Disable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                        }

                        // Enable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                        // Waiting 2s for Error Counter
                        ScalerTimerDelayXms(2000);

                        pData[7] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                        pData[6] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                        // Disable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                        if((PDATA_WORD(0) <= PDATA_WORD(1)) && (PDATA_WORD(0) <= PDATA_WORD(2)) && (PDATA_WORD(0) <= PDATA_WORD(3)))
                        {
                            // KI = 3'b011 --> KI = 1/4
                            ScalerSetByte(PB_D4_KI_0, 0x6C);
                            ScalerSetByte(PB_D5_KI_1, 0x6C);

                            // KP = 0x07 --> KP = 1.75
                            ScalerSetByte(PB_D6_KP_0, 0x07);
                            ScalerSetByte(PB_D7_KP_1, 0x07);
                            ScalerSetByte(PB_D8_KP_2, 0x07);
                            ScalerSetByte(PB_D9_KP_3, 0x07);
                        }
                        else if((PDATA_WORD(1) <= PDATA_WORD(2)) && (PDATA_WORD(1) <= PDATA_WORD(3)))
                        {
                            // KI = 3'b100 --> KI = 1/2
                            ScalerSetByte(PB_D4_KI_0, 0x90);
                            ScalerSetByte(PB_D5_KI_1, 0x90);

                            // KP = 0x07 --> KP = 1.75
                            ScalerSetByte(PB_D6_KP_0, 0x07);
                            ScalerSetByte(PB_D7_KP_1, 0x07);
                            ScalerSetByte(PB_D8_KP_2, 0x07);
                            ScalerSetByte(PB_D9_KP_3, 0x07);
                        }
                        else if(PDATA_WORD(2) <= PDATA_WORD(3))
                        {
                            // KI = 3'b011 --> KI = 1/4
                            ScalerSetByte(PB_D4_KI_0, 0x6C);
                            ScalerSetByte(PB_D5_KI_1, 0x6C);

                            // KP = 0x03 --> KP = 3.75
                            ScalerSetByte(PB_D6_KP_0, 0x0F);
                            ScalerSetByte(PB_D7_KP_1, 0x0F);
                            ScalerSetByte(PB_D8_KP_2, 0x0F);
                            ScalerSetByte(PB_D9_KP_3, 0x0F);
                        }
                        else
                        {
                            // KI = 3'b100 --> KI = 1/2
                            ScalerSetByte(PB_D4_KI_0, 0x90);
                            ScalerSetByte(PB_D5_KI_1, 0x90);

                            // KP = 0x0F --> KP = 3.75
                            ScalerSetByte(PB_D6_KP_0, 0x0F);
                            ScalerSetByte(PB_D7_KP_1, 0x0F);
                            ScalerSetByte(PB_D8_KP_2, 0x0F);
                            ScalerSetByte(PB_D9_KP_3, 0x0F);
                        }

                        g_ucDpRx0Temp = 50;

                        while(g_ucDpRx0Temp > 0)  // Reset CDR
                        {
                            // Reset Digital CDR
                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

                            // Waiting for CDR Stable
                            ScalerTimerDelayXms(10);

                            // Enable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                            // Waiting 1ms for Error Counter
                            ScalerTimerDelayXms(2);

                            if(ScalerGetByte(PB_0B_BIST_PATTERN3) < 0x7E)
                            {
                                g_ucDpRx0Temp = 0;
                            }
                            else
                            {
                                g_ucDpRx0Temp--;
                            }

                            // Disable Error Counter
                            ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                        }

                        // Read Back LE
                        ScalerSetByte(P1D_F0_COEF_1, 0x09);

                        pData[1] = 0xFF;
                        pData[0] = 0xFF;

                        switch(g_ucDpRx0PhyCtsCtrl & 0x30)
                        {
                            case 0x00: // Lane0 LE

                                // LE (Lane0)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
                                g_pucDpRx0LEMinTemp[0] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;  // The adaptive LE
                                g_pucDpRx0LEMaxTemp[0] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;  // The Best LE Value

                                for(g_ucDpRx0Temp = 0; g_ucDpRx0Temp < 3; g_ucDpRx0Temp++)
                                {
                                    // Reload LE (Lane0)
                                    ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((g_pucDpRx0LEMinTemp[0] + 1 - g_ucDpRx0Temp) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                    ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[0] + 1 - g_ucDpRx0Temp) << 2) & _BIT6);

                                    // Reload LE
                                    ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
                                    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

                                    // Enable Tap0~4 Adaptation for HBR2 0x01F
                                    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x1F);

                                    // Disable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

                                    // [0] en_eqen_manual = 1 --> Enable Adapation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

                                    // Waiting for Adaptation
                                    for(pData[4] = 0; pData[4] <= 20; pData[4]++)
                                    {
                                        Delay5us(g_ucDelay5usN);
                                    }

                                    // Disable Adaptation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

                                    // Disable Adaptation   0x000
                                    ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);

                                    // Enable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

                                    // Reload Tap0 to 21.5
                                    ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
                                    ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
                                    ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

                                    ScalerTimerDelayXms(10);

                                    // Enable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                                    // Waiting 1s for Error Counter
                                    ScalerTimerDelayXms(1000);

                                    pData[3] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                                    pData[2] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                                    // Disable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                                    if(PDATA_WORD(1) <= PDATA_WORD(0))
                                    {
                                        // LE (Lane0)
                                        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
                                        g_pucDpRx0LEMaxTemp[0] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                        pData[1] = pData[3];
                                        pData[0] = pData[2];
                                    }
                                }

                                // Reload LE (Lane0)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), 0x00);
                                ScalerSetBit(P1D_A2_L0_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[0] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                ScalerSetBit(P1D_A3_L0_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[0] << 2) & _BIT6));

                                // Reload LE
                                ScalerSetByte(P1D_AA_L0_INIT_8, 0x80);
                                ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);

                                // Enable Tap0~4 Adaptation for HBR2 0x01F
                                ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x1F);

                                break;


                            case 0x10: // Lane1 LE

                                // LE (Lane1)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
                                g_pucDpRx0LEMinTemp[1] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;
                                g_pucDpRx0LEMaxTemp[1] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                for(g_ucDpRx0Temp = 0; g_ucDpRx0Temp < 3; g_ucDpRx0Temp++)
                                {
                                    // Reload LE (Lane1)
                                    ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((g_pucDpRx0LEMinTemp[1] + 1 - g_ucDpRx0Temp) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                    ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[1] + 1 - g_ucDpRx0Temp) << 2) & _BIT6);

                                    // Reload LE
                                    ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
                                    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);

                                    // Enable Tap0~4 Adaptation for HBR2 0x01F
                                    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x1F);

                                    // Disable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

                                    // [0] en_eqen_manual = 1 --> Enable Adapation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

                                    // Waiting for Adaptation
                                    for(pData[4] = 0; pData[4] <= 20; pData[4]++)
                                    {
                                        Delay5us(g_ucDelay5usN);
                                    }

                                    // Disable Adaptation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

                                    // Disable Adaptation   0x000
                                    ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);

                                    // Enable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

                                    // Reload Tap0 to 21.5
                                    ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
                                    ScalerSetByte(P1D_BA_L1_INIT_8, 0x01);
                                    ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);

                                    ScalerTimerDelayXms(10);

                                    // Enable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                                    // Waiting 1s for Error Counter
                                    ScalerTimerDelayXms(1000);

                                    pData[3] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                                    pData[2] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                                    // Disable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                                    if(PDATA_WORD(1) <= PDATA_WORD(0))
                                    {
                                        // LE (Lane1)
                                        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
                                        g_pucDpRx0LEMaxTemp[1] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                        pData[1] = pData[3];
                                        pData[0] = pData[2];
                                    }
                                }

                                // Reload LE (Lane1)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT6);
                                ScalerSetBit(P1D_B2_L1_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[1] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                ScalerSetBit(P1D_B3_L1_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[1] << 2) & _BIT6));

                                // Reload LE
                                ScalerSetByte(P1D_BA_L1_INIT_8, 0x80);
                                ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);

                                // Enable Tap0~4 Adaptation for HBR2 0x01F
                                ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x1F);

                                break;


                            case 0x20: // Lane2 LE

                                // LE (Lane2)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
                                g_pucDpRx0LEMinTemp[2] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;
                                g_pucDpRx0LEMaxTemp[2] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                for(g_ucDpRx0Temp = 0; g_ucDpRx0Temp < 3; g_ucDpRx0Temp++)
                                {
                                    // Reload LE (Lane2)
                                    ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((g_pucDpRx0LEMinTemp[2] + 1 - g_ucDpRx0Temp) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                    ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[2] + 1 - g_ucDpRx0Temp) << 2) & _BIT6);

                                    // Reload LE
                                    ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
                                    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);

                                    // Enable Tap0~4 Adaptation for HBR2 0x01F
                                    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x1F);

                                    // Disable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

                                    // [0] en_eqen_manual = 1 --> Enable Adapation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

                                    // Waiting for Adaptation
                                    for(pData[4] = 0; pData[4] <= 20; pData[4]++)
                                    {
                                        Delay5us(g_ucDelay5usN);
                                    }

                                    // Disable Adaptation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

                                    // Disable Adaptation   0x000
                                    ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);

                                    // Enable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

                                    // Reload Tap0 to 21.5
                                    ScalerSetByte(P1D_C4_L2_INIT_2, 0x15);
                                    ScalerSetByte(P1D_CA_L2_INIT_8, 0x01);
                                    ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);

                                    ScalerTimerDelayXms(10);

                                    // Enable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                                    // Waiting 1s for Error Counter
                                    ScalerTimerDelayXms(1000);

                                    pData[3] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                                    pData[2] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                                    // Disable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                                    if(PDATA_WORD(1) <= PDATA_WORD(0))
                                    {
                                        // LE (Lane2)
                                        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
                                        g_pucDpRx0LEMaxTemp[2] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                        pData[1] = pData[3];
                                        pData[0] = pData[2];
                                    }
                                }

                                // Reload LE (Lane2)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), _BIT7);
                                ScalerSetBit(P1D_C2_L2_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[2] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                ScalerSetBit(P1D_C3_L2_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[2] << 2) & _BIT6));

                                // Reload LE
                                ScalerSetByte(P1D_CA_L2_INIT_8, 0x80);
                                ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);

                                // Enable Tap0~4 Adaptation for HBR2 0x01F
                                ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x1F);

                                break;


                            case 0x30: // Lane3 LE

                                // LE (Lane3)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                                g_pucDpRx0LEMinTemp[3] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;
                                g_pucDpRx0LEMaxTemp[3] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                for(g_ucDpRx0Temp = 0; g_ucDpRx0Temp < 3; g_ucDpRx0Temp++)
                                {
                                    // Reload LE (Lane3)
                                    ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), ((g_pucDpRx0LEMinTemp[3] + 1 - g_ucDpRx0Temp) & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                    ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, ((g_pucDpRx0LEMinTemp[3] + 1 - g_ucDpRx0Temp) << 2) & _BIT6);

                                    // Reload LE
                                    ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);
                                    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

                                    // Enable Tap0~4 Adaptation for HBR2 0x01F
                                    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x1F);

                                    // Disable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

                                    // [0] en_eqen_manual = 1 --> Enable Adapation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

                                    // Waiting for Adaptation
                                    for(pData[4] = 0; pData[4] <= 20; pData[4]++)
                                    {
                                        Delay5us(g_ucDelay5usN);
                                    }

                                    // Disable Adaptation
                                    ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

                                    // Disable Adaptation   0x000
                                    ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                    ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

                                    // Enable Sumamp High Gain Mode
                                    ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

                                    // Reload Tap0 to 21.5
                                    ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);
                                    ScalerSetByte(P1D_DA_L3_INIT_8, 0x01);
                                    ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

                                    ScalerTimerDelayXms(10);

                                    // Enable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                                    // Waiting 1s for Error Counter
                                    ScalerTimerDelayXms(1000);

                                    pData[3] = ScalerGetByte(PB_0C_BIST_PATTERN4);
                                    pData[2] = ScalerGetByte(PB_0B_BIST_PATTERN3);

                                    // Disable Error Counter
                                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                                    if(PDATA_WORD(1) <= PDATA_WORD(0))
                                    {
                                        // LE (Lane3)
                                        ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                                        g_pucDpRx0LEMaxTemp[3] = ScalerGetByte(P1D_F1_COEF_2) & 0x1F;

                                        pData[1] = pData[3];
                                        pData[0] = pData[2];
                                    }
                                }

                                // Reload LE (Lane3)
                                ScalerSetBit(P1D_F2_COEF_3, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
                                ScalerSetBit(P1D_D2_L3_LIMIT_INIT, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (g_pucDpRx0LEMaxTemp[3] & (_BIT3 | _BIT2 | _BIT1 | _BIT0)));
                                ScalerSetBit(P1D_D3_L3_INIT_1, ~_BIT6, ((g_pucDpRx0LEMaxTemp[3] << 2) & _BIT6));

                                // Reload LE
                                ScalerSetByte(P1D_DA_L3_INIT_8, 0x80);
                                ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

                                // Enable Tap0~4 Adaptation for HBR2 0x01F
                                ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                                ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x1F);

                                break;

                            default:
                                break;
                        }

                        // Disable Sumamp High Gain Mode
                        ScalerSetBit(PB_B0_CDR_07, ~_BIT1, 0x00);

                        // [0] en_eqen_manual = 1 --> Enable Adapation
                        ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, _BIT0);

                        // Waiting for Adaptation
                        for(pData[0] = 0; pData[0] <= 20; pData[0]++)
                        {
                            Delay5us(g_ucDelay5usN);
                        }

                        // Disable Adaptation
                        ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT0, 0x00);

                        // Disable Adaptation   0x000
                        ScalerSetBit(P1D_AC_L0_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                        ScalerSetBit(P1D_BC_L1_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                        ScalerSetBit(P1D_CC_L2_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                        ScalerSetBit(P1D_DC_L3_DFE_EN_3, ~(_BIT1 | _BIT0), 0x00);
                        ScalerSetByte(P1D_A1_L0_DFE_EN_2, 0x00);
                        ScalerSetByte(P1D_B1_L1_DFE_EN_2, 0x00);
                        ScalerSetByte(P1D_C1_L2_DFE_EN_2, 0x00);
                        ScalerSetByte(P1D_D1_L3_DFE_EN_2, 0x00);

                        // Enable Sumamp High Gain Mode
                        ScalerSetBit(PB_B0_CDR_07, ~_BIT1, _BIT1);

                        // Reload Tap0 to 21.5
                        ScalerSetByte(P1D_A4_L0_INIT_2, 0x15);
                        ScalerSetByte(P1D_B4_L1_INIT_2, 0x15);
                        ScalerSetByte(P1D_C4_L2_INIT_2, 0x15);
                        ScalerSetByte(P1D_D4_L3_INIT_2, 0x15);
                        ScalerSetByte(P1D_AA_L0_INIT_8, 0x01);
                        ScalerSetByte(P1D_BA_L1_INIT_8, 0x01);
                        ScalerSetByte(P1D_CA_L2_INIT_8, 0x01);
                        ScalerSetByte(P1D_DA_L3_INIT_8, 0x01);
                        ScalerSetByte(P1D_AA_L0_INIT_8, 0x00);
                        ScalerSetByte(P1D_BA_L1_INIT_8, 0x00);
                        ScalerSetByte(P1D_CA_L2_INIT_8, 0x00);
                        ScalerSetByte(P1D_DA_L3_INIT_8, 0x00);

                        // Waiting for PHY Stable
                        ScalerTimerDelayXms(10);
                    }

                    g_ucDpRx0Temp = 50;

                    while(g_ucDpRx0Temp > 0)  // Reset CDR
                    {
                        // Reset Digital CDR
                        ScalerSetByte(PB_C1_TMDS_CONT_1, 0x00);

                        // Waiting for CDR Stable
                        ScalerTimerDelayXms(10);

                        ScalerSetByte(PB_C1_TMDS_CONT_1, 0x78);

                        // Waiting for CDR Stable
                        ScalerTimerDelayXms(10);

                        // Enable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

                        // Waiting 1ms for Error Counter
                        ScalerTimerDelayXms(2);

                        if(ScalerGetByte(PB_0B_BIST_PATTERN3) < 0x7E)
                        {
                            g_ucDpRx0Temp = 0;
                        }
                        else
                        {
                            g_ucDpRx0Temp--;
                        }

                        // Disable Error Counter
                        ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);
                    }

                    // HBR2 Compliance Eye Pattern
                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
                }
                else
                {
                    // PRBS7 Pattern for RBR/HBR
                    ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
                }

                ScalerSetByte(PB7_A1_AUX_RESERVE1, 0x00);
                ScalerSetByte(PB7_A2_AUX_RESERVE2, 0x00);
                ScalerSetByte(PB7_A3_AUX_RESERVE3, 0x00);
                ScalerSetByte(PB7_A4_AUX_RESERVE4, 0x00);

                break;

            case 0x04:

                ScalerSetByte(PB7_A5_AUX_RESERVE5, (g_ucDpRx0PhyCtsCtrl & ~(_BIT2 | _BIT1 | _BIT0)));

                ScalerTimerDelayXms(10);

                ScalerSetByte(PB7_A1_AUX_RESERVE1, ScalerGetByte(PB_09_BIST_PATTERN1));
                ScalerSetByte(PB7_A2_AUX_RESERVE2, ScalerGetByte(PB_0A_BIST_PATTERN2));

                if((ScalerGetByte(PB_09_BIST_PATTERN1) | ScalerGetByte(PB_0A_BIST_PATTERN2)) != 0x00)
                {
                    ScalerSetByte(PB7_A3_AUX_RESERVE3, ScalerGetByte(PB_0B_BIST_PATTERN3));
                    ScalerSetByte(PB7_A4_AUX_RESERVE4, ScalerGetByte(PB_0C_BIST_PATTERN4));
                }
                else
                {
                    ScalerSetByte(PB7_A3_AUX_RESERVE3, 0x0F);
                    ScalerSetByte(PB7_A4_AUX_RESERVE4, 0x0F);
                }

                break;

            case 0x05:

                g_ucDpRx0PhyCtsCtrl = 0x00;

                // Clear DP PHY CTS Result
                ScalerSetByte(PB7_A0_AUX_RESERVE0, 0x99);
                ScalerSetByte(PB7_A1_AUX_RESERVE1, 0x00);
                ScalerSetByte(PB7_A2_AUX_RESERVE2, 0x00);
                ScalerSetByte(PB7_A3_AUX_RESERVE3, 0x00);
                ScalerSetByte(PB7_A4_AUX_RESERVE4, 0x00);

                // Disable PRBS7 Error Detection
                ScalerSetBit(PB_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

                // Clear DP PHY CTS Control Register
                ScalerSetByte(PB7_A5_AUX_RESERVE5, 0x00);

                CLR_DP_RX0_PHY_CTS_FLG();

                break;

            default:

                ScalerSetByte(PB7_A0_AUX_RESERVE0, 0x99);
                ScalerSetByte(PB7_A5_AUX_RESERVE5, 0x00);

                break;
        }
    }
}

//--------------------------------------------------
// Description  : Enable DP Fifo Under/OverFlow Watch Dog
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetFifoWD(bit bEn)
{
#if(_DP_FREESYNC_SUPPORT == _ON)
    // Temp for C Version Bug
    if((GET_FREESYNC_ENABLED() == _TRUE) && (ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE))
    {
        bEn = _DISABLE;
    }
#endif

    ScalerSetBit(PB6_38_DP_VWD_CTRL, ~(_BIT5 | _BIT4), ((bEn == _ENABLE) ? (_BIT5 | _BIT4) : 0x00));
}

//--------------------------------------------------
// Description  : Enable DP Fifo Under/OverFlow IRQ
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetFifoIRQ(bit bEn)
{
    if(ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE)
    {
        bEn = _DISABLE;
    }

    ScalerSetBit(PB6_3A_DP_IRQ_CTRL0, ~(_BIT1 | _BIT0), ((bEn == _ENABLE) ? (_BIT1 | _BIT0) : 0x00));
}

//--------------------------------------------------
// Description  : Signal PreDetection for DP(Power Normal)
// Input Value  : None
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpRx0NormalPreDetect(void)
{
    // For Dp PHY CTS Test
    if(GET_DP_RX0_PHY_CTS_FLG() == _TRUE)
    {
        ScalerDpRx0PhyCTS();

        return _FALSE;
    }

#if(_DP_MST_SUPPORT == _ON)

    if(GET_DP_RX0_AUX_CH_POWER_ON_WAKE_UP() == _TRUE)
    {
        CLR_DP_RX0_AUX_CH_POWER_ON_WAKE_UP();
    }

#endif

#if(_DP_ASSR_MODE_SUPPORT == _ON)

    // ASSR Mode Setting
    ScalerDpRx0ASSRModeSetting();

#endif

    switch(GET_DP_RX0_LINK_TRAINING_STATUS())
    {
        case _DP_NORMAL_LINK_TRAINING_PASS:
        case _DP_LINK_STATUS_FAIL:

            CLR_DP_RX0_VALID_VIDEO_CHECK();

#if(_DP_MST_SUPPORT == _ON)
            ScalerDpRx0MstInfoBackup(_DP_MST_BACKUP_INFO_RESET);
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            ScalerDpRx6MstInfoBackup(_DP_MST_BACKUP_INFO_RESET);
#endif
#endif
            if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               ((ScalerDpRx0DFECheck() == _TRUE) || (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE)) &&
               (ScalerDpRx0MarginLinkCheck() == _TRUE) &&
               (ScalerDpRx0AlignCheck() == _TRUE) &&
               (ScalerDpRx0DecodeCheck() == _TRUE))
            {
                /*
                DebugMessageRx0("9. Lane0 LE Diff", (g_pucDpRx0LEMaxTemp[0] - g_pucDpRx0LEMinTemp[0]));
                DebugMessageRx0("9. Lane1 LE Diff", (g_pucDpRx0LEMaxTemp[1] - g_pucDpRx0LEMinTemp[1]));
                DebugMessageRx0("9. Lane2 LE Diff", (g_pucDpRx0LEMaxTemp[2] - g_pucDpRx0LEMinTemp[2]));
                DebugMessageRx0("9. Lane3 LE Diff", (g_pucDpRx0LEMaxTemp[3] - g_pucDpRx0LEMinTemp[3]));
                DebugMessageRx0("9. Lane0 LE Min", g_pucDpRx0LEMinTemp[0]);
                DebugMessageRx0("9. Lane1 LE Min", g_pucDpRx0LEMinTemp[1]);
                DebugMessageRx0("9. Lane2 LE Min", g_pucDpRx0LEMinTemp[2]);
                DebugMessageRx0("9. Lane3 LE Min", g_pucDpRx0LEMinTemp[3]);
                DebugMessageRx0("9. Lane0 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[0] - g_pucDpRx0Tap0MinTemp[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[1] - g_pucDpRx0Tap0MinTemp[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[2] - g_pucDpRx0Tap0MinTemp[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[3] - g_pucDpRx0Tap0MinTemp[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max", g_pucDpRx0Tap0MaxTemp[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max", g_pucDpRx0Tap0MaxTemp[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max", g_pucDpRx0Tap0MaxTemp[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max", g_pucDpRx0Tap0MaxTemp[3]);
                DebugMessageRx0("9. FLD Band", ScalerGetByte(PB_BF_LANE0_A_CDR_02));
                DebugMessageRx0("9. Best FLD Band", ScalerGetByte(PB_BE_LANE0_A_CDR_01));
                DebugMessageRx0("9. Lane0 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[0] - g_pucDpRx0Tap0MinTemp2[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[1] - g_pucDpRx0Tap0MinTemp2[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[2] - g_pucDpRx0Tap0MinTemp2[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[3] - g_pucDpRx0Tap0MinTemp2[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[3]);
                DebugMessageRx0("9. TP2 Check Result", g_ucDpRx0EQCRC);
                */

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);

                ScalerTimerDelayXms(_DP_ONE_FRAME_TIME_MAX);

                SET_DP_RX0_AUX_MANUAL_MODE();

                if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL)
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);
                }

                SET_DP_RX0_AUX_AUTO_MODE();

                if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1) ||
                   (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0)))
                {
                    return _FALSE;
                }

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
                if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
                {
                    CLR_DP_RX_D0_MARGIN_LINK_HBR2();
                }
                else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
                {
                    CLR_DP_RX_D6_MARGIN_LINK_HBR2();
                }
#else
                CLR_DP_RX_D0_MARGIN_LINK_HBR2();
#endif
#endif
                return _TRUE;
            }
            else
            {
                DebugMessageRx0("7. Link Status Fail IRQ", 0);

                SET_DP_RX0_AUX_MANUAL_MODE();

                if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);

                    ScalerTimerActiveTimerEvent(SEC(0.1), _SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);
                }

                SET_DP_RX0_AUX_AUTO_MODE();
            }

            break;

        case _DP_LINK_TRAINING_FAIL:

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);

            ScalerDpRx0LinkStatusIRQ();

            break;

        case _DP_FAKE_LINK_TRAINING_PASS:
        case _DP_FAKE_LINK_TRAINING_PASS_VBIOS:

            CLR_DP_RX0_VALID_VIDEO_CHECK();

#if(_DP_MST_SUPPORT == _ON)
            ScalerDpRx0MstInfoBackup(_DP_MST_BACKUP_INFO_RESET);
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
            ScalerDpRx6MstInfoBackup(_DP_MST_BACKUP_INFO_RESET);
#endif
#endif
            ScalerTimerDelayXms(30);

            DebugMessageRx0("7. DP Rebuild PHY", GET_DP_RX0_LINK_TRAINING_STATUS());

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_LINK_STATUS_IRQ);

            SET_DP_RX0_AUX_MANUAL_MODE();

            if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
            {
                ScalerDpRx0RebuildPhy(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01));
            }

            SET_DP_RX0_AUX_AUTO_MODE();

            // De-Skew Circuit Reset
            ScalerSetBit(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), 0x00);
            ScalerSetBit(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), _BIT6);

            // Mac Reset After Link Clock Stable
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
            ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

            // Delay for Lane Alignment after Mac Reset
            ScalerTimerDelayXms(2);

            if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               ((ScalerDpRx0DFECheck() == _TRUE) || (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE)) &&
               (ScalerDpRx0MarginLinkCheck() == _TRUE) &&
               (ScalerDpRx0AlignCheck() == _TRUE) &&
               (ScalerDpRx0DecodeCheck() == _TRUE))
            {
                DebugMessageRx0("7. Rebuild Phy Pass", 0);

                /*
                DebugMessageRx0("9. Lane0 LE Diff", (g_pucDpRx0LEMaxTemp[0] - g_pucDpRx0LEMinTemp[0]));
                DebugMessageRx0("9. Lane1 LE Diff", (g_pucDpRx0LEMaxTemp[1] - g_pucDpRx0LEMinTemp[1]));
                DebugMessageRx0("9. Lane2 LE Diff", (g_pucDpRx0LEMaxTemp[2] - g_pucDpRx0LEMinTemp[2]));
                DebugMessageRx0("9. Lane3 LE Diff", (g_pucDpRx0LEMaxTemp[3] - g_pucDpRx0LEMinTemp[3]));
                DebugMessageRx0("9. Lane0 LE Min", g_pucDpRx0LEMinTemp[0]);
                DebugMessageRx0("9. Lane1 LE Min", g_pucDpRx0LEMinTemp[1]);
                DebugMessageRx0("9. Lane2 LE Min", g_pucDpRx0LEMinTemp[2]);
                DebugMessageRx0("9. Lane3 LE Min", g_pucDpRx0LEMinTemp[3]);
                DebugMessageRx0("9. Lane0 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[0] - g_pucDpRx0Tap0MinTemp[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[1] - g_pucDpRx0Tap0MinTemp[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[2] - g_pucDpRx0Tap0MinTemp[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff", (g_pucDpRx0Tap0MaxTemp[3] - g_pucDpRx0Tap0MinTemp[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max", g_pucDpRx0Tap0MaxTemp[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max", g_pucDpRx0Tap0MaxTemp[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max", g_pucDpRx0Tap0MaxTemp[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max", g_pucDpRx0Tap0MaxTemp[3]);
                DebugMessageRx0("9. FLD Band", ScalerGetByte(PB_BF_LANE0_A_CDR_02));
                DebugMessageRx0("9. Best FLD Band", ScalerGetByte(PB_BE_LANE0_A_CDR_01));
                DebugMessageRx0("9. D10.2 Counter", g_usDpRx0ClockCount);
                DebugMessageRx0("9. D10.2 Counter1", g_usDpRx0ClockCount1);
                DebugMessageRx0("9. Lane0 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[0] - g_pucDpRx0Tap0MinTemp2[0]));
                DebugMessageRx0("9. Lane1 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[1] - g_pucDpRx0Tap0MinTemp2[1]));
                DebugMessageRx0("9. Lane2 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[2] - g_pucDpRx0Tap0MinTemp2[2]));
                DebugMessageRx0("9. Lane3 Tap0 Diff 2", (g_pucDpRx0Tap0MaxTemp2[3] - g_pucDpRx0Tap0MinTemp2[3]));
                DebugMessageRx0("9. Lane0 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[0]);
                DebugMessageRx0("9. Lane1 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[1]);
                DebugMessageRx0("9. Lane2 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[2]);
                DebugMessageRx0("9. Lane3 Tap0 Max 2", g_pucDpRx0Tap0MaxTemp2[3]);
                DebugMessageRx0("9. Best FLD Band", ScalerGetByte(PB_BE_LANE0_A_CDR_01));
                DebugMessageRx0("9. TP2 Check Result", g_ucDpRx0EQCRC);
                DebugMessageRx0("9. DP Requeset", ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x06));
                DebugMessageRx0("9. DP Requeset", ScalerDpRx0GetDpcdInfo(0x00, 0x02, 0x07));
                DebugMessageRx0("9. Lane0 Tap1 Max", ScalerGetByte(P1D_A5_L0_INIT_3));
                DebugMessageRx0("9. Lane1 Tap1 Max", ScalerGetByte(P1D_B5_L1_INIT_3));
                DebugMessageRx0("9. Lane2 Tap1 Max", ScalerGetByte(P1D_C5_L2_INIT_3));
                DebugMessageRx0("9. Lane3 Tap1 Max", ScalerGetByte(P1D_D5_L3_INIT_3));
                */

                ScalerTimerDelayXms(_DP_ONE_FRAME_TIME_MAX);

                SET_DP_RX0_AUX_MANUAL_MODE();

                if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);
                }

                SET_DP_RX0_AUX_AUTO_MODE();

                if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1) ||
                   (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0)))
                {
                    return _FALSE;
                }

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
                if(GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT)
                {
                    CLR_DP_RX_D0_MARGIN_LINK_HBR2();
                }
                else if(GET_D6_SWITCH_SELECT() == _D6_INPUT_PORT)
                {
                    CLR_DP_RX_D6_MARGIN_LINK_HBR2();
                }
#else
                CLR_DP_RX_D0_MARGIN_LINK_HBR2();
#endif
#endif
                return _TRUE;
            }
            else
            {
                DebugMessageRx0("7. DP Rebuild PHY Fail", 0);

                SET_DP_RX0_AUX_MANUAL_MODE();

                if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS)
                {
                    ScalerDpRx0DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);

#if((_DP_TX_SUPPORT == _ON) && (_D0_DP_MST_PORT_SUPPORT == _ON))
                    ScalerDpRx0HDCPBlockReset();
#endif
                }
                else if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS)
                {
                    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);
                }

                SET_DP_RX0_AUX_AUTO_MODE();
            }

            break;

        case _DP_LINK_TRAINING_NONE:

            if(GET_DP_RX0_VALID_VIDEO_CHECK() == _TRUE)
            {
                ScalerDpRx0ValidSignalDetection();

                DebugMessageRx0("7. VBIOS Check !!!!!!!", GET_DP_RX0_FAKE_LINK_TRAINING());
            }

            break;

        default:

            break;
    }

    if(GET_DP_RX0_VALID_VIDEO_CHECK() == _TRUE)
    {
        CLR_DP_RX0_VALID_VIDEO_CHECK();

#if(_DP_MST_SUPPORT == _ON)
        ScalerDpRx0MstInfoBackup(_DP_MST_BACKUP_INFO_RESET);
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        ScalerDpRx6MstInfoBackup(_DP_MST_BACKUP_INFO_RESET);
#endif
#endif
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Port Source/Sync Scanning and Setting
// Input Value  : None
// Output Value : Source DP --> DP Sync Stable
//                Source None --> No Stable Sync
//--------------------------------------------------
BYTE ScalerDpRx0ScanInputPort(void)
{
    if(GET_DP_RX0_LINK_TRAINING_STATUS() != _DP_NORMAL_LINK_TRAINING_PASS)
    {
        return _SOURCE_NONE;
    }

    if(ScalerDpRx0HdcpCheck() == _FALSE)
    {
        DebugMessageRx0("7. DP HDCP Check Fail", 0);

        ScalerDpRx0CpIRQ(_DP_HDCP_BSTATUS_LINK_INTEGRITY_FAIL);

        if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & _BIT0) == 0x00)
        {
            ScalerTimerReactiveTimerEvent(SEC(1), _SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);
        }

        return _SOURCE_NONE;
    }

    if(ScalerDpRx0GetVideoStream() == _FALSE)
    {
        DebugMessageRx0("7. DP Video Stream Fail", 0);

        return _SOURCE_NONE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x07) & _BIT7) == _BIT7)
    {
        SET_DP_FREESYNC_ENABLED();
    }
    else
    {
        CLR_FREESYNC_ENABLED();
    }
#endif

    if(ScalerDpRx0MSACheck() == _FALSE)
    {
        DebugMessageRx0("7. DP MSA Fail", 0);

        return _SOURCE_NONE;
    }

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _SOURCE_NONE;
    }
#endif

    if(ScalerDpRx0GetVideoInfo() == _FALSE)
    {
        DebugMessageRx0("7. DP Get Video Info Fail", 0);

        return _SOURCE_NONE;
    }
    else
    {
        ScalerDpRx0SetColorInfo();
    }

    if(ScalerDpRx0DisplayFormatSetting() == _FALSE)
    {
        DebugMessageRx0("7. DP Display Format Fail", 0);

        return _SOURCE_NONE;
    }

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _SOURCE_NONE;
    }
#endif

    if(ScalerDpRx0StreamClkRegenerate() == _FALSE)
    {
        DebugMessageRx0("7. DP SteamClk Fail", 0);

        return _SOURCE_NONE;
    }

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if((ScalerSyncCheckUrgentEvent() == _TRUE))
    {
        return _SOURCE_NONE;
    }
#endif

    if(ScalerDpRx0FifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
    {
#if(_DP_FREESYNC_SUPPORT == _ON)
        if(GET_FREESYNC_ENABLED() == _TRUE)
        {
            return _SOURCE_NONE;
        }
        else
#endif
        {
#if(_URGENT_EVENT_CHECK_MODE == _ON)
            if((ScalerSyncCheckUrgentEvent() == _TRUE))
            {
                return _SOURCE_NONE;
            }
#endif

            ScalerDpRx0AdjustVsyncDelay();

#if(_URGENT_EVENT_CHECK_MODE == _ON)
            if((ScalerSyncCheckUrgentEvent() == _TRUE))
            {
                return _SOURCE_NONE;
            }
#endif

            if(ScalerDpRx0FifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
            {
#if(_URGENT_EVENT_CHECK_MODE == _ON)
                if((ScalerSyncCheckUrgentEvent() == _TRUE))
                {
                    return _SOURCE_NONE;
                }
#endif

                ScalerDpRx0AdjustVsyncDelay();

#if(_URGENT_EVENT_CHECK_MODE == _ON)
                if((ScalerSyncCheckUrgentEvent() == _TRUE))
                {
                    return _SOURCE_NONE;
                }
#endif

                if(ScalerDpRx0FifoCheck(_DP_FIFO_DELAY_CHECK) == _FALSE)
                {
                    DebugMessageRx0("7. DP Fifo Fail", 0);

                    return _SOURCE_NONE;
                }
            }
        }
    }

    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_HDCP_LONG_HOTPLUG_EVENT);

#if(_DP_FREESYNC_SUPPORT == _ON)
    // Measurement Enable for On-Line VFreq check
    ScalerSetBit(PB5_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);
#endif

    ScalerSetBit(PB5_31_DP_OUTPUT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));

#if(_AUDIO_SUPPORT == _ON)
    // Enable Audio Channel
    ScalerAudioDpAudioEnable(_ENABLE, _D0_INPUT_PORT);
#endif

#if(_DP_MST_SUPPORT == _ON)
    CLR_DP_RX0_SOURCE_FIRST_POWER_ON();
#endif

    DebugMessageRx0("Source DP Rx0 Found", 0);

    return _SOURCE_DP;
}

//--------------------------------------------------
// Description  : On Line Check DP stability
// Input Value  : None
// Output Value : True --> DP Stable
//                False --> DP Unstable
//--------------------------------------------------
bit ScalerDpRx0StableDetect(void)
{
#if(_DP_POWER_MANAGEMENT_FOR_FAST_DISPLAY_RECOVER == _ON)
    if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1)
#else
    if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT1) ||
       (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == (_BIT2 | _BIT0)))
#endif
    {
        DebugMessageRx0("7. DP Power Down", 0);

        return _FALSE;
    }

    if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _FALSE) ||
       (ScalerDpRx0AlignCheck() == _FALSE) ||
       (ScalerDpRx0DecodeCheck() == _FALSE) ||
       ((ScalerDpRx0DFECheck() == _FALSE) && (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _FALSE)))
    {
        SET_DP_RX0_AUX_MANUAL_MODE();

        if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_LINK_TRAINING_PASS)
        {
            SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_STATUS_FAIL);
        }

        SET_DP_RX0_AUX_AUTO_MODE();

        DebugMessageRx0("7. DP Link Fail", 0);

        return _FALSE;
    }

    if(ScalerDpRx0GetVideoStream() == _FALSE)
    {
        DebugMessageRx0("7. DP Video Stream Fail", 0);

        return _FALSE;
    }

    if(ScalerDpRx0MiscCheck() == _FALSE)
    {
        DebugMessageRx0("7. DP Misc Change", 0);

        return _FALSE;
    }

    if(ScalerDpRx0FifoCheck(_DP_FIFO_POLLING_CHECK) == _FALSE)
    {
        DebugMessageRx0("7. Fifo Under/Overflow", 0);

        return _FALSE;
    }

    if(ScalerDpRx0MSAActiveChange() == _TRUE)
    {
        DebugMessageRx0("7. MSA Timing Change", 0);

        return _FALSE;
    }

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(ScalerDpRx0GetFREESYNCStatusChange() == _TRUE)
    {
        return _FALSE;
    }
#endif

    // Clear CPIRQ Flag
    ScalerDpRx0CheckHdcpCpirqStatus();

    ScalerDpRx0CrcCalculate();

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP DC OFF to Normal HPD Process
// Input Value  : UserData -> _DP_HOT_PLUG_DC_OFF_HIGH status
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0HPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHighStatus)
{
    if((ucDpHotPlugDCOffHighStatus) == _TRUE)
    {
        //////////////////////////////////////////////////////////////////////////////////////
        // For 6193 case, HDCP moudle in Power isolation region, so system go to ps/pd mode,
        // system flow will change HDCP capablity, this lead to in the second time DC on need
        // Rx notify Tx re-link up HDCP handle by pulling a long HPD Evnet, future RL6410 no
        // need this case
        //////////////////////////////////////////////////////////////////////////////////////
#if(_DP_DELL_D3_TEST_SUPPORT == _OFF)
        if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT0)
#endif
        {
            DebugMessageDigital("7. Long HPD Event", ucDpHotPlugDCOffHighStatus);

            ScalerDpRx0HotPlugEvent(_DP_LONG_HPD_EVENT);
        }
    }
#if(_DP_MST_SUPPORT == _ON)
    else if(ucDpHotPlugDCOffHighStatus == _LOW_FOR_MST)
    {
        // In MST mode, It should be reset certainly moudle for MSG link up between Tx and Rx
        // In addition, "AC On to Normal", aux reset bit has not be set, It's better do MST reset and then pull high hpd.
        // "PS/PD to Normal", It has done MST reset success in "Normal to PS/PD", here operating MST reset is treated as no effect in order to look after "AC On to Normal" order.
        ScalerDpMstReset(_DP_MST_RX0_PORT);

        // In MST Mode, It should be give enough HPD Low time between two times DC on/off operation prevent no picture light up happen
        ScalerDpRx0HotPlugEvent(_DP_MST_LONG_HPD_EVENT);
    }
#endif
    else
    {
        DebugMessageDigital("7. HPD Asserted", ucDpHotPlugDCOffHighStatus);

        ScalerDpRx0HotPlugEvent(_DP_HPD_ASSERTED);
    }
}

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Rx LT Status Check
// Input Value  : None
// Output Value : True --> LT Status Pass
//                False --> LT Status Fail
//--------------------------------------------------
bit ScalerDpRx0LTStatusCheck(void)
{
    if((ScalerDpRx0CDRCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
       (ScalerDpRx0AlignCheck() == _TRUE) &&
       (ScalerDpRx0DecodeCheck() == _TRUE) &&
       ((ScalerDpRx0DFECheck() == _TRUE) || (ScalerDpRx0SignalCheck(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE)))
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Dp Rx Aux Ch Power Status Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0AuxChPowerStatusCheck(bit bCableStatus)
{
#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
    if((GET_D6_SWITCH_POWER_STATUS() == _DIGITAL_D6_SWITCH_POWER_ON) && (GET_D6_SWITCH_SELECT() == _D0_INPUT_PORT) && (g_enumDpMSTCapablePort == _DP_MST_RX0_PORT))
#else
    if(g_enumDpMSTCapablePort == _DP_MST_RX0_PORT)
#endif
    {
        if(bCableStatus == _TRUE)
        {
            if(PCB_D0_HOTPLUG_DETECT() == _D0_HOT_PLUG_HIGH)
            {
                // Whether to Start Debounce
                if((GET_PCB_D0_DP_SOURCE_POWER() == _OFF) &&
                   (GET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE() == _FALSE) &&
                   (GET_DP_RX0_CHECK_AUX_CH_POWER_OFF() == _FALSE))
                {
                    SET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();

                    ScalerTimerActiveTimerEvent(SEC(0.2), _SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                }

                // Debouncing
                if(GET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE() == _TRUE)
                {
                    if(GET_PCB_D0_DP_SOURCE_POWER() == _ON)
                    {
                        CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                    }
                }

                // Enable 1.5s Hotplug when Source Power On
                if((GET_DP_RX0_CHECK_AUX_CH_POWER_OFF() == _TRUE) && (GET_PCB_D0_DP_SOURCE_POWER() == _ON))
                {
                    CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF();

                    SET_DP_RX0_AUX_CH_POWER_ON_WAKE_UP();

                    SET_DP_RX0_SOURCE_FIRST_POWER_ON();

                    ScalerDpMstReset(g_enumDpMSTCapablePort);

                    ScalerDpRx0HotPlugEvent(_DP_HPD_LOW);

                    ScalerTimerActiveTimerEvent(SEC(1.5), _SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);

#if(_DP_TX_SUPPORT == _ON)

                    if((GET_DP_TX_DOWNSTREAM_DPPLUG_STATUS() == _DP_PLUG) && (GET_DP_TX_DOWNSTREAM_MSGCAP_STATUS() == _DP_MSG_SUPPORT))
                    {
                        // Clear Payload ID Only if Downstream PID Table is Not Empty
                        if(ScalerDpTxAuxNativeRead(0x00, 0x02, 0xC1, 1, pData) == _TRUE)
                        {
                            if(pData[0] != 0x00)
                            {
                                // Set Flag to Gen Clear ID Table Msg
                                SET_DP_GEN_DOWN_REQUEST_MSG(_DP_MSG_CLEAR_PAYLOAD_ID_TABLE);
                            }
                        }
                        else
                        {
                            // Set Flag to Gen Clear ID Table Msg
                            SET_DP_GEN_DOWN_REQUEST_MSG(_DP_MSG_CLEAR_PAYLOAD_ID_TABLE);
                        }
                    }
#endif
                }
            }
        }
        else
        {
            CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
            CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF();

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX0_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
        }
    }
}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP MST2SST Stream Clk PLL Setting
// Input Value  : None
// Output Value : True --> Stream CLK Regen. ok
//--------------------------------------------------
bit ScalerDpRx0MstToSstStreamClkRegenerate(void)
{
    DWORD ulStreamClkValue = 0;
    SDWORD lOffsetValue = 0;
    DWORD ulpllm = 0;
    DWORD ulXtal_clk = 0;
    WORD usDpHtotal = 0;
    WORD usDpVtotal = 0;
    DWORD ulVBs2BsCount = 0;
    DWORD ulDpNvidValue = 0;
    BYTE ucpllo = 0;
    BYTE ucdivs = 0;
    BYTE ucdiv2 = 0;
    BYTE ucplln = 0;
    BYTE ucBuf = 0;
    BYTE ucdiv_pllo = 0;
    BYTE ucdiv_divs = 0;

#if(_DP_FREESYNC_SUPPORT == _ON)
    DWORD ulDpMvidValue = 0;
#endif

    // PLL Input Clock select to Link Clock, Output Clock Select to PLL Clock, Double Buffer.
    ScalerSetBit(PA_A0_MN_SCLKG_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT4));

    ulDpNvidValue = ((((DWORD)ScalerGetByte(PA_23_MSA_NVID_00)) << 16) | (((DWORD)ScalerGetByte(PA_24_MSA_NVID_01)) << 8) | ((DWORD)ScalerGetByte(PA_25_MSA_NVID_02)));

    usDpHtotal = ((((WORD)ScalerGetByte(PA_40_MN_DPF_HTT_M)) << 8) | ((WORD)ScalerGetByte(PA_41_MN_DPF_HTT_L)));

    usDpVtotal = ((((WORD)ScalerGetByte(PA_48_MN_DPF_VTT_M)) << 8) | ((WORD)ScalerGetByte(PA_49_MN_DPF_VTT_L)));

    // [5] ln_ck_sel = 1'b1 -> CDR Clock
    // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

    // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
    ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

    // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
    ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

    // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

    // Waiting for Measure Done
    ScalerTimerDelayXms(2);

    if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
    {
        PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
    }
    else
    {
        if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
        {
            PDATA_WORD(0) = 0x4E20;
        }
        else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
        {
            PDATA_WORD(0) = 0x2710;
        }
        else // Both Default && _DP_LINK_RBR Case
        {
            PDATA_WORD(0) = 0x1770;
        }
    }

    // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
    ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

    PDATA_DWORD(0) = ((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ;

    ulXtal_clk = (PDATA_DWORD(0) / 1000);

    // Measurement Enable
    ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PA_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The result
    ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    ulVBs2BsCount = ((((DWORD)(ScalerGetByte(PA_58_MN_MEAS_CTRL) & 0x1F)) << 16) | (((DWORD)ScalerGetByte(PA_59_MN_MEAS_VLN_M)) << 8) | ((DWORD)ScalerGetByte(PA_5A_MN_MEAS_VLN_L)));

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_DP_MST_FREESYNC_ENABLED() == _TRUE)
    {
        ulDpMvidValue = ((((DWORD)ScalerGetByte(PA_20_MSA_MVID_00)) << 16) | (((DWORD)ScalerGetByte(PA_21_MSA_MVID_01)) << 8) | ((DWORD)ScalerGetByte(PA_22_MSA_MVID_02)));

        // Calculate streamclk
        ulStreamClkValue = ((DWORD)ulDpMvidValue * (PDATA_DWORD(0) / ulDpNvidValue) + (PDATA_DWORD(0) % ulDpNvidValue * 100 / ulDpNvidValue * (DWORD)ulDpMvidValue / 100));
    }
    else
#endif
    {
        // Calculate streamclk (Unit is Hz)
        ulStreamClkValue = (((((DWORD)usDpHtotal) * ((DWORD)usDpVtotal) * 100) / ulVBs2BsCount) * _GDI_CLK_KHZ * 10);
    }

    SET_DP_TX_INPUT_PIXEL_CLK(ulStreamClkValue / 100000);

    ucplln = ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00);

    // Get DPLL parameter
    // If "600Mhz > ulStreamClkValue > 270Mhz"
    if((600000000 > ulStreamClkValue) && (ulStreamClkValue >= 270000000))
    {
        ucpllo = 0;
        ucdivs = 0;

        ucdiv_divs = 1;
        ucdiv_pllo = 1;

        ulpllm = ((((ulStreamClkValue / 4) * ucdiv_divs * ucdiv_pllo) * ucplln / 250 + (ulXtal_clk / 4)) / (ulXtal_clk));

        if(ulpllm > 257)
        {
            return _FALSE;
        }
    }
    // If "270MHz > ulStreamClkValue > 4.21875Mhz"
    else if((ulStreamClkValue < 270000000) && (ulStreamClkValue >= 4218750))
    {
        ucpllo = 1;

        if((ulStreamClkValue < 270000000) && (ulStreamClkValue >= 135000000))
        {
            ucdivs = 0;
        }
        else if((ulStreamClkValue < 135000000) && (ulStreamClkValue >= 67500000))
        {
            ucdivs = 1;
        }
        else if((ulStreamClkValue < 67500000) && (ulStreamClkValue >= 33750000))
        {
            ucdivs = 2;
        }
        else if((ulStreamClkValue < 33750000) && (ulStreamClkValue >= 16875000))
        {
            ucdivs = 4;
        }
        else if((ulStreamClkValue < 16875000) && (ulStreamClkValue >= 8437500))
        {
            ucdivs = 8;
        }
        else
        {
            ucdivs = 16;
        }

        // Because set 17 get minimum error for recovery stream clk , close to fact clk.
        if(ucdivs == 0)
        {
            ucdiv_divs = 1;
        }
        else
        {
            ucdiv_divs = 2 * ucdivs;
        }

        ucdiv_pllo = 1;

        if(ucpllo != 0)
        {
            ucdiv_pllo = 1;

            for(ucBuf = 0; ucBuf < ucpllo; ucBuf++)
            {
                ucdiv_pllo = 2 * ucdiv_pllo;
            }
        }

        ulpllm = ((((ulStreamClkValue / 4) * ucdiv_divs * ucdiv_pllo) * ucplln / 250 + (ulXtal_clk / 4)) / (ulXtal_clk));

        if(ulpllm > 257)
        {
            return _FALSE;
        }
    }
    else
    {
        return _FALSE;
    }

    ulpllm++;

    // offset = (m/n*f_ref - f)/(m/n*f_ref)*2^21
    // seperate *2^21 to *32*16384*4
    lOffsetValue = ((SDWORD)((ulXtal_clk * 1000 / ucplln) * ulpllm) - (SDWORD)(ulStreamClkValue * ucdiv_pllo * ucdiv_divs)) * 32 / ulpllm * ucplln / ulXtal_clk * 16384 / 1000 * 4;

    lOffsetValue = 0x7FFFF - lOffsetValue + 1;

    // DPPLL Power Down
    ScalerSetBit(PA_BD_MN_SCLKG_PLL_PWR, ~_BIT7, _BIT7);

    /*
    // Disable M/N Tracking
    ScalerSetBit(PA_A7_MN_SCLKG_TRK_CTRL, ~_BIT7, 0x00);
    */

    // Disable HSync Tracking
    ScalerSetBit(PA_A7_MN_SCLKG_TRK_CTRL, ~_BIT6, 0x00);

    // Set VCOMD, phase Swallow Circuit Clock Select, SCLKGSTOP
    ScalerSetBit(PA_BF_MN_SCLKG_PLL_WD, ~(0x7F), 0x16);

    // Set DPPLL Div_2 & Div_s
    ScalerSetByte(PA_A3_MN_SCLKG_DIVS, (((ucdiv2) << 7) | ((ucdivs) << 0)));

    // Set DPPLL Div_O.
    ScalerSetBit(PA_BD_MN_SCLKG_PLL_PWR, ~(_BIT1 | _BIT0), ucpllo);

    // Offset Value Setting
    ScalerSetByte(PA_A6_MN_SCLKG_OFFS_L, (BYTE)lOffsetValue);
    ScalerSetByte(PA_A5_MN_SCLKG_OFFS_M, (BYTE)(lOffsetValue >> 8));
    ScalerSetBit(PA_A4_MN_SCLKG_OFFS_H, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)(lOffsetValue >> 16)) & (_BIT2 | _BIT1 | _BIT0));

    // Enable phase swallow
    ScalerSetBit(PA_B8_MN_SCLKG_SDM_CTRL, ~(_BIT5 | _BIT4), 0x00);
    ScalerSetBit(PA_B8_MN_SCLKG_SDM_CTRL, ~(_BIT5 | _BIT4), _BIT4);

    // Set DPPLL M Code
    ScalerSetBit(PA_A0_MN_SCLKG_CTRL, ~(_BIT1 | _BIT0), (((ulpllm - 2) >> 8) & 0x03));
    ScalerSetByte(PA_A1_MN_SCLKG_DIVM, ((ulpllm - 2) & 0xFF));

    // Set DPPLL N Code
    ScalerSetByte(PA_A2_MN_SCLKG_DIVN, (ucplln - 2));

    // Load offset value
    ScalerSetBit(PA_A4_MN_SCLKG_OFFS_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3), _BIT7);

    // Double Buffer for M/N Tracking
    ScalerSetBit(PA_A0_MN_SCLKG_CTRL, ~_BIT4, _BIT4);

    // DPLL VCORSTB Set to Normal
    ScalerSetBit(PA_C0_MN_SCLKG_PLL_INSEL, ~_BIT0, _DPLL_VCORSTB_NORMAL_VALUE);

    // DPLL Power On
    ScalerSetBit(PA_BD_MN_SCLKG_PLL_PWR, ~_BIT7, 0x00);

    ScalerTimerDelayXms(2);

    ////////////////////////////////
    // DPPLL VCO Band Calibration //
    ////////////////////////////////

    // Reg DPLL_CMPEN
    ScalerSetBit(PA_BD_MN_SCLKG_PLL_PWR, ~_BIT2, _BIT2);

    ScalerTimerDelayXms(2);

    // Reg DPLL_CALLCH
    ScalerSetBit(PA_BD_MN_SCLKG_PLL_PWR, ~_BIT3, _BIT3);

    ScalerTimerDelayXms(2);

    // Reg DPLL_CALSW
    ScalerSetBit(PA_BD_MN_SCLKG_PLL_PWR, ~_BIT4, _BIT4);

    // VCO Band : 01 ---> KVCO = 1340
    // VCO Band : 10 ---> KVCO = 1880
    // VCO Band : 11 ---> KVCO = 2340
    // R : 13
    // Icp = 6.28 * 700 * M / KVCO / R
    // Icp   = 2.5u + D0[0] * 2.5u + D0[1] * 5u + D0[2] * 10u (A)
    // Icp = 2.5uA, 5uA, 7.5uA, 10uA......
    if(ScalerGetBit(PA_C0_MN_SCLKG_PLL_INSEL, (_BIT5 | _BIT4)) == _BIT5)
    {
        pData[5] = 4396 * ulpllm / 1880 / 13;
    }
    else if(ScalerGetBit(PA_C0_MN_SCLKG_PLL_INSEL, (_BIT5 | _BIT4)) == (_BIT5 | _BIT4))
    {
        pData[5] = 4396 * ulpllm / 2340 / 13;
    }
    else
    {
        // For ICP default Setting
        pData[5] = 4396 * ulpllm / 1340 / 13;
    }

    pData[5] = ((20 * pData[5]) + 25) / 50;
    pData[5] -= (pData[5] == 0) ? 0 : 1;

    // Set PLL Charge Pump Current
    ScalerSetByte(PA_BE_MN_SCLKG_PLL_CHP, (0x78 | (pData[5] & 0x07)));

    /*
    ////////////////////////////////
    // DPPLL M/N Tracking Setting //
    ////////////////////////////////

    // Don't Use M/N Tracking for Nvid > 0x40000 or Nvid < 0xFF

    //////////////////// Enable M/N auto tracking /////////////////////////
    // I = (2^22)*( (Tdds / Tmn) * (1 / n), n = 8
    // 1. Fdds = 1/4 * Fvco = (ulLinkClkValue / 8) * (ulpllm / ucplln) / 4 --> Tdds = (32 / ulLinkClkValue) * (plln / ulpllm)
    // 2. Tmn = Nvid * (1 / ulLinkClkValue)
    // from1,2 we can get : I = (2^27) * (ucplln / ulpllm) / Nvid / n = (2^24) * (ucplln / ulpllm) / Nvid

    ulIcodeValue = (16777216 / ulDpNvidValue) * ucplln / ulpllm;  //I = (2^24) * (ucplln / ulpllm) / Nvid

    ScalerSetBit(PA_A8_MN_SCLKG_TRK_MN_I_H, ~(_BIT2 | _BIT1 | _BIT0), ((BYTE)(ulIcodeValue >> 16) & 0x03));
    ScalerSetByte(PA_A9_MN_SCLKG_TRK_MN_I_M, (BYTE)(ulIcodeValue >> 8));
    ScalerSetByte(PA_AA_MN_SCLKG_TRK_MN_I_L, (BYTE)ulIcodeValue);

    // Set P Code
    ScalerSetBit(PA_AB_MN_SCLKG_TRK_MN_P_H, ~(_BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1 | _BIT0));
    ScalerSetByte(PA_AC_MN_SCLKG_TRK_MN_P_M, 0xFF);
    ScalerSetByte(PA_AD_MN_SCLKG_TRK_MN_P_L, 0xFF);
    */

    ////////////////////////////////////////
    // DPPLL HS Tracking Tracking Setting //
    ////////////////////////////////////////

    // Disable Tracking New Mode
    ScalerSetBit(PA_B8_MN_SCLKG_SDM_CTRL, ~(_BIT2 | _BIT1), _BIT1);

    // Set Initial I/P Code
    ScalerSetByte(PA_B1_MN_SCLKG_TRK_VS_I_M, 0x00);
    ScalerSetByte(PA_B2_MN_SCLKG_TRK_VS_I_L, 0x04);
    ScalerSetByte(PA_B3_MN_SCLKG_TRK_VS_P_H, 0x07);
    ScalerSetByte(PA_B4_MN_SCLKG_TRK_VS_P_M, 0xFF);
    ScalerSetByte(PA_B5_MN_SCLKG_TRK_VS_P_L, 0xFF);

    // Get How Many Lines per SSC Period
    pData[0] = ulStreamClkValue / usDpHtotal / 33000;

    if(pData[0] > 15)
    {
        pData[0] = 15;
    }

    // Set Tracking Freq
    ScalerSetBit(PA_A8_MN_SCLKG_TRK_MN_I_H, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (pData[0] << 4));

    // Set Tracking Lock PE
    ScalerSetByte(PA_B7_MN_SCLKG_TRK_VS_NLOCK, 0x7F);

    // Enable H Sync Tracking
    ScalerSetByte(PA_A7_MN_SCLKG_TRK_CTRL, 0x58);

    // Double Buffer for H Sync Tracking
    ScalerSetBit(PA_A0_MN_SCLKG_CTRL, ~_BIT4, _BIT4);

    // Get Frame Period
    pData[15] = 1000 / (ulStreamClkValue / usDpHtotal / usDpVtotal) + 1;

    pData[0] = 0;
    // Waiting for Stream Clk Stable
    do
    {
        // Clear PE Flag
        ScalerSetBit(PA_B7_MN_SCLKG_TRK_VS_NLOCK, ~_BIT7, _BIT7);
        ScalerTimerDelayXms(pData[15]);

        pData[0]++;
    }
    while((ScalerGetBit(PA_B7_MN_SCLKG_TRK_VS_NLOCK, _BIT7) == _BIT7) && (pData[0] < 10));

    // Set Final I/P Code
    ScalerSetByte(PA_B1_MN_SCLKG_TRK_VS_I_M, 0x00);
    ScalerSetByte(PA_B2_MN_SCLKG_TRK_VS_I_L, 0x02);

    // Start Generate Display Format
    ScalerSetBit(PA_35_DPF_CTRL_0, ~_BIT7, _BIT7);

    // Polling Vertical BS
    ScalerTimerPollingFlagProc(50, PA_29_MST2SST_VBID, _BIT0, _TRUE);

    // Only Enable Tracking at Active Region when PE is Small
    PDATA_WORD(0) = ulVBs2BsCount / usDpVtotal / 2;

    ScalerSetBit(PA_C2_HS_TRACKING_NEW_MODE1, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (pData[0] & 0x0F));
    ScalerSetByte(PA_C3_HS_TRACKING_NEW_MODE2, pData[1]);

    // Enable Tracking New Mode
    ScalerSetBit(PA_B8_MN_SCLKG_SDM_CTRL, ~(_BIT2 | _BIT1), _BIT2);

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check Dp Interlace by VBID or Measure
// Input Value  : None
// Output Value : True --> Interlace
//--------------------------------------------------
bit ScalerDpRx0MstToSstInterlaceCheck(WORD *pusVTotal, BYTE *pucOddFlg)
{
    DWORD ulLinkClk = 0;
    WORD usTempVTotal = *pusVTotal;
    WORD usHTotalCount = 0;
    WORD usVsyncWidth = 0;
    WORD usVstart = 0;
    WORD usVactive = 0;

    // Set Vfront Porch
    SET_DP_RX0_MST_TO_SST_VFRONT_PORCH(_DP_VSYNC_FRONT_PORCH);

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_DP_MST_FREESYNC_ENABLED() == _TRUE)
    {
        // Field inverse disable
        ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT4, 0x00);

        if(ScalerGetBit(PA_29_MST2SST_VBID, _BIT2) == _BIT2) // Interlace
        {
            // Start to Measure Vertical BS to BS Counter by GDI Clock
            ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
            ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

            if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PA_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
            {
                return _FALSE;
            }

            // Pop up The result
            ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

            // Get Measure Result
            ScalerRead(PA_58_MN_MEAS_CTRL, 3, &pData[5], _AUTOINC);

            // Delay 2ms To Get VBID
            ScalerTimerDelayXms(2);

            // Get VBID
            ScalerRead(PA_29_MST2SST_VBID, 1, &pData[1], _NON_AUTOINC);

            // Delay 1 frame
            ScalerTimerDelayXms((((PDATA_DWORD(1) & 0x001FFFFF) / (_GDI_CLK_KHZ)) + 2));

            // Pop up Measure Result
            ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

            // Get Measure Result
            ScalerRead(PA_58_MN_MEAS_CTRL, 3, &pData[9], _AUTOINC);

            // Get VBID
            ScalerRead(PA_29_MST2SST_VBID, 1, &pData[2], _NON_AUTOINC);

            PDATA_DWORD(1) = (PDATA_DWORD(1) & 0x001FFFFF);
            PDATA_DWORD(2) = (PDATA_DWORD(2) & 0x001FFFFF);

            if((pData[1] & _BIT1) != (pData[2] & _BIT1))
            {
                // Enable DP Interlace, Field Information reference to VBID
                ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), _BIT7);

                if((ScalerGetBit(PA_56_INTERLACE_MODE_CONFIG, _BIT0) == 0x00) &&
                   ((((pData[1] & _BIT1) == _BIT1) && ((pData[2] & _BIT1) == 0x00) && (PDATA_DWORD(1) < PDATA_DWORD(2))) ||
                    (((pData[1] & _BIT1) == 0x00) && ((pData[2] & _BIT1) == _BIT1) && (PDATA_DWORD(1) > PDATA_DWORD(2)))))
                {
                    // Field inverse enable
                    ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT4, _BIT4);
                }
            }
            else
            {
                // Enable interlace mode, field reference HW
                ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));
            }

            *pusVTotal = usTempVTotal;

            return _TRUE;
        }
    }
    else
#endif
    {
        // [5] ln_ck_sel = 1'b1 -> CDR Clock
        // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

        // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
        ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

        // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
        ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

        // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

        // Waiting for Measure Done
        ScalerTimerDelayXms(2);

        if(ScalerGetBit(PB_50_DP_SIG_DET_0, _BIT6) == _BIT6)
        {
            PDATA_WORD(0) = ((((WORD)ScalerGetByte(PB_53_DP_SIG_DET_3)) << 8) | ScalerGetByte(PB_54_DP_SIG_DET_4));
        }
        else
        {
            if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR2)
            {
                PDATA_WORD(0) = 0x4E20;
            }
            else if(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == _DP_LINK_HBR)
            {
                PDATA_WORD(0) = 0x2710;
            }
            else // Both Default && _DP_LINK_RBR Case
            {
                PDATA_WORD(0) = 0x1770;
            }
        }

        // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

        PDATA_DWORD(0) = (((DWORD)PDATA_WORD(0)) * _GDI_CLK_KHZ);

        // Link Clk in KHz
        ulLinkClk = (PDATA_DWORD(0) / 1000);

        DebugMessageRx0("Current Link Clk", ulLinkClk);

        // Field inverse disable
        ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT4, 0x00);

        // Start to Measure Vertical BS to BS Counter by GDI Clock
        ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
        ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

        if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PA_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
        {
            return _FALSE;
        }

        // Pop up The result
        ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

        // Get Measure Result
        ScalerRead(PA_58_MN_MEAS_CTRL, 3, &pData[5], _AUTOINC);

        // Delay 2ms To Get VBID
        ScalerTimerDelayXms(2);

        // Get VBID
        ScalerRead(PA_29_MST2SST_VBID, 1, &pData[1], _NON_AUTOINC);

        // Delay 1 frame
        ScalerTimerDelayXms((((PDATA_DWORD(1) & 0x001FFFFF) / (_GDI_CLK_KHZ)) + 2));

        // Pop up Measure Result
        ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

        // Get Measure Result
        ScalerRead(PA_58_MN_MEAS_CTRL, 3, &pData[9], _AUTOINC);

        // Get Measure Htotal Counts
        ScalerRead(PA_5B_MN_MEAS_HLN_M, 2, &pData[12], _AUTOINC);

        // Get VBID
        ScalerRead(PA_29_MST2SST_VBID, 1, &pData[2], _NON_AUTOINC);

        PDATA_DWORD(1) = (PDATA_DWORD(1) & 0x001FFFFF);
        PDATA_DWORD(2) = (PDATA_DWORD(2) & 0x001FFFFF);

        // Convert HTotal Count from 1/2 Link Clk to GDI Clk
        usHTotalCount = ((DWORD)PDATA_WORD(6) * _GDI_CLK_KHZ * 2 + (ulLinkClk >> 1)) / ulLinkClk;

        DebugMessageRx0("HTotal Count", usHTotalCount);

        // if VTotal Difference > 1/2 HTotal
        if((ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))) > (usHTotalCount / 2))
        {
            if(PDATA_DWORD(1) < PDATA_DWORD(2))
            {
                usTempVTotal = ((PDATA_DWORD(1) * 8 + (usHTotalCount >> 1)) / usHTotalCount);
            }
            else
            {
                usTempVTotal = ((PDATA_DWORD(2) * 8 + (usHTotalCount >> 1)) / usHTotalCount);
            }

            usTempVTotal = (usTempVTotal + 4) / 8;

            *pucOddFlg = _TRUE;
        }
        else
        {
            *pucOddFlg = _FALSE;
        }

        DebugMessageRx0("####Calculated usVTotal####", usTempVTotal);

        DebugMessageRx0("7. DelayTime", (((PDATA_DWORD(1) & 0x000FFFFF) / (_GDI_CLK_KHZ)) + 2));
        DebugMessageRx0("7. PDATA_DWORD(1)", PDATA_DWORD(1));
        DebugMessageRx0("7. PDATA_DWORD(2)", PDATA_DWORD(2));
        DebugMessageRx0("7. PDATA_DWORD(ABS)", (ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))));

        if(ScalerGetBit(PA_29_MST2SST_VBID, _BIT2) == _BIT2) // Interlace
        {
            // Get VSW
            usVsyncWidth = ((WORD)ScalerGetByte(PA_1E_MSA_VSW_0) << 8) | ScalerGetByte(PA_1F_MSA_VSW_1);
            usVsyncWidth &= 0x7FFF;

            // Get VStart
            usVstart = ((WORD)ScalerGetByte(PA_1A_MSA_VST_0) << 8) | ScalerGetByte(PA_1B_MSA_VST_1);

            // Enable DP Interlace
            ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT7, _BIT7);

            if((*pucOddFlg) == _FALSE)
            {
                // Disable DP Interlace
                ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT7, 0x00);
            }

            // usVbackporch = usVstart - Fixed V-Sync Pulse Width, usVbackporch > usVsyncWidth + 2 lines, here 2 lines is for V-Sync Falling edge to DEN Rising Edge distance margion
            if(((pData[1] & _BIT1) != (pData[2] & _BIT1)) && (usVstart > (usVsyncWidth + _DP_VSYNC_WIDTH + 2)))
            {
                // Field Information reference to VBID
                ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT6, 0x00);

                // Get Vactive
                usVactive = ((WORD)ScalerGetByte(PA_1C_MSA_VHT_0) << 8) | ScalerGetByte(PA_1D_MSA_VHT_1);

                // Set Front Porch = VTotal - Active height - MSA V Start + V Sync Pulse Width
                SET_DP_RX0_MST_TO_SST_VFRONT_PORCH(usTempVTotal - usVactive - usVstart + usVsyncWidth);

                if((ScalerGetBit(PA_56_INTERLACE_MODE_CONFIG, _BIT0) == 0x00) &&
                   ((((pData[1] & _BIT1) == _BIT1) && ((pData[2] & _BIT1) == 0x00) && (PDATA_DWORD(1) < PDATA_DWORD(2))) ||
                    (((pData[1] & _BIT1) == 0x00) && ((pData[2] & _BIT1) == _BIT1) && (PDATA_DWORD(1) > PDATA_DWORD(2)))))
                {
                    // Field inverse enable
                    ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT4, _BIT4);
                }
            }
            else
            {
                // Field reference HW
                ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~_BIT6, _BIT6);
            }

            *pusVTotal = usTempVTotal;

            return _TRUE;
        }
        else if((ABSDWORD(PDATA_DWORD(1), PDATA_DWORD(2))) > (usHTotalCount / 2))
        {
            // Enable interlace mode, field reference HW
            ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

            *pusVTotal = usTempVTotal;

            return _TRUE;
        }
    }

    // Disable interlace mode, field reference HW
    ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), 0x00);

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP MST2SST Display Format Generator Setting
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx0MstToSstDisplayFormatSetting(void)
{
    BYTE ucOddFlg = 0;
    WORD usDpVtotal = 0;
    WORD usDpHactive = 0;
    DWORD ulStreamClkValue = 0;
    DWORD ulVBs2BsCount = 0;

#if(_DP_FREESYNC_SUPPORT == _ON)
    WORD usHBs2BsCount = 0;
    DWORD ulDpMvidValue = 0;
    DWORD ulDpNvidValue = 0;
#endif

    // Measurement Enable
    ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, 0x00);
    ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT7, _BIT7);

    if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PA_58_MN_MEAS_CTRL, _BIT6, _TRUE) == _FALSE)
    {
        return _FALSE;
    }

    // Pop up The result
    ScalerSetBit(PA_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    ulVBs2BsCount = ((((DWORD)(ScalerGetByte(PA_58_MN_MEAS_CTRL) & 0x1F)) << 16) | (((DWORD)ScalerGetByte(PA_59_MN_MEAS_VLN_M)) << 8) | ((DWORD)ScalerGetByte(PA_5A_MN_MEAS_VLN_L)));

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_DP_MST_FREESYNC_ENABLED() == _TRUE)
    {
        // HBs2Bs count in Link Clk / 2
        usHBs2BsCount = (((DWORD)ScalerGetByte(PA_5B_MN_MEAS_HLN_M)) << 8) | ((DWORD)ScalerGetByte(PA_5C_MN_MEAS_HLN_L));

        // VTotal in line, Link Clk / 2 : (Link Rate * 27 / 2)
        usDpVtotal = ulVBs2BsCount * (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) * 27 / 2) / usHBs2BsCount * 1000 / _GDI_CLK_KHZ;

        ulDpMvidValue = ((((DWORD)ScalerGetByte(PA_20_MSA_MVID_00)) << 16) | (((DWORD)ScalerGetByte(PA_21_MSA_MVID_01)) << 8) | ((DWORD)ScalerGetByte(PA_22_MSA_MVID_02)));

        ulDpNvidValue = ((((DWORD)ScalerGetByte(PA_23_MSA_NVID_00)) << 16) | (((DWORD)ScalerGetByte(PA_24_MSA_NVID_01)) << 8) | ((DWORD)ScalerGetByte(PA_25_MSA_NVID_02)));

        // [5] ln_ck_sel = 1'b1 -> CDR Clock
        // [3:0] DP_XTAL_CYCLE = 4'b0100 -> XTAL Counter Cycles = 2000
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~(_BIT5 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT2));

        // [1:0] freqdet_lane_sel = 2'b00 -> Lane0
        ScalerSetBit(PB_51_DP_SIG_DET_1, ~(_BIT1 | _BIT0), _D0_DP_LANE0);

        // [6] LANE_COUNT_CLEAR = 0 -> Keep the LANE_COUNT value
        ScalerSetBit(PB_52_DP_SIG_DET_2, ~_BIT6, 0x00);

        // [7] DP_SIG_DET_EN = 1'b1 -> Enable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, _BIT7);

        // Waiting for Measure Done
        ScalerTimerDelayXms(2);

        PDATA_DWORD(0) = (((DWORD)(ScalerGetByte(PB_52_DP_SIG_DET_2) & 0x3F) << 16) |
                          (ScalerGetByte(PB_53_DP_SIG_DET_3) << 8) |
                          (ScalerGetByte(PB_54_DP_SIG_DET_4)));

        // [7] DP_SIG_DET_EN = 0 -> Disable Signal Detection
        ScalerSetBit(PB_50_DP_SIG_DET_0, ~_BIT7, 0x00);

        PDATA_DWORD(0) = ((DWORD)PDATA_DWORD(0)) * _GDI_CLK_KHZ;

        // Calculate streamclk
        ulStreamClkValue = ((DWORD)ulDpMvidValue * (PDATA_DWORD(0) / ulDpNvidValue) + (PDATA_DWORD(0) % ulDpNvidValue * 100 / ulDpNvidValue * (DWORD)ulDpMvidValue / 100));
    }
    else
#endif
    {
        usDpVtotal = ((((WORD)ScalerGetByte(PA_18_MSA_VTT_0)) << 8) | ((WORD)ScalerGetByte(PA_19_MSA_VTT_1)));

        // Calculate streamclk (Unit is Hz)
        ulStreamClkValue = (((((((DWORD)ScalerGetByte(PA_10_MSA_HTT_0)) << 8) | ((WORD)ScalerGetByte(PA_11_MSA_HTT_1))) * ((DWORD)usDpVtotal) * 100) / ulVBs2BsCount) * _GDI_CLK_KHZ * 10);
    }

    // Input Pixel CLK Unit is 0.1 M
    SET_DP_TX_INPUT_PIXEL_CLK(ulStreamClkValue / 100000);

    // Disable Generate Display Format
    ScalerSetBit(PA_35_DPF_CTRL_0, ~_BIT7, 0x00);

    // DP Display Format Generator Reset
    ScalerSetBit(PA_00_MST2SST_RESET, ~_BIT0, _BIT0);
    ScalerSetBit(PA_00_MST2SST_RESET, ~_BIT0, 0x00);

    // Set Vactive
    ScalerRead(PA_1C_MSA_VHT_0, 2, &pData[4], _AUTOINC);
    ScalerSetByte(PA_4C_MN_DPF_VHT_M, pData[4]);
    ScalerSetByte(PA_4D_MN_DPF_VHT_L, pData[5]);

    // Set Hactive
    ScalerRead(PA_14_MSA_HWD_0, 2, pData, _AUTOINC);
    ScalerSetByte(PA_44_MN_DPF_HWD_M, pData[0]);
    ScalerSetByte(PA_45_MN_DPF_HWD_L, pData[1]);
    usDpHactive = PDATA_WORD(0);

#if(_DP_FREESYNC_SUPPORT == _ON)
    if(GET_DP_MST_FREESYNC_ENABLED() == _TRUE)
    {
        // HTotal in Pixel Clk, Link Clk / 2 : (Link Rate * 27 / 2)
        WORD usDpHtotal = (DWORD)usHBs2BsCount * (GET_DP_TX_INPUT_PIXEL_CLK() / 10) / (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) * 27 / 2);

        // Set Htotal
        ScalerSetByte(PA_40_MN_DPF_HTT_M, HIBYTE(usDpHtotal));
        ScalerSetByte(PA_41_MN_DPF_HTT_L, LOBYTE(usDpHtotal));

        // Set Hstart
        ScalerSetByte(PA_42_MN_DPF_HST_M, HIBYTE(_DP_DE_ONLY_MODE_HSTART));
        ScalerSetByte(PA_43_MN_DPF_HST_L, LOBYTE(_DP_DE_ONLY_MODE_HSTART));

        // Set HSW
        ScalerSetByte(PA_46_MN_DPF_HSW_M, HIBYTE(_DP_DE_ONLY_MODE_HSW));
        ScalerSetByte(PA_47_MN_DPF_HSW_L, LOBYTE(_DP_DE_ONLY_MODE_HSW));

        // Set Vstart
        ScalerSetByte(PA_4A_MN_DPF_VST_M, HIBYTE(_DP_DE_ONLY_MODE_VSTART));
        ScalerSetByte(PA_4B_MN_DPF_VST_L, LOBYTE(_DP_DE_ONLY_MODE_VSTART));

        // Set VSW
        ScalerSetByte(PA_4E_MN_DPF_VSW_M, HIBYTE(_DP_DE_ONLY_MODE_VSW));
        ScalerSetByte(PA_4F_MN_DPF_VSW_L, LOBYTE(_DP_DE_ONLY_MODE_VSW));

        PDATA_WORD(0) = ScalerDpRx0MstToSstGetBStoHSDelay(usDpHtotal);

        // Set HBs2Bs
        ScalerSetByte(PA_3D_BS2HS_0, pData[0]);
        ScalerSetByte(PA_3E_BS2HS_1, pData[1]);

        ScalerDpRx0MstToSstInterlaceCheck(&usDpVtotal, &ucOddFlg);

        // Set DE Only Mode Vsync Front Porch
        ScalerSetByte(PA_3F_VS_FRONT_PORCH, GET_DP_RX0_VFRONT_PORCH());

        // Set DE Only Mode
        ScalerSetBit(PA_35_DPF_CTRL_0, ~(_BIT7 | _BIT5 | _BIT4), _BIT4);

        if(ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE)
        {
            // Choose Frame start BE to Reset FIFO
            ScalerSetBit(PA_30_PG_CTRL_0, ~_BIT5, _BIT5);
        }
        else
        {
            // Choose vsync posedge to Reset FIFO
            ScalerSetBit(PA_30_PG_CTRL_0, ~_BIT5, 0x00);
        }

        // Set DP FREESYNC Mode Enable
        ScalerSetBit(PA_F0_DP_RSV0, ~_BIT0, _BIT0);

        DebugMessageRx0("MST FREESYNC Mode Enabled!!", 0);
    }
    else
#endif
    {
        DWORD ulBs2VsDelay = 0;

        // Set Htotal
        ScalerRead(PA_10_MSA_HTT_0, 2, &pData[2], _AUTOINC);
        ScalerSetByte(PA_40_MN_DPF_HTT_M, pData[2]);
        ScalerSetByte(PA_41_MN_DPF_HTT_L, pData[3]);

        // Get HSW
        pData[4] = ScalerGetBit(PA_16_MSA_HSW_0, (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
        pData[5] = ScalerGetByte(PA_17_MSA_HSW_1);

        // Get HSW min by Measure clock
        PDATA_WORD(3) = ((DWORD) _DP_HSYNC_WIDTH_MEASURE_COUNTER * GET_DP_TX_INPUT_PIXEL_CLK() * 100) / _MEASURE_CLK + 1;

        // Check HSW <= HSW min
        if(PDATA_WORD(2) <= PDATA_WORD(3))
        {
            // Check if H porch is more than HSW min
            if((PDATA_WORD(1) - usDpHactive) >= PDATA_WORD(3))
            {
                // HSW = HSW min
                PDATA_WORD(2) = PDATA_WORD(3);
            }
            else
            {
                // HSW = Max H Porch
                PDATA_WORD(2) = (PDATA_WORD(1) - usDpHactive);
            }
        }

        // DPF H Front Porch must not be less than 8 (HW constraint)
        // Check if H porch is more than 8
        if((PDATA_WORD(1) - usDpHactive - PDATA_WORD(2)) <= _DP_HSYNC_FRONT_PORCH)
        {
            // HSW < HSW min
            if(PDATA_WORD(2) < PDATA_WORD(3))
            {
                // Hstart = HSW
                PDATA_WORD(4) = PDATA_WORD(2);
            }
            else if((PDATA_WORD(1) - usDpHactive - PDATA_WORD(3) >= _DP_HSYNC_FRONT_PORCH))
            {
                // HSW = H porch - _DP_HSYNC_FRONT_PORCH
                PDATA_WORD(2) = PDATA_WORD(1) - usDpHactive - _DP_HSYNC_FRONT_PORCH;

                // Hstart = HSW
                PDATA_WORD(4) = PDATA_WORD(2);
            }
            else
            {
                // HSW = HSW min
                PDATA_WORD(2) = PDATA_WORD(3);

                // Hstart = HSW min
                PDATA_WORD(4) = PDATA_WORD(3);
            }
        }
        else
        {
            // Hstart = Htotal - Hactive - _DP_HSYNC_FRONT_PORCH
            PDATA_WORD(4) = PDATA_WORD(1) - usDpHactive - _DP_HSYNC_FRONT_PORCH;
        }

        // Set HSW and HSP => positive
        ScalerSetByte(PA_46_MN_DPF_HSW_M, (pData[4] & ~_BIT7));
        ScalerSetByte(PA_47_MN_DPF_HSW_L, pData[5]);

        // Set Hstart
        ScalerSetByte(PA_42_MN_DPF_HST_M, pData[8]);
        ScalerSetByte(PA_43_MN_DPF_HST_L, pData[9]);

        DebugMessageRx0("###Origin usVTotal###", usDpVtotal);

        if(ScalerDpRx0MstToSstInterlaceCheck(&usDpVtotal, &ucOddFlg) == _TRUE) // Interlace
        {
            SET_DP_TX_INPUT_INTERLACE_MODE(_ON);
        }
        else // Progressive
        {
            // Disable DP Interlace
            ScalerSetBit(PA_56_INTERLACE_MODE_CONFIG, ~(_BIT7 | _BIT6), 0x00);

            SET_DP_TX_INPUT_INTERLACE_MODE(_OFF);
        }

        // Set Vtotal
        ScalerSetByte(PA_48_MN_DPF_VTT_M, (usDpVtotal >> 8));
        ScalerSetByte(PA_49_MN_DPF_VTT_L, (usDpVtotal & 0xFF));

        // Get Vactive
        ScalerRead(PA_1C_MSA_VHT_0, 2, &pData[4], _AUTOINC);

        // V Front porch must not be less than 2 because of V scaling down.
        // Set Vstart -> (Vtotal - Vactive - Frontporch)
        PDATA_WORD(0) = usDpVtotal - PDATA_WORD(2) - GET_DP_RX0_MST_TO_SST_VFRONT_PORCH();
        ScalerSetByte(PA_4A_MN_DPF_VST_M, pData[0]);
        ScalerSetByte(PA_4B_MN_DPF_VST_L, pData[1]);

        // Set VSW; Set VSP => Positive
        ScalerSetByte(PA_4E_MN_DPF_VSW_M, (HIBYTE(_DP_VSYNC_WIDTH) & ~_BIT7));
        ScalerSetByte(PA_4F_MN_DPF_VSW_L, LOBYTE(_DP_VSYNC_WIDTH));

        ulBs2VsDelay = ScalerDpRx0MstToSstGetBStoVSDelay();

        // Set Odd Field BS to VS Delay
        ScalerSetByte(PA_3A_OVBLK2VS_H, (BYTE)(ulBs2VsDelay >> 16));
        ScalerSetByte(PA_3B_OVBLK2VS_M, (BYTE)(ulBs2VsDelay >> 8));
        ScalerSetByte(PA_3C_OVBLK2VS_L, (BYTE)(ulBs2VsDelay >> 0));

        if((bit)ucOddFlg == _TRUE)
        {
            // Get Htotal
            ScalerRead(PA_10_MSA_HTT_0, 2, &pData[0], _AUTOINC);

            // BStoVSDelay = BStoVSDelay + (Link Clk * 256 / Stream Clk) * ((DWORD)Htotal) / 256;
            ulBs2VsDelay += ((((DWORD)ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00)) * 270UL) * 256) / ((DWORD)GET_DP_TX_INPUT_PIXEL_CLK()) * ((DWORD)PDATA_WORD(0)) / 256 / 2;

            SET_DP_TX_INPUT_INTERLACE_VTOTAL_NUMBER(_ODD);
        }
        else
        {
            SET_DP_TX_INPUT_INTERLACE_VTOTAL_NUMBER(_EVEN);
        }

        // Set Even Field BS to VS Delay
        ScalerSetByte(PA_37_EVBLK2VS_H, (BYTE)(ulBs2VsDelay >> 16));
        ScalerSetByte(PA_38_EVBLK2VS_M, (BYTE)(ulBs2VsDelay >> 8));
        ScalerSetByte(PA_39_EVBLK2VS_L, (BYTE)(ulBs2VsDelay >> 0));

        // Choose VS Rising to Reset FIFO
        ScalerSetBit(PA_30_PG_CTRL_0, ~_BIT5, 0x00);

        // Set DP FREESYNC Mode Disable
        ScalerSetBit(PA_F0_DP_RSV0, ~_BIT0, 0x00);

        // Set full last line Mode
        ScalerSetBit(PA_35_DPF_CTRL_0, ~(_BIT7 | _BIT5 | _BIT4), 0x00);

        DebugMessageRx0("MST FREESYNC Mode Disabled!!", 0);
    }

    // Double Buffer to Apply Display Format Setting
    ScalerSetBit(PA_35_DPF_CTRL_0, ~_BIT6, _BIT6);

    ScalerDpRx0MstToSstVideoSetting();

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP MST2SST Video Fifo Check
// Input Value  : Fifo Check Condition
// Output Value : True --> Fifo not over/underflow
//--------------------------------------------------
bit ScalerDpRx0MstToSstFifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition)
{
#if(_DP_FREESYNC_SUPPORT == _ON)
    // Temp for C Version Bug
    if((GET_DP_MST_FREESYNC_ENABLED() == _TRUE) && (ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE))
    {
        return _TRUE;
    }
#endif

    if(enumFifoCheckCondition == _DP_FIFO_DELAY_CHECK)
    {
        ScalerSetBit(PA_31_PG_CTRL_1, ~_BIT0, _BIT0);

        ScalerTimerDelayXms(30);

        pData[0] = 0;

        while(pData[0] < 6)
        {
            ScalerTimerDelayXms(10);

            if((ScalerGetBit(PA_31_PG_CTRL_1, _BIT1) == _BIT1) || (ScalerGetBit(PA_31_PG_CTRL_1, _BIT0) == _BIT0))
            {
                return _FALSE;
            }

            pData[0]++;
        }
    }
    else
    {
        if((ScalerGetBit(PA_31_PG_CTRL_1, _BIT1) == _BIT1) || (ScalerGetBit(PA_31_PG_CTRL_1, _BIT0) == _BIT0))
        {
            return _FALSE;
        }
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : DP Rx0 MST to SST Measure
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx0MstToSstMeasureInput(void)
{
    // Format Conversion Select to SST_D0
    ScalerSetBit(P31_02_FC_INPUT_DPTX_SEL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_FC_SOURCE_SST_D0 << 4));

    return ScalerDpTxMeasureInputInfo();
}

//--------------------------------------------------
// Description  : Enable HDCP Read IRQ Function
// Input Value  : bEnable
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0HDCPEnableReadIrq(bit bEnable)
{
    if(bEnable == _ENABLE)
    {
        if(ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x2A) > 3)
        {
            ScalerSetBit(PB7_FA_DUMMY_0, ~_BIT2, _BIT2);
            ScalerSetBit(PB7_FA_DUMMY_0, ~_BIT2, 0x00);

            ScalerSetBit(PB7_FA_DUMMY_0, ~(_BIT3 | _BIT1), (_BIT3 | _BIT1));
        }
    }
    else
    {
        ScalerSetBit(PB7_FA_DUMMY_0, ~(_BIT3 | _BIT1), 0x00);

        CLR_DP_RX0_HDCP_AUTH_READ_IRQ_TIMEOUT();
    }
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)
#endif // End of #if(_DP_MST_SUPPORT == _ON)
#endif // End of #if(_D0_DP_EXIST == _ON)

