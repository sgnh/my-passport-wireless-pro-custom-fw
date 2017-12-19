#############################################################
#
# SCSIGETCID 
#
#############################################################

PMXPACKAGE_SCSIGETCID_VERSION = 0.0.1
PMXPACKAGE_SCSIGETCID_SITE_METHOD = local
PMXPACKAGE_SCSIGETCID_SITE = $(TOPDIR)/project/prjPackages/scsiGetCID

define PMXPACKAGE_SCSIGETCID_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_SCSIGETCID_SOURCE)/* $(@D)
endef

define PMXPACKAGE_SCSIGETCID_INSTALL_TARGET_CMDS
	cp -a $(@D)/sctool $(TARGET_DIR)/sbin/
	cp -a $(@D)/mmc_name $(TARGET_DIR)/sbin/
endef

$(eval $(generic-package))
