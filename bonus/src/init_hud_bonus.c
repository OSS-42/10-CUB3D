/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/27 15:17:18 by mbertin          ###   ########.fr       */
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
	full_line_hud_hor(data->hud_col->hud_collect, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_col->hud_collect, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_col->hud_collect, 200 - 1, 0x000000FF);
	full_line_hud_hor(data->hud_col->hud_collect, 50 - 1, 0x000000FF);
	full_line_hud_hor(data->hud_loc->hud_location, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_loc->hud_location, 0, 0xFFFFFFFF);
	full_line_hud_ver(data->hud_loc->hud_location, 200 - 1, 0x000000FF);
	full_line_hud_hor(data->hud_loc->hud_location, 50 - 1, 0x000000FF);
	player_location(data, 0, 0);
	draw_tex_collect(data, data->tex->collect, 1);
	draw_tex_location(data, data->hud_loc->p_loc, 1);
}

void	draw_tex_collect(t_vault *data, int **tex_buff, int pixels_2d)
{
	int	screen_y;

	while (pixels_2d < 200 - 1)
	{
		screen_y = 1;
		while (screen_y < 50 - 1)
		{
			mlx_put_pixel(data->hud_col->hud_collect, pixels_2d, screen_y,
				tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}

void	draw_tex_location(t_vault *data, int **tex_buff, int pixels_2d)
{
	int	screen_y;

	while (pixels_2d < 200 - 1)
	{
		screen_y = 1;
		while (screen_y < 50 - 1)
		{
			mlx_put_pixel(data->hud_loc->hud_location, pixels_2d, screen_y,
				tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}
