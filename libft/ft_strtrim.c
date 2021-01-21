/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:42:03 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/25 07:35:02 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hamid(char c, char *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int last;

	i = 0;
	if (s1 == 0)
		return (NULL);
	while (s1[i] != '\0' && hamid(s1[i], (char *)set))
		i++;
	last = ft_strlen((char *)s1);
	while (s1[i] != '\0' && hamid(s1[last - 1], (char *)set))
		last--;
	return (ft_substr(s1, i, last - i));
}
