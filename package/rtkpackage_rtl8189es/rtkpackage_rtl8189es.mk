################################################################################
#
# RTKPACKAGE_RTL8189ES
#
################################################################################

RTKPACKAGE_RTL8189ES_VERSION = 0.0.1
RTKPACKAGE_RTL8189ES_SITE_METHOD = local
RTKPACKAGE_RTL8189ES_DEPENDENCIES = linux
RTKPACKAGE_RTL8189ES_SITE = $(TOPDIR)/project/prjPackages/wifi/rtl8189es/
RTKPACKAGE_RTL8189ES_MAKE_ENV = \
					CROSS="$(TARGET_CROSS)" \
					LINUX_KERNEL_PATH="$(LINUX_DIR)" \
					LINUX_KERNEL_DIR="-I$(LINUX_DIR)/include" \



# $(MAKE) ARCH=$(ARCH) CROSS_COMPILE=$(CROSS_COMPILE) -C $(KSRC) M=$(shell pwd)  modules
ifeq ($(BR2_PACKAGE_RTKPACKAGE_SIGMATOOL), y)
define RTKPACKAGE_RTL8189ES_CONFIGURE_CMDS
    sed -i "s/CONFIG_80211W = [y|n]/CONFIG_80211W = y/g" $(@D)/Makefile
    sed -i "s/CONFIG_WIFI_TEST = [y|n]/CONFIG_WIFI_TEST = y/g" $(@D)/Makefile
endef
endif

define RTKPACKAGE_RTL8189ES_BUILD_CMDS
	$(RTKPACKAGE_RTL8189ES_MAKE_ENV) $(MAKE) -C $(@D) all
endef

define RTKPACKAGE_RTL8189ES_INSTALL_TARGET_CMDS
	mkdir -p $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/kernel/drivers/net/wireless/
	$(INSTALL) -p -m 644 $(@D)/8189es.ko $(TARGET_DIR)/lib/modules/$(LINUX_VERSION_PROBED)/kernel/drivers/net/wireless
endef

$(eval $(generic-package))
#---------------------------------------
# Compiler options
#---------------------------------------
#COMMON_FLAGS = -Wall -Werror -O2

#INCLUDE_DIR		= -I$(TOP)/include
#LINUX_KERNEL_DIR       = -I$(TOP)/../linux/linux-3.10.9/include
#LINUX_KERNEL_PATH      = "/home/barry/work/Phoenix/kernel/linux/linux-3.10.9"
#LINUX_KERNEL_DIR	= -I$(TOP)/../../../linux-kernel/include
#LINUX_KERNEL_PATH	= "$(TOP)/../../../linux-kernel"

#---------------------------------------
# Linker options
#---------------------------------------
#LIBS = -lpthread -lrt

#LIB_OSAL	= $(LIB_DIR)/libosal.so
