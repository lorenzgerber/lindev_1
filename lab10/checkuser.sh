#!/bin/bash

# Lorenz Gerber, 16.01.2017
# Credits: This script was
# inspired by a onliner on
# ubuntuforums.org

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




