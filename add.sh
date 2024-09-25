#!/bin/bash

add_function() {
	FUNCTION_NAME=$1
	if [[ $FUNCTION_NAME == "" ]]; then
		echo "Please, provide a function name"
	fi

	echo "Add function $FUNCTION_NAME to Makefile"
	gsed -i "0,/^$/ s//FUNCTIONS += $FUNCTION_NAME\n/" ./Makefile

	echo "Add function $FUNCTION_NAME to src"
	touch "./src/$FUNCTION_NAME.c"

	echo "Add function $FUNCTION_NAME to .test"
	echo "$TEST_CONTENT" > ./.test/$FUNCTION_NAME.c
	
}

TEST_CONTENT="#include <ctype.h>
#include <stdio.h>
#include \"../libft.h\"

void test()
{

}
int main()
{

}
"

add_function $@
