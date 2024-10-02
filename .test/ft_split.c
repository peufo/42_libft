typedef struct s_args t_args;
struct s_args {
	char const *str;
	char c;
	char **accepted;
};

short is_same_arr(char **arr_a, char **arr_b)
{
	while (*arr_a && *arr_b)
		if (strcmp(*(arr_a++), *(arr_b++)) != 0)
			return (0);
	if (*arr_a || *arr_b)
		return (0);
	return (1);
}

void	print_arr(char **arr)
{
	printf("[");
	while (*arr)
		printf("%s, ", *(arr++));
	printf("(null)]\n");
}

void test(t_args *args)
{

	char **res = ft_split(args->str, args->c);

	if (!is_same_arr(res, args->accepted)) {
		printf("s=%s c=%c\n", args->str, args->c);
		printf("accepted: ");
		print_arr(args->accepted);
		printf("received: ");
		print_arr(res);
	}
	free(res);
}

int main()
{
	t_args tests[] = {
		{
			.str = "HELLO",
			.c = 'L',
			.accepted = (char *[]){ "HE", "O", NULL }
		},
		{
			.str = "HELLO",
			.c = 'E',
			.accepted = (char *[]){ "H", "LLO", NULL }
		},
		{
			.str = "HELLO",
			.c = 'H',
			.accepted = (char *[]){ "ELLO", NULL }
		},
		{
			.str = "HHHHHELLO HO HO",
			.c = 'H',
			.accepted = (char *[]){ "ELLO ", "O ", "O", NULL }
		},
		{
			.str = "HELLO",
			.c = 'O',
			.accepted = (char *[]){ "HELL", NULL }
		},
		{
			.str = "HELLOOOO",
			.c = 'O',
			.accepted = (char *[]){ "HELL", NULL }
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

