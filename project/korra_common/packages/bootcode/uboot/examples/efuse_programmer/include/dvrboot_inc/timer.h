//=================================================================================================
// Copyright (c) 2009 Realtek Semiconductor Corp. All Rights Reserved.
//
// Filename: timer.h
// Abstract:
//   Related Definitions of Hardware Control for UART
//
// History:
//	 2009-01-20			cyyang			Initial Version
//=================================================================================================

#ifndef _TIMER_H_
#define _TIMER_H_

#include "sysdefs.h"
#include "dvrboot_inc/io.h"

#define TRUE	1
#define FALSE	0

//=================================================================================================

#define TIMERINFO_BASE_CLOCK				(27000000)	//T = 1/27M = 37ns
#define TIMERINFO_BASE_UNIT					37		// 37ns

#define TIMERINFO_SEC                                          1000000000/TIMERINFO_BASE_UNIT
#define TIMERINFO_MSEC                                         1000000/TIMERINFO_BASE_UNIT
#define TIMERINFO_USEC                                         1000/TIMERINFO_BASE_UNIT

//#define TIMERINFO_SEC						27000000
//#define TIMERINFO_MSEC						27000
//#define TIMERINFO_USEC						27

//=================================================================================================
//Related Register Information of Timer
#define TIMERINFO_INT_BASE_ADDRESS			0xB801B008
#define TIMERINFO_INT_TIMER0_BIT			7
#define TIMERINFO_INT_TIMER1_BIT			8
#define TIMERINFO_INT_TIMER2_BIT			9
#define TIMERINFO_INT_TIMER3_BIT			10
#define TIMERINFO_INT_TIMER4_BIT			11
#define TIMERINFO_INT_TIMER5_BIT			12
#define TIMERINFO_INT_TIMER6_BIT			13
#define TIMERINFO_INT_TIMER7_BIT			14
					
#define TIMERREG_BASE_ADDRESS				0xB801B600	//Base Address of Timer Register Set

#define TIMERREG_OFFSET_ADDRESS_TVR			0x00
#define TIMERREG_OFFSET_ADDRESS_CVR			0x20
#define TIMERREG_OFFSET_ADDRESS_CR			0x40
#define TIMERREG_OFFSET_ADDRESS_ICR			0x60

#define TIMERREG_REGISTER_NUMBER			0x4

#define TIMERREG_BASE_ADDRESS_TIMER0		TIMERREG_BASE_ADDRESS
#define TIMERREG_BASE_ADDRESS_TIMER1		TIMERREG_BASE_ADDRESS + 0x4 
#define TIMERREG_BASE_ADDRESS_TIMER2		TIMERREG_BASE_ADDRESS + 0x8 
#define TIMERREG_BASE_ADDRESS_TIMER3		TIMERREG_BASE_ADDRESS + 0xc
#define TIMERREG_BASE_ADDRESS_TIMER4		TIMERREG_BASE_ADDRESS + 0x10
#define TIMERREG_BASE_ADDRESS_TIMER5		TIMERREG_BASE_ADDRESS + 0x14 
#define TIMERREG_BASE_ADDRESS_TIMER6		TIMERREG_BASE_ADDRESS + 0x18 
#define TIMERREG_BASE_ADDRESS_TIMER7		TIMERREG_BASE_ADDRESS + 0x1c

#define PACI_PERI_TCWCR_VADDR                   (0xb801bb00)
#define PACI_PERI_TCWTR_VADDR                   (0xb801bb04)
#define PACI_PERI_TCWNMI_VADDR                  (0xb801bb08)
#define PACI_PERI_TCWOV_VADDR                   (0xb801bb0c)

//=================================================================================================
#define TIMERINFO_ID_TIMER0					0
#define TIMERINFO_ID_TIMER1					1
#define TIMERINFO_ID_TIMER2					2
#define TIMERINFO_ID_TIMER3					3
#define TIMERINFO_ID_TIMER4					4
#define TIMERINFO_ID_TIMER5					5
#define TIMERINFO_ID_TIMER6					6
#define TIMERINFO_ID_TIMER7					7

#define TIMERINFO_COUNTER_ENABLE			0x80000000
#define TIMERINFO_COUNTER_DISABLE			0x00000000

#define TIMERINFO_INTERRUPT_ENABLE			0x80000000
#define TIMERINFO_INTERRUPT_DISABLE			0x00000000

#define TIMERINFO_TIMER_ENABLE				0xC0000000
#define TIMERINFO_TIMER_DISABLE				0x00000000

#define TIMERINFO_INTERRUPT_PENDING			1

#define TIMERINFO_COUNT_NUMBER_MIN			0x00000001
#define TIMERINFO_COUNT_NUMBER_MAX			0xFFFFFFFF

//=================================================================================================
void	InitTimer(unsigned char byTimerId, unsigned int dwDivisionFactor);
void 	mdelay(unsigned int dwMiniSecond);
void 	udelay(unsigned int dwMicroSecond);
bool	SystemTimeout(unsigned char byTimerId);
//=================================================================================================

#endif

//=================================================================================================
// End of File
