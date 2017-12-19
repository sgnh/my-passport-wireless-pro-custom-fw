#!/bin/bash

SCRIPT=$(readlink -f $0)
SCRIPTPATH=`dirname ${SCRIPT}`
cd $SCRIPTPATH

if [ "`pwd`" != "$SCRIPTPATH" ]; then
  echo "Something went wrong, not able to switch to $SCRIPTPATH"
  exit 1
fi

export LD_LIBRARY_PATH="${SCRIPTPATH}"
export PLEX_MEDIA_SERVER_HOME="${SCRIPTPATH}"
export PLEX_MEDIA_SERVER_MAX_PLUGIN_PROCS=6
export PLEX_MEDIA_SERVER_APPLICATION_SUPPORT_DIR="${SCRIPTPATH}/Library/Application Support"
export LC_ALL="en_US.UTF-8"
export LANG="en_US.UTF-8"
ulimit -s 3000


startme() {
   echo "Starting Plex Media Server"
   ./Plex\ Media\ Server &
}

stopme() {
   echo "Stopping Plex Media Server"
   if [[ -f "${PLEX_MEDIA_SERVER_APPLICATION_SUPPORT_DIR}/Plex Media Server/plexmediaserver.pid" ]]; then
     kill -3 `cat "${PLEX_MEDIA_SERVER_APPLICATION_SUPPORT_DIR}/Plex Media Server/plexmediaserver.pid"`
     echo "Quit sent to server. Waiting 3 seconds and force killing if not dead"
     sleep 3
   fi
   if [[ "`/usr/bin/ps -ef|egrep -e 'Plex Media Server|Plex DLNA Server'|grep -v grep|wc -l`" != "0" ]]; then
     echo "Force killing leftover procs"
     /usr/bin/ps -ef|egrep -e "Plex Media Server|Plex DLNA Server"|awk '{print $2}' |xargs kill -9
   else
     echo "Plex Media Server shutdown cleanly"
   fi
}
case $1 in
    start)
        startme
        ;;
    stop)
        stopme
        ;;
    restart)
        stopme;startme
        ;;
    *)
        echo "plexmediaserver.sh needs one of the folling options (start|stop|restart)"
esac
