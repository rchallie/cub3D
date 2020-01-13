/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:59:11 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/09 12:55:27 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_left(t_window *win_infos)
{
	double olddirx;
	double oldplanex;

	olddirx = win_infos->player->dir_x;
	oldplanex = win_infos->player->plane_x;
	win_infos->player->dir_x = win_infos->player->dir_x
			* cos(-win_infos->player->rotate_speed) - win_infos->player->dir_y
			* sin(-win_infos->player->rotate_speed);
	win_infos->player->dir_y = olddirx * sin(-win_infos->player->rotate_speed)
			+ win_infos->player->dir_y * cos(-win_infos->player->rotate_speed);
	win_infos->player->plane_x = win_infos->player->plane_x
			* cos(-win_infos->player->rotate_speed) - win_infos->player->plane_y
			* sin(-win_infos->player->rotate_speed);
	win_infos->player->plane_y = oldplanex
			* sin(-win_infos->player->rotate_speed) + win_infos->player->plane_y
			* cos(-win_infos->player->rotate_speed);
}

void	turn_right(t_window *win_infos)
{
	double olddirx;
	double oldplanex;

	olddirx = win_infos->player->dir_x;
	oldplanex = win_infos->player->plane_x;
	win_infos->player->dir_x = win_infos->player->dir_x
			* cos(win_infos->player->rotate_speed) - win_infos->player->dir_y
			* sin(win_infos->player->rotate_speed);
	win_infos->player->dir_y = olddirx * sin(win_infos->player->rotate_speed)
			+ win_infos->player->dir_y * cos(win_infos->player->rotate_speed);
	win_infos->player->plane_x = win_infos->player->plane_x
			* cos(win_infos->player->rotate_speed) - win_infos->player->plane_y
			* sin(win_infos->player->rotate_speed);
	win_infos->player->plane_y = oldplanex
			* sin(win_infos->player->rotate_speed) + win_infos->player->plane_y
			* cos(win_infos->player->rotate_speed);
}
