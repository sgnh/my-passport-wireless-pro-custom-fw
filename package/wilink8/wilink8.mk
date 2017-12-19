#############################################################
#
# wilink8
#
#############################################################

WILINK8_VERSION = r8.a8.08
WILINK8_SOURCE = wilink8-wl18xx-$(WILINK8_VERSION).tgz
WILINK8_COMPAT_BASE = ol_r8.a8.08
WILINK8_DEPENDENCIES = linux
WILINK8_FIRMWARE_VERSION = 280
WILINK8_INSTALL_STAGING = YES
WILINK8_CONF_OPTS = \
				   --with-linux-dir=$(LINUX_DIR)
WILINK8_CFLAGS = \
				 $(TARGET_CFLAGS) \
				 -I$(LINUX_HEADERS_DIR)/include \
				 -I$(STAGING_DIR)/usr/include \
				 -I$(LINUX_DIR)/include \
				 -I$(@D)/include \
				 -DCOMPAT_BASE="\\\"$(WILINK8_COMPAT_BASE)\\\"" \
				 -DCOMPAT_BASE_TREE="\\\"\\\"" \
				 -DCOMPAT_BASE_TREE_VERSION="\\\"$(WILINK8_COMPAT_BASE)\\\"" \
				 -DCOMPAT_VERSION="\\\"$(WILINK8_COMPAT_BASE)\\\"" \
				 -DCOMPAT_PROJECT="\\\"Compat-wireless\\\""
WILINK8_MAKE_ENV = \
				   CFLAGS="$(WILINK8_CFLAGS)" \
				   COMPAT_CONFIG_CW=$(@D)/config.mk \
				   COMPAT_CONFIG=$(@D)/.config \
				   CONFIG_CHECK=$(@D)/.config.mk_md5sum.txt \
				   COMPAT_AUTOCONF=$(@D)/include/linux/compat_autoconf.h \
				   CREL=$(WILINK8_COMPAT_BASE) \
				   CREL_PRE=.compat_autoconf_$(WILINK8_COMPAT_BASE) \
				   CREL_CHECK=$(@D)/$(CREL_PRE)$(CREL)


define WILINK8_BUILD_CMDS
	$(TARGET_MAKE_ENV) $(WILINK8_MAKE_ENV) $(MAKE) $(LINUX_MAKE_FLAGS) -C $(LINUX_DIR) V=1 M=$(@D) modules
endef

define WILINK8_INSTALL_TARGET_CMDS
	$(MAKE) -C $(LINUX_DIR) $(LINUX_MAKE_FLAGS) M="$(@D)" modules_install
	mkdir -p $(TARGET_DIR)/lib/firmware
	cp -a $(@D)/firmware/* $(TARGET_DIR)/lib/firmware
	cp -a package/wilink8/firmware/wl18xx-conf.bin $(TARGET_DIR)/lib/firmware/ti-connectivity/
	cp -a package/wilink8/firmware/wl18xx-fw-2-$(WILINK8_FIRMWARE_VERSION).bin $(TARGET_DIR)/lib/firmware/ti-connectivity//wl18xx-fw-2.bin
endef

define WILINK8_INSTALL_INIT_SYSV
	[ -f $(TARGET_DIR)/etc/init.d/S30wilink8 ] || \
		$(INSTALL) -D -m 755 package/wilink8/S30wilink8 \
		$(TARGET_DIR)/etc/init.d/S30wilink8
endef

$(eval $(generic-package))
