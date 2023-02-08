/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:25:27 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/07 21:22:36 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_minimap(t_vault *data)
{
	if (!data->minimap)
		return ;
	data->minimap->wall = mlx_load_xpm42("./assets/minimap_wall.xpm42");
	data->lvl1->wall_img
		= mlx_texture_to_image(data->mlx, &data->minimap->wall->texture);
	data->minimap->floor = mlx_load_xpm42("./assets/minimap_floor.xpm42");
	data->lvl1->floor_img
		= mlx_texture_to_image(data->mlx, &data->minimap->floor->texture);
	draw_map(data);
}
