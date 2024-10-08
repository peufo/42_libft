/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:07:30 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/08 16:33:52 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	find_len;

	if (!*find)
		return ((char *)str);
	if (!len-- || !*str)
		return (0);
	find_len = ft_strlen(find) - 1;
	while (*str++ != *find)
		if (!len-- || !*str)
			return (0);
	while (ft_strncmp(str, find, find_len))
		while (*str++ != *find)
			if (!len-- || !*str)
				return (0);
	str--;
	return ((char *)str);
}
