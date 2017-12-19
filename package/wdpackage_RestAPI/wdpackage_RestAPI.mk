WDPACKAGE_RESTAPI_VERSION = 2.7.2-84
WDPACKAGE_RESTAPI_RELEASE_DATE = 2016-11-03
WDPACKAGE_RESTAPI_SOURCE = admin-rest-api-$(WDPACKAGE_RESTAPI_VERSION).deb

define WDPACKAGE_RESTAPI_EXTRACT_CMDS
	dpkg-deb -R $(DL_DIR)/$(WDPACKAGE_RESTAPI_SOURCE) $(TARGET_DIR)/
endef

define WDPACKAGE_RESTAPI_INSTALL_TARGET_CMDS
	ln -sf /var/www/rest-api/api/Filesystem/src/Filesystem/Cli/volume_mount.php $(TARGET_DIR)/usr/local/sbin/volume_mount.sh
	ln -sf /var/www/rest-api/api/Storage/src/Storage/Transfer/Cli/storage_transfer_job_start.php $(TARGET_DIR)/usr/local/sbin/storage_transfer_job_start.sh
	chmod 775 $(TARGET_DIR)/var/www/rest-api/api/Storage/src/Storage/Transfer/Cli/storage_transfer_job_start.php
	chmod 775 $(TARGET_DIR)/var/www/rest-api/api/Filesystem/src/Filesystem/Cli/volume_mount.php
	ln -sf /var/www/rest-api/api/Shares/src/Shares/Cli/crud_share_db.php $(TARGET_DIR)/usr/local/sbin/crud_share_db.sh
	chmod 775 $(TARGET_DIR)/var/www/rest-api/api/Shares/src/Shares/Cli/crud_share_db.php
	chmod 775 $(TARGET_DIR)/var/www/rest-api/api/Jobs/src/Jobs/Cli/jobs_clean_up.php
	mkdir -p  $(TARGET_DIR)/usr/local/nas/orion/
	mkdir -p  $(TARGET_DIR)/usr/local/orion/crawlersettings/
	echo "1" > $(TARGET_DIR)/usr/local/orion/crawlersettings/ExternalVolumeMediaView
	rm -Rf $(TARGET_DIR)/DEBIAN
	find  $(TARGET_DIR)/var/www/rest-api -name tests -type d | xargs -n 1 rm -rf
	sed -i 's/RESTAPI_.*/RESTAPI_'$(WDPACKAGE_RESTAPI_VERSION):$(WDPACKAGE_RESTAPI_RELEASE_DATE)'/' $(TARGET_DIR)/etc/version.packages
	$(INSTALL) -D -m 755 package/wdpackage_RestAPI/S95RestAPI $(TARGET_DIR)/etc/init.d/S95RestAPI
	mkdir -p $(TARGET_DIR)/etc/nas/volume_config
	$(INSTALL) -D -m 644 package/wdpackage_RestAPI/data_volume.conf $(TARGET_DIR)/etc/nas/volume_config/data_volume.conf
	
	cp -a package/wdpackage_RestAPI/fileputworker.inc $(TARGET_DIR)/var/www/rest-api/api/Filesystem/includes/fileputworker.inc
	cp -a package/wdpackage_RestAPI/contents.inc $(TARGET_DIR)/var/www/rest-api/api/Filesystem/includes/contents.inc
	cp -a package/wdpackage_RestAPI/SshConfiguration.php $(TARGET_DIR)/var/www/rest-api/api/System/includes/SshConfiguration.php
	cp -a package/wdpackage_RestAPI/StorageActiveTransfer.php $(TARGET_DIR)/var/www/rest-api/api/Storage/src/Storage/Transfer/Controller/StorageActiveTransfer.php
	cp -a package/wdpackage_RestAPI/JobManager.php $(TARGET_DIR)/var/www/rest-api/api/Jobs/src/Jobs/JobManager.php
endef

define WDPACKAGE_RESTAPI_INSTALL_INIT_SYSV
		$(INSTALL) -D -m 755 package/wdpackage_RestAPI/S95RestAPI $(TARGET_DIR)/etc/init.d/S95RestAPI
endef

define WDPACKAGE_RESTAPI_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/var/local/bin
	rm -f $(TARGET_DIR)/var/local/sbin
endef

$(eval $(generic-package))
