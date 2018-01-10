#############################################################
#
# paragon-tools
#
#############################################################

PARAGON_TOOLS_VERSION = k3.10.24_2014-10-29_lke_9.4.4_b2
PARAGON_TOOLS_SOURCE = ufsd_utilites_Build_for__WD_Passport_wireless_$(PARAGON_TOOLS_VERSION).tar.gz

define PARAGON_TOOLS_EXTRACT_CMDS
	tar xvfz $(DL_DIR)/$(PARAGON_TOOLS_SOURCE) -C $(@D)
endef

define PARAGON_TOOLS_BUILD_CMDS
endef

define PARAGON_TOOLS_INSTALL_TARGET_CMDS
	cp -a $(@D)/* $(TARGET_DIR)/sbin/
endef

define PARAGON_TOOLS_INSTALL_INIT_SYSV
endef

$(eval $(generic-package))
