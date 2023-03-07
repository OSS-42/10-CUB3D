/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/07 16:47:56 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_player(t_vault *data)
{
	data->plr->row = data->plr->start_x + 0.5;
	data->plr->col = data->plr->start_y + 0.5;
	data->plr->ppx = data->plr->row * data->minimap->tile_size;
	data->plr->ppy = data->plr->col * data->minimap->tile_size;
	find_orientation(data, data->plr->direction);
	data->map->map[data->plr->start_x][data->plr->start_y] = '0';
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

void	draw_player(t_vault *data)
{
	data->plr->ppx = data->plr->col * data->minimap->tile_size;
	data->plr->ppy = data->plr->row * data->minimap->tile_size;
	mlx_put_pixel(data->minimap->minimap,
		data->plr->ppx, data->plr->ppy, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->plr->ppx, data->plr->ppy + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->plr->ppx, data->plr->ppy - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->plr->ppx + 1, data->plr->ppy, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->plr->ppx - 1, data->plr->ppy, 0x00FF00FF);
	draw_pov(data);
}
