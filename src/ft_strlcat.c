/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 23:31:19 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/27 23:37:18 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_size	ft_strlcat(char *dst, const char *src, t_size dsize)
{
	const char	*dst_origin;
	const char	*src_origin;
	t_size		n;
	t_size		dst_len;

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
