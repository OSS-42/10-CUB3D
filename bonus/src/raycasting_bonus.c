/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/05 10:33:33 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	raycaster(t_vault *data)
{
	double	pixels_2d;

	pixels_2d = 0;
	while (pixels_2d < WIDTH)
	{
		data->raycaster->screen_2d_x = 2 * pixels_2d / WIDTH - 1;
		dist_and_pos(data);
		dda(data);
		creating_3d_img(data, pixels_2d);
		draw_tex_wall(data, pixels_2d);
		// sprite_casting(data);
		pixels_2d++;
	}
}

void	dist_and_pos(t_vault *data)
{
	data->raycaster->pdx_ray = data->plr->pdx + data->raycaster->plane_x
		* data->raycaster->screen_2d_x;
	data->raycaster->pdy_ray = data->plr->pdy + data->raycaster->plane_y
		* data->raycaster->screen_2d_x;
	data->raycaster->col = data->plr->col;
	data->raycaster->row = data->plr->row;
	if (data->raycaster->pdx_ray == 0)
		data->raycaster->delta_dist_x = 1e30;
	else
		data->raycaster->delta_dist_x = fabs(1 / data->raycaster->pdx_ray);
	if (data->raycaster->pdy_ray == 0)
		data->raycaster->delta_dist_y = 1e30;
	else
		data->raycaster->delta_dist_y = fabs(1 / data->raycaster->pdy_ray);
	dist_and_pos2(data);
}

void	dist_and_pos2(t_vault *data)
{
	if (data->raycaster->pdx_ray < 0)
	{
		data->raycaster->map_2d_col = -1;
		data->raycaster->ray_len_x = (data->plr->col - data->raycaster->col)
			* data->raycaster->delta_dist_x;
	}
	else
	{
		data->raycaster->map_2d_col = 1;
		data->raycaster->ray_len_x = (data->raycaster->col + 1.0
				- data->plr->col) * data->raycaster->delta_dist_x;
	}
	if (data->raycaster->pdy_ray < 0)
	{
		data->raycaster->map_2d_row = -1;
		data->raycaster->ray_len_y = (data->plr->row - data->raycaster->row)
			* data->raycaster->delta_dist_y;
	}
	else
	{
		data->raycaster->map_2d_row = 1;
		data->raycaster->ray_len_y = (data->raycaster->row + 1.0
				- data->plr->row) * data->raycaster->delta_dist_y;
	}
}

void	dda(t_vault *data)
{
	int	impact;

	impact = 0;
	while (impact == 0)
	{
		if (data->raycaster->ray_len_x < data->raycaster->ray_len_y)
		{
			data->raycaster->ray_len_x += data->raycaster->delta_dist_x;
			data->raycaster->col += data->raycaster->map_2d_col;
			if (data->raycaster->pdx_ray < 0)
				data->raycaster->side = 0;
			else if (data->raycaster->pdx_ray > 0)
				data->raycaster->side = 1;
		}
		else
		{
			data->raycaster->ray_len_y += data->raycaster->delta_dist_y;
			data->raycaster->row += data->raycaster->map_2d_row;
			if (data->raycaster->pdy_ray < 0)
				data->raycaster->side = 2;
			else if (data->raycaster->pdy_ray > 0)
				data->raycaster->side = 3;
		}
		check_type_wall(data, &impact);
	}
}

void	creating_3d_img(t_vault *data, int pixels_2d)
{
	int	side;

	side = data->raycaster->side;
	if (side == 0 || side == 1 || side == 4 || side == 5 || side == 8
		|| side == 9 || side == 12 || side == 13 || side == 16 || side == 17
		|| side == 20 || side == 21 || side == 24 || side == 25 || side == 28
		|| side == 29 || side == 32 || side == 33 || side == 36 || side == 37
		|| side == 40 || side == 41)
		data->raycaster->ray_len = (data->raycaster->ray_len_x
				- data->raycaster->delta_dist_x);
	else
		data->raycaster->ray_len = (data->raycaster->ray_len_y
				- data->raycaster->delta_dist_y);
	if (data->minimap->on_screen == 1)
		draw_ray_minimap(data);
	data->game->wall_height = (int)(HEIGHT / data->raycaster->ray_len);
	data->sp_param->ZBuffer[pixels_2d] = data->raycaster->ray_len;
	data->game->wall_start = -data->game->wall_height / 2 + HEIGHT / 2;
	if (data->game->wall_start < 0)
		data->game->wall_start = 0;
	data->game->wall_end = data->game->wall_height / 2 + HEIGHT / 2;
	if (data->game->wall_end >= HEIGHT)
		data->game->wall_end = HEIGHT - 1;
}
