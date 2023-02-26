/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:38:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/26 10:56:34 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	move_forward(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->player->row + data->player->pdy
			* data->raycaster->mov_speed);
	check_col = (int)(data->player->col + data->player->pdx
			* data->raycaster->mov_speed);
	if ((data->map->map[check_row][(int)(data->player->col)] != '1')
			&& (data->map->map[check_row][(int)(data->player->col)] != '2'))
		data->player->row += data->player->pdy * data->raycaster->mov_speed;
	if ((data->map->map[(int)(data->player->row)][check_col] != '1')
			&& (data->map->map[(int)(data->player->row)][check_col] != '2'))
		data->player->col = data->player->col + data->player->pdx
			* data->raycaster->mov_speed;
}


void	move_backward(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->player->row - data->player->pdy
			* data->raycaster->mov_speed);
	check_col = (int)(data->player->col - data->player->pdx
			* data->raycaster->mov_speed);
	if ((data->map->map[check_row][(int)(data->player->col)] != '1')
			&& (data->map->map[check_row][(int)(data->player->col)] != '2'))
		data->player->row = data->player->row - data->player->pdy
			* data->raycaster->mov_speed;
	if ((data->map->map[(int)(data->player->row)][check_col] != '1')
			&& (data->map->map[(int)(data->player->row)][check_col] != '2'))
		data->player->col = data->player->col - data->player->pdx
			* data->raycaster->mov_speed;
}

void	move_left(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->player->row - data->raycaster->plane_y
			* data->raycaster->mov_speed);
	check_col = (int)(data->player->col - data->raycaster->plane_x
			* data->raycaster->mov_speed);
	if ((data->map->map[check_row][(int)(data->player->col)] != '1')
			&& (data->map->map[check_row][(int)(data->player->col)] != '2'))
		data->player->row = data->player->row - data->raycaster->plane_y
			* data->raycaster->mov_speed;
	if ((data->map->map[(int)(data->player->row)][check_col] != '1')
			&& (data->map->map[(int)(data->player->row)][check_col] != '2'))
		data->player->col = data->player->col - data->raycaster->plane_x
			* data->raycaster->mov_speed;
}

void	move_right(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->player->row + data->raycaster->plane_y
			* data->raycaster->mov_speed);
	check_col = (int)(data->player->col + data->raycaster->plane_x
			* data->raycaster->mov_speed);
	if ((data->map->map[check_row][(int)(data->player->col)] != '1')
			&& (data->map->map[check_row][(int)(data->player->col)] != '2'))
		data->player->row = data->player->row + data->raycaster->plane_y
			* data->raycaster->mov_speed;
	if ((data->map->map[(int)(data->player->row)][check_col] != '1')
			&& (data->map->map[(int)(data->player->row)][check_col] != '2'))
		data->player->col = data->player->col + data->raycaster->plane_x
			* data->raycaster->mov_speed;
}

void	move_mouse(double xpos, double ypos, void *temp)
{
	t_vault	*data;
	double	old_player_pdx;
	double	old_plane_x;
	double	delta_x;

	(void)ypos;
	data = (t_vault *) temp;
	old_player_pdx = data->player->pdx;
	delta_x = xpos - data->old_x_cursor;
	delta_x *= 0.005;
	data->player->pdx = data->player->pdx * cos(-delta_x)
		- data->player->pdy * sin(delta_x);
	data->player->pdy = old_player_pdx * sin(delta_x)
		+ data->player->pdy * cos(delta_x);
	old_plane_x = data->raycaster->plane_x;
	data->raycaster->plane_x = data->raycaster->plane_x
		* cos(delta_x) - data->raycaster->plane_y * sin(delta_x);
	data->raycaster->plane_y = old_plane_x * sin(delta_x)
		+ data->raycaster->plane_y * cos(delta_x);
	data->old_x_cursor = xpos;
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	reinit_3d(data);
	reinit_hud(data);
	reinit_minimap(data);
	raycaster(data);
}
