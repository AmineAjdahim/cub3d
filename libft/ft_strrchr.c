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
	char *res;

	res = NULL;
	if (c == 0)
		return ((char *)(s + ft_strlen((char *)s)));
	while (*s)
	{
		if (*s == c)
			res = (char *)s;
		s++;
	}
	return (res);
}
