#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modExtraNtpServer.sh <ntpServer> 
#  Note: entering no argument removes extra ntp server
#
#

#---------------------



PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/system.conf
. /etc/nas/config/networking-general.conf 2>/dev/null

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

server=${1}

if [ $# -gt 1 ]; then
	echo "usage: modExtraNtpServer.sh <ntpServer>"
	exit 1
fi

# reject strings with spaces
echo $server | grep -q [[:space:]]
if [ $? == 0 ]; then
	echo "space detected in <ntpserver>"
	exit 1
fi

awk -v server=${server} '
BEGIN { 
    RS = "\n" ; FS = "=";
}
{
	if ( $1 == "NTPSERVERS" ) {
		# remove double quotes
		gsub("\"","",$2);
		split($2, list, " ");
		printf("NTPSERVERS=\"");
		if ( server != "" ) {
			printf("%s ",server);
		}
		for (i in list) n++;
		if (n == 2) {
			printf("%s %s\"\n",list[1],list[2]);
		}
		else {
			printf("%s %s\"\n",list[2],list[3]);
		}
	}
	else {
		print $0;
	}
}
' ${ntpConfig} > ${ntpConfig}-new

mv ${ntpConfig}-new ${ntpConfig}

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