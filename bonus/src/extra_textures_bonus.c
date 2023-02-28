/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:45:59 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/28 11:36:17 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_extra_textures(t_vault *data)
{
	data->tex->tex_nw = mlx_load_xpm42(data->scene_param->nw_wall_path);
	data->tex->tex_collect = mlx_load_xpm42("./assets/tex/hud_coll.xpm42");
	data->tex->tex_amphi = mlx_load_xpm42("./assets/tex/hud_amphi.xpm42");
	data->tex->tex_bocal = mlx_load_xpm42("./assets/tex/hud_bocal.xpm42");
	data->tex->tex_c1 = mlx_load_xpm42("./assets/tex/hud_c1.xpm42");
	data->tex->tex_c2 = mlx_load_xpm42("./assets/tex/hud_c2.xpm42");
	data->tex->tex_c3 = mlx_load_xpm42("./assets/tex/hud_c3.xpm42");
	data->tex->tex_couloir = mlx_load_xpm42("./assets/tex/hud_couloir.xpm42");
	data->tex->tex_cuisine = mlx_load_xpm42("./assets/tex/hud_cuisine.xpm42");
	data->tex->tex_detente = mlx_load_xpm42("./assets/tex/hud_detente.xpm42");
	data->tex->tex_lobby = mlx_load_xpm42("./assets/tex/hud_lobby.xpm42");
	data->tex->tex_lounge = mlx_load_xpm42("./assets/tex/hud_lounge.xpm42");
	data->tex->tex_jeux = mlx_load_xpm42("./assets/tex/hud_jeux.xpm42");
	data->tex->tex_reunion = mlx_load_xpm42("./assets/tex/hud_reunion.xpm42");
	data->tex->tex_secret = mlx_load_xpm42("./assets/tex/hud_secret.xpm42");
	data->tex->tex_door = mlx_load_xpm42("./assets/tex/tribute2.xpm42");
	get_extra_textures(data);
}

void	get_extra_textures(t_vault *data)
{
	if (!data->tex->tex_nw || !data->tex->tex_collect || !data->tex->tex_amphi
		|| !data->tex->tex_bocal || !data->tex->tex_c1 || !data->tex->tex_c2
		|| !data->tex->tex_c3 || !data->tex->tex_couloir
		|| !data->tex->tex_cuisine || !data->tex->tex_detente
		|| !data->tex->tex_lobby || !data->tex->tex_lounge
		|| !data->tex->tex_jeux || !data->tex->tex_reunion
		|| !data->tex->tex_secret || !data->tex->tex_secret
		|| !data->tex->tex_door)
		quit_game(data);
	data->tex->neutral_wall = get_texture(data->tex->tex_nw);
	data->tex->collect = get_texture(data->tex->tex_collect);
	data->tex->amphi = get_texture(data->tex->tex_amphi);
	data->tex->bocal = get_texture(data->tex->tex_bocal);
	data->tex->c1 = get_texture(data->tex->tex_c1);
	data->tex->c2 = get_texture(data->tex->tex_c2);
	data->tex->c3 = get_texture(data->tex->tex_c3);
	data->tex->couloir = get_texture(data->tex->tex_couloir);
	data->tex->cuisine = get_texture(data->tex->tex_cuisine);
	data->tex->detente = get_texture(data->tex->tex_detente);
	data->tex->lobby = get_texture(data->tex->tex_lobby);
	data->tex->lounge = get_texture(data->tex->tex_lounge);
	data->tex->jeux = get_texture(data->tex->tex_jeux);
	data->tex->reunion = get_texture(data->tex->tex_reunion);
	data->tex->secret = get_texture(data->tex->tex_secret);
	data->tex->door = get_texture(data->tex->tex_door);
}
