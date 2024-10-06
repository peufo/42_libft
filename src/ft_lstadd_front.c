/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 13:44:53 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 13:56:10 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_list	*get_last(t_list *lst)
{
	if (!lst->next)
		return (lst);
	return (get_last(lst->next));
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*last;

	last = get_last(new);
	last->next = *lst;
	*lst = new;
}
