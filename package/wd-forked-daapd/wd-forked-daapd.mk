#############################################################
#
# wd-forked-daapd
#
#############################################################

WD_FORKED_DAAPD_VERSION = 22.1
WD_FORKED_DAAPD_SITE = https://github.com/ejurgensen/forked-daapd.git
WD_FORKED_DAAPD_SOURCE = forked-daapd-$(WD_FORKED_DAAPD_VERSION).tar.gz 
WD_FORKED_DAAPD_DIR = $(BUILD_DIR)/forked-daapd-$(WD_FORKED_DAAPD_VERSION)

WD_FORKED_DAAPD_INSTALL_STAGING = YES
WD_FORKED_DAAPD_INSTALL_TARGET = YES
WD_FORKED_DAAPD_AUTORECONF = YES

WD_FORKED_DAAPD_DEPENDENCIES = zlib libavl libunistring libgcrypt libevent libconfuse sqlite avahi taglib libid3tag
WD_FORKED_DAAPD_CONF_ENV = ZLIB_LIBS="-lz" ZLIB_CFLAGS=" " LIBS="-lstdc++ -lavutil -lavdevice -lavfilter -lavformat -lswscale" LIBAV_LIBS="-lavcodec" LIBAV_CFLAGS=" "

WD_FORKED_DAAPD_CONF_OPTS = --localstatedir=/var --sysconfdir=/etc \
		--disable-rpath --disable-ipv6

define WD_FORKED_DAAPD_EXTRACT_CMDS
	tar zxvf $(DL_DIR)/$(WD_FORKED_DAAPD_SOURCE) -C $(@D)
endef

define WD_FORKED_DAAPD_INSTALL_INIT_SYSV
		$(INSTALL) -D -m 755 package/wd-forked-daapd/S88ituneserver \
		$(TARGET_DIR)/etc/init.d/S88ituneserver
endef

$(eval $(autotools-package))
