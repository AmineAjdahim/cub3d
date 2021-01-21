/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 22:40:45 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/23 00:33:52 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	char		*p;
	int			i;

	if (!(p = malloc(count * size)))
		return ((void *)p);
	i = 0;
	while (i < ((int)(count * size)))
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
