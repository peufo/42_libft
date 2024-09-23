#!/bin/bash

info() {
	echo -e "\033[36m$1\033[0m\n"
}
warning() {
	echo -e "\033[31m$1\033[0m\n"
}

watch() {
	STATE_A=""
	while [[ true ]]
	do
		STATE_B=$(find -L . -type f -name "*.c" -exec md5 {} \;)
		if [[ $STATE_A != $STATE_B ]] ; then
			STATE_A=$STATE_B
			clear
			info "HEY BRO 👋 $(date)"

			info "NORMINETTE"
			norminette

			info "\nTESTS"
			make test

		fi
		sleep 0.1
	done
}

watch