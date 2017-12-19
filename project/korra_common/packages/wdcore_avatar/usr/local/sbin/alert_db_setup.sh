#!/bin/bash                                                                                                                                                                                                                                                                     
#                                                                                                                                                                                                                                                                             
# . 2010 Western Digital Technologies, Inc. All rights reserved.                                                                                                                                                                                                              
#                                                                                                                                                                                                                                                                             
#  alert_db_setup.sh                                                                                                                                                                                                                                                  
#                                                                                                                                                                                                                                                                             
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin                                                                                                                                                                                                             
                                                                                                                                                                                                                                                                              
API_ROOT="/var/www/rest-api/api"                                                                                                                                                                                                                                              
alertdb="/CacheVolume/.wd-alert/wd-alert.db"                                                                                                                                                                                                                                  
alertdescdb="/CacheVolume/.wd-alert/wd-alert-desc.db"                                                                                                                                                                                                                         
                                                                                                                                                                                                                                                                              
if [ ! -d "/CacheVolume/.wd-alert" ]; then                                                                                                                                                                                                                                    
    mkdir /CacheVolume/.wd-alert                                                                                                                                                                                                                                              
    chmod 775 /CacheVolume/.wd-alert                                                                                                                                                                                                                                          
fi                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                              
if [ ! -s "${alertdescdb}" ]; then                                                                                                                                                                                                                                            
    cat $API_ROOT/Alerts/src/Alerts/Alert/Db/schema/wd-alert-desc.sql | sqlite3 ${alertdescdb}                                                                                                                                                                                
    chmod 775 /CacheVolume/.wd-alert/wd-alert-desc.db                                                                                                                                                                                                                         

    id=1;

    while read line
    do
       fifthChar=${line:4:1};
       if [ ! -z "$line" ] && [ "$fifthChar" != "D" ]; then
          OIFS=$IFS
          IFS='=' read -a posArray <<< "$line";
          alertCode=`echo ${posArray[0]} | sed -e 's/^ *//g' -e 's/ *$//g'`;
          alertDesc=`echo ${posArray[1]} | sed -e 's/^ *//g' -e 's/ *$//g'`;

          severity=1;
          if [ "$alertCode" -lt 1000 ]; then
             severity=1;
          elif [ "$alertCode" -lt 2000 ]; then
             severity=5;
          else
             severity=10;
          fi
          
          if [ "$alertCode" -eq 1610 ]; then
          	severity=10;
          fi
          if [ "$alertCode" -eq 1609 ]; then
          	severity=10;
          fi

          QUERY="INSERT INTO AlertDesc VALUES($id,$severity,'$alertCode','$alertDesc',2,1,1)"

          sqlite3 "${alertdescdb}" "${QUERY}" > /dev/null 2>&1

          id=$[$id +1]

          IFS=$OIFS
      fi
   done <'/etc/nas/strings/en_US/alertmessages.txt'                                                                                                                                                                                   
fi                                                                                                                                                                                                                                                                            
                                                                                                                                                                                                                                                                              
                                                                                                                                                                                                                                                                              
if [ ! -s "${alertdb}" ]; then                                                                                                                                                                                                                                                
    cat $API_ROOT/Alerts/src/Alerts/Alert/Db/schema/wd-alert.sql | sqlite3 ${alertdb}                                                                                                                                                                                         
    chmod 775 /CacheVolume/.wd-alert/wd-alert.db                                                                                                                                                                                                                              
    mkdir -p /etc/wdcomp.d/alerts/saved_settings/DataVolume/.wd-alert/
    cp /CacheVolume/.wd-alert/wd-alert.db /etc/wdcomp.d/alerts/saved_settings/DataVolume/.wd-alert/
    chmod 775 /etc/wdcomp.d/alerts/saved_settings/DataVolume/.wd-alert/
fi


