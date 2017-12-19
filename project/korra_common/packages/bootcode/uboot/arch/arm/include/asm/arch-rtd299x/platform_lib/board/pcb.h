#ifndef __PCB_H__
#define __PCB_H__

#include <platform_lib/board/pcb_mgr.h>

#if defined(CONFIG_BOARD_DEMO_RTD299X_EMMC)
	#include "pcb/pcb_rtd299x_demo.h"
#elif defined(CONFIG_BOARD_DEMO_VER_C_RTD299X_EMMC)
	#include "pcb/pcb_rtd299x_demo_ver_c.h"
#elif defined(CONFIG_BOARD_QA_RTD299X_EMMC)
	#include "pcb/pcb_rtd299x_qa.h"
#elif defined(CONFIG_BOARD_TV010_RTD2995_EMMC)
	#include "pcb/pcb_rtd2995_tv010_v1.h"
#elif defined(CONFIG_BOARD_TV010_RTD2995_EMMC_V2)
	#include "pcb/pcb_rtd2995_tv010_v2.h"    
#elif defined(CONFIG_BOARD_TV005_L4300_RTD2993_EMMC)
	#include "pcb/pcb_rtd2993_tv005_l4300.h"
#elif defined(CONFIG_BOARD_TV015_RTD2995_EMMC)
	#include "pcb/pcb_rtd2995_tv015.h"
#elif defined(CONFIG_BOARD_TV030_RTD2995_4DDR_2G_EMMC)
	#include "pcb/pcb_rtd2995_tv030.h"
#elif defined(CONFIG_BOARD_TV035_RTD2992_4DDR_1G_EMMC)
	#include "pcb/pcb_rtd2992_tv035.h"
#else
	#error "pcbMgr no support this board."
#endif

#endif	// __PCB_H__

