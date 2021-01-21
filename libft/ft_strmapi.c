/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 20:13:04 by majdahim          #+#    #+#             */
/*   Updated: 2019/10/22 17:55:24 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*tab;

	size = 0;
	if (s == 0)
		return (NULL);
	while (s[size] != '\0')
		size++;
	if (!(tab = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		tab[i] = (*f)(i, s[i]);
		i++;
	}
	*(tab + i) = '\0';
	return (tab);
}
