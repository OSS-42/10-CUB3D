/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:26:47 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/07 21:21:37 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	find_map_start(t_vault *data)
{
	int	i;

	i = data->map_start;
	while (data->scene[i])
	{
		if ((int)ft_strlen(data->scene[i]) - 1 == 0)
		{
			data->map_start++;
			i++;
		}
		else
			break ;
	}
	printf("map start here : %d\n", data->map_start);
}

void	map_max_lenght(t_vault *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		if ((int)ft_strlen(data->map->map[i]) > data->map->max_lenght)
			data->map->max_lenght = ft_strlen(data->map->map[i]);
		i++;
	}
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
	map_max_lenght(data);
	data->map->lines = line;
	data->lines = line;
}
