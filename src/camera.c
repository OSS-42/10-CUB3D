/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:40:10 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/27 13:31:24 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	rotate_left(t_vault *data)
{
	double	old_player_pdx;
	double	old_plane_x;

	old_player_pdx = data->player->pdx;
	data->player->pdx = data->player->pdx * cos(-data->raycaster->rot_speed)
		- data->player->pdy * sin(-data->raycaster->rot_speed);
	data->player->pdy = old_player_pdx * sin(-data->raycaster->rot_speed)
		+ data->player->pdy * cos(-data->raycaster->rot_speed);
	old_plane_x = data->raycaster->plane_x;
	data->raycaster->plane_x = data->raycaster->plane_x
		* cos(-data->raycaster->rot_speed) - data->raycaster->plane_y
		* sin(-data->raycaster->rot_speed);
	data->raycaster->plane_y = old_plane_x * sin(-data->raycaster->rot_speed)
		+ data->raycaster->plane_y * cos(-data->raycaster->rot_speed);
	reinit_3d(data);
	raycaster(data);
}

void	rotate_right(t_vault *data)
{
	double	old_player_pdx;
	double	old_plane_x;

	old_player_pdx = data->player->pdx;
	data->player->pdx = data->player->pdx * cos(data->raycaster->rot_speed)
		- data->player->pdy * sin(data->raycaster->rot_speed);
	data->player->pdy = old_player_pdx * sin(data->raycaster->rot_speed)
		+ data->player->pdy * cos(data->raycaster->rot_speed);
	old_plane_x = data->raycaster->plane_x;
	data->raycaster->plane_x = data->raycaster->plane_x
		* cos(data->raycaster->rot_speed) - data->raycaster->plane_y
		* sin(data->raycaster->rot_speed);
	data->raycaster->plane_y = old_plane_x * sin(data->raycaster->rot_speed)
		+ data->raycaster->plane_y * cos(data->raycaster->rot_speed);
	reinit_3d(data);
	raycaster(data);
}
