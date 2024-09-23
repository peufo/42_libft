#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void test(const void *src, t_size len)
{
	void *dst_a = malloc(strlen(src));
	void *dst_b = malloc(strlen(src));

	memcpy(dst_a, src, len);
	ft_memcpy(dst_b, src, len);
	if (memcmp(dst_a, dst_b, len) != 0)
	{
		printf("accepted: %s\n", (char *)dst_a);
		printf("recieved: %s\n", (char *)dst_b);
	}
	free(dst_a);
	free(dst_b);
}

int	main()
{
	test("YOLO", 0);
	test("YOLO", 3);
	test("YOLO", 4);
	test("", 0);
	test("PROUT ✊", 9);

}