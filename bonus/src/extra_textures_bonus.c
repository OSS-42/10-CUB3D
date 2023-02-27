/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:45:59 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/27 15:07:14 by mbertin          ###   ########.fr       */
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
	data->tex->tex_secrete = mlx_load_xpm42("./assets/tex/hud_reunion.xpm42");
	if (!data->tex->tex_nw || !data->tex->tex_collect || !data->tex->tex_amphi
		|| !data->tex->tex_bocal || !data->tex->tex_c1 || !data->tex->tex_c2
		|| !data->tex->tex_c3 || !data->tex->tex_couloir
		|| !data->tex->tex_cuisine || !data->tex->tex_detente
		|| !data->tex->tex_lobby || !data->tex->tex_lounge
		|| !data->tex->tex_jeux || !data->tex->tex_reunion
		|| !data->tex->tex_secrete)
		quit_game(data);
	get_extra_textures(data);
}

void	get_extra_textures(t_vault *data)
{
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
	data->tex->secrete = get_texture(data->tex->tex_secrete);
}

void	player_location(t_vault *data, int col, int row)
{
	data->hud_loc->location = 0;
	data->hud_loc->p_loc = data->tex->lobby;
	row = data->player->row;
	col = data->player->col;
	if (row >= 27 && row < 31 && col < 13)
	{
		data->hud_loc->location = 0;
		data->hud_loc->p_loc = data->tex->lobby;
	}
	else if (row >= 31 && col >= 13)
	{
		data->hud_loc->location = 1;
		data->hud_loc->p_loc = data->tex->reunion;
	}
	else if (row >= 23 && row < 31 && col >= 13)
	{
		data->hud_loc->location = 2;
		data->hud_loc->p_loc = data->tex->jeux;
	}
	else
		player_location_3(data, col, row);
}

void	player_location_2(t_vault *data, int col, int row)
{
	if (row >= 22 && row < 27 && col < 8)
	{
		data->hud_loc->location = 3;
		data->hud_loc->p_loc = data->tex->cuisine;
	}
	else if (row >= 18 && row < 25 && col < 13 && col >= 7)
	{
		data->hud_loc->location = 4;
		data->hud_loc->p_loc = data->tex->couloir;
	}
	else if (row >= 12 && row < 23 && col >= 13)
	{
		data->hud_loc->location = 5;
		data->hud_loc->p_loc = data->tex->c1;
	}
	else if (row >= 3 && row < 12 && col >= 13)
	{
		data->hud_loc->location = 6;
		data->hud_loc->p_loc = data->tex->c2;
	}
	else
		player_location_3(data, col, row);
}

void	player_location_3(t_vault *data, int col, int row)
{
	if (row >= 0 && row < 3 && col >= 13)
	{
		data->hud_loc->location = 7;
		data->hud_loc->p_loc = data->tex->detente;
	}
	else if (row >= 15 && row < 20 && col < 7)
	{
		data->hud_loc->location = 8;
		data->hud_loc->p_loc = data->tex->amphi;
	}
	else if (row >= 0 && row < 15 && col < 7)
	{
		data->hud_loc->location = 9;
		data->hud_loc->p_loc = data->tex->c3;
	}
	else if (row >= 10 && row < 14 && col >= 7 && col < 13)
	{
		data->hud_loc->location = 10;
		data->hud_loc->p_loc = data->tex->bocal;
	}
	else if (row >= 0 && row < 7 && col >= 7 && col < 13)
	{
		data->hud_loc->location = 11;
		data->hud_loc->p_loc = data->tex->lounge;
	}
}
