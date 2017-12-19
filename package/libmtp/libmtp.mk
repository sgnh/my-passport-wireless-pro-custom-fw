############################################################
#
# libmtp
#
###########################################################

LIBMTP_VERSION = 1.1.12
LIBMTP_SITE = http://sourceforge.net/projects/libmtp/files/latest/download
LIBMTP_SOURCE = libmtp-$(LIBMTP_VERSION).tar.gz 
LIBMTP_DIR = $(BUILD_DIR)/libmtp-$(LIBMTP_VERSION)

LIBMTP_INSTALL_STAGING = YES
LIBMTP_INSTALL_TARGET = YES

LIBMTP_LICENSE = LGPLv2.1
LIBMTP_LICENSE_FILES = COPYING

LIBMTP_DEPENDENCIES = libusb libtool
#LIBMTP_CONF_ENV = LIBS="-lusb"
LIBMTP_CONF_OPTS = --with-udev=/lib/udev

#define LIBMTP_EXTRACT_CMDS
#	tar zxvf $(DL_DIR)/$(LIBMTP_SOURCE) -C $(@D)
	#chown root:root -R $(@D)
	#cp -a package/libmtp/69-libmtp.rules $(LIBMTP_DIR)/
	#cp -a package/libmtp/libmtp.usermap $(LIBMTP_DIR)/
	#cp -a package/libmtp/libmtp.fdi $(LIBMTP_DIR)/
	#cp -a $(LIBMTP_DIR)/src/.mtpz-data $(TARGET_DIR)/usr/lib/
#endef

#define LIBMTP_INSTALL_TARGET_CMDS
#	cp -a $(LIBMTP_DIR)/src/.mtpz-data $(TARGET_DIR)/usr/lib/
#endef

$(eval $(autotools-package))
