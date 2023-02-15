/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/15 12:34:10 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	int		distance_x;
	int		distance_y;
	float	ray_len_x;
	float	ray_len_y;
	float	ray_len;

	ray_len = 0;
	data->raycaster->ray_one_a = data->player->pa - degtorad(30);
	data->raycaster->next_x = data->player->start_x;
	data->raycaster->next_y = data->player->start_y;
	// while(data->raycaster->ray_count < 60)
	// {
		find_ray_angle(data);
		distance_x = pix_to_intersection_x(data);
		distance_y = pix_to_intersection_y(data);
		while (wall_in_next_case(data) == FALSE)
		{
			printf("distance_x : %d\n", distance_x);
			printf("distance_y : %d\n", distance_y);
			ray_len_x = distance_x / cos(data->raycaster->ray_one_a);
			if (ray_len_x < 0)
				ray_len_x = -1 * ray_len_x;
			ray_len_y = distance_y / cos(degtorad(90) - data->raycaster->ray_one_a);
			if (ray_len_y < 0)
				ray_len_y = -1 * ray_len_y;
			printf("ray_len_x : %f\n", ray_len_x);
			printf("ray_len_y : %f\n", ray_len_y);
			if (ray_len_x <= ray_len_y)
			{
				printf("RAY_LEN_X est le plus court\n");
				ray_len = ray_len_x;
				find_next_case(data, distance_x, distance_y);
				if (data->raycaster->pdx_ray < 0)
					distance_x -= 11;
				else if (data->raycaster->pdx_ray > 0)
					distance_x += 11;
			}
			else if (ray_len_x > ray_len_y)
			{
				printf("RAY_LEN_Y est le plus court\n");
				ray_len = ray_len_y;
				find_next_case(data, distance_x, distance_y);
				if (data->raycaster->pdy_ray < 0)
					distance_y -= 11;
				else if (data->raycaster->pdy_ray > 0)
					distance_y += 11;
			}
		}
		draw_ray(data, ray_len);
		// data->raycaster->ray_one_a = data->raycaster->ray_one_a + degtorad(1);
		// data->raycaster->ray_count++;
	// }
	// data->raycaster->ray_count = 0;
}

void	draw_ray(t_vault *data, float ray_len)
{
	float	x;
	float	y;
	int		len;

	len = 0;
	x = data->player->ppx;
	y = data->player->ppy;
	while (len < fabsf(ray_len))
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0x00FF00FF);
		x = x + data->raycaster->pdx_ray;
		y = y + data->raycaster->pdy_ray;
		len++;
	}
}

void	find_ray_angle(t_vault *data)
{
	if (data->raycaster->ray_one_a < 0)
		data->raycaster->ray_one_a = data->raycaster->ray_one_a + 2 * PI;
	else if (data->raycaster->ray_one_a > 2 * PI)
		data->raycaster->ray_one_a = data->raycaster->ray_one_a - 2 * PI;
	data->raycaster->pdx_ray = -1 * cos(data->raycaster->ray_one_a);
	data->raycaster->pdy_ray = -1 * sin(data->raycaster->ray_one_a);
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
