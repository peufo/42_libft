#include <ctype.h>
#include <stdio.h>
#include "../libft.h"

void test(int arg) {
	int accepted = isalpha(arg);
	int recieved = ft_isalpha(arg);
	if (accepted == recieved) return;
	printf("(%i) => %i instead of %i\n", arg, recieved, accepted);
	return;
}

int main() {
	test(0);
	test(1000);
	test('0');
	test('1');
	test(' ');
	test('s');
	test('w');
	test('z');
	test('Z');
	test(6000);
	test(-6000);
	test('b');
	test('B');
	return 0;
}
