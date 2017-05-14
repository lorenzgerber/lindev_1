#!/bin/bash

# timetrack.sh
#
# script that tracks
# time using an external
# log file (time.log). the
# script takes the arguments
# 'start', 'status' and 'stop'.
#
# Lorenz Gerber 14.05.2017

case $1 in
  start)
    if [ -f "time.log" ];
  	then
      echo "you already started the tracker"
	  else
      echo "starting time tracker"
		  echo "$(date +%s)" > ./time.log
	  fi
	;;
  status)
    if [ -f "time.log" ];
	  then
      typeset -i starttime=$(cat ./time.log)
		  typeset -i currenttime=$(date +%s)
		  elapsedtime=$(($currenttime-$starttime))
      echo "Tracker has been running for $elapsedtime seconds"
    else
		  echo "time tracker is not active"
	  fi
	  ;;
    stop)
    if [ -f "time.log" ];
	  then
		  typeset -i starttime=$(cat ./time.log)
		  typeset -i currenttime=$(date +%s)
		  elapsedtime=$(($currenttime-$starttime))
		  echo "Tracker has been running for $elapsedtime seconds"
		  echo "Removing tracker now..."
		  rm -f ./time.log
	  else
		  echo "time Tracker is not active"
	  fi
	;;
  *)
    echo "usage: timetrack start|status|stop"
	;;
esac
