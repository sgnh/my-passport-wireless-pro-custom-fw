###########################################################
#
## atoptools
#
############################################################

ATOP_VERSION = 1.27-3
ATOP_SITE = http://www.atoptool.nl/download/
ATOP_LICENSE = GPL
ATOP_LICENSE_FILES = COPYING
#ATOP_DEPENDS=ncurses, zlib

define ATOP_EXTRACT_CMDS
	 tar zxvf $(DL_DIR)/atop-$(ATOP_VERSION).tar.gz --strip 1 -C $(@D)
endef

define ATOP_BUILD_CMDS
	 $(MAKE) CC=$(TARGET_CC) -C $(@D)
endef

define ATOP_INSTALL_TARGET_CMDS
	cp -a $(@D)/atop $(TARGET_DIR)/bin/
endef

$(eval $(generic-package))
