#############################################################
#
# asmupdate 
#
#############################################################

PMXPACKAGE_FWDESCRIPTOR_VERSION = 0.0.1
PMXPACKAGE_FWDESCRIPTOR_SITE_METHOD = local
PMXPACKAGE_FWDESCRIPTOR_SITE = $(TOPDIR)/project/prjPackages/fwdescriptor

define PMXPACKAGE_FWDESCRIPTOR_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_FWDESCRIPTOR_SOURCE)/* $(@D)
endef

define PMXPACKAGE_FWDESCRIPTOR_INSTALL_TARGET_CMDS
	cp -a $(@D)/fwdescriptor $(TARGET_DIR)/sbin/
	mkdir -p ${BINARIES_DIR}/bin
	cp -a $(@D)/fwdescriptor ${BINARIES_DIR}/bin/
endef

$(eval $(generic-package))
