/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 21:39:40 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/11 22:34:27 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_minimap(t_vault *data)
{
	data->minimap->minimap = mlx_new_image(data->mlx, data->map->max_lenght * 11, data->map->lines * 11);
	draw_minimap(data);
	//contours MINIMAP
	full_line_minimap_hor(data, 0, 0xFF00FFFF);
	full_line_minimap_ver(data, 0, 0xFF00FFFF);
	full_line_minimap_ver(data, data->map->max_lenght * 11 - 1, 0xFF00FFFF);
	full_line_minimap_hor(data, data->map->lines * 11 - 1, 0xFF00FFFF);
	mlx_image_to_window(data->mlx, data->minimap->minimap, 0, data->height - data->map->lines * 11);
}

void	draw_minimap(t_vault *data)
{
	data->minimap->x = 0;
	while (data->minimap->x < data->map->lines)
	{
		data->minimap->y = 0;
		while (data->minimap->y < data->map->max_lenght)
		{
			if (data->map->map[data->minimap->x][data->minimap->y] == '1')
				draw_tiles(data, data->minimap->x * 11, data->minimap->y * 11, 0xFFFFFFFF);
			else if (ft_char_isinset("0", data->map->map[data->minimap->x][data->minimap->y]) == TRUE)
				draw_tiles(data, data->minimap->x * 11, data->minimap->y * 11, 0x6E99FFFF);
			else if (ft_char_isinset("NSEW", data->map->map[data->minimap->x][data->minimap->y]) == TRUE)
			{
				draw_tiles(data, data->minimap->x * 11, data->minimap->y * 11, 0x6E99FFFF);
				data->map->map[data->minimap->x][data->minimap->y] = '0';
			}
			else if (data->map->map[data->minimap->x][data->minimap->y] == '2')
				draw_tiles(data, data->minimap->x * 11, data->minimap->y * 11, 0x000000FF);
			data->minimap->y++;
		}
		data->minimap->x++;
	}
}

void	draw_tiles(t_vault *data,
			int screen_x, int screen_y, unsigned int color)
{
	int	rows;
	int	cols;
	int	end_x;
	int	end_y;

	rows = screen_y;
	end_x = screen_x + 10;
	end_y = screen_y + 10;
	while (rows < end_y)
	{
		cols = screen_x;
		while (cols < end_x)
		{
			mlx_put_pixel(data->minimap->minimap, rows, cols, color);
			cols++;
		}
		rows++;
	}
}

void	full_line_minimap_hor(t_vault *data, int screen_y, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->max_lenght * 11;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, start, screen_y, color);
		start++;
	}
}

void	full_line_minimap_ver(t_vault *data, int screen_x, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->lines * 11;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, screen_x, start, color);
		start++;
	}
}