static short that_run_baby = 0;

void	del_content(void *content) {
	free(content);
	that_run_baby = 1;
}

int main()
{
	t_list *lst = ft_lstnew(malloc(16));

	ft_lstdelone(lst, &del_content);
	if (!that_run_baby)
	{
		printf("TEST FAILED => %s:%d", __FILE__, __LINE__);
	}
}
