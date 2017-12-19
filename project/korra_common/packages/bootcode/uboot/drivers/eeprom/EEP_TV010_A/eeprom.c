#include <common.h>
#include <command.h>
#include <environment.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sysdefs.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <linux/string.h>
//#include <sysdefs.h>
//#include "sysdefs.h"
#include "I2CUtil.h"
//#include <Platform_Lib/Board/pcbMgr.h>
#include <platform_lib/board/pcb_mgr.h>
#include <common.h>
#include <command.h>
#include <malloc.h>
#include <linux/compiler.h>
#include <asm/io.h>
//#include "AudioAmp.h"
#include "../../i2c/rtk_g2c-lib.h"

#include "I2CUtil.h"
#include "eeprom.h"

static unsigned char m_SHUTDOWN_EEP = 0;

static unsigned long long m_EEP_I2C=0, m_EEP_DEVICE_ADDR=0, m_PIN_EEP_WP=0;


UINT8 writeBuffer[EEPROM_EREASE_BLOCK_SIZE*2];
UINT8 subaddr[EEPROM_EREASE_BLOCK_SIZE*2];

static unsigned char mac_addr[16];
static unsigned char eep_mac_retOk = 0;

/************************************************************************
 *
 *                          env_mac_s2num
 *  Description :
 *  -------------
 *
 *  Decode a string of format xx.xx.xx.xx.xx.xx to 6 bytes
 *
 *  Return values :
 *  ---------------
 *
 *  TRUE -> OK, FALSE -> Failed
 *
 ************************************************************************/
 /* MAC address type (Ethernet address). */
#define SYS_MAC_ADDR_SIZE   6
typedef UINT8    t_mac_addr[SYS_MAC_ADDR_SIZE];

bool
env_mac_s2num(
    char *raw,                  /* The string                           */
    void *decoded,              /* Decoded data                         */
    UINT32 size )               /* Size of decoded data                 */
{
    t_mac_addr *mac_addr;
    char       *endp;
    UINT8      number;
    UINT32     i;
    int errno;

    if( !raw || (strlen(raw) != 5+6*2) )
        return FALSE;

    if( decoded && (size != sizeof(t_mac_addr)) )
        return FALSE;

    mac_addr = (t_mac_addr *)decoded;
    errno    = 0;

    for( i=0; i<sizeof(t_mac_addr); i++)
    {
        if( *raw == '\0' )
            return FALSE;

        number = strtoul( raw, &endp, 16 );
        if( errno )
            return FALSE;
        if( endp == raw )
            return FALSE;

        raw = &endp[1];

        if( mac_addr )
            (*mac_addr)[i] = number;
    }

    return (*endp == '\0') ? TRUE : FALSE;
}

static int EEP_I2C_Write_EX(
    unsigned char           Id,
    unsigned short          Addr,
    unsigned short          nData,
    unsigned char*          pData
    )
{
	if (!m_EEP_DEVICE_ADDR)
		return S_FALSE;

	UINT8 addr[2],data[32],i;
	addr[0] = pData[0];
	addr[1] = pData[1];

	for(i=2;i<nData;i++)
		data[i-2] = pData[i];

	//printf("AudioAmp_AdoAmp_Tas5711L_write!!!!!\n");
	if(Id < PCB_I2C_3)	{
		if (I2C_Write_EX(Id, Addr, nData, pData) != S_OK) {
			return S_FALSE;
		}
	}
	else		{
		//printf("G2C_Write_EX!!!!!\n");
		if (G2C_Write_EX(Id, Addr, 2, addr, nData-2, data) != S_OK) {
			return S_FALSE;
		}
	}

	return S_OK;
}

static int EEP_I2C_Read_EX(
    unsigned char           Id,
    unsigned short          Addr,
    unsigned short          nSubAddr,
    unsigned char*          pSubAddr,
    unsigned short          nData,
    unsigned char*          pData
    )
{
	if (!m_EEP_DEVICE_ADDR)
		return S_FALSE;

	//printf("AudioAmp_AdoAmp_Tas5711L_write!!!!!\n");
	if(Id < PCB_I2C_3)	{
		if (I2C_Read_EX(Id, Addr, nSubAddr, pSubAddr, nData, pData) != S_OK) {
			return S_FALSE;
		}
	}
	else		{
		//printf("G2C_Write_EX!!!!!\n");
		if (G2C_Read_EX(Id, Addr, nSubAddr, pSubAddr, nData, pData) != S_OK) {
			return S_FALSE;
		}
	}

	return S_OK;
}


static int mEeprom_Init(void)
{
	static bool isNotFirst = false;
	if (!isNotFirst) {
		unsigned long long value=0;
		isNotFirst = true;
		if (pcb_mgr_get_enum_info_byname("EEP_I2C", &value) < 0) {
			m_EEP_I2C = 0;
			printf("no EEP_I2C\n");
		} else {
			m_EEP_I2C = value;
			printf("EEP_I2C=%lld\n", m_EEP_I2C);
		}
		
		if (pcb_mgr_get_enum_info_byname("EEP_DEVICE_ADDR", &value) < 0) {
			m_EEP_DEVICE_ADDR = 0;
		} else {
			m_EEP_DEVICE_ADDR = value;
			//m_EEP_DEVICE_ADDR = 0xBB;
		}
		
		if (pcb_mgr_get_enum_info_byname("PIN_EEP_WP", &value) < 0) {
			m_PIN_EEP_WP = 0;
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
			printf("\033[1;31m m_PIN_EEP_WP = 0 \033[m\n");
		} else {
			m_PIN_EEP_WP = value;
			printf("m_PIN_EEP_WP = 0x%llx\n", m_PIN_EEP_WP);
		}

		if (m_EEP_I2C <= PCB_I2C_2)
			I2C_Init();
		else
			G2C_Init(m_EEP_I2C);		
	}

	return R_ERR_SUCCESS;
}

int Eeprom_Write(UINT16 start, UINT16 w_len, UINT8* write_buf)
{
#ifdef ENABLE_EEPROM_USE_FILE_SIMULATION
	return R_ERR_RX_ERROR;
#endif

EEP_PRINT("\033[1;31mee write %d, %d\033[m\n", start, w_len);
//EEP_PRINT("\033[1;31mee write\033[m\n");

	if (m_SHUTDOWN_EEP) {
		printf("\033[1;31m %s %s %d: EEPROM ERROR, shutdown operations\033[m\n", __FILE__, __FUNCTION__, __LINE__);
		return R_ERR_RX_ERROR;
	}

	UINT16 orig_start = start;
	UINT16 orig_w_len = w_len;
	UINT8* orig_write_buf = write_buf;
	int i = 0;
	
	mEeprom_Init();
	
#if 1
	SOFTI2C_WRITE	writeData;
	UINT8* dataBuffer = NULL ;
	UINT8* pwritebuf = write_buf ;
	UINT16 add = start  , len = 0 ;
	
	if(w_len<1||write_buf==NULL )
		return R_ERR_RX_ERROR;
	//Rt_Delay(50); //cs101109 for eeprm save err
	while(w_len)
	{
		add++ ;
		len++ ;
		if( (add % 32) == 0)
		{
			if(w_len < len )
				len = w_len ;

			memset(writeBuffer, 0, sizeof(writeBuffer));
			dataBuffer=(UINT8 *)writeBuffer;
			if(dataBuffer==NULL)
				return R_ERR_RX_ERROR;
			
			memcpy((void *)&dataBuffer[2],(void *)pwritebuf , len ) ;

			//*(UINT16 *)&dataBuffer[0] = start ;
			dataBuffer[0] = (UINT8)(start>>8);
			dataBuffer[1] = (UINT8)(start & 0x00FF);
			
			writeData.wLen		= len+2;
			writeData.pWriteBuf	= dataBuffer;

			if (m_PIN_EEP_WP)
				IO_Set(m_PIN_EEP_WP, 0);


		//	if (I2C_SetSpeed(I2C_MASTER, I2C_SPEED)  != S_OK) 
		//		return R_ERR_RX_ERROR;

			for (i=0; i<10; i++) {
				if (EEP_I2C_Write_EX(m_EEP_I2C, m_EEP_DEVICE_ADDR, writeData.wLen, writeData.pWriteBuf) != S_OK) {
					//printf("\033[1;33m %s %s %d: EEP_I2C_Write_EX NG, try again --%d\033[m\n", __FILE__, __FUNCTION__, __LINE__, i);
					udelay(40000);	//re-try no need busy wait 	//important!! one write cycle must delay 5~10ms, must not be removed
					//communicateToWatchDog();
					if (i==9) {
						printf("\033[1;31m %s %s %d: EEP_I2C_Write_EX Error\033[m\n", __FILE__, __FUNCTION__, __LINE__);
						m_SHUTDOWN_EEP = 1; //shutdown eeprom read/write
						//RT_FREE(RT_USER_AP, (void**)&dataBuffer);
						udelay(40000);		//important!! one write cycle must delay 5~10ms, must not be removed
						return R_ERR_RX_ERROR;
					}
				}
				else {
					//S_OK, leave re-try
					break;
				}
			}

			//printf("\033[1;32m addr 0x%x, 0x%x-0x%x : W = ", start, writeData.pWriteBuf[0], writeData.pWriteBuf[1]);
			//RT_FREE(RT_USER_AP, (void**)&dataBuffer);
			udelay(40000);		//important!! one write cycle must delay 5~10ms, must not be removed

			if(len == w_len) break ;
			w_len -= len ;
			start += len ;
			pwritebuf += len ;
			add = start ;
			len = 0 ;
			//Rt_Delay(50);  //cs101109 for eeprm save err that page1 & page 3 data is 0				
		}
		
	}

	if (m_PIN_EEP_WP)
		IO_Set(m_PIN_EEP_WP, 1); //lock

	return R_ERR_SUCCESS;
#else
	return R_ERR_FAILED;
#endif

}

int Eeprom_Read(UINT16 start, UINT16 r_len, UINT8* read_buf)
{
#ifdef ENABLE_EEPROM_USE_FILE_SIMULATION
	return R_ERR_RX_ERROR;
#endif


EEP_PRINT("\033[1;34mee read %d, %d\033[m\n", start, r_len);
//EEP_PRINT("\033[1;34mee read\033[m\n");

	if (m_SHUTDOWN_EEP) {
		printf("\033[1;31m %s %s %d: EEPROM ERROR, shutdown operations\033[m\n", __FILE__, __FUNCTION__, __LINE__);
		return R_ERR_RX_ERROR;
	}
	
	UINT16 orig_start = start;
	UINT16 orig_r_len = r_len;
	UINT8* orig_read_buf = read_buf;
	int i = 0;
	
	mEeprom_Init();


	SOFTI2C_READ	readData;
	UINT8* dataBuffer=NULL;
	UINT8* preadbuf = read_buf ;
	UINT16 add = start  , len = 0 ;
	if(r_len<1||read_buf==NULL ) {
		printf("\033[1;31m %s %s %d: EEP_I2C_Read_EX\033[m\n", __FILE__, __FUNCTION__, __LINE__);
		return R_ERR_RX_ERROR;
	}
	
	//Rt_Delay(50);  //cs101109 for eeprm save err
	//printf("\033[1;31m %s %s %d: EEP_I2C_Read_EX\033[m\n", __FILE__, __FUNCTION__, __LINE__);
	while(r_len)
	{
		//printf("\033[1;31m %s %s %d: EEP_I2C_Read_EX\033[m\n", __FILE__, __FUNCTION__, __LINE__);
		add++ ;
		len++ ;
		if(add%32 == 0)
		{
			if(r_len < len )
				len = r_len ;

			memset(writeBuffer, 0, sizeof(writeBuffer));
			dataBuffer=(UINT8 *)writeBuffer;
			if(dataBuffer==NULL)
				return R_ERR_RX_ERROR;

			memset(subaddr, 0, sizeof(subaddr));
			UINT8* pSubAddr = (UINT8 *)subaddr;
			//*(UINT16 *)&pSubAddr[0] = start;
			pSubAddr[0] = (UINT8)(start>>8);
			pSubAddr[1] = (UINT8)(start & 0x00FF);
			
			readData.wLen		= len;
			readData.pReadBuf	= dataBuffer;

			for (i=0; i<10; i++) {
				//printf("\033[1;31m %s %s %d: EEP_I2C_Read_EX\033[m\n", __FILE__, __FUNCTION__, __LINE__);
				if (EEP_I2C_Read_EX(m_EEP_I2C, m_EEP_DEVICE_ADDR, 2, pSubAddr, readData.wLen, readData.pReadBuf) != S_OK) {
					//printf("\033[1;33m %s %s %d: EEP_I2C_Read_EX NG, try again --%d\033[m\n", __FILE__, __FUNCTION__, __LINE__, i);
					udelay(40000);  //re-try no need busy wait 
					if (i==9) {
						printf("\033[1;31m %s %s %d: EEP_I2C_Read_EX Error\033[m\n", __FILE__, __FUNCTION__, __LINE__);
						m_SHUTDOWN_EEP = 1;
						//RT_FREE(RT_USER_AP, (void**)&dataBuffer);
						//RT_FREE(RT_USER_AP, (void**)&pSubAddr);
						return R_ERR_RX_ERROR;
					}
				}
				else {
					//S_OK, leave re-try
					break;
				}
			}

			memcpy((void *)preadbuf,(void *)&dataBuffer[0],len);
			
			if(len == r_len) break ;
			preadbuf += len ;
			r_len -= len ;
			start += len ;
			add = start ;
			len = 0 ;
			//Rt_Delay(50); //cs101109 for eeprm save err that page1 & page 3 data is 0			
		}
	}

	return R_ERR_SUCCESS;

}

bool Eeprom_Dump_AllContent(void)
{
	UINT8 read_buf[32];
	int k = 0;
	unsigned int j = 0;

	memset(read_buf,0x00, 32);

	for (k=0;k < EEPROM_BSIZE/EEPROM_EREASE_BLOCK_SIZE/8; k++) {	//i only dump top half half.
		Eeprom_Read(k*EEPROM_EREASE_BLOCK_SIZE, EEPROM_EREASE_BLOCK_SIZE,  read_buf);
		printf("\033[1;43m read k = %d\n", k);
		//printf("\033[1;43m k = %d, EEPROM_BSIZE=%d, EEPROM_EREASE_BLOCK_SIZE=%d, A/B=%d\n", k, EEPROM_BSIZE, EEPROM_EREASE_BLOCK_SIZE, EEPROM_BSIZE/EEPROM_EREASE_BLOCK_SIZE);
		for (j = 0; j < sizeof(read_buf); j++) {
			if (j!=0 && j%8 == 0)
				printf("\n");
			printf("\033[1;43m0x%02x ", read_buf[j]);
		}
		printf("\033[m\n");
		udelay(20000);
	}
	
	return TRUE;	
}

bool Eeprom_Reset(void)
{
	UINT8 writeBuffer[EEPROM_EREASE_BLOCK_SIZE];
	INT32 i;

	mEeprom_Init();
	
	memset(writeBuffer,0xFF, EEPROM_EREASE_BLOCK_SIZE);

	//Eeprom_Reset from EEP_AD_CHANNEL_VERIFY(0x17b)
	//printf("Eeprom_Reset from EEP_AD_CHANNEL_VERIFY(0x%x)\n", EEP_AD_CHANNEL_VERIFY);
	
	for(i = 0; i < 4 ; i++){
		printf("reset EEP_AD_CHANNEL_VERIFY block %d\n",i);
		if(Eeprom_Write(i*EEPROM_EREASE_BLOCK_SIZE + EEP_AD_CHANNEL_VERIFY, EEPROM_EREASE_BLOCK_SIZE, writeBuffer) == R_ERR_RX_ERROR) {
			printf("SrAv_24C64_EEPROM_Write fail!!!\n");
			return FALSE;
		}
	}
	for(i = 0; i < 4 ; i++){
		printf("reset EEP_AD_SYS_IDENT1 block %d\n",i);
		if(Eeprom_Write(i*EEPROM_EREASE_BLOCK_SIZE + EEP_AD_SYS_IDENT1, EEPROM_EREASE_BLOCK_SIZE, writeBuffer) == R_ERR_RX_ERROR) {
			printf("SrAv_24C64_EEPROM_Write fail!!!\n");
			return FALSE;
		}
	}
	return TRUE;	
}


bool Eeprom_SetMacAddressToKernel_Read(void)
{
	//add by skyworth-longchao for set MAC addr
	//unsigned char mac_addr[16];
	char set_mac_cmd[100];
	char       *raw = NULL;
	
#if 0 //test use
	mac_addr[0]= 0x00;
	mac_addr[1]= 0x1a;
	mac_addr[2]= 0x9a;
	mac_addr[3]= 0x66;
	mac_addr[4]= 0x88;
	mac_addr[5]= 0xEE;
	Eeprom_Write(EEP_AD_MAC, MAC_SIZE, mac_addr);
	printf("\033[1;31m Eeprom_Write hack mac address\033[m\n");
#endif

	memset(mac_addr, 0x00, 6);
	if (Eeprom_Read(EEP_AD_MAC, MAC_SIZE, mac_addr) == R_ERR_SUCCESS) {
		printf("a. Eeprom_Read-macaddr is %02x%02x%02x%02x%02x%02x\n",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
		eep_mac_retOk = 1;
	}
	else {
		printf("\033[1;31m a. Eeprom_Read mac fail\033[m\n");
		eep_mac_retOk = 0;
	}
	
	return 0;
}

bool Eeprom_SetMacAddressToKernel_Apply(void)
{
	//add by skyworth-longchao for set MAC addr
	//unsigned char mac_addr[16];
	char set_mac_cmd[100];
	char       *raw = NULL;
	
#if 0 //test use
	mac_addr[0]= 0x00;
	mac_addr[1]= 0x1a;
	mac_addr[2]= 0x9a;
	mac_addr[3]= 0x66;
	mac_addr[4]= 0x88;
	mac_addr[5]= 0xEE;
	Eeprom_Write(EEP_AD_MAC, MAC_SIZE, mac_addr);
	printf("\033[1;31m Eeprom_Write hack mac address\033[m\n");
#endif

	//printf("bbb. Eeprom_Read-macaddr is %02x%02x%02x%02x%02x%02x\n",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
	if (eep_mac_retOk) {
		//printf("b. Eeprom_Read-macaddr is %02x%02x%02x%02x%02x%02x\n",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
		if (mac_addr[0] == 0xFF) {
			printf("\033[1;31m mac_addr[0]==0xFF, skip set_mac_cmd\033[m\n");
		}
		else if (mac_addr[0] == 0x00 && mac_addr[1] == 0x00 && mac_addr[2] == 0x00) {
			printf("\033[1;31m mac_addr[0][1][2]==0x00, skip set_mac_cmd\033[m\n");
		}
		else if (mac_addr[0] == mac_addr[1] ) {
			printf("\033[1;31m mac_addr[0] == mac_addr[1], skip set_mac_cmd\033[m\n");
		}
		else {
			sprintf(set_mac_cmd,"%02x:%02x:%02x:%02x:%02x:%02x",mac_addr[0],mac_addr[1],mac_addr[2],mac_addr[3],mac_addr[4],mac_addr[5]);
			printf("\033[1;31m set_mac_cmd is %s \033[m\n",set_mac_cmd);
			raw = &set_mac_cmd;
			//if( env_set( "ethaddr", raw, ENV_ATTR_RW, raw, env_mac_s2num ) != OK ) {
			//	printf("\033[1;31m set_mac_cmd fail\033[m\n");
			//}
			if (setenv("ethaddr", set_mac_cmd)  != OK) {
				printf("\033[1;31m set_mac_cmd fail\033[m\n");
			}
		}
	}
	else {
		printf("\033[1;31m b. Eeprom_Read mac fail\033[m\n");
	}
	
	return 0;
}


