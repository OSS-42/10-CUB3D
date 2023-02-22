/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:50 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/22 14:45:39 by mbertin          ###   ########.fr       */
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
