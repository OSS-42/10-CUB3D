/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:40:10 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/21 14:17:31 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_pov(t_vault *data)
{
	float	x;
	float	y;
	int		len;

	len = 0;
	x = data->player->ppx;
	y = data->player->ppy;
	data->player->pdlen = 10;
	while (len < data->player->pdlen)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0xFF00FFFF);
		x = x + data->player->pdx;
		y = y + data->player->pdy;
		len++;
	}
}

void	rotate_left(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa - degtorad(5);
	if (data->player->pa < 0)
		data->player->pa = data->player->pa + 2 * PI;
	data->player->pdx = cos(data->player->pa);
	data->player->pdy = sin(data->player->pa);
	draw_player(data);
	raycaster(data);
}

void	rotate_right(t_vault *data)
{
	reinit_minimap(data);
	data->player->pa = data->player->pa + degtorad(5);
	if (data->player->pa > 2 * PI)
		data->player->pa = data->player->pa - 2 * PI;
	data->player->pdx = cos(data->player->pa);
	data->player->pdy = sin(data->player->pa);
	draw_player(data);
	raycaster(data);
}
