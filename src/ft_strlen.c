/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:01:59 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 22:19:42 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_size	ft_strlen(const char *str)
{
	t_size	size;

	if (!str)
		return (0);
	size = 0;
	while (str[size])
		size++;
	return (size);
}
