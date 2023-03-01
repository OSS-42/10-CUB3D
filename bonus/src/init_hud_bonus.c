/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/28 23:37:33 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_hud(t_vault *data)
{
	data->hud_loc->hud_location = mlx_new_image(data->mlx, 400, 52);
	draw_hud(data);
	mlx_image_to_window(data->mlx, data->hud_loc->hud_location,
		65, 0 + 30);
}

void	draw_hud(t_vault *data)
{
	player_location(data, data->plr->row, data->plr->col);
	draw_tex_location(data, data->tex->local, 1);
	draw_tex_location(data, data->hud_loc->p_loc, 200);
}

void	draw_tex_location(t_vault *data, int **tex_buff, int pixels_2d)
{
	int	screen_y;

	while (pixels_2d < 400 - 1)
	{
		screen_y = 0;
		while (screen_y < 50 - 1)
		{
			mlx_put_pixel(data->hud_loc->hud_location, pixels_2d, screen_y,
				tex_buff[screen_y][pixels_2d]);
			screen_y++;
		}
		pixels_2d++;
	}
}
