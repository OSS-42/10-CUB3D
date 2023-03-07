/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:30 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/07 17:50:44 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	reinit_3d(t_vault *data)
{
	mlx_delete_image(data->mlx, data->game->ddd);
	load_3d(data);
}

void	load_3d(t_vault *data)
{
	data->game->ddd = mlx_new_image(data->mlx, WIDTH,
			HEIGHT);
	background_3d(data);
	mlx_image_to_window(data->mlx, data->game->ddd, 0, 0);
}

void	background_3d(t_vault *data)
{
	int	i;
	int	start;

	i = 0;
	while (i < HEIGHT)
	{
		start = -1;
		if (i < HEIGHT / 2)
		{
			while (++start < WIDTH)
				mlx_put_pixel(data->game->ddd, start,
					i, data->scene_param->hex_ceiling);
		}
		else
		{
			while (++start < WIDTH)
				mlx_put_pixel(data->game->ddd, start,
					i, data->scene_param->hex_floor);
		}
		i++;
	}
}

void	reinit_and_draw(t_vault *data)
{
	reinit_3d(data);
	reinit_hud(data);
	if (data->minimap->on_screen == 1)
	{
		mlx_delete_image(data->mlx, data->minimap->minimap);
		show_minimap(data);
	}
	raycaster(data);
}
