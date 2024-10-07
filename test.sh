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
overwrite() {
	echo -e "\r\033[1A\033[0K$1"
}
overwrite_2() {
	echo -e "\r\033[2A\033[0K$1"
}

test() {
	info "\nMY TESTS\n"
	VERBOSE=$([[ $@ =~ "-v" ]] && echo true || echo false)
	TEST_NAME=$( echo $@ | sed 's/.*-n \(\w+\)/\1/')
	echo "name: $TEST_NAME"

	TESTS_COUNT=0
	TESTS_PASSED=0
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
			else
				overwrite "$(success "$TEST_NAME\tOK")"
			fi
		else
			if ! $VERBOSE ; then overwrite_2
			fi
			warning "$TEST_NAME\tFAIL" 
			echo -e "./$TEST_NAME.c ./.test/$TEST_NAME.c\n"
			echo -e "$RESULT\n"
		fi
	}

	TESTS_BUILD_DIR=".test/build"
	if [ ! -d  "$TESTS_BUILD_DIR" ] ; then
		warning "Tests are not compiled. Please run \"make test\""
		return
	else
		for P in $TESTS_BUILD_DIR/*
		do
			run_test "$P" "$VERBOSE"
		done
		if ! $VERBOSE ; then overwrite_2
		fi
	fi

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