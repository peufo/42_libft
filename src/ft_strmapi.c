/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jonas.voisard@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 21:25:34 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/05 22:01:06 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	t_size			len;
	char			*res;
	unsigned int	index;

	if (!s)
		return (0);
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (!res)
		return (0);
	index = 0;
	while (index < len)
	{
		res[index] = f(index, s[index]);
		index++;
	}
	res[len] = '\0';
	return (res);
}
