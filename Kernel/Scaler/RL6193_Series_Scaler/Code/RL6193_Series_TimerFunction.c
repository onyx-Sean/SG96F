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
// ID Code      : RL6193_Series_TimerFunction.c No.0000
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
void ScalerTimerClrEventStatus(EnumWaitEventType enumEvent);
BYTE ScalerTimerGetEventStatus(EnumWaitEventType enumEvent);

#if(_DP_SUPPORT == _ON)
void ScalerTimerDpValidSignalCheck(EnumScalerTimerEventID enumEventID);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Clear Event Status
// Input Value  : enumEvent   --> Specified event
// Output Value : None
//--------------------------------------------------
void ScalerTimerClrEventStatus(EnumWaitEventType enumEvent)
{
    switch(enumEvent)
    {
        case _EVENT_IVS:
        case _EVENT_IEN_STOP:
            // M2
            ScalerSetByte(P40_03_M2_STATUS1, enumEvent);
            break;

        case _EVENT_DEN_START:
            // Total
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT4 | _BIT2), _BIT2);
            break;

        case _EVENT_DEN_STOP:
            // Total
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT4 | _BIT2), _BIT4);
            break;

        case _EVENT_ALL:
            ScalerSetByte(P40_03_M2_STATUS1, (_BIT2 | _BIT0));
            ScalerSetBit(P0_05_IRQ_CTRL1, ~(_BIT6 | _BIT4 | _BIT2), (_BIT4 | _BIT2));
            ScalerSetByte(P0_03_STATUS1, (_BIT7 | _BIT6 | _BIT3 | _BIT1));
            break;

        default:
            ScalerSetByte(P0_03_STATUS1, enumEvent);
            break;
    }
}

//--------------------------------------------------
// Description  : Hold until the specified event occurs
// Input Value  : enumEvent   --> Specified event
// Output Value : Return _TRUE if event occurs
//--------------------------------------------------
BYTE ScalerTimerGetEventStatus(EnumWaitEventType enumEvent)
{
    switch(enumEvent)
    {
        case _EVENT_IVS:
        case _EVENT_IEN_STOP:
            // M2
            return (ScalerGetByte(P40_03_M2_STATUS1) & enumEvent);

        case _EVENT_DEN_START:
            // Total
            return ((ScalerGetByte(P0_05_IRQ_CTRL1) & _BIT2) << 2);

        case _EVENT_DEN_STOP:
            // Total
            return ((ScalerGetByte(P0_05_IRQ_CTRL1) & _BIT4) << 1);

        case _EVENT_ALL:
            return ((ScalerGetByte(P40_03_M2_STATUS1) & (_BIT2 | _BIT0)) | ((ScalerGetByte(P0_05_IRQ_CTRL1) & _BIT2) << 2) |
                    ((ScalerGetByte(P0_05_IRQ_CTRL1) & _BIT4) << 1) | (ScalerGetByte(P0_03_STATUS1) & (_BIT7 | _BIT6 | _BIT3 | _BIT1)));

        default:
            return (ScalerGetByte(P0_03_STATUS1) & enumEvent);
    }
}

#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Scaler Timer Event Proc Fpr Valid Signal Check DC On Event
// Input Value  : enumEventID --> Event to be processed
// Output Value : None
//--------------------------------------------------
void ScalerTimerDpValidSignalCheck(EnumScalerTimerEventID enumEventID)
{
    switch(enumEventID)
    {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) || (_D6_INPUT_PORT_TYPE != _D6_NO_PORT))
        case _SCALER_TIMER_EVENT_DP_RX0_VALID_SIGNAL_DETECT_CHECK:

            if(ScalerDpRx0ValidSignalDetectionDCOnCheck() == _TRUE)
            {
                SET_DP_RX0_VALID_VIDEO_CHECK();
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
        case _SCALER_TIMER_EVENT_DP_RX1_VALID_SIGNAL_DETECT_CHECK:

            if(ScalerDpRx1ValidSignalDetectionDCOnCheck() == _TRUE)
            {
                SET_DP_RX1_VALID_VIDEO_CHECK();
            }

            break;
#endif

        default:
            break;
    }
}
#endif // End of #if(_DP_SUPPORT == _ON)
