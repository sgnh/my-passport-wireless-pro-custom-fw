#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# updateShareBindMntDir.sh <operation> <name> <option>
#   where <operation> is:
#		--init - Initialize share bind mnt dir
#		--add - add share bind mnt dir given <name>
#		--update - update share bind mnt dir given <name> <pubic/private>
#		--rename - rename share bind mnt dir given <name> <new_name>
#		--del - delete share bind mnt dir given <name>

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/wdcomp.d/wd-nas/wd-nas.conf 2>/dev/null

command=$1
name=$2
option=$3

# post entries log
logtag="`basename $0`:"
log()
{
    logger -p local2.info "${logtag}${@}"
}

log "$command $name $option"

#
# add_mount <share_name> <public/private>
#   - Add a bind mount given the <share_name>
#   - If <share_name> is a symlink to an external volume, then create the bind mount
#     directly to the external volume.
#
add_mount()
{
	share_name=$1
	mount_location="`readlink ${WD_SHARES_PATH}/${share_name}`"
	[ -z $mount_location ] && [ ! -d "${WD_SHARES_PATH}/${share_name}" ] && log "share ${share_name} does not exist" && exit 1;
	mkdir -p "${SHARE_BIND_MNT_DIR}/${share_name}"
	mount | grep -q "${SHARE_BIND_MNT_DIR}/${share_name} "
	if [ $? -ne 0 ]; then
		if [ -z ${mount_location} ]; then
			mount -o bind "${WD_SHARES_PATH}/${share_name}" "${SHARE_BIND_MNT_DIR}/${share_name}"
		else
			mount -o bind "${mount_location}" "${SHARE_BIND_MNT_DIR}/${share_name}"		
		fi
	fi
}

#
# update_mount <share_name> <public/private>
#   - Update a bind mount given the <share_name>, and <public/private> option
## note that ONLY external, publically accessible shares are available as bind mounts
#
update_mount()
{
	share_name=$1
	option=$2
	mount_location="`readlink ${WD_SHARES_PATH}/${share_name}`"
	if [ ! -z $mount_location ]; then
	    if [ "$option" == "public" ]; then
			# if mount does not exist, then add it
			mount | grep -q "${SHARE_BIND_MNT_DIR}/${share_name} "
			[ $? -ne 0 ] && add_mount $1 $2
		else
			# delete mount if private, external share
			delete_mount $1
		fi
	fi
}

#
# rename_mount <share_name> <new_name>
#   - Rename a bind mount (if it exists)
#
rename_mount()
{
	share_name=$1
	new_name=$2			
	mount | grep -q "${SHARE_BIND_MNT_DIR}/${share_name}"
	if [ $? -ne 0 ]; then
		delete_mount $1
		add_mount $2
	fi
}


#
# init_mounts 
#   - init bind mounts.  This will only init physical, non-hidden directories in the /shares directory
#
init_mounts()
{
	mount | grep -q "${SHARE_BIND_MNT_DIR}/"
	if [ $? -ne 0 ]; then
		# initial clean up of MNT dir
		rm -rvf ${SHARE_BIND_MNT_DIR}/*
	fi
	for D in `find /shares -maxdepth 1 -mindepth 1 -type d -not -name ".*"`; do 
		share_name=$(basename $D)
		add_mount "${share_name}"
	done
}


#
# delete_mount <share_name>
#   - Delete the bind mount to <share_name>
#
delete_mount() 
{
	share_name=$1
	umount -l "${SHARE_BIND_MNT_DIR}/${share_name}"
	status=$?
    if [ $status -eq 0 ]; then
		log "umount succeded" 
		rm -rf "${SHARE_BIND_MNT_DIR}/${share_name}"
	else
	    # lazy umount should not fail, but add log message in case
		log "umount failed $status"
	fi
}

case $command in
"--init")
	init_mounts
	;;
"--add")
	add_mount "${name}"
	;;
"--update")
	update_mount "${name}" "${option}"
	;;
"--rename")
	rename_mount "${name}" "${option}"
	;;
"--delete")
	delete_mount "${name}"
	;;
*)
	echo "Command not recognized"
	exit 1
	;;
esac

exit 0
