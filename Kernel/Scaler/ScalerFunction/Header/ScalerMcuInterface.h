/********************************************************************************/
/*   The  Software  is  proprietary,  confidential,  and  valuable to Realtek   */
/*   Semiconductor  Corporation  ("Realtek").  All  rights, including but not   */
/*   limited  to  copyrights,  patents,  trademarks, trade secrets, mask work   */
/*   rights, and other similar rights and interests, are reserved to Realtek.   */
/*   Without  prior  written  consent  from  Realtek,  copying, reproduction,   */
/*   modification,  distribution,  or  otherwise  is strictly prohibited. The   */
/*   Software  shall  be  kept  strictly  in  confidence,  and  shall  not be   */
/*   disclosed to or otherwise accessed by any third party.                     */
/*   c<2003> - <2011>                                                           */
/*   The Software is provided "AS IS" without any warranty of any kind,         */
/*   express, implied, statutory or otherwise.                                  */
/********************************************************************************/

//----------------------------------------------------------------------------------------------------
// ID Code      : ScalerMcuInterface.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// INTERFACE DEFINITIONS / MACROS
//****************************************************************************
#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
//--------------------------------------------------
// Macros of DDC-CI1
//--------------------------------------------------
#define GET_DDCCI_EXCHANGE_SLAVE_ADDRESS()             (MCU_FE87_IIC_1_SET_SLAVE & 0xFE)
#define GET_DDCCI_EXCHANGE_SUBADDRESS()                (MCU_FE88_IIC_1_SUB_IN)
#define GET_DDCCI_EXCHANGE_DATA_IN()                   (MCU_FE89_IIC_1_DATA_IN)
#define GET_DDCCI_EXCHANGE_STATUS1()                   (MCU_FE8B_IIC_1_STATUS)
#define GET_DDCCI_EXCHANGE_STATUS2()                   (MCU_FE8D_IIC_1_STATUS2)
#define GET_DDCCI_EXCHANGE_IRQ_STATUS()                (MCU_FE8E_IIC_1_IRQ_CONTROL2)

#define SET_DDCCI_EXCHANGE_SLAVE_ADDRESS(x)            (MCU_FE87_IIC_1_SET_SLAVE = ((x) & 0xFE))
#define SET_DDCCI_EXCHANGE_DATA_OUT(x)                 (MCU_FE8A_IIC_1_DATA_OUT = (x))
#define CLR_DDCCI_EXCHANGE_STATUS1(x)                  (MCU_FE8B_IIC_1_STATUS &= ~(x))
#define SET_DDCCI_EXCHANGE_STATUS2(x)                  (MCU_FE8D_IIC_1_STATUS2 = (x))
#define SET_DDCCI_EXCHANGE_IRQ_STATUS(x)               (MCU_FE8E_IIC_1_IRQ_CONTROL2 = (x))
#define GET_DDCCI_EXCHANGE_DDC_CHANNEL()               (MCU_FE86_IIC_1_CH_SEL & (_BIT2 | _BIT1 | _BIT0))
#endif // End of #if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)

//****************************************************************************
// INTERFACE VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// INTERFACE FUNCTIONS
//****************************************************************************
extern void ScalerMcuInitial(void);
extern BYTE ScalerMcuDdcciGetInputPort(void);
extern void ScalerMcuClockSel(EnumClkSel enumClock);
extern void ScalerMcuPwmControl(EnumPowerStatus enumPowStatus);

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
extern BYTE ScalerMcuDdcciExchangeIntGetData_EXINT1(BYTE *pucReadArray);
#endif

#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
extern void ScalerMcuSetISPSlaveAddr(BYTE ucISPStatus);
#endif
