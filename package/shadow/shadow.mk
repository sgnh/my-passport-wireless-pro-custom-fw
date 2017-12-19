################################################################################
#
# shadow
#
################################################################################

SHADOW_VERSION = 4.1.5.1
SHADOW_SOURCE = shadow-$(SHADOW_VERSION).tar.bz2
SHADOW_SITE = http://pkg-shadow.alioth.debian.org/releases/
SHADOW_LICENSE = BSD
SHADOW_LICENSE_FILES = COPYING
SHADOW_DEPENDENCIES = acl attr busybox

SHADOW_INSTALL_STAGING = NO

SHADOW_CONF_OPTS = --disable-nls

# Shadow configuration to support audit
ifeq ($(BR2_PACKAGE_AUDIT),y)
SHADOW_DEPENDENCIES += audit
SHADOW_CONF_OPTS += --with-audit=yes
endif

# Shawdow with linux-pam support
ifeq ($(BR2_PACKAGE_LINUX_PAM),y) 
SHADOW_DEPENDENCIES += linux-pam
SHADOW_CONF_OPTS += --with-libpam=yes
endif

# Shadow with selinux support
ifeq ($(BR2_PACKAGE_LIBSELINUX),y)
SHADOW_DEPENDENCIES += libselinux libsemanage
SHADOW_CONF_OPTS += --with-selinux=yes
endif

# Comment out all config entries that conflict with using PAM
define SHADOW_LOGIN_CONFIGURATION
	for FUNCTION in FAIL_DELAY FAILLOG_ENAB LASTLOG_ENAB MAIL_CHECK_ENAB \
		OBSCURE_CHECKS_ENAB PORTTIME_CHECKS_ENAB QUOTAS_ENAB CONSOLE MOTD_FILE \
		FTMP_FILE NOLOGINS_FILE ENV_HZ PASS_MIN_LEN SU_WHEEL_ONLY CRACKLIB_DICTPATH \
		PASS_CHANGE_TRIES PASS_ALWAYS_WARN CHFN_AUTH ENCRYPT_METHOD ENVIRON_FILE ; \
	do \
		sed -i "s/^$${FUNCTION}/# &/" $(TARGET_DIR)/etc/login.defs ; \
	done
endef

SHADOW_POST_INSTALL_TARGET_HOOKS += SHADOW_LOGIN_CONFIGURATION

$(eval $(autotools-package))
