#!/bin/bash

EXEC_PATH=$PWD
PATCH_FILE_DIR=$EXEC_PATH/project/prjPatches/rootfs_config_patch_dir
PATCH_TARGET_DIR=$TARGET_DIR
PATCH_FILE_NUM=$(ls -lR $PATCH_FILE_DIR | grep '^-' | wc -l)
exit
if [ $PATCH_FILE_NUM = 0 ]; then
    exit;
fi

cd $PATCH_FILE_DIR

PATCH_LIST=$(ls -Ald * | awk '{print $9}')

echo "$PATCH_LIST" &> /tmp/BUILDROOT_PATCH_TMP.$$

while read FILENAME
do 
    cd $PATCH_TARGET_DIR
    patch -R -p0 < $PATCH_FILE_DIR/$FILENAME
done < /tmp/BUILDROOT_PATCH_TMP.$$

sleep 3

rm -rf /tmp/BUILDROOT_PATCH_TMP.$$
