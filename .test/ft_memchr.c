#include <string.h>
#include <stdio.h>

void test(const void *s, int c)
{
	t_size ns[] = {0, 1, 3, 5, 11, 12, 13, 14, 15};
	t_size len = strlen(s);
	for (int i = 0; i < 9; i++)
	{
		if (len >= ns[i]) {;
			void *a = memchr(s, c, ns[i]);
			void *b = ft_memchr(s, c, ns[i]);
			if (a != b) {
				printf("s=%s c=%c n=%lu\n", (unsigned char*)s, c, ns[i]);
				printf("accepted: %s\n", (unsigned char*)a);
				printf("received: %s\n", (unsigned char*)b);
			}
		}
	}
}

int main()
{
	test("", 0);
	test("", 1);
	test("", 1000);
	test("", -1);
	test("", -1000);
	test("prouuuuuutt", 0);
	test("prouuuuuutt", 1);
	test("prouuuuuutt", 1000);
	test("prouuuuuutt", -1);
	test("prouuuuuutt", -1000);
	test("prouuuuuutt", 'p');
	test("prouuuuuutt", 'r');
	test("prouuuuuutt", 'u');
	test("prouuuuuutt", 't');
}
