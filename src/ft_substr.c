/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:20:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/04 23:08:09 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*sub;
	t_size	str_len;

	if (!len || !s)
		return (0);
	str_len = ft_strlen(s);
	if (str_len < (t_size)start)
		len = 0;
	else if (str_len < len)
		len = str_len;
	sub = ft_calloc(len + 1, sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
