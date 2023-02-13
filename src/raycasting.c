/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/13 11:35:23 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// void	draw_rays(t_vault *data)
// {
	
// }



// void	draw_rays(t_vault *data)
// {
// 	int		map_x_len;
// 	int		map_y_len;
// 	// int		map_total_size;
// 	// int		map;
// 	int		raycast;
// 	int		mx;
// 	int		my;
// 	int		mp;
// 	int		depth_of_field;
// 	// int		side;
// 	float	dish;
// 	float	disv;
// 	float	ver_x;
// 	float	ver_y;
// 	float	ray_x;
// 	float	ray_y;
// 	float	ray_a;
// 	float	x_offset;
// 	float	y_offset;
// 	float	tan_a;

// 	map_x_len = data->map->lines;
// 	map_y_len = data->map->max_lenght;
// 	// map_total_size = map_x_len * map_y_len;
// 	// ray_a = data->player->pa;
// 	raycast = 0;
// 	ray_a = fix_angle(data->player->pa + 30);
// 	while (raycast < 60)
// 	{
// 		// check vertical lines
// 		// side = 0;
// 		disv = 100;
// 		depth_of_field = 0;
// 		dessine_le_ray(data, disv); // s'affiche....mais n'a pas le decalage de + 30
// 		tan_a = tan(degtorad(ray_a));
// 		if (cos(degtorad(ray_a)) > 0.001) // is ray looking up
// 		{
// 			ray_x = (((int)data->player->px / 10) * 10) + 10;
// 			ray_y = (data->player->px - ray_x) * tan_a + data->player->py;
// 			x_offset = 10;
// 			y_offset = -x_offset * tan_a;
// 		}
// 		else if (cos(degtorad(ray_a)) < -0.001) // is ray looking down
// 		{
// 			ray_x = (((int)data->player->px / 10) * 10) - 0.0001;
// 			ray_y = (data->player->px - ray_x) * tan_a + data->player->py;
// 			x_offset = -10;
// 			y_offset = -x_offset * tan_a;
// 		}
// 		else  // is ray looking left or right
// 		{
// 			ray_y = data->player->py;
// 			ray_x = data->player->px;
// 			depth_of_field = 8;
// 		}
// 		while (depth_of_field < 8)
// 		{
// 			mx = (int)(ray_x) / 10;
// 			my = (int)(ray_y) / 10;
// 			mp = my * map_x_len + mx;
// 			if (mp > 0 && mp < map_x_len * map_y_len && data->map->map2d[mp] == 1)
// 			{ 
// 				depth_of_field = 8;
// 				disv = cos(degtorad(ray_a)) * (ray_x - data->player->px)
// 					- sin(degtorad(ray_a)) * (ray_y - data->player->py);
// 			} //hit         
// 			else
// 			{
// 				ray_x = ray_x + x_offset;
// 				ray_y = ray_y + y_offset;
// 				depth_of_field = depth_of_field + 1;
// 			} //check next vertical
// 		}
// 		ver_x = ray_x;
// 		ver_y = ray_y;
		
// 		// check horizontal lines
// 		dish = 100000;
// 		depth_of_field = 0;
// 		tan_a = 1.0 / tan_a;
// 		if (sin(degtorad(ray_a)) > 0.001) // is ray looking up
// 		{
// 			ray_y = (((int)data->player->py / 10) * 10) - 0.0001;
// 			ray_x = (data->player->py - ray_y) * tan_a + data->player->px;
// 			y_offset = -10;
// 			x_offset = -y_offset * tan_a;
// 		}
// 		else if (sin(degtorad(ray_a)) < -0.001) // is ray looking down
// 		{
// 			ray_y = (((int)data->player->py / 10) * 10) + 10;
// 			ray_x = (data->player->py - ray_y) * tan_a + data->player->px;
// 			y_offset = 10;
// 			x_offset = -y_offset * tan_a;
// 		}
// 		else  // is ray looking left or right
// 		{
// 			ray_y = data->player->py;
// 			ray_x = data->player->px;
// 			depth_of_field = 8;
// 		}
// 		while (depth_of_field < 8)
// 		{
// 			mx = (int)(ray_x) / 10;
// 			my = (int)(ray_y) / 10;
// 			mp = my * map_x_len + mx;
// 			if (mp > 0 && mp < map_x_len * map_y_len && data->map->map2d[mp] == 1)
// 			{ 
// 				depth_of_field = 8;
// 				dish = cos(degtorad(ray_a)) * (ray_x - data->player->px)
// 					- sin(degtorad(ray_a)) * (ray_y - data->player->py);
// 			} //hit
// 			else
// 			{
// 				ray_x = ray_x + x_offset;
// 				ray_y = ray_y + y_offset;
// 				depth_of_field = depth_of_field + 1;
// 			} //check next horizontal
// 		}
// 		if (disv < dish)
// 		{
// 			ray_x = ver_x;
// 			ray_y = ver_y;
// 			dish = disv;
// 		}
// 		// dessine_le_ray(data, dish); // ne s'affiche pas
// 		raycast++;
// 		ray_a = fix_angle(ray_a - 1);
// 	}
// }

void	dessine_le_ray(t_vault *data, float len)
{
	float	x;
	float	y;

	x = data->player->px * 11 + 4;
	y = data->player->py * 11 + 4;
	while (len > 0)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0x00FF00FF);
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

// float	distance(float angle_x, float angle_y, float b_x, float b_y, int ang)
// {
// 	return (cos(degtorad(ang)) * (b_x - angle_x)
// 		- sin(degtorad(ang)) * (b_y - angle_y));
// }
