void test(char *str, unsigned int start, t_size len, char *accepted)
{
	char *res = ft_substr(str, start, len);
	if (!res && !accepted)
		return ;
	if (!res || !accepted || strcmp(res, accepted) != 0)
	{
		printf("str=%s start=%u len=%lu\n", str, start, len);
		printf("accepted: %s\n", accepted);
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
	test("HEY", 0, 3, "HE");
	test("HEY", 0, 2, "H");
	test("HEY", 0, 1, "");
	test("HEY", 0, 0, "");
	test("HEY", 1, 4, "EY");
	test("HEY", 1, 3, "EY");
	test("HEY", 1, 2, "E");
	test("HEY", 1, 1, "");
	test("HEY", 1, 0, "");
	test("HEY", 2, 4, "Y");
	test("HEY", 2, 3, "Y");
	test("HEY", 2, 2, "Y");
	test("HEY", 2, 1, "");
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
	test("HEY", 4, 0, "");
}

