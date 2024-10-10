
int main()
{
	t_list *lst = ft_lstnew("A");
	lst->next = ft_lstnew("B");
	t_list *new = ft_lstnew("C");
	new->next = ft_lstnew("D");
	ft_lstadd_back(&lst, new);
	if (strcmp(lst->content, "A")
		|| strcmp(lst->next->content, "B")
		|| strcmp(lst->next->next->content, "C")
		|| strcmp(lst->next->next->next->content, "D")
		|| !!lst->next->next->next->next
	) {
		printf("See %s:%d", __FILE__, __LINE__);
	}
}

