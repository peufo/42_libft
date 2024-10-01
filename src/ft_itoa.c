/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 21:44:38 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*handle_positive(char *str, int n)
{
	while (n != 0)
	{
		*(--str) = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char	*handle_negative(char *str, int n)
{
	while (n != 0)
	{
		*(--str) = -(n % 10) + '0';
		n /= 10;
	}
	*(--str) = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(12);
	if (!str)
		return (NULL);
	str += 12;
	*(--str) = '\0';
	if (n > 0)
		return (handle_positive(str, n));
	else if (n < 0)
		return (handle_negative(str, n));
	*(--str) = '0';
	return (str);
}
