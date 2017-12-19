WDPACKAGE_DISPATCHER_VERSION = 1.0.2-20140224.214525-3
WDPACKAGE_DISPATCHER_SOURCE = wddispatcher-av-$(WDPACKAGE_DISPATCHER_VERSION).deb

define WDPACKAGE_DISPATCHER_EXTRACT_CMDS
	dpkg-deb -R $(DL_DIR)/$(WDPACKAGE_DISPATCHER_SOURCE) $(TARGET_DIR)/
endef

define WDPACKAGE_DISPATCHER_INSTALL_TARGET_CMDS
	mv $(TARGET_DIR)/etc/init.d/wddispatcherd $(TARGET_DIR)/etc/init.d/S91wddispatcherd
	chmod 755 $(TARGET_DIR)/etc/init.d/S91wddispatcherd
	chmod 755 $(TARGET_DIR)/usr/local/bin/wddispatcher
endef

define WDPACKAGE_DISPATCHER_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/etc/init.d/S91wddispatcherd
	rm -f $(TARGET_DIR)/etc/nas/notify.d/wddispatcher.conf
	rm -f $(TARGET_DIR)/etc/nas/rsyslog.d/wddispatcher.conf
	rm -f $(TARGET_DIR)/usr/local/bin/wddispatcher
endef

$(eval $(generic-package))
