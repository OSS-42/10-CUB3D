/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_textures_bonus3.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:49:51 by maison            #+#    #+#             */
/*   Updated: 2023/03/05 11:53:36 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_type_wall_z(t_vault *data, int *impact)
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
