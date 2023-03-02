/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:24:44 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/02 10:11:48 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	play_song(t_vault *data)
{
	if (data->audio == 0)
	{
		data->audio = 1;
		system("afplay ./assets/audio/work-it.mp3&");
	}
}

void	check_and_play_song(t_vault *data)
{
	if (data->map->map[data->plr->old_row][data->plr->old_col] == 'W'
		&& data->map->map[(int)data->plr->row][(int)data->plr->col] != 'W')
	{
		system("afplay ./assets/audio/H2G2-door_close.mp3&");
		data->map->map[data->plr->old_row][data->plr->old_col] = 'D';
	}
	else if (data->map->map[data->plr->old_row][data->plr->old_col] == 'X'
		&& data->map->map[(int)data->plr->row][(int)data->plr->col] != 'X')
	{
		system("afplay ./assets/audio/H2G2-door_close.mp3&");
		data->map->map[data->plr->old_row][data->plr->old_col] = 'Z';
	}
}
