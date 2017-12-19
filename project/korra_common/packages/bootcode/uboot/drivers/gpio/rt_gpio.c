#include <common.h>
//#include <platform_lib/board/gpio.h>
#include <asm/arch/io.h>
#include <asm/arch/rbus/misc_reg.h>
#include <asm/arch/rbus/iso_reg.h>

#define gpio_assert(x)		printf("assert assert assert!!!! GPIO_NUM=%d\n", GPIO_NUM)
#define iso_gpio_assert(x)	printf("assert assert assert!!!! ISOGPIO_NUM=%d\n", ISOGPIO_NUM)

int getGPIO(int GPIO_NUM) {
	int bitOffset;
	volatile int regAddr;
	int regValue;

	if(GPIO_NUM <= 31) {
		bitOffset = GPIO_NUM;

		// Set Direction to Input
		regAddr = (GP0DIR_reg);
		regValue = rtd_inl(regAddr);
		regValue = regValue & (~(0x01 << bitOffset));
		rtd_outl(regAddr, regValue);

		// Get Value
		regAddr = (GP0DATI_reg);
		regValue = rtd_inl(regAddr);
		if(regValue & (0x01 << bitOffset))
			return 1;
		else
			return 0;
	}
	else if(GPIO_NUM >= 32 && GPIO_NUM <= 59) {
		bitOffset = GPIO_NUM - 32;

		// Set Direction to Input
		regAddr = (GP1DIR_reg);
		regValue = rtd_inl(regAddr);
		regValue = regValue & (~(0x01 << bitOffset));
		rtd_outl(regAddr, regValue);

		// Get Value
		regAddr = (GP1DATI_reg);
		regValue = rtd_inl(regAddr);
		if(regValue & (0x01 << bitOffset))
			return 1;
		else
			return 0;
	}
	else { // no such GPIO pin!
		printf("no GPIO#%d pin\n",GPIO_NUM);
		return -1;
	}
}

int setGPIO(int GPIO_NUM, int value) {
	int bitOffset;
	volatile int regAddr;
	int regValue;

	if(GPIO_NUM <= 31) {
		bitOffset = GPIO_NUM;

		// Set Direction to Ouput
		regAddr = (GP0DIR_reg);
		regValue = rtd_inl(regAddr);
		regValue = regValue | (0x01 << bitOffset);
		rtd_outl(regAddr, regValue);

		// Set Value
		regAddr = (GP0DATO_reg);
		regValue = rtd_inl(regAddr);

		if(value)
			regValue = regValue | (0x01 << bitOffset);	// set to 1
		else
			regValue = regValue & (~(0x01 << bitOffset)); // set to 0

		rtd_outl(regAddr, regValue);

		return 0;
	}
	else if(GPIO_NUM >= 32 && GPIO_NUM <= 59) {
		bitOffset = GPIO_NUM - 32;

		// Set Direction to Ouput
		regAddr = (GP1DIR_reg);
		regValue = rtd_inl(regAddr);
		regValue = regValue | (0x01 << bitOffset);
		rtd_outl(regAddr, regValue);

		// Set Value
		regAddr = (GP1DATO_reg);
		regValue = rtd_inl(regAddr);

		if(value)
			regValue = regValue | (0x01 << bitOffset);	// set to 1
		else
			regValue = regValue & (~(0x01 << bitOffset)); // set to 0

		rtd_outl(regAddr, regValue);

		return 0;
	}
	else { // no such GPIO pin!
		printf("no GPIO#%d pin\n",GPIO_NUM);
		return -1;
	}
}

int getISOGPIO(int ISOGPIO_NUM)
{
	int bitOffset;
	volatile int regAddr;
	int regValue;

	if(ISOGPIO_NUM <= 20) {
		bitOffset = ISOGPIO_NUM;

		// Set Direction to Input
		regAddr = (GPDIR_reg);
		regValue = rtd_inl(regAddr);
		regValue = regValue & (~(0x01 << bitOffset));
		rtd_outl(regAddr, regValue);

		// Get Value
		regAddr = (GPDATI_reg);
		regValue = rtd_inl(regAddr);
		if(regValue & (0x01 << bitOffset))
			return 1;
		else
			return 0;
	}
	else { // no such ISO GPIO pin!
		printf("no ISOGPIO#%d pin\n",ISOGPIO_NUM);
		return -1;
	}
}

int setISOGPIO(int ISOGPIO_NUM, int value)
{
	int bitOffset;
	volatile int regAddr;
	int regValue;

	if(ISOGPIO_NUM <= 20) {
		bitOffset = ISOGPIO_NUM;

		// Set Value
		regAddr = (GPDATO_reg);
		regValue = rtd_inl(regAddr);

		if(value)
			regValue = regValue | (0x01 << bitOffset);  // set to 1
		else
			regValue = regValue & (~(0x01 << bitOffset)); // set to 0

		rtd_outl(regAddr, regValue);

		// Set Direction to Ouput
		regAddr = (GPDIR_reg);
		regValue = rtd_inl(regAddr);
		regValue = regValue | (0x01 << bitOffset);
		rtd_outl(regAddr, regValue);

		return 0;
	}	
	else { // no such ISO GPIO pin!
		printf("no ISOGPIO#%d pin\n",ISOGPIO_NUM);
		return -1;
	}
}

