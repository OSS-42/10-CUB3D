/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:16:45 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/09 13:48:15 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_player(t_vault *data)
{
	data->player->px = data->player->start_x;
	data->player->py = data->player->start_y;
}

void	player_pixels(t_vault *data)
{
	printf("px= %.3f py= %.3f pa= %.3f pdx= %.3f pdy= %.3f\n", data->player->px, data->player->py, data->player->pa, data->player->pdx, data->player->pdy);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4,     data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4,     data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4,     data->player->px * 11 + 4 - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 1, data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 1, data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 + 1, data->player->px * 11 + 4 - 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 1, data->player->px * 11 + 4,     0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 1, data->player->px * 11 + 4 + 1, 0x00FF00FF);
	mlx_put_pixel(data->minimap->minimap, data->player->py * 11 + 4 - 1, data->player->px * 11 + 4 - 1, 0x00FF00FF);
	dessine_la_canne(data);

}

//option MLX pour garder allocaiton a utiliser ?
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
	data->player->px = data->player->px + data->player->pdx;
	data->player->py = data->player->py + data->player->pdy;
	player_pixels(data);
}

void	move_backward(t_vault *data)
{
	reinit_minimap(data);
	data->player->px = data->player->px - data->player->pdx;
	data->player->py = data->player->py - data->player->pdy;
	player_pixels(data);
}

void	rotate_left(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa - 0.1;
	if (data->player->pa < 0)
		data->player->pa = data->player->pa + 2 * PI;
	data->player->pdx = sin(data->player->pa) * 0.3;
	data->player->pdy = cos(data->player->pa) * 0.3;
	player_pixels(data);
}

void	rotate_right(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa + 0.1;
	if (data->player->pa > 2 * PI)
		data->player->pa = data->player->pa - 2 * PI;
	data->player->pdx = sin(data->player->pa) * 0.3;
	data->player->pdy = cos(data->player->pa) * 0.3;
	player_pixels(data);
}
