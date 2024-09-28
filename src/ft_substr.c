/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:20:15 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/28 11:34:21 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*sub;

	sub = ft_calloc(len, sizeof(char));
	if (sub)
		ft_strlcpy(sub, s + start, len);
	return (sub);
}
