#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modAcl.sh <share> <user> <RW/RO/NA> 
#
# Modifies ACL for a given user and share.  If the share is currently public, it will be changed to private.
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf
. /usr/local/sbin/data-volume-config_helper.sh
. /etc/nas/config/wd-nas.conf 2>/dev/null

#SYSTEM_SCRIPTS_LOG=${SYSTEM_SCRIPTS_LOG:-"/dev/null"}
## Output script log start info
#{ 
#echo "Start: `basename $0` `date`"
#echo "Param: $@" 
#} >> ${SYSTEM_SCRIPTS_LOG}
##
#{
#---------------------
# Begin Script
#---------------------

shareName=$1
username=$2
type=$3

if [ $# != 3 ]; then
	echo "usage: modAcl.sh <share> <username> <RW/RO/NA>"
	exit 1
fi

## check if share and user exists first
#getShares.sh all | grep -q -x $shareName
#if [ $? == 1 ]; then
#	echo "Share not found"
#	exit 1
#fi
#getUsers.sh | grep -q -x $username
#if [ $? == 1 ]; then
#	echo "User not found"
#	exit 1
#fi

# For backwards compatibility, accept "none" as "NA"
[ $type == "none" ] && type="NA"

if [ $type != "RW" ] && [ $type != "RO" ] && [ $type != "NA" ]; then
	echo "Must designate RW, RO, or NA for ACL"
	exit 1
fi

modifyTrusteesAcl()
{
	. /etc/system.conf
	shareName=$1
	username=$2
	type=$3
	awk -v share=$1 -v user=$2 -v type=$3 -v disk=$dataVolumeDevice '
	BEGIN {
		RS = "\n" ; FS = ":";
	}
	{
		sharepath = sprintf("[%s]/shares/%s",disk, share);
		if ( $1 == sharepath ) {
			printf("%s", $1);
			# search for user, if no match, print
			for (i=2; i <= NF-2; i=i+2) {
				if ( $i != user ) {
					printf(":%s:%s", $i, $(i+1));
				}
			}
			
			# either add or modify user as last field
			if (type != "NA") {
				printf(":%s", user);
				if ( type == "RW" ) {
					printf(":RWBEX");
				}
				else {
					printf(":RBE");
				}
			}
			# printf(":*:DU\n");
			printf(":*:CU\n");
		}
		else {
			print $0;
		}
	}
	' $trustees > $trustees-new
} 

modifySambaAcl()
{
	shareName=$1
	username=$2
	type=$3
	awk -v share=$1 -v username=$2 -v type=$3 '
	BEGIN {
		RS = "\n" ; FS = " ";
		state = 0;
	}
	function add_user_and_print_list(user, list)
	{
		printf("%s", user);
		for ( u in list ) 
			if ( list[u] != user ) printf(",%s", list[u]);
		printf("\n");		
	}
	function delete_user_and_print_list(user, list)
	{
		first = 1;
		for ( u in list ) {
			if ( list[u] != user ) {
				if ( first == 1 )
					printf("%s", list[u]);
				else 
					printf(",%s", list[u]);
				first = 0;
			}
		}
		printf("\n");		
	}
	{
		if (state == 0) {
			sharestring = sprintf("## BEGIN ## sharename = %s #",share);
			if ($0 == sharestring) {
				state = 1;
			}
			print $0;
		} else if (state == 1) {
			idx = match($0, " valid users =");
			if ( idx > 0 ) {
				#
				# valid user list
				#
				list_str = substr($0, (idx + RLENGTH));
				gsub(" ","",list_str);
				split(list_str , list, ",");
				printf("  valid users = ");
				if ( type == "NA" ) {
					delete_user_and_print_list( username, list);
				}
				else {
					add_user_and_print_list(username, list);
				}
			}
			else {
				idx = match($0, " read list =");
				if ( idx > 0 ) {
					#
					# read list
					#
					list_str = substr($0, (idx + RLENGTH));
					gsub(" ","",list_str);
					split(list_str , list, ",");
					printf("  read list = ");
					if ( type == "RO" ) {
						add_user_and_print_list( username, list);
					}
					else {
						delete_user_and_print_list( username, list);
					}
				}
				else {
					idx = match($0, " write list =");
					if ( idx > 0 ) {
						#
						# write user list
						#
						list_str = substr($0, (idx + RLENGTH));
						gsub(" ","",list_str);
						split(list_str , list, ",");
						printf("  write list = ");
						if ( type == "RW" ) {
							add_user_and_print_list( username, list);
						}
						else {
							delete_user_and_print_list( username, list);
						}
						state = 2;
					}
					else {
						print $0;
					}				
				}
			}
		}
		else {
			print $0;
		}
	}
	' $sambaOverallShare > $sambaOverallShare-new
} 

# If public, convert to private share in smb
getShares.sh public | grep -q -x $shareName
if [ $? -eq 0 ]; then
	#PUBLIC - change to private
	# save share desc
	shareDesc=`getShareDescription.sh $shareName`
	
	# remove share from overall share file
	cat $sambaOverallShare | sed "/## BEGIN ## sharename = $shareName #/,/## END ##/ d" > $sambaOverallShare-new

	# add to samba overall_share, public share by default
	echo "## BEGIN ## sharename = $shareName #" >> $sambaOverallShare-new
	echo "[$shareName]" >> $sambaOverallShare-new
	echo "  path = /shares/$shareName" >> $sambaOverallShare-new
	echo "  comment = $shareDesc" >> $sambaOverallShare-new
	echo "  invalid users =" >> $sambaOverallShare-new
	echo "  valid users = $username" >> $sambaOverallShare-new
	case $type in
	"RW")
		echo "  read list = " >> $sambaOverallShare-new
		echo "  write list = $username" >> $sambaOverallShare-new
		;;
	"RO")
		echo "  read list = $username" >> $sambaOverallShare-new
		echo "  write list = " >> $sambaOverallShare-new
		;;
	"NA")
		echo "Cannot remove user from public share"
		exit 1
		;;
	esac
	echo "  writeable = yes" >> $sambaOverallShare-new
	echo "  map read only = no" >> $sambaOverallShare-new
	echo "## END ##" >> $sambaOverallShare-new
	
	# remove line from trustees
	cat $trustees | grep -v "/shares/$shareName:" > $trustees-new
	# add back to trustees
	if [ $type == "RW" ]; then
		# echo "[$dataVolumeDevice]/shares/$shareName:$username:RWBEX:*:DU" >> $trustees-new
		echo "[$dataVolumeDevice]/shares/$shareName:$username:RWBEX:*:CU" >> $trustees-new
	else
		# echo "[$dataVolumeDevice]/shares/$shareName:$username:RBE:*:DU" >> $trustees-new
		echo "[$dataVolumeDevice]/shares/$shareName:$username:RBE:*:CU" >> $trustees-new
	fi
	
	# change file ACL to PRIVATE
	setShareAcl.sh "${PRIVATE_ACL}" "/shares/$shareName"
	
	updateShareBindMntDir.sh --update "$shareName" "private"
	
else
	# PRIVATE - modify ACL list
	modifyTrusteesAcl $shareName $username $type;
	modifySambaAcl $shareName $username $type;
fi

# modify file ACL for share directory
case $type in
	"RW")
		setfacl -m u:${username}:rwx "/shares/$shareName"
		setfacl -d -m u:${username}:rwx "/shares/$shareName"
		;;
	"RO")
		setfacl -m u:${username}:r-x "/shares/$shareName"
		setfacl -d -m u:${username}:r-x "/shares/$shareName"
		;;
	"NA")
		setfacl -x ${username} "/shares/$shareName"
		setfacl -d -x ${username} "/shares/$shareName"
		;;
esac
setfattr -n "${SYNC_ACL_ATTR}" -v "start" "/shares/$shareName"
daemon -U -X syncFileAcl.sh

mv -v $trustees-new $trustees
mv -v $sambaOverallShare-new $sambaOverallShare

setTrustees.sh 2> /dev/null

# reload
daemon -U -X "/etc/init.d/samba reload"
daemon -U -X "/etc/init.d/netatalk reload"

# regenerate apache group access files
genApacheAccessRules.sh
daemon -U -X "apache2ctl -k graceful"


# indicate that a change has been made to a share
incUpdateCount.pm "share"

#---------------------
# End Script
#---------------------
## Copy stdout to script log also
#} # | tee -a ${SYSTEM_SCRIPTS_LOG}
## Output script log end info
#{ 
#echo "End:$?: `basename $0` `date`" 
#echo ""
#} >> ${SYSTEM_SCRIPTS_LOG}
