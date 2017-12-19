#!/bin/bash

EXEC_PATH=$PWD
PATCH_FILE_DIR=$EXEC_PATH/project/prjPatches/rootfs_config_patch_dir
PATCH_TARGET_DIR=$TARGET_DIR
PATCH_SOURCE_CONFIG=$TARGET_DIR/../.config

DEFAULTSETTINGS_CONFIG=$(grep "BR2_PACKAGE_PMXPACKAGE_DEFAULTSETTINGS=y" ${PATCH_SOURCE_CONFIG} | wc -l)
if [ ${DEFAULTSETTINGS_CONFIG} -eq "1" ]; then
   if [ -f ${PATCH_TARGET_DIR}/etc/default/build_defconfig.sh ]; then
       echo "Generated Default Settings"
       cd ${PATCH_TARGET_DIR}
       ${PATCH_TARGET_DIR}/etc/default/build_defconfig.sh
       rm -f ${PATCH_TARGET_DIR}/etc/default/build_defconfig.sh
       rm -f ${PATCH_TARGET_DIR}/etc/default/saveconfigfiles.txt
   fi
fi
