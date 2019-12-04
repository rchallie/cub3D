/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_from_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:17 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 15:23:00 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_size(
	char *str,
	int start)
{
	int rtn;

	rtn = 0;
	while (ft_isprint(str[rtn]))
		rtn++;
	return (rtn);
}

static int		check_line_format(
	char *str,
	int c0,
	int c1)
{
	int i;

	if (!str || str[0] != c0 || str[1] != c1 || str[2] != ' ')
		if (c1 != ' ')
			return (0);
		else
			i = 1;
	else
		i = 2;
	while (str[i] == ' ')
		i++;
	if (str[i] != '.')
		return (0);
	i++;
	if (str[i] != '/')
		return (0);
	i++;
	while (ft_isprint(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int		file_exists(
	const char *fname)
{
	int fd;

	if ((fd = open(fname, O_RDONLY)) != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

void			path_from_string(
	char *line,
	int c0,
	int c1,
	t_window *win_infos)
{
	char	*path;
	int		i;

	if (!check_line_format(line, c0, c1))
		leave_prog_str("Error\n> Wrong path : ", line, 1, *win_infos);
	i = (line[2] == ' ') ? 3 : 2;
	while (line[i] == ' ')
		i++;
	if (!(path = ft_substr(line, i, get_size(line, i))))
		leave_prog_str("Error\n> At extract of path : ",
		line, 1, *win_infos);
	if (!file_exists(path))
		leave_prog_str("Error\n> File does'nt exists : ",
		line, 1, *win_infos);
	if (c0 == 'N' && c1 == 'O')
		win_infos->path_north = path;
	else if (c0 == 'S' && c1 == 'O')
		win_infos->path_south = path;
	else if (c0 == 'W' && c1 == 'E')
		win_infos->path_west = path;
	else if (c0 == 'E' && c1 == 'A')
		win_infos->path_east = path;
	else if (c0 == 'S' && c1 == ' ')
		win_infos->path_sprite = path;
	free(line);
}
