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
// ID Code      : RL6193_Series_MDomainInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define _MEMORY_ACCESS_TYPE                         (_LINE_MODE)

#define _FRC_WRITE_BW_MULTIPLE                      (((ScalerFmtCnvFtoPGetStatus() == _FALSE) && (ScalerGlobalGetIDCode() <= _RL6193_VER_C_ID_CODE)) ? 2 : 1)

#define GET_FREE_RUN_DVTOTAL(usBackup)              {\
                                                        BYTE pucMacroDvtotalBackup[2];\
                                                        memset(pucMacroDvtotalBackup, 0, sizeof(pucMacroDvtotalBackup));\
                                                        ScalerGetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_30_FIXED_DVTOTAL_MSB, 2, pucMacroDvtotalBackup, _AUTOINC);\
                                                        (usBackup) = (((pucMacroDvtotalBackup[0] & 0x1F) << 8) | (pucMacroDvtotalBackup[1]));\
                                                    }

#define SET_FREE_RUN_DVTOTAL(usBackup)              {\
                                                        ScalerSetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_30_FIXED_DVTOTAL_MSB, HIBYTE(usBackup) & 0x1F);\
                                                        ScalerSetDataPortByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_31_FIXED_DVTOTAL_LSB, LOBYTE(usBackup));\
                                                    }

#define GET_DVTOTAL_LASTLINE_RAW(usBackup)          {\
                                                        (usBackup) = ((((WORD)(ScalerGetByte(P0_44_LAST_LINE_H) & 0x1F) << 8) |\
                                                                               ScalerGetByte(P0_45_LAST_LINE_L)) & 0x1FFF);\
                                                    }

#define GET_DVTOTAL_LASTLINE(usBackup)              {\
                                                        ScalerTimerClrEventStatus(_EVENT_DVS);\
                                                        GET_DVTOTAL_LASTLINE_RAW(usBackup);\
                                                        if(ScalerTimerGetEventStatus(_EVENT_DVS) == _EVENT_DVS)\
                                                        {\
                                                            GET_DVTOTAL_LASTLINE_RAW(usBackup);\
                                                        }\
                                                    }

#define GET_SAFE_DVTOTAL_LASTLINE(usBackup)         {\
                                                        WORD usLocalBackup = 0;\
                                                        ScalerTimerClrEventStatus(_EVENT_DVS);\
                                                        GET_DVTOTAL_LASTLINE_RAW(usLocalBackup);\
                                                        if(ScalerTimerGetEventStatus(_EVENT_DVS) != _EVENT_DVS)\
                                                        {\
                                                            (usBackup) = usLocalBackup;\
                                                        }\
                                                    }

#define SET_D_DOMAIN_V_ACT_END(usBackup)            {\
                                                        ScalerSetByte(P0_2A_DISPLAY_FORMAT_ADDR_PORT, _P0_2B_PT_12_DISPLAY_VER_ACT_END_H);\
                                                        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, (HIBYTE(usBackup) & 0x1F));\
                                                        ScalerSetByte(P0_2B_DISPLAY_FORMAT_DATA_PORT, LOBYTE(usBackup));\
                                                    }

//--------------------------------------------------
// Freesync Line Buffer Priority
//--------------------------------------------------
#define _FREESYNC_LINEBUFFER_PRIORITY               _OFF

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerMDomainControlDBApply(void);
extern bit ScalerMDomainMemoryCheck(void);
extern void ScalerMDomainSetDisplayFormat(BYTE ucMemorySel);

#if(_FREESYNC_OD_MEASURE == _ON)
extern void ScalerMDomainFREESYNCODSetDisplayFormat(WORD usDHtotal, DWORD ulDclk, WORD usTarFreq);
#endif
