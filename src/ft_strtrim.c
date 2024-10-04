/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:18:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/04 23:52:40 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static short	is_in_charset(char c, const char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *str, char const *set)
{
	t_size		start;
	t_size		end;

	if (!str || !set)
		return (0);
	start = 0;
	while (str[start] && is_in_charset(str[start], set))
		start++;
	end = start;
	while (str[end])
		end++;
	if (end > start)
		end--;
	while (end >= start && str[end] && is_in_charset(str[end], set))
		end--;
	return (ft_substr(str, start, end - start + 1));
}
