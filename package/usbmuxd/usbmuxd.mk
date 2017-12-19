############################################################
#
# usbmuxd
#
###########################################################

USBMUXD_VERSION = 1.1.0
USBMUXD_SITE = http://www.libimobiledevice.org/downloads/usbmuxd-$(USBMUXD_VERSION).tar.bz2
USBMUXD_SOURCE = usbmuxd-$(USBMUXD_VERSION).tar.bz2
USBMUXD_DIR = $(BUILD_DIR)/usbmuxd-$(USBMUXD_VERSION)

USBMUXD_INSTALL_STAGING = YES
USBMUXD_INSTALL_TARGET = YES

USBMUXD_LICENSE = Dual GPLv2/GPLv3
USBMUXD_LICENSE_FILES = COPYING.GPLv2 COPYING.GPLv3

#USBMUXD_CONF_OPTS = --without-systemd
USBMUXD_DEPENDENCIES = libimobiledevice libplist libtool libusb libusbmuxd

define USBMUXD_EXTRACT_CMDS
	tar jxvf $(DL_DIR)/$(USBMUXD_SOURCE) -C $(@D)
endef

$(eval $(autotools-package))
