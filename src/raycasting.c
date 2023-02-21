/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/20 15:15:42 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	double	delta_dist_x;
	double	delta_dist_y;
	double	ray_len_x;
	double	ray_len_y;
	double	ray_len;
	int		opp_side_x;
	int		opp_side_y;
	int		map_2d_col;
	int		map_2d_row;
	int		col;
	int		row;
	int		side;

	ray_len = 0;
	side = 0;
	col = data->player->px;
	row = data->player->py;
	delta_dist_x = 0;
	delta_dist_y = 0;
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
		ray_len_x = ray_seg_len_x(data, data->player->ppx, 'P');
		ray_len_y = ray_seg_len_y(data, data->player->ppy, 'P');
		printf("longueur du rayon x la premiere fois : %f\n", ray_len_x);
		printf("longueur du rayon y la premiere fois : %f\n", ray_len_y);
		opp_side_x = ray_len_x * sin(degtorad(90) - data->raycaster->ray_one_a);
		opp_side_y = ray_len_y * sin(data->raycaster->ray_one_a);
		printf("ppx : %d\n", data->player->ppx);
		printf("ppy : %d\n", data->player->ppy);
		if (data->raycaster->pdx_ray < 0)
		{
			map_2d_col = -1;
			delta_dist_x = ray_seg_len_x(data, data->player->ppx - opp_side_x, 'R');
		}
		else if (data->raycaster->pdx_ray > 0)
		{
			map_2d_col = 1;
			delta_dist_x = ray_seg_len_x(data, data->player->ppx + opp_side_x, 'R');
		}
		if (data->raycaster->pdy_ray < 0)
		{
			map_2d_row = -1;
			delta_dist_y = ray_seg_len_y(data, data->player->ppy - opp_side_y, 'R');
		}
		else if (data->raycaster->pdy_ray > 0)
		{
			map_2d_row = 1;
			delta_dist_y = ray_seg_len_y(data, data->player->ppy + opp_side_y, 'R');
		}
		printf("longueur de delta x la premiere fois : %f\n", delta_dist_x);
		printf("longueur de delta y la premiere fois : %f\n", delta_dist_y);
		printf("\ncoordonnees depart:\nppx =	%d\nppy =	%d\n", data->player->ppx, data->player->ppy);
		printf("\ncoordonnees depart:\npx =	%d\npy =	%d\n", data->raycaster->next_x, data->raycaster->next_y);
		while (wall_in_next_case(data, row, col) == FALSE)
		{
			printf("\33[1;96m");
			printf("\n--------- NOUVELLE COMPARAISON ---------\n");
			printf("\033[1;0m");
			if (ray_len_x < ray_len_y)
			{
				printf("\033[1;93m");
				printf("\nINTERCEPTION EN X -> RAY_LEN_X est le plus court\n");
				printf("\033[1;0m");
				ray_len_x += delta_dist_x;
				printf("ray_len_x dans la boucle = %f\n", ray_len_x);
				col += map_2d_col;
				side = 0;
				ray_len = ray_len_x;
			}
			else
			{
				printf("\033[1;93m");
				printf("\nINTERCEPTION EN Y -> RAY_LEN_Y est le plus court\n");
				printf("\033[1;0m");
				ray_len_y += delta_dist_y;
				printf("ray_len_y dans la boucle = %f\n", ray_len_y);
				row += map_2d_row;
				side = 1;
				ray_len = ray_len_y;
			}
		}
		printf("Valeur final de ray_len : %f\n", ray_len);
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


// void	raycaster(t_vault *data)
// {
// 	double	delta_dist_x;
// 	double	delta_dist_y;
// 	double	ray_len_x;
// 	double	ray_len_y;
// 	double	ray_len;
// 	int		opp_side_x;
// 	int		opp_side_y;
// 	int		map_2d_col;
// 	int		map_2d_row;
// 	int		col;
// 	int		row;
// 	int		side;

// 	ray_len = 0;
// 	side = 0;
// 	col = data->player->px;
// 	row = data->player->py;
// 	delta_dist_x = 0;
// 	delta_dist_y = 0;
// 	data->raycaster->ray_one_a = data->player->pa - degtorad(32);
// //	while(data->raycaster->ray_count < 64)
// //	{
// 		data->raycaster->next_x = data->player->ppy / 65;
// 		data->raycaster->next_y = data->player->ppx / 65;
// 		find_ray_angle(data);
// 		ray_len_x = ray_seg_len_x(data, data->player->ppx, 'P');
// 		ray_len_y = ray_seg_len_y(data, data->player->ppy, 'P');
// 		opp_side_x = ray_len_x * sin(degtorad(90) - data->raycaster->ray_one_a);
// 		opp_side_y = ray_len_y * sin(data->raycaster->ray_one_a);
// 		if (data->raycaster->pdx_ray < 0)
// 		{
// 			map_2d_col = -1;
// 			delta_dist_x = ray_seg_len_x(data, data->player->ppx - opp_side_x, 'R');
// 		}
// 		else if (data->raycaster->pdx_ray > 0)
// 		{
// 			map_2d_col = 1;
// 			delta_dist_x = ray_seg_len_x(data, data->player->ppx + opp_side_x, 'R');
// 		}
// 		if (data->raycaster->pdy_ray < 0)
// 		{
// 			map_2d_row = -1;
// 			delta_dist_y = ray_seg_len_y(data, data->player->ppy - opp_side_y, 'R');
// 		}
// 		else if (data->raycaster->pdy_ray > 0)
// 		{
// 			map_2d_row = 1;
// 			delta_dist_y = ray_seg_len_y(data, data->player->ppy + opp_side_y, 'R');
// 		}
// 		while (wall_in_next_case(data, row, col) == FALSE)
// 		{
// 			if (ray_len_x < ray_len_y)
// 			{
// 				ray_len_x += delta_dist_x;
// 				col += map_2d_col;
// 				side = 0;
// 				ray_len = ray_len_x;
// 			}
// 			else
// 			{
// 				ray_len_y += delta_dist_y;
// 				row += map_2d_row;
// 				side = 1;
// 				ray_len = ray_len_y;
// 			}
// 		}
// 		draw_ray(data, ray_len);
// //		data->raycaster->ray_one_a = data->raycaster->ray_one_a + degtorad(1);
// //		data->raycaster->ray_count++;
// //	}
// 	data->raycaster->ray_count = 0;
// }


// void	raycaster(t_vault *data)
// {
// 	double	delta_dist_x;
// 	double	delta_dist_y;
// 	double	ray_len_x;
// 	double	ray_len_y;
// 	double	ray_len;
// 	// int		opp_side_x;
// 	// int		opp_side_y;
// 	int		map_2d_col;
// 	int		map_2d_row;
// 	int		col;
// 	int		row;
// 	int		side;
// 	int		pp_seg_y;
// 	int		pp_seg_x;
// 	int		adj_x;
// 	int		adj_y;

// 	ray_len = 0;
// 	side = 0;
// 	col = data->player->px;
// 	row = data->player->py;
// 	delta_dist_x = 0;
// 	delta_dist_y = 0;
// 	data->raycaster->ray_one_a = data->player->pa - degtorad(32);
// 	pp_seg_x = data->player->ppx % 65;
// 	pp_seg_y = data->player->ppy % 65;
// //	while(data->raycaster->ray_count < 64)
// //	{
// 		data->raycaster->next_x = data->player->ppy / 65;
// 		data->raycaster->next_y = data->player->ppx / 65;
// 		find_ray_angle(data);
// 		ray_len_x = ray_seg_len_x(data, data->player->ppx, 'P');
// 		ray_len_y = ray_seg_len_y(data, data->player->ppy, 'P');
// 		// opp_side_x = ray_len_x * sin(degtorad(90) - data->raycaster->ray_one_a);
// 		// opp_side_y = ray_len_y * sin(data->raycaster->ray_one_a);
// 		if (data->raycaster->pdx_ray < 0)
// 		{
// 			map_2d_col = -1;

// 			delta_dist_x = ray_seg_len_x(data, data->player->ppx - opp_side_x, 'R');
// 		}
// 		else if (data->raycaster->pdx_ray > 0)
// 		{
// 			map_2d_col = 1;
// 			delta_dist_x = ray_seg_len_x(data, data->player->ppx + opp_side_x, 'R');
// 		}
// 		if (data->raycaster->pdy_ray < 0)
// 		{
// 			map_2d_row = -1;
// 			delta_dist_y = ray_seg_len_y(data, data->player->ppy - opp_side_y, 'R');
// 		}
// 		else if (data->raycaster->pdy_ray > 0)
// 		{
// 			map_2d_row = 1;
// 			delta_dist_y = ray_seg_len_y(data, data->player->ppy + opp_side_y, 'R');
// 		}
// 		while (wall_in_next_case(data, row, col) == FALSE)
// 		{
// 			if (ray_len_x < ray_len_y)
// 			{
// 				ray_len_x += delta_dist_x;
// 				col += map_2d_col;
// 				side = 0;
// 				ray_len = ray_len_x;
// 			}
// 			else
// 			{
// 				ray_len_y += delta_dist_y;
// 				row += map_2d_row;
// 				side = 1;
// 				ray_len = ray_len_y;
// 			}
// 		}
// 		draw_ray(data, ray_len);
// //		data->raycaster->ray_one_a = data->raycaster->ray_one_a + degtorad(1);
// //		data->raycaster->ray_count++;
// //	}
// 	data->raycaster->ray_count = 0;
// }