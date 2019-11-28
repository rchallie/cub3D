/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:24:10 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 20:08:34 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void 	draw()
{

}

int		loop_manager(
	void *param)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	mlx_clear_window(win_infos->mlx_ptr, win_infos->win_ptr);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 120, 0xffffff,
	"Leave Game : ESC");
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 140, 0xffffff,
	ft_strjoin("Map name : ", win_infos->map_name));
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 160, 0xffffff,
	ft_strjoin("Width : ", ft_itoa(win_infos->width)));
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 180, 0xffffff,
	ft_strjoin("Height : ", ft_itoa(win_infos->height)));
	
	draw_minimap(*win_infos);
	return (0);
}
