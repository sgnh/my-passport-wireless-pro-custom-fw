#!/bin/bash

EXEC_PATH=$PWD
PATCH_FILE_DIR=$EXEC_PATH/project/prjPatches/rootfs_config_patch_dir
PATCH_TARGET_DIR=$TARGET_DIR

PATCH_FILE_NUM=$(ls -lR $PATCH_FILE_DIR/ | grep '^-' | wc -l)
PATCH_SOURCE_CONFIG=$EXEC_PATH/.config

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

DEFAULTSETTINGS_CONFIG=$(grep "BR2_PACKAGE_PMXPACKAGE_DEFAULTSETTINGS=y" ${PATCH_SOURCE_CONFIG} | wc -l)
if [ ${DEFAULTSETTINGS_CONFIG} -eq "1" ]; then
   if [ -f ${PATCH_TARGET_DIR}/etc/default/build_defconfig.sh ]; then
       echo "Generated Default Settings"
       ${PATCH_TARGET_DIR}/etc/default/build_defconfig.sh
       rm -f ${PATCH_TARGET_DIR}/etc/default/build_defconfig.sh
       rm -f ${PATCH_TARGET_DIR}/etc/default/saveconfigfiles.txt
   fi
fi

mv ${PATCH_TARGET_DIR}/etc/init.d/S40network ${PATCH_TARGET_DIR}/etc/init.d/S35network
mv ${PATCH_TARGET_DIR}/etc/init.d/S80dhcp-server ${PATCH_TARGET_DIR}/etc/init.d/S67dhcp-server
mv ${PATCH_TARGET_DIR}/etc/init.d/S90multi-role ${PATCH_TARGET_DIR}/etc/init.d/S73multi-role
mv ${PATCH_TARGET_DIR}/etc/init.d/S98powerprofile ${PATCH_TARGET_DIR}/etc/init.d/S90powerprofile
mv ${PATCH_TARGET_DIR}/etc/init.d/S01logging ${PATCH_TARGET_DIR}/etc/init.d/S02logging
mv ${PATCH_TARGET_DIR}/etc/init.d/S01rsyslog ${PATCH_TARGET_DIR}/etc/init.d/S05rsyslog
mv ${PATCH_TARGET_DIR}/etc/init.d/S20urandom ${PATCH_TARGET_DIR}/etc/init.d/S15urandom
mv ${PATCH_TARGET_DIR}/etc/init.d/S30dbus ${PATCH_TARGET_DIR}/etc/init.d/S20dbus
mv ${PATCH_TARGET_DIR}/etc/init.d/S35mdev ${PATCH_TARGET_DIR}/etc/init.d/S30mdev
mv ${PATCH_TARGET_DIR}/etc/init.d/S45ifplugd ${PATCH_TARGET_DIR}/etc/init.d/S40ifplugd
mv ${PATCH_TARGET_DIR}/etc/init.d/S48initdisk ${PATCH_TARGET_DIR}/etc/init.d/S43initdisk
mv ${PATCH_TARGET_DIR}/etc/init.d/S49factory-restore ${PATCH_TARGET_DIR}/etc/init.d/S47factory-restore
#mv ${PATCH_TARGET_DIR}/etc/init.d/S50lighttpd ${PATCH_TARGET_DIR}/etc/init.d/S53lighttpd
mv ${PATCH_TARGET_DIR}/etc/init.d/S50netatalk ${PATCH_TARGET_DIR}/etc/init.d/S55netatalk
mv ${PATCH_TARGET_DIR}/etc/init.d/S50sshd ${PATCH_TARGET_DIR}/etc/init.d/S57sshd
mv ${PATCH_TARGET_DIR}/etc/init.d/S51php-fpm ${PATCH_TARGET_DIR}/etc/init.d/S58php-fpm
mv ${PATCH_TARGET_DIR}/etc/init.d/S70vsftpd ${PATCH_TARGET_DIR}/etc/init.d/S63vsftpd
mv ${PATCH_TARGET_DIR}/etc/init.d/S80dhcp-relay ${PATCH_TARGET_DIR}/etc/init.d/S65dhcp-relay
mv ${PATCH_TARGET_DIR}/etc/init.d/S80swapfile ${PATCH_TARGET_DIR}/etc/init.d/S74swapfile
#mv ${PATCH_TARGET_DIR}/etc/init.d/S85wdmcserverd ${PATCH_TARGET_DIR}/etc/init.d/S70wdmcserverd
mv ${PATCH_TARGET_DIR}/etc/init.d/S91smb ${PATCH_TARGET_DIR}/etc/init.d/S75smb
mv ${PATCH_TARGET_DIR}/etc/init.d/S91upnp ${PATCH_TARGET_DIR}/etc/init.d/S77upnp
mv ${PATCH_TARGET_DIR}/etc/init.d/S92twonkyserver ${PATCH_TARGET_DIR}/etc/init.d/S80twonkyserver
#mv ${PATCH_TARGET_DIR}/etc/init.d/S92wdnotifierd  ${PATCH_TARGET_DIR}/etc/init.d/S83wdnotifierd
mv ${PATCH_TARGET_DIR}/etc/init.d/S95lld2d ${PATCH_TARGET_DIR}/etc/init.d/S85lld2d
#mv ${PATCH_TARGET_DIR}/etc/init.d/S95RestAPI ${PATCH_TARGET_DIR}/etc/init.d/S87RestAPI
mv ${PATCH_TARGET_DIR}/etc/init.d/S99crond  ${PATCH_TARGET_DIR}/etc/init.d/S93crond
mv ${PATCH_TARGET_DIR}/etc/init.d/S99fwupg ${PATCH_TARGET_DIR}/etc/init.d/S95fwupg
mv ${PATCH_TARGET_DIR}/etc/init.d/S99rsynchk ${PATCH_TARGET_DIR}/etc/init.d/S96rsynchk
mv ${PATCH_TARGET_DIR}/etc/init.d/S99syschk ${PATCH_TARGET_DIR}/etc/init.d/_S99syschk

