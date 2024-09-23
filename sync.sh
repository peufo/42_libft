sync() {
	LIB="./libft.h"
	FILE_NAME=${1#*src/}
	FUNCTION_NAME=${FILE_NAME%.c*}
	IMPLEMENTATION=$(grep "$FUNCTION_NAME(" $1)

	if grep -q "$IMPLEMENTATION" $LIB ; then
		return 0
	fi

	if grep -q "$FUNCTION_NAME(" $LIB ; then
		sed -i "" "s/.*$FUNCTION_NAME(.*/$IMPLEMENTATION;/" $LIB
	else
		sed -i "" "s/#endif/$IMPLEMENTATION;\n#endif/" $LIB
	fi

}

sync "$@"