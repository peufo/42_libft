#include <string.h>
#include <stdio.h>
#include "../libft.h"

void test(const char *s, int c)
{
	char *a = strchr(s, c);
	char *b = ft_strchr(s, c);
	if (a != b) {
		printf("s: %s c:%c\n", s, c);
		printf("accepted: %s\n", a);
		printf("received: %s\n", b);
	}
}

int main()
{
	test("", 0);
	test("", 1);
	test("", 1000);
	test("prouuuuuut", 0);
	test("prouuuuuut", 1);
	test("prouuuuuut", 1000);
	test("prouuuuuut", 'p');
	test("prouuuuuut", 'r');
	test("prouuuuuut", 'u');
	test("prouuuuuut", 't');
}

