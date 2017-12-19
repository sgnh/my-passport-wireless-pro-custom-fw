#ifndef __RTK_G2C_LIB_H__
#define __RTK_G2C_LIB_H__


void G2C_Init(unsigned char Id);
void G2C_UnInit(unsigned char Id);


int G2C_Write_EX(
    unsigned char 			Id,
    unsigned char          	chipAddr, 
    int         				regLen, 
    unsigned char*          regOffset,     
    int          				wDataLen, 
    unsigned char*          wData
     );

int G2C_Read_EX(
    unsigned char           Id,
    unsigned char           chipAddr, 
    int         				regLen, 
    unsigned char*          regOffset, 
    int         				rDataLen, 
    unsigned char*          rData  
    );

int G2C_SetSpeed(unsigned char Id, int KHz);

unsigned char G2C_GetBusCount(void);

int G2C_Test_EX(unsigned char Id, unsigned char chipAddr); 


#endif

