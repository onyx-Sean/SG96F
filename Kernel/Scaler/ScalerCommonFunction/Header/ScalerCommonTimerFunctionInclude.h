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
// ID Code      : ScalerCommonTimerFunctionInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
#define _RX0_WD_TIMER_DP_EVENT_COUNT                 1
#else
#define _RX0_WD_TIMER_DP_EVENT_COUNT                 0
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#define _RX1_WD_TIMER_DP_EVENT_COUNT                 1
#else
#define _RX1_WD_TIMER_DP_EVENT_COUNT                 0
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
#define _RX2_WD_TIMER_DP_EVENT_COUNT                 1
#else
#define _RX2_WD_TIMER_DP_EVENT_COUNT                 0
#endif


#define _WD_TIMER_EVENT_COUNT                        (10 + _RX0_WD_TIMER_DP_EVENT_COUNT + _RX1_WD_TIMER_DP_EVENT_COUNT + _RX2_WD_TIMER_DP_EVENT_COUNT) // For HDMI 2.0 / MHL 3.0 / DP 1.2

//--------------------------------------------------
// Definitions of TimeOut
//--------------------------------------------------
#define _TIMER_WAIT_EVENT_TIMEOUT                    90 // unit: ms

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

typedef enum
{
    _SCALER_WD_TIMER_EVENT_INVALID = 0,
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    _SCALER_WD_TIMER_EVENT_RX0_DP_LINK_TRAINING_REBUILD_PHY,
#endif
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    _SCALER_WD_TIMER_EVENT_RX1_DP_LINK_TRAINING_REBUILD_PHY,
#endif
#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
    _SCALER_WD_TIMER_EVENT_RX2_DP_LINK_TRAINING_REBUILD_PHY,
#endif
    _SCALER_WD_TIMER_EVENT_RX0_HDMI_RR_RETRY,
    _SCALER_WD_TIMER_EVENT_RX1_HDMI_RR_RETRY,
    _SCALER_WD_TIMER_EVENT_RX2_HDMI_RR_RETRY,
    _SCALER_WD_TIMER_EVENT_RX3_HDMI_RR_RETRY,
    _SCALER_WD_TIMER_EVENT_RX4_HDMI_RR_RETRY,
    _SCALER_WD_TIMER_EVENT_RX5_HDMI_RR_RETRY,

#if((_MHL_SUPPORT == _ON) && (_MHL_3_0_SUPPORT == _ON))

#if(_D0_MHL_VERSION >= _MHL_VERSION_3_0)
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_SEND_BWD_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_BWD_KEEP_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_BWD_KEEP_COMMA2,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_WAIT_FWD_COMMA2_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_WAIT_TDM_SYNC_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_RESET_HOLD_IDLE,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_WAIT_FWD_COM1,
    _SCALER_WD_TIMER_EVENT_RX0_ECBUS_CLK_UNSTABLE_TMOUT,
#endif

#if(_D1_MHL_VERSION >= _MHL_VERSION_3_0)
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_SEND_BWD_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_BWD_KEEP_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_BWD_KEEP_COMMA2,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_WAIT_FWD_COMMA2_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_WAIT_TDM_SYNC_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_RESET_HOLD_IDLE,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_WAIT_FWD_COM1,
    _SCALER_WD_TIMER_EVENT_RX1_ECBUS_CLK_UNSTABLE_TMOUT,
#endif

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_SEND_BWD_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_BWD_KEEP_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_BWD_KEEP_COMMA2,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_WAIT_FWD_COMMA2_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_WAIT_TDM_SYNC_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_RESET_HOLD_IDLE,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_WAIT_FWD_COM1,
    _SCALER_WD_TIMER_EVENT_RX2_ECBUS_CLK_UNSTABLE_TMOUT,
#endif

#if(_D3_MHL_VERSION >= _MHL_VERSION_3_0)
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_SEND_BWD_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_BWD_KEEP_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_BWD_KEEP_COMMA2,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_WAIT_FWD_COMMA2_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_WAIT_TDM_SYNC_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_RESET_HOLD_IDLE,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_WAIT_FWD_COM1,
    _SCALER_WD_TIMER_EVENT_RX3_ECBUS_CLK_UNSTABLE_TMOUT,
#endif

#if(_D4_MHL_VERSION >= _MHL_VERSION_3_0)
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_SEND_BWD_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_BWD_KEEP_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_BWD_KEEP_COMMA2,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_WAIT_FWD_COMMA2_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_WAIT_TDM_SYNC_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_RESET_HOLD_IDLE,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_WAIT_FWD_COM1,
    _SCALER_WD_TIMER_EVENT_RX4_ECBUS_CLK_UNSTABLE_TMOUT,
#endif

#if(_D5_MHL_VERSION >= _MHL_VERSION_3_0)
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_SEND_BWD_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_BWD_KEEP_COMMA1,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_BWD_KEEP_COMMA2,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_WAIT_FWD_COMMA2_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_WAIT_TDM_SYNC_TMOUT,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_RESET_HOLD_IDLE,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_WAIT_FWD_COM1,
    _SCALER_WD_TIMER_EVENT_RX5_ECBUS_CLK_UNSTABLE_TMOUT,
#endif

#endif // End of #if((_MHL_SUPPORT == _ON) && (_MHL_3_0_SUPPORT == _ON))

#if((_DP_TYPE_C_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _EMBEDDED)
    _SCALER_WD_TIMER_EVENT_PD_RX0_SENDER_RESP_TIMEOUT,
    _SCALER_WD_TIMER_EVENT_PD_RX0_SRC_TURN_OFF_POWER,
    _SCALER_WD_TIMER_EVENT_PD_RX0_SRC_TURN_ON_POWER,
#endif
#endif

    _SCALER_WD_TIMER_EVENT_END,
    _SCALER_WD_TIMER_EVENT_COUNT = _SCALER_WD_TIMER_EVENT_END,
    _SCALER_WD_TIMER_EVENT_NULL = 0xFF,
} EnumScalerWDTimerEventID;

typedef struct
{
    EnumScalerWDTimerEventID enumEventID;
    WORD usTime;
} StructWDTimerEventType;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_RECORD_TIMER_SUPPORT == _ON)
extern void ScalerTimerResetRecordTimer_WDINT(void);
extern BYTE ScalerTimerGetRecordTimer_EXINT0(void);
#endif

#if(_WD_TIMER_INT_SUPPORT == _ON)
extern void ScalerTimerWDInitial(void);
extern void ScalerTimerWDActivateTimerEvent_EXINT0(WORD usTime, EnumScalerWDTimerEventID enumEventID);
extern void ScalerTimerWDCancelTimerEvent(EnumScalerWDTimerEventID enumEventID);

#if(((_MHL_SUPPORT == _ON) && (_MHL_3_0_SUPPORT == _ON)) || (_DP_SUPPORT == _ON) || ((_DP_TYPE_C_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)))
//#if((_MHL_SUPPORT == _ON) && (_MHL_3_0_SUPPORT == _ON))
extern void ScalerTimerWDCancelTimerEvent_EXINT0(EnumScalerWDTimerEventID enumEventID);
#endif

#endif

extern void ScalerTimerSetTimerCount(EnumScalerTimerOperationMode enumOperationMode);
extern void ScalerTimerActiveTimerEvent(WORD usTime, EnumScalerTimerEventID enumEventID);
extern void ScalerTimerReactiveTimerEvent(WORD usTime, EnumScalerTimerEventID enumEventID);
extern void ScalerTimerCancelTimerEvent(EnumScalerTimerEventID enumEventID);
#if((_MHL_3_0_SUPPORT == _ON) || (_TMDS_HDCP_2_2_SUPPORT == _ON) || ((_DP_TYPE_C_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON)))
extern void ScalerTimerCancelTimerEvent_EXINT0(EnumScalerTimerEventID enumEventID);
#endif

#if(_HDCP_2_2_SUPPORT == _ON)
extern BYTE ScalerTimerPollingFlagProc_EXINT0(WORD usTimeout, WORD usRegister, BYTE ucBit, bit bSuccess);
#endif

