/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 09:34:32 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	raycaster(t_vault *data)
{
	double			delta_dist_x; // distance entre segments de grille verticaux (intersections en x)
	double			delta_dist_y; // distance entre segments de grille horizontaux (intersections en y)
	double			screen_2d_x; // x sur le plan de la largeur de la fenetre
	double			ray_len_x; // longueur du rayon initial (dans la case du joueur)
	double			ray_len_y; // longueur du rayon initial (dans la case du joueur)
	double			ray_len; // longueur du rayon
	int				map_2d_col; // mouvements dans la carte 2D sur les colonnes (y)
	int				map_2d_row; // mouvements dans la carte 2D sur les colonnes (x)
	int				col; // coordonnees map 2D (y)
	int				row; // coordonnees map 2D (x)
	int				impact; // equivaut a 'hit'
	int				side; // quel coté du mur est touché
	double			pixels_2d; // compteur pour le plan largeur de la fenetre
	int				wall_height; // hauteur de la ligne de pixels pour le mur a dessiner
	int				wall_start; // pixel de depart du dessin du mur
	int				wall_end; // pixel de fin du dessin du mur
	unsigned int	wall_color; // couleur du mur

	pixels_2d = 0; // on commence a 0 jusqu'a WIDTH
	while (pixels_2d < WIDTH)
	{
		wall_color = 0;
		impact = 0;
		ray_len = 0;
		side = 0;

		screen_2d_x = 2 * pixels_2d / WIDTH - 1; // de -1 a +1
		data->raycaster->pdx_ray = data->player->pdx + data->raycaster->plane_x * screen_2d_x;
		data->raycaster->pdy_ray = data->player->pdy + data->raycaster->plane_y * screen_2d_x;

		col = data->player->col;
		row = data->player->row;

		if (data->raycaster->pdx_ray == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / data->raycaster->pdx_ray);

		if (data->raycaster->pdy_ray == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / data->raycaster->pdy_ray);

		if (data->raycaster->pdx_ray < 0)
		{
			map_2d_col = -1;
			ray_len_x = (data->player->col - col) * delta_dist_x;
		}
		else
		{
			map_2d_col = 1;
			ray_len_x = (col + 1.0 - data->player->col) * delta_dist_x;
		}
		if (data->raycaster->pdy_ray < 0)
		{
			map_2d_row = -1;
			ray_len_y = (data->player->row - row) * delta_dist_y;
		}
		else
		{
			map_2d_row = 1;
			ray_len_y = (row + 1.0 - data->player->row) * delta_dist_y;
		}

		while (impact == 0)
		{
			if (ray_len_x < ray_len_y)
			{
				ray_len_x = ray_len_x + delta_dist_x;
				col = col + map_2d_col;
				if (data->raycaster->pdx_ray < 0) // quel cote de mur touche ? EST --> 0, OUEST --> 1
					side = 0;
				else
					side = 1;
			}
			else
			{
				ray_len_y = ray_len_y + delta_dist_y;
				row = row + map_2d_row;
				if (data->raycaster->pdy_ray < 0) // quel cote de mur touche ? NORD --> 3, SUD --> 2
					side = 2;
				else
					side = 3;
			}

			if (data->map->map[row][col] == '1')
				impact = 1;
			else
				impact = 0;
		}
		if (side == 0 || side == 1)
			ray_len = (ray_len_x - delta_dist_x);
		else
			ray_len = (ray_len_y - delta_dist_y);
		wall_height = (int)(data->raycaster->height_3d / ray_len);

		wall_start = -wall_height / 2 + data->raycaster->height_3d / 2;
		if (wall_start < 0)
			wall_start = 0;
		wall_end = wall_height / 2 + data->raycaster->height_3d / 2;
		if (wall_end >= data->raycaster->height_3d)
			wall_end = data->raycaster->height_3d - 1;

		if (side == 0)
			wall_color = YELLOW;
		else if (side == 1)
			wall_color = GREEN;
		else if (side == 2)
			wall_color = BLUE;
		else if (side == 3)
			wall_color = RED;

		draw_wall_3d(data, wall_start, wall_end, pixels_2d, wall_color);

		pixels_2d++;
	}
}

void	draw_wall_3d(t_vault *data, double wall_start, double wall_end, double screen_2d_x, unsigned int wall_color)
{
	while (wall_start < wall_end)
	{
		mlx_put_pixel(data->game->ddd, screen_2d_x, wall_start, wall_color);
		wall_start++;
	}
}
