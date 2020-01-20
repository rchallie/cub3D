/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_desc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:52:22 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/17 09:33:19 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		is_other(
	char *line,
	char first_char,
	t_window *win_infos
)
{
	if (line[first_char])
	{
		if (line[first_char] != '\0' && line[first_char] != '\n')
		{
			leave(1, win_infos,
			ft_strjoin("Error\nUnknow identifier : ", line));
		}
		free(line);
	}
	else if (line[first_char] == '\0' && win_infos->map_desc_found == 1)
		win_infos->space_after_map_desc_found = 1;
	return (SUCCES);
}

static int		is_from_path(
	char *line,
	char first_char,
	t_window *win_infos
)
{
	t_first_chars *fc;

	if (!(fc = malloc(sizeof(t_first_chars))))
		return (ERROR);
	ft_bzero(fc, sizeof(t_first_chars));
	if (line[first_char] && line[first_char + 1])
	{
		fc->c0 = line[first_char];
		fc->c1 = line[first_char + 1];
	}
	else
		return (NEXT);
	if (fc->c0 == 'R')
		return (window_size_from_string(line, win_infos));
	else if ((line[first_char] == 'N') || (line[first_char] == 'S')
			|| (line[first_char] == 'W') || (line[first_char] == 'E')
			|| (line[first_char] == 'H'))
		return (path_from_string(line, fc, first_char, win_infos));
	else if (line[first_char] == 'F' || line[first_char] == 'C')
	{
		return (color_from_string(line, line[first_char], first_char,
		win_infos));
	}
	return (NEXT);
}

static int		is_map(
	char *line,
	char **map_string,
	char first_char,
	int rtn_reader
)
{
	char	*save_map_string;

	if (line[first_char] == '1' || line[first_char] == '2'
			|| line[first_char] == '0' || line[first_char] == 'N'
			|| (line[first_char] == 'S') || (line[first_char] == 'W')
			|| (line[first_char] == 'E'))
	{
		save_map_string = *map_string;
		*map_string = ft_strjoin(*map_string, line);
		free(save_map_string);
		if (rtn_reader != 0 && line[first_char])
		{
			save_map_string = *map_string;
			*map_string = ft_strjoin(*map_string, "\n");
			free(save_map_string);
		}
		free(line);
		return (SUCCES);
	}
	return (ERROR);
}

static int		get_infos(
	char *line,
	char **map_string,
	int rtn_reader,
	t_window *win_infos
)
{
	int		first_char;
	int		rtn_ifp;

	first_char = 0;
	while (is_whitespace(line[first_char]))
		first_char++;
	if (win_infos->space_after_map_desc_found == 1 && line[first_char] != '\0')
		leave(1, win_infos, "Error\nIn map description conditions");
	if (!(rtn_ifp = is_from_path(line, first_char, win_infos)))
		return (ERROR);
	if (rtn_ifp == NEXT)
	{
		if (is_map(line, map_string, first_char, rtn_reader))
		{
			win_infos->map_desc_found = 1;
			return (SUCCES);
		}
		else
			is_other(line, first_char, win_infos);
	}
	return (SUCCES);
}

char			*treat_desc(
	const char *map_name,
	t_window *win_infos
)
{
	int		fd;
	int		rtn_reader;
	char	*line;
	char	*map_string;

	if ((fd = open(map_name, O_RDONLY)) == -1)
		leave(1, win_infos, "Error\nAt : Open map file.\n");
	if (!(map_string = malloc(sizeof(char) * 2)))
		return (ERROR);
	ft_bzero(map_string, sizeof(char));
	if (!(line = malloc(sizeof(char))))
		return (ERROR);
	ft_bzero(line, sizeof(char));
	while ((rtn_reader = get_next_line(fd, &line)) != -1)
	{
		if (line &&
			!get_infos(line, &map_string, rtn_reader, win_infos))
			return (ERROR);
		line = NULL;
		if (rtn_reader == 0)
			break ;
	}
	return (map_string);
}
