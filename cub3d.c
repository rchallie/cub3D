/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:10:44 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 18:36:24 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_window	win_infos;
	int			fd;
	char		*map_string;
		ft_putstr_fd("\n==============   CUB3D   ==============\n", 1);
	
	if (argc < 2)
		putstr_info_cmd();

	win_infos.map_name = argv[1];
	
	ft_putchar_fd('\n', 1);
	putstr_info_str("> Map name : ", win_infos.map_name, 1);
	ft_putchar_fd('\n', 1);
	
	// Par défault
	win_infos.width = 1601;
	win_infos.height = 900;
	
	// Traitement fichier de description
	fd = open(win_infos.map_name, O_RDONLY);
	map_string = treat_desc(win_infos.map_name, &win_infos);
	// Init mlx
	if (!(win_infos.mlx_ptr = mlx_init()))
		return (0);
	// Ouvrir en fonction de width et height
	if (!(win_infos.win_ptr = mlx_new_window(win_infos.mlx_ptr, win_infos.width, win_infos.height, "Cub3D")))
		return (0);
	win_infos.map = map_from_string(map_string, &win_infos);

	int i = 0;
	putstr_info_str("> Final map : ", win_infos.map[i], 1);
	i++;
	while (i < win_infos.map_height)
	{
		putstr_info_str("              ", win_infos.map[i], 1);
		i++;
	}
	// Event
	mlx_key_hook(win_infos.win_ptr, key_manager, &win_infos);
	mlx_mouse_hook(win_infos.win_ptr, mouse_manager, &win_infos);
	mlx_loop_hook(win_infos.mlx_ptr, loop_manager, &win_infos);
	
	mlx_loop(win_infos.mlx_ptr);
	return (0);
}