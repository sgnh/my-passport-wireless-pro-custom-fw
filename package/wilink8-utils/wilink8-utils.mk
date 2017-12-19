#############################################################
#
# wilink8-utils
#
#############################################################

WILINK8_UTILS_VERSION = r8.a8.08
WILINK8_UTILS_SOURCE = wilink8-utils-wl18xx-$(WILINK8_UTILS_VERSION).tgz
WILINK8_UTILS_COMPAT_BASE = ol_r8.a8.08
WILINK8_UTILS_DEPENDENCIES = linux
WILINK8_UTILS_INSTALL_STAGING = YES
WILINK8_UTILS_CONF_OPTS = \
				   --with-linux-dir=$(LINUX_DIR)
WILINK8_UTILS_CFLAGS = \
				 $(TARGET_CFLAGS) \
				 -I$(LINUX_HEADERS_DIR)/include \
				 -I$(STAGING_DIR)/usr/include \
				 -I$(LINUX_DIR)/include \
				 -I$(WILINK8_DIR)/include \
				 -I$(LIBNL_DIR)/include 
WILINK8_UTILS_MAKE_ENV = \
				   CFLAGS="$(WILINK8_UTILS_CFLAGS)" 


define WILINK8_UTILS_BUILD_CMDS
	(cd $(@D); $(TARGET_MAKE_ENV) $(WILINK8_UTILS_MAKE_ENV) $(MAKE) NFSROOT="$(STAGING_DIR)" CC="$(TARGET_CC) $(TARGET_CFLAGS) $(TARGET_LDFLAGS) -I$(STAGING_DIR)/usr/include/libnl3" LIBS="-lnl-3 -lnl-genl-3 -lm")
	(cd $(@D)/wlconf; $(TARGET_MAKE_ENV) $(WILINK8_UTILS_MAKE_ENV) $(MAKE) CC="$(TARGET_CC)")
endef

define WILINK8_UTILS_INSTALL_TARGET_CMDS
	$(INSTALL) -m 0755 -D $(@D)/calibrator \
		$(TARGET_DIR)/usr/bin/calibrator
	$(INSTALL) -m 0755 -D $(@D)/wlconf/wlconf \
		$(TARGET_DIR)/usr/sbin/wlconf
	$(INSTALL) -m 0755 -D $(@D)/wlconf/struct.bin \
		$(TARGET_DIR)/usr/sbin/struct.bin
	$(INSTALL) -m 0755 -D $(@D)/wlconf/dictionary.txt \
		$(TARGET_DIR)/usr/sbin/dictionary.txt
	$(INSTALL) -m 0755 -D $(@D)/wlconf/wl18xx-conf-default.bin \
		$(TARGET_DIR)/usr/sbin/wl18xx-conf-default.bin
endef

$(eval $(generic-package))
