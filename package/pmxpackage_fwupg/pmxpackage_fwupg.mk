#############################################################
#
# fwupg 
#
#############################################################

PMXPACKAGE_FWUPG_VERSION = 0.0.1
PMXPACKAGE_FWUPG_SITE_METHOD = local
PMXPACKAGE_FWUPG_SITE = $(TOPDIR)/project/prjPackages/fwupg

define PMXPACKAGE_FWUPG_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_FWUPG_SOURCE)/* $(@D)
endef

define PMXPACKAGE_FWUPG_INSTALL_TARGET_CMDS
	cp -a $(@D)/S99fwupg $(TARGET_DIR)/etc/init.d/
	cp -a $(@D)/S01logging $(TARGET_DIR)/etc/init.d/
	cp -a $(@D)/S10mdev $(TARGET_DIR)/etc/init.d/
	cp -a $(@D)/fwupgled.sh $(TARGET_DIR)/sbin/
endef

$(eval $(generic-package))
