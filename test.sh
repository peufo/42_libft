#!/bin/sh

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

sed_i() {
	if [[ $(uname) == "Linux" ]] ; then
		sed -i "$@"
	else
		sed -i "" "$@"
	fi
}

test() {
	local usage=(
		"test [-h|--help]			Print this help"
		"test [-v|--verbose]			Print all test output"
		"test [-l|--lib] own|unit|war|tester	Choose a specific test lib to use"
		"test [-r|--reset]			Remove and re-download external libs"
	)
	local lib="all"
	local is_verbose=false
	local is_reset=false

	opterr() { echo >&2 "test: Unknown option '$1'" }

	while (( $# )); do
		case $1 in
		-h|--help)			printf "%s\n" $usage && return	;;
		-v|--verbose)		is_verbose=true					;;
		-r|--reset)			is_reset=true					;;
		-l|--lib)			shift; lib=$1					;;
		-l=*|--lib=*)		lib="${1#*=}"					;;
		-*)					opterr $1 && return 2			;;
		*)					positional+=("${@[@]}"); break	;;
		esac
		shift
	done

	run_test() {
		PATH_NAME=$1
		is_verbose=$2
		RESULT=$($PATH_NAME)
		TEST_NAME=${PATH_NAME#*.test/build/}
		((TESTS_COUNT++))
		if [[ $RESULT == "" ]] ; then
			((TESTS_PASSED++))
			if $is_verbose ; then
				success "$TEST_NAME\tOK"
			else
				overwrite "$(success "$TEST_NAME\tOK")"
			fi
		else
			if ! $is_verbose ; then overwrite
			fi
			warning "$TEST_NAME\tFAIL"
			echo -e "./$TEST_NAME.c ./.test/$TEST_NAME.c\n"
			echo -e "$RESULT\n"
		fi
	}

	TESTS_BUILD_DIR=".test/build"
	if [ ! -d  "$TESTS_BUILD_DIR" ] ; then
		info "Run \"make test\""
		make test
		return
	fi

	# MY OWN TESTS
	if [[ $lib == "all" || $lib == "own" ]] ; then
		info "\nMY OWN TESTS\n"
		local TESTS_COUNT=0
		local TESTS_PASSED=0
		if ! $is_verbose ; then echo "" ; fi
		for P in $TESTS_BUILD_DIR/*
		do
			run_test "$P" "$is_verbose"
		done
		if ! $is_verbose ; then overwrite ; fi
		if [[ $TESTS_PASSED == $TESTS_COUNT ]]; then
			success "All tests [$TESTS_PASSED/$TESTS_COUNT] passed 🎉🎉🎉"
		else
			success "[$TESTS_PASSED/$TESTS_COUNT] tests passed"
			warning "But $(($TESTS_COUNT - $TESTS_PASSED)) tests failed"
		fi
	fi

	# ENSURE TEST EXTERNE DIR STATE
	EXT_TEST_DIR=".test/extern"
	if $is_reset ; then
		rm -rf "$EXT_TEST_DIR"
		return
	fi
	if [ ! -d "$EXT_TEST_DIR" ] ; then
		mkdir "$EXT_TEST_DIR"
	fi

	# LIB-UNIT-TESTS
	if [[ $lib == "all" || $lib == "unit" ]] ; then
		EXT_TEST_REPO="https://github.com/alelievr/libft-unit-test"
		EXT_TEST="$EXT_TEST_DIR/libft-unit-tests"

		sed_i "s;LIBFTDIR	=	../libft;LIBFTDIR	=	$(pwd);" "$EXT_TEST/Makefile"

		info "\nUNITS TEST LIB ($EXT_TEST_REPO)\n"
		if [ ! -d "$EXT_TEST" ] ; then
			git clone --depth=1 "$EXT_TEST_REPO" "$EXT_TEST"
			rm -rf "$EXT_TEST/.git"
		fi
		EXT_TEST_OUTPUT=$(make -C "$EXT_TEST" f | tr -d '\0')
		EXT_TEST_FAILS=$(cat "$EXT_TEST/result.log" | sed -E '/.+:\ *(\[OK\]\ |\{protected\})+/d')
		if $is_verbose ; then
			echo "$EXT_TEST_OUTPUT"
		elif [[ $EXT_TEST_FAILS == "" ]] ; then
			success "NO FAILS DETECTED 🎉🎉🎉"
		else
			warning "$EXT_TEST_FAILS"
		fi
	fi

	# WAR-MACHINE
	if [[ $lib == "all" || $lib == "war" ]] ; then
		EXT_TEST_REPO="https://github.com/y3ll0w42/libft-war-machine"
		EXT_TEST="$EXT_TEST_DIR/libft-war-machine"
		info "\nLIBFT WAR MACHINE ($EXT_TEST_REPO)\n"
		if [ ! -d "$EXT_TEST" ] ; then
			git clone --depth=1 "$EXT_TEST_REPO" "$EXT_TEST"
			rm -rf "$EXT_TEST/.git"
			echo "$WAR_MACHINE_CONFIG" > "$EXT_TEST/my_config.sh"
		fi
		sed_i "/clear/d" "$EXT_TEST/grademe.sh"
		"$EXT_TEST/grademe.sh" -s -u
	fi

	# LIBFT-TESTER
	if [[ $lib == "all" || $lib == "tester" ]] ; then
		EXT_TEST_REPO="https://github.com/Tripouille/libftTester"
		EXT_TEST="$EXT_TEST_DIR/libftTester"
		info "\nLIBFT-TESTER ($EXT_TEST_REPO)\n"
		if [ ! -d "$EXT_TEST" ] ; then
			git clone --depth=1 "$EXT_TEST_REPO" "$EXT_TEST"
			rm -rf "$EXT_TEST/.git"
			echo "$WAR_MACHINE_CONFIG" > "$EXT_TEST/my_config.sh"
		fi
		#sed_i "/clear/d" "$EXT_TEST/grademe.sh"
		#"$EXT_TEST/grademe.sh" -s -u
	fi
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
