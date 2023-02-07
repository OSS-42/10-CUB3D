/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:43:15 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/07 14:27:16 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	flood_fill(t_vault *data, int x, int y, char **temp)
{
	if (ft_char_isinset("NSEW", temp[x][y]) == TRUE)
		temp[x][y] = '0';
	if ((x - 1 < 0 || y - 1 < 0
			|| x + 1 >= data->map->lines
			|| y + 1 >= (int)ft_strlen(temp[x])
			|| temp[x][y] != '0'))
	{
		data->error_code = 4;
		printf("x = %d, y = %d\n", x, y);
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
