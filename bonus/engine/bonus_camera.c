/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 10:46:31 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/13 11:53:16 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_up(t_window *win_infos)
{
	if (win_infos->player->cam_height + win_infos->player->rotate_speed < 2)
		win_infos->player->cam_height += win_infos->player->rotate_speed;
}

void	turn_down(t_window *win_infos)
{
	if (win_infos->player->cam_height - win_infos->player->rotate_speed > 0)
		win_infos->player->cam_height -= win_infos->player->rotate_speed;
}
