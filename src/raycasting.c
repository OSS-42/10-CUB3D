/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/14 22:47:40 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	int		distance_x;
	int		distance_y;
	char	to_compare;
	float	ray_len_x;
	float	ray_len_y;
	float	ray_len;

	ray_len = 0;
	to_compare = 0;
	data->raycaster->ray_one_a = data->player->pa - degtorad(30);
	// while(data->raycaster->ray_count < 60)
	// {
		find_ray_angle(data);
		distance_x = pix_to_intersection_x(data);
		distance_y = pix_to_intersection_y(data);
		ray_len_x = distance_x / cos(data->raycaster->ray_one_a);
		ray_len_y = sin(degtorad(90) - data->raycaster->ray_one_a) * distance_y;
		printf("ray_len_x : %f\n", ray_len_x);
		printf("ray_len_y : %f\n", ray_len_y);
		if (ray_len_x <= ray_len_y)
		{
			printf("COMPARE = X\n");
			ray_len = distance_x / cos(data->raycaster->ray_one_a);
			find_next_case_x(data, ray_len_x, distance_x);
			to_compare = 'Y';
		}
		else if (ray_len_x > ray_len_y)
		{
			printf("COMPARE = Y\n");
			ray_len = sin(degtorad(90) - data->raycaster->ray_one_a) * distance_y;
			find_next_case_y(data, ray_len_y, distance_y);
			to_compare = 'X';
		}
		while(wall_in_next_case(data) == FALSE)
		{
			if (to_compare == 'X')
			{
				printf("COMPARE = X\n");
				to_compare = 'Y';
				ray_len = distance_x / cos(data->raycaster->ray_one_a);
				find_next_case_x(data, ray_len, distance_x);
			}
			else if (to_compare == 'Y')
			{
				printf("COMPARE = Y\n");
				to_compare = 'X';
				ray_len = sin(degtorad(90) - data->raycaster->ray_one_a) * distance_y;
				find_next_case_y(data, ray_len, distance_y);
			}
			if (data->raycaster->pdx_ray < 0)
				distance_x -= 11;
			else if (data->raycaster->pdx_ray > 0)
				distance_x += 11;
			if (data->raycaster->pdy_ray < 0)
				distance_y -= 11;
			else if (data->raycaster->pdy_ray > 0)
				distance_y += 11;
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
