/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:33:50 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/01 16:20:27 by ewurstei         ###   ########.fr       */
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
	// if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	// 	forward(data);
	// if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	// 	backward(data);
	// if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	// 	straf_left(data);
	// if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	// 	straf_right(data);
	// if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
	// 	rotate_left(data);
	// if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
	// 	rotate_right(data);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		quit_game(data);
}

int	create_win(t_vault *data)
{
	data->mlx = mlx_init(256, 256, "Une autre journée à 42 Québec !", true);
	if (!data->mlx)
		exit (EXIT_FAILURE);
	mlx_key_hook(data->mlx, &keyhandler, (void *) data);
	// mlx_hook(data->mlx_win, 02, 0, key_hook, data); // cliquer sur la croix
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
	return (EXIT_SUCCESS);
}

void	init_data(t_vault *data, char **argv)
{
	data->argv = argv[1];
	data->player = ft_calloc(1, sizeof(t_player));
	data->lvl1 = ft_calloc(1, sizeof(t_level));
	data->scene_param = ft_calloc(1, sizeof(t_param));
	data->map = ft_calloc(1, sizeof(t_map));
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
	// errors(&data);
	// newgame(&data);
	create_win(&data);
	return (0);
}
