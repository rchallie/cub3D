/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 14:33:55 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 10:04:10 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		next_sprite(
	t_sprites *actual,
	t_sprites *new,
	t_ray *ray
)
{
	while (1)
	{
		if (actual->x == ray->mapx && actual->y == ray->mapy)
		{
			free(new);
			break ;
		}
		if ((actual->x != ray->mapx || actual->y != ray->mapy)
			&& !actual->next)
		{
			actual->next = new;
			break ;
		}
		if (actual->next)
			actual = actual->next;
		else
		{
			free(new);
			break ;
		}
	}
}

void			is_sprite(
	t_ray *ray,
	t_window *win_infos
)
{
	t_sprites *new;
	t_sprites *actual;
	t_sprites save_top;

	if (!(new = malloc(sizeof(t_sprites))))
		return ;
	new->next = NULL;
	new->x = ray->mapx;
	new->y = ray->mapy;
	actual = win_infos->sprites_on_screen;
	save_top = *actual;
	if (actual->x == -1 && actual->y == -1)
	{
		actual->x = ray->mapx;
		actual->y = ray->mapy;
	}
	else
		next_sprite(actual, new, ray);
	actual = &save_top;
}

int				stock_sprite(
	char *path,
	t_window *win_infos
)
{
	if (!(win_infos->sprite->img_ptr =
		mlx_xpm_file_to_image(win_infos->mlx_ptr, path,
		&win_infos->sprite->width,
		&win_infos->sprite->height)))
		return (ERROR);
	win_infos->sprite->data =
		mlx_get_data_addr(win_infos->sprite->img_ptr,
		&win_infos->sprite->bpp,
		&win_infos->sprite->size_line,
		&win_infos->sprite->endian);
	return (SUCCES);
}

void			sort_sprite(
	t_window *win_infos,
	t_sprite *sprites,
	int nbr_sprites
)
{
	int			i;
	double		dist_one;
	double		dist_two;
	t_sprite	tmp;

	i = 0;
	while (i < nbr_sprites && i + 1 != nbr_sprites)
	{
		dist_one = ((win_infos->player->posx - sprites[i].x)
		* (win_infos->player->posx - sprites[i].x) + (win_infos->player->posy
		- sprites[i].y) * (win_infos->player->posy - sprites[i].y));
		dist_two = ((win_infos->player->posx - sprites[i + 1].x)
		* (win_infos->player->posx - sprites[i + 1].x)
		+ (win_infos->player->posy - sprites[i + 1].y)
		* (win_infos->player->posy - sprites[i + 1].y));
		if (dist_one < dist_two)
		{
			tmp = sprites[i];
			sprites[i] = sprites[i + 1];
			sprites[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

t_sprite		*list_to_tab(
	t_window *win_infos
)
{
	t_sprite	*rtn;
	t_sprites	*save_top;
	int			count;

	save_top = win_infos->sprites_on_screen;
	count = -1;
	if (!(rtn = malloc(sizeof(t_sprite)
		* ft_lstsize((t_list *)win_infos->sprites_on_screen))))
		return (ERROR);
	ft_bzero(rtn, sizeof(t_sprite)
		* ft_lstsize((t_list *)win_infos->sprites_on_screen));
	while (++count > -1)
	{
		if (win_infos->sprites_on_screen)
		{
			rtn[count].x = win_infos->sprites_on_screen->x;
			rtn[count].y = win_infos->sprites_on_screen->y;
		}
		if (win_infos->sprites_on_screen->next)
			win_infos->sprites_on_screen = win_infos->sprites_on_screen->next;
		else
			break ;
	}
	win_infos->sprites_on_screen = save_top;
	return (rtn);
}
