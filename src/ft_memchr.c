/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:05:56 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 09:02:49 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;
	unsigned char		_c;

	p = s;
	_c = (unsigned char)c;
	if (n == 0)
		return ((void *)0);
	while (*p && --n)
		if (*(p++) == _c)
			return ((void *)(p - 1));
	if (*p == c)
		return ((void *)(p));
	return (0);
}
