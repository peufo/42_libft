void test(char const *str, char const *set, const char *accepted)
{
	char *res = ft_strtrim(str, set);

	if (strcmp(res, accepted) != 0) {
		printf("str=\"%s\" set=\"%s\"\n", str, set);
		printf("accepted: %s\n", accepted);
		printf("received: %s\n", res);
	}
}

int main()
{
	test("", "", "");
	test("_-_+HEY+_-_", "", "_-_+HEY+_-_");
	test("_-_+HEY+_-_", "_", "-_+HEY+_-");
	test("_-_+HEY+_-_", "-", "_-_+HEY+_-_");
	test("_-_+HEY+_-_", "-_", "+HEY+");
	test("_-_+HEY+_-_", "_-", "+HEY+");
	test("_-_+HEY+_-_", "_-+", "HEY");
	test("_-_+HEY+_-_", "_+-", "HEY");
	test("_-_+HEY+_-_", "+_-", "HEY");
	test("_-_+HEY+_-_", "+-_", "HEY");
	test("_-_+HEY+_.-_", "+-_", "HEY+_.");
	test("._-_+HEY+_.-_", "+-_", "._-_+HEY+_.");
	test("._-_+HEY+_.-_", "+-_.YEH", "");
	test("._-_+HEY+_.-_", "+-_.YE", "H");
	test("._-_+HEY+_.-_", "+-_.YH", "E");
}

