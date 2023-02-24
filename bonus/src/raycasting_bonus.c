/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/24 15:40:28 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	raycaster(t_vault *data)
{
	double			pixels_2d; // compteur pour le plan largeur de la fenetre
	
	pixels_2d = 0; // on commence a 0 jusqu'a WIDTH
	while (pixels_2d < WIDTH)
	{
		data->raycaster->screen_2d_x = 2 * pixels_2d / WIDTH - 1; // de -1 a +1
		dist_and_pos(data);
		dda(data);
		creating_3d_img(data);
		draw_tex_wall(data, pixels_2d);
		pixels_2d++;
	}
}

void	dist_and_pos(t_vault *data)
{
	data->raycaster->pdx_ray = data->player->pdx + data->raycaster->plane_x * data->raycaster->screen_2d_x;
	data->raycaster->pdy_ray = data->player->pdy + data->raycaster->plane_y * data->raycaster->screen_2d_x;

	// map position
	data->raycaster->col = data->player->col;
	data->raycaster->row = data->player->row;

	// distance entre les cases de la grille (la longueur ne compte pas encore, seulement le ratio)
	if (data->raycaster->pdx_ray == 0)
		data->raycaster->delta_dist_x = 1e30;
	else
		data->raycaster->delta_dist_x = fabs(1 / data->raycaster->pdx_ray);

	if (data->raycaster->pdy_ray == 0)
		data->raycaster->delta_dist_y = 1e30;
	else
		data->raycaster->delta_dist_y = fabs(1 / data->raycaster->pdy_ray);

	// calcul des mouvemements dans la carte 2D et distance entre le joueur et la 1ere intersection
	if (data->raycaster->pdx_ray < 0)
	{
		data->raycaster->map_2d_col = -1;
		data->raycaster->ray_len_x = (data->player->col - data->raycaster->col) * data->raycaster->delta_dist_x;
	}
	else
	{
		data->raycaster->map_2d_col = 1;
		data->raycaster->ray_len_x = (data->raycaster->col + 1.0 - data->player->col) * data->raycaster->delta_dist_x;
	}
	if (data->raycaster->pdy_ray < 0)
	{
		data->raycaster->map_2d_row = -1;
		data->raycaster->ray_len_y = (data->player->row - data->raycaster->row) * data->raycaster->delta_dist_y;
	}
	else
	{
		data->raycaster->map_2d_row = 1;
		data->raycaster->ray_len_y = (data->raycaster->row + 1.0 - data->player->row) * data->raycaster->delta_dist_y;
	}
}

void	dda(t_vault *data)
{
	int	impact; // equivaut a 'hit'
	
	impact = 0;
	// perform DDA (calcul longueur total du rayon)
	while (impact == 0)
	{
		//jump to next map square, either in x-direction, or in y-direction
		if (data->raycaster->ray_len_x < data->raycaster->ray_len_y)
		{
			data->raycaster->ray_len_x = data->raycaster->ray_len_x + data->raycaster->delta_dist_x;
			// row = row + map_2d_row;
			data->raycaster->col = data->raycaster->col + data->raycaster->map_2d_col;
			if (data->raycaster->pdx_ray < 0) // quel cote de mur touche ? EST --> 0, OUEST --> 1
				data->raycaster->side = 0;
			else
				data->raycaster->side = 1;
		}
		else
		{
			data->raycaster->ray_len_y = data->raycaster->ray_len_y + data->raycaster->delta_dist_y;
			// col = col + map_2d_col;
			data->raycaster->row = data->raycaster->row + data->raycaster->map_2d_row;
			if (data->raycaster->pdy_ray < 0) // quel cote de mur touche ? NORD --> 3, SUD --> 2
				data->raycaster->side = 2;
			else
				data->raycaster->side = 3;
		}

		//Check if ray has hit a wall
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

	if (data->minimap->on_screen == 1)
		draw_ray_minimap(data); // pour la minimap

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
