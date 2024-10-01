#!/bin/bash

sync() {
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
}

sync "$@"
