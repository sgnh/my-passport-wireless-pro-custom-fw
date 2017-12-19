/*
 * SAMSUNG EXYNOS5 USB HOST XHCI Controller
 *
 * Copyright (C) 2012 Samsung Electronics Co.Ltd
 *	Vivek Gautam <gautam.vivek@samsung.com>
 *	Vikas Sajjan <vikas.sajjan@samsung.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

/*
 * This file is a conglomeration for DWC3-init sequence and further
 * exynos5 specific PHY-init sequence.
 */

#include <common.h>
#include <malloc.h>
#include <usb.h>
#include <watchdog.h>
#include <asm-generic/errno.h>
#include <linux/compat.h>

#include "xhci.h"
#include <usb/usb_reg.h>
#include <asm/arch/cpu.h>
#include <asm/processor.h>

////////////////////////////////////////////////////////////
//////////////////xhci phy porting//////////////////////////////
#define REG_USB3BASE		(0x18028100)

static u32 dwc3_readl(u32 offset)
{
	/*
	 * We requested the mem region starting from the Globals address
	 * space, see dwc3_probe in core.c.
	 * However, the offsets are given starting from xHCI address space.
	 */
	return __raw_readl((volatile u32*)(REG_USB3BASE + (offset - DWC3_GLOBALS_REGS_START)));
}

static void dwc3_writel(u32 offset, u32 value)
{
	/*
	 * We requested the mem region starting from the Globals address
	 * space, see dwc3_probe in core.c.
	 * However, the offsets are given starting from xHCI address space.
	 */
	__raw_writel(value, (volatile u32*)(REG_USB3BASE + (offset - DWC3_GLOBALS_REGS_START)));
}

void dwc3_set_mode(u32 mode)
{
	u32 reg;

	reg = dwc3_readl( DWC3_GCTL);
	reg &= ~(DWC3_GCTL_PRTCAPDIR(DWC3_GCTL_PRTCAP_OTG));
	reg |= DWC3_GCTL_PRTCAPDIR(mode);
	dwc3_writel( DWC3_GCTL, reg);
}

static void dwc3_core_soft_reset(void)
{
	u32		reg;

	/* Before Resetting PHY, put Core in Reset */
	reg = dwc3_readl( DWC3_GCTL);
	reg |= DWC3_GCTL_CORESOFTRESET;
	dwc3_writel( DWC3_GCTL, reg);
	mdelay(100);

	/* Assert USB3 PHY reset */
	reg = dwc3_readl( DWC3_GUSB3PIPECTL(0));
	reg |= DWC3_GUSB3PIPECTL_PHYSOFTRST;
	dwc3_writel( DWC3_GUSB3PIPECTL(0), reg);
	mdelay(100);

	/* Assert USB2 PHY reset */
	reg = dwc3_readl( DWC3_GUSB2PHYCFG(0));
	reg |= DWC3_GUSB2PHYCFG_PHYSOFTRST;
	dwc3_writel( DWC3_GUSB2PHYCFG(0), reg);
	mdelay(100);

	/* FIXME Barry original */
	usb3_phy_setting();
	mdelay(100);

	/* Clear USB3 PHY reset */
	reg = dwc3_readl( DWC3_GUSB3PIPECTL(0));
	reg &= ~DWC3_GUSB3PIPECTL_PHYSOFTRST;
	dwc3_writel( DWC3_GUSB3PIPECTL(0), reg);
	mdelay(100);

	/* Clear USB2 PHY reset */
	reg = dwc3_readl( DWC3_GUSB2PHYCFG(0));
	reg &= ~DWC3_GUSB2PHYCFG_PHYSOFTRST;
	dwc3_writel( DWC3_GUSB2PHYCFG(0), reg);

	mdelay(100);

	/* After PHYs are stable we can take Core out of reset state */
	reg = dwc3_readl( DWC3_GCTL);
	reg &= ~DWC3_GCTL_CORESOFTRESET;
	dwc3_writel( DWC3_GCTL, reg);
	mdelay(100);

	usb2_phy_setting();
	mdelay(100);

}

static int dwc3_core_init(void)
{
	unsigned long		timeout= 5000;
	u32			reg, revision;
	int			ret;


	u32 hwparams0 = dwc3_readl( DWC3_GHWPARAMS0);
	u32 hwparams1 = dwc3_readl( DWC3_GHWPARAMS1);
	u32 hwparams2 = dwc3_readl( DWC3_GHWPARAMS2);
	u32 hwparams3 = dwc3_readl( DWC3_GHWPARAMS3);
	u32 hwparams4 = dwc3_readl( DWC3_GHWPARAMS4);
	u32 hwparams5 = dwc3_readl( DWC3_GHWPARAMS5);
	u32 hwparams6 = dwc3_readl( DWC3_GHWPARAMS6);
	u32 hwparams7 = dwc3_readl( DWC3_GHWPARAMS7);
	u32 hwparams8 = dwc3_readl( DWC3_GHWPARAMS8);


	reg = dwc3_readl( DWC3_GSNPSID);	//c120
	/* This should read as U3 followed by revision number */
	if ((reg & DWC3_GSNPSID_MASK) != 0x55330000) {
		printf("this is not a DesignWare USB3 DRD Core\n");
		ret = -ENODEV;
		goto err0;
	}
	revision = reg;

	/* issue device SoftReset too */

	dwc3_writel( DWC3_DCTL, DWC3_DCTL_CSFTRST);
	mdelay(100);
	timeout = 5000;
	while ( ((dwc3_readl( DWC3_DCTL)) & DWC3_DCTL_CSFTRST) && timeout-- ) 
	{
		mdelay(10);
		if (timeout <= 0) 
		{
			printf("USB3 Reset Timed Out\n");
			ret = -ETIMEDOUT;
			goto err0;
		}
//		cpu_relax();
	}

	dwc3_core_soft_reset();
	mdelay(100);
	reg = dwc3_readl( DWC3_GCTL);
	reg &= ~DWC3_GCTL_SCALEDOWN_MASK;
	reg &= ~DWC3_GCTL_DISSCRAMBLE;

	switch (DWC3_GHWPARAMS1_EN_PWROPT(hwparams1)) {
	case DWC3_GHWPARAMS1_EN_PWROPT_CLK:
		reg &= ~DWC3_GCTL_DSBLCLKGTNG;
		break;
	default:
		printf("No power optimization available\n");
		break;
	}

	/*
	 * WORKAROUND: DWC3 revisions <1.90a have a bug
	 * where the device can fail to connect at SuperSpeed
	 * and falls back to high-speed mode which causes
	 * the device to enter a Connect/Disconnect loop
	 */
	if (revision < DWC3_REVISION_190A)
		reg |= DWC3_GCTL_U2RSTECN;



	dwc3_writel( DWC3_GCTL, reg);
	mdelay(100);
	/* workaround: to avoid transaction error and cause port reset
	 * we enable threshold control for TX/RX */

	dwc3_writel( DWC3_GTXTHRCFG, 0x01010000);
	mdelay(100);
#define RX_THRESHOLD_EN		(1<<29)
#define RX_PKT_CNT(n)		(n<<24)
#define RX_MAX_BURST_SZ(n)	(n<<19)
	dwc3_writel( DWC3_GRXTHRCFG,  RX_THRESHOLD_EN | RX_PKT_CNT(3) | RX_MAX_BURST_SZ(3));
	mdelay(100);
	dwc3_writel(DWC3_GUCTL,dwc3_readl(DWC3_GUCTL) | (1<<14));   // enable auto retry
	mdelay(100);


	return 0;

err0:
	return ret;
}

static int xhci_usb_utmi_wait_register(u32 reg, u32 mask, u32 result)
{
	uint timeout = 10;
	while (((__raw_readl((volatile u32*)reg) & mask) != result) && timeout--) {
		udelay(100);
		if (timeout <= 0) {
			printf("%s: \033[0:32:31m Can't program USB phy\033[m\n",__func__);
			return -1;
		}
	}
	return 0;
}

#define SB2_OFFSET			0x0001A000
#define	CHIP_ID				0x00000200
#define CHIP_REV			0x00000204
#define SB2_IO_ADDR(pa)		(0x18000000 + SB2_OFFSET + pa)


#define get_cpu_id()		 __raw_readl((volatile u32*)(SB2_IO_ADDR(CHIP_ID)))
#define get_cpu_revision()	 __raw_readl((volatile u32*)(SB2_IO_ADDR(CHIP_REV)))

#define RTK1195_CPU_ID		0x00006329
#define RTK1195_CPU_MASK	0x0000FFFF
#define RTK1195_REV_A		(0x0)
#define RTK1195_REV_B		(0x1)
#define RTK1195_REV_C		(0x2)

#define REG_MDIO_CTL 0x18013210


unsigned int realtek_rev(void)
{
	volatile unsigned int system_rev;
	system_rev = get_cpu_revision();
	return (system_rev>>16);
}
static int soc_is_rtk1195(void)	
{											
	volatile unsigned int realtek_cpu_id;
	realtek_cpu_id = get_cpu_id();

	return ((realtek_cpu_id & RTK1195_CPU_MASK) == (RTK1195_CPU_ID & RTK1195_CPU_MASK));	
}

static int rtk_usb_phy3_wait_vbusy(void)
{
	return xhci_usb_utmi_wait_register(REG_MDIO_CTL, (1<<7), 0);
}

static u32 rtk_xhci_usb3_phy_read(char addr)
{
	volatile unsigned int regVal;

	regVal = (addr << 8);
	__raw_writel(regVal, (volatile u32*)(REG_MDIO_CTL));

	rtk_usb_phy3_wait_vbusy();

	return __raw_readl((volatile u32*)(REG_MDIO_CTL));
}

static int rtk_xhci_usb3_phy_write(char addr, u16 data)
{
	volatile unsigned int regVal;

	regVal = (1 << 0) |
			(addr << 8) |
			(data <<16);
	__raw_writel(regVal, (volatile u32*)(REG_MDIO_CTL));

	rtk_usb_phy3_wait_vbusy();
	mdelay(10);
	return 0;
}

void usb3_phy_setting(void)
{

	printf("RTK USB3 phy init\n");
	rtk_xhci_usb3_phy_write(0x00, 0x4008);
	rtk_xhci_usb3_phy_write(0x01, 0xA878);
	rtk_xhci_usb3_phy_write(0x02, 0x6046);
	rtk_xhci_usb3_phy_write(0x03, 0x2771);
	rtk_xhci_usb3_phy_write(0x04, 0xB2F5);
	rtk_xhci_usb3_phy_write(0x05, 0x2AD7);
	rtk_xhci_usb3_phy_write(0x06, 0x0001);
	rtk_xhci_usb3_phy_write(0x07, 0x3200);
	if (soc_is_rtk1195() && (realtek_rev() == RTK1195_REV_A)) {
		rtk_xhci_usb3_phy_write(0x08, 0x3590);
		rtk_xhci_usb3_phy_write(0x09, 0x325C);
		rtk_xhci_usb3_phy_write(0x0A, 0xD643);
		rtk_xhci_usb3_phy_write(0x0B, 0xE909);
	}
	else {	// REV_B
		rtk_xhci_usb3_phy_write(0x08, 0x3592);
		rtk_xhci_usb3_phy_write(0x09, 0x325C);
		rtk_xhci_usb3_phy_write(0x0A, 0xD643);
		rtk_xhci_usb3_phy_write(0x0B, 0xA909);
	}
	rtk_xhci_usb3_phy_write(0x0C, 0xC008);
	rtk_xhci_usb3_phy_write(0x0D, 0xFF28);
	rtk_xhci_usb3_phy_write(0x0E, 0x2010);
	rtk_xhci_usb3_phy_write(0x0F, 0x8000);
	rtk_xhci_usb3_phy_write(0x10, 0x000C);
	rtk_xhci_usb3_phy_write(0x11, 0x4C00);
	rtk_xhci_usb3_phy_write(0x12, 0xFC00);
	rtk_xhci_usb3_phy_write(0x13, 0x0C81);
	rtk_xhci_usb3_phy_write(0x14, 0xDE01);
	rtk_xhci_usb3_phy_write(0x15, 0x0000);
	rtk_xhci_usb3_phy_write(0x16, 0x0000);
	rtk_xhci_usb3_phy_write(0x17, 0x0000);
	rtk_xhci_usb3_phy_write(0x18, 0x0000);
	if (soc_is_rtk1195() && (realtek_rev() == RTK1195_REV_A)) {
		rtk_xhci_usb3_phy_write(0x19, 0x7004);
	}
	else {	// REV_B
		rtk_xhci_usb3_phy_write(0x19, 0x3804);
	}
	rtk_xhci_usb3_phy_write(0x1A, 0x1260);
	rtk_xhci_usb3_phy_write(0x1B, 0xFF0C);
	rtk_xhci_usb3_phy_write(0x1C, 0xCB1C);
	rtk_xhci_usb3_phy_write(0x1D, 0xA03F);
	rtk_xhci_usb3_phy_write(0x1E, 0xC200);
	rtk_xhci_usb3_phy_write(0x1F, 0x9000);
	rtk_xhci_usb3_phy_write(0x20, 0xD4FF);
	rtk_xhci_usb3_phy_write(0x21, 0xAAFF);
	rtk_xhci_usb3_phy_write(0x22, 0x0051);
	rtk_xhci_usb3_phy_write(0x23, 0xDB60);
	rtk_xhci_usb3_phy_write(0x24, 0x0800);
	rtk_xhci_usb3_phy_write(0x25, 0x0000);
	rtk_xhci_usb3_phy_write(0x26, 0x0004);
	rtk_xhci_usb3_phy_write(0x27, 0x01D6);
	if (soc_is_rtk1195() && (realtek_rev() == RTK1195_REV_A)) {
		rtk_xhci_usb3_phy_write(0x28, 0xF882);
	}
	else {	// REV_B
	//	rtk_xhci_usb3_phy_write(0x28, 0xF842);
		rtk_xhci_usb3_phy_write(0x28, 0xF840);
	}
	rtk_xhci_usb3_phy_write(0x29, 0x3080);
	rtk_xhci_usb3_phy_write(0x2A, 0x3083);
	rtk_xhci_usb3_phy_write(0x2B, 0x2038);
	rtk_xhci_usb3_phy_write(0x2C, 0xFFFF);
	rtk_xhci_usb3_phy_write(0x2D, 0xFFFF);
	rtk_xhci_usb3_phy_write(0x2E, 0x0000);
	rtk_xhci_usb3_phy_write(0x2F, 0x0040);
	rtk_xhci_usb3_phy_write(0x09, 0x325C);
	rtk_xhci_usb3_phy_write(0x09, 0x305C);
	rtk_xhci_usb3_phy_write(0x09, 0x325C);
#if	0//def SHOW_USBPHY_PARA
	{
		int i=0;
		for (i=0; i<0x30; i++)
			printf("\033[0;36m [%02x] %08x \033[m\n", i, rtk_xhci_usb3_phy_read(i));
	}
#endif
	return 0;

}
/* hcy added below */
static u8 connected=0;
void rtk_usb3_phy_state(uint8_t state)
{
	if (soc_is_rtk1195() && (realtek_rev() < RTK1195_REV_C)) {
                if ((state & USB_PORT_STAT_CONNECTION) && (connected==0)) {
			connected = 1;
			debug("*********set A03E ******\n");
        		rtk_xhci_usb3_phy_write(0x1D, 0xA03E);
                }	
		else if (!(state & USB_PORT_STAT_CONNECTION) && (connected==1)) {
			connected = 0;
                        //saved_trim_value = 0xFFFF;      // reset to init phase
                        debug("*********set A03F ******\n");
                       rtk_xhci_usb3_phy_write(0x1D, 0xA03F);
		}
	}

}

#define REG_WRAP_VUSB2StatusOut2	(0x18013214)
#define REG_GUSB2PHYACC0		(0x18028280)

#define USB_ST_BUSY	(1<<17)

struct rtk_xhci_usb2_phy_data_s {
	char addr;
	char data;
};

static struct rtk_xhci_usb2_phy_data_s phy_page0_default_setting[] = {
	{0xe0, 0x61},
	{0xe0, 0xe1},
	{0xe2, 0x9a},
	{0xe4, 0xd6},
	{0xe5, 0x1d},
	{0xe6, 0xc0},
	{0xf1, 0x9c},
};

static struct rtk_xhci_usb2_phy_data_s phy_page1_default_setting[] = {
	{0xe0, 0x25},
	{0xe1, 0xaf},
};

static int rtk_xhci_usb2_phy_write(char addr, char data)
{
	volatile unsigned int regVal;

	__raw_writeb(data, (volatile u32*)REG_WRAP_VUSB2StatusOut2);
	xhci_usb_utmi_wait_register(REG_GUSB2PHYACC0, USB_ST_BUSY, 0);

	// VCtrl = low nibble of addr, VLoadM = 1
	regVal = (1 << 25) | 
			 ((addr & 0x0f) << 8);	
	
	__raw_writel(regVal, (volatile u32*)REG_GUSB2PHYACC0);
	xhci_usb_utmi_wait_register(REG_GUSB2PHYACC0, USB_ST_BUSY, 0);

	// VCtrl = low nibble of addr, VLoadM = 0
	regVal = (1 << 25) | 
			 ((addr & 0xf0) << 4);	
	
	__raw_writel(regVal, (volatile u32*)REG_GUSB2PHYACC0);
	xhci_usb_utmi_wait_register(REG_GUSB2PHYACC0, USB_ST_BUSY, 0);

	return 0;
}



void usb2_phy_setting(void)
{

	int i;
	rtk_xhci_usb2_phy_write(0xf4, 0x9b);	// set page 0

	for (i=0; i<ARRAY_SIZE(phy_page0_default_setting); i++) {
		if (rtk_xhci_usb2_phy_write(phy_page0_default_setting[i].addr, phy_page0_default_setting[i].data)) {
			printf("[%s:%d], Error : addr = 0x%x, value = 0x%x\n",
				__FUNCTION__, __LINE__,
				phy_page0_default_setting[i].addr,
				phy_page0_default_setting[i].data);
			return -1;
		}
		mdelay(10);
	}
	mdelay(100);
	
	rtk_xhci_usb2_phy_write(0xf4, 0xbb);	// set page 1

	for (i=0; i<ARRAY_SIZE(phy_page1_default_setting); i++) {
		if (rtk_xhci_usb2_phy_write(phy_page1_default_setting[i].addr, phy_page1_default_setting[i].data)) {
			printf("[%s:%d], Error : addr = 0x%x, value = 0x%x\n",
				__FUNCTION__, __LINE__,
				phy_page1_default_setting[i].addr,
				phy_page1_default_setting[i].data);
			return -1;
		}
		mdelay(10);
	}
	mdelay(100);
	return 0;
}
int xhci_hcd_init(int index, struct xhci_hccr **hccr, struct xhci_hcor **hcor)
{
	// FIXME
	// 1. set xhci usbphy
	// 2. register mapping
	// 3. irq ?
	int ret;
	*hccr = (struct xhci_hccr *)realtek_get_base_usb_xhci();
	*hcor = (struct xhci_hcor *)((uint32_t) *hccr
				+ HC_LENGTH(xhci_readl(&(*hccr)->cr_capbase)));
	printf("Realtek-ehci: init hccr %x and hcor %x hc_length %d\n",
		(uint32_t)*hccr, (uint32_t)*hcor,
		(uint32_t)HC_LENGTH(xhci_readl(&(*hccr)->cr_capbase)));

	ret = dwc3_core_init();
	if (ret) {
		printf("failed to initialize core\n");
		return -1;
	}
	mdelay(100);
	__raw_writel(0x7, (volatile u32*)(0x18013258));		//barry???
	mdelay(100);
	__raw_writel(0x606, (volatile u32*)(0x18013270));	//barry set Dpm 1'b1
	mdelay(100);
	dwc3_set_mode(DWC3_GCTL_PRTCAP_HOST);
	mdelay(100);

	debug("xhci: init hccr %x and hcor %x hc_length %d\n",
		(uint32_t)*hccr, (uint32_t)*hcor,
		(uint32_t)HC_LENGTH(xhci_readl(&(*hccr)->cr_capbase)));

	return 0;
}

void xhci_hcd_stop(int index)
{
	return;
}
