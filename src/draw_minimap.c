/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/09 23:50:18 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_minimap(t_vault *data)
{
	data->minimap->x = 0;
	data->minimap->img_y = data->height - data->map->lines * 11;
	while (data->minimap->x < data->lines)
	{
		data->minimap->y = 0;
		data->minimap->img_x = 0;
		while (data->minimap->y
			< (int)ft_strlen(data->map->map[data->minimap->x]))
		{
			if (data->map->map[data->minimap->x][data->minimap->y] == '1')
				mlx_image_to_window(data->mlx, data->lvl1->wall_img,
					data->minimap->img_x, data->minimap->img_y);
			else if (ft_char_isinset("0", data->map->map[data->minimap->x][data->minimap->y]) == TRUE)
				mlx_image_to_window(data->mlx, data->lvl1->floor_img,
					data->minimap->img_x, data->minimap->img_y);
			else if (ft_char_isinset(" ", data->map->map[data->minimap->x][data->minimap->y]) == TRUE)
				mlx_image_to_window(data->mlx, data->lvl1->void_img,
					data->minimap->img_x, data->minimap->img_y);
			else if (ft_char_isinset("NSEW", data->map->map[data->minimap->x][data->minimap->y]) == TRUE)
			{
				mlx_image_to_window(data->mlx, data->lvl1->floor_img,
					data->minimap->img_x, data->minimap->img_y);
				find_orientation(data, data->map->map[data->minimap->x][data->minimap->y]);
				data->map->map[data->minimap->x][data->minimap->y] = '0';
				player_pixels(data);
			}
			data->minimap->y++;
			data->minimap->img_x += 11;
		}
		data->minimap->x++;
		data->minimap->img_y += 11;
	}
}
