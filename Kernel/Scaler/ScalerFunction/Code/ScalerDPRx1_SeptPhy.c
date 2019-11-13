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
// ID Code      : ScalerDPRx1_SeptPhy.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

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
#if(_D1_DP_EXIST == _ON)
BYTE g_ucDpRx1PhyCtsCtrl;
StructDpLanesMapping g_stDpRx1LanesMapping;

#if(_DP_MST_SUPPORT == _ON)
StructDPRxMiscInfo g_stDpRx1MiscInfo;
BYTE g_pucDpRx1MstTimeSlotBackup[13];
#endif

#endif

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
void ScalerDpRx1AVMute(void);
void ScalerDpRx1AdjustVsyncDelay(void);
bit ScalerDpRx1AlignCheck(void);
void ScalerDpRx1CheckHdcpCpirqStatus(void);

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
bit ScalerDpRx1CheckVgipVsBypass(void);
#endif

void ScalerDpRx1CrcCalculate(void);
#if(_HW_HS_TRACKING_GEN_TYPE == _HS_TRACKING_GEN_2)
void ScalerDpRx1HSActiveTrackingMode(EnumDpHSTrackingType enumHSTrackingType);
#endif
void ScalerDpRx1DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus);
DWORD ScalerDpRx1GetBStoVSDelay(void);
BYTE ScalerDpRx1GetDpcdBitInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit);
BYTE ScalerDpRx1GetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL);
bit ScalerDpRx1GetVideoStream(void);
void ScalerDpRx1HotPlugDuration(EnumDpHotPlugTime enumHpdTime);
void ScalerDpRx1HotPlugEvent(EnumDpHotPlugAssertType enumHpdType);
void ScalerDpRx1Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort);
bit ScalerDpRx1MarginLinkCheck(void);
void ScalerDpRx1LinkStatusIRQ(void);
void ScalerDpRx1AuxDiffModeSet(void);

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
void ScalerDpRx1DecodeErrorCountReset(void);
bit ScalerDpRx1DecodeErrorCountCheck(WORD usTimeCriteria, BYTE ucErrorCriteria);
bit ScalerDpRx1DecodeErrorCountLaneMeasure(BYTE ucErrorCriteria, BYTE ucDpRx1LaneNumber);
#endif

bit ScalerDpRx1MSAActiveChange(void);
bit ScalerDpRx1PSPreDetect(void);
void ScalerDpRx1SetDpLaneMapping(BYTE ucLanetype);
void ScalerDpRx1SecDataBlockReset(void);
void ScalerDpRx1SetDpcdBitValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit);
void ScalerDpRx1SetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue);
void ScalerDpRx1SinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync);
bit ScalerDpRx1ValidSignalDetectionDCOnCheck(void);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
void ScalerDpRx1ASSRModeSetting(void);
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
WORD ScalerDpRx1GetBStoHSDelay(WORD usDpHtotal);
bit ScalerDpRx1GetFREESYNCStatusChange(void);
WORD ScalerDpRx1GetHPeriod(void);
WORD ScalerDpRx1GetHSW(void);
WORD ScalerDpRx1GetVFreq(void);
WORD ScalerDpRx1GetVPeriod(void);
#endif

#if(_DP_MST_SUPPORT == _ON)
void ScalerDpRx1AuxChPowerStatusCheck(bit bCableStatus);
void ScalerDpRx1MstInfoBackup(EnumDpMstBackup enumDpMstBackup);

#if(_DP_TX_SUPPORT == _ON)
void ScalerDpRx1HDCPAuthShaRun(bit bIsFirst);

#if(_D1_DP_MST_PORT_SUPPORT == _ON)
void ScalerDpRx1HDCPBlockReset(void);
#endif

void ScalerDpRx1HDCPChangeAuthState(EnumDPRxHDCPAuthState enumHDCPAuthState);
bit ScalerDpRx1HDCPCheckBinfo(void);
bit ScalerDpRx1HDCPCheckLvp(void);
void ScalerDpRx1HDCPFakeAuthenProc(void);
void ScalerDpRx1HDCPHandler(void);
void ScalerDpRx1HDCPLoadKsvFifo(void);
void ScalerDpRx1HDCPLoadShaToDpcd(void);
void ScalerDpRx1HDCPSetKsvFifoFirst(void);
void ScalerDpRx1HDCPSetReadIrqTimeout(void);
void ScalerDpRx1HDCPSetRepeaterProcTimeout(void);
void ScalerDpRx1HDCPSha1Calculate(BYTE *pucInputArray, BYTE ucCalCount);
void ScalerDpRx1HDCPWriteShaInput(void);
void ScalerDpRx1MstToSstProc(void);
void ScalerDpRx1MstToSstSetColorInfo(void);
bit ScalerDpRx1MstToSstStableDetect(void);
#endif

#endif

#if(_DP_TX_SUPPORT == _ON)
void ScalerDpRx1UpdateSinkCount(void);
#endif

#endif

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
#if(_D1_DP_EXIST == _ON)
//--------------------------------------------------
// Description  : DP RGB Output Disable
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1AVMute(void)
{
    // Disable fifo overflwo/ underflwo IRQ
    ScalerSetBit(PB9_3A_DP_IRQ_CTRL0, ~(_BIT1 | _BIT0), 0x00);

    // Disable RGB Output
    ScalerSetBit(PB8_31_DP_OUTPUT_CTRL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

#if(_AUDIO_SUPPORT == _ON)
    // Disable Audio Channel
    ScalerAudioDpAudioEnable(_DISABLE, _D1_INPUT_PORT);
#endif
}
//--------------------------------------------------
// Description  : DP Adjust Vsync Delay
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1AdjustVsyncDelay(void)
{
    DWORD ulBStoVSDelayDeltaOverflow = 0;
    DWORD ulBStoVSDelayDeltaUnderflow = 0;

    if(ScalerGetBit(PB8_21_PG_CTRL_1, (_BIT1 | _BIT0)) == 0x00)// Fifo Ok
    {
        return;
    }
    else if(ScalerGetBit(PB8_21_PG_CTRL_1, _BIT0) == _BIT0) // Fifo Overflow
    {
        // Get Htotal
        ScalerRead(PB9_08_MSA_HTT_0, 2, &pData[0], _AUTOINC);

        // ((Link Clk * 256)/ Stream CLK) * Htotal / 256 --> 1 Line
        ulBStoVSDelayDeltaOverflow = (((DWORD)ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) * 270UL) * 256) / ((DWORD)GET_INPUT_PIXEL_CLK()) * ((DWORD)PDATA_WORD(0)) / 256;

        DebugMessageRx1("7. Fifo Overflow --> nVidia Case", ulBStoVSDelayDeltaOverflow);
    }
    else if(ScalerGetBit(PB8_21_PG_CTRL_1, _BIT1) == _BIT1) // Fifo Underflow
    {
        // Get Hactive
        ScalerRead(PB9_0C_MSA_HWD_0, 2, &pData[0], _AUTOINC);

        if(PDATA_WORD(0) != 1366)
        {
            return;
        }

        PDATA_WORD(0) = PDATA_WORD(0) - 2;

        // Set Hactive
        ScalerSetByte(PB8_45_MN_DPF_HWD_M, pData[0]);
        ScalerSetByte(PB8_46_MN_DPF_HWD_L, pData[1]);

        // ((Link Clk * 2)/ Stream CLK) --> 2 pixels
        ulBStoVSDelayDeltaUnderflow = (((DWORD)ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) * 270) * 2) / ((DWORD)GET_INPUT_PIXEL_CLK());

        DebugMessageRx1("7. Fifo Underflow --> QD882 Case", ulBStoVSDelayDeltaUnderflow);
    }

    // For Initial Value Before Use PDATA_DWORD(0)
    pData[0] = 0;

    // Get BStoVSDelay Even
    ScalerRead(PB8_32_EVBLK2VS_H, 3, &pData[1], _AUTOINC);

    // For Initial Value Before Use PDATA_DWORD(1)
    pData[4] = 0;

    // Get BStoVSDelay Odd
    ScalerRead(PB8_35_OVBLK2VS_H, 3, &pData[5], _AUTOINC);

    // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
    PDATA_DWORD(0) = PDATA_DWORD(0) - ((ulBStoVSDelayDeltaOverflow + ulBStoVSDelayDeltaUnderflow) / 2);

    // BStoVSDelay = BStoVSDelay + (Nvid * 256 / Mvid) * ((DWORD)Htotal) / 256;
    PDATA_DWORD(1) = PDATA_DWORD(1) - ((ulBStoVSDelayDeltaOverflow + ulBStoVSDelayDeltaUnderflow) / 2);

    // Set Even Field BS to VS Delay
    ScalerSetByte(PB8_32_EVBLK2VS_H, pData[1]);
    ScalerSetByte(PB8_33_EVBLK2VS_M, pData[2]);
    ScalerSetByte(PB8_34_EVBLK2VS_L, pData[3]);

    // Set Odd Field BS to VS Delay
    ScalerSetByte(PB8_35_OVBLK2VS_H, pData[5]);
    ScalerSetByte(PB8_36_OVBLK2VS_M, pData[6]);
    ScalerSetByte(PB8_37_OVBLK2VS_L, pData[7]);

    // Enable Double Buffer
    ScalerSetBit(PB8_30_DPF_CTRL_0, ~_BIT6, _BIT6);

    // Reset Display Format Gen
    ScalerSetBit(PB8_30_DPF_CTRL_0, ~_BIT7, 0x00);
    ScalerSetBit(PB8_30_DPF_CTRL_0, ~_BIT7, _BIT7);

    ScalerTimerDelayXms(30);
}
//--------------------------------------------------
// Description  : Check Valid Lane Alignment
// Input Value  : None
// Output Value : True --> Align
//--------------------------------------------------
bit ScalerDpRx1AlignCheck(void)
{
    if((ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F) == _DP_ONE_LANE)
    {
        return _TRUE;
    }
    else
    {
        if(ScalerGetBit(PB0_0E_DESKEW_PHY, _BIT4) == 0x00)
        {
            if(ScalerGetBit(PB0_0E_DESKEW_PHY, (_BIT7 | _BIT6)) != (_BIT7 | _BIT6))
            {
                ScalerSetBit(PB0_0E_DESKEW_PHY, ~(_BIT7 | _BIT6), (_BIT7 | _BIT6));

                ScalerTimerDelayXms(3);
            }
            else
            {
                return _FALSE;
            }
        }
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Clear CPIRQ Flag
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1CheckHdcpCpirqStatus(void)
{
    if((ScalerGetByte(PB0_1E_HDCP_INTGT_VRF_ANS_MSB) == 0x53) && (ScalerGetByte(PB0_1F_HDCP_INTGT_VRF_ANS_LSB) == 0x1F))
    {
        if((ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x01) & _BIT2) == _BIT2)
        {
#if(_DP_HDCP_2_2_SUPPORT == _ON)
            // Check HDCP22 decode
            if(ScalerGetBit(PB0_1A_HDCP_IRQ, _BIT1) == _BIT1)
            {
                if(ScalerDpRx1GetDpcdInfo(0x06, 0x94, 0x93) == 0x00)
                {
                    // Clear Link Status CPIRQ Flag
                    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x01, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x01) & ~_BIT2));
                }
            }
            else
#endif
            {
                if(ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x29) == 0x00)
                {
                    // Clear Link Status CPIRQ Flag
                    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x01, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x01) & ~_BIT2));
                }
            }
        }
    }
}

#if(_FORMAT_CONVERSION_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Check VGIP VS bypass for DP
// Input Value  : None
// Output Value : _TRUE / _FALSE
//--------------------------------------------------
bit ScalerDpRx1CheckVgipVsBypass(void)
{
    // Get Hstart
    ScalerRead(PB8_43_MN_DPF_HST_M, 2, &pData[0], _AUTOINC);

    // Get Vstart
    ScalerRead(PB8_4B_MN_DPF_VST_M, 2, &pData[2], _AUTOINC);

    // Check for nVedia 2560x1440@144Hz timing (reduced blanking)
    if((PDATA_WORD(0) < _VGIP_IH_CAPTURE_MIN_VALUE) ||
       (PDATA_WORD(1) <= _VGIP_IV_CAPTURE_MIN_VALUE))
    {
        DebugMessageRx1("DP RX1 VGIP VS Bypass Mode", PDATA_WORD(0));

        return _TRUE;
    }

    return _FALSE;
}
#endif

//--------------------------------------------------
// Description  : DP CRC Calculate
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1CrcCalculate(void)
{
    if(GET_DP_RX1_CRC_CALCULATE() == _TRUE)
    {
        DebugMessageRx1("7. DP CRC Test Start", 0);

        // Start CRC Calculation
        ScalerSetBit(PB8_70_DP_CRC_CTRL, ~_BIT7, _BIT7);

        if(ScalerTimerPollingFlagProc(_DP_MEASURE_POLLING_TIMEOUT, PB8_70_DP_CRC_CTRL, _BIT6, _TRUE) == _TRUE)
        {
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x40, ScalerGetByte(PB8_72_DP_CRC_R_L));
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x41, ScalerGetByte(PB8_71_DP_CRC_R_M));
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x42, ScalerGetByte(PB8_74_DP_CRC_G_L));
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x43, ScalerGetByte(PB8_73_DP_CRC_G_M));
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x44, ScalerGetByte(PB8_76_DP_CRC_B_L));
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x45, ScalerGetByte(PB8_75_DP_CRC_B_M));

            CLR_DP_RX1_CRC_CALCULATE();

            // Update _TEST_CRC_COUNT
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x46, 0x21);
        }

        // Stop CRC Calculation
        ScalerSetBit(PB8_70_DP_CRC_CTRL, ~_BIT7, 0x00);
    }
}
#if(_HW_HS_TRACKING_GEN_TYPE == _HS_TRACKING_GEN_2)
//--------------------------------------------------
// Description  : DP Hs Tracking Active Region Setting
// Input Value  : Hs Tracking Type
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HSActiveTrackingMode(EnumDpHSTrackingType enumHSTrackingType)
{
    if(enumHSTrackingType == _DP_HS_TRACKING_FW_MODE)
    {
        // HS Tracking Region By FW Setting
        ScalerSetBit(PB8_B9_MN_SCLKG_SDM_TEST, ~_BIT7, _BIT7);

        // BE Start Num = 2 line
        ScalerSetBit(PB8_C7_VBID_MAN_MADE, ~(_BIT7 | _BIT6 | _BIT5 | _BIT4), _BIT5);

        // BE End Num = 2 line
        ScalerSetBit(PB8_C7_VBID_MAN_MADE, ~(_BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT1);
    }
    else
    {
        // HS Tracking Region By FW Setting
        ScalerSetBit(PB8_B9_MN_SCLKG_SDM_TEST, ~_BIT7, 0x00);
    }
}
#endif
//--------------------------------------------------
// Description  : DPCD Link Status Field Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1DpcdLinkStatusReset(EnumDpResetStatus enumDpResetStatus)
{
    pData[0] = ScalerGetByte(PBA_D0_AUX_MODE_SET);

    SET_DP_RX1_AUX_MANUAL_MODE();

    if(enumDpResetStatus == _DP_DPCD_LINK_STATUS_INITIAL)
    {
        // Set DPCD 00600h to 0x01
        ScalerDpRx1SetDpcdBitValue(0x00, 0x06, 0x00, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);
    }

    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x02, 0x00);
    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x03, 0x00);
    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x04, 0x80);
    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x05, 0x00);
    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x06, 0x00);
    ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x07, 0x00);

    SET_DP_RX1_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);

    CLR_DP_RX1_BACKUP_PD_LINK_STATUS_FLG();

    if((pData[0] & _BIT1) == _BIT1)
    {
        SET_DP_RX1_AUX_AUTO_MODE();
    }

#if(_DP_MST_SUPPORT == _ON)

    if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
    {
        pData[0] = ScalerGetByte(PBA_D0_AUX_MODE_SET);

        SET_DP_RX1_AUX_AUTO_MODE();

        pData[1] = ScalerDpRx1GetDpcdInfo(0x00, 0x20, 0x05);
        ScalerDpRx1SetDpcdValue(0x00, 0x20, 0x05, (pData[1] | _BIT1));

        ScalerDpRx1SetDpcdValue(0x00, 0x02, 0xC0, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0xC0) & ~_BIT1));

        if((pData[0] & _BIT1) != _BIT1)
        {
            SET_DP_RX1_AUX_MANUAL_MODE();
        }
    }

#endif
}
//--------------------------------------------------
// Description  : DP BS to VS Delay Calculation
// Input Value  : None
// Output Value : BS to VS Delay
//--------------------------------------------------
DWORD ScalerDpRx1GetBStoVSDelay(void)
{
    DWORD ulVFrontPorch = 0;
    DWORD ulHFrontPorch = 0;
    WORD usFifoOffset = 0;

    // Get Htotal
    ScalerRead(PB9_08_MSA_HTT_0, 2, &pData[2], _AUTOINC);

    // VFrontPorch = 3 * Htotal * (Link Clk / Stream CLK)
    ulVFrontPorch = ((DWORD)GET_DP_RX1_VFRONT_PORCH()) * ((DWORD)PDATA_WORD(1) * 256) / ((DWORD)GET_INPUT_PIXEL_CLK()) *
                    ((DWORD)ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) * 270) / 256;

    // Get Hactive
    ScalerRead(PB9_0C_MSA_HWD_0, 2, pData, _AUTOINC);

    // Get HSW
    pData[4] = ScalerGetBit(PB9_0E_MSA_HSW_0, (_BIT6 | _BIT5 | _BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0));
    pData[5] = ScalerGetByte(PB9_0F_MSA_HSW_1);

    // Get HSW min by Measure clock
    PDATA_WORD(3) = ((DWORD) _DP_HSYNC_WIDTH_MEASURE_COUNTER * GET_INPUT_PIXEL_CLK() * 100) / _MEASURE_CLK + 1;

    // Check HSW <= HSW min
    if(PDATA_WORD(2) <= PDATA_WORD(3))
    {
        // Check if H porch is more than HSW min
        if((PDATA_WORD(1) - PDATA_WORD(0)) >= PDATA_WORD(3))
        {
            // HSW = HSW min
            PDATA_WORD(2) = PDATA_WORD(3);
        }
        else
        {
            // HSW = Max H Porch
            PDATA_WORD(2) = (PDATA_WORD(1) - PDATA_WORD(0));
        }
    }

    // DPF H Front Porch must not be less than 8 (HW constraint)
    // Check if H porch is more than 8
    if((PDATA_WORD(1) - PDATA_WORD(0) - PDATA_WORD(2)) <= _DP_HSYNC_FRONT_PORCH)
    {
        // HSW < HSW min
        if(PDATA_WORD(2) < PDATA_WORD(3))
        {
            // Hstart = HSW
            PDATA_WORD(4) = PDATA_WORD(2);
        }
        else if((PDATA_WORD(1) - PDATA_WORD(0) - PDATA_WORD(3) >= _DP_HSYNC_FRONT_PORCH))
        {
            // HSW = H porch - _DP_HSYNC_FRONT_PORCH
            PDATA_WORD(2) = PDATA_WORD(1) - PDATA_WORD(0) - _DP_HSYNC_FRONT_PORCH;

            // Hstart = HSW
            PDATA_WORD(4) = PDATA_WORD(2);
        }
        else
        {
            // HSW = HSW min
            PDATA_WORD(2) = PDATA_WORD(3);

            // Hstart = HSW min
            PDATA_WORD(4) = PDATA_WORD(3);
        }
    }
    else
    {
        // Hstart = Htotal - Hactive - _DP_HSYNC_FRONT_PORCH
        PDATA_WORD(4) = PDATA_WORD(1) - PDATA_WORD(0) - _DP_HSYNC_FRONT_PORCH;
    }

    // HFrontPorch = (Htotal - Hactive - Hstart) * (Link Clk / Stream CLK)
    ulHFrontPorch = (((DWORD)(PDATA_WORD(1) - PDATA_WORD(0) - PDATA_WORD(4))) * (((DWORD)ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00)) * 270) / ((DWORD)GET_INPUT_PIXEL_CLK()));

    pData[15] = GET_COLOR_DEPTH();

    // DP fifo size = 256 x 96bit
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        // FifoOffset = (1/2 * (256 * 96) / (2 * depth per color)), color format is YCbCr 4:2:2
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (4 * (WORD)pData[15]);
    }
    else
    {
        // FifoOffset = (1/2 * (256 * 96) / (3 * depth per color)), color format is RGB or YCbCr 4:4:4 or others
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (6 * (WORD)pData[15]);
    }

    // FifoOffset = (1/2 * (256 * 96) / (3 * depth per color)) * (Link Clk / Stream CLK))
    usFifoOffset = (WORD)(((DWORD)usFifoOffset) * (((DWORD)ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00)) * 270) / ((DWORD)GET_INPUT_PIXEL_CLK()));

    return ((ulVFrontPorch + ulHFrontPorch + (DWORD)usFifoOffset) / 2);
}
//--------------------------------------------------
// Description  : Get DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpRx1GetDpcdBitInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdBit)
{
    // Release Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerSetByte(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);

    return ScalerGetBit(PBA_C4_DPCD_DATA_PORT, ucDpcdBit);
}
//--------------------------------------------------
// Description  : Get DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
// Output Value : DPCD Information
//--------------------------------------------------
BYTE ScalerDpRx1GetDpcdInfo(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL)
{
    // Release Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerSetByte(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);

    return ScalerGetByte(PBA_C4_DPCD_DATA_PORT);
}
//--------------------------------------------------
// Description  : Check Dp Video Straam VBID
// Input Value  : None
// Output Value : True --> Get Video Stream
//--------------------------------------------------
bit ScalerDpRx1GetVideoStream(void)
{
    if(ScalerGetBit(PB9_01_DP_VBID, _BIT3) == 0x00)
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Hot Plug Low Pulse Duration
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HotPlugDuration(EnumDpHotPlugTime enumHpdTime)
{
#if(_DP_TX_SUPPORT == _ON)
    BYTE ucBackUp1 = 0;
#endif
    BYTE ucBackUp2 = 0;

    if(GET_D1_CABLE_STATUS() == _TRUE)
    {
        if(enumHpdTime != 1)
        {
            if(enumHpdTime != 0)
            {
#if(_DP_TX_SUPPORT == _ON)
                if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D1_PORT)
                {
                    ScalerDpTxForceIdlePatternSetting();
                }
#endif
                PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);
                ScalerTimerDelayXms(enumHpdTime);
            }

#if(_DP_TX_SUPPORT == _ON)
            ScalerDpRx1UpdateSinkCount();
#endif

            PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);
        }
        else
        {
#if(_DP_TX_SUPPORT == _ON)
            // Disable IRQs that take too long
            ucBackUp1 = ScalerGetBit(PBB_72_HPD_IRQ_EN, _BIT6);
            ScalerSetBit(PBB_72_HPD_IRQ_EN, ~_BIT6, 0x00);
#endif

            ucBackUp2 = ScalerGetByte(PBA_D0_AUX_MODE_SET);

            SET_DP_RX1_AUX_MANUAL_MODE();

            PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);

            for(pData[0] = 0; pData[0] < 85; pData[0]++)
            {
                Delay5us(g_ucDelay5usN);
            }

            PCB_D1_HOTPLUG(_D1_HOT_PLUG_HIGH);

            if((ucBackUp2 & _BIT1) == _BIT1)
            {
                SET_DP_RX1_AUX_AUTO_MODE();
            }

#if(_DP_TX_SUPPORT == _ON)
            ScalerSetBit(PBB_72_HPD_IRQ_EN, ~_BIT6, ucBackUp1);
#endif
        }
    }
}
//--------------------------------------------------
// Description  : Dp HotPlug Event
// Input Value  : Hot Plug Type
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HotPlugEvent(EnumDpHotPlugAssertType enumHpdType)
{
    ScalerTimerWDCancelTimerEvent(_SCALER_WD_TIMER_EVENT_RX1_DP_LINK_TRAINING_REBUILD_PHY);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HOTPLUG_ASSERTED);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_LONG_HOTPLUG_EVENT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_LINK_STATUS_IRQ);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_VALID_SIGNAL_DETECT_CHECK);

#if(_DP_MST_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
#if(_DP_TX_SUPPORT == _ON)
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_CPIRQ_EVENT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_REPEATER_PROC_TIMEOUT);
    ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_READ_IRQ_TIMEOUT);
#endif
#endif

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
    if((enumHpdType != _DP_HDCP_LONG_HPD_EVENT) && (enumHpdType != _DP_HBR2_MARGIN_LINK_HPD_EVENT) &&
       (ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x00) >= _DP_VERSION_1_2) && (ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x01) < _D1_DP_LINK_CLK_RATE) && (_D1_DP_LINK_CLK_RATE == _DP_LINK_HBR2))
    {
        ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x01, _D1_DP_LINK_CLK_RATE);
        DebugMessageRx1("Flag Clear_Hotplug Event", ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x01));
    }
#endif

    if(enumHpdType == _DP_HPD_ASSERTED)
    {
        if(PCB_D1_HOTPLUG_DETECT() == _D1_HOT_PLUG_HIGH)
        {
            return;
        }
    }
    else
    {
        ScalerDpRx1AVMute();
    }

    if(enumHpdType == _DP_HPD_LOW)
    {
        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);

        return;
    }
    else if(enumHpdType == _DP_HPD_LOW_RESET_AUX)
    {
        // Reset Aux
        ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, _BIT7);

        PCB_D1_HOTPLUG(_D1_HOT_PLUG_LOW);

        return;
    }

    // Reset DDC1
    MCU_FF2D_DDC1_DDC_CONTROL_1 |= _BIT1;

    // Release Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerDpRx1DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_INITIAL);

#if(_DP_FREESYNC_SUPPORT == _ON)
    SET_DP_RX1_AUX_MANUAL_MODE();
    ScalerDpRx1SetDpcdValue(0x00, 0x01, 0x07, 0x00);
    SET_DP_RX1_AUX_AUTO_MODE();
#endif

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
    ScalerDpRx1HDCPBlockReset();
#endif

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    SET_DP_RX1_AUX_MANUAL_MODE();
    ScalerDpRx1SetDpcdValue(0x00, 0x01, 0x0A, 0x00);
    SET_DP_RX1_AUX_AUTO_MODE();
#endif

    if(enumHpdType == _DP_LONG_HPD_EVENT)
    {
        ScalerDpRx1HotPlugDuration(_DP_LONG_HPD_TIME);
    }
    else if(enumHpdType == _DP_HDCP_LONG_HPD_EVENT)
    {
        ScalerDpRx1HotPlugDuration(_DP_HDCP_LONG_HPD_TIME);
    }
    else if(enumHpdType == _DP_MST_LONG_HPD_EVENT)
    {
        // Reset Aux
        ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, _BIT7);

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
        // No Receiving Topology Rebuild MSG within 4s
        if(GET_DP_TX_WAIT_TOPOLOGY_REBUILD_MSG() == _TRUE)
        {
            ScalerDpRx1HotPlugDuration(_DP_MST_FORCE_LONG_HPD_TIME);
        }
        else
#endif
        {
            ScalerDpRx1HotPlugDuration(_DP_MST_LONG_HPD_TIME);
        }
    }
#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
    else if(enumHpdType == _DP_HBR2_MARGIN_LINK_HPD_EVENT)
    {
#if(_DP_MST_SUPPORT == _ON)
        if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
        {
            ScalerDpRx1MstReset();
        }
#endif
        ScalerDpRx1HotPlugDuration(800);
    }
#endif
    else
    {
        ScalerDpRx1HotPlugDuration(_DP_HPD_ASSERTED_TIME);
    }

    // Reset Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, _BIT7);

    // Release Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerSetBit(PBA_D0_AUX_MODE_SET, ~_BIT1, 0x00);

    ScalerDpRx1SetDpcdValue(0x00, 0x01, 0x00, 0x00);
    ScalerDpRx1SetDpcdValue(0x00, 0x01, 0x01, (ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x01) & 0xE0));

    ScalerSetBit(PBA_D0_AUX_MODE_SET, ~_BIT1, _BIT1);

    if(GET_D1_CABLE_STATUS() == _TRUE)
    {
        ScalerDpRx1ValidSignalDetectionActiveEvent();
    }
}
//--------------------------------------------------
// Description  : Initial Setting for DP
// Input Value  : _DP_VERSION_1_1 or _DP_VERSION_1_2
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1Initial(EnumDpVersionType enumDpVersion, EnumDpLaneCount enumDpLaneCount, EnumDPMSTPort enumDpRxMstPort)
{
    ScalerDpRx1AuxIntInitial();

    ScalerDpRx1DpcdInitial(enumDpVersion, enumDpLaneCount, enumDpRxMstPort);

#if(_DP_ASSR_MODE_SUPPORT == _ON)
    SET_DP_RX1_AUX_MANUAL_MODE();
    ScalerDpRx1SetDpcdValue(0x00, 0x01, 0x0A, 0x00);
    SET_DP_RX1_AUX_AUTO_MODE();
#endif

    SET_DP_RX1_LINK_TRAINING_STATUS(_DP_LINK_TRAINING_NONE);

    SET_DP_RX1_FAKE_LINK_TRAINING();

    CLR_DP_RX_D1_MARGIN_LINK_HBR_RBR();

    SET_DP_RX_TARGET_MST_PORT(enumDpRxMstPort);
    SET_DP_RX_D1_PORT_TARGET_VERSION(enumDpVersion);
    SET_DP_RX_D1_PORT_TARGET_LANE_COUNT(enumDpLaneCount);

    ScalerDpRx1SetDpLaneMapping(_DP_LANE_MAPPING_NORMAL_TYPE);

#if(_DP_MST_SUPPORT == _ON)
    CLR_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
    CLR_DP_RX1_CHECK_AUX_CH_POWER_OFF();
#endif

#if(_DP_TX_SUPPORT == _ON)
    CLR_DP_RX1_HDCP_AUTH_AKSV_WRITTEN();
#endif
}

//--------------------------------------------------
// Description  : DP Margin Link Check
// Input Value  : None
// Output Value : _TRUE : Link ok ; _FALSE : Margin Link
//--------------------------------------------------
bit ScalerDpRx1MarginLinkCheck(void)
{
    switch(ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00))
    {
        case _DP_LINK_RBR:
        case _DP_LINK_HBR:

            if((GET_DP_RX_D1_MARGIN_LINK_HBR_RBR() == _FALSE) && (GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
            {
                return _FALSE;
            }

            break;

        case _DP_LINK_HBR2:

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
            if((ScalerDpRx1DFECheck() == _TRUE) &&
               (ScalerDpRx1SignalCheck(ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00), (ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)) == _TRUE) &&
               (ScalerDpRx1DecodeErrorCountCheck(_DP_HBR2_MARGIN_LINK_TIME_CRITERIA, _DP_HBR2_MARGIN_LINK_ERROR_CRITERIA) == _FALSE))
            {
                if(GET_D1_CABLE_STATUS() == _TRUE)
                {
                    SET_DP_RX_D1_MARGIN_LINK_HBR2();
                    return _FALSE;
                }
            }
#else
            return _TRUE;
#endif
            break;

        default:
            return _TRUE;
            break;
    }

    return _TRUE;
}

//--------------------------------------------------
// Description  : Dp Interrupt Request
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1LinkStatusIRQ(void)
{
    SET_DP_RX1_AUX_MANUAL_MODE();

    if((GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_FAIL) || (GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
    {
        if((ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) <= _DP_LINK_HBR) && (GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_LINK_STATUS_FAIL))
        {
            if(GET_D1_CABLE_STATUS() == _TRUE)
            {
                SET_DP_RX_D1_MARGIN_LINK_HBR_RBR();
            }
        }

        ScalerDpRx1DpcdLinkStatusReset(_DP_DPCD_LINK_STATUS_IRQ);

        SET_DP_RX1_AUX_AUTO_MODE();

#if((_DP_TX_SUPPORT == _ON) && (_D1_DP_MST_PORT_SUPPORT == _ON))
        ScalerDpRx1HDCPBlockReset();
#endif
        if((ScalerDpRx1GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != _BIT1) &&
           (ScalerDpRx1GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT0)))
        {
            ScalerDpRx1HotPlugDuration(_DP_HPD_IRQ_TIME);
        }
    }

    SET_DP_RX1_AUX_AUTO_MODE();
}

//-------------------------------------------------------
// Description  : Set Aux Diff mode or Single-eneded mode
// Input Value  : None
// Output Value : None
//-------------------------------------------------------
void ScalerDpRx1AuxDiffModeSet(void)
{
    if(GET_DP_AUX_DIFF_MODE() == _FALSE)
    {
        // Set TX VLDO, Open AUX ADJR_P, Rx Common Mode from 1.3V
        ScalerSetByte(PBA_61_AUX_1, 0xF0);

        // [5]Enable Single-Ended Mode, [4:3]Aux Vth-->50mV, [0]Aux 50ohm auto K(Enable Big_Z0_P)
        ScalerSetByte(PBA_62_AUX_2, 0x29);

        // [4]Enable Big_Z0_N, [3:0]Open ADJR_N
        ScalerSetBit(PBA_66_AUX_6, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), _BIT4);
    }
    else
    {
        // Set TX VLDO, Set AUX ADJR_P = 3, Rx Common Mode from 1.2V
        ScalerSetByte(PBA_61_AUX_1, 0xD3);

        // [5]Disable Single-Ended Mode, [4:3]Aux Vth-->50mV, [0]Aux 50ohm auto K(Enable Big_Z0_P)
        ScalerSetByte(PBA_62_AUX_2, 0x09);

        // [4]Enable Big_Z0_N, [3:0]Set ADJR_N = 3
        ScalerSetBit(PBA_66_AUX_6, ~(_BIT4 | _BIT3 | _BIT2 | _BIT1 | _BIT0), (_BIT4 | _BIT1 | _BIT0));
    }
}

#if(_DP_HBR2_MARGIN_LINK_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Reset 8b10b Error Count value
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1DecodeErrorCountReset(void)
{
    // Reset 8b10b Error Count Value
    ScalerSetBit(PB0_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), 0x00);

    // Start Record 8b10b Error Count Value
    ScalerSetBit(PB0_08_BIST_PATTERN_SEL, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);
}

//--------------------------------------------------
// Description  : Check 8b10b Error Count
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx1DecodeErrorCountCheck(WORD usTimeCriteria, BYTE ucErrorCriteria)
{
    ScalerDpRx1DecodeErrorCountReset();

    ScalerTimerDelayXms(usTimeCriteria);

    switch(ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x01) & 0x1F)
    {
        case _DP_ONE_LANE:

            if(ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE0) == _TRUE)
            {
                return _TRUE;
            }

            break;

        case _DP_TWO_LANE:

            if((ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE0) == _TRUE) &&
               (ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE1) == _TRUE))
            {
                return _TRUE;
            }

            break;

        case _DP_FOUR_LANE:
        default:

            if((ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE0) == _TRUE) &&
               (ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE1) == _TRUE) &&
               (ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE2) == _TRUE) &&
               (ScalerDpRx1DecodeErrorCountLaneMeasure(ucErrorCriteria, _D1_DP_LANE3) == _TRUE))
            {
                return _TRUE;
            }

            break;
    }

    DebugMessageRx1("7. DP Error Count Fail", 0);

    return _FALSE;
}

//--------------------------------------------------
// Description : Measure 8b10b Error Count Per Lane
// Input Value  : DP Lane
// Output Value : True --> locked; False --> unlocked
//--------------------------------------------------
bit ScalerDpRx1DecodeErrorCountLaneMeasure(BYTE ucErrorCriteria, BYTE ucDpRx1LaneNumber)
{
    WORD usErrorCountLaneMeasure = 0;

    // Select Lane
    ScalerSetBit(PB0_08_BIST_PATTERN_SEL, ~(_BIT4 | _BIT3), (ucDpRx1LaneNumber << 3));

    usErrorCountLaneMeasure = ((((WORD)ScalerGetByte(PB0_0B_BIST_PATTERN3)) << 8) | ScalerGetByte(PB0_0C_BIST_PATTERN4));

    if(usErrorCountLaneMeasure > ucErrorCriteria)
    {
        DebugMessageRx1("DP Lane", ucDpRx1LaneNumber);
        DebugMessageRx1("DP Lane Burst Error", usErrorCountLaneMeasure);

        return _FALSE;
    }

    return _TRUE;
}
#endif

//--------------------------------------------------
// Description  : Check DP Vactive / Hactive Information
// Input Value  : None
// Output Value : True --> DP Vactive / Hactive Information Check Ok
//--------------------------------------------------
bit ScalerDpRx1MSAActiveChange(void)
{
    // Pop up Main Stream Attributes
    ScalerSetBit(PB9_00_MN_STRM_ATTR_CTRL, ~(_BIT7 | _BIT6 | _BIT5 | _BIT3 | _BIT2), (_BIT7 | _BIT6 | _BIT5 | _BIT3));

    // Get Display Format Hactive
    ScalerRead(PB8_45_MN_DPF_HWD_M, 2, &pData[0], _AUTOINC);

    // Get MSA Hactive
    ScalerRead(PB9_0C_MSA_HWD_0, 2, &pData[2], _AUTOINC);

    // Get Display Format Vactive
    ScalerRead(PB8_4D_MN_DPF_VHT_M, 2, &pData[4], _AUTOINC);

    // Get MSA Vactive
    ScalerRead(PB9_16_MSA_VHT_0, 2, &pData[6], _AUTOINC);

    if((PDATA_WORD(0) != PDATA_WORD(1)) || (PDATA_WORD(2) != PDATA_WORD(3)))
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Signal Detection for DP(Power Saving)
// Input Value  : None
// Output Value : True : DP Signal Detected
//              : False : No Signal
//--------------------------------------------------
bit ScalerDpRx1PSPreDetect(void)
{
    // Back to noraml for DP PHY CTS
    if(GET_DP_RX1_PHY_CTS_FLG() == _TRUE)
    {
        return _TRUE;
    }

    if(GET_DP_RX1_VALID_VIDEO_CHECK() == _TRUE)
    {
        DebugMessageRx1("7. Valid Video Check", 0);

        return _TRUE;
    }

    if(GET_DP_RX1_PS_AUX_TOGGLE() == _TRUE)
    {
        DebugMessageRx1("7. Power Saving Aux Handshake", 0);

        return _TRUE;
    }

#if(_DP_MST_SUPPORT == _ON)

    if(ScalerDpRxMstStreamMuxCheck(_DP_ST_SOURCE1) != 0x00)
    {
        return _TRUE;
    }

    if(GET_DP_RX1_AUX_CH_POWER_ON_WAKE_UP() == _TRUE)
    {
        CLR_DP_RX1_AUX_CH_POWER_ON_WAKE_UP();

        return _TRUE;
    }
#endif

    if(((GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS) &&
        ((ScalerDpRx1GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != _BIT1) &&
         (ScalerDpRx1GetDpcdBitInfo(0x00, 0x06, 0x00, (_BIT2 | _BIT1 | _BIT0)) != (_BIT2 | _BIT0)))) ||
       (GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS_VBIOS))
    {
#if((_SLEEP_AUDIO_SUPPORT == _ON) && ((_PS_AUDIO_INPUT == _PS_AUDIO_BOTH) || (_PS_AUDIO_INPUT == _PS_AUDIO_DP)))

        if(ScalerAudioGetDigitalAudioSource(_D1_INPUT_PORT) == _DIGITAL_AUDIO_SOURCE_DP)
        {
            DebugMessageAudio("00. DP Power Saving Audio : Idle Pattern Case", ScalerAudioGetDigitalAudioSource(_D1_INPUT_PORT));
            return _TRUE;
        }
#endif
        DebugMessageRx1("7. Idle Pattern Case", 0);

        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Set DP Lane Mapping Type
// Input Value  : ucLanetype --> Lane Mapping Type
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetDpLaneMapping(BYTE ucLanetype)
{
    if(ucLanetype == _DP_LANE_MAPPING_TYPE_C_ASSIGNMENT_E_TYPE)
    {
        // Lane 0 <--> Lane 2
        // Lane 1 <--> Lane 3
        SET_DP_RX1_PCB_LANE0_MAPPING(_D1_DP_PCB_LANE2_MAPPING);
        SET_DP_RX1_PCB_LANE1_MAPPING(_D1_DP_PCB_LANE3_MAPPING);
        SET_DP_RX1_PCB_LANE2_MAPPING(_D1_DP_PCB_LANE0_MAPPING);
        SET_DP_RX1_PCB_LANE3_MAPPING(_D1_DP_PCB_LANE1_MAPPING);
        SET_DP_RX1_PCB_LANE0_PN_SWAP(!_D1_DP_PCB_LANE0_PN_SWAP);
        SET_DP_RX1_PCB_LANE1_PN_SWAP(!_D1_DP_PCB_LANE1_PN_SWAP);
        SET_DP_RX1_PCB_LANE2_PN_SWAP(!_D1_DP_PCB_LANE2_PN_SWAP);
        SET_DP_RX1_PCB_LANE3_PN_SWAP(!_D1_DP_PCB_LANE3_PN_SWAP);

        // Enable Aux Digital Phy PN Swap
        ScalerSetBit(PBA_72_AUX_DIG_PHY2, ~_BIT0, _BIT0);
    }
    else // Normal Cable Mode
    {
        SET_DP_RX1_PCB_LANE0_MAPPING(_D1_DP_PCB_LANE0_MAPPING);
        SET_DP_RX1_PCB_LANE1_MAPPING(_D1_DP_PCB_LANE1_MAPPING);
        SET_DP_RX1_PCB_LANE2_MAPPING(_D1_DP_PCB_LANE2_MAPPING);
        SET_DP_RX1_PCB_LANE3_MAPPING(_D1_DP_PCB_LANE3_MAPPING);
        SET_DP_RX1_PCB_LANE0_PN_SWAP(_D1_DP_PCB_LANE0_PN_SWAP);
        SET_DP_RX1_PCB_LANE1_PN_SWAP(_D1_DP_PCB_LANE1_PN_SWAP);
        SET_DP_RX1_PCB_LANE2_PN_SWAP(_D1_DP_PCB_LANE2_PN_SWAP);
        SET_DP_RX1_PCB_LANE3_PN_SWAP(_D1_DP_PCB_LANE3_PN_SWAP);

        // Disable Aux Digital Phy PN Swap
        ScalerSetBit(PBA_72_AUX_DIG_PHY2, ~_BIT0, 0x00);
    }
}

//--------------------------------------------------
// Description  : Dp Secondary Data Reset
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SecDataBlockReset(void)
{
    // Set S code by FW manual
    ScalerSetBit(PB9_58_SCODE_0, ~_BIT7, _BIT7);

    // Sec Data Block Reset
    ScalerSetBit(PB8_00_MAC_DIG_RESET_CTRL, ~_BIT4, _BIT4);
    ScalerSetBit(PB8_00_MAC_DIG_RESET_CTRL, ~_BIT4, 0x00);

    // Set S code by HW auto
    ScalerSetBit(PB9_58_SCODE_0, ~_BIT7, 0x00);
}
//--------------------------------------------------
// Description  : Set DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetDpcdBitValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucNotDpcdBit, BYTE ucDpcdBit)
{
    // Release Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerSetByte(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);
    ScalerSetBit(PBA_C4_DPCD_DATA_PORT, ~(~ucNotDpcdBit), ucDpcdBit);
}
//--------------------------------------------------
// Description  : Set DPCD Table Information
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                ucDpcdValue --> DPCD Value
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SetDpcdValue(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucDpcdValue)
{
    // Release Aux
    ScalerSetBit(PBA_C0_DPCD_CTRL, ~_BIT7, 0x00);

    ScalerSetByte(PBA_C1_DPCD_ADDR_PORT_H, ucDpcdAccessPortH);
    ScalerSetByte(PBA_C2_DPCD_ADDR_PORT_M, ucDpcdAccessPortM);
    ScalerSetByte(PBA_C3_DPCD_ADDR_PORT_L, ucDpcdAccessPortL);
    ScalerSetByte(PBA_C4_DPCD_DATA_PORT, ucDpcdValue);
}
//--------------------------------------------------
// Description  : DP Sink Status Setting
// Input Value  : Receive Port, Sync Status
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1SinkStatusSet(EnumDpSinkReceivePort enumReceiverPort, EnumDpSinkStatus enumInSync)
{
    if(enumInSync == _DP_SINK_IN_SYNC)
    {
        if(enumReceiverPort == _DP_SINK_REVEICE_PORT0)
        {
            // Set Receive Port 0 in Sync
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x05) | _BIT0));
        }
        else if(enumReceiverPort == _DP_SINK_REVEICE_PORT1)
        {
            // Set Receive Port 1 in Sync
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x05) | _BIT1));
        }
    }
    else
    {
        if(enumReceiverPort == _DP_SINK_REVEICE_PORT0)
        {
            // Set Receive Port 0 Out of Sync
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x05) & ~_BIT0));
        }
        else if(enumReceiverPort == _DP_SINK_REVEICE_PORT1)
        {
            // Set Receive Port 1 Out of Sync
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x05, (ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x05) & ~_BIT1));
        }
    }
}
//--------------------------------------------------
// Description  : Check ScalerDpRx1ValidSignalDetection Process @ DC ON
// Input Value  : None
// Output Value : _TRUE -> Process / _FALSE -> Not Process
//--------------------------------------------------
bit ScalerDpRx1ValidSignalDetectionDCOnCheck(void)
{
    if((GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE) && (ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) == 0x00) && ((ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x11) & 0x03) != 0x03))
    {
        return _TRUE;
    }

    return _FALSE;
}

#if(_DP_ASSR_MODE_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP ASSR Mode On/ Off
// Input Value  : _ON/ _OFF
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1ASSRModeSetting(void)
{
    if((ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x0A) & _BIT0) == _BIT0)
    {
        // Scramble seed equal to 0xFFFE
        ScalerSetBit(PB0_07_SCRAMBLE_CTRL, ~_BIT4, _BIT4);
    }
    else
    {
        // Scramble seed equal to 0xFFFF
        ScalerSetBit(PB0_07_SCRAMBLE_CTRL, ~_BIT4, 0x00);
    }
}
#endif

#if(_DP_FREESYNC_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP BS to HS Delay Calculation
// Input Value  : None
// Output Value : BS to VS Delay
//--------------------------------------------------
WORD ScalerDpRx1GetBStoHSDelay(WORD usDpHtotal)
{
    WORD usFifoOffset = 0;

    pData[15] = GET_COLOR_DEPTH();

    // DP fifo size = 256 x 96bit
    if(GET_COLOR_SPACE() == _COLOR_SPACE_YCBCR422)
    {
        // FifoOffset = (1/2 * (256 * 96) / (2 * depth per color)), color format is YCbCr 4:2:2
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (4 * (WORD)pData[15]);
    }
    else
    {
        // FifoOffset = (1/2 * (256 * 96) / (3 * depth per color)), color format is RGB or YCbCr 4:4:4 or others
        usFifoOffset = _HW_DP_RX_VIDEO_FIFO_SIZE / (6 * (WORD)pData[15]);
    }

    // Get Hstart
    ScalerRead(PB8_43_MN_DPF_HST_M, 2, &pData[0], _AUTOINC);

    // Get Hactive
    ScalerRead(PB8_45_MN_DPF_HWD_M, 2, &pData[2], _AUTOINC);

    // H Blanking = HTotal - HActive
    PDATA_WORD(2) = usDpHtotal - PDATA_WORD(1);

    // Set BS to HS delay to (HBlanking + 1/2 FIFO - HStart), BS2HS delay: 2 pixel mode
    return ((WORD)((PDATA_WORD(2) + usFifoOffset - PDATA_WORD(0)) >> 1));
}
//--------------------------------------------------
// Description  : Check FREESYNC Enable
// Input Value  : None
// Output Value : _TRUE: FREESYNC change
//--------------------------------------------------
bit ScalerDpRx1GetFREESYNCStatusChange(void)
{
    if((GET_FREESYNC_ENABLED() == _TRUE) && ((g_stInputTimingData.usVFreq < (_PANEL_FREESYNC_MIN_FRAME_RATE - _FRAME_SYNC_MARGIN)) || (g_stInputTimingData.usVFreq > (_PANEL_FREESYNC_MAX_FRAME_RATE + _FRAME_SYNC_MARGIN))))
    {
        DebugMessageRx1("7.FREESYNC IVF out of panel range", g_stInputTimingData.usVFreq);
        return _TRUE;
    }

    if((bit)(ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x07) & _BIT7) != GET_FREESYNC_ENABLED())
    {
        DebugMessageRx1("7.FREESYNC ignore MSA 0 -> 1", 0);
        return _TRUE;
    }

    if(GET_DP_RX1_FREESYNC_SUPPORT() != GET_FREESYNC_SUPPORT())
    {
        SET_DP_RX_CAPABILITY_SWITCHED();
        SET_DP_RX1_FREESYNC_CAPABILITY_SWITCH();
        SET_DP_RX1_FREESYNC_SUPPORT(GET_FREESYNC_SUPPORT());

        if(GET_FREESYNC_SUPPORT() == _ON)
        {
            pData[0] = ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x07);
            ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x07, (pData[0] | _BIT6));
        }
        else
        {
            pData[0] = ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x07);
            ScalerDpRx1SetDpcdValue(0x00, 0x00, 0x07, (pData[0] & ~_BIT6));
        }

        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Get Current DP H Period
// Input Value  : None
// Output Value : H period in nano sec
//--------------------------------------------------
WORD ScalerDpRx1GetHPeriod(void)
{
    // Pop up The result
    ScalerSetBit(PB8_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    // HBs2Bs count in Link Clk / 2
    PDATA_DWORD(0) = (((WORD)ScalerGetByte(PB8_5B_MN_MEAS_HLN_M)) << 8) | (ScalerGetByte(PB8_5C_MN_MEAS_HLN_L));

    return ((PDATA_DWORD(0) * 1000) / (ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) * 27 / 2));
}
//--------------------------------------------------
// Description  : Get Current DP H Sync Width
// Input Value  : None
// Output Value : H Sync Width in pixel clk
//--------------------------------------------------
WORD ScalerDpRx1GetHSW(void)
{
    return ((((WORD)ScalerGetByte(PB8_47_MN_DPF_HSW_M) << 8) | (ScalerGetByte(PB8_48_MN_DPF_HSW_L))) & 0x7FFF);
}
//--------------------------------------------------
// Description  : Get Current DP V Freq
// Input Value  : None
// Output Value : VFreq in 0.1Hz
//--------------------------------------------------
WORD ScalerDpRx1GetVFreq(void)
{
    // Pop up The result
    ScalerSetBit(PB8_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    PDATA_DWORD(0) = ((((DWORD)(ScalerGetByte(PB8_58_MN_MEAS_CTRL) & 0x1F)) << 16) | (((DWORD)ScalerGetByte(PB8_59_MN_MEAS_VLN_M)) << 8) | ((DWORD)ScalerGetByte(PB8_5A_MN_MEAS_VLN_L)));

    return (DWORD)_GDI_CLK_KHZ * 1000 / (PDATA_DWORD(0) / 10);
}
//--------------------------------------------------
// Description  : Get Current DP V Period
// Input Value  : None
// Output Value : V period in line
//--------------------------------------------------
WORD ScalerDpRx1GetVPeriod(void)
{
    DWORD ulVBs2BsCount = 0;
    WORD usHBs2BsCount = 0;

    // Pop up The result
    ScalerSetBit(PB8_58_MN_MEAS_CTRL, ~_BIT5, _BIT5);

    // VBs2BS count in GDI clk
    ulVBs2BsCount = ((((DWORD)(ScalerGetByte(PB8_58_MN_MEAS_CTRL) & 0x1F)) << 16) | (((DWORD)ScalerGetByte(PB8_59_MN_MEAS_VLN_M)) << 8) | ((DWORD)ScalerGetByte(PB8_5A_MN_MEAS_VLN_L)));

    // HBs2Bs count in Link Clk / 2
    usHBs2BsCount = (((DWORD)ScalerGetByte(PB8_5B_MN_MEAS_HLN_M)) << 8) | ((DWORD)ScalerGetByte(PB8_5C_MN_MEAS_HLN_L));

    // VTotal in line, Link Clk / 2 : (Link Rate * 27 / 2)
    return (ulVBs2BsCount * (ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x00) * 27 / 2) / usHBs2BsCount * 1000 / _GDI_CLK_KHZ);
}
#endif

#if(_DP_MST_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Rx Aux Ch Power Status Check
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1AuxChPowerStatusCheck(bit bCableStatus)
{
    if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
    {
        if(bCableStatus == _TRUE)
        {
            if(PCB_D1_HOTPLUG_DETECT() == _D1_HOT_PLUG_HIGH)
            {
                // Whether to Start Debounce
                if((GET_PCB_D1_DP_SOURCE_POWER() == _OFF) &&
                   (GET_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE() == _FALSE) &&
                   (GET_DP_RX1_CHECK_AUX_CH_POWER_OFF() == _FALSE))
                {
                    SET_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE();

                    ScalerTimerActiveTimerEvent(SEC(0.2), _SCALER_TIMER_EVENT_DP_RX1_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                }

                // Debouncing
                if(GET_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE() == _TRUE)
                {
                    if(GET_PCB_D1_DP_SOURCE_POWER() == _ON)
                    {
                        CLR_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
                        ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
                    }
                }

                // Enable 1.5s Hotplug when Source Power On
                if((GET_DP_RX1_CHECK_AUX_CH_POWER_OFF() == _TRUE) && (GET_PCB_D1_DP_SOURCE_POWER() == _ON))
                {
                    CLR_DP_RX1_CHECK_AUX_CH_POWER_OFF();

                    SET_DP_RX1_AUX_CH_POWER_ON_WAKE_UP();

                    SET_DP_RX1_SOURCE_FIRST_POWER_ON();

                    ScalerDpMstReset(g_enumDpMSTCapablePort);

                    ScalerDpRx1HotPlugEvent(_DP_HPD_LOW);

                    ScalerTimerActiveTimerEvent(SEC(1.5), _SCALER_TIMER_EVENT_DP_RX1_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);

#if(_DP_TX_SUPPORT == _ON)

                    if((GET_DP_TX_DOWNSTREAM_DPPLUG_STATUS() == _DP_PLUG) && (GET_DP_TX_DOWNSTREAM_MSGCAP_STATUS() == _DP_MSG_SUPPORT))
                    {
                        // Clear Payload ID Only if Downstream PID Table is Not Empty
                        if(ScalerDpTxAuxNativeRead(0x00, 0x02, 0xC1, 1, pData) == _TRUE)
                        {
                            if(pData[0] != 0x00)
                            {
                                // Set Flag to Gen Clear ID Table Msg
                                SET_DP_GEN_DOWN_REQUEST_MSG(_DP_MSG_CLEAR_PAYLOAD_ID_TABLE);
                            }
                        }
                        else
                        {
                            // Set Flag to Gen Clear ID Table Msg
                            SET_DP_GEN_DOWN_REQUEST_MSG(_DP_MSG_CLEAR_PAYLOAD_ID_TABLE);
                        }
                    }
#endif
                }
            }
        }
        else
        {
            CLR_DP_RX1_CHECK_AUX_CH_NO_POWER_DEBOUNCE();
            CLR_DP_RX1_CHECK_AUX_CH_POWER_OFF();

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_NO_POWER_CHECK_DEBOUNCE);
            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_AUX_CH_POWER_ON_WAIT_HOTPLUG_HIGH);
        }
    }
}
//--------------------------------------------------
// Description  : Backup MST Info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1MstInfoBackup(EnumDpMstBackup enumDpMstBackup)
{
    switch(enumDpMstBackup)
    {
        case _DP_MST_BACKUP_INFO:

            if((ScalerGetBit(PB0_01_PHY_DIG_RESET_CTRL, _BIT7) == _BIT7) &&
               (GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_FAKE_LINK_TRAINING_PASS))
            {
                // Backup MST Enable
                g_stDpRx1MiscInfo.b1DpMstEnableBackup = _TRUE;

                // Backup TimeSlot Info
                g_pucDpRx1MstTimeSlotBackup[0] = ScalerGetByte(PB8_03_STHD_CTRL_2);
                g_pucDpRx1MstTimeSlotBackup[1] = ScalerGetByte(PB8_04_STHD_CTRL_3);
                g_pucDpRx1MstTimeSlotBackup[2] = ScalerGetByte(PB8_05_STHD_CTRL_4);
                g_pucDpRx1MstTimeSlotBackup[3] = ScalerGetByte(PB8_06_STHD_CTRL_5);
                g_pucDpRx1MstTimeSlotBackup[4] = ScalerGetByte(PB8_07_STHD_CTRL_6);
                g_pucDpRx1MstTimeSlotBackup[5] = ScalerGetByte(PB8_08_STHD_CTRL_7);
                g_pucDpRx1MstTimeSlotBackup[6] = ScalerGetByte(PB8_09_STHD_CTRL_8);
                g_pucDpRx1MstTimeSlotBackup[7] = ScalerGetByte(PB8_0A_STHD_CTRL_9);
                g_pucDpRx1MstTimeSlotBackup[8] = ScalerGetByte(PB8_0B_STHD_CTRL_10);
                g_pucDpRx1MstTimeSlotBackup[9] = ScalerGetByte(PB8_0C_STHD_CTRL_11);
                g_pucDpRx1MstTimeSlotBackup[10] = ScalerGetByte(PB8_0D_SOURCE_SEL_0);
                g_pucDpRx1MstTimeSlotBackup[11] = ScalerGetByte(PB8_0E_SOURCE_SEL_1);
                g_pucDpRx1MstTimeSlotBackup[12] = ScalerGetByte(PB8_0F_SOURCE_SEL_2);
            }

            break;

        case _DP_MST_BACKUP_INFO_RESTORE:

            if(((ScalerDpRx1GetDpcdInfo(0x00, 0x00, 0x21) & _BIT0) == _BIT0) && (g_stDpRx1MiscInfo.b1DpMstEnableBackup == _TRUE))
            {
                // Enable MST Decode
                ScalerSetBit(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT7, _BIT7);

                // Restore TimeSlot Info
                ScalerSetByte(PB8_03_STHD_CTRL_2, g_pucDpRx1MstTimeSlotBackup[0]);
                ScalerSetByte(PB8_04_STHD_CTRL_3, g_pucDpRx1MstTimeSlotBackup[1]);
                ScalerSetByte(PB8_05_STHD_CTRL_4, g_pucDpRx1MstTimeSlotBackup[2]);
                ScalerSetByte(PB8_06_STHD_CTRL_5, g_pucDpRx1MstTimeSlotBackup[3]);
                ScalerSetByte(PB8_07_STHD_CTRL_6, g_pucDpRx1MstTimeSlotBackup[4]);
                ScalerSetByte(PB8_08_STHD_CTRL_7, g_pucDpRx1MstTimeSlotBackup[5]);
                ScalerSetByte(PB8_09_STHD_CTRL_8, g_pucDpRx1MstTimeSlotBackup[6]);
                ScalerSetByte(PB8_0A_STHD_CTRL_9, g_pucDpRx1MstTimeSlotBackup[7]);
                ScalerSetByte(PB8_0B_STHD_CTRL_10, g_pucDpRx1MstTimeSlotBackup[8]);
                ScalerSetByte(PB8_0C_STHD_CTRL_11, g_pucDpRx1MstTimeSlotBackup[9]);
                ScalerSetByte(PB8_0D_SOURCE_SEL_0, g_pucDpRx1MstTimeSlotBackup[10]);
                ScalerSetByte(PB8_0E_SOURCE_SEL_1, g_pucDpRx1MstTimeSlotBackup[11]);
                ScalerSetByte(PB8_0F_SOURCE_SEL_2, g_pucDpRx1MstTimeSlotBackup[12]);
            }

            g_stDpRx1MiscInfo.b1DpMstEnableBackup = _FALSE;

            break;

        case _DP_MST_BACKUP_INFO_RESET:
        default:

            g_stDpRx1MiscInfo.b1DpMstEnableBackup = _FALSE;

            break;
    }
}

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Dp Rx HDCP - SHA circuit Run
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPAuthShaRun(bit bIsFirst)
{
    // Set First Run For SHA-1 Circuit
    ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT1, ((bIsFirst == _TRUE) ? _BIT1 : 0x00));

    // Run SHA-1 Circuit
    ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT2, _BIT2);

    ScalerTimerPollingFlagProc(5, PB0_30_SHA_CONTRL, _BIT4, _TRUE);

    // Disable First Run and Disable SHA-1 Circuit
    ScalerSetBit(PB0_30_SHA_CONTRL, ~(_BIT2 | _BIT1), 0x00);
}

#if(_D1_DP_MST_PORT_SUPPORT == _ON)
//--------------------------------------------------
// Description  : Upplug Reset For Dp Rx1
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPBlockReset(void)
{
    // Reset HDCP Block
    ScalerSetBit(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT0, _BIT0);
    ScalerSetBit(PB0_01_PHY_DIG_RESET_CTRL, ~_BIT0, 0x00);

    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x29, 0x00);
    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x2A, 0x00);
    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x2B, 0x00);

    for(pData[0] = 0; pData[0] < 20; pData[0]++)
    {
        ScalerDpRx1SetDpcdValue(0x06, 0x80, (0x14 + pData[0]), 0x00);
    }

    for(pData[0] = 0; pData[0] < 15; pData[0]++)
    {
        ScalerDpRx1SetDpcdValue(0x06, 0x80, (0x2C + pData[0]), 0x00);
    }

    ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_IDLE);
}
#endif

//--------------------------------------------------
// Description  : Change HDCP Auth State
// Input Value  : Target HDCP Auth State
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPChangeAuthState(EnumDPRxHDCPAuthState enumHDCPAuthState)
{
    SET_DP_RX1_HDCP_AUTH_STATE(enumHDCPAuthState);
    SET_DP_RX1_HDCP_AUTH_STATE_CHANGE();
}
//--------------------------------------------------
// Description  : Check B info
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx1HDCPCheckBinfo(void)
{
    BYTE ucBInfoDevice = 0;
    BYTE ucBInfoDepth = 0;

    if(GET_DP_TX_HDCP_DOWNSTREAM_SUPPORTED() == _TRUE)
    {
        if(GET_DP_TX_HDCP_DOWNSTREAM_REPEATER() == _TRUE)
        {
            ucBInfoDevice = (GET_DP_TX_HDCP_DOWNSTREAM_DEVICE_COUNT() <= 125) ? GET_DP_TX_HDCP_DOWNSTREAM_DEVICE_COUNT() : 0x80;
            ucBInfoDepth = (GET_DP_TX_HDCP_DOWNSTREAM_DEPTH() <= 6) ? GET_DP_TX_HDCP_DOWNSTREAM_DEPTH() : 0x08;
        }

        if(ucBInfoDevice != 0x80)
        {
            ucBInfoDevice++;
        }
    }

    if(ucBInfoDevice != 0x80)
    {
        ucBInfoDevice++;
    }

    if(ucBInfoDepth != 0x08)
    {
        ucBInfoDepth++;
    }

    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x2A, ucBInfoDevice);
    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x2B, ucBInfoDepth);

    if((ucBInfoDevice == 0x80) || (ucBInfoDepth == 0x08))
    {
        return _FALSE;
    }

    return _TRUE;
}
//--------------------------------------------------
// Description  : Check Dp Rx HDCP Link Veriffication Pattern (0x531F) for MST Mode
// Input Value  : None
// Output Value : None
//--------------------------------------------------
bit ScalerDpRx1HDCPCheckLvp(void)
{
    if(((ScalerGetByte(PB0_1E_HDCP_INTGT_VRF_ANS_MSB) == 0x53) || (ScalerGetByte(PB0_1E_HDCP_INTGT_VRF_ANS_MSB) == 0x00)) &&
       ((ScalerGetByte(PB0_1F_HDCP_INTGT_VRF_ANS_LSB) == 0x1F) || (ScalerGetByte(PB0_1F_HDCP_INTGT_VRF_ANS_LSB) == 0x00)))
    {
        return _TRUE;
    }

    return _FALSE;
}
//--------------------------------------------------
// Description  : Fake HDCP Authentication
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPFakeAuthenProc(void)
{
    BYTE pucSHAInput[64];

    // Set Device Count and Depth
    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x2A, 0x01);
    ScalerDpRx1SetDpcdValue(0x06, 0x80, 0x2B, 0x01);

    // Load KSV
    memcpy(pucSHAInput, g_pucHdcpAksvBackup, 5);

    // Load Device Count and Depth
    pucSHAInput[5] = ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2A);
    pucSHAInput[6] = ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2B);

    // Load M0'
    for(pData[0] = 0; pData[0] < 8; pData[0]++)
    {
        pucSHAInput[7 + pData[0]] = ScalerGetByte(PB0_2F_M0_BYTE_0 - pData[0]);
    }

    memset(&pucSHAInput[15], 0, 49);

    pucSHAInput[15] = 0x80;

    // Total bit numbers of SHA-1 input = KSV FIFO + B_info + M0'
    pucSHAInput[63] = 0x78;

    // Compute V'
    ScalerDpRx1HDCPSha1Calculate(pucSHAInput, 0);

    // Write Ksv to DPCD table
    SET_DP_RX1_AUX_MANUAL_MODE();

    for(pData[0] = 0; pData[0] < 15; pData[0]++)
    {
        if(pData[0] < 5)
        {
            ScalerDpRx1SetDpcdValue(0x06, 0x80, (0x2C + pData[0]), g_pucHdcpAksvBackup[pData[0]]);
        }
        else
        {
            ScalerDpRx1SetDpcdValue(0x06, 0x80, (0x2C + pData[0]), 0x00);
        }
    }

    SET_DP_RX1_AUX_AUTO_MODE();

    // Write V' to DPCD table
    ScalerDpRx1HDCPLoadShaToDpcd();
}
//--------------------------------------------------
// Description  : Dp Rx HDCP Auth Handler
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPHandler(void)
{
    CLR_DP_RX1_HDCP_UPSTREAM_EVENT();

    if(GET_DP_RX1_HDCP_REPEATER_SUPPORT() == _TRUE)
    {
        // After receiving AKSV, handler must initialize authentication
        if(GET_DP_RX1_HDCP_AUTH_AKSV_WRITTEN() == _TRUE)
        {
            CLR_DP_RX1_HDCP_AUTH_AKSV_WRITTEN();
            CLR_DP_RX1_HDCP_AUTH_CPIRQ_TIMRE();

            ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_IDLE);

            ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_CPIRQ_EVENT);
        }

        if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D1_PORT)
        {
            // In MST mode
            if((ScalerDpRx1GetDpcdInfo(0x00, 0x01, 0x11) & _BIT0) == _BIT0)
            {
                if((ScalerDpRx1HdcpEnebled() == _TRUE) && (GET_DP_RX1_HDCP_AUTH_CPIRQ_TIMRE() == _FALSE))
                {
                    if(ScalerDpRx1HDCPCheckLvp() == _FALSE)
                    {
                        SET_DP_RX1_HDCP_AUTH_CPIRQ_TIMRE();

                        ScalerDpRx1CpIRQ(_DP_HDCP_BSTATUS_LINK_INTEGRITY_FAIL);

                        ScalerTimerActiveTimerEvent(SEC(0.02), _SCALER_TIMER_EVENT_DP_RX1_HDCP_CPIRQ_EVENT);
                    }
                }
            }
            else
            {
                // In SST mode, issue HPD event for upstream device if DPTX connect a new downstream device.
                if((ScalerDpRx1HdcpEnebled() == _TRUE) && (ScalerDpRx1HDCPCheckLvp() == _TRUE))
                {
                    if(GET_DP_TX_HDCP_DOWNSTREAM_EVENT() == _DP_TX_HDCP_DOWNSTREAM_AUTH_EVENT_REAUTH)
                    {
                        ScalerDpRx1HotPlugEvent(_DP_HDCP_LONG_HPD_EVENT);
                    }
                }
            }
        }

        if((GET_DP_RX1_HDCP_AUTH_STATE() != _DP_RX_HDCP_STATE_IDLE) && (GET_DP_RX1_LINK_TRAINING_STATUS() == _DP_LINK_TRAINING_NONE))
        {
            ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_IDLE);
        }
    }

    switch(GET_DP_RX1_HDCP_AUTH_STATE())
    {
        case _DP_RX_HDCP_STATE_IDLE:

            if(GET_DP_RX1_HDCP_AUTH_STATE_CHANGE() == _TRUE)
            {
                CLR_DP_RX1_HDCP_AUTH_STATE_CHANGE();
                CLR_DP_RX1_HDCP_AUTH_REPEATER_PROC_TIMEOUT();
                CLR_DP_RX1_HDCP_AUTH_CPIRQ_TIMRE();

                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_REPEATER_PROC_TIMEOUT);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_READ_IRQ_TIMEOUT);
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_CPIRQ_EVENT);

                ScalerDpRx1HDCPEnableReadIrq(_DISABLE);

                SET_DP_RX1_HDCP_UPSTREAM_EVENT(_DP_RX_HDCP_UPSTREAM_AUTH_EVENT_STOP_ENCRYPTION);
            }

            if(GET_DP_RX1_HDCP_REPEATER_SUPPORT() == _TRUE)
            {
                // Check if R0' was read already by upstream device.
                if((ScalerGetBit(PB0_20_HDCP_DEBUG, (_BIT7 | _BIT5)) == (_BIT7 | _BIT5)) &&
                   ((ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x05) != 0x00) || (ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x06) != 0x00)) &&
                   ((ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x29) & _DP_HDCP_BSTATUS_R0_AVAILABLE) == 0x00))
                {
                    ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_1);
                }
            }

            break;

        case _DP_RX_HDCP_STATE_AUTH_1:

            if(GET_DP_RX1_HDCP_AUTH_STATE_CHANGE() == _TRUE)
            {
                CLR_DP_RX1_HDCP_AUTH_STATE_CHANGE();

                if(GET_DP_RX_HDCP_UPSTREAM_PORT() == _HDCP_D1_PORT)
                {
                    // Check if downstream device support HDCP capability.
                    if(GET_DP_TX_HDCP_DOWNSTREAM_SUPPORTED() == _TRUE)
                    {
                        // Issue event to make DPTX start HDCP handshake.
                        SET_DP_RX1_HDCP_UPSTREAM_EVENT(_DP_RX_HDCP_UPSTREAM_AUTH_EVENT_R0_PASS);

                        ScalerTimerActiveTimerEvent(SEC(6), _SCALER_TIMER_EVENT_DP_RX1_HDCP_REPEATER_PROC_TIMEOUT);
                    }
                    else
                    {
                        ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_2);
                    }
                }
                else
                {
                    ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_FAKE);
                }
            }

            // Wait for downstream pass event or device/depth max event
            if((GET_DP_TX_HDCP_DOWNSTREAM_EVENT() == _DP_TX_HDCP_DOWNSTREAM_AUTH_EVENT_PASS) ||
               (GET_DP_TX_HDCP_DOWNSTREAM_EVENT() == _DP_TX_HDCP_DOWNSTREAM_AUTH_EVENT_DEVICE_DEPTH_MAX))
            {
                ScalerTimerCancelTimerEvent(_SCALER_TIMER_EVENT_DP_RX1_HDCP_REPEATER_PROC_TIMEOUT);

                ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_2);
            }
            else if(GET_DP_RX1_HDCP_AUTH_REPEATER_PROC_TIMEOUT() == _TRUE)
            {
                CLR_DP_RX1_HDCP_AUTH_REPEATER_PROC_TIMEOUT();

                SET_DP_RX1_HDCP_UPSTREAM_EVENT(_DP_RX_HDCP_UPSTREAM_AUTH_EVENT_TIMEOUT);

                ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_DONE);
            }

            break;

        case _DP_RX_HDCP_STATE_AUTH_2:

            if(GET_DP_RX1_HDCP_AUTH_STATE_CHANGE() == _TRUE)
            {
                CLR_DP_RX1_HDCP_AUTH_STATE_CHANGE();
            }

            if(ScalerDpRx1HDCPCheckBinfo() == _TRUE)
            {
                // Load KSV List to RX KSV FIFO
                ScalerDpRx1HDCPLoadKsvFifo();

                // Input KSV FIFO to SHA-1 and Compute V'
                ScalerDpRx1HDCPWriteShaInput();

                // Write V' into DPCD table
                ScalerDpRx1HDCPLoadShaToDpcd();

                // Set 1st KSV FIFO to DPCD table
                ScalerDpRx1HDCPSetKsvFifoFirst();

                // Enable 68xxx Read INT
                ScalerDpRx1HDCPEnableReadIrq(_ENABLE);

                ScalerTimerActiveTimerEvent(SEC(5), _SCALER_TIMER_EVENT_DP_RX1_HDCP_READ_IRQ_TIMEOUT);
            }

            // Set V' Ready Bit and Issue CP_IRQ
            ScalerDpRx1CpIRQ(_DP_HDCP_BSTATUS_V_READY);

            ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_DONE);

            break;

        case _DP_RX_HDCP_STATE_AUTH_FAKE:

            if(GET_DP_RX1_HDCP_AUTH_STATE_CHANGE() == _TRUE)
            {
                CLR_DP_RX1_HDCP_AUTH_STATE_CHANGE();
            }

            // Enable 68xxx Read INT
            ScalerDpRx1HDCPEnableReadIrq(_DISABLE);

            // Fake Authentication
            ScalerDpRx1HDCPFakeAuthenProc();

            // Set V' Ready Bit and Issue CP_IRQ
            ScalerDpRx1CpIRQ(_DP_HDCP_BSTATUS_V_READY);

            ScalerDpRx1HDCPChangeAuthState(_DP_RX_HDCP_STATE_AUTH_DONE);

            break;

        case _DP_RX_HDCP_STATE_AUTH_DONE:

            if(GET_DP_RX1_HDCP_AUTH_STATE_CHANGE() == _TRUE)
            {
                CLR_DP_RX1_HDCP_AUTH_STATE_CHANGE();
            }

            if(GET_DP_RX1_HDCP_AUTH_READ_IRQ_TIMEOUT() == _TRUE)
            {
                ScalerDpRx1HDCPEnableReadIrq(_DISABLE);
            }

            break;

        default:

            break;
    }
}
//--------------------------------------------------
// Description  : Load KSV List to Rx KSV FIFO
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPLoadKsvFifo(void)
{
    PDATA_WORD(0) = 0;
    PDATA_WORD(1) = 0;

    if(GET_DP_TX_HDCP_DOWNSTREAM_SUPPORTED() == _TRUE)
    {
        if(GET_DP_TX_HDCP_DOWNSTREAM_REPEATER() == _TRUE)
        {
            PDATA_WORD(1) = (WORD) GET_DP_TX_HDCP_DOWNSTREAM_DEVICE_COUNT() * 5;
        }

        ScalerRead(PBB_4F_BKSV_0, 5, &pData[4], _AUTOINC);

        // Load BKSV of Downstream into KSV FIFO
        for(PDATA_WORD(0) = 0; PDATA_WORD(0) < 5; PDATA_WORD(0)++)
        {
            g_pucDpTxHdcpKsvFifo[PDATA_WORD(1)] = pData[4 + PDATA_WORD(0)];

            PDATA_WORD(1)++;
        }
    }

    // Load KSV of TX into KSV FIFO
    for(PDATA_WORD(0) = 0; PDATA_WORD(0) < 5; PDATA_WORD(0)++)
    {
        g_pucDpTxHdcpKsvFifo[PDATA_WORD(1)] = g_pucHdcpAksvBackup[PDATA_WORD(0)];

        PDATA_WORD(1)++;
    }

    for(PDATA_WORD(0) = PDATA_WORD(1); PDATA_WORD(0) < ((WORD) _DP_TX_HDCP_DEVICE_COUNT_MAX * 5); PDATA_WORD(0)++)
    {
        g_pucDpTxHdcpKsvFifo[PDATA_WORD(0)] = 0x00;
    }
}
//--------------------------------------------------
// Description  : Dp Rx HDCP - Load SHA Result to DPCD table
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPLoadShaToDpcd(void)
{
    SET_DP_RX1_AUX_MANUAL_MODE();

    for(pData[0] = 0; pData[0] < 5; pData[0]++)
    {
        for(pData[1] = 0; pData[1] < 4; pData[1]++)
        {
            ScalerDpRx1SetDpcdValue(0x06, 0x80, (0x14 + (pData[0] * 4) + pData[1]), ScalerGetByte(PB0_39_SHA_3 + (pData[0] * 4) - pData[1]));
        }
    }

    SET_DP_RX1_AUX_AUTO_MODE();
}
//--------------------------------------------------
// Description  : Load KSV List to Rx KSV FIFO
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPSetKsvFifoFirst(void)
{
    SET_DP_RX1_AUX_MANUAL_MODE();

    for(g_usDpRx1HdcpKsvFifoOffset = 0; g_usDpRx1HdcpKsvFifoOffset < 15; g_usDpRx1HdcpKsvFifoOffset++)
    {
        ScalerDpRx1SetDpcdValue(0x06, 0x80, (0x2C + g_usDpRx1HdcpKsvFifoOffset), g_pucDpTxHdcpKsvFifo[g_usDpRx1HdcpKsvFifoOffset]);
    }

    // Aux HW Control
    SET_DP_RX1_AUX_AUTO_MODE();
}
//--------------------------------------------------
// Description  : Set HDCP Read IRQ Timeout
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPSetReadIrqTimeout(void)
{
    SET_DP_RX1_HDCP_AUTH_READ_IRQ_TIMEOUT();
}
//--------------------------------------------------
// Description  : Set HDCP Repeater Proc Timeout
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPSetRepeaterProcTimeout(void)
{
    SET_DP_RX1_HDCP_AUTH_REPEATER_PROC_TIMEOUT();
}
//--------------------------------------------------
// Description  : Calculate SHA-1 Input
// Input Value  : Inpute Array, First Run
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPSha1Calculate(BYTE *pucInputArray, BYTE ucCalCount)
{
    // Reset SHA Block counter
    ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT3, _BIT3);

    // Start to Write SHA-1 Transform Input
    ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT3, 0x00);

    // Write SHA-1 Input Data, Total 512 bits
    for(pData[1] = 0; pData[1] < 16; pData[1]++)
    {
        ScalerSetByte(PB0_31_SHA_DATA1, pucInputArray[pData[1] * 4]);
        ScalerSetByte(PB0_32_SHA_DATA2, pucInputArray[1 + pData[1] * 4]);
        ScalerSetByte(PB0_33_SHA_DATA3, pucInputArray[2 + pData[1] * 4]);
        ScalerSetByte(PB0_34_SHA_DATA4, pucInputArray[3 + pData[1] * 4]);

        // Enable write 32-bit data to SHA-1 block
        ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);
    }

    ScalerDpRx1HDCPAuthShaRun(((ucCalCount == 0x00) ? _TRUE : _FALSE));
}
//--------------------------------------------------
// Description  : Load KSV FIFO to SHA-1 Input
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1HDCPWriteShaInput(void)
{
    WORD usKsvFifoLength = 0;
    WORD usShaInputBitNumbers = 0;
    WORD usKsvLengthTemp = 0;

    usKsvFifoLength = (WORD) ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2A) * 5;

    // Total bit numbers of SHA-1 input = KSV FIFO + B_info + M0'
    usShaInputBitNumbers = (usKsvFifoLength + 2 + 8) * 8;

    // Reset SHA Block counter
    ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT3, _BIT3);

    // Start to Write SHA-1 Transform Input
    ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT3, 0x00);

    // Write the KSV List into SHA-1 Transform Input
    do
    {
        ScalerSetByte(PB0_31_SHA_DATA1, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp]);
        ScalerSetByte(PB0_32_SHA_DATA2, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp + 1]);
        ScalerSetByte(PB0_33_SHA_DATA3, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp + 2]);
        ScalerSetByte(PB0_34_SHA_DATA4, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp + 3]);

        // Enable write 32-bit data to SHA-1 block
        ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

        usKsvLengthTemp += 4;

        if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
        {
            ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
        }
    }
    while((usKsvFifoLength - usKsvLengthTemp) >= 4);

    // Write the remaining KSV, B info and M0' into SHA-1 Transform Input
    switch(usKsvFifoLength - usKsvLengthTemp)
    {
        case 1:

            ScalerSetByte(PB0_31_SHA_DATA1, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp]);
            ScalerSetByte(PB0_32_SHA_DATA2, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2A));
            ScalerSetByte(PB0_33_SHA_DATA3, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2B));
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_0());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_1());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_2());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_3());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_4());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_5());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_6());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_7());
            ScalerSetByte(PB0_34_SHA_DATA4, 0x80);

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            break;

        case 2:

            ScalerSetByte(PB0_31_SHA_DATA1, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp]);
            ScalerSetByte(PB0_32_SHA_DATA2, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp + 1]);
            ScalerSetByte(PB0_33_SHA_DATA3, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2A));
            ScalerSetByte(PB0_34_SHA_DATA4, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2B));

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_0());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_1());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_2());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_3());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_4());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_5());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_6());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_7());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, 0x80);
            ScalerSetByte(PB0_32_SHA_DATA2, 0x00);
            ScalerSetByte(PB0_33_SHA_DATA3, 0x00);
            ScalerSetByte(PB0_34_SHA_DATA4, 0x00);

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            break;

        case 3:

            ScalerSetByte(PB0_31_SHA_DATA1, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp]);
            ScalerSetByte(PB0_32_SHA_DATA2, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp + 1]);
            ScalerSetByte(PB0_33_SHA_DATA3, g_pucDpTxHdcpKsvFifo[usKsvLengthTemp + 2]);
            ScalerSetByte(PB0_34_SHA_DATA4, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2A));

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2B));
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_0());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_1());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_2());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_3());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_4());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_5());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_6());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_7());
            ScalerSetByte(PB0_32_SHA_DATA2, 0x80);
            ScalerSetByte(PB0_33_SHA_DATA3, 0x00);
            ScalerSetByte(PB0_34_SHA_DATA4, 0x00);

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            break;

        default:

            ScalerSetByte(PB0_31_SHA_DATA1, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2A));
            ScalerSetByte(PB0_32_SHA_DATA2, ScalerDpRx1GetDpcdInfo(0x06, 0x80, 0x2B));
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_0());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_1());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_2());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_3());
            ScalerSetByte(PB0_33_SHA_DATA3, GET_DP_RX1_HDCP_M0_4());
            ScalerSetByte(PB0_34_SHA_DATA4, GET_DP_RX1_HDCP_M0_5());

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            ScalerSetByte(PB0_31_SHA_DATA1, GET_DP_RX1_HDCP_M0_6());
            ScalerSetByte(PB0_32_SHA_DATA2, GET_DP_RX1_HDCP_M0_7());
            ScalerSetByte(PB0_33_SHA_DATA3, 0x80);
            ScalerSetByte(PB0_34_SHA_DATA4, 0x00);

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;

            if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
            {
                ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
            }

            break;
    }

    if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 60)
    {
        ScalerSetByte(PB0_31_SHA_DATA1, 0x00);
        ScalerSetByte(PB0_32_SHA_DATA2, 0x00);
        ScalerSetByte(PB0_33_SHA_DATA3, 0x00);
        ScalerSetByte(PB0_34_SHA_DATA4, 0x00);

        // Enable write 32-bit data to SHA-1 block
        ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

        usKsvLengthTemp += 4;

        if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) == 0)
        {
            ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
        }
    }

    // Write 0x00 into the remaining SHA-1 Transform Input space
    if((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) <= 56)
    {
        while((usKsvLengthTemp % _DP_HDCP_SHA1_INPUT_SIZE) < 56)
        {
            ScalerSetByte(PB0_31_SHA_DATA1, 0x00);
            ScalerSetByte(PB0_32_SHA_DATA2, 0x00);
            ScalerSetByte(PB0_33_SHA_DATA3, 0x00);
            ScalerSetByte(PB0_34_SHA_DATA4, 0x00);

            // Enable write 32-bit data to SHA-1 block
            ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

            usKsvLengthTemp += 4;
        }

        // The length of SHA-1 input is equal to 2^64(8 bytes)
        ScalerSetByte(PB0_31_SHA_DATA1, 0x00);
        ScalerSetByte(PB0_32_SHA_DATA2, 0x00);
        ScalerSetByte(PB0_33_SHA_DATA3, 0x00);
        ScalerSetByte(PB0_34_SHA_DATA4, 0x00);

        // Enable write 32-bit data to SHA-1 block
        ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

        // Write the valid bit numbers into SHA-1 Transform Input
        ScalerSetByte(PB0_31_SHA_DATA1, 0x00);
        ScalerSetByte(PB0_32_SHA_DATA2, 0x00);
        ScalerSetByte(PB0_33_SHA_DATA3, HIBYTE(usShaInputBitNumbers));
        ScalerSetByte(PB0_34_SHA_DATA4, LOBYTE(usShaInputBitNumbers));

        // Enable write 32-bit data to SHA-1 block
        ScalerSetBit(PB0_30_SHA_CONTRL, ~_BIT0, _BIT0);

        usKsvLengthTemp += 8;

        ScalerDpRx1HDCPAuthShaRun((usKsvLengthTemp == _DP_HDCP_SHA1_INPUT_SIZE) ? _TRUE : _FALSE);
    }
}
//--------------------------------------------------
// Description  : Handle DP MST to SST Flow
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1MstToSstProc(void)
{
    if(GET_DP_TX_STREAM_SOURCE() == _DP_TX_SOURCE_NONE)
    {
        if(ScalerDpRx1MstToSstScanInputPort() == _TRUE)
        {
            if(ScalerDpRx1MstToSstMeasureInput() == _TRUE)
            {
                ScalerDpTxSetStreamSource(_DP_TX_SOURCE_MST2SST);
            }
        }
    }
    else
    {
        // Stable Check
        if(ScalerDpRx1MstToSstStableDetect() == _FALSE)
        {
            ScalerDpTxSetStreamSource(_DP_TX_SOURCE_NONE);

            // Disabel MST2SST Watch Dog
            CLR_REG_DP_RX_MST2SST_WATCH_DOG_ENABLE();
        }
    }
}
//--------------------------------------------------
// Description  : DP MST2SST Set Color Info Macros
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1MstToSstSetColorInfo(void)
{
#if(_DP_VSC_SDP_EXT_FOR_COLORIMETRY_SUPPORT == _ON)
    if(GET_DP_TX_VSC_SDP_COLOR_MODE() == _TRUE)
    {
        // Set Color Space Macro
        switch(g_stDpTxColorInfo.ucColorSpacePreValue)
        {
            case _VSC_COLOR_SPACE_0:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_RGB);
                break;

            case _VSC_COLOR_SPACE_1:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
                break;

            case _VSC_COLOR_SPACE_2:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
                break;

            case _VSC_COLOR_SPACE_3:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_YCBCR420);
                break;

            case _VSC_COLOR_SPACE_4:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_Y_ONLY);
                break;

            case _VSC_COLOR_SPACE_5:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_RAW);
                break;

            default:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_RGB);
                break;
        }
    }
    else
#endif
    {
        // Set Color Space Macro
        switch(g_stDpTxColorInfo.ucColorSpacePreValue)
        {
            case _BIT1:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_YCBCR422);
                break;

            case _BIT2:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_YCBCR444);
                break;

            case _BIT7:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_Y_ONLY);
                break;

            case (_BIT7 | _BIT1):
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_RAW);
                break;

            default:
                SET_DP_TX_INPUT_COLOR_SPACE(_COLOR_SPACE_RGB);
                break;
        }
    }

    // Set Porch Color
    if((GET_DP_TX_INPUT_COLOR_SPACE() == _COLOR_SPACE_YCBCR444) || (GET_DP_TX_INPUT_COLOR_SPACE() == _COLOR_SPACE_YCBCR422) || (GET_DP_TX_INPUT_COLOR_SPACE() == _COLOR_SPACE_YCBCR420))
    {
        SET_DP_TX_PORCH_COLOR_YCC_FULL();
    }
    else
    {
        SET_DP_TX_PORCH_COLOR_RGB();
    }

    // Set Color Depth Macro
    SET_DP_TX_INPUT_COLOR_DEPTH(g_stDpTxColorInfo.b3ColorDepthPreValue);
}
//--------------------------------------------------
// Description  : On Line Check DP MST2SST stability
// Input Value  : None
// Output Value : True --> DP MST2SST Stable
//                False --> DP MST2SST Unstable
//--------------------------------------------------
bit ScalerDpRx1MstToSstStableDetect(void)
{
    if(ScalerDpRx1MstToSstMiscCheck() == _FALSE)
    {
        return _FALSE;
    }

    if(ScalerDpRx1MstToSstFifoCheck(_DP_FIFO_POLLING_CHECK) == _FALSE)
    {
        return _FALSE;
    }

    if(ScalerDpRx1MstToSstMSAActiveChange() == _TRUE)
    {
        return _FALSE;
    }

    if(ScalerDpRxMstToSstTxMeasureTimingChange() == _TRUE)
    {
        return _FALSE;
    }

    return _TRUE;
}
#endif

#endif

#if(_DP_TX_SUPPORT == _ON)
//--------------------------------------------------
// Description  : DP Sink Count Update
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1UpdateSinkCount(void)
{
    if(GET_DP_TX_HPD_DEBOUNCE_LEVEL() == _HIGH)
    {
        // Align Reported Cable status with Downstream Port
        SET_DP_RX_REPORT_DOWNSTREAM_DP_CABLE_STATUS(_DP_PLUG);

#if(_DP_MST_SUPPORT == _ON)
        if(g_enumDpMSTCapablePort == _DP_MST_RX1_PORT)
        {
            // Read Sink Count
            if(ScalerDpTxAuxNativeRead(0x00, 0x02, 0x00, 1, pData) == _TRUE)
            {
                // Set Rx Sink Count
                pData[1] = ScalerDpRx1GetDpcdInfo(0x00, 0x02, 0x00);

                // Downstream sink count number plus Branch device itself
                pData[1] = ((pData[1] & _BIT6) | (pData[0] & 0xBF)) + 1;
                ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x00, pData[1]);
            }
            else
            {
                ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x00, 0x41);
            }
        }
        else
#endif // End of #if(_DP_MST_SUPPORT == _ON)
        {
            ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x00, 0x41);
        }
    }
    else
    {
        ScalerDpRx1SetDpcdValue(0x00, 0x02, 0x00, 0x41);

        // Align Reported Cable status with Downstream Port
        SET_DP_RX_REPORT_DOWNSTREAM_DP_CABLE_STATUS(_DP_UNPLUG);
    }
}
#endif // End of #if(_DP_TX_SUPPORT == _ON)

#endif // End of #if(_D1_DP_EXIST == _ON)
