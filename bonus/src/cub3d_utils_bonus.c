/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maison <maison@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/02 09:52:42 by maison           ###   ########.fr       */
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
		rgb_to_hex(data, 'C');
	}
	else if (c == 'F')
	{
		extract_r_floor(data, rgb_code, &i, &len);
		rgb_to_hex(data, 'F');
	}
}

int	check_white_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}

void	rgb_to_hex(t_vault *data, char flag)
{
	unsigned int	a;
	int				r;
	int				g;
	int				b;

	r = 0;
	g = 0;
	b = 0;
	a = 0xff;
	if (flag == 'C')
	{
		r = data->scene_param->r_ceiling;
		g = data->scene_param->g_ceiling;
		b = data->scene_param->b_ceiling;
		data->scene_param->hex_ceiling = (r << 24) | (g << 16) | (b << 8) | a;
	}
	else if (flag == 'F')
	{
		r = data->scene_param->r_floor;
		g = data->scene_param->g_floor;
		b = data->scene_param->b_floor;
		data->scene_param->hex_floor = (r << 24) | (g << 16) | (b << 8) | a;
	}
}

int	rgb_to_hex2(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
