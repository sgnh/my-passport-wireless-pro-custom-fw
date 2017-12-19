############################################################
#
# libusbmuxd
#
###########################################################

LIBUSBMUXD_VERSION = 1.0.10
LIBUSBMUXD_SITE = http://www.libimobiledevice.org/downloads/libusbmuxd-$(LIBUSBMUXD_VERSION).tar.bz2
LIBUSBMUXD_SOURCE = libusbmuxd-$(LIBUSBMUXD_VERSION).tar.bz2
LIBUSBMUXD_DIR = $(BUILD_DIR)/libusbmuxd-$(LIBUSBMUXD_VERSION)

LIBUSBMUXD_INSTALL_STAGING = YES
LIBUSBMUXD_INSTALL_TARGET = YES
#IBUSBMUXD_AUTORECONF = YES

LIBUSBMUXD_LICENSE_FILES = LGPLv2.1+
LIBUSBMUXD_LICENSE_FILES = COPYING

LIBUSBMUXD_DEPENDENCIES = libplist

define LIBUSBMUXD_EXTRACT_CMDS
	tar jxvf $(DL_DIR)/$(LIBUSBMUXD_SOURCE) -C $(@D)
endef

$(eval $(autotools-package))
