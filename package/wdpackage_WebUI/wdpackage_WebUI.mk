WDPACKAGE_WEBUI_VERSION = 1.4.0-229
WDPACKAGE_WEBUI_RELEASE_DATE = 2016-12-13
WDPACKAGE_WEBUI_SOURCE = ui-$(WDPACKAGE_WEBUI_VERSION).deb

define WDPACKAGE_WEBUI_EXTRACT_CMDS
	dpkg-deb -R $(DL_DIR)/$(WDPACKAGE_WEBUI_SOURCE) $(TARGET_DIR)/
	rm -Rf $(TARGET_DIR)/DEBIAN
	sed -i 's/UI_.*/UI_'$(WDPACKAGE_WEBUI_VERSION):$(WDPACKAGE_WEBUI_RELEASE_DATE)'/' $(TARGET_DIR)/etc/version.packages
	#chmod 755 $(TARGET_DIR)/usr/local/sbin/doDeviceSpecific.sh
	#java -jar yuicompressor-2.4.6.jar --type css -o aggregate.css aggregate_patch.css
	#java -jar yuicompressor-2.4.6.jar --type js -o aggregate.js aggregate_patch.js
	cp -a package/wdpackage_WebUI/aggregate.js $(TARGET_DIR)/var/www/UI/js/aggregate.js
	cp -a package/wdpackage_WebUI/aggregate.css $(TARGET_DIR)/var/www/UI/css/aggregate.css
	cp -a package/wdpackage_WebUI/dictionary.php $(TARGET_DIR)/var/www/UI/js/dictionary.php
	
	cp -a package/wdpackage_WebUI/detect-source $(TARGET_DIR)/var/www/
	cp -a package/wdpackage_WebUI/index.php $(TARGET_DIR)/var/www/index.php
	cp -a package/wdpackage_WebUI/indexOrigin.php $(TARGET_DIR)/var/www/indexOrigin.php
	cp -a package/wdpackage_WebUI/indexSuccess.php $(TARGET_DIR)/var/www/indexSuccess.php
	cp -a package/wdpackage_WebUI/success.html $(TARGET_DIR)/var/www/success.html
	cp -a package/wdpackage_WebUI/generate_204 $(TARGET_DIR)/var/www/generate_204
	#cp -a package/wdpackage_WebUI/ssh.php $(TARGET_DIR)/var/www/UI/views/access/partial/ssh.php
	#cp -a package/wdpackage_WebUI/ssh_confirmation.php $(TARGET_DIR)/var/www/UI/views/settings/partial/popups/ssh_confirmation.php
	#cp -a package/wdpackage_WebUI/wifi_settings_5.php $(TARGET_DIR)/var/www/UI/views/wifi/partial/popups/wifi_settings_5.php
	#cp -a package/wdpackage_WebUI/wifi_settings_advanced.php $(TARGET_DIR)/var/www/UI/views/wifi/partial/popups/wifi_settings_advanced.php
endef

define WDPACKAGE_RESTAPI_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/var/local/bin
	rm -f $(TARGET_DIR)/var/local/sbin
endef

$(eval $(generic-package))
