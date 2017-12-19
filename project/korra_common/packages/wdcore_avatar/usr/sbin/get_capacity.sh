#!/bin/bash
# Return value define : [500GB] = 0; [1 TB] = 1; [2 TB] = 2; [3 TB] = 3; 

if [ -f /tmp/HDDCapacity ]; then
    cat /tmp/HDDCapacity
    exit 0
fi

DEV=$(cat /tmp/HDDDevNode);
STR=$(smartctl -a -d sat $DEV | grep 'User Capacity' | cut -d '[' -f2 | cut -d ' ' -f1 | cut -d '.' -f1);
	
if [ "$STR" == "500" ]; then
    echo 0;
    echo 0 > /tmp/HDDCapacity
elif [ "$STR" == "1" ]; then
    echo 1;
    echo 1 > /tmp/HDDCapacity
elif [ "$STR" == "2" ]; then
    echo 2;
    echo 2 > /tmp/HDDCapacity
elif [ "$STR" == "3" ]; then
    echo 3;
    echo 3 > /tmp/HDDCapacity
elif [ "$STR" == "4" ]; then
    echo 4;
    echo 4 > /tmp/HDDCapacity
elif [ "$STR" == "5" ]; then
    echo 5;
    echo 5 > /tmp/HDDCapacity
elif [ "$STR" == "6" ]; then
    echo 6;
    echo 6 > /tmp/HDDCapacity
else
    echo error:Cannot find capacity!;
fi

