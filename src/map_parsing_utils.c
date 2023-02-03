/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:26:47 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/03 09:16:13 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	find_map_start(t_vault *data)
{
	while (isinset(data->scene[data->map_start], " 01NSEW") != 1)
		(data->map_start)++;
	printf("map start here : %d\n", data->map_start);
}

void	map_to_new_array(t_vault *data, int i)
{
	int		line;
	char	*temp;

	temp = NULL;
	line = i;
	while (data->scene[line])
		line++;
	data->map->map = ft_calloc(line - i + 1, sizeof(char *));
	line = 0;
	while (data->scene[i])
	{
		temp = ft_strdup(data->scene[i]);
		data->map->map[line] = ft_strtrim(temp, "\n");
		free(temp);
		line++;
		i++;
	}
	data->map->lines = line;
	data->lines = line;
}
