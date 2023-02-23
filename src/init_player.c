/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 09:18:09 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_player(t_vault *data)
{
	init_player(data);
	find_orientation(data, data->player->direction);
	data->map->map[data->player->start_x][data->player->start_y] = '0';
}

void	init_player(t_vault *data)
{
	data->player->row = data->player->start_x + 0.5;
	data->player->col = data->player->start_y + 0.5;
}

void	find_orientation(t_vault *data, char direction)
{
	if (direction == 'N')
	{
		data->player->pdx = 0;
		data->player->pdy = -1;
		data->raycaster->plane_x = 0.66;
		data->raycaster->plane_y = 0;
	}
	else if (direction == 'S')
	{
		data->player->pdx = 0;
		data->player->pdy = 1;
		data->raycaster->plane_x = -0.66;
		data->raycaster->plane_y = 0;
	}
	find_orientation_2(data, direction);
}

void	find_orientation_2(t_vault *data, char direction)
{
	if (direction == 'E')
	{
		data->player->pdx = 1;
		data->player->pdy = 0;
		data->raycaster->plane_x = 0;
		data->raycaster->plane_y = 0.66;
	}
	else if (direction == 'W')
	{
		data->player->pdx = -1;
		data->player->pdy = 0;
		data->raycaster->plane_x = -0.66;
		data->raycaster->plane_y = 0;
	}
}
