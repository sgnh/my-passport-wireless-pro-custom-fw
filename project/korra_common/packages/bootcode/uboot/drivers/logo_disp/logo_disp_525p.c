/************************************************************************
 *
 *  logo_disp_525p.c
 *
 *  Belong to logo_disp module
 *
 *  This file implements logo display function in NTSC mode
 *
 ************************************************************************/

/************************************************************************
 *  Include files
 ************************************************************************/
#include <common.h>
#include <asm/arch/extern_param.h>
#include <asm/arch/panelConfigParameter.h>
#include <logo_disp/logo_disp_api.h>

extern struct _PANEL_CONFIG_PARAMETER  default_panel_parameter;

extern uint sys_logo_start;
extern uchar sys_logo_is_HDMI;

/************************************************************************
 *  Implementation : Private functions
 ************************************************************************/
static void LOGO_DISP_525p(t_extern_param *logo, int bond_opt);

#if defined(CONFIG_SYS_LOGO_DISP_NTSC)

void  LOGO_DISP_setup(t_extern_param *logo_param_ptr)
{
	int bonding = 0;
//	bonding = (*(volatile unsigned int *)ISO_CHIP_INFO1) & M_BONDING;
	printf("NTSC logo\n");
	LOGO_DISP_525p(logo_param_ptr, bonding);
}

static void LOGO_DISP_525p(t_extern_param *logo, int bond_opt)
{
#ifndef CONFIG_SYS_LOGO_DISP
	printf("[FIXME] bypass %s\n", __FUNCTION__);
	return 0;
#endif

	printf(" set GDMA SUB1\n");

	// Mixer_ctrl1_reg : enable sub_t
	*(volatile unsigned int *)0x1802b060 = 0x41 ;
	// GDMA_SUB1_ctrl_reg : enable sub1
	*(volatile unsigned int *)0x1802f020 = 0xf ;

	// GDMA_SUB1_PXDT_reg  GDMA_SUB1_PXDB_reg : top and bottom address
	*(volatile unsigned int *)0x1802f044 = 0x7FFFFFFF & sys_logo_start;
	*(volatile unsigned int *)0x1802f048 = 0x7FFFFFFF & (sys_logo_start + logo->logo_offset);
	// GDMA_SUB1_CLUT_reg : color lookup table address  ** 8 bytes aligned **
	*(volatile unsigned int *)0x1802f040 = 0x7FFFFFFF & LOGO_CLUT_ADDR;
	// GDMA_SUB1_reg : used for DVD subpicture
	*(volatile unsigned int *)0x1802f024 = 0x800001 ;
	// GDMA_SUB1_SUBP_reg : sub1 width 720
	*(volatile unsigned int *)0x1802f030 = 0x2d0 ;
	// GDMA_SUB1_SIZE_reg : canvas width 720 and height 480
	*(volatile unsigned int *)0x1802f034 = 0x02d001e0 ;

	// GDMA_SUB1_VSI_reg : sub1 vertical scaling -- init offset & phase
	*(volatile unsigned int *)0x1802f078 = 0x0 ;
	// GDMA_SUB1_VSD_OUT_reg : sub1 vertical scaling -- output size
	//*(volatile unsigned int *)0x1802f07c = 0x438 ;
	*(volatile unsigned int *)0x1802f07c = (&default_panel_parameter)->iCONFIG_DISP_ACT_END_VPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_VPOS;
	// GDMA_SUB1_VSD_reg : sub1 vertical scaling -- delta phase
	//*(volatile unsigned int *)0x1802f080 = 0x1c71 ;
	*(volatile unsigned int *)0x1802f080 = (0x1e0<<14)/((&default_panel_parameter)->iCONFIG_DISP_ACT_END_VPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_VPOS) ;
	// GDMA_SUB1_VSYC_reg : sub1 vertical scaling -- FIR coefficient
	*(volatile unsigned int *)0x1802f084 = 0x02e80203 ;
	*(volatile unsigned int *)0x1802f088 = 0x06d604a5 ;
	*(volatile unsigned int *)0x1802f08c = 0x0b5b092a ;
	*(volatile unsigned int *)0x1802f090 = 0x0dfd0d18 ;

	// GDMA_SUB1_HSI_reg : sub1 hotizontal scaling -- init offset & phase
	*(volatile unsigned int *)0x1802f094 = 0x0 ;
	// GDMA_SUB1_HSD_OUT_reg : sub1 hotizontal scaling -- output size
	*(volatile unsigned int *)0x1802f098 = (&default_panel_parameter)->iCONFIG_DISP_ACT_END_HPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_HPOS ;
	// GDMA_SUB1_HSD_reg : sub1 hotizontal scaling -- delta phas
	//*(volatile unsigned int *)0x1802f09c = 0x1800 ;
	*(volatile unsigned int *)0x1802f09c = (0x2d0<<14)/((&default_panel_parameter)->iCONFIG_DISP_ACT_END_HPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_HPOS) ; ;
	// GDMA_SUB1_HSYC_reg : sub1 hotizontal scaling -- FIR coefficient
	*(volatile unsigned int *)0x1802f0a0 = 0x3e9c3e62 ;
	*(volatile unsigned int *)0x1802f0a4 = 0x3e523e7e ;
	*(volatile unsigned int *)0x1802f0a8 = 0x3ef23fb0 ;
	*(volatile unsigned int *)0x1802f0ac = 0x00b401f2 ;
	*(volatile unsigned int *)0x1802f0b0 = 0x03670516 ;
	*(volatile unsigned int *)0x1802f0b4 = 0x06d9088b ;
	*(volatile unsigned int *)0x1802f0b8 = 0x0a050b25 ;
	*(volatile unsigned int *)0x1802f0bc = 0x0bd40c0b ;

	// GDMA_ctrl_reg : sub1 prog done
	*(volatile unsigned int *)0x1802f004 = 0x11 ;
}

#endif

