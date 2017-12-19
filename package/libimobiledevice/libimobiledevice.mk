############################################################
#
# libimobiledevice
#
###########################################################

LIBIMOBILEDEVICE_VERSION = 1.2.0
LIBIMOBILEDEVICE_SITE = http://www.libimobiledevice.org/downloads/libimobiledevice-$(LIBIMOBILEDEVICE_VERSION).tar.bz2
LIBIMOBILEDEVICE_SOURCE = libimobiledevice-$(LIBIMOBILEDEVICE_VERSION).tar.bz2
LIBIMOBILEDEVICE_DIR = $(BUILD_DIR)/libimobiledevice-$(LIBIMOBILEDEVICE_VERSION)

LIBIMOBILEDEVICE_INSTALL_STAGING = YES
LIBIMOBILEDEVICE_INSTALL_TARGET = YES

LIBIMOBILEDEVICE_LICENSE = GPLv2 LGPLv2.1
LIBIMOBILEDEVICE_LICENSE_FILES = COPYING COPYING.LESSER

LIBIMOBILEDEVICE_DEPENDENCIES = openssl python libplist libusbmuxd

LIBIMOBILEDEVICE_CONF_OPTS = --without-cython
define LIBIMOBILEDEVICE_EXTRACT_CMDS
	tar jxvf $(DL_DIR)/$(LIBIMOBILEDEVICE_SOURCE) -C $(@D)
endef

$(eval $(autotools-package))
