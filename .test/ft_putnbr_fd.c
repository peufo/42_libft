#include <fcntl.h>
#include "utils.c"

typedef struct s_test t_test;
struct s_test {
	char *path;
	int n;
	char *expected;
};

void test(t_test *args)
{
	int fd = open(args->path, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
	{
		printf("CANNOT OPEN \"%s\"", args->path);
		return ;
	}
	ft_putnbr_fd(args->n, fd);
	close(fd);
	char *res = file_read(args->path);
	if (strcmp(res, args->expected)) {
		printf("expected: %s\n", args->expected);
		printf("received: %s\n", res);
		print_bytes(args->expected, strlen(args->expected));
		print_bytes(res, strlen(res));
	}
	remove(args->path);
}

int main()
{
	t_test tests[] = {
		{
			.path = "tmp.txt",
			.n = 0,
			.expected = "0",
		},
		{
			.path = "tmp.txt",
			.n = 1234,
			.expected = "1234",
		},
		{
			.path = "tmp.txt",
			.n = 2147483647,
			.expected = "2147483647",
		},
		{
			.path = "tmp.txt",
			.n = -2147483648,
			.expected = "-2147483648",
		},
	};

	short count = sizeof(tests) / sizeof(tests[0]);
	short index = 0;
	while (index < count)
	{
		test(tests + index++);
	}
}

