/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/10 00:35:51 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_rays(t_vault *data)
{
	int		ray;
	int		mx;
	int		my;
	int		mp;
	int		dof;
	float	ray_x;
	float	ray_y;
	float	ray_a;
	float	x_offset;
	float	y_offset;
	float	atan;

	ray_a = data->player->pa;
	ray = 0;
	while (ray < 1)
	{
		// check horizontal lines
		dof = 0;
		atan = -1 / tan(ray_a);
		ray++;
		if (ray_a > PI) // is ray looking up
		{
			ray_y = (((int)data->player->py / 64) * 64) - 0.0001;
			ray_x = (data->player->py - ray_y) * atan + data->player->px;
			y_offset = -64;
			x_offset = -y_offset * atan;
		}
		else if (ray_a < PI) // is ray looking up
		{
			ray_y = (((int)data->player->py / 64) * 64) + 64;
			ray_x = (data->player->py - ray_y) * atan + data->player->px;
			y_offset = 64;
			x_offset = -y_offset * atan;
		}
		else if (ray_a == PI || ray_a == 0) // is ray looking left or right
		{
			ray_y = data->player->py;
			ray_x = data->player->px;
			dof = 8;
		}
		while (dof < 8)
		{
			mx = (int) (ray_x) / 64;
			my = (int) (ray_y) / 64;
			mp = my * data->map->lines + mx;
			if (mp < data->map->lines * data->map->max_lenght && data->map->map[mp][mp] == 1)
				dof = 8; // hit wall
			else // nest horizontal line
			{
				ray_x = ray_x + x_offset;
				ray_y = ray_y + y_offset;
				dof = dof + 1;
			}
		}
		dessine_le_ray(data, ray_x, ray_y);// draw ray
	}
}

void	dessine_le_ray(t_vault *data, float ray_x, float ray_y)
{
	int 	len;
	float	x;
	float	y;

	len = ray_y - ray_x;
	x = data->player->px * 11 + 4;
	y = data->player->py * 11 + 4;
	while (len > 0)
	{
		mlx_put_pixel(data->minimap->minimap, y, x, 0x00FF00FF);
		x += ray_x;
		y += ray_y;
		len--;
	}
}