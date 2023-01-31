/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/31 08:39:37 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

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
		if (ft_isdigit(rgb_code[x] == 1) || rgb_code[x] == ',')
			x++;
		else
			return (0);
	}
	return (1);
}

int	correct_rgb_range(char *rgb_code)
{
	int		code_r;
	int		code_g;
	int		code_b;
	int		x;
	int		len;
	char	*temp;

	code_r = 0;
	code_g = 0;
	code_b = 0;
	x = 0;
	len = 0;
	temp = NULL;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_is_digit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, 0, x);
	code_r = ft_atoi(temp);
	len = ft_strlen(temp) - 1;
	free (temp);
	x++;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_is_digit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x);
	code_g = ft_atoi(temp);
	len = ft_strlen(temp) - 1;
	free (temp);
	x++;
	while (rgb_code && rgb_code[x] && rgb_code[x] != ',')
	{
		if (ft_is_digit(rgb_code[x]) == 1)
			x++;
	}
	temp = ft_substr(rgb_code, len, x);
	code_g = ft_atoi(temp);
	free (temp);
	temp = NULL;
	if (code_r > 255 || code_g > 255 || code_b > 255
		|| code_r < 0 || code_g < 0 || code_b < 0)
		return (0);
	return (1);
}
