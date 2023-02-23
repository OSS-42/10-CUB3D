/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:24:44 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/23 14:11:31 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	play_song(t_vault *data)
{
	if (data->audio == 0)
	{
		data->audio = 1;
		system("afplay ./bonus/assets/audio/work-it.mp3&");
	}
}
