#############################################################
#
# hiddenFile 
#
#############################################################

PMXPACKAGE_HIDDENFILE_VERSION = 0.0.1
PMXPACKAGE_HIDDENFILE_SITE_METHOD = local
PMXPACKAGE_HIDDENFILE_SITE = $(TOPDIR)/project/prjPackages/hiddenFile

define PMXPACKAGE_HIDDENFILE_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_HIDDENFILE_SOURCE)/* $(@D)
endef

define PMXPACKAGE_HIDDENFILE_INSTALL_TARGET_CMDS
	cp -a $(@D)/hiddenFile $(TARGET_DIR)/sbin/
endef

$(eval $(generic-package))
