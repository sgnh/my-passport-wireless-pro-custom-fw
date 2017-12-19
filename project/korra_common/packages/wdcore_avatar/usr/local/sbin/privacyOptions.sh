#!/bin/bash
#
# (c) 2014 Western Digital Technologies, Inc. All rights reserved.
#
# privacyOptions.sh
#   returns true | false
#

PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin

if [ "$1" == "create" ]; then
    touch /etc/nas/.product_improvement_opt_in
elif [ "$1" == "delete" ]; then
      if [ -f /etc/nas/.product_improvement_opt_in ]; then
          rm -f /etc/nas/.product_improvement_opt_in
      fi
else 
      if [ -f /etc/nas/.product_improvement_opt_in ]; then
         echo "send_serial_number=true"
      else
         echo "send_serial_number=false"
      fi
fi
