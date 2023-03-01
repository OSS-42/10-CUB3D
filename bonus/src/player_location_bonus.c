/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_location_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:00:16 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/28 23:46:01 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	player_location(t_vault *data, int col, int row)
{
	row = data->plr->row;
	col = data->plr->col;
	if (row >= 27 && row < 35 && col < 13)
	{
		data->hud_loc->location = 0;
		data->hud_loc->p_loc = data->tex->lobby;
	}
	else if (row >= 31 && col >= 13)
	{
		data->hud_loc->location = 1;
		data->hud_loc->p_loc = data->tex->reunion;
	}
	else if (row >= 23 && row < 31 && col >= 13)
	{
		data->hud_loc->location = 2;
		data->hud_loc->p_loc = data->tex->jeux;
	}
	else
		player_location_2(data, col, row);
}

void	player_location_2(t_vault *data, int col, int row)
{
	if (row >= 22 && row < 27 && col < 8)
	{
		data->hud_loc->location = 3;
		data->hud_loc->p_loc = data->tex->cuisine;
	}
	else if (row >= 18 && row < 25 && col < 13 && col >= 7)
	{
		data->hud_loc->location = 4;
		data->hud_loc->p_loc = data->tex->couloir;
	}
	else if (row >= 12 && row < 23 && col >= 13)
	{
		data->hud_loc->location = 5;
		data->hud_loc->p_loc = data->tex->c1;
	}
	else if (row >= 3 && row < 12 && col >= 13)
	{
		data->hud_loc->location = 6;
		data->hud_loc->p_loc = data->tex->c2;
	}
	else
		player_location_3(data, col, row);
}

void	player_location_3(t_vault *data, int col, int row)
{
	if (row >= 0 && row < 3 && col >= 13)
	{
		data->hud_loc->location = 7;
		data->hud_loc->p_loc = data->tex->detente;
	}
	else if (row >= 15 && row < 20 && col < 7)
	{
		data->hud_loc->location = 8;
		data->hud_loc->p_loc = data->tex->amphi;
	}
	else if (row >= 0 && row < 15 && col < 7)
	{
		data->hud_loc->location = 9;
		data->hud_loc->p_loc = data->tex->c3;
	}
	else if (row >= 10 && row < 14 && col >= 7 && col < 13)
	{
		data->hud_loc->location = 10;
		data->hud_loc->p_loc = data->tex->bocal;
	}
	else
		player_location_4(data, col, row);
}

void	player_location_4(t_vault *data, int col, int row)
{
	if (row >= 0 && row < 7 && col >= 7 && col < 13)
	{
		data->hud_loc->location = 11;
		data->hud_loc->p_loc = data->tex->lounge;
	}
	else if (row >= 7 && row < 10 && col >= 8 && col < 14)
	{
		data->hud_loc->location = 12;
		data->hud_loc->p_loc = data->tex->secret;
	}
}
