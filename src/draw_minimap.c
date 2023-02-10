/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 15:02:31 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/10 14:44:06 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	draw_minimap(t_vault *data)
{
	int	start_hori;
	int	x;

	start_hori = 0;
	x = 0;
	data->minimap->img_y = data->height - data->map->lines * 11;
	while (x < data->lines)
	{
		data->minimap->y = 0;
		data->minimap->img_x = 0;
		while (data->minimap->y
			< (int)ft_strlen(data->map->map[x]))
		{
			if (data->map->map[x][data->minimap->y] == '1')
				draw_char(data, start_hori, 0xFFFFFFFF, x);
			else if (ft_char_isinset("0", data->map->map[x][data->minimap->y]) == TRUE)
				draw_char(data, start_hori, 0x6E99FFFF, x);
			else if (ft_char_isinset("NSEW", data->map->map[x][data->minimap->y]) == TRUE)
			{
				draw_char(data, start_hori, 0x6E99FFFF, x);
				find_orientation(data, data->map->map[x][data->minimap->y]);
				data->map->map[x][data->minimap->y] = '0';
				player_pixels(data);
			}
			start_hori += 11;
			data->minimap->y++;
			data->minimap->img_x += 11;
		}
		start_hori = 0;
		x++;
		data->minimap->img_y += 11;
	}
}

void	draw_char(t_vault *data, int start, unsigned int rgb, int x)
{
	int	i;
	int	end;
	int	hori;

	i = 0;
	end = start + 10;
	hori = x * 11;
	while (i < 10)
	{
		dessine_une_ligne_hor(data, start, end, hori, rgb);
		hori++;
		i++;
	}
}
