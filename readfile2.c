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

int		ismapline(char *line, int i)
{
	int a;

	a = i;
	while (line[a] != '\0')
	{
		if (!ft_strrchr_o("102WSNE ", line[a]))
			return (0);
		a++;
	}
	return (1);
}

int				readfile2(char *line, int i)
{
	int r;

	r = 0;
	r = resolution(line, i);
	if (r == -1)
	{
		r = 0;
		printf("Error\nResolution element is invalid");
	}
	if (r == 0)
		r = get_textures(line, i, 0, "NO");
	if (r == 0)
		r = get_textures(line, i, 1, "SO");
	if (r == 0)
		r = get_textures(line, i, 2, "WE");
	if (r == 0)
		r = get_textures(line, i, 3, "EA");
	if (r == 0)
		r = get_textures(line, i, 4, "S ");
	if (r == -1)
	{
		r = 0;
		printf("Error\nTexture element is invalid\n");
	}
	if (r == 0)
		r = floorsky(line, i, &g_floorcolor, 'F');
	if (r == 0)
		r = floorsky(line, i, &g_skycolor, 'C');
	if (r == -1)
	{
		r = 0;
		printf("Error\nColor element is invalid\n");
	}
	if (r == 0)
		r = ismapline(line, i);
	if (r == 0)
	{
		r = 0;
		printf("Error\nAdditional information has been found\n");
	}
	if (line[i] == '\0')
		return (1);
	return (r);
}