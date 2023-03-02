/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:01:38 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/01 23:26:31 by ewurstei         ###   ########.fr       */
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

void	reinit_and_draw(t_vault *data)
{
	reinit_3d(data);
	reinit_hud(data);
	reinit_minimap(data);
	raycaster(data);
}
