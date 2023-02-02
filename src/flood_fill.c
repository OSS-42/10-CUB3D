/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:43:15 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/02 15:58:17 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	flood_fill(char **tab, t_point size, t_point actual, char to_replace)
{
	if ((actual.x - 1 < 0 || actual.y - 1 < 0 || actual.x + 1 >= size.x || actual.y + 1 >= size.y || tab[actual.y][actual.x] != to_replace) || tab[actual.y][actual.x] == ' ')
		data->error_code = 4;
	tab[actual.y][actual.x] = 'F';
	flood_fill(tab, size, (t_point){actual.x - 1, actual.y}, to_replace);
	flood_fill(tab, size, (t_point){actual.x + 1, actual.y}, to_replace);
	flood_fill(tab, size, (t_point){actual.x, actual.y + 1}, to_replace);
	flood_fill(tab, size, (t_point){actual.x, actual.y - 1}, to_replace);
}