

typedef struct s_test t_test;
struct s_test {
	char const *s;
	char (*f)(unsigned int, char);
	char *expected;
};

void test(t_test *args)
{
	char *res = ft_strmapi(args->s, args->f);
	if (strcmp(res, args->expected)) {
		printf("s=%s\n", args->s);
		printf("expected:%s\n", args->expected);
		printf("received:%s\n", args->expected);
	}
}

char to_2(unsigned int index, char c)
{
	(void)index;
	(void)c;
	return ('a');
}

char to_add_two(unsigned int index, char c)
{
	(void)index;
	(void)c;
	return (c + 2);
}

char to_upper(unsigned int index, char c)
{
	(void)index;
	if ('a' <= c && c <= 'z')
		return (c - 32);
	return (c);
}

int main()
{
	t_test tests[] = {
		{
			.s = "HOHO",
			.f = &to_2,
			.expected = "aaaa"
		},
		{
			.s = "2222222222",
			.f = &to_add_two,
			.expected = "4444444444"
		},
		{
			.s = "Les 3 rigolos",
			.f = &to_upper,
			.expected = "LES 3 RIGOLOS"
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

