/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:38:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/13 11:08:34 by ewurstei         ###   ########.fr       */
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
	data->player->ppx = data->player->ppx + data->player->pdx;
	data->player->ppy = data->player->ppy + data->player->pdy;
	draw_player(data);
}

void	move_backward(t_vault *data)
{
	reinit_minimap(data);
	data->player->ppx = data->player->ppx - data->player->pdx;
	data->player->ppy = data->player->ppy - data->player->pdy;
	draw_player(data);
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
