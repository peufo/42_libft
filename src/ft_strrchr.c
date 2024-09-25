/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:01:10 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/25 17:06:00 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char	*s_origin;

	s_origin = s;
	while (*s++)
		;
	while (s > s_origin)
		if (*(--s) == c)
			return ((char *)(s));
	return ((void *)0);
}
