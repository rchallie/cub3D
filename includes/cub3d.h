/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:52:11 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 17:11:42 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define ESC 53
# define TOWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define CAM_LEFT 123
# define CAM_RIGHT 124
# define CAMUP 126
# define CAMDOWN 125

# define ERROR_INF -1
# define ERROR 0
# define SUCCES 1
# define NEXT 2

# include "../libft/libft.h"
# include "utils.h"
# include <mlx.h>
# include <math.h>
# include <time.h>

typedef struct			s_sound
{
	clock_t				last_start_song;
}						t_sound;

typedef struct			s_sprite
{
	int					x;
	int					y;
}						t_sprite;

typedef struct			s_sprites
{
	int					x;
	int					y;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_draw_sprite
{
	t_sprite			*sprites;
	int					i;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_width;
	int					draw_start_x;
	int					draw_end_x;
	int					stripe;
	int					y;
	int					d;
	int					tex_x;
	int					tex_y;
	int					color;
	int					totcolor;
}						t_draw_sprite;

typedef struct			s_line
{
	int					x;
	int					y;
	int					y0;
	int					y1;
	int					tex_x;
	int					tex_y;
}						t_line;

typedef struct			s_first_chars
{
	int					c0;
	int					c1;
}						t_first_chars;

typedef struct			s_ray
{
	int					pix;
	int					mapx;
	int					mapy;
	double				camera_x;
	double				ray_dir_x;
	double				ray_dir_y;
	double				side_dist_x;
	double				side_dist_y;
	double				delta_dist_x;
	double				delta_dist_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_height;
	int					draw_start;
	int					draw_end;
	double				*z_buffer;
}						t_ray;

typedef struct			s_image
{
	int					width;
	int					height;
	int					size_line;
	int					bpp;
	int					endian;
	void				*img_ptr;
	char				*data;
}						t_image;

typedef struct			s_keybuffer
{
	int					toward;
	int					backward;
	int					left;
	int					right;
	int					turn_left;
	int					turn_right;
	int					cam_up;
	int					cam_down;
}						t_keybuffer;

typedef struct			s_map
{
	char				**map;
	const char			*map_name;
	int					width;
	int					height;
}						t_map;

typedef	struct			s_player
{
	double				posx;
	double				posy;
	double				speed;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
	double				rotate_speed;
	double				cam_height;
	int					health;
}						t_player;

typedef	struct			s_window
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					width;
	int					height;
	int					color_floor;
	int					color_ceiling;
	int					save;
	int					map_desc_found;
	int					space_after_map_desc_found;
	t_map				*map;
	t_keybuffer			*keybuffer;
	t_player			*player;
	t_image				*img;
	t_image				**textures;
	t_image				*sprite;
	t_sprites			*sprites_on_screen;
	t_sound				*sound;
}						t_window;

void					leave(int mod, t_window *win_infos, char *msg);
int						init_game_player(t_window *win_infos);
int						init_game_keybuffer(t_window *win_infos);
int						init_game_map(t_window *win_infos,
						const char *map_name);
int						init_game_textures(t_window *win_infos,
						int nbr_textures);
int						init_game_sprite(t_window *win_infos);
int						event_key_pressed(int key, void *param);
int						event_key_released(int key, void *param);
int						key_manager(t_window *win_infos);
int						mouse_manager(int button, int x, int y, void *param);
int						loop_manager(void *param);
int						event_destroy_window(void *param);
int						window_size_from_string(char *line,
						t_window *win_infos);
int						path_from_string(char *line, t_first_chars *fc,
						int first_char_pos, t_window *win_infos);
int						color_from_string(char *line, int c, int first_char_pos,
						t_window *win_infos);
char					*treat_desc(const char *map_name, t_window *win_infos);
char					**map_from_string(char *str, t_window *win_infos);
void					pixel_put_cinq(int x, int y, int color,
						t_window win_infos);
void					draw_minimap(t_window *win_infos);
void					turn_left(t_window *win_infos);
void					turn_right(t_window *win_infos);
void					set_start_pos(t_window *win_infos, char dir,
						int cursor, int u);
void					set_start_camera(t_window *win_infos, double dirx,
						double planex, double planey);
void					move_left(t_window *win_infos);
void					move_right(t_window *win_infos);
void					move_forward(t_window *win_infos);
void					move_backward(t_window *win_infos);
void					pixel_put_to_image(int color, int x, int y,
						t_image *img);
void					ver_line_color_image(t_line *line,
						t_window *win_infos, int color);
void					ver_line_texture_image(t_line *line,
						t_window *win_infos, t_image *texture, t_ray *ray);
t_image					*new_image(t_window *win_infos, int x_len, int	y_len);
int						raycasting(t_window *win_infos);
void					perp_and_height(t_ray *ray, t_player *player,
						t_window *win_infos);
void					hit(t_ray *ray, t_window *win_infos);
void					texturisation(t_ray *ray, t_window *win_infos);
int						set_texture(t_window *win_infos, const char *path,
						int texture_index);
int						stock_sprite(char *path, t_window *win_infos);
int						draw_sprite(t_ray *ray, t_window *win_infos);
t_sprite				*list_to_tab(t_window *win_infos);
void					sort_sprite(t_window *win_infos, t_sprite *sprites,
						int nbr_sprites);
void					is_sprite(t_ray *ray, t_window *win_infos);
int						create_bitmap(t_image *mlx_img, char *name);

int						bonus_key_manager(t_window *win_infos);
int						bonus_event_key_released(int key, t_window *win_infos);
int						bonus_event_key_pressed(int key, t_window *win_infos);
void					turn_up(t_window *win_infos);
void					turn_down(t_window *win_infos);
void					draw_health(t_window *win_infos);
void					add_health(t_window *win_infos, int amount);
void					remove_health(t_window *win_infos, int amount);
void					play_music(t_window *win_infos);
int						init_sound(t_window *win_infos);

#endif
