################################################################################
#
# apache
#
################################################################################

APACHE_VERSION = 2.4.9
APACHE_SOURCE = httpd-$(APACHE_VERSION).tar.bz2
APACHE_SITE = http://archive.apache.org/dist/httpd
APACHE_LICENSE = Apache-2.0
APACHE_LICENSE_FILES = LICENSE
# Needed for mod_php
APACHE_INSTALL_STAGING = YES
# We have a patch touching configure.in and Makefile.in,
# so we need to autoreconf:
APACHE_AUTORECONF = YES
APACHE_DEPENDENCIES = apr apr-util pcre

APACHE_CONF_ENV= \
	LIBS=-lpthread \
	ap_cv_void_ptr_lt_long=no \
	PCRE_CONFIG=$(STAGING_DIR)/usr/bin/pcre-config \
	CFLAGS+=-DBIG_SECURITY_HOLE

APACHE_CONF_OPTS = \
	--prefix=/usr/local/apache2 \
	--exec-prefix=/usr/local/apache2 \
	--sysconfdir=/etc/apache2 \
	--with-apr=$(STAGING_DIR)/usr/bin/apr-1-config \
	--with-apr-util=$(STAGING_DIR)/usr/bin/apu-1-config \
	--with-pcre=$(STAGING_DIR)/usr/bin/pcre-config \
	--enable-http \
	--enable-pie \
	--enable-dbd \
	--enable-proxy \
	--enable-mime-magic \
	--enable-rewrite \
	--without-suexec-bin \
	--enable-mods-shared=all \
	--with-mpm=prefork \
	--disable-lua \
	--disable-luajit

ifeq ($(BR2_ARCH_HAS_ATOMICS),y)
APACHE_CONF_OPTS += --enable-nonportable-atomics=yes
endif

ifeq ($(BR2_PACKAGE_LIBXML2),y)
APACHE_DEPENDENCIES += libxml2
# Apache wants the path to the header file, where it can find
# <libxml/parser.h>.
APACHE_CONF_OPTS += \
	--enable-xml2enc \
	--enable-proxy-html \
	--with-libxml2=$(STAGING_DIR)/usr/include/libxml2
else
APACHE_CONF_OPTS += \
	--disable-xml2enc \
	--disable-proxy-html
endif

ifeq ($(BR2_PACKAGE_OPENSSL),y)
APACHE_DEPENDENCIES += openssl
APACHE_CONF_OPTS += \
	--enable-ssl \
	--with-ssl=$(STAGING_DIR)/usr
else
APACHE_CONF_OPTS += --disable-ssl
endif

ifeq ($(BR2_PACKAGE_ZLIB),y)
APACHE_DEPENDENCIES += zlib
APACHE_CONF_OPTS += \
	--enable-deflate \
	--with-z=$(STAGING_DIR)/usr
else
APACHE_CONF_OPTS += --disable-deflate
endif

define APACHE_FIX_STAGING_APACHE_CONFIG
	$(SED) 's%/usr/local/apache2/build%$(STAGING_DIR)/usr/local/apache2/build%' $(STAGING_DIR)/usr/local/apache2/bin/apxs
	$(SED) 's%^prefix =.*%prefix = $(STAGING_DIR)/usr/local/apache2%' $(STAGING_DIR)/usr/local/apache2/build/config_vars.mk
	#$(SED) 's%/usr/build%$(STAGING_DIR)/usr/build%' $(STAGING_DIR)/usr/bin/apxs
	#$(SED) 's%^prefix =.*%prefix = $(STAGING_DIR)/usr%' $(STAGING_DIR)/usr/build/config_vars.mk
endef
APACHE_POST_INSTALL_STAGING_HOOKS += APACHE_FIX_STAGING_APACHE_CONFIG


ifeq ($(BR2_PACKAGE_APACHE_EXT_MOD_XSENDFILE),y)
define APACHE_BUILD_MOD_XSENDFILE_CMDS
	$(TARGET_MAKE_ENV)
	$(HOST_DIR)/usr/arm-buildroot-linux-gnueabihf/sysroot/usr/local/apache2/bin/apxs -ca $(@D)/modules/xsendfile/mod_xsendfile.c
	cp $(@D)/modules/xsendfile/.libs/mod_xsendfile.so $(TARGET_DIR)/usr/local/apache2/modules/
endef
endif

APACHE_POST_INSTALL_TARGET_HOOKS += APACHE_BUILD_MOD_XSENDFILE_CMDS

define APACHE_CLEANUP_TARGET
	$(RM) -rf $(TARGET_DIR)/usr/local/apache2/manual $(TARGET_DIR)/usr/local/apache2/build
endef
APACHE_POST_INSTALL_TARGET_HOOKS += APACHE_CLEANUP_TARGET

define APACHE_INSTALL_INIT_SYSTEMD
	#$(INSTALL) -D -m 755 package/apache/S51apache2 \
	#	$(TARGET_DIR)/etc/init.d/S51apache2

	$(INSTALL) -D -m 755 package/apache/httpd.conf.wd \
		$(TARGET_DIR)/etc/apache2/httpd.conf
	
	$(INSTALL) -D -m 755 package/apache/httpd.conf.wd \
		$(TARGET_DIR)/etc/apache2/httpd.conf.bak
		
	$(INSTALL) -D -m 755 package/apache/certificate_https_all.pem \
		$(TARGET_DIR)/etc/apache2/certificate_https_all.pem
		
	$(INSTALL) -D -m 755 package/apache/httpd-captiveportal.conf \
		$(TARGET_DIR)/etc/apache2/extra/httpd-captiveportal.conf
	#mkdir -p $(TARGET_DIR)/lib/systemd/system/multi-user.target.wants && \
	#$(INSTALL) -D -m 644 package/apache/primax-apache.service \
	#	$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-apache.service
endef

$(eval $(autotools-package))
