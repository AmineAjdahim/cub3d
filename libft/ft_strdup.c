/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 03:23:00 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/18 17:09:21 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char			*temp;
	unsigned long	len;

	len = ft_strlen((char*)src);
	if (!(temp = (char*)malloc(len + 1)))
		return (0);
	memcpy(temp, (char*)src, len);
	temp[len] = '\0';
	return (temp);
}
