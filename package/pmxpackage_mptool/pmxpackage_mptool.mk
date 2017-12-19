#############################################################
#
# mptool 
#
#############################################################

PMXPACKAGE_MPTOOL_VERSION = 0.0.1
PMXPACKAGE_MPTOOL_SITE_METHOD = local
PMXPACKAGE_MPTOOL_SITE = $(TOPDIR)/project/prjPackages/mptool

define PMXPACKAGE_MPTOOL_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_MPTOOL_SOURCE)/* $(@D)
endef

define PMXPACKAGE_MPTOOL_INSTALL_TARGET_CMDS
	cp -a $(@D)/mptool $(TARGET_DIR)/sbin/
endef

$(eval $(generic-package))
