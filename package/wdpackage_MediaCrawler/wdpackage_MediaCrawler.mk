WDPACKAGE_MEDIACRAWLER_VERSION = 3.0.3-31
WDPACKAGE_MEDIACRAWLER_RELEASE_DATE = 2017-12-15
WDPACKAGE_MEDIACRAWLER_SOURCE = wdmpserver-korra-release-$(WDPACKAGE_MEDIACRAWLER_VERSION).deb
WDPACKAGE_MEDIACRAWLER_DEPENDENCIES = wdpackage_basic

define WDPACKAGE_MEDIACRAWLER_EXTRACT_CMDS
	dpkg-deb -R $(DL_DIR)/$(WDPACKAGE_MEDIACRAWLER_SOURCE) $(TARGET_DIR)/
endef

define WDPACKAGE_MEDIACRAWLER_INSTALL_TARGET_CMDS
	#mv $(TARGET_DIR)/etc/init.d/wdmcserverd $(TARGET_DIR)/etc/init.d/S85wdmcserverd
	#mv $(TARGET_DIR)/etc/init.d/S85wdmcserverd $(TARGET_DIR)/etc/init.d/S70wdmcserverd
	chmod 755 $(TARGET_DIR)/etc/init.d/S85wdmcserverd
	chmod 755 $(TARGET_DIR)/usr/local/wdmcserver/bin/*
	cp -Ra ${STAGING_DIR}/usr/lib/libgomp.so* $(TARGET_DIR)/usr/lib/
	sed -i 's/GET_BATTERY_STATUS=.*/GET_BATTERY_STATUS=\/usr\/local\/sbin\/power_get_battery_status_performance.sh/' $(TARGET_DIR)/etc/init.d/S85wdmcserverd
	sed -i 's/MAGICK_TMPDIR=.*/MAGICK_TMPDIR=\/shares\/Storage\/.wdmc/' $(TARGET_DIR)/etc/init.d/S85wdmcserverd
	#sed -i '/export WDMC_CHILD_MEMSW_LIMIT=.*/a \\t\texport WDMC_CHILD_STACK_LIMIT=8388608' $(TARGET_DIR)/etc/init.d/S85wdmcserverd
	sed -i '/rm -f $$WDMC_NOTIFICATION_SOCKET.*/a \\t\tufraw_batch_pid=`pidof ufraw-batch`\n\t\tconvert_pid=`pidof convert`\n\t\tif [ "$${ufraw_batch_pid}" != "" ]; then\n\t\t\tkill -9 `pidof ufraw-batch`\n\t\tfi\n\t\tif [ "$${convert_pid}" != "" ]; then\n\t\t\tkill -9 `pidof convert`\n\t\tfi' $(TARGET_DIR)/etc/init.d/S85wdmcserverd
	sed -i 's/CRAWLER_.*/CRAWLER_'$(WDPACKAGE_MEDIACRAWLER_VERSION):$(WDPACKAGE_MEDIACRAWLER_RELEASE_DATE)'/' $(TARGET_DIR)/etc/version.packages
endef

define WDPACKAGE_MEDIACRAWLER_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/usr/local/wdmcserver/bin/*
	rm -f $(TARGET_DIR)/etc/nas/notify.d/wdmcserver.conf
endef

$(eval $(generic-package))
