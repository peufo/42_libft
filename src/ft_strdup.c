/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:51:11 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 13:00:45 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strdup(const char *str)
{
	char	*dup;
	t_size	len;

	len = ft_strlen(str) + 1;
	dup = ft_calloc(len, sizeof(*dup));
	if (dup)
		ft_strlcpy(dup, str, len);
	return (dup);
}
