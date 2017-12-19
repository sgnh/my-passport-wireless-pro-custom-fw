#!/bin/bash
#
# (c) 2011 Western Digital Technologies, Inc. All rights reserved.
#
# genHostsConfig.sh - Script used to update /etc/hosts and /etc/dhcp3/dhclient.conf from hostname
#
# NOTE:  Caller to do all input validation
# Arg $1: -f, force reconfiguration
# Arg $2: UPGRADE_PATH, path offset [optional]
# echo "$0($@)"

FORCE='false'
UPGRADE_PATH=${upgradePath:-"/"}

# check options and get params
while [ $# -gt 0 ]; do 
  case "${1}" in
    -f|--force)    
        FORCE='true'
        ;;
    -p|--path)
        UPGRADE_PATH="${2}"
        shift
        ;;
  esac
  shift # next set of parameters
done

. ${UPGRADE_PATH}etc/system.conf
. ${UPGRADE_PATH}etc/nas/config/wd-nas.conf 2>/dev/null
. ${UPGRADE_PATH}etc/nas/config/networking-general.conf 2>/dev/null
. ${UPGRADE_PATH}etc/nas/config/orion-resources.conf 2>/dev/null

PKG="networking-general"
WDCOMP_DIR=${WDCOMP_DIR:-"/etc/wdcomp.d"}
SAVED_SETTINGS=${SAVED_SETTINGS:-"saved_settings"}
SAVED_SETTINGS_DIR="${WDCOMP_DIR}/${PKG}/${SAVED_SETTINGS}"
SAVED_PATH="${SAVED_SETTINGS_DIR}"

#hostname=`cat ${UPGRADE_PATH}${hostnameFile}`
hostname=`cat ${UPGRADE_PATH}etc/hostname`

#[ -z "${hostname}" ] && hostname=`cat ${UPGRADE_PATH}${SAVED_PATH}${hostnameFile}`
[ -z "${hostname}" ]
logger -s "hostname=$hostname"

echo "127.0.0.1       	localhost.localdomain localhost" > "${UPGRADE_PATH}etc/hosts"
echo "127.0.1.1		$hostname"							>> "${UPGRADE_PATH}etc/hosts"
#host_line="127.0.1.1        $hostname" 
# copy default hostsConfig file to run-time location if the correct 'host_line' is missing 
#[ -f "${UPGRADE_PATH}${hostsConfig}" ] && check_first=`head -n 1 ${UPGRADE_PATH}/${hostsConfig}`
#if [ "${FORCE}" == 'true' ] || [ "$check_first" != "$host_line" ]; then
    # generate new default hostsConfig file with correct hostname
#    echo $host_line                                              > "${UPGRADE_PATH}${hostsConfig}"
#    echo "::1             localhost ip6-localhost ip6-loopback" >> "${UPGRADE_PATH}${hostsConfig}"
#    echo "127.0.0.1       localhost.localdomain localhost"      >> "${UPGRADE_PATH}${hostsConfig}"
#    echo "fe00::0         ip6-localnet"                         >> "${UPGRADE_PATH}${hostsConfig}"
#    echo "ff00::0         ip6-mcastprefix"                      >> "${UPGRADE_PATH}${hostsConfig}"
#    echo "ff02::1         ip6-allnodes"                         >> "${UPGRADE_PATH}${hostsConfig}"
#    echo "ff02::2         ip6-allrouters"                       >> "${UPGRADE_PATH}${hostsConfig}"
   
#    [ ! -z "${wd2go_server}" ] && echo ${wd2go_server} >> "${UPGRADE_PATH}${hostsConfig}"
#fi


#echo "wd2go_server=${wd2go_server}"
exit 0
