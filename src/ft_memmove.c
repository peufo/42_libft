/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 20:55:54 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/04 15:26:36 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, const void *src, t_size n)
{
	char	*_dst;
	char	*_src;

	if (!dst && !src)
		return (0);
	_src = (char *)src;
	_dst = (char *)dst;
	if (_dst < _src)
	{
		while (n--)
			*(_dst++) = *(_src++);
	}
	else if (_dst > _src)
	{
		_src += n;
		_dst += n;
		while (n--)
			*(--_dst) = *(--_src);
	}
	return (dst);
}
