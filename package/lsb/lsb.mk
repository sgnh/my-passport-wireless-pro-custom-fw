#############################################################
#
# lsb
#
#############################################################

LSB_VERSION = 4.1+Debian13+nmu1
LSB_SOURCE = lsb_$(LSB_VERSION).tar.xz
LSB_SITE = http://ftp.debian.org/debian/pool/main/l/lsb/
LSB_INSTALL_STAGING = YES
LSB_LICENSE = GPLv2
LSB_LICENSE_FILES = debian/copyright

define LSB_INSTALL_TARGET_CMDS
	$(INSTALL) -d -m 0755 $(TARGET_DIR)/lib/lsb
	(cd $(@D); chmod +x init-functions; cp init-functions $(TARGET_DIR)/lib/lsb)
	(cd $(@D); cp -a init-functions.d $(TARGET_DIR)/lib/lsb)
endef

$(eval $(generic-package))
