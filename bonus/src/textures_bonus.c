/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/03 18:41:08 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_textures(t_vault *data)
{
	data->tex->tex_n = mlx_load_xpm42(data->scene_param->no_wall_path);
	if (!data->tex->tex_n)
		quit_game(data);
	data->tex->tex_s = mlx_load_xpm42(data->scene_param->so_wall_path);
	if (!data->tex->tex_s)
		quit_game(data);
	data->tex->tex_e = mlx_load_xpm42(data->scene_param->ea_wall_path);
	if (!data->tex->tex_e)
		quit_game(data);
	data->tex->tex_w = mlx_load_xpm42(data->scene_param->we_wall_path);
	if (!data->tex->tex_w)
		quit_game(data);
	data->tex->north = get_texture(data->tex->tex_n);
	data->tex->south = get_texture(data->tex->tex_s);
	data->tex->east = get_texture(data->tex->tex_e);
	data->tex->west = get_texture(data->tex->tex_w);
	load_extra_textures(data);
}

int	**get_texture(xpm_t *tex)
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

void	find_tex_hit(t_vault *data, xpm_t *texture)
{
	double	wall_x;

	if (data->raycaster->side == 0 || data->raycaster->side == 1
		|| data->raycaster->side == 4 || data->raycaster->side == 5
		|| data->raycaster->side == 8 || data->raycaster->side == 9
		|| data->raycaster->side == 12 || data->raycaster->side == 13
		|| data->raycaster->side == 16 || data->raycaster->side == 17
		|| data->raycaster->side == 20 || data->raycaster->side == 21
		|| data->raycaster->side == 24 || data->raycaster->side == 25
		|| data->raycaster->side == 28 || data->raycaster->side == 29
		|| data->raycaster->side == 32 || data->raycaster->side == 33
		|| data->raycaster->side == 36 || data->raycaster->side == 37
		|| data->raycaster->side == 40 || data->raycaster->side == 41)
		wall_x = data->plr->row + data->raycaster->ray_len
			* data->raycaster->pdy_ray;
	else
		wall_x = data->plr->col + data->raycaster->ray_len
			* data->raycaster->pdx_ray;
	wall_x = wall_x - (int)(wall_x);
	data->game->tex_x = abs((int)(1 - wall_x * (double)(texture->texture.width)));
	if (data->game->tex_x < 0)
		data->game->tex_x = 0;
	else if (data->game->tex_x >= (int)texture->texture.width)
		data->game->tex_x = texture->texture.width - 1;
	find_tex_hit2(data, texture);
}

void	find_tex_hit2(t_vault *data, xpm_t *texture)
{
	if ((data->raycaster->side == 0 || data->raycaster->side == 1
			|| data->raycaster->side == 4 || data->raycaster->side == 5
			|| data->raycaster->side == 8 || data->raycaster->side == 9
			|| data->raycaster->side == 12 || data->raycaster->side == 13
			|| data->raycaster->side == 16 || data->raycaster->side == 17
			|| data->raycaster->side == 20 || data->raycaster->side == 21
			|| data->raycaster->side == 24 || data->raycaster->side == 25
			|| data->raycaster->side == 28 || data->raycaster->side == 29
			|| data->raycaster->side == 32 || data->raycaster->side == 33
			|| data->raycaster->side == 36 || data->raycaster->side == 37
			|| data->raycaster->side == 40 || data->raycaster->side == 41)
		&& data->raycaster->pdx_ray < 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
	if ((data->raycaster->side == 2 || data->raycaster->side == 3
			|| data->raycaster->side == 6 || data->raycaster->side == 7
			|| data->raycaster->side == 10 || data->raycaster->side == 11
			|| data->raycaster->side == 14 || data->raycaster->side == 15
			|| data->raycaster->side == 18 || data->raycaster->side == 19
			|| data->raycaster->side == 22 || data->raycaster->side == 23
			|| data->raycaster->side == 26 || data->raycaster->side == 27
			|| data->raycaster->side == 30 || data->raycaster->side == 31
			|| data->raycaster->side == 34 || data->raycaster->side == 35
			|| data->raycaster->side == 38 || data->raycaster->side == 39
			|| data->raycaster->side == 42 || data->raycaster->side == 43)
		&& data->raycaster->pdy_ray > 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
}

void	draw_line(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d)
{
	int tex_y;
	double tex_pos;
	double step;
	int screen_y;
	uint32_t color;
	double brightness_factor;

	step = 1.0 * texture->texture.height / data->game->wall_height;
	tex_pos = ((double)data->game->wall_start - (double)HEIGHT / 2
			+ (double)data->game->wall_height / 2) * step;
	if (tex_pos < 0)
		tex_pos = 0;
	screen_y = data->game->wall_start;
	while (screen_y < data->game->wall_end)
	{
		tex_y = (int)tex_pos;
		if (tex_pos > texture->texture.height - 1)
			tex_pos = texture->texture.height - 1;
		tex_pos = tex_pos + step;

		// calculate brightness factor based on distance from camera
		brightness_factor = calculate_brightness_factor(data);

		// darken the pixel by multiplying its components by the brightness factor
		// color = tex_buff[tex_y][data->game->tex_x];
		if (data->game->tex_x >= 0 && data->game->tex_x < (int)texture->texture.width)
			color = tex_buff[tex_y][data->game->tex_x];
		else
			color = 0xff0000ff; // or some other default value
		uint32_t dark_color = darken_color(color, brightness_factor);

		mlx_put_pixel(data->game->ddd, pixels_2d, screen_y, dark_color);
		screen_y++;
	}
}

double calculate_brightness_factor(t_vault *data)
{
	double	max_distance;
	double	distance;
	double	brightness_factor;

	max_distance = 18.0;
	distance = data->raycaster->ray_len;
	// set the maximum distance at which walls should be fully visible
	if (distance > max_distance)
		distance = max_distance;

	// calculate the brightness factor based on the distance from the camera
	brightness_factor = 1 - (distance / max_distance);

	if (brightness_factor < 0.0)
		brightness_factor = 0.0;

	return (brightness_factor);
}

uint32_t darken_color(uint32_t color, double brightness_factor)
{
	// Extract the red, green, blue, and alpha components of the color
	uint8_t	r = (color >> 24) & 0xFF;
	uint8_t	g = (color >> 16) & 0xFF;
	uint8_t	b = (color >> 8) & 0xFF;
	uint8_t	a = color & 0xFF;

	// Calculate the new color components by multiplying them by the brightness factor
	r *= brightness_factor;
	g *= brightness_factor;
	b *= brightness_factor;

	// Combine the color components into a single 32-bit color value
	uint32_t dark_color = (r << 24) | (g << 16) | (b << 8) | a;

	return dark_color;
}