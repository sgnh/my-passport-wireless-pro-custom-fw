#!/bin/sh
#
# (c) 2012 Western Digital Technologies, Inc. All rights reserved.
#
# monitorTemperature.sh 
# Note: This is called by init-script monitorTemperature
#
# This script is responsible to monitor temperature of internal drives
# and take actions if temperture is not normal
# 
# It takes following actions depending on temperature of internal drives
# if temperature of any drive > TF
#       - change led to RED
#       - send shutdown alert
#       - change run-level to emergency
#       - exit
#       
# if temperature of any drive between T2 & TF
#       - send shutdown-warning alert
#       - start a shutdown-warning timer of 1 HR
#       - if timer expires change run-level to emergency
#       - exit
#       
# if temperature of any drive between T1 & T2
#       - send high-temperature warning alert
#       - exit
#
# To restart all services & get back to normal
#   if temperature of all drives <= T2 - Hysterisis
#       - send normal temperature alert
#       - change led to GREEN
#       - change run-level to application
#       - exit
#

## --- Includes
PATH=/sbin:/bin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin
source /etc/nas/alert-param.sh         # ( for alerts )
source /usr/local/sbin/data-volume-config_helper.sh 2>/dev/null
source /usr/local/sbin/wdStatus.sh     # ( for $WDST_XXX status codes )
source /etc/wdcomp.d/wd-nas/temperature-monitor.conf
[ -f /usr/local/sbin/ledConfig.sh ] && . /usr/local/sbin/ledConfig.sh
. /etc/system.conf

## --- Constants


## Acronyms
NM=${STATE_NORMAL}
WR=${STATE_WARNING}
SW=${STATE_SHUTDOWN_WARNING}
SI=${STATE_SHUTDOWN_IMMEDIATE}
UK=${STATE_UNKNOWN}

## Internal Constants
## NB: TURN OFF BEFORE CHECKING-IN
DEBUG=0 ## for debugging

## For Testing
##      - set TEST=1
##      - set DEBUG=1
##      - disable the infinite "for MONITOR_TIMER" loop
##      - enter different temperatures on input
##      - to test with infinite "for MONITOR_TIMER" loop set different values for TEMP_TX
TEST=0

## Logger facility
FAC=local2

## Table of allowed actions based on last & curr state
## last | curr --       NM            WR               SW                SI              UK
##   |
eval ACTION${NM}="( act_noop      act_warning      act_start_timer   act_emergency   act_noop        )"
eval ACTION${WR}="( act_normal    act_noop         act_start_timer   act_emergency   act_noop        )"
eval ACTION${SW}="( act_normal    act_hysterisis   act_check_timer   act_emergency   act_check_timer )"
eval ACTION${SI}="( act_restart   act_hysterisis   act_cooldown      act_cooldown    act_cooldown    )"
eval ACTION${UK}="( act_UK_2_NM   act_warning      act_start_timer   act_emergency   act_noop        )" ## should never be called as UK state is never saved


## --- Global Variables

drive_list=
last_state=
curr_state=
curr_temp=


## --- Functions

## Get the drive temperature
##
## Input:   
## drive device (e.g. sda, sdb)
##
## Output:
## on success - drive temperature
## on failure - ""(empty)
##
## E.g. getDriveTemperature "/dev/sda"
getDriveTemperature()
{
    local drive
    local temp

    ## pass arguments
    drive=${1}    

    ## get the drive temperature using smart
    temp=`smartctl -d ata -A "${drive}" | \
          awk '{if ($2 == "Temperature_Celsius") print $10}'`
    echo "${temp}" > "${SMART_STATE}"

    ## return not found if number is not returned
    if ! [[ "${temp}" =~ ^[0-9]+$ ]]; then
        logger -p ${FAC}.err "$0: Non-numeric drive temperature \"${temp}\" obtained"
        return ${WDST_NOTFOUND}
    fi

    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Drive ${drive} temperature is ${temp}"
    fi

    ## output the temperature
    echo "${temp}"
    return ${WDST_OK}
}


## Get the current temperature state
##
## Input:   
## drive list (e.g. /dev/sda /dev/sdb)
##
## Output:
## on success - temperature state (e.g. NM, WR, SW, SI)
## on failure - ""(empty)
##
## E.g. determineCurrentState "/dev/sda /dev/sdb /dev/sdc"
determineCurrentState()
{
    local drive
    local temp
    local drive_temp
    local drive_state
    local prev_state
    local transition

    ## allowed temperature states transitions across all drives
    ## NB: "TRANSITION" is treated as a 2-D array
    ##  prev | next ---       NM    WR    SW    SI    UK
    ##    |
    eval TRANSITION${NM}="( ${NM} ${WR} ${SW} ${SI} ${UK} )"
    eval TRANSITION${WR}="( ${WR} ${WR} ${SW} ${SI} ${WR} )"
    eval TRANSITION${SW}="( ${SW} ${SW} ${SW} ${SI} ${SW} )"
    eval TRANSITION${SI}="( ${SI} ${SI} ${SI} ${SI} ${SI} )"
    eval TRANSITION${UK}="( ${UK} ${WR} ${SW} ${SI} ${UK} )"

    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Getting current temperature state"
    fi

    ## init
    drive_state=${NM}
    drive_temp=0

    ## loop through the drive list & finalize temperature state using
    ## TRANSITION table
    for drive in ${drive_list[@]}
    do
        ## save prev state & temp
        prev_state=${drive_state}

        ## get the current drive temperature
        temp=`getDriveTemperature "${drive}"`

        ## TEST ONLY
        if [ ${TEST} -ne 0 ]; then
            echo -n "Enter temperature: "
            read temp
            logger -p ${FAC}.debug "$0: INPUT temperature is ${temp}"
        fi

        ## reset temperature to 0 if not defined
        if [ $? -ne ${WDST_OK} ] || [ -z "${temp}" ]; then
            temp=0
        fi

        ## NB: ${temp} is integer value

        ## determine the temperature state of this drive
        if [ ${temp} -eq 0 ]; then
            state=${UK}
        elif [ ${temp} -le ${TEMP_T1} ]; then
            state=${NM}
        elif [ ${temp} -gt ${TEMP_T1} ] && [ ${temp} -le ${TEMP_T2} ]; then
            state=${WR}
        elif [ ${temp} -gt ${TEMP_T2} ] && [ ${temp} -le ${TEMP_TF} ]; then
            state=${SW}
        elif [ ${temp} -gt ${TEMP_TF} ]; then
            state=${SI}
        fi

        ## get the actual drive state using the TRANSITION table
        transition=TRANSITION${prev_state}[${state}]
        drive_state=${!transition}

        ## update drive temperature if state changes or temperature increases
        if [ ${drive_temp} -eq 0 ] || [ ${drive_state} -ne ${prev_state} ] || [ ${drive_temp} -lt ${temp} ]; then
			drive_temp=${temp}
        fi

        ## optimization: break the loop if current state is SI (shutdown immediate)
        if [ ${drive_state} -eq ${SI} ]; then break; fi
    done

    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Current Temperature - ${drive_temp}, Current State - ${drive_state}"
    fi

    ## pass to global variables
    curr_state=${drive_state}
    curr_temp=${drive_temp}

    return ${WDST_OK}
}


## --- Action Handlers

act_emergency()
{
    ## NB: curr_state is always ${SI} in this action

    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Shutdown, Temperature - ${curr_temp}"
    fi

    ## update the temp state file
    echo "${SI}" > "${TEMP_STATE}"

    ## set over temperature state
    touch "${OVER_TEMP_FLAG}"

    ## change led color to red
    ledCtrl.sh LED_EV_THERMO LED_STAT_ERR

    ## send over-temperature with immediate shutdown alert
    sendAlert.sh "${thermalShutdownImmediate}"

    ## stop the timer
    echo 0 > "${TEMP_SHUTDOWN_TIMER}"

    ## notify system for thermal state-change
    incUpdateCount.pm ${THERMAL_STATE_NFY_ID}

    ## log emergency
    logger -p ${FAC}.emerg "$0: Current temperature(${curr_temp}) is over max-threshold, stopping all services"

    ## change run-level to emergency
    changeRunLevel.pl --level=emergency

    return ${WDST_OK}
}

act_restart()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Restart, Temperature - ${curr_temp}"
    fi

    ## reset over-temperature state
    rm -f "${OVER_TEMP_FLAG}"

    ## change led color to green only if system health is good
    ledCtrl.sh LED_EV_THERMO LED_STAT_OK

    ## send normal temperature alert
    sendAlert.sh "${temperatureNormal}"

    ## update the temp state file
    echo "${NM}" > "${TEMP_STATE}"

    ## notify system for thermal state-change
    incUpdateCount.pm ${THERMAL_STATE_NFY_ID}

    ## log notice
    logger -p ${FAC}.notice "$0: Temperature of all drives(${curr_temp}) is now normal, restarting all services"

    ## change run-level to application mode
    changeRunLevel.pl --level=app
    
    return ${WDST_OK}
}

act_cooldown()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Cooldown, Temperature - ${curr_temp}"
    fi

    ## log notice
    logger -p ${FAC}.notice "$0: Current temperature(${curr_temp}) is still hot, maintaining shutdown"

    return ${WDST_OK}
}

act_noop()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action noop, Temperature - ${curr_temp}"
    fi

    ## no action taken

    return ${WDST_OK}
}

act_start_timer()
{
    ## NB: curr_state is always ${SW} in this action

    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Shutdown-Warning, Starting Timer, Temperature - ${curr_temp}"
    fi

    ## update the temp state file
    echo "${SW}" > "${TEMP_STATE}"

    ## change led color blinking yellow
    ledCtrl.sh LED_EV_THERMO LED_STAT_WARN

    ## send over-temperature with pending shutdown alert
    sendAlert.sh "${thermalShutdownPending}"

    ## start the shutdown timer
    date -u +%s > "${TEMP_SHUTDOWN_TIMER}"

    ## notify system for thermal state-change
    incUpdateCount.pm ${THERMAL_STATE_NFY_ID}

    ## log critical
    logger -p ${FAC}.crit "$0: Over-Temperature condition(${curr_temp}), Shutdown-Warning, Timer started"

    return ${WDST_OK}
}

act_check_timer()
{
    ## NB: curr_state is always ${SW} in this action

    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Shutdown-Warning, Checking Timer, Temperature - ${curr_temp}"
    fi

    ## get start timer, should never be 0
    start_time=( `cat "${TEMP_SHUTDOWN_TIMER}"` )
    if [ ${start_time} -eq 0 ]; then return ${WDST_FAILED}; fi

    ## get current time
    curr_time=( `date -u +%s` )

    ## no action if timer has not expired
    ## NB: Temperature state shall remain SW
    if [ $(( ${curr_time} - ${start_time} )) -le ${MAX_SW_TIME} ]; then
        ## debug
        if [ ${DEBUG} -ne 0 ]; then
            logger -p ${FAC}.debug "$0: Timer has not expired"
        fi

        return ${WDST_OK}
    fi

    ## --- Timer has expired

    ## log critical
    logger -p ${FAC}.notice "$0: Over-Temperature condition(${curr_temp}), Timer expired"

    ## stop the timer
    echo 0 > "${TEMP_SHUTDOWN_TIMER}"

    ## reset disk-smart led event
    ledCtrl.sh LED_EV_THERMO LED_STAT_OK

    ## modify state to SI
    curr_state=${SI}

    ## initiate last_state->SI action

    ## execute the action based on last & current state
    action_hdlr=ACTION${last_state}[${curr_state}]
    ${!action_hdlr}

    return $?
}

act_warning()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Normal -> Warning, Temperature - ${curr_temp}"
    fi

    ## update the temp state file
    echo "${WR}" > "${TEMP_STATE}"

    ## send high-temperature warning
    sendAlert.sh "${systemTemperatureHigh}"

    ## notify system for thermal state-change
    incUpdateCount.pm ${THERMAL_STATE_NFY_ID}

    ## log
    logger -p ${FAC}.warning "$0: High-Temperature(${curr_temp}) condition detected"

    return ${WDST_OK}
}

act_normal()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Shutdown-Warning -> Normal, Temperature - ${curr_temp}"
    fi

    ## stop the timer
    echo 0 > "${TEMP_SHUTDOWN_TIMER}"

    ## reset disk-smart led event
    ledCtrl.sh LED_EV_THERMO LED_STAT_OK

    ## send normal temperature alert
    sendAlert.sh "${temperatureNormal}"

    ## update the temp state file
    ## NB: Update state "after" all actions when switching to normal are completed
    echo "${NM}" > "${TEMP_STATE}"

    ## notify system for thermal state-change
    incUpdateCount.pm ${THERMAL_STATE_NFY_ID}

    ## log notice
    logger -p ${FAC}.notice "$0: Temperature of all drives(${curr_temp}) is now normal"

    return ${WDST_OK}
}

act_hysterisis()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Hysterisis, Temperature - ${curr_temp}"
    fi

    ## remain in last state if within hysterisis; otherwise update current state to normal
    if [ ${curr_temp} -gt $(( ${TEMP_T2} - ${HYSTERISIS} )) ]; then
        curr_state=${last_state}
    else
        curr_state=${NM}
    fi

    ## execute the action based on last & current state
    action_hdlr=ACTION${last_state}[${curr_state}]
    ${!action_hdlr}

    return $?
}

act_UK_2_NM()
{
    ## debug
    if [ ${DEBUG} -ne 0 ]; then
        logger -p ${FAC}.debug "$0: Action Unknown -> Normal, Temperature - ${curr_temp}"
    fi

    ## NB: No need to notify system state-change as last state was unknown

    ## update the temp state file
    echo "${NM}" > "${TEMP_STATE}"

    return ${WDST_OK}
}


## --- Main script
{
    ## exit if system has no internal drives
    driveList=( `internalDrives` )
    if [ "${driveList[@]}" == "0" ]; then
        exit 0
    fi


    ## get list of drives
    drive_list=( `internalDrives` )

    ## exit if no drives are found
    if [ -z "${drive_list}" ]; then
        exit 0
    fi

    logger -p ${FAC}.info "$0: Starting Temperature Monitor"

    ## init temp state to normal if not over temperature
    if [ ! -f "${TEMP_STATE}" ]; then
        echo "${NM}" > "${TEMP_STATE}"
        if [ -f "${OVER_TEMP_FLAG}" ]; then
            echo "${SI}" > "${TEMP_STATE}"
        fi
    fi

    ## init shutdown timer if not in shutdown-warning state
    last_state=( `cat ${TEMP_STATE}` )
    if [ ${last_state} -ne ${SW} ]; then
        echo 0 > "${TEMP_SHUTDOWN_TIMER}"
    fi

    ## loop every MONITOR_TIMER seconds
    ## NB: disable loop for if TEST=1
    for (( ; ; `sleep ${MONITOR_TIMER}`)); do
        ## debug
        if [ ${DEBUG} -ne 0 ]; then
            logger -p ${FAC}.debug "$0: Starting Temperature Monitor Run"
        fi

        ## get the last saved temperature state
        ## NB: This state was saved in an earlier run of this script
        last_state=( `cat ${TEMP_STATE}` )
        if [ $? -ne ${WDST_OK} ] || [ -z "${last_state}" ] || ! [[ "${last_state}" =~ ^[0-9]+$ ]] || [ ${last_state} -ge ${N_STATES} ]; then
            last_state=${NM}

            ## initialize the last state file
            echo "${NM}" > "${TEMP_STATE}"
        fi

        ## skip run if in standby & last state is normal
        if [ -f "${STANDBY_STATE}" ] && [ ${last_state} -eq ${NM} ]; then
            ## debug
            if [ ${DEBUG} -ne 0 ]; then
                logger -p ${FAC}.debug "$0: Skipping run as system is in standby"
            fi

            continue
        fi

        ## determine the current temperature state
        ## NB: This function shall set $curr_state & $curr_temp global vars
        determineCurrentState
        if [ $? -ne ${WDST_OK} ] || [ -z "${curr_state}" ]; then 
            ## debug
            if [ ${DEBUG} -ne 0 ]; then
                logger -p ${FAC}.debug "$0: Failed to determine current state; continuing" 
            fi

            continue
        fi

        ## execute the action based on last & current state
        ## NB: Cannot execute ${array${last_state}[${curr_state}]} directly
        ##     It must be saved in to a variable x & executed using ${!x}
        action_hdlr=ACTION${last_state}[${curr_state}]

        ## debug
        if [ ${DEBUG} -ne 0 ]; then
            logger -p ${FAC}.debug "$0: Last state=${last_state}; action=`echo ${!action_hdlr}`"
        fi

        ${!action_hdlr}

        if [ $? -ne ${WDST_OK} ]; then 
            logger -p ${FAC}.err "$0: Failed to execute the action `echo ${!action_hdlr}`; last state=${last_state}; curr temp=${curr_temp}"
            continue
        fi

        ## debug
        if [ ${DEBUG} -ne 0 ]; then
            logger -p ${FAC}.debug "$0: Finished Temperature Monitor Run" 
        fi

        ## break if TEST
        if [ ${TEST} -ne 0 ]; then
            logger -p ${FAC}.debug "$0: Finished Test Run" 
            break
        fi
    done ## for MONITOR_TIMER infinite loop

    logger -p ${FAC}.info "$0: Finished Temperature Monitor" 

    exit 0
}
## --- End of Main script
