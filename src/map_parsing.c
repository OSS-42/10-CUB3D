/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:54:06 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/30 17:47:10 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	scene_to_array(t_vault *data)
{
	int		x;
	int		fd;

	fd = open(data->argv, O_RDONLY);
	check_fd(data, fd);
	fd = open(data->argv, O_RDONLY);
	data->map = malloc(sizeof(char *) * data->lines + 1);
	if (!data->map)
		return ;
	x = 0;
	while (1)
	{
		data->map[x] = get_next_line(fd);
		if (data->map[x] == NULL)
		{
			free(data->map[x]);
			close(fd);
			break ;
		}
		x++;
	}
	close (fd);
}

void	check_map_name(t_vault *data)
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

void	check_map(t_vault *data)
{
	if (data->map[0][0] == '\0')
		data->error_code = 1;
	else if (data->lenght <= 4 || data->lines < 3)
		data->error_code = 2;
	errors(data);
	check_map_params(data);
}

void	check_map_params(t_vault *data)
{
	int		x;
	int		y;
	int		slen;
	char	*temp;

	x = 0;
	temp = NULL;
	while (data->map[x])
	{
		y = 2;
		slen = ft_strlen(data->map[x]);
		if (ft_strncmp(data->map[x], "NO", 2) == 1)
		{
			data->map_param->no_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->no_wall_path = ft_strdup(temp);
					free (temp);
				}
			}
		}
		else if (ft_strncmp(data->map[x], "SO", 2) == 1)
		{
			data->map_param->so_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->so_wall_path = ft_strdup(temp);
					free (temp);
				}
			}
		}
		else if (ft_strncmp(data->map[x], "WE", 2) == 1)
		{
			data->map_param->we_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->we_wall_path = ft_strdup(temp);
					free (temp);
				}
			}
		}
		else if (ft_strncmp(data->map[x], "EA", 2) == 1)
		{
			data->map_param->ea_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->ea_wall_path = ft_strdup(temp);
					free (temp);
				}
			}
		}
		else if (ft_strncmp(data->map[x], "F", 1) == 1)
		{
			data->map_param->f_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->f_color = ft_strdup(temp);
					free (temp);
				}
			}
		}
		else if (ft_strncmp(data->map[x], "C", 1) == 1)
		{
			data->map_param->ea_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->c_color = ft_strdup(temp);
					free (temp);
				}
			}
		}
		else if (ft_strncmp(data->map[x], "EA", 2) == 1)
		{
			data->map_param->ea_exist = 1;
			while (data->map[x][y])
			{
				if (data->map[x][y] == ' ')
					y++;
				else
				{
					temp = ft_substr(data->map[x], y, slen);
					data->map_param->ea_wall_path = ft_strcpy(temp);
					free (temp);
				}
			}
		}
	}
}
