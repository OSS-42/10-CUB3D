/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:58:58 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/03 08:55:55 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	extract_r_floor(t_vault *data, char *rgb_code, int *i, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*i] && rgb_code[*i] != ',')
	{
		if (ft_isdigit(rgb_code[*i]) == 1)
			(*i)++;
	}
	temp = ft_substr(rgb_code, *len, *i - *len);
	if (temp[0] != '\0')
		data->scene_param->r_floor = ft_atoi(temp);
	free (temp);
	(*i)++;
	*len = *i;
	if (data->scene_param->r_floor > 255 || data->scene_param->r_floor < 0)
		data->error_code = 16;
	extract_g_floor(data, rgb_code, i, len);
}

void	extract_g_floor(t_vault *data, char *rgb_code, int *i, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*i] && rgb_code[*i] != ',')
	{
		if (ft_isdigit(rgb_code[*i]) == 1)
			(*i)++;
	}
	temp = ft_substr(rgb_code, *len, *i - *len);
	if (temp[0] != '\0')
		data->scene_param->g_floor = ft_atoi(temp);
	free (temp);
	(*i)++;
	*len = *i;
	if (data->scene_param->g_floor > 255 || data->scene_param->g_floor < 0)
		data->error_code = 16;
	extract_b_floor(data, rgb_code, i, len);
}

void	extract_b_floor(t_vault *data, char *rgb_code, int *i, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*i] && rgb_code[*i] != ',')
	{
		if (ft_isdigit(rgb_code[*i]) == 1)
			(*i)++;
	}
	temp = ft_substr(rgb_code, *len, i - len);
	if (temp[0] != '\0')
		data->scene_param->b_floor = ft_atoi(temp);
	free (temp);
	temp = NULL;
	if (data->scene_param->b_floor > 255 || data->scene_param->b_floor < 0)
		data->error_code = 16;
}