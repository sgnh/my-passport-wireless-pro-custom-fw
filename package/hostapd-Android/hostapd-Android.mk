##############################################################
#
# hostapd
#
#############################################################

HOSTAPD_ANDROID_VERSION = 2.0
HOSTAPD_ANDROID_SITE = https://android.googlesource.com/platform/external/wpa_supplicant_8/+archive/e0ae542d4106cf55a8d72c8c82561b2faf736a11.tar.gz
HOSTAPD_ANDROID_SUBDIR = hostapd
HOSTAPD_ANDROID_CONFIG = $(HOSTAPD_ANDROID_DIR)/$(HOSTAPD_ANDROID_SUBDIR)/.config
HOSTAPD_ANDROID_DEPENDENCIES = libnl
HOSTAPD_ANDROID_CFLAGS = $(TARGET_CFLAGS) -I$(STAGING_DIR)/usr/include/libnl3/
HOSTAPD_ANDROID_LDFLAGS = $(TARGET_LDFLAGS)
HOSTAPD_ANDROID_LICENSE = GPLv2/BSD-3c
HOSTAPD_ANDROID_LICENSE_FILES = README
HOSTAPD_ANDROID_CONF_ENV = LIBS="-lnl -lnl-genl"

# libnl needs -lm (for rint) if linking statically
ifeq ($(BR2_PREFER_STATIC_LIB),y)
HOSTAPD_ANDROID_LDFLAGS += -lm
endif

define HOSTAPD_ANDROID_LIBNL_CONFIG
	echo '' >> $(HOSTAPD_ANDROID_CONFIG)
	echo 'CONFIG_LIBNL32=y' >> $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_VLAN_NETLINK.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
endef

define HOSTAPD_ANDROID_LIBTOMMATH_CONFIG
	$(SED) 's/\(#\)\(CONFIG_INTERNAL_LIBTOMMATH.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
endef

# Try to use openssl if it's already available
ifeq ($(BR2_PACKAGE_OPENSSL),y)
	HOSTAPD_ANDROID_DEPENDENCIES += openssl
define HOSTAPD_ANDROID_TLS_CONFIG
	$(SED) 's/\(#\)\(CONFIG_TLS=openssl\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_PWD.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
endef
else
define HOSTAPD_ANDROID_TLS_CONFIG
	$(SED) 's/\(#\)\(CONFIG_TLS=\).*/\2internal/' $(HOSTAPD_ANDROID_CONFIG)
endef
endif

ifeq ($(BR2_PACKAGE_HOSTAPD_EAP),y)
define HOSTAPD_ANDROID_EAP_CONFIG
	$(SED) 's/\(#\)\(CONFIG_EAP_AKA.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_FAST.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_GPSK.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_IKEV2.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_PAX.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_PSK.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_SAKE.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_SIM.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_EAP_TNC.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_RADIUS_SERVER.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_TLSV1.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
endef
ifneq ($(BR2_INET_IPV6),y)
define HOSTAPD_ANDROID_RADIUS_IPV6_CONFIG
	$(SED) 's/\(CONFIG_IPV6.*\)/#\1/' $(HOSTAPD_ANDROID_CONFIG)
endef
endif
else
define HOSTAPD_ANDROID_EAP_CONFIG
	$(SED) 's/^\(CONFIG_EAP.*\)/#\1/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_NO_ACCOUNTING.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_NO_RADIUS.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
endef
endif

ifeq ($(BR2_PACKAGE_HOSTAPD_WPS),y)
define HOSTAPD_ANDROID_WPS_CONFIG
	$(SED) 's/\(#\)\(CONFIG_WPS.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
endef
endif

define HOSTAPD_ANDROID_CONFIGURE_CMDS
#	cp $(@D)/hostapd/defconfig $(HOSTAPD_ANDROID_CONFIG)
# Misc
	$(SED) 's/\(#\)\(CONFIG_HS20.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_IEEE80211N.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_IEEE80211R.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_IEEE80211W.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_INTERWORKING.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(SED) 's/\(#\)\(CONFIG_FULL_DYNAMIC_VLAN.*\)/\2/' $(HOSTAPD_ANDROID_CONFIG)
	$(HOSTAPD_ANDROID_LIBTOMMATH_CONFIG)
	$(HOSTAPD_ANDROID_TLS_CONFIG)
	$(HOSTAPD_ANDROID_RADIUS_IPV6_CONFIG)
	$(HOSTAPD_ANDROID_EAP_CONFIG)
	$(HOSTAPD_ANDROID_WPS_CONFIG)
	$(HOSTAPD_ANDROID_LIBNL_CONFIG)
endef

define HOSTAPD_ANDROID_BUILD_CMDS
	$(TARGET_MAKE_ENV) CFLAGS="$(HOSTAPD_ANDROID_CFLAGS)" \
		LDFLAGS="$(TARGET_LDFLAGS)" \
		$(MAKE) CC="$(TARGET_CC)" -C $(@D)/$(HOSTAPD_ANDROID_SUBDIR)
endef

define HOSTAPD_ANDROID_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 -D $(@D)/$(HOSTAPD_ANDROID_SUBDIR)/hostapd \
		$(TARGET_DIR)/usr/sbin/hostapd
	$(INSTALL) -m 0755 -D $(@D)/$(HOSTAPD_ANDROID_SUBDIR)/hostapd_cli \
		$(TARGET_DIR)/usr/bin/hostapd_cli
	$(INSTALL) -D -m 755 package/hostapd/hostapd.conf \
		$(TARGET_DIR)/etc/hostapd/hostapd.conf
	$(INSTALL) -D -m 755 package/hostapd/hostapd.conf \
		$(TARGET_DIR)/etc/hostapd/hostapd.default.conf
	$(INSTALL) -D -m 755 package/hostapd/hostapd.conf.2G \
		$(TARGET_DIR)/etc/hostapd/hostapd.conf.2G
	$(INSTALL) -D -m 755 package/hostapd/hostapd.conf.5G \
		$(TARGET_DIR)/etc/hostapd/hostapd.conf.5G
endef

#define HOSTAPD_ANDROID_INSTALL_INIT_SYSV 
#	$(INSTALL) -D -m 755 package/hostapd/S60hostapd \
#		$(TARGET_DIR)/etc/init.d/S60hostapd
#	$(INSTALL) -D -m 755 package/hostapd/S90multi-role \
#		$(TARGET_DIR)/etc/init.d/S90multi-role
#endef

$(eval $(generic-package))
