/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:40:10 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 16:42:02 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	reinit_hud(t_vault *data)
{
	mlx_delete_image(data->mlx, data->hud->hud);
	load_hud(data);
}

void	draw_pov(t_vault *data)
{
	float	x;
	float	y;
	int		len;

	len = 0;
	x = data->player->ppx;
	y = data->player->ppy;
	while (len < 10)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0xFF00FFFF);
		x = x + data->player->pdx;
		y = y + data->player->pdy;
		len++;
	}
}

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
	reinit_hud(data);
	reinit_minimap(data);
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
	reinit_hud(data);
	reinit_minimap(data);
	raycaster(data);
}
