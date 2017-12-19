#!/bin/bash

### Borads
#rtd1195_qa_nand         
#rtd1195_qa_emmc         
#rtd1195_qa_spi          
#rtd1195_demo_mustang    
#rtd1195_demo_horseradish

TARGET=rtd1195_qa_spi
OPT='AUTORUN=bcldr'

mkdir -p wifihdd
tar xvf static_lib/lib.tar -C static_lib/

cp include/configs/rtd1195_common_U2.h include/configs/rtd1195_common.h
make clean && \
    make distclean && \
    rm -f include/autoconf.mk && \
    make ${TARGET}_config && \
    make ${OPT}

    cp -a u-boot.bin examples/flash_writer_u/bootimage/uboot_textbase_0x00020000.bin
    cp -a bootloader.tar wifihdd/bootloader_nor.tar

cp include/configs/rtd1195_common_U3.h include/configs/rtd1195_common.h
make clean && \
    make distclean && \
    rm -f include/autoconf.mk && \
    #make rtd1195_qa_spi_config && \
    make ${TARGET}_config && \
    make CONFIG_SYS_TEXT_BASE=0x01400000 Config_SPI_BOOTCODE2=TRUE

    cp -a u-boot.bin examples/flash_writer_u/bootimage/uboot_textbase_0x01400000.bin
    cp -a bootloader.tar wifihdd/bootloader2_nor.tar

cp -a examples/flash_writer_u/bootimage/uboot_textbase_0x00020000.bin \
    examples/flash_writer_u/bootimage/uboot_textbase_0x01400000.bin \
    wifihdd/

#sudo cp -a ./examples/flash_writer_u/dvrboot.exe.bin /var/lib/tftpboot

