#############################################################
#
# lld2d 
#
#############################################################

LLD2D_VERSION = 0.0.1
LLD2D_SITE_METHOD = local
LLD2D_SITE = $(TOPDIR)/project/prjPackages/lld2d

define LLD2D_EXTRACT_CMDS
	cp -Ra $(DL_DIR)/$(LLD2D_SOURCE)/* $(@D)
endef

define LLD2D_INSTALL_TARGET_CMDS
	cp -a $(@D)/lld2d $(TARGET_DIR)/sbin
	cp -a $(@D)/icon.ico $(TARGET_DIR)/etc
	[ -f $(TARGET_DIR)/etc/init.d/S95lld2d ] || \
		install -D -m 0755 package/lld2d/S95lld2d \
			$(TARGET_DIR)/etc/init.d/S95lld2d			
endef

$(eval $(generic-package))
