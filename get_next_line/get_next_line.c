/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 15:25:44 by majdahim          #+#    #+#             */
/*   Updated: 2019/11/20 17:56:01 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				freeptr(char **ptr, int r)
{
	free(*ptr);
	return (r);
}

char			*ft_strdup(char *src)
{
	char			*temp;
	unsigned long	len;

	len = ft_strlen(src);
	if (!(temp = (char*)malloc(len + 1)))
		return (0);
	memcpy(temp, src, len);
	temp[len] = '\0';
	return (temp);
}

int				check_save(char **line, char **save)
{
	char	*temp;
	char	*ptr;

	if (*save)
	{
		if ((ptr = ft_strchr(*save, '\n')))
		{
			temp = *line;
			*line = ft_substr(*save, 0, (ptr - *save));
			free(temp);
			temp = *save;
			*save = ft_strdup(ptr + 1);
			freeptr(&temp, 1);
			return (1);
		}
		else
		{
			*line = ft_strjoin(*line, *save);
			free(*save);
			*save = NULL;
		}
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *save;
	int			r;
	char		*buff;
	char		*ptr;

	*line = ft_strdup("");
	if (check_save(line, &save))
		return (1);
	if (fd < 0 || !line || (!(buff = malloc(BUFFER_SIZE + 1)) ||
		read(fd, buff, 0)))
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		if ((ptr = ft_strchr(buff, '\n')))
		{
			*ptr = '\0';
			*line = ft_strjoin(*line, buff);
			save = ft_strdup(ptr + 1);
			return (freeptr(&buff, 1));
		}
		*line = ft_strjoin(*line, buff);
	}
	return (freeptr(&buff, 0));
}
