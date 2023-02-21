/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:50 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/21 14:56:14 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_all(t_vault *data)
{
	mlx_terminate(data->mlx);
	// destroy_and_free_level(data);
	destroy_and_free_player(data);
	free_map(data);
}
