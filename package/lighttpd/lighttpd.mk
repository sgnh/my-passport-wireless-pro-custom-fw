################################################################################
#
# lighttpd
#
################################################################################

LIGHTTPD_VERSION_MAJOR = 1.4
LIGHTTPD_VERSION = $(LIGHTTPD_VERSION_MAJOR).35
LIGHTTPD_SOURCE = lighttpd-$(LIGHTTPD_VERSION).tar.xz
LIGHTTPD_SITE = http://download.lighttpd.net/lighttpd/releases-$(LIGHTTPD_VERSION_MAJOR).x
LIGHTTPD_LICENSE = BSD-3c
LIGHTTPD_LICENSE_FILES = COPYING
LIGHTTPD_DEPENDENCIES = host-pkgconf
LIGHTTPD_CONF_OPTS = \
	--libdir=/usr/lib/lighttpd \
	--libexecdir=/usr/lib \
	$(if $(BR2_LARGEFILE),,--disable-lfs)

ifeq ($(BR2_PACKAGE_LIGHTTPD_OPENSSL),y)
LIGHTTPD_DEPENDENCIES += openssl
LIGHTTPD_CONF_OPTS += --with-openssl
else
LIGHTTPD_CONF_OPTS += --without-openssl
endif

ifeq ($(BR2_PACKAGE_LIGHTTPD_ZLIB),y)
LIGHTTPD_DEPENDENCIES += zlib
LIGHTTPD_CONF_OPTS += --with-zlib
else
LIGHTTPD_CONF_OPTS += --without-zlib
endif

ifeq ($(BR2_PACKAGE_LIGHTTPD_BZIP2),y)
LIGHTTPD_DEPENDENCIES += bzip2
LIGHTTPD_CONF_OPTS += --with-bzip2
else
LIGHTTPD_CONF_OPTS += --without-bzip2
endif

ifeq ($(BR2_PACKAGE_LIGHTTPD_PCRE),y)
LIGHTTPD_CONF_ENV = PCRECONFIG=$(STAGING_DIR)/usr/bin/pcre-config
LIGHTTPD_DEPENDENCIES += pcre
LIGHTTPD_CONF_OPTS += --with-pcre
else
LIGHTTPD_CONF_OPTS += --without-pcre
endif

ifeq ($(BR2_PACKAGE_LIGHTTPD_WEBDAV),y)
LIGHTTPD_DEPENDENCIES += libxml2 sqlite
LIGHTTPD_CONF_OPTS += --with-webdav-props --with-webdav-locks
else
LIGHTTPD_CONF_OPTS += --without-webdav-props --without-webdav-locks
endif

ifeq ($(BR2_PACKAGE_LIGHTTPD_LUA),y)
LIGHTTPD_DEPENDENCIES += lua
LIGHTTPD_CONF_OPTS += --with-lua
else
LIGHTTPD_CONF_OPTS += --without-lua
endif

define LIGHTTPD_INSTALL_CONFIG
	$(INSTALL) -d -m 0755 $(TARGET_DIR)/etc/lighttpd/conf.d
	$(INSTALL) -d -m 0755 $(TARGET_DIR)/var/www
	$(INSTALL) -D -m 0644 $(@D)/doc/config/lighttpd.conf \
		$(TARGET_DIR)/etc/lighttpd/lighttpd.conf
	$(INSTALL) -D -m 0644 $(@D)/doc/config/modules.conf \
		$(TARGET_DIR)/etc/lighttpd/modules.conf
	$(INSTALL) -D -m 0644 $(@D)/doc/config/conf.d/access_log.conf \
		$(TARGET_DIR)/etc/lighttpd/conf.d/access_log.conf
	$(INSTALL) -D -m 0644 $(@D)/doc/config/conf.d/debug.conf \
		$(TARGET_DIR)/etc/lighttpd/conf.d/debug.conf
	$(INSTALL) -D -m 0644 $(@D)/doc/config/conf.d/dirlisting.conf \
		$(TARGET_DIR)/etc/lighttpd/conf.d/dirlisting.conf
	$(INSTALL) -D -m 0644 $(@D)/doc/config/conf.d/mime.conf \
		$(TARGET_DIR)/etc/lighttpd/conf.d/mime.conf
	$(INSTALL) -D -m 755 package/lighttpd/fastcgi.conf \
		$(TARGET_DIR)/etc/lighttpd/conf.d/fastcgi.conf
	mkdir -p $(TARGET_DIR)/var/www/test/ && \
		$(INSTALL) -D -m 755 package/lighttpd/index.php \
			$(TARGET_DIR)/var/www/test/index.php
endef

LIGHTTPD_POST_INSTALL_TARGET_HOOKS += LIGHTTPD_INSTALL_CONFIG

define LIGHTTPD_INSTALL_INIT_SYSV
	[ -f $(TARGET_DIR)/etc/init.d/S50lighttpd ] || \
		$(INSTALL) -D -m 755 package/lighttpd/S50lighttpd \
			$(TARGET_DIR)/etc/init.d/S50lighttpd

	[ -f $(TARGET_DIR)/etc/lighttpd/conf.d/fastcgi.conf ] || \
		$(INSTALL) -D -m 755 package/lighttpd/fastcgi.conf \
			$(TARGET_DIR)/etc/lighttpd/conf.d/fastcgi.conf

	[ -f $(TARGET_DIR)/var/www/test/index.php ] || \
		mkdir -p $(TARGET_DIR)/var/www/test/ && \
			$(INSTALL) -D -m 755 package/lighttpd/index.php \
				$(TARGET_DIR)/var/www/test/index.php
endef

define LIGHTTPD_INSTALL_INIT_SYSTEMD
	$(INSTALL) -D -m 0755 package/lighttpd/S50lighttpd \
		$(TARGET_DIR)/etc/init.d/S50lighttpd
	$(INSTALL) -D -m 755 package/lighttpd/fastcgi.conf \
		$(TARGET_DIR)/etc/lighttpd/conf.d/fastcgi.conf

	mkdir -p $(TARGET_DIR)/var/www/test/ && \
		$(INSTALL) -D -m 755 package/lighttpd/index.php \
		$(TARGET_DIR)/var/www/test/index.php

	mkdir -p $(TARGET_DIR)/lib/systemd/system/multi-user.target.wants && \
		$(INSTALL) -D -m 644 package/lighttpd/primax-lighttpd.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-lighttpd.service
endef

define LIGHTTPD_UNINSTALL_TARGET_CMDS
	$(RM) $(TARGET_DIR)/usr/sbin/lighttpd
	$(RM) $(TARGET_DIR)/usr/sbin/lighttpd-angel
	$(RM) -r $(TARGET_DIR)/usr/lib/lighttpd
endef

$(eval $(autotools-package))
