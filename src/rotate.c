/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:11:48 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/09 11:04:39 by mbertin          ###   ########.fr       */
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
	len = 10;
	x = data->player->px;
	y = data->player->py;
	while (len > 0)
	{
		mlx_put_pixel(data->minimap->minimap, y, x, 0x00FF00FF);
		x += data->player->pdx;
		y += data->player->pdy;
		len--;
	}
}
