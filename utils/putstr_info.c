/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:03:27 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 15:41:26 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	putstr_info_int(
	char *str,
	int i,
	int fd)
{
	ft_putstr_fd(str, fd);
	ft_putnbr_fd(i, fd);
	ft_putchar_fd('\n', fd);
}

void	putstr_info_char(
	char *str,
	char c,
	int fd)
{
	ft_putstr_fd(str, fd);
	ft_putchar_fd(c, fd);
	ft_putchar_fd('\n', fd);
}

void	putstr_info_str(
	char *str,
	char *put,
	int fd)
{
	ft_putstr_fd(str, fd);
	ft_putstr_fd(put, fd);
	ft_putchar_fd('\n', fd);
}

void	putstr_info_cmd(
	t_window win_infos)
{
	ft_putstr_fd("\nCub3D : \n", 1);
	ft_putstr_fd("\n./Cub3D <\"name\".cub>", 1);
	ft_putstr_fd("\n./Cub3D <\"name\".cub> <-save>\n", 1);
	ft_putchar_fd('\n', 1);
	exit(-1);
}
