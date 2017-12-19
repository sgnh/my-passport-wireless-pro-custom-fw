WDPACKAGE_BASIC_VERSION = 0.04.067
WDPACKAGE_BASIC_RELEASE_DATE = 2017-03-07
WDPACKAGE_BASIC_SITE_METHOD = local
WDPACKAGE_BASIC_SITE = $(TOPDIR)/project/prjPackages/wdcore_avatar
WDPACKAGE_BASIC_DEPENDENCIES = tzdata netatalk

define WDPACKAGE_BASIC_EXTRACT_CMDS
	cp -Ra $(DL_DIR)/$(WDPACKAGE_BASIC_SOURCE)/* $(@D)
endef

ifeq ($(BR2_PACKAGE_BUSYBOX),y)
WDPACKAGE_BASIC_DEPENDENCIES += busybox
define WDPACKAGE_BASIC_MOVE_BUSYBOX_LOGGING_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S01logging ] || \
		mv $(TARGET_DIR)/etc/init.d/S01logging \
			$(TARGET_DIR)/etc/init.d/S02logging ;
	[ ! -f $(TARGET_DIR)/etc/init.d/S01mdev ] || \
		rm $(TARGET_DIR)/etc/init.d/S01mdev ;
endef
define WDPACKAGE_BASIC_MOVE_BUSYBOX_MDEV_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S30mdev \
		$(TARGET_DIR)/etc/init.d/S30mdev	
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S01mdev \
		$(TARGET_DIR)/etc/init.d/S01mdev	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-mdev.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-mdev.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_BUSYBOX_LOGGING_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_BUSYBOX_MDEV_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_RSYSLOG), y)
WDPACKAGE_BASIC_DEPENDENCIES += rsyslog
define WDPACKAGE_BASIC_MOVE_RSYSLOG_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S01rsyslog ] || \
		mv $(TARGET_DIR)/etc/init.d/S01rsyslog \
			$(TARGET_DIR)/etc/init.d/S05rsyslog ;
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_RSYSLOG_INIT_SCRIPT
endif

define WDPACKAGE_BASIC_MOVE_URANDOM_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S20urandom ] || \
		mv $(TARGET_DIR)/etc/init.d/S20urandom \
			$(TARGET_DIR)/etc/init.d/S15urandom ;
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-urandom.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-urandom.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_URANDOM_INIT_SCRIPT

ifeq ($(BR2_PACKAGE_DBUS), y)
WDPACKAGE_BASIC_DEPENDENCIES += dbus
define WDPACKAGE_BASIC_MOVE_DBUS_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S30dbus ] || \
		mv $(TARGET_DIR)/etc/init.d/S30dbus \
			$(TARGET_DIR)/etc/init.d/S20dbus ;
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_DBUS_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_PHP_EXT_FPM), y)
WDPACKAGE_BASIC_DEPENDENCIES += php
define WDPACKAGE_BASIC_MOVE_PHP_FPM_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S51php-fpm ] ||  \
		mv $(TARGET_DIR)/etc/init.d/S51php-fpm \
			$(TARGET_DIR)/etc/init.d/S58php-fpm ;
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-php-fpm.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-php-fpm.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_PHP_FPM_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_SAMBA), y)
WDPACKAGE_BASIC_DEPENDENCIES += samba
define WDPACKAGE_BASIC_MOVE_SAMBA_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S91smb ] || \
		mv $(TARGET_DIR)/etc/init.d/S91smb \
			$(TARGET_DIR)/etc/init.d/S75smb ;
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-smb.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-smb.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_SAMBA_INIT_SCRIPT
endif

define WDPACKAGE_BASIC_RM_NETWORK_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S40network ] || \
		rm $(TARGET_DIR)/etc/init.d/S40network ;
endef
define WDPACKAGE_BASIC_MOVE_NETWORK_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S35network \
		$(TARGET_DIR)/etc/init.d/S35network	
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_NETWORK_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_NETWORK_INIT_SCRIPT

ifeq ($(BR2_PACKAGE_DHCP), y)
WDPACKAGE_BASIC_DEPENDENCIES += dhcp
define WDPACKAGE_BASIC_RM_DHCP_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S80dhcp-server ] || \
		rm $(TARGET_DIR)/etc/init.d/S80dhcp-server ;
	[ ! -f $(TARGET_DIR)/etc/init.d/S80dhcp-relay ] || \
		rm $(TARGET_DIR)/etc/init.d/S80dhcp-relay ;
endef
define WDPACKAGE_BASIC_MOVE_DHCP_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S67dhcp-server \
		$(TARGET_DIR)/etc/init.d/S67dhcp-server	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-dhcp-server.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-dhcp-server.service
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S65dhcp-relay \
		$(TARGET_DIR)/etc/init.d/S65dhcp-relay	
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_DHCP_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_DHCP_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_IFPLUGD), y)
WDPACKAGE_BASIC_DEPENDENCIES += ifplugd
define WDPACKAGE_BASIC_RM_IFPLUGD_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S45ifplugd ] || \
		rm $(TARGET_DIR)/etc/init.d/S45ifplugd ;
endef
define WDPACKAGE_BASIC_MOVE_IFPLUGD_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S40ifplugd \
		$(TARGET_DIR)/etc/init.d/S40ifplugd	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-ifplugd.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-ifplugd.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_IFPLUGD_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_IFPLUGD_INIT_SCRIPT
endif

#ifeq ($(BR2_PACKAGE_LIGHTTPD), y)
#WDPACKAGE_BASIC_DEPENDENCIES += lighttpd
#define WDPACKAGE_BASIC_RM_LIGHTTPD_INIT_SCRIPT
#	[ ! -f $(TARGET_DIR)/etc/init.d/S50lighttpd ] || \
#		rm $(TARGET_DIR)/etc/init.d/S50lighttpd ;
#endef
#define WDPACKAGE_BASIC_MOVE_LIGHTTPD_INIT_SCRIPT
#	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S50lighttpd \
#		$(TARGET_DIR)/etc/init.d/S50lighttpd
#endef
#WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_LIGHTTPD_INIT_SCRIPT
#WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_LIGHTTPD_INIT_SCRIPT
#endif

ifeq ($(BR2_PACKAGE_APACHE), y)
WDPACKAGE_BASIC_DEPENDENCIES += apache
define WDPACKAGE_BASIC_RM_HTTPD_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S51apache2 ] || \
		rm $(TARGET_DIR)/etc/init.d/S51apache2 ;
endef
define WDPACKAGE_BASIC_MOVE_HTTPD_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S51apache2 \
		$(TARGET_DIR)/etc/init.d/S51apache2
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-apache.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-apache.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_HTTPD_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_HTTPD_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_NETATALK), y)
WDPACKAGE_BASIC_DEPENDENCIES += netatalk
define WDPACKAGE_BASIC_RM_NETATALK_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S50netatalk ] || \
		rm $(TARGET_DIR)/etc/init.d/S50netatalk ;
endef
define WDPACKAGE_BASIC_MOVE_NETATALK_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S55netatalk \
		$(TARGET_DIR)/etc/init.d/S55netatalk
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-netatalk.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-netatalk.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_NETATALK_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_NETATALK_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_HOSTAPD), y)
WDPACKAGE_BASIC_DEPENDENCIES += hostapd
define WDPACKAGE_BASIC_RM_HOSTAPD_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S90multi-role ] || \
		rm $(TARGET_DIR)/etc/init.d/S90multi-role ;
endef
define WDPACKAGE_BASIC_MOVE_HOSTAPD_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S60hostapd \
		$(TARGET_DIR)/etc/init.d/S60hostapd
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-hostapd.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-hostapd.service
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S73multi-role \
		$(TARGET_DIR)/etc/init.d/S73multi-role
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-multi-role.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-multi-role.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_HOSTAPD_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_HOSTAPD_INIT_SCRIPT
else

ifeq ($(BR2_PACKAGE_HOSTAPD_ANDROID), y)
WDPACKAGE_BASIC_DEPENDENCIES += hostapd-Android
define WDPACKAGE_BASIC_RM_HOSTAPD_ANDROID_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S90multi-role ] || \
		rm $(TARGET_DIR)/etc/init.d/S90multi-role ;
endef
define WDPACKAGE_BASIC_MOVE_HOSTAPD_ANDROID_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S60hostapd \
		$(TARGET_DIR)/etc/init.d/S60hostapd
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-hostapd.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-hostapd.service
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S73multi-role \
		$(TARGET_DIR)/etc/init.d/S73multi-role
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-multi-role.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-multi-role.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_HOSTAPD_ANDROID_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_HOSTAPD_ANDROID_INIT_SCRIPT
endif
endif

ifeq ($(BR2_PACKAGE_RTKPACKAGE_HOSTAPD), y)
WDPACKAGE_BASIC_DEPENDENCIES += rtkpackage_hostapd
define WDPACKAGE_BASIC_RM_RTKPACKAGE_HOSTAPD_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S90multi-role ] || \
		rm $(TARGET_DIR)/etc/init.d/S90multi-role ;
endef
define WDPACKAGE_BASIC_MOVE_RTKPACKAGE_HOSTAPD_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S60hostapd \
		$(TARGET_DIR)/etc/init.d/S60hostapd
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-hostapd.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-hostapd.service
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S73multi-role \
		$(TARGET_DIR)/etc/init.d/S73multi-role
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-multi-role.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-multi-role.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_RTKPACKAGE_HOSTAPD_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_RTKPACKAGE_HOSTAPD_INIT_SCRIPT
endif


ifeq ($(BR2_PACKAGE_OPENSSH), y)
WDPACKAGE_BASIC_DEPENDENCIES += openssh
define WDPACKAGE_BASIC_RM_OPENSSH_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S50sshd ] || \
		rm $(TARGET_DIR)/etc/init.d/S50sshd ;
endef
define WDPACKAGE_BASIC_MOVE_OPENSSH_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S57sshd \
		$(TARGET_DIR)/etc/init.d/S57sshd
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-sshd.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-sshd.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_OPENSSH_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_OPENSSH_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_VSFTPD), y)
WDPACKAGE_BASIC_DEPENDENCIES += vsftpd
define WDPACKAGE_BASIC_RM_VSFTPD_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S70vsftpd ] || \
		rm $(TARGET_DIR)/etc/init.d/S70vsftpd ;
endef
define WDPACKAGE_BASIC_MOVE_VSFTPD_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S63vsftpd \
		$(TARGET_DIR)/etc/init.d/S63vsftpd
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-vsftpd.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-vsftpd.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_VSFTPD_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_VSFTPD_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_AVAHI), y)
WDPACKAGE_BASIC_DEPENDENCIES += avahi
define WDPACKAGE_BASIC_RM_AVAHI_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S50avahi-daemon ] || \
		rm $(TARGET_DIR)/etc/init.d/S50avahi-daemon ;
endef
define WDPACKAGE_BASIC_MOVE_AVAHI_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S50avahi-daemon \
		$(TARGET_DIR)/etc/init.d/S50avahi-daemon
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-avahi-daemon.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-avahi-daemon.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_AVAHI_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_AVAHI_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_LIBUPNP), y)
WDPACKAGE_BASIC_DEPENDENCIES += libupnp
define WDPACKAGE_BASIC_RM_LIBUPNP_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S91upnp ] || \
		rm $(TARGET_DIR)/etc/init.d/S91upnp ;
endef
define WDPACKAGE_BASIC_MOVE_LIBUPNP_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S77upnp \
		$(TARGET_DIR)/etc/init.d/S77upnp
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-upnp.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-upnp.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_LIBUPNP_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_LIBUPNP_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_LLD2D), y)
WDPACKAGE_BASIC_DEPENDENCIES += libupnp
define WDPACKAGE_BASIC_RM_LLD2D_INIT_SCRIPT
	[ ! -f $(TARGET_DIR)/etc/init.d/S95lld2d ] || \
		rm $(TARGET_DIR)/etc/init.d/S95lld2d ;
endef
define WDPACKAGE_BASIC_MOVE_LLD2D_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S85lld2d \
		$(TARGET_DIR)/etc/init.d/S85lld2d
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-lld2d.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-lld2d.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_RM_LLD2D_INIT_SCRIPT
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_LLD2D_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_PARAGON_UFSD), y)
WDPACKAGE_BASIC_DEPENDENCIES += paragon-ufsd
define WDPACKAGE_BASIC_MOVE_PARAGON_UFSD_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S09paragonfs \
		$(TARGET_DIR)/etc/init.d/S09paragonfs
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_PARAGON_UFSD_INIT_SCRIPT
endif

ifeq ($(BR2_PACKAGE_RTKPACKAGE_RTL8811AU), y)
#ifeq ($(BR2_PACKAGE_RTKPACKAGE_RTL8189ES), y)
WDPACKAGE_BASIC_DEPENDENCIES += rtkpackage_rtl8811au
#WDPACKAGE_BASIC_DEPENDENCIES += rtkpackage_rtl8189es
define WDPACKAGE_BASIC_MOVE_RTK_WIFI_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S25wilink8 \
		$(TARGET_DIR)/etc/init.d/S25wilink8
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-wilink8.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-wilink8.service
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_MOVE_RTK_WIFI_INIT_SCRIPT
#endif
endif

ifeq ($(BR2_PACKAGE_DPKG), y)
WDPACKAGE_BASIC_DEPENDENCIES += dpkg
define WDPACKAGE_BASIC_GENERATE_DPKG_FILES
	rm -Rf $(TARGET_DIR)/var/lib/dpkg/status
	touch $(TARGET_DIR)/var/lib/dpkg/status
	touch $(TARGET_DIR)/var/lib/dpkg/available
	#cp -a $(STAGING_DIR)/sbin/ldconfig.real $(TARGET_DIR)/sbin/ldconfig
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_GENERATE_DPKG_FILES
endif

define WDPACKAGE_BASIC_INSTALL_INIT_SCRIPT
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/rcS \
		$(TARGET_DIR)/etc/init.d/rcS

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S01initsystem \
		$(TARGET_DIR)/etc/init.d/S01initsystem
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-initsystem.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-initsystem.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S43initdisk \
		$(TARGET_DIR)/etc/init.d/S43initdisk	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-initdisk.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-initdisk.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S74swapfile \
		$(TARGET_DIR)/etc/init.d/S74swapfile	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-swapfile.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-swapfile.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S47factory-restore \
		$(TARGET_DIR)/etc/init.d/S47factory-restore	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-factory-restore.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-factory-restore.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S90powerprofile \
		$(TARGET_DIR)/etc/init.d/S90powerprofile
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-powerprofile.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-powerprofile.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S93crond \
		$(TARGET_DIR)/etc/init.d/S93crond	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-crond.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-crond.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S95fwupg \
		$(TARGET_DIR)/etc/init.d/S95fwupg	
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-fwupg.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-fwupg.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S96rsynchk \
		$(TARGET_DIR)/etc/init.d/S96rsynchk
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-rsynchk.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-rsynchk.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S97rtc \
		$(TARGET_DIR)/etc/init.d/S97rtc
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-rtc.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-rtc.service

	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S99confchk \
		$(TARGET_DIR)/etc/init.d/S99confchk
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-confchk.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-confchk.service
		
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S99apacs \
		$(TARGET_DIR)/etc/init.d/S99apacs
	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-apacs.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-apacs.service	
endef
WDPACKAGE_BASIC_POST_INSTALL_TARGET_HOOKS += WDPACKAGE_BASIC_INSTALL_INIT_SCRIPT

define WDPACKAGE_BASIC_INSTALL_TARGET_CMDS
	mkdir -p $(TARGET_DIR)/usr/local/bin
	mkdir -p $(TARGET_DIR)/usr/local/sbin
	mkdir -p $(TARGET_DIR)/var/www/htdocs/ui
	mkdir -p $(TARGET_DIR)/var/lib/dpkg/info
	rm -Rf $(TARGET_DIR)/var/lib/dpkg/status
	mkdir -p $(TARGET_DIR)/var/lib/dpkg/status
	mkdir -p $(TARGET_DIR)/etc/netatalk
	mkdir -p $(TARGET_DIR)/DataVolume
	ln -sf /media/sdb1/.wdcache $(TARGET_DIR)/CacheVolume
	ln -sf /tmp/netatalk-db $(TARGET_DIR)/usr/var/netatalk
	ln -sf inc_update_counts.sh $(TARGET_DIR)/usr/local/sbin/incUpdateCount.pm
	rsync -av $(@D)/  $(TARGET_DIR) --exclude=lib/systemd/system/multi-user.target.wants/ --exclude=etc/init.d/ --exclude=.stamp_*

	ln -sf Sydney $(TARGET_DIR)/usr/share/zoneinfo/Australia/Canberra
	mkdir -p $(TARGET_DIR)/usr/share/zoneinfo/Brazil
	ln -sf ../posix/America/Noronha $(TARGET_DIR)/usr/share/zoneinfo/Brazil/DeNoronha
	ln -sf ../posix/America/Sao_Paulo $(TARGET_DIR)/usr/share/zoneinfo/Brazil/East
	ln -sf ../posix/America/Manaus $(TARGET_DIR)/usr/share/zoneinfo/Brazil/West
	mkdir -p $(TARGET_DIR)/usr/share/zoneinfo/Canada
	ln -sf ../posix/America/St_Johns $(TARGET_DIR)/usr/share/zoneinfo/Canada/Newfoundland
	ln -sf ../posix/America/Regina $(TARGET_DIR)/usr/share/zoneinfo/Canada/Saskatchewan
	rm $(TARGET_DIR)/usr/share/zoneinfo/Pacific/Guam
	ln -sf Port_Moresby $(TARGET_DIR)/usr/share/zoneinfo/Pacific/Guam
	ln -sf Sydney $(TARGET_DIR)/usr/share/zoneinfo/posix/Australia/Canberra
	ln -sf ../America/Anchorage $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Alaska
	ln -sf ../America/Phoenix $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Arizona
	ln -sf ../America/Chicago $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Central
	ln -sf ../America/New_York $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Eastern
	ln -sf ../America/Indiana/Indianapolis $(TARGET_DIR)/usr/share/zoneinfo/posix/US/East-Indiana
	ln -sf ../Pacific/Honolulu $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Hawaii
	ln -sf ../America/Denver $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Mountain
	ln -sf ../America/Los_Angeles $(TARGET_DIR)/usr/share/zoneinfo/posix/US/Pacific
	[ -f $(TARGET_DIR)/etc/version ] || \
		$(INSTALL) -D -m 755 package/wdpackage_basic/version \
		$(TARGET_DIR)/etc/version

	cp -a package/wdpackage_basic/version $(TARGET_DIR)/etc/
	[ -f $(TARGET_DIR)/etc/version.packages ] || \
		$(INSTALL) -D -m 755 package/wdpackage_basic/version.packages \
		$(TARGET_DIR)/etc/version.packages
	
	sed -i 's/PMXAC_.*/PMXAC_'$(WDPACKAGE_BASIC_VERSION):$(WDPACKAGE_BASIC_RELEASE_DATE)'/' $(TARGET_DIR)/etc/version.packages
	$(INSTALL) -m 0755 -D $(@D)/etc/init.d/S08pmxcache \
		$(TARGET_DIR)/etc/init.d/S08pmxcache

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/sysinit.target.wants/primax-pmxcache.service \
		$(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/primax-pmxcache.service

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-wdmcserverd.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-wdmcserverd.service

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-RestAPI.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-RestAPI.service

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/multi-user.target.wants/primax-wdnotifierd.service \
		$(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/primax-wdnotifierd.service

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/primax-halt.service \
		$(TARGET_DIR)/lib/systemd/system/primax-halt.service
	[ -d $(TARGET_DIR)/etc/systemd/system/halt.target.wants ] || \
		mkdir $(TARGET_DIR)/etc/systemd/system/halt.target.wants
	ln -sf /lib/systemd/system/primax-halt.service $(TARGET_DIR)/etc/systemd/system/halt.target.wants/primax-halt.service

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/primax-reboot.service \
		$(TARGET_DIR)/lib/systemd/system/primax-reboot.service
	[ -d $(TARGET_DIR)/etc/systemd/system/reboot.target.wants ] || \
		mkdir $(TARGET_DIR)/etc/systemd/system/reboot.target.wants
	ln -sf /lib/systemd/system/primax-reboot.service $(TARGET_DIR)/etc/systemd/system/reboot.target.wants/primax-reboot.service

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/primax-poweroff.service \
		$(TARGET_DIR)/lib/systemd/system/primax-poweroff.service
	[ -d $(TARGET_DIR)/etc/systemd/system/poweroff.target.wants ] || \
		mkdir $(TARGET_DIR)/etc/systemd/system/poweroff.target.wants
	ln -sf /lib/systemd/system/primax-poweroff.service $(TARGET_DIR)/etc/systemd/system/poweroff.target.wants/primax-poweroff.service

	$(INSTALL) -m 0644 -D $(@D)/etc/modules-load.d/usb.conf \
		$(TARGET_DIR)/etc/modules-load.d/usb.conf
	$(INSTALL) -m 0644 -D $(@D)/etc/modules-load.d/paragon.conf \
		$(TARGET_DIR)/etc/modules-load.d/paragon.conf
	$(INSTALL) -m 0644 -D $(@D)/etc/modules-load.d/sd.conf \
		$(TARGET_DIR)/etc/modules-load.d/sd.conf

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/tmp.mount \
		$(TARGET_DIR)/lib/systemd/system/tmp.mount

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/media.mount \
		$(TARGET_DIR)/lib/systemd/system/media.mount

	ln -sf ../media.mount $(TARGET_DIR)/lib/systemd/system/local-fs.target.wants/media.mount

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/hwcollect.mount \
		$(TARGET_DIR)/lib/systemd/system/hwcollect.mount

	ln -sf ../hwcollect.mount $(TARGET_DIR)/lib/systemd/system/local-fs.target.wants/hwcollect.mount

	$(INSTALL) -m 0644 -D $(@D)/lib/systemd/system/fstrim.service \
		$(TARGET_DIR)/lib/systemd/system/fstrim.service

	ln -sf ../fstrim.service $(TARGET_DIR)/lib/systemd/system/multi-user.target.wants/fstrim.service

	mkdir -p $(TARGET_DIR)/lib/systemd/system/timers.target.wants
	ln -sf ../fstrim.timer $(TARGET_DIR)/lib/systemd/system/timers.target.wants/fstrim.timer

	rm -rf $(TARGET_DIR)/etc/fstab

	rm -rf $(TARGET_DIR)/etc/systemd/system/getty.target.wants
	rm -rf $(TARGET_DIR)/etc/systemd/system/network.service
	rm -rf $(TARGET_DIR)/etc/systemd/system/sshd.service
	rm -rf $(TARGET_DIR)/etc/systemd/system/multi-user.target.wants/avahi*
	rm -rf $(TARGET_DIR)/etc/systemd/system/multi-user.target.wants/dhcpd.service
	rm -rf $(TARGET_DIR)/etc/systemd/system/multi-user.target.wants/network.service
	rm -rf $(TARGET_DIR)/etc/systemd/system/multi-user.target.wants/sshd.service
	rm -rf $(TARGET_DIR)/etc/systemd/system/multi-user.target.wants/systemd-resolved.service
	rm -rf $(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/systemd-journal-catalog-update.service
	rm -rf $(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/systemd-journal-flush.service
	rm -rf $(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/systemd-journald.service
	rm -rf $(TARGET_DIR)/lib/systemd/system/sysinit.target.wants/systemd-tmpfiles-setup.service

	rm -rf $(TARGET_DIR)/lib/udev/rules.d/75-net-description.rules
	rm -rf $(TARGET_DIR)/lib/udev/rules.d/80-net-setup-link.rules
endef

define WDPACKAGE_BASIC_UNINSTALL_TARGET_CMDS
	rm -f $(TARGET_DIR)/var/local/bin
	rm -f $(TARGET_DIR)/var/local/sbin
	rm -f $(TARGET_DIR)/var/www/htdocs/ui
	rm -f $(TARGET_DIR)/usr/local/wdmpserver
	rm -f $(TARGET_DIR)/etc/netatalk
	rm -f $(TARGET_DIR)/CacheVolume
endef

$(eval $(generic-package))
