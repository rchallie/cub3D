/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:12:36 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 16:43:11 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void		pixel_put_to_image(
	int color,
	int x,
	int y,
	t_window *win_infos)
{
	int				i;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF000) >> 8;
	b = (color & 0xFF);
	win_infos->img->data[y * win_infos->img->size_line + x
							* win_infos->img->bpp / 8] = r;
	win_infos->img->data[y * win_infos->img->size_line + x
							* win_infos->img->bpp / 8 + 1] = g;
	win_infos->img->data[y * win_infos->img->size_line + x
							* win_infos->img->bpp / 8 + 2] = b;
}

void verLine_image(int x, int y0, int y1, t_window *win_infos, int color)
{
	int y;
	int y_max;

	if (y0 < y1)
	{
		y = y0;
		y_max = y1;
	}
	else
	{
		y = y1;
		y_max = y0;
	}
	while (y < y_max)
	{
		pixel_put_to_image(color, x, y, win_infos);
		y++;
	}
}

t_image		*new_image(
	t_window *win_infos,
	int x_len,
	int y_len)
{
	t_image *img;

	if (!(img = malloc(sizeof(t_image))))
		leave_prog_simple("Error\nImg malloc failed\n", 1, *win_infos);
	ft_bzero(img, sizeof(t_image));
	if (!(img->img_ptr = mlx_new_image(win_infos->mlx_ptr, x_len, y_len)))
		leave_prog_simple("Error\nImg mlx new failed\n", 1, *win_infos);
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
				&img->size_line, &img->endian);
	img->width = x_len;
	img->height = y_len;
	return (img);
}
