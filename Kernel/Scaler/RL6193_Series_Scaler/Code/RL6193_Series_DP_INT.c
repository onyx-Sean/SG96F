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
// ID Code      : RL6193_Series_DP_INT.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_DP_SUPPORT == _ON)

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
void ScalerDpIntHandler_EXINT0(void);

#if(_WD_TIMER_INT_SUPPORT == _ON)
void ScalerDpWDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID);
#endif

void ScalerDpExitIntSetting_EXINT0(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : DP Int Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpIntHandler_EXINT0(void) using 1
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    ScalerDpRx0IntHandler_EXINT0();
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    ScalerDpRx1IntHandler_EXINT0();
#endif
}

#if(_WD_TIMER_INT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Handle DP Related WD Timer Event
// Input Value  : ucEventID
// Output Value : None
//--------------------------------------------------
void ScalerDpWDTimerEventProc_WDINT(EnumScalerWDTimerEventID enumEventID) using 3
{
    BYTE ucTemp = 0;

    switch(enumEventID)
    {
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)

        case _SCALER_WD_TIMER_EVENT_RX0_DP_LINK_TRAINING_REBUILD_PHY:

            if(GET_DP_RX0_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_END_REBUILD_PHY)
            {
                ucTemp = ScalerGetByte_EXINT(PB7_D0_AUX_MODE_SET);

                if((ucTemp & _BIT1) == _BIT1)
                {
                    SET_DP_RX0_AUX_MANUAL_MODE_EXINT();
                }

                g_pucDpRx0Backup[0] = ScalerGetByte_EXINT(PB7_C1_DPCD_ADDR_PORT_H);
                g_pucDpRx0Backup[1] = ScalerGetByte_EXINT(PB7_C2_DPCD_ADDR_PORT_M);
                g_pucDpRx0Backup[2] = ScalerGetByte_EXINT(PB7_C3_DPCD_ADDR_PORT_L);

                ScalerDpRx0RebuildPhy_WDINT(ScalerDpRx0GetDpcdInfo_WDINT(0x00, 0x01, 0x00), ScalerDpRx0GetDpcdInfo_WDINT(0x00, 0x01, 0x01));

                SET_DP_RX0_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);

                // De-Skew Circuit Reset
                ScalerSetBit_EXINT(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), 0x00);
                ScalerSetBit_EXINT(PB_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), _BIT6);

                // Mac Reset After Link Clock Stable
                ScalerSetBit_EXINT(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
                ScalerSetBit_EXINT(PB_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

                // Delay for Lane Alignment after Mac Reset
                for(pData_EXINT[0] = 0; pData_EXINT[0] <= 20; pData_EXINT[0]++)
                {
                    Delay5us_EXINT(g_ucDelay5usN);
                }

                ScalerSetByte_EXINT(PB7_C1_DPCD_ADDR_PORT_H, g_pucDpRx0Backup[0]);
                ScalerSetByte_EXINT(PB7_C2_DPCD_ADDR_PORT_M, g_pucDpRx0Backup[1]);
                ScalerSetByte_EXINT(PB7_C3_DPCD_ADDR_PORT_L, g_pucDpRx0Backup[2]);

                if((ucTemp & _BIT1) == _BIT1)
                {
                    SET_DP_RX0_AUX_AUTO_MODE_EXINT();
                }
            }

            break;
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

        case _SCALER_WD_TIMER_EVENT_RX1_DP_LINK_TRAINING_REBUILD_PHY:

            if(GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_NORMAL_TRAINING_PATTERN_END_REBUILD_PHY)
            {
                ucTemp = ScalerGetByte_EXINT(PBA_D0_AUX_MODE_SET);

                if((ucTemp & _BIT1) == _BIT1)
                {
                    SET_DP_RX1_AUX_MANUAL_MODE_EXINT();
                }

                g_pucDpRx1Backup[0] = ScalerGetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H);
                g_pucDpRx1Backup[1] = ScalerGetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M);
                g_pucDpRx1Backup[2] = ScalerGetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L);

                ScalerDpRx1RebuildPhy_WDINT(ScalerDpRx1GetDpcdInfo_WDINT(0x00, 0x01, 0x00), ScalerDpRx1GetDpcdInfo_WDINT(0x00, 0x01, 0x01));

                SET_DP_RX1_LINK_TRAINING_STATUS(_DP_NORMAL_LINK_TRAINING_PASS);

                // De-Skew Circuit Reset
                ScalerSetBit_EXINT(PB0_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), 0x00);
                ScalerSetBit_EXINT(PB0_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), _BIT6);

                // Mac Reset After Link Clock Stable
                ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT1, _BIT1);
                ScalerSetBit_EXINT(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT1, 0x00);

                // Delay for Lane Alignment after Mac Reset
                for(pData_EXINT[0] = 0; pData_EXINT[0] <= 20; pData_EXINT[0]++)
                {
                    Delay5us_EXINT(g_ucDelay5usN);
                }

                ScalerSetByte_EXINT(PBA_C1_DPCD_ADDR_PORT_H, g_pucDpRx1Backup[0]);
                ScalerSetByte_EXINT(PBA_C2_DPCD_ADDR_PORT_M, g_pucDpRx1Backup[1]);
                ScalerSetByte_EXINT(PBA_C3_DPCD_ADDR_PORT_L, g_pucDpRx1Backup[2]);

                if((ucTemp & _BIT1) == _BIT1)
                {
                    SET_DP_RX1_AUX_AUTO_MODE_EXINT();
                }
            }

            break;
#endif

        default:
            break;
    }
}
#endif

//--------------------------------------------------
// Description  : Handle the DP settings when exiting sysint
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpExitIntSetting_EXINT0(void) using 1
{
#if(_D0_INPUT_PORT_TYPE == _D0_DP_PORT)
    if(ScalerGetBit_EXINT(PB7_D0_AUX_MODE_SET, _BIT1) == 0x00)
    {
        // Aux Hardware Control
        SET_DP_RX0_AUX_AUTO_MODE_EXINT();
    }

    // CLR Flag for 0x2002 bug
    ScalerSetBit_EXINT(PB7_FB_DUMMY_1, ~_BIT7, _BIT7);
    ScalerSetBit_EXINT(PB7_FB_DUMMY_1, ~_BIT7, 0x00);
#endif

#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
    if(ScalerGetBit_EXINT(PBA_D0_AUX_MODE_SET, _BIT1) == 0x00)
    {
        // Aux Hardware Control
        SET_DP_RX1_AUX_AUTO_MODE_EXINT();
    }

    // CLR Flag for 0x2002 bug
    ScalerSetBit_EXINT(PBA_FB_DUMMY_1, ~_BIT7, _BIT7);
    ScalerSetBit_EXINT(PBA_FB_DUMMY_1, ~_BIT7, 0x00);
#endif
}
#endif // #if(_DP_SUPPORT == _ON)
