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
// ID Code      : RL6193_Series_VGIPInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
//--------------------------------------------------
// Definitions of VGIP IH Capture Start Min Value
//--------------------------------------------------
#define _VGIP_IH_CAPTURE_MIN_VALUE                  ((ScalerFmtCnvFtoPGetStatus() == _TRUE) ? 20 : 10)
#define _VGIP_IV_CAPTURE_MIN_VALUE                  ((ScalerFmtCnvFtoPGetStatus() == _TRUE) ? 8 : 4)

//--------------------------------------------------
// Definitions of VGIP IV Capture Start Max Value
//--------------------------------------------------
#define _VGIP_IV_CAPTURE_MAX_VALUE                  240

//--------------------------------------------------
// Definitions of VGIP IHDelay Max Value
//--------------------------------------------------
#define _VGIP_IH_DELAY_MAX_VALUE                    1023


//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************


//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern void ScalerVgipInputInitial(EnumSourceTypeDef enumSourceType, EnumSourceSearchPort enumSourceSearchPort);
extern void ScalerVgipModifyPolarity(EnumSourceTypeDef enumSourceType);

extern WORD ScalerVgipGetCaptureVStartPosition(void);
extern void ScalerVgipSetCaptureVStartPosition(WORD usIVstart);

extern WORD ScalerVgipGetCaptureVHeight(void);
extern void ScalerVgipSetCaptureVHeight(WORD usIVheight);

extern WORD ScalerVgipGetCaptureVDelay(void);
extern void ScalerVgipSetCaptureVDelay(WORD usIVSDelay);

extern WORD ScalerVgipGetCaptureHStartPosition(void);
extern void ScalerVgipSetCaptureHStartPosition(WORD usIHstart);

extern void ScalerVgipSetCaptureHWidth(WORD usIHwidth);

extern void ScalerVgipSetCaptureHDelay(WORD usIHSDelay);
extern WORD ScalerVgipGetCaptureHDelay(void);

extern void ScalerVgipVsBypassEnable(bit bEnable);

extern void ScalerVgipSetDigitalCaptureStatus(bit bEnable);

