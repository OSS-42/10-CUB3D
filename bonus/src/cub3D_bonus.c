/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:33:50 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/14 09:21:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	loading_game(t_vault *data)
{
	load_textures(data);
	load_minimap(data);
	load_3d(data);
	load_player(data);
	load_hud(data);
	load_sprites(data);
}

void	delete_images(t_vault *data)
{
	mlx_delete_image(data->mlx, data->minimap->minimap);
	mlx_delete_image(data->mlx, data->hud_loc->hud_loc_static);
	mlx_delete_image(data->mlx, data->hud_loc->hud_loc_dynamic);
	mlx_delete_image(data->mlx, data->game->ddd);
	printf("%s\n", "Au revoir !");
	free_all(data);
}

int	create_game(t_vault *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT,
			"Une autre journée à 42 Québec !", FALSE);
	if (!data->mlx)
		exit (EXIT_FAILURE);
	loading_game(data);
	raycaster(data);
	mlx_key_hook(data->mlx, &keyhandler, (void *) data);
	mlx_close_hook(data->mlx, (void *) &quit_game, (void *) data);
	mlx_cursor_hook(data->mlx, &move_mouse, (void *)data);
	mlx_loop(data->mlx);
	delete_images(data);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}

void	init_data(t_vault *data, char **argv)
{
	data->argv = argv[1];
	data->plr = ft_calloc(1, sizeof(t_player));
	data->minimap = ft_calloc(1, sizeof(t_minimap));
	data->scene_param = ft_calloc(1, sizeof(t_param));
	data->map = ft_calloc(1, sizeof(t_map));
	data->size = ft_calloc(1, sizeof(t_point));
	data->actual = ft_calloc(1, sizeof(t_point));
	data->game = ft_calloc(1, sizeof(t_game));
	data->hud_loc = ft_calloc(1, sizeof(t_hud_loc));
	data->tex = ft_calloc(1, sizeof(t_tex));
	data->raycaster = ft_calloc(1, sizeof(t_rays));
	data->s_par = ft_calloc(1, sizeof(t_s_par));
	data->scene_param->r_ceiling = -1;
	data->scene_param->g_ceiling = -1;
	data->scene_param->b_ceiling = -1;
	data->scene_param->r_floor = -1;
	data->scene_param->g_floor = -1;
	data->scene_param->b_floor = -1;
	data->raycaster->mov_speed = 0.15;
	data->raycaster->rot_speed = 0.15;
	data->audio = 0;
	data->old_x_cursor = WIDTH / 2;
	data->hud_loc->location = 0;
	data->hud_loc->p_loc = data->tex->lobby;
}

int	main(int argc, char **argv)
{
	t_vault	data;

	data.error_code = 0;
	if (argc != 2)
		data.error_code = 9;
	errors(&data);
	init_data(&data, argv);
	check_scene_name(&data);
	scene_to_array(&data);
	check_scene_params(&data);
	check_map(&data);
	errors(&data);
	create_game(&data);
	return (0);
}
