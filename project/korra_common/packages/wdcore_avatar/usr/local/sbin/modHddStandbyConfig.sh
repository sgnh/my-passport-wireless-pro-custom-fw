#! /bin/sh
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# modHddStanbyConfig.sh <enabled/disabled> <time>
#
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

. /etc/nas/config/share-param.conf
. /etc/system.conf

if [ $# != 2 ]; then
	echo "usage: modHddStanbyConfig.sh <enabled/disabled> <time>"
	exit 1
fi

	
#Ecmd="sed -i 's/standby_enable=.*/standby_enable=$1/' /etc/standby.conf"
#eval $Ecmd
#Tcmd="sed -i 's/standby_time=.*/standby_time=$2/' /etc/standby.conf"
#eval $Tcmd

if [ $1 == "disabled" ] || [ $2 == "0" ]; then
	
	Ecmd="sed -i 's/standby_enable=.*/standby_enable=disabled/' /etc/standby.conf"
	eval $Ecmd

	Tcmd="sed -i 's/standby_time=.*/standby_time=0/' /etc/standby.conf"
	eval $Tcmd
	hdparm -S 0 `cat /tmp/HDDDevNode`
else
	Ecmd="sed -i 's/standby_enable=.*/standby_enable=$1/' /etc/standby.conf"
	eval $Ecmd
	Tcmd="sed -i 's/standby_time=.*/standby_time=$2/' /etc/standby.conf"
	eval $Tcmd
	
	spintimer=$(($2*12))
	hdparm -S ${spintimer} `cat /tmp/HDDDevNode`
fi


exit 0
	
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

#if [ $# != 2 ]; then
#	echo "usage: modHddStanbyConfig.sh <enabled/disabled> <time>"
#	exit 1
#fi

#echo "standby_enable=$1" > /etc/standby.conf
#echo "standby_time=$2" >> /etc/standby.conf

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









