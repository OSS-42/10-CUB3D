/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 15:10:02 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

int	ft_find_char(char *src, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!src || c == 0)
		return (count);
	while (src[i])
	{
		if (src[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	correct_rgb_range(t_vault *data, char *rgb_code, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (ft_find_char(rgb_code, ',') != 2)
	{
		data->error_code = 15;
		errors(data);
	}
	if (c == 'C')
	{
		extract_r_ceiling(data, rgb_code, &i, &len);
		extract_g_ceiling(data, rgb_code, &i, &len);
		extract_b_ceiling(data, rgb_code, &i, &len);
	}
	else if (c == 'F')
	{
		extract_r_floor(data, rgb_code, &i, &len);
		extract_g_floor(data, rgb_code, &i, &len);
		extract_b_floor(data, rgb_code, &i, &len);
	}
}

int	check_white_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}
