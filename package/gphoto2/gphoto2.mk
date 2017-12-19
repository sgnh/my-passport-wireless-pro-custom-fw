############################################################
#
# gphoto2
#
###########################################################

GPHOTO2_VERSION = 2.5.10
GPHOTO2_SITE = http://sourceforge.net/projects/gphoto/files/latest/download
GPHOTO2_SOURCE = gphoto2-$(GPHOTO2_VERSION).tar.gz
GPHOTO2_DIR = $(BUILD_DIR)/gphoto2-$(GPHOTO2_VERSION)

GPHOTO2_INSTALL_STAGING = YES
GPHOTO2_INSTALL_TARGET = YES

#GPHOTO2_DEPENDENCIES = popt libgphoto2 libusb
GPHOTO2_DEPENDENCIES = popt libgphoto2 libtool libusb

GPHOTO2_LICENSE = GPLv2
GPHOTO2_LICENSE_FILES = COPYING

#define GPHOTO2_EXTRACT_CMDS
#	tar zxvf $(DL_DIR)/$(GPHOTO2_SOURCE) -C $(@D)
#endef


$(eval $(autotools-package))
