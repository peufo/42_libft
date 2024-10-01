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

TEST_CONTENT="#include <stdio.h>

typedef struct s_test t_test;
struct s_test {

	char **expected;
};

void test(t_args *args)
{
	if (1) {
		printf(\"TEST_NOT_IMPLEMENTED\n\");
		printf(\"expected: \n\");
		printf(\"recieved: \n\");
	}
}

int main()
{
	t_args tests[] = {
		{

			.accepted = (char *[]){ "HE", "O", NULL }
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}
"

add_function $@
