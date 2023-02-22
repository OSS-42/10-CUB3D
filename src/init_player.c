/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 11:35:56 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_player(t_vault *data)
{
	init_player(data);
	find_orientation(data, data->player->direction);
	data->map->map[data->player->start_x][data->player->start_y] = '0';
	// draw_player(data);
}

void	init_player(t_vault *data)
{
	data->player->row = data->player->start_x + 0.5;
	data->player->col = data->player->start_y + 0.5;
	data->player->ppx = data->player->row * TILE;
	data->player->ppy = data->player->col * TILE;
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
	else if (direction == 'E')
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

void	draw_player(t_vault *data)
{
	data->player->ppx = data->player->col * TILE;
	data->player->ppy = data->player->row * TILE;
	mlx_put_pixel(data->minimap->minimap,
		data->player->ppx, data->player->ppy, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->ppx, data->player->ppy + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->ppx, data->player->ppy - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->ppx + 1, data->player->ppy, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->ppx - 1, data->player->ppy, 0x00FF00FF);
	draw_pov(data);
}
