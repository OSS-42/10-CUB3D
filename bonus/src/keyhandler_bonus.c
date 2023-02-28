/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhandler_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:27:09 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/28 15:01:04 by ewurstei         ###   ########.fr       */
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
	keyhandler_2(keydata, data);
}

void	keyhandler_2(mlx_key_data_t keydata, t_vault *data)
{
	if (keydata.key == MLX_KEY_D
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_right(data, 0, 0);
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_left(data);
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_right(data);
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		quit_game(data);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		show_minimap(data);
	if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
		open_door(data);
	reinit_and_draw(data);
}

void	open_door(t_vault *data)
{
	int	row;
	int	col;

	row = data->player->row + data->player->pdy * 0.5;
	col = data->player->col + data->player->pdx * 0.5;
	if (data->map->map[row][col] == 'D')
	{
		data->map->map[row][col] = '0';
		reinit_and_draw(data);
	}
}
