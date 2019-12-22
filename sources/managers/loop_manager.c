/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:24:10 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 12:59:12 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		hud(
	t_window *win_infos
)
{
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 120, 0xffffff,
	"Leave Game : ESC");
	
	char *name = ft_strjoin("Map name test: ", win_infos->map->map_name);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 140, 0xffffff,
	name);
	free(name);
	
	char *width_itoa = ft_itoa(win_infos->width);
	char *width = ft_strjoin("Width : ", width_itoa);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 160, 0xffffff,
	width);
	free(width_itoa);
	free(width);
	
	char *height_itoa = ft_itoa(win_infos->height);
	char *height = ft_strjoin("Height : ", height_itoa);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 180, 0xffffff,
	height);
	free(height_itoa);
	free(height);
	return (0);
}

static void		clear(
	t_window *win_infos
)
{
	// Checker si ft_bzero est enlevable (GAIN MONUMENTAL DE FPS)
	//ft_bzero(win_infos->img->data, win_infos->img->width *
	//	win_infos->img->height * sizeof(int));
	//mlx_clear_window(win_infos->mlx_ptr, win_infos->win_ptr);
}

static void 	draw(
	t_window *win_infos)
{
	raycasting(win_infos);
	hud(win_infos);
	//draw_minimap(win_infos); //a faire en image
}

int		loop_manager(
	void *param)
{
	t_window *win_infos;
	win_infos = (t_window *)param;

	clear(win_infos);
	draw(win_infos);
	key_manager(win_infos);
}
