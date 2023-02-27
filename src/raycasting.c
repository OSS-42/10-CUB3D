/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/27 13:35:46 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	double	pixels_2d;

	pixels_2d = 0;
	while (pixels_2d < WIDTH)
	{
		data->raycaster->screen_2d_x = 2 * pixels_2d / WIDTH - 1;
		dist_and_pos(data);
		dda(data, 0);
		creating_3d_img(data);
		draw_tex_wall(data, pixels_2d);
		pixels_2d++;
	}
}

void	dda(t_vault *data, int impact)
{
	while (impact == 0)
	{
		if (data->raycaster->ray_len_x < data->raycaster->ray_len_y)
		{
			data->raycaster->ray_len_x += data->raycaster->delta_dist_x;
			data->raycaster->col += data->raycaster->map_2d_col;
			if (data->raycaster->pdx_ray < 0)
				data->raycaster->side = 0;
			else
				data->raycaster->side = 1;
		}
		else
		{
			data->raycaster->ray_len_y += data->raycaster->delta_dist_y;
			data->raycaster->row += data->raycaster->map_2d_row;
			if (data->raycaster->pdy_ray < 0)
				data->raycaster->side = 2;
			else
				data->raycaster->side = 3;
		}
		if (data->map->map[data->raycaster->row][data->raycaster->col] == '1')
			impact = 1;
	}
}

void	creating_3d_img(t_vault *data)
{
	//pour la vue 3D
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (data->raycaster->side == 0 || data->raycaster->side == 1)
		data->raycaster->ray_len = (data->raycaster->ray_len_x - data->raycaster->delta_dist_x);
	else
		data->raycaster->ray_len = (data->raycaster->ray_len_y - data->raycaster->delta_dist_y);

	// //Calculate height of line to draw on screen
	data->game->wall_height = (int)(data->raycaster->height_3d / data->raycaster->ray_len);

	//calculate lowest and highest pixel to fill in current stripe
	data->game->wall_start = -data->game->wall_height / 2 + data->raycaster->height_3d / 2;
	if (data->game->wall_start < 0)
		data->game->wall_start = 0;
	data->game->wall_end = data->game->wall_height / 2 + data->raycaster->height_3d / 2;
	if (data->game->wall_end >= data->raycaster->height_3d)
		data->game->wall_end = data->raycaster->height_3d - 1;
	// draw the pixels of the stripe as a vertical line
}

void	draw_tex_wall(t_vault *data, int pixels_2d)
{
	if (data->raycaster->side == 0)
	{
		find_tex_hit(data, data->tex->tex_e);
		draw_line(data, data->tex->tex_e, data->tex->east, pixels_2d);
	}
	if (data->raycaster->side == 1)
	{
		find_tex_hit(data, data->tex->tex_w);
		draw_line(data, data->tex->tex_w, data->tex->west, pixels_2d);
	}
	if (data->raycaster->side == 2)
	{
		find_tex_hit(data, data->tex->tex_s);
		draw_line(data, data->tex->tex_s, data->tex->south, pixels_2d);
	}
	if (data->raycaster->side == 3)
	{
		find_tex_hit(data, data->tex->tex_n);
		draw_line(data, data->tex->tex_n, data->tex->north, pixels_2d);
	}
}
