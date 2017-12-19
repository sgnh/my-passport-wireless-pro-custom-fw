############################################################
#
# ifuse
#
###########################################################

IFUSE_VERSION = 1.1.3
IFUSE_SITE = http://www.libimobiledevice.org/downloads/ifuse-$(IFUSE_VERSION).tar.bz2
IFUSE_SOURCE = ifuse-$(IFUSE_VERSION).tar.bz2
IFUSE_DIR = $(BUILD_DIR)/ifuse-$(IFUSE_VERSION)

IFUSE_INSTALL_STAGING = YES
IFUSE_INSTALL_TARGET = YES

IFUSE_LICENSE = LGPLv2.1+
IFUSE_LICENSE_FILES = COPYING

IFUSE_DEPENDENCIES = libfuse libimobiledevice libplist
	
define IFUSE_EXTRACT_CMDS
	tar jxvf $(DL_DIR)/$(IFUSE_SOURCE) -C $(@D)
endef

$(eval $(autotools-package))
