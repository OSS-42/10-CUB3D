/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/28 15:26:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_player(t_vault *data)
{
	init_player(data);
	find_orientation(data, data->plr->direction);
	data->map->map[data->plr->start_x][data->plr->start_y] = '0';
}

void	init_player(t_vault *data)
{
	data->plr->row = data->plr->start_x + 0.5;
	data->plr->col = data->plr->start_y + 0.5;
}

void	find_orientation(t_vault *data, char direction)
{
	if (direction == 'N')
	{
		data->plr->pdx = 0;
		data->plr->pdy = -1;
		data->raycaster->plane_x = 0.66;
		data->raycaster->plane_y = 0;
	}
	else if (direction == 'S')
	{
		data->plr->pdx = 0;
		data->plr->pdy = 1;
		data->raycaster->plane_x = -0.66;
		data->raycaster->plane_y = 0;
	}
	find_orientation_2(data, direction);
}

void	find_orientation_2(t_vault *data, char direction)
{
	if (direction == 'E')
	{
		data->plr->pdx = 1;
		data->plr->pdy = 0;
		data->raycaster->plane_x = 0;
		data->raycaster->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		data->plr->pdx = -1;
		data->plr->pdy = 0;
		data->raycaster->plane_x = -0.66;
		data->raycaster->plane_y = 0;
	}
}
