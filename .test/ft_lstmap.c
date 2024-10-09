static int del_count = 0;
#include <stdio.h>
#include "../libft.h"

void del_content(void *content)
{
	if (content)
		free(content);
	del_count++;
}

void *edit_content_toupper(void *content)
{
	char *str = content;
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
	return (content);
}

void	*edit_content_o_to_a(void *ct)
{
	int i;
	void	*c;
	char	*pouet;

	c = ct;
	i = -1;
	pouet = (char *)c;
	while (pouet[++i])
		if (pouet[i] == 'o')
			pouet[i] = 'a';
	return (c);
}


void test_1() {
	t_list *lst = ft_lstnew(strdup("Hey"));
	lst->next = ft_lstnew(strdup("mum"));
	lst->next->next = ft_lstnew(strdup("!"));
	t_list *new_lst = ft_lstmap(lst, edit_content_toupper, del_content);
	if (strcmp(new_lst->content, "HEY")
		|| strcmp(new_lst->next->content, "MUM")
		|| strcmp(new_lst->next->next->content, "!")
	)
	{
		printf("TEST FAILED %s:%d\n", __FILE__, __LINE__);
		printf("el 0: %s\n", (char *)new_lst->content);
		printf("el 1: %s\n", (char *)new_lst->next->content);
		printf("el 2: %s\n", (char *)new_lst->next->next->content);
	}
}

void test_2() {

	t_list *lst = ft_lstnew(strdup("hahaha"));
	lst->next = ft_lstnew(strdup("hohoho"));
	lst->next->next = ft_lstnew(strdup("haho!"));
	t_list *new_lst = ft_lstmap(lst, edit_content_o_to_a, del_content);


	if (strcmp(new_lst->content, "hahaha")
		|| strcmp(new_lst->next->content, "hahaha")
		|| strcmp(new_lst->next->next->content, "haha!")
	)
	{
		printf("TEST FAILED %s:%d\n", __FILE__, __LINE__);
		printf("el 0: %s\n", (char *)new_lst->content);
		printf("el 1: %s\n", (char *)new_lst->next->content);
		printf("el 2: %s\n", (char *)new_lst->next->next->content);
	}
}

int main()
{
	test_1();
	test_2();
}

