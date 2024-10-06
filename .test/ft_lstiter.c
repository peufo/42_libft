static short that_run_baby = 0;

void	run(void *content) {
	(void)content;
	that_run_baby++;
}

int main()
{
	t_list *lst = ft_lstnew(NULL);
	lst->next = ft_lstnew(NULL);
	lst->next->next = ft_lstnew(NULL);
	ft_lstiter(lst, &run);
	if (that_run_baby != 3)
	{
		printf("TEST FAILED => %s:%d\n", __FILE__, __LINE__);
		printf("Run %d times", that_run_baby);
	}
}
