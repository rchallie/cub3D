/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: excalibur <excalibur@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:34:12 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/16 21:26:29 by excalibur        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_malloced(t_window *win_infos)
{
	int i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(win_infos->mlx_ptr, win_infos->textures[i]->img_ptr);
		free(win_infos->textures[i]);
		i++;
	}
	mlx_destroy_image(win_infos->mlx_ptr, win_infos->img->img_ptr);
	ft_bzero(win_infos->img, sizeof(t_image));
	free(win_infos->img);
}

void	leave_prog_str_low_free(char *message,
	char *str,
	int fd,
	t_window *win_infos)
{
	putstr_info_str(message, str, fd);
	exit(0);
}

void	leave_prog_str(
	char *message,
	char *str,
	int fd,
	t_window *win_infos)
{
	free_malloced(win_infos);
	putstr_info_str(message, str, fd);
	mlx_destroy_window(win_infos->mlx_ptr, win_infos->win_ptr);
	exit(0);
}

void	leave_prog_int(
	char *message,
	int i,
	int fd,
	t_window *win_infos)
{
	free_malloced(win_infos);
	putstr_info_int(message, i, fd);
	mlx_destroy_window(win_infos->mlx_ptr, win_infos->win_ptr);
	exit(0);
}

void	leave_prog_simple(
	char *message,
	int fd,
	t_window *win_infos)
{
	free_malloced(win_infos);
	ft_putstr_fd(message, fd);
	mlx_destroy_window(win_infos->mlx_ptr, win_infos->win_ptr);
	exit(0);
}

void	leave_prog(
	t_window *win_infos)
{
	free_malloced(win_infos);
	mlx_destroy_window(win_infos->mlx_ptr, win_infos->win_ptr);
	exit(0);
}
