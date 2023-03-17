/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:30 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/17 09:33:15 by mbertin          ###   ########.fr       */
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
	data->game->ddd = mlx_new_image(data->mlx, WIDTH, HEIGHT);
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
