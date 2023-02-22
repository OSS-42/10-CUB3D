/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:30 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 14:48:09 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void load_3d(t_vault *data)
{
	data->game->ddd = mlx_new_image(data->mlx, WIDTH, HEIGHT_3D);
	mlx_image_to_window(data->mlx, data->game->ddd, 0, 0);
	background_3d(data);
}

void	background_3d(t_vault *data)
{
	int	i;
	int	start;

	i = 0;
	while (i < HEIGHT_3D / 2)
	{
		start = 0;
		while (start < WIDTH)
		{
			mlx_put_pixel(data->game->ddd, start, i, data->scene_param->hex_ceiling);
			start++;
		}
		i++;
	}
	while (i < HEIGHT_3D)
	{
		start = 0;
		while (start < WIDTH)
		{
			mlx_put_pixel(data->game->ddd, start, i, data->scene_param->hex_floor);
			start++;
		}
		i++;
	}
}
