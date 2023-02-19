/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/18 19:49:39 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	int		distance_x;
	int		distance_y;
	double	ray_len_x;
	double	ray_len_y;
	double	ray_len;
	int		opp_side;

	ray_len = 0;
	data->raycaster->ray_one_a = data->player->pa - degtorad(32);
//	while(data->raycaster->ray_count < 64)
//	{
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
		printf("\ncoordonnees depart:\nppx =	%d\nppy =	%d\n", data->player->ppx, data->player->ppy);
		printf("\ncoordonnees depart:\npx =	%d\npy =	%d\n", data->raycaster->next_x, data->raycaster->next_y);
		while (wall_in_next_case(data, data->raycaster->next_x, data->raycaster->next_y) == FALSE)
		{
			printf("\33[1;96m");
			printf("\n--------- NOUVELLE COMPARAISON ---------\n");
			printf("\033[1;0m");
			printf("dist & orient to x gridline:	%d pixels\n", distance_x);
			printf("dist & orient to y gridline:	%d pixels\n", distance_y);
			ray_len_x = fabs(distance_x / cos(data->raycaster->ray_one_a));
			ray_len_y = fabs(distance_y / cos(degtorad(90) - data->raycaster->ray_one_a));
			printf("ray_len_x =			%f pixels\n", ray_len_x);
			printf("ray_len_y =			%f pixels\n", ray_len_y);
			if (ray_len_x < ray_len_y)
			{
				printf("\033[1;93m");
				printf("\nINTERCEPTION EN X -> RAY_LEN_X est le plus court\n");
				printf("\033[1;0m");
				data->raycaster->last_ray_len = ray_len;
				ray_len = ray_len_x;
				printf("ray_len :			%f pixels\n", ray_len);
				opp_side = ray_len * sin(data->raycaster->ray_one_a);
				if (data->raycaster->pdx_ray < 0)
				{
					printf("coordonnees d'intersection :\nsur les x =			%d\nsur les y =			%d\n",
					 data->player->ppx + distance_x, data->player->ppy + opp_side);
					find_next_case(data, data->player->ppx + distance_x, data->player->ppy + opp_side, 'X');
				}
				else
				{
					printf("coordonnees d'intersection :\nsur les x =			%d\nsur les y =			%d\n",
					 data->player->ppx + distance_x, data->player->ppy + opp_side);
					find_next_case(data, data->player->ppx + distance_x, data->player->ppy + opp_side, 'X');
				}
				if (data->raycaster->pdx_ray < 0)
					distance_x -= 65;
				else
					distance_x += 65;
			}
			else
			{
				printf("\033[1;93m");
				printf("\nINTERCEPTION EN Y -> RAY_LEN_Y est le plus court\n");
				printf("\033[1;0m");
				data->raycaster->last_ray_len = ray_len;
				ray_len = ray_len_y;
				printf("ray_len :			%f pixels\n", ray_len);
				opp_side = ray_len * sin(degtorad(90) - data->raycaster->ray_one_a);
				if (data->raycaster->pdy_ray < 0)
				{
					printf("coordonnees d'intersection :\nsur les x =			%d\nsur les y =			%d\n",
					 data->player->ppx + opp_side, data->player->ppy + distance_y);
					find_next_case(data, data->player->ppx + opp_side, data->player->ppy + distance_y, 'Y');
				}
				else
				{
					printf("coordonnees d'intersection :\nsur les x =			%d\nsur les y =			%d\n",
					 data->player->ppx + opp_side, data->player->ppy + distance_y);
					find_next_case(data, data->player->ppx + opp_side, data->player->ppy + distance_y, 'Y');
				}
				if (data->raycaster->pdy_ray < 0)
					distance_y -= 65;
				else
					distance_y += 65;
			}
		}
		draw_ray(data, ray_len);
//		data->raycaster->ray_one_a = data->raycaster->ray_one_a + degtorad(1);
//		data->raycaster->ray_count++;
//	}
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
