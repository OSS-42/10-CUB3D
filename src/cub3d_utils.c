/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 23:21:15 by ewurstei          #+#    #+#             */
/*   Updated: 2023/02/02 14:52:48 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_find_char(char *src, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!src || c == 0)
		return (count);
	while (src[i])
	{
		if (src[i] == c)
			count++;
		i++;
	}
	return (count);
}

// on ne gere pas si le code rgb a plus que ou moins que 3 parametres
int	correct_rgb_range(t_vault *data, char *rgb_code)
{
	int		code_r;
	int		code_g;
	int		code_b;
	int		i;
	int		x;
	int		len;
	char	*temp;

	code_r = -1;
	code_g = -1;
	code_b = -1;
	i = 0;
	x = 0;
	len = 0;
	temp = NULL;

	if (ft_find_char(rgb_code, ',') != 2)
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
	if (temp[0] != '\0')
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
	if (temp[0] != '\0')
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
	if (temp[0] != '\0')
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
