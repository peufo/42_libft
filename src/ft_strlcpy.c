/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:35:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/23 23:12:17 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_size	ft_strlcpy(char *dst, const char *src, t_size len)
{
	const char *_src;
	t_size _len;

	_src = src;
	_len = len;
	if (len)
		while (*_src && --_len)
			*(dst++) = *(_src++);
	*dst = '\0';
	while (*_src)
		_src++;
	return (_src - src);	
}