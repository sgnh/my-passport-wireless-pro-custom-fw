#ifndef __I2CUTIL_H__
#define __I2CUTIL_H__

#define I2C_Read(args...)                I2C_Read_EX(0, args)
#define I2C_Write(args...)               I2C_Write_EX(0, args)

//#define MAX_I2C_CNT                      3
//#define FIFO_THRESHOLD                   4
//#define DEFAULT_SPEED                    100

#define S_OK         0
#define S_FALSE     -1


int I2C_Write_EX(unsigned char id, unsigned short Addr, unsigned short nData, unsigned char* pData);
int I2C_Read_EX(unsigned char id, unsigned short Addr, unsigned short nSubAddr, unsigned char* pSubAddr, unsigned short nData, unsigned char* pData);
int I2C_SetSpeed(unsigned char Id, int KHz);

int I2C_StartXfer(
    unsigned char           Id,     
    unsigned short          Addr, 
    unsigned short          nSubAddr, 
    unsigned char*          pSubAddr, 
    unsigned short          nData, 
    unsigned char*          pData    
    );

void I2C_Set_SUB_SDA_SRC(unsigned char i2c_Id, unsigned char sub_SDA_SRC_Id);

#endif

