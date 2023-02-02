/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/02 11:12:46 by mbertin          ###   ########.fr       */
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
		free_map(data);
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
	// int		y;
	// int		slen;
	// char	*temp;
	// char	*temp2;

	x = 0;
	// y = 0;
	// temp = NULL;
	// temp2 = NULL;
	if (data->scene[0][0] == '\0')
		data->error_code = 1;
	errors(data);
	check_scene_syntax(data, &x);
	// while (data->scene[x] && check_param_existence(data) == 0)
	// {
	// 	skip_white_space(data, x, y, slen);
	// 	if (ft_strncmp(data->scene[x], "NO", 2) == 0)
	// 		check_no_params(data, x, y, slen);
	// 	else if (ft_strncmp(data->scene[x], "SO", 2) == 0)
	// 		check_so_params(data, x, y, slen);
	// 	else if (ft_strncmp(data->scene[x], "WE", 2) == 0)
	// 		check_we_params(data, x, y, slen);
	// 	else if (ft_strncmp(data->scene[x], "EA", 2) == 0)
	// 		check_ea_params(data, x, y, slen);
	// 	else if (ft_strncmp(data->scene[x], "F", 1) == 0)
	// 		check_f_params(data, x, y, slen);
	// 	else if (ft_strncmp(data->scene[x], "C", 1) == 0)
	// 		check_c_params(data, x, y, slen);
	// 	x++;
	// }
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

void	check_scene_syntax(t_vault *data, int *x)
{
	int	slen;
	int	y;

	slen = 0;
	y = 0;
	while (data->scene[*x] && check_param_existence(data) == 0)
	{
		skip_white_space(data, *x, y, &slen);
		if (ft_strncmp(data->scene[*x], "NO", 2) == 0)
			check_no_params(data, *x, y, slen);
		else if (ft_strncmp(data->scene[*x], "SO", 2) == 0)
			check_so_params(data, *x, y, slen);
		else if (ft_strncmp(data->scene[*x], "WE", 2) == 0)
			check_we_params(data, *x, y, slen);
		else if (ft_strncmp(data->scene[*x], "EA", 2) == 0)
			check_ea_params(data, *x, y, slen);
		else if (ft_strncmp(data->scene[*x], "F", 1) == 0)
			check_f_params(data, *x, y, slen);
		else if (ft_strncmp(data->scene[*x], "C", 1) == 0)
			check_c_params(data, *x, y, slen);
		(*x)++;
	}
}
