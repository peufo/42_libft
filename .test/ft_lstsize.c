int main()
{
	t_list *lst = ft_lstnew("A");
	lst->next = ft_lstnew("B");
	lst->next->next = ft_lstnew("C");

	if (ft_lstsize(lst) != 3) {
		printf("TEST FAILED => %s:%d", __FILE__, __LINE__);
	}
	if (ft_lstsize(NULL) != 0) {
		printf("TEST FAILED => %s:%d", __FILE__, __LINE__);
	}
}