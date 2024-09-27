/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:30:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/27 23:36:35 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(t_size count, t_size size)
{
	void	*ptr;
	t_size	len;

	if (count == 0 || size == 0)
		len = 1;
	else
		len = count * size;
	ptr = malloc(len);
	if (ptr)
		ft_bzero(ptr, len);
	return (ptr);
}
