/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/02 13:51:50 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

// on ne gere pas si le code rgb a plus que ou moins que 3 parametres
int	correct_rgb_range(t_vault *data, char *rgb_code)
{
	int		code_r;
	int		code_g;
	int		code_b;
	int		comma_count;
	int		i;
	int		x;
	int		len;
	char	*temp;

	code_r = -1;
	code_g = -1;
	code_b = -1;
	x = 0;
	len = 0;
	temp = NULL;

	while (rgb_code && rgb_code[i])
	{
		if (ft_strchr(rgb_code, ',') == 1)
			comma_count++;
		i++;
	}
	if (comma_count != 2)
	{
		data->error_code = 15;
		errors(data);
	}
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_isdigit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x - len);
	if (temp)
		code_r = ft_atoi(temp);
	free (temp);
	x++;
	len = x;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_isdigit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x - len);
	if (temp)
		code_g = ft_atoi(temp);
	free (temp);
	x++;
	len = x;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_isdigit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x - len);
	if (temp)
		code_b = ft_atoi(temp);
	free (temp);
	temp = NULL;
	if (code_r > 255 || code_g > 255 || code_b > 255
		|| code_r < 0 || code_g < 0 || code_b < 0)
		return (0);
	return (1);
}

int	check_white_spaces(char c)
{
	if (c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f'
		|| c == ' ')
		return (0);
	return (1);
}
