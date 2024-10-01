/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 18:23:50 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*get_zero()
{
	char	*str;

	str = malloc(2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == 0)
		return (get_zero());
	str = malloc(12);
	if (!str)
		return (NULL);
	str += 11;
	*(str) = '\0';
	if (n >= 0)
	{
		while (n != 0)
		{
			*(--str) = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		while (n != 0)
		{
			*(--str) = -(n % 10) + '0';
			n /= 10;
		}
		*(--str) = '-';
	}
	return (str);
}
