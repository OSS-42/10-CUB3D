/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/25 01:12:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_hud(t_vault *data)
{
	data->hud_col->hud_collect = mlx_new_image(data->mlx, 200, 50);
	data->hud_loc->hud_location = mlx_new_image(data->mlx, 200, 50);
	draw_hud(data);
	mlx_image_to_window(data->mlx, data->hud_col->hud_collect,
		WIDTH - WIDTH / 4, 0 + 30);
	mlx_image_to_window(data->mlx, data->hud_loc->hud_location,
		65, 0 + 30);
}

void	draw_hud(t_vault *data)
{
	// data->hud_col->total_c = 3; // a rendre dynamique
	// data->hud_col->collected = 0; // a rendre dynamique
	//contours HUD
	full_line_hud_hor(data->hud_col->hud_collect, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_col->hud_collect, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_col->hud_collect, 200 - 1, 0x000000FF);
	full_line_hud_hor(data->hud_col->hud_collect, 50 - 1, 0x000000FF);

	full_line_hud_hor(data->hud_loc->hud_location, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_loc->hud_location, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_loc->hud_location, 200 - 1, 0x000000FF);
	full_line_hud_hor(data->hud_loc->hud_location, 50 - 1, 0x000000FF);

	//separations dans HUD
	// mlx_put_string(data->mlx, "Bottles", data->map->max_lenght * 11 + 40, HEIGHT - data->map->lines * 10);
	player_location(data);
	draw_tex_collect(data, data->tex->tex_collect, data->tex->collect, 1);
	draw_tex_location(data, data->tex->tex_lobby, data->hud_loc->p_loc, 1);
}

void	draw_tex_collect(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d)
{
	int	screen_y;
	
	(void)texture;
	while (pixels_2d < 200 - 1)
	{
		screen_y = 1;
		while (screen_y < 50 - 1)
		{
			mlx_put_pixel(data->hud_col->hud_collect, pixels_2d, screen_y, tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}

void	draw_tex_location(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d)
{
	int	screen_y;
	
	(void)texture;
	while (pixels_2d < 200 - 1)
	{
		screen_y = 1;
		while (screen_y < 50 - 1)
		{
			mlx_put_pixel(data->hud_loc->hud_location, pixels_2d, screen_y, tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}

void	full_line_hud_hor(mlx_image_t *hud, int screen_y, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = 200 - 1;
	while (start < len)
	{
		mlx_put_pixel(hud, start, screen_y, color);
		start++;
	}
}

void	full_line_hud_ver(mlx_image_t *hud, int screen_x, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = 50 - 1;
	while (start < len)
	{
		mlx_put_pixel(hud, screen_x, start, color);
		start++;
	}
}

