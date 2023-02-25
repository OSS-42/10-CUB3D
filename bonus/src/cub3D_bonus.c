/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:33:50 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/25 00:48:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	quit_game(t_vault *data)
{
	printf("%s\n", "Au revoir !");
	system("killall afplay");
	free_all(data);
}

// pour écran plus grand
// data->mlx = mlx_init(1920, 1080, "Une autre journée à 42 Québec !", true);
int	create_game(t_vault *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT,
			"Une autre journée à 42 Québec !", false);
	if (!data->mlx)
		exit (EXIT_FAILURE);
	play_song(data);
	mlx_key_hook(data->mlx, &keyhandler, (void *) data);
	mlx_cursor_hook(data->mlx, &move_mouse, (void *)data);
	mlx_close_hook(data->mlx, (void *) &quit_game, (void *) data);
	load_textures(data);
	load_3d(data);
	load_hud(data);
	load_minimap(data);
	load_player(data);
	raycaster(data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->minimap->minimap);
	mlx_delete_image(data->mlx, data->hud_loc->hud_location);
	mlx_delete_image(data->mlx, data->hud_col->hud_collect);
	mlx_delete_image(data->mlx, data->game->ddd);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}

void	init_data(t_vault *data, char **argv)
{
	data->argv = argv[1];
	data->player = ft_calloc(1, sizeof(t_player));
	// data->lvl1 = ft_calloc(1, sizeof(t_level));
	data->minimap = ft_calloc(1, sizeof(t_minimap));
	data->scene_param = ft_calloc(1, sizeof(t_param));
	data->map = ft_calloc(1, sizeof(t_map));
	data->size = ft_calloc(1, sizeof(t_point));
	data->actual = ft_calloc(1, sizeof(t_point));
	data->game = ft_calloc(1, sizeof(t_game));
	data->hud_col = ft_calloc(1, sizeof(t_hud_col));
	data->hud_loc = ft_calloc(1, sizeof(t_hud_loc));
	data->tex = ft_calloc(1, sizeof(t_tex));
	data->raycaster = ft_calloc(1, sizeof(t_rays));
	data->scene_param->r_ceiling = -1;
	data->scene_param->g_ceiling = -1;
	data->scene_param->b_ceiling = -1;
	data->scene_param->r_floor = -1;
	data->scene_param->g_floor = -1;
	data->scene_param->b_floor = -1;
	data->raycaster->mov_speed = 0.15;
	data->raycaster->rot_speed = 0.15;
	data->audio = 0;
	data->old_x_cursor = 0;
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
