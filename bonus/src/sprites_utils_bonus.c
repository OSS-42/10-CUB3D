/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:36:27 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/14 16:01:02 by ewurstei         ###   ########.fr       */
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
	data->s_par->s[0].s_row = 8.5; //marc
	data->s_par->s[0].s_col = 9.5;
	data->s_par->s[0].texture = 1;

	data->s_par->s[1].s_row = 34.5; //legion
	data->s_par->s[1].s_col = 8.5;
	data->s_par->s[1].texture = 2;

	data->s_par->s[2].s_row = 8.5; //poteau au fond a gauche
	data->s_par->s[2].s_col = 15.5;
	data->s_par->s[2].texture = 3;

	data->s_par->s[3].s_row = 8.5; //poteau au fond a droite
	data->s_par->s[3].s_col = 20.5;
	data->s_par->s[3].texture = 3;

	data->s_par->s[4].s_row = 12.5; //poteau
	data->s_par->s[4].s_col = 15.5;
	data->s_par->s[4].texture = 3;

	data->s_par->s[5].s_row = 12.5; //poteau
	data->s_par->s[5].s_col = 20.5;
	data->s_par->s[5].texture = 3;

	data->s_par->s[6].s_row = 16.5; //poteau
	data->s_par->s[6].s_col = 15.5;
	data->s_par->s[6].texture = 3;

	data->s_par->s[7].s_row = 16.5; //poteau
	data->s_par->s[7].s_col = 20.5;
	data->s_par->s[7].texture = 3;

	data->s_par->s[8].s_row = 20.5; //poteau
	data->s_par->s[8].s_col = 15.5;
	data->s_par->s[8].texture = 3;

	data->s_par->s[9].s_row = 20.5; //poteau
	data->s_par->s[9].s_col = 20.5;
	data->s_par->s[9].texture = 3;

	data->s_par->s[10].s_row = 33.5; //feu
	data->s_par->s[10].s_col = 8.5;
	data->s_par->s[10].texture = 4;

	data->s_par->s[11].s_row = 7.5; //plantes
	data->s_par->s[11].s_col = 20.5;
	data->s_par->s[11].texture = 5;

	data->s_par->s[12].s_row = 17.5; //plantes
	data->s_par->s[12].s_col = 20.5;
	data->s_par->s[12].texture = 5;

	data->s_par->s[13].s_row = 19.5; //plantes
	data->s_par->s[13].s_col = 20.5;
	data->s_par->s[13].texture = 5;

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
	print_sprite_order(data);
}

void	print_sprite_order(t_vault *data)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		printf("%d sprites à dessiner est le sprite numéro %d\n", i, data->s_par->s_prio[i]);
		printf("qui est a une distance de %f case\n", data->s_par->s_dist[i]);
		i++;
	}
	printf("\n");
}
