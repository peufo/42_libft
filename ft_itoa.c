/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:29:22 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/05 00:16:08 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	*handle_positive(char *str, int n)
{
	while (n)
	{
		*(--str) = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

static char	*handle_negative(char *str, int n)
{
	while (n)
	{
		*(--str) = -(n % 10) + '0';
		n /= 10;
	}
	*(--str) = '-';
	return (str);
}

static short	get_malloc_len(int n)
{
	short	len;

	len = 1;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;

	str = malloc(get_malloc_len(n));
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
