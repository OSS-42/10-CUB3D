/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_3d_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:12:30 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 22:48:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_3d(t_vault *data)
{
	data->game->ddd = mlx_new_image(data->mlx, WIDTH,
			data->raycaster->height_3d);
	mlx_image_to_window(data->mlx, data->game->ddd, 0, 0);
	background_3d(data);
}

void	background_3d(t_vault *data)
{
	int	i;
	int	start;

	i = 0;
	while (i < data->raycaster->height_3d / 2)
	{
		start = -1;
		while (++start < WIDTH)
			mlx_put_pixel(data->game->ddd, start,
				i, data->scene_param->hex_ceiling);
		i++;
	}
	while (i < data->raycaster->height_3d)
	{
		start = -1;
		while (++start < WIDTH)
			mlx_put_pixel(data->game->ddd, start,
				i, data->scene_param->hex_floor);
		i++;
	}
}

void	reinit_3d(t_vault *data)
{
	mlx_delete_image(data->mlx, data->game->ddd);
	load_3d(data);
}
