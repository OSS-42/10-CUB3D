/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/07 11:10:50 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_map(t_vault *data)
{
	data->minimap->x = 0;
	data->minimap->img_x = 0;
	data->minimap->img_y = 0;
	while (data->minimap->x < data->lines)
	{
		data->minimap->y = 0;
		data->minimap->img_x = 0;
		printf("%s\n", data->map->map[data->minimap->x]);
		while (data->minimap->y	< (int)ft_strlen(data->map->map[data->minimap->x]))
		{
			if (data->map->map[data->minimap->x][data->minimap->y] == '1')
				mlx_image_to_window(data->mlx, data->lvl1->wall_img,
					data->minimap->img_x, data->minimap->img_y);
			else if (data->map->map[data->minimap->x][data->minimap->y] == '0'
				|| data->map->map[data->minimap->x][data->minimap->y] == ' ')
					mlx_image_to_window(data->mlx, data->lvl1->floor_img, //segfault a cet endroit
						data->minimap->img_x, data->minimap->img_y);
			data->minimap->y++;
			data->minimap->img_x += 10;
		}
		data->minimap->x++;
		data->minimap->img_y += 10;
	}
}
