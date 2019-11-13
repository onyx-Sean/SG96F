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
// ID Code      : ScalerDPRx0_ComboPhy.c No.0000
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
#if(_D0_DP_EXIST == _ON)
BYTE g_ucDpRx0PhyCtsCtrl;
StructDpLanesMapping g_stDpRx0LanesMapping;
#endif

BYTE g_ucDpRx0EQCRC;
BYTE g_ucDpValidLaneCount;


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
void ScalerDpRx0ChangeDpcdVersion(EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
void ScalerDpRx0CpIRQ(EnumDpRxBStatusType enumBStatusType);
bit ScalerDpRx0DecodeCheck(void);
void ScalerDpRx0DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus);
bit ScalerDpRx0FifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
void ScalerDpRx0HPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHighStatus);
bit ScalerDpRx0HdcpCheck(void);
bit ScalerDpRx0HdcpEnebled(void);
bit ScalerDpRx0HdcpReAuthStatusCheck(void);
void ScalerDpRx0Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
void ScalerDpRx0SetDpLaneMapping(BYTE ucLanetype);
bit ScalerDpRx0MarginLinkCheck(void);
void ScalerDpRx0LinkStatusIRQ(void);
void ScalerDpRx0AuxDiffModeSet(void);
bit ScalerDpRx0PSPreDetect(void);
bit ScalerDpRx0PhyCtsTp2Check(void);
void ScalerDpRx0SetFifoIRQ(bit bEn);
void ScalerDpRx0SetFifoWD(bit bEn);
void ScalerDpRx0ValidSignalDetection(void);

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D0_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : Dp Version Switch
// Input Value  : _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0ChangeDpcdVersion(EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort)
{
    enumDpRxMstPort = _DP_MST_NO_PORT;

    if(enumDpVersion == _DP_VERSION_1_2)
    {
        // DPCD Version
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x00, 0x12);

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

        // Sink HW/FW Version
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x09, _DP_SINK_RTK_HW_VERSION);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x0A, _DP_SINK_RTK_FW_VERSION_H);
        ScalerDpRx0SetDpcdValue(0x00, 0x04, 0x0B, _DP_SINK_RTK_FW_VERSION_L);
    }
    else
    {
        // DPCD Version
        ScalerDpRx0SetDpcdValue(0x00, 0x00, 0x00, 0x11);

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

        // Sink IEEE OUI For DP1.1
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
    }
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
        // Reset HDCP Block
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT0, _BIT0);
        ScalerSetBit(PB_01_PHY_DIG_RESET_CTRL, ~_BIT0, 0x00);

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

                if(((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, _BIT0) == 0x00)) ||
                   ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, _BIT1) == 0x00)) ||
                   ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, _BIT2) == 0x00)) ||
                   ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, _BIT3) == 0x00)))
                {
                    return _TRUE;
                }

                break;

            case _DP_TWO_LANE:

                if(((((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1)) || ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0))) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT1 | _BIT0)) == 0x00)) ||
                   ((((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2)) || ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0))) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT2 | _BIT0)) == 0x00)) ||
                   ((((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE0) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3)) || ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE0))) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT3 | _BIT0)) == 0x00)) ||
                   ((((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2)) || ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1))) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT2 | _BIT1)) == 0x00)) ||
                   ((((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE1) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3)) || ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE1))) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT3 | _BIT1)) == 0x00)) ||
                   ((((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE2) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE3)) || ((GET_DP_RX0_PCB_LANE0_MAPPING() == _DP_SCALER_LANE3) && (GET_DP_RX0_PCB_LANE1_MAPPING() == _DP_SCALER_LANE2))) &&
                    (ScalerGetBit(PB_06_DECODE_10B8B_ERROR, (_BIT3 | _BIT2)) == 0x00)))
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
// Description  : DPCD Link Status Field Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus)
{
    pData[0] = ScalerGetByte(PB7_D0_AUX_MODE_SET);

    SET_DP_RX0_AUX_MANUAL_MODE();

    if(enumDpResetStatus == _DP_DPCD_LINK_STATUS_INITIAL)
    {
        // Set DPCD 00600h to 0x01
        ScalerDpRx0SetDpcdBitValue(0x00, 0x06, 0x00, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
    }

    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x04, 0x80);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x05, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x06, 0x00);
    ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x07, 0x00);

    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);

    CLR_DP_RX0_BACKUP_PD_LINK_STATUS_FLG();

    if((pData[0] & _BIT1) == _BIT1)
    {
        SET_DP_RX0_AUX_AUTO_MODE();
    }
}
//--------------------------------------------------
// Description  : DP Video Fifo Check
// Input Value  : Fifo Check Condition
// Output Value : True --> Fifo not over/underflow
//--------------------------------------------------
bit ScalerDpRx0FifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition)
{
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
#if(_DP_HDMI_COMPATIBLE_MODE == _ON)
        return;
#endif

#if(_DP_DELL_D3_TEST_SUPPORT == _OFF)
        if(ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) == _BIT0)
#endif
        {
            DebugMessageDigital("7. Long HPD Event", ucDpHotPlugDCOffHighStatus);

            ScalerDpRx0HotPlugEvent(_DP_LONG_HPD_EVENT);
        }
    }
    else
    {
        DebugMessageDigital("7. HPD Asserted", ucDpHotPlugDCOffHighStatus);

        ScalerDpRx0HotPlugEvent(_DP_HPD_ASSERTED);
    }
}
//--------------------------------------------------
// Description  : Check DP Link Integrity
// Input Value  : None
// Output Value : FALSE => DP Link Integrity Fail
//--------------------------------------------------
bit ScalerDpRx0HdcpCheck(void)
{
    if((ScalerGetByte(PB_1E_HDCP_INTGT_VRF_ANS_MSB) != 0x00) && (ScalerGetByte(PB_1F_HDCP_INTGT_VRF_ANS_LSB) != 0x00) &&
       (ScalerGetByte(PB_1E_HDCP_INTGT_VRF_ANS_MSB) != 0x53) && (ScalerGetByte(PB_1F_HDCP_INTGT_VRF_ANS_LSB) != 0x1F) &&
       (ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x0B) != 0x00))
    {
        if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x11) & _BIT2) == 0x00)
        {
            return _FALSE;
        }

        if(ScalerDpRx0HdcpMeasureCheck() == _FALSE)
        {
            return _FALSE;
        }
    }

    return _TRUE;
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
// Description  : Initial Setting for DP
// Input Value  : _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort)
{
    ScalerDpRx0AuxIntInitial();

    ScalerDpRx0DpcdInitial(enumDpVersion, enumDpLaneCount, enumDpRxMstPort);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    SET_DP_RX0_AUX_MANUAL_MODE();
    ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x0A, 0x00);
    SET_DP_RX0_AUX_AUTO_MODE();
#endif

    SET_DP_RX0_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);

    SET_DP_RX0_FAKE_LINK_TRAINING();

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    CLR_DP_RX_D0_MARGIN_LINK_HBR_RBR();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    CLR_DP_RX_D1_MARGIN_LINK_HBR_RBR();
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    CLR_DP_RX_D2_MARGIN_LINK_HBR_RBR();
#endif

    SET_DP_RX_TARGET_MST_PORT(enumDpRxMstPort);
    SET_DP_RX_D0_PORT_TARGET_VERSION(enumDpVersion);
    SET_DP_RX_D0_PORT_TARGET_LANE_COUNT(enumDpLaneCount);

    ScalerDpRx0SetDpLaneMapping(_DP_LANE_MAPPING_NORMAL_TYPE);
}

//--------------------------------------------------
// Description  : Set DP Lane Mapping Type
// Input Value  : ucLanetype --> Lane Mapping Type
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetDpLaneMapping(BYTE ucLanetype)
{
    if(ucLanetype == _DP_LANE_MAPPING_TYPE_C_ASSIGNMENT_E_TYPE)
    {
        // Lane 0 <--> Lane 2
        // Lane 1 <--> Lane 3
        SET_DP_RX0_PCB_LANE0_MAPPING(_D0_DP_PCB_LANE2_MAPPING);
        SET_DP_RX0_PCB_LANE1_MAPPING(_D0_DP_PCB_LANE3_MAPPING);
        SET_DP_RX0_PCB_LANE2_MAPPING(_D0_DP_PCB_LANE0_MAPPING);
        SET_DP_RX0_PCB_LANE3_MAPPING(_D0_DP_PCB_LANE1_MAPPING);
        SET_DP_RX0_PCB_LANE0_PN_SWAP(!_D0_DP_PCB_LANE0_PN_SWAP);
        SET_DP_RX0_PCB_LANE1_PN_SWAP(!_D0_DP_PCB_LANE1_PN_SWAP);
        SET_DP_RX0_PCB_LANE2_PN_SWAP(!_D0_DP_PCB_LANE2_PN_SWAP);
        SET_DP_RX0_PCB_LANE3_PN_SWAP(!_D0_DP_PCB_LANE3_PN_SWAP);

        // Enable Aux Digital Phy PN Swap
        ScalerSetBit(PB7_72_AUX_DIG_PHY2, ~_BIT0, _BIT0);
    }
    else // Normal Cable Mode
    {
        SET_DP_RX0_PCB_LANE0_MAPPING(_D0_DP_PCB_LANE0_MAPPING);
        SET_DP_RX0_PCB_LANE1_MAPPING(_D0_DP_PCB_LANE1_MAPPING);
        SET_DP_RX0_PCB_LANE2_MAPPING(_D0_DP_PCB_LANE2_MAPPING);
        SET_DP_RX0_PCB_LANE3_MAPPING(_D0_DP_PCB_LANE3_MAPPING);
        SET_DP_RX0_PCB_LANE0_PN_SWAP(_D0_DP_PCB_LANE0_PN_SWAP);
        SET_DP_RX0_PCB_LANE1_PN_SWAP(_D0_DP_PCB_LANE1_PN_SWAP);
        SET_DP_RX0_PCB_LANE2_PN_SWAP(_D0_DP_PCB_LANE2_PN_SWAP);
        SET_DP_RX0_PCB_LANE3_PN_SWAP(_D0_DP_PCB_LANE3_PN_SWAP);

        // Disable Aux Digital Phy PN Swap
        ScalerSetBit(PB7_72_AUX_DIG_PHY2, ~_BIT0, 0x00);
    }
}

//--------------------------------------------------
// Description  : DP Margin Link Check
// Input Value  : None
// Output Value : _TRUE : Link ok ; _FALSE : Margin Link
//--------------------------------------------------
bit ScalerDpRx0MarginLinkCheck(void)
{
    switch(ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00))
    {
        case _DP_LINK_RBR:
        case _DP_LINK_HBR:

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT)
            {
                if((GET_DP_RX_D0_MARGIN_LINK_HBR_RBR() == _FALSE) && (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
                {
                    return _FALSE;
                }
            }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT)
            {
                if((GET_DP_RX_D1_MARGIN_LINK_HBR_RBR() == _FALSE) && (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
                {
                    return _FALSE;
                }
            }
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if(GET_DP_EMBEDDED_SWITCH_SELECT() == _D2_INPUT_PORT)
            {
                if((GET_DP_RX_D2_MARGIN_LINK_HBR_RBR() == _FALSE) && (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
                {
                    return _FALSE;
                }
            }
#endif
            break;

        default:
            return _TRUE;
            break;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Dp Interrupt Request
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0LinkStatusIRQ(void)
{
    SET_DP_RX0_AUX_MANUAL_MODE();

    if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_FAIL) || (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
    {
        if((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) <= _DP_LINK_HBR) && (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
        {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
            if((GET_DP_EMBEDDED_SWITCH_SELECT() == _D0_INPUT_PORT) && (GET_D0_CABLE_STATUS() == _TRUE))
            {
                SET_DP_RX_D0_MARGIN_LINK_HBR_RBR();
            }
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
            if((GET_DP_EMBEDDED_SWITCH_SELECT() == _D1_INPUT_PORT) && (GET_D1_CABLE_STATUS() == _TRUE))
            {
                SET_DP_RX_D1_MARGIN_LINK_HBR_RBR();
            }
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
            if((GET_DP_EMBEDDED_SWITCH_SELECT() == _D2_INPUT_PORT) && (GET_D2_CABLE_STATUS() == _TRUE))
            {
                SET_DP_RX_D2_MARGIN_LINK_HBR_RBR();
            }
#endif
        }

        ScalerDpRx0DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_IRQ);

        SET_DP_RX0_AUX_AUTO_MODE();

        if((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != _BIT1) &&
           (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT0)))
        {
            ScalerDpRx0HotPlugDuration(_DP_HPD_IRQ_TIME);
        }
    }

    SET_DP_RX0_AUX_AUTO_MODE();
}

//-------------------------------------------------------
// Description  : Set Aux Diff mode or Single-eneded mode
// Input Value  : None
// Output Value : None
//-------------------------------------------------------
void ScalerDpRx0AuxDiffModeSet(void)
{
    if(GET_DP_AUX_DIFF_MODE() == _FALSE)
    {
        // Set TX VLDO, Open AUX ADJR_P, Rx Common Mode from 1.2V
        ScalerSetByte(PB7_61_AUX_1, 0xF0);

        // [5]Enable Single-Ended Mode, [4:3]Aux Vth-->50mV, [0]Aux 50ohm auto K(Enable Big_Z0_P)
        ScalerSetByte(PB7_62_AUX_2, 0x29);

        // [4]Enable Big_Z0_N, [3:0]Open ADJR_N
        ScalerSetBit(PB7_66_AUX_6, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    }
    else
    {
        // Set TX VLDO, Set AUX ADJR_P = 3, Rx Common Mode from 1.2V
        ScalerSetByte(PB7_61_AUX_1, 0xD3);

        // [5]Disable Single-Ended Mode, [4:3]Aux Vth-->50mV, [0]Aux 50ohm auto K(Enable Big_Z0_P)
        ScalerSetByte(PB7_62_AUX_2, 0x09);

        // [4]Enable Big_Z0_N, [3:0]Set ADJR_N = 3
        ScalerSetBit(PB7_66_AUX_6, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1 | _BIT0));
    }
}

//--------------------------------------------------
// Description  : Signal Detection for DP(Power Saving)
// Input Value  : None
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpRx0PSPreDetect(void)
{
    // Back to noraml for DP PHY CTS
    if(GET_DP_RX0_PHY_CTS_FLG() == _TRUE)
    {
        return _TRUE;
    }

    if(GET_DP_RX0_VALID_VIDEO_CHECK() == _TRUE)
    {
        DebugMessageRx0("7. Valid Video Check", 0);

        return _TRUE;
    }

    if(GET_DP_RX0_PS_AUX_TOGGLE() == _TRUE)
    {
        DebugMessageRx0("7. Power Saving Aux Handshake", 0);

        return _TRUE;
    }

    if(((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) &&
        ((ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != _BIT1) &&
         (ScalerDpRx0GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT0)))) ||
       (GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))

        if(ScalerAudioGetDigitalAudioSource(_D0_INPUT_PORT) == _DIGITAL_AUDIO_SOURCE_DP)
        {
            DebugMessageAudio("00. DP Power Saving Audio : Idle Pattern Case", ScalerAudioGetDigitalAudioSource(_D0_INPUT_PORT));
            return _TRUE;
        }
#endif
        DebugMessageRx0("7. Idle Pattern Case", 0);

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
// Description  : Enable DP Fifo Under/OverFlow IRQ
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetFifoIRQ(bit bEn)
{
    ScalerSetBit(PB6_3A_DP_IRQ_CTRL0, ~(_BIT1 | _BIT0), ((bEn == _ENABLE) ? (_BIT1 | _BIT0) : 0x00));
}
//--------------------------------------------------
// Description  : Enable DP Fifo Under/OverFlow Watch Dog
// Input Value  : _ENABLE/ DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0SetFifoWD(bit bEn)
{
    ScalerSetBit(PB6_38_DP_VWD_CTRL, ~(_BIT5 | _BIT4), ((bEn == _ENABLE) ? (_BIT5 | _BIT4) : 0x00));
}

//--------------------------------------------------
// Description  : Check Valid Video Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx0ValidSignalDetection(void)
{
    if(ScalerDpRx0ValidLaneCheck(_DP_LINK_HBR) == _TRUE)
    {
        SET_DP_RX0_AUX_MANUAL_MODE();

        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00))
        {
            ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x00, _DP_LINK_HBR);
            ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x01, ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x60) | (g_ucDpValidLaneCount | _BIT7)));

            if(g_ucDpValidLaneCount == _DP_FOUR_LANE)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x77);
            }
            else if(g_ucDpValidLaneCount == _DP_TWO_LANE)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x00);
            }
            else
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x07);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x00);
            }

            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x04, 0x01);

            SET_DP_RX0_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS_VBIOS);
        }

        SET_DP_RX0_AUX_AUTO_MODE();
    }
    else if(ScalerDpRx0ValidLaneCheck(_DP_LINK_RBR) == _TRUE)
    {
        SET_DP_RX0_AUX_MANUAL_MODE();

        if((GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x00) == 0x00))
        {
            ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x00, _DP_LINK_RBR);
            ScalerDpRx0SetDpcdValue(0x00, 0x01, 0x01, ((ScalerDpRx0GetDpcdInfo(0x00, 0x01, 0x01) & 0x60) | (g_ucDpValidLaneCount | _BIT7)));

            if(g_ucDpValidLaneCount == _DP_FOUR_LANE)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x77);
            }
            else if(g_ucDpValidLaneCount == _DP_TWO_LANE)
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x77);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x00);
            }
            else
            {
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x02, 0x07);
                ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x03, 0x00);
            }

            ScalerDpRx0SetDpcdValue(0x00, 0x02, 0x04, 0x01);

            SET_DP_RX0_LINK_TRAINING_STATUS(_DP_FAKE_LINK_TRAINING_PASS_VBIOS);
        }

        SET_DP_RX0_AUX_AUTO_MODE();
    }
}

#endif
