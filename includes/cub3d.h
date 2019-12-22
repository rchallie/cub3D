/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:52:11 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 17:36:26 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// # define ESC 53
// # define TOWARD 13
// # define BACKWARD 1
// # define LEFT 0
// # define RIGHT 2

# define ERROR 0
# define SUCCES 1

# define ESC 65307
# define TOWARD 122
# define BACKWARD 115
# define LEFT 113
# define RIGHT 100
# define CAM_LEFT 65361
# define CAM_RIGHT 65363

# include "../libft/libft.h"
# include "utils.h"
# include <mlx.h>
# include <math.h>

typedef struct	s_ray
{
	int			pix;
	int			mapx;
	int			mapy;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	double		sideDistX;
    double		sideDistY;
	double		deltaDistX;
	double		deltaDistY;
	double		perpWallDist;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			lineHeight;
	int			drawStart;
	int			drawEnd;
}				t_ray;

typedef struct		s_image
{
	int				width;
	int				height;
	int				size_line;
	int				bpp;
	int				endian;
	void			*img_ptr;
	char			*data;
}					t_image;

typedef struct		s_keybuffer
{
	int				toward;
	int				backward;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
}					t_keybuffer;

typedef struct		s_map
{
	char			**map;
	const char		*map_name;
	int				width;
	int				height;
}					t_map;

typedef	struct		s_player
{
	double			posx;
	double			posy;
	double			speed;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			rotate_speed;
}					t_player;


typedef	struct		s_window
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	char			*path_sprite;
	int				color_floor;
	int				color_ceiling;
	t_map			*map;
	t_keybuffer		*keybuffer;
	t_player		*player;
	t_image			*img;
	t_image			**textures;
}					t_window;

int					init_game_player(t_window *win_infos);
int					init_game_keybuffer(t_window *win_infos);
int					init_game_map(t_window *win_infos, const char *map_name);
int					init_game_textures(t_window *win_infos, int nbr_textures);

int					key_pressed(int key, void *param);
int					key_released(int key, void *param);
int					key_manager(t_window *win_infos);
int					mouse_manager(int button, int x, int y, void *param);
int					loop_manager(void *param);
void				leave_prog(t_window *win_infos);
void				leave_prog_simple(char *message, int fd,
					t_window *win_infos);
void				leave_prog_str(char *message, char *str, int fd,
					t_window *win_infos);
void				leave_prog_int(char *message, int i, int fd,
					t_window *win_infos);
void				leave_prog_str_low_free(char *message, char *str, int fd,
					t_window *win_infos);

int					window_size_from_string(char *line, t_window	*win_infos);
int					path_from_string(char *line, int c0, int c1,
					t_window *win_infos);
int					color_from_string(char *line, int c, t_window *win_infos);
char				*treat_desc(const char *map_name, t_window *win_infos);
char				**map_from_string(char *str, t_window *win_infos);

void				pixel_put_cinq(int x, int y, int color, t_window win_infos);
void				draw_minimap(t_window *win_infos);

void				turn_left(t_window *win_infos);
void				turn_right(t_window *win_infos);
void				move_left(t_window *win_infos);
void				move_right(t_window *win_infos);
void				move_forward(t_window *win_infos);
void				move_backward(t_window *win_infos);

void				pixel_put_to_image(int color,int x, int y, t_window *win_infos);
void				verLine_color_image(int x, int y0, int y1, t_window *win_infos, int color);
void				verLine_texture_image(int x, int y0, int y1, t_window *win_infos, t_image *texture, t_ray *ray, int texX);
t_image				*new_image(t_window *win_infos, int x_len, int	y_len);

void				raycasting(t_window *win_infos);
void				colorisation(t_ray *ray, t_window *win_infos);

#endif
