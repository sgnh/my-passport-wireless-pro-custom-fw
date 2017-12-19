#############################################################
#
# rtkpackage paragon 
#
#############################################################

RTKPACKAGE_PARAGON_VERSION = k3.10.24_2014-10-29_lke_9.2.0_r249691_b39
RTKPACKAGE_PARAGON_SITE_METHOD = local
RTKPACKAGE_PARAGON_SITE = $(TOPDIR)/project/prjPackages/realtek_paragon
RTKPACKAGE_PARAGON_DEPENDENCIES = linux 

define RTKPACKAGE_PARAGON_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(RTKPACKAGE_PARAGON_SOURCE)/* $(@D)
endef

define RTKPACKAGE_PARAGON_INSTALL_TARGET_CMDS
	mkdir -p $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/kernel/external/ufsd
	cp -a $(@D)/jnl.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/kernel/external/ufsd/
	cp -a $(@D)/ufsd.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/kernel/external/ufsd/
	$(MAKE) -C $(LINUX_DIR) $(LINUX_MAKE_FLAGS) M=$(@D) \
		INSTALL_MOD_STRIP=1 INSTALL_MOD_DIR=/kernel/external/ufsd \
		modules_install
	$(INSTALL) -m 0755 -D $(WDPACKAGE_BASIC_SITE)/etc/init.d/S09paragonfs \
		$(TARGET_DIR)/etc/init.d/S09paragonfs
endef

$(eval $(generic-package))
