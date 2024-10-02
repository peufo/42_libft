#include <ctype.h>

void test(int c)
{
	int a = tolower(c);
	int b = ft_tolower(c);
	if (a != b)
	{
		printf("arg %d\n", c);
		printf("accepted: %d\n", a);
		printf("received: %d\n", b);
	}
}

int main()
{
	test('a');
	test('h');
	test('z');
	test('A');
	test('H');
	test('Z');
	test('0');
	test('5');
	//test(2147483647);
	//test(-2147483648);
	test(0);
	test(1000);
	test(-1000);
}