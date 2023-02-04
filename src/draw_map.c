/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/03 23:18:18 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_map(t_vault *data)
{
	data->minimap->x = 0;
	data->minimap->img_x = 0;
	data->minimap->img_y = 0;
	while (data->minimap->x < data->lines - 1)
	{
		while (data->minimap->y
			< (int)ft_strlen(data->map->map[data->minimap->x] - 1))
		{
			if (data->map->map[data->minimap->x][data->minimap->y] == '1')
				mlx_image_to_window(data->mlx, data->minimap->wall,
					data->minimap->y, data->minimap->img_y);
			else if (data->map->map[data->minimap->x][data->minimap->y] == '.'
				|| data->map->map[data->minimap->x][data->minimap->y] == ' ')
				mlx_image_to_window(data->mlx, data->minimap->floor,
					data->minimap->y, data->minimap->img_y);
			data->minimap->y++;
		}
		data->minimap->x++;
		data->minimap->img_x = 0;
		data->minimap->img_y = data->minimap->img_y + 1;
	}
}
