/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 21:35:55 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/23 00:23:49 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	char		*t;

	i = 0;
	t = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			t = (char *)s;
		s++;
	}
	if (c == '\0')
		return (char *)s;
	return (t);
}

int		ft_strrchr_o(const char *s, int c)
{
	int			i;
	int			t;

	i = 0;
	t = 0;
	while (*s != '\0')
	{
		if (*s == (char)c)
			t = 1;
		s++;
	}
	return (t);
}