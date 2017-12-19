#include <common.h>

#include "rtk_g2c-lib.h"
#include "asm/arch/io.h"
#include <asm/io.h>
#include <platform_lib/board/pcb_mgr.h>
#include <platform_lib/board/gpio.h>
#include <platform_lib/board/pcb.h>


#define printf(...)   

#define CONFIG_SOFT_I2C_READ_REPEATED_START

#define G2C_BUS_COUNT					2

//Test Case
#define G2C_PIN_MUX						(0xB8000870)
#define G2C_PIN_MUX_MASK				((0x0F << 20) | (0x0F << 12))
#define G2C_PIN_MUX_ENABLE			((0x0F << 20) | (0x0F << 12))
#define G2C_PIN_MUX_DEFAULT			0x685858f0 //I2C1

//MISC GPIO Port 4
#define GPIO_DIR						(0xB801BC10)
#define GPIO_DATO						(0xB801BC28)
#define GPIO_DATI						(0xB801BC40)
#define SDA_BIT							(18)
#define SCL_BIT							(17)


//G2C Port 0 (MISC GPIO 127/124)
#define G2C_PORT0_PIN_MUX				(0xB8000860)//(0xB80008B4)
#define G2C_PORT0_PIN_MUX_MASK		((0x0F << 28) | (0x0F << 4))//[31:28] [7:4]
#define G2C_PORT0_PIN_MUX_ENABLE	((0x0F << 28) | (0x0F << 4))//[31:28] [7:4]
//MISC GPIO Port 3
#define PORT0_GPIO_DIR					(0xB801BC0C)
#define PORT0_GPIO_DATO				(0xB801BC24)
#define PORT0_GPIO_DATI				(0xB801BC3C)
#define PORT0_SDA_BIT					(31)
#define PORT0_SCL_BIT					(28)


//G2C Port 1 (MISC GPIO 14/13)
#define G2C_PORT1_PIN_MUX				(0xB800080C)//(0xB800080C)
#define G2C_PORT1_PIN_MUX_MASK		((0x0F << 12) | (0x0F << 20))//[15:12] [23:20]
#define G2C_PORT1_PIN_MUX_ENABLE	((0x0F << 12) | (0x0F << 20))//[15:12] [23:20]
//MISC GPIO Port 0
#define PORT1_GPIO_DIR					(0xB801BC00)
#define PORT1_GPIO_DATO				(0xB801BC18)
#define PORT1_GPIO_DATI				(0xB801BC30)
#define PORT1_SDA_BIT					(14)
#define PORT1_SCL_BIT					(13)



//PinMux
#define SET_G2C_PINMUX(x, y)			rtd_outl(x, y)
#define GET_G2C_PINMUX(x)				rtd_inl(x)

//GPIO
#define SET_GPIO_DIR(x, y)			rtd_outl(x, y)
#define SET_GPIO_DATO(x, y)			rtd_outl(x, y)
#define SET_GPIO_DATI(x, y)			rtd_outl(x, y)

#define GET_GPIO_DIR(x)				rtd_inl(x)
#define GET_GPIO_DATO(x)				rtd_inl(x)
#define GET_GPIO_DATI(x)				rtd_inl(x)


#define GET_SDA_IN(x, y, z)			((GET_GPIO_DATI(x)&y)>>z)
//#define G2C_DELAY 						udelay(1)
volatile int ii = 0;
#define G2C_DELAY 						for(ii=0; ii<4; ii++) { }		//100KHz
#define G2C_ACTIVE 						do { } while (0)
#define G2C_TRISTATE 					do { } while (0)

#ifndef CONFIG_RTD1195
#ifndef PIN_I2C3_SDA
#define PIN_I2C3_SDA                   RTD299X_BGA_PIN_A5_GPO_127(0,0)
#endif
#ifndef PIN_I2C3_SCL
#define PIN_I2C3_SCL                   RTD299X_BGA_PIN_D7_GPO_124(0,0)
#endif
#ifndef PIN_I2C4_SDA
#define PIN_I2C4_SDA                  RTD299X_BGA_PIN_AH12_GPO_14(0, 0)
#endif
#ifndef PIN_I2C4_SCL
#define PIN_I2C4_SCL                   RTD299X_BGA_PIN_AG11_GPO_13(0, 0)
#endif

#else
#ifndef PIN_I2C3_SDA
#define PIN_I2C3_SDA                   RTD1195_BGA_PIN_A5_GPO_127(0,0)
#endif
#ifndef PIN_I2C3_SCL
#define PIN_I2C3_SCL                   RTD1195_BGA_PIN_D7_GPO_124(0,0)
#endif
#ifndef PIN_I2C4_SDA
#define PIN_I2C4_SDA                  RTD1195_BGA_PIN_AH12_GPO_14(0, 0)
#endif
#ifndef PIN_I2C4_SCL
#define PIN_I2C4_SCL                   RTD1195_BGA_PIN_AG11_GPO_13(0, 0)
#endif
#endif //CONFIG_RTD1195

volatile unsigned int PIN_MUX_REG 		= G2C_PIN_MUX;
volatile unsigned int PIN_MUX_MASK 		= G2C_PIN_MUX_MASK;
volatile unsigned int PIN_MUX_ENABLE		= G2C_PIN_MUX_ENABLE;

volatile unsigned int SDA_DIR_REG 		= GPIO_DIR;
volatile unsigned int SDA_DATO_REG 		= GPIO_DATO;
volatile unsigned int SDA_DATI_REG 		= GPIO_DATI;
volatile unsigned int SDA_PIN 				= SDA_BIT;

volatile unsigned int SCL_DIR_REG 		= GPIO_DIR;
volatile unsigned int SCL_DATO_REG 		= GPIO_DATO;
volatile unsigned int SCL_DATI_REG 		= GPIO_DATI;
volatile unsigned int SCL_PIN 				= SCL_BIT;


volatile unsigned int PORT0_PIN_MUX_DEFAULT;
volatile unsigned int PORT1_PIN_MUX_DEFAULT;

volatile unsigned int g_value;
volatile unsigned int g_group;
volatile unsigned int g_shiftIndex;
static unsigned long long get_GPO(unsigned long long m_pin)
{
	if (GET_PIN_TYPE(m_pin) == PCB_PIN_TYPE_GPIO) {
		g_value = GET_PIN_INDEX(m_pin);
		g_group = g_value / 32;
		g_shiftIndex = g_value % 32;
		
		switch(g_group){
			case 0:
				return MIS_GP0DATO;
			case 1:
				return MIS_GP1DATO;
#ifndef CONFIG_RTD1195
			case 2:
				return MIS_GP2DATO;
			case 3:
				return MIS_GP3DATO;
			case 4:
				return MIS_GP4DATO;
			case 5:
				return MIS_GP5DATO;
#endif
			default:
				return 0;
		}
	}
	else if (GET_PIN_TYPE(m_pin) == PCB_PIN_TYPE_ISO_GPIO) {
		g_value = GET_PIN_INDEX(m_pin);
		g_group = g_value / 32;
		g_shiftIndex = g_value % 32;

		switch(g_group)
		{
			case 0:
				return ISO_GPDATO;
			case 1:
				return ISO_GP1DATO;
			default:
				return 0;
		}
	}
}
static unsigned long long get_GPI(unsigned long long m_pin)
{
	if (GET_PIN_TYPE(m_pin) == PCB_PIN_TYPE_GPIO) {
		g_value = GET_PIN_INDEX(m_pin);
		g_group = g_value / 32;
		g_shiftIndex = g_value % 32;
		
		switch(g_group){
			case 0:
				return MIS_GP0DATI;
			case 1:
				return MIS_GP1DATI;
#ifndef CONFIG_RTD1195
			case 2:
				return MIS_GP2DATI;
			case 3:
				return MIS_GP3DATI;
			case 4:
				return MIS_GP4DATI;
			case 5:
				return MIS_GP5DATI;
#endif
			default:
				return 0;
		}
	}
	else if (GET_PIN_TYPE(m_pin) == PCB_PIN_TYPE_ISO_GPIO) {
		g_value = GET_PIN_INDEX(m_pin);
		g_group = g_value / 32;
		g_shiftIndex = g_value % 32;
		switch(g_group)
		{
			case 0:
				return ISO_GPDATI;
			case 1:
				return ISO_GP1DATI;
			default:
				return 0;
		}
	}

}
static unsigned long long get_GPDIR(unsigned long long m_pin)
{
	if (GET_PIN_TYPE(m_pin) == PCB_PIN_TYPE_GPIO) {
		g_value = GET_PIN_INDEX(m_pin);
		g_group = g_value / 32;
		g_shiftIndex = g_value % 32;
		
		switch(g_group){
			case 0:
				return MIS_GP0DIR;
			case 1:
				return MIS_GP1DIR;
#ifndef CONFIG_RTD1195
			case 2:
				return MIS_GP2DIR;
			case 3:
				return MIS_GP3DIR;
			case 4:
				return MIS_GP4DIR;
			case 5:
				return MIS_GP5DIR;
#endif
			default:
				return 0;
		}
	}
	else if (GET_PIN_TYPE(m_pin) == PCB_PIN_TYPE_ISO_GPIO) {
		g_value = GET_PIN_INDEX(m_pin);
		g_group = g_value / 32;
		g_shiftIndex = g_value % 32;
		switch(g_group)
		{
			case 0:
				return ISO_GPDIR;
			case 1:
				return ISO_GP1DIR;
			default:
				return 0;
		}
	}

}

static int g2c_sync(unsigned char id)
{
	if(id == 0)
	{
		PIN_MUX_REG		= G2C_PORT0_PIN_MUX;
		PIN_MUX_MASK		= G2C_PORT0_PIN_MUX_MASK;
		PIN_MUX_ENABLE	= G2C_PORT0_PIN_MUX_ENABLE;

		SDA_DIR_REG		= PORT0_GPIO_DIR;
		SDA_DATO_REG		= PORT0_GPIO_DATO;
		SDA_DATI_REG		= PORT0_GPIO_DATI;
		SDA_PIN			= PORT0_SDA_BIT;

		SCL_DIR_REG		= PORT0_GPIO_DIR;
		SCL_DATO_REG		= PORT0_GPIO_DATO;
		SCL_DATI_REG		= PORT0_GPIO_DATI;
		SCL_PIN			= PORT0_SCL_BIT;
	}
	else if(id == 1)
	{
		PIN_MUX_REG		= G2C_PORT1_PIN_MUX;
		PIN_MUX_MASK		= G2C_PORT1_PIN_MUX_MASK;
		PIN_MUX_ENABLE	= G2C_PORT1_PIN_MUX_ENABLE;

		SDA_DIR_REG		= PORT1_GPIO_DIR;
		SDA_DATO_REG		= PORT1_GPIO_DATO;
		SDA_DATI_REG		= PORT1_GPIO_DATI;
		SDA_PIN			= PORT1_SDA_BIT;

		SCL_DIR_REG		= PORT1_GPIO_DIR;
		SCL_DATO_REG		= PORT1_GPIO_DATO;
		SCL_DATI_REG		= PORT1_GPIO_DATI;
		SCL_PIN			= PORT1_SCL_BIT;
	}
	else if(id == 3)
	{
		PIN_MUX_REG		= 0;
		PIN_MUX_MASK	= 0;
		PIN_MUX_ENABLE	= 0;

		SDA_DIR_REG		= get_GPDIR(PIN_I2C3_SDA);
		SDA_DATO_REG	= get_GPO(PIN_I2C3_SDA);
		SDA_DATI_REG	= get_GPI(PIN_I2C3_SDA);
		SDA_PIN			= g_shiftIndex;

		SCL_DIR_REG		= get_GPDIR(PIN_I2C3_SCL);
		SCL_DATO_REG	= get_GPO(PIN_I2C3_SCL);
		SCL_DATI_REG	= get_GPI(PIN_I2C3_SCL);
		SCL_PIN			= g_shiftIndex;
	}
	else if(id == 4)
	{
		PIN_MUX_REG		= 0;
		PIN_MUX_MASK	= 0;
		PIN_MUX_ENABLE	= 0;

		SDA_DIR_REG		= get_GPDIR(PIN_I2C4_SDA);
		SDA_DATO_REG		= get_GPO(PIN_I2C4_SDA);
		SDA_DATI_REG		= get_GPI(PIN_I2C4_SDA);
		SDA_PIN			= g_shiftIndex;

		SCL_DIR_REG		= get_GPDIR(PIN_I2C4_SCL);
		SCL_DATO_REG		= get_GPO(PIN_I2C4_SCL);
		SCL_DATI_REG		= get_GPI(PIN_I2C4_SCL);
		SCL_PIN			= g_shiftIndex;
	}
	else if(id == 7)
	{
		PIN_MUX_REG 		= G2C_PIN_MUX;
		PIN_MUX_MASK	 	= G2C_PIN_MUX_MASK;
		PIN_MUX_ENABLE	= G2C_PIN_MUX_ENABLE;

		SDA_DIR_REG 		= GPIO_DIR;
		SDA_DATO_REG 	= GPIO_DATO;
		SDA_DATI_REG 	= GPIO_DATI;
		SDA_PIN 			= SDA_BIT;

		SCL_DIR_REG 		= GPIO_DIR;
		SCL_DATO_REG 	= GPIO_DATO;
		SCL_DATI_REG 	= GPIO_DATI;
		SCL_PIN 			= SCL_BIT;
	}
	else
		return -1;

#if 0
	printf("id = %d\n", id);
	printf("PIN_MUX_REG = %08x\n", PIN_MUX_REG);
	printf("PIN_MUX_MASK = %08x\n", PIN_MUX_MASK);
	printf("PIN_MUX_ENABLE = %08x\n", PIN_MUX_ENABLE);
	printf("SDA_DIR_REG = %08x\n", SDA_DIR_REG);
	printf("SDA_DATO_REG = %08x\n", SDA_DATO_REG);
	printf("SDA_DATI_REG = %08x\n", SDA_DATI_REG);
	printf("SDA_PIN = %08x\n", SDA_PIN);
	printf("SCL_DIR_REG = %08x\n", SCL_DIR_REG);
	printf("SCL_DATO_REG = %08x\n", SCL_DATO_REG);
	printf("SCL_DATI_REG = %08x\n", SCL_DATI_REG);
	printf("SCL_PIN = %08x\n", SCL_PIN);
#endif

	return 0;
}





//dir :	1 is output, 0 is input
static void set_sda_dir(int dir)
{
	unsigned int reg;
	reg = GET_GPIO_DIR(SDA_DIR_REG) & ~((0x01 << SDA_PIN));
	reg |= (dir << SDA_PIN);
	SET_GPIO_DIR(SDA_DIR_REG, reg);
}

static void set_scl_dir(int dir)
{
	unsigned int reg;
	reg = GET_GPIO_DIR(SCL_DIR_REG) & ~((0x01 << SCL_PIN));
	reg |= (dir << SCL_PIN);
	SET_GPIO_DIR(SCL_DIR_REG, reg);
}


static void set_sda_out(int dir, int val)
{
	unsigned int reg;
	if(dir)//output
	{
		reg = GET_GPIO_DATO(SDA_DATO_REG) & ~((0x01 << SDA_PIN));
		reg |= (val << SDA_PIN);
		SET_GPIO_DATO(SDA_DATO_REG, reg);
	}
	set_sda_dir(dir);
}

static void set_scl_out(int dir, int val)
{
	unsigned int reg;
	reg = GET_GPIO_DATO(SCL_DATO_REG) & ~((0x01 << SCL_PIN));
	reg |= (val << SCL_PIN);
	SET_GPIO_DATO(SCL_DATO_REG, reg);
}


static void G2C_SDA(int bit)
{
	if(bit)
		set_sda_out(0, 0);
	else
		set_sda_out(1, 0);
}

static void G2C_SCL(int bit)
{
	set_scl_out(0, bit);
}

#define G2C_SDA(bit)	(bit)? set_sda_out(0, 0): set_sda_out(1, 0)
#define G2C_SCL(bit)	set_scl_out(0, bit)



static void _stop(void)
{
	G2C_SCL(0);
	G2C_DELAY;
	G2C_SDA(0);
	G2C_ACTIVE;
	G2C_DELAY;
	G2C_SCL(1);
	G2C_DELAY;
	G2C_SDA(1);
	G2C_DELAY;
	G2C_TRISTATE;
}

static void _reset(void)
{
	int j;

	G2C_SCL(1);
	G2C_SDA(1);
	G2C_TRISTATE;
	for(j = 0; j < 9; j++) {
		G2C_SCL(0);
		G2C_DELAY;
		G2C_DELAY;
		G2C_SCL(1);
		G2C_DELAY;
		G2C_DELAY;
	}
	_stop();
	G2C_TRISTATE;
}

static void _start(void)
{
	G2C_DELAY;
	G2C_SDA(1); //release
	G2C_DELAY;
	G2C_ACTIVE;
	G2C_SCL(1);
	G2C_DELAY;
	G2C_SDA(0);
	G2C_DELAY;
}




static void _ack(int ack)
{
	G2C_SCL(0);
	G2C_DELAY;
	G2C_ACTIVE;
	G2C_SDA(ack);
	G2C_DELAY;
	G2C_SCL(1);
	G2C_DELAY;
	G2C_DELAY;
	G2C_SCL(0);
	G2C_DELAY;
}

static int _write_byte(unsigned char ch)
{
	int i;
	int nack;

	for(i = 0; i < 8; i++)
	{
		G2C_SCL(0);
		G2C_DELAY;
		G2C_SDA(ch & 0x80);
		G2C_DELAY;
		G2C_SCL(1);
		G2C_DELAY;
		G2C_DELAY;

		ch <<= 1;
	}

	/*
	 * wait ACK.
	 */
	G2C_SCL(0);
	G2C_DELAY;
	G2C_SDA(1);
	G2C_TRISTATE;
	G2C_DELAY;
	G2C_SCL(1);
	G2C_DELAY;
	G2C_DELAY;
	nack = GET_SDA_IN(SDA_DATI_REG, (0x01 << SDA_PIN), SDA_PIN);
	G2C_SCL(0);
	G2C_DELAY;
	G2C_ACTIVE;

	return(nack);
}


static unsigned char _read_byte(int ack)
{
	int ch;
	int i;

	/*
	 * Read 8 bits, MSB first.
	 */
	G2C_TRISTATE;
	G2C_SDA(1);
	ch = 0;
	for(i= 0; i < 8; i++) {
		G2C_SCL(0);
		G2C_DELAY;
		G2C_SCL(1);
		G2C_DELAY;
		ch <<= 1;
		ch |= GET_SDA_IN(SDA_DATI_REG, (0x01 << SDA_PIN), SDA_PIN);
		G2C_DELAY;
	}
	_ack(ack);

	return(ch);
}

static int g2c_probe(unsigned char addr)
{
	int rc;

	printf("\naddr = %02x\n", addr);

	_start();
	rc = _write_byte ((addr << 1) | 0);
	_stop();

	printf("rc = %d\n", rc);
	return (rc ? 0 : 1);
}

static int g2c_read(unsigned char chip, unsigned int addr, int alen, unsigned char *buffer, int len)
{
	int shift;
	printf("i2c_read: chip %02X addr %02X alen %d buffer %p len %d\n",
											chip, addr, alen, buffer, len);

	_start();
	if(alen > 0) {
		if(_write_byte(chip << 1)) {	/* write cycle */
			_stop();
			printf("i2c_read, no chip responded %02X\n", chip);
			return(1);
		}
		shift = (alen-1) * 8;
		while(alen-- > 0) {
			if(_write_byte(addr >> shift)) {
				printf("i2c_read, address not <ACK>ed\n");
				return(1);
			}
			shift -= 8;
		}

#ifdef CONFIG_SOFT_I2C_READ_REPEATED_START
		_start();
#else
		_stop();
		_start();
#endif
	}

	_write_byte((chip << 1) | 1);	/* read cycle */
	while(len-- > 0) {
		*buffer++ = _read_byte(len == 0);
	}
	_stop();
	return(0);
}


static int g2c_write(unsigned char chip, unsigned int addr, int alen, unsigned char *buffer, int len)
{
	int shift, failures = 0;

	printf("i2c_write: chip %02X addr %02X alen %d buffer %p len %d\n",
		chip, addr, alen, buffer, len);

	_start();
	if(_write_byte(chip << 1)) {	/* write cycle */
		_stop();
		printf("i2c_write, no chip responded %02X\n", chip);
		return(1);
	}
	shift = (alen-1) * 8;
	while(alen-- > 0) {
		if(_write_byte(addr >> shift)) {
			printf("i2c_write, address not <ACK>ed\n");
			return(1);
		}
		shift -= 8;
	}

	while(len-- > 0) {
		if(_write_byte(*buffer++)) {
			failures++;
		}
	}
	_stop();
	return(failures);
}



void G2C_Init(unsigned char Id)
{
	unsigned long pin_mux_reg;

	if(g2c_sync(Id) < 0)
	{
		printf("[G2C]Invalid Id %d, can't initial G2C.\n", Id);
		return;
	}

	pin_mux_reg = GET_G2C_PINMUX(PIN_MUX_REG);
	if(Id == 0)
		PORT0_PIN_MUX_DEFAULT = pin_mux_reg;
	else if(Id == 1)
		PORT1_PIN_MUX_DEFAULT = pin_mux_reg;

	pin_mux_reg &= ~PIN_MUX_MASK;
	pin_mux_reg |= PIN_MUX_ENABLE;
	SET_G2C_PINMUX(PIN_MUX_REG, pin_mux_reg); //enable GPIO mode
	printf("pin_mux_reg[0x%08x] = 0x%08x\n", PIN_MUX_REG, GET_G2C_PINMUX(PIN_MUX_REG));

	/* set default as output */
	set_sda_dir(0);
	set_scl_dir(1);

	_reset();
}



void G2C_UnInit(unsigned char Id)
{
	if(g2c_sync(Id) < 0)
	{
		printf("[G2C]Invalid Id %d, can't uninitial G2C.\n", Id);
		return;
	}

	_reset();

	//set to input
   	set_sda_dir(0);
  	set_scl_dir(0);

   if(Id == 0)
   		SET_G2C_PINMUX(PIN_MUX_REG, PORT0_PIN_MUX_DEFAULT);
   else if(Id == 1)
   		SET_G2C_PINMUX(PIN_MUX_REG, PORT1_PIN_MUX_DEFAULT);
	else if(Id == 7)
   		SET_G2C_PINMUX(PIN_MUX_REG, G2C_PIN_MUX_DEFAULT); //disable  GPIO mode

	printf("pin_mux_reg[0x%08x] = 0x%08x\n", PIN_MUX_REG, GET_G2C_PINMUX(PIN_MUX_REG));

}



int G2C_Write_EX(
    unsigned char           Id,
    unsigned char          	chipAddr,
    int         				regLen,
    unsigned char*          regOffset,
    int          				wDataLen,
    unsigned char*          wData
    )
{
	int regVal;

	if(g2c_sync(Id) < 0)
	{
		printf("[G2C]Invalid Id %d, can't write via G2C.\n", Id);
		return -1;
	}

	if(regLen > 4 || regLen < 0)
	{
		printf("[G2C]Only suppotts Four byte length register.\n");
		return -1;
	}

	if(regLen == 2)
	{
		regVal = (regOffset[0] << 8) | regOffset[1];
	}
	else if(regLen == 3)
	{
		regVal = (regOffset[0] << 16) | (regOffset[1] << 8) | regOffset[2];
	}
	else if(regLen == 4)
	{
		regVal = (regOffset[0] << 24) | (regOffset[1] << 16) | (regOffset[2] << 8) | regOffset[3];
	}
	else
		regVal = regOffset[0];

    return g2c_write(chipAddr, regVal, regLen, wData, wDataLen);
}



int G2C_Read_EX(
    unsigned char           Id,
    unsigned char           chipAddr,
    int         				regLen,
    unsigned char*          regOffset,
    int         				rDataLen,
    unsigned char*          rData
    )
{
	int regVal;

	if(g2c_sync(Id) < 0)
	{
		printf("[G2C]Invalid Id %d, can't read via G2C.\n", Id);
		return -1;
	}

	if(regLen > 4 || regLen < 0)
	{
		printf("[G2C]Only suppotts Four byte length register.\n");
		return -1;
	}

	if(regLen == 2)
	{
		regVal = (regOffset[0] << 8) | regOffset[1];
	}
	else if(regLen == 3)
	{
		regVal = (regOffset[0] << 16) | (regOffset[1] << 8) | regOffset[2];
	}
	else if(regLen == 4)
	{
		regVal = (regOffset[0] << 24) | (regOffset[1] << 16) | (regOffset[2] << 8) | regOffset[3];
	}
	else
		regVal = regOffset[0];

	printf("chipAddr=%02x, regLen=%d, regval=%08x, rDataLen=%d\n", chipAddr, regLen, regVal, rDataLen);

    return g2c_read(chipAddr, regVal, regLen, rData, rDataLen);
}

int G2C_Test_EX(unsigned char Id, unsigned char chipAddr)
{

	if(g2c_sync(Id) < 0)
	{
		printf("[G2C]Invalid Id %d, can't write via G2C.\n", Id);
		return -1;
	}

	return g2c_probe(chipAddr);

}

int G2C_SetSpeed(unsigned char Id, int KHz)
{
	if(g2c_sync(Id) < 0)
	{
		printf("[G2C]Invalid Id %d, can't read via G2C.\n", Id);
		return -1;
	}

    if (KHz < 10 || KHz > 400)
    {
         printf("[G2C%d] warning, speed %d out of range, speed should between 10 ~ 400Hz\n", Id, KHz);
        return -1;
    }

	printf("[G2C%d] i2c speed changed to %d KHz\n", Id, KHz);
   	return 0;
}

unsigned char G2C_GetBusCount(void)
{
    return G2C_BUS_COUNT;
}


