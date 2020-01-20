/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:22:42 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 17:09:03 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_start_pos(
	t_window *win_infos,
	char dir,
	int cursor,
	int u
)
{
	if (dir == 'E')
	{
		win_infos->player->dir_y = 0.0;
		set_start_camera(win_infos, 1.0, 0.0, 0.66);
	}
	else if (dir == 'W')
	{
		win_infos->player->dir_y = 0.0;
		set_start_camera(win_infos, -1.0, 0.0, -0.66);
	}
	else if (dir == 'N')
	{
		win_infos->player->dir_y = -1.0;
		set_start_camera(win_infos, 0.0, 0.66, 0.0);
	}
	else if (dir == 'S')
	{
		win_infos->player->dir_y = 1.0;
		set_start_camera(win_infos, 0.0, -0.66, 0.0);
	}
	win_infos->player->posx = (double)(cursor - 1) + 0.5;
	win_infos->player->posy = (double)u + 0.5;
}

void	move_forward(
	t_window *win_infos
)
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

void	move_backward(
	t_window *win_infos
)
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

void	move_left(
	t_window *win_infos
)
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

void	move_right(
	t_window *win_infos
)
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
