/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_floor_rgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:58:58 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/02 16:19:35 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	extract_r_floor(t_vault *data, char *rgb_code, int *x, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*x] && rgb_code[*x] != ',')
	{
		if (ft_isdigit(rgb_code[*x]) == 1)
			(*x)++;
	}
	temp = ft_substr(rgb_code, *len, *x - *len);
	if (temp[0] != '\0')
		data->scene_param->r_floor = ft_atoi(temp);
	free (temp);
	(*x)++;
	*len = *x;
	if (data->scene_param->r_floor > 255 || data->scene_param->r_floor < 0)
		data->error_code = 16;
	extract_g_floor(data, rgb_code, x, len);
}

void	extract_g_floor(t_vault *data, char *rgb_code, int *x, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*x] && rgb_code[*x] != ',')
	{
		if (ft_isdigit(rgb_code[*x]) == 1)
			(*x)++;
	}
	temp = ft_substr(rgb_code, *len, *x - *len);
	if (temp[0] != '\0')
		data->scene_param->g_floor = ft_atoi(temp);
	free (temp);
	(*x)++;
	*len = *x;
	if (data->scene_param->g_floor > 255 || data->scene_param->g_floor < 0)
		data->error_code = 16;
	extract_b_floor(data, rgb_code, x, len);
}

void	extract_b_floor(t_vault *data, char *rgb_code, int *x, int *len)
{
	char	*temp;

	temp = NULL;
	while (rgb_code && rgb_code[*x] && rgb_code[*x] != ',')
	{
		if (ft_isdigit(rgb_code[*x]) == 1)
			(*x)++;
	}
	temp = ft_substr(rgb_code, *len, x - len);
	if (temp[0] != '\0')
		data->scene_param->b_floor = ft_atoi(temp);
	free (temp);
	temp = NULL;
	if (data->scene_param->b_floor > 255 || data->scene_param->b_floor < 0)
		data->error_code = 16;
}
