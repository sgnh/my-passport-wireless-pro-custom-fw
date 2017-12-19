/*
 * SAMSUNG EXYNOS USB HOST EHCI Controller
 *
 * Copyright (C) 2012 Samsung Electronics Co.Ltd
 *	Vivek Gautam <gautam.vivek@samsung.com>
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

#include <common.h>
#include <usb.h>
#include <asm/arch/cpu.h>
//#include <asm/arch/ehci.h>
//#include <asm/arch/system.h>
//#include <asm/arch/power.h>
#include "ehci.h"

#define REG_WRAP_VStatusOut2	(0x18013824)
#define REG_EHCI_INSNREG05		(0x180130A4)

#define USB_ST_BUSY	(1<<17)

struct rtk_usb_phy_data_s {
	char addr;
	char data;
};

static struct rtk_usb_phy_data_s phy_page0_default_setting[] = {
	{0xe0, 0x61},
	{0xe0, 0xe1},
	{0xe2, 0x9a},
	{0xe4, 0xd6},
	{0xe5, 0x1d},
	{0xe6, 0xc0},
	{0xf1, 0x9c},
};

static struct rtk_usb_phy_data_s phy_page1_default_setting[] = {
	{0xe0, 0x25},
	{0xe1, 0xaf},
};

static int utmi_wait_register(u32 reg, u32 mask, u32 result)
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

static int rtk_usb_phy_write(char addr, char data)
{
	volatile unsigned int regVal;

	__raw_writeb(data, (volatile u32*)REG_WRAP_VStatusOut2);
	utmi_wait_register(REG_EHCI_INSNREG05, USB_ST_BUSY, 0);

	// VCtrl = low nibble of addr, VLoadM = 1
	regVal = (1 << 13) | 	// Port num
			 (1 << 12) |	// vload
			 ((addr & 0x0f) << 8);	// vcontrol
	__raw_writel(regVal, (volatile u32*)REG_EHCI_INSNREG05);
	utmi_wait_register(REG_EHCI_INSNREG05, USB_ST_BUSY, 0);

	// VCtrl = low nibble of addr, VLoadM = 0
	regVal &= ~(1 << 12);
	__raw_writel(regVal, (volatile u32*)REG_EHCI_INSNREG05);
	utmi_wait_register(REG_EHCI_INSNREG05, USB_ST_BUSY, 0);

	// VCtrl = high nibble of addr, VLoadM = 1
	regVal = (1 << 13) | 	// Port num
			 (1 << 12) |	// vload
			 ((addr & 0xf0) << 4);	// vcontrol
	__raw_writel(regVal, (volatile u32*)REG_EHCI_INSNREG05);
	utmi_wait_register(REG_EHCI_INSNREG05, USB_ST_BUSY, 0);

	// VCtrl = high nibble of addr, VLoadM = 0
	regVal &= ~(1 << 12);
	__raw_writel(regVal, (volatile u32*)REG_EHCI_INSNREG05);
	utmi_wait_register(REG_EHCI_INSNREG05, USB_ST_BUSY, 0);

	return 0;
}

/* Setup the EHCI host controller. */
int rtk_usb_phy_init(void)
{
#if 1
	int i;

//	printf("%s %d\n",__func__, __LINE__);
	rtk_usb_phy_write(0xf4, 0x9b);	// set page 0

	for (i=0; i<ARRAY_SIZE(phy_page0_default_setting); i++) {
		if (rtk_usb_phy_write(phy_page0_default_setting[i].addr, phy_page0_default_setting[i].data)) {
			printf("[%s:%d], Error : addr = 0x%x, value = 0x%x\n",
				__FUNCTION__, __LINE__,
				phy_page0_default_setting[i].addr,
				phy_page0_default_setting[i].data);
			return -1;
		}
	}

	rtk_usb_phy_write(0xf4, 0xbb);	// set page 1

	for (i=0; i<ARRAY_SIZE(phy_page1_default_setting); i++) {
		if (rtk_usb_phy_write(phy_page1_default_setting[i].addr, phy_page1_default_setting[i].data)) {
			printf("[%s:%d], Error : addr = 0x%x, value = 0x%x\n",
				__FUNCTION__, __LINE__,
				phy_page1_default_setting[i].addr,
				phy_page1_default_setting[i].data);
			return -1;
		}
	}
	mdelay(100);
	return 0;
#else
	set_usbhost_mode(USB20_PHY_CFG_HOST_LINK_EN);

	set_usbhost_phy_ctrl(POWER_USB_HOST_PHY_CTRL_EN);

	clrbits_le32(&usb->usbphyctrl0,
			HOST_CTRL0_FSEL_MASK |
			HOST_CTRL0_COMMONON_N |
			/* HOST Phy setting */
			HOST_CTRL0_PHYSWRST |
			HOST_CTRL0_PHYSWRSTALL |
			HOST_CTRL0_SIDDQ |
			HOST_CTRL0_FORCESUSPEND |
			HOST_CTRL0_FORCESLEEP);

	setbits_le32(&usb->usbphyctrl0,
			/* Setting up the ref freq */
			(CLK_24MHZ << 16) |
			/* HOST Phy setting */
			HOST_CTRL0_LINKSWRST |
			HOST_CTRL0_UTMISWRST);
	udelay(10);
	clrbits_le32(&usb->usbphyctrl0,
			HOST_CTRL0_LINKSWRST |
			HOST_CTRL0_UTMISWRST);
	udelay(20);

	/* EHCI Ctrl setting */
	setbits_le32(&usb->ehcictrl,
			EHCICTRL_ENAINCRXALIGN |
			EHCICTRL_ENAINCR4 |
			EHCICTRL_ENAINCR8 |
			EHCICTRL_ENAINCR16);
#endif
}

#if 0
/* Reset the EHCI host controller. */
static void reset_usb_phy(void)
{
	/* HOST_PHY reset */
	setbits_le32(&usb->usbphyctrl0,
			HOST_CTRL0_PHYSWRST |
			HOST_CTRL0_PHYSWRSTALL |
			HOST_CTRL0_SIDDQ |
			HOST_CTRL0_FORCESUSPEND |
			HOST_CTRL0_FORCESLEEP);

	set_usbhost_phy_ctrl(POWER_USB_HOST_PHY_CTRL_DISABLE);
}
#endif

/*
 * EHCI-initialization
 * Create the appropriate control structures to manage
 * a new EHCI host controller.
 */
int ehci_hcd_init(int index, struct ehci_hccr **hccr, struct ehci_hcor **hcor)
{
#if 0
	struct exynos_usb_phy *usb;

	usb = (struct exynos_usb_phy *)rtk_get_base_usb_phy();
#endif
	rtk_usb_phy_init();

	*hccr = (struct ehci_hccr *)realtek_get_base_usb_ehci();
	*hcor = (struct ehci_hcor *)((uint32_t) *hccr
				+ HC_LENGTH(ehci_readl(&(*hccr)->cr_capbase)));

	debug("Realtek-ehci: init hccr %x and hcor %x hc_length %d\n",
		(uint32_t)*hccr, (uint32_t)*hcor,
		(uint32_t)HC_LENGTH(ehci_readl(&(*hccr)->cr_capbase)));

	return 0;
}

/*
 * Destroy the appropriate control structures corresponding
 * the EHCI host controller.
 */
int ehci_hcd_stop(int index)
{
#if 0
	struct exynos_usb_phy *usb;

	usb = (struct exynos_usb_phy *)samsung_get_base_usb_phy();
	reset_usb_phy(usb);
#endif

	return 0;
}
