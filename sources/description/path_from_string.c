/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_from_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 13:35:17 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/17 17:12:07 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int		set_texture(
	t_window *win_infos,
	const char *path,
	int texture_index
)
{
	if(!(win_infos->textures[texture_index]->img_ptr = 
		mlx_xpm_file_to_image(win_infos->mlx_ptr, path,
		&win_infos->textures[texture_index]->width, 
		&win_infos->textures[texture_index]->height)))
			return (ERROR);
	win_infos->textures[texture_index]->data = 
		mlx_get_data_addr(win_infos->textures[texture_index]->img_ptr,
		&win_infos->textures[texture_index]->bpp,
		&win_infos->textures[texture_index]->size_line,
		&win_infos->textures[texture_index]->endian);	
	return (SUCCES);
}

static int		get_size(
	char *str,
	int start
)
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
	int c1
)
{
	int i;

	if (!str || str[0] != c0 || str[1] != c1 || str[2] != ' ')
		if (c1 != ' ')
			return (ERROR);
		else
			i = 1;
	else
		i = 2;
	while (str[i] == ' ')
		i++;
	if (str[i] != '.')
		return (ERROR);
	i++;
	if (str[i] != '/')
		return (ERROR);
	i++;
	while (ft_isprint(str[i]))
		i++;
	if (str[i] != '\0')
		return (ERROR);
	return (SUCCES);
}

static int		file_exists(
	const char *fname
)
{
	int fd;
	int fname_len;

	fname_len = ft_strlen(fname);
	if ((fd = open(fname, O_RDONLY)) == -1)
		return (close(fd));
	if(fname[fname_len - 1] != 'm' || fname[fname_len - 2] != 'p' 
		|| fname[fname_len - 3] != 'x' || fname[fname_len - 4] != '.')
		return (ERROR);
	return (SUCCES);
}

int			path_from_string(
	char *line,
	int c0,
	int c1,
	t_window *win_infos
)
{
	char	*path;
	int		i;

	if (!check_line_format(line, c0, c1))
		return (ERROR);
	i = (line[2] == ' ') ? 3 : 2;
	while (line[i] == ' ')
		i++;
	if (!(path = ft_substr(line, i, get_size(line, i))))
		return (ERROR);
	if (!file_exists(path))
		return (ERROR);
	if (c0 == 'N' && c1 == 'O')
		return (set_texture(win_infos, path, 0));
	else if (c0 == 'S' && c1 == 'O')
		return (set_texture(win_infos, path, 1));
	else if (c0 == 'W' && c1 == 'E')
		return (set_texture(win_infos, path, 2));
	else if (c0 == 'E' && c1 == 'A')
		return (set_texture(win_infos, path, 3));
	else if (c0 == 'S' && c1 == ' ')
		win_infos->path_sprite = path;
	free(path);
	free(line);
	// AJOUTER UN RETURN ERROR QUAND SPRITE SERA INIT COMME IL FAUT
}
