#############################################################
#
# ghelper 
#
#############################################################

PMXPACKAGE_GHELPER_VERSION = 0.0.1
PMXPACKAGE_GHELPER_SITE_METHOD = local
PMXPACKAGE_GHELPER_SITE = $(TOPDIR)/project/prjPackages/ghelper

define PMXPACKAGE_GHELPER_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_GHELPER_SOURCE)/* $(@D)
endef

define PMXPACKAGE_GHELPER_INSTALL_TARGET_CMDS
	cp -a $(@D)/ghelper $(TARGET_DIR)/bin/	
endef

$(eval $(generic-package))
