#############################################################
#
# libunistring
#
#############################################################
LIBUNISTRING_VERSION = 0.9.3
LIBUNISTRING_SOURCE = libunistring-$(LIBUNISTRING_VERSION).tar.gz
LIBUNISTRING_SITE = http://ftp.gnu.org/gnu/libunistring/libunistring-0.9.3.tar.gz
LIBUNISTRING_INSTALL_STAGING = YES
FORKED_DAAPD_INSTALL_TARGET = YES

define LIBUNISTRING_EXTRACT_CMDS
	tar zxvf $(DL_DIR)/$(LIBUNISTRING_SOURCE) -C $(@D)
endef



$(eval $(autotools-package))

