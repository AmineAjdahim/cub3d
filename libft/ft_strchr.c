/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 04:15:07 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/23 03:05:45 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *i;

	i = NULL;
	if (c == '\0')
		i = (char *)(s + ft_strlen((char *)s));
	while (*s)
	{
		if (*s == c)
		{
			i = (char *)s;
			break ;
		}
		s++;
	}
	return (i);
}
