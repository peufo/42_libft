#include <ctype.h>
#include <stdio.h>

void test(int arg) {
	int accepted = isprint(arg);
	int recieved = ft_isprint(arg);
	if (accepted == recieved) return;
	printf("(%i) => %i instead %i\n", arg, recieved, accepted);
	return;
}

int main() {
	test(-1);
	test(0);
	test(1);
	test(31);
	test(32);
	test(33);
	test(125);
	test(126);
	test(127);
	test(128);
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
