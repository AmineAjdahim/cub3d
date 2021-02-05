/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall_heavens_rect.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:58:15 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 15:58:52 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rect(float l, int px)
{
	int xt;
	int start;
	int end;

	xt = -1;
	start = (g_window_height - l) / 2;
	end = (g_window_height + l) / 2;
	end = (end >= g_window_height) ? g_window_height : end;
	while (start++ <= end)
	{
		if (start >= 0)
			draw(px, start, 0xffffff);
	}
}

void	rect_draw(int rect_height, int x, int y, int color)
{
	int len;
	int mlen;
	int rect_width;

	rect_width = g_window_width;
	len = x + rect_width;
	while (len-- != x)
	{
		mlen = y + rect_height;
		while (mlen-- != y)
			draw(len, mlen, color);
	}
}

void	draw_heavens(void)
{
	rect_draw(g_window_height / 2, 0, 0, g_skycolor);
	rect_draw(g_window_height / 2, 0,
		g_window_height / 2, g_floorcolor);
}

void	draw_wall(float l, int px, int ix, int s)
{
	g_drw.xt = -1;
	g_drw.end = (g_window_height + l) / 2;
	g_drw.start = (g_window_height - l) / 2;
	g_drw.end = (g_drw.end >= g_window_height) ? g_window_height : g_drw.end;
	while (g_drw.start++ < g_drw.end)
	{
		g_drw.wall_y = (++g_drw.xt * g_rayss.texture_height) / l;
		g_drw.wall_x = (((int)ix % s) * g_rayss.texture_width / s);
		if (g_drw.start >= 0 && g_rayss.texture[((int)g_drw.wall_y) *
			g_rayss.texture_width + (int)g_drw.wall_x] > 0x000000)
			draw(px, g_drw.start, g_rayss.texture[((int)g_drw.wall_y) *
				g_rayss.texture_width + (int)g_drw.wall_x]);
	}
}
