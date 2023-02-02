/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_orientation_params.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:08:43 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/02 09:46:28 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_no_params(t_vault *data, int x, int y, int slen)
{
	char	*temp;
	char	*temp2;

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

void	check_so_params(t_vault *data, int x, int y, int slen)
{
	char	*temp;
	char	*temp2;

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

void	check_we_params(t_vault *data, int x, int y, int slen)
{
	char	*temp;
	char	*temp2;

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

void	check_ea_params(t_vault *data, int x, int y, int slen)
{
	char	*temp;
	char	*temp2;

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
