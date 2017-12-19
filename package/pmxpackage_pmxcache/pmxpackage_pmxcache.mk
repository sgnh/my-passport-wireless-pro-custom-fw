#############################################################
#
# pmxcache
#
#############################################################

PMXPACKAGE_PMXCACHE_VERSION = 0.0.1
PMXPACKAGE_PMXCACHE_SITE_METHOD = local
PMXPACKAGE_PMXCACHE_SITE = $(TOPDIR)/project/prjPackages/pmxcache
PMXPACKAGE_PMXCACHE_DEPENDENCIES = linux

define PMXPACKAGE_PMXCACHE_BUILD_CMDS
	 cp -Ra $(DL_DIR)/$(MXPACKAGE_PMXCACHE_SOURCE)/* $(@D)
endef

define PMXPACKAGE_PMXCACHE_INSTALL_TARGET_CMDS
	cp -a $(@D)/modules.* $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
	cp -Ra $(@D)/pmxcache $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/
	cp -a $(@D)/avtest $(TARGET_DIR)/usr/bin/
	cp -Ra $(@D)/pluginfs $(TARGET_DIR)/usr/lib/
endef

$(eval $(generic-package))
