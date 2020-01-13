/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 17:34:12 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/08 10:35:49 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		event_destroy_window(void *param)
{
	t_window *win_infos;

	win_infos = (t_window *)param;
	leave(0, win_infos, "");
	return (SUCCES);
}
