/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:06:44 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 09:02:49 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(const char *a, const char *b)
{
	char	*str;
	size_t	len;

	if (!a || !b)
		return (0);
	len = ft_strlen(a) + ft_strlen(b) + 1;
	str = ft_calloc(len, sizeof(*str));
	if (!str)
		return (str);
	ft_strlcat(str, a, len);
	ft_strlcat(str, b, len);
	return (str);
}
