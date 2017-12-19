//=================================================================================================
// Copyright (c) 2009 Realtek Semiconductor Corp. All Rights Reserved.
//
// Filename: timer.c
// Abstract:
//   Hardware IO Control Functions in Viking Timer
//
// History:
//	 2009-01-20			cyyang			Initial Version
//=================================================================================================

#ifndef _TIMER_H_
#include "dvrboot_inc/timer.h"
#endif


//=================================================================================================
// Name: InitTimer
// Description: Initial Register for Timer
// Input: 
//	- (UINT8) byTimerId: Timer ID
//
// Output: None
//=================================================================================================
void InitTimer(unsigned char byTimerId, unsigned int dwInit)
{
	//Disable Interrupt
    rtd_outl((TIMERREG_BASE_ADDRESS_TIMER0 + (byTimerId * TIMERREG_REGISTER_NUMBER) + TIMERREG_OFFSET_ADDRESS_ICR), TIMERINFO_INTERRUPT_DISABLE);

	//Disable Timer
	rtd_outl((TIMERREG_BASE_ADDRESS_TIMER0 + (byTimerId * TIMERREG_REGISTER_NUMBER) + TIMERREG_OFFSET_ADDRESS_CR), TIMERINFO_TIMER_DISABLE);

	//Set The Initial Value
	rtd_outl((TIMERREG_BASE_ADDRESS_TIMER0 + (byTimerId * TIMERREG_REGISTER_NUMBER) + TIMERREG_OFFSET_ADDRESS_TVR), dwInit);

	//Enable Timer Mode
	rtd_outl((TIMERREG_BASE_ADDRESS_TIMER0 + (byTimerId * TIMERREG_REGISTER_NUMBER) + TIMERREG_OFFSET_ADDRESS_CR), TIMERINFO_TIMER_ENABLE);

	// Clear Interrupt Pending (must after enable)
    rtd_outl(TIMERINFO_INT_BASE_ADDRESS, (1 << (byTimerId+TIMERINFO_INT_TIMER0_BIT)));
}

//=================================================================================================
// Name: SystemDelay
// Description: Delay Specific Time
// Input: 
//	- (UINT32) dwMicroSecond: Delay Time (Unit: 1 us)
//
// Output: None
//=================================================================================================
void mdelay(unsigned int dwMiniSecond)
{
#ifdef ENV_SIMULATION
	//Initial Timer 7
	InitTimer(TIMERINFO_ID_TIMER7, 1*TIMERINFO_MSEC);
#else
	//Initial Timer 7
	InitTimer(TIMERINFO_ID_TIMER7, dwMiniSecond*TIMERINFO_MSEC);
#endif
	//Wait for Interrupt Pending Status
	while(SystemTimeout(TIMERINFO_ID_TIMER7) == FALSE);
}
//=================================================================================================
void udelay(unsigned int dwMicroSecond)
{
#ifdef ENV_SIMULATION
	//Initial Timer 7
	InitTimer(TIMERINFO_ID_TIMER7, 1*TIMERINFO_USEC);
#else
	//Initial Timer 7
    InitTimer(TIMERINFO_ID_TIMER7, dwMicroSecond*TIMERINFO_USEC);
#endif
    //Wait for Interrupt Pending Status
    while(SystemTimeout(TIMERINFO_ID_TIMER7) == FALSE);	
}
//=================================================================================================
bool SystemTimeout(unsigned char byTimerId)
{
	bool	bIoStatus = FALSE;
	UINT32 	bitmask = 1 << (byTimerId+TIMERINFO_INT_TIMER0_BIT);

	if(rtd_inl(TIMERINFO_INT_BASE_ADDRESS) & bitmask)
	{
		bIoStatus = TRUE;
	}

	return bIoStatus;
}

//=================================================================================================
// End of File
