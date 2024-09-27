#include <string.h>
#include <stdio.h>

void test(const char *str)
{
	char *a = strdup(str);
	char *b = ft_strdup(str);
	if (strcmp(a, b) != 0) {
		printf("arg %s\n", str);
		printf("accepted: %s\n", a);
		printf("recieved: %s\n", b);
	}
}

int main()
{
	test("");
	test("Hi mum 👋");
}
