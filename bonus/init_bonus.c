/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:36:52 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/16 09:18:37 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_sound(t_window *win_infos)
{
	if (!(win_infos->sound = malloc(sizeof(t_sound))))
		return (ERROR);
	ft_bzero(win_infos->sound, sizeof(t_sound));
	win_infos->sound->last_start_song = clock();
	system("afplay -v 0.30 bonus/sound/maintheme.mp3 &>/dev/null &");
	return (SUCCES);
}
