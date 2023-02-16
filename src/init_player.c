/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/16 16:27:01 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_player(t_vault *data)
{
	init_player(data);
	find_orientation(data, data->player->direction);
	data->map->map[data->player->start_x][data->player->start_y] = '0';
	draw_player(data);
}

void	init_player(t_vault *data)
{
	data->player->px = data->player->start_x;
	data->player->py = data->player->start_y;
	data->player->ppx = data->player->px * 65 + 32;
	data->player->ppy = data->player->py * 65 + 32;
}

void	find_orientation(t_vault *data, char direction)
{
	if (direction == 'N')
	{
		data->player->pa = 3 *PI / 2;
		data->player->pdx = 0;
		data->player->pdy = -1;
	}
	else if (direction == 'S')
	{
		data->player->pa = PI / 2;
		data->player->pdx = 0;
		data->player->pdy = 1;
	}
	else if (direction == 'E')
	{
		data->player->pa = 0;
		data->player->pdx = 1;
		data->player->pdy = 0;
	}
	else if (direction == 'W')
	{
		data->player->pa = PI;
		data->player->pdx = -1;
		data->player->pdy = 0;
	}
}

void	draw_player(t_vault *data)
{
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
	raycaster(data);
}
