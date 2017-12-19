#!/bin/bash
#
# � 2010 Western Digital Technologies, Inc. All rights reserved.
#
# storage_transfer_get_config.sh
#
# Used to update the auto Storage Transfer property in the configuration.
#

#---------------------

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /etc/nas/config/sdcard-param.conf
. /etc/system.conf

SlurpCONF="/etc/nas/config/sdcard-param.conf"
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
timestamp=$(date "+%Y.%m.%d-%H.%M.%S")
echo $timestamp ": storage_transfer_set_config.sh" $@ >> /tmp/backup.log

version_api=`cat /etc/version.packages | grep RESTAPI_2.4`
if [ "$version_api" == "" ]; then
	storageType=$1
	if [ "$storageType" != "sdcard" ] && [ "$storageType" != "usb" ]; then
		echo "storage_transfer_set_config.sh <sdcard | usb> [--auto_transfer true | false --transfer_mode move | copy]"
		exit 1
	fi
	shift
	while [ "$1" != "" ]; do
		case $1 in
			--auto_transfer )
							shift
                           	if [ "$1" == "true" ] || [ "$1" == "false" ]; then
                            	if [ "$storageType" == "sdcard" ]; then
                            		sed -i 's/AutoTransfer=.*/AutoTransfer='${1}'/' $SlurpCONF
                            	elif [ "$storageType" == "usb" ]; then
                            		sed -i 's/USB_TransferAuto=.*/USB_TransferAuto='${1}'/' $SlurpCONF
                            	fi
                            else
                            	exit 1
                            fi                              
                            ;;
			--transfer_mode )
							shift
                            if [ "$1" == "move" ] || [ "$1" == "copy" ]; then
                            	if [ "$storageType" == "sdcard" ]; then
                            		sed -i 's/TransferMode=.*/TransferMode='${1}'/' $SlurpCONF
                            	elif [ "$storageType" == "usb" ]; then
                            		sed -i 's/USB_ModeTransfer=.*/USB_ModeTransfer='${1}'/' $SlurpCONF
                            	fi
                            	
                            else
                            	exit 1
                            fi                              
                            ;;
      		* )             echo "storage_transfer_set_config.sh <sdcard | usb> [--auto_transfer true | false --transfer_mode move | copy]"
                            ;;      
		esac
		shift
	done

else
	while [ "$1" != "" ]; do
        case $1 in
			--auto_transfer )       shift
					if [ "$1" == "true" ] || [ "$1" == "false" ]; then
	                	sed -i 's/AutoTransfer=.*/AutoTransfer='${1}'/' /etc/nas/config/sdcard-param.conf
	                              else
	                                exit 1
	                              fi                              
	                              ;;
	                        --transfer_mode )       shift
	                              if [ "$1" == "move" ] || [ "$1" == "copy" ]; then
	                                sed -i 's/TransferMode=.*/TransferMode='${1}'/' /etc/nas/config/sdcard-param.conf
	                              else
	                                exit 1
	                              fi                              
	                              ;;
	      * )                     echo "storage_transfer_get_config.sh  --auto_transfer true --transfer_mode move"
	                              ;;      
	        esac
	        shift
	done

fi


exit 0
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

