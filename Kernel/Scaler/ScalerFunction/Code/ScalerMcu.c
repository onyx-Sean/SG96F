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
// ID Code      : ScalerMcu.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __SCALER_MCU__

#include "ScalerFunctionInclude.h"

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
void ScalerMcuInitial(void);
BYTE ScalerMcuDdcciGetInputPort(void);
void ScalerMcuClockSel(EnumClkSel enumClock);
void ScalerMcuPwmControl(EnumPowerStatus enumPowStatus);
void ScalerMcuCacheInitial(void);

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
void ScalerMcuDdcRamEDIDAddrSelect(EnumD0D1DDCRAMSelect enumDdcRamSel, EnumDDCAddrType enumDdcAddr);
#endif

#if((_DP_TYPE_C_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))
void ScalerMcuReceiveExternalTypeCGlobalIRQ(bit bEn);
#endif


#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
BYTE ScalerMcuDdcciExchangeIntGetData_EXINT1(BYTE *pucReadArray);
#endif

#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
void ScalerMcuSetISPSlaveAddr(BYTE ucISPStatus);
#endif
//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : MCU Initial Settings
//
// MCU initial function, must be called at first
// Since code banking can not work correctly before this function is called,
// this function should stay in bank0.
//
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuInitial(void)
{
    // Clear Watchdog & Set CNT1 to Max
    MCU_FFEA_WATCHDOG_TIMER |= _BIT6 | _BIT2 | _BIT1 | _BIT0;

    // First Mux(epll/m2pll) Select M2pll
    MCU_FFE9_MCU_CLK_CONTROL_1 &= ~_BIT4;

    // Select Flash Clock Divider 1
    ScalerMcuFlashClockDiv(_FLASH_CLK_IN_DIV);

    // Select Flash Clock Divider 2
    ScalerMcuFlash2ClockDiv(_FLASH_2_CLK_IN_DIV);

    // MCU Clock Divider In Power Initial Mode.
    ScalerMcuClockDiv(_MCU_CLK_IN_DIV);


    ////////////////////////
    // Bankswitch Settings//
    ////////////////////////

    // Enable address remapping to XDATA, enable global XRAM and XFR
    // Use Pbank_switch, enable bankswitching function
    MCU_FFFC_BANK_SWICH_CONTROL |= _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0;

    // Select XDATA BANK Start
    MCU_FFFD_XDATA_BANK_START = 0x00;

    // Select first bank number for XDATA access
    MCU_FFFE_XDATA_BANK_SEL = 0x00; // Xdata_bank_sel: Bank0


    ///////////////////////////////
    ///   DDCCI Auto Switch     ///
    ///   ISP Channel Setting   ///
    /// and Switch ISP Address  ///
    ///////////////////////////////

#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
    // Enable DDCCI Auto Switch Function
    MCU_FF2A_IIC_IRQ_CONTROL2 |= _BIT4;

    // Enable VGA_DDC ISP Channel, Disable Other Channel
    ScalerMcuSetISPChannel(_CODE_DIGITAL_SIGNATURE_ISP_SEL_DIS);

    // Set Error ISP Slave Address
    ScalerMcuSetISPSlaveAddr(_DISABLE);
#endif


    //////////////////
    //Cache Initial///
    //////////////////

    ScalerMcuCacheInitial();


    ///////////////////////
    //Delay 5us Caculate///
    ///////////////////////

    ScalerMcu5usDelayCalc(_EXT_XTAL_CLK);


    //////////////////
    //TIMER SETTINGS//
    //////////////////

    // Clock Control, Timer divide by 12 clock, MOVX duration = 2 machine cycles
    CKCON = ((CKCON & ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0)) | _CKCON_MOVX_DEFAULT_CYCLE);

    // Disable all interrupts
    IE = 0x00;

    // Stop Timer0 and Clear Flag
    TR0 = _OFF;
    TF0 = _OFF;

    // Stop Timer1 and Clear Flag
    TR1 = _OFF;
    TF1 = _OFF;

    // Stop Timer2 and Clear Flag
    TR2 = _OFF;
    TF2 = _OFF;
    TCLK = 0;
    RCLK = 0;

#if(_UART_SUPPORT == _ON)
    // Set Timer0 to Mode1 (16bit Counter)
    // Set Timer1 to Mode2 (8bit Counter with Auto-Reload)
    TMOD = 0x21;
#else
    // Set Timer0/1 to Mode1 (16bit counter)
    TMOD = 0x11;
#endif

    // Enable Timer2 AutoReload Mode
    T2CON &= ~_BIT0;

    // Set Interrupt Priority for Timer2
    PT0 = 0;
    PT1 = 0;
    PT2 = 1;

    // Enable Global Interrupt
    EA = _ENABLE;

    // Load Timer2 Count Value
    ScalerTimerSetTimerCount(_TIMER_OPERATION_INITIAL_MODE);

    // Start Watchdog
    MCU_FFEA_WATCHDOG_TIMER |= _BIT7;

#if(_UART_SUPPORT == _ON)

    /////////////////
    //UART Settings//
    /////////////////

    // Set Serial Port to Mode 1
    SM0 = 0;
    SM1 = 1;

    // SMOD0 Set to 1
    PCON |= _BIT7;

    // RI will be only activated if a valid stop is received
    SM2 = 1;

    // Set Serial Port Receive Enable
    REN = _ENABLE;

    // Clear Transmit and Receive Flags
    TI = 0;
    RI = 0;

    // Enable Serial Port IRQ
    ES = _ENABLE;
#endif


    /////////////////////////
    //GPIO Control Settings//
    /////////////////////////

    ScalerMcuGpioInitial();


    ////////////////
    //ISP Settings//
    ////////////////

    ScalerMcuIspInitial();


    ///////////////////
    // Flash Settings//
    ///////////////////

    // Set Flash fast read mode
    MCU_FF6C_READ_INSTRUCTION |= _BIT6;

#if(_PCB_FLASH_LATCH_SO_DATA_IN_RISING_EDGE == _ON)
    // Set latch Flash SO data in Rising edge
    MCU_FF6C_READ_INSTRUCTION &= ~_BIT5;
#else
    // Set latch Flash SO data in falling edge
    MCU_FF6C_READ_INSTRUCTION |= _BIT5;
#endif

    ////////////////
    //PWM Settings//
    ////////////////

#if(_PWM_DUT_RESOLUTION == _PWM_8BIT)
    // Select 8 bit duty width type
    MCU_FF53_PWM_DUT_TYPE |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
#else
    // Select 12 bit duty width type
    MCU_FF53_PWM_DUT_TYPE &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);

    // Enable double buffer mode
    MCU_FF48_PWM_EN |= _BIT7;
#endif

    // Enable PWM reset by DVS
    MCU_FF47_PWM_VS_CTRL = (((BYTE)_PWM5_RST_BY_DVS << 5) | ((BYTE)_PWM4_RST_BY_DVS << 4) | ((BYTE)_PWM3_RST_BY_DVS << 3) |
                            ((BYTE)_PWM2_RST_BY_DVS << 2) | ((BYTE)_PWM1_RST_BY_DVS << 1) | ((BYTE)_PWM0_RST_BY_DVS));


    ////////////////
    //DDC Settings//
    ////////////////

    ScalerMcuDdcInitial();


    ///////////////////
    //DDC-CI Settings//
    ///////////////////

    ScalerMcuDdcciInitial();


    ////////////////
    //IIC Settings//
    ////////////////

#if(_HW_IIC_SUPPORT == _ON)
    ScalerMcuHwIICInitial();
#endif


    ///////////////////
    //SARADC Settings//
    ///////////////////

#if(_LOW_SPEED_ADC_SUPPORT == _ON)
    // Set Threshold for Auto Mode
    MCU_FF0F_ADC0_THRESHOLD_H = 0x00;
    MCU_FF10_ADC0_THRESHOLD_L = 0xFF;
    MCU_FF11_ADC1_THRESHOLD_H = 0x00;
    MCU_FF12_ADC1_THRESHOLD_L = 0xFF;
    MCU_FF13_ADC2_THRESHOLD_H = 0x00;
    MCU_FF14_ADC2_THRESHOLD_L = 0xFF;
    MCU_FF15_ADC3_THRESHOLD_H = 0x00;
    MCU_FF16_ADC3_THRESHOLD_L = 0xFF;

    // Set Auto Mode
    MCU_FF08_ADC_ACONTROL |= _BIT5;

    // Set Wait Time between measure
    MCU_FF17_CTRL0_WAIT_TIME_VALUE = 0x00;

    // Set ADC bias current to 5uA
    MCU_FF08_ADC_ACONTROL &= ~(_BIT2 | _BIT1);

    // ADC Start Scan
    MCU_FF08_ADC_ACONTROL |= _BIT7;
#endif

#if(_WD_TIMER_INT_SUPPORT == _ON)
    ScalerTimerWDInitial();
#endif
}

//--------------------------------------------------
// Description  : Get InputPort by checking Active DDC Channel for Ddccci
// Input Value  : None
// Output Value : InputPort
//--------------------------------------------------
BYTE ScalerMcuDdcciGetInputPort(void)
{
    BYTE ucInput = _NO_INPUT_PORT;

    switch(GET_DDC_CHANNEL())
    {
        case _VGA_DDC2:
        case _VGA_DDC:
            ucInput = _A0_INPUT_PORT;
            break;

        case _DDC0:
#if(_D0_DDC_CHANNEL_SEL == _DDC0)
            ucInput = _D0_INPUT_PORT;
#elif(_D1_DDC_CHANNEL_SEL == _DDC0)
            ucInput = _D1_INPUT_PORT;
#elif(_D2_DDC_CHANNEL_SEL == _DDC0)
            ucInput = _D2_INPUT_PORT;
#endif
            break;

        case _DDC1:
#if(_D0_DDC_CHANNEL_SEL == _DDC1)
            ucInput = _D0_INPUT_PORT;
#elif(_D1_DDC_CHANNEL_SEL == _DDC1)
            ucInput = _D1_INPUT_PORT;
#elif(_D2_DDC_CHANNEL_SEL == _DDC1)
            ucInput = _D2_INPUT_PORT;
#endif
            break;

        case _DDC2:
#if(_D0_DDC_CHANNEL_SEL == _DDC2)
            ucInput = _D0_INPUT_PORT;
#elif(_D1_DDC_CHANNEL_SEL == _DDC2)
            ucInput = _D1_INPUT_PORT;
#elif(_D2_DDC_CHANNEL_SEL == _DDC2)
            ucInput = _D2_INPUT_PORT;
#endif
            break;

        case _DDC3:
            ucInput = _D3_INPUT_PORT;
            break;

        case _DDC4:
            ucInput = _D4_INPUT_PORT;
            break;

        case _DDC5:
            ucInput = _D5_INPUT_PORT;
            break;

        default:
            ucInput = _NO_INPUT_PORT;
            break;
    }

    return ucInput;
}

//--------------------------------------------------
// Description  : CPU Clock Select.
// Input Value  : Clock --> _M2PLL_CLK/_EXT_XTAL_CLK
// Output Value : None
//--------------------------------------------------
void ScalerMcuClockSel(EnumClkSel enumClock)
{
    if(enumClock == _M2PLL_CLK)
    {
        // Bit1 : 1 --> CPU CLK Source Select to M2PLL
        MCU_FFED_MCU_CONTROL |= _BIT1;
    }
    else
    {
        // Bit1 : 0 --> CPU CLK Source Select to Xtal
        MCU_FFED_MCU_CONTROL &= ~_BIT1;
    }
}

//--------------------------------------------------
// Description  : Low Power Consumption Setting For Mcu Module.
// Input Value  : enumPowAction
// Output Value : None
//--------------------------------------------------
void ScalerMcuPwmControl(EnumPowerStatus enumPowStatus)
{
    if(enumPowStatus == _POWER_STATUS_NORMAL)
    {
        // PWM output clock stop disable
        MCU_FFF2_PWM_I2C_CLOCK_STOP |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_FFF2_PWM_I2C_CLOCK_STOP &= ~(((BYTE)_PWM5_EN << 5) | ((BYTE)_PWM4_EN << 4) | ((BYTE)_PWM3_EN << 3) | ((BYTE)_PWM2_EN << 2) | ((BYTE)_PWM1_EN << 1) | ((BYTE)_PWM0_EN));

        // PWM Output Enable
        MCU_FF48_PWM_EN &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_FF48_PWM_EN |= (((BYTE)_PWM5_EN << 5) | ((BYTE)_PWM4_EN << 4) | ((BYTE)_PWM3_EN << 3) | ((BYTE)_PWM2_EN << 2) | ((BYTE)_PWM1_EN << 1) | ((BYTE)_PWM0_EN));

#if(_PWM_RST_BY_TCON == _ON)
        // Enable TCON
        ScalerTconEnable(_ON);

        // Enable PWM reset by TCON
        MCU_FF47_PWM_VS_CTRL |= _BIT6;
#endif
    }
    else if(enumPowStatus == _POWER_STATUS_SAVING)
    {
        // PWM Output Enable
        MCU_FF48_PWM_EN &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_FF48_PWM_EN |= (((BYTE)_PWM5_PSAV_EN << 5) | ((BYTE)_PWM4_PSAV_EN << 4) | ((BYTE)_PWM3_PSAV_EN << 3) | ((BYTE)_PWM2_PSAV_EN << 2) | ((BYTE)_PWM1_PSAV_EN << 1) | ((BYTE)_PWM0_PSAV_EN));

        // PWM output clock stop disable
        MCU_FFF2_PWM_I2C_CLOCK_STOP |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_FFF2_PWM_I2C_CLOCK_STOP &= ~(((BYTE)_PWM5_PSAV_EN << 5) | ((BYTE)_PWM4_PSAV_EN << 4) | ((BYTE)_PWM3_PSAV_EN << 3) |
                                         ((BYTE)_PWM2_PSAV_EN << 2) | ((BYTE)_PWM1_PSAV_EN << 1) | ((BYTE)_PWM0_PSAV_EN));
    }
    else if(enumPowStatus == _POWER_STATUS_OFF)
    {
        // PWM Output Disable when Power Down(or enable by define)
        MCU_FF48_PWM_EN &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_FF48_PWM_EN |= (((BYTE)_PWM5_PDOW_EN << 5) | ((BYTE)_PWM4_PDOW_EN << 4) | ((BYTE)_PWM3_PDOW_EN << 3) | ((BYTE)_PWM2_PDOW_EN << 2) | ((BYTE)_PWM1_PDOW_EN << 1) | ((BYTE)_PWM0_PDOW_EN));

        // PWM Output Clock Stop Enable when Power Down(or enable by define)
        MCU_FFF2_PWM_I2C_CLOCK_STOP |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
        MCU_FFF2_PWM_I2C_CLOCK_STOP &= ~(((BYTE)_PWM5_PDOW_EN << 5) | ((BYTE)_PWM4_PDOW_EN << 4) | ((BYTE)_PWM3_PDOW_EN << 3) |
                                         ((BYTE)_PWM2_PDOW_EN << 2) | ((BYTE)_PWM1_PDOW_EN << 1) | ((BYTE)_PWM0_PDOW_EN));
    }
    else
    {
        // PWM Output Disable
        MCU_FF48_PWM_EN &= ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);

        // PWM Output Clock Stop Enable
        MCU_FFF2_PWM_I2C_CLOCK_STOP |= (_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0);
    }
}

//--------------------------------------------------
// Description  : Cache Initial Settings
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMcuCacheInitial(void)
{
    // Reset Cache
    MCU_FDA1_CACHE_OPTION |= _BIT0;
    MCU_FDA1_CACHE_OPTION &= ~_BIT0;

    // Disable Common Bank Function
    MCU_FDA1_CACHE_OPTION &= ~_BIT1;

    // Enable Cache
    MCU_FDA0_CACHE_FUNCTION |= _BIT0;
}

#if(_D6_INPUT_PORT_TYPE != _D6_NO_PORT)
//--------------------------------------------------
// Description  : D0/D1 DDC RAM layout selected
// Input Value  : enumDdcRamSel --> D0 or D1 DDCRAM; enumDdcAddr --> Point to Top or bottom address
// Output Value : None
//--------------------------------------------------
void ScalerMcuDdcRamEDIDAddrSelect(EnumD0D1DDCRAMSelect enumDdcRamSel, EnumDDCAddrType enumDdcAddr)
{
    switch(enumDdcRamSel)
    {
        case _D0_DDCRAM:

            if(enumDdcAddr == _DDCRAM_TOP_ADDR)
            {
                MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT0;
            }
            else
            {
                MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT0;
            }

            break;

        case _D1_DDCRAM:

            if(enumDdcAddr == _DDCRAM_TOP_ADDR)
            {
                MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT1;
            }
            else
            {
                MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT1;
            }

            break;

        default:
            break;
    }
}
#endif

#if((_DP_TYPE_C_SUPPORT == _ON) && (_PORT_CONTROLLER_EMBEDDED_SUPPORT == _ON))
//--------------------------------------------------
// Description  : Main 8051 access external TypeC IRQ
// Input Value  : bEn --> _ENABLE or _DISABLE
// Output Value : None
//--------------------------------------------------
void ScalerMcuReceiveExternalTypeCGlobalIRQ(bit bEn)
{
    if(bEn == _ENABLE)
    {
        // Clerar IRQ Flag and Enable TypeC Global IRQ
        MCU_FD29_UFP_DPF_IRQ_STATUS |= (_BIT7 | _BIT6);
    }
    else
    {
        // Disable TypeC Global IRQ
        MCU_FD29_UFP_DPF_IRQ_STATUS &= ~_BIT6;
    }
}
#endif

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get DDC-CI1 Data in Interrupt Process
// Input Value  : pReadArray --> Data received
// Output Value : _SUCCESS or _FAIL
//--------------------------------------------------
BYTE ScalerMcuDdcciExchangeIntGetData_EXINT1(BYTE *pucReadArray) using 2
{
    // Get DDC-CI Sub Address Latched
    if((MCU_FE8B_IIC_1_STATUS & _BIT1) == _BIT1)
    {
        g_ucDdcciExchangeCountEXINT = 0;

        // Save Address
        pucReadArray[g_ucDdcciExchangeCountEXINT++] = MCU_FE88_IIC_1_SUB_IN;

        // Clear Flag
        MCU_FE8B_IIC_1_STATUS &= ~_BIT1;
    }

    if((MCU_FE8B_IIC_1_STATUS & _BIT2) == _BIT2)
    {
        // Save received data until buffer empty
        while((MCU_FE8D_IIC_1_STATUS2 & _BIT1) == 0)
        {
            if(g_ucDdcciExchangeCountEXINT >= _DDCCI_RXBUF_LENGTH)
            {
                // Reset data buffer
                MCU_FE8E_IIC_1_IRQ_CONTROL2 |= _BIT6;

                g_ucDdcciExchangeCountEXINT = 0;

                break;
            }

            pucReadArray[g_ucDdcciExchangeCountEXINT++] = MCU_FE89_IIC_1_DATA_IN;

            // All data are received
            if((pucReadArray[1] & 0x7F) == g_ucDdcciExchangeCountEXINT)
            {
                // Reset data buffer and Enable mcu write
                MCU_FE8E_IIC_1_IRQ_CONTROL2 |= (_BIT6 | _BIT5);

                g_ucDdcciExchangeCountEXINT = 0;

                for(pData_EXINT[0] = 32; pData_EXINT[0] > 0; pData_EXINT[0] --)
                {
                    MCU_FE8A_IIC_1_DATA_OUT = 0;
                }

                // Disable mcu write
                MCU_FE8E_IIC_1_IRQ_CONTROL2 &= ~_BIT5;

                // Reset data buffer
                MCU_FE8E_IIC_1_IRQ_CONTROL2 |= _BIT6;

                return _SUCCESS;
            }
        }
    }

    return _FAIL;
}
#endif // End of #if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)

#if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
//--------------------------------------------------
// Description  : Modify ISP addr
// Input Value  : _ENABLE or _DISABLE
// Output Value : NONE
//--------------------------------------------------
void ScalerMcuSetISPSlaveAddr(BYTE ucISPStatus)
{
    if(ucISPStatus == _ENABLE)
    {
        // Set ISP Slave Address to Right Value
        MCU_FFEC_ISP_SLAVE_ADDRESS = 0x94;
    }
    else
    {
        // Set ISP Slave Address to any Wrong Value,
        MCU_FFEC_ISP_SLAVE_ADDRESS = 0xEE;
    }
}
#endif // End of #if(_CODE_DIGITAL_SIGNATURE_SUPPORT == _SIGNATURE_TYPE_EXTERNAL)
