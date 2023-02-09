/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/02/09 10:12:16 by ewurstei         ###   ########.fr       */
=======
/*   Updated: 2023/02/09 11:42:43 by ewurstei         ###   ########.fr       */
>>>>>>> mbertin
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_minimap(t_vault *data)
{
	data->minimap->x = 0;
	data->minimap->img_y = 0;
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
				player_pixels(data, data->map->map[data->minimap->x][data->minimap->y]);
				data->map->map[data->minimap->x][data->minimap->y] = '0';
			}
			data->minimap->y++;
			data->minimap->img_x += 11;
		}
		data->minimap->x++;
		data->minimap->img_y += 11;
	}
	// param_to_window(data);
}

<<<<<<< HEAD
// void	param_to_window(t_vault *data)
// {
=======
void	param_to_window(t_vault *data)
{
	(void)data;
>>>>>>> mbertin
	// mlx_put_string(data->mlx, "Px = ", data->map->lines * 11 + 10, 10);
	// // mlx_put_string(data->mlx, ftoa(data->player->px), data->map->lines * 11 + 10, 20);
	// mlx_put_string(data->mlx, "Py = ", data->map->lines * 11 + 20, 10);
	// // mlx_put_string(data->mlx, ftoa(data->player->py), data->map->lines * 11 + 10, 20);
	// mlx_put_string(data->mlx, "Pa = ", data->map->lines * 11 + 30, 10);
	// // mlx_put_string(data->mlx, ftoa(data->player->pa), data->map->lines * 11 + 10, 20);
	// mlx_put_string(data->mlx, "PDx = ", data->map->lines * 11 + 40, 10);
	// // mlx_put_string(data->mlx, ftoa(data->player->pdx), data->map->lines * 11 + 10, 20);
	// mlx_put_string(data->mlx, "PDy = ", data->map->lines * 11 + 50, 10);
	// mlx_put_string(data->mlx, ftoa(data->player->pdy), data->map->lines * 11 + 10, 20);
// }