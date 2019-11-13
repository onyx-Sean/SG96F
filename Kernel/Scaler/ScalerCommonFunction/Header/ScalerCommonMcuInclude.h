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
// ID Code      : ScalerCommonMcuInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************

//--------------------------------------------------
// Macros of HW IIC Setting
//--------------------------------------------------
#define _HW_IIC_SLPC_14318K                 (tHwI2cSetting[g_ucHwI2cSettingIndex].ucSLPC_14318K)
#define _HW_IIC_SHPC_14318K                 (tHwI2cSetting[g_ucHwI2cSettingIndex].ucSHPC_14318K)
#define _HW_IIC_SLPC_28000K                 (tHwI2cSetting[g_ucHwI2cSettingIndex].ucSLPC_28000K)
#define _HW_IIC_SHPC_28000K                 (tHwI2cSetting[g_ucHwI2cSettingIndex].ucSHPC_28000K)
#define _HW_IIC_STA_SUGPIO_C                (tHwI2cSetting[g_ucHwI2cSettingIndex].ucSTA_SUGPIO_C)
#define _HW_IIC_TOR                         (tHwI2cSetting[g_ucHwI2cSettingIndex].ucTOR)
#define _HW_IIC_FTPC                        (tHwI2cSetting[g_ucHwI2cSettingIndex].ucFTPC)
#define _HW_IIC_FD10_14318K                 (tHwI2cSetting[g_ucHwI2cSettingIndex].ucFD10_14318K)
#define _HW_IIC_FD10_28000K                 (tHwI2cSetting[g_ucHwI2cSettingIndex].ucFD10_28000K)

//--------------------------------------------------
// Macros of 5us Delay
//--------------------------------------------------
#define Delay5us(N)                         {\
                                                g_ucDelay5usI = (N);\
                                                while(--g_ucDelay5usI) {};\
                                            }

#define Delay5us_EXINT(N)                   {\
                                                g_ucDelay5usI_EXINT = (N);\
                                                while(--g_ucDelay5usI_EXINT) {};\
                                            }

//--------------------------------------------------
// Macros of SW IIC Status
//--------------------------------------------------
#if(_SW_IIC_SUPPORT == _ON)
#define GET_SW_IIC_STATUS()                 (g_ucSwIICStatus)
#define SET_SW_IIC_STATUS(x)                (g_ucSwIICStatus = (x))
#endif

//--------------------------------------------------
// MACRO for RUN DDCCI Command
//--------------------------------------------------
#define GET_RUN_DDCCI_COMMAND()             (g_bRunDdcciCommand)
#define SET_RUN_DDCCI_COMMAND(x)            (g_bRunDdcciCommand = (x))

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************

extern BYTE data g_ucDelay5usN;
extern BYTE data g_ucDelay5usI;
extern BYTE data g_ucDelay5usI_EXINT;
extern bit g_bRunDdcciCommand;

#if(_TWO_CHIP_DATA_COMMUNICATION_SUPPORT == _ON)
extern bit g_bRunDdcciExchangeCommand;
extern BYTE g_ucDdcciExchangeCountEXINT;
extern BYTE g_pucDdcciExchangeRxBuf[_TWO_CHIP_DDCCI_EXCHANGE_RXBUF_LENGTH];
#endif

#if(_SW_IIC_SUPPORT == _ON)
extern BYTE idata g_ucSwIICStatus;
#endif

#if(_A0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_A0[_A0_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D0_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D0[_D0_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D1_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D1[_D1_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D2_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D2[_D2_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D3_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D3[_D3_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D4_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D4[_D4_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D5_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D5[_D5_EMBEDDED_DDCRAM_SIZE];
#endif


#if(_D0_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL_D0[_D0_MHL_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D1_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL_D1[_D1_MHL_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D2_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL_D2[_D2_MHL_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D3_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL_D3[_D3_MHL_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D4_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL_D4[_D4_MHL_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D5_MHL_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_MHL_D5[_D5_MHL_EMBEDDED_DDCRAM_SIZE];
#endif

#if(_D6_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)
extern BYTE xdata MCU_DDCRAM_D6[_D6_EMBEDDED_DDCRAM_SIZE];
#endif // End of #if(_D6_EMBEDDED_DDCRAM_SIZE != _EDID_SIZE_NONE)


extern BYTE g_pucDdcciRxBuf[_DDCCI_RXBUF_LENGTH];
extern BYTE g_pucDdcciTxBuf[_DDCCI_TXBUF_LENGTH];

#if(_HW_IIC_SUPPORT == _ON)
extern BYTE g_ucHwI2cSettingIndex;
#endif


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMcuFlashClockDiv(EnumFlashClkDiv enumClkDiv);
extern void ScalerMcuFlash2ClockDiv(EnumFlash2ClkDiv enumClkDiv);
extern void ScalerMcuClockDiv(EnumMcuClkDiv enumClkDiv);
extern void ScalerMcu5usDelayCalc(EnumClkSel enumClock);

#if(_SW_IIC_SUPPORT == _ON)
extern bit ScalerMcuIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pucReadArray);
extern bit ScalerMcuIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, WORD usLength, BYTE *pucWriteArray);
#endif

#if(_HW_IIC_SUPPORT == _ON)
extern void ScalerMcuHwIICInitial(void);
extern bit ScalerMcuHwIICRead(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pucReadArray, BYTE ucHwIICPinNum);
extern bit ScalerMcuHwIICWrite(BYTE ucSlaveAddr, BYTE ucSubAddrLength, WORD usSubAddr, BYTE ucDataLength, BYTE *pucWriteArray, BYTE ucHwIICPinNum);
#endif

extern void ScalerMcuIspInitial(void);

