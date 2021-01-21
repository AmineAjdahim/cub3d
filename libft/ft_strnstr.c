/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 18:35:15 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/25 08:17:58 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t		i;
	char		*ptr;
	char		*find;
	size_t		size;

	i = 0;
	ptr = (char *)str;
	find = (char *)to_find;
	if (*to_find == '\0' || to_find == NULL)
		return (ptr);
	size = ft_strlen(find);
	while (ptr[i] != '\0' && len >= i + size)
	{
		if (ft_strncmp(ptr + i, find, size) == 0)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
