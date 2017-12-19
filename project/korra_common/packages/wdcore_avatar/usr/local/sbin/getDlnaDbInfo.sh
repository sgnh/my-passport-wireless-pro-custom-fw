#!/bin/bash
#
# (c) 2013 Western Digital Technologies, Inc. All rights reserved.
#
# getDlnaDbInfo.sh 
#
#

# A sample output from the script is shown below 
# NOTE, the order of writing the values out is important; any other order will confuse the upper layers 
# ["version \"7.2.2-RC6\"","music_tracks \"1\"","pictures \"4\"","videos \"11\"","time_db_update \"1366415400\"","scan_in_progress \"false\""]

#This script is used by the server ON/OFF, server db rebuild/rescan scripts 




PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
. /usr/local/sbin/share-param.sh
. /etc/system.conf

TWONKY_IP="`cat /tmp/twonky_server`"

info_status=/tmp/info_status
twonky_dir=/CacheVolume/.twonkymedia


#include a helper function, wait_for_server_up
. /usr/local/sbin/waitForDlnaServerUp.sh

#get the counts from the db.info file; function used when server is OFF
function get_persistent_media_counts() {
    #The syntax parser is looking for  "parameter:value<newline>"
    if [ -f ${twonky_dir}/db.info ];then
        awk '
            BEGIN { FS=":"; RS = "\n"; }
            {
                if ($1 == "m") music_tracks = $2
                if ($1 == "p") pictures = $2
                if ($1 == "v") videos = $2
            }
            END {
                # print output
                printf("music_tracks \"%s\"\n", music_tracks); 
                printf("pictures \"%s\"\n", pictures); 
                printf("videos \"%s\"\n", videos); 
            }
        ' ${twonky_dir}/db.info
    else
        echo music_tracks \"0\"
        echo pictures \"0\"
        echo videos \"0\"
    fi
}

#get the counts in realtime by making curl calls; used when server is updating its db
function get_real_time_media_counts() {
    #write the status into temporary file, twonky_info_status and then immediately parse it
    info_status_all=`curl -s -crlf http://${TWONKY_IP}/rpc/info_status`
    echo $info_status_all > /tmp/twonky_info_status #see if this tmp file needs to be deleted
    
    #in Twonky 7 the syntax is "parameter|value<space>"
    awk '
	BEGIN { FS="|"; RS = " "; }
	{
		if ($1 == "musictracks") music_tracks = $2
		if ($1 == "pictures") pictures = $2
		if ($1 == "videos") videos = $2
	}
	END {
		# print output
		printf("music_tracks \"%s\"\n", music_tracks); 
		printf("pictures \"%s\"\n", pictures); 
		printf("videos \"%s\"\n", videos); 
	}
	' /tmp/twonky_info_status

}


# This is now a mix of getting the info directly with rpc calls if the server is enabled 
# or from persistemt storage if the server is diasbled
twonky_direct_get_info() {
    
    state=`cat /etc/nas/service_startup/twonky`

    if [ "$state" == "disabled" ]; then 
        if [ -d ${twonky_dir}/db ]; then
            version=`ls -l -t ${twonky_dir}/db | grep ^- | awk 'END{print $NF}'`
        else 
            version=0.0.0
        fi
        echo "version \"$version\""
		
        get_persistent_media_counts
    else 
        wait_for_server_up
        version=`curl -s http://${TWONKY_IP}/rpc/version`
        echo "version \"$version\""

        get_real_time_media_counts

        #get the dbupdate field in real-time; if "In Progress", then set scan_in_progress to true; else conver to Epoch time
        info_status_dbupdate=`curl -s http://${TWONKY_IP}/rpc/info_status | grep dbupdate`
        if [ "${info_status_dbupdate:0:20}" == "dbupdate|In Progress" ]; then 
            echo "time_db_update \"0\""
            echo "scan_in_progress \"true\"";
        else
            db_update_time=${info_status_dbupdate#dbupdate|} #delete the prefix, dbupdate|
            db_update_time=`date --date "$db_update_time" +%s` #change format to Epoch time; that's how the presentation layer needs it
            echo "time_db_update \"${db_update_time}\""
            echo "scan_in_progress \"false\"";
        fi
    fi    
}

# slower, from RPC get, legacy Twonky 5, NOT TESTED or called with  Twonky 7  integration
twonky_rpc_get_info() {
	# get info_status option from Twonky
	port=`getMediaServerPort.sh`

	curl "http://127.0.0.1:${port}/rpc/info_status" > ${info_status} 2>/dev/null
	if [ $? == 1 ]; then
		echo "Failed twonky get"
		exit 1
	fi

	awk '
	BEGIN { 
		FS = "|"; RS = "\n";
	}
	{
		if ($1 == "version") version = $2
		if ($1 == "musictracks") music_tracks = $2
		if ($1 == "pictures") pictures = $2
		if ($1 == "videos") videos = $2
		if ($1 == "dbupdate") time_db_update = $2
	}
	END {
		# print output
		printf("version \"%s\"\n", version); 
		printf("music_tracks \"%s\"\n", music_tracks); 
		printf("pictures \"%s\"\n", pictures); 
		printf("videos \"%s\"\n", videos);
		gsub("<br>","",time_db_update);
		gsub("<b>","",time_db_update);
		gsub("</b>","",time_db_update);
		printf("time_db_update %s\n", time_db_update); 
		if ( match(time_db_update, "In Progress") == 0 )
			print "scan_in_progress=false";
		else 
			print "scan_in_progress=true";
	}
	' ${info_status}
}
twonky_direct_get_info
#if [ -f ${twonky_dir}/db.info ] && [ -f ${twonky_dir}/scan_file.dat ]; then
#	twonky_direct_get_info > ${info_status} 
#fi
#cat ${info_status}
