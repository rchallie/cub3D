/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:34:12 by rchallie          #+#    #+#             */
/*   Updated: 2019/12/02 16:21:14 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	leave_prog_str(
	char *message,
	char *str,
	int fd,
	t_window win_infos)
{
	putstr_info_str(message, str, fd);
	mlx_destroy_window(win_infos.mlx_ptr, win_infos.win_ptr);
	exit(0);
}

void	leave_prog_int(
	char *message,
	int i,
	int fd,
	t_window win_infos)
{
	putstr_info_int(message, i, fd);
	mlx_destroy_window(win_infos.mlx_ptr, win_infos.win_ptr);
	exit(0);
}

void	leave_prog_simple(
	char *message,
	int fd,
	t_window win_infos)
{
	ft_putstr_fd(message, fd);
	mlx_destroy_window(win_infos.mlx_ptr, win_infos.win_ptr);
	exit(0);
}

void	leave_prog(
	t_window win_infos)
{
	mlx_destroy_window(win_infos.mlx_ptr, win_infos.win_ptr);
	exit(0);
}
