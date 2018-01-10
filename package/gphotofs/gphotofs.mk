############################################################
#
# gphotofs
#
###########################################################

GPHOTOFS_VERSION = 0.5
GPHOTOFS_SITE = http://sourceforge.net/projects/gphoto/files/gphotofs/0.5.0/
GPHOTOFS_SOURCE = gphotofs-$(GPHOTOFS_VERSION).tar.bz2
GPHOTOFS_DIR = $(BUILD_DIR)/gphotofs-$(GPHOTOFS_VERSION)

GPHOTOFS_INSTALL_STAGING = YES
GPHOTOFS_INSTALL_TARGET = YES

GPHOTOFS_LICENSE = GPLv2
GPHOTOFS_LICENSE_FILES = COPYING	

GPHOTOFS_DEPENDENCIES = popt libgphoto2 libfuse gphoto2 libusb

define GPHOTOFS_EXTRACT_CMDS
	tar jxvf $(DL_DIR)/$(GPHOTOFS_SOURCE) -C $(@D)
endef

$(eval $(autotools-package))
