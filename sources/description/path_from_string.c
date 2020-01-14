/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_from_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:17 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/13 14:25:38 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int			get_size(
	char *str,
	int start
)
{
	int rtn;

	rtn = 0;
	while (ft_isprint(str[start + rtn]) && str[start + rtn] != '\t'
			&& str[start + rtn] != '\n' && str[start + rtn] != '\r'
			&& str[start + rtn] != '\v' && str[start + rtn] != ' ')
		rtn++;
	return (rtn);
}

static int			check_line_format(
	char *str
)
{
	int i;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] != 'N' && str[i] != 'S' && str[i] != 'W'
		&& str[i] != 'E' && str[i] != 'H')
		return (ERROR);
	i++;
	if (str[i] != 'O' && str[i] != 'E' && str[i] != 'A'
		&& !is_whitespace(str[i]))
		return (ERROR);
	i++;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] != '.' && str[i + 1] != '/')
		return (ERROR);
	while (ft_isprint(str[i]) && !is_whitespace(str[i]) && str[i] != '\0')
		i++;
	if (!is_whitespace(str[i]) && str[i] != '\0')
		return (ERROR);
	while (is_whitespace(str[i]))
		i++;
	return (str[i] != '\0' ? ERROR : SUCCES);
}

static int			file_exists(
	const char *fname
)
{
	int fd;
	int fname_len;

	fname_len = ft_strlen(fname);
	if ((fd = open(fname, O_RDONLY)) == -1)
	{
		close(fd);
		return (ERROR);
	}
	if (fname[fname_len - 1] != 'm' || fname[fname_len - 2] != 'p'
		|| fname[fname_len - 3] != 'x' || fname[fname_len - 4] != '.')
		return (ERROR);
	return (SUCCES);
}

int					path_from_string(
	char *line,
	t_first_chars *fc,
	int first_char_pos,
	t_window *win_infos
)
{
	char	*path;
	int		i;

	if (!check_line_format(line))
		leave(1, win_infos, ft_strjoin("Error\nPath Line format : ", line));
	i = (line[first_char_pos + 1] == ' ') ?
		first_char_pos + 2 : first_char_pos + 3;
	while (is_whitespace(line[i]))
		i++;
	if (!(path = ft_substr(line, i, get_size(line, i))) || !file_exists(path))
		leave(1, win_infos, ft_strjoin("Error\nInvalid Path : ", line));
	if (fc->c0 == 'N' && fc->c1 == 'O')
		return (set_texture(win_infos, path, 0));
	else if (fc->c0 == 'S' && fc->c1 == 'O')
		return (set_texture(win_infos, path, 1));
	else if (fc->c0 == 'W' && fc->c1 == 'E')
		return (set_texture(win_infos, path, 2));
	else if (fc->c0 == 'E' && fc->c1 == 'A')
		return (set_texture(win_infos, path, 3));
	else if (fc->c0 == 'S' && fc->c1 == ' ')
		return (stock_sprite(path, win_infos));
	else if (fc->c0 == 'H' && fc->c1 == ' ')
		return (set_texture(win_infos, path, 4));
	return (SUCCES);
}
