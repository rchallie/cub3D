/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 14:05:43 by rchallie          #+#    #+#             */
/*   Updated: 2019/11/28 15:38:09 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		key_manager(
	int key,
	void *param)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	ft_putstr_fd("> Input Key : ", 1);
	ft_putnbr_fd(key, 1);
	ft_putchar_fd('\n', 1);
	if (key == ESC)
		leave_prog_simple("> Close ! Bye bye !\n\n", 1, *win_infos);
	return (0);
}
