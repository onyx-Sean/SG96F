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
// ID Code      : SysDP.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_DP__

#include "SysInclude.h"

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************


//--------------------------------------------------
// Definitions of mode search status
//--------------------------------------------------


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_DP_TYPE_C_SUPPORT == _ON)

#if(_D0_DP_TYPE_C_SUPPORT == _ON)
StructPortController g_stD0PortControllerInfo;

#if(_D0_DP_USB_HUB_SUPPORT == _ON)
StructUsbHubInfo g_stD0UsbHubInfo;
#endif

#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
StructPortController g_stD1PortControllerInfo;

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
StructUsbHubInfo g_stD1UsbHubInfo;
#endif

#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
StructPortController g_stD2PortControllerInfo;

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
StructUsbHubInfo g_stD2UsbHubInfo;
#endif

#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
StructPortController g_stD6PortControllerInfo;

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
StructUsbHubInfo g_stD6UsbHubInfo;
#endif

#endif

#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
void SysDpRxHandler(void);

#if(_DP_TYPE_C_SUPPORT == _ON)

void SysDpTypeCHandler(void);
void SysDpTypeCPortControllerProc(void);

#if(_DP_USB_HUB_SUPPORT == _ON)
void SysDpUsbHubProc(void);
void SysDpUsbHubConfigProc(BYTE ucInputPort, BYTE ucDpLanes);
void SysDpUsbHubDetectProc(BYTE ucInputPort);

#if(_D0_DP_USB_HUB_SUPPORT == _ON)
void SysDpD0UsbHubDetectProc(void);
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
void SysDpD1UsbHubDetectProc(void);
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
void SysDpD2UsbHubDetectProc(void);
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
void SysDpD6UsbHubDetectProc(void);
#endif

BYTE SysDpGetUsbHubDeviceInfo(BYTE ucInputPort);
bit SysDpGetUsbHubChangeFlg(BYTE ucInputPort);
WORD SysDpGetUsbHubSetU3ReadyDelayTime(BYTE ucInputPort);
#endif // End of #if(_DP_USB_HUB_SUPPORT == _ON)

#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DP_TYPE_C_SUPPORT == _ON))
bit SysDpTypeCGetD0CableConnectCheck(void);
void SysDpTypeCSetD0LaneCount(BYTE ucTypeCLane);
void SysDpTypeCReactiveD0AltModeCheck(WORD usTime);
#endif

#if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DP_TYPE_C_SUPPORT == _ON))
bit SysDpTypeCGetD1CableConnectCheck(void);
void SysDpTypeCSetD1LaneCount(BYTE ucTypeCLane);
void SysDpTypeCReactiveD1AltModeCheck(WORD usTime);
#endif

#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DP_TYPE_C_SUPPORT == _ON))
bit SysDpTypeCGetD2CableConnectCheck(void);
void SysDpTypeCSetD2LaneCount(BYTE ucTypeCLane);
void SysDpTypeCReactiveD2AltModeCheck(WORD usTime);
#endif

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_DP_TYPE_C_SUPPORT == _ON))
bit SysDpTypeCGetD6CableConnectCheck(void);
void SysDpTypeCSetD6LaneCount(BYTE ucTypeCLane);
void SysDpTypeCReactiveD6AltModeCheck(WORD usTime);
#endif

BYTE SysDpTypeCGetInputLaneStatus(BYTE ucInputPort);

#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)

#endif

#if(_DP_TX_SUPPORT == _ON)
void SysDpTxHandler(void);
bit SysDpTxCloneOutputStatus(void);
#endif

#if(_DP_MST_SUPPORT == _ON)
void SysDpMstHandler(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_DP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Rx Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpRxHandler(void)
{
#if(_DP_TX_SUPPORT == _ON)
    ScalerSyncDpTxHdcpUpstreamSwitchProc(SysSourceGetInputPort());
#endif

    ScalerDpCapabilitySwitchProc();

#if(_DP_TX_SUPPORT == _ON)
    if(GET_MODE_STATE() == _MODE_STATUS_ACTIVE)
    {
        ScalerDpTxCloneOutputProc(SysSourceGetInputPort(), GET_PORT_TYPE(SysSourceGetInputPortType(SysSourceGetInputPort())), SysDpTxCloneOutputStatus());
    }
#endif
}

#if(_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Type-C Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTypeCHandler(void)
{
    SysDpTypeCPortControllerProc();

#if(_DP_USB_HUB_SUPPORT == _ON)
    SysDpUsbHubProc();
#endif
}

//--------------------------------------------------
// Description  : Type-C Port Controller Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTypeCPortControllerProc(void)
{
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
#if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _EMBEDDED)
    ScalerTypeCRx0CcHandler();
#else
    if(UserInterfaceTypeCPortControllerSupport(_D0_INPUT_PORT) == _TRUE)
    {
        UserCommonPortControllerConfigDetect(_D0_INPUT_PORT);

        if((UserCommonPortControllerGetD0PortPower() == _ON) && (GET_D0_DP_TYPE_C_LANE_STATUS() != UserInterfaceGetDpLaneCount(_D0_INPUT_PORT)))
        {
            if(UserCommonPortControllerConfig(_D0_INPUT_PORT) == _TRUE)
            {
                SET_D0_DP_TYPE_C_LANE_STATUS(UserInterfaceGetDpLaneCount(_D0_INPUT_PORT));
                ScalerDpLaneCountSwitch(_D0_INPUT_PORT, GET_D0_DP_TYPE_C_LANE_STATUS());
            }
        }
    }
#endif  // #if(_D0_DP_TYPE_C_PORT_CTRL_TYPE == _EMBEDDED)
#endif  // #if(_D0_DP_TYPE_C_SUPPORT == _ON)

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
    if(UserInterfaceTypeCPortControllerSupport(_D1_INPUT_PORT) == _TRUE)
    {
        UserCommonPortControllerConfigDetect(_D1_INPUT_PORT);

        if((UserCommonPortControllerGetD1PortPower() == _ON) && (GET_D1_DP_TYPE_C_LANE_STATUS() != UserInterfaceGetDpLaneCount(_D1_INPUT_PORT)))
        {
            if(UserCommonPortControllerConfig(_D1_INPUT_PORT) == _TRUE)
            {
                SET_D1_DP_TYPE_C_LANE_STATUS(UserInterfaceGetDpLaneCount(_D1_INPUT_PORT));
                ScalerDpLaneCountSwitch(_D1_INPUT_PORT, GET_D1_DP_TYPE_C_LANE_STATUS());
            }
        }
    }
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
    if(UserInterfaceTypeCPortControllerSupport(_D2_INPUT_PORT) == _TRUE)
    {
        UserCommonPortControllerConfigDetect(_D2_INPUT_PORT);

        if((UserCommonPortControllerGetD2PortPower() == _ON) && (GET_D2_DP_TYPE_C_LANE_STATUS() != UserInterfaceGetDpLaneCount(_D2_INPUT_PORT)))
        {
            if(UserCommonPortControllerConfig(_D2_INPUT_PORT) == _TRUE)
            {
                SET_D2_DP_TYPE_C_LANE_STATUS(UserInterfaceGetDpLaneCount(_D2_INPUT_PORT));
                ScalerDpLaneCountSwitch(_D2_INPUT_PORT, GET_D2_DP_TYPE_C_LANE_STATUS());
            }
        }
    }
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
    if(UserInterfaceTypeCPortControllerSupport(_D6_INPUT_PORT) == _TRUE)
    {
        UserCommonPortControllerConfigDetect(_D6_INPUT_PORT);

        if((UserCommonPortControllerGetD6PortPower() == _ON) && (GET_D6_DP_TYPE_C_LANE_STATUS() != UserInterfaceGetDpLaneCount(_D6_INPUT_PORT)))
        {
            if(UserCommonPortControllerConfig(_D6_INPUT_PORT) == _TRUE)
            {
                SET_D6_DP_TYPE_C_LANE_STATUS(UserInterfaceGetDpLaneCount(_D6_INPUT_PORT));
                ScalerDpLaneCountSwitch(_D6_INPUT_PORT, GET_D6_DP_TYPE_C_LANE_STATUS());
            }
        }
    }
#endif
}

#if(_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Type-C Usb Hub Proc
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpUsbHubProc(void)
{
#if(_D0_DP_USB_HUB_SUPPORT == _ON)
    if(UserInterfaceTypecUSBSupport(_D0_INPUT_PORT) == _TRUE)
    {
        SysDpUsbHubDetectProc(_D0_INPUT_PORT);
        SysDpUsbHubConfigProc(_D0_INPUT_PORT, GET_D0_DP_TYPE_C_LANE_STATUS());
    }
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
    if(UserInterfaceTypecUSBSupport(_D1_INPUT_PORT) == _TRUE)
    {
        SysDpUsbHubDetectProc(_D1_INPUT_PORT);
        SysDpUsbHubConfigProc(_D1_INPUT_PORT, GET_D1_DP_TYPE_C_LANE_STATUS());
    }
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
    if(UserInterfaceTypecUSBSupport(_D2_INPUT_PORT) == _TRUE)
    {
        SysDpUsbHubDetectProc(_D2_INPUT_PORT);
        SysDpUsbHubConfigProc(_D2_INPUT_PORT, GET_D2_DP_TYPE_C_LANE_STATUS());
    }
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
    if(UserInterfaceTypecUSBSupport(_D6_INPUT_PORT) == _TRUE)
    {
        SysDpUsbHubDetectProc(_D6_INPUT_PORT);
        SysDpUsbHubConfigProc(_D6_INPUT_PORT, GET_D6_DP_TYPE_C_LANE_STATUS());
    }
#endif
}

//--------------------------------------------------
// Description  : Adjust Type-C Dp Lanes
// Input Value  : ucInputPort --> Input Port
//                ucDpLanes   --> Target Dp Lanes
// Output Value : None
//--------------------------------------------------
void SysDpUsbHubConfigProc(BYTE ucInputPort, BYTE ucDpLanes)
{
    if(ucDpLanes == _DP_TWO_LANE)
    {
        switch(ucInputPort)
        {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)
            case _D0_INPUT_PORT:

                if(GET_D0_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_SS_STATE)
                {
                    if(GET_D0_TYPE_C_USB_HUB_INFO() == 0x00)
                    {
                        break;
                    }

                    if(UserCommonUsbHubSetSSMode(_D0_INPUT_PORT, _ENABLE) == _TRUE)
                    {
                        SET_D0_USB_HUB_MODE_STATE(_USB_MODE_STATUS_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D0_INPUT_PORT), _SYSTEM_TIMER_EVENT_D0_USBHUB_DETECT);
                    }
                }

                break;
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
            case _D1_INPUT_PORT:

                if(GET_D1_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_SS_STATE)
                {
                    if(GET_D1_TYPE_C_USB_HUB_INFO() == 0x00)
                    {
                        break;
                    }

                    if(UserCommonUsbHubSetSSMode(_D1_INPUT_PORT, _ENABLE) == _TRUE)
                    {
                        SET_D1_USB_HUB_MODE_STATE(_USB_MODE_STATUS_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D1_INPUT_PORT), _SYSTEM_TIMER_EVENT_D1_USBHUB_DETECT);
                    }
                }

                break;
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
            case _D2_INPUT_PORT:

                if(GET_D2_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_SS_STATE)
                {
                    if(GET_D2_TYPE_C_USB_HUB_INFO() == 0x00)
                    {
                        break;
                    }

                    if(UserCommonUsbHubSetSSMode(_D2_INPUT_PORT, _ENABLE) == _TRUE)
                    {
                        SET_D2_USB_HUB_MODE_STATE(_USB_MODE_STATUS_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D2_INPUT_PORT), _SYSTEM_TIMER_EVENT_D2_USBHUB_DETECT);
                    }
                }

                break;
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
            case _D6_INPUT_PORT:

                if(GET_D6_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_SS_STATE)
                {
                    if(GET_D6_TYPE_C_USB_HUB_INFO() == 0x00)
                    {
                        break;
                    }

                    if(UserCommonUsbHubSetSSMode(_D6_INPUT_PORT, _ENABLE) == _TRUE)
                    {
                        SET_D6_USB_HUB_MODE_STATE(_USB_MODE_STATUS_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D6_INPUT_PORT), _SYSTEM_TIMER_EVENT_D6_USBHUB_DETECT);
                    }
                }

                break;
#endif

            default:
                break;
        }
    }
    else
    {
        switch(ucInputPort)
        {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)
            case _D0_INPUT_PORT:

                if(GET_D0_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_DETECT_SS_STATE)
                {
                    if(UserCommonUsbHubSetSSMode(_D0_INPUT_PORT, _DISABLE) == _TRUE)
                    {
                        SET_D0_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D0_INPUT_PORT), _SYSTEM_TIMER_EVENT_D0_USBHUB_DETECT);
                    }
                }

                break;
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
            case _D1_INPUT_PORT:

                if(GET_D1_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_DETECT_SS_STATE)
                {
                    if(UserCommonUsbHubSetSSMode(_D1_INPUT_PORT, _DISABLE) == _TRUE)
                    {
                        SET_D1_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D1_INPUT_PORT), _SYSTEM_TIMER_EVENT_D1_USBHUB_DETECT);
                    }
                }

                break;
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
            case _D2_INPUT_PORT:

                if(GET_D2_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_DETECT_SS_STATE)
                {
                    if(UserCommonUsbHubSetSSMode(_D2_INPUT_PORT, _DISABLE) == _TRUE)
                    {
                        SET_D2_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D2_INPUT_PORT), _SYSTEM_TIMER_EVENT_D2_USBHUB_DETECT);
                    }
                }

                break;
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
            case _D6_INPUT_PORT:

                if(GET_D6_USB_HUB_MODE_STATE() != _USB_MODE_STATUS_DETECT_SS_STATE)
                {
                    if(UserCommonUsbHubSetSSMode(_D6_INPUT_PORT, _DISABLE) == _TRUE)
                    {
                        SET_D6_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
                        ScalerTimerReactiveTimerEvent(SysDpGetUsbHubSetU3ReadyDelayTime(_D6_INPUT_PORT), _SYSTEM_TIMER_EVENT_D6_USBHUB_DETECT);
                    }
                }

                break;
#endif
            default:
                break;
        }
    }
}

//--------------------------------------------------
// Description  : Detect Usb Hub Info
// Input Value  : ucInputPort --> Input Port
// Output Value : None
//--------------------------------------------------
void SysDpUsbHubDetectProc(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)

        case _D0_INPUT_PORT:

            SysDpD0UsbHubDetectProc();

            break;
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            SysDpD1UsbHubDetectProc();

            break;
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)

        case _D2_INPUT_PORT:

            SysDpD2UsbHubDetectProc();

            break;
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)

        case _D6_INPUT_PORT:

            SysDpD6UsbHubDetectProc();

            break;
#endif

        default:
            break;
    }
}

#if(_D0_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect SS Device
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpD0UsbHubDetectProc(void)
{
    BYTE ucUsbHubInfo = 0x00;

    CLR_D0_USB_HUB_PLUG_DEVICE_CHANGE_FLG();

    switch(GET_D0_USB_HUB_MODE_STATE())
    {
        case _USB_MODE_STATUS_INITIAL:

            SET_D0_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
            SET_D0_USB_HUB_SS_DEVICE_DETECT_FLG();

            break;

        case _USB_MODE_STATUS_DETECT_SS_STATE:
        case _USB_MODE_STATUS_SS_STATE:

            if((GET_D0_USB_HUB_SS_DEVICE_DETECT_FLG() == _TRUE) && (UserInterfaceTypecGetUSBSupportStatus(_D0_INPUT_PORT) == _ON))
            {
                CLR_D0_USB_HUB_SS_DEVICE_DETECT_FLG();
                ScalerTimerActiveTimerEvent(UserCommonUsbHubSetPollingStep(_D0_INPUT_PORT), _SYSTEM_TIMER_EVENT_D0_USBHUB_DETECT);

                ucUsbHubInfo = UserCommonUsbHubDetectSSDevicePlugInfo(_D0_INPUT_PORT);

                if(GET_D0_TYPE_C_USB_HUB_INFO() != ucUsbHubInfo)
                {
                    SET_D0_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
                    SET_D0_TYPE_C_USB_HUB_INFO(ucUsbHubInfo);
                }
            }

            break;

        default:
        case _USB_MODE_STATUS_PS_STATE:
        case _USB_MODE_STATUS_PD_STATE:

            break;
    }
}
#endif // End of #if(_D0_DP_USB_HUB_SUPPORT == _ON)

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect SS Device
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpD1UsbHubDetectProc(void)
{
    BYTE ucUsbHubInfo = 0x00;

    CLR_D1_USB_HUB_PLUG_DEVICE_CHANGE_FLG();

    switch(GET_D1_USB_HUB_MODE_STATE())
    {
        case _USB_MODE_STATUS_INITIAL:

            SET_D1_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
            SET_D1_USB_HUB_SS_DEVICE_DETECT_FLG();

            break;

        case _USB_MODE_STATUS_DETECT_SS_STATE:
        case _USB_MODE_STATUS_SS_STATE:

            if((GET_D1_USB_HUB_SS_DEVICE_DETECT_FLG() == _TRUE) && (UserInterfaceTypecGetUSBSupportStatus(_D1_INPUT_PORT) == _ON))
            {
                CLR_D1_USB_HUB_SS_DEVICE_DETECT_FLG();
                ScalerTimerActiveTimerEvent(UserCommonUsbHubSetPollingStep(_D1_INPUT_PORT), _SYSTEM_TIMER_EVENT_D1_USBHUB_DETECT);

                ucUsbHubInfo = UserCommonUsbHubDetectSSDevicePlugInfo(_D1_INPUT_PORT);

                if(GET_D1_TYPE_C_USB_HUB_INFO() != ucUsbHubInfo)
                {
                    SET_D1_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
                    SET_D1_TYPE_C_USB_HUB_INFO(ucUsbHubInfo);
                }
            }

            break;

        default:
        case _USB_MODE_STATUS_PS_STATE:
        case _USB_MODE_STATUS_PD_STATE:

            break;
    }
}
#endif // End of #if(_D1_DP_USB_HUB_SUPPORT == _ON)

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect SS Device
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpD2UsbHubDetectProc(void)
{
    BYTE ucUsbHubInfo = 0x00;

    CLR_D2_USB_HUB_PLUG_DEVICE_CHANGE_FLG();

    switch(GET_D0_USB_HUB_MODE_STATE())
    {
        case _USB_MODE_STATUS_INITIAL:

            SET_D2_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
            SET_D2_USB_HUB_SS_DEVICE_DETECT_FLG();

            break;

        case _USB_MODE_STATUS_DETECT_SS_STATE:
        case _USB_MODE_STATUS_SS_STATE:

            if((GET_D2_USB_HUB_SS_DEVICE_DETECT_FLG() == _TRUE) && (UserInterfaceTypecGetUSBSupportStatus(_D2_INPUT_PORT) == _ON))
            {
                CLR_D2_USB_HUB_SS_DEVICE_DETECT_FLG();
                ScalerTimerActiveTimerEvent(UserCommonUsbHubSetPollingStep(_D2_INPUT_PORT), _SYSTEM_TIMER_EVENT_D2_USBHUB_DETECT);

                ucUsbHubInfo = UserCommonUsbHubDetectSSDevicePlugInfo(_D2_INPUT_PORT);

                if(GET_D2_TYPE_C_USB_HUB_INFO() != ucUsbHubInfo)
                {
                    SET_D2_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
                    SET_D2_TYPE_C_USB_HUB_INFO(ucUsbHubInfo);
                }
            }

            break;

        default:
        case _USB_MODE_STATUS_PS_STATE:
        case _USB_MODE_STATUS_PD_STATE:

            break;
    }
}
#endif // End of #if(_D2_DP_USB_HUB_SUPPORT == _ON)

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Detect SS Device
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpD6UsbHubDetectProc(void)
{
    BYTE ucUsbHubInfo = 0x00;

    CLR_D6_USB_HUB_PLUG_DEVICE_CHANGE_FLG();

    switch(GET_D6_USB_HUB_MODE_STATE())
    {
        case _USB_MODE_STATUS_INITIAL:

            SET_D6_USB_HUB_MODE_STATE(_USB_MODE_STATUS_DETECT_SS_STATE);
            SET_D6_USB_HUB_SS_DEVICE_DETECT_FLG();

            break;

        case _USB_MODE_STATUS_DETECT_SS_STATE:
        case _USB_MODE_STATUS_SS_STATE:

            if((GET_D6_USB_HUB_SS_DEVICE_DETECT_FLG() == _TRUE) && (UserInterfaceTypecGetUSBSupportStatus(_D6_INPUT_PORT) == _ON))
            {
                CLR_D6_USB_HUB_SS_DEVICE_DETECT_FLG();
                ScalerTimerActiveTimerEvent(UserCommonUsbHubSetPollingStep(_D6_INPUT_PORT), _SYSTEM_TIMER_EVENT_D6_USBHUB_DETECT);

                ucUsbHubInfo = UserCommonUsbHubDetectSSDevicePlugInfo(_D6_INPUT_PORT);

                if(GET_D6_TYPE_C_USB_HUB_INFO() != ucUsbHubInfo)
                {
                    SET_D6_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
                    SET_D6_TYPE_C_USB_HUB_INFO(ucUsbHubInfo);
                }
            }

            break;

        default:
        case _USB_MODE_STATUS_PS_STATE:
        case _USB_MODE_STATUS_PD_STATE:

            break;
    }
}
#endif // End of #if(_D6_DP_USB_HUB_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Get Usb Hub Device Info
// Input Value  : ucInputPort --> Input Port
// Output Value : Usb Hub Info
//--------------------------------------------------
BYTE SysDpGetUsbHubDeviceInfo(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)

        case _D0_INPUT_PORT:

            return GET_D0_TYPE_C_USB_HUB_INFO();
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            return GET_D1_TYPE_C_USB_HUB_INFO();
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)

        case _D2_INPUT_PORT:

            return GET_D2_TYPE_C_USB_HUB_INFO();
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)

        case _D6_INPUT_PORT:

            return GET_D6_TYPE_C_USB_HUB_INFO();
#endif

        default:
            break;
    }

    return 0;
}

//--------------------------------------------------
// Description  : Get Usb Hub Device Info Change Flag
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit SysDpGetUsbHubChangeFlg(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)

        case _D0_INPUT_PORT:

            return GET_D0_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            return GET_D1_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)

        case _D2_INPUT_PORT:

            return GET_D2_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)

        case _D6_INPUT_PORT:

            return GET_D6_USB_HUB_PLUG_DEVICE_CHANGE_FLG();
#endif

        default:
            break;
    }

    return 0;
}

//--------------------------------------------------
// Description  : Set Usb Hub Config U3 Delay Time
// Input Value  : ucInputPort --> Input Port
// Output Value : Usb Hub Info
//--------------------------------------------------
WORD SysDpGetUsbHubSetU3ReadyDelayTime(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)

        case _D0_INPUT_PORT:

            if(UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(_D0_INPUT_PORT) == _TRUE)
            {
                return SEC(0);
            }
            else
            {
                return SEC(2);
            }
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            if(UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(_D1_INPUT_PORT) == _TRUE)
            {
                return SEC(0);
            }
            else
            {
                return SEC(2);
            }
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
        case _D6_INPUT_PORT:

            if(UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(_D6_INPUT_PORT) == _TRUE)
            {
                return SEC(0);
            }
            else
            {
                return SEC(2);
            }
#endif

        default:
            break;
    }

    return SEC(0);
}
#endif // End of #if(_DP_USB_HUB_SUPPORT == _ON)

#if((_D0_INPUT_PORT_TYPE != _D0_NO_PORT) && (_D0_DP_TYPE_C_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get D0 Cable Status
// Input Value  : None
// Output Value : _TRUE : Cable Connected / _FALSE : Cable Not Connected
//--------------------------------------------------
bit SysDpTypeCGetD0CableConnectCheck(void)
{
    if(UserInterfaceTypeCPortControllerCableCheckUserFlow(_D0_INPUT_PORT) == _TRUE)
    {
        return(!PCB_D0_PIN());
    }

    // Current Lit Up Port is _D0_INPUT_PORT,
    if(SysSourceGetInputPort() == _D0_INPUT_PORT)
    {
        if(SysSourceGetSourceType() == _SOURCE_DP)
        {
            DebugMessageSystem("8. Type-C D0 Lit Up", 1);
            return _TRUE;
        }
    }

    if(GET_D0_DP_TYPE_C_CABLE_DETECT() == _FALSE)
    {
        if(GET_D0_DP_TYPE_C_ALTMODE_STATUS() == _TRUE)
        {
            return _TRUE;
        }

        return _FALSE;
    }
    else
    {
        CLR_D0_DP_TYPE_C_CABLE_DETECT();
        ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_D0_TYPEC_CABLE_DETECT);

        if(UserCommonPortControllerCheckPCEnterAltMode(_D0_INPUT_PORT) == _FALSE)
        {
            CLR_D0_DP_TYPE_C_ALTMODE_STATUS();
            DebugMessageSystem("8. Type-C cable disconnected", 1);

            return _FALSE;
        }
        else
        {
            SET_D0_DP_TYPE_C_ALTMODE_STATUS();
            DebugMessageSystem("8. Type-C cable connected", 1);

            return _TRUE;
        }
    }
}

//--------------------------------------------------
// Description  : Set D0 Type-C Lane Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTypeCSetD0LaneCount(BYTE ucTypeCLane)
{
    SET_D0_DP_TYPE_C_LANE_STATUS(ucTypeCLane);
}

//--------------------------------------------------
// Description  : Reactive D0 Alt Mode Check
// Input Value  : usTime --> Time counter
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
void SysDpTypeCReactiveD0AltModeCheck(WORD usTime)
{
    CLR_D0_DP_TYPE_C_CABLE_DETECT();
    ScalerTimerReactiveTimerEvent(usTime, _SYSTEM_TIMER_EVENT_D0_TYPEC_CABLE_DETECT);
}
#endif

#if((_D1_INPUT_PORT_TYPE != _D1_NO_PORT) && (_D1_DP_TYPE_C_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get D1 Cable Status
// Input Value  : None
// Output Value : _TRUE : Cable Connected / _FALSE : Cable Not Connected
//--------------------------------------------------
bit SysDpTypeCGetD1CableConnectCheck(void)
{
    if(UserInterfaceTypeCPortControllerCableCheckUserFlow(_D1_INPUT_PORT) == _TRUE)
    {
        return(!PCB_D1_PIN());
    }

    // Current Lit Up Port is _D1_INPUT_PORT,
    if(SysSourceGetInputPort() == _D1_INPUT_PORT)
    {
        if(SysSourceGetSourceType() == _SOURCE_DP)
        {
            DebugMessageSystem("8. Type-C D1 Lit Up", 1);
            return _TRUE;
        }
    }

    if(GET_D1_DP_TYPE_C_CABLE_DETECT() == _FALSE)
    {
        if(GET_D1_DP_TYPE_C_ALTMODE_STATUS() == _TRUE)
        {
            return _TRUE;
        }

        return _FALSE;
    }
    else
    {
        CLR_D1_DP_TYPE_C_CABLE_DETECT();
        ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_D1_TYPEC_CABLE_DETECT);

        if(UserCommonPortControllerCheckPCEnterAltMode(_D1_INPUT_PORT) == _FALSE)
        {
            CLR_D1_DP_TYPE_C_ALTMODE_STATUS();

            return _FALSE;
        }
        else
        {
            SET_D1_DP_TYPE_C_ALTMODE_STATUS();

            return _TRUE;
        }
    }
}

//--------------------------------------------------
// Description  : Set D1 Type-C Lane Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTypeCSetD1LaneCount(BYTE ucTypeCLane)
{
    SET_D1_DP_TYPE_C_LANE_STATUS(ucTypeCLane);
}

//--------------------------------------------------
// Description  : Reactive D1 Alt Mode Check
// Input Value  : usTime --> Time counter
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
void SysDpTypeCReactiveD1AltModeCheck(WORD usTime)
{
    CLR_D1_DP_TYPE_C_CABLE_DETECT();
    ScalerTimerActiveTimerEvent(usTime, _SYSTEM_TIMER_EVENT_D1_TYPEC_CABLE_DETECT);
}
#endif

#if((_D2_INPUT_PORT_TYPE != _D2_NO_PORT) && (_D2_DP_TYPE_C_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get D2 Cable Status
// Input Value  : None
// Output Value : _TRUE : Cable Not Connected / _FALSE : Cable Connected
//--------------------------------------------------
bit SysDpTypeCGetD2CableConnectCheck(void)
{
    if(UserInterfaceTypeCPortControllerCableCheckUserFlow(_D2_INPUT_PORT) == _TRUE)
    {
        return(!PCB_D2_PIN());
    }

    // Current Lit Up Port is _D2_INPUT_PORT,
    if(SysSourceGetInputPort() == _D2_INPUT_PORT)
    {
        if(SysSourceGetSourceType() == _SOURCE_DP)
        {
            DebugMessageSystem("8. Type-C D2 Lit Up", 1);
            return _TRUE;
        }
    }

    if(GET_D2_DP_TYPE_C_CABLE_DETECT() == _FALSE)
    {
        if(GET_D2_DP_TYPE_C_ALTMODE_STATUS() == _TRUE)
        {
            return _TRUE;
        }

        return _FALSE;
    }
    else
    {
        CLR_D2_DP_TYPE_C_CABLE_DETECT();
        ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_D2_TYPEC_CABLE_DETECT);

        if(UserCommonPortControllerCheckPCEnterAltMode(_D2_INPUT_PORT) == _FALSE)
        {
            CLR_D2_DP_TYPE_C_ALTMODE_STATUS();

            return _FALSE;
        }
        else
        {
            SET_D2_DP_TYPE_C_ALTMODE_STATUS();

            return _TRUE;
        }
    }
}

//--------------------------------------------------
// Description  : Set D2 Type-C Lane Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTypeCSetD2LaneCount(BYTE ucTypeCLane)
{
    SET_D2_DP_TYPE_C_LANE_STATUS(ucTypeCLane);
}

//--------------------------------------------------
// Description  : Reactive D2 Alt Mode Check
// Input Value  : usTime --> Time counter
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
void SysDpTypeCReactiveD2AltModeCheck(WORD usTime)
{
    CLR_D2_DP_TYPE_C_CABLE_DETECT();
    ScalerTimerActiveTimerEvent(usTime, _SYSTEM_TIMER_EVENT_D2_TYPEC_CABLE_DETECT);
}
#endif

#if((_D6_INPUT_PORT_TYPE != _D6_NO_PORT) && (_D6_DP_TYPE_C_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Get D6 Cable Status
// Input Value  : None
// Output Value : _TRUE : Cable Not Connected / _FALSE : Cable Connected
//--------------------------------------------------
bit SysDpTypeCGetD6CableConnectCheck(void)
{
    if(UserInterfaceTypeCPortControllerCableCheckUserFlow(_D6_INPUT_PORT) == _TRUE)
    {
        return(!PCB_D6_PIN());
    }

    // Current Lit Up Port is _D6_INPUT_PORT,
    if(SysSourceGetInputPort() == _D6_INPUT_PORT)
    {
        if(SysSourceGetSourceType() == _SOURCE_DP)
        {
            return _TRUE;
        }
    }

    if(GET_D6_DP_TYPE_C_CABLE_DETECT() == _FALSE)
    {
        if(GET_D6_DP_TYPE_C_ALTMODE_STATUS() == _TRUE)
        {
            return _TRUE;
        }

        return _FALSE;
    }
    else
    {
        CLR_D6_DP_TYPE_C_CABLE_DETECT();
        ScalerTimerActiveTimerEvent(SEC(0.5), _SYSTEM_TIMER_EVENT_D6_TYPEC_CABLE_DETECT);

        if(UserCommonPortControllerCheckPCEnterAltMode(_D6_INPUT_PORT) == _FALSE)
        {
            CLR_D6_DP_TYPE_C_ALTMODE_STATUS();

            return _FALSE;
        }
        else
        {
            SET_D6_DP_TYPE_C_ALTMODE_STATUS();

            return _TRUE;
        }
    }
}

//--------------------------------------------------
// Description  : Set D6 Type-C Lane Counter
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTypeCSetD6LaneCount(BYTE ucTypeCLane)
{
    SET_D6_DP_TYPE_C_LANE_STATUS(ucTypeCLane);
}

//--------------------------------------------------
// Description  : Reactive D6 Alt Mode Check
// Input Value  : usTime --> Time counter
// Output Value : _TRUE/_FALSE
//--------------------------------------------------
void SysDpTypeCReactiveD6AltModeCheck(WORD usTime)
{
    CLR_D6_DP_TYPE_C_CABLE_DETECT();
    ScalerTimerActiveTimerEvent(usTime, _SYSTEM_TIMER_EVENT_D6_TYPEC_CABLE_DETECT);
}
#endif

//--------------------------------------------------
// Description  : Get Input Port Lane Status
// Input Value  : ucInputPort --> Input Port
// Output Value : Type-C Lane Status
//--------------------------------------------------
BYTE SysDpTypeCGetInputLaneStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_D0_DP_TYPE_C_LANE_STATUS();
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_D1_DP_TYPE_C_LANE_STATUS();
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_D2_DP_TYPE_C_LANE_STATUS();
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_D6_DP_TYPE_C_LANE_STATUS();
#endif

        default:
            break;
    }

    return 0;
}
#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)
#endif // End of #if(_DP_SUPPORT == _ON)

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Tx Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpTxHandler(void)
{
    if((GET_POWER_STATUS() == _POWER_STATUS_NORMAL) || (GET_POWER_STATUS() == _POWER_STATUS_FAKE_SAVING) || (GET_POWER_STATUS() == _POWER_STATUS_NOSUPPORT_SAVING) || (GET_POWER_STATUS() == _POWER_STATUS_FAKE_OFF))
    {
        // HPD Detection Function
        ScalerDpTxHPDProc();

        ScalerDpTxJudgeHandler();

        ScalerDpTxModeHandler();

#if(_DP_MST_SUPPORT == _ON)
        ScalerDpHDCPHandler();
#endif

        ScalerDpTxHDCPHandler();
    }
}

//--------------------------------------------------
// Description  : Decide whether to Clone output to DP Tx
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit SysDpTxCloneOutputStatus(void)
{
    if(UserInterfaceGetDpCloneOutputStatus() == _FALSE)
    {
        return _FALSE;
    }

    if(GET_PORT_TYPE(SysSourceGetInputPortType(SysSourceGetInputPort())) == _PORT_DP)
    {
#if((_D0_INPUT_PORT_TYPE == _D0_DP_PORT) && (_D0_DP_MST_PORT_SUPPORT == _OFF))
        if(SysSourceGetInputPort() == _D0_INPUT_PORT)
        {
            return _FALSE;
        }
#endif

#if((_D1_INPUT_PORT_TYPE == _D1_DP_PORT) && (_D1_DP_MST_PORT_SUPPORT == _OFF))
        if(SysSourceGetInputPort() == _D1_INPUT_PORT)
        {
            return _FALSE;
        }
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
        if(ScalerSyncGetFREESYNCEnable() == _TRUE)
        {
            return _FALSE;
        }
#endif
    }

    return _TRUE;
}
#endif

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Rx MST Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysDpMstHandler(void)
{
    if((GET_POWER_STATUS() == _POWER_STATUS_NORMAL) || (GET_POWER_STATUS() == _POWER_STATUS_FAKE_SAVING) || (GET_POWER_STATUS() == _POWER_STATUS_NOSUPPORT_SAVING) || (GET_POWER_STATUS() == _POWER_STATUS_FAKE_OFF))
    {
        ScalerDpRxMstHandler();

#if(_DP_TX_SUPPORT == _ON)
        ScalerDpTxMstHandler();
#endif

        ScalerDpRxMstStreamsHandler();

        if(GET_POWER_STATUS() != _POWER_STATUS_FAKE_OFF)
        {
            ScalerDpRxMstStreamMuxChangeHandler();
        }
    }
}
#endif
