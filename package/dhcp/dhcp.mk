################################################################################
#
# dhcp
#
################################################################################

DHCP_VERSION = 4.1-ESV-R10
DHCP_SITE = http://ftp.isc.org/isc/dhcp/$(DHCP_VERSION)
DHCP_INSTALL_STAGING = YES
DHCP_LICENSE = ISC
DHCP_LICENSE_FILES = LICENSE
# For 0001-fix-configure-debug.patch
DHCP_AUTORECONF = YES

ifeq ($(BR2_PACKAGE_DHCP_WITHOUT_ROUTERS),y)
DHCP_CONF_ENV = \
	CPPFLAGS='-DDHCP_WITHOUT_ROUTERS -D_PATH_DHCPD_CONF=\"/etc/dhcpd.conf\" \
		-D_PATH_DHCLIENT_CONF=\"/etc/dhcp/dhclient.conf\"' \
		ac_cv_file__dev_random=yes
else
DHCP_CONF_ENV = \
	CPPFLAGS='-D_PATH_DHCPD_CONF=\"/etc/dhcpd.conf\" \
		-D_PATH_DHCLIENT_CONF=\"/etc/dhcp/dhclient.conf\"' \
	ac_cv_file__dev_random=yes
endif

DHCP_CONF_OPTS = \
	--with-srv-lease-file=/var/lib/dhcp/dhcpd.leases \
	--with-srv6-lease-file=/var/lib/dhcp/dhcpd6.leases \
	--with-cli-lease-file=/var/lib/dhcp/dhclient.leases \
	--with-cli6-lease-file=/var/lib/dhcp/dhclient6.leases \
	--with-srv-pid-file=/var/run/dhcpd.pid \
	--with-srv6-pid-file=/var/run/dhcpd6.pid \
	--with-cli-pid-file=/var/run/dhclient.pid \
	--with-cli6-pid-file=/var/run/dhclient6.pid \
	--with-relay-pid-file=/var/run/dhcrelay.pid \
	--with-relay6-pid-file=/var/run/dhcrelay6.pid

ifeq ($(BR2_PACKAGE_DHCP_SERVER_DELAYED_ACK),y)
DHCP_CONF_OPTS += --enable-delayed-ack
endif

ifneq ($(BR2_INET_IPV6),y)
DHCP_CONF_OPTS += --disable-dhcpv6
endif

ifeq ($(BR2_PACKAGE_DHCP_SERVER),y)
define DHCP_INSTALL_SERVER
	mkdir -p $(TARGET_DIR)/var/lib
	(cd $(TARGET_DIR)/var/lib; ln -snf /tmp dhcp)
	$(INSTALL) -m 0755 -D $(@D)/server/dhcpd $(TARGET_DIR)/usr/sbin/dhcpd
	$(INSTALL) -m 0755 -D package/dhcp/S80dhcp-server \
		$(TARGET_DIR)/etc/init.d/S80dhcp-server
	$(INSTALL) -m 0644 -D package/dhcp/dhcpd.conf \
		$(TARGET_DIR)/etc/dhcpd.conf
	$(INSTALL) -m 0644 -D package/dhcp/dhcpd.conf \
		$(TARGET_DIR)/etc/dhcpd.conf.bak
endef
endif

ifeq ($(BR2_PACKAGE_DHCP_RELAY),y)
define DHCP_INSTALL_RELAY
	mkdir -p $(TARGET_DIR)/var/lib
	(cd $(TARGET_DIR)/var/lib; ln -snf /tmp dhcp)
	$(INSTALL) -m 0755 -D $(DHCP_DIR)/relay/dhcrelay \
		$(TARGET_DIR)/usr/sbin/dhcrelay
	$(INSTALL) -m 0755 -D package/dhcp/S80dhcp-relay \
		$(TARGET_DIR)/etc/init.d/S80dhcp-relay
endef
endif

ifeq ($(BR2_PACKAGE_DHCP_CLIENT),y)
define DHCP_INSTALL_CLIENT
	mkdir -p $(TARGET_DIR)/var/lib
	(cd $(TARGET_DIR)/var/lib; ln -snf /tmp dhcp)
	$(INSTALL) -m 0755 -D $(DHCP_DIR)/client/dhclient \
		$(TARGET_DIR)/usr/sbin/dhclient
	$(INSTALL) -m 0644 -D package/dhcp/dhclient.conf \
		$(TARGET_DIR)/etc/dhcp/dhclient.conf
	$(INSTALL) -m 0755 -D package/dhcp/dhclient-script \
		$(TARGET_DIR)/sbin/dhclient-script
endef
endif

# Options don't matter, scripts won't start if binaries aren't there
define DHCP_INSTALL_INIT_SYSV
	$(INSTALL) -m 0755 -D package/dhcp/S80dhcp-server \
		$(TARGET_DIR)/etc/init.d/S80dhcp-server
	$(INSTALL) -m 0755 -D package/dhcp/S80dhcp-relay \
		$(TARGET_DIR)/etc/init.d/S80dhcp-relay
endef

ifeq ($(BR2_PACKAGE_DHCP_SERVER),y)
define DHCP_INSTALL_INIT_SYSTEMD
	$(INSTALL) -D -m 644 package/dhcp/dhcpd.service \
		$(TARGET_DIR)/lib/systemd/system/dhcpd.service

	mkdir -p $(TARGET_DIR)/etc/systemd/system/multi-user.target.wants

	ln -sf ../../../../lib/systemd/system/dhcpd.service \
		$(TARGET_DIR)/etc/systemd/system/multi-user.target.wants/dhcpd.service

	echo "d /var/lib/dhcp 0755 - - - -" > \
		$(TARGET_DIR)/usr/lib/tmpfiles.d/dhcpd.conf
	echo "f /var/lib/dhcp/dhcpd.leases - - - - -" >> \
		$(TARGET_DIR)/usr/lib/tmpfiles.d/dhcpd.conf
endef
endif

define DHCP_INSTALL_TARGET_CMDS
	$(DHCP_INSTALL_RELAY)
	$(DHCP_INSTALL_SERVER)
	$(DHCP_INSTALL_CLIENT)
endef

$(eval $(autotools-package))
