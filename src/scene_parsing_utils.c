/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:15:48 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/02 11:22:36 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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

void	skip_white_space(t_vault *data, int x, int y, int *slen)
{
	char	*temp;

	y = 0;
	while (data->scene[x][y] == '\n')
		x++;
	*slen = ft_strlen(data->scene[x]);
	while (check_white_spaces(data->scene[x][y]) == 0)
		y++;
	temp = ft_substr(data->scene[x], y, *slen);
	free (data->scene[x]);
	data->scene[x] = ft_strdup(temp);
	free (temp);
}

int	isinset(char *s1, char *set)
{
	int	x;
	int	len;

	x = 0;
	len = ft_strlen(s1);
	while (x < len - 1)
	{
		if (ft_strchr(set, s1[x]) == NULL)
			return (0);
		x++;
	}
	return (1);
}

void	check_valid_char(t_vault *data, int x)
{
	while (data->scene[x])
	{
		if (isinset(data->scene[x], " 01NSEW") != 1)
		{
			data->error_code = 3;
			errors(data);
		}
		x++;
	}
	errors(data);
}
