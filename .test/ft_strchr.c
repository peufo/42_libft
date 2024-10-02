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
	test("", -1);
	test("", -1000);
	test("prouuuuuutt", 0);
	test("prouuuuuutt", 1);
	test("prouuuuuutt", 1000);
	test("prouuuuuutt", -1);
	test("prouuuuuutt", -1000);
	test("prouuuuuutt", 'p');
	test("prouuuuuutt", 'r');
	test("prouuuuuutt", 'u');
	test("prouuuuuutt", 't');
}

