#############################################################
#
# tre
#
#############################################################
TRE_VERSION = 0.8.0
TRE_SOURCE = tre-$(TRE_VERSION).tar.gz
TRE_SITE = http://linux.softpedia.com/get/Programming/Libraries/TRE-11116.shtml
TRE_INSTALL_STAGING = YES
TRE_INSTALL_TARGET = YES

define TRE_EXTRACT_CMDS
	tar zxvf $(DL_DIR)/$(TRE_SOURCE) -C $(@D)
endef


$(eval $(autotools-package))

