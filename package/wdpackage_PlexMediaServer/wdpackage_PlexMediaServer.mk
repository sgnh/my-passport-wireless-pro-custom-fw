WDPACKAGE_PLEXMEDIASERVER_VERSION = 0.9.16.3.1840-cece46d
WDPACKAGE_PLEXMEDIASERVER_SOURCE = plexmediaserver-$(WDPACKAGE_PLEXMEDIASERVER_VERSION).tar.gz

ifeq ($(BR2_PACKAGE_WDPACKAGE_PLEXMEDIASERVER_INSTALL_PACKAGE),y)

define WDPACKAGE_PLEXMEDIASERVER_EXTRACT_CMDS
	mkdir -p $(TARGET_DIR)/usr/local/sbin/packages
	cp -a package/wdpackage_PlexMediaServer/plexmediaserver-install.sh $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver-install.sh
	chmod 775 $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver-install.sh
	cp -a package/wdpackage_PlexMediaServer/plexmediaserver-postinstall.sh $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver-postinstall.sh
	chmod 775 $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver-postinstall.sh
	cp -a package/wdpackage_PlexMediaServer/plexmediaserver-uninstall.sh $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver-uninstall.sh
	chmod 775 $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver-uninstall.sh
	mkdir -p $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver
	cp -a package/wdpackage_PlexMediaServer/plexmediaserver.sh $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver/plexmediaserver.sh 
	chmod 775 $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver/plexmediaserver.sh 
	cp package/wdpackage_PlexMediaServer/S80plexmediaserver $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver/S80plexmediaserver
	chmod 775 $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver/S80plexmediaserver
	cp package/wdpackage_PlexMediaServer/primax-plexmediaserver.service $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver/primax-plexmediaserver.service
	chmod 664 $(TARGET_DIR)/usr/local/sbin/packages/plexmediaserver/primax-plexmediaserver.service
	cp package/wdpackage_PlexMediaServer/plexfwupdate.conf $(TARGET_DIR)/etc/plexfwupdate.conf
endef

else

define WDPACKAGE_PLEXMEDIASERVER_EXTRACT_CMDS
	mkdir -p $(TARGET_DIR)/usr/local
	tar xvfz $(DL_DIR)/$(WDPACKAGE_PLEXMEDIASERVER_SOURCE) -C $(TARGET_DIR)/usr/local/
	mv $(TARGET_DIR)/usr/local/plexmediaserver-$(WDPACKAGE_PLEXMEDIASERVER_VERSION) $(TARGET_DIR)/usr/local/plexmediaserver
	cp -a package/wdpackage_PlexMediaServer/plexmediaserver.sh $(TARGET_DIR)/usr/local/plexmediaserver/
	chmod 775 $(TARGET_DIR)/usr/local/plexmediaserver/plexmediaserver.sh
	mkdir -p  $(TARGET_DIR)/home/root
	ln -sf /media/sdb1/.wdcache/.plexmediaserver $(TARGET_DIR)/usr/local/plexmediaserver/Library
	mkdir -p $(TARGET_DIR)/lib
	ln -sf ld-linux-armhf.so.3 $(TARGET_DIR)/lib/ld-linux.so.3
endef

define WDPACKAGE_PLEXMEDIASERVER_INSTALL_INIT_SYSV
	[ ! -f $(TARGET_DIR)/etc/init.d/S80plexmediaserver ] || \
		rm $(TARGET_DIR)/etc/init.d/S80plexmediaserver ; 
	$(INSTALL) -D -m 755 package/wdpackage_PlexMediaServer/S80plexmediaserver \
		$(TARGET_DIR)/etc/init.d/S80plexmediaserver ;
endef

define WDPACKAGE_PLEXMEDIASERVER_INSTALL_INIT_SYSTEMD
	[ ! -f $(TARGET_DIR)/etc/init.d/S80plexmediaserver ] || \
		rm $(TARGET_DIR)/etc/init.d/S80plexmediaserver ; 
	$(INSTALL) -D -m 755 package/wdpackage_PlexMediaServer/S80plexmediaserver \
		$(TARGET_DIR)/etc/init.d/S80plexmediaserver ;
	$(INSTALL) -m 0644 -D package/wdpackage_PlexMediaServer/primax-plexmediaserver.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-plexmediaserver.service
endef

endif

define WDPACKAGE_PLEXMEDIASERVER_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/usr/local/plexmediaserver
endef

$(eval $(generic-package))                              
