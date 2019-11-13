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
// ID Code      : RTD2014UserTypeCInterface.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_TYPECINTERFACE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)
#if(_DP_TYPE_C_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Usb Hub Polling Par
//--------------------------------------------------
#define _USB_D0_HUB_POLLING_DEVICE_STEP         500 // Unit: ms
#define _USB_D1_HUB_POLLING_DEVICE_STEP         500 // Unit: ms
#define _USB_D2_HUB_POLLING_DEVICE_STEP         500 // Unit: ms
#define _USB_D6_HUB_POLLING_DEVICE_STEP         500 // Unit: ms
#define _USB_DX_HUB_POLLING_DEVICE_STEP         500 // Unit: ms

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD0PortControllerPower(void);
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD1PortControllerPower(void);
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD2PortControllerPower(void);
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
bit UserInterfaceTypeCGetD6PortControllerPower(void);
#endif

bit UserInterfaceTypeCPortControllerCheckAltMode(BYTE ucInputPort);
bit UserInterfaceTypeCPortControllerAltModeUserFlow(BYTE ucInputPort);
bit UserInterfaceTypeCPortControllerCableCheckUserFlow(BYTE ucInputPort);
BYTE UserInterfaceTypeCGetOsdLaneSelMode(BYTE ucInputPort);

#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
bit UserInterfaceTypeCPDO(BYTE ucInputPort);
#endif

bit UserInterfaceTypeCPortControllerSupport(BYTE ucInputPort);
void UserInterfaceTypeCPortControllerTypeCModeSwitch(BYTE ucInputPort);

#if(_DP_USB_HUB_SUPPORT == _ON)
bit UserInterfaceTypecUSBSupport(BYTE ucInputPort);
bit UserInterfaceTypecGetUSBSupportStatus(BYTE ucInputPort);

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB)
void UserInterfaceTypecSwitchDPLaneByUsbHubStatus(void);
#endif

WORD UserInterfaceTypecUsbHubSetPollingStep(BYTE ucInputPort);
bit UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(BYTE ucInputPort);
bit UserInterfaceTypecUsbHubSetSSMode(BYTE ucInputPort, bit bEn);
BYTE UserInterfaceTypecUsbHubDetectSSDevicePlugInfo(BYTE ucInputPort);
#endif // End of #if(_DP_USB_HUB_SUPPORT == _ON)

#if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)
bit UserInterfaceTypeCPortControllerConfig(BYTE ucInputPort);
#endif // End of #if(_USB_HUB_USERDECITION_SUPPORT == _ON)

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D0 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD0PortControllerPower(void)
{
    return _ON;
}
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D1 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD1PortControllerPower(void)
{
    return _ON;
}
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D2 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD2PortControllerPower(void)
{
    return _ON;
}
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D6 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserInterfaceTypeCGetD6PortControllerPower(void)
{
    return _ON;
}
#endif

//--------------------------------------------------
// Description  : User Decition Port Controller whether Enter Alt Mode
// Input Value  : ucInputPort --> Inputput
// Output Value : Decition Alt Mode result
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerCheckAltMode(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _FALSE;
            break;

        case _D1_INPUT_PORT:
            return _FALSE;
            break;

        case _D2_INPUT_PORT:
            return _FALSE;
            break;

        case _D3_INPUT_PORT:
            return _FALSE;
            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Alt Mode Decition By User Flow Support
// Input Value  : ucInputPort --> Inputput
// Output Value : _TRUE: Adopt User Flow, _FALSE: Adopt Kernal Flow
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerAltModeUserFlow(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _FALSE;
            break;

        case _D1_INPUT_PORT:
            return _FALSE;
            break;

        case _D2_INPUT_PORT:
            return _FALSE;
            break;

        case _D3_INPUT_PORT:
            return _FALSE;
            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Cable Check By User Flow Support
// Input Value  : ucInputPort --> Inputput
// Output Value : _TRUE: Adopt User Flow, _FALSE: Adopt Kernal Flow
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerCableCheckUserFlow(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _FALSE;
            break;

        case _D1_INPUT_PORT:
            return _FALSE;
            break;

        case _D2_INPUT_PORT:
            return _FALSE;
            break;

        case _D3_INPUT_PORT:
            return _FALSE;
            break;

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Get OSD lane Sel Mode
// Input Value  : ucInputPort --> Input Port
// Output Value : Lane Sel mode
//--------------------------------------------------
BYTE UserInterfaceTypeCGetOsdLaneSelMode(BYTE ucInputPort)
{
    BYTE ucLaneMode = _DP_LANE_AUTO_MODE;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D0_LANE_MODE();
            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D1_LANE_MODE();
            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D2_LANE_MODE();
            break;
#endif


#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            ucLaneMode = GET_OSD_DP_D6_LANE_MODE();
            break;
#endif
        default:
            break;
    }

    return ucLaneMode;
}

#if(_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : 5400 PD current & voltage calculate
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserInterfaceTypeCPDO(BYTE ucInputPort)
{
    WORD usTemp = 0;

    if(UserCommonPortControllerGetPdReadyFlag(ucInputPort) == _TRUE)
    {
        if(UserCommonPortControllerGetPDOStatus(ucInputPort) == _FAIL)
        {
            return _FAIL;
        }
    }
    else
    {
        return _FALSE;
    }

    // All Filed Element of g_unSMBusRdDataPool.stRdGetPDOStatus can be used here
    // For example:
    /*
    g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte0
    usTemp = (g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte0 + ((g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte1 & 0x03) << 8)) * 10;
    SET_OSDINFO_TYPEC_CURRENT(usTemp);

    usTemp = ((((g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte1 & 0xFC) >> 2)+ ((g_unSMBusRdDataPool.stRdGetPDOStatus.ucByte2 & 0xFF) << 6)) * 50);
    SET_OSDINFO_TYPEC_VOLTAGE(usTemp);
    */

    return _TRUE;
}
#endif

//--------------------------------------------------
// Description  : Get Type-C Port Controller Support
// Input Value  : InputPort
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerSupport(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return _TRUE;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return _TRUE;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return _TRUE;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return _TRUE;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : User Set OSD Menu Set Lane Mode Switched Flag
// Input Value  : InputPort
// Output Value : None
//--------------------------------------------------
void UserInterfaceTypeCPortControllerTypeCModeSwitch(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)

    UserCommonPortControllerSetSwitchToAutoModeFlg(ucInputPort, _TRUE);

    // Let Auto Mode Can Operate 5400 Connection Action
    UserCommonPortControllerSetCfgDetectFlag(ucInputPort, _ENABLE);
#endif

#endif
}

#if(_DP_USB_HUB_SUPPORT == _ON)
//--------------------------------------------------
// Description  : User Decide Wether Support USB Hub
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserInterfaceTypecUSBSupport(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            return _TRUE;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            return _TRUE;
#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            return _TRUE;
#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:

            return _TRUE;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit UserInterfaceTypecGetUSBSupportStatus(BYTE ucInputPort)
{
    if((SysPowerGetPowerStatus() == _POWER_STATUS_OFF) && ((GET_DP_DC_OFF_HPD_HIGH() == _OFF) || (UserInterfaceGetDpMSTCapablePort() != _DP_MST_NO_PORT)))
    {
        return _OFF;
    }

    switch(ucInputPort)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
        case _D0_INPUT_PORT:

            if(GET_OSD_DP_D0_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _D1_INPUT_PORT:

            if(GET_OSD_DP_D1_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;

#endif

#if(_D2_INPUT_PORT_TYPE == _D2_DP_PORT)
        case _D2_INPUT_PORT:

            if(GET_OSD_DP_D2_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;

#endif

#if(_D6_INPUT_PORT_TYPE == _D6_DP_PORT)
        case _D6_INPUT_PORT:
            if(GET_OSD_DP_D6_LANE_MODE() != _DP_FOUR_LANE)
            {
                return _ON;
            }

            break;

#endif

        default:
            break;
    }

    return _OFF;
}

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB)
//--------------------------------------------------
// Description  : User decided how many lanes to switch
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceTypecSwitchDPLaneByUsbHubStatus(void)
{
    BYTE ucUsbHubInfo = 0x00;

#if(_D0_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D0_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D0_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D0_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D0_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D0_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D0_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D0_LANES));
    }
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D1_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D1_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D1_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D1_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D1_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D1_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D1_LANES));
    }
#endif

#if(_D2_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D2_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D2_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D2_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D2_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D2_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D2_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D2_LANES));
    }
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
    if((SysDpGetUsbHubChangeFlg(_D6_INPUT_PORT) == _TRUE) && (GET_OSD_DP_D6_LANE_MODE() == _DP_LANE_AUTO_MODE))
    {
        ucUsbHubInfo = SysDpGetUsbHubDeviceInfo(_D6_INPUT_PORT);

        if(ucUsbHubInfo != 0x00)
        {
            UserCommonNVRamSetSystemData(_DP_D6_LANES, _DP_LINK_2_LANE);
            UserCommonNVRamSaveSystemData();
        }
        else
        {
            UserCommonNVRamSetSystemData(_DP_D6_LANES, _DP_LINK_4_LANE);
            UserCommonNVRamSaveSystemData();
        }

        ScalerDpLaneCountSwitch(_D6_INPUT_PORT, UserCommonNVRamGetSystemData(_DP_D6_LANES));
    }
#endif
}
#endif

//--------------------------------------------------
// Description  : User Set Usb Hub Polling SS Device Step
// Input Value  : ucInputPort --> Input Port
// Output Value : Usb Hub Polling Step Par.
//--------------------------------------------------
WORD UserInterfaceTypecUsbHubSetPollingStep(BYTE ucInputPort)
{
    if(ucInputPort == _D0_INPUT_PORT)
    {
        return _USB_D0_HUB_POLLING_DEVICE_STEP;
    }
    else if(ucInputPort == _D1_INPUT_PORT)
    {
        return _USB_D1_HUB_POLLING_DEVICE_STEP;
    }
    else if(ucInputPort == _D2_INPUT_PORT)
    {
        return _USB_D2_HUB_POLLING_DEVICE_STEP;
    }
    else if(ucInputPort == _D6_INPUT_PORT)
    {
        return _USB_D6_HUB_POLLING_DEVICE_STEP;
    }
    else
    {
        return _USB_DX_HUB_POLLING_DEVICE_STEP;
    }
}

//--------------------------------------------------
// Description  : Usb Hub RTS5400 Series User Flow Support
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE: User Flow, _FALSE: Kernal Flow
//--------------------------------------------------
bit UserInterfaceTypeCUsbHubU3InfoDectectUserFlow(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_USB_HUB_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            return _FALSE;
#endif

#if(_D1_DP_USB_HUB_SUPPORT == _ON)

        case _D1_INPUT_PORT:

            return _FALSE;
#endif

#if(_D6_DP_USB_HUB_SUPPORT == _ON)
        case _D6_INPUT_PORT:

            return _FALSE;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Set Usb Hub into SS Mode
// Input Value  : None
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserInterfaceTypecUsbHubSetSSMode(BYTE ucInputPort, bit bEn)
{
    ucInputPort = ucInputPort;
    bEn = bEn;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Detect Usb Hub SS Device Plug In
// Input Value  : ucInputPort --> Input Port
// Output Value : Return SS Device Info.
//--------------------------------------------------
BYTE UserInterfaceTypecUsbHubDetectSSDevicePlugInfo(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    return 0x00;
}
#endif // End of #if(_DP_USB_HUB_SUPPORT == _ON)

#if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Port Controller Config
// Input Value  : ucInputPort --> Input Port
// Output Value : return _TRUE / __FALSE
//--------------------------------------------------
bit UserInterfaceTypeCPortControllerConfig(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    return _TRUE;
}
#endif // End of #if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)
#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)
