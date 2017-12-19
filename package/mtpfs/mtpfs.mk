############################################################
#
# mtpfs
#
###########################################################

MTPFS_VERSION = 1.1
MTPFS_SITE = http://www.adebenham.com/files/mtp/mtpfs-1.1.tar.gz
MTPFS_SOURCE = mtpfs-$(MTPFS_VERSION).tar.gz 
MTPFS_DIR = $(BUILD_DIR)/mtpfs-$(MTPFS_VERSION)

MTPFS_INSTALL_STAGING = YES
MTPFS_INSTALL_TARGET = YES
MTPFS_AUTORECONF = YES

MTPFS_DEPENDENCIES = libmad libid3tag
	
MTPFS_CONF_ENV = MAD_LIBS="-lmad" MAD_CFLAGS=" " LIBS="-lid3tag"

define MTPFS_EXTRACT_CMDS
	tar zxvf $(DL_DIR)/$(MTPFS_SOURCE) -C $(@D)
endef


$(eval $(autotools-package))
