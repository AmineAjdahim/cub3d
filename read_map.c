/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:12:26 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 16:12:34 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		*ft_set(void *b, int c, size_t len)
{
	unsigned char	*t;
	unsigned int	i;

	i = 0;
	t = b;
	while (i < len)
	{
		t[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void		allocmap(void)
{
	int i;

	i = 0;
	g_map = (char **)malloc(sizeof(char*) * g_heightmap);
	while (i <= g_heightmap)
	{
		g_map[i] = (char *)malloc(sizeof(char) * g_widthmap);
		ft_set(g_map[i], 8, sizeof(char ) * g_widthmap);
		i++;
	}
}

void		fill_map(char *line, int l, int mapline, int *error)
{
	g_f.b = ft_strlen(line);
	g_f.a = 0;
	while (g_f.a < g_widthmap)
	{
		if (g_f.a <= g_f.b)
		{
			if (line[g_f.a] == ' ')
				g_map[l - mapline][g_f.a] = ' ';
			if (line[g_f.a] == '1')
				g_map[l - mapline][g_f.a] = 1;
			if (line[g_f.a] == '0')
				g_map[l - mapline][g_f.a] = 0;
			if (line[g_f.a] == '2')
				g_map[l - mapline][g_f.a] = 2;
			if (line[g_f.a] == 'S' || line[g_f.a] == 'W' ||
				line[g_f.a] == 'E' || line[g_f.a] == 'N')
				g_map[l - mapline][g_f.a] = line[g_f.a];
			if (line[g_f.a] != 'S' && line[g_f.a] != 'W' && line[g_f.a] != 'E'
				&& line[g_f.a] != 'N' && line[g_f.a] != ' ' &&
				line[g_f.a] != '1' && line[g_f.a] != '0' &&
				line[g_f.a] != '2' && line[g_f.a] != '\0')
				*error = l - mapline;
		}
		g_f.a++;
	}
}

int			read_map(int mapline)
{
	int		i;
	int		error;
	int		fd;
	char	*line;

	error = 0;
	i = 0;
	allocmap();
	fd = open(g_path, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		if (i >= mapline)
			fill_map(line, i, mapline, &error);
		free(line);
		i++;
	}
	free(line);
	fill_map(line, i, mapline, &error);
	close(fd);
	return (error);
}

int			playercount(void)
{
	int i;
	int count;
	int count2;
	int j;

	i = 0;
	count = 0;
	count2 = 0;
	while (i < g_heightmap)
	{
		j = 0;
		while (j < g_widthmap)
		{
			if (g_map[i][j] == 'W' || g_map[i][j] == 'S' ||
				g_map[i][j] == 'N' || g_map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	return (count > 1 || count2 > 1);
}
