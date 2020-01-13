/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:24:10 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/11 16:31:07 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		hud(
	t_window *win_infos
)
{
	char *str;
	char *width_itoa;
	char *height_itoa;

	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 100, 0xffffff,
	"Forwars : W , Backward : S , Left : A, Right : D");
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 120, 0xffffff,
	"Leave Game : ESC");
	str = ft_strjoin("Map name test: ", win_infos->map->map_name);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 140, 0xffffff,
	str);
	free(str);
	width_itoa = ft_itoa(win_infos->width);
	str = ft_strjoin("Width : ", width_itoa);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 160, 0xffffff,
	str);
	free(width_itoa);
	free(str);
	height_itoa = ft_itoa(win_infos->height);
	str = ft_strjoin("Height : ", height_itoa);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 180, 0xffffff,
	str);
	free(str);
	return ;
}

static void		draw(
	t_window *win_infos
)
{
	if (!(raycasting(win_infos)))
		leave(0, win_infos, "");
	hud(win_infos);
}

int				loop_manager(
	void *param
)
{
	t_window *win_infos;

	win_infos = (t_window *)param;
	draw(win_infos);
	key_manager(win_infos);
	return (0);
}
