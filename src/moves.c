/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:38:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/21 14:17:58 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	reinit_minimap(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	load_minimap(data);
}

void	move_forward(t_vault *data)
{
	reinit_minimap(data);
	data->player->ppx = data->player->ppx + data->player->pdx * 5;
	data->player->ppy = data->player->ppy + data->player->pdy * 5;
	draw_player(data);
	raycaster(data);
}

void	move_backward(t_vault *data)
{
	reinit_minimap(data);
	data->player->ppx = data->player->ppx - data->player->pdx * 5;
	data->player->ppy = data->player->ppy - data->player->pdy * 5;
	draw_player(data);
	raycaster(data);
}

//void	move_left(t_vault *data)
// {
// 	reinit_minimap(data);
//
// 	draw_player(data);
// }

//void	move_right(t_vault *data)
// {
// 	reinit_minimap(data);
//
// 	draw_player(data);
// }
