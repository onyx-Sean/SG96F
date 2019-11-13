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
// ID Code      : UserCommonPortControllerUser.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_PORTCONTROLLERUSER__

#include "UserCommonInclude.h"

#if(_DP_TYPE_C_SUPPORT == _ON)
#if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)

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
bit UserCommonPortControllerCheckPCEnterAltMode(BYTE ucInputPort);
bit UserCommonPortControllerConfigDetect(BYTE ucInputPort);
bit UserCommonPortControllerConfig(BYTE ucInputPort);
void UserCommonPortControllerSetCfgDetectFlag(BYTE ucInputPort, bit bEnable);
void UserCommonPortControllerSetAltModeFlag(BYTE ucInputPort, bit bFlag);
bit UserCommonPortControllerGetAltModeFlag(BYTE ucInputPort);

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
// Description  : Check Port Controller Enter Alt Mode
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
        return _FALSE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Auto Detect Config Result
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerConfigDetect(BYTE ucInputPort)
{
    ucInputPort= ucInputPort;

    return _TRUE;
}

//--------------------------------------------------
// Description  : Port Controller Config
// Input Value  : ucInputPort --> Input Port
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
bit UserCommonPortControllerConfig(BYTE ucInputPort)
{
    return UserInterfaceTypeCPortControllerConfig(ucInputPort);
}

//--------------------------------------------------
// Description  : Set Config Detect Flag
// Input Value  : ucInputPort --> Input Port
//                bEnable     --> Enable/Disable
// Output Value : Operation result (Fail/Success)
//--------------------------------------------------
void UserCommonPortControllerSetCfgDetectFlag(BYTE ucInputPort, bit bEnable)
{
    ucInputPort = ucInputPort;
    bEnable = bEnable;
}

//--------------------------------------------------
// Description  : Set Alt Mode Flag
// Input Value  : ucInputPort --> Input Port
//                bFalg       --> _TRUE/_FALSE
// Output Value : None
//--------------------------------------------------
void UserCommonPortControllerSetAltModeFlag(BYTE ucInputPort, bit bFlag)
{
    ucInputPort = ucInputPort;
    bFlag = bFlag;
}

//--------------------------------------------------
// Description  : Get Alt Mode Flag
// Input Value  : ucInputPort --> Input Port
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit UserCommonPortControllerGetAltModeFlag(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;

    return _FALSE;
}

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
#endif // End of #if(_PORT_CONTROLLER_USERDECITION_SUPPORT == _ON)
#endif // End of #if(_DP_TYPE_C_SUPPORT == _ON)
