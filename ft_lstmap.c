/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:28:12 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/08 16:32:02 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (0);
	new_lst = ft_lstnew(ft_strdup(f(lst->content)));
	if (lst->content)
		del(lst->content);
	if (lst->next)
		new_lst->next = ft_lstmap(lst->next, f, del);
	else
		new_lst->next = NULL;
	return (new_lst);
}
