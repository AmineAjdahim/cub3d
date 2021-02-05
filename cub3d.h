/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 16:46:21 by majdahim          #+#    #+#             */
/*   Updated: 2021/01/07 16:46:36 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"


typedef struct	s_coll{
	double	k;
	int		i1;
	int		j1;
	int		i13;
	int		j13;
	int		i0;
	int		j0;
	int		i2;
	int		j2;
}				t_coll;

typedef struct	s_checkmap
{
	int		i;
	int		j;
}				t_checkmap;

typedef struct	s_draw_wall
{
	int		xt;
	int		start;
	int		end;
	float	wall_y;
	float	wall_x;
}				t_draw_wall;

typedef struct	s_fill_map
{
	int		a;
	int		b;
}				t_fill_map;

typedef struct	s_alpha
{
	double		b;
	double		b1;
	double		a;
	double		a1;
}				t_alpha_p;

typedef struct	s_draw_map
{
	int		i;
	int		j;
	int		lnx;
	int		lny;
}				t_draw_mapp;

typedef struct	s_rays
{
	double		lh;
	double		lv;
	double		l;
	double		gama;
	double		addition;
	int			n;
	double		slice_size;
	int			*texture;
	int			texture_width;
	int			texture_height;
}				t_rays;

typedef struct	s_intersection
{
	double		l;
	int			i;
	int			j;
	double		xi;
	double		yi;
	double		ls;

}				t_intersection;

typedef struct	s_readfile
{
	char	*line;
	int		i;
}				t_readfile;

typedef struct	s_heroz
{
	double		ax;
	double		ay;
	double		up;
	int			found;
	int			i;
	int			j;
	double		a;
	double		b;
}				t_heroz;

typedef struct	s_vertical
{
	double		bx;
	double		by;
	double		right;
	int			found;
	double		a;
	double		b;
	int			i;
	int			j;
}				t_vertical;

typedef struct	s_sprite
{
	int			x;
	int			y;
	int			width;
	int			height;
	double		size;
	double		angle;
	double		it_x;
	double		it_y;
	double		distance;
}				t_sprite;

t_sprite		g_sprite[INT32_MAX];

int				g_nbr_sprite;
int				g_fov;
double			g_int_col[INT32_MAX];
long	g_skycolor;
long	g_floorcolor;
char	*g_texture[5];
char	**g_map;
int		g_maplinefound;
int		g_heightmap;
int		g_widthmap;
int		*g_pixels;
int		*g_texture1;
int		*g_texture2;
int		*g_texture3;
int		*g_texture4;
int		*g_textures;
int		g_texture_width1;
int		g_texture_width2;
int		g_texture_width3;
int		g_texture_width4;
int		g_texture_widths;
int		g_texture_height1;
int		g_texture_height2;
int		g_texture_height3;
int		g_texture_height4;
int		g_texture_heights;

void	*g_texture1_id;
void	*g_texture2_id;
void	*g_texture3_id;
void	*g_texture4_id;
void	*g_textures_id;

void	*g_mlx_ptr;
void	*g_win_ptr;
void	*g_new_img;
int		g_window_width;
int		g_window_height;
float	g_r;

double	g_playerx;
double	g_playery;
double	g_alpha;
double	g_wall;
char	*g_path;
t_coll			g_coll;
t_alpha_p		g_alphap;
t_intersection	g_store;
t_intersection	g_store2;
t_draw_mapp		g_drawi;
t_rays			g_rayss;
t_checkmap		g_mp;
t_fill_map		g_f;
t_draw_wall		g_drw;
t_readfile		g_rf;
t_intersection	g_intersection;
t_heroz			g_h;
t_vertical		g_v;

void			calcul_sprite(void);
int				mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);
void			draw(int x, int y, int color);
void			draw_map(void);
void			square(int x, int y, int a, int b);
void			sq(int x, int y, int size, int color);
int				checksurround(char **mapp, int i, int j, char c);
int				readfile(char *path);
int				intigame(int argc, char **argv);
int				get_textures(char *line, int i, int k, char *c);
unsigned	int	color_rgb(unsigned int r, unsigned int g, unsigned int b);
int				floorsky(char *line, int i, long *color, char c);
int				comma(char *s, char c);
void			*ft_set(void *b, int c, size_t len);
void			allocmap(void);
void			fill_map(char *line, int l, int mapline, int *error);
int				read_map(int mapline);
void			draw(int x, int y, int color);
void			sq(int x, int y, int size, int color);
void			draw_map(void);
int				playercount(void);
int				oneclosed_h(int i, int j);
int				oneclosed_v(int j, int i);
int				checksurround(char **mapp, int i, int j, char c);
int				checkmap(void);
t_intersection	heroz(double alphaa);
t_intersection	vertical(double alphaa);
void			initialize_textures(int add);
int				update_matrix_width(char *line);
int				getmapline(void);
void			rect(float l, int px);
void			rect_draw(int rect_height, int x, int y, int color);
void			draw_heavens(void);
void			draw_wall(float l, int px, int ix, int s);
int				varset(void);
int				return_print(char *s);
int				intigame(int argc, char **argv);
int				resolution(char *line, int i);
int				readfile2(char *line, int i);
t_intersection	heroz2(double alphaa);
t_intersection	vertical2(double alphaa);
void			textures_wh(void);
int				deal_key(int key);
void			rays(void);
static int		ft_isspace(char c);
int				savebitmap(int width, int height, int *pixels);
void			generate_bitmap_image(unsigned char *image, int height
		, int width, char *imagefilename);
unsigned char	*create_bitmap_file_header(int height, int stride);
unsigned char	*create_bitmap_info_header(int height, int width);
#endif
