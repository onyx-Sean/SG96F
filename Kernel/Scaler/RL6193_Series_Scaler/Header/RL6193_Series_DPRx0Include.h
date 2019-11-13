/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : RL6193_Series_DPRx0Include.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//----------------------------------------------------------------------------
// Macro of Dp Link Training Information
//----------------------------------------------------------------------------
#define GET_DP_RX0_FAKE_LINK_TRAINING()                 ((g_ucDpRx0Info & _BIT7) >> 7)
#define SET_DP_RX0_FAKE_LINK_TRAINING()                 (g_ucDpRx0Info |= _BIT7)
#define CLR_DP_RX0_FAKE_LINK_TRAINING()                 (g_ucDpRx0Info &= ~_BIT7)

#define GET_DP_RX0_VALID_VIDEO_CHECK()                  ((g_ucDpRx0Info & _BIT6) >> 6)
#define SET_DP_RX0_VALID_VIDEO_CHECK()                  (g_ucDpRx0Info |= _BIT6)
#define CLR_DP_RX0_VALID_VIDEO_CHECK()                  (g_ucDpRx0Info &= ~_BIT6)

#define GET_DP_RX0_CRC_CALCULATE()                      ((g_ucDpRx0Info & _BIT5) >> 5)
#define SET_DP_RX0_CRC_CALCULATE()                      (g_ucDpRx0Info |= _BIT5)
#define CLR_DP_RX0_CRC_CALCULATE()                      (g_ucDpRx0Info &= ~_BIT5)

#define GET_DP_RX0_PS_AUX_TOGGLE()                      (g_bDpRx0PSAuxToggle)
#define SET_DP_RX0_PS_AUX_TOGGLE()                      (g_bDpRx0PSAuxToggle = _TRUE)
#define CLR_DP_RX0_PS_AUX_TOGGLE()                      (g_bDpRx0PSAuxToggle = _FALSE)

// Add for DPCD 2002h Bug
#define GET_DP_RX0_POWER_STATE_INTO_PS()                (g_bDpRx0PowerStateIntoPS)
#define SET_DP_RX0_POWER_STATE_INTO_PS()                (g_bDpRx0PowerStateIntoPS = _TRUE)
#define CLR_DP_RX0_POWER_STATE_INTO_PS()                (g_bDpRx0PowerStateIntoPS = _FALSE)

#define GET_DP_RX0_AUX_COMMAND_NO_REPLY()               (g_bDpRx0AuxCommandNoReply)
#define SET_DP_RX0_AUX_COMMAND_NO_REPLY()               (g_bDpRx0AuxCommandNoReply = _TRUE)
#define CLR_DP_RX0_AUX_COMMAND_NO_REPLY()               (g_bDpRx0AuxCommandNoReply = _FALSE)

#define GET_DP_RX0_PHY_CTS_FLG()                        (!((bit)ScalerGetBit(PB_A7_CMU_07, _BIT0)))
#define SET_DP_RX0_PHY_CTS_FLG()                        (ScalerSetBit(PB_A7_CMU_07, ~_BIT0, 0x00))
#define CLR_DP_RX0_PHY_CTS_FLG()                        (ScalerSetBit(PB_A7_CMU_07, ~_BIT0, _BIT0))

#if(_DP_MST_SUPPORT == _ON)
#define GET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE()     (g_stDpRx0MiscInfo.b1DpCheckAuxChNoPowerDebounce)
#define SET_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE()     (g_stDpRx0MiscInfo.b1DpCheckAuxChNoPowerDebounce = _TRUE)
#define CLR_DP_RX0_CHECK_AUX_CH_NO_POWER_DEBOUNCE()     (g_stDpRx0MiscInfo.b1DpCheckAuxChNoPowerDebounce = _FALSE)

#define GET_DP_RX0_CHECK_AUX_CH_POWER_OFF()             (g_stDpRx0MiscInfo.b1DpCheckAuxChPowerOff)
#define SET_DP_RX0_CHECK_AUX_CH_POWER_OFF()             (g_stDpRx0MiscInfo.b1DpCheckAuxChPowerOff = _TRUE)
#define CLR_DP_RX0_CHECK_AUX_CH_POWER_OFF()             (g_stDpRx0MiscInfo.b1DpCheckAuxChPowerOff = _FALSE)

#define GET_DP_RX0_AUX_CH_POWER_ON_WAKE_UP()            (g_stDpRx0MiscInfo.b1DpAuxChPowerOnWakeUp)
#define SET_DP_RX0_AUX_CH_POWER_ON_WAKE_UP()            (g_stDpRx0MiscInfo.b1DpAuxChPowerOnWakeUp = _TRUE)
#define CLR_DP_RX0_AUX_CH_POWER_ON_WAKE_UP()            (g_stDpRx0MiscInfo.b1DpAuxChPowerOnWakeUp = _FALSE)

#define GET_DP_RX0_SOURCE_FIRST_POWER_ON()              (g_stDpRx0MiscInfo.b1DpSourceFirstPowerOn)
#define SET_DP_RX0_SOURCE_FIRST_POWER_ON()              (g_stDpRx0MiscInfo.b1DpSourceFirstPowerOn = _TRUE)
#define CLR_DP_RX0_SOURCE_FIRST_POWER_ON()              (g_stDpRx0MiscInfo.b1DpSourceFirstPowerOn = _FALSE)

#endif // #if(_DP_MST_SUPPORT == _ON)

#define SET_DP_RX0_AUX_MANUAL_MODE_EXINT()              {\
                                                            for(g_ucRx0AuxTemp_EXINT = 0; ((ScalerGetBit_EXINT(PB7_C7_TP1_OCCR, 0x07) >= 0x02) && (g_ucRx0AuxTemp_EXINT < 255)); g_ucRx0AuxTemp_EXINT++)\
                                                            {\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                            }\
                                                            ScalerSetBit_EXINT(PB7_D0_AUX_MODE_SET, ~_BIT1, 0x00);\
                                                        }

#define SET_DP_RX0_AUX_MANUAL_MODE()                    {\
                                                            EX0 = 0;\
                                                            for(g_ucRx0AuxTemp = 0; ((ScalerGetBit(PB7_C7_TP1_OCCR, 0x07) >= 0x02) && (g_ucRx0AuxTemp < 255)); g_ucRx0AuxTemp++)\
                                                            {\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                            }\
                                                            ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, 0x00);\
                                                            EX0 = 1;\
                                                        }

#define SET_DP_RX0_AUX_AUTO_MODE_EXINT()                {\
                                                            for(g_ucRx0AuxTemp_EXINT = 0; ((ScalerGetBit_EXINT(PB7_C7_TP1_OCCR, 0x07) >= 0x02) && (g_ucRx0AuxTemp_EXINT < 255)); g_ucRx0AuxTemp_EXINT++)\
                                                            {\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                            }\
                                                            ScalerSetBit_EXINT(PB7_D0_AUX_MODE_SET, ~_BIT1, _BIT1);\
                                                        }

#define SET_DP_RX0_AUX_AUTO_MODE()                      {\
                                                            EX0 = 0;\
                                                            for(g_ucRx0AuxTemp = 0; ((ScalerGetBit(PB7_C7_TP1_OCCR, 0x07) >= 0x02) && (g_ucRx0AuxTemp < 255)); g_ucRx0AuxTemp++)\
                                                            {\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                                _nop_();\
                                                            }\
                                                            ScalerSetBit(PB7_D0_AUX_MODE_SET, ~_BIT1, _BIT1);\
                                                            EX0 = 1;\
                                                        }

#define GET_DP_RX0_VFRONT_PORCH()                       (g_usDpRx0Vfrontporch)
#define SET_DP_RX0_VFRONT_PORCH(x)                      (g_usDpRx0Vfrontporch = (x))

#define SET_DP_RX0_PORCH_COLOR_RGB()                    {\
                                                            ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x00);\
                                                            ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                            ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x00);\
                                                            ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                            ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x00);\
                                                            ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                        }

#define SET_DP_RX0_PORCH_COLOR_YCC_LIMIT()              {\
                                                            if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x10);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x10);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                            else\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x80);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x0F);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                        }

#define SET_DP_RX0_PORCH_COLOR_YCC_FULL()               {\
                                                            if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR420)\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x10);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x10);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                            else\
                                                            {\
                                                                ScalerSetByte(PB5_51_MN_DPF_BG_RED_M, 0x80);\
                                                                ScalerSetByte(PB5_52_MN_DPF_BG_RED_L, 0x00);\
                                                                ScalerSetByte(PB5_53_MN_DPF_BG_GRN_M, 0x00);\
                                                                ScalerSetByte(PB5_54_MN_DPF_BG_GRN_L, 0x00);\
                                                                ScalerSetByte(PB5_55_MN_DPF_BG_BLU_M, 0x80);\
                                                                ScalerSetByte(PB5_56_MN_DPF_BG_BLU_L, 0x00);\
                                                            }\
                                                        }

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Macro of RX HDCP Authentication
//--------------------------------------------------
#define GET_DP_RX0_HDCP_AUTH_STATE()                    (g_stDpRx0HDCPAuthInfo.b4AuthState)
#define SET_DP_RX0_HDCP_AUTH_STATE(x)                   (g_stDpRx0HDCPAuthInfo.b4AuthState = (x))

#define GET_DP_RX0_HDCP_AUTH_STATE_CHANGE()             (g_stDpRx0HDCPAuthInfo.b1AuthStateChange)
#define SET_DP_RX0_HDCP_AUTH_STATE_CHANGE()             (g_stDpRx0HDCPAuthInfo.b1AuthStateChange = _TRUE)
#define CLR_DP_RX0_HDCP_AUTH_STATE_CHANGE()             (g_stDpRx0HDCPAuthInfo.b1AuthStateChange = _FALSE)

#define GET_DP_RX0_HDCP_AUTH_REPEATER_PROC_TIMEOUT()    (g_stDpRx0HDCPAuthInfo.b1AuthRepeaterProcTimeout)
#define SET_DP_RX0_HDCP_AUTH_REPEATER_PROC_TIMEOUT()    (g_stDpRx0HDCPAuthInfo.b1AuthRepeaterProcTimeout = _TRUE)
#define CLR_DP_RX0_HDCP_AUTH_REPEATER_PROC_TIMEOUT()    (g_stDpRx0HDCPAuthInfo.b1AuthRepeaterProcTimeout = _FALSE)

#define GET_DP_RX0_HDCP_AUTH_READ_IRQ_TIMEOUT()         (g_stDpRx0HDCPAuthInfo.b1AuthReadIrqTimeout)
#define SET_DP_RX0_HDCP_AUTH_READ_IRQ_TIMEOUT()         (g_stDpRx0HDCPAuthInfo.b1AuthReadIrqTimeout = _TRUE)
#define CLR_DP_RX0_HDCP_AUTH_READ_IRQ_TIMEOUT()         (g_stDpRx0HDCPAuthInfo.b1AuthReadIrqTimeout = _FALSE)

#define GET_DP_RX0_HDCP_UPSTREAM_EVENT()                (g_stDpRx0HDCPAuthInfo.ucAuthUpstreamEvent)
#define SET_DP_RX0_HDCP_UPSTREAM_EVENT(x)               (g_stDpRx0HDCPAuthInfo.ucAuthUpstreamEvent = (x))
#define CLR_DP_RX0_HDCP_UPSTREAM_EVENT()                (g_stDpRx0HDCPAuthInfo.ucAuthUpstreamEvent = _DP_RX_HDCP_UPSTREAM_AUTH_EVENT_NONE)

#define GET_DP_RX0_HDCP_AUTH_CPIRQ_TIMRE()              (g_stDpRx0HDCPAuthInfo.b1AuthCpIrqTimer)
#define SET_DP_RX0_HDCP_AUTH_CPIRQ_TIMRE()              (g_stDpRx0HDCPAuthInfo.b1AuthCpIrqTimer = _TRUE)
#define CLR_DP_RX0_HDCP_AUTH_CPIRQ_TIMRE()              (g_stDpRx0HDCPAuthInfo.b1AuthCpIrqTimer = _FALSE)

#define GET_DP_RX0_HDCP_AUTH_AKSV_WRITTEN()             (g_bDpRx0HdcpAksvWritten)
#define SET_DP_RX0_HDCP_AUTH_AKSV_WRITTEN()             (g_bDpRx0HdcpAksvWritten = _TRUE)
#define CLR_DP_RX0_HDCP_AUTH_AKSV_WRITTEN()             (g_bDpRx0HdcpAksvWritten = _FALSE)

#define GET_DP_RX0_HDCP_REPEATER_SUPPORT()              ((ScalerDpRx0GetDpcdInfo(0x06, 0x80, 0x28) & (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))

#define GET_DP_RX0_HDCP_M0_0()                          (ScalerGetByte(PB_2F_M0_BYTE_0))
#define GET_DP_RX0_HDCP_M0_1()                          (ScalerGetByte(PB_2E_M0_BYTE_1))
#define GET_DP_RX0_HDCP_M0_2()                          (ScalerGetByte(PB_2D_M0_BYTE_2))
#define GET_DP_RX0_HDCP_M0_3()                          (ScalerGetByte(PB_2C_M0_BYTE_3))
#define GET_DP_RX0_HDCP_M0_4()                          (ScalerGetByte(PB_2B_M0_BYTE_4))
#define GET_DP_RX0_HDCP_M0_5()                          (ScalerGetByte(PB_2A_M0_BYTE_5))
#define GET_DP_RX0_HDCP_M0_6()                          (ScalerGetByte(PB_29_M0_BYTE_6))
#define GET_DP_RX0_HDCP_M0_7()                          (ScalerGetByte(PB_28_M0_BYTE_7))
#endif


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************
extern bit g_bDpRx0PSAuxToggle;

// Add for DPCD 2002h Bug
extern bit g_bDpRx0PowerStateIntoPS;
extern bit g_bDpRx0AuxCommandNoReply;

extern BYTE g_ucDpRx0LinkStatus01;
extern BYTE g_ucDpRx0LinkStatus23;
extern BYTE g_ucDpRx0LinkRequest01;
extern BYTE g_ucDpRx0LinkRequest23;
extern BYTE g_ucDpRx0Temp;
extern BYTE g_pucDpRx0Backup[3];
extern BYTE g_ucDpRx0Info;
extern BYTE g_ucDpRx0LinkRate;
extern BYTE g_ucDpRx0LaneCount;
extern BYTE g_ucDpRx0TrainingPatternSet;
extern BYTE g_pucDpRx0Tap0MaxTemp[4];
extern BYTE g_pucDpRx0LEMinTemp[4];
extern BYTE g_pucDpRx0LEMaxTemp[4];
extern BYTE g_pucDpRx0Tap1MaxTemp[4];
extern BYTE g_ucDpRx0EQCRC;
extern WORD g_usDpRx0ClockCount;
extern WORD g_usDpRx0ClockCount1;
extern BYTE g_ucRx0AuxTemp;
extern BYTE g_ucRx0AuxTemp_EXINT;
extern WORD g_usDpRx0Vfrontporch;

#if(_DP_MST_SUPPORT == _ON)
extern StructDPRxMiscInfo g_stDpRx0MiscInfo;
#endif

#if(_DP_TX_SUPPORT == _ON)
extern bit g_bDpRx0HdcpAksvWritten;
extern WORD g_usDpRx0HdcpKsvFifoOffset;
extern StructDPRxHDCPAuthInfo g_stDpRx0HDCPAuthInfo;
#endif

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerDpRx0AuxIntInitial(void);
extern void ScalerDpRx0DpcdInitial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
extern void ScalerDpRx0ChangeDpcdVersion(EnumDpVersionType enumDpVersion, EnumDPMSTPort enumDpRxMstPort);
extern void ScalerDpRx0HotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
extern void ScalerDpRx0HotPlugDuration(EnumDpHotPlugTime enumHpdTime);
extern void ScalerDpRx0MacInitial(void);
extern void ScalerDpRx0PhyInitial(void);
extern void ScalerDpRx0RebuildPhy(BYTE ucDpLinkRate, BYTE ucDpcdLane);
extern void ScalerDpRx0ValidSignalDetection(void);
extern bit ScalerDpRx0DecodeCheck(void);
extern void ScalerDpRx0SetNoVideoStreamIRQ(bit bEn);
extern bit ScalerDpRx0DFECheck(void);
extern bit ScalerDpRx0SignalCheck(BYTE ucDpLinkRate, BYTE ucDpcdLane);
extern bit ScalerDpRx0DisplayFormatSetting(void);
extern bit ScalerDpRx0StreamClkRegenerate(void);
extern bit ScalerDpRx0FifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
extern bit ScalerDpRx0HdcpCheck(void);
extern bit ScalerDpRx0HdcpReAuthStatusCheck(void);
extern void ScalerDpRx0CpIRQ(EnumDpRxBStatusType enumBStatusType);
extern bit ScalerDpRx0HdcpEnebled(void);
extern void ScalerDpRx0PhyCTS(void);
extern void ScalerDpRx0SetFifoWD(bit bEn);
extern void ScalerDpRx0SetFifoIRQ(bit bEn);
extern bit ScalerDpRx0NormalPreDetect(void);
extern BYTE ScalerDpRx0ScanInputPort(void);
extern bit ScalerDpRx0StableDetect(void);
extern void ScalerDpRx0HPDPowerOfftoNormalProc(BYTE ucDpHotPlugDCOffHighStatus);

#if(_DP_MST_SUPPORT == _ON)
extern bit ScalerDpRx0LTStatusCheck(void);
extern void ScalerDpRx0AuxChPowerStatusCheck(bit bCableStatus);

#if(_DP_TX_SUPPORT == _ON)
extern bit ScalerDpRx0MstToSstStreamClkRegenerate(void);
extern bit ScalerDpRx0MstToSstDisplayFormatSetting(void);
extern bit ScalerDpRx0MstToSstFifoCheck(EnumDpFifoCheckCondition enumFifoCheckCondition);
extern bit ScalerDpRx0MstToSstMeasureInput(void);
extern void ScalerDpRx0HDCPEnableReadIrq(bit bEnable);
#endif
#endif

#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
