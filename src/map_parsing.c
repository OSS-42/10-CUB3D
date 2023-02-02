/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/02 15:43:02 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_map(t_vault *data)
{
	find_map_start(data);
	map_to_new_array(data, data->map_start);
	// check map validity
}

void	check_valid_char(t_vault *data, int x)
{
	while (data->scene[x])
	{
		if (isinset(data->scene[x], " 01NSEW") != 1)
		{
			data->error_code = 3;
			errors(data);
		}
		x++;
	}
	errors(data);
}
