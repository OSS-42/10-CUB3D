/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/07 16:04:52 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_map(t_vault *data)
{
	find_map_start(data);
	map_to_new_array(data, data->map_start);
	check_valid_char(data, 0);
	find_player_start(data);
	errors(data);
	flood_fill(data, data->player->start_x, data->player->start_y, ft_dbl_ptr_copy(data->map->map));
	errors(data);
}

void	find_player_start(t_vault *data)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	flag = 0;
	while (data->map->map[x] && isinset(data->map->map[x], "NSEW") == 0)
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == 'N' || data->map->map[x][y] == 'S'
				|| data->map->map[x][y] == 'E' || data->map->map[x][y] == 'W')
				flag++;
			y++;
		}
		x++;
	}
	data->player->start_x = x;
	data->player->start_y = y;
	if (flag > 1 || flag == 0)
		data->error_code = 10;
}
