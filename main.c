/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: majdahim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:19:10 by majdahim          #+#    #+#             */
/*   Updated: 2021/01/18 19:49:51 by majdahim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void				value(void)
{
	g_window_height = -1;
	g_window_width = -1;
	g_floorcolor = -1;
	g_skycolor = -1;
	g_playerx = -1;
}

const int			g_bytes_per_pixel = 3;
const int			g_file_header_size = 14;
const int			g_info_header_size = 40;

int					savebitmap(int width, int height, int *pixels)
{
	int				i;
	int				j;
	unsigned char	*image;
	char			*imagefilename;

	i = 0;
	image = (unsigned char *)malloc(height * width * 3 * sizeof(unsigned char));
	imagefilename = (char*)"bitmapImage.bmp";
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			*(image + i * width * 3 + j * 3 + (2)) = (unsigned char)
				floor(pixels[i * width + j] / (256 * 256));
			*(image + i * width * 3 + j * 3 + (1)) = (unsigned char)
				floor(pixels[i * width + j] / 256) % 256;
			*(image + i * width * 3 + j * 3 + (0)) = (unsigned char)
				(pixels[i * width + j] % 256);
			j++;
		}
		i++;
	}
	generate_bitmap_image((unsigned char*)image, height, width, imagefilename);
	return (1);
}

void				generate_bitmap_image(unsigned char *image, int height
		, int width, char *imagefilename)
{
	int				a[4];
	unsigned char	padding[3];
	FILE			*imagefile;
	unsigned char	*fileheader;
	unsigned char	*infoheader;

	padding[0] = 0;
	padding[1] = 0;
	padding[2] = 0;
	a[0] = height - 1;
	a[1] = width * g_bytes_per_pixel;
	a[2] = (4 - (a[1]) % 4) % 4;
	a[3] = (a[1]) + a[2];
	imagefile = fopen(imagefilename, "wb");
	fileheader = create_bitmap_file_header(height, a[3]);
	infoheader = create_bitmap_info_header(height, width);
	fwrite(fileheader, 1, g_file_header_size, imagefile);
	fwrite(infoheader, 1, g_info_header_size, imagefile);
	while (a[0] >= 0)
	{
		fwrite(image + (a[0] * a[1]), g_bytes_per_pixel, width, imagefile);
		fwrite(padding, 1, a[2], imagefile);
		a[0]--;
	}
	fclose(imagefile);
}

unsigned char		*create_bitmap_file_header(int height, int stride)
{
	int						filesize;
	static unsigned char	fileheader[11];

	filesize = g_file_header_size + g_info_header_size + (stride * height);
	fileheader[0] = (unsigned char)('B');
	fileheader[1] = (unsigned char)('M');
	fileheader[2] = (unsigned char)(filesize);
	fileheader[3] = (unsigned char)(filesize >> 8);
	fileheader[4] = (unsigned char)(filesize >> 16);
	fileheader[5] = (unsigned char)(filesize >> 24);
	fileheader[6] = 0;
	fileheader[7] = 0;
	fileheader[8] = 0;
	fileheader[9] = 0;
	fileheader[10] = (unsigned char)(g_file_header_size + g_info_header_size);
	return (fileheader);
}

unsigned char		*create_bitmap_info_header(int height, int width)
{
	static unsigned char infoheader[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	infoheader[0] = (unsigned char)(g_info_header_size);
	infoheader[4] = (unsigned char)(width);
	infoheader[5] = (unsigned char)(width >> 8);
	infoheader[6] = (unsigned char)(width >> 16);
	infoheader[7] = (unsigned char)(width >> 24);
	infoheader[8] = (unsigned char)(height);
	infoheader[9] = (unsigned char)(height >> 8);
	infoheader[10] = (unsigned char)(height >> 16);
	infoheader[11] = (unsigned char)(height >> 24);
	infoheader[12] = (unsigned char)(1);
	infoheader[14] = (unsigned char)(g_bytes_per_pixel * 8);
	return (infoheader);
}

int					clickdetecter(void *key)
{
	mlx_destroy_window(g_mlx_ptr, g_win_ptr);
	exit(0);
}

int					main(int argc, char **argv)
{
	int add;

	add = 0;
	value();
	if (!intigame(argc, argv))
		return (0);
	g_mlx_ptr = mlx_init();
	initialize_textures(add);
	g_win_ptr = mlx_new_window(g_mlx_ptr,
			g_window_width, g_window_height, "Cub3d");
	g_new_img = mlx_new_image(g_mlx_ptr, g_window_width, g_window_height);
	g_pixels = (int *)mlx_get_data_addr(g_new_img, &add, &add, &add);
	rays();
	mlx_hook(g_win_ptr, 2, (1L << 1), deal_key, (void *)0);
	mlx_hook(g_win_ptr, 17, 0, clickdetecter, (void *)0);
	if (argc == 3 && ft_strncmp(argv[2], "--save", 5))
		return (savebitmap(g_window_width, g_window_height, g_pixels));
	mlx_put_image_to_window(g_mlx_ptr, g_win_ptr, g_new_img, 0, 0);
	mlx_loop(g_mlx_ptr);
}
