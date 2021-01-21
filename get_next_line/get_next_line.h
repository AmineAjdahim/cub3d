/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:50:41 by majdahim          #+#    #+#             */
/*   Updated: 2019/11/20 19:11:16 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#define BUFFER_SIZE 1000

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

int				check_save(char **line, char **save);
int				get_next_line(int fd, char **line);
unsigned	int ft_strlensave(char *save);
int				freeptr(char **ptr, int r);
int	readfile(char *path);
int	read_map(int mapline);
int	getmapline(void);




#endif
