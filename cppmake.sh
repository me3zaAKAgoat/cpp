#!/bin/bash

# Store the make command and its arguments in a variable
make_command="make $@"

# Execute the make command and capture its exit status
$make_command

# Check the exit status of make and conditions for running Cleaner_42.sh
if [ $? -eq 0 ] && (grep -q 'g++' Makefile || grep -q '\.cpp' Makefile) && ([ $# -eq 0 ] || [[ " $@ " =~ (^| )re($| ) ]]); then
	# If make exited successfully (exit status 0) and conditions are met, run Cleaner_42.sh
	echo 'Cleaner_42.sh is running in the background.'
	nohup ~/Cleaner_42.sh > /dev/null 2>&1 &
fi
