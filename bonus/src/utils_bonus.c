/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:01:38 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/07 17:50:31 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_wall_path(t_vault *data)
{
	int	fd;

	fd = open(data->scene_param->no_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	fd = open(data->scene_param->so_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	fd = open(data->scene_param->we_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	fd = open(data->scene_param->ea_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	errors(data);
}

void	full_line_hud_hor(mlx_image_t *hud, int screen_y, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = 200 - 1;
	while (start < len)
	{
		mlx_put_pixel(hud, start, screen_y, color);
		start++;
	}
}

void	full_line_hud_ver(mlx_image_t *hud, int screen_x, unsigned int color)
{
	int	start;
	int	len;

	start = 0;
	len = 50 - 1;
	while (start < len)
	{
		mlx_put_pixel(hud, screen_x, start, color);
		start++;
	}
}

int	is_not_wall_limited(t_vault *data, int row, int col)
{
	if (data->map->map[row][col] != '1'
		&& data->map->map[row][col] != '2'
		&& data->map->map[row][col] != '3'
		&& data->map->map[row][col] != '4'
		&& data->map->map[row][col] != '5'
		&& data->map->map[row][col] != '6'
		&& data->map->map[row][col] != '7'
		&& data->map->map[row][col] != '8'
		&& data->map->map[row][col] != '9'
		&& data->map->map[row][col] != 'Z')
		return (TRUE);
	return (FALSE);
}

int	is_not_wall_full(t_vault *data, int row, int col)
{
	if (data->map->map[row][col] != '1'
		&& data->map->map[row][col] != '2'
		&& data->map->map[row][col] != '3'
		&& data->map->map[row][col] != '4'
		&& data->map->map[row][col] != '5'
		&& data->map->map[row][col] != '6'
		&& data->map->map[row][col] != '7'
		&& data->map->map[row][col] != '8'
		&& data->map->map[row][col] != '9'
		&& data->map->map[row][col] != 'D'
		&& data->map->map[row][col] != 'Z')
		return (TRUE);
	return (FALSE);
}
