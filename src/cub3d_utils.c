/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 14:35:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
		// extract_g_ceiling(data, rgb_code, &i, &len);
		// extract_b_ceiling(data, rgb_code, &i, &len);
		rgb_to_hex(data, data->scene_param->r_ceiling, data->scene_param->g_ceiling, data->scene_param->b_ceiling, 'C');
	}
	else if (c == 'F')
	{
		extract_r_floor(data, rgb_code, &i, &len);
		// extract_g_floor(data, rgb_code, &i, &len);
		// extract_b_floor(data, rgb_code, &i, &len);
		rgb_to_hex(data, data->scene_param->r_floor, data->scene_param->g_floor, data->scene_param->b_floor, 'F');
	}
}

int	check_white_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}
