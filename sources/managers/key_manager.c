/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:05:43 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 09:18:04 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		key_manager(
	t_window *win_infos
)
{
	double olddirx;
	double oldplanex;

	if (win_infos->keybuffer->toward == 1)
		move_forward(win_infos);
	if (win_infos->keybuffer->backward == 1)
		move_backward(win_infos);
	if (win_infos->keybuffer->left == 1)
		move_left(win_infos);
	if (win_infos->keybuffer->right == 1)
		move_right(win_infos);
	if (win_infos->keybuffer->turn_left == 1)
		turn_left(win_infos);
	if (win_infos->keybuffer->turn_right == 1)
		turn_right(win_infos);
	bonus_key_manager(win_infos);
	return (SUCCES);
}

int		event_key_released(
	int key,
	void *param
)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	if (key == TOWARD && win_infos->keybuffer->toward == 1)
		win_infos->keybuffer->toward = 0;
	else if (key == BACKWARD && win_infos->keybuffer->backward == 1)
		win_infos->keybuffer->backward = 0;
	else if (key == LEFT && win_infos->keybuffer->left == 1)
		win_infos->keybuffer->left = 0;
	else if (key == RIGHT && win_infos->keybuffer->right == 1)
		win_infos->keybuffer->right = 0;
	else if (key == CAM_LEFT && win_infos->keybuffer->turn_left == 1)
		win_infos->keybuffer->turn_left = 0;
	else if (key == CAM_RIGHT && win_infos->keybuffer->turn_right == 1)
		win_infos->keybuffer->turn_right = 0;
	bonus_event_key_released(key, win_infos);
	return (SUCCES);
}

int		event_key_pressed(
	int key,
	void *param
)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	if (key == ESC)
		leave(0, win_infos, "");
	else if (key == TOWARD && win_infos->keybuffer->toward == 0)
		win_infos->keybuffer->toward = 1;
	else if (key == BACKWARD && win_infos->keybuffer->backward == 0)
		win_infos->keybuffer->backward = 1;
	else if (key == LEFT && win_infos->keybuffer->left == 0)
		win_infos->keybuffer->left = 1;
	else if (key == RIGHT && win_infos->keybuffer->right == 0)
		win_infos->keybuffer->right = 1;
	else if (key == CAM_LEFT && win_infos->keybuffer->turn_left == 0)
		win_infos->keybuffer->turn_left = 1;
	else if (key == CAM_RIGHT && win_infos->keybuffer->turn_right == 0)
		win_infos->keybuffer->turn_right = 1;
	bonus_event_key_pressed(key, win_infos);
	return (SUCCES);
}
