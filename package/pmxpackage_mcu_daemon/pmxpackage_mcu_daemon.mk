#############################################################
#
# mcu_daemon 
#
#############################################################

PMXPACKAGE_MCU_DAEMON_VERSION = 0.0.1
PMXPACKAGE_MCU_DAEMON_SITE_METHOD = local
PMXPACKAGE_MCU_DAEMON_SITE = $(TOPDIR)/project/prjPackages/mcu_daemon
MCU_DAEMON_VERSION = 1.000

define PMXPACKAGE_MCU_DAEMON_EXTRACT_CMDS
	 cp -Ra $(DL_DIR)/$(PMXPACKAGE_MCU_DAEMON_SOURCE)/* $(@D)
endef

define PMXPACKAGE_MCU_DAEMON_INSTALL_TARGET_CMDS
	cp -a $(@D)/mcu_daemon $(TARGET_DIR)/bin/
	cp -a $(@D)/stm32isp $(TARGET_DIR)/sbin/
	#cp -Ra $(@D)/firmware/* $(BINARIES_DIR)/
	echo "${MCU_DAEMON_VERSION}" > $(BINARIES_DIR)/mcu.version
endef

ifeq ($(BR2_PACKAGE_PMXPACKAGE_RESCUEFS), y)
define PMXPACKAGE_MCU_DAEMON_INCLUDE_FIRMWARE
	cp -a $(@D)/mcu_daemon-rescuefs $(TARGET_DIR)/bin/mcu_daemon
	cp -a $(@D)/stm32isp-rescuefs $(TARGET_DIR)/sbin/stm32isp
endef
PMXPACKAGE_MCU_DAEMON_POST_INSTALL_TARGET_HOOKS += PMXPACKAGE_MCU_DAEMON_INCLUDE_FIRMWARE
endif

ifeq ($(BR2_PACKAGE_PMXPACKAGE_FWUPGFS), y)
define PMXPACKAGE_MCU_DAEMON_INCLUDE_FIRMWARE
	mkdir -p $(TARGET_DIR)/etc/firmware
	cp -Ra $(@D)/firmware/* \
		    $(TARGET_DIR)/etc/firmware/ ;
	cp -a $(@D)/mcu_daemon-fwupgfs $(TARGET_DIR)/bin/mcu_daemon
	cp -a $(@D)/stm32isp-fwupgfs $(TARGET_DIR)/sbin/stm32isp
endef
PMXPACKAGE_MCU_DAEMON_POST_INSTALL_TARGET_HOOKS += PMXPACKAGE_MCU_DAEMON_INCLUDE_FIRMWARE
endif

$(eval $(generic-package))
