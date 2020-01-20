/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_health.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 14:28:42 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 10:04:50 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void		add_health(
	t_window *win_infos,
	int amount
)
{
	if (win_infos->player->health + amount > 20)
		win_infos->player->health = 20;
	else
		win_infos->player->health += amount;
}

void		remove_health(
	t_window *win_infos,
	int amount
)
{
	if (win_infos->player->health - amount <= 0)
		leave(0, win_infos, "Game over!");
	else
		win_infos->player->health -= amount;
}

static void	health_img(
	t_window *win_infos
)
{
	t_image	*img;
	double	img_width;
	int		x;
	int		y;

	img_width = (int)(((double)191 / (double)20)
		* (double)win_infos->player->health);
	if (!(img = new_image(win_infos, (int)img_width, 30)))
		leave(1, win_infos, "Error init image map");
	img->width = (int)img_width;
	img->height = 30;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel_put_to_image(0x00FF00, x, y, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win_infos->mlx_ptr, win_infos->win_ptr,
		img->img_ptr, 85, 520);
}

void		draw_health(
	t_window *win_infos
)
{
	health_img(win_infos);
	mlx_put_image_to_window(win_infos->mlx_ptr, win_infos->win_ptr,
		win_infos->textures[4]->img_ptr, 40, 500);
}
