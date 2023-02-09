/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:11:48 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/09 11:31:11 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	find_orientation(t_vault *data)
{
	if (data->player->direction == 'N')
	{
		data->player->pdx = 0;
		data->player->pdy = 1;
	}
	else if (data->player->direction == 'S')
	{
		data->player->pdx = 0;
		data->player->pdy = -1;
	}
	else if (data->player->direction == 'E')
	{
		data->player->pdx = 1;
		data->player->pdy = 0;
	}
	else if (data->player->direction == 'W')
	{
		data->player->pdx = -1;
		data->player->pdy = 0;
	}
}

void	dessine_la_canne(void *param)
{
	t_vault	 *data;
	float		x;
	float		y;
	int		len;

	data = param;
	len = 100;
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
