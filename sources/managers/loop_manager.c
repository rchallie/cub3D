/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 11:24:10 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 16:38:42 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		compass(t_window	*win_infos)
{
	//printf("X : %f\n", win_infos->player->dirX);
	if (win_infos->player->dirX >= -0.25f && win_infos->player->dirX <= 0.25f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : East");
	else if (win_infos->player->dirX > -1.25f && win_infos->player->dirX < -0.25f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : North-East");
	else if (win_infos->player->dirX > -1.75f && win_infos->player->dirX < -1.25f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : North");
	else if (win_infos->player->dirX > -2.75f && win_infos->player->dirX < -1.75f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : North-West");
	else if (win_infos->player->dirX > -3.25f && win_infos->player->dirX < -2.75f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : West");
	else if (win_infos->player->dirX > -4.75f && win_infos->player->dirX < -3.25f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : South-West");
	else if (win_infos->player->dirX > -5.25f && win_infos->player->dirX < -4.75f)
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : South");
	else if (win_infos->player->dirX < -5.25f )
		mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25, 200, 0xffffff,
		"Axe : South-Est");
}

// static void		raycastin

static void 	draw(
	t_window *win_infos)
{
	raycasting(win_infos);
	// draw_minimap(win_infos); //a faire en image
}

int		loop_manager(
	void *param)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	mlx_clear_window(win_infos->mlx_ptr, win_infos->win_ptr);
	draw(win_infos);
	key_manager(win_infos);

	ft_bzero(win_infos->img->data, win_infos->img->width * win_infos->img->height * (win_infos->img->bpp/8));
	
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
