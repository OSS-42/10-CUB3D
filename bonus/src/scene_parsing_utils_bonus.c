/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:15:48 by mbertin           #+#    #+#             */
/*   Updated: 2023/03/02 21:00:09 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_fd(t_vault *data, int fd)
{
	char	*line;

	if (fd < 0)
	{
		data->error_code = 7;
		errors(data);
	}
	data->lines = 0;
	line = get_next_line(fd);
	if (line == NULL)
	{
		data->error_code = 1;
		errors(data);
	}
	while (line)
	{
		data->lines++;
		free (line);
		line = get_next_line(fd);
	}
	close (fd);
}

int	check_param_existence(t_vault *data)
{
	if (data->scene_param->c_exist == 0 || data->scene_param->f_exist == 0
		|| data->scene_param->no_exist == 0 || data->scene_param->so_exist == 0
		|| data->scene_param->we_exist == 0 || data->scene_param->ea_exist == 0)
		return (0);
	return (1);
}

void	skip_white_space(t_vault *data, int i, int j, int *slen)
{
	char	*temp;

	j = 0;
	while (data->scene[i][j] == '\n')
		i++;
	*slen = ft_strlen(data->scene[i]);
	while (check_white_spaces(data->scene[i][j]) == 0)
		j++;
	temp = ft_substr(data->scene[i], j, *slen);
	free (data->scene[i]);
	data->scene[i] = ft_strdup(temp);
	free (temp);
}

int	isinset(char *s1, char *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_char_isinset(set, s1[i]) != TRUE)
			return (0);
		i++;
	}
	return (1);
}

void	check_valid_char(t_vault *data, int i)
{
	while (data->map->map[i])
	{
		if (isinset(data->map->map[i], " 0123456789ENSWDZ") == FALSE)
		{
			data->error_code = 3;
			errors(data);
		}
		i++;
	}
	errors(data);
}
