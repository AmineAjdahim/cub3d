/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 11:00:21 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/29 11:00:27 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ismapline(char *line, int i)
{
	int a;

	a = i;
	while (line[a] != '\0')
	{
		if (ft_strchr("102WSEN ", line[a]))
			return (0);
		a++;
	}
	return (1);
}

int				readfile2(char *line, int i)
{
	int r;

	g_rf.line = line;
	g_rf.i = 0;
	r = 0;
	r = resolution(line, i, 'R');
	if (r == 1)
		r = get_textures(i, 0, 'N', 'O');
	if (r == 1)
		r = get_textures(i, 1, 'S', 'O');
	if (r == 1)
		r = get_textures(i, 2, 'W', 'E');
	if (r == 1)
		r = get_textures(i, 3, 'E', 'A');
	if (r == 1)
		r = get_textures(i, 4, 'S', ' ');
	if (r == 1)
		r = floorsky(line, i, &g_skycolor, 'C');
	if (r == 1)
		r = floorsky(line, i, &g_floorcolor, 'F');
	if (r == 1)
		r = ismapline(line, i);
	if (line[i] == '\0')
		return (1);
	return (r);
}
