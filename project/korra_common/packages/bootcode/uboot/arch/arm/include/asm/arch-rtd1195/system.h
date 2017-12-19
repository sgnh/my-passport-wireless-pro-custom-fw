/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 *	=========================================
 *	  Date		 Who			Comment
 *	=========================================
 * 	20130606	Louis Yang		Change for phoenix 1195
 *
 */

#ifndef _ASM_MACH_SYSTEM_H_
#define _ASM_MACH_SYSTEM_H_

#include <asm/arch/io.h>
#include <asm/arch/rbus/crt_reg.h>
#include <asm/arch/rbus/sb2_reg.h>
#include <asm/arch/platform_lib/board/gpio.h>

// Mips kseq base address
#define MIPS_KSEG0BASE		0x80000000
#define MIPS_KSEG1BASE		0xa0000000
#define MIPS_KSEG_MSK		0xe0000000

#define GET_IC_VERSION()	rtd_inl(CHIP_INFO)
#define GET_IC_ID()	        rtd_inl(CHIP_ID)
#define VERSION_A	        0x00000000
#define VERSION_B	        0x00010000
#define VERSION_C	        0x00020000

//RTD1195  support 2 uarts, uart0 in ISO_MISC_OFF, uart1 in MISC
// this is configured by include/configs/xxx.h


//RTD1195 support 3 MISC timers,TC0/TC1 for SCPU NWC,TC2 for SCPU SWC.
#define SYSTEM_TIMER 		CONFIG_SYS_TIMER

#if defined (CONFIG_V6_VERIFICATION)
#define TIMER_CLOCK		33000000	//FPGA
#else
#define TIMER_CLOCK		27000000
#endif
#define MAX_HWTIMER_NUM		3

// linux will do the remapping of rbus so that you have to read/write rbus via rtd_xxx series
// or just tells a correct address to the system
#define SYSTEM_GIC_DIST_BASE			GET_MAPPED_RBUS_ADDR(0xb801f000)
#define SYSTEM_GIC_CPU_BASE				GET_MAPPED_RBUS_ADDR(0xb801e100)


// The definition of RTD1195 ddr address mapping in u-boot.
// Attention: if you need to modify the following settings,
// please update the RTD1195_address_map.xls in romcode/reference/flowchart diagram simultaneously.
#define ARM_REDIRECT_CODE_ADDR					(0x00000000)
#define MIPS_EXC_REDIRECT_CODE_ADDR				(0x00000080)
#define MIPS_AUDIO_EXC_VECTOR_ADDR				(0x00000094)
#define MIPS_EXC_DISPATCH_CODE_ADDR				(0x00000100)
#define MIPS_ISR_VIDEO_IMG_ADDR					(0x00001500)
#define MIPS_ROS_BOOT_VECTOR_IMG_ADDR			(0x00001900)
#define MIPS_A_ENTRY_CODE_ADDR					(0x00002000)


#define MIPS_UART_REG_BASE_ADDR					(ARM_ROMCODE_SIZE+0x000000c4)
#define MIPS_ONE_STEP_INFO_ADDR					(ARM_ROMCODE_SIZE+0x000000c8)
#define MIPS_BOOT_AV_INFO_PTR_ADDR				(ARM_ROMCODE_SIZE+0x000000cc)
#define MIPS_AUDIO_FLAG_PTR_ADDR				(ARM_ROMCODE_SIZE+0x000000d0)
	
	
#define MIPS_AUDIO_FW_ENTRY_PTR_ADDR			(ARM_ROMCODE_SIZE+0x000000e0)
#define MIPS_SHARED_PRINTK_BUFFER_ADDR			(ARM_ROMCODE_SIZE+0x000000e8)	// 0x0000b0e8~0x0000b0ff
#define MIPS_SHARED_PRINTK_BUFFER_SIZE			(0x18)
#define MIPS_BOOT_AV_INFO_ADDR					(ARM_ROMCODE_SIZE+0x00001400)


#define BOOTCODE_TEXT_ADDR						(CONFIG_SYS_TEXT_BASE) 		//0x00020000
#define LINUX_KERNEL_ADDR						(0x00108000)
#define DVRBOOT_EXE_BIN_ENTRY_ADDR				(0x01500000)
#define MIPS_AUDIO_FW_ENTRY_ADDR				(0x01b00000)


#define FIRMWARE_DESCRIPTION_TABLE_ADDR			(0x06400000)
#define FACTORY_DATA_ADDR						(0x07000000)	// 0x07000000~0x077fffff (8M)
#define FACTORY_RO_DATA_ADDR					(0x07800000)	// 0x07800000~0x07820000 (128K)
#define UBOOT_HEAP_RELOCATION_ADDR				(0x07880000)	// 0x07880000~0x078fffff (512K)
#define UBOOT_NONCACHE_MEMORY_ADDR				(0x07900000)	// 0x07900000~0x079fffff (1M)
#define UBOOT_SECURE_MCP_MEMORY_ADDR			(0x08000000)	// 0x08000000~0x09ffffff
#define UBOOT_SECURE_MCP_MEMORY_SIZE			(0x02000000)	// 32M
#define ENCRYPTED_FW_ADDR						(0x05000000)
#define ENCRYPTED_LINUX_KERNEL_ADDR				(0x0a000000)
#define COMPRESSED_FW_IMAGE_ADDR				(0x0b000000)
#define TEMP_BUFFER_FOR_FLASH_DATA_ADDR			(0x0c000000)

// RTD1195 SPI flash base address
#define BOARD_FLASH_ADDR_BASE					(0x18100000)

// RTD1195 Dummy Register; for phoenix, refer to romcode sysdefs.h, iso doc
//#define ACPU_JUMP_ADDR_reg					ISO_RESERVED_USER_3	/* register which represent ACPU jump address */
#define ACPU_JUMP_ADDR_reg          			(0x58007080) //work around for lx5280 rom.
#define REG_CRT_SUSPEND_reg						(WDOG_DATA1)	/* register which represent suspend to ram or disk */
#define REG_AC_DC_ON_reg						(WDOG_DATA12)	/* register which represent AC or DC on */
		
#define VO_RESOLUTION 							(0x18070000 + 0x1100 ) // VO_RESOLUTION_INFO

#endif	// _ASM_MACH_SYSTEM_H_

