#ifndef _REALTEK_CPU_H_
#define _REALTEK_CPU_H_

#define RTD1195_USBPHY_BASE				0x18013210
#define RTD1195_USB_HOST_EHCI_BASE		0x18013000
#define RTD1195_USB_HOST_XHCI_BASE		0x18020000
#define RTD1195_USBOTG_BASE				0x18038000

#ifndef __ASSEMBLY__
#include <asm/io.h>

#define REALTEK_BASE(device, base)			\
static inline unsigned int __attribute__((no_instrument_function)) \
	realtek_get_base_##device(void)	\
{									\
	return RTD1195_##base;			\
}

REALTEK_BASE(usb_phy,  USBPHY_BASE)
REALTEK_BASE(usb_ehci, USB_HOST_EHCI_BASE)
REALTEK_BASE(usb_xhci, USB_HOST_XHCI_BASE)
REALTEK_BASE(usb_otg,  USBOTG_BASE)
#endif


#endif /* _REALTEK_CPU_H_ */
