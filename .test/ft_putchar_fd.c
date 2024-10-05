#include <fcntl.h>
#include "utils.c"

typedef struct s_test t_test;
struct s_test {
	char *path;
	char c;
};

void test(t_test *args)
{

	int fd = open(args->path, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("CANNOT OPEN \"%s\"", args->path);
		return ;
	}
	ft_putchar_fd(args->c, fd);
	close(fd);
	char *res = file_read(args->path);
	if (args->c != res[0] && res[0] == '\0') {
		printf("expected:%c \n", args->c);
		printf("received:%s \n", res);
	}
	remove(args->path);
}

int main()
{
	t_test tests[] = {
		{
			.path = "tmp.txt",
			.c = 'A'
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

