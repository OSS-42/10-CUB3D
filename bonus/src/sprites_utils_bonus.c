/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:36:27 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/16 21:45:30 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_sprites(t_vault *data)
{
	data->game->sprite = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data->mlx, data->game->sprite, 0, 0);
}

void	reinit_sprites(t_vault *data)
{
	mlx_delete_image(data->mlx, data->game->sprite);
	load_sprites(data);
}

void	load_sprites_coord(t_vault *data)
{
	data->s_par->s[0].s_row = 8.5;
	data->s_par->s[0].s_col = 9.5;
	data->s_par->s[0].texture = 1;
	data->s_par->s[1].s_row = 34.5;
	data->s_par->s[1].s_col = 14.5;
	data->s_par->s[1].texture = 2;
	data->s_par->s[2].s_row = 16.5;
	data->s_par->s[2].s_col = 4.5;
	data->s_par->s[2].texture = 4;
	data->s_par->s[3].s_row = 1.5;
	data->s_par->s[3].s_col = 22.5;
	data->s_par->s[3].texture = 6;
	data->s_par->s[4].s_row = 25.5;
	data->s_par->s[4].s_col = 20.5;
	data->s_par->s[4].texture = 7;
	data->s_par->s[5].s_row = 29.5;
	data->s_par->s[5].s_col = 13.5;
	data->s_par->s[5].texture = 8;
	data->s_par->s[6].s_row = 12.5;
	data->s_par->s[6].s_col = 11.5;
	data->s_par->s[6].texture = 10;
	data->s_par->s[114].s_row = 33.5;
	data->s_par->s[114].s_col = 8.5;
	data->s_par->s[114].texture = 12;
	load_c1_spt_pot(data);
}

void	sprite_ordering(t_vault *data)
{
	int	i;

	i = 0;
	while (i < NUMSPRITES)
	{
		data->s_par->s_prio[i] = i;
		data->s_par->s_dist[i]
			= ((data->plr->row - data->s_par->s[i].s_row)
				* (data->plr->row - data->s_par->s[i].s_row)
				+ (data->plr->col - data->s_par->s[i].s_col)
				* (data->plr->col - data->s_par->s[i].s_col));
		i++;
	}
	sort_sprites(data);
}

void	sort_sprites(t_vault *data)
{
	int		i;
	int		j;
	double	tmp_dist;
	double	tmp_prio;

	i = 0;
	while (i < NUMSPRITES)
	{
		j = 0;
		while (j < NUMSPRITES - 1)
		{
			if (data->s_par->s_dist[j] < data->s_par->s_dist[j + 1])
			{
				tmp_dist = data->s_par->s_dist[j];
				data->s_par->s_dist[j] = data->s_par->s_dist[j + 1];
				data->s_par->s_dist[j + 1] = tmp_dist;
				tmp_prio = data->s_par->s_prio[j];
				data->s_par->s_prio[j] = data->s_par->s_prio[j + 1];
				data->s_par->s_prio[j + 1] = tmp_prio;
			}
			j++;
		}
		i++;
	}
}
