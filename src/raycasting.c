/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/15 22:24:50 by ewurstei         ###   ########.fr       */
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
	float	opp_side;

	ray_len = 0;
	data->raycaster->ray_one_a = data->player->pa - degtorad(30);
	data->raycaster->next_x = data->player->start_y;
	data->raycaster->next_y = data->player->start_x;
	// while(data->raycaster->ray_count < 60)
	// {
		printf("########### NOUVEAU RAYON ###########\n");
		find_ray_angle(data);
		distance_x = pix_to_intersection_x(data);
		distance_y = pix_to_intersection_y(data);
		printf("coordonnees depart: ppx = %f, ppy = %f\n", data->player->ppx, data->player->ppy);
		while (wall_in_next_case(data) == FALSE)
		{
			printf("--------- NOUVELLE COMPARAISON ---------\n");
			printf("distance_x : %d\n", distance_x);
			printf("distance_y : %d\n", distance_y);
			ray_len_x = distance_x / cos(data->raycaster->ray_one_a);
			if (ray_len_x < 0)
				ray_len_x = -1 * ray_len_x;
			ray_len_y = distance_y / cos(degtorad(90) - data->raycaster->ray_one_a);
			if (ray_len_y < 0)
				ray_len_y = -1 * ray_len_y;
			if (ray_len_x <= ray_len_y)
			{
				printf("INTERCEPTION EN X -> RAY_LEN_X est le plus court\n");
				ray_len = ray_len_x;
				printf("ray_len : %f\n", ray_len);
				opp_side = ray_len * sin(data->raycaster->ray_one_a);
				if (data->raycaster->pdx_ray < 0)
				{
					printf("coordonnees d'intersection : x_pxl = %f, y_pxl = %f\n",
					 data->player->ppx + distance_x, data->player->ppy + (-1 * opp_side));
					find_next_case(data, -1 * opp_side, distance_x - 11);
				}
				else
				{
					printf("coordonnees d'intersection : x_pxl = %f, y_pxl = %f\n",
					 data->player->ppx + distance_x, data->player->ppy + opp_side);
					find_next_case(data, opp_side, distance_x);
				}
				if (data->raycaster->pdx_ray < 0)
					distance_x -= 11;
				else if (data->raycaster->pdx_ray > 0)
					distance_x += 11;
			}
			else if (ray_len_x > ray_len_y)
			{
				printf("INTERCEPTION EN Y -> RAY_LEN_Y est le plus court\n");
				ray_len = ray_len_y;
				printf("ray_len : %f\n", ray_len);
				opp_side = ray_len * sin(degtorad(90) - data->raycaster->ray_one_a);
				if (data->raycaster->pdy_ray < 0)
				{
					printf("coordonnees d'intersection : x_pxl = %f, y_pxl = %f\n",
					 data->player->ppx + (-1 * opp_side), data->player->ppy + distance_y);
					find_next_case(data, distance_y - 11, -1 * opp_side);
				}
				else
				{
					printf("coordonnees d'intersection : x_pxl = %f, y_pxl = %f\n",
					 data->player->ppx + opp_side, data->player->ppy + distance_y);
					find_next_case(data, distance_y, opp_side);
				}
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
