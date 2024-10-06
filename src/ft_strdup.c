/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:51:11 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 09:02:49 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	len;

	len = ft_strlen(str) + 1;
	dup = ft_calloc(len, sizeof(*dup));
	if (dup)
		ft_strlcpy(dup, str, len);
	return (dup);
}
