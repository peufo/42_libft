int main()
{

	t_list *lst = ft_lstnew("A");
	lst->next = ft_lstnew("B");
	lst->next->next = ft_lstnew("C");
	t_list *last = ft_lstlast(lst);
	if (((char *)(last->content))[0] != 'C') {
		printf("TEST FAILED => %s:%d", __FILE__, __LINE__);
	}
}
