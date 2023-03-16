/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 18:12:34 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/16 18:18:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	sprite_computing(t_vault *data, int i)
{
	data->s_par->s_diff_col
		= data->s_par->s[data->s_par->s_prio[i]].s_row - (data->plr->row);
	data->s_par->s_diff_row
		= data->s_par->s[data->s_par->s_prio[i]].s_col - (data->plr->col);
	data->s_par->inv_det = 1.0 / (data->raycaster->plane_x * data->plr->pdy
			- data->plr->pdx * data->raycaster->plane_y);
	data->s_par->tr_x
		= data->s_par->inv_det * (data->plr->pdy * data->s_par->s_diff_row
			- data->plr->pdx * data->s_par->s_diff_col);
	data->s_par->tr_y
		= data->s_par->inv_det * (-data->raycaster->plane_y
			* data->s_par->s_diff_row + data->raycaster->plane_x
			* data->s_par->s_diff_col);
	data->s_par->s_sc_x = (int)((WIDTH / 2)
			* (1 + data->s_par->tr_x / data->s_par->tr_y));
	sprite_computing2(data);
}

void	sprite_computing2(t_vault *data)
{
	data->s_par->s_h = abs((int)(HEIGHT / data->s_par->tr_y));
	data->s_par->s_ds_y = -data->s_par->s_h / 2 + HEIGHT / 2;
	if (data->s_par->s_ds_y < 0)
		data->s_par->s_ds_y = 0;
	data->s_par->s_de_y = data->s_par->s_h / 2 + HEIGHT / 2;
	if (data->s_par->s_de_y >= HEIGHT)
		data->s_par->s_de_y = HEIGHT - 1;
	data->s_par->s_w = abs((int)(HEIGHT / data->s_par->tr_y));
	data->s_par->s_ds_x = -data->s_par->s_w / 2 + data->s_par->s_sc_x;
	if (data->s_par->s_ds_x < 0)
		data->s_par->s_ds_x = 0;
	data->s_par->s_de_x = data->s_par->s_w / 2 + data->s_par->s_sc_x;
	if (data->s_par->s_de_x >= WIDTH)
		data->s_par->s_de_x = WIDTH - 1;
}

double	b_factor_sprites(double distance)
{
	double	max_distance;
	double	brightness_factor;

	max_distance = 15.0;
	if (distance > max_distance)
		distance = max_distance;
	brightness_factor = 1 - (distance / max_distance);
	if (brightness_factor < 0.0)
		brightness_factor = 0.0;
	return (brightness_factor);
}
