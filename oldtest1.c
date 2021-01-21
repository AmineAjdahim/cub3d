/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 14:09:17 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/26 18:27:44 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		textures_wh(void)
{
	if (g_rayss.lh > g_rayss.lv && (acosf(cosf(g_rayss.gama)) < M_PI / 2))
		g_rayss.texture = g_texture1;
	if (g_rayss.lh > g_rayss.lv && !(acosf(cosf(g_rayss.gama)) < M_PI / 2))
		g_rayss.texture = g_texture2;
	if (g_rayss.lh < g_rayss.lv && (asinf(sinf(g_rayss.gama)) > 0))
		g_rayss.texture = g_texture3;
	if (g_rayss.lh < g_rayss.lv && !(asinf(sinf(g_rayss.gama)) > 0))
		g_rayss.texture = g_texture4;
	if (g_rayss.lh > g_rayss.lv && (acosf(cosf(g_rayss.gama)) < M_PI / 2))
		g_rayss.texture_width = g_texture_width1;
	if (g_rayss.lh > g_rayss.lv && !(acosf(cosf(g_rayss.gama)) < M_PI / 2))
		g_rayss.texture_width = g_texture_width2;
	if (g_rayss.lh < g_rayss.lv && (asinf(sinf(g_rayss.gama)) > 0))
		g_rayss.texture_width = g_texture_width3;
	if (g_rayss.lh < g_rayss.lv && !(asinf(sinf(g_rayss.gama)) > 0))
		g_rayss.texture_width = g_texture_width4;
	if (g_rayss.lh > g_rayss.lv && (acosf(cosf(g_rayss.gama)) < M_PI / 2))
		g_rayss.texture_height = g_texture_height1;
	if (g_rayss.lh > g_rayss.lv && !(acosf(cosf(g_rayss.gama)) < M_PI / 2))
		g_rayss.texture_height = g_texture_height2;
	if (g_rayss.lh < g_rayss.lv && (asinf(sinf(g_rayss.gama)) > 0))
		g_rayss.texture_height = g_texture_height3;
	if (g_rayss.lh < g_rayss.lv && !(asinf(sinf(g_rayss.gama)) > 0))
		g_rayss.texture_height = g_texture_height4;
}

void		rays(void)
{
	draw_heavens();
	g_rayss.gama = g_alpha - M_PI / 6;
	g_rayss.addition = (M_PI / 3) / g_window_width;
	g_rayss.n = 0;
	while (g_rayss.gama < g_alpha + M_PI / 3)
	{
		g_store = heroz(g_rayss.gama);
		g_store2 = vertical(g_rayss.gama);
		g_rayss.lh = g_store.l;
		g_rayss.lv = g_store2.l;
		if (g_rayss.lh < g_rayss.lv)
			g_rayss.l = g_rayss.lh;
		else
			g_rayss.l = g_rayss.lv;
		textures_wh();
		g_rayss.slice_size = g_wall * (((g_window_width / 2) /
			tanf(M_PI / 6)) / (g_rayss.l * cosf(g_rayss.gama - g_alpha)));
		draw_wall(g_rayss.slice_size, g_rayss.n, (g_rayss.lh > g_rayss.lv) ?
			(sin(g_rayss.gama) * g_rayss.l + g_playery) :
				cos(g_rayss.gama) * g_rayss.l +
			g_playerx, g_wall);
		g_rayss.gama += g_rayss.addition;
		g_rayss.n++;
	}
}

void		collisions_alpha(void)
{
	g_coll.k = 2;
	g_alphap.b = (g_wall / g_coll.k * cos(g_alpha));
	g_alphap.b1 = (g_wall / g_coll.k * cos(M_PI / 2 - g_alpha));
	g_alphap.a = (g_wall / g_coll.k * sin(g_alpha));
	g_alphap.a1 = (g_wall / g_coll.k * sin(M_PI / 2 - g_alpha));
	g_coll.i1 = ((g_playery - g_coll.k * g_alphap.a) / g_wall);
	g_coll.j1 = ((g_playerx - g_coll.k * g_alphap.b) / g_wall);
	g_coll.i13 = ((g_playery + g_coll.k * g_alphap.a) / g_wall);
	g_coll.j13 = ((g_playerx + g_coll.k * g_alphap.b) / g_wall);
	g_coll.i0 = ((g_playery - g_coll.k * g_alphap.a1) / g_wall);
	g_coll.j0 = ((g_playerx + g_coll.k * g_alphap.b1) / g_wall);
	g_coll.i2 = ((g_playery + g_coll.k * g_alphap.a1) / g_wall);
	g_coll.j2 = ((g_playerx - g_coll.k * g_alphap.b1) / g_wall);
}

void		key_with_coll(int key)
{
	if (key == 13 && g_map[g_coll.i13][g_coll.j13] != 1)
	{
		g_playery += g_alphap.a;
		g_playerx += g_alphap.b;
	}
	if (key == 1 && g_map[g_coll.i1][g_coll.j1] != 1)
	{
		g_playery -= g_alphap.a;
		g_playerx -= g_alphap.b;
	}
	if (key == 2 && g_map[g_coll.i2][g_coll.j2] != 1)
	{
		g_playery += g_alphap.a1;
		g_playerx -= g_alphap.b1;
	}
	if (key == 0 && g_map[g_coll.i0][g_coll.j0] != 1)
	{
		g_playery -= g_alphap.a1;
		g_playerx += g_alphap.b1;
	}
}

int			deal_key(int key)
{
	collisions_alpha();
	if (key == 123)
		g_alpha -= 0.03 * M_PI;
	if (key == 124)
		g_alpha += 0.03 * M_PI;
	if (key == 53)
		exit(1);
	key_with_coll(key);
	rays();
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_new_img, 0, 0);
	return (0);
}
