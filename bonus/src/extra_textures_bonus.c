/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_textures_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:45:59 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/03 11:11:30 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"


//textures 1024x1024 (murs)
// void	load_extra_textures(t_vault *data)
// {
// 	data->tex->tex_amphi = mlx_load_xpm42("./assets/tex/hud_amphi_SD.xpm42");
// 	data->tex->tex_bocal = mlx_load_xpm42("./assets/tex/hud_bocal_SD.xpm42");
// 	data->tex->tex_c1 = mlx_load_xpm42("./assets/tex/hud_c1_SD.xpm42");
// 	data->tex->tex_c2 = mlx_load_xpm42("./assets/tex/hud_c2_SD.xpm42");
// 	data->tex->tex_c3 = mlx_load_xpm42("./assets/tex/hud_c3_SD.xpm42");
// 	data->tex->tex_couloir = mlx_load_xpm42("./assets/tex/hud_coul_SD.xpm42");
// 	data->tex->tex_cuisine = mlx_load_xpm42("./assets/tex/hud_cuis_SD.xpm42");
// 	data->tex->tex_detente = mlx_load_xpm42("./assets/tex/hud_det_SD.xpm42");
// 	data->tex->tex_lobby = mlx_load_xpm42("./assets/tex/hud_lobby_SD.xpm42");
// 	data->tex->tex_lounge = mlx_load_xpm42("./assets/tex/hud_lounge_SD.xpm42");
// 	data->tex->tex_jeux = mlx_load_xpm42("./assets/tex/hud_jeux_SD.xpm42");
// 	data->tex->tex_reunion = mlx_load_xpm42("./assets/tex/hud_reun_SD.xpm42");
// 	data->tex->tex_secret = mlx_load_xpm42("./assets/tex/hud_secret_SD.xpm42");
// 	data->tex->tex_local = mlx_load_xpm42("./assets/tex/hud_local_SD.xpm42");
// 	data->tex->tex_window = mlx_load_xpm42("./assets/tex/window42_SD.xpm42");
// 	data->tex->tex_door = mlx_load_xpm42("./assets/tex/door42_SD.xpm42");
// 	data->tex->tex_dungeon = mlx_load_xpm42("./assets/tex/dungeon42_SD.xpm42");
// 	data->tex->tex_tribute = mlx_load_xpm42("./assets/tex/dungeon_trib_SD.xpm42");
// 	data->tex->tex_marc = mlx_load_xpm42("./assets/tex/dungeon_marc_SD.xpm42");
// 	data->tex->tex_armada = mlx_load_xpm42("./assets/tex/dungeon_arm_SD.xpm42");
// 	data->tex->tex_torrent = mlx_load_xpm42("./assets/tex/dungeon_tor_SD.xpm42");
// 	check_extra_textures(data);
// }

//textures 256 x256 (murs seulement - changes dans la scene aussi)
void	load_extra_textures(t_vault *data)
{
	data->tex->tex_amphi = mlx_load_xpm42("./assets/tex/hud_amphi_SD.xpm42");
	data->tex->tex_bocal = mlx_load_xpm42("./assets/tex/hud_bocal_SD.xpm42");
	data->tex->tex_c1 = mlx_load_xpm42("./assets/tex/hud_c1_SD.xpm42");
	data->tex->tex_c2 = mlx_load_xpm42("./assets/tex/hud_c2_SD.xpm42");
	data->tex->tex_c3 = mlx_load_xpm42("./assets/tex/hud_c3_SD.xpm42");
	data->tex->tex_couloir = mlx_load_xpm42("./assets/tex/hud_coul_SD.xpm42");
	data->tex->tex_cuisine = mlx_load_xpm42("./assets/tex/hud_cuis_SD.xpm42");
	data->tex->tex_detente = mlx_load_xpm42("./assets/tex/hud_det_SD.xpm42");
	data->tex->tex_lobby = mlx_load_xpm42("./assets/tex/hud_lobby_SD.xpm42");
	data->tex->tex_lounge = mlx_load_xpm42("./assets/tex/hud_lounge_SD.xpm42");
	data->tex->tex_jeux = mlx_load_xpm42("./assets/tex/hud_jeux_SD.xpm42");
	data->tex->tex_reunion = mlx_load_xpm42("./assets/tex/hud_reun_SD.xpm42");
	data->tex->tex_secret = mlx_load_xpm42("./assets/tex/hud_secret_SD.xpm42");
	data->tex->tex_local = mlx_load_xpm42("./assets/tex/hud_local_SD.xpm42");
	data->tex->tex_mbertin = mlx_load_xpm42("./assets/tex/jeunecon.xpm42");
	data->tex->tex_ewurstei = mlx_load_xpm42("./assets/tex/vieuxcon.xpm42");
	data->tex->tex_window = mlx_load_xpm42("./assets/tex/window42.xpm42");
	data->tex->tex_door = mlx_load_xpm42("./assets/tex/door42.xpm42");
	data->tex->tex_dungeon = mlx_load_xpm42("./assets/tex/dungeon42.xpm42");
	data->tex->tex_tribute = mlx_load_xpm42("./assets/tex/dungeon_tribute_SD.xpm42");
	data->tex->tex_marc = mlx_load_xpm42("./assets/tex/dungeon_marc_SD.xpm42");
	data->tex->tex_armada = mlx_load_xpm42("./assets/tex/dungeon_armada_SD.xpm42");
	data->tex->tex_torrent = mlx_load_xpm42("./assets/tex/dungeon_torrent_SD.xpm42");
	data->tex->tex_wall = mlx_load_xpm42("./assets/tex/wood42.xpm42");
	check_extra_textures(data);
}

void	check_extra_textures(t_vault *data)
{
	if (!data->tex->tex_window || !data->tex->tex_local || !data->tex->tex_amphi
		|| !data->tex->tex_bocal || !data->tex->tex_c1 || !data->tex->tex_c2
		|| !data->tex->tex_c3 || !data->tex->tex_couloir
		|| !data->tex->tex_cuisine || !data->tex->tex_detente
		|| !data->tex->tex_lobby || !data->tex->tex_lounge
		|| !data->tex->tex_mbertin || !data->tex->tex_ewurstei
		|| !data->tex->tex_jeux || !data->tex->tex_reunion
		|| !data->tex->tex_secret || !data->tex->tex_door
		|| !data->tex->tex_dungeon || !data->tex->tex_tribute
		|| !data->tex->tex_marc || !data->tex->tex_armada
		|| !data->tex->tex_torrent || !data->tex->tex_wall)
		quit_game(data);
	get_extra_textures(data);
}

void	get_extra_textures(t_vault *data)
{
	data->tex->amphi = get_texture(data->tex->tex_amphi);
	data->tex->local = get_texture(data->tex->tex_local);
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
	data->tex->mbertin = get_texture(data->tex->tex_mbertin);
	data->tex->ewurstei = get_texture(data->tex->tex_ewurstei);
	data->tex->reunion = get_texture(data->tex->tex_reunion);
	data->tex->secret = get_texture(data->tex->tex_secret);
	data->tex->window = get_texture(data->tex->tex_window);
	data->tex->door = get_texture(data->tex->tex_door);
	data->tex->dungeon = get_texture(data->tex->tex_dungeon);
	data->tex->tribute = get_texture(data->tex->tex_tribute);
	data->tex->marc = get_texture(data->tex->tex_marc);
	data->tex->armada = get_texture(data->tex->tex_armada);
	data->tex->torrent = get_texture(data->tex->tex_torrent);
	data->tex->wall = get_texture(data->tex->tex_wall);
}
