#!/bin/bash

EXEC_PATH=$PWD
PATCH_FILE_DIR=$EXEC_PATH/project/prjPatches/rootfs_config_patch_dir
PATCH_TARGET_DIR=$TARGET_DIR
PATCH_FILE_NUM=$(ls -lR $PATCH_FILE_DIR | grep '^-' | wc -l)
PATCH_SOURCE_CONFIG=$EXEC_PATH/.config

cp -a $EXEC_PATH/project/prjPackages/recovery/automount.sh ${PATCH_TARGET_DIR}/sbin
#cp -a $EXEC_PATH/primax_packages/wdcore_avatar/sbin/updateFirmwareFromFile.sh ${PATCH_TARGET_DIR}/sbin
cp -a $EXEC_PATH/project/prjPackages/wdcore_avatar/etc/mdev.conf ${PATCH_TARGET_DIR}/etc

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
    patch -p0 < $PATCH_FILE_DIR/$FILENAME
done < /tmp/BUILDROOT_PATCH_TMP.$$

rm -rf /tmp/BUILDROOT_PATCH_TMP.$$

INIT_LIST=`ls ${PATCH_TARGET_DIR}/etc/init.d/`

for INIT in ${INIT_LIST[@]}
do
    chmod 777 ${PATCH_TARGET_DIR}/etc/init.d/${INIT}
done
    chmod 777 ${PATCH_TARGET_DIR}/sbin/updateFirmwareFromFile.sh


rm -rf ${PATCH_TARGET_DIR}/usr/lib/libncurses.so
rm -rf ${PATCH_TARGET_DIR}/usr/lib/libncurses.so.5
rm -rf ${PATCH_TARGET_DIR}/usr/lib/libncurses.so.5.9
rm -rf ${PATCH_TARGET_DIR}/usr/lib/libstdc++.so.6
rm -rf ${PATCH_TARGET_DIR}/usr/lib/libstdc++.so.6.0.17
rm -rf ${PATCH_TARGET_DIR}/usr/lib/libstdc++.so.6.0.17-gdb.py
rm -rf ${PATCH_TARGET_DIR}/lib/libcrypt-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libcrypt.so.1
rm -rf ${PATCH_TARGET_DIR}/lib/libdl-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libdl.so.2
rm -rf ${PATCH_TARGET_DIR}/lib/libm-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libnsl-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libnss_dns-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libnss_dns.so.2
#rm -rf ${PATCH_TARGET_DIR}/lib/libnss_files-2.15.so
#rm -rf ${PATCH_TARGET_DIR}/lib/libnss_files.so.2
rm -rf ${PATCH_TARGET_DIR}/lib/libpthread-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libpthread.so.0
rm -rf ${PATCH_TARGET_DIR}/lib/libresolv-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libresolv.so.2
rm -rf ${PATCH_TARGET_DIR}/lib/librt-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/librt.so.1
rm -rf ${PATCH_TARGET_DIR}/lib/libutil-2.15.so
rm -rf ${PATCH_TARGET_DIR}/lib/libutil.so.1







