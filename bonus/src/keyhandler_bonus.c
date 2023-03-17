/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:27:09 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/17 09:35:32 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	keyhandler(mlx_key_data_t keydata, void *param)
{
	t_vault	*data;

	data = (t_vault *) param;
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_forward(data, 0, 0);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_backward(data, 0, 0);
	if (keydata.key == MLX_KEY_A
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_left(data, 0, 0);
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_right(data, 0, 0);
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_left(data);
	keyhandler_2(keydata, data);
}

void	keyhandler_2(mlx_key_data_t keydata, t_vault *data)
{
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_right(data);
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		quit_game(data);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
	{
		if (data->minimap->on_screen == 1)
		{
			mlx_delete_image(data->mlx, data->minimap->minimap);
			data->minimap->on_screen = 0;
		}
		else
		{
			data->minimap->on_screen = 1;
			show_minimap(data);
		}
	}
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		open_door(data);
}

void	open_door(t_vault *data)
{
	int	row;
	int	col;

	row = data->plr->row + data->plr->pdy * 0.5;
	col = data->plr->col + data->plr->pdx * 0.5;
	if (data->map->map[row][col] == 'D')
	{
		system("afplay ./assets/audio/H2G2-door_open.mp3&");
		data->map->map[row][col] = 'W';
	}
	else if (data->map->map[row][col] == 'Z')
	{
		system("afplay ./assets/audio/H2G2-door_open.mp3&");
		if (data->audio == FALSE)
		{
			system("afplay ./assets/audio/exam-final.mp3&");
			data->audio = TRUE;
		}
		data->map->map[row][col] = 'X';
	}
}

void	close_door(t_vault *data)
{
	if (data->map->map[data->plr->old_row][data->plr->old_col] == 'W'
		&& data->map->map[(int)data->plr->row][(int)data->plr->col] != 'W')
	{
		system("afplay ./assets/audio/H2G2-door_close.mp3&");
		data->map->map[data->plr->old_row][data->plr->old_col] = 'D';
	}
	else if (data->map->map[data->plr->old_row][data->plr->old_col] == 'X'
		&& data->map->map[(int)data->plr->row][(int)data->plr->col] != 'X')
	{
		system("afplay ./assets/audio/H2G2-door_close.mp3&");
		data->map->map[data->plr->old_row][data->plr->old_col] = 'Z';
	}
}
