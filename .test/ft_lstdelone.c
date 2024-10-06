
static short WATH_THE_FUCK = 0;
void	del(void *d) {
	free(d);
	WATH_THE_FUCK = 1;
}

int main()
{
	t_list *lst = ft_lstnew("A");

	ft_lstdelone(lst, &del);
	if (!WATH_THE_FUCK)
	{
		printf("TEST FAILED => %s:%d", __FILE__, __LINE__);
	}
}
