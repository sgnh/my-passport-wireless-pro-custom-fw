#############################################################
#
# asmupdate 
#
#############################################################

PMXPACKAGE_ASMUPDATE_VERSION = 0.0.1
PMXPACKAGE_ASMUPDATE_SITE_METHOD = local
PMXPACKAGE_ASMUPDATE_SITE = $(TOPDIR)/project/prjPackages/asmupdate
ASMEDIA_FIRMWARE_VERSION = 1006-20170809

define PMXPACKAGE_ASMUPDATE_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_ASMUPDATE_SOURCE)/* $(@D)
endef

define PMXPACKAGE_ASMUPDATE_INSTALL_TARGET_CMDS
	cp -a $(@D)/asmupdate $(TARGET_DIR)/sbin/
	ln -sf /sbin/asmupdate $(TARGET_DIR)/bin/stbtool
endef

ifeq ($(BR2_PACKAGE_PMXPACKAGE_ASMUPDATE_STATIC),y)
define PMXPACKAGE_ASMUPDATE_INCLUDE_STATIC
	mkdir -p ${BINARIES_DIR}/bin
	cp -a $(@D)/asmupdate-static ${BINARIES_DIR}/bin//asmupdate
endef
PMXPACKAGE_ASMUPDATE_POST_INSTALL_TARGET_HOOKS += PMXPACKAGE_ASMUPDATE_INCLUDE_STATIC
endif

ifeq ($(BR2_PACKAGE_PMXPACKAGE_RESCUEFS), y)
define PMXPACKAGE_ASMUPDATE_INCLUDE_FIRMWARE
	mkdir -p $(TARGET_DIR)/etc/firmware
	cp -f $(@D)/firmware/Release-CFU-$(ASMEDIA_FIRMWARE_VERSION).bin \
		    $(TARGET_DIR)/etc/firmware/AsmSataFw.bin ;
	cp -a $(@D)/asmupdate-rescuefs $(TARGET_DIR)/sbin/asmupdate
endef
PMXPACKAGE_ASMUPDATE_POST_INSTALL_TARGET_HOOKS += PMXPACKAGE_ASMUPDATE_INCLUDE_FIRMWARE
endif

ifeq ($(BR2_PACKAGE_PMXPACKAGE_FWUPGFS), y)
define PMXPACKAGE_ASMUPDATE_INCLUDE_FIRMWARE
	mkdir -p $(TARGET_DIR)/etc/firmware
	cp -f $(@D)/firmware/Release-CFU-$(ASMEDIA_FIRMWARE_VERSION).bin \
		    $(TARGET_DIR)/etc/firmware/ ;
	cp -a $(@D)/asmupdate-fwupgfs $(TARGET_DIR)/sbin/asmupdate
endef
PMXPACKAGE_ASMUPDATE_POST_INSTALL_TARGET_HOOKS += PMXPACKAGE_ASMUPDATE_INCLUDE_FIRMWARE
endif

$(eval $(generic-package))
