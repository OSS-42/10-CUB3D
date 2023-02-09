/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hud.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:00:20 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/09 17:29:04 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_hud(t_vault *data)
{
	char	*value;
	if (data->player->pdy < 0)
		value = ft_ftoa(data->player->pdy, -1);
	else
		value = ft_ftoa(data->player->pdy, 1);
	data->hud->px = mlx_put_string(data->mlx, "px  = ", data->map->max_lenght * 11 + 10, 320 - data->map->lines * 11 - 5);
	data->hud->px = mlx_put_string(data->mlx, value, data->map->max_lenght * 11 + 70, 320 - data->map->lines * 11 - 5);
	// free(value);
	// value = ft_ftoa(data->player->py);
	// data->hud->py = mlx_put_string(data->mlx, "py  = ", data->map->max_lenght * 11 + 10, 320 - data->map->lines * 11 + 10);
	// data->hud->py = mlx_put_string(data->mlx, value, data->map->lines * 11 + 10, 20);
	// free(value);
	// value = ft_ftoa(data->player->pa);
	// data->hud->pa = mlx_put_string(data->mlx, "pa  = ", data->map->max_lenght * 11 + 10, 320 - data->map->lines * 11 + 25);
	// data->hud->pa = mlx_put_string(data->mlx, value, data->map->lines * 11 + 10, 20);
	// free(value);
	// value = ft_ftoa(data->player->pdx);
	// data->hud->pdx = mlx_put_string(data->mlx, "pdx = ", data->map->max_lenght * 11 + 10, 320 - data->map->lines * 11 + 40);
	// data->hud->pdx = mlx_put_string(data->mlx, value, data->map->lines * 11 + 10, 20);
	// free(value);
	// value = ft_ftoa(data->player->pdy);
	// data->hud->pdy = mlx_put_string(data->mlx, "pdy = ", data->map->max_lenght * 11 + 10, 320 - data->map->lines * 11 + 55);
	// data->hud->pdy = mlx_put_string(data->mlx, value, data->map->lines * 11 + 10, 20);
	// free(value);
}

char	*ft_ftoa(float nbr, int	sign)
{
	int		n;
	int		i;
	int		k;
	char	*res;

	n = (int)nbr;
	printf("%d\n", n);
	i = 0;
	k = 1;
	res = ft_calloc(20 + 1, sizeof(char));
	if (sign == -1)
	{
		res[i] = '-';
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		k++;
	}
	printf("%d\n", k);
	n = (int)nbr;
	while (n > 0)
	{
		res[i] = 48 + n % 10;
		n = n / 10;
		i++;
	}
	if (n == 0)
	{
		res[i] = 48;
		i++;
	}
	if (n % 10 == 0)
	{
		res[i] = '.';
		i++;
	}
	return (res);
}
