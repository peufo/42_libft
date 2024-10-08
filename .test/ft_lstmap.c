static int del_count = 0;
#include <stdio.h>

void del_content(void *content)
{
	if (content)
		free(content);
	del_count++;
}

void *edit_content_toupper(void *content)
{
	char *str = strdup(content);
	char *s = str;
	while (*s)
	{
		*s = toupper(*s);
		s++;
	}
	return (str);
}

int main()
{
	t_list *lst = ft_lstnew(strdup("Hey"));
	lst->next = ft_lstnew(strdup("mum"));
	lst->next->next = ft_lstnew(strdup("!"));
	t_list *new_lst = ft_lstmap(lst, edit_content_toupper, del_content);

	if (lst->content ||lst->next->content || lst->next->next->content)
	{
		printf("TEST FAILED %s:%d\n", __FILE__, __LINE__);
		printf("List content is still defined");
	}

	if (strcmp(new_lst->content, "HEY")
		|| strcmp(new_lst->next->content, "MUM")
		|| strcmp(new_lst->next->next->content, "!")
	)
	{
		printf("TEST FAILED %s:%d\n", __FILE__, __LINE__);
		printf("new list contents is invalid");
	}
}

