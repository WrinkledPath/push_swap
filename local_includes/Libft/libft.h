/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ywagner <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 17:36:10 by ywagner           #+#    #+#             */
/*   Updated: 2025/02/13 15:40:54 by ywagner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

long	ft_atol(const char *str);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int arg);
int		ft_isprint(int c);
int		ft_memcmp(const void *ptr1, const void *ptr2, size_t size);
int		ft_strlcpy(char *dst, const char *src, size_t dst_len);
int		ft_strncmp(const char *s1, const char *s2, size_t size);
int		ft_tolower(int ch);
int		ft_toupper(int ch);

void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *str, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(void *ptr, int value, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

char	*ft_itoa(int n);
char	**ft_split(const char *s, char c);
char	*ft_strchr(const char *str, int chr);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *big, const char *small, size_t len);
char	*ft_strrchr(const char *str, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(const char *s, unsigned int start, size_t len);

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
size_t	ft_strlen(const char *str);
#endif
