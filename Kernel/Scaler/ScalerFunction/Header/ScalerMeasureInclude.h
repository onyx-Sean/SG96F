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
// ID Code      : ScalerMeasureInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of Measure Clock Frequency
//--------------------------------------------------
#define _MEASURE_CLK_DIV                             (ScalerGetBit(P40_07_MEASURE_CLK_DIVIDER, (_BIT3 | _BIT2 | _BIT1 | _BIT0)))
#define _MEASURE_USE_M2PLL_CLK                       ((bit)ScalerGetBit(P40_07_MEASURE_CLK_DIVIDER, _BIT4) ? _TRUE : _FALSE)
#define _MEASURE_CLK                                 (DWORD)((GET_M2PLL_POWER_STATUS() == _FALSE) ? _EXT_XTAL : (_MEASURE_USE_M2PLL_CLK ? (((DWORD)_M2PLL_CLK_KHZ) / _MEASURE_CLK_DIV) : _EXT_XTAL))

//--------------------------------------------------
// Definitions Of Measure Polling Time
// timeout clk = measure clk / 16384
// timeout = 512 / timeout clock + 10(tolerance) (ms)
// reset time = 1 / timeout clock, with min = 2 (ms)
//--------------------------------------------------
#define _MEASURE_TIMEOUT_CLK                         (_MEASURE_CLK / (16384 / 10)) // (0.1k)
#define _MEASURE_TIMEOUT                             ((WORD)(((DWORD)512 * 10 / _MEASURE_TIMEOUT_CLK) + 10)) // (ms)
#define _MEASURE_RESET_TIME                          ((_MEASURE_TIMEOUT_CLK >= 10) ? 2 : (2 * 10 / _MEASURE_TIMEOUT_CLK)) // (ms)

//--------------------------------------------------
// Definitions of Measure block limitation
//--------------------------------------------------
#define _MEASURE_H_FREQ_MIN                          (_MEASURE_CLK * 10 / (WORD)0x1FFF) // Unit: 0.1k

//--------------------------------------------------
// Macro of Sync Measurement Result
//--------------------------------------------------
#define GET_INPUT_TIMING_H_POLARITY()                (g_stInputTimingData.b1HSP)
#define GET_INPUT_TIMING_V_POLARITY()                (g_stInputTimingData.b1VSP)
#define GET_INPUT_TIMING_INTERLACE_FLG()             (g_stInputTimingData.b1Interlace)
#define GET_INPUT_TIMING_HFREQ()                     (g_stInputTimingData.usHFreq)
#define GET_INPUT_TIMING_HTOTAL()                    (g_stInputTimingData.usHTotal)
#define GET_INPUT_TIMING_HWIDTH()                    (g_stInputTimingData.usHWidth)
#define GET_INPUT_TIMING_HSTART()                    (g_stInputTimingData.usHStart)
#define GET_INPUT_TIMING_HSYNCWIDTH()                (g_stInputTimingData.usHSWidth)
#define GET_INPUT_TIMING_VFREQ()                     (g_stInputTimingData.usVFreq)
#define GET_INPUT_TIMING_VTOTAL()                    (g_stInputTimingData.usVTotal)
#define GET_INPUT_TIMING_VHEIGHT()                   (g_stInputTimingData.usVHeight)
#define GET_INPUT_TIMING_VSTART()                    (g_stInputTimingData.usVStart)
#define GET_INPUT_TIMING_VSYNCWIDTH()                (g_stInputTimingData.usVSWidth)

//--------------------------------------------------
// Macro of Sync Measurement Result
//--------------------------------------------------
#define GET_SYNC_H_POLARITY()                        (g_stMeasureSyncHV.b1HSP)
#define GET_SYNC_V_POLARITY()                        (g_stMeasureSyncHV.b1VSP)
#define GET_SYNC_H_PERIOD()                          (g_stMeasureSyncHV.usHSPeriod)
#define GET_SYNC_H_SYNCWIDTH()                       (g_stMeasureSyncHV.usHSWidth)
#define GET_SYNC_V_PERIOD()                          (g_stMeasureSyncHV.usVSPeriod)
#define GET_SYNC_V_SYNCWIDTH()                       (g_stMeasureSyncHV.usVSWidth)
#define GET_SYNC_H_TOTAL()                           (g_stMeasureSyncHV.usHTotal)
#define GET_SYNC_H_WIDTH()                           (g_stMeasureSyncHV.usHWidth)
#define GET_SYNC_V_HEIGHT()                          (g_stMeasureSyncHV.usVHeight)

//--------------------------------------------------
// Macro of Active Measurement Result
//--------------------------------------------------
#define GET_ACTIVE_V_START()                         (g_stActiveRegion.usVActiveStart)
#define GET_ACTIVE_V_END()                           (g_stActiveRegion.usVActiveEnd)
#define GET_ACTIVE_H_START()                         (g_stActiveRegion.usHActiveStart)
#define GET_ACTIVE_H_END()                           (g_stActiveRegion.usHActiveEnd)
#define GET_ACTIVE_H_WIDTH()                         ((g_stActiveRegion.usHActiveEnd - g_stActiveRegion.usHActiveStart) + 1)
#define GET_ACTIVE_V_HEIGHT()                        ((g_stActiveRegion.usVActiveEnd - g_stActiveRegion.usVActiveStart) + 1)

//--------------------------------------------------
// Macro of input timing infor. modification
//--------------------------------------------------
#define SET_INPUT_TIMING_HSTART(x)                   (g_stInputTimingData.usHStart = (x))
#define SET_INPUT_TIMING_HWIDTH(x)                   (g_stInputTimingData.usHWidth = (x))
#define SET_INPUT_TIMING_HTOTAL(x)                   (g_stInputTimingData.usHTotal = (x))

#define SET_INPUT_TIMING_VSTART(x)                   (g_stInputTimingData.usVStart = (x))
#define SET_INPUT_TIMING_VHEIGHT(x)                  (g_stInputTimingData.usVHeight = (x))
#define SET_INPUT_TIMING_VTOTAL(x)                   (g_stInputTimingData.usVTotal = (x))

//--------------------------------------------------
// Macro of input timing info Double Check
//--------------------------------------------------
#define GET_INPUT_TIMING_DOUBLE_CHECK()              (g_bInputTimingDoubleCheck)
#define SET_INPUT_TIMING_DOUBLE_CHECK()              (g_bInputTimingDoubleCheck = _TRUE)
#define CLR_INPUT_TIMING_DOUBLE_CHECK()              (g_bInputTimingDoubleCheck = _FALSE)


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
typedef enum
{
    _ACTIVE_REGION_TYPE = 0x00,
    _WHOLE_FRAME_TYPE = _BIT3,
    _BACK_PORCH_TYPE = _BIT4,
    _FRONT_PORCH_TYPE = (_BIT4 | _BIT3),
} EnumActiveRegionType;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern StructAutoActiveData g_stActiveRegion;
extern StructMeasureSyncData g_stMeasureSyncHV;
extern StructTimingInfo g_stInputTimingData;

extern DWORD g_ulInputActiveRegionBackUp;
extern bit g_bInputTimingDoubleCheck;

//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
#if(_VGA_SUPPORT == _ON)
extern bit ScalerMeasureVgaInterlaceCheck(EnumSourceSearchPort enumSourceSearchPort);
#endif

extern void ScalerMeasureInitialSetting(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort);
extern bit ScalerMeasureInputActiveRegionChange(void);
extern void ScalerMeasureUpdateOnlineMeasureResult(void);
extern void ScalerMeasureSetInputRegionCount(EnumActiveRegionType enumRegion);
extern DWORD ScalerMeasureGetInputRegionCountResult(bit bWait);
extern void ScalerMeasureSetDisplayRegionCount(EnumActiveRegionType enumRegion);
extern DWORD ScalerMeasureGetDisplayRegionCountResult(bit bWait);

#if(_DIGITAL_PORT_SUPPORT == _ON)
extern bit ScalerMeasureAutoFuncWaitFinish(void);
#endif


extern void ScalerMeasureUpdateInputTimingData(StructMeasureSyncData *pstMeasureSyncHV, StructAutoActiveData *pstActiveRegion);

