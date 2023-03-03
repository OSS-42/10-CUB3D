/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_textures_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:46:07 by maison            #+#    #+#             */
/*   Updated: 2023/03/02 21:25:13 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_type_wall(t_vault *data, int *impact)
{
	if (data->map->map[data->raycaster->row][data->raycaster->col] == '1')
		*impact = 1;
	else if (data->map->map[data->raycaster->row][data->raycaster->col]
		== '2')
	{
		*impact = 1;
		if (data->raycaster->side == 0)
			data->raycaster->side = 5;
		else if (data->raycaster->side == 1)
			data->raycaster->side = 4;
		else if (data->raycaster->side == 2)
			data->raycaster->side = 6;
		else if (data->raycaster->side == 3)
			data->raycaster->side = 7;
	}
	else
		check_bonus_type_wall(data, impact);
}

void	check_bonus_type_wall(t_vault *data, int *impact)
{
	if (data->map->map[data->raycaster->row][data->raycaster->col] == 'D')
		check_type_wall_D(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '3')
		check_type_wall_3(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '4')
		check_type_wall_4(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '5')
		check_type_wall_5(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '6')
		check_type_wall_6(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '7')
		check_type_wall_7(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '8')
		check_type_wall_8(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == '9')
		check_type_wall_9(data, impact);
	else if (data->map->map[data->raycaster->row][data->raycaster->col] == 'Z')
		check_type_wall_Z(data, impact);
}

// side = 0 -> on touche (regarde) le mur EST (E)
// side = 1 -> OUEST (W)
// side = 2 -> SUD (S)
// side = 3 -> NORD (N)

void	check_type_wall_D(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 8;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 9;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 10;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 11;
}

void	check_type_wall_3(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 12;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 13;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 14;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 15;
}

void	check_type_wall_4(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 16;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 17;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 18;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 19;
}
