#!/bin/bash

add_function() {
	FUNCTION_NAME=$1
	if [[ $FUNCTION_NAME == "" ]]; then
		echo "Please, provide a function name"
		return
	fi

	echo "Create file ./src/$FUNCTION_NAME"
	touch "./src/$FUNCTION_NAME.c"

	echo "Create file ./.test/$FUNCTION_NAME"
	echo "$TEST_CONTENT" > ./.test/$FUNCTION_NAME.c

}

TEST_CONTENT="
int main()
{
	printf(\"TEST NOT IMPLEMENTED %s:%d\", __FILE__, __LINE__);
}
"

add_function $@
