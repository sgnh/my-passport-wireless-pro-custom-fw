#include <common.h>
#include <asm/io.h>

#define BISR_CHECK_COUNT 3 //10

void BISR_SetDDomain(void)
{
#if 0
	// DISP_I use (three SRAM)
	rtd_outl(0xb8020000, 0x000001ff);  // ADC clock,SOG0,bandgap,RGB power
	rtd_outl(0xb8020104, 0x00000608); // enable APLL & dual clk
	rtd_outl(0xb8022210, 0x90000001); //001:ADC/YPbPr (incluing Pattern Generator),analog mode =>bit1 set 0
	rtd_outl(0xb8022284, 0x0000000C); //from vgip/ch1/frome DI

	// DISP_D use
	//rtd_outl(0xb8000534, 0x00002042); //DPLL display Reset to Normal
	rtd_outl(0xb8000534, 0x00002042); //DPLL display Reset to Normal,		

	rtd_outl(0xb8028000, 0x07530400); // Frame Sync mode, 24-bit RGB
	// display PLL
	rtd_outl(SYSTEM_SYS_PLL_DISP1_VADDR, 0x01801323);	//113Mhz
	rtd_outl(SYSTEM_SYS_PLL_DISP2_VADDR, 0x0000000d);
	rtd_outl(SYSTEM_SYS_PLL_DISP2_VADDR, 0x0000000f);
	rtd_outl(SYSTEM_SYS_PLL_DISP2_VADDR, 0x00000042);

	rtd_outl(0xb8000534, ((rtd_inl(0xb8000534))|0x20000));//To improve EPI jitter, add by alexchang 0427-2012 
	rtd_maskl(0xb8000534, ~(_BIT23|_BIT22), _BIT23); //modified by Dick. improve OSD jitter

#endif
}



void BISR_Repair(void)
{
#if 0
	int count = 0;
	unsigned int ret = 0;

	BISR_SetDDomain();
#if 1
	//imem_bisr - refer emcu spec
	rtd_maskl(0xb8060424, ~_BIT2, 0); //clear hold_remap
	//printf("imem_bisr - refer emcu spec\n");
	rtd_outl(0xb8060424, 0x00000000);  // run1
	rtd_outl(0xb8060424, 0x00000002);  // soft_rstn pull high
	rtd_outl(0xb8060424, 0x0000000a);  // pwr_rstn pull high 
	//--rtd_inl(0xb8060424, 0x0000001a);  // check bisr_done : bit 4 and bisr_fail bit 5
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8060424);
	}while(!(ret & _BIT4) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, imem_bisr bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT5)
		printf("imem_bisr _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8060424, ~_BIT2, _BIT2);  // set hold_remap = 1
	udelay(200);

	//rtd_outl(0xb8060424, 0x00000003);  // bisr_pwr_rst_n=0, run2
	//rtd_outl(0xb8060424, 0x0000000b);  // bisr_pwr_rst_n=1, run2
	//rtd_inl(0xb8060424, 0x0000001b);	// check bisr_done : bit 4 and bisr_fail bit 5
	//rtd_outl(0xb8060424, 0x0000001f);  // set hold_remap = 1

#endif

#if 1
	// rsds3 -- reger disp_if spec
	rtd_maskl(0xb802d018, ~_BIT3, 0); //clear hold_remap
	//printf("rsds3 -- reger disp_if spec\n");
	rtd_outl(0xb802d018, 0x00000000); // 
	rtd_outl(0xb802d018, 0x00000002); // soft rst_n pull high
	rtd_outl(0xb802d018, 0x00000006); // pwr rst_n pull high
	//--rtd_inl(0xb802d018, 0x00000026); // check bisr_done :bit 5	and bisr_repaired :bit 4
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb802d018);
	}while(!(ret & _BIT5) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, rsds3 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	//--rtd_inl(0xb802d01c, 0x00000000); // check bisr_fail_0:bit 29(0x20000000) bisr_fail_1:bit 28(0x10000000)
	ret = rtd_inl(0xb802d01c);
	if (ret & _BIT29)
		printf("rsds3 _BIT29 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT28)
		printf("rsds3 _BIT28 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb802d018, ~_BIT3, _BIT3); // set hold remap = 1
	udelay(200);
#endif

#if 1 //die die die!!! rtd_outl(0xb8000e00, 0x00001864); will ACPU/VCPU go5280 die
	rtd_maskl(0xb8000100, ~(_BIT3|_BIT1), 0); //halt ACPU/VCPU

#if 1
	// GPU1
	rtd_maskl(0xb8000e08, ~_BIT11, 0); //clear hold_remap
	//printf("GPU1\n");
	// RUN 1 BISR Enable
#if 0
	rtd_outl(0xb8000e04, 0x00001864);  // bisr_rst_n=1
	rtd_outl(0xb8000e00, 0x00001864);  // bisr_run1_rstn=1
#else
	rtd_maskl(0xb8000e04, ~_BIT11, _BIT11);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT11, _BIT11);  // bisr_run1_rstn=1
#endif
	// RUN 1 Read Status
	//--rtd_inl(0xb8000eb0, 0x00000001);  // bit 0: bisr_done bit 4-1 : bisr_fail	bit 17-16 :bisr_reparied   
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000eb0);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, GPU1 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("GPU1 _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("GPU1 _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("GPU1 _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT4)
		printf("GPU1 _BIT4 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT11, _BIT11);  // set hold remap : bit11
	udelay(200);
#endif

#if 1
		//	GPU2
	IoReg_Write32(0xb8000c04,0x80); //	set GPU group 2 BIST test mode

	// GPU2
	rtd_maskl(0xb8000e08, ~_BIT12, 0); //clear hold_remap
	//printf("GPU2\n");
	// RUN 1 BISR Enable
	rtd_maskl(0xb8000e04, ~_BIT12, _BIT12);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT12, _BIT12);  // bisr_run1_rstn=1
	// RUN 1 Read Status
	//--rtd_inl(0xb8000ec0, 0x00000001);  // check bisr_done :bit 0 bisr_fail: bit 1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000ec0);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, GPU2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("GPU2 _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT12, _BIT12);  // set hold remap : bit12
	udelay(200);

	//	GPU2
	IoReg_Write32(0xb8000c04,0x00); //	clear GPU group 2 BIST test mode

#if 0
	//double-check test mode exit
	udelay(1000);
	ret = rtd_inl(0xb8000ec0);
	if (ret & _BIT0)
		printf("GPU2 still keep done, --%s %d--\n", __FILE__, __LINE__);
	else
		printf("GPU2 still keep done FAIL!!!, --%s %d--\n", __FILE__, __LINE__);
	ret = rtd_inl(0xb8000e08);
	if (ret & _BIT12)
		printf("GPU2 still keep remap, --%s %d--\n", __FILE__, __LINE__);
	else
		printf("GPU2 still keep remap FAIL!!!, --%s %d--\n", __FILE__, __LINE__);
#endif
#endif

#if 1
	// ACPU
	rtd_maskl(0xb8000e08, ~_BIT5, 0); //clear hold_remap
	//printf("ACPU\n");
	// RUN 1 BISR Enable
	rtd_maskl(0xb8000e04, ~_BIT5, _BIT5);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT5, _BIT5);  // bisr_run1_rstn=1
	// RUN 1 Read Status
	//--rtd_inl(0xb8000e50, 0x00000001);  // bisr_done :bit0 bist_fail :bit8-bit1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e50);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, ACPU bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT8)
		printf("ACPU _BIT8 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT7)
		printf("ACPU _BIT7 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT6)
		printf("ACPU _BIT6 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT5)
		printf("ACPU _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT4)
		printf("ACPU _BIT4 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("ACPU _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("ACPU _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("ACPU _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT5, _BIT5);  // set hold remap : bit5
	udelay(200);
#endif

#if 1
	// VCPU
	rtd_maskl(0xb8000e08, ~_BIT6, 0); //clear hold_remap
	//printf("VCPU\n");
	// RUN 1 BISR Enable
	rtd_maskl(0xb8000e04, ~_BIT6, _BIT6);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT6, _BIT6);  // bisr_run1_rstn=1
	// RUN 1 Read Status
	//--rtd_inl(0xb8000e60, 0x00000001);  // check bist_done bit 0 bist_fail :bit4-bit1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e60);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, VCPU bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT4)
		printf("VCPU _BIT4 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("VCPU _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("VCPU _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("VCPU _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT6, _BIT6);  // set hold remap : bit6
	udelay(200);
#endif

#if 1 //USB
	//// RUN 1 BISR Enable
	//rtd_outl(0xb8000e04, 0x00000004);  // bisr_run1_rstn=1
	//rtd_outl(0xb8000e00, 0x00000004);  // bisr_rst_n=1
	//// RUN 1 Read Status
	//rtd_inl(0xb8000e20, 0x00000001);	// bisr_done : bit 0 bisr_fail :bit 1
	//rtd_outl(0xb8000e08, 0x00000002);  // set hold remap : bit2  

	//printf("USB\n");
	rtd_maskl(0xb8000e08, ~_BIT2, 0); //clear hold_remap
	rtd_maskl(0xb8000e04, ~_BIT2, _BIT2);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT2, _BIT2);  // bisr_run1_rstn=1

	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e20);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, USB bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("USB _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT2, _BIT2);  // set hold remap : bit2
	udelay(200);
#endif

	rtd_maskl(0xb8000100, ~(_BIT3|_BIT1), (_BIT3|_BIT1)); //reset ACPU/VCPU
#endif

#if 1
	//SE
	rtd_maskl(0xb8000e08, ~_BIT1, 0); //clear hold_remap
	//printf("SE\n");
	// RUN 1 BISR Enable
#if 0
	rtd_outl(0xb8000e04, 0x00000382);  // bisr_rst_n=1
	rtd_outl(0xb8000e00, 0x00000382);  // bisr_run1_rstn=1
#else
	rtd_maskl(0xb8000e04, ~_BIT1, _BIT1);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT1, _BIT1);  // bisr_run1_rstn=1
#endif
	// RUN 1 Read Status
	//--rtd_inl(0xb8000e10, 0x00000001);  // bisr_done : bit 0 bisr_fail :bit 1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e10);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, SE bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("SE _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT1, _BIT1);  // set hold remap : bit1  
	udelay(200);
#endif

#if 0 //main CPU, has done by ROM code 
#if 1	//has done?
	//SCPU DC0
	rtd_maskl(0xb8000e08, ~_BIT7, 0); //clear hold_remap
	//printf("SCPU DC0\n");
	// RUN 1 BISR Enable
#if 0
	rtd_outl(0xb8000e04, 0x00000382);  // bisr_rst_n=1
	rtd_outl(0xb8000e00, 0x00000382);  // bisr_run1_rstn=1
#else
	rtd_maskl(0xb8000e04, ~_BIT7, _BIT7);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT7, _BIT7);  // bisr_run1_rstn=1
#endif
	// RUN 1 Read Status
	//--rtd_inl(0xb8000e70, 0x00000001);  // bisr_dine : bit 0 bisr_fail:bit 8-1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e70);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, SCPU DC0 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT8)
		printf("SCPU DC0 _BIT8 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT7)
		printf("SCPU DC0 _BIT7 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT6)
		printf("SCPU DC0 _BIT6 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT5)
		printf("SCPU DC0 _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT4)
		printf("SCPU DC0 _BIT4 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("SCPU DC0 _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("SCPU DC0 _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("SCPU DC0 _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT7, _BIT7);  // set hold remap : bit7 
	udelay(200);
#endif

#if 1	//has been done?
	//SCPU DC1
	rtd_maskl(0xb8000e08, ~_BIT8, 0); //clear hold_remap
	//printf("SCPU DC1\n");
	// RUN 1 BISR Enable
#if 0
	rtd_outl(0xb8000e04, 0x00000382);  // bisr_rst_n=1
	rtd_outl(0xb8000e00, 0x00000382);  // bisr_run1_rstn=1
#else
	rtd_maskl(0xb8000e04, ~_BIT8, _BIT8);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT8, _BIT8);  // bisr_run1_rstn=1
#endif
	// RUN 1 Read Status
	//--rtd_inl(0xb8000e80, 0x00000001);  // bisr_dine : bit 0 bisr_fail:bit 8-1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e80);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, SCPU DC1 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT8)
		printf("SCPU DC1 _BIT8 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT7)
		printf("SCPU DC1 _BIT7 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT6)
		printf("SCPU DC1 _BIT6 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT5)
		printf("SCPU DC1 _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT4)
		printf("SCPU DC1 _BIT4 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("SCPU DC1 _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("SCPU DC1 _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("SCPU DC1 _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT8, _BIT8);  // set hold remap : bit8 
	udelay(200);
#endif

#if 1	//has been done?
	//SCPU IC
	rtd_maskl(0xb8000e08, ~_BIT9, 0); //clear hold_remap
	//printf("SCPU IC\n");
	// RUN 1 BISR Enable
#if 0
	rtd_outl(0xb8000e04, 0x00000382);  // bisr_rst_n=1
	rtd_outl(0xb8000e00, 0x00000382);  // bisr_run1_rstn=1
#else
	rtd_maskl(0xb8000e04, ~_BIT9, _BIT9);  // bisr_rst_n=1
	rtd_maskl(0xb8000e00, ~_BIT9, _BIT9);  // bisr_run1_rstn=1
#endif
	// RUN 1 Read Status
	//--rtd_inl(0xb8000e90, 0x00000001);  // bisr_dine : bit 0 bisr_fail:bit 4-1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8000e90);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, SCPU IC bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT4)
		printf("SCPU IC _BIT4 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("SCPU IC _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("SCPU IC _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("SCPU IC _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8000e08, ~_BIT9, _BIT9);  // set hold remap : bit9 
	udelay(200);
#endif
#endif //END MAIN CPU

#if 1
	//GDMA
	rtd_maskl(0xb802f220, ~_BIT4, 0); //clear hold_remap
	//printf("GDMA\n");
	//bisr enable
	rtd_outl(0xb802f220, 0x00000001);
	rtd_outl(0xb802f220, 0x00000005);
	rtd_outl(0xb802f220, 0x0000000d);
	// run 1 read status
	//--rtd_inl(0xb802f224, 0x00000001); // bisr_done : bit0  bisr_fail:bit3:1
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb802f224);
	}while(!(ret & _BIT0) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, GDMA bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT3)
		printf("GDMA _BIT3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT2)
		printf("GDMA _BIT2 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("GDMA _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb802f220, ~_BIT4, _BIT4); // bisr_hold_remap
	udelay(200);
#endif

#if 1
	//DISPI SDNR & SDNR3 & DI
	rtd_maskl(0xb8024340, ~_BIT7, 0); //clear hold_remap
	//printf("DI\n");
	//bisr enable
	rtd_outl(0xb8024340, 0x00000000); // bisr_*_rst_n=0
	rtd_outl(0xb8024340, 0x00000040); // bisr_soft_rst_n=1
	rtd_outl(0xb8024340, 0x00000060); // bisr_pwr_rst_n=1


	// run 1 read status
	//--rtd_inl(0xb8024330, 0x81000000); // check bisr done : bit 24
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8024330);	//DI
	}while(!(ret & _BIT24) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, DI bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT0)
		printf("DI _BIT0 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT1)
		printf("DI _BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8024340, ~_BIT7, _BIT7); // bisr_hold_remap : bit 7 
	udelay(200);
#endif

#if 1
	rtd_maskl(0xb8025230, ~_BIT4, 0); //clear hold_remap
	//printf("SDNR\n");
	rtd_outl(0xb8025230, 0x00000000); //sdnr
	rtd_outl(0xb8025230, 0x00000002);
	rtd_outl(0xb8025230, 0x80000002);

	// run 1 read status
	//--rtd_inl(0xb8025230, 0x80000006); // check bisr done : bit 2 bisr_fail: bit 5
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8025230);	//SDNR
	}while(!(ret & _BIT2) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, SDNR bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT5)
		printf("SDNR _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	ret = rtd_inl(0xb80252d4);	//check bisr_fail bit 0
	if (ret & _BIT0)
		printf("SDNR a_BIT0 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8025230, ~_BIT4, _BIT4); // set bisr_hold_remap : bit 4
	udelay(200);
#endif

#if 1
	rtd_maskl(0xb8025228, ~_BIT4, 0); //clear hold_remap
	//printf("SDNR3\n");
	rtd_outl(0xb8025228, 0x00000000); //sdnr_3
	rtd_outl(0xb8025228, 0x00000002);
	rtd_outl(0xb8025228, 0x80000002);

	// run 1 read status
	//--rtd_inl(0xb8025228, 0x80000006); // check bisr done : bit2 bisr_fail: bit6-5 
	count = 0;
	do {
		udelay(200);
		count++;
		ret = rtd_inl(0xb8025228);	//SDNR3
	}while(!(ret & _BIT2) && (count < BISR_CHECK_COUNT));
	if (count >= BISR_CHECK_COUNT)
		printf("count > 10, SDNR3 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT6)
		printf("SDNR3 _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT5)
		printf("SDNR3 _BIT5 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	ret = rtd_inl(0xb80252d0);	//check bisr_fail bit 1-0
	if (ret & _BIT1)
		printf("SDNR3 a_BIT1 bisr fail, --%s %d--\n", __FILE__, __LINE__);
	if (ret & _BIT0)
		printf("SDNR3 a_BIT0 bisr fail, --%s %d--\n", __FILE__, __LINE__);

	rtd_maskl(0xb8025228, ~_BIT4, _BIT4); // set bisr_hold_remap : bit 4
	udelay(200);
#endif

#if 1 //debug information
	ret = rtd_inl(0xb8000e08);
	printf("remap(0xb8000e08)=0x%x\n", ret);
#endif

#endif
}

