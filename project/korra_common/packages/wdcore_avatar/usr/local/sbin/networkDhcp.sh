#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# NetworkDhcp.sh
#
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/share-param.conf
. /etc/nas/config/networking-general.conf 2>/dev/null
. /etc/nas/config/wifinetwork-param.conf

tmp_conf=/etc/.tmp_netconf

# do NOT change the interface file while the network is up
# ifdown relies on the values to shut down the gateway and
# to know whether to stop the dhcp client.
echo 0 > /tmp/ApCliRetry 

if [ "${STA_CHANNEL}" == 5 ]; then
	activeIF=${STA_IFACE}
else
	activeIF=${STA2G4_IFACE}
fi  
   
if [ "$STA_CLIENT" == "false" ]; then 
	exit 1

else
	connectStatus=`wpa_cli -i ${activeIF} status | grep -rsi wpa_state | awk -F= '{print $NF}'`
	if [ "$connectStatus" != "COMPLETED" ]; then
		exit 2
	fi
	
	connectedip=`wpa_cli -i ${activeIF} status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
	autoIp=`wpa_cli -i ${activeIF} status | grep -rsw "ip_address" | awk -F= '{print $NF}' | awk -F. '{print $1"."$2}'`
	if [ "$connectedip" == "" ] || [ "$autoIp" == "169.254" ]; then
		exit 3
	fi
	
	for ((renewDhcp=1; renewDhcp<5; renewDhcp++ )); do
   		/etc/init.d/S40ifplugd restart
		sleep 3
		/sbin/ifup ${activeIF}	
		connectedip=`wpa_cli -i ${activeIF} status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
		if [ "$connectedip" != "" ]; then
			break;
		fi	
	done
	
	connectedip=`wpa_cli -i ${activeIF} status | grep -rsw "ip_address" | awk -F= '{print $NF}'`
	if [ "$connectedip" == "" ]; then
		exit 4
	else 
		exit 0
	fi	
	
fi   
   

   


