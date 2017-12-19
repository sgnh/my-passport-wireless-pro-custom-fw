#ifndef __POWER_H__
#define __POWER_H__

#include <config.h>


#if defined(CONFIG_BOARD_QA_RTD1195)
	#include "power/power_rtd1195_qa.h"
#elif defined(CONFIG_BOARD_QA_RTD1195_WIFI_STORAGE)
	#include "power/power_rtd1195_wifi_storage.h"	
#elif defined(CONFIG_BOARD_DEMO_RTD1195_MUSTANG)
	#include "power/power_rtd1195_mustang.h"	
#elif defined(CONFIG_BOARD_DEMO_RTD1195_HORSERADISH)
	#include "power/power_rtd1195_horseradish.h"	
#elif defined(CONFIG_BOARD_FPGA_RTD1195_EMMC)
	#include "power/power_rtd1195_qa.h"
#else
	#error "power-saving does not support this board."
#endif



#endif	// __POWER_H__

