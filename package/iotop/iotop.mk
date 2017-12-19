#############################################################
#
# iotop
#
#############################################################

IOTOP_VERSION = 0.6
IOTOP_SOURCE = iotop-$(IOTOP_VERSION).tar.bz2
IOTOP_SITE = http://guichaz.free.fr/iotop/files
IOTOP_INSTALL_STAGING = YES
IOTOP_DEPENDENCIES = python
IOTOP_LICENSE = GPLv2
IOTOP_LICENSE_FILES = COPYING

define IOTOP_INSTALL_TARGET_CMDS
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) python setup.py install --prefix=$(TARGET_DIR)/usr)
	(sed -i '1,1c \'#\!\/usr\/bin\/python $(TARGET_DIR)/usr/sbin/iotop)
endef

$(eval $(generic-package))
