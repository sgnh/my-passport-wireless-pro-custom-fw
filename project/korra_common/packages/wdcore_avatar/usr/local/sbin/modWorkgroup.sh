#! /bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
#Script used to change host name and description.
#Usage:
#  machineName.sh Newname 'A nice description of machine'
#
# NOTE:  Caller to do all input validation
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf

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

if [ $# != 1 ]; then
	echo "usage: modWorkgroup.sh <workgroupName>"
	exit 1
fi


# Make changes
sed -e "/workgroup =/s/\(.*=\)\(.*\)/ workgroup = ${1}/" $sambaConfig> $sambaConfig-new
if [ $? != 0 ]; then
    exit 1
fi

# Replace config files
mv -f $sambaConfig-new $sambaConfig

/etc/init.d/S75smb reload

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



