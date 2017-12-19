#!/bin/bash
source /usr/local/sbin/data-volume-config_helper.sh 2>/dev/null

function usage() {
    echo "usage $(basename $0) [delay] [duration]"
    echo "where:"
    echo "delay:     Delay between temperature readings within range $SLEEP_TIME_MIN and $SLEEP_TIME_MAX integer seconds."
    echo "           Default: 1 "
    echo "duration:  Over all time to sample temperature within range $MAX_TIME_MIN and $MAX_TIME_MAX integer seconds."
    echo "           Default: 2 "
}

#Limits
SLEEP_TIME_MIN=0
SLEEP_TIME_MAX=86400
MAX_TIME_MIN=0
MAX_TIME_MAX=86400

sleepTime=${1:-1}
maxTime=${2:-0}
totalTime=0

# Validate sleep time
echo "$sleepTime" | grep -q "[^0-9]"
if [ $? -eq 0 ]; then
    echo "$(usage)"
    exit 1;
fi
if [ $sleepTime -lt $SLEEP_TIME_MIN -o $sleepTime -gt $SLEEP_TIME_MAX ]; then
    echo "$(usage)"
    exit 1
fi

# Validate max time
echo "$maxTime" | grep -q "[^0-9]"
if [ $? -eq 0 ]; then
    echo "$(usage)"
    exit 1;
fi
if [ $maxTime -lt $MAX_TIME_MIN -o $maxTime -gt $MAX_TIME_MAX ]; then
    echo "$(usage)"
    exit 1
fi

# Get list of drives
driveList=(`internalDrives`)

# Verify at least one drive is present
if [ ${#driveList[@]} -eq 0 ]; then
    logger -s -p local2.warning "$0: No drives found"        
    exit 1
fi

while [ $totalTime -le $maxTime ]
do
  for drive in "${driveList[@]}"
  do
      temperature=`smartctl --all $drive | grep Temperature`
      if [ -n "$temperature" ]; then
          echo "$temperature"
      else
          logger -s -p local2.warning "$0: No temperature available"        
      fi
  done
  [ -f /sys/class/i2c-adapter/i2c-0/0-004c/temp2_input ] && cat /sys/class/i2c-adapter/i2c-0/0-004c/temp2_input
  [ -f /sys/class/i2c-adapter/i2c-0/0-004c/temp1_input ] && cat /sys/class/i2c-adapter/i2c-0/0-004c/temp1_input
  d=`date`
  echo "------ ${d}"
  sleep ${sleepTime}
  if [ $maxTime -ne 0 ]; then
	totalTime=`expr $totalTime + $sleepTime`
  fi
done
