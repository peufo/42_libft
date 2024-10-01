/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 01:06:44 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 13:01:23 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strjoin(const char *a, const char *b)
{
	char	*str;
	t_size	len;

	len = ft_strlen(a) + ft_strlen(b) + 1;
	str = calloc(len, sizeof(*str));
	if (!str)
		return (str);
	ft_strlcat(str, a, len);
	ft_strlcat(str, b, len);
	return (str);
}
