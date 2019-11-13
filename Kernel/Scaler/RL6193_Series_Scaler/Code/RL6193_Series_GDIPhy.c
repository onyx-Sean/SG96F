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
// ID Code      : RL6193_Series_GDIPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RL6193_SERIES_GDIPHY__

#include "ScalerFunctionInclude.h"


//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************
#define _MHL_1K                                 7
#define _MHL_100K                               8


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
void ScalerGDIPhyBandgap(bit bSelect);

#if(_DIGITAL_PORT_SUPPORT == _ON)
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect);
void ScalerGDIPhyPowerProc(BYTE ucPortSelect, EnumPowerAction enumPowerAction);
void ScalerGDIPhyDigitalPhySwitch(BYTE ucInputPort);
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
void ScalerGDIPhyRx0PowerProc(EnumPowerAction enumPowerAction);
void ScalerGDIPhyRx0Z0Switch(bit bSelect);
void ScalerGDIPhyRx0Power(EnumPowerAction enumPowerAction);
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
void ScalerGDIPhyRx1PowerProc(EnumPowerAction enumPowerAction);
void ScalerGDIPhyRx1Z0Switch(bit bSelect);
void ScalerGDIPhyRx1Power(EnumPowerAction enumPowerAction);
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
void ScalerGDIPhyRx2PowerProc(EnumPowerAction enumPowerAction);
void ScalerGDIPhyRx2Z0Switch(bit bSelect);
void ScalerGDIPhyRx2Power(EnumPowerAction enumPowerAction);
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
void ScalerGDIPhyRx3PowerProc(EnumPowerAction enumPowerAction);
void ScalerGDIPhyRx3Z0Switch(bit bSelect);
void ScalerGDIPhyRx3Power(EnumPowerAction enumPowerAction);
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
void ScalerGDIPhyRx4PowerProc(EnumPowerAction enumPowerAction);
void ScalerGDIPhyRx4Z0Switch(bit bSelect);
void ScalerGDIPhyRx4Power(EnumPowerAction enumPowerAction);
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
void ScalerGDIPhyRx5PowerProc(EnumPowerAction enumPowerAction);
void ScalerGDIPhyRx5Z0Switch(bit bSelect);
void ScalerGDIPhyRx5Power(EnumPowerAction enumPowerAction);
#endif


//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : GDI Bandgap
// Input Value  : ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyBandgap(bit bSelect)
{
    BYTE ucTemp = 0;

    // [6] reg_en_vtest_hiz = 0 --> Enable Vtest HIZ Mode
    // [2:1] reg_offcal_range = 2'b11 --> 75uA
    ScalerSetBit(PB_A7_CMU_07, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerSetBit(PB0_A7_CMU_07, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerSetBit(PB1_A7_CMU_07, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerSetBit(PB2_A7_CMU_07, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerSetBit(PB3_A7_CMU_07, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));
    ScalerSetBit(PB4_A7_CMU_07, ~(_BIT6 | _BIT2 | _BIT1), (_BIT2 | _BIT1));

    // [7] EN_ENHANCE_BIAS = 1 --> Enhance Clock Lane Input Buffer Bias Current
    ScalerSetBit(PB_AA_CDR_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB0_AA_CDR_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB1_AA_CDR_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB2_AA_CDR_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB3_AA_CDR_01, ~_BIT7, _BIT7);
    ScalerSetBit(PB4_AA_CDR_01, ~_BIT7, _BIT7);

    // [1] HST_BUF_SEL = 1'b0 --> Disable Hysteresis Amplifier in Clock Lane
    ScalerSetBit(PB_A6_CMU_06, ~_BIT6, 0x00);
    ScalerSetBit(PB0_A6_CMU_06, ~_BIT6, 0x00);
    ScalerSetBit(PB1_A6_CMU_06, ~_BIT6, 0x00);
    ScalerSetBit(PB2_A6_CMU_06, ~_BIT6, 0x00);
    ScalerSetBit(PB3_A6_CMU_06, ~_BIT6, 0x00);
    ScalerSetBit(PB4_A6_CMU_06, ~_BIT6, 0x00);

    // PSM=1 for HDMI port
#if(_D0_INPUT_PORT_TYPE == _D0_HDMI_PORT)
    ScalerSetBit(PB_AB_CDR_02, ~_BIT7, _BIT7);
#elif(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    ScalerSetBit(PB_AB_CDR_02, ~_BIT7, 0x00);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_HDMI_PORT)
    ScalerSetBit(PB0_AB_CDR_02, ~_BIT7, _BIT7);
#elif(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    ScalerSetBit(PB0_AB_CDR_02, ~_BIT7, 0x00);
#endif

#if((_D2_INPUT_PORT_TYPE == _D2_HDMI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DVI_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
    ScalerSetBit(PB1_AB_CDR_02, ~_BIT7, _BIT7);
#endif

#if((_D3_INPUT_PORT_TYPE == _D3_HDMI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DVI_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
    ScalerSetBit(PB2_AB_CDR_02, ~_BIT7, _BIT7);
#endif

#if((_D4_INPUT_PORT_TYPE == _D4_HDMI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DVI_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
    ScalerSetBit(PB3_AB_CDR_02, ~_BIT7, _BIT7);
#endif

#if((_D5_INPUT_PORT_TYPE == _D5_HDMI_PORT) || (_D5_INPUT_PORT_TYPE == _D5_DVI_PORT))
    ScalerSetBit(PB4_AB_CDR_02, ~_BIT7, _BIT7);
#endif

    if(bSelect == _ON)
    {
        ////////////////
        // BangGap EN //
        ////////////////

        // [7] EN_GDI_BG = 1'b1 --> GDI BG Power On
        // [6:5] RBG = 2'b00 --> BG = 1.245V
        ScalerSetBit(PB_B4_BANDGAP_00, ~(_BIT6 | _BIT5), 0x00);
        ScalerSetBit(PB_B4_BANDGAP_00, ~_BIT7, _BIT7);


        //////////////
        // Z0 AutoK //
        //////////////

        // [4] ibhx_ref_sel = 0 --> Vref = VBG
        // [3] Z0_AUTOK = 1 --> Z0 Auto K
        ScalerSetBit(PB_B4_BANDGAP_00, ~(_BIT4 | _BIT3), _BIT3);

        // [2] Z0_rstb = 1 -> 0 -> 1 --> 50ohm Auto Calibration
        ScalerSetBit(PB_B4_BANDGAP_00, ~_BIT2, _BIT2);
        ScalerSetBit(PB_B4_BANDGAP_00, ~_BIT2, 0x00);
        ScalerSetBit(PB_B4_BANDGAP_00, ~_BIT2, _BIT2);

        // Waiting for Calibration
        for(ucTemp = 0; ucTemp <= 10; ucTemp++)
        {
            Delay5us(g_ucDelay5usN);
        }

#if((_D0_CBUS_CHANNEL_SEL == _CBUS0) || (_D1_CBUS_CHANNEL_SEL == _CBUS0) || (_D2_CBUS_CHANNEL_SEL == _CBUS0) ||\
    (_D3_CBUS_CHANNEL_SEL == _CBUS0) || (_D4_CBUS_CHANNEL_SEL == _CBUS0) || (_D5_CBUS_CHANNEL_SEL == _CBUS0) ||\
    (_D0_CBUS_CHANNEL_SEL == _CBUS1) || (_D1_CBUS_CHANNEL_SEL == _CBUS1) || (_D2_CBUS_CHANNEL_SEL == _CBUS1) ||\
    (_D3_CBUS_CHANNEL_SEL == _CBUS1) || (_D4_CBUS_CHANNEL_SEL == _CBUS1) || (_D5_CBUS_CHANNEL_SEL == _CBUS1))

        // Set 1k Manual Code
        ScalerSetByte(P27_A2_CBUS_RES_AUTOK_0, _MHL_1K);

        // Set 100k Manual Code
        ScalerSetByte(P27_A3_CBUS_RES_AUTOK_1, _MHL_100K);

#elif((_D0_CBUS_CHANNEL_SEL == _CBUS2) || (_D1_CBUS_CHANNEL_SEL == _CBUS2) || (_D2_CBUS_CHANNEL_SEL == _CBUS2) ||\
      (_D3_CBUS_CHANNEL_SEL == _CBUS2) || (_D4_CBUS_CHANNEL_SEL == _CBUS2) || (_D5_CBUS_CHANNEL_SEL == _CBUS2) ||\
      (_D0_CBUS_CHANNEL_SEL == _CBUS3) || (_D1_CBUS_CHANNEL_SEL == _CBUS3) || (_D2_CBUS_CHANNEL_SEL == _CBUS3) ||\
      (_D3_CBUS_CHANNEL_SEL == _CBUS3) || (_D4_CBUS_CHANNEL_SEL == _CBUS3) || (_D5_CBUS_CHANNEL_SEL == _CBUS3))

        // Set 1k Manual Code
        ScalerSetByte(P67_A2_CBUS_RES_AUTOK_0, _MHL_1K);

        // Set 100k Manual Code
        ScalerSetByte(P67_A3_CBUS_RES_AUTOK_1, _MHL_100K);

#endif
    }
    else
    {
#if(_MHL_SUPPORT == _ON)
        // Check All CBUS Mac are not in Active State
        if((ScalerGetBit(P28_A4_CBUS_CTRL_04, _BIT0) == 0x00) && (ScalerGetBit(P29_A4_CBUS_CTRL_04, _BIT0) == 0x00) &&
           (ScalerGetBit(P2A_A4_CBUS_CTRL_04, _BIT0) == 0x00) && (ScalerGetBit(P68_A4_CBUS_CTRL_04, _BIT0) == 0x00) &&
           (ScalerGetBit(P69_A4_CBUS_CTRL_04, _BIT0) == 0x00) && (ScalerGetBit(P6A_A4_CBUS_CTRL_04, _BIT0) == 0x00))
#endif
        {
            // [7] EN_GDI_BG = 1'b0 --> GDI BG Power Off
            ScalerSetBit(PB_B4_BANDGAP_00, ~_BIT7, 0x00);
        }
    }
}

#if(_DIGITAL_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D0~D5 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyZ0Switch(BYTE ucPortSelect, bit bSelect)
{
    bSelect = bSelect;

    switch(ucPortSelect)
    {
        case _D0_INPUT_PORT:

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
            ScalerGDIPhyRx0Z0Switch(bSelect);
#endif

            break;

        case _D1_INPUT_PORT:

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
            ScalerGDIPhyRx1Z0Switch(bSelect);
#endif

            break;

        case _D2_INPUT_PORT:

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
            ScalerGDIPhyRx2Z0Switch(bSelect);
#endif

            break;


        case _D3_INPUT_PORT:

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
            ScalerGDIPhyRx3Z0Switch(bSelect);
#endif

            break;

        case _D4_INPUT_PORT:

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
            ScalerGDIPhyRx4Z0Switch(bSelect);
#endif

            break;

        case _D5_INPUT_PORT:

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
            ScalerGDIPhyRx5Z0Switch(bSelect);
#endif

            break;

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : GDI Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyPowerProc(BYTE ucPortSelect, EnumPowerAction enumPowerAction)
{
    enumPowerAction = enumPowerAction;

    switch(ucPortSelect)
    {
#if(_A0_INPUT_PORT_TYPE != _A0_NO_PORT)
        case _A0_INPUT_PORT:
        case _A1_INPUT_PORT:
        case _A2_INPUT_PORT:

            break;
#endif

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
        case _D0_INPUT_PORT:

            ScalerGDIPhyRx0PowerProc(enumPowerAction);

            break;
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
        case _D1_INPUT_PORT:

            ScalerGDIPhyRx1PowerProc(enumPowerAction);

            break;
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
        case _D2_INPUT_PORT:

            ScalerGDIPhyRx2PowerProc(enumPowerAction);

            break;
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
        case _D3_INPUT_PORT:

            ScalerGDIPhyRx3PowerProc(enumPowerAction);

            break;
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
        case _D4_INPUT_PORT:

            ScalerGDIPhyRx4PowerProc(enumPowerAction);

            break;
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
        case _D5_INPUT_PORT:

            ScalerGDIPhyRx5PowerProc(enumPowerAction);

            break;
#endif

        default:

            break;
    }
}

//--------------------------------------------------
// Description  : GDI Digital Phy Switch
// Input Value  : Port Type
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyDigitalPhySwitch(BYTE ucInputPort)
{
    ucInputPort = ucInputPort;
}
#endif // End of #if(_DIGITAL_PORT_SUPPORT == _ON)

#if(_D0_INPUT_PORT_TYPE != _D0_NO_PORT)
//--------------------------------------------------
// Description  : GDI Rx0 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx0PowerProc(EnumPowerAction enumPowerAction)
{
    ScalerGDIPhyRx0Power(enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            if(ScalerGetBit(PB_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
                if((GET_MHL_RX0_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
                   (((GET_MHL_RX0_ADOPTER_ID_HBYTE() == _CHROMA_MHL_ADOPTER_ID_HBYTE) && (GET_MHL_RX0_ADOPTER_ID_LBYTE() == _CHROMA_MHL_ADOPTER_ID_LBYTE)) ||
                    ((GET_MHL_RX0_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX0_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
                {
                    // Reset D0 CBUS
                    ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
                }
#endif
            }

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            if((GET_D0_TMDS_MODE() == _TMDS_MHL_MODE) && (GET_MHL_RX0_SWITCH_PORT_DISCOVERY_DONE() == _TRUE) &&
               (ScalerGetBit(PB_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX0_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
               (((GET_MHL_RX0_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_MHL_RX0_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE)) ||
                ((GET_MHL_RX0_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX0_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
            }
#endif
            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _ON);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D0_TMDS_SUPPORT == _ON)
            ScalerTMDSRx0PowerSavingProc();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_D0_TMDS_SUPPORT == _ON)
            ScalerTMDSRx0PowerOffProc();
#endif
            ScalerGDIPhyZ0Switch(_D0_INPUT_PORT, _OFF);

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            // MHL Power Off Process
            ScalerMHLPowerOffProc(_D0_INPUT_PORT);
#endif

#if((_D0_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            CLR_TMDS_RX0_TOGGLE_Z0();
            CLR_TMDS_RX0_TOGGLE_Z0_EVENT();
#endif
            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D0/D0 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx0Z0Switch(bit bSelect)
{
    if(bSelect == _ON)
    {
        SET_DIGITAL_PORT_SWITCH_TO_D0();

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        SET_DIGITAL_PORT_SWITCH_TO_D6();
#endif
    }
    else
    {
        CLR_DIGITAL_PORT_SWITCH_TO_D0();

#if((_D6_INPUT_PORT_TYPE == _D6_DP_PORT) && (_D6_INPUT_PORT_SWITCH_FROM == _SWITCH_FROM_D0))
        CLR_DIGITAL_PORT_SWITCH_TO_D6();
#endif
    }

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

    if(GET_D0_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(bSelect == _ON)
        {
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
            // Enable Z0
            ScalerSetBit(PB_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
        }
        else
        {
            if((ScalerGetBit(PB_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX0_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY))
            {
                if((GET_MHL_RX0_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX0_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))
                {
                    SET_MHL_RX0_SWITCH_PORT_DISCOVERY_DONE();
                }
                else
                {
                    // Reset D0 CBUS While Non-NoteII
                    ScalerMHLCBUSResetProc(_D0_INPUT_PORT);
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(_D0_INPUT_PORT, _OFF);

        if(bSelect == _ON)
        {
            if(ScalerGetBit(PB_A2_CMU_02, _BIT7) == 0x00)
            {
                SET_TMDS_RX0_Z0_ASSERTED();

                // Clear HDCP Flag
                ScalerSetBit(P2_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                CLR_TMDS_RX0_DDC_DETECTED();

                // Enable DDC Toggle IRQ
                MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
                MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

                // Enable Z0
                ScalerSetBit(PB_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
            // Disable DDC Toggle IRQ
            MCU_FFE4_DDC0_EDID_IRQ &= ~(_BIT3 | _BIT1);

            // Disable Z0
            ScalerSetBit(PB_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
        }
    }

#else // Else of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)

    if(bSelect == _ON)
    {
        // Disable MHL Mode
        ScalerSetBit(PB_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB_A2_CMU_02, _BIT7) == 0x00)
        {
#if(_D0_TMDS_SUPPORT == _ON)

            SET_TMDS_RX0_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P2_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX0_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT2;
            MCU_FFE4_DDC0_EDID_IRQ |= _BIT3;

#endif // End of #if(_D0_TMDS_SUPPORT == _ON)

            // Enable Z0
            ScalerSetBit(PB_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
        }
    }
    else
    {
#if(_D0_TMDS_SUPPORT == _ON)

        // Disable DDC Toggle IRQ
        MCU_FFE4_DDC0_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif
        // Disable Z0
        ScalerSetBit(PB_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
#endif // End of #if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
}


//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx0Power(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ////////////
            // LDO EN //
            ////////////

            // [6] CMU_LDO_EN = 1 --> Enable CMU's LDO
            // [5:3] CMU_VSEL_LDO_A[2:0] = 3'b011 --> CMU's LDO_A Output Voltage = 1.8V
            // [2:0] CMU_VSEL_LDO_D[2:0] = 3'b011 --> CMU's LDO_D Output Voltage = 1.8V
            ScalerSetBit(PB_B8_CMU_LDO_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
            ScalerSetBit(PB_B8_CMU_LDO_00, ~_BIT6, _BIT6);

            // [4:3] reg_rxvcom_sel = 2'b01 --> VDD - 0.3V
            ScalerSetBit(PB_A7_CMU_07, ~(_BIT4 | _BIT3), _BIT3);


            ////////////////////////
            // Offset Calibration //
            ////////////////////////

            // [6] EN_BACK_OFFSET = 1'b1 --> Enable Background Offset Calibration
            // [5] EN_FORE_OFFSET = 1'b0 --> Disable Auto K-offset
            ScalerSetBit(PB_AA_CDR_01, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB_AD_CDR_04, ~_BIT2, 0x00);


            //////////////
            // Z0 AutoK //
            //////////////

            // [0] Z0_manual = 1 --> Port0 50ohm Auto Mode
            ScalerSetBit(PB_A0_CMU_00, ~_BIT0, _BIT0);

#if(_D0_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)
            // Z0 Differential Impedance = level 5
            ScalerSetBit(PB_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
#else
            // Z0 Differential Impedance = level 8
            ScalerSetBit(PB_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);
#endif
            // Z0 Common Mode Impedance = level 6
            ScalerSetBit(PB_BB_COMMON_Z0_00, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

            // [3] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [2] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB_A0_CMU_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));


            ///////////////
            // Reset PHY //
            ///////////////

            // [6:3] cdr_rst_n = 4'b1111 --> Normal CDR
            ScalerSetBit(PB_C1_TMDS_CONT_1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

            // [5:2] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB_EF_DIG_11, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

            // [5] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB_F5_WD_01, ~_BIT5, _BIT5);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB_F6_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB_F7_DATA_TIMER, ~_BIT1, _BIT1);


            //////////////////////////////
            // HDMI/DP Interface Switch //
            //////////////////////////////

#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

            if(ScalerGetBit(PB_A0_CMU_00, _BIT5) == 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB_A1_CMU_01, 0x00);

                // Disable CMU PLL
                // Disable Local Bias LPF
                ScalerSetBit(PB_A7_CMU_07, ~(_BIT7 | _BIT5), 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to DP
                ScalerSetBit(PB_A0_CMU_00, ~_BIT5, _BIT5);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            // For DP Analog PHY to Digital PHY Clock Inverse
            ScalerSetByte(PB_E7_DIG_03, 0x00);

            // Digital PHY Select to DP
            ScalerSetBit(PB_E4_DIG_00, ~_BIT0, 0x00);
            ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, 0x00);
#else
            if(ScalerGetBit(PB_A0_CMU_00, _BIT5) != 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB_A1_CMU_01, 0x00);

                // Disable CMU PLL
                // Disable Local Bias LPF
                ScalerSetBit(PB_A7_CMU_07, ~(_BIT7 | _BIT5), 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to HDMI
                ScalerSetBit(PB_A0_CMU_00, ~_BIT5, 0x00);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            ScalerSetBit(PB_E7_DIG_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB_E4_DIG_00, ~_BIT0, _BIT0);
            ScalerSetBit(PB_00_HD_DP_SEL, ~_BIT0, _BIT0);
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB_A1_CMU_01, 0x80);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB_AD_CDR_04, ~_BIT2, 0x00);

            // [6] CMU_LDO_EN = 1'b0 --> Disable CMU's LDO
            ScalerSetBit(PB_B8_CMU_LDO_00, ~_BIT6, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_D0_INPUT_PORT_TYPE == _D0_MHL_PORT)
            if(GET_D0_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                // Disable RGB Z0
                ScalerSetBit(PB_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            }
#else
            // Disable RGB Z0
            ScalerSetBit(PB_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif

#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB_A1_CMU_01, 0x80);

            // Disable Local Bias LPF
            ScalerSetBit(PB_A7_CMU_07, ~_BIT5, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB_AD_CDR_04, ~_BIT2, 0x00);

            // [6] CMU_LDO_EN = 1'b0 --> Disable CMU's LDO
            ScalerSetBit(PB_B8_CMU_LDO_00, ~_BIT6, 0x00);

            break;

        default:

            break;
    }
}
#endif

#if(_D1_INPUT_PORT_TYPE != _D1_NO_PORT)
//--------------------------------------------------
// Description  : GDI Rx1 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx1PowerProc(EnumPowerAction enumPowerAction)
{
    ScalerGDIPhyRx1Power(enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            if(ScalerGetBit(PB0_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB0_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
                if((GET_MHL_RX1_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
                   (((GET_MHL_RX1_ADOPTER_ID_HBYTE() == _CHROMA_MHL_ADOPTER_ID_HBYTE) && (GET_MHL_RX1_ADOPTER_ID_LBYTE() == _CHROMA_MHL_ADOPTER_ID_LBYTE)) ||
                    ((GET_MHL_RX1_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX1_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
                {
                    // Reset D1 CBUS
                    ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
                }
#endif
            }

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            if((GET_D1_TMDS_MODE() == _TMDS_MHL_MODE) && (GET_MHL_RX1_SWITCH_PORT_DISCOVERY_DONE() == _TRUE) &&
               (ScalerGetBit(PB0_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX1_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
               (((GET_MHL_RX1_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_MHL_RX1_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE)) ||
                ((GET_MHL_RX1_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX1_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
            }
#endif
            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _ON);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D1_TMDS_SUPPORT == _ON)
            ScalerTMDSRx1PowerSavingProc();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_D1_TMDS_SUPPORT == _ON)
            ScalerTMDSRx1PowerOffProc();
#endif
            ScalerGDIPhyZ0Switch(_D1_INPUT_PORT, _OFF);

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            // MHL Power Off Process
            ScalerMHLPowerOffProc(_D1_INPUT_PORT);
#endif

#if((_D1_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            CLR_TMDS_RX1_TOGGLE_Z0();
            CLR_TMDS_RX1_TOGGLE_Z0_EVENT();
#endif
            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D1/D1 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx1Z0Switch(bit bSelect)
{
    if(bSelect == _ON)
    {
        SET_DIGITAL_PORT_SWITCH_TO_D1();
    }
    else
    {
        CLR_DIGITAL_PORT_SWITCH_TO_D1();
    }

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

    if(GET_D1_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(bSelect == _ON)
        {
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
            // Enable Z0
            ScalerSetBit(PB0_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
        }
        else
        {
            if((ScalerGetBit(PB0_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX1_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY))
            {
                if((GET_MHL_RX1_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX1_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))
                {
                    SET_MHL_RX1_SWITCH_PORT_DISCOVERY_DONE();
                }
                else
                {
                    // Reset D1 CBUS While Non-NoteII
                    ScalerMHLCBUSResetProc(_D1_INPUT_PORT);
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(_D1_INPUT_PORT, _OFF);

        if(bSelect == _ON)
        {
            if(ScalerGetBit(PB0_A2_CMU_02, _BIT7) == 0x00)
            {
                SET_TMDS_RX1_Z0_ASSERTED();

                // Clear HDCP Flag
                ScalerSetBit(P70_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                CLR_TMDS_RX1_DDC_DETECTED();

                // Enable DDC Toggle IRQ
                MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
                MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;

                // Enable Z0
                ScalerSetBit(PB0_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
            // Disable DDC Toggle IRQ
            MCU_FFE5_DDC1_EDID_IRQ &= ~(_BIT3 | _BIT1);

            // Disable Z0
            ScalerSetBit(PB0_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
        }
    }

#else // Else of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)

    if(bSelect == _ON)
    {
        // Disable MHL Mode
        ScalerSetBit(PB0_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB0_A2_CMU_02, _BIT7) == 0x00)
        {
#if(_D1_TMDS_SUPPORT == _ON)

            SET_TMDS_RX1_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P70_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX1_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT2;
            MCU_FFE5_DDC1_EDID_IRQ |= _BIT3;

#endif // End of #if(_D1_TMDS_SUPPORT == _ON)

            // Enable Z0
            ScalerSetBit(PB0_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
        }
    }
    else
    {
#if(_D1_TMDS_SUPPORT == _ON)

        // Disable DDC Toggle IRQ
        MCU_FFE5_DDC1_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif
        // Disable Z0
        ScalerSetBit(PB0_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
}


//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx1Power(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ////////////
            // LDO EN //
            ////////////

            // [6] CMU_LDO_EN = 1 --> Enable CMU's LDO
            // [5:3] CMU_VSEL_LDO_A[2:0] = 3'b011 --> CMU's LDO_A Output Voltage = 1.8V
            // [2:0] CMU_VSEL_LDO_D[2:0] = 3'b011 --> CMU's LDO_D Output Voltage = 1.8V
            ScalerSetBit(PB0_B8_CMU_LDO_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
            ScalerSetBit(PB0_B8_CMU_LDO_00, ~_BIT6, _BIT6);

            // [4:3] reg_rxvcom_sel = 2'b01 --> VDD - 0.3V
            ScalerSetBit(PB0_A7_CMU_07, ~(_BIT4 | _BIT3), _BIT3);


            ////////////////////////
            // Offset Calibration //
            ////////////////////////

            // [6] EN_BACK_OFFSET = 1'b1 --> Enable Background Offset Calibration
            // [5] EN_FORE_OFFSET = 1'b0 --> Disable Auto K-offset
            ScalerSetBit(PB0_AA_CDR_01, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB0_AD_CDR_04, ~_BIT2, 0x00);


            //////////////
            // Z0 AutoK //
            //////////////

            // [0] Z0_manual = 1 --> Port1 50ohm Auto Mode
            ScalerSetBit(PB0_A0_CMU_00, ~_BIT0, _BIT0);

#if(_D1_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)
            // Z0 Differential Impedance = level 5
            ScalerSetBit(PB0_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT0));
#else
            // Z0 Differential Impedance = level 8
            ScalerSetBit(PB0_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT3);
#endif
            // Z0 Common Mode Impedance = level 6
            ScalerSetBit(PB0_BB_COMMON_Z0_00, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

            // [3] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [2] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB0_A0_CMU_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));


            ///////////////
            // Reset PHY //
            ///////////////

            // [6:3] cdr_rst_n = 4'b1111 --> Normal CDR
            ScalerSetBit(PB0_C1_TMDS_CONT_1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

            // [5:2] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB0_EF_DIG_11, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

            // [5] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB0_F5_WD_01, ~_BIT5, _BIT5);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB0_F6_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB0_F7_DATA_TIMER, ~_BIT1, _BIT1);


            //////////////////////////////
            // HDMI/DP Interface Switch //
            //////////////////////////////

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

            if(ScalerGetBit(PB0_A0_CMU_00, _BIT5) == 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB0_A1_CMU_01, 0x00);

                // Disable CMU PLL
                // Disable Local Bias LPF
                ScalerSetBit(PB0_A7_CMU_07, ~(_BIT7 | _BIT5), 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB0_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB0_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to DP
                ScalerSetBit(PB0_A0_CMU_00, ~_BIT5, _BIT5);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB0_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            // For DP Analog PHY to Digital PHY Clock Inverse
            ScalerSetByte(PB0_E7_DIG_03, 0x00);

            // Digital PHY Select to DP
            ScalerSetBit(PB0_E4_DIG_00, ~_BIT0, 0x00);
            ScalerSetBit(PB0_00_HD_DP_SEL, ~_BIT0, 0x00);
#else
            if(ScalerGetBit(PB0_A0_CMU_00, _BIT5) != 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB0_A1_CMU_01, 0x00);

                // Disable CMU PLL
                // Disable Local Bias LPF
                ScalerSetBit(PB0_A7_CMU_07, ~(_BIT7 | _BIT5), 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB0_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB0_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to HDMI
                ScalerSetBit(PB0_A0_CMU_00, ~_BIT5, 0x00);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB0_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            ScalerSetBit(PB0_E7_DIG_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB0_E4_DIG_00, ~_BIT0, _BIT0);
            ScalerSetBit(PB0_00_HD_DP_SEL, ~_BIT0, _BIT0);
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB0_A1_CMU_01, 0x80);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB0_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB0_AD_CDR_04, ~_BIT2, 0x00);

            // [6] CMU_LDO_EN = 1'b0 --> Disable CMU's LDO
            ScalerSetBit(PB0_B8_CMU_LDO_00, ~_BIT6, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_D1_INPUT_PORT_TYPE == _D1_MHL_PORT)
            if(GET_D1_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                // Disable RGB Z0
                ScalerSetBit(PB0_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            }
#else
            // Disable RGB Z0
            ScalerSetBit(PB0_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif

#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB0_A1_CMU_01, 0x80);

            // Disable Local Bias LPF
            ScalerSetBit(PB0_A7_CMU_07, ~_BIT5, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB0_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB0_AD_CDR_04, ~_BIT2, 0x00);

            // [6] CMU_LDO_EN = 1'b0 --> Disable CMU's LDO
            ScalerSetBit(PB0_B8_CMU_LDO_00, ~_BIT6, 0x00);

            break;

        default:

            break;
    }
}
#endif

#if(_D2_INPUT_PORT_TYPE != _D2_NO_PORT)
//--------------------------------------------------
// Description  : GDI Rx2 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx2PowerProc(EnumPowerAction enumPowerAction)
{
    ScalerGDIPhyRx2Power(enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            if(ScalerGetBit(PB1_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB1_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
                if((GET_MHL_RX2_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
                   (((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _CHROMA_MHL_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _CHROMA_MHL_ADOPTER_ID_LBYTE)) ||
                    ((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
                {
                    // Reset D2 CBUS
                    ScalerMHLCBUSResetProc(_D2_INPUT_PORT);
                }
#endif
            }

            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
            if((GET_D2_TMDS_MODE() == _TMDS_MHL_MODE) && (GET_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE() == _TRUE) &&
               (ScalerGetBit(PB1_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX2_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
               (((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE)) ||
                ((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D2_INPUT_PORT);
            }
#endif
            ScalerGDIPhyZ0Switch(_D2_INPUT_PORT, _ON);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D2_TMDS_SUPPORT == _ON)
            ScalerTMDSRx2PowerSavingProc();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_D2_TMDS_SUPPORT == _ON)
            ScalerTMDSRx2PowerOffProc();
#endif
            ScalerGDIPhyZ0Switch(_D2_INPUT_PORT, _OFF);

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
            // MHL Power Off Process
            ScalerMHLPowerOffProc(_D2_INPUT_PORT);
#endif

#if((_D2_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            CLR_TMDS_RX2_TOGGLE_Z0();
            CLR_TMDS_RX2_TOGGLE_Z0_EVENT();
#endif
            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D2/D2 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx2Z0Switch(bit bSelect)
{
    if(bSelect == _ON)
    {
        SET_DIGITAL_PORT_SWITCH_TO_D2();
    }
    else
    {
        CLR_DIGITAL_PORT_SWITCH_TO_D2();
    }

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)

    if(GET_D2_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(bSelect == _ON)
        {
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
            // Enable Z0
            ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
        }
        else
        {
            if((ScalerGetBit(PB1_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX2_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY))
            {
                if((GET_MHL_RX2_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX2_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))
                {
                    SET_MHL_RX2_SWITCH_PORT_DISCOVERY_DONE();
                }
                else
                {
                    // Reset D2 CBUS While Non-NoteII
                    ScalerMHLCBUSResetProc(_D2_INPUT_PORT);
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(_D2_INPUT_PORT, _OFF);

        if(bSelect == _ON)
        {
            if(ScalerGetBit(PB1_A2_CMU_02, _BIT7) == 0x00)
            {
                SET_TMDS_RX2_Z0_ASSERTED();

                // Clear HDCP Flag
                ScalerSetBit(P71_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                CLR_TMDS_RX2_DDC_DETECTED();

                // Enable DDC Toggle IRQ
                MCU_FE69_DDC2_EDID_IRQ |= _BIT2;
                MCU_FE69_DDC2_EDID_IRQ |= _BIT3;

                // Enable Z0
                ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
            // Disable DDC Toggle IRQ
            MCU_FE69_DDC2_EDID_IRQ &= ~(_BIT3 | _BIT1);

            // Disable Z0
            ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
        }
    }

#else // Else of #if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)

    if(bSelect == _ON)
    {
        // Disable MHL Mode
        ScalerSetBit(PB1_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB1_A2_CMU_02, _BIT7) == 0x00)
        {
#if(_D2_TMDS_SUPPORT == _ON)

            SET_TMDS_RX2_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P71_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX2_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE69_DDC2_EDID_IRQ |= _BIT2;
            MCU_FE69_DDC2_EDID_IRQ |= _BIT3;

#if((_D3_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))

            SET_TMDS_RX3_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P72_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX3_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
            MCU_FE72_DDC3_EDID_IRQ |= _BIT3;

#endif // End of #if((_D3_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
#endif // End of #if(_D2_TMDS_SUPPORT == _ON)

            // Enable Z0
            ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
        }
    }
    else
    {
#if(_D2_TMDS_SUPPORT == _ON)

        // Disable DDC Toggle IRQ
        MCU_FE69_DDC2_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif
        // Disable Z0
        ScalerSetBit(PB1_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
#endif // End of #if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
}


//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx2Power(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ////////////
            // LDO EN //
            ////////////

            // [6] CMU_LDO_EN = 1 --> Enable CMU's LDO
            // [5:3] CMU_VSEL_LDO_A[2:0] = 3'b011 --> CMU's LDO_A Output Voltage = 1.8V
            // [2:0] CMU_VSEL_LDO_D[2:0] = 3'b011 --> CMU's LDO_D Output Voltage = 1.8V
            ScalerSetBit(PB1_B8_CMU_LDO_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
            ScalerSetBit(PB1_B8_CMU_LDO_00, ~_BIT6, _BIT6);

            // [4:3] reg_rxvcom_sel = 2'b01 --> VDD - 0.3V
            ScalerSetBit(PB1_A7_CMU_07, ~(_BIT4 | _BIT3), _BIT3);


            ////////////////////////
            // Offset Calibration //
            ////////////////////////

            // [6] EN_BACK_OFFSET = 1 --> Enable Background Offset Calibration
            // [5] EN_FORE_OFFSET = 1'b0 --> Disable Auto K-offset
            ScalerSetBit(PB1_AA_CDR_01, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB1_AD_CDR_04, ~_BIT2, 0x00);


            //////////////
            // Z0 AutoK //
            //////////////

            // [0] Z0_manual = 1 --> Port2 50ohm Auto Mode
            ScalerSetBit(PB1_A0_CMU_00, ~_BIT0, _BIT0);

#if(_D2_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)
            // Z0 Differential Impedance = level 6
            ScalerSetBit(PB1_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
#else
            // Z0 Differential Impedance = level 9
            ScalerSetBit(PB1_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
#endif
            // Z0 Common Mode Impedance = level 6
            ScalerSetBit(PB1_BB_COMMON_Z0_00, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

            // [3] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [2] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB1_A0_CMU_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));


            ///////////////
            // Reset PHY //
            ///////////////

            // [6:3] cdr_rst_n = 4'b1111 --> Normal CDR
            ScalerSetBit(PB1_C1_TMDS_CONT_1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

            // [5:2] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB1_EF_DIG_11, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

            // [5] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB1_F5_WD_01, ~_BIT5, _BIT5);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB1_F6_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB1_F7_DATA_TIMER, ~_BIT1, _BIT1);


            //////////////////////////////
            // HDMI/DP Interface Switch //
            //////////////////////////////

            if(ScalerGetBit(PB1_A0_CMU_00, _BIT5) != 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB1_A1_CMU_01, 0x00);

                // Disable Local Bias LPF
                ScalerSetBit(PB1_A7_CMU_07, ~_BIT5, 0x00);

                // Disable CMU PLL
                ScalerSetBit(PB1_A7_CMU_07, ~_BIT7, 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB1_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB1_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to HDMI
                ScalerSetBit(PB1_A0_CMU_00, ~_BIT5, 0x00);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB1_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            ScalerSetBit(PB1_E7_DIG_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB1_E4_DIG_00, ~_BIT0, _BIT0);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB1_A1_CMU_01, 0x80);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB1_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB1_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB1_B8_CMU_LDO_00, ~_BIT6, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_D2_INPUT_PORT_TYPE == _D2_MHL_PORT)
            if(GET_D2_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                // Disable RGB Z0
                ScalerSetBit(PB1_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            }
#else
            // Disable RGB Z0
            ScalerSetBit(PB1_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif

#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB1_A1_CMU_01, 0x80);

            // Disable Local Bias LPF
            ScalerSetBit(PB1_A7_CMU_07, ~_BIT5, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB1_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB1_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB1_B8_CMU_LDO_00, ~_BIT6, 0x00);

            break;

        default:

            break;
    }
}
#endif

#if((_D3_INPUT_PORT_TYPE != _D3_NO_PORT) || (_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT))
//--------------------------------------------------
// Description  : GDI Rx3 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx3PowerProc(EnumPowerAction enumPowerAction)
{
    ScalerGDIPhyRx3Power(enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            if(ScalerGetBit(PB2_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB2_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
                if((GET_MHL_RX3_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
                   (((GET_MHL_RX3_ADOPTER_ID_HBYTE() == _CHROMA_MHL_ADOPTER_ID_HBYTE) && (GET_MHL_RX3_ADOPTER_ID_LBYTE() == _CHROMA_MHL_ADOPTER_ID_LBYTE)) ||
                    ((GET_MHL_RX3_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX3_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
                {
                    // Reset D3 CBUS
                    ScalerMHLCBUSResetProc(_D3_INPUT_PORT);
                }
#endif
            }

#if(_D2_INPUT_PORT_TYPE == _D2_DUAL_DVI_PORT)

            if(ScalerGetBit(PB1_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB2_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
            }
#endif
            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
            if((GET_D3_TMDS_MODE() == _TMDS_MHL_MODE) && (GET_MHL_RX3_SWITCH_PORT_DISCOVERY_DONE() == _TRUE) &&
               (ScalerGetBit(PB2_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX3_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
               (((GET_MHL_RX3_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_MHL_RX3_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE)) ||
                ((GET_MHL_RX3_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX3_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D3_INPUT_PORT);
            }
#endif
            ScalerGDIPhyZ0Switch(_D3_INPUT_PORT, _ON);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D3_TMDS_SUPPORT == _ON)
            ScalerTMDSRx3PowerSavingProc();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_D3_TMDS_SUPPORT == _ON)
            ScalerTMDSRx3PowerOffProc();
#endif
            ScalerGDIPhyZ0Switch(_D3_INPUT_PORT, _OFF);

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
            // MHL Power Off Process
            ScalerMHLPowerOffProc(_D3_INPUT_PORT);
#endif

#if((_D3_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            CLR_TMDS_RX3_TOGGLE_Z0();
            CLR_TMDS_RX3_TOGGLE_Z0_EVENT();
#endif
            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D3/D3 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx3Z0Switch(bit bSelect)
{
    if(bSelect == _ON)
    {
        SET_DIGITAL_PORT_SWITCH_TO_D3();
    }
    else
    {
        CLR_DIGITAL_PORT_SWITCH_TO_D3();
    }

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)

    if(GET_D3_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(bSelect == _ON)
        {
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
            // Enable Z0
            ScalerSetBit(PB2_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
        }
        else
        {
            if((ScalerGetBit(PB2_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX3_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY))
            {
                if((GET_MHL_RX3_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX3_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))
                {
                    SET_MHL_RX3_SWITCH_PORT_DISCOVERY_DONE();
                }
                else
                {
                    // Reset D3 CBUS While Non-NoteII
                    ScalerMHLCBUSResetProc(_D3_INPUT_PORT);
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(_D3_INPUT_PORT, _OFF);

        if(bSelect == _ON)
        {
            if(ScalerGetBit(PB2_A2_CMU_02, _BIT7) == 0x00)
            {
                SET_TMDS_RX3_Z0_ASSERTED();

                // Clear HDCP Flag
                ScalerSetBit(P72_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                CLR_TMDS_RX3_DDC_DETECTED();

                // Enable DDC Toggle IRQ
                MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
                MCU_FE72_DDC3_EDID_IRQ |= _BIT3;

                // Enable Z0
                ScalerSetBit(PB2_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
            // Disable DDC Toggle IRQ
            MCU_FE72_DDC3_EDID_IRQ &= ~(_BIT3 | _BIT1);

            // Disable Z0
            ScalerSetBit(PB2_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
        }
    }

#else // Else of #if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)

    if(bSelect == _ON)
    {
        // Disable MHL Mode
        ScalerSetBit(PB2_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB2_A2_CMU_02, _BIT7) == 0x00)
        {
#if((_D3_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT))

            SET_TMDS_RX3_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P72_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX3_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE72_DDC3_EDID_IRQ |= _BIT2;
            MCU_FE72_DDC3_EDID_IRQ |= _BIT3;

#if((_D4_TMDS_SUPPORT == _ON) && (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))

            SET_TMDS_RX4_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P73_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX4_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;
            MCU_FE7B_DDC4_EDID_IRQ |= _BIT3;

#endif // End of #if((_D4_TMDS_SUPPORT == _ON) && (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
#endif // End of #if((_D3_TMDS_SUPPORT == _ON) && (_D2_INPUT_PORT_TYPE != _D2_DUAL_DVI_PORT))

            // Enable Z0
            ScalerSetBit(PB2_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
        }
    }
    else
    {
#if(_D3_TMDS_SUPPORT == _ON)

        // Disable DDC Toggle IRQ
        MCU_FE72_DDC3_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif
        // Disable Z0
        ScalerSetBit(PB2_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
#endif // End of #if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
}

//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx3Power(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ////////////
            // LDO EN //
            ////////////

            // [6] CMU_LDO_EN = 1 --> Enable CMU's LDO
            // [5:3] CMU_VSEL_LDO_A[2:0] = 3'b011 --> CMU's LDO_A Output Voltage = 1.8V
            // [2:0] CMU_VSEL_LDO_D[2:0] = 3'b011 --> CMU's LDO_D Output Voltage = 1.8V
            ScalerSetBit(PB2_B8_CMU_LDO_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
            ScalerSetBit(PB2_B8_CMU_LDO_00, ~_BIT6, _BIT6);

            // [4:3] reg_rxvcom_sel = 2'b01 --> VDD - 0.3V
            ScalerSetBit(PB2_A7_CMU_07, ~(_BIT4 | _BIT3), _BIT3);


            ////////////////////////
            // Offset Calibration //
            ////////////////////////

            // [6] EN_BACK_OFFSET = 1 --> Enable Background Offset Calibration
            // [5] EN_FORE_OFFSET = 1'b0 --> Disable Auto K-offset
            ScalerSetBit(PB2_AA_CDR_01, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB2_AD_CDR_04, ~_BIT2, 0x00);


            //////////////
            // Z0 AutoK //
            //////////////

            // [0] Z0_manual = 1 --> Port3 50ohm Auto Mode
            ScalerSetBit(PB2_A0_CMU_00, ~_BIT0, _BIT0);

#if(_D3_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)
            // Z0 Differential Impedance = level 6
            ScalerSetBit(PB2_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
#else
            // Z0 Differential Impedance = level 9
            ScalerSetBit(PB2_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
#endif
            // Z0 Common Mode Impedance = level 6
            ScalerSetBit(PB2_BB_COMMON_Z0_00, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

            // [3] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [2] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB2_A0_CMU_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));


            ///////////////
            // Reset PHY //
            ///////////////

            // [6:3] cdr_rst_n = 4'b1111 --> Normal CDR
            ScalerSetBit(PB2_C1_TMDS_CONT_1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

            // [5:2] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB2_EF_DIG_11, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

            // [5] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB2_F5_WD_01, ~_BIT5, _BIT5);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB2_F6_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB2_F7_DATA_TIMER, ~_BIT1, _BIT1);


            //////////////////////////////
            // HDMI/DP Interface Switch //
            //////////////////////////////

            if(ScalerGetBit(PB2_A0_CMU_00, _BIT5) != 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB2_A1_CMU_01, 0x00);

                // Disable Local Bias LPF
                ScalerSetBit(PB2_A7_CMU_07, ~_BIT5, 0x00);

                // Disable CMU PLL
                ScalerSetBit(PB2_A7_CMU_07, ~_BIT7, 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB2_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB2_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to HDMI
                ScalerSetBit(PB2_A0_CMU_00, ~_BIT5, 0x00);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB2_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            ScalerSetBit(PB2_E7_DIG_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB2_E4_DIG_00, ~_BIT0, _BIT0);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB2_A1_CMU_01, 0x80);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB2_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB2_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB2_B8_CMU_LDO_00, ~_BIT6, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_D3_INPUT_PORT_TYPE == _D3_MHL_PORT)
            if(GET_D3_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                // Disable RGB Z0
                ScalerSetBit(PB2_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            }
#else
            // Disable RGB Z0
            ScalerSetBit(PB2_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif

#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB2_A1_CMU_01, 0x80);

            // Disable Local Bias LPF
            ScalerSetBit(PB2_A7_CMU_07, ~_BIT5, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB2_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB2_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB2_B8_CMU_LDO_00, ~_BIT6, 0x00);

            break;

        default:

            break;
    }
}
#endif

#if((_D4_INPUT_PORT_TYPE != _D4_NO_PORT) || (_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT))
//--------------------------------------------------
// Description  : GDI Rx4 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx4PowerProc(EnumPowerAction enumPowerAction)
{
    ScalerGDIPhyRx4Power(enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            if(ScalerGetBit(PB3_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB3_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
                if((GET_MHL_RX4_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
                   (((GET_MHL_RX4_ADOPTER_ID_HBYTE() == _CHROMA_MHL_ADOPTER_ID_HBYTE) && (GET_MHL_RX4_ADOPTER_ID_LBYTE() == _CHROMA_MHL_ADOPTER_ID_LBYTE)) ||
                    ((GET_MHL_RX4_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX4_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
                {
                    // Reset D4 CBUS
                    ScalerMHLCBUSResetProc(_D4_INPUT_PORT);
                }
#endif
            }

#if(_D3_INPUT_PORT_TYPE == _D3_DUAL_DVI_PORT)

            if(ScalerGetBit(PB2_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB3_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
            }
#endif
            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
            if((GET_D4_TMDS_MODE() == _TMDS_MHL_MODE) && (GET_MHL_RX4_SWITCH_PORT_DISCOVERY_DONE() == _TRUE) &&
               (ScalerGetBit(PB3_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX4_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
               (((GET_MHL_RX4_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_MHL_RX4_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE)) ||
                ((GET_MHL_RX4_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX4_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D4_INPUT_PORT);
            }
#endif
            ScalerGDIPhyZ0Switch(_D4_INPUT_PORT, _ON);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D4_TMDS_SUPPORT == _ON)
            ScalerTMDSRx4PowerSavingProc();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_D4_TMDS_SUPPORT == _ON)
            ScalerTMDSRx4PowerOffProc();
#endif
            ScalerGDIPhyZ0Switch(_D4_INPUT_PORT, _OFF);

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
            // MHL Power Off Process
            ScalerMHLPowerOffProc(_D4_INPUT_PORT);
#endif

#if((_D4_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            CLR_TMDS_RX4_TOGGLE_Z0();
            CLR_TMDS_RX4_TOGGLE_Z0_EVENT();
#endif
            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D4/D4 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx4Z0Switch(bit bSelect)
{
    if(bSelect == _ON)
    {
        SET_DIGITAL_PORT_SWITCH_TO_D4();
    }
    else
    {
        CLR_DIGITAL_PORT_SWITCH_TO_D4();
    }

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)

    if(GET_D4_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(bSelect == _ON)
        {
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
            // Enable Z0
            ScalerSetBit(PB3_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
        }
        else
        {
            if((ScalerGetBit(PB3_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX4_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY))
            {
                if((GET_MHL_RX4_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX4_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))
                {
                    SET_MHL_RX4_SWITCH_PORT_DISCOVERY_DONE();
                }
                else
                {
                    // Reset D4 CBUS While Non-NoteII
                    ScalerMHLCBUSResetProc(_D4_INPUT_PORT);
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(_D4_INPUT_PORT, _OFF);

        if(bSelect == _ON)
        {
            if(ScalerGetBit(PB3_A2_CMU_02, _BIT7) == 0x00)
            {
                SET_TMDS_RX4_Z0_ASSERTED();

                // Clear HDCP Flag
                ScalerSetBit(P73_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                CLR_TMDS_RX4_DDC_DETECTED();

                // Enable DDC Toggle IRQ
                MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;
                MCU_FE7B_DDC4_EDID_IRQ |= _BIT3;

                // Enable Z0
                ScalerSetBit(PB3_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
            // Disable DDC Toggle IRQ
            MCU_FE7B_DDC4_EDID_IRQ &= ~(_BIT3 | _BIT1);

            // Disable Z0
            ScalerSetBit(PB3_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
        }
    }

#else // Else of #if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)

    if(bSelect == _ON)
    {
        // Disable MHL Mode
        ScalerSetBit(PB3_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB3_A2_CMU_02, _BIT7) == 0x00)
        {
#if((_D4_TMDS_SUPPORT == _ON) && (_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT))

            SET_TMDS_RX4_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P73_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX4_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE7B_DDC4_EDID_IRQ |= _BIT2;
            MCU_FE7B_DDC4_EDID_IRQ |= _BIT3;

#if((_D5_TMDS_SUPPORT == _ON) && (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))

            SET_TMDS_RX5_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P74_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX5_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE84_DDC5_EDID_IRQ |= _BIT2;
            MCU_FE84_DDC5_EDID_IRQ |= _BIT3;

#endif // End of #if((_D5_TMDS_SUPPORT == _ON) && (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
#endif // End of #if((_D4_TMDS_SUPPORT == _ON) && (_D3_INPUT_PORT_TYPE != _D3_DUAL_DVI_PORT))

            // Enable Z0
            ScalerSetBit(PB3_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
        }
    }
    else
    {
#if(_D4_TMDS_SUPPORT == _ON)

        // Disable DDC Toggle IRQ
        MCU_FFE4_DDC0_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif
        // Disable Z0
        ScalerSetBit(PB3_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
#endif // End of #if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
}

//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx4Power(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ////////////
            // LDO EN //
            ////////////

            // [6] CMU_LDO_EN = 1 --> Enable CMU's LDO
            // [5:3] CMU_VSEL_LDO_A[2:0] = 3'b011 --> CMU's LDO_A Output Voltage = 1.8V
            // [2:0] CMU_VSEL_LDO_D[2:0] = 3'b011 --> CMU's LDO_D Output Voltage = 1.8V
            ScalerSetBit(PB3_B8_CMU_LDO_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
            ScalerSetBit(PB3_B8_CMU_LDO_00, ~_BIT6, _BIT6);

            // [4:3] reg_rxvcom_sel = 2'b01 --> VDD - 0.3V
            ScalerSetBit(PB3_A7_CMU_07, ~(_BIT4 | _BIT3), _BIT3);


            ////////////////////////
            // Offset Calibration //
            ////////////////////////

            // [6] EN_BACK_OFFSET = 1 --> Enable Background Offset Calibration
            // [5] EN_FORE_OFFSET = 1'b0 --> Disable Auto K-offset
            ScalerSetBit(PB3_AA_CDR_01, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB3_AD_CDR_04, ~_BIT2, 0x00);


            //////////////
            // Z0 AutoK //
            //////////////

            // [0] Z0_manual = 1 --> Port4 50ohm Auto Mode
            ScalerSetBit(PB3_A0_CMU_00, ~_BIT0, _BIT0);

#if(_D4_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)
            // Z0 Differential Impedance = level 6
            ScalerSetBit(PB3_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
#else
            // Z0 Differential Impedance = level 9
            ScalerSetBit(PB3_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
#endif
            // Z0 Common Mode Impedance = level 6
            ScalerSetBit(PB3_BB_COMMON_Z0_00, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

            // [3] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [2] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB3_A0_CMU_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));


            ///////////////
            // Reset PHY //
            ///////////////

            // [6:3] cdr_rst_n = 4'b1111 --> Normal CDR
            ScalerSetBit(PB3_C1_TMDS_CONT_1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

            // [5:2] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB3_EF_DIG_11, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

            // [5] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB3_F5_WD_01, ~_BIT5, _BIT5);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB3_F6_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB3_F7_DATA_TIMER, ~_BIT1, _BIT1);


            //////////////////////////////
            // HDMI/DP Interface Switch //
            //////////////////////////////

            if(ScalerGetBit(PB3_A0_CMU_00, _BIT5) != 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB3_A1_CMU_01, 0x00);

                // Disable Local Bias LPF
                ScalerSetBit(PB3_A7_CMU_07, ~_BIT5, 0x00);

                // Disable CMU PLL
                ScalerSetBit(PB3_A7_CMU_07, ~_BIT7, 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB3_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB3_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to HDMI
                ScalerSetBit(PB3_A0_CMU_00, ~_BIT5, 0x00);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB3_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            ScalerSetBit(PB3_E7_DIG_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB3_E4_DIG_00, ~_BIT0, _BIT0);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB3_A1_CMU_01, 0x80);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB3_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB3_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB3_B8_CMU_LDO_00, ~_BIT6, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_D4_INPUT_PORT_TYPE == _D4_MHL_PORT)
            if(GET_D4_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                // Disable RGB Z0
                ScalerSetBit(PB3_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            }
#else
            // Disable RGB Z0
            ScalerSetBit(PB3_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif

#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB3_A1_CMU_01, 0x80);

            // Disable Local Bias LPF
            ScalerSetBit(PB3_A7_CMU_07, ~_BIT5, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB3_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB3_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB3_B8_CMU_LDO_00, ~_BIT6, 0x00);

            break;

        default:

            break;
    }
}
#endif

#if((_D5_INPUT_PORT_TYPE != _D5_NO_PORT) || (_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT))
//--------------------------------------------------
// Description  : GDI Rx5 Power Process
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx5PowerProc(EnumPowerAction enumPowerAction)
{
    ScalerGDIPhyRx5Power(enumPowerAction);

    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:

            break;

        case _POWER_ACTION_PS_TO_NORMAL:

            if(ScalerGetBit(PB4_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB4_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
                if((GET_MHL_RX5_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
                   (((GET_MHL_RX5_ADOPTER_ID_HBYTE() == _CHROMA_MHL_ADOPTER_ID_HBYTE) && (GET_MHL_RX5_ADOPTER_ID_LBYTE() == _CHROMA_MHL_ADOPTER_ID_LBYTE)) ||
                    ((GET_MHL_RX5_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX5_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
                {
                    // Reset D5 CBUS
                    ScalerMHLCBUSResetProc(_D5_INPUT_PORT);
                }
#endif
            }

#if(_D4_INPUT_PORT_TYPE == _D4_DUAL_DVI_PORT)

            if(ScalerGetBit(PB3_A2_CMU_02, _BIT7) == _BIT7)
            {
                // Enable RGB Z0
                ScalerSetBit(PB4_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), (_BIT6 | _BIT5 | _BIT4));
            }
#endif
            break;

        case _POWER_ACTION_OFF_TO_NORMAL:

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
            if((GET_D5_TMDS_MODE() == _TMDS_MHL_MODE) && (GET_MHL_RX5_SWITCH_PORT_DISCOVERY_DONE() == _TRUE) &&
               (ScalerGetBit(PB4_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX5_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY) &&
               (((GET_MHL_RX5_ADOPTER_ID_HBYTE() == _HUAWEI_D2_ADOPTER_ID_HBYTE) && (GET_MHL_RX5_ADOPTER_ID_LBYTE() == _HUAWEI_D2_ADOPTER_ID_LBYTE)) ||
                ((GET_MHL_RX5_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX5_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))))
            {
                // Reset CBUS
                ScalerMHLCBUSResetProc(_D5_INPUT_PORT);
            }
#endif
            ScalerGDIPhyZ0Switch(_D5_INPUT_PORT, _ON);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

#if(_D5_TMDS_SUPPORT == _ON)
            ScalerTMDSRx5PowerSavingProc();
#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_FAKE_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

#if(_D5_TMDS_SUPPORT == _ON)
            ScalerTMDSRx5PowerOffProc();
#endif
            ScalerGDIPhyZ0Switch(_D5_INPUT_PORT, _OFF);

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
            // MHL Power Off Process
            ScalerMHLPowerOffProc(_D5_INPUT_PORT);
#endif

#if((_D5_TMDS_SUPPORT == _ON) && (_TMDS_TOGGLE_HPD_Z0_FOR_ACER == _ON))
            CLR_TMDS_RX5_TOGGLE_Z0();
            CLR_TMDS_RX5_TOGGLE_Z0_EVENT();
#endif
            break;

        default:

            break;
    }
}


//--------------------------------------------------
// Description  : GDI Z0 Switch
// Input Value  : D5/D1 Port ; Z0 ON/OFF
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx5Z0Switch(bit bSelect)
{
    if(bSelect == _ON)
    {
        SET_DIGITAL_PORT_SWITCH_TO_D5();
    }
    else
    {
        CLR_DIGITAL_PORT_SWITCH_TO_D5();
    }

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)

    if(GET_D5_TMDS_MODE() == _TMDS_MHL_MODE)
    {
        if(bSelect == _ON)
        {
#if(_MHL_DEBUG_WITHOUT_CBUS_MODE == _ON)
            // Enable Z0
            ScalerSetBit(PB4_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
#endif
        }
        else
        {
            if((ScalerGetBit(PB4_A2_CMU_02, _BIT4) == _BIT4) &&
               (GET_MHL_RX5_PROCESS_STATE() >= _MHL_STATE_DEV_CAP_RDY))
            {
                if((GET_MHL_RX5_ADOPTER_ID_HBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_HBYTE) && (GET_MHL_RX5_ADOPTER_ID_LBYTE() == _SAMSUNG_NOTE2_ADOPTER_ID_LBYTE))
                {
                    SET_MHL_RX5_SWITCH_PORT_DISCOVERY_DONE();
                }
                else
                {
                    // Reset D5 CBUS While Non-NoteII
                    ScalerMHLCBUSResetProc(_D5_INPUT_PORT);
                }
            }
        }
    }
    else
    {
        ScalerMHLCBUSPhySwitch(_D5_INPUT_PORT, _OFF);

        if(bSelect == _ON)
        {
            if(ScalerGetBit(PB4_A2_CMU_02, _BIT7) == 0x00)
            {
                SET_TMDS_RX5_Z0_ASSERTED();

                // Clear HDCP Flag
                ScalerSetBit(P74_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

                // Initialize DDC Detection Process
                CLR_TMDS_RX5_DDC_DETECTED();

                // Enable DDC Toggle IRQ
                MCU_FE84_DDC5_EDID_IRQ |= _BIT2;
                MCU_FE84_DDC5_EDID_IRQ |= _BIT3;

                // Enable Z0
                ScalerSetBit(PB4_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
            }
        }
        else
        {
            // Disable DDC Toggle IRQ
            MCU_FE84_DDC5_EDID_IRQ &= ~(_BIT3 | _BIT1);

            // Disable Z0
            ScalerSetBit(PB4_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
        }
    }

#else // Else of #if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)

    if(bSelect == _ON)
    {
        // Disable MHL Mode
        ScalerSetBit(PB4_A0_CMU_00, ~(_BIT7 | _BIT6), 0x00);

        if(ScalerGetBit(PB4_A2_CMU_02, _BIT7) == 0x00)
        {
#if((_D5_TMDS_SUPPORT == _ON) && (_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT))

            SET_TMDS_RX5_Z0_ASSERTED();

            // Clear HDCP Flag
            ScalerSetBit(P74_A9_TMDS_ABC0, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6 | _BIT5));

            // Initialize DDC Detection Process
            CLR_TMDS_RX5_DDC_DETECTED();

            // Enable DDC Toggle IRQ
            MCU_FE84_DDC5_EDID_IRQ |= _BIT2;
            MCU_FE84_DDC5_EDID_IRQ |= _BIT3;

#endif // End of #if((_D5_TMDS_SUPPORT == _ON) && (_D4_INPUT_PORT_TYPE != _D4_DUAL_DVI_PORT))

            // Enable Z0
            ScalerSetBit(PB4_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), (_BIT7 | _BIT6 | _BIT5 | _BIT4));
        }
    }
    else
    {
#if(_D5_TMDS_SUPPORT == _ON)

        // Disable DDC Toggle IRQ
        MCU_FE84_DDC5_EDID_IRQ &= ~(_BIT3 | _BIT1);
#endif
        // Disable Z0
        ScalerSetBit(PB4_A2_CMU_02, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);
    }
#endif // End of #if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
}

//--------------------------------------------------
// Description  : GDI Bandgap Power On/Off
// Input Value  : On/Off
// Output Value : None
//--------------------------------------------------
void ScalerGDIPhyRx5Power(EnumPowerAction enumPowerAction)
{
    switch(enumPowerAction)
    {
        case _POWER_ACTION_AC_ON_TO_NORMAL:
        case _POWER_ACTION_OFF_TO_NORMAL:
        case _POWER_ACTION_PS_TO_NORMAL:

            ////////////
            // LDO EN //
            ////////////

            // [6] CMU_LDO_EN = 1 --> Enable CMU's LDO
            // [5:3] CMU_VSEL_LDO_A[2:0] = 3'b011 --> CMU's LDO_A Output Voltage = 1.8V
            // [2:0] CMU_VSEL_LDO_D[2:0] = 3'b011 --> CMU's LDO_D Output Voltage = 1.8V
            ScalerSetBit(PB4_B8_CMU_LDO_00, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT3 | _BIT1 | _BIT0));
            ScalerSetBit(PB4_B8_CMU_LDO_00, ~_BIT6, _BIT6);

            // [4:3] reg_rxvcom_sel = 2'b01 --> VDD - 0.3V
            ScalerSetBit(PB4_A7_CMU_07, ~(_BIT4 | _BIT3), _BIT3);


            ////////////////////////
            // Offset Calibration //
            ////////////////////////

            // [6] EN_BACK_OFFSET = 1 --> Enable Background Offset Calibration
            // [5] EN_FORE_OFFSET = 1'b0 --> Disable Auto K-offset
            ScalerSetBit(PB4_AA_CDR_01, ~(_BIT6 | _BIT5), _BIT6);

            // Disable Auto K-offset Auto Mode
            ScalerSetBit(PB4_AD_CDR_04, ~_BIT2, 0x00);


            //////////////
            // Z0 AutoK //
            //////////////

            // [0] Z0_manual = 1 --> Port5 50ohm Auto Mode
            ScalerSetBit(PB4_A0_CMU_00, ~_BIT0, _BIT0);

#if(_D5_TMDS_Z0_IMPEDANCE_OPTION == _LG_90_OHM)
            // Z0 Differential Impedance = level 6
            ScalerSetBit(PB4_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT2 | _BIT1));
#else
            // Z0 Differential Impedance = level 9
            ScalerSetBit(PB4_A2_CMU_02, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT3 | _BIT0));
#endif
            // Z0 Common Mode Impedance = level 6
            ScalerSetBit(PB4_BB_COMMON_Z0_00, ~(_BIT7 | _BIT6 | _BIT5), (_BIT7 | _BIT6));

            // [3] n_channel_en = 1 --> Switch n Channel 50ohm Z0
            // [2] p_channel_en = 1 --> Switch p Channel 50ohm Z0
            ScalerSetBit(PB4_A0_CMU_00, ~(_BIT3 | _BIT2), (_BIT3 | _BIT2));


            ///////////////
            // Reset PHY //
            ///////////////

            // [6:3] cdr_rst_n = 4'b1111 --> Normal CDR
            ScalerSetBit(PB4_C1_TMDS_CONT_1, ~(_BIT6 | _BIT5 | _BIT4 | _BIT3), (_BIT6 | _BIT5 | _BIT4 | _BIT3));

            // [5:2] phy_si_reset_n = 4'b1111 --> Normal Digital PHY
            ScalerSetBit(PB4_EF_DIG_11, ~(_BIT5 | _BIT4 | _BIT3 | _BIT2), (_BIT5 | _BIT4 | _BIT3 | _BIT2));

            // [5] bypass_clk_rdy = 1 --> Manual Mode
            ScalerSetBit(PB4_F5_WD_01, ~_BIT5, _BIT5);

            // [1] bypass_eqen_rdy = 1 --> Manual Mode
            ScalerSetBit(PB4_F6_EQEN_TIMER, ~_BIT1, _BIT1);

            // [1] bypass_data_rdy = 1 --> Manual Mode
            ScalerSetBit(PB4_F7_DATA_TIMER, ~_BIT1, _BIT1);


            //////////////////////////////
            // HDMI/DP Interface Switch //
            //////////////////////////////

            if(ScalerGetBit(PB4_A0_CMU_00, _BIT5) != 0x00)
            {
                // Disable Rx_En and CMU_En
                ScalerSetByte(PB4_A1_CMU_01, 0x00);

                // Disable Local Bias LPF
                ScalerSetBit(PB4_A7_CMU_07, ~_BIT5, 0x00);

                // Disable CMU PLL
                ScalerSetBit(PB4_A7_CMU_07, ~_BIT7, 0x00);

                // Disable Auto K-offset
                ScalerSetBit(PB4_AA_CDR_01, ~_BIT5, 0x00);

                // Disable Auto K-offset Auto Mode
                ScalerSetBit(PB4_AD_CDR_04, ~_BIT2, 0x00);

                // Analog Select to HDMI
                ScalerSetBit(PB4_A0_CMU_00, ~_BIT5, 0x00);
            }

            // Digital PHY Lane Swap Setting
            ScalerSetByte(PB4_F0_DIG_12, 0xE4);

            // Digital PHY P/N Swap Setting
            ScalerSetBit(PB4_E7_DIG_03, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), 0x00);

            // Digital PHY Select to HDMI
            ScalerSetBit(PB4_E4_DIG_00, ~_BIT0, _BIT0);

            break;

        case _POWER_ACTION_NORMAL_TO_PS:
        case _POWER_ACTION_NOSUPPORT_PS_TO_PS:

            // Disable R/G/B RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB4_A1_CMU_01, 0x80);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB4_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB4_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB4_B8_CMU_LDO_00, ~_BIT6, 0x00);

#if(_TMDS_Z0_POWER_SAVING_OPTION == _ONLY_CLK_CHANNEL_CONNECTED_FOR_PS)

#if(_D5_INPUT_PORT_TYPE == _D5_MHL_PORT)
            if(GET_D5_TMDS_MODE() == _TMDS_HDMI_MODE)
            {
                // Disable RGB Z0
                ScalerSetBit(PB4_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
            }
#else
            // Disable RGB Z0
            ScalerSetBit(PB4_A2_CMU_02, ~(_BIT6 | _BIT5 | _BIT4), 0x00);
#endif

#endif
            break;

        case _POWER_ACTION_NORMAL_TO_OFF:
        case _POWER_ACTION_SWITCH_INTERFACE_TO_OFF:
        case _POWER_ACTION_AC_ON_TO_OFF:
        case _POWER_ACTION_NOSUPPORT_PS_TO_OFF:
        case _POWER_ACTION_PS_TO_OFF:
        case _POWER_ACTION_FAKE_OFF_TO_OFF:

            // Disable R/G/B/Clock RX_EN, Disable R/G/B/Clock CDR_EN
            ScalerSetByte(PB4_A1_CMU_01, 0x80);

            // Disable Local Bias LPF
            ScalerSetBit(PB4_A7_CMU_07, ~_BIT5, 0x00);

            // Disable Auto k-offset(foreground)
            ScalerSetBit(PB4_AA_CDR_01, ~_BIT5, 0x00);

            // Disable Auto k-offset auto mode (foreground)
            ScalerSetBit(PB4_AD_CDR_04, ~_BIT2, 0x00);

            // [7] CMU_LDO_EN = 0 --> Disable CMU's LDO
            ScalerSetBit(PB4_B8_CMU_LDO_00, ~_BIT6, 0x00);

            break;

        default:

            break;
    }
}
#endif

