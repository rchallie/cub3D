/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_size_from_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:43:09 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 15:18:25 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		get_size(
	char *str,
	int start)
{
	int rtn;

	rtn = 0;
	while (ft_isdigit(str[start]))
		rtn = (rtn * 10) + (str[start++] - '0');
	return (rtn);
}

static int		check_line_format(
	char *str)
{
	int i;

	if (!str || str[0] != 'R' || str[1] != ' ')
		return (0);
	i = 1;
	while (str[i] == ' ')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != ' ')
		return (0);
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

void			window_size_from_string(
	char *line,
	t_window *win_infos)
{
	int i;

	if (!check_line_format(line))
	{
		putstr_info_str("Error\n> Resolution line not at well format : ",
		line, 1);
		leave_prog(*win_infos);
	}
	i = 1;
	while (line[i] == ' ')
		i++;
	win_infos->width = get_size(line, i);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ')
		i++;
	win_infos->height = get_size(line, i);
	free(line);
}
