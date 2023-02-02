/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:26:47 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/02 13:26:56 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	find_map_start(t_vault *data)
{
	while (isinset(data->scene[data->map_start], " 01NSEW") != 1)
		(data->map_start)++;
	printf("map start here : %d\n", data->map_start);
}

void	map_to_new_array(t_vault *data, int x)
{
	int		line;
	char	*temp;

	temp = NULL;
	line = x;
	while (data->scene[line])
		line++;
	data->map->map = ft_calloc(line - x + 1, sizeof(char *));
	line = 0;
	while (data->scene[x])
	{
		temp = ft_strdup(data->scene[x]);
		data->map->map[line] = ft_strtrim(temp, "\n");
		free(temp);
		line++;
		x++;
	}
	data->map->lines = line;
}
