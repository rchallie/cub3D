/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:01:43 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/16 17:51:11 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	colorisation(t_ray *ray, t_window *win_infos) //TEMPORAIRE a remplacer par le fill texture
{
	t_image *img;
	double wallX; //where exactly the wall was hit

	if (ray->side == 0 || ray->side == 1)
		wallX = win_infos->player->posy + ray->perpWallDist * ray->rayDirY;
	else
		wallX = win_infos->player->posx + ray->perpWallDist * ray->rayDirX;
	wallX -= floor(wallX);
	if (win_infos->map->map[ray->mapy][ray->mapx] == '1')
	{
		img = win_infos->textures[3];
		if (ray->side == 1) {img = win_infos->textures[2];} // OUEST
		if (ray->side == 2) {img = win_infos->textures[1];} // SUD
		if (ray->side == 3) {img = win_infos->textures[0];} // NORD
		
		//x coor of the texture
		int texX = (int)(wallX * (double)img->width);
		if((ray->side == 0 || ray->side == 1) && ray->rayDirX > 0) texX = img->width - texX - 1;
		if((ray->side == 2 || ray->side == 3) && ray->rayDirY < 0) texX = img->width - texX - 1;

		verLine_texture_image(ray->pix, ray->drawEnd, ray->drawStart, win_infos, img, ray, texX);
	}
	else if (win_infos->map->map[ray->mapy][ray->mapx] == '2')
	{
		int color = 16711680;
		if (ray->side == 1) {color = color / 2;} // OUEST
		if (ray->side == 2) {color = color / 4;} // SUD
		if (ray->side == 3) {color = color / 6;} // NORD
		verLine_color_image(ray->pix, ray->drawEnd, ray->drawStart, win_infos, color);
	}

	// Donne a X et a Y une couleur differente
	// side == 0 // EST

	//printf("Color ceiling : %d\n", win_infos->color_ceiling);
	verLine_color_image(ray->pix, 0, ray->drawStart, win_infos, win_infos->color_ceiling);
	verLine_color_image(ray->pix, win_infos->height, ray->drawEnd, win_infos, win_infos->color_floor);
	//mlx_xpm_file_to_image
}