/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_textures_bonus2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:23:18 by maison            #+#    #+#             */
/*   Updated: 2023/03/02 21:01:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

// side = 0 -> on touche (regarde) le mur EST (E)
// side = 1 -> OUEST (W)
// side = 2 -> SUD (S)
// side = 3 -> NORD (N)

void	check_type_wall_5(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 20;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 21;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 22;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 23;
}

void	check_type_wall_6(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 24;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 25;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 26;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 27;
}

void	check_type_wall_7(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 28;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 29;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 30;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 31;
}

void	check_type_wall_8(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 32;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 33;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 34;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 35;
}

void	check_type_wall_Z(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 36;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 37;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 38;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 39;
}

void	check_type_wall_9(t_vault *data, int *impact)
{
	*impact = 1;
	if (data->raycaster->side == 0)
		data->raycaster->side = 40;
	else if (data->raycaster->side == 1)
		data->raycaster->side = 41;
	else if (data->raycaster->side == 2)
		data->raycaster->side = 42;
	else if (data->raycaster->side == 3)
		data->raycaster->side = 43;
}
