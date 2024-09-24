#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft.h"

void memprint(const void *src, t_size len)
{
	while (len--)
	{
		if (*(char *)src == '\0')
			write(1, "\\0", 2);
		else
			write(1, src++, 1);
	}
}

void test(const void *src, t_size len)
{
	void *dst_a = malloc(strlen(src));
	void *dst_b = malloc(strlen(src));

	memmove(dst_a, src, len);
	ft_memmove(dst_b, src, len);
	if (memcmp(dst_a, dst_b, len) != 0)
	{
		printf("accepted: %s\n", (char *)dst_a);
		memprint(dst_a, len);
		printf("recieved: %s\n", (char *)dst_b);
		memprint(dst_b, len);
	}
	free(dst_a);
	free(dst_b);
}

void test_overlap(const void *src, int delta, t_size len)
{
	char src_a[100];
	char src_b[100];
	char *a = src_a + 50;
	char *b = src_b + 50;
	strcpy(a, src);
	strcpy(b, src);
	if (delta >= 0)
	{
		memmove(a, a + delta, len);
		ft_memmove(b, b + delta , len);
	}
	else
	{
		memmove(a - delta, a, len);
		ft_memmove(b - delta, b, len);
	}
	if (memcmp(a, b, len) != 0)
	{
		printf("delta=%d len=%lu\n", delta, len);
		printf("accepted: %s\n", (char *)a);
		printf("recieved: %s\n", (char *)b);
	}
}

int	main()
{
	test("YOLO", 0);
	test("YOLO", 3);
	test("YOLO", 4);
	test("", 0);
	test("PROUT ✊", 9);
	test("PROUT ✊", 9);

	test_overlap("0123456789", 0, 10);
	test_overlap("0123456789", 1, 10);
	test_overlap("0123456789", 5, 15);
	test_overlap("0123456789", 9, 10);
	test_overlap("0123456789", 10, 10);
	test_overlap("0123456789", 12, 10);
	test_overlap("0123456789", -5, 5);
	test_overlap("0123456789", -5, 10);
	test_overlap("0123456789", -5, 15);
	test_overlap("0123456789", -15, 10);
}