/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:14:36 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/17 09:29:13 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	data_to_bitmap(
	t_image *mlx_img,
	int fd
)
{
	int i;

	i = mlx_img->width * mlx_img->height - 1;
	while (i >= 0)
	{
		write(fd, &mlx_img->data[i * mlx_img->bpp / 8], 4);
		i--;
	}
	return (SUCCES);
}

static void	mir_verti_pixel(
	t_image *mlx_img,
	int line_cnt,
	int *e,
	int f
)
{
	char	save;
	int		k;

	k = 3;
	while (k >= 0)
	{
		save = mlx_img->data[*e + (line_cnt * mlx_img->size_line)];
		mlx_img->data[*e + (line_cnt * mlx_img->size_line)] =
			mlx_img->data[f - k + (line_cnt * mlx_img->size_line - 1)];
		mlx_img->data[f - k + (line_cnt * mlx_img->size_line - 1)] =
			save;
		k--;
		*e = *e + 1;
	}
}

static int	mir_verti(
	t_image *mlx_img
)
{
	int		line_cnt;
	int		e;
	int		f;

	line_cnt = 0;
	while (line_cnt < mlx_img->height)
	{
		e = 0;
		f = mlx_img->size_line;
		while (e < f && e != f)
		{
			mir_verti_pixel(mlx_img, line_cnt, &e, f);
			f -= 4;
		}
		line_cnt++;
	}
	return (SUCCES);
}

static int	bitmap_info_header(
	t_image *mlx_img,
	int fd
)
{
	int header_info_size;
	int plane_nbr;
	int o_count;

	header_info_size = 40;
	plane_nbr = 1;
	write(fd, &header_info_size, 4);
	write(fd, &mlx_img->width, 4);
	write(fd, &mlx_img->height, 4);
	write(fd, &plane_nbr, 2);
	write(fd, &mlx_img->bpp, 2);
	o_count = 0;
	while (o_count < 28)
	{
		write(fd, "\0", 1);
		o_count++;
	}
	return (SUCCES);
}

int			create_bitmap(
	t_image *mlx_img,
	char *name
)
{
	int fd;
	int file_size;
	int first_pix;

	name = ft_strjoin(name, ".bmp");
	fd = open(name, O_CREAT | O_RDWR);
	file_size = 14 + 40 + 4 + (mlx_img->width * mlx_img->height) * 4;
	first_pix = 14 + 40 + 4;
	write(fd, "BM", 2);
	write(fd, &file_size, 4);
	write(fd, "\0\0\0\0", 4);
	write(fd, &first_pix, 4);
	bitmap_info_header(mlx_img, fd);
	mir_verti(mlx_img);
	data_to_bitmap(mlx_img, fd);
	close(fd);
	free(name);
	return (SUCCES);
}
