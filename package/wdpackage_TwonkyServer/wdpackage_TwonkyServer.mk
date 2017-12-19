WDPACKAGE_TWONKYSERVER_VERSION = 7.3.1-84
WDPACKAGE_TWONKYSERVER_SOURCE = western-digital-korra-oem-$(WDPACKAGE_TWONKYSERVER_VERSION).zip

define WDPACKAGE_TWONKYSERVER_EXTRACT_CMDS
	mkdir -p $(TARGET_DIR)/usr/local/twonkymedia-7
	unzip -o $(DL_DIR)/$(WDPACKAGE_TWONKYSERVER_SOURCE) -d $(TARGET_DIR)/usr/local/twonkymedia-7
	cp -Ra package/wdpackage_TwonkyServer/WD_patched/* $(TARGET_DIR)/usr/local/twonkymedia-7/
	find $(TARGET_DIR)/usr/local/twonkymedia-7 -name .svn -type d | xargs -n 1 rm -rf
	rm -f  $(TARGET_DIR)/usr/local/twonkymedia-7/cgi-bin/convert-readme.txt
	mkdir -p $(TARGET_DIR)/usr/var/twonky
	mkdir -p $(TARGET_DIR)/var/twonky/twonkyserver
endef

define WDPACKAGE_TWONKYSERVER_INSTALL_INIT_SYSV
	[ ! -f $(TARGET_DIR)/etc/init.d/S80twonkyserver ] || \
		rm $(TARGET_DIR)/etc/init.d/S80twonkyserver ; 
	$(INSTALL) -D -m 755 package/wdpackage_TwonkyServer/S80twonkyserver \
		$(TARGET_DIR)/etc/init.d/S80twonkyserver ;
endef

define WDPACKAGE_TWONKYSERVER_INSTALL_INIT_SYSTEMD
	[ ! -f $(TARGET_DIR)/etc/init.d/S80twonkyserver ] || \
		rm $(TARGET_DIR)/etc/init.d/S80twonkyserver ; 
	$(INSTALL) -D -m 755 package/wdpackage_TwonkyServer/S80twonkyserver \
		$(TARGET_DIR)/etc/init.d/S80twonkyserver ;

	$(INSTALL) -m 0644 -D package/wdpackage_TwonkyServer/primax-twonkyserver.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-twonkyserver.service
endef

define WDPACKAGE_TWONKYSERVER_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/var/local/twonkymedia-7
endef

$(eval $(generic-package))
