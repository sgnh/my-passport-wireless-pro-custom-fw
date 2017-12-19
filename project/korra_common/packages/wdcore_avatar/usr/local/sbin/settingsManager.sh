#!/bin/bash
# settingsManager.sh
# © 2011-2012 Western Digital Technologies, Inc. All rights reserved.
#
# System settings manager script
##

copySettings ()
{
    local src="${1}"
    local tgt="${2}"
    local def="${3}"
    
    # Copy "saved_settings" file from source location to target path,
    # check corner cases: 'source path equals target path' and 'missing file'.
    if [ "${src}" == "${tgt}" ]; then
        [ -n "${verbose}" ] && logger -s -t "${logtag}" "paths are the same.."
        if [ -e "${tgt}" ]; then
            [ -n "${verbose}" ] && logger -s -t "${logtag}" "leaving target file \"as is\": \"${tgt}\""
        else
            [ -n "${verbose}" ] && logger -s -t "${logtag}" "source and target files are missing, restoring target from default:"
            cp -vfd "${def}" "${tgt}"
        fi
    else
        [ -n "${verbose}" ] && logger -s -t "${logtag}" "paths differ.."
        if [ -e "${src}" ]; then
            # this is the normal update action when versions match
            # and, this is the default update action when versions differ but no upgrade-patch script is found
            [ -n "${verbose}" ] && logger -s -t "${logtag}" "copying file:"
            cp -vfd "${src}" "${tgt}"          
        else
            [ -n "${verbose}" ] && logger -s -t "${logtag}" "source file is missing, restoring target from default:"
            cp -vfd "${def}" "${tgt}"
        fi
    fi
}
            
doUpgrade ()
{
    [ -n "${verbose}" ] && logger -s -t "${logtag}" "doUpgrade ( $@ )"
    local filename="${1}"
    local tgt_path="${2}/${1}"
    local def_path="${3}/${1}"
    local orig_path="${4}/${1}"
    local src_path=""
    local SRC_LIST=`mktemp "${upgradePath}/etc/nas/setmgr/srcpathlist-XXXX"`
    local upgrade_patch="${upgradePath}${WDCOMP_DIR}/upgrade/upgrade-patch_"*"_${filename}"
    ## Note: ${upgrade_patch} must not be quoted "" since the wildcard must be allowed to expand    
    
    if [ -n "${restorePath}" ]; then
        # search in restore point list
        find ${restorePath} -type f -printf "/%P\n" > ${SRC_LIST}
    else
        # search in 'old' saved_settings tree to ensure correct source path
        "${upgradePath}"/usr/local/sbin/getSaveSettingsList.sh all > ${SRC_LIST}
    fi
    # filenames must match exactly (but not the paths)
    while read filepath
    do
        if [ "${filepath}" == "${orig_path}" ]; then 
            src_path="${filepath}"
            # break on exact match
            break
        fi
        # Note: A "filname match only" condition is handled as a "path change".
        # -> This means that the following situation is NOT ALLOWED: 
        # -> Deletion of existing "path/filename" and simultaneous re-introduction of same "filename" but on a different path (in saved_setttings) for a new purpose. 
        if [ $(basename "${filepath}") == "${filename}" ]; then 
            src_path="${filepath}"
        fi
    done < ${SRC_LIST}
    if [ "${src_path}" == "" ]; then
        logger -s -t "${logtag}" "warning: missing source path for ${filename}"
        ## return 0 (don't return here so that new upgrade patches may be run, i.e. incomming with no existing source file path)
    fi
    # add path offset to restore-point if it exists
    [ -n "${restorePath}" ] && src_path=${restorePath}${src_path}

    # compare versions
    local version_old=${old_version}
    local version_new=${new_version}
    if [ "${version_old}" == "${version_new}" ] && [ ! -f ${upgrade_patch} ]; then
        [ -n "${verbose}" ] && logger -s -t "${logtag}" "versions match.."
        copySettings ${src_path} ${tgt_path} ${def_path}
    else
        [ -n "${verbose}" ] && logger -s -t "${logtag}" "versions differ and/or upgrade-patch exists.."
        # check for upgrade
        if [ -f ${upgrade_patch} ]; then
            [ -n "${verbose}" ] && logger -s -t "${logtag}" "executing upgrade patch:"
            run-parts --arg="${filename}" --arg="${PKG}" --arg="${old_version}" --arg="${new_version}" --arg="${src_path}" --arg="${tgt_path}" --arg="${def_path}" --arg="${upgradePath}" --regex=.*_${filename} "${upgradePath}"/etc/wdcomp.d/upgrade
        else
            [ -n "${verbose}" ] && logger -s -t "${logtag}" "no upgrade patch found, copying.."
            copySettings ${src_path} ${tgt_path} ${def_path}
        fi                  
    fi
    mv -f ${SRC_LIST} "${upgradePath}"/etc/nas/setmgr/srcpathlist_${PKG}_last
}

doSettings ()
{  
    [ -n "${verbose}" ] && logger -s -t "${logtag}" "doSettings( $@ )"
    mkdir -p "${upgradePath}"/etc/nas/setmgr
    local FILE_LIST=`mktemp "${upgradePath}"/etc/nas/setmgr/tgtpathlist-XXXX`
    # get the "new" saved_settings list of file paths - path changes must be handled via upgrade-patch files
    "${upgradePath}"/usr/local/sbin/getSaveSettingsList.sh ${PKG} "${upgradePath}" > ${FILE_LIST}
    # look in the original rootfs if no saved_settings were found in the upgrade rootfs
    [ ! -s ${FILE_LIST} ] && "${upgradePath}"/usr/local/sbin/getSaveSettingsList.sh ${PKG} > ${FILE_LIST}
    # process mount events for this package only if it has resources on the volume
    if [ "${SYS_EVENT}" == "mountvolume_data" ] && [ "${PKG_ACTION}" != 'restore_factory' ]; then
        grep -q '/CacheVolume' ${FILE_LIST}; cache=$?
        grep -q '/shares' ${FILE_LIST};      share=$?
        [ "${cache}" != "0" ] && [ "${share}" != "0" ] && return 0
    fi
    # select package maintainer scripts
    pkg_preinst="${upgradePath}/var/lib/dpkg/info/${PKG}.preinst"
    # logger -s -t "${logtag}" "pkg_preinst=${pkg_preinst}"
    pkg_postinst="${upgradePath}/var/lib/dpkg/info/${PKG}.postinst"
    # call pkg preinst script for extended actions (wd actions)
    if [ -f ${pkg_preinst} ]; then
        [ "${PKG_ACTION}" == 'update'          ] &&  ${pkg_preinst} 'update' ${old_version}
        [ "${PKG_ACTION}" == 'restore_nspt'    ] &&  ${pkg_preinst} 'update' ${old_version}
        [ "${PKG_ACTION}" == 'restore_factory' ] &&  ${pkg_preinst} 'restore'
        [ "${PKG_ACTION}" == 'test'            ] &&  ${pkg_preinst} 'test'
    fi
    # process saved_settings
    [ -f "${FILE_LIST}" ] && while read pathline
    do
        ## init paths
        filename=`basename "${pathline}"`
        # strip any filename from path
        pathline=`dirname "${pathline}"`
        def_path="${settings_dir}${pathline}"
        tgt_path="${upgradePath}${pathline}"
        # exclude paths on un-mounted volumes
        if [ "${mount_status}" != "0" ]; then
            echo "${pathline}" | grep -q '/CacheVolume'
            cache=$?
            echo "${pathline}" | grep -q '/shares'
            share=$?
            [ "${cache}" == "0" ] || [ "${share}" == "0" ] && continue
        fi
        # ensure target directory exists
        [ ! -d "${tgt_path}" ] && mkdir -pv "${tgt_path}"

        ## do settings actions
        case "${PKG_ACTION}" in
            upgrade|update|restore_nspt )
                # logger -s -t "${logtag}" "doUpgrade ${filename} ${tgt_path} ${def_path} ${pathline}"
                doUpgrade ${filename} ${tgt_path} ${def_path} ${pathline}
                ;;
            install )
                # update/restore saved_settings files from defaults
                cp -v -d -u "${def_path}/${filename}" "${tgt_path}/${filename}"
                ;;
            restore_factory )
                # restore all settings files from defaults
                cp -v -d --remove-destination "${def_path}/${filename}" "${tgt_path}/${filename}"
                ;;
            test )
                # restore missing settings files from defaults
                [ ! -e "${tgt_path}/${filename}" ] && cp -vfd "${def_path}/${filename}" "${tgt_path}/${filename}"
                [ -n "${verbose}" ] && [ -e "${tgt_path}/${filename}" ] && logger -s -t "${logtag}" "check file exists: ${tgt_path}/${filename} - ok"
                ;;
            * ) 
                logger -s -t "${logtag}" "invalid package action: ${PKG_ACTION}"
                ;;
        esac
    done < ${FILE_LIST}
    
    ## call pkg postinst script for extended actions (wd actions)
    if [ -f ${pkg_postinst} ]; then
        [ "${PKG_ACTION}" == 'update'          ] && ${pkg_postinst} 'update' ${old_version}
        [ "${PKG_ACTION}" == 'restore_nspt'    ] && ${pkg_postinst} 'update' ${old_version}
        [ "${PKG_ACTION}" == 'restore_factory' ] && ${pkg_postinst} 'restore'
        [ "${PKG_ACTION}" == 'test'            ] && ${pkg_postinst} 'test'
    fi
    # clean up 
    mv -f ${FILE_LIST} "${upgradePath}"/etc/nas/setmgr/tgtpathlist_${PKG}_last
}

doFirstBoot ()
{
    local boot_type=${1}
    local pkg_version=${2}
    logger -s -t "${logtag}" "run pkg bootup scripts:"   
    [ -d "/etc/wdcomp.d/boot" ] && run-parts --arg="${boot_type}" --arg="${pkg_version}" --regex=.*_${PKG} /etc/wdcomp.d/boot
}

getAction()
{
    case "${PKG_ACTION}" in
    
        install|upgrade )
            ;;
        update )
            [ ! -f "${sys_update}" ] && [ -n "${verbose}" ] && logger -s -t "${logtag}" "warning - update action without ${sys_update}"
            ;;
        restore|test )
            # 'test' action checks for restore cookie
            [ ! -f "${sys_restore}" ] && [ -n "${verbose}" ] && logger -s -t "${logtag}" "warning: restore without ${sys_restore}"
            [ "${PKG_ACTION}" == 'test' ] && [ ! -f "${sys_restore}" ] && return 0
            # check restore type: factory or nspt            
            [ -f "${sys_restore}" ] && nsptpath="`cat ${sys_restore}`"
            [ -n "${nsptpath}" ] && PKG_ACTION='restore_nspt'
            [ -z "${nsptpath}" ] && PKG_ACTION='restore_factory'
            if [ "${PKG_ACTION}" == 'restore_nspt' ]; then
                # set the nspt restore path
                restorePath="${nsptpath}"
                logger -s -t "${logtag}" "${PKG_ACTION} settings from path: ${restorePath:-'/'}"
            fi
            ;;
        factory_restore )
            logger -s -t "${logtag}" "forcing factory restore settings action.."
            PKG_ACTION='restore_factory'
            ;; 
        * ) 
            logger -s -t "${logtag}" "invalid package action: ${PKG_ACTION}"
            exit 0
            ;;
    esac
    logger -s -t "${logtag}" "getAction() = ${PKG_ACTION}"
}

cleanup ()
{
    # clean up system state "touch-files", upgrade files, etc. 
    rm -f "${sys_update}"
    rm -f "${sys_install}"
    rm -f /tmp/fw_update_status
    rm -f /etc/.fw_update_fail_check
    #rm -f /CacheVolume/*.deb  # */
    #rm -rf /CacheVolume/upgrade
}

## begin script
# logger -s -t "${logtag}" "$0($@): upgradePath= $upgradePath"
upgradePath=${upgradePath:-""}
restorePath=""
#verbose='true'
# check options and get params
while [ $# -gt 0 ]; do 
  case "${1}" in
    -a|--action)    
        ACTION="${2}"
        shift
        ;;
    -u|--upgradepath)
        upgradePath="${2}"
        shift
        ;;
    -r|--restorepath)
        restorePath="${2}"
        shift
        ;;
    -p|--package)
        PKG_LIST="${2}"
        shift
        ;;
    -e|--event)
        SYS_EVENT="${2}"
        shift
        ;;
    -v|--verbose)
        verbose='true'
        ;;
  esac
  shift # next set of parameters
done

PKG_ACTION=${ACTION:-"test"}
## set relative path
SAVE_PATH=$PATH
PATH="${upgradePath}/sbin:${upgradePath}/bin:${upgradePath}/usr/bin:${upgradePath}/usr/sbin:${upgradePath}/usr/local/bin:${upgradePath}/usr/local/sbin"
logtag='_'
[ -n "${verbose}" ] && logger -s -t "${logtag}" "BEGIN: $0 ($@)"
## source shared definitions
source "${upgradePath}/etc/system.conf" 2>/dev/null
WDCOMP_DIR=${WDCOMP_DIR:-"/etc/wdcomp.d"}
SAVED_SETTINGS=${SAVED_SETTINGS:-"saved_settings"}
PKG_LIST=${PKG_LIST:-"${setpkglist}"}
sys_update="${updateInProgress}"
sys_install="${freshInstall}"
sys_restore="${upgradePath}${RESTORE_SETTINGS_FROM_DIR_TRIGGER}"
# check mount status of internal volume 
mount_status=""
mount | grep -q '/CacheVolume'
mount_status=$?
mkdir -p /tmp/nas/maint_script
echo ${upgradePath:-"/"} > /tmp/nas/maint_script/upgradePath
echo ${restorePath:-"/"} > /tmp/nas/maint_script/restorePath
PKG=""
old_version=""
new_version=""
settings_dir=""

## Handle as 'boot event' or 'settings request'
if [ "${SYS_EVENT}" == "bootup" ]; then
    # Run component boot scripts (if present):
    # - "boot-update" if nas-safepoint is indicated
    # - "boot-fresh"  if factory-restore or first-time bootup
    # - "boot-system" if normal system boot up
    [ -f "${sys_restore}" ] && SAFEPOINT=`cat "${sys_restore}"` 2>/dev/null
    [ -f "${sys_restore}" ] && bootup='boot-fresh'
    [ -n "${SAFEPOINT}" ]   && bootup='boot-update'
    [ -f "${sys_install}" ] && bootup='boot-fresh'
    [ -f "${sys_update}"  ] && bootup='boot-update'
    bootup=${bootup:-'boot-system'}
    doFirstBoot ${bootup}
    cleanup
else
    # process the package list for requested action
    getAction
    for package in ${PKG_LIST}; do
        PKG="${package}"
        logger -s -t "${logtag}" "pkg: ${PKG}"
        package_dir="${upgradePath}${WDCOMP_DIR}/${PKG}"
        settings_dir="${upgradePath}${WDCOMP_DIR}/${PKG}/${SAVED_SETTINGS}"
        # set pkg version(s)
        old_version=`cat /tmp/nas/maint_script/${PKG}/oldpkgver 2>/dev/null`
        old_version=${old_version:-"$(dpkg-query -W -f='${Version}\n' $PKG)"}
        new_version=`cat /tmp/nas/maint_script/${PKG}/newpkgver 2>/dev/null`
        new_version=${new_version:-"$( dpkg-query --admindir=${upgradePath}/var/lib/dpkg -W -f='${Version}\n' ${PKG} )"} 
        doSettings
    done
fi
## restore path
PATH=$SAVE_PATH

[ -n "${verbose}" ] && logger -s -t "${logtag}" "END: $(basename $0) ($@)"
exit 0

