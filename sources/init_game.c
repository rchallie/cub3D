/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:49:46 by excalibur         #+#    #+#             */
/*   Updated: 2019/12/16 23:12:57 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			init_game_player(
	t_window *win_infos
)
{
	if (!(win_infos->player = malloc(sizeof(t_player))))
		return (ERROR);
	ft_bzero(win_infos->player, sizeof(t_player));
	win_infos->player->posx = 0.0;
	win_infos->player->posy = 0.0;
	win_infos->player->speed = 0.10;
	win_infos->player->dirX = 1.0;
	win_infos->player->dirY = 0.0;
	win_infos->player->planeX = 0.0;
	win_infos->player->planeY = 0.66;
	win_infos->player->rotate_speed = 0.10;
	return (SUCCES);
}

int			init_game_keybuffer(
	t_window *win_infos
)
{
	if (!(win_infos->keybuffer = malloc(sizeof(t_keybuffer))))
		return (ERROR);
	ft_bzero(win_infos->keybuffer, sizeof(t_keybuffer));
	win_infos->keybuffer->toward = 0;
	win_infos->keybuffer->backward = 0;
	win_infos->keybuffer->left = 0;
	win_infos->keybuffer->right = 0;
	win_infos->keybuffer->turn_left = 0;
	win_infos->keybuffer->turn_right = 0;
	return(SUCCES);
}

int			init_game_map(
	t_window *win_infos,
	const char *map_name
)
{
	if (!(win_infos->map = malloc(sizeof(t_map))))
		return (ERROR);
	ft_bzero(win_infos->map, sizeof(t_map));	
	win_infos->map->map_name = map_name;
	win_infos->map->height = 0;
	win_infos->map->width = 0;
	return (SUCCES);
}

int			init_game_textures(
	t_window *win_infos,
	int nbr_textures
)
{
	int count;

	count = 0;
	if (!(win_infos->textures = malloc(sizeof(t_image *) * 4)))
		return(ERROR);
	while(count < nbr_textures)
	{
		if (!(win_infos->textures[count] = malloc(sizeof(t_image))))
			return(ERROR);
		ft_bzero(win_infos->textures[count], sizeof(t_image));
		count++;
	}
	return (SUCCES);
}