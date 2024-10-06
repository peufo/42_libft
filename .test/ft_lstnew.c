
typedef struct s_test t_test;
struct s_test {
	char *data;
};

void test(t_test *args)
{
	t_list *lst = ft_lstnew(args->data);
	if (strcmp(lst->content, args->data)) {
		printf("data=%s\n", args->data);
		printf("expected: %s\n", args->data);
		printf("received: %s\n", args->data);
	}
}

int main()
{
	t_test tests[] = {
		{ .data = "YOLO" },
		{ .data = "" },
		{ .data = "HAHA HOHO" },
		{ .data = (void *)0 },
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

