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
// ID Code      : RTD2014UserHdr.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

#if(_ULTRA_HDR_SUPPORT == _ON)
#if(_LOCAL_DIMMING_SUPPORT == _ON)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _PANEL_PWM_LOCAL_1                          _DEVICE_LED_DRIVER_PWM_1
#define _PANEL_PWM_LOCAL_2                          _DEVICE_LED_DRIVER_PWM_2
#define _PANEL_PWM_LOCAL_3                          _DEVICE_LED_DRIVER_PWM_3
#define _PANEL_PWM_LOCAL_4                          _DEVICE_LED_DRIVER_PWM_4
#define _PANEL_PWM_LOCAL_5                          _DEVICE_LED_DRIVER_PWM_5
#define _PANEL_PWM_LOCAL_6                          _DEVICE_LED_DRIVER_PWM_6
#define _PANEL_PWM_LOCAL_7                          _DEVICE_LED_DRIVER_PWM_7
#define _PANEL_PWM_LOCAL_8                          _DEVICE_LED_DRIVER_PWM_8
#define _PANEL_PWM_LOCAL_9                          _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_10                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_11                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_12                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_13                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_14                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_15                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_16                         _DEVICE_LED_DRIVER_PWM_NONE
#define _PANEL_PWM_LOCAL_ALL                        _DEVICE_LED_DRIVER_PWM_ALL

#define _PANEL_PWM_LOCAL_START                      _DEVICE_LED_DRIVER_PWM_1
#define _PANEL_PWM_LOCAL_END                        _DEVICE_LED_DRIVER_PWM_8

// Opteration Mode
#define _DEFAULT_VSYNC_MODE                         _VSYNC_TRIGGERS_ON_RISING_EDGE
#define _DEFAULT_UPDATE_MODE                        _UPDATE_MODE_BY_CSB
#define _DEFAULT_ADMIM_MODE                         _ADIM_SET_BY_INTERNAL_REG
#define _DEFAULT_PWM_MODE                           _PWM_DETERMINED_BY_INTERNAL_REG
#define _DEFAULT_INDUCTOR_EN                        _BALANCE_WITH_INDUCTOR
#define _DEFAULT_HSYNC_EN                           _HSYNC_DISABLE
#define _DEFAULT_PWM_EN                             _PWM_NORMAL

// Opteration Status
#define _DEFAULT_STATUS_MODE                        0x00

// PWM period and Period Reset control
#define _DEFAULT_HSYNC_DIV                          _HSYNC_FREQ_1_OFF_4
#define _DEFAULT_PERIOD_RST_MODE                    _ON//_PERIOD_RST_AT_VSYNC_EDGE
#define _DEFAULT_PERIOD_VALUE                       0x1FFF                       // Rang : 0 ~ 0x1FFF

// Analog diming level control
#define _DEFAULT_ADIM_LEVEL_VALUE                   0x3FF                        // Rang : 0 ~ 0x3FF
#define _DEFAULT_ADJUST_SPEED                       0                            // Rang : 0~15, 0.0156m sec/step
#define _DEFAULT_OCP_THRESHOLD                      _OCP_THRESHOLD_2V5

// Initial value
#define _OPERATION_MODE                             ((_DEFAULT_PWM_EN << 7) | (_DEFAULT_HSYNC_EN << 6) | (_DEFAULT_INDUCTOR_EN << 5) | (_DEFAULT_PWM_MODE << 4) | (_DEFAULT_ADMIM_MODE << 3) | (_DEFAULT_UPDATE_MODE << 2) | (_DEFAULT_VSYNC_MODE))
#define _OPERATION_STATUS                           (_DEFAULT_STATUS_MODE)
#define _PERIOD_CONTROL                             (_DEFAULT_PERIOD_VALUE & 0x00FF)
#define _PERIOD_CONTROL2                            ((_DEFAULT_HSYNC_DIV << 6) | (_DEFAULT_PERIOD_RST_MODE << 5) | ((_DEFAULT_PERIOD_VALUE & 0x1F00) >> 8))
#define _DIMMING_LEVEL_CONTROL                      (_DEFAULT_ADIM_LEVEL_VALUE & 0x00FF)
#define _DIMMING_LEVEL_CONTROL2                     ((_DEFAULT_ADJUST_SPEED << 4) | (_DEFAULT_OCP_THRESHOLD << 2) | ((_DEFAULT_ADIM_LEVEL_VALUE & 0x300) >> 8))

//--------------------------------------------------
// Setting
//--------------------------------------------------
#ifndef _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS
#define _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS      0x40
#endif

#define _DEVICE_LED_DRIVER_READ_SLAVE_ADDRESS       (_DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS | _BIT0)

#define _REG_ADDRESS_OPERATION_MODE                 0x01
#define _REG_ADDRESS_OPERATION_STATUS               0x02
#define _REG_ADDRESS_PERIOD_CONTROL                 0x03
#define _REG_ADDRESS_PERIOD_CONTROL2                0x04
#define _REG_ADDRESS_DIMMING_LEVEL_CONTROL          0x05
#define _REG_ADDRESS_DIMMING_LEVEL_CONTROL2         0x06

//--------------------------------------------------
// PWM Delay Time
//--------------------------------------------------
#define _REG_ADDRESS_PWM1_DELAY_TIME_LSB            0x10
#define _REG_ADDRESS_PWM1_DELAY_TIME_MSB            0x11
#define _REG_ADDRESS_PWM2_DELAY_TIME_LSB            0x12
#define _REG_ADDRESS_PWM2_DELAY_TIME_MSB            0x13
#define _REG_ADDRESS_PWM3_DELAY_TIME_LSB            0x14
#define _REG_ADDRESS_PWM3_DELAY_TIME_MSB            0x15
#define _REG_ADDRESS_PWM4_DELAY_TIME_LSB            0x16
#define _REG_ADDRESS_PWM4_DELAY_TIME_MSB            0x17
#define _REG_ADDRESS_PWM5_DELAY_TIME_LSB            0x18
#define _REG_ADDRESS_PWM5_DELAY_TIME_MSB            0x19
#define _REG_ADDRESS_PWM6_DELAY_TIME_LSB            0x1A
#define _REG_ADDRESS_PWM6_DELAY_TIME_MSB            0x1B
#define _REG_ADDRESS_PWM7_DELAY_TIME_LSB            0x1C
#define _REG_ADDRESS_PWM7_DELAY_TIME_MSB            0x1D
#define _REG_ADDRESS_PWM8_DELAY_TIME_LSB            0x1E
#define _REG_ADDRESS_PWM8_DELAY_TIME_MSB            0x1F
#define _REG_ADDRESS_PWM9_DELAY_TIME_LSB            0x20
#define _REG_ADDRESS_PWM9_DELAY_TIME_MSB            0x21
#define _REG_ADDRESS_PWM10_DELAY_TIME_LSB           0x22
#define _REG_ADDRESS_PWM10_DELAY_TIME_MSB           0x23
#define _REG_ADDRESS_PWM11_DELAY_TIME_LSB           0x24
#define _REG_ADDRESS_PWM11_DELAY_TIME_MSB           0x25
#define _REG_ADDRESS_PWM12_DELAY_TIME_LSB           0x26
#define _REG_ADDRESS_PWM12_DELAY_TIME_MSB           0x27
#define _REG_ADDRESS_PWM13_DELAY_TIME_LSB           0x28
#define _REG_ADDRESS_PWM13_DELAY_TIME_MSB           0x29
#define _REG_ADDRESS_PWM14_DELAY_TIME_LSB           0x2A
#define _REG_ADDRESS_PWM14_DELAY_TIME_MSB           0x2B
#define _REG_ADDRESS_PWM15_DELAY_TIME_LSB           0x2C
#define _REG_ADDRESS_PWM15_DELAY_TIME_MSB           0x2D
#define _REG_ADDRESS_PWM16_DELAY_TIME_LSB           0x2E
#define _REG_ADDRESS_PWM16_DELAY_TIME_MSB           0x2F

//--------------------------------------------------
// PWM Plus Width
//--------------------------------------------------
#define _REG_ADDRESS_PWM1_PLUS_WIDTH_LSB            0x30
#define _REG_ADDRESS_PWM1_PLUS_WIDTH_MSB            0x31
#define _REG_ADDRESS_PWM2_PLUS_WIDTH_LSB            0x32
#define _REG_ADDRESS_PWM2_PLUS_WIDTH_MSB            0x33
#define _REG_ADDRESS_PWM3_PLUS_WIDTH_LSB            0x34
#define _REG_ADDRESS_PWM3_PLUS_WIDTH_MSB            0x35
#define _REG_ADDRESS_PWM4_PLUS_WIDTH_LSB            0x36
#define _REG_ADDRESS_PWM4_PLUS_WIDTH_MSB            0x37
#define _REG_ADDRESS_PWM5_PLUS_WIDTH_LSB            0x38
#define _REG_ADDRESS_PWM5_PLUS_WIDTH_MSB            0x39
#define _REG_ADDRESS_PWM6_PLUS_WIDTH_LSB            0x3A
#define _REG_ADDRESS_PWM6_PLUS_WIDTH_MSB            0x3B
#define _REG_ADDRESS_PWM7_PLUS_WIDTH_LSB            0x3C
#define _REG_ADDRESS_PWM7_PLUS_WIDTH_MSB            0x3D
#define _REG_ADDRESS_PWM8_PLUS_WIDTH_LSB            0x3E
#define _REG_ADDRESS_PWM8_PLUS_WIDTH_MSB            0x3F
#define _REG_ADDRESS_PWM9_PLUS_WIDTH_LSB            0x40
#define _REG_ADDRESS_PWM9_PLUS_WIDTH_MSB            0x41
#define _REG_ADDRESS_PWM10_PLUS_WIDTH_LSB           0x42
#define _REG_ADDRESS_PWM10_PLUS_WIDTH_MSB           0x43
#define _REG_ADDRESS_PWM11_PLUS_WIDTH_LSB           0x44
#define _REG_ADDRESS_PWM11_PLUS_WIDTH_MSB           0x45
#define _REG_ADDRESS_PWM12_PLUS_WIDTH_LSB           0x46
#define _REG_ADDRESS_PWM12_PLUS_WIDTH_MSB           0x47
#define _REG_ADDRESS_PWM13_PLUS_WIDTH_LSB           0x48
#define _REG_ADDRESS_PWM13_PLUS_WIDTH_MSB           0x49
#define _REG_ADDRESS_PWM14_PLUS_WIDTH_LSB           0x4A
#define _REG_ADDRESS_PWM14_PLUS_WIDTH_MSB           0x4B
#define _REG_ADDRESS_PWM15_PLUS_WIDTH_LSB           0x4C
#define _REG_ADDRESS_PWM15_PLUS_WIDTH_MSB           0x4D
#define _REG_ADDRESS_PWM16_PLUS_WIDTH_LSB           0x4E
#define _REG_ADDRESS_PWM16_PLUS_WIDTH_MSB           0x4F

//--------------------------------------------------
// PWM Smooth Level
//--------------------------------------------------
#define _PWM_SMOOTH_MAX                             0x64
#define _PWM_SMOOTH_MIN                             0x01F4
#define _PWM_SMOOTH_SECTION                         100

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _DEVICE_LED_DRIVER_PWM_1,
    _DEVICE_LED_DRIVER_PWM_2,
    _DEVICE_LED_DRIVER_PWM_3,
    _DEVICE_LED_DRIVER_PWM_4,
    _DEVICE_LED_DRIVER_PWM_5,
    _DEVICE_LED_DRIVER_PWM_6,
    _DEVICE_LED_DRIVER_PWM_7,
    _DEVICE_LED_DRIVER_PWM_8,
    _DEVICE_LED_DRIVER_PWM_9,
    _DEVICE_LED_DRIVER_PWM_10,
    _DEVICE_LED_DRIVER_PWM_11,
    _DEVICE_LED_DRIVER_PWM_12,
    _DEVICE_LED_DRIVER_PWM_13,
    _DEVICE_LED_DRIVER_PWM_14,
    _DEVICE_LED_DRIVER_PWM_15,
    _DEVICE_LED_DRIVER_PWM_16,
    _DEVICE_LED_DRIVER_PWM_ALL,
    _DEVICE_LED_DRIVER_PWM_NONE = 0xFF,
} EnumDeviceLedDriverPwm;

typedef enum
{
    _VSYNC_TRIGGERS_ON_RISING_EDGE  = 0x01,
    _VSYNC_TRIGGERS_ON_FALLING_EDGE,
    _VSYNC_TRIGGERS_ON_BOTH_EDGE,
}EnumOperationModeVsyncMode;

typedef enum
{
    _UPDATE_MODE_BY_CSB = 0,
    _UPDATE_MODE_BY_VSYNC,

}EnumOperationModeUpdateMode;

typedef enum
{
    _ADIM_SET_BY_ADIM_PIN = 0,
    _ADIM_SET_BY_INTERNAL_REG,

}EnumOperationAdimMode;

typedef enum
{
    _PWM_DETERMINED_BY_INTERNAL_REG  = 0,
    _PWM_DETERMINED_BY_VSYNC,

}EnumOperationPwmMode;

typedef enum
{
    _BALANCE_WITH_INDUCTOR = 0,
    _BALANCE_WITHOUT_INDUCTOR,

}EnumOperationInductorEn;

typedef enum
{
    _HSYNC_DISABLE = 0,
    _HSYNC_ENABLE,

}EnumOperationHsyncEn;

typedef enum
{
    _PWM_OFF = 0,
    _PWM_NORMAL,

}EnumOperationPwmEn;

typedef enum
{
    _HSYNC_FREQ_1_OFF_4 = 0,
    _HSYNC_FREQ_1_OFF_8,
    _HSYNC_FREQ_1_OFF_16,
    _HSYNC_FREQ_1_OFF_32,

}EnumOperationHsyncDiv;

typedef enum
{
    _PERIOD_RST_AT_VSYNC_EDGE = 0,

}EnumOperationPeriodRst;

typedef enum
{
    _OCP_THRESHOLD_1V = 0,
    _OCP_THRESHOLD_1V5,
    _OCP_THRESHOLD_2V,
    _OCP_THRESHOLD_2V5,

}EnumOCPThreshold;


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
WORD g_usLedControlPwm = 0;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void DeviceInterfaceLedDriverBacklightPowerPin(BYTE ucEnable);
void DeviceInterfaceLedDriverBacklightPower(BYTE ucEnable);
//bit DeviceInterfaceLedDriverDebug(BYTE ucType, BYTE *ucDdcciArray, BYTE *ucReturnValue);
void UserInterfaceLedDriverInitial(void);
void DeviceInterfaceLedDriverPwmFrequency(WORD usFrequency);
void DeviceInterfaceLedDriverPwm(EnumDeviceLedDriverPwm enumDeviceLedDriverPwm, WORD usValue);
void UserInterfaceLedDriverPwmArray(WORD *pusValue);
void DeviceInterfaceLedDriverSetPwmDelay(void);
void DeviceInterfaceLedDriverPwmControl(bit bPwmControl);
WORD UserInterfaceLedDriverPWMSmoothLevel(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void DeviceInterfaceLedDriverBacklightPowerPin(BYTE ucEnable)
{
    if(_LIGHT_CONTROL_ON == ucEnable)
    {
        bBACKLIGHTPOWER = ucEnable;
        ScalerTimerDelayXms(20);
        DeviceInterfaceLedDriverPwmControl(ucEnable);
        DeviceInterfaceLedDriverPwm(_PANEL_PWM_LOCAL_ALL, ((g_usLedControlPwm) * 9));
    }
    else
    {
        DeviceInterfaceLedDriverPwm(_PANEL_PWM_LOCAL_ALL, 0x0000);
        DeviceInterfaceLedDriverPwmControl(ucEnable);
        ScalerTimerDelayXms(20);
        bBACKLIGHTPOWER = ucEnable;
    }
}

//--------------------------------------------------
// Description  :
// Input Value  :
// Output Value :
//--------------------------------------------------
void DeviceInterfaceLedDriverBacklightPower(BYTE ucEnable)
{
    if(ucEnable == _LIGHT_CONTROL_ON)
    {
        ScalerTimerActiveTimerEvent(SEC(60), _USER_TIMER_EVENT_PANEL_USED_TIMER);
        ScalerMcuPwmAdjustFrequency(_BACKLIGHT_PWM, 480);
    }
    else
    {
        ScalerTimerCancelTimerEvent(_USER_TIMER_EVENT_PANEL_USED_TIMER);
    }
    PCB_BACKLIGHT_POWER_PIN(ucEnable);
}
/*
//--------------------------------------------------
// Description  : Set Led Driver Debug
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit DeviceInterfaceLedDriverDebug(BYTE ucType, BYTE *ucDdcciArray, BYTE *ucReturnValue)
{
    BYTE ucRegData[5] = {0};

    if(*(ucDdcciArray + 2) != _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS)
    {
        return _FALSE;
    }

    if(ucType == _READ)
    {
        ucRegData[0] = _DEVICE_LED_DRIVER_READ_SLAVE_ADDRESS;
        ucRegData[1] = *(ucDdcciArray + 1);

#if(_SPI_SUPPORT == _ON)
        //SPI_READ(3, ucRegData);
        ScalerSpiData(_READ, 3, ucRegData);
#endif

        *ucReturnValue = ucRegData[0];
    }
    else if(ucType == _WRITE)
    {
        ucRegData[0] = _DEVICE_LED_DRIVER_READ_SLAVE_ADDRESS;
        ucRegData[1] = *(ucDdcciArray + 1);

#if(_SPI_SUPPORT == _ON)
        //SPI_READ(3, ucRegData);
        ScalerSpiData(_READ, 3, ucRegData);
#endif

		ucRegData[3] = ucRegData[1];
		ucRegData[4] = ucRegData[2];
        ucRegData[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
        ucRegData[1] = *(ucDdcciArray + 1);
        ucRegData[2] = *(ucDdcciArray + 3);

#if(_SPI_SUPPORT == _ON)
        //SPI_WRITE(5, ucRegData);
        ScalerSpiData(_WRITE, 5, ucRegData);
#endif
    }

    return _TRUE;
}
*/

//--------------------------------------------------
// Description  : Set Led Driver Initial
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceLedDriverInitial(void)
{
    BYTE ucTemp[8] = {0};

#if(_SPI_SUPPORT == _ON)
    //ScalerSpiInitial(_SPI_TIMING_MODE2, _CLK_SOURCE_M2PLL, 15, _HIGH);
    ScalerSpiInitial();
#endif

    ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
    ucTemp[1] = _REG_ADDRESS_OPERATION_MODE;
    ucTemp[2] = _OPERATION_MODE;
    ucTemp[3] = _OPERATION_STATUS;
    ucTemp[4] = _PERIOD_CONTROL;
    ucTemp[5] = _PERIOD_CONTROL2;
    ucTemp[6] = _DIMMING_LEVEL_CONTROL;
    ucTemp[7] = _DIMMING_LEVEL_CONTROL2;

#if(_SPI_SUPPORT == _ON)
    //SPI_WRITE(8, ucTemp);
    ScalerSpiData(_WRITE, 8, ucTemp);
#endif

    DeviceInterfaceLedDriverSetPwmDelay();
    DeviceInterfaceLedDriverPwmFrequency(0);
    //DeviceInterfaceLedDriverPwm(_PANEL_PWM_LOCAL_ALL, 0x0000);
#if(_ULTRA_HDR_SUPPORT == _ON)
    if(UserInterfaceGetHDREnableStatus() == _ON)
    {
        DeviceInterfaceLedDriverPwm(_PANEL_PWM_LOCAL_ALL, 0x800);
    }
    else
#endif
    {
        UserAdjustBacklight(GET_OSD_BACKLIGHT());
    }
}

//--------------------------------------------------
// Description  : Set Led Driver Pwm Delay
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void DeviceInterfaceLedDriverSetPwmDelay(void)
{
    BYTE i = 0;
    BYTE ucTemp[4] = {0};
    WORD usTempDelay = 0;

    for(i = 0; i < 15; i++)
    {
        ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
        ucTemp[1] = _REG_ADDRESS_PWM1_DELAY_TIME_LSB+i*2;
        ucTemp[2] = (BYTE)usTempDelay;
        ucTemp[3] = (BYTE)(usTempDelay >> 8);

#if(_SPI_SUPPORT == _ON)
        //SPI_WRITE(4, ucTemp);
        ScalerSpiData(_WRITE, 4, ucTemp);
#endif

        usTempDelay = usTempDelay+228;
    }
}

//--------------------------------------------------
// Description  : Set Led Driver Pwm Enable/Disable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void DeviceInterfaceLedDriverPwmControl(bit bPwmControl)
{
    BYTE ucTemp[3] = {0};
    BYTE ucResult = 0;
/*
    if(bPwmControl == _LIGHT_CONTROL_ON)
    {
        ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
        ucTemp[1] = _REG_ADDRESS_OPERATION_MODE;
        ucTemp[2] = _OPERATION_MODE;
        //ucTemp[2] = ((ucResult & ~(_BIT7)) | (_PWM_NORMAL << 7));

#if(_SPI_SUPPORT == _ON)
        SPI_WRITE(3, ucTemp);
        //ScalerSpiData(_WRITE, 3, ucTemp);
#endif
    }
    else
    {
        ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
        ucTemp[1] = _REG_ADDRESS_OPERATION_MODE;
        //ucTemp[2] = ((ucResult & ~(_BIT7)) | (_PWM_OFF << 7));
        ucTemp[2] = _OPERATION_OFF_MODE;

#if(_SPI_SUPPORT == _ON)
        SPI_WRITE(3, ucTemp);
        ScalerSpiData(_WRITE, 3, ucTemp);
#endif
    }
    return;
*/
#if(_SPI_SUPPORT == _ON)
    ucTemp[0] = _DEVICE_LED_DRIVER_READ_SLAVE_ADDRESS;
    ucTemp[1] = _REG_ADDRESS_OPERATION_MODE;
    //SPI_READ(3, ucTemp);
    ScalerSpiData(_READ, 3, ucTemp);
    ucResult = ucTemp[0];
#endif // End of #if(_SPI_SUPPORT == _ON)

    if(bPwmControl == _LIGHT_CONTROL_ON)
    {
        ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
        ucTemp[1] = _REG_ADDRESS_OPERATION_MODE;
        //ucTemp[2] = _OPERATION_MODE;
        ucTemp[2] = ((ucResult & ~(_BIT7)) | (_PWM_NORMAL << 7));

#if(_SPI_SUPPORT == _ON)
        //SPI_WRITE(3, ucTemp);
        ScalerSpiData(_WRITE, 3, ucTemp);
#endif
    }
    else
    {
        ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;
        ucTemp[1] = _REG_ADDRESS_OPERATION_MODE;
        ucTemp[2] = ((ucResult & ~(_BIT7)) | (_PWM_OFF << 7));

#if(_SPI_SUPPORT == _ON)
        //SPI_WRITE(3, ucTemp);
        ScalerSpiData(_WRITE, 3, ucTemp);
#endif
    }
}

//--------------------------------------------------
// Description  : Set Led Driver Pwm Frequency
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void DeviceInterfaceLedDriverPwmFrequency(WORD usFrequency)
{
    usFrequency = usFrequency;
}

//--------------------------------------------------
// Description  : Set Led Driver Pwm Frequency
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void DeviceInterfaceLedDriverPwm(EnumDeviceLedDriverPwm enumDeviceLedDriverPwm, WORD usValue)
{
    BYTE i = 0;
    BYTE ucTemp[2 + ((_PANEL_PWM_LOCAL_END - _PANEL_PWM_LOCAL_START + 1) * 2)] = {0};
    BYTE ucLength = 0;

    if(enumDeviceLedDriverPwm == _PANEL_PWM_LOCAL_ALL)
    {
        ucLength = (_PANEL_PWM_LOCAL_END - _PANEL_PWM_LOCAL_START + 1);
        enumDeviceLedDriverPwm = _PANEL_PWM_LOCAL_START;
    }
    else
    {
        ucLength = 1;
    }

    ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;

    ucTemp[1] = ((enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_1) ? _REG_ADDRESS_PWM1_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_2) ? _REG_ADDRESS_PWM2_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_3) ? _REG_ADDRESS_PWM3_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_4) ? _REG_ADDRESS_PWM4_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_5) ? _REG_ADDRESS_PWM5_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_6) ? _REG_ADDRESS_PWM6_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_7) ? _REG_ADDRESS_PWM7_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_8) ? _REG_ADDRESS_PWM8_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_9) ? _REG_ADDRESS_PWM9_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_10) ? _REG_ADDRESS_PWM10_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_11) ? _REG_ADDRESS_PWM11_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_12) ? _REG_ADDRESS_PWM12_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_13) ? _REG_ADDRESS_PWM13_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_14) ? _REG_ADDRESS_PWM14_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_15) ? _REG_ADDRESS_PWM15_PLUS_WIDTH_LSB :
                 (enumDeviceLedDriverPwm == _DEVICE_LED_DRIVER_PWM_16) ? _REG_ADDRESS_PWM16_PLUS_WIDTH_LSB : _REG_ADDRESS_PWM1_PLUS_WIDTH_LSB);

    usValue = ((usValue > _PANEL_PWM_MAX) ? _PANEL_PWM_MAX :
              ((usValue < _PANEL_PWM_MIN) ? _PANEL_PWM_MIN : usValue));

    for(i = 0; i < ucLength; i++)
    {
        ucTemp[2 + (i * 2)] = (usValue & 0x00FF);
        ucTemp[3 + (i * 2)] = ((usValue & 0x1F00) >> 8);
    }

    ucLength = 2 + (ucLength * 2);

#if(_SPI_SUPPORT == _ON)
    //SPI_WRITE(ucLength, ucTemp);
    ScalerSpiData(_WRITE, ucLength, ucTemp);
#endif
}

//--------------------------------------------------
// Description  : Set Led Driver Pwm Frequency
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void UserInterfaceLedDriverPwmArray(WORD *pusValue)
{
    BYTE i = 0;
    BYTE j = 0;

    BYTE ucTemp[2 + ((_PANEL_PWM_LOCAL_END - _PANEL_PWM_LOCAL_START + 1) * 2)] = {0};
    BYTE ucLength = (_PANEL_PWM_LOCAL_END - _PANEL_PWM_LOCAL_START + 1);

    BYTE code tPAANEL_LOCAL_PWM_TYPE[]  = { _PANEL_PWM_LOCAL_1,  _PANEL_PWM_LOCAL_2,  _PANEL_PWM_LOCAL_3,  _PANEL_PWM_LOCAL_4,
                                            _PANEL_PWM_LOCAL_5,  _PANEL_PWM_LOCAL_6,  _PANEL_PWM_LOCAL_7,  _PANEL_PWM_LOCAL_8,
                                            _PANEL_PWM_LOCAL_9,  _PANEL_PWM_LOCAL_10, _PANEL_PWM_LOCAL_11, _PANEL_PWM_LOCAL_12,
                                            _PANEL_PWM_LOCAL_13, _PANEL_PWM_LOCAL_14, _PANEL_PWM_LOCAL_15, _PANEL_PWM_LOCAL_16,
                                          };

    ucTemp[0] = _DEVICE_LED_DRIVER_WRITE_SLAVE_ADDRESS;

    ucTemp[1] = ((_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_1) ? _REG_ADDRESS_PWM1_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_2) ? _REG_ADDRESS_PWM2_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_3) ? _REG_ADDRESS_PWM3_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_4) ? _REG_ADDRESS_PWM4_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_5) ? _REG_ADDRESS_PWM5_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_6) ? _REG_ADDRESS_PWM6_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_7) ? _REG_ADDRESS_PWM7_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_8) ? _REG_ADDRESS_PWM8_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_9) ? _REG_ADDRESS_PWM9_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_10) ? _REG_ADDRESS_PWM10_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_11) ? _REG_ADDRESS_PWM11_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_12) ? _REG_ADDRESS_PWM12_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_13) ? _REG_ADDRESS_PWM13_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_14) ? _REG_ADDRESS_PWM14_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_15) ? _REG_ADDRESS_PWM15_PLUS_WIDTH_LSB :
                 (_PANEL_PWM_LOCAL_START == _DEVICE_LED_DRIVER_PWM_16) ? _REG_ADDRESS_PWM16_PLUS_WIDTH_LSB : _REG_ADDRESS_PWM1_PLUS_WIDTH_LSB);


    for(i = 0; i < ucLength; i++)
    {
        PDATA_DWORD(0) = 0;

        for(j = 0; j < sizeof(tPAANEL_LOCAL_PWM_TYPE); j++)
        {
            if((_PANEL_PWM_LOCAL_START + i) == tPAANEL_LOCAL_PWM_TYPE[j])
            {
                PDATA_DWORD(0) = ((*(pusValue + j) > _PANEL_PWM_MAX) ? _PANEL_PWM_MAX :
                                  ((*(pusValue + j) < _PANEL_PWM_MIN) ? _PANEL_PWM_MIN : *(pusValue + j)));
                break;
            }
        }

        ucTemp[2 + (i * 2)] = (PDATA_DWORD(0) & 0x00FF);
        ucTemp[3 + (i * 2)] = ((PDATA_DWORD(0) & 0x1F00) >> 8);
    }

    ucLength = 2 + (ucLength * 2);

#if(_SPI_SUPPORT == _ON)
    ScalerSpiSPIDataCeForceLow(_WRITE, ucLength, ucTemp);
#endif
}

//--------------------------------------------------
// Description  : Set Led Driver Pwm Frequency
// Input Value  : None
// Output Value : None
//--------------------------------------------------
WORD UserInterfaceLedDriverPWMSmoothLevel(void)
{
    WORD usPWMSmoothLevel;
    usPWMSmoothLevel = _PWM_SMOOTH_MIN - ((_PWM_SMOOTH_MIN - _PWM_SMOOTH_MAX) / _PWM_SMOOTH_SECTION) * GET_OSD_LD_ADJ();
    return usPWMSmoothLevel;
}
#endif
#endif

#endif // End of #if(_OSD_TYPE == _REALTEK_2014_OSD)

