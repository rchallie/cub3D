/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 11:34:02 by rchallie          #+#    #+#             */
/*   Updated: 2020/02/17 10:15:53 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		perp_and_height(
	t_ray *ray,
	t_player *player,
	t_window *win_infos
)
{
	if (ray->side == 0 || ray->side == 1)
		ray->perp_wall_dist = (ray->mapx - player->posx + (1 - ray->step_x) / 2)
		/ ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->mapy - player->posy + (1 - ray->step_y) / 2)
		/ ray->ray_dir_y;
	ray->line_height = (int)(win_infos->height / ray->perp_wall_dist);
	ray->draw_start = (-ray->line_height / 2 + ((win_infos->height / 2)
		* win_infos->player->cam_height));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2 + ((win_infos->height / 2)
		* win_infos->player->cam_height));
	if (ray->draw_end >= win_infos->height)
		ray->draw_end = win_infos->height - 1;
}

static void	predict_wall_face(
	t_ray *ray
)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_dist_x;
		ray->mapx += ray->step_x;
		if (ray->step_x == 1)
			ray->side = 0;
		else if (ray->step_x == -1)
			ray->side = 1;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->mapy += ray->step_y;
		if (ray->step_y == 1)
			ray->side = 2;
		else if (ray->step_y == -1)
			ray->side = 3;
	}
}

void		hit(
	t_ray *ray,
	t_window *win_infos
)
{
	while (ray->hit == 0)
	{
		predict_wall_face(ray);
		if (win_infos->map->map[ray->mapy][ray->mapx] > '0'
			&& win_infos->map->map[ray->mapy][ray->mapx] != '2')
			ray->hit = 1;
		else if (win_infos->map->map[ray->mapy][ray->mapx] == '2')
			is_sprite(ray, win_infos);
	}
}
