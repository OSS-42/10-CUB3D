/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:40:10 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/10 15:14:12 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	draw_pov(t_vault *data)
{
	float	x;
	float	y;
	int		len;

	len = 0;
	x = data->plr->ppx;
	y = data->plr->ppy;
	while (len < 10)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0xFF00FFFF);
		x = x + data->plr->pdx;
		y = y + data->plr->pdy;
		len++;
	}
}

void	rotate_left(t_vault *data)
{
	double	old_player_pdx;
	double	old_plane_x;

	old_player_pdx = data->plr->pdx;
	data->plr->pdx = data->plr->pdx * cos(-data->raycaster->rot_speed)
		- data->plr->pdy * sin(-data->raycaster->rot_speed);
	data->plr->pdy = old_player_pdx * sin(-data->raycaster->rot_speed)
		+ data->plr->pdy * cos(-data->raycaster->rot_speed);
	old_plane_x = data->raycaster->plane_x;
	data->raycaster->plane_x = data->raycaster->plane_x
		* cos(-data->raycaster->rot_speed) - data->raycaster->plane_y
		* sin(-data->raycaster->rot_speed);
	data->raycaster->plane_y = old_plane_x * sin(-data->raycaster->rot_speed)
		+ data->raycaster->plane_y * cos(-data->raycaster->rot_speed);
	reinit_and_draw(data);
	// reinit_3d(data);
	// reinit_hud(data);
	// reinit_minimap(data);
	// raycaster(data);
}

void	rotate_right(t_vault *data)
{
	double	old_player_pdx;
	double	old_plane_x;

	old_player_pdx = data->plr->pdx;
	data->plr->pdx = data->plr->pdx * cos(data->raycaster->rot_speed)
		- data->plr->pdy * sin(data->raycaster->rot_speed);
	data->plr->pdy = old_player_pdx * sin(data->raycaster->rot_speed)
		+ data->plr->pdy * cos(data->raycaster->rot_speed);
	old_plane_x = data->raycaster->plane_x;
	data->raycaster->plane_x = data->raycaster->plane_x
		* cos(data->raycaster->rot_speed) - data->raycaster->plane_y
		* sin(data->raycaster->rot_speed);
	data->raycaster->plane_y = old_plane_x * sin(data->raycaster->rot_speed)
		+ data->raycaster->plane_y * cos(data->raycaster->rot_speed);
	reinit_and_draw(data);
	// reinit_3d(data);
	// reinit_hud(data);
	// reinit_minimap(data);
	// raycaster(data);
}
