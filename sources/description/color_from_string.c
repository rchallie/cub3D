/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_from_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 15:10:34 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/04 15:18:57 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		check_line_format(
	char *str,
	int c)
{
	int i;

	if (!str || str[0] != c || str[1] != ' ')
		return (0);
	i = 1;
	while (str[i] == ' ')
		i++;
	while (ft_isdigit(str[i]) || str[i] == ',')
		i++;
	if (str[i] != '\0')
		return (0);
	return (1);
}

static int		get_color_from_rgb(
	int r,
	int g,
	int b)
{
	int c;

	c = r;
	c = (c << 8) | g;
	c = (c << 8) | b;
	return (c);
}

static int		get_num_color(
	char *line,
	int *i,
	t_window win_infos)
{
	int color;

	color = ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
		leave_prog_str("Error\n> Invalid : ",
		ft_itoa(color), 1, win_infos);
	while (ft_isdigit(line[*i]))
		*i += 1;
	*i += 1;
	return (color);
}

void			color_from_string(
	char *line,
	int c,
	t_window *win_infos)
{
	int rgb;
	int r;
	int g;
	int b;
	int i;

	rgb = 0;
	if (!check_line_format(line, c))
		leave_prog_str("Error\n> Color line not at well format : ",
		line, 1, *win_infos);
	i = 1;
	while (line[i] == ' ')
		i++;
	r = get_num_color(line, &i, *win_infos);
	g = get_num_color(line, &i, *win_infos);
	b = get_num_color(line, &i, *win_infos);
	rgb = get_color_from_rgb(r, g, b);
	if (c == 'F')
		win_infos->color_floor = rgb;
	else if (c == 'C')
		win_infos->color_ceiling = rgb;
	free(line);
}
