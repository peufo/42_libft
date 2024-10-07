/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:35:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 09:02:49 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	const char	*_src;

	_src = src;
	if (len)
	{
		while (*_src && --len)
			*(dst++) = *(_src++);
		*dst = '\0';
	}
	while (*_src)
		_src++;
	return (_src - src);
}
