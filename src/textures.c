/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:42:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/13 23:10:23 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	rgb_to_hex2(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

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

	if (data->raycaster->side == 0 || data->raycaster->side == 1)
		wall_x = data->plr->row + data->raycaster->ray_len
			* data->raycaster->pdy_ray;
	else
		wall_x = data->plr->col + data->raycaster->ray_len
			* data->raycaster->pdx_ray;
	wall_x = wall_x - (int)(wall_x);
	data->game->tex_x = (int)(wall_x * (double)(texture->texture.width));
	if ((data->raycaster->side == 0 || data->raycaster->side == 1)
		&& data->raycaster->pdx_ray > 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
	if ((data->raycaster->side == 2 || data->raycaster->side == 3)
		&& data->raycaster->pdy_ray < 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
}

void	draw_line(t_vault *data, xpm_t *texture, int **tex_buff, int pixels_2d)
{
	int				tex_y;
	double			tex_pos;
	double			step;
	int				screen_y;

	step = 1.0 * texture->texture.height / data->game->wall_height;
	tex_pos = ((double)data->game->wall_start
			- (double)data->raycaster->height_3d / 2
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
		mlx_put_pixel(data->game->ddd, pixels_2d, screen_y,
			tex_buff[tex_y][data->game->tex_x]);
		screen_y++;
	}
}
