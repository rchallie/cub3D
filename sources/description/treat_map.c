/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:58:52 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/16 19:44:31 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		get_map_size(
	char *str,
	t_window *win_infos)
{
	int i;
	int j;
	int	width;
	int	height;

	i = 0;
	j = 0;
	width = 0;
	height = 0;
	while (str[i] != '\n')
	{
		if (str[i] != ' ')
			width++;
		i++;
	}
	win_infos->map->width = width;
	// checker si i = (width * 2) - 1 si width impaire,
	// voir se que ça fait quand width est pair
	while (str[i * j] != '\0')
	{
		if (j != 0)
			height++;
		j++;
	}
	win_infos->map->height = height;
}

static char		**malloc_map(
	t_window *win_infos)
{
	int		i;
	char	**map;

	if (!(map = (char **)malloc(sizeof(char *) * win_infos->map->height)))
		leave_prog_int("Error\n> Malloc failed on map init (1) : ",
		win_infos->map->height, 1, win_infos);
	i = 0;
	while (i < win_infos->map->height)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * win_infos->map->width)))
		{
			leave_prog_int("Error\n> Malloc failed on map init (1) : ",
			win_infos->map->width, 1, win_infos);
		}
		i++;
	}
	return (map);
}

static char		**init_map(
	char *str,
	char **map,
	t_window *win_infos)
{
	int cursor;
	int u;
	int i;

	u = 0;
	i = 0;
	while (u < win_infos->map->height)
	{
		cursor = 0;
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != ' ')
				map[u][cursor++] = str[i];
			if (str[i] == 'N')
			{
				win_infos->player->posx = (double)(cursor - 1);
				win_infos->player->posy = (double)u;
				map[u][cursor - 1] = '0';
			}
			i++;
		}
		map[u++][cursor] = '\0';
		i += 1;
	}
	return (map);
}

char			**map_from_string(
	char *str,
	t_window *win_infos)
{
	char	**map;

	get_map_size(str, win_infos);
	map = malloc_map(win_infos);
	map = init_map(str, map, win_infos);
	free(str);
	return (map);
}
