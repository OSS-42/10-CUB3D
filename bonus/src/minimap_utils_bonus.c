/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 10:31:14 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/05 10:23:42 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	draw_tiles(t_vault *data,
			int screen_x, int screen_y, unsigned int color)
{
	int	rows;
	int	cols;
	int	end_x;
	int	end_y;

	rows = screen_y;
	end_x = screen_x + data->minimap->tile_size - 1;
	end_y = screen_y + data->minimap->tile_size - 1;
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
	len = data->map->max_lenght * data->minimap->tile_size;
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
	len = data->map->lines * data->minimap->tile_size;
	while (start < len)
	{
		mlx_put_pixel(data->minimap->minimap, screen_x, start, color);
		start++;
	}
}

void	draw_ray_minimap(t_vault *data)
{
	double	x;
	double	y;
	int		len;

	len = 0;
	x = data->plr->ppx;
	y = data->plr->ppy;
	while (len < fabs(data->raycaster->ray_len) * data->minimap->tile_size)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0x00FF00FF);
		x = x + data->raycaster->pdx_ray;
		y = y + data->raycaster->pdy_ray;
		len++;
	}
}

int	is_a_wall(t_vault *data, int row, int line)
{
	if (data->map->map[row][line] == '1'
		|| data->map->map[row][line] == '2'
		|| data->map->map[row][line] == '3'
		|| data->map->map[row][line] == '4'
		|| data->map->map[row][line] == '5'
		|| data->map->map[row][line] == '6'
		|| data->map->map[row][line] == '7'
		|| data->map->map[row][line] == '8'
		|| data->map->map[row][line] == '9'
		|| data->map->map[row][line] == 'Z')
		return (TRUE);
	return (FALSE);
}
