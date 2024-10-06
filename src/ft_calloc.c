/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:30:04 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/06 09:02:49 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	if (count == 0 || size == 0)
		len = 1;
	else
		len = count * size;
	ptr = malloc(len);
	if (ptr)
		ft_bzero(ptr, len);
	return (ptr);
}
