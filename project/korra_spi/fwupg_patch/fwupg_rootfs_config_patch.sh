#!/bin/bash

EXEC_PATH=$PWD
PATCH_FILE_DIR=$EXEC_PATH/fwupg_patch/rootfs_config_patch_dir
PATCH_TARGET_DIR=$TARGET_DIR
PATCH_FILE_NUM=$(ls -lR $PATCH_FILE_DIR | grep '^-' | wc -l)
if [ $PATCH_FILE_NUM != 0 ]; then
	cd $PATCH_FILE_DIR

	PATCH_LIST=$(ls -Ald * | awk '{print $9}')

	echo "$PATCH_LIST" &> /tmp/BUILDROOT_PATCH_TMP.$$

	while read FILENAME
	do 
    	cd $PATCH_TARGET_DIR
    	patch -p0 < $PATCH_FILE_DIR/$FILENAME
	done < /tmp/BUILDROOT_PATCH_TMP.$$

	rm -rf /tmp/BUILDROOT_PATCH_TMP.$$
fi
rm -f $PATCH_TARGET_DIR/etc/init.d/S40network
mkdir -p $PATCH_TARGET_DIR/media/sda1/update
echo "$EXEC_PATH/output/images/MyPassportWireless-recover.bin"
if [ -f "$EXEC_PATH/output/images/MyPassportWireless-recover.bin" ]; then
    cp -a $EXEC_PATH/output/images/MyPassportWireless-recover.bin $PATCH_TARGET_DIR/media/sda1/update/
fi
if [ -f "$EXEC_PATH/output/images/rootfs.ubi" ]; then
    cp -a $EXEC_PATH/output/images/rootfs.ubi $PATCH_TARGET_DIR/media/sda1/update/
fi
if [ -f "$EXEC_PATH/output/images/WD_AVATAR.bin" ]; then
    cp -a $EXEC_PATH/output/images/WD_AVATAR* $PATCH_TARGET_DIR/media/sda1/update/
fi
