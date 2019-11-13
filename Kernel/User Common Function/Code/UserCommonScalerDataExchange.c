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
// ID Code      : UserCommonScalerDataExchange.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __USER_COMMON_DATA_EXCHANGE__

#include "UserCommonInclude.h"

#if((_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Data Exchange DDC-CI Slave Address
//--------------------------------------------------
#define _DATA_EXCHANGE_DEFINE_DEVICE_ADDRESS       0x66

//--------------------------------------------------
// Definitions of DDCCI Tx Actual Length, Not include 3 BYTE header
//--------------------------------------------------
#define _DATA_EXCHAGNE_WR_DATA_ADD_HEADER_LEN      3
#define _DATA_EXCHAGNE_WRITE_DATA_LEN              (_TWO_CHIP_DDCCI_EXCHANGE_RXBUF_LENGTH - _DATA_EXCHAGNE_WR_DATA_ADD_HEADER_LEN)

//--------------------------------------------------
// Definitions of DDCCI Rx Actual Length
//--------------------------------------------------
#define _DATA_EXCHAGNE_READ_DATA_LEN               _TWO_CHIP_DDCCI_EXCHANGE_RXBUF_LENGTH

//--------------------------------------------------
// Definitions of DDCCI Tx Protocol Items
//--------------------------------------------------
#define _DATA_EXCHAGNE_TX_LENGTH                   0
#define _DATA_EXCHAGNE_TX_COMMAND_TYPE             1
#define _DATA_EXCHAGNE_TX_START_ADDR               2

//--------------------------------------------------
// Definitions of Data Event
//--------------------------------------------------
#define _DATA_EXCHANGE_EVENT_LEN                   5

//--------------------------------------------------
// Definitions of Data Exchange Transmit Info
//--------------------------------------------------
#define GET_DATA_EXCHANGE_TX_MOT_BIT()             (g_stDataExchangeEventInfo.b1DataExchangeTxEventMotBit)
#define SET_DATA_EXCHANGE_TX_MOT_BIT(x)            (g_stDataExchangeEventInfo.b1DataExchangeTxEventMotBit = (x))

#define GET_DATA_EXCHANGE_TX_STARTADDR()           (g_stDataExchangeEventInfo.b6DataExchangeTxEventSrartAddr)
#define SET_DATA_EXCHANGE_TX_STARTADDR(x)          (g_stDataExchangeEventInfo.b6DataExchangeTxEventSrartAddr = (x))

//--------------------------------------------------
// Definitions of Data Exchange Transmit Info
//--------------------------------------------------
#define GET_DATA_EXCHANGE_TX_INIT_FINISHED()       (g_stDataExchangeEventInfo.b1DataExchangeTxEventInitFinishedBit)
#define SET_DATA_EXCHANGE_TX_INIT_FINISHED(x)      (g_stDataExchangeEventInfo.b1DataExchangeTxEventInitFinishedBit = (x))

#define GET_DATA_EXCHANGE_TX_EVENT()               (g_stDataExchangeEventInfo.b6DataExchangeTxEvent)
#define SET_DATA_EXCHANGE_TX_EVENT(x)              (g_stDataExchangeEventInfo.b6DataExchangeTxEvent = (x))

//--------------------------------------------------
// Definitions of Data Exchange Rx Info
//--------------------------------------------------
#define GET_DATA_EXCHANGE_RX_INIT_FINISHED()       (g_stDataExchangeEventInfo.b1DataExchangeRxInitFinishedBit)
#define SET_DATA_EXCHANGE_RX_INIT_FINISHED(x)      (g_stDataExchangeEventInfo.b1DataExchangeRxInitFinishedBit = (x))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Structure of Event Type
//--------------------------------------------------
typedef struct
{
    BYTE b1DataExchangeBit : 1; // 1-->Init Finished, 0-->Init Not Finished
    EnumDataExchangeCmdType enumDataExchangeEvent; // Data Change Event
} StructDataExchangeNode;

typedef struct
{
    BYTE b1DataExchangeRxInitFinishedBit : 1; // 1--> Rx Init Finished, 0--> Rx Init Not Finished
    BYTE b1DataExchangeTxEventInitFinishedBit : 1; // 1--> Tx Init Finished, 0-->Tx Init Not Finished
    BYTE b6DataExchangeTxEventSrartAddr : 6; // Start Address For Buffer Pointer
    BYTE b6DataExchangeTxEvent : 6; // Tx Event
    BYTE b1DataExchangeTxEventMotBit : 1; // 1--> Not Finished, 0--> Finished
} StructDataExchangeEventInfo;

//****************************************************************************
// CODE TABLES
//****************************************************************************

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
StructDataExchangeEventInfo g_stDataExchangeEventInfo;
StructDataExchangeNode g_pstDataExchangeList[_DATA_EXCHANGE_EVENT_LEN] =
{
    {_FALSE, _EXCHAGNE_CMD_OSD_USER_DATA_GROUP},
    {_FALSE, _EXCHAGNE_CMD_COLOR_PROC_DATA_GROUP},
    {_FALSE, _EXCHAGNE_CMD_BRI_CON_DATA_GROUP},
    {_FALSE, _EXCHAGNE_CMD_MISC_DATA_GROUP},
    {_FALSE, _EXCHAGNE_CMD_INIT_FINISHED},
};

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void UserCommonDataExchangeInit(void);
void UserCommonDataExchangeHandler(void);
void UserCommonDataExchangeRxProc(void);
void UserCommonDataExchangeTxProc(void);
void UserCommonDataExchangeRxDdcci(void);
void UserCommonDataExchangeRxSystem(void);
void UserCommonDataExchangeRxUser(void);
void UserCommonDataExchangeTx(void);
bit UserCommonDataExchangeBusyStatus(void);
bit UserCommonDataExchangeWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucCmd, WORD usLength, BYTE *pucWriteArray, BYTE ucOffset, BYTE ucSWIICStatus, BYTE ucHwIICPinNum);
bit UserCommonDataExchangeWriteData(BYTE ucSlaveAddr, WORD usSubAddr, WORD usLength, BYTE *pucWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum);
void UserCommonDataExchangeEvent(BYTE ucEvent);
EnumDataExchangeCmdType UserCommonDataExchangeCheckEvent(void);
bit UserCommonDataExchangeGetEvent(void);
bit UserCommonDataExchangeSetEvent(EnumDataExchangeCmdType enumEvent);
bit UserCommonDataExchangeSetSentDataEvent(EnumOSDEvenMassage enumEvent);
bit UserCommonDataExchangeSentData(BYTE *pucWriteArray, WORD usLength);
void UserCommonDataExchangeGetData_EXINT1(void);


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Data Exchange Init Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeInit(void)
{
    BYTE ucTimeOut = 10;

    DebugMessageSystem("0. Init... Data Exchange Tx", GET_DATA_EXCHANGE_TX_INIT_FINISHED());
    SET_DATA_EXCHANGE_TX_INIT_FINISHED(_FALSE);

    while((--ucTimeOut > 0) && (GET_DATA_EXCHANGE_TX_INIT_FINISHED() == _FALSE))
    {
        ScalerTimerDelayXms(1);

        if(GET_DATA_EXCHANGE_TX_MOT_BIT() == _FALSE)
        {
            if(UserCommonDataExchangeGetEvent() == _FALSE)
            {
                break;
            }
        }

        UserCommonDataExchangeTx();
    }

    DebugMessageSystem("0. Init... Data Exchange Fnished", GET_DATA_EXCHANGE_TX_INIT_FINISHED());
}

//--------------------------------------------------
// Description  : User Common Data Exchange Handler Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeHandler(void)
{
    UserCommonDataExchangeRxProc();
    UserCommonDataExchangeTxProc();
}

//--------------------------------------------------
// Description  : User Common Data Exchange Handler Rx Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeRxProc(void)
{
    if(GET_RUN_DDCCI_EXCHANGE_COMMAND() == _SUCCESS)
    {
        switch(GET_RUN_DDCCI_EXCHANGE_COMMAND_TYPE())
        {
            case _DATA_EXCHANGE_DDCCI:
                UserCommonDataExchangeRxDdcci();
                break;

            case _DATA_EXCHANGE_SYSTEM:
                UserCommonDataExchangeRxSystem();
                break;

            case _DATA_EXCHANGE_USER:
                UserCommonDataExchangeRxUser();
                break;

            default:

                break;
        }

        memset(g_pucDdcciExchangeRxBuf, 0x00, sizeof(g_pucDdcciExchangeRxBuf));

        SET_RUN_DDCCI_EXCHANGE_COMMAND(_FAIL);
    }
}

//--------------------------------------------------
// Description  : User Common Data Exchange Handler Tx Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeTxProc(void)
{
    if((GET_DATA_EXCHANGE_TX_MOT_BIT() == _FALSE) && (UserCommonDataExchangeGetEvent() == _FALSE))
    {
        return;
    }

    UserCommonDataExchangeTx();
}

//--------------------------------------------------
// Description  : Data Exchange Handler Rx Process For DDC-CI
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeRxDdcci(void)
{
    switch(g_pucDdcciExchangeRxBuf[_DDCCI_EXCHAGNE_RX_COMMAND_TYPE])
    {
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Data Exchange Handler Rx Process For System Data
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeRxSystem(void)
{
    switch(g_pucDdcciExchangeRxBuf[_DDCCI_EXCHAGNE_RX_COMMAND_TYPE])
    {
        default:
            break;
    }
}

//--------------------------------------------------
// Description  : Data Exchange Handler Rx User Receive Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeRxUser(void)
{
    BYTE pucTempBuffer[_DATA_EXCHAGNE_READ_DATA_LEN] = {0};
    BYTE ucReceivedDataLength = 0;

    if(g_pucDdcciExchangeRxBuf[_DDCCI_EXCHAGNE_RX_LENGTH] > _DATA_EXCHAGNE_READ_DATA_LEN)
    {
        ucReceivedDataLength = _DATA_EXCHAGNE_READ_DATA_LEN;
    }
    else
    {
        ucReceivedDataLength = g_pucDdcciExchangeRxBuf[_DDCCI_EXCHAGNE_RX_LENGTH];
    }

    memcpy(pucTempBuffer, g_pucDdcciExchangeRxBuf, ucReceivedDataLength);

    switch(pucTempBuffer[_DDCCI_EXCHAGNE_RX_COMMAND_TYPE])
    {
        default:
            UserInterfaceReceivedDataProc(pucTempBuffer);
            break;
    }
}

//--------------------------------------------------
// Description  : Scaler Data Exchange Handler Tx Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeTx(void)
{
    BYTE *pucWriteArray = 0;
    BYTE pucCmdInitFinishedStr[2] = {0x22, 0xAA};
    BYTE ucMisc = 0;
    WORD usLength = 0;
    WORD usDataExType = _DATA_EXCHANGE_DDCCI;
    StructDataExchangeLuminanceProcData stLuminanceData;
    StructDataExchangeOSDUserData stOsdUserData;
    StructDataExchangeColorProcData stColorProcData;

    if(UserCommonDataExchangeBusyStatus() == _TRUE)
    {
        return;
    }

    if(GET_DATA_EXCHANGE_TX_MOT_BIT() == _TRUE)
    {
        switch(GET_DATA_EXCHANGE_TX_EVENT())
        {
            case _EXCHAGNE_CMD_OSD_USER_DATA_GROUP:
                stOsdUserData.b4ColorTempType = GET_COLOR_TEMP_TYPE();
                stOsdUserData.b4Language = GET_OSD_LANGUAGE();
                stOsdUserData.b3Sharpness = GET_OSD_SHARPNESS();
                stOsdUserData.b1DDCCIStatus = GET_OSD_DDCCI_STATUS();
                stOsdUserData.ucVolume = GET_OSD_VOLUME();
                stOsdUserData.usBackLight = GET_OSD_BACKLIGHT();

                usLength = (sizeof(StructDataExchangeOSDUserData) - GET_DATA_EXCHANGE_TX_STARTADDR());
                pucWriteArray = BYTEPTR(stOsdUserData) + GET_DATA_EXCHANGE_TX_STARTADDR();
                usDataExType = _DATA_EXCHANGE_DDCCI;
                break;

            case _OSDEVENT_SAVE_NVRAM_BRICON_MSG:
                usLength = (sizeof(StructDataExchangeLuminanceProcData) - GET_DATA_EXCHANGE_TX_STARTADDR());
                stLuminanceData.usBrightness = GET_OSD_BRIGHTNESS();
                stLuminanceData.usContrast = GET_OSD_CONTRAST();
                pucWriteArray = BYTEPTR(stLuminanceData) + GET_DATA_EXCHANGE_TX_STARTADDR();
                usDataExType = _DATA_EXCHANGE_DDCCI;
                break;

            case _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG:
                ucMisc = GET_COLOR_TEMP_TYPE();

                if(GET_COLOR_TEMP_TYPE() != _CT_USER)
                {
                    SET_COLOR_TEMP_TYPE(_CT_USER);

                    RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());
                }
                memcpy(BYTEPTR(stColorProcData), &g_stColorProcData, sizeof(StructColorProcDataType));

                SET_COLOR_TEMP_TYPE(ucMisc);

                RTDNVRamLoadColorSetting(GET_COLOR_TEMP_TYPE());

                usLength = (sizeof(StructDataExchangeColorProcData) - GET_DATA_EXCHANGE_TX_STARTADDR());
                pucWriteArray = BYTEPTR(stColorProcData) + GET_DATA_EXCHANGE_TX_STARTADDR();
                usDataExType = _DATA_EXCHANGE_DDCCI;
                break;

            case _EXCHAGNE_CMD_MISC_DATA_GROUP:
                usLength = 1;
                ucMisc = ScalerOsdGetOsdEnable();
                pucWriteArray = &ucMisc;
                usDataExType = _DATA_EXCHANGE_DDCCI;
                break;

            case _EXCHAGNE_CMD_INIT_FINISHED:
                usLength = 2;
                pucWriteArray = pucCmdInitFinishedStr;
                usDataExType = _DATA_EXCHANGE_DDCCI;
                break;

            default:
                break;
        }

        if(usLength <= _DATA_EXCHAGNE_WRITE_DATA_LEN)
        {
            SET_DATA_EXCHANGE_TX_MOT_BIT(_FALSE);

            if(usLength == 0)
            {
                return; // No Data Need to Translate
            }
        }
        else
        {
            SET_DATA_EXCHANGE_TX_MOT_BIT(_TRUE);
            usLength = _DATA_EXCHAGNE_WRITE_DATA_LEN;
        }

        if(UserCommonDataExchangeWrite(_DATA_EXCHANGE_DEFINE_DEVICE_ADDRESS, usDataExType, GET_DATA_EXCHANGE_TX_EVENT(), usLength, pucWriteArray, GET_DATA_EXCHANGE_TX_STARTADDR(), _IIC_DATA_EXCHANGE, _PCB_TWO_CHIP_DATA_EXCHANGE_IIC) == _SUCCESS)
        {
            SET_DATA_EXCHANGE_TX_STARTADDR(GET_DATA_EXCHANGE_TX_STARTADDR() + usLength);
        }
        else
        {
            SET_DATA_EXCHANGE_TX_MOT_BIT(_TRUE); // Retry
            DebugMessageSystem("5.Tx Handler Send Data Retry", 1);
        }
    }
}

//--------------------------------------------------
// Description  : Check Transmit Busy Status Status
// Input Value  : None
// Output Value : _TRUE: Busy _FLSE: Free
//--------------------------------------------------
bit UserCommonDataExchangeBusyStatus(void)
{
    if(GET_TWO_CHIP_HW_SCL_PIN_STATUS() == _LOW)
    {
        DebugMessageSystem("0. SCL is Low", 1);
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Write data to the DDC-CI Port by IIC
// Input Value  : usSubAddr    --> Start address of selected device
//                ucCmd        --> Command Type
//                usLength     --> Numbers of data we want to write
//                pReadArray   --> Result array
//                ucOffset      --> Transmit data start address
//                ucIICStatus   --> SW IIC Applications
//                ucHwIICPinNum --> HW IIC Pin Used
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonDataExchangeWrite(BYTE ucSlaveAddr, WORD usSubAddr, BYTE ucCmd, WORD usLength, BYTE *pucWriteArray, BYTE ucOffset, BYTE ucSWIICStatus, BYTE ucHwIICPinNum)
{
    BYTE pucTempData[_DATA_EXCHAGNE_WRITE_DATA_LEN + _DATA_EXCHAGNE_WR_DATA_ADD_HEADER_LEN]; // + 3 for Length & Op Code & Data Array Start Address

    if(usLength <= 0)
    {
        return _FAIL;
    }

    // Assign Actual Data Lenth
    usLength += _DATA_EXCHAGNE_WR_DATA_ADD_HEADER_LEN;
    pucTempData[_DATA_EXCHAGNE_TX_LENGTH] = usLength;

    // Assign Comand Type Code
    pucTempData[_DATA_EXCHAGNE_TX_COMMAND_TYPE] = ucCmd;

    // Assign Data Structure Start Address
    pucTempData[_DATA_EXCHAGNE_TX_START_ADDR] = ucOffset;

    memcpy(&pucTempData[_DATA_EXCHAGNE_TX_START_ADDR + 1], pucWriteArray, usLength);

    DebugMessageSystem("0. DataExchangeWrite-Slave addr", ucSlaveAddr);
    DebugMessageSystem("0. DataExchangeWrite-usSubAddr", usSubAddr);
    DebugMessageSystem("0. DataExchangeWrite-usLength", pucTempData[_DATA_EXCHAGNE_TX_LENGTH]);
    DebugMessageSystem("0. DataExchangeWrite-Cmd type", pucTempData[_DATA_EXCHAGNE_TX_COMMAND_TYPE]);
    DebugMessageSystem("0. DataExchangeWrite-Start Address", pucTempData[_DATA_EXCHAGNE_TX_START_ADDR]);

    if(UserCommonDataExchangeWriteData(ucSlaveAddr, usSubAddr, usLength, pucTempData, ucSWIICStatus, ucHwIICPinNum) == _SUCCESS)
    {
        return _SUCCESS;
    }
    else
    {
        return _FAIL;
    }
}

//--------------------------------------------------
// Description  : Write data to the DDC-CI Port by IIC
// Input Value  : usSubAddr    --> Start address of selected device
//                usLength     --> Numbers of data we want to write
//                pReadArray   --> Result array
//                ucIICStatus   --> SW IIC Applications
//                ucHwIICPinNum --> HW IIC Pin Used
// Output Value : Reading result (Fail/Success)
//--------------------------------------------------
bit UserCommonDataExchangeWriteData(BYTE ucSlaveAddr, WORD usSubAddr, WORD usLength, BYTE *pucWriteArray, BYTE ucSWIICStatus, BYTE ucHwIICPinNum)
{
    BYTE ucDataCnt = 0;

    ucSWIICStatus = ucSWIICStatus;

    if(usLength <= 0)
    {
        return _FAIL;
    }

    while(usLength > 0)
    {
        // Transmit max effective data 32 bytes each time, DDC-CI Buffer Max Depth = 32 Bytes
        ucDataCnt = _DATA_EXCHAGNE_WRITE_DATA_LEN + _DATA_EXCHAGNE_WR_DATA_ADD_HEADER_LEN; // + 3 Include 3 BYTE Header

        if(usLength > ucDataCnt)
        {
            usLength -= ucDataCnt;
        }
        else
        {
            ucDataCnt = usLength;
            usLength = 0;
        }

        // Execute Hardware IIC Write Command
        if(ucHwIICPinNum == _SW_IIC_PIN_GPIO)
        {
#if(_SW_IIC_SUPPORT == _ON)
            SET_SW_IIC_STATUS(ucSWIICStatus);

            if(ScalerMcuIICWrite(ucSlaveAddr, 1, usSubAddr, ucDataCnt, pucWriteArray) == _FAIL)
            {
                return _FAIL;
            }
#endif // End of #if(_SW_IIC_SUPPORT == _ON)
        }
        else if(ucHwIICPinNum != _NO_IIC_PIN)
        {
#if(_HW_IIC_SUPPORT == _ON)
            if(ScalerMcuHwIICWrite(ucSlaveAddr, 1, usSubAddr, ucDataCnt, pucWriteArray, ucHwIICPinNum) == _FAIL)
            {
                return _FAIL;
            }
#endif // End of #if(_HW_IIC_SUPPORT == _ON)
        }

        // Increase data location
        pucWriteArray += ucDataCnt;
    }

    return _SUCCESS;
}

//--------------------------------------------------
// Description  : Record Data Exchange Event
// Input Value  : ucEvent --> Opration Event
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeEvent(BYTE ucEvent)
{
    DebugMessageSystem("0. Data Exchange Event", ucEvent);

    if(ucEvent == _EXCHAGNE_CMD_DATA_GROUP_NONE)
    {
        SET_DATA_EXCHANGE_TX_MOT_BIT(_FALSE);
    }
    else
    {
        SET_DATA_EXCHANGE_TX_MOT_BIT(_TRUE);
    }

    SET_DATA_EXCHANGE_TX_STARTADDR(0x00);
    SET_DATA_EXCHANGE_TX_EVENT(ucEvent);
}

//--------------------------------------------------
// Description  : Check Data Exchange Event
// Input Value  : None
// Output Value : Event
//--------------------------------------------------
EnumDataExchangeCmdType UserCommonDataExchangeCheckEvent(void)
{
    BYTE ucEventCnt = 0;

    for(ucEventCnt = 0; ucEventCnt < _DATA_EXCHANGE_EVENT_LEN; ucEventCnt++)
    {
        if(g_pstDataExchangeList[ucEventCnt].b1DataExchangeBit == _FALSE)
        {
            g_pstDataExchangeList[ucEventCnt].b1DataExchangeBit = _TRUE;
            return g_pstDataExchangeList[ucEventCnt].enumDataExchangeEvent;
        }
    }

    return _EXCHAGNE_CMD_DATA_GROUP_NONE; // All Init Data Exchange Events Had Been Done
}

//--------------------------------------------------
// Description  : Data Exchange Get Event
// Input Value  : None
// Output Value : _TRUE: Exist Init Event Need Do First, _FALSE: Do Nothing Event
//--------------------------------------------------
bit UserCommonDataExchangeGetEvent(void)
{
    EnumDataExchangeCmdType enumEvent = UserCommonDataExchangeCheckEvent();

    if(enumEvent == _EXCHAGNE_CMD_DATA_GROUP_NONE)
    {
        return _FALSE;
    }

    if(enumEvent == _EXCHAGNE_CMD_INIT_FINISHED)
    {
        SET_DATA_EXCHANGE_TX_INIT_FINISHED(_TRUE); // Record Finished Event Finished
    }

    UserCommonDataExchangeEvent(enumEvent);

    return _TRUE;
}

//--------------------------------------------------
// Description  : Data Exchange Set Event
// Input Value  : enumEvent --> Need to do event
// Output Value : _TRUE: Set Event Successfull, _FALSE: Set Event Fail
//--------------------------------------------------
bit UserCommonDataExchangeSetEvent(EnumDataExchangeCmdType enumEvent)
{
    BYTE ucEventCnt = 0;

    DebugMessageSystem("0. Set Event ~~ =", enumEvent);
    if(enumEvent == _EXCHAGNE_CMD_DATA_GROUP_NONE)
    {
        return _FALSE;
    }

    for(ucEventCnt = 0; ucEventCnt < _DATA_EXCHANGE_EVENT_LEN; ucEventCnt++)
    {
        if(g_pstDataExchangeList[ucEventCnt].b1DataExchangeBit == _FALSE)
        {
            if(g_pstDataExchangeList[ucEventCnt].enumDataExchangeEvent == enumEvent)
            {
                return _TRUE;
            }
        }
    }


    for(ucEventCnt = 0; ucEventCnt < _DATA_EXCHANGE_EVENT_LEN; ucEventCnt++)
    {
        if(g_pstDataExchangeList[ucEventCnt].b1DataExchangeBit == _TRUE)
        {
            g_pstDataExchangeList[ucEventCnt].b1DataExchangeBit = _FALSE;
            g_pstDataExchangeList[ucEventCnt].enumDataExchangeEvent = enumEvent;

            return _TRUE;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Data Exchange Set Send Data Event, this Event will be implement later
// Input Value  : enumEvent --> Need to do event
// Output Value : _TRUE: Set Event Successfull, _FALSE: Set Event Fail
//--------------------------------------------------
bit UserCommonDataExchangeSetSentDataEvent(EnumOSDEvenMassage enumEvent)
{
    EnumDataExchangeCmdType enumExchangeEvent = _EXCHAGNE_CMD_DATA_GROUP_NONE;

    switch(enumEvent)
    {
        case _OSDEVENT_SAVE_NVRAM_OSDUSERDATA_MSG:
            enumExchangeEvent = _EXCHAGNE_CMD_OSD_USER_DATA_GROUP;
            break;

        case _OSDEVENT_SAVE_NVRAM_COLORPROC_MSG:
            enumExchangeEvent = _EXCHAGNE_CMD_COLOR_PROC_DATA_GROUP;
            break;

        case _OSDEVENT_SAVE_NVRAM_BRICON_MSG:
            enumExchangeEvent = _EXCHAGNE_CMD_BRI_CON_DATA_GROUP;
            break;

        default:
            break;
    }

    if(UserCommonDataExchangeSetEvent(enumExchangeEvent) == _TRUE)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Data Exchange Set Send Data Directly
// Input Value  : pucWriteArray --> Will be Send to another device data
//                     usLength --> Send Data Length
// Output Value : _TRUE: Set Event Successfull, _FALSE: Set Event Fail
//--------------------------------------------------
bit UserCommonDataExchangeSentData(BYTE *pucWriteArray, WORD usLength)
{
    if(UserCommonDataExchangeWriteData(_DATA_EXCHANGE_DEFINE_DEVICE_ADDRESS, _DATA_EXCHANGE_USER, usLength, pucWriteArray, _IIC_DATA_EXCHANGE, _PCB_TWO_CHIP_DATA_EXCHANGE_IIC) == _TRUE)
    {
        return _TRUE;
    }
    else
    {
        return _FALSE;
    }
}

//--------------------------------------------------
// Description  : Get DDC-CI1 Data in Interrupt Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserCommonDataExchangeGetData_EXINT1(void) using 2
{
    BYTE ucTemp = 0;

    // Clear Unused DDCCI IRQ Flag
    SET_DDCCI_EXCHANGE_STATUS2(GET_DDCCI_EXCHANGE_STATUS2() & ~(_BIT5 | _BIT4));

    if(GET_RUN_DDCCI_EXCHANGE_COMMAND() == _SUCCESS)
    {
        // Clear Flags
        if((GET_DDCCI_EXCHANGE_STATUS1() & _BIT1) == _BIT1)
        {
            CLR_DDCCI_EXCHANGE_STATUS1(_BIT1);
        }

        if((GET_DDCCI_EXCHANGE_STATUS1() & _BIT2) == _BIT2)
        {
            ucTemp = GET_DDCCI_EXCHANGE_DATA_IN();
        }
    }
    else
    {
        if(GET_DDCCI_EXCHANGE_SLAVE_ADDRESS() == _DATA_EXCHANGE_DEFINE_DEVICE_ADDRESS)
        {
            SET_RUN_DDCCI_EXCHANGE_COMMAND(ScalerMcuDdcciExchangeIntGetData_EXINT1(g_pucDdcciExchangeRxBuf));
        }
        else if(GET_DDCCI_EXCHANGE_SLAVE_ADDRESS() == _DDCCI_DEST_ADDRESS)
        {
            // Copy Data From DDC-CI Mode
            memcpy(g_pucDdcciExchangeRxBuf, g_pucDdcciRxBuf, _DDCCI_RXBUF_LENGTH);
        }
    }
}
#endif // End of #if((_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON) && (_TRANSLATOR_SUPPORT == _OFF))
