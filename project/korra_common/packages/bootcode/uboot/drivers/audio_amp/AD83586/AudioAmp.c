#include <common.h>
#include <asm/arch/io.h>
#include <asm/arch/system.h>
#include <platform_lib/board/pcb_mgr.h>
#include <platform_lib/board/pcb.h>
#include <platform_lib/board/pwm.h>
#include <i2c.h>
#include "AudioAmp.h"

//AMP IC Pin 20 / Pin 21
#define IC_SA0_PIN						0	//1
#define IC_SA1_PIN						0	//1

//#define AD83586_DEVICE_ADDR_W	0x6A
//#define AD83586_DEVICE_ADDR_R		0x6B
// I2C Address is 0x0110x0y, x : SA0, y : SA1
//#define AD83586_DEVICE_ADDR_W			(0x60 | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1))
//#define AD83586_DEVICE_ADDR_R			(0x61 | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1))

//need shift 1 bit, delete R/W bit
//#define AD83586_DEV_ADDR				(AD83586_DEVICE_ADDR_W>>1)

//#define printf(fmt,args...)
/**************************** Setting *****************************/
#define AD83586_VOLUME_MAX		0xFF	// -max dB
#define AD83586_VOLUME_MIN		0x00	// +12dB

#define AD83586_BASS_MAX			0x1F	// -12dB
#define AD83586_BASS_MIN			0x00	// +12dB

#define AD83586_TREBLE_MAX		0x1F	// -12dB
#define AD83586_TREBLE_MIN			0x00	// +12dB

#define AD83586_RA_READ_ENABLE	0x08	// B[3]
#define AD83586_R1_READ_ENABLE	0x04	// B[2]
#define AD83586_WA_WRITE_ENABLE 0x02	// B[1]
#define AD83586_W1_WRITE_ENABLE 0x01	// B[0]

/**************************** Register *****************************/
#define AD83586_ADDR_0x00_SCTL1 		0x00
#define AD83586_ADDR_0x01_SCTL2 		0x01
#define AD83586_ADDR_0x02_SCTL3 		0x02
#define AD83586_ADDR_0x03_MVOL			0x03
#define AD83586_ADDR_0x04_C1VOL 		0x04
#define AD83586_ADDR_0x05_C2VOL 		0x05
#define AD83586_ADDR_0x06_C3VOL 		0x06
#define AD83586_ADDR_0x07_BTONE 		0x07
#define AD83586_ADDR_0x08_TTONE 		0x08
#define AD83586_ADDR_0x09_XOF			0x09
#define AD83586_ADDR_0x0A_SCTL4 		0x0A
#define AD83586_ADDR_0x0B_C1CFG 		0x0B
#define AD83586_ADDR_0x0C_C2CFG 		0x0C
#define AD83586_ADDR_0x0D_C3CFG 		0x0D
#define AD83586_ADDR_0x0E_LAR				0x0E
#define AD83586_ADDR_0x0F_RESERVED		0x0F
#define AD83586_ADDR_0x10_ERDLY 		0x10
#define AD83586_ADDR_0x11_SCTL5 		0x11
#define AD83586_ADDR_0x12_HVUV			0x12
#define AD83586_ADDR_0x13_ZDCFG 		0x13
#define AD83586_ADDR_0x14_CFADDR			0x14
#define AD83586_ADDR_0x15_A1CF1 		0x15
#define AD83586_ADDR_0x16_A1CF2 		0x16
#define AD83586_ADDR_0x17_A1CF3 		0x17
#define AD83586_ADDR_0x18_A2CF1 		0x18
#define AD83586_ADDR_0x19_A2CF2 		0x19
#define AD83586_ADDR_0x1A_A2CF3 		0x1A
#define AD83586_ADDR_0x1B_B1CF1 		0x1B
#define AD83586_ADDR_0x1C_B1CF2 		0x1C
#define AD83586_ADDR_0x1D_B1CF3 		0x1D
#define AD83586_ADDR_0x1E_B2CF1 		0x1E
#define AD83586_ADDR_0x1F_B2CF2 		0x1F
#define AD83586_ADDR_0x20_B2CF3 		0x20
#define AD83586_ADDR_0x21_A0CF1 		0x21
#define AD83586_ADDR_0x22_A0CF2 		0x22
#define AD83586_ADDR_0x23_A0CF3 		0x23
#define AD83586_ADDR_0x24_CFUD			0x24
#define AD83586_ADDR_0x25_FDCFG			0x25
#define AD83586_ADDR_0x26_MBIST			0x26
#define AD83586_ADDR_0x27_STATUS			0x27
#define AD83586_ADDR_0x28_PWM_CTRL		0x28
#define AD83586_ADDR_0x29_TM_CTRL		0x29
#define AD83586_ADDR_0x2A_QT_SW_LEVEL	0x2A
#define AD83586_ADDR_0x2B_VFT				0x2B

/************************** RAM Base Address ***************************/
#define AD83586_RAM_ADDR_CH_1_EQ1							0x00
#define AD83586_RAM_ADDR_CH_1_EQ2							0x05
#define AD83586_RAM_ADDR_CH_1_EQ3							0x0A
#define AD83586_RAM_ADDR_CH_1_EQ4							0x0F
#define AD83586_RAM_ADDR_CH_1_EQ5							0x14
#define AD83586_RAM_ADDR_CH_1_EQ6							0x19
#define AD83586_RAM_ADDR_CH_1_EQ7							0x1E
#define AD83586_RAM_ADDR_CH_1_EQ8							0x23
#define AD83586_RAM_ADDR_CH_1_EQ9							0x28
#define AD83586_RAM_ADDR_CH_3_EQ1							0x2D
#define AD83586_RAM_ADDR_CH_2_EQ1							0x32
#define AD83586_RAM_ADDR_CH_2_EQ2							0x37
#define AD83586_RAM_ADDR_CH_2_EQ3							0x3C
#define AD83586_RAM_ADDR_CH_2_EQ4							0x41
#define AD83586_RAM_ADDR_CH_2_EQ5							0x46
#define AD83586_RAM_ADDR_CH_2_EQ6							0x4B
#define AD83586_RAM_ADDR_CH_2_EQ7							0x50
#define AD83586_RAM_ADDR_CH_2_EQ8							0x55
#define AD83586_RAM_ADDR_CH_2_EQ9							0x5A
#define AD83586_RAM_ADDR_CH_3_EQ2							0x5F
#define AD83586_RAM_ADDR_CH_1_MIXER_1						0x64
#define AD83586_RAM_ADDR_CH_1_MIXER_2						0x65
#define AD83586_RAM_ADDR_CH_2_MIXER_1						0x66
#define AD83586_RAM_ADDR_CH_2_MIXER_2						0x67
#define AD83586_RAM_ADDR_CH_3_MIXER_1						0x68
#define AD83586_RAM_ADDR_CH_3_MIXER_2						0x69
#define AD83586_RAM_ADDR_CH_1_PRESCALE						0x6A
#define AD83586_RAM_ADDR_CH_2_PRESCALE						0x6B
#define AD83586_RAM_ADDR_CH_1_POSTSCALE 					0x6C
#define AD83586_RAM_ADDR_CH_2_POSTSCALE 					0x6D
#define AD83586_RAM_ADDR_CH_3_POSTSCALE 					0x6E
#define AD83586_RAM_ADDR_CH_1_2_POWER_CLIPPING				0x6F
#define AD83586_RAM_ADDR_CH_3_POWER_CLIPPING				0x70
#define AD83586_RAM_ADDR_CH_1_2_DRC_ATTACK_THRESHOLD		0x71
#define AD83586_RAM_ADDR_CH_1_2_DRC_RELEASE_THRESHOLD	0x72
#define AD83586_RAM_ADDR_CH_3_DRC_ATTACK_THRESHOLD		0x73
#define AD83586_RAM_ADDR_CH_3_DRC_RELEASE_THRESHOLD 	0x74

static unsigned long long m_I2C_MASTER=0, m_AMP_DEVICE_ADDR=0, m_PIN_AMP_MUTE=0; 
//static unsigned long long m_AD83586_DEVICE_ADDR_W=(0x60 | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1)); 
//static unsigned long long m_AD83586_DEVICE_ADDR_R=(0x61 | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1));
static unsigned long long m_PIN_951_RST=0;
extern void amp_IO(unsigned char bus_id, unsigned short device_id, unsigned char addr, unsigned val);

//*************************************************************
// PUBLIC FUNCTIONS
//*************************************************************
#define R_ERR_FAILED		(0)
#define R_ERR_RX_ERROR		(0)
#define R_ERR_SUCCESS		(1)
#define _FALSE				(0)
#define _TRUE				(1)
#define ENABLE				1
#define DISABLE				0
#define S_OK			(0)
#define S_FALSE		(-1)

void AudioAmp_InitAudioOut2I2S_1st(void)
{
	unsigned long long value=0;

	#if 1	// too slow remove for tv015	
	pcb_mgr_show_all_enum_info();
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
          //m_AD83586_DEVICE_ADDR_W = (((m_AMP_DEVICE_ADDR << 1) | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1)))>>1;
 					//m_AD83586_DEVICE_ADDR_R = ((((m_AMP_DEVICE_ADDR << 1)+1)| (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1)))>>1;
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
  if (m_PIN_AMP_MUTE) {
    //reset AMP
    IO_Set(m_PIN_AMP_MUTE, 0);
		printf("get m_PIN_AMP_MUTE = %d (reset AMP!)\n", m_PIN_AMP_MUTE);
  }
  if (m_PIN_951_RST) {
    //reset Yamaha YYS951
    IO_Set(m_PIN_951_RST, 1);
		printf("get m_PIN_951_RST = %d (reset Yamaha YYS951!)\n", m_PIN_951_RST);
  }
	#else
	m_I2C_MASTER = 2;
 	m_AMP_DEVICE_ADDR = 0x30;	
 	//m_AD83586_DEVICE_ADDR_W = ((0x60 | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1)))>>1;
 	//m_AD83586_DEVICE_ADDR_R = ((0x61 | (IC_SA0_PIN<<3) | (IC_SA1_PIN<<1)))>>1;
	#endif
	I2C_Init();
}

unsigned long xAudioAmp_Write(UINT8 i2c_master, UINT8 w_len, UINT8* write_buf)
{
	if(I2C_Write_EX(i2c_master, m_AMP_DEVICE_ADDR, w_len, write_buf,0) != S_OK) {
		return R_ERR_RX_ERROR;
	}
	mdelay(10); //use HW i2c need to add this to avoid set error
	
	return R_ERR_SUCCESS;
}

unsigned long xAudioAmp_Read(UINT8 i2c_master, UINT8 w_len, UINT8 r_len, UINT8* write_buf, UINT8* read_buf)
{
	if(I2C_Read_EX(i2c_master, m_AMP_DEVICE_ADDR, w_len, write_buf, r_len, read_buf, 0) != S_OK)
	{
		//printf("\033[1;33m %s %s %d\033[m\n", __FILE__, __FUNCTION__, __LINE__);
		return R_ERR_RX_ERROR;
	}
	mdelay(10); //use HW i2c need to add this to avoid set error

	return R_ERR_SUCCESS;
}

unsigned long xAudioAmp_I2C_Write(UINT8 nDevAddr, UINT8 nSubAddr, UINT8 Data)
{
	UINT8 msg[15];
	unsigned long ret;

	msg[0] = nSubAddr;
	msg[1] = Data;
	ret = xAudioAmp_Write(m_I2C_MASTER, 2, msg);

	if (ret != R_ERR_SUCCESS)
	{
		printf("%s: error\n ", __FUNCTION__);
	}

	return ret;
}

unsigned long xAudioAmp_I2C_Read(UINT8 nDevAddr, UINT8 nSubAddr, UINT8* Data)
{
	UINT8 w_data[2];
	unsigned long ret;

	w_data[0] = nSubAddr;
	ret = xAudioAmp_Read(m_I2C_MASTER, 1, 1, w_data, Data);

	if (ret != R_ERR_SUCCESS)
	{
		printf("%s: error\n ", __FUNCTION__);
	}

	return ret;
}

void AudioAmp_SW_Reset(void)
{
	UINT8 ucData = 0;
	unsigned char wData[20];

	printf("------AudioControl_ESMT83586_SW_Reset------- \n");
	//SW reset
	xAudioAmp_I2C_Read(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, &ucData);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, &ucData);
	//wData[0] = AD83586_ADDR_0x11_SCTL5;
	//wData[1] = ucData;
	//I2C_Read_EX(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 2, wData, 1, &ucData);
	ucData = ucData & (~_BIT5);
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, ucData);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, &ucData);
	//Normal operation
	//xAudioAmp_I2C_Read(AD83586_DEV_ADDR, AD83586_ADDR_0x11_SCTL5, &ucData);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, &ucData);
	//wData[0] = AD83586_ADDR_0x11_SCTL5;
	//wData[1] = ucData;
	//I2C_Read_EX(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 2, wData, 1, &ucData);
	ucData = ucData | (_BIT5);
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, ucData);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, &ucData);
}

//USER:LewisLee DATE:2011/10/25
//because CAudioAmp_ESMT_AD83586::Init() is to pull up amp voltage
//so it need some time to wake up IC
//let IC other initial later
void AudioAmp_Setting_Initial(void)
{
	UINT8 ucData = 0;
	printf("------AudioControl_ESMT83586_Setting_Initial------- \n");

//	AudioAmp_HW_Reset(_FALSE);
	AudioAmp_SW_Reset();

//	Reg[00h]=00h ##State_Control_1
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x00_SCTL1, 0x00);	
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x00_SCTL1, 0x00);

//	Reg[01h]=04h ##State_Control_2
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x01_SCTL2, 0x04);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x00_SCTL1, 0x04);

//	Reg[02h]=00h ##State_Control_3
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x02_SCTL3, 0x00);	//0x0F(mute)
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x02_SCTL3, 0x00);
	xAudioAmp_I2C_Read(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x02_SCTL3, &ucData);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x02_SCTL3, &ucData);
	//unsigned char wData[20];
	//wData[0] = AD83586_ADDR_0x02_SCTL3;
	//wData[1] = ucData;
	//I2C_Read_EX(m_I2C_MASTER, m_AMP_DEVICE_ADDR, 2, wData, 1, &ucData);
	printf("ESMT83586: AD83586_ADDR_0x02_SCTL3=%x\n",ucData);


//	Reg[03h]=18h ##Master_volume_control
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x03_MVOL, 0x14);			// Lance , 20111117 from Gill's request
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x03_MVOL, 0x14);
//	Reg[04h]=14h ##Channel_1_volume_control
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x04_C1VOL, 0x14);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x04_C1VOL, 0x14);

//	Reg[05h]=14h ##Channel_2_volume_control
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x05_C2VOL, 0x14);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x05_C2VOL, 0x14);

//	Reg[06h]=14h ##Channel_3_volume_control
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x06_C3VOL, 0x14);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x06_C3VOL, 0x14);

//	Reg[07h]=10h ##Bass_tone_boost_and_cut
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x07_BTONE, 0x10);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x07_BTONE, 0x10);

//	Reg[08h]=10h ##Treble_tone_boost_and_cut
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x08_TTONE, 0x10);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x08_TTONE, 0x10);

//	Reg[09h]=00h ##Bass_management_crossover_frequency
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x09_XOF, 0x00);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x09_XOF, 0x00);

//	Reg[0Ah]=98h ##State_Control_4
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0A_SCTL4, 0x98);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0A_SCTL4, 0x98);

//	Reg[0Bh]=0eh ##Channel_1_configuration_registers
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0B_C1CFG, 0x0e);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0B_C1CFG, 0x0e);

//	Reg[0Ch]=0eh ##Channel_2_configuration_registers
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0C_C2CFG, 0x0e);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0C_C2CFG, 0x0e);

//	Reg[0Dh]=0ch ##Channel_3_configuration_registers
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0D_C3CFG, 0x0c);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0D_C3CFG, 0x0c);

//	Reg[0Eh]=6ah ##DRC_limiter_attack/release_rate
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0E_LAR, 0x6a);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x0E_LAR, 0x6a);

//	Reg[0Fh]=69h ##DRC limiter attack/release threshold
//	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD82586_ADDR_0x0F_LATRT, 0x69);
	//	Reg[0Fh]=00h ##Reserved

//	Reg[10h]=06h ##Reserved
//	Reg[11h]=22h ##State_Control_5
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, 0x22);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x11_SCTL5, 0x22);

//	Reg[12h]=01h ##PVDD_under_voltage_selection
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x12_HVUV, 0x01);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x12_HVUV, 0x01);

//	Reg[13h]=04h ##Zero_detection_level_selection
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x13_ZDCFG, 0x04);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x13_ZDCFG, 0x04);

//	Reg[14h]=00h ##Coefficient_RAM_base_address
//	Reg[15h]=e0h ##Top_8-bits_of_coefficients_A1
//	Reg[16h]=22h ##Middle_8-bits_of_coefficients_A1
//	Reg[17h]=b4h ##Bottom_8-bits_of_coefficients_A1
//	Reg[18h]=00h ##Top_8-bits_of_coefficients_A2
//	Reg[19h]=00h ##Middle_8-bits_of_coefficients_A2
//	Reg[1Ah]=00h ##Bottom_8-bits_of_coefficients_A2
//	Reg[1Bh]=1fh ##Top_8-bits_of_coefficients_B1
//	Reg[1Ch]=bah ##Middle_8-bits_of_coefficients_B1
//	Reg[1Dh]=98h ##Bottom_8-bits_of_coefficients_B1
//	Reg[1Eh]=00h ##Top_8-bits_of_coefficients_B2
//	Reg[1Fh]=00h ##Middle_8-bits_of_coefficients_B2
//	Reg[20h]=00h ##Bottom_8-bits_of_coefficients_B2
//	Reg[21h]=1fh ##Top_8-bits_of_coefficients_A0
//	Reg[22h]=ddh ##Middle_8-bits_of_coefficients_A0
//	Reg[23h]=4ch ##Bottom_8-bits_of_coefficients_A0
//	Reg[24h]=00h ##CfRW
//	Reg[25h]=00h ##Reserved
//	Reg[26h]=00h ##Reserved
//	Reg[27h]=3fh ##Reserved
//	Reg[28h]=00h ##Reserved
//	Reg[29h]=00h ##Reserved
//	Reg[2Ah]=0dh ##Power_saving_mode_switching_level
	xAudioAmp_I2C_Write(m_AMP_DEVICE_ADDR, AD83586_ADDR_0x2A_QT_SW_LEVEL, 0x0d);
	//amp_IO(m_I2C_MASTER, m_AMP_DEVICE_ADDR, AD83586_ADDR_0x2A_QT_SW_LEVEL, 0x0d);
}

void AudioAmp_InitAudioOut2I2S_2nd(void)
{
	if ( m_I2C_MASTER != 0 && m_AMP_DEVICE_ADDR != 0 )
	{
    	// Start up
    	AudioAmp_Setting_Initial();		
	}
	else {
		printf("No AMP_I2C and DEVICE_ADDR \n");
	}
}
void AudioAmp_SetMute(BOOL isMute)
{

}
void AudioAmp_SetMasterVolume(UINT8 iValue)
{

}
void AudioAmp_SetSubWoof(BOOL isEnable)
{

}
void AudioAmp_SetOscillator(void)
{

}
void AudioAmp_Set951RST(BOOL val)
{

}





