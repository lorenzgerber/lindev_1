#!/bin/bash

# checkuser.sh
#
# Checks if a username,
# either provided as argument or
# interactively asked for, is
# currently logged in to the system
# The result is returned as
# exit status only.
#
# Lorenz Gerber 14.05.2017

if [ -z $1 ] ; then
    echo "Enter username: "
    read u
else
    u=$1
fi

who | awk '{print $1}' |
    while read user;
    do [ "$u" = "$user" ] && exit 0;
    done
