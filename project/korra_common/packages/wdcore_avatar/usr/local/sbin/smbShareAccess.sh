#! /bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
#
#---------------------


PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf

#---------------------
# Begin Script
#---------------------

if [ $# != 4 ]; then
	echo "usage: smbShareAccess.sh <add|modify|delete> <share_name> <username> <read_only|read_write>"
	exit 1
fi


if [ $1 != "modify" ]; then
	exit 1
else
	if [ $2 == "Public" ]; then
	
		if [ $4 == "read_only" ]; then
			writable="no" 
			sed -i 's/writable =.*/writable = '${writable}'/' ${smbConfig} |grep writable|sed -n '1p'
			
		fi
		
		if [ $4 == "read_write" ]; then
			writable="yes" 
			sed -i 's/writable =.*/writable = '${writable}'/' ${smbConfig} |grep writable|sed -n '1p'
			
		fi

	fi

	if [ $2 == "Private" ]; then
	
		if [ $4 == "read_only" ]; then
			writable="no" 
			sed -i 's/writable =.*/writable = '${writable}'/' ${smbConfig} |grep writable|sed -n '2p'
			
		fi
		
		if [ $4 == "read_write" ]; then
			writable="yes" 
			sed -i 's/writable =.*/writable = '${writable}'/' ${smbConfig} |grep writable|sed -n '2p'
			
		fi
		
	fi 	
fi

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



