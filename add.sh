#!/bin/bash

add_function() {
	FUNCTION_NAME=$1
	if [[ $FUNCTION_NAME == "" ]]; then
		echo "Please, provide a function name"
	fi

	echo "Create file ./src/$FUNCTION_NAME"
	touch "./src/$FUNCTION_NAME.c"

	echo "Create file ./.test/$FUNCTION_NAME"
	echo "$TEST_CONTENT" > ./.test/$FUNCTION_NAME.c

}

TEST_CONTENT="
typedef struct s_test t_test;
struct s_test {
	TODO
};

void test(t_test *args)
{
	if (1) {
		printf(\"TODO\n\");
		printf(\"expected: \n\", args->expected);
		printf(\"received: \n\");
	}
}

int main()
{
	t_test tests[] = {
		{

			.expected = TODO
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
