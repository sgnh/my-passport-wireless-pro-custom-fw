#!/bin/bash

EXEC_PATH=$PWD
PATCH_FILE_DIR=$EXEC_PATH/project/prjPatches/rootfs_config_patch_dir
PATCH_TARGET_DIR=$TARGET_DIR

PATCH_FILE_NUM=$(ls -lR $PATCH_FILE_DIR/ | grep '^-' | wc -l)
if [ $PATCH_FILE_NUM = 0 ]; then
    exit;
fi

mv ${PATCH_TARGET_DIR}/etc/init.d/S35network ${PATCH_TARGET_DIR}/etc/init.d/S40network
mv ${PATCH_TARGET_DIR}/etc/init.d/S67dhcp-server ${PATCH_TARGET_DIR}/etc/init.d/S80dhcp-server
mv ${PATCH_TARGET_DIR}/etc/init.d/S73multi-role ${PATCH_TARGET_DIR}/etc/init.d/S90multi-role
mv ${PATCH_TARGET_DIR}/etc/init.d/S90powerprofile ${PATCH_TARGET_DIR}/etc/init.d/S98powerprofile
mv ${PATCH_TARGET_DIR}/etc/init.d/S02logging ${PATCH_TARGET_DIR}/etc/init.d/S01logging
mv ${PATCH_TARGET_DIR}/etc/init.d/S05rsyslog ${PATCH_TARGET_DIR}/etc/init.d/S01rsyslog
mv ${PATCH_TARGET_DIR}/etc/init.d/S15urandom ${PATCH_TARGET_DIR}/etc/init.d/S20urandom
mv ${PATCH_TARGET_DIR}/etc/init.d/S20dbus ${PATCH_TARGET_DIR}/etc/init.d/S30dbus
mv ${PATCH_TARGET_DIR}/etc/init.d/S30mdev ${PATCH_TARGET_DIR}/etc/init.d/S35mdev
mv ${PATCH_TARGET_DIR}/etc/init.d/S40ifplugd ${PATCH_TARGET_DIR}/etc/init.d/S45ifplugd
mv ${PATCH_TARGET_DIR}/etc/init.d/S43initdisk ${PATCH_TARGET_DIR}/etc/init.d/S48initdisk
mv ${PATCH_TARGET_DIR}/etc/init.d/S47factory-restore ${PATCH_TARGET_DIR}/etc/init.d/S49factory-restore
#mv ${PATCH_TARGET_DIR}/etc/init.d/S53lighttpd ${PATCH_TARGET_DIR}/etc/init.d/S50lighttpd
mv ${PATCH_TARGET_DIR}/etc/init.d/S55netatalk ${PATCH_TARGET_DIR}/etc/init.d/S50netatalk
mv ${PATCH_TARGET_DIR}/etc/init.d/S57sshd ${PATCH_TARGET_DIR}/etc/init.d/S50sshd
mv ${PATCH_TARGET_DIR}/etc/init.d/S58php-fpm ${PATCH_TARGET_DIR}/etc/init.d/S51php-fpm
mv ${PATCH_TARGET_DIR}/etc/init.d/S63vsftpd ${PATCH_TARGET_DIR}/etc/init.d/S70vsftpd
mv ${PATCH_TARGET_DIR}/etc/init.d/S65dhcp-relay ${PATCH_TARGET_DIR}/etc/init.d/S80dhcp-relay

mv ${PATCH_TARGET_DIR}/etc/init.d/S74swapfile ${PATCH_TARGET_DIR}/etc/init.d/S80swapfile
#mv ${PATCH_TARGET_DIR}/etc/init.d/S70wdmcserverd ${PATCH_TARGET_DIR}/etc/init.d/S85wdmcserverd
mv ${PATCH_TARGET_DIR}/etc/init.d/S75smb ${PATCH_TARGET_DIR}/etc/init.d/S91smb
mv ${PATCH_TARGET_DIR}/etc/init.d/S77upnp ${PATCH_TARGET_DIR}/etc/init.d/S91upnp
mv ${PATCH_TARGET_DIR}/etc/init.d/S80twonkyserver ${PATCH_TARGET_DIR}/etc/init.d/S92twonkyserver
#mv ${PATCH_TARGET_DIR}/etc/init.d/S83wdnotifierd  ${PATCH_TARGET_DIR}/etc/init.d/S92wdnotifierd
mv ${PATCH_TARGET_DIR}/etc/init.d/S85lld2d ${PATCH_TARGET_DIR}/etc/init.d/S95lld2d
#mv ${PATCH_TARGET_DIR}/etc/init.d/S87RestAPI ${PATCH_TARGET_DIR}/etc/init.d/S95RestAPI
mv ${PATCH_TARGET_DIR}/etc/init.d/S93crond  ${PATCH_TARGET_DIR}/etc/init.d/S99crond
mv ${PATCH_TARGET_DIR}/etc/init.d/S95fwupg ${PATCH_TARGET_DIR}/etc/init.d/S99fwupg
mv ${PATCH_TARGET_DIR}/etc/init.d/S96rsynchk ${PATCH_TARGET_DIR}/etc/init.d/S99rsynchk
mv ${PATCH_TARGET_DIR}/etc/init.d/_S99syschk ${PATCH_TARGET_DIR}/etc/init.d/S99syschk

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
