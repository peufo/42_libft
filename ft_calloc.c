/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:30:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/08 16:31:09 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	if ((long)count < 0 && (long)size < 0)
		return (0);
	if (count == 0 || size == 0)
		len = 1;
	else
		len = count * size;
	ptr = malloc(len);
	if (ptr)
		ft_bzero(ptr, len);
	return (ptr);
}
