/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:43:15 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/02 09:54:24 by maison           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	flood_fill(t_vault *data, int x, int y, char **temp)
{
	if (!temp[x] || !temp[x][y] || ((x - 1 < 0 || y - 1 < 0
			|| x + 1 >= data->map->lines || y + 1 >= (int)ft_strlen(temp[x]))
			&& ft_char_isinset("0 2DZ", temp[x][y] == FALSE))
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
