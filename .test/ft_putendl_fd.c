#include <fcntl.h>
#include "utils.c"

typedef struct s_test t_test;
struct s_test {
	char *path;
	char *s;
};

void test(t_test *args)
{
	int fd = open(args->path, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("CANNOT OPEN \"%s\"", args->path);
		return ;
	}
	ft_putendl_fd(args->s, fd);
	close(fd);
	char *res = file_read(args->path);
	char *expected = ft_strjoin(args->s, "\n");
	if (strcmp(res, expected)) {
		printf("expected:%s \n", expected);
		printf("received:%s \n", res);
	}
	remove(args->path);
}

int main()
{
	t_test tests[] = {
		{
			.path = "tmp.txt",
			.s = "Salut maman\n"
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

