/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/17 10:43:16 by ewurstei         ###   ########.fr       */
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
	while (temp % 65 != 0)
	{
		if (data->raycaster->pdx_ray < 0)
			temp--;
		else if (data->raycaster->pdx_ray > 0)
			temp++;
		else if (data->raycaster->pdx_ray == 0)
			temp = (int)data->player->ppx;
	}
	temp = temp - (int)data->player->ppx;
	return (temp);
}

int	pix_to_intersection_y(t_vault *data)
{
	int	temp;

	temp = (int)data->player->ppy;
	while (temp % 65 != 0)
	{
		if (data->raycaster->pdy_ray < 0)
			temp--;
		else if (data->raycaster->pdy_ray > 0)
			temp++;
		else if (data->raycaster->pdy_ray == 0)
			temp = (int)data->player->ppy;
	}
	temp = temp - (int)data->player->ppy;
	return (temp);
}

void	find_next_case(t_vault *data, int distance_x, int distance_y)
{
	int		col;
	int		row;

	if (data->raycaster->pdx_ray == 0)
		col = data->raycaster->next_y;
	else
		col = distance_x / 65;
	if (data->raycaster->pdy_ray == 0)
		row = data->raycaster->next_x;
	else
		row = distance_y / 65;
	if (col > data->map->max_lenght)
		col = col - 1;
	else if (col < 0)
		col = col + 1;
	else if (row > data->map->lines)
		row = row - 1;
	else if (row < 0)
		row = row + 1;
	printf("coordonnees case 2D a verifier:\nmap_x =	%d\nmap_y =	%d\n", row, col);
	printf("\n GROS normal \n");
	data->raycaster->next_x = row;
	data->raycaster->next_y = col;
	printf("nouvelles coordonnees case 2D a verifier:\nmap_x =	%d\nmap_y =	%d\n", data->raycaster->next_x, data->raycaster->next_y);
	printf("valeur case : %c\n", data->map->map[row][col]);
}

// void	find_next_case_y(t_vault *data, float ray_len_y, int distance_y)
// {
// 	int		x;
// 	int		y;
// 	float	opp_side_x;

// 	opp_side_x = ray_len_y * sin(degtorad(90) - data->raycaster->ray_one_a);
// 	if (data->raycaster->pdx_ray == 0)
// 		x = data->player->px;
// 	else
// 		x = (data->player->ppx + distance_y) / 11;
// 	if (data->raycaster->pdy_ray == 0)
// 		y = data->player->py;
// 	else
// 		y = (data->player->ppy + opp_side_x) / 11;
// 	if (x < 0 || x > data->map->max_lenght * 11 || opp_side_x < 11
// 		|| opp_side_x > data->map->lines * 11)
// 		x = data->player->px;
// 	if (y < 0 || y > data->map->lines * 11)
// 		y = data->player->py;
// 	data->raycaster->next_x = x;
// 	data->raycaster->next_y = y;
// }

int	wall_in_next_case(t_vault *data, int x, int y)
{
	if (data->map->map[x][y] == '1')
	{
		printf("Suis-je un mur ? ... ");
		printf("\033[1;32m");
		printf("OUI\n");
		printf("\033[1;0m");
		return (TRUE);
	}
	printf("Suis-je un mur ? ... ");
	printf("\033[1;91m");
	printf("NON\n");
	printf("\033[1;0m");
	return (FALSE);
}
