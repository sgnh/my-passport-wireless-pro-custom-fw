/************************************************************************
 *
 *  logo_disp_1080p60.c
 *
 *  Belong to logo_disp module
 *
 *  This file implements logo display function in 1080p60 mode
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
static void LOGO_DISP_1080p60(t_extern_param *logo, int bond_opt);

#if defined(CONFIG_SYS_LOGO_DISP_1080P60)

void  LOGO_DISP_setup(t_extern_param *logo_param_ptr)
{
	int bonding = 0;
//	bonding = (*(volatile unsigned int *)ISO_CHIP_INFO1) & M_BONDING;
	printf("1080p 60Hz logo\n");
	LOGO_DISP_1080p60(logo_param_ptr, bonding);
}

static void LOGO_DISP_1080p60(t_extern_param *logo, int bond_opt)
{
	printf("[FIXME] bypass %s\n", __FUNCTION__);
	return 0;

	// Mixer_ctrl1_reg : enable sub_t
	*(volatile unsigned int *)0xb802b000 = 0x41 ;
	// GDMA_SUB1_ctrl_reg : enable sub1
    *(volatile unsigned int *)0xb802f008 = 0xf ;

    // GDMA_SUB1_PXDT_reg  GDMA_SUB1_PXDB_reg : top and bottom address
    *(volatile unsigned int *)0xb802f028 = 0x7FFFFFFF & sys_logo_start;
    *(volatile unsigned int *)0xb802f02c = 0x7FFFFFFF & (sys_logo_start + logo->logo_offset);
    // GDMA_SUB1_CLUT_reg : color lookup table address  ** 8 bytes aligned **
    *(volatile unsigned int *)0xb802f024 = 0x7FFFFFFF & LOGO_CLUT_ADDR;
    // GDMA_SUB1_reg : used for HDDVD subpicture
    *(volatile unsigned int *)0xb802f00c = 0x400001 ;
    // GDMA_SUB1_SUBP_reg : sub1 width 1920
    *(volatile unsigned int *)0xb802f010 = 0x780 ;
    // GDMA_SUB1_SIZE_reg : canvas width 1920 and height 1080
    *(volatile unsigned int *)0xb802f014 = 0x07800438 ;

	// GDMA_SUB1_VSI_reg : sub1 vertical scaling -- init offset & phase
	*(volatile unsigned int *)0xb802f05c = 0x0 ;
	// GDMA_SUB1_VSD_OUT_reg : sub1 vertical scaling -- output size
    //*(volatile unsigned int *)0xb802f060 = 0x438 ;
    *(volatile unsigned int *)0xb802f060 = (&default_panel_parameter)->iCONFIG_DISP_ACT_END_VPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_VPOS;
    // GDMA_SUB1_VSD_reg : sub1 vertical scaling -- delta phase
    //*(volatile unsigned int *)0xb802f064 = 0x4000 ;
    *(volatile unsigned int *)0xb802f064 = (0x438<<14)/((&default_panel_parameter)->iCONFIG_DISP_ACT_END_VPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_VPOS) ;
    // GDMA_SUB1_VSYC_reg : sub1 vertical scaling -- FIR coefficient
    *(volatile unsigned int *)0xb802f068 = 0x02e80203 ;
    *(volatile unsigned int *)0xb802f06c = 0x06d604a5 ;
    *(volatile unsigned int *)0xb802f070 = 0x0b5b092a ;
    *(volatile unsigned int *)0xb802f074 = 0x0dfd0d18 ;

	// GDMA_SUB1_HSI_reg : sub1 hotizontal scaling -- init offset & phase
    *(volatile unsigned int *)0xb802f078 = 0x0 ;
    // GDMA_SUB1_HSD_OUT_reg : sub1 hotizontal scaling -- output size
    *(volatile unsigned int *)0xb802f07c = (&default_panel_parameter)->iCONFIG_DISP_ACT_END_HPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_HPOS ;
    // GDMA_SUB1_HSD_reg : sub1 hotizontal scaling -- delta phas
    //*(volatile unsigned int *)0xb802f080 = 0x4000 ;
    *(volatile unsigned int *)0xb802f080 = (0x780<<14)/((&default_panel_parameter)->iCONFIG_DISP_ACT_END_HPOS - (&default_panel_parameter)->iCONFIG_DISP_ACT_STA_HPOS) ; ;
    // GDMA_SUB1_HSYC_reg : sub1 hotizontal scaling -- FIR coefficient
    *(volatile unsigned int *)0xb802f084 = 0x3e9c3e62 ;
    *(volatile unsigned int *)0xb802f088 = 0x3e523e7e ;
    *(volatile unsigned int *)0xb802f08c = 0x3ef23fb0 ;
    *(volatile unsigned int *)0xb802f090 = 0x00b401f2 ;
    *(volatile unsigned int *)0xb802f094 = 0x03670516 ;
    *(volatile unsigned int *)0xb802f098 = 0x06d9088b ;
    *(volatile unsigned int *)0xb802f09c = 0x0a050b25 ;
    *(volatile unsigned int *)0xb802f0a0 = 0x0bd40c0b ;

    // GDMA_ctrl_reg : sub1 prog done
    *(volatile unsigned int *)0xb802f004 = 0x3 ;
}

#endif

