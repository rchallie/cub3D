/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:01:43 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 17:07:11 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	colorisation(t_ray *ray, t_window *win_infos) //TEMPORAIRE a remplacer par le fill texture
{
	int color;
	if (win_infos->map->map[ray->mapy][ray->mapx] == '0')
		color = 16762880;
	else if (win_infos->map->map[ray->mapy][ray->mapx] == '1')
		color = 65297;
	else if (win_infos->map->map[ray->mapy][ray->mapx] == '2')
		color = 16711680;

	// Donne a X et a Y une couleur differente
	// side == 0 // EST
	if (ray->side == 1) {color = color / 2;} // OUEST
	if (ray->side == 2) {color = color / 4;} // SUD
	if (ray->side == 3) {color = color / 6;} // NORD
	verLine_image(ray->pix, ray->drawEnd, ray->drawStart, win_infos, color);
}