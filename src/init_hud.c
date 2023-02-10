/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/10 13:37:12 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_hud(t_vault *data)
{
	dessine_une_ligne_hor(data, 0, data->width, 0, 0xFF00FFFF);
	// data->hud->px = mlx_put_string(data->mlx, "px  = ", data->map->max_lenght * 11 + 10, 320 - data->map->lines * 11 - 5);
	// data->hud->px = mlx_put_string(data->mlx, value, data->map->max_lenght * 11 + 70, 320 - data->map->lines * 11 - 5);
}

// char	*ft_ftoa(float nbr, int	sign)
// {
// 	int		n;
// 	int		i;
// 	int		k;
// 	char	*res;

// 	n = (int)nbr;
// 	printf("%d\n", n);
// 	i = 0;
// 	k = 1;
// 	res = ft_calloc(20 + 1, sizeof(char));
// 	if (sign == -1)
// 	{
// 		res[i] = '-';
// 		i++;
// 	}
// 	while (n > 0)
// 	{
// 		n = n / 10;
// 		k++;
// 	}
// 	printf("%d\n", k);
// 	n = (int)nbr;
// 	while (n > 0)
// 	{
// 		res[i] = 48 + n % 10;
// 		n = n / 10;
// 		i++;
// 	}
// 	if (n == 0)
// 	{
// 		res[i] = 48;
// 		i++;
// 	}
// 	if (n % 10 == 0)
// 	{
// 		res[i] = '.';
// 		i++;
// 	}
// 	return (res);
// }
