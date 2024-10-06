/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:31:19 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 09:02:49 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*dst_origin;
	const char	*src_origin;
	size_t		n;
	size_t		dst_len;

	dst_origin = dst;
	src_origin = src;
	n = dsize;
	while (n-- && *dst)
		dst++;
	dst_len = dst - dst_origin;
	n = dsize - dst_len;
	if (n == 0)
		return (dst_len + ft_strlen(src));
	while (--n && *src)
		*(dst++) = *(src++);
	while (*src)
		src++;
	*dst = '\0';
	return (dst_len + (src - src_origin));
}
