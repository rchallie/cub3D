/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:21:39 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/19 22:23:14 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		perp_and_height(
	t_ray *ray,
	t_player *player,
	t_window *win_infos
)
{
	// Calculer la distance du rayon perpendiculaire
	if (ray->side == 0 || ray->side == 1)
		ray->perpWallDist = (ray->mapx - player->posx + (1 - ray->stepX) / 2) 
		/ ray->rayDirX;
	else
	ray->perpWallDist = (ray->mapy - player->posy + (1 - ray->stepY) / 2)
		/ ray->rayDirY;
	
	// Calculer le pixel le plus bas et le plus haut pour print une ligne 
	ray->lineHeight = (int)(win_infos->height / ray->perpWallDist);
	ray->drawStart = -ray->lineHeight / 2 + win_infos->height / 2;
	if(ray->drawStart < 0)
		ray->drawStart = 0;
	ray->drawEnd = ray->lineHeight / 2 + win_infos->height / 2;
	if(ray->drawEnd >= win_infos->height)
		ray->drawEnd = win_infos->height - 1;
}

static void		hit(t_ray *ray, t_window *win_infos)
{
	while (ray->hit == 0)
	{
		// saute vers la prochain carré de la map, soit vers x soit vers y
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapx += ray->stepX;
			if (ray->stepX == 1)
				ray->side = 0;
			else if (ray->stepX == -1)
				ray->side = 1;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapy += ray->stepY;
			if(ray->stepY == 1)
				ray->side = 2;
			else if (ray->stepY == -1)
				ray->side = 3;
		}
		// Check si le rayon tappe un mur 
		if (win_infos->map->map[ray->mapy][ray->mapx] > '0')
			ray->hit = 1;
	}
}

static void		next_step(t_ray *ray, t_player *player)
{
	// Calcul le prochain pas et initialise sideDist
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (player->posx - ray->mapx) * ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapx + 1.0 - player->posx) * ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (player->posy - ray->mapy) * ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapy + 1.0 - player->posy) * ray->deltaDistY;
	}
}

static void 	init_values(t_ray *ray, t_player *player, t_window *win_infos)
{
	// Calcul la position et la direction du rayon
	ray->cameraX = (2 * ray->pix)/(double)win_infos->width - 1;
	ray->rayDirX = player->dirX + player->planeX * ray->cameraX;
	ray->rayDirY = player->dirY + player->planeY * ray->cameraX;

	// Position du joueur sur la carte
	ray->mapx = (int)player->posx;
	ray->mapy = (int)player->posy;

	// Taille du rayon depuis un x ou y-side vers le prochain x ou le prochain y-side
	ray->deltaDistX = fabs(1 / ray->rayDirX);
	ray->deltaDistY = fabs(1 / ray->rayDirY);

	ray->hit = 0;
}

void			raycasting(
	t_window *win_infos)
{
	t_ray *ray;
	t_player	*player;

	player = win_infos->player;
	if (!(ray = malloc(sizeof(t_ray))))
		return ;
	ft_bzero(ray, sizeof(t_ray));
	while (ray->pix < win_infos->width) 
	{
		init_values(ray, player, win_infos);
		next_step(ray, player);
		hit(ray, win_infos);
		perp_and_height(ray, player, win_infos);
		colorisation(ray, win_infos); // A remplacer par le fill texture
		ray->pix++;
	}
	mlx_put_image_to_window(win_infos->mlx_ptr, win_infos->win_ptr, win_infos->img->img_ptr, 0, 0);
	free(ray);
}