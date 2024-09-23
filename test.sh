#!/bin/bash

warning() {
	echo -e "\033[31m$1\033[0m"
}
success() {
	echo -e "\033[32m$1\033[0m"
}

test() {
	for P in .test/build/*
	do
		RESULT=$($P)
		TEST_NAME=${P#*.test/build/}
		if [[ $RESULT == "" ]] ; then
			success "$TEST_NAME => SUCCESS" 
		else
			warning "$TEST_NAME => FAIL" 
			echo -e "./src/$TEST_NAME.c ./.test/$TEST_NAME.c\n"
			echo -e "$RESULT\n"
		fi		

	done
}

test