/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:39:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/23 16:29:20 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	show_minimap(t_vault *data)
{
	load_minimap(data);
	draw_minimap(data);
	draw_player(data);
}

void	load_minimap(t_vault *data)
{
	if (data->map->max_lenght < data->map->lines)
		data->minimap->tile_size = HEIGHT / 48;
	else
		data->minimap->tile_size = WIDTH / 48;
	data->minimap->minimap = mlx_new_image(data->mlx,
			data->map->max_lenght * data->minimap->tile_size,
			data->map->lines * data->minimap->tile_size);
	mlx_image_to_window(data->mlx,
		data->minimap->minimap,
		(WIDTH - data->map->max_lenght * data->minimap->tile_size),
		(HEIGHT / 2) - (data->map->lines * data->minimap->tile_size / 2));
}
		// (WIDTH / 2) - (data->map->max_lenght * data->minimap->tile_size / 2),

void	draw_minimap(t_vault *data)
{
	int	i;

	i = 0;
	while (i < data->map->lines * data->minimap->tile_size)
	{
		full_line_minimap_hor(data, i, DGRAY);
		i++;
	}
	data->minimap->x = 0;
	while (data->minimap->x < data->map->lines)
	{
		data->minimap->y = 0;
		draw_tiles_loop(data, 0, 0);
		data->minimap->x++;
	}
	full_line_minimap_hor(data, 0, 0xFF00FFFF);
	full_line_minimap_ver(data, 0, 0xFF00FFFF);
	full_line_minimap_ver(data, data->map->max_lenght
		* data->minimap->tile_size - 1, 0xFF00FFFF);
	full_line_minimap_hor(data, data->map->lines
		* data->minimap->tile_size - 1, 0xFF00FFFF);
}

void	draw_tiles_loop(t_vault *data, int screen_x, int screen_y)
{
	while (data->minimap->y < data->map->max_lenght)
	{
		screen_x = data->minimap->x * data->minimap->tile_size;
		screen_y = data->minimap->y * data->minimap->tile_size;
		if (data->map->map[data->minimap->x][data->minimap->y] == '0'
			|| data->map->map[data->minimap->x][data->minimap->y] == 'W')
			draw_tiles(data, screen_x, screen_y, 0x6E99FFFF);
		else if (is_not_wall_limited(data, data->minimap->x, data->minimap->y)
			== FALSE)
			draw_tiles(data, screen_x, screen_y, 0xFFFFFFFF);
		else if (data->map->map[data->minimap->x][data->minimap->y] == '.')
			draw_tiles(data, screen_x, screen_y, 0x000000FF);
		else if (data->map->map[data->minimap->x][data->minimap->y] == 'D')
			draw_tiles(data, screen_x, screen_y, 0x806040FF);
		else if (ft_char_isinset("NSEW", data->map->map[data->minimap->x]
				[data->minimap->y]) == TRUE)
			draw_tiles(data, screen_x, screen_y, 0x6E99FFFF);
		data->minimap->y++;
	}
}

void	reinit_minimap(t_vault *data)
{
	if (data->minimap->on_screen == 1)
	{
		mlx_delete_image(data->mlx, data->minimap->minimap);
		show_minimap(data);
	}
}
