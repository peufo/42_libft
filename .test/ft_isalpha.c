#include <ctype.h>

void test(int arg) {
	int accepted = isalpha(arg);
	int received = ft_isalpha(arg);
	if (accepted == received) return;
	printf("(%i) => %i instead of %i\n", arg, received, accepted);
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
