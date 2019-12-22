/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 11:22:42 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/16 14:17:20 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_window *win_infos)
{
	double olddirx;
	double oldplanex;

	olddirx = win_infos->player->dirX;
	oldplanex = win_infos->player->planeX;
	win_infos->player->dirX = win_infos->player->dirX
			* cos(-win_infos->player->rotate_speed) - win_infos->player->dirY
			* sin(-win_infos->player->rotate_speed);
	win_infos->player->dirY = olddirx * sin(-win_infos->player->rotate_speed)
			+ win_infos->player->dirY * cos(-win_infos->player->rotate_speed);
	win_infos->player->planeX = win_infos->player->planeX
			* cos(-win_infos->player->rotate_speed) - win_infos->player->planeY
			* sin(-win_infos->player->rotate_speed);
	win_infos->player->planeY = oldplanex
			* sin(-win_infos->player->rotate_speed) + win_infos->player->planeY
			* cos(-win_infos->player->rotate_speed);
}

void	turn_right(t_window *win_infos)
{
	double olddirx;
	double oldplanex;

	olddirx = win_infos->player->dirX;
	oldplanex = win_infos->player->planeX;
	win_infos->player->dirX = win_infos->player->dirX
			* cos(win_infos->player->rotate_speed) - win_infos->player->dirY
			* sin(win_infos->player->rotate_speed);
	win_infos->player->dirY = olddirx * sin(win_infos->player->rotate_speed)
			+ win_infos->player->dirY * cos(win_infos->player->rotate_speed);
	win_infos->player->planeX = win_infos->player->planeX
			* cos(win_infos->player->rotate_speed) - win_infos->player->planeY
			* sin(win_infos->player->rotate_speed);
	win_infos->player->planeY = oldplanex
			* sin(win_infos->player->rotate_speed) + win_infos->player->planeY
			* cos(win_infos->player->rotate_speed);
}

void	move_forward(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx + win_infos->player->dirX
		* win_infos->player->speed)] == '0')
		win_infos->player->posx += win_infos->player->dirX
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		+ win_infos->player->dirY * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy += win_infos->player->dirY
		* win_infos->player->speed;
}

void	move_backward(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx - win_infos->player->dirX
		* win_infos->player->speed)] == '0')
		win_infos->player->posx -= win_infos->player->dirX
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		- win_infos->player->dirY * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy -= win_infos->player->dirY
		* win_infos->player->speed;
}

void	move_left(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx - win_infos->player->planeX
		* win_infos->player->speed)] == '0')
		win_infos->player->posx -= win_infos->player->planeX
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		- win_infos->player->planeY * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy -= win_infos->player->planeY
		* win_infos->player->speed;
}

void	move_right(t_window *win_infos)
{
	if (win_infos->map->map[(int)win_infos->player->posy]
		[(int)(win_infos->player->posx + win_infos->player->planeX
		* win_infos->player->speed)] == '0')
		win_infos->player->posx += win_infos->player->planeX
		* win_infos->player->speed;
	if (win_infos->map->map[(int)(win_infos->player->posy
		+ win_infos->player->planeY * win_infos->player->speed)]
		[(int)win_infos->player->posx] == '0')
		win_infos->player->posy += win_infos->player->planeY
		* win_infos->player->speed;
}