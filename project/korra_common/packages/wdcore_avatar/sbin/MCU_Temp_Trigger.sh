#!/bin/bash
source /etc/power.conf
source /etc/TempControl.conf

if [ -f /tmp/test_MCU_Temp_Trigger_Debug ]; then
    _DEBUG="on"
else
    _DEBUG="off"
fi

function DEBUG()
{
 [ "$_DEBUG" == "on" ] &&  $@
}

DEBUG echo "`date` Battery $1, SMART $2"

Change_HighPerformance()
{
    DEBUG echo "Change to HighPerformance"
    /usr/local/sbin/setcpu.sh 2 1100000
}

Change_MidPerformance()
{
    DEBUG echo "Change to MidPerformance"
    /usr/local/sbin/setcpu.sh 2 800000
}

Change_BatteryPerformance()
{
    DEBUG echo "Change to BatteryPerformance"
    cpu1=`cat /sys/bus/cpu/devices/cpu1/online`
    /usr/local/sbin/setcpu.sh 2 500000
}

if [ ! -f /tmp/BatteryHDDTempWarning ]; then
    if [ "${powerprofile}" == "max_system_performance" ]; then
        if [ "$1" -gt "${BatteryTemp3}" ] || [ "$2" -gt "${HDDTemp3}" ]; then
            DEBUG echo "Performance:Status: Normal -> BT3 and HT3"
            DEBUG echo "Over Heat: Battery $1, SMART $2, Shutdown System...."
            /usr/local/sbin/sendAlert.sh 0006
            /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
            halt TempOver
            exit 0
        fi
        if [ "$1" -gt "${BatteryTemp2}" ] || [ "$2" -gt "${HDDTemp2}" ]; then
            DEBUG echo "Performance:Status: Normal -> BT2 and HT2"
            /usr/local/sbin/sendAlert.sh 0005
            /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
            touch /tmp/BatteryHDDTempWarning
            touch /tmp/BatteryHDDTempStage2
            Change_BatteryPerformance
            exit 0
        fi
        if [ "$1" -gt "${BatteryTemp1}" ] || [ "$2" -gt "${HDDTemp1}" ]; then
            DEBUG echo "Performance:Status: Normal -> BT1 and HT1"
            /usr/local/sbin/sendAlert.sh 0001
            /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
            touch /tmp/BatteryHDDTempWarning
            touch /tmp/BatteryHDDTempStage1
            Change_MidPerformance
            exit 0
        fi
    fi
    if [ "${powerprofile}" == "max_life" ]; then
        if [ "$1" -gt "${BatteryTemp3}" ] || [ "$2" -gt "${HDDTemp3}" ]; then
            DEBUG echo "BatteryLife:Status: Normal -> BT3 and HT3"
            DEBUG echo "Over Heat: Battery $1, SMART $2, Shutdown System...."
            /usr/local/sbin/sendAlert.sh 0006
            /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
            halt TempOver
            exit 0
        fi
        DEBUG echo "BatteryLife:Status: Normal"
    fi
    DEBUG echo "Status: Normal"
else
    if [ "${powerprofile}" == "max_system_performance" ]; then
        if [ -f /tmp/BatteryHDDTempStage1 ]; then
            if [ "$1" -lt "${BatteryTemp0}" ] && [ "$2" -lt "${HDDTemp0}" ]; then
                DEBUG echo "Performance:Status: BT1 and HT1 -> Normal"
                #/usr/local/sbin/sendAlert.sh 2003
                /usr/local/sbin/sendHWCollect.sh 103 Return $1 $2 ${powerprofile}
                rm -f /tmp/BatteryHDDTempWarning
                rm -f /tmp/BatteryHDDTempStage1
                Change_HighPerformance
                exit 0
            fi
            if [ "$1" -gt "${BatteryTemp2}" ] || [ "$2" -gt "${HDDTemp2}" ]; then
                DEBUG echo "Performance:Status: BT1 and HT1 -> BT2 and HT2"
                /usr/local/sbin/sendAlert.sh 0005
                /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
                rm -f /tmp/BatteryHDDTempStage1
                touch /tmp/BatteryHDDTempStage2
                Change_BatteryPerformance
                exit 0
            fi
            DEBUG echo "Status: BT1 and HT1"
        fi
        if [ -f /tmp/BatteryHDDTempStage2 ]; then
            if [ "$1" -lt "${BatteryTemp1}" ] && [ "$2" -lt "${HDDTemp1}" ]; then
                DEBUG echo "Performance:Status: BT2 and HT2 -> BT1 and HT2"
                /usr/local/sbin/sendAlert.sh 0001
                /usr/local/sbin/sendHWCollect.sh 103 Return $1 $2 ${powerprofile}
                rm -f /tmp/BatteryHDDTempStage2
                touch /tmp/BatteryHDDTempStage1
                Change_MidPerformance
                exit 0
            fi
            if [ "$1" -gt "${BatteryTemp3}" ] || [ "$2" -gt "${HDDTemp3}" ]; then
                DEBUG echo "Performance:Status: BT2 and HT2 -> BT3 and HT3"
                /usr/local/sbin/sendAlert.sh 0006
                /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
                halt TempOver
                exit 0
            fi
            DEBUG echo "Performance:Status: BT2 and HT2"
        fi
    fi
    if [ "${powerprofile}" == "max_life" ]; then
        if [ "$1" -gt "${BatteryTemp3}" ] || [ "$2" -gt "${HDDTemp3}" ]; then
            DEBUG echo "BatteryLife:Status: HDDTempWarning -> BT3 and HT3"
            DEBUG echo "Over Heat: Battery $1, SMART $2, Shutdown System...."
            /usr/local/sbin/sendAlert.sh 0006
            /usr/local/sbin/sendHWCollect.sh 103 Over $1 $2 ${powerprofile}
            halt TempOver
            exit 0
        fi
        DEBUG echo "BatteryLife:Status: Normal (Previous with Performance:Status:HDDTempWarning)"
    fi
fi
exit 0
