#!/bin/bash
#
# � 2012 Western Digital Technologies, Inc. All rights reserved.
#
# ledCtrl.sh 
#   This file defines generic LED APIs. It should be independent of the hw level. 
#   It implements the LED policies (from PRD/SFS docs) regardless of  LED 
#   access mechanism.
#

#---------------------

################################################################
# led_usage()
#    prints script usage
################################################################
function led_usage(){
    echo "$0.sh  [<event> <state>]"
    echo "<event> is one of these:"
    echo "     ${LED_EV[@]}"
    echo "<state> is one of these:"
    echo "     ${LED_STAT[@]}"

}

################################################################
#
# read_err_log(): 
#   returns array of logged error events
#
################################################################
function read_err_log() {
    local logfile=""
    
    if [ "$1" == "event" ]; then
        logfile=${TMP_ERR_LOG_EV}
    elif [ "$1" == "state" ]; then
        logfile=${TMP_ERR_LOG_ST}
    elif [ "$1}" == "err_state" ]; then
        logfile=${TMP_LED_CUR_STATE}
    elif [ "$1}" == "err_event" ]; then
        logfile=${TMP_LED_CUR_EVENT}
    fi
    if [ -f ${logfile} ]; then
       local curerr=( `cat ${logfile}` ) 
    else
       touch ${logfile} 
       local curerr=${logfile}
    fi
    #echo ${curerr[@]}

    cat ${logfile}
}

################################################################
#
# led_find_err( event ): 
#   errev=LED_EV_ 
#   returns index into the error log array if found or "1" 
#   otherwise.
#
################################################################
function led_find_err() {
    local errev=${1}
    local idx=0
    local curerr=(`read_err_log event`)

    for i in "${curerr[@]}"
    do
        if [ "$i" == "$errev" ]; then
           echo "$idx"
           return $idx
        fi
        idx=$(($idx+1))
    done 
    echo "1"
    return 1
}

################################################################
#
# led_find_index( type, name ): 
#   type=event|status
#   returns index into the event/status array if found or "1" 
#   otherwise.
#
################################################################
function led_find_index() {
    local arr_type=${1}
    local name=${2}
    local idx=0

    if [ "$arr_type" == "event" ]; then
        arr=( "${LED_EV[@]}" )
    elif [ "$arr_type" == "state" ]; then
        arr=( "${LED_STAT[@]}" )
    elif [ "$arr_type" == "pri_error" ]; then
        arr=( "${LED_EV_ERR_PRI[@]}" )
    elif [ "$arr_type" == "err_event" ]; then
        arr=( `cat $TMP_ERR_LOG_EV` )
    elif [ "$arr_type" == "err_state" ]; then
        arr=( `cat $TMP_ERR_LOG_ST` )
    fi

    for i in "${arr[@]}"
    do
        if [ "${i}" = "${name}" ]; then
           echo "$idx"
           return 0
        fi
        idx=$(($idx+1))
    done 
    echo ""
    return 1
}


################################################################
#
# led_log( event, state, what): 
#   errev=LED_EV_ : an event to add
#   state=error|warn|normal
#   what=add|rem  : 'add' or 'rem' will add or remove the 'errev' 
#                   from error log, respectively.
#   Note that it skips logging an error if the error already
#   exits. The function also enables the led color for the error
#   if applicable.
#
################################################################
function led_log() {
    local errev=${1}
    local errst=${2}
    local what=${3}

    local curerr_ev=(`read_err_log event`)
    local curerr_st=(`read_err_log state`)

    if [ "$what" == "add" ]; then
       err=`led_find_err $errev`
       #echo ">>>>>> errev = $errev, errst = $errst, erridx = $err"
       # only add the error if it was not loggged.
       if [ $err -eq 1 ]; then 
           LED_ERR_LOG_EV=( "${curerr_ev[@]}" "$errev" )
           echo ${LED_ERR_LOG_EV[@]} > $TMP_ERR_LOG_EV
           LED_ERR_LOG_ST=( "${curerr_st[@]}" "$errst" )
           echo ${LED_ERR_LOG_ST[@]} > $TMP_ERR_LOG_ST
       else
           # update just the state
           curerr_st[$err]=$errst
           echo ${curerr_st[@]} > $TMP_ERR_LOG_ST
       fi
    elif [ "$what" == "rem" ]; then
       idx=0
       for i in "${curerr_ev[@]}" 
       do
          if [ "$i" == "$errev" ]; then
              unset curerr_ev[$idx]
              unset curerr_st[$idx]
              echo ${curerr_ev[@]} > $TMP_ERR_LOG_EV
              echo ${curerr_st[@]} > $TMP_ERR_LOG_ST
              break
          fi
          idx=$(($idx+1))
       done 
    fi
}
################################################################
# led_log_ev_state(): 
#   This function will log current error event or state 
#
################################################################
function led_log_event_state() {
   local ev_st=$1
   local val=$2
 
   if [ "$ev_st" == "event" ]; then
      if [ "$val" == "" ]; then
         cat ${TMP_LED_CUR_EVENT}
      else
         echo $val > ${TMP_LED_CUR_EVENT}
      fi
   fi
   if [ "$ev_st" == "state" ]; then
      if [ "$val" == "" ]; then
         cat ${TMP_LED_CUR_STATE}
      else
         echo $val > ${TMP_LED_CUR_STATE}
      fi
   fi

}

################################################################
# led_set_color(): 
#   This function will determine error priority and enable the color
#   for the highest pririty error. 
#
################################################################
function led_set_color() {
   local evtype=$1
   local req_ev=$2
   local mode=""
   local lcolor=""
   local errlog=(`read_err_log event`)
   local errev=""

   #echo ${errlog[@]}
   for pri_err in "${LED_EV_ERR_PRI[@]}" 
   do
      errev=""
      for cur_err in "${errlog[@]}" 
      do
         # Get the currently highest priority error
         if [ "${pri_err}" == "${cur_err}" ]; then
            #echo "found priority ${cur_err}" 
            errev=$pri_err  
            break
         fi
      done
      if [ "$errev" != "" ]; then
         break;
      fi
   done

   # Otherwise, treat other errors as FIFO policy
   if [ "$errev" == "" ]; then
      errcnt=${#errlog[*]}
      if [ $errcnt -gt 0 ]; then
         errev=${errlog[0]}
         #echo "found FIFO ${cur_err}" 
      fi
   fi

   # Now set the error color if exists
   if [ "$errev" != "" ]; then
      if [ "$evtype" == "normal" ]; then
          cur_err_ev=`led_log_event_state event`
          cur_err_st=`led_log_event_state state`
          # if the corrected error is not "current" (for led color), 
          # keep the current error color
          if [ "$cur_err_ev" != "$req_ev" ]; then
              return 0
          else 
              evtype=$cur_err_st
          fi
      else
         # re-determine the event type (error/warn) for this event
         ev_idx=`led_find_index err_event ${errev}`
         if [ $? -ne 1 ]; then
             stlist=(`read_err_log state`)
             evtype=${stlist[$ev_idx]}
         fi
          
      fi
      err_idx=`led_find_index event ${errev}`
      if [ "$evtype" == "error" ]; then
         mode=${LED_ERR_MODE[$err_idx]}
         color=${LED_ERR_COLOR[$err_idx]}
         led_log_event_state event $errev
         led_log_event_state state error
      elif [ "$evtype" == "warn" ] || [ "$evtype" == "inprog" ]; then
         mode=${LED_WARN_MODE[$err_idx]}
         color=${LED_WARN_COLOR[$err_idx]}
         led_log_event_state event $errev
         led_log_event_state state warn
      fi
      #echo "==== $errev, ev_type= $evtype, err_idx= $err_idx, color= $color"
   else
      # otherwise  this appears to be the only error/warning which has been corrected.
      ev_idx=`led_find_index event $req_ev`
      mode=${LED_NORMAL_MODE[$ev_idx]}
      color=${LED_NORMAL_COLOR[$ev_idx]}
      # set curent error to null
      echo "" > ${TMP_LED_CUR_EVENT}
      echo "" > ${TMP_LED_CUR_STATE}
    
   fi

   # check for LED disabled
   if [ ! -f $ENABLE_FILE -o "`cat $ENABLE_FILE`" == "enabled" -o "$evtype" == "warn" -o "$evtype" == "error" ]; then
		# LED enabled
		led_ctrl no_blink
		led_ctrl ${mode} ${color}
		#echo ">>> mode = $mode, color = $color"
	else
		# LED disabled
		led_ctrl "off" "off"
	fi
}

function ledMain()
{
	################################################################
	# ledMain.sh _main( event, state)
	#   event = LED_EV_?
	#   state = LED_STAT_?
	#   returns '0' on success, non-zero otherwise 
	################################################################
	ev=$1
	st=$2

	if [ $# -eq 0 ]; then
	   led_usage
	   exit 1
	fi

	# Validate the event
	evidx=`led_find_index event ${ev}`
	if [ $? -eq 1 ]; then
	   led_usage
	   exit 2 
	fi

	case ${st} in
	   "LED_STAT_ERR" )
		  # log the error and set the color
		  led_log ${ev} error add
		  led_set_color error ${ev}
		  ;;
	   "LED_STAT_WARN" )
		  # log the warning and set the color
		  led_log ${ev} warn add
		  led_set_color warn ${ev}
		  ;;
	   "LED_STAT_OK" )
		  # remove logged error/warning for this event from queue
		  led_log ${ev} normal rem
		  led_set_color normal ${ev}
		  ;;
	   "LED_STAT_IN_PROG" )
		  led_log ${ev} inprog add 
		  led_set_color inprog ${ev}
		  ;;
		* )
		  led_usage
		  exit 3 
		  ;;

	esac

	exit 0
}	 
