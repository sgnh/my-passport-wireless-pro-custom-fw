#ifndef EEPROM_H
#define EEPROM_H

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sysdefs.h>
#include "I2CUtil.h"


#if 1  //def SETUPCLASSSQLITEEEPROM_DEBUG
	#define EEP_PRINT(fmt,args...)	printf(fmt,## args)
#else
	#define EEP_PRINT(fmt,args...)	
#endif


#define ENV_ATTR_USER	0
#define ENV_ATTR_RO	1
#define ENV_ATTR_RW	2
#define NULL            0
#define OK              0
#define NOK             1
//extern bool env_mac_s2num(char *raw,	void *decoded,UINT32 size );
    
#define FALSE		(0)
#define TRUE			(1)
#define false		(0)
#define true			(1)

#ifndef UINT8
typedef  unsigned char UINT8;
#endif
#ifndef UINT16
typedef  unsigned short UINT16;
#endif
#ifndef UINT32
typedef  unsigned int UINT32;
#endif
#ifndef INT8
typedef  char INT8;
#endif
#ifndef INT16
typedef  short INT16;
#endif
#ifndef INT32
typedef  int INT32;
#endif
#ifndef bool
typedef int bool;
#endif
#ifndef BOOL
typedef int BOOL;
#endif


#define R_ERR_FAILED		(0)
#define R_ERR_RX_ERROR		(0)
#define R_ERR_SUCCESS		(1)

#define EEPROM_ADDR 		(0XA0 >> 1)

#define SRUTIL_EEPROM_PAGE_SIZE	32

#define EEPROM_EREASE_BLOCK_SIZE	32

#pragma pack(1) /* bytes alignment */ /* very dangerous, must use carefully */
// Used total EPROM bytes = 256*sizeof(EEPROM_ATV_CHANNEL_INFO)
typedef struct _EEPROM_ATV_CHANNEL_INFO
{
    UINT32 freq;
    UINT8 chNum:8;
    UINT8 colorStd:4;
    UINT8 defaultcolorstd:4;
    UINT8 soundStd:4;
    UINT8 skip:1;
    UINT8 afcEnable:1;
    UINT8 isFake:1;
    UINT8 reserved:1;
    INT8 vol_compensation;
} EEPROM_ATV_CHANNEL_INFO;
#pragma pack()  /* restore original alignment from stack */ /* MUST DO IT */


#define HDCP_KEY_SIZE       329
#define SERIAL_CODE_SIZE    32
#define MAX_CHAN_NUM        256
#define MAX_SOURCE_NUM      8   //atv, av, ypp, vga, hdmi1, hdmi2, hdmi3, playback
#define MAC_SIZE            6

#define EEPROM_BSIZE	4096		// total 4K byte
//#define EEPROM_BSIZE	8192		// total 8K byte

typedef enum _EEP_ADD_MAP 
{
    EEP_AD_START = 0,
    
    EEP_AD_DATE = EEP_AD_START,
    EEP_AD_DATE_END	= EEP_AD_DATE + 5 + (-1),   // + (-1) for next item
    
    EEP_AD_SERIALCODE_IDENT,
    EEP_AD_SERIALCODE_IDENT_END = EEP_AD_SERIALCODE_IDENT + 2 + (-1),   // + (-1) for next item
    
    EEP_AD_SERIALCODE,
    EEP_AD_SERIALCODE_END = EEP_AD_SERIALCODE + SERIAL_CODE_SIZE + (-1),    // + (-1) for next item
    
    EEP_AD_HDCPKEY,
    EEP_AD_HDCPKEY_END = EEP_AD_HDCPKEY + HDCP_KEY_SIZE + (-1),
    
    EEP_AD_MAC,
    EEP_AD_MAC_END = EEP_AD_MAC + MAC_SIZE + (-1),
    
    EEP_AD_VIP_STORE_INIT_FLAG,  //380
    EEP_AD_VIP_STORE_END = EEP_AD_VIP_STORE_INIT_FLAG + 1 + (-1),
    EEP_AD_RESV1,
    EEP_AD_RESV1_END = EEP_AD_RESV1 + 4 + (-1),
    
    EEP_AD_CHANNEL_VERIFY,
    EEP_AD_CHANNEL_VERIFY_END = EEP_AD_CHANNEL_VERIFY + 2 + (-1),
    
    EEP_AD_CHANNEL_INFO,
    EEP_AD_CHANNEL_INFO_END = EEP_AD_CHANNEL_INFO + sizeof(EEPROM_ATV_CHANNEL_INFO)*MAX_CHAN_NUM + (-1),
    
    EEP_AD_SYS_IDENT1,
    EEP_AD_SYS_IDENT1_END = EEP_AD_SYS_IDENT1 + 1 + (-1),
	
} EEP_ADD_MAP;




typedef struct _SOFTI2C_WRITE {
	UINT32 clkGPIO;
	UINT32 dataGPIO;
	UINT8  wLen;
	UINT8* pWriteBuf;
} SOFTI2C_WRITE;

typedef struct _SOFTI2C_READ {
	UINT32 clkGPIO;
	UINT32 dataGPIO;
	UINT8  wLen;
	UINT8* pReadBuf;
} SOFTI2C_READ;

int Eeprom_Write(UINT16 start, UINT16 w_len, UINT8* write_buf);
int Eeprom_Read(UINT16 start, UINT16 r_len, UINT8* read_buf);
bool Eeprom_SetMacAddressToKernel_Read(void);
bool Eeprom_SetMacAddressToKernel_Apply(void);
#endif

