/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 23:54:21 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/23 22:28:33 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

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
	
	pixels_2d = 0; // on commence a 0 jusqu'a WIDTH
	while (pixels_2d < WIDTH)
	{
		data->game->wall_color = DGRAY;
		impact = 0;
		ray_len = 0;
		side = 0;

		screen_2d_x = 2 * pixels_2d / WIDTH - 1; // de -1 a +1
		data->raycaster->pdx_ray = data->player->pdx + data->raycaster->plane_x * screen_2d_x;
		data->raycaster->pdy_ray = data->player->pdy + data->raycaster->plane_y * screen_2d_x;

		// map position
		col = data->player->col;
		row = data->player->row;

		// distance entre les cases de la grille (la longueur ne compte pas encore, seulement le ratio)
		if (data->raycaster->pdx_ray == 0)
			delta_dist_x = 1e30;
		else
			delta_dist_x = fabs(1 / data->raycaster->pdx_ray);

		if (data->raycaster->pdy_ray == 0)
			delta_dist_y = 1e30;
		else
			delta_dist_y = fabs(1 / data->raycaster->pdy_ray);

		// calcul des mouvemements dans la carte 2D et distance entre le joueur et la 1ere intersection
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
					side = 0;
				else
					side = 1;
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
				impact = 1;
			else
				impact = 0;
		}

		//pour la vue 3D
		//Calculate distance projected on camera direction (Euclidean distance would give fisheye effect!)
		if (side == 0 || side == 1)
			ray_len = (ray_len_x - delta_dist_x);
		else
			ray_len = (ray_len_y - delta_dist_y);

		if (data->minimap->on_screen == 1)
			draw_ray_minimap(data, ray_len); // pour la minimap

		// //Calculate height of line to draw on screen
		data->game->wall_height = (int)(data->raycaster->height_3d / ray_len);

		//calculate lowest and highest pixel to fill in current stripe
		data->game->wall_start = -data->game->wall_height / 2 + HEIGHT_3D / 2;
		if (data->game->wall_start < 0)
			data->game->wall_start = 0;
		data->game->wall_end = data->game->wall_height / 2 + HEIGHT_3D / 2;
		if (data->game->wall_end >= HEIGHT_3D)
			data->game->wall_end = HEIGHT_3D - 1;
		// draw the pixels of the stripe as a vertical line
		draw_tex_wall(data, pixels_2d, side, ray_len);
		// draw_wall_3d(data, data->game->wall_start, data->game->wall_end, pixels_2d, data->game->wall_color);

		pixels_2d++;
	}
}

void	find_tex_hit(t_vault *data, xpm_t *texture, int side, double ray_len)
{
	double	wall_x; //where exactly the wall was hit

	if (side == 0 || side == 1) 
		wall_x = data->player->row + ray_len * data->raycaster->pdy_ray;
	else
		wall_x = data->player->col + ray_len * data->raycaster->pdx_ray;
	wall_x = wall_x - (int)(wall_x);

	//x coordinate on the texture
	data->game->tex_x = (int)(wall_x * (double)(texture->texture.width));
	if ((side == 0 || side == 1) && data->raycaster->pdx_ray > 0) 
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
	if ((side == 2 || side == 3) && data->raycaster->pdy_ray < 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
}

void	draw_line(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d)
{
	int				tex_y;
	double			tex_pos;
	double			step;
	int 			screen_y;
	
	step = 1.0 * texture->texture.height / data->game->wall_height;
	// Starting texture coordinate
	tex_pos = ((double)data->game->wall_start - (double)HEIGHT_3D / 2 + (double)data->game->wall_height / 2) * step;
	if (tex_pos < 0)
		tex_pos = 0;
	screen_y = data->game->wall_start;
	while (screen_y < data->game->wall_end)
	{
		// Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		tex_y = (int)tex_pos;
		if (tex_pos > texture->texture.height - 1)
			tex_pos = texture->texture.height - 1;
		tex_pos = tex_pos + step;
		mlx_put_pixel(data->game->ddd, pixels_2d, screen_y, tex_buff[tex_y][data->game->tex_x]);
		screen_y++;
	}
}

int	**fill_texture(xpm_t *tex)
{
	int	**tex_buff;
	int	i;
	int	j;
	
	tex_buff = ft_calloc(sizeof(int *), tex->texture.height + 1);
	i = 3;
	while (++i < (int)tex->texture.height + 4)
	{
		j = 3;
		tex_buff[i - 4] = ft_calloc(sizeof(int), tex->texture.width);
		while (++j < (int)tex->texture.width + 4)
			tex_buff[i - 4][j - 4]
				= rgb_to_hex2(tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 0],
					tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 1],
					tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 2],
					tex->texture.pixels[(tex->texture.width * 4
						* (i - 4)) + (4 * (j - 4)) + 3]);
	}
	return (tex_buff);
}

void	create_texture(t_vault *data)
{
	printf("NO : %s\n", data->scene_param->no_wall_path);
	printf("SO : %s\n", data->scene_param->so_wall_path);
	printf("EA : %s\n", data->scene_param->ea_wall_path);
	printf("WE : %s\n", data->scene_param->we_wall_path);
	data->tex->tex_n = mlx_load_xpm42(data->scene_param->no_wall_path);
	if (!data->tex->tex_n)
	{
		printf("coucou\n");
		quit_game(data);
	}
	data->tex->tex_s = mlx_load_xpm42(data->scene_param->so_wall_path);
	if (!data->tex->tex_s)
	{
		printf("coucou2\n");
		quit_game(data);
	}
	data->tex->tex_e = mlx_load_xpm42(data->scene_param->ea_wall_path);
	if (!data->tex->tex_e)
	{
		printf("coucou3\n");
		quit_game(data);
	}
	data->tex->tex_w = mlx_load_xpm42(data->scene_param->we_wall_path);
	if (!data->tex->tex_w)
	{
		printf("coucou4\n");
		quit_game(data);
	}
	data->tex->north = fill_texture(data->tex->tex_n);
	data->tex->south = fill_texture(data->tex->tex_s);
	data->tex->east = fill_texture(data->tex->tex_e);
	data->tex->west = fill_texture(data->tex->tex_w);
}

void	draw_tex_wall(t_vault *data, int pixels_2d, int side, double raylen)
{
	if (side == 0)
	{
		find_tex_hit(data, data->tex->tex_e, side, raylen);
		draw_line(data, data->tex->tex_e, data->tex->east, pixels_2d);
	}
	if (side == 1)
	{
		find_tex_hit(data, data->tex->tex_w, side, raylen);
		draw_line(data, data->tex->tex_w, data->tex->west, pixels_2d);
	}
	if (side == 2)
	{
		find_tex_hit(data, data->tex->tex_s, side, raylen);
		draw_line(data, data->tex->tex_s, data->tex->south, pixels_2d);
	}
	if (side == 3)
	{
		find_tex_hit(data, data->tex->tex_n, side, raylen);
		draw_line(data, data->tex->tex_n, data->tex->north, pixels_2d);
	}
}

// void	draw_wall_3d(t_vault *data, double wall_start, double wall_end, double screen_2d_x, unsigned int wall_color)
// {
// 	while (wall_start < wall_end)
// 	{
// 		mlx_put_pixel(data->game->ddd, screen_2d_x, wall_start, wall_color);
// 		wall_start++;
// 	}
// }

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
