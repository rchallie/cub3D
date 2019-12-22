/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:10:44 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 16:05:08 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

/******
 * 
 * 
 * CHANGE EXCALIBUR(perso) TO RCHALLIE(ecole)
 * FAIRE LES FREES
 * 
 * */

t_window	*init_game_window_pone(
	void
)
{
	t_window *new_win_infos;
	if (!(new_win_infos = malloc(sizeof(t_window))))
		return ;
	ft_bzero(new_win_infos, sizeof(t_window));
	if (!(new_win_infos->mlx_ptr = mlx_init()))
		return ;
	new_win_infos->width = 400;
	new_win_infos->height = 400;
	return (new_win_infos);
}

int			init_game_window_ptwo(
	t_window *win_infos
)
{
	char	*map_string;

	if(!(map_string = treat_desc(win_infos->map->map_name, win_infos)))
		return (ERROR);
	win_infos->map->map = map_from_string(map_string, win_infos);
	if (!(win_infos->win_ptr = mlx_new_window(win_infos->mlx_ptr,
		win_infos->width, win_infos->height, "Cub3D")))
		return (ERROR);
	if(!(win_infos->img = new_image(win_infos, win_infos->width,
		win_infos->height)))
		return (ERROR);
	return (SUCCES);
}

// Add system de stage pour les free ne fonction d'où l'erreur viens
int		main(
	int argc,
	char **argv
)
{
	t_window	*win_infos;
	int			fd;
	
	if (argc < 2)
		putstr_info_cmd();
	if(!(win_infos = init_game_window_pone())
		|| !init_game_textures(win_infos, 4)
		|| !init_game_map(win_infos, argv[1])
		|| !init_game_keybuffer(win_infos)
		|| !init_game_player(win_infos)
		|| !init_game_window_ptwo(win_infos))
		return (ERROR);										// A remplacé par une sortie propre du programme
	mlx_hook(win_infos->win_ptr, 2, 1L<<0, key_pressed, win_infos);
	mlx_hook(win_infos->win_ptr, 3, 1L<<1, key_released, win_infos);
	mlx_loop_hook(win_infos->mlx_ptr, loop_manager, win_infos);
	mlx_loop(win_infos->mlx_ptr);
	return (0);
}