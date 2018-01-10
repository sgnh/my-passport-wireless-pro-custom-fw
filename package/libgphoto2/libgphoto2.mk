############################################################
#
# libgphoto2
#
###########################################################

LIBGPHOTO2_VERSION = 2.5.16
LIBGPHOTO2_SITE = http://sourceforge.net/projects/gphoto/files/latest/download
LIBGPHOTO2_SOURCE = libgphoto2-$(LIBGPHOTO2_VERSION).tar.bz2 
LIBGPHOTO2_DIR = $(BUILD_DIR)/libgphoto2-$(LIBGPHOTO2_VERSION)

LIBGPHOTO2_INSTALL_STAGING = YES
LIBGPHOTO2_INSTALL_TARGET = YES

#LIBGPHOTO2_CONF_OPTS = --enable-static --enable-shared --disable-rpath

LIBGPHOTO2_LICENSE = LGPLv2.1+
LIBGPHOTO2_LICENSE_FILES = COPYING

LIBGPHOTO2_DEPENDENCIES = libusb-compat libusb libtool libxml2

#define LIBGPHOTO2_EXTRACT_CMDS
#	tar zxvf $(DL_DIR)/$(LIBGPHOTO2_SOURCE) -C $(@D)
#endef

$(eval $(autotools-package))
