/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 */

#include <common.h>
#include <asm/armv7.h>
#include <asm/sizes.h>
#include <config.h>
#include <asm/errno.h>
#include <asm/io.h>

DECLARE_GLOBAL_DATA_PTR;

unsigned int cortex_rev(void)
{

    unsigned int rev;

    /* Read Main ID Register (MIDR) */
    asm ("mrc p15, 0, %0, c0, c0, 0" : "=r" (rev));

    return rev;
}

/*
 * Print CPU information
 */
int print_cpuinfo(void)
{  
    printf("CPU  : Cortex-A7 dual core\n");

    return 0;
}

#ifndef CONFIG_SYS_DCACHE_OFF
void enable_caches(void)
{
    /* Enable D-cache. I-cache is already enabled in start.S */
    dcache_enable();
}
#endif

#ifndef CONFIG_SYS_L2CACHE_OFF
void v7_outer_cache_enable(void)
{
	//set_pl310_ctrl_reg(1);
}

void v7_outer_cache_disable(void)
{
	//set_pl310_ctrl_reg(0);
}
#endif
