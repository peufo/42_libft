#include <ctype.h>

void test(int arg) {
	int accepted = isdigit(arg);
	int received = ft_isdigit(arg);
	if (accepted == received) return;
	printf("(%i) => %i instead of %i\n", arg, received, accepted);
	return;
}

int main() {
	test(0);
	test(1000);
	test(6000);
	test(-6000);
	test('0');
	test('5');
	test('9');
	test(' ');
	test('_');
	return 0;
}
