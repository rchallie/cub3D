/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 11:12:36 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 10:04:20 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		pixel_put_to_image(
	int color,
	int x,
	int y,
	t_image *img
)
{
	unsigned char *src;
	unsigned char r;
	unsigned char g;
	unsigned char b;

	src = (unsigned char *)&color;
	r = src[0];
	g = src[1];
	b = src[2];
	img->data[y * img->size_line + x * img->bpp / 8] = r;
	img->data[y * img->size_line + x * img->bpp / 8 + 1] = g;
	img->data[y * img->size_line + x * img->bpp / 8 + 2] = b;
}

void		ver_line_color_image(
	t_line *line,
	t_window *win_infos,
	int color
)
{
	int y;
	int y_max;

	if (line->y0 < line->y1)
	{
		y = line->y0;
		y_max = line->y1;
	}
	else
	{
		y = line->y1;
		y_max = line->y0;
	}
	if (y >= 0)
	{
		while (y < y_max)
		{
			pixel_put_to_image(color, line->x, y, win_infos->img);
			y++;
		}
	}
}

static void	texture_on_img(
	t_line *line,
	t_image *texture,
	t_window *win_infos,
	t_ray *ray
)
{
	int d;

	d = line->y * texture->size_line - (win_infos->height
		* win_infos->player->cam_height) * texture->size_line
		/ 2 + ray->line_height * texture->size_line / 2;
	line->tex_y = ((d * texture->height) / ray->line_height)
		/ texture->size_line;
	win_infos->img->data[line->y * win_infos->img->size_line + line->x
					* win_infos->img->bpp / 8] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)];
	win_infos->img->data[line->y * win_infos->img->size_line + line->x
					* win_infos->img->bpp / 8 + 1] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 1];
	win_infos->img->data[line->y * win_infos->img->size_line + line->x
					* win_infos->img->bpp / 8 + 2] = texture->data[line->tex_y
					* texture->size_line + line->tex_x * (texture->bpp / 8)
					+ 2];
}

void		ver_line_texture_image(
	t_line *line,
	t_window *win_infos,
	t_image *texture,
	t_ray *ray
)
{
	int y_max;

	if (line->y0 < line->y1)
	{
		line->y = line->y0;
		y_max = line->y1;
	}
	else
	{
		line->y = line->y1;
		y_max = line->y0;
	}
	if (line->y >= 0)
	{
		while (line->y < y_max)
		{
			texture_on_img(line, texture, win_infos, ray);
			line->y++;
		}
	}
}

t_image		*new_image(
	t_window *win_infos,
	int x_len,
	int y_len)
{
	t_image *img;

	if (!(img = malloc(sizeof(t_image))))
		return (void *)0;
	ft_bzero(img, sizeof(t_image));
	if (!(img->img_ptr = mlx_new_image(win_infos->mlx_ptr, x_len, y_len)))
		return (void *)0;
	img->data = mlx_get_data_addr(img->img_ptr, &img->bpp,
				&img->size_line, &img->endian);
	img->width = x_len;
	img->height = y_len;
	return (img);
}
