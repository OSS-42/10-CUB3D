/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:40:10 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/11 22:40:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_pov(t_vault *data)
{
	float	x;
	float	y;
	int		len;

	len = 50;
	x = data->player->px * 11 + 4;
	y = data->player->py * 11 + 4;
	while (len > 0)
	{
		mlx_put_pixel(data->minimap->minimap, y, x, 0xFF00FFFF);
		x += data->player->pdx;
		y += data->player->pdy;
		len--;
	}
}

void	rotate_left(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa - 0.1;
	if (data->player->pa < 0)
		data->player->pa = data->player->pa + 2 * PI;
	data->player->pdx = sin(data->player->pa) * 0.3;
	data->player->pdy = cos(data->player->pa) * 0.3;
	draw_player(data);
}

void	rotate_right(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa + 0.1;
	if (data->player->pa > 2 * PI)
		data->player->pa = data->player->pa - 2 * PI;
	data->player->pdx = sin(data->player->pa) * 0.3;
	data->player->pdy = cos(data->player->pa) * 0.3;
	draw_player(data);
}