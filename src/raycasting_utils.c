/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/14 14:27:39 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

int	pix_to_intersection_x(t_vault *data)
{
	int	temp;

	temp = (int)data->player->ppx;
	while (temp % 11 != 0)
	{
		if (data->raycaster->pdx_ray < 0)
			temp--;
		else if (data->raycaster->pdx_ray > 0)
			temp++;
	}
	temp = temp - (int)data->player->ppx;
	return (temp);
}

int	pix_to_intersection_y(t_vault *data)
{
	int	temp;

	temp = (int)data->player->ppy;
	while (temp % 11 != 0)
	{
		if (data->raycaster->pdy_ray < 0)
			temp--;
		else if (data->raycaster->pdy_ray > 0)
			temp++;
	}
	temp = temp - (int)data->player->ppy;
	return (temp);
}

float	ray_len_calculator_x(t_vault *data, int distance_x)
{
	int		x;
	int		y;
	float	opp_side_y;
	float	ray_len;

	ray_len = distance_x / cos(data->raycaster->ray_one_a);
	opp_side_y = ray_len * sin(data->raycaster->ray_one_a);
	if (data->raycaster->pdx_ray == 0)
		x = data->player->px;
	else
		x = (data->player->ppx + distance_x - 4) / 11;
	if (data->raycaster->pdy_ray == 0)
		y = data->player->py;
	else
		y = (data->player->ppy + opp_side_y - 4) / 11;
	if (x < 0 || x > data->map->max_lenght * 11)
		x = data->player->px;
	if (y < 0 || y > data->map->lines * 11 || opp_side_y < 11 || opp_side_y > data->map->lines * 11)
		y = data->player->py;
	data->raycaster->next_x = x;
	data->raycaster->next_y = y;
	// printf("%d\n", distance_x);
	// printf("Dans ray_len_calculator_x : \n");
	// printf("ray_len : %f\n", ray_len);
	// printf("position x du joueur = %.3f\n", data->player->px);
	// printf("position y du joueur = %.3f\n", data->player->py);
	// printf("prochaine case x = %d\n", x);
	// printf("prochaine case y = %d\n", y);
	return (ray_len);
}

float	ray_len_calculator_y(t_vault *data, int distance_y)
{
	int		x;
	int		y;
	float	opp_side_x;
	float	ray_len;

	ray_len = 1 / (sin(data->raycaster->ray_one_a) / distance_y);
	opp_side_x = ray_len * sin(data->raycaster->ray_one_a);
	if (data->raycaster->pdx_ray == 0)
		x = data->player->px;
	else
		x = (data->player->ppx + distance_y - 4) / 11;
	if (data->raycaster->pdy_ray == 0)
		y = data->player->py;
	else
		y = (data->player->ppy + opp_side_x - 4) / 11;
	if (x < 0 || x > data->map->max_lenght * 11 || opp_side_x < 11
		|| opp_side_x > data->map->lines * 11)
		x = data->player->px;
	if (y < 0 || y > data->map->lines * 11)
		y = data->player->py;
	data->raycaster->next_x = x;
	data->raycaster->next_y = y;
	// printf("%d\n", distance_x);
	// printf("Dans ray_len_calculator_y : \n");
	// printf("ray_len : %f\n", ray_len);
	// printf("position x du joueur = %.3f\n", data->player->px);
	// printf("position y du joueur = %.3f\n", data->player->py);
	// printf("prochaine case x = %d\n", x);
	// printf("prochaine case y = %d\n", y);
	return (ray_len);
}

int	wall_in_next_case(t_vault *data)
{
	if (data->map->map[data->raycaster->next_y][data->raycaster->next_x] == '1')
	{
		printf("Dans wall_in_array : map[x][y] = %c", data->map->map[data->raycaster->next_y][data->raycaster->next_x]);
		return(TRUE);
	}
	return (FALSE);
}
