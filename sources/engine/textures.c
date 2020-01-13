/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:01:43 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/09 11:29:46 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	determine_side_draw(
	t_ray *ray,
	t_window *win_infos,
	t_line *line,
	double wall_x
)
{
	t_image	*img;
	int		tex_x;

	img = win_infos->textures[3];
	if (ray->side == 1)
		img = win_infos->textures[2];
	if (ray->side == 2)
		img = win_infos->textures[1];
	if (ray->side == 3)
		img = win_infos->textures[0];
	tex_x = (int)(wall_x * (double)img->width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line->y0 = ray->draw_end;
	line->y1 = ray->draw_start;
	line->tex_x = tex_x;
	ver_line_texture_image(line, win_infos, img, ray);
}

void		texturisation(
	t_ray *ray,
	t_window *win_infos
)
{
	t_image	*img;
	t_line	*line;
	double	wall_x;

	if (!(line = malloc(sizeof(t_line))))
		leave(1, win_infos, "Error\nDuring line malloc\n");
	ft_bzero(line, sizeof(t_line));
	line->x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = win_infos->player->posy + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = win_infos->player->posx + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	if (win_infos->map->map[ray->mapy][ray->mapx] == '1')
		determine_side_draw(ray, win_infos, line, wall_x);
	line->y0 = 0;
	line->y1 = ray->draw_start;
	ver_line_color_image(line, win_infos, win_infos->color_ceiling);
	line->y0 = win_infos->height;
	line->y1 = ray->draw_end;
	ver_line_color_image(line, win_infos, win_infos->color_floor);
}

int			set_texture(
	t_window *win_infos,
	const char *path,
	int texture_index
)
{
	if (!(win_infos->textures[texture_index]->img_ptr =
		mlx_xpm_file_to_image(win_infos->mlx_ptr, (char *)path,
		&win_infos->textures[texture_index]->width,
		&win_infos->textures[texture_index]->height)))
		return (ERROR);
	win_infos->textures[texture_index]->data =
		mlx_get_data_addr(win_infos->textures[texture_index]->img_ptr,
		&win_infos->textures[texture_index]->bpp,
		&win_infos->textures[texture_index]->size_line,
		&win_infos->textures[texture_index]->endian);
	return (SUCCES);
}
