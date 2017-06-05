#!/bin/bash

# test_electro
#
# test script for the
# electrotest application
#
# Lorenz Gerber 30.05.17

##################
# Check input args
##################
if [ $# -eq 0 ]
then
    echo "Usage: test_electro.sh /path/to/electrotest"
    exit
fi

if ! [ $1 == *"electrotest" ] && ! [ -e $1 ]
then
    echo "Usage: test_electro.sh /path/to/electrotest"
fi

#############################################
# Test normal operation with serial resitance
#############################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
S
2
13
31
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mnormal operation, serial resistances:"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if grep -q "0.02 W" $outputfile \
  	&& grep -q "44.0 ohm" $outputfile \
  	&& grep -q "39.0" $outputfile \
    && grep -q "4.7" $outputfile
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

###############################################
# Test normal operation with parallel resitance
###############################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
P
2
3
4
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mnormal operation, parallel resistances:"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if grep -q "0.58 W" $outputfile \
  	&& grep -q "1.7 ohm" $outputfile \
  	&& grep -q "1.5" $outputfile
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

###########################################
# Test error on negative number of resitors
###########################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
P
-1
1
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch negative number of resitors:"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

###########################################
# Check error on string as resistance value
###########################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
P
2
P
P
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch string as resistance value:"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

##########################################
# Check error on negative resistance value
##########################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
P
2
-10
-10
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch negative resistance value:"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

###################################
# Check for division by zero errors
###################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
0
P
1
0
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch division by zero:"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

##############################################
# Check error for extreme values on resistance
##############################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
P
1
100000000000000000000000000000000000000000000000000
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch out of range resistance value (1e50):"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

##############################################
# Check error for extreme number of resitances
##############################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
1
P
100000000000000000000000000000000000000000000000000
1
1
1
1
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch out of range components (1e50):"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi

###########################################
# Check error for extreme values on voltage
###########################################
outputfile=$(mktemp -t output.XXX)

./electrotest >$outputfile <<EOF 2>/dev/null &
100000000000000000000000000000000000000000000000000
P
1
1
EOF
lastPid=$!
sleep 0.01
echo -e "\e[33mcatch out of range voltage value (1e50):"
if ps -p $lastPid >&/dev/null
then
  echo -e "\t\t\t\t\t\t\e[31mFAIL on Time Out"
  kill $lastPid 2>/dev/null
else
  wait $lastPid
  status=$?

  if [ $status -ne 0 ]
  then
      echo -e "\t\t\t\t\t\t\e[32mSUCCESS"
  else
      echo -e "\t\t\t\t\t\t\e[31mFAIL"
  fi
  rm $outputfile
fi
