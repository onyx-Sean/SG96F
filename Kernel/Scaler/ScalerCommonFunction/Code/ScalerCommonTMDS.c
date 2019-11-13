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
// ID Code      : ScalerCommonTMDS.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_COMMON_TMDS__

#include "ScalerCommonFunctionInclude.h"

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
#if(_HDMI_SUPPORT == _ON)
BYTE ScalerTMDSHdmiGetAVIInfo(BYTE ucInputPort, EnumAviInfoContent enumContent);

#if(_HDMI_2_0_SUPPORT == _ON)
void ScalerTMDSHDMI2HPDRRIRQEnable(BYTE ucInputPort, bit bEnable);
#endif
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_HDMI_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get HDMI AVI Info Contents
// Input Value  : Content of Interest
// Output Value : Content Value
//--------------------------------------------------
BYTE ScalerTMDSHdmiGetAVIInfo(BYTE ucInputPort, EnumAviInfoContent enumContent)
{
    ucInputPort = ucInputPort;

    switch(ucInputPort)
    {
#if(_D0_HDMI_SUPPORT == _ON)
        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D1_HDMI_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx1HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D2_HDMI_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx2HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D3_HDMI_SUPPORT == _ON)
        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx3HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D4_HDMI_SUPPORT == _ON)
        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx4HdmiGetAVIInfo(enumContent);
#endif

#endif

#if(_D5_HDMI_SUPPORT == _ON)
        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            return ScalerTMDSRx0HdmiGetAVIInfo(enumContent);
#else
            return ScalerTMDSRx5HdmiGetAVIInfo(enumContent);
#endif

#endif

        default:
            return _FALSE;
    }
}


#if(_HDMI_2_0_SUPPORT == _ON)
//--------------------------------------------------
// Description  : TMDS HPD IRQ Enable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerTMDSHDMI2HPDRRIRQEnable(BYTE ucInputPort, bit bEnable)
{
    ucInputPort = ucInputPort;

    switch(ucInputPort)
    {
#if(_D0_HDMI_2_0_SUPPORT == _ON)
        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#endif
            break;
#endif

#if(_D1_HDMI_2_0_SUPPORT == _ON)
        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx1HDMI2HPDRRIRQEnable(bEnable);
#endif
            break;
#endif

#if(_D2_HDMI_2_0_SUPPORT == _ON)
        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx2HDMI2HPDRRIRQEnable(bEnable);
#endif

            break;
#endif

#if(_D3_HDMI_2_0_SUPPORT == _ON)
        case _D3_INPUT_PORT:

#if(_D3_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx3HDMI2HPDRRIRQEnable(bEnable);
#endif

            break;
#endif

#if(_D4_HDMI_2_0_SUPPORT == _ON)
        case _D4_INPUT_PORT:

#if(_D4_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx4HDMI2HPDRRIRQEnable(bEnable);
#endif
            break;
#endif

#if(_D5_HDMI_2_0_SUPPORT == _ON)
        case _D5_INPUT_PORT:

#if(_D5_INPUT_PORT_TMDS_MAC_PAGE == _PAGE2)
            ScalerTMDSRx0HDMI2HPDRRIRQEnable(bEnable);
#else
            ScalerTMDSRx5HDMI2HPDRRIRQEnable(bEnable);
#endif

            break;
#endif

        default:
            break;
    }
}
#endif
#endif
