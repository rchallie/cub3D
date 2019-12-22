/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:52:22 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 17:02:33 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_infos(
	char *line,
	char **map_string,
	int rtn_reader,
	t_window *win_infos)
{
	char *save_map_string;
	
	if (line[0] == 'R')
	{
		if(!window_size_from_string(line, win_infos))
			return (ERROR);
	}
	else if ((line[0] == 'N' && line[1] == 'O')
			|| (line[0] == 'S' && line[1] == 'O')
			|| (line[0] == 'W' && line[1] == 'E')
			|| (line[0] == 'E' && line[1] == 'A')
			|| (line[0] == 'S' && line[1] == ' '))
	{
		if(!path_from_string(line, line[0], line[1], win_infos))
			return (ERROR);
	}
	else if (line[0] == 'F' || line[0] == 'C')
		color_from_string(line, line[0], win_infos);
	else if (line[0] == '1')
	{
		save_map_string = *map_string;
		*map_string = ft_strjoin(*map_string, line);
		free(save_map_string);
		if (rtn_reader != 0)
		{
			save_map_string = *map_string;
			*map_string = ft_strjoin(*map_string, "\n");
			free(save_map_string);
		}
		free(line);
	}
	else
		free(line);
	return(SUCCES);
}

char			*treat_desc(
	const char *map_name,
	t_window *win_infos)
{
	int		fd;
	int		rtn_reader;
	char	*line;
	char	*map_string;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		return (NULL);
	if (!(map_string = malloc(sizeof(char) * 2)))
		return (NULL);
	ft_bzero(map_string, sizeof(char));
	if(!(line = malloc(sizeof(char))))
		return (NULL);
	ft_bzero(line, sizeof(char));
	while ((rtn_reader = get_line(fd, &line)) != -1)
	{
		if(!get_infos(line, &map_string, rtn_reader, win_infos))
			return (NULL);
		line = NULL;
		if (rtn_reader == 0)
			break ;
	}
	return (map_string);
}
