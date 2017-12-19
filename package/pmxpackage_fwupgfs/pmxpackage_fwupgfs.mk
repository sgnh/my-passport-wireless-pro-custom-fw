PMXPACKAGE_FWUPGFS_SITE_METHOD = local
PMXPACKAGE_FWUPGFS_SITE = $(TOPDIR)/project/prjPackages/fwupgfs

define PMXPACKAGE_FWUPGFS_EXTRACT_CMDS
	cp -Ra $(DL_DIR)/$(PMXPACKAGE_FWUPGFS_SOURCE)/* $(@D)
endef

define PMXPACKAGE_FWUPGFS_INSTALL_TARGET_CMDS
		$(INSTALL) -D -m 755 package/wdpackage_basic/version \
		$(TARGET_DIR)/etc/version
		$(INSTALL) -D -m 755 $(@D)/etc/S01init \
		$(TARGET_DIR)/etc/init.d/S01init
		$(INSTALL) -D -m 755 $(@D)/etc/S99fwupg \
		$(TARGET_DIR)/etc/init.d/S99fwupg
		$(INSTALL) -D -m 755 $(@D)/sbin/fwupgled.sh \
		$(TARGET_DIR)/sbin/fwupgled.sh
		$(INSTALL) -D -m 755 $(@D)/sbin/fwupgledoff.sh \
		$(TARGET_DIR)/sbin/fwupgledoff.sh

endef

define PMXPACKAGE_FWUPGFS_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/etc/etc/S01init
	rm -f $(TARGET_DIR)/etc/init.d/S99fwupg
	rm -f $(TARGET_DIR)/sbin/fwupgled.sh
	rm -f $(TARGET_DIR)/sbin/fwupgledoff.sh

endef

$(eval $(generic-package))
