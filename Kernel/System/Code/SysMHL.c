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
// ID Code      : SysMHL.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SYSTEM_MHL__

#include "SysInclude.h"

#if(_MHL_SUPPORT == _ON)

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
void SysMHLMscHandler(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : MHL Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void SysMHLMscHandler(void)
{
    BYTE ucKeyCode = 0;

    if(GET_MODE_STATE() == _MODE_STATUS_INITIAL)
    {
        CLR_MODE_STATE_CHANGE_MHL();
        return;
    }

#if(_URGENT_EVENT_CHECK_MODE == _ON)
    if(ScalerSyncCheckUrgentEvent() == _TRUE)
    {
        return;
    }
#endif

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

    if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D0_INPUT_PORT, _ON);

        if(ScalerMHLMscHandler(_D0_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D0_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D0_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                if(UserInterfaceAdjustMHLMscRCPProc(ucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCPE_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_RCPK, ucKeyCode);
            }

            ///////////////
            //UCP Handler//
            ///////////////
#if(_MHL_UCP_SUPPORT == _ON)
            if(ScalerMHLMscUCPGetCommand(_D0_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                ScalerMHLMscSendCommand(_D0_INPUT_PORT, _MSC_MSG, _MSC_UCPK, ucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#if(_D0_MHL_VERSION >= _MHL_VERSION_3_0)

            /////////////////
            // HID Handler //
            /////////////////
#if(_MHL3_ECBUS_HID_SUPPORT == _ON)
            ScalerMHLMscRHIDHandler(_D0_INPUT_PORT);
#endif
            ////////////////
            // ECBUS EMSC //
            ////////////////
            if(ScalerMHL3ECBUSHandler(_D0_INPUT_PORT) == _TRUE)
            {
                ScalerMHL3ECBUSEMSCRxHandler(_D0_INPUT_PORT);

                ScalerMHL3ECBUSEMSCTxHandler(_D0_INPUT_PORT);
            }

#endif // End of #if(_D0_MHL_VERSION >= _MHL_VERSION_3_0)

        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D0_INPUT_PORT);

#if(_D0_MHL_VERSION >= _MHL_VERSION_3_0)

        ///////////////////////////////
        // Check WRITE_BURST Process //
        ///////////////////////////////
        ScalerMHLCheckWriteBurst(_D0_INPUT_PORT);

        /////////////////////////////
        // Check eMSC BIST Process //
        /////////////////////////////
        ScalerMHL3BISTHandler(_D0_INPUT_PORT);

#endif // End of #if(_D0_MHL_VERSION >= _MHL_VERSION_3_0)

    }
#endif  // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

    if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D1_INPUT_PORT, _ON);

        if(ScalerMHLMscHandler(_D1_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D1_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D1_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                if(UserInterfaceAdjustMHLMscRCPProc(ucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCPE_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_RCPK, ucKeyCode);
            }

#if(_MHL_UCP_SUPPORT == _ON)
            ///////////////
            //UCP Handler//
            ///////////////
            if(ScalerMHLMscUCPGetCommand(_D1_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                ScalerMHLMscSendCommand(_D1_INPUT_PORT, _MSC_MSG, _MSC_UCPK, ucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#if(_D1_MHL_VERSION >= _MHL_VERSION_3_0)

            /////////////////
            // HID Handler //
            /////////////////
#if(_MHL3_ECBUS_HID_SUPPORT == _ON)
            ScalerMHLMscRHIDHandler(_D1_INPUT_PORT);
#endif
            ////////////////
            // ECBUS EMSC //
            ////////////////
            if(ScalerMHL3ECBUSHandler(_D1_INPUT_PORT) == _TRUE)
            {
                ScalerMHL3ECBUSEMSCRxHandler(_D1_INPUT_PORT);

                ScalerMHL3ECBUSEMSCTxHandler(_D1_INPUT_PORT);
            }

#endif // End of #if(_D1_MHL_VERSION >= _MHL_VERSION_3_0)

        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D1_INPUT_PORT);

#if(_D1_MHL_VERSION >= _MHL_VERSION_3_0)

        ///////////////////////////////
        // Check WRITE_BURST Process //
        ///////////////////////////////
        ScalerMHLCheckWriteBurst(_D1_INPUT_PORT);

        /////////////////////////////
        // Check eMSC BIST Process //
        /////////////////////////////
        ScalerMHL3BISTHandler(_D1_INPUT_PORT);

#endif // End of #if(_D1_MHL_VERSION >= _MHL_VERSION_3_0)

    }
#endif  // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)

    if(GET_D2_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D2_INPUT_PORT, _ON);

        if(ScalerMHLMscHandler(_D2_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D2_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D2_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                if(UserInterfaceAdjustMHLMscRCPProc(ucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D2_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCPE_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D2_INPUT_PORT, _MSC_MSG, _MSC_RCPK, ucKeyCode);
            }

            ///////////////
            //UCP Handler//
            ///////////////
#if(_MHL_UCP_SUPPORT == _ON)
            if(ScalerMHLMscUCPGetCommand(_D2_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                ScalerMHLMscSendCommand(_D2_INPUT_PORT, _MSC_MSG, _MSC_UCPK, ucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

            /////////////////
            // HID Handler //
            /////////////////
#if(_MHL3_ECBUS_HID_SUPPORT == _ON)
            ScalerMHLMscRHIDHandler(_D2_INPUT_PORT);
#endif
            ////////////////
            // ECBUS EMSC //
            ////////////////
            if(ScalerMHL3ECBUSHandler(_D2_INPUT_PORT) == _TRUE)
            {
                ScalerMHL3ECBUSEMSCRxHandler(_D2_INPUT_PORT);

                ScalerMHL3ECBUSEMSCTxHandler(_D2_INPUT_PORT);
            }

#endif // End of #if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D2_INPUT_PORT);

#if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

        ///////////////////////////////
        // Check WRITE_BURST Process //
        ///////////////////////////////
        ScalerMHLCheckWriteBurst(_D2_INPUT_PORT);

        /////////////////////////////
        // Check eMSC BIST Process //
        /////////////////////////////
        ScalerMHL3BISTHandler(_D2_INPUT_PORT);

#endif // End of #if(_D2_MHL_VERSION >= _MHL_VERSION_3_0)

    }
#endif  // End of #if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)

    if(GET_D3_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D3_INPUT_PORT, _ON);

        if(ScalerMHLMscHandler(_D3_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D3_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D3_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                if(UserInterfaceAdjustMHLMscRCPProc(ucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D3_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCPE_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D3_INPUT_PORT, _MSC_MSG, _MSC_RCPK, ucKeyCode);
            }

#if(_MHL_UCP_SUPPORT == _ON)
            ///////////////
            //UCP Handler//
            ///////////////
            if(ScalerMHLMscUCPGetCommand(_D3_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                ScalerMHLMscSendCommand(_D3_INPUT_PORT, _MSC_MSG, _MSC_UCPK, ucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#if(_D3_MHL_VERSION >= _MHL_VERSION_3_0)

            /////////////////
            // HID Handler //
            /////////////////
#if(_MHL3_ECBUS_HID_SUPPORT == _ON)
            ScalerMHLMscRHIDHandler(_D3_INPUT_PORT);
#endif
            ////////////////
            // ECBUS EMSC //
            ////////////////
            if(ScalerMHL3ECBUSHandler(_D3_INPUT_PORT) == _TRUE)
            {
                ScalerMHL3ECBUSEMSCRxHandler(_D3_INPUT_PORT);

                ScalerMHL3ECBUSEMSCTxHandler(_D3_INPUT_PORT);
            }

#endif // End of #if(_D3_MHL_VERSION >= _MHL_VERSION_3_0)

        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D3_INPUT_PORT);

#if(_D3_MHL_VERSION >= _MHL_VERSION_3_0)

        ///////////////////////////////
        // Check WRITE_BURST Process //
        ///////////////////////////////
        ScalerMHLCheckWriteBurst(_D3_INPUT_PORT);

        /////////////////////////////
        // Check eMSC BIST Process //
        /////////////////////////////
        ScalerMHL3BISTHandler(_D3_INPUT_PORT);

#endif // End of #if(_D3_MHL_VERSION >= _MHL_VERSION_3_0)

    }

#endif  // End of #if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)

    if(GET_D4_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D4_INPUT_PORT, _ON);

        if(ScalerMHLMscHandler(_D4_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D4_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D4_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                if(UserInterfaceAdjustMHLMscRCPProc(ucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D4_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCPE_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D4_INPUT_PORT, _MSC_MSG, _MSC_RCPK, ucKeyCode);
            }

            ///////////////
            //UCP Handler//
            ///////////////
#if(_MHL_UCP_SUPPORT == _ON)
            if(ScalerMHLMscUCPGetCommand(_D4_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                ScalerMHLMscSendCommand(_D4_INPUT_PORT, _MSC_MSG, _MSC_UCPK, ucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#if(_D4_MHL_VERSION >= _MHL_VERSION_3_0)

            /////////////////
            // HID Handler //
            /////////////////
#if(_MHL3_ECBUS_HID_SUPPORT == _ON)
            ScalerMHLMscRHIDHandler(_D4_INPUT_PORT);
#endif
            ////////////////
            // ECBUS EMSC //
            ////////////////
            if(ScalerMHL3ECBUSHandler(_D4_INPUT_PORT) == _TRUE)
            {
                ScalerMHL3ECBUSEMSCRxHandler(_D4_INPUT_PORT);

                ScalerMHL3ECBUSEMSCTxHandler(_D4_INPUT_PORT);
            }

#endif // End of #if(_D4_MHL_VERSION >= _MHL_VERSION_3_0)

        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D4_INPUT_PORT);

#if(_D4_MHL_VERSION >= _MHL_VERSION_3_0)

        ///////////////////////////////
        // Check WRITE_BURST Process //
        ///////////////////////////////
        ScalerMHLCheckWriteBurst(_D4_INPUT_PORT);

        /////////////////////////////
        // Check eMSC BIST Process //
        /////////////////////////////
        ScalerMHL3BISTHandler(_D4_INPUT_PORT);

#endif // End of #if(_D4_MHL_VERSION >= _MHL_VERSION_3_0)

    }
#endif  // End of #if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)

    if(GET_D5_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        ScalerMHLCBUSPhySwitch(_D5_INPUT_PORT, _ON);

        if(ScalerMHLMscHandler(_D5_INPUT_PORT, SysSourceGetInputPort(), GET_MODE_STATE()) == _TRUE)
        {
            ///////////////
            //RAP Handler//
            ///////////////
            if(ScalerMHLMscRAPHandler(_D5_INPUT_PORT) == _FALSE)
            {
                if(SysSourceGetSourceType() != _SOURCE_NONE)
                {
                    SET_MODE_RESET_TARGET(_MODE_ACTION_RESET_TO_SEARCH);
                }
            }

            ///////////////
            //RCP Handler//
            ///////////////
            if(ScalerMHLMscRCPGetCommand(_D5_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                if(UserInterfaceAdjustMHLMscRCPProc(ucKeyCode) == _FALSE)
                {
                    ScalerMHLMscSendCommand(_D5_INPUT_PORT, _MSC_MSG, _MSC_RCPE, _MSC_RCPE_INEFFECTIVE_CODE);
                }

                ScalerMHLMscSendCommand(_D5_INPUT_PORT, _MSC_MSG, _MSC_RCPK, ucKeyCode);
            }

#if(_MHL_UCP_SUPPORT == _ON)
            ///////////////
            //UCP Handler//
            ///////////////
            if(ScalerMHLMscUCPGetCommand(_D5_INPUT_PORT, &ucKeyCode) == _TRUE)
            {
                ScalerMHLMscSendCommand(_D5_INPUT_PORT, _MSC_MSG, _MSC_UCPK, ucKeyCode);
            }
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

#if(_D5_MHL_VERSION >= _MHL_VERSION_3_0)

            /////////////////
            // HID Handler //
            /////////////////
#if(_MHL3_ECBUS_HID_SUPPORT == _ON)
            ScalerMHLMscRHIDHandler(_D5_INPUT_PORT);
#endif
            ////////////////
            // ECBUS EMSC //
            ////////////////
            if(ScalerMHL3ECBUSHandler(_D5_INPUT_PORT) == _TRUE)
            {
                ScalerMHL3ECBUSEMSCRxHandler(_D5_INPUT_PORT);

                ScalerMHL3ECBUSEMSCTxHandler(_D5_INPUT_PORT);
            }

#endif // End of #if(_D5_MHL_VERSION >= _MHL_VERSION_3_0)

        }

        /////////////////////////
        //Check SET_INT Process//
        /////////////////////////
        ScalerMHLMscCheckDeviceINT(_D5_INPUT_PORT);

#if(_D5_MHL_VERSION >= _MHL_VERSION_3_0)

        ///////////////////////////////
        // Check WRITE_BURST Process //
        ///////////////////////////////
        ScalerMHLCheckWriteBurst(_D5_INPUT_PORT);

        /////////////////////////////
        // Check eMSC BIST Process //
        /////////////////////////////
        ScalerMHL3BISTHandler(_D5_INPUT_PORT);

#endif // End of #if(_D5_MHL_VERSION >= _MHL_VERSION_3_0)

    }
#endif  // End of #if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)

    CLR_MODE_STATE_CHANGE_MHL();
}

#endif // End of #if(_MHL_SUPPORT == _ON)
