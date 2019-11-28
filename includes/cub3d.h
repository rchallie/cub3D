/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:52:11 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 18:54:11 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 53

# include "../libft/libft.h"
# include "utils.h"
# include <mlx.h>

typedef	struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	char			*map_name;
	int				width;
	int				height;
	char			*path_north;
	char			*path_south;
	char			*path_west;
	char			*path_east;
	char			*path_sprite;
	int				color_floor;
	int				color_ceiling;
	char			**map;
	int				map_width;
	int				map_height;
}					t_window;

int					key_manager(int key, void *param);
int					mouse_manager(int button, int x, int y, void *param);
int					loop_manager(void *param);
void				leave_prog(t_window win_infos);
void				leave_prog_simple(char *message, int fd,
					t_window win_infos);
void				leave_prog_str(char *message, char *str, int fd,
					t_window win_infos);
void				leave_prog_int(char *message, int i, int fd,
					t_window win_infos);

void				window_size_from_string(char *line, t_window	*win_infos);
void				path_from_string(char *line, int c0, int c1,
					t_window *win_infos);
void				color_from_string(char *line, int c, t_window *win_infos);
char				*treat_desc(char *map_name, t_window *win_infos);
char				**map_from_string(char *str, t_window *win_infos);

#endif
