static short that_run_baby = 0;

void	del_content(void *content) {
	free(content);
	that_run_baby++;
}

int main()
{
	t_list *lst = ft_lstnew(malloc(16));
	lst->next = ft_lstnew(malloc(16));
	lst->next->next = ft_lstnew(malloc(16));
	ft_lstclear(&lst, &del_content);
	if (lst != NULL && that_run_baby != 3)
	{
		printf("TEST FAILED => %s:%d\n", __FILE__, __LINE__);
		printf("Run %d times", that_run_baby);
	}
}
