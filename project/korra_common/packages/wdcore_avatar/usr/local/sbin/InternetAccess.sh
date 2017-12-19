#!/bin/bash
#
# ï¿?2014 Primax Technologies, Inc. All rights reserved.
#
# InternetAccess.sh 
#
#  
#   
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

#---------------------
# Begin Script
#---------------------
if [ -f "/etc/.device_Unconfigured" ]; then
	uplink=`/usr/local/sbin/wifi_client_ap_scan.sh --current`
	if [ "$uplink" == "" ]; then
		echo "InternetConnectionFailed"
		exit 0;
	fi
fi

ping -c 5 8.8.8.8 > /tmp/pingInternet
isConnectInternet=`cat /tmp/pingInternet | grep "100% packet loss" | wc -l`
if [ ${isConnectInternet} -eq 0 ]; then
	curl -4 --connect-timeout 5 "http://www.wdc.com/en/" > /dev/null 2>&1
	if [ $? != 0 ]; then
		curl -4 --connect-timeout 5 "http://www.google.com" > /dev/null 2>&1
		if [ $? != 0 ]; then
			echo "InternetConnectionFailed" > /tmp/InternetConnectionFailed
			exit 0;
		fi
	else
		if [ ! -f "/tmp/InternetConnection" ]; then
			/usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert > /dev/null 2>&1
			/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
			/usr/local/sbin/getNewPlexFirmwareUpgrade.sh immediate > /dev/null 2>&1
			/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
			date +%s > /tmp/InternetConnection
		else
			now_time=`date "+%s"`
			start_time=`cat /tmp/InternetConnection`
			time_diff=`expr $now_time - $start_time`
			if [ ! -f "/tmp/Rnum" ]; then
				expr 86400 + $RANDOM \* 2 > /tmp/Rnum
				number=`cat /tmp/Rnum`
			else
				number=`cat /tmp/Rnum`
			fi
			if [ "$time_diff" -gt "$number" ]; then
				/usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert > /dev/null 2>&1
				/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
				/usr/local/sbin/getNewPlexFirmwareUpgrade.sh immediate > /dev/null 2>&1
				/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
				date +%s > /tmp/InternetConnection
			fi
		fi
	fi
else
	cat /tmp/pingInternet | grep "package" > /dev/null 2>&1
	if [ $? != 0 ]; then
		curl -4 --connect-timeout 5 "http://www.wdc.com/en/" > /dev/null 2>&1
		if [ $? != 0 ]; then
			curl -4 --connect-timeout 5 "http://www.google.com" > /dev/null 2>&1
			if [ $? != 0 ]; then
				echo "InternetConnectionFailed"
				echo "InternetConnectionFailed" > /tmp/InternetConnectionFailed
				exit 0;
			fi
		fi
	fi
	
	if [ ! -f "/tmp/InternetConnection" ]; then
		/usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert > /dev/null 2>&1
		/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
		/usr/local/sbin/getNewPlexFirmwareUpgrade.sh immediate > /dev/null 2>&1
		/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
		date +%s > /tmp/InternetConnection
	else
		now_time=`date "+%s"`
		start_time=`cat /tmp/InternetConnection`
		time_diff=`expr $now_time - $start_time`
		
		if [ ! -f "/tmp/Rnum" ]; then
			expr 86400 + $RANDOM \* 2 > /tmp/Rnum
			number=`cat /tmp/Rnum`
		else
			number=`cat /tmp/Rnum`
		fi
		
		if [ "$time_diff" -gt "$number" ]; then
			/usr/local/sbin/getNewFirmwareUpgrade.sh immediate send_alert > /dev/null 2>&1
			/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
			/usr/local/sbin/getNewPlexFirmwareUpgrade.sh immediate > /dev/null 2>&1
			/usr/local/sbin/checkAutoUpdate.sh > /dev/null 2>&1
			date +%s > /tmp/InternetConnection
		fi
	fi
fi

#---------------------
# End Script
#---------------------
