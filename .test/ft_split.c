#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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
	printf("]\n");
}

void test(char const *s, char c, char const **accepted)
{
	char **res = ft_split(s, c);

	if (is_same_arr(res, accepted)) {
		printf("s=%s c=%c\n", s, c);
		printf("accepted: ");
		print_arr(accepted);
		printf("recieved: ");
		print_arr(res);
	}
}

int main()
{
	char **arr = {"HE", "O", NULL};

	test("HELLO", "L", arr);
}

