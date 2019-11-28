/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 10:11:51 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 15:39:06 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		mouse_manager(int button, int x, int y, void *param)
{
	t_window	*mlx_infos;

	mlx_infos = (t_window *)param;
	putstr_info_int("Button : ", button, 1);
	putstr_info_int("X : ", x, 1);
	putstr_info_int("Y : ", y, 1);
	return (0);
}
