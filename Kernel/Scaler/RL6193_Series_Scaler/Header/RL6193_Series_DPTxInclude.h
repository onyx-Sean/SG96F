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
// ID Code      : RL6193_Series_DPTxInclude.h No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#if(_DP_TX_SUPPORT == _ON)

//****************************************************************************
// LAYER DEFINITIONS / MACROS
//****************************************************************************
#define GET_DP_TX_HDCP_M0_0()                           (ScalerGetByte(PBB_43_M0_BYTE_0))
#define GET_DP_TX_HDCP_M0_1()                           (ScalerGetByte(PBB_42_M0_BYTE_1))
#define GET_DP_TX_HDCP_M0_2()                           (ScalerGetByte(PBB_41_M0_BYTE_2))
#define GET_DP_TX_HDCP_M0_3()                           (ScalerGetByte(PBB_40_M0_BYTE_3))
#define GET_DP_TX_HDCP_M0_4()                           (ScalerGetByte(PBB_3F_M0_BYTE_4))
#define GET_DP_TX_HDCP_M0_5()                           (ScalerGetByte(PBB_3E_M0_BYTE_5))
#define GET_DP_TX_HDCP_M0_6()                           (ScalerGetByte(PBB_3D_M0_BYTE_6))
#define GET_DP_TX_HDCP_M0_7()                           (ScalerGetByte(PBB_3C_M0_BYTE_7))

#define SET_DP_TX_MVID_FW_MODE()                        ;

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************
//--------------------------------------------------
// Enumerations of Audio Sampling Freq
//--------------------------------------------------
typedef enum
{
    _DP_TX_AUDIO_FREQ_NO_AUDIO = 0,
    _DP_TX_AUDIO_FREQ_32K = 1,
    _DP_TX_AUDIO_FREQ_44_1K = 2,
    _DP_TX_AUDIO_FREQ_48K = 3,
    _DP_TX_AUDIO_FREQ_64K = 4,
    _DP_TX_AUDIO_FREQ_88_2K = 5,
    _DP_TX_AUDIO_FREQ_96K = 6,
    _DP_TX_AUDIO_FREQ_128K = 7,
    _DP_TX_AUDIO_FREQ_176_4K = 14,
    _DP_TX_AUDIO_FREQ_192K = 8,
    _DP_TX_AUDIO_FREQ_256K = 9,
    _DP_TX_AUDIO_FREQ_352_8K = 10,
    _DP_TX_AUDIO_FREQ_384K = 11,
    _DP_TX_AUDIO_FREQ_512K = 12,
    _DP_TX_AUDIO_FREQ_705_6K = 13,
    _DP_TX_AUDIO_FREQ_768K = 15,
} EnumDPTxAudioSamplingFreq;

//****************************************************************************
// VARIABLE EXTERN
//****************************************************************************


//****************************************************************************
// FUNCTION EXTERN
//****************************************************************************
extern bit ScalerDpTxCloneCheckInputPortSupport(EnumSourceSearchPort enumInputPort);
extern BYTE ScalerDpTxAudioGetSamplingFreqRange(void);
extern void ScalerDpTxSSTAudioPlaySetting(EnumDPTxAudioPlayState enumPlayState);

#endif
