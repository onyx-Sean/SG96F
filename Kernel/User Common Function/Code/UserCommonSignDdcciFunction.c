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
// ID Code      : UserCommonSignDdcciFunction.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_SIGN_DDCCI_FUNCTION__

#include "UserCommonInclude.h"

#if(_CODE_DIGITAL_SIGNATURE_SUPPORT != _SIGNATURE_TYPE_OFF)
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
void UserCommonSignDdcciHandler(void);
BYTE UserCommonSignDdcciCalCheckSum(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Digital Signature DDCCI CMD Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonSignDdcciHandler(void)
{
    BYTE ucLength = 0;
    BYTE ucIndex = 0;

    if(GET_RUN_DDCCI_COMMAND() == _SUCCESS)
    {
        if(g_pucDdcciRxBuf[_DDCCI_SIGN_SUB_ADDR] != _DDCCI_SIGN_TEST_SUB_ADDR)
        {
            return;
        }

        if(g_pucDdcciRxBuf[_DDCCI_SIGN_CMD_TYPE] != _DDCCI_SIGN_TEST_CMD_TYPE)
        {
            return;
        }

        g_pucDdcciTxBuf[_DDCCI_SIGN_SUB_ADDR] = _DDCCI_DEST_ADDRESS;
        g_pucDdcciTxBuf[_DDCCI_SIGN_CMD_TYPE] = _DDCCI_SIGN_TEST_CMD_TYPE;

        switch(g_pucDdcciRxBuf[_DDCCI_SIGN_OPCODE])
        {
            case _DDCCI_OPCODE_SIGN_HANDSHAKE_CHECK_REQ:
                ucLength = 0x03;
                g_pucDdcciTxBuf[_DDCCI_SIGN_LENGTH] = ucLength;
                g_pucDdcciTxBuf[_DDCCI_SIGN_OPCODE] = _DDCCI_OPCODE_SIGN_HANDSHAKE_CHECK_REPLY;
                g_pucDdcciTxBuf[_DDCCI_SIGN_DATAOUT] = _DDCCI_SIGN_HANDSHAKE_CHECK_PASS;
                g_pucDdcciTxBuf[_DDCCI_SIGN_DATAOUT + 1] = UserCommonSignDdcciCalCheckSum();
                break;

            case _DDCCI_OPCODE_SIGN_HANDSHAKE_ENABLE_ISP_REQ:
                ucLength = 0x03;
                ucIndex = _DDCCI_SIGN_OPCODE;
                if((g_pucDdcciRxBuf[ucIndex + 3] == 'R') && (g_pucDdcciRxBuf[ucIndex + 6] == 'E') &&
                   (g_pucDdcciRxBuf[ucIndex + 9] == 'A') && (g_pucDdcciRxBuf[ucIndex + 12] == 'L') &&
                   (g_pucDdcciRxBuf[ucIndex + 15] == 'T') && (g_pucDdcciRxBuf[ucIndex + 18] == 'E') &&
                   (g_pucDdcciRxBuf[ucIndex + 21] == 'C') && (g_pucDdcciRxBuf[ucIndex + 24] == 'H'))
                {
                    g_pucDdcciTxBuf[_DDCCI_SIGN_LENGTH] = ucLength;
                    g_pucDdcciTxBuf[_DDCCI_SIGN_OPCODE] = _DDCCI_OPCODE_SIGN_HANDSHAKE_ENABLE_ISP_REPLY;
                    g_pucDdcciTxBuf[_DDCCI_SIGN_DATAOUT] = _DDCCI_SIGN_HANDSHAKE_ENABLE_ISP_PASS;
                    g_pucDdcciTxBuf[_DDCCI_SIGN_DATAOUT + 1] = UserCommonSignDdcciCalCheckSum();

                    // Enable VGA_DDC & VGA_DDC2(VGA Port) & DDC0(HDMI Port)
                    // Set Right ISP Slave Address
                    ScalerMcuSetISPChannel(_CODE_DIGITAL_SIGNATURE_ISP_SEL_EN);
                    ScalerMcuSetISPSlaveAddr(_ENABLE);
                }
                break;

            case _DDCCI_OPCODE_SIGN_CHANGE_TO_DEBUG_MODE:
                // Return DDCCI to Normal Judge Mode
                ScalerDebugClrDdcciSwitchState();
                // Switch DDCCI to Debug Mode, No Matter Which Port as Auto-Switch
                ScalerMcuDdcciSwitchPort(_DEBUG_MODE, _A0_INPUT_PORT);
                break;

            default:

                return;
        }

        ScalerMcuDdcciSendData(g_pucDdcciTxBuf);

        UserCommonDdcciInitRx();

        SET_RUN_DDCCI_COMMAND(_FAIL);
    }
}

//--------------------------------------------------
// Description  : Caculate checksum
// Input Value  : None
// Output Value : ucSum --> Checksum value
//--------------------------------------------------
BYTE UserCommonSignDdcciCalCheckSum(void)
{
    BYTE ucCount = 0;
    BYTE ucCheckLen = 0;
    BYTE ucSum = _DDCCI_SIGN_VIRTUAL_HOST_ADDRESS;

    ucCheckLen = (g_pucDdcciTxBuf[_DDCCI_SIGN_LENGTH] & 0x7F) + 2;

    for(ucCount = 0; ucCount < ucCheckLen; ucCount++)
    {
        ucSum = ucSum ^ g_pucDdcciTxBuf[ucCount];
    }

    return ucSum;
}
#endif //#if(_CODE_DIGITAL_SIGNATURE_SUPPORT != _SIGNATURE_TYPE_OFF)
