/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/11 16:15:02 by ewurstei         ###   ########.fr       */
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

void	draw_line(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d)
{
	int			screen_y;

	data->tex->step = 1.0 * texture->texture.height / data->game->wall_height;
	data->tex->tex_pos = ((double)data->game->wall_start - (double)HEIGHT / 2
			+ (double)data->game->wall_height / 2) * data->tex->step;
	if (data->tex->tex_pos < 0)
		data->tex->tex_pos = 0;
	screen_y = data->game->wall_start;
	while (screen_y < data->game->wall_end)
	{
		data->tex->tex_y = (int)data->tex->tex_pos;
		if (data->tex->tex_pos > texture->texture.height - 1)
			data->tex->tex_pos = texture->texture.height - 1;
		data->tex->tex_pos = data->tex->tex_pos + data->tex->step;
		data->tex->brightness_factor = brightness_factor(data);
		data->tex->color = tex_buff[data->tex->tex_y][data->game->tex_x];
		data->tex->dark = darken_color(data->tex->color,
				data->tex->brightness_factor, 0);
		mlx_put_pixel(data->game->ddd, pixels_2d, screen_y, data->tex->dark);
		screen_y++;
	}
}

double	brightness_factor(t_vault *data)
{
	double	max_distance;
	double	distance;
	double	brightness_factor;

	max_distance = 15.0;
	distance = data->raycaster->ray_len;
	if (distance > max_distance)
		distance = max_distance;
	brightness_factor = 1 - (distance / max_distance);
	if (brightness_factor < 0.0)
		brightness_factor = 0.0;
	return (brightness_factor);
}

uint32_t	darken_color(uint32_t color, double brightness_factor,
		uint32_t dark_color)
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;

	a = color & 0xFF;
	b = (color >> 8) & 0xFF;
	g = (color >> 16) & 0xFF;
	r = (color >> 24) & 0xFF;
	r *= brightness_factor;
	g *= brightness_factor;
	b *= brightness_factor;
	dark_color = (r << 24) | (g << 16) | (b << 8) | a;
	return (dark_color);
}
