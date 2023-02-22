/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 09:06:30 by ewurstei         ###   ########.fr       */
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
		printf("\033[1;91m");
		printf("\n\n########### NOUVEAU RAYON ###########\n\n");
		printf("\033[1;0m");
		//calculate ray position and direction
		screen_2d_x = 2 * pixels_2d / WIDTH - 1; // de -1 a +1
		data->raycaster->pdx_ray = data->player->pdx + data->raycaster->plane_x * screen_2d_x;
		data->raycaster->pdy_ray = data->player->pdy + data->raycaster->plane_y * screen_2d_x;
		printf("\nposition x sur plan camera : %f\n", screen_2d_x);
		printf("rayDirX : %f\n", data->raycaster->pdx_ray);
		printf("rayDirY : %f\n", data->raycaster->pdy_ray);

		// from sqrt formula to....
		// delta_dist_x = abs(1 / data->raycaster->pdx_ray);
		// delta_dist_y = abs(1 / data->raycaster->pdy_ray);
		// est commenté car repris en dessous dans des if pour eviter division par 0

		// map position
		col = data->player->col;
		row = data->player->row;
		printf("\nposition map 2D:\n");
		printf("row (x) : %d (%f)\n", row, data->player->col);
		printf("col (y) : %d (%f)\n", col, data->player->row);

		// distance entre les cases de la grille (la longueur ne compte pas encore, seulement le ratio)
		if (data->raycaster->pdx_ray == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / data->raycaster->pdx_ray);

		if (data->raycaster->pdy_ray == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / data->raycaster->pdy_ray);
		printf("\nMesure segment suivant :\n");
		printf("deltaDistX : %f\n", delta_dist_x);
		printf("deltaDistY : %f\n", delta_dist_y);

		// calcul des mouvemements dans la carte 2D et distance entre le joueur et la 1ere intersection
		if (data->raycaster->pdx_ray < 0)
		{
			map_2d_row = -1;
			ray_len_x = (data->player->col - row) * delta_dist_x;
		}
		else
		{
			map_2d_row = 1;
			ray_len_x = (row + 1.0 - data->player->col) * delta_dist_x;
		}
		if (data->raycaster->pdy_ray < 0)
		{
			map_2d_col = -1;
			ray_len_y = (data->player->row - col) * delta_dist_y;
		}
		else
		{
			map_2d_col = 1;
			ray_len_y = (col + 1.0 - data->player->row) * delta_dist_y;
		}
		printf("\nLongueur rayon initial :\n");
		printf("sideDistX (ray_len_x) : %f\n", ray_len_x);
		printf("sideDistY (ray_len_y) : %f\n", ray_len_y);

		// perform DDA (calcul longueur total du rayon)
		while (impact == 0)
		{
			//jump to next map square, either in x-direction, or in y-direction
			if (ray_len_x < ray_len_y)
			{
				ray_len_x = ray_len_x + delta_dist_x;
				// row = row + map_2d_row;
				col = col + map_2d_col;
				if (data->raycaster->pdx_ray < 0) // quel cote de mur touche ? EST --> 0, OUEST --> 1
					side = 1;
				else
					side = 0;
			}
			else
			{
				ray_len_y = ray_len_y + delta_dist_y;
				// col = col + map_2d_col;
				row = row + map_2d_row;
				if (data->raycaster->pdy_ray < 0) // quel cote de mur touche ? NORD --> 3, SUD --> 2
					side = 2;
				else
					side = 3;
			}
			
			//Check if ray has hit a wall
			if (data->map->map[row][col] == '1')
			{
				printf("\nSuis-je un mur ? ... \n");
				printf("row (x) : %d\n", row);
				printf("col (y) : %d\n", col);
				printf("\033[1;32m");
				printf("OUI\n");
				printf("\033[1;0m");
				impact = 1;
			}
			else
			{
				printf("\nSuis-je un mur ? ... \n");
				printf("row (x) : %d\n", row);
				printf("col (y) : %d\n", col);
				printf("\033[1;91m");
				printf("NON\n");
				printf("\033[1;0m");
				impact = 0;
			}
		}


		//pour la vue 3D
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0 || side == 1)
			ray_len = (ray_len_x - delta_dist_x);
		else
			ray_len = (ray_len_y - delta_dist_y);

		draw_ray_minimap(data, ray_len); // pour la minimap

		// //Calculate height of line to draw on screen
		wall_height = (int)(data->raycaster->height_3d / ray_len);

		//calculate lowest and highest pixel to fill in current stripe
		wall_start = -wall_height / 2 + data->raycaster->height_3d / 2;
		if (wall_start < 0)
			wall_start = 0;
		wall_end = wall_height / 2 + data->raycaster->height_3d / 2;
		if (wall_end >= data->raycaster->height_3d)
			wall_end = data->raycaster->height_3d - 1;

		// give x and y sides different brightness
		printf("\nCote de mur touché : %d\n", side);
		
		if (side == 0)
		{
			wall_color = YELLOW;
			printf("couleur du mur : JAUNE (EST)\n");
		}
		else if (side == 1)
		{
			wall_color = GREEN;
			printf("couleur du mur : VERT (OUEST)\n");
		}
		else if (side == 2)
		{
			wall_color = BLUE;
			printf("couleur du mur : BLEU (SUD)\n");
		}
		else if (side == 3)
		{
			wall_color = RED;
			printf("couleur du mur : ROUGE (NORD)\n");
		}
		

		// draw the pixels of the stripe as a vertical line
		// draw_wall_3d(data, wall_start, wall_end, screen_2d_x, wall_color);
		draw_wall_3d(data, wall_start, wall_end, pixels_2d, wall_color);


		pixels_2d++;
	}
}

void	draw_wall_3d(t_vault *data, double wall_start, double wall_end, double screen_2d_x, unsigned int wall_color)
{
	printf("\nParametre dessin 3d\n");
	printf("wall_start : %f\n", wall_start);
	printf("wall_end : %f\n", wall_end);
	printf("x sur plan fenetre : %f\n", screen_2d_x);
	while (wall_start < wall_end)
	{
		mlx_put_pixel(data->game->ddd, screen_2d_x, wall_start, wall_color);
		wall_start++;
	}
}

void	draw_ray_minimap(t_vault *data, float ray_len)
{
	float	x;
	float	y;
	int		len;

	len = 0;
	x = data->player->ppx;
	y = data->player->ppy;
	while (len < fabsf(ray_len) * TILE)
	{
		mlx_put_pixel(data->minimap->minimap, x, y, 0x00FF00FF);
		x = x + data->raycaster->pdx_ray;
		y = y + data->raycaster->pdy_ray;
		len++;
	}
}

// void	find_ray_angle(t_vault *data)
// {
// 	if (data->raycaster->ray_one_a < 0)
// 		data->raycaster->ray_one_a = data->raycaster->ray_one_a + 2 * PI;
// 	else if (data->raycaster->ray_one_a > 2 * PI)
// 		data->raycaster->ray_one_a = data->raycaster->ray_one_a - 2 * PI;
// 	data->raycaster->pdx_ray = cos(data->raycaster->ray_one_a);
// 	data->raycaster->pdy_ray = sin(data->raycaster->ray_one_a);
// }
