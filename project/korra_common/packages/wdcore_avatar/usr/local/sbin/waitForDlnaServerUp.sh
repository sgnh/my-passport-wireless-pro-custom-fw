#
# (c) 2014 Western Digital Technologies, Inc. All rights reserved.
#
# This function will exit if the server is not ready within 15 seconds.
# TODO: Use bash logger to log the exception exit condition.
function wait_for_server_up(){
    server_up=0    # 0 is equivalent to false boolean flag
    sleep_count=0  # seconds counter
    while [[ $server_up -eq 0 && $sleep_count -lt 15 ]]
    do
	sleep 1  # sleep 1 second.

	# Wait up to 5 seconds for Twonky to receive the curl request.
	response=`curl -m 5 -s "http://${TWONKY_IP}/rpc/get_all"`
	curl_exit_code=`echo $?`

	# Check for curl timeout, which means Twonky did not receive the curl request.
	if [ $curl_exit_code == 28 ]; then
		logger -p local5.err "waitForDlnaServerUp.sh: curl failure ${curl_exit_code}, getting Twonky initialization settings."
		return 1
	fi

	# Check if server is ready.
	if [ "$response" != "" ];
	then
	    server_up=1  # set boolean flag to true 
	fi

	sleep_count=`expr $sleep_count + 1`  # increment sleep count 1 second
    done

    if [ $sleep_count == 15 ];
    then
        logger -p local5.err "waitForDlnaServerUp.sh: $sleep_count second timeout waiting for DLNA server to become operational"
        exit 1
    fi
}
