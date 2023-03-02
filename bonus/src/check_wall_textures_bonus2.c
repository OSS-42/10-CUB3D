/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_textures_bonus2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 08:23:18 by maison            #+#    #+#             */
/*   Updated: 2023/03/02 09:54:52 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

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
