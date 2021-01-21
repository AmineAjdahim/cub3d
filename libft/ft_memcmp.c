/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:25:45 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/15 23:06:04 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	a;

	a = 0;
	while (n > a)
	{
		if (((unsigned char *)s1)[a] != ((unsigned char *)s2)[a])
		{
			return ((int)(((unsigned char *)s1)[a]
						- ((unsigned char *)s2)[a]));
		}
		a++;
	}
	return (0);
}
