/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/28 15:26:01 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_map(t_vault *data)
{
	find_map_start(data);
	map_to_new_array(data, data->map_start);
	check_valid_char(data, 0);
	find_player_start(data);
	errors(data);
	flood_fill(data, data->plr->start_x, data->plr->start_y,
		data->map->temp_map);
	ft_dbl_ptr_free((void **)data->map->temp_map);
	errors(data);
	fill_map_void(data);
}

void	find_player_start(t_vault *data)
{
	int	x;
	int	y;
	int	flag;

	x = 0;
	flag = 0;
	while (data->map->map[x])
	{
		y = 0;
		while (data->map->map[x][y])
		{
			if (data->map->map[x][y] == 'N' || data->map->map[x][y] == 'S'
				|| data->map->map[x][y] == 'E' || data->map->map[x][y] == 'W')
			{
				data->plr->direction = data->map->map[x][y];
				data->plr->start_x = x;
				data->plr->start_y = y;
				flag++;
			}
			y++;
		}
		x++;
	}
	if (flag > 1 || flag == 0)
		data->error_code = 10;
}

void	fill_map_void(t_vault *data)
{
	int		x;

	x = 0;
	while (data->map->map[x])
	{
		if ((int)ft_strlen(data->map->map[x]) <= data->map->max_lenght)
		{
			replace_voids(data, x);
			fill_rest_of_line(data, x);
		}
		x++;
	}
}

void	replace_voids(t_vault *data, int x)
{
	int	y;

	y = 0;
	while (data->map->map[x][y])
	{
		if (data->map->map[x][y] == ' ')
			data->map->map[x][y] = '.';
		y++;
	}
}

void	fill_rest_of_line(t_vault *data, int x)
{
	int		y;
	char	*temp;

	y = 0;
	temp = NULL;
	temp = ft_calloc(data->map->max_lenght + 1, sizeof(char));
	while (data->map->map[x][y])
	{
		temp[y] = data->map->map[x][y];
		y++;
	}
	while (y < data->map->max_lenght)
	{
		temp[y] = '.';
		y++;
	}
	free(data->map->map[x]);
	data->map->map[x] = ft_strdup(temp);
	free (temp);
	temp = NULL;
}
