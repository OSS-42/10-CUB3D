/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/22 20:36:15 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	check_scene_name(t_vault *data)
{
	char	*filename;
	int		fd;

	fd = open(data->argv, O_DIRECTORY);
	if (fd > 0)
	{
		close(fd);
		data->error_code = 12;
		errors(data);
	}
	filename = ft_strrchr(data->argv, '.');
	if (filename == NULL)
	{
		data->error_code = 8;
		errors(data);
	}
	if (ft_strncmp(filename, ".cub", ft_strlen(filename)) != 0)
	{
		data->error_code = 8;
		errors(data);
	}
}

void	scene_to_array(t_vault *data)
{
	int		i;
	int		fd;

	fd = open(data->argv, O_RDONLY);
	check_fd(data, fd);
	fd = open(data->argv, O_RDONLY);
	data->scene = ft_calloc(sizeof(char *), data->lines + 1);
	if (!data->scene)
		free_map(data);
	i = 0;
	while (1)
	{
		data->scene[i] = get_next_line(fd);
		if (data->scene[i] == NULL)
		{
			free(data->scene[i]);
			close(fd);
			break ;
		}
		i++;
	}
	close (fd);
}

void	check_scene_params(t_vault *data)
{
	int	i;

	i = 0;
	if (data->scene[0][0] == '\0')
		data->error_code = 1;
	errors(data);
	check_scene_syntax(data, &i);
	if (check_param_existence(data) == 0)
		data->error_code = 13;
	errors(data);
	check_wall_path(data);
	check_color_code(data);
	data->map_start = i;
}

void	check_scene_syntax(t_vault *data, int *i)
{
	int	slen;
	int	y;

	slen = 0;
	y = 0;
	while (data->scene[*i] && check_param_existence(data) == 0)
	{
		skip_white_space(data, *i, y, &slen);
		if (ft_strncmp(data->scene[*i], "NO", 2) == 0)
			check_no_params(data, *i, y, slen);
		else if (ft_strncmp(data->scene[*i], "SO", 2) == 0)
			check_so_params(data, *i, y, slen);
		else if (ft_strncmp(data->scene[*i], "WE", 2) == 0)
			check_we_params(data, *i, y, slen);
		else if (ft_strncmp(data->scene[*i], "EA", 2) == 0)
			check_ea_params(data, *i, y, slen);
		else if (ft_strncmp(data->scene[*i], "F", 1) == 0)
			check_f_params(data, *i, y, slen);
		else if (ft_strncmp(data->scene[*i], "C", 1) == 0)
			check_c_params(data, *i, y, slen);
		(*i)++;
	}
}
