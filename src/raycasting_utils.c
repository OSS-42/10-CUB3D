/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/14 22:42:23 by ewurstei         ###   ########.fr       */
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

void	find_next_case_x(t_vault *data, float ray_len_x, int distance_x)
{
	int		x;
	int		y;
	float	opp_side_y;

	opp_side_y = ray_len_x * sin(data->raycaster->ray_one_a);
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
	if (y < 0 || y > data->map->lines * 11 || opp_side_y < 11
		|| opp_side_y > data->map->lines * 11)
		y = data->player->py;
	data->raycaster->next_x = x;
	data->raycaster->next_y = y;
}

void	find_next_case_y(t_vault *data, float ray_len_y, int distance_y)
{
	int		x;
	int		y;
	float	opp_side_x;

	opp_side_x = ray_len_y * sin(data->raycaster->ray_one_a);
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
}

int	wall_in_next_case(t_vault *data)
{
	printf("x = %d y = %d\n", data->raycaster->next_y, data->raycaster->next_x);
	if (data->map->map[data->raycaster->next_y][data->raycaster->next_x] == '1')
		return(TRUE);
	return (FALSE);
}
