#include <string.h>
#include <stdio.h>

void test(const void *s1, const void *s2, t_size n)
{
	if (n > strlen(s1) || n > strlen(s2))
		return;
	int a = memcmp(s1, s2, n);
	int b = ft_memcmp(s1, s2, n);
	if (a != b) {
		printf("s1=%s s2=%s n=%lu\n", (unsigned char*)s1, (unsigned char*)s2, n);
		printf("accepted: %i\n", a);
		printf("recieved: %i\n", b);
	}
}

int main()
{
	test("", "", 0);
	test("YOLO", "", 0);
	test("", "YOLO", 0);
	test("YOLO", "YOLO", 0);
	test("", "", 1);
	test("YOLO", "", 1);
	test("", "YOLO", 1);
	test("YOLO", "YOLO", 1);
	test("YOLO", "", 2);
	test("", "YOLO", 2);
	test("YOLO", "YOLO", 2);
	test("YOLO", "", 4);
	test("", "YOLO", 4);
	test("YOLO", "YOLO", 4);
	test("YOLO", "", 5);
	test("", "YOLO", 5);
	test("YOLO", "YOLO", 5);
	test("YOLO", "", 6);
	test("", "YOLO", 6);
	test("YOLO", "YOLO", 6);
	test("YOLO", "YOKO", 0);
	test("YOLO", "YOKO", 1);
	test("YOLO", "YOKO", 2);
	test("YOLO", "YOKO", 4);
	test("YOLO", "YOKO", 5);
	test("YOLO", "YOKO", 6);
}

