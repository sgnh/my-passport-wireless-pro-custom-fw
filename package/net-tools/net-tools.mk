#############################################################
#
# net-tools
#
#############################################################

NET_TOOLS_VERSION = 1.60
NET_TOOLS_SOURCE = net-tools_$(NET_TOOLS_VERSION).orig.tar.gz
NET_TOOLS_PATCH = net-tools_$(NET_TOOLS_VERSION)-25.diff.gz
NET_TOOLS_SITE = $(BR2_DEBIAN_MIRROR)/debian/pool/main/n/net-tools
NET_TOOLS_DEPENDENCIES = linux
NET_TOOLS_INSTALL_STAGING = YES
NET_TOOLS_CONF_OPTS = 

define NET_TOOLS_DEBIAN_PATCHES
	if [ -d $(@D)/debian/patches ]; then \
		support/scripts/apply-patches.sh $(@D) $(@D)/debian/patches \*.patch; \
	fi
	(cp $(@D)/debian/config.h $(@D))
	(cp package/net-tools/config.make $(@D))
endef

NET_TOOLS_POST_PATCH_HOOKS = NET_TOOLS_DEBIAN_PATCHES

# BR2_PACKAGE_NET_TOOLS_ARP
# BR2_PACKAGE_NET_TOOLS_HOSTNAME
# BR2_PACKAGE_NET_TOOLS_IFCONFIG
# BR2_PACKAGE_NET_TOOLS_NAMEIF
# BR2_PACKAGE_NET_TOOLS_NETSTAT
# BR2_PACKAGE_NET_TOOLS_PLIPCONFIG
# BR2_PACKAGE_NET_TOOLS_RARP
# BR2_PACKAGE_NET_TOOLS_ROUTE
# BR2_PACKAGE_NET_TOOLS_SLATTACH

ifeq ($(BR2_PACKAGE_NET_TOOLS_ARP),y)
define NET_TOOLS_BUILD_ARP
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) arp)
endef
define NET_TOOLS_INSTALL_ARP
	$(INSTALL) -m 0755 -D $(@D)/arp $(TARGET_DIR)/usr/sbin/arp
endef
endif

# Need fixed libdnet-dev package depend 
#ifeq ($(BR2_PACKAGE_NET_TOOLS_HOSTNAME),y)
#define NET_TOOLS_BUILD_HOSTNAME
#	(cd $(@D);  $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) hostname)
#endef
#defind NET_TOOLS_INSTALL_HOSTNAME
#	$(INSTALL) -m 0755 -D $(@D)/hostname (TARGET_DIR)/usr/sbin/hostname
#endef
#endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_IFCONFIG),y)
define NET_TOOLS_BUILD_IFCONFIG
	(cd $(@D);  $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) ifconfig)
endef
define NET_TOOLS_INSTALL_IFCONFIG
	$(INSTALL) -m 0755 -D $(@D)/ifconfig $(TARGET_DIR)/usr/sbin/ifconfig
endef
endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_NAMEIF),y)
define NET_TOOLS_BUILD_NAMEIF
	(cd $(@D);  $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) nameif)
endef
define NET_TOOLS_INSTALL_NAMEIF
	$(INSTALL) -m 0755 -D $(@D)/nameif $(TARGET_DIR)/usr/sbin/nameif
endef
endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_NETSTAT),y)
define NET_TOOLS_BUILD_NETSTAT
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) netstat)
endef
define NET_TOOLS_INSTALL_NETSTAT
	$(INSTALL) -m 0755 -D $(@D)/netstat $(TARGET_DIR)/usr/sbin/netstat
endef
endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_PLIPCONFIG),y)
define NET_TOOLS_BUILD_PLIPCONFIG
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) plipconfig)
endef
define NET_TOOLS_INSTALL_PLIPCONFIG
	$(INSTALL) -m 0755 -D $(@D)/plipconfig $(TARGET_DIR)/usr/sbin/plipconfig
endef
endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_RARP),y)
define NET_TOOLS_BUILD_RARP
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) rarp)
endef
define NET_TOOLS_INSTALL_RARP
    $(INSTALL) -m 0755 -D $(@D)/rarp $(TARGET_DIR)/usr/sbin/rarp
endef
endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_ROUTE),y)
define NET_TOOLS_BUILD_ROUTE
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) route)
endef
define NET_TOOLS_INSTALL_ROUTE
    $(INSTALL) -m 0755 -D $(@D)/route $(TARGET_DIR)/usr/sbin/route
endef
endif

ifeq ($(BR2_PACKAGE_NET_TOOLS_SLATTACH),y)
define NET_TOOLS_BUILD_SLATTACH
	(cd $(@D); $(TARGET_MAKE_ENV) $(TARGET_CONFIGURE_OPTS) $(MAKE) slattach)
endef
define NET_TOOLS_INSTALL_SLATTACH
    $(INSTALL) -m 0755 -D $(@D)/slattach $(TARGET_DIR)/usr/sbin/slattach
endef
endif

define NET_TOOLS_BUILD_CMDS
	$(NET_TOOLS_BUILD_ARP)
	$(NET_TOOLS_BUILD_HOSTNAME)
	$(NET_TOOLS_BUILD_IFCONFIG)
	$(NET_TOOLS_BUILD_NAMEIF)
	$(NET_TOOLS_BUILD_NETSTAT)
	$(NET_TOOLS_BUILD_PLIPCONFIG)
	$(NET_TOOLS_BUILD_RARP)
	$(NET_TOOLS_BUILD_ROUTE)
	$(NET_TOOLS_BUILD_SLATTACH)
endef



define NET_TOOLS_INSTALL_TARGET_CMDS
	$(NET_TOOLS_INSTALL_ARP)
	$(NET_TOOLS_INSTALL_HOSTNAME)
	$(NET_TOOLS_INSTALL_IFCONFIG)
	$(NET_TOOLS_INSTALL_NAMEIF)
	$(NET_TOOLS_INSTALL_NETSTAT)
	$(NET_TOOLS_INSTALL_PLIPCONFIG)
	$(NET_TOOLS_INSTALL_RARP)
	$(NET_TOOLS_INSTALL_ROUTE)
	$(NET_TOOLS_INSTALL_SLATTACH)
endef

$(eval $(generic-package))
