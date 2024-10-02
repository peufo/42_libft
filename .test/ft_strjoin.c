void test(const char *a, const char *b, const char *accepted)
{
	char *res = ft_strjoin(a, b);

	if (strcmp(res, accepted) != 0) {
		printf("a=%s b=%s\n", a, b);
		printf("accepted: %s\n", accepted);
		printf("received: %s\n", res);
	}
}

int main()
{
	test("", "", "");
	test("A", "", "A");
	test("", "A", "A");
	test("A", "B", "AB");
	test("AA", "B", "AAB");
	test("AA", "BB", "AABB");
}

