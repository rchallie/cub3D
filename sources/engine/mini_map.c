/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:54:42 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 20:07:27 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_minimap(t_window win_infos)
{
	int y;
	int x;
	char **map;

	y = 0;
	map = win_infos.map;
	while (y < win_infos.map_height)
	{
		x = 0;
		while(x < win_infos.map_width)
		{
			if (map[y][x] == '1')
				pixel_put_cinq(25+x*5, 25+y*5, 0x94908f, win_infos);
			else if (map[y][x] == '0')
				pixel_put_cinq(25+x*5, 25+y*5, 0xffffff, win_infos);
			else
				pixel_put_cinq(25+x*5, 25+y*5, 0xc92a02, win_infos);
			x++;
		}
		y++;
	}
}