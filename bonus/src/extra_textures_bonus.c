/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:45:59 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/24 16:09:53 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_extra_textures(t_vault *data)
{
	data->tex->tex_nw = mlx_load_xpm42(data->scene_param->nw_wall_path);
	if (!data->tex->tex_nw)
		quit_game(data);
	data->tex->neutral_wall = get_texture(data->tex->tex_nw);
}