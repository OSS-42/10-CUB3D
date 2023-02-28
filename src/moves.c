/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:38:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/28 15:26:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	move_forward(t_vault *data)
{
	if (data->map->map[(int)(data->plr->row + data->plr->pdy
			* data->raycaster->mov_speed)][(int)(data->plr->col)] != '1')
		data->plr->row = data->plr->row + data->plr->pdy
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->plr->row)][(int)(data->plr->col
			+ data->plr->pdx * data->raycaster->mov_speed)] != '1')
		data->plr->col = data->plr->col + data->plr->pdx
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}

void	move_backward(t_vault *data)
{
	if (data->map->map[(int)(data->plr->row - data->plr->pdy
			* data->raycaster->mov_speed)][(int)(data->plr->col)] != '1')
		data->plr->row = data->plr->row - data->plr->pdy
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->plr->row)][(int)(data->plr->col
			- data->plr->pdx * data->raycaster->mov_speed)] != '1')
		data->plr->col = data->plr->col - data->plr->pdx
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}

void	move_left(t_vault *data)
{
	if (data->map->map[(int)(data->plr->row - data->raycaster->plane_y
			* data->raycaster->mov_speed)][(int)(data->plr->col)] != '1')
		data->plr->row = data->plr->row - data->raycaster->plane_y
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->plr->row)][(int)(data->plr->col
			- data->raycaster->plane_x * data->raycaster->mov_speed)] != '1')
		data->plr->col = data->plr->col - data->raycaster->plane_x
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}

void	move_right(t_vault *data)
{
	if (data->map->map[(int)(data->plr->row + data->raycaster->plane_y
			* data->raycaster->mov_speed)][(int)(data->plr->col)] != '1')
		data->plr->row = data->plr->row + data->raycaster->plane_y
			* data->raycaster->mov_speed;
	if (data->map->map[(int)(data->plr->row)][(int)(data->plr->col
			+ data->raycaster->plane_x * data->raycaster->mov_speed)] != '1')
		data->plr->col = data->plr->col + data->raycaster->plane_x
			* data->raycaster->mov_speed;
	reinit_3d(data);
	raycaster(data);
}
