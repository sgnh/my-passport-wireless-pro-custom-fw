//#include <stdio.h>
//#include <stdlib.h>
#include <linux/string.h>
//#include <sysdefs.h>
#include "I2CUtil.h"
//#include <Platform_Lib/Board/pcbMgr.h>
#include <platform_lib/board/pcb_mgr.h>
#include <common.h>
#include <command.h>
#include <malloc.h>
#include <linux/compiler.h>
#include <asm/io.h>
#include "AudioAmp.h"

static unsigned long long m_I2C_MASTER=0, m_AMP_DEVICE_ADDR=0, m_PIN_AMP_MUTE=0;
static unsigned long long m_PIN_951_RST=0;
#if 0
#if defined(BOARD_ID_RTD2974_HISENSE_V1)|| defined(BOARD_ID_RTD2974_HISENSE_V2)
static unsigned long long m_PIN_HEADPHONE_PLUG_IN=0;
#endif
#endif

#define ENABLE_AMP_USE_HW_I2C


#define ErrCode int
#define R_ERR_RX_ERROR		(0)
#define R_ERR_SUCCESS		(1)

typedef struct
{
	UINT8   UINT8Adr;
	UINT8   UINT8DataLen;
	UINT8    *pUINT8Datas;
} sInitTSA5727Reg;

UINT8   UINT8Reg1BValue[]={0x00};
UINT8   UINT8Reg40Value[]={0x05,0xAC,0x00,0x00};
UINT8   UINT8Reg3BValue[]={0x00,0x00,0x05,0xF8,0x00,0x7F,0xFA,0x08};
UINT8   UINT8Reg3CValue[]={0x00,0x06,0xB2,0x1C,0xFF,0xFB,0x49,0x4C};
UINT8   UINT8Reg43Value[]={0x05,0xAC,0x00,0x00};
UINT8   UINT8Reg3EValue[]={0x00,0x00,0x01,0xFF,0x00,0x7F,0xFE,0x01};
UINT8   UINT8Reg3FValue[]={0x00,0x06,0xB2,0x1C,0xFF,0xFB,0x49,0x4C};
UINT8   UINT8Reg46Value[]={0x00,0x02,0x00,0x03};
UINT8   UINT8Reg58Value[]={0x00,0x7C,0x56,0x40,0x0F,0x83,0xA9,0xC0,0x00,0x00,0x00,0x00,0x00,0x78,0xAC,0x80,0x00,0x00,0x00,0x00};
UINT8   UINT8Reg5AValue[]={0x00,0x03,0xA9,0xBF,0x00,0x03,0xA9,0xBF,0x00,0x00,0x00,0x00,0x00,0x78,0xAC,0x80,0x00,0x00,0x00,0x00};
UINT8   UINT8Reg5CValue[]={0x00,0x7C,0x56,0x40,0x0F,0x83,0xA9,0xC0,0x00,0x00,0x00,0x00,0x00,0x78,0xAC,0x80,0x00,0x00,0x00,0x00};
UINT8   UINT8Reg5EValue[]={0x00,0x03,0xA9,0xBF,0x00,0x03,0xA9,0xBF,0x00,0x00,0x00,0x00,0x00,0x78,0xAC,0x80,0x00,0x00,0x00,0x00};
UINT8   UINT8Reg50Value[]={0x0F,0x70,0x80,0x00};
UINT8   UINT8Reg20Value[]={0x00,0x98,0x77,0x72};
UINT8   UINT8Reg25Value[]={0x01,0x02,0x31,0x45};
UINT8   UINT8Reg72Value[]={0x00,0x00,0x00,0x00};
UINT8   UINT8Reg73Value[]={0x00,0x80,0x00,0x00};
UINT8   UINT8Reg76Value[]={0x00,0x00,0x00,0x00};
UINT8   UINT8Reg77Value[]={0x00,0x80,0x00,0x00};
UINT8   UINT8Reg56Value[]={0x00,0x59,0x00,0x00};
UINT8   UINT8Reg70Value[]={0x00,0x80,0x00,0x00};
UINT8   UINT8Reg74Value[]={0x00,0x80,0x00,0x00};
UINT8   UINT8Reg51Value[]={0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00};
UINT8   UINT8Reg52Value[]={0x00,0x80,0x00,0x00,0x00,0x80,0x00,0x00};
UINT8   UINT8Reg07Value[]={0x00,0x38};
UINT8   UINT8Reg08Value[]={0x00,0xC0};
UINT8   UINT8Reg09Value[]={0x00,0xC0};
UINT8   UINT8Reg06Value[]={0x00};
UINT8   UINT8Reg03Value[]={0x80};
UINT8   UINT8Reg04Value[]={0x05};
UINT8   UINT8Reg0EValue[]={0x91};
UINT8   UINT8Reg10Value[]={0x02};
UINT8   UINT8Reg1AValue[]={0x0F};
UINT8   UINT8Reg1CValue[]={0x02};
UINT8   UINT8Reg11Value[]={0xB8};
UINT8   UINT8Reg12Value[]={0x60};
UINT8   UINT8Reg13Value[]={0xA0};
UINT8   UINT8Reg14Value[]={0x48};
UINT8   UINT8Reg05Value[]={0x02};



sInitTSA5727Reg   asInitTSA5727Reg[] = {
	//Adr         DataLen       pData

	// step1. Trim oscillator (write 0x00 to register 0x1B) and wait at least 50ms.
	{0x1B,sizeof(UINT8Reg1BValue),UINT8Reg1BValue},  //must


	{0x40,sizeof(UINT8Reg40Value),UINT8Reg40Value},
	{0x3B,sizeof(UINT8Reg3BValue),UINT8Reg3BValue},
	{0x3C,sizeof(UINT8Reg3CValue),UINT8Reg3CValue},
	{0x43,sizeof(UINT8Reg43Value),UINT8Reg43Value},
	{0x3E,sizeof(UINT8Reg3EValue),UINT8Reg3EValue},
	{0x3F,sizeof(UINT8Reg3FValue),UINT8Reg3FValue},
	{0x46,sizeof(UINT8Reg46Value),UINT8Reg46Value},
	{0x58,sizeof(UINT8Reg58Value),UINT8Reg58Value},
	{0x5A,sizeof(UINT8Reg5AValue),UINT8Reg5AValue},
	{0x5C,sizeof(UINT8Reg5CValue),UINT8Reg5CValue},
	{0x5E,sizeof(UINT8Reg5EValue),UINT8Reg5EValue},
	{0x50,sizeof(UINT8Reg50Value),UINT8Reg50Value},
	{0x20,sizeof(UINT8Reg20Value),UINT8Reg20Value},
	{0x25,sizeof(UINT8Reg25Value),UINT8Reg25Value},
	{0x72,sizeof(UINT8Reg72Value),UINT8Reg72Value},
	{0x73,sizeof(UINT8Reg73Value),UINT8Reg73Value},
	{0x76,sizeof(UINT8Reg76Value),UINT8Reg76Value},
	{0x77,sizeof(UINT8Reg77Value),UINT8Reg77Value},
	{0x56,sizeof(UINT8Reg56Value),UINT8Reg56Value},
	{0x70,sizeof(UINT8Reg70Value),UINT8Reg70Value},
	{0x74,sizeof(UINT8Reg74Value),UINT8Reg74Value},
	{0x51,sizeof(UINT8Reg51Value),UINT8Reg51Value},
	{0x52,sizeof(UINT8Reg52Value),UINT8Reg52Value},
	{0x07,sizeof(UINT8Reg07Value),UINT8Reg07Value},
	{0x08,sizeof(UINT8Reg08Value),UINT8Reg08Value},
	{0x09,sizeof(UINT8Reg09Value),UINT8Reg09Value},
	{0x06,sizeof(UINT8Reg06Value),UINT8Reg06Value},
	{0x03,sizeof(UINT8Reg03Value),UINT8Reg03Value},
	{0x04,sizeof(UINT8Reg04Value),UINT8Reg04Value},
	{0x0E,sizeof(UINT8Reg0EValue),UINT8Reg0EValue},
	{0x10,sizeof(UINT8Reg10Value),UINT8Reg10Value},
	{0x1A,sizeof(UINT8Reg1AValue),UINT8Reg1AValue},
	{0x1C,sizeof(UINT8Reg1CValue),UINT8Reg1CValue},
	{0x11,sizeof(UINT8Reg11Value),UINT8Reg11Value},
	{0x12,sizeof(UINT8Reg12Value),UINT8Reg12Value},
	{0x13,sizeof(UINT8Reg13Value),UINT8Reg13Value},
	{0x14,sizeof(UINT8Reg14Value),UINT8Reg14Value},

	{0x05,sizeof(UINT8Reg05Value),UINT8Reg05Value},



};


//*************************************************************
// PRIVATE FUNCTIONS
//*************************************************************
static ErrCode AudioAmp_AdoAmp_Tas5727_write(UINT8 i2c_master,UINT8 w_len, UINT8* write_buf)
{
	if (!m_AMP_DEVICE_ADDR)
		return R_ERR_RX_ERROR;

	if (I2C_Write_EX(i2c_master, m_AMP_DEVICE_ADDR, w_len, write_buf) != S_OK) {
		//printf("%s %s %d\n", __FILE__, __FUNCTION__, __LINE__);
		return R_ERR_RX_ERROR;
	}
	//udelay(10000); //use HW i2c need to add this to avoid set error

	return R_ERR_SUCCESS;
}

void AudioAmp_InitTas5727(UINT8 devAddr)
{
	UINT8 dat[23], i=0;

	printf("init TAS5727\n");
	//bcoz PCB design error, need workaround I2C source switch
	//0xb800_08C0[23:20] = 0x8 / 0xb806_02A0[5:4] = 0x3  <-- AMP
	//0xb800_08C0[23:20] = 0x0 / 0xb806_02A0[5:4] = 0x3  <-- Tuner
	rtd_maskl(0xb80008c0, 0xFF0FFFFF, 0x00800000); //AMP


	while (i < (sizeof(asInitTSA5727Reg)/sizeof(sInitTSA5727Reg)))
	{
		dat[0] =asInitTSA5727Reg[i].UINT8Adr;
		memcpy(&dat[1],asInitTSA5727Reg[i].pUINT8Datas,asInitTSA5727Reg[i].UINT8DataLen);

		if( R_ERR_RX_ERROR == AudioAmp_AdoAmp_Tas5727_write(m_I2C_MASTER,asInitTSA5727Reg[i].UINT8DataLen+1,&dat[0]))
			printf(" err!UINT8Adr=[0x%x],UINT8DataLen=[%u]\n",asInitTSA5727Reg[i].UINT8Adr,asInitTSA5727Reg[i].UINT8DataLen);

		if(i == 0x00)
		{
			udelay(60000);
		}

		i++;
	}

	rtd_maskl(0xb80008c0, 0xFF0FFFFF, 0x00000000); //Tuner

	printf("InitTas5727 ok\n");
}

void AudioAmp_SetOscillator(void)
{
#if defined(ENABLE_AMP_USE_HW_I2C)
	UINT8 dat[2];
	dat[0]= 0x1B;
	dat[1]= 0x00;


	udelay(300000);
	printf("init TAS5727\n");

	//bcoz PCB design error, need workaround I2C source switch
	//0xb800_08C0[23:20] = 0x8 / 0xb806_02A0[5:4] = 0x3  <-- AMP
	//0xb800_08C0[23:20] = 0x0 / 0xb806_02A0[5:4] = 0x3  <-- Tuner
	rtd_maskl(0xb80008c0, 0xFF0FFFFF, 0x00800000); //AMP


	AudioAmp_AdoAmp_Tas5727_write(m_I2C_MASTER,2,dat);
#endif
}


void AudioAmp_Set951RST(BOOL val)
{
	if (m_PIN_951_RST) {
		IO_Set(m_PIN_951_RST, val);
	}
}

void AudioAmp_SetMute(BOOL isMute)
{
#if defined(ENABLE_AMP_USE_HW_I2C)
	UINT8 dat[2];

	dat[0]= 0x06;
	if (isMute)
		dat[1]= 0x07;
	else
		dat[1]= 0x00;

	AudioAmp_AdoAmp_Tas5727_write(m_I2C_MASTER,2,dat);
#endif
}

void AudioAmp_SetMasterVolume(UINT8 iValue)
{
#if defined(ENABLE_AMP_USE_HW_I2C)
	UINT8 dat[2];
	//dat[0]= m_AMP_DEVICE_ADDR;
	dat[0]= 0x07;
	dat[1]= iValue;
	AudioAmp_AdoAmp_Tas5727_write(m_I2C_MASTER,2,dat);
#endif
}


//*************************************************************
// PUBLIC FUNCTIONS
//*************************************************************
void AudioAmp_InitAudioOut2I2S_1st(void)
{

	unsigned long long value=0;
	if (pcb_mgr_get_enum_info_byname("AMP_I2C", &value) < 0) {
		printf("no AMP_I2C\n");
		m_I2C_MASTER = 0;
	} else {
		m_I2C_MASTER = value;
		printf("get AMP_I2C %08x%08x\n", HI32(value), LO32(value));
	}
	if (pcb_mgr_get_enum_info_byname("AMP_DEVICE_ADDR", &value) < 0) {
		printf("no AMP_DEVICE_ADDR\n");
		m_AMP_DEVICE_ADDR = 0;
	} else {
		m_AMP_DEVICE_ADDR = value;
		printf("get AMP_DEVICE_ADDR %08x%08x \n", HI32(value), LO32(value));

	}
	if (pcb_mgr_get_enum_info_byname("PIN_AMP_MUTE", &value) < 0) {
		printf("no PIN_AMP_MUTE\n");
		m_PIN_AMP_MUTE = 0;
	} else {
		m_PIN_AMP_MUTE = value;
		printf("get AMP_MUTE %08x%08x\n", HI32(value), LO32(value));

	}

	if (pcb_mgr_get_enum_info_byname("PIN_MISC_951_RST", &value) < 0) {
		printf("no PIN_MISC_951_RST\n");
		m_PIN_951_RST = 0;
	} else {
		m_PIN_951_RST = value;
		printf("get MISC_951_RST = %08x%08x\n", HI32(value), LO32(value));

	}
#if 0
#if defined(BOARD_ID_RTD2974_HISENSE_V1)|| defined(BOARD_ID_RTD2974_HISENSE_V2)
	if (pcb_mgr_get_enum_info_byname("PIN_HEADPHONE_PLUG_IN", &value) < 0) {
		printf("no PIN_HEADPHONE_PLUG_IN\n");
		m_PIN_HEADPHONE_PLUG_IN = 0;
	} else {
		m_PIN_HEADPHONE_PLUG_IN = value;
		//printf("get HEADPHONE_PLUG_IN = %08x%08x\n", HI32(value), LO32(value));

	}
#endif
#endif

	if (m_PIN_AMP_MUTE) {
		//reset AMP
#if 0
#if defined(BOARD_ID_RTD2974_HISENSE_V1)|| defined(BOARD_ID_RTD2974_HISENSE_V2)
	if (IO_Get(m_PIN_HEADPHONE_PLUG_IN))
		IO_Set(m_PIN_AMP_MUTE, 1);
	else
#endif
#endif
		IO_Set(m_PIN_AMP_MUTE, 0);
		printf("get m_PIN_AMP_MUTE = %d (reset AMP!)\n", m_PIN_AMP_MUTE);
	}

	if (m_PIN_951_RST) {
		IO_Set(m_PIN_951_RST, 1);
		printf("get m_PIN_951_RST = %d (reset Yamaha YYS951!)\n", m_PIN_951_RST);
	}

	I2C_Init();
}

void AudioAmp_InitAudioOut2I2S_2nd(void)
{
	if (m_PIN_951_RST) {
	//#if defined(BOARD_ID_RTD2974_HISENSE_V1) || defined(BOARD_ID_RTD2974_HISENSE_V2)  //wayne for audio amp sequence
	//IO_Set(m_PIN_951_RST, 1);
	// udelay(1000000);
      //#endif
		IO_Set(m_PIN_951_RST, 0);

      /*
	#if defined(BOARD_ID_RTD2974_HISENSE_V1)|| defined(BOARD_ID_RTD2974_HISENSE_V2) //wayne for audio amp sequence
      udelay(5000);
	IO_Set(m_PIN_951_RST, 1);
	udelay(100);
	IO_Set(m_PIN_951_RST, 0);
	#endif
	*/
	}


	AudioAmp_InitTas5727(m_AMP_DEVICE_ADDR);
}




