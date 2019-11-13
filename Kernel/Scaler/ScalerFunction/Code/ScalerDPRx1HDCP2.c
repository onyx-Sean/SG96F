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
// ID Code      : ScalerDPRx1HDCP2.c No.0000
// Update Note  :
//----------------------------------------------------------------------------------------------------

#include "ScalerFunctionInclude.h"

#if(_DP_HDCP_2_2_SUPPORT == _ON)
#if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)

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
//----------------------------------------------------------------------------
// Global Variables (XDATA) for Each Interface = 77 Bytes
//----------------------------------------------------------------------------
BYTE g_ucDPRx1Hdcp2Ctrl;
BYTE g_pucDpRx1Hdcp2dKey0[16];
BYTE g_pucDpRx1Hdcp2dKey1[16];
BYTE g_pucDpRx1Hdcp2Km[16];
BYTE g_pucDpRx1Hdcp2Rtx[8];
BYTE g_pucDpRx1Hdcp2TxCaps[3];
BYTE g_pucDpRx1Hdcp2Rn[8];
BYTE g_pucDpRx1Hdcp2Rrx[8];

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
BYTE ScalerDpRx1Hdcp2GetMessageID_EXINT0(void);
void ScalerDpRx1Hdcp2LoadCertRrxKey(void);
void ScalerDpRx1Hdcp2LoadDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucLength, BYTE *pucReadArray);
BYTE ScalerDpRx1Hdcp2MPrimeCalculate_EXINT0(void);
void ScalerDpRx1Hdcp2SetDpcdReadValue_EXINT0(BYTE ucRSAType, BYTE *pucReadArray, WORD usLength);
void ScalerDpRx1Hdcp2ClearDpcdReadValue_EXINT0(BYTE ucRSAType, WORD usLength);

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
BYTE ScalerDpRx1Hdcp2MPrimeCalculate(void);
#endif

bit ScalerDpRx1Hdcp2CaptureKpubKm(void);
void ScalerDpRx1Hdcp2CalculateKmKh(void);

//****************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  : Get HDCP 2.2 Message ID Code
// Input Value  : None
// Output Value : Message ID Code
//--------------------------------------------------
BYTE ScalerDpRx1Hdcp2GetMessageID_EXINT0(void) using 1
{
    // Write Ake Initial
    if((ScalerGetBit_EXINT(PBA_A3_AUX_RESERVE3, _BIT3) == _BIT3) && (ScalerGetBit_EXINT(PBA_A4_AUX_RESERVE4, _BIT3) == _BIT3))
    {
        // CLR Flag
        ScalerSetByte_EXINT(PBA_A4_AUX_RESERVE4, _BIT3);

        return _HDCP_2_2_AKE_INIT;
    }

    // Write AKE No Store Km
    if((ScalerGetBit_EXINT(PBA_A3_AUX_RESERVE3, _BIT7) == _BIT7) && (ScalerGetBit_EXINT(PBA_A4_AUX_RESERVE4, _BIT7) == _BIT7))
    {
        // CLR Flag
        ScalerSetByte_EXINT(PBA_A4_AUX_RESERVE4, _BIT7);

        return _HDCP_2_2_AKE_NO_STORED_KM;
    }

    // Write AKE Store Km
    if((ScalerGetBit_EXINT(PBA_A3_AUX_RESERVE3, _BIT6) == _BIT6) && (ScalerGetBit_EXINT(PBA_A4_AUX_RESERVE4, _BIT6) == _BIT6))
    {
        // CLR Flag
        ScalerSetByte_EXINT(PBA_A4_AUX_RESERVE4, _BIT6);

        return _HDCP_2_2_AKE_STORED_KM;
    }

    // Write Locality Check Initial
    if((ScalerGetBit_EXINT(PBA_A3_AUX_RESERVE3, _BIT4) == _BIT4) && (ScalerGetBit_EXINT(PBA_A4_AUX_RESERVE4, _BIT4) == _BIT4))
    {
        // CLR Flag
        ScalerSetByte_EXINT(PBA_A4_AUX_RESERVE4, _BIT4);

        return _HDCP_2_2_LC_INIT;
    }

    // Write SEK Send
    if((ScalerGetBit_EXINT(PBA_A5_AUX_RESERVE5, _BIT4) == _BIT4) && (ScalerGetBit_EXINT(PBA_A5_AUX_RESERVE5, _BIT0) == _BIT0))
    {
        // CLR Flag
        ScalerSetBit_EXINT(PBA_A5_AUX_RESERVE5, ~(_BIT2 | _BIT1 | _BIT0), _BIT0);

        return _HDCP_2_2_SKE_SEND_EKS;
    }

    // Write Cipher Type
    if((ScalerGetBit_EXINT(PBA_A5_AUX_RESERVE5, _BIT5) == _BIT5) && (ScalerGetBit_EXINT(PBA_A5_AUX_RESERVE5, _BIT1) == _BIT1))
    {
        // CLR Flag
        ScalerSetBit_EXINT(PBA_A5_AUX_RESERVE5, ~(_BIT2 | _BIT1 | _BIT0), _BIT1);

        return _HDCP_2_2_SKE_TYPE_VALUE;
    }

    // Write Stream ID Type
    if((ScalerGetBit_EXINT(PBA_A3_AUX_RESERVE3, _BIT5) == _BIT5) && (ScalerGetBit_EXINT(PBA_A4_AUX_RESERVE4, _BIT5) == _BIT5))
    {
        // CLR Flag
        ScalerSetByte_EXINT(PBA_A4_AUX_RESERVE4, _BIT5);

        return _HDCP_2_2_REPEATERAUTH_STREAM_MANAGE;
    }

    return _HDCP_2_2_NONE;
}
//--------------------------------------------------
// Description  : HDCP 2.2 Load Certificate Key
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1Hdcp2LoadCertRrxKey(void)
{
    for(PDATA_WORD(0) = 0; PDATA_WORD(0) < 522; PDATA_WORD(0)++)
    {
        PDATA_WORD(1) = 0x900B + PDATA_WORD(0);

        ScalerDpRx1SetDpcdValue(0x06, pData[2], pData[3], g_stRxHdcp2DownLoadKeyType.pucHdcp2Certrx[PDATA_WORD(0)]);
    }
}
//--------------------------------------------------
// Description  : HDCP 2.2 Down Load Value in INT
// Input Value  : ucDpcdAccessPortH --> High Byte of DPCD Address
//                ucDpcdAccessPortM --> Middle Byte of DPCD Address
//                ucDpcdAccessPortL --> Low Bye of DPCD Adress
//                usLength == > Length,
//                pReadArray == > Key Array
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1Hdcp2LoadDpcdValue_EXINT0(BYTE ucDpcdAccessPortH, BYTE ucDpcdAccessPortM, BYTE ucDpcdAccessPortL, BYTE ucLength, BYTE *pucReadArray) using 1
{
    pData_EXINT[2] = ucDpcdAccessPortM;
    pData_EXINT[3] = ucDpcdAccessPortL;

    // Load Value To FW
    for(pData_EXINT[0] = 0; pData_EXINT[0] < ucLength; pData_EXINT[0]++)
    {
        pucReadArray[pData_EXINT[0]] = ScalerDpRx1GetDpcdInfo_EXINT0(ucDpcdAccessPortH, pData_EXINT[2], pData_EXINT[3]);

        PDATA_WORD_EXINT(1) = PDATA_WORD_EXINT(1) + 1;
    }
}
//--------------------------------------------------
// Description  : Get M Prime
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerDpRx1Hdcp2MPrimeCalculate_EXINT0(void) using 1
{
    BYTE pucSHA256Input[64];
    memset(pucSHA256Input, 0, sizeof(pucSHA256Input));

    // Get kd
    for(pData_EXINT[0] = 0; pData_EXINT[0] < 64; pData_EXINT[0]++)
    {
        if(pData_EXINT[0] < 16)
        {
            pucSHA256Input[pData_EXINT[0]] = g_pucDpRx1Hdcp2dKey0[pData_EXINT[0]];
        }
        else if(pData_EXINT[0] < 32)
        {
            pucSHA256Input[pData_EXINT[0]] = g_pucDpRx1Hdcp2dKey1[pData_EXINT[0] - 16];
        }
        else
        {
            pucSHA256Input[pData_EXINT[0]] = 0;
        }
    }

    pucSHA256Input[32] = 0x80;
    pucSHA256Input[62] = 0x01;

    // Get SHA256(kd)
    if(ScalerHdcp2RxSha256Calculate_EXINT0(pucSHA256Input, 0) == _TRUE)
    {
        for(pData_EXINT[0] = 0; pData_EXINT[0] < 64; pData_EXINT[0]++)
        {
            if(pData_EXINT[0] < 32)
            {
                g_pucHdcp2HmacSha256CipherInput[pData_EXINT[0]] = ScalerGetByte_EXINT(P63_35_HDCP_SHA_0 + pData_EXINT[0]);
            }
            else
            {
                g_pucHdcp2HmacSha256CipherInput[pData_EXINT[0]] = 0;
            }
        }
    }

    // Get # of StreamID_Type Length, StreamID_Type = stream_ID1 || Type || stream_ID2 || Type || .....
    pData_EXINT[1] = ScalerDpRx1GetDpcdInfo_EXINT0(0x06, 0x93, 0xF4) * 2;

    // Stuff streamID_Type
    for(pData_EXINT[0] = 0; pData_EXINT[0] < pData_EXINT[1]; pData_EXINT[0]++)
    {
        g_pucHdcp2HmacSha256Input[pData_EXINT[0]] = ScalerDpRx1GetDpcdInfo_EXINT0(0x06, 0x93, 0xF5 + pData_EXINT[0]);
    }

    // Stuff seq_num_M
    for(pData_EXINT[0] = 0; pData_EXINT[0] < 3; pData_EXINT[0]++)
    {
        g_pucHdcp2HmacSha256Input[pData_EXINT[1] + pData_EXINT[0]] = ScalerDpRx1GetDpcdInfo_EXINT0(0x06, 0x93, (0xF0 + pData_EXINT[0]));
    }

    g_pucHdcp2HmacSha256Input[pData_EXINT[1] + 3] = 0x80;

    for(pData_EXINT[0] = pData_EXINT[1] + 4; pData_EXINT[0] < 64; pData_EXINT[0]++)
    {
        g_pucHdcp2HmacSha256Input[pData_EXINT[0]] = 0;
    }

    // 8 * (StreamID_Type + seq_num_M + SHA256(kd))
    PDATA_WORD_EXINT(1) = 8 * (pData_EXINT[1] + 3 + 64);

    g_pucHdcp2HmacSha256Input[62] = pData_EXINT[2];
    g_pucHdcp2HmacSha256Input[63] = pData_EXINT[3];

    if(ScalerHdcp2RxHmacSha256Calculate_EXINT0(g_pucHdcp2HmacSha256Input, g_pucHdcp2HmacSha256CipherInput) == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}

//--------------------------------------------------
// Description  : Download HDCP Receiver Public Key Certificate
// Input Value  : Public Key / Write Length
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1Hdcp2SetDpcdReadValue_EXINT0(BYTE ucRSAType, BYTE *pucReadArray, WORD usLength) using 1
{
    switch(ucRSAType)
    {
        case _HDCP_2_2_RRX:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0x15;

            break;

        case _HDCP_2_2_RX_H_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0xC0;

            break;

        case _HDCP_2_2_RX_L_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0xF8;

            break;

        case _HDCP_2_2_RX_M_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x94;
            pData_EXINT[3] = 0x73;

            break;

        default:

            return;
    }

    for(pData_EXINT[0] = 0; pData_EXINT[0] < usLength; pData_EXINT[0]++)
    {
        ScalerDpRx1SetDpcdValue_EXINT0(pData_EXINT[1], pData_EXINT[2], pData_EXINT[3], pucReadArray[pData_EXINT[0]]);
        PDATA_WORD_EXINT(1) = PDATA_WORD_EXINT(1) + 1;
    }
}

//--------------------------------------------------
// Description  : Clear HDCP Receiver Public Key Certificate
// Input Value  : Public Key / Write Length
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1Hdcp2ClearDpcdReadValue_EXINT0(BYTE ucRSAType, WORD usLength) using 1
{
    switch(ucRSAType)
    {
        case _HDCP_2_2_RRX:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0x15;

            break;

        case _HDCP_2_2_RX_H_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0xC0;

            break;

        case _HDCP_2_2_RX_PAIRING_INFO:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0xE0;

            break;

        case _HDCP_2_2_RX_L_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x92;
            pData_EXINT[3] = 0xF8;

            break;

        case _HDCP_2_2_RX_M_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x94;
            pData_EXINT[3] = 0x73;

            break;

        case _HDCP_2_2_RX_V_PRIME:

            pData_EXINT[1] = 0x06;
            pData_EXINT[2] = 0x93;
            pData_EXINT[3] = 0x32;

            break;

        default:

            return;
    }

    for(pData_EXINT[0] = 0; pData_EXINT[0] < usLength; pData_EXINT[0]++)
    {
        ScalerDpRx1SetDpcdValue_EXINT0(pData_EXINT[1], pData_EXINT[2], pData_EXINT[3], 0x00);
        PDATA_WORD_EXINT(1) = PDATA_WORD_EXINT(1) + 1;
    }
}

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Get M Prime
// Input Value  : None
// Output Value : None
//--------------------------------------------------
BYTE ScalerDpRx1Hdcp2MPrimeCalculate(void)
{
    BYTE pucSHA256Input[64];
    BYTE pucKd[32];

    memset(pucSHA256Input, 0, sizeof(pucSHA256Input));

    pucKd[0] = 0x4f;
    pucKd[1] = 0x14;
    pucKd[2] = 0x8d;
    pucKd[3] = 0x11;
    pucKd[4] = 0xdd;
    pucKd[5] = 0x49;
    pucKd[6] = 0x18;
    pucKd[7] = 0x10;
    pucKd[8] = 0x6f;
    pucKd[9] = 0xab;
    pucKd[10] = 0x16;
    pucKd[11] = 0x6f;
    pucKd[12] = 0xf6;
    pucKd[13] = 0xfd;
    pucKd[14] = 0xa6;
    pucKd[15] = 0xed;
    pucKd[16] = 0xb5;
    pucKd[17] = 0x02;
    pucKd[18] = 0x0c;
    pucKd[19] = 0x0d;
    pucKd[20] = 0xf2;
    pucKd[21] = 0x81;
    pucKd[22] = 0xba;
    pucKd[23] = 0xdf;
    pucKd[24] = 0xe4;
    pucKd[25] = 0x19;
    pucKd[26] = 0x77;
    pucKd[27] = 0xfa;
    pucKd[28] = 0xd0;
    pucKd[29] = 0xac;
    pucKd[30] = 0x61;
    pucKd[31] = 0x17;

    // Get kd
    for(pData[0] = 0; pData[0] < 64; pData[0]++)
    {
        if(pData[0] < 32)
        {
            pucSHA256Input[pData[0]] = pucKd[pData[0]];
        }
        else
        {
            pucSHA256Input[pData[0]] = 0;
        }
    }

    pucSHA256Input[32] = 0x80;
    pucSHA256Input[62] = 0x01;

    // Get SHA256(kd)
    if(ScalerHdcp2RxSha256Calculate(pucSHA256Input, 0) == _TRUE)
    {
        for(pData[0] = 0; pData[0] < 64; pData[0]++)
        {
            if(pData[0] < 32)
            {
                g_pucHdcp2HmacSha256CipherInput[pData[0]] = ScalerGetByte(P63_35_HDCP_SHA_0 + pData[0]);
            }
            else
            {
                g_pucHdcp2HmacSha256CipherInput[pData[0]] = 0;
            }
        }
    }

    for(pData[0] = 0; pData[0] < 64; pData[0]++)
    {
        DebugMessageHDCP2("SHA256(kd)", g_pucHdcp2HmacSha256CipherInput[pData[0]]);
    }

    // StreamID
    g_pucHdcp2HmacSha256Input[0] = 0x00;

    // Type
    g_pucHdcp2HmacSha256Input[1] = 0x01;

    // Stuff seq_num_M
    g_pucHdcp2HmacSha256Input[2] = 0x00;
    g_pucHdcp2HmacSha256Input[3] = 0x00;
    g_pucHdcp2HmacSha256Input[4] = 0x00;

    g_pucHdcp2HmacSha256Input[5] = 0x80;

    for(pData[0] = 6; pData[0] < 64; pData[0]++)
    {
        g_pucHdcp2HmacSha256Input[pData[0]] = 0;
    }

    // 8 * ( StreamID_Type + seq_M + Kd )
    PDATA_WORD(1) = 8 * (2 + 3 + 64);

    g_pucHdcp2HmacSha256Input[62] = pData[2];
    g_pucHdcp2HmacSha256Input[63] = pData[3];

    if(ScalerHdcp2RxHmacSha256Calculate(g_pucHdcp2HmacSha256Input, g_pucHdcp2HmacSha256CipherInput) == _TRUE)
    {
        return _TRUE;
    }

    return _FALSE;
}
#endif // End of #if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)

//--------------------------------------------------
// Description  : Capture Kpub/Km
// Input Value  : None
// Output Value : _TRUE or _FALSE
//--------------------------------------------------
bit ScalerDpRx1Hdcp2CaptureKpubKm(void)
{
    BYTE pucKpubKm[128];
    memset(pucKpubKm, 0, sizeof(pucKpubKm));

    CLR_DP_RX1_HDCP2_AKE_NO_STORED_KM_RECEIVED();

    DebugMessageHDCP2("[D1]AKE_NO_STORED_KM", 0);

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
    for(pData[0] = 0; pData[0] < 128; pData[0]++)
    {
        pucKpubKm[pData[0]] = g_stRxHdcp2DownLoadKeyType.pucHdcp2KpubKm[pData[0]];

        DebugMessageHDCP2("[D1]Ekpub(km)", pucKpubKm[pData[0]]);
    }
#else
    // Save Transmitter Ekpub[km] to FW
    for(pData[0] = 0; pData[0] < 128; pData[0]++)
    {
        pucKpubKm[pData[0]] = ScalerDpRx1GetDpcdInfo(0x06, 0x92, (0x20 + pData[0]));
    }
#endif

    // Decrypt Ekpub[km]
    return (ScalerHdcp2RxRsaCalculate(pucKpubKm) == _TRUE);
}

//--------------------------------------------------
// Description  : Load H_Prime and Calculate Paring
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void ScalerDpRx1Hdcp2CalculateKmKh(void)
{
    BYTE pucSHA256[32];

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
    BYTE pucM[16];
    memset(pucM, 0, sizeof(pucM));
#endif
    memset(pucSHA256, 0, sizeof(pucSHA256));

    // Load H prime to pucSHA256
    memcpy(pucSHA256, (volatile BYTE xdata *)P63_35_HDCP_SHA_0, 32);

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
    for(pData[0] = 0; pData[0] < 32; pData[0]++)
    {
        DebugMessageHDCP2("H prime", pucSHA256[pData[0]]);
    }
#endif

    SET_DP_RX1_AUX_MANUAL_MODE();

    // Load H prime to DPCD Table
    for(pData[0] = 0; pData[0] < 32; pData[0]++)
    {
        ScalerDpRx1SetDpcdValue(0x06, 0x92, (0xC0 + pData[0]), pucSHA256[pData[0]]);
    }

    SET_DP_RX1_AUX_AUTO_MODE();

    // Set H Prime Available Flag
    ScalerDpRx1CpIRQ(_DP_HDCP2_H_PRIME_AVAILABLE);

    // Start Pairing AES Calculate
    for(pData[0] = 0; pData[0] < 16; pData[0]++)
    {
        if(pData[0] < 8)
        {
            g_pucHdcp2M[pData[0]] = g_pucDpRx1Hdcp2Rtx[pData[0]];
        }
        else
        {
            g_pucHdcp2M[pData[0]] = g_pucDpRx1Hdcp2Rrx[pData[0] - 8];
        }
    }

    // AES Cipher Calculate Ekh[km]
    ScalerHdcp2RxAesOfflineCtrl(g_pucHdcp2M, g_pucHdcp2Kh);

    // Calculate Ekh[km] = kh AES m XOR Km
    for(pData[0] = 0; pData[0] < 16; pData[0]++)
    {
        g_pucHdcp2EkhKm[pData[0]] = ScalerGetByte(P63_81_HDCP_AES_OUT_15 + pData[0]) ^ g_pucDpRx1Hdcp2Km[pData[0]];
    }

    SET_DP_RX1_AUX_MANUAL_MODE();

    // Load Ekh_km prime to DPCD Table
    for(pData[0] = 0; pData[0] < 16; pData[0]++)
    {
        ScalerDpRx1SetDpcdValue(0x06, 0x92, (0xE0 + pData[0]), g_pucHdcp2EkhKm[pData[0]]);
    }

    SET_DP_RX1_AUX_AUTO_MODE();

    // Set Paring Available Flag
    ScalerDpRx1CpIRQ(_DP_HDCP2_PARING_AVAILABLE);

#if(_HDCP_2_2_ERRATA_TEST_SUPPORT == _ON)
    // Start Pairing AES Calculate
    for(pData[0] = 0; pData[0] < 16; ++pData[0])
    {
        if(pData[0] < 8)
        {
            pucM[pData[0]] = g_pucDpRx1Hdcp2Rtx[pData[0]];
        }
        else
        {
            pucM[pData[0]] = g_pucDpRx1Hdcp2Rrx[pData[0] - 8];
        }
    }

    // AES Cipher Calculate Ekh[km]
    ScalerHdcp2RxAesOfflineCtrl(pucM, g_pucHdcp2Kh);

    // Calculate Ekh[km] = kh AES m XOR Km
    for(pData[0] = 0; pData[0] < 16; ++pData[0])
    {
        g_pucHdcp2Kh[pData[0]] = ScalerGetByte(P63_81_HDCP_AES_OUT_15 + pData[0]) ^ g_pucDpRx1Hdcp2Km[pData[0]];

        DebugMessageHDCP2("g_ucHdcp2Kh", g_pucHdcp2Kh[pData[0]]);
    }
#endif
}

#endif // End of #if(_D1_INPUT_PORT_TYPE == _D1_DP_PORT)
#endif // End of #if(_DP_HDCP_2_2_SUPPORT == _ON)
