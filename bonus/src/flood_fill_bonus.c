/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:43:15 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/28 09:20:36 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	flood_fill(t_vault *data, int x, int y, char **temp)
{
	if (!temp[x] || !temp[x][y] || ((x - 1 < 0 || y - 1 < 0
			|| x + 1 >= data->map->lines || y + 1 >= (int)ft_strlen(temp[x]))
			&& ft_char_isinset("0 2D", temp[x][y] == FALSE))
			|| temp[x][y] == ' ')
	{
		data->error_code = 4;
		return ;
	}
	if (temp[x][y] == '0' || ft_char_isinset("NSEW", temp[x][y]))
		temp[x][y] = '.';
	else
		return ;
	flood_fill(data, x + 1, y, temp);
	flood_fill(data, x - 1, y, temp);
	flood_fill(data, x, y + 1, temp);
	flood_fill(data, x, y - 1, temp);
	flood_fill(data, x + 1, y + 1, temp);
	flood_fill(data, x + 1, y - 1, temp);
	flood_fill(data, x - 1, y + 1, temp);
	flood_fill(data, x - 1, y - 1, temp);
}
