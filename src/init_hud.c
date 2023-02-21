/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/20 22:25:34 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	load_hud(t_vault *data)
{
	data->hud->hud = mlx_new_image(data->mlx,
			WIDTH - data->map->max_lenght * TILE, data->map->lines * TILE);
	draw_hud(data);
	mlx_image_to_window(data->mlx, data->hud->hud,
		0 + data->map->max_lenght * TILE, HEIGHT - data->map->lines * TILE);
}

void	draw_hud(t_vault *data)
{
	data->hud->lives_count = 3;
	data->hud->total_c = 3; // a rendre dynamique
	data->hud->collected = 0; // a rendre dynamique
	//contours HUD
	full_line_hud_hor(data, 0, 0x00FF00FF);
	full_line_hud_ver(data, 0, 0x00FF00FF);
	full_line_hud_ver(data, WIDTH - data->map->max_lenght * TILE - 1, 0x00FF00FF);
	full_line_hud_hor(data, data->map->lines * TILE - 1, 0x00FF00FF);

	//separations dans HUD
	// mlx_put_string(data->mlx, "Bottles", data->map->max_lenght * 11 + 40, HEIGHT - data->map->lines * 10);
	// mlx_put_string(data->mlx, "To collect ", data->map->max_lenght * 11 + 10, HEIGHT - data->map->lines * 7);
	// mlx_put_string(data->mlx, ft_itoa(data->hud->total_c), data->map->max_lenght * 11 + 130, HEIGHT - data->map->lines * 7);
	// mlx_put_string(data->mlx, "Collected ", data->map->max_lenght * 11 + 10, HEIGHT - data->map->lines * 4);
	// mlx_put_string(data->mlx, ft_itoa(data->hud->collected), data->map->max_lenght * 11 + 130, HEIGHT - data->map->lines * 4);
	full_line_hud_ver(data, 0 + 150, 0xFF00FFFF);
	full_line_hud_ver(data, 0 + 250, 0xFF00FFFF);
	// mlx_put_string(data->mlx, "Lives", data->map->max_lenght * 11 + 275, HEIGHT - data->map->lines * 10);
	// mlx_put_string(data->mlx, ft_itoa(data->hud->lives_count), data->map->max_lenght * 11 + 295, HEIGHT - data->map->lines * 7);
	full_line_hud_ver(data, 0 + 350, 0xFF00FFFF);
}

void	full_line_hud_hor(t_vault *data, int screen_y, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = WIDTH - data->map->max_lenght * TILE - 1;
	while (start < len)
	{
		mlx_put_pixel(data->hud->hud, start, screen_y, color);
		start++;
	}
}

void	full_line_hud_ver(t_vault *data, int screen_x, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = data->map->lines * TILE - 1;
	while (start < len)
	{
		mlx_put_pixel(data->hud->hud, screen_x, start, color);
		start++;
	}
}
