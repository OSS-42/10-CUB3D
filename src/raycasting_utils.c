/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/14 11:51:51 by mbertin          ###   ########.fr       */
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

void	ray_len_calculator_x(t_vault *data, int distance_x)
{
	int		next_case_x;
	int		next_case_y;
	float	opp_side_y;
	float	ray_len;

	ray_len = distance_x / cos(data->raycaster->ray_one_a);
	opp_side_y = ray_len * sin(data->raycaster->ray_one_a);
	if (data->raycaster->pdx_ray == 0)
		next_case_x = data->player->px;
	else
		next_case_x = (data->player->ppx + distance_x - 4) / 11;
	if (data->raycaster->pdy_ray == 0)
		next_case_y = data->player->py;
	else
		next_case_y = (data->player->ppy + opp_side_y - 4) / 11;
	if (next_case_x < 0 || next_case_x > data->map->max_lenght * 11)
		next_case_x = data->player->px;
	if (next_case_y < 0 || next_case_y > data->map->lines * 11 || opp_side_y < 11 || opp_side_y > data->map->lines * 11)
		next_case_y = data->player->py;
	// printf("%d\n", distance_x);
	printf("Dans ray_len_calculator_x : \n");
	printf("ray_len : %f\n", ray_len);
	printf("position x du joueur = %.3f\n", data->player->px);
	printf("position y du joueur = %.3f\n", data->player->py);
	printf("prochaine case x = %d\n", next_case_x);
	printf("prochaine case y = %d\n", next_case_y);
}

void	ray_len_calculator_y(t_vault *data, int distance_y)
{
	int		next_case_x;
	int		next_case_y;
	float	opp_side_x;
	float	ray_len;

	ray_len = sin(data->raycaster->ray_one_a) / distance_y;
	opp_side_x = ray_len * sin(data->raycaster->ray_one_a);
	if (data->raycaster->pdx_ray == 0)
		next_case_x = data->player->px;
	else
		next_case_x = (data->player->ppx + distance_y - 4) / 11;
	if (data->raycaster->pdy_ray == 0)
		next_case_y = data->player->py;
	else
		next_case_y = (data->player->ppy + opp_side_x - 4) / 11;
	if (next_case_x < 0 || next_case_x > data->map->max_lenght * 11 || opp_side_x < 11 || opp_side_x > data->map->lines * 11)
		next_case_x = data->player->px;
	if (next_case_y < 0 || next_case_y > data->map->lines * 11)
		next_case_y = data->player->py;
	// printf("%d\n", distance_x);
	printf("Dans ray_len_calculator_y : \n");
	printf("ray_len : %f\n", ray_len);
	printf("position x du joueur = %.3f\n", data->player->px);
	printf("position y du joueur = %.3f\n", data->player->py);
	printf("prochaine case x = %d\n", next_case_x);
	printf("prochaine case y = %d\n", next_case_y);
}