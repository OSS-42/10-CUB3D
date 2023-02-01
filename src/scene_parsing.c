/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/01 16:24:50 by ewurstei         ###   ########.fr       */
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

void	scene_to_array(t_vault *data)
{
	int		x;
	int		fd;

	fd = open(data->argv, O_RDONLY);
	check_fd(data, fd);
	fd = open(data->argv, O_RDONLY);
	data->scene = ft_calloc(sizeof(char *), data->lines + 1);
	if (!data->scene)
		free_map(data) ;
	x = 0;
	while (1)
	{
		data->scene[x] = get_next_line(fd);
		if (data->scene[x] == NULL)
		{
			free(data->scene[x]);
			close(fd);
			break ;
		}
		x++;
	}
	close (fd);
}

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

void	check_scene_params(t_vault *data)
{
	int		x;
	int		y;
	int		slen;
	char	*temp;
	char	*temp2;

	x = 0;
	y = 0;
	temp = NULL;
	temp2 = NULL;
	if (data->scene[0][0] == '\0')
		data->error_code = 1;
	errors(data);
	while (data->scene[x] && check_param_existence(data) == 0)
	{
		y = 0;
		while (data->scene[x][y] == '\n')
			x++;
		slen = ft_strlen(data->scene[x]);
		while (check_white_spaces(data->scene[x][y]) == 0)
			y++;
		temp = ft_substr(data->scene[x], y, slen);
		free (data->scene[x]);
		data->scene[x] = ft_strdup(temp);
		free (temp);
		if (ft_strncmp(data->scene[x], "NO", 2) == 0)
		{
			y = 2;
			if (data->scene_param->no_exist == 1)
			{
				data->error_code = 17;
				errors(data);
			}
			data->scene_param->no_exist = 1;
			while (data->scene[x][y])
			{
				while (check_white_spaces(data->scene[x][y]) == 0)
					y++;
				temp = ft_substr(data->scene[x], y, slen);
				temp2 = ft_strtrim(temp, "\n");
				data->scene_param->no_wall_path = ft_strdup(temp2);
				free (temp);
				free (temp2);
				break ;
			}
		}
		else if (ft_strncmp(data->scene[x], "SO", 2) == 0)
		{
			y = 2;
			if (data->scene_param->so_exist == 1)
			{
				data->error_code = 17;
				errors(data);
			}
			data->scene_param->so_exist = 1;
			while (data->scene[x][y])
			{
				while (check_white_spaces(data->scene[x][y]) == 0)
					y++;
				temp = ft_substr(data->scene[x], y, slen);
				temp2 = ft_strtrim(temp, "\n");
				data->scene_param->so_wall_path = ft_strdup(temp2);
				free (temp);
				free (temp2);
				break ;
			}
		}
		else if (ft_strncmp(data->scene[x], "WE", 2) == 0)
		{
			y = 2;
			if (data->scene_param->we_exist == 1)
			{
				data->error_code = 17;
				errors(data);
			}
			data->scene_param->we_exist = 1;
			while (data->scene[x][y])
			{
				while (check_white_spaces(data->scene[x][y]) == 0)
					y++;
				temp = ft_substr(data->scene[x], y, slen);
				temp2 = ft_strtrim(temp, "\n");
				data->scene_param->we_wall_path = ft_strdup(temp2);
				free (temp);
				free (temp2);
				break ;
			}
		}
		else if (ft_strncmp(data->scene[x], "EA", 2) == 0)
		{
			y = 2;
			if (data->scene_param->ea_exist == 1)
			{
				data->error_code = 17;
				errors(data);
			}
			data->scene_param->ea_exist = 1;
			while (data->scene[x][y])
			{
				while (check_white_spaces(data->scene[x][y]) == 0)
					y++;
				temp = ft_substr(data->scene[x], y, slen);
				temp2 = ft_strtrim(temp, "\n");
				data->scene_param->ea_wall_path = ft_strdup(temp2);
				free (temp);
				free (temp2);
				break ;
			}
		}
		else if (ft_strncmp(data->scene[x], "F", 1) == 0)
		{
			y = 1;
			if (data->scene_param->f_exist == 1)
			{
				data->error_code = 17;
				errors(data);
			}
			data->scene_param->f_exist = 1;
			while (data->scene[x][y])
			{
				while (check_white_spaces(data->scene[x][y]) == 0)
					y++;
				temp = ft_substr(data->scene[x], y, slen);
				temp2 = ft_strtrim(temp, "\n");
				data->scene_param->f_color = ft_strdup(temp2);
				free (temp);
				free (temp2);
				break ;
			}
		}
		else if (ft_strncmp(data->scene[x], "C", 1) == 0)
		{
			y = 1;
			if (data->scene_param->c_exist == 1)
			{
				data->error_code = 17;
				errors(data);
			}
			data->scene_param->c_exist = 1;
			while (data->scene[x][y])
			{
				while (check_white_spaces(data->scene[x][y]) == 0)
					y++;
				temp = ft_substr(data->scene[x], y, slen);
				temp2 = ft_strtrim(temp, "\n");
				data->scene_param->c_color = ft_strdup(temp2);
				free (temp);
				free (temp2);
				break ;
			}
		}
		x++;
	}
	if (check_param_existence(data) == 0)
		data->error_code = 13;
	errors(data);
	check_wall_path(data);
	check_color_code(data);
	check_valid_char(data, x);
	x = find_map_start(data, x);
	map_to_new_array(data, x);
	// check map validity
}

int	find_map_start(t_vault *data, int x)
{
	while (ft_strchr(data->scene[x], '1') == 0)
		x++;
	return (x);
	printf("map start here : %d\n", x);
}

int	check_param_existence(t_vault *data)
{
	if (data->scene_param->c_exist == 0 || data->scene_param->f_exist == 0
		|| data->scene_param->no_exist == 0 || data->scene_param->so_exist == 0
		|| data->scene_param->we_exist == 0 || data->scene_param->ea_exist == 0)
		return (0);
	return (1);
}

void	check_wall_path(t_vault *data)
{
	int	fd;

	fd = open(data->scene_param->no_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	fd = open(data->scene_param->so_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	fd = open(data->scene_param->we_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	fd = open(data->scene_param->ea_wall_path, 0, 0);
	if (fd < 0)
		data->error_code = 14;
	close (fd);
	errors(data);
}

void	check_color_code(t_vault *data)
{
	if (correct_rgb_char(data->scene_param->c_color) == 0
		|| correct_rgb_char(data->scene_param->f_color) == 0)
		data->error_code = 15;
	errors(data);
	if (correct_rgb_range(data->scene_param->c_color) == 0
		|| correct_rgb_range(data->scene_param->f_color) == 0)
		data->error_code = 16;
	errors(data);
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
