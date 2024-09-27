#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"

void test(const char *str)
{
	int a = atoi(str);
	int b = ft_atoi(str);
	if (a != b) {
		printf("str=%s\n", str);
		printf("accepted: %i\n", a);
		printf("recieved: %i\n\n", b);
	}
}

int main()
{
	test("");
	test("00123");
	test("-00123");
	test("+0123");
	test(" 0123");
	test(" -0123");
	test(" +0123");
	test("prout");
	test("prout123");
	test("123prout123");
	test("123prout");
	test("+123prout");
	test("-123prout");
	test("--123prout");
	test("-+123prout");
	test("-++123prout");
	test("--+123");
	test("--++123");
	test(" 123prout");
	test("  +123prout");
	test(" -123prout");
	test("  --123prout");
	test(" -+123prout");
	test("  -++123prout");
	test(" --+123");
	test("  --++123");
	test(" 123prout");
	test("  +123prout");
	test("\n123prout");
	test("\n\t+123prout");
	test(" -123prout");
	test("  --123prout");
	test(" -+123prout");
	test("  -++123prout");
	test(" --+123");
	test("  --++123");
	test("2147483647");
	test("+2147483647");
	test("++2147483647");
	test("-+2147483647");
	test("+-2147483647");
	test("--2147483647");
	test("  -2147483647");
	test("2147483648");
	test("+2147483648");
	test("++2147483648");
	test("-+2147483648");
	test("+-2147483648");
	test("--2147483648");
	test("  -2147483648");
	test("-2147483648");
}

