/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:52:22 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 17:59:28 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void		get_infos(
	char *line,
	char **map_string,
	int rtn_reader,
	t_window *win_infos)
{
	if (line[0] == 'R')
		window_size_from_string(line, win_infos);
	else if ((line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A')
			|| (line[0] == 'S' && line[1] == ' '))
		path_from_string(line, line[0], line[1], win_infos);
	else if (line[0] == 'F' || line[0] == 'C')
		color_from_string(line, line[0], win_infos);
	else if (line[0] == '1')
	{
		*map_string = ft_strjoin(*map_string, line);
		if (rtn_reader != 0)
			*map_string = ft_strjoin(*map_string, "\n");
	}
}

char			*treat_desc(
	char *map_name,
	t_window *win_infos)
{
	int		fd;
	int		rtn_reader;
	char	*line;
	char	*map_string;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		leave_prog_str("Error\n> Can't treat : ",
		map_name, 1, *win_infos);
	map_string = "";
	while ((rtn_reader = get_line(fd, &line)) != -1)
	{
		get_infos(line, &map_string, rtn_reader, win_infos);
		line = NULL;
		if (rtn_reader == 0)
			break ;
	}
	return (map_string);
}
