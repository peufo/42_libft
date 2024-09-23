#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"


void test(char *src, t_size len)
{
	char *a = malloc(len + 1);
	char *b = malloc(len + 1);
	*a = '\0';
	*b = '\0';
	t_size res_a = strlcpy(a, src, len);
	t_size res_b = ft_strlcpy(b, src, len);
	if (res_a != res_b || strcmp(a, b) != 0)
	{
		printf("len=%lu src=%s\n", len, src);
		printf("accepted: res=%lu dst=%s\n", res_a, a);
		printf("received: res=%lu dst=%s\n", res_b, b);
	}
	free(a);
	free(b);
}

int main()
{ 
	test("", 0);
	test("", 10);
	test("YOLO", 0);
	test("YOLO", 1);
	test("YOLO", 4);
	test("YOLO", 5);
	test("YOLO", 6);
}