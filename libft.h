/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvoisard <jvoisard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 22:24:54 by jvoisard          #+#    #+#             */
/*   Updated: 2024/10/01 20:38:45 by jvoisard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>

typedef unsigned long	t_size;

int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
t_size	ft_strlen(const char *str);
t_size	ft_strlcpy(char *dst, const char *src, t_size len);
void	ft_bzero(void *s, t_size n);
void	*ft_memset(void *str, int c, t_size n);
void	*ft_memcpy(void *dst, const void *src, t_size n);
void	*ft_memmove(void *dst, const void *src, t_size n);
t_size	ft_strlcat(char *dst, const char *src, t_size dsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, t_size n);
int		ft_memcmp(const void *s1, const void *s2, t_size n);
char	*ft_strnstr(const char *str, const char *find, t_size len);
void	*ft_calloc(t_size count, t_size size);
char	*ft_strdup(const char *str);
char	*ft_substr(char const *s, unsigned int start, t_size len);
char	*ft_strjoin(const char *a, const char *b);
char	*ft_strtrim(char const *str, char const *set);
char	**ft_split(char const *str_origin, char c);
char	**ft_split(char const *str_origin, char c);
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int , int, char));
#endif
