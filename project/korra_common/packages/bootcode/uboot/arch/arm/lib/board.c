/*
 * (C) Copyright 2002-2006
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

/*
 * To match the U-Boot user interface on ARM platforms to the U-Boot
 * standard (as on PPC platforms), some messages with debug character
 * are removed from the default U-Boot build.
 *
 * Define DEBUG here if you want additional info as shown below
 * printed upon startup:
 *
 * U-Boot code: 00F00000 -> 00F3C774  BSS: -> 00FC3274
 * IRQ Stack: 00ebff7c
 * FIQ Stack: 00ebef7c
 */

#include <common.h>
#include <command.h>
#include <malloc.h>
#include <stdio_dev.h>
#include <version.h>
#include <net.h>
#include <serial.h>
#include <nand.h>
#include <onenand_uboot.h>
#include <mmc.h>
#include <libfdt.h>
#include <fdtdec.h>
#include <post.h>
#include <logbuff.h>
#include <platform_lib/board/pcb_mgr.h>
#include <platform_lib/board/power.h>
#include <system.h>
#include <fw_info.h>
#include <extern_param.h>
#include <logo_disp/logo_disp_api.h>
#include <asm/arch/factorylib.h>
#include <asm/arch/factorylib_ro.h>
#include <asm/arch/bootparam.h>
#include <asm/arch/rbus/misc_reg.h>
#include <asm/arch/rbus/iso_reg.h>
#include <watchdog.h>
#if defined(CONFIG_SYS_IR_SUPPORT)
#include <asm/arch/ir.h>
#endif
#ifdef CONFIG_BITBANGMII
#include <miiphy.h>
#endif

#ifdef CONFIG_DRIVER_SMC91111
#include "../drivers/net/smc91111.h"
#endif
#ifdef CONFIG_DRIVER_LAN91C96
#include "../drivers/net/lan91c96.h"
#endif

#ifdef CONFIG_SYS_PANEL_SUPPORT
#include "panel.h"
#endif

DECLARE_GLOBAL_DATA_PTR;

ulong monitor_flash_len;

uchar boot_ac_on = 0;

#ifdef CONFIG_HAS_DATAFLASH
extern int  AT91F_DataflashInit(void);
extern void dataflash_print_info(void);
#endif

extern int init_customize_func(void);

#if defined(CONFIG_HARD_I2C) || \
    defined(CONFIG_SOFT_I2C)
#include <i2c.h>
#endif

/************************************************************************
 *  External variables
 ************************************************************************/
extern int _f_exc_redirect_img, _e_exc_redirect_img;
extern int _f_exc_dispatch_img, _e_exc_dispatch_img;
extern int _f_a_entry_img, _e_a_entry_img;
extern int _f_v_entry_img, _e_v_entry_img;
extern int _f_isrvideo_img, _e_isrvideo_img;
extern int _f_rosbootvector_img, _e_rosbootvector_img;

/************************************************************************
 * Coloured LED functionality
 ************************************************************************
 * May be supplied by boards if desired
 */
inline void __coloured_LED_init(void) {}
void coloured_LED_init(void)
	__attribute__((weak, alias("__coloured_LED_init")));
inline void __red_led_on(void) {}
void red_led_on(void) __attribute__((weak, alias("__red_led_on")));
inline void __red_led_off(void) {}
void red_led_off(void) __attribute__((weak, alias("__red_led_off")));
inline void __green_led_on(void) {}
void green_led_on(void) __attribute__((weak, alias("__green_led_on")));
inline void __green_led_off(void) {}
void green_led_off(void) __attribute__((weak, alias("__green_led_off")));
inline void __yellow_led_on(void) {}
void yellow_led_on(void) __attribute__((weak, alias("__yellow_led_on")));
inline void __yellow_led_off(void) {}
void yellow_led_off(void) __attribute__((weak, alias("__yellow_led_off")));
inline void __blue_led_on(void) {}
void blue_led_on(void) __attribute__((weak, alias("__blue_led_on")));
inline void __blue_led_off(void) {}
void blue_led_off(void) __attribute__((weak, alias("__blue_led_off")));

extern int sink_capability_handler(int set);

/*
 ************************************************************************
 * Init Utilities							*
 ************************************************************************
 * Some of this code should be moved into the core functions,
 * or dropped completely,
 * but let's get it working (again) first...
 */

#if defined(CONFIG_ARM_DCC) && !defined(CONFIG_BAUDRATE)
#define CONFIG_BAUDRATE 115200
#endif

static int init_baudrate(void)
{
	gd->baudrate = getenv_ulong("baudrate", 10, CONFIG_BAUDRATE);
	return 0;
}

static int display_banner(void)
{
	printf("\n\n%s\n\n", version_string);
	debug("U-Boot code: %08lX -> %08lX  BSS: -> %08lX\n",
	       _TEXT_BASE,
	       _bss_start_ofs + _TEXT_BASE, _bss_end_ofs + _TEXT_BASE);
#ifdef CONFIG_MODEM_SUPPORT
	debug("Modem Support enabled\n");
#endif
#ifdef CONFIG_USE_IRQ
	debug("IRQ Stack: %08lx\n", IRQ_STACK_START);
	debug("FIQ Stack: %08lx\n", FIQ_STACK_START);
#endif

	return (0);
}

/*
 * WARNING: this code looks "cleaner" than the PowerPC version, but
 * has the disadvantage that you either get nothing, or everything.
 * On PowerPC, you might see "DRAM: " before the system hangs - which
 * gives a simple yet clear indication which part of the
 * initialization if failing.
 */
static int display_dram_config(void)
{
	int i;

#if 0 
	puts("RAM Configuration:\n");

	for (i = 0; i < CONFIG_NR_DRAM_BANKS; i++) {
		printf("Bank #%d: %08lx ", i, gd->bd->bi_dram[i].start);
		print_size(gd->bd->bi_dram[i].size, "\n");
	}
#else
	ulong size = 0;

	for (i = 0; i < CONFIG_NR_DRAM_BANKS; i++)
		size += gd->bd->bi_dram[i].size;

	puts("DRAM:  ");
	print_size(size, "\n");
#endif

	return (0);
}

#if defined(CONFIG_HARD_I2C) || defined(CONFIG_SOFT_I2C)
static int init_func_i2c(void)
{
	puts("I2C:   ");
	i2c_init(CONFIG_SYS_I2C_SPEED, CONFIG_SYS_I2C_SLAVE);
	puts("ready\n");
	return (0);
}
#endif

#if defined(CONFIG_CMD_PCI) || defined (CONFIG_PCI)
#include <pci.h>
static int arm_pci_init(void)
{
	pci_init();
	return 0;
}
#endif /* CONFIG_CMD_PCI || CONFIG_PCI */

/*
 * Breathe some life into the board...
 *
 * Initialize a serial port as console, and carry out some hardware
 * tests.
 *
 * The first part of initialization is running from Flash memory;
 * its main purpose is to initialize the RAM so that we
 * can relocate the monitor code to RAM.
 */

/*
 * All attempts to come up with a "common" initialization sequence
 * that works for all boards and architectures failed: some of the
 * requirements are just _too_ different. To get rid of the resulting
 * mess of board dependent #ifdef'ed code we now make the whole
 * initialization sequence configurable to the user.
 *
 * The requirements for any new initalization function is simple: it
 * receives a pointer to the "global data" structure as it's only
 * argument, and returns an integer return code, where 0 means
 * "continue" and != 0 means "fatal error, hang the system".
 */
typedef int (init_fnc_t) (void);

int print_cpuinfo(void);

void __dram_init_banksize(void)
{
	gd->bd->bi_dram[0].start = CONFIG_SYS_SDRAM_BASE;
	gd->bd->bi_dram[0].size =  gd->ram_size;
}
void dram_init_banksize(void)
	__attribute__((weak, alias("__dram_init_banksize")));

int __arch_cpu_init(void)
{
	return 0;
}

int arch_cpu_init(void)
	__attribute__((weak, alias("__arch_cpu_init")));

init_fnc_t *init_sequence[] = {
	clock_init,			/* init clock, pll related */
	arch_cpu_init,		/* basic arch cpu dependent setup */

#if defined(CONFIG_BOARD_EARLY_INIT_F)
	board_early_init_f,
#endif
#ifdef CONFIG_OF_CONTROL
	fdtdec_check_fdt,
#endif
	timer_init,		/* initialize timer */
#ifdef CONFIG_FSL_ESDHC
	get_clocks,
#endif
	env_init,		/* initialize environment */
	init_baudrate,		/* initialze baudrate settings */
	serial_init,		/* serial communications setup */
	console_init_f,		/* stage 1 init of console */
	display_banner,		/* say that we are here */
#if defined(CONFIG_DISPLAY_CPUINFO)
	print_cpuinfo,		/* display cpu info (and speed) */
#endif
#if defined(CONFIG_CUSTOMIZE_FUNC_REGISTER)
	init_customize_func,	/* init customize func feature */
#endif
#if defined(CONFIG_SYS_PCB_MANAGER)
	pcb_mgr_init,	/* initialize pinmux*/
#endif
#if defined(CONFIG_DISPLAY_BOARDINFO)
	checkboard,		/* display board info */
#endif
#if defined(CONFIG_HARD_I2C) || defined(CONFIG_SOFT_I2C)
	init_func_i2c,
#endif
#if !defined(CONFIG_RTD299X) && !defined(CONFIG_RTD1195)
	dram_init,		/* configure available RAM banks */
#endif
	NULL,
};

void board_init_f(ulong bootflag)
{
	init_fnc_t **init_fnc_ptr;
#ifndef CONFIG_NO_RELOCATION
	bd_t *bd;
	gd_t *id;
	ulong addr_sp;
#endif
	ulong addr; /*, addr_heap; */
#ifdef CONFIG_PRAM
	ulong reg;
#endif

#if defined(CONFIG_RTD299X) || defined(CONFIG_RTD1195)
	/* save the function address of printf in specified address */
	/* please find out PRINTF_ADDRESS in System.map 			*/
	/* 0x00020060~0x0002008F */
	extern unsigned int PRINTF_ADDRESS;
	extern unsigned int PRINTF_ADDRESS2;
	extern unsigned int PRINTF_ADDRESS3;
	extern unsigned int PRINTF_ADDRESS4; // printf
	extern unsigned int PRINTF_ADDRESS5;
	extern unsigned int PRINTF_ADDRESS6; // flush_dcache_all
	extern unsigned int PRINTF_ADDRESS7;
	extern unsigned int PRINTF_ADDRESS8;
	extern unsigned int UATAG_ADDRESS9;  // romcode update this for boot device info ( magic number 0xF9E8D7C6 )
	extern unsigned int UATAG_ADDRESS10; // romcode update this for boot device info
	extern unsigned int UATAG_ADDRESS11; //
	extern unsigned int UATAG_ADDRESS12; //
	*((unsigned int *)&PRINTF_ADDRESS)  = (unsigned int)0xF9E8D7C6;
	*((unsigned int *)&PRINTF_ADDRESS2) = (unsigned int)printf;
	*((unsigned int *)&PRINTF_ADDRESS3) = (unsigned int)0xF9E8D7C6;
	*((unsigned int *)&PRINTF_ADDRESS4) = (unsigned int)printf;
	*((unsigned int *)&PRINTF_ADDRESS5) = (unsigned int)0xF9E8D7C6;
	*((unsigned int *)&PRINTF_ADDRESS6) = (unsigned int)flush_dcache_all;
	*((unsigned int *)&PRINTF_ADDRESS7) = (unsigned int)0xF9E8D7C6;
	*((unsigned int *)&PRINTF_ADDRESS8) = (unsigned int)flush_cache;
#endif
	bootstage_mark_name(BOOTSTAGE_ID_START_UBOOT_F, "board_init_f");

#ifdef CONFIG_REALTEK_WATCHDOG
        WATCHDOG_ENABLE();
        //puts("WATCHDOG_ENABLE\n\n\n");
#else
        WATCHDOG_DISABLE();
        //puts("WATCHDOG_DISABLE\n\n\n");
#endif


	/* Pointer is writable since we allocated a register for it */
#ifdef CONFIG_NO_RELOCATION
	gd = (gd_t *) _irq_stack_start;
#else
	gd = (gd_t *) ((CONFIG_SYS_INIT_SP_ADDR) & ~0x07);
#endif

	/* compiler optimization barrier needed for GCC >= 3.4 */
	__asm__ __volatile__("": : :"memory");

	memset((void *)gd, 0, sizeof(gd_t));

	gd->mon_len = _bss_end_ofs;
#ifdef CONFIG_OF_EMBED
	/* Get a pointer to the FDT */
	gd->fdt_blob = _binary_dt_dtb_start;
#elif defined CONFIG_OF_SEPARATE
	/* FDT is at end of image */
	gd->fdt_blob = (void *)(_end_ofs + _TEXT_BASE);
#else
	//we do here
#endif
	/* Allow the early environment to override the fdt address */
	gd->fdt_blob = (void *)getenv_ulong("fdtcontroladdr", 16,
						(uintptr_t)gd->fdt_blob);

	for (init_fnc_ptr = init_sequence; *init_fnc_ptr; ++init_fnc_ptr) {
		if ((*init_fnc_ptr)() != 0) {
			hang ();
		}
	}

#if defined(CONFIG_RTD299X) || defined(CONFIG_RTD1195)
	#ifdef CONFIG_SYS_RAM_DCU1_SIZE
		gd->ram_size = CONFIG_SYS_RAM_DCU1_SIZE;
		#ifdef CONFIG_SYS_RAM_DCU2_SIZE
			gd->ram_size += CONFIG_SYS_RAM_DCU2_SIZE;
		#endif
	#else
		gd->ram_size = 0x10000000;
	#endif
#endif

#ifdef CONFIG_OF_CONTROL
	/* For now, put this check after the console is ready */
	if (fdtdec_prepare_fdt()) {
		panic("** CONFIG_OF_CONTROL defined but no FDT - please see "
			"doc/README.fdt-control");
	}
#endif

	debug("monitor len: %08lX\n", gd->mon_len);
	/*
	 * Ram is setup, size stored in gd !!
	 */
	debug("ramsize: %08lX\n", gd->ram_size);

#ifdef CONFIG_NO_RELOCATION
	debug("Reserving %ldk for U-Boot from : %08x\n", gd->mon_len >> 10, CONFIG_SYS_TEXT_BASE);
	debug("Stack Pointer is: %08lx\n", (ulong)_stack_start);
	debug("Reserving %zu Bytes for Global Data at: %08x\n", sizeof (gd_t), (unsigned int)gd);

	/* setup stackpointer for exeptions */
    gd->irq_sp = (ulong)_irq_stack_start;

	addr = (ulong) _irq_stack_start;
	addr += sizeof(gd_t);
    gd->bd = (bd_t *)addr;
    debug("Reserving %zu Bytes for Board Info at: %08x\n", sizeof (bd_t), (unsigned int)gd->bd);

	addr += sizeof(bd_t);

#ifdef CONFIG_HEAP_RELOCATION
	gd->heap_addr = UBOOT_HEAP_RELOCATION_ADDR;
#else
	// 4K aligned
	if (addr&(0x1000-1)) {
		addr &= ~(0x1000-1);
        addr += 0x1000;
	}

	gd->heap_addr = addr;

    addr += TOTAL_MALLOC_LEN;
#endif
	debug("Reserving %zu Bytes for Heap at: %08lx\n", TOTAL_MALLOC_LEN, gd->heap_addr);

#ifdef CONFIG_NONCACHE_ALLOCATION
	// 1MB alignment
	gd->noncache_addr = UBOOT_NONCACHE_MEMORY_ADDR;
	debug("Reserving %zu Bytes for Non-cache allocation at: %08lx\n", CONFIG_SYS_NON_CACHE_LEN, gd->noncache_addr);
#endif

#if !(defined(CONFIG_SYS_ICACHE_OFF) && defined(CONFIG_SYS_DCACHE_OFF))
	/* round down to next 64 kB limit */
	addr &= ~(0x10000 - 1);
	addr += 0x10000;

	// check bootcode overlap
	if (addr + 0x4000 > LINUX_KERNEL_ADDR) // TLB needs 16 KB
	{
		printf("[WARNING] TLB was overlaped with kernel. (addr: 0x%08x)\n", addr);
	}

    gd->tlb_addr = addr;
    debug("TLB table at: %08lx\n", gd->tlb_addr);
#endif

	gd->bd->bi_baudrate = gd->baudrate;
    /* Ram ist board specific, so move it to board code ... */
    dram_init_banksize();
    display_dram_config();  /* and display it */

	relocate_code(_stack_start, (gd_t *)gd, _TEXT_BASE);
#else	// !CONFIG_NO_RELOCATION
#if defined(CONFIG_SYS_MEM_TOP_HIDE)
	/*
	 * Subtract specified amount of memory to hide so that it won't
	 * get "touched" at all by U-Boot. By fixing up gd->ram_size
	 * the Linux kernel should now get passed the now "corrected"
	 * memory size and won't touch it either. This should work
	 * for arch/ppc and arch/powerpc. Only Linux board ports in
	 * arch/powerpc with bootwrapper support, that recalculate the
	 * memory size from the SDRAM controller setup will have to
	 * get fixed.
	 */
	gd->ram_size -= CONFIG_SYS_MEM_TOP_HIDE;
#endif

	addr = CONFIG_SYS_SDRAM_BASE + gd->ram_size;

#ifdef CONFIG_LOGBUFFER
#ifndef CONFIG_ALT_LB_ADDR
	/* reserve kernel log buffer */
	addr -= (LOGBUFF_RESERVE);
	debug("Reserving %dk for kernel logbuffer at %08lx\n", LOGBUFF_LEN,
		addr);
#endif
#endif

#ifdef CONFIG_PRAM
	/*
	 * reserve protected RAM
	 */
	reg = getenv_ulong("pram", 10, CONFIG_PRAM);
	addr -= (reg << 10);		/* size is in kB */
	debug("Reserving %ldk for protected RAM at %08lx\n", reg, addr);
#endif /* CONFIG_PRAM */

#if !(defined(CONFIG_SYS_ICACHE_OFF) && defined(CONFIG_SYS_DCACHE_OFF))
	/* reserve TLB table */
	addr -= (4096 * 4);

	/* round down to next 64 kB limit */
	addr &= ~(0x10000 - 1);

	gd->tlb_addr = addr;
	debug("TLB table at: %08lx\n", gd->tlb_addr);
#endif

	/* round down to next 4 kB limit */
	addr &= ~(4096 - 1);
	debug("Top of RAM usable for U-Boot at: %08lx\n", addr);

#ifdef CONFIG_LCD
#ifdef CONFIG_FB_ADDR
	gd->fb_base = CONFIG_FB_ADDR;
#else
	/* reserve memory for LCD display (always full pages) */
	addr = lcd_setmem(addr);
	gd->fb_base = addr;
#endif /* CONFIG_FB_ADDR */
#endif /* CONFIG_LCD */

	/*
	 * reserve memory for U-Boot code, data & bss
	 * round down to next 4 kB limit
	 */
	addr -= gd->mon_len;
	addr &= ~(4096 - 1);

	debug("Reserving %ldk for U-Boot at: %08lx\n", gd->mon_len >> 10, addr);

#ifndef CONFIG_SPL_BUILD
	/*
	 * reserve memory for malloc() arena
	 */
	addr_sp = addr - TOTAL_MALLOC_LEN;
	debug("Reserving %dk for malloc() at: %08lx\n",
			TOTAL_MALLOC_LEN >> 10, addr_sp);
	/*
	 * (permanently) allocate a Board Info struct
	 * and a permanent copy of the "global" data
	 */
	addr_sp -= sizeof (bd_t);
	bd = (bd_t *) addr_sp;
	gd->bd = bd;
	debug("Reserving %zu Bytes for Board Info at: %08lx\n",
			sizeof (bd_t), addr_sp);

#ifdef CONFIG_MACH_TYPE
	gd->bd->bi_arch_number = CONFIG_MACH_TYPE; /* board id for Linux */
#endif

	addr_sp -= sizeof (gd_t);
	id = (gd_t *) addr_sp;
	debug("Reserving %zu Bytes for Global Data at: %08lx\n",
			sizeof (gd_t), addr_sp);

	/* setup stackpointer for exeptions */
	gd->irq_sp = addr_sp;
#ifdef CONFIG_USE_IRQ
	addr_sp -= (CONFIG_STACKSIZE_IRQ+CONFIG_STACKSIZE_FIQ);
	debug("Reserving %zu Bytes for IRQ stack at: %08lx\n",
		CONFIG_STACKSIZE_IRQ+CONFIG_STACKSIZE_FIQ, addr_sp);
#endif
	/* leave 3 words for abort-stack    */
	addr_sp -= 12;

	/* 8-byte alignment for ABI compliance */
	addr_sp &= ~0x07;
#else
	addr_sp += 128;	/* leave 32 words for abort-stack   */
	gd->irq_sp = addr_sp;
#endif

	debug("New Stack Pointer is: %08lx\n", addr_sp);

#ifdef CONFIG_POST
	post_bootmode_init();
	post_run(NULL, POST_ROM | post_bootmode_get(0));
#endif

	gd->bd->bi_baudrate = gd->baudrate;
	/* Ram ist board specific, so move it to board code ... */
	dram_init_banksize();
	display_dram_config();	/* and display it */

	gd->relocaddr = addr;
	gd->start_addr_sp = addr_sp;
	gd->reloc_off = addr - _TEXT_BASE;
	debug("relocation Offset is: %08lx\n", gd->reloc_off);
	memcpy(id, (void *)gd, sizeof(gd_t));

	relocate_code(addr_sp, id, addr);

	/* NOTREACHED - relocate_code() does not return */
#endif	//CONFIG_NO_RELOCATION
}

BOOT_FLASH_T boot_flash_type;


#if !defined(CONFIG_SYS_NO_FLASH)
static char *failed = "*** failed ***\n";
#endif

extern int rtl8168_initialize(bd_t *bis);



/*
 ************************************************************************
 *
 * This is the next part if the initialization sequence: we are now
 * running from RAM and have a "normal" C environment, i. e. global
 * data can be written, BSS has been cleared, the stack size in not
 * that critical any more, etc.
 *
 ************************************************************************
 */

void board_init_r(gd_t *id, ulong dest_addr)
{
	ulong malloc_start;
#if !defined(CONFIG_SYS_NO_FLASH)
	ulong flash_size;
#endif

#ifdef CONFIG_REALTEK_WATCHDOG
	WATCHDOG_KICK();
	puts("Watchdog: Enabled\n");
#else
	puts("Watchdog: Disabled\n");
#endif

	gd = id;

	gd->flags |= GD_FLG_RELOC;	/* tell others: relocation done */
	bootstage_mark_name(BOOTSTAGE_ID_START_UBOOT_R, "board_init_r");

	monitor_flash_len = _end_ofs;

	/* Enable caches */
	enable_caches();

	debug("monitor flash len: %08lX\n", monitor_flash_len);
	board_init();	/* Setup chipselects */

	/*
	 * TODO: printing of the clock inforamtion of the board is now
	 * implemented as part of bdinfo command. Currently only support for
	 * davinci SOC's is added. Remove this check once all the board
	 * implement this.
	 */
#ifdef CONFIG_CLOCKS
	set_cpu_clk_info(); /* Setup clock information */
#endif
#ifdef CONFIG_SERIAL_MULTI
	serial_initialize();
#endif

#ifdef CONFIG_NO_RELOCATION
	debug("Now running in RAM - U-Boot at: %08lx\n", _TEXT_BASE);
#else
	debug("Now running in RAM - U-Boot at: %08lx\n", dest_addr);
#endif

#ifdef CONFIG_LOGBUFFER
	logbuff_init_ptrs();
#endif
#ifdef CONFIG_POST
	post_output_backlog();
#endif

	/* The Malloc area is immediately below the monitor copy in DRAM */
#ifdef CONFIG_NO_RELOCATION
	malloc_start = gd->heap_addr;
	mem_malloc_init (malloc_start, TOTAL_MALLOC_LEN);
#else
	malloc_start = dest_addr - TOTAL_MALLOC_LEN;
	mem_malloc_init (malloc_start, TOTAL_MALLOC_LEN);
#endif

#ifdef CONFIG_NONCACHE_ALLOCATION
    mem_malloc_noncache_init(gd->noncache_addr, CONFIG_SYS_NON_CACHE_LEN);
#endif

/*
 *********************************************************
 * Realtek Patch:
 *	Copy several mips codes from .data section
 *	to specific ddr region for A/V CPU use.
 *********************************************************
 */
#ifdef CONFIG_BSP_REALTEK
{
	unsigned char *a,*b;
	boot_av_info_t *boot_av;

	extern uint *uart_reg_base_ptr;
	extern uint *boot_av_info_ptr;
	extern uint *AudioFlag_ptr;
	//extern uint *VideoFlag_ptr_V1;
	//extern uint *VideoFlag_ptr_V2;
	extern uint *AudioFW_entry_ptr;
	//extern uint *VideoFW_entry_ptr_V1;
	//extern uint *VideoFW_entry_ptr_V2;
#if !defined(CONFIG_POWER_SAVING_MD) && !defined(CONFIG_POWER_DOWN_MD)
	// copy .exc_redirect (MIPS exception redirect)
	a = (unsigned char *)&_e_exc_redirect_img;
	b = (unsigned char *)&_f_exc_redirect_img;
	md_memcpy((unsigned char *)MIPS_EXC_REDIRECT_CODE_ADDR, b, a-b);

	// copy .exc_dispatch (MIPS exception dispatch)
	a = (unsigned char *)&_e_exc_dispatch_img;
	b = (unsigned char *)&_f_exc_dispatch_img;
	md_memcpy((unsigned char *)MIPS_EXC_DISPATCH_CODE_ADDR, b, a-b);

	// copy .isrvideoimg (video cpu isr handler)
	a = (unsigned char *)&_e_isrvideo_img;
	b = (unsigned char *)&_f_isrvideo_img;
	md_memcpy((unsigned char *)MIPS_ISR_VIDEO_IMG_ADDR, b, a-b);

	// copy .rosbootvectorimg (MIPS vector interrupt)
	a = (unsigned char *)&_e_rosbootvector_img;
	b = (unsigned char *)&_f_rosbootvector_img;
	md_memcpy((unsigned char *)MIPS_ROS_BOOT_VECTOR_IMG_ADDR, b, a-b);

	// copy .a_entry (ACPU bootcode)
	a = (unsigned char *)&_e_a_entry_img;
	b = (unsigned char *)&_f_a_entry_img;
	md_memcpy((unsigned char *)MIPS_A_ENTRY_CODE_ADDR, b, a-b);
#endif
	// fill the ACPU jump address.
	// After ACPU got HW semaphore in rom code, it will check this register.
	rtd_outl(ACPU_JUMP_ADDR_reg,SWAPEND32( MIPS_A_ENTRY_CODE_ADDR | MIPS_KSEG1BASE));
	rtd_outl(RESERVED_USE_3,MIPS_A_ENTRY_CODE_ADDR | MIPS_KSEG1BASE);
	
	// fill the UART register base address for A/V CPU.
	*uart_reg_base_ptr = SWAPEND32(CONFIG_SYS_NS16550_COM1 | 0xb0000000);

	*boot_av_info_ptr = 0;
	*AudioFlag_ptr = 0;	
	*AudioFW_entry_ptr = 0;

	/* clear boot_av_info memory */
	boot_av = (boot_av_info_t *) MIPS_BOOT_AV_INFO_ADDR;
	memset(boot_av, 0, sizeof(boot_av_info_t));


}
#endif	/* CONFIG_BSP_REALTEK */

#ifdef CONFIG_ARCH_EARLY_INIT_R
	arch_early_init_r();
#endif

#if !defined(CONFIG_SYS_NO_FLASH)
	puts("Flash: ");

	flash_size = flash_init();
	if (flash_size > 0) {
# ifdef CONFIG_SYS_FLASH_CHECKSUM
		char *s = getenv("flashchecksum");

		print_size(flash_size, "");
		/*
		 * Compute and print flash CRC if flashchecksum is set to 'y'
		 *
		 * NOTE: Maybe we should add some WATCHDOG_RESET()? XXX
		 */
		if (s && (*s == 'y')) {
			printf("  CRC: %08X", crc32(0,
				(const unsigned char *) CONFIG_SYS_FLASH_BASE,
				flash_size));
		}
		putc('\n');
# else	/* !CONFIG_SYS_FLASH_CHECKSUM */
		print_size(flash_size, "\n");
# endif /* CONFIG_SYS_FLASH_CHECKSUM */
	} else {
		puts(failed);
		hang();
	}
#endif

#if defined(CONFIG_RTKSPI) && defined(CONFIG_CMD_RTKSPI)
	rtkspi_init();		/* SPI initial */
#endif

#if defined(CONFIG_CMD_NAND)
	puts("NAND:  ");
	nand_init();		/* go init the NAND */
#endif

#if defined(CONFIG_CMD_ONENAND)
	onenand_init();
#endif
#ifndef CONFIG_POWER_SAVING_eMMC
#ifdef CONFIG_GENERIC_MMC
	puts("MMC:   ");
	mmc_initialize(gd->bd);

	EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

	if(bringup_mmc_driver() < 0) {
		printf("[ERR] bringup mmc failed.\n");
	}
#endif
#endif
	EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

#ifdef CONFIG_BSP_REALTEK
        pcb_get_boot_flash_type();   	
#ifdef CONFIG_SYS_FACTORY
	puts("Factory: ");
	factory_init();
	get_bootparam();
#if 0	
	get_layout();
#endif

	EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

#ifdef CONFIG_SYS_FACTORY_READ_ONLY
	puts("Factory RO: ");
	factory_ro_init();
#endif
#endif
#endif /* CONFIG_BSP_REALTEK */

#ifdef CONFIG_HAS_DATAFLASH
	AT91F_DataflashInit();
	dataflash_print_info();
#endif

	/* initialize environment */
	env_relocate();

	EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here

#if defined(CONFIG_SYS_PANEL_SUPPORT)
	/* panel parameters setting */
	panel_init();
#endif

	EXECUTE_CUSTOMIZE_FUNC(0); // insert execute customer callback at here
#if defined(CONFIG_SYS_IR_SUPPORT)
        IR_init();
#endif

#if defined(CONFIG_SYS_AUTO_DETECT)
	sink_capability_handler(1);
#endif	

#ifdef CONFIG_SYS_LOGO_DISP
	puts("Logo: ");
	LOGO_DISP_init(); // after panel init
#endif

#if defined(CONFIG_CMD_PCI) || defined(CONFIG_PCI)
	arm_pci_init();
#endif

	stdio_init();	/* get the devices list going. */

	jumptable_init();

#if defined(CONFIG_API)
	/* Initialize API */
	api_init();
#endif

	console_init_r();	/* fully init console as a device */

#if defined(CONFIG_ARCH_MISC_INIT)
	/* miscellaneous arch dependent initialisations */
	arch_misc_init();
#endif
#if defined(CONFIG_MISC_INIT_R)
	/* miscellaneous platform dependent initialisations */
	misc_init_r();
#endif

	 /* set up exceptions */
	interrupt_init();
	/* enable exceptions */
	enable_interrupts();

	/* Perform network card initialisation if necessary */
#if defined(CONFIG_DRIVER_SMC91111) || defined (CONFIG_DRIVER_LAN91C96)
	/* XXX: this needs to be moved to board init */
	if (getenv("ethaddr")) {
		uchar enetaddr[6];
		eth_getenv_enetaddr("ethaddr", enetaddr);
		smc_set_mac_addr(enetaddr);
	}
#endif /* CONFIG_DRIVER_SMC91111 || CONFIG_DRIVER_LAN91C96 */

	/* Initialize from environment */
	load_addr = getenv_ulong("loadaddr", 16, load_addr);

#ifdef CONFIG_BOARD_LATE_INIT
	board_late_init();
#endif

#ifdef CONFIG_BITBANGMII
	bb_miiphy_init();
#endif
#ifndef CONFIG_POWER_SAVING_ETN
#if defined(CONFIG_CMD_NET)
	puts("Net:   ");
#ifdef CONFIG_BSP_REALTEK
	//rtl8168_initialize(gd->bd);
#else
	eth_initialize(gd->bd);
#endif
#if defined(CONFIG_RESET_PHY_R)
	debug("Reset Ethernet PHY\n");
	reset_phy();
#endif
#endif //CONFIG_CMD_NET
#endif //CONFIG_POWER_SAVING_ETN
#ifdef CONFIG_POST
	post_run(NULL, POST_RAM | post_bootmode_get(0));
#endif

#if defined(CONFIG_PRAM) || defined(CONFIG_LOGBUFFER)
	/*
	 * Export available size of memory for Linux,
	 * taking into account the protected RAM at top of memory
	 */
	{
		ulong pram = 0;
		uchar memsz[32];

#ifdef CONFIG_PRAM
		pram = getenv_ulong("pram", 10, CONFIG_PRAM);
#endif
#ifdef CONFIG_LOGBUFFER
#ifndef CONFIG_ALT_LB_ADDR
		/* Also take the logbuffer into account (pram is in kB) */
		pram += (LOGBUFF_LEN + LOGBUFF_OVERHEAD) / 1024;
#endif
#endif
		sprintf((char *)memsz, "%ldk", (gd->ram_size / 1024) - pram);
		setenv("mem", (char *)memsz);
	}
#endif

      WATCHDOG_KICK();
	/* main_loop() can return to retry autoboot, if so just run it again. */
	for (;;) {
		main_loop();
	}

	/* NOTREACHED - no way out of command loop except booting */
}

void hang(void)
{
	puts("### ERROR ### Please RESET the board ###\n");
	for (;;);
}
