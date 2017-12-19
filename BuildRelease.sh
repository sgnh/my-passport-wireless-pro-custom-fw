#!/bin/bash

if [ "$1" = "" ]; then
	echo "Unknow command"
else
    while [ "$1" != "" ]
    do
        case "$1" in
            clean)
                echo "Clean build"
                ./SDKbuild.sh korra_rescue clean
                ./SDKbuild.sh korra_fwupg clean
                ./SDKbuild.sh korra_spi clean
                [ -f m.log ] && rm m.log
                ;;
            build)
                echo "Build FW image"
                ./SDKbuild.sh korra_rescue build
                ./SDKbuild.sh korra_fwupg build
                ./SDKbuild.sh korra_spi build
                ./SDKbuild.sh korra_spi genfw
                ;;
            *)
                echo "Unknow command"
                ;;
        esac
        shift 1
    done
fi


