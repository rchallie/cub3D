/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:12:36 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 12:18:55 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


void		pixel_put_to_image(
	int color,
	int x,
	int y,
	t_window *win_infos)
{

    unsigned char *src = (unsigned char *) &color;
    unsigned char r;
    unsigned char g;
    unsigned char b;
    r = src[0];
    g = src[1];
    b = src[2];
	win_infos->img->data[y * win_infos->img->size_line + x
							* win_infos->img->bpp / 8] = r;
	win_infos->img->data[y * win_infos->img->size_line + x
							* win_infos->img->bpp / 8 + 1] = g;
	win_infos->img->data[y * win_infos->img->size_line + x
							* win_infos->img->bpp / 8 + 2] = b;
}

void verLine_color_image(int x, int y0, int y1, t_window *win_infos, int color)
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

void verLine_texture_image(int x, int y0, int y1, t_window *win_infos, t_image *texture, t_ray *ray, int texX)
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
		//printf("%d\n", texture->bpp / 8);
		int d = y * texture->size_line - win_infos->height * texture->size_line / 2 + ray->lineHeight * texture->size_line / 2;
		int texY = ((d * texture->height) / ray->lineHeight) / texture->size_line;
		//pixel_put_to_image(color, x, y, win_infos);
		win_infos->img->data[y * win_infos->img->size_line + x
						* win_infos->img->bpp / 8] = texture->data[texY * texture->size_line + texX * texture->bpp / 8];
		win_infos->img->data[y * win_infos->img->size_line + x
						* win_infos->img->bpp / 8 + 1] = texture->data[texY * texture->size_line + texX * texture->bpp / 8 + 1];
		win_infos->img->data[y * win_infos->img->size_line + x
						* win_infos->img->bpp / 8 + 2] = texture->data[texY * texture->size_line + texX * texture->bpp / 8 + 2];
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
		return ;
	ft_bzero(img, sizeof(t_image));
	if (!(img->img_ptr = mlx_new_image(win_infos->mlx_ptr, x_len, y_len)))
		return ;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
				&img->size_line, &img->endian);
	img->width = x_len;
	img->height = y_len;
	return (img);
}
