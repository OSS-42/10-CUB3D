/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/18 09:36:41 by ewurstei         ###   ########.fr       */
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

void	find_next_case(t_vault *data, int intersec_x, int intersec_y, char flag)
{
	int		col;
	int		row;

	// si rayons verticaux ou horizontaux parfaitement
	if (data->raycaster->pdx_ray == 0)
		col = data->raycaster->next_y;
	else
		col = intersec_x / 65;
	if (data->raycaster->pdy_ray == 0)
		row = data->raycaster->next_x;
	else
		row = intersec_y / 65;

	// si rayon out of bounds
	// if (col > data->map->max_lenght)
	// 	col = col - 1;
	// else if (col < 0)
	// 	col = col + 1;
	// else if (row > data->map->lines)
	// 	row = row - 1;
	// else if (row < 0)
	// 	row = row + 1;

	// si rayons regardent en arriere, decaler le check de la case de -1
	// (void)flag;
	if (data->raycaster->pdy_ray < 0 && flag == 'Y')
		row = row - 1;
	if (data->raycaster->pdx_ray < 0 && flag == 'X')
		col = col - 1;
	// else if (data->raycaster->pdx_ray < 0 && flag == 'X')
	// 	col = col - 1;
	// else if (data->raycaster->pdx_ray < 0 && flag == 'Y')
		
		
	printf("coordonnees case 2D a verifier:\nmap_x =	%d\nmap_y =	%d\n", row, col);
	printf("\n GROS normal \n");
	data->raycaster->next_x = row;
	data->raycaster->next_y = col;
	printf("nouvelles coordonnees case 2D a verifier:\nmap_x =	%d\nmap_y =	%d\n", data->raycaster->next_x, data->raycaster->next_y);
	printf("valeur case : %c\n", data->map->map[row][col]);
}

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
