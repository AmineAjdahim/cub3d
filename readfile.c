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
	if(s == NULL)
		return (0);
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
	char	**d;
	int		j;

	if (line[i] != '\0' && line[i] == c && line[i + 1] == ' ')
	{
		if (*color != (unsigned long)-1)
			return (-1);
		j = i + 2;
		if (count(line + j, ',') != 2)
			return (-1);
		d = ft_split(line + j, ',');
		if (!is_digit(d[0]) || !is_digit(d[1]) || !is_digit(d[2]))
			return (free_and_return(d, -1));
		if (is_all_space(d[0]) || is_all_space(d[1])
				|| is_all_space(d[2]))
			return (free_and_return(d, -1));
		if (ft_atoi(d[0]) > 255 || ft_atoi(d[1]) > 255 || ft_atoi(d[2]) > 255
			|| ft_atoi(d[0]) < 0 || ft_atoi(d[1]) < 0 || ft_atoi(d[2]) < 0)
			return (-1);
		*color = color_rgb(ft_atoi(d[0]), ft_atoi(d[1]), ft_atoi(d[2]));
		free_and_return(d, 0);
		return (1);
	}
	return (0);
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
	free(data[0]);
	free(data);
	return (0);
}

void	freearr(char **arr, int i, char **t, char **data)
{
	int	j;

	j = -1;
	if (ft_strncmp(t[2], t[0], ft_strlen(t[0])) != 1)
		g_window_width = 2560;
	else if (g_window_width > 2560)
		g_window_width = 2560;
	if (ft_strncmp(t[3], data[2], ft_strlen(t[1])) != 1)
		g_window_height = 1440;
	else if (g_window_height > 1440)
		g_window_height = 1440;
	while (++j < i)
		free(arr[j]);
}

int	resolution(char *line, int i)
{
	char	**data;
	char	*t[4];

	if (line[i] != '\0' && line[i] == 'R'
			&& line[i + 1] == ' ')
	{
		if(num_of_params(line + i) != 2)
			return (-1);
		data = ft_split(line + i, ' ');
		t[0] = data[1];
		t[1] = data[2];
		free(data[0]);
		if (g_window_width != -1 || g_window_height != -1 ||
				!is_digit(t[0]) || !is_digit(t[1]))
			return (-1);
		g_window_width = ft_atoi(t[0]);
		g_window_height = ft_atoi(t[1]);
		t[2] = ft_itoa(g_window_width);
		t[3] = ft_itoa(g_window_height);
		freearr(t, 4, t, data);
		return (1);
	}
	return (0);
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
		if (!readfile2(line, i))
			return (0);
		free(line);
	}
	free(line);
	close(fd);
	return (1);
}
