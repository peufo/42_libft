/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:15:34 by jvoisard          #+#    #+#             */
/*   Updated: 2024/09/27 23:37:09 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *str, int c, t_size n)
{
	unsigned char	*_str;

	_str = str;
	while (n--)
		*(_str++) = (unsigned char)c;
	return (str);
}
