/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size_from_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:43:09 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 16:11:42 by excalibur        ###   ########.fr       */
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

	if (!str || str[0] != 'R' || str[1] != ' ')
		return (ERROR);
	i = 1;
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
		return (ERROR);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != ' ')
		return (ERROR);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (ERROR);
	return (SUCCES);
}

int			window_size_from_string(
	char *line,
	t_window *win_infos
)
{
	int i;

	if (!check_line_format(line))
		return (ERROR);
	i = 1;
	while (line[i] == ' ')
		i++;
	win_infos->width = get_size(line, i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	win_infos->height = get_size(line, i);
	return (SUCCES);
}
