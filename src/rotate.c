/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:11:48 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/09 13:47:49 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	dessine_la_canne(t_vault *data)
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
