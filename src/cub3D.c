/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:33:50 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 11:51:40 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	quit_game(t_vault *data)
{
	printf("%s\n", "Au revoir !");
	free_all(data);
}

void	keyhandler(mlx_key_data_t keydata, void *param)
{
	t_vault	*data;

	data = (t_vault *) param;
	if (keydata.key == MLX_KEY_W
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_forward(data);
	if (keydata.key == MLX_KEY_S
		&& (keydata.action == MLX_REPEAT  || keydata.action == MLX_PRESS))
		move_backward(data);
	if (keydata.key == MLX_KEY_A
			&& (keydata.action == MLX_REPEAT  || keydata.action == MLX_PRESS))
		move_left(data);
	if (keydata.key == MLX_KEY_D
			&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		move_right(data);
	if (keydata.key == MLX_KEY_LEFT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_left(data);
	if (keydata.key == MLX_KEY_RIGHT
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		rotate_right(data);
	if (keydata.key == MLX_KEY_ESCAPE
		&& (keydata.action == MLX_REPEAT || keydata.action == MLX_PRESS))
		quit_game(data);
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		show_minimap(data);
}

// pour écran plus grand
// data->mlx = mlx_init(1920, 1080, "Une autre journée à 42 Québec !", true);
int	create_game(t_vault *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT,
			"Une autre journée à 42 Québec !", false);
	if (!data->mlx)
		exit (EXIT_FAILURE);
	mlx_key_hook(data->mlx, &keyhandler, (void *) data);
	mlx_close_hook(data->mlx, (void *) &quit_game, (void *) data);
	load_3d(data);
	load_hud(data);
	load_minimap(data);
	load_player(data);
	raycaster(data);
	mlx_loop(data->mlx);
	mlx_delete_image(data->mlx, data->minimap->minimap);
	mlx_delete_image(data->mlx, data->hud->hud);
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
	data->hud = ft_calloc(1, sizeof(t_hud));
	data->raycaster = ft_calloc(1, sizeof(t_rays));
	data->scene_param->r_ceiling = -1;
	data->scene_param->g_ceiling = -1;
	data->scene_param->b_ceiling = -1;
	data->scene_param->r_floor = -1;
	data->scene_param->g_floor = -1;
	data->scene_param->b_floor = -1;
	data->raycaster->mov_speed = 0.15;
	data->raycaster->rot_speed = 0.15;
	data->hud->hud_height = HEIGHT / 5;
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
	system("leaks cub3D");
	return (0);
}
