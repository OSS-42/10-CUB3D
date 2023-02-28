/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:21:30 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/28 15:26:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	dist_and_pos(t_vault *data)
{
	data->raycaster->pdx_ray = data->plr->pdx + data->raycaster->plane_x
		* data->raycaster->screen_2d_x;
	data->raycaster->pdy_ray = data->plr->pdy + data->raycaster->plane_y
		* data->raycaster->screen_2d_x;
	data->raycaster->col = data->plr->col;
	data->raycaster->row = data->plr->row;
	if (data->raycaster->pdx_ray == 0)
		data->raycaster->delta_dist_x = 1e30;
	else
		data->raycaster->delta_dist_x = fabs(1 / data->raycaster->pdx_ray);
	if (data->raycaster->pdy_ray == 0)
		data->raycaster->delta_dist_y = 1e30;
	else
		data->raycaster->delta_dist_y = fabs(1 / data->raycaster->pdy_ray);
	dist_and_pos2(data);
}

void	dist_and_pos2(t_vault *data)
{
	if (data->raycaster->pdx_ray < 0)
	{
		data->raycaster->map_2d_col = -1;
		data->raycaster->ray_len_x = (data->plr->col - data->raycaster->col)
			* data->raycaster->delta_dist_x;
	}
	else
	{
		data->raycaster->map_2d_col = 1;
		data->raycaster->ray_len_x = (data->raycaster->col + 1.0
				- data->plr->col) * data->raycaster->delta_dist_x;
	}
	if (data->raycaster->pdy_ray < 0)
	{
		data->raycaster->map_2d_row = -1;
		data->raycaster->ray_len_y = (data->plr->row - data->raycaster->row)
			* data->raycaster->delta_dist_y;
	}
	else
	{
		data->raycaster->map_2d_row = 1;
		data->raycaster->ray_len_y = (data->raycaster->row + 1.0
				- data->plr->row) * data->raycaster->delta_dist_y;
	}
}

void	check_type_wall(t_vault *data, int *impact)
{
	if (data->map->map[data->raycaster->row][data->raycaster->col] == '1')
		*impact = 1;
	else if (data->map->map[data->raycaster->row][data->raycaster->col]
		== '2')
	{
		*impact = 1;
		if (data->raycaster->side == 0)
			data->raycaster->side = 5;
		else if (data->raycaster->side == 1)
			data->raycaster->side = 4;
		else if (data->raycaster->side == 2)
			data->raycaster->side = 6;
		else if (data->raycaster->side == 3)
			data->raycaster->side = 7;
	}
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == 'D')
		check_type_wall_d(data, impact);
}

void	check_type_wall_d(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 8;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 9;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 10;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 11;
}
