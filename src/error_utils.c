/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:17:50 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/21 10:17:09 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	free_all(t_vault *data)
{
	mlx_terminate(data->mlx);
	free_map(data);
	destroy_and_free_level(data);
	destroy_and_free_player(data);
	system("leaks cub3D");
}
