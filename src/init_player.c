/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/11 22:41:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_player(t_vault *data)
{
	init_player(data);
	find_orientation(data, data->map->map[data->player->start_x][data->player->start_y]);
	draw_player(data);
}

void	init_player(t_vault *data)
{
	data->player->px = data->player->start_x;
	data->player->py = data->player->start_y;
	data->player->pdx = sin(data->player->pa) * 0.3;
	data->player->pdy = cos(data->player->pa) * 0.3;
}

void	find_orientation(t_vault *data, char direction)
{
	if (direction == 'N')
	{
		data->player->pdx = 0;
		data->player->pdy = 0.1;
		data->player->pa = 0;
	}
	else if (direction == 'S')
	{
		data->player->pdx = 0;
		data->player->pdy = -0.1;
		data->player->pa = PI;
	}
	else if (direction == 'E')
	{
		data->player->pdx = 0.1;
		data->player->pdy = 0;
		data->player->pa = PI / 2;
	}
	else if (direction == 'W')
	{
		data->player->pdx = -0.1;
		data->player->pdy = 0;
		data->player->pa = 3 * PI / 2;
	}
}

void	draw_player(t_vault *data)
{
	printf("px= %.3f py= %.3f pa= %.3f pdx= %.3f pdy= %.3f\n",
		data->player->px, data->player->py, data->player->pa,
		data->player->pdx, data->player->pdy);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4,     data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4,     data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4,     data->player->px * 11 + 4 - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4 + 1, data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4 + 1, data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4 + 1, data->player->px * 11 + 4 - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4 - 1, data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4 - 1, data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap,
		data->player->py * 11 + 4 - 1, data->player->px * 11 + 4 - 1, 0x00FF00FF);
	draw_pov(data);
	// draw_rays(data);
}

