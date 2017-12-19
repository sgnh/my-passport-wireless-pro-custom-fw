#############################################################
#
# default settings
#
#############################################################

PMXPACKAGE_DEFAULTSETTINGS_VERSION = 0.0.1
PMXPACKAGE_DEFAULTSETTINGS_SITE_METHOD = local
PMXPACKAGE_DEFAULTSETTINGS_SITE = $(TOPDIR)/project/prjPackages/defaultsettings

define PMXPACKAGE_DEFAULTSETTINGS_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_DEFAULTSETTINGS_SOURCE)/* $(@D)
endef

define PMXPACKAGE_DEFAULTSETTINGS_BUILD_CMDS
endef

define PMXPACKAGE_DEFAULTSETTINGS_INSTALL_TARGET_CMDS
     mkdir -p $(TARGET_DIR)/etc/default
	 cp -a $(@D)/* $(TARGET_DIR)/etc/default
endef

$(eval $(generic-package))
