/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 22:35:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 22:11:51 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_size	ft_strlcpy(char *dst, const char *src, t_size len)
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
