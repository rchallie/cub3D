/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size_from_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:43:09 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/11 14:40:42 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_size(
	char *str,
	int start
)
{
	int rtn;

	rtn = 0;
	while (ft_isdigit(str[start]))
		rtn = (rtn * 10) + (str[start++] - '0');
	return (rtn);
}

static int		check_line_format(
	char *str
)
{
	int i;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	if (!str || str[i] != 'R' || str[i + 1] != ' ')
		return (ERROR);
	i = i + 1;
	while (is_whitespace(str[i]))
		i++;
	if (!ft_isdigit(str[i]))
		return (ERROR);
	while (ft_isdigit(str[i]))
		i++;
	if (!is_whitespace(str[i]))
		return (ERROR);
	while (is_whitespace(str[i]))
		i++;
	while (ft_isdigit(str[i]))
		i++;
	while (is_whitespace(str[i]))
		i++;
	if (!is_whitespace(str[i]) && str[i] != '\0')
		return (ERROR);
	return (SUCCES);
}

int				window_size_from_string(
	char *line,
	t_window *win_infos
)
{
	int i;

	if (!check_line_format(line))
		leave(1, win_infos, ft_strjoin("Error\nWin Line format : ", line));
	i = 0;
	while (is_whitespace(line[i]))
		i++;
	i += 1;
	while (is_whitespace(line[i]))
		i++;
	win_infos->width = get_size(line, i);
	if (win_infos->width > 2560)
		win_infos->width = 2560;
	while (ft_isdigit(line[i]))
		i++;
	while (is_whitespace(line[i]))
		i++;
	win_infos->height = get_size(line, i);
	if (win_infos->height > 1440)
		win_infos->height = 1440;
	return (SUCCES);
}
