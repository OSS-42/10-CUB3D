/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/17 12:28:19 by ewurstei         ###   ########.fr       */
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
	data->raycaster->ray_one_a = data->player->pa - degtorad(32);
	while(data->raycaster->ray_count < 64)
	{
		printf("\033[1;91m");
		printf("\n\n########### NOUVEAU RAYON #%d ###########\n\n", data->raycaster->ray_count);
		printf("\033[1;0m");
		data->raycaster->next_x = data->player->ppy / 65;
		data->raycaster->next_y = data->player->ppx / 65;
		find_ray_angle(data);
		printf("angle pa : %f°\n", data->player->pa * 57.29578);
		printf("ray_one_a: %f°\n", data->raycaster->ray_one_a * 57.29578);
		distance_x = pix_to_intersection_x(data);
		distance_y = pix_to_intersection_y(data);
		printf("\ncoordonnees depart:\nppx =	%f\nppy =	%f\n", data->player->ppx, data->player->ppy);
		printf("\ncoordonnees depart:\npx =	%d\npy =	%d\n", data->raycaster->next_x, data->raycaster->next_y);
		while (wall_in_next_case(data, data->raycaster->next_x, data->raycaster->next_y) == FALSE)
		{
			printf("\33[1;96m");
			printf("\n--------- NOUVELLE COMPARAISON ---------\n");
			printf("\033[1;0m");
			printf("distance_x :	%d pixels\n", distance_x);
			printf("distance_y :	%d pixels\n", distance_y);
			ray_len_x = distance_x / cos(data->raycaster->ray_one_a);
			if (ray_len_x < 0)
				ray_len_x = -1 * ray_len_x;
			ray_len_y = distance_y / cos(degtorad(90) - data->raycaster->ray_one_a);
			if (ray_len_y < 0)
				ray_len_y = -1 * ray_len_y;
			printf("ray_len_x =	%f pixels\n", ray_len_x);
			printf("ray_len_y =	%f pixels\n", ray_len_y);
			if (ray_len_x < ray_len_y)
			{
				printf("\033[1;93m");
				printf("\nINTERCEPTION EN X -> RAY_LEN_X est le plus court\n");
				printf("\033[1;0m");
				ray_len = ray_len_x;
				printf("ray_len :	%f pixels\n", ray_len);
				opp_side = ray_len * sin(data->raycaster->ray_one_a);
				if (data->raycaster->pdx_ray < 0)
				{
					printf("coordonnees d'intersection :\nsur les x =	%f\nsur les y =	%f\n",
					 data->player->ppx + distance_x, data->player->ppy + opp_side);
					find_next_case(data, data->player->ppx + distance_x - 65, data->player->ppy + opp_side);
					ray_len = ray_len + 1;
				}
				else
				{
					printf("coordonnees d'intersection :\nsur les x =	%f\nsur les y =	%f\n",
					 data->player->ppx + distance_x, data->player->ppy + opp_side);
					find_next_case(data, data->player->ppx + distance_x, data->player->ppy + opp_side);
					ray_len = ray_len - 1;
				}
				if (data->raycaster->pdx_ray < 0)
					distance_x -= 65;
				else if (data->raycaster->pdx_ray > 0)
					distance_x += 65;
			}
			else
			{
				printf("\033[1;93m");
				printf("\nINTERCEPTION EN Y -> RAY_LEN_Y est le plus court\n");
				printf("\033[1;0m");
				ray_len = ray_len_y;
				printf("ray_len :	%f pixels\n", ray_len);
				opp_side = ray_len * sin(degtorad(90) - data->raycaster->ray_one_a);
				if (data->raycaster->pdy_ray < 0)
				{
					printf("coordonnees d'intersection :\nsur les x =	%f\nsur les y =	%f\n",
					 data->player->ppx + opp_side, data->player->ppy + distance_y);
					find_next_case(data, data->player->ppx + opp_side, data->player->ppy + distance_y - 65);
					ray_len = ray_len + 1;
				}
				else
				{
					printf("coordonnees d'intersection :\nsur les x =	%f\nsur les y =	%f\n",
					 data->player->ppx + opp_side, data->player->ppy + distance_y);
					find_next_case(data, data->player->ppx + opp_side, data->player->ppy + distance_y);
					ray_len = ray_len - 1;
				}
				if (data->raycaster->pdy_ray < 0)
					distance_y -= 65;
				else if (data->raycaster->pdy_ray > 0)
					distance_y += 65;
			}
		}
		draw_ray(data, ray_len);
		data->raycaster->ray_one_a = data->raycaster->ray_one_a + degtorad(1);
		data->raycaster->ray_count++;
	}
	data->raycaster->ray_count = 0;
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
	data->raycaster->pdx_ray = cos(data->raycaster->ray_one_a);
	data->raycaster->pdy_ray = sin(data->raycaster->ray_one_a);
}
