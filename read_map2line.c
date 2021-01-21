/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map2line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:12:46 by majdahim          #+#    #+#             */
/*   Updated: 2020/12/28 16:12:54 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		initialize_textures(int add)
{
	g_texture1_id = mlx_xpm_file_to_image(g_mlx_ptr, g_texture[0],
		&g_texture_width1, &g_texture_height1);
	g_texture1 = (int *)mlx_get_data_addr(g_texture1_id, &add, &add, &add);
	g_texture2_id = mlx_xpm_file_to_image(g_mlx_ptr, g_texture[1],
		&g_texture_width2, &g_texture_height2);
	g_texture2 = (int *)mlx_get_data_addr(g_texture2_id, &add, &add, &add);
	g_texture3_id = mlx_xpm_file_to_image(g_mlx_ptr, g_texture[2],
		&g_texture_width3, &g_texture_height3);
	g_texture3 = (int *)mlx_get_data_addr(g_texture3_id, &add, &add, &add);
	g_texture4_id = mlx_xpm_file_to_image(g_mlx_ptr, g_texture[3],
		&g_texture_width4, &g_texture_height4);
	g_texture4 = (int *)mlx_get_data_addr(g_texture4_id, &add, &add, &add);
	g_textures_id = mlx_xpm_file_to_image(g_mlx_ptr, g_texture[0],
		&g_texture_widths, &g_texture_heights);
	g_textures = (int *)mlx_get_data_addr(g_textures_id, &add, &add, &add);
}

int			update_matrix_width(char *line)
{
	if (ft_strlen(line) >= g_widthmap)
		g_widthmap = ft_strlen(line);
	return (1);
}

int			get_textures(int i, int k, char c, char b)
{
	int j;

	if (g_rf.line[i] != '\0' && g_rf.line[i] == c && g_rf.line[i + 1] == b)
	{
		if (g_texture[k] != NULL)
			return (0);
		if (g_rf.line[i + 2] != ' ')
			return (0);
		j = i + 2;
		while (g_rf.line[j] != '\0' && g_rf.line[j] == ' ')
			j++;
		g_texture[k] = ft_strdup(g_rf.line + j);
	}
	i++;
	g_rf.i++;
	return (1);
}

int			getmapliine(char *line, int i)
{
	if (line[i] == 'E' || line[i] == 'W' ||
		line[i] == 'N' || line[i] == 'S')
		if (line[i + 1] == '1' || line[i + 1] == '0' || line[i + 1] == '2')
			g_maplinefound = update_matrix_width(line);
	return (0);
}

void		getmapline1(void)
{
	if (g_maplinefound == 1)
		g_heightmap++;
}

int			getmapline(void)
{
	int		fd;
	char	*line;
	int		mapline;
	int		i;

	fd = open("file.cub", O_RDONLY);
	mapline = 0;
	g_maplinefound = 0;
	while (get_next_line(fd, &line) != 0)
	{
		i = 0;
		while (line[i] != '\0' && line[i] == ' ')
			i++;
		if (g_maplinefound == 0)
			mapline++;
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
			g_maplinefound = update_matrix_width(line);
		getmapliine(line, i);
		getmapline1();
		free(line);
	}
	free(line);
	g_heightmap++;
	close(fd);
	return (mapline);
}
