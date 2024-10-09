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
			if ! $VERBOSE ; then overwrite
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
	fi

	if ! $VERBOSE ; then echo ""
	fi
	for P in $TESTS_BUILD_DIR/*
	do
		run_test "$P" "$VERBOSE"
	done
	if ! $VERBOSE ; then overwrite
	fi

	if [[ $TESTS_PASSED == $TESTS_COUNT ]]; then
		success "All tests [$TESTS_PASSED/$TESTS_COUNT] passed 🎉🎉🎉"
	else
		success "[$TESTS_PASSED/$TESTS_COUNT] tests passed"
		warning "But $(($TESTS_COUNT - $TESTS_PASSED)) tests failed"
	fi

	# ENSURE TEST EXTERNE DIR existe
	EXT_TEST_DIR=".test/extern"
	if [ ! -d "$EXT_TEST_DIR" ] ; then
		mkdir "$EXT_TEST_DIR"
	fi

	# LIB-UNIT-TESTS
	EXT_TEST_REPO="https://github.com/alelievr/libft-unit-test"
	EXT_TEST="$EXT_TEST_DIR/libft-unit-tests"

	sed -i "s;LIBFTDIR	=	../libft;LIBFTDIR	=	$(pwd);" "$EXT_TEST/Makefile"

	info "\nUNITS TEST LIB ($EXT_TEST_REPO)\n"
	if [ ! -d "$EXT_TEST" ] ; then
		git clone "$EXT_TEST_REPO" "$EXT_TEST"
	fi
	EXT_TEST_OUTPUT=$(make -C "$EXT_TEST" f | tr -d '\0')
	EXT_TEST_FAILS=$(cat "$EXT_TEST/result.log" | sed -E '/.+:\ *(\[OK\]\ |\{protected\})+/d')
	if $VERBOSE ; then
		echo "$EXT_TEST_OUTPUT"
	elif [[ $EXT_TEST_FAILS == "" ]] ; then
		success "NO FAILS DETECTED 🎉🎉🎉"
	else
		warning "$EXT_TEST_FAILS"
	fi

	# WAR-MACHINE
	EXT_TEST_REPO="https://github.com/y3ll0w42/libft-war-machine"
	EXT_TEST="$EXT_TEST_DIR/libft-war-machine"
	info "\nLIBFT WAR MACHINE ($EXT_TEST_REPO)\n"
	if [ ! -d "$EXT_TEST" ] ; then
		git clone "$EXT_TEST_REPO" "$EXT_TEST"
		echo "$WAR_MACHINE_CONFIG" > "$EXT_TEST/my_config.sh"
	fi
	sed -i "/clear/d" "$EXT_TEST/grademe.sh"
	"$EXT_TEST/grademe.sh" -s -u ft_lstnew
}

WAR_MACHINE_CONFIG="
#!/bin/bash
PATH_LIBFT=\"$(pwd)\"
HEADER_DIR=\"\"
SRC_DIR=\"\"
PATH_DEEPTHOUGHT=\"\${PATH_TEST}\"
COLOR_OK=\"\${GREEN}\"
COLOR_FAIL=\"\${RED}\"
COLOR_WARNING=\"\${YELLOW}\"
COLOR_TITLE=\"\${BOLD}\${BLUE}\"
COLOR_FUNC=\"\${CYAN}\"
COLOR_PART=\"\${UNDERLINE}\${PURPLE}\"
COLOR_TOTAL=\"\${BOLD}\${YELLOW}\"
COLOR_DEEPTHOUGHT_PATH=\"\${BOLD}\${PURPLE}\"
"

test "$@"
