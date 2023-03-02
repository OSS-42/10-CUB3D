/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:38:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/02 10:13:44 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	move_forward(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->plr->row + data->plr->pdy
			* data->raycaster->mov_speed);
	check_col = (int)(data->plr->col + data->plr->pdx
			* data->raycaster->mov_speed);
	if (not_wall(data, check_row, (int)(data->plr->col)) == TRUE)
	{
		data->plr->old_row = data->plr->row;
		data->plr->row += data->plr->pdy * data->raycaster->mov_speed;
	}
	if (not_wall(data, (int)(data->plr->row), check_col) == TRUE)
	{
		data->plr->old_col = data->plr->col;
		data->plr->col += data->plr->pdx * data->raycaster->mov_speed;
	}
	check_and_play_song(data);
}

void	move_backward(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->plr->row - data->plr->pdy
			* data->raycaster->mov_speed);
	check_col = (int)(data->plr->col - data->plr->pdx
			* data->raycaster->mov_speed);
	if (not_wall(data, check_row, (int)(data->plr->col)) == TRUE)
	{
		data->plr->old_row = data->plr->row;
		data->plr->row -= data->plr->pdy * data->raycaster->mov_speed;
	}
	if (not_wall(data, (int)(data->plr->row), check_col) == TRUE)
	{
		data->plr->old_col = data->plr->col;
		data->plr->col -= data->plr->pdx * data->raycaster->mov_speed;
	}
	check_and_play_song(data);
}

void	move_left(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->plr->row - data->raycaster->plane_y
			* data->raycaster->mov_speed);
	check_col = (int)(data->plr->col - data->raycaster->plane_x
			* data->raycaster->mov_speed);
	if (not_wall(data, check_row, (int)(data->plr->col)) == TRUE)
	{
		data->plr->old_row = data->plr->row;
		data->plr->row -= data->raycaster->plane_y
			* data->raycaster->mov_speed;
	}
	if (not_wall(data, (int)(data->plr->row), check_col) == TRUE)
	{
		data->plr->old_col = data->plr->col;
		data->plr->col -= data->raycaster->plane_x
			* data->raycaster->mov_speed;
	}
	check_and_play_song(data);
}

void	move_right(t_vault *data, int check_row, int check_col)
{
	check_row = (int)(data->plr->row + data->raycaster->plane_y
			* data->raycaster->mov_speed);
	check_col = (int)(data->plr->col + data->raycaster->plane_x
			* data->raycaster->mov_speed);
	if (not_wall(data, check_row, (int)(data->plr->col)) == TRUE)
	{
		data->plr->old_row = data->plr->row;
		data->plr->row += data->raycaster->plane_y
			* data->raycaster->mov_speed;
	}
	if (not_wall(data, (int)(data->plr->row), check_col) == TRUE)
	{
		data->plr->old_col = data->plr->col;
		data->plr->col += data->raycaster->plane_x
			* data->raycaster->mov_speed;
	}
	check_and_play_song(data);
}

void	move_mouse(double xpos, double ypos, void *temp)
{
	t_vault	*data;
	double	old_player_pdx;
	double	old_plane_x;
	double	delta_x;

	(void)ypos;
	data = (t_vault *) temp;
	old_player_pdx = data->plr->pdx;
	delta_x = xpos - data->old_x_cursor;
	delta_x *= 0.005;
	data->plr->pdx = data->plr->pdx * cos(-delta_x)
		- data->plr->pdy * sin(delta_x);
	data->plr->pdy = old_player_pdx * sin(delta_x)
		+ data->plr->pdy * cos(delta_x);
	old_plane_x = data->raycaster->plane_x;
	data->raycaster->plane_x = data->raycaster->plane_x
		* cos(delta_x) - data->raycaster->plane_y * sin(delta_x);
	data->raycaster->plane_y = old_plane_x * sin(delta_x)
		+ data->raycaster->plane_y * cos(delta_x);
	data->old_x_cursor = xpos;
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_DISABLED);
	reinit_and_draw(data);
}
