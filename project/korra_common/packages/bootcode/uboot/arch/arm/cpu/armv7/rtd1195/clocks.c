/*
 * This file is subject to the terms and conditions of the GNU General Public
 * License.  See the file "COPYING" in the main directory of this archive
 * for more details.
 *
 * Copyright (C) 2012 by Chuck Chen <ycchen@realtek.com>
 *
 * Time initialization.
 */

#include <common.h>
#include <asm/utils.h>
#include <asm/arch/system.h>
#include <asm/arch/rbus/iso_reg.h>

/*
 * clock enable api
 */
void enable_clock(uint reg_reset, uint mask_reset, uint reg_clock, uint mask_clock)
{
	// clk = 0
	rtd_outl(reg_clock, rtd_inl(reg_clock) & (~mask_clock));

	// rst = 0
	rtd_outl(reg_reset, rtd_inl(reg_reset) & (~mask_reset));

	// wait
	udelay(10);

	// rst = 1
	rtd_outl(reg_reset, rtd_inl(reg_reset) | mask_reset);

	// wait
	udelay(10);

	// clk = 1
	rtd_outl(reg_clock, rtd_inl(reg_clock) | mask_clock);

}

static int rtc_init(void)
{
#if 0 // (wilma+ 2013/06/29)	
	uint rtcstop_regValue;

	rtcstop_regValue = rtd_inl(RTCSTOP_reg);

	// check RTC status
	if (RTCSTOP_get_RTCSTOP(rtcstop_regValue) == 0x0) // status: running
	{
		;	// RTC: Already running ... do nothing ...
	}
	else // status: stopped
	{
		// initialize RTC
		rtd_outl(RTCACR_reg, RTCACR_BC(0x0) | RTCACR_CLKSEL(0x0)); // clk select

		// reset time info
		rtd_outl(RTCSEC_reg, RTCSEC_RTCSEC(0x0)); // sec
		rtd_outl(RTCMIN_reg, RTCMIN_RTCMIN(0x0)); // min
		rtd_outl(RTCHR_reg, RTCHR_RTCHR(0x0)); // hour
		rtd_outl(RTCDATE1_reg, RTCDATE1_RTCDATE1(0x0)); // date LSB
		rtd_outl(RTCDATE2_reg, RTCDATE2_RTCDATE2(0x0)); // date MSB

		// enable RTC
		rtd_outl(RTCEN_reg, RTCEN_RTCEN(0x5A));

		// check RTC status
		rtcstop_regValue = rtd_inl(RTCSTOP_reg);
		if (RTCSTOP_get_RTCSTOP(rtcstop_regValue) == 0x0)
		{
			;	// RTC: Running
		}
		else
		{
			;	// RTC: Stop
		}
	}
#endif
	return 0;
}

/*
 * Enable essential clock domains, modules and
 * do some additional special settings needed
 */
int clock_init(void)
{

    /* enable 90KHz counter */
	rtd_setbits(0x1801b538,_BIT0);

	return 0;
}
