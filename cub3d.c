/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 10:10:44 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 15:26:41 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

/******
 * 
 * 
 * 
 * FAIRE LES FREE
 * 
 * 
 * */

void    my_pixel_put_to_image(unsigned long img_color, char *data, int sizeline, int bpp, int x, int y)
{
  int i;
  unsigned char color1;
  unsigned char color2;
  unsigned char color3;
  color1 = (img_color & 0xFF0000) >> 16;
  color2 = (img_color & 0xFF000) >> 8;
  color3 = (img_color & 0xFF);
  data[y * sizeline + x * bpp / 8 ] = color1;
  data[y * sizeline + x * bpp / 8 + 1] = color2;
  data[y * sizeline + x * bpp / 8 + 2] = color3;
}

int		main(int argc, char **argv)
{
	t_window	*win_infos;
	int			fd;
	char		*map_string;
	
	ft_putstr_fd("\n==============   CUB3D   ==============\n", 1);
	if (argc < 2)
		putstr_info_cmd();

	if (!(win_infos = malloc(sizeof(t_window))))
		return (NULL);
	// Map init
	if (!(win_infos->map = malloc(sizeof(t_map))))
		return (NULL);
	win_infos->map->map_name = argv[1];
	win_infos->map->height = 0;
	win_infos->map->width = 0;
	// Par défault
	win_infos->width = 400;
	win_infos->height = 400;
	// KeyBuffer init
	if (!(win_infos->keybuffer = malloc(sizeof(t_keybuffer))))
		return (NULL);
	win_infos->keybuffer->toward = 0;
	win_infos->keybuffer->backward = 0;
	win_infos->keybuffer->left = 0;
	win_infos->keybuffer->right = 0;
	//Player init
	if (!(win_infos->player = malloc(sizeof(t_player))))
		return (NULL);
	win_infos->player->posx = 0.0;
	win_infos->player->posy = 0.0;
	win_infos->player->speed = 0.08;
	win_infos->player->dirX = 1.0;
	win_infos->player->dirY = 0.0;
	win_infos->player->planeX = 0.0;
	win_infos->player->planeY = 0.66;
	win_infos->player->rotate_speed = 0.08;
	
	// Traitement fichier de description
	fd = open(win_infos->map->map_name, O_RDONLY);
	map_string = treat_desc(win_infos->map->map_name, win_infos);
	// Init mlx
	if (!(win_infos->mlx_ptr = mlx_init()))
		return (0);
	// Ouvrir en fonction de width et height
	if (!(win_infos->win_ptr = mlx_new_window(win_infos->mlx_ptr, win_infos->width, win_infos->height, "Cub3D")))
		return (0);
	
	// MAP
	win_infos->map->map = map_from_string(map_string, win_infos);
	putstr_info_char("Char MAIN : ", win_infos->map->map[11][24], 1);
	int i = 0;
	putstr_info_str("> Final map : ", win_infos->map->map[i], 1);
	i++;
	while (i < win_infos->map->height)
	{
		putstr_info_str("              ", win_infos->map->map[i], 1);
		i++;
	}

	putstr_info_int("> Player X  : ", (int)win_infos->player->posx, 1);
	putstr_info_int("> Player Y  : ", (int)win_infos->player->posy, 1);

	// IMG 
	win_infos->img = new_image(win_infos->win_ptr, win_infos->width, win_infos->height);
	
	/*if (!(win_infos->img = malloc(sizeof(t_image))))
		return (NULL); //Exit;
	ft_bzero(win_infos->img, sizeof(t_image));
	
	win_infos->img->img_ptr = mlx_new_image(win_infos->mlx_ptr, 1080, 900);
	win_infos->img->data = mlx_get_data_addr(win_infos->img->img_ptr, &win_infos->img->bpp, &win_infos->img->size_line, &win_infos->img->endian);
	// win_infos->img->width = 100;
	// win_infos->img->height = 100;
	int color = mlx_get_color_value(win_infos->mlx_ptr, 0xf8f8ff);
	int x = 0;
	int y = 0;
	while (x < 1080)
	{
		my_pixel_put_to_image(color, win_infos->img->data, win_infos->img->size_line, win_infos->img->bpp, x, y);
		x++;
		//printf("x : %d, y : %d\n", x, y);
		if(x == 1080 && y < 899)
		{
			x = 0;
			y++;
		}
	}
	write(1, "PUTE\n", 5);
	mlx_put_image_to_window(win_infos->mlx_ptr, win_infos->win_ptr, win_infos->img->img_ptr, 0, 0);
	*/
	// Event
	mlx_hook(win_infos->win_ptr, 2, 1L<<0, key_pressed, win_infos);
	mlx_hook(win_infos->win_ptr, 3, 1L<<1, key_released, win_infos);
	mlx_mouse_hook(win_infos->win_ptr, mouse_manager, win_infos);
	mlx_loop_hook(win_infos->mlx_ptr, loop_manager, win_infos);
	mlx_loop(win_infos->mlx_ptr);
	return (0);
}