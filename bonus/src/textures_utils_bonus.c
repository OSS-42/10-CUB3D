/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_utils_bonuc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 11:19:59 by maison            #+#    #+#             */
/*   Updated: 2023/03/05 11:20:08 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	find_tex_hit(t_vault *data, xpm_t *texture)
{
	double	wall_x;
	int		side;

	side = data->raycaster->side;
	if (side == 0 || side == 1 || side == 4 || side == 5 || side == 8
		|| side == 9 || side == 12 || side == 13 || side == 16 || side == 17
		|| side == 20 || side == 21 || side == 24 || side == 25 || side == 28
		|| side == 29 || side == 32 || side == 33 || side == 36 || side == 37
		|| side == 40 || side == 41)
		wall_x = data->plr->row + data->raycaster->ray_len
			* data->raycaster->pdy_ray;
	else
		wall_x = data->plr->col + data->raycaster->ray_len
			* data->raycaster->pdx_ray;
	wall_x = wall_x - (int)(wall_x);
	data->game->tex_x = abs((int)(1 - wall_x
				* (double)(texture->texture.width)));
	if (data->game->tex_x < 0)
		data->game->tex_x = 0;
	else if (data->game->tex_x >= (int)texture->texture.width)
		data->game->tex_x = texture->texture.width - 1;
	find_tex_hit2(data, texture, side);
}

void	find_tex_hit2(t_vault *data, xpm_t *texture, int side)
{
	if ((side == 0 || side == 1 || side == 4 || side == 5 || side == 8
			|| side == 9 || side == 12 || side == 13 || side == 16
			|| side == 17 || side == 20 || side == 21 || side == 24
			|| side == 25 || side == 28 || side == 29 || side == 32
			|| side == 33 || side == 36 || side == 37 || side == 40
			|| side == 41) && data->raycaster->pdx_ray < 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
	if ((side == 2 || side == 3 || side == 6 || side == 7 || side == 10
			|| side == 11 || side == 14 || side == 15 || side == 18
			|| side == 19 || side == 22 || side == 23 || side == 26
			|| side == 27 || side == 30 || side == 31 || side == 34
			|| side == 35 || side == 38 || side == 39 || side == 42
			|| side == 43) && data->raycaster->pdy_ray > 0)
		data->game->tex_x = texture->texture.width - data->game->tex_x - 1;
}
