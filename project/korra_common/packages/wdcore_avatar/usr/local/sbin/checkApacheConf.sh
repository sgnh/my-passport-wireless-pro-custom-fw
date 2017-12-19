#!/bin/sh

DEBUG=1
RETRY=3
RETRY_INT=1

TAR_C_VAR="czf"
TAR_X_VAR="xf"

LOG_FILE="/tmp/chkconf.log"
CONF_DEF_DIR="/etc/apache2"
CONF_BK_PATH="/etc/default/apache.conf"
APACHE_INIT="/etc/init.d/S51apache2"

REST_API_URL="http://localhost/api/2.6/rest/system_state?&auth_username=admin&auth_passw="

[ $DEBUG -eq 1 ] && TAR_C_VAR+="v" TAR_X_VAR+="v"

is_server_alive() {
	until [ $RETRY -eq 0 ]
	do
		CRET=`curl -m 3 -sL -w "%{http_code}\\n" $REST_API_URL -o /dev/null`
		[ $CRET -eq 200 ] && break;
		
		RETRY=$[$RETRY-1]
		sleep $RETRY_INT
	done
}

conf_backup() {
	tar $TAR_C_VAR $CONF_BK_PATH $CONF_DEF_DIR
}

conf_restore() {
	tar $TAR_X_VAR $CONF_BK_PATH -C /
}

echo > $LOG_FILE
is_server_alive
[ $DEBUG -eq 1 ] && echo $CRET >> $LOG_FILE

if [[ $CRET -eq 200 && ! -f $CONF_BK_PATH ]]; then
    [ $DEBUG -eq 1 ] && echo "do backup..." >> $LOG_FILE
	conf_backup
elif [[ $CRET -ne 200 && -f $CONF_BK_PATH ]]; then
	[ $DEBUG -eq 1 ] && echo "do restore..." >> $LOG_FILE
	conf_restore
	$APACHE_INIT restart
else
	[ $DEBUG -eq 1 ] && echo "do nothing..." >> $LOG_FILE
fi

exit 0
