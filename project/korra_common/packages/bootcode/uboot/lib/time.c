/*
 * (C) Copyright 2000-2009
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
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
#include <watchdog.h>

#ifndef CONFIG_WD_PERIOD
# define CONFIG_WD_PERIOD	(10 * 1000 * 1000)	/* 10 seconds default*/
#endif

/* ------------------------------------------------------------------------- */
#ifdef CONFIG_DISPLAY_TIME_EVALUATION
ulong evaluate_startValue = 0;
ulong evaluate_lastValue = 0;
#endif

/* ------------------------------------------------------------------------- */

void udelay(unsigned long usec)
{
	ulong kv;

	do {
		WATCHDOG_RESET();
		kv = usec > CONFIG_WD_PERIOD ? CONFIG_WD_PERIOD : usec;
		__udelay (kv);
		usec -= kv;
	} while(usec);
}

void mdelay(unsigned long msec)
{
	while (msec--)
		udelay(1000);
}

#if 0 // temp mark for CK test only
int enable_armv7_count(void)
{
	unsigned int value = 0;

	value |= (1 << 0); // enable PMNC all counters
	value |= (1 << 1); // reset all counters to zero
	value |= (1 << 2); // reset cycle counter to zero
	value |= (1 << 3); // enable "by 64" divider for CCNT
	value |= (1 << 4); // export to ETM

	/* disable cycle counter overflow interrupts */
	asm volatile ("mcr p15, 0, %0, C9, C14, 2" :: "r"(0x80000001));

	/* program the performance-counter control-register */
	asm volatile ("mcr p15, 0, %0, c9, c12, 0" :: "r"(value));

	/* enable cycle counter */
	asm volatile ("mcr p15, 0, %0, c9, c12, 1" :: "r"(0x80000001));

	/* clear cycle counter overflow */
	asm volatile ("mcr p15, 0, %0, c9, c12, 3" :: "r"(0x80000001));

	printf("<<< enable armv7 count >>>\n");

	return 1;
}

int disable_armv7_count(void)
{
	unsigned int value;

	// get the performance-counter control-register:
	asm volatile ("mrc p15, 0, %0, c9, c12, 0" : "=r"(value));

	value &= ~(1 << 0); // disable PMNC all counters

	// program the performance-counter control-register:
	asm volatile ("mcr p15, 0, %0, c9, c12, 0" :: "r"(value));

	printf("<<< disable armv7 count >>>\n");

	return 1;
}

uint get_armv7_count(void)
{
	uint cur_value = 0;

	// Read CCNT Register
	asm volatile ("mrc p15, 0, %0, c9, c13, 0": "=r"(cur_value));

	printf("[%d] cur_value = 0x%08x\n", cur_value);
}
#endif

void reset_evaluate_time(char *str)
{
#ifdef CONFIG_DISPLAY_TIME_EVALUATION

	evaluate_startValue = 0;
	evaluate_lastValue = 0;

	printf("[%10u][%10u ms][reset time]  %s\n",
		evaluate_startValue, evaluate_lastValue, str);

#else

	return; // do nothing

#endif
}

void display_evaluate_time(char *str)
{
#ifdef CONFIG_DISPLAY_TIME_EVALUATION
	ulong evaluate_currValue = 0;

	evaluate_currValue = get_timer_masked();

	if (evaluate_startValue == 0)
		evaluate_startValue = evaluate_currValue;

	printf("[%8u][%4u ms]  %s\n",
		(evaluate_currValue - evaluate_startValue),
		(evaluate_currValue - evaluate_lastValue),
		str);

	evaluate_lastValue = evaluate_currValue;

#else

	return; // do nothing

#endif
}

#ifdef CONFIG_CUSTOMIZE_FUNC_REGISTER

#define MAX_CUSTOMIZE_TYPE_COUNT 2
#define MAX_CUSTOMIZE_FUNC_COUNT 2

typedef enum {
	CUSTOMIZE_FUNC_PERIODIC = 0,
	CUSTOMIZE_FUNC_BEFORE_ENTER_KERNEL = 1,
} customize_func_type_t;

typedef void (*customize_func_callback_t)(void);

static customize_func_callback_t customize_func_list[MAX_CUSTOMIZE_TYPE_COUNT][MAX_CUSTOMIZE_FUNC_COUNT] = {NULL};
static int customize_func_count[MAX_CUSTOMIZE_TYPE_COUNT] = {0};

int init_customize_func(void)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < MAX_CUSTOMIZE_TYPE_COUNT;i++)
	{
		for (j = 0;j < MAX_CUSTOMIZE_FUNC_COUNT;j++)
		{
			customize_func_list[i][j] = NULL;
		}

		customize_func_count[i] = 0;
	}

	return 0;
}

int register_customize_func(int type, customize_func_callback_t callback, char *info)
{
	if (callback == NULL)
	{
		printf("[ERR]%s: register callback function is null.\n", __FUNCTION__);
		return 1;
	}

	if (customize_func_count[type] >= MAX_CUSTOMIZE_FUNC_COUNT)
	{
		printf("[ERR]%s: register too many customize functions.\n", __FUNCTION__);
		printf("[ERR]%s: type=0x%08x callback=0x%08x\n", type, callback);
		return 1;
	}

	printf("%s: [%d]:0x%08x (%s)\n", __FUNCTION__, customize_func_count[type], callback, info);

	customize_func_list[type][customize_func_count[type]] = callback;
	customize_func_count[type]++;

	return 0;
}

void execute_customize_func(int type)
{
	int i = 0;

	for (i = 0;i < MAX_CUSTOMIZE_FUNC_COUNT;i++)
	{
		if (customize_func_list[type][i] != NULL)
		{
			customize_func_list[type][i]();
		}
	}
}
#endif

