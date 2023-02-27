/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:45:59 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/26 14:20:58 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_extra_textures(t_vault *data)
{
	data->tex->tex_nw = mlx_load_xpm42(data->scene_param->nw_wall_path);
	if (!data->tex->tex_nw)
		quit_game(data);
	data->tex->neutral_wall = get_texture(data->tex->tex_nw);
	data->tex->tex_collect = mlx_load_xpm42("./assets/textures/hud_coll.xpm42");
	if (!data->tex->tex_collect)
		quit_game(data);
	data->tex->collect = get_texture(data->tex->tex_collect);
	data->tex->tex_amphi = mlx_load_xpm42("./assets/textures/hud_amphi.xpm42");
	if (!data->tex->tex_amphi)
		quit_game(data);
	data->tex->amphi = get_texture(data->tex->tex_amphi);
	data->tex->tex_bocal = mlx_load_xpm42("./assets/textures/hud_bocal.xpm42");
	if (!data->tex->tex_bocal)
		quit_game(data);
	data->tex->bocal = get_texture(data->tex->tex_bocal);
	data->tex->tex_c1 = mlx_load_xpm42("./assets/textures/hud_c1.xpm42");
	if (!data->tex->tex_c1)
		quit_game(data);
	data->tex->c1 = get_texture(data->tex->tex_c1);
	data->tex->tex_c2 = mlx_load_xpm42("./assets/textures/hud_c2.xpm42");
	if (!data->tex->tex_c2)
		quit_game(data);
	data->tex->c2 = get_texture(data->tex->tex_c2);
	data->tex->tex_c3 = mlx_load_xpm42("./assets/textures/hud_c3.xpm42");
	if (!data->tex->tex_c3)
		quit_game(data);
	data->tex->c3 = get_texture(data->tex->tex_c3);
	data->tex->tex_couloir = mlx_load_xpm42("./assets/textures/hud_couloir.xpm42");
	if (!data->tex->tex_couloir)
		quit_game(data);
	data->tex->couloir = get_texture(data->tex->tex_couloir);
	data->tex->tex_cuisine = mlx_load_xpm42("./assets/textures/hud_cuisine.xpm42");
	if (!data->tex->tex_cuisine)
		quit_game(data);
	data->tex->cuisine = get_texture(data->tex->tex_cuisine);
	data->tex->tex_detente = mlx_load_xpm42("./assets/textures/hud_detente.xpm42");
	if (!data->tex->tex_detente)
		quit_game(data);
	data->tex->detente = get_texture(data->tex->tex_detente);
	data->tex->tex_lobby = mlx_load_xpm42("./assets/textures/hud_lobby.xpm42");
	if (!data->tex->tex_lobby)
		quit_game(data);
	data->tex->lobby = get_texture(data->tex->tex_lobby);
	data->tex->tex_lounge = mlx_load_xpm42("./assets/textures/hud_lounge.xpm42");
	if (!data->tex->tex_lounge)
		quit_game(data);
	data->tex->lounge = get_texture(data->tex->tex_lounge);
	data->tex->tex_jeux = mlx_load_xpm42("./assets/textures/hud_jeux.xpm42");
	if (!data->tex->tex_jeux)
		quit_game(data);
	data->tex->jeux = get_texture(data->tex->tex_jeux);
	data->tex->tex_reunion = mlx_load_xpm42("./assets/textures/hud_reunion.xpm42");
	if (!data->tex->tex_reunion)
		quit_game(data);
	data->tex->reunion = get_texture(data->tex->tex_reunion);
	data->tex->tex_secrete = mlx_load_xpm42("./assets/textures/hud_secret.xpm42");
	if (!data->tex->tex_secrete)
		quit_game(data);
	data->tex->secrete = get_texture(data->tex->tex_secrete);
		data->tex->tex_light = mlx_load_xpm42("./assets/textures/greenlight.xpm42");
	if (!data->tex->tex_light)
		quit_game(data);
	data->tex->light = get_texture(data->tex->tex_light);
}

void	player_location(t_vault *data)
{
	data->hud_loc->location = 0;
	data->hud_loc->p_loc = data->tex->lobby;
	if (data->player->row >= 27 && data->player->row < 31 && data->player->col < 13)
	{
		data->hud_loc->location = 0; // lobby
		data->hud_loc->p_loc = data->tex->lobby;
	}
	else if (data->player->row >= 31 && data->player->col >= 13)
	{
		data->hud_loc->location = 1; // salle de reunion
		data->hud_loc->p_loc = data->tex->reunion;
	}
	else if (data->player->row >= 23 && data->player->row < 31 && data->player->col >= 13)
	{
		data->hud_loc->location = 2; // salles de jeu
		data->hud_loc->p_loc = data->tex->jeux;
	}
	else if (data->player->row >= 22 && data->player->row < 27 && data->player->col < 8)
	{
		data->hud_loc->location = 3; // cuisine
		data->hud_loc->p_loc = data->tex->cuisine;
	}
	else if (data->player->row >= 18 && data->player->row < 25 && data->player->col < 13 && data->player->col >= 7)
	{
		data->hud_loc->location = 4; // couloir de la muerte
		data->hud_loc->p_loc = data->tex->couloir;
	}
	else if (data->player->row >= 12 && data->player->row < 23 && data->player->col >= 13)
	{
		data->hud_loc->location = 5; // cluster 1
		data->hud_loc->p_loc = data->tex->c1;
	}
	else if (data->player->row >= 3 && data->player->row < 12 && data->player->col >= 13)
	{
		data->hud_loc->location = 6; // cluster 2
		data->hud_loc->p_loc = data->tex->c2;
	}
	else if (data->player->row >= 0 && data->player->row < 3 && data->player->col >= 13)
	{
		data->hud_loc->location = 7; // salle detente		
		data->hud_loc->p_loc = data->tex->detente;
	}
	else if (data->player->row >= 15 && data->player->row < 20 && data->player->col < 7)
	{
		data->hud_loc->location = 8; // amphi
		data->hud_loc->p_loc = data->tex->amphi;
	}
	else if (data->player->row >= 0 && data->player->row < 15 && data->player->col < 7)
	{
		data->hud_loc->location = 9; // cluster 3
		data->hud_loc->p_loc = data->tex->c3;
	}
	else if (data->player->row >= 10 && data->player->row < 14 && data->player->col >= 7 && data->player->col < 13)
	{
		data->hud_loc->location = 10; // attention danger, BOCAL !
		data->hud_loc->p_loc = data->tex->bocal;
	}
	else if (data->player->row >= 0 && data->player->row < 7 && data->player->col >= 7 && data->player->col < 13)
	{
		data->hud_loc->location = 11; // lounge
		data->hud_loc->p_loc = data->tex->lounge;
	}
	// else if (data->player->row >= 0 && data->player->row < 7 && data->player->col >= 7 && data->player->col < 13)
	// {
	// 	data->hud_loc->location = 12; // salle secrete
	// 	data->hud_loc->p_loc = data->tex->secrete;
	// }
}
