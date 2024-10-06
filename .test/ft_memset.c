void test(char *str, int c, size_t len)
{
	char *str_a = strdup(str);
	char *str_b = strdup(str);
	memset(str_a, c, len);
	ft_memset(str_b, c, len);
	if (strcmp(str_a, str_b) == 0) return;
	printf("accepted: %s\n", str_a);
	printf("received: %s\n", str_b);
}

int	main()
{
	test("YOLO", 'e', 0);
	test("YOLO", 'e', 3);
	test("YOLO", 'e', 4);
	test("", 'e', 0);
	test("", '\n', 0);
	test("PROUT ✊", 'e', 9);
	test("PROUT ✊", 1000, 9);
	test("PROUT ✊", 32000, 9);
}