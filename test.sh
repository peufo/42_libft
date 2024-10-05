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

	info "\nMY TESTS"
	TESTS_COUNT=0
	TESTS_PASSED=0
	for P in .test/build/*
	do
		RESULT=$($P)
		TEST_NAME=${P#*.test/build/}
		((TESTS_COUNT++))
		if [[ $RESULT == "" ]] ; then
			((TESTS_PASSED++))
			if [[ $1 == "-v" ]] ; then
				success "$TEST_NAME\tOK"
			fi
		else
			warning "$TEST_NAME\tFAIL" 
			echo -e "./src/$TEST_NAME.c ./.test/$TEST_NAME.c\n"
			echo -e "$RESULT\n"
		fi
	done
	
	if [[ $TESTS_PASSED == $TESTS_COUNT ]]; then
		success "All tests [$TESTS_PASSED/$TESTS_COUNT] passed 🎉🎉🎉"
	else
		success "[$TESTS_PASSED/$TESTS_COUNT] tests passed"
		warning "But $(($TESTS_COUNT - $TESTS_PASSED)) tests failed"
	fi

	info "\n\nUNITS TEST LIB (https://github.com/alelievr/libft-unit-test)\n"
	cd ../libft-unit-tests
	UNITS_TESTS=$(make f)
	UNITS_FAILS=$(cat ./result.log | sed -E '/.+:\ +(\[OK\]\ |\{protected\})+/d')
	
	if [[ $1 == "-v" ]] ; then
		echo "$UNITS_TESTS"
	else
		warning "$UNITS_FAILS"
	fi
}

test $@