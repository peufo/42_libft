/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:59:13 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/23 19:12:13 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, t_size n)
{
	char	*_dst;
	char	*_src;

	_src = (char *)src;
	_dst = (char *)dst;
	while (*_src && n--)
		*(_dst++) = *(_src++);
	return (dst);
}
