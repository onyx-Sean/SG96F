



#define __BANK4__

#include "SysInclude.h"


WORD	ISP_Check_Bank4_Sum()
{	  
	BYTE code *p;
	WORD ucCheckSum = 0x00;
	
	p = 0x0000;
	
	do{
			ucCheckSum	+= *p;
			p++;

	}while(p<=0xFFFE);
	
	ucCheckSum	+= *p;


	return ucCheckSum;
}



