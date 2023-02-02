/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fc_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 09:37:22 by mbertin           #+#    #+#             */
/*   Updated: 2023/02/02 13:52:38 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	check_f_params(t_vault *data, int x, int y, int slen)
{
	char	*temp;
	char	*temp2;

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

void	check_c_params(t_vault *data, int x, int y, int slen)
{
	char	*temp;
	char	*temp2;

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

void	check_color_code(t_vault *data)
{
	if (correct_rgb_char(data->scene_param->c_color) == 0
		|| correct_rgb_char(data->scene_param->f_color) == 0)
		data->error_code = 15;
	errors(data);
	if (correct_rgb_range(data, data->scene_param->c_color) == 0
		|| correct_rgb_range(data, data->scene_param->f_color) == 0)
		data->error_code = 16;
	errors(data);
}

int	correct_rgb_char(char *rgb_code)
{
	int	x;

	x = 0;
	while (rgb_code && rgb_code[x])
	{
		while (rgb_code[x] == ' ')
		{
			x++;
			if (rgb_code[x] == '\0')
				return (0);
		}
		if (ft_isdigit(rgb_code[x]) == 1 || rgb_code[x] == ',')
			x++;
		else
			return (0);
	}
	return (1);
}
