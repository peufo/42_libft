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

run_test() {
	PATH_NAME=$1
	VERBOSE=$2
	RESULT=$($PATH_NAME)
	TEST_NAME=${PATH_NAME#*.test/build/}
	((TESTS_COUNT++))
	if [[ $RESULT == "" ]] ; then
		((TESTS_PASSED++))
		if $VERBOSE ; then
			success "$TEST_NAME\tOK"
		fi
	else
		warning "$TEST_NAME\tFAIL" 
		echo -e "./src/$TEST_NAME.c ./.test/$TEST_NAME.c\n"
		echo -e "$RESULT\n"
	fi
}

test() {
	info "\nMY TESTS\n"
	VERBOSE=$([[ $@ =~ "-v" ]] && echo true || echo false)
	TEST_NAME=$( echo $@ | sed 's/.*-n \(\w+\)/\1/')
	echo "name: $TEST_NAME"
	TESTS_COUNT=0
	TESTS_PASSED=0
	for P in .test/build/*
	do
		run_test "$P" "$VERBOSE"
	done
	
	if [[ $TESTS_PASSED == $TESTS_COUNT ]]; then
		success "All tests [$TESTS_PASSED/$TESTS_COUNT] passed 🎉🎉🎉"
	else
		success "[$TESTS_PASSED/$TESTS_COUNT] tests passed"
		warning "But $(($TESTS_COUNT - $TESTS_PASSED)) tests failed"
	fi

	info "\nUNITS TEST LIB (https://github.com/alelievr/libft-unit-test)\n"
	cd ../libft-unit-tests
	UNITS_TESTS=$(make f)
	UNITS_FAILS=$(cat ./result.log | sed -E '/.+:\ *(\[OK\]\ |\{protected\})+/d')
	
	if $VERBOSE ; then
		echo "$UNITS_TESTS"
	elif [[ $UNITS_FAILS == "" ]] ; then
		success "NO FAILS DETECTED 🎉🎉🎉"
	else
		warning "$UNITS_FAILS"
	fi
}

test $@