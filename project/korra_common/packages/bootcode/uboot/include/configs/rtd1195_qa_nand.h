/*
 * Configuration settings for the Realtek 1195 qa board.
 *
 * Won't include this file.
 * Just type "make <board_name>_config" and will be included in source tree.
 */

#ifndef __CONFIG_RTK_RTD1195_QA_NAND_H
#define __CONFIG_RTK_RTD1195_QA_NAND_H

/*
 * Include the common settings of RTD1195 platform.
 */
#include <configs/rtd1195_common.h>

/*
 * The followings were RTD1195 demo board specific configuration settings.
 */

/* Board config name */
#define CONFIG_BOARD_QA_RTD1195
       
      
/* Flash type is NAND*/
#define CONFIG_SYS_RTK_NAND_FLASH


#if defined(CONFIG_SYS_RTK_NAND_FLASH)
	/* Flash writer setting:
	*  The corresponding setting will be located at
	*  uboot/examples/flash_writer_u/$(CONFIG_FLASH_WRITER_SETTING).inc */	
	#define CONFIG_FLASH_WRITER_SETTING            "1195_force_nand"
	#define CONFIG_CHIP_ID            			   "rtd1195"
	#define CONFIG_CUSTOMER_ID            		   "demo" 
	#define CONFIG_CHIP_TYPE            		   "0000"
	#define CONFIG_FACTORY_START_BLK	0x60		/* For NAND */
	#define CONFIG_FACTORY_SIZE     0x800000    /*For MLC; SLC:0x400000 */
	#define CONFIG_MTD_DEVICE
	#define CONFIG_MTD_PARTITIONS
	#define CONFIG_CMD_NAND
	#define CONFIG_SYS_MAX_NAND_DEVICE 1
	#define CONFIG_SYS_NAND_BASE    0x00000000
	#undef  CONFIG_ENV_IS_NOWHERE
	#define CONFIG_ENV_IS_IN_FACTORY
	
	/* for secure*/
	//#define CONFIG_NAND_ON_THE_FLY_TEST_KEY  
	//#define CONFIG_CMD_KEY_BURNING 

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


#define ARM_ROMCODE_SIZE			(44*1024)			//page aligned
#define MIPS_RESETROM_SIZE          (0x1000UL)
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_SYS_SDRAM_BASE		(ARM_ROMCODE_SIZE)	//for arm, first 42K can't be used as ddr. for lextra, it's okay
#define CONFIG_SYS_RAM_DCU1_SIZE	0x40000000
	
#endif

/* Bootcode Feature: Rescue linux read from USB */
#define CONFIG_RESCUE_FROM_USB
#ifdef CONFIG_RESCUE_FROM_USB
	#define CONFIG_RESCUE_FROM_USB_VMLINUX			"nand.uImage"
	#define CONFIG_RESCUE_FROM_USB_DTB				"rescue.nand.dtb"
	#define CONFIG_RESCUE_FROM_USB_ROOTFS			"rescue.root.nand.cpio.gz_pad.img"
	#define CONFIG_RESCUE_FROM_USB_AUDIO_CORE		"bluecore.audio"
#endif /* CONFIG_RESCUE_FROM_USB */


#endif /* __CONFIG_RTK_RTD1195_QA_NAND_H */

