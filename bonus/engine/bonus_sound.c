/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_sound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchallie <rchallie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 14:03:33 by rchallie          #+#    #+#             */
/*   Updated: 2020/01/14 17:06:38 by rchallie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	play_music(t_window *win_infos)
{
	long	clk_tck;
	clock_t	actual_time;

	actual_time = clock();
	clk_tck = CLOCKS_PER_SEC;
	if ((double)(actual_time - win_infos->sound->last_start_song)
		/ (double)clk_tck >= 129.5)
	{
		system("killall afplay");
		system("afplay -v 0.30 bonus/sound/maintheme.mp3 &>/dev/null &");
		win_infos->sound->last_start_song = actual_time;
	}
}
