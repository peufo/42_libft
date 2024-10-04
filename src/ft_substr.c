/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:20:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/04 15:08:08 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*sub;

	if (!len)
		len = ft_strlen(s) + 1;
	sub = ft_calloc(len, sizeof(char));
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, len);
	*(sub + len) = '\0';
	return (sub);
}
