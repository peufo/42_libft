#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>

void test(char *dst, char *src, t_size len)
{
	char dst_a[100];
	char dst_b[100];
	strcpy(dst_a, dst);
	strcpy(dst_b, dst);
	t_size res_a = strlcat(dst_a, src, len);
	t_size res_b = ft_strlcat(dst_b, src, len);
	if (res_a != res_b || strcmp(dst_a, dst_b) != 0)
	{
		printf("dst=%s src=%s len=%lu\n", dst, src, len);
		printf("accepted: res=%lu dst=%s\n", res_a, dst_a);
		printf("received: res=%lu dst=%s\n", res_b, dst_b);
	}
}

int main()
{
	test("", "", 0);
	test("", "", 10);
	test("YOLO", "", 0);
	test("YOLO", "", 10);
	test("", "YOLO", 0);
	test("", "YOLO", 10);
	test("YOLO", "BABA", 0);
	test("YOLO", "BABA", 3);
	test("YOLO", "BABA", 4);
	test("YOLO", "BABA", 5);
	test("YOLO", "BABA", 8);
	test("YOLO", "BABA", 9);
	test("YOLO", "BABA", 10);
}
