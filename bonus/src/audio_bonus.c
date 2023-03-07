/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   audio_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:24:44 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/07 17:00:05 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	play_song(t_vault *data)
{
	if (data->audio == 0)
	{
		data->audio = 1;
		// system("afplay ./assets/audio/work-it.mp3&");
	}
}


