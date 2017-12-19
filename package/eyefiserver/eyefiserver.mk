#############################################################
#
# eyefiserver
#
#############################################################

EYEFISERVER_VERSION = 0.0.1
EYEFISERVER_SITE = https://eyefiserver.googlecode.com/
EYEFISERVER_SOURCE = eyefiserver-$(EYEFISERVER_VERSION).tgz
EYEFISERVER_LICENSE = GPL v3

define EYEFISERVER_INSTALL_TARGET_CMDS
	mkdir -p $(TARGET_DIR)/usr/local/bin/
	rm -rf ${@D}/var/
	mv $(@D)/etc/init.d/eyefiserver $(@D)/etc/init.d/S99eyefiserver
	cp -a $(@D)/. $(TARGET_DIR)/
endef

$(eval $(generic-package))
