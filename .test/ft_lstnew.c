#include "../libft.h"

typedef struct s_test t_test;
struct s_test {
	void *data;
};

void test(t_test *args)
{
	t_list *lst = ft_lstnew(args->data);
	if (strcmp(lst->content, args->data)) {
		ft_putstr("data=");
		ft_putstr(args->data);
		ft_putstr("\nexpected: ");
		ft_putstr(args->data);
		ft_putstr("\nreceived: ");
		ft_putstr(lst->content);
		ft_putstr("\n");
	}
	if (lst->next)
		ft_putstr("lst next is defined ???");
}

int main()
{
	int num = 42;
	char str[] = "Yo mec";

	t_test tests[] = {
		{ .data = "YOLO" },
		{ .data = "" },
		{ .data = str},
		{ .data = &num },
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

