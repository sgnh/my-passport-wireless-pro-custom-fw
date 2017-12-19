#!/bin/bash
#
if [ -f /tmp/sdstats ]; then
    cat /tmp/sdstats | grep "status=running" | wc -l
else
    echo 0		
fi

