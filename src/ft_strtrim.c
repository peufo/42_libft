/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 10:18:07 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/28 11:54:49 by jvoisard         ###   ########.fr       */
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
	return (ft_substr(str, start, end - start + 2));
}
