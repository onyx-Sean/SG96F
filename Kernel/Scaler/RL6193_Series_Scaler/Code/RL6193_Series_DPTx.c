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
// ID Code      : RL6193_Series_DPTx.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_DP_TX_SUPPORT == _ON)

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
bit ScalerDpTxCloneCheckInputPortSupport(EnumSourceSearchPort enumInputPort);
BYTE ScalerDpTxAudioGetSamplingFreqRange(void);
void ScalerDpTxSSTAudioPlaySetting(EnumDPTxAudioPlayState enumPlayState);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : DP Tx Clone Output Process
// Input Value  : Input Port Type to be Cloned
// Output Value : None
//--------------------------------------------------
bit ScalerDpTxCloneCheckInputPortSupport(EnumSourceSearchPort enumInputPort)
{
    if(enumInputPort != _NO_INPUT_PORT)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : DP Tx Get Audio Sampling Frequency Range
// Input Value  :
// Output Value : Audio Frequency Range
//--------------------------------------------------
BYTE ScalerDpTxAudioGetSamplingFreqRange(void)
{
    BYTE ucSampleFreqRange = 0;
    WORD usAudioPacket = 0;

    ucSampleFreqRange = (ScalerGetBit(PBC_4F_SEC_AUD_SAMPLE_CNT_HB, (_BIT7 | _BIT6 | _BIT5 | _BIT4)) >> 4);

    usAudioPacket = (WORD)((ScalerGetBit(PBC_4F_SEC_AUD_SAMPLE_CNT_HB, (_BIT3 | _BIT2 | _BIT1 | _BIT0)) << 8) | ScalerGetByte(PBC_50_SEC_AUD_SAMPLE_CNT_LB));

    // For RL6193C, HW can't seperate 176.4kHz and 192kHz, this modification is compatible with Ver D.
    if((ucSampleFreqRange == _DP_TX_AUDIO_FREQ_192K) && (usAudioPacket <= 0x00B9))
    {
        ucSampleFreqRange = _DP_TX_AUDIO_FREQ_176_4K;
    }

    return ucSampleFreqRange;
}

//--------------------------------------------------
// Description  : Set DP TX Audio Play for DP MST2SST
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpTxSSTAudioPlaySetting(EnumDPTxAudioPlayState enumPlayState)
{
    DWORD ulMaud = 0;
    DWORD ulNaud = 0;

    switch(enumPlayState)
    {
        case _DP_TX_AUDIO_OFF:

            // Enable VBID audiomute_flag
            ScalerSetBit(PBB_C7_VBID, ~_BIT2, _BIT2);

            // Disable DP TX Audio and Audio Timestamp
            ScalerSetBit(PBC_00_SEC_FUNCTION_CTRL, ~(_BIT1 | _BIT0), 0x00);

            // Clear Header for Audio
            ScalerDpTxClearSecDataHeader(_SEC_PACKET_TYPE_AUDIO_STREAM);

            // Set Maud
            ScalerSetByte(PBC_20_AUD_TS_MAUD_H, 0x00);
            ScalerSetByte(PBC_21_AUD_TS_MAUD_M, 0x00);
            ScalerSetByte(PBC_22_AUD_TS_MAUD_L, 0x00);

            // Sed Naud
            ScalerSetByte(PBC_23_AUD_TS_NAUD_H, 0x00);
            ScalerSetByte(PBC_24_AUD_TS_NAUD_M, 0x00);
            ScalerSetByte(PBC_25_AUD_TS_NAUD_L, 0x00);

            // Clear Header for Audio Timestamp
            ScalerDpTxClearSecDataHeader(_SEC_PACKET_TYPE_AUDIO_TIMESTAMP);

            CLR_DP_TX_AUDIO_READY_TO_PLAY();

            break;

        case _DP_TX_AUDIO_STANDBY:

            // Enable VBID audiomute_flag
            ScalerSetBit(PBB_C7_VBID, ~_BIT2, _BIT2);

            // Disable DP TX Audio and Audio Timestamp
            ScalerSetBit(PBC_00_SEC_FUNCTION_CTRL, ~(_BIT1 | _BIT0), 0x00);

            break;

        case _DP_TX_AUDIO_PRESET:

            ScalerDpTxAudioSetting();

            // Enable TX audio freq. detection
            ScalerSetBit(PBC_4C_SEC_AUD_FREQDET_CTRL, ~_BIT7, _BIT7);

            // Enable TX audio RS decoder
            ScalerSetBit(PBC_4B_SEC_RS_DECODE_CTRL, ~_BIT7, _BIT7);

            SET_DP_TX_AUDIO_READY_TO_PLAY();
            CLR_DP_TX_CURRENT_AUDIO_FREQUENCY();

            break;

        case _DP_TX_AUDIO_ON:

            ScalerDpTxAudioSetting();

            // Naud
            ulNaud = 32768;

            // Maud
            ulMaud = (DWORD)(512 * ((ulNaud * ScalerDpTxAudioGetSamplingFreqPacket()) / _DP_TX_LINK_CLK_MHZ)) / 1000 / 10;

            // Set Maud
            ScalerSetByte(PBC_20_AUD_TS_MAUD_H, (BYTE)(ulMaud >> 16));
            ScalerSetByte(PBC_21_AUD_TS_MAUD_M, (BYTE)(ulMaud >> 8));
            ScalerSetByte(PBC_22_AUD_TS_MAUD_L, (BYTE)(ulMaud >> 0));

            // Sed Naud
            ScalerSetByte(PBC_23_AUD_TS_NAUD_H, (BYTE)(ulNaud >> 16));
            ScalerSetByte(PBC_24_AUD_TS_NAUD_M, (BYTE)(ulNaud >> 8));
            ScalerSetByte(PBC_25_AUD_TS_NAUD_L, (BYTE)(ulNaud >> 0));

            // Set Header for Audio Timestamp
            ScalerDpTxSetSecDataHeader(_SEC_PACKET_TYPE_AUDIO_TIMESTAMP);

            // Set Header for Audio Stream
            ScalerDpTxSetSecDataHeader(_SEC_PACKET_TYPE_AUDIO_STREAM);

            // Disable VBID audiomute_flag
            ScalerSetBit(PBB_C7_VBID, ~_BIT2, 0x00);

            // DP Audio and Audio Timestamp enable
            ScalerSetBit(PBC_00_SEC_FUNCTION_CTRL, ~(_BIT1 | _BIT0), (_BIT1 | _BIT0));

            break;

        default:
            break;
    }
}

#endif // End of #if(_DP_TX_SUPPORT == _ON)
