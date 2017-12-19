/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 */

#ifndef _ASM_MACH_SYSTEM_H_
#define _ASM_MACH_SYSTEM_H_

#include <asm/arch/io.h>
#include <asm/arch/rbus/crt_reg.h>

// Mips kseq base address
#define MIPS_KSEG0BASE					0x80000000
#define MIPS_KSEG1BASE					0xa0000000
#define MIPS_KSEG_MSK					0xe0000000

#define GET_IC_VERSION()	rtd_inl(SC_VERID_reg)
#define VERSION_A			0x62270000
#define VERSION_B			0x62270001

//RTD299X support 4 uarts, uart0 in ISO_MISC_OFF, uart1/2/3 in MISC
// this is configured by include/configs/xxx.h


//RTD299X support 8 timers, timer0 for VCPU, timer1 for ACPU, timer2 for SCPU
#define SYSTEM_TIMER 		CONFIG_SYS_TIMER
//#define TIMER_CLOCK			50000000	//FPGA
#define TIMER_CLOCK			27000000
#define MAX_HWTIMER_NUM		8

// linux will do the remapping of rbus so that you have to read/write rbus via rtd_xxx series
// or just tells a correct address to the system
#define SYSTEM_GIC_DIST_BASE		GET_MAPPED_RBUS_ADDR(0xb801f000)
#define SYSTEM_GIC_CPU_BASE			GET_MAPPED_RBUS_ADDR(0xb801e100)
#define SYSTEM_PL310_BASE			GET_MAPPED_RBUS_ADDR(0xb801d000)

// The definition of RTD299X ddr address mapping in u-boot.
// Attention: if you need to modify the following settings,
//            please update the RTD299X_address_map.xls in romcode/reference simultaneously.
#define ARM_REDIRECT_CODE_ADDR			(0x00000000)
#define MIPS_EXC_REDIRECT_CODE_ADDR		(0x00000080)
#define MIPS_AUDIO_GDB_VECTOR_ADDR		(0x00000088)
#define MIPS_VIDEO_GDB_VECTOR_V1_ADDR	(0x0000008c)
#define MIPS_VIDEO_GDB_VECTOR_V2_ADDR	(0x00000090)
#define MIPS_AUDIO_EXC_VECTOR_ADDR		(0x00000094)
#define MIPS_VIDEO_EXC_VECTOR_V1_ADDR	(0x000000a4)
#define MIPS_VIDEO_EXC_VECTOR_V2_ADDR	(0x000000b4)
#define MIPS_UART_REG_BASE_ADDR			(0x000000c4)
#define MIPS_BOOT_AV_INFO_PTR_ADDR		(0x000000cc)
#define MIPS_AUDIO_FLAG_PTR_ADDR		(0x000000d0)
#define MIPS_VIDEO_FLAG_PTR_V1_ADDR		(0x000000d4)
#define MIPS_VIDEO_FLAG_PTR_V2_ADDR		(0x000000d8)
#define MIPS_VIDEO_FW_ENTRY_PTR_V2_ADDR	(0x000000dc)
#define MIPS_AUDIO_FW_ENTRY_PTR_ADDR	(0x000000e0)
#define MIPS_VIDEO_FW_ENTRY_PTR_V1_ADDR	(0x000000e4)
#define MIPS_SHARED_PRINTK_BUFFER_ADDR	(0x000000e8)	// 0x000000e8~0x000000ff
#define MIPS_SHARED_PRINTK_BUFFER_SIZE	(0x18)
#define MIPS_EXC_DISPATCH_CODE_ADDR		(0x00000100)
#define MIPS_V_ENTRY_CODE_ADDR			(0x00000200)
#define MIPS_AUDIO_OUTPUT_INFO_ADDR		(0x00001000)
#define MIPS_AUDIO_OUTPUT_INFO_SIZE		(0x10)
#define MIPS_BOOT_AV_INFO_ADDR			(0x00001400)
#define MIPS_ISR_VIDEO_IMG_ADDR			(0x00001500)
#define MIPS_ROS_BOOT_VECTOR_IMG_ADDR	(0x00001900)
#define MIPS_A_ENTRY_CODE_ADDR			(0x00002000)
#define UBOOT_EXTERN_PARAM_ADDR			(0x00002800)
#define UBOOT_LOGO_START_ADDR			(0x00003000)
#define ECPU_KERNEL_ENTRY_ADDR			(0x00004000)	// 0x00004000~0x000087ff
#define EXTERN_PARAM_FROM_FLASH_ADDR	(0x00009000)	// 0x00009000~0x000097ff
#define ARM_REDIRECT_CODE2_ADDR			(0x0001f800)	// 0x0001f800~0x0001ffff

#define BOOTCODE_TEXT_ADDR				(CONFIG_SYS_TEXT_BASE)
#define LINUX_KERNEL_ADDR				(0x00100000)
#define LINUX_KERNEL_ENTRY				(0x00108000)
#define ENCRYPTED_BOOTCODE_ADDR			(0x00200000)
#define DVRBOOT_EXE_BIN_ENTRY_ADDR		(0x01500000)
#define MIPS_AUDIO_FW_ENTRY_ADDR		(0x01700000)
#define MIPS_VIDEO_FW_1_ENTRY_ADDR		(0x01a00000)
#define MIPS_VIDEO_FW_2_ENTRY_ADDR		(0x01d00000)
#define RPC_SHARE_MEMORY_ADDR			(0x01ff8000)

/* Memory for power on music, video, and image. Include stream buffer and decode buffer */
#define KERNEL_RESERVE_FOR_POM_POV_ADDR	(0x02000000)	// 0x02000000~0x05ffffff
#define KERNEL_RESERVE_FOR_POM_POV_SIZE	(0x04000000)	// 64M
#define POWER_ON_MUSIC_STREAM_ADDR		(0x02000000)
#define POWER_ON_VIDEO_STREAM_ADDR		(0x02100000)
#define POWER_ON_MUSIC_BUFFER_ADDR		(0x03000000)	// 0x03000000~0x030fffff
#define POWER_ON_MUSIC_BUFFER_SIZE		(0x00100000)	// 1M
#define POWER_ON_VIDEO_BUFFER_ADDR		(0x04000000)	// 0x04000000~0x05ffffff
#define POWER_ON_VIDEO_BUFFER_SIZE		(0x02000000)	// 32M
#define POWER_ON_VIDEO_LAST_IMAGE_ADDR	(KERNEL_RESERVE_FOR_POM_POV_ADDR + KERNEL_RESERVE_FOR_POM_POV_SIZE)
#define POWER_ON_VIDEO_LAST_IMAGE_SIZE	(0x00400000)	// 4M

#define FIRMWARE_DESCRIPTION_TABLE_ADDR	(0x06400000)
#define FACTORY_DATA_ADDR				(0x07000000)	// 0x07000000~0x077fffff (8M)
#define FACTORY_RO_DATA_ADDR			(0x07800000)	// 0x07800000~0x07820000 (128K)
#define UBOOT_HEAP_RELOCATION_ADDR		(0x07880000)	// 0x07880000~0x078fffff (512K)
#define UBOOT_NONCACHE_MEMORY_ADDR		(0x07900000)	// 0x07900000~0x079fffff (1M)
#define UBOOT_SECURE_MCP_MEMORY_ADDR	(0x08000000)	// 0x08000000~0x09ffffff
#define UBOOT_SECURE_MCP_MEMORY_SIZE	(0x02000000)	// 32M
#define ENCRYPTED_LINUX_KERNEL_ADDR		(0x0a000000)
#define COMPRESSED_FW_IMAGE_ADDR		(0x0b000000)
#define TEMP_BUFFER_FOR_FLASH_DATA_ADDR	(0x0c000000)

// RTD299X SPI flash base address
#define BOARD_FLASH_ADDR_BASE	(0xb8100000)

// RTD299X Dummy Register
#define ACPU_JUMP_ADDR_reg		(0xb801a618)	/* register which represent ACPU jump address */
#define VCPU_JUMP_ADDR_reg		(0xb801a61c)	/* register which represent VCPU jump address */
#define REG_CRT_SUSPEND_reg		(WDOG_DATA1)	/* register which represent suspend to ram or disk */
#define REG_AC_DC_ON_reg		(WDOG_DATA12)	/* register which represent AC or DC on */

#endif	// _ASM_MACH_SYSTEM_H_

