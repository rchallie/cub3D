/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:46:37 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 19:53:49 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	pixel_put_cinq(
	int x,
	int y,
	int color,
	t_window win_infos)
{
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x, y, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+1, y, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+2, y, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+3, y, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+4, y, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+5, y, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x, y+1, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+1, y+1, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+2, y+1, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+3, y+1, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+4, y+1, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+5, y+1, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x, y+2, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+1, y+2, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+2, y+2, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+3, y+2, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+4, y+2, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+5, y+2, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x, y+3, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+1, y+3, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+2, y+3, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+3, y+3, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+4, y+3, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+5, y+3, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x, y+4, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+1, y+4, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+2, y+4, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+3, y+4, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+4, y+4, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+5, y+4, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x, y+5, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+1, y+5, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+2, y+5, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+3, y+5, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+4, y+5, color);
	mlx_pixel_put(win_infos.mlx_ptr, win_infos.win_ptr, x+5, y+5, color);

}