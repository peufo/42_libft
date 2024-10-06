void print_bytes(void *ptr, int size) 
{
    unsigned char *p = ptr;
    int i;
    for (i=0; i<size; i++) {
        printf("%02hhX ", p[i]);
    }
    printf("\n");
}

void test(const void *src, size_t len)
{
	size_t src_len = ft_strlen(src);
	void *dst_a = ft_calloc(1, src_len);
	void *dst_b = ft_calloc(1, src_len);
	ft_memmove(dst_b, src, len);
	if (!src_len)
		return ;
	memmove(dst_a, src, len);
	if (memcmp(dst_a, dst_b, len))
	{
		printf("accepted: %s\n", (char *)dst_a);
		print_bytes(dst_a, len);
		printf("received: %s\n", (char *)dst_b);
		print_bytes(dst_b, len);
	}
	free(dst_a);
	free(dst_b);
}



void test_overlap(const void *src, int delta, size_t len)
{
	char src_a[100] = { '\0' };
	char src_b[100] = { '\0' };
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
	if (memcmp(a, b, len - 1))
	{
		printf("delta=%d len=%lu\n", delta, len);
		printf("accepted: ");
		print_bytes(a, len);
		printf("received: ");
		print_bytes(b, len);
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
