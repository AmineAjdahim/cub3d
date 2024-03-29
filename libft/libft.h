/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 00:58:21 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/25 05:00:20 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>


void	*ft_malloc(size_t n);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isalnum(int c);
int		ft_atoi(const char *str);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memchr(const void *s, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strdup(const char *src);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strnstr(const char *str, const char *to_find, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strmapi(char const *s, char(*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char c);
int		ft_strrchr_o(const char *s, int c);
#endif
