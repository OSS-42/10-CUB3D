/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/30 23:45:45 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	correct_rgb(char *rgb_code)
{
	int	x;

	x = 0;
	while (rgb_code && rgb_code[x])
	{
		if (ft_isdigit(rgb_code[x] == 1) || rgb_code[x] == ',')
			x++;
		else
			return (0);
	}
	return (1);
}

//fonction range of rgb [0,255]