/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 16:13:08 by majdahim          #+#    #+#             */
/*   Updated: 2021/01/19 09:47:39 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned	int		color_rgb(unsigned int r, unsigned int g, unsigned int b)
{
	return ((r * 256 * 256) + (g * 256) + b);
}

int					count(char *s, char c)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			counter++;
		i++;
	}
	return (counter);
}

int					is_all_space(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int					is_digit(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]) && s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int					free_and_return(char **data, int a)
{
	free(data[0]);
	free(data[1]);
	free(data[2]);
	free(data);
	return (a);
}

int					check_rgb(char **data)
{
	if (ft_atoi(data[0]) >= 256)
		return (0);
	return (0);
}

int					check_color(long *color)
{
	if (*color != -1)
		return (0);
	return (1);
}

int					floorsky(char *line, int i, long *color, char c)
{
	int		j;
	char	**data;

	if (line[i] != '\0' && line[i] == c && line[i + 1] == ' ')
	{
		check_color(color);
		j = i + 2;
		if (count(line + j, ',') != 2)
			return (0);
		data = ft_split(line + j, ',');
		if (!is_digit(data[0]) || !is_digit(data[1]) || !is_digit(data[2]))
			return (free_and_return(data, 0));
		if (is_all_space(data[0]) || is_all_space(data[1]) ||
			is_all_space(data[2]))
			return (free_and_return(data, 0));
		if (ft_atoi(data[0]) >= 256 || ft_atoi(data[1]) >= 256 ||
			ft_atoi(data[1]) >= 256)
			return (0);
		*color = color_rgb(ft_atoi(data[0]),
			ft_atoi(data[1]), ft_atoi(data[2]));
		free_and_return(data, 0);
	}
	i++;
	g_rf.i++;
	return (1);
}

int					num_of_params(char *line)
{
	int i;
	int params;

	i = 1;
	params = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != ' ' && line[i - 1] == ' ')
			params++;
		i++;
	}
	return (params);
}

int					free_resolution(char **tw, char **data)
{
	free(tw[2]);
	free(tw[3]);
	free(tw[0]);
	free(tw[1]);
	free(data);
	free(data[0]);
	return (0);
}

int					resolution(char *line, int i, char resolution)
{
	char	**data;
	char	*tw[4];

	if (line[i] != '\0' && line[i] == 'R' && line[i + 1] == ' ' &&
		num_of_params(line + i) == 2)
	{
		if (g_window_width != -1 || g_window_height != -1)
			return (0);
		data = ft_split(line + i, ' ');
		if (!is_digit(data[1]) || !is_digit(data[2]))
			return (0);
		tw[0] = data[1];
		tw[1] = data[2];
		g_window_width = ft_atoi(tw[0]);
		g_window_height = ft_atoi(tw[1]);
		tw[2] = ft_itoa(g_window_width);
		tw[3] = ft_itoa(g_window_height);
		if (ft_strncmp(tw[2], tw[0], ft_strlen(tw[0])) != 1)
			g_window_width = 2560;
		if (ft_strncmp(tw[3], data[2], ft_strlen(tw[1])) != 1)
			g_window_height = 1440;
		free_resolution(tw, data);
	}
	g_rf.i++;
	return (1);
}

int					readfile(char *path)
{
	int		i;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line) != 0)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		readfile2(line, i);
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}
