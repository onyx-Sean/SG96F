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
// ID Code      : RL6193_Series_MHLRx2.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Macros of MHL Adopter ID
//--------------------------------------------------
#define GET_MHL_RX2_ADOPTER_ID_DONE()            (g_bMHLRx2AdopterIDDone)
#define SET_MHL_RX2_ADOPTER_ID_DONE()            (g_bMHLRx2AdopterIDDone = _TRUE)
#define CLR_MHL_RX2_ADOPTER_ID_DONE()            (g_bMHLRx2AdopterIDDone = _FALSE)

#define GET_MHL_RX2_CBUS_RESET_FOR_HTC_DONE()    (g_bMHLRx2CbusResetForHTCDone)
#define SET_MHL_RX2_CBUS_RESET_FOR_HTC_DONE()    (g_bMHLRx2CbusResetForHTCDone = _TRUE)
#define CLR_MHL_RX2_CBUS_RESET_FOR_HTC_DONE()    (g_bMHLRx2CbusResetForHTCDone = _FALSE)

#define GET_MHL_RX2_SENT_MSC_DCAP_RDY()          (g_bMHLRx2SentMscDcapRdy)
#define SET_MHL_RX2_SENT_MSC_DCAP_RDY()          (g_bMHLRx2SentMscDcapRdy = _TRUE)
#define CLR_MHL_RX2_SENT_MSC_DCAP_RDY()          (g_bMHLRx2SentMscDcapRdy = _FALSE)

#define GET_MHL_RX2_MHL_VERSION()                (g_ucMHLRx2MhlVersion)
#define SET_MHL_RX2_MHL_VERSION(x)               (g_ucMHLRx2MhlVersion = (x))
#define CLR_MHL_RX2_MHL_VERSION()                (g_ucMHLRx2MhlVersion = 0x00)

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// CODE TABLES
//****************************************************************************


//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************
BYTE g_ucMHLRx2AdopterIDH = 0xFF;
BYTE g_ucMHLRx2AdopterIDL = 0xFF;
bit g_bMHLRx2AdopterIDDone = _FALSE;
bit g_bMHLRx2CbusResetForHTCDone = _FALSE;
bit g_bMHLRx2SentMscDcapRdy = _FALSE;
StructMHLProcessInfo g_stMHLRx2Process;
BYTE g_ucMHLRx2MhlVersion;

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void ScalerMHLRx2ModeMHLSetting(void);
void ScalerMHLRx2ModeHdmiSetting(void);
void ScalerMHLRx2InitialSettings(void);
void ScalerMHLRx2CBUSPhySwitch(bit bSelect);
void ScalerMHLRx2CBUSSwitchClk(EnumClkSel enumClockSel);
void ScalerMHLRx2CBUSResetProc(void);
void ScalerMHLRx2PowerOffProc(void);
bit ScalerMHLRx2DetectClkMode(void);
BYTE ScalerMHLRx2DetectClkMode_EXINT0(void);
void ScalerMHLRx2IntHandler_EXINT0(void);
bit ScalerMHLRx2MscSendCommand(EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue);
bit ScalerMHLRx2MscSendWriteBurst(BYTE ucOffset, BYTE ucDataLength, BYTE *pucData, EnumMHLWriteBurstMode enumMode);
bit ScalerMHLRx2MscReadDevCapabilities(EnumMHLMscOffset enumMSCOffset, BYTE *pucData);
BYTE ScalerMHLRx2MscFIFOSendCommand(EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue, BYTE ucDataLength, BYTE *pucData);
void ScalerMHLRx2MscCheckDeviceINT(void);
bit ScalerMHLRx2MscHandler(BYTE ucActivePort, BYTE ucModeState);
bit ScalerMHLRx2MscRAPHandler(void);

#if(_MHL_UCP_SUPPORT == _ON)
BYTE ScalerMHLRx2MscUCPGetCommand(BYTE *pucKeyCode);
#endif

bit ScalerMHLRx2PSPreDetect(void);
bit ScalerMHLRx2NormalPreDetect(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : TMDS Settings when MHL Mode for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2ModeMHLSetting(void)
{
    CLR_DIGITAL_PORT_SWITCH_TO_D2();

    // Clear CBUS Reset Flag for HTC Butterfly Debug
    CLR_MHL_RX2_CBUS_RESET_FOR_HTC_DONE();

    // Clear CBUS Reset Flag for Other Port Discovery Done
    CLR_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE();

    PCB_D2_HDMI_MHL_SWITCH(_TMDS_SWITCH_MHL_CBUS);
    PCB_D2_MHL_VBUS_SWITCH(_MHL_VBUS_ON);

    // Port 2 Z0 Disable
    ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Disable Auto K-offset Auto Mode
    ScalerSetBit(PB1_AD_CDR_04, ~_BIT2, 0x00);

    // Enable MHL Mode
    ScalerSetBit(PB1_A0_CMU_00, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

    // [7] PSM = 1'b0 --> Disable TMDS Lane3 Clock Switch
    ScalerSetBit(PB1_AB_CDR_02, ~_BIT7, 0x00);

#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
    // GPIO Select to CBUS
    ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT2, 0x00);

#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
    // GPIO Select to CBUS
    ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT3, 0x00);

#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
    // GPIO Select to CBUS
    ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT2, 0x00);

#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
    // GPIO Select to CBUS
    ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT3, 0x00);

#endif // End of #if(_D2_CBUS_CHANNEL_SEL == _CBUS0)

#if(_D2_DDC_CHANNEL_SEL == _DDC0)
    // Disable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_GPIO);

    // Switch DDCRAM To MHL EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT0;

    // DDC0 Disable Force Nack and disable DDC Toggle IRQ
    MCU_FFE4_DDC0_EDID_IRQ &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D2_DDC_CHANNEL_SEL == _DDC1)
    // Disable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_GPIO);

    // Switch DDCRAM To MHL EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT1;

    // DDC1 Disable Force Nack and disable DDC Toggle IRQ
    MCU_FFE5_DDC1_EDID_IRQ &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D2_DDC_CHANNEL_SEL == _DDC2)
    // Disable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_GPIO);

    // Switch DDCRAM To MHL EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT2;

    // DDC2 Disable Force Nack and disable DDC Toggle IRQ
    MCU_FE69_DDC2_EDID_IRQ &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D2_DDC_CHANNEL_SEL == _DDC3)
    // Disable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_GPIO);

    // Switch DDCRAM To MHL EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT3;

    // DDC3 Disable Force Nack and disable DDC Toggle IRQ
    MCU_FE72_DDC3_EDID_IRQ &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D2_DDC_CHANNEL_SEL == _DDC4)
    // Disable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_GPIO);

    // Switch DDCRAM To MHL EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT4;

    // DDC4 Disable Force Nack and disable DDC Toggle IRQ
    MCU_FE7B_DDC4_EDID_IRQ &= ~(_BIT5 | _BIT3 | _BIT1);
#elif(_D2_DDC_CHANNEL_SEL == _DDC5)
    // Disable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_GPIO);

    // Switch DDCRAM To MHL EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS |= _BIT5;

    // DDC5 Disable Force Nack and disable DDC Toggle IRQ
    MCU_FE84_DDC5_EDID_IRQ &= ~(_BIT5 | _BIT3 | _BIT1);
#endif
}

//--------------------------------------------------
// Description  : TMDS Settings when HDMI Mode for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2ModeHdmiSetting(void)
{
    ScalerMHLRx2CBUSPhySwitch(_OFF);

    PCB_D2_HDMI_MHL_SWITCH(_TMDS_SWITCH_HDMI_HPD);
    PCB_D2_MHL_VBUS_SWITCH(_MHL_VBUS_OFF);

    // Disable MHL Mode
    ScalerSetBit(PB1_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

    // [7] PSM = 1 --> Enable TMDS Lane3 Clock Switch
    ScalerSetBit(PB1_AB_CDR_02, ~_BIT7, _BIT7);

#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
    // GPIO Select to Hot Plug
    ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT2, _BIT2);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
    // GPIO Select to Hot Plug
    ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT3, _BIT3);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
    // GPIO Select to Hot Plug
    ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT2, _BIT2);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
    // GPIO Select to Hot Plug
    ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT3, _BIT3);
#endif  // End of #if(_D2_CBUS_CHANNEL_SEL == _CBUS0)

#if(_D2_DDC_CHANNEL_SEL == _DDC0)
    // Enable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC0_SWITCH_DDC);

    // Switch DDCRAM To HDMI EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT0;

#if(_D2_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
    // DDC0 Enable Force Nack
    MCU_FFE4_DDC0_EDID_IRQ |= _BIT5;
#endif

#elif(_D2_DDC_CHANNEL_SEL == _DDC1)
    // Enable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC1_SWITCH_DDC);

    // Switch DDCRAM To HDMI EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT1;

#if(_D2_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
    // DDC1 Enable Force Nack
    MCU_FFE5_DDC1_EDID_IRQ |= _BIT5;
#endif

#elif(_D2_DDC_CHANNEL_SEL == _DDC2)
    // Enable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC2_SWITCH_DDC);

    // Switch DDCRAM To HDMI EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT2;

#if(_D2_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
    // DDC2 Enable Force Nack
    MCU_FE69_DDC2_EDID_IRQ |= _BIT5;
#endif

#elif(_D2_DDC_CHANNEL_SEL == _DDC3)
    // Enable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC3_SWITCH_DDC);

    // Switch DDCRAM To HDMI EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT3;

#if(_D2_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
    // DDC3 Enable Force Nack
    MCU_FE72_DDC3_EDID_IRQ |= _BIT5;
#endif

#elif(_D2_DDC_CHANNEL_SEL == _DDC4)
    // Enable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC4_SWITCH_DDC);

    // Switch DDCRAM To HDMI EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT4;

#if(_D2_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
    // DDC4 Enable Force Nack
    MCU_FE7B_DDC4_EDID_IRQ |= _BIT5;
#endif

#elif(_D2_DDC_CHANNEL_SEL == _DDC5)
    // Enable DDC Channel
    ScalerPinshareGpioDdcPinSwitch(_DDC5_SWITCH_DDC);

    // Switch DDCRAM To HDMI EDID
    MCU_FEB1_DDCRAM_ST_ADDRESS &= ~_BIT5;

#if(_D2_EMBEDDED_DDCRAM_SIZE == _EDID_SIZE_NONE)
    // DDC5 Enable Force Nack
    MCU_FE84_DDC5_EDID_IRQ |= _BIT5;
#endif

#endif // End of #if(_D2_DDC_CHANNEL_SEL == _DDC0)

}

//--------------------------------------------------
// Description  : Calibration for 1K/100K and LDO Level Adjust
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2InitialSettings(void)
{
#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
    // Adjust CBUS Input Comparator VIH = 0.9V and VIL = 0.7V
    ScalerSetByte(P27_A6_CBUS_INPUT_CONTROL, 0x09);

    // Set CBUS Min Vih
    ScalerSetBit(P27_A6_CBUS_INPUT_CONTROL, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

#if(_MHL_CBUS_LDO_HIGH == _ENABLE)
    // Set CBUS Max Driving Strength, Set LDO to 1.8V Level
    ScalerSetBit(P27_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2));
#else
    // Set CBUS Max Driving Strength, Set LDO to 1.65V Level
    ScalerSetBit(P27_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));
#endif

    // DDC2 CBUS Swap Settings
    ScalerSetBit(P6F_04_CBUS0_MAP_DDC, ~(_BIT2 | _BIT1 | _BIT0), 0x02);

#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
    // Adjust CBUS Input Comparator VIH = 0.9V and VIL = 0.7V
    ScalerSetByte(P27_A6_CBUS_INPUT_CONTROL, 0x09);

    // Set CBUS Min Vih
    ScalerSetBit(P27_A6_CBUS_INPUT_CONTROL, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

#if(_MHL_CBUS_LDO_HIGH == _ENABLE)
    // Set CBUS Max Driving Strength, Set LDO to 1.8V Level
    ScalerSetBit(P27_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2));
#else
    // Set CBUS Max Driving Strength, Set LDO to 1.65V Level
    ScalerSetBit(P27_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));
#endif

    // DDC2 CBUS Swap Settings
    ScalerSetBit(P6F_05_CBUS1_MAP_DDC, ~(_BIT2 | _BIT1 | _BIT0), 0x02);

#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
    // Adjust CBUS Input Comparator VIH = 0.9V and VIL = 0.7V
    ScalerSetByte(P67_A6_CBUS_INPUT_CONTROL, 0x09);

    // Set CBUS Min Vih
    ScalerSetBit(P67_A6_CBUS_INPUT_CONTROL, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

#if(_MHL_CBUS_LDO_HIGH == _ENABLE)
    // Set CBUS Max Driving Strength, Set LDO to 1.8V Level
    ScalerSetBit(P67_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2));
#else
    // Set CBUS Max Driving Strength, Set LDO to 1.65V Level
    ScalerSetBit(P67_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));
#endif

    // DDC2 CBUS Swap Settings
    ScalerSetBit(P6F_06_CBUS2_MAP_DDC, ~(_BIT2 | _BIT1 | _BIT0), 0x02);

#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
    // Adjust CBUS Input Comparator VIH = 0.9V and VIL = 0.7V
    ScalerSetByte(P67_A6_CBUS_INPUT_CONTROL, 0x09);

    // Set CBUS Min Vih
    ScalerSetBit(P67_A6_CBUS_INPUT_CONTROL, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));

#if(_MHL_CBUS_LDO_HIGH == _ENABLE)
    // Set CBUS Max Driving Strength, Set LDO to 1.8V Level
    ScalerSetBit(P67_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT2));
#else
    // Set CBUS Max Driving Strength, Set LDO to 1.65V Level
    ScalerSetBit(P67_A7_CBUS_OUTPUT_CONTROL_0, ~(_BIT5 | _BIT4 | _BIT2 | _BIT1 | _BIT0), (_BIT5 | _BIT4 | _BIT0));
#endif

    // DDC2 CBUS Swap Settings
    ScalerSetBit(P6F_07_CBUS3_MAP_DDC, ~(_BIT2 | _BIT1 | _BIT0), 0x02);

#endif

    // Discovery Function Power Down and System Clk Gated
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT6 | _BIT5 | _BIT3 | _BIT2), _BIT6);

    // Set MHL 1MHz Clk Divider
    ScalerSetBit(P2A_A1_CBUS_CTRL_01, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT3 | _BIT2));

    // Set MHL 1KHz Clk Divider and Set Stuck Low Time to 150us
    ScalerSetBit(P2A_A2_CBUS_CTRL_02, ~(_BIT4 | _BIT3 | _BIT1 | _BIT0), _BIT0);
    ScalerSetByte(P2A_A3_CBUS_CTRL_03, 0xE2);

    // Set HW Bypass Wake Up Pulses Mode
    ScalerSetBit(P2A_A4_CBUS_CTRL_04, ~_BIT7, _BIT7);

    // Set MHL Wake pulse boundary 14~26
    ScalerSetBit(P2A_A4_CBUS_CTRL_04, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT4 | _BIT3));

    // Set Discovery Upper/Lower Bound
    ScalerSetBit(P2A_A5_CBUS_CTRL_05, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), 0x5A);

    // Set Wake Up Pulse Number to 4
    ScalerSetBit(P2A_A6_CBUS_CTRL_06, ~(_BIT7 | _BIT6 | _BIT5), _BIT7);

    // Set CBUS (PHY) Power Saving Mode to Manual Mode
    ScalerSetByte(P2A_A9_CBUS_CTRL_09, 0x00);

    ScalerMHLRx2SetTimingRelateSetting();
}

//--------------------------------------------------
// Description  : Power Process for CBUS Phy for D2 Port
// Input Value  : bSelect --> _ON/_OFF
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2CBUSPhySwitch(bit bSelect)
{
    if(bSelect == _ON)
    {
        if(ScalerGetBit(P2A_A8_CBUS_CTRL_08, _BIT5) == 0x00)
        {
#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
            // GPIO Select to CBUS
            ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT2, 0x00);

            // Enable CBUS Phy, LDO, Input Comparator and Output Driver
            ScalerSetBit(P27_A0_CBUS_EN_0, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), (_BIT6 | _BIT4 | _BIT2 | _BIT0));
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
            // GPIO Select to CBUS
            ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT3, 0x00);

            // Enable CBUS Phy, LDO and Input Comparator
            ScalerSetBit(P27_A0_CBUS_EN_0, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), (_BIT7 | _BIT5 | _BIT3 | _BIT1));
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
            // GPIO Select to CBUS
            ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT2, 0x00);

            // Enable CBUS Phy, LDO, Input Comparator and Output Driver
            ScalerSetBit(P67_A0_CBUS_EN_0, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), (_BIT6 | _BIT4 | _BIT2 | _BIT0));
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
            // GPIO Select to CBUS
            ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT3, 0x00);

            // Enable CBUS Phy, LDO and Input Comparator
            ScalerSetBit(P67_A0_CBUS_EN_0, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), (_BIT7 | _BIT5 | _BIT3 | _BIT1));
#endif
            // Discovery Function Power On and Enable System Clk
            ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT6 | _BIT5), _BIT5);

            // Enable Discovery IRQ
            ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT2 | _BIT0), (_BIT2 | _BIT0));

            // MHL Attached
            ScalerSetBit(P2A_A8_CBUS_CTRL_08, ~_BIT5, _BIT5);

            // Internal IRQ Enable (Global)
            ScalerGlobalIRQControl(_ENABLE);

            EX0 = 1;
        }
    }
    else
    {
        if(ScalerGetBit(P2A_A8_CBUS_CTRL_08, _BIT5) == _BIT5)
        {
#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
            // Disable CBUS Phy, LDO, Input Comparator
            ScalerSetBit(P27_A0_CBUS_EN_0, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), 0x00);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
            // Disable CBUS Phy, LDO, Input Comparator
            ScalerSetBit(P27_A0_CBUS_EN_0, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), 0x00);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
            // Disable CBUS Phy, LDO, Input Comparator
            ScalerSetBit(P67_A0_CBUS_EN_0, ~(_BIT6 | _BIT4 | _BIT2 | _BIT0), 0x00);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
            // Disable CBUS Phy, LDO, Input Comparator
            ScalerSetBit(P67_A0_CBUS_EN_0, ~(_BIT7 | _BIT5 | _BIT3 | _BIT1), 0x00);
#endif
            // Discovery Function Power Down and System Clk Gated
            ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Discovery IRQ
            ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT2 | _BIT0), _BIT2);

            // MHL Unattached
            ScalerSetBit(P2A_A8_CBUS_CTRL_08, ~_BIT5, 0x00);
        }
    }
}

//--------------------------------------------------
// Description  : Clock Select For MHL for D2 Port
// Input Value  : ucClockSel --> System refernce clock select.
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2CBUSSwitchClk(EnumClkSel enumClockSel)
{
    if((enumClockSel == _M2PLL_CLK) && (ScalerGetBit(P2A_A0_CBUS_CTRL_00, _BIT4) != 0x00))
    {
        // Gate CBUS System Clk First (In Case of Digital Clk Glitch)
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT5, 0x00);

        // MHL System Clk select to M2PLL
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT4 | _BIT3 | _BIT2), 0x00);

        // Clear Wake Up Pulses Flag
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT3, _BIT3);

        // Sys Clk Divider
        ScalerSetBit(P2A_A1_CBUS_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), (_BIT6 | _BIT5));

        // Set Debounce For Core Function Set to 2 cycles
        ScalerSetBit(P2A_A2_CBUS_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), _BIT6);

        // Upper Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P2A_AF_CBUS_CTRL_0F, 0xE1);

        // Lower Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P2A_B0_CBUS_CTRL_10, 0x83);

        // Upper Bound of SYNC Pulse High Time Period
        ScalerSetByte(P2A_B1_CBUS_CTRL_11, 0x55);

        // Lower Bound of SYNC Pulse High Time Period
        ScalerSetByte(P2A_B2_CBUS_CTRL_12, 0x25);

        // Absolute Threshold Time
        ScalerSetByte(P2A_B4_CBUS_CTRL_14, 0x5A);

        // Parity Bit Time
        ScalerSetByte(P2A_B5_CBUS_CTRL_15, 0x75);

        // Parity Error Limit
        ScalerSetBit(P2A_B6_CBUS_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0E);

        // Ack Bit Initial Falling Edge
        ScalerSetBit(P2A_B7_CBUS_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x04);

        // Ack Bit Drive Low Time
        ScalerSetBit(P2A_B8_CBUS_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x3A);

        // Requester Bit Time
        ScalerSetByte(P2A_BA_CBUS_CTRL_1A, 0x75);

        // Check Received Ack Bit's Falling Edge
        ScalerSetBit(P2A_BC_CBUS_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x7A);

        // Check Received Ack Bit's Driving Low Period Upper Bound
        ScalerSetBit(P2A_BD_CBUS_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x4C);

        // Check Received Ack Bit's Driving Low Period Lower Bound
        ScalerSetBit(P2A_BE_CBUS_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x24);

        // Actively Driving High Time for CBUS
        ScalerSetBit(P2A_C0_CBUS_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x18);

        // CBUS Requester Transmit Opportunity after Arbitration
        ScalerSetByte(P2A_C2_CBUS_CTRL_22, 0x75);

        // CBUS Requester Continue After Ack
        ScalerSetByte(P2A_C3_CBUS_CTRL_23, 0x3A);

        // Link Layer Timeout
        ScalerSetBit(P2A_C5_CBUS_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT4 | _BIT3 | _BIT2));

        // Set IIC SCL Clock Frequency
        ScalerSetByte(P2A_F9_CBUS_CTRL_59, 0x11);

        // Reset CBUS Core Function After Clk Switch
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT7, _BIT7);
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT7, 0x00);

        // Enable CBUS System Clk
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT5, _BIT5);
    }
    else if((enumClockSel == _IOSC_CLK) && (ScalerGetBit(P2A_A0_CBUS_CTRL_00, _BIT4) != _BIT4))
    {
        // Gate CBUS System Clk First (In Case of Digital Clk Glitch)
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT5, 0x00);

        // MHL System Clk select to IOSC (Bypass GDI Clk)
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT4 | _BIT3 | _BIT2), _BIT4);
        ScalerSetBit(P2A_A2_CBUS_CTRL_02, ~_BIT2, 0x00);

        // Clear Wake Up Pulses Flag
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT3, _BIT3);

        // Sys Clk Divider
        ScalerSetBit(P2A_A1_CBUS_CTRL_01, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // Disable Debounce For Core Function
        ScalerSetBit(P2A_A2_CBUS_CTRL_02, ~(_BIT7 | _BIT6 | _BIT5), 0x00);

        // Upper Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P2A_AF_CBUS_CTRL_0F, 0x35);

        // Lower Bound of SYNC Pulse Low Time Period
        ScalerSetByte(P2A_B0_CBUS_CTRL_10, 0x20);

        // Upper Bound of SYNC Pulse High Time Period
        ScalerSetByte(P2A_B1_CBUS_CTRL_11, 0x14);

        // Lower Bound of SYNC Pulse High Time Period
        ScalerSetByte(P2A_B2_CBUS_CTRL_12, 0x09);

        // Absolute Threshold Time
        ScalerSetByte(P2A_B4_CBUS_CTRL_14, 0x15);

        // Parity Bit Time
        ScalerSetByte(P2A_B5_CBUS_CTRL_15, 0x1C);

        // Parity Error Limit
        ScalerSetBit(P2A_B6_CBUS_CTRL_16, ~(_BIT7 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT2);

        // Ack Bit Initial Falling Edge
        ScalerSetBit(P2A_B7_CBUS_CTRL_17, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x01);

        // Ack Bit Drive Low Time
        ScalerSetBit(P2A_B8_CBUS_CTRL_18, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x0D);

        // Requester Bit Time
        ScalerSetByte(P2A_BA_CBUS_CTRL_1A, 0x1C);

        // Check Received Ack Bit's Falling Edge
        ScalerSetBit(P2A_BC_CBUS_CTRL_1C, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x1C);

        // Check Received Ack Bit's Driving Low Period Upper Bound
        ScalerSetBit(P2A_BD_CBUS_CTRL_1D, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x12);

        // Check Received Ack Bit's Driving Low Period Lower Bound
        ScalerSetBit(P2A_BE_CBUS_CTRL_1E, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), 0x05);

        // Actively Driving High Time for CBUS
        ScalerSetBit(P2A_C0_CBUS_CTRL_20, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));

        // CBUS Requester Transmit Opportunity after Arbitration
        ScalerSetByte(P2A_C2_CBUS_CTRL_22, 0x1C);

        // CBUS Requester Continue After Ack
        ScalerSetByte(P2A_C3_CBUS_CTRL_23, 0x0D);

        // Link Layer Timeout
        ScalerSetBit(P2A_C5_CBUS_CTRL_25, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

        // Set IIC SCL Clock Frequency
        ScalerSetByte(P2A_F9_CBUS_CTRL_59, 0x03);

        // Reset CBUS Core Function After Clk Switch
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT7, _BIT7);
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT7, 0x00);

        // Enable CBUS System Clk
        ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~_BIT5, _BIT5);
    }
}

//--------------------------------------------------
// Description  : MHL Cbus Reset Proc for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2CBUSResetProc(void)
{
    // Disable Stuck Low IRQ and Clear Stuck Low Flags
    ScalerSetBit(P2A_A4_CBUS_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);

    // Port 2 Z0 Disable
    ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

    // Disable Auto K-offset Auto Mode
    ScalerSetBit(PB1_AD_CDR_04, ~_BIT2, 0x00);

    // Manual Enable CBUS PHY PSM
#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
    ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT0, _BIT0);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
    ScalerSetBit(P27_A1_CBUS_EN_1, ~_BIT1, _BIT1);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
    ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT0, _BIT0);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
    ScalerSetBit(P67_A1_CBUS_EN_1, ~_BIT1, _BIT1);
#endif  // End of #if(_D2_CBUS_CHANNEL_SEL == _CBUS0)

    // Force CBUS Floating
    ScalerSetBit(P2A_A8_CBUS_CTRL_08, ~_BIT7, _BIT7);

    // Enable Discovery Debounce
    ScalerSetBit(P2A_A8_CBUS_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

    // Reset CBUS Core Function
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT7), _BIT7);
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT7), 0x00);

    SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_INITIAL);
    CLR_MHL_RX2_ADOPTER_ID_HBYTE();
    CLR_MHL_RX2_ADOPTER_ID_LBYTE();
    CLR_MHL_RX2_ADOPTER_ID_DONE();
    CLR_MHL_RX2_CBUS_RESET_FOR_HTC_DONE();
    CLR_MHL_RX2_MHL_VERSION();

    ScalerMHLRx2DataPortInitial();

    // Enable Discovery Done IRQ and Clear Flag
    ScalerSetBit(P2A_A0_CBUS_CTRL_00, ~(_BIT2 | _BIT0), (_BIT2 | _BIT0));
}

//--------------------------------------------------
// Description  : MHL Power Off Process for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2PowerOffProc(void)
{
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_RX2_READY_TO_TRANSMIT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_RX2_RECONNECT_1K);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE);
}

//--------------------------------------------------
// Description  : MHL Detect Clk Mode if 24Bit or PP Mode
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
bit ScalerMHLRx2DetectClkMode(void)
{
    WORD usTemp = 200;

    // Clear Error Flag and Start Detection
    ScalerSetBit(P76_B3_MHL_CTRL_13, ~(_BIT1 | _BIT0), _BIT0);
    ScalerSetBit(P76_A7_MHL_CTRL_07, ~_BIT0, _BIT0);

    // Wait until detection is done(1ms) or timeout(1.5ms)
    while((ScalerGetBit(P76_A7_MHL_CTRL_07, _BIT0) == _BIT0) && (--usTemp != 0))
    {
        Delay5us(g_ucDelay5usN);
    }

    if(((bit)ScalerGetBit(P76_B3_MHL_CTRL_13, _BIT0) == _TRUE) ||
       ((bit)ScalerGetBit(P76_A7_MHL_CTRL_07, _BIT7) != GET_TMDS_RX2_CLK_MODE()))
    {
        ScalerSetBit(P76_B3_MHL_CTRL_13, ~(_BIT1 | _BIT0), _BIT0);

        if(GET_TMDS_RX2_CLK_MODE() == _TMDS_24BIT_PHY_SETTING)
        {
            usTemp = 300;

            // Wait until RGB detection is done or timeout(3ms)
            while((ScalerGetBit(P71_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) != (_BIT7 | _BIT6 | _BIT5)) &&
                  (--usTemp != 0))
            {
                Delay5us(g_ucDelay5usN);
            }

            if(usTemp == 0)
            {
                return _FALSE;
            }
            else
            {
                return _TRUE;
            }
        }
        else
        {
            return _FALSE;
        }
    }
    else
    {
        return _TRUE;
    }
}

//--------------------------------------------------
// Description  : MHL Detect Clk Mode if 24Bit or PP Mode (EXINT0 Only)
// Input Value  : None
// Output Value : True or False
//--------------------------------------------------
BYTE ScalerMHLRx2DetectClkMode_EXINT0(void) using 1
{
    WORD usTemp = 200;

    // Clear Error Flag and Start Detection
    ScalerSetBit_EXINT(P76_B3_MHL_CTRL_13, ~(_BIT1 | _BIT0), _BIT0);
    ScalerSetBit_EXINT(P76_A7_MHL_CTRL_07, ~_BIT0, _BIT0);

    // Wait until detection is done(1ms) or timeout(1.5ms)
    while((ScalerGetBit_EXINT(P76_A7_MHL_CTRL_07, _BIT0) == _BIT0) && (--usTemp != 0))
    {
        Delay5us_EXINT(g_ucDelay5usN);
    }

    if(((bit)ScalerGetBit_EXINT(P76_B3_MHL_CTRL_13, _BIT0) == _TRUE) ||
       ((bit)ScalerGetBit_EXINT(P76_A7_MHL_CTRL_07, _BIT7) != GET_TMDS_RX2_CLK_MODE()))
    {
        ScalerSetBit_EXINT(P76_B3_MHL_CTRL_13, ~(_BIT1 | _BIT0), _BIT0);

        if(GET_TMDS_RX2_CLK_MODE() == _TMDS_24BIT_PHY_SETTING)
        {
            usTemp = 300;

            // Wait until RGB detection is done or timeout(3ms)
            while((ScalerGetBit_EXINT(P71_A4_TMDS_CTRL, (_BIT7 | _BIT6 | _BIT5)) != (_BIT7 | _BIT6 | _BIT5)) &&
                  (--usTemp != 0))
            {
                Delay5us_EXINT(g_ucDelay5usN);
            }

            if(usTemp == 0)
            {
                return _FALSE;
            }
            else
            {
                return _TRUE;
            }
        }
        else
        {
            return _FALSE;
        }
    }
    else
    {
        return _TRUE;
    }
}

//--------------------------------------------------
// Description  : Int Process for MHL for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2IntHandler_EXINT0(void) using 1
{
    // Check Discovery Pulse
    if(ScalerGetBit_EXINT(P2A_A0_CBUS_CTRL_00, (_BIT2 | _BIT0)) == (_BIT2 | _BIT0))
    {
        // Disable Discovery Done IRQ and Clear Discovery Flags
        ScalerSetBit_EXINT(P2A_A0_CBUS_CTRL_00, ~(_BIT2 | _BIT0), (_BIT2));

        // Disable Discovery Debounce
        ScalerSetBit_EXINT(P2A_A8_CBUS_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

        // Enable Stuck Low IRQ and Clear Flag
        ScalerSetBit_EXINT(P2A_A4_CBUS_CTRL_04, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

        if(ScalerGetBit_EXINT(PB1_A2_CMU_02, _BIT4) == 0x00)
        {
            // Suspend Key Calculation before load key
            ScalerSetBit_EXINT(P71_AE_TMDS_RPS, ~_BIT1, 0x00);
        }

        // Enable GDI BandGap
        ScalerSetBit_EXINT(PB_B4_BANDGAP_00, ~_BIT7, _BIT7);

        // Manual Disable CBUS PHY PSM
#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
        ScalerSetBit_EXINT(P27_A1_CBUS_EN_1, ~_BIT0, 0x00);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
        ScalerSetBit_EXINT(P27_A1_CBUS_EN_1, ~_BIT1, 0x00);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
        ScalerSetBit_EXINT(P67_A1_CBUS_EN_1, ~_BIT0, 0x00);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
        ScalerSetBit_EXINT(P67_A1_CBUS_EN_1, ~_BIT1, 0x00);
#endif  // End of #if(_D2_CBUS_CHANNEL_SEL == _CBUS0)

        // Enable RX_EN
        ScalerSetBit_EXINT(PB1_A1_CMU_01, ~_BIT7, _BIT7);

        // Port 2 Z0 Enable
        ScalerSetBit_EXINT(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));

        // Clear HDCP Flags
        ScalerSetBit_EXINT(P71_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

        SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_DISCOVERY_DONE);
        SET_MHL_RX2_READY_TO_TRANSMIT();
    }

    // Check Stuck Low Flag
    if(ScalerGetBit_EXINT(P2A_A4_CBUS_CTRL_04, (_BIT1 | _BIT0)) == (_BIT1 | _BIT0))
    {
        // Disable Stuck Low IRQ and Clear Stuck Low Flags
        ScalerSetBit_EXINT(P2A_A4_CBUS_CTRL_04, ~(_BIT1 | _BIT0), _BIT1);

        // Enable Discovery Done IRQ and Clear Flag
        ScalerSetBit_EXINT(P2A_A0_CBUS_CTRL_00, ~(_BIT2 | _BIT0), (_BIT2 | _BIT0));

        CLR_DIGITAL_PORT_SWITCH_TO_D2();

        // Port 2 Z0 Disable
        ScalerSetBit_EXINT(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

        // Disable Auto K-offset Auto Mode
        ScalerSetBit_EXINT(PB1_AD_CDR_04, ~_BIT2, 0x00);

        // Manual Enable CBUS PHY PSM
#if(_D2_CBUS_CHANNEL_SEL == _CBUS0)
        ScalerSetBit_EXINT(P27_A1_CBUS_EN_1, ~_BIT0, _BIT0);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS1)
        ScalerSetBit_EXINT(P27_A1_CBUS_EN_1, ~_BIT1, _BIT1);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS2)
        ScalerSetBit_EXINT(P67_A1_CBUS_EN_1, ~_BIT0, _BIT0);
#elif(_D2_CBUS_CHANNEL_SEL == _CBUS3)
        ScalerSetBit_EXINT(P67_A1_CBUS_EN_1, ~_BIT1, _BIT1);
#endif  // End of #if(_D2_CBUS_CHANNEL_SEL == _CBUS0)

        // Enable Discovery Debounce
        ScalerSetBit_EXINT(P2A_A8_CBUS_CTRL_08, ~(_BIT2 | _BIT1 | _BIT0), (_BIT1 | _BIT0));

#if(_MHL_CBUS_CTS_MODE == _ON)
        // Disable DDC Manual
        ScalerSetBit_EXINT(P2A_C8_CBUS_CTRL_28, ~_BIT6, 0x00);
#endif
        // Reset CBUS Core Function
        ScalerSetBit_EXINT(P2A_A0_CBUS_CTRL_00, ~(_BIT7), _BIT7);
        ScalerSetBit_EXINT(P2A_A0_CBUS_CTRL_00, ~(_BIT7), 0x00);

        SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_INITIAL);
        CLR_MHL_RX2_ADOPTER_ID_HBYTE();
        CLR_MHL_RX2_ADOPTER_ID_LBYTE();
        CLR_MHL_RX2_ADOPTER_ID_DONE();
        CLR_MHL_RX2_CBUS_RESET_FOR_HTC_DONE();
        CLR_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE();
        CLR_MHL_RX2_MHL_VERSION();

        ScalerMHLRx2DataPortInitial_EXINT0();
    }
}

//--------------------------------------------------
// Description  : Send MSC HPD Operation for D2 Port
// Input Value  : enumMSCType --> MSC Command
//                enumMSCOffset --> MSC Device Register
//                enumMSCValue --> MSC Device Register Field
// Output Value : Success or Fail
//--------------------------------------------------
bit ScalerMHLRx2MscSendCommand(EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue)
{
    BYTE ucResultPacket = 0;

    if(GET_MHL_RX2_READY_TO_TRANSMIT() == _TRUE)
    {
        ucResultPacket = ScalerMHLRx2MscFIFOSendCommand(enumMSCCommand, enumMSCOffset, enumMSCValue, 0, _NULL_POINTER);

        switch(ucResultPacket)
        {
            case _MHL_SUCCESS: // Source reply ACK Packet

                SET_MHL_RX2_READY_TO_TRANSMIT();

                return _SUCCESS;
                break;

            case _MHL_ABORT_FAIL: // Source reply ABORT Packet

                CLR_MHL_RX2_READY_TO_TRANSMIT();
                ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_RX2_READY_TO_TRANSMIT);

                return _FAIL;
                break;

            case _MHL_PROTOCOL_ERROR: // Source Reply Data Packet Instead of Control Packet

                ScalerMHLRx2MscFIFOSendCommand(_MSC_ABORT, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE, 0, _NULL_POINTER);

                return _FAIL;
                break;

            default: // Source Reply No Packet(Timeout) or NACK

                return _FAIL;
                break;
        }
    }
    else
    {
        return _FAIL;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Send Write Burst Operation for D2 Port
// Input Value  : ucDataLength --> Data Length
//                pucData --> Data
//                ucMode --> Write Burst Mode
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
bit ScalerMHLRx2MscSendWriteBurst(BYTE ucOffset, BYTE ucDataLength, BYTE *pucData, EnumMHLWriteBurstMode enumMode)
{
    BYTE ucResultPacket = 0;

    if(enumMode == _MHL_WRITE_BURST_WITH_REQ)
    {
        // Clear Grant To Write Flag
        ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT);

        // Send Request to Write
        ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT);

        // Disable Access Port Auto Increase
        ScalerSetBit(P2A_AB_CBUS_CTRL_0B, ~_BIT0, 0x00);

        // Polling Grant to Write
        ScalerSetByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT);
        ScalerTimerPollingFlagProc(100, P2A_AD_CBUS_CTRL_0D, _MSC_GRT_WRT, _TRUE);

        // Enable Access Port Auto Increase
        ScalerSetBit(P2A_AB_CBUS_CTRL_0B, ~_BIT0, _BIT0);
    }
    if(GET_MHL_RX2_READY_TO_TRANSMIT() == _TRUE)
    {
        ucResultPacket = ScalerMHLRx2MscFIFOSendCommand(_MSC_WRITE_BURST, ucOffset, 0x00, ucDataLength, pucData);

        switch(ucResultPacket)
        {
            case _MHL_SUCCESS: // Source reply ACK Packet

                // Send Device Scratchpad Change
                ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_DSCR_CHG);

                return _SUCCESS;

                break;

            case _MHL_ABORT_FAIL: // Source reply ABORT Packet

                CLR_MHL_RX2_READY_TO_TRANSMIT();
                ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_RX2_READY_TO_TRANSMIT);

                return _FAIL;
                break;

            case _MHL_PROTOCOL_ERROR: // Source Reply Data Packet Instead of Control Packet

                ScalerMHLRx2MscFIFOSendCommand(_MSC_ABORT, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE, 0, _NULL_POINTER);

                return _FAIL;
                break;

            default: // Source Reply No Packet(Timeout) or NACK

                return _FAIL;
                break;
        }
    }
    else
    {
        return _FAIL;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Read Device Capabilities for D2 Port
// Input Value  : enumMSCOffset --> Device Capability Offset
//                pucData --> Data to be Read
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
bit ScalerMHLRx2MscReadDevCapabilities(EnumMHLMscOffset enumMSCOffset, BYTE *pucData)
{
    BYTE ucResultPacket = 0;

    if(GET_MHL_RX2_READY_TO_TRANSMIT() == _TRUE)
    {
        ucResultPacket = ScalerMHLRx2MscFIFOSendCommand(_MSC_READ_DEVCAP, enumMSCOffset, _MSC_NULL_VALUE, 0, pucData);

        switch(ucResultPacket)
        {
            case _MHL_SUCCESS: // Source reply ACK Packet

                SET_MHL_RX2_READY_TO_TRANSMIT();

                return _SUCCESS;

                break;

            case _MHL_ABORT_FAIL: // Source reply ABORT Packet

                CLR_MHL_RX2_READY_TO_TRANSMIT();
                ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_RX2_READY_TO_TRANSMIT);

                return _FAIL;
                break;

            case _MHL_PROTOCOL_ERROR: // Source Reply Data Packet Instead of Control Packet

                ScalerMHLRx2MscFIFOSendCommand(_MSC_ABORT, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE, 0, _NULL_POINTER);

                return _FAIL;
                break;

            default: // Source Reply No Packet(Timeout) or NACK

                return _FAIL;
                break;
        }
    }
    else
    {
        return _FAIL;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Send MSC HPD Operation for D2 Port
// Input Value  : enumMSCType --> MSC Command
//                enumMSCOffset --> MSC Device Register
//                enumMSCValue --> MSC Device Register Field
// Output Value : Success or Different Fail Situations
//--------------------------------------------------
BYTE ScalerMHLRx2MscFIFOSendCommand(EnumMHLMscCommand enumMSCCommand, EnumMHLMscOffset enumMSCOffset, EnumMHLMscData enumMSCValue, BYTE ucDataLength, BYTE *pucData)
{
    BYTE ucTimeOut = 100;
    BYTE ucSendType = 0;
    BYTE ucWaitType = 0;
    BYTE ucI = 0;

    switch(enumMSCCommand)
    {
        case _MSC_SET_INT:
        case _MSC_MSG:

            ucSendType = _MSC_SEND_COM_OFF_DAT;
            ucWaitType = _MSC_WAIT_COMMAND;
            break;

        case _MSC_READ_DEVCAP:

            ucSendType = _MSC_SEND_COM_OFF;
            ucWaitType = _MSC_WAIT_COM_DAT;
            break;

        case _MSC_SET_HPD:

            ucSendType = _MSC_SEND_COMMAND;
            ucWaitType = _MSC_WAIT_COMMAND;
            break;

        case _MSC_ABORT:

            ucSendType = _MSC_SEND_COMMAND;
            ucWaitType = _MSC_WAIT_NULL;
            break;

        case _MSC_WRITE_BURST:

            ucSendType = _MSC_SEND_COM_OFF_DAT_COM;
            ucWaitType = _MSC_WAIT_COMMAND;
            break;

        default:

            break;
    }

    // Check If Source Has Sent An ABORT Packet
    if(ScalerGetBit(P2A_CF_CBUS_CTRL_2F, _BIT2) == _BIT2)
    {
        ScalerSetByte(P2A_CF_CBUS_CTRL_2F, _BIT2);

        ScalerTimerActiveTimerEvent(SEC(2.5), _SCALER_TIMER_EVENT_MHL_RX2_READY_TO_TRANSMIT);

        CLR_MHL_RX2_READY_TO_TRANSMIT();

        return _MHL_FAIL;
    }

    // Clear FIFO and Send Command Only
    ScalerSetByte(P2A_DE_CBUS_CTRL_3E, (_BIT6 | ucSendType));

    // Set MSC Command
    ScalerSetByte(P2A_DF_CBUS_CTRL_3F, enumMSCCommand);

    // Set MSC Offset
    ScalerSetByte(P2A_E1_CBUS_CTRL_41, enumMSCOffset);

    if(enumMSCCommand == _MSC_WRITE_BURST)
    {
        // Set MSC Last Command
        ScalerSetByte(P2A_E0_CBUS_CTRL_40, _MSC_EOF_PACKET);

        // Set MSC Data
        for(ucI = 0; ucI < ucDataLength; ucI++)
        {
            ScalerSetByte(P2A_E2_CBUS_CTRL_42, pucData[ucI]);
        }
    }
    else if(enumMSCCommand != _MSC_READ_DEVCAP)
    {
        // Set MSC Value
        ScalerSetByte(P2A_E2_CBUS_CTRL_42, enumMSCValue);
    }

    // MSC Packet and Wait Type
    ScalerSetBit(P2A_E3_CBUS_CTRL_43, ~(_BIT7 | _BIT6 | _BIT1 | _BIT0), ((_MSC_PACKET << 6) | ucWaitType));

    // Send Request
    ScalerSetBit(P2A_DE_CBUS_CTRL_3E, ~(_BIT7), _BIT7);

    // Check if Process is finished
    while(--ucTimeOut != 0)
    {
        if(ScalerGetBit(P2A_CF_CBUS_CTRL_2F, _BIT2) == _BIT2)
        {
            // Clear Flag
            ScalerSetBit(P2A_CF_CBUS_CTRL_2F, ~_BIT2, _BIT2);

            return _MHL_ABORT_FAIL;
        }
        else if((ScalerGetBit(P2A_F6_CBUS_CTRL_56, _BIT7) == _BIT7) && (ScalerGetBit(P2A_F7_CBUS_CTRL_57, _BIT7) == 0x00))
        {
            // Clear Flag
            ScalerSetBit(P2A_F6_CBUS_CTRL_56, ~_BIT7, _BIT7);

            if(ucWaitType == _MSC_WAIT_NULL)
            {
                return _MHL_SUCCESS;
            }
            else
            {
                // Check ACK Packet
                if(ScalerGetByte(P2A_E4_CBUS_CTRL_44) == _MSC_ACK_PACKET)
                {
                    if(enumMSCCommand == _MSC_READ_DEVCAP)
                    {
                        *pucData = ScalerGetByte(P2A_E5_CBUS_CTRL_45);
                    }

                    return _MHL_SUCCESS;
                }
                else
                {
                    return _MHL_FAIL;
                }
            }
        }
        else if((ScalerGetBit(P2A_F7_CBUS_CTRL_57, _BIT7) == _BIT7) && (ScalerGetByte(P2A_D2_CBUS_CTRL_32) == _MSC_PROTOCOL_ERROR))
        {
            // Clear Flags
            ScalerSetBit(P2A_F6_CBUS_CTRL_56, ~_BIT7, _BIT7);
            ScalerSetBit(P2A_F7_CBUS_CTRL_57, ~_BIT7, _BIT7);
            ScalerSetByte(P2A_D2_CBUS_CTRL_32, 0xFF);

            return _MHL_PROTOCOL_ERROR;
        }

        ScalerTimerDelayXms(1);
    }

    // Clear Flag
    ScalerSetBit(P2A_F6_CBUS_CTRL_56, ~_BIT7, _BIT7);
    ScalerSetBit(P2A_F7_CBUS_CTRL_57, ~_BIT7, _BIT7);
    ScalerSetByte(P2A_D2_CBUS_CTRL_32, 0xFF);

    return _MHL_FAIL;
}

//--------------------------------------------------
// Description  : Check Write Status for D2 Port
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerMHLRx2MscCheckDeviceINT(void)
{
    WORD usTmp = 0;
    BYTE ucBirstLength = 0;
    BYTE pucWriteBurstTmp[16];

    /********************************************************/
    /******** Get MSC Command WRITE_STAT or SET_INT *********/
    /********************************************************/

    if((bit)ScalerGetBit(P2A_CE_CBUS_CTRL_2E, _BIT7) == _TRUE)
    {
        //----------------------------------------------------------//
        //-------- Check DevCap Ready (DCAP_RDY, DCAP_CHG) ---------//
        //----------------------------------------------------------//
        if((((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _TRUE) ||
            ((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)))
        {
            if(GET_MHL_RX2_MHL_VERSION() == _MHL_VERSION_NULL)
            {
                // Read Source Device MHL Version
                if(ScalerMHLRx2MscReadDevCapabilities(_MSC_MHL_VERSION_01, &g_ucMHLRx2MhlVersion) == _TRUE)
                {
                    if((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                    {
                        // Write 1 Clear DevCap_Chg Flag
                        ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                    }

                    // Clear Flag
                    ScalerSetBit(P2A_CE_CBUS_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
                }
            }

            // Read Source Adopter ID
            if((GET_MHL_RX2_ADOPTER_ID_DONE() == _FALSE) && (GET_MHL_RX2_READY_TO_TRANSMIT() == _TRUE))
            {
                if((ScalerMHLRx2MscReadDevCapabilities(_MSC_ADOPTER_ID_H_03, &g_ucMHLRx2AdopterIDH) == _TRUE) &&
                   (ScalerMHLRx2MscReadDevCapabilities(_MSC_ADOPTER_ID_L_04, &g_ucMHLRx2AdopterIDL) == _TRUE))
                {
                    DebugMessageRx2("D2 MHL Adopter IDH", g_ucMHLRx2AdopterIDH);
                    DebugMessageRx2("D2 MHL Adopter IDL", g_ucMHLRx2AdopterIDL);

                    SET_MHL_RX2_ADOPTER_ID_DONE();

                    if((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG) == _TRUE)
                    {
                        // Write 1 Clear DevCap_Chg Flag
                        ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_DCAP_CHG);
                    }

                    // Clear Flag
                    ScalerSetBit(P2A_CE_CBUS_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT7 | _BIT6));
                }
            }
        }

        //------------------------------------//
        //------ Check Request To Write ------//
        //------------------------------------//
        if((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _TRUE)
        {
            if(ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_GRT_WRT) == _SUCCESS)
            {
                ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_REQ_WRT);
            }
        }

        //-----------------------------------------------------------//
        //-- Check 3D Request and Reply No Support For All Timings --//
        //-----------------------------------------------------------//
        if((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_3D_REQ) == _TRUE)
        {
            // 3D_VIC Header
            pucWriteBurstTmp[0] = _MHL_3D_VIC_HB;
            pucWriteBurstTmp[1] = _MHL_3D_VIC_LB;

            // Total Entries -> 0
            pucWriteBurstTmp[3] = 0x00;

            // SEQ -> 1
            pucWriteBurstTmp[4] = 0x01;

            // NUM_ENT -> 0
            pucWriteBurstTmp[5] = 0x00;

            // Checksum -> 256 - Sum{pucWriteBurstTmp[i]}
            pucWriteBurstTmp[2] = 256 - (pucWriteBurstTmp[0] + pucWriteBurstTmp[1] + pucWriteBurstTmp[3] + pucWriteBurstTmp[4] + pucWriteBurstTmp[5]);

            // 3D_DTD Header
            pucWriteBurstTmp[6] = _MHL_3D_DTD_HB;
            pucWriteBurstTmp[7] = _MHL_3D_DTD_LB;

            // Total Entries -> 0
            pucWriteBurstTmp[9] = 0x00;

            // SEQ -> 1
            pucWriteBurstTmp[10] = 0x01;

            // NUM_ENT -> 0
            pucWriteBurstTmp[11] = 0x00;

            // Checksum -> 256 - Sum{pucWriteBurstTmp[i]}
            pucWriteBurstTmp[8] = 256 - (pucWriteBurstTmp[6] + pucWriteBurstTmp[7] + pucWriteBurstTmp[9] + pucWriteBurstTmp[10] + pucWriteBurstTmp[11]);

            ucBirstLength = 6;

            if(ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _SUCCESS)
            {
                usTmp = 400;

                while((usTmp-- > 0) && ((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT) != _TRUE))
                {
                    ScalerTimerDelayXms(5);
                }

                if(ScalerMHLRx2MscSendWriteBurst(0x40, ucBirstLength, &pucWriteBurstTmp[0], _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                {
                    if(ScalerMHLRx2MscSendCommand(_MSC_SET_INT, _MSC_RCHANGE_INT, _MSC_REQ_WRT) == _SUCCESS)
                    {
                        usTmp = 400;

                        while((usTmp-- > 0) && ((bit)ScalerGetDataPortBit(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_GRT_WRT) != _TRUE))
                        {
                            ScalerTimerDelayXms(5);
                        }

                        if(ScalerMHLRx2MscSendWriteBurst(0x40, ucBirstLength, &pucWriteBurstTmp[ucBirstLength], _MHL_WRITE_BURST_WITH_REQ) == _SUCCESS)
                        {
                            ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_RCHANGE_INT, _MSC_3D_REQ);

                            // Clear Flag
                            ScalerSetBit(P2A_CE_CBUS_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT7);
                        }
                    }
                }
            }
        }

        // Clear Flag
        ScalerSetByte(P2A_CE_CBUS_CTRL_2E, (BYTE)_BIT7);
    }


    /****************************************************************/
    /******* Source Device Reading Sink Capabilities Ready **********/
    /****************************************************************/

    if((bit)ScalerGetBit(P2A_CE_CBUS_CTRL_2E, _BIT6) == _TRUE)
    {
        // Read Source Adopter ID
        if((GET_MHL_RX2_ADOPTER_ID_DONE() == _FALSE) && (GET_MHL_RX2_READY_TO_TRANSMIT() == _TRUE))
        {
            // Delay for Read Adopter ID
            ScalerTimerDelayXms(70);

            if((ScalerMHLRx2MscReadDevCapabilities(_MSC_ADOPTER_ID_H_03, &g_ucMHLRx2AdopterIDH) == _TRUE) &&
               (ScalerMHLRx2MscReadDevCapabilities(_MSC_ADOPTER_ID_L_04, &g_ucMHLRx2AdopterIDL) == _TRUE))
            {
                SET_MHL_RX2_ADOPTER_ID_DONE();

                ScalerSetBit(P2A_CE_CBUS_CTRL_2E, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT6);
            }
        }
    }

    // Sent Command to Triger VBUS for HTC M8
    if(((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _HTC_BUTTERFLY_ADOPTER_ID_LBYTE)) &&
       (GET_MHL_RX2_SENT_MSC_DCAP_RDY() == _FALSE) && (GET_MHL_RX2_PROCESS_STATE() == _MHL_STATE_SET_DEV_CAP_DONE))
    {
        ScalerMHLRx2MscSendCommand(_MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY);
        DebugMessageRx2("D2 MHL Sent Devies Capabilitly Ready", 0);
        SET_MHL_RX2_SENT_MSC_DCAP_RDY();
    }

    // MHL Version Switch to 1.2 For Samsung Note4
    if(((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE)) &&
       (GET_MHL_RX2_MHL_VERSION() >= _MHL_VERSION_3_0) && (GET_MHL_RX2_CBUS_RESET_FOR_HTC_DONE() == _FALSE))
    {
        ScalerSetDataPortByte(P2A_AC_CBUS_CTRL_0C, _MSC_MHL_VERSION_01, _MHL_VERSION_1_2);

        ScalerMHLRx2MscSendCommand(_MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY);

        SET_MHL_RX2_CBUS_RESET_FOR_HTC_DONE();
    }

#if(_MHL_CBUS_CTS_MODE == _ON)

    if(ScalerGetBit(P2A_CE_CBUS_CTRL_2E, _BIT5) == _BIT5)
    {
        ScalerSetByte(P2A_C8_CBUS_CTRL_28, _BIT6);

        ScalerSetByte(P2A_CE_CBUS_CTRL_2E, _BIT5);
    }

    if(ScalerGetBit(P2A_CE_CBUS_CTRL_2E, _BIT4) == _BIT4)
    {
        ScalerSetByte(P2A_C8_CBUS_CTRL_28, 0x00);

        ScalerSetByte(P2A_CE_CBUS_CTRL_2E, _BIT4);
    }

#endif // Enf of #if(_MHL_CBUS_CTS_MODE == _ON)
}

//--------------------------------------------------
// Description  : MSC Handler for D2 Port
// Input Value  : ucActivePort --> Current Active Port
//                ucModeState --> Current Mode State
// Output Value : True or False
//--------------------------------------------------
bit ScalerMHLRx2MscHandler(BYTE ucActivePort, BYTE ucModeState)
{
    // Check if Discovery State is done and send HPD & Device Capabilities Ready
    switch(GET_MHL_RX2_PROCESS_STATE())
    {
        case _MHL_STATE_INITIAL:

            ScalerTimerActiveTimerEvent(SEC(5), _SCALER_TIMER_EVENT_MHL_RX2_RECONNECT_1K);

            return _FALSE;
            break;

        case _MHL_STATE_DISCOVERY_DONE:

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_RX2_RECONNECT_1K);

            ScalerMHLRx2SetDevCapReg();

            if(ScalerMHLRx2MscSendCommand(_MSC_WRITE_STAT, _MSC_CONNECTED_RDY, _MSC_DCAP_RDY) == _SUCCESS)
            {
                ScalerTimerActiveTimerEvent(SEC(1), _SCALER_TIMER_EVENT_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE);

                DebugMessageDigital("D2 MHL Dev Cap RDY", 0x01);
                SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_DEV_CAP_RDY);
            }

            break;

        default:
            break;
    }

    // Send HPD, PATH_EN and Device Capabilities Ready For Source
    if((ucActivePort == _D2_INPUT_PORT) && (ucModeState != _MODE_STATUS_INITIAL) && (ucModeState != _MODE_STATUS_POWER_OFF))
    {
        switch(GET_MHL_RX2_PROCESS_STATE())
        {
            case _MHL_STATE_DEV_CAP_RDY:

                ScalerTimerDelayXms(150);

                if(ScalerMHLRx2MscSendCommand(_MSC_SET_HPD, _MSC_NULL_ADDRESS, _MSC_NULL_VALUE) == _SUCCESS)
                {
                    DebugMessageDigital("D2 MHL HPD Done", 0x01);
                    SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_HPD_DONE);
                }

                return _TRUE;
                break;

            case _MHL_STATE_HPD_DONE:

                if((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _ZTE_NUBIA_Z5_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _ZTE_NUBIA_Z5_ADOPTER_ID_LBYTE))
                {
                    ScalerTimerDelayXms(50);
                }

                if(ScalerMHLRx2MscSendCommand(_MSC_WRITE_STAT, _MSC_LINK_MODE, _MSC_PATH_EN) == _SUCCESS)
                {
                    DebugMessageDigital("D2 MHL Path Enabled", 0x01);
                    SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_PATH_EN_DONE);
                    SET_MHL_RX2_READY_TO_RESEND();

                    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE);
                }

                return _TRUE;
                break;

            case _MHL_STATE_PATH_EN_DONE:

                if(GET_TMDS_RX2_PHY_SET() == _TRUE)
                {
                    SET_MHL_RX2_PROCESS_STATE(_MHL_STATE_DONE);
                }

                return _TRUE;
                break;

            case _MHL_STATE_DONE:
            default:

                return _TRUE;
                break;
        }
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : RAP Process for D2 Port
// Input Value  : None
// Output Value : True or False (False if Content Off)
//--------------------------------------------------
bit ScalerMHLRx2MscRAPHandler(void)
{
    // Check RAP Command
    if((bit)ScalerGetBit(P2A_D4_CBUS_CTRL_34, _BIT3) == _TRUE)
    {
        if((ScalerGetByte(P2A_DC_CBUS_CTRL_3C) == _MSC_RAP_POLL) ||
           (ScalerGetByte(P2A_DC_CBUS_CTRL_3C) == _MSC_RAP_CONTENT_ON) ||
           (ScalerGetByte(P2A_DC_CBUS_CTRL_3C) == _MSC_RAP_CONTENT_OFF))
        {
            // Reply RAPK and No Error
            ScalerMHLRx2MscSendCommand(_MSC_MSG, _MSC_RAPK, _MSC_RAPK_NO_ERROR);
        }
        else
        {
            // Reply RAPK and Ineffective Code
            ScalerMHLRx2MscSendCommand(_MSC_MSG, _MSC_RAPK, _MSC_RAPK_UNRECOGNIZE_CODE);
        }

        // Clear Flag
        ScalerSetByte(P2A_D4_CBUS_CTRL_34, (BYTE)_BIT3);

        if(ScalerGetByte(P2A_DC_CBUS_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
        {
            return _FALSE;
        }
    }

    return _TRUE;
}

#if(_MHL_UCP_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Get UCP Key Code for D2 Port
// Input Value  : UCP Key Code
// Output Value : True or False
//--------------------------------------------------
BYTE ScalerMHLRx2MscUCPGetCommand(BYTE *pucKeyCode)
{
    // Check UCP Command
    if(((bit)ScalerGetBit(P2A_D4_CBUS_CTRL_34, _BIT1) == _TRUE) && (ScalerGetByte(P2A_D6_CBUS_CTRL_36) == _MSC_UCP))
    {
        // Clear Flag
        ScalerSetByte(P2A_D4_CBUS_CTRL_34, (BYTE)_BIT1);

        pucKeyCode[0] = ScalerGetByte(P2A_D7_CBUS_CTRL_37);

        return _TRUE;
    }

    return _FALSE;
}
#endif  // End of #if(_MHL_UCP_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Signal PreDetection for MHL(Power Saving)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerMHLRx2PSPreDetect(void)
{
    // Check RAP Content OFF
    if(ScalerGetByte(P2A_DC_CBUS_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
    {
        return _FAIL;
    }

    // PSM --> PNM While Wake Up Pulses Received
    if(ScalerGetBit(P2A_A0_CBUS_CTRL_00, (_BIT5 | _BIT4 | _BIT3)) == (_BIT5 | _BIT4 | _BIT3))
    {
        return _TRUE;
    }

    // Pre-Detect True By Switch Back to MHL Port
    if(GET_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE() == _TRUE)
    {
        CLR_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE();
        return _TRUE;
    }

    // [7] PSM = 1 --> Enable TMDS Lane3 Clock Switch
    ScalerSetBit(PB1_AB_CDR_02, ~_BIT7, _BIT7);

    // Disable clk lane Z0
    ScalerSetBit(PB1_A2_CMU_02, ~_BIT7, 0x00);

    // Reset Freq. Detect Counter(Toggle) & Choose Measure Clk to TMDS Clk
    ScalerSetBit(P71_E6_HDMI_FREQDET_CTRL, ~(_BIT7 | _BIT5 | _BIT4), 0x00);
    ScalerSetBit(P71_E6_HDMI_FREQDET_CTRL, ~_BIT7, _BIT7);

    // Clear Freq. Stable Flag
    ScalerSetBit(P71_EF_HDMI_ERROR_TH, ~_BIT6, _BIT6);

    // Clear Unstable Flag
    ScalerSetBit(P71_E6_HDMI_FREQDET_CTRL, ~_BIT2, _BIT2);

    // Delay enough time for freq. measure (calculated for measure 5 times)
    ScalerTimerDelayXms(5);

    // Detect Freq. Measure Stable
    if((ScalerGetBit(P71_E6_HDMI_FREQDET_CTRL, (_BIT6 | _BIT2)) == _BIT6) && (ScalerGetBit(P71_EF_HDMI_ERROR_TH, _BIT6) == _BIT6))
    {
        // [7] PSM = 1'b0 --> Disable TMDS Lane3 Clock Switch
        ScalerSetBit(PB1_AB_CDR_02, ~_BIT7, 0x00);

        // Enable clk lane Z0
        ScalerSetBit(PB1_A2_CMU_02, ~_BIT7, _BIT7);

        return _TRUE;
    }
    else
    {
        // Disable Freq. Detection
        ScalerSetBit(P71_E6_HDMI_FREQDET_CTRL, ~_BIT7, 0x00);

        // [7] PSM = 1'b0 --> Disable TMDS Lane3 Clock Switch
        ScalerSetBit(PB1_AB_CDR_02, ~_BIT7, 0x00);

        // Enable clk lane Z0
        ScalerSetBit(PB1_A2_CMU_02, ~_BIT7, _BIT7);
    }

    switch(GET_MHL_RX2_PROCESS_STATE())
    {
        case _MHL_STATE_INITIAL:
        case _MHL_STATE_PATH_EN_DONE:
        case _MHL_STATE_DONE:

            return _FAIL;
            break;

        default:

            return _SUCCESS;
            break;
    }

    return _FAIL;
}

//--------------------------------------------------
// Description  : Signal PreDetection for MHL(Power Normal)
// Input Value  : Input Port
// Output Value : True : TMDS Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerMHLRx2NormalPreDetect(void)
{
    // Check RAP Content OFF
    if(ScalerGetByte(P2A_DC_CBUS_CTRL_3C) == _MSC_RAP_CONTENT_OFF)
    {
        return _FAIL;
    }

    // Pre-Detect True By Switch Back to MHL Port
    if(GET_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE() == _TRUE)
    {
        CLR_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE();
        return _TRUE;
    }

    ScalerTimerDelayXms(6);

    if(GET_TMDS_RX2_PHY_SET() == _TRUE)
    {
        return _SUCCESS;
    }

    switch(GET_MHL_RX2_PROCESS_STATE())
    {
        case _MHL_STATE_INITIAL:
        case _MHL_STATE_PATH_EN_DONE:

            return _FAIL;
            break;

        default:

            return _SUCCESS;
            break;
    }

    return _FAIL;
}

#endif // End of #if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
