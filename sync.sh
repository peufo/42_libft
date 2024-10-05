#!/bin/bash

sync() {

	#SYNC Makefile SOURCES
	SOURCES=$(ls src/*.c | tr '\n' ' ')
	SED_COMMAND="s;^SOURCES	.*;SOURCES		=	$SOURCES;"
	if [[ $(uname) == "Linux" ]];  then
		sed -i "$SED_COMMAND" Makefile
	else
		sed -i "" "$SED_COMMAND" Makefile
	fi
}

sync "$@"
