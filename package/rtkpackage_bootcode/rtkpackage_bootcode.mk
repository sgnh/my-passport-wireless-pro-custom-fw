################################################################################
#
# RTKPACKAGE_BOOTCODE
#
################################################################################

RTKPACKAGE_BOOTCODE_KORRA_VERSION=KD3_02
RTKPACKAGE_BOOTCODE_KORRA_LITE_VERSION=LD2_02
ifeq ($(BR2_PACKAGE_RTKPACKAGE_BOOTCODE_KORRA),y)
RTKPACKAGE_BOOTCODE_VERSION=$(RTKPACKAGE_BOOTCODE_KORRA_VERSION)
RTKPACKAGE_PMX_BOARD=KORRA
endif
ifeq ($(BR2_PACKAGE_RTKPACKAGE_BOOTCODE_KORRA_LITE),y)
RTKPACKAGE_BOOTCODE_VERSION=$(RTKPACKAGE_BOOTCODE_KORRA_LITE_VERSION)
RTKPACKAGE_PMX_BOARD=KORRA_LITE
endif
RTKPACKAGE_BOOTCODE_SITE_METHOD = local
RTKPACKAGE_BOOTCODE_SITE = $(TOPDIR)/project/prjPackages/bootcode/
RTKPACKAGE_BOOTCODE_UBOOT = $(@D)/uboot
RTKPACKAGE_BOOTCODE_MAKE_ENV = \
					CROSS="$(TARGET_CROSS)" \
					LINUX_KERNEL_PATH="$(LINUX_DIR)" \
					LINUX_KERNEL_DIR="-I$(LINUX_DIR)/include"
RTKPACKAGE_BOOTCODE_CONFIG = 'rtd1195_qa_spi'
RTKPACKAGE_BOOTCODE_BUILD_OPTS = 'AUTORUN=bcldr'


define RTKPACKAGE_BOOTCODE_CONFIGURE_CMDS
	sed -i "s/PMX_LOADER_VERSION\ .*/PMX_LOADER_VERSION\ \"$(RTKPACKAGE_BOOTCODE_VERSION)\"/g" $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/pmx_version.h
	sed -i "s/PMX_BOARD/$(RTKPACKAGE_PMX_BOARD)/g" $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/pmx_version.h
endef
define RTKPACKAGE_BOOTCODE_BUILD_CMDS
	mkdir -p $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/
	tar xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/static_lib/lib.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/static_lib
	cp $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common_U2.h $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common.h
	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) clean
	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) distclean
	rm -f $(RTKPACKAGE_BOOTCODE_UBOOT)/include/autoconf.mk
	make $(RTKPACKAGE_BOOTCODE_CONFIG)_config -C $(RTKPACKAGE_BOOTCODE_UBOOT) TOPDIR=$(RTKPACKAGE_BOOTCODE_UBOOT)
	make $(RTKPACKAGE_BOOTCODE_BUILD_OPTS) -C $(RTKPACKAGE_BOOTCODE_UBOOT)
	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/u-boot.bin $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x00020000.bin
	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/bootloader.tar $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader_nor.tar

	cp $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common_U3.h $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common.h
	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) clean
	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) distclean
	rm -f $(RTKPACKAGE_BOOTCODE_UBOOT)/include/autoconf.mk
	make $(RTKPACKAGE_BOOTCODE_CONFIG)_config -C $(RTKPACKAGE_BOOTCODE_UBOOT) TOPDIR=$(RTKPACKAGE_BOOTCODE_UBOOT)
	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) CONFIG_SYS_TEXT_BASE=0x01400000 Config_SPI_BOOTCODE2=TRUE
	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/u-boot.bin $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x01400000.bin
	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/bootloader.tar $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader2_nor.tar
	rm -rf $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/
	mkdir -p $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/
	tar -xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader_nor.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/ hw_setting.bin uboot.bin
	tar -xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader2_nor.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/ bootcode2.hdr uboot2.bin
	cat $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/hw_setting.bin $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/uboot.bin > $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/bootcode1.bin
	cat $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/bootcode2.hdr $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/uboot2.bin > $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/bootcode2.bin
	echo $(RTKPACKAGE_BOOTCODE_VERSION) > $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/bcver
endef


define RTKPACKAGE_BOOTCODE_INSTALL_TARGET_CMDS
	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x00020000.bin \
			$(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x01400000.bin \
				$(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/
	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/dvrboot.exe.bin $(BINARIES_DIR)/bootcode_$(RTKPACKAGE_BOOTCODE_VERSION).bin
	cd $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/
	tar -cf $(BINARIES_DIR)/bootcode.img -C $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/ bootcode1.bin bootcode2.bin bcver
endef

#ifeq ($(BR2_PACKAGE_RTKPACKAGE_BOOTCODE_KORRA_LITE),y)
#define RTKPACKAGE_BOOTCODE_CONFIGURE_CMDS
#	sed -i "s/PMX_LOADER_VERSION\ .*/PMX_LOADER_VERSION\ \"$(RTKPACKAGE_BOOTCODE_KORRA_LITE_VERSION)\"/g" $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/pmx_version.h
#	sed -i "s/PMX_BOARD/PMX_KORRA_LITE_BOARD\ \"$(RTKPACKAGE_BOOTCODE_KORRA_VERSION)\"/g" $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/pmx_version.h
#endef
#define RTKPACKAGE_BOOTCODE_BUILD_CMDS
#	mkdir -p $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/
#	tar xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/static_lib/lib.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/static_lib
#	cp $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common_U2.h $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common.h
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) clean
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) distclean
#	rm -f $(RTKPACKAGE_BOOTCODE_UBOOT)/include/autoconf.mk
#	make $(RTKPACKAGE_BOOTCODE_CONFIG)_config -C $(RTKPACKAGE_BOOTCODE_UBOOT) TOPDIR=$(RTKPACKAGE_BOOTCODE_UBOOT)
#	make $(RTKPACKAGE_BOOTCODE_BUILD_OPTS) -C $(RTKPACKAGE_BOOTCODE_UBOOT)
#	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/u-boot.bin $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x00020000.bin
#	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/bootloader.tar $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader_nor.tar
#
#	cp $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common_U3.h $(RTKPACKAGE_BOOTCODE_UBOOT)/include/configs/rtd1195_common.h
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) clean
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) distclean
#	rm -f $(RTKPACKAGE_BOOTCODE_UBOOT)/include/autoconf.mk
#	make $(RTKPACKAGE_BOOTCODE_CONFIG)_config -C $(RTKPACKAGE_BOOTCODE_UBOOT) TOPDIR=$(RTKPACKAGE_BOOTCODE_UBOOT)
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) CONFIG_SYS_TEXT_BASE=0x01400000 Config_SPI_BOOTCODE2=TRUE
#	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/u-boot.bin $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x01400000.bin
#	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/bootloader.tar $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader2_nor.tar
#	rm -rf $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/
#	mkdir -p $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/
#	tar -xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader_nor.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/ hw_setting.bin uboot.bin
#	tar -xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/bootloader2_nor.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/ bootcode2.hdr uboot2.bin
#	cat $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/hw_setting.bin $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/uboot.bin > $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/loader1.bin
#	cat $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/bootcode2.hdr $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/uboot2.bin > $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/loader2.bin
#endef


#define RTKPACKAGE_BOOTCODE_INSTALL_TARGET_CMDS
#	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x00020000.bin \
#			$(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/bootimage/uboot_textbase_0x01400000.bin \
#				$(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/
#	cp -a $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/dvrboot.exe.bin $(BINARIES_DIR)/bootcode_$(RTKPACKAGE_BOOTCODE_KORRA_LITE_VERSION).bin
#	cd $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/
#	tar -cf $(BINARIES_DIR)/bootcode_$(RTKPACKAGE_BOOTCODE_KORRA_LITE_VERSION).img -C $(RTKPACKAGE_BOOTCODE_UBOOT)/tmp_loader/ loader1.bin loader2.bin
#endef
#endif
#ifeq ($(BR2_PACKAGE_RTKPACKAGE_BOOTCODE_KORRA_DOCK),y)
#define RTKPACKAGE_BOOTCODE_BUILD_CMDS
#	mkdir -p $(RTKPACKAGE_BOOTCODE_UBOOT)/wifihdd/
#	tar xvf $(RTKPACKAGE_BOOTCODE_UBOOT)/static_lib/lib.tar -C $(RTKPACKAGE_BOOTCODE_UBOOT)/static_lib
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) clean
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) distclean
#	rm -f $(RTKPACKAGE_BOOTCODE_UBOOT)/include/autoconf.mk
#	echo "" > $(RTKPACKAGE_BOOTCODE_UBOOT)/examples/flash_writer_u/pmx.h
#	make rtd1195_qa_nand_config -C $(RTKPACKAGE_BOOTCODE_UBOOT) TOPDIR=$(RTKPACKAGE_BOOTCODE_UBOOT)
#	make -C $(RTKPACKAGE_BOOTCODE_UBOOT) 
#endef
#
#endif

$(eval $(generic-package))
