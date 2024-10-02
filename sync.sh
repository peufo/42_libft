#!/bin/bash

sync() {

	#TODO
	#SYNC libft.h
	: '
		LIB="./libft.h"
		FILE_NAME=${1#*src/}
		FUNC_NAME=${FILE_NAME%.c*}
		IMPLEMENTATION=$(grep "$FUNC_NAME(" $1)

		if grep -Pq "$IMPLEMENTATION" $LIB ; then
			return 0
		fi

		if grep -Pq "$FUNC_NAME(" $LIB ; then
			sed -i "" "s/.*$FUNC_NAME(.*/$IMPLEMENTATION;/" $LIB
		else
			sed -i "" "s/#endif/$IMPLEMENTATION;\n#endif/" $LIB
		fi
	'

	#SYNC Makefile wildcard
	if [[ $(uname) == "Linux" ]];  then
		sed -i "$(wc -l < Makefile),\$s;.*;# Les sources nécessaires à la compilation de mon programme sont 🥁🥁🥁 : $@ $;g" Makefile
	else
		sed -i "" "$(wc -l < Makefile),\$s;.*;# Les sources nécessaires à la compilation de mon programme sont 🥁🥁🥁 : $@ $;g" Makefile
	fi

}

sync "$@"
