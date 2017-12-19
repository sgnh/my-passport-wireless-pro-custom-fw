#############################################################
#
# libupnp
#
#############################################################

LIBUPNP_VERSION = 1.6.6
LIBUPNP_SOURCE = libupnp-$(LIBUPNP_VERSION).tar.bz2
LIBUPNP_SITE = http://downloads.sourceforge.net/project/pupnp/pupnp/libUPnP%20$(LIBUPNP_VERSION)
LIBUPNP_CONF_ENV = ac_cv_lib_compat_ftime=no
LIBUPNP_INSTALL_STAGING = YES

define LIBUPNP_INSTALL_TARGET_CMDS
	cp -a $(@D)/upnp/.libs/libupnp.so* $(TARGET_DIR)/lib/
	cp -a $(@D)/threadutil/.libs/libthreadutil.so* $(TARGET_DIR)/lib/
	cp -a $(@D)/ixml/.libs/libixml.so* $(TARGET_DIR)/lib/

	if [ ! -d $(TARGET_DIR)/usr/local/upnp ]; then \
		mkdir -p $(TARGET_DIR)/usr/local/upnp; \
		cp -a $(@D)/upnp/sample/upnp_nas_device $(TARGET_DIR)/usr/local/upnp/; \
		cp -Rf $(@D)/upnp/sample/web $(TARGET_DIR)/usr/local/upnp/web_wlan1; \
		cp -a package/libupnp/nasdevicedesc*.xml $(TARGET_DIR)/usr/local/upnp/web_wlan1/; \
	fi
	
	if [ ! -f $(TARGET_DIR)/etc/init.d/S91upnp ]; then \
		$(INSTALL) -m 0755 -D package/libupnp/S91upnp $(TARGET_DIR)/etc/init.d/S91upnp; \
	fi

endef

$(eval $(autotools-package))
