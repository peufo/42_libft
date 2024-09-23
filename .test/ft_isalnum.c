#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

void test(int arg) {
	int accepted = isalnum(arg);
	int recieved = ft_isalnum(arg);
	if (accepted == recieved) return;
	printf("(%i) => %i instead of %i\n", arg, recieved, accepted);
	return;
}

int main() {
	test(0);
	test(1000);
	test(6000);
	test(-6000);
	test('a');
	test('f');
	test('z');
	test('A');
	test('F');
	test('Z');
	test('5');
	test(' ');
	test('_');
	return 0;
}
