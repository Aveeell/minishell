/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerrok <jerrok@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:41:24 by jerrok            #+#    #+#             */
/*   Updated: 2022/04/19 10:42:58 by jerrok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

int		ft_atoi(const char *str);
void	ft_bzero(char *str, size_t size);
int		ft_isalnum(int ch);
int		ft_isalpha(int ch);
int		ft_isascii(int ch);
int		ft_isdigit(int ch);
int		ft_isprint(int ch);
void	*ft_memcpy(char *dest, const char *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_memset(char *str, char symb, size_t size);
char	*ft_strchr(char const *str, int n);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);
size_t	ft_strlen(char const *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(char const *str, char const *substr, size_t n);
char	*ft_strrchr(char const *str, int n);
int		ft_tolower(int ch);
int		ft_toupper(int ch);
char	*ft_strdup(char *src);
void	*ft_memccpy(char *dest, const char *src, int c, size_t size);
void	*ft_memchr(const void *src, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t number, size_t size);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_itoa(int n);
void	ft_putnbr_fd(int n, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putnbr_fd(int n, int fd);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strcmp(char *s1, char *s2);

#endif