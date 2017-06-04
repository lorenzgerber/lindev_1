#!/bin/bash

# test_electro
#
# test script for the
# electrotest application
#
# Lorenz Gerber 30.05.17


if [ -e "electrotest" ]; then
    echo "Usage: give path to electrotest as argument"
fi

eval ./electrotest

# Check for wrong resistnace values string, negative


# Check extreme values

# Check for division by zero errors
