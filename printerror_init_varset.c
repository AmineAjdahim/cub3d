/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printerror_init_varset.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:11:10 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 16:11:48 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				varset(void)
{
	if (g_maplinefound == 0)
		return (0);
	if (g_window_width == -1 || g_window_height == -1)
		return (0);
	if (access(g_texture[0], F_OK) != 0 || access(g_texture[1], F_OK) != 0
			|| access(g_texture[2], F_OK) != 0 ||
				access(g_texture[3], F_OK) != 0
			|| access(g_texture[0], F_OK) != 0)
		return (0);
	if (g_skycolor == -1 || g_floorcolor == -1)
		return (0);
	return (1);
}

int				return_print(char *s)
{
	printf("%s", s);
	return (0);
}

void			get_player_cord1(int i, int j)
{
	if (g_map[i][j] == 'N')
		g_alpha = 0;
	if (g_map[i][j] == 'E')
		g_alpha = M_PI;
	if (g_map[i][j] == 'W')
		g_alpha = M_PI_2;
	if (g_map[i][j] == 'S')
		g_alpha = -1 * M_PI_2;
}

void			get_player_cord(void)
{
	int i;
	int j;

	i = 0;
	while (i < g_heightmap)
	{
		j = 0;
		while (j < g_widthmap)
		{
			if (g_map[i][j] == 'N' || g_map[i][j] == 'W' ||
				g_map[i][j] == 'S' || g_map[i][j] == 'E')
			{
				g_playerx = (j * g_wall) + (g_wall / 2);
				g_playery = (i * g_wall) + (g_wall / 2);
				get_player_cord1(i, j);
			}
			j++;
		}
		i++;
	}
}

int				return_error(int num_error)
{
	if (num_error == 0)
		printf("Error\nMissing arguments");
	if (num_error == 2)
		printf("Error\nMap file should end with .cub");
	if (num_error == 3)
		printf("Error\nError while reading from cub file");
	if (num_error == 4)
		printf("Error\nThere are some additional information");
	if (num_error == 5)
		printf("Error\nOne or more elements are missing or wrong");
	if (num_error == 6)
		printf("Error\nResolution element is wrong");
	if (num_error == 7)
		printf("Error\nMap is missconfigured");
	if (num_error == 8)
		printf("Error\nPlayer has not been found");
	return (0);
}

int				cubextension(char *s)
{
	int		i;
	int		j;
	char	*cub;

	i = ft_strlen(s) - 1;
	j = 3;
	cub = ".cub";
	while (j)
	{
		if (s[i] != cub[j])
			return (0);
		i--;
		j--;
	}
	return (1);
}

void			get_wall_size(void)
{
	if (g_window_width > 2560)
		g_window_width = 2560;
	if (g_window_height > 1440)
		g_window_height = 1440;
	if (g_widthmap > g_heightmap)
		if (g_window_width > g_widthmap)
			g_wall = g_window_width / g_widthmap;
		else
			g_wall = g_widthmap / g_window_width;
	else
	{
		if (g_window_height > g_heightmap)
			g_wall = g_window_height / g_heightmap;
		else
			g_wall = g_heightmap / g_window_height;
	}
}

int				intigame(int argc, char **argv)
{
	if (argc <= 1)
		return (return_error(0));
	if (argc > 2 && ft_strncmp(argv[2], "--save", 5) != 0)
		return (return_error(04));
	if (!cubextension(argv[1]))
		return (return_error(2));
	if ((readfile(argv[1]) != 1))
		return (return_error(3));
	if (read_map(getmapline() - 1) != 0)
		return (return_error(4));
	if (!varset())
		return (return_error(5));
	if (g_window_width <= 0 || g_window_height <= 0)
		return (return_error(6));
	if (checkmap())
		return (return_error(7));
	get_wall_size();
	get_player_cord();
	if (g_playerx == -1)
		return (return_error(8));
	return (1);
}
