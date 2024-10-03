
typedef struct s_test t_test;
struct s_test {
	const char *s1;
	const char *s2;
	t_size n;
};

void test(t_test *args)
{
	int res = ft_strncmp(args->s1, args->s2, args->n);
	int expected = strncmp(args->s1, args->s2, args->n);
	if (res != expected) {
		printf("s1=%s s2=%s n=%lu\n", args->s1, args->s2, args->n);
		printf("expected:%i \n", expected);
		printf("received:%i \n", res);
	}
}

int main()
{
	t_test tests[] = {
		{
			.s1 = "YOLO",
			.s2 = "YOLO",
			.n = 0,
		},
		{
			.s1 = "YOLO",
			.s2 = "YOLO",
			.n = 2,
		},
		{
			.s1 = "YOLO",
			.s2 = "YOLO",
			.n = 8,
		},
		{
			.s1 = "YOL",
			.s2 = "YOLO",
			.n = 8,
		},
		{
			.s1 = "YOLO",
			.s2 = "YOL",
			.n = 8,
		},
		{
			.s1 = "YOLA",
			.s2 = "YOLO",
			.n = 8,
		},
		{
			.s1 = "YOLA",
			.s2 = "YOLALALA",
			.n = 4,
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

