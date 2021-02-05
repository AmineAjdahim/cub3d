/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:10:19 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 16:10:39 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	oneclosed_v(int i, int j)
{
	int a;
	int closed;

	a = i - 1;
	closed = 0;
	while (a >= 0 && closed == 0)
	{
		if (g_map[a][j] == 1)
			closed++;
		if (g_map[a][j] == 8)
			return (0);
		a--;
	}
	a = i + 1;
	while (a < g_heightmap && closed == 1)
	{
		if (g_map[a][j] == 1)
			closed++;
		a++;
	}
	if (closed == 2)
		return (1);
	else
		return (0);
}

int	oneclosed_h(int i, int j)
{
	int a;
	int closed;

	a = j - 1;
	closed = 0;
	while (a >= 0 && closed == 0)
	{
		if (g_map[i][a] == 1)
			closed++;
		if (g_map[i][a] == 8)
			return (0);
		a--;
	}
	a = j + 1;
	while (a < g_widthmap && closed == 1)
	{
		if (g_map[i][a] == 1)
			closed++;
		a++;
	}
	if (closed == 2)
		return (1);
	else
		return (0);
}

int			checksurround(char **mapp, int i, int j, char c)
{
	if (i != 0 && mapp[i - 1][j] == c)
		return (1);
	if (i != g_heightmap - 1 && mapp[i + 1][j] == c)
		return (1);
	if (j != g_widthmap && mapp[i][j + 1] == c)
		return (1);
	if (j != 0 && mapp[i][j - 1] == c)
		return (1);
	return (0);
}

int			check_wsne(void)
{
	if (g_map[g_mp.i][g_mp.j] != ' ' && g_map[g_mp.i][g_mp.j] != 1 &&
			g_map[g_mp.i][g_mp.j] != 2 && g_map[g_mp.i][g_mp.j] != 0 &&
				g_map[g_mp.i][g_mp.j] != 'N' &&
				g_map[g_mp.i][g_mp.j] != 'S' && g_map[g_mp.i][g_mp.j] != 'E' &&
				g_map[g_mp.i][g_mp.j] != 'W' && g_map[g_mp.i][g_mp.j] != 8)
		return (1);
	return (0);
}

int			checkmap(void)
{
	g_mp.i = 0;
	g_mp.j = 0;
	if (playercount())
		return (1);
	while (g_mp.i < g_heightmap)
	{
		g_mp.j = 0;
		while (g_mp.j < g_widthmap)
		{
			if (g_map[g_mp.i][g_mp.j] == '2'){
				printf("FD\n");
			}
			if (g_map[g_mp.i][g_mp.j] == 'W' || g_map[g_mp.i][g_mp.j] == 'N' || g_map[g_mp.i][g_mp.j] == 'E' || g_map[g_mp.i][g_mp.j] == 'S' || g_map[g_mp.i][g_mp.j] == '2')
				if (checksurround(g_map, g_mp.i, g_mp.j, 32) || checksurround(g_map, g_mp.i, g_mp.j, 8) || g_mp.i == 0 || g_mp.j == 0 || g_mp.i == g_heightmap - 1 || g_mp.j == g_widthmap + 1){
					printf("1 %d, %d\n", g_mp.i, g_mp.j);
					return (1);
				}
			if (g_map[g_mp.i][g_mp.j] == 0)
				if (!oneclosed_h(g_mp.i, g_mp.j) ||
					!oneclosed_v(g_mp.i, g_mp.j)){
					printf("2 %d, %d\n", g_mp.i, g_mp.j);
					return (1);
				}
			if (g_map[g_mp.i][g_mp.j] == ' ')
				if (checksurround(g_map, g_mp.i, g_mp.j, 0)){
					printf("3 %d, %d\n", g_mp.i, g_mp.j);
					return (1);
				}
			check_wsne();
			g_mp.j++;
		}
		g_mp.i++;
	}
	return (0);
}
