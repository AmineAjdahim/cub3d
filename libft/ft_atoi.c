/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 02:19:29 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/24 06:38:11 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int				i;
	int				b;
	size_t			c;

	i = 0;
	b = 1;
	c = 0;
	while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\r') ||
			(str[i] == '\n' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '-')
		b = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		c = c * 10 + (str[i] - '0');
		if (c > 9223372036854775807 && b == -1)
			return (0);
		else if (c > 9223372036854775807 && b == 1)
			return (-1);
		i++;
	}
	return (c * b);
}
