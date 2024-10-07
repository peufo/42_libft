/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:28:12 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/07 12:24:27 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (!lst)
		return (0);
	if (f)
		new_lst = ft_lstnew(f(lst->content));
	else
		new_lst = ft_lstnew(0);
	if (del && lst->content)
		del(lst->content);
	if (lst->next)
		new_lst->next = ft_lstmap(lst->next, f, del);
	return (new_lst);
}
