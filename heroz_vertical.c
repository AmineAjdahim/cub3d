/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heroz_vertical.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:12:06 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 16:12:16 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_intersection		heroz2(double alphaa)
{
	if (g_map[g_h.i][g_h.j] == 1 && g_h.found == 1)
	{
		g_h.found = 0;
		g_h.a = powf(g_playerx - g_h.ax, 2);
		g_h.b = powf(g_playery - g_h.ay, 2);
		g_store.l = sqrtl(g_h.a + g_h.b);
		g_store.xi = g_h.ax;
		g_store.yi = g_h.ay;
	}
	g_h.ax = (g_h.up < 0) ? g_h.ax - g_wall / tanf(alphaa) :
		g_h.ax + g_wall / tanf(alphaa);
	g_h.ay = (g_h.up < 0) ? g_h.ay - g_wall : g_h.ay + g_wall;
	g_h.j = g_h.ax / g_wall;
	g_h.i = (g_h.ay - (g_h.up < 0)) / g_wall;
	return (g_store);
}

t_intersection		heroz(double alphaa)
{
	g_h.up = asinf(sinf(alphaa));
	g_store.l = INT32_MAX;
	if (g_playerx == 0 || g_playery == 0)
		return (g_store);
	if (g_h.up < 0)
		g_h.ay = (floor((g_playery / g_wall)) * g_wall);
	else
		g_h.ay = (floor(g_playery / g_wall) * g_wall) + g_wall;
	g_h.ax = g_playerx - (g_playery - g_h.ay) / tanf(alphaa);
	g_h.i = (g_h.ay - (g_h.up < 0)) / g_wall;
	g_h.j = g_h.ax / g_wall;
	g_h.found = 1;
	while (g_h.j >= 0 && g_h.i >= 0 && g_h.j < g_widthmap &&
		g_h.i < g_heightmap)
	{
		if (g_map[g_h.i][g_h.j] == 2)
		{
			g_store.ls = sqrt(powf(g_playerx - g_h.ax, 2) + powf(g_playery - g_h.ay, 2));
			g_store.i = g_h.i;
			g_store.j = g_h.j;
		}
		heroz2(alphaa);
	}
	//printf(" heroz =============%f , %d, %d \n",g_store.ls,g_store.i,g_store.j = g_h.j);
	return (g_store);
}

t_intersection		vertical2(double alphaa)
{
	if (g_map[g_v.i][g_v.j] == 1 && g_v.found == 0)
	{
		g_v.found = 1;
		g_v.a = powf(g_playerx - g_v.bx, 2);
		g_v.b = powf(g_playery - g_v.by, 2);
		g_intersection.l = sqrtl(g_v.a + g_v.b);
		g_intersection.xi = g_v.bx;
		g_intersection.yi = g_v.by;
	}
	g_v.bx = (g_v.right < M_PI / 2) ? g_v.bx + g_wall : g_v.bx - g_wall;
	g_v.by = (g_v.right < M_PI / 2) ? (g_v.by) + (g_wall * tanf(alphaa)) :
		(g_v.by) - (g_wall * tanf(alphaa));
	g_v.j = (g_v.bx - (g_v.right >= M_PI / 2)) / g_wall;
	g_v.i = g_v.by / g_wall;
	return (g_intersection);
}

t_intersection		vertical(double alphaa)
{
	g_v.right = acosf(cosf(alphaa));
	g_intersection.l = INT32_MAX;
	if (g_playerx == 0 || g_playery == 0)
		return (g_intersection);
	if (g_v.right < M_PI / 2)
		g_v.bx = (floor((g_playerx / g_wall)) * g_wall) + g_wall;
	else
		g_v.bx = (floor((g_playerx / g_wall)) * g_wall);
	g_v.by = g_playery - (g_playerx - g_v.bx) * tanf(alphaa);
	g_v.i = g_v.by / g_wall;
	g_v.j = (g_v.bx - (g_v.right >= M_PI / 2)) / g_wall;
	g_v.found = 0;
	while (g_v.j >= 0 && g_v.i >= 0 && g_v.i < g_heightmap &&
		g_v.j < g_widthmap)
	{
		if (g_map[g_v.i][g_v.j] == 2)
		{
			g_intersection.ls = sqrt(powf(g_playerx - g_v.bx, 2) + powf(g_playery - g_v.by, 2));
			g_intersection.i = g_v.i;
			g_intersection.j = g_v.j;
		}
		vertical2(alphaa);
	}
	//printf("vertical ================== %f , %d, %d \n",g_intersection.ls,g_intersection.i,g_intersection.j);
	return (g_intersection);
}
