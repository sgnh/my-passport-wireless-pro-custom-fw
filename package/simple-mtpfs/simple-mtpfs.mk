############################################################
#
# simple-mtpfs
#
###########################################################

SIMPLE_MTPFS_VERSION = 0.2
SIMPLE_MTPFS_SITE = https://github.com/phatina/simple-mtpfs
SIMPLE_MTPFS_SOURCE = simple-mtpfs-$(SIMPLE_MTPFS_VERSION).tar.gz 
SIMPLE_MTPFS_DIR = $(BUILD_DIR)/simple-mtpfs-$(SIMPLE_MTPFS_VERSION)

SIMPLE_MTPFS_INSTALL_STAGING = YES
SIMPLE_MTPFS_INSTALL_TARGET = YES
SIMPLE_MTPFS_AUTORECONF = YES
SIMPLE_MTPFS_CONF_OPTS = --with-tmpdir=/media/sdb1/.wdcache/

SIMPLE_MTPFS_LICENSE = GPLv2
SIMPLE_MTPFS_LICENSE_FILES = COPYING

SIMPLE_MTPFS_DEPENDENCIES = libusb libmtp
	
#SIMPLE_MTPFS_CONF_ENV = MAD_LIBS="-lmad" MAD_CFLAGS=" " LIBS="-lid3tag"

define SIMPLE_MTPFS_EXTRACT_CMDS
	tar zxvf $(DL_DIR)/$(SIMPLE_MTPFS_SOURCE) -C $(@D)
endef



$(eval $(autotools-package))
