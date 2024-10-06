/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 15:52:42 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 16:26:16 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	clear_next(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	clear_next(lst->next, del);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!lst)
		return ;
	clear_next(*lst, del);
	*lst = NULL;
}
