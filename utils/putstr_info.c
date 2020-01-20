/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 15:03:27 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 10:00:05 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	putstr_info_cmd(
	t_window win_infos)
{
	ft_putstr_fd("\nCub3D : \n", 1);
	ft_putstr_fd("\n./Cub3D <\"name\".cub>", 1);
	ft_putstr_fd("\n./Cub3D <\"name\".cub> <-save>\n", 1);
	ft_putchar_fd('\n', 1);
	exit(-1);
}
