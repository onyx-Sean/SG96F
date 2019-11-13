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
//**********************************************************************************************************

//----------------------------------------------------------------------------------------------------
// ID Code      : NoneFactoryFunction_RL6369.c No.0000
// Update Note  :
//
//----------------------------------------------------------------------------------------------------
#define __FACTORY_FUNCTION__

#include "UserCommonInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _NUMBER_OF_INPUT_PORTS                      7


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

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
void NoneFactoryQCFlow(BYTE ucInputPort);
bit NoneFactoryQCNextPort(BYTE ucInputPort);
#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************

#if(_FACTORY_RTD_QC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Contain Full QC Main Test Flow
// Input Value  : ucInputPort => Current Test Input Port
// Output Value : None
//--------------------------------------------------
void NoneFactoryQCFlow(BYTE ucInputPort)
{
    static bit bTestFinished = 0;
    static BYTE ucA0PortResult = 0;
    static BYTE ucD0PortResult = 0;
    static BYTE ucD1PortResult = 0;
    static BYTE ucD2PortResult = 0;

    if(bTestFinished == _FALSE)
    {
        ScalerGlobalWatchDog(_DISABLE);

        // Disable All Digital Function
        ScalerQCAllDigitalFunctionDisable();

        switch(ucInputPort)
        {

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
            case _A0_INPUT_PORT:

                bLED1 = _LED_ON; // Pass
                bLED2 = _LED_ON; // Fail

                ucA0PortResult = ScalerQCA0PortTest();

                DebugMessageQC("6. A0 Port Test Results", ucA0PortResult);

                break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            case _D0_INPUT_PORT:

                ucD0PortResult = ScalerQCD0PortTest();

                DebugMessageQC("6. D0 Port Test Results", ucD0PortResult);

                break;

#endif


#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            case _D1_INPUT_PORT:

                ucD1PortResult = ScalerQCD1PortTest();
                DebugMessageQC("6. D1 Port Test Results", ucD1PortResult);

                break;

#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
            case _D2_INPUT_PORT:

                ucD2PortResult = ScalerQCD2PortTest();
                DebugMessageQC("6. D2 Port Test Results", ucD2PortResult);

                break;

#endif

            default:
                break;
        }

#if(_QC_TEST_DEBUG == _OFF)
        if(((bit)ucA0PortResult == _TRUE) ||
           ((bit)ucD0PortResult == _TRUE) ||
           ((bit)ucD1PortResult == _TRUE) ||
           ((bit)ucD2PortResult == _TRUE))
        {
            bTestFinished = _TRUE;

            bLED2 = _LED_ON;     // Need to reset RLE0638 TX PG

            DebugMessageQC("7. A0 Port Test Results", ucA0PortResult);
            DebugMessageQC("7. D0 Port Test Results", ucD0PortResult);
            DebugMessageQC("7. D1 Port Test Results", ucD1PortResult);
            DebugMessageQC("7. D2 Port Test Results", ucD2PortResult);
            DebugMessageQC("7. D3 Port Test Results", ucD3PortResult);
            DebugMessageQC("7. D4 Port Test Results", ucD4PortResult);
            DebugMessageQC("7. D5 Port Test Results", ucD5PortResult);

            DebugMessageQC("7. **** QC Test Finsish Fail ****", 0xFF);
            DebugMessageQC("7. MEMORY_TYPE_CONFIG", _MEMORY_TYPE_CONFIG);
            DebugMessageQC("7. MEMORY_SIZE_CONFIG", _MEMORY_SIZE_CONFIG);

            ScalerSetByte(P0_06_TOP_DUMMY1, ucA0PortResult);
            ScalerSetByte(P0_0D_TOP_DUMMY2, ucD0PortResult);
            ScalerSetByte(P0_5E_SYNCPROC_DUMMY0, ucD1PortResult);
            ScalerSetByte(P0_5F_SYNCPROC_DUMMY1, 0xFF);

            while(1)
            {
                bLED2 = ~(bLED2);     // Need to reset RLE0638 TX PG
                ScalerTimerDelayXms(200);
                ScalerDebug();      // QC Test
            }
        }
#endif

        // Finished Show Result
        if(NoneFactoryQCNextPort(ucInputPort) == _FALSE)
        {
            bTestFinished = _TRUE;

            bLED1 = _LED_OFF;
            bLED2 = _LED_OFF;

            ScalerTimerDelayXms(100);

            bLED1 = _LED_ON;  // Pass

            DebugMessageQC("7. A0 Port Test Results", ucA0PortResult);
            DebugMessageQC("7. D0 Port Test Results", ucD0PortResult);
            DebugMessageQC("7. D1 Port Test Results", ucD1PortResult);
            DebugMessageQC("7. D2 Port Test Results", ucD2PortResult);
            DebugMessageQC("7. D3 Port Test Results", ucD3PortResult);
            DebugMessageQC("7. D4 Port Test Results", ucD4PortResult);
            DebugMessageQC("7. D5 Port Test Results", ucD5PortResult);

            DebugMessageQC("7. **** QC Test Finsish Pass ****", 0x00);
            DebugMessageQC("7. MEMORY_TYPE_CONFIG", _MEMORY_TYPE_CONFIG);
            DebugMessageQC("7. MEMORY_SIZE_CONFIG", _MEMORY_SIZE_CONFIG);

            ScalerSetByte(P0_06_TOP_DUMMY1, ucA0PortResult);
            ScalerSetByte(P0_0D_TOP_DUMMY2, ucD0PortResult);
            ScalerSetByte(P0_5E_SYNCPROC_DUMMY0, ucD1PortResult);
            ScalerSetByte(P0_5F_SYNCPROC_DUMMY1, 0x00);

            while(1)
            {
                ScalerDebug();      // QC Test
            }
        }
    }
}

//--------------------------------------------------
// Description  : Switch to Next Port for test
// Input Value  : ucInputPort => Current Test Input Port
// Output Value : _FALSE => No Further port should be tested
//--------------------------------------------------
bit NoneFactoryQCNextPort(BYTE ucInputPort)
{
    BYTE ucInitialPort;
    BYTE ucTemp;

#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
    ucInitialPort = _A0_INPUT_PORT;
#elif(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
    ucInitialPort = _D0_INPUT_PORT;
#elif(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
    ucInitialPort = _D1_INPUT_PORT;
#elif(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
    ucInitialPort = _D2_INPUT_PORT;
#else
    ucInitialPort = _A0_INPUT_PORT;
#endif

    DebugMessageQC("0. Current Port =", ucInputPort);

    for(ucTemp = 0; ucTemp < _NUMBER_OF_INPUT_PORTS; ucTemp++)
    {
        ucInputPort = (ucInputPort + 1) % _NUMBER_OF_INPUT_PORTS;

        switch(ucInputPort)
        {
            case _A0_INPUT_PORT:
                if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
                {
                    ucTemp = _NUMBER_OF_INPUT_PORTS;
                }
                break;

            case _D0_INPUT_PORT:
                if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
                {
                    ucTemp = _NUMBER_OF_INPUT_PORTS;
                }
                break;

            case _D1_INPUT_PORT:
                if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
                {
                    ucTemp = _NUMBER_OF_INPUT_PORTS;
                }
                break;

            case _D2_INPUT_PORT:
                if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
                {
                    ucTemp = _NUMBER_OF_INPUT_PORTS;
                }
                break;

            default:
                break;
        }
    }

    DebugMessageQC("0. Next Port =", ucInputPort);

    if(ucInputPort == ucInitialPort)
    {
        DebugMessageQC("0. Test Finished", ucInputPort);
        return _FALSE;
    }

    SysSourceSwitchInputPort(ucInputPort);
    SysModeSetResetTarget(_MODE_ACTION_RESET_TO_SEARCH);
    SysPowerSetTargetPowerStatus(_POWER_STATUS_NORMAL);

    return _TRUE;
}
#endif
