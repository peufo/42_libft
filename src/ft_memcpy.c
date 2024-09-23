/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:59:13 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/23 21:59:23 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, t_size n)
{
	char	*_dst;
	char	*_src;

	if (n == 0 || dst == src)
		return (dst);
	_src = (char *)src;
	_dst = (char *)dst;
	while (n--)
		*(_dst++) = *(_src++);
	return (dst);
}
