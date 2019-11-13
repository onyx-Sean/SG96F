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
// ID Code      : UserCommonPortControllerRts5400.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_PORTCONTROLLER5400__

#include "UserCommonInclude.h"

#if(_DP_TYPE_C_SUPPORT == _ON)
#if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Enumerations Time of Type-C Cable Recheck After Reconnected
//--------------------------------------------------
#define _TYPE_C_RESTART_CHECK_CABLE_STATUS_TIME             2000 // Restart time 2s for after type-c reconnected

//--------------------------------------------------
// Enumerations of Type-C Related Macro
//--------------------------------------------------
#if(_DP_TYPE_C_SUPPORT == _ON)
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#define GET_TYPE_C_D0_CONFIG_MODE()                         (g_stTypeCD0ControllerInfo.b4ConfigMode)
#define SET_TYPE_C_D0_CONFIG_MODE(x)                        (g_stTypeCD0ControllerInfo.b4ConfigMode = (x))

#define GET_TYPE_C_D0_SWITCH_AUTOMODE_FALG()                (g_stTypeCD0ControllerInfo.b1SwitchToAutoMode)
#define SET_TYPE_C_D0_SWITCH_AUTOMODE_FALG(x)               (g_stTypeCD0ControllerInfo.b1SwitchToAutoMode = (x))
#endif

#define GET_TYPE_C_D0_PD_READY_FALG()                       (g_stTypeCD0ControllerInfo.b1PDReadyFlag)
#define SET_TYPE_C_D0_PD_READY_FALG()                       (g_stTypeCD0ControllerInfo.b1PDReadyFlag = _TRUE)
#define CLR_TYPE_C_D0_PD_READY_FALG()                       (g_stTypeCD0ControllerInfo.b1PDReadyFlag = _FALSE)

#define GET_TYPE_C_D0_ALT_MODE_FALG()                       (g_stTypeCD0ControllerInfo.b1AltModeFlag)
#define SET_TYPE_C_D0_ALT_MODE_FALG()                       (g_stTypeCD0ControllerInfo.b1AltModeFlag = _TRUE)
#define CLR_TYPE_C_D0_ALT_MODE_FALG()                       (g_stTypeCD0ControllerInfo.b1AltModeFlag = _FALSE)

#define GET_TYPE_C_D0_PIN_ASSIGNMENT_TYPE()                 (g_stTypeCD0ControllerInfo.b6PinAssignmentType)
#define SET_TYPE_C_D0_PIN_ASSIGNMENT_TYPE(x)                (g_stTypeCD0ControllerInfo.b6PinAssignmentType = (x))

#define GET_TYPE_C_D0_CONFIG_DETECT_FALG()                  (g_stTypeCD0ControllerInfo.b1ConfigDetectFlag)
#define SET_TYPE_C_D0_CONFIG_DETECT_FALG()                  (g_stTypeCD0ControllerInfo.b1ConfigDetectFlag = _TRUE)
#define CLR_TYPE_C_D0_CONFIG_DETECT_FALG()                  (g_stTypeCD0ControllerInfo.b1ConfigDetectFlag = _FALSE)
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#define GET_TYPE_C_D1_CONFIG_MODE()                         (g_stTypeCD1ControllerInfo.b4ConfigMode)
#define SET_TYPE_C_D1_CONFIG_MODE(x)                        (g_stTypeCD1ControllerInfo.b4ConfigMode = (x))

#define GET_TYPE_C_D1_SWITCH_AUTOMODE_FALG()                (g_stTypeCD1ControllerInfo.b1SwitchToAutoMode)
#define SET_TYPE_C_D1_SWITCH_AUTOMODE_FALG(x)               (g_stTypeCD1ControllerInfo.b1SwitchToAutoMode = (x))
#endif

#define GET_TYPE_C_D1_PD_READY_FALG()                       (g_stTypeCD1ControllerInfo.b1PDReadyFlag)
#define SET_TYPE_C_D1_PD_READY_FALG()                       (g_stTypeCD1ControllerInfo.b1PDReadyFlag = _TRUE)
#define CLR_TYPE_C_D1_PD_READY_FALG()                       (g_stTypeCD1ControllerInfo.b1PDReadyFlag = _FALSE)

#define GET_TYPE_C_D1_ALT_MODE_FALG()                       (g_stTypeCD1ControllerInfo.b1AltModeFlag)
#define SET_TYPE_C_D1_ALT_MODE_FALG()                       (g_stTypeCD1ControllerInfo.b1AltModeFlag = _TRUE)
#define CLR_TYPE_C_D1_ALT_MODE_FALG()                       (g_stTypeCD1ControllerInfo.b1AltModeFlag = _FALSE)

#define GET_TYPE_C_D1_PIN_ASSIGNMENT_TYPE()                 (g_stTypeCD1ControllerInfo.b6PinAssignmentType)
#define SET_TYPE_C_D1_PIN_ASSIGNMENT_TYPE(x)                (g_stTypeCD1ControllerInfo.b6PinAssignmentType = (x))

#define GET_TYPE_C_D1_CONFIG_DETECT_FALG()                  (g_stTypeCD1ControllerInfo.b1ConfigDetectFlag)
#define SET_TYPE_C_D1_CONFIG_DETECT_FALG()                  (g_stTypeCD1ControllerInfo.b1ConfigDetectFlag = _TRUE)
#define CLR_TYPE_C_D1_CONFIG_DETECT_FALG()                  (g_stTypeCD1ControllerInfo.b1ConfigDetectFlag = _FALSE)
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#define GET_TYPE_C_D2_CONFIG_MODE()                         (g_stTypeCD2ControllerInfo.b4ConfigMode)
#define SET_TYPE_C_D2_CONFIG_MODE(x)                        (g_stTypeCD2ControllerInfo.b4ConfigMode = (x))

#define GET_TYPE_C_D2_SWITCH_AUTOMODE_FALG()                (g_stTypeCD2ControllerInfo.b1SwitchToAutoMode)
#define SET_TYPE_C_D2_SWITCH_AUTOMODE_FALG(x)               (g_stTypeCD2ControllerInfo.b1SwitchToAutoMode = (x))
#endif

#define GET_TYPE_C_D2_PD_READY_FALG()                       (g_stTypeCD2ControllerInfo.b1PDReadyFlag)
#define SET_TYPE_C_D2_PD_READY_FALG()                       (g_stTypeCD2ControllerInfo.b1PDReadyFlag = _TRUE)
#define CLR_TYPE_C_D2_PD_READY_FALG()                       (g_stTypeCD2ControllerInfo.b1PDReadyFlag = _FALSE)

#define GET_TYPE_C_D2_ALT_MODE_FALG()                       (g_stTypeCD2ControllerInfo.b1AltModeFlag)
#define SET_TYPE_C_D2_ALT_MODE_FALG()                       (g_stTypeCD2ControllerInfo.b1AltModeFlag = _TRUE)
#define CLR_TYPE_C_D2_ALT_MODE_FALG()                       (g_stTypeCD2ControllerInfo.b1AltModeFlag = _FALSE)

#define GET_TYPE_C_D2_PIN_ASSIGNMENT_TYPE()                 (g_stTypeCD2ControllerInfo.b6PinAssignmentType)
#define SET_TYPE_C_D2_PIN_ASSIGNMENT_TYPE(x)                (g_stTypeCD2ControllerInfo.b6PinAssignmentType = (x))

#define GET_TYPE_C_D2_CONFIG_DETECT_FALG()                  (g_stTypeCD2ControllerInfo.b1ConfigDetectFlag)
#define SET_TYPE_C_D2_CONFIG_DETECT_FALG()                  (g_stTypeCD2ControllerInfo.b1ConfigDetectFlag = _TRUE)
#define CLR_TYPE_C_D2_CONFIG_DETECT_FALG()                  (g_stTypeCD2ControllerInfo.b1ConfigDetectFlag = _FALSE)
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#define GET_TYPE_C_D6_CONFIG_MODE()                         (g_stTypeCD6ControllerInfo.b4ConfigMode)
#define SET_TYPE_C_D6_CONFIG_MODE(x)                        (g_stTypeCD6ControllerInfo.b4ConfigMode = (x))

#define GET_TYPE_C_D6_SWITCH_AUTOMODE_FALG()                (g_stTypeCD6ControllerInfo.b1SwitchToAutoMode)
#define SET_TYPE_C_D6_SWITCH_AUTOMODE_FALG(x)               (g_stTypeCD6ControllerInfo.b1SwitchToAutoMode = (x))
#endif

#define GET_TYPE_C_D6_PD_READY_FALG()                       (g_stTypeCD6ControllerInfo.b1PDReadyFlag)
#define SET_TYPE_C_D6_PD_READY_FALG()                       (g_stTypeCD6ControllerInfo.b1PDReadyFlag = _TRUE)
#define CLR_TYPE_C_D6_PD_READY_FALG()                       (g_stTypeCD6ControllerInfo.b1PDReadyFlag = _FALSE)

#define GET_TYPE_C_D6_ALT_MODE_FALG()                       (g_stTypeCD6ControllerInfo.b1AltModeFlag)
#define SET_TYPE_C_D6_ALT_MODE_FALG()                       (g_stTypeCD6ControllerInfo.b1AltModeFlag = _TRUE)
#define CLR_TYPE_C_D6_ALT_MODE_FALG()                       (g_stTypeCD6ControllerInfo.b1AltModeFlag = _FALSE)

#define GET_TYPE_C_D6_PIN_ASSIGNMENT_TYPE()                 (g_stTypeCD6ControllerInfo.b6PinAssignmentType)
#define SET_TYPE_C_D6_PIN_ASSIGNMENT_TYPE(x)                (g_stTypeCD6ControllerInfo.b6PinAssignmentType = (x))

#define GET_TYPE_C_D6_CONFIG_DETECT_FALG()                  (g_stTypeCD6ControllerInfo.b1ConfigDetectFlag)
#define SET_TYPE_C_D6_CONFIG_DETECT_FALG()                  (g_stTypeCD6ControllerInfo.b1ConfigDetectFlag = _TRUE)
#define CLR_TYPE_C_D6_CONFIG_DETECT_FALG()                  (g_stTypeCD6ControllerInfo.b1ConfigDetectFlag = _FALSE)
#endif

#endif

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef struct
{
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
    BYTE b1SwitchToAutoMode : 1;
#endif
    BYTE b4ConfigMode : 4;
#endif
    BYTE b1PDReadyFlag : 1;
    BYTE b1AltModeFlag : 1;
    BYTE b1ConfigDetectFlag : 1;
    BYTE b6PinAssignmentType : 6;
} StructPortControllerInfo;

//****************************************************************************
// CODE TABLES
//****************************************************************************
// Write Command && Read Command
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
code StructSMBusWRGetICStatus tSMBusWrCmdGetICStatus[1] = {{0x3A, 0x03, 0x08, 0x00, 0x01}};
code StructSMBusRDGetICStatus tSMBusRdCmdGetICStatus[1] = {{0x80, 0x02, 0x00}};

code StructSMBusWRReadDPLanes tSMBusWrCmdReadDpCapVdoSelf[1] = {{0x08, 0x04, 0x9A, 0x00, 0x01, 0x0C}};
code StructSMBusWRReadDPLanes tSMBusWrCmdReadDpCapVdoPartner[1] = {{0x08, 0x04, 0x9A, 0x00, 0x09, 0x0C}};
code StructSMBusRDReadDPLanesCfg tSMBusRdCmdDPCapVdo[1] = {{0x80, 0x05, 0x45, 0x04, 0x00, 0x00}};

code StructSMBusWRGetStatus tSMBusWrGetStatus[1] = {{0x09, 0x03, 0x00, 0x00, 0x0E}};
code StructSMBusRDGetStatus tSMBusRDGetStatus[1] = {{0x80, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};

code StructSMBusWRReadDPLanes tSMBusWrCmdReadDPCfgVdoSelf[1] = {{0x08, 0x04, 0x9A, 0x00, 0x01, 0x0E}};
code StructSMBusWRReadDPLanes tSMBusWrCmdReadDPCfgVdoPartner[1] = {{0x08, 0x04, 0x9A, 0x00, 0x09, 0x0E}};
code StructSMBusRDReadDPLanesCfg tSMBusRdCmdReadDPCfgVdo[1] = {{0x80, 0x05, 0x06, 0x04, 0x00, 0x00}};
#else
code StructSMBusWRGetICStatus tSMBusWrCmdGetICStatus[1] = {{0x3A, 0x01, 0x14}};
code StructSMBusRDGetICStatus tSMBusRdCmdGetICStatus[1] = {{0x80, 0x15, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
#endif

code StructSMBusWRSetDPLanes tSMBusWrCmdSetDPCapVdoSelf[1] = {{0x08, 0x08, 0x1A, 0x00, 0x01, 0x0C, 0x45, 0x00, 0x08, 0x00}};

code StructSMBusWRSetDPLanes tSMBusWrCmdSetDPCfgVdoSelf[1] = {{0x08, 0x08, 0x1A, 0x00, 0x01, 0x0E, 0x05, 0x04, 0x00, 0x00}};

code StructSMBusWRSetDPMultiFunction tSMBusWrCmdSetDPMultiFunction[1] = {{0x08, 0x08, 0x1A, 0x00, 0x01, 0x0D, 0x18, 0x00, 0x00, 0x00}};
code StructSMBusWRReadDPMultiFunction tSMBusWrCmdReadDPMultiFunction[1] = {{0x08, 0x04, 0x9A, 0x00, 0x01, 0x0D}};
code StructSMBusRDReadDPMultiFunction tSMBusRdCmdDPMultiFunction[1] = {{0x80, 0x05, 0x08, 0x00, 0x00, 0x00}};

code StructSMBusWRReconnect tSMBusWrCmdSetReconnect[1] = {{0x08, 0x03, 0x1F, 0x00, 0x01}};

code StructSMBusRDCommandReadyStatus tSMBusRdCmdCommandReadyStatus[1] = {{0x00, 0x00}};

code StructSMBusRDReadDPLanes tSMBusRdCmdDPlanes[1] = {{0x80, 0x05, 0x45, 0x00, 0x08, 0x00}};

#if(_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON)
code StructSMBusWRGetPDOStatus tSMBusWrCmdGetPDOPartnerStatus[1] = {{0x08, 0x03, 0x83, 0x00, 0xE3}};
code StructSMBusRDGetPDOStatus tSMBusRdCmdGetPDOPartnerStatus[1] = {{0x80, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}};
#endif


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
StructPortControllerInfo g_stTypeCD0ControllerInfo;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
StructPortControllerInfo g_stTypeCD1ControllerInfo;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
StructPortControllerInfo g_stTypeCD2ControllerInfo;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
StructPortControllerInfo g_stTypeCD6ControllerInfo;
#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE UserCommonPortControllerGetPCAddr(BYTE ucInputPort);
bit UserCommonPortControllerGetPCStatus(BYTE ucInputPort);
bit UserCommonPortControllerCheckPCEnterAltMode(BYTE ucInputPort);
bit UserCommonPortControllerSetPCDPMultiFunction(BYTE ucInputPort, bit bMultiFunction);
bit UserCommonPortControllerSetPinAssignment(BYTE ucInputPort, BYTE ucPinAssignment, BYTE ucDfpUfpFlag);
BYTE UserCommonPortControllerGetPinAssignment(bit bAutoMode, BYTE ucOsdDpLaneCnt, BYTE ucUfpDfpMode, BYTE ucPinAssignmentCap);
bit UserCommonPortControllerReconnect(BYTE ucInputPort);
bit UserCommonPortControllerConfigDetect(BYTE ucInputPort);
bit UserCommonPortControllerGetInputCableStatus(BYTE ucInputPort);
bit UserCommonPortControllerConfig(BYTE ucInputPort);
void UserCommonPortControllerRestartCheckCableTime(BYTE ucInputPort, WORD usTime);
void UserCommonPortControllerSetCfgDetectFlag(BYTE ucInputPort, bit bEnable);
bit UserCommonPortControllerGetCfgDetectFlag(BYTE ucInputPort);
void UserCommonPortControllerSetAltModeFlag(BYTE ucInputPort, bit bFlag);
bit UserCommonPortControllerGetAltModeFlag(BYTE ucInputPort);
void UserCommonPortControllerSetPdReadyFlag(BYTE ucInputPort, bit bFlag);
bit UserCommonPortControllerGetPdReadyFlag(BYTE ucInputPort);
void UserCommonPortControllerSetPinAssignmentType(BYTE ucInputPort, BYTE ucPinAssignment);
BYTE UserCommonPortControllerGetPinAssignmentType(BYTE ucInputPort);
bit UserCommonPortControllerCheckReConfigFlag(BYTE ucInputPort);
bit UserCommonPortControllerCheckReconnect(BYTE ucInputPort);
void UserCommonPortControllerDoAfterReconnect(BYTE ucInputPort);

#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
bit UserCommonPortControllerGetPCCfgVdoSelf(BYTE ucInputPort);
bit UserCommonPortControllerGetCapVdoSrc(BYTE ucInputPort, BYTE ucDfpUfpFlag);
void UserCommonPortControllerPinMappingSetting(BYTE ucInputPort, BYTE ucPinAssignType);
void UserCommonPortControllerSaveLaneCfg(BYTE ucInputPort, BYTE ucLastDPLaneCount, BYTE ucNewPinAssignment);
bit UserCommonPortControllerGetSwitchToAutoModeFlg(BYTE ucInputPort);
void UserCommonPortControllerSetSwitchToAutoModeFlg(BYTE ucInputPort, bit bFlg);
#endif

bit UserCommonPortControllerGetStatus(BYTE ucInputPort);
BYTE UserCommonPortControllerCheckDfpUfpMode(BYTE ucCfgInfo);
void UserCommonPortControllerSetCfgMode(BYTE ucInputPort, BYTE ucCfgMode);
BYTE UserCommonPortControllerGetCfgMode(BYTE ucInputPort);
#endif

#if(_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON)
bit UserCommonPortControllerGetPDOStatus(BYTE ucInputPort);
#endif

#if(_D0_DP_TYPE_C_SUPPORT == _ON)
bit UserCommonPortControllerGetD0PortPower(void);
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
bit UserCommonPortControllerGetD1PortPower(void);
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
bit UserCommonPortControllerGetD2PortPower(void);
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
bit UserCommonPortControllerGetD6PortPower(void);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get Port Controller Slave Address
// Input Value  : ucInputPort --> Input Port
// Output Value : Slave Address
//--------------------------------------------------
BYTE UserCommonPortControllerGetPCAddr(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
        case _D0_INPUT_PORT:
            return _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR;

        case _D1_INPUT_PORT:
            return _D1_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR;

        case _D2_INPUT_PORT:
            return _D2_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR;

        case _D6_INPUT_PORT:
            return _D6_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR;

        default:
            break;
    }

    return _D0_DP_TYPE_C_PORT_CTRL_SLAVE_ADDR;
}

//--------------------------------------------------
// Description  : Read IC Status from the 5400/5411 by SMBus
// Input Value  : None
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerGetPCStatus(BYTE ucInputPort)
{
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, tSMBusWrCmdGetICStatus[0].ucCommandCode, 1, tSMBusWrCmdGetICStatus[0].ucDataLength + 1, ((BYTE *)&tSMBusWrCmdGetICStatus[0].ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Read Back Device Reply Data
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
    if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRdCmdGetICStatus[0].ucCommandCode, 1, tSMBusRdCmdGetICStatus[0].ucDataLength, &(g_unSMBusRdDataPool.stRdGetICStatus.ucByte7), ucInputPort) == _FAIL)
#else
    if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRdCmdGetICStatus[0].ucCommandCode, 1, tSMBusRdCmdGetICStatus[0].ucDataLength, &(g_unSMBusRdDataPool.stRdGetICStatus.ucDataLength), ucInputPort) == _FAIL)
#endif
    {
        return _FAIL;
    }

    // Fill in Original Subcommand Code for g_unSMBusRdDataPool structure
    g_unSMBusRdDataPool.stRdGetICStatus.ucCommandCode = tSMBusRdCmdGetICStatus[0].ucCommandCode;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Check 5400 Enter Alt Mode
// Input Value  : ucInputPort --> Inputput
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerCheckPCEnterAltMode(BYTE ucInputPort)
{
    if(UserInterfaceTypeCPortControllerAltModeUserFlow(ucInputPort) == _TRUE)
    {
        if(UserInterfaceTypeCPortControllerCheckAltMode(ucInputPort) == _TRUE)
        {
            // Enter Alt Mode
            return _TRUE;
        }
        else
        {
            // Not Enter Alt Mode
            return _FALSE;
        }
    }
    else
    {
        // Get 5400 Enter Alt Mode
        if(UserCommonPortControllerGetPCStatus(ucInputPort) == _FAIL)
        {
            return _FALSE;
        }

        DebugMessageSystem("8. Type-C Get IC Status", g_unSMBusRdDataPool.stRdGetICStatus.ucPDTypeCStatus);

        // _BIT3: = 1 Expression Type-C  Connected
        if((g_unSMBusRdDataPool.stRdGetICStatus.ucPDTypeCStatus & _BIT3) == _BIT3)
        {
            return _TRUE; // Enter Alt Mode Already
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Set 5400 IC DP MultiFunction
// Input Value  : bMultiFunction --> _TRUE: Support Usb + DP Function, _FALSE: DP Function only
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerSetPCDPMultiFunction(BYTE ucInputPort, bit bMultiFunction)
{
    StructSMBusWRSetDPMultiFunction stDpMultiFunction;
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    memcpy(&stDpMultiFunction, ((BYTE *)&tSMBusWrCmdSetDPMultiFunction[0]), tSMBusWrCmdSetDPMultiFunction[0].ucDataLength + 2);

    if(bMultiFunction == _TRUE)
    {
        // Set to Multifunction Prefer
        stDpMultiFunction.ucDPCapVDOByte0 = 0x18;
    }
    else
    {
        // Set to Multifunction Not Prefer
        stDpMultiFunction.ucDPCapVDOByte0 = 0x08;
    }

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, stDpMultiFunction.ucCommandCode, 1, stDpMultiFunction.ucDataLength + 1, &stDpMultiFunction.ucDataLength, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Set 5400 DP Lanes Counter
// Input Value  : None
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerSetPinAssignment(BYTE ucInputPort, BYTE ucPinAssignment, BYTE ucDfpUfpFlag)
{
    StructSMBusWRSetDPLanes stDpLaneConfigPar;
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    if(ucDfpUfpFlag == _TYPE_C_DFP_U)
    {
        memcpy(&stDpLaneConfigPar, &tSMBusWrCmdSetDPCfgVdoSelf[0], tSMBusWrCmdSetDPCfgVdoSelf[0].ucDataLength + 2);
    }
    else
    {
        memcpy(&stDpLaneConfigPar, &tSMBusWrCmdSetDPCapVdoSelf[0], tSMBusWrCmdSetDPCapVdoSelf[0].ucDataLength + 2);
    }

    if(ucDfpUfpFlag == _TYPE_C_DFP_U)
    {
        stDpLaneConfigPar.ucDPCapVDOByte1 = ucPinAssignment;
    }
    else
    {
        stDpLaneConfigPar.ucDPCapVDOByte2 = ucPinAssignment;
    }

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, stDpLaneConfigPar.ucCommandCode, 1, stDpLaneConfigPar.ucDataLength + 1, &stDpLaneConfigPar.ucDataLength, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Pin assignment mapping
// Input Value  : ucAutoMode         --> Auto Mode
//                ucOsdDpLaneCnt     --> User Want to change lane count
//                ucUfpDfpMode       --> DFP or UFP Mode
//                ucPinAssignmentCap --> Source Support Pin Assignment Type
// Output Value : Pin Assignment Type
//--------------------------------------------------
BYTE UserCommonPortControllerGetPinAssignment(bit bAutoMode, BYTE ucOsdDpLaneCnt, BYTE ucUfpDfpMode, BYTE ucPinAssignmentCap)
{
    if(bAutoMode == _TRUE)
    {
        if(ucUfpDfpMode == _TYPE_C_DFP_U)
        {
            if((ucPinAssignmentCap & _BIT5) == _BIT5) // Pin Assignment F 2 lane only
            {
                return _TYPE_C_PIN_ASSIGNMENT_F;
            }
            else if((ucPinAssignmentCap & _BIT4) == _BIT4) // Pin Assignment E (google cable case)
            {
                return _TYPE_C_PIN_ASSIGNMENT_E;
            }
            else if((ucPinAssignmentCap & _BIT3) == _BIT3) // Pin Assignment D 2 lane only
            {
                return _TYPE_C_PIN_ASSIGNMENT_D;
            }
            else if((ucPinAssignmentCap & _BIT2) == _BIT2) // Pin Assignment C 4 lane only
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
            else
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
        }
        else
        {
            if(ucPinAssignmentCap == 0x04)
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
            else if(ucPinAssignmentCap == 0x08)
            {
                return _TYPE_C_PIN_ASSIGNMENT_D;
            }
            else
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
        }
    }
    else
    {
        if(ucUfpDfpMode == _TYPE_C_DFP_U)
        {
            if(ucOsdDpLaneCnt == _DP_LINK_4_LANE)
            {
                if((ucPinAssignmentCap & _BIT4) == _BIT4) // Pin Assignment E (google cable case)
                {
                    return _TYPE_C_PIN_ASSIGNMENT_E;
                }
                else
                {
                    return _TYPE_C_PIN_ASSIGNMENT_C;
                }
            }
            else if(ucOsdDpLaneCnt == _DP_LINK_2_LANE)
            {
                return _TYPE_C_PIN_ASSIGNMENT_D;
            }
            else
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
        }
        else
        {
            if(ucOsdDpLaneCnt == _DP_LINK_4_LANE)
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
            else if(ucOsdDpLaneCnt == _DP_LINK_2_LANE)
            {
                return _TYPE_C_PIN_ASSIGNMENT_D;
            }
            else
            {
                return _TYPE_C_PIN_ASSIGNMENT_C;
            }
        }
    }
}

//--------------------------------------------------
// Description  : Reconnect 5400 Device
// Input Value  : None
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerReconnect(BYTE ucInputPort)
{
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, tSMBusWrCmdSetReconnect[0].ucCommandCode, 1, tSMBusWrCmdSetReconnect[0].ucDataLength + 1, ((BYTE *)&tSMBusWrCmdSetReconnect[0].ucDataLength), ucInputPort) == _FAIL)
    {
        DebugMessageSystem("ReConnet Fail Wr fail", 1);

        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 500, ucInputPort) == _FAIL)
    {
        DebugMessageSystem("ReConnet Polling Fail ", 1);

        return _FAIL;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : 5400 Auto Detect Config Result
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerConfigDetect(BYTE ucInputPort)
{
    BYTE ucDPLanes = _DP_TWO_LANE;

    if(UserCommonPortControllerGetInputCableStatus(ucInputPort) == _FALSE)
    {
        DebugMessageSystem("8. Cable Connect Flag", 0);

        return _FALSE;
    }

    if(UserCommonPortControllerGetCfgDetectFlag(ucInputPort) == _ENABLE)
    {
        // Get 5400 IC Status
        if(UserCommonPortControllerGetPCStatus(ucInputPort) == _FAIL)
        {
            DebugMessageSystem("8. Get Type-C Status Fail", 0);

            return _FAIL;
        }
        DebugMessageSystem("8. Get Type-C Get PC Status", g_unSMBusRdDataPool.stRdGetICStatus.ucPDTypeCStatus);

        if((g_unSMBusRdDataPool.stRdGetICStatus.ucPDTypeCStatus & (_BIT3 | _BIT0)) == (_BIT3 | _BIT0))
        {
            DebugMessageSystem("8. Get Type-C PD Ready", g_unSMBusRdDataPool.stRdGetICStatus.ucPDTypeCStatus);

            UserCommonPortControllerSetPdReadyFlag(ucInputPort, _TRUE);
        }
        else
        {
            DebugMessageSystem("8. Type-C Connected Status", g_unSMBusRdDataPool.stRdGetICStatus.ucPDTypeCStatus);

            return _FAIL;
        }

#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
        ScalerTimerDelayXms(50);

        if(UserCommonPortControllerGetStatus(ucInputPort) == _FAIL)
        {
            DebugMessageSystem("8. Type-C Get Status Fail", 0);

            return _FAIL;
        }

        DebugMessageSystem("8. Get Type-C Get Status", g_unSMBusRdDataPool.stRdGetStatus.ucByte13_AltModeStatus);

        if((g_unSMBusRdDataPool.stRdGetStatus.ucByte13_AltModeStatus == 0x06) || // == 0x06 enter alt mode
           (g_unSMBusRdDataPool.stRdGetStatus.ucByte13_AltModeStatus == 0x05))
        {
            DebugMessageSystem("8. Type-C Enter Alt Mode", 1);

            UserCommonPortControllerSetAltModeFlag(ucInputPort, _TRUE);
        }
        else
        {
            DebugMessageSystem("8. Type-C Not Enter Alt Mode", g_unSMBusRdDataPool.stRdGetStatus.ucByte13_AltModeStatus);

            UserCommonPortControllerSetAltModeFlag(ucInputPort, _FALSE);

            return _FAIL; // Have not enter alt mode
        }

        if(UserCommonPortControllerCheckDfpUfpMode(g_unSMBusRdDataPool.stRdGetStatus.ucByte10_DFP_UFP) == _TYPE_C_DFP_U) // DFP_U Configed
        {
            DebugMessageSystem("8. Type-C Config DFP_U Mode", _TYPE_C_DFP_U);

            UserCommonPortControllerSetCfgMode(ucInputPort, _TYPE_C_DFP_U);
        }
        else
        {
            DebugMessageSystem("8. Type-C Config UFP_U Mode", _TYPE_C_UFP_U);

            UserCommonPortControllerSetCfgMode(ucInputPort, _TYPE_C_UFP_U);
        }

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
        if(UserInterfaceTypeCGetOsdLaneSelMode(ucInputPort) == _DP_LANE_AUTO_MODE)
        {
            ucDPLanes = UserInterfaceGetDpLaneCount(ucInputPort);
            DebugMessageSystem("8. Type-C Auto Mode DPCD Table Lane Count", ucDPLanes);

            if(UserCommonPortControllerGetCfgMode(ucInputPort) == _TYPE_C_DFP_U)
            {
                // User switch Type-C mode to auto after lit up
                if(UserCommonPortControllerGetSwitchToAutoModeFlg(ucInputPort) == _TRUE)
                {
                    // For Get VDO partner caparbility
                    if(UserCommonPortControllerGetCapVdoSrc(ucInputPort, _TYPE_C_DFP_U) == _FAIL)
                    {
                        return _FAIL;
                    }

                    UserCommonPortControllerSetPinAssignmentType(ucInputPort, (UserCommonPortControllerGetPinAssignment(_TRUE, ucDPLanes, _TYPE_C_DFP_U, g_unSMBusRdDataPool.stRdDpCap.ucDPCfgPinConfig)));
                }
                else // Ac On or cable plug in
                {
                    if(UserCommonPortControllerGetPCCfgVdoSelf(ucInputPort) == _FAIL)
                    {
                        return _FAIL;
                    }

                    if(g_unSMBusRdDataPool.stRdDPlanesCfg.ucDPCfgPinConfig == _TYPE_C_PIN_ASSIGNMENT_E)
                    {
                        DebugMessageSystem("8. Pin Assignment E Mode Swap", 1);

                        UserCommonPortControllerPinMappingSetting(ucInputPort, _DP_LANE_MAPPING_TYPE_C_ASSIGNMENT_E_TYPE);
                    }
                    else
                    {
                        DebugMessageSystem("8. Pin Assignment Normal Mode ", g_unSMBusRdDataPool.stRdDPlanesCfg.ucDPCfgPinConfig);

                        UserCommonPortControllerPinMappingSetting(ucInputPort, _DP_LANE_MAPPING_NORMAL_TYPE);
                    }

                    UserCommonPortControllerSetPinAssignmentType(ucInputPort, (UserCommonPortControllerGetPinAssignment(_TRUE, ucDPLanes, _TYPE_C_DFP_U, g_unSMBusRdDataPool.stRdDPlanesCfg.ucDPCfgPinConfig)));
                }

                DebugMessageSystem("8. Pin Assignment Type", UserCommonPortControllerGetPinAssignmentType(ucInputPort));
            }
            else
            {
                UserCommonPortControllerPinMappingSetting(ucInputPort, _DP_LANE_MAPPING_NORMAL_TYPE);

                if(UserCommonPortControllerGetCapVdoSrc(ucInputPort, _TYPE_C_UFP_U) == _FAIL)
                {
                    return _FAIL;
                }

                DebugMessageSystem("8. Original Pin Assignment Type", UserCommonPortControllerGetPinAssignmentType(ucInputPort));

                // User switch Type-C mode to auto after lit up
                if(UserCommonPortControllerGetSwitchToAutoModeFlg(ucInputPort) == _TRUE)
                {
                    // Force Set Cpa VDO Selt is _TYPE_C_PIN_ASSIGNMENT_CD
                    UserCommonPortControllerSetPinAssignmentType(ucInputPort, _TYPE_C_PIN_ASSIGNMENT_CD);
                }
                else
                {
                    // Refer to Port Partner VDO Cfg
                    UserCommonPortControllerSetPinAssignmentType(ucInputPort, (UserCommonPortControllerGetPinAssignment(_TRUE, ucDPLanes, _TYPE_C_UFP_U, g_unSMBusRdDataPool.stRdDPlanesCfg.ucDPCfgPinConfig)));
                }

                DebugMessageSystem("8. Pin Assignment Type", UserCommonPortControllerGetPinAssignmentType(ucInputPort));
            }

            UserCommonPortControllerSaveLaneCfg(ucInputPort, ucDPLanes, UserCommonPortControllerGetPinAssignmentType(ucInputPort));
            UserCommonPortControllerSetCfgDetectFlag(ucInputPort, _DISABLE);

            DebugMessageSystem("8. Type-C Auto Detect Config Pass", 1);

            return _TRUE;
        }
#endif // End of #if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
#endif // End of #if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)

        UserCommonPortControllerSetCfgDetectFlag(ucInputPort, _DISABLE);
    }

    if(SysDpTypeCGetInputLaneStatus(ucInputPort) != UserInterfaceGetDpLaneCount(ucInputPort))
    {
        ucDPLanes = UserInterfaceGetDpLaneCount(ucInputPort);
        DebugMessageSystem("8. Type-C Manual Mode DPCD Table Lane Count", ucDPLanes);

        if(UserInterfaceTypeCGetOsdLaneSelMode(ucInputPort) == _DP_TWO_LANE)
        {
            UserCommonPortControllerSetPinAssignmentType(ucInputPort, (UserCommonPortControllerGetPinAssignment(_FALSE, ucDPLanes, _TYPE_C_UFP_U, _TYPE_C_PIN_ASSIGNMENT_D)));

            DebugMessageSystem("8. TWO_LANE - Pin Assignment Type", UserCommonPortControllerGetPinAssignmentType(ucInputPort));
        }
        else // _DP_FOUR_LANE
        {
            UserCommonPortControllerSetPinAssignmentType(ucInputPort, (UserCommonPortControllerGetPinAssignment(_FALSE, ucDPLanes, _TYPE_C_UFP_U, _TYPE_C_PIN_ASSIGNMENT_C)));

            DebugMessageSystem("8. FOUR_LANE - Pin Assignment Type", UserCommonPortControllerGetPinAssignmentType(ucInputPort));
        }
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get Input Port Cable Status
// Input Value  : ucInputPort --> Input Port
// Output Value : Cable Status
//--------------------------------------------------
bit UserCommonPortControllerGetInputCableStatus(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_D0_CABLE_STATUS();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_D1_CABLE_STATUS();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_D2_CABLE_STATUS();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_D6_CABLE_STATUS();
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : 5400 Config
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerConfig(BYTE ucInputPort)
{
    bit bMultiFunctionFlag = _FALSE;

    if(UserCommonPortControllerCheckReConfigFlag(ucInputPort) == _TRUE)
    {
        DebugMessageSystem("8. Type-C Config Pinassignment Type", UserCommonPortControllerGetPinAssignmentType(ucInputPort));

        if(UserCommonPortControllerGetPinAssignmentType(ucInputPort) == _TYPE_C_PIN_ASSIGNMENT_D)
        {
            bMultiFunctionFlag = _TRUE;
        }

#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
        if(UserCommonPortControllerGetCfgMode(ucInputPort) == _TYPE_C_DFP_U)
        {
#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
            if(((UserInterfaceTypeCGetOsdLaneSelMode(ucInputPort) == _DP_LANE_AUTO_MODE) &&
                (UserCommonPortControllerGetSwitchToAutoModeFlg(ucInputPort) == _TRUE)) ||
               (UserInterfaceTypeCGetOsdLaneSelMode(ucInputPort) != _DP_LANE_AUTO_MODE))
#endif
            {
                // Set Dp Lane
                if(UserCommonPortControllerSetPinAssignment(ucInputPort, UserCommonPortControllerGetPinAssignmentType(ucInputPort), _TYPE_C_DFP_U) == _FAIL)
                {
                    DebugMessageSystem("8. Type-C DFP_U Pin Assignment Setting Fail", 0);

                    return _FAIL;
                }
            }
        }
        else
#endif
        {
            // Set Dp Multifuncton
            if(UserCommonPortControllerSetPCDPMultiFunction(ucInputPort, bMultiFunctionFlag) == _FAIL)
            {
                DebugMessageSystem("8. Type-C UFP_U MultiFunction Setting Fail", 0);

                return _FAIL;
            }

            // Set Dp Lane
            if(UserCommonPortControllerSetPinAssignment(ucInputPort, UserCommonPortControllerGetPinAssignmentType(ucInputPort), _TYPE_C_UFP_U) == _FAIL)
            {
                DebugMessageSystem("8. Type-C UFP_U Pin Assignment Setting Fail", 0);

                return _FAIL;
            }
        }

        if(UserCommonPortControllerCheckReconnect(ucInputPort) == _TRUE)
        {
            DebugMessageSystem("8. Type-C Reconnect", 1);

            if(UserCommonPortControllerGetPdReadyFlag(ucInputPort) == _TRUE)
            {
                if(UserCommonPortControllerReconnect(ucInputPort) == _FAIL)
                {
                    DebugMessageSystem("8. Type-C Reconnect Fail", 0);

                    return _FAIL;
                }
            }

            // Do some thing after reconnect
            UserCommonPortControllerDoAfterReconnect(ucInputPort);

            // Reconnect will take up 500~1000ms to Type-C Connected state
            UserCommonPortControllerRestartCheckCableTime(ucInputPort, _TYPE_C_RESTART_CHECK_CABLE_STATUS_TIME);
        }

        DebugMessageSystem("8. Type-C Pin Assignment Config Successfull", 1);

        return _TRUE;
    }
    else
    {
        DebugMessageSystem("8. Type-C Config Condition Not Ready", 0);

        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : 5400 Set Config ReStart Time Check Type-c Cable Status
// Input Value  : ucInputPort --> Input Port
//                bEnable     --> Enable/Disable
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
void UserCommonPortControllerRestartCheckCableTime(BYTE ucInputPort, WORD usTime)
{
    ucInputPort = ucInputPort;
    usTime = usTime;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            SysDpTypeCReactiveD0AltModeCheck(usTime);

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            SysDpTypeCReactiveD1AltModeCheck(usTime);

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            SysDpTypeCReactiveD2AltModeCheck(usTime);

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            SysDpTypeCReactiveD6AltModeCheck(usTime);

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : 5400 Set Config Detect Flag
// Input Value  : ucInputPort --> Input Port
//                bEnable     --> Enable/Disable
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
void UserCommonPortControllerSetCfgDetectFlag(BYTE ucInputPort, bit bEnable)
{
    ucInputPort = ucInputPort;
    bEnable = bEnable;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                SET_TYPE_C_D0_CONFIG_DETECT_FALG();
            }
            else
            {
                CLR_TYPE_C_D0_CONFIG_DETECT_FALG();
            }

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                SET_TYPE_C_D1_CONFIG_DETECT_FALG();
            }
            else
            {
                CLR_TYPE_C_D1_CONFIG_DETECT_FALG();
            }

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                SET_TYPE_C_D2_CONFIG_DETECT_FALG();
            }
            else
            {
                CLR_TYPE_C_D2_CONFIG_DETECT_FALG();
            }

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            if(bEnable == _ENABLE)
            {
                SET_TYPE_C_D6_CONFIG_DETECT_FALG();
            }
            else
            {
                CLR_TYPE_C_D6_CONFIG_DETECT_FALG();
            }

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : 5400 Get Config Detect Flag
// Input Value  : ucInputPort --> Input Port
//                bEnable     --> Enable/Disable
// Output Value : Operation result (_ENABLE/_DISABLE)
//--------------------------------------------------
bit UserCommonPortControllerGetCfgDetectFlag(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_TYPE_C_D0_CONFIG_DETECT_FALG();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_TYPE_C_D1_CONFIG_DETECT_FALG();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_TYPE_C_D2_CONFIG_DETECT_FALG();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_TYPE_C_D6_CONFIG_DETECT_FALG();

            break;
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : 5400 Set Alt Mode Flag
// Input Value  : ucInputPort --> Input Port
//                bFalg       --> _TRUE/_FALSE
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetAltModeFlag(BYTE ucInputPort, bit bFlag)
{
    bFlag = bFlag;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            if(bFlag == _TRUE)
            {
                SET_TYPE_C_D0_ALT_MODE_FALG();
            }
            else
            {
                CLR_TYPE_C_D0_ALT_MODE_FALG();
            }

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(bFlag == _TRUE)
            {
                SET_TYPE_C_D1_ALT_MODE_FALG();
            }
            else
            {
                CLR_TYPE_C_D1_ALT_MODE_FALG();
            }

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            if(bFlag == _TRUE)
            {
                SET_TYPE_C_D2_ALT_MODE_FALG();
            }
            else
            {
                CLR_TYPE_C_D2_ALT_MODE_FALG();
            }

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            if(bFlag == _TRUE)
            {
                SET_TYPE_C_D6_ALT_MODE_FALG();
            }
            else
            {
                CLR_TYPE_C_D6_ALT_MODE_FALG();
            }

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : 5400 Set Get Alt Mode Flag
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserCommonPortControllerGetAltModeFlag(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_TYPE_C_D0_ALT_MODE_FALG();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_TYPE_C_D1_ALT_MODE_FALG();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_TYPE_C_D2_ALT_MODE_FALG();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_TYPE_C_D6_ALT_MODE_FALG();
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : 5400 Set Config Power Deliver Ready Flag
// Input Value  : ucInputPort --> Input Port
//                bEnable     --> Enable/Disable
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
void UserCommonPortControllerSetPdReadyFlag(BYTE ucInputPort, bit bFlag)
{
    bFlag = bFlag;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            if(bFlag == _ENABLE)
            {
                SET_TYPE_C_D0_PD_READY_FALG();
            }
            else
            {
                CLR_TYPE_C_D0_PD_READY_FALG();
            }

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            if(bFlag == _ENABLE)
            {
                SET_TYPE_C_D1_PD_READY_FALG();
            }
            else
            {
                CLR_TYPE_C_D1_PD_READY_FALG();
            }

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            if(bFlag == _ENABLE)
            {
                SET_TYPE_C_D2_PD_READY_FALG();
            }
            else
            {
                CLR_TYPE_C_D2_PD_READY_FALG();
            }

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            if(bFlag == _ENABLE)
            {
                SET_TYPE_C_D6_PD_READY_FALG();
            }
            else
            {
                CLR_TYPE_C_D6_PD_READY_FALG();
            }

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : 5400 Get Config Power Deliver Ready Flag
// Input Value  : ucInputPort --> Input Port
// Output Value : Return PD Ready Status
//--------------------------------------------------
bit UserCommonPortControllerGetPdReadyFlag(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_TYPE_C_D0_PD_READY_FALG();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_TYPE_C_D1_PD_READY_FALG();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_TYPE_C_D2_PD_READY_FALG();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_TYPE_C_D6_PD_READY_FALG();
#endif

        default:
            break;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : 5400 Set Config Pin Assignment Type
// Input Value  : ucInputPort       --> Input Port
//                ucPinAssignment   --> Pin Assignment
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetPinAssignmentType(BYTE ucInputPort, BYTE ucPinAssignment)
{
    ucPinAssignment = ucPinAssignment;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            SET_TYPE_C_D0_PIN_ASSIGNMENT_TYPE(ucPinAssignment);

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            SET_TYPE_C_D1_PIN_ASSIGNMENT_TYPE(ucPinAssignment);

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            SET_TYPE_C_D2_PIN_ASSIGNMENT_TYPE(ucPinAssignment);

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            SET_TYPE_C_D6_PIN_ASSIGNMENT_TYPE(ucPinAssignment);

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : 5400 Get Config Pin Assignment
// Input Value  : ucInputPort       --> Input Port
//                ucPinAssignment   --> Pin Assignment
// Output Value : Pin Assignment
//--------------------------------------------------
BYTE UserCommonPortControllerGetPinAssignmentType(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_TYPE_C_D0_PIN_ASSIGNMENT_TYPE();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_TYPE_C_D1_PIN_ASSIGNMENT_TYPE();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_TYPE_C_D2_PIN_ASSIGNMENT_TYPE();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        return GET_TYPE_C_D6_PIN_ASSIGNMENT_TYPE();
#endif

        default:
            break;
    }

    return 0;
}

//--------------------------------------------------
// Description  : Check Config Condition Flag
// Input Value  : ucInputPort --> Inputput
// Output Value : Record Flag (_TRUE / _FALSE)
//--------------------------------------------------
bit UserCommonPortControllerCheckReConfigFlag(BYTE ucInputPort)
{
    if(UserCommonPortControllerGetInputCableStatus(ucInputPort) == _FALSE)
    {
        return _FALSE;
    }

#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
    if(UserCommonPortControllerGetAltModeFlag(ucInputPort) == _TRUE)
    {
        return _TRUE;
    }
#else
    if(UserCommonPortControllerGetPdReadyFlag(ucInputPort) == _TRUE)
    {
        return _TRUE;
    }
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : Check Config Reconnect Condition
// Input Value  : ucInputPort --> Inputput
// Output Value : Condition Flag (_TRUE / _FALSE)
//--------------------------------------------------
bit UserCommonPortControllerCheckReconnect(BYTE ucInputPort)
{
#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
    // Set Dp Reconnect
    if((UserInterfaceTypeCGetOsdLaneSelMode(ucInputPort) != _DP_LANE_AUTO_MODE) ||
       (UserCommonPortControllerGetSwitchToAutoModeFlg(ucInputPort) == _TRUE))
    {
        return _TRUE;
    }
#endif

#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB)
    ucInputPort = ucInputPort;

    return _TRUE;
#endif

    return _FALSE;
}

//--------------------------------------------------
// Description  : Do Some thing after Reconnect
// Input Value  : ucInputPort --> Inputput
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerDoAfterReconnect(BYTE ucInputPort)
{
#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
    // Clear Firt Switch to Type-C Auto Mode
    if(UserCommonPortControllerGetSwitchToAutoModeFlg(ucInputPort) == _TRUE)
    {
        UserCommonPortControllerSetSwitchToAutoModeFlg(ucInputPort, _FALSE);
    }
#endif
#endif

#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL < _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_USBHUB)
    ucInputPort = ucInputPort;

#endif
#endif
}

#if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)
#if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)
//--------------------------------------------------
// Description  : Read 5400 Type-C Configration Status
// Input Value  : ucInputPort --> Inputput
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerGetPCCfgVdoSelf(BYTE ucInputPort)
{
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, tSMBusWrCmdReadDPCfgVdoSelf[0].ucCommandCode, 1, tSMBusWrCmdReadDPCfgVdoSelf[0].ucDataLength + 1, ((BYTE *)&tSMBusWrCmdReadDPCfgVdoSelf[0].ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Read Back Device Reply Data
    if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRdCmdReadDPCfgVdo[0].ucCommandCode, 1, tSMBusRdCmdReadDPCfgVdo[0].ucDataLength, &(g_unSMBusRdDataPool.stRdDPlanesCfg.ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Fill in Original Subcommand Code for g_unSMBusRdDataPool structure
    g_unSMBusRdDataPool.stRdDPlanesCfg.ucCommandCode = tSMBusRdCmdReadDPCfgVdo[0].ucCommandCode;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Get Dp capability VDO
// Input Value  : ucInputPort  --> Input Port
//                ucDfpUfpFlag --> Dfp or Ufp Config Status
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerGetCapVdoSrc(BYTE ucInputPort, BYTE ucDfpUfpFlag)
{
    StructSMBusWRReadDPLanes stGetCapVdoPar;
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    if(ucDfpUfpFlag == _TYPE_C_DFP_U)
    {
        memcpy(&stGetCapVdoPar, &tSMBusWrCmdReadDpCapVdoPartner[0], tSMBusWrCmdReadDpCapVdoPartner[0].ucDataLength + 2);
    }
    else
    {
        memcpy(&stGetCapVdoPar, &tSMBusWrCmdReadDPCfgVdoPartner[0], tSMBusWrCmdReadDPCfgVdoPartner[0].ucDataLength + 2);
    }

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, stGetCapVdoPar.ucCommandCode, 1, stGetCapVdoPar.ucDataLength + 1, &stGetCapVdoPar.ucDataLength, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    if(ucDfpUfpFlag == _TYPE_C_DFP_U)
    {
        // Read Back Device Reply Data Of VDO Partner Cap
        if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRdCmdDPCapVdo[0].ucCommandCode, 1, tSMBusRdCmdDPCapVdo[0].ucDataLength, &(g_unSMBusRdDataPool.stRdDpCap.ucDataLength), ucInputPort) == _FAIL)
        {
            return _FAIL;
        }
    }
    else
    {
        // Read Back Device Reply Data Of VDO Partner Config
        if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRdCmdReadDPCfgVdo[0].ucCommandCode, 1, tSMBusRdCmdReadDPCfgVdo[0].ucDataLength, &(g_unSMBusRdDataPool.stRdDPlanesCfg.ucDataLength), ucInputPort) == _FAIL)
        {
            return _FAIL;
        }
    }

    if(ucDfpUfpFlag == _TYPE_C_DFP_U)
    {
        DebugMessageSystem("DFP_U VDO Partner Cap", g_unSMBusRdDataPool.stRdDpCap.ucDPCfgPinConfig);

        // Fill in Original Subcommand Code for g_unSMBusRdDataPool structure
        g_unSMBusRdDataPool.stRdDpCap.ucCommandCode = tSMBusRdCmdDPCapVdo[0].ucCommandCode;
    }
    else
    {
        DebugMessageSystem("UFP_U VDO Partner Cfg", g_unSMBusRdDataPool.stRdDPlanesCfg.ucDPCfgPinConfig);

        // Fill in Original Subcommand Code for g_unSMBusRdDataPool structure
        g_unSMBusRdDataPool.stRdDPlanesCfg.ucCommandCode = tSMBusRdCmdReadDPCfgVdo[0].ucCommandCode;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Pin assignment mapping
// Input Value  : ucInputPort     --> Input Port
//                ucPinAssignType --> Pin Assignment Type
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerPinMappingSetting(BYTE ucInputPort, BYTE ucPinAssignType)
{
    switch(ucInputPort)
    {
#if((_D0_DP_TYPE_C_SUPPORT == _ON) || (_D6_DP_TYPE_C_SUPPORT == _ON))
        case _D0_INPUT_PORT:
        case _D6_INPUT_PORT:
            ScalerDpRx0SetDpLaneMapping(ucPinAssignType);
            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            ScalerDpRx1SetDpLaneMapping(ucPinAssignType);
            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Saving Lane Config
// Input Value  : ucInputPort        --> Input Port
//                ucLastDPLaneCount  --> Last DP Lanes
//                ucNewPinAssignment --> New DP Lanes
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSaveLaneCfg(BYTE ucInputPort, BYTE ucLastDPLaneCount, BYTE ucNewPinAssignment)
{
    BYTE ucNewDPLaneCount = 0;

    if((ucNewPinAssignment == _TYPE_C_PIN_ASSIGNMENT_C) || (ucNewPinAssignment == _TYPE_C_PIN_ASSIGNMENT_E)) // || (ucNewPinAssignment == _TYPE_C_PIN_ASSIGNMENT_CD))
    {
        ucNewDPLaneCount = 4;
    }
    else
    {
        ucNewDPLaneCount = 2;
    }

    if(ucNewDPLaneCount == ucLastDPLaneCount) // Check Dp lane count is change by auto mode
    {
        return;
    }

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            UserCommonNVRamSetSystemData(_DP_D0_LANES, ucNewDPLaneCount);
            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            UserCommonNVRamSetSystemData(_DP_D1_LANES, ucNewDPLaneCount);
            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            UserCommonNVRamSetSystemData(_DP_D2_LANES, ucNewDPLaneCount);
            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            UserCommonNVRamSetSystemData(_DP_D6_LANES, ucNewDPLaneCount);
            break;
#endif
        default:
            break;
    }

    UserCommonEepromSaveSystemData();

    // Set Lane Count Change par
    ScalerDpLaneCountSwitch(ucInputPort, UserCommonNVRamGetSystemData(ucInputPort));
}

//--------------------------------------------------
// Description  : Get Switched To Auto Mode
// Input Value  : ucInputPort --> Input Port
// Output Value : Osd Menu Switch to Auto Mode
//--------------------------------------------------
bit UserCommonPortControllerGetSwitchToAutoModeFlg(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_TYPE_C_D0_SWITCH_AUTOMODE_FALG();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_TYPE_C_D1_SWITCH_AUTOMODE_FALG();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_TYPE_C_D2_SWITCH_AUTOMODE_FALG();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_TYPE_C_D6_SWITCH_AUTOMODE_FALG();
#endif

        default:
            break;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Set Switched To Auto Mode
// Input Value  : ucInputPort --> Input Port
//                bFlg        --> _TRUE / _FALSE
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetSwitchToAutoModeFlg(BYTE ucInputPort, bit bFlg)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:

            if(bFlg == _TRUE)
            {
                SysDpTypeCSetD0LaneCount(0);
            }
            SET_TYPE_C_D0_SWITCH_AUTOMODE_FALG(bFlg);

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:

            if(bFlg == _TRUE)
            {
                SysDpTypeCSetD1LaneCount(0);
            }
            SET_TYPE_C_D1_SWITCH_AUTOMODE_FALG(bFlg);

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:

            if(bFlg == _TRUE)
            {
                SysDpTypeCSetD2LaneCount(0);
            }
            SET_TYPE_C_D2_SWITCH_AUTOMODE_FALG(bFlg);

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:

            if(bFlg == _TRUE)
            {
                SysDpTypeCSetD6LaneCount(0);
            }
            SET_TYPE_C_D6_SWITCH_AUTOMODE_FALG(bFlg);

            break;
#endif

        default:
            break;
    }
}
#endif // End of #if(_TYPE_C_PINCFG_AUTO_MODE == _TYPE_C_PINCFG_AUTO_MODE_FACING_SOURCE)

//--------------------------------------------------
// Description  : Get 5400 DFP_U Config Status
// Input Value  : None
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerGetStatus(BYTE ucInputPort)
{
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, tSMBusWrGetStatus[0].ucCommandCode, 1, tSMBusWrGetStatus[0].ucDataLength + 1, ((BYTE *)&tSMBusWrGetStatus[0].ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Read Back Device Reply Data
    if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRDGetStatus[0].ucCommandCode, 1, tSMBusRDGetStatus[0].ucDataLength, &(g_unSMBusRdDataPool.stRdGetStatus.ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Fill in Original Subcommand Code for g_unSMBusRdDataPool structure
    g_unSMBusRdDataPool.stRdGetICStatus.ucCommandCode = tSMBusRDGetStatus[0].ucCommandCode;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Pin assignment mapping
// Input Value  : ucCfgInfo --> Port Controller Config Mode
// Output Value : None
//--------------------------------------------------
BYTE UserCommonPortControllerCheckDfpUfpMode(BYTE ucCfgInfo)
{
    if(((ucCfgInfo & (_BIT2 | _BIT1 | _BIT0)) == _BIT2) || ((ucCfgInfo & (_BIT2 | _BIT1 | _BIT0)) == _BIT1))
    {
        return _TYPE_C_DFP_U;
    }
    else
    {
        return _TYPE_C_UFP_U;
    }
}

//--------------------------------------------------
// Description  : 5400 Set Config Mode
// Input Value  : ucInputPort --> Input Port
//                ucCfgMode   --> Config Mode
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetCfgMode(BYTE ucInputPort, BYTE ucCfgMode)
{
    ucCfgMode = ucCfgMode;

    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            SET_TYPE_C_D0_CONFIG_MODE(ucCfgMode);

            break;
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            SET_TYPE_C_D1_CONFIG_MODE(ucCfgMode);

            break;
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            SET_TYPE_C_D2_CONFIG_MODE(ucCfgMode);

            break;
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            SET_TYPE_C_D6_CONFIG_MODE(ucCfgMode);

            break;
#endif

        default:
            break;
    }
}

//--------------------------------------------------
// Description  : 5400 Set Config Mode
// Input Value  : ucInputPort --> Input Port
// Output Value : Config Mode
//--------------------------------------------------
BYTE UserCommonPortControllerGetCfgMode(BYTE ucInputPort)
{
    switch(ucInputPort)
    {
#if(_D0_DP_TYPE_C_SUPPORT == _ON)
        case _D0_INPUT_PORT:
            return GET_TYPE_C_D0_CONFIG_MODE();
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
        case _D1_INPUT_PORT:
            return GET_TYPE_C_D1_CONFIG_MODE();
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
        case _D2_INPUT_PORT:
            return GET_TYPE_C_D2_CONFIG_MODE();
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
        case _D6_INPUT_PORT:
            return GET_TYPE_C_D6_CONFIG_MODE();
#endif

        default:
            break;
    }

    return _TYPE_C_UFP_U;
}
#endif // End of #if(_TYPE_C_RTS5400_SERIES_SPEC_VER_SEL >= _RTS5400_SERIES_FW_SPEC_VERSION_V0D7)

#if(_TYPE_C_RTS5400_SERIES_PDO_INFO_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Read 5400 PDO Status
// Input Value  : None
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerGetPDOStatus(BYTE ucInputPort)
{
    BYTE ucSlaveAddr = UserCommonPortControllerGetPCAddr(ucInputPort);

    // Execute Write Command
    if(UserCommonTypecCommunicationWrite(ucSlaveAddr, tSMBusWrCmdGetPDOPartnerStatus[0].ucCommandCode, 1, tSMBusWrCmdGetPDOPartnerStatus[0].ucDataLength + 1, ((BYTE *)&tSMBusWrCmdGetPDOPartnerStatus[0].ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Polling Write Command Operation Status
    if(UserCommonTypecCommunicationPollingPDReady(ucSlaveAddr, 100, ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Read Back Device Reply Data
    if(UserCommonTypecCommunicationRead(ucSlaveAddr, tSMBusRdCmdGetPDOPartnerStatus[0].ucCommandCode, 1, tSMBusRdCmdGetPDOPartnerStatus[0].ucDataLength, &(g_unSMBusRdDataPool.stRdGetPDOStatus.ucDataLength), ucInputPort) == _FAIL)
    {
        return _FAIL;
    }

    // Fill in Original Subcommand Code for g_unSMBusRdDataPool structure
    g_unSMBusRdDataPool.stRdGetPDOStatus.ucCommandCode = tSMBusRdCmdGetPDOPartnerStatus[0].ucCommandCode;

    return _TRUE;
}
#endif

#if(_D0_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D0 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserCommonPortControllerGetD0PortPower(void)
{
    return UserInterfaceTypeCGetD0PortControllerPower();
}
#endif

#if(_D1_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D1 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserCommonPortControllerGetD1PortPower(void)
{
    return UserInterfaceTypeCGetD1PortControllerPower();
}
#endif

#if(_D2_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D2 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserCommonPortControllerGetD2PortPower(void)
{
    return UserInterfaceTypeCGetD2PortControllerPower();
}
#endif

#if(_D6_DP_TYPE_C_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get D6 Port Controller Power Status
// Input Value  : None
// Output Value : _ON /_OFF
//--------------------------------------------------
bit UserCommonPortControllerGetD6PortPower(void)
{
    return UserInterfaceTypeCGetD6PortControllerPower();
}
#endif

#endif // End of #if(_PORT_CONTROLLER_RTS5400_SERIES_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)
