/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/10 14:41:09 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_rays(t_vault *data)
{
	int		map_x_len;
	int		map_y_len;
	// int		map_total_size;
	// int		map;
	int		raycast;
	int		mx;
	int		my;
	int		mp;
	int		depth_of_field;
	float	disH;
	float	ray_x;
	float	ray_y;
	float	ray_a;
	float	x_offset;
	float	y_offset;
	float	atan;

	disH = 10000;
	map_x_len = data->map->lines;
	map_y_len = data->map->max_lenght;
	// map_total_size = map_x_len * map_y_len;
	ray_a = data->player->pa;
	raycast = 0;
	while (raycast < 1)
	{
		// check horizontal lines
		depth_of_field = 0;
		atan = -1 / tan(ray_a);
		raycast++;
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
			depth_of_field = 8;
		}
		while (depth_of_field < 8)
		{
			mx = (int)(ray_x) / 64;
			my = (int)(ray_y) / 64;
			mp = my * map_x_len + mx;
			if (mp > 0 && mp < map_x_len * map_y_len && data->map->map2d[mp] == 1)
			{ 
				depth_of_field = 8;
				disH = cos(degtorad(ray_a)) * (ray_x - data->player->px)
					- sin(degtorad(ray_a)) * (ray_y - data->player->py);
			} //hit         
			else
			{
				ray_x = ray_x + x_offset;
				ray_y = ray_y + y_offset;
				depth_of_field = depth_of_field + 1;
			} //check next horizontal
		}
	}
	dessine_le_ray(data, disH * 0.01); // draw ray
}

void	dessine_le_ray(t_vault *data, float len)
{
	float	x;
	float	y;

	x = data->player->px * 11 + 4;
	y = data->player->py * 11 + 4;
	while (len > 0)
	{
		mlx_put_pixel(data->minimap->minimap, y, x, 0x00FF00FF);
		x += data->player->pdx;
		y += data->player->pdy;
		len--;
	}
}

void	map_double_array_to_int(t_vault *data)
{
	int		i;
	int		j;
	int		k;
	int		*temp;

	i = -1;
	k = 0;
	temp = ft_calloc((data->map->lines * data->map->max_lenght),
			sizeof(int));
	while (++i < data->map->lines)
	{
		j = 0;
		while (j < data->map->max_lenght)
		{
			temp[k] = data->map->map[i][j] - 48;
			k++;
			j++;
		}
	}
	data->map->map2d = temp;
	free (temp);
	temp = NULL;
}

float	degtorad(float angle)
{
	return (angle * PI / 180);
}

int	fix_angle(int angle)
{
	if (angle > 359)
		angle = angle - 360;
	if (angle < 0)
		angle = angle + 360;
	return (angle);
}

float	distance(float angle_x, float angle_y, float b_x, float b_y, int ang)
{
	return (cos(degtorad(ang)) * (b_x - angle_x)
		- sin(degtorad(ang)) * (b_y - angle_y));
}
