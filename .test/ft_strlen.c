#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

void test(char *str) {
	size_t accepted = strlen(str);
	size_t recieved = ft_strlen(str);
	if (accepted == recieved) return;
	printf("(%s) => %zu instead %zu\n", str, recieved, accepted);
	return;
}

int main() {
	const unsigned long max = 1000000;
	char *str_max = malloc(sizeof(*str_max) * max);
	for (unsigned long i = 0; i < max; i++)
		str_max[i] = 'a';
	str_max[max - 1] = '\0';


	test("");
	test("YOLO");
	test("HEY comment va \n Bien merci ✊");
	test(str_max);
	free(str_max);
	return 0;
}
