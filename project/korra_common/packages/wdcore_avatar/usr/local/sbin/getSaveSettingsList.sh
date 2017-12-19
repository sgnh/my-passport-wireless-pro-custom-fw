#!/bin/bash
#
# � 2011 Western Digital Technologies, Inc. All rights reserved.
#
# getSaveSettingsList.sh <component>  <mountBasePath>
#
# Gets the save settings file list for a given component and write to sdtout.  If <component> = all, returns save settings list for all components.
##
PKG=${1:-"all"}
patharg1=${2:-"/"}
# source shared definitions
[ -f /etc/system.conf ] && . /etc/system.conf 2>/dev/null
[ -f /etc/nas/config/wd-nas.conf ] && . /etc/nas/config/wd-nas.conf 2>/dev/null
WDCOMP_DIR=${WDCOMP_DIR:-"/etc/wdcomp.d"}
SETTINGS_DIR_NAME=${SETTINGS_DIR_NAME:-"saved_settings"}

if [ "$#" == "0" ]; then
        echo "usage: getSaveSettingsList.sh <pkg> [mountBasePath]"
        echo "          <component> = 'all' returns save settings list for all components"
        echo "          [mountBasePath] = optional path offset"
        exit 1
fi

if [ -f "/etc/version" ] && [ "`cat /etc/version`" == "01.05.07" ] && [ "${PKG}" == "all" ]; then
        (cd /usr/local/share/factoryDefault/; find etc -type f > /tmp/save_file_list)
        wait
        while read line
        do
            echo "$line"
        done < /tmp/save_file_list 
else
    if [ "${PKG}" == "all" ]; then
            ${patharg1}/usr/bin/find ${patharg1}/${WDCOMP_DIR}/*/saved_settings -type f -printf "/%P\n"
            # */
    elif [ "${PKG}" != "" ]; then
        if [ -d ${patharg1}/${WDCOMP_DIR}/${PKG}/saved_settings ]; then
            ${patharg1}/usr/bin/find ${patharg1}/${WDCOMP_DIR}/${PKG}/saved_settings -type f -printf "/%P\n"
        fi
    fi
fi
