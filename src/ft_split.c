/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 15:54:47 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 15:18:16 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*str_cut(char *start, char *end)
{
	char	*cut;
	char	*_cut;

	if (!start | !end | end < start)
		return (NULL);
	cut = malloc(end - start + 1);
	_cut = cut;
	if (!cut)
		return (NULL);
	while (start < end)
		*(_cut++) = *(start++);
	*_cut = '\0';
	return (cut);
}

t_size	get_length(char const *str_origin, char c)
{
	t_size		length;
	char		*str;

	length = 0;
	str = (char *)str_origin;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		length += (!!*str);
		while (*str && *str != c)
			str++;
	}
	return (length);
}

char	**ft_split(char const *str_origin, char c)
{
	t_size		length;
	t_size		index;
	char		**arr;
	char		*start;
	char		*end;

	length = get_length(str_origin, c);
	arr = malloc(sizeof(*arr) * (length + 1));
	start = (char *)str_origin;
	index = 0;
	while (*start)
	{
		while (*start && *start == c)
			start++;
		end = start;
		while (*end && *end != c)
			end++;
		if (start == end)
			break ;
		arr[index++] = str_cut(start, end);
		start = end;
	}
	arr[index] = NULL;
	return (arr);
}
