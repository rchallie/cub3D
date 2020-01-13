/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:22:42 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/08 14:01:22 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_forward(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx + win_infos->player->dir_x
		* win_infos->player->speed)] == '0')
		win_infos->player->posx += win_infos->player->dir_x
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		+ win_infos->player->dir_y * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy += win_infos->player->dir_y
		* win_infos->player->speed;
}

void	move_backward(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx - win_infos->player->dir_x
		* win_infos->player->speed)] == '0')
		win_infos->player->posx -= win_infos->player->dir_x
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		- win_infos->player->dir_y * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy -= win_infos->player->dir_y
		* win_infos->player->speed;
}

void	move_left(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx - win_infos->player->plane_x
		* win_infos->player->speed)] == '0')
		win_infos->player->posx -= win_infos->player->plane_x
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		- win_infos->player->plane_y * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy -= win_infos->player->plane_y
		* win_infos->player->speed;
}

void	move_right(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx + win_infos->player->plane_x
		* win_infos->player->speed)] == '0')
		win_infos->player->posx += win_infos->player->plane_x
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		+ win_infos->player->plane_y * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy += win_infos->player->plane_y
		* win_infos->player->speed;
}
