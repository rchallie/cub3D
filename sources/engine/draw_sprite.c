/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:15:45 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/13 13:41:23 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void			calcul_values(
	t_draw_sprite *ds,
	t_window *win_infos
)
{
	ds->inv_det = 1.0 / (win_infos->player->plane_x * win_infos->player->dir_y
		- win_infos->player->dir_x * win_infos->player->plane_y);
	ds->transform_x = ds->inv_det * (win_infos->player->dir_y * ds->sprite_x
		- win_infos->player->dir_x * ds->sprite_y);
	ds->transform_y = ds->inv_det * (-win_infos->player->plane_y * ds->sprite_x
		+ win_infos->player->plane_x * ds->sprite_y);
	ds->sprite_screen_x = (int)((win_infos->width / 2) * (1 + ds->transform_x
		/ ds->transform_y));
	ds->sprite_height = abs((int)(win_infos->height / ds->transform_y));
	ds->draw_start_y = -ds->sprite_height / 2 + ((win_infos->height / 2)
		* win_infos->player->cam_height);
	if (ds->draw_start_y < 0)
		ds->draw_start_y = 0;
	ds->draw_end_y = ds->sprite_height / 2 + ((win_infos->height / 2)
		* win_infos->player->cam_height);
	if (ds->draw_end_y >= win_infos->height)
		ds->draw_end_y = win_infos->height - 1;
	ds->sprite_width = abs((int)(win_infos->height / ds->transform_y));
	ds->draw_start_x = -ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_start_x < 0)
		ds->draw_start_x = 0;
	ds->draw_end_x = ds->sprite_width / 2 + ds->sprite_screen_x;
	if (ds->draw_end_x >= win_infos->width)
		ds->draw_end_x = win_infos->width - 1;
	ds->stripe = ds->draw_start_x;
}

static void			pix_on_sprite_image(
	t_draw_sprite *ds,
	t_window *win_infos
)
{
	ds->d = ds->y * win_infos->sprite->size_line - (win_infos->height
		* win_infos->player->cam_height)
		* (win_infos->sprite->size_line / 2) + ds->sprite_height
		* win_infos->sprite->size_line / 2;
	ds->tex_y = ((ds->d * win_infos->sprite->height) / ds->sprite_height)
		/ win_infos->sprite->size_line;
	ds->totcolor = win_infos->sprite->data[ds->tex_y
		* win_infos->sprite->size_line + ds->tex_x
		* win_infos->sprite->bpp / 8]
		+ win_infos->sprite->data[ds->tex_y
		* win_infos->sprite->size_line + ds->tex_x
		* win_infos->sprite->bpp / 8 + 1]
		+ win_infos->sprite->data[ds->tex_y
		* win_infos->sprite->size_line + ds->tex_x
		* win_infos->sprite->bpp / 8 + 2];
}

static void			is_black(
	t_draw_sprite *ds,
	t_window *win_infos
)
{
	win_infos->img->data[ds->y * win_infos->img->size_line
		+ ds->stripe * win_infos->img->bpp / 8] =
		win_infos->sprite->data[ds->tex_y
		* win_infos->sprite->size_line + ds->tex_x
		* win_infos->sprite->bpp / 8];
	win_infos->img->data[ds->y * win_infos->img->size_line
		+ ds->stripe * win_infos->img->bpp / 8 + 1] =
		win_infos->sprite->data[ds->tex_y
		* win_infos->sprite->size_line + ds->tex_x
		* win_infos->sprite->bpp / 8 + 1];
	win_infos->img->data[ds->y * win_infos->img->size_line
		+ ds->stripe * win_infos->img->bpp / 8 + 2] =
		win_infos->sprite->data[ds->tex_y
		* win_infos->sprite->size_line + ds->tex_x
		* win_infos->sprite->bpp / 8 + 2];
}

static void			make_sprite(
	t_draw_sprite *ds,
	t_window *win_infos,
	t_ray *ray
)
{
	ds->sprite_x = ds->sprites[ds->i].x - (win_infos->player->posx - 0.5);
	ds->sprite_y = ds->sprites[ds->i].y - (win_infos->player->posy - 0.5);
	calcul_values(ds, win_infos);
	while (ds->stripe < ds->draw_end_x)
	{
		ds->tex_x = (int)(win_infos->sprite->size_line * (ds->stripe
		- (-ds->sprite_width / 2 + ds->sprite_screen_x))
			* win_infos->sprite->width / ds->sprite_width)
			/ win_infos->sprite->size_line;
		if (ds->transform_y > 0 && ds->stripe > 0 && ds->stripe
			< win_infos->width && ds->transform_y < ray->z_buffer[ds->stripe])
		{
			ds->y = ds->draw_start_y;
			while (ds->y < ds->draw_end_y)
			{
				pix_on_sprite_image(ds, win_infos);
				if (ds->totcolor != 0)
					is_black(ds, win_infos);
				ds->y++;
			}
		}
		ds->stripe++;
	}
}

int					draw_sprite(
	t_ray *ray,
	t_window *win_infos
)
{
	t_draw_sprite *ds;

	if (!(ds = malloc(sizeof(t_draw_sprite))))
		return (ERROR);
	ft_bzero(ds, sizeof(t_draw_sprite));
	ds->i = 0;
	ds->sprites = list_to_tab(win_infos);
	sort_sprite(win_infos, ds->sprites,
		ft_lstsize((t_list *)win_infos->sprites_on_screen));
	while (ds->i < ft_lstsize((t_list *)win_infos->sprites_on_screen))
	{
		make_sprite(ds, win_infos, ray);
		ds->i++;
	}
	free(ds->sprites);
	return (SUCCES);
}
