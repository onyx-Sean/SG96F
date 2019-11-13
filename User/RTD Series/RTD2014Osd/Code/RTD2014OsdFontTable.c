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
// ID Code      : RTD2014OsdFontTable.c
// Update Note  :
//----------------------------------------------------------------------------------------------------

#define __RTD_OSDFONTTABLE__

#include "UserCommonInclude.h"

#if(_OSD_TYPE == _REALTEK_2014_OSD)

//****************************************************************************
// DEFINITIONS / MACROS
//****************************************************************************

//****************************************************************************
// STRUCT / TYPE / ENUM DEFINITTIONS
//****************************************************************************

//****************************************************************************
// CODE TABLES
//****************************************************************************
BYTE code tOSD_ICON1[] =
{
0x01,0x02,0x03,0x04,_NEXT_,
0x05,0x06,0x07,0x08,_NEXT_,
0x09,0x0A,0x0B,0x0C,_END_,
};
BYTE code tOSD_ICON2[] =
{
0x0D,0x0E,0x0F,0x10,_NEXT_,	
0x11,0x12,0x13,0x14,_NEXT_,
0x15,0x16,0x17,0x18,_END_,	

};
BYTE code tOSD_ICON3[] =
{
0x19,0x1A,0x1B,0x1C,_NEXT_,
0x1D,0x1E,0x1F,0x20,_NEXT_,
0x21,0x22,0x23,0x24,_END_,

};
BYTE code tOSD_ICON4[] =
{
0x25,0x26,0x27,0x28,_NEXT_,
0x29,0x2a,0x2b,0x2c,_NEXT_,
0x2d,0x2e,0x2f,0x30,_END_,
	
};
BYTE code tOSD_ICON5[] =
{
0x31,0x32,0x33,0x34,_NEXT_,
0x35,0x36,0x37,0x38,_NEXT_,
0x39,0x3a,0x3b,0x3c,_END_,

};

BYTE code tOSD_LINE[] =
{
0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,_END_,	
};

BYTE code tOSD_LINE_DOWN[] =
{
0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,0x19,_END_,	

};

BYTE code tOSD_UP[] =
{
0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,_END_,	
};

BYTE code tOSD_DOWN[] =
{
0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,0x12,_END_,	
};
#if(_OSD_HHT==_ON)

BYTE code tWANGZHI[] =
{
0xD3,0xD4,0xD5,0xD6,0xD7,0xD8,0xD9,0x00,0xDA,0xDB,0xDC,0xDD,_END_,


};
#else
BYTE code tWANGZHI[] =
{
0x41,0x42,0x43,0x44,0x45,0x46,0x47,0x48,0x49,0x4A,0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x59,0x5A,0x5B,0x5C,0x5D,0x5E,0x5F,0x60,0x61,0x00,0x62,0x63,0x64,0x65,0x66,0x67,0x68,0x69,0x6a,0xb9,0xba,0xbb,0xbc,_NEXT_,
0x73,0x74,0x75,0x76,0x77,0x78,0x79,0x7A,0x7B,0x7C,0x7D,0x7E,0x7F,0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,0x90,0x91,0x92,0x93,0x9D,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0xbd,0xbe,0xbf,0xc0,_END_,


};

#endif

BYTE code tOSD_LINE1[] =
{
0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x14,_END_,
};

BYTE code tOSD_LINE_ICON[] =
{
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,_END_,
	
};
BYTE code tOSD_LINE_ICON1[] =
{
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,_END_,
	
};
BYTE code tOSD_LINE_ICON_UP[] =
{
0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,_END_,
	
};

BYTE code tOSD_FREESYNC[] =
{
0x1F,0x20,0x21,0x22,0x23,0x24,0x25,_END_,
	
};

BYTE code tOSD_LINE1_DOWN[] =
{
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,_END_,
};
BYTE code tOSD_LINE1_UP[] =
{
0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,_END_,
};

BYTE code tOSD_LINE2_DOWN[] =
{
0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,_END_,
};
BYTE code tOSD_LINE2_UP[] =
{
0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,0x17,_END_,
};

BYTE code tOSD_LINE_LEFT[] =
{
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_END_,
};

BYTE code tOSD_LINE_RIGHT[] =
{
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_END_,
};

BYTE code tOSD_LINE_LEFT1[] =
{
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_NEXT_,
0x15,_END_,
};

BYTE code tOSD_LINE_RIGHT1[] =
{
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_NEXT_,
0x16,_END_,
};


BYTE code tOSD_BIAN_UP[] =
{
0x01,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x1a,0x03,_END_,	
};

BYTE code tOSD_PIXIO[] =
{
0x26,0x27,0x28,0x29,0x2A,_END_,
};
#if(_OSD_HHT==_ON)

BYTE code tOSD_PIXIO_2BIT[] =
{
0xc1,0xc2,0xc3	,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,_NEXT_,
0xcA,0xcB,0xcC	,0xcD,0xcE,0xcF,0xD0,0xD1,0xD2,_END_,

};
#else
BYTE code tOSD_PIXIO_2BIT[] =
{
0x3D,0x3E,0x3F	,0x40,0x6B,0x6c,_NEXT_,
0x6d,0x6e,0x6f	,0x70,0x71,0x72,_END_,

};

#endif
BYTE code tOSD_BIAN_DOWN[] =
{
0x02,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x1b,0x04,_END_,	
};


BYTE code tOSD_DIAN_LEFT[] =
{

0x1C,_END_,
};


BYTE code tOSD_DIAN_RIGHT[] =
{

0x1D,_END_,
};

BYTE code tOSD_QUAN_LEFT[] =
{

0x15,_END_,
};


BYTE code tOSD_QUAN_RIGHT[] =
{

0x16,_END_,
};





BYTE code tOSD_iREALTEK[] =
{
    _iREALTEK_00, _iREALTEK_01, _iREALTEK_02, _iREALTEK_03, _iREALTEK_04, _iREALTEK_05, _iREALTEK_06, _iREALTEK_07, _iREALTEK_08, _iREALTEK_09, _iREALTEK_0A, _iREALTEK_0B, _NEXT_,
    _iREALTEK_10, _iREALTEK_11, _iREALTEK_12, _iREALTEK_13, _iREALTEK_14, _iREALTEK_15, _iREALTEK_16, _iREALTEK_17, _iREALTEK_18, _iREALTEK_19, _iREALTEK_1A, _iREALTEK_1B, _END_,
};

BYTE code tOSD_iKEY_BACK[] =
{
    _iKEY_BACK_00, _iKEY_BACK_01, _NEXT_,
    _iKEY_BACK_10, _iKEY_BACK_11, _END_,
};

BYTE code tOSD_iKEY_LEFT[] =
{
    _iKEY_LEFT_00, _iKEY_LEFT_01, _NEXT_,
    _iKEY_LEFT_10, _iKEY_LEFT_11, _END_,
};

BYTE code tOSD_iKEY_RIGHT[] =
{
    _iKEY_RIGHT_00, _iKEY_RIGHT_01, _NEXT_,
    _iKEY_RIGHT_10, _iKEY_RIGHT_11, _END_,
};

BYTE code tOSD_iKEY_ENTER[] =
{
    _iKEY_ENTER_00, _iKEY_ENTER_01, _NEXT_,
    _iKEY_ENTER_10, _iKEY_ENTER_11, _END_,
};

BYTE code tOSD_iKEY_EXIT[] =
{
    _iKEY_EXIT_00, _iKEY_EXIT_01, _NEXT_,
    _iKEY_EXIT_10, _iKEY_EXIT_11, _END_,
};

#if(_OSD_LOGO_TYPE ==  _DNA_LOGO)

BYTE code tiOSD_REALTEK_1BIT_LOGO0[]=
{
	0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, _NEXT_,
	0x09,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x09,0x09,0x09,0x14,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x16,0x17,0x09,0x09,0x09,0x09,0x18,0x19,0x19,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09, _NEXT_,
	0x09,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x09,0x09,0x26,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x28,0x29,0x09,0x09,0x09,0x2A,0x27,0x27,0x09,0x09,0x2B,0x2C,0x2D,0x2E,0x09,0x09,0x09,0x09,0x09, _NEXT_,
	0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x09,0x3D,0x3E,0x3F,0x40,0x40,0x40,0x40,0x41,0x3E,0x3E,0x42,0x43,0x44,0x27,0x45,0x46,0x09,0x2A,0x27,0x27,0x09,0x47,0x27,0x48,0x27,0x49,0x4A,0x09,0x09,0x09,0x09, _NEXT_,
	0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x09,0x09,0x51,0x52,0x53,0x54,0x4C,0x55,0x09,0x26,0x27,0x56,0x09,0x09,0x09,0x09,0x57,0x27,0x58,0x59,0x5A,0x5B,0x5C,0x27,0x5D,0x5E,0x5F,0x27,0x60,0x61,0x27,0x62,0x63,0x64,0x27,0x49,0x65,0x09,0x09,0x09, _NEXT_,
	0x66,0x67,0x68,0x69,0x6A,0x27,0x6B,0x6C,0x27,0x6D,0x6E,0x6F,0x70,0x71,0x09,0x26,0x27,0x72,0x73,0x73,0x74,0x75,0x76,0x27,0x77,0x59,0x27,0x27,0x78,0x79,0x7A,0x27,0x27,0x7B,0x7C,0x27,0x7D,0x7E,0x15,0x15,0x7F,0x27,0x80,0x81,0x09,0x09, _NEXT_,
	0x09,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x09,0x09,0x26,0x27,0x27,0x27,0x27,0x27,0x8E,0x8F,0x90,0x91,0x59,0x27,0x27,0x92,0x09,0x93,0x94,0x95,0x96,0x27,0x97,0x98,0x99,0x27,0x27,0x27,0x27,0x27,0x80,0x9A,0x09, _NEXT_,
	0x09,0x09,0x9B,0x9C,0x9D,0x9E,0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0x09,0x09,0x09,0xA5,0xA6,0xA6,0xA6,0xA6,0xA7,0x09,0x09,0x09,0x09,0xA8,0xA6,0xA6,0xA9,0x09,0x09,0x09,0xAA,0xAB,0xAB,0xAC,0xAD,0xAB,0xAB,0xAB,0xAB,0xAB,0xAB,0xAB,0xAE,0x09, _NEXT_,
	0x09,0x09,0x09,0x09,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09, _END_,

};

BYTE code tiOSD_REALTEK_1BIT_LOGO1[]=
{
	0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, _NEXT_,
	0x09,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x09,0x09,0x09,0x14,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x16,0x17,0x09,0x09,0x09,0x09,0x18,0x19,0x19,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09, _NEXT_,
	0x09,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x09,0x09,0x26,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x28,0x29,0x09,0x09,0x09,0x2A,0x27,0x27,0x09,0x09,0x2B,0x2C,0x2D,0x2E,0x09,0x09,0x09,0x09,0x09, _NEXT_,
	0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x09,0x3D,0x3E,0x3F,0x40,0x40,0x40,0x40,0x41,0x3E,0x3E,0x42,0x43,0x44,0x27,0x45,0x46,0x09,0x2A,0x27,0x27,0x09,0x47,0x27,0x48,0x27,0x49,0x4A,0x09,0x09,0x09,0x09, _NEXT_,
	0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x09,0x09,0x51,0x52,0x53,0x54,0x4C,0x55,0x09,0x26,0x27,0x56,0x09,0x09,0x09,0x09,0x57,0x27,0x58,0x59,0x5A,0x5B,0x5C,0x27,0x5D,0x5E,0x5F,0x27,0x60,0x61,0x27,0x62,0x63,0x64,0x27,0x49,0x65,0x09,0x09,0x09, _NEXT_,
	0x66,0x67,0x68,0x69,0x6A,0x27,0x6B,0x6C,0x27,0x6D,0x6E,0x6F,0x70,0x71,0x09,0x26,0x27,0x72,0x73,0x73,0x74,0x75,0x76,0x27,0x77,0x59,0x27,0x27,0x78,0x79,0x7A,0x27,0x27,0x7B,0x7C,0x27,0x7D,0x7E,0x15,0x15,0x7F,0x27,0x80,0x81,0x09,0x09, _NEXT_,
	0x09,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x09,0x09,0x26,0x27,0x27,0x27,0x27,0x27,0x8E,0x8F,0x90,0x91,0x59,0x27,0x27,0x92,0x09,0x93,0x94,0x95,0x96,0x27,0x97,0x98,0x99,0x27,0x27,0x27,0x27,0x27,0x80,0x9A,0x09, _NEXT_,
	0x09,0x09,0x9B,0x9C,0x9D,0x9E,0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0x09,0x09,0x09,0xA5,0xA6,0xA6,0xA6,0xA6,0xA7,0x09,0x09,0x09,0x09,0xA8,0xA6,0xA6,0xA9,0x09,0x09,0x09,0xAA,0xAB,0xAB,0xAC,0xAD,0xAB,0xAB,0xAB,0xAB,0xAB,0xAB,0xAB,0xAE,0x09, _NEXT_,
	0x09,0x09,0x09,0x09,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09, _END_,
};
#endif
#if(_OSD_LOGO_TYPE ==  _NEWSKILL_LOGO)

BYTE code tiOSD_REALTEK_1BIT_LOGO0[]=
{

////////////////////////////////////////////Font Map index////////////////////////////////////////////
0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x00, 0x00, 0x06, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x09, 0x0A, 0x00, 0x00, 0x00, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11,  _NEXT_,
0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1D, 0x1E, 0x00, 0x00, 0x00, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25,  _NEXT_,
0x26, 0x27, 0x28, 0x00, 0x00, 0x29, 0x2A, 0x2B, 0x2C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x2D, 0x2E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x2F, 0x30, 0x31, 0x32, 0x33,  _NEXT_,
0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x2D, 0x2E, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5A, 0x5B, 0x5C, 0x2D, 0x5D,  _NEXT_,
0x00, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x00, 0x69, 0x2D, 0x6A, 0x00, 0x6B, 0x6C, 0x6D, 0x6E, 0x6F, 0x70, 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F, 0x2D, 0x80, 0x81, 0x82, 0x00, 0x83, 0x84, 0x85, 0x86, 0x87, 0x2D, 0x5D,  _NEXT_,
0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x00, 0x00, 0x90, 0x91, 0x92, 0x69, 0x2D, 0x2E, 0x00, 0x93, 0x2D, 0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0x00, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0x2D, 0xA6, 0xA7, 0xA8, 0x37, 0x83, 0x84, 0xA9, 0x5B, 0x87, 0x2D, 0x5D,  _NEXT_,
0xAA, 0x2D, 0xAB, 0x00, 0x00, 0xAC, 0xAD, 0xAE, 0x00, 0x29, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0x00, 0x93, 0x2D, 0x00, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0x00, 0xBA, 0xBB, 0x00, 0xBC, 0xBD, 0xBE, 0x00, 0xBF, 0xC0, 0xC1, 0xC2, 0xC3, 0xB3, 0xB4, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xB3, 0xCC,  _NEXT_,
0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6, 0x2D, 0xD7, 0xD8, 0x00, 0x00, 0x00, 0x00, 0xD9, 0xDA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  _NEXT_,
0x00, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0x00, 0x00, 0xE0, 0xE1, 0xE2, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, _END_,

};

BYTE code tiOSD_REALTEK_1BIT_LOGO1[]=
{
	0x00,0x00,0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, _NEXT_,
	0x09,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x09,0x09,0x09,0x14,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x15,0x16,0x17,0x09,0x09,0x09,0x09,0x18,0x19,0x19,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09, _NEXT_,
	0x09,0x1A,0x1B,0x1C,0x1D,0x1E,0x1F,0x20,0x21,0x22,0x23,0x24,0x25,0x09,0x09,0x26,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x27,0x28,0x29,0x09,0x09,0x09,0x2A,0x27,0x27,0x09,0x09,0x2B,0x2C,0x2D,0x2E,0x09,0x09,0x09,0x09,0x09, _NEXT_,
	0x2F,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x3A,0x3B,0x3C,0x09,0x3D,0x3E,0x3F,0x40,0x40,0x40,0x40,0x41,0x3E,0x3E,0x42,0x43,0x44,0x27,0x45,0x46,0x09,0x2A,0x27,0x27,0x09,0x47,0x27,0x48,0x27,0x49,0x4A,0x09,0x09,0x09,0x09, _NEXT_,
	0x4B,0x4C,0x4D,0x4E,0x4F,0x50,0x09,0x09,0x51,0x52,0x53,0x54,0x4C,0x55,0x09,0x26,0x27,0x56,0x09,0x09,0x09,0x09,0x57,0x27,0x58,0x59,0x5A,0x5B,0x5C,0x27,0x5D,0x5E,0x5F,0x27,0x60,0x61,0x27,0x62,0x63,0x64,0x27,0x49,0x65,0x09,0x09,0x09, _NEXT_,
	0x66,0x67,0x68,0x69,0x6A,0x27,0x6B,0x6C,0x27,0x6D,0x6E,0x6F,0x70,0x71,0x09,0x26,0x27,0x72,0x73,0x73,0x74,0x75,0x76,0x27,0x77,0x59,0x27,0x27,0x78,0x79,0x7A,0x27,0x27,0x7B,0x7C,0x27,0x7D,0x7E,0x15,0x15,0x7F,0x27,0x80,0x81,0x09,0x09, _NEXT_,
	0x09,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x09,0x09,0x26,0x27,0x27,0x27,0x27,0x27,0x8E,0x8F,0x90,0x91,0x59,0x27,0x27,0x92,0x09,0x93,0x94,0x95,0x96,0x27,0x97,0x98,0x99,0x27,0x27,0x27,0x27,0x27,0x80,0x9A,0x09, _NEXT_,
	0x09,0x09,0x9B,0x9C,0x9D,0x9E,0x9F,0xA0,0xA1,0xA2,0xA3,0xA4,0x09,0x09,0x09,0xA5,0xA6,0xA6,0xA6,0xA6,0xA7,0x09,0x09,0x09,0x09,0xA8,0xA6,0xA6,0xA9,0x09,0x09,0x09,0xAA,0xAB,0xAB,0xAC,0xAD,0xAB,0xAB,0xAB,0xAB,0xAB,0xAB,0xAB,0xAE,0x09, _NEXT_,
	0x09,0x09,0x09,0x09,0xAF,0xB0,0xB1,0xB2,0xB3,0xB4,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09,0x09, _END_,
};
#endif

//****************************************************************************
// VARIABLE DECLARATIONS
//****************************************************************************

//****************************************************************************
// FUNCTION DECLARATIONS
//****************************************************************************
void OsdFontPut1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor);
void OsdFontPut1BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor);
void OsdFontPut1BitMainMenuIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground);
void OsdFontPut2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);
void OsdFontPut2BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3);

//***************************************************************************
// FUNCTION DEFINITIONS
//****************************************************************************
//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut1Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor)
{
    WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
    BYTE xdata ucByte0 = 0x4C;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usOsdAddr = (WORD)((g_ucOsdWidth - ucRow - 1) + g_ucOsdWidth * ucCol);
        ucByte0 = 0x4E;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
        ucByte0 = 0x4E;
    }
#endif

    ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucColor);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut1BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor)
{
    BYTE ucOsdWidth = 0;
    BYTE ucCount = 0;
    BYTE ucHTemp = ucCol;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucOsdWidth = g_ucOsdHeight;
    }
    else
#endif
    {
        ucOsdWidth = g_ucOsdWidth;
    }

    while(*pucArray != _END_)
    {
        if(*pucArray == _NEXT_)
        {
            ucRow++;
            ucHTemp =ucCol;
            pucArray++;
        }
        else if(*pucArray == _SPACE_)
        {
            ucHTemp++;
            pucArray++;
        }
        else if(*pucArray == _REPEAT_)
        {
            ucCount = *(pucArray + 1) - 1;

            while(ucCount > 0)
            {
                if(*(pucArray - 1) != _SPACE_)
                {
                    OsdFontPut1Bit(ucRow, ucHTemp, *(pucArray - 1), ucColor);
                }

                ucHTemp++;

                if((ucHTemp == ucOsdWidth) && (*(pucArray + 1) != _NEXT_))
                {
                    ucRow++;
                    ucHTemp =ucCol;
                }
                ucCount--;
            }
            pucArray += 2;
        }
        else
        {
            OsdFontPut1Bit(ucRow, ucHTemp, *pucArray, ucColor);
            ucHTemp++;

            if((ucHTemp == ucOsdWidth) && (*(pucArray + 1) != _NEXT_))
            {
                ucRow++;
                ucHTemp =ucCol;
            }
            pucArray++;
        }
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut1BitMainMenuIcon(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucForeground, BYTE ucBackground)
{
    WORD usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
    BYTE ucByte0 = 0x4C;
    BYTE ucByte2 = 0;
    BYTE ucLength = 6;
    BYTE ucHeight = 4;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usOsdAddr = (WORD)((g_ucOsdWidth - ucRow - 1) + g_ucOsdWidth * ucCol);
        ucByte0 = 0x4E;
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
        ucByte0 = 0x4E;
    }
#endif

    ucForeground &= 0x0F;

    ucByte2 = ((ucForeground << 4) | ucBackground);

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        for(ucHeight = 0; ucHeight < 4; ucHeight++)
        {
            for(ucLength=0; ucLength < 6; ucLength++)
            {
                usOsdAddr = (WORD)(g_ucOsdWidth - ucRow - ucHeight - 1) + g_ucOsdWidth * (ucCol + ucLength);
                ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);
                ucIcon++;
            }
        }
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        for(ucHeight = 0; ucHeight < 4; ucHeight++)
        {
            for(ucLength=0; ucLength < 6; ucLength++)
            {
                usOsdAddr = (WORD)(g_ucOsdHeight - 1 - (ucCol + ucLength)) * g_ucOsdWidth + (ucRow + ucHeight);
                ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);
                ucIcon++;
            }
        }
    }
    else
#endif
    {
        for(ucHeight = 0; ucHeight < 4; ucHeight++)
        {
            for(ucLength=0; ucLength < 6; ucLength++)
            {
                ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart + ucLength, ucByte0, ucIcon, ucByte2);
                ucIcon++;
            }
            usOsdAddr += g_ucOsdWidth;
        }
    }
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut2Bit(BYTE ucRow, BYTE ucCol, BYTE ucIcon, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3)
{
    WORD xdata usOsdAddr = (WORD)ucRow * g_ucOsdWidth + ucCol;
    BYTE xdata ucByte0 = 0;
    BYTE xdata ucByte2 = 0;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90)
    {
        usOsdAddr = (WORD)((g_ucOsdWidth - ucRow - 1) + g_ucOsdWidth * ucCol);
    }
    else if(GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270)
    {
        usOsdAddr = (WORD)(g_ucOsdHeight - 1 - ucCol) * g_ucOsdWidth + ucRow;
    }
#endif

    ucColor0 &= 0x0F;
    ucByte0 = (0x80) | ((ucColor0 & _BIT3) << 2) | ((ucColor1 & _BIT3) << 1) | ((ucColor3 & 0x07) << 1) | ((ucColor0 & _BIT2) >> 2);

	ucByte2 = ((ucColor0 & 0x03) << 6) | ((ucColor2 & 0x07) << 3) | (ucColor1 & 0x07);

    ScalerOsdCommandAllByte(usOsdAddr + g_usFontSelectStart, ucByte0, ucIcon, ucByte2);
}

//--------------------------------------------------
// Description  :
// Input Value  : None
// Output Value : None
//--------------------------------------------------
void OsdFontPut2BitTable(BYTE ucRow, BYTE ucCol, BYTE *pucArray, BYTE ucColor0, BYTE ucColor1, BYTE ucColor2, BYTE ucColor3)
{
    BYTE ucOsdWidth = 0;
    BYTE ucCount = 0;
    BYTE ucHTemp = ucCol;

#if(_OSD_ROTATE_FUNCTION == _OSD_ROTATE_SOFTWARE)
    if((GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_90) ||
       (GET_OSD_ROTATE_STATUS() == _OSD_ROTATE_DEGREE_270))
    {
        ucOsdWidth = g_ucOsdHeight;
    }
    else
#endif
    {
        ucOsdWidth = g_ucOsdWidth;
    }

    while(*pucArray != _END_)
    {
        if(*pucArray == _NEXT_)
        {
            ucRow++;
            ucHTemp =ucCol;
            pucArray++;
        }
        else if(*pucArray == _SPACE_)
        {
            ucHTemp++;
            pucArray++;
        }
        else if(*pucArray == _REPEAT_)
        {
            ucCount = *(pucArray + 1) - 1;

            while(ucCount > 0)
            {
                if(*(pucArray - 1) != _SPACE_)
                {
                    OsdFontPut2Bit(ucRow, ucHTemp, *(pucArray - 1), ucColor0, ucColor1, ucColor2, ucColor3);
                }

                ucHTemp++;

                if((ucHTemp == ucOsdWidth) && (*(pucArray + 1) != _NEXT_))
                {
                    ucRow++;
                    ucHTemp =ucCol;
                }
                ucCount--;
            }
            pucArray += 2;
        }
        else
        {
            OsdFontPut2Bit(ucRow, ucHTemp, *pucArray, ucColor0, ucColor1, ucColor2, ucColor3);
            ucHTemp++;

            if((ucHTemp == ucOsdWidth) && (*(pucArray + 1) != _NEXT_))
            {
                ucRow++;
                ucHTemp = ucCol;
            }
            pucArray++;
        }
    }
}

//void OsdFontPut4Bit()
//{
//}

//void OsdFontPut4BitTable()
//{
//}

#endif//#if(_OSD_TYPE == _REALTEK_2014_OSD)
