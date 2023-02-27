/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/27 16:11:24 by mbertin          ###   ########.fr       */
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
		creating_3d_img(data);
		draw_tex_wall(data, pixels_2d);
		pixels_2d++;
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
		if (data->map->map[data->raycaster->row][data->raycaster->col] == '1')
			impact = 1;
		else if (data->map->map[data->raycaster->row][data->raycaster->col]
			== '2')
		{
			impact = 1;
			if (data->raycaster->side == 0)
				data->raycaster->side = 5;
			else if (data->raycaster->side == 1)
				data->raycaster->side = 4;
			else if (data->raycaster->side == 2)
				data->raycaster->side = 6;
			else if (data->raycaster->side == 3)
				data->raycaster->side = 7;
		}
	}
}

void	creating_3d_img(t_vault *data)
{
	//pour la vue 3D
	//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
	if (data->raycaster->side == 0 || data->raycaster->side == 1 || data->raycaster->side == 4 || data->raycaster->side == 5)
		data->raycaster->ray_len = (data->raycaster->ray_len_x - data->raycaster->delta_dist_x);
	else
		data->raycaster->ray_len = (data->raycaster->ray_len_y - data->raycaster->delta_dist_y);

	if (data->minimap->on_screen == 1)
		draw_ray_minimap(data); // pour la minimap

	// //Calculate height of line to draw on screen
	data->game->wall_height = (int)(HEIGHT / data->raycaster->ray_len);

	//calculate lowest and highest pixel to fill in current stripe
	data->game->wall_start = -data->game->wall_height / 2 + HEIGHT / 2;
	if (data->game->wall_start < 0)
		data->game->wall_start = 0;
	data->game->wall_end = data->game->wall_height / 2 + HEIGHT / 2;
	if (data->game->wall_end >= HEIGHT)
		data->game->wall_end = HEIGHT - 1;
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
	if (data->raycaster->side == 4 || data->raycaster->side == 5 || data->raycaster->side == 6 || data->raycaster->side == 7)
	{
		find_tex_hit(data, data->tex->tex_nw);
		draw_line(data, data->tex->tex_nw, data->tex->neutral_wall, pixels_2d);
	}
}
