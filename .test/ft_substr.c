#include "../libft.h"

void test(char *str, unsigned int start, size_t len, char *expected)
{
	char *res = ft_substr(str, start, len);
	
	if (strcmp(res, expected))
	{
		printf("str=%s start=%u len=%lu\n", str, start, len);
		printf("expected: %s\n", expected);
		printf("received: %s\n", res);
	}
}

int main()
{
	test("", 0, 0, "");
	test("", 1, 0, "");
	test("", 0, 1, "");
	test("", 1, 1, "");
	test("HEY", 0, 4, "HEY");
	test("HEY", 0, 3, "HEY");
	test("HEY", 0, 2, "HE");
	test("HEY", 0, 1, "H");
	test("HEY", 0, 0, "");
	test("HEY", 1, 4, "EY");
	test("HEY", 1, 3, "EY");
	test("HEY", 1, 2, "EY");
	test("HEY", 1, 1, "E");
	test("HEY", 1, 0, "");
	test("HEY", 2, 4, "Y");
	test("HEY", 2, 3, "Y");
	test("HEY", 2, 2, "Y");
	test("HEY", 2, 1, "Y");
	test("HEY", 2, 0, "");
	test("HEY", 3, 4, "");
	test("HEY", 3, 3, "");
	test("HEY", 3, 2, "");
	test("HEY", 3, 1, "");
	test("HEY", 3, 0, "");
	test("HEY", 4, 4, "");
	test("HEY", 4, 3, "");
	test("HEY", 4, 2, "");
	test("HEY", 4, 1, "");
	test("i just want this part #############", 0, 22, "i just want this part ");
	test("i just want this part #############", 5, 20, "t want this part ###");
}

