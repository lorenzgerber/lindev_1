#!/bin/bash

# setting some values
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'


echo "Checking makefile for 5D exercise"
echo "---------------------------------"

echo "- Building with 'all', checking for string 'Stop' in StdErr."

cd 5D/

if make all 2>&1 | grep -q 'Stop'
then
   echo -e "${RED}FAIL! Building with 'make all' not finished successfully."
else
  echo -e "${GREEN}SUCCESS!"
fi

echo -e "${NC}- Check for existance of executable"
if [ -e ./program1 ]
then
  echo -e "${GREEN}SUCCESS!"
else
  echo -e "${RED} FAIL! File 'program1' does not exist"
fi

echo -e "${NC}- Trying to Run Program and checking for correct output."
if ./program1 | grep -Pzoq 'A\nB\nC\nD\n'
then
  echo -e "${GREEN}SUCCESS!"
else
  echo -e "${RED}FAIL! Program did not produce expected output."
fi

echo -e "${NC} - Checking sanity of 'make install'"
sudo make install &>/dev/null
if [ -e /usr/bin/program1 ]
then
  echo -e "${GREEN}SUCCESS!"
else
  echo -e "${RED}FAIL! 'program1' not found in /usr/bin."
fi

echo -e "${NC} - Checking sanity of 'make uninstall'"
sudo make uninstall &>/dev/null
if ! [ -e /usr/bin/program1 ]
then
  echo -e "${GREEN}SUCCESS!"
else
  echo -e "${RED}FAIL! 'program1' not found in /usr/bin."
fi


echo -e "${NC} - Checking for removal of .o and executable files upon 'make clean'"
make clean &>/dev/null
count=`ls -1 *.o 2>/dev/null | wc -l`
if [ $count != 0 ]
then
  echo -e "${RED}FAIL! Not all .o and/or executalbes removed."
else
  echo -e "${GREEN}SUCCESS!"
fi


echo -e ${NC}
make clean &>/dev/null

cd ..
