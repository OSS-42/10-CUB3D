/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:25:27 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/04 10:16:03 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_minimap(t_vault *data)
{
	if (!data->minimap)
		return ;
	data->minimap->wall = mlx_load_xpm42("assets/minimap_wall.xpm42");
	data->minimap->floor = mlx_load_xpm42("assets/minimap_floor.xpm42");
	draw_map(data);
}
