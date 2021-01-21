/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:09:09 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 16:10:05 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw(int x, int y, int color)
{
	if (x < g_window_width && y < g_window_height)
		g_pixels[y * g_window_width + x] = color;
}

void	sq(int x, int y, int size, int color)
{
	int liney;
	int linex;

	liney = size - 1;
	while (liney--)
	{
		linex = size - 1;
		while (linex--)
		{
			draw(x + linex, y + liney, color);
		}
	}
}

void	draw_map(void)
{
	int te;

	te = 1;
	g_drawi.i = 0;
	while (g_drawi.i < g_heightmap)
	{
		g_drawi.j = 0;
		while (g_drawi.j < g_widthmap)
		{
			if (g_map[g_drawi.i][g_drawi.j] == 1)
			{
				g_drawi.lnx = g_drawi.j * g_wall;
				g_drawi.lny = g_drawi.i * g_wall;
			}
			if (g_map[g_drawi.i][g_drawi.j] == 'E' && te)
			{
				te = 0;
				g_playerx = (g_drawi.j * g_wall) + (g_wall / 2);
				g_playery = (g_drawi.i * g_wall) + (g_wall / 2);
			}
			g_drawi.j++;
		}
		g_drawi.i++;
	}
}

void	square(int x, int y, int a, int b)
{
	int len1;
	int len2;

	len1 = a;
	len2 = b;
	while (len1--)
	{
		len2 = b;
		while (len2--)
			draw(x + len2, y + len1, 0);
	}
}
