/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:07:30 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 16:20:59 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_size	ft_startwith(const char *str, const char *start)
{
	while (*str && *start)
		if (*(str++) != *(start++))
			return (0);
	if (*start)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *str, const char *find, t_size len)
{
	t_size	find_len;

	if (!*find)
		return ((char *)str);
	find_len = ft_strlen(find);
	if (len > find_len)
	{
		len -= find_len - 1;
		while (len-- && *str)
			if (ft_startwith(str++, find))
				return ((char *)(str - 1));
	}
	return ((void *)0);
}
