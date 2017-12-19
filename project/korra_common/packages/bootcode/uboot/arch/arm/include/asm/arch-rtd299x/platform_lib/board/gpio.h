#ifndef GPIO_USERSPACE_ACCESS_LIBRARY
#define GPIO_USERSPACE_ACCESS_LIBRARY

#include <asm/arch/rbus/iso_reg.h>

//#define MIS_PSELH	((volatile int)0xb801b000)
//#define MIS_PSELL	((volatile int)0xb801b004)

//see "rtd299x_MISC.doc-page35"
#define MIS_REG_BASE		0xb801b000

/* GPIO */
#define MIS_GP0DIR		(MIS_REG_BASE + 0xc00)
#define MIS_GP1DIR		(MIS_REG_BASE + 0xc04)
#define MIS_GP2DIR		(MIS_REG_BASE + 0xc08)
#define MIS_GP3DIR		(MIS_REG_BASE + 0xc0c)
#define MIS_GP4DIR		(MIS_REG_BASE + 0xc10)
#define MIS_GP5DIR		(MIS_REG_BASE + 0xc14)
#define MIS_GP0DATO		(MIS_REG_BASE + 0xc18)
#define MIS_GP1DATO		(MIS_REG_BASE + 0xc1c)
#define MIS_GP2DATO		(MIS_REG_BASE + 0xc20)
#define MIS_GP3DATO		(MIS_REG_BASE + 0xc24)
#define MIS_GP4DATO		(MIS_REG_BASE + 0xc28)
#define MIS_GP5DATO		(MIS_REG_BASE + 0xc2c)
#define MIS_GP0DATI		(MIS_REG_BASE + 0xc30)
#define MIS_GP1DATI		(MIS_REG_BASE + 0xc34)
#define MIS_GP2DATI		(MIS_REG_BASE + 0xc38)
#define MIS_GP3DATI		(MIS_REG_BASE + 0xc3c)
#define MIS_GP4DATI		(MIS_REG_BASE + 0xc40)
#define MIS_GP5DATI		(MIS_REG_BASE + 0xc44)

#define ISO_GPDIR		(GPDIR_reg)
#define ISO_GP1DIR		(GPDIR_1_reg)
#define ISO_GPDATO		(GPDATO_reg)
#define ISO_GP1DATO		(GPDATO_1_reg)
#define ISO_GPDATI		(GPDATI_reg)
#define ISO_GP1DATI		(GPDATI_1_reg)

int getGPIO(int GPIO_NUM);
int setGPIO(int GPIO_NUM, int value);
int getISOGPIO(int ISOGPIO_NUM);
int setISOGPIO(int ISOGPIO_NUM, int value);


#endif
