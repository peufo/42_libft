#!/bin/bash

info() {
	echo -e "\033[36m$1\033[0m"
}
warning() {
	echo -e "\033[31m$1\033[0m"
}
success() {
	echo -e "\033[32m$1\033[0m"
}

test() {

	info "\nMY OWN TESTS"
	for P in .test/build/*
	do
		RESULT=$($P)
		TEST_NAME=${P#*.test/build/}
		if [[ $RESULT == "" ]] ; then
			success "$TEST_NAME\tOK" 
		else
			warning "$TEST_NAME\tFAIL" 
			echo -e "./src/$TEST_NAME.c ./.test/$TEST_NAME.c\n"
			echo -e "$RESULT\n"
		fi
	done

	info "\n\nUNITS TEST LIB (https://github.com/alelievr/libft-unit-test)\n"
	cd ../libft-unit-tests
	UNITS_TESTS=$(make f)
	UNITS_FAILS=$(cat ./result.log | sed -E '/.+:\ +(\[OK\]\ |\{protected\})+/d')
	warning "$UNITS_FAILS"
}

test