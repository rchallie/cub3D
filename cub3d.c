/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:10:44 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/17 09:03:45 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void		need_save(
	t_window *win_infos,
	char **argv
)
{
	if (ft_strlen(argv[2]) > 0)
	{
		if (ft_strlen(argv[2]) == ft_strlen("--save") &&
			ft_strncmp(argv[2], "--save", ft_strlen(argv[2])) == 0)
		{
			win_infos->save = 1;
			raycasting(win_infos);
		}
		else
			putstr_info_cmd();
	}
	else
		win_infos->save = 0;
}

void			leave(
	int mod,
	t_window *win_infos,
	char *msg
)
{
	if (mod == 0)
		mlx_destroy_window(win_infos->mlx_ptr, win_infos->win_ptr);
	system("killall afplay");
	ft_putstr_fd(msg, 1);
	if (msg[0])
		write(1, "\n", 1);
	exit(0);
}

static t_window	*init_game_window_pone(
	void
)
{
	t_window *new_win_infos;

	if (!(new_win_infos = malloc(sizeof(t_window))))
		exit(1);
	ft_bzero(new_win_infos, sizeof(t_window));
	if (!(new_win_infos->mlx_ptr = mlx_init()))
		return (ERROR);
	new_win_infos->map_desc_found = 0;
	new_win_infos->space_after_map_desc_found = 0;
	new_win_infos->width = 400;
	new_win_infos->height = 400;
	return (new_win_infos);
}

static int		init_game_window_ptwo(
	t_window *win_infos
)
{
	char	*map_string;

	win_infos->save = 0;
	if (!(map_string = treat_desc(win_infos->map->map_name, win_infos)))
		return (ERROR);
	win_infos->map->map = map_from_string(map_string, win_infos);
	if (!(win_infos->win_ptr = mlx_new_window(win_infos->mlx_ptr,
		win_infos->width, win_infos->height, "Cub3D")))
		return (ERROR);
	if (!(win_infos->img = new_image(win_infos, win_infos->width,
		win_infos->height)))
		return (ERROR);
	return (SUCCES);
}

int				main(
	int argc,
	char **argv
)
{
	t_window	*win_infos;
	int			fd;

	if (argc < 2)
		putstr_info_cmd();
	if (!(win_infos = init_game_window_pone())
		|| !init_game_textures(win_infos, 5)
		|| !init_game_sprite(win_infos)
		|| !init_game_map(win_infos, argv[1])
		|| !init_game_keybuffer(win_infos)
		|| !init_game_player(win_infos)
		|| !init_game_window_ptwo(win_infos)
		|| !init_sound(win_infos))
		leave(1, win_infos, "");
	need_save(win_infos, argv);
	mlx_hook(win_infos->win_ptr, 2, 1L << 0, event_key_pressed, win_infos);
	mlx_hook(win_infos->win_ptr, 3, 1L << 1, event_key_released, win_infos);
	mlx_hook(win_infos->win_ptr, 17, 1L << 17, event_destroy_window, win_infos);
	mlx_loop_hook(win_infos->mlx_ptr, loop_manager, win_infos);
	if (win_infos->save != 1)
		mlx_loop(win_infos->mlx_ptr);
	leave(0, win_infos, "");
	return (0);
}
