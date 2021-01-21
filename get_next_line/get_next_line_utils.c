/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:12:09 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/30 22:12:33 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		len1;
	int		len;

	if (!(s2) || !(s1))
		return (0);
	len = ft_strlen(s1);
	len1 = ft_strlen(s2);
	if (!(res = malloc(len + len1 + 1)))
		return (0);
	ft_strcpy(res, s1);
	ft_strcpy(&res[len], s2);
	free(s1);
	s1 = NULL;
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dst, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strchr(char *s, int c)
{
	char *i;

	if (!s)
		return (0);
	i = NULL;
	if (c == '\0')
		i = (s + ft_strlen(s));
	while (*s)
	{
		if (*s == c || *s == '\0')
		{
			i = s;
			break ;
		}
		s++;
	}
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!
	s)
		return (0);
	if (start > ft_strlen(s))
	{
		res = malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	i = 0;
	if (!(res = malloc(len + 1)))
		return (NULL);
	while (i < len)
		res[i++] = s[start++];
	res[i] = '\0';
	return (res);
}
