/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/08 22:31:32 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_player(t_vault *data)
{
	data->player->px = data->player->start_x;
	data->player->py = data->player->start_y;
	data->player->pdy = cos(data->player->pa) * 0.1;
	data->player->pdx = sin(data->player->pa) * 0.1;
}

void	player_pixels(t_vault *data, char direction)
{
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4,     data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4,     data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4,     data->player->px * 11 + 4 - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 1, data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 1, data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 1, data->player->px * 11 + 4 - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 1, data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 1, data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 1, data->player->px * 11 + 4 - 1, 0x00FF00FF);
	if (direction == 'N')
	{
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4 - 2, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4 - 3, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4 - 4, 0x00FF00FF);
	}
	else if (direction == 'S')
	{
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4 + 2, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4 + 3, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4 + 4, 0x00FF00FF);
	}
	else if (direction == 'W')
	{
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 2, data->player->px * 11 + 4, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 3, data->player->px * 11 + 4, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 4, data->player->px * 11 + 4, 0x00FF00FF);
	}
	else if (direction == 'E')
	{
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 2, data->player->px * 11 + 4, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 3, data->player->px * 11 + 4, 0x00FF00FF);
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 4, data->player->px * 11 + 4, 0x00FF00FF);
	}
	else if (direction == 'A')
	{
		mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4, data->player->px * 11 + 4, 0x00FF00FF);
	}
}

void	reinit_minimap(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	data->minimap->minimap = mlx_new_image(data->mlx,
			data->map->max_lenght * 11, data->map->lines * 11);
	init_minimap(data);
	draw_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, 0);
}

void	move_forward(t_vault *data)
{
	reinit_minimap(data);
	data->player->px = data->player->px - data->player->pdx;
	data->player->py = data->player->py - data->player->pdy;
	player_pixels(data, 'A');
}

void	move_backward(t_vault *data)
{
	reinit_minimap(data);
	data->player->px = data->player->px + data->player->pdx;
	data->player->py = data->player->py + data->player->pdy;
	player_pixels(data, 'A');
}

void	rotate_left(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa - 0.3;
	if (data->player->pa < 0)
		data->player->pa = data->player->pa + 2 * PI;
	printf("%f\n", data->player->px);
	data->player->pdy = cos(data->player->pa) * 0.1;
	data->player->pdx = sin(data->player->pa) * 0.1;
	// data->player->py = data->player->py - 0.3;
	player_pixels(data, 'A');
}

void	rotate_right(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa + 0.3;
	if (data->player->pa > 2 * PI)
		data->player->pa = data->player->pa - 2 * PI;
	data->player->pdy = cos(data->player->pa) * 0.1;
	data->player->pdx = sin(data->player->pa) * 0.1;
	// data->player->py = data->player->py + 0.3;
	player_pixels(data, 'A');
}
