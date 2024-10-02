#include <ctype.h>

void test(int arg) {
	int accepted = isascii(arg);
	int received = ft_isascii(arg);
	if (accepted == received) return;
	printf("(%i) => %i instead of %i\n", arg, received, accepted);
	return;
}

int main() {
	test(-1);
	test(0);
	test(1);
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
	test('\n');
	return 0;
}
