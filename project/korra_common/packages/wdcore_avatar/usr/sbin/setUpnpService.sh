#!/bin/sh

usage(){
	echo "Usage: setUpnpService.sh on|off"
}

[ $# != 1 ] && usage && exit 1
[ $1 != "on" ] && [ $1 != "off" ] && usage && exit 1

if [ $1 == "on" ]; then
	if [ -f "/etc/nas/config/upnp" ]; then
		rm -f /etc/nas/config/upnp
		if [ `pidof upnp_nas_device | wc -l` == "0" ]; then
			/etc/init.d/S91upnp restart
		fi 
	else
		echo "Upnp already on"
	fi 
elif [ $1 == "off" ]; then
	if [ ! -f "/etc/nas/config/upnp" ]; then
		touch /etc/nas/config/upnp
		if [ `pidof upnp_nas_device | wc -l` != "0" ]; then
			/etc/init.d/S91upnp stop
		fi
	else
		echo "UPnP already off"
	fi
fi
