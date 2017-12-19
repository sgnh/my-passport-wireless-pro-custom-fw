#############################################################
#
# monitor
#
#############################################################

PMXPACKAGE_MONITOR_VERSION = 0.0.1
PMXPACKAGE_MONITOR_SITE_METHOD = local
PMXPACKAGE_MONITOR_SITE = $(TOPDIR)/project/prjPackages/monitor

define PMXPACKAGE_MONITOR_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_MONITOR_SOURCE)/* $(@D)
endef

define PMXPACKAGE_MONITOR_INSTALL_TARGET_CMDS
	cp -a $(@D)/monitor $(TARGET_DIR)/bin/	
endef

$(eval $(generic-package))
