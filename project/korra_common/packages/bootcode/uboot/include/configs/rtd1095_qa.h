/*
 * Configuration settings for the Realtek 1195 fpga board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_RTD1095_QA_H
#define __CONFIG_RTK_RTD1095_QA_H

/*
 * Include the common settings of RTD1195 platform.
 */
#include <configs/rtd1195_common.h>

/*
 * The followings were RTD1195 demo board specific configuration settings.
 */

/* Board config name */
#define CONFIG_BOARD_FPGA_RTD1195_EMMC 

/* Flash writer setting:
 *   The corresponding setting will be located at
 *   uboot/examples/flash_writer_u/$(CONFIG_FLASH_WRITER_SETTING).inc
 */
//#define CONFIG_FLASH_WRITER_SETTING          

      
/* Flash type is SPI or NAND or eMMC*/
#define CONFIG_SYS_RTK_SPI_FLASH
//#define CONFIG_SYS_RTK_NAND_FLASH
//#define CONFIG_SYS_RTK_EMMC_FLASH

#if defined(CONFIG_SYS_RTK_EMMC_FLASH)
#define CONFIG_FLASH_WRITER_SETTING   		   "1095_force_emmc_nS_nE"
#define CONFIG_CHIP_ID            			   "rtd1095"
#define CONFIG_CUSTOMER_ID            		   "fpga" 
#define CONFIG_CHIP_TYPE            		   "0000"
/* Factory start address and size in eMMC */
#define CONFIG_FACTORY_START	0x220000	/* For eMMC */
#define CONFIG_FACTORY_SIZE	0x400000	/* For eMMC */

/* MMC */
#define CONFIG_MMC
#ifndef CONFIG_PARTITIONS
#define CONFIG_PARTITIONS
#endif
#define CONFIG_DOS_PARTITION
#define CONFIG_GENERIC_MMC   
#define CONFIG_RTK_MMC
#define CONFIG_CMD_MMC
#define USE_SIMPLIFY_READ_WRITE

/* ENV */
#undef	CONFIG_ENV_IS_NOWHERE
#ifdef CONFIG_SYS_FACTORY    
#define CONFIG_ENV_IS_IN_FACTORY
#else
#define CONFIG_ENV_IS_IN_MMC	/* if enable CONFIG_SYS_FACTORY, env will be saved in factory data */
#endif

#define CONFIG_SYS_FACTORY_READ_ONLY

#elif defined(CONFIG_SYS_RTK_NAND_FLASH)
#define CONFIG_FLASH_WRITER_SETTING            "1095_force_nand"
#define CONFIG_CHIP_ID            			   "rtd1095"
#define CONFIG_CUSTOMER_ID            		   "fpga" 
#define CONFIG_CHIP_TYPE            		   "0000"
#define CONFIG_FACTORY_START_BLK	0x60		/* For NAND */
#define CONFIG_FACTORY_SIZE		0x800000	/* For NAND */
#define CONFIG_MTD_DEVICE
#define CONFIG_MTD_PARTITIONS
#define CONFIG_CMD_NAND
#define CONFIG_SYS_MAX_NAND_DEVICE 1
#define CONFIG_SYS_NAND_BASE    0x00000000
#undef	CONFIG_ENV_IS_NOWHERE 
#define CONFIG_ENV_IS_IN_FACTORY
#else
#define CONFIG_FLASH_WRITER_SETTING            "1095_force_spi_nS_nE"
#define CONFIG_CHIP_ID            			   "rtd1095"
#define CONFIG_CUSTOMER_ID            		   "fpga" 
#define CONFIG_CHIP_TYPE            		   "0000"
#define CONFIG_FACTORY_SIZE		0x20000		/* For SPI */

#endif

/* Boot Revision */
#define CONFIG_COMPANY_ID 		"0000"
#define CONFIG_BOARD_ID         "0705"
#define CONFIG_VERSION          "0000"

/*
 * SDRAM Memory Map
 * Even though we use two CS all the memory
 * is mapped to one contiguous block
 */
#if 1 	
// undefine existed configs to prevent compile warning
#undef CONFIG_NR_DRAM_BANKS
#undef CONFIG_SYS_SDRAM_BASE
#undef CONFIG_SYS_RAM_DCU1_SIZE


#define ARM_ROMCODE_SIZE			(44*1024)
#define MIPS_RESETROM_SIZE              (0x1000UL)
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		(ARM_ROMCODE_SIZE)		//for arm, first 32K can't be used as ddr. for lextra, it's okay
#define CONFIG_SYS_RAM_DCU1_SIZE	(0x20000000-ARM_ROMCODE_SIZE)

#undef  V_NS16550_CLK
#define V_NS16550_CLK			27000000
	
#endif


#endif /* __CONFIG_RTK_RTD1095_QA_H */

