/*
 * (C) Copyright 2008
 * Texas Instruments
 *
 * Richard Woodruff <r-woodruff2@ti.com>
 * Syed Moahmmed Khasim <khasim@ti.com>
 *
 * (C) Copyright 2002
 * Sysgo Real-Time Solutions, GmbH <www.elinos.com>
 * Marius Groeger <mgroeger@sysgo.de>
 * Alex Zuepke <azu@sysgo.de>
 *
 * (C) Copyright 2002
 * Gary Jennejohn, DENX Software Engineering, <garyj@denx.de>
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

#include <common.h>
#include <asm/io.h>

DECLARE_GLOBAL_DATA_PTR;

struct timer_reg
{
	u32 tvr;
	u32 cvr;
	u32 cr;
	u32 icr;
	u8 isr_bit;
};

struct timer_reg rtk_timer[8][5] =
{
{0x1801b600, 0x1801b620, 0x1801b640, 0x1801b660, 6},
{0x1801b604, 0x1801b624, 0x1801b644, 0x1801b664, 7},
{0x1801b608, 0x1801b628, 0x1801b648, 0x1801b668, 8},
{0x1801b60c, 0x1801b62c, 0x1801b64c, 0x1801b66c, 9},
{0x1801b610, 0x1801b630, 0x1801b650, 0x1801b670, 10},
{0x1801b614, 0x1801b634, 0x1801b654, 0x1801b674, 11},
{0x1801b618, 0x1801b638, 0x1801b658, 0x1801b678, 12},
{0x1801b61c, 0x1801b63c, 0x1801b65c, 0x1801b67c, 13},
};

static struct timer_reg *timer_base = rtk_timer[CONFIG_SYS_TIMER];

/*
 * Nothing really to do with interrupts, just starts up a counter.
 */

//#define TIMER_CLOCK		27000000
#define TIMER_CLOCK		50000000	// for FPGA
#define TIMER_OVERFLOW_VAL	0xffffffff
#define TIMER_LOAD_VAL		0xffffffff

#define TIMERINFO_TIMER_ENABLE              0xC0000000
#define TIMERINFO_TIMER_DISABLE             0x00000000
#define TIMERINFO_INTERRUPT_ENABLE          0x80000000
#define TIMERINFO_INTERRUPT_DISABLE         0x00000000

int timer_init(void)
{
	//Disable Interrupt
    writel(TIMERINFO_INTERRUPT_DISABLE, timer_base->icr);

    //Disable Timer
    writel(TIMERINFO_TIMER_DISABLE, timer_base->cr);

    //Set The Initial Value
    writel(TIMER_LOAD_VAL, timer_base->tvr);

    //Enable Timer Mode
    writel(TIMERINFO_TIMER_ENABLE, timer_base->cr);

	return 0;
}

/*
 * timer without interrupts
 */
ulong get_timer(ulong base)
{
	return get_timer_masked() - base;
}

/* delay x useconds */
void __udelay(unsigned long usec)
{
	long tmo = usec * (TIMER_CLOCK / 1000) / 1000;
	unsigned long now, last = readl(timer_base->cvr);

	while (tmo > 0) {
		now = readl(timer_base->cvr);
		if (now < last) /* count up timer overflow */
			tmo -= TIMER_OVERFLOW_VAL - last + now + 1;
		else
			tmo -= now - last;
		last = now;
	}
}

ulong get_timer_masked(void)
{
	/* current tick value */
	ulong now = readl(timer_base->cvr) / (TIMER_CLOCK / CONFIG_SYS_HZ);

	if (now >= gd->lastinc)	/* normal mode (non roll) */
		/* move stamp fordward with absoulte diff ticks */
		gd->tbl += (now - gd->lastinc);
	else	/* we have rollover of incrementer */
		gd->tbl += ((TIMER_LOAD_VAL / (TIMER_CLOCK / CONFIG_SYS_HZ))
			     - gd->lastinc) + now;
	gd->lastinc = now;
	return gd->tbl;
}

/*
 * This function is derived from PowerPC code (read timebase as long long).
 * On ARM it just returns the timer value.
 */
unsigned long long get_ticks(void)
{
	return get_timer(0);
}

/*
 * This function is derived from PowerPC code (timebase clock frequency).
 * On ARM it returns the number of timer ticks per second.
 */
ulong get_tbclk(void)
{
	return CONFIG_SYS_HZ;
}
